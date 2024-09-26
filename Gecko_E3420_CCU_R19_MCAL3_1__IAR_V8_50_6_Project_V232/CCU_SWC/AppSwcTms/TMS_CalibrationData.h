/*
 * File: TMS_CalibrationData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2111
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Sep 19 15:03:10 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TMS_CalibrationData_h_
#define RTW_HEADER_TMS_CalibrationData_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ME11_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: TMS_CalibrationData */
extern CALDATA const volatile uint8 ACDefog;/* Referenced by: '<S385>/Constant7' */
extern CALDATA const volatile uint8 ACOff;/* Referenced by:
                                           * '<S4>/Constant2'
                                           * '<S38>/Constant1'
                                           * '<S38>/Constant5'
                                           * '<S39>/Constant'
                                           * '<S40>/Constant'
                                           * '<S41>/Constant'
                                           * '<S174>/Constant'
                                           * '<S385>/Constant3'
                                           * '<S385>/Constant5'
                                           * '<S90>/Constant'
                                           * '<S122>/Constant'
                                           * '<S129>/Constant1'
                                           * '<S133>/Constant'
                                           * '<S226>/Constant'
                                           */
extern CALDATA const volatile uint8 AC_ColdStart;/* Referenced by: '<S47>/ColdStart' */
extern CALDATA const volatile uint8 AC_HotStart;/* Referenced by:
                                                 * '<S47>/HotStart'
                                                 * '<S48>/HotStart'
                                                 * '<S123>/Constant26'
                                                 */
extern CALDATA const volatile uint8 AC_LittleColdStart;/* Referenced by: '<S47>/ColdStart6' */
extern CALDATA const volatile uint8 BlowerACMode;
                                     /* Referenced by: '<S77>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerBILevelMode;
                                     /* Referenced by: '<S77>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerDefrostMode;
                                     /* Referenced by: '<S77>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerHeaterDefrostMode;
                                     /* Referenced by: '<S77>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerHeaterMode;
                                     /* Referenced by: '<S77>/AutoBlowerMode' */
extern CALDATA const volatile uint8 DriveFRESH;/* Referenced by:
                                                * '<S118>/Constant2'
                                                * '<S118>/Constant3'
                                                * '<S142>/Constant2'
                                                * '<S142>/Constant3'
                                                */
extern CALDATA const volatile uint8 RECIRC;/* Referenced by:
                                            * '<S118>/Constant4'
                                            * '<S142>/Constant4'
                                            */
extern CALDATA const volatile float32 cal_ACBatHeatEnvTemp[2];/* Referenced by: '<S1488>/Constant1' */
extern CALDATA const volatile float32 cal_ACBatHeatT1[3];/* Referenced by: '<S1488>/Constant2' */
extern CALDATA const volatile float32 cal_ACBatHeatT2[3];/* Referenced by: '<S1488>/Constant3' */
extern CALDATA const volatile float32 cal_ACBatHeatTave[3];/* Referenced by: '<S1488>/Constant' */
extern CALDATA const volatile float32 cal_ACBatHeatTrgTemp;/* Referenced by:
                                                            * '<S646>/Constant5'
                                                            * '<S1488>/Constant4'
                                                            */
extern CALDATA const volatile float32 cal_ACCMClsEnvTemp;/* Referenced by: '<S441>/Relay' */
extern CALDATA const volatile float32 cal_ACCMCtlDownlmt;/* Referenced by: '<S565>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtlKiDeadzoneNeg;/* Referenced by: '<S445>/Constant9' */
extern CALDATA const volatile float32 cal_ACCMCtlKiDeadzonePos;/* Referenced by: '<S445>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtlKpDeadzoneNeg;/* Referenced by: '<S445>/Constant10' */
extern CALDATA const volatile float32 cal_ACCMCtlKpDeadzonePos;/* Referenced by: '<S445>/Constant11' */
extern CALDATA const volatile float32 cal_ACCMCtlPID_IsumMax;/* Referenced by: '<S445>/Constant13' */
extern CALDATA const volatile float32 cal_ACCMCtlPID_IsumMin;/* Referenced by: '<S445>/Constant12' */
extern CALDATA const volatile float32 cal_ACCMCtlUplmt;/* Referenced by: '<S565>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlA1FF_1X[6];
                              /* Referenced by: '<S580>/cal_ACCMCtrlA1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlA1FF_CUR[6];
                              /* Referenced by: '<S580>/cal_ACCMCtrlA1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_2X[6];
                             /* Referenced by: '<S580>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_2Y[5];
                             /* Referenced by: '<S580>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_MAP[30];
                             /* Referenced by: '<S580>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlACct;/* Referenced by:
                                                        * '<S580>/Constant2'
                                                        * '<S582>/Constant2'
                                                        * '<S583>/Constant2'
                                                        * '<S584>/Constant2'
                                                        * '<S585>/Constant2'
                                                        */
extern CALDATA const volatile float32 cal_ACCMCtrlADeadzone;/* Referenced by: '<S580>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlADlyTime;/* Referenced by: '<S580>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKi_1X[8];
                               /* Referenced by: '<S580>/cal_ACCMCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKi_CUR[8];
                               /* Referenced by: '<S580>/cal_ACCMCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKp_1X[8];
                               /* Referenced by: '<S580>/cal_ACCMCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKp_CUR[8];
                               /* Referenced by: '<S580>/cal_ACCMCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAPIMax;/* Referenced by: '<S580>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlAPIMin;/* Referenced by: '<S580>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlARunTime;/* Referenced by: '<S580>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlBDeadzone;/* Referenced by: '<S581>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlBDlyTime;/* Referenced by: '<S581>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlBFF_1X[6];
                              /* Referenced by: '<S581>/cal_ACCMCtrlB1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBFF_CUR[6];
                              /* Referenced by: '<S581>/cal_ACCMCtrlB1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKi_1X[8];
                               /* Referenced by: '<S581>/cal_ACCMCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKi_CUR[8];
                               /* Referenced by: '<S581>/cal_ACCMCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKp_1X[8];
                               /* Referenced by: '<S581>/cal_ACCMCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKp_CUR[8];
                               /* Referenced by: '<S581>/cal_ACCMCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBPIMax;/* Referenced by: '<S581>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlBPIMin;/* Referenced by: '<S581>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlBRunTime;/* Referenced by: '<S581>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlC1FF_1X[5];
                              /* Referenced by: '<S582>/cal_ACCMCtrlC1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC1FF_CUR[5];
                              /* Referenced by: '<S582>/cal_ACCMCtrlC1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC2FF_1X[4];
                              /* Referenced by: '<S582>/cal_ACCMCtrlC2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC2FF_CUR[4];
                              /* Referenced by: '<S582>/cal_ACCMCtrlC2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCDeadzone;/* Referenced by: '<S582>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlCDlyTime;/* Referenced by: '<S582>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKi_1X[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKi_CUR[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKp_1X[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKp_CUR[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCPIMax;/* Referenced by: '<S582>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlCPIMin;/* Referenced by: '<S582>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlCRunTime;/* Referenced by: '<S582>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlD1FF_1X[3];
                              /* Referenced by: '<S583>/cal_ACCMCtrlD1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD1FF_CUR[3];
                              /* Referenced by: '<S583>/cal_ACCMCtrlD1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD2FF_1X[4];
                              /* Referenced by: '<S583>/cal_ACCMCtrlD2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD2FF_CUR[4];
                              /* Referenced by: '<S583>/cal_ACCMCtrlD2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDDeadzone;/* Referenced by: '<S583>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlDDlyTime;/* Referenced by: '<S583>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKi_1X[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKi_CUR[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKp_1X[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKp_CUR[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMax_1X[5];
                            /* Referenced by: '<S583>/cal_ACCMCtrlDPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMax_CUR[5];
                            /* Referenced by: '<S583>/cal_ACCMCtrlDPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMin;/* Referenced by: '<S583>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlDRunTime;/* Referenced by: '<S583>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlDTrg_1X[7];
                              /* Referenced by: '<S583>/cal_ACCMCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDTrg_CUR[7];
                              /* Referenced by: '<S583>/cal_ACCMCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE1FF_1X[7];
                              /* Referenced by: '<S584>/cal_ACCMCtrlE1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE1FF_CUR[7];
                              /* Referenced by: '<S584>/cal_ACCMCtrlE1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE2FF_1X[4];
                              /* Referenced by: '<S584>/cal_ACCMCtrlE2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE2FF_CUR[4];
                              /* Referenced by: '<S584>/cal_ACCMCtrlE2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEDeadzone;/* Referenced by: '<S584>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlEDlyTime;/* Referenced by: '<S584>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKi_1X[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKi_CUR[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKp_1X[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKp_CUR[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEPIMax;/* Referenced by: '<S584>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlEPIMin;/* Referenced by: '<S584>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlERunTime;/* Referenced by: '<S584>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlETrgTemp;/* Referenced by:
                                                            * '<S584>/Constant4'
                                                            * '<S584>/Constant6'
                                                            */
extern CALDATA const volatile float32 cal_ACCMCtrlF1FF_1X[5];
                              /* Referenced by: '<S585>/cal_ACCMCtrlF1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF1FF_CUR[5];
                              /* Referenced by: '<S585>/cal_ACCMCtrlF1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF2FF_1X[5];
                              /* Referenced by: '<S585>/cal_ACCMCtrlF2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF2FF_CUR[5];
                              /* Referenced by: '<S585>/cal_ACCMCtrlF2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFDeadzone;/* Referenced by: '<S585>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlFDlyTime;/* Referenced by: '<S585>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKi_1X[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlFKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKi_CUR[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlFKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKp_1X[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlFKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKp_CUR[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlFKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMax_1X[5];
                            /* Referenced by: '<S585>/cal_ACCMCtrlFPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMax_CUR[5];
                            /* Referenced by: '<S585>/cal_ACCMCtrlFPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMin;/* Referenced by: '<S585>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlFRunTime;/* Referenced by: '<S585>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlH1FF_1X[5];
                              /* Referenced by: '<S587>/cal_ACCMCtrlH1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH1FF_CUR[5];
                              /* Referenced by: '<S587>/cal_ACCMCtrlH1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH2FF_1X[4];
                              /* Referenced by: '<S587>/cal_ACCMCtrlH2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH2FF_CUR[4];
                              /* Referenced by: '<S587>/cal_ACCMCtrlH2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHCct;/* Referenced by: '<S587>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlHDeadzone;/* Referenced by: '<S587>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlHDlyTime;/* Referenced by: '<S587>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKi_1X[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlHKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKi_CUR[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlHKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKp_1X[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlHKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKp_CUR[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlHKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHPIMax;/* Referenced by: '<S587>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlHPIMin;/* Referenced by: '<S587>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlHRunTime;/* Referenced by: '<S587>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlKi;/* Referenced by: '<S445>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlKp;/* Referenced by: '<S445>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlSpdData;/* Referenced by: '<S566>/Constant' */
extern CALDATA const volatile boolean cal_ACCMCtrlSpdDataEnb;/* Referenced by: '<S566>/Constant1' */
extern CALDATA const volatile boolean cal_ACCMEnbData;/* Referenced by: '<S457>/Constant' */
extern CALDATA const volatile boolean cal_ACCMEnbDataEnb;/* Referenced by: '<S457>/Constant1' */
extern CALDATA const volatile boolean cal_ACCMForbidCtrl;/* Referenced by:
                                                          * '<S437>/Constant'
                                                          * '<S945>/Constant3'
                                                          * '<S1645>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_ACCMHiTempData;/* Referenced by: '<S1866>/Constant' */
extern CALDATA const volatile boolean cal_ACCMHiTempDataEnb;/* Referenced by: '<S1866>/Constant1' */
extern CALDATA const volatile uint8 cal_ACCMHiTempFanCtrl;/* Referenced by: '<S915>/Constant5' */
extern CALDATA const volatile float32 cal_ACCMHiTempFanOff;/* Referenced by: '<S915>/Relay' */
extern CALDATA const volatile float32 cal_ACCMHiTempFanOn;/* Referenced by: '<S915>/Relay' */
extern CALDATA const volatile uint16 cal_ACCMHighTempVolAmend_1X[2];
                     /* Referenced by: '<S1720>/cal_ACCMHighTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ACCMHighTempVolAmend_CUR[2];
                     /* Referenced by: '<S1720>/cal_ACCMHighTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ACCMOpenEnvTemp;/* Referenced by: '<S441>/Relay' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2X[12];
                     /* Referenced by: '<S182>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2Y[12];
                     /* Referenced by: '<S182>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_MAP[144];
                     /* Referenced by: '<S182>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2X[12];
                        /* Referenced by: '<S182>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2Y[12];
                        /* Referenced by: '<S182>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_MAP[144];
                        /* Referenced by: '<S182>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACChgBatHighSOCHeat;/* Referenced by:
                                                               * '<S1442>/Relay'
                                                               * '<S1469>/Relay'
                                                               * '<S1348>/Constant'
                                                               * '<S1609>/Constant'
                                                               * '<S1621>/Constant'
                                                               * '<S1623>/Constant'
                                                               * '<S1625>/Constant'
                                                               * '<S1331>/Constant'
                                                               */
extern CALDATA const volatile float32 cal_ACChgBatLowSOCHeat;/* Referenced by:
                                                              * '<S1442>/Relay'
                                                              * '<S1469>/Relay'
                                                              * '<S1350>/Constant'
                                                              * '<S1611>/Constant'
                                                              * '<S1619>/Constant'
                                                              * '<S1329>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_1X[7];
                     /* Referenced by: '<S1493>/cal_ACChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_CUR[7];
                     /* Referenced by: '<S1493>/cal_ACChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForACHotStart;/* Referenced by:
                                                                    * '<S43>/Kp11'
                                                                    * '<S161>/Constant'
                                                                    */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForAQS;/* Referenced by:
                                                             * '<S43>/Kp4'
                                                             * '<S165>/Constant'
                                                             */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForForceChange;/* Referenced by:
                                                                     * '<S43>/Kp3'
                                                                     * '<S125>/Constant11'
                                                                     * '<S125>/Constant9'
                                                                     * '<S159>/Constant'
                                                                     */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForForceDefog;/* Referenced by:
                                                                    * '<S43>/Kp12'
                                                                    * '<S167>/Constant'
                                                                    */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForManual;/* Referenced by:
                                                                * '<S43>/Kp1'
                                                                * '<S168>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForNormalDefog;/* Referenced by:
                                                                     * '<S43>/Kp5'
                                                                     * '<S156>/Constant2'
                                                                     */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForPCUTemp;/* Referenced by:
                                                                 * '<S43>/Kp15'
                                                                 * '<S166>/Constant'
                                                                 */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForPTCDvt;/* Referenced by:
                                                                * '<S43>/Kp10'
                                                                * '<S157>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForQkChargeCooling;/* Referenced by:
                                                                      * '<S43>/Kp14'
                                                                      * '<S158>/Constant'
                                                                      */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForRemoteAC;/* Referenced by:
                                                                  * '<S43>/Kp13'
                                                                  * '<S160>/Constant'
                                                                  */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForSummer;/* Referenced by:
                                                                * '<S43>/Kp8'
                                                                * '<S156>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForTargetOutTemp;/* Referenced by:
                                                                      * '<S43>/Kp6'
                                                                      * '<S162>/Constant'
                                                                      */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForTempLow;/* Referenced by:
                                                                 * '<S43>/Kp2'
                                                                 * '<S164>/Constant'
                                                                 */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForVent;/* Referenced by:
                                                              * '<S43>/Kp7'
                                                              * '<S163>/Constant'
                                                              */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForWinter;/* Referenced by:
                                                                * '<S43>/Kp9'
                                                                * '<S156>/Constant1'
                                                                */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2X[10];
                          /* Referenced by: '<S182>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2Y[10];
                          /* Referenced by: '<S182>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_MAP[100];
                          /* Referenced by: '<S182>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_1X[16];
                         /* Referenced by: '<S182>/cal_ACDVTPreSetEnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_CUR[16];
                         /* Referenced by: '<S182>/cal_ACDVTPreSetEnvCor_CUR' */
extern CALDATA const volatile uint16 cal_ACDVTPreSetSolarCorByVx_2X[6];
                   /* Referenced by: '<S182>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_2Y[6];
                   /* Referenced by: '<S182>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_MAP[36];
                   /* Referenced by: '<S182>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile uint16 cal_ACDVTPreSetSolarCor_2X[8];
                       /* Referenced by: '<S182>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_2Y[8];
                       /* Referenced by: '<S182>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_MAP[64];
                       /* Referenced by: '<S182>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile uint16 cal_ACDrDVTSolarCor_2X[15];
                           /* Referenced by: '<S178>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDrDVTSolarCor_2Y[15];
                           /* Referenced by: '<S178>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDrDVTSolarCor_MAP[225];
                           /* Referenced by: '<S178>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanLevel0EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel0EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel0EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel0EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel1EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel1EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel1EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel1EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel2EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel2EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel2EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel2EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel3EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel3EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel3EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel3EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel4EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel4EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel4EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel4EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel5EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel5EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel5EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel5EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel6EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel6EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel6EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel6EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel7EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel7EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel7EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel7EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel8EnvCor_1X[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel8EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel8EnvCor_CUR[2];
                          /* Referenced by: '<S49>/cal_ACFanLevel8EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanMaxSpdCellTempLim_1X[5];
                         /* Referenced by: '<S47>/cal_ACFanMaxSpdCellTempLim' */
extern CALDATA const volatile uint8 cal_ACFanMaxSpdCellTempLim_CUR[5];
                         /* Referenced by: '<S47>/cal_ACFanMaxSpdCellTempLim' */
extern CALDATA const volatile float32 cal_ACFanMaxSpdDvtLim_1X[5];
                          /* Referenced by: '<S47>/cal_ACFanMaxSpdDvtLim_CUR' */
extern CALDATA const volatile uint8 cal_ACFanMaxSpdDvtLim_CUR[5];
                          /* Referenced by: '<S47>/cal_ACFanMaxSpdDvtLim_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdBatCor_1X[3];
                             /* Referenced by: '<S53>/cal_ACFanSpdBatCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdBatCor_CUR[3];
                             /* Referenced by: '<S53>/cal_ACFanSpdBatCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdDvtSet_1X[14];
                            /* Referenced by: '<S53>/cal_ACFanSpdDvtSet_CUR ' */
extern CALDATA const volatile float32 cal_ACFanSpdDvtSet_CUR[14];
                            /* Referenced by: '<S53>/cal_ACFanSpdDvtSet_CUR ' */
extern CALDATA const volatile float32 cal_ACFanSpdRecircCor_1X[4];
                          /* Referenced by: '<S53>/cal_ACFanSpdRecircCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdRecircCor_CUR[4];
                          /* Referenced by: '<S53>/cal_ACFanSpdRecircCor_CUR' */
