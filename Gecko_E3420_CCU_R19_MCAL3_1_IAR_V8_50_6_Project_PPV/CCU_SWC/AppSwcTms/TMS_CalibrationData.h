/*
 * File: TMS_CalibrationData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2326
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov 14 16:10:51 2024
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
extern CALDATA const volatile uint8 ACDefog;/* Referenced by: '<S390>/Constant7' */
extern CALDATA const volatile uint8 ACOff;/* Referenced by:
                                           * '<S4>/Constant2'
                                           * '<S43>/Constant1'
                                           * '<S43>/Constant5'
                                           * '<S44>/Constant'
                                           * '<S45>/Constant'
                                           * '<S46>/Constant'
                                           * '<S179>/Constant'
                                           * '<S390>/Constant3'
                                           * '<S390>/Constant5'
                                           * '<S95>/Constant'
                                           * '<S127>/Constant'
                                           * '<S134>/Constant1'
                                           * '<S138>/Constant'
                                           * '<S231>/Constant'
                                           */
extern CALDATA const volatile uint8 AC_ColdStart;/* Referenced by: '<S52>/ColdStart' */
extern CALDATA const volatile uint8 AC_HotStart;/* Referenced by:
                                                 * '<S52>/HotStart'
                                                 * '<S53>/HotStart'
                                                 * '<S128>/Constant26'
                                                 */
extern CALDATA const volatile uint8 AC_LittleColdStart;/* Referenced by: '<S52>/ColdStart6' */
extern CALDATA const volatile uint8 BlowerACMode;
                                     /* Referenced by: '<S82>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerBILevelMode;
                                     /* Referenced by: '<S82>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerDefrostMode;
                                     /* Referenced by: '<S82>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerHeaterDefrostMode;
                                     /* Referenced by: '<S82>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerHeaterMode;
                                     /* Referenced by: '<S82>/AutoBlowerMode' */
extern CALDATA const volatile uint8 DriveFRESH;/* Referenced by:
                                                * '<S123>/Constant2'
                                                * '<S123>/Constant3'
                                                * '<S147>/Constant2'
                                                * '<S147>/Constant3'
                                                */
extern CALDATA const volatile uint8 RECIRC;/* Referenced by:
                                            * '<S123>/Constant4'
                                            * '<S147>/Constant4'
                                            */
extern CALDATA const volatile float32 cal_ACBatHeatEnvTemp[2];/* Referenced by: '<S1509>/Constant1' */
extern CALDATA const volatile float32 cal_ACBatHeatT1[3];/* Referenced by: '<S1509>/Constant2' */
extern CALDATA const volatile float32 cal_ACBatHeatT2[3];/* Referenced by: '<S1509>/Constant3' */
extern CALDATA const volatile float32 cal_ACBatHeatTave[3];/* Referenced by: '<S1509>/Constant' */
extern CALDATA const volatile float32 cal_ACBatHeatTrgTemp;/* Referenced by:
                                                            * '<S650>/Constant5'
                                                            * '<S1509>/Constant4'
                                                            */
extern CALDATA const volatile float32 cal_ACCMClsEnvTemp;/* Referenced by: '<S446>/Relay' */
extern CALDATA const volatile float32 cal_ACCMCtlDownlmt;/* Referenced by: '<S569>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtlKiDeadzoneNeg;/* Referenced by: '<S450>/Constant9' */
extern CALDATA const volatile float32 cal_ACCMCtlKiDeadzonePos;/* Referenced by: '<S450>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtlKpDeadzoneNeg;/* Referenced by: '<S450>/Constant10' */
extern CALDATA const volatile float32 cal_ACCMCtlKpDeadzonePos;/* Referenced by: '<S450>/Constant11' */
extern CALDATA const volatile float32 cal_ACCMCtlPID_IsumMax;/* Referenced by: '<S450>/Constant13' */
extern CALDATA const volatile float32 cal_ACCMCtlPID_IsumMin;/* Referenced by: '<S450>/Constant12' */
extern CALDATA const volatile float32 cal_ACCMCtlUplmt;/* Referenced by: '<S569>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlA1FF_1X[6];
                              /* Referenced by: '<S584>/cal_ACCMCtrlA1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlA1FF_CUR[6];
                              /* Referenced by: '<S584>/cal_ACCMCtrlA1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_2X[6];
                             /* Referenced by: '<S584>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_2Y[5];
                             /* Referenced by: '<S584>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_MAP[30];
                             /* Referenced by: '<S584>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlACct;/* Referenced by:
                                                        * '<S584>/Constant2'
                                                        * '<S586>/Constant2'
                                                        * '<S587>/Constant2'
                                                        * '<S588>/Constant2'
                                                        * '<S589>/Constant2'
                                                        */
extern CALDATA const volatile float32 cal_ACCMCtrlADeadzone;/* Referenced by: '<S584>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlADlyTime;/* Referenced by: '<S584>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKi_1X[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKi_CUR[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKp_1X[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKp_CUR[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAPIMax;/* Referenced by: '<S584>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlAPIMin;/* Referenced by: '<S584>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlARunTime;/* Referenced by: '<S584>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlBDeadzone;/* Referenced by: '<S585>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlBDlyTime;/* Referenced by: '<S585>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlBFF_1X[6];
                              /* Referenced by: '<S585>/cal_ACCMCtrlB1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBFF_CUR[6];
                              /* Referenced by: '<S585>/cal_ACCMCtrlB1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKi_1X[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKi_CUR[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKp_1X[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKp_CUR[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBPIMax;/* Referenced by: '<S585>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlBPIMin;/* Referenced by: '<S585>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlBRunTime;/* Referenced by: '<S585>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlC1FF_1X[5];
                              /* Referenced by: '<S586>/cal_ACCMCtrlC1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC1FF_CUR[5];
                              /* Referenced by: '<S586>/cal_ACCMCtrlC1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC2FF_1X[4];
                              /* Referenced by: '<S586>/cal_ACCMCtrlC2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC2FF_CUR[4];
                              /* Referenced by: '<S586>/cal_ACCMCtrlC2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCDeadzone;/* Referenced by: '<S586>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlCDlyTime;/* Referenced by: '<S586>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKi_1X[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKi_CUR[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKp_1X[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKp_CUR[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCPIMax;/* Referenced by: '<S586>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlCPIMin;/* Referenced by: '<S586>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlCRunTime;/* Referenced by: '<S586>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlD1FF_1X[3];
                              /* Referenced by: '<S587>/cal_ACCMCtrlD1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD1FF_CUR[3];
                              /* Referenced by: '<S587>/cal_ACCMCtrlD1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD2FF_1X[4];
                              /* Referenced by: '<S587>/cal_ACCMCtrlD2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD2FF_CUR[4];
                              /* Referenced by: '<S587>/cal_ACCMCtrlD2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDDeadzone;/* Referenced by: '<S587>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlDDlyTime;/* Referenced by: '<S587>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKi_1X[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKi_CUR[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKp_1X[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKp_CUR[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMax_1X[5];
                            /* Referenced by: '<S587>/cal_ACCMCtrlDPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMax_CUR[5];
                            /* Referenced by: '<S587>/cal_ACCMCtrlDPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMin;/* Referenced by: '<S587>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlDRunTime;/* Referenced by: '<S587>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlDTrg_1X[7];
                              /* Referenced by: '<S587>/cal_ACCMCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDTrg_CUR[7];
                              /* Referenced by: '<S587>/cal_ACCMCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE1FF_1X[7];
                              /* Referenced by: '<S588>/cal_ACCMCtrlE1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE1FF_CUR[7];
                              /* Referenced by: '<S588>/cal_ACCMCtrlE1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE2FF_1X[4];
                              /* Referenced by: '<S588>/cal_ACCMCtrlE2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE2FF_CUR[4];
                              /* Referenced by: '<S588>/cal_ACCMCtrlE2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEDeadzone;/* Referenced by: '<S588>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlEDlyTime;/* Referenced by: '<S588>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKi_1X[8];
                               /* Referenced by: '<S588>/cal_ACCMCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKi_CUR[8];
                               /* Referenced by: '<S588>/cal_ACCMCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKp_1X[8];
                               /* Referenced by: '<S588>/cal_ACCMCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKp_CUR[8];
                               /* Referenced by: '<S588>/cal_ACCMCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEPIMax;/* Referenced by: '<S588>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlEPIMin;/* Referenced by: '<S588>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlERunTime;/* Referenced by: '<S588>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlETrgTemp;/* Referenced by:
                                                            * '<S588>/Constant4'
                                                            * '<S588>/Constant6'
                                                            */
extern CALDATA const volatile float32 cal_ACCMCtrlF1FF_1X[5];
                              /* Referenced by: '<S589>/cal_ACCMCtrlF1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF1FF_CUR[5];
                              /* Referenced by: '<S589>/cal_ACCMCtrlF1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF2FF_1X[5];
                              /* Referenced by: '<S589>/cal_ACCMCtrlF2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF2FF_CUR[5];
                              /* Referenced by: '<S589>/cal_ACCMCtrlF2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFDeadzone;/* Referenced by: '<S589>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlFDlyTime;/* Referenced by: '<S589>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKi_1X[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlFKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKi_CUR[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlFKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKp_1X[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlFKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKp_CUR[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlFKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMax_1X[5];
                            /* Referenced by: '<S589>/cal_ACCMCtrlFPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMax_CUR[5];
                            /* Referenced by: '<S589>/cal_ACCMCtrlFPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMin;/* Referenced by: '<S589>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlFRunTime;/* Referenced by: '<S589>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlH1FF_1X[5];
                              /* Referenced by: '<S591>/cal_ACCMCtrlH1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH1FF_CUR[5];
                              /* Referenced by: '<S591>/cal_ACCMCtrlH1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH2FF_1X[4];
                              /* Referenced by: '<S591>/cal_ACCMCtrlH2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH2FF_CUR[4];
                              /* Referenced by: '<S591>/cal_ACCMCtrlH2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHCct;/* Referenced by: '<S591>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlHDeadzone;/* Referenced by: '<S591>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlHDlyTime;/* Referenced by: '<S591>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKi_1X[8];
                               /* Referenced by: '<S591>/cal_ACCMCtrlHKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKi_CUR[8];
                               /* Referenced by: '<S591>/cal_ACCMCtrlHKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKp_1X[8];
                               /* Referenced by: '<S591>/cal_ACCMCtrlHKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKp_CUR[8];
                               /* Referenced by: '<S591>/cal_ACCMCtrlHKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHPIMax;/* Referenced by: '<S591>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlHPIMin;/* Referenced by: '<S591>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlHRunTime;/* Referenced by: '<S591>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlKi;/* Referenced by: '<S450>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlKp;/* Referenced by: '<S450>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlSpdData;/* Referenced by: '<S570>/Constant' */
extern CALDATA const volatile boolean cal_ACCMCtrlSpdDataEnb;/* Referenced by: '<S570>/Constant1' */
extern CALDATA const volatile boolean cal_ACCMEnbData;/* Referenced by: '<S462>/Constant' */
extern CALDATA const volatile boolean cal_ACCMEnbDataEnb;/* Referenced by: '<S462>/Constant1' */
extern CALDATA const volatile boolean cal_ACCMForbidCtrl;/* Referenced by:
                                                          * '<S442>/Constant'
                                                          * '<S956>/Constant3'
                                                          * '<S1659>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_ACCMHiTempData;/* Referenced by: '<S1858>/Constant' */
extern CALDATA const volatile boolean cal_ACCMHiTempDataEnb;/* Referenced by: '<S1858>/Constant1' */
extern CALDATA const volatile uint8 cal_ACCMHiTempFanCtrl;/* Referenced by: '<S926>/Constant5' */
extern CALDATA const volatile float32 cal_ACCMHiTempFanOff;/* Referenced by: '<S926>/Relay' */
extern CALDATA const volatile float32 cal_ACCMHiTempFanOn;/* Referenced by: '<S926>/Relay' */
extern CALDATA const volatile uint16 cal_ACCMHighTempVolAmend_1X[2];
                     /* Referenced by: '<S1731>/cal_ACCMHighTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ACCMHighTempVolAmend_CUR[2];
                     /* Referenced by: '<S1731>/cal_ACCMHighTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ACCMOpenEnvTemp;/* Referenced by: '<S446>/Relay' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2X[12];
                     /* Referenced by: '<S187>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2Y[12];
                     /* Referenced by: '<S187>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_MAP[144];
                     /* Referenced by: '<S187>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2X[12];
                        /* Referenced by: '<S187>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2Y[12];
                        /* Referenced by: '<S187>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_MAP[144];
                        /* Referenced by: '<S187>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACChgBatHighSOCHeat;/* Referenced by:
                                                               * '<S1463>/Relay'
                                                               * '<S1490>/Relay'
                                                               * '<S1628>/Constant'
                                                               * '<S1635>/Constant'
                                                               * '<S1637>/Constant'
                                                               * '<S1639>/Constant'
                                                               */
extern CALDATA const volatile float32 cal_ACChgBatLowSOCHeat;/* Referenced by:
                                                              * '<S1463>/Relay'
                                                              * '<S1490>/Relay'
                                                              * '<S1374>/Constant'
                                                              * '<S1359>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_1X[7];
                     /* Referenced by: '<S1514>/cal_ACChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_CUR[7];
                     /* Referenced by: '<S1514>/cal_ACChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForACHotStart;/* Referenced by:
                                                                    * '<S48>/Kp11'
                                                                    * '<S166>/Constant'
                                                                    */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForAQS;/* Referenced by:
                                                             * '<S48>/Kp4'
                                                             * '<S170>/Constant'
                                                             */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForForceChange;/* Referenced by:
                                                                     * '<S48>/Kp3'
                                                                     * '<S130>/Constant11'
                                                                     * '<S130>/Constant9'
                                                                     * '<S164>/Constant'
                                                                     */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForForceDefog;/* Referenced by:
                                                                    * '<S48>/Kp12'
                                                                    * '<S172>/Constant'
                                                                    */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForManual;/* Referenced by:
                                                                * '<S48>/Kp1'
                                                                * '<S173>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForNormalDefog;/* Referenced by:
                                                                     * '<S48>/Kp5'
                                                                     * '<S161>/Constant2'
                                                                     */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForPCUTemp;/* Referenced by:
                                                                 * '<S48>/Kp15'
                                                                 * '<S171>/Constant'
                                                                 */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForPTCDvt;/* Referenced by:
                                                                * '<S48>/Kp10'
                                                                * '<S162>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForQkChargeCooling;/* Referenced by:
                                                                      * '<S48>/Kp14'
                                                                      * '<S163>/Constant'
                                                                      */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForRemoteAC;/* Referenced by:
                                                                  * '<S48>/Kp13'
                                                                  * '<S165>/Constant'
                                                                  */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForSummer;/* Referenced by:
                                                                * '<S48>/Kp8'
                                                                * '<S161>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForTargetOutTemp;/* Referenced by:
                                                                      * '<S48>/Kp6'
                                                                      * '<S167>/Constant'
                                                                      */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForTempLow;/* Referenced by:
                                                                 * '<S48>/Kp2'
                                                                 * '<S169>/Constant'
                                                                 */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForVent;/* Referenced by:
                                                              * '<S48>/Kp7'
                                                              * '<S168>/Constant'
                                                              */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForWinter;/* Referenced by:
                                                                * '<S48>/Kp9'
                                                                * '<S161>/Constant1'
                                                                */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2X[10];
                          /* Referenced by: '<S187>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2Y[10];
                          /* Referenced by: '<S187>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_MAP[100];
                          /* Referenced by: '<S187>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_1X[16];
                         /* Referenced by: '<S187>/cal_ACDVTPreSetEnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_CUR[16];
                         /* Referenced by: '<S187>/cal_ACDVTPreSetEnvCor_CUR' */
extern CALDATA const volatile uint16 cal_ACDVTPreSetSolarCorByVx_2X[6];
                   /* Referenced by: '<S187>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_2Y[6];
                   /* Referenced by: '<S187>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_MAP[36];
                   /* Referenced by: '<S187>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile uint16 cal_ACDVTPreSetSolarCor_2X[8];
                       /* Referenced by: '<S187>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_2Y[8];
                       /* Referenced by: '<S187>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_MAP[64];
                       /* Referenced by: '<S187>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile uint16 cal_ACDrDVTSolarCor_2X[15];
                           /* Referenced by: '<S183>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDrDVTSolarCor_2Y[15];
                           /* Referenced by: '<S183>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDrDVTSolarCor_MAP[225];
                           /* Referenced by: '<S183>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanLevel0EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel0EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel0EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel0EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel1EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel1EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel1EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel1EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel2EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel2EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel2EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel2EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel3EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel3EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel3EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel3EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel4EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel4EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel4EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel4EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel5EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel5EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel5EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel5EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel6EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel6EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel6EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel6EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel7EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel7EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel7EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel7EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel8EnvCor_1X[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel8EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel8EnvCor_CUR[2];
                          /* Referenced by: '<S54>/cal_ACFanLevel8EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanMaxSpdCellTempLim_1X[5];
                         /* Referenced by: '<S52>/cal_ACFanMaxSpdCellTempLim' */
extern CALDATA const volatile uint8 cal_ACFanMaxSpdCellTempLim_CUR[5];
                         /* Referenced by: '<S52>/cal_ACFanMaxSpdCellTempLim' */
extern CALDATA const volatile float32 cal_ACFanMaxSpdDvtLim_1X[5];
                          /* Referenced by: '<S52>/cal_ACFanMaxSpdDvtLim_CUR' */
extern CALDATA const volatile uint8 cal_ACFanMaxSpdDvtLim_CUR[5];
                          /* Referenced by: '<S52>/cal_ACFanMaxSpdDvtLim_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdBatCor_1X[3];
                             /* Referenced by: '<S58>/cal_ACFanSpdBatCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdBatCor_CUR[3];
                             /* Referenced by: '<S58>/cal_ACFanSpdBatCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdDvtSet_1X[14];
                            /* Referenced by: '<S58>/cal_ACFanSpdDvtSet_CUR ' */
extern CALDATA const volatile float32 cal_ACFanSpdDvtSet_CUR[14];
                            /* Referenced by: '<S58>/cal_ACFanSpdDvtSet_CUR ' */
extern CALDATA const volatile float32 cal_ACFanSpdRecircCor_1X[4];
                          /* Referenced by: '<S58>/cal_ACFanSpdRecircCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdRecircCor_CUR[4];
                          /* Referenced by: '<S58>/cal_ACFanSpdRecircCor_CUR' */
extern CALDATA const volatile uint16 cal_ACFanSpdSolarCorByEnv_2X[15];
                      /* Referenced by: '<S58>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_2Y[15];
                      /* Referenced by: '<S58>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_MAP[225];
                      /* Referenced by: '<S58>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACFanSpdSolarCor_2X[15];
                           /* Referenced by: '<S58>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCor_2Y[15];
                           /* Referenced by: '<S58>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCor_MAP[225];
                           /* Referenced by: '<S58>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdVssCor_1X[3];
                             /* Referenced by: '<S58>/cal_ACFanSpdVssCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdVssCor_CUR[3];
                             /* Referenced by: '<S58>/cal_ACFanSpdVssCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletAutoDefogPrtEnvCor_1X[10];
                 /* Referenced by: '<S142>/cal_ACInletAutoDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletAutoDefogPrtEnvCor_CUR[10];
                 /* Referenced by: '<S142>/cal_ACInletAutoDefogPrtEnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletDefogPrtEnvCor_1X[10];
                     /* Referenced by: '<S142>/cal_ACInletDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogPrtEnvCor_CUR[10];
                     /* Referenced by: '<S142>/cal_ACInletDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogRiskCor_1X[2];
                       /* Referenced by: '<S142>/cal_ACInletDefogRiskCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogRiskCor_CUR[2];
                       /* Referenced by: '<S142>/cal_ACInletDefogRiskCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletEnvPrtSetCool_1X[5];
                      /* Referenced by: '<S125>/cal_ACInletEnvPrtSetCool_CUR' */
