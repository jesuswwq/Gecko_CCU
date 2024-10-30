/*
 * File: calPrmsVcu.c
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.604
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct 30 14:09:32 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "calPrmsVcu.h"
#include "AppSwcVcu.h"

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile float32 ACPT_MotorEffVoltFac_X_V[9] = { 270.0F, 300.0F,
  310.0F, 330.0F, 360.0F, 380.0F, 400.0F, 430.0F, 450.0F } ;
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c1' */

CALDATA const volatile float32 ACPT_MotorSpdFiltCoeff_X_rpm[8] = { 0.0F, 16.0F,
  40.0F, 64.0F, 96.0F, 121.0F, 242.0F, 300.0F } ;
                      /* Referenced by: '<S1117>/MPPC_OutSftSpdFiltCoeff_rat' */

CALDATA const volatile float32 ACPT_Pwr2MotorTqGen_X_kW[22] = { -180.0F, -160.0F,
  -150.0F, -140.0F, -130.0F, -120.0F, -110.0F, -100.0F, -90.0F, -80.0F, -70.0F,
  -60.0F, -50.0F, -40.0F, -30.0F, -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, -2.0F,
  0.0F } ;                /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm1' */

CALDATA const volatile float32 ACPT_Pwr2MotorTqGen_Y_rpm[28] = { 100.0F, 500.0F,
  1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 3500.0F, 4000.0F, 4215.0F,
  4500.0F, 5000.0F, 5500.0F, 6000.0F, 6500.0F, 7000.0F, 7500.0F, 8000.0F,
  8500.0F, 9000.0F, 9500.0F, 10000.0F, 10500.0F, 11000.0F, 11500.0F, 12000.0F,
  12500.0F, 13000.0F } ;  /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm1' */

CALDATA const volatile float32 ACPT_Pwr2MotorTqMot_X_kW[21] = { 0.0F, 2.0F, 5.0F,
  10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F,
  120.0F, 130.0F, 140.0F, 150.0F, 160.0F, 170.0F, 180.0F } ;
                           /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm' */

CALDATA const volatile float32 ACPT_Pwr2MotorTqMot_Y_rpm[28] = { 100.0F, 500.0F,
  1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 3500.0F, 4000.0F, 4215.0F,
  4500.0F, 5000.0F, 5500.0F, 6000.0F, 6500.0F, 7000.0F, 7500.0F, 8000.0F,
  8500.0F, 9000.0F, 9500.0F, 10000.0F, 10500.0F, 11000.0F, 11500.0F, 12000.0F,
  12500.0F, 13000.0F } ;   /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm' */

CALDATA const volatile float32 ACPT_TqDrtFacIgbtTemp_X_C[8] = { 100.0F, 110.0F,
  120.0F, 130.0F, 140.0F, 150.0F, 160.0F, 170.0F } ;
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c2' */

CALDATA const volatile float32 ACPT_TqDrtFacMotorTemp_X_C[8] = { 120.0F, 130.0F,
  140.0F, 145.0F, 150.0F, 155.0F, 160.0F, 170.0F } ;
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c4' */

CALDATA const volatile float32 ADAC_ACCDsrdTqKi_X_N[15] = { -700.0F, -500.0F,
  -400.0F, -300.0F, -200.0F, -100.0F, -50.0F, 0.0F, 50.0F, 100.0F, 200.0F,
  300.0F, 400.0F, 500.0F, 700.0F } ;
                          /* Referenced by: '<S1145>/ADAC_CCSDsrdTqKi_X_N_PL' */

CALDATA const volatile float32 ADAC_ACCDsrdTqKi_Y_mps2[15] = { -2.0F, -0.5F,
  -0.3F, -0.2F, -0.15F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.15F, 0.2F, 0.3F,
  0.5F, 2.0F } ;       /* Referenced by: '<S1145>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */

CALDATA const volatile float32 ADAC_ACCDsrdTqKp_X_mps2[15] = { -2.0F, -1.5F,
  -1.2F, -0.8F, -0.5F, -0.15F, -0.05F, 0.0F, 0.05F, 0.15F, 0.5F, 0.8F, 1.2F,
  1.5F, 2.0F } ;       /* Referenced by: '<S1145>/ADAC_CCSDsrdTqKp_X_mps2_PL' */

CALDATA const volatile float32 ADAC_ACCOvrdTq_X_kph[7] = { 0.0F, 2.0F, 4.0F,
  6.0F, 8.0F, 10.0F, 20.0F } ;
                        /* Referenced by: '<S1139>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 ADAC_CCDsrdAcceltnDec_X_mps2[12] = { -2.0F, -1.4F,
  -1.2F, -0.7F, -0.6F, -0.5F, -0.4F, -0.3F, -0.2F, -0.07F, 0.0F, 0.07F } ;
                /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm1' */

CALDATA const volatile float32 ADAC_CCDsrdAcceltnDeltaSpd_X_kph[21] = { -30.0F,
  -20.0F, -15.0F, -10.0F, -8.0F, -6.0F, -4.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F,
  2.0F, 3.0F, 4.0F, 6.0F, 8.0F, 10.0F, 15.0F, 20.0F, 30.0F } ;
               /* Referenced by: '<S1161>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

CALDATA const volatile float32 ADAC_CCDsrdAcceltnInc_X_mps2[12] = { -0.07F, 0.0F,
  0.07F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 1.1F, 1.4F, 2.0F } ;
                 /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm' */

CALDATA const volatile float32 ADAC_CCDsrdAcceltnSpd_X_kph[6] = { 40.0F, 60.0F,
  80.0F, 100.0F, 120.0F, 140.0F } ;
                /* Referenced by: '<S1161>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

CALDATA const volatile float32 ADAC_CCDsrdTqKi_X_N[15] = { -700.0F, -500.0F,
  -400.0F, -300.0F, -200.0F, -100.0F, -50.0F, 0.0F, 50.0F, 100.0F, 200.0F,
  300.0F, 400.0F, 500.0F, 700.0F } ;
                          /* Referenced by: '<S1168>/ADAC_CCSDsrdTqKi_X_N_PL' */

CALDATA const volatile float32 ADAC_CCDsrdTqKi_Y_mps2[15] = { -2.0F, -0.41F,
  -0.3F, -0.2F, -0.15F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.15F, 0.2F, 0.3F,
  0.4F, 2.0F } ;       /* Referenced by: '<S1168>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */

CALDATA const volatile float32 ADAC_CCDsrdTqKp_X_mps2[15] = { -2.0F, -1.5F,
  -1.2F, -0.8F, -0.5F, -0.15F, -0.05F, 0.0F, 0.05F, 0.15F, 0.5F, 0.8F, 1.2F,
  1.5F, 2.0F } ;       /* Referenced by: '<S1168>/ADAC_CCSDsrdTqKp_X_mps2_PL' */

CALDATA const volatile float32 ADAC_CCMaxDrgTqWhl_X_kph[14] = { 8.0F, 8.2F, 9.0F,
  10.0F, 11.0F, 12.0F, 18.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F, 120.0F, 150.0F
} ;                     /* Referenced by: '<S1170>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 ADAC_CCSpdStabOfst_X_kph[8] = { 30.0F, 40.0F,
  60.0F, 80.0F, 100.0F, 120.0F, 140.0F, 160.0F } ;
                        /* Referenced by: '<S1197>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 ADAC_FullPedDrvTqWhl_X_kph[23] = { 0.0F, 5.0F,
  10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 45.0F, 55.0F, 62.0F, 68.0F, 74.0F,
  87.0F, 99.0F, 111.0F, 124.0F, 136.0F, 149.0F, 161.0F, 173.0F, 186.0F, 198.0F }
;                                /* Referenced by: '<S1134>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 ADAC_HDCDsrdTqKi_X_N[15] = { -700.0F, -500.0F,
  -400.0F, -300.0F, -200.0F, -100.0F, -50.0F, 0.0F, 50.0F, 100.0F, 200.0F,
  300.0F, 400.0F, 500.0F, 700.0F } ;
                          /* Referenced by: '<S1234>/ADAC_CCSDsrdTqKi_X_N_PL' */

CALDATA const volatile float32 ADAC_HDCDsrdTqKi_Y_mps2[15] = { -2.0F, -0.5F,
  -0.3F, -0.2F, -0.15F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.15F, 0.2F, 0.3F,
  0.5F, 2.0F } ;       /* Referenced by: '<S1234>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */

CALDATA const volatile float32 ADAC_HDCDsrdTqKp_X_mps2[15] = { -2.0F, -1.5F,
  -1.2F, -0.8F, -0.5F, -0.15F, -0.05F, 0.0F, 0.05F, 0.15F, 0.5F, 0.8F, 1.2F,
  1.5F, 2.0F } ;       /* Referenced by: '<S1234>/ADAC_CCSDsrdTqKp_X_mps2_PL' */

CALDATA const volatile float32 ADAC_HDCTgtAcceltnDeltaSpd_X_kph[16] = { -10.0F,
  -6.0F, -3.0F, -2.0F, -1.0F, -0.8F, -0.5F, -0.2F, 0.0F, 0.2F, 0.5F, 0.8F, 1.0F,
  2.0F, 3.0F, 5.0F } ;          /* Referenced by: '<S1232>/1-D Lookup Table3' */

CALDATA const volatile float32 ADAC_INVMaxDrgTqWhl_X_kph[12] = { 2.0F, 4.0F,
  6.0F, 8.0F, 10.0F, 15.0F, 20.0F, 40.0F, 60.0F, 80.0F, 100.0F, 150.0F } ;
                                /* Referenced by: '<S1134>/1-D Lookup Table1' */

CALDATA const volatile float32 ADAC_NonDrvnSpdFiltCoeff_X_kph[7] = { 0.0F, 0.2F,
  0.5F, 0.8F, 1.2F, 1.5F, 3.0F } ;
                 /* Referenced by: '<S1159>/Lookup_MVTM_VehSpdFiltCoeff_rat1' */

CALDATA const volatile float32 ADSA_DeceltnIdxAvg_X_pct[10] = { 0.0F, 5.0F,
  10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 50.0F } ;
                       /* Referenced by: '<S17>/MTQD_ZeroTqOfstTipInTMOly_Nm' */

CALDATA const volatile float32 ADSA_SprtIdxVehSpd_X_kph[15] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 120.0F,
  140.0F, 160.0F } ;      /* Referenced by: '<S17>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 AEMS_CellTempMinFac_X_C[5] = { 0.0F, 25.0F, 30.0F,
  40.0F, 55.0F } ;                /* Referenced by: '<S31>/MTQD_TMOverDrt_c5' */

CALDATA const volatile float32 AEMS_ChrgCurFbKi_X_mV[15] = { -100.0F, -50.0F,
  -30.0F, -20.0F, -10.0F, 0.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 80.0F, 120.0F,
  160.0F, 200.0F } ;              /* Referenced by: '<S81>/lu1d_BatLimHiSoC1' */

CALDATA const volatile float32 AEMS_ChrgCurFbKp_X_mV[11] = { -10.0F, 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 80.0F, 120.0F, 160.0F, 200.0F } ;
                                   /* Referenced by: '<S81>/lu1d_BatLimHiSoC' */

CALDATA const volatile float32 AEMS_ChrgPwrFbKi_X_kW[15] = { -40.0F, -20.0F,
  -10.0F, -5.0F, -1.0F, 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 8.0F, 10.0F,
  11.0F } ;                       /* Referenced by: '<S46>/lu1d_BatLimHiSoC1' */

CALDATA const volatile float32 AEMS_ChrgPwrFbKp_X_kW[11] = { -5.0F, -2.0F, 0.0F,
  1.0F, 2.0F, 3.0F, 4.0F, 5.0F, 10.0F, 15.0F, 20.0F } ;
                                   /* Referenced by: '<S46>/lu1d_BatLimHiSoC' */

CALDATA const volatile float32 AEMS_DchaCurFbKi_X_mV[15] = { -200.0F, -160.0F,
  -120.0F, -80.0F, -50.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 10.0F, 20.0F,
  30.0F, 50.0F, 100.0F } ;        /* Referenced by: '<S82>/lu1d_BatLimHiSoC1' */

CALDATA const volatile float32 AEMS_DchaCurFbKp_X_mV[11] = { -200.0F, -160.0F,
  -120.0F, -80.0F, -50.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F, 10.0F } ;
                                   /* Referenced by: '<S82>/lu1d_BatLimHiSoC' */

CALDATA const volatile float32 AEMS_DchaPwrFbKi_X_kW[15] = { -11.0F, -10.0F,
  -8.0F, -6.0F, -5.0F, -4.0F, -3.0F, -2.0F, -1.0F, 0.0F, 1.0F, 5.0F, 10.0F,
  20.0F, 40.0F } ;                /* Referenced by: '<S64>/lu1d_BatLimHiSoC1' */

CALDATA const volatile float32 AEMS_DchaPwrFbKp_X_kW[11] = { -20.0F, -10.0F,
  -5.0F, -3.0F, -2.0F, -1.5F, -1.0F, -0.5F, 0.0F, 2.0F, 5.0F } ;
                                   /* Referenced by: '<S64>/lu1d_BatLimHiSoC' */

CALDATA const volatile float32 AEMS_HVBatMaxChrgPwrSOC_X_pct[7] = { 80.0F, 90.0F,
  93.0F, 95.0F, 97.0F, 98.0F, 100.0F } ;
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c8' */

CALDATA const volatile float32 AEMS_HVBatMaxDchaPwrSOC_X_pct[7] = { 0.0F, 1.0F,
  2.0F, 5.0F, 10.0F, 50.0F, 100.0F } ;
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c6' */

CALDATA const volatile float32 AEMS_MaxConChrgCurOfst_X_A[8] = { -200.0F,
  -100.0F, -70.0F, -50.0F, -30.0F, -20.0F, -10.0F, 0.0F } ;
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c1' */

CALDATA const volatile float32 AEMS_MaxConDchaCurOfst_X_A[8] = { 0.0F, 10.0F,
  20.0F, 30.0F, 50.0F, 70.0F, 100.0F, 200.0F } ;
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c1' */

CALDATA const volatile float32 AEMS_MaxInsChrgCurOfst_X_A[8] = { -200.0F,
  -100.0F, -70.0F, -50.0F, -30.0F, -20.0F, -10.0F, 0.0F } ;
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c7' */

CALDATA const volatile float32 AEMS_MaxInsChrgCurr_X_C[17] = { -30.0F, -15.0F,
  -10.0F, -5.0F, 0.0F, 10.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 44.0F, 46.0F,
  47.0F, 48.0F, 49.0F, 50.0F } ;
                     /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

CALDATA const volatile float32 AEMS_MaxInsChrgCurr_Y_pct[10] = { 0.0F, 50.0F,
  60.0F, 70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;/* Referenced by:
                                                              * '<S26>/Lookup2D_MEMS_MaxInsDchaCurrFac_c'
                                                              * '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A'
                                                              */

CALDATA const volatile float32 AEMS_MaxInsDchaCurOfst_X_A[8] = { 0.0F, 10.0F,
  20.0F, 30.0F, 50.0F, 70.0F, 100.0F, 200.0F } ;
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c2' */

CALDATA const volatile float32 AEMS_MaxInsDchaCurr_X_C[17] = { -31.0F, -30.0F,
  -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 20.0F, 25.0F, 30.0F,
  40.0F, 45.0F, 50.0F, 55.0F } ;
                     /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

CALDATA const volatile float32 AEMS_MaxInsDchaCurr_Y_pct[10] = { 0.0F, 2.0F,
  5.0F, 10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 40.0F, 100.0F } ;/* Referenced by:
                                                             * '<S28>/Lookup2D_MEMS_MaxInsDchaCurrFac_c'
                                                             * '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A'
                                                             */

CALDATA const volatile float32 AIBS_EnvirTemp_X_C[6] = { -15.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F } ;                /* Referenced by:
                                        * '<S1003>/MIBS_NextRtcWupThr_min'
                                        * '<S1003>/MIBS_WupChgTmThr_min'
                                        */

/* 环境温度（X轴）_versteckt */
CALDATA const volatile float32 AIBS_KL30_Y_V[10] = { 12.0F, 12.1F, 12.2F, 12.3F,
  12.4F, 12.5F, 12.6F, 12.7F, 12.8F, 13.0F } ;/* Referenced by:
                                               * '<S1003>/MIBS_NextRtcWupThr_min'
                                               * '<S1003>/MIBS_WupChgTmThr_min'
                                               */

/* KL30电压（Y轴）_versteckt */
CALDATA const volatile float32 AIPC_AccPedBckLsh_X_pct[12] = { 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 40.0F, 60.0F, 80.0F, 90.0F, 100.0F } ;
                                      /* Referenced by: '<S876>/Lookup Table' */

CALDATA const volatile uint8 AIPC_TireRadius_X_enum[6] = { 0U, 1U, 2U, 3U, 4U,
  15U } ;                            /* Referenced by: '<S874>/TireSizeTable' */

CALDATA const volatile float32 ARME_BMSBatCellTempMin_X_C[6] = { -20.0F, -15.0F,
  -10.0F, 0.0F, 10.0F, 20.0F } ;       /* Referenced by:
                                        * '<S960>/MRME_WLTPDwLimFac_c'
                                        * '<S979>/MRME_DynEstRmnChgStp_c'
                                        */

/* BMS电芯最小温度 */
CALDATA const volatile float32 ARME_BMSBatRptSOC_Y_pct[12] = { 0.0F, 3.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F } ;/* Referenced by:
                                                                     * '<S951>/MRME_CHTCStdRmnMil_km'
                                                                     * '<S960>/MRME_WLTPStdRmnMil_km'
                                                                     */

/* 标准续航查表RPTSOC值 */
CALDATA const volatile float32 ARME_EstTgtSubDynEstErr_Y_km[10] = { -90.0F,
  -70.0F, -50.0F, -30.0F, -15.0F, -5.0F, 0.0F, 5.0F, 15.0F, 30.0F } ;
                            /* Referenced by: '<S979>/MRME_DynEstRmnChgStp_c' */

/* 目标续航与实际续航值差值 */
CALDATA const volatile uint8 ASYS_HVBatPackTyp_X_Ah[10] = { 1U, 2U, 3U, 4U, 5U,
  6U, 7U, 8U, 9U, 10U } ;              /* Referenced by:
                                        * '<S26>/Lookup2D_MEMS_MaxInsDchaCurrFac_c'
                                        * '<S26>/PwrDrt2'
                                        * '<S26>/PwrDrt4'
                                        * '<S28>/Lookup2D_MEMS_MaxInsDchaCurrFac_c'
                                        * '<S28>/PwrDrt'
                                        * '<S28>/PwrDrt1'
                                        * '<S28>/PwrDrt2'
                                        * '<S28>/PwrDrt3'
                                        * '<S31>/ASYS_HVBatPackTyp_X_Ah'
                                        * '<S31>/PwrDrt4'
                                        * '<S100>/MDAG_CellTempLoThr_C'
                                        * '<S100>/MDAG_CellUndrVoltThr1_mV'
                                        * '<S100>/MDAG_CellUndrVoltThr2_mV'
                                        * '<S750>/MHVM_BMSCelMaxVol_mV'
                                        * '<S750>/MHVM_BMSTotMaxVol_V'
                                        * '<S750>/MHVM_MaxChrgCurntDC_A'
                                        * '<S750>/MHVM_MaxChrgVoltDC_V'
                                        * '<S951>/MRME_CHTCStdRmnMil_km'
                                        * '<S1002>/MIBS_BMSBatSOCExtrmLo_pct'
                                        * '<S1002>/MIBS_IBSEnMinSOC_pct'
                                        * '<S81>/PwrDrt'
                                        * '<S82>/PwrDrt'
                                        * '<S82>/PwrDrt1'
                                        * '<S103>/BMS_BMSCTL_LMPRECSOC1_CAL'
                                        * '<S103>/BMS_BMSCTL_LMPRECSOC2_CAL'
                                        * '<S103>/BMS_BMSCTL_LMPSOC1_CAL'
                                        * '<S103>/BMS_BMSCTL_LMPSOC2_CAL'
                                        * '<S955>/  '
                                        * '<S960>/MRME_WLTPStdRmnMil_km'
                                        * '<S960>/MRME_WLTPStdSOCCnsm_pct100km '
                                        */

CALDATA const volatile float32 ATQC_RegenMaxTqDecRate_X_kph[4] = { 20.0F, 40.0F,
  60.0F, 80.0F } ;
                /* Referenced by: '<S1261>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

CALDATA const volatile float32 ATQC_RegenMaxTqDecRate_Y_pct[5] = { 0.0F, 5.0F,
  10.0F, 20.0F, 30.0F } ;
               /* Referenced by: '<S1261>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

CALDATA const volatile float32 ATQC_RegenMaxTqIncRate_X_Nm[8] = { -2000.0F,
  -1500.0F, -1000.0F, -800.0F, -500.0F, -300.0F, -200.0F, -100.0F } ;
                        /* Referenced by: '<S1261>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKi_X_N[15] = { -700.0F,
  -500.0F, -400.0F, -300.0F, -200.0F, -100.0F, -50.0F, 0.0F, 50.0F, 100.0F,
  200.0F, 300.0F, 400.0F, 500.0F, 700.0F } ;
                          /* Referenced by: '<S1296>/ADAC_CCSDsrdTqKi_X_N_PL' */

CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKi_Y_mps2[15] = { -2.0F, -0.5F,
  -0.3F, -0.2F, -0.15F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.15F, 0.2F, 0.3F,
  0.5F, 2.0F } ;       /* Referenced by: '<S1296>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */

CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKp_X_mps2[15] = { -2.0F, -1.5F,
  -1.2F, -0.8F, -0.5F, -0.15F, -0.05F, 0.0F, 0.05F, 0.15F, 0.5F, 0.8F, 1.2F,
  1.5F, 2.0F } ;       /* Referenced by: '<S1296>/ADAC_CCSDsrdTqKp_X_mps2_PL' */

CALDATA const volatile float32 ATQD_AdaptCstVehSpd_X_kph[14] = { 8.0F, 8.2F,
  9.0F, 10.0F, 11.0F, 12.0F, 18.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F, 120.0F,
  150.0F } ;                           /* Referenced by:
                                        * '<S1292>/ATQD_RegenTqBrk_X_kph_PL'
                                        * '<S1296>/ATQD_RegenTqBrk_X_kph_PL1'
                                        */

CALDATA const volatile float32 ATQD_CrpTqReqWhlD_X_kph[10] = { 0.0F, 2.0F, 3.0F,
  4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F } ;
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlD_Nm' */

CALDATA const volatile float32 ATQD_CrpTqReqWhlR_X_kph[10] = { -10.0F, -9.0F,
  -8.0F, -7.0F, -6.0F, -5.0F, -4.0F, -3.0F, -2.0F, 0.0F } ;
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlR_Nm' */

CALDATA const volatile float32 ATQD_CstRegenEndPstnV_X_kph[14] = { 2.0F, 4.0F,
  7.0F, 9.0F, 11.0F, 15.0F, 20.0F, 30.0F, 40.0F, 60.0F, 80.0F, 90.0F, 100.0F,
  120.0F } ;                    /* Referenced by: '<S1291>/1-D Lookup Table1' */

CALDATA const volatile float32 ATQD_CstRegenEndPstn_X_kph[15] = { 7.0F, 8.0F,
  9.0F, 10.0F, 12.0F, 14.0F, 16.0F, 18.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F,
  70.0F, 100.0F } ;     /* Referenced by: '<S1291>/ATQD_RegenTqBrk_X_kph_PL2' */

CALDATA const volatile float32 ATQD_CstRegenRateAccPed_X_pct[8] = { -5.0F, 0.0F,
  10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 80.0F } ;
                        /* Referenced by: '<S1293>/ATQD_RegenTqBrk_X_kph_PL2' */

CALDATA const volatile float32 ATQD_CstRegenTqReqWhlD_X_kph[14] = { 8.0F, 8.2F,
  9.0F, 10.0F, 11.0F, 12.0F, 18.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F, 120.0F,
  150.0F } ;            /* Referenced by: '<S1290>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 ATQD_CstRegenTqReqWhlOff_X_pct[5] = { 0.0F, 5.0F,
  10.0F, 20.0F, 50.0F } ; /* Referenced by: '<S1290>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 ATQD_CstRegenTqReqWhlOff_Y_kph[14] = { 8.0F, 8.2F,
  9.0F, 10.0F, 11.0F, 12.0F, 18.0F, 30.0F, 45.0F, 60.0F, 80.0F, 100.0F, 120.0F,
  150.0F } ;              /* Referenced by: '<S1290>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 ATQD_CstRegenTqReqWhlR_X_kph[12] = { -150.0F,
  -100.0F, -80.0F, -60.0F, -45.0F, -30.0F, -18.0F, -12.0F, -10.0F, -8.2F, -8.0F,
  0.0F } ;                      /* Referenced by: '<S1290>/1-D Lookup Table2' */

CALDATA const volatile float32 ATQD_CstRegenTqReqWhlV_X_kph[14] = { 2.0F, 4.0F,
  7.0F, 9.0F, 11.0F, 15.0F, 20.0F, 30.0F, 40.0F, 60.0F, 80.0F, 100.0F, 120.0F,
  160.0F } ;                    /* Referenced by: '<S1290>/1-D Lookup Table1' */

CALDATA const volatile float32 ATQD_FwdFullPedDrvTqWhl_X_kph[19] = { 0.0F,
  5.26442337F, 10.5383654F, 15.7946501F, 21.0539875F, 31.5900345F, 42.1265068F,
  44.3735886F, 47.3844757F, 52.6475F, 57.9181023F, 63.1764908F, 73.7083282F,
  84.2376404F, 94.7668457F, 105.296257F, 115.826721F, 126.357201F, 136.885559F }
;                                      /* Referenced by:
                                        * '<S1283>/MTQD_PTBaseTq_Nm'
                                        * '<S1283>/MTQD_PTBaseTq_Nm1'
                                        */

CALDATA const volatile float32 ATQD_FwdPedMapEco_X_kph[18] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 120.0F,
  130.0F, 140.0F, 150.0F, 170.0F, 180.0F } ;
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct1' */

CALDATA const volatile float32 ATQD_FwdPedMapEco_Y_pct[21] = { 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 65.0F,
  70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;/* Referenced by:
                                                       * '<S1283>/MTQD_PedMapBasTqEco_pct1'
                                                       * '<S1283>/2-D Lookup Table1'
                                                       */

CALDATA const volatile float32 ATQD_FwdPedMapNoCrpEco_X_kph[2] = { 0.0F, 7.0F } ;
                                /* Referenced by: '<S1283>/2-D Lookup Table1' */

CALDATA const volatile float32 ATQD_FwdPedMapNoCrpNorm_X_kph[2] = { 0.0F, 7.0F }
;                               /* Referenced by: '<S1283>/2-D Lookup Table3' */

CALDATA const volatile float32 ATQD_FwdPedMapNoCrpSnow_X_kph[2] = { 0.0F, 7.0F }
;                                /* Referenced by: '<S1283>/2-D Lookup Table' */

CALDATA const volatile float32 ATQD_FwdPedMapNoCrpSpt_X_kph[2] = { 0.0F, 7.0F } ;
                                /* Referenced by: '<S1283>/2-D Lookup Table2' */

CALDATA const volatile float32 ATQD_FwdPedMapNorm_X_kph[18] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 120.0F,
  130.0F, 140.0F, 150.0F, 170.0F, 180.0F } ;
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct3' */

