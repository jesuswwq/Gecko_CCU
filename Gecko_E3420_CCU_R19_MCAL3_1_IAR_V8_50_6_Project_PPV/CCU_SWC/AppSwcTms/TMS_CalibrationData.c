#include "TMS_CalibrationData.h"
#include "ME11.h"

#include "XcpTest_types.h"

CALDATA const volatile uint8 ACAuto = 7U;
CALDATA const volatile uint8 ACDefog = 15U;
CALDATA const volatile uint8 ACOff = 8U;
CALDATA const volatile uint8 AC_ColdStart = 1U;
CALDATA const volatile uint8 AC_HotStart = 2U;
CALDATA const volatile uint8 AC_LittleColdStart = 3U;
CALDATA const volatile uint8 BlowerACMode = 5U;
CALDATA const volatile uint8 BlowerBILevelMode = 4U;
CALDATA const volatile uint8 BlowerDefrostMode = 1U;
CALDATA const volatile uint8 BlowerHeaterDefrostMode = 3U;
CALDATA const volatile uint8 BlowerHeaterMode = 2U;
CALDATA const volatile uint8 DriveFRESH = 0U;
CALDATA const volatile uint8 RECIRC = 100U;
CALDATA const volatile float32 cal_ACBatHeatEnvTemp[2] = { 5.0F, 15.0F } ;