extern CALDATA const volatile uint8 cal_ACInletEnvPrtSetCool_CUR[5];
                      /* Referenced by: '<S125>/cal_ACInletEnvPrtSetCool_CUR' */
extern CALDATA const volatile float32 cal_ACInletEnvPrtSetHeat_1X[5];
                      /* Referenced by: '<S125>/cal_ACInletEnvPrtSetHeat_CUR' */
extern CALDATA const volatile uint8 cal_ACInletEnvPrtSetHeat_CUR[5];
                      /* Referenced by: '<S125>/cal_ACInletEnvPrtSetHeat_CUR' */
extern CALDATA const volatile uint8 cal_ACPMPSpdDiffVal;/* Referenced by: '<S1031>/Constant' */
extern CALDATA const volatile float32 cal_ACPTCDesBacAC_1X[12];
                             /* Referenced by: '<S343>/cal_ACPTCDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacAC_CUR[12];
                             /* Referenced by: '<S343>/cal_ACPTCDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacBi_1X[12];
                             /* Referenced by: '<S343>/cal_ACPTCDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacBi_CUR[12];
                             /* Referenced by: '<S343>/cal_ACPTCDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacDefog_1X[12];
                          /* Referenced by: '<S343>/cal_ACPTCDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacDefog_CUR[12];
                          /* Referenced by: '<S343>/cal_ACPTCDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFootDe_1X[12];
                         /* Referenced by: '<S343>/cal_ACPTCDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFootDe_CUR[12];
                         /* Referenced by: '<S343>/cal_ACPTCDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFoot_1X[12];
                           /* Referenced by: '<S343>/cal_ACPTCDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFoot_CUR[12];
                           /* Referenced by: '<S343>/cal_ACPTCDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesCabinCor_1X[8];
                          /* Referenced by: '<S343>/cal_ACPTCDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesCabinCor_CUR[8];
                          /* Referenced by: '<S343>/cal_ACPTCDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_2X[6];
                            /* Referenced by: '<S343>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_2Y[6];
                            /* Referenced by: '<S343>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_MAP[36];
                            /* Referenced by: '<S343>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPTCDesFanCor_1X[4];
                            /* Referenced by: '<S343>/cal_ACPTCDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesFanCor_CUR[4];
                            /* Referenced by: '<S343>/cal_ACPTCDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacAC_1X[12];
                           /* Referenced by: '<S365>/cal_ACPTCPsDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacAC_CUR[12];
                           /* Referenced by: '<S365>/cal_ACPTCPsDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacBi_1X[12];
                           /* Referenced by: '<S365>/cal_ACPTCPsDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacBi_CUR[12];
                           /* Referenced by: '<S365>/cal_ACPTCPsDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_1X[12];
                        /* Referenced by: '<S365>/cal_ACPTCPsDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_CUR[12];
                        /* Referenced by: '<S365>/cal_ACPTCPsDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_1X[12];
                       /* Referenced by: '<S365>/cal_ACPTCPsDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_CUR[12];
                       /* Referenced by: '<S365>/cal_ACPTCPsDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_1X[12];
                         /* Referenced by: '<S365>/cal_ACPTCPsDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_CUR[12];
                         /* Referenced by: '<S365>/cal_ACPTCPsDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_1X[8];
                        /* Referenced by: '<S365>/cal_ACPTCPsDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_CUR[8];
                        /* Referenced by: '<S365>/cal_ACPTCPsDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2X[6];
                          /* Referenced by: '<S365>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2Y[6];
                          /* Referenced by: '<S365>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_MAP[36];
                          /* Referenced by: '<S365>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPTCPsDesFanCor_1X[4];
                          /* Referenced by: '<S365>/cal_ACPTCPsDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesFanCor_CUR[4];
                          /* Referenced by: '<S365>/cal_ACPTCPsDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPwrPreSetByEnv_2X[10];
                        /* Referenced by: '<S96>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPwrPreSetByEnv_2Y[10];
                        /* Referenced by: '<S96>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACPTCPwrPreSetByEnv_MAP[100];
                        /* Referenced by: '<S96>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2X[14];
                        /* Referenced by: '<S184>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2Y[14];
                        /* Referenced by: '<S184>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_MAP[196];
                        /* Referenced by: '<S184>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACPsDVTSolarCor_2X[15];
                           /* Referenced by: '<S184>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSolarCor_2Y[15];
                           /* Referenced by: '<S184>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSolarCor_MAP[225];
                           /* Referenced by: '<S184>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPumpBatHeatSpd;/* Referenced by:
                                                          * '<S1031>/Constant18'
                                                          * '<S1031>/Constant6'
                                                          */
extern CALDATA const volatile uint8 cal_ACPumpCtrlASpd;/* Referenced by: '<S1031>/Constant1' */
extern CALDATA const volatile uint8 cal_ACPumpDefSpd;/* Referenced by:
                                                      * '<S1031>/Constant17'
                                                      * '<S1031>/Constant2'
                                                      */
extern CALDATA const volatile uint8 cal_ACPumpDehSpd;/* Referenced by: '<S1031>/Constant8' */
extern CALDATA const volatile uint8 cal_ACPumpDoubleHeatSpd;/* Referenced by: '<S1031>/Constant7' */
extern CALDATA const volatile uint8 cal_ACRecirRatioLmt;/* Referenced by:
                                                         * '<S284>/Constant2'
                                                         * '<S309>/Constant2'
                                                         * '<S343>/Constant2'
                                                         * '<S365>/Constant2'
                                                         * '<S58>/Constant2'
                                                         */
extern CALDATA const volatile float32 cal_ADCVCCVal;/* Referenced by:
                                                     * '<S1715>/Constant2'
                                                     * '<S1719>/Constant1'
                                                     * '<S1720>/Constant1'
                                                     * '<S1723>/Constant1'
                                                     * '<S1724>/Constant2'
                                                     * '<S1725>/Constant1'
                                                     * '<S1726>/Constant1'
                                                     * '<S1727>/Constant1'
                                                     * '<S1728>/Constant1'
                                                     * '<S1729>/Constant1'
                                                     * '<S1731>/Constant1'
                                                     */
extern CALDATA const volatile float32 cal_AEXVClsEvapPrtTemp;
                                   /* Referenced by: '<S692>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVClsValEvapPrt;/* Referenced by:
                                                             * '<S692>/EvapTemperature'
                                                             * '<S692>/Constant3'
                                                             */
extern CALDATA const volatile float32 cal_AEXVClsValRunTimeEvapPrt;
                                   /* Referenced by: '<S692>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVCtlKi;/* Referenced by: '<S689>/Constant11' */
extern CALDATA const volatile float32 cal_AEXVCtlKisumMax;/* Referenced by: '<S689>/Constant8' */
extern CALDATA const volatile float32 cal_AEXVCtlKisumMin;/* Referenced by: '<S689>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVCtlKp;/* Referenced by: '<S689>/Constant10' */
extern CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_1X[6];
                   /* Referenced by: '<S724>/cal_AEXVCtrlBCabinCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_CUR[6];
                   /* Referenced by: '<S724>/cal_AEXVCtrlBCabinCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_1X[6];
                       /* Referenced by: '<S724>/cal_AEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_CUR[6];
                       /* Referenced by: '<S724>/cal_AEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDeadzone;/* Referenced by: '<S724>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDelayTime;/* Referenced by: '<S724>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlBFF_1X[5];
                               /* Referenced by: '<S724>/cal_AEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBFF_CUR[5];
                               /* Referenced by: '<S724>/cal_AEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKi_1X[8];
                               /* Referenced by: '<S724>/cal_AEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKi_CUR[8];
                               /* Referenced by: '<S724>/cal_AEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKp_1X[8];
                               /* Referenced by: '<S724>/cal_AEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKp_CUR[8];
                               /* Referenced by: '<S724>/cal_AEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBOpenVal;/* Referenced by: '<S724>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlBPIMax;/* Referenced by: '<S724>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlBPIMin;/* Referenced by: '<S724>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_1X[9];
                /* Referenced by: '<S724>/cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR[9];
                /* Referenced by: '<S724>/cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_1X[9];
                       /* Referenced by: '<S724>/cal_AEXVCtrlBTrgSubCool_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_CUR[9];
                       /* Referenced by: '<S724>/cal_AEXVCtrlBTrgSubCool_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCDeadzone;/* Referenced by: '<S725>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlCDelayTime;/* Referenced by: '<S725>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlCFF_1X[5];
                               /* Referenced by: '<S725>/cal_AEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCFF_CUR[5];
                               /* Referenced by: '<S725>/cal_AEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKi_1X[7];
                               /* Referenced by: '<S725>/cal_AEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKi_CUR[7];
                               /* Referenced by: '<S725>/cal_AEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKp_1X[7];
                               /* Referenced by: '<S725>/cal_AEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKp_CUR[7];
                               /* Referenced by: '<S725>/cal_AEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCOpenVal;/* Referenced by: '<S725>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlCPIMax;/* Referenced by: '<S725>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlCPIMin;/* Referenced by: '<S725>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgflt;/* Referenced by: '<S725>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_1X[7];
                    /* Referenced by: '<S725>/cal_AEXVCtrlCTrgtSuperHeat_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_CUR[7];
                    /* Referenced by: '<S725>/cal_AEXVCtrlCTrgtSuperHeat_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDDeadzone;/* Referenced by: '<S726>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlDDelayTime;/* Referenced by: '<S726>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlDFF_1X[5];
                               /* Referenced by: '<S726>/cal_AEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDFF_CUR[5];
                               /* Referenced by: '<S726>/cal_AEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKi_1X[8];
                               /* Referenced by: '<S726>/cal_AEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKi_CUR[8];
                               /* Referenced by: '<S726>/cal_AEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKp_1X[8];
                               /* Referenced by: '<S726>/cal_AEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKp_CUR[8];
                               /* Referenced by: '<S726>/cal_AEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDOpenVal;/* Referenced by: '<S726>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlDPIMax;/* Referenced by: '<S726>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlDPIMin;/* Referenced by: '<S726>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlDTrg_1X[3];
                              /* Referenced by: '<S726>/cal_AEXVCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDTrg_CUR[3];
                              /* Referenced by: '<S726>/cal_AEXVCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDefaultPos;/* Referenced by: '<S727>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVDiffDown;/* Referenced by: '<S748>/Constant8' */
extern CALDATA const volatile float32 cal_AEXVDiffDownRate;/* Referenced by: '<S748>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVDiffUp;/* Referenced by: '<S748>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVDiffUpRate;/* Referenced by: '<S748>/Constant5' */
extern CALDATA const volatile float32 cal_AEXVDownSpdLmt;/* Referenced by:
                                                          * '<S753>/DownLmt'
                                                          * '<S753>/DownLmt1'
                                                          */
extern CALDATA const volatile boolean cal_AEXVEnbData;/* Referenced by: '<S695>/Constant' */
extern CALDATA const volatile boolean cal_AEXVEnbDataEnb;/* Referenced by: '<S695>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVFloorDiff1;/* Referenced by: '<S751>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVFloorDiff2;/* Referenced by: '<S751>/Constant' */
extern CALDATA const volatile float32 cal_AEXVFltClsSpd;/* Referenced by: '<S692>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVHighPressLmtOn;/* Referenced by: '<S748>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVHighPressProhOn;/* Referenced by: '<S692>/Constant' */
extern CALDATA const volatile uint8 cal_AEXVInitReqData;/* Referenced by: '<S705>/Constant' */
extern CALDATA const volatile boolean cal_AEXVInitReqDataeEnb;/* Referenced by: '<S705>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVLowPressLmtOn;/* Referenced by: '<S748>/Constant4' */
extern CALDATA const volatile float32 cal_AEXVLowPressProhOn;/* Referenced by: '<S692>/Constant2' */
extern CALDATA const volatile float32 cal_AEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                  * '<S754>/DownLmt'
                                                                  * '<S754>/DownLmt1'
                                                                  */
extern CALDATA const volatile float32 cal_AEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                * '<S754>/UpLmt'
                                                                * '<S754>/UpLmt2'
                                                                */
extern CALDATA const volatile float32 cal_AEXVOpenDelayTimeEvapNOPrt;
                                   /* Referenced by: '<S692>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenEvapNOPrtTemp;
                                   /* Referenced by: '<S692>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenRunTimeEvapNOPrt;
                                   /* Referenced by: '<S692>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenValEvapNOPrt;
                                   /* Referenced by: '<S692>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenValveSpd;/* Referenced by: '<S692>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVPosData;/* Referenced by: '<S749>/Constant' */
extern CALDATA const volatile boolean cal_AEXVPosDataEnb;/* Referenced by: '<S749>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVSubCoolflt;/* Referenced by: '<S724>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVUpSpdLmt;/* Referenced by:
                                                        * '<S753>/UpLmt'
                                                        * '<S753>/UpLmt2'
                                                        */
extern CALDATA const volatile uint8 cal_AQS2InRecThreVal;/* Referenced by: '<S129>/Constant3' */
extern CALDATA const volatile uint8 cal_AQS2OutRecThreVal;/* Referenced by: '<S129>/Constant4' */
extern CALDATA const volatile boolean cal_AcPMPFaultFlgData;/* Referenced by: '<S1045>/Constant' */
extern CALDATA const volatile boolean cal_AcPMPFaultFlgDataEnb;/* Referenced by: '<S1045>/Constant1' */
extern CALDATA const volatile uint8 cal_AcPMPSpdSetData;/* Referenced by: '<S1044>/Constant' */
extern CALDATA const volatile boolean cal_AcPMPSpdSetDataEnb;/* Referenced by: '<S1044>/Constant1' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressDownSide_1X[12];
               /* Referenced by: '<S547>/cal_AccmSpdLimByHiPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressDownSide_CUR[12];
               /* Referenced by: '<S547>/cal_AccmSpdLimByHiPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressLevelCalcu_1X[12];
             /* Referenced by: '<S547>/cal_AccmSpdLimByHiPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressLevelCalcu_CUR[12];
             /* Referenced by: '<S547>/cal_AccmSpdLimByHiPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressUpSide_1X[12];
                 /* Referenced by: '<S547>/cal_AccmSpdLimByHiPressUpSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressUpSide_CUR[12];
                 /* Referenced by: '<S547>/cal_AccmSpdLimByHiPressUpSide_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressDownSide_1X[12];
               /* Referenced by: '<S547>/cal_AccmSpdLimByLoPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressDownSide_CUR[12];
               /* Referenced by: '<S547>/cal_AccmSpdLimByLoPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressLevelCalcu_1X[12];
             /* Referenced by: '<S547>/cal_AccmSpdLimByLoPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressLevelCalcu_CUR[12];
             /* Referenced by: '<S547>/cal_AccmSpdLimByLoPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressUpSide_1X[12];
                 /* Referenced by: '<S547>/cal_AccmSpdLimByLoPressUpSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressUpSide_CUR[12];
                 /* Referenced by: '<S547>/cal_AccmSpdLimByLoPressUpSide_CUR' */
extern CALDATA const volatile uint8 cal_AirInletPerData;/* Referenced by: '<S1233>/Constant' */
extern CALDATA const volatile boolean cal_AirInletPerEnb;/* Referenced by: '<S1233>/Constant1' */
extern CALDATA const volatile float32 cal_AirInletRecInPCUTemp;/* Referenced by: '<S133>/Constant6' */
extern CALDATA const volatile float32 cal_AirInletRecOutPCUTemp;/* Referenced by: '<S133>/Constant1' */
extern CALDATA const volatile boolean cal_AutoDefogEnable;/* Referenced by: '<S142>/Constant1' */
extern CALDATA const volatile boolean cal_AvgSwitch;/* Referenced by:
                                                     * '<S685>/Constant1'
                                                     * '<S685>/Constant4'
                                                     * '<S685>/Constant5'
                                                     * '<S685>/Constant6'
                                                     */
extern CALDATA const volatile uint8 cal_BATPMPSpdDiffVal;/* Referenced by: '<S1032>/Constant' */
extern CALDATA const volatile uint8 cal_BCVFltStsDelayTime;/* Referenced by: '<S673>/Constant5' */
extern CALDATA const volatile float32 cal_BCVPosDiffDelayTime;/* Referenced by: '<S673>/Constant2' */
extern CALDATA const volatile float32 cal_BEXVCtlKi;/* Referenced by: '<S759>/Constant11' */
extern CALDATA const volatile float32 cal_BEXVCtlKisumMax;/* Referenced by: '<S759>/Constant8' */
extern CALDATA const volatile float32 cal_BEXVCtlKisumMin;/* Referenced by: '<S759>/Constant9' */
extern CALDATA const volatile float32 cal_BEXVCtlKp;/* Referenced by: '<S759>/Constant10' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_1X[6];
                       /* Referenced by: '<S792>/cal_BEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_CUR[6];
                       /* Referenced by: '<S792>/cal_BEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDeadzone;/* Referenced by: '<S792>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDelayTime;/* Referenced by: '<S792>/Constant' */
extern CALDATA const volatile float32 cal_BEXVCtrlBFF_1X[5];
                               /* Referenced by: '<S792>/cal_BEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBFF_CUR[5];
                               /* Referenced by: '<S792>/cal_BEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKi_1X[7];
                               /* Referenced by: '<S792>/cal_BEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKi_CUR[7];
                               /* Referenced by: '<S792>/cal_BEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKp_1X[7];
                               /* Referenced by: '<S792>/cal_BEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKp_CUR[7];
                               /* Referenced by: '<S792>/cal_BEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBOpenVal;/* Referenced by: '<S792>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVCtrlBPIDown;/* Referenced by: '<S792>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVCtrlBPIUp;/* Referenced by: '<S792>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_1X[5];
                     /* Referenced by: '<S792>/cal_BEXVCtrlBTrgCabinComp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_CUR[5];
                     /* Referenced by: '<S792>/cal_BEXVCtrlBTrgCabinComp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_1X[6];
                   /* Referenced by: '<S792>/cal_BEXVCtrlBTrgWtrTempDiff_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_CUR[6];
                   /* Referenced by: '<S792>/cal_BEXVCtrlBTrgWtrTempDiff_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_1X[6];
                     /* Referenced by: '<S793>/cal_BEXVCtrlCBatCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_CUR[6];
                     /* Referenced by: '<S793>/cal_BEXVCtrlCBatCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCDeadzone;/* Referenced by: '<S793>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVCtrlCDelayTime;/* Referenced by: '<S793>/Constant' */
