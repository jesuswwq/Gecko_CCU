/*
 * File: TMS_CalibrationData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2191
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Oct 11 13:47:24 2024
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
extern CALDATA const volatile uint8 ACDefog;/* Referenced by: '<S388>/Constant7' */
extern CALDATA const volatile uint8 ACOff;/* Referenced by:
                                           * '<S4>/Constant2'
                                           * '<S41>/Constant1'
                                           * '<S41>/Constant5'
                                           * '<S42>/Constant'
                                           * '<S43>/Constant'
                                           * '<S44>/Constant'
                                           * '<S177>/Constant'
                                           * '<S388>/Constant3'
                                           * '<S388>/Constant5'
                                           * '<S93>/Constant'
                                           * '<S125>/Constant'
                                           * '<S132>/Constant1'
                                           * '<S136>/Constant'
                                           * '<S229>/Constant'
                                           */
extern CALDATA const volatile uint8 AC_ColdStart;/* Referenced by: '<S50>/ColdStart' */
extern CALDATA const volatile uint8 AC_HotStart;/* Referenced by:
                                                 * '<S50>/HotStart'
                                                 * '<S51>/HotStart'
                                                 * '<S126>/Constant26'
                                                 */
extern CALDATA const volatile uint8 AC_LittleColdStart;/* Referenced by: '<S50>/ColdStart6' */
extern CALDATA const volatile uint8 BlowerACMode;
                                     /* Referenced by: '<S80>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerBILevelMode;
                                     /* Referenced by: '<S80>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerDefrostMode;
                                     /* Referenced by: '<S80>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerHeaterDefrostMode;
                                     /* Referenced by: '<S80>/AutoBlowerMode' */
extern CALDATA const volatile uint8 BlowerHeaterMode;
                                     /* Referenced by: '<S80>/AutoBlowerMode' */
extern CALDATA const volatile uint8 DriveFRESH;/* Referenced by:
                                                * '<S121>/Constant2'
                                                * '<S121>/Constant3'
                                                * '<S145>/Constant2'
                                                * '<S145>/Constant3'
                                                */
extern CALDATA const volatile uint8 RECIRC;/* Referenced by:
                                            * '<S121>/Constant4'
                                            * '<S145>/Constant4'
                                            */
extern CALDATA const volatile float32 cal_ACBatHeatEnvTemp[2];/* Referenced by: '<S1528>/Constant1' */
extern CALDATA const volatile float32 cal_ACBatHeatT1[3];/* Referenced by: '<S1528>/Constant2' */
extern CALDATA const volatile float32 cal_ACBatHeatT2[3];/* Referenced by: '<S1528>/Constant3' */
extern CALDATA const volatile float32 cal_ACBatHeatTave[3];/* Referenced by: '<S1528>/Constant' */
extern CALDATA const volatile float32 cal_ACBatHeatTrgTemp;/* Referenced by:
                                                            * '<S648>/Constant5'
                                                            * '<S1528>/Constant4'
                                                            */
extern CALDATA const volatile float32 cal_ACCMClsEnvTemp;/* Referenced by: '<S444>/Relay' */
extern CALDATA const volatile float32 cal_ACCMCtlDownlmt;/* Referenced by: '<S567>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtlKiDeadzoneNeg;/* Referenced by: '<S448>/Constant9' */
extern CALDATA const volatile float32 cal_ACCMCtlKiDeadzonePos;/* Referenced by: '<S448>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtlKpDeadzoneNeg;/* Referenced by: '<S448>/Constant10' */
extern CALDATA const volatile float32 cal_ACCMCtlKpDeadzonePos;/* Referenced by: '<S448>/Constant11' */
extern CALDATA const volatile float32 cal_ACCMCtlPID_IsumMax;/* Referenced by: '<S448>/Constant13' */
extern CALDATA const volatile float32 cal_ACCMCtlPID_IsumMin;/* Referenced by: '<S448>/Constant12' */
extern CALDATA const volatile float32 cal_ACCMCtlUplmt;/* Referenced by: '<S567>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlA1FF_1X[6];
                              /* Referenced by: '<S582>/cal_ACCMCtrlA1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlA1FF_CUR[6];
                              /* Referenced by: '<S582>/cal_ACCMCtrlA1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_2X[6];
                             /* Referenced by: '<S582>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_2Y[5];
                             /* Referenced by: '<S582>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlA2FF_MAP[30];
                             /* Referenced by: '<S582>/cal_ACCMCtrlA2FF_MAP ' */
extern CALDATA const volatile float32 cal_ACCMCtrlACct;/* Referenced by:
                                                        * '<S582>/Constant2'
                                                        * '<S584>/Constant2'
                                                        * '<S585>/Constant2'
                                                        * '<S586>/Constant2'
                                                        * '<S587>/Constant2'
                                                        */
extern CALDATA const volatile float32 cal_ACCMCtrlADeadzone;/* Referenced by: '<S582>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlADlyTime;/* Referenced by: '<S582>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKi_1X[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKi_CUR[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKp_1X[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAKp_CUR[8];
                               /* Referenced by: '<S582>/cal_ACCMCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlAPIMax;/* Referenced by: '<S582>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlAPIMin;/* Referenced by: '<S582>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlARunTime;/* Referenced by: '<S582>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlBDeadzone;/* Referenced by: '<S583>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlBDlyTime;/* Referenced by: '<S583>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlBFF_1X[6];
                              /* Referenced by: '<S583>/cal_ACCMCtrlB1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBFF_CUR[6];
                              /* Referenced by: '<S583>/cal_ACCMCtrlB1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKi_1X[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKi_CUR[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKp_1X[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBKp_CUR[8];
                               /* Referenced by: '<S583>/cal_ACCMCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlBPIMax;/* Referenced by: '<S583>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlBPIMin;/* Referenced by: '<S583>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlBRunTime;/* Referenced by: '<S583>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlC1FF_1X[5];
                              /* Referenced by: '<S584>/cal_ACCMCtrlC1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC1FF_CUR[5];
                              /* Referenced by: '<S584>/cal_ACCMCtrlC1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC2FF_1X[4];
                              /* Referenced by: '<S584>/cal_ACCMCtrlC2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlC2FF_CUR[4];
                              /* Referenced by: '<S584>/cal_ACCMCtrlC2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCDeadzone;/* Referenced by: '<S584>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlCDlyTime;/* Referenced by: '<S584>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKi_1X[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKi_CUR[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKp_1X[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCKp_CUR[8];
                               /* Referenced by: '<S584>/cal_ACCMCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlCPIMax;/* Referenced by: '<S584>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlCPIMin;/* Referenced by: '<S584>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlCRunTime;/* Referenced by: '<S584>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlD1FF_1X[3];
                              /* Referenced by: '<S585>/cal_ACCMCtrlD1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD1FF_CUR[3];
                              /* Referenced by: '<S585>/cal_ACCMCtrlD1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD2FF_1X[4];
                              /* Referenced by: '<S585>/cal_ACCMCtrlD2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlD2FF_CUR[4];
                              /* Referenced by: '<S585>/cal_ACCMCtrlD2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDDeadzone;/* Referenced by: '<S585>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlDDlyTime;/* Referenced by: '<S585>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKi_1X[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKi_CUR[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKp_1X[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDKp_CUR[8];
                               /* Referenced by: '<S585>/cal_ACCMCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMax_1X[5];
                            /* Referenced by: '<S585>/cal_ACCMCtrlDPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMax_CUR[5];
                            /* Referenced by: '<S585>/cal_ACCMCtrlDPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDPIMin;/* Referenced by: '<S585>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlDRunTime;/* Referenced by: '<S585>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlDTrg_1X[7];
                              /* Referenced by: '<S585>/cal_ACCMCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlDTrg_CUR[7];
                              /* Referenced by: '<S585>/cal_ACCMCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE1FF_1X[7];
                              /* Referenced by: '<S586>/cal_ACCMCtrlE1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE1FF_CUR[7];
                              /* Referenced by: '<S586>/cal_ACCMCtrlE1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE2FF_1X[4];
                              /* Referenced by: '<S586>/cal_ACCMCtrlE2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlE2FF_CUR[4];
                              /* Referenced by: '<S586>/cal_ACCMCtrlE2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEDeadzone;/* Referenced by: '<S586>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlEDlyTime;/* Referenced by: '<S586>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKi_1X[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKi_CUR[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKp_1X[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEKp_CUR[8];
                               /* Referenced by: '<S586>/cal_ACCMCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlEPIMax;/* Referenced by: '<S586>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlEPIMin;/* Referenced by: '<S586>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlERunTime;/* Referenced by: '<S586>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlETrgTemp;/* Referenced by:
                                                            * '<S586>/Constant4'
                                                            * '<S586>/Constant6'
                                                            */
extern CALDATA const volatile float32 cal_ACCMCtrlF1FF_1X[5];
                              /* Referenced by: '<S587>/cal_ACCMCtrlF1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF1FF_CUR[5];
                              /* Referenced by: '<S587>/cal_ACCMCtrlF1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF2FF_1X[5];
                              /* Referenced by: '<S587>/cal_ACCMCtrlF2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlF2FF_CUR[5];
                              /* Referenced by: '<S587>/cal_ACCMCtrlF2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFDeadzone;/* Referenced by: '<S587>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlFDlyTime;/* Referenced by: '<S587>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKi_1X[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlFKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKi_CUR[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlFKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKp_1X[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlFKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFKp_CUR[8];
                               /* Referenced by: '<S587>/cal_ACCMCtrlFKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMax_1X[5];
                            /* Referenced by: '<S587>/cal_ACCMCtrlFPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMax_CUR[5];
                            /* Referenced by: '<S587>/cal_ACCMCtrlFPIMax_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlFPIMin;/* Referenced by: '<S587>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlFRunTime;/* Referenced by: '<S587>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlH1FF_1X[5];
                              /* Referenced by: '<S589>/cal_ACCMCtrlH1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH1FF_CUR[5];
                              /* Referenced by: '<S589>/cal_ACCMCtrlH1FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH2FF_1X[4];
                              /* Referenced by: '<S589>/cal_ACCMCtrlH2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlH2FF_CUR[4];
                              /* Referenced by: '<S589>/cal_ACCMCtrlH2FF_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHCct;/* Referenced by: '<S589>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlHDeadzone;/* Referenced by: '<S589>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlHDlyTime;/* Referenced by: '<S589>/Constant' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKi_1X[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlHKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKi_CUR[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlHKi_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKp_1X[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlHKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHKp_CUR[8];
                               /* Referenced by: '<S589>/cal_ACCMCtrlHKp_CUR' */
extern CALDATA const volatile float32 cal_ACCMCtrlHPIMax;/* Referenced by: '<S589>/Constant7' */
extern CALDATA const volatile float32 cal_ACCMCtrlHPIMin;/* Referenced by: '<S589>/Constant8' */
extern CALDATA const volatile float32 cal_ACCMCtrlHRunTime;/* Referenced by: '<S589>/Constant1' */
extern CALDATA const volatile float32 cal_ACCMCtrlKi;/* Referenced by: '<S448>/Constant3' */
extern CALDATA const volatile float32 cal_ACCMCtrlKp;/* Referenced by: '<S448>/Constant2' */
extern CALDATA const volatile float32 cal_ACCMCtrlSpdData;/* Referenced by: '<S568>/Constant' */
extern CALDATA const volatile boolean cal_ACCMCtrlSpdDataEnb;/* Referenced by: '<S568>/Constant1' */
extern CALDATA const volatile boolean cal_ACCMEnbData;/* Referenced by: '<S460>/Constant' */
extern CALDATA const volatile boolean cal_ACCMEnbDataEnb;/* Referenced by: '<S460>/Constant1' */
extern CALDATA const volatile boolean cal_ACCMForbidCtrl;/* Referenced by:
                                                          * '<S440>/Constant'
                                                          * '<S947>/Constant3'
                                                          * '<S1684>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_ACCMHiTempData;/* Referenced by: '<S1872>/Constant' */
extern CALDATA const volatile boolean cal_ACCMHiTempDataEnb;/* Referenced by: '<S1872>/Constant1' */
extern CALDATA const volatile uint8 cal_ACCMHiTempFanCtrl;/* Referenced by: '<S917>/Constant5' */
extern CALDATA const volatile float32 cal_ACCMHiTempFanOff;/* Referenced by: '<S917>/Relay' */
extern CALDATA const volatile float32 cal_ACCMHiTempFanOn;/* Referenced by: '<S917>/Relay' */
extern CALDATA const volatile uint16 cal_ACCMHighTempVolAmend_1X[2];
                     /* Referenced by: '<S1755>/cal_ACCMHighTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ACCMHighTempVolAmend_CUR[2];
                     /* Referenced by: '<S1755>/cal_ACCMHighTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ACCMOpenEnvTemp;/* Referenced by: '<S444>/Relay' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2X[12];
                     /* Referenced by: '<S185>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2Y[12];
                     /* Referenced by: '<S185>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_MAP[144];
                     /* Referenced by: '<S185>/cal_ACCabinPreSetByEnvECO_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2X[12];
                        /* Referenced by: '<S185>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2Y[12];
                        /* Referenced by: '<S185>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACCabinPreSetByEnv_MAP[144];
                        /* Referenced by: '<S185>/cal_ACCabinPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACChgBatHighSOCHeat;/* Referenced by:
                                                               * '<S1482>/Relay'
                                                               * '<S1509>/Relay'
                                                               * '<S1388>/Constant'
                                                               * '<S1648>/Constant'
                                                               * '<S1660>/Constant'
                                                               * '<S1662>/Constant'
                                                               * '<S1664>/Constant'
                                                               * '<S1369>/Constant'
                                                               */
extern CALDATA const volatile float32 cal_ACChgBatLowSOCHeat;/* Referenced by:
                                                              * '<S1482>/Relay'
                                                              * '<S1509>/Relay'
                                                              * '<S1390>/Constant'
                                                              * '<S1650>/Constant'
                                                              * '<S1658>/Constant'
                                                              * '<S1367>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_1X[7];
                     /* Referenced by: '<S1533>/cal_ACChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_CUR[7];
                     /* Referenced by: '<S1533>/cal_ACChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForACHotStart;/* Referenced by:
                                                                    * '<S46>/Kp11'
                                                                    * '<S164>/Constant'
                                                                    */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForAQS;/* Referenced by:
                                                             * '<S46>/Kp4'
                                                             * '<S168>/Constant'
                                                             */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForForceChange;/* Referenced by:
                                                                     * '<S46>/Kp3'
                                                                     * '<S128>/Constant11'
                                                                     * '<S128>/Constant9'
                                                                     * '<S162>/Constant'
                                                                     */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForForceDefog;/* Referenced by:
                                                                    * '<S46>/Kp12'
                                                                    * '<S170>/Constant'
                                                                    */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForManual;/* Referenced by:
                                                                * '<S46>/Kp1'
                                                                * '<S171>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForNormalDefog;/* Referenced by:
                                                                     * '<S46>/Kp5'
                                                                     * '<S159>/Constant2'
                                                                     */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForPCUTemp;/* Referenced by:
                                                                 * '<S46>/Kp15'
                                                                 * '<S169>/Constant'
                                                                 */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForPTCDvt;/* Referenced by:
                                                                * '<S46>/Kp10'
                                                                * '<S160>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForQkChargeCooling;/* Referenced by:
                                                                      * '<S46>/Kp14'
                                                                      * '<S161>/Constant'
                                                                      */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForRemoteAC;/* Referenced by:
                                                                  * '<S46>/Kp13'
                                                                  * '<S163>/Constant'
                                                                  */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForSummer;/* Referenced by:
                                                                * '<S46>/Kp8'
                                                                * '<S159>/Constant'
                                                                */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForTargetOutTemp;/* Referenced by:
                                                                      * '<S46>/Kp6'
                                                                      * '<S165>/Constant'
                                                                      */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForTempLow;/* Referenced by:
                                                                 * '<S46>/Kp2'
                                                                 * '<S167>/Constant'
                                                                 */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForVent;/* Referenced by:
                                                              * '<S46>/Kp7'
                                                              * '<S166>/Constant'
                                                              */
extern CALDATA const volatile uint8 cal_ACCtlRecLevelForWinter;/* Referenced by:
                                                                * '<S46>/Kp9'
                                                                * '<S159>/Constant1'
                                                                */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2X[10];
                          /* Referenced by: '<S185>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2Y[10];
                          /* Referenced by: '<S185>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetByEnv_MAP[100];
                          /* Referenced by: '<S185>/cal_ACDVTPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_1X[16];
                         /* Referenced by: '<S185>/cal_ACDVTPreSetEnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_CUR[16];
                         /* Referenced by: '<S185>/cal_ACDVTPreSetEnvCor_CUR' */
extern CALDATA const volatile uint16 cal_ACDVTPreSetSolarCorByVx_2X[6];
                   /* Referenced by: '<S185>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_2Y[6];
                   /* Referenced by: '<S185>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_MAP[36];
                   /* Referenced by: '<S185>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern CALDATA const volatile uint16 cal_ACDVTPreSetSolarCor_2X[8];
                       /* Referenced by: '<S185>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_2Y[8];
                       /* Referenced by: '<S185>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_MAP[64];
                       /* Referenced by: '<S185>/cal_ACDVTPreSetSolarCor_MAP' */
extern CALDATA const volatile uint16 cal_ACDrDVTSolarCor_2X[15];
                           /* Referenced by: '<S181>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDrDVTSolarCor_2Y[15];
                           /* Referenced by: '<S181>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACDrDVTSolarCor_MAP[225];
                           /* Referenced by: '<S181>/cal_ACDrDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanLevel0EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel0EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel0EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel0EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel1EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel1EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel1EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel1EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel2EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel2EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel2EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel2EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel3EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel3EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel3EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel3EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel4EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel4EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel4EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel4EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel5EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel5EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel5EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel5EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel6EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel6EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel6EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel6EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel7EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel7EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel7EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel7EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel8EnvCor_1X[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel8EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanLevel8EnvCor_CUR[2];
                          /* Referenced by: '<S52>/cal_ACFanLevel8EnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanMaxSpdCellTempLim_1X[5];
                         /* Referenced by: '<S50>/cal_ACFanMaxSpdCellTempLim' */
extern CALDATA const volatile uint8 cal_ACFanMaxSpdCellTempLim_CUR[5];
                         /* Referenced by: '<S50>/cal_ACFanMaxSpdCellTempLim' */
extern CALDATA const volatile float32 cal_ACFanMaxSpdDvtLim_1X[5];
                          /* Referenced by: '<S50>/cal_ACFanMaxSpdDvtLim_CUR' */
extern CALDATA const volatile uint8 cal_ACFanMaxSpdDvtLim_CUR[5];
                          /* Referenced by: '<S50>/cal_ACFanMaxSpdDvtLim_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdBatCor_1X[3];
                             /* Referenced by: '<S56>/cal_ACFanSpdBatCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdBatCor_CUR[3];
                             /* Referenced by: '<S56>/cal_ACFanSpdBatCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdDvtSet_1X[14];
                            /* Referenced by: '<S56>/cal_ACFanSpdDvtSet_CUR ' */
extern CALDATA const volatile float32 cal_ACFanSpdDvtSet_CUR[14];
                            /* Referenced by: '<S56>/cal_ACFanSpdDvtSet_CUR ' */
extern CALDATA const volatile float32 cal_ACFanSpdRecircCor_1X[4];
                          /* Referenced by: '<S56>/cal_ACFanSpdRecircCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdRecircCor_CUR[4];
                          /* Referenced by: '<S56>/cal_ACFanSpdRecircCor_CUR' */
extern CALDATA const volatile uint16 cal_ACFanSpdSolarCorByEnv_2X[15];
                      /* Referenced by: '<S56>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_2Y[15];
                      /* Referenced by: '<S56>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_MAP[225];
                      /* Referenced by: '<S56>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACFanSpdSolarCor_2X[15];
                           /* Referenced by: '<S56>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCor_2Y[15];
                           /* Referenced by: '<S56>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdSolarCor_MAP[225];
                           /* Referenced by: '<S56>/cal_ACFanSpdSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACFanSpdVssCor_1X[3];
                             /* Referenced by: '<S56>/cal_ACFanSpdVssCor_CUR' */