extern CALDATA const volatile uint16 cal_ACFanSpdSolarCorByEnv_2X[15];
                      /* Referenced by: '<S53>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_2Y[15];
                      /* Referenced by: '<S53>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_MAP[225];
                      /* Referenced by: '<S53>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACFanSpdSolarCor_2X[15];
                           /* Referenced by: '<S53>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCor_2Y[15];
                           /* Referenced by: '<S53>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCor_MAP[225];
                           /* Referenced by: '<S53>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdVssCor_1X[3];
                             /* Referenced by: '<S53>/cal_ACFanSpdVssCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdVssCor_CUR[3];
                             /* Referenced by: '<S53>/cal_ACFanSpdVssCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletAutoDefogPrtEnvCor_1X[10];
                 /* Referenced by: '<S137>/cal_ACInletAutoDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletAutoDefogPrtEnvCor_CUR[10];
                 /* Referenced by: '<S137>/cal_ACInletAutoDefogPrtEnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletDefogPrtEnvCor_1X[10];
                     /* Referenced by: '<S137>/cal_ACInletDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogPrtEnvCor_CUR[10];
                     /* Referenced by: '<S137>/cal_ACInletDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogRiskCor_1X[2];
                       /* Referenced by: '<S137>/cal_ACInletDefogRiskCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogRiskCor_CUR[2];
                       /* Referenced by: '<S137>/cal_ACInletDefogRiskCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletEnvPrtSetCool_1X[5];
                      /* Referenced by: '<S120>/cal_ACInletEnvPrtSetCool_CUR' */
extern CALDATA const volatile uint8 cal_ACInletEnvPrtSetCool_CUR[5];
                      /* Referenced by: '<S120>/cal_ACInletEnvPrtSetCool_CUR' */
extern CALDATA const volatile float32 cal_ACInletEnvPrtSetHeat_1X[5];
                      /* Referenced by: '<S120>/cal_ACInletEnvPrtSetHeat_CUR' */
extern CALDATA const volatile uint8 cal_ACInletEnvPrtSetHeat_CUR[5];
                      /* Referenced by: '<S120>/cal_ACInletEnvPrtSetHeat_CUR' */
extern CALDATA const volatile uint8 cal_ACPMPSpdDiffVal;/* Referenced by: '<S1020>/Constant' */
extern CALDATA const volatile float32 cal_ACPTCDesBacAC_1X[12];
                             /* Referenced by: '<S338>/cal_ACPTCDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacAC_CUR[12];
                             /* Referenced by: '<S338>/cal_ACPTCDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacBi_1X[12];
                             /* Referenced by: '<S338>/cal_ACPTCDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacBi_CUR[12];
                             /* Referenced by: '<S338>/cal_ACPTCDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacDefog_1X[12];
                          /* Referenced by: '<S338>/cal_ACPTCDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacDefog_CUR[12];
                          /* Referenced by: '<S338>/cal_ACPTCDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFootDe_1X[12];
                         /* Referenced by: '<S338>/cal_ACPTCDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFootDe_CUR[12];
                         /* Referenced by: '<S338>/cal_ACPTCDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFoot_1X[12];
                           /* Referenced by: '<S338>/cal_ACPTCDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFoot_CUR[12];
                           /* Referenced by: '<S338>/cal_ACPTCDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesCabinCor_1X[8];
                          /* Referenced by: '<S338>/cal_ACPTCDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesCabinCor_CUR[8];
                          /* Referenced by: '<S338>/cal_ACPTCDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_2X[6];
                            /* Referenced by: '<S338>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_2Y[6];
                            /* Referenced by: '<S338>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_MAP[36];
                            /* Referenced by: '<S338>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPTCDesFanCor_1X[4];
                            /* Referenced by: '<S338>/cal_ACPTCDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesFanCor_CUR[4];
                            /* Referenced by: '<S338>/cal_ACPTCDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacAC_1X[12];
                           /* Referenced by: '<S360>/cal_ACPTCPsDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacAC_CUR[12];
                           /* Referenced by: '<S360>/cal_ACPTCPsDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacBi_1X[12];
                           /* Referenced by: '<S360>/cal_ACPTCPsDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacBi_CUR[12];
                           /* Referenced by: '<S360>/cal_ACPTCPsDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_1X[12];
                        /* Referenced by: '<S360>/cal_ACPTCPsDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_CUR[12];
                        /* Referenced by: '<S360>/cal_ACPTCPsDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_1X[12];
                       /* Referenced by: '<S360>/cal_ACPTCPsDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_CUR[12];
                       /* Referenced by: '<S360>/cal_ACPTCPsDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_1X[12];
                         /* Referenced by: '<S360>/cal_ACPTCPsDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_CUR[12];
                         /* Referenced by: '<S360>/cal_ACPTCPsDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_1X[8];
                        /* Referenced by: '<S360>/cal_ACPTCPsDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_CUR[8];
                        /* Referenced by: '<S360>/cal_ACPTCPsDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2X[6];
                          /* Referenced by: '<S360>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2Y[6];
                          /* Referenced by: '<S360>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_MAP[36];
                          /* Referenced by: '<S360>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPTCPsDesFanCor_1X[4];
                          /* Referenced by: '<S360>/cal_ACPTCPsDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesFanCor_CUR[4];
                          /* Referenced by: '<S360>/cal_ACPTCPsDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPwrPreSetByEnv_2X[10];
                        /* Referenced by: '<S91>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPwrPreSetByEnv_2Y[10];
                        /* Referenced by: '<S91>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACPTCPwrPreSetByEnv_MAP[100];
                        /* Referenced by: '<S91>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2X[14];
                        /* Referenced by: '<S179>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2Y[14];
                        /* Referenced by: '<S179>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_MAP[196];
                        /* Referenced by: '<S179>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACPsDVTSolarCor_2X[15];
                           /* Referenced by: '<S179>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSolarCor_2Y[15];
                           /* Referenced by: '<S179>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSolarCor_MAP[225];
                           /* Referenced by: '<S179>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPumpBatHeatSpd;/* Referenced by:
                                                          * '<S1020>/Constant18'
                                                          * '<S1020>/Constant6'
                                                          */
extern CALDATA const volatile uint8 cal_ACPumpCtrlASpd;/* Referenced by: '<S1020>/Constant1' */
extern CALDATA const volatile uint8 cal_ACPumpDefSpd;/* Referenced by:
                                                      * '<S1020>/Constant17'
                                                      * '<S1020>/Constant2'
                                                      */
extern CALDATA const volatile uint8 cal_ACPumpDehSpd;/* Referenced by: '<S1020>/Constant8' */
extern CALDATA const volatile uint8 cal_ACPumpDoubleHeatSpd;/* Referenced by: '<S1020>/Constant7' */
extern CALDATA const volatile uint8 cal_ACRecirRatioLmt;/* Referenced by:
                                                         * '<S279>/Constant2'
                                                         * '<S304>/Constant2'
                                                         * '<S338>/Constant2'
                                                         * '<S360>/Constant2'
                                                         * '<S53>/Constant2'
                                                         */
extern CALDATA const volatile float32 cal_ADCVCCVal;/* Referenced by:
                                                     * '<S1701>/Constant2'
                                                     * '<S1705>/Constant1'
                                                     * '<S1706>/Constant1'
                                                     * '<S1712>/Constant1'
                                                     * '<S1713>/Constant2'
                                                     * '<S1714>/Constant1'
                                                     * '<S1715>/Constant1'
                                                     * '<S1716>/Constant1'
                                                     * '<S1717>/Constant1'
                                                     * '<S1718>/Constant1'
                                                     * '<S1720>/Constant1'
                                                     */
extern CALDATA const volatile float32 cal_AEXVClsEvapPrtTemp;
                                   /* Referenced by: '<S681>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVClsValEvapPrt;/* Referenced by:
                                                             * '<S681>/EvapTemperature'
                                                             * '<S681>/Constant3'
                                                             */
extern CALDATA const volatile float32 cal_AEXVClsValRunTimeEvapPrt;
                                   /* Referenced by: '<S681>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVCtlKi;/* Referenced by: '<S678>/Constant11' */
extern CALDATA const volatile float32 cal_AEXVCtlKisumMax;/* Referenced by: '<S678>/Constant8' */
extern CALDATA const volatile float32 cal_AEXVCtlKisumMin;/* Referenced by: '<S678>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVCtlKp;/* Referenced by: '<S678>/Constant10' */
extern CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_1X[6];
                   /* Referenced by: '<S713>/cal_AEXVCtrlBCabinCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_CUR[6];
                   /* Referenced by: '<S713>/cal_AEXVCtrlBCabinCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_1X[6];
                       /* Referenced by: '<S713>/cal_AEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_CUR[6];
                       /* Referenced by: '<S713>/cal_AEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDeadzone;/* Referenced by: '<S713>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDelayTime;/* Referenced by: '<S713>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlBFF_1X[5];
                               /* Referenced by: '<S713>/cal_AEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBFF_CUR[5];
                               /* Referenced by: '<S713>/cal_AEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKi_1X[8];
                               /* Referenced by: '<S713>/cal_AEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKi_CUR[8];
                               /* Referenced by: '<S713>/cal_AEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKp_1X[8];
                               /* Referenced by: '<S713>/cal_AEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKp_CUR[8];
                               /* Referenced by: '<S713>/cal_AEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBOpenVal;/* Referenced by: '<S713>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlBPIMax;/* Referenced by: '<S713>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlBPIMin;/* Referenced by: '<S713>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_1X[9];
                /* Referenced by: '<S713>/cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR[9];
                /* Referenced by: '<S713>/cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_1X[9];
                       /* Referenced by: '<S713>/cal_AEXVCtrlBTrgSubCool_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_CUR[9];
                       /* Referenced by: '<S713>/cal_AEXVCtrlBTrgSubCool_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCDeadzone;/* Referenced by: '<S714>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlCDelayTime;/* Referenced by: '<S714>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlCFF_1X[5];
                               /* Referenced by: '<S714>/cal_AEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCFF_CUR[5];
                               /* Referenced by: '<S714>/cal_AEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKi_1X[7];
                               /* Referenced by: '<S714>/cal_AEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKi_CUR[7];
                               /* Referenced by: '<S714>/cal_AEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKp_1X[7];
                               /* Referenced by: '<S714>/cal_AEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKp_CUR[7];
                               /* Referenced by: '<S714>/cal_AEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCOpenVal;/* Referenced by: '<S714>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlCPIMax;/* Referenced by: '<S714>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlCPIMin;/* Referenced by: '<S714>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgflt;/* Referenced by: '<S714>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_1X[7];
                    /* Referenced by: '<S714>/cal_AEXVCtrlCTrgtSuperHeat_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_CUR[7];
                    /* Referenced by: '<S714>/cal_AEXVCtrlCTrgtSuperHeat_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDDeadzone;/* Referenced by: '<S715>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlDDelayTime;/* Referenced by: '<S715>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlDFF_1X[5];
                               /* Referenced by: '<S715>/cal_AEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDFF_CUR[5];
                               /* Referenced by: '<S715>/cal_AEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKi_1X[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKi_CUR[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKp_1X[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKp_CUR[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDOpenVal;/* Referenced by: '<S715>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlDPIMax;/* Referenced by: '<S715>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlDPIMin;/* Referenced by: '<S715>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlDTrg_1X[3];
                              /* Referenced by: '<S715>/cal_AEXVCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDTrg_CUR[3];
                              /* Referenced by: '<S715>/cal_AEXVCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDefaultPos;/* Referenced by: '<S716>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVDiffDown;/* Referenced by: '<S737>/Constant8' */
extern CALDATA const volatile float32 cal_AEXVDiffDownRate;/* Referenced by: '<S737>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVDiffUp;/* Referenced by: '<S737>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVDiffUpRate;/* Referenced by: '<S737>/Constant5' */
extern CALDATA const volatile float32 cal_AEXVDownSpdLmt;/* Referenced by:
                                                          * '<S742>/DownLmt'
                                                          * '<S742>/DownLmt1'
                                                          */
extern CALDATA const volatile boolean cal_AEXVEnbData;/* Referenced by: '<S684>/Constant' */
extern CALDATA const volatile boolean cal_AEXVEnbDataEnb;/* Referenced by: '<S684>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVFloorDiff1;/* Referenced by: '<S740>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVFloorDiff2;/* Referenced by: '<S740>/Constant' */
extern CALDATA const volatile float32 cal_AEXVFltClsSpd;/* Referenced by: '<S681>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVHighPressLmtOn;/* Referenced by: '<S737>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVHighPressProhOn;/* Referenced by: '<S681>/Constant' */
extern CALDATA const volatile uint8 cal_AEXVInitReqData;/* Referenced by: '<S694>/Constant' */
extern CALDATA const volatile boolean cal_AEXVInitReqDataeEnb;/* Referenced by: '<S694>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVLowPressLmtOn;/* Referenced by: '<S737>/Constant4' */
extern CALDATA const volatile float32 cal_AEXVLowPressProhOn;/* Referenced by: '<S681>/Constant2' */
extern CALDATA const volatile float32 cal_AEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                  * '<S743>/DownLmt'
                                                                  * '<S743>/DownLmt1'
                                                                  */
extern CALDATA const volatile float32 cal_AEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                * '<S743>/UpLmt'
                                                                * '<S743>/UpLmt2'
                                                                */
extern CALDATA const volatile float32 cal_AEXVOpenDelayTimeEvapNOPrt;
                                   /* Referenced by: '<S681>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenEvapNOPrtTemp;
                                   /* Referenced by: '<S681>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenRunTimeEvapNOPrt;
                                   /* Referenced by: '<S681>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenValEvapNOPrt;
                                   /* Referenced by: '<S681>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenValveSpd;/* Referenced by: '<S681>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVPosData;/* Referenced by: '<S738>/Constant' */
extern CALDATA const volatile boolean cal_AEXVPosDataEnb;/* Referenced by: '<S738>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVSubCoolflt;/* Referenced by: '<S713>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVUpSpdLmt;/* Referenced by:
                                                        * '<S742>/UpLmt'
                                                        * '<S742>/UpLmt2'
                                                        */
extern CALDATA const volatile uint8 cal_AQS2InRecThreVal;/* Referenced by: '<S124>/Constant3' */
extern CALDATA const volatile uint8 cal_AQS2OutRecThreVal;/* Referenced by: '<S124>/Constant4' */
extern CALDATA const volatile boolean cal_AcPMPFaultFlgData;/* Referenced by: '<S1034>/Constant' */
extern CALDATA const volatile boolean cal_AcPMPFaultFlgDataEnb;/* Referenced by: '<S1034>/Constant1' */
extern CALDATA const volatile uint8 cal_AcPMPSpdSetData;/* Referenced by: '<S1033>/Constant' */
extern CALDATA const volatile boolean cal_AcPMPSpdSetDataEnb;/* Referenced by: '<S1033>/Constant1' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressDownSide_1X[12];
               /* Referenced by: '<S543>/cal_AccmSpdLimByHiPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressDownSide_CUR[12];
               /* Referenced by: '<S543>/cal_AccmSpdLimByHiPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressLevelCalcu_1X[12];
             /* Referenced by: '<S543>/cal_AccmSpdLimByHiPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressLevelCalcu_CUR[12];
             /* Referenced by: '<S543>/cal_AccmSpdLimByHiPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressUpSide_1X[12];
                 /* Referenced by: '<S543>/cal_AccmSpdLimByHiPressUpSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressUpSide_CUR[12];
                 /* Referenced by: '<S543>/cal_AccmSpdLimByHiPressUpSide_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressDownSide_1X[12];
               /* Referenced by: '<S543>/cal_AccmSpdLimByLoPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressDownSide_CUR[12];
               /* Referenced by: '<S543>/cal_AccmSpdLimByLoPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressLevelCalcu_1X[12];
             /* Referenced by: '<S543>/cal_AccmSpdLimByLoPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressLevelCalcu_CUR[12];
             /* Referenced by: '<S543>/cal_AccmSpdLimByLoPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressUpSide_1X[12];
                 /* Referenced by: '<S543>/cal_AccmSpdLimByLoPressUpSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressUpSide_CUR[12];
                 /* Referenced by: '<S543>/cal_AccmSpdLimByLoPressUpSide_CUR' */
extern CALDATA const volatile uint8 cal_AirInletPerData;/* Referenced by: '<S1785>/Constant' */
extern CALDATA const volatile boolean cal_AirInletPerEnb;/* Referenced by: '<S1785>/Constant1' */
extern CALDATA const volatile float32 cal_AirInletRecInPCUTemp;/* Referenced by: '<S128>/Constant6' */
extern CALDATA const volatile float32 cal_AirInletRecOutPCUTemp;/* Referenced by: '<S128>/Constant1' */
extern CALDATA const volatile boolean cal_AutoDefogEnable;/* Referenced by: '<S137>/Constant1' */
extern CALDATA const volatile boolean cal_AvgSwitch;/* Referenced by:
                                                     * '<S674>/Constant1'
                                                     * '<S674>/Constant4'
                                                     * '<S674>/Constant5'
                                                     * '<S674>/Constant6'
                                                     */
extern CALDATA const volatile uint8 cal_BATPMPSpdDiffVal;/* Referenced by: '<S1021>/Constant' */
extern CALDATA const volatile uint8 cal_BCVFltStsDelayTime;/* Referenced by: '<S662>/Constant5' */
extern CALDATA const volatile float32 cal_BCVPosDiffDelayTime;/* Referenced by: '<S662>/Constant2' */
extern CALDATA const volatile float32 cal_BEXVCtlKi;/* Referenced by: '<S748>/Constant11' */
extern CALDATA const volatile float32 cal_BEXVCtlKisumMax;/* Referenced by: '<S748>/Constant8' */
extern CALDATA const volatile float32 cal_BEXVCtlKisumMin;/* Referenced by: '<S748>/Constant9' */
extern CALDATA const volatile float32 cal_BEXVCtlKp;/* Referenced by: '<S748>/Constant10' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_1X[6];
                       /* Referenced by: '<S781>/cal_BEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_CUR[6];
                       /* Referenced by: '<S781>/cal_BEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDeadzone;/* Referenced by: '<S781>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDelayTime;/* Referenced by: '<S781>/Constant' */
extern CALDATA const volatile float32 cal_BEXVCtrlBFF_1X[5];
                               /* Referenced by: '<S781>/cal_BEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBFF_CUR[5];
                               /* Referenced by: '<S781>/cal_BEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKi_1X[7];
                               /* Referenced by: '<S781>/cal_BEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKi_CUR[7];
                               /* Referenced by: '<S781>/cal_BEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKp_1X[7];
                               /* Referenced by: '<S781>/cal_BEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKp_CUR[7];
                               /* Referenced by: '<S781>/cal_BEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBOpenVal;/* Referenced by: '<S781>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVCtrlBPIDown;/* Referenced by: '<S781>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVCtrlBPIUp;/* Referenced by: '<S781>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_1X[5];
                     /* Referenced by: '<S781>/cal_BEXVCtrlBTrgCabinComp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_CUR[5];
                     /* Referenced by: '<S781>/cal_BEXVCtrlBTrgCabinComp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_1X[6];
                   /* Referenced by: '<S781>/cal_BEXVCtrlBTrgWtrTempDiff_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_CUR[6];
                   /* Referenced by: '<S781>/cal_BEXVCtrlBTrgWtrTempDiff_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_1X[6];
                     /* Referenced by: '<S782>/cal_BEXVCtrlCBatCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_CUR[6];
                     /* Referenced by: '<S782>/cal_BEXVCtrlCBatCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCDeadzone;/* Referenced by: '<S782>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVCtrlCDelayTime;/* Referenced by: '<S782>/Constant' */