CALDATA const volatile float32 ATQD_FwdPedMapNorm_Y_pct[21] = { 0.0F, 5.0F,
  10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F,
  65.0F, 70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;/* Referenced by:
                                                              * '<S1283>/MTQD_PedMapBasTqEco_pct3'
                                                              * '<S1283>/2-D Lookup Table3'
                                                              */

CALDATA const volatile float32 ATQD_FwdPedMapSnow_X_kph[18] = { 0.0F, 10.0F,
  20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 70.0F, 80.0F, 90.0F, 100.0F, 110.0F, 120.0F,
  130.0F, 140.0F, 150.0F, 170.0F, 180.0F } ;
                          /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 ATQD_FwdPedMapSnow_Y_pct[21] = { 0.0F, 5.0F,
  10.0F, 15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F,
  65.0F, 70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;/* Referenced by:
                                                              * '<S1283>/MTQD_PedMapBasTqEco_pct'
                                                              * '<S1283>/2-D Lookup Table'
                                                              */

CALDATA const volatile float32 ATQD_FwdPedMapSpt_X_kph[18] = { 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 50.0F, 70.0F, 90.0F, 100.0F, 120.0F, 130.0F,
  150.0F, 160.0F, 170.0F, 180.0F } ;
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct2' */

CALDATA const volatile float32 ATQD_FwdPedMapSpt_Y_pct[21] = { 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 65.0F,
  70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;/* Referenced by:
                                                       * '<S1283>/MTQD_PedMapBasTqEco_pct2'
                                                       * '<S1283>/2-D Lookup Table2'
                                                       */

CALDATA const volatile float32 ATQD_LimpHomeMaxTq_X_kph[8] = { -15.0F, -10.0F,
  -5.0F, 0.0F, 5.0F, 10.0F, 20.0F, 30.0F } ;
                        /* Referenced by: '<S1278>/ATQD_RegenTqBrk_X_kph_PL2' */

CALDATA const volatile float32 ATQD_RevFullPedDrvTqWhl_X_kph[19] = { -150.0F,
  -136.0F, -124.0F, -111.0F, -99.0F, -87.0F, -74.0F, -68.0F, -62.0F, -55.0F,
  -45.0F, -35.0F, -30.0F, -25.0F, -20.0F, -15.0F, -10.0F, -5.0F, 0.0F } ;
                                 /* Referenced by: '<S1285>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 ATQD_RevPedMap_X_kph[11] = { -100.0F, -90.0F,
  -80.0F, -70.0F, -60.0F, -50.0F, -40.0F, -30.0F, -20.0F, -10.0F, 0.0F } ;
                          /* Referenced by: '<S1285>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 ATQD_RevPedMap_Y_pct[21] = { 0.0F, 5.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F, 45.0F, 50.0F, 55.0F, 60.0F, 65.0F,
  70.0F, 75.0F, 80.0F, 85.0F, 90.0F, 95.0F, 100.0F } ;
                          /* Referenced by: '<S1285>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOff_X_pct[9] = { 0.0F, 0.5F,
  2.5F, 7.0F, 10.0F, 15.0F, 20.0F, 25.0F, 100.0F } ;
                      /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOff_c' */

CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOn_X_pct[9] = { 0.0F, 0.5F,
  2.5F, 7.0F, 10.0F, 15.0F, 20.0F, 50.0F, 100.0F } ;
                       /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOn_c' */

CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOn_Y_kph[5] = { 0.0F, 0.5F,
  10.0F, 20.0F, 30.0F } ;
                       /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOn_c' */

CALDATA const volatile float32 ATQD_TqDrtFacHiddenLmtPwr_X_kph[7] = { -22.0F,
  -18.0F, -15.0F, 0.0F, 55.0F, 58.0F, 62.0F } ;
               /* Referenced by: '<S1325>/Lookup_MTQD_TqDrtFacHiddenLmtPwr_c' */

CALDATA const volatile float32 ATQD_TqDrtFacLimpHome_X_kph[7] = { -42.0F, -38.0F,
  -25.0F, 0.0F, 25.0F, 38.0F, 42.0F } ;
                /* Referenced by: '<S1324>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 ATQD_TqDrtFacLmtPerfmn_X_kph[8] = { -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 20.0F, 30.0F, 50.0F } ;
                /* Referenced by: '<S1323>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 ATQD_TqDrtFacMotorSpd_X_rpm[5] = { -15800.0F,
  -15300.0F, 0.0F, 15300.0F, 15800.0F } ;
                                 /* Referenced by: '<S1320>/MTQD_TMOverDrt_c' */

CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl1_X_kph[7] = { -6.0F,
  -4.0F, -2.0F, 0.0F, 2.0F, 4.0F, 6.0F } ;
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl2_X_kph[7] = { -62.0F,
  -58.0F, -55.0F, 0.0F, 55.0F, 58.0F, 62.0F } ;
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */

CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl3_X_kph[7] = { -82.0F,
  -78.0F, -75.0F, 0.0F, 75.0F, 78.0F, 82.0F } ;
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */

CALDATA const volatile float32 ATQD_TqDrtFacVehSpdEco_X_kph[6] = { -12.0F, -8.0F,
  0.0F, 135.0F, 143.0F, 147.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 ATQD_TqDrtFacVehSpdNorm_X_kph[6] = { -12.0F,
  -8.0F, 0.0F, 170.0F, 178.0F, 182.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */

CALDATA const volatile float32 ATQD_TqDrtFacVehSpdRev_X_kph[6] = { -42.0F,
  -38.0F, -35.0F, 0.0F, 8.0F, 12.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c4' */

CALDATA const volatile float32 ATQD_TqDrtFacVehSpdSnow_X_kph[6] = { -12.0F,
  -8.0F, 0.0F, 90.0F, 98.0F, 102.0F } ;
                 /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c' */

CALDATA const volatile float32 ATQD_TqDrtFacVehSpdSpt_X_kph[6] = { -12.0F, -8.0F,
  0.0F, 170.0F, 178.0F, 182.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */

CALDATA const volatile float32 ATQD_WhlSpdDiffMaxTq_X_kph[10] = { 0.0F, 3.0F,
  5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 70.0F, 100.0F } ;
                        /* Referenced by: '<S1278>/ATQD_RegenTqBrk_X_kph_PL1' */

CALDATA const volatile float32 ATQF_DecRateFiltTm_X_Nmps[12] = { -8000.0F,
  -5000.0F, -4000.0F, -3000.0F, -2500.0F, -2000.0F, -1500.0F, -1000.0F, -500.0F,
  -300.0F, 0.0F, 100.0F } ;
                        /* Referenced by: '<S1339>/ATQD_RegenTqBrk_X_kph_PL1' */

/* torque decrease rate filter time in starting phase, x axle */
CALDATA const volatile float32 ATQF_IncRateFiltTm_X_Nmps[12] = { -100.0F, 0.0F,
  300.0F, 500.0F, 1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 4000.0F, 5000.0F,
  8000.0F } ;           /* Referenced by: '<S1340>/ATQD_RegenTqBrk_X_kph_PL1' */

/* torque increase rate filter time in starting phase, x axle */
CALDATA const volatile float32 ATQF_TipOutTqDecRateCoeff_Nm[8] = { 0.0F, 100.0F,
  300.0F, 500.0F, 700.0F, 1000.0F, 1500.0F, 2000.0F } ;
                                /* Referenced by: '<S1339>/1-D Lookup Table1' */

CALDATA const volatile float32 ATQF_TqRateDecMaxACC_X_Nm[8] = { 0.0F, 100.0F,
  300.0F, 500.0F, 700.0F, 1000.0F, 1500.0F, 2000.0F } ;
                                    /* Referenced by: '<S1339>/Lookup Table5' */

CALDATA const volatile float32 ATQF_TqRateDecMaxRegen_X_pct[7] = { -20.0F,
  -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 20.0F } ;
               /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL6' */

CALDATA const volatile float32 ATQF_TqRateDecMaxRegen_Y_kph[13] = { -10.0F,
  -5.0F, 0.0F, 5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 80.0F, 90.0F,
  100.0F } ;   /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL7' */

CALDATA const volatile float32 ATQF_TqRateDecMax_X_pct[12] = { -5.0F, 0.0F, 5.0F,
  10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 80.0F, 90.0F, 100.0F } ;
                /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* X axis of max torque decreasing change rate */
CALDATA const volatile float32 ATQF_TqRateDecMax_Y_kph[13] = { -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 80.0F, 90.0F, 100.0F } ;
               /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* Y axis of max torque decreasing change rate */
CALDATA const volatile float32 ATQF_TqRateIncMaxACC_X_Nm[8] = { 0.0F, 200.0F,
  400.0F, 600.0F, 800.0F, 1000.0F, 1500.0F, 2000.0F } ;
                                    /* Referenced by: '<S1340>/Lookup Table5' */

CALDATA const volatile float32 ATQF_TqRateIncMax_X_pct[12] = { -5.0F, 0.0F, 5.0F,
  15.0F, 35.0F, 55.0F, 70.0F, 75.0F, 80.0F, 90.0F, 95.0F, 100.0F } ;
                /* Referenced by: '<S1340>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* X axis of max torque increasing change rate */
CALDATA const volatile float32 ATQF_TqRateIncMax_Y_kph[13] = { -10.0F, -4.0F,
  0.0F, 4.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 80.0F, 100.0F, 200.0F } ;
               /* Referenced by: '<S1340>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* Y axis of max torque increasing change rate */
CALDATA const volatile float32 ATQF_TqRateLimEndErr_X_pct[14] = { -20.0F, -10.0F,
  -2.0F, 0.0F, 5.0F, 10.0F, 20.0F, 30.0F, 40.0F, 50.0F, 60.0F, 80.0F, 90.0F,
  100.0F } ;    /* Referenced by: '<S1338>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* pedal position including acc and brk */
CALDATA const volatile float32 ATQF_TqRateLimEndErr_Y_kph[11] = { -20.0F, 0.0F,
  10.0F, 20.0F, 30.0F, 50.0F, 70.0F, 90.0F, 110.0F, 130.0F, 150.0F } ;
               /* Referenced by: '<S1338>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* vehicle speed */
CALDATA const volatile float32 ATQR_ASDSpdFiltHi_X_rpm[8] = { 0.0F, 2.0F, 4.0F,
  6.0F, 8.0F, 10.0F, 15.0F, 20.0F } ;
                                 /* Referenced by: '<S1366>/1-D Lookup Table' */

CALDATA const volatile float32 ATQR_ASDTqGain_X_kph[8] = { 0.0F, 0.5F, 1.0F,
  1.5F, 2.0F, 3.0F, 5.0F, 10.0F } ;
                                 /* Referenced by: '<S1367>/1-D Lookup Table' */

CALDATA const volatile float32 ATZX_AZDecRate_X_Nm[11] = { -8.0F, -6.0F, -4.0F,
  -3.5F, -3.0F, -2.5F, -1.0F, -0.5F, 0.0F, 1.0F, 2.0F } ;
                                /* Referenced by: '<S1398>/1-D Lookup Table4' */

CALDATA const volatile float32 ATZX_AZIncRate_X_Nm[11] = { -2.0F, -1.0F, 0.0F,
  0.5F, 1.0F, 2.5F, 3.0F, 3.5F, 4.0F, 6.0F, 8.0F } ;
                                /* Referenced by: '<S1398>/1-D Lookup Table3' */

CALDATA const volatile float32 ATZX_AZRngDec_X_kph[12] = { -15.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F, 70.0F, 100.0F } ;
                         /* Referenced by: '<S1398>/MTZX_AZRngTipOutTMOly_Nm' */

CALDATA const volatile float32 ATZX_AZRngInc_X_kph[12] = { -15.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F, 70.0F, 100.0F } ;
                          /* Referenced by: '<S1398>/MTZX_AZRngTipInTMOly_Nm' */

CALDATA const volatile float32 ATZX_BZDecRate_X_Nm[11] = { -2.0F, -1.0F, 0.0F,
  1.0F, 2.0F, 4.0F, 6.0F, 8.0F, 10.0F, 12.0F, 15.0F } ;
                                /* Referenced by: '<S1398>/1-D Lookup Table2' */

CALDATA const volatile float32 ATZX_BZIncRate_X_Nm[11] = { -15.0F, -12.0F,
  -10.0F, -8.0F, -6.0F, -4.0F, -2.0F, -1.0F, 0.0F, 1.0F, 2.0F } ;
                                /* Referenced by: '<S1398>/1-D Lookup Table1' */

CALDATA const volatile float32 ATZX_BZRngDec_X_kph[12] = { -15.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F, 70.0F, 100.0F } ;
                         /* Referenced by: '<S1398>/MTZX_BZRngTipOutTMOly_Nm' */

CALDATA const volatile float32 ATZX_BZRngInc_X_kph[12] = { -15.0F, -10.0F, -5.0F,
  0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F, 70.0F, 100.0F } ;
                          /* Referenced by: '<S1398>/MTZX_BZRngTipInTMOly_Nm' */

CALDATA const volatile float32 ATZX_OPDSlopTq_X_Nm[5] = { -466.0F, -233.0F, 0.0F,
  233.0F, 466.0F } ;                   /* Referenced by:
                                        * '<S1398>/2-D Lookup Table'
                                        * '<S1398>/2-D Lookup Table1'
                                        * '<S1398>/2-D Lookup Table2'
                                        * '<S1398>/2-D Lookup Table3'
                                        */

CALDATA const volatile float32 ATZX_RampDecRate_X_Nm[10] = { 0.0F, 10.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F, 150.0F, 200.0F, 250.0F } ;
                                /* Referenced by: '<S1397>/1-D Lookup Table1' */

CALDATA const volatile float32 ATZX_RampIncRate_X_Nm[10] = { 0.0F, 10.0F, 20.0F,
  40.0F, 60.0F, 80.0F, 100.0F, 150.0F, 200.0F, 250.0F } ;
                                /* Referenced by: '<S1397>/1-D Lookup Table2' */

CALDATA const volatile float32 ATZX_ZeroTqOfstDecACC_X_kph[12] = { -15.0F,
  -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F, 70.0F, 100.0F } ;
                   /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipOutTMOly_Nm5' */

CALDATA const volatile float32 ATZX_ZeroTqOfstDec_Y_kph[16] = { -15.0F, -10.0F,
  -5.0F, 0.0F, 0.1F, 0.2F, 1.9F, 2.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F,
  70.0F, 100.0F } ;             /* Referenced by: '<S1398>/2-D Lookup Table1' */

CALDATA const volatile float32 ATZX_ZeroTqOfstIncACC_X_kph[12] = { -15.0F,
  -10.0F, -5.0F, 0.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F, 70.0F, 100.0F } ;
                    /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipInTMOly_Nm1' */

CALDATA const volatile float32 ATZX_ZeroTqOfstInc_Y_kph[16] = { -15.0F, -10.0F,
  -5.0F, 0.0F, 0.1F, 0.2F, 1.9F, 2.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F,
  70.0F, 100.0F } ;              /* Referenced by: '<S1398>/2-D Lookup Table' */

CALDATA const volatile float32 ATZX_ZeroXTmACC_X_kph[10] = { -20.0F, -10.0F,
  0.0F, 5.0F, 10.0F, 20.0F, 30.0F, 50.0F, 60.0F, 100.0F } ;
                        /* Referenced by: '<S1398>/MTZX_ZeroXTmTipInTMOly_s1' */

CALDATA const volatile float32 ATZX_ZeroXTmDec_Y_kph[16] = { -15.0F, -10.0F,
  -5.0F, 0.0F, 0.1F, 0.2F, 1.9F, 2.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F,
  70.0F, 100.0F } ;             /* Referenced by: '<S1398>/2-D Lookup Table2' */

CALDATA const volatile float32 ATZX_ZeroXTmInc_Y_kph[16] = { -15.0F, -10.0F,
  -5.0F, 0.0F, 0.1F, 0.2F, 1.9F, 2.0F, 5.0F, 10.0F, 15.0F, 20.0F, 30.0F, 50.0F,
  70.0F, 100.0F } ;             /* Referenced by: '<S1398>/2-D Lookup Table3' */

CALDATA const volatile float32 AVTM_ActPwrBacklash_X_kW[8] = { 0.0F, 0.5F, 1.0F,
  2.0F, 3.0F, 5.0F, 10.0F, 30.0F } ;   /* Referenced by: '<S1454>/Dbnd' */

CALDATA const volatile float32 AVTM_MotorMaxDrvTqWT_X_rpm[23] = { 0.0F, 500.0F,
  1000.0F, 1500.0F, 2000.0F, 2500.0F, 3000.0F, 3500.0F, 4000.0F, 4500.0F,
  5000.0F, 5500.0F, 6000.0F, 7000.0F, 8000.0F, 9000.0F, 10000.0F, 11000.0F,
  12000.0F, 13000.0F, 14000.0F, 15000.0F, 16000.0F } ;
                                 /* Referenced by: '<S1449>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 AVTM_MotorSpdFiltCoeff_X_rpm[8] = { 0.0F, 10.0F,
  20.0F, 30.0F, 50.0F, 100.0F, 200.0F, 300.0F } ;
                      /* Referenced by: '<S1440>/MPPC_OutSftSpdFiltCoeff_rat' */

CALDATA const volatile float32 AVTM_VehSpdFiltCoeff_X_kph[8] = { 0.0F, 0.1F,
  0.2F, 0.3F, 0.4F, 1.0F, 2.0F, 5.0F } ;
                  /* Referenced by: '<S1440>/Lookup_MVTM_VehSpdFiltCoeff_rat' */

CALDATA const volatile float32 KCPT_GenMaxTqDecRate_Nmps = -800.0F;/* Referenced by: '<S1117>/Constant18' */
CALDATA const volatile float32 KCPT_GenMaxTqIncRate_Nmps = 50000.0F;/* Referenced by: '<S1117>/Constant19' */
CALDATA const volatile float32 KCPT_MotMaxTqDecRate_Nmps = -50000.0F;/* Referenced by: '<S1117>/Constant11' */
CALDATA const volatile float32 KCPT_MotMaxTqFiltAchvd_Nm = 2.0F;/* Referenced by:
                                                                 * '<S1117>/KCPT_MotorMaxTqFiltAchvd_Nm'
                                                                 * '<S1117>/KCPT_MotorMaxTqFiltAchvd_Nm1'
                                                                 */
CALDATA const volatile float32 KCPT_MotMaxTqIncRate_Nmps = 800.0F;/* Referenced by: '<S1117>/Constant3' */
CALDATA const volatile float32 KCPT_MotorDrgMaxTqAllwd_Nm = -300.0F;
                     /* Referenced by: '<S1117>/KCPT_MotorMaxTqFiltAchvd_Nm2' */
CALDATA const volatile float32 KCPT_MotorMaxTqFiltCoeff_c = 0.8F;/* Referenced by:
                                                                  * '<S1117>/KCPT_MotorMaxTqFiltCoeff_c'
                                                                  * '<S1117>/KCPT_MotorMaxTqFiltCoeff_c1'
                                                                  */
CALDATA const volatile float32 KCPT_MotorRvrsSpdOffD_rpm = -50.0F;/* Referenced by: '<S1117>/Constant8' */
CALDATA const volatile float32 KCPT_MotorRvrsSpdOffR_rpm = 100.0F;/* Referenced by: '<S1117>/Constant10' */
CALDATA const volatile float32 KCPT_MotorRvrsSpdOnD_rpm = -100.0F;/* Referenced by: '<S1117>/Constant9' */
CALDATA const volatile float32 KCPT_MotorRvrsSpdOnR_rpm = 50.0F;/* Referenced by: '<S1117>/Constant5' */
CALDATA const volatile float32 KDAC_ABSActvDlyTm4CC_s = 0.8F;/* Referenced by: '<S1181>/Constant2' */
CALDATA const volatile float32 KDAC_ACCDsrdTqIMax_N = 5000.0F;
                                      /* Referenced by: '<S1145>/Saturation1' */
CALDATA const volatile float32 KDAC_ACCDsrdTqIMin_N = -30000.0F;
                                      /* Referenced by: '<S1145>/Saturation1' */
CALDATA const volatile float32 KDAC_AccReqStopAllwdSpd_kph = 3.0F;
                        /* Referenced by: '<S1141>/KVTM_LimpHomeOvrdVal_flg2' */
CALDATA const volatile float32 KDAC_BrkPedPrsdOff_pct = 0.5F;
                           /* Referenced by: '<S1134>/KTQD_BrkPedPstnHi_pct1' */
CALDATA const volatile float32 KDAC_BrkPedPrsdOn_pct = 2.0F;
                            /* Referenced by: '<S1134>/KTQD_BrkPedPstnHi_pct' */
CALDATA const volatile float32 KDAC_BrkTq2PresrCvrtCoeff_c = 0.0093F;/* Referenced by:
                                                                      * '<S1447>/Constant18'
                                                                      * '<S1134>/Constant18'
                                                                      * '<S1233>/Constant18'
                                                                      */
CALDATA const volatile boolean KDAC_BypCruiseSdnCC_flg = false;
                        /* Referenced by: '<S1181>/KVTM_LimpHomeOvrdVal_flg3' */
CALDATA const volatile boolean KDAC_BypCruiseSdn_flg = false;
                        /* Referenced by: '<S1138>/KVTM_LimpHomeOvrdVal_flg2' */
CALDATA const volatile boolean KDAC_BypESPTqIntv_flg = true;
                        /* Referenced by: '<S1138>/KVTM_LimpHomeOvrdVal_flg3' */
CALDATA const volatile float32 KDAC_CCAccelPedPrsdOff_pct = 1.0F;
                       /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph1' */
CALDATA const volatile float32 KDAC_CCAccelPedPrsdOn_pct = 3.0F;
                        /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph' */
CALDATA const volatile float32 KDAC_CCDsrdAcceltnMax_mps2 = 2.0F;
                                      /* Referenced by: '<S1161>/Saturation1' */
CALDATA const volatile float32 KDAC_CCDsrdAcceltnMin_mps2 = -2.0F;
                                      /* Referenced by: '<S1161>/Saturation1' */
CALDATA const volatile float32 KDAC_CCDsrdTqDecIDlyTm_s = 0.5F;/* Referenced by: '<S1170>/Constant4' */
CALDATA const volatile float32 KDAC_CCDsrdTqIMax_N = 2000.0F;
                                      /* Referenced by: '<S1168>/Saturation1' */
CALDATA const volatile float32 KDAC_CCDsrdTqIMin_N = -2000.0F;
                                      /* Referenced by: '<S1168>/Saturation1' */
CALDATA const volatile float32 KDAC_CCDsrdTqIncIDlyTm_s = 0.5F;/* Referenced by: '<S1170>/Constant1' */
CALDATA const volatile float32 KDAC_CCHldISpdOverOff_kph = 0.5F;
                       /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph3' */
CALDATA const volatile float32 KDAC_CCHldISpdOverOn_kph = 1.0F;
                       /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph2' */
CALDATA const volatile float32 KDAC_CCMaxSpdOfst_kph = 5.0F;
                                      /* Referenced by: '<S1181>/Constant150' */
CALDATA const volatile uint8 KDAC_CCMaxTgtSpdE_kph = 140U;/* Referenced by: '<S1208>/Constant3' */
CALDATA const volatile uint8 KDAC_CCMaxTgtSpdN_kph = 150U;
                                      /* Referenced by: '<S1208>/Constant164' */
CALDATA const volatile uint8 KDAC_CCMaxTgtSpdS_kph = 150U;/* Referenced by: '<S1208>/Constant4' */
CALDATA const volatile uint8 KDAC_CCMaxTgtSpdSnow_kph = 120U;/* Referenced by: '<S1208>/Constant8' */
CALDATA const volatile float32 KDAC_CCMinSpdOfst_kph = 5.0F;
                                      /* Referenced by: '<S1181>/Constant148' */
CALDATA const volatile uint8 KDAC_CCMinTgtSpd_kph = 30U;/* Referenced by: '<S1208>/Constant9' */
CALDATA const volatile float32 KDAC_CCOvrdTqOff_Nm = 5.0F;/* Referenced by: '<S1155>/Constant5' */
CALDATA const volatile float32 KDAC_CCOvrdTqOn_Nm = 20.0F;
                                      /* Referenced by: '<S1155>/Constant174' */
CALDATA const volatile uint8 KDAC_CCSpdChgLongDiv_cnt = 100U;
                         /* Referenced by: '<S1157>/KDAC_CCSpdChgLongDiv_cnt' */
CALDATA const volatile uint8 KDAC_CCSpdChgShort_kph = 1U;
                           /* Referenced by: '<S1157>/KDAC_CCSpdChgShort_kph' */
CALDATA const volatile float32 KDAC_CCTgtSpdChgRate_kphps = 5.0F;
                       /* Referenced by: '<S1157>/KDAC_CCTgtSpdChgRate_kphps' */
CALDATA const volatile float32 KDAC_CCTqReqWhlAchvd_Nm = 100.0F;
                              /* Referenced by: '<S1169>/KDAC_TapDwnTmOut_s2' */
CALDATA const volatile float32 KDAC_CCTqReqWhlDec_Nmps = -10000.0F;
                              /* Referenced by: '<S1169>/KDAC_TapDwnTmOut_s1' */
CALDATA const volatile float32 KDAC_CCTqReqWhlInc_Nmps = 10000.0F;
                              /* Referenced by: '<S1169>/KDAC_TapDwnTmOut_s3' */
CALDATA const volatile uint8 KDAC_CruzSetSwOpCntr_cnt = 2U;/* Referenced by: '<S1210>/Constant4' */
CALDATA const volatile float32 KDAC_CruzSetSwOpTm_s = 1.0F;
                             /* Referenced by: '<S1158>/KDAC_CruzSetSwOpTm_s' */
CALDATA const volatile float32 KDAC_DrvAsstTqSplitEHBMin_Nm = -20.0F;/* Referenced by: '<S1134>/Constant19' */
CALDATA const volatile float32 KDAC_ESCIntvDlyTm4CC_s = 0.8F;/* Referenced by: '<S1181>/Constant1' */
CALDATA const volatile float32 KDAC_ESPActvDlyTm4CC_s = 0.8F;/* Referenced by: '<S1181>/Constant3' */
CALDATA const volatile float32 KDAC_HDCActvSlopOff_pct = -3.0F;/* Referenced by: '<S1229>/Cnst7' */
CALDATA const volatile float32 KDAC_HDCActvSlopOn_pct = -10.0F;/* Referenced by: '<S1229>/Cnst5' */
CALDATA const volatile uint8 KDAC_HDCActvSpdHiOfst_kph = 10U;/* Referenced by: '<S1229>/Cnst10' */
CALDATA const volatile uint8 KDAC_HDCActvSpdHi_kph = 25U;/* Referenced by:
                                                          * '<S1229>/Cnst2'
                                                          * '<S1229>/Cnst3'
                                                          */
CALDATA const volatile uint8 KDAC_HDCActvSpdLoOfst_kph = 3U;/* Referenced by: '<S1229>/Cnst11' */
CALDATA const volatile uint8 KDAC_HDCActvSpdLo_kph = 5U;/* Referenced by:
                                                         * '<S1229>/Cnst4'
                                                         * '<S1229>/Cnst6'
                                                         */
CALDATA const volatile float32 KDAC_HDCDsrdTqIMax_N = 1000.0F;
                                      /* Referenced by: '<S1234>/Saturation1' */
CALDATA const volatile float32 KDAC_HDCDsrdTqIMin_N = -10000.0F;
                                      /* Referenced by: '<S1234>/Saturation1' */
CALDATA const volatile boolean KDAC_HDCFuncEnbl_flg = false;/* Referenced by: '<S1229>/Cnst1' */
CALDATA const volatile uint8 KDAC_HDCStdbyAllwdSpd_kph = 60U;/* Referenced by:
                                                              * '<S1229>/Cnst'
                                                              * '<S1229>/Cnst9'
                                                              */
CALDATA const volatile float32 KDAC_HDCTgtAcceltnFiltCoeff_rat = 0.8F;/* Referenced by: '<S1232>/Cnst5' */
CALDATA const volatile float32 KDAC_HDCTqReqWhlAchvd_Nm = 30.0F;/* Referenced by:
                                                                 * '<S1134>/KDAC_TapDwnTmOut_s2'
                                                                 * '<S1233>/KDAC_TapDwnTmOut_s2'
                                                                 */
CALDATA const volatile float32 KDAC_HDCTqReqWhlDec_Nmps = -2000.0F;/* Referenced by:
                                                                    * '<S1134>/KDAC_TapDwnTmOut_s1'
                                                                    * '<S1233>/KDAC_TapDwnTmOut_s1'
                                                                    */
CALDATA const volatile float32 KDAC_HDCTqReqWhlInc_Nmps = 1500.0F;/* Referenced by:
                                                                   * '<S1134>/KDAC_TapDwnTmOut_s3'
                                                                   * '<S1233>/KDAC_TapDwnTmOut_s3'
                                                                   */
CALDATA const volatile boolean KDAC_OPDTqRespFst_flg = false;/* Referenced by: '<S1134>/Constant15' */
CALDATA const volatile boolean KDAC_OPDTqRespSprt_flg = true;/* Referenced by: '<S1134>/Constant14' */
CALDATA const volatile float32 KDAC_SpdOutRngDlyTm4CC_s = 1.0F;
                                      /* Referenced by: '<S1181>/Constant164' */
CALDATA const volatile float32 KDAC_SpdStabDlyTm4CC_s = 5.0F;/* Referenced by: '<S1197>/Constant8' */
CALDATA const volatile float32 KDAC_SpdUnstabDlyTm4CC_s = 40.0F;/* Referenced by: '<S1197>/Constant4' */
CALDATA const volatile float32 KDAC_TCSActvDlyTm4CC_s = 0.8F;/* Referenced by: '<S1181>/Constant4' */
CALDATA const volatile float32 KDAC_TapDwnTmOut_s = 0.5F;
                               /* Referenced by: '<S1157>/KDAC_TapDwnTmOut_s' */
CALDATA const volatile float32 KDAC_TapUpTmOut_s = 0.5F;
                                /* Referenced by: '<S1157>/KDAC_TapUpTmOut_s' */
CALDATA const volatile float32 KDAC_VehResistA_fac = 143.4F;/* Referenced by:
                                                             * '<S1076>/KDAC_TapDwnTmOut_s4'
                                                             * '<S1167>/KDAC_TapDwnTmOut_s3'
                                                             */
CALDATA const volatile float32 KDAC_VehResistB_fac = 0.774F;/* Referenced by:
                                                             * '<S1076>/KDAC_TapDwnTmOut_s3'
                                                             * '<S1167>/KDAC_TapDwnTmOut_s2'
                                                             */
CALDATA const volatile float32 KDAC_VehResistC_fac = 0.031F;/* Referenced by:
                                                             * '<S1076>/KDAC_TapDwnTmOut_s2'
                                                             * '<S1167>/KDAC_TapDwnTmOut_s1'
                                                             */
CALDATA const volatile float32 KDAC_VirtAccelPedPstnOff_pct = 0.2F;/* Referenced by: '<S1134>/Constant7' */
CALDATA const volatile float32 KDAC_VirtAccelPedPstnOn_pct = 0.5F;/* Referenced by: '<S1134>/Constant6' */
CALDATA const volatile float32 KDAC_WhlSlipDiffSpd4CC_kph = 5.0F;/* Referenced by:
                                                                  * '<S1181>/Constant174'
                                                                  * '<S1181>/Constant6'
                                                                  */
CALDATA const volatile float32 KDAC_WhlSlipDiffSpdOfst4CC_kph = 5.0F;/* Referenced by: '<S1181>/Constant5' */
CALDATA const volatile float32 KDAC_WhlSlipDlyTm4CC_s = 0.5F;/* Referenced by: '<S1181>/Constant8' */
CALDATA const volatile uint16 KDAG_ACCMCRCFltActnMsk_enum = 8192U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s15' */
CALDATA const volatile uint16 KDAG_ACCMHVILActnMsk_enum = 24576U;
                         /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s2' */

/* 压缩机高压互锁故障动作 */
CALDATA const volatile uint16 KDAG_ACCMLostCommActnMsk_enum = 8192U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s38' */

/* ACCM通信丢失级故障动作 */
CALDATA const volatile uint16 KDAG_ACChrgStFailActnMsk_enum = 0U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s24' */

/* ACChargeStateFail故障动作 */
CALDATA const volatile float32 KDAG_ACChrgStFailFailTm_s = 3.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s20' */

/* ACChargeStateFail故障确认时间 */
CALDATA const volatile uint16 KDAG_ACDchaBMSPwrLoActnMsk_enum = 4096U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s21' */

/* AC放电BMS功率低故障动作 */
CALDATA const volatile float32 KDAG_ACDchaBMSPwrLoFailTm_s = 3.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s19' */

/* AC放电BMS功率低确认时间 */
CALDATA const volatile float32 KDAG_ACDchaBMSPwrLo_A = 5.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s18' */

/* AC放电BMS功率低电流能力门槛 */
CALDATA const volatile uint16 KDAG_ACDchaBMSSOCLoActnMsk_enum = 4096U;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s9' */

/* AC放电BMSSOC低故障动作 */
CALDATA const volatile float32 KDAG_ACDchaBMSSOCLoFailTm_s = 3.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s10' */

/* AC放电BMSSOC低确认时间 */
CALDATA const volatile float32 KDAG_ACDchaBMSSOCLo_pct = 15.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s16' */

/* AC放电BMSSOC低触发门槛 */
CALDATA const volatile uint16 KDAG_ACDchaOverPwrActnMsk_enum = 4096U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s23' */

/* AC放电功率超限故障动作 */
CALDATA const volatile float32 KDAG_ACDchaOverPwrFailTm_s = 3.0F;/* Referenced by:
                                                                  * '<S374>/KDAG_BMSCmdTmOutFailTm_s22'
                                                                  * '<S375>/KDAG_BMSCmdTmOutFailTm_s22'
                                                                  */

/* AC放电功率超限确认时间 */
CALDATA const volatile uint16 KDAG_ACSCmdTmOutActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s25' */

/* ACSCmd超时故障动作 */
CALDATA const volatile float32 KDAG_ACSCmdTmOutFailTm_s = 180.0F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s24' */

/* ACSCmd超时故障确认时间 */
CALDATA const volatile float32 KDAG_AccPed1VoltMax_mV = 4250.0F;/* Referenced by:
                                                                 * '<S513>/Constant76'
                                                                 * '<S878>/Constant4'
                                                                 */

/* 加速踏板1路电压过高门槛 */
CALDATA const volatile float32 KDAG_AccPed1VoltMin_mV = 500.0F;/* Referenced by:
                                                                * '<S513>/Constant75'
                                                                * '<S878>/Constant3'
                                                                */

/* 加速踏板1路电压过低门槛 */
CALDATA const volatile float32 KDAG_AccPed2VoltMax_mV = 2200.0F;/* Referenced by:
                                                                 * '<S513>/Constant78'
                                                                 * '<S878>/Constant5'
                                                                 */

/* 加速踏板2路电压过高门槛 */
CALDATA const volatile float32 KDAG_AccPed2VoltMin_mV = 250.0F;/* Referenced by:
                                                                * '<S513>/Constant77'
                                                                * '<S878>/Constant6'
                                                                */

/* 加速踏板2路电压过低门槛 */
CALDATA const volatile uint16 KDAG_AccPedBothFailActnMsk_enum = 114U;
                        /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s23' */

/* 加速踏板双路失效故障动作 */
CALDATA const volatile uint16 KDAG_AccPedCrsChkActnMsk_enum = 114U;
                        /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s21' */

/* 加速踏板双路校验故障动作 */
CALDATA const volatile float32 KDAG_AccPedCrsChkFailTm_s = 0.1F;
                        /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s20' */

/* 加速踏板双路校验偏差确认时间 */
CALDATA const volatile float32 KDAG_AccPedCrsChkThr_pct = 10.0F;/* Referenced by: '<S514>/Constant81' */

/* 加速踏板双路校验偏差门槛 */
CALDATA const volatile uint16 KDAG_AccPedShtCircActnMsk_enum = 116U;/* Referenced by:
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s11'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s15'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s17'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s19'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                     */

/* 加速踏板短路故障动作 */
CALDATA const volatile float32 KDAG_AccPedShtCircFailTm_s = 0.1F;/* Referenced by:
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s12'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s13'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s14'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s16'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s18'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                  */

/* 加速踏板短路确认时间 */
CALDATA const volatile float32 KDAG_AccPedSuplyVoltMax_mV = 5250.0F;/* Referenced by:
                                                                     * '<S513>/Constant36'
                                                                     * '<S513>/Constant72'
                                                                     * '<S878>/Constant2'
                                                                     * '<S878>/Constant7'
                                                                     */

/* 加速踏板供电过高电压门槛 */
CALDATA const volatile float32 KDAG_AccPedSuplyVoltMin_mV = 4750.0F;/* Referenced by:
                                                                     * '<S513>/Constant34'
                                                                     * '<S513>/Constant48'
                                                                     * '<S878>/Constant1'
                                                                     * '<S878>/Constant8'
                                                                     */

/* 加速踏板供电过低电压门槛 */
CALDATA const volatile uint16 KDAG_BACBusOffActnMsk_enum = 0U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s11' */
CALDATA const volatile uint16 KDAG_BMSCRCFltActnMsk_enum = 32505U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s30' */
CALDATA const volatile uint16 KDAG_BMSCmdTmOutActnMsk_enum = 16121U;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s2' */

/* BMS继电器指令响应超时故障动作 */
CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm1_s = 5.0F;
                          /* Referenced by: '<S102>/KDAG_BMSCmdTmOutFailTm_s' */

/* BMS继电器指令响应超时确认时间_非直流充电闭合等待时间 */
CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm2_s = 10.0F;
                         /* Referenced by: '<S102>/KDAG_BMSCmdTmOutFailTm_s1' */

/* BMS继电器指令响应超时确认时间_直流充电闭合等待时间 */
CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm3_s = 10.0F;
                         /* Referenced by: '<S102>/KDAG_BMSCmdTmOutFailTm_s2' */

/* BMS继电器指令响应超时确认时间_BMS自己断开继电器等待时间 */
CALDATA const volatile uint16 KDAG_BMSEmgcySdnActnMsk_enum = 16121U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s11' */

/* BMS紧急下电故障动作 */
CALDATA const volatile float32 KDAG_BMSEmgcySdnFailTm_s = 0.1F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s12' */

/* BMS紧急下电故障确认时间 */
CALDATA const volatile uint16 KDAG_BMSLostCommActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s4' */
CALDATA const volatile uint16 KDAG_BMSSOCLoActnMsk_enum = 114U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s10' */

/* BMSSOC低故障动作 */
CALDATA const volatile float32 KDAG_BMSSOCLoFailTm_s = 1.0F;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s9' */

/* BMSSOC低故障确认时间 */
CALDATA const volatile float32 KDAG_BMSSysFailFailTm_s = 0.1F;/* Referenced by:
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s5'
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s7'
                                                               */

/* BMSFail故障确认时间 */
CALDATA const volatile uint16 KDAG_BMSSysFailLvl2ActnMsk_enum = 116U;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s6' */

/* BMSFailLevel2故障动作 */
CALDATA const volatile uint16 KDAG_BMSSysFailLvl3ActnMsk_enum = 16121U;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s8' */

/* BMSFailLevel3故障动作 */
CALDATA const volatile uint16 KDAG_BMSUndrVoltActnMsk1_enum = 0U;
                        /* Referenced by: '<S104>/KDAG_BMSCmdTmOutFailTm_s13' */

/* BMSPack欠压故障动作_升级前 */
CALDATA const volatile uint16 KDAG_BMSUndrVoltActnMsk2_enum = 0U;
                        /* Referenced by: '<S104>/KDAG_BMSCmdTmOutFailTm_s15' */

/* BMSPack欠压故障动作_升级后 */
CALDATA const volatile float32 KDAG_BMSUndrVoltFailTm_s = 1.0F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s14' */

/* BMSPack欠压故障确认时间 */
CALDATA const volatile uint16 KDAG_BODBusOffActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s2' */
CALDATA const volatile float32 KDAG_BrkPedVoltMax_mV = 4500.0F;/* Referenced by: '<S544>/Constant1' */

/* 制动踏板电压过高门槛 */
CALDATA const volatile float32 KDAG_BrkPedVoltMin_mV = 500.0F;/* Referenced by: '<S544>/Constant48' */

/* 制动踏板电压过低门槛 */
CALDATA const volatile uint16 KDAG_BrkSwCrsChkActnMsk_enum = 112U;
                        /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s23' */

/* 制动开关双路校验故障动作 */
CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntDec_cnt = 1U;/* Referenced by: '<S545>/Constant11' */

/* 制动开关双路校验计数减少步长 */
CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntHi_cnt = 20U;/* Referenced by: '<S545>/Constant1' */

/* 制动开关双路校验计数High_高于此值判定有故障 */
CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntInc_cnt = 1U;/* Referenced by: '<S545>/Constant10' */

/* 制动开关双路校验计数增加步长 */
CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntLo_cnt = 10U;/* Referenced by: '<S545>/Constant3' */

/* 制动开关双路校验计数Low_低于此值判定无故障 */
CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntMax_cnt = 30U;/* Referenced by: '<S545>/Constant12' */

/* 制动开关双路校验计数Max */
CALDATA const volatile float32 KDAG_BrkSwCrsChkIntvlTm_s = 2.0F;/* Referenced by: '<S545>/Constant5' */

/* 两次制动开关校验至少需要间隔的时间 */
CALDATA const volatile float32 KDAG_BrkSwDisagreeTmHi_s = 1.0F;/* Referenced by: '<S545>/Constant4' */

/* 制动开关不一致时间High_高于此值表示此次校验不通过 */
CALDATA const volatile float32 KDAG_BrkSwDisagreeTmLo_s = 0.2F;/* Referenced by: '<S545>/Constant2' */

/* 制动开关不一致时间Low_低于此值表示此次校验通过 */
CALDATA const volatile float32 KDAG_BrkSwDisagreeTmLong_s = 10.0F;/* Referenced by: '<S545>/Constant6' */

/* 制动开关不一致时间Long_高于此值直接报校验故障 */
CALDATA const volatile uint16 KDAG_CCPCRCFltActnMsk_enum = 32U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s13' */
CALDATA const volatile uint16 KDAG_CHABusOffActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s3' */
CALDATA const volatile uint16 KDAG_CRRRCRCFltActnMsk_enum = 64U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s21' */
CALDATA const volatile uint16 KDAG_CellUndrVoltActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s13' */

/* BMSCell欠压故障动作 */
CALDATA const volatile float32 KDAG_CellUndrVoltFailTm_s = 3.0F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s15' */

/* BMSCell欠压故障确认时间 */
CALDATA const volatile uint16 KDAG_DCCCmdTmOutActnMsk1_enum = 0U;
                        /* Referenced by: '<S285>/KDAG_BMSCmdTmOutFailTm_s13' */

/* DCDC模式指令响应超时故障动作_升级前 */
CALDATA const volatile uint16 KDAG_DCCCmdTmOutActnMsk2_enum = 0U;
                        /* Referenced by: '<S285>/KDAG_BMSCmdTmOutFailTm_s15' */

/* DCDC模式指令响应超时故障动作_升级后 */
CALDATA const volatile float32 KDAG_DCCCmdTmOutFailTm_s = 5.0F;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s14' */

/* DCDC模式指令响应超时故障确认时间 */
CALDATA const volatile uint16 KDAG_DCCInVoltLoActnMsk_enum = 0U;
                         /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDC输入电压低故障动作 */
CALDATA const volatile float32 KDAG_DCCInVoltLoFailTm_s = 3.0F;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s13' */

/* DCDC输入电压低故障确认时间 */
CALDATA const volatile uint16 KDAG_DCCModeFltActnMsk1_enum = 0U;
                         /* Referenced by: '<S287>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDCModeFault故障动作_升级前 */
CALDATA const volatile uint16 KDAG_DCCModeFltActnMsk2_enum = 0U;
                        /* Referenced by: '<S287>/KDAG_BMSCmdTmOutFailTm_s11' */

/* DCDCModeFault故障动作_升级后 */
CALDATA const volatile float32 KDAG_DCCModeFltFailTm_s = 60.0F;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s12' */

/* DCDCModeFault故障确认时间 */
CALDATA const volatile float32 KDAG_DCCSysFailFailTm_s = 1.5F;/* Referenced by:
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s5'
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s7'
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s9'
                                                               */

/* DCDCFail故障确认时间 */
CALDATA const volatile uint16 KDAG_DCCSysFailLvl3ActnMsk1_enum = 594U;
                         /* Referenced by: '<S286>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDCFaillevel3故障动作_升级前 */
CALDATA const volatile uint16 KDAG_DCCSysFailLvl3ActnMsk2_enum = 633U;
                         /* Referenced by: '<S286>/KDAG_BMSCmdTmOutFailTm_s8' */

/* DCDCFaillevel3故障动作_升级后 */
CALDATA const volatile float32 KDAG_DCCSysFailLvl3FailTm_s = 60.0F;
                         /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s6' */

/* DCDCFaillevel3故障确认时间 */
CALDATA const volatile uint16 KDAG_DCCSysFailLvl4ActnMsk_enum = 16121U;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s10' */

/* DCDCFaillevel4故障动作 */
CALDATA const volatile uint16 KDAG_DCSChrgReqActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s21' */

/* DCSChargeRequest故障动作 */
CALDATA const volatile float32 KDAG_DCSChrgReqFailTm_s = 1.0F;/* Referenced by:
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s20'
                                                               * '<S770>/Constant5'
                                                               */

/* DCSChargeRequest故障确认时间 */
CALDATA const volatile uint16 KDAG_DCSCmdTmOutActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s27' */

/* DCSCmd超时故障动作 */
CALDATA const volatile float32 KDAG_DCSCmdTmOutFailTm_s = 180.0F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s17' */

/* DCSCmd超时故障确认时间 */
CALDATA const volatile uint16 KDAG_DCSFailStaActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s28' */

/* DCSFailState故障动作 */
CALDATA const volatile float32 KDAG_DCSFailStaFailTm_s = 0.2F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s16' */

/* DCSFailState故障确认时间 */
CALDATA const volatile uint16 KDAG_DCSInletConnectActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s19' */

/* DCS插枪状态故障动作 */
CALDATA const volatile float32 KDAG_DCSInletConnectFailTm_s = 1.0F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s18' */

/* DCS插枪状态故障确认时间 */
CALDATA const volatile uint16 KDAG_DCSModeFailActnMsk_enum = 0U;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s23' */

/* DCSModeFail故障动作 */
CALDATA const volatile float32 KDAG_DCSModeFailFailTm_s = 0.2F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s22' */

/* DCSModeFail故障确认时间 */
CALDATA const volatile uint8 KDAG_Did0xF163WrtData_cnt[4] = { 0U, 1U, 0U, 1U } ;/* Referenced by: '<S99>/DidData3' */

/* CCU_FlashDriver软件 */
CALDATA const volatile uint8 KDAG_Did0xF180WrtData_cnt[4] = { 0U, 1U, 0U, 1U } ;/* Referenced by: '<S99>/DidData2' */

/* CCU_Boot软件 */
CALDATA const volatile uint8 KDAG_Did0xF187WrtData_cnt[2] = { 0U, 2U } ;/* Referenced by: '<S99>/DidData' */

/* 总成号 */
CALDATA const volatile uint8 KDAG_Did0xF188WrtData_cnt[4] = { 0U, 1U, 0U, 1U } ;/* Referenced by: '<S99>/DidData4' */

/* CCU_App软件 */
CALDATA const volatile uint8 KDAG_Did0xF191WrtData_cnt[4] = { 0U, 1U, 0U, 1U } ;/* Referenced by: '<S99>/DidData1' */

/* CCU硬件 */
CALDATA const volatile uint16 KDAG_EHBCRCFltActnMsk_enum = 114U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s34' */
CALDATA const volatile float32 KDAG_EHBFltFailTm_s = 0.5F;/* Referenced by:
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s17'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s4'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s5'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s7'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s9'
                                                           */

/* EHB故障确认时间 */
CALDATA const volatile uint16 KDAG_EHBFltLvl2ActnMsk_enum = 112U;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s6' */

/* EHB2级故障动作 */
CALDATA const volatile uint16 KDAG_EHBFltLvl3ActnMsk_enum = 112U;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s8' */

/* EHB3级故障动作 */
CALDATA const volatile uint16 KDAG_EHBFltLvl4ActnMsk_enum = 114U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s18' */

/* EHB4级故障动作 */
CALDATA const volatile uint16 KDAG_EHBFltLvl5ActnMsk_enum = 114U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s10' */

/* EHB5级故障动作 */
CALDATA const volatile uint16 KDAG_EHBLostCommActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s7' */
CALDATA const volatile uint16 KDAG_EPTBusOffActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s1' */
CALDATA const volatile uint16 KDAG_ESCCRCFltActnMsk_enum = 114U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s35' */
CALDATA const volatile float32 KDAG_ESCFltFailTm_s = 0.5F;/* Referenced by:
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s14'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s19'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s20'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s22'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s24'
                                                           */

/* ESC故障确认时间 */
CALDATA const volatile uint16 KDAG_ESCFltLvl2ActnMsk_enum = 112U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s21' */

/* ESC2级故障动作 */
CALDATA const volatile uint16 KDAG_ESCFltLvl3ActnMsk_enum = 112U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s23' */

/* ESC3级故障动作 */
CALDATA const volatile uint16 KDAG_ESCFltLvl4ActnMsk_enum = 114U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s15' */

/* ESC4级故障动作 */
CALDATA const volatile uint16 KDAG_ESCFltLvl5ActnMsk_enum = 114U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s12' */

/* ESC5级故障动作 */
CALDATA const volatile uint16 KDAG_ESCLostCommActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s5' */
CALDATA const volatile uint16 KDAG_ESCVehSpdInvldActnMsk_enum = 0U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s13' */

/* 车速失效故障动作 */
CALDATA const volatile float32 KDAG_ESCVehSpdInvldFailTm_s = 0.5F;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s3' */

/* 车速失效确认时间 */
CALDATA const volatile boolean KDAG_EmgcyShtdwnOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg9' */
CALDATA const volatile boolean KDAG_EmgcyShtdwnOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg9' */
CALDATA const volatile uint16 KDAG_FCMCRCFltActnMsk_enum = 64U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s24' */
CALDATA const volatile uint16 KDAG_FCMLostCommActnMsk_enum = 64U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s37' */

/* FCM通信丢失级故障动作 */
CALDATA const volatile boolean KDAG_FanFullSpdOnOvrdSw_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg17' */
CALDATA const volatile boolean KDAG_FanFullSpdOnOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg17' */
CALDATA const volatile boolean KDAG_FbdACCOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg7' */
CALDATA const volatile boolean KDAG_FbdACCOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg7' */
CALDATA const volatile boolean KDAG_FbdACChrgOvrdSw_flg = true;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg11' */
CALDATA const volatile boolean KDAG_FbdACChrgOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg11' */
CALDATA const volatile boolean KDAG_FbdACDchaOvrdSw_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg13' */
CALDATA const volatile boolean KDAG_FbdACDchaOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg13' */
CALDATA const volatile boolean KDAG_FbdACOvrdSw_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg14' */
CALDATA const volatile boolean KDAG_FbdACOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg14' */
CALDATA const volatile boolean KDAG_FbdCCOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg5' */
CALDATA const volatile boolean KDAG_FbdCCOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg5' */
CALDATA const volatile boolean KDAG_FbdDCChrgOvrdSw_flg = true;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg12' */
CALDATA const volatile boolean KDAG_FbdDCChrgOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg12' */
CALDATA const volatile boolean KDAG_FbdDCDCOvrdSw_flg = true;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg10' */
CALDATA const volatile boolean KDAG_FbdDCDCOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg10' */
CALDATA const volatile boolean KDAG_FbdDRGrOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg4' */
CALDATA const volatile boolean KDAG_FbdDRGrOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg4' */
CALDATA const volatile boolean KDAG_FbdDrvTqOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg2' */
CALDATA const volatile boolean KDAG_FbdDrvTqOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg2' */
CALDATA const volatile boolean KDAG_FbdHVOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg8' */
CALDATA const volatile boolean KDAG_FbdHVOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg8' */
CALDATA const volatile boolean KDAG_FbdLSPOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg6' */
CALDATA const volatile boolean KDAG_FbdLSPOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg6' */
CALDATA const volatile boolean KDAG_FltLampOnOvrdSw_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg15' */
CALDATA const volatile boolean KDAG_FltLampOnOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg15' */
CALDATA const volatile uint16 KDAG_FrstHVILVoltChkActnMsk1_enum = 16498U;/* Referenced by:
                                                                      * '<S561>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                      * '<S562>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                      */

/* 主要高压互锁故障动作1 */
CALDATA const volatile uint16 KDAG_FrstHVILVoltChkActnMsk2_enum = 32505U;/* Referenced by:
                                                                      * '<S561>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      * '<S562>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      */

/* 主要高压互锁故障动作2 */
CALDATA const volatile float32 KDAG_FrstHVILVoltMax_mV = 6000.0F;/* Referenced by: '<S561>/Constant75' */

/* 主要高压互锁电压过高门槛 */
CALDATA const volatile float32 KDAG_FrstHVILVoltMin_mV = 4000.0F;/* Referenced by: '<S562>/Constant75' */

/* 主要高压互锁电压过低门槛 */
CALDATA const volatile float32 KDAG_GearShftInvldFailTm1_s = 1.0F;
                          /* Referenced by: '<S476>/KDAG_BMSCmdTmOutFailTm_s' */

/* 换挡输入失效故障确认时间1 */
CALDATA const volatile float32 KDAG_GearShftInvldFailTm2_s = 120.0F;
                         /* Referenced by: '<S476>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 换挡输入失效故障确认时间2 */
CALDATA const volatile float32 KDAG_HVAccAcptBMSVoltFac_c = 0.7F;/* Referenced by:
                                                                  * '<S278>/KDAG_BMSCmdTmOutFailTm_s19'
                                                                  * '<S278>/KDAG_BMSCmdTmOutFailTm_s2'
                                                                  * '<S752>/Constant1'
                                                                  */

/* 高压部件电压与电池电压比值的可接受比例系数 */
CALDATA const volatile float32 KDAG_HVILVoltChkFailTm_s = 0.2F;/* Referenced by:
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s10'
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s3'
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s9'
                                                                */

/* 高压互锁故障确认时间 */
CALDATA const volatile uint16 KDAG_HVIsoResistLoActnMsk_enum = 16121U;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 高压电池绝缘故障动作 */
CALDATA const volatile float32 KDAG_HVIsoResistLoFailTm_s = 25.0F;
                          /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s' */

/* 高压电池绝缘故障阻值低确认时间 */
CALDATA const volatile float32 KDAG_HVIsoResistLoPassTm_s = 5.0F;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s3' */

/* 高压电池绝缘故障阻值低恢复时间 */
CALDATA const volatile float32 KDAG_HVIsoResistLoThr_kOhm = 5.0F;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s26' */

/* 高压电池绝缘故障阻值门槛 */
CALDATA const volatile uint16 KDAG_INVCRCFltActnMsk_enum = 32505U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s32' */
CALDATA const volatile float32 KDAG_INVFltFailTm_s = 0.1F;/* Referenced by:
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s4'
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s5'
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s7'
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s9'
                                                           */

/* INVFault故障确认时间 */
CALDATA const volatile uint16 KDAG_INVFltLvl2ActnMsk_enum = 116U;
                         /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s6' */

/* INVFaultLevel2故障动作 */
CALDATA const volatile uint16 KDAG_INVFltLvl3ActnMsk_enum = 16505U;
                         /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s8' */

/* INVFaultLevel3故障动作 */
CALDATA const volatile uint16 KDAG_INVFltLvl4ActnMsk_enum = 32505U;
                        /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s10' */

/* INVFaultLevel4故障动作 */
CALDATA const volatile uint16 KDAG_INVInVoltLoActnMsk_enum = 0U;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s17' */

/* INV输入电压低故障动作 */
CALDATA const volatile float32 KDAG_INVInVoltLoFailTm_s = 3.0F;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s18' */

/* INV输入电压低故障确认时间 */
CALDATA const volatile uint16 KDAG_INVLostCommActnMsk_enum = 0U;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s6' */
CALDATA const volatile uint16 KDAG_INVRunCmdRespActnMsk_enum = 0U;
                        /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s11' */

/* INVRun指令响应超时故障动作 */
CALDATA const volatile float32 KDAG_INVRunCmdRespFailTm_s = 0.5F;
                        /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s12' */

/* INVRun指令响应超时故障确认时间 */
CALDATA const volatile uint16 KDAG_IPUCRCFltActnMsk_enum = 32377U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s36' */
CALDATA const volatile uint16 KDAG_IPULostCommActnMsk1_enum = 114U;
                         /* Referenced by: '<S238>/KDAG_BMSCmdTmOutFailTm_s1' */
CALDATA const volatile uint16 KDAG_IPULostCommActnMsk2_enum = 32377U;
                         /* Referenced by: '<S238>/KDAG_BMSCmdTmOutFailTm_s9' */
CALDATA const volatile boolean KDAG_LVBatLampOnOvrdSw_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg16' */
CALDATA const volatile boolean KDAG_LVBatLampOnOvrdVal_flg = false;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg16' */
CALDATA const volatile float32 KDAG_LVBatVoltHiRec_V = 16.5F;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s5' */

/* 蓄电池过压恢复门槛 */
CALDATA const volatile float32 KDAG_LVBatVoltHi_V = 17.0F;/* Referenced by:
                                                           * '<S497>/KDAG_BMSCmdTmOutFailTm_s8'
                                                           * '<S544>/KDAG_BMSCmdTmOutFailTm_s8'
                                                           */

/* 蓄电池过压触发门槛 */
CALDATA const volatile float32 KDAG_LVBatVoltLoRec_V = 9.5F;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s4' */

/* 蓄电池欠压恢复门槛 */
CALDATA const volatile float32 KDAG_LVBatVoltLo_V = 9.0F;/* Referenced by:
                                                          * '<S497>/KDAG_BMSCmdTmOutFailTm_s7'
                                                          * '<S544>/KDAG_BMSCmdTmOutFailTm_s7'
                                                          */

/* 蓄电池欠压触发门槛 */
CALDATA const volatile float32 KDAG_LVBatVoltPassbl_V = 11.0F;
                        /* Referenced by: '<S506>/KDAG_BMSCmdTmOutFailTm_s15' */

/* 蓄电池电压尚可门槛 */
CALDATA const volatile float32 KDAG_LVBattSOCLoFailTm_s = 10.0F;
                        /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s18' */

/* 蓄电池SOC低确认时间 */
CALDATA const volatile uint8 KDAG_LVBattSOCLo_pct = 60U;/* Referenced by: '<S497>/Constant77' */

/* 蓄电池SOC低门槛 */
CALDATA const volatile float32 KDAG_LVBattSOHLoFailTm_s = 10.0F;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 蓄电池SOH低确认时间 */
CALDATA const volatile uint8 KDAG_LVBattSOHLo_pct = 30U;/* Referenced by: '<S497>/Constant78' */

/* 蓄电池SOH低门槛 */
CALDATA const volatile uint16 KDAG_LVBattTempHiActnMsk1_enum = 0U;
                        /* Referenced by: '<S506>/KDAG_BMSCmdTmOutFailTm_s13' */

/* 蓄电池过温故障动作_升级前 */
CALDATA const volatile uint16 KDAG_LVBattTempHiActnMsk2_enum = 0U;
                         /* Referenced by: '<S506>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 蓄电池过温故障动作_升级后 */
CALDATA const volatile float32 KDAG_LVBattTempHiFailTm_s = 60.0F;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s2' */

/* 蓄电池过温确认时间 */
CALDATA const volatile float32 KDAG_LVBattTempHi_C = 105.0F;/* Referenced by: '<S506>/Constant40' */

/* 蓄电池过温温度门槛 */
CALDATA const volatile float32 KDAG_LVBattVoltExcdFailTm_s = 10.0F;/* Referenced by:
                                                                    * '<S497>/KDAG_BMSCmdTmOutFailTm_s3'
                                                                    * '<S497>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                    */

/* 蓄电池欠压过压确认时间 */
CALDATA const volatile boolean KDAG_LimpHomeOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg1' */
CALDATA const volatile boolean KDAG_LimpHomeOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg1' */
CALDATA const volatile boolean KDAG_LmtDrvTqOvrdSw_flg = false;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg3' */
CALDATA const volatile boolean KDAG_LmtDrvTqOvrdVal_flg = false;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg3' */
CALDATA const volatile uint8 KDAG_ManlClrDTCReq_enum = 0U;
                         /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph1' */

/* 手动清除所有故障的标定_从0改成255时触发起一次作用 */
CALDATA const volatile uint16 KDAG_OBCChrgReqActnMsk_enum = 0U;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s7' */

/* OBCChargeRequest故障动作 */
CALDATA const volatile float32 KDAG_OBCChrgReqFailTm_s = 30.0F;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s8' */

/* OBCChargeRequest故障确认时间 */
CALDATA const volatile uint16 KDAG_OBCConnectTmOutActnMsk_enum = 0U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s25' */

/* OBC连接超时故障动作 */
CALDATA const volatile float32 KDAG_OBCConnectTmOutFailTm1_s = 180.0F;
                          /* Referenced by: '<S409>/KDAG_BMSCmdTmOutFailTm_s' */

/* OBC连接超时故障等待时间_连接前 */
CALDATA const volatile float32 KDAG_OBCConnectTmOutFailTm2_s = 3.0F;
                         /* Referenced by: '<S409>/KDAG_BMSCmdTmOutFailTm_s1' */

/* OBC连接超时故障等待时间_连接后断开 */
CALDATA const volatile uint16 KDAG_OBCInletConnectActnMsk_enum = 0U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s11' */

/* OBC插枪状态故障动作 */
CALDATA const volatile float32 KDAG_OBCInletConnectFailTm_s = 3.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s12' */

/* OBC插枪状态故障确认时间 */
CALDATA const volatile uint16 KDAG_OBCModeMsmtchActnMsk_enum = 0U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s27' */

/* OBC模式不匹配故障动作 */
CALDATA const volatile float32 KDAG_OBCModeMsmtchFailTm_s = 90.0F;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s26' */

/* OBC模式不匹配故障确认时间 */
CALDATA const volatile uint16 KDAG_OBCS2StatActnMsk_enum = 0U;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s5' */

/* OBCS2连接超时故障动作 */
CALDATA const volatile float32 KDAG_OBCS2StatFailTm_s = 6.0F;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s6' */

/* OBCS2连接超时故障确认时间 */
CALDATA const volatile float32 KDAG_OBCSysFailFailTm_s = 3.0F;/* Referenced by:
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s14'
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s15'
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s17'
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               */

/* OBCFail故障确认时间 */
CALDATA const volatile uint16 KDAG_OBCSysFailLvl4ActnMsk_enum = 16121U;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s13' */

/* OBCFailLevel4故障动作 */
CALDATA const volatile uint16 KDAG_SCSCRCFltActnMsk_enum = 80U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s19' */
CALDATA const volatile uint16 KDAG_SCSLostCommActnMsk_enum = 80U;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s39' */

/* SCS通信丢失级故障动作 */
CALDATA const volatile uint16 KDAG_SecdHVILVoltHiActnMsk_enum = 16384U;
                        /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s11' */

/* 次要高压互锁电压高故障动作 */
CALDATA const volatile uint16 KDAG_SecdHVILVoltLoActnMsk_enum = 16384U;
                         /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s4' */

/* 次要高压互锁电压低故障动作 */
CALDATA const volatile float32 KDAG_SecdHVILVoltMax_mV = 6000.0F;/* Referenced by: '<S544>/Constant2' */

/* 次要高压互锁电压过高门槛 */
CALDATA const volatile float32 KDAG_SecdHVILVoltMin_mV = 4000.0F;/* Referenced by: '<S544>/Constant75' */

/* 次要高压互锁电压过低门槛 */
CALDATA const volatile float32 KDAG_SysPwrModeInvldFailTm_s = 3.0F;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s1' */

/* PowerMode失效确认时间 */
CALDATA const volatile uint16 KDAG_TMSFailLvl3ActnMsk_enum = 0U;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s11' */

/* TMSRFailLevel3故障动作 */
CALDATA const volatile float32 KDAG_TMSFailLvl3FailTm_s = 0.5F;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s16' */

/* TMSRFailLevel3故障确认时间 */
CALDATA const volatile uint16 KDAG_VehCrashActnMsk_enum = 15737U;
                         /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s2' */

/* 碰撞故障动作 */
CALDATA const volatile float32 KDAG_VehSpdLo_kph = 3.0F;/* Referenced by: '<S89>/Constant2' */

/* 低车速门槛，用于故障升级 */
CALDATA const volatile boolean KDAG_VehStandStillBypasBrk_flg = true;
                         /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph2' */

/* 驻车清除故障不看刹车的标定量_建议标成1不用看刹车_满足停车和PN挡即可 */
CALDATA const volatile float32 KDAG_VehStandStillSpd_kph = 0.5F;
                          /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph' */

/* 驻车清除故障的车速门槛_需基本绝对停止 */
CALDATA const volatile float32 KDAG_WakeUpDlyTm_s = 0.1F;
                         /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph3' */

/* 唤醒源拉高的信号延迟时间_即诊断开始的延迟时间 */
CALDATA const volatile uint32 KDAG_WaterTempAbvThr_Ohm = 500U;/* Referenced by: '<S578>/Constant1' */

/* 冷却水温过高的电阻门槛 */
CALDATA const volatile uint32 KDAG_WaterTempBlwThr_Ohm = 5000001U;/* Referenced by: '<S578>/Constant75' */

/* 冷却水温过低的电阻门槛 */
CALDATA const volatile float32 KDAG_WaterTempExcdThrFailTm_s = 0.25F;/* Referenced by:
                                                                      * '<S578>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      * '<S578>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                      */

/* 冷却水温异常的确认时间 */
CALDATA const volatile float32 KDSA_AcceltnIdxAvgInit_pct = 40.0F;/* Referenced by: '<S17>/Unit Delay2' */
CALDATA const volatile float32 KDSA_AcceltnIdxDecRate_pctps = -0.2F;
                      /* Referenced by: '<S17>/KVTM_AcceltnIdxIncRate_pctps1' */
CALDATA const volatile float32 KDSA_AcceltnIdxIncRate_pctps = 1.0F;
                       /* Referenced by: '<S17>/KVTM_AcceltnIdxIncRate_pctps' */
CALDATA const volatile float32 KDSA_BrkPedPstnAvgInit_pct = 0.0F;/* Referenced by: '<S17>/Unit Delay4' */
CALDATA const volatile float32 KDSA_BrkPedPstnDecRate_pctps = -1.0F;
                       /* Referenced by: '<S17>/KVTM_BrkPedPstnDecRate_pctps' */
CALDATA const volatile float32 KDSA_BrkPedPstnIncRate_pctps = 5.0F;
                       /* Referenced by: '<S17>/KVTM_BrkPedPstnIncRate_pctps' */
CALDATA const volatile float32 KDSA_DrvSprtIdxMax_pct = 100.0F;/* Referenced by: '<S17>/Saturation2' */
CALDATA const volatile float32 KDSA_DrvSprtIdxMin_pct = 0.0F;/* Referenced by: '<S17>/Saturation2' */
CALDATA const volatile float32 KDSA_SprtIdxBrkPedRstSpd_kph = 4.0F;
                         /* Referenced by: '<S17>/KVTM_SDSHldVehSpd4Brk_kph1' */
CALDATA const volatile float32 KDSA_SprtIdxBrkPedRstTm_s = 120.0F;
                          /* Referenced by: '<S17>/KVTM_AccelPedRlsdDlyTm_s1' */
CALDATA const volatile float32 KDSA_SprtIdxBrkPedRstVal_pct = 5.0F;
                          /* Referenced by: '<S17>/KVTM_AccelPedRlsdDlyTm_s2' */
CALDATA const volatile float32 KDSA_SprtIdxHldAccPed4Acc_pct = 3.0F;
                         /* Referenced by: '<S17>/KVTM_SDSHoldAccPedPstn_pct' */
CALDATA const volatile float32 KDSA_SprtIdxHldAccPed4Brk_pct = 2.0F;
                          /* Referenced by: '<S17>/KVTM_SDSHldAccPed4Brk_pct' */
CALDATA const volatile float32 KDSA_SprtIdxHldAccPedRlsDlyTm4Brk_s = 15.0F;
                           /* Referenced by: '<S17>/KVTM_AccelPedRlsdDlyTm_s' */
CALDATA const volatile float32 KDSA_SprtIdxHldAcceltn4Acc_mps2 = -0.2F;
                             /* Referenced by: '<S17>/KVTM_SDSHldDchaPwr_kW2' */
CALDATA const volatile float32 KDSA_SprtIdxHldDchaPwr_kW = -999.0F;
                              /* Referenced by: '<S17>/KVTM_SDSHldDchaPwr_kW' */
CALDATA const volatile float32 KDSA_SprtIdxHldVehSpd4Acc_kph = 5.0F;
                             /* Referenced by: '<S17>/KVTM_SDSHldDchaPwr_kW1' */
CALDATA const volatile float32 KDSA_SprtIdxHldVehSpd4Brk_kph = 10.0F;
                          /* Referenced by: '<S17>/KVTM_SDSHldVehSpd4Brk_kph' */
CALDATA const volatile float32 KDSA_SprtIdxHldWhlTq4Acc_Nm = 30.0F;
                               /* Referenced by: '<S17>/KVTM_SDSHoldWhlTq_Nm' */
CALDATA const volatile boolean KDSA_UseTqCalcAcceltn_flg = true;
                          /* Referenced by: '<S17>/KVTM_UseTqCalcAcceltn_flg' */
CALDATA const volatile float32 KEMS_AccPwrDecFiltCoeff_c = 0.9F;
                           /* Referenced by: '<S28>/KVTM_LimpHomeOvrdSw_flg3' */

/* 放电附件功率滤波系数（只滤下降） */
CALDATA const volatile float32 KEMS_AccPwrIncFiltCoeff_c = 0.9F;
                           /* Referenced by: '<S26>/KVTM_LimpHomeOvrdSw_flg4' */

/* 充电附件功率滤波系数（只滤上降） */
CALDATA const volatile float32 KEMS_CellTempSynDecRate_Cps = -0.5F;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg6' */

/* 电芯温度下降斜率 */
CALDATA const volatile float32 KEMS_CellTempSynIncRate_Cps = 0.5F;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg7' */

/* 电芯温度上升斜率 */
CALDATA const volatile float32 KEMS_ChrgCurFbKiMax_A = 300.0F;/* Referenced by: '<S81>/Saturation' */

/* 充电KI上限限制 */
CALDATA const volatile float32 KEMS_ChrgCurFbKiMin_A = 0.0F;/* Referenced by: '<S81>/Saturation' */

/* 充电KI下限限制 */
CALDATA const volatile float32 KEMS_ChrgCurFbMax_A = 500.0F;/* Referenced by: '<S81>/Saturation2' */

/* 充电KP+KI上限限制 */
CALDATA const volatile float32 KEMS_ChrgCurFbMin_A = 0.0F;/* Referenced by: '<S81>/Saturation2' */

/* 充电KP+KI下限限制 */
CALDATA const volatile float32 KEMS_ChrgFbActvDlyTm_s = 2.0F;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg2' */

/* 充电功率闭环退出延迟时间 */
CALDATA const volatile float32 KEMS_ChrgPwr2MotRawFiltCoeff_c = 0.9F;
                           /* Referenced by: '<S26>/KVTM_LimpHomeOvrdSw_flg5' */

/* 充电总功率滤波系数（只滤下降） */
CALDATA const volatile float32 KEMS_ChrgPwrFbFiltCoeff_c = 0.8F;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg3' */

/* 充电功率闭环滤波系数 */
CALDATA const volatile float32 KEMS_ChrgPwrFbKiMax_kW = 20.0F;/* Referenced by: '<S46>/Saturation' */

/* 充电功率闭环KI上限限制 */
CALDATA const volatile float32 KEMS_ChrgPwrFbKiMin_kW = 0.0F;/* Referenced by: '<S46>/Saturation' */

/* 充电功率闭环KI下限限制 */
CALDATA const volatile float32 KEMS_ChrgPwrFbMax_kW = 30.0F;/* Referenced by: '<S46>/Saturation2' */

/* 充电功率闭环KI+KP上限限制 */
CALDATA const volatile float32 KEMS_ChrgPwrFbMin_kW = 0.0F;/* Referenced by: '<S46>/Saturation2' */

/* 充电功率闭环KI+KP下限限制 */
CALDATA const volatile float32 KEMS_ChrgPwrFbOff_kW = -10.0F;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg1' */

/* 充电功率闭环进入阀值 */
CALDATA const volatile float32 KEMS_ChrgPwrFbOn_kW = -5.0F;
                          /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg15' */

/* 充电功率闭环退出阀值 */
CALDATA const volatile float32 KEMS_DCCSurgePwr_kW = 0.5F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg2' */

/* DCC涌动功率 */
CALDATA const volatile float32 KEMS_DchaCurFbKiMax_A = 0.0F;/* Referenced by: '<S82>/Saturation' */

/* 放电Ki上限限制 */
CALDATA const volatile float32 KEMS_DchaCurFbKiMin_A = -450.0F;/* Referenced by: '<S82>/Saturation' */

/* 放电Ki下限限制 */
CALDATA const volatile float32 KEMS_DchaCurFbMax_A = 0.0F;/* Referenced by: '<S82>/Saturation2' */

/* 放电KP+Ki上限限制 */
CALDATA const volatile float32 KEMS_DchaCurFbMin_A = -650.0F;/* Referenced by: '<S82>/Saturation2' */

/* 放电KP+Ki下限限制 */
CALDATA const volatile float32 KEMS_DchaFbActvDlyTm_s = 2.0F;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg2' */

/* 放电功率闭环退出延迟时间 */
CALDATA const volatile float32 KEMS_DchaPwr2MotRawFiltCoeff_c = 0.9F;
                           /* Referenced by: '<S28>/KVTM_LimpHomeOvrdSw_flg2' */

/* 放电总功率滤波系数（只滤上升） */
CALDATA const volatile float32 KEMS_DchaPwrFbFiltCoeff_c = 0.8F;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg3' */

/* 放电功率闭环滤波系数 */
CALDATA const volatile float32 KEMS_DchaPwrFbKiMax_kW = 0.0F;/* Referenced by: '<S64>/Saturation' */

/* 放电功率闭环KI上限限制 */
CALDATA const volatile float32 KEMS_DchaPwrFbKiMin_kW = -20.0F;/* Referenced by: '<S64>/Saturation' */

/* 放电功率闭环KI下限限制 */
CALDATA const volatile float32 KEMS_DchaPwrFbMax_kW = 0.0F;/* Referenced by: '<S64>/Saturation2' */

/* 放电功率闭环KI+KP上限限制 */
CALDATA const volatile float32 KEMS_DchaPwrFbMin_kW = -30.0F;/* Referenced by: '<S64>/Saturation2' */

/* 放电功率闭环KI+KP下限限制 */
CALDATA const volatile float32 KEMS_DchaPwrFbOff_kW = 10.0F;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg1' */

/* 放电功率闭环退出阀值 */
CALDATA const volatile float32 KEMS_DchaPwrFbOn_kW = 5.0F;
                          /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg15' */

/* 放电功率闭环进入阀值 */
CALDATA const volatile float32 KEMS_HVBatActCurrExcdThr_A = -800.0F;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg1' */

/* 实际电流异常超限值 */
CALDATA const volatile float32 KEMS_HVBatActCurrExcdVal_A = 500.0F;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg2' */

/* 实际电流异常超限替代值（驱动超限） */
CALDATA const volatile float32 KEMS_HVBatCurrBelowConChrgDlyTm_s = 60.0F;
                         /* Referenced by: '<S26>/KTQC_DrvTqLoEnblRBSThr_Nm1' */

/* Con持续回收切Ins瞬时回收 */
CALDATA const volatile float32 KEMS_HVBatCurrBelowConDlyTm_s = 60.0F;
                         /* Referenced by: '<S28>/KTQC_DrvTqLoEnblRBSThr_Nm1' */

/* Con持续切Ins瞬时 */
CALDATA const volatile float32 KEMS_HVBatCurrOverConChrgDlyTm_s = 6000.0F;
                         /* Referenced by: '<S26>/KTQC_DrvTqLoEnblRBSThr_Nm3' */

/* Ins瞬时回收切Con持续回收 */
CALDATA const volatile float32 KEMS_HVBatCurrOverConDlyTm_s = 6000.0F;
                         /* Referenced by: '<S28>/KTQC_DrvTqLoEnblRBSThr_Nm3' */

/* Ins瞬时切Con持续 */
CALDATA const volatile float32 KEMS_MaxChrgCurDecRate_Aps = -25.0F;
                        /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltCoeff_c1' */

/* 最大充电电流下降斜率 */
CALDATA const volatile float32 KEMS_MaxChrgCurFiltAchvd_A = 5.0F;
                        /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltAchvd_Nm' */

/* 最大充电电流滤波结束值 */
CALDATA const volatile float32 KEMS_MaxChrgCurIncRate_Aps = 50.0F;
                         /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltCoeff_c' */

/* 最大充电电流上升斜率 */
CALDATA const volatile float32 KEMS_MaxDchaCurDecRate_Aps = -75.0F;
                        /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltCoeff_c1' */

/* 最大放电电流下降斜率 */
CALDATA const volatile float32 KEMS_MaxDchaCurFiltAchvd_A = 5.0F;
                        /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltAchvd_Nm' */

/* 最大放电电流滤波结束值 */
CALDATA const volatile float32 KEMS_MaxDchaCurIncRate_Aps = 25.0F;
                         /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltCoeff_c' */

/* 最大放电电流上升斜率 */
CALDATA const volatile float32 KEMS_TMSActSOCOff_pct = 3.0F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg5' */

/* 关系TMS工作SOC阀值 */
CALDATA const volatile float32 KEMS_TMSActSOCOn_pct = 5.0F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg4' */

/* 允许TMS工作SOC阀值 */
CALDATA const volatile float32 KEMS_TMSMaxPwrLim_kW = 10.0F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg6' */

/* TMS最大允许使用功率 */
CALDATA const volatile float32 KEMS_TMSPwrEnblOff_kW = 0.5F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg3' */

/* 关闭TMS工作功率阀值 */
CALDATA const volatile float32 KEMS_TMSPwrEnblOn_kW = 1.0F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg1' */

/* 允许TMS工作功率阀值 */
CALDATA const volatile float32 KEMS_TMSPwrOffDlyTm_s = 1.8F;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg8' */

/* 关闭TMS工作功率确认时间 */
CALDATA const volatile boolean KGSM_DRFlt2NSw_flg = false;/* Referenced by: '<S1531>/Constant3' */

/* 驱动档故障进N档强控 */
CALDATA const volatile boolean KGSM_DRFlt2NVal_flg = false;/* Referenced by: '<S1531>/Constant2' */

/* 驱动档故障进N档-观测量：VGSM_DRFlt2N_flg */
CALDATA const volatile float32 KGSM_EPBApld2PDlyTm_s = 2.0F;/* Referenced by: '<S1569>/Constant4' */

/* 规范：EPB拉起入P需求判断时间阈值 */
CALDATA const volatile float32 KGSM_EPBReld2NDlyTm_s = 2.0F;/* Referenced by: '<S1570>/Constant4' */

/* 规范：EPB释放入N需求判断时间阈值 */
CALDATA const volatile float32 KGSM_EPBReqMaxTm_s = 2.0F;/* Referenced by:
                                                          * '<S1508>/Constant2'
                                                          * '<S1508>/Constant4'
                                                          * '<S1508>/Constant5'
                                                          */

/* 规范：EPB拉起操作时间阈值 */
CALDATA const volatile boolean KGSM_GrNReq2PSw_flg = false;/* Referenced by: '<S1531>/Constant5' */

/* N档非换挡请求进P档请求强控 */
CALDATA const volatile boolean KGSM_GrNReq2PVal_flg = false;/* Referenced by: '<S1531>/Constant4' */

/* N档非换挡请求进P档请求-观测量：VGSM_GrNReq2P_flg */
CALDATA const volatile float32 KGSM_GrShftF1R1HldTm_s = 0.3F;/* Referenced by:
                                                              * '<S1568>/Constant3'
                                                              * '<S1568>/Constant4'
                                                              * '<S1570>/Constant2'
                                                              */

/* 规范：换挡杆入N需求判断时间阈值 */
CALDATA const volatile float32 KGSM_GrShftF2R2HldTm_s = 0.2F;/* Referenced by:
                                                              * '<S1568>/Constant5'
                                                              * '<S1568>/Constant6'
                                                              * '<S1568>/Constant7'
                                                              * '<S1568>/Constant8'
                                                              * '<S1570>/Constant1'
                                                              * '<S1570>/Constant9'
                                                              */

/* 规范：换挡杆入D需求判断时间阈值/换挡杆入R需求判断时间阈值 */
CALDATA const volatile float32 KGSM_GrShftHwPHldTm_s = 0.2F;/* Referenced by:
                                                             * '<S1569>/Constant2'
                                                             * '<S1569>/Constant5'
                                                             * '<S1569>/Constant6'
                                                             */

/* 规范：换挡杆入P按键时间阈值 */
CALDATA const volatile float32 KGSM_GrShftMaxVehSpd_kph = 3.0F;/* Referenced by:
                                                                * '<S1508>/Constant6'
                                                                * '<S636>/Constant'
                                                                * '<S636>/Constant1'
                                                                * '<S1533>/Constant6'
                                                                * '<S1568>/Constant10'
                                                                * '<S1568>/Constant11'
                                                                * '<S1568>/Constant12'
                                                                * '<S1568>/Constant9'
                                                                * '<S1570>/Constant10'
                                                                * '<S1570>/Constant3'
                                                                */

/* 规范：换挡车速阈值 */
CALDATA const volatile boolean KGSM_HldGearPSw_flg = false;/* Referenced by: '<S1531>/Constant1' */

/* 保持P档请求强控 */
CALDATA const volatile boolean KGSM_HldGearPVal_flg = false;/* Referenced by: '<S1531>/Constant' */

/* 保持P档请求-观测量：VGSM_HldGearP_flg */
CALDATA const volatile float32 KGSM_INVTrnOffDly_s = 2.0F;/* Referenced by: '<S1509>/Constant1' */

/* 规范：车辆实际档位由非P档进入到P档计时满2S */
CALDATA const volatile float32 KGSM_PErrDispMaxTm_s = 5.0F;/* Referenced by:
                                                            * '<S1508>/Cnst'
                                                            * '<S1508>/Cnst2'
                                                            */

/* 规范：Perror置位时间阈值 */
CALDATA const volatile boolean KGSM_ReqEPBSw_flg = false;/* Referenced by: '<S1508>/Constant1' */

/* 请求EPB状态强控 */
CALDATA const volatile EnumEPBReq KGSM_ReqEPBVal_enum = EnumEPBReq_NoCmd;/* Referenced by: '<S1508>/Constant' */

/* 请求EPB状态-观测量：VGSM_ReqEPB_enum */
CALDATA const volatile float32 KGSM_TgtGrReqWatTm_s = 2.0F;/* Referenced by:
                                                            * '<S1568>/Constant1'
                                                            * '<S1568>/Constant2'
                                                            * '<S1569>/Constant1'
                                                            * '<S1569>/Constant3'
                                                            * '<S1614>/Constant4'
                                                            * '<S1615>/Constant4'
                                                            * '<S1678>/Constant4'
                                                            * '<S1679>/Constant4'
                                                            * '<S1680>/Constant4'
                                                            * '<S1720>/Constant4'
                                                            * '<S1721>/Constant4'
                                                            * '<S1722>/Constant4'
                                                            */

/* 规范：换挡请求持续时间阈值 */
CALDATA const volatile boolean KGSM_VehActGearPstnSw_flg = false;
                                      /* Referenced by: '<S1509>/APA_Switdh4' */

/* 实际输出档位控制强控 */
CALDATA const volatile EnumGearPstn KGSM_VehActGearPstnVal_enum = EnumGearPstn_P;
                                      /* Referenced by: '<S1509>/APA_Switdh5' */

/* 实际输出档位控制 0-P 1-N 2-D 3-R-观测量：VGSM_VehActGearPstn_enum */
CALDATA const volatile float32 KHMI_BackwSldgBgnEnd_kph = -3.0F;/* Referenced by: '<S638>/Constant1' */
CALDATA const volatile float32 KHMI_BackwSldgBgnSpd_kph = -0.5F;/* Referenced by: '<S638>/Constant' */
CALDATA const volatile float32 KHMI_BackwSldgDst_m = -0.5F;/* Referenced by: '<S638>/Constant2' */
CALDATA const volatile float32 KHMI_BatCellMaxTemWarning_C = 48.0F;/* Referenced by: '<S630>/Constant' */

/* 电芯（最高温度）限功率温度 */
CALDATA const volatile float32 KHMI_BothAccBrkTime_s = 0.2F;/* Referenced by: '<S631>/Constant1' */

/* 回馈能力受限判断时长 */
CALDATA const volatile float32 KHMI_CellOverTempTime_s = 5.0F;/* Referenced by: '<S630>/Constant1' */

/* 电芯过温判断时长 */
CALDATA const volatile float32 KHMI_DriPwrLmtTime_s = 5.0F;/* Referenced by: '<S635>/Constant1' */

/* 驱动能力受限判断时长 */
CALDATA const volatile float32 KHMI_DriPwrLmtVa_kw = 25.0F;/* Referenced by: '<S635>/Constant' */

/* 驱动能力受限阈值 */
CALDATA const volatile float32 KHMI_FwdSldgBgnEnd_kph = 3.0F;/* Referenced by: '<S638>/Constant5' */
CALDATA const volatile float32 KHMI_FwdSldgBgnSpd_kph = 0.5F;/* Referenced by: '<S638>/Constant4' */
CALDATA const volatile float32 KHMI_FwdSldgDst_m = 0.5F;/* Referenced by: '<S638>/Constant6' */
CALDATA const volatile float32 KHMI_InfoDispIntervalTm_s = 2.5F;/* Referenced by: '<S627>/Constant27' */

/* InfoDisp发送给仪表维持时长 */
CALDATA const volatile float32 KHMI_RecPwrLmtTime_s = 5.0F;/* Referenced by: '<S637>/Constant1' */

/* 回馈能力受限判断时长 */
CALDATA const volatile float32 KHMI_RecPwrLmtVa_kw = -10.0F;/* Referenced by: '<S637>/Constant' */

/* 回馈能力受限阈值 */
CALDATA const volatile float32 KHMI_SnowModWarnSpd_kph = 120.0F;/* Referenced by: '<S639>/Constant1' */

/* 雪地模式超速报警车速阈值 */
CALDATA const volatile float32 KHMI_SpdWheelFRdiff_kph = 20.0F;/* Referenced by:
                                                                * '<S640>/Constant1'
                                                                * '<S640>/Constant3'
                                                                * '<S640>/Constant5'
                                                                * '<S640>/Constant7'
                                                                */

/* 左右车轮差值阈值 */
CALDATA const volatile float32 KHMI_WarningSendTime_s = 2.5F;/* Referenced by:
                                                              * '<S627>/Constant'
                                                              * '<S627>/Constant10'
                                                              * '<S627>/Constant12'
                                                              * '<S627>/Constant14'
                                                              * '<S627>/Constant16'
                                                              * '<S627>/Constant18'
                                                              * '<S627>/Constant2'
                                                              * '<S627>/Constant20'
                                                              * '<S627>/Constant22'
                                                              * '<S627>/Constant4'
                                                              * '<S627>/Constant6'
                                                              * '<S627>/Constant8'
                                                              */

/* InfoDisp提醒维持发送时间 */
CALDATA const volatile float32 KHVM_ChrgStopWaitTm_s = 1.0F;/* Referenced by: '<S749>/MainState' */

/* OBC充电唤醒源断开等待时间 */
CALDATA const volatile float32 KHVM_ChrgTransCfmTm_s = 0.5F;/* Referenced by:
                                                             * '<S770>/Constant1'
                                                             * '<S770>/Constant11'
                                                             * '<S770>/Constant12'
                                                             * '<S770>/Constant2'
                                                             * '<S770>/Constant3'
                                                             * '<S770>/Constant4'
                                                             * '<S770>/Constant7'
                                                             * '<S770>/Constant9'
                                                             */

/* 充放电状态转移到结束的确认时间 */
CALDATA const volatile float32 KHVM_ChrgVoltReachCfmTm_s = 3.0F;/* Referenced by:
                                                                 * '<S750>/Constant4'
                                                                 * '<S750>/Constant7'
                                                                 */

/* 交直流充电达到截止电压确认时间 */
CALDATA const volatile float32 KHVM_DCCBuckLVVolt_V = 14.41F;/* Referenced by: '<S749>/MainState' */

/* DCDC BUCK 电压 */
CALDATA const volatile float32 KHVM_DchaStopWaitTm_s = 2.0F;/* Referenced by: '<S749>/MainState' */

/* OBC放电电唤醒源断开等待时间 */
CALDATA const volatile uint8 KHVM_HUMaxChrgCurntAC_A = 32U;/* Referenced by: '<S750>/Constant3' */

/* HU设置交流充电电流最大限制 */
CALDATA const volatile uint8 KHVM_HUMinChrgCurntAC_A = 5U;/* Referenced by: '<S750>/Constant2' */

/* HU设置交流充电电流最小限制 */
CALDATA const volatile float32 KHVM_HVCheckTmout_s = 4.0F;/* Referenced by: '<S749>/MainState' */

/* INV&DCDC高压建立等待时间 */
CALDATA const volatile float32 KHVM_HVCutOffTmout_s = 180.0F;/* Referenced by: '<S749>/MainState' */

/* BMS主继电器断开等待时间 */
CALDATA const volatile float32 KHVM_HVDeviceOffTmout_s = 10.0F;/* Referenced by: '<S749>/MainState' */

/* 下电关闭设备（空调&DCDC）等待时间 */
CALDATA const volatile float32 KHVM_HVDschrgTmout_s = 180.0F;/* Referenced by: '<S749>/MainState' */

/* INV泄放等待时间 */
CALDATA const volatile float32 KHVM_HVSetUpTmout_s = 61.0F;/* Referenced by: '<S749>/MainState' */

/* 主继电器闭合等待时间 */
CALDATA const volatile boolean KHVM_INVPreprogm_ovrdflg = false;/* Referenced by: '<S771>/Constant1' */

/* INV与编程标定控制开关 */
CALDATA const volatile boolean KHVM_INVPreprogm_ovrdval = false;/* Referenced by: '<S771>/Constant' */

/* INV与编程标定控制值 */
CALDATA const volatile float32 KHVM_INVholdTm_s = 2.0F;/* Referenced by: '<S749>/MainState' */

/* 下电保持INV硬线使能延迟时间 */
CALDATA const volatile float32 KHVM_KL15OffPwrDwnCfmTm_s = 0.5F;/* Referenced by: '<S775>/Constant4' */

/* KL15断开确认时间 */
CALDATA const volatile float32 KHVM_MaxHVDCCurntAC_A = 32.0F;/* Referenced by: '<S750>/Constant1' */

/* VCU反馈给OBC最大电流限制(直流侧) */
CALDATA const volatile float32 KHVM_MaxHVDCVoltAC_V = 455.0F;/* Referenced by: '<S750>/Constant12' */

/* 交流充电最大电压 */
CALDATA const volatile float32 KHVM_OBCS2ClsTmout_s = 6.0F;/* Referenced by: '<S749>/MainState' */

/* S2闭合等待时间 */
CALDATA const volatile boolean KHVM_PTRdy2PTStdby_ovrdflg = false;/* Referenced by: '<S773>/Constant7' */

/* Rdy退回Stdby开关 */
CALDATA const volatile boolean KHVM_PTRdy2PTStdby_ovrdval = false;/* Referenced by: '<S773>/Constant4' */

/* Rdy退回Stdby控制值 */
CALDATA const volatile float32 KHVM_PTRdyBrkSwEffctvTm_s = 2.0F;/* Referenced by: '<S773>/Constant1' */

/* 刹车上升沿保持时间 */
CALDATA const volatile boolean KHVM_PTStdby2PTRdy_ovrdflg = false;/* Referenced by: '<S773>/Constant3' */

/* Stdby进入Rdy开关 */
CALDATA const volatile boolean KHVM_PTStdby2PTRdy_ovrdval = false;/* Referenced by: '<S773>/Constant' */

/* Stdby进入Rdy控制值 */
CALDATA const volatile boolean KHVM_PowUpSelfChek_ovrdflg = false;/* Referenced by: '<S774>/Constant3' */

/* 高压自检条件控制开关 */
CALDATA const volatile boolean KHVM_PowUpSelfChek_ovrdval = false;/* Referenced by: '<S774>/Constant' */

/* 高压自检条件控制值 */
CALDATA const volatile boolean KHVM_PwrOn2PwrDwn_ovrdflg = false;/* Referenced by: '<S775>/Constant3' */

/* 高压下电条件满足开关 */
CALDATA const volatile boolean KHVM_PwrOn2PwrDwn_ovrdval = false;/* Referenced by: '<S775>/Constant' */

/* 高压下电条件满足控制值 */
CALDATA const volatile float32 KHVM_PwrUpACChrgEffctvTm_s = 2.0F;/* Referenced by: '<S776>/Constant1' */

/* OBC唤醒源上升沿保持时间 */
CALDATA const volatile float32 KHVM_PwrUpDCChrgEffctvTm_s = 2.0F;/* Referenced by: '<S776>/Constant4' */

/* BMS唤醒源上升沿保持时间 */
CALDATA const volatile float32 KHVM_PwrUpIBSDlyTm_s = 3.0F;/* Referenced by: '<S776>/Constant5' */

/* IBS唤醒源延迟时间 */
CALDATA const volatile float32 KHVM_PwrUpIBSEffctvTm_s = 5.0F;/* Referenced by: '<S776>/Constant9' */

/* IBS上升沿保持时间 */
CALDATA const volatile float32 KHVM_PwrUpKL15EffctvTm_s = 2.0F;/* Referenced by: '<S776>/Constant17' */

/* KL15上升沿保持时间 */
CALDATA const volatile float32 KHVM_SOCExtrmLo_pct = 0.0F;/* Referenced by: '<S752>/Constant9' */

/* SOC极低阈值 */
CALDATA const volatile float32 KHVM_SOCLoPwrDwnDlyTm_s = 10.0F;/* Referenced by: '<S775>/Constant2' */

/* SOC极低确认时间 */
CALDATA const volatile float32 KHVM_SOPExtrmLo_kW = 0.1F;/* Referenced by: '<S752>/Constant3' */

/* SOP极低阈值 */
CALDATA const volatile float32 KHVM_SleepWaitTm_s = 5.0F;/* Referenced by: '<S749>/MainState' */

/* 下电可以休眠等待时间 */
CALDATA const volatile float32 KHVM_TBOXReSetACChgTm_s = 2.0F;/* Referenced by: '<S750>/Constant6' */

/* TBOX远程充电请求保持时间 */
CALDATA const volatile boolean KHVM_Tbox2OBCOprtCmd_ovrdflg = false;/* Referenced by: '<S750>/Constant9' */

/* TBOX远程充电开关 */
CALDATA const volatile uint8 KHVM_Tbox2OBCOprtCmd_ovrdval = 0U;/* Referenced by: '<S750>/Constant' */

/* TBOX远程充电标定值 */
CALDATA const volatile float32 KHVM_VehHaltCfmTm_s = 0.5F;/* Referenced by: '<S752>/Constant7' */

/* 车辆停止车速确认时间 */
CALDATA const volatile float32 KHVM_VehHaltSpd_kph = 1.0F;/* Referenced by: '<S752>/Constant10' */

/* 车辆停止车速阈值 */
CALDATA const volatile float32 KHVM_VehMoveCfmTm_s = 1.0F;/* Referenced by: '<S752>/Constant12' */

/* 车辆运动车速确认时间 */
CALDATA const volatile float32 KHVM_VehSpdLo_kph = 3.0F;/* Referenced by: '<S752>/Constant2' */

/* 低车速阈值 */
CALDATA const volatile boolean KHVM_WakeUp2PwrUp_ovrdflg = false;/* Referenced by: '<S776>/Constant6' */

/* 唤醒到上高压条件开关 */
CALDATA const volatile boolean KHVM_WakeUp2PwrUp_ovrdval = false;/* Referenced by: '<S776>/Constant' */

/* 唤醒到上高压条件控制值 */
CALDATA const volatile boolean KHVM_WakeUpVCU_ovrdflg = false;/* Referenced by: '<S777>/Constant1' */

/* 休眠到唤醒条件控制开关 */
CALDATA const volatile boolean KHVM_WakeUpVCU_ovrdval = false;/* Referenced by: '<S777>/Constant' */

/* 休眠到唤醒条件控制值 */
CALDATA const volatile uint8 KIBS_ChgMaxNumThr_cnt = 60U;/* Referenced by:
                                                          * '<S1002>/Constant'
                                                          * '<S1002>/Constant6'
                                                          */

/* 最大补电次数阈值_versteckt */
CALDATA const volatile float32 KIBS_ChrgCurntOKThr_A = 0.05F;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS充电电流阈值_versteckt */
CALDATA const volatile uint16 KIBS_ChrgFailTmThr_min = 1U;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS补电故障时间阈值_versteckt */
CALDATA const volatile float32 KIBS_ChrgTempThr1_C = -15.0F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电温度阈值1_versteckt */
CALDATA const volatile float32 KIBS_ChrgTempThr2_C = -5.0F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电温度阈值2_versteckt */
CALDATA const volatile float32 KIBS_ChrgTempThr3_C = 5.0F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电温度阈值3_versteckt */
CALDATA const volatile float32 KIBS_ChrgVoltThr1_V = 12.4F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值1_versteckt */
CALDATA const volatile float32 KIBS_ChrgVoltThr2_V = 12.5F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值2_versteckt */
CALDATA const volatile float32 KIBS_ChrgVoltThr3_V = 12.6F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值3_versteckt */
CALDATA const volatile float32 KIBS_ChrgVoltThr4_V = 12.7F;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值4_versteckt */
CALDATA const volatile uint16 KIBS_CurntOKTmThr_min = 1U;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS充电电流达到阈值确认时间_versteckt */
CALDATA const volatile float32 KIBS_DfltEnvirTemp_C = 5.0F;/* Referenced by: '<S1003>/Constant1' */

/* AC环境温度失效时，默认的环境温度_versteckt */
CALDATA const volatile float32 KIBS_EnvirTemptFiltCoeff_c = 0.1F;/* Referenced by: '<S1003>/Constant3' */

/* 环境温度滤波系数_versteckt */
CALDATA const volatile uint8 KIBS_FailChgNumThr_cnt = 6U;/* Referenced by:
                                                          * '<S1002>/Constant10'
                                                          * '<S1002>/Constant12'
                                                          */

/* 最大补电失败次数阈值_versteckt */
CALDATA const volatile boolean KIBS_FbIBSWup_flg = true;/* Referenced by: '<S1002>/Constant17' */

/* 禁止IBS唤醒手动开关_versteckt */
CALDATA const volatile uint16 KIBS_FbRctWupThr_min = 65535U;/* Referenced by: '<S1003>/Constant10' */

/* 禁止RTC唤醒配置的时间_versteckt */
CALDATA const volatile uint16 KIBS_HoldNMTmThr_s = 8U;/* Referenced by: '<S1002>/Constant14' */

/* IBS唤醒保持网络时间_versteckt */
CALDATA const volatile uint8 KIBS_KL30VoltDebNumThr_cnt = 5U;/* Referenced by: '<S1020>/Constant2' */

/* KL30电压低于补电电压总次数_versteckt */
CALDATA const volatile float32 KIBS_KL30VoltDebTmThr_s = 1.0F;/* Referenced by: '<S1003>/Constant7' */

/* KL30电压是否满足诊断时间_versteckt */
CALDATA const volatile float32 KIBS_KL30VoltFiltCoeff_c = 0.2F;/* Referenced by: '<S1003>/Constant2' */

/* KL30电压滤波系数_versteckt */
CALDATA const volatile uint16 KIBS_StWaitTm_s = 5U;/* Referenced by: '<S1003>/Constant5' */

/* IBS状态（电压&温度）稳定时间_versteckt */
CALDATA const volatile uint8 KIBS_WakeupReas_enum = 34U;/* Referenced by: '<S1018>/Constant' */

/* 底层唤醒原因枚举值_versteckt */
CALDATA const volatile uint16 KIBS_WupChgTmThr1_min = 15U;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS补电时间阈值1_versteckt */
CALDATA const volatile boolean KIPC_ACCCfgOvrdSw_flg = false;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg2' */
CALDATA const volatile boolean KIPC_ACCCfgOvrdVal_flg = false;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg2' */
CALDATA const volatile float32 KIPC_AccPed1FullPstn_pct = 74.0F;/* Referenced by: '<S882>/Constant2' */
CALDATA const volatile float32 KIPC_AccPed2FullPstn_pct = 74.0F;/* Referenced by: '<S884>/Constant6' */
CALDATA const volatile float32 KIPC_AccPedDbnd_pct = 2.0F;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp1' */
CALDATA const volatile float32 KIPC_AccPedInitTm_s = 0.3F;
                               /* Referenced by: '<S879>/KIPC_AccPedInitTm_s' */
CALDATA const volatile float32 KIPC_AccPedLrnDwnFiltCoeff_rat = 0.91F;/* Referenced by:
                                                                      * '<S881>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                      * '<S883>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                      */
CALDATA const volatile float32 KIPC_AccPedLrnDwnStabThr_pct = 0.5F;/* Referenced by:
                                                                    * '<S881>/KAccPed_Threshold1ISLow_V6'
                                                                    * '<S883>/KAccPed_Threshold1ISLow_V6'
                                                                    */
CALDATA const volatile float32 KIPC_AccPedLrnDwnStabTm_s = 2.0F;/* Referenced by:
                                                                 * '<S881>/KAccPed_Threshold1ISLow_V5'
                                                                 * '<S883>/KAccPed_Threshold1ISLow_V5'
                                                                 */
CALDATA const volatile float32 KIPC_AccPedMinPstnHi_pct = 21.0F;/* Referenced by:
                                                                 * '<S881>/KAccPed_Threshold1ISLow_V10'
                                                                 * '<S881>/KAccPed_Threshold1ISLow_V11'
                                                                 * '<S883>/KAccPed_Threshold1ISLow_V10'
                                                                 * '<S883>/KAccPed_Threshold1ISLow_V11'
                                                                 */
CALDATA const volatile float32 KIPC_AccPedMinPstnLo_pct = 13.0F;/* Referenced by:
                                                                 * '<S881>/KAccPed_Threshold1ISLow_V8'
                                                                 * '<S883>/KAccPed_Threshold1ISLow_V8'
                                                                 */
CALDATA const volatile float32 KIPC_AccPedMinPstnLrnUpHi_pct = 80.0F;/* Referenced by:
                                                                      * '<S881>/KAccPed_Threshold1ISLow_V2'
                                                                      * '<S883>/KAccPed_Threshold1ISLow_V2'
                                                                      */
CALDATA const volatile float32 KIPC_AccPedMinPstnLrnUpLo_pct = 20.0F;/* Referenced by:
                                                                      * '<S881>/KAccPed_Threshold1ISLow_V1'
                                                                      * '<S883>/KAccPed_Threshold1ISLow_V1'
                                                                      */
CALDATA const volatile float32 KIPC_AccPedMinPstnUpOfst_pct = 0.2F;/* Referenced by:
                                                                    * '<S881>/KAccPed_Threshold1ISLow_V7'
                                                                    * '<S883>/KAccPed_Threshold1ISLow_V7'
                                                                    */
CALDATA const volatile float32 KIPC_AccPedNormzPstnFiltTm_s = 0.02F;/* Referenced by:
                                                                     * '<S878>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                     * '<S878>/KIPC_AccPedLrnDwnFiltCoeff_rat1'
                                                                     */
CALDATA const volatile float32 KIPC_AccPedPrsdThr4Stk_pct = 2.0F;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V1' */
CALDATA const volatile float32 KIPC_AccPedPstnLmt_pct = 100.0F;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp5' */
CALDATA const volatile boolean KIPC_AccPedPstnOvrdSw_flg = false;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp3' */
CALDATA const volatile float32 KIPC_AccPedPstnOvrdVal_pct = 0.0F;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp4' */
CALDATA const volatile float32 KIPC_AccPedSclRng_pct = 106.0F;/* Referenced by:
                                                               * '<S882>/cnst_ValidCheck_EngCoolantTemp1'
                                                               * '<S884>/cnst_ValidCheck_EngCoolantTemp3'
                                                               */
CALDATA const volatile boolean KIPC_AccPedStkDiagEnbl_flg = true;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V7' */
CALDATA const volatile float32 KIPC_AccPedStkFiltCoeff_rat = 0.91F;
                       /* Referenced by: '<S879>/KIPC_AccPedStkFiltCoeff_rat' */
CALDATA const volatile float32 KIPC_AccPedStkStabThr_pct = 0.5F;
                        /* Referenced by: '<S879>/KAccPed_Threshold1ISLow_V6' */
CALDATA const volatile float32 KIPC_AccPedStkStabTm_s = 5.0F;
                        /* Referenced by: '<S879>/KAccPed_Threshold1ISLow_V5' */
CALDATA const volatile float32 KIPC_AccPedSwThr_pct = 2.0F;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp2' */

/* 油门开关开启阈值 */
CALDATA const volatile float32 KIPC_AccPedZeroPstnDecRate_pctps = -100.0F;
                          /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V18' */
CALDATA const volatile float32 KIPC_AccPedZeroPstnIncRate_pctps = 100.0F;
                          /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V17' */
CALDATA const volatile float32 KIPC_BrkPedPrsdThr4Stk_pct = 10.0F;
                          /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V11' */
CALDATA const volatile float32 KIPC_BrkPedPstnDfltPrsd_pct = 100.0F;/* Referenced by: '<S871>/Constant2' */
CALDATA const volatile boolean KIPC_BrkPedPstnOvrdSw_flg = false;
                   /* Referenced by: '<S871>/cnst_ValidCheck_EngCoolantTemp2' */
CALDATA const volatile float32 KIPC_BrkPedPstnOvrdVal_pct = 0.0F;
                   /* Referenced by: '<S871>/cnst_ValidCheck_EngCoolantTemp3' */
CALDATA const volatile float32 KIPC_BrkPedReldThr4Stk_pct = 3.0F;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V2' */
CALDATA const volatile float32 KIPC_BrkSwPrsdPedPstn_pct = 5.0F;
                             /* Referenced by: '<S871>/KTQD_BrkPedPstnHi_pct' */
CALDATA const volatile boolean KIPC_CCSCfgOvrdSw_flg = false;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg1' */
CALDATA const volatile boolean KIPC_CCSCfgOvrdVal_flg = false;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg1' */
CALDATA const volatile boolean KIPC_CrpCtrlCfgOvrdSw_flg = false;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg3' */
CALDATA const volatile boolean KIPC_CrpCtrlCfgOvrdVal_flg = false;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg3' */
CALDATA const volatile boolean KIPC_CrpModeActOvrdSw_flg = false;
                           /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg' */
CALDATA const volatile EnumCrpModeAct KIPC_CrpModeActOvrdVal_enum =
  EnumCrpModeAct_Open;    /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg' */
CALDATA const volatile boolean KIPC_DrvModeActOvrdSw_flg = false;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg1' */
CALDATA const volatile EnumDrvModeAct KIPC_DrvModeActOvrdVal_enum =
  EnumDrvModeAct_Eco;    /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg1' */
CALDATA const volatile boolean KIPC_DrvPwrIntnstyOvrdSw_flg = false;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg4' */
CALDATA const volatile uint8 KIPC_DrvPwrIntnstyOvrdVal_pct = 0U;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg4' */
CALDATA const volatile boolean KIPC_ESCVehSpdPrio_flg = true;
                                /* Referenced by: '<S942>/KSYS_VehTransRto_c' */
CALDATA const volatile boolean KIPC_ESCWhlSpdPrio_flg = true;
                               /* Referenced by: '<S942>/KSYS_VehTransRto_c2' */
CALDATA const volatile boolean KIPC_EnblFltRstAccPedZP_flg = true;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V3' */
CALDATA const volatile boolean KIPC_EnblVpedAutoCrp_flg = true;/* Referenced by: '<S910>/Shift_enum1' */
CALDATA const volatile float32 KIPC_ExitAutoCrpDrvDist_m = 1.0F;
                         /* Referenced by: '<S910>/KIPC_ExitAutoCrpDrvDist_m' */
CALDATA const volatile float32 KIPC_ExitAutoCrpPNDurTm_s = 5.0F;/* Referenced by: '<S910>/Shift_enum4' */
CALDATA const volatile float32 KIPC_ExitAutoCrpVehSpd_kph = 15.0F;
                        /* Referenced by: '<S910>/KIPC_ExitAutoCrpVehSpd_kph' */
CALDATA const volatile boolean KIPC_HDCCfgOvrdSw_flg = false;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg4' */
CALDATA const volatile boolean KIPC_HDCCfgOvrdVal_flg = false;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg4' */
CALDATA const volatile boolean KIPC_RegenModeActOvrdSw_flg = false;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg3' */
CALDATA const volatile EnumRegenModeAct KIPC_RegenModeActOvrdVal_enum =
  EnumRegenModeAct_Weak; /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg3' */
CALDATA const volatile boolean KIPC_RegenPwrIntnstyOvrdSw_flg = false;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg5' */
CALDATA const volatile uint8 KIPC_RegenPwrIntnstyOvrdVal_pct = 0U;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg5' */
CALDATA const volatile boolean KIPC_SnowModeDft_flg = false;/* Referenced by: '<S873>/Unit Delay3' */
CALDATA const volatile boolean KIPC_SnowModeOvrdSw_flg = false;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg2' */
CALDATA const volatile boolean KIPC_SnowModeOvrdVal_flg = false;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg2' */
CALDATA const volatile float32 KIPC_VehHiddenBtnSyncnTm_s = 2.0F;/* Referenced by:
                                                                  * '<S873>/Cnst4'
                                                                  * '<S873>/Cnst6'
                                                                  * '<S873>/Cnst9'
                                                                  */
CALDATA const volatile float32 KIPC_VehHiddenModeWaitTm_s = 10.0F;/* Referenced by:
                                                                   * '<S873>/Cnst1'
                                                                   * '<S873>/Cnst2'
                                                                   * '<S873>/Cnst3'
                                                                   * '<S873>/Cnst5'
                                                                   * '<S873>/Cnst7'
                                                                   */
CALDATA const volatile boolean KIPC_iTPMSCfgOvrdSw_flg = false;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg5' */
CALDATA const volatile boolean KIPC_iTPMSCfgOvrdVal_flg = false;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg5' */
CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVoltHi_mV = 15000.0F;/* Referenced by: '<S1462>/sat6' */
CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVoltLo_mV = 0.0F;/* Referenced by: '<S1462>/sat7' */
CALDATA const volatile boolean KIPM_HwAccPedCh1SuplyVolt_mV_ovrdflg = false;/* Referenced by: '<S1462>/sat3' */
CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVolt_mV_ovrdval = 0.0F;/* Referenced by: '<S1462>/sat4' */
CALDATA const volatile float32 KIPM_HwAccPedCh1VoltHi_mV = 5500.0F;/* Referenced by: '<S1463>/sat6' */
CALDATA const volatile float32 KIPM_HwAccPedCh1VoltLo_mV = 0.0F;/* Referenced by: '<S1463>/sat7' */
CALDATA const volatile boolean KIPM_HwAccPedCh1Volt_mV_ovrdflg = false;/* Referenced by: '<S1463>/sat3' */
CALDATA const volatile float32 KIPM_HwAccPedCh1Volt_mV_ovrdval = 0.0F;/* Referenced by: '<S1463>/sat4' */
CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVoltHi_mV = 15000.0F;/* Referenced by: '<S1464>/sat6' */
CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVoltLo_mV = 0.0F;/* Referenced by: '<S1464>/sat7' */
CALDATA const volatile boolean KIPM_HwAccPedCh2SuplyVolt_mV_ovrdflg = false;/* Referenced by: '<S1464>/sat3' */
CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVolt_mV_ovrdval = 0.0F;/* Referenced by: '<S1464>/sat4' */
CALDATA const volatile float32 KIPM_HwAccPedCh2VoltHi_mV = 5500.0F;/* Referenced by: '<S1465>/sat6' */
CALDATA const volatile float32 KIPM_HwAccPedCh2VoltLo_mV = 0.0F;/* Referenced by: '<S1465>/sat7' */
CALDATA const volatile boolean KIPM_HwAccPedCh2Volt_mV_ovrdflg = false;/* Referenced by: '<S1465>/sat3' */
CALDATA const volatile float32 KIPM_HwAccPedCh2Volt_mV_ovrdval = 0.0F;/* Referenced by: '<S1465>/sat4' */
CALDATA const volatile boolean KIPM_HwBMSWakeup_flg_ovrdflg = false;/* Referenced by: '<S1466>/sat3' */
CALDATA const volatile boolean KIPM_HwBMSWakeup_flg_ovrdval = false;/* Referenced by: '<S1466>/sat4' */
CALDATA const volatile boolean KIPM_HwBrkSwHi_flg_ovrdflg = false;/* Referenced by: '<S1467>/sat3' */
CALDATA const volatile boolean KIPM_HwBrkSwHi_flg_ovrdval = false;/* Referenced by: '<S1467>/sat4' */
CALDATA const volatile boolean KIPM_HwBrkSwLo_flg_ovrdflg = false;/* Referenced by: '<S1468>/sat3' */
CALDATA const volatile boolean KIPM_HwBrkSwLo_flg_ovrdval = false;/* Referenced by: '<S1468>/sat4' */
CALDATA const volatile boolean KIPM_HwCrpModeSw_flg_ovrdflg = false;/* Referenced by: '<S1469>/sat3' */
CALDATA const volatile boolean KIPM_HwCrpModeSw_flg_ovrdval = false;/* Referenced by: '<S1469>/sat4' */
CALDATA const volatile boolean KIPM_HwDrvModeSw_flg_ovrdflg = false;/* Referenced by: '<S1470>/sat3' */
CALDATA const volatile boolean KIPM_HwDrvModeSw_flg_ovrdval = false;/* Referenced by: '<S1470>/sat4' */
CALDATA const volatile boolean KIPM_HwEmgcyShutOff_flg_ovrdflg = false;/* Referenced by: '<S1471>/sat3' */
CALDATA const volatile boolean KIPM_HwEmgcyShutOff_flg_ovrdval = false;/* Referenced by: '<S1471>/sat4' */
CALDATA const volatile float32 KIPM_HwHVIL1VoltHi_mV = 5500.0F;/* Referenced by: '<S1472>/sat6' */
CALDATA const volatile float32 KIPM_HwHVIL1VoltLo_mV = 0.0F;/* Referenced by: '<S1472>/sat7' */
CALDATA const volatile boolean KIPM_HwHVIL1Volt_mV_ovrdflg = true;/* Referenced by: '<S1472>/sat3' */
CALDATA const volatile float32 KIPM_HwHVIL1Volt_mV_ovrdval = 5000.0F;/* Referenced by: '<S1472>/sat4' */
CALDATA const volatile float32 KIPM_HwHVIL2VoltHi_mV = 5500.0F;/* Referenced by: '<S1473>/sat6' */
CALDATA const volatile float32 KIPM_HwHVIL2VoltLo_mV = 0.0F;/* Referenced by: '<S1473>/sat7' */
CALDATA const volatile boolean KIPM_HwHVIL2Volt_mV_ovrdflg = true;/* Referenced by: '<S1473>/sat3' */
CALDATA const volatile float32 KIPM_HwHVIL2Volt_mV_ovrdval = 5000.0F;/* Referenced by: '<S1473>/sat4' */
CALDATA const volatile boolean KIPM_HwKL15A_flg_ovrdflg = false;/* Referenced by: '<S1474>/sat3' */
CALDATA const volatile boolean KIPM_HwKL15A_flg_ovrdval = false;/* Referenced by: '<S1474>/sat4' */
CALDATA const volatile boolean KIPM_HwKL15B_flg_ovrdflg = false;/* Referenced by: '<S1475>/sat3' */
CALDATA const volatile boolean KIPM_HwKL15B_flg_ovrdval = false;/* Referenced by: '<S1475>/sat4' */
CALDATA const volatile uint16 KIPM_HwKL30Hi_mV = 20000U;/* Referenced by: '<S1476>/sat6' */
CALDATA const volatile uint16 KIPM_HwKL30Lo_mV = 0U;/* Referenced by: '<S1476>/sat7' */
CALDATA const volatile boolean KIPM_HwKL30_mV_ovrdflg = false;/* Referenced by: '<S1476>/sat3' */
CALDATA const volatile uint16 KIPM_HwKL30_mV_ovrdval = 0U;/* Referenced by: '<S1476>/sat4' */
CALDATA const volatile boolean KIPM_HwOBCWakeup_flg_ovrdflg = false;/* Referenced by: '<S1477>/sat3' */
CALDATA const volatile boolean KIPM_HwOBCWakeup_flg_ovrdval = false;/* Referenced by: '<S1477>/sat4' */
CALDATA const volatile boolean KIPM_HwRearFogLampSwt_flg_ovrdflg = false;/* Referenced by: '<S1478>/sat3' */
CALDATA const volatile boolean KIPM_HwRearFogLampSwt_flg_ovrdval = false;/* Referenced by: '<S1478>/sat4' */
CALDATA const volatile uint16 KIPM_HwShftPstnSwPrsdHi_Ohm = 6000U;/* Referenced by: '<S1481>/Constant' */
CALDATA const volatile uint16 KIPM_HwShftPstnSwPrsdLo_Ohm = 4000U;/* Referenced by: '<S1481>/Constant1' */
CALDATA const volatile uint16 KIPM_HwShftPstnSwReldHi_Ohm = 40000U;/* Referenced by: '<S1481>/Constant3' */
CALDATA const volatile uint16 KIPM_HwShftPstnSwReldLo_Ohm = 36000U;/* Referenced by: '<S1481>/Constant4' */
CALDATA const volatile uint16 KIPM_HwShftPstnSwShtBatt_Ohm = 65000U;/* Referenced by: '<S1481>/Constant5' */
CALDATA const volatile uint16 KIPM_HwShftPstnSwShtGnd_Ohm = 500U;/* Referenced by: '<S1481>/Constant7' */
CALDATA const volatile boolean KIPM_HwShftPstnSwSts_enum_ovrdflg = false;/* Referenced by: '<S1479>/sat3' */
CALDATA const volatile EnumPGearSwSts KIPM_HwShftPstnSwSts_enum_ovrdval =
  EnumPGearSwSts_Reld;                 /* Referenced by: '<S1479>/sat4' */
CALDATA const volatile boolean KIPM_HwVehCrash_flg_ovrdflg = false;/* Referenced by: '<S1480>/sat3' */
CALDATA const volatile boolean KIPM_HwVehCrash_flg_ovrdval = false;/* Referenced by: '<S1480>/sat4' */
CALDATA const volatile boolean KOPM_HwWakeupBMS_flg_ovrdflg = false;/* Referenced by: '<S1494>/sat3' */
CALDATA const volatile boolean KOPM_HwWakeupBMS_flg_ovrdval = false;/* Referenced by: '<S1494>/sat4' */
CALDATA const volatile float32 KRME_AvgSOCCnsm100NumWghtFac_c = 0.0F;/* Referenced by: '<S981>/Constant9' */

/* 前100个数组能耗加权系数 */
CALDATA const volatile float32 KRME_AvgSOCCnsm10NumWghtFac_c = 0.2F;/* Referenced by: '<S981>/Constant5' */

/* 前10个数组能耗加权系数 */
CALDATA const volatile float32 KRME_AvgSOCCnsm15NumWghtFac_c = 0.2F;/* Referenced by: '<S981>/Constant6' */

/* 前15个数组能耗加权系数 */
CALDATA const volatile float32 KRME_AvgSOCCnsm1NumWghtFac_c = 0.0F;/* Referenced by: '<S981>/Constant3' */

/* 初始数组加权系数 */
CALDATA const volatile float32 KRME_AvgSOCCnsm25NumWghtFac_c = 0.2F;/* Referenced by: '<S981>/Constant7' */

/* 前25个数组能耗加权系数 */
CALDATA const volatile float32 KRME_AvgSOCCnsm50NumWghtFac_c = 0.2F;/* Referenced by: '<S981>/Constant8' */

/* 前50个数组能耗加权系数 */
CALDATA const volatile float32 KRME_AvgSOCCnsm5NumWghtFac_c = 0.2F;/* Referenced by: '<S981>/Constant4' */

/* 前5个数组能耗加权系数 */
CALDATA const volatile boolean KRME_AvgSOCCnsmWghtSw_flg = false;/* Referenced by: '<S981>/Constant10' */

/* 加权SOC消耗强控开关 */
CALDATA const volatile float32 KRME_AvgSOCCnsmWghtVal_pctpkm = 0.0F;/* Referenced by: '<S981>/Constant11' */

/* 加权SOC消耗强控值 */
CALDATA const volatile float32 KRME_CHTCRmnMilEstVldOff_km = 25.0F;/* Referenced by: '<S951>/Constant4' */

/* 标准续航CHTC有效性Off */
CALDATA const volatile float32 KRME_CHTCRmnMilEstVldOn_km = 30.0F;/* Referenced by: '<S951>/Constant7' */

/* 标准续航CHTC有效性On */
CALDATA const volatile float32 KRME_CalPwrCnsmTgtDist_m = 100.0F;/* Referenced by:
                                                                  * '<S955>/Constant8'
                                                                  * '<S955>/Constant9'
                                                                  */

/* Pwr功耗单位里程 */
CALDATA const volatile float32 KRME_CalPwrCnsmVehThr_kph = 0.5F;/* Referenced by: '<S955>/Constant1' */

/* 计算Pwr消耗车速值 */
CALDATA const volatile float32 KRME_CalSOCCnsmTgtDist_m = 1000.0F;/* Referenced by:
                                                                   * '<S980>/Constant2'
                                                                   * '<S980>/Constant8'
                                                                   * '<S980>/Constant9'
                                                                   */

/* SOC消耗单位里程 */
CALDATA const volatile float32 KRME_CalSOCCnsmVehThr_kph = 0.5F;/* Referenced by:
                                                                 * '<S959>/Constant1'
                                                                 * '<S978>/Constant10'
                                                                 * '<S980>/Constant1'
                                                                 */

/* 计算SOC消耗车速值 */
CALDATA const volatile float32 KRME_ChrgOfstSOCVal_pct = 10.0F;/* Referenced by:
                                                                * '<S966>/Constant1'
                                                                * '<S966>/Constant2'
                                                                */

/* 充电模式SOC偏移值 */
CALDATA const volatile float32 KRME_DchaVehStpDlyTm_s = 2.0F;/* Referenced by: '<S978>/Constant11' */

/* 车辆停止确认时间 */
CALDATA const volatile float32 KRME_NVMMilDwLim_km = 0.0F;/* Referenced by: '<S958>/Constant2' */

/* NVM存储动态续航下限值 */
CALDATA const volatile float32 KRME_NVMMilUpLim_km = 1000.0F;/* Referenced by: '<S958>/Constant8' */

/* NVM存储动态续航上限值 */
CALDATA const volatile float32 KRME_NVMSOCCnsmDwLim_pctp100km = 0.0F;/* Referenced by: '<S981>/Constant2' */

/* NVM存储SOC消耗下限值（按照100km折算） */
CALDATA const volatile float32 KRME_NVMSOCCnsmUpLim_pctp100km = 200.0F;/* Referenced by: '<S981>/Constant1' */

/* NVM存储SOC消耗上限值（按照100km折算） */
CALDATA const volatile uint8 KRME_SOCCnsmStorRst_enum = 0U;/* Referenced by: '<S981>/Constant64' */

/* 重置SOCCnse数组存储值(标定使用) */
CALDATA const volatile boolean KRME_SOHCrctFacEnbl_flg = false;/* Referenced by: '<S951>/Constant2' */

/* 使用SOH对RptSOC修正 */
CALDATA const volatile boolean KRME_WLTPCtrlModeSel_flg = false;/* Referenced by: '<S958>/Constant13' */

/* WLTP控制方式选择:0-动态续航 1-查表WLTP续航 */
CALDATA const volatile float32 KRME_WLTPRmnMilEstVldOff_km = 25.0F;/* Referenced by: '<S958>/Constant17' */

/* 动态续航WLTP有效性Off */
CALDATA const volatile float32 KRME_WLTPRmnMilEstVldOn_km = 30.0F;/* Referenced by: '<S958>/Constant18' */

/* 动态续航WLTP有效性On */
CALDATA const volatile float32 KRME_WLTPStdUpLimFac_c = 1.16F;/* Referenced by: '<S960>/Constant7' */

/* 基于标准续航WLTP最大上限系数 */
CALDATA const volatile uint8 KSYS_CalVer_cnt = 20U;
                           /* Referenced by: '<S1492>/ASYS_HVBatPackTyp_X_Ah' */
CALDATA const volatile boolean KSYS_ChkTaskRunCnt_flg = false;
                          /* Referenced by: '<S1492>/ASYS_HVBatPackTyp_X_Ah1' */
CALDATA const volatile float32 KSYS_VehMass_kg = 1800.0F;/* Referenced by:
                                                          * '<S17>/KVTM_VehMass_kg'
                                                          * '<S1076>/KDAC_TapDwnTmOut_s'
                                                          * '<S1076>/KDAC_TapDwnTmOut_s1'
                                                          * '<S1076>/KDAC_TapDwnTmOut_s6'
                                                          * '<S1296>/KDAC_TapDwnTmOut_s1'
                                                          * '<S1167>/KDAC_TapDwnTmOut_s'
                                                          */
CALDATA const volatile float32 KSYS_VehTransRto_c = 12.1F;/* Referenced by:
                                                           * '<S875>/KSYS_VehTransRto_c'
                                                           * '<S1076>/KSYS_VehTransRto_c'
                                                           * '<S1098>/KSYS_VehTransRto_c'
                                                           * '<S1117>/KSYS_VehTransRto_c'
                                                           * '<S1117>/KSYS_VehTransRto_c1'
                                                           * '<S1447>/KSYS_VehTransRto_c3'
                                                           * '<S1448>/KSYS_VehTransRto_c1'
                                                           * '<S1448>/KSYS_VehTransRto_c2'
                                                           * '<S1260>/KSYS_VehTransRto_c'
                                                           * '<S1397>/KSYS_VehTransRto_c1'
                                                           * '<S1397>/KSYS_VehTransRto_c2'
                                                           * '<S1339>/KSYS_VehTransRto_c'
                                                           * '<S1340>/KSYS_VehTransRto_c'
                                                           * '<S1357>/KSYS_VehTransRto_c'
                                                           * '<S1357>/KSYS_VehTransRto_c1'
                                                           * '<S1314>/KSYS_VehTransRto_c'
                                                           */
CALDATA const volatile float32 KTBX_ChrgCondCfmTmr_s = 5.0F;/* Referenced by: '<S1034>/Constant3' */

/* 充电条件判断时间 */
CALDATA const volatile float32 KTBX_CnclSpdLimTmr_s = 2.0F;/* Referenced by: '<S1034>/Constant9' */

/* 取消限速等级确认时间 */
CALDATA const volatile float32 KTBX_LckVerCfmTmr_s = 10.0F;/* Referenced by: '<S1034>/Constant1' */

/* 锁车版本确认时间 */
CALDATA const volatile float32 KTBX_LoSpdCfmTmr_s = 5.0F;/* Referenced by: '<S1034>/Constant6' */

/* 低车速确认时间 */
CALDATA const volatile float32 KTBX_RecryCommCfmTmr_s = 2.0F;/* Referenced by: '<S1034>/Constant10' */

/* TBOX通讯恢复确认时间 */
CALDATA const volatile float32 KTBX_SpdLimCfmTmr_s = 5.0F;/* Referenced by:
                                                           * '<S1034>/Constant4'
                                                           * '<S1034>/Constant5'
                                                           * '<S1034>/Constant8'
                                                           */

/* 限速等级确认时间 */
CALDATA const volatile float32 KTBX_TBOXLostCommTmr_s = 120.0F;/* Referenced by: '<S1034>/Constant2' */

/* TBOX通讯丢失确认时间 */
CALDATA const volatile float32 KTBX_UnlckVerCfmTmr_s = 10.0F;/* Referenced by: '<S1034>/Constant' */

/* 非锁车版本确认时间 */
CALDATA const volatile float32 KTBX_VehLoSpdThr_kph = 1.0F;/* Referenced by:
                                                            * '<S1033>/Constant35'
                                                            * '<S1034>/Constant7'
                                                            */

/* 低车速阀值 */
CALDATA const volatile boolean KTQC_ABSInhbBrkRegen_flg = false;
                      /* Referenced by: '<S1261>/KTQD_CstRegenVehSpdOff_kph1' */
CALDATA const volatile float32 KTQC_ABSorESPActvTm1_s = 0.2F;
                      /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal' */
CALDATA const volatile float32 KTQC_ABSorESPActvTm2_s = 0.4F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal1' */
CALDATA const volatile float32 KTQC_BrkRegenTgtTqDecRate_Nmps = -10000.0F;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm5' */
CALDATA const volatile float32 KTQC_BrkRegenTgtTqIncRate_Nmps = 10000.0F;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm4' */
CALDATA const volatile float32 KTQC_CstRegenLmtTqDecRecry_Nmps = 2000.0F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal5' */
CALDATA const volatile float32 KTQC_CstRegenLmtTqDecSlow_Nmps = 10.0F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal4' */
CALDATA const volatile float32 KTQC_CstRegenLmtTqIncPhs1_Nmps = 1035.0F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal2' */
CALDATA const volatile float32 KTQC_CstRegenLmtTqIncPhs2_Nmps = 2070.0F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal3' */
CALDATA const volatile float32 KTQC_DrvTqHiDsblRBSDlyTm_s = 0.1F;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm3' */
CALDATA const volatile float32 KTQC_DrvTqHiDsblRBSThr_Nm = 20.0F;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm2' */
CALDATA const volatile float32 KTQC_DrvTqLoEnblRBSDlyTm_s = 0.1F;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm1' */
CALDATA const volatile float32 KTQC_DrvTqLoEnblRBSThr_Nm = -30.0F;
                        /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm' */
CALDATA const volatile float32 KTQC_ESCTqIntvAllwdVal_Nm = 6000.0F;/* Referenced by:
                                                                    * '<S1440>/DrvCtl_DrvMot_MaxTrqFlg_Cal'
                                                                    * '<S1440>/DrvCtl_DrvMot_MaxTrqFlg_Cal1'
                                                                    * '<S1260>/DrvCtl_DrvMot_MaxTrqFlg_Cal'
                                                                    * '<S1260>/DrvCtl_DrvMot_MaxTrqFlg_Cal1'
                                                                    */
CALDATA const volatile boolean KTQC_EnblBrkRsmCstRegen_flg = true;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal8' */
CALDATA const volatile boolean KTQC_EnblESPIntvBrkTgtZero_flg = true;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm6' */
CALDATA const volatile boolean KTQC_EnblRBSIntv_flg = true;
                       /* Referenced by: '<S1261>/KTQD_CstRegenVehSpdOff_kph' */
CALDATA const volatile float32 KTQC_RsmCstRegenAccPed_pct = 10.0F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal6' */
CALDATA const volatile float32 KTQC_RsmCstRegenTqReq_Nm = 100.0F;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal7' */
CALDATA const volatile float32 KTQD_AccelPedPrsdOff_pct = 1.0F;
                       /* Referenced by: '<S1322>/KTQD_CstRegenVehSpdOn_kph1' */
CALDATA const volatile float32 KTQD_AccelPedPrsdOn_pct = 2.0F;
                        /* Referenced by: '<S1322>/KTQD_CstRegenVehSpdOn_kph' */
CALDATA const volatile float32 KTQD_AdaptCstDsrdTqIMax_N = 3000.0F;
                                      /* Referenced by: '<S1296>/Saturation2' */
CALDATA const volatile float32 KTQD_AdaptCstDsrdTqIMin_N = -3000.0F;
                                      /* Referenced by: '<S1296>/Saturation2' */
CALDATA const volatile boolean KTQD_AdaptCstRegenEnbl_flg = false;
                      /* Referenced by: '<S1292>/KTQD_CstRegenVehSpdOff_kph1' */
CALDATA const volatile float32 KTQD_AdaptCstTgtAcceltnFiltTm_s = 0.03F;
                              /* Referenced by: '<S1296>/KDAC_TapDwnTmOut_s2' */
CALDATA const volatile float32 KTQD_AdaptCstVehSpdOff_kph = 8.0F;
                       /* Referenced by: '<S1292>/KTQD_CstRegenVehSpdOff_kph' */
CALDATA const volatile float32 KTQD_AdaptCstVehSpdOn_kph = 9.0F;
                        /* Referenced by: '<S1292>/KTQD_CstRegenVehSpdOn_kph' */
CALDATA const volatile float32 KTQD_BrkPedPrsd_pct = 1.0F;
                            /* Referenced by: '<S1291>/KTQD_BrkPedPstnHi_pct' */
CALDATA const volatile float32 KTQD_BrkPedReldDlyTm_s = 2.0F;
                           /* Referenced by: '<S1292>/KTQD_BrkPedPstnHi_pct2' */
CALDATA const volatile boolean KTQD_CrpEnbl_flg = true;
                       /* Referenced by: '<S1282>/Motohawk_KTQD_EnblEcrp_flg' */
CALDATA const volatile float32 KTQD_CrpRsmPedPstn_pct = 3.0F;
                           /* Referenced by: '<S1282>/KTQD_CrpRsmPedPstn_pct' */
CALDATA const volatile float32 KTQD_CstRegenTqFiltAchvd_Nm = 35.0F;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph1' */
CALDATA const volatile float32 KTQD_CstRegenTqReqWhlDecEnbl_Nmps = -1000.0F;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph3' */
CALDATA const volatile float32 KTQD_CstRegenTqReqWhlDec_Nmps = -200.0F;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph4' */
CALDATA const volatile float32 KTQD_CstRegenTqReqWhlIncEnbl_Nmps = 500.0F;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph2' */
CALDATA const volatile float32 KTQD_CstRegenVehSpdOff_kph = 1.0F;
                       /* Referenced by: '<S1291>/KTQD_CstRegenVehSpdOff_kph' */
CALDATA const volatile float32 KTQD_CstRegenVehSpdOn_kph = 1.5F;
                        /* Referenced by: '<S1291>/KTQD_CstRegenVehSpdOn_kph' */
CALDATA const volatile float32 KTQD_EPBAppliedMaxTq_Nm = 9999.0F;
                            /* Referenced by: '<S1321>/KTQD_LimpHomeMaxTq_Nm' */
CALDATA const volatile float32 KTQD_EnblDRShftVehSpd_kph = 5.0F;
                        /* Referenced by: '<S1314>/KTQD_EnblDRShftVehSpd_kph' */
CALDATA const volatile float32 KTQD_EnblDRShftWhlTq_Nm = 1.0F;
                          /* Referenced by: '<S1314>/KTQD_EnblDRShftWhlTq_Nm' */
CALDATA const volatile float32 KTQD_PedTqReqFiltCoeffMAA_c = 0.9995F;
                      /* Referenced by: '<S1321>/KCPT_MotorMaxTqFiltCoeff_c2' */
CALDATA const volatile float32 KTQD_PlugOnTqZeroSpd_kph = 5.0F;
                         /* Referenced by: '<S1312>/KTQD_TqZeroSpdPlugOn_kph' */
CALDATA const volatile float32 KTQD_TqDrtFacLmtPerfmnRate_cps = 0.1F;
                   /* Referenced by: '<S1323>/KTQD_TqDrtFacVehSpdIncRate_cps' */
CALDATA const volatile float32 KTQD_TqDrtFacVehSpdDecRate_cps = -0.4F;
                   /* Referenced by: '<S1327>/KTQD_TqDrtFacVehSpdDecRate_cps' */
CALDATA const volatile float32 KTQD_TqDrtFacVehSpdIncRate_cps = 0.4F;
                   /* Referenced by: '<S1327>/KTQD_TqDrtFacVehSpdIncRate_cps' */
CALDATA const volatile float32 KTQD_WhlSpdDiffFiltCoeff_c = 0.91F;
                       /* Referenced by: '<S1278>/KTQD_WhlSpdDiffFiltCoeff_c' */
CALDATA const volatile boolean KTQF_DsblEndFlgRateCond_flg = true;
                   /* Referenced by: '<S1338>/KTQF_DsblEndFlgRateCondInc_flg' */

/* set to false, change rate is considered when judging ending flag */
CALDATA const volatile float32 KTQF_TqDecDlyTm_s = 0.02F;
                               /* Referenced by: '<S1336>/KTQF_TqDecDelay_s ' */

/* torque increase judgement turn on delay */
CALDATA const volatile float32 KTQF_TqDecThr_Nm = -30.0F;
                                /* Referenced by: '<S1336>/KTQF_TqDecThr_Nm ' */

/* torque decrease judgement tq threshold */
CALDATA const volatile float32 KTQF_TqIncDlyTm_s = 0.02F;
                               /* Referenced by: '<S1336>/KTQF_TqIncDelay_s ' */

/* torque Decrease judgement turn on delay */
CALDATA const volatile float32 KTQF_TqIncThr_Nm = 30.0F;
                                /* Referenced by: '<S1336>/KTQF_TqIncThr_Nm ' */

/* torque increase judgement tq threshold */
CALDATA const volatile float32 KTQF_TqOutChgRateFilt_rat = 0.8F;
                     /* Referenced by: '<S1338>/KTQF_TqOutChgRateFiltInc_rat' */

/* torque output change rate filter */
CALDATA const volatile float32 KTQF_TqRateDecMaxEndg_Nmps = -2000.0F;
                       /* Referenced by: '<S1339>/KTQF_TqRateDecMaxEndg_Nmps' */

/* decrease tq rate max in ending or decreasing period */
CALDATA const volatile float32 KTQF_TqRateDecMaxRegenACC_Nmps = -4000.0F;
                      /* Referenced by: '<S1339>/KTQF_TqRateDecMaxEndg_Nmps1' */
CALDATA const volatile float32 KTQF_TqRateDecMaxStart_Nmps = -7000.0F;
                      /* Referenced by: '<S1339>/KTQF_TqRateDecMaxEndg_Nmps3' */
CALDATA const volatile float32 KTQF_TqRateDecMin_Nmps = -260.0F;/* Referenced by:
                                                                 * '<S1338>/KTQF_TqRateDecMin_Nmps'
                                                                 * '<S1339>/KTQF_TqRateDecMin_Nmps'
                                                                 */

/* Rate limit, max decreasing.  */
CALDATA const volatile float32 KTQF_TqRateIncMaxEndg_Nmps = 2000.0F;
                       /* Referenced by: '<S1340>/KTQF_TqRateIncMaxEndg_Nmps' */

/* increase tq rate max in ending or decreasing period */
CALDATA const volatile float32 KTQF_TqRateIncMin_Nmps = 260.0F;/* Referenced by:
                                                                * '<S1338>/KTQF_TqRateIncMin_Nmps'
                                                                * '<S1340>/KTQF_TqRateIncMin_Nmps'
                                                                */

/* Rate limit, min decreasing.  */
CALDATA const volatile float32 KTQF_TqRateLimEndErrFac_c = 0.8F;
                           /* Referenced by: '<S1338>/KTQF_TqRateLimEndTm_s1' */
CALDATA const volatile float32 KTQF_TqRateLimEndTm_s = 0.0F;
                            /* Referenced by: '<S1338>/KTQF_TqRateLimEndTm_s' */

/* Rate limit, target torque prediction time towards ending.  */
CALDATA const volatile float32 KTQF_TqRawChgRateFilt_rat = 0.8F;
                        /* Referenced by: '<S1338>/KTQF_TqRawChgRateFilt_rat' */

/* raw torque change rate filter */
CALDATA const volatile float32 KTQR_ABSActvDlyTm4Dampng_s = 0.2F;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg4' */
CALDATA const volatile float32 KTQR_ASDEnblOscSpd_rpm = 2.0F;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c3' */
CALDATA const volatile boolean KTQR_ASDEnbl_flg = false;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg6' */
CALDATA const volatile float32 KTQR_ASDOscTrigTm_s = 0.5F;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c1' */
CALDATA const volatile float32 KTQR_ASDPhCompKa_c = -0.6442F;/* Referenced by:
                                                              * '<S1368>/KTQR_MotDampngLmtFac_c13'
                                                              * '<S1368>/KTQR_MotDampngLmtFac_c2'
                                                              * '<S1368>/KTQR_MotDampngLmtFac_c6'
                                                              * '<S1368>/KTQR_MotDampngLmtFac_c9'
                                                              */
CALDATA const volatile float32 KTQR_ASDPhCompKb1_c = 1.0F;/* Referenced by:
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c10'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c11'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c3'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c7'
                                                           */
CALDATA const volatile float32 KTQR_ASDPhCompKb2_c = -0.94F;/* Referenced by:
                                                             * '<S1368>/KTQR_MotDampngLmtFac_c1'
                                                             * '<S1368>/KTQR_MotDampngLmtFac_c12'
                                                             * '<S1368>/KTQR_MotDampngLmtFac_c5'
                                                             * '<S1368>/KTQR_MotDampngLmtFac_c8'
                                                             */
CALDATA const volatile float32 KTQR_ASDSpdFiltHiDecRate_nu = -0.15F;
                          /* Referenced by: '<S1366>/KTQR_MotDampngLmtFac_c2' */
CALDATA const volatile float32 KTQR_ASDSpdFiltHiIncRate_nu = 15.0F;
                          /* Referenced by: '<S1366>/KTQR_MotDampngLmtFac_c1' */
CALDATA const volatile float32 KTQR_ASDSpdFiltLo_s = 0.01F;
                          /* Referenced by: '<S1366>/KTQR_MotDampngLmtFac_c3' */
CALDATA const volatile uint8 KTQR_ASDSpdPhCompCout_Cnt = 1U;
                          /* Referenced by: '<S1368>/KTQR_MotDampngLmtFac_c4' */
CALDATA const volatile float32 KTQR_ASDTqDbnd_Nm = 0.5F;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c4' */
CALDATA const volatile float32 KTQR_ASDTqMax_Nm = 10.0F;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c5' */
CALDATA const volatile float32 KTQR_ASDTqMin_Nm = -10.0F;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c6' */
CALDATA const volatile boolean KTQR_AllZeroCrsDsblDamp_flg = false;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg5' */
CALDATA const volatile boolean KTQR_BypassASDOscTrig_flg = true;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c2' */
CALDATA const volatile float32 KTQR_MotDampngBrkout_pct = 110.0F;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c5' */
CALDATA const volatile float32 KTQR_MotDampngLmtFac_c = 0.25F;
                           /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c' */
CALDATA const volatile float32 KTQR_MotDampngLmtMaxRate_Nmps = 10.0F;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c4' */
CALDATA const volatile float32 KTQR_MotDampngLmtMin_Nm = 0.5F;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c2' */
CALDATA const volatile float32 KTQR_MotDampngSpdOff_rpm = 5.0F;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c3' */
CALDATA const volatile float32 KTQR_MotDampngSpdOn_rpm = 10.0F;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c1' */
CALDATA const volatile boolean KTQR_MotorDampngDsblAZ_flg = false;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg3' */
CALDATA const volatile boolean KTQR_MotorDampngDsblBZ_flg = false;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg2' */
CALDATA const volatile boolean KTQR_MotorDampngDsblZX_flg = true;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg1' */
CALDATA const volatile boolean KTQR_MotorDampngEnbl_flg = false;
                          /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg' */
CALDATA const volatile float32 KTQR_MotorStdbyDlyTm_s = 3.0F;
                               /* Referenced by: '<S1364>/KTQF_TqIncDelay_s ' */
CALDATA const volatile boolean KTQR_MotorStdbyEnbl_flg = true;
                          /* Referenced by: '<S1364>/KTQR_EnblMotorStdby_flg' */
CALDATA const volatile float32 KTQR_MotorStdbyVehHaltHi_kph = 1.0F;
                     /* Referenced by: '<S1364>/KTQR_MotorStdbyVehHaltHi_kph' */
CALDATA const volatile float32 KTQR_MotorStdbyVehHaltLo_kph = 0.5F;
                     /* Referenced by: '<S1364>/KTQR_MotorStdbyVehHaltLo_kph' */
CALDATA const volatile float32 KTQR_MotorTqZeroDlyTm_s = 2.0F;
                              /* Referenced by: '<S1363>/KTQF_TqIncDelay_s 1' */
CALDATA const volatile float32 KTQR_MotorTqZero_Nm = 0.5F;
                    /* Referenced by: '<S1363>/KTQR_MotorStdbyVehHaltLo_kph1' */
CALDATA const volatile float32 KTZX_AZDMaxTm_s = 0.8F;
                                  /* Referenced by: '<S1393>/KTZX_AZDMaxTm_s' */
CALDATA const volatile float32 KTZX_AZIMaxTm_s = 0.8F;
                                  /* Referenced by: '<S1393>/KTZX_AZIMaxTm_s' */
CALDATA const volatile float32 KTZX_BrkPedPrsd_pct = 5.0F;
                              /* Referenced by: '<S1393>/KTZX_BrkPedPrsd_pct' */
CALDATA const volatile float32 KTZX_ClkZXTmD_s = 0.25F;
                                  /* Referenced by: '<S1393>/KTZX_ClkZXTmD_s' */
CALDATA const volatile float32 KTZX_ClkZXTmR_s = 0.25F;
                                  /* Referenced by: '<S1393>/KTZX_ClkZXTmR_s' */
CALDATA const volatile float32 KTZX_ClkZXTqD_Nm = 0.8F;
                                 /* Referenced by: '<S1393>/KTZX_ClkZXTqD_Nm' */
CALDATA const volatile float32 KTZX_ClkZXTqR_Nm = 0.8F;
                                 /* Referenced by: '<S1393>/KTZX_ClkZXTqR_Nm' */
CALDATA const volatile float32 KTZX_MotorTqDecDlyTm_s = 0.02F;
                               /* Referenced by: '<S1403>/KTQF_TqDecDelay_s ' */
CALDATA const volatile float32 KTZX_MotorTqDecThr_Nm = -3.0F;
                                /* Referenced by: '<S1403>/KTQF_TqDecThr_Nm ' */
CALDATA const volatile float32 KTZX_MotorTqIncDlyTm_s = 0.02F;
                               /* Referenced by: '<S1403>/KTQF_TqIncDelay_s ' */
CALDATA const volatile float32 KTZX_MotorTqIncThr_Nm = 3.0F;
                                /* Referenced by: '<S1403>/KTQF_TqIncThr_Nm ' */
CALDATA const volatile float32 KTZX_TMSpdBckThr_rpm = -8.0F;
                             /* Referenced by: '<S1393>/KTZX_TMSpdBckThr_rpm' */
CALDATA const volatile float32 KTZX_TMSpdFwdThr_rpm = 8.0F;
                             /* Referenced by: '<S1393>/KTZX_TMSpdFwdThr_rpm' */
CALDATA const volatile float32 KTZX_TqDsengCfmTm_s = 2.0F;
                              /* Referenced by: '<S1393>/KTZX_TqDsengCfmTm_s' */
CALDATA const volatile float32 KTZX_TqDsengThr_Nm = 0.5F;
                               /* Referenced by: '<S1393>/KTZX_TqDsengThr_Nm' */
CALDATA const volatile boolean KTZX_UseZeroTqAddRngFinshAZ_flg = false;/* Referenced by:
                                                                      * '<S1419>/KTZX_UseZeroTqAddRngFinshAZ_flg'
                                                                      * '<S1420>/KTZX_UseZeroTqAddRngFinshAZ_flg'
                                                                      */
CALDATA const volatile float32 KTZX_VehStopSpd_kph = 3.0F;
                              /* Referenced by: '<S1393>/KTZX_VehStopSpd_kph' */
CALDATA const volatile float32 KTZX_ZXRegenTqTgtThr_Nm = -9999.0F;
                            /* Referenced by: '<S1393>/KTZX_ZXRgnTqTgtThr_Nm' */
CALDATA const volatile uint16 KVCU_EcuCommReqOff_Cnt = 0U;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg4' */

/* _versteckt */
CALDATA const volatile uint16 KVCU_EcuCommReqOn_Cnt = 10U;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg1' */

/* _versteckt */
CALDATA const volatile boolean KVCU_EcuCommReq_flg = false;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg2' */

/* _versteckt */
CALDATA const volatile float32 KVCU_MCUTempWrngOff_C = 149.0F;
                         /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg3' */
CALDATA const volatile float32 KVCU_MCUTempWrngOn_C = 156.0F;
                        /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg15' */
CALDATA const volatile float32 KVCU_MotorTempWrngOff_C = 149.0F;
                         /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg2' */
CALDATA const volatile float32 KVCU_MotorTempWrngOn_C = 157.0F;
                         /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg1' */
CALDATA const volatile uint16 KVCU_RtcWakeupTm_min = 65535U;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg3' */

/* _versteckt */
CALDATA const volatile boolean KVCU_XWhlDistErrRefOvrdSw_flg = false;
                        /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg13' */

/* _versteckt */
CALDATA const volatile float32 KVCU_XWhlDistErrRefOvrdVal_mpkm = 0.0F;
                         /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg5' */

/* _versteckt */
CALDATA const volatile boolean KVCU_XWhlDistErrRefStatOvrdSw_flg = false;
                        /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg12' */

/* _versteckt */
CALDATA const volatile uint8 KVCU_XWhlDistErrRefStatOvrdVal_enum = 0U;
                         /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg6' */

/* _versteckt */
CALDATA const volatile boolean KVCU_iTPMSWrngOvrdSw_flg = false;
                        /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg11' */

/* _versteckt */
CALDATA const volatile boolean KVCU_iTPMSWrngOvrdVal_flg = false;
                         /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg4' */

/* _versteckt */
CALDATA const volatile float32 KVSO_AirBlowArea_m2 = 3.07F;/* Referenced by: '<S1098>/A' */
CALDATA const volatile float32 KVSO_AirResistCoeff_c = 0.3F;/* Referenced by: '<S1098>/Cd' */
CALDATA const volatile float32 KVSO_AvgXWhlDistErr1Fac_c = 0.0F;/* Referenced by: '<S1082>/Cnst3' */
CALDATA const volatile float32 KVSO_AvgXWhlDistErr2Fac_c = 0.0F;/* Referenced by: '<S1082>/Cnst1' */
CALDATA const volatile float32 KVSO_AvgXWhlDistErr3Fac_c = 1.0F;/* Referenced by: '<S1082>/Cnst2' */
CALDATA const volatile float32 KVSO_AvgXWhlDistErr4Fac_c = 0.0F;/* Referenced by: '<S1082>/Cnst4' */
CALDATA const volatile float32 KVSO_AvgXWhlDistErr5Fac_c = 0.0F;/* Referenced by: '<S1082>/Cnst5' */
CALDATA const volatile float32 KVSO_DistErrHldSlip_kph = 1.0F;/* Referenced by: '<S1086>/Cnst' */
CALDATA const volatile float32 KVSO_DistErrHldSpd_kph = 10.0F;/* Referenced by: '<S1086>/Cnst2' */
CALDATA const volatile float32 KVSO_DistErrHldStrg_kph = 1.0F;/* Referenced by:
                                                               * '<S1086>/Cnst1'
                                                               * '<S1086>/Cnst3'
                                                               */
CALDATA const volatile float32 KVSO_MassEstBrkPrsd_pct = 2.0F;
                          /* Referenced by: '<S1098>/KVSO_MassEstBrkPrsd_pct' */
CALDATA const volatile float32 KVSO_MassEstSpdLo_kph = -5.0F;
                            /* Referenced by: '<S1098>/KVSO_MassEstSpdLo_kph' */
CALDATA const volatile float32 KVSO_MotorActTqFiltTm_s = 0.05F;/* Referenced by: '<S1098>/Const1' */
CALDATA const volatile float32 KVSO_RSECovMeas_c = 10.0F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c3' */
CALDATA const volatile float32 KVSO_RSECovSlopFrc_c = 400000.0F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c1' */
CALDATA const volatile float32 KVSO_RSECovVehSpdSlopFrc_c = 0.0F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c2' */
CALDATA const volatile float32 KVSO_RSECovVehSpd_c = 10.0F;
                                 /* Referenced by: '<S1076>/KTQD_CovVehSpd_c' */
CALDATA const volatile float32 KVSO_RoadSlopTqFiltTm_s = 0.06F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c4' */
CALDATA const volatile float32 KVSO_RoadSlopTqHoldBrkPresr_bar = 3.0F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c7' */
CALDATA const volatile float32 KVSO_RoadSlopTqHoldSpd_kph = 0.2F;
                        /* Referenced by: '<S1076>/KVSO_OPDSlopTqHoldSpd_kph' */
CALDATA const volatile float32 KVSO_RoadSlopTqMax_Nm = 1800.0F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c5' */
CALDATA const volatile float32 KVSO_RoadSlopTqMin_Nm = -1800.0F;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c6' */
CALDATA const volatile float32 KVSO_RollgResistCoeff_c = 0.013F;/* Referenced by: '<S1098>/f' */
CALDATA const volatile float32 KVSO_RotMassCnvnCoeff_c = 1.0F;
                          /* Referenced by: '<S1098>/KVSO_RotMassCnvnCoeff_c' */
CALDATA const volatile float32 KVSO_SlopFiltTm_s = 0.2F;
                                /* Referenced by: '<S1098>/KVSO_SlopFiltTm_s' */
CALDATA const volatile float32 KVSO_TPMSLrnReqCfmTm_s = 2.0F;/* Referenced by: '<S1082>/Cnst7' */
CALDATA const volatile float32 KVSO_VMECovMeas_c = 0.001F;
                                   /* Referenced by: '<S1098>/KVSO_CovMeas_c' */
CALDATA const volatile float32 KVSO_VMECovSlop_c = 0.0006F;
                                   /* Referenced by: '<S1098>/KVSO_CovSlop_c' */
CALDATA const volatile float32 KVSO_VMECovVehMass_c = 800.0F;
                                /* Referenced by: '<S1098>/KVSO_CovVehMass_c' */
CALDATA const volatile float32 KVSO_VMECovVehSpd2_c = 100.0F;
                                /* Referenced by: '<S1098>/KVSO_CovVehSpd2_c' */
CALDATA const volatile float32 KVSO_VMECovVehSpd_c = 0.01F;
                                 /* Referenced by: '<S1098>/KVSO_CovVehSpd_c' */
CALDATA const volatile float32 KVSO_VehMassFiltTm_s = 0.2F;
                             /* Referenced by: '<S1098>/KVSO_VehMassFiltTm_s' */
CALDATA const volatile float32 KVSO_VehMassInit_kg = 1500.0F;
                              /* Referenced by: '<S1098>/KVSO_VehMassInit_kg' */
CALDATA const volatile float32 KVSO_VehResistPosTh_mps = 0.0556F;
                              /* Referenced by: '<S1076>/KDAC_TapDwnTmOut_s5' */
CALDATA const volatile float32 KVSO_VehSpdFiltTm_s = 0.05F;/* Referenced by: '<S1098>/Const' */
CALDATA const volatile float32 KVSO_VehTransEff_c = 0.96F;
                               /* Referenced by: '<S1098>/KVSO_VehTransEff_c' */
CALDATA const volatile float32 KVSO_WhlDistErrRecThr_m = 250.0F;
                             /* Referenced by: '<S1095>/KVSO_SpdErrRecDist_m' */
CALDATA const volatile float32 KVSO_WhlDistErrRefRecThr_m = 2000.0F;
                            /* Referenced by: '<S1095>/KVSO_SpdErrRecDist_m1' */
CALDATA const volatile float32 KVSO_XWhlDistErrExcd_mpkm = 1.8F;/* Referenced by: '<S1082>/Cnst6' */
CALDATA const volatile float32 KVTM_BrkLampOffRegenTq_Nm = -620.0F;/* Referenced by: '<S1447>/Constant8' */
CALDATA const volatile float32 KVTM_BrkLampOnRegenTq_Nm = -670.0F;/* Referenced by: '<S1447>/Constant9' */
CALDATA const volatile float32 KVTM_BrkPedReld_pct = 2.0F;
                            /* Referenced by: '<S1440>/KTQD_BrkPedPstnHi_pct' */
CALDATA const volatile float32 KVTM_MotorMaxDrvPwr_kW = 160.0F;
                              /* Referenced by: '<S1449>/KSYS_VehTransRto_c2' */
CALDATA const volatile float32 KVTM_MotorMaxRegenPwr_kW = -50.0F;
                              /* Referenced by: '<S1449>/KSYS_VehTransRto_c1' */
CALDATA const volatile float32 KVTM_MotorPwrTypeRecup_Nm = -2.8F;
                              /* Referenced by: '<S1449>/KSYS_VehTransRto_c4' */
CALDATA const volatile float32 KVTM_MotorSpdFiltCoeff_rat = 0.65F;
                       /* Referenced by: '<S1440>/KVTM_MotorSpdFiltCoeff_rat' */
CALDATA const volatile float32 KVTM_VehAcceltnFiltCoeff_rat = 0.93F;
                              /* Referenced by: '<S1440>/KDAC_TapDwnTmOut_s1' */
CALDATA const volatile float32 KVTM_VehAcceltnMax_mps2 = 10.0F;
                                      /* Referenced by: '<S1440>/Saturation1' */
CALDATA const volatile float32 KVTM_VehAcceltnMin_mps2 = -10.0F;
                                      /* Referenced by: '<S1440>/Saturation1' */
CALDATA const volatile float32 KVTM_VehSpdFiltCoeff_rat = 0.5F;
                      /* Referenced by: '<S1440>/KVTM_MotorSpdFiltCoeff_rat1' */
CALDATA const volatile float32 MCPT_MotorEffVoltFac_c[9] = { 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c1' */

CALDATA const volatile float32 MCPT_MotorSpdFiltCoeff_rat[8] = { 0.98F, 0.94F,
  0.9F, 0.87F, 0.78F, 0.6F, 0.5F, 0.5F } ;
                      /* Referenced by: '<S1117>/MPPC_OutSftSpdFiltCoeff_rat' */

CALDATA const volatile float32 MCPT_Pwr2MotorTqGen_Nm[616] = { -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, 0.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -138.955505F,
  -47.4619293F, 0.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -265.512543F, -174.791962F, -111.985733F, -55.6271973F,
  -22.4101963F, 0.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -225.301544F, -185.764221F, -147.330811F, -108.598351F, -71.7937F,
  -36.1558266F, -15.2032518F, 0.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -280.759277F,
  -222.117966F, -161.821518F, -133.54631F, -106.022728F, -79.1436462F,
  -52.8993454F, -27.0396137F, -11.5852337F, 0.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -313.236023F,
  -262.384277F, -215.112213F, -169.169586F, -125.399323F, -104.079376F,
  -83.1338425F, -62.4F, -41.9251328F, -21.6313553F, -9.42046833F, 0.0F, -330.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -292.159698F, -248.8172F, -211.636795F, -174.403107F, -138.359436F,
  -103.282272F, -85.9431229F, -68.8438263F, -51.8220787F, -34.9350204F,
  -18.1840534F, -7.81186104F, 0.0F, -330.0F, -330.0F, -330.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -308.642517F, -274.829926F, -241.167435F, -208.899292F,
  -177.671127F, -147.084061F, -117.198761F, -87.7354126F, -73.1641312F,
  -58.6999245F, -44.3231125F, -30.016489F, -15.6962786F, -6.63885975F, 0.0F,
  -330.0F, -330.0F, -330.0F, -330.0F, -330.0F, -322.981873F, -291.089478F,
  -263.667084F, -234.414886F, -206.933914F, -180.29808F, -153.766373F,
  -127.643547F, -101.921028F, -76.4671631F, -63.8475723F, -51.2644882F,
  -38.756546F, -26.2721577F, -13.6453867F, -5.59133482F, 0.0F, -330.0F, -330.0F,
  -330.0F, -330.0F, -328.473785F, -302.531708F, -273.164F, -247.416092F,
  -220.742218F, -195.120697F, -169.804184F, -145.091476F, -120.524147F,
  -96.4135208F, -72.3669815F, -60.5046425F, -48.6101494F, -36.8151894F,
  -25.0126705F, -13.0135069F, -5.31858587F, 0.0F, -330.0F, -330.0F, -330.0F,
  -327.937195F, -304.832245F, -279.48526F, -253.488678F, -229.652939F,
  -205.399323F, -181.647461F, -158.348373F, -135.397339F, -112.557587F,
  -90.0200272F, -67.6733551F, -56.534256F, -45.4915657F, -34.4097214F,
  -23.3977451F, -12.1783466F, -4.95267725F, 0.0F, -330.0F, -330.0F, -310.737518F,
  -290.021698F, -268.605194F, -246.540878F, -225.341034F, -203.885712F,
  -183.196442F, -162.290756F, -141.6577F, -121.157547F, -100.844772F,
  -80.6823044F, -60.7523499F, -50.7828827F, -40.8713684F, -30.9927616F,
  -21.0984459F, -11.015873F, -4.4470315F, 0.0F, -330.0F, -299.373047F,
  -280.662231F, -261.951416F, -242.257187F, -222.495667F, -202.957901F,
  -184.101944F, -165.205612F, -146.476547F, -128.05278F, -109.661507F,
  -91.2914658F, -73.1604462F, -55.1095238F, -46.1153603F, -37.1149521F,
  -28.1499538F, -19.1921291F, -10.157979F, -4.07119274F, 0.0F, -307.073944F,
  -272.95462F, -255.894958F, -238.835297F, -221.149551F, -202.957901F,
  -185.469635F, -168.191101F, -150.96463F, -133.952332F, -116.999649F,
  -100.209862F, -83.5082169F, -66.9851151F, -50.515995F, -42.3030624F,
  -34.1083679F, -25.9039249F, -17.670475F, -9.32981586F, -3.73192644F, 0.0F,
  -282.544373F, -251.150558F, -235.453644F, -219.756744F, -203.652969F,
  -187.107895F, -171.062027F, -155.067673F, -139.179047F, -123.512741F,
  -107.89624F, -92.4044495F, -77.0255356F, -61.771225F, -46.56707F, -38.9833183F,
  -31.4333153F, -23.8958588F, -16.350111F, -8.62224674F, -3.44889855F, 0.0F,
  -261.524414F, -232.466156F, -217.937012F, -203.407883F, -188.834045F,
  -173.753342F, -158.766586F, -143.883102F, -129.238495F, -114.70517F,
  -100.315117F, -85.9843903F, -71.7746201F, -57.6151123F, -43.5743561F,
  -36.5605202F, -29.5257549F, -22.5580044F, -15.5676165F, -8.29857445F,
  -3.31942987F, 0.0F, -244.610458F, -217.431519F, -203.842056F, -190.252579F,
  -176.53746F, -162.469681F, -148.44043F, -134.382584F, -120.649353F,
  -107.198578F, -93.7259064F, -80.4171F, -67.1944427F, -53.9682541F,
  -40.8624229F, -34.319973F, -27.785738F, -21.2691917F, -14.7256517F,
  -7.82145786F, -3.12858319F, 0.0F, -229.07782F, -203.624741F, -190.898193F,
  -178.171646F, -165.445099F, -152.351624F, -139.22847F, -126.177116F,
  -113.252403F, -100.632248F, -88.053215F, -75.539978F, -63.1580315F,
  -50.825592F, -38.4979515F, -32.3886909F, -26.2870274F, -20.1902447F,
  -14.0139751F, -7.40539694F, -2.96215892F, 0.0F, -216.294434F, -192.261719F,
  -180.245361F, -168.229F, -156.087097F, -143.601715F, -131.107925F,
  -118.878952F, -106.856461F, -94.9606171F, -83.0778885F, -71.312973F,
  -59.6447487F, -48.0301094F, -36.4536781F, -30.6860733F, -24.9392509F,
  -19.1792927F, -13.321475F, -6.97844362F, -2.79137731F, 0.0F, -204.49678F,
  -181.774918F, -170.413986F, -159.053055F, -147.657F, -136.019348F,
  -124.215317F, -112.501221F, -101.070663F, -89.8323517F, -78.7675247F,
  -67.5767F, -56.6104813F, -45.6419106F, -34.7062836F, -29.2672615F,
  -23.8088703F, -18.3705959F, -12.9787712F, -6.9082756F, -2.76331019F, 0.0F,
  -194.149536F, -172.577362F, -161.791275F, -151.005188F, -140.219116F,
  -129.110138F, -117.810989F, -106.795181F, -96.0442505F, -85.3726654F,
  -74.7786865F, -64.2753525F, -53.8078575F, -43.4264679F, -33.1126F, -27.9543F,
  -22.7831917F, -17.6388073F, -12.5255661F, -6.63978291F, -2.65591311F, 0.0F,
  -184.640167F, -164.124603F, -153.866806F, -143.609024F, -133.351242F,
  -122.71801F, -112.168678F, -101.74482F, -91.1960144F, -80.9411774F,
  -71.2068939F, -61.363636F, -51.4537888F, -41.5718727F, -31.704546F,
  -26.7849789F, -21.8724289F, -16.9816132F, -12.104188F, -6.37516689F,
  -2.55006671F, 0.0F, -176.036865F, -156.477219F, -146.697388F, -136.917557F,
  -127.137733F, -117.191833F, -106.937286F, -97.0392F, -87.2908478F,
  -77.6715088F, -68.0573044F, -58.5448647F, -49.1436501F, -39.6939125F,
  -30.3845596F, -25.7472935F, -21.1115971F, -16.4578457F, -11.7984F,
  -6.19566631F, -2.47826648F, 0.0F, -168.035187F, -149.364609F, -140.029327F,
  -130.694031F, -121.358749F, -111.830193F, -102.302643F, -92.8146057F,
  -83.4790192F, -74.2889938F, -65.1907349F, -56.1563835F, -47.1772308F,
  -38.2306519F, -29.2603054F, -24.7666111F, -20.2729149F, -15.9104586F,
  -11.556488F, -6.08823156F, -2.43529272F, 0.0F, -160.729309F, -142.870499F,
  -133.941101F, -125.011688F, -116.082283F, -107.090302F, -97.9735489F,
  -88.9208908F, -80.1052322F, -71.3355713F, -62.628727F, -53.9772224F,
  -45.3927345F, -36.8426704F, -28.256321F, -23.913044F, -19.5903339F,
  -15.4547033F, -11.3190718F, -5.94867325F, -2.37946939F, 0.0F, -154.198059F,
  -137.064941F, -128.498383F, -119.931824F, -111.365257F, -102.798714F,
  -94.059494F, -85.3499298F, -76.8396225F, -68.5162201F, -60.2777786F,
  -51.8967323F, -43.6315079F, -35.4718246F, -27.261652F, -23.0464344F, -18.9119F,
  -14.9876728F, -11.0634451F, -5.78367233F, -2.31346893F, 0.0F, -148.349518F,
  -131.866241F, -123.624603F, -115.382957F, -107.141319F, -98.8778915F,
  -90.4730453F, -82.1029587F, -73.9916F, -66.0655746F, -58.1505394F,
  -49.9378891F, -42.0289841F, -34.1743584F, -26.2222214F, -22.1798935F,
  -18.2677174F, -14.5078735F, -10.7480316F, -5.55232573F, -2.22093034F, 0.0F,
  -143.106888F, -127.206131F, -119.255737F, -111.305359F, -103.35498F, -95.3594F,
  -87.3131943F, -79.252182F, -71.3869247F, -63.5077591F, -55.8609924F,
  -48.3698692F, -40.7572746F, -33.1729774F, -25.4020042F, -21.4482079F,
  -17.7531929F, -14.2077513F, -10.6623106F, -5.51513052F, -2.2060523F, 0.0F } ;
                          /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm1' */

CALDATA const volatile float32 MCPT_Pwr2MotorTqMot_Nm[588] = { 0.0F, 141.973648F,
  288.662964F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  0.0F, 30.5270634F, 75.2212372F, 141.973648F, 249.603607F, 326.713623F, 330.0F,
  330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 330.0F, 330.0F, 330.0F, 0.0F, 15.9589663F, 41.2223816F, 82.1576F,
  161.102219F, 226.121155F, 285.616577F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 0.0F,
  10.27386F, 27.9216042F, 56.7725563F, 112.462059F, 165.365692F, 218.042633F,
  265.973633F, 304.84137F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 0.0F, 7.8119F, 20.9665089F,
  43.0910606F, 86.5534F, 128.828506F, 169.628036F, 208.997498F, 247.640488F,
  285.593811F, 325.082F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 330.0F, 330.0F, 0.0F, 6.28772F, 16.6026478F, 34.6001854F, 70.2116F,
  105.141129F, 139.362671F, 172.693741F, 205.224243F, 237.931686F, 267.73465F,
  298.512573F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 0.0F, 5.2525F, 13.6490154F, 28.7920284F, 58.8085976F, 88.433F,
  117.683548F, 146.48674F, 174.768188F, 202.61586F, 230.202484F, 256.261292F,
  283.03775F, 306.717163F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F, 330.0F,
  330.0F, 0.0F, 4.4966855F, 11.4579496F, 24.6025753F, 50.5993156F, 76.3452682F,
  102.266853F, 127.187599F, 152.055145F, 176.73494F, 200.995636F, 224.940613F,
  248.929916F, 271.449158F, 294.575439F, 315.426331F, 330.0F, 330.0F, 330.0F,
  330.0F, 330.0F, 0.0F, 3.8582F, 9.6455F, 20.9918079F, 44.1336517F, 67.0264359F,
  90.1488419F, 112.331917F, 134.162979F, 156.156418F, 177.860031F, 199.221F,
  220.605F, 241.735809F, 261.972321F, 281.888763F, 301.2005F, 321.153107F,
  330.0F, 330.0F, 330.0F, 0.0F, 3.70671415F, 9.26678562F, 20.1777515F,
  42.1759644F, 63.6072769F, 85.3556595F, 107.107147F, 127.663269F, 148.494751F,
  169.30629F, 189.847427F, 210.895889F, 230.984161F, 250.876572F, 270.348083F,
  290.491028F, 308.754608F, 329.851715F, 330.0F, 330.0F, 0.0F, 3.50166678F,
  8.7541666F, 18.9006062F, 39.3677826F, 59.9098549F, 80.1364136F, 100.275F,
  120.325523F, 139.799072F, 159.43042F, 178.818817F, 198.251099F, 217.395462F,
  236.746109F, 255.301468F, 273.430298F, 292.900635F, 310.330566F, 329.029327F,
  330.0F, 0.0F, 3.14768F, 7.8692F, 16.8372421F, 35.5149155F, 54.0020638F,
  72.313446F, 90.6430206F, 108.781036F, 126.608841F, 144.477722F, 162.233337F,
  179.923386F, 197.656738F, 215.203888F, 232.236237F, 248.776428F, 264.621582F,
  281.152F, 298.724F, 316.296F, 0.0F, 2.85458183F, 7.13645458F, 15.1435289F,
  32.0926514F, 49.0575943F, 65.9748459F, 82.6868744F, 99.1732635F, 115.760208F,
  132.208939F, 148.481445F, 164.615204F, 180.47583F, 196.097702F, 211.692444F,
  227.241226F, 241.649246F, 255.384964F, 270.681732F, 286.604187F, 0.0F,
  2.62306666F, 6.55766678F, 13.730092F, 29.3136463F, 44.8024254F, 60.3640404F,
  75.7808075F, 91.107F, 106.364807F, 121.456139F, 136.330856F, 151.168884F,
  165.771561F, 180.286636F, 194.338196F, 208.23909F, 221.980743F, 235.566666F,
  250.289581F, 265.012512F, 0.0F, 2.42716932F, 6.06792307F, 12.5749922F,
  27.0604076F, 41.4337463F, 55.7174759F, 69.9345551F, 84.137764F, 98.1328278F,
  112.105186F, 125.934883F, 139.588165F, 153.106308F, 166.438843F, 179.563599F,
  192.604095F, 204.480911F, 216.813431F, 230.287231F, 243.833542F, 0.0F,
  2.25652862F, 5.64132166F, 11.5497885F, 25.1227608F, 38.4272461F, 51.778553F,
  65.0135727F, 78.1600723F, 91.2025F, 104.183197F, 117.048813F, 129.749878F,
  142.343552F, 154.71727F, 166.874786F, 178.702347F, 189.094528F, 201.25943F,
  213.83815F, 226.416855F, 0.0F, 2.10609341F, 5.26523352F, 10.6224794F,
  23.1133232F, 35.7716F, 48.1796417F, 60.6106682F, 72.852005F, 85.2511673F,
  97.5419846F, 109.355324F, 120.966667F, 132.933243F, 144.354874F, 155.64389F,
  166.555389F, 176.59433F, 187.638397F, 199.365799F, 211.093201F, 0.0F, 1.9482F,
  4.8705F, 9.741F, 21.5365162F, 33.3248482F, 45.0230942F, 56.674942F,
  68.1754913F, 79.7144241F, 91.0842209F, 102.254433F, 113.43866F, 124.492233F,
  135.340591F, 145.872284F, 155.293472F, 164.435623F, 174.574F, 185.484879F,
  196.395752F, 0.0F, 1.80663526F, 4.51658821F, 9.03317642F, 19.9735565F,
  31.0158825F, 42.09795F, 53.0533676F, 64.0331345F, 74.8339767F, 85.568F,
  96.264F, 106.651291F, 116.984451F, 127.148453F, 137.159958F, 146.145233F,
  154.726196F, 163.945419F, 174.192F, 184.438583F, 0.0F, 1.66806662F,
  4.17016649F, 8.34033298F, 18.4956455F, 28.9560776F, 39.3544693F, 49.6478577F,
  59.9731407F, 70.1941452F, 80.3078156F, 90.4339142F, 100.376717F, 110.28096F,
  119.59433F, 129.399567F, 138.340652F, 145.606339F, 153.479111F, 163.071548F,
  172.664F, 0.0F, 1.56016839F, 3.90042114F, 7.80084229F, 17.7528687F, 27.391573F,
  37.0809784F, 46.9517365F, 56.6864319F, 66.2632294F, 75.9066391F, 85.4976349F,
  94.9449844F, 104.286423F, 113.457993F, 122.293007F, 130.654846F, 138.86879F,
  147.974731F, 157.22316F, 166.471573F, 0.0F, 1.44014F, 3.60035F, 7.2007F,
  16.0019093F, 25.5519352F, 34.9624481F, 44.3057976F, 53.6597443F, 62.9949913F,
  72.085144F, 81.8594818F, 91.0107422F, 99.3292F, 109.027138F, 116.126556F,
  123.333153F, 131.217F, 139.964798F, 148.712601F, 157.460403F, 0.0F,
  1.36064768F, 3.40161896F, 6.80323792F, 14.8500891F, 24.0256824F, 33.1186371F,
  41.9904709F, 50.8382034F, 59.6442032F, 68.2393951F, 76.9595F, 85.5332108F,
  93.919281F, 102.140541F, 110.155022F, 116.795029F, 124.28643F, 132.572189F,
  140.857956F, 149.143707F, 0.0F, 1.28143632F, 3.20359087F, 6.40718174F,
  13.8533735F, 22.5799885F, 31.1900387F, 39.7447624F, 48.2019F, 56.6346664F,
  64.9822083F, 73.3269119F, 81.6798248F, 89.7719421F, 97.452179F, 104.736519F,
  111.531593F, 117.468803F, 124.462547F, 132.241455F, 140.02037F, 0.0F,
  1.21409571F, 3.03523922F, 6.07047844F, 12.8116989F, 20.8496685F, 29.4897F,
  37.6607132F, 45.7995415F, 53.8879166F, 61.907917F, 69.8779373F, 77.8464127F,
  85.4227142F, 92.7946F, 100.058006F, 105.957512F, 112.357826F, 119.848351F,
  127.338867F, 134.829391F, 0.0F, 1.179425F, 2.94856238F, 5.89712477F,
  12.4534788F, 20.5064449F, 28.4013596F, 36.2372704F, 44.0253181F, 51.7537231F,
  59.3844147F, 66.9827881F, 74.4519119F, 81.7180176F, 88.6227722F, 94.8839111F,
  101.166344F, 108.392502F, 115.618668F, 122.844833F, 130.071F, 0.0F,
  1.11391199F, 2.78478F, 5.56956F, 11.6060648F, 19.4586849F, 26.9322662F,
  34.4249725F, 41.9096413F, 49.276844F, 56.6983604F, 64.0069885F, 71.2048F,
  78.3252792F, 84.7059555F, 90.8063278F, 96.5813217F, 102.796204F, 109.649277F,
  116.502357F, 123.355438F, 0.0F, 1.06519234F, 2.66298079F, 5.32596159F,
  10.9314747F, 18.5412655F, 25.9835796F, 32.7927246F, 38.8979645F, 46.9587975F,
  54.3899841F, 61.0519714F, 66.9039688F, 73.9052887F, 81.5337296F, 87.3207474F,
  93.59F, 100.275F, 106.96F, 113.645F, 120.33F } ;
                           /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm' */

CALDATA const volatile float32 MCPT_TqDrtFacIgbtTemp_c[8] = { 1.0F, 1.0F, 1.0F,
  0.66F, 0.33F, 0.0F, 0.0F, 0.0F } ;
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c2' */

CALDATA const volatile float32 MCPT_TqDrtFacMotorTemp_c[8] = { 1.0F, 1.0F, 1.0F,
  0.5F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c4' */

CALDATA const volatile float32 MDAC_ACCDsrdTqKi_c[225] = { 1125.0F, 1215.0F,
  1285.0F, 1346.0F, 1398.0F, 1435.0F, 1462.0F, 1480.0F, 1520.0F, 1615.0F,
  1714.0F, 1800.0F, 1894.0F, 2250.0F, 2250.0F, 1090.0F, 1172.0F, 1236.0F,
  1291.0F, 1339.0F, 1372.0F, 1397.0F, 1414.0F, 1450.0F, 1537.0F, 1627.0F,
  1706.0F, 1792.0F, 2117.0F, 2117.0F, 972.0F, 1031.0F, 1077.0F, 1117.0F, 1152.0F,
  1176.0F, 1194.0F, 1206.0F, 1232.0F, 1295.0F, 1361.0F, 1417.0F, 1480.0F,
  1715.0F, 1715.0F, 878.0F, 922.0F, 957.0F, 988.0F, 1014.0F, 1032.0F, 1046.0F,
  1055.0F, 1075.0F, 1122.0F, 1172.0F, 1215.0F, 1262.0F, 1440.0F, 1440.0F, 818.0F,
  855.0F, 884.0F, 909.0F, 931.0F, 946.0F, 957.0F, 965.0F, 981.0F, 1021.0F,
  1062.0F, 1098.0F, 1137.0F, 1285.0F, 1285.0F, 765.0F, 796.0F, 821.0F, 842.0F,
  861.0F, 874.0F, 883.0F, 889.0F, 904.0F, 937.0F, 972.0F, 1002.0F, 1035.0F,
  1161.0F, 1161.0F, 720.0F, 747.0F, 768.0F, 786.0F, 802.0F, 813.0F, 821.0F,
  826.0F, 838.0F, 867.0F, 897.0F, 923.0F, 951.0F, 1058.0F, 1058.0F, 889.0F,
  920.0F, 923.0F, 928.0F, 880.0F, 837.0F, 800.0F, 750.0F, 800.0F, 837.0F, 880.0F,
  928.0F, 923.0F, 920.0F, 889.0F, 1058.0F, 1058.0F, 951.0F, 923.0F, 897.0F,
  867.0F, 838.0F, 826.0F, 821.0F, 813.0F, 802.0F, 786.0F, 768.0F, 747.0F, 720.0F,
  1161.0F, 1161.0F, 1035.0F, 1002.0F, 972.0F, 937.0F, 904.0F, 889.0F, 883.0F,
  874.0F, 861.0F, 842.0F, 821.0F, 796.0F, 765.0F, 1285.0F, 1285.0F, 1137.0F,
  1098.0F, 1062.0F, 1021.0F, 981.0F, 965.0F, 957.0F, 946.0F, 931.0F, 909.0F,
  884.0F, 855.0F, 818.0F, 1440.0F, 1440.0F, 1262.0F, 1215.0F, 1172.0F, 1122.0F,
  1075.0F, 1055.0F, 1046.0F, 1032.0F, 1014.0F, 988.0F, 957.0F, 922.0F, 878.0F,
  1715.0F, 1715.0F, 1480.0F, 1417.0F, 1361.0F, 1295.0F, 1232.0F, 1206.0F,
  1194.0F, 1176.0F, 1152.0F, 1117.0F, 1077.0F, 1031.0F, 972.0F, 2117.0F, 2117.0F,
  1792.0F, 1706.0F, 1627.0F, 1537.0F, 1450.0F, 1414.0F, 1397.0F, 1372.0F,
  1339.0F, 1291.0F, 1236.0F, 1172.0F, 1090.0F, 2250.0F, 2250.0F, 1894.0F,
  1800.0F, 1714.0F, 1615.0F, 1520.0F, 1480.0F, 1462.0F, 1435.0F, 1398.0F,
  1346.0F, 1285.0F, 1215.0F, 1125.0F } ;
                      /* Referenced by: '<S1145>/MDAC_CCSDsrdTqKi_fac_IntTbl' */

CALDATA const volatile float32 MDAC_ACCDsrdTqKp_c[15] = { 2000.0F, 1000.0F,
  600.0F, 500.0F, 400.0F, 200.0F, 0.0F, 0.0F, 0.0F, 200.0F, 400.0F, 500.0F,
  600.0F, 1000.0F, 2000.0F } ;
                      /* Referenced by: '<S1145>/MDAC_CCSDsrdTqKp_fac_IntTbl' */

CALDATA const volatile float32 MDAC_ACCOvrdTqOff_Nm[7] = { 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F } ;/* Referenced by: '<S1139>/MTQD_CstTqReqWhlS_Nm1' */

CALDATA const volatile float32 MDAC_ACCOvrdTqOn_Nm[7] = { 20.0F, 20.0F, 20.0F,
  20.0F, 20.0F, 20.0F, 20.0F } ;
                             /* Referenced by: '<S1139>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MDAC_CCDsrdAcceltnDec_mps3[12] = { -20.0F, -20.0F,
  -20.0F, -20.0F, -10.0F, -2.0F, -2.0F, -2.0F, -2.0F, -1.0F, -0.03F, -0.2F } ;
                /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm1' */

CALDATA const volatile float32 MDAC_CCDsrdAcceltnInc_mps3[12] = { 0.1F, 0.1F,
  1.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 3.0F, 5.0F } ;
                 /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm' */

CALDATA const volatile float32 MDAC_CCDsrdAcceltn_mps2[126] = { -0.9F, -0.9F,
  -0.9F, -0.9F, -0.9F, -0.9F, -0.9F, -0.9F, -0.9F, -0.9F, -0.9F, -0.9F, -0.85F,
  -0.85F, -0.85F, -0.85F, -0.85F, -0.85F, -0.8F, -0.8F, -0.8F, -0.8F, -0.8F,
  -0.8F, -0.8F, -0.8F, -0.8F, -0.8F, -0.8F, -0.8F, -0.7F, -0.7F, -0.7F, -0.7F,
  -0.7F, -0.7F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.4F, -0.4F, -0.4F,
  -0.4F, -0.4F, -0.4F, -0.3F, -0.3F, -0.3F, -0.3F, -0.3F, -0.3F, -0.15F, -0.15F,
  -0.15F, -0.15F, -0.15F, -0.15F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.4F,
  0.4F, 0.4F, 0.4F, 0.4F, 0.4F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.7F, 0.7F,
  0.7F, 0.7F, 0.7F, 0.7F, 0.85F, 0.85F, 0.85F, 0.8F, 0.8F, 0.8F, 1.0F, 1.0F,
  0.95F, 0.9F, 0.85F, 0.85F, 1.1F, 1.1F, 1.0F, 1.0F, 0.9F, 0.9F, 1.2F, 1.2F,
  1.1F, 1.0F, 1.0F, 1.0F, 1.2F, 1.2F, 1.1F, 1.0F, 1.0F, 1.0F } ;
                   /* Referenced by: '<S1161>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

CALDATA const volatile float32 MDAC_CCDsrdTqKi_c[225] = { 100.0F, 100.0F, 100.0F,
  150.0F, 150.0F, 300.0F, 300.0F, 750.0F, 800.0F, 857.0F, 1714.0F, 1800.0F,
  1894.0F, 2250.0F, 2250.0F, 200.0F, 200.0F, 300.0F, 300.0F, 400.0F, 400.0F,
  400.0F, 750.0F, 800.0F, 857.0F, 1636.0F, 1714.0F, 1800.0F, 2117.0F, 2117.0F,
  200.0F, 200.0F, 300.0F, 300.0F, 400.0F, 400.0F, 400.0F, 750.0F, 800.0F, 857.0F,
  1384.0F, 1565.0F, 1636.0F, 1714.0F, 1714.0F, 200.0F, 200.0F, 400.0F, 400.0F,
  400.0F, 400.0F, 400.0F, 750.0F, 800.0F, 857.0F, 1200.0F, 1333.0F, 1384.0F,
  1440.0F, 1440.0F, 200.0F, 200.0F, 400.0F, 400.0F, 400.0F, 400.0F, 400.0F,
  750.0F, 800.0F, 857.0F, 1090.0F, 1200.0F, 1241.0F, 1285.0F, 1285.0F, 500.0F,
  500.0F, 500.0F, 500.0F, 500.0F, 500.0F, 500.0F, 750.0F, 800.0F, 857.0F,
  1000.0F, 1090.0F, 1125.0F, 1161.0F, 1161.0F, 500.0F, 500.0F, 500.0F, 500.0F,
  500.0F, 500.0F, 500.0F, 750.0F, 800.0F, 857.0F, 923.0F, 1000.0F, 1028.0F,
  1058.0F, 1058.0F, 500.0F, 500.0F, 500.0F, 500.0F, 500.0F, 500.0F, 500.0F,
  750.0F, 800.0F, 837.0F, 880.0F, 928.0F, 923.0F, 920.0F, 889.0F, 1058.0F,
  1058.0F, 1028.0F, 1000.0F, 923.0F, 857.0F, 800.0F, 750.0F, 800.0F, 818.0F,
  837.0F, 857.0F, 818.0F, 782.0F, 720.0F, 1161.0F, 1161.0F, 1125.0F, 1090.0F,
  1000.0F, 857.0F, 800.0F, 750.0F, 857.0F, 878.0F, 900.0F, 923.0F, 878.0F,
  837.0F, 765.0F, 1285.0F, 1285.0F, 1241.0F, 1200.0F, 1090.0F, 857.0F, 800.0F,
  750.0F, 923.0F, 947.0F, 972.0F, 1000.0F, 947.0F, 900.0F, 818.0F, 1440.0F,
  1440.0F, 1384.0F, 1333.0F, 1200.0F, 857.0F, 800.0F, 750.0F, 1000.0F, 1028.0F,
  1058.0F, 1090.0F, 1028.0F, 972.0F, 878.0F, 1714.0F, 1714.0F, 1636.0F, 1565.0F,
  1384.0F, 857.0F, 800.0F, 750.0F, 1125.0F, 1161.0F, 1200.0F, 1241.0F, 1161.0F,
  1090.0F, 972.0F, 2117.0F, 2117.0F, 2000.0F, 1894.0F, 1636.0F, 857.0F, 800.0F,
  750.0F, 1285.0F, 1333.0F, 1384.0F, 1333.0F, 1241.0F, 1241.0F, 1090.0F, 2250.0F,
  2250.0F, 2117.0F, 2000.0F, 1714.0F, 857.0F, 800.0F, 750.0F, 1333.0F, 1384.0F,
  1440.0F, 1384.0F, 1285.0F, 1285.0F, 1125.0F } ;
                      /* Referenced by: '<S1168>/MDAC_CCSDsrdTqKi_fac_IntTbl' */

CALDATA const volatile float32 MDAC_CCDsrdTqKp_c[15] = { 2000.0F, 800.0F, 600.0F,
  400.0F, 200.0F, 100.0F, 0.0F, 0.0F, 0.0F, 100.0F, 400.0F, 500.0F, 600.0F,
  1000.0F, 2000.0F } ;/* Referenced by: '<S1168>/MDAC_CCSDsrdTqKp_fac_IntTbl' */

CALDATA const volatile float32 MDAC_CCMaxDrgTqWhl_Nm[14] = { 0.0F, -20.0F,
  -20.0F, -30.0F, -50.0F, -135.0F, -377.0F, -586.0F, -616.0F, -624.0F, -585.0F,
  -536.0F, -425.0F, -261.0F } ;
                             /* Referenced by: '<S1170>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MDAC_CCSpdStabLowerOfst_kph[8] = { 8.0F, 10.0F,
  15.0F, 20.0F, 25.0F, 30.0F, 35.0F, 40.0F } ;
                            /* Referenced by: '<S1197>/MTQD_CstTqReqWhlS_Nm1' */

CALDATA const volatile float32 MDAC_CCSpdStabUpprOfst_kph[8] = { 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F } ;
                             /* Referenced by: '<S1197>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MDAC_FullPedDrvTqWhl_Nm[23] = { 2898.0F, 2898.0F,
  2898.0F, 2898.0F, 2898.0F, 2898.0F, 2898.0F, 2898.0F, 2898.0F, 2898.0F,
  2898.0F, 2867.0F, 2711.0F, 2328.0F, 1987.0F, 1728.0F, 1552.0F, 1366.0F,
  1221.0F, 1097.0F, 1014.0F, 900.0F, 828.0F } ;
                                 /* Referenced by: '<S1134>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 MDAC_HDCDsrdTqKi_c[225] = { 1125.0F, 1215.0F,
  1285.0F, 1346.0F, 1398.0F, 1435.0F, 1462.0F, 1480.0F, 1520.0F, 1615.0F,
  1714.0F, 1800.0F, 1894.0F, 2250.0F, 2250.0F, 1090.0F, 1172.0F, 1236.0F,
  1291.0F, 1339.0F, 1372.0F, 1397.0F, 1414.0F, 1450.0F, 1537.0F, 1627.0F,
  1706.0F, 1792.0F, 2117.0F, 2117.0F, 972.0F, 1031.0F, 1077.0F, 1117.0F, 1152.0F,
  1176.0F, 1194.0F, 1206.0F, 1232.0F, 1295.0F, 1361.0F, 1417.0F, 1480.0F,
  1715.0F, 1715.0F, 878.0F, 922.0F, 957.0F, 988.0F, 1014.0F, 1032.0F, 1046.0F,
  1055.0F, 1075.0F, 1122.0F, 1172.0F, 1215.0F, 1262.0F, 1440.0F, 1440.0F, 818.0F,
  855.0F, 884.0F, 909.0F, 931.0F, 946.0F, 957.0F, 965.0F, 981.0F, 1021.0F,
  1062.0F, 1098.0F, 1137.0F, 1285.0F, 1285.0F, 765.0F, 796.0F, 821.0F, 842.0F,
  861.0F, 874.0F, 883.0F, 889.0F, 904.0F, 937.0F, 972.0F, 1002.0F, 1035.0F,
  1161.0F, 1161.0F, 720.0F, 747.0F, 768.0F, 786.0F, 802.0F, 813.0F, 821.0F,
  826.0F, 838.0F, 867.0F, 897.0F, 923.0F, 951.0F, 1058.0F, 1058.0F, 889.0F,
  920.0F, 923.0F, 928.0F, 880.0F, 837.0F, 800.0F, 750.0F, 800.0F, 837.0F, 880.0F,
  928.0F, 923.0F, 920.0F, 889.0F, 1058.0F, 1058.0F, 951.0F, 923.0F, 897.0F,
  867.0F, 838.0F, 826.0F, 821.0F, 813.0F, 802.0F, 786.0F, 768.0F, 747.0F, 720.0F,
  1161.0F, 1161.0F, 1035.0F, 1002.0F, 972.0F, 937.0F, 904.0F, 889.0F, 883.0F,
  874.0F, 861.0F, 842.0F, 821.0F, 796.0F, 765.0F, 1285.0F, 1285.0F, 1137.0F,
  1098.0F, 1062.0F, 1021.0F, 981.0F, 965.0F, 957.0F, 946.0F, 931.0F, 909.0F,
  884.0F, 855.0F, 818.0F, 1440.0F, 1440.0F, 1262.0F, 1215.0F, 1172.0F, 1122.0F,
  1075.0F, 1055.0F, 1046.0F, 1032.0F, 1014.0F, 988.0F, 957.0F, 922.0F, 878.0F,
  1715.0F, 1715.0F, 1480.0F, 1417.0F, 1361.0F, 1295.0F, 1232.0F, 1206.0F,
  1194.0F, 1176.0F, 1152.0F, 1117.0F, 1077.0F, 1031.0F, 972.0F, 2117.0F, 2117.0F,
  1792.0F, 1706.0F, 1627.0F, 1537.0F, 1450.0F, 1414.0F, 1397.0F, 1372.0F,
  1339.0F, 1291.0F, 1236.0F, 1172.0F, 1090.0F, 2250.0F, 2250.0F, 1894.0F,
  1800.0F, 1714.0F, 1615.0F, 1520.0F, 1480.0F, 1462.0F, 1435.0F, 1398.0F,
  1346.0F, 1285.0F, 1215.0F, 1125.0F } ;
                      /* Referenced by: '<S1234>/MDAC_CCSDsrdTqKi_fac_IntTbl' */

CALDATA const volatile float32 MDAC_HDCDsrdTqKp_c[15] = { 2000.0F, 1000.0F,
  600.0F, 500.0F, 400.0F, 200.0F, 0.0F, 0.0F, 0.0F, 200.0F, 400.0F, 500.0F,
  600.0F, 1000.0F, 2000.0F } ;
                      /* Referenced by: '<S1234>/MDAC_CCSDsrdTqKp_fac_IntTbl' */

CALDATA const volatile float32 MDAC_HDCTgtAcceltn_mps2[16] = { -2.0F, -2.0F,
  -1.5F, -0.8F, -0.35F, -0.2F, -0.1F, -0.05F, 0.0F, 0.05F, 0.1F, 0.2F, 0.35F,
  0.5F, 0.8F, 1.1F } ;          /* Referenced by: '<S1232>/1-D Lookup Table3' */

CALDATA const volatile float32 MDAC_INVMaxDrgTqWhl_Nm[12] = { 0.0F, 0.0F,
  -500.0F, -1000.0F, -1500.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F } ;        /* Referenced by: '<S1134>/1-D Lookup Table1' */

CALDATA const volatile float32 MDAC_NonDrvnSpdFiltCoeff_rat[7] = { 0.98F, 0.97F,
  0.95F, 0.93F, 0.83F, 0.67F, 0.5F } ;
                 /* Referenced by: '<S1159>/Lookup_MVTM_VehSpdFiltCoeff_rat1' */

CALDATA const volatile float32 MDAG_BMSSOCLoRecThr1_pct[10] = { 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F } ;
                         /* Referenced by: '<S103>/BMS_BMSCTL_LMPRECSOC1_CAL' */

/* BMSSOC低故障恢复门槛_低温 */
CALDATA const volatile float32 MDAG_BMSSOCLoRecThr2_pct[10] = { 5.0F, 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F } ;
                         /* Referenced by: '<S103>/BMS_BMSCTL_LMPRECSOC2_CAL' */

/* BMSSOC低故障恢复门槛_高温 */
CALDATA const volatile float32 MDAG_BMSSOCLoThr1_pct[10] = { 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F } ;
                            /* Referenced by: '<S103>/BMS_BMSCTL_LMPSOC1_CAL' */

/* BMSSOC低故障触发门槛_低温 */
CALDATA const volatile float32 MDAG_BMSSOCLoThr2_pct[10] = { 3.0F, 3.0F, 3.0F,
  3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F } ;
                            /* Referenced by: '<S103>/BMS_BMSCTL_LMPSOC2_CAL' */

/* BMSSOC低故障触发门槛_高温 */
CALDATA const volatile sint16 MDAG_CellTempLoThr_C[10] = { 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0 } ;                 /* Referenced by: '<S100>/MDAG_CellTempLoThr_C' */

/* 区分电芯温度高低的分界值 */
CALDATA const volatile uint16 MDAG_CellUndrVoltThr1_mV[10] = { 2300U, 2300U,
  2300U, 2300U, 2300U, 2300U, 2300U, 2300U, 2300U, 2300U } ;
                          /* Referenced by: '<S100>/MDAG_CellUndrVoltThr1_mV' */

/* BMSCell欠压故障的电压门槛_低温 */
CALDATA const volatile uint16 MDAG_CellUndrVoltThr2_mV[10] = { 2700U, 2700U,
  2700U, 2700U, 2700U, 2700U, 2700U, 2700U, 2700U, 2700U } ;
                          /* Referenced by: '<S100>/MDAG_CellUndrVoltThr2_mV' */

/* BMSCell欠压故障的电压门槛_高温 */
CALDATA const volatile float32 MDSA_DeceltnIdxAvg_pct[10] = { 0.0F, 0.0F, 0.0F,
  0.0F, 5.0F, 10.0F, 12.0F, 16.0F, 20.0F, 20.0F } ;
                       /* Referenced by: '<S17>/MTQD_ZeroTqOfstTipInTMOly_Nm' */

CALDATA const volatile float32 MDSA_MildDrvMap_mps2[15] = { 1.5F, 1.4F, 1.3F,
  1.0F, 0.7F, 0.5F, 0.3F, 0.25F, 0.2F, 0.2F, 0.18F, 0.15F, 0.1F, 0.05F, 0.05F } ;
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl3' */

CALDATA const volatile float32 MDSA_SprtIdxHldINVTq_Nm[15] = { -999.0F, -999.0F,
  -999.0F, -999.0F, -999.0F, -999.0F, -999.0F, -999.0F, -999.0F, -999.0F,
  -999.0F, -999.0F, -999.0F, -999.0F, -999.0F } ;
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl4' */

CALDATA const volatile float32 MDSA_VehDrgTq_Nm[15] = { 43.0F, 48.0F, 55.0F,
  65.0F, 77.0F, 92.0F, 109.0F, 129.0F, 152.0F, 177.0F, 205.0F, 235.0F, 268.0F,
  304.0F, 342.0F } ;     /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl1' */

CALDATA const volatile float32 MDSA_WildDrvMap_mps2[15] = { 4.5F, 4.0F, 3.8F,
  3.6F, 3.5F, 3.2F, 3.0F, 2.6F, 2.2F, 1.8F, 1.5F, 1.0F, 0.5F, 0.3F, 0.3F } ;
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl2' */

CALDATA const volatile float32 MEMS_CellOverVoltBgn_mV[10] = { 3700.0F, 3700.0F,
  3700.0F, 3700.0F, 3700.0F, 3700.0F, 3700.0F, 3700.0F, 3700.0F, 3700.0F } ;/* Referenced by: '<S26>/PwrDrt2' */

/* 过压修正Begin值（优先使用过压闭环） */
CALDATA const volatile float32 MEMS_CellOverVoltRng_mV[10] = { 40.0F, 40.0F,
  40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F, 40.0F } ;/* Referenced by: '<S26>/PwrDrt4' */

/* 过压修正Range值（优先使用过压闭环） */
CALDATA const volatile float32 MEMS_CellOverVoltThr_mV[10] = { 3650.0F, 3650.0F,
  3650.0F, 3650.0F, 3650.0F, 3650.0F, 3650.0F, 3650.0F, 3650.0F, 3650.0F } ;/* Referenced by: '<S81>/PwrDrt' */

/* 过压闭环控制目标电压 */
CALDATA const volatile float32 MEMS_CellTempLoThr_C[10] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by: '<S31>/PwrDrt4' */

/* 电芯常温和低温区分值 */
CALDATA const volatile float32 MEMS_CellTempMinFac_rat[5] = { 1.0F, 1.0F, 0.0F,
  0.0F, 0.0F } ;                  /* Referenced by: '<S31>/MTQD_TMOverDrt_c5' */

/* 电芯温度切换过渡系数 */
CALDATA const volatile float32 MEMS_CellUndrVoltBgn1_mV[10] = { 2300.0F, 2300.0F,
  2300.0F, 2300.0F, 2300.0F, 2300.0F, 2300.0F, 2300.0F, 2300.0F, 2300.0F } ;/* Referenced by: '<S28>/PwrDrt' */

/* 低温放电欠压修正Begin值（优先使用电压闭环） */
CALDATA const volatile float32 MEMS_CellUndrVoltBgn2_mV[10] = { 2700.0F, 2700.0F,
  2700.0F, 2700.0F, 2700.0F, 2700.0F, 2700.0F, 2700.0F, 2700.0F, 2700.0F } ;/* Referenced by: '<S28>/PwrDrt1' */

/* 常温放电欠压修正Begin值(优先使用电压闭环) */
CALDATA const volatile float32 MEMS_CellUndrVoltRng1_mV[10] = { 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F } ;/* Referenced by: '<S28>/PwrDrt2' */

/* 低温放电欠压修正Rang值（优先使用电压闭环） */
CALDATA const volatile float32 MEMS_CellUndrVoltRng2_mV[10] = { 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F } ;/* Referenced by: '<S28>/PwrDrt3' */

/* 常温放电欠压修正Rang值(优先使用电压闭环) */
CALDATA const volatile float32 MEMS_CellUndrVoltThr1_mV[10] = { 2400.0F, 2400.0F,
  2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F, 2400.0F } ;/* Referenced by: '<S82>/PwrDrt' */

/* 低温电压闭环控制目标电压 */
CALDATA const volatile float32 MEMS_CellUndrVoltThr2_mV[10] = { 2800.0F, 2800.0F,
  2800.0F, 2800.0F, 2800.0F, 2800.0F, 2800.0F, 2800.0F, 2800.0F, 2800.0F } ;/* Referenced by: '<S82>/PwrDrt1' */

/* 常温电压闭环控制目标电压 */
CALDATA const volatile float32 MEMS_ChrgCurFbKi_c[15] = { 0.15F, 0.1F, 0.1F,
  0.1F, 0.05F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 2.0F, 3.0F } ;
                                  /* Referenced by: '<S81>/lu1d_BatLimHiSoC1' */

/* 过压闭环控制Ki */
CALDATA const volatile float32 MEMS_ChrgCurFbKp_c[11] = { 0.0F, 0.0F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.15F, 0.15F, 0.15F, 0.2F, 0.25F } ;
                                   /* Referenced by: '<S81>/lu1d_BatLimHiSoC' */

/* 过压闭环控制KP */
CALDATA const volatile float32 MEMS_ChrgPwrFbKi_c[15] = { 0.5F, 0.5F, 0.5F, 0.2F,
  0.2F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F } ;
                                  /* Referenced by: '<S46>/lu1d_BatLimHiSoC1' */

/* 充电功率闭环KI */
CALDATA const volatile float32 MEMS_ChrgPwrFbKp_c[11] = { 0.0F, 0.0F, 0.0F,
  0.25F, 0.5F, 0.75F, 0.8F, 1.0F, 2.0F, 2.0F, 3.0F } ;
                                   /* Referenced by: '<S46>/lu1d_BatLimHiSoC' */

/* 充电功率闭环KP */
CALDATA const volatile float32 MEMS_DchaCurFbKi_c[15] = { 3.0F, 2.0F, 1.5F, 1.5F,
  1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 0.05F, 0.1F, 0.1F, 0.1F, 0.15F } ;
                                  /* Referenced by: '<S82>/lu1d_BatLimHiSoC1' */

/* 欠压电压闭环KI */
CALDATA const volatile float32 MEMS_DchaCurFbKp_c[11] = { 0.25F, 0.2F, 0.15F,
  0.15F, 0.15F, 0.1F, 0.1F, 0.1F, 0.1F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S82>/lu1d_BatLimHiSoC' */

/* 欠压电压闭环KP */
CALDATA const volatile float32 MEMS_DchaPwrFbKi_c[15] = { 5.4F, 5.4F, 5.4F, 5.4F,
  5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 5.4F, 0.2F, 0.2F, 0.5F, 0.5F, 0.5F } ;
                                  /* Referenced by: '<S64>/lu1d_BatLimHiSoC1' */

/* 放电功率闭环KI */
CALDATA const volatile float32 MEMS_DchaPwrFbKp_c[11] = { 3.0F, 2.0F, 1.25F,
  1.0F, 1.0F, 1.0F, 0.75F, 0.25F, 0.0F, 0.0F, 0.0F } ;
                                   /* Referenced by: '<S64>/lu1d_BatLimHiSoC' */

/* 放电功率闭环KP */
CALDATA const volatile float32 MEMS_HVBatMaxChrgPwrSOC_kW[7] = { -999.0F,
  -999.0F, -999.0F, -999.0F, -999.0F, -999.0F, -999.0F } ;
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c8' */

/* 充电SOC功率限制（目前暂未使用） */
CALDATA const volatile float32 MEMS_HVBatMaxDchaPwrSOC_kW[7] = { 999.0F, 999.0F,
  999.0F, 999.0F, 999.0F, 999.0F, 999.0F } ;
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c6' */

/* 放电SOC限制功率(目前暂未使用) */
CALDATA const volatile float32 MEMS_MaxConChrgCurOfst_A[8] = { -15.0F, -15.0F,
  -15.0F, -10.0F, -7.0F, -5.0F, -3.0F, 0.0F } ;
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c1' */

/* Con持续回收电流偏移 */
CALDATA const volatile float32 MEMS_MaxConDchaCurOfst_A[8] = { 0.0F, 3.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F } ;/* Referenced by: '<S28>/MTQD_TMOverDrt_c1' */

/* 放电-持续电流偏移 */
CALDATA const volatile float32 MEMS_MaxInsChrgCurOfst_A[8] = { -15.0F, -15.0F,
  -15.0F, -10.0F, -7.0F, -5.0F, -3.0F, 0.0F } ;
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c7' */

/* Ins瞬时回收电流偏移 */
CALDATA const volatile float32 MEMS_MaxInsChrgCurrFac_c[100] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                  /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurrFac_c' */

/* VCU修正不同Pack类型回收系数 */
CALDATA const volatile float32 MEMS_MaxInsChrgCurr_A[170] = { -200.0F, -230.0F,
  -250.0F, -300.0F, -400.0F, -500.0F, -500.0F, -500.0F, -500.0F, -500.0F,
  -500.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -200.0F, -230.0F,
  -250.0F, -300.0F, -400.0F, -500.0F, -500.0F, -500.0F, -500.0F, -500.0F,
  -500.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -200.0F, -230.0F,
  -250.0F, -300.0F, -400.0F, -500.0F, -500.0F, -500.0F, -500.0F, -500.0F,
  -500.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -200.0F, -230.0F,
  -250.0F, -300.0F, -400.0F, -500.0F, -500.0F, -500.0F, -500.0F, -500.0F,
  -500.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -200.0F, -230.0F,
  -250.0F, -300.0F, -400.0F, -500.0F, -500.0F, -500.0F, -500.0F, -500.0F,
  -500.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -200.0F, -230.0F,
  -250.0F, -300.0F, -400.0F, -500.0F, -500.0F, -500.0F, -500.0F, -500.0F,
  -500.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -100.0F, -150.0F,
  -180.0F, -220.0F, -250.0F, -300.0F, -300.0F, -300.0F, -300.0F, -300.0F,
  -300.0F, -220.0F, -220.0F, -120.0F, -120.0F, -80.0F, 0.0F, -50.0F, -80.0F,
  -120.0F, -160.0F, -180.0F, -200.0F, -200.0F, -200.0F, -200.0F, -200.0F,
  -200.0F, -200.0F, -200.0F, -120.0F, -120.0F, -80.0F, 0.0F, -20.0F, -30.0F,
  -35.0F, -40.0F, -50.0F, -50.0F, -50.0F, -50.0F, -50.0F, -50.0F, -50.0F, -50.0F,
  -50.0F, -50.0F, -50.0F, -50.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                     /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

/* VCU限制Ins瞬时回收电流 */
CALDATA const volatile float32 MEMS_MaxInsDchaCurOfst_A[8] = { 0.0F, 3.0F, 5.0F,
  8.0F, 10.0F, 10.0F, 10.0F, 10.0F } ;
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c2' */

/* 放电-瞬时电流偏移 */
CALDATA const volatile float32 MEMS_MaxInsDchaCurrFac_c[100] = { 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                  /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurrFac_c' */

/* VCU修正不同类型Pack放电系数 */
CALDATA const volatile float32 MEMS_MaxInsDchaCurr_A[170] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 12.0F, 20.0F, 46.0F, 69.0F, 96.0F, 98.0F, 99.0F, 109.0F, 111.0F,
  115.0F, 126.0F, 149.0F, 183.0F, 161.0F, 106.0F, 58.0F, 0.0F, 18.0F, 45.0F,
  72.0F, 106.0F, 147.0F, 156.0F, 165.0F, 189.0F, 200.0F, 224.0F, 255.0F, 283.0F,
  330.0F, 266.0F, 248.0F, 92.0F, 0.0F, 26.0F, 56.0F, 98.0F, 142.0F, 195.0F,
  202.0F, 208.0F, 233.0F, 240.0F, 300.0F, 385.0F, 410.0F, 449.0F, 350.0F, 310.0F,
  102.0F, 0.0F, 32.0F, 69.0F, 101.0F, 147.0F, 218.0F, 229.0F, 240.0F, 260.0F,
  272.0F, 355.0F, 423.0F, 439.0F, 483.0F, 355.0F, 350.0F, 105.0F, 0.0F, 38.0F,
  83.0F, 121.0F, 161.0F, 240.0F, 256.0F, 272.0F, 288.0F, 303.0F, 409.0F, 462.0F,
  477.0F, 517.0F, 360.0F, 350.0F, 108.0F, 0.0F, 41.0F, 97.0F, 142.0F, 188.0F,
  276.0F, 292.0F, 309.0F, 325.0F, 341.0F, 443.0F, 494.0F, 517.0F, 550.0F, 360.0F,
  350.0F, 108.0F, 0.0F, 44.0F, 110.0F, 163.0F, 215.0F, 312.0F, 328.0F, 345.0F,
  362.0F, 379.0F, 476.0F, 525.0F, 556.0F, 584.0F, 360.0F, 350.0F, 108.0F, 0.0F,
  49.0F, 138.0F, 206.0F, 269.0F, 369.0F, 369.0F, 399.0F, 431.0F, 455.0F, 525.0F,
  607.0F, 636.0F, 651.0F, 412.0F, 350.0F, 123.0F, 0.0F, 90.0F, 215.0F, 315.0F,
  398.0F, 523.0F, 638.0F, 600.0F, 638.0F, 637.0F, 638.0F, 675.0F, 675.0F, 675.0F,
  514.0F, 500.0F, 154.0F } ;
                     /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

/* VCU限制Ins瞬时放电电流 */
CALDATA const volatile float32 MHVM_BMSCelMaxVol_mV[10] = { 3660.0F, 3660.0F,
  3660.0F, 3660.0F, 3660.0F, 3660.0F, 3660.0F, 3660.0F, 3660.0F, 3660.0F } ;
                              /* Referenced by: '<S750>/MHVM_BMSCelMaxVol_mV' */

/* 交直流充电截止单体电压 */
CALDATA const volatile float32 MHVM_BMSTotMaxVol_V[10] = { 453.0F, 453.0F,
  453.0F, 453.0F, 453.0F, 453.0F, 453.0F, 453.0F, 453.0F, 453.0F } ;
                               /* Referenced by: '<S750>/MHVM_BMSTotMaxVol_V' */

/* 交直流充电截止总电压 */
CALDATA const volatile float32 MHVM_MaxChrgCurntDC_A[10] = { 300.0F, 300.0F,
  300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F, 300.0F } ;
                             /* Referenced by: '<S750>/MHVM_MaxChrgCurntDC_A' */

/* DC直流充电最大电流 */
CALDATA const volatile float32 MHVM_MaxChrgVoltDC_V[10] = { 453.0F, 453.0F,
  453.0F, 453.0F, 453.0F, 453.0F, 453.0F, 453.0F, 453.0F, 453.0F } ;
                              /* Referenced by: '<S750>/MHVM_MaxChrgVoltDC_V' */

/* DC直流充电最大电压 */
CALDATA const volatile float32 MIBS_BMSBatSOCExtrmLo_pct[10] = { 5.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F, 5.0F } ;
                        /* Referenced by: '<S1002>/MIBS_BMSBatSOCExtrmLo_pct' */

/* 动力电池SOC极低，禁止或退出IBS补电_versteckt */
CALDATA const volatile float32 MIBS_IBSEnMinSOC_pct[10] = { 10.0F, 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F } ;
                             /* Referenced by: '<S1002>/MIBS_IBSEnMinSOC_pct' */

/* IBS补电动力电池SOC阈值_versteckt */
CALDATA const volatile uint16 MIBS_NextRtcWupThr_min[60] = { 120U, 120U, 120U,
  90U, 90U, 60U, 120U, 120U, 120U, 90U, 90U, 60U, 120U, 120U, 120U, 90U, 90U,
  60U, 120U, 120U, 120U, 90U, 90U, 120U, 120U, 120U, 120U, 180U, 180U, 120U,
  240U, 240U, 240U, 180U, 180U, 240U, 240U, 240U, 240U, 300U, 300U, 240U, 240U,
  330U, 330U, 300U, 300U, 240U, 360U, 330U, 330U, 300U, 300U, 240U, 360U, 330U,
  330U, 300U, 300U, 240U } ;
                           /* Referenced by: '<S1003>/MIBS_NextRtcWupThr_min' */

/* IBS下一次RTC唤醒时间阈值_versteckt */
CALDATA const volatile uint16 MIBS_WupChgTmThr2_min[60] = { 120U, 120U, 120U,
  180U, 180U, 180U, 120U, 120U, 120U, 180U, 180U, 180U, 120U, 120U, 120U, 180U,
  180U, 180U, 120U, 120U, 120U, 180U, 180U, 120U, 120U, 120U, 120U, 90U, 90U,
  120U, 120U, 90U, 90U, 90U, 90U, 30U, 90U, 90U, 90U, 30U, 30U, 30U, 90U, 30U,
  30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U, 30U
} ;                          /* Referenced by: '<S1003>/MIBS_WupChgTmThr_min' */

/* IBS补电时间阈值2_versteckt */
CALDATA const volatile float32 MIPC_AccPedBckLsh_pct[12] = { 2.0F, 2.0F, 2.0F,
  2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 3.0F, 3.0F } ;
                                      /* Referenced by: '<S876>/Lookup Table' */

CALDATA const volatile float32 MIPC_TireRadius_m[6] = { 0.3412F, 0.3412F,
  0.3412F, 0.3412F, 0.3412F, 0.3412F } ;
                                     /* Referenced by: '<S874>/TireSizeTable' */

CALDATA const volatile float32 MRME_CHTCStdRmnMil_km[120] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 8.0F, 8.0F, 8.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 28.0F, 28.0F, 28.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 56.0F, 56.0F, 56.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  84.0F, 84.0F, 83.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 112.0F, 112.0F,
  111.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 140.0F, 140.0F, 139.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 168.0F, 168.0F, 167.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 196.0F, 196.0F, 195.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 224.0F, 224.0F, 222.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  252.0F, 252.0F, 250.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 280.0F,
  280.0F, 278.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                             /* Referenced by: '<S951>/MRME_CHTCStdRmnMil_km' */

/* 标准续航CHTC查表值 */
CALDATA const volatile float32 MRME_DchaRmnMilEstChgStp_c[60] = { 0.2F, 0.2F,
  0.2F, 0.2F, 0.2F, 0.2F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.3F, 0.45F, 0.45F,
  0.45F, 0.45F, 0.45F, 0.45F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.5F, 0.6F, 0.6F,
  0.6F, 0.6F, 0.6F, 0.6F, 0.7F, 0.7F, 0.7F, 0.7F, 0.7F, 0.7F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 1.7F, 1.7F, 1.7F, 1.7F,
  1.7F, 1.7F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F, 1.5F } ;
                            /* Referenced by: '<S979>/MRME_DynEstRmnChgStp_c' */

/* 动态续航变化速率修正系数（默认以1km为基准） */
CALDATA const volatile float32 MRME_WLTPStdDwLimFac_c[6] = { 0.4F, 0.5F, 0.6F,
  0.7F, 0.8F, 0.9F } ;         /* Referenced by: '<S960>/MRME_WLTPDwLimFac_c' */

/* 基于标准续航WLTP最小下限系数(使用电芯温度修正) */
CALDATA const volatile float32 MRME_WLTPStdPwrCnsm_kWh100km[10] = { 28.0F, 30.0F,
  30.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;/* Referenced by: '<S955>/  ' */

/* 标准工况100km电耗（按照100km折算） */
CALDATA const volatile float32 MRME_WLTPStdRmnMil_km[120] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 9.0F, 9.0F, 9.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 29.0F, 29.0F, 29.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 57.0F, 57.0F, 57.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  86.0F, 86.0F, 86.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 114.0F, 114.0F,
  114.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 143.0F, 143.0F, 143.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 171.0F, 171.0F, 171.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 200.0F, 200.0F, 200.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 228.0F, 228.0F, 228.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  257.0F, 257.0F, 257.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 285.0F,
  285.0F, 285.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                             /* Referenced by: '<S960>/MRME_WLTPStdRmnMil_km' */

/* 标准续航WLTP查表值 */
CALDATA const volatile float32 MRME_WLTPStdSOCCnsm_pct100km[10] = { 50.0F, 37.0F,
  35.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                     /* Referenced by: '<S960>/MRME_WLTPStdSOCCnsm_pct100km ' */

/* 标准工况SOC消耗（按100km折算） */
CALDATA const volatile float32 MTQC_RegenMaxTqDecRate_Nmps[20] = { -10000.0F,
  -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F,
  -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F,
  -10000.0F, -10000.0F, -10000.0F, -10000.0F, -10000.0F } ;
                   /* Referenced by: '<S1261>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

CALDATA const volatile float32 MTQC_RegenMaxTqIncRate_Nmps[8] = { 12000.0F,
  12000.0F, 10000.0F, 10000.0F, 8000.0F, 5000.0F, 1000.0F, 500.0F } ;
                             /* Referenced by: '<S1261>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlEndPstn_mps2[14] = {
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                  /* Referenced by: '<S1296>/MTQD_CstTqReqWhlS_Nm2' */

CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlS_mps2[14] = { 0.0F,
  0.0F, 0.0F, 0.0F, -0.2F, -0.5F, -2.0F, -2.0F, -2.0F, -2.0F, -2.0F, -2.0F,
  -2.0F, -2.0F } ;           /* Referenced by: '<S1296>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlW_mps2[14] = { 0.0F,
  0.0F, 0.0F, 0.0F, -0.1F, -0.3F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F } ;          /* Referenced by: '<S1296>/MTQD_CstTqReqWhlS_Nm1' */

CALDATA const volatile float32 MTQD_AdaptCstDsrdTqKi_c[225] = { 1125.0F, 1285.0F,
  1285.0F, 1384.0F, 1440.0F, 1384.0F, 1333.0F, 750.0F, 800.0F, 857.0F, 1714.0F,
  2000.0F, 2117.0F, 2250.0F, 2250.0F, 1090.0F, 1241.0F, 1241.0F, 1333.0F,
  1384.0F, 1333.0F, 1285.0F, 750.0F, 800.0F, 857.0F, 1636.0F, 1894.0F, 2000.0F,
  2117.0F, 2117.0F, 972.0F, 1090.0F, 1161.0F, 1241.0F, 1200.0F, 1161.0F, 1125.0F,
  750.0F, 800.0F, 857.0F, 1384.0F, 1565.0F, 1636.0F, 1714.0F, 1714.0F, 878.0F,
  972.0F, 1028.0F, 1090.0F, 1058.0F, 1028.0F, 1000.0F, 750.0F, 800.0F, 857.0F,
  1200.0F, 1333.0F, 1384.0F, 1440.0F, 1440.0F, 818.0F, 900.0F, 947.0F, 1000.0F,
  972.0F, 947.0F, 923.0F, 750.0F, 800.0F, 857.0F, 1090.0F, 1200.0F, 1241.0F,
  1285.0F, 1285.0F, 765.0F, 837.0F, 878.0F, 923.0F, 900.0F, 878.0F, 857.0F,
  750.0F, 800.0F, 857.0F, 1000.0F, 1090.0F, 1125.0F, 1161.0F, 1161.0F, 720.0F,
  782.0F, 818.0F, 857.0F, 837.0F, 818.0F, 800.0F, 750.0F, 800.0F, 857.0F, 923.0F,
  1000.0F, 1028.0F, 1058.0F, 1058.0F, 889.0F, 920.0F, 923.0F, 928.0F, 880.0F,
  837.0F, 800.0F, 750.0F, 800.0F, 837.0F, 880.0F, 928.0F, 923.0F, 920.0F, 889.0F,
  1058.0F, 1058.0F, 1028.0F, 1000.0F, 923.0F, 857.0F, 800.0F, 750.0F, 800.0F,
  818.0F, 837.0F, 857.0F, 818.0F, 782.0F, 720.0F, 1161.0F, 1161.0F, 1125.0F,
  1090.0F, 1000.0F, 857.0F, 800.0F, 750.0F, 857.0F, 878.0F, 900.0F, 923.0F,
  878.0F, 837.0F, 765.0F, 1285.0F, 1285.0F, 1241.0F, 1200.0F, 1090.0F, 857.0F,
  800.0F, 750.0F, 850.0F, 850.0F, 850.0F, 850.0F, 850.0F, 850.0F, 850.0F,
  1440.0F, 1440.0F, 1384.0F, 1333.0F, 1200.0F, 857.0F, 800.0F, 750.0F, 800.0F,
  800.0F, 750.0F, 750.0F, 750.0F, 750.0F, 700.0F, 1714.0F, 1714.0F, 1636.0F,
  1565.0F, 1384.0F, 857.0F, 800.0F, 750.0F, 750.0F, 750.0F, 700.0F, 700.0F,
  700.0F, 700.0F, 650.0F, 2117.0F, 2117.0F, 1800.0F, 1714.0F, 1636.0F, 857.0F,
  800.0F, 750.0F, 700.0F, 700.0F, 650.0F, 650.0F, 650.0F, 650.0F, 600.0F,
  2250.0F, 2250.0F, 1894.0F, 1800.0F, 1714.0F, 857.0F, 800.0F, 750.0F, 600.0F,
  600.0F, 550.0F, 550.0F, 550.0F, 550.0F, 500.0F } ;
                      /* Referenced by: '<S1296>/MDAC_CCSDsrdTqKi_fac_IntTbl' */

CALDATA const volatile float32 MTQD_AdaptCstDsrdTqKp_c[15] = { 2000.0F, 1000.0F,
  600.0F, 500.0F, 400.0F, 200.0F, 0.0F, 0.0F, 0.0F, 200.0F, 400.0F, 500.0F,
  600.0F, 1000.0F, 2000.0F } ;
                      /* Referenced by: '<S1296>/MDAC_CCSDsrdTqKp_fac_IntTbl' */

CALDATA const volatile float32 MTQD_AdaptCstMaxTqWhl_Nm[14] = { 0.0F, -20.0F,
  -50.0F, -150.0F, -250.0F, -350.0F, -1050.0F, -1600.0F, -1600.0F, -1600.0F,
  -1600.0F, -1600.0F, -1600.0F, -1600.0F } ;
                            /* Referenced by: '<S1292>/MTQD_CstTqReqWhlS_Nm4' */

CALDATA const volatile float32 MTQD_AdaptCstMinTqWhl_Nm[14] = { 0.0F, -20.0F,
  -25.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F,
  -30.0F, -30.0F } ;        /* Referenced by: '<S1292>/MTQD_CstTqReqWhlS_Nm3' */

CALDATA const volatile float32 MTQD_CrpTqReqWhlD_Nm[10] = { 720.0F, 600.0F,
  480.0F, 400.0F, 350.0F, 150.0F, 20.0F, 10.0F, 5.0F, 0.0F } ;
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlD_Nm' */

CALDATA const volatile float32 MTQD_CrpTqReqWhlR_Nm[10] = { 0.0F, 0.0F, 5.0F,
  10.0F, 20.0F, 150.0F, 350.0F, 430.0F, 520.0F, 600.0F } ;
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlR_Nm' */

CALDATA const volatile float32 MTQD_CstRegenEndPstnA_pct[15] = { 0.0F, 1.0F,
  3.0F, 4.0F, 5.0F, 7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 12.0F, 12.0F, 12.0F, 12.0F,
  12.0F } ;                 /* Referenced by: '<S1291>/MTQD_CstTqReqWhlA_Nm1' */

CALDATA const volatile float32 MTQD_CstRegenEndPstnS_pct[15] = { 0.0F, 1.0F,
  3.0F, 5.0F, 7.0F, 9.0F, 11.0F, 12.0F, 13.0F, 14.0F, 15.0F, 15.0F, 15.0F, 15.0F,
  15.0F } ;                 /* Referenced by: '<S1291>/MTQD_CstTqReqWhlS_Nm2' */

CALDATA const volatile float32 MTQD_CstRegenEndPstnV_pct[14] = { 15.0F, 15.0F,
  15.0F, 18.0F, 20.0F, 20.0F, 20.0F, 20.0F, 20.0F, 19.0F, 18.0F, 17.0F, 16.0F,
  15.0F } ;                     /* Referenced by: '<S1291>/1-D Lookup Table1' */

CALDATA const volatile float32 MTQD_CstRegenEndPstnW_pct[15] = { 0.0F, 1.0F,
  2.0F, 3.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 9.0F, 10.0F, 10.0F, 10.0F, 10.0F,
  10.0F } ;                 /* Referenced by: '<S1291>/MTQD_CstTqReqWhlS_Nm3' */

CALDATA const volatile float32 MTQD_CstRegenTqReqWhlInc_Nmps[8] = { 200.0F,
  200.0F, 800.0F, 1500.0F, 3000.0F, 5000.0F, 6000.0F, 8000.0F } ;
                            /* Referenced by: '<S1293>/MTQD_CstTqReqWhlS_Nm3' */

CALDATA const volatile float32 MTQD_CstRegenTqReqWhlOff_Nm[70] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, -20.0F, -20.0F, -20.0F, -20.0F, -20.0F, -20.0F, -20.0F,
  -20.0F, -20.0F, -20.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F, -30.0F,
  -40.0F, -40.0F, -40.0F, -30.0F, -40.0F, -50.0F, -50.0F, -50.0F, -30.0F, -75.0F,
  -120.0F, -120.0F, -120.0F, -30.0F, -127.5F, -225.0F, -225.0F, -225.0F, -30.0F,
  -150.0F, -270.0F, -270.0F, -270.0F, -30.0F, -165.0F, -300.0F, -300.0F, -300.0F,
  -30.0F, -132.5F, -235.0F, -235.0F, -235.0F, -30.0F, -130.0F, -230.0F, -230.0F,
  -230.0F, -30.0F, -115.0F, -200.0F, -200.0F, -200.0F, -30.0F, -87.5F, -145.0F,
  -145.0F, -145.0F } ;    /* Referenced by: '<S1290>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 MTQD_CstRegenTqReqWhlR_Nm[12] = { -100.0F,
  -152.0F, -152.0F, -130.0F, -105.0F, -90.0F, -65.0F, -30.0F, -20.0F, -20.0F,
  0.0F, 0.0F } ;                /* Referenced by: '<S1290>/1-D Lookup Table2' */

CALDATA const volatile float32 MTQD_CstRegenTqReqWhlS_Nm[14] = { 0.0F, -20.0F,
  -20.0F, -30.0F, -50.0F, -135.0F, -377.0F, -586.0F, -616.0F, -624.0F, -585.0F,
  -536.0F, -425.0F, -261.0F } ;
                             /* Referenced by: '<S1290>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MTQD_CstRegenTqReqWhlV_Nm[14] = { 0.0F, -375.0F,
  -750.0F, -1080.0F, -1125.0F, -1125.0F, -1125.0F, -1125.0F, -1125.0F, -1016.0F,
  -907.0F, -700.0F, -600.0F, -500.0F } ;
                                /* Referenced by: '<S1290>/1-D Lookup Table1' */

CALDATA const volatile float32 MTQD_CstRegenTqReqWhlW_Nm[14] = { 0.0F, -20.0F,
  -20.0F, -30.0F, -40.0F, -50.0F, -120.0F, -225.0F, -270.0F, -300.0F, -235.0F,
  -230.0F, -200.0F, -145.0F } ;
                            /* Referenced by: '<S1290>/MTQD_CstTqReqWhlS_Nm1' */

CALDATA const volatile float32 MTQD_FwdFullPedDrvTqWhlSprt_Nm[19] = { 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 3907.2F,
  3528.69F, 3174.6F, 2808.3F, 2380.95F, 2039.07F, 1807.08F, 1562.88F, 1404.15F,
  1245.42F, 1147.74F } ;        /* Referenced by: '<S1283>/MTQD_PTBaseTq_Nm1' */

CALDATA const volatile float32 MTQD_FwdFullPedDrvTqWhl_Nm[19] = { 4000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F, 3907.2F,
  3528.69F, 3174.6F, 2808.3F, 2380.95F, 2039.07F, 1807.08F, 1562.88F, 1404.15F,
  1245.42F, 1147.74F } ;         /* Referenced by: '<S1283>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 MTQD_FwdPedMapEco_pct[378] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 3.0F, 4.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 2.0F, 2.0F, 6.0F, 9.0F, 2.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 10.0F,
  14.0F, 5.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 3.0F, 3.0F, 4.0F, 4.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 15.0F, 20.0F, 10.0F, 5.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  4.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 18.0F, 26.0F,
  15.0F, 9.0F, 6.0F, 4.0F, 4.0F, 5.0F, 6.0F, 6.0F, 7.0F, 8.0F, 10.0F, 11.0F,
  11.0F, 11.0F, 11.0F, 11.0F, 22.0F, 30.0F, 21.0F, 14.0F, 10.0F, 8.0F, 7.0F,
  7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 13.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F,
  26.0F, 36.0F, 27.0F, 19.0F, 15.0F, 12.0F, 10.0F, 10.0F, 10.0F, 11.0F, 12.0F,
  14.0F, 16.0F, 18.0F, 18.0F, 18.0F, 18.0F, 18.0F, 32.0F, 42.0F, 32.0F, 24.0F,
  20.0F, 17.0F, 15.0F, 14.0F, 14.0F, 15.0F, 16.0F, 17.0F, 19.0F, 22.0F, 22.0F,
  22.0F, 22.0F, 22.0F, 38.0F, 47.0F, 37.0F, 29.0F, 26.0F, 22.0F, 20.0F, 19.0F,
  19.0F, 19.0F, 20.0F, 21.0F, 23.0F, 26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 44.0F,
  52.0F, 43.0F, 35.0F, 31.0F, 27.0F, 25.0F, 24.0F, 24.0F, 24.0F, 25.0F, 26.0F,
  28.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 50.0F, 57.0F, 48.0F, 40.0F, 36.0F,
  32.0F, 30.0F, 29.0F, 29.0F, 30.0F, 30.0F, 32.0F, 34.0F, 36.0F, 36.0F, 36.0F,
  36.0F, 36.0F, 55.0F, 62.0F, 53.0F, 46.0F, 42.0F, 38.0F, 36.0F, 35.0F, 35.0F,
  36.0F, 36.0F, 38.0F, 40.0F, 42.0F, 42.0F, 42.0F, 42.0F, 42.0F, 61.0F, 67.0F,
  59.0F, 52.0F, 48.0F, 44.0F, 42.0F, 42.0F, 42.0F, 42.0F, 42.0F, 44.0F, 46.0F,
  49.0F, 49.0F, 49.0F, 49.0F, 49.0F, 67.0F, 72.0F, 65.0F, 58.0F, 55.0F, 51.0F,
  49.0F, 49.0F, 48.0F, 49.0F, 49.0F, 50.0F, 53.0F, 55.0F, 55.0F, 55.0F, 55.0F,
  55.0F, 73.0F, 77.0F, 70.0F, 64.0F, 62.0F, 58.0F, 56.0F, 56.0F, 56.0F, 56.0F,
  56.0F, 58.0F, 60.0F, 62.0F, 62.0F, 62.0F, 62.0F, 62.0F, 79.0F, 82.0F, 76.0F,
  71.0F, 69.0F, 66.0F, 64.0F, 64.0F, 64.0F, 64.0F, 64.0F, 65.0F, 67.0F, 69.0F,
  69.0F, 69.0F, 69.0F, 69.0F, 83.0F, 86.0F, 82.0F, 78.0F, 76.0F, 74.0F, 72.0F,
  72.0F, 72.0F, 72.0F, 72.0F, 73.0F, 75.0F, 76.0F, 76.0F, 76.0F, 76.0F, 76.0F,
  89.0F, 91.0F, 88.0F, 85.0F, 84.0F, 82.0F, 81.0F, 81.0F, 81.0F, 81.0F, 81.0F,
  82.0F, 83.0F, 84.0F, 84.0F, 84.0F, 84.0F, 84.0F, 95.0F, 96.0F, 94.0F, 92.0F,
  92.0F, 91.0F, 90.0F, 90.0F, 90.0F, 90.0F, 90.0F, 91.0F, 91.0F, 92.0F, 92.0F,
  92.0F, 92.0F, 92.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F } ;             /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct1' */

CALDATA const volatile float32 MTQD_FwdPedMapNoCrpEco_pct[42] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                      /* Referenced by: '<S1283>/2-D Lookup Table1' */

CALDATA const volatile float32 MTQD_FwdPedMapNoCrpNorm_pct[42] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                      /* Referenced by: '<S1283>/2-D Lookup Table3' */

CALDATA const volatile float32 MTQD_FwdPedMapNoCrpSnow_pct[42] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                       /* Referenced by: '<S1283>/2-D Lookup Table' */

CALDATA const volatile float32 MTQD_FwdPedMapNoCrpSpt_pct[42] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F } ;                      /* Referenced by: '<S1283>/2-D Lookup Table2' */

CALDATA const volatile float32 MTQD_FwdPedMapNorm_pct[378] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 4.0F, 4.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 1.0F, 1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 8.0F, 11.0F, 3.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 3.0F, 3.0F, 3.0F, 14.0F,
  19.0F, 12.0F, 7.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.3F, 3.5F, 3.5F, 3.5F, 3.6F,
  3.65F, 3.72F, 3.78F, 3.85F, 3.85F, 23.0F, 28.0F, 21.0F, 14.0F, 10.0F, 6.0F,
  4.0F, 5.0F, 5.0F, 6.0F, 6.0F, 6.0F, 6.0F, 7.0F, 7.0F, 8.0F, 8.0F, 8.0F, 28.0F,
  37.0F, 29.0F, 22.0F, 18.0F, 14.0F, 10.0F, 8.0F, 8.0F, 8.0F, 9.0F, 10.0F, 11.0F,
  12.0F, 13.0F, 14.0F, 14.0F, 14.0F, 33.5F, 43.0F, 34.0F, 27.0F, 24.0F, 20.0F,
  16.0F, 13.0F, 13.0F, 13.0F, 12.0F, 14.0F, 15.0F, 16.0F, 18.0F, 19.0F, 19.0F,
  19.0F, 39.0F, 48.0F, 38.0F, 32.0F, 29.0F, 25.0F, 23.0F, 21.0F, 20.0F, 18.0F,
  17.0F, 18.0F, 19.0F, 21.0F, 23.0F, 25.0F, 25.0F, 25.0F, 46.0F, 54.0F, 44.0F,
  36.0F, 33.0F, 30.0F, 27.0F, 27.0F, 26.0F, 26.0F, 25.0F, 25.0F, 25.0F, 26.0F,
  28.0F, 31.0F, 31.0F, 31.0F, 52.0F, 59.0F, 49.0F, 41.0F, 39.0F, 36.0F, 34.0F,
  34.0F, 34.0F, 34.0F, 34.0F, 34.0F, 35.0F, 35.0F, 36.0F, 37.0F, 37.0F, 37.0F,
  58.0F, 64.0F, 55.0F, 47.0F, 45.0F, 42.0F, 40.0F, 41.0F, 42.0F, 42.0F, 43.0F,
  44.0F, 45.0F, 46.0F, 46.0F, 48.0F, 48.0F, 48.0F, 64.0F, 69.0F, 60.0F, 53.0F,
  50.0F, 48.0F, 46.0F, 47.0F, 48.0F, 49.0F, 51.0F, 53.0F, 55.0F, 56.0F, 57.0F,
  58.0F, 60.0F, 60.0F, 70.0F, 74.0F, 65.0F, 58.0F, 56.0F, 54.0F, 52.0F, 53.0F,
  54.0F, 55.0F, 57.0F, 59.0F, 62.0F, 64.0F, 66.0F, 66.0F, 68.0F, 68.0F, 74.0F,
  78.0F, 70.0F, 64.0F, 62.0F, 59.0F, 58.0F, 59.0F, 60.0F, 62.0F, 63.0F, 66.0F,
  69.0F, 70.0F, 72.5F, 73.0F, 74.0F, 74.0F, 80.0F, 83.0F, 75.0F, 69.0F, 67.0F,
  65.0F, 64.0F, 65.0F, 66.0F, 68.0F, 69.0F, 72.0F, 74.0F, 76.0F, 78.0F, 78.0F,
  78.0F, 78.0F, 85.0F, 87.0F, 80.0F, 74.0F, 73.0F, 71.0F, 70.0F, 71.0F, 72.0F,
  73.0F, 75.0F, 77.0F, 80.0F, 81.0F, 84.0F, 85.0F, 85.0F, 85.0F, 88.0F, 90.0F,
  85.0F, 80.0F, 79.0F, 77.0F, 76.0F, 77.0F, 78.0F, 79.0F, 81.0F, 83.0F, 85.0F,
  88.0F, 89.0F, 91.0F, 91.0F, 91.0F, 92.0F, 93.0F, 89.0F, 85.0F, 84.0F, 83.0F,
  82.0F, 83.0F, 84.0F, 85.0F, 86.0F, 88.0F, 90.0F, 92.0F, 94.0F, 94.0F, 94.0F,
  94.0F, 95.0F, 96.0F, 93.0F, 90.0F, 89.0F, 88.0F, 88.0F, 89.0F, 89.0F, 90.0F,
  91.0F, 92.0F, 94.0F, 96.0F, 97.0F, 97.0F, 97.0F, 97.0F, 97.0F, 98.0F, 97.0F,
  95.0F, 95.0F, 94.0F, 94.0F, 94.0F, 95.0F, 95.0F, 96.0F, 96.0F, 97.0F, 98.0F,
  99.0F, 99.0F, 99.0F, 99.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F } ;     /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct3' */

CALDATA const volatile float32 MTQD_FwdPedMapSnow_pct[378] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 3.0F, 4.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 2.0F, 2.0F, 6.0F, 9.0F, 2.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 2.0F, 2.0F, 3.0F, 3.0F, 3.0F, 3.0F, 3.0F, 10.0F,
  14.0F, 5.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 3.0F, 3.0F, 4.0F, 4.0F, 5.0F,
  5.0F, 5.0F, 5.0F, 5.0F, 15.0F, 20.0F, 10.0F, 5.0F, 3.0F, 3.0F, 3.0F, 3.0F,
  4.0F, 4.0F, 5.0F, 6.0F, 7.0F, 8.0F, 8.0F, 8.0F, 8.0F, 8.0F, 18.0F, 26.0F,
  15.0F, 9.0F, 6.0F, 4.0F, 4.0F, 5.0F, 6.0F, 6.0F, 7.0F, 8.0F, 10.0F, 11.0F,
  11.0F, 11.0F, 11.0F, 11.0F, 22.0F, 30.0F, 21.0F, 14.0F, 10.0F, 8.0F, 7.0F,
  7.0F, 8.0F, 9.0F, 10.0F, 11.0F, 13.0F, 14.0F, 14.0F, 14.0F, 14.0F, 14.0F,
  26.0F, 36.0F, 27.0F, 19.0F, 15.0F, 12.0F, 10.0F, 10.0F, 10.0F, 11.0F, 12.0F,
  14.0F, 16.0F, 18.0F, 18.0F, 18.0F, 18.0F, 18.0F, 32.0F, 42.0F, 32.0F, 24.0F,
  20.0F, 17.0F, 15.0F, 14.0F, 14.0F, 15.0F, 16.0F, 17.0F, 19.0F, 22.0F, 22.0F,
  22.0F, 22.0F, 22.0F, 38.0F, 47.0F, 37.0F, 29.0F, 26.0F, 22.0F, 20.0F, 19.0F,
  19.0F, 19.0F, 20.0F, 21.0F, 23.0F, 26.0F, 26.0F, 26.0F, 26.0F, 26.0F, 44.0F,
  52.0F, 43.0F, 35.0F, 31.0F, 27.0F, 25.0F, 24.0F, 24.0F, 24.0F, 25.0F, 26.0F,
  28.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 50.0F, 57.0F, 48.0F, 40.0F, 36.0F,
  32.0F, 30.0F, 29.0F, 29.0F, 30.0F, 30.0F, 32.0F, 34.0F, 36.0F, 36.0F, 36.0F,
  36.0F, 36.0F, 55.0F, 62.0F, 53.0F, 46.0F, 42.0F, 38.0F, 36.0F, 35.0F, 35.0F,
  36.0F, 36.0F, 38.0F, 40.0F, 42.0F, 42.0F, 42.0F, 42.0F, 42.0F, 61.0F, 67.0F,
  59.0F, 52.0F, 48.0F, 44.0F, 42.0F, 42.0F, 42.0F, 42.0F, 42.0F, 44.0F, 46.0F,
  49.0F, 49.0F, 49.0F, 49.0F, 49.0F, 67.0F, 72.0F, 65.0F, 58.0F, 55.0F, 51.0F,
  49.0F, 49.0F, 48.0F, 49.0F, 49.0F, 50.0F, 53.0F, 55.0F, 55.0F, 55.0F, 55.0F,
  55.0F, 73.0F, 77.0F, 70.0F, 64.0F, 62.0F, 58.0F, 56.0F, 56.0F, 56.0F, 56.0F,
  56.0F, 58.0F, 60.0F, 62.0F, 62.0F, 62.0F, 62.0F, 62.0F, 79.0F, 82.0F, 76.0F,
  71.0F, 69.0F, 66.0F, 64.0F, 64.0F, 64.0F, 64.0F, 64.0F, 65.0F, 67.0F, 69.0F,
  69.0F, 69.0F, 69.0F, 69.0F, 83.0F, 86.0F, 82.0F, 78.0F, 76.0F, 74.0F, 72.0F,
  72.0F, 72.0F, 72.0F, 72.0F, 73.0F, 75.0F, 76.0F, 76.0F, 76.0F, 76.0F, 76.0F,
  89.0F, 91.0F, 88.0F, 85.0F, 84.0F, 82.0F, 81.0F, 81.0F, 81.0F, 81.0F, 81.0F,
  82.0F, 83.0F, 84.0F, 84.0F, 84.0F, 84.0F, 84.0F, 95.0F, 96.0F, 94.0F, 92.0F,
  92.0F, 91.0F, 90.0F, 90.0F, 90.0F, 90.0F, 90.0F, 91.0F, 91.0F, 92.0F, 92.0F,
  92.0F, 92.0F, 92.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F } ;              /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 MTQD_FwdPedMapSpt_pct[378] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 4.0F, 4.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 10.0F, 13.0F, 6.0F, 2.0F, 2.0F, 2.1F,
  2.3F, 2.6F, 2.8F, 2.9F, 2.9F, 2.8F, 2.7F, 2.7F, 2.7F, 2.7F, 2.7F, 2.7F, 17.0F,
  22.0F, 15.0F, 10.0F, 6.0F, 4.0F, 4.0F, 4.5F, 5.0F, 5.5F, 5.5F, 6.0F, 6.4F,
  6.8F, 7.0F, 7.0F, 7.0F, 7.0F, 25.0F, 32.0F, 25.0F, 18.0F, 14.0F, 10.0F, 8.0F,
  7.0F, 8.0F, 8.8F, 9.2F, 9.5F, 10.0F, 10.4F, 11.0F, 11.0F, 12.0F, 12.0F, 35.0F,
  42.0F, 35.0F, 27.0F, 23.0F, 19.0F, 16.0F, 15.0F, 13.0F, 12.0F, 12.0F, 13.0F,
  14.0F, 15.0F, 16.0F, 17.0F, 18.0F, 18.0F, 44.0F, 52.0F, 44.0F, 35.0F, 32.0F,
  28.0F, 25.0F, 23.0F, 22.0F, 20.0F, 19.0F, 19.0F, 19.0F, 21.0F, 22.0F, 23.0F,
  24.0F, 24.0F, 52.0F, 59.0F, 50.0F, 43.0F, 41.0F, 38.0F, 35.0F, 34.0F, 33.0F,
  31.0F, 30.0F, 28.0F, 27.0F, 27.0F, 28.0F, 29.0F, 30.0F, 30.0F, 58.0F, 64.0F,
  56.0F, 48.0F, 47.0F, 45.0F, 43.0F, 43.0F, 44.0F, 43.0F, 42.0F, 40.0F, 39.0F,
  38.0F, 38.0F, 38.0F, 38.0F, 38.0F, 64.0F, 69.0F, 62.0F, 54.0F, 53.0F, 51.0F,
  49.0F, 50.0F, 52.0F, 52.0F, 53.0F, 53.0F, 53.0F, 52.0F, 51.0F, 51.0F, 52.0F,
  52.0F, 70.0F, 74.0F, 67.0F, 60.0F, 58.0F, 56.0F, 55.0F, 56.0F, 58.0F, 59.0F,
  61.0F, 63.0F, 65.0F, 66.0F, 66.0F, 66.0F, 66.0F, 66.0F, 74.0F, 78.0F, 72.0F,
  65.0F, 64.0F, 62.0F, 61.0F, 62.0F, 64.0F, 66.0F, 68.0F, 70.0F, 73.0F, 73.0F,
  76.0F, 78.0F, 80.0F, 80.0F, 79.0F, 82.0F, 77.0F, 70.0F, 69.0F, 68.0F, 67.0F,
  68.0F, 70.0F, 71.0F, 73.0F, 75.0F, 77.0F, 78.0F, 80.0F, 83.0F, 87.0F, 87.0F,
  84.0F, 86.0F, 82.0F, 75.0F, 74.0F, 73.0F, 72.0F, 73.0F, 75.0F, 76.0F, 78.0F,
  80.0F, 82.0F, 82.0F, 84.0F, 87.0F, 90.0F, 90.0F, 88.0F, 90.0F, 86.0F, 80.0F,
  79.0F, 78.0F, 77.0F, 79.0F, 80.0F, 81.0F, 83.0F, 84.0F, 86.0F, 87.0F, 88.0F,
  91.0F, 94.0F, 94.0F, 92.0F, 93.0F, 90.0F, 84.0F, 84.0F, 83.0F, 82.0F, 83.0F,
  85.0F, 86.0F, 88.0F, 89.0F, 90.0F, 91.0F, 92.5F, 94.0F, 94.5F, 94.5F, 94.0F,
  95.0F, 93.0F, 88.0F, 88.0F, 87.0F, 87.0F, 88.0F, 89.0F, 90.0F, 92.0F, 93.0F,
  94.0F, 95.0F, 95.5F, 95.5F, 95.5F, 95.5F, 96.0F, 97.0F, 96.0F, 92.0F, 92.0F,
  91.0F, 91.0F, 92.0F, 93.0F, 94.0F, 95.0F, 96.0F, 96.0F, 97.0F, 98.0F, 99.0F,
  99.0F, 99.0F, 99.0F, 99.0F, 98.0F, 95.0F, 95.0F, 94.0F, 94.0F, 95.0F, 96.0F,
  97.0F, 98.0F, 98.0F, 98.0F, 99.0F, 99.0F, 99.0F, 99.0F, 99.0F, 100.0F, 100.0F,
  99.0F, 98.0F, 98.0F, 97.0F, 97.0F, 98.0F, 98.0F, 99.0F, 99.0F, 99.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F,
  100.0F, 100.0F, 100.0F } ;
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct2' */

CALDATA const volatile float32 MTQD_LimpHomeMaxTq_Nm[8] = { 828.0F, 828.0F,
  1000.0F, 1500.0F, 1300.0F, 1000.0F, 828.0F, 828.0F } ;
                            /* Referenced by: '<S1278>/MTQD_CstTqReqWhlS_Nm2' */

CALDATA const volatile float32 MTQD_RevFullPedDrvTqWhl_Nm[19] = { 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 500.0F, 1000.0F, 2000.0F,
  4000.0F, 4000.0F, 4000.0F, 4000.0F, 4000.0F } ;
                                 /* Referenced by: '<S1285>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 MTQD_RevPedMap_pct[231] = { 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
  0.0F, 0.0F, 0.0F, 1.0F, 4.0F, 3.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 2.0F, 9.0F, 6.0F, 3.0F, 3.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 5.0F,
  14.0F, 10.0F, 5.0F, 4.0F, 4.0F, 3.0F, 3.0F, 3.0F, 3.0F, 5.0F, 10.0F, 20.0F,
  15.0F, 7.0F, 6.0F, 6.0F, 5.0F, 4.0F, 4.0F, 6.0F, 9.0F, 15.0F, 26.0F, 18.0F,
  10.0F, 9.0F, 8.0F, 7.0F, 7.0F, 8.0F, 10.0F, 14.0F, 21.0F, 30.0F, 22.0F, 12.0F,
  11.0F, 10.0F, 10.0F, 10.0F, 12.0F, 15.0F, 19.0F, 27.0F, 36.0F, 26.5F, 16.0F,
  15.0F, 14.0F, 14.0F, 15.0F, 17.0F, 20.0F, 24.0F, 32.0F, 42.0F, 32.5F, 20.0F,
  19.0F, 19.0F, 19.0F, 20.0F, 22.0F, 26.0F, 29.0F, 37.0F, 47.0F, 38.0F, 25.0F,
  24.0F, 24.0F, 24.0F, 25.0F, 27.0F, 31.0F, 35.0F, 43.0F, 52.0F, 44.0F, 30.0F,
  30.0F, 29.0F, 29.0F, 30.0F, 32.0F, 36.0F, 40.0F, 48.0F, 57.0F, 50.0F, 36.0F,
  36.0F, 35.0F, 35.0F, 36.0F, 38.0F, 42.0F, 46.0F, 53.0F, 62.0F, 56.0F, 42.0F,
  42.0F, 42.0F, 42.0F, 42.0F, 44.0F, 48.0F, 52.0F, 59.0F, 67.0F, 61.0F, 49.0F,
  49.0F, 48.0F, 49.0F, 49.0F, 51.0F, 55.0F, 58.0F, 65.0F, 72.0F, 67.0F, 56.0F,
  56.0F, 56.0F, 56.0F, 56.0F, 58.0F, 62.0F, 64.0F, 70.0F, 77.0F, 73.0F, 64.0F,
  64.0F, 64.0F, 64.0F, 64.0F, 66.0F, 69.0F, 71.0F, 76.0F, 82.0F, 79.0F, 72.0F,
  72.0F, 72.0F, 72.0F, 72.0F, 74.0F, 76.0F, 78.0F, 82.0F, 86.0F, 83.0F, 81.0F,
  81.0F, 81.0F, 81.0F, 81.0F, 82.0F, 84.0F, 85.0F, 88.0F, 91.0F, 89.0F, 90.0F,
  90.0F, 90.0F, 90.0F, 90.0F, 91.0F, 92.0F, 92.0F, 94.0F, 96.0F, 95.0F, 100.0F,
  100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F, 100.0F
} ;                       /* Referenced by: '<S1285>/MTQD_PedMapBasTqEco_pct' */

CALDATA const volatile float32 MTQD_TqDrtFacBrkPedAccOff_c[9] = { 1.0F, 1.0F,
  0.6F, 0.5F, 0.1F, 0.05F, 0.04F, 0.0F, 0.0F } ;
                      /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOff_c' */

CALDATA const volatile float32 MTQD_TqDrtFacBrkPedAccOn_c[45] = { 1.0F, 1.0F,
  0.65F, 0.65F, 0.65F, 0.65F, 0.65F, 0.1F, 0.0F, 1.0F, 1.0F, 0.65F, 0.65F, 0.65F,
  0.65F, 0.65F, 0.1F, 0.0F, 1.0F, 1.0F, 0.6F, 0.5F, 0.08F, 0.05F, 0.0F, 0.0F,
  0.0F, 1.0F, 1.0F, 0.6F, 0.5F, 0.08F, 0.05F, 0.0F, 0.0F, 0.0F, 1.0F, 1.0F, 0.6F,
  0.5F, 0.08F, 0.05F, 0.0F, 0.0F, 0.0F } ;
                       /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOn_c' */

CALDATA const volatile float32 MTQD_TqDrtFacHiddenLmtPwr_c[7] = { 0.0F, 0.35F,
  0.5F, 0.5F, 0.5F, 0.35F, 0.0F } ;
               /* Referenced by: '<S1325>/Lookup_MTQD_TqDrtFacHiddenLmtPwr_c' */

CALDATA const volatile float32 MTQD_TqDrtFacLimpHome_c[7] = { 0.0F, 0.3F, 1.0F,
  1.0F, 1.0F, 0.3F, 0.0F } ;
                /* Referenced by: '<S1324>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 MTQD_TqDrtFacLmtPerfmn_c[8] = { 0.5F, 0.65F, 0.8F,
  0.7F, 0.6F, 0.5F, 0.5F, 0.5F } ;
                /* Referenced by: '<S1323>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 MTQD_TqDrtFacMotorSpd_c[5] = { 0.0F, 1.0F, 1.0F,
  1.0F, 0.0F } ;                 /* Referenced by: '<S1320>/MTQD_TMOverDrt_c' */

CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl1_c[7] = { 0.0F, 0.3F,
  1.0F, 1.0F, 1.0F, 0.3F, 0.0F } ;
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl2_c[7] = { 0.0F, 0.35F,
  1.0F, 1.0F, 1.0F, 0.35F, 0.0F } ;
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */

CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl3_c[7] = { 0.0F, 0.4F,
  1.0F, 1.0F, 1.0F, 0.4F, 0.0F } ;
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */

CALDATA const volatile float32 MTQD_TqDrtFacVehSpdEco_c[6] = { 0.0F, 1.0F, 1.0F,
  1.0F, 0.5F, 0.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */

CALDATA const volatile float32 MTQD_TqDrtFacVehSpdNorm_c[6] = { 0.0F, 1.0F, 1.0F,
  1.0F, 0.5F, 0.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */

CALDATA const volatile float32 MTQD_TqDrtFacVehSpdRev_c[6] = { 0.0F, 0.7F, 1.0F,
  1.0F, 1.0F, 0.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c4' */

CALDATA const volatile float32 MTQD_TqDrtFacVehSpdSnow_c[6] = { 0.0F, 1.0F, 1.0F,
  1.0F, 0.5F, 0.0F } ;
                 /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c' */

CALDATA const volatile float32 MTQD_TqDrtFacVehSpdSpt_c[6] = { 0.0F, 1.0F, 1.0F,
  1.0F, 0.5F, 0.0F } ;
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */

CALDATA const volatile float32 MTQD_WhlSpdDiffMaxTqFac_c[10] = { 1.0F, 1.0F,
  0.9F, 0.85F, 0.8F, 0.6F, 0.4F, 0.2F, 0.1F, 0.0F } ;
                             /* Referenced by: '<S1278>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MTQD_WhlSpdDiffMaxTq_Nm[10] = { 4000.0F, 4000.0F,
  3600.0F, 3000.0F, 2000.0F, 1200.0F, 800.0F, 400.0F, 100.0F, 0.0F } ;
                            /* Referenced by: '<S1278>/MTQD_CstTqReqWhlS_Nm1' */

CALDATA const volatile float32 MTQF_DecEndRateFiltTmSMode_s[12] = { 0.03F, 0.03F,
  0.05F, 0.05F, 0.06F, 0.06F, 0.07F, 0.08F, 0.1F, 0.15F, 0.2F, 0.08F } ;
                             /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MTQF_DecEndRateFiltTm_s[12] = { 0.03F, 0.03F,
  0.05F, 0.05F, 0.06F, 0.06F, 0.07F, 0.08F, 0.1F, 0.15F, 0.2F, 0.08F } ;
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm1' */

/* torque decrease rate filter time in ending phase */
CALDATA const volatile float32 MTQF_DecStartRateFiltTmACC_s[12] = { 0.02F, 0.02F,
  0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.05F, 0.1F, 0.08F } ;
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm2' */

CALDATA const volatile float32 MTQF_DecStartRateFiltTmSMode_s[12] = { 0.02F,
  0.02F, 0.03F, 0.03F, 0.03F, 0.05F, 0.05F, 0.06F, 0.08F, 0.1F, 0.15F, 0.08F } ;
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm3' */

CALDATA const volatile float32 MTQF_DecStartRateFiltTm_s[12] = { 0.02F, 0.02F,
  0.03F, 0.03F, 0.03F, 0.05F, 0.05F, 0.06F, 0.08F, 0.1F, 0.15F, 0.08F } ;
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm4' */

/* torque decrease rate filter time in starting phase */
CALDATA const volatile float32 MTQF_IncEndRateFiltTmSMode_s[12] = { 0.1F, 0.2F,
  0.15F, 0.1F, 0.05F, 0.03F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F, 0.02F } ;
                             /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm' */

CALDATA const volatile float32 MTQF_IncEndRateFiltTm_s[12] = { 0.1F, 0.2F, 0.15F,
  0.1F, 0.08F, 0.07F, 0.06F, 0.06F, 0.05F, 0.05F, 0.05F, 0.05F } ;
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm1' */

/* torque increase rate filter time in ending phase */
CALDATA const volatile float32 MTQF_IncStartRateFiltTmACC_s[12] = { 0.05F, 0.03F,
  0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.02F, 0.02F } ;
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm2' */

CALDATA const volatile float32 MTQF_IncStartRateFiltTmSMode_s[12] = { 0.05F,
  0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.03F, 0.02F, 0.02F } ;
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm3' */

CALDATA const volatile float32 MTQF_IncStartRateFiltTm_s[12] = { 0.1F, 0.2F,
  0.2F, 0.15F, 0.15F, 0.1F, 0.05F, 0.03F, 0.03F, 0.03F, 0.02F, 0.02F } ;
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm4' */

/* torque increase rate filter time in starting phase */
CALDATA const volatile float32 MTQF_TipOutTqDecRateCoeff_rat[8] = { 1.0F, 1.0F,
  1.5F, 1.8F, 1.9F, 2.0F, 2.0F, 2.0F } ;
                                /* Referenced by: '<S1339>/1-D Lookup Table1' */

CALDATA const volatile float32 MTQF_TqRateDecMaxACC_Nmps[8] = { -3000.0F,
  -3500.0F, -4500.0F, -5000.0F, -5500.0F, -6000.0F, -6000.0F, -6000.0F } ;
                                    /* Referenced by: '<S1339>/Lookup Table5' */

/* Max torque decreasing change rate in ACC */
CALDATA const volatile float32 MTQF_TqRateDecMaxE_Nmps[156] = { -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2600.0F,
  -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F,
  -2600.0F, -2600.0F, -2600.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F,
  -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F } ;
                   /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* Max torque decreasing change rate in Eco */
CALDATA const volatile float32 MTQF_TqRateDecMaxN_Nmps[156] = { -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F } ;
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* Max torque decreasing change rate in Normal */
CALDATA const volatile float32 MTQF_TqRateDecMaxRegenE_Nmps[91] = { -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F,
  -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1500.0F, -1800.0F, -1800.0F, -1800.0F,
  -1800.0F, -1800.0F, -1800.0F, -1800.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F } ;
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl3' */

CALDATA const volatile float32 MTQF_TqRateDecMaxRegenN_Nmps[91] = { -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F } ;
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl5' */

CALDATA const volatile float32 MTQF_TqRateDecMaxRegenS_Nmps[91] = { -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F,
  -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2000.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F } ;
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl4' */

CALDATA const volatile float32 MTQF_TqRateDecMaxS_Nmps[156] = { -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F,
  -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2500.0F, -2600.0F,
  -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F, -2600.0F,
  -2600.0F, -2600.0F, -2600.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F,
  -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2800.0F, -2900.0F,
  -2900.0F, -2900.0F, -2900.0F, -2900.0F, -2900.0F, -2900.0F, -2900.0F, -2900.0F,
  -2900.0F, -2900.0F, -2900.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F,
  -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3000.0F, -3100.0F,
  -3100.0F, -3100.0F, -3100.0F, -3100.0F, -3100.0F, -3100.0F, -3100.0F, -3100.0F,
  -3100.0F, -3100.0F, -3100.0F } ;
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* Max torque decreasing change rate in Sport */
CALDATA const volatile float32 MTQF_TqRateIncMaxACC_Nmps[8] = { 5000.0F, 5000.0F,
  6500.0F, 7000.0F, 7500.0F, 8000.0F, 9000.0F, 9000.0F } ;
                                    /* Referenced by: '<S1340>/Lookup Table5' */

/* Max torque increasing change rate in ACC */
CALDATA const volatile float32 MTQF_TqRateIncMaxE_Nmps[156] = { 1635.0F, 1635.0F,
  3379.0F, 3379.0F, 3815.0F, 4905.0F, 4905.0F, 4905.0F, 4905.0F, 5995.0F,
  7085.0F, 7085.0F, 1635.0F, 1635.0F, 3379.0F, 3379.0F, 3815.0F, 4905.0F,
  4905.0F, 4905.0F, 4905.0F, 5995.0F, 7085.0F, 7085.0F, 1635.0F, 800.0F, 3379.0F,
  3379.0F, 3815.0F, 4905.0F, 4905.0F, 4905.0F, 4905.0F, 5995.0F, 7085.0F,
  7085.0F, 1635.0F, 1635.0F, 3379.0F, 3379.0F, 3815.0F, 4905.0F, 4905.0F,
  4905.0F, 4905.0F, 5995.0F, 7085.0F, 7085.0F, 1635.0F, 1635.0F, 3379.0F,
  3379.0F, 3815.0F, 4905.0F, 4905.0F, 4905.0F, 4905.0F, 5995.0F, 7085.0F,
  7085.0F, 2071.0F, 2071.0F, 2180.0F, 2180.0F, 3815.0F, 3815.0F, 3815.0F,
  4905.0F, 5995.0F, 5995.0F, 7085.0F, 7085.0F, 2180.0F, 2180.0F, 2180.0F,
  2180.0F, 3815.0F, 3815.0F, 3815.0F, 4905.0F, 5995.0F, 5995.0F, 7085.0F,
  7085.0F, 2180.0F, 2180.0F, 2180.0F, 2180.0F, 3815.0F, 3815.0F, 3815.0F,
  4905.0F, 5450.0F, 5995.0F, 7085.0F, 7085.0F, 2180.0F, 2180.0F, 2180.0F,
  2180.0F, 3815.0F, 3815.0F, 3815.0F, 4905.0F, 5450.0F, 5995.0F, 7085.0F,
  7085.0F, 2180.0F, 2180.0F, 2180.0F, 2180.0F, 3379.0F, 3379.0F, 3815.0F,
  4905.0F, 5450.0F, 5995.0F, 7085.0F, 7085.0F, 2180.0F, 2180.0F, 2180.0F,
  2180.0F, 3379.0F, 3379.0F, 3815.0F, 4905.0F, 5450.0F, 5995.0F, 7085.0F,
  7085.0F, 2180.0F, 2180.0F, 2180.0F, 2180.0F, 3379.0F, 3379.0F, 3815.0F,
  4905.0F, 5450.0F, 5995.0F, 7085.0F, 7085.0F, 2180.0F, 2180.0F, 2180.0F,
  2180.0F, 3379.0F, 3379.0F, 3815.0F, 4905.0F, 5450.0F, 5995.0F, 7085.0F,
  7085.0F } ;      /* Referenced by: '<S1340>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* Max torque increasing change rate in Eco */
CALDATA const volatile float32 MTQF_TqRateIncMaxN_Nmps[156] = { 2180.0F, 2180.0F,
  3924.0F, 3924.0F, 4360.0F, 5450.0F, 5450.0F, 5450.0F, 5450.0F, 6540.0F,
  8720.0F, 10900.0F, 1635.0F, 1635.0F, 3924.0F, 3924.0F, 4360.0F, 5450.0F,
  5450.0F, 5450.0F, 5450.0F, 6540.0F, 8720.0F, 10900.0F, 1635.0F, 800.0F,
  3924.0F, 3924.0F, 4360.0F, 5450.0F, 5450.0F, 5450.0F, 5450.0F, 6540.0F,
  8720.0F, 10900.0F, 1635.0F, 1635.0F, 3924.0F, 3924.0F, 4360.0F, 5450.0F,
  5450.0F, 5450.0F, 5450.0F, 6540.0F, 8720.0F, 10900.0F, 2180.0F, 2180.0F,
  3924.0F, 3924.0F, 4360.0F, 5450.0F, 5450.0F, 5450.0F, 5450.0F, 6540.0F,
  8720.0F, 10900.0F, 2725.0F, 2725.0F, 2725.0F, 2725.0F, 4360.0F, 4360.0F,
  4360.0F, 4360.0F, 6540.0F, 7630.0F, 8720.0F, 10900.0F, 2725.0F, 2725.0F,
  2725.0F, 2725.0F, 4360.0F, 4360.0F, 4360.0F, 4360.0F, 6540.0F, 7630.0F,
  8720.0F, 10900.0F, 2725.0F, 2725.0F, 2725.0F, 2725.0F, 4360.0F, 4360.0F,
  4360.0F, 4360.0F, 6540.0F, 7630.0F, 8720.0F, 10900.0F, 2725.0F, 2725.0F,
  2725.0F, 2725.0F, 4360.0F, 4360.0F, 4360.0F, 4360.0F, 6540.0F, 7630.0F,
  8720.0F, 10900.0F, 2725.0F, 2725.0F, 2725.0F, 2725.0F, 3924.0F, 3924.0F,
  4360.0F, 4360.0F, 6540.0F, 7630.0F, 8720.0F, 10900.0F, 2725.0F, 2725.0F,
  2725.0F, 2725.0F, 3924.0F, 3924.0F, 4360.0F, 4360.0F, 6540.0F, 7630.0F,
  8720.0F, 10900.0F, 2725.0F, 2725.0F, 2725.0F, 2725.0F, 3924.0F, 3924.0F,
  4360.0F, 4360.0F, 6540.0F, 7630.0F, 8720.0F, 10900.0F, 2725.0F, 2725.0F,
  2725.0F, 2725.0F, 3924.0F, 3924.0F, 4360.0F, 4360.0F, 6540.0F, 7630.0F,
  8720.0F, 10900.0F } ;
                  /* Referenced by: '<S1340>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* Max torque increasing change rate in Normal */
CALDATA const volatile float32 MTQF_TqRateIncMaxS_Nmps[156] = { 2725.0F, 2725.0F,
  4360.0F, 4578.0F, 4905.0F, 5450.0F, 5450.0F, 5450.0F, 5450.0F, 9810.0F,
  10900.0F, 10900.0F, 2180.0F, 2180.0F, 4360.0F, 4578.0F, 4905.0F, 5450.0F,
  5450.0F, 5450.0F, 5450.0F, 9810.0F, 10900.0F, 10900.0F, 2180.0F, 800.0F,
  4360.0F, 4578.0F, 4905.0F, 5450.0F, 5450.0F, 5450.0F, 5450.0F, 9810.0F,
  10900.0F, 10900.0F, 2180.0F, 2180.0F, 4360.0F, 4578.0F, 4905.0F, 6540.0F,
  6540.0F, 6540.0F, 8175.0F, 9810.0F, 10900.0F, 10900.0F, 4360.0F, 4360.0F,
  4360.0F, 4578.0F, 5450.0F, 6540.0F, 7630.0F, 7630.0F, 8175.0F, 9810.0F,
  10900.0F, 10900.0F, 4360.0F, 4360.0F, 4360.0F, 4578.0F, 5450.0F, 6540.0F,
  7630.0F, 7630.0F, 8175.0F, 9810.0F, 10900.0F, 10900.0F, 4360.0F, 4360.0F,
  4360.0F, 4578.0F, 5450.0F, 6540.0F, 7630.0F, 7630.0F, 8175.0F, 9810.0F,
  10900.0F, 10900.0F, 4578.0F, 4578.0F, 4578.0F, 4578.0F, 7085.0F, 7085.0F,
  7630.0F, 7630.0F, 8175.0F, 9810.0F, 10900.0F, 10900.0F, 4578.0F, 4578.0F,
  4578.0F, 4578.0F, 7085.0F, 7085.0F, 7630.0F, 7630.0F, 9265.0F, 9810.0F,
  10900.0F, 10900.0F, 4578.0F, 4578.0F, 4578.0F, 4578.0F, 7085.0F, 7085.0F,
  7630.0F, 7630.0F, 9265.0F, 9810.0F, 10900.0F, 10900.0F, 4905.0F, 4905.0F,
  4905.0F, 5014.0F, 7630.0F, 7630.0F, 8175.0F, 8175.0F, 9265.0F, 9810.0F,
  10900.0F, 10900.0F, 4905.0F, 4905.0F, 4905.0F, 5014.0F, 7630.0F, 7630.0F,
  8175.0F, 8175.0F, 9265.0F, 9810.0F, 10900.0F, 10900.0F, 4905.0F, 4905.0F,
  4905.0F, 5014.0F, 7630.0F, 7630.0F, 8175.0F, 8175.0F, 9265.0F, 9810.0F,
  10900.0F, 10900.0F } ;
                  /* Referenced by: '<S1340>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* Max torque increasing change rate in Sport */
CALDATA const volatile float32 MTQF_TqRateLimEndErrE_Nm[154] = { 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F } ;
                   /* Referenced by: '<S1338>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* torque ending error in E */
CALDATA const volatile float32 MTQF_TqRateLimEndErrN_Nm[154] = { 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F } ;
                  /* Referenced by: '<S1338>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* torque ending error in N */
CALDATA const volatile float32 MTQF_TqRateLimEndErrS_Nm[154] = { 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 200.0F, 200.0F,
  200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 200.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F, 150.0F,
  150.0F, 150.0F } ;
                  /* Referenced by: '<S1338>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* torque ending error in S */
CALDATA const volatile float32 MTQR_ASDSpdFiltHi_s[8] = { 0.0011F, 0.0043F,
  0.01F, 0.0488F, 0.0733F, 0.1011F, 0.1329F, 0.1329F } ;
                                 /* Referenced by: '<S1366>/1-D Lookup Table' */

CALDATA const volatile float32 MTQR_ASDTqGain_c[8] = { -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F } ;
                                 /* Referenced by: '<S1367>/1-D Lookup Table' */

CALDATA const volatile float32 MTZX_AZDecRate_Nmps[11] = { -250.0F, -250.0F,
  -200.0F, -180.0F, -150.0F, -120.0F, -70.0F, -50.0F, -35.0F, -100.0F, -100.0F }
;                               /* Referenced by: '<S1398>/1-D Lookup Table4' */

CALDATA const volatile float32 MTZX_AZIncRate_Nmps[11] = { 100.0F, 100.0F, 50.0F,
  50.0F, 100.0F, 150.0F, 200.0F, 250.0F, 300.0F, 400.0F, 400.0F } ;
                                /* Referenced by: '<S1398>/1-D Lookup Table3' */

CALDATA const volatile float32 MTZX_AZRngDec_Nm[12] = { 6.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F } ;
                         /* Referenced by: '<S1398>/MTZX_AZRngTipOutTMOly_Nm' */

CALDATA const volatile float32 MTZX_AZRngInc_Nm[12] = { 6.0F, 6.0F, 6.0F, 6.0F,
  6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F, 6.0F } ;
                          /* Referenced by: '<S1398>/MTZX_AZRngTipInTMOly_Nm' */

CALDATA const volatile float32 MTZX_BZDecRate_Nmps[11] = { -35.0F, -35.0F,
  -35.0F, -50.0F, -75.0F, -125.0F, -200.0F, -400.0F, -700.0F, -800.0F, -800.0F }
;                               /* Referenced by: '<S1398>/1-D Lookup Table2' */

CALDATA const volatile float32 MTZX_BZIncRate_Nmps[11] = { 800.0F, 800.0F,
  700.0F, 400.0F, 200.0F, 125.0F, 75.0F, 50.0F, 35.0F, 35.0F, 35.0F } ;
                                /* Referenced by: '<S1398>/1-D Lookup Table1' */

CALDATA const volatile float32 MTZX_BZRngDec_Nm[12] = { 10.0F, 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F } ;
                         /* Referenced by: '<S1398>/MTZX_BZRngTipOutTMOly_Nm' */

CALDATA const volatile float32 MTZX_BZRngInc_Nm[12] = { 10.0F, 10.0F, 10.0F,
  10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F } ;
                          /* Referenced by: '<S1398>/MTZX_BZRngTipInTMOly_Nm' */

CALDATA const volatile float32 MTZX_RampDecRate_Nmps[10] = { -200.0F, -300.0F,
  -400.0F, -500.0F, -600.0F, -600.0F, -600.0F, -600.0F, -800.0F, -800.0F } ;
                                /* Referenced by: '<S1397>/1-D Lookup Table1' */

CALDATA const volatile float32 MTZX_RampIncRate_Nmps[10] = { 200.0F, 300.0F,
  400.0F, 500.0F, 600.0F, 600.0F, 600.0F, 600.0F, 800.0F, 800.0F } ;
                                /* Referenced by: '<S1397>/1-D Lookup Table2' */

CALDATA const volatile float32 MTZX_ZeroTqOfstDecACC_Nm[12] = { -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                   /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipOutTMOly_Nm5' */

CALDATA const volatile float32 MTZX_ZeroTqOfstDec_Nm[80] = { -1.0F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F, -1.0F,
  -1.0F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F,
  -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F,
  -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -0.5F, -1.0F, -1.0F,
  -1.0F, -1.0F, -1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F } ;
                                /* Referenced by: '<S1398>/2-D Lookup Table1' */

CALDATA const volatile float32 MTZX_ZeroTqOfstIncACC_Nm[12] = { 1.0F, 2.0F, 2.0F,
  2.0F, 6.0F, 6.0F, 6.0F, 5.0F, 5.0F, 3.0F, 3.0F, 0.0F } ;
                    /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipInTMOly_Nm1' */

CALDATA const volatile float32 MTZX_ZeroTqOfstInc_Nm[80] = { 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 2.0F, 1.6F,
  1.6F, 1.6F, 0.5F, 0.0F, 1.6F, 1.6F, 1.6F, 0.5F, 0.0F, 1.6F, 1.6F, 1.6F, 0.5F,
  0.0F, 1.6F, 1.6F, 1.6F, 0.5F, 0.0F, 1.6F, 1.6F, 1.6F, 1.6F, 1.6F, 1.6F, 1.6F,
  1.6F, 1.6F, 1.6F, 1.6F, 1.6F, 1.6F, 1.6F, 1.6F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F,
  1.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F } ;
                                 /* Referenced by: '<S1398>/2-D Lookup Table' */

CALDATA const volatile float32 MTZX_ZeroXTmACC_s[10] = { 0.05F, 0.05F, 0.08F,
  0.08F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F } ;
                        /* Referenced by: '<S1398>/MTZX_ZeroXTmTipInTMOly_s1' */

CALDATA const volatile float32 MTZX_ZeroXTmDec_s[80] = { 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.18F, 0.18F, 0.18F, 0.18F, 0.18F, 0.18F, 0.18F, 0.18F, 0.18F,
  0.18F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F, 0.12F,
  0.12F, 0.12F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.05F, 0.05F, 0.05F, 0.05F,
  0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F } ;
                                /* Referenced by: '<S1398>/2-D Lookup Table2' */

CALDATA const volatile float32 MTZX_ZeroXTmInc_s[80] = { 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F, 0.15F,
  0.18F, 0.18F, 0.16F, 0.1F, 0.1F, 0.18F, 0.18F, 0.16F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
  0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.08F, 0.08F,
  0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F, 0.08F,
  0.08F, 0.08F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F,
  0.05F, 0.05F, 0.05F, 0.05F, 0.05F, 0.05F } ;
                                /* Referenced by: '<S1398>/2-D Lookup Table3' */

CALDATA const volatile float32 MVTM_ActPwrBacklash_kW[8] = { 0.0F, 0.0F, 0.2F,
  0.4F, 0.6F, 1.0F, 1.5F, 1.5F } ;     /* Referenced by: '<S1454>/Dbnd' */

CALDATA const volatile float32 MVTM_MotorMaxDrvTqWT_Nm[23] = { 280.0F, 280.0F,
  280.0F, 280.0F, 280.0F, 280.0F, 280.0F, 280.0F, 280.0F, 280.0F, 280.0F, 278.0F,
  262.0F, 226.0F, 193.0F, 169.0F, 150.0F, 133.0F, 119.0F, 107.0F, 99.0F, 90.0F,
  85.0F } ;                      /* Referenced by: '<S1449>/MTQD_PTBaseTq_Nm' */

CALDATA const volatile float32 MVTM_MotorSpdFiltCoeff_rat[8] = { 0.95F, 0.93F,
  0.9F, 0.85F, 0.75F, 0.65F, 0.5F, 0.3F } ;
                      /* Referenced by: '<S1440>/MPPC_OutSftSpdFiltCoeff_rat' */

CALDATA const volatile float32 MVTM_VehSpdFiltCoeff_rat[8] = { 0.91F, 0.9F, 0.8F,
  0.7F, 0.6F, 0.5F, 0.35F, 0.0F } ;
                  /* Referenced by: '<S1440>/Lookup_MVTM_VehSpdFiltCoeff_rat' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
