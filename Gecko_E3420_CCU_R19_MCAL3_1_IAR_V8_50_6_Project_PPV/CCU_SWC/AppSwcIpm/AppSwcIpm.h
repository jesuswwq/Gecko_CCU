/*
 * File: AppSwcIpm.h
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.231
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Feb 10 15:10:30 2025
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
#include "AppSwcIpm_types.h"

/* Includes for objects with custom storage classes */
#include "calPrmsIpm.h"
#include "monPrmsIpm.h"

/* user code (top of header file) */
#include"ME11_ABI.h"
#include"DIAG_ABI.h"

/* PublicStructure Variables for Internal Data, for system '<S395>/Chart' */
typedef struct {
  float32 t;                           /* '<S395>/Chart' */
} ARID_DEF_Chart_AppSwcIpm_T;

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  ARID_DEF_Chart_AppSwcIpm_T ARID_DEF_Chart;/* '<S398>/Chart' */
  ARID_DEF_Chart_AppSwcIpm_T ARID_DEF_Chart_o;/* '<S397>/Chart' */
  ARID_DEF_Chart_AppSwcIpm_T ARID_DEF_Chart_n;/* '<S396>/Chart' */
  ARID_DEF_Chart_AppSwcIpm_T ARID_DEF_Chart_i;/* '<S395>/Chart' */
  DT_IPM_HU_B_BAC IPM_HU_B_BAC_m;      /* '<S24>/BusCreator' */
  DT_IPM_ESC_A_CHA ESC_A_CHA_f;        /* '<S185>/BusCreator' */
  DT_IPM_COMP_AC_BOD IPM_COMP_AC_BOD_c;/* '<S83>/BusCreator' */
  DT_IPM_FCM_B_CHA IPM_FCM_B_CHA_k;    /* '<S275>/BusCreator' */
  DT_IPM_BMS_4_AC_ChargeState_EPT IPM_BMS_4_AC_ChargeState_EPT_c;/* '<S310>/BusCreator' */
  DT_IPM_CCP_PanelStatus_BOD IPM_CCP_PanelStatus_BOD_p;/* '<S356>/BusCreator' */
  DT_IPM_IPU_OBC_1_State_EPT IPM_IPU_OBC_1_State_EPT_b;/* '<S132>/BusCreator' */
  DT_IPM_BMS_2_BatState_EPT IPM_BMS_2_BatState_EPT_n;/* '<S308>/BusCreator' */
  DT_IPM_BMS_6_DischrgRecup_EPT IPM_BMS_6_DischrgRecup_EPT_m;/* '<S311>/BusCreator' */
  DT_IPM_EHB_B_CHA EHB_B_CHA_l;        /* '<S182>/BusCreator' */
  DT_IPM_ESC_7_FuncStatus_CHA ESC_7_FuncStatus_CHA_a;/* '<S184>/BusCreator' */
  DT_IPM_HVCH_Status1_BOD IPM_HVCH_Status1_BOD_g;/* '<S84>/BusCreator' */
  DT_IPM_HVCH_Status2_BOD IPM_HVCH_Status2_BOD_g;/* '<S85>/BusCreator' */
  DT_IPM_INV_2_Value_EPT IPM_INV_2_Value_EPT_f;/* '<S240>/BusCreator' */
  DT_IPM_IPU_OBC_2_Inlet_EPT IPM_IPU_OBC_2_Inlet_EPT_c;/* '<S168>/BusCreator' */
  DT_IPM_BMS_1_MainState_EPT BusCreator;/* '<S307>/BusCreator' */
  DT_IPM_BMS_5_BatTemp_EPT IPM_BMS_5_BatTemp_EPT_l;/* '<S128>/BusCreator' */
  DT_IPM_EPS_2_StrWhlAng_CHA IPM_EPS_2_StrWhlAng_CHA_g;/* '<S183>/BusCreator' */
  DT_IPM_INV_1_Value_EPT IPM_INV_1_Value_EPT_d;/* '<S239>/BusCreator' */
  DT_IPM_IPU_DCC_1_State_EPT IPM_IPU_DCC_1_State_EPT_j;/* '<S130>/BusCreator' */
  DT_IPM_SCS_LeSwitchSts_BOD IPM_SCS_LeSwitchSts_BOD_l;/* '<S358>/BusCreator' */
  DT_MsgActv MsgActv_outputs_p;        /* '<S6>/BusCreator' */
  DT_IPM_ACCM_Version_BOD IPM_ACCM_Version_BOD_d;/* '<S76>/BusCreator' */
  DT_IPM_BMS_7_CellVolt_EPT IPM_BMS_7_CellVolt_EPT_b;/* '<S312>/BusCreator' */
  DT_IPM_CRRR_A_CHA IPM_CRRR_A_CHA_h;  /* '<S273>/BusCreator' */
  DT_IPM_EHB_A_CHA IPM_EHB_A_CHA_l;    /* '<S274>/BusCreator' */
  DT_IPM_ESCL_ESCLStatus_BOD IPM_ESCL_ESCLStatus_BOD_b;/* '<S357>/BusCreator' */
  DT_IPM_INV_3_Value_EPT IPM_INV_3_Value_EPT_n;/* '<S241>/BusCreator' */
  DT_IPM_INV_IMMO_Req_EPT IPM_INV_IMMO_Req_EPT_b;/* '<S129>/BusCreator' */
  DT_IPM_IPU_DCC_2_ChrgInValue_EPT IPM_IPU_DCC_2_ChrgInValue_EPT_o;/* '<S131>/BusCreator' */
  DT_IPM_SCS_RiSwitchSts_BOD IPM_SCS_RiSwitchSts_BOD_l;/* '<S267>/BusCreator1' */
  DT_IPM_TBOX_BJS_Time_BAC IPM_TBOX_BJS_Time_BAC_d;/* '<S15>/BusCreator' */
  DT_IPM_BMS_10_DC_ChargeStates_EPT IPM_BMS_10_DC_ChargeStates_EPT_j;/* '<S306>/BusCreator' */
  DT_IPM_BMS_3_DC_ChargeState_EPT IPM_BMS_3_DC_ChargeState_EPT_j;/* '<S309>/BusCreator' */
  DT_IPM_BMS_9_BattInfo_EPT IPM_BMS_9_BattInfo_EPT_a;/* '<S177>/BusCreator' */
  DT_IPM_FCM_A_CHA IPM_FCM_A_CHA_f;    /* '<S125>/BusCreator' */
  DT_IPM_ICU_2_Odo_BAC IPM_ICU_2_Odo_BAC_j;/* '<S23>/BusCreator' */
  DT_IPM_INV_4_Value_EPT IPM_INV_4_Value_EPT_b;/* '<S242>/BusCreator' */
  DT_IPM_SRS_1_Status_CHA IPM_SRS_1_Status_CHA_e;/* '<S389>/BusCreator' */
  uint64 UnitDelay_DSTATE;             /* '<S379>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S327>/Unit Delay' */
  float32 UnitDelay_DSTATE_d;          /* '<S326>/Unit Delay' */
  float32 UnitDelay_DSTATE_c;          /* '<S325>/Unit Delay' */
  float32 UnitDelay_DSTATE_n;          /* '<S324>/Unit Delay' */
  float32 UnitDelay_DSTATE_e;          /* '<S299>/Unit Delay' */
  float32 UnitDelay_DSTATE_j;          /* '<S297>/Unit Delay' */
  float32 UnitDelay_DSTATE_f;          /* '<S291>/Unit Delay' */
  float32 UnitDelay_DSTATE_o;          /* '<S289>/Unit Delay' */
  float32 UnitDelay_DSTATE_jy;         /* '<S246>/Unit Delay' */
  float32 UnitDelay_DSTATE_k;          /* '<S244>/Unit Delay' */
  float32 UnitDelay_DSTATE_dc;         /* '<S210>/Unit Delay' */
  float32 UnitDelay_DSTATE_ev;         /* '<S208>/Unit Delay' */
  float32 UnitDelay_DSTATE_a;          /* '<S198>/Unit Delay' */
  float32 UnitDelay_DSTATE_au;         /* '<S195>/Unit Delay' */
  float32 UnitDelay_DSTATE_eu;         /* '<S188>/Unit Delay' */
  float32 UnitDelay_DSTATE_jg;         /* '<S186>/Unit Delay' */
  float32 UnitDelay_DSTATE_ow;         /* '<S149>/Unit Delay' */
  float32 UnitDelay_DSTATE_p;          /* '<S148>/Unit Delay' */
  float32 UnitDelay_DSTATE_e1;         /* '<S111>/Unit Delay' */
  float32 UnitDelay_DSTATE_py;         /* '<S110>/Unit Delay' */
  float32 UnitDelay_DSTATE_lk;         /* '<S109>/Unit Delay' */
  float32 UnitDelay_DSTATE_lq;         /* '<S102>/Unit Delay' */
  float32 UnitDelay_DSTATE_h;          /* '<S94>/Unit Delay' */
  float32 UnitDelay_DSTATE_kc;         /* '<S91>/Unit Delay' */
  float32 UnitDelay_DSTATE_hz;         /* '<S89>/Unit Delay' */
  uint16 UnitDelay_DSTATE_g;           /* '<S21>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fi;           /* '<S390>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nh;           /* '<S380>/Unit Delay' */
  uint8 UnitDelay_DSTATE_dg;           /* '<S322>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jh;           /* '<S321>/Unit Delay' */
  uint8 UnitDelay_DSTATE_b;            /* '<S319>/Unit Delay' */
  uint8 UnitDelay_DSTATE_of;           /* '<S317>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gr;           /* '<S316>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jk;           /* '<S301>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pi;           /* '<S300>/Unit Delay' */
  uint8 UnitDelay_DSTATE_k3;           /* '<S288>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m;            /* '<S281>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hf;           /* '<S280>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hg;           /* '<S279>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ms;           /* '<S278>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ki;           /* '<S277>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ows;          /* '<S276>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ga;           /* '<S263>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nu;           /* '<S249>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gn;           /* '<S247>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jq;           /* '<S245>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lj;           /* '<S220>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ff;           /* '<S219>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nj;           /* '<S218>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jc;           /* '<S217>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hi;           /* '<S216>/Unit Delay' */
  uint8 UnitDelay_DSTATE_kv;           /* '<S206>/Unit Delay' */
  uint8 UnitDelay_DSTATE_da;           /* '<S192>/Unit Delay' */
  uint8 UnitDelay_DSTATE_i;            /* '<S191>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jhg;          /* '<S179>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ol;           /* '<S178>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mu;           /* '<S165>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ph;           /* '<S150>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nf;           /* '<S146>/Unit Delay' */
  uint8 UnitDelay_DSTATE_i5;           /* '<S145>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lg;           /* '<S144>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pc;           /* '<S143>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hl;           /* '<S142>/Unit Delay' */
  uint8 UnitDelay_DSTATE_euu;          /* '<S141>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ec;           /* '<S140>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ju;           /* '<S139>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c4;           /* '<S121>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h2;           /* '<S113>/Unit Delay' */
  uint8 UnitDelay_DSTATE_g5;           /* '<S112>/Unit Delay' */
  uint8 UnitDelay_DSTATE_iv;           /* '<S100>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pr;           /* '<S98>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ck;           /* '<S96>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pcn;          /* '<S92>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lo;           /* '<S90>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ha;           /* '<S82>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pyg;          /* '<S81>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hzk;          /* '<S80>/Unit Delay' */
  uint8 UnitDelay_DSTATE_evy;          /* '<S79>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ge;           /* '<S78>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ce;           /* '<S77>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mn;           /* '<S75>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c5;           /* '<S74>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c3;           /* '<S73>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ps;           /* '<S72>/Unit Delay' */
  uint8 UnitDelay_DSTATE_as;           /* '<S68>/Unit Delay' */
  uint8 UnitDelay_DSTATE_js;           /* '<S67>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ic;           /* '<S66>/Unit Delay' */
  uint8 UnitDelay_DSTATE_bo;           /* '<S65>/Unit Delay' */
  uint8 UnitDelay_DSTATE_cc;           /* '<S64>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nuf;          /* '<S63>/Unit Delay' */
  uint8 UnitDelay_DSTATE_np;           /* '<S62>/Unit Delay' */
  uint8 UnitDelay_DSTATE_a1;           /* '<S61>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ks;           /* '<S60>/Unit Delay' */
  uint8 UnitDelay_DSTATE_a5;           /* '<S59>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mj;           /* '<S57>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fiu;          /* '<S56>/Unit Delay' */
  uint8 UnitDelay_DSTATE_dk;           /* '<S55>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fq;           /* '<S52>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hig;          /* '<S51>/Unit Delay' */
  uint8 UnitDelay_DSTATE_kz;           /* '<S50>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h0;           /* '<S49>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lz;           /* '<S48>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fc;           /* '<S47>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nfb;          /* '<S46>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jks;          /* '<S45>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ad;           /* '<S44>/Unit Delay' */
  uint8 UnitDelay_DSTATE_o3;           /* '<S43>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ap;           /* '<S42>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hv;           /* '<S41>/Unit Delay' */
  uint8 UnitDelay_DSTATE_bg;           /* '<S40>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mv;           /* '<S37>/Unit Delay' */
  uint8 UnitDelay_DSTATE_cd;           /* '<S36>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gw;           /* '<S35>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fe;           /* '<S34>/Unit Delay' */
  uint8 UnitDelay_DSTATE_cu;           /* '<S33>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lt;           /* '<S32>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jp;           /* '<S31>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jv;           /* '<S30>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m2;           /* '<S29>/Unit Delay' */
  uint8 UnitDelay_DSTATE_px;           /* '<S28>/Unit Delay' */
  uint8 UnitDelay_DSTATE_af;           /* '<S27>/Unit Delay' */
  uint8 UnitDelay_DSTATE_no;           /* '<S20>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ah;           /* '<S19>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jg0;          /* '<S18>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ke;           /* '<S17>/Unit Delay' */
  uint8 UnitDelay_DSTATE_iy;           /* '<S16>/Unit Delay' */
  EnumRegenModeSelct UnitDelay_DSTATE_ca;/* '<S38>/Unit Delay' */
  EnumDrvModeSelct UnitDelay_DSTATE_k0;/* '<S39>/Unit Delay' */
  EnumCrpModeEnbl UnitDelay_DSTATE_dt; /* '<S53>/Unit Delay' */
  EnumDCCActMd UnitDelay_DSTATE_ov;    /* '<S147>/Unit Delay' */
  EnumRegenTgtTqStat UnitDelay_DSTATE_n0;/* '<S187>/Unit Delay' */
  EnumEPBState UnitDelay_DSTATE_cj;    /* '<S190>/Unit Delay' */
  EnumINVActMd UnitDelay_DSTATE_cw;    /* '<S243>/Unit Delay' */
  EnumGrShftLvrPstnReq UnitDelay_DSTATE_n1;/* '<S268>/Unit Delay' */
  EnumACCMode UnitDelay_DSTATE_ecm;    /* '<S293>/Unit Delay' */
  boolean UnitDelay3_DSTATE;           /* '<S396>/Unit Delay3' */
  boolean UnitDelay3_DSTATE_l;         /* '<S397>/Unit Delay3' */
  boolean UnitDelay3_DSTATE_o;         /* '<S395>/Unit Delay3' */
  boolean UnitDelay3_DSTATE_g;         /* '<S398>/Unit Delay3' */
  boolean UnitDelay_DSTATE_fl;         /* '<S391>/Unit Delay' */
  boolean UnitDelay_DSTATE_ds;         /* '<S388>/Unit Delay' */
  boolean UnitDelay_DSTATE_ko;         /* '<S387>/Unit Delay' */
  boolean UnitDelay_DSTATE_cds;        /* '<S386>/Unit Delay' */
  boolean UnitDelay_DSTATE_oa;         /* '<S385>/Unit Delay' */
  boolean UnitDelay_DSTATE_du;         /* '<S384>/Unit Delay' */
  boolean UnitDelay_DSTATE_bc;         /* '<S383>/Unit Delay' */
  boolean UnitDelay_DSTATE_dcs;        /* '<S382>/Unit Delay' */
  boolean UnitDelay_DSTATE_f1;         /* '<S381>/Unit Delay' */
  boolean UnitDelay_DSTATE_i5p;        /* '<S378>/Unit Delay' */
  boolean UnitDelay_DSTATE_nz;         /* '<S377>/Unit Delay' */
  boolean UnitDelay_DSTATE_e1e;        /* '<S376>/Unit Delay' */
  boolean UnitDelay_DSTATE_dp;         /* '<S375>/Unit Delay' */
  boolean UnitDelay_DSTATE_b1;         /* '<S374>/Unit Delay' */
  boolean UnitDelay_DSTATE_p1;         /* '<S373>/Unit Delay' */
  boolean UnitDelay_DSTATE_it;         /* '<S372>/Unit Delay' */
  boolean UnitDelay_DSTATE_kd;         /* '<S371>/Unit Delay' */
  boolean UnitDelay_DSTATE_ab;         /* '<S370>/Unit Delay' */
  boolean UnitDelay_DSTATE_phn;        /* '<S369>/Unit Delay' */
  boolean UnitDelay_DSTATE_eo;         /* '<S368>/Unit Delay' */
  boolean UnitDelay_DSTATE_ei;         /* '<S367>/Unit Delay' */
  boolean UnitDelay_DSTATE_ah2;        /* '<S366>/Unit Delay' */
  boolean UnitDelay_DSTATE_ob;         /* '<S365>/Unit Delay' */
  boolean UnitDelay_DSTATE_bd;         /* '<S364>/Unit Delay' */
  boolean UnitDelay_DSTATE_go;         /* '<S363>/Unit Delay' */
  boolean UnitDelay_DSTATE_jb;         /* '<S362>/Unit Delay' */
  boolean UnitDelay_DSTATE_ky;         /* '<S361>/Unit Delay' */
  boolean UnitDelay_DSTATE_pz;         /* '<S360>/Unit Delay' */
  boolean UnitDelay_DSTATE_cr;         /* '<S359>/Unit Delay' */
  boolean UnitDelay_DSTATE_jn;         /* '<S332>/Unit Delay' */
  boolean UnitDelay_DSTATE_nv;         /* '<S318>/Unit Delay' */
  boolean UnitDelay_DSTATE_df;         /* '<S314>/Unit Delay' */
  boolean UnitDelay_DSTATE_cb;         /* '<S298>/Unit Delay' */
  boolean UnitDelay_DSTATE_m2f;        /* '<S296>/Unit Delay' */
  boolean UnitDelay_DSTATE_iv1;        /* '<S295>/Unit Delay' */
  boolean UnitDelay_DSTATE_g3;         /* '<S294>/Unit Delay' */
  boolean UnitDelay_DSTATE_jg0u;       /* '<S292>/Unit Delay' */
  boolean UnitDelay_DSTATE_ep;         /* '<S290>/Unit Delay' */
  boolean UnitDelay_DSTATE_ie;         /* '<S287>/Unit Delay' */
  boolean UnitDelay_DSTATE_mg;         /* '<S283>/Unit Delay' */
  boolean UnitDelay_DSTATE_pcv;        /* '<S272>/Unit Delay' */
  boolean UnitDelay_DSTATE_el;         /* '<S271>/Unit Delay' */
  boolean UnitDelay_DSTATE_ka;         /* '<S270>/Unit Delay' */
  boolean UnitDelay_DSTATE_jyd;        /* '<S269>/Unit Delay' */
  boolean UnitDelay_DSTATE_mvx;        /* '<S248>/Unit Delay' */
  boolean UnitDelay_DSTATE_ofi;        /* '<S227>/Unit Delay' */
  boolean UnitDelay_DSTATE_gg;         /* '<S225>/Unit Delay' */
  boolean UnitDelay_DSTATE_b3;         /* '<S209>/Unit Delay' */
  boolean UnitDelay_DSTATE_g2;         /* '<S207>/Unit Delay' */
  boolean UnitDelay_DSTATE_ieu;        /* '<S205>/Unit Delay' */
  boolean UnitDelay_DSTATE_a2;         /* '<S204>/Unit Delay' */
  boolean UnitDelay_DSTATE_lx;         /* '<S203>/Unit Delay' */
  boolean UnitDelay_DSTATE_fx;         /* '<S202>/Unit Delay' */
  boolean UnitDelay_DSTATE_a50;        /* '<S201>/Unit Delay' */
  boolean UnitDelay_DSTATE_dj;         /* '<S197>/Unit Delay' */
  boolean UnitDelay_DSTATE_ls;         /* '<S196>/Unit Delay' */
  boolean UnitDelay_DSTATE_pk;         /* '<S193>/Unit Delay' */
  boolean UnitDelay_DSTATE_cn;         /* '<S189>/Unit Delay' */
  boolean UnitDelay_DSTATE_aj;         /* '<S171>/Unit Delay' */
  boolean UnitDelay_DSTATE_f1x;        /* '<S159>/Unit Delay' */
  boolean UnitDelay_DSTATE_lku;        /* '<S151>/Unit Delay' */
  boolean UnitDelay_DSTATE_fy;         /* '<S127>/Unit Delay' */
  boolean UnitDelay_DSTATE_mo;         /* '<S126>/Unit Delay' */
  boolean UnitDelay_DSTATE_kzl;        /* '<S108>/Unit Delay' */
  boolean UnitDelay_DSTATE_lg3;        /* '<S103>/Unit Delay' */
  boolean UnitDelay_DSTATE_ja;         /* '<S101>/Unit Delay' */
  boolean UnitDelay_DSTATE_bf;         /* '<S99>/Unit Delay' */
  boolean UnitDelay_DSTATE_ig;         /* '<S97>/Unit Delay' */
  boolean UnitDelay_DSTATE_ii;         /* '<S95>/Unit Delay' */
  boolean UnitDelay_DSTATE_do;         /* '<S93>/Unit Delay' */
  boolean UnitDelay_DSTATE_h2u;        /* '<S88>/Unit Delay' */
  boolean UnitDelay_DSTATE_ch;         /* '<S87>/Unit Delay' */
  boolean UnitDelay_DSTATE_g3l;        /* '<S86>/Unit Delay' */
  boolean UnitDelay_DSTATE_a2i;        /* '<S71>/Unit Delay' */
  boolean UnitDelay_DSTATE_et;         /* '<S70>/Unit Delay' */
  boolean UnitDelay_DSTATE_bo0;        /* '<S69>/Unit Delay' */
  boolean UnitDelay_DSTATE_aq;         /* '<S58>/Unit Delay' */
  boolean UnitDelay_DSTATE_m2g;        /* '<S54>/Unit Delay' */
} ARID_DEF_AppSwcIpm_T;