extern CALDATA const volatile float32 cal_ACFanSpdVssCor_CUR[3];
                             /* Referenced by: '<S56>/cal_ACFanSpdVssCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletAutoDefogPrtEnvCor_1X[10];
                 /* Referenced by: '<S140>/cal_ACInletAutoDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletAutoDefogPrtEnvCor_CUR[10];
                 /* Referenced by: '<S140>/cal_ACInletAutoDefogPrtEnvCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletDefogPrtEnvCor_1X[10];
                     /* Referenced by: '<S140>/cal_ACInletDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogPrtEnvCor_CUR[10];
                     /* Referenced by: '<S140>/cal_ACInletDefogPrtEnvCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogRiskCor_1X[2];
                       /* Referenced by: '<S140>/cal_ACInletDefogRiskCor_CUR' */
extern CALDATA const volatile uint8 cal_ACInletDefogRiskCor_CUR[2];
                       /* Referenced by: '<S140>/cal_ACInletDefogRiskCor_CUR' */
extern CALDATA const volatile float32 cal_ACInletEnvPrtSetCool_1X[5];
                      /* Referenced by: '<S123>/cal_ACInletEnvPrtSetCool_CUR' */
extern CALDATA const volatile uint8 cal_ACInletEnvPrtSetCool_CUR[5];
                      /* Referenced by: '<S123>/cal_ACInletEnvPrtSetCool_CUR' */
extern CALDATA const volatile float32 cal_ACInletEnvPrtSetHeat_1X[5];
                      /* Referenced by: '<S123>/cal_ACInletEnvPrtSetHeat_CUR' */
extern CALDATA const volatile uint8 cal_ACInletEnvPrtSetHeat_CUR[5];
                      /* Referenced by: '<S123>/cal_ACInletEnvPrtSetHeat_CUR' */
extern CALDATA const volatile uint8 cal_ACPMPSpdDiffVal;/* Referenced by: '<S1022>/Constant' */
extern CALDATA const volatile float32 cal_ACPTCDesBacAC_1X[12];
                             /* Referenced by: '<S341>/cal_ACPTCDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacAC_CUR[12];
                             /* Referenced by: '<S341>/cal_ACPTCDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacBi_1X[12];
                             /* Referenced by: '<S341>/cal_ACPTCDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacBi_CUR[12];
                             /* Referenced by: '<S341>/cal_ACPTCDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacDefog_1X[12];
                          /* Referenced by: '<S341>/cal_ACPTCDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacDefog_CUR[12];
                          /* Referenced by: '<S341>/cal_ACPTCDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFootDe_1X[12];
                         /* Referenced by: '<S341>/cal_ACPTCDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFootDe_CUR[12];
                         /* Referenced by: '<S341>/cal_ACPTCDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFoot_1X[12];
                           /* Referenced by: '<S341>/cal_ACPTCDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesBacFoot_CUR[12];
                           /* Referenced by: '<S341>/cal_ACPTCDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesCabinCor_1X[8];
                          /* Referenced by: '<S341>/cal_ACPTCDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesCabinCor_CUR[8];
                          /* Referenced by: '<S341>/cal_ACPTCDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_2X[6];
                            /* Referenced by: '<S341>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_2Y[6];
                            /* Referenced by: '<S341>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCDesEnvCor_MAP[36];
                            /* Referenced by: '<S341>/cal_ACPTCDesEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPTCDesFanCor_1X[4];
                            /* Referenced by: '<S341>/cal_ACPTCDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCDesFanCor_CUR[4];
                            /* Referenced by: '<S341>/cal_ACPTCDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacAC_1X[12];
                           /* Referenced by: '<S363>/cal_ACPTCPsDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacAC_CUR[12];
                           /* Referenced by: '<S363>/cal_ACPTCPsDesBacAC_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacBi_1X[12];
                           /* Referenced by: '<S363>/cal_ACPTCPsDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacBi_CUR[12];
                           /* Referenced by: '<S363>/cal_ACPTCPsDesBacBi_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_1X[12];
                        /* Referenced by: '<S363>/cal_ACPTCPsDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_CUR[12];
                        /* Referenced by: '<S363>/cal_ACPTCPsDesBacDefog_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_1X[12];
                       /* Referenced by: '<S363>/cal_ACPTCPsDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_CUR[12];
                       /* Referenced by: '<S363>/cal_ACPTCPsDesBacFootDe_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_1X[12];
                         /* Referenced by: '<S363>/cal_ACPTCPsDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_CUR[12];
                         /* Referenced by: '<S363>/cal_ACPTCPsDesBacFoot_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_1X[8];
                        /* Referenced by: '<S363>/cal_ACPTCPsDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_CUR[8];
                        /* Referenced by: '<S363>/cal_ACPTCPsDesCabinCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2X[6];
                          /* Referenced by: '<S363>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2Y[6];
                          /* Referenced by: '<S363>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_MAP[36];
                          /* Referenced by: '<S363>/cal_ACPTCPsDesEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPTCPsDesFanCor_1X[4];
                          /* Referenced by: '<S363>/cal_ACPTCPsDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPsDesFanCor_CUR[4];
                          /* Referenced by: '<S363>/cal_ACPTCPsDesFanCor_CUR' */
extern CALDATA const volatile float32 cal_ACPTCPwrPreSetByEnv_2X[10];
                        /* Referenced by: '<S94>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPTCPwrPreSetByEnv_2Y[10];
                        /* Referenced by: '<S94>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACPTCPwrPreSetByEnv_MAP[100];
                        /* Referenced by: '<S94>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2X[14];
                        /* Referenced by: '<S182>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2Y[14];
                        /* Referenced by: '<S182>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_MAP[196];
                        /* Referenced by: '<S182>/cal_ACPsDVTSetCorByEnv_MAP' */
extern CALDATA const volatile uint16 cal_ACPsDVTSolarCor_2X[15];
                           /* Referenced by: '<S182>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSolarCor_2Y[15];
                           /* Referenced by: '<S182>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile float32 cal_ACPsDVTSolarCor_MAP[225];
                           /* Referenced by: '<S182>/cal_ACPsDVTSolarCor_MAP' */
extern CALDATA const volatile uint8 cal_ACPumpBatHeatSpd;/* Referenced by:
                                                          * '<S1022>/Constant18'
                                                          * '<S1022>/Constant6'
                                                          */
extern CALDATA const volatile uint8 cal_ACPumpCtrlASpd;/* Referenced by: '<S1022>/Constant1' */
extern CALDATA const volatile uint8 cal_ACPumpDefSpd;/* Referenced by:
                                                      * '<S1022>/Constant17'
                                                      * '<S1022>/Constant2'
                                                      */
extern CALDATA const volatile uint8 cal_ACPumpDehSpd;/* Referenced by: '<S1022>/Constant8' */
extern CALDATA const volatile uint8 cal_ACPumpDoubleHeatSpd;/* Referenced by: '<S1022>/Constant7' */
extern CALDATA const volatile uint8 cal_ACRecirRatioLmt;/* Referenced by:
                                                         * '<S282>/Constant2'
                                                         * '<S307>/Constant2'
                                                         * '<S341>/Constant2'
                                                         * '<S363>/Constant2'
                                                         * '<S56>/Constant2'
                                                         */
extern CALDATA const volatile float32 cal_ADCVCCVal;/* Referenced by:
                                                     * '<S1074>/Constant2'
                                                     * '<S1075>/Constant1'
                                                     * '<S1740>/Constant2'
                                                     * '<S1742>/Constant1'
                                                     * '<S1743>/Constant1'
                                                     * '<S1749>/Constant1'
                                                     * '<S1750>/Constant1'
                                                     * '<S1751>/Constant1'
                                                     * '<S1752>/Constant1'
                                                     * '<S1753>/Constant1'
                                                     * '<S1755>/Constant1'
                                                     */
extern CALDATA const volatile float32 cal_AEXVClsEvapPrtTemp;
                                   /* Referenced by: '<S683>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVClsValEvapPrt;/* Referenced by:
                                                             * '<S683>/EvapTemperature'
                                                             * '<S683>/Constant3'
                                                             */
extern CALDATA const volatile float32 cal_AEXVClsValRunTimeEvapPrt;
                                   /* Referenced by: '<S683>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVCtlKi;/* Referenced by: '<S680>/Constant11' */
extern CALDATA const volatile float32 cal_AEXVCtlKisumMax;/* Referenced by: '<S680>/Constant8' */
extern CALDATA const volatile float32 cal_AEXVCtlKisumMin;/* Referenced by: '<S680>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVCtlKp;/* Referenced by: '<S680>/Constant10' */
extern CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_1X[6];
                   /* Referenced by: '<S715>/cal_AEXVCtrlBCabinCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_CUR[6];
                   /* Referenced by: '<S715>/cal_AEXVCtrlBCabinCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_1X[6];
                       /* Referenced by: '<S715>/cal_AEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_CUR[6];
                       /* Referenced by: '<S715>/cal_AEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDeadzone;/* Referenced by: '<S715>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlBDelayTime;/* Referenced by: '<S715>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlBFF_1X[5];
                               /* Referenced by: '<S715>/cal_AEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBFF_CUR[5];
                               /* Referenced by: '<S715>/cal_AEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKi_1X[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKi_CUR[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKp_1X[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBKp_CUR[8];
                               /* Referenced by: '<S715>/cal_AEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBOpenVal;/* Referenced by: '<S715>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlBPIMax;/* Referenced by: '<S715>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlBPIMin;/* Referenced by: '<S715>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_1X[9];
                /* Referenced by: '<S715>/cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR[9];
                /* Referenced by: '<S715>/cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_1X[9];
                       /* Referenced by: '<S715>/cal_AEXVCtrlBTrgSubCool_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_CUR[9];
                       /* Referenced by: '<S715>/cal_AEXVCtrlBTrgSubCool_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCDeadzone;/* Referenced by: '<S716>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlCDelayTime;/* Referenced by: '<S716>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlCFF_1X[5];
                               /* Referenced by: '<S716>/cal_AEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCFF_CUR[5];
                               /* Referenced by: '<S716>/cal_AEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKi_1X[7];
                               /* Referenced by: '<S716>/cal_AEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKi_CUR[7];
                               /* Referenced by: '<S716>/cal_AEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKp_1X[7];
                               /* Referenced by: '<S716>/cal_AEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCKp_CUR[7];
                               /* Referenced by: '<S716>/cal_AEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCOpenVal;/* Referenced by: '<S716>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlCPIMax;/* Referenced by: '<S716>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlCPIMin;/* Referenced by: '<S716>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgflt;/* Referenced by: '<S716>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_1X[7];
                    /* Referenced by: '<S716>/cal_AEXVCtrlCTrgtSuperHeat_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_CUR[7];
                    /* Referenced by: '<S716>/cal_AEXVCtrlCTrgtSuperHeat_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDDeadzone;/* Referenced by: '<S717>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVCtrlDDelayTime;/* Referenced by: '<S717>/Constant' */
extern CALDATA const volatile float32 cal_AEXVCtrlDFF_1X[5];
                               /* Referenced by: '<S717>/cal_AEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDFF_CUR[5];
                               /* Referenced by: '<S717>/cal_AEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKi_1X[8];
                               /* Referenced by: '<S717>/cal_AEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKi_CUR[8];
                               /* Referenced by: '<S717>/cal_AEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKp_1X[8];
                               /* Referenced by: '<S717>/cal_AEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDKp_CUR[8];
                               /* Referenced by: '<S717>/cal_AEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDOpenVal;/* Referenced by: '<S717>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVCtrlDPIMax;/* Referenced by: '<S717>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVCtrlDPIMin;/* Referenced by: '<S717>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVCtrlDTrg_1X[3];
                              /* Referenced by: '<S717>/cal_AEXVCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDTrg_CUR[3];
                              /* Referenced by: '<S717>/cal_AEXVCtrlDTrg_CUR' */
extern CALDATA const volatile float32 cal_AEXVCtrlDefaultPos;/* Referenced by: '<S718>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVDiffDown;/* Referenced by: '<S739>/Constant8' */
extern CALDATA const volatile float32 cal_AEXVDiffDownRate;/* Referenced by: '<S739>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVDiffUp;/* Referenced by: '<S739>/Constant6' */
extern CALDATA const volatile float32 cal_AEXVDiffUpRate;/* Referenced by: '<S739>/Constant5' */
extern CALDATA const volatile float32 cal_AEXVDownSpdLmt;/* Referenced by:
                                                          * '<S744>/DownLmt'
                                                          * '<S744>/DownLmt1'
                                                          */
extern CALDATA const volatile boolean cal_AEXVEnbData;/* Referenced by: '<S686>/Constant' */
extern CALDATA const volatile boolean cal_AEXVEnbDataEnb;/* Referenced by: '<S686>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVFloorDiff1;/* Referenced by: '<S742>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVFloorDiff2;/* Referenced by: '<S742>/Constant' */
extern CALDATA const volatile float32 cal_AEXVFltClsSpd;/* Referenced by: '<S683>/Constant7' */
extern CALDATA const volatile float32 cal_AEXVHighPressLmtOn;/* Referenced by: '<S739>/Constant3' */
extern CALDATA const volatile float32 cal_AEXVHighPressProhOn;/* Referenced by: '<S683>/Constant' */
extern CALDATA const volatile uint8 cal_AEXVInitReqData;/* Referenced by: '<S696>/Constant' */
extern CALDATA const volatile boolean cal_AEXVInitReqDataeEnb;/* Referenced by: '<S696>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVLowPressLmtOn;/* Referenced by: '<S739>/Constant4' */
extern CALDATA const volatile float32 cal_AEXVLowPressProhOn;/* Referenced by: '<S683>/Constant2' */
extern CALDATA const volatile float32 cal_AEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                  * '<S745>/DownLmt'
                                                                  * '<S745>/DownLmt1'
                                                                  */
extern CALDATA const volatile float32 cal_AEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                * '<S745>/UpLmt'
                                                                * '<S745>/UpLmt2'
                                                                */
extern CALDATA const volatile float32 cal_AEXVOpenDelayTimeEvapNOPrt;
                                   /* Referenced by: '<S683>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenEvapNOPrtTemp;
                                   /* Referenced by: '<S683>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenRunTimeEvapNOPrt;
                                   /* Referenced by: '<S683>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenValEvapNOPrt;
                                   /* Referenced by: '<S683>/EvapTemperature' */
extern CALDATA const volatile float32 cal_AEXVOpenValveSpd;/* Referenced by: '<S683>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVPosData;/* Referenced by: '<S740>/Constant' */
extern CALDATA const volatile boolean cal_AEXVPosDataEnb;/* Referenced by: '<S740>/Constant1' */
extern CALDATA const volatile float32 cal_AEXVSubCoolflt;/* Referenced by: '<S715>/Constant9' */
extern CALDATA const volatile float32 cal_AEXVUpSpdLmt;/* Referenced by:
                                                        * '<S744>/UpLmt'
                                                        * '<S744>/UpLmt2'
                                                        */
extern CALDATA const volatile uint8 cal_AQS2InRecThreVal;/* Referenced by: '<S127>/Constant3' */
extern CALDATA const volatile uint8 cal_AQS2OutRecThreVal;/* Referenced by: '<S127>/Constant4' */
extern CALDATA const volatile boolean cal_AcPMPFaultFlgData;/* Referenced by: '<S1036>/Constant' */
extern CALDATA const volatile boolean cal_AcPMPFaultFlgDataEnb;/* Referenced by: '<S1036>/Constant1' */
extern CALDATA const volatile uint8 cal_AcPMPSpdSetData;/* Referenced by: '<S1035>/Constant' */
extern CALDATA const volatile boolean cal_AcPMPSpdSetDataEnb;/* Referenced by: '<S1035>/Constant1' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressDownSide_1X[12];
               /* Referenced by: '<S545>/cal_AccmSpdLimByHiPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressDownSide_CUR[12];
               /* Referenced by: '<S545>/cal_AccmSpdLimByHiPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressLevelCalcu_1X[12];
             /* Referenced by: '<S545>/cal_AccmSpdLimByHiPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressLevelCalcu_CUR[12];
             /* Referenced by: '<S545>/cal_AccmSpdLimByHiPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByHiPressUpSide_1X[12];
                 /* Referenced by: '<S545>/cal_AccmSpdLimByHiPressUpSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByHiPressUpSide_CUR[12];
                 /* Referenced by: '<S545>/cal_AccmSpdLimByHiPressUpSide_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressDownSide_1X[12];
               /* Referenced by: '<S545>/cal_AccmSpdLimByLoPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressDownSide_CUR[12];
               /* Referenced by: '<S545>/cal_AccmSpdLimByLoPressDownSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressLevelCalcu_1X[12];
             /* Referenced by: '<S545>/cal_AccmSpdLimByLoPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressLevelCalcu_CUR[12];
             /* Referenced by: '<S545>/cal_AccmSpdLimByLoPressLevelCalcu_CUR' */
extern CALDATA const volatile uint8 cal_AccmSpdLimByLoPressUpSide_1X[12];
                 /* Referenced by: '<S545>/cal_AccmSpdLimByLoPressUpSide_CUR' */
extern CALDATA const volatile float32 cal_AccmSpdLimByLoPressUpSide_CUR[12];
                 /* Referenced by: '<S545>/cal_AccmSpdLimByLoPressUpSide_CUR' */
extern CALDATA const volatile uint8 cal_AirInletPerData;/* Referenced by: '<S1810>/Constant' */
extern CALDATA const volatile boolean cal_AirInletPerEnb;/* Referenced by: '<S1810>/Constant1' */
extern CALDATA const volatile float32 cal_AirInletRecInPCUTemp;/* Referenced by: '<S131>/Constant6' */
extern CALDATA const volatile float32 cal_AirInletRecOutPCUTemp;/* Referenced by: '<S131>/Constant1' */
extern CALDATA const volatile boolean cal_AutoDefogEnable;/* Referenced by: '<S140>/Constant1' */
extern CALDATA const volatile boolean cal_AvgSwitch;/* Referenced by:
                                                     * '<S676>/Constant1'
                                                     * '<S676>/Constant4'
                                                     * '<S676>/Constant5'
                                                     * '<S676>/Constant6'
                                                     */
extern CALDATA const volatile uint8 cal_BATPMPSpdDiffVal;/* Referenced by: '<S1023>/Constant' */
extern CALDATA const volatile uint8 cal_BCVFltStsDelayTime;/* Referenced by: '<S664>/Constant5' */
extern CALDATA const volatile float32 cal_BCVPosDiffDelayTime;/* Referenced by: '<S664>/Constant2' */
extern CALDATA const volatile float32 cal_BEXVCtlKi;/* Referenced by: '<S750>/Constant11' */
extern CALDATA const volatile float32 cal_BEXVCtlKisumMax;/* Referenced by: '<S750>/Constant8' */
extern CALDATA const volatile float32 cal_BEXVCtlKisumMin;/* Referenced by: '<S750>/Constant9' */
extern CALDATA const volatile float32 cal_BEXVCtlKp;/* Referenced by: '<S750>/Constant10' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_1X[6];
                       /* Referenced by: '<S783>/cal_BEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_CUR[6];
                       /* Referenced by: '<S783>/cal_BEXVCtrlBDCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDeadzone;/* Referenced by: '<S783>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVCtrlBDelayTime;/* Referenced by: '<S783>/Constant' */
extern CALDATA const volatile float32 cal_BEXVCtrlBFF_1X[5];
                               /* Referenced by: '<S783>/cal_BEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBFF_CUR[5];
                               /* Referenced by: '<S783>/cal_BEXVCtrlBFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKi_1X[7];
                               /* Referenced by: '<S783>/cal_BEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKi_CUR[7];
                               /* Referenced by: '<S783>/cal_BEXVCtrlBKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKp_1X[7];
                               /* Referenced by: '<S783>/cal_BEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBKp_CUR[7];
                               /* Referenced by: '<S783>/cal_BEXVCtrlBKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBOpenVal;/* Referenced by: '<S783>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVCtrlBPIDown;/* Referenced by: '<S783>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVCtrlBPIUp;/* Referenced by: '<S783>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_1X[5];
                     /* Referenced by: '<S783>/cal_BEXVCtrlBTrgCabinComp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_CUR[5];
                     /* Referenced by: '<S783>/cal_BEXVCtrlBTrgCabinComp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_1X[6];
                   /* Referenced by: '<S783>/cal_BEXVCtrlBTrgWtrTempDiff_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_CUR[6];
                   /* Referenced by: '<S783>/cal_BEXVCtrlBTrgWtrTempDiff_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_1X[6];
                     /* Referenced by: '<S784>/cal_BEXVCtrlCBatCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_CUR[6];
                     /* Referenced by: '<S784>/cal_BEXVCtrlCBatCoolPIMin_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCDeadzone;/* Referenced by: '<S784>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVCtrlCDelayTime;/* Referenced by: '<S784>/Constant' */