extern CALDATA const volatile float32 cal_BEXVCtrlCFF_1X[5];
                               /* Referenced by: '<S793>/cal_BEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCFF_CUR[5];
                               /* Referenced by: '<S793>/cal_BEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKi_1X[8];
                               /* Referenced by: '<S793>/cal_BEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKi_CUR[8];
                               /* Referenced by: '<S793>/cal_BEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKp_1X[8];
                               /* Referenced by: '<S793>/cal_BEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKp_CUR[8];
                               /* Referenced by: '<S793>/cal_BEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCOpenVal;/* Referenced by: '<S793>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVCtrlCPIMax;/* Referenced by: '<S793>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVCtrlCPIMin;/* Referenced by: '<S793>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVCtrlCTrg_1X[5];
                              /* Referenced by: '<S793>/cal_BEXVCtrlCTrg_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCTrg_CUR[5];
                              /* Referenced by: '<S793>/cal_BEXVCtrlCTrg_CUR' */
extern CALDATA const volatile float32 cal_BEXVDiffDown;/* Referenced by: '<S818>/Constant8' */
extern CALDATA const volatile float32 cal_BEXVDiffDownRate;/* Referenced by: '<S818>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVDiffUp;/* Referenced by: '<S818>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVDiffUpRate;/* Referenced by: '<S818>/Constant5' */
extern CALDATA const volatile float32 cal_BEXVDownSpdLmt;/* Referenced by:
                                                          * '<S823>/DownLmt'
                                                          * '<S823>/DownLmt1'
                                                          */
extern CALDATA const volatile boolean cal_BEXVEnbData;/* Referenced by: '<S814>/Constant' */
extern CALDATA const volatile boolean cal_BEXVEnbDataEnb;/* Referenced by: '<S814>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVFloorDiff1;/* Referenced by: '<S821>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVFloorDiff2;/* Referenced by: '<S821>/Constant' */
extern CALDATA const volatile float32 cal_BEXVHighPressLmtOn;/* Referenced by: '<S818>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVHighPressProhOn;/* Referenced by: '<S763>/Constant' */
extern CALDATA const volatile uint8 cal_BEXVInitReqData;/* Referenced by: '<S773>/Constant' */
extern CALDATA const volatile boolean cal_BEXVInitReqDataeEnb;/* Referenced by: '<S773>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVLowPressLmtOn;/* Referenced by: '<S818>/Constant4' */
extern CALDATA const volatile float32 cal_BEXVLowPressProhOn;/* Referenced by: '<S763>/Constant2' */
extern CALDATA const volatile float32 cal_BEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                  * '<S824>/DownLmt'
                                                                  * '<S824>/DownLmt1'
                                                                  */
extern CALDATA const volatile float32 cal_BEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                * '<S824>/UpLmt'
                                                                * '<S824>/UpLmt2'
                                                                */
extern CALDATA const volatile float32 cal_BEXVOpenValveSpd;/* Referenced by: '<S763>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVPosData;/* Referenced by: '<S819>/Constant' */
extern CALDATA const volatile boolean cal_BEXVPosDataEnb;/* Referenced by: '<S819>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVSubCoolflt;/* Referenced by: '<S793>/Constant10' */
extern CALDATA const volatile float32 cal_BEXVSubHeatflt;/* Referenced by: '<S792>/Constant12' */
extern CALDATA const volatile float32 cal_BEXVUpSpdLmt;/* Referenced by:
                                                        * '<S823>/UpLmt'
                                                        * '<S823>/UpLmt2'
                                                        */
extern CALDATA const volatile float32 cal_BMSInletTempHighOffMCV;/* Referenced by: '<S643>/Relay' */
extern CALDATA const volatile float32 cal_BMSInletTempLowOnMCV;/* Referenced by: '<S643>/Relay' */
extern CALDATA const volatile float32 cal_BatBalCellTemp1;/* Referenced by:
                                                           * '<S1326>/Constant1'
                                                           * '<S1330>/Constant1'
                                                           * '<S1556>/Constant'
                                                           * '<S1559>/Constant'
                                                           * '<S1594>/Constant'
                                                           * '<S1352>/Constant1'
                                                           * '<S1360>/Constant4'
                                                           * '<S1572>/Constant'
                                                           * '<S1579>/Constant'
                                                           * '<S1584>/Constant'
                                                           * '<S1599>/Constant'
                                                           * '<S1603>/Constant'
                                                           * '<S1633>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatBalCellTemp2;/* Referenced by:
                                                           * '<S1326>/Constant2'
                                                           * '<S1330>/Constant2'
                                                           * '<S1333>/Constant'
                                                           * '<S1444>/Constant'
                                                           * '<S1545>/Constant'
                                                           * '<S1621>/Constant'
                                                           * '<S1630>/Constant4'
                                                           * '<S1631>/Constant4'
                                                           * '<S1633>/Constant4'
                                                           * '<S1356>/Constant4'
                                                           * '<S1439>/Constant'
                                                           * '<S1538>/Constant'
                                                           * '<S1647>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatCoolInletTrgTemp;/* Referenced by:
                                                               * '<S585>/Constant3'
                                                               * '<S591>/Constant5'
                                                               * '<S792>/Constant11'
                                                               */
extern CALDATA const volatile boolean cal_BatCoolOverData;/* Referenced by: '<S1380>/Constant' */
extern CALDATA const volatile boolean cal_BatCoolOverEnb;/* Referenced by: '<S1380>/Constant1' */
extern CALDATA const volatile uint16 cal_BatCoolStopBatPMPRunTime;/* Referenced by: '<S1032>/Constant16' */
extern CALDATA const volatile uint8 cal_BatCoolStopBatPMPSpd;/* Referenced by: '<S1032>/Constant15' */
extern CALDATA const volatile float32 cal_BatCoolTrgFilter;/* Referenced by:
                                                            * '<S585>/Constant5'
                                                            * '<S588>/Constant9'
                                                            */
extern CALDATA const volatile boolean cal_BatHeatACCMEnb;/* Referenced by:
                                                          * '<S464>/Constant1'
                                                          * '<S593>/Constant9'
                                                          */
extern CALDATA const volatile boolean cal_BatHeatOverData;/* Referenced by: '<S1461>/Constant' */
extern CALDATA const volatile boolean cal_BatHeatOverEnb;/* Referenced by: '<S1461>/Constant1' */
extern CALDATA const volatile float32 cal_BatHeatPwrLoLmt;/* Referenced by:
                                                           * '<S1403>/Constant'
                                                           * '<S1486>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatHeatTrgTemp;/* Referenced by: '<S956>/Constant5' */
extern CALDATA const volatile float32 cal_BatHeatTrgTempComp_1X[11];
                       /* Referenced by: '<S1514>/cal_BatHeatTrgTempComp_CUR' */
extern CALDATA const volatile float32 cal_BatHeatTrgTempComp_CUR[11];
                       /* Referenced by: '<S1514>/cal_BatHeatTrgTempComp_CUR' */
extern CALDATA const volatile BatModes cal_BatModeData;/* Referenced by: '<S1456>/Constant' */
extern CALDATA const volatile boolean cal_BatModeEnb;/* Referenced by: '<S1456>/Constant1' */
extern CALDATA const volatile boolean cal_BatModeSwitch;/* Referenced by:
                                                         * '<S34>/Constant1'
                                                         * '<S1304>/Constant'
                                                         */
extern CALDATA const volatile boolean cal_BatModeTestCtrl;/* Referenced by: '<S672>/Constant' */
extern CALDATA const volatile uint8 cal_BatPMPBatHeatSpd;/* Referenced by: '<S1032>/Constant6' */
extern CALDATA const volatile boolean cal_BatPMPFaultFlgData;/* Referenced by: '<S1061>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPFaultFlgDataEnb;/* Referenced by: '<S1061>/Constant1' */
extern CALDATA const volatile uint8 cal_BatPMPSpdSetData;/* Referenced by: '<S1060>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPSpdSetDataEnb;/* Referenced by: '<S1060>/Constant1' */
extern CALDATA const volatile float32 cal_BatPumpBal_1X[4];
                               /* Referenced by: '<S1032>/cal_BatPumpBal_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpBal_CUR[4];
                               /* Referenced by: '<S1032>/cal_BatPumpBal_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpCtrlASpd;/* Referenced by: '<S1032>/Constant1' */
extern CALDATA const volatile uint8 cal_BatPumpMotHeatBatSpd;/* Referenced by: '<S1032>/Constant13' */
extern CALDATA const volatile uint8 cal_BatPumpMotLTRAndBatCHSpd;/* Referenced by: '<S1032>/Constant14' */
extern CALDATA const volatile float32 cal_BatPumpThSto_1X[4];
                             /* Referenced by: '<S1032>/cal_BatPumpThSto_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpThSto_CUR[4];
                             /* Referenced by: '<S1032>/cal_BatPumpThSto_CUR' */
extern CALDATA const volatile float32 cal_BatTrgTempData;/* Referenced by: '<S1323>/Constant' */
extern CALDATA const volatile boolean cal_BatTrgTempEnb;/* Referenced by: '<S1323>/Constant1' */
extern CALDATA const volatile float32 cal_BetwT1AndT2DownMCV_1X[6];
                        /* Referenced by: '<S649>/cal_BetwT1AndT2DownMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2DownMCV_CUR[6];
                        /* Referenced by: '<S649>/cal_BetwT1AndT2DownMCV_CUR' */
extern CALDATA const volatile float32 cal_BetwT1AndT2StbyMCV_1X[6];
                        /* Referenced by: '<S649>/cal_BetwT1AndT2StbyMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2StbyMCV_CUR[6];
                        /* Referenced by: '<S649>/cal_BetwT1AndT2StbyMCV_CUR' */
extern CALDATA const volatile float32 cal_BetwT1AndT2UpMCV_1X[6];
                          /* Referenced by: '<S649>/cal_BetwT1AndT2UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2UpMCV_CUR[6];
                          /* Referenced by: '<S649>/cal_BetwT1AndT2UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_BlowerFanSpdLL;/* Referenced by: '<S53>/Constant14' */
extern CALDATA const volatile uint8 cal_BlowerFanSpdVentUL;/* Referenced by: '<S52>/Constant29' */
extern CALDATA const volatile uint8 cal_BlwFanData;/* Referenced by: '<S1252>/Constant' */
extern CALDATA const volatile boolean cal_BlwFanEnb;/* Referenced by: '<S1252>/Constant1' */
extern CALDATA const volatile uint16 cal_BlwFrqVal;/* Referenced by: '<S1237>/Constant5' */
extern CALDATA const volatile uint8 cal_C3WVExhPosVal;/* Referenced by: '<S643>/Constant7' */
extern CALDATA const volatile uint8 cal_C3WVSLStsData;/* Referenced by: '<S669>/Constant' */
extern CALDATA const volatile boolean cal_C3WVSLStsDataEnb;/* Referenced by: '<S669>/Constant1' */
extern CALDATA const volatile uint8 cal_C5WVExhPosVal;/* Referenced by: '<S672>/Constant11' */
extern CALDATA const volatile uint8 cal_C5WVSLStsData;/* Referenced by: '<S679>/Constant' */
extern CALDATA const volatile boolean cal_C5WVSLStsDataEnb;/* Referenced by: '<S679>/Constant1' */
extern CALDATA const volatile boolean cal_CANAliveEnable;/* Referenced by: '<S2>/Constant' */
extern CALDATA const volatile sint16 cal_CAPStartCoolantMin;
                             /* Referenced by: '<S41>/AirConditionStartState' */
extern CALDATA const volatile uint8 cal_CO2RecircRatio;/* Referenced by: '<S48>/Constant14' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_1X[8];
                      /* Referenced by: '<S547>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_CUR[8];
                      /* Referenced by: '<S547>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_2X[10];
                         /* Referenced by: '<S547>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile uint8 cal_COMPATNoiseSpdLmt_2Y[10];
                         /* Referenced by: '<S547>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_MAP[100];
                         /* Referenced by: '<S547>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile float32 cal_COMPActlSpd1;/* Referenced by: '<S543>/Constant' */
extern CALDATA const volatile float32 cal_COMPActlSpd2;/* Referenced by: '<S544>/Constant' */
extern CALDATA const volatile float32 cal_COMPActlSpd3;/* Referenced by: '<S545>/Constant' */
extern CALDATA const volatile float32 cal_COMPBatMaxSpdLmt;/* Referenced by: '<S548>/Constant2' */
extern CALDATA const volatile float32 cal_COMPCabinCoolMaxSpdLmt;/* Referenced by: '<S548>/Constant3' */
extern CALDATA const volatile float32 cal_COMPClosePwrMaxLmt;/* Referenced by: '<S464>/Relay' */
extern CALDATA const volatile float32 cal_COMPClsLowSpeed;/* Referenced by:
                                                           * '<S564>/Constant'
                                                           * '<S480>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_COMPCoolLowSpd;/* Referenced by:
                                                          * '<S549>/Constant'
                                                          * '<S552>/Constant'
                                                          * '<S556>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt1_1X[2];
                            /* Referenced by: '<S548>/cal_COMPEnvSpdLmt1_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt1_CUR[2];
                            /* Referenced by: '<S548>/cal_COMPEnvSpdLmt1_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt2_1X[2];
                            /* Referenced by: '<S548>/cal_COMPEnvSpdLmt2_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt2_CUR[2];
                            /* Referenced by: '<S548>/cal_COMPEnvSpdLmt2_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt3_1X[2];
                            /* Referenced by: '<S548>/cal_COMPEnvSpdLmt3_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt3_CUR[2];
                            /* Referenced by: '<S548>/cal_COMPEnvSpdLmt3_CUR' */
extern CALDATA const volatile float32 cal_COMPEvapTFrbVal;/* Referenced by: '<S459>/Relay2' */
extern CALDATA const volatile float32 cal_COMPEvapTNmlVal;/* Referenced by: '<S459>/Relay2' */
extern CALDATA const volatile float32 cal_COMPExhTDownSpd;/* Referenced by: '<S572>/Constant1' */
extern CALDATA const volatile float32 cal_COMPExhTFrbVal;/* Referenced by: '<S459>/Relay1' */
extern CALDATA const volatile float32 cal_COMPExhTLmtRlybVal;/* Referenced by: '<S459>/Relay1' */
extern CALDATA const volatile float32 cal_COMPExhTLmtVal;/* Referenced by: '<S459>/Relay' */
extern CALDATA const volatile float32 cal_COMPExhTNmlVal;/* Referenced by: '<S459>/Relay' */
extern CALDATA const volatile uint8 cal_COMPFanLevelLmt_1X[9];
                           /* Referenced by: '<S548>/cal_COMPFanLevelLmt_CUR' */
extern CALDATA const volatile float32 cal_COMPFanLevelLmt_CUR[9];
                           /* Referenced by: '<S548>/cal_COMPFanLevelLmt_CUR' */
extern CALDATA const volatile uint8 cal_COMPFanSpdLmt[3];/* Referenced by: '<S445>/Constant14' */
extern CALDATA const volatile float32 cal_COMPONMinSpd;/* Referenced by: '<S453>/Relay' */
extern CALDATA const volatile float32 cal_COMPOffMaxSpd;/* Referenced by: '<S453>/Relay' */
extern CALDATA const volatile float32 cal_COMPPwrMaxLmt;/* Referenced by: '<S33>/Constant3' */
extern CALDATA const volatile float32 cal_COMPSpdDiffDown;/* Referenced by: '<S573>/Constant6' */
extern CALDATA const volatile float32 cal_COMPSpdDiffDownRate;/* Referenced by: '<S573>/Constant7' */
extern CALDATA const volatile float32 cal_COMPSpdDiffUp;/* Referenced by: '<S573>/Constant' */
extern CALDATA const volatile float32 cal_COMPSpdDiffUpRate;/* Referenced by: '<S573>/Constant5' */
extern CALDATA const volatile float32 cal_COMPSpdLmt[4];/* Referenced by: '<S445>/Constant13' */
extern CALDATA const volatile float32 cal_COMPStartPwrMinLmt;/* Referenced by: '<S464>/Relay' */
extern CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos1;/* Referenced by: '<S1664>/Constant' */
extern CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos2;/* Referenced by: '<S1665>/Constant' */
extern CALDATA const volatile float32 cal_CabinCondToEvpHPEXVPos;/* Referenced by: '<S1683>/Constant' */
extern CALDATA const volatile uint16 cal_CabinDesTempSolarCorECO_2X[14];
                   /* Referenced by: '<S187>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_2Y[14];
                   /* Referenced by: '<S187>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_MAP[196];
                   /* Referenced by: '<S187>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile uint16 cal_CabinDesTempSolarCor_2X[14];
                      /* Referenced by: '<S187>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCor_2Y[14];
                      /* Referenced by: '<S187>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCor_MAP[196];
                      /* Referenced by: '<S187>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile uint16 cal_CabinEvpToCondCompLmt;/* Referenced by: '<S1682>/Constant' */
extern CALDATA const volatile float32 cal_CabinEvpToHPEnvTemp;/* Referenced by: '<S1696>/Constant' */
extern CALDATA const volatile float32 cal_CabinHys1TempOffset;/* Referenced by:
                                                               * '<S1653>/Constant4'
                                                               * '<S1653>/Constant6'
                                                               * '<S1653>/Constant7'
                                                               * '<S1658>/Constant6'
                                                               * '<S1675>/Constant4'
                                                               * '<S1675>/Constant6'
                                                               * '<S1675>/Constant7'
                                                               * '<S1676>/Constant14'
                                                               * '<S1676>/Constant15'
                                                               * '<S1677>/Constant12'
                                                               * '<S1688>/Constant6'
                                                               * '<S1689>/Constant14'
                                                               * '<S1689>/Constant15'
                                                               * '<S1690>/Constant12'
                                                               */
extern CALDATA const volatile float32 cal_CabinHys2TempOffset;/* Referenced by:
                                                               * '<S1653>/Constant8'
                                                               * '<S1675>/Constant8'
                                                               * '<S1676>/Constant12'
                                                               * '<S1689>/Constant12'
                                                               */
extern CALDATA const volatile float32 cal_CabinMD2F2MaxEnvTemp;/* Referenced by:
                                                                * '<S1685>/Constant1'
                                                                * '<S1673>/Constant'
                                                                * '<S1674>/Constant9'
                                                                * '<S1676>/Constant11'
                                                                * '<S1689>/Constant11'
                                                                * '<S1690>/Constant11'
                                                                */
extern CALDATA const volatile CabinMode cal_CabinModeData;/* Referenced by: '<S1702>/Constant' */
extern CALDATA const volatile boolean cal_CabinModeEnb;/* Referenced by: '<S1702>/Constant1' */
extern CALDATA const volatile float32 cal_CabinModeKeepStandbyTime;/* Referenced by: '<S1659>/Constant2' */
extern CALDATA const volatile float32 cal_CabinModeTransF1Constant;/* Referenced by: '<S1651>/Constant3' */
extern CALDATA const volatile float32 cal_CabinModeTransF1Slope;/* Referenced by: '<S1651>/Constant2' */
extern CALDATA const volatile float32 cal_CabinModeTransF2Constant;/* Referenced by: '<S1651>/Constant4' */
extern CALDATA const volatile float32 cal_CabinModeTransF2Slope;/* Referenced by: '<S1651>/Constant1' */
extern CALDATA const volatile boolean cal_CabinSetPTCSwitch;/* Referenced by: '<S181>/Constant9' */
extern CALDATA const volatile uint8 cal_CabinTCorSelect;/* Referenced by: '<S178>/Constant1' */
extern CALDATA const volatile float32 cal_CabinTempData;/* Referenced by: '<S1733>/Constant' */
extern CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_1X[10];
                    /* Referenced by: '<S178>/cal_CabinTempDuctUpStepCor_CUR' */
