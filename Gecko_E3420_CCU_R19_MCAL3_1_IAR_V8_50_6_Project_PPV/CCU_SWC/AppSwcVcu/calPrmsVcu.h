/*
 * File: calPrmsVcu.h
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.619
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov 14 16:25:54 2024
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
                                /* Referenced by: '<S1230>/MTQD_TMOverDrt_c1' */
extern CALDATA const volatile float32 ACPT_MotorSpdFiltCoeff_X_rpm[8];
                      /* Referenced by: '<S1230>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqGen_X_kW[22];
                          /* Referenced by: '<S1230>/MCPT_Pwr2MotorTqMot_Nm1' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqGen_Y_rpm[28];
                          /* Referenced by: '<S1230>/MCPT_Pwr2MotorTqMot_Nm1' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqMot_X_kW[21];
                           /* Referenced by: '<S1230>/MCPT_Pwr2MotorTqMot_Nm' */
extern CALDATA const volatile float32 ACPT_Pwr2MotorTqMot_Y_rpm[28];
                           /* Referenced by: '<S1230>/MCPT_Pwr2MotorTqMot_Nm' */
extern CALDATA const volatile float32 ACPT_TqDrtFacIgbtTemp_X_C[8];
                                /* Referenced by: '<S1230>/MTQD_TMOverDrt_c2' */
extern CALDATA const volatile float32 ACPT_TqDrtFacMotorTemp_X_C[8];
                                /* Referenced by: '<S1230>/MTQD_TMOverDrt_c4' */
extern CALDATA const volatile float32 ADAC_ACCDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1258>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ADAC_ACCDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1258>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ADAC_ACCDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1258>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ADAC_ACCOvrdTq_X_kph[7];
                        /* Referenced by: '<S1252>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnDec_X_mps2[12];
                /* Referenced by: '<S1274>/Lookup_MTQD_CstRegenTqReqWhlR_Nm1' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnDeltaSpd_X_kph[21];
               /* Referenced by: '<S1274>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnInc_X_mps2[12];
                 /* Referenced by: '<S1274>/Lookup_MTQD_CstRegenTqReqWhlR_Nm' */
extern CALDATA const volatile float32 ADAC_CCDsrdAcceltnSpd_X_kph[6];
                /* Referenced by: '<S1274>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */
extern CALDATA const volatile float32 ADAC_CCDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1281>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ADAC_CCDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1281>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ADAC_CCDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1281>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ADAC_CCMaxDrgTqWhl_X_kph[14];
                        /* Referenced by: '<S1283>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ADAC_CCSpdStabOfst_X_kph[8];
                        /* Referenced by: '<S1310>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ADAC_FullPedDrvTqWhl_X_kph[23];
                                 /* Referenced by: '<S1247>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 ADAC_HDCDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1347>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ADAC_HDCDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1347>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ADAC_HDCDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1347>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ADAC_HDCTgtAcceltnDeltaSpd_X_kph[16];
                                /* Referenced by: '<S1345>/1-D Lookup Table3' */
extern CALDATA const volatile float32 ADAC_INVMaxDrgTqWhl_X_kph[12];
                                /* Referenced by: '<S1247>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ADAC_NonDrvnSpdFiltCoeff_X_kph[7];
                 /* Referenced by: '<S1272>/Lookup_MVTM_VehSpdFiltCoeff_rat1' */
extern CALDATA const volatile float32 ADSA_DeceltnIdxAvg_X_pct[10];
                       /* Referenced by: '<S17>/MTQD_ZeroTqOfstTipInTMOly_Nm' */
extern CALDATA const volatile float32 ADSA_SprtIdxVehSpd_X_kph[15];
                          /* Referenced by: '<S17>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 AEMS_CellTempMinFac_X_C[5];
                                  /* Referenced by: '<S31>/MTQD_TMOverDrt_c5' */
extern CALDATA const volatile float32 AEMS_ChrgCurFbKi_X_mV[15];
                                  /* Referenced by: '<S82>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_ChrgCurFbKp_X_mV[11];
                                   /* Referenced by: '<S82>/lu1d_BatLimHiSoC' */
extern CALDATA const volatile float32 AEMS_ChrgPwrFbKi_X_kW[15];
                                  /* Referenced by: '<S46>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_ChrgPwrFbKp_X_kW[11];
                                   /* Referenced by: '<S46>/lu1d_BatLimHiSoC' */
extern CALDATA const volatile float32 AEMS_DchaCurFbKi_X_mV[15];
                                  /* Referenced by: '<S83>/lu1d_BatLimHiSoC1' */
extern CALDATA const volatile float32 AEMS_DchaCurFbKp_X_mV[11];
                                   /* Referenced by: '<S83>/lu1d_BatLimHiSoC' */
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
                                                             * '<S1032>/MIBS_NextRtcWupThr_min'
                                                             * '<S1032>/MIBS_WupChgTmThr_min'
                                                             */

/* �����¶ȣ�X�ᣩ_versteckt */
extern CALDATA const volatile float32 AIBS_KL30_Y_V[10];/* Referenced by:
                                                         * '<S1032>/MIBS_NextRtcWupThr_min'
                                                         * '<S1032>/MIBS_WupChgTmThr_min'
                                                         */

/* KL30��ѹ��Y�ᣩ_versteckt */
extern CALDATA const volatile float32 AIPC_AccPedBckLsh_X_pct[12];
                                      /* Referenced by: '<S905>/Lookup Table' */
extern CALDATA const volatile uint8 AIPC_TireRadius_X_enum[6];
                                     /* Referenced by: '<S903>/TireSizeTable' */
extern CALDATA const volatile float32 ARME_BMSBatCellTempMin_X_C[6];/* Referenced by:
                                                                     * '<S989>/MRME_WLTPDwLimFac_c'
                                                                     * '<S1008>/MRME_DynEstRmnChgStp_c'
                                                                     */

/* BMS��о��С�¶� */
extern CALDATA const volatile float32 ARME_BMSBatRptSOC_Y_pct[12];/* Referenced by:
                                                                   * '<S980>/MRME_CHTCStdRmnMil_km'
                                                                   * '<S989>/MRME_WLTPStdRmnMil_km'
                                                                   */

/* ��׼�������RPTSOCֵ */
extern CALDATA const volatile float32 ARME_EstTgtSubDynEstErr_Y_km[10];
                           /* Referenced by: '<S1008>/MRME_DynEstRmnChgStp_c' */

/* Ŀ��������ʵ������ֵ��ֵ */
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
                                                                * '<S101>/MDAG_CellTempLoThr_C'
                                                                * '<S101>/MDAG_CellUndrVoltThr1_mV'
                                                                * '<S101>/MDAG_CellUndrVoltThr2_mV'
                                                                * '<S764>/MHVM_BMSCelMaxVol_mV'
                                                                * '<S764>/MHVM_BMSTotMaxVol_V'
                                                                * '<S764>/MHVM_MaxChrgCurntDC_A'
                                                                * '<S764>/MHVM_MaxChrgVoltDC_V'
                                                                * '<S980>/MRME_CHTCStdRmnMil_km'
                                                                * '<S1031>/MIBS_BMSBatSOCExtrmLo_pct'
                                                                * '<S1031>/MIBS_IBSEnMinSOC_pct'
                                                                * '<S82>/PwrDrt'
                                                                * '<S83>/PwrDrt'
                                                                * '<S83>/PwrDrt1'
                                                                * '<S104>/BMS_BMSCTL_LMPRECSOC1_CAL'
                                                                * '<S104>/BMS_BMSCTL_LMPRECSOC2_CAL'
                                                                * '<S104>/BMS_BMSCTL_LMPSOC1_CAL'
                                                                * '<S104>/BMS_BMSCTL_LMPSOC2_CAL'
                                                                * '<S984>/  '
                                                                * '<S989>/MRME_WLTPStdRmnMil_km'
                                                                * '<S989>/MRME_WLTPStdSOCCnsm_pct100km '
                                                                */
extern CALDATA const volatile float32 ATQC_RegenMaxTqDecRate_X_kph[4];
                /* Referenced by: '<S1374>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */
extern CALDATA const volatile float32 ATQC_RegenMaxTqDecRate_Y_pct[5];
               /* Referenced by: '<S1374>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */
extern CALDATA const volatile float32 ATQC_RegenMaxTqIncRate_X_Nm[8];
                        /* Referenced by: '<S1374>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKi_X_N[15];
                          /* Referenced by: '<S1409>/ADAC_CCSDsrdTqKi_X_N_PL' */
extern CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKi_Y_mps2[15];
                       /* Referenced by: '<S1409>/ADAC_CCSDsrdTqKi_Y_mps2_PL' */
extern CALDATA const volatile float32 ATQD_AdaptCstDsrdTqKp_X_mps2[15];
                       /* Referenced by: '<S1409>/ADAC_CCSDsrdTqKp_X_mps2_PL' */
extern CALDATA const volatile float32 ATQD_AdaptCstVehSpd_X_kph[14];/* Referenced by:
                                                                     * '<S1405>/ATQD_RegenTqBrk_X_kph_PL'
                                                                     * '<S1409>/ATQD_RegenTqBrk_X_kph_PL1'
                                                                     */
extern CALDATA const volatile float32 ATQD_CrpTqReqWhlD_X_kph[10];
                      /* Referenced by: '<S1395>/Lookup_MTQD_CrpTqReqWhlD_Nm' */
extern CALDATA const volatile float32 ATQD_CrpTqReqWhlR_X_kph[10];
                      /* Referenced by: '<S1395>/Lookup_MTQD_CrpTqReqWhlR_Nm' */
extern CALDATA const volatile float32 ATQD_CstRegenEndPstnV_X_kph[14];
                                /* Referenced by: '<S1404>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATQD_CstRegenEndPstn_X_kph[15];
                        /* Referenced by: '<S1404>/ATQD_RegenTqBrk_X_kph_PL2' */
extern CALDATA const volatile float32 ATQD_CstRegenRateAccPed_X_pct[8];
                        /* Referenced by: '<S1406>/ATQD_RegenTqBrk_X_kph_PL2' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlD_X_kph[14];
                        /* Referenced by: '<S1403>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlOff_X_pct[5];
                          /* Referenced by: '<S1403>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlOff_Y_kph[14];
                          /* Referenced by: '<S1403>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlR_X_kph[12];
                                /* Referenced by: '<S1403>/1-D Lookup Table2' */
extern CALDATA const volatile float32 ATQD_CstRegenTqReqWhlV_X_kph[14];
                                /* Referenced by: '<S1403>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATQD_FwdFullPedDrvTqWhl_X_kph[19];/* Referenced by:
                                                                      * '<S1396>/MTQD_PTBaseTq_Nm'
                                                                      * '<S1396>/MTQD_PTBaseTq_Nm1'
                                                                      */
extern CALDATA const volatile float32 ATQD_FwdPedMapEco_X_kph[18];
                         /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct1' */
extern CALDATA const volatile float32 ATQD_FwdPedMapEco_Y_pct[21];/* Referenced by:
                                                                   * '<S1396>/MTQD_PedMapBasTqEco_pct1'
                                                                   * '<S1396>/2-D Lookup Table1'
                                                                   */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpEco_X_kph[2];
                                /* Referenced by: '<S1396>/2-D Lookup Table1' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpNorm_X_kph[2];
                                /* Referenced by: '<S1396>/2-D Lookup Table3' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpSnow_X_kph[2];
                                 /* Referenced by: '<S1396>/2-D Lookup Table' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNoCrpSpt_X_kph[2];
                                /* Referenced by: '<S1396>/2-D Lookup Table2' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNorm_X_kph[18];
                         /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct3' */
extern CALDATA const volatile float32 ATQD_FwdPedMapNorm_Y_pct[21];/* Referenced by:
                                                                    * '<S1396>/MTQD_PedMapBasTqEco_pct3'
                                                                    * '<S1396>/2-D Lookup Table3'
                                                                    */
extern CALDATA const volatile float32 ATQD_FwdPedMapSnow_X_kph[18];
                          /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_FwdPedMapSnow_Y_pct[21];/* Referenced by:
                                                                    * '<S1396>/MTQD_PedMapBasTqEco_pct'
                                                                    * '<S1396>/2-D Lookup Table'
                                                                    */
extern CALDATA const volatile float32 ATQD_FwdPedMapSpt_X_kph[18];
                         /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct2' */
extern CALDATA const volatile float32 ATQD_FwdPedMapSpt_Y_pct[21];/* Referenced by:
                                                                   * '<S1396>/MTQD_PedMapBasTqEco_pct2'
                                                                   * '<S1396>/2-D Lookup Table2'
                                                                   */
extern CALDATA const volatile float32 ATQD_LimpHomeMaxTq_X_kph[8];
                        /* Referenced by: '<S1391>/ATQD_RegenTqBrk_X_kph_PL2' */
extern CALDATA const volatile float32 ATQD_RevFullPedDrvTqWhl_X_kph[19];
                                 /* Referenced by: '<S1398>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 ATQD_RevPedMap_X_kph[11];
                          /* Referenced by: '<S1398>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_RevPedMap_Y_pct[21];
                          /* Referenced by: '<S1398>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOff_X_pct[9];
                      /* Referenced by: '<S1435>/MTQD_BrkPdlTqDerateAccOff_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOn_X_pct[9];
                       /* Referenced by: '<S1435>/MTQD_BrkPdlTqDerateAccOn_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacBrkPedAccOn_Y_kph[5];
                       /* Referenced by: '<S1435>/MTQD_BrkPdlTqDerateAccOn_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacHiddenLmtPwr_X_kph[7];
               /* Referenced by: '<S1438>/Lookup_MTQD_TqDrtFacHiddenLmtPwr_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacLimpHome_X_kph[7];
                /* Referenced by: '<S1437>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacLmtPerfmn_X_kph[8];
                /* Referenced by: '<S1436>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacMotorSpd_X_rpm[5];
                                 /* Referenced by: '<S1433>/MTQD_TMOverDrt_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl1_X_kph[7];
                /* Referenced by: '<S1439>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl2_X_kph[7];
                /* Referenced by: '<S1439>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 ATQD_TqDrtFacTboxLmtLvl3_X_kph[7];
                /* Referenced by: '<S1439>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdEco_X_kph[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdNorm_X_kph[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdRev_X_kph[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c4' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdSnow_X_kph[6];
                 /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c' */