extern CALDATA const volatile float32 cal_BEXVCtrlCFF_1X[5];
                               /* Referenced by: '<S782>/cal_BEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCFF_CUR[5];
                               /* Referenced by: '<S782>/cal_BEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKi_1X[8];
                               /* Referenced by: '<S782>/cal_BEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKi_CUR[8];
                               /* Referenced by: '<S782>/cal_BEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKp_1X[8];
                               /* Referenced by: '<S782>/cal_BEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKp_CUR[8];
                               /* Referenced by: '<S782>/cal_BEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCOpenVal;/* Referenced by: '<S782>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVCtrlCPIMax;/* Referenced by: '<S782>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVCtrlCPIMin;/* Referenced by: '<S782>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVCtrlCTrg_1X[5];
                              /* Referenced by: '<S782>/cal_BEXVCtrlCTrg_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCTrg_CUR[5];
                              /* Referenced by: '<S782>/cal_BEXVCtrlCTrg_CUR' */
extern CALDATA const volatile float32 cal_BEXVDiffDown;/* Referenced by: '<S807>/Constant8' */
extern CALDATA const volatile float32 cal_BEXVDiffDownRate;/* Referenced by: '<S807>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVDiffUp;/* Referenced by: '<S807>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVDiffUpRate;/* Referenced by: '<S807>/Constant5' */
extern CALDATA const volatile float32 cal_BEXVDownSpdLmt;/* Referenced by:
                                                          * '<S812>/DownLmt'
                                                          * '<S812>/DownLmt1'
                                                          */
extern CALDATA const volatile boolean cal_BEXVEnbData;/* Referenced by: '<S803>/Constant' */
extern CALDATA const volatile boolean cal_BEXVEnbDataEnb;/* Referenced by: '<S803>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVFloorDiff1;/* Referenced by: '<S810>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVFloorDiff2;/* Referenced by: '<S810>/Constant' */
extern CALDATA const volatile float32 cal_BEXVHighPressLmtOn;/* Referenced by: '<S807>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVHighPressProhOn;/* Referenced by: '<S752>/Constant' */
extern CALDATA const volatile uint8 cal_BEXVInitReqData;/* Referenced by: '<S762>/Constant' */
extern CALDATA const volatile boolean cal_BEXVInitReqDataeEnb;/* Referenced by: '<S762>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVLowPressLmtOn;/* Referenced by: '<S807>/Constant4' */
extern CALDATA const volatile float32 cal_BEXVLowPressProhOn;/* Referenced by: '<S752>/Constant2' */
extern CALDATA const volatile float32 cal_BEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                  * '<S813>/DownLmt'
                                                                  * '<S813>/DownLmt1'
                                                                  */
extern CALDATA const volatile float32 cal_BEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                * '<S813>/UpLmt'
                                                                * '<S813>/UpLmt2'
                                                                */
extern CALDATA const volatile float32 cal_BEXVOpenValveSpd;/* Referenced by: '<S752>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVPosData;/* Referenced by: '<S808>/Constant' */
extern CALDATA const volatile boolean cal_BEXVPosDataEnb;/* Referenced by: '<S808>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVSubCoolflt;/* Referenced by: '<S782>/Constant10' */
extern CALDATA const volatile float32 cal_BEXVSubHeatflt;/* Referenced by: '<S781>/Constant12' */
extern CALDATA const volatile float32 cal_BEXVUpSpdLmt;/* Referenced by:
                                                        * '<S812>/UpLmt'
                                                        * '<S812>/UpLmt2'
                                                        */
extern CALDATA const volatile float32 cal_BMSInletTempHighOffMCV;/* Referenced by: '<S639>/Relay' */
extern CALDATA const volatile float32 cal_BMSInletTempLowOnMCV;/* Referenced by: '<S639>/Relay' */
extern CALDATA const volatile float32 cal_BatBalCellTemp1;/* Referenced by:
                                                           * '<S1295>/Constant1'
                                                           * '<S1298>/Constant1'
                                                           * '<S1535>/Constant'
                                                           * '<S1538>/Constant'
                                                           * '<S1574>/Constant'
                                                           * '<S1320>/Constant1'
                                                           * '<S1333>/Constant4'
                                                           * '<S1551>/Constant'
                                                           * '<S1558>/Constant'
                                                           * '<S1563>/Constant'
                                                           * '<S1579>/Constant'
                                                           * '<S1583>/Constant'
                                                           * '<S1617>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatBalCellTemp2;/* Referenced by:
                                                           * '<S1295>/Constant2'
                                                           * '<S1298>/Constant2'
                                                           * '<S1301>/Constant'
                                                           * '<S1423>/Constant'
                                                           * '<S1524>/Constant'
                                                           * '<S1601>/Constant'
                                                           * '<S1613>/Constant4'
                                                           * '<S1614>/Constant4'
                                                           * '<S1615>/Constant4'
                                                           * '<S1617>/Constant4'
                                                           * '<S1324>/Constant4'
                                                           * '<S1325>/Constant4'
                                                           * '<S1326>/Constant4'
                                                           * '<S1418>/Constant'
                                                           * '<S1517>/Constant'
                                                           * '<S1633>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatCoolInletTrgTemp;/* Referenced by:
                                                               * '<S581>/Constant3'
                                                               * '<S587>/Constant5'
                                                               * '<S781>/Constant11'
                                                               */
extern CALDATA const volatile boolean cal_BatCoolOverData;/* Referenced by: '<S1357>/Constant' */
extern CALDATA const volatile boolean cal_BatCoolOverEnb;/* Referenced by: '<S1357>/Constant1' */
extern CALDATA const volatile uint16 cal_BatCoolStopBatPMPRunTime;/* Referenced by: '<S1021>/Constant16' */
extern CALDATA const volatile uint8 cal_BatCoolStopBatPMPSpd;/* Referenced by: '<S1021>/Constant15' */
extern CALDATA const volatile float32 cal_BatCoolTrgFilter;/* Referenced by:
                                                            * '<S581>/Constant5'
                                                            * '<S584>/Constant9'
                                                            */
extern CALDATA const volatile boolean cal_BatHeatACCMEnb;/* Referenced by:
                                                          * '<S459>/Constant1'
                                                          * '<S589>/Constant9'
                                                          */
extern CALDATA const volatile boolean cal_BatHeatOverData;/* Referenced by: '<S1440>/Constant' */
extern CALDATA const volatile boolean cal_BatHeatOverEnb;/* Referenced by: '<S1440>/Constant1' */
extern CALDATA const volatile float32 cal_BatHeatPwrLoLmt;/* Referenced by:
                                                           * '<S1380>/Constant'
                                                           * '<S1465>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatHeatTrgTemp;/* Referenced by: '<S945>/Constant5' */
extern CALDATA const volatile float32 cal_BatHeatTrgTempComp_1X[11];
                       /* Referenced by: '<S1493>/cal_BatHeatTrgTempComp_CUR' */
extern CALDATA const volatile float32 cal_BatHeatTrgTempComp_CUR[11];
                       /* Referenced by: '<S1493>/cal_BatHeatTrgTempComp_CUR' */
extern CALDATA const volatile BatModes cal_BatModeData;/* Referenced by: '<S1435>/Constant' */
extern CALDATA const volatile boolean cal_BatModeEnb;/* Referenced by: '<S1435>/Constant1' */
extern CALDATA const volatile boolean cal_BatModeSwitch;/* Referenced by:
                                                         * '<S30>/Constant1'
                                                         * '<S1273>/Constant'
                                                         */
extern CALDATA const volatile boolean cal_BatModeTestCtrl;/* Referenced by: '<S661>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPFaultFlgData;/* Referenced by: '<S1050>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPFaultFlgDataEnb;/* Referenced by: '<S1050>/Constant1' */
extern CALDATA const volatile uint8 cal_BatPMPSpdSetData;/* Referenced by: '<S1049>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPSpdSetDataEnb;/* Referenced by: '<S1049>/Constant1' */
extern CALDATA const volatile float32 cal_BatPumpBal_1X[4];
                               /* Referenced by: '<S1021>/cal_BatPumpBal_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpBal_CUR[4];
                               /* Referenced by: '<S1021>/cal_BatPumpBal_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpCtrlASpd;/* Referenced by:
                                                         * '<S1021>/Constant1'
                                                         * '<S1021>/Constant4'
                                                         */
extern CALDATA const volatile uint8 cal_BatPumpMotHeatBatSpd;/* Referenced by: '<S1021>/Constant13' */
extern CALDATA const volatile uint8 cal_BatPumpMotLTRAndBatCHSpd;/* Referenced by: '<S1021>/Constant14' */
extern CALDATA const volatile float32 cal_BatPumpThSto_1X[4];
                             /* Referenced by: '<S1021>/cal_BatPumpThSto_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpThSto_CUR[4];
                             /* Referenced by: '<S1021>/cal_BatPumpThSto_CUR' */
extern CALDATA const volatile float32 cal_BatTrgTempData;/* Referenced by: '<S1292>/Constant' */
extern CALDATA const volatile boolean cal_BatTrgTempEnb;/* Referenced by: '<S1292>/Constant1' */
extern CALDATA const volatile float32 cal_BetwT1AndT2DownMCV_1X[6];
                        /* Referenced by: '<S645>/cal_BetwT1AndT2DownMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2DownMCV_CUR[6];
                        /* Referenced by: '<S645>/cal_BetwT1AndT2DownMCV_CUR' */
extern CALDATA const volatile float32 cal_BetwT1AndT2StbyMCV_1X[6];
                        /* Referenced by: '<S645>/cal_BetwT1AndT2StbyMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2StbyMCV_CUR[6];
                        /* Referenced by: '<S645>/cal_BetwT1AndT2StbyMCV_CUR' */
extern CALDATA const volatile float32 cal_BetwT1AndT2UpMCV_1X[6];
                          /* Referenced by: '<S645>/cal_BetwT1AndT2UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2UpMCV_CUR[6];
                          /* Referenced by: '<S645>/cal_BetwT1AndT2UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_BlowerFanSpdLL;/* Referenced by: '<S48>/Constant14' */
extern CALDATA const volatile uint8 cal_BlowerFanSpdVentUL;/* Referenced by: '<S47>/Constant29' */
extern CALDATA const volatile uint8 cal_BlwFanData;/* Referenced by: '<S1204>/Constant' */
extern CALDATA const volatile boolean cal_BlwFanEnb;/* Referenced by: '<S1204>/Constant1' */
extern CALDATA const volatile uint16 cal_BlwFrqVal;/* Referenced by: '<S1186>/Constant5' */
extern CALDATA const volatile uint8 cal_C3WVExhPosVal;/* Referenced by: '<S639>/Constant7' */
extern CALDATA const volatile uint8 cal_C3WVSLStsData;/* Referenced by: '<S658>/Constant' */
extern CALDATA const volatile boolean cal_C3WVSLStsDataEnb;/* Referenced by: '<S658>/Constant1' */
extern CALDATA const volatile uint8 cal_C5WVExhPosVal;/* Referenced by: '<S661>/Constant11' */
extern CALDATA const volatile uint8 cal_C5WVSLStsData;/* Referenced by: '<S668>/Constant' */
extern CALDATA const volatile boolean cal_C5WVSLStsDataEnb;/* Referenced by: '<S668>/Constant1' */
extern CALDATA const volatile boolean cal_CANAliveEnable;/* Referenced by: '<S2>/Constant' */
extern CALDATA const volatile sint16 cal_CAPStartCoolantMin;
                             /* Referenced by: '<S36>/AirConditionStartState' */
extern CALDATA const volatile uint8 cal_CO2RecircRatio;/* Referenced by: '<S43>/Constant14' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_1X[8];
                      /* Referenced by: '<S543>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_CUR[8];
                      /* Referenced by: '<S543>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_2X[10];
                         /* Referenced by: '<S543>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile uint8 cal_COMPATNoiseSpdLmt_2Y[10];
                         /* Referenced by: '<S543>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_MAP[100];
                         /* Referenced by: '<S543>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile float32 cal_COMPActlSpd1;/* Referenced by: '<S539>/Constant' */
extern CALDATA const volatile float32 cal_COMPActlSpd2;/* Referenced by: '<S540>/Constant' */
extern CALDATA const volatile float32 cal_COMPActlSpd3;/* Referenced by: '<S541>/Constant' */
extern CALDATA const volatile float32 cal_COMPBatMaxSpdLmt;/* Referenced by: '<S544>/Constant2' */
extern CALDATA const volatile float32 cal_COMPCabinCoolMaxSpdLmt;/* Referenced by: '<S544>/Constant3' */
extern CALDATA const volatile float32 cal_COMPClsLowSpeed;/* Referenced by:
                                                           * '<S560>/Constant'
                                                           * '<S475>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_COMPCoolLowSpd;/* Referenced by:
                                                          * '<S545>/Constant'
                                                          * '<S548>/Constant'
                                                          * '<S552>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt1_1X[2];
                            /* Referenced by: '<S544>/cal_COMPEnvSpdLmt1_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt1_CUR[2];
                            /* Referenced by: '<S544>/cal_COMPEnvSpdLmt1_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt2_1X[2];
                            /* Referenced by: '<S544>/cal_COMPEnvSpdLmt2_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt2_CUR[2];
                            /* Referenced by: '<S544>/cal_COMPEnvSpdLmt2_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt3_1X[2];
                            /* Referenced by: '<S544>/cal_COMPEnvSpdLmt3_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt3_CUR[2];
                            /* Referenced by: '<S544>/cal_COMPEnvSpdLmt3_CUR' */
extern CALDATA const volatile float32 cal_COMPEvapTFrbVal;/* Referenced by: '<S454>/Relay2' */
extern CALDATA const volatile float32 cal_COMPEvapTNmlVal;/* Referenced by: '<S454>/Relay2' */
extern CALDATA const volatile float32 cal_COMPExhTDownSpd;/* Referenced by: '<S568>/Constant1' */
extern CALDATA const volatile float32 cal_COMPExhTFrbVal;/* Referenced by: '<S454>/Relay1' */
extern CALDATA const volatile float32 cal_COMPExhTLmtRlybVal;/* Referenced by: '<S454>/Relay1' */
extern CALDATA const volatile float32 cal_COMPExhTLmtVal;/* Referenced by: '<S454>/Relay' */
extern CALDATA const volatile float32 cal_COMPExhTNmlVal;/* Referenced by: '<S454>/Relay' */
extern CALDATA const volatile uint8 cal_COMPFanLevelLmt_1X[9];
                           /* Referenced by: '<S544>/cal_COMPFanLevelLmt_CUR' */
extern CALDATA const volatile float32 cal_COMPFanLevelLmt_CUR[9];
                           /* Referenced by: '<S544>/cal_COMPFanLevelLmt_CUR' */
extern CALDATA const volatile uint8 cal_COMPFanSpdLmt[3];/* Referenced by: '<S440>/Constant14' */
extern CALDATA const volatile float32 cal_COMPONMinSpd;/* Referenced by: '<S448>/Relay' */
extern CALDATA const volatile float32 cal_COMPOffMaxSpd;/* Referenced by: '<S448>/Relay' */
extern CALDATA const volatile float32 cal_COMPSpdDiffDown;/* Referenced by: '<S569>/Constant6' */
extern CALDATA const volatile float32 cal_COMPSpdDiffDownRate;/* Referenced by: '<S569>/Constant7' */
extern CALDATA const volatile float32 cal_COMPSpdDiffUp;/* Referenced by: '<S569>/Constant' */
extern CALDATA const volatile float32 cal_COMPSpdDiffUpRate;/* Referenced by: '<S569>/Constant5' */
extern CALDATA const volatile float32 cal_COMPSpdLmt[4];/* Referenced by: '<S440>/Constant13' */
extern CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos1;/* Referenced by: '<S1650>/Constant' */
extern CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos2;/* Referenced by: '<S1651>/Constant' */
extern CALDATA const volatile float32 cal_CabinCondToEvpHPEXVPos;/* Referenced by: '<S1669>/Constant' */
extern CALDATA const volatile uint16 cal_CabinDesTempSolarCorECO_2X[14];
                   /* Referenced by: '<S182>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_2Y[14];
                   /* Referenced by: '<S182>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_MAP[196];
                   /* Referenced by: '<S182>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile uint16 cal_CabinDesTempSolarCor_2X[14];
                      /* Referenced by: '<S182>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCor_2Y[14];
                      /* Referenced by: '<S182>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCor_MAP[196];
                      /* Referenced by: '<S182>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile uint16 cal_CabinEvpToCondCompLmt;/* Referenced by: '<S1668>/Constant' */
extern CALDATA const volatile float32 cal_CabinEvpToHPEnvTemp;/* Referenced by: '<S1682>/Constant' */
extern CALDATA const volatile float32 cal_CabinHys1TempOffset;/* Referenced by:
                                                               * '<S1639>/Constant4'
                                                               * '<S1639>/Constant6'
                                                               * '<S1639>/Constant7'
                                                               * '<S1644>/Constant6'
                                                               * '<S1661>/Constant4'
                                                               * '<S1661>/Constant6'
                                                               * '<S1661>/Constant7'
                                                               * '<S1662>/Constant14'
                                                               * '<S1662>/Constant15'
                                                               * '<S1663>/Constant12'
                                                               * '<S1674>/Constant6'
                                                               * '<S1675>/Constant14'
                                                               * '<S1675>/Constant15'
                                                               * '<S1676>/Constant12'
                                                               */
extern CALDATA const volatile float32 cal_CabinHys2TempOffset;/* Referenced by:
                                                               * '<S1639>/Constant8'
                                                               * '<S1661>/Constant8'
                                                               * '<S1662>/Constant12'
                                                               * '<S1675>/Constant12'
                                                               */
extern CALDATA const volatile float32 cal_CabinMD2F2MaxEnvTemp;/* Referenced by:
                                                                * '<S1671>/Constant1'
                                                                * '<S1659>/Constant'
                                                                * '<S1660>/Constant9'
                                                                * '<S1662>/Constant11'
                                                                * '<S1675>/Constant11'
                                                                * '<S1676>/Constant11'
                                                                */
extern CALDATA const volatile CabinMode cal_CabinModeData;/* Referenced by: '<S1688>/Constant' */
extern CALDATA const volatile boolean cal_CabinModeEnb;/* Referenced by: '<S1688>/Constant1' */
extern CALDATA const volatile float32 cal_CabinModeKeepStandbyTime;/* Referenced by: '<S1645>/Constant2' */
extern CALDATA const volatile float32 cal_CabinModeTransF1Constant;/* Referenced by: '<S1637>/Constant3' */
extern CALDATA const volatile float32 cal_CabinModeTransF1Slope;/* Referenced by: '<S1637>/Constant2' */
extern CALDATA const volatile float32 cal_CabinModeTransF2Constant;/* Referenced by: '<S1637>/Constant4' */
extern CALDATA const volatile float32 cal_CabinModeTransF2Slope;/* Referenced by: '<S1637>/Constant1' */
extern CALDATA const volatile boolean cal_CabinSetPTCSwitch;/* Referenced by: '<S176>/Constant9' */
extern CALDATA const volatile uint8 cal_CabinTCorSelect;/* Referenced by: '<S173>/Constant1' */
extern CALDATA const volatile float32 cal_CabinTempData;/* Referenced by: '<S1722>/Constant' */
extern CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_1X[10];
                    /* Referenced by: '<S173>/cal_CabinTempDuctUpStepCor_CUR' */