extern CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_CUR[10];
                    /* Referenced by: '<S178>/cal_CabinTempDuctUpStepCor_CUR' */
extern CALDATA const volatile boolean cal_CabinTempEnb;/* Referenced by: '<S1733>/Constant1' */
extern CALDATA const volatile uint16 cal_CabinVolAmend_1X[2];
                            /* Referenced by: '<S1715>/cal_CabinVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_CabinVolAmend_CUR[2];
                            /* Referenced by: '<S1715>/cal_CabinVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ChiTempData;/* Referenced by: '<S1785>/Constant' */
extern CALDATA const volatile boolean cal_ChiTempDataEnb;/* Referenced by: '<S1785>/Constant1' */
extern CALDATA const volatile uint16 cal_ChillTempVolAmend_1X[2];
                        /* Referenced by: '<S1723>/cal_ChillTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ChillTempVolAmend_CUR[2];
                        /* Referenced by: '<S1723>/cal_ChillTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ClsCoolInletTemp;/* Referenced by: '<S1312>/Constant' */
extern CALDATA const volatile float32 cal_ClsCoolInletTempTime;/* Referenced by: '<S1312>/Constant2' */
extern CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_1X[15];
                      /* Referenced by: '<S1717>/cal_ColdPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_CUR[15];
                      /* Referenced by: '<S1717>/cal_ColdPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_1X[7];
                 /* Referenced by: '<S1292>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_CUR[7];
                 /* Referenced by: '<S1292>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_CondDepFilter;/* Referenced by: '<S904>/Constant2' */
extern CALDATA const volatile float32 cal_CondDep_1X[28];
                                   /* Referenced by: '<S685>/cal_CondDep_CUR' */
extern CALDATA const volatile float32 cal_CondDep_CUR[28];
                                   /* Referenced by: '<S685>/cal_CondDep_CUR' */
extern CALDATA const volatile float32 cal_CoolFanCtrl_2X[4];
                               /* Referenced by: '<S924>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_CoolFanCtrl_2Y[13];
                               /* Referenced by: '<S924>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_CoolFanCtrl_MAP[52];
                               /* Referenced by: '<S924>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_CoolFanData;/* Referenced by: '<S930>/Constant' */
extern CALDATA const volatile boolean cal_CoolFanEnb;/* Referenced by: '<S930>/Constant1' */
extern CALDATA const volatile float32 cal_CoolStartCompensate;/* Referenced by: '<S281>/Constant8' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2X[6];
                     /* Referenced by: '<S589>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2Y[6];
                     /* Referenced by: '<S589>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_MAP[36];
                     /* Referenced by: '<S589>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCOffPowerVal;/* Referenced by: '<S589>/Constant6' */
extern CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_1X[6];
                        /* Referenced by: '<S589>/cal_CtrlFPTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_CUR[6];
                        /* Referenced by: '<S589>/cal_CtrlFPTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_DCBatHeatEnvTemp[2];/* Referenced by: '<S1512>/Constant1' */
extern CALDATA const volatile float32 cal_DCBatHeatT1[3];/* Referenced by: '<S1512>/Constant2' */
extern CALDATA const volatile float32 cal_DCBatHeatT2[3];/* Referenced by: '<S1512>/Constant3' */
extern CALDATA const volatile float32 cal_DCBatHeatTave[3];/* Referenced by: '<S1512>/Constant' */
extern CALDATA const volatile float32 cal_DCBatHeatTrgTemp;/* Referenced by:
                                                            * '<S650>/Constant4'
                                                            * '<S1512>/Constant4'
                                                            */
extern CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_1X[7];
                     /* Referenced by: '<S1514>/cal_DCChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_CUR[7];
                     /* Referenced by: '<S1514>/cal_DCChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DLTRBatInlet2MaxTempDiff;/* Referenced by: '<S1554>/Constant' */
extern CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_1X[5];
                       /* Referenced by: '<S1527>/cal_DLTRBatMaxEntTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_CUR[5];
                       /* Referenced by: '<S1527>/cal_DLTRBatMaxEntTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_1X[5];/* Referenced by:
                                                                      * '<S1526>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      * '<S1528>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_CUR[5];/* Referenced by:
                                                                      * '<S1526>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      * '<S1528>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_1X[5];
                    /* Referenced by: '<S1546>/cal_DLTRDCBatMaxExitTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_CUR[5];
                    /* Referenced by: '<S1546>/cal_DLTRDCBatMaxExitTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRIPUTempExitVal;/* Referenced by: '<S1547>/Constant' */
extern CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_1X[5];
                 /* Referenced by: '<S1546>/cal_DLTRNotDCBatMaxExitTempC_CUR' */
extern CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_CUR[5];
                 /* Referenced by: '<S1546>/cal_DLTRNotDCBatMaxExitTempC_CUR' */
extern CALDATA const volatile float32 cal_DcutTPidDeadBand;/* Referenced by:
                                                            * '<S230>/Kp11'
                                                            * '<S232>/Kp11'
                                                            */
extern CALDATA const volatile float32 cal_DcutTempPidLL;/* Referenced by:
                                                         * '<S230>/Kp6'
                                                         * '<S232>/Kp6'
                                                         */
extern CALDATA const volatile float32 cal_DcutTempPidUL;/* Referenced by:
                                                         * '<S230>/Kp5'
                                                         * '<S232>/Kp5'
                                                         */
extern CALDATA const volatile float32 cal_DcutTempPid_IsumMax;/* Referenced by:
                                                               * '<S230>/Kp8'
                                                               * '<S232>/Kp8'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_IsumMin;/* Referenced by:
                                                               * '<S230>/Kp13'
                                                               * '<S232>/Kp13'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_Ki;/* Referenced by:
                                                          * '<S230>/Kp7'
                                                          * '<S232>/Kp7'
                                                          */
extern CALDATA const volatile float32 cal_DcutTempPid_KiNeg;/* Referenced by:
                                                             * '<S230>/Kp9'
                                                             * '<S232>/Kp9'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_KiPos;/* Referenced by:
                                                             * '<S230>/Kp10'
                                                             * '<S232>/Kp10'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_Kp;/* Referenced by:
                                                          * '<S230>/Kp'
                                                          * '<S232>/Kp'
                                                          */
extern CALDATA const volatile float32 cal_DcutTempPid_KpNeg;/* Referenced by:
                                                             * '<S230>/Kp1'
                                                             * '<S232>/Kp1'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_KpPos;/* Referenced by:
                                                             * '<S230>/Kp2'
                                                             * '<S232>/Kp2'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_pWinNeg;/* Referenced by:
                                                               * '<S230>/Kp4'
                                                               * '<S232>/Kp4'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_pWinPos;/* Referenced by:
                                                               * '<S230>/Kp3'
                                                               * '<S232>/Kp3'
                                                               */
extern CALDATA const volatile float32 cal_DefaultSetTemp;/* Referenced by: '<S209>/Constant' */
extern CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_1X[7];
                    /* Referenced by: '<S1514>/cal_DisChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_CUR[7];
                    /* Referenced by: '<S1514>/cal_DisChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DrDuctFaceFloorFaFactor;/* Referenced by: '<S228>/Constant3' */
extern CALDATA const volatile float32 cal_DrDuctFaceFloorFoFactor;/* Referenced by: '<S228>/Constant4' */
extern CALDATA const volatile float32 cal_DrDuctSenFailDeflt;
                       /* Referenced by: '<S177>/cal_DrDuctSensorFailDefault' */
extern CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOff;
/* Referenced by: '<S391>/On:cal_DrErrOfEvaDVT2CoolMixOn Off:cal_DrErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOn;
/* Referenced by: '<S391>/On:cal_DrErrOfEvaDVT2CoolMixOn Off:cal_DrErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOff;
/* Referenced by: '<S391>/On:cal_DrErrOfPtcDVT2HeatMixOn Off:cal_DrErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOn;
/* Referenced by: '<S391>/On:cal_DrErrOfPtcDVT2HeatMixOn Off:cal_DrErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandNeg;/* Referenced by: '<S283>/Kp12' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandPos;/* Referenced by: '<S283>/Kp11' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKi;/* Referenced by: '<S283>/Kp7' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKiNeg;/* Referenced by: '<S283>/Kp9' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKiPos;/* Referenced by: '<S283>/Kp10' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKp;/* Referenced by: '<S283>/Kp' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKpNeg;/* Referenced by: '<S283>/Kp1' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKpPos;/* Referenced by: '<S283>/Kp2' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL;/* Referenced by:
                                                            * '<S283>/Kp6'
                                                            * '<S284>/Constant1'
                                                            * '<S309>/Constant4'
                                                            */
extern CALDATA const volatile uint8 cal_DrEvaDesValPIDLL_2X[4];
                          /* Referenced by: '<S277>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL_2Y[7];
                          /* Referenced by: '<S277>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL_MAP[28];
                          /* Referenced by: '<S277>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDUL;/* Referenced by:
                                                            * '<S283>/Kp5'
                                                            * '<S284>/Constant'
                                                            * '<S309>/Constant3'
                                                            */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMax;/* Referenced by: '<S283>/Kp8' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMin;/* Referenced by: '<S283>/Kp13' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_pWinNeg;/* Referenced by: '<S283>/Kp4' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_pWinPos;/* Referenced by: '<S283>/Kp3' */
extern CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_1X[4];
                      /* Referenced by: '<S283>/cal_DrEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_CUR[4];
                      /* Referenced by: '<S283>/cal_DrEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetDefog_1X[8];
                          /* Referenced by: '<S391>/cal_DrMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetDefog_CUR[8];
                          /* Referenced by: '<S391>/cal_DrMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_1X[8];
                     /* Referenced by: '<S391>/cal_DrMixBacSetFaceHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_CUR[8];
                     /* Referenced by: '<S391>/cal_DrMixBacSetFaceHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFace_1X[8];
                           /* Referenced by: '<S391>/cal_DrMixBacSetFace_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFace_CUR[8];
                           /* Referenced by: '<S391>/cal_DrMixBacSetFace_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_1X[8];
                  /* Referenced by: '<S391>/cal_DrMixBacSetHeaterDeforst_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_CUR[8];
                  /* Referenced by: '<S391>/cal_DrMixBacSetHeaterDeforst_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeater_1X[8];
                         /* Referenced by: '<S391>/cal_DrMixBacSetHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeater_CUR[8];
                         /* Referenced by: '<S391>/cal_DrMixBacSetHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixDesValPIDIntegDeadBand;/* Referenced by: '<S392>/Kp11' */
extern CALDATA const volatile uint8 cal_DrMixDesValPIDLL;/* Referenced by: '<S392>/Kp6' */
extern CALDATA const volatile uint8 cal_DrMixDesValPIDUL;/* Referenced by: '<S392>/Kp5' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_IsumMax;/* Referenced by: '<S392>/Kp8' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_IsumMin;/* Referenced by: '<S392>/Kp13' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_Ki;/* Referenced by: '<S392>/Kp7' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KiNeg;/* Referenced by: '<S392>/Kp9' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KiPos;/* Referenced by: '<S392>/Kp10' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_Kp;/* Referenced by: '<S392>/Kp' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KpNeg;/* Referenced by: '<S392>/Kp1' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KpPos;/* Referenced by: '<S392>/Kp2' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_pWinNeg;/* Referenced by: '<S392>/Kp4' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_pWinPos;/* Referenced by: '<S392>/Kp3' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4InHeat;/* Referenced by: '<S344>/Kp16' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4OutHeat;/* Referenced by: '<S344>/Kp26' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKi;/* Referenced by: '<S344>/Kp7' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKiNeg;/* Referenced by: '<S344>/Kp9' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKiPos;/* Referenced by: '<S344>/Kp10' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKp;/* Referenced by: '<S344>/Kp' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKpNeg;/* Referenced by: '<S344>/Kp1' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKpPos;/* Referenced by: '<S344>/Kp2' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDLL;/* Referenced by: '<S344>/Kp6' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDUL;/* Referenced by: '<S344>/Kp5' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMax;/* Referenced by: '<S344>/Kp8' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMin;/* Referenced by: '<S344>/Kp13' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_pWinNeg;/* Referenced by: '<S344>/Kp4' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_pWinPos;/* Referenced by: '<S344>/Kp3' */
extern CALDATA const volatile float32 cal_DvtCoff;/* Referenced by: '<S185>/Constant' */
extern CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_1X[8];
                    /* Referenced by: '<S189>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_CUR[8];
                    /* Referenced by: '<S189>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_1X[8];
                    /* Referenced by: '<S189>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_CUR[8];
                    /* Referenced by: '<S189>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2X[10];
                     /* Referenced by: '<S189>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2Y[10];
                     /* Referenced by: '<S189>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_MAP[100];
                     /* Referenced by: '<S189>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesValPIDIntegDeadBand;/* Referenced by: '<S189>/Constant7' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKi_1X[9];
                            /* Referenced by: '<S189>/cal_DvtDesValPIDKi_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKi_CUR[9];
                            /* Referenced by: '<S189>/cal_DvtDesValPIDKi_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKp_1X[9];
                            /* Referenced by: '<S189>/cal_DvtDesValPIDKp_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKp_CUR[9];
                            /* Referenced by: '<S189>/cal_DvtDesValPIDKp_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPID_Ki;/* Referenced by: '<S189>/Kp7' */
extern CALDATA const volatile float32 cal_DvtDesValPID_Kp;/* Referenced by: '<S189>/Kp' */
extern CALDATA const volatile float32 cal_DvtDesValPID_LL;/* Referenced by:
                                                           * '<S183>/Kp2'
                                                           * '<S183>/Kp6'
                                                           * '<S184>/Kp2'
                                                           * '<S184>/Kp6'
                                                           * '<S189>/Kp6'
                                                           */
extern CALDATA const volatile float32 cal_DvtDesValPID_UL;/* Referenced by:
                                                           * '<S183>/Kp1'
                                                           * '<S183>/Kp5'
                                                           * '<S184>/Kp1'
                                                           * '<S184>/Kp5'
                                                           */
extern CALDATA const volatile float32 cal_DvtDesValPID_pWinNeg;/* Referenced by: '<S189>/Kp4' */
extern CALDATA const volatile float32 cal_DvtDesValPID_pWinPos;/* Referenced by: '<S189>/Kp3' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_2X[6];
                            /* Referenced by: '<S180>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_2Y[7];
                            /* Referenced by: '<S180>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_MAP[42];
                            /* Referenced by: '<S180>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_EEEnvAndEnvDiffVal;/* Referenced by: '<S1717>/Switch12' */
extern CALDATA const volatile float32 cal_EVAPSufTempClsSOV;/* Referenced by: '<S448>/Relay' */
extern CALDATA const volatile float32 cal_EVAPSufTempOpenSOV;/* Referenced by: '<S448>/Relay' */
extern CALDATA const volatile uint16 cal_EVAPSurfTempVolAmend_1X[2];
                     /* Referenced by: '<S1726>/cal_EVAPSurfTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EVAPSurfTempVolAmend_CUR[2];
                     /* Referenced by: '<S1726>/cal_EVAPSurfTempVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_EVAPTempVolAmend_1X[2];
                         /* Referenced by: '<S1725>/cal_EVAPTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EVAPTempVolAmend_CUR[2];
                         /* Referenced by: '<S1725>/cal_EVAPTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_EntExtDefTime;/* Referenced by: '<S1704>/Constant3' */
extern CALDATA const volatile boolean cal_EnvFailSwFlg;/* Referenced by: '<S1724>/Constant' */
extern CALDATA const volatile float32 cal_EnvTAme_1X[11];
                                  /* Referenced by: '<S1718>/cal_EnvTAme_CUR' */
extern CALDATA const volatile float32 cal_EnvTAme_CUR[11];
                                  /* Referenced by: '<S1718>/cal_EnvTAme_CUR' */
extern CALDATA const volatile float32 cal_EnvTempCorData;/* Referenced by: '<S1751>/Constant' */
extern CALDATA const volatile boolean cal_EnvTempCorEnb;/* Referenced by: '<S1751>/Constant1' */
extern CALDATA const volatile float32 cal_EnvTempRiseStep;/* Referenced by: '<S1717>/Constant3' */
extern CALDATA const volatile float32 cal_EnvTempStep;/* Referenced by: '<S182>/Constant3' */
extern CALDATA const volatile uint16 cal_EnvVolAmend_1X[2];
                              /* Referenced by: '<S1724>/cal_EnvVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EnvVolAmend_CUR[2];
                              /* Referenced by: '<S1724>/cal_EnvVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForEvaLL;/* Referenced by: '<S180>/Constant4' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForEvaUL;/* Referenced by: '<S180>/Constant3' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForPtcLL;/* Referenced by: '<S181>/Constant2' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForPtcUL;/* Referenced by: '<S181>/Constant1' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInComf_OFF;
/* Referenced by: '<S90>/On:cal_ErrOfEvaActTargInComf_ON Off:cal_ErrOfEvaActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInComf_ON;
/* Referenced by: '<S90>/On:cal_ErrOfEvaActTargInComf_ON Off:cal_ErrOfEvaActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInDefog_OFF;
/* Referenced by: '<S91>/On:cal_ErrOfEvaActTargInDefog_ON Off:cal_ErrOfEvaActTargInDefog_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInDefog_ON;
/* Referenced by: '<S91>/On:cal_ErrOfEvaActTargInDefog_ON Off:cal_ErrOfEvaActTargInDefog_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInEcon_OFF;
/* Referenced by: '<S90>/On:cal_ErrOfEvaActTargInEcon_ON Off:cal_ErrOfEvaActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInEcon_ON;
/* Referenced by: '<S90>/On:cal_ErrOfEvaActTargInEcon_ON Off:cal_ErrOfEvaActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInComf_OFF;
/* Referenced by: '<S97>/On:cal_ErrOfPTCActTargInComf_ON Off:cal_ErrOfPTCActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInComf_ON;
/* Referenced by: '<S97>/On:cal_ErrOfPTCActTargInComf_ON Off:cal_ErrOfPTCActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInEcon_OFF;
/* Referenced by: '<S97>/On:cal_ErrOfPTCActTargInEcon_ON Off:cal_ErrOfPTCActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInEcon_ON;
/* Referenced by: '<S97>/On:cal_ErrOfPTCActTargInEcon_ON Off:cal_ErrOfPTCActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_EvaDesLLMax;/* Referenced by:
                                                       * '<S180>/Constant1'
                                                       * '<S277>/Constant1'
                                                       * '<S278>/Constant1'
                                                       * '<S281>/Constant4'
                                                       */
extern CALDATA const volatile float32 cal_EvaDesLLMin;/* Referenced by:
                                                       * '<S277>/Constant8'
                                                       * '<S278>/Constant8'
                                                       * '<S281>/Constant2'
                                                       * '<S281>/Constant6'
                                                       */
extern CALDATA const volatile boolean cal_EvaDesLLSelect;/* Referenced by: '<S281>/Constant' */
extern CALDATA const volatile boolean cal_EvaEnable;/* Referenced by:
                                                     * '<S388>/Constant1'
                                                     * '<S389>/Constant1'
                                                     */