/* Imported (extern) states */
extern boolean VBSW_CANComCRCInstFlt_flg[100];/* '<S392>/Data Store Memory' */

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_AppSwcIpm_T AppSwcIpm_ARID_DEF;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S16>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S17>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S18>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S19>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S25>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * Block '<S40>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S41>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S42>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S43>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S44>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S45>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S46>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S47>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S48>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S49>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S50>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S51>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S52>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S54>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S55>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S56>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S57>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S58>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S59>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S62>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S64>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S66>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S67>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S68>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S69>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S70>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S71>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S72>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S73>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S74>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S75>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S77>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S78>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S79>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S80>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S81>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S82>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S86>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S87>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S88>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S89>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S91>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S92>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S93>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S95>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S97>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S99>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S100>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S103>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S109>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S110>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S111>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S117>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S119>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S120>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S126>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S127>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S134>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S135>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S139>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S140>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S141>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S144>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S148>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S149>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S151>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S154>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S155>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S159>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S160>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S162>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S165>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S169>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S170>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S171>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S172>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S178>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S179>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S188>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S189>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S191>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S192>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S193>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S195>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S196>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S197>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S198>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S201>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S202>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S203>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S204>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S205>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S206>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S207>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S208>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S209>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S210>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S213>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S214>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S216>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S217>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S218>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S219>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S220>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S221>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S222>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S223>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S224>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S225>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S226>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S227>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S228>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S229>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S244>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S245>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S246>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S247>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S248>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S249>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S252>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S253>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S255>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S259>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S260>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S263>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S269>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S270>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S271>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S272>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S276>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S277>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S278>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S279>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S280>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S281>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S283>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S287>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S288>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S289>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S290>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S291>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S292>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S294>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S295>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S296>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S297>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S298>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S299>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S300>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S301>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S314>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S315>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S316>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S317>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S318>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S319>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S321>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S322>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S324>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S325>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S326>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S327>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S332>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S334>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S335>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S336>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S337>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S338>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S344>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S345>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S346>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S347>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S359>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S360>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S361>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S362>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S363>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S364>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S365>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S366>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S367>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S368>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S369>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S370>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S371>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S372>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S373>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S374>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S375>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S376>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S377>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S378>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S379>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S381>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S382>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S383>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S384>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S385>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S386>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S387>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S388>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S390>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S391>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion14' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion15' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion16' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S392>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S8>/Constant8' : Unused code path elimination
 * Block '<S25>/Unit Delay' : Unused code path elimination
 * Block '<S117>/Unit Delay' : Unused code path elimination
 * Block '<S118>/Unit Delay' : Unused code path elimination
 * Block '<S119>/Unit Delay' : Unused code path elimination
 * Block '<S120>/Unit Delay' : Unused code path elimination
 * Block '<S133>/Unit Delay' : Unused code path elimination
 * Block '<S134>/Unit Delay' : Unused code path elimination
 * Block '<S135>/Unit Delay' : Unused code path elimination
 * Block '<S154>/Unit Delay' : Unused code path elimination
 * Block '<S155>/Unit Delay' : Unused code path elimination
 * Block '<S158>/Unit Delay' : Unused code path elimination
 * Block '<S160>/Unit Delay' : Unused code path elimination
 * Block '<S161>/Unit Delay' : Unused code path elimination
 * Block '<S162>/Unit Delay' : Unused code path elimination
 * Block '<S163>/Unit Delay' : Unused code path elimination
 * Block '<S164>/Unit Delay' : Unused code path elimination
 * Block '<S169>/Unit Delay' : Unused code path elimination
 * Block '<S170>/Unit Delay' : Unused code path elimination
 * Block '<S172>/Unit Delay' : Unused code path elimination
 * Block '<S173>/Unit Delay' : Unused code path elimination
 * Block '<S213>/Unit Delay' : Unused code path elimination
 * Block '<S214>/Unit Delay' : Unused code path elimination
 * Block '<S215>/Unit Delay' : Unused code path elimination
 * Block '<S221>/Unit Delay' : Unused code path elimination
 * Block '<S222>/Unit Delay' : Unused code path elimination
 * Block '<S223>/Unit Delay' : Unused code path elimination
 * Block '<S224>/Unit Delay' : Unused code path elimination
 * Block '<S226>/Unit Delay' : Unused code path elimination
 * Block '<S228>/Unit Delay' : Unused code path elimination
 * Block '<S229>/Unit Delay' : Unused code path elimination
 * Block '<S252>/Unit Delay' : Unused code path elimination
 * Block '<S253>/Unit Delay' : Unused code path elimination
 * Block '<S254>/Unit Delay' : Unused code path elimination
 * Block '<S255>/Unit Delay' : Unused code path elimination
 * Block '<S259>/Unit Delay' : Unused code path elimination
 * Block '<S260>/Unit Delay' : Unused code path elimination
 * Block '<S282>/Unit Delay' : Unused code path elimination
 * Block '<S284>/Unit Delay' : Unused code path elimination
 * Block '<S285>/Unit Delay' : Unused code path elimination
 * Block '<S286>/Unit Delay' : Unused code path elimination
 * Block '<S313>/Unit Delay' : Unused code path elimination
 * Block '<S315>/Unit Delay' : Unused code path elimination
 * Block '<S320>/Unit Delay' : Unused code path elimination
 * Block '<S333>/Unit Delay' : Unused code path elimination
 * Block '<S334>/Unit Delay' : Unused code path elimination
 * Block '<S335>/Unit Delay' : Unused code path elimination
 * Block '<S336>/Unit Delay' : Unused code path elimination
 * Block '<S337>/Unit Delay' : Unused code path elimination
 * Block '<S338>/Unit Delay' : Unused code path elimination
 * Block '<S344>/Unit Delay' : Unused code path elimination
 * Block '<S345>/Unit Delay' : Unused code path elimination
 * Block '<S346>/Unit Delay' : Unused code path elimination
 * Block '<S347>/Unit Delay' : Unused code path elimination
 * Block '<S352>/Unit Delay' : Unused code path elimination
 * Block '<S353>/Unit Delay' : Unused code path elimination
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
 * '<S7>'   : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms'
 * '<S8>'   : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms'
 * '<S9>'   : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms'
 * '<S10>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms'
 * '<S11>'  : 'AppSwcIpm/Ipm100ms/ChaCAN_IN_100ms'
 * '<S12>'  : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms'
 * '<S13>'  : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms'
 * '<S14>'  : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms'
 * '<S15>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC'
 * '<S16>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeDay_nu'
 * '<S17>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeHour_nu'
 * '<S18>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeMin_nu'
 * '<S19>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeMonth_nu'
 * '<S20>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeSec_nu'
 * '<S21>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/Subsys_VIPM_TBOXBJSTimeYear_nu'
 * '<S22>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_1000ms/Msg_TBOX_BJS_Time_BAC/rescale_in'
 * '<S23>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_BMS_9_BattInfo_EPT'
 * '<S24>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC'
 * '<S25>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_ICUTotOdo_km'
 * '<S26>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_BMS_9_BattInfo_EPT/rescale_in'
 * '<S27>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_CDCBackLadjval_enum'
 * '<S28>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUACAutoCtl_enum'
 * '<S29>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUACPwrCtl_enum'
 * '<S30>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUACUnlckVentSet_enum'
 * '<S31>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUAirInletModeSet_enum'
 * '<S32>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUBCMCargoLghtSet_enum'
 * '<S33>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUBCMOTAModeSet_enum'
 * '<S34>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUBlwrModeSet_enum'
 * '<S35>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChgWiprMtMdSwSet_enum'
 * '<S36>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChrgngReq_enum'
 * '<S37>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChrgngmode_enum'
 * '<S38>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUCstRecupModeSel_enum'
 * '<S39>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUDrvModeSel_enum'
 * '<S40>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUDrvPwrSet_cnt'
 * '<S41>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUFlwrMeHmCtrl_enum'
 * '<S42>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUFrntFanSpdSet_enum'
 * '<S43>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUHybEcoModeSet_enum'
 * '<S44>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndEntrySts_enum'
 * '<S45>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndLckSts_enum'
 * '<S46>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndUnlckSts_enum'
 * '<S47>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HULckHornOnSt_enum'
 * '<S48>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HULeftTempSet_enum'
 * '<S49>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUMaiDrvrSeatHeat_enum'
 * '<S50>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUManlDefrstCtl_enum'
 * '<S51>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUOvrspdCntrlLckSet_enum'
 * '<S52>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUParkAutoUnlckSet_enum'
 * '<S53>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUPeristalsisModeEnbl_enum'
 * '<S54>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUPwrOffReq_flg'
 * '<S55>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HURecupPwrSet_pct'
 * '<S56>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HURrMirrHeat_enum'
 * '<S57>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUSteerWhlHeat_enum'
 * '<S58>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUTPMSRstReq_flg'
 * '<S59>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUTrnkLckSwCtrl_enum'
 * '<S60>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUVehMaxCurr_A'
 * '<S61>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUWiprIntlTmSet_enum'
 * '<S62>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXACRemtCtrlFlg_enum'
 * '<S63>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXACTempSet_enum'
 * '<S64>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXRemtMaiDrSeatHeatReq_enum'
 * '<S65>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXRemtPwrCtrlReq_enum'
 * '<S66>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXRemtStrWhlHeatReq_enum'
 * '<S67>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXRmtPwrLck_enum'
 * '<S68>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUCCMSpdLimLvl_enum'
 * '<S69>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUChrgngConds_flg'
 * '<S70>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUOprtLic_flg'
 * '<S71>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUVer_flg'
 * '<S72>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBoxOpenVentn_enum'
 * '<S73>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBoxRmtCarSearch_enum'
 * '<S74>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBoxRmtLck_enum'
 * '<S75>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TboxRmtDefrstCtl_enum'
 * '<S76>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD'
 * '<S77>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_APPVerMax_enum'
 * '<S78>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_APPVerMin_enum'
 * '<S79>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_BootVer_enum'
 * '<S80>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_ClientNum_enum'
 * '<S81>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_HwVerMax_enum'
 * '<S82>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_1000ms/Msg_ACCM_Version_BOD/Subsys_VIPM_HwVerMin_enum'
 * '<S83>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD'
 * '<S84>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD'
 * '<S85>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD'
 * '<S86>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPCANBusOff_flg'
 * '<S87>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPCommuError_flg'
 * '<S88>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPCurrOfst_flg'
 * '<S89>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPEcompActSpd_rpm'
 * '<S90>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPEcompST_enum'
 * '<S91>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPHiVolt_V'
 * '<S92>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPHvErr_enum'
 * '<S93>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPIPMErr_flg'
 * '<S94>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPInCurr_A'
 * '<S95>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPLoseStep_flg'
 * '<S96>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPLvErr_enum'
 * '<S97>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPOverDuty_flg'
 * '<S98>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPOvrCurr_enum'
 * '<S99>'  : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPPISaturation_flg'
 * '<S100>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPSelfChkErr_enum'
 * '<S101>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPTempErr_flg'
 * '<S102>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_COMPTemp_C'
 * '<S103>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/Subsys_VIPM_ECUHiVoltInterlockSig_flg'
 * '<S104>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in'
 * '<S105>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in1'
 * '<S106>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in2'
 * '<S107>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_COMP_AC_BOD/rescale_in3'
 * '<S108>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHHVSt_flg'
 * '<S109>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHInletTemp_C'
 * '<S110>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHOutlTemp_C'
 * '<S111>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHPCBTemp_C'
 * '<S112>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHSt_enum'
 * '<S113>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/Subsys_VIPM_HVCHWorkMode_enum'
 * '<S114>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/rescale_in'
 * '<S115>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/rescale_in1'
 * '<S116>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status1_BOD/rescale_in2'
 * '<S117>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHCurr_A'
 * '<S118>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHFltCod_enum'
 * '<S119>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHHVVolts_V'
 * '<S120>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHPwr_kW'
 * '<S121>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/Subsys_VIPM_HVCHWorkSt_enum'
 * '<S122>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/rescale_in'
 * '<S123>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/rescale_in1'
 * '<S124>' : 'AppSwcIpm/Ipm100ms/BodCAN_IN_100ms/Msg_HVCH_Status2_BOD/rescale_in2'
 * '<S125>' : 'AppSwcIpm/Ipm100ms/ChaCAN_IN_100ms/Msg_FCM_A_CHA'
 * '<S126>' : 'AppSwcIpm/Ipm100ms/ChaCAN_IN_100ms/Msg_FCM_A_CHA/Subsys_VIPM_FCMHMAHiBeamReq_flg'
 * '<S127>' : 'AppSwcIpm/Ipm100ms/ChaCAN_IN_100ms/Msg_FCM_A_CHA/Subsys_VIPM_FCMHMASetFb_flg'
 * '<S128>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT'
 * '<S129>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT'
 * '<S130>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT'
 * '<S131>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT'
 * '<S132>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT'
 * '<S133>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempAve_C'
 * '<S134>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempMax_C'
 * '<S135>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempMin_C'
 * '<S136>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in'
 * '<S137>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in1'
 * '<S138>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in2'
 * '<S139>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData02_nu'
 * '<S140>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData03_nu'
 * '<S141>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData04_nu'
 * '<S142>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData05_nu'
 * '<S143>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData06_nu'
 * '<S144>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData07_nu'
 * '<S145>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngSts_enum'
 * '<S146>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngSubID_cnt'
 * '<S147>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCActOprtMode_enum'
 * '<S148>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCLoVoltActCurnt_A'
 * '<S149>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCLoVoltActVolt_V'
 * '<S150>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCSysFailSta_enum'
 * '<S151>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUHVILFailSt_flg'
 * '<S152>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/rescale_in'
 * '<S153>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/rescale_in1'
 * '<S154>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/Subsys_VIPM_IPUDCCHiVoltActCurnt_A'
 * '<S155>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/Subsys_VIPM_IPUDCCHiVoltActVolt_V'
 * '<S156>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/rescale_in'
 * '<S157>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/rescale_in1'
 * '<S158>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCActOprtMode_enum'
 * '<S159>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCConnectMainSta_flg'
 * '<S160>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCHVDCActCur_A'
 * '<S161>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCHVDCActVol_V'
 * '<S162>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCInletActPwr_kW'
 * '<S163>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCInletConnectSta_enum'
 * '<S164>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCReq_enum'
 * '<S165>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCSysFailSta_enum'
 * '<S166>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/rescale_in'
 * '<S167>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/rescale_in1'
 * '<S168>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT'
 * '<S169>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUDeviceIntTemp_C'
 * '<S170>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW'
 * '<S171>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCS2State_flg'
 * '<S172>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCTempInt_C'
 * '<S173>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCWakeUpMode_enum'
 * '<S174>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in'
 * '<S175>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in1'
 * '<S176>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in2'
 * '<S177>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT'
 * '<S178>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_BMSBatCapcty_Ah'
 * '<S179>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_BMSPackID_enum'
 * '<S180>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms'
 * '<S181>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms'
 * '<S182>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA'
 * '<S183>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA'
 * '<S184>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA'
 * '<S185>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA'
 * '<S186>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPedlValPerc_pct'
 * '<S187>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum'
 * '<S188>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm'
 * '<S189>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBCDDActv_flg'
 * '<S190>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBEPBActuatorStR_enum'
 * '<S191>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBEPBDynAppSt_enum'
 * '<S192>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBFltLvl_enum'
 * '<S193>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBReqBrkLiOn_flg'
 * '<S194>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/rescale_in'
 * '<S195>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSRotSpd_degps'
 * '<S196>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAngCald_flg'
 * '<S197>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAngFailr_flg'
 * '<S198>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAng_deg'
 * '<S199>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/rescale_in'
 * '<S200>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/rescale_in1'
 * '<S201>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCABSActvSta_flg'
 * '<S202>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCCDPActv_flg'
 * '<S203>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCEBDActv_flg'
 * '<S204>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCESPActvSta_flg'
 * '<S205>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCESSActv_flg'
 * '<S206>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCFltLvl_enum'
 * '<S207>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCReqBrkLghtOn_flg'
 * '<S208>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCSlopPct_pct'
 * '<S209>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCTCSActvSta_flg'
 * '<S210>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCVehSpd_kph'
 * '<S211>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/rescale_in'
 * '<S212>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/rescale_in1'
 * '<S213>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCLatAccSnsrVal_g'
 * '<S214>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCLongAccSnsrVal_g'
 * '<S215>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCMstrCylPresr_bar'
 * '<S216>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCVehStandStillSta_enum'
 * '<S217>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnFL_enum'
 * '<S218>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnFR_enum'
 * '<S219>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnRL_enum'
 * '<S220>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnRR_enum'
 * '<S221>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphFL_kph'
 * '<S222>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphFR_kph'
 * '<S223>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphRL_kph'
 * '<S224>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphRR_kph'
 * '<S225>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqDecReqActv_flg'
 * '<S226>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqDecReqVal_Nm'
 * '<S227>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqIncReqActv_flg'
 * '<S228>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqIncReqVal_Nm'
 * '<S229>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCYawRate_degps'
 * '<S230>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in'
 * '<S231>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in1'
 * '<S232>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in2'
 * '<S233>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in3'
 * '<S234>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in4'
 * '<S235>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in5'
 * '<S236>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in6'
 * '<S237>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in7'
 * '<S238>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in8'
 * '<S239>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT'
 * '<S240>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT'
 * '<S241>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT'
 * '<S242>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_4_Value_EPT'
 * '<S243>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ActMode_enum'
 * '<S244>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ActTorq_Nm'
 * '<S245>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1AntithftAuthRslt_enum'
 * '<S246>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1MotSpd_rpm'
 * '<S247>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1PreChrgAllwd_enum'
 * '<S248>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1PreprogmFlg_flg'
 * '<S249>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ShutdownAllwd_enum'
 * '<S250>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/rescale_in'
 * '<S251>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/rescale_in1'
 * '<S252>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2IgbtMaxTemp_C'
 * '<S253>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2InpCurnt_A'
 * '<S254>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2InpVolt_V'
 * '<S255>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2MotorMaxTemp_C'
 * '<S256>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in'
 * '<S257>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in1'
 * '<S258>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in2'
 * '<S259>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/Subsys_VIPM_INV3DrvTqAllwdMax_Nm'
 * '<S260>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/Subsys_VIPM_INV3RecupTqAllwdMax_Nm'
 * '<S261>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/rescale_in'
 * '<S262>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/rescale_in1'
 * '<S263>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_4_Value_EPT/Subsys_VIPM_INV4FltLvl_enum'
 * '<S264>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms'
 * '<S265>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms'
 * '<S266>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms'
 * '<S267>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD'
 * '<S268>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSGrShftLvrPstnReq_enum'
 * '<S269>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght11Sw_flg'
 * '<S270>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght12Sw_flg'
 * '<S271>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght13Sw_flg'
 * '<S272>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRghtSwVldty_flg'
 * '<S273>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA'
 * '<S274>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA'
 * '<S275>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA'
 * '<S276>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRBSDWarnLt_enum'
 * '<S277>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRBSDWarnRt_enum'
 * '<S278>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRDOWWarnLt_enum'
 * '<S279>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRDOWWarnRt_enum'
 * '<S280>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRRCTAWarnLt_enum'
 * '<S281>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRRCTAWarnRt_enum'
 * '<S282>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBAVHAppldSt_enum'
 * '<S283>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBBLA_flg'
 * '<S284>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBActuatorStL_enum'
 * '<S285>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBSwitchSts_enum'
 * '<S286>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBSysSt_enum'
 * '<S287>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBHDCFucFault_flg'
 * '<S288>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCSdnMode_enum'
 * '<S289>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlDece_mps2'
 * '<S290>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlTqReqActv_flg'
 * '<S291>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlTqReqVal_Nm'
 * '<S292>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAEBReq_flg'
 * '<S293>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccMode_enum'
 * '<S294>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccReqDriveOff_flg'
 * '<S295>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccReqStandstill_flg'
 * '<S296>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTarAccrnReqActv_flg'
 * '<S297>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTarAccrn_mps2'
 * '<S298>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTgtAxReq_flg'
 * '<S299>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTgtAx_mps2'
 * '<S300>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMEPBReq_enum'
 * '<S301>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMTrnLampReq_enum'
 * '<S302>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in'
 * '<S303>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in1'
 * '<S304>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in2'
 * '<S305>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in3'
 * '<S306>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT'
 * '<S307>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT'
 * '<S308>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT'
 * '<S309>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_3_DC_ChargeState_EPT'
 * '<S310>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT'
 * '<S311>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT'
 * '<S312>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT'
 * '<S313>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT/Subsys_VIPM_BMSDCSActOprtMode_enum'
 * '<S314>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT/Subsys_VIPM_BMSDCSInletConnectSta_flg'
 * '<S315>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSActExchgCurnt_A'
 * '<S316>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSChrgInterlockSta_enum'
 * '<S317>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSDchrgInterlockSta_enum'
 * '<S318>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSEmgcySdnReq_flg'
 * '<S319>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSPwrTrainConnectSta_enum'
 * '<S320>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSRunSta_enum'
 * '<S321>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSSysFailSta_enum'
 * '<S322>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSThermrunawayWrn_enum'
 * '<S323>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/rescale_in'
 * '<S324>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOCAct_pct'
 * '<S325>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOCRpt_pct'
 * '<S326>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOH_pct'
 * '<S327>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSHVBatActVolt_V'
 * '<S328>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in'
 * '<S329>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in1'
 * '<S330>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in2'
 * '<S331>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in3'
 * '<S332>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_3_DC_ChargeState_EPT/Subsys_VIPM_BMSDCSChrgReq_flg'
 * '<S333>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSACChrgAtclSta_enum'
 * '<S334>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSInletCooltActlTemp_C'
 * '<S335>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSIsoResist_MOhm'
 * '<S336>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSMaxChrgCurntAC_A'
 * '<S337>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSMaxChrgVoltAC_V'
 * '<S338>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSOutlCooltActlTemp_C'
 * '<S339>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in'
 * '<S340>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in1'
 * '<S341>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in2'
 * '<S342>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in3'
 * '<S343>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in4'
 * '<S344>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxConChrgCurnt_A'
 * '<S345>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxConDisCurnt_A'
 * '<S346>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxInsChrgCurnt_A'
 * '<S347>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxInsDisCurnt_A'
 * '<S348>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in'
 * '<S349>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in1'
 * '<S350>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in2'
 * '<S351>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in3'
 * '<S352>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT/Subsys_VIPM_BMSCellVoltMax_mV'
 * '<S353>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT/Subsys_VIPM_BMSCellVoltMin_mV'
 * '<S354>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms'
 * '<S355>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms'
 * '<S356>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD'
 * '<S357>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_ESCL_ESCLStatus_BOD'
 * '<S358>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD'
 * '<S359>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPACAutoKey_flg'
 * '<S360>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPACSwKey_flg'
 * '<S361>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAVASOffKey_flg'
 * '<S362>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAVHKey_flg'
 * '<S363>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAirInletModeKey_flg'
 * '<S364>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwngModeNextKey_flg'
 * '<S365>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwngModePrevKey_flg'
 * '<S366>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwrLvlAddKey_flg'
 * '<S367>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwrLvlDecKey_flg'
 * '<S368>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPCenLckKey_flg'
 * '<S369>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPESCOffKey_flg'
 * '<S370>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPFrntWindDefrstKey_flg'
 * '<S371>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPHDCKey_flg'
 * '<S372>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPHzrdKey_flg'
 * '<S373>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPModeKey_flg'
 * '<S374>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPPwrRecupLvlKey_flg'
 * '<S375>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg'
 * '<S376>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTPMSKey_flg'
 * '<S377>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTempAddKey_flg'
 * '<S378>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTempDecKey_flg'
 * '<S379>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_ESCL_ESCLStatus_BOD/Subsys_VIPM_ESCLUnOrLockfeedback_nu'
 * '<S380>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSFrntWiprSwtSt_enum'
 * '<S381>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSFrntWshrSwtSt_flg'
 * '<S382>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSHiBeamSwSt_flg'
 * '<S383>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLampAutoSt_flg'
 * '<S384>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLeTrnLmpSwSt_flg'
 * '<S385>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLoBeamSwSt_flg'
 * '<S386>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSOvrVehBeamSwSt_flg'
 * '<S387>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSPstnLghtSwSt_flg'
 * '<S388>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSRiTrnLmpSwSt_flg'
 * '<S389>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA'
 * '<S390>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA/Subsys_VIPM_SRSCrashOutputSts_enum'
 * '<S391>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA/Subsys_VIPM_SRSDrvSeatbeltBkld_flg'
 * '<S392>' : 'AppSwcIpm/IpmMsgActv/CANCommCRCFlt'
 * '<S393>' : 'AppSwcIpm/IpmMsgActv/CANCommError'
 * '<S394>' : 'AppSwcIpm/IpmMsgActv/MsgActv'
 * '<S395>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay'
 * '<S396>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay1'
 * '<S397>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay2'
 * '<S398>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay3'
 * '<S399>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay/Chart'
 * '<S400>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay1/Chart'
 * '<S401>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay2/Chart'
 * '<S402>' : 'AppSwcIpm/IpmMsgActv/CANCommError/Turn_Off_Delay3/Chart'
 */
#endif                                 /* RTW_HEADER_AppSwcIpm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
