/*
 * File: calPrmsVcu.h
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

#ifndef RTW_HEADER_calPrmsVcu_h_
#define RTW_HEADER_calPrmsVcu_h_
#include "rtwtypes.h"
#include "AppSwcVcu_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile float32 ACPT_MotorEffVoltFac_X_V[9];
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c1' */
extern CALDATA const volatile float32 ACPT_MotorSpdFiltCoeff_X_rpm[8];
                      /* Referenced by: '<S1117>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqGen_X_kW[22];
                          /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm1' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqGen_Y_rpm[28];
                          /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm1' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqMot_X_kW[21];
                           /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqMot_Y_rpm[28];
                           /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm' */
extern CALDATA const volatile float32 ACPT_TqDrtFacIgbtTemp_X_C[8];
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c2' */
extern CALDATA const volatile float32 ACPT_TqDrtFacMotorTemp_X_C[8];
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c4' */
extern CALDATA const volatile float32 ADAC_ACCDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1145>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ADAC_ACCDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1145>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ADAC_ACCDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1145>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ADAC_ACCOvrdTq_X_kph[7];
                        /* Referenced by: '<S1139>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnDec_X_mps2[12];
                /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm1' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnDeltaSpd_X_kph[21];
               /* Referenced by: '<S1161>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnInc_X_mps2[12];
                 /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnSpd_X_kph[6];
                /* Referenced by: '<S1161>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */
extern CALDATA const volatile float32 ADAC_CCDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1168>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ADAC_CCDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1168>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ADAC_CCDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1168>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ADAC_CCMaxDrgTqWhl_X_kph[14];
                        /* Referenced by: '<S1170>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ADAC_CCSpdStabOfst_X_kph[8];
                        /* Referenced by: '<S1197>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ADAC_FullPedDrvTqWhl_X_kph[23];
                                 /* Referenced by: '<S1134>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 ADAC_HDCDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1234>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ADAC_HDCDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1234>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ADAC_HDCDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1234>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ADAC_HDCTgtAcceltnDeltaSpd_X_kph[16];
                                /* Referenced by: '<S1232>/1-D Lookup Table3' */
extern CALDATA const volatile float32 ADAC_INVMaxDrgTqWhl_X_kph[12];
                                /* Referenced by: '<S1134>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ADAC_NonDrvnSpdFiltCoeff_X_kph[7];
                 /* Referenced by: '<S1159>/Lookup_MVTM_VehSpdFiltCoeff_rat1' */
extern CALDATA const volatile float32 ADSA_DeceltnIdxAvg_X_pct[10];
                       /* Referenced by: '<S17>/MTQD_ZeroTqOfstTipInTMOly_Nm' */
extern CALDATA const volatile float32 ADSA_SprtIdxVehSpd_X_kph[15];
                          /* Referenced by: '<S17>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 AEMS_CellTempMinFac_X_C[5];
                                  /* Referenced by: '<S31>/MTQD_TMOverDrt_c5' */
extern CALDATA const volatile float32 AEMS_ChrgCurFbKi_X_mV[15];
                                  /* Referenced by: '<S81>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_ChrgCurFbKp_X_mV[11];
                                   /* Referenced by: '<S81>/lu1d_BatLimHiSoC' */
extern CALDATA const volatile float32 AEMS_ChrgPwrFbKi_X_kW[15];
                                  /* Referenced by: '<S46>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_ChrgPwrFbKp_X_kW[11];
                                   /* Referenced by: '<S46>/lu1d_BatLimHiSoC' */
extern CALDATA const volatile float32 AEMS_DchaCurFbKi_X_mV[15];
                                  /* Referenced by: '<S82>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_DchaCurFbKp_X_mV[11];
                                   /* Referenced by: '<S82>/lu1d_BatLimHiSoC' */
extern CALDATA const volatile float32 AEMS_DchaPwrFbKi_X_kW[15];
                                  /* Referenced by: '<S64>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_DchaPwrFbKp_X_kW[11];
                                   /* Referenced by: '<S64>/lu1d_BatLimHiSoC' */
extern CALDATA const volatile float32 AEMS_HVBatMaxChrgPwrSOC_X_pct[7];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c8' */
extern CALDATA const volatile float32 AEMS_HVBatMaxDchaPwrSOC_X_pct[7];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c6' */
extern CALDATA const volatile float32 AEMS_MaxConChrgCurOfst_X_A[8];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c1' */
extern CALDATA const volatile float32 AEMS_MaxConDchaCurOfst_X_A[8];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c1' */
extern CALDATA const volatile float32 AEMS_MaxInsChrgCurOfst_X_A[8];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c7' */
extern CALDATA const volatile float32 AEMS_MaxInsChrgCurr_X_C[17];
                     /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A' */
extern CALDATA const volatile float32 AEMS_MaxInsChrgCurr_Y_pct[10];/* Referenced by:
                                                                     * '<S26>/Lookup2D_MEMS_MaxInsDchaCurrFac_c'
                                                                     * '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A'
                                                                     */
extern CALDATA const volatile float32 AEMS_MaxInsDchaCurOfst_X_A[8];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c2' */
extern CALDATA const volatile float32 AEMS_MaxInsDchaCurr_X_C[17];
                     /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A' */
extern CALDATA const volatile float32 AEMS_MaxInsDchaCurr_Y_pct[10];/* Referenced by:
                                                                     * '<S28>/Lookup2D_MEMS_MaxInsDchaCurrFac_c'
                                                                     * '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A'
                                                                     */
extern CALDATA const volatile float32 AIBS_EnvirTemp_X_C[6];/* Referenced by:
                                                             * '<S1003>/MIBS_NextRtcWupThr_min'
                                                             * '<S1003>/MIBS_WupChgTmThr_min'
                                                             */

/* 环境温度（X轴）_versteckt */
extern CALDATA const volatile float32 AIBS_KL30_Y_V[10];/* Referenced by:
                                                         * '<S1003>/MIBS_NextRtcWupThr_min'
                                                         * '<S1003>/MIBS_WupChgTmThr_min'
                                                         */

/* KL30电压（Y轴）_versteckt */
extern CALDATA const volatile float32 AIPC_AccPedBckLsh_X_pct[12];
                                      /* Referenced by: '<S876>/Lookup Table' */
extern CALDATA const volatile uint8 AIPC_TireRadius_X_enum[6];
                                     /* Referenced by: '<S874>/TireSizeTable' */
extern CALDATA const volatile float32 ARME_BMSBatCellTempMin_X_C[6];/* Referenced by:
                                                                     * '<S960>/MRME_WLTPDwLimFac_c'
                                                                     * '<S979>/MRME_DynEstRmnChgStp_c'
                                                                     */

/* BMS电芯最小温度 */
extern CALDATA const volatile float32 ARME_BMSBatRptSOC_Y_pct[12];/* Referenced by:
                                                                   * '<S951>/MRME_CHTCStdRmnMil_km'
                                                                   * '<S960>/MRME_WLTPStdRmnMil_km'
                                                                   */

/* 标准续航查表RPTSOC值 */
extern CALDATA const volatile float32 ARME_EstTgtSubDynEstErr_Y_km[10];
                            /* Referenced by: '<S979>/MRME_DynEstRmnChgStp_c' */

/* 目标续航与实际续航值差值 */
extern CALDATA const volatile uint8 ASYS_HVBatPackTyp_X_Ah[10];/* Referenced by:
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
extern CALDATA const volatile float32 ATQC_RegenMaxTqDecRate_X_kph[4];
                /* Referenced by: '<S1261>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */
extern CALDATA const volatile float32 ATQC_RegenMaxTqDecRate_Y_pct[5];
               /* Referenced by: '<S1261>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */
extern CALDATA const volatile float32 ATQC_RegenMaxTqIncRate_X_Nm[8];
                        /* Referenced by: '<S1261>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1296>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1296>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1296>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ATQD_AdaptCstVehSpd_X_kph[14];/* Referenced by:
                                                                     * '<S1292>/ATQD_RegenTqBrk_X_kph_PL'
                                                                     * '<S1296>/ATQD_RegenTqBrk_X_kph_PL1'
                                                                     */
extern CALDATA const volatile float32 ATQD_CrpTqReqWhlD_X_kph[10];
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlD_Nm' */
extern CALDATA const volatile float32 ATQD_CrpTqReqWhlR_X_kph[10];
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlR_Nm' */
extern CALDATA const volatile float32 ATQD_CstRegenEndPstnV_X_kph[14];
                                /* Referenced by: '<S1291>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATQD_CstRegenEndPstn_X_kph[15];
                        /* Referenced by: '<S1291>/ATQD_RegenTqBrk_X_kph_PL2' */
extern CALDATA const volatile float32 ATQD_CstRegenRateAccPed_X_pct[8];
                        /* Referenced by: '<S1293>/ATQD_RegenTqBrk_X_kph_PL2' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlD_X_kph[14];
                        /* Referenced by: '<S1290>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlOff_X_pct[5];
                          /* Referenced by: '<S1290>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlOff_Y_kph[14];
                          /* Referenced by: '<S1290>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlR_X_kph[12];
                                /* Referenced by: '<S1290>/1-D Lookup Table2' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlV_X_kph[14];
                                /* Referenced by: '<S1290>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATQD_FwdFullPedDrvTqWhl_X_kph[19];/* Referenced by:
                                                                      * '<S1283>/MTQD_PTBaseTq_Nm'
                                                                      * '<S1283>/MTQD_PTBaseTq_Nm1'
                                                                      */
extern CALDATA const volatile float32 ATQD_FwdPedMapEco_X_kph[18];
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct1' */
extern CALDATA const volatile float32 ATQD_FwdPedMapEco_Y_pct[21];/* Referenced by:
                                                                   * '<S1283>/MTQD_PedMapBasTqEco_pct1'
                                                                   * '<S1283>/2-D Lookup Table1'
                                                                   */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpEco_X_kph[2];
                                /* Referenced by: '<S1283>/2-D Lookup Table1' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpNorm_X_kph[2];
                                /* Referenced by: '<S1283>/2-D Lookup Table3' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpSnow_X_kph[2];
                                 /* Referenced by: '<S1283>/2-D Lookup Table' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpSpt_X_kph[2];
                                /* Referenced by: '<S1283>/2-D Lookup Table2' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNorm_X_kph[18];
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct3' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNorm_Y_pct[21];/* Referenced by:
                                                                    * '<S1283>/MTQD_PedMapBasTqEco_pct3'
                                                                    * '<S1283>/2-D Lookup Table3'
                                                                    */
extern CALDATA const volatile float32 ATQD_FwdPedMapSnow_X_kph[18];
                          /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_FwdPedMapSnow_Y_pct[21];/* Referenced by:
                                                                    * '<S1283>/MTQD_PedMapBasTqEco_pct'
                                                                    * '<S1283>/2-D Lookup Table'
                                                                    */
extern CALDATA const volatile float32 ATQD_FwdPedMapSpt_X_kph[18];
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct2' */
extern CALDATA const volatile float32 ATQD_FwdPedMapSpt_Y_pct[21];/* Referenced by:
                                                                   * '<S1283>/MTQD_PedMapBasTqEco_pct2'
                                                                   * '<S1283>/2-D Lookup Table2'
                                                                   */
extern CALDATA const volatile float32 ATQD_LimpHomeMaxTq_X_kph[8];
                        /* Referenced by: '<S1278>/ATQD_RegenTqBrk_X_kph_PL2' */
extern CALDATA const volatile float32 ATQD_RevFullPedDrvTqWhl_X_kph[19];
                                 /* Referenced by: '<S1285>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 ATQD_RevPedMap_X_kph[11];
                          /* Referenced by: '<S1285>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_RevPedMap_Y_pct[21];
                          /* Referenced by: '<S1285>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOff_X_pct[9];
                      /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOff_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOn_X_pct[9];
                       /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOn_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOn_Y_kph[5];
                       /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOn_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacHiddenLmtPwr_X_kph[7];
               /* Referenced by: '<S1325>/Lookup_MTQD_TqDrtFacHiddenLmtPwr_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacLimpHome_X_kph[7];
                /* Referenced by: '<S1324>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacLmtPerfmn_X_kph[8];
                /* Referenced by: '<S1323>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacMotorSpd_X_rpm[5];
                                 /* Referenced by: '<S1320>/MTQD_TMOverDrt_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl1_X_kph[7];
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl2_X_kph[7];
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl3_X_kph[7];
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdEco_X_kph[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdNorm_X_kph[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdRev_X_kph[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c4' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdSnow_X_kph[6];
                 /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdSpt_X_kph[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 ATQD_WhlSpdDiffMaxTq_X_kph[10];
                        /* Referenced by: '<S1278>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ATQF_DecRateFiltTm_X_Nmps[12];
                        /* Referenced by: '<S1339>/ATQD_RegenTqBrk_X_kph_PL1' */

/* torque decrease rate filter time in starting phase, x axle */
extern CALDATA const volatile float32 ATQF_IncRateFiltTm_X_Nmps[12];
                        /* Referenced by: '<S1340>/ATQD_RegenTqBrk_X_kph_PL1' */

/* torque increase rate filter time in starting phase, x axle */
extern CALDATA const volatile float32 ATQF_TipOutTqDecRateCoeff_Nm[8];
                                /* Referenced by: '<S1339>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATQF_TqRateDecMaxACC_X_Nm[8];
                                    /* Referenced by: '<S1339>/Lookup Table5' */
extern CALDATA const volatile float32 ATQF_TqRateDecMaxRegen_X_pct[7];
               /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL6' */
extern CALDATA const volatile float32 ATQF_TqRateDecMaxRegen_Y_kph[13];
               /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL7' */
extern CALDATA const volatile float32 ATQF_TqRateDecMax_X_pct[12];
                /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* X axis of max torque decreasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateDecMax_Y_kph[13];
               /* Referenced by: '<S1339>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* Y axis of max torque decreasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateIncMaxACC_X_Nm[8];
                                    /* Referenced by: '<S1340>/Lookup Table5' */
extern CALDATA const volatile float32 ATQF_TqRateIncMax_X_pct[12];
                /* Referenced by: '<S1340>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* X axis of max torque increasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateIncMax_Y_kph[13];
               /* Referenced by: '<S1340>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* Y axis of max torque increasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateLimEndErr_X_pct[14];
                /* Referenced by: '<S1338>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* pedal position including acc and brk */
extern CALDATA const volatile float32 ATQF_TqRateLimEndErr_Y_kph[11];
               /* Referenced by: '<S1338>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* vehicle speed */
extern CALDATA const volatile float32 ATQR_ASDSpdFiltHi_X_rpm[8];
                                 /* Referenced by: '<S1366>/1-D Lookup Table' */
extern CALDATA const volatile float32 ATQR_ASDTqGain_X_kph[8];
                                 /* Referenced by: '<S1367>/1-D Lookup Table' */