extern CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_CUR[10];
                    /* Referenced by: '<S173>/cal_CabinTempDuctUpStepCor_CUR' */
extern CALDATA const volatile boolean cal_CabinTempEnb;/* Referenced by: '<S1722>/Constant1' */
extern CALDATA const volatile uint16 cal_CabinVolAmend_1X[2];
                            /* Referenced by: '<S1701>/cal_CabinVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_CabinVolAmend_CUR[2];
                            /* Referenced by: '<S1701>/cal_CabinVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ChiTempData;/* Referenced by: '<S1793>/Constant' */
extern CALDATA const volatile boolean cal_ChiTempDataEnb;/* Referenced by: '<S1793>/Constant1' */
extern CALDATA const volatile uint16 cal_ChillTempVolAmend_1X[2];
                        /* Referenced by: '<S1712>/cal_ChillTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ChillTempVolAmend_CUR[2];
                        /* Referenced by: '<S1712>/cal_ChillTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ClsCoolInletTemp;/* Referenced by: '<S1281>/Constant' */
extern CALDATA const volatile float32 cal_ClsCoolInletTempTime;/* Referenced by: '<S1281>/Constant2' */
extern CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_1X[15];
                      /* Referenced by: '<S1703>/cal_ColdPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_CUR[15];
                      /* Referenced by: '<S1703>/cal_ColdPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_1X[7];
                 /* Referenced by: '<S1261>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_CUR[7];
                 /* Referenced by: '<S1261>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_CondDepFilter;/* Referenced by: '<S893>/Constant2' */
extern CALDATA const volatile float32 cal_CondDep_1X[28];
                                   /* Referenced by: '<S674>/cal_CondDep_CUR' */
extern CALDATA const volatile float32 cal_CondDep_CUR[28];
                                   /* Referenced by: '<S674>/cal_CondDep_CUR' */
extern CALDATA const volatile float32 cal_CoolFanCtrl_2X[4];
                               /* Referenced by: '<S913>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_CoolFanCtrl_2Y[13];
                               /* Referenced by: '<S913>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_CoolFanCtrl_MAP[52];
                               /* Referenced by: '<S913>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_CoolFanData;/* Referenced by: '<S919>/Constant' */
extern CALDATA const volatile boolean cal_CoolFanEnb;/* Referenced by: '<S919>/Constant1' */
extern CALDATA const volatile float32 cal_CoolStartCompensate;/* Referenced by: '<S276>/Constant8' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2X[6];
                     /* Referenced by: '<S585>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2Y[6];
                     /* Referenced by: '<S585>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_MAP[36];
                     /* Referenced by: '<S585>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCOffPowerVal;/* Referenced by: '<S585>/Constant6' */
extern CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_1X[6];
                        /* Referenced by: '<S585>/cal_CtrlFPTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_CUR[6];
                        /* Referenced by: '<S585>/cal_CtrlFPTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_DCBatHeatEnvTemp[2];/* Referenced by: '<S1491>/Constant1' */
extern CALDATA const volatile float32 cal_DCBatHeatT1[3];/* Referenced by: '<S1491>/Constant2' */
extern CALDATA const volatile float32 cal_DCBatHeatT2[3];/* Referenced by: '<S1491>/Constant3' */
extern CALDATA const volatile float32 cal_DCBatHeatTave[3];/* Referenced by: '<S1491>/Constant' */
extern CALDATA const volatile float32 cal_DCBatHeatTrgTemp;/* Referenced by:
                                                            * '<S646>/Constant4'
                                                            * '<S1491>/Constant4'
                                                            */
extern CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_1X[7];
                     /* Referenced by: '<S1493>/cal_DCChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_CUR[7];
                     /* Referenced by: '<S1493>/cal_DCChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DLTRBatInlet2MaxTempDiff;/* Referenced by: '<S1533>/Constant' */
extern CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_1X[5];
                       /* Referenced by: '<S1506>/cal_DLTRBatMaxEntTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_CUR[5];
                       /* Referenced by: '<S1506>/cal_DLTRBatMaxEntTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_1X[5];/* Referenced by:
                                                                      * '<S1505>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      * '<S1507>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_CUR[5];/* Referenced by:
                                                                      * '<S1505>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      * '<S1507>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_1X[5];
                    /* Referenced by: '<S1525>/cal_DLTRDCBatMaxExitTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_CUR[5];
                    /* Referenced by: '<S1525>/cal_DLTRDCBatMaxExitTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRIPUTempExitVal;/* Referenced by: '<S1526>/Constant' */
extern CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_1X[5];
                 /* Referenced by: '<S1525>/cal_DLTRNotDCBatMaxExitTempC_CUR' */
extern CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_CUR[5];
                 /* Referenced by: '<S1525>/cal_DLTRNotDCBatMaxExitTempC_CUR' */
extern CALDATA const volatile float32 cal_DcutTPidDeadBand;/* Referenced by:
                                                            * '<S225>/Kp11'
                                                            * '<S227>/Kp11'
                                                            */
extern CALDATA const volatile float32 cal_DcutTempPidLL;/* Referenced by:
                                                         * '<S225>/Kp6'
                                                         * '<S227>/Kp6'
                                                         */
extern CALDATA const volatile float32 cal_DcutTempPidUL;/* Referenced by:
                                                         * '<S225>/Kp5'
                                                         * '<S227>/Kp5'
                                                         */
extern CALDATA const volatile float32 cal_DcutTempPid_IsumMax;/* Referenced by:
                                                               * '<S225>/Kp8'
                                                               * '<S227>/Kp8'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_IsumMin;/* Referenced by:
                                                               * '<S225>/Kp13'
                                                               * '<S227>/Kp13'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_Ki;/* Referenced by:
                                                          * '<S225>/Kp7'
                                                          * '<S227>/Kp7'
                                                          */
extern CALDATA const volatile float32 cal_DcutTempPid_KiNeg;/* Referenced by:
                                                             * '<S225>/Kp9'
                                                             * '<S227>/Kp9'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_KiPos;/* Referenced by:
                                                             * '<S225>/Kp10'
                                                             * '<S227>/Kp10'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_Kp;/* Referenced by:
                                                          * '<S225>/Kp'
                                                          * '<S227>/Kp'
                                                          */
extern CALDATA const volatile float32 cal_DcutTempPid_KpNeg;/* Referenced by:
                                                             * '<S225>/Kp1'
                                                             * '<S227>/Kp1'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_KpPos;/* Referenced by:
                                                             * '<S225>/Kp2'
                                                             * '<S227>/Kp2'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_pWinNeg;/* Referenced by:
                                                               * '<S225>/Kp4'
                                                               * '<S227>/Kp4'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_pWinPos;/* Referenced by:
                                                               * '<S225>/Kp3'
                                                               * '<S227>/Kp3'
                                                               */
extern CALDATA const volatile float32 cal_DefaultSetTemp;/* Referenced by: '<S204>/Constant' */
extern CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_1X[7];
                    /* Referenced by: '<S1493>/cal_DisChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_CUR[7];
                    /* Referenced by: '<S1493>/cal_DisChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DrDuctFaceFloorFaFactor;/* Referenced by: '<S223>/Constant3' */
extern CALDATA const volatile float32 cal_DrDuctFaceFloorFoFactor;/* Referenced by: '<S223>/Constant4' */
extern CALDATA const volatile float32 cal_DrDuctSenFailDeflt;
                       /* Referenced by: '<S172>/cal_DrDuctSensorFailDefault' */
extern CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOff;
/* Referenced by: '<S386>/On:cal_DrErrOfEvaDVT2CoolMixOn Off:cal_DrErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOn;
/* Referenced by: '<S386>/On:cal_DrErrOfEvaDVT2CoolMixOn Off:cal_DrErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOff;
/* Referenced by: '<S386>/On:cal_DrErrOfPtcDVT2HeatMixOn Off:cal_DrErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOn;
/* Referenced by: '<S386>/On:cal_DrErrOfPtcDVT2HeatMixOn Off:cal_DrErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandNeg;/* Referenced by: '<S278>/Kp12' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandPos;/* Referenced by: '<S278>/Kp11' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKi;/* Referenced by: '<S278>/Kp7' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKiNeg;/* Referenced by: '<S278>/Kp9' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKiPos;/* Referenced by: '<S278>/Kp10' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKp;/* Referenced by: '<S278>/Kp' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKpNeg;/* Referenced by: '<S278>/Kp1' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKpPos;/* Referenced by: '<S278>/Kp2' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL;/* Referenced by:
                                                            * '<S278>/Kp6'
                                                            * '<S279>/Constant1'
                                                            * '<S304>/Constant4'
                                                            */
extern CALDATA const volatile uint8 cal_DrEvaDesValPIDLL_2X[4];
                          /* Referenced by: '<S272>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL_2Y[7];
                          /* Referenced by: '<S272>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL_MAP[28];
                          /* Referenced by: '<S272>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDUL;/* Referenced by:
                                                            * '<S278>/Kp5'
                                                            * '<S279>/Constant'
                                                            * '<S304>/Constant3'
                                                            */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMax;/* Referenced by: '<S278>/Kp8' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMin;/* Referenced by: '<S278>/Kp13' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_pWinNeg;/* Referenced by: '<S278>/Kp4' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_pWinPos;/* Referenced by: '<S278>/Kp3' */
extern CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_1X[4];
                      /* Referenced by: '<S278>/cal_DrEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_CUR[4];
                      /* Referenced by: '<S278>/cal_DrEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetDefog_1X[8];
                          /* Referenced by: '<S386>/cal_DrMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetDefog_CUR[8];
                          /* Referenced by: '<S386>/cal_DrMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_1X[8];
                     /* Referenced by: '<S386>/cal_DrMixBacSetFaceHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_CUR[8];
                     /* Referenced by: '<S386>/cal_DrMixBacSetFaceHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFace_1X[8];
                           /* Referenced by: '<S386>/cal_DrMixBacSetFace_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFace_CUR[8];
                           /* Referenced by: '<S386>/cal_DrMixBacSetFace_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_1X[8];
                  /* Referenced by: '<S386>/cal_DrMixBacSetHeaterDeforst_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_CUR[8];
                  /* Referenced by: '<S386>/cal_DrMixBacSetHeaterDeforst_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeater_1X[8];
                         /* Referenced by: '<S386>/cal_DrMixBacSetHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeater_CUR[8];
                         /* Referenced by: '<S386>/cal_DrMixBacSetHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixDesValPIDIntegDeadBand;/* Referenced by: '<S387>/Kp11' */
extern CALDATA const volatile uint8 cal_DrMixDesValPIDLL;/* Referenced by: '<S387>/Kp6' */
extern CALDATA const volatile uint8 cal_DrMixDesValPIDUL;/* Referenced by: '<S387>/Kp5' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_IsumMax;/* Referenced by: '<S387>/Kp8' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_IsumMin;/* Referenced by: '<S387>/Kp13' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_Ki;/* Referenced by: '<S387>/Kp7' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KiNeg;/* Referenced by: '<S387>/Kp9' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KiPos;/* Referenced by: '<S387>/Kp10' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_Kp;/* Referenced by: '<S387>/Kp' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KpNeg;/* Referenced by: '<S387>/Kp1' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KpPos;/* Referenced by: '<S387>/Kp2' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_pWinNeg;/* Referenced by: '<S387>/Kp4' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_pWinPos;/* Referenced by: '<S387>/Kp3' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4InHeat;/* Referenced by: '<S339>/Kp16' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4OutHeat;/* Referenced by: '<S339>/Kp26' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKi;/* Referenced by: '<S339>/Kp7' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKiNeg;/* Referenced by: '<S339>/Kp9' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKiPos;/* Referenced by: '<S339>/Kp10' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKp;/* Referenced by: '<S339>/Kp' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKpNeg;/* Referenced by: '<S339>/Kp1' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKpPos;/* Referenced by: '<S339>/Kp2' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDLL;/* Referenced by: '<S339>/Kp6' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDUL;/* Referenced by: '<S339>/Kp5' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMax;/* Referenced by: '<S339>/Kp8' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMin;/* Referenced by: '<S339>/Kp13' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_pWinNeg;/* Referenced by: '<S339>/Kp4' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_pWinPos;/* Referenced by: '<S339>/Kp3' */
extern CALDATA const volatile float32 cal_DvtCoff;/* Referenced by: '<S180>/Constant' */
extern CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_1X[8];
                    /* Referenced by: '<S184>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_CUR[8];
                    /* Referenced by: '<S184>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_1X[8];
                    /* Referenced by: '<S184>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_CUR[8];
                    /* Referenced by: '<S184>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2X[10];
                     /* Referenced by: '<S184>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2Y[10];
                     /* Referenced by: '<S184>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_MAP[100];
                     /* Referenced by: '<S184>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesValPIDIntegDeadBand;/* Referenced by: '<S184>/Constant7' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKi_1X[9];
                            /* Referenced by: '<S184>/cal_DvtDesValPIDKi_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKi_CUR[9];
                            /* Referenced by: '<S184>/cal_DvtDesValPIDKi_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKp_1X[9];
                            /* Referenced by: '<S184>/cal_DvtDesValPIDKp_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKp_CUR[9];
                            /* Referenced by: '<S184>/cal_DvtDesValPIDKp_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPID_Ki;/* Referenced by: '<S184>/Kp7' */
extern CALDATA const volatile float32 cal_DvtDesValPID_Kp;/* Referenced by: '<S184>/Kp' */
extern CALDATA const volatile float32 cal_DvtDesValPID_LL;/* Referenced by:
                                                           * '<S178>/Kp2'
                                                           * '<S178>/Kp6'
                                                           * '<S179>/Kp2'
                                                           * '<S179>/Kp6'
                                                           * '<S184>/Kp6'
                                                           */
extern CALDATA const volatile float32 cal_DvtDesValPID_UL;/* Referenced by:
                                                           * '<S178>/Kp1'
                                                           * '<S178>/Kp5'
                                                           * '<S179>/Kp1'
                                                           * '<S179>/Kp5'
                                                           */
extern CALDATA const volatile float32 cal_DvtDesValPID_pWinNeg;/* Referenced by: '<S184>/Kp4' */
extern CALDATA const volatile float32 cal_DvtDesValPID_pWinPos;/* Referenced by: '<S184>/Kp3' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_2X[6];
                            /* Referenced by: '<S175>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_2Y[7];
                            /* Referenced by: '<S175>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_MAP[42];
                            /* Referenced by: '<S175>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_EEEnvAndEnvDiffVal;/* Referenced by: '<S1703>/Switch12' */
extern CALDATA const volatile float32 cal_EVAPSufTempClsSOV;/* Referenced by: '<S443>/Relay' */
extern CALDATA const volatile float32 cal_EVAPSufTempOpenSOV;/* Referenced by: '<S443>/Relay' */
extern CALDATA const volatile uint16 cal_EVAPSurfTempVolAmend_1X[2];
                     /* Referenced by: '<S1715>/cal_EVAPSurfTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EVAPSurfTempVolAmend_CUR[2];
                     /* Referenced by: '<S1715>/cal_EVAPSurfTempVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_EVAPTempVolAmend_1X[2];
                         /* Referenced by: '<S1714>/cal_EVAPTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EVAPTempVolAmend_CUR[2];
                         /* Referenced by: '<S1714>/cal_EVAPTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_EntExtDefTime;/* Referenced by: '<S1690>/Constant3' */
extern CALDATA const volatile boolean cal_EnvFailSwFlg;/* Referenced by: '<S1713>/Constant' */
extern CALDATA const volatile float32 cal_EnvTAme_1X[11];
                                  /* Referenced by: '<S1704>/cal_EnvTAme_CUR' */
extern CALDATA const volatile float32 cal_EnvTAme_CUR[11];
                                  /* Referenced by: '<S1704>/cal_EnvTAme_CUR' */
extern CALDATA const volatile float32 cal_EnvTempCorData;/* Referenced by: '<S1740>/Constant' */
extern CALDATA const volatile boolean cal_EnvTempCorEnb;/* Referenced by: '<S1740>/Constant1' */
extern CALDATA const volatile float32 cal_EnvTempRiseStep;/* Referenced by: '<S1703>/Constant3' */
extern CALDATA const volatile float32 cal_EnvTempStep;/* Referenced by: '<S177>/Constant3' */
extern CALDATA const volatile uint16 cal_EnvVolAmend_1X[2];
                              /* Referenced by: '<S1713>/cal_EnvVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EnvVolAmend_CUR[2];
                              /* Referenced by: '<S1713>/cal_EnvVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForEvaLL;/* Referenced by: '<S175>/Constant4' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForEvaUL;/* Referenced by: '<S175>/Constant3' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForPtcLL;/* Referenced by: '<S176>/Constant2' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForPtcUL;/* Referenced by: '<S176>/Constant1' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInComf_OFF;
/* Referenced by: '<S85>/On:cal_ErrOfEvaActTargInComf_ON Off:cal_ErrOfEvaActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInComf_ON;
/* Referenced by: '<S85>/On:cal_ErrOfEvaActTargInComf_ON Off:cal_ErrOfEvaActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInDefog_OFF;
/* Referenced by: '<S86>/On:cal_ErrOfEvaActTargInDefog_ON Off:cal_ErrOfEvaActTargInDefog_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInDefog_ON;
/* Referenced by: '<S86>/On:cal_ErrOfEvaActTargInDefog_ON Off:cal_ErrOfEvaActTargInDefog_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInEcon_OFF;
/* Referenced by: '<S85>/On:cal_ErrOfEvaActTargInEcon_ON Off:cal_ErrOfEvaActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInEcon_ON;
/* Referenced by: '<S85>/On:cal_ErrOfEvaActTargInEcon_ON Off:cal_ErrOfEvaActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInComf_OFF;
/* Referenced by: '<S92>/On:cal_ErrOfPTCActTargInComf_ON Off:cal_ErrOfPTCActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInComf_ON;
/* Referenced by: '<S92>/On:cal_ErrOfPTCActTargInComf_ON Off:cal_ErrOfPTCActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInEcon_OFF;
/* Referenced by: '<S92>/On:cal_ErrOfPTCActTargInEcon_ON Off:cal_ErrOfPTCActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInEcon_ON;
/* Referenced by: '<S92>/On:cal_ErrOfPTCActTargInEcon_ON Off:cal_ErrOfPTCActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_EvaDesLLMax;/* Referenced by:
                                                       * '<S175>/Constant1'
                                                       * '<S272>/Constant1'
                                                       * '<S273>/Constant1'
                                                       * '<S276>/Constant4'
                                                       */