extern CALDATA const volatile float32 cal_EvapBacTempDesACBi_1X[6];
                        /* Referenced by: '<S284>/cal_EvapBacTempDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesACBi_CUR[6];
                        /* Referenced by: '<S284>/cal_EvapBacTempDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesAC_1X[6];
                          /* Referenced by: '<S284>/cal_EvapBacTempDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesAC_CUR[6];
                          /* Referenced by: '<S284>/cal_EvapBacTempDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesDefog_1X[6];
                       /* Referenced by: '<S284>/cal_EvapBacTempDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesDefog_CUR[6];
                       /* Referenced by: '<S284>/cal_EvapBacTempDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFootDe_1X[6];
                      /* Referenced by: '<S284>/cal_EvapBacTempDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFootDe_CUR[6];
                      /* Referenced by: '<S284>/cal_EvapBacTempDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFoot_1X[6];
                        /* Referenced by: '<S284>/cal_EvapBacTempDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFoot_CUR[6];
                        /* Referenced by: '<S284>/cal_EvapBacTempDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_1X[6];
                      /* Referenced by: '<S309>/cal_EvapBacTempPsDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_CUR[6];
                      /* Referenced by: '<S309>/cal_EvapBacTempPsDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesAC_1X[6];
                        /* Referenced by: '<S309>/cal_EvapBacTempPsDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesAC_CUR[6];
                        /* Referenced by: '<S309>/cal_EvapBacTempPsDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_1X[6];
                     /* Referenced by: '<S309>/cal_EvapBacTempPsDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_CUR[6];
                     /* Referenced by: '<S309>/cal_EvapBacTempPsDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_1X[6];
                    /* Referenced by: '<S309>/cal_EvapBacTempPsDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_CUR[6];
                    /* Referenced by: '<S309>/cal_EvapBacTempPsDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_1X[6];
                      /* Referenced by: '<S309>/cal_EvapBacTempPsDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_CUR[6];
                      /* Referenced by: '<S309>/cal_EvapBacTempPsDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimByEnv_1X[8];
                         /* Referenced by: '<S281>/cal_EvapDesLoLimByEnv_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimByEnv_CUR[8];
                         /* Referenced by: '<S281>/cal_EvapDesLoLimByEnv_CUR' */
extern CALDATA const volatile uint16 cal_EvapDesLoLimBySolarCor_1X[2];
                    /* Referenced by: '<S281>/cal_EvapDesLoLimBySolarCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimBySolarCor_CUR[2];
                    /* Referenced by: '<S281>/cal_EvapDesLoLimBySolarCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempCabinCor_1X[6];
                       /* Referenced by: '<S284>/cal_EvapDesTempCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempCabinCor_CUR[6];
                       /* Referenced by: '<S284>/cal_EvapDesTempCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_2X[6];
                         /* Referenced by: '<S284>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_2Y[6];
                         /* Referenced by: '<S284>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_MAP[36];
                         /* Referenced by: '<S284>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_EvapDesTempFanCor_1X[4];
                         /* Referenced by: '<S284>/cal_EvapDesTempFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempFanCor_CUR[4];
                         /* Referenced by: '<S284>/cal_EvapDesTempFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_1X[6];
                     /* Referenced by: '<S309>/cal_EvapDesTempPsCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_CUR[6];
                     /* Referenced by: '<S309>/cal_EvapDesTempPsCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2X[6];
                       /* Referenced by: '<S309>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2Y[6];
                       /* Referenced by: '<S309>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_MAP[36];
                       /* Referenced by: '<S309>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_EvapDesTempPsFanCor_1X[4];
                       /* Referenced by: '<S309>/cal_EvapDesTempPsFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsFanCor_CUR[4];
                       /* Referenced by: '<S309>/cal_EvapDesTempPsFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapSurTempData;/* Referenced by: '<S1817>/Constant' */
extern CALDATA const volatile boolean cal_EvapSurTempDataEnb;/* Referenced by: '<S1817>/Constant1' */
extern CALDATA const volatile float32 cal_EvapTempData;/* Referenced by: '<S1807>/Constant' */
extern CALDATA const volatile boolean cal_EvapTempDataEnb;/* Referenced by: '<S1807>/Constant1' */
extern CALDATA const volatile float32 cal_ExhSuperHeatFilter;/* Referenced by: '<S908>/Constant1' */
extern CALDATA const volatile uint16 cal_ExhaustTime;/* Referenced by: '<S11>/Constant7' */
extern CALDATA const volatile float32 cal_ExitExtDefTime;/* Referenced by: '<S1705>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefBatMinT;/* Referenced by: '<S948>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefEnvMaxTemp;/* Referenced by: '<S1704>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefEnvMinTemp;/* Referenced by: '<S1704>/Constant1' */
extern CALDATA const volatile boolean cal_ExtDefFlgData;/* Referenced by: '<S1707>/Constant' */
extern CALDATA const volatile boolean cal_ExtDefFlgDataEnb;/* Referenced by: '<S1707>/Constant1' */
extern CALDATA const volatile float32 cal_ExtDefOHXOffTemp;/* Referenced by: '<S1709>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefOHXOnTemp;/* Referenced by: '<S1708>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefPTCTrgTemp;/* Referenced by: '<S446>/Constant6' */
extern CALDATA const volatile float32 cal_ExtDefTempDiff;/* Referenced by: '<S1704>/Constant2' */
extern CALDATA const volatile uint8 cal_FANSpdHotStartLL;/* Referenced by: '<S53>/Constant12' */
extern CALDATA const volatile uint8 cal_FANSpdHotStartUL;/* Referenced by: '<S52>/Constant27' */
extern CALDATA const volatile uint8 cal_FANSpdModeShiftMax;/* Referenced by: '<S52>/Constant3' */
extern CALDATA const volatile float32 cal_FaceDuctTempData;/* Referenced by: '<S1756>/Constant' */
extern CALDATA const volatile boolean cal_FaceDuctTempEnb;/* Referenced by: '<S1756>/Constant1' */
extern CALDATA const volatile uint16 cal_FaceDuctVolAmend_1X[2];
                         /* Referenced by: '<S1719>/cal_FaceDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_FaceDuctVolAmend_CUR[2];
                         /* Referenced by: '<S1719>/cal_FaceDuctVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_FallTime2Tamb;
                                    /* Referenced by: '<S1717>/TempRampStep3' */
extern CALDATA const volatile uint16 cal_FalseTime2EnvTamb;
                                     /* Referenced by: '<S182>/TempRampStep3' */
extern CALDATA const volatile uint16 cal_FalseTime2Solar;
                                     /* Referenced by: '<S187>/TempRampStep2' */
extern CALDATA const volatile uint8 cal_FanCtrlOff;/* Referenced by: '<S929>/Constant2' */
extern CALDATA const volatile uint8 cal_FanLevelToPWM[10];/* Referenced by:
                                                           * '<S57>/Constant2'
                                                           * '<S58>/Constant18'
                                                           * '<S59>/Constant2'
                                                           * '<S61>/Constant1'
                                                           * '<S61>/Constant11'
                                                           * '<S61>/Constant14'
                                                           * '<S61>/Constant16'
                                                           * '<S61>/Constant18'
                                                           * '<S61>/Constant2'
                                                           * '<S61>/Constant4'
                                                           * '<S61>/Constant7'
                                                           * '<S61>/Constant9'
                                                           */
extern CALDATA const volatile boolean cal_FixPIDSecletFlag;/* Referenced by:
                                                            * '<S388>/Constant'
                                                            * '<S389>/Constant'
                                                            * '<S277>/Constant'
                                                            * '<S278>/Constant'
                                                            * '<S337>/Constant'
                                                            * '<S338>/Constant'
                                                            * '<S186>/Constant'
                                                            */
extern CALDATA const volatile float32 cal_FootDuctTempData;/* Referenced by: '<S1766>/Constant' */
extern CALDATA const volatile boolean cal_FootDuctTempEnb;/* Referenced by: '<S1766>/Constant1' */
extern CALDATA const volatile uint16 cal_FootDuctVolAmend_1X[2];
                         /* Referenced by: '<S1720>/cal_FootDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_FootDuctVolAmend_CUR[2];
                         /* Referenced by: '<S1720>/cal_FootDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_HAPevap_min;
                             /* Referenced by: '<S41>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPparkdly_time;
                             /* Referenced by: '<S41>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPpurge_time;
                             /* Referenced by: '<S41>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPtimelim2activtic;
                             /* Referenced by: '<S41>/AirConditionStartState' */
extern CALDATA const volatile boolean cal_HMIUnlckVentEnb;/* Referenced by: '<S1213>/Constant1' */
extern CALDATA const volatile uint8 cal_HMIUnlckVentEnbData;/* Referenced by: '<S1213>/Constant' */
extern CALDATA const volatile float32 cal_HPAndLPDiffMaxVal;/* Referenced by: '<S523>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtlKi;/* Referenced by: '<S830>/Constant11' */
extern CALDATA const volatile float32 cal_HPEXVCtlKiDeadzoneNeg;/* Referenced by: '<S830>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVCtlKiDeadzonePos;/* Referenced by: '<S830>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtlKisumMax;/* Referenced by: '<S830>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtlKisumMin;/* Referenced by: '<S830>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtlKp;/* Referenced by: '<S830>/Constant10' */
extern CALDATA const volatile float32 cal_HPEXVCtlKpDeadzoneNeg;/* Referenced by: '<S830>/Constant5' */
extern CALDATA const volatile float32 cal_HPEXVCtlKpDeadzonePos;/* Referenced by: '<S830>/Constant4' */
extern CALDATA const volatile float32 cal_HPEXVCtrlADeadzone;/* Referenced by: '<S867>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlADelayTime;/* Referenced by: '<S867>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFFLolmt;/* Referenced by: '<S867>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFFUplmt;/* Referenced by: '<S867>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFF_1X[5];
                              /* Referenced by: '<S867>/cal_HPEXVCtrlAFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFF_CUR[5];
                              /* Referenced by: '<S867>/cal_HPEXVCtrlAFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKi_1X[6];
                              /* Referenced by: '<S867>/cal_HPEXVCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKi_CUR[6];
                              /* Referenced by: '<S867>/cal_HPEXVCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKp_1X[6];
                              /* Referenced by: '<S867>/cal_HPEXVCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKp_CUR[6];
                              /* Referenced by: '<S867>/cal_HPEXVCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAMax;/* Referenced by: '<S867>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAMin;/* Referenced by: '<S867>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAOpenVal;/* Referenced by: '<S867>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_1X[5];
                     /* Referenced by: '<S867>/cal_HPEXVCtrlATrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_CUR[5];
                     /* Referenced by: '<S867>/cal_HPEXVCtrlATrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCDeadzone;/* Referenced by: '<S869>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCDelayTime;/* Referenced by: '<S869>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCFF_1X[5];
                              /* Referenced by: '<S869>/cal_HPEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCFF_CUR[5];
                              /* Referenced by: '<S869>/cal_HPEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKi_1X[8];
                              /* Referenced by: '<S869>/cal_HPEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKi_CUR[8];
                              /* Referenced by: '<S869>/cal_HPEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKp_1X[8];
                              /* Referenced by: '<S869>/cal_HPEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKp_CUR[8];
                              /* Referenced by: '<S869>/cal_HPEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCMax;/* Referenced by: '<S869>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCMin;/* Referenced by: '<S869>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCOpenVal;/* Referenced by: '<S869>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDDeadzone;/* Referenced by: '<S870>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDDelayTime;/* Referenced by: '<S870>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFFLolmt;/* Referenced by: '<S870>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFFUplmt;/* Referenced by: '<S870>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFF_1X[5];
                              /* Referenced by: '<S870>/cal_HPEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFF_CUR[5];
                              /* Referenced by: '<S870>/cal_HPEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKi_1X[8];
                              /* Referenced by: '<S870>/cal_HPEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKi_CUR[8];
                              /* Referenced by: '<S870>/cal_HPEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKp_1X[8];
                              /* Referenced by: '<S870>/cal_HPEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKp_CUR[8];
                              /* Referenced by: '<S870>/cal_HPEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDMax;/* Referenced by: '<S870>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDMin;/* Referenced by: '<S870>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDOpenVal;/* Referenced by: '<S870>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_1X[5];
                     /* Referenced by: '<S870>/cal_HPEXVCtrlDTrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_CUR[5];
                     /* Referenced by: '<S870>/cal_HPEXVCtrlDTrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEDeadzone;/* Referenced by: '<S871>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEDelayTime;/* Referenced by: '<S871>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFFLolmt;/* Referenced by: '<S871>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFFUplmt;/* Referenced by: '<S871>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFF_1X[5];
                              /* Referenced by: '<S871>/cal_HPEXVCtrlEFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFF_CUR[5];
                              /* Referenced by: '<S871>/cal_HPEXVCtrlEFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKi_1X[6];
                              /* Referenced by: '<S871>/cal_HPEXVCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKi_CUR[6];
                              /* Referenced by: '<S871>/cal_HPEXVCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKp_1X[6];
                              /* Referenced by: '<S871>/cal_HPEXVCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKp_CUR[6];
                              /* Referenced by: '<S871>/cal_HPEXVCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEMax;/* Referenced by: '<S871>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEMin;/* Referenced by: '<S871>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEOpenVal;/* Referenced by: '<S871>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_1X[5];
                     /* Referenced by: '<S871>/cal_HPEXVCtrlETrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_CUR[5];
                     /* Referenced by: '<S871>/cal_HPEXVCtrlETrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVDiffDown;/* Referenced by: '<S834>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVDiffDownRate;/* Referenced by: '<S834>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVDiffUp;/* Referenced by: '<S834>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVDiffUpRate;/* Referenced by: '<S834>/Constant5' */
extern CALDATA const volatile float32 cal_HPEXVDownSpdLmt;/* Referenced by:
                                                           * '<S839>/DownLmt'
                                                           * '<S839>/DownLmt1'
                                                           */
extern CALDATA const volatile boolean cal_HPEXVEnbData;/* Referenced by: '<S845>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVEnbDataEnb;/* Referenced by: '<S845>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVFloorDiff1;/* Referenced by: '<S837>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVFloorDiff2;/* Referenced by: '<S837>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVHiPressLmtOff;/* Referenced by: '<S873>/HiPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVHiPressLmtOn;/* Referenced by: '<S873>/HiPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVHiPressProOpenSpd;/* Referenced by:
                                                                  * '<S834>/Constant1'
                                                                  * '<S834>/Constant3'
                                                                  */
extern CALDATA const volatile float32 cal_HPEXVHiPressProhOff;/* Referenced by: '<S834>/HiProRelay' */
extern CALDATA const volatile float32 cal_HPEXVHiPressProhOn;/* Referenced by: '<S834>/HiProRelay' */
extern CALDATA const volatile uint8 cal_HPEXVInitReqData;/* Referenced by: '<S902>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVInitReqDataeEnb;/* Referenced by: '<S902>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVLowPressLmtOff;/* Referenced by: '<S873>/LowPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVLowPressLmtOn;/* Referenced by: '<S873>/LowPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVLowPressProOpenSpd;/* Referenced by:
                                                                   * '<S834>/Constant'
                                                                   * '<S834>/Constant2'
                                                                   */
extern CALDATA const volatile float32 cal_HPEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                   * '<S840>/DownLmt'
                                                                   * '<S840>/DownLmt1'
                                                                   */
extern CALDATA const volatile float32 cal_HPEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                 * '<S840>/UpLmt'
                                                                 * '<S840>/UpLmt2'
                                                                 */
extern CALDATA const volatile float32 cal_HPEXVPosData;/* Referenced by: '<S835>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVPosDataEnb;/* Referenced by: '<S835>/Constant1' */
extern CALDATA const volatile boolean cal_HPEXVStepLmtSw;/* Referenced by: '<S827>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVSubCoolflt;/* Referenced by:
                                                           * '<S867>/Constant11'
                                                           * '<S870>/Constant11'
                                                           * '<S871>/Constant11'
                                                           */
extern CALDATA const volatile float32 cal_HPEXVUpSpdLmt;/* Referenced by:
                                                         * '<S839>/UpLmt'
                                                         * '<S839>/UpLmt2'
                                                         */
extern CALDATA const volatile float32 cal_HPEXVlowPressLmtTrg;/* Referenced by: '<S831>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVlowPressProhOff;/* Referenced by: '<S834>/LowProRelay' */
extern CALDATA const volatile float32 cal_HPEXVlowPressProhOn;/* Referenced by: '<S834>/LowProRelay' */
extern CALDATA const volatile float32 cal_HPHighLmtVal;/* Referenced by: '<S1730>/Constant' */
extern CALDATA const volatile float32 cal_HPProVal1;/* Referenced by: '<S533>/Relay' */
extern CALDATA const volatile float32 cal_HPProVal1Relay;/* Referenced by: '<S533>/Relay' */
extern CALDATA const volatile float32 cal_HPProVal2;/* Referenced by:
                                                     * '<S531>/Relay1'
                                                     * '<S533>/Relay1'
                                                     */
extern CALDATA const volatile float32 cal_HPProVal2Relay;/* Referenced by:
                                                          * '<S531>/Relay1'
                                                          * '<S533>/Relay1'
                                                          */
extern CALDATA const volatile float32 cal_HPProVal3;/* Referenced by:
                                                     * '<S528>/Relay2'
                                                     * '<S530>/Relay2'
                                                     * '<S531>/Relay2'
                                                     * '<S533>/Relay2'
                                                     */
extern CALDATA const volatile float32 cal_HPProVal3Relay;/* Referenced by:
                                                          * '<S528>/Relay2'
                                                          * '<S531>/Relay2'
                                                          * '<S533>/Relay2'
                                                          */
extern CALDATA const volatile float32 cal_HPProVal4;/* Referenced by: '<S530>/Relay2' */
extern CALDATA const volatile uint8 cal_HVPartModeData;/* Referenced by: '<S1710>/Constant' */
extern CALDATA const volatile boolean cal_HVPartModeEnb;/* Referenced by: '<S1710>/Constant1' */
extern CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOff;/* Referenced by: '<S502>/Relay1' */
extern CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOn;/* Referenced by: '<S502>/Relay1' */
extern CALDATA const volatile uint8 cal_HeatCabinAndCoolBatFanSpd;/* Referenced by: '<S445>/Constant1' */
extern CALDATA const volatile float32 cal_HeatFanCtrl_2X[4];
                               /* Referenced by: '<S927>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_HeatFanCtrl_2Y[13];
                               /* Referenced by: '<S927>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_HeatFanCtrl_MAP[52];
                               /* Referenced by: '<S927>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsDownSpd;/* Referenced by: '<S457>/Constant1' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP1;/* Referenced by: '<S457>/Relay13' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP2;/* Referenced by: '<S457>/Relay13' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP3;/* Referenced by: '<S457>/Relay12' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP4;/* Referenced by: '<S457>/Relay12' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP5;/* Referenced by: '<S457>/Relay14' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP6;/* Referenced by: '<S457>/Relay14' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP7;/* Referenced by: '<S457>/Relay15' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP8;/* Referenced by: '<S457>/Relay15' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsDownSpd;/* Referenced by: '<S457>/Constant3' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP1;/* Referenced by: '<S457>/Relay5' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP2;/* Referenced by: '<S457>/Relay5' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP3;/* Referenced by: '<S457>/Relay4' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP4;/* Referenced by: '<S457>/Relay4' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP5;/* Referenced by: '<S457>/Relay6' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP6;/* Referenced by: '<S457>/Relay6' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP7;/* Referenced by: '<S457>/Relay7' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP8;/* Referenced by: '<S457>/Relay7' */