extern CALDATA const volatile float32 ATQD_TqDrtFacVehSpdSpt_X_kph[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 ATQD_WhlSpdDiffMaxTq_X_kph[10];
                        /* Referenced by: '<S1391>/ATQD_RegenTqBrk_X_kph_PL1' */
extern CALDATA const volatile float32 ATQF_DecRateFiltTm_X_Nmps[12];
                        /* Referenced by: '<S1452>/ATQD_RegenTqBrk_X_kph_PL1' */

/* torque decrease rate filter time in starting phase, x axle */
extern CALDATA const volatile float32 ATQF_IncRateFiltTm_X_Nmps[12];
                        /* Referenced by: '<S1453>/ATQD_RegenTqBrk_X_kph_PL1' */

/* torque increase rate filter time in starting phase, x axle */
extern CALDATA const volatile float32 ATQF_TipOutTqDecRateCoeff_Nm[8];
                                /* Referenced by: '<S1452>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATQF_TqRateDecMaxACC_X_Nm[8];
                                    /* Referenced by: '<S1452>/Lookup Table5' */
extern CALDATA const volatile float32 ATQF_TqRateDecMaxRegen_X_pct[7];
               /* Referenced by: '<S1452>/ATQD_TqRateLimEndErrIncE_X_pct_PL6' */
extern CALDATA const volatile float32 ATQF_TqRateDecMaxRegen_Y_kph[13];
               /* Referenced by: '<S1452>/ATQD_TqRateLimEndErrIncE_X_pct_PL7' */
extern CALDATA const volatile float32 ATQF_TqRateDecMax_X_pct[12];
                /* Referenced by: '<S1452>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* X axis of max torque decreasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateDecMax_Y_kph[13];
               /* Referenced by: '<S1452>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* Y axis of max torque decreasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateIncMaxACC_X_Nm[8];
                                    /* Referenced by: '<S1453>/Lookup Table5' */
extern CALDATA const volatile float32 ATQF_TqRateIncMax_X_pct[12];
                /* Referenced by: '<S1453>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* X axis of max torque increasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateIncMax_Y_kph[13];
               /* Referenced by: '<S1453>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* Y axis of max torque increasing change rate */
extern CALDATA const volatile float32 ATQF_TqRateLimEndErr_X_pct[14];
                /* Referenced by: '<S1451>/ATQD_TqRateLimEndErrIncE_X_pct_PL' */

/* pedal position including acc and brk */
extern CALDATA const volatile float32 ATQF_TqRateLimEndErr_Y_kph[11];
               /* Referenced by: '<S1451>/ATQD_TqRateLimEndErrIncE_X_pct_PL1' */

/* vehicle speed */
extern CALDATA const volatile float32 ATQR_ASDSpdFiltHi_X_rpm[8];
                                 /* Referenced by: '<S1479>/1-D Lookup Table' */
extern CALDATA const volatile float32 ATQR_ASDTqGain_X_kph[8];
                                 /* Referenced by: '<S1480>/1-D Lookup Table' */
extern CALDATA const volatile float32 ATZX_AZDecRate_X_Nm[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table4' */
extern CALDATA const volatile float32 ATZX_AZIncRate_X_Nm[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table3' */
extern CALDATA const volatile float32 ATZX_AZRngDec_X_kph[12];
                         /* Referenced by: '<S1511>/MTZX_AZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_AZRngInc_X_kph[12];
                          /* Referenced by: '<S1511>/MTZX_AZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_BZDecRate_X_Nm[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table2' */
extern CALDATA const volatile float32 ATZX_BZIncRate_X_Nm[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATZX_BZRngDec_X_kph[12];
                         /* Referenced by: '<S1511>/MTZX_BZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_BZRngInc_X_kph[12];
                          /* Referenced by: '<S1511>/MTZX_BZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 ATZX_OPDSlopTq_X_Nm[5];/* Referenced by:
                                                              * '<S1511>/2-D Lookup Table'
                                                              * '<S1511>/2-D Lookup Table1'
                                                              * '<S1511>/2-D Lookup Table2'
                                                              * '<S1511>/2-D Lookup Table3'
                                                              */
extern CALDATA const volatile float32 ATZX_RampDecRate_X_Nm[10];
                                /* Referenced by: '<S1510>/1-D Lookup Table1' */
extern CALDATA const volatile float32 ATZX_RampIncRate_X_Nm[10];
                                /* Referenced by: '<S1510>/1-D Lookup Table2' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstDecACC_X_kph[12];
                   /* Referenced by: '<S1511>/MTZX_ZeroTqOfstTipOutTMOly_Nm5' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstDec_Y_kph[16];
                                /* Referenced by: '<S1511>/2-D Lookup Table1' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstIncACC_X_kph[12];
                    /* Referenced by: '<S1511>/MTZX_ZeroTqOfstTipInTMOly_Nm1' */
extern CALDATA const volatile float32 ATZX_ZeroTqOfstInc_Y_kph[16];
                                 /* Referenced by: '<S1511>/2-D Lookup Table' */
extern CALDATA const volatile float32 ATZX_ZeroXTmACC_X_kph[10];
                        /* Referenced by: '<S1511>/MTZX_ZeroXTmTipInTMOly_s1' */
extern CALDATA const volatile float32 ATZX_ZeroXTmDec_Y_kph[16];
                                /* Referenced by: '<S1511>/2-D Lookup Table2' */
extern CALDATA const volatile float32 ATZX_ZeroXTmInc_Y_kph[16];
                                /* Referenced by: '<S1511>/2-D Lookup Table3' */
extern CALDATA const volatile float32 AVTM_ActPwrBacklash_X_kW[8];/* Referenced by: '<S1567>/Dbnd' */
extern CALDATA const volatile float32 AVTM_MotorMaxDrvTqWT_X_rpm[23];
                                 /* Referenced by: '<S1562>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 AVTM_MotorSpdFiltCoeff_X_rpm[8];
                      /* Referenced by: '<S1553>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 AVTM_VehSpdFiltCoeff_X_kph[8];
                  /* Referenced by: '<S1553>/Lookup_MVTM_VehSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 KCPT_GenMaxTqDecRate_Nmps;/* Referenced by: '<S1230>/Constant18' */
extern CALDATA const volatile float32 KCPT_GenMaxTqIncRate_Nmps;/* Referenced by: '<S1230>/Constant19' */
extern CALDATA const volatile float32 KCPT_MotMaxTqDecRate_Nmps;/* Referenced by: '<S1230>/Constant11' */
extern CALDATA const volatile float32 KCPT_MotMaxTqFiltAchvd_Nm;/* Referenced by:
                                                                 * '<S1230>/KCPT_MotorMaxTqFiltAchvd_Nm'
                                                                 * '<S1230>/KCPT_MotorMaxTqFiltAchvd_Nm1'
                                                                 */
extern CALDATA const volatile float32 KCPT_MotMaxTqIncRate_Nmps;/* Referenced by: '<S1230>/Constant3' */
extern CALDATA const volatile float32 KCPT_MotorDrgMaxTqAllwd_Nm;
                     /* Referenced by: '<S1230>/KCPT_MotorMaxTqFiltAchvd_Nm2' */
extern CALDATA const volatile float32 KCPT_MotorMaxTqFiltCoeff_c;/* Referenced by:
                                                                  * '<S1230>/KCPT_MotorMaxTqFiltCoeff_c'
                                                                  * '<S1230>/KCPT_MotorMaxTqFiltCoeff_c1'
                                                                  */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOffD_rpm;/* Referenced by: '<S1230>/Constant8' */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOffR_rpm;/* Referenced by: '<S1230>/Constant10' */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOnD_rpm;/* Referenced by: '<S1230>/Constant9' */
extern CALDATA const volatile float32 KCPT_MotorRvrsSpdOnR_rpm;/* Referenced by: '<S1230>/Constant5' */
extern CALDATA const volatile float32 KDAC_ABSActvDlyTm4CC_s;/* Referenced by: '<S1294>/Constant2' */
extern CALDATA const volatile float32 KDAC_ACCDsrdTqIMax_N;
                                      /* Referenced by: '<S1258>/Saturation1' */
extern CALDATA const volatile float32 KDAC_ACCDsrdTqIMin_N;
                                      /* Referenced by: '<S1258>/Saturation1' */
extern CALDATA const volatile float32 KDAC_AccReqStopAllwdSpd_kph;
                        /* Referenced by: '<S1254>/KVTM_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile float32 KDAC_BrkPedPrsdOff_pct;
                           /* Referenced by: '<S1247>/KTQD_BrkPedPstnHi_pct1' */
extern CALDATA const volatile float32 KDAC_BrkPedPrsdOn_pct;
                            /* Referenced by: '<S1247>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile float32 KDAC_BrkTq2PresrCvrtCoeff_c;/* Referenced by:
                                                                   * '<S1560>/Constant18'
                                                                   * '<S1247>/Constant18'
                                                                   * '<S1346>/Constant18'
                                                                   */
extern CALDATA const volatile boolean KDAC_BypCruiseSdnCC_flg;
                        /* Referenced by: '<S1294>/KVTM_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile boolean KDAC_BypCruiseSdn_flg;
                        /* Referenced by: '<S1251>/KVTM_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile boolean KDAC_BypESPTqIntv_flg;
                        /* Referenced by: '<S1251>/KVTM_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile float32 KDAC_CCAccelPedPrsdOff_pct;
                       /* Referenced by: '<S1283>/KTQD_CstRegenVehSpdOn_kph1' */
extern CALDATA const volatile float32 KDAC_CCAccelPedPrsdOn_pct;
                        /* Referenced by: '<S1283>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KDAC_CCDsrdAcceltnMax_mps2;
                                      /* Referenced by: '<S1274>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdAcceltnMin_mps2;
                                      /* Referenced by: '<S1274>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqDecIDlyTm_s;/* Referenced by: '<S1283>/Constant4' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqIMax_N;
                                      /* Referenced by: '<S1281>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqIMin_N;
                                      /* Referenced by: '<S1281>/Saturation1' */
extern CALDATA const volatile float32 KDAC_CCDsrdTqIncIDlyTm_s;/* Referenced by: '<S1283>/Constant1' */
extern CALDATA const volatile float32 KDAC_CCHldISpdOverOff_kph;
                       /* Referenced by: '<S1283>/KTQD_CstRegenVehSpdOn_kph3' */
extern CALDATA const volatile float32 KDAC_CCHldISpdOverOn_kph;
                       /* Referenced by: '<S1283>/KTQD_CstRegenVehSpdOn_kph2' */
extern CALDATA const volatile float32 KDAC_CCMaxSpdOfst_kph;
                                      /* Referenced by: '<S1294>/Constant150' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdE_kph;/* Referenced by: '<S1321>/Constant3' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdN_kph;
                                      /* Referenced by: '<S1321>/Constant164' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdS_kph;/* Referenced by: '<S1321>/Constant4' */
extern CALDATA const volatile uint8 KDAC_CCMaxTgtSpdSnow_kph;/* Referenced by: '<S1321>/Constant8' */
extern CALDATA const volatile float32 KDAC_CCMinSpdOfst_kph;
                                      /* Referenced by: '<S1294>/Constant148' */
extern CALDATA const volatile uint8 KDAC_CCMinTgtSpd_kph;/* Referenced by: '<S1321>/Constant9' */
extern CALDATA const volatile float32 KDAC_CCOvrdTqOff_Nm;/* Referenced by: '<S1268>/Constant5' */
extern CALDATA const volatile float32 KDAC_CCOvrdTqOn_Nm;
                                      /* Referenced by: '<S1268>/Constant174' */
extern CALDATA const volatile uint8 KDAC_CCSpdChgLongDiv_cnt;
                         /* Referenced by: '<S1270>/KDAC_CCSpdChgLongDiv_cnt' */
extern CALDATA const volatile uint8 KDAC_CCSpdChgShort_kph;
                           /* Referenced by: '<S1270>/KDAC_CCSpdChgShort_kph' */
extern CALDATA const volatile float32 KDAC_CCTgtSpdChgRate_kphps;
                       /* Referenced by: '<S1270>/KDAC_CCTgtSpdChgRate_kphps' */
extern CALDATA const volatile float32 KDAC_CCTqReqWhlAchvd_Nm;
                              /* Referenced by: '<S1282>/KDAC_TapDwnTmOut_s2' */
extern CALDATA const volatile float32 KDAC_CCTqReqWhlDec_Nmps;
                              /* Referenced by: '<S1282>/KDAC_TapDwnTmOut_s1' */
extern CALDATA const volatile float32 KDAC_CCTqReqWhlInc_Nmps;
                              /* Referenced by: '<S1282>/KDAC_TapDwnTmOut_s3' */
extern CALDATA const volatile uint8 KDAC_CruzSetSwOpCntr_cnt;/* Referenced by: '<S1323>/Constant4' */
extern CALDATA const volatile float32 KDAC_CruzSetSwOpTm_s;
                             /* Referenced by: '<S1271>/KDAC_CruzSetSwOpTm_s' */
extern CALDATA const volatile float32 KDAC_DrvAsstTqSplitEHBMin_Nm;/* Referenced by: '<S1247>/Constant19' */
extern CALDATA const volatile float32 KDAC_ESCIntvDlyTm4CC_s;/* Referenced by: '<S1294>/Constant1' */
extern CALDATA const volatile float32 KDAC_ESPActvDlyTm4CC_s;/* Referenced by: '<S1294>/Constant3' */
extern CALDATA const volatile float32 KDAC_HDCActvSlopOff_pct;/* Referenced by: '<S1342>/Cnst7' */
extern CALDATA const volatile float32 KDAC_HDCActvSlopOn_pct;/* Referenced by: '<S1342>/Cnst5' */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdHiOfst_kph;/* Referenced by: '<S1342>/Cnst10' */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdHi_kph;/* Referenced by:
                                                           * '<S1342>/Cnst2'
                                                           * '<S1342>/Cnst3'
                                                           */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdLoOfst_kph;/* Referenced by: '<S1342>/Cnst11' */
extern CALDATA const volatile uint8 KDAC_HDCActvSpdLo_kph;/* Referenced by:
                                                           * '<S1342>/Cnst4'
                                                           * '<S1342>/Cnst6'
                                                           */
extern CALDATA const volatile float32 KDAC_HDCDsrdTqIMax_N;
                                      /* Referenced by: '<S1347>/Saturation1' */
extern CALDATA const volatile float32 KDAC_HDCDsrdTqIMin_N;
                                      /* Referenced by: '<S1347>/Saturation1' */
extern CALDATA const volatile boolean KDAC_HDCFuncEnbl_flg;/* Referenced by: '<S1342>/Cnst1' */
extern CALDATA const volatile uint8 KDAC_HDCStdbyAllwdSpd_kph;/* Referenced by:
                                                               * '<S1342>/Cnst'
                                                               * '<S1342>/Cnst9'
                                                               */
extern CALDATA const volatile float32 KDAC_HDCTgtAcceltnFiltCoeff_rat;/* Referenced by: '<S1345>/Cnst5' */
extern CALDATA const volatile float32 KDAC_HDCTqReqWhlAchvd_Nm;/* Referenced by:
                                                                * '<S1247>/KDAC_TapDwnTmOut_s2'
                                                                * '<S1346>/KDAC_TapDwnTmOut_s2'
                                                                */
extern CALDATA const volatile float32 KDAC_HDCTqReqWhlDec_Nmps;/* Referenced by:
                                                                * '<S1247>/KDAC_TapDwnTmOut_s1'
                                                                * '<S1346>/KDAC_TapDwnTmOut_s1'
                                                                */
extern CALDATA const volatile float32 KDAC_HDCTqReqWhlInc_Nmps;/* Referenced by:
                                                                * '<S1247>/KDAC_TapDwnTmOut_s3'
                                                                * '<S1346>/KDAC_TapDwnTmOut_s3'
                                                                */
extern CALDATA const volatile boolean KDAC_OPDTqRespFst_flg;/* Referenced by: '<S1247>/Constant15' */
extern CALDATA const volatile boolean KDAC_OPDTqRespSprt_flg;/* Referenced by: '<S1247>/Constant14' */
extern CALDATA const volatile float32 KDAC_SpdOutRngDlyTm4CC_s;
                                      /* Referenced by: '<S1294>/Constant164' */
extern CALDATA const volatile float32 KDAC_SpdStabDlyTm4CC_s;/* Referenced by: '<S1310>/Constant8' */
extern CALDATA const volatile float32 KDAC_SpdUnstabDlyTm4CC_s;/* Referenced by: '<S1310>/Constant4' */
extern CALDATA const volatile float32 KDAC_TCSActvDlyTm4CC_s;/* Referenced by: '<S1294>/Constant4' */
extern CALDATA const volatile float32 KDAC_TapDwnTmOut_s;
                               /* Referenced by: '<S1270>/KDAC_TapDwnTmOut_s' */
extern CALDATA const volatile float32 KDAC_TapUpTmOut_s;
                                /* Referenced by: '<S1270>/KDAC_TapUpTmOut_s' */
extern CALDATA const volatile float32 KDAC_VehResistA_fac;/* Referenced by:
                                                           * '<S1162>/KDAC_TapDwnTmOut_s4'
                                                           * '<S1280>/KDAC_TapDwnTmOut_s3'
                                                           */
extern CALDATA const volatile float32 KDAC_VehResistB_fac;/* Referenced by:
                                                           * '<S1162>/KDAC_TapDwnTmOut_s3'
                                                           * '<S1280>/KDAC_TapDwnTmOut_s2'
                                                           */
extern CALDATA const volatile float32 KDAC_VehResistC_fac;/* Referenced by:
                                                           * '<S1162>/KDAC_TapDwnTmOut_s2'
                                                           * '<S1280>/KDAC_TapDwnTmOut_s1'
                                                           */
extern CALDATA const volatile float32 KDAC_VirtAccelPedPstnOff_pct;/* Referenced by: '<S1247>/Constant7' */
extern CALDATA const volatile float32 KDAC_VirtAccelPedPstnOn_pct;/* Referenced by: '<S1247>/Constant6' */
extern CALDATA const volatile float32 KDAC_WhlSlipDiffSpd4CC_kph;/* Referenced by:
                                                                  * '<S1294>/Constant174'
                                                                  * '<S1294>/Constant6'
                                                                  */
extern CALDATA const volatile float32 KDAC_WhlSlipDiffSpdOfst4CC_kph;/* Referenced by: '<S1294>/Constant5' */
extern CALDATA const volatile float32 KDAC_WhlSlipDlyTm4CC_s;/* Referenced by: '<S1294>/Constant8' */
extern CALDATA const volatile uint16 KDAG_ACCMCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s15' */
extern CALDATA const volatile uint16 KDAG_ACCMHVILActnMsk_enum;
                         /* Referenced by: '<S554>/KDAG_BMSCmdTmOutFailTm_s2' */

/* ѹ������ѹ�������϶��� */
extern CALDATA const volatile uint16 KDAG_ACCMLostCommActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s38' */

/* ACCMͨ�Ŷ�ʧ�����϶��� */
extern CALDATA const volatile uint16 KDAG_ACChrgStFailActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s24' */

/* ACChargeStateFail���϶��� */
extern CALDATA const volatile float32 KDAG_ACChrgStFailFailTm_s;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s20' */

/* ACChargeStateFail����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_ACDchaBMSPwrLoActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s21' */

/* AC�ŵ�BMS���ʵ͹��϶��� */
extern CALDATA const volatile float32 KDAG_ACDchaBMSPwrLoFailTm_s;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s19' */

/* AC�ŵ�BMS���ʵ�ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_ACDchaBMSPwrLo_A;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s18' */

/* AC�ŵ�BMS���ʵ͵��������ż� */
extern CALDATA const volatile uint16 KDAG_ACDchaBMSSOCLoActnMsk_enum;
                         /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s9' */

/* AC�ŵ�BMSSOC�͹��϶��� */
extern CALDATA const volatile float32 KDAG_ACDchaBMSSOCLoFailTm_s;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s10' */

/* AC�ŵ�BMSSOC��ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_ACDchaBMSSOCLo_pct;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s16' */

/* AC�ŵ�BMSSOC�ʹ����ż� */
extern CALDATA const volatile uint16 KDAG_ACDchaOverPwrActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s23' */

/* AC�ŵ繦�ʳ��޹��϶��� */
extern CALDATA const volatile float32 KDAG_ACDchaOverPwrFailTm_s;/* Referenced by:
                                                                  * '<S377>/KDAG_BMSCmdTmOutFailTm_s22'
                                                                  * '<S378>/KDAG_BMSCmdTmOutFailTm_s22'
                                                                  */

/* AC�ŵ繦�ʳ���ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_ACSCmdTmOutActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s25' */

/* ACSCmd��ʱ���϶��� */
extern CALDATA const volatile float32 KDAG_ACSCmdTmOutFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s24' */

/* ACSCmd��ʱ����ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_AccPed1VoltMax_mV;/* Referenced by:
                                                              * '<S523>/Constant76'
                                                              * '<S907>/Constant4'
                                                              */

/* ����̤��1·��ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_AccPed1VoltMin_mV;/* Referenced by:
                                                              * '<S523>/Constant75'
                                                              * '<S907>/Constant3'
                                                              */

/* ����̤��1·��ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_AccPed2VoltMax_mV;/* Referenced by:
                                                              * '<S523>/Constant78'
                                                              * '<S907>/Constant5'
                                                              */

/* ����̤��2·��ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_AccPed2VoltMin_mV;/* Referenced by:
                                                              * '<S523>/Constant77'
                                                              * '<S907>/Constant6'
                                                              */

/* ����̤��2·��ѹ�����ż� */
extern CALDATA const volatile uint16 KDAG_AccPedBothFailActnMsk_enum;
                        /* Referenced by: '<S523>/KDAG_BMSCmdTmOutFailTm_s23' */

/* ����̤��˫·ʧЧ���϶��� */
extern CALDATA const volatile uint16 KDAG_AccPedCrsChkActnMsk_enum;
                        /* Referenced by: '<S523>/KDAG_BMSCmdTmOutFailTm_s21' */

/* ����̤��˫·У����϶��� */
extern CALDATA const volatile float32 KDAG_AccPedCrsChkFailTm_s;
                        /* Referenced by: '<S523>/KDAG_BMSCmdTmOutFailTm_s20' */

/* ����̤��˫·У��ƫ��ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_AccPedCrsChkThr_pct;/* Referenced by: '<S524>/Constant81' */

/* ����̤��˫·У��ƫ���ż� */
extern CALDATA const volatile uint16 KDAG_AccPedShtCircActnMsk_enum;/* Referenced by:
                                                                     * '<S523>/KDAG_BMSCmdTmOutFailTm_s11'
                                                                     * '<S523>/KDAG_BMSCmdTmOutFailTm_s15'
                                                                     * '<S523>/KDAG_BMSCmdTmOutFailTm_s17'
                                                                     * '<S523>/KDAG_BMSCmdTmOutFailTm_s19'
                                                                     * '<S523>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                     */

/* ����̤���·���϶��� */
extern CALDATA const volatile float32 KDAG_AccPedShtCircFailTm_s;/* Referenced by:
                                                                  * '<S523>/KDAG_BMSCmdTmOutFailTm_s12'
                                                                  * '<S523>/KDAG_BMSCmdTmOutFailTm_s13'
                                                                  * '<S523>/KDAG_BMSCmdTmOutFailTm_s14'
                                                                  * '<S523>/KDAG_BMSCmdTmOutFailTm_s16'
                                                                  * '<S523>/KDAG_BMSCmdTmOutFailTm_s18'
                                                                  * '<S523>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                  */

/* ����̤���·ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_AccPedSuplyVoltMax_mV;/* Referenced by:
                                                                  * '<S523>/Constant36'
                                                                  * '<S523>/Constant72'
                                                                  * '<S907>/Constant2'
                                                                  * '<S907>/Constant7'
                                                                  */

/* ����̤�幩����ߵ�ѹ�ż� */
extern CALDATA const volatile float32 KDAG_AccPedSuplyVoltMin_mV;/* Referenced by:
                                                                  * '<S523>/Constant34'
                                                                  * '<S523>/Constant48'
                                                                  * '<S907>/Constant1'
                                                                  * '<S907>/Constant8'
                                                                  */

/* ����̤�幩����͵�ѹ�ż� */
extern CALDATA const volatile uint16 KDAG_BACBusOffActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s11' */
extern CALDATA const volatile uint16 KDAG_BMSCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s30' */
extern CALDATA const volatile uint16 KDAG_BMSCmdTmOutActnMsk_enum;
                         /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s2' */

/* BMS�̵���ָ����Ӧ��ʱ���϶��� */
extern CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm1_s;
                          /* Referenced by: '<S103>/KDAG_BMSCmdTmOutFailTm_s' */

/* BMS�̵���ָ����Ӧ��ʱȷ��ʱ��_��ֱ�����պϵȴ�ʱ�� */
extern CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm2_s;
                         /* Referenced by: '<S103>/KDAG_BMSCmdTmOutFailTm_s1' */

/* BMS�̵���ָ����Ӧ��ʱȷ��ʱ��_ֱ�����պϵȴ�ʱ�� */
extern CALDATA const volatile float32 KDAG_BMSCmdTmOutFailTm3_s;
                         /* Referenced by: '<S103>/KDAG_BMSCmdTmOutFailTm_s2' */

/* BMS�̵���ָ����Ӧ��ʱȷ��ʱ��_BMS�Լ��Ͽ��̵����ȴ�ʱ�� */
extern CALDATA const volatile uint16 KDAG_BMSEmgcySdnActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s11' */

/* BMS�����µ���϶��� */
extern CALDATA const volatile float32 KDAG_BMSEmgcySdnFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s12' */

/* BMS�����µ����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_BMSLostCommActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s4' */
extern CALDATA const volatile uint16 KDAG_BMSSOCLoActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s10' */

/* BMSSOC�͹��϶��� */
extern CALDATA const volatile float32 KDAG_BMSSOCLoFailTm_s;
                         /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s9' */

/* BMSSOC�͹���ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_BMSSysFailFailTm_s;/* Referenced by:
                                                               * '<S101>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               * '<S101>/KDAG_BMSCmdTmOutFailTm_s5'
                                                               * '<S101>/KDAG_BMSCmdTmOutFailTm_s7'
                                                               */

/* BMSFail����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_BMSSysFailLvl2ActnMsk_enum;
                         /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s6' */

/* BMSFailLevel2���϶��� */
extern CALDATA const volatile uint16 KDAG_BMSSysFailLvl3ActnMsk_enum;
                         /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s8' */

/* BMSFailLevel3���϶��� */
extern CALDATA const volatile uint16 KDAG_BMSUndrVoltActnMsk1_enum;
                        /* Referenced by: '<S105>/KDAG_BMSCmdTmOutFailTm_s13' */

/* BMSPackǷѹ���϶���_����ǰ */
extern CALDATA const volatile uint16 KDAG_BMSUndrVoltActnMsk2_enum;
                        /* Referenced by: '<S105>/KDAG_BMSCmdTmOutFailTm_s15' */

/* BMSPackǷѹ���϶���_������ */
extern CALDATA const volatile float32 KDAG_BMSUndrVoltFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s14' */

/* BMSPackǷѹ����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_BODBusOffActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s2' */
extern CALDATA const volatile float32 KDAG_BrkPedVoltMax_mV;/* Referenced by: '<S554>/Constant1' */

/* �ƶ�̤���ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_BrkPedVoltMin_mV;/* Referenced by: '<S554>/Constant48' */

/* �ƶ�̤���ѹ�����ż� */
extern CALDATA const volatile uint16 KDAG_BrkSwCrsChkActnMsk_enum;
                        /* Referenced by: '<S554>/KDAG_BMSCmdTmOutFailTm_s23' */

/* �ƶ�����˫·У����϶��� */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntDec_cnt;/* Referenced by: '<S555>/Constant11' */

/* �ƶ�����˫·У��������ٲ��� */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntHi_cnt;/* Referenced by: '<S555>/Constant1' */

/* �ƶ�����˫·У�����High_���ڴ�ֵ�ж��й��� */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntInc_cnt;/* Referenced by: '<S555>/Constant10' */

/* �ƶ�����˫·У��������Ӳ��� */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntLo_cnt;/* Referenced by: '<S555>/Constant3' */

/* �ƶ�����˫·У�����Low_���ڴ�ֵ�ж��޹��� */
extern CALDATA const volatile uint8 KDAG_BrkSwCrsChkCntMax_cnt;/* Referenced by: '<S555>/Constant12' */

/* �ƶ�����˫·У�����Max */
extern CALDATA const volatile float32 KDAG_BrkSwCrsChkIntvlTm_s;/* Referenced by: '<S555>/Constant5' */

/* �����ƶ�����У��������Ҫ�����ʱ�� */
extern CALDATA const volatile float32 KDAG_BrkSwDisagreeTmHi_s;/* Referenced by: '<S555>/Constant4' */

/* �ƶ����ز�һ��ʱ��High_���ڴ�ֵ��ʾ�˴�У�鲻ͨ�� */
extern CALDATA const volatile float32 KDAG_BrkSwDisagreeTmLo_s;/* Referenced by: '<S555>/Constant2' */

/* �ƶ����ز�һ��ʱ��Low_���ڴ�ֵ��ʾ�˴�У��ͨ�� */
extern CALDATA const volatile float32 KDAG_BrkSwDisagreeTmLong_s;/* Referenced by: '<S555>/Constant6' */

/* �ƶ����ز�һ��ʱ��Long_���ڴ�ֱֵ�ӱ�У����� */
extern CALDATA const volatile uint16 KDAG_CCPCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s13' */
extern CALDATA const volatile uint16 KDAG_CHABusOffActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s3' */
extern CALDATA const volatile uint16 KDAG_CRRRCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s21' */
extern CALDATA const volatile uint16 KDAG_CellUndrVoltActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s13' */

/* BMSCellǷѹ���϶��� */
extern CALDATA const volatile float32 KDAG_CellUndrVoltFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s15' */

/* BMSCellǷѹ����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCCCmdTmOutActnMsk1_enum;
                        /* Referenced by: '<S286>/KDAG_BMSCmdTmOutFailTm_s13' */

/* DCDCģʽָ����Ӧ��ʱ���϶���_����ǰ */
extern CALDATA const volatile uint16 KDAG_DCCCmdTmOutActnMsk2_enum;
                        /* Referenced by: '<S286>/KDAG_BMSCmdTmOutFailTm_s15' */

/* DCDCģʽָ����Ӧ��ʱ���϶���_������ */
extern CALDATA const volatile float32 KDAG_DCCCmdTmOutFailTm_s;
                        /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s14' */

/* DCDCģʽָ����Ӧ��ʱ����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCCInVoltLoActnMsk_enum;
                         /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDC�����ѹ�͹��϶��� */
extern CALDATA const volatile float32 KDAG_DCCInVoltLoFailTm_s;
                        /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s13' */

/* DCDC�����ѹ�͹���ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCCModeFltActnMsk1_enum;
                         /* Referenced by: '<S288>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDCModeFault���϶���_����ǰ */
extern CALDATA const volatile uint16 KDAG_DCCModeFltActnMsk2_enum;
                        /* Referenced by: '<S288>/KDAG_BMSCmdTmOutFailTm_s11' */

/* DCDCModeFault���϶���_������ */
extern CALDATA const volatile float32 KDAG_DCCModeFltFailTm_s;
                        /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s12' */

/* DCDCModeFault����ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_DCCSysFailFailTm_s;/* Referenced by:
                                                               * '<S279>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               * '<S279>/KDAG_BMSCmdTmOutFailTm_s5'
                                                               * '<S279>/KDAG_BMSCmdTmOutFailTm_s7'
                                                               * '<S279>/KDAG_BMSCmdTmOutFailTm_s9'
                                                               */

/* DCDCFail����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCCSysFailLvl3ActnMsk1_enum;
                         /* Referenced by: '<S287>/KDAG_BMSCmdTmOutFailTm_s1' */

/* DCDCFaillevel3���϶���_����ǰ */
extern CALDATA const volatile uint16 KDAG_DCCSysFailLvl3ActnMsk2_enum;
                         /* Referenced by: '<S287>/KDAG_BMSCmdTmOutFailTm_s8' */

/* DCDCFaillevel3���϶���_������ */
extern CALDATA const volatile float32 KDAG_DCCSysFailLvl3FailTm_s;
                         /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s6' */

/* DCDCFaillevel3����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCCSysFailLvl4ActnMsk_enum;
                        /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s10' */

/* DCDCFaillevel4���϶��� */
extern CALDATA const volatile uint16 KDAG_DCSChrgReqActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s21' */

/* DCSChargeRequest���϶��� */
extern CALDATA const volatile float32 KDAG_DCSChrgReqFailTm_s;/* Referenced by:
                                                               * '<S101>/KDAG_BMSCmdTmOutFailTm_s20'
                                                               * '<S787>/Constant5'
                                                               */

/* DCSChargeRequest����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCSCmdTmOutActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s27' */

/* DCSCmd��ʱ���϶��� */
extern CALDATA const volatile float32 KDAG_DCSCmdTmOutFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s17' */

/* DCSCmd��ʱ����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCSFailStaActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s28' */

/* DCSFailState���϶��� */
extern CALDATA const volatile float32 KDAG_DCSFailStaFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s16' */

/* DCSFailState����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCSInletConnectActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s19' */

/* DCS��ǹ״̬���϶��� */
extern CALDATA const volatile float32 KDAG_DCSInletConnectFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s18' */

/* DCS��ǹ״̬����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_DCSModeFailActnMsk_enum;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s23' */

/* DCSModeFail���϶��� */
extern CALDATA const volatile float32 KDAG_DCSModeFailFailTm_s;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s22' */

/* DCSModeFail����ȷ��ʱ�� */
extern CALDATA const volatile uint8 KDAG_Did0xF163WrtData_cnt[4];/* Referenced by: '<S100>/DidData3' */

/* CCU_FlashDriver��� */
extern CALDATA const volatile uint8 KDAG_Did0xF180WrtData_cnt[4];/* Referenced by: '<S100>/DidData2' */

/* CCU_Boot��� */
extern CALDATA const volatile uint8 KDAG_Did0xF187WrtData_cnt[2];/* Referenced by: '<S100>/DidData' */

/* �ܳɺ� */
extern CALDATA const volatile uint8 KDAG_Did0xF188WrtData_cnt[4];/* Referenced by: '<S100>/DidData4' */

/* CCU_App��� */
extern CALDATA const volatile uint8 KDAG_Did0xF191WrtData_cnt[4];/* Referenced by: '<S100>/DidData1' */

/* CCUӲ�� */
extern CALDATA const volatile uint16 KDAG_EHBCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s34' */
extern CALDATA const volatile float32 KDAG_EHBFltFailTm_s;/* Referenced by:
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s17'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s4'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s5'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s7'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s9'
                                                           */

/* EHB����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl2ActnMsk_enum;
                         /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s6' */

/* EHB2�����϶��� */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl3ActnMsk_enum;
                         /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s8' */

/* EHB3�����϶��� */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl4ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s18' */

/* EHB4�����϶��� */
extern CALDATA const volatile uint16 KDAG_EHBFltLvl5ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s10' */

/* EHB5�����϶��� */
extern CALDATA const volatile uint16 KDAG_EHBLostCommActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s7' */
extern CALDATA const volatile uint16 KDAG_EPTBusOffActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s1' */
extern CALDATA const volatile uint16 KDAG_ESCCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s35' */
extern CALDATA const volatile float32 KDAG_ESCFltFailTm_s;/* Referenced by:
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s14'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s19'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s20'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s22'
                                                           * '<S439>/KDAG_BMSCmdTmOutFailTm_s24'
                                                           */

/* ESC����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl2ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s21' */

/* ESC2�����϶��� */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl3ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s23' */

/* ESC3�����϶��� */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl4ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s15' */

/* ESC4�����϶��� */
extern CALDATA const volatile uint16 KDAG_ESCFltLvl5ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s12' */

/* ESC5�����϶��� */
extern CALDATA const volatile uint16 KDAG_ESCLostCommActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s5' */
extern CALDATA const volatile uint16 KDAG_ESCVehSpdInvldActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s13' */

/* ����ʧЧ���϶��� */
extern CALDATA const volatile float32 KDAG_ESCVehSpdInvldFailTm_s;
                         /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s3' */

/* ����ʧЧȷ��ʱ�� */
extern CALDATA const volatile boolean KDAG_EmgcyShtdwnOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg9' */
extern CALDATA const volatile boolean KDAG_EmgcyShtdwnOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg9' */
extern CALDATA const volatile uint16 KDAG_FCMCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s24' */
extern CALDATA const volatile uint16 KDAG_FCMLostCommActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s37' */

/* FCMͨ�Ŷ�ʧ�����϶��� */
extern CALDATA const volatile boolean KDAG_FanFullSpdOnOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg17' */
extern CALDATA const volatile boolean KDAG_FanFullSpdOnOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg17' */
extern CALDATA const volatile boolean KDAG_FbdACCOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg7' */
extern CALDATA const volatile boolean KDAG_FbdACCOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg7' */
extern CALDATA const volatile boolean KDAG_FbdACChrgOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg11' */
extern CALDATA const volatile boolean KDAG_FbdACChrgOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg11' */
extern CALDATA const volatile boolean KDAG_FbdACDchaOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg13' */
extern CALDATA const volatile boolean KDAG_FbdACDchaOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg13' */
extern CALDATA const volatile boolean KDAG_FbdACOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg14' */
extern CALDATA const volatile boolean KDAG_FbdACOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg14' */
extern CALDATA const volatile boolean KDAG_FbdCCOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile boolean KDAG_FbdCCOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg5' */
extern CALDATA const volatile boolean KDAG_FbdDCChrgOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg12' */
extern CALDATA const volatile boolean KDAG_FbdDCChrgOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg12' */
extern CALDATA const volatile boolean KDAG_FbdDCDCOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg10' */
extern CALDATA const volatile boolean KDAG_FbdDCDCOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg10' */
extern CALDATA const volatile boolean KDAG_FbdDRGrOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile boolean KDAG_FbdDRGrOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg4' */
extern CALDATA const volatile boolean KDAG_FbdDrvTqOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile boolean KDAG_FbdDrvTqOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile boolean KDAG_FbdHVOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg8' */
extern CALDATA const volatile boolean KDAG_FbdHVOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg8' */
extern CALDATA const volatile boolean KDAG_FbdLSPOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg6' */
extern CALDATA const volatile boolean KDAG_FbdLSPOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg6' */
extern CALDATA const volatile boolean KDAG_FltLampOnOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg15' */
extern CALDATA const volatile boolean KDAG_FltLampOnOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg15' */
extern CALDATA const volatile uint16 KDAG_FrstHVILVoltChkActnMsk1_enum;/* Referenced by:
                                                                      * '<S571>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                      * '<S572>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                      */

/* ��Ҫ��ѹ�������϶���1 */
extern CALDATA const volatile uint16 KDAG_FrstHVILVoltChkActnMsk2_enum;/* Referenced by:
                                                                      * '<S571>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      * '<S572>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                      */

/* ��Ҫ��ѹ�������϶���2 */
extern CALDATA const volatile float32 KDAG_FrstHVILVoltMax_mV;/* Referenced by: '<S571>/Constant75' */

/* ��Ҫ��ѹ������ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_FrstHVILVoltMin_mV;/* Referenced by: '<S572>/Constant75' */

/* ��Ҫ��ѹ������ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_GearShftInvldFailTm1_s;
                         /* Referenced by: '<S479>/KDAG_BMSCmdTmOutFailTm_s2' */

/* ��������ʧЧ����ȷ��ʱ��1 */
extern CALDATA const volatile float32 KDAG_GearShftInvldFailTm2_s;
                         /* Referenced by: '<S479>/KDAG_BMSCmdTmOutFailTm_s4' */

/* ��������ʧЧ����ȷ��ʱ��2 */
extern CALDATA const volatile float32 KDAG_HVAccAcptBMSVoltFac_c;/* Referenced by:
                                                                  * '<S279>/KDAG_BMSCmdTmOutFailTm_s19'
                                                                  * '<S279>/KDAG_BMSCmdTmOutFailTm_s2'
                                                                  * '<S766>/Constant1'
                                                                  */

/* ��ѹ������ѹ���ص�ѹ��ֵ�Ŀɽ��ܱ���ϵ�� */
extern CALDATA const volatile float32 KDAG_HVILVoltChkFailTm_s;/* Referenced by:
                                                                * '<S554>/KDAG_BMSCmdTmOutFailTm_s10'
                                                                * '<S554>/KDAG_BMSCmdTmOutFailTm_s3'
                                                                * '<S554>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                * '<S554>/KDAG_BMSCmdTmOutFailTm_s9'
                                                                */

/* ��ѹ��������ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_HVIsoResistLoActnMsk_enum;
                         /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s1' */

/* ��ѹ��ؾ�Ե���϶��� */
extern CALDATA const volatile float32 KDAG_HVIsoResistLoFailTm_s;
                          /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s' */

/* ��ѹ��ؾ�Ե������ֵ��ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_HVIsoResistLoPassTm_s;
                         /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s3' */

/* ��ѹ��ؾ�Ե������ֵ�ͻָ�ʱ�� */
extern CALDATA const volatile float32 KDAG_HVIsoResistLoThr_kOhm;
                        /* Referenced by: '<S101>/KDAG_BMSCmdTmOutFailTm_s26' */

/* ��ѹ��ؾ�Ե������ֵ�ż� */
extern CALDATA const volatile uint16 KDAG_INVCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s32' */
extern CALDATA const volatile float32 KDAG_INVFltFailTm_s;/* Referenced by:
                                                           * '<S351>/KDAG_BMSCmdTmOutFailTm_s4'
                                                           * '<S351>/KDAG_BMSCmdTmOutFailTm_s5'
                                                           * '<S351>/KDAG_BMSCmdTmOutFailTm_s7'
                                                           * '<S351>/KDAG_BMSCmdTmOutFailTm_s9'
                                                           */

/* INVFault����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_INVFltLvl2ActnMsk_enum;
                         /* Referenced by: '<S351>/KDAG_BMSCmdTmOutFailTm_s6' */

/* INVFaultLevel2���϶��� */
extern CALDATA const volatile uint16 KDAG_INVFltLvl3ActnMsk_enum;
                         /* Referenced by: '<S351>/KDAG_BMSCmdTmOutFailTm_s8' */

/* INVFaultLevel3���϶��� */
extern CALDATA const volatile uint16 KDAG_INVFltLvl4ActnMsk_enum;
                        /* Referenced by: '<S351>/KDAG_BMSCmdTmOutFailTm_s10' */

/* INVFaultLevel4���϶��� */
extern CALDATA const volatile uint16 KDAG_INVInVoltLoActnMsk_enum;
                        /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s17' */

/* INV�����ѹ�͹��϶��� */
extern CALDATA const volatile float32 KDAG_INVInVoltLoFailTm_s;
                        /* Referenced by: '<S279>/KDAG_BMSCmdTmOutFailTm_s18' */

/* INV�����ѹ�͹���ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_INVLostCommActnMsk_enum;
                         /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s6' */
extern CALDATA const volatile uint16 KDAG_INVRunCmdRespActnMsk_enum;
                        /* Referenced by: '<S351>/KDAG_BMSCmdTmOutFailTm_s11' */

/* INVRunָ����Ӧ��ʱ���϶��� */
extern CALDATA const volatile float32 KDAG_INVRunCmdRespFailTm_s;
                        /* Referenced by: '<S351>/KDAG_BMSCmdTmOutFailTm_s12' */

/* INVRunָ����Ӧ��ʱ����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_IPUCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s36' */
extern CALDATA const volatile uint16 KDAG_IPULostCommActnMsk1_enum;
                         /* Referenced by: '<S239>/KDAG_BMSCmdTmOutFailTm_s1' */
extern CALDATA const volatile uint16 KDAG_IPULostCommActnMsk2_enum;
                         /* Referenced by: '<S239>/KDAG_BMSCmdTmOutFailTm_s9' */
extern CALDATA const volatile boolean KDAG_LVBatLampOnOvrdSw_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg16' */
extern CALDATA const volatile boolean KDAG_LVBatLampOnOvrdVal_flg;
                         /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg16' */
extern CALDATA const volatile float32 KDAG_LVBatVoltHiRec_V;
                         /* Referenced by: '<S507>/KDAG_BMSCmdTmOutFailTm_s5' */

/* ���ع�ѹ�ָ��ż� */
extern CALDATA const volatile float32 KDAG_LVBatVoltHi_V;/* Referenced by:
                                                          * '<S507>/KDAG_BMSCmdTmOutFailTm_s8'
                                                          * '<S554>/KDAG_BMSCmdTmOutFailTm_s8'
                                                          */

/* ���ع�ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_LVBatVoltLoRec_V;
                         /* Referenced by: '<S507>/KDAG_BMSCmdTmOutFailTm_s4' */

/* ����Ƿѹ�ָ��ż� */
extern CALDATA const volatile float32 KDAG_LVBatVoltLo_V;/* Referenced by:
                                                          * '<S507>/KDAG_BMSCmdTmOutFailTm_s7'
                                                          * '<S554>/KDAG_BMSCmdTmOutFailTm_s7'
                                                          */

/* ����Ƿѹ�����ż� */
extern CALDATA const volatile float32 KDAG_LVBatVoltPassbl_V;
                        /* Referenced by: '<S516>/KDAG_BMSCmdTmOutFailTm_s15' */

/* ���ص�ѹ�п��ż� */
extern CALDATA const volatile float32 KDAG_LVBattSOCLoFailTm_s;
                        /* Referenced by: '<S507>/KDAG_BMSCmdTmOutFailTm_s18' */

/* ����SOC��ȷ��ʱ�� */
extern CALDATA const volatile uint8 KDAG_LVBattSOCLo_pct;/* Referenced by: '<S507>/Constant77' */

/* ����SOC���ż� */
extern CALDATA const volatile float32 KDAG_LVBattSOHLoFailTm_s;
                         /* Referenced by: '<S507>/KDAG_BMSCmdTmOutFailTm_s1' */

/* ����SOH��ȷ��ʱ�� */
extern CALDATA const volatile uint8 KDAG_LVBattSOHLo_pct;/* Referenced by: '<S507>/Constant78' */

/* ����SOH���ż� */
extern CALDATA const volatile uint16 KDAG_LVBattTempHiActnMsk1_enum;
                        /* Referenced by: '<S516>/KDAG_BMSCmdTmOutFailTm_s13' */

/* ���ع��¹��϶���_����ǰ */
extern CALDATA const volatile uint16 KDAG_LVBattTempHiActnMsk2_enum;
                         /* Referenced by: '<S516>/KDAG_BMSCmdTmOutFailTm_s1' */

/* ���ع��¹��϶���_������ */
extern CALDATA const volatile float32 KDAG_LVBattTempHiFailTm_s;
                         /* Referenced by: '<S507>/KDAG_BMSCmdTmOutFailTm_s2' */

/* ���ع���ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_LVBattTempHi_C;/* Referenced by: '<S516>/Constant40' */

/* ���ع����¶��ż� */
extern CALDATA const volatile float32 KDAG_LVBattVoltExcdFailTm_s;/* Referenced by:
                                                                   * '<S507>/KDAG_BMSCmdTmOutFailTm_s3'
                                                                   * '<S507>/KDAG_BMSCmdTmOutFailTm_s6'
                                                                   */

/* ����Ƿѹ��ѹȷ��ʱ�� */
extern CALDATA const volatile boolean KDAG_LimpHomeOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile boolean KDAG_LimpHomeOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg1' */
extern CALDATA const volatile boolean KDAG_LmtDrvTqOvrdSw_flg;
                           /* Referenced by: '<S91>/KDAG_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile boolean KDAG_LmtDrvTqOvrdVal_flg;
                          /* Referenced by: '<S91>/KDAG_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile uint8 KDAG_ManlClrDTCReq_enum;
                         /* Referenced by: '<S90>/KDAG_VehStandStillSpd_kph1' */

/* �ֶ�������й��ϵı궨_��0�ĳ�255ʱ������һ������ */
extern CALDATA const volatile uint16 KDAG_OBCChrgReqActnMsk_enum;
                         /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s7' */

/* OBCChargeRequest���϶��� */
extern CALDATA const volatile float32 KDAG_OBCChrgReqFailTm_s;
                         /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s8' */

/* OBCChargeRequest����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_OBCConnectTmOutActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s25' */

/* OBC���ӳ�ʱ���϶��� */
extern CALDATA const volatile float32 KDAG_OBCConnectTmOutFailTm1_s;
                          /* Referenced by: '<S412>/KDAG_BMSCmdTmOutFailTm_s' */

/* OBC���ӳ�ʱ���ϵȴ�ʱ��_����ǰ */
extern CALDATA const volatile float32 KDAG_OBCConnectTmOutFailTm2_s;
                         /* Referenced by: '<S412>/KDAG_BMSCmdTmOutFailTm_s1' */

/* OBC���ӳ�ʱ���ϵȴ�ʱ��_���Ӻ�Ͽ� */
extern CALDATA const volatile uint16 KDAG_OBCInletConnectActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s11' */

/* OBC��ǹ״̬���϶��� */
extern CALDATA const volatile float32 KDAG_OBCInletConnectFailTm_s;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s12' */

/* OBC��ǹ״̬����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_OBCModeMsmtchActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s27' */

/* OBCģʽ��ƥ����϶��� */
extern CALDATA const volatile float32 KDAG_OBCModeMsmtchFailTm_s;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s26' */

/* OBCģʽ��ƥ�����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_OBCS2StatActnMsk_enum;
                         /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s5' */

/* OBCS2���ӳ�ʱ���϶��� */
extern CALDATA const volatile float32 KDAG_OBCS2StatFailTm_s;
                         /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s6' */

/* OBCS2���ӳ�ʱ����ȷ��ʱ�� */
extern CALDATA const volatile float32 KDAG_OBCSysFailFailTm_s;/* Referenced by:
                                                               * '<S377>/KDAG_BMSCmdTmOutFailTm_s14'
                                                               * '<S377>/KDAG_BMSCmdTmOutFailTm_s15'
                                                               * '<S377>/KDAG_BMSCmdTmOutFailTm_s17'
                                                               * '<S377>/KDAG_BMSCmdTmOutFailTm_s4'
                                                               */

/* OBCFail����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_OBCSysFailLvl4ActnMsk_enum;
                        /* Referenced by: '<S377>/KDAG_BMSCmdTmOutFailTm_s13' */

/* OBCFailLevel4���϶��� */
extern CALDATA const volatile uint16 KDAG_SCSCRCFltActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s19' */
extern CALDATA const volatile uint16 KDAG_SCSLostCommActnMsk_enum;
                        /* Referenced by: '<S165>/KDAG_BMSCmdTmOutFailTm_s39' */

/* SCSͨ�Ŷ�ʧ�����϶��� */
extern CALDATA const volatile uint16 KDAG_SecdHVILVoltHiActnMsk_enum;
                        /* Referenced by: '<S554>/KDAG_BMSCmdTmOutFailTm_s11' */

/* ��Ҫ��ѹ������ѹ�߹��϶��� */
extern CALDATA const volatile uint16 KDAG_SecdHVILVoltLoActnMsk_enum;
                         /* Referenced by: '<S554>/KDAG_BMSCmdTmOutFailTm_s4' */

/* ��Ҫ��ѹ������ѹ�͹��϶��� */
extern CALDATA const volatile float32 KDAG_SecdHVILVoltMax_mV;/* Referenced by: '<S554>/Constant2' */

/* ��Ҫ��ѹ������ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_SecdHVILVoltMin_mV;/* Referenced by: '<S554>/Constant75' */

/* ��Ҫ��ѹ������ѹ�����ż� */
extern CALDATA const volatile float32 KDAG_SysPwrModeInvldFailTm_s;
                         /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s1' */

/* PowerModeʧЧȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_TMSFailLvl3ActnMsk_enum;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s11' */

/* TMSRFailLevel3���϶��� */
extern CALDATA const volatile float32 KDAG_TMSFailLvl3FailTm_s;
                        /* Referenced by: '<S439>/KDAG_BMSCmdTmOutFailTm_s16' */

/* TMSRFailLevel3����ȷ��ʱ�� */
extern CALDATA const volatile uint16 KDAG_VehCrashActnMsk_enum;
                         /* Referenced by: '<S523>/KDAG_BMSCmdTmOutFailTm_s2' */

/* ��ײ���϶��� */
extern CALDATA const volatile float32 KDAG_VehSpdLo_kph;/* Referenced by: '<S90>/Constant2' */

/* �ͳ����ż������ڹ������� */
extern CALDATA const volatile boolean KDAG_VehStandStillBypasBrk_flg;
                         /* Referenced by: '<S90>/KDAG_VehStandStillSpd_kph2' */

/* פ��������ϲ���ɲ���ı궨��_������1���ÿ�ɲ��_����ͣ����PN������ */
extern CALDATA const volatile float32 KDAG_VehStandStillSpd_kph;
                          /* Referenced by: '<S90>/KDAG_VehStandStillSpd_kph' */

/* פ��������ϵĳ����ż�_���������ֹͣ */
extern CALDATA const volatile float32 KDAG_WakeUpDlyTm_s;
                         /* Referenced by: '<S90>/KDAG_VehStandStillSpd_kph3' */

/* ����Դ���ߵ��ź��ӳ�ʱ��_����Ͽ�ʼ���ӳ�ʱ�� */
extern CALDATA const volatile uint32 KDAG_WaterTempAbvThr_Ohm;/* Referenced by: '<S588>/Constant1' */

/* ��ȴˮ�¹��ߵĵ����ż� */
extern CALDATA const volatile uint32 KDAG_WaterTempBlwThr_Ohm;/* Referenced by: '<S588>/Constant75' */

/* ��ȴˮ�¹��͵ĵ����ż� */
extern CALDATA const volatile float32 KDAG_WaterTempExcdThrFailTm_s;/* Referenced by:
                                                                     * '<S588>/KDAG_BMSCmdTmOutFailTm_s1'
                                                                     * '<S588>/KDAG_BMSCmdTmOutFailTm_s5'
                                                                     */

/* ��ȴˮ���쳣��ȷ��ʱ�� */
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

/* �ŵ總�������˲�ϵ����ֻ���½��� */
extern CALDATA const volatile float32 KEMS_AccPwrIncFiltCoeff_c;
                           /* Referenced by: '<S26>/KVTM_LimpHomeOvrdSw_flg4' */

/* ��總�������˲�ϵ����ֻ���Ͻ��� */
extern CALDATA const volatile float32 KEMS_CellTempSynDecRate_Cps;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg6' */

/* ��о�¶��½�б�� */
extern CALDATA const volatile float32 KEMS_CellTempSynIncRate_Cps;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg7' */

/* ��о�¶�����б�� */
extern CALDATA const volatile float32 KEMS_ChrgCurFbKiMax_A;/* Referenced by: '<S82>/Saturation' */

/* ���KI�������� */
extern CALDATA const volatile float32 KEMS_ChrgCurFbKiMin_A;/* Referenced by: '<S82>/Saturation' */

/* ���KI�������� */
extern CALDATA const volatile float32 KEMS_ChrgCurFbMax_A;/* Referenced by: '<S82>/Saturation2' */

/* ���KP+KI�������� */
extern CALDATA const volatile float32 KEMS_ChrgCurFbMin_A;/* Referenced by: '<S82>/Saturation2' */

/* ���KP+KI�������� */
extern CALDATA const volatile float32 KEMS_ChrgFbActvDlyTm_s;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg2' */

/* ��繦�ʱջ��˳��ӳ�ʱ�� */
extern CALDATA const volatile float32 KEMS_ChrgPwr2MotRawFiltCoeff_c;
                           /* Referenced by: '<S26>/KVTM_LimpHomeOvrdSw_flg5' */

/* ����ܹ����˲�ϵ����ֻ���½��� */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbFiltCoeff_c;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg3' */

/* ��繦�ʱջ��˲�ϵ�� */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbKiMax_kW;/* Referenced by: '<S46>/Saturation' */

/* ��繦�ʱջ�KI�������� */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbKiMin_kW;/* Referenced by: '<S46>/Saturation' */

/* ��繦�ʱջ�KI�������� */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbMax_kW;/* Referenced by: '<S46>/Saturation2' */

/* ��繦�ʱջ�KI+KP�������� */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbMin_kW;/* Referenced by: '<S46>/Saturation2' */

/* ��繦�ʱջ�KI+KP�������� */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbOff_kW;
                           /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg1' */

/* ��繦�ʱջ����뷧ֵ */
extern CALDATA const volatile float32 KEMS_ChrgPwrFbOn_kW;
                          /* Referenced by: '<S27>/KVTM_LimpHomeOvrdSw_flg15' */

/* ��繦�ʱջ��˳���ֵ */
extern CALDATA const volatile float32 KEMS_DCCSurgePwr_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg2' */

/* DCCӿ������ */
extern CALDATA const volatile float32 KEMS_DchaCurFbKiMax_A;/* Referenced by: '<S83>/Saturation' */

/* �ŵ�Ki�������� */
extern CALDATA const volatile float32 KEMS_DchaCurFbKiMin_A;/* Referenced by: '<S83>/Saturation' */

/* �ŵ�Ki�������� */
extern CALDATA const volatile float32 KEMS_DchaCurFbMax_A;/* Referenced by: '<S83>/Saturation2' */

/* �ŵ�KP+Ki�������� */
extern CALDATA const volatile float32 KEMS_DchaCurFbMin_A;/* Referenced by: '<S83>/Saturation2' */

/* �ŵ�KP+Ki�������� */
extern CALDATA const volatile float32 KEMS_DchaFbActvDlyTm_s;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg2' */

/* �ŵ繦�ʱջ��˳��ӳ�ʱ�� */
extern CALDATA const volatile float32 KEMS_DchaPwr2MotRawFiltCoeff_c;
                           /* Referenced by: '<S28>/KVTM_LimpHomeOvrdSw_flg2' */

/* �ŵ��ܹ����˲�ϵ����ֻ�������� */
extern CALDATA const volatile float32 KEMS_DchaPwrFbFiltCoeff_c;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg3' */

/* �ŵ繦�ʱջ��˲�ϵ�� */
extern CALDATA const volatile float32 KEMS_DchaPwrFbKiMax_kW;/* Referenced by: '<S64>/Saturation' */

/* �ŵ繦�ʱջ�KI�������� */
extern CALDATA const volatile float32 KEMS_DchaPwrFbKiMin_kW;/* Referenced by: '<S64>/Saturation' */

/* �ŵ繦�ʱջ�KI�������� */
extern CALDATA const volatile float32 KEMS_DchaPwrFbMax_kW;/* Referenced by: '<S64>/Saturation2' */

/* �ŵ繦�ʱջ�KI+KP�������� */
extern CALDATA const volatile float32 KEMS_DchaPwrFbMin_kW;/* Referenced by: '<S64>/Saturation2' */

/* �ŵ繦�ʱջ�KI+KP�������� */
extern CALDATA const volatile float32 KEMS_DchaPwrFbOff_kW;
                           /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg1' */

/* �ŵ繦�ʱջ��˳���ֵ */
extern CALDATA const volatile float32 KEMS_DchaPwrFbOn_kW;
                          /* Referenced by: '<S29>/KVTM_LimpHomeOvrdSw_flg15' */

/* �ŵ繦�ʱջ����뷧ֵ */
extern CALDATA const volatile float32 KEMS_HVBatActCurrExcdThr_A;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg1' */

/* ʵ�ʵ����쳣����ֵ */
extern CALDATA const volatile float32 KEMS_HVBatActCurrExcdVal_A;
                           /* Referenced by: '<S31>/KVTM_LimpHomeOvrdSw_flg2' */

/* ʵ�ʵ����쳣�������ֵ���������ޣ� */
extern CALDATA const volatile float32 KEMS_HVBatCurrBelowConChrgDlyTm_s;
                         /* Referenced by: '<S26>/KTQC_DrvTqLoEnblRBSThr_Nm1' */

/* Con����������Ins˲ʱ���� */
extern CALDATA const volatile float32 KEMS_HVBatCurrBelowConDlyTm_s;
                         /* Referenced by: '<S28>/KTQC_DrvTqLoEnblRBSThr_Nm1' */

/* Con������Ins˲ʱ */
extern CALDATA const volatile float32 KEMS_HVBatCurrOverConChrgDlyTm_s;
                         /* Referenced by: '<S26>/KTQC_DrvTqLoEnblRBSThr_Nm3' */

/* Ins˲ʱ������Con�������� */
extern CALDATA const volatile float32 KEMS_HVBatCurrOverConDlyTm_s;
                         /* Referenced by: '<S28>/KTQC_DrvTqLoEnblRBSThr_Nm3' */

/* Ins˲ʱ��Con���� */
extern CALDATA const volatile float32 KEMS_MaxChrgCurDecRate_Aps;
                        /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltCoeff_c1' */

/* ���������½�б�� */
extern CALDATA const volatile float32 KEMS_MaxChrgCurFiltAchvd_A;
                        /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltAchvd_Nm' */

/* ���������˲�����ֵ */
extern CALDATA const volatile float32 KEMS_MaxChrgCurIncRate_Aps;
                         /* Referenced by: '<S26>/KCPT_MotorMaxTqFiltCoeff_c' */

/* ������������б�� */
extern CALDATA const volatile float32 KEMS_MaxDchaCurDecRate_Aps;
                        /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltCoeff_c1' */

/* ���ŵ�����½�б�� */
extern CALDATA const volatile float32 KEMS_MaxDchaCurFiltAchvd_A;
                        /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltAchvd_Nm' */

/* ���ŵ�����˲�����ֵ */
extern CALDATA const volatile float32 KEMS_MaxDchaCurIncRate_Aps;
                         /* Referenced by: '<S28>/KCPT_MotorMaxTqFiltCoeff_c' */

/* ���ŵ��������б�� */
extern CALDATA const volatile float32 KEMS_TMSActSOCOff_pct;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg5' */

/* ��ϵTMS����SOC��ֵ */
extern CALDATA const volatile float32 KEMS_TMSActSOCOn_pct;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg4' */

/* ����TMS����SOC��ֵ */
extern CALDATA const volatile float32 KEMS_TMSMaxPwrLim_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg6' */

/* TMS�������ʹ�ù��� */
extern CALDATA const volatile float32 KEMS_TMSPwrEnblOff_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg3' */

/* �ر�TMS�������ʷ�ֵ */
extern CALDATA const volatile float32 KEMS_TMSPwrEnblOn_kW;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg1' */

/* ����TMS�������ʷ�ֵ */
extern CALDATA const volatile float32 KEMS_TMSPwrOffDlyTm_s;
                           /* Referenced by: '<S30>/KVTM_LimpHomeOvrdSw_flg8' */

/* �ر�TMS��������ȷ��ʱ�� */
extern CALDATA const volatile boolean KGSM_DRFlt2NSw_flg;/* Referenced by: '<S1645>/Constant3' */

/* ���������Ͻ�N��ǿ�� */
extern CALDATA const volatile boolean KGSM_DRFlt2NVal_flg;/* Referenced by: '<S1645>/Constant2' */

/* ���������Ͻ�N��-�۲�����VGSM_DRFlt2N_flg */
extern CALDATA const volatile float32 KGSM_EPBApld2PDlyTm_s;/* Referenced by: '<S1683>/Constant4' */

/* �淶��EPB������P�����ж�ʱ����ֵ */
extern CALDATA const volatile float32 KGSM_EPBReld2NDlyTm_s;/* Referenced by: '<S1684>/Constant4' */

/* �淶��EPB�ͷ���N�����ж�ʱ����ֵ */
extern CALDATA const volatile float32 KGSM_EPBReqMaxTm_s;/* Referenced by:
                                                          * '<S1622>/Constant2'
                                                          * '<S1622>/Constant4'
                                                          * '<S1622>/Constant5'
                                                          */

/* �淶��EPB�������ʱ����ֵ */
extern CALDATA const volatile boolean KGSM_GrNReq2PSw_flg;/* Referenced by: '<S1645>/Constant5' */

/* N���ǻ��������P������ǿ�� */
extern CALDATA const volatile boolean KGSM_GrNReq2PVal_flg;/* Referenced by: '<S1645>/Constant4' */

/* N���ǻ��������P������-�۲�����VGSM_GrNReq2P_flg */
extern CALDATA const volatile float32 KGSM_GrShftF1R1HldTm_s;/* Referenced by:
                                                              * '<S1682>/Constant3'
                                                              * '<S1682>/Constant4'
                                                              * '<S1684>/Constant2'
                                                              */

/* �淶����������N�����ж�ʱ����ֵ */
extern CALDATA const volatile float32 KGSM_GrShftF2R2HldTm_s;/* Referenced by:
                                                              * '<S1682>/Constant5'
                                                              * '<S1682>/Constant6'
                                                              * '<S1682>/Constant7'
                                                              * '<S1682>/Constant8'
                                                              * '<S1684>/Constant1'
                                                              * '<S1684>/Constant9'
                                                              */

/* �淶����������D�����ж�ʱ����ֵ/��������R�����ж�ʱ����ֵ */
extern CALDATA const volatile float32 KGSM_GrShftHwPHldTm_s;/* Referenced by:
                                                             * '<S1683>/Constant2'
                                                             * '<S1683>/Constant5'
                                                             * '<S1683>/Constant6'
                                                             */

/* �淶����������P����ʱ����ֵ */
extern CALDATA const volatile float32 KGSM_GrShftMaxVehSpd_kph;/* Referenced by:
                                                                * '<S1622>/Constant6'
                                                                * '<S650>/Constant'
                                                                * '<S650>/Constant1'
                                                                * '<S1647>/Constant6'
                                                                * '<S1682>/Constant10'
                                                                * '<S1682>/Constant11'
                                                                * '<S1682>/Constant12'
                                                                * '<S1682>/Constant9'
                                                                */

/* �淶������������ֵ */
extern CALDATA const volatile float32 KGSM_GrSlopMaxVehSpd_kph;/* Referenced by:
                                                                * '<S1684>/Constant10'
                                                                * '<S1684>/Constant3'
                                                                */

/* �淶��P2D/P2R���³��� */
extern CALDATA const volatile boolean KGSM_HldGearPSw_flg;/* Referenced by: '<S1645>/Constant1' */

/* ����P������ǿ�� */
extern CALDATA const volatile boolean KGSM_HldGearPVal_flg;/* Referenced by: '<S1645>/Constant' */

/* ����P������-�۲�����VGSM_HldGearP_flg */
extern CALDATA const volatile float32 KGSM_INVTrnOffDly_s;/* Referenced by: '<S1623>/Constant1' */

/* �淶������ʵ�ʵ�λ�ɷ�P�����뵽P����ʱ��2S */
extern CALDATA const volatile float32 KGSM_PErrDispMaxTm_s;/* Referenced by:
                                                            * '<S1622>/Cnst'
                                                            * '<S1622>/Cnst2'
                                                            */

/* �淶��Perror��λʱ����ֵ */
extern CALDATA const volatile boolean KGSM_ReqEPBSw_flg;/* Referenced by: '<S1622>/Constant1' */

/* ����EPB״̬ǿ�� */
extern CALDATA const volatile EnumEPBReq KGSM_ReqEPBVal_enum;/* Referenced by: '<S1622>/Constant' */

/* ����EPB״̬-�۲�����VGSM_ReqEPB_enum */
extern CALDATA const volatile float32 KGSM_TgtGrReqWatTm_s;/* Referenced by:
                                                            * '<S1682>/Constant1'
                                                            * '<S1682>/Constant2'
                                                            * '<S1683>/Constant1'
                                                            * '<S1683>/Constant3'
                                                            * '<S1728>/Constant4'
                                                            * '<S1729>/Constant4'
                                                            * '<S1792>/Constant4'
                                                            * '<S1793>/Constant4'
                                                            * '<S1794>/Constant4'
                                                            * '<S1834>/Constant4'
                                                            * '<S1835>/Constant4'
                                                            * '<S1836>/Constant4'
                                                            */

/* �淶�������������ʱ����ֵ */
extern CALDATA const volatile boolean KGSM_VehActGearPstnSw_flg;
                                      /* Referenced by: '<S1623>/APA_Switdh4' */

/* ʵ�������λ����ǿ�� */
extern CALDATA const volatile EnumGearPstn KGSM_VehActGearPstnVal_enum;
                                      /* Referenced by: '<S1623>/APA_Switdh5' */

/* ʵ�������λ���� 0-P 1-N 2-D 3-R-�۲�����VGSM_VehActGearPstn_enum */
extern CALDATA const volatile float32 KHMI_BackwSldgBgnEnd_kph;/* Referenced by: '<S652>/Constant1' */
extern CALDATA const volatile float32 KHMI_BackwSldgBgnSpd_kph;/* Referenced by: '<S652>/Constant' */
extern CALDATA const volatile float32 KHMI_BackwSldgDst_m;/* Referenced by: '<S652>/Constant2' */
extern CALDATA const volatile float32 KHMI_BatCellMaxTemWarning_C;/* Referenced by: '<S644>/Constant' */

/* ��о������¶ȣ��޹����¶� */
extern CALDATA const volatile float32 KHMI_BothAccBrkTime_s;/* Referenced by: '<S645>/Constant1' */

/* �������������ж�ʱ�� */
extern CALDATA const volatile float32 KHMI_CellOverTempTime_s;/* Referenced by: '<S644>/Constant1' */

/* ��о�����ж�ʱ�� */
extern CALDATA const volatile float32 KHMI_DriPwrLmtTime_s;/* Referenced by: '<S649>/Constant1' */

/* �������������ж�ʱ�� */
extern CALDATA const volatile float32 KHMI_DriPwrLmtVa_kw;/* Referenced by: '<S649>/Constant' */

/* ��������������ֵ */
extern CALDATA const volatile float32 KHMI_FwdSldgBgnEnd_kph;/* Referenced by: '<S652>/Constant5' */
extern CALDATA const volatile float32 KHMI_FwdSldgBgnSpd_kph;/* Referenced by: '<S652>/Constant4' */
extern CALDATA const volatile float32 KHMI_FwdSldgDst_m;/* Referenced by: '<S652>/Constant6' */
extern CALDATA const volatile float32 KHMI_InfoDispIntervalTm_s;/* Referenced by: '<S641>/Constant27' */

/* InfoDisp���͸��Ǳ�ά��ʱ�� */
extern CALDATA const volatile float32 KHMI_RecPwrLmtTime_s;/* Referenced by: '<S651>/Constant1' */

/* �������������ж�ʱ�� */
extern CALDATA const volatile float32 KHMI_RecPwrLmtVa_kw;/* Referenced by: '<S651>/Constant' */

/* ��������������ֵ */
extern CALDATA const volatile float32 KHMI_SnowModWarnSpd_kph;/* Referenced by: '<S653>/Constant1' */

/* ѩ��ģʽ���ٱ���������ֵ */
extern CALDATA const volatile float32 KHMI_SpdWheelFRdiff_kph;/* Referenced by:
                                                               * '<S654>/Constant1'
                                                               * '<S654>/Constant3'
                                                               * '<S654>/Constant5'
                                                               * '<S654>/Constant7'
                                                               */

/* ���ҳ��ֲ�ֵ��ֵ */
extern CALDATA const volatile float32 KHMI_WarningSendTime_s;/* Referenced by:
                                                              * '<S641>/Constant'
                                                              * '<S641>/Constant10'
                                                              * '<S641>/Constant12'
                                                              * '<S641>/Constant14'
                                                              * '<S641>/Constant16'
                                                              * '<S641>/Constant18'
                                                              * '<S641>/Constant2'
                                                              * '<S641>/Constant20'
                                                              * '<S641>/Constant22'
                                                              * '<S641>/Constant4'
                                                              * '<S641>/Constant6'
                                                              * '<S641>/Constant8'
                                                              */

/* InfoDisp����ά�ַ���ʱ�� */
extern CALDATA const volatile float32 KHVM_ACChrgFltWaitTm_s;/* Referenced by:
                                                              * '<S793>/Constant10'
                                                              * '<S793>/Constant11'
                                                              */

/* ������ŵ���󶵵�ʱ�� */
extern CALDATA const volatile float32 KHVM_ChrgStopWaitTm_s;/* Referenced by: '<S763>/MainState' */

/* OBC��绽��Դ�Ͽ��ȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_ChrgTransCfmTm_s;/* Referenced by:
                                                             * '<S787>/Constant1'
                                                             * '<S787>/Constant11'
                                                             * '<S787>/Constant12'
                                                             * '<S787>/Constant2'
                                                             * '<S787>/Constant3'
                                                             * '<S787>/Constant4'
                                                             * '<S787>/Constant7'
                                                             * '<S787>/Constant9'
                                                             */

/* ��ŵ�״̬ת�Ƶ�������ȷ��ʱ�� */
extern CALDATA const volatile float32 KHVM_ChrgVoltReachCfmTm_s;/* Referenced by:
                                                                 * '<S764>/Constant4'
                                                                 * '<S764>/Constant7'
                                                                 */

/* ��ֱ�����ﵽ��ֹ��ѹȷ��ʱ�� */
extern CALDATA const volatile float32 KHVM_DCCBuckLVVolt_V;/* Referenced by: '<S763>/MainState' */

/* DCDC BUCK ��ѹ */
extern CALDATA const volatile float32 KHVM_DchaStopWaitTm_s;/* Referenced by: '<S763>/MainState' */

/* OBC�ŵ�绽��Դ�Ͽ��ȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_HUChrgngReqHldTm_s;/* Referenced by: '<S793>/Constant8' */

/* HUԤԼ������󱣳�ʱ�� */
extern CALDATA const volatile float32 KHVM_HVCheckTmout_s;/* Referenced by: '<S763>/MainState' */

/* INV&DCDC��ѹ�����ȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_HVCutOffTmout_s;/* Referenced by: '<S763>/MainState' */

/* BMS���̵����Ͽ��ȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_HVDeviceOffTmout_s;/* Referenced by: '<S763>/MainState' */

/* �µ�ر��豸���յ�&DCDC���ȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_HVDschrgTmout_s;/* Referenced by: '<S763>/MainState' */

/* INVй�ŵȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_HVSetUpTmout_s;/* Referenced by: '<S763>/MainState' */

/* ���̵����պϵȴ�ʱ�� */
extern CALDATA const volatile boolean KHVM_INVPreprogm_ovrdflg;/* Referenced by: '<S788>/Constant1' */

/* INV���̱궨���ƿ��� */
extern CALDATA const volatile boolean KHVM_INVPreprogm_ovrdval;/* Referenced by: '<S788>/Constant' */

/* INV���̱궨����ֵ */
extern CALDATA const volatile float32 KHVM_INVholdTm_s;/* Referenced by: '<S763>/MainState' */

/* �µ籣��INVӲ��ʹ���ӳ�ʱ�� */
extern CALDATA const volatile float32 KHVM_KL15OffPwrDwnCfmTm_s;/* Referenced by: '<S792>/Constant4' */

/* KL15�Ͽ�ȷ��ʱ�� */
extern CALDATA const volatile float32 KHVM_MaxHVDCCurntAC_A;/* Referenced by: '<S764>/Constant1' */

/* VCU������OBC����������(ֱ����) */
extern CALDATA const volatile float32 KHVM_MaxHVDCVoltAC_V;/* Referenced by: '<S764>/Constant12' */

/* �����������ѹ */
extern CALDATA const volatile float32 KHVM_OBCS2ClsTmout_s;/* Referenced by: '<S763>/MainState' */

/* S2�պϵȴ�ʱ�� */
extern CALDATA const volatile boolean KHVM_PTRdy2PTStdby_ovrdflg;/* Referenced by: '<S790>/Constant7' */

/* Rdy�˻�Stdby���� */
extern CALDATA const volatile boolean KHVM_PTRdy2PTStdby_ovrdval;/* Referenced by: '<S790>/Constant4' */

/* Rdy�˻�Stdby����ֵ */
extern CALDATA const volatile float32 KHVM_PTRdyBrkSwEffctvTm_s;/* Referenced by: '<S790>/Constant1' */

/* ɲ�������ر���ʱ�� */
extern CALDATA const volatile boolean KHVM_PTStdby2PTRdy_ovrdflg;/* Referenced by: '<S790>/Constant3' */

/* Stdby����Rdy���� */
extern CALDATA const volatile boolean KHVM_PTStdby2PTRdy_ovrdval;/* Referenced by: '<S790>/Constant' */

/* Stdby����Rdy����ֵ */
extern CALDATA const volatile boolean KHVM_PowUpSelfChek_ovrdflg;/* Referenced by: '<S791>/Constant3' */

/* ��ѹ�Լ��������ƿ��� */
extern CALDATA const volatile boolean KHVM_PowUpSelfChek_ovrdval;/* Referenced by: '<S791>/Constant' */

/* ��ѹ�Լ���������ֵ */
extern CALDATA const volatile boolean KHVM_PwrOn2PwrDwn_ovrdflg;/* Referenced by: '<S792>/Constant3' */

/* ��ѹ�µ��������㿪�� */
extern CALDATA const volatile boolean KHVM_PwrOn2PwrDwn_ovrdval;/* Referenced by: '<S792>/Constant' */

/* ��ѹ�µ������������ֵ */
extern CALDATA const volatile float32 KHVM_PwrUpACChrgEffctvTm_s;/* Referenced by: '<S793>/Constant1' */

/* OBC����Դ�����ر���ʱ�� */
extern CALDATA const volatile float32 KHVM_PwrUpDCChrgEffctvTm_s;/* Referenced by: '<S793>/Constant4' */

/* BMS����Դ�����ر���ʱ�� */
extern CALDATA const volatile float32 KHVM_PwrUpIBSDlyTm_s;/* Referenced by: '<S793>/Constant5' */

/* IBS����Դ�ӳ�ʱ�� */
extern CALDATA const volatile float32 KHVM_PwrUpIBSEffctvTm_s;/* Referenced by: '<S793>/Constant9' */

/* IBS�����ر���ʱ�� */
extern CALDATA const volatile float32 KHVM_PwrUpKL15EffctvTm_s;/* Referenced by: '<S793>/Constant17' */

/* KL15�����ر���ʱ�� */
extern CALDATA const volatile float32 KHVM_SOCExtrmLo_pct;/* Referenced by: '<S766>/Constant9' */

/* SOC������ֵ */
extern CALDATA const volatile float32 KHVM_SOCLoPwrDwnDlyTm_s;/* Referenced by: '<S792>/Constant2' */

/* SOC����ȷ��ʱ�� */
extern CALDATA const volatile float32 KHVM_SOPExtrmLo_kW;/* Referenced by: '<S766>/Constant3' */

/* SOP������ֵ */
extern CALDATA const volatile float32 KHVM_SleepWaitTm_s;/* Referenced by: '<S763>/MainState' */

/* �µ�������ߵȴ�ʱ�� */
extern CALDATA const volatile float32 KHVM_TBOXReSetACChgTm_s;/* Referenced by: '<S764>/Constant6' */

/* TBOXԶ�̳�����󱣳�ʱ�� */
extern CALDATA const volatile boolean KHVM_Tbox2OBCOprtCmd_ovrdflg;/* Referenced by: '<S764>/Constant9' */

/* TBOXԶ�̳�翪�� */
extern CALDATA const volatile uint8 KHVM_Tbox2OBCOprtCmd_ovrdval;/* Referenced by: '<S764>/Constant' */

/* TBOXԶ�̳��궨ֵ */
extern CALDATA const volatile float32 KHVM_VehHaltCfmTm_s;/* Referenced by: '<S766>/Constant7' */

/* ����ֹͣ����ȷ��ʱ�� */
extern CALDATA const volatile float32 KHVM_VehHaltSpd_kph;/* Referenced by: '<S766>/Constant10' */

/* ����ֹͣ������ֵ */
extern CALDATA const volatile float32 KHVM_VehMoveCfmTm_s;/* Referenced by: '<S766>/Constant12' */

/* �����˶�����ȷ��ʱ�� */
extern CALDATA const volatile float32 KHVM_VehSpdLo_kph;/* Referenced by: '<S766>/Constant2' */

/* �ͳ�����ֵ */
extern CALDATA const volatile boolean KHVM_WakeUp2PwrUp_ovrdflg;/* Referenced by: '<S793>/Constant6' */

/* ���ѵ��ϸ�ѹ�������� */
extern CALDATA const volatile boolean KHVM_WakeUp2PwrUp_ovrdval;/* Referenced by: '<S793>/Constant' */

/* ���ѵ��ϸ�ѹ��������ֵ */
extern CALDATA const volatile boolean KHVM_WakeUpVCU_ovrdflg;/* Referenced by: '<S794>/Constant1' */

/* ���ߵ������������ƿ��� */
extern CALDATA const volatile boolean KHVM_WakeUpVCU_ovrdval;/* Referenced by: '<S794>/Constant' */

/* ���ߵ�������������ֵ */
extern CALDATA const volatile uint8 KIBS_ChgMaxNumThr_cnt;/* Referenced by:
                                                           * '<S1031>/Constant'
                                                           * '<S1031>/Constant6'
                                                           */

/* ��󲹵������ֵ_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgCurntOKThr_A;/* Referenced by: '<S1029>/ChrgSt' */

/* IBS��������ֵ_versteckt */
extern CALDATA const volatile uint16 KIBS_ChrgFailTmThr_min;/* Referenced by: '<S1029>/ChrgSt' */

/* IBS�������ʱ����ֵ_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgTempThr1_C;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����¶���ֵ1_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgTempThr2_C;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����¶���ֵ2_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgTempThr3_C;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����¶���ֵ3_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr1_V;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����ѹ��ֵ1_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr2_V;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����ѹ��ֵ2_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr3_V;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����ѹ��ֵ3_versteckt */
extern CALDATA const volatile float32 KIBS_ChrgVoltThr4_V;/* Referenced by: '<S1032>/VoltState' */

/* IBS�����ѹ��ֵ4_versteckt */
extern CALDATA const volatile uint16 KIBS_CurntOKTmThr_min;/* Referenced by: '<S1029>/ChrgSt' */

/* IBS�������ﵽ��ֵȷ��ʱ��_versteckt */
extern CALDATA const volatile float32 KIBS_DfltEnvirTemp_C;/* Referenced by: '<S1032>/Constant1' */

/* AC�����¶�ʧЧʱ��Ĭ�ϵĻ����¶�_versteckt */
extern CALDATA const volatile float32 KIBS_EnvirTemptFiltCoeff_c;/* Referenced by: '<S1032>/Constant3' */

/* �����¶��˲�ϵ��_versteckt */
extern CALDATA const volatile uint8 KIBS_FailChgNumThr_cnt;/* Referenced by:
                                                            * '<S1031>/Constant10'
                                                            * '<S1031>/Constant12'
                                                            */

/* ��󲹵�ʧ�ܴ�����ֵ_versteckt */
extern CALDATA const volatile boolean KIBS_FbIBSWup_flg;/* Referenced by: '<S1031>/Constant17' */

/* ��ֹIBS�����ֶ�����_versteckt */
extern CALDATA const volatile uint16 KIBS_FbRctWupThr_min;/* Referenced by: '<S1032>/Constant10' */

/* ��ֹRTC�������õ�ʱ��_versteckt */
extern CALDATA const volatile uint16 KIBS_HoldNMTmThr_s;/* Referenced by: '<S1031>/Constant14' */

/* IBS���ѱ�������ʱ��_versteckt */
extern CALDATA const volatile uint8 KIBS_KL30VoltDebNumThr_cnt;/* Referenced by: '<S1049>/Constant2' */

/* KL30��ѹ���ڲ����ѹ�ܴ���_versteckt */
extern CALDATA const volatile float32 KIBS_KL30VoltDebTmThr_s;/* Referenced by: '<S1032>/Constant7' */

/* KL30��ѹ�Ƿ��������ʱ��_versteckt */
extern CALDATA const volatile float32 KIBS_KL30VoltFiltCoeff_c;/* Referenced by: '<S1032>/Constant2' */

/* KL30��ѹ�˲�ϵ��_versteckt */
extern CALDATA const volatile uint16 KIBS_StWaitTm_s;/* Referenced by: '<S1032>/Constant5' */

/* IBS״̬����ѹ&�¶ȣ��ȶ�ʱ��_versteckt */
extern CALDATA const volatile uint8 KIBS_WakeupReas_enum;/* Referenced by: '<S1047>/Constant' */

/* �ײ㻽��ԭ��ö��ֵ_versteckt */
extern CALDATA const volatile uint16 KIBS_WupChgTmThr1_min;/* Referenced by: '<S1029>/ChrgSt' */

/* IBS����ʱ����ֵ1_versteckt */
extern CALDATA const volatile boolean KIPC_ACCCfgOvrdSw_flg;
                          /* Referenced by: '<S903>/KIPC_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile boolean KIPC_ACCCfgOvrdVal_flg;
                         /* Referenced by: '<S903>/KIPC_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile float32 KIPC_AccPed1FullPstn_pct;/* Referenced by: '<S911>/Constant2' */
extern CALDATA const volatile float32 KIPC_AccPed2FullPstn_pct;/* Referenced by: '<S913>/Constant6' */
extern CALDATA const volatile float32 KIPC_AccPedDbnd_pct;
                   /* Referenced by: '<S905>/cnst_ValidCheck_EngCoolantTemp1' */
extern CALDATA const volatile float32 KIPC_AccPedInitTm_s;
                               /* Referenced by: '<S908>/KIPC_AccPedInitTm_s' */
extern CALDATA const volatile float32 KIPC_AccPedLrnDwnFiltCoeff_rat;/* Referenced by:
                                                                      * '<S910>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                      * '<S912>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                      */
extern CALDATA const volatile float32 KIPC_AccPedLrnDwnStabThr_pct;/* Referenced by:
                                                                    * '<S910>/KAccPed_Threshold1ISLow_V6'
                                                                    * '<S912>/KAccPed_Threshold1ISLow_V6'
                                                                    */
extern CALDATA const volatile float32 KIPC_AccPedLrnDwnStabTm_s;/* Referenced by:
                                                                 * '<S910>/KAccPed_Threshold1ISLow_V5'
                                                                 * '<S912>/KAccPed_Threshold1ISLow_V5'
                                                                 */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnHi_pct;/* Referenced by:
                                                                * '<S910>/KAccPed_Threshold1ISLow_V10'
                                                                * '<S910>/KAccPed_Threshold1ISLow_V11'
                                                                * '<S912>/KAccPed_Threshold1ISLow_V10'
                                                                * '<S912>/KAccPed_Threshold1ISLow_V11'
                                                                */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnLo_pct;/* Referenced by:
                                                                * '<S910>/KAccPed_Threshold1ISLow_V8'
                                                                * '<S912>/KAccPed_Threshold1ISLow_V8'
                                                                */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnLrnUpHi_pct;/* Referenced by:
                                                                     * '<S910>/KAccPed_Threshold1ISLow_V2'
                                                                     * '<S912>/KAccPed_Threshold1ISLow_V2'
                                                                     */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnLrnUpLo_pct;/* Referenced by:
                                                                     * '<S910>/KAccPed_Threshold1ISLow_V1'
                                                                     * '<S912>/KAccPed_Threshold1ISLow_V1'
                                                                     */
extern CALDATA const volatile float32 KIPC_AccPedMinPstnUpOfst_pct;/* Referenced by:
                                                                    * '<S910>/KAccPed_Threshold1ISLow_V7'
                                                                    * '<S912>/KAccPed_Threshold1ISLow_V7'
                                                                    */
extern CALDATA const volatile float32 KIPC_AccPedNormzPstnFiltTm_s;/* Referenced by:
                                                                    * '<S907>/KIPC_AccPedLrnDwnFiltCoeff_rat'
                                                                    * '<S907>/KIPC_AccPedLrnDwnFiltCoeff_rat1'
                                                                    */
extern CALDATA const volatile float32 KIPC_AccPedPrsdThr4Stk_pct;
                           /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V1' */
extern CALDATA const volatile float32 KIPC_AccPedPstnLmt_pct;
                   /* Referenced by: '<S905>/cnst_ValidCheck_EngCoolantTemp5' */
extern CALDATA const volatile boolean KIPC_AccPedPstnOvrdSw_flg;
                   /* Referenced by: '<S905>/cnst_ValidCheck_EngCoolantTemp3' */
extern CALDATA const volatile float32 KIPC_AccPedPstnOvrdVal_pct;
                   /* Referenced by: '<S905>/cnst_ValidCheck_EngCoolantTemp4' */
extern CALDATA const volatile float32 KIPC_AccPedSclRng_pct;/* Referenced by:
                                                             * '<S911>/cnst_ValidCheck_EngCoolantTemp1'
                                                             * '<S913>/cnst_ValidCheck_EngCoolantTemp3'
                                                             */
extern CALDATA const volatile boolean KIPC_AccPedStkDiagEnbl_flg;
                           /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V7' */
extern CALDATA const volatile float32 KIPC_AccPedStkFiltCoeff_rat;
                       /* Referenced by: '<S908>/KIPC_AccPedStkFiltCoeff_rat' */
extern CALDATA const volatile float32 KIPC_AccPedStkStabThr_pct;
                        /* Referenced by: '<S908>/KAccPed_Threshold1ISLow_V6' */
extern CALDATA const volatile float32 KIPC_AccPedStkStabTm_s;
                        /* Referenced by: '<S908>/KAccPed_Threshold1ISLow_V5' */
extern CALDATA const volatile float32 KIPC_AccPedSwThr_pct;
                   /* Referenced by: '<S905>/cnst_ValidCheck_EngCoolantTemp2' */

/* ���ſ��ؿ�����ֵ */
extern CALDATA const volatile float32 KIPC_AccPedZeroPstnDecRate_pctps;
                          /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V18' */
extern CALDATA const volatile float32 KIPC_AccPedZeroPstnIncRate_pctps;
                          /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V17' */
extern CALDATA const volatile float32 KIPC_BrkPedPrsdThr4Stk_pct;
                          /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V11' */
extern CALDATA const volatile float32 KIPC_BrkPedPstnDfltPrsd_pct;/* Referenced by: '<S900>/Constant2' */
extern CALDATA const volatile boolean KIPC_BrkPedPstnOvrdSw_flg;
                   /* Referenced by: '<S900>/cnst_ValidCheck_EngCoolantTemp2' */
extern CALDATA const volatile float32 KIPC_BrkPedPstnOvrdVal_pct;
                   /* Referenced by: '<S900>/cnst_ValidCheck_EngCoolantTemp3' */
extern CALDATA const volatile float32 KIPC_BrkPedReldThr4Stk_pct;
                           /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V2' */
extern CALDATA const volatile float32 KIPC_BrkSwPrsdPedPstn_pct;
                             /* Referenced by: '<S900>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile boolean KIPC_CCSCfgOvrdSw_flg;
                          /* Referenced by: '<S903>/KIPC_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile boolean KIPC_CCSCfgOvrdVal_flg;
                         /* Referenced by: '<S903>/KIPC_LimpHomeOvrdVal_flg1' */
extern CALDATA const volatile boolean KIPC_CrpCtrlCfgOvrdSw_flg;
                          /* Referenced by: '<S903>/KIPC_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile boolean KIPC_CrpCtrlCfgOvrdVal_flg;
                         /* Referenced by: '<S903>/KIPC_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile boolean KIPC_CrpModeActOvrdSw_flg;
                           /* Referenced by: '<S902>/KIPC_LimpHomeOvrdSw_flg' */
extern CALDATA const volatile EnumCrpModeAct KIPC_CrpModeActOvrdVal_enum;
                          /* Referenced by: '<S902>/KIPC_LimpHomeOvrdVal_flg' */
extern CALDATA const volatile boolean KIPC_DrvModeActOvrdSw_flg;
                          /* Referenced by: '<S902>/KIPC_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile EnumDrvModeAct KIPC_DrvModeActOvrdVal_enum;
                         /* Referenced by: '<S902>/KIPC_LimpHomeOvrdVal_flg1' */
extern CALDATA const volatile boolean KIPC_DrvPwrIntnstyOvrdSw_flg;
                          /* Referenced by: '<S902>/KIPC_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile uint8 KIPC_DrvPwrIntnstyOvrdVal_pct;
                         /* Referenced by: '<S902>/KIPC_LimpHomeOvrdVal_flg4' */
extern CALDATA const volatile boolean KIPC_ESCVehSpdPrio_flg;
                                /* Referenced by: '<S971>/KSYS_VehTransRto_c' */
extern CALDATA const volatile boolean KIPC_ESCWhlSpdPrio_flg;
                               /* Referenced by: '<S971>/KSYS_VehTransRto_c2' */
extern CALDATA const volatile boolean KIPC_EnblFltRstAccPedZP_flg;
                           /* Referenced by: '<S908>/KAPD_Threshold1ISLow_V3' */
extern CALDATA const volatile boolean KIPC_EnblVpedAutoCrp_flg;/* Referenced by: '<S939>/Shift_enum1' */
extern CALDATA const volatile float32 KIPC_ExitAutoCrpDrvDist_m;
                         /* Referenced by: '<S939>/KIPC_ExitAutoCrpDrvDist_m' */
extern CALDATA const volatile float32 KIPC_ExitAutoCrpPNDurTm_s;/* Referenced by: '<S939>/Shift_enum4' */
extern CALDATA const volatile float32 KIPC_ExitAutoCrpVehSpd_kph;
                        /* Referenced by: '<S939>/KIPC_ExitAutoCrpVehSpd_kph' */
extern CALDATA const volatile boolean KIPC_HDCCfgOvrdSw_flg;
                          /* Referenced by: '<S903>/KIPC_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile boolean KIPC_HDCCfgOvrdVal_flg;
                         /* Referenced by: '<S903>/KIPC_LimpHomeOvrdVal_flg4' */
extern CALDATA const volatile boolean KIPC_RegenModeActOvrdSw_flg;
                          /* Referenced by: '<S902>/KIPC_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile EnumRegenModeAct KIPC_RegenModeActOvrdVal_enum;
                         /* Referenced by: '<S902>/KIPC_LimpHomeOvrdVal_flg3' */
extern CALDATA const volatile boolean KIPC_RegenPwrIntnstyOvrdSw_flg;
                          /* Referenced by: '<S902>/KIPC_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile uint8 KIPC_RegenPwrIntnstyOvrdVal_pct;
                         /* Referenced by: '<S902>/KIPC_LimpHomeOvrdVal_flg5' */
extern CALDATA const volatile boolean KIPC_SnowModeDft_flg;/* Referenced by: '<S902>/Unit Delay3' */
extern CALDATA const volatile boolean KIPC_SnowModeOvrdSw_flg;
                          /* Referenced by: '<S902>/KIPC_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile boolean KIPC_SnowModeOvrdVal_flg;
                         /* Referenced by: '<S902>/KIPC_LimpHomeOvrdVal_flg2' */
extern CALDATA const volatile float32 KIPC_VehHiddenBtnSyncnTm_s;/* Referenced by:
                                                                  * '<S902>/Cnst4'
                                                                  * '<S902>/Cnst6'
                                                                  * '<S902>/Cnst9'
                                                                  */
extern CALDATA const volatile float32 KIPC_VehHiddenModeWaitTm_s;/* Referenced by:
                                                                  * '<S902>/Cnst1'
                                                                  * '<S902>/Cnst2'
                                                                  * '<S902>/Cnst3'
                                                                  * '<S902>/Cnst5'
                                                                  * '<S902>/Cnst7'
                                                                  */
extern CALDATA const volatile boolean KIPC_iTPMSCfgOvrdSw_flg;
                          /* Referenced by: '<S903>/KIPC_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile boolean KIPC_iTPMSCfgOvrdVal_flg;
                         /* Referenced by: '<S903>/KIPC_LimpHomeOvrdVal_flg5' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVoltHi_mV;/* Referenced by: '<S1575>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVoltLo_mV;/* Referenced by: '<S1575>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh1SuplyVolt_mV_ovrdflg;/* Referenced by: '<S1575>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1SuplyVolt_mV_ovrdval;/* Referenced by: '<S1575>/sat4' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1VoltHi_mV;/* Referenced by: '<S1576>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1VoltLo_mV;/* Referenced by: '<S1576>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh1Volt_mV_ovrdflg;/* Referenced by: '<S1576>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh1Volt_mV_ovrdval;/* Referenced by: '<S1576>/sat4' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVoltHi_mV;/* Referenced by: '<S1577>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVoltLo_mV;/* Referenced by: '<S1577>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh2SuplyVolt_mV_ovrdflg;/* Referenced by: '<S1577>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2SuplyVolt_mV_ovrdval;/* Referenced by: '<S1577>/sat4' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2VoltHi_mV;/* Referenced by: '<S1578>/sat6' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2VoltLo_mV;/* Referenced by: '<S1578>/sat7' */
extern CALDATA const volatile boolean KIPM_HwAccPedCh2Volt_mV_ovrdflg;/* Referenced by: '<S1578>/sat3' */
extern CALDATA const volatile float32 KIPM_HwAccPedCh2Volt_mV_ovrdval;/* Referenced by: '<S1578>/sat4' */
extern CALDATA const volatile boolean KIPM_HwBMSWakeup_flg_ovrdflg;/* Referenced by: '<S1579>/sat3' */
extern CALDATA const volatile boolean KIPM_HwBMSWakeup_flg_ovrdval;/* Referenced by: '<S1579>/sat4' */
extern CALDATA const volatile boolean KIPM_HwBrkSwHi_flg_ovrdflg;/* Referenced by: '<S1580>/sat3' */
extern CALDATA const volatile boolean KIPM_HwBrkSwHi_flg_ovrdval;/* Referenced by: '<S1580>/sat4' */
extern CALDATA const volatile boolean KIPM_HwBrkSwLo_flg_ovrdflg;/* Referenced by: '<S1581>/sat3' */
extern CALDATA const volatile boolean KIPM_HwBrkSwLo_flg_ovrdval;/* Referenced by: '<S1581>/sat4' */
extern CALDATA const volatile boolean KIPM_HwCrpModeSw_flg_ovrdflg;/* Referenced by: '<S1582>/sat3' */
extern CALDATA const volatile boolean KIPM_HwCrpModeSw_flg_ovrdval;/* Referenced by: '<S1582>/sat4' */
extern CALDATA const volatile boolean KIPM_HwDrvModeSw_flg_ovrdflg;/* Referenced by: '<S1583>/sat3' */
extern CALDATA const volatile boolean KIPM_HwDrvModeSw_flg_ovrdval;/* Referenced by: '<S1583>/sat4' */
extern CALDATA const volatile boolean KIPM_HwEmgcyShutOff_flg_ovrdflg;/* Referenced by: '<S1584>/sat3' */
extern CALDATA const volatile boolean KIPM_HwEmgcyShutOff_flg_ovrdval;/* Referenced by: '<S1584>/sat4' */
extern CALDATA const volatile float32 KIPM_HwHVIL1VoltHi_mV;/* Referenced by: '<S1585>/sat6' */
extern CALDATA const volatile float32 KIPM_HwHVIL1VoltLo_mV;/* Referenced by: '<S1585>/sat7' */
extern CALDATA const volatile boolean KIPM_HwHVIL1Volt_mV_ovrdflg;/* Referenced by: '<S1585>/sat3' */
extern CALDATA const volatile float32 KIPM_HwHVIL1Volt_mV_ovrdval;/* Referenced by: '<S1585>/sat4' */
extern CALDATA const volatile float32 KIPM_HwHVIL2VoltHi_mV;/* Referenced by: '<S1586>/sat6' */
extern CALDATA const volatile float32 KIPM_HwHVIL2VoltLo_mV;/* Referenced by: '<S1586>/sat7' */
extern CALDATA const volatile boolean KIPM_HwHVIL2Volt_mV_ovrdflg;/* Referenced by: '<S1586>/sat3' */
extern CALDATA const volatile float32 KIPM_HwHVIL2Volt_mV_ovrdval;/* Referenced by: '<S1586>/sat4' */
extern CALDATA const volatile boolean KIPM_HwKL15A_flg_ovrdflg;/* Referenced by: '<S1587>/sat3' */
extern CALDATA const volatile boolean KIPM_HwKL15A_flg_ovrdval;/* Referenced by: '<S1587>/sat4' */
extern CALDATA const volatile boolean KIPM_HwKL15B_flg_ovrdflg;/* Referenced by: '<S1588>/sat3' */
extern CALDATA const volatile boolean KIPM_HwKL15B_flg_ovrdval;/* Referenced by: '<S1588>/sat4' */
extern CALDATA const volatile uint16 KIPM_HwKL30Hi_mV;/* Referenced by: '<S1589>/sat6' */
extern CALDATA const volatile uint16 KIPM_HwKL30Lo_mV;/* Referenced by: '<S1589>/sat7' */
extern CALDATA const volatile boolean KIPM_HwKL30_mV_ovrdflg;/* Referenced by: '<S1589>/sat3' */
extern CALDATA const volatile uint16 KIPM_HwKL30_mV_ovrdval;/* Referenced by: '<S1589>/sat4' */
extern CALDATA const volatile boolean KIPM_HwOBCWakeup_flg_ovrdflg;/* Referenced by: '<S1590>/sat3' */
extern CALDATA const volatile boolean KIPM_HwOBCWakeup_flg_ovrdval;/* Referenced by: '<S1590>/sat4' */
extern CALDATA const volatile boolean KIPM_HwRearFogLampSwt_flg_ovrdflg;/* Referenced by: '<S1591>/sat3' */
extern CALDATA const volatile boolean KIPM_HwRearFogLampSwt_flg_ovrdval;/* Referenced by: '<S1591>/sat4' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwPrsdHi_Ohm;/* Referenced by: '<S1594>/Constant' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwPrsdLo_Ohm;/* Referenced by: '<S1594>/Constant1' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwReldHi_Ohm;/* Referenced by: '<S1594>/Constant3' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwReldLo_Ohm;/* Referenced by: '<S1594>/Constant4' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwShtBatt_Ohm;/* Referenced by: '<S1594>/Constant5' */
extern CALDATA const volatile uint16 KIPM_HwShftPstnSwShtGnd_Ohm;/* Referenced by: '<S1594>/Constant7' */
extern CALDATA const volatile boolean KIPM_HwShftPstnSwSts_enum_ovrdflg;/* Referenced by: '<S1592>/sat3' */
extern CALDATA const volatile EnumPGearSwSts KIPM_HwShftPstnSwSts_enum_ovrdval;/* Referenced by: '<S1592>/sat4' */
extern CALDATA const volatile boolean KIPM_HwVehCrash_flg_ovrdflg;/* Referenced by: '<S1593>/sat3' */
extern CALDATA const volatile boolean KIPM_HwVehCrash_flg_ovrdval;/* Referenced by: '<S1593>/sat4' */
extern CALDATA const volatile boolean KOPM_HwWakeupBMS_flg_ovrdflg;/* Referenced by: '<S1607>/sat3' */
extern CALDATA const volatile boolean KOPM_HwWakeupBMS_flg_ovrdval;/* Referenced by: '<S1607>/sat4' */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm100NumWghtFac_c;/* Referenced by: '<S1010>/Constant9' */

/* ǰ100�������ܺļ�Ȩϵ�� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm10NumWghtFac_c;/* Referenced by: '<S1010>/Constant5' */

/* ǰ10�������ܺļ�Ȩϵ�� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm15NumWghtFac_c;/* Referenced by: '<S1010>/Constant6' */

/* ǰ15�������ܺļ�Ȩϵ�� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm1NumWghtFac_c;/* Referenced by: '<S1010>/Constant3' */

/* ��ʼ�����Ȩϵ�� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm25NumWghtFac_c;/* Referenced by: '<S1010>/Constant7' */

/* ǰ25�������ܺļ�Ȩϵ�� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm50NumWghtFac_c;/* Referenced by: '<S1010>/Constant8' */

/* ǰ50�������ܺļ�Ȩϵ�� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsm5NumWghtFac_c;/* Referenced by: '<S1010>/Constant4' */

/* ǰ5�������ܺļ�Ȩϵ�� */
extern CALDATA const volatile boolean KRME_AvgSOCCnsmWghtSw_flg;/* Referenced by: '<S1010>/Constant10' */

/* ��ȨSOC����ǿ�ؿ��� */
extern CALDATA const volatile float32 KRME_AvgSOCCnsmWghtVal_pctpkm;/* Referenced by: '<S1010>/Constant11' */

/* ��ȨSOC����ǿ��ֵ */
extern CALDATA const volatile float32 KRME_CHTCRmnMilEstVldOff_km;/* Referenced by: '<S980>/Constant4' */

/* ��׼����CHTC��Ч��Off */
extern CALDATA const volatile float32 KRME_CHTCRmnMilEstVldOn_km;/* Referenced by: '<S980>/Constant7' */

/* ��׼����CHTC��Ч��On */
extern CALDATA const volatile float32 KRME_CalPwrCnsmTgtDist_m;/* Referenced by:
                                                                * '<S984>/Constant8'
                                                                * '<S984>/Constant9'
                                                                */

/* Pwr���ĵ�λ��� */
extern CALDATA const volatile float32 KRME_CalPwrCnsmVehThr_kph;/* Referenced by: '<S984>/Constant1' */

/* ����Pwr���ĳ���ֵ */
extern CALDATA const volatile float32 KRME_CalSOCCnsmTgtDist_m;/* Referenced by:
                                                                * '<S1009>/Constant2'
                                                                * '<S1009>/Constant8'
                                                                * '<S1009>/Constant9'
                                                                */

/* SOC���ĵ�λ��� */
extern CALDATA const volatile float32 KRME_CalSOCCnsmVehThr_kph;/* Referenced by:
                                                                 * '<S988>/Constant1'
                                                                 * '<S1007>/Constant10'
                                                                 * '<S1009>/Constant1'
                                                                 */

/* ����SOC���ĳ���ֵ */
extern CALDATA const volatile float32 KRME_ChrgOfstSOCVal_pct;/* Referenced by:
                                                               * '<S995>/Constant1'
                                                               * '<S995>/Constant2'
                                                               */

/* ���ģʽSOCƫ��ֵ */
extern CALDATA const volatile float32 KRME_DchaVehStpDlyTm_s;/* Referenced by: '<S1007>/Constant11' */

/* ����ֹͣȷ��ʱ�� */
extern CALDATA const volatile float32 KRME_NVMMilDwLim_km;/* Referenced by: '<S987>/Constant2' */

/* NVM�洢��̬��������ֵ */
extern CALDATA const volatile float32 KRME_NVMMilUpLim_km;/* Referenced by: '<S987>/Constant8' */

/* NVM�洢��̬��������ֵ */
extern CALDATA const volatile float32 KRME_NVMSOCCnsmDwLim_pctp100km;/* Referenced by: '<S1010>/Constant2' */

/* NVM�洢SOC��������ֵ������100km���㣩 */
extern CALDATA const volatile float32 KRME_NVMSOCCnsmUpLim_pctp100km;/* Referenced by: '<S1010>/Constant1' */

/* NVM�洢SOC��������ֵ������100km���㣩 */
extern CALDATA const volatile uint8 KRME_SOCCnsmStorRst_enum;/* Referenced by: '<S1010>/Constant64' */

/* ����SOCCnse����洢ֵ(�궨ʹ��) */
extern CALDATA const volatile boolean KRME_SOHCrctFacEnbl_flg;/* Referenced by: '<S980>/Constant2' */

/* ʹ��SOH��RptSOC���� */
extern CALDATA const volatile boolean KRME_WLTPCtrlModeSel_flg;/* Referenced by: '<S987>/Constant13' */

/* WLTP���Ʒ�ʽѡ��:0-��̬���� 1-���WLTP���� */
extern CALDATA const volatile float32 KRME_WLTPRmnMilEstVldOff_km;/* Referenced by: '<S987>/Constant17' */

/* ��̬����WLTP��Ч��Off */
extern CALDATA const volatile float32 KRME_WLTPRmnMilEstVldOn_km;/* Referenced by: '<S987>/Constant18' */

/* ��̬����WLTP��Ч��On */
extern CALDATA const volatile float32 KRME_WLTPStdUpLimFac_c;/* Referenced by: '<S989>/Constant7' */

/* ���ڱ�׼����WLTP�������ϵ�� */
extern CALDATA const volatile uint8 KSYS_CalVer_cnt;
                           /* Referenced by: '<S1605>/ASYS_HVBatPackTyp_X_Ah' */
extern CALDATA const volatile boolean KSYS_ChkTaskRunCnt_flg;
                          /* Referenced by: '<S1605>/ASYS_HVBatPackTyp_X_Ah1' */
extern CALDATA const volatile float32 KSYS_VehMass_kg;/* Referenced by:
                                                       * '<S17>/KVTM_VehMass_kg'
                                                       * '<S1208>/KDAC_TapDwnTmOut_s6'
                                                       * '<S1162>/KDAC_TapDwnTmOut_s6'
                                                       * '<S1409>/KDAC_TapDwnTmOut_s1'
                                                       * '<S1280>/KDAC_TapDwnTmOut_s'
                                                       */
extern CALDATA const volatile float32 KSYS_VehTransRto_c;/* Referenced by:
                                                          * '<S904>/KSYS_VehTransRto_c'
                                                          * '<S1230>/KSYS_VehTransRto_c'
                                                          * '<S1230>/KSYS_VehTransRto_c1'
                                                          * '<S1560>/KSYS_VehTransRto_c3'
                                                          * '<S1561>/KSYS_VehTransRto_c1'
                                                          * '<S1561>/KSYS_VehTransRto_c2'
                                                          * '<S1213>/KSYS_VehTransRto_c1'
                                                          * '<S1373>/KSYS_VehTransRto_c'
                                                          * '<S1510>/KSYS_VehTransRto_c1'
                                                          * '<S1510>/KSYS_VehTransRto_c2'
                                                          * '<S1452>/KSYS_VehTransRto_c'
                                                          * '<S1453>/KSYS_VehTransRto_c'
                                                          * '<S1470>/KSYS_VehTransRto_c'
                                                          * '<S1470>/KSYS_VehTransRto_c1'
                                                          * '<S1427>/KSYS_VehTransRto_c'
                                                          */
extern CALDATA const volatile float32 KTBX_ChrgCondCfmTmr_s;/* Referenced by: '<S1082>/Constant3' */

/* ��������ж�ʱ�� */
extern CALDATA const volatile float32 KTBX_CnclSpdLimTmr_s;/* Referenced by: '<S1082>/Constant9' */

/* ȡ�����ٵȼ�ȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_LckVerCfmTmr_s;/* Referenced by: '<S1082>/Constant1' */

/* �����汾ȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_LoSpdCfmTmr_s;/* Referenced by: '<S1082>/Constant6' */

/* �ͳ���ȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_RecryCommCfmTmr_s;/* Referenced by: '<S1082>/Constant10' */

/* TBOXͨѶ�ָ�ȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_RmtACStFbMaxTmr_s;
                         /* Referenced by: '<S1062>/KVTM_LimpHomeOvrdSw_flg5' */

/* Զ�̿յ�״̬�������ʱ�� */
extern CALDATA const volatile float32 KTBX_RmtEnblACLwSOC_pct;/* Referenced by:
                                                               * '<S1062>/KVTM_LimpHomeOvrdSw_flg1'
                                                               * '<S1062>/KVTM_LimpHomeOvrdSw_flg2'
                                                               */

/* Զ�̿����յ����SOC */
extern CALDATA const volatile float32 KTBX_SpdLimCfmTmr_s;/* Referenced by:
                                                           * '<S1082>/Constant4'
                                                           * '<S1082>/Constant5'
                                                           * '<S1082>/Constant8'
                                                           */

/* ���ٵȼ�ȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_TBOXLostCommTmr_s;/* Referenced by: '<S1082>/Constant2' */

/* TBOXͨѶ��ʧȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_UnlckVerCfmTmr_s;/* Referenced by: '<S1082>/Constant' */

/* �������汾ȷ��ʱ�� */
extern CALDATA const volatile float32 KTBX_VehLoSpdThr_kph;/* Referenced by:
                                                            * '<S1081>/Constant35'
                                                            * '<S1082>/Constant7'
                                                            */

/* �ͳ��ٷ�ֵ */
extern CALDATA const volatile boolean KTQC_ABSInhbBrkRegen_flg;
                      /* Referenced by: '<S1374>/KTQD_CstRegenVehSpdOff_kph1' */
extern CALDATA const volatile float32 KTQC_ABSorESPActvTm1_s;
                      /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal' */
extern CALDATA const volatile float32 KTQC_ABSorESPActvTm2_s;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal1' */
extern CALDATA const volatile float32 KTQC_BrkRegenTgtTqDecRate_Nmps;
                       /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm5' */
extern CALDATA const volatile float32 KTQC_BrkRegenTgtTqIncRate_Nmps;
                       /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm4' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqDecRecry_Nmps;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal5' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqDecSlow_Nmps;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal4' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqIncPhs1_Nmps;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal2' */
extern CALDATA const volatile float32 KTQC_CstRegenLmtTqIncPhs2_Nmps;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal3' */
extern CALDATA const volatile float32 KTQC_DrvTqHiDsblRBSDlyTm_s;
                       /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm3' */
extern CALDATA const volatile float32 KTQC_DrvTqHiDsblRBSThr_Nm;
                       /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm2' */
extern CALDATA const volatile float32 KTQC_DrvTqLoEnblRBSDlyTm_s;
                       /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm1' */
extern CALDATA const volatile float32 KTQC_DrvTqLoEnblRBSThr_Nm;
                        /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm' */
extern CALDATA const volatile float32 KTQC_ESCTqIntvAllwdVal_Nm;/* Referenced by:
                                                                 * '<S1553>/DrvCtl_DrvMot_MaxTrqFlg_Cal'
                                                                 * '<S1553>/DrvCtl_DrvMot_MaxTrqFlg_Cal1'
                                                                 * '<S1373>/DrvCtl_DrvMot_MaxTrqFlg_Cal'
                                                                 * '<S1373>/DrvCtl_DrvMot_MaxTrqFlg_Cal1'
                                                                 */
extern CALDATA const volatile boolean KTQC_EnblBrkRsmCstRegen_flg;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal8' */
extern CALDATA const volatile boolean KTQC_EnblESPIntvBrkTgtZero_flg;
                       /* Referenced by: '<S1374>/KTQC_DrvTqLoEnblRBSThr_Nm6' */
extern CALDATA const volatile boolean KTQC_EnblRBSIntv_flg;
                       /* Referenced by: '<S1374>/KTQD_CstRegenVehSpdOff_kph' */
extern CALDATA const volatile float32 KTQC_RsmCstRegenAccPed_pct;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal6' */
extern CALDATA const volatile float32 KTQC_RsmCstRegenTqReq_Nm;
                     /* Referenced by: '<S1372>/DrvCtl_DrvMot_MaxTrqFlg_Cal7' */
extern CALDATA const volatile float32 KTQD_AccelPedPrsdOff_pct;
                       /* Referenced by: '<S1435>/KTQD_CstRegenVehSpdOn_kph1' */
extern CALDATA const volatile float32 KTQD_AccelPedPrsdOn_pct;
                        /* Referenced by: '<S1435>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KTQD_AdaptCstDsrdTqIMax_N;
                                      /* Referenced by: '<S1409>/Saturation2' */
extern CALDATA const volatile float32 KTQD_AdaptCstDsrdTqIMin_N;
                                      /* Referenced by: '<S1409>/Saturation2' */
extern CALDATA const volatile boolean KTQD_AdaptCstRegenEnbl_flg;
                      /* Referenced by: '<S1405>/KTQD_CstRegenVehSpdOff_kph1' */
extern CALDATA const volatile float32 KTQD_AdaptCstTgtAcceltnFiltTm_s;
                              /* Referenced by: '<S1409>/KDAC_TapDwnTmOut_s2' */
extern CALDATA const volatile float32 KTQD_AdaptCstVehSpdOff_kph;
                       /* Referenced by: '<S1405>/KTQD_CstRegenVehSpdOff_kph' */
extern CALDATA const volatile float32 KTQD_AdaptCstVehSpdOn_kph;
                        /* Referenced by: '<S1405>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KTQD_BrkPedPrsd_pct;
                            /* Referenced by: '<S1404>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile float32 KTQD_BrkPedReldDlyTm_s;
                           /* Referenced by: '<S1405>/KTQD_BrkPedPstnHi_pct2' */
extern CALDATA const volatile boolean KTQD_CrpEnbl_flg;
                       /* Referenced by: '<S1395>/Motohawk_KTQD_EnblEcrp_flg' */
extern CALDATA const volatile float32 KTQD_CrpRsmPedPstn_pct;
                           /* Referenced by: '<S1395>/KTQD_CrpRsmPedPstn_pct' */
extern CALDATA const volatile float32 KTQD_CstRegenTqFiltAchvd_Nm;
                      /* Referenced by: '<S1406>/KTQD_CstRegenVehSpdOff_kph1' */
extern CALDATA const volatile float32 KTQD_CstRegenTqReqWhlDecEnbl_Nmps;
                      /* Referenced by: '<S1406>/KTQD_CstRegenVehSpdOff_kph3' */
extern CALDATA const volatile float32 KTQD_CstRegenTqReqWhlDec_Nmps;
                      /* Referenced by: '<S1406>/KTQD_CstRegenVehSpdOff_kph4' */
extern CALDATA const volatile float32 KTQD_CstRegenTqReqWhlIncEnbl_Nmps;
                      /* Referenced by: '<S1406>/KTQD_CstRegenVehSpdOff_kph2' */
extern CALDATA const volatile float32 KTQD_CstRegenVehSpdOff_kph;
                       /* Referenced by: '<S1404>/KTQD_CstRegenVehSpdOff_kph' */
extern CALDATA const volatile float32 KTQD_CstRegenVehSpdOn_kph;
                        /* Referenced by: '<S1404>/KTQD_CstRegenVehSpdOn_kph' */
extern CALDATA const volatile float32 KTQD_EPBAppliedMaxTq_Nm;
                            /* Referenced by: '<S1434>/KTQD_LimpHomeMaxTq_Nm' */
extern CALDATA const volatile float32 KTQD_EnblDRShftVehSpd_kph;
                        /* Referenced by: '<S1427>/KTQD_EnblDRShftVehSpd_kph' */
extern CALDATA const volatile float32 KTQD_EnblDRShftWhlTq_Nm;
                          /* Referenced by: '<S1427>/KTQD_EnblDRShftWhlTq_Nm' */
extern CALDATA const volatile float32 KTQD_PedTqReqFiltCoeffMAA_c;
                      /* Referenced by: '<S1434>/KCPT_MotorMaxTqFiltCoeff_c2' */
extern CALDATA const volatile float32 KTQD_PlugOnTqZeroSpd_kph;
                         /* Referenced by: '<S1425>/KTQD_TqZeroSpdPlugOn_kph' */
extern CALDATA const volatile float32 KTQD_TqDrtFacLmtPerfmnRate_cps;
                   /* Referenced by: '<S1436>/KTQD_TqDrtFacVehSpdIncRate_cps' */
extern CALDATA const volatile float32 KTQD_TqDrtFacVehSpdDecRate_cps;
                   /* Referenced by: '<S1440>/KTQD_TqDrtFacVehSpdDecRate_cps' */
extern CALDATA const volatile float32 KTQD_TqDrtFacVehSpdIncRate_cps;
                   /* Referenced by: '<S1440>/KTQD_TqDrtFacVehSpdIncRate_cps' */
extern CALDATA const volatile float32 KTQD_WhlSpdDiffFiltCoeff_c;
                       /* Referenced by: '<S1391>/KTQD_WhlSpdDiffFiltCoeff_c' */
extern CALDATA const volatile boolean KTQF_DsblEndFlgRateCond_flg;
                   /* Referenced by: '<S1451>/KTQF_DsblEndFlgRateCondInc_flg' */

/* set to false, change rate is considered when judging ending flag */
extern CALDATA const volatile float32 KTQF_TqDecDlyTm_s;
                               /* Referenced by: '<S1449>/KTQF_TqDecDelay_s ' */

/* torque increase judgement turn on delay */
extern CALDATA const volatile float32 KTQF_TqDecThr_Nm;
                                /* Referenced by: '<S1449>/KTQF_TqDecThr_Nm ' */

/* torque decrease judgement tq threshold */
extern CALDATA const volatile float32 KTQF_TqIncDlyTm_s;
                               /* Referenced by: '<S1449>/KTQF_TqIncDelay_s ' */

/* torque Decrease judgement turn on delay */
extern CALDATA const volatile float32 KTQF_TqIncThr_Nm;
                                /* Referenced by: '<S1449>/KTQF_TqIncThr_Nm ' */

/* torque increase judgement tq threshold */
extern CALDATA const volatile float32 KTQF_TqOutChgRateFilt_rat;
                     /* Referenced by: '<S1451>/KTQF_TqOutChgRateFiltInc_rat' */

/* torque output change rate filter */
extern CALDATA const volatile float32 KTQF_TqRateDecMaxEndg_Nmps;
                       /* Referenced by: '<S1452>/KTQF_TqRateDecMaxEndg_Nmps' */

/* decrease tq rate max in ending or decreasing period */
extern CALDATA const volatile float32 KTQF_TqRateDecMaxRegenACC_Nmps;
                      /* Referenced by: '<S1452>/KTQF_TqRateDecMaxEndg_Nmps1' */
extern CALDATA const volatile float32 KTQF_TqRateDecMaxStart_Nmps;
                      /* Referenced by: '<S1452>/KTQF_TqRateDecMaxEndg_Nmps3' */
extern CALDATA const volatile float32 KTQF_TqRateDecMin_Nmps;/* Referenced by:
                                                              * '<S1451>/KTQF_TqRateDecMin_Nmps'
                                                              * '<S1452>/KTQF_TqRateDecMin_Nmps'
                                                              */

/* Rate limit, max decreasing.  */
extern CALDATA const volatile float32 KTQF_TqRateIncMaxEndg_Nmps;
                       /* Referenced by: '<S1453>/KTQF_TqRateIncMaxEndg_Nmps' */

/* increase tq rate max in ending or decreasing period */
extern CALDATA const volatile float32 KTQF_TqRateIncMin_Nmps;/* Referenced by:
                                                              * '<S1451>/KTQF_TqRateIncMin_Nmps'
                                                              * '<S1453>/KTQF_TqRateIncMin_Nmps'
                                                              */

/* Rate limit, min decreasing.  */
extern CALDATA const volatile float32 KTQF_TqRateLimEndErrFac_c;
                           /* Referenced by: '<S1451>/KTQF_TqRateLimEndTm_s1' */
extern CALDATA const volatile float32 KTQF_TqRateLimEndTm_s;
                            /* Referenced by: '<S1451>/KTQF_TqRateLimEndTm_s' */

/* Rate limit, target torque prediction time towards ending.  */
extern CALDATA const volatile float32 KTQF_TqRawChgRateFilt_rat;
                        /* Referenced by: '<S1451>/KTQF_TqRawChgRateFilt_rat' */

/* raw torque change rate filter */
extern CALDATA const volatile float32 KTQR_ABSActvDlyTm4Dampng_s;
                         /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg4' */
extern CALDATA const volatile float32 KTQR_ASDEnblOscSpd_rpm;
                          /* Referenced by: '<S1480>/KTQR_MotDampngLmtFac_c3' */
extern CALDATA const volatile boolean KTQR_ASDEnbl_flg;
                         /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg6' */
extern CALDATA const volatile float32 KTQR_ASDOscTrigTm_s;
                          /* Referenced by: '<S1480>/KTQR_MotDampngLmtFac_c1' */
extern CALDATA const volatile float32 KTQR_ASDPhCompKa_c;/* Referenced by:
                                                          * '<S1481>/KTQR_MotDampngLmtFac_c13'
                                                          * '<S1481>/KTQR_MotDampngLmtFac_c2'
                                                          * '<S1481>/KTQR_MotDampngLmtFac_c6'
                                                          * '<S1481>/KTQR_MotDampngLmtFac_c9'
                                                          */
extern CALDATA const volatile float32 KTQR_ASDPhCompKb1_c;/* Referenced by:
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c10'
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c11'
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c3'
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c7'
                                                           */
extern CALDATA const volatile float32 KTQR_ASDPhCompKb2_c;/* Referenced by:
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c1'
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c12'
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c5'
                                                           * '<S1481>/KTQR_MotDampngLmtFac_c8'
                                                           */
extern CALDATA const volatile float32 KTQR_ASDSpdFiltHiDecRate_nu;
                          /* Referenced by: '<S1479>/KTQR_MotDampngLmtFac_c2' */
extern CALDATA const volatile float32 KTQR_ASDSpdFiltHiIncRate_nu;
                          /* Referenced by: '<S1479>/KTQR_MotDampngLmtFac_c1' */
extern CALDATA const volatile float32 KTQR_ASDSpdFiltLo_s;
                          /* Referenced by: '<S1479>/KTQR_MotDampngLmtFac_c3' */
extern CALDATA const volatile uint8 KTQR_ASDSpdPhCompCout_Cnt;
                          /* Referenced by: '<S1481>/KTQR_MotDampngLmtFac_c4' */
extern CALDATA const volatile float32 KTQR_ASDTqDbnd_Nm;
                          /* Referenced by: '<S1480>/KTQR_MotDampngLmtFac_c4' */
extern CALDATA const volatile float32 KTQR_ASDTqMax_Nm;
                          /* Referenced by: '<S1480>/KTQR_MotDampngLmtFac_c5' */
extern CALDATA const volatile float32 KTQR_ASDTqMin_Nm;
                          /* Referenced by: '<S1480>/KTQR_MotDampngLmtFac_c6' */
extern CALDATA const volatile boolean KTQR_AllZeroCrsDsblDamp_flg;
                         /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg5' */
extern CALDATA const volatile boolean KTQR_BypassASDOscTrig_flg;
                          /* Referenced by: '<S1480>/KTQR_MotDampngLmtFac_c2' */
extern CALDATA const volatile float32 KTQR_MotDampngBrkout_pct;
                          /* Referenced by: '<S1475>/KTQR_MotDampngLmtFac_c5' */
extern CALDATA const volatile float32 KTQR_MotDampngLmtFac_c;
                           /* Referenced by: '<S1475>/KTQR_MotDampngLmtFac_c' */
extern CALDATA const volatile float32 KTQR_MotDampngLmtMaxRate_Nmps;
                          /* Referenced by: '<S1475>/KTQR_MotDampngLmtFac_c4' */
extern CALDATA const volatile float32 KTQR_MotDampngLmtMin_Nm;
                          /* Referenced by: '<S1475>/KTQR_MotDampngLmtFac_c2' */
extern CALDATA const volatile float32 KTQR_MotDampngSpdOff_rpm;
                          /* Referenced by: '<S1475>/KTQR_MotDampngLmtFac_c3' */
extern CALDATA const volatile float32 KTQR_MotDampngSpdOn_rpm;
                          /* Referenced by: '<S1475>/KTQR_MotDampngLmtFac_c1' */
extern CALDATA const volatile boolean KTQR_MotorDampngDsblAZ_flg;
                         /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg3' */
extern CALDATA const volatile boolean KTQR_MotorDampngDsblBZ_flg;
                         /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg2' */
extern CALDATA const volatile boolean KTQR_MotorDampngDsblZX_flg;
                         /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg1' */
extern CALDATA const volatile boolean KTQR_MotorDampngEnbl_flg;
                          /* Referenced by: '<S1475>/KTQR_EnblMotorStdby_flg' */
extern CALDATA const volatile float32 KTQR_MotorStdbyDlyTm_s;
                               /* Referenced by: '<S1477>/KTQF_TqIncDelay_s ' */
extern CALDATA const volatile boolean KTQR_MotorStdbyEnbl_flg;
                          /* Referenced by: '<S1477>/KTQR_EnblMotorStdby_flg' */
extern CALDATA const volatile float32 KTQR_MotorStdbyVehHaltHi_kph;
                     /* Referenced by: '<S1477>/KTQR_MotorStdbyVehHaltHi_kph' */
extern CALDATA const volatile float32 KTQR_MotorStdbyVehHaltLo_kph;
                     /* Referenced by: '<S1477>/KTQR_MotorStdbyVehHaltLo_kph' */
extern CALDATA const volatile float32 KTQR_MotorTqZeroDlyTm_s;
                              /* Referenced by: '<S1476>/KTQF_TqIncDelay_s 1' */
extern CALDATA const volatile float32 KTQR_MotorTqZero_Nm;
                    /* Referenced by: '<S1476>/KTQR_MotorStdbyVehHaltLo_kph1' */
extern CALDATA const volatile float32 KTZX_AZDMaxTm_s;
                                  /* Referenced by: '<S1506>/KTZX_AZDMaxTm_s' */
extern CALDATA const volatile float32 KTZX_AZIMaxTm_s;
                                  /* Referenced by: '<S1506>/KTZX_AZIMaxTm_s' */
extern CALDATA const volatile float32 KTZX_BrkPedPrsd_pct;
                              /* Referenced by: '<S1506>/KTZX_BrkPedPrsd_pct' */
extern CALDATA const volatile float32 KTZX_ClkZXTmD_s;
                                  /* Referenced by: '<S1506>/KTZX_ClkZXTmD_s' */
extern CALDATA const volatile float32 KTZX_ClkZXTmR_s;
                                  /* Referenced by: '<S1506>/KTZX_ClkZXTmR_s' */
extern CALDATA const volatile float32 KTZX_ClkZXTqD_Nm;
                                 /* Referenced by: '<S1506>/KTZX_ClkZXTqD_Nm' */
extern CALDATA const volatile float32 KTZX_ClkZXTqR_Nm;
                                 /* Referenced by: '<S1506>/KTZX_ClkZXTqR_Nm' */
extern CALDATA const volatile float32 KTZX_MotorTqDecDlyTm_s;
                               /* Referenced by: '<S1516>/KTQF_TqDecDelay_s ' */
extern CALDATA const volatile float32 KTZX_MotorTqDecThr_Nm;
                                /* Referenced by: '<S1516>/KTQF_TqDecThr_Nm ' */
extern CALDATA const volatile float32 KTZX_MotorTqIncDlyTm_s;
                               /* Referenced by: '<S1516>/KTQF_TqIncDelay_s ' */
extern CALDATA const volatile float32 KTZX_MotorTqIncThr_Nm;
                                /* Referenced by: '<S1516>/KTQF_TqIncThr_Nm ' */
extern CALDATA const volatile float32 KTZX_TMSpdBckThr_rpm;
                             /* Referenced by: '<S1506>/KTZX_TMSpdBckThr_rpm' */
extern CALDATA const volatile float32 KTZX_TMSpdFwdThr_rpm;
                             /* Referenced by: '<S1506>/KTZX_TMSpdFwdThr_rpm' */
extern CALDATA const volatile float32 KTZX_TqDsengCfmTm_s;
                              /* Referenced by: '<S1506>/KTZX_TqDsengCfmTm_s' */
extern CALDATA const volatile float32 KTZX_TqDsengThr_Nm;
                               /* Referenced by: '<S1506>/KTZX_TqDsengThr_Nm' */
extern CALDATA const volatile boolean KTZX_UseZeroTqAddRngFinshAZ_flg;/* Referenced by:
                                                                      * '<S1532>/KTZX_UseZeroTqAddRngFinshAZ_flg'
                                                                      * '<S1533>/KTZX_UseZeroTqAddRngFinshAZ_flg'
                                                                      */
extern CALDATA const volatile float32 KTZX_VehStopSpd_kph;
                              /* Referenced by: '<S1506>/KTZX_VehStopSpd_kph' */
extern CALDATA const volatile float32 KTZX_ZXRegenTqTgtThr_Nm;
                            /* Referenced by: '<S1506>/KTZX_ZXRgnTqTgtThr_Nm' */
extern CALDATA const volatile uint16 KVCU_EcuCommReqOff_Cnt;
                         /* Referenced by: '<S1602>/KIPC_LimpHomeOvrdSw_flg4' */

/* _versteckt */
extern CALDATA const volatile uint16 KVCU_EcuCommReqOn_Cnt;
                         /* Referenced by: '<S1602>/KIPC_LimpHomeOvrdSw_flg1' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_EcuCommReq_flg;
                         /* Referenced by: '<S1602>/KIPC_LimpHomeOvrdSw_flg2' */

/* _versteckt */
extern CALDATA const volatile float32 KVCU_MCUTempWrngOff_C;
                         /* Referenced by: '<S1605>/KVTM_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile float32 KVCU_MCUTempWrngOn_C;
                        /* Referenced by: '<S1605>/KVTM_LimpHomeOvrdSw_flg15' */
extern CALDATA const volatile float32 KVCU_MotorTempWrngOff_C;
                         /* Referenced by: '<S1605>/KVTM_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile float32 KVCU_MotorTempWrngOn_C;
                         /* Referenced by: '<S1605>/KVTM_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile uint16 KVCU_RtcWakeupTm_min;
                         /* Referenced by: '<S1602>/KIPC_LimpHomeOvrdSw_flg3' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_XWhlDistErrRefOvrdSw_flg;
                        /* Referenced by: '<S1603>/KIPC_LimpHomeOvrdSw_flg13' */

/* _versteckt */
extern CALDATA const volatile float32 KVCU_XWhlDistErrRefOvrdVal_mpkm;
                         /* Referenced by: '<S1603>/KIPC_LimpHomeOvrdSw_flg5' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_XWhlDistErrRefStatOvrdSw_flg;
                        /* Referenced by: '<S1603>/KIPC_LimpHomeOvrdSw_flg12' */

/* _versteckt */
extern CALDATA const volatile uint8 KVCU_XWhlDistErrRefStatOvrdVal_enum;
                         /* Referenced by: '<S1603>/KIPC_LimpHomeOvrdSw_flg6' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_iTPMSWrngOvrdSw_flg;
                        /* Referenced by: '<S1603>/KIPC_LimpHomeOvrdSw_flg11' */

/* _versteckt */
extern CALDATA const volatile boolean KVCU_iTPMSWrngOvrdVal_flg;
                         /* Referenced by: '<S1603>/KIPC_LimpHomeOvrdSw_flg4' */

/* _versteckt */
extern CALDATA const volatile float32 KVSO_AirBlowArea_m2;/* Referenced by: '<S1208>/A' */
extern CALDATA const volatile float32 KVSO_AirResistCoeff_c;/* Referenced by: '<S1208>/Cd' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr1Fac_c;/* Referenced by: '<S1192>/Cnst3' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr2Fac_c;/* Referenced by: '<S1192>/Cnst1' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr3Fac_c;/* Referenced by: '<S1192>/Cnst2' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr4Fac_c;/* Referenced by: '<S1192>/Cnst4' */
extern CALDATA const volatile float32 KVSO_AvgXWhlDistErr5Fac_c;/* Referenced by: '<S1192>/Cnst5' */
extern CALDATA const volatile float32 KVSO_DistErrHldSlip_kph;/* Referenced by: '<S1196>/Cnst' */
extern CALDATA const volatile float32 KVSO_DistErrHldSpd_kph;/* Referenced by: '<S1196>/Cnst2' */
extern CALDATA const volatile float32 KVSO_DistErrHldStrg_kph;/* Referenced by:
                                                               * '<S1196>/Cnst1'
                                                               * '<S1196>/Cnst3'
                                                               */
extern CALDATA const volatile float32 KVSO_IMUPosnXCmp_m;/* Referenced by:
                                                          * '<S1130>/KVSO_IMUPosnXCmp_m'
                                                          * '<S1131>/KVSO_IMUPosnXCmp_m'
                                                          */
extern CALDATA const volatile float32 KVSO_IMUPosnYCmp_m;/* Referenced by:
                                                          * '<S1130>/KVSO_IMUPosnYCmp_m'
                                                          * '<S1131>/KVSO_IMUPosnYCmp_m'
                                                          */
extern CALDATA const volatile float32 KVSO_LatAccRawFiltTm_s;
                           /* Referenced by: '<S1131>/KVSO_LatAccRawFiltTm_s' */
extern CALDATA const volatile float32 KVSO_LatAccSnsrValOfst_mps2;
                      /* Referenced by: '<S1131>/KVSO_LatAccSnsrValOfst_mps2' */
extern CALDATA const volatile float32 KVSO_LgtAccRawFiltTm_s;
                           /* Referenced by: '<S1130>/KVSO_LgtAccRawFiltTm_s' */
extern CALDATA const volatile float32 KVSO_LgtAccSnsrValOfst_mps2;
                      /* Referenced by: '<S1130>/KVSO_LgtAccSnsrValOfst_mps2' */
extern CALDATA const volatile float32 KVSO_MassEstBrkPrsd_bar;
                          /* Referenced by: '<S1208>/KVSO_MassEstBrkPrsd_bar' */
extern CALDATA const volatile float32 KVSO_MassEstBrkPrsd_pct;
                          /* Referenced by: '<S1208>/KVSO_MassEstBrkPrsd_pct' */
extern CALDATA const volatile float32 KVSO_MassEstFrcLo_N;
                              /* Referenced by: '<S1208>/KVSO_MassEstFrcLo_N' */
extern CALDATA const volatile float32 KVSO_MassEstPkInit_c;/* Referenced by:
                                                            * '<S1208>/KVSO_MassEstPkInit_c'
                                                            * '<S1208>/Unit Delay2'
                                                            */
extern CALDATA const volatile float32 KVSO_MassEstSpdLo_kph;
                            /* Referenced by: '<S1208>/KVSO_MassEstSpdLo_kph' */
extern CALDATA const volatile float32 KVSO_MassEstYawRateHi_degps;
                      /* Referenced by: '<S1208>/KVSO_MassEstYawRateHi_degps' */
extern CALDATA const volatile float32 KVSO_MassLoadTm_s;
                                /* Referenced by: '<S1208>/KVSO_MassLoadTm_s' */
extern CALDATA const volatile float32 KVSO_RSEAxSnsrFiltTm_s;
                           /* Referenced by: '<S1161>/KVSO_RSEAxSnsrFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RSEConfAxSnsrDerFiltTm_s;
                    /* Referenced by: '<S1179>/KVSO_RSEConfAxSnsrDerFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RSEConfBrkPresrDerFiltTm_s;
                  /* Referenced by: '<S1177>/KVSO_RSEConfBrkPresrDerFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RSEConfBrkPresrDerMax_kPaps;
                 /* Referenced by: '<S1177>/KVSO_RSEConfBrkPresrDerMax_kPaps' */
extern CALDATA const volatile float32 KVSO_RSEConfSpdDerFiltTm_s;
                       /* Referenced by: '<S1179>/KVSO_RSEConfSpdDerFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RSEConfStopSpdDer_mps2;
                      /* Referenced by: '<S1179>/KVSO_RSEConfStopSpdDer_mps2' */
extern CALDATA const volatile float32 KVSO_RSEConfStopVehSpdMax_mps;
                    /* Referenced by: '<S1179>/KVSO_RSEConfStopVehSpdMax_mps' */
extern CALDATA const volatile float32 KVSO_RSEConfStrtAxSnsrDer_mps3;
                   /* Referenced by: '<S1179>/KVSO_RSEConfStrtAxSnsrDer_mps3' */
extern CALDATA const volatile float32 KVSO_RSEConfStrtVehSpdMax_mps;
                    /* Referenced by: '<S1179>/KVSO_RSEConfStrtVehSpdMax_mps' */
extern CALDATA const volatile float32 KVSO_RSEConfWhlSlipCfmTm_s;
                       /* Referenced by: '<S1180>/KVSO_RSEConfWhlSlipCfmTm_s' */
extern CALDATA const volatile float32 KVSO_RSEConfWhlSlipSpd_kph;
                       /* Referenced by: '<S1180>/KVSO_RSEConfWhlSlipSpd_kph' */
extern CALDATA const volatile float32 KVSO_RSEConfYawRateDerFiltTm_s;
                   /* Referenced by: '<S1181>/KVSO_RSEConfYawRateDerFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RSEConfYawRateDerMax_degps2;
                 /* Referenced by: '<S1181>/KVSO_RSEConfYawRateDerMax_degps2' */
extern CALDATA const volatile float32 KVSO_RSEConfYawRateMax_degps;
                     /* Referenced by: '<S1181>/KVSO_RSEConfYawRateMax_degps' */
extern CALDATA const volatile float32 KVSO_RSEVehSpdDerFiltTm_s;
                        /* Referenced by: '<S1161>/KVSO_RSEVehSpdDerFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RoadSlopEstEnblDlyTm_s;
                      /* Referenced by: '<S1160>/KVSO_RoadSlopEstEnblDlyTm_s' */
extern CALDATA const volatile float32 KVSO_RoadSlopEstFiltTm_s;
                         /* Referenced by: '<S1160>/KVSO_RoadSlopEstFiltTm_s' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqFiltTm_s;
                                /* Referenced by: '<S1162>/KTQD_CovVehSpd_c4' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqMax_Nm;
                                /* Referenced by: '<S1162>/KTQD_CovVehSpd_c5' */
extern CALDATA const volatile float32 KVSO_RoadSlopTqMin_Nm;
                                /* Referenced by: '<S1162>/KTQD_CovVehSpd_c6' */
extern CALDATA const volatile float32 KVSO_RollgResistCoeff_c;/* Referenced by: '<S1208>/f' */
extern CALDATA const volatile float32 KVSO_TPMSLrnReqCfmTm_s;/* Referenced by: '<S1192>/Cnst7' */
extern CALDATA const volatile float32 KVSO_VehMassFiltTm_s;
                             /* Referenced by: '<S1208>/KVSO_VehMassFiltTm_s' */
extern CALDATA const volatile float32 KVSO_VehResistPosTh_mps;
                              /* Referenced by: '<S1162>/KDAC_TapDwnTmOut_s5' */
extern CALDATA const volatile float32 KVSO_VehSpdFiltTm_s;/* Referenced by: '<S1208>/Const' */
extern CALDATA const volatile float32 KVSO_VehTransEff_c;
                               /* Referenced by: '<S1213>/KVSO_VehTransEff_c' */
extern CALDATA const volatile float32 KVSO_WhlDistErrRecThr_m;
                             /* Referenced by: '<S1205>/KVSO_SpdErrRecDist_m' */
extern CALDATA const volatile float32 KVSO_WhlDistErrRefRecThr_m;
                            /* Referenced by: '<S1205>/KVSO_SpdErrRecDist_m1' */
extern CALDATA const volatile float32 KVSO_WhlLgtFrcFiltTm_s;
                          /* Referenced by: '<S1208>/KVSO_MotorActTqFiltTm_s' */
extern CALDATA const volatile float32 KVSO_WhlMomOfJ_kgm2;/* Referenced by:
                                                           * '<S1215>/KVSO_WhlMomOfJ_kgm2'
                                                           * '<S1216>/KVSO_WhlMomOfJ_kgm2'
                                                           * '<S1217>/KVSO_WhlMomOfJ_kgm2'
                                                           * '<S1218>/KVSO_WhlMomOfJ_kgm2'
                                                           */
extern CALDATA const volatile float32 KVSO_XWhlDistErrExcd_mpkm;/* Referenced by: '<S1192>/Cnst6' */
extern CALDATA const volatile float32 KVSO_YawRateFiltTm_s;
                             /* Referenced by: '<S1132>/KVSO_YawRateFiltTm_s' */
extern CALDATA const volatile float32 KVSO_YawRateRawFiltTm_s;
                          /* Referenced by: '<S1132>/KVSO_YawRateRawFiltTm_s' */
extern CALDATA const volatile float32 KVTM_BrkLampOffRegenTq_Nm;/* Referenced by: '<S1560>/Constant8' */
extern CALDATA const volatile float32 KVTM_BrkLampOnRegenTq_Nm;/* Referenced by: '<S1560>/Constant9' */
extern CALDATA const volatile float32 KVTM_BrkPedReld_pct;
                            /* Referenced by: '<S1553>/KTQD_BrkPedPstnHi_pct' */
extern CALDATA const volatile float32 KVTM_MotorMaxDrvPwr_kW;
                              /* Referenced by: '<S1562>/KSYS_VehTransRto_c2' */
extern CALDATA const volatile float32 KVTM_MotorMaxRegenPwr_kW;
                              /* Referenced by: '<S1562>/KSYS_VehTransRto_c1' */
extern CALDATA const volatile float32 KVTM_MotorPwrTypeRecup_Nm;
                              /* Referenced by: '<S1562>/KSYS_VehTransRto_c4' */
extern CALDATA const volatile float32 KVTM_MotorSpdFiltCoeff_rat;
                       /* Referenced by: '<S1553>/KVTM_MotorSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 KVTM_VehAcceltnFiltCoeff_rat;
                              /* Referenced by: '<S1553>/KDAC_TapDwnTmOut_s1' */
extern CALDATA const volatile float32 KVTM_VehAcceltnMax_mps2;
                                      /* Referenced by: '<S1553>/Saturation1' */
extern CALDATA const volatile float32 KVTM_VehAcceltnMin_mps2;
                                      /* Referenced by: '<S1553>/Saturation1' */
extern CALDATA const volatile float32 KVTM_VehSpdFiltCoeff_rat;
                      /* Referenced by: '<S1553>/KVTM_MotorSpdFiltCoeff_rat1' */
extern CALDATA const volatile float32 MCPT_MotorEffVoltFac_c[9];
                                /* Referenced by: '<S1230>/MTQD_TMOverDrt_c1' */
extern CALDATA const volatile float32 MCPT_MotorSpdFiltCoeff_rat[8];
                      /* Referenced by: '<S1230>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 MCPT_Pwr2MotorTqGen_Nm[616];
                          /* Referenced by: '<S1230>/MCPT_Pwr2MotorTqMot_Nm1' */
extern CALDATA const volatile float32 MCPT_Pwr2MotorTqMot_Nm[588];
                           /* Referenced by: '<S1230>/MCPT_Pwr2MotorTqMot_Nm' */
extern CALDATA const volatile float32 MCPT_TqDrtFacIgbtTemp_c[8];
                                /* Referenced by: '<S1230>/MTQD_TMOverDrt_c2' */
extern CALDATA const volatile float32 MCPT_TqDrtFacMotorTemp_c[8];
                                /* Referenced by: '<S1230>/MTQD_TMOverDrt_c4' */
extern CALDATA const volatile float32 MDAC_ACCDsrdTqKi_c[225];
                      /* Referenced by: '<S1258>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_ACCDsrdTqKp_c[15];
                      /* Referenced by: '<S1258>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_ACCOvrdTqOff_Nm[7];
                            /* Referenced by: '<S1252>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MDAC_ACCOvrdTqOn_Nm[7];
                             /* Referenced by: '<S1252>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MDAC_CCDsrdAcceltnDec_mps3[12];
                /* Referenced by: '<S1274>/Lookup_MTQD_CstRegenTqReqWhlR_Nm1' */
extern CALDATA const volatile float32 MDAC_CCDsrdAcceltnInc_mps3[12];
                 /* Referenced by: '<S1274>/Lookup_MTQD_CstRegenTqReqWhlR_Nm' */
extern CALDATA const volatile float32 MDAC_CCDsrdAcceltn_mps2[126];
                   /* Referenced by: '<S1274>/MTQD_TqRateLimEndErr_Nm_IntTbl' */
extern CALDATA const volatile float32 MDAC_CCDsrdTqKi_c[225];
                      /* Referenced by: '<S1281>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_CCDsrdTqKp_c[15];
                      /* Referenced by: '<S1281>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_CCMaxDrgTqWhl_Nm[14];
                             /* Referenced by: '<S1283>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MDAC_CCSpdStabLowerOfst_kph[8];
                            /* Referenced by: '<S1310>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MDAC_CCSpdStabUpprOfst_kph[8];
                             /* Referenced by: '<S1310>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MDAC_FullPedDrvTqWhl_Nm[23];
                                 /* Referenced by: '<S1247>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MDAC_HDCDsrdTqKi_c[225];
                      /* Referenced by: '<S1347>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_HDCDsrdTqKp_c[15];
                      /* Referenced by: '<S1347>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MDAC_HDCTgtAcceltn_mps2[16];
                                /* Referenced by: '<S1345>/1-D Lookup Table3' */
extern CALDATA const volatile float32 MDAC_INVMaxDrgTqWhl_Nm[12];
                                /* Referenced by: '<S1247>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MDAC_NonDrvnSpdFiltCoeff_rat[7];
                 /* Referenced by: '<S1272>/Lookup_MVTM_VehSpdFiltCoeff_rat1' */
extern CALDATA const volatile float32 MDAG_BMSSOCLoRecThr1_pct[10];
                         /* Referenced by: '<S104>/BMS_BMSCTL_LMPRECSOC1_CAL' */

/* BMSSOC�͹��ϻָ��ż�_���� */
extern CALDATA const volatile float32 MDAG_BMSSOCLoRecThr2_pct[10];
                         /* Referenced by: '<S104>/BMS_BMSCTL_LMPRECSOC2_CAL' */

/* BMSSOC�͹��ϻָ��ż�_���� */
extern CALDATA const volatile float32 MDAG_BMSSOCLoThr1_pct[10];
                            /* Referenced by: '<S104>/BMS_BMSCTL_LMPSOC1_CAL' */

/* BMSSOC�͹��ϴ����ż�_���� */
extern CALDATA const volatile float32 MDAG_BMSSOCLoThr2_pct[10];
                            /* Referenced by: '<S104>/BMS_BMSCTL_LMPSOC2_CAL' */

/* BMSSOC�͹��ϴ����ż�_���� */
extern CALDATA const volatile sint16 MDAG_CellTempLoThr_C[10];
                              /* Referenced by: '<S101>/MDAG_CellTempLoThr_C' */

/* ���ֵ�о�¶ȸߵ͵ķֽ�ֵ */
extern CALDATA const volatile uint16 MDAG_CellUndrVoltThr1_mV[10];
                          /* Referenced by: '<S101>/MDAG_CellUndrVoltThr1_mV' */

/* BMSCellǷѹ���ϵĵ�ѹ�ż�_���� */
extern CALDATA const volatile uint16 MDAG_CellUndrVoltThr2_mV[10];
                          /* Referenced by: '<S101>/MDAG_CellUndrVoltThr2_mV' */

/* BMSCellǷѹ���ϵĵ�ѹ�ż�_���� */
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

/* ��ѹ����Beginֵ������ʹ�ù�ѹ�ջ��� */
extern CALDATA const volatile float32 MEMS_CellOverVoltRng_mV[10];/* Referenced by: '<S26>/PwrDrt4' */

/* ��ѹ����Rangeֵ������ʹ�ù�ѹ�ջ��� */
extern CALDATA const volatile float32 MEMS_CellOverVoltThr_mV[10];/* Referenced by: '<S82>/PwrDrt' */

/* ��ѹ�ջ�����Ŀ���ѹ */
extern CALDATA const volatile float32 MEMS_CellTempLoThr_C[10];/* Referenced by: '<S31>/PwrDrt4' */

/* ��о���º͵�������ֵ */
extern CALDATA const volatile float32 MEMS_CellTempMinFac_rat[5];
                                  /* Referenced by: '<S31>/MTQD_TMOverDrt_c5' */

/* ��о�¶��л�����ϵ�� */
extern CALDATA const volatile float32 MEMS_CellUndrVoltBgn1_mV[10];/* Referenced by: '<S28>/PwrDrt' */

/* ���·ŵ�Ƿѹ����Beginֵ������ʹ�õ�ѹ�ջ��� */
extern CALDATA const volatile float32 MEMS_CellUndrVoltBgn2_mV[10];/* Referenced by: '<S28>/PwrDrt1' */

/* ���·ŵ�Ƿѹ����Beginֵ(����ʹ�õ�ѹ�ջ�) */
extern CALDATA const volatile float32 MEMS_CellUndrVoltRng1_mV[10];/* Referenced by: '<S28>/PwrDrt2' */

/* ���·ŵ�Ƿѹ����Rangֵ������ʹ�õ�ѹ�ջ��� */
extern CALDATA const volatile float32 MEMS_CellUndrVoltRng2_mV[10];/* Referenced by: '<S28>/PwrDrt3' */

/* ���·ŵ�Ƿѹ����Rangֵ(����ʹ�õ�ѹ�ջ�) */
extern CALDATA const volatile float32 MEMS_CellUndrVoltThr1_mV[10];/* Referenced by: '<S83>/PwrDrt' */

/* ���µ�ѹ�ջ�����Ŀ���ѹ */
extern CALDATA const volatile float32 MEMS_CellUndrVoltThr2_mV[10];/* Referenced by: '<S83>/PwrDrt1' */

/* ���µ�ѹ�ջ�����Ŀ���ѹ */
extern CALDATA const volatile float32 MEMS_ChrgCurFbKi_c[15];
                                  /* Referenced by: '<S82>/lu1d_BatLimHiSoC1' */

/* ��ѹ�ջ�����Ki */
extern CALDATA const volatile float32 MEMS_ChrgCurFbKp_c[11];
                                   /* Referenced by: '<S82>/lu1d_BatLimHiSoC' */

/* ��ѹ�ջ�����KP */
extern CALDATA const volatile float32 MEMS_ChrgPwrFbKi_c[15];
                                  /* Referenced by: '<S46>/lu1d_BatLimHiSoC1' */

/* ��繦�ʱջ�KI */
extern CALDATA const volatile float32 MEMS_ChrgPwrFbKp_c[11];
                                   /* Referenced by: '<S46>/lu1d_BatLimHiSoC' */

/* ��繦�ʱջ�KP */
extern CALDATA const volatile float32 MEMS_DchaCurFbKi_c[15];
                                  /* Referenced by: '<S83>/lu1d_BatLimHiSoC1' */

/* Ƿѹ��ѹ�ջ�KI */
extern CALDATA const volatile float32 MEMS_DchaCurFbKp_c[11];
                                   /* Referenced by: '<S83>/lu1d_BatLimHiSoC' */

/* Ƿѹ��ѹ�ջ�KP */
extern CALDATA const volatile float32 MEMS_DchaPwrFbKi_c[15];
                                  /* Referenced by: '<S64>/lu1d_BatLimHiSoC1' */

/* �ŵ繦�ʱջ�KI */
extern CALDATA const volatile float32 MEMS_DchaPwrFbKp_c[11];
                                   /* Referenced by: '<S64>/lu1d_BatLimHiSoC' */

/* �ŵ繦�ʱջ�KP */
extern CALDATA const volatile float32 MEMS_HVBatMaxChrgPwrSOC_kW[7];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c8' */

/* ���SOC�������ƣ�Ŀǰ��δʹ�ã� */
extern CALDATA const volatile float32 MEMS_HVBatMaxDchaPwrSOC_kW[7];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c6' */

/* �ŵ�SOC���ƹ���(Ŀǰ��δʹ��) */
extern CALDATA const volatile float32 MEMS_MaxConChrgCurOfst_A[8];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c1' */

/* Con�������յ���ƫ�� */
extern CALDATA const volatile float32 MEMS_MaxConDchaCurOfst_A[8];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c1' */

/* �ŵ�-��������ƫ�� */
extern CALDATA const volatile float32 MEMS_MaxInsChrgCurOfst_A[8];
                                  /* Referenced by: '<S26>/MTQD_TMOverDrt_c7' */

/* Ins˲ʱ���յ���ƫ�� */
extern CALDATA const volatile float32 MEMS_MaxInsChrgCurrFac_c[100];
                  /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurrFac_c' */

/* VCU������ͬPack���ͻ���ϵ�� */
extern CALDATA const volatile float32 MEMS_MaxInsChrgCurr_A[170];
                     /* Referenced by: '<S26>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

/* VCU����Ins˲ʱ���յ��� */
extern CALDATA const volatile float32 MEMS_MaxInsDchaCurOfst_A[8];
                                  /* Referenced by: '<S28>/MTQD_TMOverDrt_c2' */

/* �ŵ�-˲ʱ����ƫ�� */
extern CALDATA const volatile float32 MEMS_MaxInsDchaCurrFac_c[100];
                  /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurrFac_c' */

/* VCU������ͬ����Pack�ŵ�ϵ�� */
extern CALDATA const volatile float32 MEMS_MaxInsDchaCurr_A[170];
                     /* Referenced by: '<S28>/Lookup2D_MEMS_MaxInsDchaCurr_A' */

/* VCU����Ins˲ʱ�ŵ���� */
extern CALDATA const volatile float32 MHVM_BMSCelMaxVol_mV[10];
                              /* Referenced by: '<S764>/MHVM_BMSCelMaxVol_mV' */

/* ��ֱ������ֹ�����ѹ */
extern CALDATA const volatile float32 MHVM_BMSTotMaxVol_V[10];
                               /* Referenced by: '<S764>/MHVM_BMSTotMaxVol_V' */

/* ��ֱ������ֹ�ܵ�ѹ */
extern CALDATA const volatile float32 MHVM_MaxChrgCurntDC_A[10];
                             /* Referenced by: '<S764>/MHVM_MaxChrgCurntDC_A' */

/* DCֱ����������� */
extern CALDATA const volatile float32 MHVM_MaxChrgVoltDC_V[10];
                              /* Referenced by: '<S764>/MHVM_MaxChrgVoltDC_V' */

/* DCֱ���������ѹ */
extern CALDATA const volatile float32 MIBS_BMSBatSOCExtrmLo_pct[10];
                        /* Referenced by: '<S1031>/MIBS_BMSBatSOCExtrmLo_pct' */

/* �������SOC���ͣ���ֹ���˳�IBS����_versteckt */
extern CALDATA const volatile float32 MIBS_IBSEnMinSOC_pct[10];
                             /* Referenced by: '<S1031>/MIBS_IBSEnMinSOC_pct' */

/* IBS���綯�����SOC��ֵ_versteckt */
extern CALDATA const volatile uint16 MIBS_NextRtcWupThr_min[60];
                           /* Referenced by: '<S1032>/MIBS_NextRtcWupThr_min' */

/* IBS��һ��RTC����ʱ����ֵ_versteckt */
extern CALDATA const volatile uint16 MIBS_WupChgTmThr2_min[60];
                             /* Referenced by: '<S1032>/MIBS_WupChgTmThr_min' */

/* IBS����ʱ����ֵ2_versteckt */
extern CALDATA const volatile float32 MIPC_AccPedBckLsh_pct[12];
                                      /* Referenced by: '<S905>/Lookup Table' */
extern CALDATA const volatile float32 MIPC_TireRadius_m[6];
                                     /* Referenced by: '<S903>/TireSizeTable' */
extern CALDATA const volatile float32 MRME_CHTCStdRmnMil_km[120];
                             /* Referenced by: '<S980>/MRME_CHTCStdRmnMil_km' */

/* ��׼����CHTC���ֵ */
extern CALDATA const volatile float32 MRME_DchaRmnMilEstChgStp_c[60];
                           /* Referenced by: '<S1008>/MRME_DynEstRmnChgStp_c' */

/* ��̬�����仯��������ϵ����Ĭ����1kmΪ��׼�� */
extern CALDATA const volatile float32 MRME_WLTPStdDwLimFac_c[6];
                               /* Referenced by: '<S989>/MRME_WLTPDwLimFac_c' */

/* ���ڱ�׼����WLTP��С����ϵ��(ʹ�õ�о�¶�����) */
extern CALDATA const volatile float32 MRME_WLTPStdPwrCnsm_kWh100km[10];/* Referenced by: '<S984>/  ' */

/* ��׼����100km��ģ�����100km���㣩 */
extern CALDATA const volatile float32 MRME_WLTPStdRmnMil_km[120];
                             /* Referenced by: '<S989>/MRME_WLTPStdRmnMil_km' */

/* ��׼����WLTP���ֵ */
extern CALDATA const volatile float32 MRME_WLTPStdSOCCnsm_pct100km[10];
                     /* Referenced by: '<S989>/MRME_WLTPStdSOCCnsm_pct100km ' */

/* ��׼����SOC���ģ���100km���㣩 */
extern CALDATA const volatile float32 MTQC_RegenMaxTqDecRate_Nmps[20];
                   /* Referenced by: '<S1374>/MTQD_TqRateLimEndErr_Nm_IntTbl' */
extern CALDATA const volatile float32 MTQC_RegenMaxTqIncRate_Nmps[8];
                             /* Referenced by: '<S1374>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlEndPstn_mps2[14];
                            /* Referenced by: '<S1409>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlS_mps2[14];
                             /* Referenced by: '<S1409>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_AdaptCstAcceltnReqWhlW_mps2[14];
                            /* Referenced by: '<S1409>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MTQD_AdaptCstDsrdTqKi_c[225];
                      /* Referenced by: '<S1409>/MDAC_CCSDsrdTqKi_fac_IntTbl' */
extern CALDATA const volatile float32 MTQD_AdaptCstDsrdTqKp_c[15];
                      /* Referenced by: '<S1409>/MDAC_CCSDsrdTqKp_fac_IntTbl' */
extern CALDATA const volatile float32 MTQD_AdaptCstMaxTqWhl_Nm[14];
                            /* Referenced by: '<S1405>/MTQD_CstTqReqWhlS_Nm4' */
extern CALDATA const volatile float32 MTQD_AdaptCstMinTqWhl_Nm[14];
                            /* Referenced by: '<S1405>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQD_CrpTqReqWhlD_Nm[10];
                      /* Referenced by: '<S1395>/Lookup_MTQD_CrpTqReqWhlD_Nm' */
extern CALDATA const volatile float32 MTQD_CrpTqReqWhlR_Nm[10];
                      /* Referenced by: '<S1395>/Lookup_MTQD_CrpTqReqWhlR_Nm' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnA_pct[15];
                            /* Referenced by: '<S1404>/MTQD_CstTqReqWhlA_Nm1' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnS_pct[15];
                            /* Referenced by: '<S1404>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnV_pct[14];
                                /* Referenced by: '<S1404>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTQD_CstRegenEndPstnW_pct[15];
                            /* Referenced by: '<S1404>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlInc_Nmps[8];
                            /* Referenced by: '<S1406>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlOff_Nm[70];
                          /* Referenced by: '<S1403>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlR_Nm[12];
                                /* Referenced by: '<S1403>/1-D Lookup Table2' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlS_Nm[14];
                             /* Referenced by: '<S1403>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlV_Nm[14];
                                /* Referenced by: '<S1403>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTQD_CstRegenTqReqWhlW_Nm[14];
                            /* Referenced by: '<S1403>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MTQD_FwdFullPedDrvTqWhlSprt_Nm[19];
                                /* Referenced by: '<S1396>/MTQD_PTBaseTq_Nm1' */
extern CALDATA const volatile float32 MTQD_FwdFullPedDrvTqWhl_Nm[19];
                                 /* Referenced by: '<S1396>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MTQD_FwdPedMapEco_pct[378];
                         /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct1' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpEco_pct[42];
                                /* Referenced by: '<S1396>/2-D Lookup Table1' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpNorm_pct[42];
                                /* Referenced by: '<S1396>/2-D Lookup Table3' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpSnow_pct[42];
                                 /* Referenced by: '<S1396>/2-D Lookup Table' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNoCrpSpt_pct[42];
                                /* Referenced by: '<S1396>/2-D Lookup Table2' */
extern CALDATA const volatile float32 MTQD_FwdPedMapNorm_pct[378];
                         /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct3' */
extern CALDATA const volatile float32 MTQD_FwdPedMapSnow_pct[378];
                          /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 MTQD_FwdPedMapSpt_pct[378];
                         /* Referenced by: '<S1396>/MTQD_PedMapBasTqEco_pct2' */
extern CALDATA const volatile float32 MTQD_LimpHomeMaxTq_Nm[8];
                            /* Referenced by: '<S1391>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQD_RevFullPedDrvTqWhl_Nm[19];
                                 /* Referenced by: '<S1398>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MTQD_RevPedMap_pct[231];
                          /* Referenced by: '<S1398>/MTQD_PedMapBasTqEco_pct' */
extern CALDATA const volatile float32 MTQD_TqDrtFacBrkPedAccOff_c[9];
                      /* Referenced by: '<S1435>/MTQD_BrkPdlTqDerateAccOff_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacBrkPedAccOn_c[45];
                       /* Referenced by: '<S1435>/MTQD_BrkPdlTqDerateAccOn_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacHiddenLmtPwr_c[7];
               /* Referenced by: '<S1438>/Lookup_MTQD_TqDrtFacHiddenLmtPwr_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacLimpHome_c[7];
                /* Referenced by: '<S1437>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacLmtPerfmn_c[8];
                /* Referenced by: '<S1436>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacMotorSpd_c[5];
                                 /* Referenced by: '<S1433>/MTQD_TMOverDrt_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl1_c[7];
                /* Referenced by: '<S1439>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl2_c[7];
                /* Referenced by: '<S1439>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 MTQD_TqDrtFacTboxLmtLvl3_c[7];
                /* Referenced by: '<S1439>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdEco_c[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c1' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdNorm_c[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c3' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdRev_c[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c4' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdSnow_c[6];
                 /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c' */
extern CALDATA const volatile float32 MTQD_TqDrtFacVehSpdSpt_c[6];
                /* Referenced by: '<S1440>/Lookup_MTQD_TqDrtFacVehSpdSnow_c2' */
extern CALDATA const volatile float32 MTQD_WhlSpdDiffMaxTqFac_c[10];
                             /* Referenced by: '<S1391>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQD_WhlSpdDiffMaxTq_Nm[10];
                            /* Referenced by: '<S1391>/MTQD_CstTqReqWhlS_Nm1' */
extern CALDATA const volatile float32 MTQF_DecEndRateFiltTmSMode_s[12];
                             /* Referenced by: '<S1452>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQF_DecEndRateFiltTm_s[12];
                            /* Referenced by: '<S1452>/MTQD_CstTqReqWhlS_Nm1' */

/* torque decrease rate filter time in ending phase */
extern CALDATA const volatile float32 MTQF_DecStartRateFiltTmACC_s[12];
                            /* Referenced by: '<S1452>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQF_DecStartRateFiltTmSMode_s[12];
                            /* Referenced by: '<S1452>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQF_DecStartRateFiltTm_s[12];
                            /* Referenced by: '<S1452>/MTQD_CstTqReqWhlS_Nm4' */

/* torque decrease rate filter time in starting phase */
extern CALDATA const volatile float32 MTQF_IncEndRateFiltTmSMode_s[12];
                             /* Referenced by: '<S1453>/MTQD_CstTqReqWhlS_Nm' */
extern CALDATA const volatile float32 MTQF_IncEndRateFiltTm_s[12];
                            /* Referenced by: '<S1453>/MTQD_CstTqReqWhlS_Nm1' */

/* torque increase rate filter time in ending phase */
extern CALDATA const volatile float32 MTQF_IncStartRateFiltTmACC_s[12];
                            /* Referenced by: '<S1453>/MTQD_CstTqReqWhlS_Nm2' */
extern CALDATA const volatile float32 MTQF_IncStartRateFiltTmSMode_s[12];
                            /* Referenced by: '<S1453>/MTQD_CstTqReqWhlS_Nm3' */
extern CALDATA const volatile float32 MTQF_IncStartRateFiltTm_s[12];
                            /* Referenced by: '<S1453>/MTQD_CstTqReqWhlS_Nm4' */

/* torque increase rate filter time in starting phase */
extern CALDATA const volatile float32 MTQF_TipOutTqDecRateCoeff_rat[8];
                                /* Referenced by: '<S1452>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxACC_Nmps[8];
                                    /* Referenced by: '<S1452>/Lookup Table5' */

/* Max torque decreasing change rate in ACC */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxE_Nmps[156];
                   /* Referenced by: '<S1452>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* Max torque decreasing change rate in Eco */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxN_Nmps[156];
                  /* Referenced by: '<S1452>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* Max torque decreasing change rate in Normal */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxRegenE_Nmps[91];
                  /* Referenced by: '<S1452>/MTQD_TqRateLimEndErr_Nm_IntTbl3' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxRegenN_Nmps[91];
                  /* Referenced by: '<S1452>/MTQD_TqRateLimEndErr_Nm_IntTbl5' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxRegenS_Nmps[91];
                  /* Referenced by: '<S1452>/MTQD_TqRateLimEndErr_Nm_IntTbl4' */
extern CALDATA const volatile float32 MTQF_TqRateDecMaxS_Nmps[156];
                  /* Referenced by: '<S1452>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* Max torque decreasing change rate in Sport */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxACC_Nmps[8];
                                    /* Referenced by: '<S1453>/Lookup Table5' */

/* Max torque increasing change rate in ACC */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxE_Nmps[156];
                   /* Referenced by: '<S1453>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* Max torque increasing change rate in Eco */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxN_Nmps[156];
                  /* Referenced by: '<S1453>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* Max torque increasing change rate in Normal */
extern CALDATA const volatile float32 MTQF_TqRateIncMaxS_Nmps[156];
                  /* Referenced by: '<S1453>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* Max torque increasing change rate in Sport */
extern CALDATA const volatile float32 MTQF_TqRateLimEndErrE_Nm[154];
                   /* Referenced by: '<S1451>/MTQD_TqRateLimEndErr_Nm_IntTbl' */

/* torque ending error in E */
extern CALDATA const volatile float32 MTQF_TqRateLimEndErrN_Nm[154];
                  /* Referenced by: '<S1451>/MTQD_TqRateLimEndErr_Nm_IntTbl2' */

/* torque ending error in N */
extern CALDATA const volatile float32 MTQF_TqRateLimEndErrS_Nm[154];
                  /* Referenced by: '<S1451>/MTQD_TqRateLimEndErr_Nm_IntTbl1' */

/* torque ending error in S */
extern CALDATA const volatile float32 MTQR_ASDSpdFiltHi_s[8];
                                 /* Referenced by: '<S1479>/1-D Lookup Table' */
extern CALDATA const volatile float32 MTQR_ASDTqGain_c[8];
                                 /* Referenced by: '<S1480>/1-D Lookup Table' */
extern CALDATA const volatile float32 MTZX_AZDecRate_Nmps[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table4' */
extern CALDATA const volatile float32 MTZX_AZIncRate_Nmps[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table3' */
extern CALDATA const volatile float32 MTZX_AZRngDec_Nm[12];
                         /* Referenced by: '<S1511>/MTZX_AZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_AZRngInc_Nm[12];
                          /* Referenced by: '<S1511>/MTZX_AZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_BZDecRate_Nmps[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table2' */
extern CALDATA const volatile float32 MTZX_BZIncRate_Nmps[11];
                                /* Referenced by: '<S1511>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTZX_BZRngDec_Nm[12];
                         /* Referenced by: '<S1511>/MTZX_BZRngTipOutTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_BZRngInc_Nm[12];
                          /* Referenced by: '<S1511>/MTZX_BZRngTipInTMOly_Nm' */
extern CALDATA const volatile float32 MTZX_RampDecRate_Nmps[10];
                                /* Referenced by: '<S1510>/1-D Lookup Table1' */
extern CALDATA const volatile float32 MTZX_RampIncRate_Nmps[10];
                                /* Referenced by: '<S1510>/1-D Lookup Table2' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstDecACC_Nm[12];
                   /* Referenced by: '<S1511>/MTZX_ZeroTqOfstTipOutTMOly_Nm5' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstDec_Nm[80];
                                /* Referenced by: '<S1511>/2-D Lookup Table1' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstIncACC_Nm[12];
                    /* Referenced by: '<S1511>/MTZX_ZeroTqOfstTipInTMOly_Nm1' */
extern CALDATA const volatile float32 MTZX_ZeroTqOfstInc_Nm[80];
                                 /* Referenced by: '<S1511>/2-D Lookup Table' */
extern CALDATA const volatile float32 MTZX_ZeroXTmACC_s[10];
                        /* Referenced by: '<S1511>/MTZX_ZeroXTmTipInTMOly_s1' */
extern CALDATA const volatile float32 MTZX_ZeroXTmDec_s[80];
                                /* Referenced by: '<S1511>/2-D Lookup Table2' */
extern CALDATA const volatile float32 MTZX_ZeroXTmInc_s[80];
                                /* Referenced by: '<S1511>/2-D Lookup Table3' */
extern CALDATA const volatile float32 MVTM_ActPwrBacklash_kW[8];/* Referenced by: '<S1567>/Dbnd' */
extern CALDATA const volatile float32 MVTM_MotorMaxDrvTqWT_Nm[23];
                                 /* Referenced by: '<S1562>/MTQD_PTBaseTq_Nm' */
extern CALDATA const volatile float32 MVTM_MotorSpdFiltCoeff_rat[8];
                      /* Referenced by: '<S1553>/MPPC_OutSftSpdFiltCoeff_rat' */
extern CALDATA const volatile float32 MVTM_VehSpdFiltCoeff_rat[8];
                  /* Referenced by: '<S1553>/Lookup_MVTM_VehSpdFiltCoeff_rat' */

#endif                                 /* RTW_HEADER_calPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