extern CALDATA const volatile float32 cal_BEXVCtrlCFF_1X[5];
                               /* Referenced by: '<S784>/cal_BEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCFF_CUR[5];
                               /* Referenced by: '<S784>/cal_BEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKi_1X[8];
                               /* Referenced by: '<S784>/cal_BEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKi_CUR[8];
                               /* Referenced by: '<S784>/cal_BEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKp_1X[8];
                               /* Referenced by: '<S784>/cal_BEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCKp_CUR[8];
                               /* Referenced by: '<S784>/cal_BEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCOpenVal;/* Referenced by: '<S784>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVCtrlCPIMax;/* Referenced by: '<S784>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVCtrlCPIMin;/* Referenced by: '<S784>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVCtrlCTrg_1X[5];
                              /* Referenced by: '<S784>/cal_BEXVCtrlCTrg_CUR' */
extern CALDATA const volatile float32 cal_BEXVCtrlCTrg_CUR[5];
                              /* Referenced by: '<S784>/cal_BEXVCtrlCTrg_CUR' */
extern CALDATA const volatile float32 cal_BEXVDiffDown;/* Referenced by: '<S809>/Constant8' */
extern CALDATA const volatile float32 cal_BEXVDiffDownRate;/* Referenced by: '<S809>/Constant7' */
extern CALDATA const volatile float32 cal_BEXVDiffUp;/* Referenced by: '<S809>/Constant6' */
extern CALDATA const volatile float32 cal_BEXVDiffUpRate;/* Referenced by: '<S809>/Constant5' */
extern CALDATA const volatile float32 cal_BEXVDownSpdLmt;/* Referenced by:
                                                          * '<S814>/DownLmt'
                                                          * '<S814>/DownLmt1'
                                                          */
extern CALDATA const volatile boolean cal_BEXVEnbData;/* Referenced by: '<S805>/Constant' */
extern CALDATA const volatile boolean cal_BEXVEnbDataEnb;/* Referenced by: '<S805>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVFloorDiff1;/* Referenced by: '<S812>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVFloorDiff2;/* Referenced by: '<S812>/Constant' */
extern CALDATA const volatile float32 cal_BEXVHighPressLmtOn;/* Referenced by: '<S809>/Constant3' */
extern CALDATA const volatile float32 cal_BEXVHighPressProhOn;/* Referenced by: '<S754>/Constant' */
extern CALDATA const volatile uint8 cal_BEXVInitReqData;/* Referenced by: '<S764>/Constant' */
extern CALDATA const volatile boolean cal_BEXVInitReqDataeEnb;/* Referenced by: '<S764>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVLowPressLmtOn;/* Referenced by: '<S809>/Constant4' */
extern CALDATA const volatile float32 cal_BEXVLowPressProhOn;/* Referenced by: '<S754>/Constant2' */
extern CALDATA const volatile float32 cal_BEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                  * '<S815>/DownLmt'
                                                                  * '<S815>/DownLmt1'
                                                                  */
extern CALDATA const volatile float32 cal_BEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                * '<S815>/UpLmt'
                                                                * '<S815>/UpLmt2'
                                                                */
extern CALDATA const volatile float32 cal_BEXVOpenValveSpd;/* Referenced by: '<S754>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVPosData;/* Referenced by: '<S810>/Constant' */
extern CALDATA const volatile boolean cal_BEXVPosDataEnb;/* Referenced by: '<S810>/Constant1' */
extern CALDATA const volatile float32 cal_BEXVSubCoolflt;/* Referenced by: '<S784>/Constant10' */
extern CALDATA const volatile float32 cal_BEXVSubHeatflt;/* Referenced by: '<S783>/Constant12' */
extern CALDATA const volatile float32 cal_BEXVUpSpdLmt;/* Referenced by:
                                                        * '<S814>/UpLmt'
                                                        * '<S814>/UpLmt2'
                                                        */
extern CALDATA const volatile float32 cal_BMSInletTempHighOffMCV;/* Referenced by: '<S641>/Relay' */
extern CALDATA const volatile float32 cal_BMSInletTempLowOnMCV;/* Referenced by: '<S641>/Relay' */
extern CALDATA const volatile float32 cal_BatBalCellTemp1;/* Referenced by:
                                                           * '<S1333>/Constant1'
                                                           * '<S1336>/Constant1'
                                                           * '<S1575>/Constant'
                                                           * '<S1578>/Constant'
                                                           * '<S1613>/Constant'
                                                           * '<S1358>/Constant1'
                                                           * '<S1371>/Constant4'
                                                           * '<S1591>/Constant'
                                                           * '<S1598>/Constant'
                                                           * '<S1603>/Constant'
                                                           * '<S1618>/Constant'
                                                           * '<S1622>/Constant'
                                                           * '<S1656>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatBalCellTemp2;/* Referenced by:
                                                           * '<S1333>/Constant2'
                                                           * '<S1336>/Constant2'
                                                           * '<S1339>/Constant'
                                                           * '<S1463>/Constant'
                                                           * '<S1564>/Constant'
                                                           * '<S1640>/Constant'
                                                           * '<S1652>/Constant4'
                                                           * '<S1653>/Constant4'
                                                           * '<S1654>/Constant4'
                                                           * '<S1656>/Constant4'
                                                           * '<S1362>/Constant4'
                                                           * '<S1363>/Constant4'
                                                           * '<S1364>/Constant4'
                                                           * '<S1458>/Constant'
                                                           * '<S1557>/Constant'
                                                           * '<S1672>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatCoolInletTrgTemp;/* Referenced by:
                                                               * '<S583>/Constant3'
                                                               * '<S589>/Constant5'
                                                               * '<S783>/Constant11'
                                                               */
extern CALDATA const volatile boolean cal_BatCoolOverData;/* Referenced by: '<S1397>/Constant' */
extern CALDATA const volatile boolean cal_BatCoolOverEnb;/* Referenced by: '<S1397>/Constant1' */
extern CALDATA const volatile uint16 cal_BatCoolStopBatPMPRunTime;/* Referenced by: '<S1023>/Constant16' */
extern CALDATA const volatile uint8 cal_BatCoolStopBatPMPSpd;/* Referenced by: '<S1023>/Constant15' */
extern CALDATA const volatile float32 cal_BatCoolTrgFilter;/* Referenced by:
                                                            * '<S583>/Constant5'
                                                            * '<S586>/Constant9'
                                                            */
extern CALDATA const volatile boolean cal_BatHeatACCMEnb;/* Referenced by:
                                                          * '<S462>/Constant1'
                                                          * '<S591>/Constant9'
                                                          */
extern CALDATA const volatile boolean cal_BatHeatOverData;/* Referenced by: '<S1480>/Constant' */
extern CALDATA const volatile boolean cal_BatHeatOverEnb;/* Referenced by: '<S1480>/Constant1' */
extern CALDATA const volatile float32 cal_BatHeatPwrLoLmt;/* Referenced by:
                                                           * '<S1420>/Constant'
                                                           * '<S1505>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_BatHeatTrgTemp;/* Referenced by: '<S947>/Constant5' */
extern CALDATA const volatile float32 cal_BatHeatTrgTempComp_1X[11];
                       /* Referenced by: '<S1533>/cal_BatHeatTrgTempComp_CUR' */
extern CALDATA const volatile float32 cal_BatHeatTrgTempComp_CUR[11];
                       /* Referenced by: '<S1533>/cal_BatHeatTrgTempComp_CUR' */
extern CALDATA const volatile BatModes cal_BatModeData;/* Referenced by: '<S1475>/Constant' */
extern CALDATA const volatile boolean cal_BatModeEnb;/* Referenced by: '<S1475>/Constant1' */
extern CALDATA const volatile boolean cal_BatModeSwitch;/* Referenced by:
                                                         * '<S32>/Constant1'
                                                         * '<S1311>/Constant'
                                                         */
extern CALDATA const volatile boolean cal_BatModeTestCtrl;/* Referenced by: '<S663>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPFaultFlgData;/* Referenced by: '<S1052>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPFaultFlgDataEnb;/* Referenced by: '<S1052>/Constant1' */
extern CALDATA const volatile uint8 cal_BatPMPSpdSetData;/* Referenced by: '<S1051>/Constant' */
extern CALDATA const volatile boolean cal_BatPMPSpdSetDataEnb;/* Referenced by: '<S1051>/Constant1' */
extern CALDATA const volatile float32 cal_BatPumpBal_1X[4];
                               /* Referenced by: '<S1023>/cal_BatPumpBal_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpBal_CUR[4];
                               /* Referenced by: '<S1023>/cal_BatPumpBal_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpCtrlASpd;/* Referenced by: '<S1023>/Constant1' */
extern CALDATA const volatile uint8 cal_BatPumpMotHeatBatSpd;/* Referenced by: '<S1023>/Constant13' */
extern CALDATA const volatile uint8 cal_BatPumpMotLTRAndBatCHSpd;/* Referenced by: '<S1023>/Constant14' */
extern CALDATA const volatile float32 cal_BatPumpThSto_1X[4];
                             /* Referenced by: '<S1023>/cal_BatPumpThSto_CUR' */
extern CALDATA const volatile uint8 cal_BatPumpThSto_CUR[4];
                             /* Referenced by: '<S1023>/cal_BatPumpThSto_CUR' */
extern CALDATA const volatile float32 cal_BatTrgTempData;/* Referenced by: '<S1330>/Constant' */
extern CALDATA const volatile boolean cal_BatTrgTempEnb;/* Referenced by: '<S1330>/Constant1' */
extern CALDATA const volatile float32 cal_BetwT1AndT2DownMCV_1X[6];
                        /* Referenced by: '<S647>/cal_BetwT1AndT2DownMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2DownMCV_CUR[6];
                        /* Referenced by: '<S647>/cal_BetwT1AndT2DownMCV_CUR' */
extern CALDATA const volatile float32 cal_BetwT1AndT2StbyMCV_1X[6];
                        /* Referenced by: '<S647>/cal_BetwT1AndT2StbyMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2StbyMCV_CUR[6];
                        /* Referenced by: '<S647>/cal_BetwT1AndT2StbyMCV_CUR' */
extern CALDATA const volatile float32 cal_BetwT1AndT2UpMCV_1X[6];
                          /* Referenced by: '<S647>/cal_BetwT1AndT2UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_BetwT1AndT2UpMCV_CUR[6];
                          /* Referenced by: '<S647>/cal_BetwT1AndT2UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_BlowerFanSpdLL;/* Referenced by: '<S51>/Constant14' */
extern CALDATA const volatile uint8 cal_BlowerFanSpdVentUL;/* Referenced by: '<S50>/Constant29' */
extern CALDATA const volatile uint8 cal_BlwFanData;/* Referenced by: '<S1242>/Constant' */
extern CALDATA const volatile boolean cal_BlwFanEnb;/* Referenced by: '<S1242>/Constant1' */
extern CALDATA const volatile uint16 cal_BlwFrqVal;/* Referenced by: '<S1224>/Constant5' */
extern CALDATA const volatile uint8 cal_C3WVExhPosVal;/* Referenced by: '<S641>/Constant7' */
extern CALDATA const volatile uint8 cal_C3WVSLStsData;/* Referenced by: '<S660>/Constant' */
extern CALDATA const volatile boolean cal_C3WVSLStsDataEnb;/* Referenced by: '<S660>/Constant1' */
extern CALDATA const volatile uint8 cal_C5WVExhPosVal;/* Referenced by: '<S663>/Constant11' */
extern CALDATA const volatile uint8 cal_C5WVSLStsData;/* Referenced by: '<S670>/Constant' */
extern CALDATA const volatile boolean cal_C5WVSLStsDataEnb;/* Referenced by: '<S670>/Constant1' */
extern CALDATA const volatile boolean cal_CANAliveEnable;/* Referenced by: '<S2>/Constant' */
extern CALDATA const volatile sint16 cal_CAPStartCoolantMin;
                             /* Referenced by: '<S39>/AirConditionStartState' */
extern CALDATA const volatile uint8 cal_CO2RecircRatio;/* Referenced by: '<S46>/Constant14' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_1X[8];
                      /* Referenced by: '<S545>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_CUR[8];
                      /* Referenced by: '<S545>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_2X[10];
                         /* Referenced by: '<S545>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile uint8 cal_COMPATNoiseSpdLmt_2Y[10];
                         /* Referenced by: '<S545>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_MAP[100];
                         /* Referenced by: '<S545>/cal_COMPATNoiseSpdLmt_MAP' */
extern CALDATA const volatile float32 cal_COMPActlSpd1;/* Referenced by: '<S541>/Constant' */
extern CALDATA const volatile float32 cal_COMPActlSpd2;/* Referenced by: '<S542>/Constant' */
extern CALDATA const volatile float32 cal_COMPActlSpd3;/* Referenced by: '<S543>/Constant' */
extern CALDATA const volatile float32 cal_COMPBatMaxSpdLmt;/* Referenced by: '<S546>/Constant2' */
extern CALDATA const volatile float32 cal_COMPCabinCoolMaxSpdLmt;/* Referenced by: '<S546>/Constant3' */
extern CALDATA const volatile float32 cal_COMPClsLowSpeed;/* Referenced by:
                                                           * '<S562>/Constant'
                                                           * '<S478>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_COMPCoolLowSpd;/* Referenced by:
                                                          * '<S547>/Constant'
                                                          * '<S550>/Constant'
                                                          * '<S554>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt1_1X[2];
                            /* Referenced by: '<S546>/cal_COMPEnvSpdLmt1_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt1_CUR[2];
                            /* Referenced by: '<S546>/cal_COMPEnvSpdLmt1_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt2_1X[2];
                            /* Referenced by: '<S546>/cal_COMPEnvSpdLmt2_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt2_CUR[2];
                            /* Referenced by: '<S546>/cal_COMPEnvSpdLmt2_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt3_1X[2];
                            /* Referenced by: '<S546>/cal_COMPEnvSpdLmt3_CUR' */
extern CALDATA const volatile float32 cal_COMPEnvSpdLmt3_CUR[2];
                            /* Referenced by: '<S546>/cal_COMPEnvSpdLmt3_CUR' */
extern CALDATA const volatile float32 cal_COMPEvapTFrbVal;/* Referenced by: '<S457>/Relay2' */
extern CALDATA const volatile float32 cal_COMPEvapTNmlVal;/* Referenced by: '<S457>/Relay2' */
extern CALDATA const volatile float32 cal_COMPExhTDownSpd;/* Referenced by: '<S570>/Constant1' */
extern CALDATA const volatile float32 cal_COMPExhTFrbVal;/* Referenced by: '<S457>/Relay1' */
extern CALDATA const volatile float32 cal_COMPExhTLmtRlybVal;/* Referenced by: '<S457>/Relay1' */
extern CALDATA const volatile float32 cal_COMPExhTLmtVal;/* Referenced by: '<S457>/Relay' */
extern CALDATA const volatile float32 cal_COMPExhTNmlVal;/* Referenced by: '<S457>/Relay' */
extern CALDATA const volatile uint8 cal_COMPFanLevelLmt_1X[9];
                           /* Referenced by: '<S546>/cal_COMPFanLevelLmt_CUR' */
extern CALDATA const volatile float32 cal_COMPFanLevelLmt_CUR[9];
                           /* Referenced by: '<S546>/cal_COMPFanLevelLmt_CUR' */
extern CALDATA const volatile uint8 cal_COMPFanSpdLmt[3];/* Referenced by: '<S443>/Constant14' */
extern CALDATA const volatile float32 cal_COMPONMinSpd;/* Referenced by: '<S451>/Relay' */
extern CALDATA const volatile float32 cal_COMPOffMaxSpd;/* Referenced by: '<S451>/Relay' */
extern CALDATA const volatile float32 cal_COMPPwrMaxLmt;/* Referenced by: '<S31>/Constant3' */
extern CALDATA const volatile float32 cal_COMPSpdDiffDown;/* Referenced by: '<S571>/Constant6' */
extern CALDATA const volatile float32 cal_COMPSpdDiffDownRate;/* Referenced by: '<S571>/Constant7' */
extern CALDATA const volatile float32 cal_COMPSpdDiffUp;/* Referenced by: '<S571>/Constant' */
extern CALDATA const volatile float32 cal_COMPSpdDiffUpRate;/* Referenced by: '<S571>/Constant5' */
extern CALDATA const volatile float32 cal_COMPSpdLmt[4];/* Referenced by: '<S443>/Constant13' */
extern CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos1;/* Referenced by: '<S1689>/Constant' */
extern CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos2;/* Referenced by: '<S1690>/Constant' */
extern CALDATA const volatile float32 cal_CabinCondToEvpHPEXVPos;/* Referenced by: '<S1708>/Constant' */
extern CALDATA const volatile uint16 cal_CabinDesTempSolarCorECO_2X[14];
                   /* Referenced by: '<S185>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_2Y[14];
                   /* Referenced by: '<S185>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_MAP[196];
                   /* Referenced by: '<S185>/cal_CabinDesTempSolarCorECO_MAP' */
extern CALDATA const volatile uint16 cal_CabinDesTempSolarCor_2X[14];
                      /* Referenced by: '<S185>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCor_2Y[14];
                      /* Referenced by: '<S185>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile float32 cal_CabinDesTempSolarCor_MAP[196];
                      /* Referenced by: '<S185>/cal_CabinDesTempSolarCor_MAP' */
extern CALDATA const volatile uint16 cal_CabinEvpToCondCompLmt;/* Referenced by: '<S1707>/Constant' */
extern CALDATA const volatile float32 cal_CabinEvpToHPEnvTemp;/* Referenced by: '<S1721>/Constant' */
extern CALDATA const volatile float32 cal_CabinHys1TempOffset;/* Referenced by:
                                                               * '<S1678>/Constant4'
                                                               * '<S1678>/Constant6'
                                                               * '<S1678>/Constant7'
                                                               * '<S1683>/Constant6'
                                                               * '<S1700>/Constant4'
                                                               * '<S1700>/Constant6'
                                                               * '<S1700>/Constant7'
                                                               * '<S1701>/Constant14'
                                                               * '<S1701>/Constant15'
                                                               * '<S1702>/Constant12'
                                                               * '<S1713>/Constant6'
                                                               * '<S1714>/Constant14'
                                                               * '<S1714>/Constant15'
                                                               * '<S1715>/Constant12'
                                                               */
extern CALDATA const volatile float32 cal_CabinHys2TempOffset;/* Referenced by:
                                                               * '<S1678>/Constant8'
                                                               * '<S1700>/Constant8'
                                                               * '<S1701>/Constant12'
                                                               * '<S1714>/Constant12'
                                                               */
extern CALDATA const volatile float32 cal_CabinMD2F2MaxEnvTemp;/* Referenced by:
                                                                * '<S1710>/Constant1'
                                                                * '<S1698>/Constant'
                                                                * '<S1699>/Constant9'
                                                                * '<S1701>/Constant11'
                                                                * '<S1714>/Constant11'
                                                                * '<S1715>/Constant11'
                                                                */
extern CALDATA const volatile CabinMode cal_CabinModeData;/* Referenced by: '<S1727>/Constant' */
extern CALDATA const volatile boolean cal_CabinModeEnb;/* Referenced by: '<S1727>/Constant1' */
extern CALDATA const volatile float32 cal_CabinModeKeepStandbyTime;/* Referenced by: '<S1684>/Constant2' */
extern CALDATA const volatile float32 cal_CabinModeTransF1Constant;/* Referenced by: '<S1676>/Constant3' */
extern CALDATA const volatile float32 cal_CabinModeTransF1Slope;/* Referenced by: '<S1676>/Constant2' */
extern CALDATA const volatile float32 cal_CabinModeTransF2Constant;/* Referenced by: '<S1676>/Constant4' */
extern CALDATA const volatile float32 cal_CabinModeTransF2Slope;/* Referenced by: '<S1676>/Constant1' */
extern CALDATA const volatile boolean cal_CabinSetPTCSwitch;/* Referenced by: '<S179>/Constant9' */
extern CALDATA const volatile uint8 cal_CabinTCorSelect;/* Referenced by: '<S176>/Constant1' */
extern CALDATA const volatile float32 cal_CabinTempData;/* Referenced by: '<S1757>/Constant' */
extern CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_1X[10];
                    /* Referenced by: '<S176>/cal_CabinTempDuctUpStepCor_CUR' */