extern CALDATA const volatile float32 cal_HeatPwrOn;/* Referenced by:
                                                     * '<S1383>/Constant'
                                                     * '<S1394>/Constant'
                                                     * '<S1466>/Constant'
                                                     * '<S1479>/Constant'
                                                     */
extern CALDATA const volatile float32 cal_HiPressData;/* Referenced by: '<S1851>/Constant' */
extern CALDATA const volatile boolean cal_HiPressDataEnb;/* Referenced by: '<S1851>/Constant1' */
extern CALDATA const volatile float32 cal_IGBTDownLmtTemp;/* Referenced by: '<S1308>/Relay1' */
extern CALDATA const volatile float32 cal_IGBTUpLmtTemp;/* Referenced by: '<S1308>/Relay1' */
extern CALDATA const volatile uint8 cal_IGNONDelayTime;/* Referenced by: '<S32>/Constant3' */
extern CALDATA const volatile uint8 cal_InnerRecTrgPos;/* Referenced by: '<S1866>/Constant1' */
extern CALDATA const volatile float32 cal_LAirmixNomOutWaterT;/* Referenced by:
                                                               * '<S393>/Constant6'
                                                               * '<S419>/Constant6'
                                                               */
extern CALDATA const volatile float32 cal_LCCOutHiPressRaw_1X[2];
                         /* Referenced by: '<S1730>/cal_LCCOutHiPressRaw_CUR' */
extern CALDATA const volatile float32 cal_LCCOutHiPressRaw_CUR[2];
                         /* Referenced by: '<S1730>/cal_LCCOutHiPressRaw_CUR' */
extern CALDATA const volatile uint8 cal_LPFanCtrl;/* Referenced by: '<S928>/Constant11' */
extern CALDATA const volatile float32 cal_LPFanOff;/* Referenced by: '<S941>/Constant' */
extern CALDATA const volatile float32 cal_LPFanOn;/* Referenced by: '<S940>/Constant' */
extern CALDATA const volatile float32 cal_LPProOffTimer;/* Referenced by: '<S928>/Constant1' */
extern CALDATA const volatile float32 cal_LPProOnTimer;/* Referenced by: '<S928>/Constant' */
extern CALDATA const volatile float32 cal_LTRExitBatMaxCellTemp;/* Referenced by: '<S1452>/Constant' */
extern CALDATA const volatile float32 cal_LTRFanCtrl_1X[2];/* Referenced by:
                                                            * '<S935>/Constant1'
                                                            * '<S935>/Constant2'
                                                            */
extern CALDATA const volatile uint8 cal_LTRFanCtrl_1Y[3];/* Referenced by:
                                                          * '<S935>/Constant4'
                                                          * '<S935>/Constant6'
                                                          * '<S935>/Constant9'
                                                          */
extern CALDATA const volatile float32 cal_LTRIGBTMaxExitTempB;/* Referenced by: '<S1620>/Constant' */
extern CALDATA const volatile float32 cal_LTRIGBTTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1072>/Constant1'
                                                                      * '<S1072>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRIGBTTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                     * '<S1072>/Constant4'
                                                                     * '<S1072>/Constant6'
                                                                     * '<S1072>/Constant9'
                                                                     */
extern CALDATA const volatile float32 cal_LTRIPUTempFanCtrl_1X[2];/* Referenced by:
                                                                   * '<S934>/Constant1'
                                                                   * '<S934>/Constant2'
                                                                   */
extern CALDATA const volatile uint8 cal_LTRIPUTempFanCtrl_1Y[3];/* Referenced by:
                                                                 * '<S934>/Constant4'
                                                                 * '<S934>/Constant6'
                                                                 * '<S934>/Constant9'
                                                                 */
extern CALDATA const volatile float32 cal_LTRIPUTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1076>/Constant1'
                                                                      * '<S1076>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRIPUTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                    * '<S1076>/Constant4'
                                                                    * '<S1076>/Constant6'
                                                                    * '<S1076>/Constant9'
                                                                    */
extern CALDATA const volatile float32 cal_LTRMotorInletMaxExitTempA;/* Referenced by: '<S1619>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorMaxEntTemp;/* Referenced by: '<S1645>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorMaxExitTemp;/* Referenced by: '<S1622>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1073>/Constant1'
                                                                      * '<S1073>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRMotorTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                      * '<S1073>/Constant4'
                                                                      * '<S1073>/Constant6'
                                                                      * '<S1073>/Constant9'
                                                                      */
extern CALDATA const volatile float32 cal_LTT1DownMCV_1X[5];
                               /* Referenced by: '<S651>/cal_LTT1DownMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1DownMCV_CUR[5];
                               /* Referenced by: '<S651>/cal_LTT1DownMCV_CUR' */
extern CALDATA const volatile float32 cal_LTT1StbyMCV_1X[6];
                               /* Referenced by: '<S651>/cal_LTT1StbyMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1StbyMCV_CUR[6];
                               /* Referenced by: '<S651>/cal_LTT1StbyMCV_CUR' */
extern CALDATA const volatile float32 cal_LTT1UpMCV_1X[5];
                                 /* Referenced by: '<S651>/cal_LTT1UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1UpMCV_CUR[5];
                                 /* Referenced by: '<S651>/cal_LTT1UpMCV_CUR' */
extern CALDATA const volatile boolean cal_LessThanT1CalSwt;/* Referenced by:
                                                            * '<S649>/Constant3'
                                                            * '<S651>/Constant3'
                                                            */
extern CALDATA const volatile float32 cal_LoPressData;/* Referenced by: '<S1775>/Constant' */
extern CALDATA const volatile boolean cal_LoPressDataEnb;/* Referenced by: '<S1775>/Constant1' */
extern CALDATA const volatile float32 cal_LoPressRaw_1X[2];
                                  /* Referenced by: '<S1721>/cal_LoPress_CUR' */
extern CALDATA const volatile float32 cal_LoPressRaw_CUR[2];
                                  /* Referenced by: '<S1721>/cal_LoPress_CUR' */
extern CALDATA const volatile float32 cal_MBIGBTHighExitTempG;/* Referenced by: '<S1609>/Constant' */
extern CALDATA const volatile float32 cal_MBIPUDevHighExitTempI;/* Referenced by: '<S1613>/Constant' */
extern CALDATA const volatile float32 cal_MBMotorInletHighExitTempH;/* Referenced by: '<S1610>/Constant' */
extern CALDATA const volatile uint8 cal_MCVFltStsDelayTime;/* Referenced by: '<S644>/Constant5' */
extern CALDATA const volatile float32 cal_MCVPosDiffDelayTime;/* Referenced by: '<S644>/Constant2' */
extern CALDATA const volatile uint8 cal_MixCoolTrgPos;/* Referenced by: '<S1867>/Constant1' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinCoolingEn_OFF;/* Referenced by: '<S90>/Constant7' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinCoolingEn_ON;/* Referenced by: '<S90>/Constant6' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinHeatingEn_OFF;
/* Referenced by: '<S95>/On:cal_MixDoor2CabinHeatingEn_ON Off:cal_MixDoor2CabinHeatingEn_OFF ' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinHeatingEn_ON;
/* Referenced by: '<S95>/On:cal_MixDoor2CabinHeatingEn_ON Off:cal_MixDoor2CabinHeatingEn_OFF ' */
extern CALDATA const volatile float32 cal_MixDoorClsFF_1X[8];
                              /* Referenced by: '<S392>/cal_MixDoorClsFF_CUR' */
extern CALDATA const volatile float32 cal_MixDoorClsFF_CUR[8];
                              /* Referenced by: '<S392>/cal_MixDoorClsFF_CUR' */
extern CALDATA const volatile boolean cal_MixDoorEnb;/* Referenced by:
                                                      * '<S1867>/Judge'
                                                      * '<S1867>/Constant6'
                                                      * '<S1880>/Constant1'
                                                      * '<S1881>/Constant1'
                                                      */
extern CALDATA const volatile float32 cal_MixDoorKi_1X[8];
                                 /* Referenced by: '<S392>/cal_MixDoorKi_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKi_CUR[8];
                                 /* Referenced by: '<S392>/cal_MixDoorKi_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKp_1X[8];
                                 /* Referenced by: '<S392>/cal_MixDoorKp_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKp_CUR[8];
                                 /* Referenced by: '<S392>/cal_MixDoorKp_CUR' */
extern CALDATA const volatile uint8 cal_MixDoorNData;/* Referenced by: '<S1880>/Constant' */
extern CALDATA const volatile float32 cal_MixDoorNErr;/* Referenced by: '<S1867>/Judge' */
extern CALDATA const volatile uint8 cal_MixDoorPData;/* Referenced by: '<S1881>/Constant' */
extern CALDATA const volatile float32 cal_MixDoorPErr;/* Referenced by: '<S1867>/Judge' */
extern CALDATA const volatile float32 cal_MixDoorPercData;/* Referenced by: '<S1219>/Constant' */
extern CALDATA const volatile boolean cal_MixDoorPercDataEnb;/* Referenced by: '<S1219>/Constant1' */
extern CALDATA const volatile float32 cal_MixDoorPerc_CUR[2];
                              /* Referenced by: '<S1214>/cal_MixDoorPerc_CUR' */
extern CALDATA const volatile float32 cal_MixDoorV_1X[2];
                              /* Referenced by: '<S1214>/cal_MixDoorPerc_CUR' */
extern CALDATA const volatile uint16 cal_MixDoorVolAmend_1X[2];
                          /* Referenced by: '<S1214>/cal_MixDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_MixDoorVolAmend_CUR[2];
                          /* Referenced by: '<S1214>/cal_MixDoorVolAmend_CUR' */
extern CALDATA const volatile uint8 cal_MixWarmTrgPos;/* Referenced by: '<S1867>/Constant' */
extern CALDATA const volatile uint16 cal_ModeDoorVolAmend_1X[2];
                         /* Referenced by: '<S1215>/cal_ModeDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ModeDoorVolAmend_CUR[2];
                         /* Referenced by: '<S1215>/cal_ModeDoorVolAmend_CUR' */
extern CALDATA const volatile boolean cal_ModeMotorEnb;/* Referenced by:
                                                        * '<S1868>/Judge'
                                                        * '<S1868>/Constant4'
                                                        * '<S1888>/Constant1'
                                                        * '<S1889>/Constant1'
                                                        */
extern CALDATA const volatile uint8 cal_ModeMotorNData;/* Referenced by: '<S1888>/Constant' */
extern CALDATA const volatile float32 cal_ModeMotorNErr;/* Referenced by: '<S1868>/Judge' */
extern CALDATA const volatile uint8 cal_ModeMotorPData;/* Referenced by: '<S1889>/Constant' */
extern CALDATA const volatile float32 cal_ModeMotorPErr;/* Referenced by: '<S1868>/Judge' */
extern CALDATA const volatile float32 cal_ModeMotorTrgPosData;/* Referenced by: '<S1887>/Constant' */
extern CALDATA const volatile boolean cal_ModeMotorTrgPosDataEnb;/* Referenced by:
                                                                  * '<S1868>/Constant3'
                                                                  * '<S1887>/Constant1'
                                                                  */
extern CALDATA const volatile uint8 cal_ModeMotorTrgPos_1X[5];
                          /* Referenced by: '<S1868>/cal_ModeMotorTrgPos_CUR' */
extern CALDATA const volatile float32 cal_ModeMotorTrgPos_CUR[5];
                          /* Referenced by: '<S1868>/cal_ModeMotorTrgPos_CUR' */
extern CALDATA const volatile float32 cal_MotHeatBatMinTempDiff;/* Referenced by: '<S1351>/Constant' */
extern CALDATA const volatile uint16 cal_MotInletTempVolAmend_1X[2];
                     /* Referenced by: '<S1727>/cal_MotInletTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_MotInletTempVolAmend_CUR[2];
                     /* Referenced by: '<S1727>/cal_MotInletTempVolAmend_CUR' */
extern CALDATA const volatile uint8 cal_MotPMPDefaultSpd;/* Referenced by: '<S1033>/Constant4' */
extern CALDATA const volatile boolean cal_MotPMPFaultFlgData;/* Referenced by: '<S1075>/Constant' */
extern CALDATA const volatile boolean cal_MotPMPFaultFlgDataEnb;/* Referenced by: '<S1075>/Constant1' */
extern CALDATA const volatile uint8 cal_MotPMPMotHeatBatSpd;/* Referenced by: '<S1033>/Constant11' */
extern CALDATA const volatile uint8 cal_MotPMPSpdDiffVal;/* Referenced by: '<S1033>/Constant' */
extern CALDATA const volatile uint8 cal_MotPMPSpdSetData;/* Referenced by: '<S1074>/Constant' */
extern CALDATA const volatile boolean cal_MotPMPSpdSetDataEnb;/* Referenced by: '<S1074>/Constant1' */
extern CALDATA const volatile uint8 cal_MotPMPThStoSpd;/* Referenced by: '<S1033>/Constant12' */
extern CALDATA const volatile float32 cal_MotTempData;/* Referenced by: '<S1823>/Constant' */
extern CALDATA const volatile boolean cal_MotTempDataEnb;/* Referenced by: '<S1823>/Constant1' */
extern CALDATA const volatile float32 cal_MotTempDownLmt;/* Referenced by: '<S1308>/Relay' */
extern CALDATA const volatile float32 cal_MotTempUpLmt;/* Referenced by: '<S1308>/Relay' */
extern CALDATA const volatile float32 cal_MotorModeData;/* Referenced by: '<S1226>/Constant' */
extern CALDATA const volatile boolean cal_MotorModeEnb;/* Referenced by: '<S1226>/Constant1' */
extern CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOff;/* Referenced by: '<S502>/Relay' */
extern CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOn;/* Referenced by: '<S502>/Relay' */
extern CALDATA const volatile float32 cal_NmlBatHeatEnvTemp[2];/* Referenced by: '<S1513>/Constant1' */
extern CALDATA const volatile float32 cal_NmlBatHeatT1[3];/* Referenced by: '<S1513>/Constant2' */
extern CALDATA const volatile float32 cal_NmlBatHeatT2[3];/* Referenced by: '<S1513>/Constant3' */
extern CALDATA const volatile float32 cal_NmlBatHeatTave[3];/* Referenced by: '<S1513>/Constant' */
extern CALDATA const volatile float32 cal_NmlBatHeatTrgTemp;/* Referenced by:
                                                             * '<S650>/Constant6'
                                                             * '<S1513>/Constant4'
                                                             */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsDownSpd;/* Referenced by: '<S457>/Constant' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP1;/* Referenced by: '<S457>/Relay1' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP2;/* Referenced by: '<S457>/Relay1' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP3;/* Referenced by: '<S457>/Relay' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP4;/* Referenced by: '<S457>/Relay' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP5;/* Referenced by: '<S457>/Relay2' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP6;/* Referenced by: '<S457>/Relay2' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP7;/* Referenced by: '<S457>/Relay3' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP8;/* Referenced by: '<S457>/Relay3' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsDownSpd;/* Referenced by: '<S457>/Constant2' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP1;/* Referenced by: '<S457>/Relay9' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP2;/* Referenced by: '<S457>/Relay9' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP3;/* Referenced by: '<S457>/Relay8' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP4;/* Referenced by: '<S457>/Relay8' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP5;/* Referenced by: '<S457>/Relay10' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP6;/* Referenced by: '<S457>/Relay10' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP7;/* Referenced by: '<S457>/Relay11' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP8;/* Referenced by: '<S457>/Relay11' */
extern CALDATA const volatile float32 cal_OHXTempData;/* Referenced by: '<S1833>/Constant' */
extern CALDATA const volatile boolean cal_OHXTempDataEnb;/* Referenced by: '<S1833>/Constant1' */
extern CALDATA const volatile uint16 cal_OHXTempVolAmend_1X[2];
                          /* Referenced by: '<S1728>/cal_OHXTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_OHXTempVolAmend_CUR[2];
                          /* Referenced by: '<S1728>/cal_OHXTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_OpenCoolInletTemp;/* Referenced by: '<S1312>/Constant1' */
extern CALDATA const volatile float32 cal_OpenCtrlCOMPDownlmt;/* Referenced by: '<S569>/Constant4' */
extern CALDATA const volatile float32 cal_OpenCtrlCOMPUplmt;/* Referenced by: '<S569>/Constant3' */
extern CALDATA const volatile uint8 cal_OutRecTrgPos;/* Referenced by: '<S1866>/Constant' */
extern CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_1X[8];
                       /* Referenced by: '<S547>/cal_PCULimBTMAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_CUR[8];
                       /* Referenced by: '<S547>/cal_PCULimBTMAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_1X[8];
               /* Referenced by: '<S547>/cal_PCULimBTMAndCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_CUR[8];
               /* Referenced by: '<S547>/cal_PCULimBTMAndCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_1X[8];
                     /* Referenced by: '<S547>/cal_PCULimCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_CUR[8];
                     /* Referenced by: '<S547>/cal_PCULimCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_1X[7];
                  /* Referenced by: '<S1292>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_CUR[7];
                  /* Referenced by: '<S1292>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2X[6];
                          /* Referenced by: '<S584>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2Y[6];
                          /* Referenced by: '<S584>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_MAP[36];
                          /* Referenced by: '<S584>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_1X[9];
                          /* Referenced by: '<S956>/cal_PTCBatHeatPwrLmt_CUR' */
extern CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_CUR[9];
                          /* Referenced by: '<S956>/cal_PTCBatHeatPwrLmt_CUR' */
extern CALDATA const volatile uint8 cal_PTCDelOffTime;/* Referenced by: '<S956>/Constant12' */
extern CALDATA const volatile uint8 cal_PTCEnableData;/* Referenced by: '<S1022>/Constant' */
extern CALDATA const volatile boolean cal_PTCEnableDataEnb;/* Referenced by: '<S1022>/Constant1' */
extern CALDATA const volatile float32 cal_PTCMaxTemp;/* Referenced by: '<S446>/Constant1' */
extern CALDATA const volatile float32 cal_PTCMinTemp;/* Referenced by: '<S446>/Constant3' */
extern CALDATA const volatile uint8 cal_PTCOffAcPMPSpd;/* Referenced by: '<S1031>/Constant16' */
extern CALDATA const volatile float32 cal_PTCOffPowerVal;/* Referenced by: '<S584>/Constant6' */
extern CALDATA const volatile float32 cal_PTCOnReqPower_1X[6];
                             /* Referenced by: '<S584>/cal_PTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_PTCOnReqPower_CUR[6];
                             /* Referenced by: '<S584>/cal_PTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_PTCPwrOffFlt;/* Referenced by: '<S956>/Constant11' */
extern CALDATA const volatile float32 cal_PTCReqTempData;/* Referenced by: '<S953>/Constant' */
extern CALDATA const volatile boolean cal_PTCReqTempDataEnb;/* Referenced by: '<S953>/Constant1' */
extern CALDATA const volatile float32 cal_PTCReqtPowerData;/* Referenced by: '<S1029>/Constant' */
extern CALDATA const volatile boolean cal_PTCReqtPowerDataEnb;/* Referenced by: '<S1029>/Constant1' */
extern CALDATA const volatile uint8 cal_PTCRunAcPMPFFSpd;/* Referenced by:
                                                          * '<S1031>/Constant12'
                                                          * '<S1031>/Constant14'
                                                          */
