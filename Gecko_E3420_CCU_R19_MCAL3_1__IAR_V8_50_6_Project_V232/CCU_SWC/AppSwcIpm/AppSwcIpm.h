/*
 * File: AppSwcIpm.h
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.172
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 16 10:34:34 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AppSwcIpm_h_
#define RTW_HEADER_AppSwcIpm_h_
#ifndef AppSwcIpm_COMMON_INCLUDES_
#define AppSwcIpm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_AppSwcIpm.h"
#endif                                 /* AppSwcIpm_COMMON_INCLUDES_ */

#include "Rte_Type.h"
//#include "AppSwcIpm_types.h"

/* Includes for objects with custom storage classes */
#include "calPrmsIpm.h"
#include "monPrmsIpm.h"

/* user code (top of header file) */
#include"ME11_ABI.h"
#include"DIAG_ABI.h"

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  DT_IPM_COMP_AC_BOD IPM_COMP_AC_BOD;  /* '<S21>/BusCreator' */
  DT_IPM_ESC_A_CHA IPM_ESC_A_CHA;      /* '<S157>/BusCreator' */
  DT_IPM_HU_B_BAC IPM_HU_B_BAC;        /* '<S71>/BusCreator' */
  DT_IPM_BMS_4_AC_ChargeState_EPT IPM_BMS_4_AC_ChargeState_EPT;/* '<S270>/BusCreator' */
  DT_IPM_FCM_B_CHA IPM_FCM_B_CHA;      /* '<S236>/BusCreator' */
  DT_IPM_CCP_PanelStatus_BOD IPM_CCP_PanelStatus_BOD_c;/* '<S316>/BusCreator' */
  DT_IPM_IPU_OBC_1_State_EPT IPM_IPU_OBC_1_State_EPT;/* '<S105>/BusCreator' */
  DT_IPM_BMS_2_BatState_EPT IPM_BMS_2_BatState_EPT;/* '<S268>/BusCreator' */
  DT_IPM_BMS_6_DischrgRecup_EPT IPM_BMS_6_DischrgRecup_EPT;/* '<S271>/BusCreator' */
  DT_IPM_HVCH_Status1_BOD IPM_HVCH_Status1_BOD;/* '<S22>/BusCreator' */
  DT_IPM_HVCH_Status2_BOD IPM_HVCH_Status2_BOD;/* '<S23>/BusCreator' */
  DT_IPM_INV_2_Value_EPT IPM_INV_2_Value_EPT;/* '<S201>/BusCreator' */
  DT_IPM_IPU_OBC_2_Inlet_EPT IPM_IPU_OBC_2_Inlet_EPT;/* '<S140>/BusCreator' */
  DT_IPM_BMS_1_MainState_EPT BusCreator;/* '<S267>/BusCreator' */
  DT_IPM_BMS_5_BatTemp_EPT IPM_BMS_5_BatTemp_EPT;/* '<S101>/BusCreator' */
  DT_IPM_EHB_B_CHA IPM_EHB_B_CHA;      /* '<S154>/BusCreator' */
  DT_IPM_EPS_2_StrWhlAng_CHA IPM_EPS_2_StrWhlAng_CHA;/* '<S155>/BusCreator' */
  DT_IPM_ESC_7_FuncStatus_CHA ESC_7_FuncStatus_CHA_b;/* '<S156>/BusCreator' */
  DT_IPM_INV_1_Value_EPT IPM_INV_1_Value_EPT;/* '<S200>/BusCreator' */
  DT_IPM_IPU_DCC_1_State_EPT IPM_IPU_DCC_1_State_EPT;/* '<S103>/BusCreator' */
  DT_IPM_SCS_LeSwitchSts_BOD IPM_SCS_LeSwitchSts_BOD;/* '<S318>/BusCreator' */
  DT_MsgActv MsgActv_outputs;          /* '<S6>/BusCreator' */
  DT_IPM_ACCM_Version_BOD IPM_ACCM_Version_BOD;/* '<S14>/BusCreator' */
  DT_IPM_BMS_7_CellVolt_EPT IPM_BMS_7_CellVolt_EPT;/* '<S272>/BusCreator' */
  DT_IPM_CRRR_A_CHA IPM_CRRR_A_CHA;    /* '<S234>/BusCreator' */
  DT_IPM_EHB_A_CHA IPM_EHB_A_CHA;      /* '<S235>/BusCreator' */
  DT_IPM_ESCL_ESCLStatus_BOD IPM_ESCL_ESCLStatus_BOD;/* '<S317>/BusCreator' */
  DT_IPM_INV_3_Value_EPT IPM_INV_3_Value_EPT;/* '<S202>/BusCreator' */
  DT_IPM_INV_IMMO_Req_EPT IPM_INV_IMMO_Req_EPT_l;/* '<S102>/BusCreator' */
  DT_IPM_IPU_DCC_2_ChrgInValue_EPT IPM_IPU_DCC_2_ChrgInValue_EPT;/* '<S104>/BusCreator' */
  DT_IPM_SCS_RiSwitchSts_BOD IPM_SCS_RiSwitchSts_BOD;/* '<S228>/BusCreator1' */
  DT_IPM_TBOX_BJS_Time_BAC IPM_TBOX_BJS_Time_BAC;/* '<S63>/BusCreator' */
  DT_IPM_BMS_10_DC_ChargeStates_EPT IPM_BMS_10_DC_ChargeStates_EPT;/* '<S266>/BusCreator' */
  DT_IPM_BMS_3_DC_ChargeState_EPT IPM_BMS_3_DC_ChargeState_EPT;/* '<S269>/BusCreator' */
  DT_IPM_BMS_9_BattInfo_EPT IPM_BMS_9_BattInfo_EPT;/* '<S149>/BusCreator' */
  DT_IPM_INV_4_Value_EPT IPM_INV_4_Value_EPT;/* '<S203>/BusCreator' */
  DT_IPM_SRS_1_Status_CHA IPM_SRS_1_Status_CHA;/* '<S349>/BusCreator' */
  uint64 UnitDelay_DSTATE;             /* '<S339>/Unit Delay' */
  uint8 UnitDelay_DSTATE_f;            /* '<S350>/Unit Delay' */
  uint8 UnitDelay_DSTATE_n;            /* '<S340>/Unit Delay' */
  uint8 UnitDelay_DSTATE_d;            /* '<S282>/Unit Delay' */
  uint8 UnitDelay_DSTATE_j;            /* '<S281>/Unit Delay' */
  uint8 UnitDelay_DSTATE_b;            /* '<S279>/Unit Delay' */
  uint8 UnitDelay_DSTATE_o;            /* '<S277>/Unit Delay' */
  uint8 UnitDelay_DSTATE_g;            /* '<S276>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m;            /* '<S261>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ni;           /* '<S260>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mc;           /* '<S242>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h;            /* '<S241>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hg;           /* '<S240>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ms;           /* '<S239>/Unit Delay' */
  uint8 UnitDelay_DSTATE_k;            /* '<S238>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ow;           /* '<S237>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ga;           /* '<S224>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nu;           /* '<S210>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gn;           /* '<S208>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jq;           /* '<S206>/Unit Delay' */
  uint8 UnitDelay_DSTATE_a;            /* '<S185>/Unit Delay' */
  uint8 UnitDelay_DSTATE_o5;           /* '<S184>/Unit Delay' */
  uint8 UnitDelay_DSTATE_i;            /* '<S183>/Unit Delay' */
  uint8 UnitDelay_DSTATE_p;            /* '<S182>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ji;           /* '<S181>/Unit Delay' */
  uint8 UnitDelay_DSTATE_bt;           /* '<S175>/Unit Delay' */
  uint8 UnitDelay_DSTATE_me;           /* '<S163>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jh;           /* '<S151>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ol;           /* '<S150>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mu;           /* '<S137>/Unit Delay' */
  uint8 UnitDelay_DSTATE_og;           /* '<S123>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nf;           /* '<S119>/Unit Delay' */
  uint8 UnitDelay_DSTATE_i5;           /* '<S118>/Unit Delay' */
  uint8 UnitDelay_DSTATE_l;            /* '<S117>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pc;           /* '<S116>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hl;           /* '<S115>/Unit Delay' */
  uint8 UnitDelay_DSTATE_e;            /* '<S114>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ec;           /* '<S113>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ju;           /* '<S112>/Unit Delay' */
  uint8 UnitDelay_DSTATE_by;           /* '<S100>/Unit Delay' */
  uint8 UnitDelay_DSTATE_e3;           /* '<S99>/Unit Delay' */
  uint8 UnitDelay_DSTATE_dn;           /* '<S97>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ay;           /* '<S96>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hx;           /* '<S95>/Unit Delay' */
  uint8 UnitDelay_DSTATE_dw;           /* '<S92>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nh;           /* '<S91>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nn;           /* '<S90>/Unit Delay' */
  uint8 UnitDelay_DSTATE_la;           /* '<S89>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pp;           /* '<S88>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mt;           /* '<S87>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hm;           /* '<S86>/Unit Delay' */
  uint8 UnitDelay_DSTATE_om;           /* '<S85>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lw;           /* '<S84>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m4;           /* '<S83>/Unit Delay' */
  uint8 UnitDelay_DSTATE_b0;           /* '<S82>/Unit Delay' */
  uint8 UnitDelay_DSTATE_f4;           /* '<S81>/Unit Delay' */
  uint8 UnitDelay_DSTATE_g2;           /* '<S80>/Unit Delay' */
  uint8 UnitDelay_DSTATE_g1;           /* '<S77>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h5;           /* '<S76>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mz;           /* '<S75>/Unit Delay' */
  uint8 UnitDelay_DSTATE_bz;           /* '<S74>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c;            /* '<S73>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ll;           /* '<S72>/Unit Delay' */
  uint8 UnitDelay_DSTATE_no;           /* '<S68>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ah;           /* '<S67>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jg;           /* '<S66>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ke;           /* '<S65>/Unit Delay' */
  uint8 UnitDelay_DSTATE_iy;           /* '<S64>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c4;           /* '<S59>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h2;           /* '<S51>/Unit Delay' */
  uint8 UnitDelay_DSTATE_iv;           /* '<S38>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pr;           /* '<S36>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ck;           /* '<S34>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pcn;          /* '<S30>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lo;           /* '<S28>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ha;           /* '<S20>/Unit Delay' */
  uint8 UnitDelay_DSTATE_py;           /* '<S19>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hz;           /* '<S18>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ev;           /* '<S17>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ge;           /* '<S16>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ce;           /* '<S15>/Unit Delay' */
  boolean UnitDelay_DSTATE_fl;         /* '<S351>/Unit Delay' */
  boolean UnitDelay_DSTATE_ds;         /* '<S348>/Unit Delay' */
  boolean UnitDelay_DSTATE_ko;         /* '<S347>/Unit Delay' */
  boolean UnitDelay_DSTATE_cd;         /* '<S346>/Unit Delay' */
  boolean UnitDelay_DSTATE_oa;         /* '<S345>/Unit Delay' */
  boolean UnitDelay_DSTATE_du;         /* '<S344>/Unit Delay' */
  boolean UnitDelay_DSTATE_bc;         /* '<S343>/Unit Delay' */
  boolean UnitDelay_DSTATE_dc;         /* '<S342>/Unit Delay' */
  boolean UnitDelay_DSTATE_f1;         /* '<S341>/Unit Delay' */
  boolean UnitDelay_DSTATE_i5p;        /* '<S338>/Unit Delay' */
  boolean UnitDelay_DSTATE_nz;         /* '<S337>/Unit Delay' */
  boolean UnitDelay_DSTATE_e1;         /* '<S336>/Unit Delay' */
  boolean UnitDelay_DSTATE_dp;         /* '<S335>/Unit Delay' */
  boolean UnitDelay_DSTATE_b1;         /* '<S334>/Unit Delay' */
  boolean UnitDelay_DSTATE_p1;         /* '<S333>/Unit Delay' */
  boolean UnitDelay_DSTATE_it;         /* '<S332>/Unit Delay' */
  boolean UnitDelay_DSTATE_kd;         /* '<S331>/Unit Delay' */
  boolean UnitDelay_DSTATE_ab;         /* '<S330>/Unit Delay' */
  boolean UnitDelay_DSTATE_ph;         /* '<S329>/Unit Delay' */
  boolean UnitDelay_DSTATE_eo;         /* '<S328>/Unit Delay' */
  boolean UnitDelay_DSTATE_ei;         /* '<S327>/Unit Delay' */
  boolean UnitDelay_DSTATE_ah2;        /* '<S326>/Unit Delay' */
  boolean UnitDelay_DSTATE_ob;         /* '<S325>/Unit Delay' */
  boolean UnitDelay_DSTATE_bd;         /* '<S324>/Unit Delay' */
  boolean UnitDelay_DSTATE_go;         /* '<S323>/Unit Delay' */
  boolean UnitDelay_DSTATE_jb;         /* '<S322>/Unit Delay' */
  boolean UnitDelay_DSTATE_ky;         /* '<S321>/Unit Delay' */
  boolean UnitDelay_DSTATE_pz;         /* '<S320>/Unit Delay' */
  boolean UnitDelay_DSTATE_cr;         /* '<S319>/Unit Delay' */
  boolean UnitDelay_DSTATE_jn;         /* '<S292>/Unit Delay' */
  boolean UnitDelay_DSTATE_nv;         /* '<S278>/Unit Delay' */
  boolean UnitDelay_DSTATE_df;         /* '<S274>/Unit Delay' */
  boolean UnitDelay_DSTATE_ja;         /* '<S258>/Unit Delay' */
  boolean UnitDelay_DSTATE_e0;         /* '<S256>/Unit Delay' */
  boolean UnitDelay_DSTATE_hxq;        /* '<S255>/Unit Delay' */
  boolean UnitDelay_DSTATE_fr;         /* '<S254>/Unit Delay' */
  boolean UnitDelay_DSTATE_h0;         /* '<S252>/Unit Delay' */
  boolean UnitDelay_DSTATE_fp;         /* '<S250>/Unit Delay' */
  boolean UnitDelay_DSTATE_ie;         /* '<S248>/Unit Delay' */
  boolean UnitDelay_DSTATE_mg;         /* '<S244>/Unit Delay' */
  boolean UnitDelay_DSTATE_pcv;        /* '<S233>/Unit Delay' */
  boolean UnitDelay_DSTATE_el;         /* '<S232>/Unit Delay' */
  boolean UnitDelay_DSTATE_ka;         /* '<S231>/Unit Delay' */
  boolean UnitDelay_DSTATE_jy;         /* '<S230>/Unit Delay' */
  boolean UnitDelay_DSTATE_mv;         /* '<S209>/Unit Delay' */
  boolean UnitDelay_DSTATE_my;         /* '<S192>/Unit Delay' */
  boolean UnitDelay_DSTATE_nn0;        /* '<S190>/Unit Delay' */
  boolean UnitDelay_DSTATE_md;         /* '<S177>/Unit Delay' */
  boolean UnitDelay_DSTATE_c5;         /* '<S176>/Unit Delay' */
  boolean UnitDelay_DSTATE_az;         /* '<S174>/Unit Delay' */
  boolean UnitDelay_DSTATE_et;         /* '<S173>/Unit Delay' */
  boolean UnitDelay_DSTATE_eih;        /* '<S172>/Unit Delay' */
  boolean UnitDelay_DSTATE_dj;         /* '<S168>/Unit Delay' */
  boolean UnitDelay_DSTATE_ls;         /* '<S167>/Unit Delay' */
  boolean UnitDelay_DSTATE_px;         /* '<S164>/Unit Delay' */
  boolean UnitDelay_DSTATE_m2;         /* '<S161>/Unit Delay' */
  boolean UnitDelay_DSTATE_aj;         /* '<S143>/Unit Delay' */
  boolean UnitDelay_DSTATE_f1x;        /* '<S131>/Unit Delay' */
  boolean UnitDelay_DSTATE_fi;         /* '<S98>/Unit Delay' */
  boolean UnitDelay_DSTATE_eh;         /* '<S94>/Unit Delay' */
  boolean UnitDelay_DSTATE_kz;         /* '<S46>/Unit Delay' */
  boolean UnitDelay_DSTATE_lg;         /* '<S41>/Unit Delay' */
  boolean UnitDelay_DSTATE_jav;        /* '<S39>/Unit Delay' */
  boolean UnitDelay_DSTATE_bf;         /* '<S37>/Unit Delay' */
  boolean UnitDelay_DSTATE_ig;         /* '<S35>/Unit Delay' */
  boolean UnitDelay_DSTATE_ii;         /* '<S33>/Unit Delay' */
  boolean UnitDelay_DSTATE_do;         /* '<S31>/Unit Delay' */
  boolean UnitDelay_DSTATE_h2u;        /* '<S26>/Unit Delay' */
  boolean UnitDelay_DSTATE_ch;         /* '<S25>/Unit Delay' */
  boolean UnitDelay_DSTATE_g3;         /* '<S24>/Unit Delay' */
} ARID_DEF_AppSwcIpm_T;

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_AppSwcIpm_T AppSwcIpm_ARID_DEF;/* '<S21>/BusCreator' */

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S24>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S26>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S27>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S29>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S30>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S31>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S32>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S33>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S34>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S35>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S37>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S39>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S40>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S47>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S49>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S66>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S67>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S68>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S76>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S77>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S80>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S81>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S82>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S83>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S84>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S85>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S86>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S88>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S89>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S91>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S95>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S97>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S99>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S100>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S106>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S107>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S112>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S115>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S116>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S117>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S118>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S119>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S122>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S123>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S126>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S127>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S131>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S134>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S137>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S141>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S144>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S160>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S161>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S163>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S164>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S166>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S167>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S168>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S169>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S172>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S173>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S174>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S175>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S176>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S177>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S178>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S181>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S182>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S183>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S184>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S185>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S186>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S187>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S188>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S189>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S190>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S191>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S192>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S193>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S205>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S206>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S207>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S208>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S209>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S210>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S213>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S214>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S216>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S220>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S221>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S224>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S230>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S231>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S232>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S233>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S237>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S238>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S239>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S240>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S241>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S242>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S244>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S248>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S249>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S250>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S251>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S252>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S254>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S255>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S256>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S257>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S258>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S259>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S260>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S261>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S274>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S275>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S276>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S277>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S278>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S279>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S281>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S282>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S284>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S285>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S286>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S287>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S292>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S294>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S295>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S296>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S297>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S298>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S304>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S305>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S306>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S307>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S319>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S320>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S321>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S322>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S323>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S324>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S325>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S326>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S327>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S328>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S329>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S330>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S331>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S332>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S333>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S334>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S335>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S336>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S337>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S338>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S339>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S340>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S341>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S342>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S343>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S344>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S345>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S346>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S347>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S348>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S350>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S351>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S27>/Unit Delay' : Unused code path elimination
 * Block '<S29>/Unit Delay' : Unused code path elimination
 * Block '<S32>/Unit Delay' : Unused code path elimination
 * Block '<S40>/Unit Delay' : Unused code path elimination
 * Block '<S47>/Unit Delay' : Unused code path elimination
 * Block '<S48>/Unit Delay' : Unused code path elimination
 * Block '<S49>/Unit Delay' : Unused code path elimination
 * Block '<S50>/Unit Delay' : Unused code path elimination
 * Block '<S55>/Unit Delay' : Unused code path elimination
 * Block '<S56>/Unit Delay' : Unused code path elimination
 * Block '<S57>/Unit Delay' : Unused code path elimination
 * Block '<S58>/Unit Delay' : Unused code path elimination
 * Block '<S69>/Unit Delay' : Unused code path elimination
 * Block '<S78>/Unit Delay' : Unused code path elimination
 * Block '<S79>/Unit Delay' : Unused code path elimination
 * Block '<S93>/Unit Delay' : Unused code path elimination
 * Block '<S106>/Unit Delay' : Unused code path elimination
 * Block '<S107>/Unit Delay' : Unused code path elimination
 * Block '<S108>/Unit Delay' : Unused code path elimination
 * Block '<S120>/Unit Delay' : Unused code path elimination
 * Block '<S121>/Unit Delay' : Unused code path elimination
 * Block '<S122>/Unit Delay' : Unused code path elimination
 * Block '<S126>/Unit Delay' : Unused code path elimination
 * Block '<S127>/Unit Delay' : Unused code path elimination
 * Block '<S130>/Unit Delay' : Unused code path elimination
 * Block '<S132>/Unit Delay' : Unused code path elimination
 * Block '<S133>/Unit Delay' : Unused code path elimination
 * Block '<S134>/Unit Delay' : Unused code path elimination
 * Block '<S135>/Unit Delay' : Unused code path elimination
 * Block '<S136>/Unit Delay' : Unused code path elimination
 * Block '<S141>/Unit Delay' : Unused code path elimination
 * Block '<S142>/Unit Delay' : Unused code path elimination
 * Block '<S144>/Unit Delay' : Unused code path elimination
 * Block '<S145>/Unit Delay' : Unused code path elimination
 * Block '<S158>/Unit Delay' : Unused code path elimination
 * Block '<S159>/Unit Delay' : Unused code path elimination
 * Block '<S160>/Unit Delay' : Unused code path elimination
 * Block '<S162>/Unit Delay' : Unused code path elimination
 * Block '<S166>/Unit Delay' : Unused code path elimination
 * Block '<S169>/Unit Delay' : Unused code path elimination
 * Block '<S178>/Unit Delay' : Unused code path elimination
 * Block '<S180>/Unit Delay' : Unused code path elimination
 * Block '<S186>/Unit Delay' : Unused code path elimination
 * Block '<S187>/Unit Delay' : Unused code path elimination
 * Block '<S188>/Unit Delay' : Unused code path elimination
 * Block '<S189>/Unit Delay' : Unused code path elimination
 * Block '<S191>/Unit Delay' : Unused code path elimination
 * Block '<S193>/Unit Delay' : Unused code path elimination
 * Block '<S204>/Unit Delay' : Unused code path elimination
 * Block '<S205>/Unit Delay' : Unused code path elimination
 * Block '<S207>/Unit Delay' : Unused code path elimination
 * Block '<S213>/Unit Delay' : Unused code path elimination
 * Block '<S214>/Unit Delay' : Unused code path elimination
 * Block '<S215>/Unit Delay' : Unused code path elimination
 * Block '<S216>/Unit Delay' : Unused code path elimination
 * Block '<S220>/Unit Delay' : Unused code path elimination
 * Block '<S221>/Unit Delay' : Unused code path elimination
 * Block '<S229>/Unit Delay' : Unused code path elimination
 * Block '<S243>/Unit Delay' : Unused code path elimination
 * Block '<S245>/Unit Delay' : Unused code path elimination
 * Block '<S246>/Unit Delay' : Unused code path elimination
 * Block '<S247>/Unit Delay' : Unused code path elimination
 * Block '<S249>/Unit Delay' : Unused code path elimination
 * Block '<S251>/Unit Delay' : Unused code path elimination
 * Block '<S253>/Unit Delay' : Unused code path elimination
 * Block '<S257>/Unit Delay' : Unused code path elimination
 * Block '<S259>/Unit Delay' : Unused code path elimination
 * Block '<S273>/Unit Delay' : Unused code path elimination
 * Block '<S275>/Unit Delay' : Unused code path elimination
 * Block '<S280>/Unit Delay' : Unused code path elimination
 * Block '<S284>/Unit Delay' : Unused code path elimination
 * Block '<S285>/Unit Delay' : Unused code path elimination
 * Block '<S286>/Unit Delay' : Unused code path elimination
 * Block '<S287>/Unit Delay' : Unused code path elimination
 * Block '<S293>/Unit Delay' : Unused code path elimination
 * Block '<S294>/Unit Delay' : Unused code path elimination
 * Block '<S295>/Unit Delay' : Unused code path elimination
 * Block '<S296>/Unit Delay' : Unused code path elimination
 * Block '<S297>/Unit Delay' : Unused code path elimination
 * Block '<S298>/Unit Delay' : Unused code path elimination
 * Block '<S304>/Unit Delay' : Unused code path elimination
 * Block '<S305>/Unit Delay' : Unused code path elimination
 * Block '<S306>/Unit Delay' : Unused code path elimination
 * Block '<S307>/Unit Delay' : Unused code path elimination
 * Block '<S312>/Unit Delay' : Unused code path elimination
 * Block '<S313>/Unit Delay' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AppSwcIpm'
 * '<S1>'   : 'AppSwcIpm/InitializeFunction'
 * '<S2>'   : 'AppSwcIpm/Ipm100ms'
 * '<S3>'   : 'AppSwcIpm/Ipm10ms'
 * '<S4>'   : 'AppSwcIpm/Ipm20ms'
 * '<S5>'   : 'AppSwcIpm/Ipm50ms'
 * '<S6>'   : 'AppSwcIpm/IpmMsgActv'
 * '<S7>'   : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms'
 * '<S8>'   : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms'
 * '<S9>'   : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms'
 * '<S10>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms'
 * '<S11>'  : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms'
 * '<S12>'  : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms'
 * '<S13>'  : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms'
 * '<S14>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD'
 * '<S15>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_APPVerMax_enum'
 * '<S16>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_APPVerMin_enum'
 * '<S17>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_BootVer_enum'
 * '<S18>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_ClientNum_enum'
 * '<S19>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_HwVerMax_enum'
 * '<S20>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_HwVerMin_enum'
 * '<S21>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD'
 * '<S22>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD'
 * '<S23>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD'
 * '<S24>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPCANBusOff_flg'
 * '<S25>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPCommuError_flg'
 * '<S26>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPCurrOfst_flg'
 * '<S27>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPEcompActSpd_rpm'
 * '<S28>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPEcompST_enum'
 * '<S29>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPHiVolt_V'
 * '<S30>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPHvErr_enum'
 * '<S31>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPIPMErr_flg'
 * '<S32>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPInCurr_A'
 * '<S33>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPLoseStep_flg'
 * '<S34>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPLvErr_enum'
 * '<S35>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPOverDuty_flg'
 * '<S36>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPOvrCurr_enum'
 * '<S37>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPPISaturation_flg'
 * '<S38>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPSelfChkErr_enum'
 * '<S39>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPTempErr_flg'
 * '<S40>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPTemp_C'
 * '<S41>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_ECUHiVoltInterlockSig_flg'
 * '<S42>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in'
 * '<S43>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in1'
 * '<S44>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in2'
 * '<S45>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in3'
 * '<S46>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHHVSt_flg'
 * '<S47>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHInletTemp_C'
 * '<S48>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHOutlTemp_C'
 * '<S49>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHPCBTemp_C'
 * '<S50>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHSt_enum'
 * '<S51>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHWorkMode_enum'
 * '<S52>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/rescale_in'
 * '<S53>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/rescale_in1'
 * '<S54>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status1_BOD/rescale_in2'
 * '<S55>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHCurr_A'
 * '<S56>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHFltCod_enum'
 * '<S57>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHHVVolts_V'
 * '<S58>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHPwr_kW'
 * '<S59>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHWorkSt_enum'
 * '<S60>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/rescale_in'
 * '<S61>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/rescale_in1'
 * '<S62>'  : 'AppSwcIpm/Ipm100ms/BODCAN_IN_100ms/Msg_HVCH_Status2_BOD/rescale_in2'
 * '<S63>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC'
 * '<S64>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeDay_nu'
 * '<S65>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeHour_nu'
 * '<S66>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeMin_nu'
 * '<S67>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeMonth_nu'
 * '<S68>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeSec_nu'
 * '<S69>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeYear_nu'
 * '<S70>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/rescale_in'
 * '<S71>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC'
 * '<S72>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_CDCBackLadjval_enum'
 * '<S73>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUACAutoCtl_enum'
 * '<S74>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUACPwrCtl_enum'
 * '<S75>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUAirInletModeSet_enum'
 * '<S76>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUBlwrModeSet_enum'
 * '<S77>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChgWiprMtMdSwSet_enum'
 * '<S78>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUCstRecupModeSel_enum'
 * '<S79>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUDrvModeSel_enum'
 * '<S80>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUDrvPwrSet_cnt'
 * '<S81>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUFlwrMeHmCtrl_enum'
 * '<S82>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUFrntFanSpdSet_enum'
 * '<S83>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUHybEcoModeSet_enum'
 * '<S84>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndEntrySts_enum'
 * '<S85>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndLckSts_enum'
 * '<S86>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndUnlckSts_enum'
 * '<S87>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HULckHornOnSt_enum'
 * '<S88>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HULeftTempSet_enum'
 * '<S89>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUMaiDrvrSeatHeat_enum'
 * '<S90>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUManlDefrstCtl_enum'
 * '<S91>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUOvrspdCntrlLckSet_enum'
 * '<S92>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUParkAutoUnlckSet_enum'
 * '<S93>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUPeristalsisModeEnbl_enum'
 * '<S94>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUPwrOffReq_flg'
 * '<S95>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HURecupPwrSet_pct'
 * '<S96>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HURrMirrHeat_enum'
 * '<S97>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUSteerWhlHeat_enum'
 * '<S98>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUTPMSRstReq_flg'
 * '<S99>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUTrnkLckSwCtrl_enum'
 * '<S100>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUWiprIntlTmSet_enum'
 * '<S101>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT'
 * '<S102>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT'
 * '<S103>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT'
 * '<S104>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT'
 * '<S105>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT'
 * '<S106>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempAve_C'
 * '<S107>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempMax_C'
 * '<S108>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempMin_C'
 * '<S109>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in'
 * '<S110>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in1'
 * '<S111>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in2'
 * '<S112>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData02_nu'
 * '<S113>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData03_nu'
 * '<S114>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData04_nu'
 * '<S115>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData05_nu'
 * '<S116>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData06_nu'
 * '<S117>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData07_nu'
 * '<S118>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngSts_enum'
 * '<S119>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngSubID_cnt'
 * '<S120>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCActOprtMode_enum'
 * '<S121>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCLoVoltActCurnt_A'
 * '<S122>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCLoVoltActVolt_V'
 * '<S123>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCSysFailSta_enum'
 * '<S124>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/rescale_in'
 * '<S125>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/rescale_in1'
 * '<S126>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/Subsys_VIPM_IPUDCCHiVoltActCurnt_A'
 * '<S127>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/Subsys_VIPM_IPUDCCHiVoltActVolt_V'
 * '<S128>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/rescale_in'
 * '<S129>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/rescale_in1'
 * '<S130>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCActOprtMode_enum'
 * '<S131>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCConnectMainSta_flg'
 * '<S132>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCHVDCActCur_A'
 * '<S133>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCHVDCActVol_V'
 * '<S134>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCInletActPwr_kW'
 * '<S135>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCInletConnectSta_enum'
 * '<S136>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCReq_enum'
 * '<S137>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCSysFailSta_enum'
 * '<S138>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/rescale_in'
 * '<S139>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/rescale_in1'
 * '<S140>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT'
 * '<S141>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUDeviceIntTemp_C'
 * '<S142>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW'
 * '<S143>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCS2State_flg'
 * '<S144>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCTempInt_C'
 * '<S145>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCWakeUpMode_enum'
 * '<S146>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in'
 * '<S147>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in1'
 * '<S148>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in2'
 * '<S149>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT'
 * '<S150>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_BMSBatCapcty_Ah'
 * '<S151>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_BMSPackID_enum'
 * '<S152>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms'
 * '<S153>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms'
 * '<S154>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA'
 * '<S155>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA'
 * '<S156>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA'
 * '<S157>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA'
 * '<S158>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPedlValPerc_pct'
 * '<S159>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum'
 * '<S160>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm'
 * '<S161>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBCDDActv_flg'
 * '<S162>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBEPBActuatorStR_enum'
 * '<S163>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBFltLvl_enum'
 * '<S164>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBReqBrkLiOn_flg'
 * '<S165>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/rescale_in'
 * '<S166>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSRotSpd_degps'
 * '<S167>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAngCald_flg'
 * '<S168>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAngFailr_flg'
 * '<S169>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAng_deg'
 * '<S170>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/rescale_in'
 * '<S171>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/rescale_in1'
 * '<S172>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCABSActvSta_flg'
 * '<S173>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCESPActvSta_flg'
 * '<S174>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCESSActv_flg'
 * '<S175>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCFltLvl_enum'
 * '<S176>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCReqBrkLghtOn_flg'
 * '<S177>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCTCSActvSta_flg'
 * '<S178>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCVehSpd_kph'
 * '<S179>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/rescale_in'
 * '<S180>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCMstrCylPresr_bar'
 * '<S181>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCVehStandStillSta_enum'
 * '<S182>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnFL_enum'
 * '<S183>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnFR_enum'
 * '<S184>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnRL_enum'
 * '<S185>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnRR_enum'
 * '<S186>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphFL_kph'
 * '<S187>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphFR_kph'
 * '<S188>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphRL_kph'
 * '<S189>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphRR_kph'
 * '<S190>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqDecReqActv_flg'
 * '<S191>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqDecReqVal_Nm'
 * '<S192>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqIncReqActv_flg'
 * '<S193>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqIncReqVal_Nm'
 * '<S194>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in'
 * '<S195>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in1'
 * '<S196>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in2'
 * '<S197>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in3'
 * '<S198>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in4'
 * '<S199>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in5'
 * '<S200>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT'
 * '<S201>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT'
 * '<S202>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT'
 * '<S203>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_4_Value_EPT'
 * '<S204>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ActMode_enum'
 * '<S205>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ActTorq_Nm'
 * '<S206>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1AntithftAuthRslt_enum'
 * '<S207>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1MotSpd_rpm'
 * '<S208>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1PreChrgAllwd_enum'
 * '<S209>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1PreprogmFlg_flg'
 * '<S210>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ShutdownAllwd_enum'
 * '<S211>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/rescale_in'
 * '<S212>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/rescale_in1'
 * '<S213>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2IgbtMaxTemp_C'
 * '<S214>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2InpCurnt_A'
 * '<S215>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2InpVolt_V'
 * '<S216>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2MotorMaxTemp_C'
 * '<S217>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in'
 * '<S218>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in1'
 * '<S219>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in2'
 * '<S220>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/Subsys_VIPM_INV3DrvTqAllwdMax_Nm'
 * '<S221>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/Subsys_VIPM_INV3RecupTqAllwdMax_Nm'
 * '<S222>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/rescale_in'
 * '<S223>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/rescale_in1'
 * '<S224>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_4_Value_EPT/Subsys_VIPM_INV4FltLvl_enum'
 * '<S225>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms'
 * '<S226>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms'
 * '<S227>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms'
 * '<S228>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD'
 * '<S229>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSGrShftLvrPstnReq_enum'
 * '<S230>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght11Sw_flg'
 * '<S231>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght12Sw_flg'
 * '<S232>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght13Sw_flg'
 * '<S233>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRghtSwVldty_flg'
 * '<S234>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA'
 * '<S235>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA'
 * '<S236>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA'
 * '<S237>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRBSDWarnLt_enum'
 * '<S238>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRBSDWarnRt_enum'
 * '<S239>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRDOWWarnLt_enum'
 * '<S240>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRDOWWarnRt_enum'
 * '<S241>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRRCTAWarnLt_enum'
 * '<S242>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRRCTAWarnRt_enum'
 * '<S243>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBAVHAppldSt_enum'
 * '<S244>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBBLA_flg'
 * '<S245>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBActuatorStL_enum'
 * '<S246>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBSwitchSts_enum'
 * '<S247>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBSysSt_enum'
 * '<S248>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBHDCFucFault_flg'
 * '<S249>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlDece_mps2'
 * '<S250>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlTqReqActv_flg'
 * '<S251>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlTqReqVal_Nm'
 * '<S252>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAEBReq_flg'
 * '<S253>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccMode_enum'
 * '<S254>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccReqDriveOff_flg'
 * '<S255>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccReqStandstill_flg'
 * '<S256>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTarAccrnReqActv_flg'
 * '<S257>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTarAccrn_mps2'
 * '<S258>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTgtAxReq_flg'
 * '<S259>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTgtAx_mps2'
 * '<S260>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMEPBReq_enum'
 * '<S261>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMTrnLampReq_enum'
 * '<S262>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in'
 * '<S263>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in1'
 * '<S264>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in2'
 * '<S265>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in3'
 * '<S266>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT'
 * '<S267>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT'
 * '<S268>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT'
 * '<S269>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_3_DC_ChargeState_EPT'
 * '<S270>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT'
 * '<S271>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT'
 * '<S272>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT'
 * '<S273>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT/Subsys_VIPM_BMSDCSActOprtMode_enum'
 * '<S274>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT/Subsys_VIPM_BMSDCSInletConnectSta_flg'
 * '<S275>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSActExchgCurnt_A'
 * '<S276>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSChrgInterlockSta_enum'
 * '<S277>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSDchrgInterlockSta_enum'
 * '<S278>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSEmgcySdnReq_flg'
 * '<S279>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSPwrTrainConnectSta_enum'
 * '<S280>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSRunSta_enum'
 * '<S281>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSSysFailSta_enum'
 * '<S282>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSThermrunawayWrn_enum'
 * '<S283>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/rescale_in'
 * '<S284>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOCAct_pct'
 * '<S285>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOCRpt_pct'
 * '<S286>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOH_pct'
 * '<S287>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSHVBatActVolt_V'
 * '<S288>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in'
 * '<S289>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in1'
 * '<S290>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in2'
 * '<S291>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in3'
 * '<S292>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_3_DC_ChargeState_EPT/Subsys_VIPM_BMSDCSChrgReq_flg'
 * '<S293>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSACChrgAtclSta_enum'
 * '<S294>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSInletCooltActlTemp_C'
 * '<S295>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSIsoResist_MOhm'
 * '<S296>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSMaxChrgCurntAC_A'
 * '<S297>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSMaxChrgVoltAC_V'
 * '<S298>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSOutlCooltActlTemp_C'
 * '<S299>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in'
 * '<S300>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in1'
 * '<S301>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in2'
 * '<S302>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in3'
 * '<S303>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in4'
 * '<S304>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxConChrgCurnt_A'
 * '<S305>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxConDisCurnt_A'
 * '<S306>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxInsChrgCurnt_A'
 * '<S307>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxInsDisCurnt_A'
 * '<S308>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in'
 * '<S309>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in1'
 * '<S310>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in2'
 * '<S311>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in3'
 * '<S312>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT/Subsys_VIPM_BMSCellVoltMax_mV'
 * '<S313>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT/Subsys_VIPM_BMSCellVoltMin_mV'
 * '<S314>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms'
 * '<S315>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms'
 * '<S316>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD'
 * '<S317>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_ESCL_ESCLStatus_BOD'
 * '<S318>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD'
 * '<S319>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPACAutoKey_flg'
 * '<S320>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPACSwKey_flg'
 * '<S321>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAVASOffKey_flg'
 * '<S322>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAVHKey_flg'
 * '<S323>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAirInletModeKey_flg'
 * '<S324>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwngModeNextKey_flg'
 * '<S325>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwngModePrevKey_flg'
 * '<S326>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwrLvlAddKey_flg'
 * '<S327>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwrLvlDecKey_flg'
 * '<S328>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPCenLckKey_flg'
 * '<S329>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPESCOffKey_flg'
 * '<S330>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPFrntWindDefrstKey_flg'
 * '<S331>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPHDCKey_flg'
 * '<S332>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPHzrdKey_flg'
 * '<S333>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPModeKey_flg'
 * '<S334>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPPwrRecupLvlKey_flg'
 * '<S335>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg'
 * '<S336>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTPMSKey_flg'
 * '<S337>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTempAddKey_flg'
 * '<S338>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTempDecKey_flg'
 * '<S339>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_ESCL_ESCLStatus_BOD/Subsys_VIPM_ESCLUnOrLockfeedback_nu'
 * '<S340>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSFrntWiprSwtSt_enum'
 * '<S341>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSFrntWshrSwtSt_flg'
 * '<S342>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSHiBeamSwSt_flg'
 * '<S343>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLampAutoSt_flg'
 * '<S344>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLeTrnLmpSwSt_flg'
 * '<S345>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLoBeamSwSt_flg'
 * '<S346>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSOvrVehBeamSwSt_flg'
 * '<S347>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSPstnLghtSwSt_flg'
 * '<S348>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSRiTrnLmpSwSt_flg'
 * '<S349>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA'
 * '<S350>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA/Subsys_VIPM_SRSCrashOutputSts_enum'
 * '<S351>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA/Subsys_VIPM_SRSDrvSeatbeltBkld_flg'
 * '<S352>' : 'AppSwcIpm/IpmMsgActv/CANCommError'
 * '<S353>' : 'AppSwcIpm/IpmMsgActv/MsgActv'
 */
#endif                                 /* RTW_HEADER_AppSwcIpm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