extern CALDATA const volatile float32 cal_EvaDesLLMin;/* Referenced by:
                                                       * '<S272>/Constant8'
                                                       * '<S273>/Constant8'
                                                       * '<S276>/Constant2'
                                                       * '<S276>/Constant6'
                                                       */
extern CALDATA const volatile boolean cal_EvaDesLLSelect;/* Referenced by: '<S276>/Constant' */
extern CALDATA const volatile boolean cal_EvaEnable;/* Referenced by:
                                                     * '<S383>/Constant1'
                                                     * '<S384>/Constant1'
                                                     */
extern CALDATA const volatile float32 cal_EvapBacTempDesACBi_1X[6];
                        /* Referenced by: '<S279>/cal_EvapBacTempDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesACBi_CUR[6];
                        /* Referenced by: '<S279>/cal_EvapBacTempDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesAC_1X[6];
                          /* Referenced by: '<S279>/cal_EvapBacTempDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesAC_CUR[6];
                          /* Referenced by: '<S279>/cal_EvapBacTempDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesDefog_1X[6];
                       /* Referenced by: '<S279>/cal_EvapBacTempDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesDefog_CUR[6];
                       /* Referenced by: '<S279>/cal_EvapBacTempDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFootDe_1X[6];
                      /* Referenced by: '<S279>/cal_EvapBacTempDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFootDe_CUR[6];
                      /* Referenced by: '<S279>/cal_EvapBacTempDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFoot_1X[6];
                        /* Referenced by: '<S279>/cal_EvapBacTempDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFoot_CUR[6];
                        /* Referenced by: '<S279>/cal_EvapBacTempDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_1X[6];
                      /* Referenced by: '<S304>/cal_EvapBacTempPsDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_CUR[6];
                      /* Referenced by: '<S304>/cal_EvapBacTempPsDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesAC_1X[6];
                        /* Referenced by: '<S304>/cal_EvapBacTempPsDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesAC_CUR[6];
                        /* Referenced by: '<S304>/cal_EvapBacTempPsDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_1X[6];
                     /* Referenced by: '<S304>/cal_EvapBacTempPsDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_CUR[6];
                     /* Referenced by: '<S304>/cal_EvapBacTempPsDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_1X[6];
                    /* Referenced by: '<S304>/cal_EvapBacTempPsDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_CUR[6];
                    /* Referenced by: '<S304>/cal_EvapBacTempPsDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_1X[6];
                      /* Referenced by: '<S304>/cal_EvapBacTempPsDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_CUR[6];
                      /* Referenced by: '<S304>/cal_EvapBacTempPsDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimByEnv_1X[8];
                         /* Referenced by: '<S276>/cal_EvapDesLoLimByEnv_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimByEnv_CUR[8];
                         /* Referenced by: '<S276>/cal_EvapDesLoLimByEnv_CUR' */
extern CALDATA const volatile uint16 cal_EvapDesLoLimBySolarCor_1X[2];
                    /* Referenced by: '<S276>/cal_EvapDesLoLimBySolarCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimBySolarCor_CUR[2];
                    /* Referenced by: '<S276>/cal_EvapDesLoLimBySolarCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempCabinCor_1X[6];
                       /* Referenced by: '<S279>/cal_EvapDesTempCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempCabinCor_CUR[6];
                       /* Referenced by: '<S279>/cal_EvapDesTempCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_2X[6];
                         /* Referenced by: '<S279>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_2Y[6];
                         /* Referenced by: '<S279>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_MAP[36];
                         /* Referenced by: '<S279>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_EvapDesTempFanCor_1X[4];
                         /* Referenced by: '<S279>/cal_EvapDesTempFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempFanCor_CUR[4];
                         /* Referenced by: '<S279>/cal_EvapDesTempFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_1X[6];
                     /* Referenced by: '<S304>/cal_EvapDesTempPsCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_CUR[6];
                     /* Referenced by: '<S304>/cal_EvapDesTempPsCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2X[6];
                       /* Referenced by: '<S304>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2Y[6];
                       /* Referenced by: '<S304>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_MAP[36];
                       /* Referenced by: '<S304>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_EvapDesTempPsFanCor_1X[4];
                       /* Referenced by: '<S304>/cal_EvapDesTempPsFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsFanCor_CUR[4];
                       /* Referenced by: '<S304>/cal_EvapDesTempPsFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapSurTempData;/* Referenced by: '<S1825>/Constant' */
extern CALDATA const volatile boolean cal_EvapSurTempDataEnb;/* Referenced by: '<S1825>/Constant1' */
extern CALDATA const volatile float32 cal_EvapTempData;/* Referenced by: '<S1815>/Constant' */
extern CALDATA const volatile boolean cal_EvapTempDataEnb;/* Referenced by: '<S1815>/Constant1' */
extern CALDATA const volatile float32 cal_ExhSuperHeatFilter;/* Referenced by: '<S897>/Constant1' */
extern CALDATA const volatile uint16 cal_ExhaustTime;/* Referenced by: '<S10>/Constant7' */
extern CALDATA const volatile float32 cal_ExitExtDefTime;/* Referenced by: '<S1691>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefBatMinT;/* Referenced by: '<S937>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefEnvMaxTemp;/* Referenced by: '<S1690>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefEnvMinTemp;/* Referenced by: '<S1690>/Constant1' */
extern CALDATA const volatile boolean cal_ExtDefFlgData;/* Referenced by: '<S1693>/Constant' */
extern CALDATA const volatile boolean cal_ExtDefFlgDataEnb;/* Referenced by: '<S1693>/Constant1' */
extern CALDATA const volatile float32 cal_ExtDefOHXOffTemp;/* Referenced by: '<S1695>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefOHXOnTemp;/* Referenced by: '<S1694>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefPTCTrgTemp;/* Referenced by: '<S441>/Constant6' */
extern CALDATA const volatile float32 cal_ExtDefTempDiff;/* Referenced by: '<S1690>/Constant2' */
extern CALDATA const volatile uint8 cal_FANSpdHotStartLL;/* Referenced by: '<S48>/Constant12' */
extern CALDATA const volatile uint8 cal_FANSpdHotStartUL;/* Referenced by: '<S47>/Constant27' */
extern CALDATA const volatile uint8 cal_FANSpdModeShiftMax;/* Referenced by: '<S47>/Constant3' */
extern CALDATA const volatile float32 cal_FaceDuctTempData;/* Referenced by: '<S1745>/Constant' */
extern CALDATA const volatile boolean cal_FaceDuctTempEnb;/* Referenced by: '<S1745>/Constant1' */
extern CALDATA const volatile uint16 cal_FaceDuctVolAmend_1X[2];
                         /* Referenced by: '<S1705>/cal_FaceDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_FaceDuctVolAmend_CUR[2];
                         /* Referenced by: '<S1705>/cal_FaceDuctVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_FallTime2Tamb;
                                    /* Referenced by: '<S1703>/TempRampStep3' */
extern CALDATA const volatile uint16 cal_FalseTime2EnvTamb;
                                     /* Referenced by: '<S177>/TempRampStep3' */
extern CALDATA const volatile uint16 cal_FalseTime2Solar;
                                     /* Referenced by: '<S182>/TempRampStep2' */
extern CALDATA const volatile uint8 cal_FanCtrlOff;/* Referenced by: '<S918>/Constant2' */
extern CALDATA const volatile uint8 cal_FanLevelToPWM[10];/* Referenced by:
                                                           * '<S52>/Constant2'
                                                           * '<S53>/Constant18'
                                                           * '<S54>/Constant2'
                                                           * '<S56>/Constant1'
                                                           * '<S56>/Constant11'
                                                           * '<S56>/Constant14'
                                                           * '<S56>/Constant16'
                                                           * '<S56>/Constant18'
                                                           * '<S56>/Constant2'
                                                           * '<S56>/Constant4'
                                                           * '<S56>/Constant7'
                                                           * '<S56>/Constant9'
                                                           */
extern CALDATA const volatile boolean cal_FixPIDSecletFlag;/* Referenced by:
                                                            * '<S383>/Constant'
                                                            * '<S384>/Constant'
                                                            * '<S272>/Constant'
                                                            * '<S273>/Constant'
                                                            * '<S332>/Constant'
                                                            * '<S333>/Constant'
                                                            * '<S181>/Constant'
                                                            */
extern CALDATA const volatile float32 cal_FootDuctTempData;/* Referenced by: '<S1755>/Constant' */
extern CALDATA const volatile boolean cal_FootDuctTempEnb;/* Referenced by: '<S1755>/Constant1' */
extern CALDATA const volatile uint16 cal_FootDuctVolAmend_1X[2];
                         /* Referenced by: '<S1706>/cal_FootDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_FootDuctVolAmend_CUR[2];
                         /* Referenced by: '<S1706>/cal_FootDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_HAPevap_min;
                             /* Referenced by: '<S36>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPparkdly_time;
                             /* Referenced by: '<S36>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPpurge_time;
                             /* Referenced by: '<S36>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPtimelim2activtic;
                             /* Referenced by: '<S36>/AirConditionStartState' */
extern CALDATA const volatile float32 cal_HPAndLPDiffMaxVal;/* Referenced by: '<S519>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtlKi;/* Referenced by: '<S819>/Constant11' */
extern CALDATA const volatile float32 cal_HPEXVCtlKiDeadzoneNeg;/* Referenced by: '<S819>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVCtlKiDeadzonePos;/* Referenced by: '<S819>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtlKisumMax;/* Referenced by: '<S819>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtlKisumMin;/* Referenced by: '<S819>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtlKp;/* Referenced by: '<S819>/Constant10' */
extern CALDATA const volatile float32 cal_HPEXVCtlKpDeadzoneNeg;/* Referenced by: '<S819>/Constant5' */
extern CALDATA const volatile float32 cal_HPEXVCtlKpDeadzonePos;/* Referenced by: '<S819>/Constant4' */
extern CALDATA const volatile float32 cal_HPEXVCtrlADeadzone;/* Referenced by: '<S856>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlADelayTime;/* Referenced by: '<S856>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFFLolmt;/* Referenced by: '<S856>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFFUplmt;/* Referenced by: '<S856>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFF_1X[5];
                              /* Referenced by: '<S856>/cal_HPEXVCtrlAFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFF_CUR[5];
                              /* Referenced by: '<S856>/cal_HPEXVCtrlAFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKi_1X[6];
                              /* Referenced by: '<S856>/cal_HPEXVCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKi_CUR[6];
                              /* Referenced by: '<S856>/cal_HPEXVCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKp_1X[6];
                              /* Referenced by: '<S856>/cal_HPEXVCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKp_CUR[6];
                              /* Referenced by: '<S856>/cal_HPEXVCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAMax;/* Referenced by: '<S856>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAMin;/* Referenced by: '<S856>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAOpenVal;/* Referenced by: '<S856>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_1X[5];
                     /* Referenced by: '<S856>/cal_HPEXVCtrlATrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_CUR[5];
                     /* Referenced by: '<S856>/cal_HPEXVCtrlATrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCDeadzone;/* Referenced by: '<S858>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCDelayTime;/* Referenced by: '<S858>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCFF_1X[5];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCFF_CUR[5];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKi_1X[8];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKi_CUR[8];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKp_1X[8];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKp_CUR[8];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCMax;/* Referenced by: '<S858>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCMin;/* Referenced by: '<S858>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCOpenVal;/* Referenced by: '<S858>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDDeadzone;/* Referenced by: '<S859>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDDelayTime;/* Referenced by: '<S859>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFFLolmt;/* Referenced by: '<S859>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFFUplmt;/* Referenced by: '<S859>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFF_1X[5];
                              /* Referenced by: '<S859>/cal_HPEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFF_CUR[5];
                              /* Referenced by: '<S859>/cal_HPEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKi_1X[8];
                              /* Referenced by: '<S859>/cal_HPEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKi_CUR[8];
                              /* Referenced by: '<S859>/cal_HPEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKp_1X[8];
                              /* Referenced by: '<S859>/cal_HPEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKp_CUR[8];
                              /* Referenced by: '<S859>/cal_HPEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDMax;/* Referenced by: '<S859>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDMin;/* Referenced by: '<S859>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDOpenVal;/* Referenced by: '<S859>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_1X[5];
                     /* Referenced by: '<S859>/cal_HPEXVCtrlDTrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_CUR[5];
                     /* Referenced by: '<S859>/cal_HPEXVCtrlDTrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEDeadzone;/* Referenced by: '<S860>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEDelayTime;/* Referenced by: '<S860>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFFLolmt;/* Referenced by: '<S860>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFFUplmt;/* Referenced by: '<S860>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFF_1X[5];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlEFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFF_CUR[5];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlEFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKi_1X[6];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKi_CUR[6];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKp_1X[6];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKp_CUR[6];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEMax;/* Referenced by: '<S860>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEMin;/* Referenced by: '<S860>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEOpenVal;/* Referenced by: '<S860>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_1X[5];
                     /* Referenced by: '<S860>/cal_HPEXVCtrlETrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_CUR[5];
                     /* Referenced by: '<S860>/cal_HPEXVCtrlETrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVDiffDown;/* Referenced by: '<S823>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVDiffDownRate;/* Referenced by: '<S823>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVDiffUp;/* Referenced by: '<S823>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVDiffUpRate;/* Referenced by: '<S823>/Constant5' */
extern CALDATA const volatile float32 cal_HPEXVDownSpdLmt;/* Referenced by:
                                                           * '<S828>/DownLmt'
                                                           * '<S828>/DownLmt1'
                                                           */
extern CALDATA const volatile boolean cal_HPEXVEnbData;/* Referenced by: '<S834>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVEnbDataEnb;/* Referenced by: '<S834>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVFloorDiff1;/* Referenced by: '<S826>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVFloorDiff2;/* Referenced by: '<S826>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVHiPressLmtOff;/* Referenced by: '<S862>/HiPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVHiPressLmtOn;/* Referenced by: '<S862>/HiPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVHiPressProOpenSpd;/* Referenced by:
                                                                  * '<S823>/Constant1'
                                                                  * '<S823>/Constant3'
                                                                  */
extern CALDATA const volatile float32 cal_HPEXVHiPressProhOff;/* Referenced by: '<S823>/HiProRelay' */
extern CALDATA const volatile float32 cal_HPEXVHiPressProhOn;/* Referenced by: '<S823>/HiProRelay' */
extern CALDATA const volatile uint8 cal_HPEXVInitReqData;/* Referenced by: '<S891>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVInitReqDataeEnb;/* Referenced by: '<S891>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVLowPressLmtOff;/* Referenced by: '<S862>/LowPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVLowPressLmtOn;/* Referenced by: '<S862>/LowPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVLowPressProOpenSpd;/* Referenced by:
                                                                   * '<S823>/Constant'
                                                                   * '<S823>/Constant2'
                                                                   */
extern CALDATA const volatile float32 cal_HPEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                   * '<S829>/DownLmt'
                                                                   * '<S829>/DownLmt1'
                                                                   */
extern CALDATA const volatile float32 cal_HPEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                 * '<S829>/UpLmt'
                                                                 * '<S829>/UpLmt2'
                                                                 */
extern CALDATA const volatile float32 cal_HPEXVPosData;/* Referenced by: '<S824>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVPosDataEnb;/* Referenced by: '<S824>/Constant1' */
extern CALDATA const volatile boolean cal_HPEXVStepLmtSw;/* Referenced by: '<S816>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVSubCoolflt;/* Referenced by:
                                                           * '<S856>/Constant11'
                                                           * '<S859>/Constant11'
                                                           * '<S860>/Constant11'
                                                           */
extern CALDATA const volatile float32 cal_HPEXVUpSpdLmt;/* Referenced by:
                                                         * '<S828>/UpLmt'
                                                         * '<S828>/UpLmt2'
                                                         */
extern CALDATA const volatile float32 cal_HPEXVlowPressLmtTrg;/* Referenced by: '<S820>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVlowPressProhOff;/* Referenced by: '<S823>/LowProRelay' */
extern CALDATA const volatile float32 cal_HPEXVlowPressProhOn;/* Referenced by: '<S823>/LowProRelay' */
extern CALDATA const volatile float32 cal_HPHighLmtVal;/* Referenced by: '<S1719>/Constant' */
extern CALDATA const volatile float32 cal_HPProVal1;/* Referenced by: '<S529>/Relay' */
extern CALDATA const volatile float32 cal_HPProVal1Relay;/* Referenced by: '<S529>/Relay' */
extern CALDATA const volatile float32 cal_HPProVal2;/* Referenced by:
                                                     * '<S527>/Relay1'
                                                     * '<S529>/Relay1'
                                                     */
extern CALDATA const volatile float32 cal_HPProVal2Relay;/* Referenced by:
                                                          * '<S527>/Relay1'
                                                          * '<S529>/Relay1'
                                                          */
extern CALDATA const volatile float32 cal_HPProVal3;/* Referenced by:
                                                     * '<S524>/Relay2'
                                                     * '<S526>/Relay2'
                                                     * '<S527>/Relay2'
                                                     * '<S529>/Relay2'
                                                     */
extern CALDATA const volatile float32 cal_HPProVal3Relay;/* Referenced by:
                                                          * '<S524>/Relay2'
                                                          * '<S527>/Relay2'
                                                          * '<S529>/Relay2'
                                                          */
extern CALDATA const volatile float32 cal_HPProVal4;/* Referenced by: '<S526>/Relay2' */
extern CALDATA const volatile uint8 cal_HVPartModeData;/* Referenced by: '<S1696>/Constant' */
extern CALDATA const volatile boolean cal_HVPartModeEnb;/* Referenced by: '<S1696>/Constant1' */
extern CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOff;/* Referenced by: '<S498>/Relay1' */
extern CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOn;/* Referenced by: '<S498>/Relay1' */
extern CALDATA const volatile uint8 cal_HeatCabinAndCoolBatFanSpd;/* Referenced by: '<S440>/Constant1' */
extern CALDATA const volatile float32 cal_HeatFanCtrl_2X[4];
                               /* Referenced by: '<S916>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_HeatFanCtrl_2Y[13];
                               /* Referenced by: '<S916>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_HeatFanCtrl_MAP[52];
                               /* Referenced by: '<S916>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsDownSpd;/* Referenced by: '<S452>/Constant1' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP1;/* Referenced by: '<S452>/Relay13' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP2;/* Referenced by: '<S452>/Relay13' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP3;/* Referenced by: '<S452>/Relay12' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP4;/* Referenced by: '<S452>/Relay12' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP5;/* Referenced by: '<S452>/Relay14' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP6;/* Referenced by: '<S452>/Relay14' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP7;/* Referenced by: '<S452>/Relay15' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP8;/* Referenced by: '<S452>/Relay15' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsDownSpd;/* Referenced by: '<S452>/Constant3' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP1;/* Referenced by: '<S452>/Relay5' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP2;/* Referenced by: '<S452>/Relay5' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP3;/* Referenced by: '<S452>/Relay4' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP4;/* Referenced by: '<S452>/Relay4' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP5;/* Referenced by: '<S452>/Relay6' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP6;/* Referenced by: '<S452>/Relay6' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP7;/* Referenced by: '<S452>/Relay7' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP8;/* Referenced by: '<S452>/Relay7' */