extern CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_CUR[10];
                    /* Referenced by: '<S176>/cal_CabinTempDuctUpStepCor_CUR' */
extern CALDATA const volatile boolean cal_CabinTempEnb;/* Referenced by: '<S1757>/Constant1' */
extern CALDATA const volatile uint16 cal_CabinVolAmend_1X[2];
                            /* Referenced by: '<S1740>/cal_CabinVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_CabinVolAmend_CUR[2];
                            /* Referenced by: '<S1740>/cal_CabinVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ChiTempData;/* Referenced by: '<S1818>/Constant' */
extern CALDATA const volatile boolean cal_ChiTempDataEnb;/* Referenced by: '<S1818>/Constant1' */
extern CALDATA const volatile uint16 cal_ChillTempVolAmend_1X[2];
                        /* Referenced by: '<S1749>/cal_ChillTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ChillTempVolAmend_CUR[2];
                        /* Referenced by: '<S1749>/cal_ChillTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ClsCoolInletTemp;/* Referenced by: '<S1319>/Constant' */
extern CALDATA const volatile float32 cal_ClsCoolInletTempTime;/* Referenced by: '<S1319>/Constant2' */
extern CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_1X[15];
                      /* Referenced by: '<S1072>/cal_ColdPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_CUR[15];
                      /* Referenced by: '<S1072>/cal_ColdPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_1X[7];
                 /* Referenced by: '<S1299>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_CUR[7];
                 /* Referenced by: '<S1299>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern CALDATA const volatile float32 cal_CondDepFilter;/* Referenced by: '<S895>/Constant2' */
extern CALDATA const volatile float32 cal_CondDep_1X[28];
                                   /* Referenced by: '<S676>/cal_CondDep_CUR' */
extern CALDATA const volatile float32 cal_CondDep_CUR[28];
                                   /* Referenced by: '<S676>/cal_CondDep_CUR' */
extern CALDATA const volatile float32 cal_CoolFanCtrl_2X[4];
                               /* Referenced by: '<S915>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_CoolFanCtrl_2Y[13];
                               /* Referenced by: '<S915>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_CoolFanCtrl_MAP[52];
                               /* Referenced by: '<S915>/cal_CoolFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_CoolFanData;/* Referenced by: '<S921>/Constant' */
extern CALDATA const volatile boolean cal_CoolFanEnb;/* Referenced by: '<S921>/Constant1' */
extern CALDATA const volatile float32 cal_CoolStartCompensate;/* Referenced by: '<S279>/Constant8' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2X[6];
                     /* Referenced by: '<S587>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2Y[6];
                     /* Referenced by: '<S587>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_MAP[36];
                     /* Referenced by: '<S587>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_CtrlFPTCOffPowerVal;/* Referenced by: '<S587>/Constant6' */
extern CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_1X[6];
                        /* Referenced by: '<S587>/cal_CtrlFPTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_CUR[6];
                        /* Referenced by: '<S587>/cal_CtrlFPTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_DCBatHeatEnvTemp[2];/* Referenced by: '<S1531>/Constant1' */
extern CALDATA const volatile float32 cal_DCBatHeatT1[3];/* Referenced by: '<S1531>/Constant2' */
extern CALDATA const volatile float32 cal_DCBatHeatT2[3];/* Referenced by: '<S1531>/Constant3' */
extern CALDATA const volatile float32 cal_DCBatHeatTave[3];/* Referenced by: '<S1531>/Constant' */
extern CALDATA const volatile float32 cal_DCBatHeatTrgTemp;/* Referenced by:
                                                            * '<S648>/Constant4'
                                                            * '<S1531>/Constant4'
                                                            */
extern CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_1X[7];
                     /* Referenced by: '<S1533>/cal_DCChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_CUR[7];
                     /* Referenced by: '<S1533>/cal_DCChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DLTRBatInlet2MaxTempDiff;/* Referenced by: '<S1573>/Constant' */
extern CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_1X[5];
                       /* Referenced by: '<S1546>/cal_DLTRBatMaxEntTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_CUR[5];
                       /* Referenced by: '<S1546>/cal_DLTRBatMaxEntTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_1X[5];/* Referenced by:
                                                                      * '<S1545>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      * '<S1547>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_CUR[5];/* Referenced by:
                                                                      * '<S1545>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      * '<S1547>/cal_DLTRDCBatMaxEntTempB_CUR'
                                                                      */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_1X[5];
                    /* Referenced by: '<S1565>/cal_DLTRDCBatMaxExitTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_CUR[5];
                    /* Referenced by: '<S1565>/cal_DLTRDCBatMaxExitTempB_CUR' */
extern CALDATA const volatile float32 cal_DLTRIPUTempExitVal;/* Referenced by: '<S1566>/Constant' */
extern CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_1X[5];
                 /* Referenced by: '<S1565>/cal_DLTRNotDCBatMaxExitTempC_CUR' */
extern CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_CUR[5];
                 /* Referenced by: '<S1565>/cal_DLTRNotDCBatMaxExitTempC_CUR' */
extern CALDATA const volatile float32 cal_DcutTPidDeadBand;/* Referenced by:
                                                            * '<S228>/Kp11'
                                                            * '<S230>/Kp11'
                                                            */
extern CALDATA const volatile float32 cal_DcutTempPidLL;/* Referenced by:
                                                         * '<S228>/Kp6'
                                                         * '<S230>/Kp6'
                                                         */
extern CALDATA const volatile float32 cal_DcutTempPidUL;/* Referenced by:
                                                         * '<S228>/Kp5'
                                                         * '<S230>/Kp5'
                                                         */
extern CALDATA const volatile float32 cal_DcutTempPid_IsumMax;/* Referenced by:
                                                               * '<S228>/Kp8'
                                                               * '<S230>/Kp8'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_IsumMin;/* Referenced by:
                                                               * '<S228>/Kp13'
                                                               * '<S230>/Kp13'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_Ki;/* Referenced by:
                                                          * '<S228>/Kp7'
                                                          * '<S230>/Kp7'
                                                          */
extern CALDATA const volatile float32 cal_DcutTempPid_KiNeg;/* Referenced by:
                                                             * '<S228>/Kp9'
                                                             * '<S230>/Kp9'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_KiPos;/* Referenced by:
                                                             * '<S228>/Kp10'
                                                             * '<S230>/Kp10'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_Kp;/* Referenced by:
                                                          * '<S228>/Kp'
                                                          * '<S230>/Kp'
                                                          */
extern CALDATA const volatile float32 cal_DcutTempPid_KpNeg;/* Referenced by:
                                                             * '<S228>/Kp1'
                                                             * '<S230>/Kp1'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_KpPos;/* Referenced by:
                                                             * '<S228>/Kp2'
                                                             * '<S230>/Kp2'
                                                             */
extern CALDATA const volatile float32 cal_DcutTempPid_pWinNeg;/* Referenced by:
                                                               * '<S228>/Kp4'
                                                               * '<S230>/Kp4'
                                                               */
extern CALDATA const volatile float32 cal_DcutTempPid_pWinPos;/* Referenced by:
                                                               * '<S228>/Kp3'
                                                               * '<S230>/Kp3'
                                                               */
extern CALDATA const volatile float32 cal_DefaultSetTemp;/* Referenced by: '<S207>/Constant' */
extern CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_1X[7];
                    /* Referenced by: '<S1533>/cal_DisChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_CUR[7];
                    /* Referenced by: '<S1533>/cal_DisChrgBatHeatTrgTemp_CUR' */
extern CALDATA const volatile float32 cal_DrDuctFaceFloorFaFactor;/* Referenced by: '<S226>/Constant3' */
extern CALDATA const volatile float32 cal_DrDuctFaceFloorFoFactor;/* Referenced by: '<S226>/Constant4' */
extern CALDATA const volatile float32 cal_DrDuctSenFailDeflt;
                       /* Referenced by: '<S175>/cal_DrDuctSensorFailDefault' */
extern CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOff;
/* Referenced by: '<S389>/On:cal_DrErrOfEvaDVT2CoolMixOn Off:cal_DrErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOn;
/* Referenced by: '<S389>/On:cal_DrErrOfEvaDVT2CoolMixOn Off:cal_DrErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOff;
/* Referenced by: '<S389>/On:cal_DrErrOfPtcDVT2HeatMixOn Off:cal_DrErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOn;
/* Referenced by: '<S389>/On:cal_DrErrOfPtcDVT2HeatMixOn Off:cal_DrErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandNeg;/* Referenced by: '<S281>/Kp12' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandPos;/* Referenced by: '<S281>/Kp11' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKi;/* Referenced by: '<S281>/Kp7' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKiNeg;/* Referenced by: '<S281>/Kp9' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKiPos;/* Referenced by: '<S281>/Kp10' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKp;/* Referenced by: '<S281>/Kp' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKpNeg;/* Referenced by: '<S281>/Kp1' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDKpPos;/* Referenced by: '<S281>/Kp2' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL;/* Referenced by:
                                                            * '<S281>/Kp6'
                                                            * '<S282>/Constant1'
                                                            * '<S307>/Constant4'
                                                            */
extern CALDATA const volatile uint8 cal_DrEvaDesValPIDLL_2X[4];
                          /* Referenced by: '<S275>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL_2Y[7];
                          /* Referenced by: '<S275>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDLL_MAP[28];
                          /* Referenced by: '<S275>/cal_DrEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_DrEvaDesValPIDUL;/* Referenced by:
                                                            * '<S281>/Kp5'
                                                            * '<S282>/Constant'
                                                            * '<S307>/Constant3'
                                                            */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMax;/* Referenced by: '<S281>/Kp8' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMin;/* Referenced by: '<S281>/Kp13' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_pWinNeg;/* Referenced by: '<S281>/Kp4' */
extern CALDATA const volatile float32 cal_DrEvaDesValPID_pWinPos;/* Referenced by: '<S281>/Kp3' */
extern CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_1X[4];
                      /* Referenced by: '<S281>/cal_DrEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_CUR[4];
                      /* Referenced by: '<S281>/cal_DrEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetDefog_1X[8];
                          /* Referenced by: '<S389>/cal_DrMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetDefog_CUR[8];
                          /* Referenced by: '<S389>/cal_DrMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_1X[8];
                     /* Referenced by: '<S389>/cal_DrMixBacSetFaceHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_CUR[8];
                     /* Referenced by: '<S389>/cal_DrMixBacSetFaceHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFace_1X[8];
                           /* Referenced by: '<S389>/cal_DrMixBacSetFace_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetFace_CUR[8];
                           /* Referenced by: '<S389>/cal_DrMixBacSetFace_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_1X[8];
                  /* Referenced by: '<S389>/cal_DrMixBacSetHeaterDeforst_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_CUR[8];
                  /* Referenced by: '<S389>/cal_DrMixBacSetHeaterDeforst_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeater_1X[8];
                         /* Referenced by: '<S389>/cal_DrMixBacSetHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixBacSetHeater_CUR[8];
                         /* Referenced by: '<S389>/cal_DrMixBacSetHeater_CUR' */
extern CALDATA const volatile float32 cal_DrMixDesValPIDIntegDeadBand;/* Referenced by: '<S390>/Kp11' */
extern CALDATA const volatile uint8 cal_DrMixDesValPIDLL;/* Referenced by: '<S390>/Kp6' */
extern CALDATA const volatile uint8 cal_DrMixDesValPIDUL;/* Referenced by: '<S390>/Kp5' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_IsumMax;/* Referenced by: '<S390>/Kp8' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_IsumMin;/* Referenced by: '<S390>/Kp13' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_Ki;/* Referenced by: '<S390>/Kp7' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KiNeg;/* Referenced by: '<S390>/Kp9' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KiPos;/* Referenced by: '<S390>/Kp10' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_Kp;/* Referenced by: '<S390>/Kp' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KpNeg;/* Referenced by: '<S390>/Kp1' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_KpPos;/* Referenced by: '<S390>/Kp2' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_pWinNeg;/* Referenced by: '<S390>/Kp4' */
extern CALDATA const volatile float32 cal_DrMixDesValPID_pWinPos;/* Referenced by: '<S390>/Kp3' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4InHeat;/* Referenced by: '<S342>/Kp16' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4OutHeat;/* Referenced by: '<S342>/Kp26' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKi;/* Referenced by: '<S342>/Kp7' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKiNeg;/* Referenced by: '<S342>/Kp9' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKiPos;/* Referenced by: '<S342>/Kp10' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKp;/* Referenced by: '<S342>/Kp' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKpNeg;/* Referenced by: '<S342>/Kp1' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDKpPos;/* Referenced by: '<S342>/Kp2' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDLL;/* Referenced by: '<S342>/Kp6' */
extern CALDATA const volatile float32 cal_DrPtcDesValPIDUL;/* Referenced by: '<S342>/Kp5' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMax;/* Referenced by: '<S342>/Kp8' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMin;/* Referenced by: '<S342>/Kp13' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_pWinNeg;/* Referenced by: '<S342>/Kp4' */
extern CALDATA const volatile float32 cal_DrPtcDesValPID_pWinPos;/* Referenced by: '<S342>/Kp3' */
extern CALDATA const volatile float32 cal_DvtCoff;/* Referenced by: '<S183>/Constant' */
extern CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_1X[8];
                    /* Referenced by: '<S187>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_CUR[8];
                    /* Referenced by: '<S187>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_1X[8];
                    /* Referenced by: '<S187>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_CUR[8];
                    /* Referenced by: '<S187>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2X[10];
                     /* Referenced by: '<S187>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2Y[10];
                     /* Referenced by: '<S187>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_MAP[100];
                     /* Referenced by: '<S187>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern CALDATA const volatile float32 cal_DvtDesValPIDIntegDeadBand;/* Referenced by: '<S187>/Constant7' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKi_1X[9];
                            /* Referenced by: '<S187>/cal_DvtDesValPIDKi_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKi_CUR[9];
                            /* Referenced by: '<S187>/cal_DvtDesValPIDKi_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKp_1X[9];
                            /* Referenced by: '<S187>/cal_DvtDesValPIDKp_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPIDKp_CUR[9];
                            /* Referenced by: '<S187>/cal_DvtDesValPIDKp_CUR' */
extern CALDATA const volatile float32 cal_DvtDesValPID_Ki;/* Referenced by: '<S187>/Kp7' */
extern CALDATA const volatile float32 cal_DvtDesValPID_Kp;/* Referenced by: '<S187>/Kp' */
extern CALDATA const volatile float32 cal_DvtDesValPID_LL;/* Referenced by:
                                                           * '<S181>/Kp2'
                                                           * '<S181>/Kp6'
                                                           * '<S182>/Kp2'
                                                           * '<S182>/Kp6'
                                                           * '<S187>/Kp6'
                                                           */
extern CALDATA const volatile float32 cal_DvtDesValPID_UL;/* Referenced by:
                                                           * '<S181>/Kp1'
                                                           * '<S181>/Kp5'
                                                           * '<S182>/Kp1'
                                                           * '<S182>/Kp5'
                                                           */
extern CALDATA const volatile float32 cal_DvtDesValPID_pWinNeg;/* Referenced by: '<S187>/Kp4' */
extern CALDATA const volatile float32 cal_DvtDesValPID_pWinPos;/* Referenced by: '<S187>/Kp3' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_2X[6];
                            /* Referenced by: '<S178>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_2Y[7];
                            /* Referenced by: '<S178>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_ECOEvaDesValLL_MAP[42];
                            /* Referenced by: '<S178>/cal_ECOEvaDesValLL_MAP' */
extern CALDATA const volatile float32 cal_EEEnvAndEnvDiffVal;/* Referenced by: '<S1072>/Switch12' */
extern CALDATA const volatile float32 cal_EVAPSufTempClsSOV;/* Referenced by: '<S446>/Relay' */
extern CALDATA const volatile float32 cal_EVAPSufTempOpenSOV;/* Referenced by: '<S446>/Relay' */
extern CALDATA const volatile uint16 cal_EVAPSurfTempVolAmend_1X[2];
                     /* Referenced by: '<S1751>/cal_EVAPSurfTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EVAPSurfTempVolAmend_CUR[2];
                     /* Referenced by: '<S1751>/cal_EVAPSurfTempVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_EVAPTempVolAmend_1X[2];
                         /* Referenced by: '<S1750>/cal_EVAPTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EVAPTempVolAmend_CUR[2];
                         /* Referenced by: '<S1750>/cal_EVAPTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_EntExtDefTime;/* Referenced by: '<S1729>/Constant3' */
extern CALDATA const volatile boolean cal_EnvFailSwFlg;/* Referenced by: '<S1074>/Constant' */
extern CALDATA const volatile float32 cal_EnvTAme_1X[11];
                                  /* Referenced by: '<S1073>/cal_EnvTAme_CUR' */
extern CALDATA const volatile float32 cal_EnvTAme_CUR[11];
                                  /* Referenced by: '<S1073>/cal_EnvTAme_CUR' */
extern CALDATA const volatile float32 cal_EnvTempCorData;/* Referenced by: '<S1085>/Constant' */
extern CALDATA const volatile boolean cal_EnvTempCorEnb;/* Referenced by: '<S1085>/Constant1' */
extern CALDATA const volatile float32 cal_EnvTempRiseStep;/* Referenced by: '<S1072>/Constant3' */
extern CALDATA const volatile float32 cal_EnvTempStep;/* Referenced by: '<S180>/Constant3' */
extern CALDATA const volatile uint16 cal_EnvVolAmend_1X[2];
                              /* Referenced by: '<S1074>/cal_EnvVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_EnvVolAmend_CUR[2];
                              /* Referenced by: '<S1074>/cal_EnvVolAmend_CUR' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForEvaLL;/* Referenced by: '<S178>/Constant4' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForEvaUL;/* Referenced by: '<S178>/Constant3' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForPtcLL;/* Referenced by: '<S179>/Constant2' */
extern CALDATA const volatile float32 cal_ErrAmbTDvtForPtcUL;/* Referenced by: '<S179>/Constant1' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInComf_OFF;
/* Referenced by: '<S88>/On:cal_ErrOfEvaActTargInComf_ON Off:cal_ErrOfEvaActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInComf_ON;
/* Referenced by: '<S88>/On:cal_ErrOfEvaActTargInComf_ON Off:cal_ErrOfEvaActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInDefog_OFF;
/* Referenced by: '<S89>/On:cal_ErrOfEvaActTargInDefog_ON Off:cal_ErrOfEvaActTargInDefog_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInDefog_ON;
/* Referenced by: '<S89>/On:cal_ErrOfEvaActTargInDefog_ON Off:cal_ErrOfEvaActTargInDefog_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInEcon_OFF;
/* Referenced by: '<S88>/On:cal_ErrOfEvaActTargInEcon_ON Off:cal_ErrOfEvaActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfEvaActTargInEcon_ON;
/* Referenced by: '<S88>/On:cal_ErrOfEvaActTargInEcon_ON Off:cal_ErrOfEvaActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInComf_OFF;
/* Referenced by: '<S95>/On:cal_ErrOfPTCActTargInComf_ON Off:cal_ErrOfPTCActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInComf_ON;
/* Referenced by: '<S95>/On:cal_ErrOfPTCActTargInComf_ON Off:cal_ErrOfPTCActTargInComf_OFF ' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInEcon_OFF;
/* Referenced by: '<S95>/On:cal_ErrOfPTCActTargInEcon_ON Off:cal_ErrOfPTCActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_ErrOfPTCActTargInEcon_ON;
/* Referenced by: '<S95>/On:cal_ErrOfPTCActTargInEcon_ON Off:cal_ErrOfPTCActTargInEcon_OFF' */
extern CALDATA const volatile float32 cal_EvaDesLLMax;/* Referenced by:
                                                       * '<S178>/Constant1'
                                                       * '<S275>/Constant1'
                                                       * '<S276>/Constant1'
                                                       * '<S279>/Constant4'
                                                       */