extern CALDATA const volatile float32 cal_PTCRunAcPMPFFTime;/* Referenced by: '<S1031>/Constant15' */
extern CALDATA const volatile float32 cal_PTCTempRecircOff;/* Referenced by: '<S134>/Constant5' */
extern CALDATA const volatile float32 cal_PTCTempRecircOn;/* Referenced by: '<S134>/Constant6' */
extern CALDATA const volatile float32 cal_PressRateVal1;/* Referenced by: '<S534>/Relay' */
extern CALDATA const volatile float32 cal_PressRateVal1Relay;/* Referenced by: '<S534>/Relay' */
extern CALDATA const volatile float32 cal_PressRateVal2;/* Referenced by:
                                                         * '<S532>/Relay1'
                                                         * '<S534>/Relay1'
                                                         */
extern CALDATA const volatile float32 cal_PressRateVal2Relay;/* Referenced by:
                                                              * '<S532>/Relay1'
                                                              * '<S534>/Relay1'
                                                              */
extern CALDATA const volatile float32 cal_PressRateVal3;/* Referenced by:
                                                         * '<S529>/Relay2'
                                                         * '<S532>/Relay2'
                                                         * '<S534>/Relay2'
                                                         * '<S536>/Relay1'
                                                         */
extern CALDATA const volatile float32 cal_PressRateVal3Relay;/* Referenced by:
                                                              * '<S529>/Relay2'
                                                              * '<S532>/Relay2'
                                                              * '<S534>/Relay2'
                                                              */
extern CALDATA const volatile float32 cal_PressRateVal4;/* Referenced by: '<S536>/Relay1' */
extern CALDATA const volatile float32 cal_PsDVTWeight;
                    /* Referenced by: '<S60>/ACCtl_facLeftBlowerFanSpdWeight' */
extern CALDATA const volatile float32 cal_PsDuctFaceFloorFaFactor;/* Referenced by: '<S229>/Constant3' */
extern CALDATA const volatile float32 cal_PsDuctFaceFloorFoFactor;/* Referenced by: '<S229>/Constant4' */
extern CALDATA const volatile float32 cal_PsDuctSensorFailDeflt;
                       /* Referenced by: '<S177>/cal_PsDuctSensorFailDefault' */
extern CALDATA const volatile float32 cal_PsEnv4SetSelect;/* Referenced by: '<S187>/Constant3' */
extern CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOff;
/* Referenced by: '<S417>/On:cal_PsErrOfEvaDVT2CoolMixOn Off:cal_PsErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOn;
/* Referenced by: '<S417>/On:cal_PsErrOfEvaDVT2CoolMixOn Off:cal_PsErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOff;
/* Referenced by: '<S417>/On:cal_PsErrOfPtcDVT2HeatMixOn Off:cal_PsErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOn;
/* Referenced by: '<S417>/On:cal_PsErrOfPtcDVT2HeatMixOn Off:cal_PsErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandNeg;/* Referenced by: '<S308>/Kp12' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandPos;/* Referenced by: '<S308>/Kp11' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKi;/* Referenced by: '<S308>/Kp7' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKiNeg;/* Referenced by: '<S308>/Kp9' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKiPos;/* Referenced by: '<S308>/Kp10' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKp;/* Referenced by: '<S308>/Kp' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKpNeg;/* Referenced by: '<S308>/Kp1' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKpPos;/* Referenced by: '<S308>/Kp2' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL;/* Referenced by: '<S308>/Kp6' */
extern CALDATA const volatile uint8 cal_PsEvaDesValPIDLL_2X[4];
                          /* Referenced by: '<S278>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL_2Y[7];
                          /* Referenced by: '<S278>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL_MAP[28];
                          /* Referenced by: '<S278>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDUL;/* Referenced by: '<S308>/Kp5' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMax;/* Referenced by: '<S308>/Kp8' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMin;/* Referenced by: '<S308>/Kp13' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_pWinNeg;/* Referenced by: '<S308>/Kp4' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_pWinPos;/* Referenced by: '<S308>/Kp3' */
extern CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_1X[4];
                      /* Referenced by: '<S308>/cal_PsEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_CUR[4];
                      /* Referenced by: '<S308>/cal_PsEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetAC_1X[8];
                             /* Referenced by: '<S417>/cal_PsMixBacSetAC_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetAC_CUR[8];
                             /* Referenced by: '<S417>/cal_PsMixBacSetAC_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetBi_1X[8];
                             /* Referenced by: '<S417>/cal_PsMixBacSetBi_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetBi_CUR[8];
                             /* Referenced by: '<S417>/cal_PsMixBacSetBi_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetDefog_1X[8];
                          /* Referenced by: '<S417>/cal_PsMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetDefog_CUR[8];
                          /* Referenced by: '<S417>/cal_PsMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFootDe_1X[8];
                         /* Referenced by: '<S417>/cal_PsMixBacSetFootDe_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFootDe_CUR[8];
                         /* Referenced by: '<S417>/cal_PsMixBacSetFootDe_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFoot_1X[8];
                           /* Referenced by: '<S417>/cal_PsMixBacSetFoot_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFoot_CUR[8];
                           /* Referenced by: '<S417>/cal_PsMixBacSetFoot_CUR' */
extern CALDATA const volatile float32 cal_PsMixDesValPIDIntegDeadBand;/* Referenced by: '<S418>/Kp11' */
extern CALDATA const volatile uint8 cal_PsMixDesValPIDLL;/* Referenced by: '<S418>/Kp6' */
extern CALDATA const volatile uint8 cal_PsMixDesValPIDUL;/* Referenced by: '<S418>/Kp5' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_IsumMax;/* Referenced by: '<S418>/Kp8' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_IsumMin;/* Referenced by: '<S418>/Kp13' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_Ki;/* Referenced by: '<S418>/Kp7' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KiNeg;/* Referenced by: '<S418>/Kp9' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KiPos;/* Referenced by: '<S418>/Kp10' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_Kp;/* Referenced by: '<S418>/Kp' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KpNeg;/* Referenced by: '<S418>/Kp1' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KpPos;/* Referenced by: '<S418>/Kp2' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_pWinNeg;/* Referenced by: '<S418>/Kp4' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_pWinPos;/* Referenced by: '<S418>/Kp3' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4InHeat;/* Referenced by: '<S366>/Kp16' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4OutHeat;/* Referenced by: '<S366>/Kp24' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKi;/* Referenced by: '<S366>/Kp7' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKiNeg;/* Referenced by: '<S366>/Kp9' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKiPos;/* Referenced by: '<S366>/Kp10' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKp;/* Referenced by: '<S366>/Kp' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKpNeg;/* Referenced by: '<S366>/Kp1' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKpPos;/* Referenced by: '<S366>/Kp2' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDLL;/* Referenced by: '<S366>/Kp6' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDUL;/* Referenced by: '<S366>/Kp5' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMax;/* Referenced by: '<S366>/Kp8' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMin;/* Referenced by: '<S366>/Kp13' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_pWinNeg;/* Referenced by: '<S366>/Kp4' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_pWinPos;/* Referenced by: '<S366>/Kp3' */
extern CALDATA const volatile boolean cal_PtcEnable;/* Referenced by:
                                                     * '<S388>/Constant5'
                                                     * '<S389>/Constant5'
                                                     */
extern CALDATA const volatile float32 cal_PtcPwrDesValPIDDeadBandNeg;/* Referenced by: '<S96>/Constant6' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPIDDeadBandPos;/* Referenced by: '<S96>/Constant7' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_IsumMax;/* Referenced by: '<S96>/Kp8' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_IsumMin;/* Referenced by: '<S96>/Kp13' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_Ki;/* Referenced by: '<S96>/Kp7' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KiNeg;/* Referenced by: '<S96>/Kp9' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KiPos;/* Referenced by: '<S96>/Kp10' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_Kp;/* Referenced by: '<S96>/Kp' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KpNeg;/* Referenced by: '<S96>/Kp1' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KpPos;/* Referenced by: '<S96>/Kp2' */
extern CALDATA const volatile uint16 cal_PtcPwrDesValPID_LL;/* Referenced by: '<S96>/Kp6' */
extern CALDATA const volatile uint16 cal_PtcPwrDesValPID_UL;/* Referenced by: '<S96>/Kp5' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_pWinNeg;/* Referenced by: '<S96>/Kp4' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_pWinPos;/* Referenced by: '<S96>/Kp3' */
extern CALDATA const volatile boolean cal_PwrACPumpData;/* Referenced by: '<S1250>/Constant' */
extern CALDATA const volatile boolean cal_PwrACPumpEnb;/* Referenced by: '<S1250>/Constant1' */
extern CALDATA const volatile boolean cal_PwrBlwData;/* Referenced by: '<S1253>/Constant' */
extern CALDATA const volatile boolean cal_PwrBlwEnb;/* Referenced by: '<S1253>/Constant1' */
extern CALDATA const volatile uint8 cal_PwrFanAndPumpData;/* Referenced by: '<S1261>/Constant' */
extern CALDATA const volatile boolean cal_PwrFanAndPumpDataEnb;/* Referenced by: '<S1261>/Constant1' */
extern CALDATA const volatile boolean cal_PwrFanData;/* Referenced by: '<S1245>/Constant' */
extern CALDATA const volatile boolean cal_PwrFanEnb;/* Referenced by: '<S1245>/Constant1' */
extern CALDATA const volatile boolean cal_PwrHVPartData;/* Referenced by: '<S1264>/Constant' */
extern CALDATA const volatile boolean cal_PwrHVPartEnb;/* Referenced by: '<S1264>/Constant1' */
extern CALDATA const volatile float32 cal_PwrOffsetVal;/* Referenced by:
                                                        * '<S33>/Constant4'
                                                        * '<S33>/Constant5'
                                                        */
extern CALDATA const volatile boolean cal_PwrSensorData;/* Referenced by: '<S1246>/Constant' */
extern CALDATA const volatile boolean cal_PwrSensorEnb;/* Referenced by: '<S1246>/Constant1' */
extern CALDATA const volatile float32 cal_REC_DVTFresh;/* Referenced by: '<S138>/Constant6' */
extern CALDATA const volatile float32 cal_REC_DVTRecirc;/* Referenced by: '<S138>/Constant5' */
extern CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_1X[14];
                       /* Referenced by: '<S82>/cal_RFace2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_CUR[14];
                       /* Referenced by: '<S82>/cal_RFace2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_1X[14];
                       /* Referenced by: '<S82>/cal_RFaceFloor2FaceByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_CUR[14];
                       /* Referenced by: '<S82>/cal_RFaceFloor2FaceByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_1X[14];
                      /* Referenced by: '<S82>/cal_RFaceFloor2FloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_CUR[14];
                      /* Referenced by: '<S82>/cal_RFaceFloor2FloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_1X[14];
                      /* Referenced by: '<S82>/cal_RFloor2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_CUR[14];
                      /* Referenced by: '<S82>/cal_RFloor2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RecirActVal_1X[2];
                              /* Referenced by: '<S1216>/cal_RecirActVal_CUR' */
extern CALDATA const volatile uint8 cal_RecirActVal_CUR[2];
                              /* Referenced by: '<S1216>/cal_RecirActVal_CUR' */
extern CALDATA const volatile float32 cal_RecircDoorNErr;/* Referenced by: '<S1866>/Judge' */
extern CALDATA const volatile float32 cal_RecircDoorPErr;/* Referenced by: '<S1866>/Judge' */
extern CALDATA const volatile uint16 cal_RecircDoorVolAmend_1X[2];
                       /* Referenced by: '<S1216>/cal_RecircDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_RecircDoorVolAmend_CUR[2];
                       /* Referenced by: '<S1216>/cal_RecircDoorVolAmend_CUR' */
extern CALDATA const volatile boolean cal_RecircMotorEnb;/* Referenced by:
                                                          * '<S1866>/Judge'
                                                          * '<S1866>/Constant6'
                                                          * '<S1873>/Constant1'
                                                          * '<S1874>/Constant1'
                                                          */
extern CALDATA const volatile uint8 cal_RecircMotorNData;/* Referenced by: '<S1873>/Constant' */
extern CALDATA const volatile uint8 cal_RecircMotorPData;/* Referenced by: '<S1874>/Constant' */
extern CALDATA const volatile uint8 cal_RecircTrgPosData;/* Referenced by: '<S1875>/Constant' */
extern CALDATA const volatile boolean cal_RecircTrgPosDataEnb;/* Referenced by:
                                                               * '<S1866>/Constant5'
                                                               * '<S1875>/Constant1'
                                                               */
extern CALDATA const volatile RefModes cal_RefModeData;/* Referenced by: '<S1711>/Constant' */
extern CALDATA const volatile boolean cal_RefModeEnb;/* Referenced by: '<S1711>/Constant1' */
extern CALDATA const volatile boolean cal_RemtACDefEnbData;/* Referenced by:
                                                            * '<S1136>/Constant'
                                                            * '<S1136>/Constant1'
                                                            */
extern CALDATA const volatile boolean cal_RemtACEnb;/* Referenced by: '<S1137>/Constant1' */
extern CALDATA const volatile boolean cal_RemtACEnbData;/* Referenced by: '<S1137>/Constant' */
extern CALDATA const volatile uint16 cal_RiseTime2EnvTamb;
                                      /* Referenced by: '<S182>/TempRampStep' */
extern CALDATA const volatile uint16 cal_RiseTime2Solar;
                                     /* Referenced by: '<S187>/TempRampStep1' */
extern CALDATA const volatile uint16 cal_RiseTime2Tamb;
                                     /* Referenced by: '<S1717>/TempRampStep' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOff;/* Referenced by: '<S956>/Relay' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOn;/* Referenced by: '<S956>/Relay' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_1X[6];
                          /* Referenced by: '<S956>/cal_SOCHighPTCPwrLmt_CUR' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_CUR[6];
                          /* Referenced by: '<S956>/cal_SOCHighPTCPwrLmt_CUR' */
extern CALDATA const volatile boolean cal_SOVData;/* Referenced by: '<S1266>/Constant' */
extern CALDATA const volatile boolean cal_SOVEnb;/* Referenced by: '<S1266>/Constant1' */
extern CALDATA const volatile float32 cal_SensorTempDownFlg;/* Referenced by:
                                                             * '<S1739>/Constant1'
                                                             * '<S1759>/Constant1'
                                                             * '<S1769>/Constant1'
                                                             * '<S1791>/Constant1'
                                                             * '<S1801>/Constant1'
                                                             * '<S1810>/Constant1'
                                                             * '<S1820>/Constant1'
                                                             * '<S1828>/Constant1'
                                                             * '<S1836>/Constant1'
                                                             * '<S1845>/Constant1'
                                                             * '<S1863>/Constant1'
                                                             */
extern CALDATA const volatile float32 cal_SensorTempUpFlt;/* Referenced by:
                                                           * '<S1739>/Constant'
                                                           * '<S1759>/Constant'
                                                           * '<S1769>/Constant'
                                                           * '<S1791>/Constant'
                                                           * '<S1801>/Constant'
                                                           * '<S1810>/Constant'
                                                           * '<S1820>/Constant'
                                                           * '<S1828>/Constant'
                                                           * '<S1836>/Constant'
                                                           * '<S1845>/Constant'
                                                           * '<S1863>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_SensorVolDownFlg;/* Referenced by:
                                                            * '<S1220>/Constant1'
                                                            * '<S1227>/Constant1'
                                                            * '<S1234>/Constant1'
                                                            * '<S1776>/Constant1'
                                                            * '<S1781>/Constant1'
                                                            * '<S1853>/Constant1'
                                                            */
extern CALDATA const volatile float32 cal_SensorVolUpFlg;/* Referenced by:
                                                          * '<S1220>/Constant'
                                                          * '<S1227>/Constant'
                                                          * '<S1234>/Constant'
                                                          * '<S1776>/Constant'
                                                          * '<S1781>/Constant'
                                                          * '<S1853>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_SetLeftMixDoorTrgData;/* Referenced by: '<S1882>/Constant' */
extern CALDATA const volatile boolean cal_SetLeftMixDoorTrgDataEnb;/* Referenced by:
                                                                    * '<S1867>/Constant5'
                                                                    * '<S1882>/Constant1'
                                                                    */
extern CALDATA const volatile float32 cal_SetPtcDesCoff;/* Referenced by: '<S181>/Constant5' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMax_2X[10];
                          /* Referenced by: '<S181>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile uint8 cal_SetPtcDesTempMax_2Y[10];
                          /* Referenced by: '<S181>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMax_MAP[100];
                          /* Referenced by: '<S181>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMin;/* Referenced by: '<S181>/Constant8' */
extern CALDATA const volatile uint16 cal_SolarData;/* Referenced by: '<S1780>/Constant' */
extern CALDATA const volatile boolean cal_SolarEnb;/* Referenced by: '<S1780>/Constant1' */
extern CALDATA const volatile uint16 cal_SolarFalseStep;
                           /* Referenced by: '<S212>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile uint16 cal_SolarRiseStep;
                           /* Referenced by: '<S212>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile float32 cal_SolarValRaw_1X[11];
                              /* Referenced by: '<S1722>/cal_SolarValRaw_CUR' */
extern CALDATA const volatile uint16 cal_SolarValRaw_CUR[11];
                              /* Referenced by: '<S1722>/cal_SolarValRaw_CUR' */
extern CALDATA const volatile uint16 cal_SolorVolAmend_1X[2];
                            /* Referenced by: '<S1722>/cal_SolorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_SolorVolAmend_CUR[2];
                            /* Referenced by: '<S1722>/cal_SolorVolAmend_CUR' */
extern CALDATA const volatile float32 cal_StartPrsProTimes;/* Referenced by: '<S457>/Constant4' */
extern CALDATA const volatile float32 cal_SuperHeatFilter;/* Referenced by:
                                                           * '<S905>/Constant1'
                                                           * '<S906>/Constant1'
                                                           * '<S907>/Constant1'
                                                           * '<S909>/Constant1'
                                                           */
extern CALDATA const volatile float32 cal_SuperHeat_1X[28];
                                 /* Referenced by: '<S685>/cal_SuperHeat_CUR' */
extern CALDATA const volatile float32 cal_SuperHeat_CUR[28];
                                 /* Referenced by: '<S685>/cal_SuperHeat_CUR' */
extern CALDATA const volatile float32 cal_TACCMOutRaw_1X[30];
                                  /* Referenced by: '<S1731>/cal_ACCMTHi_CUR' */
extern CALDATA const volatile float32 cal_TACCMOutRaw_CUR[30];
                                  /* Referenced by: '<S1731>/cal_ACCMTHi_CUR' */
extern CALDATA const volatile float32 cal_TCabinRaw_1X[27];
                                /* Referenced by: '<S1715>/cal_TCabinRaw_CUR' */
extern CALDATA const volatile float32 cal_TCabinRaw_CUR[27];
                                /* Referenced by: '<S1715>/cal_TCabinRaw_CUR' */
extern CALDATA const volatile float32 cal_TChillOutRaw_1X[27];
                             /* Referenced by: '<S1723>/cal_TChillOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TChillOutRaw_CUR[27];
                             /* Referenced by: '<S1723>/cal_TChillOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TDuctRaw_1X[26];/* Referenced by:
                                                           * '<S1719>/cal_TDuctRaw_CUR'
                                                           * '<S1720>/cal_TDuctRaw_CUR'
                                                           */