extern CALDATA const volatile float32 cal_HeatPwrOn;/* Referenced by:
                                                     * '<S1360>/Constant'
                                                     * '<S1371>/Constant'
                                                     * '<S1445>/Constant'
                                                     * '<S1458>/Constant'
                                                     */
extern CALDATA const volatile float32 cal_HiPressData;/* Referenced by: '<S1859>/Constant' */
extern CALDATA const volatile boolean cal_HiPressDataEnb;/* Referenced by: '<S1859>/Constant1' */
extern CALDATA const volatile float32 cal_IGBTDownLmtTemp;/* Referenced by: '<S1277>/Relay1' */
extern CALDATA const volatile float32 cal_IGBTUpLmtTemp;/* Referenced by: '<S1277>/Relay1' */
extern CALDATA const volatile uint8 cal_IGNONDelayTime;/* Referenced by: '<S28>/Constant3' */
extern CALDATA const volatile uint8 cal_InnerRecTrgPos;/* Referenced by: '<S1194>/Constant1' */
extern CALDATA const volatile float32 cal_LAirmixNomOutWaterT;/* Referenced by:
                                                               * '<S388>/Constant6'
                                                               * '<S414>/Constant6'
                                                               */
extern CALDATA const volatile float32 cal_LCCOutHiPressRaw_1X[2];
                         /* Referenced by: '<S1719>/cal_LCCOutHiPressRaw_CUR' */
extern CALDATA const volatile float32 cal_LCCOutHiPressRaw_CUR[2];
                         /* Referenced by: '<S1719>/cal_LCCOutHiPressRaw_CUR' */
extern CALDATA const volatile uint8 cal_LPFanCtrl;/* Referenced by: '<S917>/Constant11' */
extern CALDATA const volatile float32 cal_LPFanOff;/* Referenced by: '<S930>/Constant' */
extern CALDATA const volatile float32 cal_LPFanOn;/* Referenced by: '<S929>/Constant' */
extern CALDATA const volatile float32 cal_LPProOffTimer;/* Referenced by: '<S917>/Constant1' */
extern CALDATA const volatile float32 cal_LPProOnTimer;/* Referenced by: '<S917>/Constant' */
extern CALDATA const volatile float32 cal_LTRExitBatMaxCellTemp;/* Referenced by: '<S1431>/Constant' */
extern CALDATA const volatile float32 cal_LTRFanCtrl_1X[2];/* Referenced by:
                                                            * '<S924>/Constant1'
                                                            * '<S924>/Constant2'
                                                            */
extern CALDATA const volatile uint8 cal_LTRFanCtrl_1Y[3];/* Referenced by:
                                                          * '<S924>/Constant4'
                                                          * '<S924>/Constant6'
                                                          * '<S924>/Constant9'
                                                          */
extern CALDATA const volatile float32 cal_LTRIGBTMaxExitTempB;/* Referenced by: '<S1600>/Constant' */
extern CALDATA const volatile float32 cal_LTRIGBTTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1061>/Constant1'
                                                                      * '<S1061>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRIGBTTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                     * '<S1061>/Constant4'
                                                                     * '<S1061>/Constant6'
                                                                     * '<S1061>/Constant9'
                                                                     */
extern CALDATA const volatile float32 cal_LTRIPUTempFanCtrl_1X[2];/* Referenced by:
                                                                   * '<S923>/Constant1'
                                                                   * '<S923>/Constant2'
                                                                   */
extern CALDATA const volatile uint8 cal_LTRIPUTempFanCtrl_1Y[3];/* Referenced by:
                                                                 * '<S923>/Constant4'
                                                                 * '<S923>/Constant6'
                                                                 * '<S923>/Constant9'
                                                                 */
extern CALDATA const volatile float32 cal_LTRIPUTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1065>/Constant1'
                                                                      * '<S1065>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRIPUTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                    * '<S1065>/Constant4'
                                                                    * '<S1065>/Constant6'
                                                                    * '<S1065>/Constant9'
                                                                    */
extern CALDATA const volatile float32 cal_LTRMotorInletMaxExitTempA;/* Referenced by: '<S1599>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorMaxEntTemp;/* Referenced by: '<S1629>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorMaxExitTemp;/* Referenced by: '<S1602>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1062>/Constant1'
                                                                      * '<S1062>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRMotorTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                      * '<S1062>/Constant4'
                                                                      * '<S1062>/Constant6'
                                                                      * '<S1062>/Constant9'
                                                                      */
extern CALDATA const volatile float32 cal_LTT1DownMCV_1X[5];
                               /* Referenced by: '<S647>/cal_LTT1DownMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1DownMCV_CUR[5];
                               /* Referenced by: '<S647>/cal_LTT1DownMCV_CUR' */
extern CALDATA const volatile float32 cal_LTT1StbyMCV_1X[6];
                               /* Referenced by: '<S647>/cal_LTT1StbyMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1StbyMCV_CUR[6];
                               /* Referenced by: '<S647>/cal_LTT1StbyMCV_CUR' */
extern CALDATA const volatile float32 cal_LTT1UpMCV_1X[5];
                                 /* Referenced by: '<S647>/cal_LTT1UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1UpMCV_CUR[5];
                                 /* Referenced by: '<S647>/cal_LTT1UpMCV_CUR' */
extern CALDATA const volatile boolean cal_LessThanT1CalSwt;/* Referenced by:
                                                            * '<S645>/Constant3'
                                                            * '<S647>/Constant3'
                                                            */
extern CALDATA const volatile float32 cal_LoPressData;/* Referenced by: '<S1764>/Constant' */
extern CALDATA const volatile boolean cal_LoPressDataEnb;/* Referenced by: '<S1764>/Constant1' */
extern CALDATA const volatile float32 cal_LoPressRaw_1X[2];
                                  /* Referenced by: '<S1707>/cal_LoPress_CUR' */
extern CALDATA const volatile float32 cal_LoPressRaw_CUR[2];
                                  /* Referenced by: '<S1707>/cal_LoPress_CUR' */
extern CALDATA const volatile float32 cal_MBIGBTHighExitTempG;/* Referenced by: '<S1589>/Constant' */
extern CALDATA const volatile float32 cal_MBIPUDevHighExitTempI;/* Referenced by: '<S1593>/Constant' */
extern CALDATA const volatile float32 cal_MBMotorInletHighExitTempH;/* Referenced by: '<S1590>/Constant' */
extern CALDATA const volatile uint8 cal_MCVFltStsDelayTime;/* Referenced by: '<S640>/Constant5' */
extern CALDATA const volatile float32 cal_MCVPosDiffDelayTime;/* Referenced by: '<S640>/Constant2' */
extern CALDATA const volatile uint8 cal_MixCoolTrgPos;/* Referenced by: '<S1195>/Constant1' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinCoolingEn_OFF;/* Referenced by: '<S85>/Constant7' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinCoolingEn_ON;/* Referenced by: '<S85>/Constant6' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinHeatingEn_OFF;
/* Referenced by: '<S90>/On:cal_MixDoor2CabinHeatingEn_ON Off:cal_MixDoor2CabinHeatingEn_OFF ' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinHeatingEn_ON;
/* Referenced by: '<S90>/On:cal_MixDoor2CabinHeatingEn_ON Off:cal_MixDoor2CabinHeatingEn_OFF ' */
extern CALDATA const volatile float32 cal_MixDoorClsFF_1X[8];
                              /* Referenced by: '<S387>/cal_MixDoorClsFF_CUR' */
extern CALDATA const volatile float32 cal_MixDoorClsFF_CUR[8];
                              /* Referenced by: '<S387>/cal_MixDoorClsFF_CUR' */
extern CALDATA const volatile boolean cal_MixDoorEnb;/* Referenced by:
                                                      * '<S1195>/Judge'
                                                      * '<S1195>/Constant6'
                                                      * '<S1228>/Constant1'
                                                      * '<S1229>/Constant1'
                                                      */
extern CALDATA const volatile float32 cal_MixDoorKi_1X[8];
                                 /* Referenced by: '<S387>/cal_MixDoorKi_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKi_CUR[8];
                                 /* Referenced by: '<S387>/cal_MixDoorKi_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKp_1X[8];
                                 /* Referenced by: '<S387>/cal_MixDoorKp_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKp_CUR[8];
                                 /* Referenced by: '<S387>/cal_MixDoorKp_CUR' */
extern CALDATA const volatile uint8 cal_MixDoorNData;/* Referenced by: '<S1228>/Constant' */
extern CALDATA const volatile float32 cal_MixDoorNErr;/* Referenced by: '<S1195>/Judge' */
extern CALDATA const volatile uint8 cal_MixDoorPData;/* Referenced by: '<S1229>/Constant' */
extern CALDATA const volatile float32 cal_MixDoorPErr;/* Referenced by: '<S1195>/Judge' */
extern CALDATA const volatile float32 cal_MixDoorPercData;/* Referenced by: '<S1771>/Constant' */
extern CALDATA const volatile boolean cal_MixDoorPercDataEnb;/* Referenced by: '<S1771>/Constant1' */
extern CALDATA const volatile float32 cal_MixDoorPerc_CUR[2];
                              /* Referenced by: '<S1708>/cal_MixDoorPerc_CUR' */
extern CALDATA const volatile float32 cal_MixDoorV_1X[2];
                              /* Referenced by: '<S1708>/cal_MixDoorPerc_CUR' */
extern CALDATA const volatile uint16 cal_MixDoorVolAmend_1X[2];
                          /* Referenced by: '<S1708>/cal_MixDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_MixDoorVolAmend_CUR[2];
                          /* Referenced by: '<S1708>/cal_MixDoorVolAmend_CUR' */
extern CALDATA const volatile uint8 cal_MixWarmTrgPos;/* Referenced by: '<S1195>/Constant' */
extern CALDATA const volatile uint16 cal_ModeDoorVolAmend_1X[2];
                         /* Referenced by: '<S1709>/cal_ModeDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ModeDoorVolAmend_CUR[2];
                         /* Referenced by: '<S1709>/cal_ModeDoorVolAmend_CUR' */
extern CALDATA const volatile boolean cal_ModeMotorEnb;/* Referenced by:
                                                        * '<S1196>/Judge'
                                                        * '<S1196>/Constant4'
                                                        * '<S1236>/Constant1'
                                                        * '<S1237>/Constant1'
                                                        */
extern CALDATA const volatile uint8 cal_ModeMotorNData;/* Referenced by: '<S1236>/Constant' */
extern CALDATA const volatile float32 cal_ModeMotorNErr;/* Referenced by: '<S1196>/Judge' */
extern CALDATA const volatile uint8 cal_ModeMotorPData;/* Referenced by: '<S1237>/Constant' */
extern CALDATA const volatile float32 cal_ModeMotorPErr;/* Referenced by: '<S1196>/Judge' */
extern CALDATA const volatile float32 cal_ModeMotorTrgPosData;/* Referenced by: '<S1235>/Constant' */
extern CALDATA const volatile boolean cal_ModeMotorTrgPosDataEnb;/* Referenced by:
                                                                  * '<S1196>/Constant3'
                                                                  * '<S1235>/Constant1'
                                                                  */
extern CALDATA const volatile uint8 cal_ModeMotorTrgPos_1X[5];
                          /* Referenced by: '<S1196>/cal_ModeMotorTrgPos_CUR' */
extern CALDATA const volatile float32 cal_ModeMotorTrgPos_CUR[5];
                          /* Referenced by: '<S1196>/cal_ModeMotorTrgPos_CUR' */
extern CALDATA const volatile float32 cal_MotHeatBatMinTempDiff;/* Referenced by: '<S1319>/Constant' */
extern CALDATA const volatile uint16 cal_MotInletTempVolAmend_1X[2];
                     /* Referenced by: '<S1716>/cal_MotInletTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_MotInletTempVolAmend_CUR[2];
                     /* Referenced by: '<S1716>/cal_MotInletTempVolAmend_CUR' */
extern CALDATA const volatile uint8 cal_MotPMPDefaultSpd;/* Referenced by: '<S1022>/Constant4' */
extern CALDATA const volatile boolean cal_MotPMPFaultFlgData;/* Referenced by: '<S1063>/Constant' */
extern CALDATA const volatile boolean cal_MotPMPFaultFlgDataEnb;/* Referenced by: '<S1063>/Constant1' */
extern CALDATA const volatile uint8 cal_MotPMPMotHeatBatSpd;/* Referenced by: '<S1022>/Constant11' */
extern CALDATA const volatile uint8 cal_MotPMPSpdDiffVal;/* Referenced by: '<S1022>/Constant' */
extern CALDATA const volatile uint8 cal_MotPMPSpdSetData;/* Referenced by: '<S1064>/Constant' */
extern CALDATA const volatile boolean cal_MotPMPSpdSetDataEnb;/* Referenced by: '<S1064>/Constant1' */
extern CALDATA const volatile uint8 cal_MotPMPThStoSpd;/* Referenced by: '<S1022>/Constant12' */
extern CALDATA const volatile float32 cal_MotTempData;/* Referenced by: '<S1831>/Constant' */
extern CALDATA const volatile boolean cal_MotTempDataEnb;/* Referenced by: '<S1831>/Constant1' */
extern CALDATA const volatile float32 cal_MotTempDownLmt;/* Referenced by: '<S1277>/Relay' */
extern CALDATA const volatile float32 cal_MotTempUpLmt;/* Referenced by: '<S1277>/Relay' */
extern CALDATA const volatile float32 cal_MotorModeData;/* Referenced by: '<S1778>/Constant' */
extern CALDATA const volatile boolean cal_MotorModeEnb;/* Referenced by: '<S1778>/Constant1' */
extern CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOff;/* Referenced by: '<S498>/Relay' */
extern CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOn;/* Referenced by: '<S498>/Relay' */
extern CALDATA const volatile float32 cal_NmlBatHeatEnvTemp[2];/* Referenced by: '<S1492>/Constant1' */
extern CALDATA const volatile float32 cal_NmlBatHeatT1[3];/* Referenced by: '<S1492>/Constant2' */
extern CALDATA const volatile float32 cal_NmlBatHeatT2[3];/* Referenced by: '<S1492>/Constant3' */
extern CALDATA const volatile float32 cal_NmlBatHeatTave[3];/* Referenced by: '<S1492>/Constant' */
extern CALDATA const volatile float32 cal_NmlBatHeatTrgTemp;/* Referenced by:
                                                             * '<S646>/Constant6'
                                                             * '<S1492>/Constant4'
                                                             */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsDownSpd;/* Referenced by: '<S452>/Constant' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP1;/* Referenced by: '<S452>/Relay1' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP2;/* Referenced by: '<S452>/Relay1' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP3;/* Referenced by: '<S452>/Relay' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP4;/* Referenced by: '<S452>/Relay' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP5;/* Referenced by: '<S452>/Relay2' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP6;/* Referenced by: '<S452>/Relay2' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP7;/* Referenced by: '<S452>/Relay3' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP8;/* Referenced by: '<S452>/Relay3' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsDownSpd;/* Referenced by: '<S452>/Constant2' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP1;/* Referenced by: '<S452>/Relay9' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP2;/* Referenced by: '<S452>/Relay9' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP3;/* Referenced by: '<S452>/Relay8' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP4;/* Referenced by: '<S452>/Relay8' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP5;/* Referenced by: '<S452>/Relay10' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP6;/* Referenced by: '<S452>/Relay10' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP7;/* Referenced by: '<S452>/Relay11' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP8;/* Referenced by: '<S452>/Relay11' */
extern CALDATA const volatile float32 cal_OHXTempData;/* Referenced by: '<S1841>/Constant' */
extern CALDATA const volatile boolean cal_OHXTempDataEnb;/* Referenced by: '<S1841>/Constant1' */
extern CALDATA const volatile uint16 cal_OHXTempVolAmend_1X[2];
                          /* Referenced by: '<S1717>/cal_OHXTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_OHXTempVolAmend_CUR[2];
                          /* Referenced by: '<S1717>/cal_OHXTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_OpenCoolInletTemp;/* Referenced by: '<S1281>/Constant1' */
extern CALDATA const volatile float32 cal_OpenCtrlCOMPDownlmt;/* Referenced by: '<S565>/Constant4' */
extern CALDATA const volatile float32 cal_OpenCtrlCOMPUplmt;/* Referenced by: '<S565>/Constant3' */
extern CALDATA const volatile uint8 cal_OutRecTrgPos;/* Referenced by: '<S1194>/Constant' */
extern CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_1X[8];
                       /* Referenced by: '<S543>/cal_PCULimBTMAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_CUR[8];
                       /* Referenced by: '<S543>/cal_PCULimBTMAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_1X[8];
               /* Referenced by: '<S543>/cal_PCULimBTMAndCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_CUR[8];
               /* Referenced by: '<S543>/cal_PCULimBTMAndCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_1X[8];
                     /* Referenced by: '<S543>/cal_PCULimCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_CUR[8];
                     /* Referenced by: '<S543>/cal_PCULimCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_1X[7];
                  /* Referenced by: '<S1261>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_CUR[7];
                  /* Referenced by: '<S1261>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2X[6];
                          /* Referenced by: '<S580>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2Y[6];
                          /* Referenced by: '<S580>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_MAP[36];
                          /* Referenced by: '<S580>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_1X[9];
                          /* Referenced by: '<S945>/cal_PTCBatHeatPwrLmt_CUR' */
extern CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_CUR[9];
                          /* Referenced by: '<S945>/cal_PTCBatHeatPwrLmt_CUR' */
extern CALDATA const volatile uint8 cal_PTCDelOffTime;/* Referenced by: '<S945>/Constant12' */
extern CALDATA const volatile uint8 cal_PTCEnableData;/* Referenced by: '<S1011>/Constant' */
extern CALDATA const volatile boolean cal_PTCEnableDataEnb;/* Referenced by: '<S1011>/Constant1' */
extern CALDATA const volatile float32 cal_PTCMaxTemp;/* Referenced by: '<S441>/Constant1' */
extern CALDATA const volatile float32 cal_PTCMinTemp;/* Referenced by: '<S441>/Constant3' */
extern CALDATA const volatile uint8 cal_PTCOffAcPMPSpd;/* Referenced by: '<S1020>/Constant16' */
extern CALDATA const volatile float32 cal_PTCOffPowerVal;/* Referenced by: '<S580>/Constant6' */
extern CALDATA const volatile float32 cal_PTCOnReqPower_1X[6];
                             /* Referenced by: '<S580>/cal_PTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_PTCOnReqPower_CUR[6];
                             /* Referenced by: '<S580>/cal_PTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_PTCPwrOffFlt;/* Referenced by: '<S945>/Constant11' */
extern CALDATA const volatile float32 cal_PTCReqTempData;/* Referenced by: '<S942>/Constant' */
extern CALDATA const volatile boolean cal_PTCReqTempDataEnb;/* Referenced by: '<S942>/Constant1' */
extern CALDATA const volatile float32 cal_PTCReqtPowerData;/* Referenced by: '<S1018>/Constant' */
extern CALDATA const volatile boolean cal_PTCReqtPowerDataEnb;/* Referenced by: '<S1018>/Constant1' */
extern CALDATA const volatile uint8 cal_PTCRunAcPMPFFSpd;/* Referenced by:
                                                          * '<S1020>/Constant12'
                                                          * '<S1020>/Constant14'
                                                          */