extern CALDATA const volatile float32 ATZX_AZDecRate_X_Nm[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table4' */
extern CALDATA const volatile float32 ATZX_AZIncRate_X_Nm[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table3' */
extern CALDATA const volatile float32 ATZX_AZRngDec_X_kph[12];
                         /* Referenced by: '<S1398>/MTZX_AZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_AZRngInc_X_kph[12];
                          /* Referenced by: '<S1398>/MTZX_AZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_BZDecRate_X_Nm[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table2' */
extern CALDATA const volatile float32 ATZX_BZIncRate_X_Nm[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATZX_BZRngDec_X_kph[12];
                         /* Referenced by: '<S1398>/MTZX_BZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_BZRngInc_X_kph[12];
                          /* Referenced by: '<S1398>/MTZX_BZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_OPDSlopTq_X_Nm[5];/* Referenced by:
                                                              * '<S1398>/2-D Lookup Table'
                                                              * '<S1398>/2-D Lookup Table1'
                                                              * '<S1398>/2-D Lookup Table2'
                                                              * '<S1398>/2-D Lookup Table3'
                                                              */
extern CALDATA const volatile float32 ATZX_RampDecRate_X_Nm[10];
                                /* Referenced by: '<S1397>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATZX_RampIncRate_X_Nm[10];
                                /* Referenced by: '<S1397>/1-D Lookup Table2' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstDecACC_X_kph[12];
                   /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipOutTMOly_Nm5' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstDec_Y_kph[16];
                                /* Referenced by: '<S1398>/2-D Lookup Table1' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstIncACC_X_kph[12];
                    /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipInTMOly_Nm1' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstInc_Y_kph[16];
                                 /* Referenced by: '<S1398>/2-D Lookup Table' */
extern CALDATA const volatile float32 ATZX_ZeroXTmACC_X_kph[10];
                        /* Referenced by: '<S1398>/MTZX_ZeroXTmTipInTMOly_s1' */
extern CALDATA const volatile float32 ATZX_ZeroXTmDec_Y_kph[16];
                                /* Referenced by: '<S1398>/2-D Lookup Table2' */
extern CALDATA const volatile float32 ATZX_ZeroXTmInc_Y_kph[16];
                                /* Referenced by: '<S1398>/2-D Lookup Table3' */
extern CALDATA const volatile float32 AVTM_ActPwrBacklash_X_kW[8];/* Referenced by: '<S1454>/Dbnd' */
extern CALDATA const volatile float32 AVTM_MotorMaxDrvTqWT_X_rpm[23];
                                 /* Referenced by: '<S1449>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 AVTM_MotorSpdFiltCoeff_X_rpm[8];
                      /* Referenced by: '<S1440>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 AVTM_VehSpdFiltCoeff_X_kph[8];
                  /* Referenced by: '<S1440>/Lookup_MVTM_VehSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 KCPT_GenMaxTqDecRate_Nmps;/* Referenced by: '<S1117>/Constant18' */
extern CALDATA const volatile float32 KCPT_GenMaxTqIncRate_Nmps;/* Referenced by: '<S1117>/Constant19' */
extern CALDATA const volatile float32 KCPT_MotMaxTqDecRate_Nmps;/* Referenced by: '<S1117>/Constant11' */
extern CALDATA const volatile float32 KCPT_MotMaxTqFiltAchvd_Nm;/* Referenced by:
                                                                 * '<S1117>/KCPT_MotorMaxTqFiltAchvd_Nm'
                                                                 * '<S1117>/KCPT_MotorMaxTqFiltAchvd_Nm1'
                                                                 */
extern CALDATA const volatile float32 KCPT_MotMaxTqIncRate_Nmps;/* Referenced by: '<S1117>/Constant3' */
extern CALDATA const volatile float32 KCPT_MotorDrgMaxTqAllwd_Nm;
                     /* Referenced by: '<S1117>/KCPT_MotorMaxTqFiltAchvd_Nm2' */
extern CALDATA const volatile float32 KCPT_MotorMaxTqFiltCoeff_c;/* Referenced by:
                                                                  * '<S1117>/KCPT_MotorMaxTqFiltCoeff_c'
                                                                  * '<S1117>/KCPT_MotorMaxTqFiltCoeff_c1'
                                                                  */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOffD_rpm;/* Referenced by: '<S1117>/Constant8' */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOffR_rpm;/* Referenced by: '<S1117>/Constant10' */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOnD_rpm;/* Referenced by: '<S1117>/Constant9' */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOnR_rpm;/* Referenced by: '<S1117>/Constant5' */
extern CALDATA const volatile float32 KDAC_ABSActvDlyTm4CC_s;/* Referenced by: '<S1181>/Constant2' */
extern CALDATA const volatile float32 KDAC_ACCDsrdTqIMax_N;
                                      /* Referenced by: '<S1145>/Saturation1' */
extern CALDATA const volatile float32 KDAC_ACCDsrdTqIMin_N;
                                      /* Referenced by: '<S1145>/Saturation1' */
extern CALDATA const volatile float32 KDAC_AccReqStopAllwdSpd_kph;
                        /* Referenced by: '<S1141>/KVTM_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile float32 KDAC_BrkPedPrsdOff_pct;
                           /* Referenced by: '<S1134>/KTQD_BrkPedPstnHi_pct1' */
extern CALDATA const volatile float32 KDAC_BrkPedPrsdOn_pct;
                            /* Referenced by: '<S1134>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile float32 KDAC_BrkTq2PresrCvrtCoeff_c;/* Referenced by:
                                                                   * '<S1447>/Constant18'
                                                                   * '<S1134>/Constant18'
                                                                   * '<S1233>/Constant18'
                                                                   */
extern CALDATA const volatile boolean KDAC_BypCruiseSdnCC_flg;
                        /* Referenced by: '<S1181>/KVTM_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile boolean KDAC_BypCruiseSdn_flg;
                        /* Referenced by: '<S1138>/KVTM_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile boolean KDAC_BypESPTqIntv_flg;
                        /* Referenced by: '<S1138>/KVTM_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile float32 KDAC_CCAccelPedPrsdOff_pct;
                       /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph1' */
extern CALDATA const volatile float32 KDAC_CCAccelPedPrsdOn_pct;
                        /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KDAC_CCDsrdAcceltnMax_mps2;
                                      /* Referenced by: '<S1161>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdAcceltnMin_mps2;
                                      /* Referenced by: '<S1161>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqDecIDlyTm_s;/* Referenced by: '<S1170>/Constant4' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqIMax_N;
                                      /* Referenced by: '<S1168>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqIMin_N;
                                      /* Referenced by: '<S1168>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqIncIDlyTm_s;/* Referenced by: '<S1170>/Constant1' */
extern CALDATA const volatile float32 KDAC_CCHldISpdOverOff_kph;
                       /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph3' */
extern CALDATA const volatile float32 KDAC_CCHldISpdOverOn_kph;
                       /* Referenced by: '<S1170>/KTQD_CstRegenVehSpdOn_kph2' */
extern CALDATA const volatile float32 KDAC_CCMaxSpdOfst_kph;
                                      /* Referenced by: '<S1181>/Constant150' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdE_kph;/* Referenced by: '<S1208>/Constant3' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdN_kph;
                                      /* Referenced by: '<S1208>/Constant164' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdS_kph;/* Referenced by: '<S1208>/Constant4' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdSnow_kph;/* Referenced by: '<S1208>/Constant8' */
extern CALDATA const volatile float32 KDAC_CCMinSpdOfst_kph;
                                      /* Referenced by: '<S1181>/Constant148' */
extern CALDATA const volatile uint8 KDAC_CCMinTgtSpd_kph;/* Referenced by: '<S1208>/Constant9' */
extern CALDATA const volatile float32 KDAC_CCOvrdTqOff_Nm;/* Referenced by: '<S1155>/Constant5' */
extern CALDATA const volatile float32 KDAC_CCOvrdTqOn_Nm;
                                      /* Referenced by: '<S1155>/Constant174' */
extern CALDATA const volatile uint8 KDAC_CCSpdChgLongDiv_cnt;
                         /* Referenced by: '<S1157>/KDAC_CCSpdChgLongDiv_cnt' */
extern CALDATA const volatile uint8 KDAC_CCSpdChgShort_kph;
                           /* Referenced by: '<S1157>/KDAC_CCSpdChgShort_kph' */
extern CALDATA const volatile float32 KDAC_CCTgtSpdChgRate_kphps;
                       /* Referenced by: '<S1157>/KDAC_CCTgtSpdChgRate_kphps' */
extern CALDATA const volatile float32 KDAC_CCTqReqWhlAchvd_Nm;
                              /* Referenced by: '<S1169>/KDAC_TapDwnTmOut_s2' */
extern CALDATA const volatile float32 KDAC_CCTqReqWhlDec_Nmps;
                              /* Referenced by: '<S1169>/KDAC_TapDwnTmOut_s1' */
extern CALDATA const volatile float32 KDAC_CCTqReqWhlInc_Nmps;
                              /* Referenced by: '<S1169>/KDAC_TapDwnTmOut_s3' */
extern CALDATA const volatile uint8 KDAC_CruzSetSwOpCntr_cnt;/* Referenced by: '<S1210>/Constant4' */
extern CALDATA const volatile float32 KDAC_CruzSetSwOpTm_s;
                             /* Referenced by: '<S1158>/KDAC_CruzSetSwOpTm_s' */
extern CALDATA const volatile float32 KDAC_DrvAsstTqSplitEHBMin_Nm;/* Referenced by: '<S1134>/Constant19' */
extern CALDATA const volatile float32 KDAC_ESCIntvDlyTm4CC_s;/* Referenced by: '<S1181>/Constant1' */
extern CALDATA const volatile float32 KDAC_ESPActvDlyTm4CC_s;/* Referenced by: '<S1181>/Constant3' */
extern CALDATA const volatile float32 KDAC_HDCActvSlopOff_pct;/* Referenced by: '<S1229>/Cnst7' */
extern CALDATA const volatile float32 KDAC_HDCActvSlopOn_pct;/* Referenced by: '<S1229>/Cnst5' */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdHiOfst_kph;/* Referenced by: '<S1229>/Cnst10' */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdHi_kph;/* Referenced by:
                                                           * '<S1229>/Cnst2'
                                                           * '<S1229>/Cnst3'
                                                           */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdLoOfst_kph;/* Referenced by: '<S1229>/Cnst11' */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdLo_kph;/* Referenced by:
                                                           * '<S1229>/Cnst4'
                                                           * '<S1229>/Cnst6'
                                                           */
extern CALDATA const volatile float32 KDAC_HDCDsrdTqIMax_N;
                                      /* Referenced by: '<S1234>/Saturation1' */
extern CALDATA const volatile float32 KDAC_HDCDsrdTqIMin_N;
                                      /* Referenced by: '<S1234>/Saturation1' */
extern CALDATA const volatile boolean KDAC_HDCFuncEnbl_flg;/* Referenced by: '<S1229>/Cnst1' */
extern CALDATA const volatile uint8 KDAC_HDCStdbyAllwdSpd_kph;/* Referenced by:
                                                               * '<S1229>/Cnst'
                                                               * '<S1229>/Cnst9'
                                                               */
extern CALDATA const volatile float32 KDAC_HDCTgtAcceltnFiltCoeff_rat;/* Referenced by: '<S1232>/Cnst5' */
extern CALDATA const volatile float32 KDAC_HDCTqReqWhlAchvd_Nm;/* Referenced by:
                                                                * '<S1134>/KDAC_TapDwnTmOut_s2'
                                                                * '<S1233>/KDAC_TapDwnTmOut_s2'
                                                                */
extern CALDATA const volatile float32 KDAC_HDCTqReqWhlDec_Nmps;/* Referenced by:
                                                                * '<S1134>/KDAC_TapDwnTmOut_s1'
                                                                * '<S1233>/KDAC_TapDwnTmOut_s1'
                                                                */
extern CALDATA const volatile float32 KDAC_HDCTqReqWhlInc_Nmps;/* Referenced by:
                                                                * '<S1134>/KDAC_TapDwnTmOut_s3'
                                                                * '<S1233>/KDAC_TapDwnTmOut_s3'
                                                                */
extern CALDATA const volatile boolean KDAC_OPDTqRespFst_flg;/* Referenced by: '<S1134>/Constant15' */
extern CALDATA const volatile boolean KDAC_OPDTqRespSprt_flg;/* Referenced by: '<S1134>/Constant14' */
extern CALDATA const volatile float32 KDAC_SpdOutRngDlyTm4CC_s;
                                      /* Referenced by: '<S1181>/Constant164' */
extern CALDATA const volatile float32 KDAC_SpdStabDlyTm4CC_s;/* Referenced by: '<S1197>/Constant8' */
extern CALDATA const volatile float32 KDAC_SpdUnstabDlyTm4CC_s;/* Referenced by: '<S1197>/Constant4' */
extern CALDATA const volatile float32 KDAC_TCSActvDlyTm4CC_s;/* Referenced by: '<S1181>/Constant4' */
extern CALDATA const volatile float32 KDAC_TapDwnTmOut_s;
                               /* Referenced by: '<S1157>/KDAC_TapDwnTmOut_s' */
extern CALDATA const volatile float32 KDAC_TapUpTmOut_s;
                                /* Referenced by: '<S1157>/KDAC_TapUpTmOut_s' */
extern CALDATA const volatile float32 KDAC_VehResistA_fac;/* Referenced by:
                                                           * '<S1076>/KDAC_TapDwnTmOut_s4'
                                                           * '<S1167>/KDAC_TapDwnTmOut_s3'
                                                           */
extern CALDATA const volatile float32 KDAC_VehResistB_fac;/* Referenced by:
                                                           * '<S1076>/KDAC_TapDwnTmOut_s3'
                                                           * '<S1167>/KDAC_TapDwnTmOut_s2'
                                                           */
extern CALDATA const volatile float32 KDAC_VehResistC_fac;/* Referenced by:
                                                           * '<S1076>/KDAC_TapDwnTmOut_s2'
                                                           * '<S1167>/KDAC_TapDwnTmOut_s1'
                                                           */
extern CALDATA const volatile float32 KDAC_VirtAccelPedPstnOff_pct;/* Referenced by: '<S1134>/Constant7' */
extern CALDATA const volatile float32 KDAC_VirtAccelPedPstnOn_pct;/* Referenced by: '<S1134>/Constant6' */
extern CALDATA const volatile float32 KDAC_WhlSlipDiffSpd4CC_kph;/* Referenced by:
                                                                  * '<S1181>/Constant174'
                                                                  * '<S1181>/Constant6'
                                                                  */
extern CALDATA const volatile float32 KDAC_WhlSlipDiffSpdOfst4CC_kph;/* Referenced by: '<S1181>/Constant5' */
extern CALDATA const volatile float32 KDAC_WhlSlipDlyTm4CC_s;/* Referenced by: '<S1181>/Constant8' */
extern CALDATA const volatile uint16 KDAG_ACCMCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s15' */
extern CALDATA const volatile uint16 KDAG_ACCMHVILActnMsk_enum;
                         /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s2' */

/* 压缩机高压互锁故障动作 */
extern CALDATA const volatile uint16 KDAG_ACCMLostCommActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s38' */

/* ACCM通信丢失级故障动作 */
extern CALDATA const volatile uint16 KDAG_ACChrgStFailActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s24' */

/* ACChargeStateFail故障动作 */
extern CALDATA const volatile float32 KDAG_ACChrgStFailFailTm_s;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s20' */

/* ACChargeStateFail故障确认时间 */
extern CALDATA const volatile uint16 KDAG_ACDchaBMSPwrLoActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s21' */

/* AC放电BMS功率低故障动作 */
extern CALDATA const volatile float32 KDAG_ACDchaBMSPwrLoFailTm_s;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s19' */

/* AC放电BMS功率低确认时间 */
extern CALDATA const volatile float32 KDAG_ACDchaBMSPwrLo_A;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s18' */

/* AC放电BMS功率低电流能力门槛 */
extern CALDATA const volatile uint16 KDAG_ACDchaBMSSOCLoActnMsk_enum;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s9' */

/* AC放电BMSSOC低故障动作 */
extern CALDATA const volatile float32 KDAG_ACDchaBMSSOCLoFailTm_s;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s10' */

/* AC放电BMSSOC低确认时间 */
extern CALDATA const volatile float32 KDAG_ACDchaBMSSOCLo_pct;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s16' */

/* AC放电BMSSOC低触发门槛 */
extern CALDATA const volatile uint16 KDAG_ACDchaOverPwrActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s23' */

/* AC放电功率超限故障动作 */
extern CALDATA const volatile float32 KDAG_ACDchaOverPwrFailTm_s;/* Referenced by:
                                                                  * '<S374>/KDAG_BMSCmdTmOutFailTm_s22'
                                                                  * '<S375>/KDAG_BMSCmdTmOutFailTm_s22'
                                                                  */

/* AC放电功率超限确认时间 */
extern CALDATA const volatile uint16 KDAG_ACSCmdTmOutActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s25' */

/* ACSCmd超时故障动作 */
extern CALDATA const volatile float32 KDAG_ACSCmdTmOutFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s24' */

/* ACSCmd超时故障确认时间 */
extern CALDATA const volatile float32 KDAG_AccPed1VoltMax_mV;/* Referenced by:
                                                              * '<S513>/Constant76'
                                                              * '<S878>/Constant4'
                                                              */

/* 加速踏板1路电压过高门槛 */
extern CALDATA const volatile float32 KDAG_AccPed1VoltMin_mV;/* Referenced by:
                                                              * '<S513>/Constant75'
                                                              * '<S878>/Constant3'
                                                              */

/* 加速踏板1路电压过低门槛 */
extern CALDATA const volatile float32 KDAG_AccPed2VoltMax_mV;/* Referenced by:
                                                              * '<S513>/Constant78'
                                                              * '<S878>/Constant5'
                                                              */

/* 加速踏板2路电压过高门槛 */
extern CALDATA const volatile float32 KDAG_AccPed2VoltMin_mV;/* Referenced by:
                                                              * '<S513>/Constant77'
                                                              * '<S878>/Constant6'
                                                              */

/* 加速踏板2路电压过低门槛 */
extern CALDATA const volatile uint16 KDAG_AccPedBothFailActnMsk_enum;
                        /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s23' */

/* 加速踏板双路失效故障动作 */
extern CALDATA const volatile uint16 KDAG_AccPedCrsChkActnMsk_enum;
                        /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s21' */

/* 加速踏板双路校验故障动作 */
extern CALDATA const volatile float32 KDAG_AccPedCrsChkFailTm_s;
                        /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s20' */

/* 加速踏板双路校验偏差确认时间 */
extern CALDATA const volatile float32 KDAG_AccPedCrsChkThr_pct;/* Referenced by: '<S514>/Constant81' */

/* 加速踏板双路校验偏差门槛 */
extern CALDATA const volatile uint16 KDAG_AccPedShtCircActnMsk_enum;/* Referenced by:
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s11'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s15'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s17'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s19'
                                                                     * '<S513>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                     */

/* 加速踏板短路故障动作 */
extern CALDATA const volatile float32 KDAG_AccPedShtCircFailTm_s;/* Referenced by:
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s12'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s13'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s14'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s16'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s18'
                                                                  * '<S513>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                  */

/* 加速踏板短路确认时间 */
extern CALDATA const volatile float32 KDAG_AccPedSuplyVoltMax_mV;/* Referenced by:
                                                                  * '<S513>/Constant36'
                                                                  * '<S513>/Constant72'
                                                                  * '<S878>/Constant2'
                                                                  * '<S878>/Constant7'
                                                                  */

/* 加速踏板供电过高电压门槛 */
extern CALDATA const volatile float32 KDAG_AccPedSuplyVoltMin_mV;/* Referenced by:
                                                                  * '<S513>/Constant34'
                                                                  * '<S513>/Constant48'
                                                                  * '<S878>/Constant1'
                                                                  * '<S878>/Constant8'
                                                                  */

/* 加速踏板供电过低电压门槛 */
extern CALDATA const volatile uint16 KDAG_BACBusOffActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s11' */
extern CALDATA const volatile uint16 KDAG_BMSCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s30' */
extern CALDATA const volatile uint16 KDAG_BMSCmdTmOutActnMsk_enum;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s2' */

/* BMS继电器指令响应超时故障动作 */
extern CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm1_s;
                          /* Referenced by: '<S102>/KDAG_BMSCmdTmOutFailTm_s' */

/* BMS继电器指令响应超时确认时间_非直流充电闭合等待时间 */
extern CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm2_s;
                         /* Referenced by: '<S102>/KDAG_BMSCmdTmOutFailTm_s1' */

/* BMS继电器指令响应超时确认时间_直流充电闭合等待时间 */
extern CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm3_s;
                         /* Referenced by: '<S102>/KDAG_BMSCmdTmOutFailTm_s2' */

/* BMS继电器指令响应超时确认时间_BMS自己断开继电器等待时间 */
extern CALDATA const volatile uint16 KDAG_BMSEmgcySdnActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s11' */

/* BMS紧急下电故障动作 */
extern CALDATA const volatile float32 KDAG_BMSEmgcySdnFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s12' */

/* BMS紧急下电故障确认时间 */
extern CALDATA const volatile uint16 KDAG_BMSLostCommActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s4' */
extern CALDATA const volatile uint16 KDAG_BMSSOCLoActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s10' */

/* BMSSOC低故障动作 */
extern CALDATA const volatile float32 KDAG_BMSSOCLoFailTm_s;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s9' */

/* BMSSOC低故障确认时间 */
extern CALDATA const volatile float32 KDAG_BMSSysFailFailTm_s;/* Referenced by:
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s5'
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s7'
                                                               */

/* BMSFail故障确认时间 */
extern CALDATA const volatile uint16 KDAG_BMSSysFailLvl2ActnMsk_enum;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s6' */

/* BMSFailLevel2故障动作 */
extern CALDATA const volatile uint16 KDAG_BMSSysFailLvl3ActnMsk_enum;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s8' */

/* BMSFailLevel3故障动作 */
extern CALDATA const volatile uint16 KDAG_BMSUndrVoltActnMsk1_enum;
                        /* Referenced by: '<S104>/KDAG_BMSCmdTmOutFailTm_s13' */

/* BMSPack欠压故障动作_升级前 */
extern CALDATA const volatile uint16 KDAG_BMSUndrVoltActnMsk2_enum;
                        /* Referenced by: '<S104>/KDAG_BMSCmdTmOutFailTm_s15' */

/* BMSPack欠压故障动作_升级后 */
extern CALDATA const volatile float32 KDAG_BMSUndrVoltFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s14' */

/* BMSPack欠压故障确认时间 */
extern CALDATA const volatile uint16 KDAG_BODBusOffActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s2' */
extern CALDATA const volatile float32 KDAG_BrkPedVoltMax_mV;/* Referenced by: '<S544>/Constant1' */

/* 制动踏板电压过高门槛 */
extern CALDATA const volatile float32 KDAG_BrkPedVoltMin_mV;/* Referenced by: '<S544>/Constant48' */

/* 制动踏板电压过低门槛 */
extern CALDATA const volatile uint16 KDAG_BrkSwCrsChkActnMsk_enum;
                        /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s23' */

/* 制动开关双路校验故障动作 */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntDec_cnt;/* Referenced by: '<S545>/Constant11' */

/* 制动开关双路校验计数减少步长 */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntHi_cnt;/* Referenced by: '<S545>/Constant1' */

/* 制动开关双路校验计数High_高于此值判定有故障 */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntInc_cnt;/* Referenced by: '<S545>/Constant10' */

/* 制动开关双路校验计数增加步长 */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntLo_cnt;/* Referenced by: '<S545>/Constant3' */

/* 制动开关双路校验计数Low_低于此值判定无故障 */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntMax_cnt;/* Referenced by: '<S545>/Constant12' */

/* 制动开关双路校验计数Max */
extern CALDATA const volatile float32 KDAG_BrkSwCrsChkIntvlTm_s;/* Referenced by: '<S545>/Constant5' */

/* 两次制动开关校验至少需要间隔的时间 */
extern CALDATA const volatile float32 KDAG_BrkSwDisagreeTmHi_s;/* Referenced by: '<S545>/Constant4' */

/* 制动开关不一致时间High_高于此值表示此次校验不通过 */
extern CALDATA const volatile float32 KDAG_BrkSwDisagreeTmLo_s;/* Referenced by: '<S545>/Constant2' */

/* 制动开关不一致时间Low_低于此值表示此次校验通过 */
extern CALDATA const volatile float32 KDAG_BrkSwDisagreeTmLong_s;/* Referenced by: '<S545>/Constant6' */

/* 制动开关不一致时间Long_高于此值直接报校验故障 */
extern CALDATA const volatile uint16 KDAG_CCPCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s13' */
extern CALDATA const volatile uint16 KDAG_CHABusOffActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s3' */
extern CALDATA const volatile uint16 KDAG_CRRRCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s21' */
extern CALDATA const volatile uint16 KDAG_CellUndrVoltActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s13' */

/* BMSCell欠压故障动作 */
extern CALDATA const volatile float32 KDAG_CellUndrVoltFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s15' */

/* BMSCell欠压故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCCCmdTmOutActnMsk1_enum;
                        /* Referenced by: '<S285>/KDAG_BMSCmdTmOutFailTm_s13' */

/* DCDC模式指令响应超时故障动作_升级前 */
extern CALDATA const volatile uint16 KDAG_DCCCmdTmOutActnMsk2_enum;
                        /* Referenced by: '<S285>/KDAG_BMSCmdTmOutFailTm_s15' */

/* DCDC模式指令响应超时故障动作_升级后 */
extern CALDATA const volatile float32 KDAG_DCCCmdTmOutFailTm_s;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s14' */

/* DCDC模式指令响应超时故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCCInVoltLoActnMsk_enum;
                         /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDC输入电压低故障动作 */
extern CALDATA const volatile float32 KDAG_DCCInVoltLoFailTm_s;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s13' */

/* DCDC输入电压低故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCCModeFltActnMsk1_enum;
                         /* Referenced by: '<S287>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDCModeFault故障动作_升级前 */
extern CALDATA const volatile uint16 KDAG_DCCModeFltActnMsk2_enum;
                        /* Referenced by: '<S287>/KDAG_BMSCmdTmOutFailTm_s11' */

/* DCDCModeFault故障动作_升级后 */
extern CALDATA const volatile float32 KDAG_DCCModeFltFailTm_s;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s12' */

/* DCDCModeFault故障确认时间 */
extern CALDATA const volatile float32 KDAG_DCCSysFailFailTm_s;/* Referenced by:
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s5'
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s7'
                                                               * '<S278>/KDAG_BMSCmdTmOutFailTm_s9'
                                                               */

/* DCDCFail故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCCSysFailLvl3ActnMsk1_enum;
                         /* Referenced by: '<S286>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDCFaillevel3故障动作_升级前 */
extern CALDATA const volatile uint16 KDAG_DCCSysFailLvl3ActnMsk2_enum;
                         /* Referenced by: '<S286>/KDAG_BMSCmdTmOutFailTm_s8' */

/* DCDCFaillevel3故障动作_升级后 */
extern CALDATA const volatile float32 KDAG_DCCSysFailLvl3FailTm_s;
                         /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s6' */

/* DCDCFaillevel3故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCCSysFailLvl4ActnMsk_enum;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s10' */

/* DCDCFaillevel4故障动作 */
extern CALDATA const volatile uint16 KDAG_DCSChrgReqActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s21' */

/* DCSChargeRequest故障动作 */
extern CALDATA const volatile float32 KDAG_DCSChrgReqFailTm_s;/* Referenced by:
                                                               * '<S100>/KDAG_BMSCmdTmOutFailTm_s20'
                                                               * '<S770>/Constant5'
                                                               */

/* DCSChargeRequest故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCSCmdTmOutActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s27' */

/* DCSCmd超时故障动作 */
extern CALDATA const volatile float32 KDAG_DCSCmdTmOutFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s17' */

/* DCSCmd超时故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCSFailStaActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s28' */

/* DCSFailState故障动作 */
extern CALDATA const volatile float32 KDAG_DCSFailStaFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s16' */

/* DCSFailState故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCSInletConnectActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s19' */

/* DCS插枪状态故障动作 */
extern CALDATA const volatile float32 KDAG_DCSInletConnectFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s18' */

/* DCS插枪状态故障确认时间 */
extern CALDATA const volatile uint16 KDAG_DCSModeFailActnMsk_enum;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s23' */

/* DCSModeFail故障动作 */
extern CALDATA const volatile float32 KDAG_DCSModeFailFailTm_s;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s22' */

/* DCSModeFail故障确认时间 */
extern CALDATA const volatile uint8 KDAG_Did0xF163WrtData_cnt[4];/* Referenced by: '<S99>/DidData3' */

/* CCU_FlashDriver软件 */
extern CALDATA const volatile uint8 KDAG_Did0xF180WrtData_cnt[4];/* Referenced by: '<S99>/DidData2' */

/* CCU_Boot软件 */
extern CALDATA const volatile uint8 KDAG_Did0xF187WrtData_cnt[2];/* Referenced by: '<S99>/DidData' */

/* 总成号 */
extern CALDATA const volatile uint8 KDAG_Did0xF188WrtData_cnt[4];/* Referenced by: '<S99>/DidData4' */

/* CCU_App软件 */
extern CALDATA const volatile uint8 KDAG_Did0xF191WrtData_cnt[4];/* Referenced by: '<S99>/DidData1' */

/* CCU硬件 */
extern CALDATA const volatile uint16 KDAG_EHBCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s34' */
extern CALDATA const volatile float32 KDAG_EHBFltFailTm_s;/* Referenced by:
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s17'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s4'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s5'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s7'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s9'
                                                           */

/* EHB故障确认时间 */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl2ActnMsk_enum;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s6' */

/* EHB2级故障动作 */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl3ActnMsk_enum;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s8' */

/* EHB3级故障动作 */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl4ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s18' */

/* EHB4级故障动作 */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl5ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s10' */

/* EHB5级故障动作 */
extern CALDATA const volatile uint16 KDAG_EHBLostCommActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s7' */
extern CALDATA const volatile uint16 KDAG_EPTBusOffActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s1' */
extern CALDATA const volatile uint16 KDAG_ESCCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s35' */
extern CALDATA const volatile float32 KDAG_ESCFltFailTm_s;/* Referenced by:
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s14'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s19'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s20'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s22'
                                                           * '<S436>/KDAG_BMSCmdTmOutFailTm_s24'
                                                           */

/* ESC故障确认时间 */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl2ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s21' */

/* ESC2级故障动作 */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl3ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s23' */

/* ESC3级故障动作 */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl4ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s15' */

/* ESC4级故障动作 */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl5ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s12' */

/* ESC5级故障动作 */
extern CALDATA const volatile uint16 KDAG_ESCLostCommActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s5' */
extern CALDATA const volatile uint16 KDAG_ESCVehSpdInvldActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s13' */

/* 车速失效故障动作 */
extern CALDATA const volatile float32 KDAG_ESCVehSpdInvldFailTm_s;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s3' */

/* 车速失效确认时间 */
extern CALDATA const volatile boolean KDAG_EmgcyShtdwnOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg9' */
extern CALDATA const volatile boolean KDAG_EmgcyShtdwnOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg9' */
extern CALDATA const volatile uint16 KDAG_FCMCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s24' */
extern CALDATA const volatile uint16 KDAG_FCMLostCommActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s37' */

/* FCM通信丢失级故障动作 */
extern CALDATA const volatile boolean KDAG_FanFullSpdOnOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg17' */
extern CALDATA const volatile boolean KDAG_FanFullSpdOnOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg17' */
extern CALDATA const volatile boolean KDAG_FbdACCOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg7' */
extern CALDATA const volatile boolean KDAG_FbdACCOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg7' */
extern CALDATA const volatile boolean KDAG_FbdACChrgOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg11' */
extern CALDATA const volatile boolean KDAG_FbdACChrgOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg11' */
extern CALDATA const volatile boolean KDAG_FbdACDchaOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg13' */
extern CALDATA const volatile boolean KDAG_FbdACDchaOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg13' */
extern CALDATA const volatile boolean KDAG_FbdACOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg14' */
extern CALDATA const volatile boolean KDAG_FbdACOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg14' */
extern CALDATA const volatile boolean KDAG_FbdCCOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile boolean KDAG_FbdCCOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg5' */
extern CALDATA const volatile boolean KDAG_FbdDCChrgOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg12' */
extern CALDATA const volatile boolean KDAG_FbdDCChrgOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg12' */
extern CALDATA const volatile boolean KDAG_FbdDCDCOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg10' */
extern CALDATA const volatile boolean KDAG_FbdDCDCOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg10' */
extern CALDATA const volatile boolean KDAG_FbdDRGrOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile boolean KDAG_FbdDRGrOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg4' */
extern CALDATA const volatile boolean KDAG_FbdDrvTqOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile boolean KDAG_FbdDrvTqOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile boolean KDAG_FbdHVOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg8' */
extern CALDATA const volatile boolean KDAG_FbdHVOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg8' */
extern CALDATA const volatile boolean KDAG_FbdLSPOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg6' */
extern CALDATA const volatile boolean KDAG_FbdLSPOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg6' */
extern CALDATA const volatile boolean KDAG_FltLampOnOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg15' */
extern CALDATA const volatile boolean KDAG_FltLampOnOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg15' */
extern CALDATA const volatile uint16 KDAG_FrstHVILVoltChkActnMsk1_enum;/* Referenced by:
                                                                      * '<S561>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                      * '<S562>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                      */

/* 主要高压互锁故障动作1 */
extern CALDATA const volatile uint16 KDAG_FrstHVILVoltChkActnMsk2_enum;/* Referenced by:
                                                                      * '<S561>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      * '<S562>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      */

/* 主要高压互锁故障动作2 */
extern CALDATA const volatile float32 KDAG_FrstHVILVoltMax_mV;/* Referenced by: '<S561>/Constant75' */

/* 主要高压互锁电压过高门槛 */
extern CALDATA const volatile float32 KDAG_FrstHVILVoltMin_mV;/* Referenced by: '<S562>/Constant75' */

/* 主要高压互锁电压过低门槛 */
extern CALDATA const volatile float32 KDAG_GearShftInvldFailTm1_s;
                          /* Referenced by: '<S476>/KDAG_BMSCmdTmOutFailTm_s' */

/* 换挡输入失效故障确认时间1 */
extern CALDATA const volatile float32 KDAG_GearShftInvldFailTm2_s;
                         /* Referenced by: '<S476>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 换挡输入失效故障确认时间2 */
extern CALDATA const volatile float32 KDAG_HVAccAcptBMSVoltFac_c;/* Referenced by:
                                                                  * '<S278>/KDAG_BMSCmdTmOutFailTm_s19'
                                                                  * '<S278>/KDAG_BMSCmdTmOutFailTm_s2'
                                                                  * '<S752>/Constant1'
                                                                  */

/* 高压部件电压与电池电压比值的可接受比例系数 */
extern CALDATA const volatile float32 KDAG_HVILVoltChkFailTm_s;/* Referenced by:
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s10'
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s3'
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                * '<S544>/KDAG_BMSCmdTmOutFailTm_s9'
                                                                */

/* 高压互锁故障确认时间 */
extern CALDATA const volatile uint16 KDAG_HVIsoResistLoActnMsk_enum;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 高压电池绝缘故障动作 */
extern CALDATA const volatile float32 KDAG_HVIsoResistLoFailTm_s;
                          /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s' */

/* 高压电池绝缘故障阻值低确认时间 */
extern CALDATA const volatile float32 KDAG_HVIsoResistLoPassTm_s;
                         /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s3' */

/* 高压电池绝缘故障阻值低恢复时间 */
extern CALDATA const volatile float32 KDAG_HVIsoResistLoThr_kOhm;
                        /* Referenced by: '<S100>/KDAG_BMSCmdTmOutFailTm_s26' */

/* 高压电池绝缘故障阻值门槛 */
extern CALDATA const volatile uint16 KDAG_INVCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s32' */
extern CALDATA const volatile float32 KDAG_INVFltFailTm_s;/* Referenced by:
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s4'
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s5'
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s7'
                                                           * '<S350>/KDAG_BMSCmdTmOutFailTm_s9'
                                                           */

/* INVFault故障确认时间 */
extern CALDATA const volatile uint16 KDAG_INVFltLvl2ActnMsk_enum;
                         /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s6' */

/* INVFaultLevel2故障动作 */
extern CALDATA const volatile uint16 KDAG_INVFltLvl3ActnMsk_enum;
                         /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s8' */

/* INVFaultLevel3故障动作 */
extern CALDATA const volatile uint16 KDAG_INVFltLvl4ActnMsk_enum;
                        /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s10' */

/* INVFaultLevel4故障动作 */
extern CALDATA const volatile uint16 KDAG_INVInVoltLoActnMsk_enum;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s17' */

/* INV输入电压低故障动作 */
extern CALDATA const volatile float32 KDAG_INVInVoltLoFailTm_s;
                        /* Referenced by: '<S278>/KDAG_BMSCmdTmOutFailTm_s18' */

/* INV输入电压低故障确认时间 */
extern CALDATA const volatile uint16 KDAG_INVLostCommActnMsk_enum;
                         /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s6' */
extern CALDATA const volatile uint16 KDAG_INVRunCmdRespActnMsk_enum;
                        /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s11' */

/* INVRun指令响应超时故障动作 */
extern CALDATA const volatile float32 KDAG_INVRunCmdRespFailTm_s;
                        /* Referenced by: '<S350>/KDAG_BMSCmdTmOutFailTm_s12' */

/* INVRun指令响应超时故障确认时间 */
extern CALDATA const volatile uint16 KDAG_IPUCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s36' */
extern CALDATA const volatile uint16 KDAG_IPULostCommActnMsk1_enum;
                         /* Referenced by: '<S238>/KDAG_BMSCmdTmOutFailTm_s1' */
extern CALDATA const volatile uint16 KDAG_IPULostCommActnMsk2_enum;
                         /* Referenced by: '<S238>/KDAG_BMSCmdTmOutFailTm_s9' */
extern CALDATA const volatile boolean KDAG_LVBatLampOnOvrdSw_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg16' */
extern CALDATA const volatile boolean KDAG_LVBatLampOnOvrdVal_flg;
                         /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg16' */
extern CALDATA const volatile float32 KDAG_LVBatVoltHiRec_V;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s5' */

/* 蓄电池过压恢复门槛 */
extern CALDATA const volatile float32 KDAG_LVBatVoltHi_V;/* Referenced by:
                                                          * '<S497>/KDAG_BMSCmdTmOutFailTm_s8'
                                                          * '<S544>/KDAG_BMSCmdTmOutFailTm_s8'
                                                          */

/* 蓄电池过压触发门槛 */
extern CALDATA const volatile float32 KDAG_LVBatVoltLoRec_V;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s4' */

/* 蓄电池欠压恢复门槛 */
extern CALDATA const volatile float32 KDAG_LVBatVoltLo_V;/* Referenced by:
                                                          * '<S497>/KDAG_BMSCmdTmOutFailTm_s7'
                                                          * '<S544>/KDAG_BMSCmdTmOutFailTm_s7'
                                                          */

/* 蓄电池欠压触发门槛 */
extern CALDATA const volatile float32 KDAG_LVBatVoltPassbl_V;
                        /* Referenced by: '<S506>/KDAG_BMSCmdTmOutFailTm_s15' */

/* 蓄电池电压尚可门槛 */
extern CALDATA const volatile float32 KDAG_LVBattSOCLoFailTm_s;
                        /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s18' */

/* 蓄电池SOC低确认时间 */
extern CALDATA const volatile uint8 KDAG_LVBattSOCLo_pct;/* Referenced by: '<S497>/Constant77' */

/* 蓄电池SOC低门槛 */
extern CALDATA const volatile float32 KDAG_LVBattSOHLoFailTm_s;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 蓄电池SOH低确认时间 */
extern CALDATA const volatile uint8 KDAG_LVBattSOHLo_pct;/* Referenced by: '<S497>/Constant78' */

/* 蓄电池SOH低门槛 */
extern CALDATA const volatile uint16 KDAG_LVBattTempHiActnMsk1_enum;
                        /* Referenced by: '<S506>/KDAG_BMSCmdTmOutFailTm_s13' */

/* 蓄电池过温故障动作_升级前 */
extern CALDATA const volatile uint16 KDAG_LVBattTempHiActnMsk2_enum;
                         /* Referenced by: '<S506>/KDAG_BMSCmdTmOutFailTm_s1' */

/* 蓄电池过温故障动作_升级后 */
extern CALDATA const volatile float32 KDAG_LVBattTempHiFailTm_s;
                         /* Referenced by: '<S497>/KDAG_BMSCmdTmOutFailTm_s2' */

/* 蓄电池过温确认时间 */
extern CALDATA const volatile float32 KDAG_LVBattTempHi_C;/* Referenced by: '<S506>/Constant40' */

/* 蓄电池过温温度门槛 */
extern CALDATA const volatile float32 KDAG_LVBattVoltExcdFailTm_s;/* Referenced by:
                                                                   * '<S497>/KDAG_BMSCmdTmOutFailTm_s3'
                                                                   * '<S497>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                   */

/* 蓄电池欠压过压确认时间 */
extern CALDATA const volatile boolean KDAG_LimpHomeOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile boolean KDAG_LimpHomeOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg1' */
extern CALDATA const volatile boolean KDAG_LmtDrvTqOvrdSw_flg;
                           /* Referenced by: '<S90>/KDAG_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile boolean KDAG_LmtDrvTqOvrdVal_flg;
                          /* Referenced by: '<S90>/KDAG_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile uint8 KDAG_ManlClrDTCReq_enum;
                         /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph1' */

/* 手动清除所有故障的标定_从0改成255时触发起一次作用 */
extern CALDATA const volatile uint16 KDAG_OBCChrgReqActnMsk_enum;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s7' */

/* OBCChargeRequest故障动作 */
extern CALDATA const volatile float32 KDAG_OBCChrgReqFailTm_s;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s8' */

/* OBCChargeRequest故障确认时间 */
extern CALDATA const volatile uint16 KDAG_OBCConnectTmOutActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s25' */

/* OBC连接超时故障动作 */
extern CALDATA const volatile float32 KDAG_OBCConnectTmOutFailTm1_s;
                          /* Referenced by: '<S409>/KDAG_BMSCmdTmOutFailTm_s' */

/* OBC连接超时故障等待时间_连接前 */
extern CALDATA const volatile float32 KDAG_OBCConnectTmOutFailTm2_s;
                         /* Referenced by: '<S409>/KDAG_BMSCmdTmOutFailTm_s1' */

/* OBC连接超时故障等待时间_连接后断开 */
extern CALDATA const volatile uint16 KDAG_OBCInletConnectActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s11' */

/* OBC插枪状态故障动作 */
extern CALDATA const volatile float32 KDAG_OBCInletConnectFailTm_s;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s12' */

/* OBC插枪状态故障确认时间 */
extern CALDATA const volatile uint16 KDAG_OBCModeMsmtchActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s27' */

/* OBC模式不匹配故障动作 */
extern CALDATA const volatile float32 KDAG_OBCModeMsmtchFailTm_s;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s26' */

/* OBC模式不匹配故障确认时间 */
extern CALDATA const volatile uint16 KDAG_OBCS2StatActnMsk_enum;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s5' */

/* OBCS2连接超时故障动作 */
extern CALDATA const volatile float32 KDAG_OBCS2StatFailTm_s;
                         /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s6' */

/* OBCS2连接超时故障确认时间 */
extern CALDATA const volatile float32 KDAG_OBCSysFailFailTm_s;/* Referenced by:
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s14'
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s15'
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s17'
                                                               * '<S374>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               */

/* OBCFail故障确认时间 */
extern CALDATA const volatile uint16 KDAG_OBCSysFailLvl4ActnMsk_enum;
                        /* Referenced by: '<S374>/KDAG_BMSCmdTmOutFailTm_s13' */

/* OBCFailLevel4故障动作 */
extern CALDATA const volatile uint16 KDAG_SCSCRCFltActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s19' */
extern CALDATA const volatile uint16 KDAG_SCSLostCommActnMsk_enum;
                        /* Referenced by: '<S164>/KDAG_BMSCmdTmOutFailTm_s39' */

/* SCS通信丢失级故障动作 */
extern CALDATA const volatile uint16 KDAG_SecdHVILVoltHiActnMsk_enum;
                        /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s11' */

/* 次要高压互锁电压高故障动作 */
extern CALDATA const volatile uint16 KDAG_SecdHVILVoltLoActnMsk_enum;
                         /* Referenced by: '<S544>/KDAG_BMSCmdTmOutFailTm_s4' */

/* 次要高压互锁电压低故障动作 */
extern CALDATA const volatile float32 KDAG_SecdHVILVoltMax_mV;/* Referenced by: '<S544>/Constant2' */

/* 次要高压互锁电压过高门槛 */
extern CALDATA const volatile float32 KDAG_SecdHVILVoltMin_mV;/* Referenced by: '<S544>/Constant75' */

/* 次要高压互锁电压过低门槛 */
extern CALDATA const volatile float32 KDAG_SysPwrModeInvldFailTm_s;
                         /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s1' */

/* PowerMode失效确认时间 */
extern CALDATA const volatile uint16 KDAG_TMSFailLvl3ActnMsk_enum;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s11' */

/* TMSRFailLevel3故障动作 */
extern CALDATA const volatile float32 KDAG_TMSFailLvl3FailTm_s;
                        /* Referenced by: '<S436>/KDAG_BMSCmdTmOutFailTm_s16' */

/* TMSRFailLevel3故障确认时间 */
extern CALDATA const volatile uint16 KDAG_VehCrashActnMsk_enum;
                         /* Referenced by: '<S513>/KDAG_BMSCmdTmOutFailTm_s2' */

/* 碰撞故障动作 */
extern CALDATA const volatile float32 KDAG_VehSpdLo_kph;/* Referenced by: '<S89>/Constant2' */

/* 低车速门槛，用于故障升级 */
extern CALDATA const volatile boolean KDAG_VehStandStillBypasBrk_flg;
                         /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph2' */

/* 驻车清除故障不看刹车的标定量_建议标成1不用看刹车_满足停车和PN挡即可 */
extern CALDATA const volatile float32 KDAG_VehStandStillSpd_kph;
                          /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph' */

/* 驻车清除故障的车速门槛_需基本绝对停止 */
extern CALDATA const volatile float32 KDAG_WakeUpDlyTm_s;
                         /* Referenced by: '<S89>/KDAG_VehStandStillSpd_kph3' */

/* 唤醒源拉高的信号延迟时间_即诊断开始的延迟时间 */
extern CALDATA const volatile uint32 KDAG_WaterTempAbvThr_Ohm;/* Referenced by: '<S578>/Constant1' */

/* 冷却水温过高的电阻门槛 */
extern CALDATA const volatile uint32 KDAG_WaterTempBlwThr_Ohm;/* Referenced by: '<S578>/Constant75' */

/* 冷却水温过低的电阻门槛 */
extern CALDATA const volatile float32 KDAG_WaterTempExcdThrFailTm_s;/* Referenced by:
                                                                     * '<S578>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                     * '<S578>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                     */

/* 冷却水温异常的确认时间 */
extern CALDATA const volatile float32 KDSA_AcceltnIdxAvgInit_pct;/* Referenced by: '<S17>/Unit Delay2' */
extern CALDATA const volatile float32 KDSA_AcceltnIdxDecRate_pctps;
                      /* Referenced by: '<S17>/KVTM_AcceltnIdxIncRate_pctps1' */
extern CALDATA const volatile float32 KDSA_AcceltnIdxIncRate_pctps;
                       /* Referenced by: '<S17>/KVTM_AcceltnIdxIncRate_pctps' */
extern CALDATA const volatile float32 KDSA_BrkPedPstnAvgInit_pct;/* Referenced by: '<S17>/Unit Delay4' */
extern CALDATA const volatile float32 KDSA_BrkPedPstnDecRate_pctps;
                       /* Referenced by: '<S17>/KVTM_BrkPedPstnDecRate_pctps' */
extern CALDATA const volatile float32 KDSA_BrkPedPstnIncRate_pctps;
                       /* Referenced by: '<S17>/KVTM_BrkPedPstnIncRate_pctps' */
extern CALDATA const volatile float32 KDSA_DrvSprtIdxMax_pct;/* Referenced by: '<S17>/Saturation2' */
extern CALDATA const volatile float32 KDSA_DrvSprtIdxMin_pct;/* Referenced by: '<S17>/Saturation2' */
extern CALDATA const volatile float32 KDSA_SprtIdxBrkPedRstSpd_kph;
                         /* Referenced by: '<S17>/KVTM_SDSHldVehSpd4Brk_kph1' */
extern CALDATA const volatile float32 KDSA_SprtIdxBrkPedRstTm_s;
                          /* Referenced by: '<S17>/KVTM_AccelPedRlsdDlyTm_s1' */
extern CALDATA const volatile float32 KDSA_SprtIdxBrkPedRstVal_pct;
                          /* Referenced by: '<S17>/KVTM_AccelPedRlsdDlyTm_s2' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldAccPed4Acc_pct;
                         /* Referenced by: '<S17>/KVTM_SDSHoldAccPedPstn_pct' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldAccPed4Brk_pct;
                          /* Referenced by: '<S17>/KVTM_SDSHldAccPed4Brk_pct' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldAccPedRlsDlyTm4Brk_s;
                           /* Referenced by: '<S17>/KVTM_AccelPedRlsdDlyTm_s' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldAcceltn4Acc_mps2;
                             /* Referenced by: '<S17>/KVTM_SDSHldDchaPwr_kW2' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldDchaPwr_kW;
                              /* Referenced by: '<S17>/KVTM_SDSHldDchaPwr_kW' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldVehSpd4Acc_kph;
                             /* Referenced by: '<S17>/KVTM_SDSHldDchaPwr_kW1' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldVehSpd4Brk_kph;
                          /* Referenced by: '<S17>/KVTM_SDSHldVehSpd4Brk_kph' */
extern CALDATA const volatile float32 KDSA_SprtIdxHldWhlTq4Acc_Nm;
                               /* Referenced by: '<S17>/KVTM_SDSHoldWhlTq_Nm' */
extern CALDATA const volatile boolean KDSA_UseTqCalcAcceltn_flg;
                          /* Referenced by: '<S17>/KVTM_UseTqCalcAcceltn_flg' */
extern CALDATA const volatile float32 KEMS_AccPwrDecFiltCoeff_c;
                           /* Referenced by: '<S28>/KVTM_LimpHomeOvrdSw_flg3' */

/* 放电附件功率滤波系数（只滤下降） */
extern CALDATA const volatile float32 KEMS_AccPwrIncFiltCoeff_c;
                           /* Referenced by: '<S26>/KVTM_LimpHomeOvrdSw_flg4' */

/* 充电附件功率滤波系数（只滤上降） */
extern CALDATA const volatile float32 KEMS_CellTempSynDecRate_Cps;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg6' */

/* 电芯温度下降斜率 */
extern CALDATA const volatile float32 KEMS_CellTempSynIncRate_Cps;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg7' */

/* 电芯温度上升斜率 */
extern CALDATA const volatile float32 KEMS_ChrgCurFbKiMax_A;/* Referenced by: '<S81>/Saturation' */

/* 充电KI上限限制 */
extern CALDATA const volatile float32 KEMS_ChrgCurFbKiMin_A;/* Referenced by: '<S81>/Saturation' */

/* 充电KI下限限制 */
extern CALDATA const volatile float32 KEMS_ChrgCurFbMax_A;/* Referenced by: '<S81>/Saturation2' */

/* 充电KP+KI上限限制 */
extern CALDATA const volatile float32 KEMS_ChrgCurFbMin_A;/* Referenced by: '<S81>/Saturation2' */

/* 充电KP+KI下限限制 */
extern CALDATA const volatile float32 KEMS_ChrgFbActvDlyTm_s;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg2' */

/* 充电功率闭环退出延迟时间 */
extern CALDATA const volatile float32 KEMS_ChrgPwr2MotRawFiltCoeff_c;
                           /* Referenced by: '<S26>/KVTM_LimpHomeOvrdSw_flg5' */

/* 充电总功率滤波系数（只滤下降） */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbFiltCoeff_c;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg3' */

/* 充电功率闭环滤波系数 */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbKiMax_kW;/* Referenced by: '<S46>/Saturation' */

/* 充电功率闭环KI上限限制 */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbKiMin_kW;/* Referenced by: '<S46>/Saturation' */

/* 充电功率闭环KI下限限制 */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbMax_kW;/* Referenced by: '<S46>/Saturation2' */

/* 充电功率闭环KI+KP上限限制 */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbMin_kW;/* Referenced by: '<S46>/Saturation2' */

/* 充电功率闭环KI+KP下限限制 */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbOff_kW;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg1' */

/* 充电功率闭环进入阀值 */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbOn_kW;
                          /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg15' */

/* 充电功率闭环退出阀值 */
extern CALDATA const volatile float32 KEMS_DCCSurgePwr_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg2' */

/* DCC涌动功率 */
extern CALDATA const volatile float32 KEMS_DchaCurFbKiMax_A;/* Referenced by: '<S82>/Saturation' */

/* 放电Ki上限限制 */
extern CALDATA const volatile float32 KEMS_DchaCurFbKiMin_A;/* Referenced by: '<S82>/Saturation' */

/* 放电Ki下限限制 */
extern CALDATA const volatile float32 KEMS_DchaCurFbMax_A;/* Referenced by: '<S82>/Saturation2' */

/* 放电KP+Ki上限限制 */
extern CALDATA const volatile float32 KEMS_DchaCurFbMin_A;/* Referenced by: '<S82>/Saturation2' */

/* 放电KP+Ki下限限制 */
extern CALDATA const volatile float32 KEMS_DchaFbActvDlyTm_s;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg2' */

/* 放电功率闭环退出延迟时间 */
extern CALDATA const volatile float32 KEMS_DchaPwr2MotRawFiltCoeff_c;
                           /* Referenced by: '<S28>/KVTM_LimpHomeOvrdSw_flg2' */

/* 放电总功率滤波系数（只滤上升） */
extern CALDATA const volatile float32 KEMS_DchaPwrFbFiltCoeff_c;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg3' */

/* 放电功率闭环滤波系数 */
extern CALDATA const volatile float32 KEMS_DchaPwrFbKiMax_kW;/* Referenced by: '<S64>/Saturation' */

/* 放电功率闭环KI上限限制 */
extern CALDATA const volatile float32 KEMS_DchaPwrFbKiMin_kW;/* Referenced by: '<S64>/Saturation' */

/* 放电功率闭环KI下限限制 */
extern CALDATA const volatile float32 KEMS_DchaPwrFbMax_kW;/* Referenced by: '<S64>/Saturation2' */

/* 放电功率闭环KI+KP上限限制 */
extern CALDATA const volatile float32 KEMS_DchaPwrFbMin_kW;/* Referenced by: '<S64>/Saturation2' */

/* 放电功率闭环KI+KP下限限制 */
extern CALDATA const volatile float32 KEMS_DchaPwrFbOff_kW;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg1' */

/* 放电功率闭环退出阀值 */
extern CALDATA const volatile float32 KEMS_DchaPwrFbOn_kW;
                          /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg15' */

/* 放电功率闭环进入阀值 */
extern CALDATA const volatile float32 KEMS_HVBatActCurrExcdThr_A;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg1' */

/* 实际电流异常超限值 */
extern CALDATA const volatile float32 KEMS_HVBatActCurrExcdVal_A;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg2' */

/* 实际电流异常超限替代值（驱动超限） */
extern CALDATA const volatile float32 KEMS_HVBatCurrBelowConChrgDlyTm_s;
                         /* Referenced by: '<S26>/KTQC_DrvTqLoEnblRBSThr_Nm1' */

/* Con持续回收切Ins瞬时回收 */
extern CALDATA const volatile float32 KEMS_HVBatCurrBelowConDlyTm_s;
                         /* Referenced by: '<S28>/KTQC_DrvTqLoEnblRBSThr_Nm1' */

/* Con持续切Ins瞬时 */
extern CALDATA const volatile float32 KEMS_HVBatCurrOverConChrgDlyTm_s;
                         /* Referenced by: '<S26>/KTQC_DrvTqLoEnblRBSThr_Nm3' */

/* Ins瞬时回收切Con持续回收 */
extern CALDATA const volatile float32 KEMS_HVBatCurrOverConDlyTm_s;
                         /* Referenced by: '<S28>/KTQC_DrvTqLoEnblRBSThr_Nm3' */

/* Ins瞬时切Con持续 */
extern CALDATA const volatile float32 KEMS_MaxChrgCurDecRate_Aps;
                        /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltCoeff_c1' */

/* 最大充电电流下降斜率 */
extern CALDATA const volatile float32 KEMS_MaxChrgCurFiltAchvd_A;
                        /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltAchvd_Nm' */

/* 最大充电电流滤波结束值 */
extern CALDATA const volatile float32 KEMS_MaxChrgCurIncRate_Aps;
                         /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltCoeff_c' */

/* 最大充电电流上升斜率 */
extern CALDATA const volatile float32 KEMS_MaxDchaCurDecRate_Aps;
                        /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltCoeff_c1' */

/* 最大放电电流下降斜率 */
extern CALDATA const volatile float32 KEMS_MaxDchaCurFiltAchvd_A;
                        /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltAchvd_Nm' */

/* 最大放电电流滤波结束值 */
extern CALDATA const volatile float32 KEMS_MaxDchaCurIncRate_Aps;
                         /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltCoeff_c' */

/* 最大放电电流上升斜率 */
extern CALDATA const volatile float32 KEMS_TMSActSOCOff_pct;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg5' */

/* 关系TMS工作SOC阀值 */
extern CALDATA const volatile float32 KEMS_TMSActSOCOn_pct;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg4' */

/* 允许TMS工作SOC阀值 */
extern CALDATA const volatile float32 KEMS_TMSMaxPwrLim_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg6' */

/* TMS最大允许使用功率 */
extern CALDATA const volatile float32 KEMS_TMSPwrEnblOff_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg3' */

/* 关闭TMS工作功率阀值 */
extern CALDATA const volatile float32 KEMS_TMSPwrEnblOn_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg1' */

/* 允许TMS工作功率阀值 */
extern CALDATA const volatile float32 KEMS_TMSPwrOffDlyTm_s;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg8' */

/* 关闭TMS工作功率确认时间 */
extern CALDATA const volatile boolean KGSM_DRFlt2NSw_flg;/* Referenced by: '<S1531>/Constant3' */

/* 驱动档故障进N档强控 */
extern CALDATA const volatile boolean KGSM_DRFlt2NVal_flg;/* Referenced by: '<S1531>/Constant2' */

/* 驱动档故障进N档-观测量：VGSM_DRFlt2N_flg */
extern CALDATA const volatile float32 KGSM_EPBApld2PDlyTm_s;/* Referenced by: '<S1569>/Constant4' */

/* 规范：EPB拉起入P需求判断时间阈值 */
extern CALDATA const volatile float32 KGSM_EPBReld2NDlyTm_s;/* Referenced by: '<S1570>/Constant4' */

/* 规范：EPB释放入N需求判断时间阈值 */
extern CALDATA const volatile float32 KGSM_EPBReqMaxTm_s;/* Referenced by:
                                                          * '<S1508>/Constant2'
                                                          * '<S1508>/Constant4'
                                                          * '<S1508>/Constant5'
                                                          */

/* 规范：EPB拉起操作时间阈值 */
extern CALDATA const volatile boolean KGSM_GrNReq2PSw_flg;/* Referenced by: '<S1531>/Constant5' */

/* N档非换挡请求进P档请求强控 */
extern CALDATA const volatile boolean KGSM_GrNReq2PVal_flg;/* Referenced by: '<S1531>/Constant4' */

/* N档非换挡请求进P档请求-观测量：VGSM_GrNReq2P_flg */
extern CALDATA const volatile float32 KGSM_GrShftF1R1HldTm_s;/* Referenced by:
                                                              * '<S1568>/Constant3'
                                                              * '<S1568>/Constant4'
                                                              * '<S1570>/Constant2'
                                                              */

/* 规范：换挡杆入N需求判断时间阈值 */
extern CALDATA const volatile float32 KGSM_GrShftF2R2HldTm_s;/* Referenced by:
                                                              * '<S1568>/Constant5'
                                                              * '<S1568>/Constant6'
                                                              * '<S1568>/Constant7'
                                                              * '<S1568>/Constant8'
                                                              * '<S1570>/Constant1'
                                                              * '<S1570>/Constant9'
                                                              */

/* 规范：换挡杆入D需求判断时间阈值/换挡杆入R需求判断时间阈值 */
extern CALDATA const volatile float32 KGSM_GrShftHwPHldTm_s;/* Referenced by:
                                                             * '<S1569>/Constant2'
                                                             * '<S1569>/Constant5'
                                                             * '<S1569>/Constant6'
                                                             */

/* 规范：换挡杆入P按键时间阈值 */
extern CALDATA const volatile float32 KGSM_GrShftMaxVehSpd_kph;/* Referenced by:
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
extern CALDATA const volatile boolean KGSM_HldGearPSw_flg;/* Referenced by: '<S1531>/Constant1' */

/* 保持P档请求强控 */
extern CALDATA const volatile boolean KGSM_HldGearPVal_flg;/* Referenced by: '<S1531>/Constant' */

/* 保持P档请求-观测量：VGSM_HldGearP_flg */
extern CALDATA const volatile float32 KGSM_INVTrnOffDly_s;/* Referenced by: '<S1509>/Constant1' */

/* 规范：车辆实际档位由非P档进入到P档计时满2S */
extern CALDATA const volatile float32 KGSM_PErrDispMaxTm_s;/* Referenced by:
                                                            * '<S1508>/Cnst'
                                                            * '<S1508>/Cnst2'
                                                            */

/* 规范：Perror置位时间阈值 */
extern CALDATA const volatile boolean KGSM_ReqEPBSw_flg;/* Referenced by: '<S1508>/Constant1' */

/* 请求EPB状态强控 */
extern CALDATA const volatile EnumEPBReq KGSM_ReqEPBVal_enum;/* Referenced by: '<S1508>/Constant' */

/* 请求EPB状态-观测量：VGSM_ReqEPB_enum */
extern CALDATA const volatile float32 KGSM_TgtGrReqWatTm_s;/* Referenced by:
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
extern CALDATA const volatile boolean KGSM_VehActGearPstnSw_flg;
                                      /* Referenced by: '<S1509>/APA_Switdh4' */

/* 实际输出档位控制强控 */
extern CALDATA const volatile EnumGearPstn KGSM_VehActGearPstnVal_enum;
                                      /* Referenced by: '<S1509>/APA_Switdh5' */

/* 实际输出档位控制 0-P 1-N 2-D 3-R-观测量：VGSM_VehActGearPstn_enum */
extern CALDATA const volatile float32 KHMI_BackwSldgBgnEnd_kph;/* Referenced by: '<S638>/Constant1' */
extern CALDATA const volatile float32 KHMI_BackwSldgBgnSpd_kph;/* Referenced by: '<S638>/Constant' */
extern CALDATA const volatile float32 KHMI_BackwSldgDst_m;/* Referenced by: '<S638>/Constant2' */
extern CALDATA const volatile float32 KHMI_BatCellMaxTemWarning_C;/* Referenced by: '<S630>/Constant' */

/* 电芯（最高温度）限功率温度 */
extern CALDATA const volatile float32 KHMI_BothAccBrkTime_s;/* Referenced by: '<S631>/Constant1' */

/* 回馈能力受限判断时长 */
extern CALDATA const volatile float32 KHMI_CellOverTempTime_s;/* Referenced by: '<S630>/Constant1' */

/* 电芯过温判断时长 */
extern CALDATA const volatile float32 KHMI_DriPwrLmtTime_s;/* Referenced by: '<S635>/Constant1' */

/* 驱动能力受限判断时长 */
extern CALDATA const volatile float32 KHMI_DriPwrLmtVa_kw;/* Referenced by: '<S635>/Constant' */

/* 驱动能力受限阈值 */
extern CALDATA const volatile float32 KHMI_FwdSldgBgnEnd_kph;/* Referenced by: '<S638>/Constant5' */
extern CALDATA const volatile float32 KHMI_FwdSldgBgnSpd_kph;/* Referenced by: '<S638>/Constant4' */
extern CALDATA const volatile float32 KHMI_FwdSldgDst_m;/* Referenced by: '<S638>/Constant6' */
extern CALDATA const volatile float32 KHMI_InfoDispIntervalTm_s;/* Referenced by: '<S627>/Constant27' */

/* InfoDisp发送给仪表维持时长 */
extern CALDATA const volatile float32 KHMI_RecPwrLmtTime_s;/* Referenced by: '<S637>/Constant1' */

/* 回馈能力受限判断时长 */
extern CALDATA const volatile float32 KHMI_RecPwrLmtVa_kw;/* Referenced by: '<S637>/Constant' */

/* 回馈能力受限阈值 */
extern CALDATA const volatile float32 KHMI_SnowModWarnSpd_kph;/* Referenced by: '<S639>/Constant1' */

/* 雪地模式超速报警车速阈值 */
extern CALDATA const volatile float32 KHMI_SpdWheelFRdiff_kph;/* Referenced by:
                                                               * '<S640>/Constant1'
                                                               * '<S640>/Constant3'
                                                               * '<S640>/Constant5'
                                                               * '<S640>/Constant7'
                                                               */

/* 左右车轮差值阈值 */
extern CALDATA const volatile float32 KHMI_WarningSendTime_s;/* Referenced by:
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
extern CALDATA const volatile float32 KHVM_ChrgStopWaitTm_s;/* Referenced by: '<S749>/MainState' */

/* OBC充电唤醒源断开等待时间 */
extern CALDATA const volatile float32 KHVM_ChrgTransCfmTm_s;/* Referenced by:
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
extern CALDATA const volatile float32 KHVM_ChrgVoltReachCfmTm_s;/* Referenced by:
                                                                 * '<S750>/Constant4'
                                                                 * '<S750>/Constant7'
                                                                 */

/* 交直流充电达到截止电压确认时间 */
extern CALDATA const volatile float32 KHVM_DCCBuckLVVolt_V;/* Referenced by: '<S749>/MainState' */

/* DCDC BUCK 电压 */
extern CALDATA const volatile float32 KHVM_DchaStopWaitTm_s;/* Referenced by: '<S749>/MainState' */

/* OBC放电电唤醒源断开等待时间 */
extern CALDATA const volatile uint8 KHVM_HUMaxChrgCurntAC_A;/* Referenced by: '<S750>/Constant3' */

/* HU设置交流充电电流最大限制 */
extern CALDATA const volatile uint8 KHVM_HUMinChrgCurntAC_A;/* Referenced by: '<S750>/Constant2' */

/* HU设置交流充电电流最小限制 */
extern CALDATA const volatile float32 KHVM_HVCheckTmout_s;/* Referenced by: '<S749>/MainState' */

/* INV&DCDC高压建立等待时间 */
extern CALDATA const volatile float32 KHVM_HVCutOffTmout_s;/* Referenced by: '<S749>/MainState' */

/* BMS主继电器断开等待时间 */
extern CALDATA const volatile float32 KHVM_HVDeviceOffTmout_s;/* Referenced by: '<S749>/MainState' */

/* 下电关闭设备（空调&DCDC）等待时间 */
extern CALDATA const volatile float32 KHVM_HVDschrgTmout_s;/* Referenced by: '<S749>/MainState' */

/* INV泄放等待时间 */
extern CALDATA const volatile float32 KHVM_HVSetUpTmout_s;/* Referenced by: '<S749>/MainState' */

/* 主继电器闭合等待时间 */
extern CALDATA const volatile boolean KHVM_INVPreprogm_ovrdflg;/* Referenced by: '<S771>/Constant1' */

/* INV与编程标定控制开关 */
extern CALDATA const volatile boolean KHVM_INVPreprogm_ovrdval;/* Referenced by: '<S771>/Constant' */

/* INV与编程标定控制值 */
extern CALDATA const volatile float32 KHVM_INVholdTm_s;/* Referenced by: '<S749>/MainState' */

/* 下电保持INV硬线使能延迟时间 */
extern CALDATA const volatile float32 KHVM_KL15OffPwrDwnCfmTm_s;/* Referenced by: '<S775>/Constant4' */

/* KL15断开确认时间 */
extern CALDATA const volatile float32 KHVM_MaxHVDCCurntAC_A;/* Referenced by: '<S750>/Constant1' */

/* VCU反馈给OBC最大电流限制(直流侧) */
extern CALDATA const volatile float32 KHVM_MaxHVDCVoltAC_V;/* Referenced by: '<S750>/Constant12' */

/* 交流充电最大电压 */
extern CALDATA const volatile float32 KHVM_OBCS2ClsTmout_s;/* Referenced by: '<S749>/MainState' */

/* S2闭合等待时间 */
extern CALDATA const volatile boolean KHVM_PTRdy2PTStdby_ovrdflg;/* Referenced by: '<S773>/Constant7' */

/* Rdy退回Stdby开关 */
extern CALDATA const volatile boolean KHVM_PTRdy2PTStdby_ovrdval;/* Referenced by: '<S773>/Constant4' */

/* Rdy退回Stdby控制值 */
extern CALDATA const volatile float32 KHVM_PTRdyBrkSwEffctvTm_s;/* Referenced by: '<S773>/Constant1' */

/* 刹车上升沿保持时间 */
extern CALDATA const volatile boolean KHVM_PTStdby2PTRdy_ovrdflg;/* Referenced by: '<S773>/Constant3' */

/* Stdby进入Rdy开关 */
extern CALDATA const volatile boolean KHVM_PTStdby2PTRdy_ovrdval;/* Referenced by: '<S773>/Constant' */

/* Stdby进入Rdy控制值 */
extern CALDATA const volatile boolean KHVM_PowUpSelfChek_ovrdflg;/* Referenced by: '<S774>/Constant3' */

/* 高压自检条件控制开关 */
extern CALDATA const volatile boolean KHVM_PowUpSelfChek_ovrdval;/* Referenced by: '<S774>/Constant' */

/* 高压自检条件控制值 */
extern CALDATA const volatile boolean KHVM_PwrOn2PwrDwn_ovrdflg;/* Referenced by: '<S775>/Constant3' */

/* 高压下电条件满足开关 */
extern CALDATA const volatile boolean KHVM_PwrOn2PwrDwn_ovrdval;/* Referenced by: '<S775>/Constant' */

/* 高压下电条件满足控制值 */
extern CALDATA const volatile float32 KHVM_PwrUpACChrgEffctvTm_s;/* Referenced by: '<S776>/Constant1' */

/* OBC唤醒源上升沿保持时间 */
extern CALDATA const volatile float32 KHVM_PwrUpDCChrgEffctvTm_s;/* Referenced by: '<S776>/Constant4' */

/* BMS唤醒源上升沿保持时间 */
extern CALDATA const volatile float32 KHVM_PwrUpIBSDlyTm_s;/* Referenced by: '<S776>/Constant5' */

/* IBS唤醒源延迟时间 */
extern CALDATA const volatile float32 KHVM_PwrUpIBSEffctvTm_s;/* Referenced by: '<S776>/Constant9' */

/* IBS上升沿保持时间 */
extern CALDATA const volatile float32 KHVM_PwrUpKL15EffctvTm_s;/* Referenced by: '<S776>/Constant17' */

/* KL15上升沿保持时间 */
extern CALDATA const volatile float32 KHVM_SOCExtrmLo_pct;/* Referenced by: '<S752>/Constant9' */

/* SOC极低阈值 */
extern CALDATA const volatile float32 KHVM_SOCLoPwrDwnDlyTm_s;/* Referenced by: '<S775>/Constant2' */

/* SOC极低确认时间 */
extern CALDATA const volatile float32 KHVM_SOPExtrmLo_kW;/* Referenced by: '<S752>/Constant3' */

/* SOP极低阈值 */
extern CALDATA const volatile float32 KHVM_SleepWaitTm_s;/* Referenced by: '<S749>/MainState' */

/* 下电可以休眠等待时间 */
extern CALDATA const volatile float32 KHVM_TBOXReSetACChgTm_s;/* Referenced by: '<S750>/Constant6' */

/* TBOX远程充电请求保持时间 */
extern CALDATA const volatile boolean KHVM_Tbox2OBCOprtCmd_ovrdflg;/* Referenced by: '<S750>/Constant9' */

/* TBOX远程充电开关 */
extern CALDATA const volatile uint8 KHVM_Tbox2OBCOprtCmd_ovrdval;/* Referenced by: '<S750>/Constant' */

/* TBOX远程充电标定值 */
extern CALDATA const volatile float32 KHVM_VehHaltCfmTm_s;/* Referenced by: '<S752>/Constant7' */

/* 车辆停止车速确认时间 */
extern CALDATA const volatile float32 KHVM_VehHaltSpd_kph;/* Referenced by: '<S752>/Constant10' */

/* 车辆停止车速阈值 */
extern CALDATA const volatile float32 KHVM_VehMoveCfmTm_s;/* Referenced by: '<S752>/Constant12' */

/* 车辆运动车速确认时间 */
extern CALDATA const volatile float32 KHVM_VehSpdLo_kph;/* Referenced by: '<S752>/Constant2' */

/* 低车速阈值 */
extern CALDATA const volatile boolean KHVM_WakeUp2PwrUp_ovrdflg;/* Referenced by: '<S776>/Constant6' */

/* 唤醒到上高压条件开关 */
extern CALDATA const volatile boolean KHVM_WakeUp2PwrUp_ovrdval;/* Referenced by: '<S776>/Constant' */

/* 唤醒到上高压条件控制值 */
extern CALDATA const volatile boolean KHVM_WakeUpVCU_ovrdflg;/* Referenced by: '<S777>/Constant1' */

/* 休眠到唤醒条件控制开关 */
extern CALDATA const volatile boolean KHVM_WakeUpVCU_ovrdval;/* Referenced by: '<S777>/Constant' */

/* 休眠到唤醒条件控制值 */
extern CALDATA const volatile uint8 KIBS_ChgMaxNumThr_cnt;/* Referenced by:
                                                           * '<S1002>/Constant'
                                                           * '<S1002>/Constant6'
                                                           */

/* 最大补电次数阈值_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgCurntOKThr_A;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS充电电流阈值_versteckt */
extern CALDATA const volatile uint16 KIBS_ChrgFailTmThr_min;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS补电故障时间阈值_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgTempThr1_C;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电温度阈值1_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgTempThr2_C;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电温度阈值2_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgTempThr3_C;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电温度阈值3_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr1_V;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值1_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr2_V;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值2_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr3_V;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值3_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr4_V;/* Referenced by: '<S1003>/VoltState' */

/* IBS补电电压阈值4_versteckt */
extern CALDATA const volatile uint16 KIBS_CurntOKTmThr_min;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS充电电流达到阈值确认时间_versteckt */
extern CALDATA const volatile float32 KIBS_DfltEnvirTemp_C;/* Referenced by: '<S1003>/Constant1' */

/* AC环境温度失效时，默认的环境温度_versteckt */
extern CALDATA const volatile float32 KIBS_EnvirTemptFiltCoeff_c;/* Referenced by: '<S1003>/Constant3' */

/* 环境温度滤波系数_versteckt */
extern CALDATA const volatile uint8 KIBS_FailChgNumThr_cnt;/* Referenced by:
                                                            * '<S1002>/Constant10'
                                                            * '<S1002>/Constant12'
                                                            */

/* 最大补电失败次数阈值_versteckt */
extern CALDATA const volatile boolean KIBS_FbIBSWup_flg;/* Referenced by: '<S1002>/Constant17' */

/* 禁止IBS唤醒手动开关_versteckt */
extern CALDATA const volatile uint16 KIBS_FbRctWupThr_min;/* Referenced by: '<S1003>/Constant10' */

/* 禁止RTC唤醒配置的时间_versteckt */
extern CALDATA const volatile uint16 KIBS_HoldNMTmThr_s;/* Referenced by: '<S1002>/Constant14' */

/* IBS唤醒保持网络时间_versteckt */
extern CALDATA const volatile uint8 KIBS_KL30VoltDebNumThr_cnt;/* Referenced by: '<S1020>/Constant2' */

/* KL30电压低于补电电压总次数_versteckt */
extern CALDATA const volatile float32 KIBS_KL30VoltDebTmThr_s;/* Referenced by: '<S1003>/Constant7' */

/* KL30电压是否满足诊断时间_versteckt */
extern CALDATA const volatile float32 KIBS_KL30VoltFiltCoeff_c;/* Referenced by: '<S1003>/Constant2' */

/* KL30电压滤波系数_versteckt */
extern CALDATA const volatile uint16 KIBS_StWaitTm_s;/* Referenced by: '<S1003>/Constant5' */

/* IBS状态（电压&温度）稳定时间_versteckt */
extern CALDATA const volatile uint8 KIBS_WakeupReas_enum;/* Referenced by: '<S1018>/Constant' */

/* 底层唤醒原因枚举值_versteckt */
extern CALDATA const volatile uint16 KIBS_WupChgTmThr1_min;/* Referenced by: '<S1000>/ChrgSt' */

/* IBS补电时间阈值1_versteckt */
extern CALDATA const volatile boolean KIPC_ACCCfgOvrdSw_flg;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile boolean KIPC_ACCCfgOvrdVal_flg;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile float32 KIPC_AccPed1FullPstn_pct;/* Referenced by: '<S882>/Constant2' */
extern CALDATA const volatile float32 KIPC_AccPed2FullPstn_pct;/* Referenced by: '<S884>/Constant6' */
extern CALDATA const volatile float32 KIPC_AccPedDbnd_pct;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp1' */
extern CALDATA const volatile float32 KIPC_AccPedInitTm_s;
                               /* Referenced by: '<S879>/KIPC_AccPedInitTm_s' */
extern CALDATA const volatile float32 KIPC_AccPedLrnDwnFiltCoeff_rat;/* Referenced by:
                                                                      * '<S881>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                      * '<S883>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                      */
extern CALDATA const volatile float32 KIPC_AccPedLrnDwnStabThr_pct;/* Referenced by:
                                                                    * '<S881>/KAccPed_Threshold1ISLow_V6'
                                                                    * '<S883>/KAccPed_Threshold1ISLow_V6'
                                                                    */
extern CALDATA const volatile float32 KIPC_AccPedLrnDwnStabTm_s;/* Referenced by:
                                                                 * '<S881>/KAccPed_Threshold1ISLow_V5'
                                                                 * '<S883>/KAccPed_Threshold1ISLow_V5'
                                                                 */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnHi_pct;/* Referenced by:
                                                                * '<S881>/KAccPed_Threshold1ISLow_V10'
                                                                * '<S881>/KAccPed_Threshold1ISLow_V11'
                                                                * '<S883>/KAccPed_Threshold1ISLow_V10'
                                                                * '<S883>/KAccPed_Threshold1ISLow_V11'
                                                                */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnLo_pct;/* Referenced by:
                                                                * '<S881>/KAccPed_Threshold1ISLow_V8'
                                                                * '<S883>/KAccPed_Threshold1ISLow_V8'
                                                                */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnLrnUpHi_pct;/* Referenced by:
                                                                     * '<S881>/KAccPed_Threshold1ISLow_V2'
                                                                     * '<S883>/KAccPed_Threshold1ISLow_V2'
                                                                     */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnLrnUpLo_pct;/* Referenced by:
                                                                     * '<S881>/KAccPed_Threshold1ISLow_V1'
                                                                     * '<S883>/KAccPed_Threshold1ISLow_V1'
                                                                     */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnUpOfst_pct;/* Referenced by:
                                                                    * '<S881>/KAccPed_Threshold1ISLow_V7'
                                                                    * '<S883>/KAccPed_Threshold1ISLow_V7'
                                                                    */
extern CALDATA const volatile float32 KIPC_AccPedNormzPstnFiltTm_s;/* Referenced by:
                                                                    * '<S878>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                    * '<S878>/KIPC_AccPedLrnDwnFiltCoeff_rat1'
                                                                    */
extern CALDATA const volatile float32 KIPC_AccPedPrsdThr4Stk_pct;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V1' */
extern CALDATA const volatile float32 KIPC_AccPedPstnLmt_pct;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp5' */
extern CALDATA const volatile boolean KIPC_AccPedPstnOvrdSw_flg;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp3' */
extern CALDATA const volatile float32 KIPC_AccPedPstnOvrdVal_pct;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp4' */
extern CALDATA const volatile float32 KIPC_AccPedSclRng_pct;/* Referenced by:
                                                             * '<S882>/cnst_ValidCheck_EngCoolantTemp1'
                                                             * '<S884>/cnst_ValidCheck_EngCoolantTemp3'
                                                             */
extern CALDATA const volatile boolean KIPC_AccPedStkDiagEnbl_flg;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V7' */
extern CALDATA const volatile float32 KIPC_AccPedStkFiltCoeff_rat;
                       /* Referenced by: '<S879>/KIPC_AccPedStkFiltCoeff_rat' */
extern CALDATA const volatile float32 KIPC_AccPedStkStabThr_pct;
                        /* Referenced by: '<S879>/KAccPed_Threshold1ISLow_V6' */
extern CALDATA const volatile float32 KIPC_AccPedStkStabTm_s;
                        /* Referenced by: '<S879>/KAccPed_Threshold1ISLow_V5' */
extern CALDATA const volatile float32 KIPC_AccPedSwThr_pct;
                   /* Referenced by: '<S876>/cnst_ValidCheck_EngCoolantTemp2' */

/* 油门开关开启阈值 */
extern CALDATA const volatile float32 KIPC_AccPedZeroPstnDecRate_pctps;
                          /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V18' */
extern CALDATA const volatile float32 KIPC_AccPedZeroPstnIncRate_pctps;
                          /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V17' */
extern CALDATA const volatile float32 KIPC_BrkPedPrsdThr4Stk_pct;
                          /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V11' */
extern CALDATA const volatile float32 KIPC_BrkPedPstnDfltPrsd_pct;/* Referenced by: '<S871>/Constant2' */
extern CALDATA const volatile boolean KIPC_BrkPedPstnOvrdSw_flg;
                   /* Referenced by: '<S871>/cnst_ValidCheck_EngCoolantTemp2' */
extern CALDATA const volatile float32 KIPC_BrkPedPstnOvrdVal_pct;
                   /* Referenced by: '<S871>/cnst_ValidCheck_EngCoolantTemp3' */
extern CALDATA const volatile float32 KIPC_BrkPedReldThr4Stk_pct;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V2' */
extern CALDATA const volatile float32 KIPC_BrkSwPrsdPedPstn_pct;
                             /* Referenced by: '<S871>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile boolean KIPC_CCSCfgOvrdSw_flg;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile boolean KIPC_CCSCfgOvrdVal_flg;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg1' */
extern CALDATA const volatile boolean KIPC_CrpCtrlCfgOvrdSw_flg;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile boolean KIPC_CrpCtrlCfgOvrdVal_flg;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile boolean KIPC_CrpModeActOvrdSw_flg;
                           /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg' */
extern CALDATA const volatile EnumCrpModeAct KIPC_CrpModeActOvrdVal_enum;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg' */
extern CALDATA const volatile boolean KIPC_DrvModeActOvrdSw_flg;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile EnumDrvModeAct KIPC_DrvModeActOvrdVal_enum;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg1' */
extern CALDATA const volatile boolean KIPC_DrvPwrIntnstyOvrdSw_flg;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile uint8 KIPC_DrvPwrIntnstyOvrdVal_pct;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg4' */
extern CALDATA const volatile boolean KIPC_ESCVehSpdPrio_flg;
                                /* Referenced by: '<S942>/KSYS_VehTransRto_c' */
extern CALDATA const volatile boolean KIPC_ESCWhlSpdPrio_flg;
                               /* Referenced by: '<S942>/KSYS_VehTransRto_c2' */
extern CALDATA const volatile boolean KIPC_EnblFltRstAccPedZP_flg;
                           /* Referenced by: '<S879>/KAPD_Threshold1ISLow_V3' */
extern CALDATA const volatile boolean KIPC_EnblVpedAutoCrp_flg;/* Referenced by: '<S910>/Shift_enum1' */
extern CALDATA const volatile float32 KIPC_ExitAutoCrpDrvDist_m;
                         /* Referenced by: '<S910>/KIPC_ExitAutoCrpDrvDist_m' */
extern CALDATA const volatile float32 KIPC_ExitAutoCrpPNDurTm_s;/* Referenced by: '<S910>/Shift_enum4' */
extern CALDATA const volatile float32 KIPC_ExitAutoCrpVehSpd_kph;
                        /* Referenced by: '<S910>/KIPC_ExitAutoCrpVehSpd_kph' */
extern CALDATA const volatile boolean KIPC_HDCCfgOvrdSw_flg;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile boolean KIPC_HDCCfgOvrdVal_flg;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg4' */
extern CALDATA const volatile boolean KIPC_RegenModeActOvrdSw_flg;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile EnumRegenModeAct KIPC_RegenModeActOvrdVal_enum;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile boolean KIPC_RegenPwrIntnstyOvrdSw_flg;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile uint8 KIPC_RegenPwrIntnstyOvrdVal_pct;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg5' */
extern CALDATA const volatile boolean KIPC_SnowModeDft_flg;/* Referenced by: '<S873>/Unit Delay3' */
extern CALDATA const volatile boolean KIPC_SnowModeOvrdSw_flg;
                          /* Referenced by: '<S873>/KIPC_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile boolean KIPC_SnowModeOvrdVal_flg;
                         /* Referenced by: '<S873>/KIPC_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile float32 KIPC_VehHiddenBtnSyncnTm_s;/* Referenced by:
                                                                  * '<S873>/Cnst4'
                                                                  * '<S873>/Cnst6'
                                                                  * '<S873>/Cnst9'
                                                                  */
extern CALDATA const volatile float32 KIPC_VehHiddenModeWaitTm_s;/* Referenced by:
                                                                  * '<S873>/Cnst1'
                                                                  * '<S873>/Cnst2'
                                                                  * '<S873>/Cnst3'
                                                                  * '<S873>/Cnst5'
                                                                  * '<S873>/Cnst7'
                                                                  */
extern CALDATA const volatile boolean KIPC_iTPMSCfgOvrdSw_flg;
                          /* Referenced by: '<S874>/KIPC_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile boolean KIPC_iTPMSCfgOvrdVal_flg;
                         /* Referenced by: '<S874>/KIPC_LimpHomeOvrdVal_flg5' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVoltHi_mV;/* Referenced by: '<S1462>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVoltLo_mV;/* Referenced by: '<S1462>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh1SuplyVolt_mV_ovrdflg;/* Referenced by: '<S1462>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVolt_mV_ovrdval;/* Referenced by: '<S1462>/sat4' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1VoltHi_mV;/* Referenced by: '<S1463>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1VoltLo_mV;/* Referenced by: '<S1463>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh1Volt_mV_ovrdflg;/* Referenced by: '<S1463>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1Volt_mV_ovrdval;/* Referenced by: '<S1463>/sat4' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVoltHi_mV;/* Referenced by: '<S1464>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVoltLo_mV;/* Referenced by: '<S1464>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh2SuplyVolt_mV_ovrdflg;/* Referenced by: '<S1464>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVolt_mV_ovrdval;/* Referenced by: '<S1464>/sat4' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2VoltHi_mV;/* Referenced by: '<S1465>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2VoltLo_mV;/* Referenced by: '<S1465>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh2Volt_mV_ovrdflg;/* Referenced by: '<S1465>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2Volt_mV_ovrdval;/* Referenced by: '<S1465>/sat4' */
extern CALDATA const volatile boolean KIPM_HwBMSWakeup_flg_ovrdflg;/* Referenced by: '<S1466>/sat3' */
extern CALDATA const volatile boolean KIPM_HwBMSWakeup_flg_ovrdval;/* Referenced by: '<S1466>/sat4' */
extern CALDATA const volatile boolean KIPM_HwBrkSwHi_flg_ovrdflg;/* Referenced by: '<S1467>/sat3' */
extern CALDATA const volatile boolean KIPM_HwBrkSwHi_flg_ovrdval;/* Referenced by: '<S1467>/sat4' */
extern CALDATA const volatile boolean KIPM_HwBrkSwLo_flg_ovrdflg;/* Referenced by: '<S1468>/sat3' */
extern CALDATA const volatile boolean KIPM_HwBrkSwLo_flg_ovrdval;/* Referenced by: '<S1468>/sat4' */
extern CALDATA const volatile boolean KIPM_HwCrpModeSw_flg_ovrdflg;/* Referenced by: '<S1469>/sat3' */
extern CALDATA const volatile boolean KIPM_HwCrpModeSw_flg_ovrdval;/* Referenced by: '<S1469>/sat4' */
extern CALDATA const volatile boolean KIPM_HwDrvModeSw_flg_ovrdflg;/* Referenced by: '<S1470>/sat3' */
extern CALDATA const volatile boolean KIPM_HwDrvModeSw_flg_ovrdval;/* Referenced by: '<S1470>/sat4' */
extern CALDATA const volatile boolean KIPM_HwEmgcyShutOff_flg_ovrdflg;/* Referenced by: '<S1471>/sat3' */
extern CALDATA const volatile boolean KIPM_HwEmgcyShutOff_flg_ovrdval;/* Referenced by: '<S1471>/sat4' */
extern CALDATA const volatile float32 KIPM_HwHVIL1VoltHi_mV;/* Referenced by: '<S1472>/sat6' */
extern CALDATA const volatile float32 KIPM_HwHVIL1VoltLo_mV;/* Referenced by: '<S1472>/sat7' */
extern CALDATA const volatile boolean KIPM_HwHVIL1Volt_mV_ovrdflg;/* Referenced by: '<S1472>/sat3' */
extern CALDATA const volatile float32 KIPM_HwHVIL1Volt_mV_ovrdval;/* Referenced by: '<S1472>/sat4' */
extern CALDATA const volatile float32 KIPM_HwHVIL2VoltHi_mV;/* Referenced by: '<S1473>/sat6' */
extern CALDATA const volatile float32 KIPM_HwHVIL2VoltLo_mV;/* Referenced by: '<S1473>/sat7' */
extern CALDATA const volatile boolean KIPM_HwHVIL2Volt_mV_ovrdflg;/* Referenced by: '<S1473>/sat3' */
extern CALDATA const volatile float32 KIPM_HwHVIL2Volt_mV_ovrdval;/* Referenced by: '<S1473>/sat4' */
extern CALDATA const volatile boolean KIPM_HwKL15A_flg_ovrdflg;/* Referenced by: '<S1474>/sat3' */
extern CALDATA const volatile boolean KIPM_HwKL15A_flg_ovrdval;/* Referenced by: '<S1474>/sat4' */
extern CALDATA const volatile boolean KIPM_HwKL15B_flg_ovrdflg;/* Referenced by: '<S1475>/sat3' */
extern CALDATA const volatile boolean KIPM_HwKL15B_flg_ovrdval;/* Referenced by: '<S1475>/sat4' */
extern CALDATA const volatile uint16 KIPM_HwKL30Hi_mV;/* Referenced by: '<S1476>/sat6' */
extern CALDATA const volatile uint16 KIPM_HwKL30Lo_mV;/* Referenced by: '<S1476>/sat7' */
extern CALDATA const volatile boolean KIPM_HwKL30_mV_ovrdflg;/* Referenced by: '<S1476>/sat3' */
extern CALDATA const volatile uint16 KIPM_HwKL30_mV_ovrdval;/* Referenced by: '<S1476>/sat4' */
extern CALDATA const volatile boolean KIPM_HwOBCWakeup_flg_ovrdflg;/* Referenced by: '<S1477>/sat3' */
extern CALDATA const volatile boolean KIPM_HwOBCWakeup_flg_ovrdval;/* Referenced by: '<S1477>/sat4' */
extern CALDATA const volatile boolean KIPM_HwRearFogLampSwt_flg_ovrdflg;/* Referenced by: '<S1478>/sat3' */
extern CALDATA const volatile boolean KIPM_HwRearFogLampSwt_flg_ovrdval;/* Referenced by: '<S1478>/sat4' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwPrsdHi_Ohm;/* Referenced by: '<S1481>/Constant' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwPrsdLo_Ohm;/* Referenced by: '<S1481>/Constant1' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwReldHi_Ohm;/* Referenced by: '<S1481>/Constant3' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwReldLo_Ohm;/* Referenced by: '<S1481>/Constant4' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwShtBatt_Ohm;/* Referenced by: '<S1481>/Constant5' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwShtGnd_Ohm;/* Referenced by: '<S1481>/Constant7' */
extern CALDATA const volatile boolean KIPM_HwShftPstnSwSts_enum_ovrdflg;/* Referenced by: '<S1479>/sat3' */
extern CALDATA const volatile EnumPGearSwSts KIPM_HwShftPstnSwSts_enum_ovrdval;/* Referenced by: '<S1479>/sat4' */
extern CALDATA const volatile boolean KIPM_HwVehCrash_flg_ovrdflg;/* Referenced by: '<S1480>/sat3' */
extern CALDATA const volatile boolean KIPM_HwVehCrash_flg_ovrdval;/* Referenced by: '<S1480>/sat4' */
extern CALDATA const volatile boolean KOPM_HwWakeupBMS_flg_ovrdflg;/* Referenced by: '<S1494>/sat3' */
extern CALDATA const volatile boolean KOPM_HwWakeupBMS_flg_ovrdval;/* Referenced by: '<S1494>/sat4' */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm100NumWghtFac_c;/* Referenced by: '<S981>/Constant9' */

/* 前100个数组能耗加权系数 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm10NumWghtFac_c;/* Referenced by: '<S981>/Constant5' */

/* 前10个数组能耗加权系数 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm15NumWghtFac_c;/* Referenced by: '<S981>/Constant6' */

/* 前15个数组能耗加权系数 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm1NumWghtFac_c;/* Referenced by: '<S981>/Constant3' */

/* 初始数组加权系数 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm25NumWghtFac_c;/* Referenced by: '<S981>/Constant7' */

/* 前25个数组能耗加权系数 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm50NumWghtFac_c;/* Referenced by: '<S981>/Constant8' */

/* 前50个数组能耗加权系数 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm5NumWghtFac_c;/* Referenced by: '<S981>/Constant4' */

/* 前5个数组能耗加权系数 */
extern CALDATA const volatile boolean KRME_AvgSOCCnsmWghtSw_flg;/* Referenced by: '<S981>/Constant10' */

/* 加权SOC消耗强控开关 */
extern CALDATA const volatile float32 KRME_AvgSOCCnsmWghtVal_pctpkm;/* Referenced by: '<S981>/Constant11' */

/* 加权SOC消耗强控值 */
extern CALDATA const volatile float32 KRME_CHTCRmnMilEstVldOff_km;/* Referenced by: '<S951>/Constant4' */

/* 标准续航CHTC有效性Off */
extern CALDATA const volatile float32 KRME_CHTCRmnMilEstVldOn_km;/* Referenced by: '<S951>/Constant7' */

/* 标准续航CHTC有效性On */
extern CALDATA const volatile float32 KRME_CalPwrCnsmTgtDist_m;/* Referenced by:
                                                                * '<S955>/Constant8'
                                                                * '<S955>/Constant9'
                                                                */

/* Pwr功耗单位里程 */
extern CALDATA const volatile float32 KRME_CalPwrCnsmVehThr_kph;/* Referenced by: '<S955>/Constant1' */

/* 计算Pwr消耗车速值 */
extern CALDATA const volatile float32 KRME_CalSOCCnsmTgtDist_m;/* Referenced by:
                                                                * '<S980>/Constant2'
                                                                * '<S980>/Constant8'
                                                                * '<S980>/Constant9'
                                                                */

/* SOC消耗单位里程 */
extern CALDATA const volatile float32 KRME_CalSOCCnsmVehThr_kph;/* Referenced by:
                                                                 * '<S959>/Constant1'
                                                                 * '<S978>/Constant10'
                                                                 * '<S980>/Constant1'
                                                                 */

/* 计算SOC消耗车速值 */
extern CALDATA const volatile float32 KRME_ChrgOfstSOCVal_pct;/* Referenced by:
                                                               * '<S966>/Constant1'
                                                               * '<S966>/Constant2'
                                                               */

/* 充电模式SOC偏移值 */
extern CALDATA const volatile float32 KRME_DchaVehStpDlyTm_s;/* Referenced by: '<S978>/Constant11' */

/* 车辆停止确认时间 */
extern CALDATA const volatile float32 KRME_NVMMilDwLim_km;/* Referenced by: '<S958>/Constant2' */

/* NVM存储动态续航下限值 */
extern CALDATA const volatile float32 KRME_NVMMilUpLim_km;/* Referenced by: '<S958>/Constant8' */

/* NVM存储动态续航上限值 */
extern CALDATA const volatile float32 KRME_NVMSOCCnsmDwLim_pctp100km;/* Referenced by: '<S981>/Constant2' */

/* NVM存储SOC消耗下限值（按照100km折算） */
extern CALDATA const volatile float32 KRME_NVMSOCCnsmUpLim_pctp100km;/* Referenced by: '<S981>/Constant1' */

/* NVM存储SOC消耗上限值（按照100km折算） */
extern CALDATA const volatile uint8 KRME_SOCCnsmStorRst_enum;/* Referenced by: '<S981>/Constant64' */

/* 重置SOCCnse数组存储值(标定使用) */
extern CALDATA const volatile boolean KRME_SOHCrctFacEnbl_flg;/* Referenced by: '<S951>/Constant2' */

/* 使用SOH对RptSOC修正 */
extern CALDATA const volatile boolean KRME_WLTPCtrlModeSel_flg;/* Referenced by: '<S958>/Constant13' */

/* WLTP控制方式选择:0-动态续航 1-查表WLTP续航 */
extern CALDATA const volatile float32 KRME_WLTPRmnMilEstVldOff_km;/* Referenced by: '<S958>/Constant17' */

/* 动态续航WLTP有效性Off */
extern CALDATA const volatile float32 KRME_WLTPRmnMilEstVldOn_km;/* Referenced by: '<S958>/Constant18' */

/* 动态续航WLTP有效性On */
extern CALDATA const volatile float32 KRME_WLTPStdUpLimFac_c;/* Referenced by: '<S960>/Constant7' */

/* 基于标准续航WLTP最大上限系数 */
extern CALDATA const volatile uint8 KSYS_CalVer_cnt;
                           /* Referenced by: '<S1492>/ASYS_HVBatPackTyp_X_Ah' */
extern CALDATA const volatile boolean KSYS_ChkTaskRunCnt_flg;
                          /* Referenced by: '<S1492>/ASYS_HVBatPackTyp_X_Ah1' */
extern CALDATA const volatile float32 KSYS_VehMass_kg;/* Referenced by:
                                                       * '<S17>/KVTM_VehMass_kg'
                                                       * '<S1076>/KDAC_TapDwnTmOut_s'
                                                       * '<S1076>/KDAC_TapDwnTmOut_s1'
                                                       * '<S1076>/KDAC_TapDwnTmOut_s6'
                                                       * '<S1296>/KDAC_TapDwnTmOut_s1'
                                                       * '<S1167>/KDAC_TapDwnTmOut_s'
                                                       */
extern CALDATA const volatile float32 KSYS_VehTransRto_c;/* Referenced by:
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
extern CALDATA const volatile float32 KTBX_ChrgCondCfmTmr_s;/* Referenced by: '<S1034>/Constant3' */

/* 充电条件判断时间 */
extern CALDATA const volatile float32 KTBX_CnclSpdLimTmr_s;/* Referenced by: '<S1034>/Constant9' */

/* 取消限速等级确认时间 */
extern CALDATA const volatile float32 KTBX_LckVerCfmTmr_s;/* Referenced by: '<S1034>/Constant1' */

/* 锁车版本确认时间 */
extern CALDATA const volatile float32 KTBX_LoSpdCfmTmr_s;/* Referenced by: '<S1034>/Constant6' */

/* 低车速确认时间 */
extern CALDATA const volatile float32 KTBX_RecryCommCfmTmr_s;/* Referenced by: '<S1034>/Constant10' */

/* TBOX通讯恢复确认时间 */
extern CALDATA const volatile float32 KTBX_SpdLimCfmTmr_s;/* Referenced by:
                                                           * '<S1034>/Constant4'
                                                           * '<S1034>/Constant5'
                                                           * '<S1034>/Constant8'
                                                           */

/* 限速等级确认时间 */
extern CALDATA const volatile float32 KTBX_TBOXLostCommTmr_s;/* Referenced by: '<S1034>/Constant2' */

/* TBOX通讯丢失确认时间 */
extern CALDATA const volatile float32 KTBX_UnlckVerCfmTmr_s;/* Referenced by: '<S1034>/Constant' */

/* 非锁车版本确认时间 */
extern CALDATA const volatile float32 KTBX_VehLoSpdThr_kph;/* Referenced by:
                                                            * '<S1033>/Constant35'
                                                            * '<S1034>/Constant7'
                                                            */

/* 低车速阀值 */
extern CALDATA const volatile boolean KTQC_ABSInhbBrkRegen_flg;
                      /* Referenced by: '<S1261>/KTQD_CstRegenVehSpdOff_kph1' */
extern CALDATA const volatile float32 KTQC_ABSorESPActvTm1_s;
                      /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal' */
extern CALDATA const volatile float32 KTQC_ABSorESPActvTm2_s;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal1' */
extern CALDATA const volatile float32 KTQC_BrkRegenTgtTqDecRate_Nmps;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm5' */
extern CALDATA const volatile float32 KTQC_BrkRegenTgtTqIncRate_Nmps;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm4' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqDecRecry_Nmps;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal5' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqDecSlow_Nmps;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal4' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqIncPhs1_Nmps;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal2' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqIncPhs2_Nmps;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal3' */
extern CALDATA const volatile float32 KTQC_DrvTqHiDsblRBSDlyTm_s;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm3' */
extern CALDATA const volatile float32 KTQC_DrvTqHiDsblRBSThr_Nm;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm2' */
extern CALDATA const volatile float32 KTQC_DrvTqLoEnblRBSDlyTm_s;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm1' */
extern CALDATA const volatile float32 KTQC_DrvTqLoEnblRBSThr_Nm;
                        /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm' */
extern CALDATA const volatile float32 KTQC_ESCTqIntvAllwdVal_Nm;/* Referenced by:
                                                                 * '<S1440>/DrvCtl_DrvMot_MaxTrqFlg_Cal'
                                                                 * '<S1440>/DrvCtl_DrvMot_MaxTrqFlg_Cal1'
                                                                 * '<S1260>/DrvCtl_DrvMot_MaxTrqFlg_Cal'
                                                                 * '<S1260>/DrvCtl_DrvMot_MaxTrqFlg_Cal1'
                                                                 */
extern CALDATA const volatile boolean KTQC_EnblBrkRsmCstRegen_flg;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal8' */
extern CALDATA const volatile boolean KTQC_EnblESPIntvBrkTgtZero_flg;
                       /* Referenced by: '<S1261>/KTQC_DrvTqLoEnblRBSThr_Nm6' */
extern CALDATA const volatile boolean KTQC_EnblRBSIntv_flg;
                       /* Referenced by: '<S1261>/KTQD_CstRegenVehSpdOff_kph' */
extern CALDATA const volatile float32 KTQC_RsmCstRegenAccPed_pct;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal6' */
extern CALDATA const volatile float32 KTQC_RsmCstRegenTqReq_Nm;
                     /* Referenced by: '<S1259>/DrvCtl_DrvMot_MaxTrqFlg_Cal7' */
extern CALDATA const volatile float32 KTQD_AccelPedPrsdOff_pct;
                       /* Referenced by: '<S1322>/KTQD_CstRegenVehSpdOn_kph1' */
extern CALDATA const volatile float32 KTQD_AccelPedPrsdOn_pct;
                        /* Referenced by: '<S1322>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KTQD_AdaptCstDsrdTqIMax_N;
                                      /* Referenced by: '<S1296>/Saturation2' */
extern CALDATA const volatile float32 KTQD_AdaptCstDsrdTqIMin_N;
                                      /* Referenced by: '<S1296>/Saturation2' */
extern CALDATA const volatile boolean KTQD_AdaptCstRegenEnbl_flg;
                      /* Referenced by: '<S1292>/KTQD_CstRegenVehSpdOff_kph1' */
extern CALDATA const volatile float32 KTQD_AdaptCstTgtAcceltnFiltTm_s;
                              /* Referenced by: '<S1296>/KDAC_TapDwnTmOut_s2' */
extern CALDATA const volatile float32 KTQD_AdaptCstVehSpdOff_kph;
                       /* Referenced by: '<S1292>/KTQD_CstRegenVehSpdOff_kph' */
extern CALDATA const volatile float32 KTQD_AdaptCstVehSpdOn_kph;
                        /* Referenced by: '<S1292>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KTQD_BrkPedPrsd_pct;
                            /* Referenced by: '<S1291>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile float32 KTQD_BrkPedReldDlyTm_s;
                           /* Referenced by: '<S1292>/KTQD_BrkPedPstnHi_pct2' */
extern CALDATA const volatile boolean KTQD_CrpEnbl_flg;
                       /* Referenced by: '<S1282>/Motohawk_KTQD_EnblEcrp_flg' */
extern CALDATA const volatile float32 KTQD_CrpRsmPedPstn_pct;
                           /* Referenced by: '<S1282>/KTQD_CrpRsmPedPstn_pct' */
extern CALDATA const volatile float32 KTQD_CstRegenTqFiltAchvd_Nm;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph1' */
extern CALDATA const volatile float32 KTQD_CstRegenTqReqWhlDecEnbl_Nmps;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph3' */
extern CALDATA const volatile float32 KTQD_CstRegenTqReqWhlDec_Nmps;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph4' */
extern CALDATA const volatile float32 KTQD_CstRegenTqReqWhlIncEnbl_Nmps;
                      /* Referenced by: '<S1293>/KTQD_CstRegenVehSpdOff_kph2' */
extern CALDATA const volatile float32 KTQD_CstRegenVehSpdOff_kph;
                       /* Referenced by: '<S1291>/KTQD_CstRegenVehSpdOff_kph' */
extern CALDATA const volatile float32 KTQD_CstRegenVehSpdOn_kph;
                        /* Referenced by: '<S1291>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KTQD_EPBAppliedMaxTq_Nm;
                            /* Referenced by: '<S1321>/KTQD_LimpHomeMaxTq_Nm' */
extern CALDATA const volatile float32 KTQD_EnblDRShftVehSpd_kph;
                        /* Referenced by: '<S1314>/KTQD_EnblDRShftVehSpd_kph' */
extern CALDATA const volatile float32 KTQD_EnblDRShftWhlTq_Nm;
                          /* Referenced by: '<S1314>/KTQD_EnblDRShftWhlTq_Nm' */
extern CALDATA const volatile float32 KTQD_PedTqReqFiltCoeffMAA_c;
                      /* Referenced by: '<S1321>/KCPT_MotorMaxTqFiltCoeff_c2' */
extern CALDATA const volatile float32 KTQD_PlugOnTqZeroSpd_kph;
                         /* Referenced by: '<S1312>/KTQD_TqZeroSpdPlugOn_kph' */
extern CALDATA const volatile float32 KTQD_TqDrtFacLmtPerfmnRate_cps;
                   /* Referenced by: '<S1323>/KTQD_TqDrtFacVehSpdIncRate_cps' */
extern CALDATA const volatile float32 KTQD_TqDrtFacVehSpdDecRate_cps;
                   /* Referenced by: '<S1327>/KTQD_TqDrtFacVehSpdDecRate_cps' */
extern CALDATA const volatile float32 KTQD_TqDrtFacVehSpdIncRate_cps;
                   /* Referenced by: '<S1327>/KTQD_TqDrtFacVehSpdIncRate_cps' */
extern CALDATA const volatile float32 KTQD_WhlSpdDiffFiltCoeff_c;
                       /* Referenced by: '<S1278>/KTQD_WhlSpdDiffFiltCoeff_c' */
extern CALDATA const volatile boolean KTQF_DsblEndFlgRateCond_flg;
                   /* Referenced by: '<S1338>/KTQF_DsblEndFlgRateCondInc_flg' */

/* set to false, change rate is considered when judging ending flag */
extern CALDATA const volatile float32 KTQF_TqDecDlyTm_s;
                               /* Referenced by: '<S1336>/KTQF_TqDecDelay_s ' */

/* torque increase judgement turn on delay */
extern CALDATA const volatile float32 KTQF_TqDecThr_Nm;
                                /* Referenced by: '<S1336>/KTQF_TqDecThr_Nm ' */

/* torque decrease judgement tq threshold */
extern CALDATA const volatile float32 KTQF_TqIncDlyTm_s;
                               /* Referenced by: '<S1336>/KTQF_TqIncDelay_s ' */

/* torque Decrease judgement turn on delay */
extern CALDATA const volatile float32 KTQF_TqIncThr_Nm;
                                /* Referenced by: '<S1336>/KTQF_TqIncThr_Nm ' */

/* torque increase judgement tq threshold */
extern CALDATA const volatile float32 KTQF_TqOutChgRateFilt_rat;
                     /* Referenced by: '<S1338>/KTQF_TqOutChgRateFiltInc_rat' */

/* torque output change rate filter */
extern CALDATA const volatile float32 KTQF_TqRateDecMaxEndg_Nmps;
                       /* Referenced by: '<S1339>/KTQF_TqRateDecMaxEndg_Nmps' */

/* decrease tq rate max in ending or decreasing period */
extern CALDATA const volatile float32 KTQF_TqRateDecMaxRegenACC_Nmps;
                      /* Referenced by: '<S1339>/KTQF_TqRateDecMaxEndg_Nmps1' */
extern CALDATA const volatile float32 KTQF_TqRateDecMaxStart_Nmps;
                      /* Referenced by: '<S1339>/KTQF_TqRateDecMaxEndg_Nmps3' */
extern CALDATA const volatile float32 KTQF_TqRateDecMin_Nmps;/* Referenced by:
                                                              * '<S1338>/KTQF_TqRateDecMin_Nmps'
                                                              * '<S1339>/KTQF_TqRateDecMin_Nmps'
                                                              */

/* Rate limit, max decreasing.  */
extern CALDATA const volatile float32 KTQF_TqRateIncMaxEndg_Nmps;
                       /* Referenced by: '<S1340>/KTQF_TqRateIncMaxEndg_Nmps' */

/* increase tq rate max in ending or decreasing period */
extern CALDATA const volatile float32 KTQF_TqRateIncMin_Nmps;/* Referenced by:
                                                              * '<S1338>/KTQF_TqRateIncMin_Nmps'
                                                              * '<S1340>/KTQF_TqRateIncMin_Nmps'
                                                              */

/* Rate limit, min decreasing.  */
extern CALDATA const volatile float32 KTQF_TqRateLimEndErrFac_c;
                           /* Referenced by: '<S1338>/KTQF_TqRateLimEndTm_s1' */
extern CALDATA const volatile float32 KTQF_TqRateLimEndTm_s;
                            /* Referenced by: '<S1338>/KTQF_TqRateLimEndTm_s' */

/* Rate limit, target torque prediction time towards ending.  */
extern CALDATA const volatile float32 KTQF_TqRawChgRateFilt_rat;
                        /* Referenced by: '<S1338>/KTQF_TqRawChgRateFilt_rat' */

/* raw torque change rate filter */
extern CALDATA const volatile float32 KTQR_ABSActvDlyTm4Dampng_s;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg4' */
extern CALDATA const volatile float32 KTQR_ASDEnblOscSpd_rpm;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c3' */
extern CALDATA const volatile boolean KTQR_ASDEnbl_flg;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg6' */
extern CALDATA const volatile float32 KTQR_ASDOscTrigTm_s;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c1' */
extern CALDATA const volatile float32 KTQR_ASDPhCompKa_c;/* Referenced by:
                                                          * '<S1368>/KTQR_MotDampngLmtFac_c13'
                                                          * '<S1368>/KTQR_MotDampngLmtFac_c2'
                                                          * '<S1368>/KTQR_MotDampngLmtFac_c6'
                                                          * '<S1368>/KTQR_MotDampngLmtFac_c9'
                                                          */
extern CALDATA const volatile float32 KTQR_ASDPhCompKb1_c;/* Referenced by:
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c10'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c11'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c3'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c7'
                                                           */
extern CALDATA const volatile float32 KTQR_ASDPhCompKb2_c;/* Referenced by:
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c1'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c12'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c5'
                                                           * '<S1368>/KTQR_MotDampngLmtFac_c8'
                                                           */
extern CALDATA const volatile float32 KTQR_ASDSpdFiltHiDecRate_nu;
                          /* Referenced by: '<S1366>/KTQR_MotDampngLmtFac_c2' */
extern CALDATA const volatile float32 KTQR_ASDSpdFiltHiIncRate_nu;
                          /* Referenced by: '<S1366>/KTQR_MotDampngLmtFac_c1' */
extern CALDATA const volatile float32 KTQR_ASDSpdFiltLo_s;
                          /* Referenced by: '<S1366>/KTQR_MotDampngLmtFac_c3' */
extern CALDATA const volatile uint8 KTQR_ASDSpdPhCompCout_Cnt;
                          /* Referenced by: '<S1368>/KTQR_MotDampngLmtFac_c4' */
extern CALDATA const volatile float32 KTQR_ASDTqDbnd_Nm;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c4' */
extern CALDATA const volatile float32 KTQR_ASDTqMax_Nm;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c5' */
extern CALDATA const volatile float32 KTQR_ASDTqMin_Nm;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c6' */
extern CALDATA const volatile boolean KTQR_AllZeroCrsDsblDamp_flg;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg5' */
extern CALDATA const volatile boolean KTQR_BypassASDOscTrig_flg;
                          /* Referenced by: '<S1367>/KTQR_MotDampngLmtFac_c2' */
extern CALDATA const volatile float32 KTQR_MotDampngBrkout_pct;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c5' */
extern CALDATA const volatile float32 KTQR_MotDampngLmtFac_c;
                           /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c' */
extern CALDATA const volatile float32 KTQR_MotDampngLmtMaxRate_Nmps;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c4' */
extern CALDATA const volatile float32 KTQR_MotDampngLmtMin_Nm;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c2' */
extern CALDATA const volatile float32 KTQR_MotDampngSpdOff_rpm;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c3' */
extern CALDATA const volatile float32 KTQR_MotDampngSpdOn_rpm;
                          /* Referenced by: '<S1362>/KTQR_MotDampngLmtFac_c1' */
extern CALDATA const volatile boolean KTQR_MotorDampngDsblAZ_flg;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg3' */
extern CALDATA const volatile boolean KTQR_MotorDampngDsblBZ_flg;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg2' */
extern CALDATA const volatile boolean KTQR_MotorDampngDsblZX_flg;
                         /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg1' */
extern CALDATA const volatile boolean KTQR_MotorDampngEnbl_flg;
                          /* Referenced by: '<S1362>/KTQR_EnblMotorStdby_flg' */
extern CALDATA const volatile float32 KTQR_MotorStdbyDlyTm_s;
                               /* Referenced by: '<S1364>/KTQF_TqIncDelay_s ' */
extern CALDATA const volatile boolean KTQR_MotorStdbyEnbl_flg;
                          /* Referenced by: '<S1364>/KTQR_EnblMotorStdby_flg' */
extern CALDATA const volatile float32 KTQR_MotorStdbyVehHaltHi_kph;
                     /* Referenced by: '<S1364>/KTQR_MotorStdbyVehHaltHi_kph' */
extern CALDATA const volatile float32 KTQR_MotorStdbyVehHaltLo_kph;
                     /* Referenced by: '<S1364>/KTQR_MotorStdbyVehHaltLo_kph' */
extern CALDATA const volatile float32 KTQR_MotorTqZeroDlyTm_s;
                              /* Referenced by: '<S1363>/KTQF_TqIncDelay_s 1' */
extern CALDATA const volatile float32 KTQR_MotorTqZero_Nm;
                    /* Referenced by: '<S1363>/KTQR_MotorStdbyVehHaltLo_kph1' */
extern CALDATA const volatile float32 KTZX_AZDMaxTm_s;
                                  /* Referenced by: '<S1393>/KTZX_AZDMaxTm_s' */
extern CALDATA const volatile float32 KTZX_AZIMaxTm_s;
                                  /* Referenced by: '<S1393>/KTZX_AZIMaxTm_s' */
extern CALDATA const volatile float32 KTZX_BrkPedPrsd_pct;
                              /* Referenced by: '<S1393>/KTZX_BrkPedPrsd_pct' */
extern CALDATA const volatile float32 KTZX_ClkZXTmD_s;
                                  /* Referenced by: '<S1393>/KTZX_ClkZXTmD_s' */
extern CALDATA const volatile float32 KTZX_ClkZXTmR_s;
                                  /* Referenced by: '<S1393>/KTZX_ClkZXTmR_s' */
extern CALDATA const volatile float32 KTZX_ClkZXTqD_Nm;
                                 /* Referenced by: '<S1393>/KTZX_ClkZXTqD_Nm' */
extern CALDATA const volatile float32 KTZX_ClkZXTqR_Nm;
                                 /* Referenced by: '<S1393>/KTZX_ClkZXTqR_Nm' */
extern CALDATA const volatile float32 KTZX_MotorTqDecDlyTm_s;
                               /* Referenced by: '<S1403>/KTQF_TqDecDelay_s ' */
extern CALDATA const volatile float32 KTZX_MotorTqDecThr_Nm;
                                /* Referenced by: '<S1403>/KTQF_TqDecThr_Nm ' */
extern CALDATA const volatile float32 KTZX_MotorTqIncDlyTm_s;
                               /* Referenced by: '<S1403>/KTQF_TqIncDelay_s ' */
extern CALDATA const volatile float32 KTZX_MotorTqIncThr_Nm;
                                /* Referenced by: '<S1403>/KTQF_TqIncThr_Nm ' */
extern CALDATA const volatile float32 KTZX_TMSpdBckThr_rpm;
                             /* Referenced by: '<S1393>/KTZX_TMSpdBckThr_rpm' */
extern CALDATA const volatile float32 KTZX_TMSpdFwdThr_rpm;
                             /* Referenced by: '<S1393>/KTZX_TMSpdFwdThr_rpm' */
extern CALDATA const volatile float32 KTZX_TqDsengCfmTm_s;
                              /* Referenced by: '<S1393>/KTZX_TqDsengCfmTm_s' */
extern CALDATA const volatile float32 KTZX_TqDsengThr_Nm;
                               /* Referenced by: '<S1393>/KTZX_TqDsengThr_Nm' */
extern CALDATA const volatile boolean KTZX_UseZeroTqAddRngFinshAZ_flg;/* Referenced by:
                                                                      * '<S1419>/KTZX_UseZeroTqAddRngFinshAZ_flg'
                                                                      * '<S1420>/KTZX_UseZeroTqAddRngFinshAZ_flg'
                                                                      */
extern CALDATA const volatile float32 KTZX_VehStopSpd_kph;
                              /* Referenced by: '<S1393>/KTZX_VehStopSpd_kph' */
extern CALDATA const volatile float32 KTZX_ZXRegenTqTgtThr_Nm;
                            /* Referenced by: '<S1393>/KTZX_ZXRgnTqTgtThr_Nm' */
extern CALDATA const volatile uint16 KVCU_EcuCommReqOff_Cnt;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg4' */

/* _versteckt */
extern CALDATA const volatile uint16 KVCU_EcuCommReqOn_Cnt;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg1' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_EcuCommReq_flg;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg2' */

/* _versteckt */
extern CALDATA const volatile float32 KVCU_MCUTempWrngOff_C;
                         /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile float32 KVCU_MCUTempWrngOn_C;
                        /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg15' */
extern CALDATA const volatile float32 KVCU_MotorTempWrngOff_C;
                         /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile float32 KVCU_MotorTempWrngOn_C;
                         /* Referenced by: '<S1492>/KVTM_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile uint16 KVCU_RtcWakeupTm_min;
                         /* Referenced by: '<S1489>/KIPC_LimpHomeOvrdSw_flg3' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_XWhlDistErrRefOvrdSw_flg;
                        /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg13' */

/* _versteckt */
extern CALDATA const volatile float32 KVCU_XWhlDistErrRefOvrdVal_mpkm;
                         /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg5' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_XWhlDistErrRefStatOvrdSw_flg;
                        /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg12' */

/* _versteckt */
extern CALDATA const volatile uint8 KVCU_XWhlDistErrRefStatOvrdVal_enum;
                         /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg6' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_iTPMSWrngOvrdSw_flg;
                        /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg11' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_iTPMSWrngOvrdVal_flg;
                         /* Referenced by: '<S1490>/KIPC_LimpHomeOvrdSw_flg4' */

/* _versteckt */
extern CALDATA const volatile float32 KVSO_AirBlowArea_m2;/* Referenced by: '<S1098>/A' */
extern CALDATA const volatile float32 KVSO_AirResistCoeff_c;/* Referenced by: '<S1098>/Cd' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr1Fac_c;/* Referenced by: '<S1082>/Cnst3' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr2Fac_c;/* Referenced by: '<S1082>/Cnst1' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr3Fac_c;/* Referenced by: '<S1082>/Cnst2' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr4Fac_c;/* Referenced by: '<S1082>/Cnst4' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr5Fac_c;/* Referenced by: '<S1082>/Cnst5' */
extern CALDATA const volatile float32 KVSO_DistErrHldSlip_kph;/* Referenced by: '<S1086>/Cnst' */
extern CALDATA const volatile float32 KVSO_DistErrHldSpd_kph;/* Referenced by: '<S1086>/Cnst2' */
extern CALDATA const volatile float32 KVSO_DistErrHldStrg_kph;/* Referenced by:
                                                               * '<S1086>/Cnst1'
                                                               * '<S1086>/Cnst3'
                                                               */
extern CALDATA const volatile float32 KVSO_MassEstBrkPrsd_pct;
                          /* Referenced by: '<S1098>/KVSO_MassEstBrkPrsd_pct' */
extern CALDATA const volatile float32 KVSO_MassEstSpdLo_kph;
                            /* Referenced by: '<S1098>/KVSO_MassEstSpdLo_kph' */
extern CALDATA const volatile float32 KVSO_MotorActTqFiltTm_s;/* Referenced by: '<S1098>/Const1' */
extern CALDATA const volatile float32 KVSO_RSECovMeas_c;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c3' */
extern CALDATA const volatile float32 KVSO_RSECovSlopFrc_c;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c1' */
extern CALDATA const volatile float32 KVSO_RSECovVehSpdSlopFrc_c;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c2' */
extern CALDATA const volatile float32 KVSO_RSECovVehSpd_c;
                                 /* Referenced by: '<S1076>/KTQD_CovVehSpd_c' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqFiltTm_s;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c4' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqHoldBrkPresr_bar;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c7' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqHoldSpd_kph;
                        /* Referenced by: '<S1076>/KVSO_OPDSlopTqHoldSpd_kph' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqMax_Nm;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c5' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqMin_Nm;
                                /* Referenced by: '<S1076>/KTQD_CovVehSpd_c6' */
extern CALDATA const volatile float32 KVSO_RollgResistCoeff_c;/* Referenced by: '<S1098>/f' */
extern CALDATA const volatile float32 KVSO_RotMassCnvnCoeff_c;
                          /* Referenced by: '<S1098>/KVSO_RotMassCnvnCoeff_c' */
extern CALDATA const volatile float32 KVSO_SlopFiltTm_s;
                                /* Referenced by: '<S1098>/KVSO_SlopFiltTm_s' */
extern CALDATA const volatile float32 KVSO_TPMSLrnReqCfmTm_s;/* Referenced by: '<S1082>/Cnst7' */
extern CALDATA const volatile float32 KVSO_VMECovMeas_c;
                                   /* Referenced by: '<S1098>/KVSO_CovMeas_c' */
extern CALDATA const volatile float32 KVSO_VMECovSlop_c;
                                   /* Referenced by: '<S1098>/KVSO_CovSlop_c' */
extern CALDATA const volatile float32 KVSO_VMECovVehMass_c;
                                /* Referenced by: '<S1098>/KVSO_CovVehMass_c' */
extern CALDATA const volatile float32 KVSO_VMECovVehSpd2_c;
                                /* Referenced by: '<S1098>/KVSO_CovVehSpd2_c' */
extern CALDATA const volatile float32 KVSO_VMECovVehSpd_c;
                                 /* Referenced by: '<S1098>/KVSO_CovVehSpd_c' */
extern CALDATA const volatile float32 KVSO_VehMassFiltTm_s;
                             /* Referenced by: '<S1098>/KVSO_VehMassFiltTm_s' */
extern CALDATA const volatile float32 KVSO_VehMassInit_kg;
                              /* Referenced by: '<S1098>/KVSO_VehMassInit_kg' */
extern CALDATA const volatile float32 KVSO_VehResistPosTh_mps;
                              /* Referenced by: '<S1076>/KDAC_TapDwnTmOut_s5' */
extern CALDATA const volatile float32 KVSO_VehSpdFiltTm_s;/* Referenced by: '<S1098>/Const' */
extern CALDATA const volatile float32 KVSO_VehTransEff_c;
                               /* Referenced by: '<S1098>/KVSO_VehTransEff_c' */
extern CALDATA const volatile float32 KVSO_WhlDistErrRecThr_m;
                             /* Referenced by: '<S1095>/KVSO_SpdErrRecDist_m' */
extern CALDATA const volatile float32 KVSO_WhlDistErrRefRecThr_m;
                            /* Referenced by: '<S1095>/KVSO_SpdErrRecDist_m1' */
extern CALDATA const volatile float32 KVSO_XWhlDistErrExcd_mpkm;/* Referenced by: '<S1082>/Cnst6' */
extern CALDATA const volatile float32 KVTM_BrkLampOffRegenTq_Nm;/* Referenced by: '<S1447>/Constant8' */
extern CALDATA const volatile float32 KVTM_BrkLampOnRegenTq_Nm;/* Referenced by: '<S1447>/Constant9' */
extern CALDATA const volatile float32 KVTM_BrkPedReld_pct;
                            /* Referenced by: '<S1440>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile float32 KVTM_MotorMaxDrvPwr_kW;
                              /* Referenced by: '<S1449>/KSYS_VehTransRto_c2' */
extern CALDATA const volatile float32 KVTM_MotorMaxRegenPwr_kW;
                              /* Referenced by: '<S1449>/KSYS_VehTransRto_c1' */
extern CALDATA const volatile float32 KVTM_MotorPwrTypeRecup_Nm;
                              /* Referenced by: '<S1449>/KSYS_VehTransRto_c4' */
extern CALDATA const volatile float32 KVTM_MotorSpdFiltCoeff_rat;
                       /* Referenced by: '<S1440>/KVTM_MotorSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 KVTM_VehAcceltnFiltCoeff_rat;
                              /* Referenced by: '<S1440>/KDAC_TapDwnTmOut_s1' */
extern CALDATA const volatile float32 KVTM_VehAcceltnMax_mps2;
                                      /* Referenced by: '<S1440>/Saturation1' */
extern CALDATA const volatile float32 KVTM_VehAcceltnMin_mps2;
                                      /* Referenced by: '<S1440>/Saturation1' */
extern CALDATA const volatile float32 KVTM_VehSpdFiltCoeff_rat;
                      /* Referenced by: '<S1440>/KVTM_MotorSpdFiltCoeff_rat1' */
extern CALDATA const volatile float32 MCPT_MotorEffVoltFac_c[9];
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c1' */
extern CALDATA const volatile float32 MCPT_MotorSpdFiltCoeff_rat[8];
                      /* Referenced by: '<S1117>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 MCPT_Pwr2MotorTqGen_Nm[616];
                          /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm1' */
extern CALDATA const volatile float32 MCPT_Pwr2MotorTqMot_Nm[588];
                           /* Referenced by: '<S1117>/MCPT_Pwr2MotorTqMot_Nm' */
extern CALDATA const volatile float32 MCPT_TqDrtFacIgbtTemp_c[8];
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c2' */
extern CALDATA const volatile float32 MCPT_TqDrtFacMotorTemp_c[8];
                                /* Referenced by: '<S1117>/MTQD_TMOverDrt_c4' */
extern CALDATA const volatile float32 MDAC_ACCDsrdTqKi_c[225];
                      /* Referenced by: '<S1145>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_ACCDsrdTqKp_c[15];
                      /* Referenced by: '<S1145>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_ACCOvrdTqOff_Nm[7];
                            /* Referenced by: '<S1139>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MDAC_ACCOvrdTqOn_Nm[7];
                             /* Referenced by: '<S1139>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MDAC_CCDsrdAcceltnDec_mps3[12];
                /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm1' */
extern CALDATA const volatile float32 MDAC_CCDsrdAcceltnInc_mps3[12];
                 /* Referenced by: '<S1161>/Lookup_MTQD_CstRegenTqReqWhlR_Nm' */
extern CALDATA const volatile float32 MDAC_CCDsrdAcceltn_mps2[126];
                   /* Referenced by: '<S1161>/MTQD_TqRateLimEndErr_Nm_IntTbl' */
extern CALDATA const volatile float32 MDAC_CCDsrdTqKi_c[225];
                      /* Referenced by: '<S1168>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_CCDsrdTqKp_c[15];
                      /* Referenced by: '<S1168>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_CCMaxDrgTqWhl_Nm[14];
                             /* Referenced by: '<S1170>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MDAC_CCSpdStabLowerOfst_kph[8];
                            /* Referenced by: '<S1197>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MDAC_CCSpdStabUpprOfst_kph[8];
                             /* Referenced by: '<S1197>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MDAC_FullPedDrvTqWhl_Nm[23];
                                 /* Referenced by: '<S1134>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MDAC_HDCDsrdTqKi_c[225];
                      /* Referenced by: '<S1234>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_HDCDsrdTqKp_c[15];
                      /* Referenced by: '<S1234>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_HDCTgtAcceltn_mps2[16];
                                /* Referenced by: '<S1232>/1-D Lookup Table3' */
extern CALDATA const volatile float32 MDAC_INVMaxDrgTqWhl_Nm[12];
                                /* Referenced by: '<S1134>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MDAC_NonDrvnSpdFiltCoeff_rat[7];
                 /* Referenced by: '<S1159>/Lookup_MVTM_VehSpdFiltCoeff_rat1' */
extern CALDATA const volatile float32 MDAG_BMSSOCLoRecThr1_pct[10];
                         /* Referenced by: '<S103>/BMS_BMSCTL_LMPRECSOC1_CAL' */

/* BMSSOC低故障恢复门槛_低温 */
extern CALDATA const volatile float32 MDAG_BMSSOCLoRecThr2_pct[10];
                         /* Referenced by: '<S103>/BMS_BMSCTL_LMPRECSOC2_CAL' */

/* BMSSOC低故障恢复门槛_高温 */
extern CALDATA const volatile float32 MDAG_BMSSOCLoThr1_pct[10];
                            /* Referenced by: '<S103>/BMS_BMSCTL_LMPSOC1_CAL' */

/* BMSSOC低故障触发门槛_低温 */
extern CALDATA const volatile float32 MDAG_BMSSOCLoThr2_pct[10];
                            /* Referenced by: '<S103>/BMS_BMSCTL_LMPSOC2_CAL' */

/* BMSSOC低故障触发门槛_高温 */
extern CALDATA const volatile sint16 MDAG_CellTempLoThr_C[10];
                              /* Referenced by: '<S100>/MDAG_CellTempLoThr_C' */

/* 区分电芯温度高低的分界值 */
extern CALDATA const volatile uint16 MDAG_CellUndrVoltThr1_mV[10];
                          /* Referenced by: '<S100>/MDAG_CellUndrVoltThr1_mV' */

/* BMSCell欠压故障的电压门槛_低温 */
extern CALDATA const volatile uint16 MDAG_CellUndrVoltThr2_mV[10];
                          /* Referenced by: '<S100>/MDAG_CellUndrVoltThr2_mV' */

/* BMSCell欠压故障的电压门槛_高温 */
extern CALDATA const volatile float32 MDSA_DeceltnIdxAvg_pct[10];
                       /* Referenced by: '<S17>/MTQD_ZeroTqOfstTipInTMOly_Nm' */
extern CALDATA const volatile float32 MDSA_MildDrvMap_mps2[15];
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl3' */
extern CALDATA const volatile float32 MDSA_SprtIdxHldINVTq_Nm[15];
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl4' */
extern CALDATA const volatile float32 MDSA_VehDrgTq_Nm[15];
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl1' */
extern CALDATA const volatile float32 MDSA_WildDrvMap_mps2[15];
                         /* Referenced by: '<S17>/MTQD_RegenTqBrk_Nm_IntTbl2' */
extern CALDATA const volatile float32 MEMS_CellOverVoltBgn_mV[10];/* Referenced by: '<S26>/PwrDrt2' */

/* 过压修正Begin值（优先使用过压闭环） */
extern CALDATA const volatile float32 MEMS_CellOverVoltRng_mV[10];/* Referenced by: '<S26>/PwrDrt4' */

/* 过压修正Range值（优先使用过压闭环） */
extern CALDATA const volatile float32 MEMS_CellOverVoltThr_mV[10];/* Referenced by: '<S81>/PwrDrt' */

/* 过压闭环控制目标电压 */
extern CALDATA const volatile float32 MEMS_CellTempLoThr_C[10];/* Referenced by: '<S31>/PwrDrt4' */

/* 电芯常温和低温区分值 */
extern CALDATA const volatile float32 MEMS_CellTempMinFac_rat[5];
                                  /* Referenced by: '<S31>/MTQD_TMOverDrt_c5' */

/* 电芯温度切换过渡系数 */
extern CALDATA const volatile float32 MEMS_CellUndrVoltBgn1_mV[10];/* Referenced by: '<S28>/PwrDrt' */

/* 低温放电欠压修正Begin值（优先使用电压闭环） */
extern CALDATA const volatile float32 MEMS_CellUndrVoltBgn2_mV[10];/* Referenced by: '<S28>/PwrDrt1' */

/* 常温放电欠压修正Begin值(优先使用电压闭环) */
extern CALDATA const volatile float32 MEMS_CellUndrVoltRng1_mV[10];/* Referenced by: '<S28>/PwrDrt2' */

/* 低温放电欠压修正Rang值（优先使用电压闭环） */
extern CALDATA const volatile float32 MEMS_CellUndrVoltRng2_mV[10];/* Referenced by: '<S28>/PwrDrt3' */

/* 常温放电欠压修正Rang值(优先使用电压闭环) */
extern CALDATA const volatile float32 MEMS_CellUndrVoltThr1_mV[10];/* Referenced by: '<S82>/PwrDrt' */

/* 低温电压闭环控制目标电压 */
extern CALDATA const volatile float32 MEMS_CellUndrVoltThr2_mV[10];/* Referenced by: '<S82>/PwrDrt1' */

/* 常温电压闭环控制目标电压 */
extern CALDATA const volatile float32 MEMS_ChrgCurFbKi_c[15];
                                  /* Referenced by: '<S81>/lu1d_BatLimHiSoC1' */

/* 过压闭环控制Ki */
extern CALDATA const volatile float32 MEMS_ChrgCurFbKp_c[11];
                                   /* Referenced by: '<S81>/lu1d_BatLimHiSoC' */

/* 过压闭环控制KP */
extern CALDATA const volatile float32 MEMS_ChrgPwrFbKi_c[15];
                                  /* Referenced by: '<S46>/lu1d_BatLimHiSoC1' */

/* 充电功率闭环KI */
extern CALDATA const volatile float32 MEMS_ChrgPwrFbKp_c[11];
                                   /* Referenced by: '<S46>/lu1d_BatLimHiSoC' */

/* 充电功率闭环KP */
extern CALDATA const volatile float32 MEMS_DchaCurFbKi_c[15];
                                  /* Referenced by: '<S82>/lu1d_BatLimHiSoC1' */

/* 欠压电压闭环KI */
extern CALDATA const volatile float32 MEMS_DchaCurFbKp_c[11];
                                   /* Referenced by: '<S82>/lu1d_BatLimHiSoC' */

/* 欠压电压闭环KP */
extern CALDATA const volatile float32 MEMS_DchaPwrFbKi_c[15];
                                  /* Referenced by: '<S64>/lu1d_BatLimHiSoC1' */

/* 放电功率闭环KI */
extern CALDATA const volatile float32 MEMS_DchaPwrFbKp_c[11];
                                   /* Referenced by: '<S64>/lu1d_BatLimHiSoC' */

/* 放电功率闭环KP */
extern CALDATA const volatile float32 MEMS_HVBatMaxChrgPwrSOC_kW[7];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c8' */

/* 充电SOC功率限制（目前暂未使用） */
extern CALDATA const volatile float32 MEMS_HVBatMaxDchaPwrSOC_kW[7];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c6' */

/* 放电SOC限制功率(目前暂未使用) */
extern CALDATA const volatile float32 MEMS_MaxConChrgCurOfst_A[8];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c1' */

/* Con持续回收电流偏移 */
extern CALDATA const volatile float32 MEMS_MaxConDchaCurOfst_A[8];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c1' */

/* 放电-持续电流偏移 */
extern CALDATA const volatile float32 MEMS_MaxInsChrgCurOfst_A[8];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c7' */

/* Ins瞬时回收电流偏移 */
extern CALDATA const volatile float32 MEMS_MaxInsChrgCurrFac_c[100];
                  /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurrFac_c' */

/* VCU修正不同Pack类型回收系数 */
extern CALDATA const volatile float32 MEMS_MaxInsChrgCurr_A[170];
                     /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

/* VCU限制Ins瞬时回收电流 */
extern CALDATA const volatile float32 MEMS_MaxInsDchaCurOfst_A[8];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c2' */

/* 放电-瞬时电流偏移 */
extern CALDATA const volatile float32 MEMS_MaxInsDchaCurrFac_c[100];
                  /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurrFac_c' */

/* VCU修正不同类型Pack放电系数 */
extern CALDATA const volatile float32 MEMS_MaxInsDchaCurr_A[170];
                     /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

/* VCU限制Ins瞬时放电电流 */
extern CALDATA const volatile float32 MHVM_BMSCelMaxVol_mV[10];
                              /* Referenced by: '<S750>/MHVM_BMSCelMaxVol_mV' */

/* 交直流充电截止单体电压 */
extern CALDATA const volatile float32 MHVM_BMSTotMaxVol_V[10];
                               /* Referenced by: '<S750>/MHVM_BMSTotMaxVol_V' */

/* 交直流充电截止总电压 */
extern CALDATA const volatile float32 MHVM_MaxChrgCurntDC_A[10];
                             /* Referenced by: '<S750>/MHVM_MaxChrgCurntDC_A' */

/* DC直流充电最大电流 */
extern CALDATA const volatile float32 MHVM_MaxChrgVoltDC_V[10];
                              /* Referenced by: '<S750>/MHVM_MaxChrgVoltDC_V' */

/* DC直流充电最大电压 */
extern CALDATA const volatile float32 MIBS_BMSBatSOCExtrmLo_pct[10];
                        /* Referenced by: '<S1002>/MIBS_BMSBatSOCExtrmLo_pct' */

/* 动力电池SOC极低，禁止或退出IBS补电_versteckt */
extern CALDATA const volatile float32 MIBS_IBSEnMinSOC_pct[10];
                             /* Referenced by: '<S1002>/MIBS_IBSEnMinSOC_pct' */

/* IBS补电动力电池SOC阈值_versteckt */
extern CALDATA const volatile uint16 MIBS_NextRtcWupThr_min[60];
                           /* Referenced by: '<S1003>/MIBS_NextRtcWupThr_min' */

/* IBS下一次RTC唤醒时间阈值_versteckt */
extern CALDATA const volatile uint16 MIBS_WupChgTmThr2_min[60];
                             /* Referenced by: '<S1003>/MIBS_WupChgTmThr_min' */

/* IBS补电时间阈值2_versteckt */
extern CALDATA const volatile float32 MIPC_AccPedBckLsh_pct[12];
                                      /* Referenced by: '<S876>/Lookup Table' */
extern CALDATA const volatile float32 MIPC_TireRadius_m[6];
                                     /* Referenced by: '<S874>/TireSizeTable' */
extern CALDATA const volatile float32 MRME_CHTCStdRmnMil_km[120];
                             /* Referenced by: '<S951>/MRME_CHTCStdRmnMil_km' */

/* 标准续航CHTC查表值 */
extern CALDATA const volatile float32 MRME_DchaRmnMilEstChgStp_c[60];
                            /* Referenced by: '<S979>/MRME_DynEstRmnChgStp_c' */

/* 动态续航变化速率修正系数（默认以1km为基准） */
extern CALDATA const volatile float32 MRME_WLTPStdDwLimFac_c[6];
                               /* Referenced by: '<S960>/MRME_WLTPDwLimFac_c' */

/* 基于标准续航WLTP最小下限系数(使用电芯温度修正) */
extern CALDATA const volatile float32 MRME_WLTPStdPwrCnsm_kWh100km[10];/* Referenced by: '<S955>/  ' */

/* 标准工况100km电耗（按照100km折算） */
extern CALDATA const volatile float32 MRME_WLTPStdRmnMil_km[120];
                             /* Referenced by: '<S960>/MRME_WLTPStdRmnMil_km' */

/* 标准续航WLTP查表值 */
extern CALDATA const volatile float32 MRME_WLTPStdSOCCnsm_pct100km[10];
                     /* Referenced by: '<S960>/MRME_WLTPStdSOCCnsm_pct100km ' */

/* 标准工况SOC消耗（按100km折算） */
extern CALDATA const volatile float32 MTQC_RegenMaxTqDecRate_Nmps[20];
                   /* Referenced by: '<S1261>/MTQD_TqRateLimEndErr_Nm_IntTbl' */
extern CALDATA const volatile float32 MTQC_RegenMaxTqIncRate_Nmps[8];
                             /* Referenced by: '<S1261>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlEndPstn_mps2[14];
                            /* Referenced by: '<S1296>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlS_mps2[14];
                             /* Referenced by: '<S1296>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlW_mps2[14];
                            /* Referenced by: '<S1296>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MTQD_AdaptCstDsrdTqKi_c[225];
                      /* Referenced by: '<S1296>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MTQD_AdaptCstDsrdTqKp_c[15];
                      /* Referenced by: '<S1296>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MTQD_AdaptCstMaxTqWhl_Nm[14];
                            /* Referenced by: '<S1292>/MTQD_CstTqReqWhlS_Nm4' */
extern CALDATA const volatile float32 MTQD_AdaptCstMinTqWhl_Nm[14];
                            /* Referenced by: '<S1292>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQD_CrpTqReqWhlD_Nm[10];
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlD_Nm' */
extern CALDATA const volatile float32 MTQD_CrpTqReqWhlR_Nm[10];
                      /* Referenced by: '<S1282>/Lookup_MTQD_CrpTqReqWhlR_Nm' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnA_pct[15];
                            /* Referenced by: '<S1291>/MTQD_CstTqReqWhlA_Nm1' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnS_pct[15];
                            /* Referenced by: '<S1291>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnV_pct[14];
                                /* Referenced by: '<S1291>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnW_pct[15];
                            /* Referenced by: '<S1291>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlInc_Nmps[8];
                            /* Referenced by: '<S1293>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlOff_Nm[70];
                          /* Referenced by: '<S1290>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlR_Nm[12];
                                /* Referenced by: '<S1290>/1-D Lookup Table2' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlS_Nm[14];
                             /* Referenced by: '<S1290>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlV_Nm[14];
                                /* Referenced by: '<S1290>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlW_Nm[14];
                            /* Referenced by: '<S1290>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MTQD_FwdFullPedDrvTqWhlSprt_Nm[19];
                                /* Referenced by: '<S1283>/MTQD_PTBaseTq_Nm1' */
extern CALDATA const volatile float32 MTQD_FwdFullPedDrvTqWhl_Nm[19];
                                 /* Referenced by: '<S1283>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MTQD_FwdPedMapEco_pct[378];
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct1' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpEco_pct[42];
                                /* Referenced by: '<S1283>/2-D Lookup Table1' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpNorm_pct[42];
                                /* Referenced by: '<S1283>/2-D Lookup Table3' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpSnow_pct[42];
                                 /* Referenced by: '<S1283>/2-D Lookup Table' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpSpt_pct[42];
                                /* Referenced by: '<S1283>/2-D Lookup Table2' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNorm_pct[378];
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct3' */
extern CALDATA const volatile float32 MTQD_FwdPedMapSnow_pct[378];
                          /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 MTQD_FwdPedMapSpt_pct[378];
                         /* Referenced by: '<S1283>/MTQD_PedMapBasTqEco_pct2' */
extern CALDATA const volatile float32 MTQD_LimpHomeMaxTq_Nm[8];
                            /* Referenced by: '<S1278>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQD_RevFullPedDrvTqWhl_Nm[19];
                                 /* Referenced by: '<S1285>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MTQD_RevPedMap_pct[231];
                          /* Referenced by: '<S1285>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 MTQD_TqDrtFacBrkPedAccOff_c[9];
                      /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOff_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacBrkPedAccOn_c[45];
                       /* Referenced by: '<S1322>/MTQD_BrkPdlTqDerateAccOn_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacHiddenLmtPwr_c[7];
               /* Referenced by: '<S1325>/Lookup_MTQD_TqDrtFacHiddenLmtPwr_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacLimpHome_c[7];
                /* Referenced by: '<S1324>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacLmtPerfmn_c[8];
                /* Referenced by: '<S1323>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacMotorSpd_c[5];
                                 /* Referenced by: '<S1320>/MTQD_TMOverDrt_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl1_c[7];
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl2_c[7];
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl3_c[7];
                /* Referenced by: '<S1326>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdEco_c[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdNorm_c[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdRev_c[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c4' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdSnow_c[6];
                 /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdSpt_c[6];
                /* Referenced by: '<S1327>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 MTQD_WhlSpdDiffMaxTqFac_c[10];
                             /* Referenced by: '<S1278>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_WhlSpdDiffMaxTq_Nm[10];
                            /* Referenced by: '<S1278>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MTQF_DecEndRateFiltTmSMode_s[12];
                             /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQF_DecEndRateFiltTm_s[12];
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm1' */

/* torque decrease rate filter time in ending phase */
extern CALDATA const volatile float32 MTQF_DecStartRateFiltTmACC_s[12];
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQF_DecStartRateFiltTmSMode_s[12];
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQF_DecStartRateFiltTm_s[12];
                            /* Referenced by: '<S1339>/MTQD_CstTqReqWhlS_Nm4' */

/* torque decrease rate filter time in starting phase */
extern CALDATA const volatile float32 MTQF_IncEndRateFiltTmSMode_s[12];
                             /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQF_IncEndRateFiltTm_s[12];
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm1' */

/* torque increase rate filter time in ending phase */
extern CALDATA const volatile float32 MTQF_IncStartRateFiltTmACC_s[12];
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQF_IncStartRateFiltTmSMode_s[12];
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQF_IncStartRateFiltTm_s[12];
                            /* Referenced by: '<S1340>/MTQD_CstTqReqWhlS_Nm4' */

/* torque increase rate filter time in starting phase */
extern CALDATA const volatile float32 MTQF_TipOutTqDecRateCoeff_rat[8];
                                /* Referenced by: '<S1339>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxACC_Nmps[8];
                                    /* Referenced by: '<S1339>/Lookup Table5' */

/* Max torque decreasing change rate in ACC */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxE_Nmps[156];
                   /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* Max torque decreasing change rate in Eco */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxN_Nmps[156];
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* Max torque decreasing change rate in Normal */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxRegenE_Nmps[91];
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl3' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxRegenN_Nmps[91];
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl5' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxRegenS_Nmps[91];
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl4' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxS_Nmps[156];
                  /* Referenced by: '<S1339>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* Max torque decreasing change rate in Sport */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxACC_Nmps[8];
                                    /* Referenced by: '<S1340>/Lookup Table5' */

/* Max torque increasing change rate in ACC */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxE_Nmps[156];
                   /* Referenced by: '<S1340>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* Max torque increasing change rate in Eco */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxN_Nmps[156];
                  /* Referenced by: '<S1340>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* Max torque increasing change rate in Normal */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxS_Nmps[156];
                  /* Referenced by: '<S1340>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* Max torque increasing change rate in Sport */
extern CALDATA const volatile float32 MTQF_TqRateLimEndErrE_Nm[154];
                   /* Referenced by: '<S1338>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* torque ending error in E */
extern CALDATA const volatile float32 MTQF_TqRateLimEndErrN_Nm[154];
                  /* Referenced by: '<S1338>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* torque ending error in N */
extern CALDATA const volatile float32 MTQF_TqRateLimEndErrS_Nm[154];
                  /* Referenced by: '<S1338>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* torque ending error in S */
extern CALDATA const volatile float32 MTQR_ASDSpdFiltHi_s[8];
                                 /* Referenced by: '<S1366>/1-D Lookup Table' */
extern CALDATA const volatile float32 MTQR_ASDTqGain_c[8];
                                 /* Referenced by: '<S1367>/1-D Lookup Table' */
extern CALDATA const volatile float32 MTZX_AZDecRate_Nmps[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table4' */
extern CALDATA const volatile float32 MTZX_AZIncRate_Nmps[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table3' */
extern CALDATA const volatile float32 MTZX_AZRngDec_Nm[12];
                         /* Referenced by: '<S1398>/MTZX_AZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_AZRngInc_Nm[12];
                          /* Referenced by: '<S1398>/MTZX_AZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_BZDecRate_Nmps[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table2' */
extern CALDATA const volatile float32 MTZX_BZIncRate_Nmps[11];
                                /* Referenced by: '<S1398>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTZX_BZRngDec_Nm[12];
                         /* Referenced by: '<S1398>/MTZX_BZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_BZRngInc_Nm[12];
                          /* Referenced by: '<S1398>/MTZX_BZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_RampDecRate_Nmps[10];
                                /* Referenced by: '<S1397>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTZX_RampIncRate_Nmps[10];
                                /* Referenced by: '<S1397>/1-D Lookup Table2' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstDecACC_Nm[12];
                   /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipOutTMOly_Nm5' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstDec_Nm[80];
                                /* Referenced by: '<S1398>/2-D Lookup Table1' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstIncACC_Nm[12];
                    /* Referenced by: '<S1398>/MTZX_ZeroTqOfstTipInTMOly_Nm1' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstInc_Nm[80];
                                 /* Referenced by: '<S1398>/2-D Lookup Table' */
extern CALDATA const volatile float32 MTZX_ZeroXTmACC_s[10];
                        /* Referenced by: '<S1398>/MTZX_ZeroXTmTipInTMOly_s1' */
extern CALDATA const volatile float32 MTZX_ZeroXTmDec_s[80];
                                /* Referenced by: '<S1398>/2-D Lookup Table2' */
extern CALDATA const volatile float32 MTZX_ZeroXTmInc_s[80];
                                /* Referenced by: '<S1398>/2-D Lookup Table3' */
extern CALDATA const volatile float32 MVTM_ActPwrBacklash_kW[8];/* Referenced by: '<S1454>/Dbnd' */
extern CALDATA const volatile float32 MVTM_MotorMaxDrvTqWT_Nm[23];
                                 /* Referenced by: '<S1449>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MVTM_MotorSpdFiltCoeff_rat[8];
                      /* Referenced by: '<S1440>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 MVTM_VehSpdFiltCoeff_rat[8];
                  /* Referenced by: '<S1440>/Lookup_MVTM_VehSpdFiltCoeff_rat' */

#endif                                 /* RTW_HEADER_calPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