extern CALDATA const volatile float32 cal_TDuctRaw_CUR[26];/* Referenced by:
                                                            * '<S1719>/cal_TDuctRaw_CUR'
                                                            * '<S1720>/cal_TDuctRaw_CUR'
                                                            */
extern CALDATA const volatile float32 cal_TEnvRaw_1X[27];
                                  /* Referenced by: '<S1724>/cal_TEnvRaw_CUR' */
extern CALDATA const volatile float32 cal_TEnvRaw_CUR[27];
                                  /* Referenced by: '<S1724>/cal_TEnvRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapOutRaw_1X[30];
                              /* Referenced by: '<S1725>/cal_TEvapOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapOutRaw_CUR[30];
                              /* Referenced by: '<S1725>/cal_TEvapOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapSurfRaw_1X[23];
                                 /* Referenced by: '<S1726>/cal_TEvapSur_CUR' */
extern CALDATA const volatile float32 cal_TEvapSurfRaw_CUR[23];
                                 /* Referenced by: '<S1726>/cal_TEvapSur_CUR' */
extern CALDATA const volatile float32 cal_TLCCOutRaw_1X[20];
                                /* Referenced by: '<S1729>/cal_WCCTHiRaw_CUR' */
extern CALDATA const volatile float32 cal_TLCCOutRaw_CUR[20];
                                /* Referenced by: '<S1729>/cal_WCCTHiRaw_CUR' */
extern CALDATA const volatile PwrModes cal_TMSStatusData;/* Referenced by: '<S1285>/Constant' */
extern CALDATA const volatile uint8 cal_TMSStatusEnb;/* Referenced by: '<S1285>/Constant1' */
extern CALDATA const volatile float32 cal_TMotEntRaw_1X[17];
                                     /* Referenced by: '<S1727>/cal_TMot_CUR' */
extern CALDATA const volatile float32 cal_TMotEntRaw_CUR[17];
                                     /* Referenced by: '<S1727>/cal_TMot_CUR' */
extern CALDATA const volatile float32 cal_TOHXOutRaw_1X[30];
                                  /* Referenced by: '<S1728>/cal_OHXTRaw_CUR' */
extern CALDATA const volatile float32 cal_TOHXOutRaw_CUR[30];
                                  /* Referenced by: '<S1728>/cal_OHXTRaw_CUR' */
extern CALDATA const volatile float32 cal_TSACBatMinEntTempA;/* Referenced by: '<S1356>/Constant' */
extern CALDATA const volatile float32 cal_TSACBatMinEntTempB;/* Referenced by: '<S1630>/Constant' */
extern CALDATA const volatile float32 cal_TSACBatMinExitTempM;/* Referenced by: '<S1624>/Constant4' */
extern CALDATA const volatile float32 cal_TSACBatMinExitTempN;/* Referenced by: '<S1367>/Constant4' */
extern CALDATA const volatile float32 cal_TSBatInletTempOffsetP;/* Referenced by: '<S1362>/Constant1' */
extern CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_1X[5];
                  /* Referenced by: '<S1361>/cal_TSBatMaxTempForEnvExitC_CUR' */
extern CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_CUR[5];
                  /* Referenced by: '<S1361>/cal_TSBatMaxTempForEnvExitC_CUR' */
extern CALDATA const volatile float32 cal_TSBatMinExitTempJ;/* Referenced by: '<S1366>/Constant4' */
extern CALDATA const volatile float32 cal_TSBatMinTempOffsetD;/* Referenced by: '<S1362>/Constant5' */
extern CALDATA const volatile float32 cal_TSBatMinTemplowValB;/* Referenced by: '<S1352>/Constant2' */
extern CALDATA const volatile float32 cal_TSDCBatMinEntTempC;/* Referenced by: '<S1631>/Constant' */
extern CALDATA const volatile float32 cal_TSDCBatMinExitTempK;/* Referenced by: '<S1623>/Constant4' */
extern CALDATA const volatile float32 cal_TSIGBTMinTempEntC;/* Referenced by: '<S1352>/Constant3' */
extern CALDATA const volatile float32 cal_TSIGBTMinTempExitG;/* Referenced by: '<S1363>/Constant3' */
extern CALDATA const volatile float32 cal_TSIPUExitTempI;/* Referenced by:
                                                          * '<S1365>/Constant'
                                                          * '<S1625>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_TSMotorMinTempEntC;/* Referenced by: '<S1352>/Constant' */
extern CALDATA const volatile float32 cal_TSMotorMinTempExitH;/* Referenced by: '<S1364>/Constant' */
extern CALDATA const volatile float32 cal_TempRampStepFast;/* Referenced by: '<S1717>/Constant2' */
extern CALDATA const volatile float32 cal_TempRampStepLoVSpeed;
                                    /* Referenced by: '<S1717>/TempRampStep4' */
extern CALDATA const volatile float32 cal_TempRampStepSlow;/* Referenced by: '<S1717>/Constant1' */
extern CALDATA const volatile float32 cal_TevapLoStepMin;/* Referenced by:
                                                          * '<S180>/Constant2'
                                                          * '<S180>/Constant5'
                                                          */
extern CALDATA const volatile uint16 cal_TevapLoTime;/* Referenced by: '<S180>/Constant6' */
extern CALDATA const volatile float32 cal_TevapUpStepMin;/* Referenced by:
                                                          * '<S181>/Constant'
                                                          * '<S181>/Constant3'
                                                          */
extern CALDATA const volatile uint16 cal_TevapUpTime;
                                    /* Referenced by: '<S181>/PTCHeatedCheck' */
extern CALDATA const volatile float32 cal_U_DVTFFSolarFilterRate;/* Referenced by:
                                                                  * '<S183>/ACCtrl_facSolarFlt_C'
                                                                  * '<S184>/ACCtrl_facSolarFlt_C'
                                                                  * '<S187>/ACCtrl_facSolarFlt_C'
                                                                  */
extern CALDATA const volatile boolean cal_UnlockVentEnb;/* Referenced by: '<S1290>/Constant1' */
extern CALDATA const volatile boolean cal_UnlockVentEnbData;/* Referenced by: '<S1290>/Constant' */
extern CALDATA const volatile uint16 cal_UpAndDownStartTime;
                           /* Referenced by: '<S212>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile float32 cal_VehHeatSOCOff;/* Referenced by:
                                                         * '<S1344>/Constant'
                                                         * '<S1449>/Constant'
                                                         * '<S1575>/Constant'
                                                         * '<S1587>/Constant'
                                                         * '<S1494>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_VehHeatSOCOn;/* Referenced by:
                                                        * '<S1350>/Constant'
                                                        * '<S1432>/Constant'
                                                        * '<S1568>/Constant'
                                                        * '<S1582>/Constant'
                                                        * '<S1483>/Constant'
                                                        */
extern CALDATA const volatile float32 cal_VehicleSpeedHighVs;/* Referenced by: '<S1742>/Constant' */
extern CALDATA const volatile float32 cal_VehicleSpeedLowVs;/* Referenced by: '<S1743>/Constant' */
extern CALDATA const volatile uint16 cal_WCCHPVolAmend_1X[2];
                            /* Referenced by: '<S1730>/cal_WCCHPVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCHPVolAmend_CUR[2];
                            /* Referenced by: '<S1730>/cal_WCCHPVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_WCCHighTempVolAmend_1X[2];
                      /* Referenced by: '<S1729>/cal_WCCHighTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCHighTempVolAmend_CUR[2];
                      /* Referenced by: '<S1729>/cal_WCCHighTempVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_WCCLPVolAmend_1X[2];
                            /* Referenced by: '<S1721>/cal_WCCLPVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCLPVolAmend_CUR[2];
                            /* Referenced by: '<S1721>/cal_WCCLPVolAmend_CUR' */
extern CALDATA const volatile float32 cal_WCCTempData;/* Referenced by: '<S1843>/Constant' */
extern CALDATA const volatile boolean cal_WCCTempDataEnb;/* Referenced by: '<S1843>/Constant1' */
extern CALDATA const volatile WaterModes cal_WaterModeData;/* Referenced by: '<S1703>/Constant' */
extern CALDATA const volatile boolean cal_WaterModeEnb;/* Referenced by: '<S1703>/Constant1' */
extern CALDATA const volatile boolean cal_bACAutoData;/* Referenced by: '<S1169>/Constant' */
extern CALDATA const volatile boolean cal_bACAutoEnb;/* Referenced by: '<S1169>/Constant1' */
extern CALDATA const volatile boolean cal_bACDefrostData;/* Referenced by: '<S1183>/Constant' */
extern CALDATA const volatile boolean cal_bACDefrostEnb;/* Referenced by: '<S1183>/Constant1' */
extern CALDATA const volatile boolean cal_bACOnOffData;/* Referenced by: '<S1196>/Constant' */
extern CALDATA const volatile boolean cal_bACOnOffEnb;/* Referenced by: '<S1196>/Constant1' */
extern CALDATA const volatile boolean cal_bExhFlgData;/* Referenced by: '<S1094>/Constant' */
extern CALDATA const volatile boolean cal_bExhFlgEnb;/* Referenced by: '<S1094>/Constant1' */
extern CALDATA const volatile boolean cal_bLeftSetHighData;/* Referenced by: '<S1148>/Constant' */
extern CALDATA const volatile boolean cal_bLeftSetHighEnb;/* Referenced by: '<S1148>/Constant1' */
extern CALDATA const volatile boolean cal_bLeftSetLowData;/* Referenced by: '<S1149>/Constant' */
extern CALDATA const volatile boolean cal_bLeftSetLowEnb;/* Referenced by: '<S1149>/Constant1' */
extern CALDATA const volatile uint8 cal_eACStsData;/* Referenced by: '<S1208>/Constant' */
extern CALDATA const volatile boolean cal_eACStsEnb;/* Referenced by: '<S1208>/Constant1' */
extern CALDATA const volatile uint8 cal_eBlwStsData;/* Referenced by: '<S1107>/Constant' */
extern CALDATA const volatile boolean cal_eBlwStsEnb;/* Referenced by: '<S1107>/Constant1' */
extern CALDATA const volatile uint8 cal_eC3WVValueData;/* Referenced by: '<S641>/Constant' */
extern CALDATA const volatile boolean cal_eC3WVValueEnb;/* Referenced by: '<S641>/Constant1' */
extern CALDATA const volatile uint8 cal_eC5WVValueData;/* Referenced by: '<S642>/Constant' */
extern CALDATA const volatile boolean cal_eC5WVValueEnb;/* Referenced by: '<S642>/Constant1' */
extern CALDATA const volatile uint8 cal_eInnerData;/* Referenced by: '<S1123>/Constant' */
extern CALDATA const volatile boolean cal_eInnerEnb;/* Referenced by: '<S1123>/Constant1' */
extern CALDATA const volatile uint8 cal_eModeMotorData;/* Referenced by: '<S1130>/Constant' */
extern CALDATA const volatile boolean cal_eModeMotorEnb;/* Referenced by: '<S1130>/Constant1' */
extern CALDATA const volatile float32 cal_rCabinCoolToCondMixDoor;/* Referenced by: '<S1668>/Constant' */
extern CALDATA const volatile uint8 cal_rCabinEvpToHPInnRatio;/* Referenced by: '<S1695>/Constant' */
extern CALDATA const volatile uint8 cal_rCabinHPToEvpInnRatio;/* Referenced by: '<S1694>/Constant' */
extern CALDATA const volatile float32 cal_sMixDoorData;/* Referenced by: '<S1125>/Constant' */
extern CALDATA const volatile boolean cal_sMixDoorEnb;/* Referenced by: '<S1125>/Constant1' */
extern CALDATA const volatile float32 cal_tACBatCoolCellTempOn;/* Referenced by: '<S1387>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitACChrgMinCellTemp;/* Referenced by: '<S1347>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitBal1ToBatDiff;/* Referenced by: '<S1340>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitBatToBal2Diff;/* Referenced by: '<S1337>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitDCChrgMinCellTemp;/* Referenced by: '<S1342>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitMaxToMinCellDiff;/* Referenced by: '<S1345>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalONACChrgMinCellTemp;/* Referenced by: '<S1335>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolACChrgCellTempOff;/* Referenced by: '<S1415>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolCellTempOn;/* Referenced by: '<S1399>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolDCChrgCellTempOff;/* Referenced by: '<S1414>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolVehReadyCellTempOff;/* Referenced by: '<S1416>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOff;/* Referenced by: '<S1505>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOn;/* Referenced by: '<S1469>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOff;/* Referenced by: '<S1508>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOn;/* Referenced by: '<S1472>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOff;/* Referenced by: '<S1503>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOn;/* Referenced by: '<S1468>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatExitMaxToMinCellDiff;/* Referenced by:
                                                                      * '<S1336>/Constant'
                                                                      * '<S1343>/Constant'
                                                                      * '<S1349>/Constant'
                                                                      * '<S1368>/Constant'
                                                                      * '<S1567>/Constant'
                                                                      * '<S1573>/Constant'
                                                                      * '<S1577>/Constant'
                                                                      * '<S1581>/Constant'
                                                                      * '<S1586>/Constant'
                                                                      * '<S1597>/Constant'
                                                                      * '<S1601>/Constant'
                                                                      * '<S1608>/Constant'
                                                                      * '<S1632>/Constant'
                                                                      * '<S1355>/Constant'
                                                                      * '<S1357>/Constant'
                                                                      * '<S1390>/Constant'
                                                                      * '<S1400>/Constant'
                                                                      * '<S1407>/Constant'
                                                                      * '<S1443>/Constant'
                                                                      * '<S1453>/Constant'
                                                                      * '<S1473>/Constant'
                                                                      * '<S1484>/Constant'
                                                                      * '<S1492>/Constant'
                                                                      * '<S1544>/Constant'
                                                                      * '<S1555>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOff;/* Referenced by: '<S1507>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOn;/* Referenced by: '<S1482>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToCoolDvtDiff;/* Referenced by: '<S1663>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToCoolEvapTemp;/* Referenced by: '<S1666>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToEvpEvapTemp;/* Referenced by: '<S1684>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCoolEnvTempHigh;/* Referenced by:
                                                                 * '<S1653>/Constant'
                                                                 * '<S1653>/Constant2'
                                                                 * '<S1653>/Constant9'
                                                                 * '<S1674>/Constant10'
                                                                 * '<S1675>/Constant2'
                                                                 * '<S1675>/Constant3'
                                                                 */
extern CALDATA const volatile float32 cal_tCabinCoolEnvTempLow;/* Referenced by:
                                                                * '<S1653>/Constant1'
                                                                * '<S1653>/Constant3'
                                                                * '<S1653>/Constant5'
                                                                * '<S1658>/Constant1'
                                                                * '<S1658>/Constant5'
                                                                * '<S1685>/Constant'
                                                                * '<S1673>/Constant1'
                                                                * '<S1675>/Constant5'
                                                                * '<S1676>/Constant13'
                                                                * '<S1677>/Constant11'
                                                                * '<S1688>/Constant5'
                                                                * '<S1689>/Constant13'
                                                                */
extern CALDATA const volatile float32 cal_tCabinCoolToCondDvtDiff;/* Referenced by: '<S1667>/Constant' */
extern CALDATA const volatile float32 cal_tCabinEvpToCondDvtDiff;/* Referenced by:
                                                                  * '<S1680>/Constant'
                                                                  * '<S1681>/Constant'
                                                                  */
extern CALDATA const volatile float32 cal_tCabinHPToEvpEnvTemp;/* Referenced by: '<S1693>/Constant' */
extern CALDATA const volatile float32 cal_tDCBatCoolCellTempOn;/* Referenced by: '<S1386>/Constant' */
extern CALDATA const volatile float32 cal_tLTROffBatBal2ToMaxCellDiff;/* Referenced by:
                                                                      * '<S1451>/Constant'
                                                                      * '<S1551>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tLTROffIPUTemp;/* Referenced by: '<S1446>/Constant' */
extern CALDATA const volatile float32 cal_tLTROnDCChrgMaxCellTemp;/* Referenced by:
                                                                   * '<S1438>/Constant'
                                                                   * '<S1440>/Constant'
                                                                   * '<S1540>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tLTROnDCChrgMinCellTemp;/* Referenced by:
                                                                   * '<S1441>/Constant'
                                                                   * '<S1541>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tLTROnIPUTemp;/* Referenced by:
                                                         * '<S1433>/Constant'
                                                         * '<S1534>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_tLTROnMaxCellToMotDiff;/* Referenced by:
                                                                  * '<S1442>/Constant'
                                                                  * '<S1542>/Constant'
                                                                  * '<S1543>/Constant'
                                                                  */
extern CALDATA const volatile float32 cal_tLTROnMotInletTemp;/* Referenced by: '<S1641>/Constant' */
extern CALDATA const volatile float32 cal_tLTROnMotTemp;/* Referenced by: '<S1642>/Constant' */
extern CALDATA const volatile float32 cal_tLeftSetPointData;/* Referenced by: '<S1150>/Constant' */
extern CALDATA const volatile boolean cal_tLeftSetPointEnb;/* Referenced by: '<S1150>/Constant1' */
extern CALDATA const volatile float32 cal_tMotHeatBatACChrgMinCellTempLow;/* Referenced by:
                                                                      * '<S1578>/Constant'
                                                                      * '<S1598>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatBatMinCellTempLow;/* Referenced by:
                                                                     * '<S1583>/Constant'
                                                                     * '<S1602>/Constant'
                                                                     */
extern CALDATA const volatile float32 cal_tMotHeatExitMinCellToBal1Diff;/* Referenced by:
                                                                      * '<S1559>/Constant1'
                                                                      * '<S1594>/Constant1'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatExitMinCellToMotTempDiff;/* Referenced by:
                                                                      * '<S1559>/Constant2'
                                                                      * '<S1594>/Constant2'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatOnMotToMinCellDiff;/* Referenced by:
                                                                      * '<S1557>/Constant1'
                                                                      * '<S1558>/Constant1'
                                                                      * '<S1592>/Constant1'
                                                                      * '<S1593>/Constant1'
                                                                      */
extern CALDATA const volatile float32 cal_tMotStorExitMaxCellTemp;/* Referenced by:
                                                                   * '<S1571>/Constant'
                                                                   * '<S1589>/Constant'
                                                                   * '<S1612>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tMotStorExitMotToMinCellDiff;/* Referenced by: '<S1556>/Constant3' */
extern CALDATA const volatile float32 cal_tMotStorMinCellTempLow;/* Referenced by: '<S1569>/Constant' */
extern CALDATA const volatile float32 cal_tMotStorOnMotToMinCellDiff;/* Referenced by: '<S1556>/Constant1' */
extern CALDATA const volatile uint16 cal_tiAQSFresh2RecircDelay;/* Referenced by: '<S129>/Constant5' */
extern CALDATA const volatile uint16 cal_tiAQSRecirc2FreshDelay;/* Referenced by: '<S129>/Constant11' */
extern CALDATA const volatile uint16 cal_tiCO2Fresh2RecircMax;/* Referenced by: '<S130>/Constant12' */
extern CALDATA const volatile uint16 cal_tiCO2Recirc2FreshMax;/* Referenced by: '<S130>/Constant5' */
extern CALDATA const volatile uint16 cal_tiColdStartTimeMax;/* Referenced by: '<S41>/Constant2' */

#endif                                 /* RTW_HEADER_TMS_CalibrationData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