extern CALDATA const volatile float32 cal_PTCRunAcPMPFFTime;/* Referenced by: '<S1020>/Constant15' */
extern CALDATA const volatile float32 cal_PTCTempRecircOff;/* Referenced by: '<S129>/Constant5' */
extern CALDATA const volatile float32 cal_PTCTempRecircOn;/* Referenced by: '<S129>/Constant6' */
extern CALDATA const volatile float32 cal_PressRateVal1;/* Referenced by: '<S530>/Relay' */
extern CALDATA const volatile float32 cal_PressRateVal1Relay;/* Referenced by: '<S530>/Relay' */
extern CALDATA const volatile float32 cal_PressRateVal2;/* Referenced by:
                                                         * '<S528>/Relay1'
                                                         * '<S530>/Relay1'
                                                         */
extern CALDATA const volatile float32 cal_PressRateVal2Relay;/* Referenced by:
                                                              * '<S528>/Relay1'
                                                              * '<S530>/Relay1'
                                                              */
extern CALDATA const volatile float32 cal_PressRateVal3;/* Referenced by:
                                                         * '<S525>/Relay2'
                                                         * '<S528>/Relay2'
                                                         * '<S530>/Relay2'
                                                         * '<S532>/Relay1'
                                                         */
extern CALDATA const volatile float32 cal_PressRateVal3Relay;/* Referenced by:
                                                              * '<S525>/Relay2'
                                                              * '<S528>/Relay2'
                                                              * '<S530>/Relay2'
                                                              */
extern CALDATA const volatile float32 cal_PressRateVal4;/* Referenced by: '<S532>/Relay1' */
extern CALDATA const volatile float32 cal_PsDVTWeight;
                    /* Referenced by: '<S55>/ACCtl_facLeftBlowerFanSpdWeight' */
extern CALDATA const volatile float32 cal_PsDuctFaceFloorFaFactor;/* Referenced by: '<S224>/Constant3' */
extern CALDATA const volatile float32 cal_PsDuctFaceFloorFoFactor;/* Referenced by: '<S224>/Constant4' */
extern CALDATA const volatile float32 cal_PsDuctSensorFailDeflt;
                       /* Referenced by: '<S172>/cal_PsDuctSensorFailDefault' */
extern CALDATA const volatile float32 cal_PsEnv4SetSelect;/* Referenced by: '<S182>/Constant3' */
extern CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOff;
/* Referenced by: '<S412>/On:cal_PsErrOfEvaDVT2CoolMixOn Off:cal_PsErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOn;
/* Referenced by: '<S412>/On:cal_PsErrOfEvaDVT2CoolMixOn Off:cal_PsErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOff;
/* Referenced by: '<S412>/On:cal_PsErrOfPtcDVT2HeatMixOn Off:cal_PsErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOn;
/* Referenced by: '<S412>/On:cal_PsErrOfPtcDVT2HeatMixOn Off:cal_PsErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandNeg;/* Referenced by: '<S303>/Kp12' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandPos;/* Referenced by: '<S303>/Kp11' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKi;/* Referenced by: '<S303>/Kp7' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKiNeg;/* Referenced by: '<S303>/Kp9' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKiPos;/* Referenced by: '<S303>/Kp10' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKp;/* Referenced by: '<S303>/Kp' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKpNeg;/* Referenced by: '<S303>/Kp1' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKpPos;/* Referenced by: '<S303>/Kp2' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL;/* Referenced by: '<S303>/Kp6' */
extern CALDATA const volatile uint8 cal_PsEvaDesValPIDLL_2X[4];
                          /* Referenced by: '<S273>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL_2Y[7];
                          /* Referenced by: '<S273>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL_MAP[28];
                          /* Referenced by: '<S273>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDUL;/* Referenced by: '<S303>/Kp5' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMax;/* Referenced by: '<S303>/Kp8' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMin;/* Referenced by: '<S303>/Kp13' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_pWinNeg;/* Referenced by: '<S303>/Kp4' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_pWinPos;/* Referenced by: '<S303>/Kp3' */
extern CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_1X[4];
                      /* Referenced by: '<S303>/cal_PsEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_CUR[4];
                      /* Referenced by: '<S303>/cal_PsEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetAC_1X[8];
                             /* Referenced by: '<S412>/cal_PsMixBacSetAC_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetAC_CUR[8];
                             /* Referenced by: '<S412>/cal_PsMixBacSetAC_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetBi_1X[8];
                             /* Referenced by: '<S412>/cal_PsMixBacSetBi_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetBi_CUR[8];
                             /* Referenced by: '<S412>/cal_PsMixBacSetBi_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetDefog_1X[8];
                          /* Referenced by: '<S412>/cal_PsMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetDefog_CUR[8];
                          /* Referenced by: '<S412>/cal_PsMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFootDe_1X[8];
                         /* Referenced by: '<S412>/cal_PsMixBacSetFootDe_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFootDe_CUR[8];
                         /* Referenced by: '<S412>/cal_PsMixBacSetFootDe_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFoot_1X[8];
                           /* Referenced by: '<S412>/cal_PsMixBacSetFoot_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFoot_CUR[8];
                           /* Referenced by: '<S412>/cal_PsMixBacSetFoot_CUR' */
extern CALDATA const volatile float32 cal_PsMixDesValPIDIntegDeadBand;/* Referenced by: '<S413>/Kp11' */
extern CALDATA const volatile uint8 cal_PsMixDesValPIDLL;/* Referenced by: '<S413>/Kp6' */
extern CALDATA const volatile uint8 cal_PsMixDesValPIDUL;/* Referenced by: '<S413>/Kp5' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_IsumMax;/* Referenced by: '<S413>/Kp8' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_IsumMin;/* Referenced by: '<S413>/Kp13' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_Ki;/* Referenced by: '<S413>/Kp7' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KiNeg;/* Referenced by: '<S413>/Kp9' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KiPos;/* Referenced by: '<S413>/Kp10' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_Kp;/* Referenced by: '<S413>/Kp' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KpNeg;/* Referenced by: '<S413>/Kp1' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KpPos;/* Referenced by: '<S413>/Kp2' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_pWinNeg;/* Referenced by: '<S413>/Kp4' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_pWinPos;/* Referenced by: '<S413>/Kp3' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4InHeat;/* Referenced by: '<S361>/Kp16' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4OutHeat;/* Referenced by: '<S361>/Kp24' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKi;/* Referenced by: '<S361>/Kp7' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKiNeg;/* Referenced by: '<S361>/Kp9' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKiPos;/* Referenced by: '<S361>/Kp10' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKp;/* Referenced by: '<S361>/Kp' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKpNeg;/* Referenced by: '<S361>/Kp1' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKpPos;/* Referenced by: '<S361>/Kp2' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDLL;/* Referenced by: '<S361>/Kp6' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDUL;/* Referenced by: '<S361>/Kp5' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMax;/* Referenced by: '<S361>/Kp8' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMin;/* Referenced by: '<S361>/Kp13' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_pWinNeg;/* Referenced by: '<S361>/Kp4' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_pWinPos;/* Referenced by: '<S361>/Kp3' */
extern CALDATA const volatile boolean cal_PtcEnable;/* Referenced by:
                                                     * '<S383>/Constant5'
                                                     * '<S384>/Constant5'
                                                     */
extern CALDATA const volatile float32 cal_PtcPwrDesValPIDDeadBandNeg;/* Referenced by: '<S91>/Constant6' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPIDDeadBandPos;/* Referenced by: '<S91>/Constant7' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_IsumMax;/* Referenced by: '<S91>/Kp8' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_IsumMin;/* Referenced by: '<S91>/Kp13' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_Ki;/* Referenced by: '<S91>/Kp7' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KiNeg;/* Referenced by: '<S91>/Kp9' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KiPos;/* Referenced by: '<S91>/Kp10' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_Kp;/* Referenced by: '<S91>/Kp' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KpNeg;/* Referenced by: '<S91>/Kp1' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KpPos;/* Referenced by: '<S91>/Kp2' */
extern CALDATA const volatile uint16 cal_PtcPwrDesValPID_LL;/* Referenced by: '<S91>/Kp6' */
extern CALDATA const volatile uint16 cal_PtcPwrDesValPID_UL;/* Referenced by: '<S91>/Kp5' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_pWinNeg;/* Referenced by: '<S91>/Kp4' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_pWinPos;/* Referenced by: '<S91>/Kp3' */
extern CALDATA const volatile boolean cal_PwrACPumpData;/* Referenced by: '<S1202>/Constant' */
extern CALDATA const volatile boolean cal_PwrACPumpEnb;/* Referenced by: '<S1202>/Constant1' */
extern CALDATA const volatile boolean cal_PwrBlwData;/* Referenced by: '<S1205>/Constant' */
extern CALDATA const volatile boolean cal_PwrBlwEnb;/* Referenced by: '<S1205>/Constant1' */
extern CALDATA const volatile uint8 cal_PwrFanAndPumpData;/* Referenced by: '<S1213>/Constant' */
extern CALDATA const volatile boolean cal_PwrFanAndPumpDataEnb;/* Referenced by: '<S1213>/Constant1' */
extern CALDATA const volatile boolean cal_PwrFanData;/* Referenced by: '<S1197>/Constant' */
extern CALDATA const volatile boolean cal_PwrFanEnb;/* Referenced by: '<S1197>/Constant1' */
extern CALDATA const volatile boolean cal_PwrHVPartData;/* Referenced by: '<S1216>/Constant' */
extern CALDATA const volatile boolean cal_PwrHVPartEnb;/* Referenced by: '<S1216>/Constant1' */
extern CALDATA const volatile boolean cal_PwrSensorData;/* Referenced by: '<S1198>/Constant' */
extern CALDATA const volatile boolean cal_PwrSensorEnb;/* Referenced by: '<S1198>/Constant1' */
extern CALDATA const volatile float32 cal_REC_DVTFresh;/* Referenced by: '<S133>/Constant6' */
extern CALDATA const volatile float32 cal_REC_DVTRecirc;/* Referenced by: '<S133>/Constant5' */
extern CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_1X[14];
                       /* Referenced by: '<S77>/cal_RFace2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_CUR[14];
                       /* Referenced by: '<S77>/cal_RFace2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_1X[14];
                       /* Referenced by: '<S77>/cal_RFaceFloor2FaceByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_CUR[14];
                       /* Referenced by: '<S77>/cal_RFaceFloor2FaceByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_1X[14];
                      /* Referenced by: '<S77>/cal_RFaceFloor2FloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_CUR[14];
                      /* Referenced by: '<S77>/cal_RFaceFloor2FloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_1X[14];
                      /* Referenced by: '<S77>/cal_RFloor2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_CUR[14];
                      /* Referenced by: '<S77>/cal_RFloor2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RecirActVal_1X[2];
                              /* Referenced by: '<S1710>/cal_RecirActVal_CUR' */
extern CALDATA const volatile uint8 cal_RecirActVal_CUR[2];
                              /* Referenced by: '<S1710>/cal_RecirActVal_CUR' */
extern CALDATA const volatile float32 cal_RecircDoorNErr;/* Referenced by: '<S1194>/Judge' */
extern CALDATA const volatile float32 cal_RecircDoorPErr;/* Referenced by: '<S1194>/Judge' */
extern CALDATA const volatile uint16 cal_RecircDoorVolAmend_1X[2];
                       /* Referenced by: '<S1710>/cal_RecircDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_RecircDoorVolAmend_CUR[2];
                       /* Referenced by: '<S1710>/cal_RecircDoorVolAmend_CUR' */
extern CALDATA const volatile boolean cal_RecircMotorEnb;/* Referenced by:
                                                          * '<S1194>/Judge'
                                                          * '<S1194>/Constant6'
                                                          * '<S1221>/Constant1'
                                                          * '<S1222>/Constant1'
                                                          */
extern CALDATA const volatile uint8 cal_RecircMotorNData;/* Referenced by: '<S1221>/Constant' */
extern CALDATA const volatile uint8 cal_RecircMotorPData;/* Referenced by: '<S1222>/Constant' */
extern CALDATA const volatile uint8 cal_RecircTrgPosData;/* Referenced by: '<S1223>/Constant' */
extern CALDATA const volatile boolean cal_RecircTrgPosDataEnb;/* Referenced by:
                                                               * '<S1194>/Constant5'
                                                               * '<S1223>/Constant1'
                                                               */
extern CALDATA const volatile RefModes cal_RefModeData;/* Referenced by: '<S1697>/Constant' */
extern CALDATA const volatile boolean cal_RefModeEnb;/* Referenced by: '<S1697>/Constant1' */
extern CALDATA const volatile uint16 cal_RiseTime2EnvTamb;
                                      /* Referenced by: '<S177>/TempRampStep' */
extern CALDATA const volatile uint16 cal_RiseTime2Solar;
                                     /* Referenced by: '<S182>/TempRampStep1' */
extern CALDATA const volatile uint16 cal_RiseTime2Tamb;
                                     /* Referenced by: '<S1703>/TempRampStep' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOff;/* Referenced by: '<S945>/Relay' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOn;/* Referenced by: '<S945>/Relay' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_1X[6];
                          /* Referenced by: '<S945>/cal_SOCHighPTCPwrLmt_CUR' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_CUR[6];
                          /* Referenced by: '<S945>/cal_SOCHighPTCPwrLmt_CUR' */
extern CALDATA const volatile boolean cal_SOVData;/* Referenced by: '<S1239>/Constant' */
extern CALDATA const volatile boolean cal_SOVEnb;/* Referenced by: '<S1239>/Constant1' */
extern CALDATA const volatile float32 cal_SensorTempDownFlg;/* Referenced by:
                                                             * '<S1728>/Constant1'
                                                             * '<S1748>/Constant1'
                                                             * '<S1758>/Constant1'
                                                             * '<S1799>/Constant1'
                                                             * '<S1809>/Constant1'
                                                             * '<S1818>/Constant1'
                                                             * '<S1828>/Constant1'
                                                             * '<S1836>/Constant1'
                                                             * '<S1844>/Constant1'
                                                             * '<S1853>/Constant1'
                                                             * '<S1871>/Constant1'
                                                             */
extern CALDATA const volatile float32 cal_SensorTempUpFlt;/* Referenced by:
                                                           * '<S1728>/Constant'
                                                           * '<S1748>/Constant'
                                                           * '<S1758>/Constant'
                                                           * '<S1799>/Constant'
                                                           * '<S1809>/Constant'
                                                           * '<S1818>/Constant'
                                                           * '<S1828>/Constant'
                                                           * '<S1836>/Constant'
                                                           * '<S1844>/Constant'
                                                           * '<S1853>/Constant'
                                                           * '<S1871>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_SensorVolDownFlg;/* Referenced by:
                                                            * '<S1765>/Constant1'
                                                            * '<S1772>/Constant1'
                                                            * '<S1779>/Constant1'
                                                            * '<S1786>/Constant1'
                                                            * '<S1789>/Constant1'
                                                            * '<S1861>/Constant1'
                                                            */
extern CALDATA const volatile float32 cal_SensorVolUpFlg;/* Referenced by:
                                                          * '<S1765>/Constant'
                                                          * '<S1772>/Constant'
                                                          * '<S1779>/Constant'
                                                          * '<S1786>/Constant'
                                                          * '<S1789>/Constant'
                                                          * '<S1861>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_SetLeftMixDoorTrgData;/* Referenced by: '<S1230>/Constant' */
extern CALDATA const volatile boolean cal_SetLeftMixDoorTrgDataEnb;/* Referenced by:
                                                                    * '<S1195>/Constant5'
                                                                    * '<S1230>/Constant1'
                                                                    */
extern CALDATA const volatile float32 cal_SetPtcDesCoff;/* Referenced by: '<S176>/Constant5' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMax_2X[10];
                          /* Referenced by: '<S176>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile uint8 cal_SetPtcDesTempMax_2Y[10];
                          /* Referenced by: '<S176>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMax_MAP[100];
                          /* Referenced by: '<S176>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMin;/* Referenced by: '<S176>/Constant8' */
extern CALDATA const volatile uint16 cal_SolarData;/* Referenced by: '<S1788>/Constant' */
extern CALDATA const volatile boolean cal_SolarEnb;/* Referenced by: '<S1788>/Constant1' */
extern CALDATA const volatile uint16 cal_SolarFalseStep;
                           /* Referenced by: '<S207>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile uint16 cal_SolarRiseStep;
                           /* Referenced by: '<S207>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile float32 cal_SolarValRaw_1X[11];
                              /* Referenced by: '<S1711>/cal_SolarValRaw_CUR' */
extern CALDATA const volatile uint16 cal_SolarValRaw_CUR[11];
                              /* Referenced by: '<S1711>/cal_SolarValRaw_CUR' */
extern CALDATA const volatile uint16 cal_SolorVolAmend_1X[2];
                            /* Referenced by: '<S1711>/cal_SolorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_SolorVolAmend_CUR[2];
                            /* Referenced by: '<S1711>/cal_SolorVolAmend_CUR' */
extern CALDATA const volatile float32 cal_StartPrsProTimes;/* Referenced by: '<S452>/Constant4' */
extern CALDATA const volatile float32 cal_SuperHeatFilter;/* Referenced by:
                                                           * '<S894>/Constant1'
                                                           * '<S895>/Constant1'
                                                           * '<S896>/Constant1'
                                                           * '<S898>/Constant1'
                                                           */
extern CALDATA const volatile float32 cal_SuperHeat_1X[28];
                                 /* Referenced by: '<S674>/cal_SuperHeat_CUR' */
extern CALDATA const volatile float32 cal_SuperHeat_CUR[28];
                                 /* Referenced by: '<S674>/cal_SuperHeat_CUR' */
extern CALDATA const volatile float32 cal_TACCMOutRaw_1X[30];
                                  /* Referenced by: '<S1720>/cal_ACCMTHi_CUR' */
extern CALDATA const volatile float32 cal_TACCMOutRaw_CUR[30];
                                  /* Referenced by: '<S1720>/cal_ACCMTHi_CUR' */
extern CALDATA const volatile float32 cal_TCabinRaw_1X[27];
                                /* Referenced by: '<S1701>/cal_TCabinRaw_CUR' */
extern CALDATA const volatile float32 cal_TCabinRaw_CUR[27];
                                /* Referenced by: '<S1701>/cal_TCabinRaw_CUR' */
extern CALDATA const volatile float32 cal_TChillOutRaw_1X[27];
                             /* Referenced by: '<S1712>/cal_TChillOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TChillOutRaw_CUR[27];
                             /* Referenced by: '<S1712>/cal_TChillOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TDuctRaw_1X[26];/* Referenced by:
                                                           * '<S1705>/cal_TDuctRaw_CUR'
                                                           * '<S1706>/cal_TDuctRaw_CUR'
                                                           */