extern CALDATA const volatile float32 cal_EvaDesLLMin;/* Referenced by:
                                                       * '<S275>/Constant8'
                                                       * '<S276>/Constant8'
                                                       * '<S279>/Constant2'
                                                       * '<S279>/Constant6'
                                                       */
extern CALDATA const volatile boolean cal_EvaDesLLSelect;/* Referenced by: '<S279>/Constant' */
extern CALDATA const volatile boolean cal_EvaEnable;/* Referenced by:
                                                     * '<S386>/Constant1'
                                                     * '<S387>/Constant1'
                                                     */
extern CALDATA const volatile float32 cal_EvapBacTempDesACBi_1X[6];
                        /* Referenced by: '<S282>/cal_EvapBacTempDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesACBi_CUR[6];
                        /* Referenced by: '<S282>/cal_EvapBacTempDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesAC_1X[6];
                          /* Referenced by: '<S282>/cal_EvapBacTempDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesAC_CUR[6];
                          /* Referenced by: '<S282>/cal_EvapBacTempDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesDefog_1X[6];
                       /* Referenced by: '<S282>/cal_EvapBacTempDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesDefog_CUR[6];
                       /* Referenced by: '<S282>/cal_EvapBacTempDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFootDe_1X[6];
                      /* Referenced by: '<S282>/cal_EvapBacTempDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFootDe_CUR[6];
                      /* Referenced by: '<S282>/cal_EvapBacTempDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFoot_1X[6];
                        /* Referenced by: '<S282>/cal_EvapBacTempDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempDesFoot_CUR[6];
                        /* Referenced by: '<S282>/cal_EvapBacTempDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_1X[6];
                      /* Referenced by: '<S307>/cal_EvapBacTempPsDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_CUR[6];
                      /* Referenced by: '<S307>/cal_EvapBacTempPsDesACBi_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesAC_1X[6];
                        /* Referenced by: '<S307>/cal_EvapBacTempPsDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesAC_CUR[6];
                        /* Referenced by: '<S307>/cal_EvapBacTempPsDesAC_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_1X[6];
                     /* Referenced by: '<S307>/cal_EvapBacTempPsDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_CUR[6];
                     /* Referenced by: '<S307>/cal_EvapBacTempPsDesDefog_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_1X[6];
                    /* Referenced by: '<S307>/cal_EvapBacTempPsDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_CUR[6];
                    /* Referenced by: '<S307>/cal_EvapBacTempPsDesFootDe_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_1X[6];
                      /* Referenced by: '<S307>/cal_EvapBacTempPsDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_CUR[6];
                      /* Referenced by: '<S307>/cal_EvapBacTempPsDesFoot_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimByEnv_1X[8];
                         /* Referenced by: '<S279>/cal_EvapDesLoLimByEnv_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimByEnv_CUR[8];
                         /* Referenced by: '<S279>/cal_EvapDesLoLimByEnv_CUR' */
extern CALDATA const volatile uint16 cal_EvapDesLoLimBySolarCor_1X[2];
                    /* Referenced by: '<S279>/cal_EvapDesLoLimBySolarCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesLoLimBySolarCor_CUR[2];
                    /* Referenced by: '<S279>/cal_EvapDesLoLimBySolarCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempCabinCor_1X[6];
                       /* Referenced by: '<S282>/cal_EvapDesTempCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempCabinCor_CUR[6];
                       /* Referenced by: '<S282>/cal_EvapDesTempCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_2X[6];
                         /* Referenced by: '<S282>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_2Y[6];
                         /* Referenced by: '<S282>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempEnvCor_MAP[36];
                         /* Referenced by: '<S282>/cal_EvapDesTempEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_EvapDesTempFanCor_1X[4];
                         /* Referenced by: '<S282>/cal_EvapDesTempFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempFanCor_CUR[4];
                         /* Referenced by: '<S282>/cal_EvapDesTempFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_1X[6];
                     /* Referenced by: '<S307>/cal_EvapDesTempPsCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_CUR[6];
                     /* Referenced by: '<S307>/cal_EvapDesTempPsCabinCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2X[6];
                       /* Referenced by: '<S307>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2Y[6];
                       /* Referenced by: '<S307>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_MAP[36];
                       /* Referenced by: '<S307>/cal_EvapDesTempPsEnvCor_MAP' */
extern CALDATA const volatile uint8 cal_EvapDesTempPsFanCor_1X[4];
                       /* Referenced by: '<S307>/cal_EvapDesTempPsFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapDesTempPsFanCor_CUR[4];
                       /* Referenced by: '<S307>/cal_EvapDesTempPsFanCor_CUR' */
extern CALDATA const volatile float32 cal_EvapSurTempData;/* Referenced by: '<S1838>/Constant' */
extern CALDATA const volatile boolean cal_EvapSurTempDataEnb;/* Referenced by: '<S1838>/Constant1' */
extern CALDATA const volatile float32 cal_EvapTempData;/* Referenced by: '<S1828>/Constant' */
extern CALDATA const volatile boolean cal_EvapTempDataEnb;/* Referenced by: '<S1828>/Constant1' */
extern CALDATA const volatile float32 cal_ExhSuperHeatFilter;/* Referenced by: '<S899>/Constant1' */
extern CALDATA const volatile uint16 cal_ExhaustTime;/* Referenced by: '<S12>/Constant7' */
extern CALDATA const volatile float32 cal_ExitExtDefTime;/* Referenced by: '<S1730>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefBatMinT;/* Referenced by: '<S939>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefEnvMaxTemp;/* Referenced by: '<S1729>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefEnvMinTemp;/* Referenced by: '<S1729>/Constant1' */
extern CALDATA const volatile boolean cal_ExtDefFlgData;/* Referenced by: '<S1732>/Constant' */
extern CALDATA const volatile boolean cal_ExtDefFlgDataEnb;/* Referenced by: '<S1732>/Constant1' */
extern CALDATA const volatile float32 cal_ExtDefOHXOffTemp;/* Referenced by: '<S1734>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefOHXOnTemp;/* Referenced by: '<S1733>/Constant' */
extern CALDATA const volatile float32 cal_ExtDefPTCTrgTemp;/* Referenced by: '<S444>/Constant6' */
extern CALDATA const volatile float32 cal_ExtDefTempDiff;/* Referenced by: '<S1729>/Constant2' */
extern CALDATA const volatile uint8 cal_FANSpdHotStartLL;/* Referenced by: '<S51>/Constant12' */
extern CALDATA const volatile uint8 cal_FANSpdHotStartUL;/* Referenced by: '<S50>/Constant27' */
extern CALDATA const volatile uint8 cal_FANSpdModeShiftMax;/* Referenced by: '<S50>/Constant3' */
extern CALDATA const volatile float32 cal_FaceDuctTempData;/* Referenced by: '<S1770>/Constant' */
extern CALDATA const volatile boolean cal_FaceDuctTempEnb;/* Referenced by: '<S1770>/Constant1' */
extern CALDATA const volatile uint16 cal_FaceDuctVolAmend_1X[2];
                         /* Referenced by: '<S1742>/cal_FaceDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_FaceDuctVolAmend_CUR[2];
                         /* Referenced by: '<S1742>/cal_FaceDuctVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_FallTime2Tamb;
                                    /* Referenced by: '<S1072>/TempRampStep3' */
extern CALDATA const volatile uint16 cal_FalseTime2EnvTamb;
                                     /* Referenced by: '<S180>/TempRampStep3' */
extern CALDATA const volatile uint16 cal_FalseTime2Solar;
                                     /* Referenced by: '<S185>/TempRampStep2' */
extern CALDATA const volatile uint8 cal_FanCtrlOff;/* Referenced by: '<S920>/Constant2' */
extern CALDATA const volatile uint8 cal_FanLevelToPWM[10];/* Referenced by:
                                                           * '<S55>/Constant2'
                                                           * '<S56>/Constant18'
                                                           * '<S57>/Constant2'
                                                           * '<S59>/Constant1'
                                                           * '<S59>/Constant11'
                                                           * '<S59>/Constant14'
                                                           * '<S59>/Constant16'
                                                           * '<S59>/Constant18'
                                                           * '<S59>/Constant2'
                                                           * '<S59>/Constant4'
                                                           * '<S59>/Constant7'
                                                           * '<S59>/Constant9'
                                                           */
extern CALDATA const volatile boolean cal_FixPIDSecletFlag;/* Referenced by:
                                                            * '<S386>/Constant'
                                                            * '<S387>/Constant'
                                                            * '<S275>/Constant'
                                                            * '<S276>/Constant'
                                                            * '<S335>/Constant'
                                                            * '<S336>/Constant'
                                                            * '<S184>/Constant'
                                                            */
extern CALDATA const volatile float32 cal_FootDuctTempData;/* Referenced by: '<S1780>/Constant' */
extern CALDATA const volatile boolean cal_FootDuctTempEnb;/* Referenced by: '<S1780>/Constant1' */
extern CALDATA const volatile uint16 cal_FootDuctVolAmend_1X[2];
                         /* Referenced by: '<S1743>/cal_FootDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_FootDuctVolAmend_CUR[2];
                         /* Referenced by: '<S1743>/cal_FootDuctVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_HAPevap_min;
                             /* Referenced by: '<S39>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPparkdly_time;
                             /* Referenced by: '<S39>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPpurge_time;
                             /* Referenced by: '<S39>/AirConditionStartState' */
extern CALDATA const volatile uint16 cal_HAPtimelim2activtic;
                             /* Referenced by: '<S39>/AirConditionStartState' */
extern CALDATA const volatile float32 cal_HPAndLPDiffMaxVal;/* Referenced by: '<S521>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtlKi;/* Referenced by: '<S821>/Constant11' */
extern CALDATA const volatile float32 cal_HPEXVCtlKiDeadzoneNeg;/* Referenced by: '<S821>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVCtlKiDeadzonePos;/* Referenced by: '<S821>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtlKisumMax;/* Referenced by: '<S821>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtlKisumMin;/* Referenced by: '<S821>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtlKp;/* Referenced by: '<S821>/Constant10' */
extern CALDATA const volatile float32 cal_HPEXVCtlKpDeadzoneNeg;/* Referenced by: '<S821>/Constant5' */
extern CALDATA const volatile float32 cal_HPEXVCtlKpDeadzonePos;/* Referenced by: '<S821>/Constant4' */
extern CALDATA const volatile float32 cal_HPEXVCtrlADeadzone;/* Referenced by: '<S858>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlADelayTime;/* Referenced by: '<S858>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFFLolmt;/* Referenced by: '<S858>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFFUplmt;/* Referenced by: '<S858>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFF_1X[5];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlAFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAFF_CUR[5];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlAFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKi_1X[6];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKi_CUR[6];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlAKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKp_1X[6];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAKp_CUR[6];
                              /* Referenced by: '<S858>/cal_HPEXVCtrlAKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAMax;/* Referenced by: '<S858>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAMin;/* Referenced by: '<S858>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlAOpenVal;/* Referenced by: '<S858>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_1X[5];
                     /* Referenced by: '<S858>/cal_HPEXVCtrlATrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_CUR[5];
                     /* Referenced by: '<S858>/cal_HPEXVCtrlATrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCDeadzone;/* Referenced by: '<S860>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCDelayTime;/* Referenced by: '<S860>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCFF_1X[5];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCFF_CUR[5];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlCFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKi_1X[8];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKi_CUR[8];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlCKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKp_1X[8];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCKp_CUR[8];
                              /* Referenced by: '<S860>/cal_HPEXVCtrlCKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCMax;/* Referenced by: '<S860>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCMin;/* Referenced by: '<S860>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlCOpenVal;/* Referenced by: '<S860>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDDeadzone;/* Referenced by: '<S861>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDDelayTime;/* Referenced by: '<S861>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFFLolmt;/* Referenced by: '<S861>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFFUplmt;/* Referenced by: '<S861>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFF_1X[5];
                              /* Referenced by: '<S861>/cal_HPEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDFF_CUR[5];
                              /* Referenced by: '<S861>/cal_HPEXVCtrlDFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKi_1X[8];
                              /* Referenced by: '<S861>/cal_HPEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKi_CUR[8];
                              /* Referenced by: '<S861>/cal_HPEXVCtrlDKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKp_1X[8];
                              /* Referenced by: '<S861>/cal_HPEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDKp_CUR[8];
                              /* Referenced by: '<S861>/cal_HPEXVCtrlDKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDMax;/* Referenced by: '<S861>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDMin;/* Referenced by: '<S861>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDOpenVal;/* Referenced by: '<S861>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_1X[5];
                     /* Referenced by: '<S861>/cal_HPEXVCtrlDTrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_CUR[5];
                     /* Referenced by: '<S861>/cal_HPEXVCtrlDTrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEDeadzone;/* Referenced by: '<S862>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEDelayTime;/* Referenced by: '<S862>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFFLolmt;/* Referenced by: '<S862>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFFUplmt;/* Referenced by: '<S862>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFF_1X[5];
                              /* Referenced by: '<S862>/cal_HPEXVCtrlEFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEFF_CUR[5];
                              /* Referenced by: '<S862>/cal_HPEXVCtrlEFF_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKi_1X[6];
                              /* Referenced by: '<S862>/cal_HPEXVCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKi_CUR[6];
                              /* Referenced by: '<S862>/cal_HPEXVCtrlEKi_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKp_1X[6];
                              /* Referenced by: '<S862>/cal_HPEXVCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEKp_CUR[6];
                              /* Referenced by: '<S862>/cal_HPEXVCtrlEKp_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEMax;/* Referenced by: '<S862>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEMin;/* Referenced by: '<S862>/Constant9' */
extern CALDATA const volatile float32 cal_HPEXVCtrlEOpenVal;/* Referenced by: '<S862>/Constant3' */
extern CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_1X[5];
                     /* Referenced by: '<S862>/cal_HPEXVCtrlETrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_CUR[5];
                     /* Referenced by: '<S862>/cal_HPEXVCtrlETrgtSubcool_CUR' */
extern CALDATA const volatile float32 cal_HPEXVDiffDown;/* Referenced by: '<S825>/Constant8' */
extern CALDATA const volatile float32 cal_HPEXVDiffDownRate;/* Referenced by: '<S825>/Constant7' */
extern CALDATA const volatile float32 cal_HPEXVDiffUp;/* Referenced by: '<S825>/Constant6' */
extern CALDATA const volatile float32 cal_HPEXVDiffUpRate;/* Referenced by: '<S825>/Constant5' */
extern CALDATA const volatile float32 cal_HPEXVDownSpdLmt;/* Referenced by:
                                                           * '<S830>/DownLmt'
                                                           * '<S830>/DownLmt1'
                                                           */
extern CALDATA const volatile boolean cal_HPEXVEnbData;/* Referenced by: '<S836>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVEnbDataEnb;/* Referenced by: '<S836>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVFloorDiff1;/* Referenced by: '<S828>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVFloorDiff2;/* Referenced by: '<S828>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVHiPressLmtOff;/* Referenced by: '<S864>/HiPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVHiPressLmtOn;/* Referenced by: '<S864>/HiPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVHiPressProOpenSpd;/* Referenced by:
                                                                  * '<S825>/Constant1'
                                                                  * '<S825>/Constant3'
                                                                  */
extern CALDATA const volatile float32 cal_HPEXVHiPressProhOff;/* Referenced by: '<S825>/HiProRelay' */
extern CALDATA const volatile float32 cal_HPEXVHiPressProhOn;/* Referenced by: '<S825>/HiProRelay' */
extern CALDATA const volatile uint8 cal_HPEXVInitReqData;/* Referenced by: '<S893>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVInitReqDataeEnb;/* Referenced by: '<S893>/Constant1' */
extern CALDATA const volatile float32 cal_HPEXVLowPressLmtOff;/* Referenced by: '<S864>/LowPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVLowPressLmtOn;/* Referenced by: '<S864>/LowPressLmt' */
extern CALDATA const volatile float32 cal_HPEXVLowPressProOpenSpd;/* Referenced by:
                                                                   * '<S825>/Constant'
                                                                   * '<S825>/Constant2'
                                                                   */
extern CALDATA const volatile float32 cal_HPEXVOpenCtrlDownSpdLmt;/* Referenced by:
                                                                   * '<S831>/DownLmt'
                                                                   * '<S831>/DownLmt1'
                                                                   */
extern CALDATA const volatile float32 cal_HPEXVOpenCtrlUpSpdLmt;/* Referenced by:
                                                                 * '<S831>/UpLmt'
                                                                 * '<S831>/UpLmt2'
                                                                 */
extern CALDATA const volatile float32 cal_HPEXVPosData;/* Referenced by: '<S826>/Constant' */
extern CALDATA const volatile boolean cal_HPEXVPosDataEnb;/* Referenced by: '<S826>/Constant1' */
extern CALDATA const volatile boolean cal_HPEXVStepLmtSw;/* Referenced by: '<S818>/Constant2' */
extern CALDATA const volatile float32 cal_HPEXVSubCoolflt;/* Referenced by:
                                                           * '<S858>/Constant11'
                                                           * '<S861>/Constant11'
                                                           * '<S862>/Constant11'
                                                           */
extern CALDATA const volatile float32 cal_HPEXVUpSpdLmt;/* Referenced by:
                                                         * '<S830>/UpLmt'
                                                         * '<S830>/UpLmt2'
                                                         */
extern CALDATA const volatile float32 cal_HPEXVlowPressLmtTrg;/* Referenced by: '<S822>/Constant' */
extern CALDATA const volatile float32 cal_HPEXVlowPressProhOff;/* Referenced by: '<S825>/LowProRelay' */
extern CALDATA const volatile float32 cal_HPEXVlowPressProhOn;/* Referenced by: '<S825>/LowProRelay' */
extern CALDATA const volatile float32 cal_HPHighLmtVal;/* Referenced by: '<S1754>/Constant' */
extern CALDATA const volatile float32 cal_HPProVal1;/* Referenced by: '<S531>/Relay' */
extern CALDATA const volatile float32 cal_HPProVal1Relay;/* Referenced by: '<S531>/Relay' */
extern CALDATA const volatile float32 cal_HPProVal2;/* Referenced by:
                                                     * '<S529>/Relay1'
                                                     * '<S531>/Relay1'
                                                     */
extern CALDATA const volatile float32 cal_HPProVal2Relay;/* Referenced by:
                                                          * '<S529>/Relay1'
                                                          * '<S531>/Relay1'
                                                          */
extern CALDATA const volatile float32 cal_HPProVal3;/* Referenced by:
                                                     * '<S526>/Relay2'
                                                     * '<S528>/Relay2'
                                                     * '<S529>/Relay2'
                                                     * '<S531>/Relay2'
                                                     */
extern CALDATA const volatile float32 cal_HPProVal3Relay;/* Referenced by:
                                                          * '<S526>/Relay2'
                                                          * '<S529>/Relay2'
                                                          * '<S531>/Relay2'
                                                          */
extern CALDATA const volatile float32 cal_HPProVal4;/* Referenced by: '<S528>/Relay2' */
extern CALDATA const volatile uint8 cal_HVPartModeData;/* Referenced by: '<S1735>/Constant' */
extern CALDATA const volatile boolean cal_HVPartModeEnb;/* Referenced by: '<S1735>/Constant1' */
extern CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOff;/* Referenced by: '<S500>/Relay1' */
extern CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOn;/* Referenced by: '<S500>/Relay1' */
extern CALDATA const volatile uint8 cal_HeatCabinAndCoolBatFanSpd;/* Referenced by: '<S443>/Constant1' */
extern CALDATA const volatile float32 cal_HeatFanCtrl_2X[4];
                               /* Referenced by: '<S918>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_HeatFanCtrl_2Y[13];
                               /* Referenced by: '<S918>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile uint8 cal_HeatFanCtrl_MAP[52];
                               /* Referenced by: '<S918>/cal_HeatFanCtrl_MAP' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsDownSpd;/* Referenced by: '<S455>/Constant1' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP1;/* Referenced by: '<S455>/Relay13' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP2;/* Referenced by: '<S455>/Relay13' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP3;/* Referenced by: '<S455>/Relay12' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP4;/* Referenced by: '<S455>/Relay12' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP5;/* Referenced by: '<S455>/Relay14' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP6;/* Referenced by: '<S455>/Relay14' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP7;/* Referenced by: '<S455>/Relay15' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP8;/* Referenced by: '<S455>/Relay15' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsDownSpd;/* Referenced by: '<S455>/Constant3' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP1;/* Referenced by: '<S455>/Relay5' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP2;/* Referenced by: '<S455>/Relay5' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP3;/* Referenced by: '<S455>/Relay4' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP4;/* Referenced by: '<S455>/Relay4' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP5;/* Referenced by: '<S455>/Relay6' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP6;/* Referenced by: '<S455>/Relay6' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP7;/* Referenced by: '<S455>/Relay7' */