CALDATA const volatile float32 cal_ACBatHeatT1[3] = { 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACBatHeatT2[3] = { 5.0F, 5.0F, 5.0F } ;

CALDATA const volatile float32 cal_ACBatHeatTave[3] = { 10.0F, 10.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACBatHeatTrgTemp = 45.0F;
CALDATA const volatile float32 cal_ACCMClsEnvTemp = -14.0F;
CALDATA const volatile float32 cal_ACCMCtlDownlmt = 30.0F;
CALDATA const volatile float32 cal_ACCMCtlKiDeadzoneNeg = 0.5F;
CALDATA const volatile float32 cal_ACCMCtlKiDeadzonePos = 0.5F;
CALDATA const volatile float32 cal_ACCMCtlKpDeadzoneNeg = 0.5F;
CALDATA const volatile float32 cal_ACCMCtlKpDeadzonePos = 0.5F;
CALDATA const volatile float32 cal_ACCMCtlPID_IsumMax = 4000.0F;
CALDATA const volatile float32 cal_ACCMCtlPID_IsumMin = -4000.0F;
CALDATA const volatile float32 cal_ACCMCtlUplmt = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlA1FF_1X[6] = { -15.0F, -10.0F, -5.0F,
  5.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlA1FF_CUR[6] = { 2000.0F, 2000.0F,
  2000.0F, 1500.0F, 1000.0F, 1000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlA2FF_2X[6] = { -10.0F, -5.0F, 0.0F,
  5.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlA2FF_2Y[5] = { 1.0F, 2.0F, 3.0F, 4.0F,
  5.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlA2FF_MAP[30] = { 2000.0F, 2000.0F,
  2000.0F, 1200.0F, 1000.0F, 1000.0F, 2000.0F, 2000.0F, 2000.0F, 1300.0F,
  1200.0F, 1000.0F, 2000.0F, 2000.0F, 2000.0F, 1500.0F, 1300.0F, 1000.0F,
  2000.0F, 2000.0F, 2000.0F, 1600.0F, 1400.0F, 1000.0F, 2000.0F, 2000.0F,
  2000.0F, 1800.0F, 1500.0F, 1200.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlACct = 1.1F;
CALDATA const volatile float32 cal_ACCMCtrlADeadzone = 1.0F;
CALDATA const volatile float32 cal_ACCMCtrlADlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlAKi_1X[8] = { -20.0F, -10.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlAKi_CUR[8] = { 0.5F, 0.6F, 1.0F, 0.6F,
  0.6F, 0.4F, 0.3F, 0.2F } ;

CALDATA const volatile float32 cal_ACCMCtrlAKp_1X[8] = { -15.0F, -10.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlAKp_CUR[8] = { 60.0F, 50.0F, 30.0F,
  10.0F, 10.0F, 15.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlAPIMax = 6000.0F;
CALDATA const volatile float32 cal_ACCMCtrlAPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlARunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlBDeadzone = 0.5F;
CALDATA const volatile float32 cal_ACCMCtrlBDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlBFF_1X[6] = { -5.0F, 0.0F, 5.0F,
  10.0F, 15.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlBFF_CUR[6] = { 1500.0F, 1500.0F,
  1500.0F, 1500.0F, 1200.0F, 1200.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlBKi_1X[8] = { -10.0F, -5.0F, -2.0F,
  -1.0F, 1.0F, 2.0F, 3.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlBKi_CUR[8] = { 0.1F, 0.3F, 0.2F, 0.0F,
  0.0F, 0.01F, 0.03F, 0.1F } ;

CALDATA const volatile float32 cal_ACCMCtrlBKp_1X[8] = { -10.0F, -5.0F, -2.0F,
  -1.0F, 1.0F, 2.0F, 3.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlBKp_CUR[8] = { 50.0F, 40.0F, 50.0F,
  0.0F, 0.0F, 20.0F, 30.0F, 40.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlBPIMax = 6000.0F;
CALDATA const volatile float32 cal_ACCMCtrlBPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlBRunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlC1FF_1X[5] = { 15.0F, 25.0F, 35.0F,
  45.0F, 55.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlC1FF_CUR[5] = { 1000.0F, 1200.0F,
  1500.0F, 1500.0F, 2000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlC2FF_1X[4] = { 2.0F, 3.0F, 4.0F, 5.0F
} ;

CALDATA const volatile float32 cal_ACCMCtrlC2FF_CUR[4] = { 1200.0F, 1200.0F,
  1200.0F, 1200.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlCDeadzone = 0.5F;
CALDATA const volatile float32 cal_ACCMCtrlCDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlCKi_1X[8] = { -20.0F, -15.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlCKi_CUR[8] = { 0.5F, 0.5F, 0.3F, 0.0F,
  0.0F, 0.05F, 0.15F, 0.15F } ;

CALDATA const volatile float32 cal_ACCMCtrlCKp_1X[8] = { -20.0F, -15.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlCKp_CUR[8] = { 30.0F, 20.0F, 10.0F,
  0.0F, 0.0F, 10.0F, 15.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlCPIMax = 6000.0F;
CALDATA const volatile float32 cal_ACCMCtrlCPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlCRunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlD1FF_1X[3] = { 5.0F, 20.0F, 25.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlD1FF_CUR[3] = { 1000.0F, 1000.0F,
  1500.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlD2FF_1X[4] = { 2.0F, 3.0F, 4.0F, 5.0F
} ;

CALDATA const volatile float32 cal_ACCMCtrlD2FF_CUR[4] = { 1000.0F, 1000.0F,
  1000.0F, 1000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDDeadzone = 0.5F;
CALDATA const volatile float32 cal_ACCMCtrlDDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlDKi_1X[8] = { -10.0F, -5.0F, 0.0F,
  2.0F, 4.0F, 6.0F, 8.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDKi_CUR[8] = { 0.5F, 0.3F, 0.005F,
  0.5F, 0.25F, 0.2F, 0.2F, 0.2F } ;

CALDATA const volatile float32 cal_ACCMCtrlDKp_1X[8] = { -10.0F, -5.0F, 0.0F,
  2.0F, 4.0F, 6.0F, 8.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDKp_CUR[8] = { 10.0F, 5.0F, 4.0F,
  2.0F, 4.0F, 6.0F, 10.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDPIMax_1X[5] = { 10.0F, 15.0F, 20.0F,
  25.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDPIMax_CUR[5] = { 2000.0F, 3000.0F,
  4000.0F, 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlDRunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlDTrg_1X[7] = { 15.0F, 16.0F, 18.0F,
  20.0F, 22.0F, 25.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlDTrg_CUR[7] = { 11.0F, 12.0F, 14.0F,
  15.0F, 15.0F, 20.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlE1FF_1X[7] = { 0.0F, 5.0F, 15.0F,
  25.0F, 35.0F, 45.0F, 55.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlE1FF_CUR[7] = { 1000.0F, 1000.0F,
  1000.0F, 1200.0F, 1200.0F, 1200.0F, 1500.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlE2FF_1X[4] = { 2.0F, 3.0F, 4.0F, 5.0F
} ;

CALDATA const volatile float32 cal_ACCMCtrlE2FF_CUR[4] = { 1200.0F, 1200.0F,
  1200.0F, 1200.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlEDeadzone = 1.0F;
CALDATA const volatile float32 cal_ACCMCtrlEDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlEKi_1X[8] = { -10.0F, -5.0F, -2.0F,
  -1.0F, 1.0F, 2.0F, 3.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlEKi_CUR[8] = { 0.1F, 0.3F, 0.2F, 0.0F,
  0.0F, 0.01F, 0.03F, 0.1F } ;

CALDATA const volatile float32 cal_ACCMCtrlEKp_1X[8] = { -10.0F, -5.0F, -2.0F,
  -1.0F, 1.0F, 2.0F, 3.0F, 10.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlEKp_CUR[8] = { 50.0F, 40.0F, 50.0F,
  0.0F, 0.0F, 20.0F, 30.0F, 40.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlEPIMax = 6000.0F;
CALDATA const volatile float32 cal_ACCMCtrlEPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlERunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlETrgTemp = 18.0F;
CALDATA const volatile float32 cal_ACCMCtrlF1FF_1X[5] = { -20.0F, -10.0F, 0.0F,
  10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlF1FF_CUR[5] = { 1500.0F, 1500.0F,
  1000.0F, 1000.0F, 1000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlF2FF_1X[5] = { 1.0F, 2.0F, 3.0F, 4.0F,
  5.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlF2FF_CUR[5] = { 1000.0F, 1000.0F,
  1000.0F, 1000.0F, 1000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlFDeadzone = 1.0F;
CALDATA const volatile float32 cal_ACCMCtrlFDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlFKi_1X[8] = { -20.0F, -10.0F, -3.0F,
  0.0F, 3.0F, 10.0F, 20.0F, 25.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlFKi_CUR[8] = { 0.2F, 0.2F, 0.3F, 0.1F,
  0.2F, 0.15F, 0.1F, 0.1F } ;

CALDATA const volatile float32 cal_ACCMCtrlFKp_1X[8] = { -20.0F, -10.0F, -3.0F,
  0.0F, 3.0F, 10.0F, 20.0F, 25.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlFKp_CUR[8] = { 10.0F, 15.0F, 20.0F,
  0.0F, 15.0F, 10.0F, 20.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlFPIMax_1X[5] = { 10.0F, 15.0F, 20.0F,
  25.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlFPIMax_CUR[5] = { 2000.0F, 3000.0F,
  4000.0F, 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlFPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlFRunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlH1FF_1X[5] = { 15.0F, 25.0F, 35.0F,
  45.0F, 55.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlH1FF_CUR[5] = { 1000.0F, 1200.0F,
  1500.0F, 1500.0F, 2000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlH2FF_1X[4] = { 2.0F, 3.0F, 4.0F, 5.0F
} ;

CALDATA const volatile float32 cal_ACCMCtrlH2FF_CUR[4] = { 1200.0F, 1200.0F,
  1200.0F, 1200.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlHCct = 1.2F;
CALDATA const volatile float32 cal_ACCMCtrlHDeadzone = 0.5F;
CALDATA const volatile float32 cal_ACCMCtrlHDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlHKi_1X[8] = { -20.0F, -15.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlHKi_CUR[8] = { 0.5F, 0.5F, 0.3F, 0.0F,
  0.0F, 0.05F, 0.15F, 0.15F } ;

CALDATA const volatile float32 cal_ACCMCtrlHKp_1X[8] = { -20.0F, -15.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlHKp_CUR[8] = { 30.0F, 20.0F, 10.0F,
  0.0F, 0.0F, 10.0F, 15.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlHPIMax = 6000.0F;
CALDATA const volatile float32 cal_ACCMCtrlHPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlHRunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlI1FF_1X[5] = { 15.0F, 25.0F, 35.0F,
  45.0F, 55.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlI1FF_CUR[5] = { 1000.0F, 1200.0F,
  1500.0F, 1500.0F, 2000.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlI2FF_1X[4] = { 2.0F, 3.0F, 4.0F, 5.0F
} ;

CALDATA const volatile float32 cal_ACCMCtrlI2FF_CUR[4] = { 1200.0F, 1200.0F,
  1200.0F, 1200.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlIDeadzone = 0.5F;
CALDATA const volatile float32 cal_ACCMCtrlIDlyTime = 5.0F;
CALDATA const volatile float32 cal_ACCMCtrlIKi_1X[8] = { -20.0F, -15.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlIKi_CUR[8] = { 0.5F, 0.5F, 0.3F, 0.0F,
  0.0F, 0.05F, 0.15F, 0.15F } ;

CALDATA const volatile float32 cal_ACCMCtrlIKp_1X[8] = { -20.0F, -15.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlIKp_CUR[8] = { 30.0F, 20.0F, 10.0F,
  0.0F, 0.0F, 10.0F, 15.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCMCtrlIPIMax = 6000.0F;
CALDATA const volatile float32 cal_ACCMCtrlIPIMin = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlIRunTime = 15.0F;
CALDATA const volatile float32 cal_ACCMCtrlKi = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlKp = 0.0F;
CALDATA const volatile float32 cal_ACCMCtrlSpdData = 0.0F;
CALDATA const volatile boolean cal_ACCMCtrlSpdDataEnb = false;
CALDATA const volatile boolean cal_ACCMEnbData = false;
CALDATA const volatile boolean cal_ACCMEnbDataEnb = false;
CALDATA const volatile boolean cal_ACCMForbidCtrl = true;
CALDATA const volatile float32 cal_ACCMHiTempData = 0.0F;
CALDATA const volatile boolean cal_ACCMHiTempDataEnb = false;
CALDATA const volatile uint8 cal_ACCMHiTempFanCtrl = 84U;
CALDATA const volatile float32 cal_ACCMHiTempFanOff = 70.0F;
CALDATA const volatile float32 cal_ACCMHiTempFanOn = 85.0F;
CALDATA const volatile uint16 cal_ACCMHighTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_ACCMHighTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_ACCMOpenEnvTemp = -12.0F;
CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2X[12] = { -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 40.0F } ;

CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_2Y[12] = { 16.0F, 18.0F,
  20.0F, 21.0F, 22.0F, 23.0F, 24.0F, 25.0F, 26.0F, 27.0F, 30.0F, 32.0F } ;

CALDATA const volatile float32 cal_ACCabinPreSetByEnvECO_MAP[144] = { 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  20.0F, 19.5F, 19.5F, 19.0F, 17.0F, 15.5F, 16.5F, 16.5F, 18.0F, 20.0F, 20.5F,
  20.5F, 23.0F, 22.0F, 21.0F, 21.0F, 20.0F, 18.5F, 19.5F, 19.5F, 21.0F, 23.0F,
  23.5F, 23.5F, 23.5F, 22.0F, 21.5F, 21.0F, 20.5F, 19.0F, 20.0F, 20.0F, 21.0F,
  23.0F, 24.0F, 24.0F, 24.5F, 23.5F, 23.0F, 22.0F, 21.5F, 20.5F, 20.0F, 20.5F,
  21.5F, 23.0F, 24.0F, 24.0F, 25.0F, 24.0F, 23.5F, 23.0F, 22.0F, 21.0F, 20.5F,
  21.0F, 22.0F, 23.0F, 24.0F, 24.0F, 26.0F, 25.0F, 24.0F, 23.5F, 22.5F, 22.0F,
  22.0F, 21.5F, 23.0F, 24.0F, 24.5F, 24.5F, 27.0F, 26.0F, 25.5F, 25.0F, 24.0F,
  22.5F, 22.5F, 22.0F, 24.0F, 25.0F, 25.5F, 25.5F, 28.0F, 27.0F, 26.5F, 26.0F,
  25.0F, 24.0F, 24.0F, 23.0F, 25.0F, 26.0F, 26.5F, 26.5F, 29.0F, 27.5F, 27.0F,
  26.5F, 25.5F, 25.5F, 25.0F, 24.5F, 26.5F, 26.5F, 28.0F, 28.0F, 31.5F, 31.0F,
  31.0F, 30.5F, 27.0F, 27.0F, 26.0F, 25.5F, 28.0F, 28.0F, 29.5F, 29.5F, 40.0F,
  40.0F, 40.0F, 40.0F, 35.0F, 35.0F, 35.0F, 35.0F, 30.0F, 30.0F, 30.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2X[12] = { -20.0F, -15.0F,
  -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 40.0F } ;

CALDATA const volatile float32 cal_ACCabinPreSetByEnv_2Y[12] = { 16.0F, 18.0F,
  20.0F, 21.0F, 22.0F, 23.0F, 24.0F, 25.0F, 26.0F, 27.0F, 30.0F, 32.0F } ;

CALDATA const volatile float32 cal_ACCabinPreSetByEnv_MAP[144] = { 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 15.0F, 22.0F,
  21.5F, 21.5F, 21.0F, 20.5F, 19.0F, 17.5F, 17.0F, 17.0F, 17.0F, 16.5F, 16.5F,
  25.0F, 24.0F, 23.0F, 23.0F, 22.5F, 22.0F, 20.5F, 20.0F, 20.0F, 20.0F, 19.5F,
  19.5F, 25.5F, 24.0F, 23.5F, 23.0F, 23.0F, 22.5F, 21.0F, 20.5F, 21.0F, 20.0F,
  20.0F, 20.0F, 26.5F, 25.5F, 25.0F, 24.0F, 24.0F, 23.5F, 22.5F, 21.5F, 21.0F,
  20.5F, 20.0F, 20.0F, 27.0F, 26.0F, 25.5F, 25.0F, 25.0F, 24.0F, 23.0F, 22.0F,
  22.0F, 21.0F, 21.0F, 21.0F, 28.0F, 27.0F, 26.0F, 25.5F, 25.5F, 24.5F, 24.0F,
  23.5F, 22.0F, 22.0F, 21.5F, 21.5F, 29.0F, 28.0F, 27.5F, 27.0F, 27.0F, 26.0F,
  24.5F, 24.0F, 22.5F, 23.0F, 22.5F, 22.5F, 30.0F, 29.0F, 28.5F, 28.0F, 28.0F,
  27.0F, 26.0F, 25.5F, 24.5F, 24.0F, 23.5F, 23.5F, 31.0F, 29.5F, 29.0F, 28.5F,
  28.0F, 27.5F, 27.5F, 26.5F, 26.0F, 25.5F, 25.0F, 25.0F, 33.5F, 33.0F, 33.0F,
  32.5F, 32.0F, 29.0F, 29.0F, 27.5F, 27.0F, 27.0F, 26.5F, 26.5F, 40.0F, 40.0F,
  40.0F, 40.0F, 35.0F, 35.0F, 35.0F, 35.0F, 30.0F, 30.0F, 30.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACChgBatHighSOCHeat = 85.0F;
CALDATA const volatile float32 cal_ACChgBatLowSOCHeat = 83.0F;
CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_1X[7] = { -40.0F, -20.0F,
  -10.0F, 0.0F, 10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_ACChrgBatHeatTrgTemp_CUR[7] = { 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F } ;

CALDATA const volatile uint8 cal_ACCtlRecLevelForACHotStart = 4U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForAQS = 9U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForForceChange = 14U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForForceDefog = 11U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForManual = 12U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForNormalDefog = 7U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForPCUTemp = 10U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForPTCDvt = 3U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForQkChargeCooling = 13U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForRemoteAC = 15U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForSummer = 1U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForTargetOutTemp = 5U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForTempLow = 8U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForVent = 6U;
CALDATA const volatile uint8 cal_ACCtlRecLevelForWinter = 2U;
CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2X[10] = { 15.0F, 20.0F,
  22.5F, 25.0F, 28.0F, 30.0F, 33.0F, 35.0F, 38.0F, 40.0F } ;

CALDATA const volatile float32 cal_ACDVTPreSetByEnv_2Y[10] = { -10.0F, -5.0F,
  0.0F, 5.0F, 15.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F } ;

CALDATA const volatile float32 cal_ACDVTPreSetByEnv_MAP[100] = { 12.0F, 17.0F,
  19.5F, 22.5F, 27.5F, 33.5F, 39.0F, 43.0F, 45.0F, 47.0F, 12.0F, 17.0F, 19.0F,
  22.0F, 27.0F, 33.0F, 39.0F, 43.0F, 45.0F, 47.0F, 12.0F, 17.0F, 19.0F, 22.0F,
  27.0F, 33.0F, 39.0F, 43.0F, 45.0F, 47.0F, 12.0F, 17.0F, 19.0F, 22.0F, 27.0F,
  33.0F, 39.0F, 43.0F, 45.0F, 47.0F, 12.0F, 19.0F, 22.0F, 24.5F, 31.5F, 36.0F,
  39.0F, 43.0F, 45.0F, 47.0F, 12.0F, 19.0F, 22.0F, 24.5F, 24.5F, 22.5F, 21.5F,
  20.5F, 19.5F, 18.5F, 12.0F, 19.0F, 22.0F, 24.5F, 24.5F, 22.5F, 21.5F, 20.5F,
  19.5F, 18.5F, 12.0F, 19.0F, 22.0F, 24.5F, 24.5F, 22.5F, 21.5F, 20.5F, 19.5F,
  18.5F, 12.0F, 19.0F, 22.0F, 24.5F, 24.5F, 22.5F, 21.5F, 20.5F, 19.5F, 18.5F,
  12.0F, 19.0F, 22.0F, 24.5F, 24.5F, 22.5F, 21.5F, 20.5F, 19.5F, 18.5F } ;

CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_1X[16] = { -25.0F, -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F, 50.0F } ;

CALDATA const volatile float32 cal_ACDVTPreSetEnvCor_CUR[16] = { 15.0F, 13.0F,
  13.0F, 11.0F, 10.0F, 9.0F, 5.0F, 4.5F, 2.0F, 1.0F, -1.0F, -3.5F, -6.0F, -8.5F,
  -3.0F, -3.0F } ;

CALDATA const volatile uint16 cal_ACDVTPreSetSolarCorByVx_2X[6] = { 0U, 100U,
  350U, 700U, 1000U, 1200U } ;

CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_2Y[6] = { 0.0F, 10.0F,
  30.0F, 40.0F, 60.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACDVTPreSetSolarCorByVx_MAP[36] = { 0.0F,
  0.0F, -0.5F, -1.0F, -1.5F, -2.5F, 0.0F, 0.0F, 0.0F, 0.0F, -0.5F, -1.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint16 cal_ACDVTPreSetSolarCor_2X[8] = { 0U, 150U, 200U,
  300U, 400U, 500U, 700U, 1000U } ;

CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_2Y[8] = { -40.0F, -10.0F,
  0.0F, 5.0F, 15.0F, 25.0F, 35.0F, 40.0F } ;

CALDATA const volatile float32 cal_ACDVTPreSetSolarCor_MAP[64] = { 0.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, 0.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, 0.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  0.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, 0.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, 0.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, 0.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, 0.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F } ;

CALDATA const volatile uint16 cal_ACDrDVTSolarCor_2X[15] = { 0U, 100U, 200U,
  300U, 350U, 400U, 450U, 500U, 550U, 600U, 700U, 800U, 900U, 1000U, 1200U } ;

CALDATA const volatile float32 cal_ACDrDVTSolarCor_2Y[15] = { -25.0F, -20.0F,
  -15.0F, -10.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F,
  45.0F, 50.0F } ;

CALDATA const volatile float32 cal_ACDrDVTSolarCor_MAP[225] = { 0.0F, 0.0F,
  -1.0F, -1.5F, -2.0F, -3.0F, -3.0F, -3.0F, -3.0F, -3.0F, -4.0F, -4.0F, -4.0F,
  -4.0F, -4.0F, 0.0F, 0.0F, -1.0F, -1.5F, -2.0F, -3.0F, -3.0F, -3.0F, -3.0F,
  -3.0F, -4.0F, -4.0F, -4.0F, -4.0F, -4.0F, 0.0F, 0.0F, 0.0F, -1.0F, -2.0F,
  -3.0F, -3.0F, -3.0F, -3.5F, -3.5F, -3.5F, -3.5F, -3.5F, -3.5F, -3.5F, 0.0F,
  0.0F, 0.0F, -1.5F, -2.5F, -3.5F, -4.0F, -4.5F, -5.0F, -5.0F, -6.0F, -6.0F,
  -6.0F, -6.0F, -6.0F, 0.0F, 0.0F, 0.0F, -1.5F, -2.5F, -3.5F, -4.5F, -5.0F,
  -5.5F, -6.0F, -6.5F, -6.5F, -6.5F, -6.5F, -6.5F, 0.0F, 0.0F, 0.0F, -1.5F,
  -3.0F, -4.0F, -4.5F, -5.0F, -5.5F, -6.0F, -6.5F, -6.5F, -6.5F, -6.5F, -6.5F,
  0.0F, 0.0F, -1.0F, -2.0F, -3.5F, -4.5F, -4.5F, -5.5F, -6.0F, -7.0F, -7.5F,
  -7.5F, -7.5F, -7.5F, -7.5F, 0.0F, 0.0F, -1.0F, -2.0F, -2.5F, -3.5F, -4.0F,
  -4.0F, -5.0F, -6.0F, -6.5F, -6.5F, -6.5F, -6.5F, -6.5F, 0.0F, 0.0F, -1.0F,
  -1.5F, -3.0F, -3.5F, -4.5F, -4.5F, -4.5F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F,
  -5.0F, 0.0F, 0.0F, -1.0F, -2.5F, -2.5F, -3.5F, -3.5F, -4.5F, -4.5F, -4.5F,
  -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F, 0.0F, -2.0F, -2.5F, -3.0F, -3.5F,
  -4.0F, -4.0F, -4.5F, -4.5F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F, 0.0F,
  -2.0F, -2.5F, -3.0F, -3.5F, -4.0F, -4.0F, -4.5F, -4.5F, -5.0F, -5.0F, -5.0F,
  -5.0F, -5.0F, 0.0F, 0.0F, -2.0F, -2.5F, -3.0F, -3.5F, -4.0F, -4.0F, -4.5F,
  -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F, 0.0F, -2.0F, -2.5F, -3.0F,
  -3.5F, -4.0F, -4.0F, -4.5F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F,
  0.0F, -2.0F, -2.5F, -3.0F, -3.5F, -4.0F, -4.0F, -4.5F, -5.0F, -5.0F, -5.0F,
  -5.0F, -5.0F, -5.0F } ;

CALDATA const volatile float32 cal_ACFanLevel0EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel0EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel1EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel1EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel2EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel2EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel3EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel3EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel4EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel4EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel5EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel5EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel6EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel6EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel7EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel7EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel8EnvCor_1X[2] = { -8.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanLevel8EnvCor_CUR[2] = { 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACFanMaxSpdCellTempLim_1X[5] = { 48.0F, 54.0F,
  60.0F, 65.0F, 100.0F } ;

CALDATA const volatile uint8 cal_ACFanMaxSpdCellTempLim_CUR[5] = { 43U, 42U, 41U,
  40U, 39U } ;

CALDATA const volatile float32 cal_ACFanMaxSpdDvtLim_1X[5] = { 10.0F, 20.0F,
  45.0F, 64.0F, 70.0F } ;

CALDATA const volatile uint8 cal_ACFanMaxSpdDvtLim_CUR[5] = { 78U, 59U, 41U, 34U,
  23U } ;

CALDATA const volatile float32 cal_ACFanSpdBatCor_1X[3] = { 9.0F, 12.0F, 15.0F }
;

CALDATA const volatile float32 cal_ACFanSpdBatCor_CUR[3] = { 1.0F, 1.0F, 1.0F } ;

CALDATA const volatile float32 cal_ACFanSpdDvtSet_1X[14] = { 0.5F, 2.0F, 4.0F,
  6.0F, 8.0F, 10.0F, 14.0F, 22.0F, 30.0F, 37.0F, 45.0F, 55.0F, 65.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACFanSpdDvtSet_CUR[14] = { 78.0F, 56.0F,
  43.0F, 37.0F, 34.0F, 33.0F, 31.0F, 33.0F, 36.0F, 40.0F, 50.0F, 58.0F, 70.0F,
  78.0F } ;

CALDATA const volatile float32 cal_ACFanSpdRecircCor_1X[4] = { 0.0F, 20.0F,
  80.0F, 100.0F } ;

CALDATA const volatile float32 cal_ACFanSpdRecircCor_CUR[4] = { 0.0F, 0.0F, 0.0F,
  0.0F } ;

CALDATA const volatile uint16 cal_ACFanSpdSolarCorByEnv_2X[15] = { 0U, 100U,
  200U, 300U, 350U, 400U, 450U, 500U, 550U, 600U, 700U, 800U, 900U, 1000U, 1200U
} ;

CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_2Y[15] = { -25.0F,
  -20.0F, -15.0F, -10.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F, 50.0F } ;

CALDATA const volatile float32 cal_ACFanSpdSolarCorByEnv_MAP[225] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 0.0F, 1.0F, 1.0F, 2.0F, 2.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 0.0F, 1.0F, 1.0F, 2.0F,
  2.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 0.0F, 3.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 6.0F, 6.0F,
  0.0F, 3.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F,
  7.0F, 7.0F } ;

CALDATA const volatile uint16 cal_ACFanSpdSolarCor_2X[15] = { 100U, 150U, 200U,
  300U, 400U, 450U, 500U, 550U, 600U, 650U, 700U, 800U, 900U, 1000U, 1200U } ;

CALDATA const volatile float32 cal_ACFanSpdSolarCor_2Y[15] = { -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 40.0F, 45.0F, 50.0F, 55.0F,
  60.0F, 70.0F } ;

CALDATA const volatile float32 cal_ACFanSpdSolarCor_MAP[225] = { 0.0F, 2.0F,
  3.0F, 4.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F, 6.0F, 7.0F, 7.0F, 8.0F, 9.0F, 10.0F,
  0.0F, 2.0F, 3.0F, 4.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F, 6.0F, 7.0F, 7.0F, 8.0F,
  9.0F, 10.0F, 0.0F, 2.0F, 3.0F, 4.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F, 6.0F, 7.0F,
  7.0F, 8.0F, 9.0F, 10.0F, 0.0F, 2.0F, 3.0F, 4.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 7.0F, 7.0F, 8.0F, 9.0F, 10.0F, 0.0F, 1.0F, 1.0F, 4.0F, 5.0F, 5.0F, 6.0F,
  6.0F, 6.0F, 6.0F, 7.0F, 7.0F, 8.0F, 9.0F, 10.0F, 0.0F, 1.0F, 1.0F, 4.0F, 5.0F,
  5.0F, 6.0F, 6.0F, 6.0F, 6.0F, 7.0F, 7.0F, 8.0F, 9.0F, 10.0F, 0.0F, 1.0F, 1.0F,
  4.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F, 6.0F, 7.0F, 7.0F, 8.0F, 9.0F, 10.0F, 0.0F,
  0.0F, 0.0F, 1.0F, 2.0F, 2.0F, 3.0F, 3.0F, 4.0F, 4.0F, 5.0F, 6.0F, 8.0F, 10.0F,
  14.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 2.0F, 0.0F, 0.0F, 0.0F, -1.0F, -3.0F, -3.0F, -3.0F, -3.0F, -4.0F,
  -4.0F, -5.0F, -6.0F, -7.0F, -9.0F, -11.0F, 0.0F, 0.0F, 0.0F, -1.0F, -3.0F,
  -3.0F, -3.0F, -3.0F, -4.0F, -4.0F, -5.0F, -6.0F, -7.0F, -9.0F, -11.0F, 0.0F,
  0.0F, 0.0F, -2.0F, -4.0F, -4.0F, -4.0F, -4.0F, -5.0F, -5.0F, -5.0F, -6.0F,
  -8.0F, -10.0F, -12.0F, 0.0F, 0.0F, 0.0F, -2.0F, -4.0F, -4.0F, -4.0F, -4.0F,
  -5.0F, -5.0F, -6.0F, -7.0F, -8.0F, -10.0F, -12.0F, 0.0F, 0.0F, 0.0F, -3.0F,
  -5.0F, -5.0F, -5.0F, -5.0F, -6.0F, -6.0F, -6.0F, -7.0F, -9.0F, -11.0F, -13.0F,
  0.0F, 0.0F, 0.0F, -3.0F, -5.0F, -5.0F, -5.0F, -5.0F, -6.0F, -6.0F, -6.0F,
  -7.0F, -9.0F, -11.0F, -13.0F } ;

CALDATA const volatile float32 cal_ACFanSpdVssCor_1X[3] = { 0.0F, 40.0F, 120.0F
} ;

CALDATA const volatile float32 cal_ACFanSpdVssCor_CUR[3] = { 0.0F, 1.0F, 2.0F } ;

CALDATA const volatile float32 cal_ACInletAutoDefogPrtEnvCor_1X[10] = { -40.0F,
  -30.0F, -20.0F, -15.0F, -10.0F, 0.0F, 5.0F, 15.0F, 20.0F, 30.0F } ;

CALDATA const volatile uint8 cal_ACInletAutoDefogPrtEnvCor_CUR[10] = { 15U, 15U,
  15U, 15U, 15U, 15U, 15U, 100U, 100U, 0U } ;

CALDATA const volatile float32 cal_ACInletDefogPrtEnvCor_1X[10] = { -40.0F,
  -30.0F, -20.0F, -15.0F, -10.0F, 0.0F, 5.0F, 15.0F, 20.0F, 30.0F } ;

CALDATA const volatile uint8 cal_ACInletDefogPrtEnvCor_CUR[10] = { 15U, 15U, 15U,
  15U, 15U, 15U, 15U, 100U, 100U, 0U } ;

CALDATA const volatile uint8 cal_ACInletDefogRiskCor_1X[2] = { 0U, 3U } ;

CALDATA const volatile uint8 cal_ACInletDefogRiskCor_CUR[2] = { 100U, 100U } ;

CALDATA const volatile float32 cal_ACInletEnvPrtSetCool_1X[5] = { -10.0F, 0.0F,
  20.0F, 40.0F, 60.0F } ;

CALDATA const volatile uint8 cal_ACInletEnvPrtSetCool_CUR[5] = { 0U, 0U, 0U, 0U,
  0U } ;

CALDATA const volatile float32 cal_ACInletEnvPrtSetHeat_1X[5] = { -10.0F, 0.0F,
  20.0F, 40.0F, 60.0F } ;

CALDATA const volatile uint8 cal_ACInletEnvPrtSetHeat_CUR[5] = { 80U, 80U, 0U,
  0U, 0U } ;

CALDATA const volatile uint8 cal_ACPMPSpdDiffVal = 10U;
CALDATA const volatile float32 cal_ACPTCDesBacAC_1X[12] = { -20.0F, 0.0F, 14.0F,
  15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacAC_CUR[12] = { 0.0F, 0.0F, 0.0F,
  15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacBi_1X[12] = { -20.0F, 0.0F, 14.0F,
  15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacBi_CUR[12] = { 0.0F, 0.0F, 0.0F,
  15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacDefog_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacDefog_CUR[12] = { 0.0F, 0.0F, 0.0F,
  15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacFootDe_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacFootDe_CUR[12] = { 0.0F, 0.0F,
  0.0F, 15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacFoot_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 60.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCDesBacFoot_CUR[12] = { 0.0F, 0.0F, 0.0F,
  15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCDesCabinCor_1X[8] = { -20.0F, -10.0F,
  -5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 41.0F } ;

CALDATA const volatile float32 cal_ACPTCDesCabinCor_CUR[8] = { 5.0F, 5.0F, 2.0F,
  1.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACPTCDesEnvCor_2X[6] = { -20.0F, -10.0F,
  -5.0F, 0.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACPTCDesEnvCor_2Y[6] = { 10.0F, 20.0F, 60.0F,
  80.0F, 100.0F, 120.0F } ;

CALDATA const volatile float32 cal_ACPTCDesEnvCor_MAP[36] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F,
  0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F,
  0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint8 cal_ACPTCDesFanCor_1X[4] = { 0U, 3U, 5U, 8U } ;

CALDATA const volatile float32 cal_ACPTCDesFanCor_CUR[4] = { 0.0F, 1.0F, 2.0F,
  3.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacAC_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacAC_CUR[12] = { 0.0F, 0.0F, 0.0F,
  15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacBi_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacBi_CUR[12] = { 0.0F, 0.0F, 0.0F,
  15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacDefog_CUR[12] = { 0.0F, 0.0F,
  0.0F, 15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacFootDe_CUR[12] = { 0.0F, 0.0F,
  0.0F, 15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_1X[12] = { -20.0F, 0.0F,
  14.0F, 15.0F, 25.0F, 29.0F, 32.0F, 50.0F, 65.0F, 70.0F, 80.0F, 81.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesBacFoot_CUR[12] = { 0.0F, 0.0F,
  0.0F, 15.0F, 25.0F, 30.0F, 35.0F, 50.0F, 62.0F, 73.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_1X[8] = { -20.0F, -10.0F,
  -5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 41.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesCabinCor_CUR[8] = { 5.0F, 5.0F,
  2.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2X[6] = { -20.0F, -10.0F,
  -5.0F, 0.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_2Y[6] = { 10.0F, 20.0F,
  60.0F, 80.0F, 100.0F, 120.0F } ;

CALDATA const volatile float32 cal_ACPTCPsDesEnvCor_MAP[36] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F,
  0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F, 0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F,
  0.0F, 3.0F, 2.0F, 1.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint8 cal_ACPTCPsDesFanCor_1X[4] = { 0U, 3U, 5U, 8U } ;

CALDATA const volatile float32 cal_ACPTCPsDesFanCor_CUR[4] = { 0.0F, 1.0F, 2.0F,
  3.0F } ;

CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2X[14] = { -16.0F, -10.0F,
  -5.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 10.0F, 16.0F }
;

CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_2Y[14] = { -25.0F, -20.0F,
  -15.0F, -10.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F,
  45.0F } ;

CALDATA const volatile float32 cal_ACPsDVTSetCorByEnv_MAP[196] = { -40.0F,
  -35.0F, -25.0F, -12.0F, -10.0F, -5.0F, 0.0F, 5.0F, 18.0F, 20.0F, 21.0F, 22.0F,
  30.0F, 50.0F, -40.0F, -35.0F, -25.0F, -12.0F, -10.0F, -5.0F, 0.0F, 5.0F, 18.0F,
  20.0F, 21.0F, 22.0F, 30.0F, 50.0F, -40.0F, -35.0F, -25.0F, -12.0F, -10.0F,
  -5.0F, 0.0F, 5.0F, 18.0F, 20.0F, 21.0F, 22.0F, 30.0F, 50.0F, -40.0F, -35.0F,
  -25.0F, -12.0F, -10.0F, -5.0F, 0.0F, 5.0F, 18.0F, 20.0F, 21.0F, 22.0F, 30.0F,
  50.0F, -40.0F, -35.0F, -25.0F, -12.0F, -10.0F, -5.0F, 0.0F, 5.0F, 18.0F, 20.0F,
  21.0F, 22.0F, 30.0F, 50.0F, -40.0F, -35.0F, -25.0F, -12.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 18.0F, 20.0F, 21.0F, 22.0F, 30.0F, 50.0F, -40.0F, -35.0F, -25.0F,
  -12.0F, -10.0F, -5.0F, 0.0F, 5.0F, 18.0F, 20.0F, 21.0F, 22.0F, 30.0F, 50.0F,
  -40.0F, -35.0F, -25.0F, -12.0F, -10.0F, -5.0F, 0.0F, 5.0F, 18.0F, 20.0F, 21.0F,
  22.0F, 30.0F, 50.0F, -40.0F, -35.0F, -25.0F, -12.0F, -10.0F, -5.0F, 0.0F, 5.0F,
  18.0F, 20.0F, 21.0F, 22.0F, 30.0F, 50.0F, -40.0F, -30.0F, -14.0F, -10.5F,
  -7.0F, -3.5F, 0.0F, 3.5F, 7.0F, 10.5F, 14.0F, 17.5F, 30.0F, 40.0F, -40.0F,
  -30.0F, -14.0F, -10.5F, -7.0F, -3.5F, 0.0F, 3.5F, 7.0F, 10.5F, 14.0F, 17.5F,
  30.0F, 40.0F, -40.0F, -30.0F, -14.0F, -10.5F, -7.0F, -3.5F, 0.0F, 3.5F, 7.0F,
  10.5F, 14.0F, 17.5F, 30.0F, 40.0F, -40.0F, -30.0F, -14.0F, -10.5F, -7.0F,
  -3.5F, 0.0F, 3.5F, 7.0F, 10.5F, 14.0F, 17.5F, 30.0F, 40.0F, -40.0F, -30.0F,
  -14.0F, -10.5F, -7.0F, -3.5F, 0.0F, 3.5F, 7.0F, 10.5F, 14.0F, 17.5F, 30.0F,
  40.0F } ;

CALDATA const volatile uint16 cal_ACPsDVTSolarCor_2X[15] = { 0U, 100U, 200U,
  300U, 350U, 400U, 450U, 500U, 550U, 600U, 700U, 800U, 900U, 1000U, 1200U } ;

CALDATA const volatile float32 cal_ACPsDVTSolarCor_2Y[15] = { -25.0F, -20.0F,
  -15.0F, -10.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F,
  45.0F, 50.0F } ;

CALDATA const volatile float32 cal_ACPsDVTSolarCor_MAP[225] = { 0.0F, 0.0F,
  -1.0F, -1.5F, -2.0F, -3.0F, -3.0F, -3.0F, -3.0F, -3.0F, -4.0F, -4.0F, -4.0F,
  -4.0F, -4.0F, 0.0F, 0.0F, -1.0F, -1.5F, -2.0F, -3.0F, -3.0F, -3.0F, -3.0F,
  -3.0F, -4.0F, -4.0F, -4.0F, -4.0F, -4.0F, 0.0F, 0.0F, 0.0F, -1.0F, -2.0F,
  -3.0F, -3.0F, -3.0F, -3.5F, -3.5F, -3.5F, -3.5F, -3.5F, -3.5F, -3.5F, 0.0F,
  0.0F, 0.0F, -1.5F, -2.5F, -3.5F, -4.0F, -4.5F, -5.0F, -5.0F, -6.0F, -6.0F,
  -6.0F, -6.0F, -6.0F, 0.0F, 0.0F, 0.0F, -1.5F, -2.5F, -3.5F, -4.5F, -5.0F,
  -5.5F, -6.0F, -6.5F, -6.5F, -6.5F, -6.5F, -6.5F, 0.0F, 0.0F, 0.0F, -1.5F,
  -3.0F, -4.0F, -4.5F, -5.0F, -5.5F, -6.0F, -6.5F, -6.5F, -6.5F, -6.5F, -6.5F,
  0.0F, 0.0F, -1.0F, -2.0F, -3.5F, -4.5F, -4.5F, -5.5F, -6.0F, -7.0F, -7.5F,
  -7.5F, -7.5F, -7.5F, -7.5F, 0.0F, 0.0F, -1.0F, -2.0F, -2.5F, -3.5F, -4.0F,
  -4.0F, -5.0F, -6.0F, -6.5F, -6.5F, -6.5F, -6.5F, -6.5F, 0.0F, 0.0F, -1.0F,
  -1.5F, -3.0F, -3.5F, -4.5F, -4.5F, -4.5F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F,
  -5.0F, 0.0F, 0.0F, -1.0F, -2.5F, -2.5F, -3.5F, -3.5F, -4.5F, -4.5F, -4.5F,
  -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F, 0.0F, -2.0F, -2.5F, -3.0F, -3.5F,
  -4.0F, -4.0F, -4.5F, -4.5F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F, 0.0F,
  -2.0F, -2.5F, -3.0F, -3.5F, -4.0F, -4.0F, -4.5F, -4.5F, -5.0F, -5.0F, -5.0F,
  -5.0F, -5.0F, 0.0F, 0.0F, -2.0F, -2.5F, -3.0F, -3.5F, -4.0F, -4.0F, -4.5F,
  -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F, 0.0F, -2.0F, -2.5F, -3.0F,
  -3.5F, -4.0F, -4.0F, -4.5F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, -5.0F, 0.0F,
  0.0F, -2.0F, -2.5F, -3.0F, -3.5F, -4.0F, -4.0F, -4.5F, -5.0F, -5.0F, -5.0F,
  -5.0F, -5.0F, -5.0F } ;

CALDATA const volatile uint8 cal_ACPumpBatHeatSpd = 80U;
CALDATA const volatile uint8 cal_ACPumpCtrlASpd = 80U;
CALDATA const volatile uint8 cal_ACPumpDefSpd = 10U;
CALDATA const volatile uint8 cal_ACPumpDehSpd = 80U;
CALDATA const volatile uint8 cal_ACPumpDoubleHeatSpd = 80U;
CALDATA const volatile uint8 cal_ACRecirRatioLmt = 50U;
CALDATA const volatile float32 cal_ADCVCCVal = 2700.0F;
CALDATA const volatile float32 cal_AEXVClsEvapPrtTemp = 1.0F;
CALDATA const volatile float32 cal_AEXVClsValEvapPrt = 3.0F;
CALDATA const volatile float32 cal_AEXVClsValRunTimeEvapPrt = 10.0F;
CALDATA const volatile float32 cal_AEXVCtlKi = 0.0F;
CALDATA const volatile float32 cal_AEXVCtlKisumMax = 50.0F;
CALDATA const volatile float32 cal_AEXVCtlKisumMin = -50.0F;
CALDATA const volatile float32 cal_AEXVCtlKp = 0.0F;
CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_1X[6] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBCabinCoolPIMin_CUR[6] = { 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F, 15.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_1X[6] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBDCoolPIMin_CUR[6] = { 15.0F, 15.0F,
  15.0F, 15.0F, 15.0F, 15.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBDeadzone = 0.5F;
CALDATA const volatile float32 cal_AEXVCtrlBDelayTime = 10.0F;
CALDATA const volatile float32 cal_AEXVCtrlBFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBFF_CUR[5] = { 30.0F, 30.0F, 30.0F,
  30.0F, 30.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBKi_1X[8] = { -10.0F, -3.0F, -2.0F,
  -1.0F, 1.0F, 2.0F, 3.0F, 10.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBKi_CUR[8] = { 0.004F, 0.004F, 0.002F,
  0.0F, 0.0F, 0.002F, 0.004F, 0.004F } ;

CALDATA const volatile float32 cal_AEXVCtrlBKp_1X[8] = { -10.0F, -3.0F, -2.0F,
  -1.0F, 1.0F, 2.0F, 3.0F, 10.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBKp_CUR[8] = { 2.0F, 2.5F, 2.0F, 0.2F,
  0.2F, 1.0F, 2.0F, 1.5F } ;

CALDATA const volatile float32 cal_AEXVCtrlBOpenVal = 30.0F;
CALDATA const volatile float32 cal_AEXVCtrlBPIMax = 100.0F;
CALDATA const volatile float32 cal_AEXVCtrlBPIMin = 15.0F;
CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_1X[9] = { 1000.0F,
  1500.0F, 2000.0F, 2500.0F, 3000.0F, 4000.0F, 5000.0F, 5500.0F, 6000.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR[9] = { 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_1X[9] = { 10.0F, 15.0F,
  20.0F, 25.0F, 28.0F, 31.0F, 32.0F, 35.0F, 40.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlBTrgSubCool_CUR[9] = { 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCDeadzone = 0.5F;
CALDATA const volatile float32 cal_AEXVCtrlCDelayTime = 10.0F;
CALDATA const volatile float32 cal_AEXVCtrlCFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCFF_CUR[5] = { 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCKi_1X[7] = { -10.0F, -5.0F, -2.0F,
  0.0F, 4.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCKi_CUR[7] = { 0.03F, 0.03F, 0.0F,
  0.0F, 0.0F, 0.02F, 0.02F } ;

CALDATA const volatile float32 cal_AEXVCtrlCKp_1X[7] = { -10.0F, -5.0F, -2.0F,
  0.0F, 4.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCKp_CUR[7] = { 1.5F, 1.0F, 0.0F, 0.0F,
  0.0F, 0.6F, 1.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCOpenVal = 100.0F;
CALDATA const volatile float32 cal_AEXVCtrlCPIMax = 100.0F;
CALDATA const volatile float32 cal_AEXVCtrlCPIMin = 10.0F;
CALDATA const volatile float32 cal_AEXVCtrlCTrgflt = 0.015F;
CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_1X[7] = { 6.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlCTrgtSuperHeat_CUR[7] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDDeadzone = 1.0F;
CALDATA const volatile float32 cal_AEXVCtrlDDelayTime = 10.0F;
CALDATA const volatile float32 cal_AEXVCtrlDFF_1X[5] = { 800.0F, 1000.0F,
  1500.0F, 2000.0F, 4000.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDFF_CUR[5] = { 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDKi_1X[8] = { -15.0F, -10.0F, -6.0F,
  -3.0F, 3.0F, 6.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDKi_CUR[8] = { 0.02F, 0.02F, 0.03F,
  0.0F, 0.0F, 0.0F, 0.02F, 0.02F } ;

CALDATA const volatile float32 cal_AEXVCtrlDKp_1X[8] = { -15.0F, -10.0F, -6.0F,
  -3.0F, 3.0F, 6.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDKp_CUR[8] = { 2.0F, 2.0F, 0.4F, 0.0F,
  0.0F, 0.0F, 1.5F, 1.5F } ;

CALDATA const volatile float32 cal_AEXVCtrlDOpenVal = 80.0F;
CALDATA const volatile float32 cal_AEXVCtrlDPIMax = 100.0F;
CALDATA const volatile float32 cal_AEXVCtrlDPIMin = 20.0F;
CALDATA const volatile float32 cal_AEXVCtrlDTrg_1X[3] = { 15.0F, 20.0F, 25.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDTrg_CUR[3] = { 8.0F, 10.0F, 12.0F } ;

CALDATA const volatile float32 cal_AEXVCtrlDefPos = 0.0F;
CALDATA const volatile float32 cal_AEXVCtrlDefaultPos = 100.0F;
CALDATA const volatile float32 cal_AEXVDiffDown = 5.0F;
CALDATA const volatile float32 cal_AEXVDiffDownRate = 5.0F;
CALDATA const volatile float32 cal_AEXVDiffUp = 5.0F;
CALDATA const volatile float32 cal_AEXVDiffUpRate = 5.0F;
CALDATA const volatile float32 cal_AEXVDownSpdLmt = 0.5F;
CALDATA const volatile boolean cal_AEXVEnbData = false;
CALDATA const volatile boolean cal_AEXVEnbDataEnb = false;
CALDATA const volatile float32 cal_AEXVFloorDiff1 = 0.2F;
CALDATA const volatile float32 cal_AEXVFloorDiff2 = 0.7F;
CALDATA const volatile float32 cal_AEXVFltClsSpd = 0.5F;
CALDATA const volatile float32 cal_AEXVHighPressLmtOn = 2.2F;
CALDATA const volatile float32 cal_AEXVHighPressProhOn = 2.4F;
CALDATA const volatile uint8 cal_AEXVInitReqData = 0U;
CALDATA const volatile boolean cal_AEXVInitReqDataeEnb = false;
CALDATA const volatile float32 cal_AEXVLowPressLmtOn = 0.16F;
CALDATA const volatile float32 cal_AEXVLowPressProhOn = 0.14F;
CALDATA const volatile float32 cal_AEXVOpenCtrlDownSpdLmt = 2.0F;
CALDATA const volatile float32 cal_AEXVOpenCtrlUpSpdLmt = 2.0F;
CALDATA const volatile float32 cal_AEXVOpenDelayTimeEvapNOPrt = 3.0F;
CALDATA const volatile float32 cal_AEXVOpenEvapNOPrtTemp = 4.0F;
CALDATA const volatile float32 cal_AEXVOpenRunTimeEvapNOPrt = 10.0F;
CALDATA const volatile float32 cal_AEXVOpenValEvapNOPrt = 10.0F;
CALDATA const volatile float32 cal_AEXVOpenValveSpd = 0.2F;
CALDATA const volatile float32 cal_AEXVPosData = 0.0F;
CALDATA const volatile boolean cal_AEXVPosDataEnb = false;
CALDATA const volatile float32 cal_AEXVSubCoolflt = 0.015F;
CALDATA const volatile float32 cal_AEXVUpSpdLmt = 0.5F;
CALDATA const volatile uint8 cal_AQS2InRecThreVal = 60U;
CALDATA const volatile uint8 cal_AQS2OutRecThreVal = 20U;
CALDATA const volatile boolean cal_AcPMPFaultFlgData = false;
CALDATA const volatile boolean cal_AcPMPFaultFlgDataEnb = false;
CALDATA const volatile uint8 cal_AcPMPSpdSetData = 0U;
CALDATA const volatile boolean cal_AcPMPSpdSetDataEnb = false;
CALDATA const volatile uint8 cal_AccmSpdLimByHiPressDownSide_1X[12] = { 0U, 1U,
  2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U } ;

CALDATA const volatile float32 cal_AccmSpdLimByHiPressDownSide_CUR[12] = { 0.0F,
  8000.0F, 8000.0F, 8000.0F, 7000.0F, 6000.0F, 3000.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;

CALDATA const volatile float32 cal_AccmSpdLimByHiPressLevelCalcu_1X[12] = {
  0.25F, 0.26F, 0.27F, 2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.1F, 3.2F, 3.3F } ;

CALDATA const volatile uint8 cal_AccmSpdLimByHiPressLevelCalcu_CUR[12] = { 0U,
  1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U } ;

CALDATA const volatile uint8 cal_AccmSpdLimByHiPressUpSide_1X[12] = { 0U, 1U, 2U,
  3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U } ;

CALDATA const volatile float32 cal_AccmSpdLimByHiPressUpSide_CUR[12] = { 0.0F,
  8000.0F, 8000.0F, 7000.0F, 6000.0F, 3000.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;

CALDATA const volatile uint8 cal_AccmSpdLimByLoPressDownSide_1X[12] = { 0U, 1U,
  2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U } ;

CALDATA const volatile float32 cal_AccmSpdLimByLoPressDownSide_CUR[12] = { 0.0F,
  0.0F, 0.0F, 1000.0F, 1000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F,
  8000.0F, 8000.0F } ;

CALDATA const volatile float32 cal_AccmSpdLimByLoPressLevelCalcu_1X[12] = {
  0.04F, 0.06F, 0.08F, 0.1F, 0.12F, 0.14F, 0.16F, 0.18F, 0.2F, 0.3F, 0.4F, 0.5F
} ;

CALDATA const volatile uint8 cal_AccmSpdLimByLoPressLevelCalcu_CUR[12] = { 0U,
  1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U } ;

CALDATA const volatile uint8 cal_AccmSpdLimByLoPressUpSide_1X[12] = { 0U, 1U, 2U,
  3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U } ;

CALDATA const volatile float32 cal_AccmSpdLimByLoPressUpSide_CUR[12] = { 0.0F,
  0.0F, 1000.0F, 1000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F,
  8000.0F, 8000.0F } ;

CALDATA const volatile uint8 cal_AirInletPerData = 0U;
CALDATA const volatile boolean cal_AirInletPerEnb = false;
CALDATA const volatile float32 cal_AirInletRecInPCUTemp = 60.0F;
CALDATA const volatile float32 cal_AirInletRecOutPCUTemp = 50.0F;
CALDATA const volatile boolean cal_AutoDefogEnable = false;
CALDATA const volatile boolean cal_AvgSwitch = false;
CALDATA const volatile uint8 cal_BATPMPSpdDiffVal = 10U;
CALDATA const volatile uint8 cal_BCVFltStsDelayTime = 3U;
CALDATA const volatile float32 cal_BCVPosDiffDelayTime = 0.5F;
CALDATA const volatile uint16 cal_BCVPosDiffMaxVal = 2U;
CALDATA const volatile float32 cal_BEXVCtlKi = 0.0F;
CALDATA const volatile float32 cal_BEXVCtlKisumMax = 50.0F;
CALDATA const volatile float32 cal_BEXVCtlKisumMin = -50.0F;
CALDATA const volatile float32 cal_BEXVCtlKp = 0.0F;
CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_1X[6] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBDCoolPIMin_CUR[6] = { 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBDeadzone = 0.5F;
CALDATA const volatile float32 cal_BEXVCtrlBDelayTime = 10.0F;
CALDATA const volatile float32 cal_BEXVCtrlBFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBFF_CUR[5] = { 30.0F, 30.0F, 25.0F,
  25.0F, 25.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBKi_1X[7] = { -10.0F, -6.0F, -3.0F,
  -2.0F, 2.0F, 4.0F, 10.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBKi_CUR[7] = { 0.02F, 0.02F, 0.01F,
  0.0F, 0.0F, 0.01F, 0.01F } ;

CALDATA const volatile float32 cal_BEXVCtrlBKp_1X[7] = { -10.0F, -6.0F, -4.0F,
  -2.0F, 2.0F, 4.0F, 10.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBKp_CUR[7] = { 1.5F, 1.0F, 0.5F, 0.1F,
  0.1F, 0.4F, 1.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBOpenVal = 60.0F;
CALDATA const volatile float32 cal_BEXVCtrlBPIDown = 10.0F;
CALDATA const volatile float32 cal_BEXVCtrlBPIUp = 100.0F;
CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_1X[5] = { -6.0F, -3.0F,
  0.0F, 3.0F, 6.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBTrgCabinComp_CUR[5] = { -5.0F, -3.0F,
  0.0F, 2.0F, 4.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_1X[6] = { -3.0F,
  -1.0F, 0.0F, 1.0F, 3.0F, 5.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlBTrgWtrTempDiff_CUR[6] = { 15.0F,
  12.0F, 8.0F, 8.0F, 5.0F, 5.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_1X[6] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCBatCoolPIMin_CUR[6] = { 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCDeadzone = 0.5F;
CALDATA const volatile float32 cal_BEXVCtrlCDelayTime = 10.0F;
CALDATA const volatile float32 cal_BEXVCtrlCFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCFF_CUR[5] = { 30.0F, 30.0F, 25.0F,
  25.0F, 25.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCKi_1X[8] = { -10.0F, -6.0F, -3.0F,
  -2.0F, 2.0F, 4.0F, 6.0F, 10.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCKi_CUR[8] = { 0.002F, 0.001F, 0.001F,
  0.0F, 0.0F, 0.001F, 0.001F, 0.001F } ;

CALDATA const volatile float32 cal_BEXVCtrlCKp_1X[8] = { -10.0F, -6.0F, -4.0F,
  -2.0F, 2.0F, 4.0F, 6.0F, 10.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCKp_CUR[8] = { 1.5F, 1.0F, 0.5F, 0.1F,
  0.1F, 0.4F, 0.5F, 0.5F } ;

CALDATA const volatile float32 cal_BEXVCtrlCOpenVal = 60.0F;
CALDATA const volatile float32 cal_BEXVCtrlCPIMax = 100.0F;
CALDATA const volatile float32 cal_BEXVCtrlCPIMin = 10.0F;
CALDATA const volatile float32 cal_BEXVCtrlCTrg_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlCTrg_CUR[5] = { 8.0F, 8.0F, 8.0F,
  8.0F, 8.0F } ;

CALDATA const volatile float32 cal_BEXVCtrlDefPos = 0.0F;
CALDATA const volatile float32 cal_BEXVDiffDown = 5.0F;
CALDATA const volatile float32 cal_BEXVDiffDownRate = 5.0F;
CALDATA const volatile float32 cal_BEXVDiffUp = 5.0F;
CALDATA const volatile float32 cal_BEXVDiffUpRate = 5.0F;
CALDATA const volatile float32 cal_BEXVDownSpdLmt = 0.5F;
CALDATA const volatile boolean cal_BEXVEnbData = false;
CALDATA const volatile boolean cal_BEXVEnbDataEnb = false;
CALDATA const volatile float32 cal_BEXVFloorDiff1 = 0.2F;
CALDATA const volatile float32 cal_BEXVFloorDiff2 = 0.7F;
CALDATA const volatile float32 cal_BEXVHighPressLmtOn = 2.2F;
CALDATA const volatile float32 cal_BEXVHighPressProhOn = 2.4F;
CALDATA const volatile uint8 cal_BEXVInitReqData = 0U;
CALDATA const volatile boolean cal_BEXVInitReqDataeEnb = false;
CALDATA const volatile float32 cal_BEXVLowPressLmtOn = 0.16F;
CALDATA const volatile float32 cal_BEXVLowPressProhOn = 0.14F;
CALDATA const volatile float32 cal_BEXVOpenCtrlDownSpdLmt = 2.0F;
CALDATA const volatile float32 cal_BEXVOpenCtrlUpSpdLmt = 2.0F;
CALDATA const volatile float32 cal_BEXVOpenValveSpd = 0.2F;
CALDATA const volatile float32 cal_BEXVPosData = 0.0F;
CALDATA const volatile boolean cal_BEXVPosDataEnb = false;
CALDATA const volatile float32 cal_BEXVSubCoolflt = 0.015F;
CALDATA const volatile float32 cal_BEXVSubHeatflt = 0.045F;
CALDATA const volatile float32 cal_BEXVUpSpdLmt = 0.5F;
CALDATA const volatile float32 cal_BMSInletTempHighOffMCV = 47.0F;
CALDATA const volatile float32 cal_BMSInletTempLowOnMCV = 43.0F;
CALDATA const volatile float32 cal_BatBalCellTemp1 = 20.0F;
CALDATA const volatile float32 cal_BatBalCellTemp2 = 30.0F;
CALDATA const volatile float32 cal_BatCoolInletTrgTemp = 18.0F;
CALDATA const volatile boolean cal_BatCoolOverData = false;
CALDATA const volatile boolean cal_BatCoolOverEnb = false;
CALDATA const volatile uint16 cal_BatCoolStopBatPMPRunTime = 10U;
CALDATA const volatile uint8 cal_BatCoolStopBatPMPSpd = 30U;
CALDATA const volatile float32 cal_BatCoolTrgFilter = 0.015F;
CALDATA const volatile boolean cal_BatHeatACCMEnb = false;
CALDATA const volatile boolean cal_BatHeatOverData = false;
CALDATA const volatile boolean cal_BatHeatOverEnb = false;
CALDATA const volatile float32 cal_BatHeatPwrLoLmt = 0.5F;
CALDATA const volatile float32 cal_BatHeatTrgTemp = 45.0F;
CALDATA const volatile float32 cal_BatHeatTrgTempComp_1X[11] = { -5.0F, -4.0F,
  -3.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F } ;

CALDATA const volatile float32 cal_BatHeatTrgTempComp_CUR[11] = { 20.0F, 18.0F,
  16.0F, 14.0F, 10.0F, 6.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile BatModes cal_BatModeData = Off;
CALDATA const volatile boolean cal_BatModeEnb = false;
CALDATA const volatile boolean cal_BatModeTestCtrl = false;
CALDATA const volatile uint8 cal_BatPMPBatHeatSpd = 80U;
CALDATA const volatile boolean cal_BatPMPFaultFlgData = false;
CALDATA const volatile boolean cal_BatPMPFaultFlgDataEnb = false;
CALDATA const volatile uint8 cal_BatPMPSpdSetData = 0U;
CALDATA const volatile boolean cal_BatPMPSpdSetDataEnb = false;
CALDATA const volatile float32 cal_BatPumpB1Off_1X[4] = { 2.0F, 5.0F, 10.0F,
  15.0F } ;

CALDATA const volatile uint8 cal_BatPumpB1Off_CUR[4] = { 22U, 60U, 80U, 80U } ;

CALDATA const volatile float32 cal_BatPumpBal_1X[4] = { 2.0F, 5.0F, 10.0F, 15.0F
} ;

CALDATA const volatile uint8 cal_BatPumpBal_CUR[4] = { 22U, 60U, 80U, 80U } ;

CALDATA const volatile uint8 cal_BatPumpCtrlASpd = 80U;
CALDATA const volatile float32 cal_BatPumpLTR_1X[4] = { 2.0F, 5.0F, 10.0F, 15.0F
} ;

CALDATA const volatile uint8 cal_BatPumpLTR_CUR[4] = { 22U, 60U, 80U, 80U } ;

CALDATA const volatile uint8 cal_BatPumpMotHeatBatSpd = 100U;
CALDATA const volatile uint8 cal_BatPumpMotLTRAndBatCHSpd = 100U;
CALDATA const volatile float32 cal_BatPumpThSto_1X[4] = { 2.0F, 5.0F, 10.0F,
  15.0F } ;

CALDATA const volatile uint8 cal_BatPumpThSto_CUR[4] = { 22U, 60U, 80U, 80U } ;

CALDATA const volatile float32 cal_BatTrgTempData = 0.0F;
CALDATA const volatile boolean cal_BatTrgTempEnb = false;
CALDATA const volatile float32 cal_BetwT1AndT2DownMCV_1X[6] = { -6.0F, -4.0F,
  -2.0F, 0.0F, 2.0F, 4.0F } ;

CALDATA const volatile uint8 cal_BetwT1AndT2DownMCV_CUR[6] = { 12U, 12U, 8U, 8U,
  5U, 5U } ;

CALDATA const volatile float32 cal_BetwT1AndT2StbyMCV_1X[6] = { -5.0F, -3.0F,
  -1.0F, 1.0F, 3.0F, 5.0F } ;

CALDATA const volatile uint8 cal_BetwT1AndT2StbyMCV_CUR[6] = { 12U, 12U, 12U, 8U,
  8U, 8U } ;

CALDATA const volatile float32 cal_BetwT1AndT2UpMCV_1X[6] = { -4.0F, -2.0F, 0.0F,
  2.0F, 4.0F, 6.0F } ;

CALDATA const volatile uint8 cal_BetwT1AndT2UpMCV_CUR[6] = { 12U, 12U, 8U, 8U,
  5U, 5U } ;

CALDATA const volatile float32 cal_BlowerFanEnvLmtTmpOff = -13.0F;
CALDATA const volatile float32 cal_BlowerFanEnvLmtTmpOn = -15.0F;
CALDATA const volatile uint8 cal_BlowerFanMaxLowTmp = 59U;
CALDATA const volatile uint8 cal_BlowerFanMaxNormal = 73U;
CALDATA const volatile uint8 cal_BlowerFanSpdLL = 0U;
CALDATA const volatile uint8 cal_BlowerFanSpdVentUL = 78U;
CALDATA const volatile uint8 cal_BlwFanData = 0U;
CALDATA const volatile boolean cal_BlwFanEnb = false;
CALDATA const volatile uint16 cal_BlwFrqVal = 1000U;
CALDATA const volatile uint8 cal_C3WVExhPosVal = 10U;
CALDATA const volatile uint8 cal_C3WVSLStsData = 0U;
CALDATA const volatile boolean cal_C3WVSLStsDataEnb = false;
CALDATA const volatile uint8 cal_C5WVExhPosVal = 12U;
CALDATA const volatile uint8 cal_C5WVSLStsData = 0U;
CALDATA const volatile boolean cal_C5WVSLStsDataEnb = false;
CALDATA const volatile boolean cal_CANAliveEnable = true;
CALDATA const volatile sint16 cal_CAPStartCoolantMin = 35;
CALDATA const volatile uint8 cal_CO2RecircRatio = 40U;
CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_1X[8] = { 20.0F, 21.0F,
  30.0F, 31.0F, 35.0F, 36.0F, 40.0F, 41.0F } ;

CALDATA const volatile float32 cal_COMPATNoiseSpdLmtHVS_CUR[8] = { 4000.0F,
  4000.0F, 5000.0F, 5000.0F, 6000.0F, 6000.0F, 8000.0F, 8000.0F } ;

CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_2X[10] = { 0.0F, 4300.0F,
  4301.0F, 4600.0F, 4601.0F, 5000.0F, 5001.0F, 6000.0F, 6001.0F, 8000.0F } ;

CALDATA const volatile uint8 cal_COMPATNoiseSpdLmt_2Y[10] = { 0U, 24U, 30U, 36U,
  42U, 48U, 54U, 60U, 68U, 100U } ;

CALDATA const volatile float32 cal_COMPATNoiseSpdLmt_MAP[100] = { 800.0F, 800.0F,
  800.0F, 800.0F, 800.0F, 800.0F, 800.0F, 800.0F, 800.0F, 800.0F, 2200.0F,
  2200.0F, 2200.0F, 2200.0F, 2200.0F, 2200.0F, 2200.0F, 2200.0F, 2200.0F,
  2200.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F,
  2400.0F, 2400.0F, 2400.0F, 3200.0F, 3200.0F, 3200.0F, 3200.0F, 3200.0F,
  3200.0F, 3200.0F, 3200.0F, 3200.0F, 3200.0F, 3800.0F, 3800.0F, 3800.0F,
  3800.0F, 3800.0F, 3800.0F, 3800.0F, 3800.0F, 3800.0F, 3800.0F, 4300.0F,
  4300.0F, 4300.0F, 4300.0F, 5000.0F, 5000.0F, 5000.0F, 5000.0F, 8000.0F,
  8000.0F, 4300.0F, 4300.0F, 4300.0F, 4300.0F, 5000.0F, 5000.0F, 5000.0F,
  5000.0F, 8000.0F, 8000.0F, 4300.0F, 4300.0F, 4300.0F, 4300.0F, 5000.0F,
  5000.0F, 5000.0F, 5000.0F, 8000.0F, 8000.0F, 4300.0F, 4300.0F, 4300.0F,
  4300.0F, 5000.0F, 5000.0F, 5000.0F, 5000.0F, 8000.0F, 8000.0F, 4300.0F,
  4300.0F, 4300.0F, 4300.0F, 5000.0F, 5000.0F, 5000.0F, 5000.0F, 8000.0F,
  8000.0F } ;

CALDATA const volatile float32 cal_COMPActlSpd1 = 800.0F;
CALDATA const volatile float32 cal_COMPActlSpd2 = 1200.0F;
CALDATA const volatile float32 cal_COMPActlSpd3 = 2000.0F;
CALDATA const volatile float32 cal_COMPBatMaxSpdLmt = 4000.0F;
CALDATA const volatile float32 cal_COMPCabinCoolMaxSpdLmt = 6000.0F;
CALDATA const volatile float32 cal_COMPClosePwrMaxLmt = 1.0F;
CALDATA const volatile float32 cal_COMPClsLowSpeed = 800.0F;
CALDATA const volatile float32 cal_COMPCoolLowSpd = 20.0F;
CALDATA const volatile float32 cal_COMPEnvSpdLmt1_1X[2] = { 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt1_CUR[2] = { 4000.0F, 5000.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt2_1X[2] = { 30.0F, 35.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt2_CUR[2] = { 5000.0F, 6000.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt3_1X[2] = { 35.0F, 40.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt3_CUR[2] = { 6000.0F, 8000.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt4_1X[2] = { 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmt4_CUR[2] = { 4000.0F, 5000.0F } ;

CALDATA const volatile float32 cal_COMPEnvSpdLmtDef = 4000.0F;
CALDATA const volatile float32 cal_COMPEvapTFrbVal = -1.0F;
CALDATA const volatile float32 cal_COMPEvapTNmlVal = 4.0F;
CALDATA const volatile float32 cal_COMPExhTDownSpd = 150.0F;
CALDATA const volatile float32 cal_COMPExhTFrbVal = 125.0F;
CALDATA const volatile float32 cal_COMPExhTLmtRlybVal = 120.0F;
CALDATA const volatile float32 cal_COMPExhTLmtVal = 115.0F;
CALDATA const volatile float32 cal_COMPExhTNmlVal = 110.0F;
CALDATA const volatile uint8 cal_COMPFanLevelLmt_1X[9] = { 0U, 1U, 2U, 3U, 4U,
  5U, 6U, 7U, 8U } ;

CALDATA const volatile float32 cal_COMPFanLevelLmt_CUR[9] = { 0.0F, 1500.0F,
  2000.0F, 3000.0F, 3500.0F, 4000.0F, 5500.0F, 5500.0F, 6000.0F } ;

CALDATA const volatile uint8 cal_COMPFanSpdLmt[3] = { 40U, 50U, 60U } ;

CALDATA const volatile float32 cal_COMPNoPTCLmtSpd = 4000.0F;
CALDATA const volatile float32 cal_COMPONMinSpd = 1000.0F;
CALDATA const volatile float32 cal_COMPOffMaxSpd = 750.0F;
CALDATA const volatile float32 cal_COMPPwrMaxLmt = 10.0F;
CALDATA const volatile float32 cal_COMPSpdDiffDown = 1000.0F;
CALDATA const volatile float32 cal_COMPSpdDiffDownRate = 60.0F;
CALDATA const volatile float32 cal_COMPSpdDiffUp = 1000.0F;
CALDATA const volatile float32 cal_COMPSpdDiffUpRate = 60.0F;
CALDATA const volatile float32 cal_COMPSpdLmt[4] = { 1200.0F, 2500.0F, 4000.0F,
  5000.0F } ;

CALDATA const volatile float32 cal_COMPSpdOilBackVal = 2500.0F;
CALDATA const volatile float32 cal_COMPStartPwrMinLmt = 2.0F;
CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos1 = 80.0F;
CALDATA const volatile float32 cal_CabinCondToCoolHPEXVPos2 = 20.0F;
CALDATA const volatile float32 cal_CabinCondToEvpHPEXVPos = 6.0F;
CALDATA const volatile uint16 cal_CabinDesTempSolarCorECO_2X[14] = { 100U, 150U,
  200U, 300U, 400U, 450U, 500U, 550U, 600U, 700U, 800U, 900U, 1000U, 1200U } ;

CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_2Y[14] = { -25.0F,
  -20.0F, -15.0F, -10.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F } ;

CALDATA const volatile float32 cal_CabinDesTempSolarCorECO_MAP[196] = { 0.0F,
  2.0F, 2.0F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -2.0F, -2.0F,
  0.0F, 2.0F, 2.0F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, -2.0F,
  -2.0F, 0.0F, 2.0F, 2.0F, 1.5F, 1.5F, 1.5F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  -2.0F, -2.0F, 0.0F, 1.0F, 1.0F, 0.5F, 0.5F, 0.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, -1.0F, -1.0F, 0.0F, -1.0F, -1.0F, -1.5F, -1.5F, -1.5F, -2.0F, -2.0F,
  -2.0F, -2.0F, -2.0F, -2.0F, -3.0F, -3.0F, 0.0F, 0.0F, 0.0F, -0.5F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.5F, -1.5F, -1.5F, -1.5F, -1.5F, 0.0F, 0.0F,
  0.0F, -0.5F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -2.0F, -2.0F, -2.0F, -2.0F,
  -2.0F, 0.0F, -0.5F, -0.5F, -1.0F, -1.0F, -1.0F, -1.5F, -1.5F, -1.5F, -2.0F,
  -2.0F, -2.0F, -2.0F, -2.0F, 0.0F, -0.5F, -0.5F, -0.5F, -1.0F, -1.0F, -2.0F,
  -2.0F, -2.0F, -2.0F, -2.0F, -2.0F, -2.5F, -2.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
;

CALDATA const volatile uint16 cal_CabinDesTempSolarCor_2X[14] = { 100U, 150U,
  200U, 300U, 400U, 450U, 500U, 550U, 600U, 700U, 800U, 900U, 1000U, 1200U } ;

CALDATA const volatile float32 cal_CabinDesTempSolarCor_2Y[14] = { -25.0F,
  -20.0F, -15.0F, -10.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F } ;

CALDATA const volatile float32 cal_CabinDesTempSolarCor_MAP[196] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint16 cal_CabinEvpToCondCompLmt = 850U;
CALDATA const volatile float32 cal_CabinEvpToHPEnvTemp = 5.0F;
CALDATA const volatile float32 cal_CabinHys1TempOffset = 1.0F;
CALDATA const volatile float32 cal_CabinHys2TempOffset = 3.0F;
CALDATA const volatile float32 cal_CabinMD2F2MaxEnvTemp = 30.0F;
CALDATA const volatile CabinMode cal_CabinModeData = CabinMode_MD_Off;
CALDATA const volatile boolean cal_CabinModeEnb = false;
CALDATA const volatile float32 cal_CabinModeKeepStandbyTime = 0.2F;
CALDATA const volatile float32 cal_CabinModeTransF1Constant = 1.0F;
CALDATA const volatile float32 cal_CabinModeTransF1Slope = 1.2F;
CALDATA const volatile float32 cal_CabinModeTransF2Constant = 10.5F;
CALDATA const volatile float32 cal_CabinModeTransF2Slope = 1.3F;
CALDATA const volatile boolean cal_CabinSetPTCSwitch = true;
CALDATA const volatile uint8 cal_CabinTCorSelect = 0U;
CALDATA const volatile float32 cal_CabinTempData = 24.0F;
CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_1X[10] = { -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 2.0F, 8.0F, 15.0F, 20.0F, 25.0F } ;

CALDATA const volatile float32 cal_CabinTempDuctUpStepCor_CUR[10] = { -1.0F,
  -0.799987793F, -0.5F, -0.2F, 0.0F, 0.2F, 0.4F, 0.8F, 0.9F, 1.0F } ;

CALDATA const volatile boolean cal_CabinTempEnb = false;
CALDATA const volatile uint16 cal_CabinVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_CabinVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile boolean cal_CallDrvierCtlSwitch = false;
CALDATA const volatile float32 cal_ChiTempData = 0.0F;
CALDATA const volatile boolean cal_ChiTempDataEnb = false;
CALDATA const volatile uint16 cal_ChillTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_ChillTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_ClsCoolInletTemp = 15.0F;
CALDATA const volatile float32 cal_ClsCoolInletTempTime = 15.0F;
CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_1X[15] = { -13.0F, -12.0F,
  -11.0F, -10.0F, -9.0F, -8.0F, -7.0F, -6.0F, -5.0F, -4.5F, 10.0F, 10.5F, 25.0F,
  25.5F, 35.0F } ;

CALDATA const volatile float32 cal_ColdPCUTempMinByEnv_CUR[15] = { 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 25.0F, 25.0F, 35.0F,
  35.0F, 40.0F } ;

CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_1X[7] = { -5.0F,
  -4.5F, 10.0F, 10.5F, 25.0F, 25.5F, 30.0F } ;

CALDATA const volatile float32 cal_ColdStartPCUTempMinByEnv_CUR[7] = { 10.0F,
  10.0F, 25.0F, 25.0F, 35.0F, 35.0F, 35.0F } ;

CALDATA const volatile float32 cal_CondDepFilter = 0.9F;
CALDATA const volatile float32 cal_CondDep_1X[28] = { 0.029451F, 0.039117F,
  0.051209F, 0.066144F, 0.084378F, 0.1064F, 0.13273F, 0.16394F, 0.2006F,
  0.24334F, 0.2928F, 0.34966F, 0.41461F, 0.48837F, 0.57171F, 0.66538F, 0.7702F,
  0.88698F, 1.0166F, 1.1599F, 1.3179F, 1.4915F, 1.6818F, 2.1168F, 2.6332F,
  3.2442F, 3.9724F, 4.0541F } ;

CALDATA const volatile float32 cal_CondDep_CUR[28] = { -50.0F, -45.0F, -40.0F,
  -35.0F, -30.0F, -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 70.0F,
  80.0F, 90.0F, 100.0F, 101.0F } ;

CALDATA const volatile float32 cal_CoolFanCtrl_2X[4] = { 0.0F, 40.0F, 80.0F,
  120.0F } ;

CALDATA const volatile float32 cal_CoolFanCtrl_2Y[13] = { 0.0F, 0.8F, 0.9F, 1.0F,
  1.1F, 1.2F, 1.3F, 1.4F, 1.5F, 1.6F, 1.7F, 1.8F, 1.9F } ;

CALDATA const volatile uint8 cal_CoolFanCtrl_MAP[52] = { 16U, 16U, 16U, 16U, 16U,
  16U, 16U, 16U, 40U, 40U, 40U, 40U, 40U, 40U, 40U, 40U, 50U, 50U, 50U, 50U, 50U,
  50U, 50U, 50U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 60U, 70U,
  70U, 70U, 70U, 70U, 70U, 70U, 70U, 84U, 84U, 84U, 84U, 84U, 84U, 84U, 84U } ;

CALDATA const volatile uint8 cal_CoolFanData = 0U;
CALDATA const volatile boolean cal_CoolFanEnb = false;
CALDATA const volatile float32 cal_CoolStartCompensate = 10.0F;
CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2X[6] = { 16.0F, 20.0F,
  24.0F, 28.0F, 31.0F, 32.0F } ;

CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_2Y[6] = { 0.0F, 1.0F,
  3.0F, 6.0F, 9.0F, 10.0F } ;

CALDATA const volatile float32 cal_CtrlFPTCAuxHeatPwrLmt_MAP[36] = { 0.0F, 0.0F,
  1.0F, 2.0F, 3.0F, 8.0F, 0.0F, 1.0F, 2.0F, 3.0F, 5.0F, 8.0F, 0.0F, 2.0F, 4.0F,
  5.0F, 6.0F, 8.0F, 0.0F, 2.0F, 5.0F, 5.0F, 6.0F, 8.0F, 0.0F, 3.0F, 6.0F, 6.0F,
  7.0F, 8.0F, 0.0F, 3.0F, 8.0F, 8.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_CtrlFPTCOffPowerVal = 0.5F;
CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_1X[6] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F } ;

CALDATA const volatile float32 cal_CtrlFPTCOnReqPower_CUR[6] = { 0.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F } ;

CALDATA const volatile float32 cal_DCBatHeatEnvTemp[2] = { 0.0F, 15.0F } ;

CALDATA const volatile float32 cal_DCBatHeatT1[3] = { 10.0F, 15.0F, 20.0F } ;

CALDATA const volatile float32 cal_DCBatHeatT2[3] = { 25.0F, 25.0F, 25.0F } ;

CALDATA const volatile float32 cal_DCBatHeatTave[3] = { 20.0F, 25.0F, 30.0F } ;

CALDATA const volatile float32 cal_DCBatHeatTrgTemp = 45.0F;
CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_1X[7] = { -40.0F, -20.0F,
  -10.0F, 0.0F, 10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_DCChrgBatHeatTrgTemp_CUR[7] = { 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F } ;

CALDATA const volatile float32 cal_DLTRBatInlet2MaxTempDiff = 0.0F;
CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_1X[5] = { -10.0F, 0.0F,
  10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_DLTRBatMaxEntTempB_CUR[5] = { 33.0F, 34.0F,
  35.0F, 36.0F, 38.0F } ;

CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_1X[5] = { -10.0F, 0.0F,
  10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_DLTRDCBatMaxEntTempB_CUR[5] = { 32.0F, 32.0F,
  32.0F, 32.0F, 32.0F } ;

CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_1X[5] = { -10.0F, 0.0F,
  10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_DLTRDCBatMaxExitTempB_CUR[5] = { 35.0F, 35.0F,
  35.0F, 35.0F, 35.0F } ;

CALDATA const volatile float32 cal_DLTRIPUTempExitVal = 55.0F;
CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_1X[5] = { -10.0F,
  0.0F, 10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_DLTRNotDCBatMaxExitTempC_CUR[5] = { 35.0F,
  35.0F, 35.0F, 35.0F, 35.0F } ;

CALDATA const volatile float32 cal_DcutTPidDeadBand = 1.5F;
CALDATA const volatile float32 cal_DcutTempPidLL = -10.0F;
CALDATA const volatile float32 cal_DcutTempPidUL = 80.0F;
CALDATA const volatile float32 cal_DcutTempPid_IsumMax = 80.0F;
CALDATA const volatile float32 cal_DcutTempPid_IsumMin = -80.0F;
CALDATA const volatile float32 cal_DcutTempPid_Ki = 0.0F;
CALDATA const volatile float32 cal_DcutTempPid_KiNeg = 0.015F;
CALDATA const volatile float32 cal_DcutTempPid_KiPos = 0.015F;
CALDATA const volatile float32 cal_DcutTempPid_Kp = 2.0F;
CALDATA const volatile float32 cal_DcutTempPid_KpNeg = 2.0F;
CALDATA const volatile float32 cal_DcutTempPid_KpPos = 2.0F;
CALDATA const volatile float32 cal_DcutTempPid_pWinNeg = 80.0F;
CALDATA const volatile float32 cal_DcutTempPid_pWinPos = 80.0F;
CALDATA const volatile float32 cal_DefaultSetTemp = 24.0F;
CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_1X[7] = { -40.0F,
  -20.0F, -10.0F, 0.0F, 10.0F, 20.0F, 30.0F } ;

CALDATA const volatile float32 cal_DisChrgBatHeatTrgTemp_CUR[7] = { 60.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F } ;

CALDATA const volatile float32 cal_DrDuctFaceFloorFaFactor = 0.6F;
CALDATA const volatile float32 cal_DrDuctFaceFloorFoFactor = 0.4F;
CALDATA const volatile float32 cal_DrDuctSenFailDeflt = 25.0F;
CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOff = 0.0F;
CALDATA const volatile float32 cal_DrErrOfEvaDVT2CoolMixOn = 6.0F;
CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOff = 0.0F;
CALDATA const volatile float32 cal_DrErrOfPtcDVT2HeatMixOn = 6.0F;
CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandNeg = 2.0F;
CALDATA const volatile float32 cal_DrEvaDesValPIDIntegDeadBandPos = 2.0F;
CALDATA const volatile float32 cal_DrEvaDesValPIDKi = 0.0F;
CALDATA const volatile float32 cal_DrEvaDesValPIDKiNeg = 0.002F;
CALDATA const volatile float32 cal_DrEvaDesValPIDKiPos = 0.002F;
CALDATA const volatile float32 cal_DrEvaDesValPIDKp = 0.3F;
CALDATA const volatile float32 cal_DrEvaDesValPIDKpNeg = 0.6F;
CALDATA const volatile float32 cal_DrEvaDesValPIDKpPos = 1.0F;
CALDATA const volatile float32 cal_DrEvaDesValPIDLL = 2.5F;
CALDATA const volatile uint8 cal_DrEvaDesValPIDLL_2X[4] = { 0U, 3U, 5U, 8U } ;

CALDATA const volatile float32 cal_DrEvaDesValPIDLL_2Y[7] = { 16.0F, 20.0F,
  22.0F, 24.0F, 26.0F, 28.0F, 30.0F } ;

CALDATA const volatile float32 cal_DrEvaDesValPIDLL_MAP[28] = { 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F } ;

CALDATA const volatile float32 cal_DrEvaDesValPIDUL = 25.0F;
CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMax = 5.0F;
CALDATA const volatile float32 cal_DrEvaDesValPID_IsumMin = -5.0F;
CALDATA const volatile float32 cal_DrEvaDesValPID_pWinNeg = 1.0F;
CALDATA const volatile float32 cal_DrEvaDesValPID_pWinPos = 1.0F;
CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_1X[4] = { 0.0F, 2.0F,
  3.0F, 4.0F } ;

CALDATA const volatile float32 cal_DrEvapDesFilterByDvt_CUR[4] = { 0.19921875F,
  0.3984375F, 0.6015625F, 1.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetDefog_1X[8] = { 13.0F, 18.0F,
  25.0F, 43.0F, 45.0F, 47.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetDefog_CUR[8] = { 20.0F, 30.0F,
  40.0F, 60.0F, 80.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_1X[8] = { 13.0F, 18.0F,
  25.0F, 43.0F, 45.0F, 47.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetFaceHeater_CUR[8] = { 20.0F, 30.0F,
  40.0F, 60.0F, 80.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetFace_1X[8] = { 13.0F, 18.0F, 25.0F,
  43.0F, 45.0F, 47.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetFace_CUR[8] = { 20.0F, 30.0F,
  40.0F, 60.0F, 80.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_1X[8] = { 13.0F,
  18.0F, 25.0F, 43.0F, 45.0F, 47.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetHeaterDeforst_CUR[8] = { 20.0F,
  30.0F, 40.0F, 60.0F, 80.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetHeater_1X[8] = { 13.0F, 18.0F,
  25.0F, 43.0F, 45.0F, 47.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_DrMixBacSetHeater_CUR[8] = { 20.0F, 30.0F,
  40.0F, 60.0F, 80.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_DrMixDesValPIDIntegDeadBand = 3.0F;
CALDATA const volatile uint8 cal_DrMixDesValPIDLL = 0U;
CALDATA const volatile uint8 cal_DrMixDesValPIDUL = 100U;
CALDATA const volatile float32 cal_DrMixDesValPID_IsumMax = 30.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_IsumMin = -30.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_Ki = 0.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_KiNeg = 0.05F;
CALDATA const volatile float32 cal_DrMixDesValPID_KiPos = 0.05F;
CALDATA const volatile float32 cal_DrMixDesValPID_Kp = 1.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_KpNeg = 2.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_KpPos = 2.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_pWinNeg = 3.0F;
CALDATA const volatile float32 cal_DrMixDesValPID_pWinPos = 3.0F;
CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4InHeat = 2.0F;
CALDATA const volatile float32 cal_DrPtcDesValPIDIntegDeadBand4OutHeat = 2.0F;
CALDATA const volatile float32 cal_DrPtcDesValPIDKi = 0.0F;
CALDATA const volatile float32 cal_DrPtcDesValPIDKiNeg = 0.005F;
CALDATA const volatile float32 cal_DrPtcDesValPIDKiPos = 0.004F;
CALDATA const volatile float32 cal_DrPtcDesValPIDKp = 0.5F;
CALDATA const volatile float32 cal_DrPtcDesValPIDKpNeg = 1.0F;
CALDATA const volatile float32 cal_DrPtcDesValPIDKpPos = 1.5F;
CALDATA const volatile float32 cal_DrPtcDesValPIDLL = 0.0F;
CALDATA const volatile float32 cal_DrPtcDesValPIDUL = 60.0F;
CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMax = 20.0F;
CALDATA const volatile float32 cal_DrPtcDesValPID_IsumMin = -20.0F;
CALDATA const volatile float32 cal_DrPtcDesValPID_pWinNeg = 2.0F;
CALDATA const volatile float32 cal_DrPtcDesValPID_pWinPos = 2.0F;
CALDATA const volatile float32 cal_DvtCoff = 0.9F;
CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_1X[8] = { 0.5F,
  1.0F, 2.0F, 3.0F, 5.0F, 8.0F, 12.0F, 18.0F } ;

CALDATA const volatile float32 cal_DvtDesIsumMaxByCabinTDiff_CUR[8] = { 0.5F,
  1.0F, 2.0F, 5.0F, 9.0F, 13.0F, 18.0F, 23.0F } ;

CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_1X[8] = { 0.5F,
  1.0F, 1.5F, 3.0F, 4.5F, 6.0F, 8.0F, 10.0F } ;

CALDATA const volatile float32 cal_DvtDesIsumMinByCabinTDiff_CUR[8] = { -0.5F,
  -1.0F, -1.0F, -2.0F, -4.0F, -6.0F, -10.0F, -15.0F } ;

CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2X[10] = { 0.0F, 2.0F,
  4.0F, 6.0F, 8.0F, 10.0F, 15.0F, 20.0F, 30.0F, 45.0F } ;

CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_2Y[10] = { -40.0F,
  -35.0F, -30.0F, -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F } ;

CALDATA const volatile float32 cal_DvtDesLmtByCabinTDiff_MAP[100] = { 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 63.0F, 63.0F, 70.0F, 75.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 63.0F, 63.0F, 70.0F, 75.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 57.0F, 57.0F, 60.0F, 72.0F, 80.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 57.0F, 57.0F, 60.0F, 72.0F, 80.0F, 80.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F,
  80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F, 80.0F } ;

CALDATA const volatile float32 cal_DvtDesValPIDIntegDeadBand = 2.0F;
CALDATA const volatile float32 cal_DvtDesValPIDKi_1X[9] = { -15.0F, -10.0F,
  -3.0F, -1.5F, 0.0F, 1.5F, 3.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_DvtDesValPIDKi_CUR[9] = { 0.001F, 0.001F,
  0.001F, 0.0F, 0.0F, 0.0F, 0.001F, 0.002F, 0.002F } ;

CALDATA const volatile float32 cal_DvtDesValPIDKp_1X[9] = { -15.0F, -10.0F,
  -3.0F, -1.5F, 0.0F, 1.5F, 3.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_DvtDesValPIDKp_CUR[9] = { 1.5F, 1.2F, 0.6F,
  0.0F, 0.0F, 0.0F, 0.8F, 1.5F, 2.0F } ;

CALDATA const volatile float32 cal_DvtDesValPID_Ki = 0.0F;
CALDATA const volatile float32 cal_DvtDesValPID_Kp = 0.5F;
CALDATA const volatile float32 cal_DvtDesValPID_LL = 2.5F;
CALDATA const volatile float32 cal_DvtDesValPID_UL = 60.0F;
CALDATA const volatile float32 cal_DvtDesValPID_pWinNeg = 1.0F;
CALDATA const volatile float32 cal_DvtDesValPID_pWinPos = 1.0F;
CALDATA const volatile float32 cal_ECOEvaDesValLL_2X[6] = { 10.0F, 15.0F, 20.0F,
  25.0F, 30.0F, 35.0F } ;

CALDATA const volatile float32 cal_ECOEvaDesValLL_2Y[7] = { 16.0F, 20.0F, 22.0F,
  24.0F, 26.0F, 28.0F, 30.0F } ;

CALDATA const volatile float32 cal_ECOEvaDesValLL_MAP[42] = { 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F }
;

CALDATA const volatile float32 cal_EEEnvAndEnvDiffVal = 15.0F;
CALDATA const volatile float32 cal_EVAPSufTempClsSOV = 8.0F;
CALDATA const volatile float32 cal_EVAPSufTempOpenSOV = 3.0F;
CALDATA const volatile uint16 cal_EVAPSurfTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_EVAPSurfTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile uint16 cal_EVAPTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_EVAPTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_EntExtDefTime = 10.0F;
CALDATA const volatile float32 cal_EnvDLTROffVal = 0.0F;
CALDATA const volatile float32 cal_EnvDLTROnVal = 2.0F;
CALDATA const volatile boolean cal_EnvFailSwFlg = false;
CALDATA const volatile float32 cal_EnvTAme_1X[11] = { -20.0F, -15.0F, -10.0F,
  0.0F, 5.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F } ;

CALDATA const volatile float32 cal_EnvTAme_CUR[11] = { 3.0F, 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F } ;

CALDATA const volatile float32 cal_EnvTempCorData = 0.0F;
CALDATA const volatile boolean cal_EnvTempCorEnb = false;
CALDATA const volatile float32 cal_EnvTempDiffMaxVal = 10.0F;
CALDATA const volatile boolean cal_EnvTempFltSwitch = false;
CALDATA const volatile float32 cal_EnvTempRiseStep = 0.5F;
CALDATA const volatile float32 cal_EnvTempStep = 0.1F;
CALDATA const volatile uint16 cal_EnvVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_EnvVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_ErrAmbTDvtForEvaLL = 2.0F;
CALDATA const volatile float32 cal_ErrAmbTDvtForEvaUL = 4.0F;
CALDATA const volatile float32 cal_ErrAmbTDvtForPtcLL = 2.0F;
CALDATA const volatile float32 cal_ErrAmbTDvtForPtcUL = 4.0F;
CALDATA const volatile float32 cal_EvaDesLLMax = 80.0F;
CALDATA const volatile float32 cal_EvaDesLLMin = 2.5F;
CALDATA const volatile boolean cal_EvaDesLLSelect = false;
CALDATA const volatile boolean cal_EvaEnable = false;
CALDATA const volatile float32 cal_EvapBacTempDesACBi_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesACBi_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesAC_1X[6] = { -1.0F, 2.0F, 10.0F,
  25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesAC_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesDefog_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesDefog_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesFootDe_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesFootDe_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesFoot_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempDesFoot_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesACBi_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesAC_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesAC_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesDefog_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesFootDe_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_1X[6] = { -1.0F, 2.0F,
  10.0F, 25.0F, 29.0F, 30.0F } ;

CALDATA const volatile float32 cal_EvapBacTempPsDesFoot_CUR[6] = { -1.0F, 6.0F,
  10.0F, 20.0F, 28.0F, 80.0F } ;

CALDATA const volatile float32 cal_EvapDesLoLimByEnv_1X[8] = { -5.0F, 0.0F, 5.0F,
  10.0F, 15.0F, 20.0F, 30.0F, 50.0F } ;

CALDATA const volatile float32 cal_EvapDesLoLimByEnv_CUR[8] = { 10.0F, 10.0F,
  5.0F, 5.0F, 0.5F, 0.5F, 0.5F, 0.5F } ;

CALDATA const volatile uint16 cal_EvapDesLoLimBySolarCor_1X[2] = { 0U, 900U } ;

CALDATA const volatile float32 cal_EvapDesLoLimBySolarCor_CUR[2] = { 0.0F, -4.0F
} ;

CALDATA const volatile float32 cal_EvapDesTempCabinCor_1X[6] = { -10.0F, 15.0F,
  20.0F, 30.0F, 35.0F, 40.0F } ;

CALDATA const volatile float32 cal_EvapDesTempCabinCor_CUR[6] = { 0.0F, 0.0F,
  0.0F, 0.0F, -2.0F, -3.0F } ;

CALDATA const volatile float32 cal_EvapDesTempEnvCor_2X[6] = { 5.0F, 25.0F,
  30.0F, 35.0F, 40.0F, 50.0F } ;

CALDATA const volatile float32 cal_EvapDesTempEnvCor_2Y[6] = { 10.0F, 20.0F,
  60.0F, 80.0F, 100.0F, 120.0F } ;

CALDATA const volatile float32 cal_EvapDesTempEnvCor_MAP[36] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint8 cal_EvapDesTempFanCor_1X[4] = { 0U, 3U, 5U, 8U } ;

CALDATA const volatile float32 cal_EvapDesTempFanCor_CUR[4] = { 0.0F, -1.0F,
  -2.0F, -3.0F } ;

CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_1X[6] = { -10.0F, 15.0F,
  20.0F, 30.0F, 35.0F, 40.0F } ;

CALDATA const volatile float32 cal_EvapDesTempPsCabinCor_CUR[6] = { 0.0F, 0.0F,
  0.0F, 0.0F, -2.0F, -3.0F } ;

CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2X[6] = { 5.0F, 25.0F,
  30.0F, 35.0F, 40.0F, 50.0F } ;

CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_2Y[6] = { 10.0F, 20.0F,
  60.0F, 80.0F, 100.0F, 120.0F } ;

CALDATA const volatile float32 cal_EvapDesTempPsEnvCor_MAP[36] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint8 cal_EvapDesTempPsFanCor_1X[4] = { 0U, 3U, 5U, 8U } ;

CALDATA const volatile float32 cal_EvapDesTempPsFanCor_CUR[4] = { 0.0F, -1.0F,
  -2.0F, -3.0F } ;

CALDATA const volatile float32 cal_EvapSurTempData = 0.0F;
CALDATA const volatile boolean cal_EvapSurTempDataEnb = false;
CALDATA const volatile float32 cal_EvapTempData = 0.0F;
CALDATA const volatile boolean cal_EvapTempDataEnb = false;
CALDATA const volatile float32 cal_ExhSuperHeatFilter = 0.9F;
CALDATA const volatile uint16 cal_ExhaustTime = 600U;
CALDATA const volatile float32 cal_ExitExtDefTime = 3.0F;
CALDATA const volatile float32 cal_ExtDefBatMinT = 20.0F;
CALDATA const volatile float32 cal_ExtDefEnvMaxTemp = 5.0F;
CALDATA const volatile float32 cal_ExtDefEnvMinTemp = -15.0F;
CALDATA const volatile boolean cal_ExtDefFlgData = false;
CALDATA const volatile boolean cal_ExtDefFlgDataEnb = false;
CALDATA const volatile float32 cal_ExtDefOHXOffTemp = 12.0F;
CALDATA const volatile float32 cal_ExtDefOHXOnTemp = 1.0F;
CALDATA const volatile float32 cal_ExtDefPTCTrgTemp = 25.0F;
CALDATA const volatile float32 cal_ExtDefTempDiff = 12.0F;
CALDATA const volatile uint8 cal_FANSpdHotStartLL = 15U;
CALDATA const volatile uint8 cal_FANSpdHotStartUL = 40U;
CALDATA const volatile uint8 cal_FANSpdModeShiftMax = 60U;
CALDATA const volatile float32 cal_FaceDuctTempData = 0.0F;
CALDATA const volatile boolean cal_FaceDuctTempEnb = false;
CALDATA const volatile uint16 cal_FaceDuctVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_FaceDuctVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile uint16 cal_FallTime2Tamb = 100U;
CALDATA const volatile uint16 cal_FalseTime2EnvTamb = 10U;
CALDATA const volatile uint16 cal_FalseTime2Solar = 20U;
CALDATA const volatile uint8 cal_FanCtrlOff = 10U;
CALDATA const volatile uint8 cal_FanLevelToPWM[10] = { 0U, 23U, 27U, 34U, 41U,
  50U, 59U, 69U, 78U, 78U } ;

CALDATA const volatile boolean cal_FixPIDSecletFlag = true;
CALDATA const volatile float32 cal_FootDuctTempData = 0.0F;
CALDATA const volatile boolean cal_FootDuctTempEnb = false;
CALDATA const volatile uint16 cal_FootDuctVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_FootDuctVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile sint16 cal_HAPevap_min = 30;
CALDATA const volatile uint16 cal_HAPparkdly_time = 10U;
CALDATA const volatile uint16 cal_HAPpurge_time = 100U;
CALDATA const volatile uint16 cal_HAPtimelim2activtic = 100U;
CALDATA const volatile boolean cal_HMIUnlckVentEnb = false;
CALDATA const volatile uint8 cal_HMIUnlckVentEnbData = 0U;
CALDATA const volatile float32 cal_HPAndLPDiffMaxVal = 0.3F;
CALDATA const volatile float32 cal_HPEXVCtlKi = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtlKiDeadzoneNeg = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtlKiDeadzonePos = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtlKisumMax = 50.0F;
CALDATA const volatile float32 cal_HPEXVCtlKisumMin = -50.0F;
CALDATA const volatile float32 cal_HPEXVCtlKp = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtlKpDeadzoneNeg = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtlKpDeadzonePos = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtrlADeadzone = 1.0F;
CALDATA const volatile float32 cal_HPEXVCtrlADelayTime = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlAFFLolmt = 4.0F;
CALDATA const volatile float32 cal_HPEXVCtrlAFFUplmt = 12.0F;
CALDATA const volatile float32 cal_HPEXVCtrlAFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlAFF_CUR[5] = { 6.0F, 8.0F, 10.0F,
  10.0F, 10.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlAKi_1X[11] = { -15.0F, -10.0F, -5.0F,
  -2.0F, -1.0F, 0.0F, 1.0F, 2.0F, 5.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlAKi_CUR[11] = { 0.01F, 0.005F,
  0.005F, 0.005F, 0.006F, 0.0F, 0.006F, 0.005F, 0.004F, 0.005F, 0.01F } ;

CALDATA const volatile float32 cal_HPEXVCtrlAKp_1X[12] = { -12.0F, -8.0F, -5.0F,
  -3.0F, -2.0F, -1.0F, 1.0F, 2.0F, 3.0F, 5.0F, 8.0F, 12.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlAKp_CUR[12] = { 0.9F, 1.0F, 0.7F,
  0.9F, 0.7F, 0.0F, 0.0F, 0.7F, 0.9F, 0.7F, 1.0F, 0.9F } ;

CALDATA const volatile float32 cal_HPEXVCtrlAMax = 80.0F;
CALDATA const volatile float32 cal_HPEXVCtrlAMin = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlAOpenVal = 20.0F;
CALDATA const volatile float32 cal_HPEXVCtrlATrgFilterVal = 0.0F;
CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_1X[5] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlATrgtSubcool_CUR[5] = { 4.0F, 6.0F,
  6.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCDeadzone = 0.5F;
CALDATA const volatile float32 cal_HPEXVCtrlCDelayTime = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlCFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCFF_CUR[5] = { 40.0F, 40.0F, 40.0F,
  40.0F, 40.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCKi_1X[8] = { -10.0F, -3.0F, -2.0F,
  0.0F, 2.0F, 5.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCKi_CUR[8] = { 0.01F, 0.004F, 0.0F,
  0.0F, 0.0F, 0.002F, 0.002F, 0.003F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCKp_1X[8] = { -15.0F, -3.0F, -2.0F,
  0.0F, 2.0F, 5.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCKp_CUR[8] = { 2.0F, 2.0F, 0.5F,
  0.0F, 0.0F, 0.8F, 1.0F, 1.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlCMax = 100.0F;
CALDATA const volatile float32 cal_HPEXVCtrlCMin = 25.0F;
CALDATA const volatile float32 cal_HPEXVCtrlCOpenVal = 25.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDDeadzone = 1.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDDelayTime = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDFFLolmt = 4.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDFFUplmt = 100.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDFF_CUR[5] = { 25.0F, 25.0F, 25.0F,
  25.0F, 25.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDKi_1X[8] = { -10.0F, -5.0F, -2.0F,
  0.0F, 2.0F, 5.0F, 10.0F, 15.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDKi_CUR[8] = { 0.005F, 0.004F,
  0.005F, 0.005F, 0.005F, 0.004F, 0.005F, 0.006F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDKp_1X[8] = { -10.0F, -5.0F, -3.0F,
  1.0F, 3.0F, 5.0F, 8.0F, 12.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDKp_CUR[8] = { 1.0F, 0.7F, 1.0F,
  1.0F, 0.9F, 0.7F, 1.0F, 0.9F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDMax = 100.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDMin = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDOpenVal = 20.0F;
CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_1X[5] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlDTrgtSubcool_CUR[5] = { 8.0F, 8.0F,
  8.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEDeadzone = 1.0F;
CALDATA const volatile float32 cal_HPEXVCtrlEDelayTime = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlEFFLolmt = 4.0F;
CALDATA const volatile float32 cal_HPEXVCtrlEFFUplmt = 12.0F;
CALDATA const volatile float32 cal_HPEXVCtrlEFF_1X[5] = { 1000.0F, 2000.0F,
  3000.0F, 5000.0F, 7000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEFF_CUR[5] = { 6.0F, 8.0F, 10.0F,
  10.0F, 10.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEKi_1X[6] = { 0.0F, 1.0F, 2.0F, 5.0F,
  10.0F, 15.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEKi_CUR[6] = { 0.0F, 0.006F, 0.005F,
  0.004F, 0.005F, 0.01F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEKp_1X[6] = { 1.0F, 2.0F, 3.0F, 5.0F,
  8.0F, 12.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEKp_CUR[6] = { 0.0F, 0.7F, 0.9F,
  0.7F, 1.0F, 0.9F } ;

CALDATA const volatile float32 cal_HPEXVCtrlEMax = 80.0F;
CALDATA const volatile float32 cal_HPEXVCtrlEMin = 10.0F;
CALDATA const volatile float32 cal_HPEXVCtrlEOpenVal = 20.0F;
CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_1X[5] = { 1000.0F,
  2000.0F, 3000.0F, 4000.0F, 5000.0F } ;

CALDATA const volatile float32 cal_HPEXVCtrlETrgtSubcool_CUR[5] = { 4.0F, 6.0F,
  6.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_HPEXVDiffDown = 5.0F;
CALDATA const volatile float32 cal_HPEXVDiffDownRate = 5.0F;
CALDATA const volatile float32 cal_HPEXVDiffUp = 5.0F;
CALDATA const volatile float32 cal_HPEXVDiffUpRate = 5.0F;
CALDATA const volatile float32 cal_HPEXVDownSpdLmt = 0.5F;
CALDATA const volatile boolean cal_HPEXVEnbData = false;
CALDATA const volatile boolean cal_HPEXVEnbDataEnb = false;
CALDATA const volatile float32 cal_HPEXVFloorDiff1 = 0.2F;
CALDATA const volatile float32 cal_HPEXVFloorDiff2 = 0.7F;
CALDATA const volatile float32 cal_HPEXVHiPressLmtOff = 2.1F;
CALDATA const volatile float32 cal_HPEXVHiPressLmtOn = 2.3F;
CALDATA const volatile float32 cal_HPEXVHiPressProOpenSpd = 0.1F;
CALDATA const volatile float32 cal_HPEXVHiPressProhOff = 2.2F;
CALDATA const volatile float32 cal_HPEXVHiPressProhOn = 2.4F;
CALDATA const volatile uint8 cal_HPEXVInitReqData = 0U;
CALDATA const volatile boolean cal_HPEXVInitReqDataeEnb = false;
CALDATA const volatile float32 cal_HPEXVLowPressLmtOff = 0.17F;
CALDATA const volatile float32 cal_HPEXVLowPressLmtOn = 0.15F;
CALDATA const volatile float32 cal_HPEXVLowPressProOpenSpd = 0.2F;
CALDATA const volatile float32 cal_HPEXVOpenCtrlDownSpdLmt = 1.0F;
CALDATA const volatile float32 cal_HPEXVOpenCtrlUpSpdLmt = 1.0F;
CALDATA const volatile float32 cal_HPEXVPosData = 0.0F;
CALDATA const volatile boolean cal_HPEXVPosDataEnb = false;
CALDATA const volatile boolean cal_HPEXVStepLmtSw = true;
CALDATA const volatile float32 cal_HPEXVSubCoolflt = 0.015F;
CALDATA const volatile float32 cal_HPEXVSubCoolflt_1X[6] = { -20.0F, -10.0F,
  -5.0F, 5.0F, 10.0F, 20.0F } ;

CALDATA const volatile float32 cal_HPEXVSubCoolflt_CUR[6] = { 0.015F, 0.015F,
  0.015F, 0.015F, 0.015F, 0.015F } ;

CALDATA const volatile float32 cal_HPEXVUpSpdLmt = 0.5F;
CALDATA const volatile float32 cal_HPEXVlowPressLmtTrg = 5.0F;
CALDATA const volatile float32 cal_HPEXVlowPressProhOff = 0.16F;
CALDATA const volatile float32 cal_HPEXVlowPressProhOn = 0.14F;
CALDATA const volatile float32 cal_HPHighLmtVal = 5.0F;
CALDATA const volatile float32 cal_HPProVal1 = 1.5F;
CALDATA const volatile float32 cal_HPProVal1Relay = 1.3F;
CALDATA const volatile float32 cal_HPProVal2 = 2.0F;
CALDATA const volatile float32 cal_HPProVal2Relay = 1.8F;
CALDATA const volatile float32 cal_HPProVal3 = 2.5F;
CALDATA const volatile float32 cal_HPProVal3Relay = 2.3F;
CALDATA const volatile float32 cal_HPProVal4 = 2.7F;
CALDATA const volatile uint8 cal_HVCHDriverTime = 30U;
CALDATA const volatile boolean cal_HVCHFltData = false;
CALDATA const volatile boolean cal_HVCHFltDataEnb = false;
CALDATA const volatile uint8 cal_HVPartModeData = 0U;
CALDATA const volatile boolean cal_HVPartModeEnb = false;
CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOff = -14.0F;
CALDATA const volatile float32 cal_HeatCOMPEnvTempLmtOn = -12.0F;
CALDATA const volatile uint8 cal_HeatCabinAndCoolBatFanSpd = 80U;
CALDATA const volatile float32 cal_HeatFanCtrl_2X[4] = { 0.0F, 40.0F, 80.0F,
  120.0F } ;

CALDATA const volatile float32 cal_HeatFanCtrl_2Y[13] = { 0.0F, 1.0F, 2.0F, 3.0F,
  4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F } ;

CALDATA const volatile uint8 cal_HeatFanCtrl_MAP[52] = { 40U, 40U, 40U, 40U, 40U,
  40U, 40U, 40U, 40U, 40U, 40U, 40U, 40U, 40U, 40U, 40U, 50U, 50U, 50U, 50U, 60U,
  60U, 60U, 60U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 70U, 80U, 80U, 80U, 80U, 80U,
  80U, 80U, 80U, 80U, 80U, 80U, 80U, 84U, 84U, 84U, 84U, 84U, 84U, 84U, 84U } ;

CALDATA const volatile float32 cal_HeatPumpCOMPHPrsDownSpd = 60.0F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP1 = 0.15F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP2 = 0.16F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP3 = 0.16F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP4 = 0.18F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP5 = 2.2F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP6 = 2.4F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP7 = 2.4F;
CALDATA const volatile float32 cal_HeatPumpCOMPHPrsP8 = 2.6F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsDownSpd = 30.0F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP1 = 0.11F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP2 = 0.13F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP3 = 0.13F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP4 = 0.15F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP5 = 0.6F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP6 = 0.65F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP7 = 0.65F;
CALDATA const volatile float32 cal_HeatPumpCOMPLPrsP8 = 0.7F;
CALDATA const volatile float32 cal_HeatPwrOn = 1.0F;
CALDATA const volatile float32 cal_HiPressData = 0.0F;
CALDATA const volatile boolean cal_HiPressDataEnb = false;
CALDATA const volatile float32 cal_IGBTDownLmtTemp = 55.0F;
CALDATA const volatile float32 cal_IGBTUpLmtTemp = 65.0F;
CALDATA const volatile uint8 cal_IGNONDelayTime = 40U;
CALDATA const volatile uint8 cal_InnerRecTrgPos = 95U;
CALDATA const volatile float32 cal_LAirmixNomOutWaterT = 50.0F;
CALDATA const volatile float32 cal_LCCOutHiPressRaw_1X[2] = { 350.0F, 4500.0F } ;

CALDATA const volatile float32 cal_LCCOutHiPressRaw_CUR[2] = { 0.0598F, 3.518F }
;

CALDATA const volatile uint8 cal_LPFanCtrl = 60U;
CALDATA const volatile float32 cal_LPFanOff = 0.17F;
CALDATA const volatile float32 cal_LPFanOn = 0.14F;
CALDATA const volatile float32 cal_LPProOffTimer = 10.0F;
CALDATA const volatile float32 cal_LPProOnTimer = 20.0F;
CALDATA const volatile float32 cal_LTRFanCtrl_1X[2] = { 50.0F, 60.0F } ;

CALDATA const volatile uint8 cal_LTRFanCtrl_1Y[3] = { 10U, 60U, 80U } ;

CALDATA const volatile float32 cal_LTRIGBTMaxExitTempB = 55.0F;
CALDATA const volatile float32 cal_LTRIGBTTempMotPMPCtrl_1X[2] = { 60.0F, 70.0F
} ;

CALDATA const volatile uint8 cal_LTRIGBTTempMotPMPCtrl_1Y[3] = { 10U, 60U, 80U }
;

CALDATA const volatile float32 cal_LTRIPUTempFanCtrl_1X[2] = { 60.0F, 70.0F } ;

CALDATA const volatile uint8 cal_LTRIPUTempFanCtrl_1Y[3] = { 10U, 60U, 80U } ;

CALDATA const volatile float32 cal_LTRIPUTempMotPMPCtrl_1X[2] = { 60.0F, 70.0F }
;

CALDATA const volatile uint8 cal_LTRIPUTempMotPMPCtrl_1Y[3] = { 10U, 60U, 80U } ;

CALDATA const volatile float32 cal_LTRMotorInletMaxExitTempA = 50.0F;
CALDATA const volatile float32 cal_LTRMotorMaxEntTemp = 65.0F;
CALDATA const volatile float32 cal_LTRMotorMaxExitTemp = 55.0F;
CALDATA const volatile float32 cal_LTRMotorTempMotPMPCtrl_1X[2] = { 60.0F, 70.0F
} ;

CALDATA const volatile uint8 cal_LTRMotorTempMotPMPCtrl_1Y[3] = { 10U, 60U, 80U
} ;

CALDATA const volatile float32 cal_LTT1DownMCV_1X[5] = { 37.0F, 39.0F, 41.0F,
  43.0F, 45.0F } ;

CALDATA const volatile uint8 cal_LTT1DownMCV_CUR[5] = { 2U, 2U, 5U, 8U, 8U } ;

CALDATA const volatile float32 cal_LTT1StbyMCV_1X[6] = { 38.0F, 40.0F, 42.0F,
  44.0F, 46.0F, 48.0F } ;

CALDATA const volatile uint8 cal_LTT1StbyMCV_CUR[6] = { 5U, 5U, 5U, 12U, 12U,
  12U } ;

CALDATA const volatile float32 cal_LTT1UpMCV_1X[5] = { 39.0F, 41.0F, 43.0F,
  45.0F, 47.0F } ;

CALDATA const volatile uint8 cal_LTT1UpMCV_CUR[5] = { 2U, 5U, 8U, 12U, 12U } ;

CALDATA const volatile boolean cal_LessThanT1CalSwt = true;
CALDATA const volatile float32 cal_LoPressData = 0.0F;
CALDATA const volatile boolean cal_LoPressDataEnb = false;
CALDATA const volatile float32 cal_LoPressRaw_1X[2] = { 500.0F, 4500.0F } ;

CALDATA const volatile float32 cal_LoPressRaw_CUR[2] = { 0.0F, 1.0F } ;

CALDATA const volatile float32 cal_MBIGBTHighExitTempG = 65.0F;
CALDATA const volatile float32 cal_MBIPUDevHighExitTempI = 65.0F;
CALDATA const volatile float32 cal_MBMotorInletHighExitTempH = 60.0F;
CALDATA const volatile uint8 cal_MCVFltStsDelayTime = 3U;
CALDATA const volatile float32 cal_MCVPosDiffDelayTime = 0.5F;
CALDATA const volatile uint16 cal_MCVPosDiffMaxVal = 2U;
CALDATA const volatile uint8 cal_MixCoolTrgPos = 7U;
CALDATA const volatile float32 cal_MixDoorClsFF_1X[8] = { -40.0F, -5.0F, -4.0F,
  -3.0F, -2.5F, -1.5F, -1.0F, 0.0F } ;

CALDATA const volatile float32 cal_MixDoorClsFF_CUR[8] = { 60.0F, 70.0F, 80.0F,
  85.0F, 90.0F, 95.0F, 100.0F, 100.0F } ;

CALDATA const volatile boolean cal_MixDoorEnb = false;
CALDATA const volatile float32 cal_MixDoorHPPosVal = 100.0F;
CALDATA const volatile float32 cal_MixDoorKi_1X[8] = { -15.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F } ;

CALDATA const volatile float32 cal_MixDoorKi_CUR[8] = { 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_MixDoorKp_1X[8] = { -40.0F, -5.0F, -4.0F,
  -3.0F, -2.5F, -1.5F, -1.0F, 0.0F } ;

CALDATA const volatile float32 cal_MixDoorKp_CUR[8] = { 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile uint8 cal_MixDoorNData = 0U;
CALDATA const volatile float32 cal_MixDoorNErr = 5.0F;
CALDATA const volatile uint8 cal_MixDoorPData = 0U;
CALDATA const volatile float32 cal_MixDoorPErr = 5.0F;
CALDATA const volatile float32 cal_MixDoorPercData = 0.0F;
CALDATA const volatile boolean cal_MixDoorPercDataEnb = false;
CALDATA const volatile float32 cal_MixDoorPerc_CUR[2] = { 0.0F, 100.0F } ;

CALDATA const volatile float32 cal_MixDoorV_1X[2] = { 400.0F, 4600.0F } ;

CALDATA const volatile uint16 cal_MixDoorVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_MixDoorVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile boolean cal_MixIODrvNotChgFlg = false;
CALDATA const volatile uint8 cal_MixWarmTrgPos = 94U;
CALDATA const volatile uint16 cal_ModeDoorVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_ModeDoorVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile boolean cal_ModeMotorEnb = false;
CALDATA const volatile uint8 cal_ModeMotorNData = 0U;
CALDATA const volatile float32 cal_ModeMotorNErr = 0.5F;
CALDATA const volatile uint8 cal_ModeMotorPData = 0U;
CALDATA const volatile float32 cal_ModeMotorPErr = 0.5F;
CALDATA const volatile float32 cal_ModeMotorTrgPosData = 0.0F;
CALDATA const volatile boolean cal_ModeMotorTrgPosDataEnb = false;
CALDATA const volatile uint8 cal_ModeMotorTrgPos_1X[5] = { 1U, 2U, 3U, 4U, 5U } ;

CALDATA const volatile float32 cal_ModeMotorTrgPos_CUR[5] = { 0.5F, 2.5F, 1.65F,
  3.4F, 4.5F } ;

CALDATA const volatile boolean cal_MotIODrvNotChgFlg = false;
CALDATA const volatile uint16 cal_MotInletTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_MotInletTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile uint8 cal_MotPMPDefaultSpd = 22U;
CALDATA const volatile boolean cal_MotPMPFaultFlgData = false;
CALDATA const volatile boolean cal_MotPMPFaultFlgDataEnb = false;
CALDATA const volatile uint8 cal_MotPMPMotHeatBatSpd = 100U;
CALDATA const volatile uint8 cal_MotPMPSpdDiffVal = 10U;
CALDATA const volatile uint8 cal_MotPMPSpdSetData = 0U;
CALDATA const volatile boolean cal_MotPMPSpdSetDataEnb = false;
CALDATA const volatile uint8 cal_MotPMPThStoSpd = 60U;
CALDATA const volatile float32 cal_MotTempData = 0.0F;
CALDATA const volatile boolean cal_MotTempDataEnb = false;
CALDATA const volatile float32 cal_MotTempDownLmt = 45.0F;
CALDATA const volatile float32 cal_MotTempUpLmt = 60.0F;
CALDATA const volatile float32 cal_MotorModeData = 0.0F;
CALDATA const volatile boolean cal_MotorModeEnb = false;
CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOff = 0.0F;
CALDATA const volatile float32 cal_NmCOMPEnvTempLmtOn = 4.0F;
CALDATA const volatile float32 cal_NmlBatHeatEnvTemp[2] = { 5.0F, 15.0F } ;

CALDATA const volatile float32 cal_NmlBatHeatT1[3] = { 0.0F, 0.0F, 0.0F } ;

CALDATA const volatile float32 cal_NmlBatHeatT2[3] = { 5.0F, 5.0F, 5.0F } ;

CALDATA const volatile float32 cal_NmlBatHeatTave[3] = { 10.0F, 10.0F, 10.0F } ;

CALDATA const volatile float32 cal_NmlBatHeatTrgTemp = 45.0F;
CALDATA const volatile float32 cal_NmlCOMPHPrsDownSpd = 150.0F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP1 = 0.23F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP2 = 0.25F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP3 = 0.25F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP4 = 0.27F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP5 = 2.2F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP6 = 2.4F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP7 = 2.4F;
CALDATA const volatile float32 cal_NmlCOMPHPrsP8 = 2.7F;
CALDATA const volatile float32 cal_NmlCOMPLPrsDownSpd = 150.0F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP1 = 0.11F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP2 = 0.13F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP3 = 0.13F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP4 = 0.15F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP5 = 0.6F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP6 = 0.65F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP7 = 0.65F;
CALDATA const volatile float32 cal_NmlCOMPLPrsP8 = 0.7F;
CALDATA const volatile float32 cal_OHXTempData = 0.0F;
CALDATA const volatile boolean cal_OHXTempDataEnb = false;
CALDATA const volatile uint16 cal_OHXTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_OHXTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_OilBackJudgeTime = 20.0F;
CALDATA const volatile float32 cal_OilBackRunTime = 1.0F;
CALDATA const volatile float32 cal_OilBackStartSpd = 1500.0F;
CALDATA const volatile float32 cal_OpenCoolInletTemp = 19.0F;
CALDATA const volatile float32 cal_OpenCtrlCOMPDownlmt = 100.0F;
CALDATA const volatile float32 cal_OpenCtrlCOMPUplmt = 100.0F;
CALDATA const volatile uint8 cal_OutRecTrgPos = 5U;
CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_1X[8] = { 60.0F, 61.0F,
  62.0F, 65.0F, 66.0F, 67.0F, 70.0F, 72.0F } ;

CALDATA const volatile float32 cal_PCULimBTMAccmSpdDes_CUR[8] = { 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 0.0F } ;

CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_1X[8] = { 60.0F,
  61.0F, 62.0F, 65.0F, 66.0F, 67.0F, 70.0F, 80.0F } ;

CALDATA const volatile float32 cal_PCULimBTMAndCabinAccmSpdDes_CUR[8] = {
  8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F, 8000.0F } ;

CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_1X[8] = { 60.0F, 61.0F,
  65.0F, 66.0F, 67.0F, 68.0F, 69.0F, 70.0F } ;

CALDATA const volatile float32 cal_PCULimCabinAccmSpdDes_CUR[8] = { 6000.0F,
  6000.0F, 6000.0F, 4800.0F, 3600.0F, 2400.0F, 1200.0F, 0.0F } ;

CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_1X[7] = { -20.0F,
  -19.5F, 10.0F, 10.5F, 25.0F, 25.5F, 40.0F } ;

CALDATA const volatile float32 cal_PCUtempOffset2ShutByEnv_CUR[7] = { 25.0F,
  25.0F, 20.0F, 20.0F, 15.0F, 15.0F, 10.0F } ;

CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2X[6] = { 16.0F, 20.0F,
  24.0F, 28.0F, 31.0F, 32.0F } ;

CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_2Y[6] = { 0.0F, 1.0F, 3.0F,
  6.0F, 9.0F, 10.0F } ;

CALDATA const volatile float32 cal_PTCAuxHeatPwrLmt_MAP[36] = { 0.0F, 0.0F, 1.0F,
  2.0F, 3.0F, 8.0F, 0.0F, 1.0F, 2.0F, 3.0F, 5.0F, 8.0F, 0.0F, 2.0F, 4.0F, 5.0F,
  6.0F, 8.0F, 0.0F, 2.0F, 5.0F, 5.0F, 6.0F, 8.0F, 0.0F, 3.0F, 6.0F, 6.0F, 7.0F,
  8.0F, 0.0F, 3.0F, 8.0F, 8.0F, 8.0F, 8.0F } ;

CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_1X[9] = { -2.0F, -1.0F, 0.0F,
  1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 7.0F } ;

CALDATA const volatile float32 cal_PTCBatHeatPwrLmt_CUR[9] = { 0.0F, 0.0F, 0.0F,
  1.5F, 3.0F, 4.0F, 5.0F, 8.0F, 8.0F } ;

CALDATA const volatile uint8 cal_PTCDelOffTime = 1U;
CALDATA const volatile uint8 cal_PTCEnableData = 0U;
CALDATA const volatile boolean cal_PTCEnableDataEnb = false;
CALDATA const volatile float32 cal_PTCMaxTemp = 80.0F;
CALDATA const volatile float32 cal_PTCMinTemp = -40.0F;
CALDATA const volatile uint8 cal_PTCOffAcPMPSpd = 80U;
CALDATA const volatile float32 cal_PTCOffPowerVal = 0.5F;
CALDATA const volatile float32 cal_PTCOnReqPower_1X[6] = { 0.0F, 10.0F, 20.0F,
  30.0F, 40.0F, 50.0F } ;

CALDATA const volatile float32 cal_PTCOnReqPower_CUR[6] = { 0.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F } ;

CALDATA const volatile float32 cal_PTCPwrOffFlt = 2.0F;
CALDATA const volatile float32 cal_PTCReqTempData = -40.0F;
CALDATA const volatile boolean cal_PTCReqTempDataEnb = false;
CALDATA const volatile float32 cal_PTCReqtPowerData = 0.0F;
CALDATA const volatile boolean cal_PTCReqtPowerDataEnb = false;
CALDATA const volatile uint8 cal_PTCRunAcPMPFFSpd = 25U;
CALDATA const volatile float32 cal_PTCRunAcPMPFFTime_1X[6] = { -20.0F, -10.0F,
  0.0F, 10.0F, 15.0F, 25.0F } ;

CALDATA const volatile float32 cal_PTCRunAcPMPFFTime_CUR[6] = { 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F } ;

CALDATA const volatile float32 cal_PTCTempRecircOff = 70.0F;
CALDATA const volatile float32 cal_PTCTempRecircOn = 90.0F;
CALDATA const volatile float32 cal_PressRateVal1 = 8.0F;
CALDATA const volatile float32 cal_PressRateVal1Relay = 6.0F;
CALDATA const volatile float32 cal_PressRateVal2 = 10.0F;
CALDATA const volatile float32 cal_PressRateVal2Relay = 8.0F;
CALDATA const volatile float32 cal_PressRateVal3 = 16.0F;
CALDATA const volatile float32 cal_PressRateVal3Relay = 14.0F;
CALDATA const volatile float32 cal_PressRateVal4 = 20.0F;
CALDATA const volatile float32 cal_PsDVTWeight = 0.0F;
CALDATA const volatile float32 cal_PsDuctFaceFloorFaFactor = 0.6F;
CALDATA const volatile float32 cal_PsDuctFaceFloorFoFactor = 0.4F;
CALDATA const volatile float32 cal_PsDuctSensorFailDeflt = 25.0F;
CALDATA const volatile float32 cal_PsEnv4SetSelect = 0.0F;
CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOff = 0.0F;
CALDATA const volatile float32 cal_PsErrOfEvaDVT2CoolMixOn = 6.0F;
CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOff = 0.0F;
CALDATA const volatile float32 cal_PsErrOfPtcDVT2HeatMixOn = 6.0F;
CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandNeg = 0.5F;
CALDATA const volatile float32 cal_PsEvaDesValPIDIntegDeadBandPos = 0.5F;
CALDATA const volatile float32 cal_PsEvaDesValPIDKi = 0.0F;
CALDATA const volatile float32 cal_PsEvaDesValPIDKiNeg = 0.004F;
CALDATA const volatile float32 cal_PsEvaDesValPIDKiPos = 0.004F;
CALDATA const volatile float32 cal_PsEvaDesValPIDKp = 0.3F;
CALDATA const volatile float32 cal_PsEvaDesValPIDKpNeg = 1.0F;
CALDATA const volatile float32 cal_PsEvaDesValPIDKpPos = 1.0F;
CALDATA const volatile float32 cal_PsEvaDesValPIDLL = 2.5F;
CALDATA const volatile uint8 cal_PsEvaDesValPIDLL_2X[4] = { 0U, 3U, 5U, 8U } ;

CALDATA const volatile float32 cal_PsEvaDesValPIDLL_2Y[7] = { 16.0F, 20.0F,
  22.0F, 24.0F, 26.0F, 28.0F, 30.0F } ;

CALDATA const volatile float32 cal_PsEvaDesValPIDLL_MAP[28] = { 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F,
  2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F, 2.5F } ;

CALDATA const volatile float32 cal_PsEvaDesValPIDUL = 25.0F;
CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMax = 2.5F;
CALDATA const volatile float32 cal_PsEvaDesValPID_IsumMin = -2.5F;
CALDATA const volatile float32 cal_PsEvaDesValPID_pWinNeg = 3.0F;
CALDATA const volatile float32 cal_PsEvaDesValPID_pWinPos = 3.0F;
CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_1X[4] = { 0.0F, 2.0F,
  3.0F, 4.0F } ;

CALDATA const volatile float32 cal_PsEvapDesFilterByDvt_CUR[4] = { 0.19921875F,
  0.3984375F, 0.6015625F, 1.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetAC_1X[8] = { 13.0F, 17.0F, 19.0F,
  43.0F, 43.5F, 44.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetAC_CUR[8] = { 20.0F, 40.0F, 50.0F,
  80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetBi_1X[8] = { 13.0F, 17.0F, 19.0F,
  43.0F, 43.5F, 44.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetBi_CUR[8] = { 20.0F, 40.0F, 50.0F,
  80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetDefog_1X[8] = { 13.0F, 17.0F,
  19.0F, 43.0F, 43.5F, 44.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetDefog_CUR[8] = { 20.0F, 40.0F,
  50.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetFootDe_1X[8] = { 13.0F, 17.0F,
  19.0F, 43.0F, 43.5F, 44.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetFootDe_CUR[8] = { 20.0F, 40.0F,
  50.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetFoot_1X[8] = { 13.0F, 17.0F, 19.0F,
  43.0F, 43.5F, 44.0F, 49.0F, 50.0F } ;

CALDATA const volatile float32 cal_PsMixBacSetFoot_CUR[8] = { 20.0F, 40.0F,
  50.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;

CALDATA const volatile float32 cal_PsMixDesValPIDIntegDeadBand = 3.0F;
CALDATA const volatile uint8 cal_PsMixDesValPIDLL = 0U;
CALDATA const volatile uint8 cal_PsMixDesValPIDUL = 100U;
CALDATA const volatile float32 cal_PsMixDesValPID_IsumMax = 40.0F;
CALDATA const volatile float32 cal_PsMixDesValPID_IsumMin = -30.0F;
CALDATA const volatile float32 cal_PsMixDesValPID_Ki = 0.008F;
CALDATA const volatile float32 cal_PsMixDesValPID_KiNeg = 0.02F;
CALDATA const volatile float32 cal_PsMixDesValPID_KiPos = 0.02F;
CALDATA const volatile float32 cal_PsMixDesValPID_Kp = 1.0F;
CALDATA const volatile float32 cal_PsMixDesValPID_KpNeg = 1.5F;
CALDATA const volatile float32 cal_PsMixDesValPID_KpPos = 1.5F;
CALDATA const volatile float32 cal_PsMixDesValPID_pWinNeg = 3.0F;
CALDATA const volatile float32 cal_PsMixDesValPID_pWinPos = 3.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4InHeat = 5.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDIntegDeadBand4OutHeat = 3.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDKi = 0.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDKiNeg = 0.004F;
CALDATA const volatile float32 cal_PsPtcDesValPIDKiPos = 0.004F;
CALDATA const volatile float32 cal_PsPtcDesValPIDKp = 0.5F;
CALDATA const volatile float32 cal_PsPtcDesValPIDKpNeg = 1.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDKpPos = 1.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDLL = 0.0F;
CALDATA const volatile float32 cal_PsPtcDesValPIDUL = 60.0F;
CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMax = 2.0F;
CALDATA const volatile float32 cal_PsPtcDesValPID_IsumMin = -2.0F;
CALDATA const volatile float32 cal_PsPtcDesValPID_pWinNeg = 4.0F;
CALDATA const volatile float32 cal_PsPtcDesValPID_pWinPos = 3.0F;
CALDATA const volatile boolean cal_PtcEnable = false;
CALDATA const volatile boolean cal_PwrACPumpData = false;
CALDATA const volatile boolean cal_PwrACPumpEnb = false;
CALDATA const volatile boolean cal_PwrBlwData = false;
CALDATA const volatile boolean cal_PwrBlwEnb = false;
CALDATA const volatile uint8 cal_PwrFanAndPumpData = 0U;
CALDATA const volatile boolean cal_PwrFanAndPumpDataEnb = false;
CALDATA const volatile boolean cal_PwrFanData = false;
CALDATA const volatile boolean cal_PwrFanEnb = false;
CALDATA const volatile boolean cal_PwrHVPartData = false;
CALDATA const volatile boolean cal_PwrHVPartEnb = false;
CALDATA const volatile float32 cal_PwrOffsetVal = 0.2F;
CALDATA const volatile boolean cal_PwrSensorData = false;
CALDATA const volatile boolean cal_PwrSensorEnb = false;
CALDATA const volatile float32 cal_REC_DVTFresh = 18.0F;
CALDATA const volatile float32 cal_REC_DVTRecirc = 12.0F;
CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_1X[14] = { -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F } ;

CALDATA const volatile float32 cal_RFace2FaceFloorByEnv_CUR[14] = { 21.0F, 21.0F,
  21.0F, 21.0F, 21.0F, 21.0F, 21.0F, 21.0F, 21.0F, 21.0F, 23.0F, 25.0F, 27.0F,
  27.0F } ;

CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_1X[14] = { -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F } ;

CALDATA const volatile float32 cal_RFaceFloor2FaceByEnv_CUR[14] = { 19.0F, 19.0F,
  19.0F, 19.0F, 19.0F, 19.0F, 19.0F, 19.0F, 19.0F, 19.0F, 21.0F, 23.0F, 25.0F,
  25.0F } ;

CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_1X[14] = { -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F } ;

CALDATA const volatile float32 cal_RFaceFloor2FloorByEnv_CUR[14] = { 30.0F,
  30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 32.0F, 32.0F,
  32.0F, 32.0F } ;

CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_1X[14] = { -20.0F,
  -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F,
  40.0F, 45.0F } ;

CALDATA const volatile float32 cal_RFloor2FaceFloorByEnv_CUR[14] = { 26.0F,
  26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 30.0F, 30.0F,
  30.0F, 30.0F } ;

CALDATA const volatile boolean cal_RecIODrvNotChgFlg = false;
CALDATA const volatile float32 cal_RecirActVal_1X[2] = { 1.42F, 4.68F } ;

CALDATA const volatile uint8 cal_RecirActVal_CUR[2] = { 100U, 0U } ;

CALDATA const volatile float32 cal_RecircDoorNErr = 5.0F;
CALDATA const volatile float32 cal_RecircDoorPErr = 5.0F;
CALDATA const volatile uint16 cal_RecircDoorVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_RecircDoorVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile boolean cal_RecircMotorEnb = false;
CALDATA const volatile uint8 cal_RecircMotorNData = 0U;
CALDATA const volatile uint8 cal_RecircMotorPData = 0U;
CALDATA const volatile uint8 cal_RecircTrgPosData = 0U;
CALDATA const volatile boolean cal_RecircTrgPosDataEnb = false;
CALDATA const volatile RefModes cal_RefModeData = RefModes_Ref_Off;
CALDATA const volatile boolean cal_RefModeEnb = false;
CALDATA const volatile boolean cal_RemtACDefEnbData = false;
CALDATA const volatile boolean cal_RemtACEnb = false;
CALDATA const volatile boolean cal_RemtACEnbData = false;
CALDATA const volatile uint16 cal_RiseTime2EnvTamb = 10U;
CALDATA const volatile uint16 cal_RiseTime2Solar = 35U;
CALDATA const volatile uint16 cal_RiseTime2Tamb = 250U;
CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOff = 93.0F;
CALDATA const volatile float32 cal_SOCHighPTCPwrLmtOn = 95.0F;
CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_1X[6] = { 16.0F, 20.0F,
  24.0F, 26.0F, 28.0F, 31.0F } ;

CALDATA const volatile float32 cal_SOCHighPTCPwrLmt_CUR[6] = { 2.0F, 2.0F, 2.0F,
  3.0F, 5.0F, 7.0F } ;

CALDATA const volatile boolean cal_SOVData = false;
CALDATA const volatile boolean cal_SOVEnb = false;
CALDATA const volatile float32 cal_SensorTempDownFlg = 200.0F;
CALDATA const volatile float32 cal_SensorTempUpFlt = 2600.0F;
CALDATA const volatile float32 cal_SensorVolDownFlg = 50.0F;
CALDATA const volatile float32 cal_SensorVolUpFlg = 4950.0F;
CALDATA const volatile float32 cal_SetLeftMixDoorTrgData = 0.0F;
CALDATA const volatile boolean cal_SetLeftMixDoorTrgDataEnb = false;
CALDATA const volatile float32 cal_SetPtcDesCoff = 0.9F;
CALDATA const volatile float32 cal_SetPtcDesTempMax_2X[10] = { -30.0F, -15.0F,
  -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 25.0F } ;

CALDATA const volatile uint8 cal_SetPtcDesTempMax_2Y[10] = { 0U, 23U, 27U, 34U,
  41U, 50U, 59U, 69U, 78U, 90U } ;

CALDATA const volatile float32 cal_SetPtcDesTempMax_MAP[100] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 60.0F, 60.0F, 60.0F, 60.0F,
  60.0F, 60.0F, 50.0F, 45.0F, 42.0F, 42.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
  60.0F, 50.0F, 45.0F, 42.0F, 42.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F,
  50.0F, 48.0F, 45.0F, 43.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 50.0F,
  48.0F, 45.0F, 43.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 52.0F, 50.0F,
  47.0F, 45.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 52.0F, 50.0F, 47.0F,
  45.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 52.0F, 50.0F, 47.0F, 45.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 52.0F, 50.0F, 47.0F, 45.0F, 60.0F,
  60.0F, 60.0F, 60.0F, 60.0F, 60.0F, 52.0F, 50.0F, 47.0F, 45.0F } ;

CALDATA const volatile float32 cal_SetPtcDesTempMin = 0.0F;
CALDATA const volatile uint16 cal_SolarData = 0U;
CALDATA const volatile boolean cal_SolarEnb = false;
CALDATA const volatile uint16 cal_SolarFalseStep = 25U;
CALDATA const volatile uint16 cal_SolarRiseStep = 25U;
CALDATA const volatile float32 cal_SolarValRaw_1X[11] = { 0.335550517F,
  0.571425498F, 0.807300508F, 1.04317546F, 1.27905047F, 1.51492548F, 1.75080049F,
  1.9866755F, 2.22255063F, 2.45842552F, 2.69430017F } ;

CALDATA const volatile uint16 cal_SolarValRaw_CUR[11] = { 1000U, 1000U, 1000U,
  1000U, 1000U, 950U, 750U, 550U, 375U, 175U, 0U } ;

CALDATA const volatile uint16 cal_SolorVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_SolorVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_StartPrsProTimes = 0.5F;
CALDATA const volatile float32 cal_SuperHeatFilter = 0.9F;
CALDATA const volatile float32 cal_SuperHeat_1X[28] = { 0.029451F, 0.039117F,
  0.051209F, 0.066144F, 0.084378F, 0.1064F, 0.13273F, 0.16394F, 0.2006F,
  0.24334F, 0.2928F, 0.34966F, 0.41461F, 0.48837F, 0.57171F, 0.66538F, 0.7702F,
  0.88698F, 1.0166F, 1.1599F, 1.3179F, 1.4915F, 1.6818F, 2.1168F, 2.6332F,
  3.2442F, 3.9724F, 4.0541F } ;

CALDATA const volatile float32 cal_SuperHeat_CUR[28] = { -50.0F, -45.0F, -40.0F,
  -35.0F, -30.0F, -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 70.0F,
  80.0F, 90.0F, 100.0F, 101.0F } ;

CALDATA const volatile float32 cal_TACCMOutRaw_1X[30] = { 66.1F, 144.1F, 191.8F,
  222.4F, 258.9F, 302.6F, 355.1F, 418.4F, 495.2F, 588.7F, 703.2F, 844.0F,
  1018.2F, 1234.9F, 1505.8F, 1846.7F, 2278.2F, 2828.0F, 3533.1F, 4443.7F,
  5628.2F, 7180.4F, 9230.6F, 11960.2F, 15625.5F, 20590.3F, 27377.1F, 36742.9F,
  49795.9F, 94331.5F } ;

CALDATA const volatile float32 cal_TACCMOutRaw_CUR[30] = { 140.0F, 110.0F,
  100.0F, 95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F,
  45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F,
  -10.0F, -15.0F, -20.0F, -25.0F, -30.0F, -40.0F } ;

CALDATA const volatile float32 cal_TCabinRaw_1X[27] = { 0.196F, 0.23F, 0.269F,
  0.318F, 0.382F, 0.453F, 0.541F, 0.649F, 0.782F, 0.95F, 1.161F, 1.427F, 1.766F,
  2.2F, 2.756F, 3.477F, 4.427F, 5.683F, 7.346F, 9.572F, 12.58F, 16.68F, 22.32F,
  29.06F, 38.9F, 52.23F, 70.23F } ;

CALDATA const volatile float32 cal_TCabinRaw_CUR[27] = { 90.0F, 85.0F, 80.0F,
  75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F,
  20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F,
  -35.0F, -40.0F } ;

CALDATA const volatile float32 cal_TChillOutRaw_1X[27] = { 0.196F, 0.23F, 0.269F,
  0.318F, 0.382F, 0.453F, 0.541F, 0.649F, 0.782F, 0.95F, 1.161F, 1.427F, 1.766F,
  2.2F, 2.756F, 3.477F, 4.427F, 5.683F, 7.346F, 9.572F, 12.58F, 16.68F, 22.32F,
  29.06F, 38.9F, 52.23F, 70.23F } ;

CALDATA const volatile float32 cal_TChillOutRaw_CUR[27] = { 90.0F, 85.0F, 80.0F,
  75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F,
  20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F,
  -35.0F, -40.0F } ;

CALDATA const volatile float32 cal_TDuctRaw_1X[26] = { 0.3229F, 0.3789F, 0.4466F,
  0.5285F, 0.6283F, 0.7505F, 0.9007F, 1.086F, 1.317F, 1.606F, 1.969F, 2.428F,
  3.012F, 3.761F, 4.727F, 5.983F, 7.626F, 9.795F, 12.68F, 16.55F, 21.79F, 28.94F,
  38.81F, 52.58F, 71.97F, 99.61F } ;

CALDATA const volatile float32 cal_TDuctRaw_CUR[26] = { 85.0F, 80.0F, 75.0F,
  70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F,
  15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F,
  -35.0F, -40.0F } ;

CALDATA const volatile float32 cal_TEnvRaw_1X[27] = { 0.181F, 0.211F, 0.248F,
  0.292F, 0.353F, 0.418F, 0.498F, 0.597F, 0.719F, 0.872F, 1.064F, 1.305F, 1.61F,
  2.0F, 2.504F, 3.158F, 4.014F, 5.13F, 6.65F, 8.638F, 11.33F, 14.95F, 19.86F,
  26.55F, 35.72F, 48.28F, 65.51F } ;

CALDATA const volatile float32 cal_TEnvRaw_CUR[27] = { 90.0F, 85.0F, 80.0F,
  75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F,
  20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F,
  -35.0F, -40.0F } ;

CALDATA const volatile float32 cal_TEvapOutRaw_1X[30] = { 66.1F, 144.1F, 191.8F,
  222.4F, 258.9F, 302.6F, 355.1F, 418.4F, 495.2F, 588.7F, 703.2F, 844.0F,
  1018.2F, 1234.9F, 1505.8F, 1846.7F, 2278.2F, 2828.0F, 3533.1F, 4443.7F,
  5628.2F, 7180.4F, 9230.6F, 11960.2F, 15625.5F, 20590.3F, 27377.1F, 36742.9F,
  49795.9F, 94331.5F } ;

CALDATA const volatile float32 cal_TEvapOutRaw_CUR[30] = { 140.0F, 110.0F,
  100.0F, 95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F,
  45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F,
  -10.0F, -15.0F, -20.0F, -25.0F, -30.0F, -40.0F } ;

CALDATA const volatile float32 cal_TEvapSurfRaw_1X[23] = { 0.1578F, 0.2102F,
  0.2845F, 0.3916F, 0.5489F, 0.6547F, 0.7847F, 0.9456F, 1.146F, 1.369F, 1.711F,
  2.109F, 2.168F, 3.27F, 4.113F, 5.21F, 6.65F, 8.554F, 11.09F, 19.14F, 34.27F,
  63.91F, 124.6F } ;

CALDATA const volatile float32 cal_TEvapSurfRaw_CUR[23] = { 100.0F, 90.0F, 80.0F,
  70.0F, 60.0F, 55.0F, 50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F,
  10.0F, 5.0F, 0.0F, -5.0F, -10.0F, -20.0F, -30.0F, -40.0F, -50.0F } ;

CALDATA const volatile float32 cal_TLCCOutRaw_1X[20] = { 189.0F, 240.3F, 308.4F,
  399.6F, 524.9F, 697.2F, 941.8F, 1290.0F, 1794.0F, 2536.0F, 3661.0F, 5372.0F,
  8080.0F, 12474.0F, 19691.0F, 32014.0F, 54308.0F, 94143.0F, 169149.0F,
  316181.0F } ;

CALDATA const volatile float32 cal_TLCCOutRaw_CUR[20] = { 150.0F, 140.0F, 130.0F,
  120.0F, 110.0F, 100.0F, 90.0F, 80.0F, 70.0F, 60.0F, 50.0F, 40.0F, 30.0F, 20.0F,
  10.0F, 0.0F, -10.0F, -20.0F, -30.0F, -40.0F } ;

CALDATA const volatile PwrModes cal_TMSStatusData = PwrOff;
CALDATA const volatile uint8 cal_TMSStatusEnb = 0U;
CALDATA const volatile float32 cal_TMotEntRaw_1X[17] = { 110.1F, 143.8F, 190.5F,
  256.2F, 350.3F, 487.6F, 691.8F, 1001.9F, 1483.3F, 2248.1F, 3492.8F, 5568.3F,
  9113.8F, 15309.4F, 26347.9F, 46272.5F, 82300.2F } ;

CALDATA const volatile float32 cal_TMotEntRaw_CUR[17] = { 120.0F, 110.0F, 100.0F,
  90.0F, 80.0F, 70.0F, 60.0F, 50.0F, 40.0F, 30.0F, 20.0F, 10.0F, 0.0F, -10.0F,
  -20.0F, -30.0F, -40.0F } ;

CALDATA const volatile float32 cal_TOHXOutRaw_1X[30] = { 66.1F, 144.1F, 191.8F,
  222.4F, 258.9F, 302.6F, 355.1F, 418.4F, 495.2F, 588.7F, 703.2F, 844.0F,
  1018.2F, 1234.9F, 1505.8F, 1846.7F, 2278.2F, 2828.0F, 3533.1F, 4443.7F,
  5628.2F, 7180.4F, 9230.6F, 11960.2F, 15625.5F, 20590.3F, 27377.1F, 36742.9F,
  49795.9F, 94331.5F } ;

CALDATA const volatile float32 cal_TOHXOutRaw_CUR[30] = { 140.0F, 110.0F, 100.0F,
  95.0F, 90.0F, 85.0F, 80.0F, 75.0F, 70.0F, 65.0F, 60.0F, 55.0F, 50.0F, 45.0F,
  40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F, -5.0F, -10.0F,
  -15.0F, -20.0F, -25.0F, -30.0F, -40.0F } ;

CALDATA const volatile float32 cal_TSACBatMinEntTempA = 5.0F;
CALDATA const volatile float32 cal_TSACBatMinEntTempB = 25.0F;
CALDATA const volatile float32 cal_TSACBatMinExitTempM = 24.0F;
CALDATA const volatile float32 cal_TSACBatMinExitTempN = 4.0F;
CALDATA const volatile float32 cal_TSBatInletTempOffsetP = 5.0F;
CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_1X[5] = { 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F } ;

CALDATA const volatile float32 cal_TSBatMaxTempForEnvExitC_CUR[5] = { 24.0F,
  26.0F, 28.0F, 30.0F, 32.0F } ;

CALDATA const volatile float32 cal_TSBatMinExitTempJ = -14.0F;
CALDATA const volatile float32 cal_TSBatMinTempOffsetD = 5.0F;
CALDATA const volatile float32 cal_TSBatMinTemplowValB = -13.0F;
CALDATA const volatile float32 cal_TSDCBatMinEntTempC = 25.0F;
CALDATA const volatile float32 cal_TSDCBatMinExitTempK = 24.0F;
CALDATA const volatile float32 cal_TSIGBTMinTempEntC = 58.0F;
CALDATA const volatile float32 cal_TSIGBTMinTempExitG = 65.0F;
CALDATA const volatile float32 cal_TSIPUExitTempI = 65.0F;
CALDATA const volatile float32 cal_TSMotorMinTempEntC = 58.0F;
CALDATA const volatile float32 cal_TSMotorMinTempExitH = 60.0F;
CALDATA const volatile float32 cal_TempRampStepFast = 0.5F;
CALDATA const volatile float32 cal_TempRampStepLoVSpeed = 0.5F;
CALDATA const volatile float32 cal_TempRampStepSlow = 0.25F;
CALDATA const volatile float32 cal_TevapLoStepMin = 3.0F;
CALDATA const volatile uint16 cal_TevapLoTime = 10U;
CALDATA const volatile float32 cal_TevapUpStepMin = 3.0F;
CALDATA const volatile uint16 cal_TevapUpTime = 10U;
CALDATA const volatile float32 cal_U_DVTFFSolarFilterRate = 0.001F;
CALDATA const volatile boolean cal_UnlockVentEnb = false;
CALDATA const volatile boolean cal_UnlockVentEnbData = false;
CALDATA const volatile uint16 cal_UpAndDownStartTime = 20U;
CALDATA const volatile float32 cal_VehHeatSOCOff = 3.0F;
CALDATA const volatile float32 cal_VehHeatSOCOn = 5.0F;
CALDATA const volatile float32 cal_VehicleSpeedHighVs = 60.0F;
CALDATA const volatile float32 cal_VehicleSpeedLowVs = 10.0F;
CALDATA const volatile uint16 cal_WCCHPVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_WCCHPVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile uint16 cal_WCCHighTempVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_WCCHighTempVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile uint16 cal_WCCLPVolAmend_1X[2] = { 0U, 5000U } ;

CALDATA const volatile sint16 cal_WCCLPVolAmend_CUR[2] = { 0, 0 } ;

CALDATA const volatile float32 cal_WCCTempData = 0.0F;
CALDATA const volatile boolean cal_WCCTempDataEnb = false;
CALDATA const volatile WaterModes cal_WaterModeData = WaterOff;
CALDATA const volatile boolean cal_WaterModeEnb = false;
CALDATA const volatile boolean cal_bACAutoData = false;
CALDATA const volatile boolean cal_bACAutoEnb = false;
CALDATA const volatile boolean cal_bACDefrostData = false;
CALDATA const volatile boolean cal_bACDefrostEnb = false;
CALDATA const volatile boolean cal_bACOnOffData = false;
CALDATA const volatile boolean cal_bACOnOffEnb = false;
CALDATA const volatile boolean cal_bExhFlgData = false;
CALDATA const volatile boolean cal_bExhFlgEnb = false;
CALDATA const volatile boolean cal_bLeftSetHighData = false;
CALDATA const volatile boolean cal_bLeftSetHighEnb = false;
CALDATA const volatile boolean cal_bLeftSetLowData = false;
CALDATA const volatile boolean cal_bLeftSetLowEnb = false;
CALDATA const volatile uint8 cal_eACStsData = 0U;
CALDATA const volatile boolean cal_eACStsEnb = false;
CALDATA const volatile uint8 cal_eBlwStsData = 0U;
CALDATA const volatile boolean cal_eBlwStsEnb = false;
CALDATA const volatile uint8 cal_eC3WVValueData = 0U;
CALDATA const volatile boolean cal_eC3WVValueEnb = false;
CALDATA const volatile uint8 cal_eC5WVValueData = 0U;
CALDATA const volatile boolean cal_eC5WVValueEnb = false;
CALDATA const volatile uint8 cal_eInnerData = 0U;
CALDATA const volatile boolean cal_eInnerEnb = false;
CALDATA const volatile uint8 cal_eModeMotorData = 0U;
CALDATA const volatile boolean cal_eModeMotorEnb = false;
CALDATA const volatile float32 cal_rCabinCoolToCondMixDoor = 90.0F;
CALDATA const volatile uint8 cal_rCabinEvpToHPInnRatio = 10U;
CALDATA const volatile uint8 cal_rCabinHPToEvpInnRatio = 10U;
CALDATA const volatile float32 cal_sMixDoorData = 0.0F;
CALDATA const volatile boolean cal_sMixDoorEnb = false;
CALDATA const volatile float32 cal_tACBatCoolCellTempOn = 36.0F;
CALDATA const volatile float32 cal_tBatCoolACChrgCellTempOff = 34.0F;
CALDATA const volatile float32 cal_tBatCoolCellTempOn = 36.0F;
CALDATA const volatile float32 cal_tBatCoolDCChrgCellTempOff = 31.0F;
CALDATA const volatile float32 cal_tBatCoolVehReadyCellTempOff = 34.0F;
CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOff = 5.0F;
CALDATA const volatile float32 cal_tBatHeatACChrgCellTempOn = 3.0F;
CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOff = 25.0F;
CALDATA const volatile float32 cal_tBatHeatACChrgSOCHighTempOn = 15.0F;
CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOff = 25.0F;
CALDATA const volatile float32 cal_tBatHeatDCChrgCellTempOn = 20.0F;
CALDATA const volatile float32 cal_tBatHeatExitMaxToMinCellDiff = 20.0F;
CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOff = -13.0F;
CALDATA const volatile float32 cal_tBatHeatVehReadyCellTempOn = -15.0F;
CALDATA const volatile float32 cal_tCabinCondToCoolDvtDiff = -3.0F;
CALDATA const volatile float32 cal_tCabinCondToCoolEvapTemp = 5.0F;
CALDATA const volatile float32 cal_tCabinCondToEvpEvapTemp = 1.0F;
CALDATA const volatile float32 cal_tCabinCoolEnvTempHigh = 35.0F;
CALDATA const volatile float32 cal_tCabinCoolEnvTempLow = 15.0F;
CALDATA const volatile float32 cal_tCabinCoolToCondDvtDiff = 3.0F;
CALDATA const volatile float32 cal_tCabinEvpToCondDvtDiff = -4.0F;
CALDATA const volatile float32 cal_tCabinHPToEvpEnvTemp = 16.0F;
CALDATA const volatile float32 cal_tDCBatCoolCellTempOn = 33.0F;
CALDATA const volatile float32 cal_tLTROffBatBal2ToMaxCellDiff = 3.0F;
CALDATA const volatile float32 cal_tLTROnIPUTemp = 55.0F;
CALDATA const volatile float32 cal_tLTROnMaxCellToMotDiff = 3.0F;
CALDATA const volatile float32 cal_tLTROnMotInletTemp = 65.0F;
CALDATA const volatile float32 cal_tLTROnMotTemp = 65.0F;
CALDATA const volatile float32 cal_tLeftSetPointData = 24.0F;
CALDATA const volatile boolean cal_tLeftSetPointEnb = false;
CALDATA const volatile float32 cal_tMotHeatBatACChrgMinCellTempLow = 6.0F;
CALDATA const volatile float32 cal_tMotHeatBatMinCellTempLow = -13.0F;
CALDATA const volatile float32 cal_tMotHeatExitMinCellToBal1Diff = 5.0F;
CALDATA const volatile float32 cal_tMotHeatExitMinCellToMotTempDiff = 2.0F;
CALDATA const volatile float32 cal_tMotHeatOnMotToMinCellDiff = 5.0F;
CALDATA const volatile float32 cal_tMotStorExitMaxCellTemp = 28.0F;
CALDATA const volatile uint16 cal_tiAQSFresh2RecircDelay = 6U;
CALDATA const volatile uint16 cal_tiAQSRecirc2FreshDelay = 1800U;
CALDATA const volatile uint16 cal_tiCO2Fresh2RecircMax = 300U;
CALDATA const volatile uint16 cal_tiCO2Recirc2FreshMax = 18000U;
CALDATA const volatile uint16 cal_tiColdStartTimeMax = 1200U;