extern CALDATA const volatile float32 cal_TDuctRaw_CUR[26];/* Referenced by:
                                                            * '<S1705>/cal_TDuctRaw_CUR'
                                                            * '<S1706>/cal_TDuctRaw_CUR'
                                                            */
extern CALDATA const volatile float32 cal_TEnvRaw_1X[27];
                                  /* Referenced by: '<S1713>/cal_TEnvRaw_CUR' */
extern CALDATA const volatile float32 cal_TEnvRaw_CUR[27];
                                  /* Referenced by: '<S1713>/cal_TEnvRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapOutRaw_1X[30];
                              /* Referenced by: '<S1714>/cal_TEvapOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapOutRaw_CUR[30];
                              /* Referenced by: '<S1714>/cal_TEvapOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapSurfRaw_1X[23];
                                 /* Referenced by: '<S1715>/cal_TEvapSur_CUR' */
extern CALDATA const volatile float32 cal_TEvapSurfRaw_CUR[23];
                                 /* Referenced by: '<S1715>/cal_TEvapSur_CUR' */
extern CALDATA const volatile float32 cal_TLCCOutRaw_1X[20];
                                /* Referenced by: '<S1718>/cal_WCCTHiRaw_CUR' */
extern CALDATA const volatile float32 cal_TLCCOutRaw_CUR[20];
                                /* Referenced by: '<S1718>/cal_WCCTHiRaw_CUR' */
extern CALDATA const volatile PwrModes cal_TMSStatusData;/* Referenced by: '<S1258>/Constant' */
extern CALDATA const volatile uint8 cal_TMSStatusEnb;/* Referenced by: '<S1258>/Constant1' */
extern CALDATA const volatile float32 cal_TMotEntRaw_1X[17];
                                     /* Referenced by: '<S1716>/cal_TMot_CUR' */
extern CALDATA const volatile float32 cal_TMotEntRaw_CUR[17];
                                     /* Referenced by: '<S1716>/cal_TMot_CUR' */
extern CALDATA const volatile float32 cal_TOHXOutRaw_1X[30];
                                  /* Referenced by: '<S1717>/cal_OHXTRaw_CUR' */
extern CALDATA const volatile float32 cal_TOHXOutRaw_CUR[30];
                                  /* Referenced by: '<S1717>/cal_OHXTRaw_CUR' */
extern CALDATA const volatile float32 cal_TSACBatMinEntTempA;/* Referenced by:
                                                              * '<S1613>/Constant'
                                                              * '<S1324>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_TSACBatMinEntTempB;/* Referenced by:
                                                              * '<S1614>/Constant'
                                                              * '<S1325>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_TSACBatMinExitTempM;/* Referenced by:
                                                               * '<S1341>/Constant4'
                                                               * '<S1604>/Constant4'
                                                               */
extern CALDATA const volatile float32 cal_TSACBatMinExitTempN;/* Referenced by:
                                                               * '<S1342>/Constant4'
                                                               * '<S1605>/Constant4'
                                                               */
extern CALDATA const volatile float32 cal_TSBatInletTempOffsetP;/* Referenced by: '<S1344>/Constant5' */
extern CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_1X[5];
                  /* Referenced by: '<S1334>/cal_TSBatMaxTempForEnvExitC_CUR' */
extern CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_CUR[5];
                  /* Referenced by: '<S1334>/cal_TSBatMaxTempForEnvExitC_CUR' */
extern CALDATA const volatile float32 cal_TSBatMinExitTempJ;/* Referenced by: '<S1339>/Constant4' */
extern CALDATA const volatile float32 cal_TSBatMinTempOffsetD;/* Referenced by: '<S1335>/Constant5' */
extern CALDATA const volatile float32 cal_TSBatMinTemplowValB;/* Referenced by: '<S1320>/Constant2' */
extern CALDATA const volatile float32 cal_TSDCBatMinEntTempC;/* Referenced by:
                                                              * '<S1615>/Constant'
                                                              * '<S1326>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_TSDCBatMinExitTempK;/* Referenced by:
                                                               * '<S1340>/Constant4'
                                                               * '<S1603>/Constant4'
                                                               */
extern CALDATA const volatile float32 cal_TSIGBTMinTempEntC;/* Referenced by: '<S1320>/Constant3' */
extern CALDATA const volatile float32 cal_TSIGBTMinTempExitG;/* Referenced by: '<S1336>/Constant3' */
extern CALDATA const volatile float32 cal_TSIPUExitTempI;/* Referenced by:
                                                          * '<S1338>/Constant'
                                                          * '<S1606>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_TSMotorMinTempEntC;/* Referenced by: '<S1320>/Constant' */
extern CALDATA const volatile float32 cal_TSMotorMinTempExitH;/* Referenced by: '<S1337>/Constant' */
extern CALDATA const volatile float32 cal_TempRampStepFast;/* Referenced by: '<S1703>/Constant2' */
extern CALDATA const volatile float32 cal_TempRampStepLoVSpeed;
                                    /* Referenced by: '<S1703>/TempRampStep4' */
extern CALDATA const volatile float32 cal_TempRampStepSlow;/* Referenced by: '<S1703>/Constant1' */
extern CALDATA const volatile float32 cal_TevapLoStepMin;/* Referenced by:
                                                          * '<S175>/Constant2'
                                                          * '<S175>/Constant5'
                                                          */
extern CALDATA const volatile uint16 cal_TevapLoTime;/* Referenced by: '<S175>/Constant6' */
extern CALDATA const volatile float32 cal_TevapUpStepMin;/* Referenced by:
                                                          * '<S176>/Constant'
                                                          * '<S176>/Constant3'
                                                          */
extern CALDATA const volatile uint16 cal_TevapUpTime;
                                    /* Referenced by: '<S176>/PTCHeatedCheck' */
extern CALDATA const volatile float32 cal_U_DVTFFSolarFilterRate;/* Referenced by:
                                                                  * '<S178>/ACCtrl_facSolarFlt_C'
                                                                  * '<S179>/ACCtrl_facSolarFlt_C'
                                                                  * '<S182>/ACCtrl_facSolarFlt_C'
                                                                  */
extern CALDATA const volatile uint16 cal_UpAndDownStartTime;
                           /* Referenced by: '<S207>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile float32 cal_VehHeatSOCOff;/* Referenced by:
                                                         * '<S1312>/Constant'
                                                         * '<S1428>/Constant'
                                                         * '<S1554>/Constant'
                                                         * '<S1566>/Constant'
                                                         * '<S1473>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_VehHeatSOCOn;/* Referenced by:
                                                        * '<S1318>/Constant'
                                                        * '<S1411>/Constant'
                                                        * '<S1547>/Constant'
                                                        * '<S1561>/Constant'
                                                        * '<S1462>/Constant'
                                                        */
extern CALDATA const volatile float32 cal_VehicleSpeedHighVs;/* Referenced by: '<S1731>/Constant' */
extern CALDATA const volatile float32 cal_VehicleSpeedLowVs;/* Referenced by: '<S1732>/Constant' */
extern CALDATA const volatile uint16 cal_WCCHPVolAmend_1X[2];
                            /* Referenced by: '<S1719>/cal_WCCHPVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCHPVolAmend_CUR[2];
                            /* Referenced by: '<S1719>/cal_WCCHPVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_WCCHighTempVolAmend_1X[2];
                      /* Referenced by: '<S1718>/cal_WCCHighTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCHighTempVolAmend_CUR[2];
                      /* Referenced by: '<S1718>/cal_WCCHighTempVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_WCCLPVolAmend_1X[2];
                            /* Referenced by: '<S1707>/cal_WCCLPVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCLPVolAmend_CUR[2];
                            /* Referenced by: '<S1707>/cal_WCCLPVolAmend_CUR' */
extern CALDATA const volatile float32 cal_WCCTempData;/* Referenced by: '<S1851>/Constant' */
extern CALDATA const volatile boolean cal_WCCTempDataEnb;/* Referenced by: '<S1851>/Constant1' */
extern CALDATA const volatile WaterModes cal_WaterModeData;/* Referenced by: '<S1689>/Constant' */
extern CALDATA const volatile boolean cal_WaterModeEnb;/* Referenced by: '<S1689>/Constant1' */
extern CALDATA const volatile boolean cal_bACAutoData;/* Referenced by: '<S1145>/Constant' */
extern CALDATA const volatile boolean cal_bACAutoEnb;/* Referenced by: '<S1145>/Constant1' */
extern CALDATA const volatile boolean cal_bACDefrostData;/* Referenced by: '<S1159>/Constant' */
extern CALDATA const volatile boolean cal_bACDefrostEnb;/* Referenced by: '<S1159>/Constant1' */
extern CALDATA const volatile boolean cal_bACOnOffData;/* Referenced by: '<S1171>/Constant' */
extern CALDATA const volatile boolean cal_bACOnOffEnb;/* Referenced by: '<S1171>/Constant1' */
extern CALDATA const volatile boolean cal_bExhFlgData;/* Referenced by: '<S1081>/Constant' */
extern CALDATA const volatile boolean cal_bExhFlgEnb;/* Referenced by: '<S1081>/Constant1' */
extern CALDATA const volatile boolean cal_bLeftSetHighData;/* Referenced by: '<S1126>/Constant' */
extern CALDATA const volatile boolean cal_bLeftSetHighEnb;/* Referenced by: '<S1126>/Constant1' */
extern CALDATA const volatile boolean cal_bLeftSetLowData;/* Referenced by: '<S1127>/Constant' */
extern CALDATA const volatile boolean cal_bLeftSetLowEnb;/* Referenced by: '<S1127>/Constant1' */
extern CALDATA const volatile uint8 cal_eACStsData;/* Referenced by: '<S1183>/Constant' */
extern CALDATA const volatile boolean cal_eACStsEnb;/* Referenced by: '<S1183>/Constant1' */
extern CALDATA const volatile uint8 cal_eBlwStsData;/* Referenced by: '<S1092>/Constant' */
extern CALDATA const volatile boolean cal_eBlwStsEnb;/* Referenced by: '<S1092>/Constant1' */
extern CALDATA const volatile uint8 cal_eC3WVValueData;/* Referenced by: '<S637>/Constant' */
extern CALDATA const volatile boolean cal_eC3WVValueEnb;/* Referenced by: '<S637>/Constant1' */
extern CALDATA const volatile uint8 cal_eC5WVValueData;/* Referenced by: '<S638>/Constant' */
extern CALDATA const volatile boolean cal_eC5WVValueEnb;/* Referenced by: '<S638>/Constant1' */
extern CALDATA const volatile uint8 cal_eInnerData;/* Referenced by: '<S1108>/Constant' */
extern CALDATA const volatile boolean cal_eInnerEnb;/* Referenced by: '<S1108>/Constant1' */
extern CALDATA const volatile uint8 cal_eModeMotorData;/* Referenced by: '<S1115>/Constant' */
extern CALDATA const volatile boolean cal_eModeMotorEnb;/* Referenced by: '<S1115>/Constant1' */
extern CALDATA const volatile float32 cal_rCabinCoolToCondMixDoor;/* Referenced by: '<S1654>/Constant' */
extern CALDATA const volatile uint8 cal_rCabinEvpToHPInnRatio;/* Referenced by: '<S1681>/Constant' */
extern CALDATA const volatile uint8 cal_rCabinHPToEvpInnRatio;/* Referenced by: '<S1680>/Constant' */
extern CALDATA const volatile float32 cal_sMixDoorData;/* Referenced by: '<S1110>/Constant' */
extern CALDATA const volatile boolean cal_sMixDoorEnb;/* Referenced by: '<S1110>/Constant1' */
extern CALDATA const volatile float32 cal_tACBatCoolCellTempOn;/* Referenced by: '<S1364>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitACChrgMinCellTemp;/* Referenced by: '<S1315>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitBal1ToBatDiff;/* Referenced by: '<S1308>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitBatToBal2Diff;/* Referenced by: '<S1305>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitDCChrgMinCellTemp;/* Referenced by: '<S1310>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitMaxToMinCellDiff;/* Referenced by: '<S1313>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalONACChrgMinCellTemp;/* Referenced by: '<S1303>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolACChrgCellTempOff;/* Referenced by: '<S1394>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolCellTempOn;/* Referenced by: '<S1376>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolDCChrgCellTempOff;/* Referenced by: '<S1393>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolVehReadyCellTempOff;/* Referenced by: '<S1395>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOff;/* Referenced by: '<S1484>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOn;/* Referenced by: '<S1448>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOff;/* Referenced by: '<S1487>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOn;/* Referenced by: '<S1451>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOff;/* Referenced by: '<S1482>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOn;/* Referenced by: '<S1447>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatExitMaxToMinCellDiff;/* Referenced by:
                                                                      * '<S1304>/Constant'
                                                                      * '<S1311>/Constant'
                                                                      * '<S1317>/Constant'
                                                                      * '<S1343>/Constant'
                                                                      * '<S1546>/Constant'
                                                                      * '<S1552>/Constant'
                                                                      * '<S1556>/Constant'
                                                                      * '<S1560>/Constant'
                                                                      * '<S1565>/Constant'
                                                                      * '<S1577>/Constant'
                                                                      * '<S1581>/Constant'
                                                                      * '<S1588>/Constant'
                                                                      * '<S1616>/Constant'
                                                                      * '<S1323>/Constant'
                                                                      * '<S1327>/Constant'
                                                                      * '<S1367>/Constant'
                                                                      * '<S1377>/Constant'
                                                                      * '<S1384>/Constant'
                                                                      * '<S1422>/Constant'
                                                                      * '<S1432>/Constant'
                                                                      * '<S1452>/Constant'
                                                                      * '<S1463>/Constant'
                                                                      * '<S1471>/Constant'
                                                                      * '<S1523>/Constant'
                                                                      * '<S1534>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOff;/* Referenced by: '<S1486>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOn;/* Referenced by: '<S1461>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToCoolDvtDiff;/* Referenced by: '<S1649>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToCoolEvapTemp;/* Referenced by: '<S1652>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToEvpEvapTemp;/* Referenced by: '<S1670>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCoolEnvTempHigh;/* Referenced by:
                                                                 * '<S1639>/Constant'
                                                                 * '<S1639>/Constant2'
                                                                 * '<S1639>/Constant9'
                                                                 * '<S1660>/Constant10'
                                                                 * '<S1661>/Constant2'
                                                                 * '<S1661>/Constant3'
                                                                 */
extern CALDATA const volatile float32 cal_tCabinCoolEnvTempLow;/* Referenced by:
                                                                * '<S1639>/Constant1'
                                                                * '<S1639>/Constant3'
                                                                * '<S1639>/Constant5'
                                                                * '<S1644>/Constant1'
                                                                * '<S1644>/Constant5'
                                                                * '<S1671>/Constant'
                                                                * '<S1659>/Constant1'
                                                                * '<S1661>/Constant5'
                                                                * '<S1662>/Constant13'
                                                                * '<S1663>/Constant11'
                                                                * '<S1674>/Constant5'
                                                                * '<S1675>/Constant13'
                                                                */
extern CALDATA const volatile float32 cal_tCabinCoolToCondDvtDiff;/* Referenced by: '<S1653>/Constant' */
extern CALDATA const volatile float32 cal_tCabinEvpToCondDvtDiff;/* Referenced by:
                                                                  * '<S1666>/Constant'
                                                                  * '<S1667>/Constant'
                                                                  */
extern CALDATA const volatile float32 cal_tCabinHPToEvpEnvTemp;/* Referenced by: '<S1679>/Constant' */
extern CALDATA const volatile float32 cal_tDCBatCoolCellTempOn;/* Referenced by: '<S1363>/Constant' */
extern CALDATA const volatile float32 cal_tLTROffBatBal2ToMaxCellDiff;/* Referenced by:
                                                                      * '<S1430>/Constant'
                                                                      * '<S1530>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tLTROffIPUTemp;/* Referenced by: '<S1425>/Constant' */
extern CALDATA const volatile float32 cal_tLTROnDCChrgMaxCellTemp;/* Referenced by:
                                                                   * '<S1417>/Constant'
                                                                   * '<S1419>/Constant'
                                                                   * '<S1519>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tLTROnDCChrgMinCellTemp;/* Referenced by:
                                                                   * '<S1420>/Constant'
                                                                   * '<S1520>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tLTROnIPUTemp;/* Referenced by:
                                                         * '<S1412>/Constant'
                                                         * '<S1513>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_tLTROnMaxCellToMotDiff;/* Referenced by:
                                                                  * '<S1421>/Constant'
                                                                  * '<S1521>/Constant'
                                                                  * '<S1522>/Constant'
                                                                  */
extern CALDATA const volatile float32 cal_tLTROnMotTemp;/* Referenced by:
                                                         * '<S1627>/Constant'
                                                         * '<S1628>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_tLeftSetPointData;/* Referenced by: '<S1128>/Constant' */
extern CALDATA const volatile boolean cal_tLeftSetPointEnb;/* Referenced by: '<S1128>/Constant1' */
extern CALDATA const volatile float32 cal_tMotHeatBatACChrgMinCellTempLow;/* Referenced by:
                                                                      * '<S1557>/Constant'
                                                                      * '<S1578>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatBatMinCellTempLow;/* Referenced by:
                                                                     * '<S1562>/Constant'
                                                                     * '<S1582>/Constant'
                                                                     */
extern CALDATA const volatile float32 cal_tMotHeatExitMinCellToBal1Diff;/* Referenced by:
                                                                      * '<S1538>/Constant1'
                                                                      * '<S1574>/Constant1'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatExitMinCellToMotTempDiff;/* Referenced by:
                                                                      * '<S1538>/Constant2'
                                                                      * '<S1574>/Constant2'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatOnMotToMinCellDiff;/* Referenced by:
                                                                      * '<S1536>/Constant1'
                                                                      * '<S1537>/Constant1'
                                                                      * '<S1572>/Constant1'
                                                                      * '<S1573>/Constant1'
                                                                      */
extern CALDATA const volatile float32 cal_tMotStorExitMaxCellTemp;/* Referenced by:
                                                                   * '<S1550>/Constant'
                                                                   * '<S1568>/Constant'
                                                                   * '<S1592>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tMotStorExitMotToMinCellDiff;/* Referenced by: '<S1535>/Constant3' */
extern CALDATA const volatile float32 cal_tMotStorMinCellTempLow;/* Referenced by: '<S1548>/Constant' */
extern CALDATA const volatile float32 cal_tMotStorOnMotToMinCellDiff;/* Referenced by: '<S1535>/Constant1' */
extern CALDATA const volatile uint16 cal_tiAQSFresh2RecircDelay;/* Referenced by: '<S124>/Constant5' */
extern CALDATA const volatile uint16 cal_tiAQSRecirc2FreshDelay;/* Referenced by: '<S124>/Constant11' */
extern CALDATA const volatile uint16 cal_tiCO2Fresh2RecircMax;/* Referenced by: '<S125>/Constant12' */
extern CALDATA const volatile uint16 cal_tiCO2Recirc2FreshMax;/* Referenced by: '<S125>/Constant5' */
extern CALDATA const volatile uint16 cal_tiColdStartTimeMax;/* Referenced by: '<S36>/Constant2' */

#endif                                 /* RTW_HEADER_TMS_CalibrationData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