extern CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP8;/* Referenced by: '<S455>/Relay7' */
extern CALDATA const volatile float32 cal_HeatPwrOn;/* Referenced by:
                                                     * '<S1400>/Constant'
                                                     * '<S1411>/Constant'
                                                     * '<S1485>/Constant'
                                                     * '<S1498>/Constant'
                                                     */
extern CALDATA const volatile float32 cal_HiPressData;/* Referenced by: '<S1865>/Constant' */
extern CALDATA const volatile boolean cal_HiPressDataEnb;/* Referenced by: '<S1865>/Constant1' */
extern CALDATA const volatile float32 cal_IGBTDownLmtTemp;/* Referenced by: '<S1315>/Relay1' */
extern CALDATA const volatile float32 cal_IGBTUpLmtTemp;/* Referenced by: '<S1315>/Relay1' */
extern CALDATA const volatile uint8 cal_IGNONDelayTime;/* Referenced by: '<S30>/Constant3' */
extern CALDATA const volatile uint8 cal_InnerRecTrgPos;/* Referenced by: '<S1232>/Constant1' */
extern CALDATA const volatile float32 cal_LAirmixNomOutWaterT;/* Referenced by:
                                                               * '<S391>/Constant6'
                                                               * '<S417>/Constant6'
                                                               */
extern CALDATA const volatile float32 cal_LCCOutHiPressRaw_1X[2];
                         /* Referenced by: '<S1754>/cal_LCCOutHiPressRaw_CUR' */
extern CALDATA const volatile float32 cal_LCCOutHiPressRaw_CUR[2];
                         /* Referenced by: '<S1754>/cal_LCCOutHiPressRaw_CUR' */
extern CALDATA const volatile uint8 cal_LPFanCtrl;/* Referenced by: '<S919>/Constant11' */
extern CALDATA const volatile float32 cal_LPFanOff;/* Referenced by: '<S932>/Constant' */
extern CALDATA const volatile float32 cal_LPFanOn;/* Referenced by: '<S931>/Constant' */
extern CALDATA const volatile float32 cal_LPProOffTimer;/* Referenced by: '<S919>/Constant1' */
extern CALDATA const volatile float32 cal_LPProOnTimer;/* Referenced by: '<S919>/Constant' */
extern CALDATA const volatile float32 cal_LTRExitBatMaxCellTemp;/* Referenced by: '<S1471>/Constant' */
extern CALDATA const volatile float32 cal_LTRFanCtrl_1X[2];/* Referenced by:
                                                            * '<S926>/Constant1'
                                                            * '<S926>/Constant2'
                                                            */
extern CALDATA const volatile uint8 cal_LTRFanCtrl_1Y[3];/* Referenced by:
                                                          * '<S926>/Constant4'
                                                          * '<S926>/Constant6'
                                                          * '<S926>/Constant9'
                                                          */
extern CALDATA const volatile float32 cal_LTRIGBTMaxExitTempB;/* Referenced by: '<S1639>/Constant' */
extern CALDATA const volatile float32 cal_LTRIGBTTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1063>/Constant1'
                                                                      * '<S1063>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRIGBTTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                     * '<S1063>/Constant4'
                                                                     * '<S1063>/Constant6'
                                                                     * '<S1063>/Constant9'
                                                                     */
extern CALDATA const volatile float32 cal_LTRIPUTempFanCtrl_1X[2];/* Referenced by:
                                                                   * '<S925>/Constant1'
                                                                   * '<S925>/Constant2'
                                                                   */
extern CALDATA const volatile uint8 cal_LTRIPUTempFanCtrl_1Y[3];/* Referenced by:
                                                                 * '<S925>/Constant4'
                                                                 * '<S925>/Constant6'
                                                                 * '<S925>/Constant9'
                                                                 */
extern CALDATA const volatile float32 cal_LTRIPUTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1067>/Constant1'
                                                                      * '<S1067>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRIPUTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                    * '<S1067>/Constant4'
                                                                    * '<S1067>/Constant6'
                                                                    * '<S1067>/Constant9'
                                                                    */
extern CALDATA const volatile float32 cal_LTRMotorInletMaxExitTempA;/* Referenced by: '<S1638>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorMaxEntTemp;/* Referenced by: '<S1670>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorMaxExitTemp;/* Referenced by: '<S1641>/Constant' */
extern CALDATA const volatile float32 cal_LTRMotorTempMotPMPCtrl_1X[2];/* Referenced by:
                                                                      * '<S1064>/Constant1'
                                                                      * '<S1064>/Constant2'
                                                                      */
extern CALDATA const volatile uint8 cal_LTRMotorTempMotPMPCtrl_1Y[3];/* Referenced by:
                                                                      * '<S1064>/Constant4'
                                                                      * '<S1064>/Constant6'
                                                                      * '<S1064>/Constant9'
                                                                      */
extern CALDATA const volatile float32 cal_LTT1DownMCV_1X[5];
                               /* Referenced by: '<S649>/cal_LTT1DownMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1DownMCV_CUR[5];
                               /* Referenced by: '<S649>/cal_LTT1DownMCV_CUR' */
extern CALDATA const volatile float32 cal_LTT1StbyMCV_1X[6];
                               /* Referenced by: '<S649>/cal_LTT1StbyMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1StbyMCV_CUR[6];
                               /* Referenced by: '<S649>/cal_LTT1StbyMCV_CUR' */
extern CALDATA const volatile float32 cal_LTT1UpMCV_1X[5];
                                 /* Referenced by: '<S649>/cal_LTT1UpMCV_CUR' */
extern CALDATA const volatile uint8 cal_LTT1UpMCV_CUR[5];
                                 /* Referenced by: '<S649>/cal_LTT1UpMCV_CUR' */
extern CALDATA const volatile boolean cal_LessThanT1CalSwt;/* Referenced by:
                                                            * '<S647>/Constant3'
                                                            * '<S649>/Constant3'
                                                            */
extern CALDATA const volatile float32 cal_LoPressData;/* Referenced by: '<S1789>/Constant' */
extern CALDATA const volatile boolean cal_LoPressDataEnb;/* Referenced by: '<S1789>/Constant1' */
extern CALDATA const volatile float32 cal_LoPressRaw_1X[2];
                                  /* Referenced by: '<S1744>/cal_LoPress_CUR' */
extern CALDATA const volatile float32 cal_LoPressRaw_CUR[2];
                                  /* Referenced by: '<S1744>/cal_LoPress_CUR' */
extern CALDATA const volatile float32 cal_MBIGBTHighExitTempG;/* Referenced by: '<S1628>/Constant' */
extern CALDATA const volatile float32 cal_MBIPUDevHighExitTempI;/* Referenced by: '<S1632>/Constant' */
extern CALDATA const volatile float32 cal_MBMotorInletHighExitTempH;/* Referenced by: '<S1629>/Constant' */
extern CALDATA const volatile uint8 cal_MCVFltStsDelayTime;/* Referenced by: '<S642>/Constant5' */
extern CALDATA const volatile float32 cal_MCVPosDiffDelayTime;/* Referenced by: '<S642>/Constant2' */
extern CALDATA const volatile uint8 cal_MixCoolTrgPos;/* Referenced by: '<S1233>/Constant1' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinCoolingEn_OFF;/* Referenced by: '<S88>/Constant7' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinCoolingEn_ON;/* Referenced by: '<S88>/Constant6' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinHeatingEn_OFF;
/* Referenced by: '<S93>/On:cal_MixDoor2CabinHeatingEn_ON Off:cal_MixDoor2CabinHeatingEn_OFF ' */
extern CALDATA const volatile uint8 cal_MixDoor2CabinHeatingEn_ON;
/* Referenced by: '<S93>/On:cal_MixDoor2CabinHeatingEn_ON Off:cal_MixDoor2CabinHeatingEn_OFF ' */
extern CALDATA const volatile float32 cal_MixDoorClsFF_1X[8];
                              /* Referenced by: '<S390>/cal_MixDoorClsFF_CUR' */
extern CALDATA const volatile float32 cal_MixDoorClsFF_CUR[8];
                              /* Referenced by: '<S390>/cal_MixDoorClsFF_CUR' */
extern CALDATA const volatile boolean cal_MixDoorEnb;/* Referenced by:
                                                      * '<S1233>/Judge'
                                                      * '<S1233>/Constant6'
                                                      * '<S1266>/Constant1'
                                                      * '<S1267>/Constant1'
                                                      */
extern CALDATA const volatile float32 cal_MixDoorKi_1X[8];
                                 /* Referenced by: '<S390>/cal_MixDoorKi_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKi_CUR[8];
                                 /* Referenced by: '<S390>/cal_MixDoorKi_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKp_1X[8];
                                 /* Referenced by: '<S390>/cal_MixDoorKp_CUR' */
extern CALDATA const volatile float32 cal_MixDoorKp_CUR[8];
                                 /* Referenced by: '<S390>/cal_MixDoorKp_CUR' */
extern CALDATA const volatile uint8 cal_MixDoorNData;/* Referenced by: '<S1266>/Constant' */
extern CALDATA const volatile float32 cal_MixDoorNErr;/* Referenced by: '<S1233>/Judge' */
extern CALDATA const volatile uint8 cal_MixDoorPData;/* Referenced by: '<S1267>/Constant' */
extern CALDATA const volatile float32 cal_MixDoorPErr;/* Referenced by: '<S1233>/Judge' */
extern CALDATA const volatile float32 cal_MixDoorPercData;/* Referenced by: '<S1796>/Constant' */
extern CALDATA const volatile boolean cal_MixDoorPercDataEnb;/* Referenced by: '<S1796>/Constant1' */
extern CALDATA const volatile float32 cal_MixDoorPerc_CUR[2];
                              /* Referenced by: '<S1745>/cal_MixDoorPerc_CUR' */
extern CALDATA const volatile float32 cal_MixDoorV_1X[2];
                              /* Referenced by: '<S1745>/cal_MixDoorPerc_CUR' */
extern CALDATA const volatile uint16 cal_MixDoorVolAmend_1X[2];
                          /* Referenced by: '<S1745>/cal_MixDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_MixDoorVolAmend_CUR[2];
                          /* Referenced by: '<S1745>/cal_MixDoorVolAmend_CUR' */
extern CALDATA const volatile uint8 cal_MixWarmTrgPos;/* Referenced by: '<S1233>/Constant' */
extern CALDATA const volatile uint16 cal_ModeDoorVolAmend_1X[2];
                         /* Referenced by: '<S1746>/cal_ModeDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_ModeDoorVolAmend_CUR[2];
                         /* Referenced by: '<S1746>/cal_ModeDoorVolAmend_CUR' */
extern CALDATA const volatile boolean cal_ModeMotorEnb;/* Referenced by:
                                                        * '<S1234>/Judge'
                                                        * '<S1234>/Constant4'
                                                        * '<S1274>/Constant1'
                                                        * '<S1275>/Constant1'
                                                        */
extern CALDATA const volatile uint8 cal_ModeMotorNData;/* Referenced by: '<S1274>/Constant' */
extern CALDATA const volatile float32 cal_ModeMotorNErr;/* Referenced by: '<S1234>/Judge' */
extern CALDATA const volatile uint8 cal_ModeMotorPData;/* Referenced by: '<S1275>/Constant' */
extern CALDATA const volatile float32 cal_ModeMotorPErr;/* Referenced by: '<S1234>/Judge' */
extern CALDATA const volatile float32 cal_ModeMotorTrgPosData;/* Referenced by: '<S1273>/Constant' */
extern CALDATA const volatile boolean cal_ModeMotorTrgPosDataEnb;/* Referenced by:
                                                                  * '<S1234>/Constant3'
                                                                  * '<S1273>/Constant1'
                                                                  */
extern CALDATA const volatile uint8 cal_ModeMotorTrgPos_1X[5];
                          /* Referenced by: '<S1234>/cal_ModeMotorTrgPos_CUR' */
extern CALDATA const volatile float32 cal_ModeMotorTrgPos_CUR[5];
                          /* Referenced by: '<S1234>/cal_ModeMotorTrgPos_CUR' */
extern CALDATA const volatile float32 cal_MotHeatBatMinTempDiff;/* Referenced by: '<S1357>/Constant' */
extern CALDATA const volatile uint16 cal_MotInletTempVolAmend_1X[2];
                     /* Referenced by: '<S1075>/cal_MotInletTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_MotInletTempVolAmend_CUR[2];
                     /* Referenced by: '<S1075>/cal_MotInletTempVolAmend_CUR' */
extern CALDATA const volatile uint8 cal_MotPMPDefaultSpd;/* Referenced by: '<S1024>/Constant4' */
extern CALDATA const volatile boolean cal_MotPMPFaultFlgData;/* Referenced by: '<S1066>/Constant' */
extern CALDATA const volatile boolean cal_MotPMPFaultFlgDataEnb;/* Referenced by: '<S1066>/Constant1' */
extern CALDATA const volatile uint8 cal_MotPMPMotHeatBatSpd;/* Referenced by: '<S1024>/Constant11' */
extern CALDATA const volatile uint8 cal_MotPMPSpdDiffVal;/* Referenced by: '<S1024>/Constant' */
extern CALDATA const volatile uint8 cal_MotPMPSpdSetData;/* Referenced by: '<S1065>/Constant' */
extern CALDATA const volatile boolean cal_MotPMPSpdSetDataEnb;/* Referenced by: '<S1065>/Constant1' */
extern CALDATA const volatile uint8 cal_MotPMPThStoSpd;/* Referenced by: '<S1024>/Constant12' */
extern CALDATA const volatile float32 cal_MotTempData;/* Referenced by: '<S1098>/Constant' */
extern CALDATA const volatile boolean cal_MotTempDataEnb;/* Referenced by: '<S1098>/Constant1' */
extern CALDATA const volatile float32 cal_MotTempDownLmt;/* Referenced by: '<S1315>/Relay' */
extern CALDATA const volatile float32 cal_MotTempUpLmt;/* Referenced by: '<S1315>/Relay' */
extern CALDATA const volatile float32 cal_MotorModeData;/* Referenced by: '<S1803>/Constant' */
extern CALDATA const volatile boolean cal_MotorModeEnb;/* Referenced by: '<S1803>/Constant1' */
extern CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOff;/* Referenced by: '<S500>/Relay' */
extern CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOn;/* Referenced by: '<S500>/Relay' */
extern CALDATA const volatile float32 cal_NmlBatHeatEnvTemp[2];/* Referenced by: '<S1532>/Constant1' */
extern CALDATA const volatile float32 cal_NmlBatHeatT1[3];/* Referenced by: '<S1532>/Constant2' */
extern CALDATA const volatile float32 cal_NmlBatHeatT2[3];/* Referenced by: '<S1532>/Constant3' */
extern CALDATA const volatile float32 cal_NmlBatHeatTave[3];/* Referenced by: '<S1532>/Constant' */
extern CALDATA const volatile float32 cal_NmlBatHeatTrgTemp;/* Referenced by:
                                                             * '<S648>/Constant6'
                                                             * '<S1532>/Constant4'
                                                             */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsDownSpd;/* Referenced by: '<S455>/Constant' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP1;/* Referenced by: '<S455>/Relay1' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP2;/* Referenced by: '<S455>/Relay1' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP3;/* Referenced by: '<S455>/Relay' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP4;/* Referenced by: '<S455>/Relay' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP5;/* Referenced by: '<S455>/Relay2' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP6;/* Referenced by: '<S455>/Relay2' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP7;/* Referenced by: '<S455>/Relay3' */
extern CALDATA const volatile float32 cal_NmlCOMPHPrsP8;/* Referenced by: '<S455>/Relay3' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsDownSpd;/* Referenced by: '<S455>/Constant2' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP1;/* Referenced by: '<S455>/Relay9' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP2;/* Referenced by: '<S455>/Relay9' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP3;/* Referenced by: '<S455>/Relay8' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP4;/* Referenced by: '<S455>/Relay8' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP5;/* Referenced by: '<S455>/Relay10' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP6;/* Referenced by: '<S455>/Relay10' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP7;/* Referenced by: '<S455>/Relay11' */
extern CALDATA const volatile float32 cal_NmlCOMPLPrsP8;/* Referenced by: '<S455>/Relay11' */
extern CALDATA const volatile float32 cal_OHXTempData;/* Referenced by: '<S1847>/Constant' */
extern CALDATA const volatile boolean cal_OHXTempDataEnb;/* Referenced by: '<S1847>/Constant1' */
extern CALDATA const volatile uint16 cal_OHXTempVolAmend_1X[2];
                          /* Referenced by: '<S1752>/cal_OHXTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_OHXTempVolAmend_CUR[2];
                          /* Referenced by: '<S1752>/cal_OHXTempVolAmend_CUR' */
extern CALDATA const volatile float32 cal_OpenCoolInletTemp;/* Referenced by: '<S1319>/Constant1' */
extern CALDATA const volatile float32 cal_OpenCtrlCOMPDownlmt;/* Referenced by: '<S567>/Constant4' */
extern CALDATA const volatile float32 cal_OpenCtrlCOMPUplmt;/* Referenced by: '<S567>/Constant3' */
extern CALDATA const volatile uint8 cal_OutRecTrgPos;/* Referenced by: '<S1232>/Constant' */
extern CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_1X[8];
                       /* Referenced by: '<S545>/cal_PCULimBTMAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_CUR[8];
                       /* Referenced by: '<S545>/cal_PCULimBTMAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_1X[8];
               /* Referenced by: '<S545>/cal_PCULimBTMAndCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_CUR[8];
               /* Referenced by: '<S545>/cal_PCULimBTMAndCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_1X[8];
                     /* Referenced by: '<S545>/cal_PCULimCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_CUR[8];
                     /* Referenced by: '<S545>/cal_PCULimCabinAccmSpdDes_CUR' */
extern CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_1X[7];
                  /* Referenced by: '<S1299>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_CUR[7];
                  /* Referenced by: '<S1299>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2X[6];
                          /* Referenced by: '<S582>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2Y[6];
                          /* Referenced by: '<S582>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_MAP[36];
                          /* Referenced by: '<S582>/cal_PTCAuxHeatPwrLmt_MAP' */
extern CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_1X[9];
                          /* Referenced by: '<S947>/cal_PTCBatHeatPwrLmt_CUR' */
extern CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_CUR[9];
                          /* Referenced by: '<S947>/cal_PTCBatHeatPwrLmt_CUR' */
extern CALDATA const volatile uint8 cal_PTCDelOffTime;/* Referenced by: '<S947>/Constant12' */
extern CALDATA const volatile uint8 cal_PTCEnableData;/* Referenced by: '<S1013>/Constant' */
extern CALDATA const volatile boolean cal_PTCEnableDataEnb;/* Referenced by: '<S1013>/Constant1' */
extern CALDATA const volatile float32 cal_PTCMaxTemp;/* Referenced by: '<S444>/Constant1' */
extern CALDATA const volatile float32 cal_PTCMinTemp;/* Referenced by: '<S444>/Constant3' */
extern CALDATA const volatile uint8 cal_PTCOffAcPMPSpd;/* Referenced by: '<S1022>/Constant16' */
extern CALDATA const volatile float32 cal_PTCOffPowerVal;/* Referenced by: '<S582>/Constant6' */
extern CALDATA const volatile float32 cal_PTCOnReqPower_1X[6];
                             /* Referenced by: '<S582>/cal_PTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_PTCOnReqPower_CUR[6];
                             /* Referenced by: '<S582>/cal_PTCOnReqPower_CUR' */
extern CALDATA const volatile float32 cal_PTCPwrOffFlt;/* Referenced by: '<S947>/Constant11' */
extern CALDATA const volatile float32 cal_PTCReqTempData;/* Referenced by: '<S944>/Constant' */
extern CALDATA const volatile boolean cal_PTCReqTempDataEnb;/* Referenced by: '<S944>/Constant1' */
extern CALDATA const volatile float32 cal_PTCReqtPowerData;/* Referenced by: '<S1020>/Constant' */
extern CALDATA const volatile boolean cal_PTCReqtPowerDataEnb;/* Referenced by: '<S1020>/Constant1' */
extern CALDATA const volatile uint8 cal_PTCRunAcPMPFFSpd;/* Referenced by:
                                                          * '<S1022>/Constant12'
                                                          * '<S1022>/Constant14'
                                                          */
extern CALDATA const volatile float32 cal_PTCRunAcPMPFFTime;/* Referenced by: '<S1022>/Constant15' */
extern CALDATA const volatile float32 cal_PTCTempRecircOff;/* Referenced by: '<S132>/Constant5' */
extern CALDATA const volatile float32 cal_PTCTempRecircOn;/* Referenced by: '<S132>/Constant6' */
extern CALDATA const volatile float32 cal_PressRateVal1;/* Referenced by: '<S532>/Relay' */
extern CALDATA const volatile float32 cal_PressRateVal1Relay;/* Referenced by: '<S532>/Relay' */
extern CALDATA const volatile float32 cal_PressRateVal2;/* Referenced by:
                                                         * '<S530>/Relay1'
                                                         * '<S532>/Relay1'
                                                         */
extern CALDATA const volatile float32 cal_PressRateVal2Relay;/* Referenced by:
                                                              * '<S530>/Relay1'
                                                              * '<S532>/Relay1'
                                                              */
extern CALDATA const volatile float32 cal_PressRateVal3;/* Referenced by:
                                                         * '<S527>/Relay2'
                                                         * '<S530>/Relay2'
                                                         * '<S532>/Relay2'
                                                         * '<S534>/Relay1'
                                                         */
extern CALDATA const volatile float32 cal_PressRateVal3Relay;/* Referenced by:
                                                              * '<S527>/Relay2'
                                                              * '<S530>/Relay2'
                                                              * '<S532>/Relay2'
                                                              */
extern CALDATA const volatile float32 cal_PressRateVal4;/* Referenced by: '<S534>/Relay1' */
extern CALDATA const volatile float32 cal_PsDVTWeight;
                    /* Referenced by: '<S58>/ACCtl_facLeftBlowerFanSpdWeight' */
extern CALDATA const volatile float32 cal_PsDuctFaceFloorFaFactor;/* Referenced by: '<S227>/Constant3' */
extern CALDATA const volatile float32 cal_PsDuctFaceFloorFoFactor;/* Referenced by: '<S227>/Constant4' */
extern CALDATA const volatile float32 cal_PsDuctSensorFailDeflt;
                       /* Referenced by: '<S175>/cal_PsDuctSensorFailDefault' */
extern CALDATA const volatile float32 cal_PsEnv4SetSelect;/* Referenced by: '<S185>/Constant3' */
extern CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOff;
/* Referenced by: '<S415>/On:cal_PsErrOfEvaDVT2CoolMixOn Off:cal_PsErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOn;
/* Referenced by: '<S415>/On:cal_PsErrOfEvaDVT2CoolMixOn Off:cal_PsErrOfEvaDVT2CoolMixOff ' */
extern CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOff;
/* Referenced by: '<S415>/On:cal_PsErrOfPtcDVT2HeatMixOn Off:cal_PsErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOn;
/* Referenced by: '<S415>/On:cal_PsErrOfPtcDVT2HeatMixOn Off:cal_PsErrOfPtcDVT2HeatMixOff' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandNeg;/* Referenced by: '<S306>/Kp12' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandPos;/* Referenced by: '<S306>/Kp11' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKi;/* Referenced by: '<S306>/Kp7' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKiNeg;/* Referenced by: '<S306>/Kp9' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKiPos;/* Referenced by: '<S306>/Kp10' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKp;/* Referenced by: '<S306>/Kp' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKpNeg;/* Referenced by: '<S306>/Kp1' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDKpPos;/* Referenced by: '<S306>/Kp2' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL;/* Referenced by: '<S306>/Kp6' */
extern CALDATA const volatile uint8 cal_PsEvaDesValPIDLL_2X[4];
                          /* Referenced by: '<S276>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL_2Y[7];
                          /* Referenced by: '<S276>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDLL_MAP[28];
                          /* Referenced by: '<S276>/cal_PsEvaDesValPIDLL_MAP' */
extern CALDATA const volatile float32 cal_PsEvaDesValPIDUL;/* Referenced by: '<S306>/Kp5' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMax;/* Referenced by: '<S306>/Kp8' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMin;/* Referenced by: '<S306>/Kp13' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_pWinNeg;/* Referenced by: '<S306>/Kp4' */
extern CALDATA const volatile float32 cal_PsEvaDesValPID_pWinPos;/* Referenced by: '<S306>/Kp3' */
extern CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_1X[4];
                      /* Referenced by: '<S306>/cal_PsEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_CUR[4];
                      /* Referenced by: '<S306>/cal_PsEvapDesFilterByDvt_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetAC_1X[8];
                             /* Referenced by: '<S415>/cal_PsMixBacSetAC_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetAC_CUR[8];
                             /* Referenced by: '<S415>/cal_PsMixBacSetAC_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetBi_1X[8];
                             /* Referenced by: '<S415>/cal_PsMixBacSetBi_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetBi_CUR[8];
                             /* Referenced by: '<S415>/cal_PsMixBacSetBi_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetDefog_1X[8];
                          /* Referenced by: '<S415>/cal_PsMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetDefog_CUR[8];
                          /* Referenced by: '<S415>/cal_PsMixBacSetDefog_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFootDe_1X[8];
                         /* Referenced by: '<S415>/cal_PsMixBacSetFootDe_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFootDe_CUR[8];
                         /* Referenced by: '<S415>/cal_PsMixBacSetFootDe_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFoot_1X[8];
                           /* Referenced by: '<S415>/cal_PsMixBacSetFoot_CUR' */
extern CALDATA const volatile float32 cal_PsMixBacSetFoot_CUR[8];
                           /* Referenced by: '<S415>/cal_PsMixBacSetFoot_CUR' */
extern CALDATA const volatile float32 cal_PsMixDesValPIDIntegDeadBand;/* Referenced by: '<S416>/Kp11' */
extern CALDATA const volatile uint8 cal_PsMixDesValPIDLL;/* Referenced by: '<S416>/Kp6' */
extern CALDATA const volatile uint8 cal_PsMixDesValPIDUL;/* Referenced by: '<S416>/Kp5' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_IsumMax;/* Referenced by: '<S416>/Kp8' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_IsumMin;/* Referenced by: '<S416>/Kp13' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_Ki;/* Referenced by: '<S416>/Kp7' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KiNeg;/* Referenced by: '<S416>/Kp9' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KiPos;/* Referenced by: '<S416>/Kp10' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_Kp;/* Referenced by: '<S416>/Kp' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KpNeg;/* Referenced by: '<S416>/Kp1' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_KpPos;/* Referenced by: '<S416>/Kp2' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_pWinNeg;/* Referenced by: '<S416>/Kp4' */
extern CALDATA const volatile float32 cal_PsMixDesValPID_pWinPos;/* Referenced by: '<S416>/Kp3' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4InHeat;/* Referenced by: '<S364>/Kp16' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4OutHeat;/* Referenced by: '<S364>/Kp24' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKi;/* Referenced by: '<S364>/Kp7' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKiNeg;/* Referenced by: '<S364>/Kp9' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKiPos;/* Referenced by: '<S364>/Kp10' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKp;/* Referenced by: '<S364>/Kp' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKpNeg;/* Referenced by: '<S364>/Kp1' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDKpPos;/* Referenced by: '<S364>/Kp2' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDLL;/* Referenced by: '<S364>/Kp6' */
extern CALDATA const volatile float32 cal_PsPtcDesValPIDUL;/* Referenced by: '<S364>/Kp5' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMax;/* Referenced by: '<S364>/Kp8' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMin;/* Referenced by: '<S364>/Kp13' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_pWinNeg;/* Referenced by: '<S364>/Kp4' */
extern CALDATA const volatile float32 cal_PsPtcDesValPID_pWinPos;/* Referenced by: '<S364>/Kp3' */
extern CALDATA const volatile boolean cal_PtcEnable;/* Referenced by:
                                                     * '<S386>/Constant5'
                                                     * '<S387>/Constant5'
                                                     */
extern CALDATA const volatile float32 cal_PtcPwrDesValPIDDeadBandNeg;/* Referenced by: '<S94>/Constant6' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPIDDeadBandPos;/* Referenced by: '<S94>/Constant7' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_IsumMax;/* Referenced by: '<S94>/Kp8' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_IsumMin;/* Referenced by: '<S94>/Kp13' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_Ki;/* Referenced by: '<S94>/Kp7' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KiNeg;/* Referenced by: '<S94>/Kp9' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KiPos;/* Referenced by: '<S94>/Kp10' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_Kp;/* Referenced by: '<S94>/Kp' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KpNeg;/* Referenced by: '<S94>/Kp1' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_KpPos;/* Referenced by: '<S94>/Kp2' */
extern CALDATA const volatile uint16 cal_PtcPwrDesValPID_LL;/* Referenced by: '<S94>/Kp6' */
extern CALDATA const volatile uint16 cal_PtcPwrDesValPID_UL;/* Referenced by: '<S94>/Kp5' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_pWinNeg;/* Referenced by: '<S94>/Kp4' */
extern CALDATA const volatile float32 cal_PtcPwrDesValPID_pWinPos;/* Referenced by: '<S94>/Kp3' */
extern CALDATA const volatile boolean cal_PwrACPumpData;/* Referenced by: '<S1240>/Constant' */
extern CALDATA const volatile boolean cal_PwrACPumpEnb;/* Referenced by: '<S1240>/Constant1' */
extern CALDATA const volatile boolean cal_PwrBlwData;/* Referenced by: '<S1243>/Constant' */
extern CALDATA const volatile boolean cal_PwrBlwEnb;/* Referenced by: '<S1243>/Constant1' */
extern CALDATA const volatile uint8 cal_PwrFanAndPumpData;/* Referenced by: '<S1251>/Constant' */
extern CALDATA const volatile boolean cal_PwrFanAndPumpDataEnb;/* Referenced by: '<S1251>/Constant1' */
extern CALDATA const volatile boolean cal_PwrFanData;/* Referenced by: '<S1235>/Constant' */
extern CALDATA const volatile boolean cal_PwrFanEnb;/* Referenced by: '<S1235>/Constant1' */
extern CALDATA const volatile boolean cal_PwrHVPartData;/* Referenced by: '<S1254>/Constant' */
extern CALDATA const volatile boolean cal_PwrHVPartEnb;/* Referenced by: '<S1254>/Constant1' */
extern CALDATA const volatile float32 cal_PwrOffsetVal;/* Referenced by:
                                                        * '<S31>/Constant4'
                                                        * '<S31>/Constant5'
                                                        */
extern CALDATA const volatile boolean cal_PwrSensorData;/* Referenced by: '<S1236>/Constant' */
extern CALDATA const volatile boolean cal_PwrSensorEnb;/* Referenced by: '<S1236>/Constant1' */
extern CALDATA const volatile float32 cal_REC_DVTFresh;/* Referenced by: '<S136>/Constant6' */
extern CALDATA const volatile float32 cal_REC_DVTRecirc;/* Referenced by: '<S136>/Constant5' */
extern CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_1X[14];
                       /* Referenced by: '<S80>/cal_RFace2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_CUR[14];
                       /* Referenced by: '<S80>/cal_RFace2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_1X[14];
                       /* Referenced by: '<S80>/cal_RFaceFloor2FaceByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_CUR[14];
                       /* Referenced by: '<S80>/cal_RFaceFloor2FaceByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_1X[14];
                      /* Referenced by: '<S80>/cal_RFaceFloor2FloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_CUR[14];
                      /* Referenced by: '<S80>/cal_RFaceFloor2FloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_1X[14];
                      /* Referenced by: '<S80>/cal_RFloor2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_CUR[14];
                      /* Referenced by: '<S80>/cal_RFloor2FaceFloorByEnv_CUR' */
extern CALDATA const volatile float32 cal_RecirActVal_1X[2];
                              /* Referenced by: '<S1747>/cal_RecirActVal_CUR' */
extern CALDATA const volatile uint8 cal_RecirActVal_CUR[2];
                              /* Referenced by: '<S1747>/cal_RecirActVal_CUR' */
extern CALDATA const volatile float32 cal_RecircDoorNErr;/* Referenced by: '<S1232>/Judge' */
extern CALDATA const volatile float32 cal_RecircDoorPErr;/* Referenced by: '<S1232>/Judge' */
extern CALDATA const volatile uint16 cal_RecircDoorVolAmend_1X[2];
                       /* Referenced by: '<S1747>/cal_RecircDoorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_RecircDoorVolAmend_CUR[2];
                       /* Referenced by: '<S1747>/cal_RecircDoorVolAmend_CUR' */
extern CALDATA const volatile boolean cal_RecircMotorEnb;/* Referenced by:
                                                          * '<S1232>/Judge'
                                                          * '<S1232>/Constant6'
                                                          * '<S1259>/Constant1'
                                                          * '<S1260>/Constant1'
                                                          */
extern CALDATA const volatile uint8 cal_RecircMotorNData;/* Referenced by: '<S1259>/Constant' */
extern CALDATA const volatile uint8 cal_RecircMotorPData;/* Referenced by: '<S1260>/Constant' */
extern CALDATA const volatile uint8 cal_RecircTrgPosData;/* Referenced by: '<S1261>/Constant' */
extern CALDATA const volatile boolean cal_RecircTrgPosDataEnb;/* Referenced by:
                                                               * '<S1232>/Constant5'
                                                               * '<S1261>/Constant1'
                                                               */
extern CALDATA const volatile RefModes cal_RefModeData;/* Referenced by: '<S1736>/Constant' */
extern CALDATA const volatile boolean cal_RefModeEnb;/* Referenced by: '<S1736>/Constant1' */
extern CALDATA const volatile uint16 cal_RiseTime2EnvTamb;
                                      /* Referenced by: '<S180>/TempRampStep' */
extern CALDATA const volatile uint16 cal_RiseTime2Solar;
                                     /* Referenced by: '<S185>/TempRampStep1' */
extern CALDATA const volatile uint16 cal_RiseTime2Tamb;
                                     /* Referenced by: '<S1072>/TempRampStep' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOff;/* Referenced by: '<S947>/Relay' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOn;/* Referenced by: '<S947>/Relay' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_1X[6];
                          /* Referenced by: '<S947>/cal_SOCHighPTCPwrLmt_CUR' */
extern CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_CUR[6];
                          /* Referenced by: '<S947>/cal_SOCHighPTCPwrLmt_CUR' */
extern CALDATA const volatile boolean cal_SOVData;/* Referenced by: '<S1277>/Constant' */
extern CALDATA const volatile boolean cal_SOVEnb;/* Referenced by: '<S1277>/Constant1' */
extern CALDATA const volatile float32 cal_SensorTempDownFlg;/* Referenced by:
                                                             * '<S1093>/Constant1'
                                                             * '<S1103>/Constant1'
                                                             * '<S1763>/Constant1'
                                                             * '<S1773>/Constant1'
                                                             * '<S1783>/Constant1'
                                                             * '<S1824>/Constant1'
                                                             * '<S1831>/Constant1'
                                                             * '<S1841>/Constant1'
                                                             * '<S1850>/Constant1'
                                                             * '<S1859>/Constant1'
                                                             * '<S1877>/Constant1'
                                                             */
extern CALDATA const volatile float32 cal_SensorTempUpFlt;/* Referenced by:
                                                           * '<S1093>/Constant'
                                                           * '<S1103>/Constant'
                                                           * '<S1763>/Constant'
                                                           * '<S1773>/Constant'
                                                           * '<S1783>/Constant'
                                                           * '<S1824>/Constant'
                                                           * '<S1831>/Constant'
                                                           * '<S1841>/Constant'
                                                           * '<S1850>/Constant'
                                                           * '<S1859>/Constant'
                                                           * '<S1877>/Constant'
                                                           */
extern CALDATA const volatile float32 cal_SensorVolDownFlg;/* Referenced by:
                                                            * '<S1790>/Constant1'
                                                            * '<S1797>/Constant1'
                                                            * '<S1804>/Constant1'
                                                            * '<S1811>/Constant1'
                                                            * '<S1814>/Constant1'
                                                            * '<S1867>/Constant1'
                                                            */
extern CALDATA const volatile float32 cal_SensorVolUpFlg;/* Referenced by:
                                                          * '<S1790>/Constant'
                                                          * '<S1797>/Constant'
                                                          * '<S1804>/Constant'
                                                          * '<S1811>/Constant'
                                                          * '<S1814>/Constant'
                                                          * '<S1867>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_SetLeftMixDoorTrgData;/* Referenced by: '<S1268>/Constant' */
extern CALDATA const volatile boolean cal_SetLeftMixDoorTrgDataEnb;/* Referenced by:
                                                                    * '<S1233>/Constant5'
                                                                    * '<S1268>/Constant1'
                                                                    */
extern CALDATA const volatile float32 cal_SetPtcDesCoff;/* Referenced by: '<S179>/Constant5' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMax_2X[10];
                          /* Referenced by: '<S179>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile uint8 cal_SetPtcDesTempMax_2Y[10];
                          /* Referenced by: '<S179>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMax_MAP[100];
                          /* Referenced by: '<S179>/cal_SetPtcDesTempMax_MAP' */
extern CALDATA const volatile float32 cal_SetPtcDesTempMin;/* Referenced by: '<S179>/Constant8' */
extern CALDATA const volatile uint16 cal_SolarData;/* Referenced by: '<S1813>/Constant' */
extern CALDATA const volatile boolean cal_SolarEnb;/* Referenced by: '<S1813>/Constant1' */
extern CALDATA const volatile uint16 cal_SolarFalseStep;
                           /* Referenced by: '<S210>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile uint16 cal_SolarRiseStep;
                           /* Referenced by: '<S210>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile float32 cal_SolarValRaw_1X[11];
                              /* Referenced by: '<S1748>/cal_SolarValRaw_CUR' */
extern CALDATA const volatile uint16 cal_SolarValRaw_CUR[11];
                              /* Referenced by: '<S1748>/cal_SolarValRaw_CUR' */
extern CALDATA const volatile uint16 cal_SolorVolAmend_1X[2];
                            /* Referenced by: '<S1748>/cal_SolorVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_SolorVolAmend_CUR[2];
                            /* Referenced by: '<S1748>/cal_SolorVolAmend_CUR' */
extern CALDATA const volatile float32 cal_StartPrsProTimes;/* Referenced by: '<S455>/Constant4' */
extern CALDATA const volatile float32 cal_SuperHeatFilter;/* Referenced by:
                                                           * '<S896>/Constant1'
                                                           * '<S897>/Constant1'
                                                           * '<S898>/Constant1'
                                                           * '<S900>/Constant1'
                                                           */
extern CALDATA const volatile float32 cal_SuperHeat_1X[28];
                                 /* Referenced by: '<S676>/cal_SuperHeat_CUR' */
extern CALDATA const volatile float32 cal_SuperHeat_CUR[28];
                                 /* Referenced by: '<S676>/cal_SuperHeat_CUR' */
extern CALDATA const volatile float32 cal_TACCMOutRaw_1X[30];
                                  /* Referenced by: '<S1755>/cal_ACCMTHi_CUR' */
extern CALDATA const volatile float32 cal_TACCMOutRaw_CUR[30];
                                  /* Referenced by: '<S1755>/cal_ACCMTHi_CUR' */
extern CALDATA const volatile float32 cal_TCabinRaw_1X[27];
                                /* Referenced by: '<S1740>/cal_TCabinRaw_CUR' */
extern CALDATA const volatile float32 cal_TCabinRaw_CUR[27];
                                /* Referenced by: '<S1740>/cal_TCabinRaw_CUR' */
extern CALDATA const volatile float32 cal_TChillOutRaw_1X[27];
                             /* Referenced by: '<S1749>/cal_TChillOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TChillOutRaw_CUR[27];
                             /* Referenced by: '<S1749>/cal_TChillOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TDuctRaw_1X[26];/* Referenced by:
                                                           * '<S1742>/cal_TDuctRaw_CUR'
                                                           * '<S1743>/cal_TDuctRaw_CUR'
                                                           */
extern CALDATA const volatile float32 cal_TDuctRaw_CUR[26];/* Referenced by:
                                                            * '<S1742>/cal_TDuctRaw_CUR'
                                                            * '<S1743>/cal_TDuctRaw_CUR'
                                                            */
extern CALDATA const volatile float32 cal_TEnvRaw_1X[27];
                                  /* Referenced by: '<S1074>/cal_TEnvRaw_CUR' */
extern CALDATA const volatile float32 cal_TEnvRaw_CUR[27];
                                  /* Referenced by: '<S1074>/cal_TEnvRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapOutRaw_1X[30];
                              /* Referenced by: '<S1750>/cal_TEvapOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapOutRaw_CUR[30];
                              /* Referenced by: '<S1750>/cal_TEvapOutRaw_CUR' */
extern CALDATA const volatile float32 cal_TEvapSurfRaw_1X[23];
                                 /* Referenced by: '<S1751>/cal_TEvapSur_CUR' */
extern CALDATA const volatile float32 cal_TEvapSurfRaw_CUR[23];
                                 /* Referenced by: '<S1751>/cal_TEvapSur_CUR' */
extern CALDATA const volatile float32 cal_TLCCOutRaw_1X[20];
                                /* Referenced by: '<S1753>/cal_WCCTHiRaw_CUR' */
extern CALDATA const volatile float32 cal_TLCCOutRaw_CUR[20];
                                /* Referenced by: '<S1753>/cal_WCCTHiRaw_CUR' */
extern CALDATA const volatile PwrModes cal_TMSStatusData;/* Referenced by: '<S1296>/Constant' */
extern CALDATA const volatile uint8 cal_TMSStatusEnb;/* Referenced by: '<S1296>/Constant1' */
extern CALDATA const volatile float32 cal_TMotEntRaw_1X[17];
                                     /* Referenced by: '<S1075>/cal_TMot_CUR' */
extern CALDATA const volatile float32 cal_TMotEntRaw_CUR[17];
                                     /* Referenced by: '<S1075>/cal_TMot_CUR' */
extern CALDATA const volatile float32 cal_TOHXOutRaw_1X[30];
                                  /* Referenced by: '<S1752>/cal_OHXTRaw_CUR' */
extern CALDATA const volatile float32 cal_TOHXOutRaw_CUR[30];
                                  /* Referenced by: '<S1752>/cal_OHXTRaw_CUR' */
extern CALDATA const volatile float32 cal_TSACBatMinEntTempA;/* Referenced by:
                                                              * '<S1652>/Constant'
                                                              * '<S1362>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_TSACBatMinEntTempB;/* Referenced by:
                                                              * '<S1653>/Constant'
                                                              * '<S1363>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_TSACBatMinExitTempM;/* Referenced by:
                                                               * '<S1379>/Constant4'
                                                               * '<S1643>/Constant4'
                                                               */
extern CALDATA const volatile float32 cal_TSACBatMinExitTempN;/* Referenced by:
                                                               * '<S1380>/Constant4'
                                                               * '<S1644>/Constant4'
                                                               */
extern CALDATA const volatile float32 cal_TSBatInletTempOffsetP;/* Referenced by: '<S1382>/Constant5' */
extern CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_1X[5];
                  /* Referenced by: '<S1372>/cal_TSBatMaxTempForEnvExitC_CUR' */
extern CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_CUR[5];
                  /* Referenced by: '<S1372>/cal_TSBatMaxTempForEnvExitC_CUR' */
extern CALDATA const volatile float32 cal_TSBatMinExitTempJ;/* Referenced by: '<S1377>/Constant4' */
extern CALDATA const volatile float32 cal_TSBatMinTempOffsetD;/* Referenced by: '<S1373>/Constant5' */
extern CALDATA const volatile float32 cal_TSBatMinTemplowValB;/* Referenced by: '<S1358>/Constant2' */
extern CALDATA const volatile float32 cal_TSDCBatMinEntTempC;/* Referenced by:
                                                              * '<S1654>/Constant'
                                                              * '<S1364>/Constant'
                                                              */
extern CALDATA const volatile float32 cal_TSDCBatMinExitTempK;/* Referenced by:
                                                               * '<S1378>/Constant4'
                                                               * '<S1642>/Constant4'
                                                               */
extern CALDATA const volatile float32 cal_TSIGBTMinTempEntC;/* Referenced by: '<S1358>/Constant3' */
extern CALDATA const volatile float32 cal_TSIGBTMinTempExitG;/* Referenced by: '<S1374>/Constant3' */
extern CALDATA const volatile float32 cal_TSIPUExitTempI;/* Referenced by:
                                                          * '<S1376>/Constant'
                                                          * '<S1645>/Constant'
                                                          */
extern CALDATA const volatile float32 cal_TSMotorMinTempEntC;/* Referenced by: '<S1358>/Constant' */
extern CALDATA const volatile float32 cal_TSMotorMinTempExitH;/* Referenced by: '<S1375>/Constant' */
extern CALDATA const volatile float32 cal_TempRampStepFast;/* Referenced by: '<S1072>/Constant2' */
extern CALDATA const volatile float32 cal_TempRampStepLoVSpeed;
                                    /* Referenced by: '<S1072>/TempRampStep4' */
extern CALDATA const volatile float32 cal_TempRampStepSlow;/* Referenced by: '<S1072>/Constant1' */
extern CALDATA const volatile float32 cal_TevapLoStepMin;/* Referenced by:
                                                          * '<S178>/Constant2'
                                                          * '<S178>/Constant5'
                                                          */
extern CALDATA const volatile uint16 cal_TevapLoTime;/* Referenced by: '<S178>/Constant6' */
extern CALDATA const volatile float32 cal_TevapUpStepMin;/* Referenced by:
                                                          * '<S179>/Constant'
                                                          * '<S179>/Constant3'
                                                          */
extern CALDATA const volatile uint16 cal_TevapUpTime;
                                    /* Referenced by: '<S179>/PTCHeatedCheck' */
extern CALDATA const volatile float32 cal_U_DVTFFSolarFilterRate;/* Referenced by:
                                                                  * '<S181>/ACCtrl_facSolarFlt_C'
                                                                  * '<S182>/ACCtrl_facSolarFlt_C'
                                                                  * '<S185>/ACCtrl_facSolarFlt_C'
                                                                  */
extern CALDATA const volatile uint16 cal_UpAndDownStartTime;
                           /* Referenced by: '<S210>/TempRampBaseTimeAndStep' */
extern CALDATA const volatile float32 cal_VehHeatSOCOff;/* Referenced by:
                                                         * '<S1350>/Constant'
                                                         * '<S1468>/Constant'
                                                         * '<S1594>/Constant'
                                                         * '<S1606>/Constant'
                                                         * '<S1513>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_VehHeatSOCOn;/* Referenced by:
                                                        * '<S1356>/Constant'
                                                        * '<S1451>/Constant'
                                                        * '<S1587>/Constant'
                                                        * '<S1601>/Constant'
                                                        * '<S1502>/Constant'
                                                        */
extern CALDATA const volatile float32 cal_VehicleSpeedHighVs;/* Referenced by: '<S1076>/Constant' */
extern CALDATA const volatile float32 cal_VehicleSpeedLowVs;/* Referenced by: '<S1077>/Constant' */
extern CALDATA const volatile uint16 cal_WCCHPVolAmend_1X[2];
                            /* Referenced by: '<S1754>/cal_WCCHPVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCHPVolAmend_CUR[2];
                            /* Referenced by: '<S1754>/cal_WCCHPVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_WCCHighTempVolAmend_1X[2];
                      /* Referenced by: '<S1753>/cal_WCCHighTempVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCHighTempVolAmend_CUR[2];
                      /* Referenced by: '<S1753>/cal_WCCHighTempVolAmend_CUR' */
extern CALDATA const volatile uint16 cal_WCCLPVolAmend_1X[2];
                            /* Referenced by: '<S1744>/cal_WCCLPVolAmend_CUR' */
extern CALDATA const volatile sint16 cal_WCCLPVolAmend_CUR[2];
                            /* Referenced by: '<S1744>/cal_WCCLPVolAmend_CUR' */
extern CALDATA const volatile float32 cal_WCCTempData;/* Referenced by: '<S1857>/Constant' */
extern CALDATA const volatile boolean cal_WCCTempDataEnb;/* Referenced by: '<S1857>/Constant1' */
extern CALDATA const volatile WaterModes cal_WaterModeData;/* Referenced by: '<S1728>/Constant' */
extern CALDATA const volatile boolean cal_WaterModeEnb;/* Referenced by: '<S1728>/Constant1' */
extern CALDATA const volatile boolean cal_bACAutoData;/* Referenced by: '<S1183>/Constant' */
extern CALDATA const volatile boolean cal_bACAutoEnb;/* Referenced by: '<S1183>/Constant1' */
extern CALDATA const volatile boolean cal_bACDefrostData;/* Referenced by: '<S1197>/Constant' */
extern CALDATA const volatile boolean cal_bACDefrostEnb;/* Referenced by: '<S1197>/Constant1' */
extern CALDATA const volatile boolean cal_bACOnOffData;/* Referenced by: '<S1209>/Constant' */
extern CALDATA const volatile boolean cal_bACOnOffEnb;/* Referenced by: '<S1209>/Constant1' */
extern CALDATA const volatile boolean cal_bExhFlgData;/* Referenced by: '<S1118>/Constant' */
extern CALDATA const volatile boolean cal_bExhFlgEnb;/* Referenced by: '<S1118>/Constant1' */
extern CALDATA const volatile boolean cal_bLeftSetHighData;/* Referenced by: '<S1163>/Constant' */
extern CALDATA const volatile boolean cal_bLeftSetHighEnb;/* Referenced by: '<S1163>/Constant1' */
extern CALDATA const volatile boolean cal_bLeftSetLowData;/* Referenced by: '<S1164>/Constant' */
extern CALDATA const volatile boolean cal_bLeftSetLowEnb;/* Referenced by: '<S1164>/Constant1' */
extern CALDATA const volatile uint8 cal_eACStsData;/* Referenced by: '<S1221>/Constant' */
extern CALDATA const volatile boolean cal_eACStsEnb;/* Referenced by: '<S1221>/Constant1' */
extern CALDATA const volatile uint8 cal_eBlwStsData;/* Referenced by: '<S1129>/Constant' */
extern CALDATA const volatile boolean cal_eBlwStsEnb;/* Referenced by: '<S1129>/Constant1' */
extern CALDATA const volatile uint8 cal_eC3WVValueData;/* Referenced by: '<S639>/Constant' */
extern CALDATA const volatile boolean cal_eC3WVValueEnb;/* Referenced by: '<S639>/Constant1' */
extern CALDATA const volatile uint8 cal_eC5WVValueData;/* Referenced by: '<S640>/Constant' */
extern CALDATA const volatile boolean cal_eC5WVValueEnb;/* Referenced by: '<S640>/Constant1' */
extern CALDATA const volatile uint8 cal_eInnerData;/* Referenced by: '<S1145>/Constant' */
extern CALDATA const volatile boolean cal_eInnerEnb;/* Referenced by: '<S1145>/Constant1' */
extern CALDATA const volatile uint8 cal_eModeMotorData;/* Referenced by: '<S1152>/Constant' */
extern CALDATA const volatile boolean cal_eModeMotorEnb;/* Referenced by: '<S1152>/Constant1' */
extern CALDATA const volatile float32 cal_rCabinCoolToCondMixDoor;/* Referenced by: '<S1693>/Constant' */
extern CALDATA const volatile uint8 cal_rCabinEvpToHPInnRatio;/* Referenced by: '<S1720>/Constant' */
extern CALDATA const volatile uint8 cal_rCabinHPToEvpInnRatio;/* Referenced by: '<S1719>/Constant' */
extern CALDATA const volatile float32 cal_sMixDoorData;/* Referenced by: '<S1147>/Constant' */
extern CALDATA const volatile boolean cal_sMixDoorEnb;/* Referenced by: '<S1147>/Constant1' */
extern CALDATA const volatile float32 cal_tACBatCoolCellTempOn;/* Referenced by: '<S1404>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitACChrgMinCellTemp;/* Referenced by: '<S1353>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitBal1ToBatDiff;/* Referenced by: '<S1346>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitBatToBal2Diff;/* Referenced by: '<S1343>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitDCChrgMinCellTemp;/* Referenced by: '<S1348>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalExitMaxToMinCellDiff;/* Referenced by: '<S1351>/Constant' */
extern CALDATA const volatile float32 cal_tBatBalONACChrgMinCellTemp;/* Referenced by: '<S1341>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolACChrgCellTempOff;/* Referenced by: '<S1434>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolCellTempOn;/* Referenced by: '<S1416>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolDCChrgCellTempOff;/* Referenced by: '<S1433>/Constant' */
extern CALDATA const volatile float32 cal_tBatCoolVehReadyCellTempOff;/* Referenced by: '<S1435>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOff;/* Referenced by: '<S1524>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOn;/* Referenced by: '<S1488>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOff;/* Referenced by: '<S1527>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOn;/* Referenced by: '<S1491>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOff;/* Referenced by: '<S1522>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOn;/* Referenced by: '<S1487>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatExitMaxToMinCellDiff;/* Referenced by:
                                                                      * '<S1342>/Constant'
                                                                      * '<S1349>/Constant'
                                                                      * '<S1355>/Constant'
                                                                      * '<S1381>/Constant'
                                                                      * '<S1586>/Constant'
                                                                      * '<S1592>/Constant'
                                                                      * '<S1596>/Constant'
                                                                      * '<S1600>/Constant'
                                                                      * '<S1605>/Constant'
                                                                      * '<S1616>/Constant'
                                                                      * '<S1620>/Constant'
                                                                      * '<S1627>/Constant'
                                                                      * '<S1655>/Constant'
                                                                      * '<S1361>/Constant'
                                                                      * '<S1365>/Constant'
                                                                      * '<S1407>/Constant'
                                                                      * '<S1417>/Constant'
                                                                      * '<S1424>/Constant'
                                                                      * '<S1462>/Constant'
                                                                      * '<S1472>/Constant'
                                                                      * '<S1492>/Constant'
                                                                      * '<S1503>/Constant'
                                                                      * '<S1511>/Constant'
                                                                      * '<S1563>/Constant'
                                                                      * '<S1574>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOff;/* Referenced by: '<S1526>/Constant' */
extern CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOn;/* Referenced by: '<S1501>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToCoolDvtDiff;/* Referenced by: '<S1688>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToCoolEvapTemp;/* Referenced by: '<S1691>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCondToEvpEvapTemp;/* Referenced by: '<S1709>/Constant' */
extern CALDATA const volatile float32 cal_tCabinCoolEnvTempHigh;/* Referenced by:
                                                                 * '<S1678>/Constant'
                                                                 * '<S1678>/Constant2'
                                                                 * '<S1678>/Constant9'
                                                                 * '<S1699>/Constant10'
                                                                 * '<S1700>/Constant2'
                                                                 * '<S1700>/Constant3'
                                                                 */
extern CALDATA const volatile float32 cal_tCabinCoolEnvTempLow;/* Referenced by:
                                                                * '<S1678>/Constant1'
                                                                * '<S1678>/Constant3'
                                                                * '<S1678>/Constant5'
                                                                * '<S1683>/Constant1'
                                                                * '<S1683>/Constant5'
                                                                * '<S1710>/Constant'
                                                                * '<S1698>/Constant1'
                                                                * '<S1700>/Constant5'
                                                                * '<S1701>/Constant13'
                                                                * '<S1702>/Constant11'
                                                                * '<S1713>/Constant5'
                                                                * '<S1714>/Constant13'
                                                                */
extern CALDATA const volatile float32 cal_tCabinCoolToCondDvtDiff;/* Referenced by: '<S1692>/Constant' */
extern CALDATA const volatile float32 cal_tCabinEvpToCondDvtDiff;/* Referenced by:
                                                                  * '<S1705>/Constant'
                                                                  * '<S1706>/Constant'
                                                                  */
extern CALDATA const volatile float32 cal_tCabinHPToEvpEnvTemp;/* Referenced by: '<S1718>/Constant' */
extern CALDATA const volatile float32 cal_tDCBatCoolCellTempOn;/* Referenced by: '<S1403>/Constant' */
extern CALDATA const volatile float32 cal_tLTROffBatBal2ToMaxCellDiff;/* Referenced by:
                                                                      * '<S1470>/Constant'
                                                                      * '<S1570>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tLTROffIPUTemp;/* Referenced by: '<S1465>/Constant' */
extern CALDATA const volatile float32 cal_tLTROnDCChrgMaxCellTemp;/* Referenced by:
                                                                   * '<S1457>/Constant'
                                                                   * '<S1459>/Constant'
                                                                   * '<S1559>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tLTROnDCChrgMinCellTemp;/* Referenced by:
                                                                   * '<S1460>/Constant'
                                                                   * '<S1560>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tLTROnIPUTemp;/* Referenced by:
                                                         * '<S1452>/Constant'
                                                         * '<S1553>/Constant'
                                                         */
extern CALDATA const volatile float32 cal_tLTROnMaxCellToMotDiff;/* Referenced by:
                                                                  * '<S1461>/Constant'
                                                                  * '<S1561>/Constant'
                                                                  * '<S1562>/Constant'
                                                                  */
extern CALDATA const volatile float32 cal_tLTROnMotInletTemp;/* Referenced by: '<S1666>/Constant' */
extern CALDATA const volatile float32 cal_tLTROnMotTemp;/* Referenced by: '<S1667>/Constant' */
extern CALDATA const volatile float32 cal_tLeftSetPointData;/* Referenced by: '<S1165>/Constant' */
extern CALDATA const volatile boolean cal_tLeftSetPointEnb;/* Referenced by: '<S1165>/Constant1' */
extern CALDATA const volatile float32 cal_tMotHeatBatACChrgMinCellTempLow;/* Referenced by:
                                                                      * '<S1597>/Constant'
                                                                      * '<S1617>/Constant'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatBatMinCellTempLow;/* Referenced by:
                                                                     * '<S1602>/Constant'
                                                                     * '<S1621>/Constant'
                                                                     */
extern CALDATA const volatile float32 cal_tMotHeatExitMinCellToBal1Diff;/* Referenced by:
                                                                      * '<S1578>/Constant1'
                                                                      * '<S1613>/Constant1'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatExitMinCellToMotTempDiff;/* Referenced by:
                                                                      * '<S1578>/Constant2'
                                                                      * '<S1613>/Constant2'
                                                                      */
extern CALDATA const volatile float32 cal_tMotHeatOnMotToMinCellDiff;/* Referenced by:
                                                                      * '<S1576>/Constant1'
                                                                      * '<S1577>/Constant1'
                                                                      * '<S1611>/Constant1'
                                                                      * '<S1612>/Constant1'
                                                                      */
extern CALDATA const volatile float32 cal_tMotStorExitMaxCellTemp;/* Referenced by:
                                                                   * '<S1590>/Constant'
                                                                   * '<S1608>/Constant'
                                                                   * '<S1631>/Constant'
                                                                   */
extern CALDATA const volatile float32 cal_tMotStorExitMotToMinCellDiff;/* Referenced by: '<S1575>/Constant3' */
extern CALDATA const volatile float32 cal_tMotStorMinCellTempLow;/* Referenced by: '<S1588>/Constant' */
extern CALDATA const volatile float32 cal_tMotStorOnMotToMinCellDiff;/* Referenced by: '<S1575>/Constant1' */
extern CALDATA const volatile uint16 cal_tiAQSFresh2RecircDelay;/* Referenced by: '<S127>/Constant5' */
extern CALDATA const volatile uint16 cal_tiAQSRecirc2FreshDelay;/* Referenced by: '<S127>/Constant11' */
extern CALDATA const volatile uint16 cal_tiCO2Fresh2RecircMax;/* Referenced by: '<S128>/Constant12' */
extern CALDATA const volatile uint16 cal_tiCO2Recirc2FreshMax;/* Referenced by: '<S128>/Constant5' */
extern CALDATA const volatile uint16 cal_tiColdStartTimeMax;/* Referenced by: '<S39>/Constant2' */

#endif                                 /* RTW_HEADER_TMS_CalibrationData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
