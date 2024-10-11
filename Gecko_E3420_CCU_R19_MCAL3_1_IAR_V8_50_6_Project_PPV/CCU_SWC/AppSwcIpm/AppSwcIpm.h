/*
 * File: AppSwcIpm.h
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.209
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Sep 24 13:50:26 2024
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

/* PublicStructure Variables for Internal Data, for system '<Root>' */
typedef struct {
  DT_IPM_ESC_A_CHA ESC_A_CHA_f;        /* '<S173>/BusCreator' */
  DT_IPM_HU_B_BAC IPM_HU_B_BAC_m;      /* '<S71>/BusCreator' */
  DT_IPM_COMP_AC_BOD IPM_COMP_AC_BOD;  /* '<S21>/BusCreator' */
  DT_IPM_FCM_B_CHA IPM_FCM_B_CHA;      /* '<S263>/BusCreator' */
  DT_IPM_BMS_4_AC_ChargeState_EPT IPM_BMS_4_AC_ChargeState_EPT;/* '<S298>/BusCreator' */
  DT_IPM_CCP_PanelStatus_BOD IPM_CCP_PanelStatus_BOD_k;/* '<S344>/BusCreator' */
  DT_IPM_IPU_OBC_1_State_EPT IPM_IPU_OBC_1_State_EPT;/* '<S120>/BusCreator' */
  DT_IPM_BMS_2_BatState_EPT IPM_BMS_2_BatState_EPT;/* '<S296>/BusCreator' */
  DT_IPM_BMS_6_DischrgRecup_EPT IPM_BMS_6_DischrgRecup_EPT;/* '<S299>/BusCreator' */
  DT_IPM_EHB_B_CHA EHB_B_CHA_l;        /* '<S170>/BusCreator' */
  DT_IPM_ESC_7_FuncStatus_CHA ESC_7_FuncStatus_CHA_a;/* '<S172>/BusCreator' */
  DT_IPM_HVCH_Status1_BOD IPM_HVCH_Status1_BOD;/* '<S22>/BusCreator' */
  DT_IPM_HVCH_Status2_BOD IPM_HVCH_Status2_BOD;/* '<S23>/BusCreator' */
  DT_IPM_INV_2_Value_EPT IPM_INV_2_Value_EPT;/* '<S228>/BusCreator' */
  DT_IPM_IPU_OBC_2_Inlet_EPT IPM_IPU_OBC_2_Inlet_EPT;/* '<S156>/BusCreator' */
  DT_IPM_BMS_1_MainState_EPT BusCreator;/* '<S295>/BusCreator' */
  DT_IPM_BMS_5_BatTemp_EPT IPM_BMS_5_BatTemp_EPT;/* '<S116>/BusCreator' */
  DT_IPM_EPS_2_StrWhlAng_CHA IPM_EPS_2_StrWhlAng_CHA;/* '<S171>/BusCreator' */
  DT_IPM_INV_1_Value_EPT IPM_INV_1_Value_EPT;/* '<S227>/BusCreator' */
  DT_IPM_IPU_DCC_1_State_EPT IPM_IPU_DCC_1_State_EPT;/* '<S118>/BusCreator' */
  DT_IPM_SCS_LeSwitchSts_BOD IPM_SCS_LeSwitchSts_BOD;/* '<S346>/BusCreator' */
  DT_MsgActv MsgActv_outputs;          /* '<S6>/BusCreator' */
  DT_IPM_ACCM_Version_BOD IPM_ACCM_Version_BOD;/* '<S14>/BusCreator' */
  DT_IPM_BMS_7_CellVolt_EPT IPM_BMS_7_CellVolt_EPT;/* '<S300>/BusCreator' */
  DT_IPM_CRRR_A_CHA IPM_CRRR_A_CHA;    /* '<S261>/BusCreator' */
  DT_IPM_EHB_A_CHA IPM_EHB_A_CHA;      /* '<S262>/BusCreator' */
  DT_IPM_ESCL_ESCLStatus_BOD IPM_ESCL_ESCLStatus_BOD;/* '<S345>/BusCreator' */
  DT_IPM_INV_3_Value_EPT IPM_INV_3_Value_EPT;/* '<S229>/BusCreator' */
  DT_IPM_INV_IMMO_Req_EPT IPM_INV_IMMO_Req_EPT_g;/* '<S117>/BusCreator' */
  DT_IPM_IPU_DCC_2_ChrgInValue_EPT IPM_IPU_DCC_2_ChrgInValue_EPT;/* '<S119>/BusCreator' */
  DT_IPM_SCS_RiSwitchSts_BOD IPM_SCS_RiSwitchSts_BOD;/* '<S255>/BusCreator1' */
  DT_IPM_TBOX_BJS_Time_BAC IPM_TBOX_BJS_Time_BAC;/* '<S63>/BusCreator' */
  DT_IPM_BMS_10_DC_ChargeStates_EPT IPM_BMS_10_DC_ChargeStates_EPT;/* '<S294>/BusCreator' */
  DT_IPM_BMS_3_DC_ChargeState_EPT IPM_BMS_3_DC_ChargeState_EPT;/* '<S297>/BusCreator' */
  DT_IPM_BMS_9_BattInfo_EPT IPM_BMS_9_BattInfo_EPT;/* '<S165>/BusCreator' */
  DT_IPM_INV_4_Value_EPT IPM_INV_4_Value_EPT;/* '<S230>/BusCreator' */
  DT_IPM_SRS_1_Status_CHA IPM_SRS_1_Status_CHA;/* '<S377>/BusCreator' */
  uint64 UnitDelay_DSTATE;             /* '<S367>/Unit Delay' */
  float32 UnitDelay_DSTATE_l;          /* '<S315>/Unit Delay' */
  float32 UnitDelay_DSTATE_d;          /* '<S314>/Unit Delay' */
  float32 UnitDelay_DSTATE_c;          /* '<S313>/Unit Delay' */
  float32 UnitDelay_DSTATE_n;          /* '<S312>/Unit Delay' */
  float32 UnitDelay_DSTATE_e;          /* '<S287>/Unit Delay' */
  float32 UnitDelay_DSTATE_j;          /* '<S285>/Unit Delay' */
  float32 UnitDelay_DSTATE_f;          /* '<S279>/Unit Delay' */
  float32 UnitDelay_DSTATE_o;          /* '<S277>/Unit Delay' */
  float32 UnitDelay_DSTATE_jy;         /* '<S234>/Unit Delay' */
  float32 UnitDelay_DSTATE_k;          /* '<S232>/Unit Delay' */
  float32 UnitDelay_DSTATE_dc;         /* '<S198>/Unit Delay' */
  float32 UnitDelay_DSTATE_ev;         /* '<S196>/Unit Delay' */
  float32 UnitDelay_DSTATE_a;          /* '<S186>/Unit Delay' */
  float32 UnitDelay_DSTATE_au;         /* '<S183>/Unit Delay' */
  float32 UnitDelay_DSTATE_eu;         /* '<S176>/Unit Delay' */
  float32 UnitDelay_DSTATE_jg;         /* '<S174>/Unit Delay' */
  float32 UnitDelay_DSTATE_ow;         /* '<S137>/Unit Delay' */
  float32 UnitDelay_DSTATE_p;          /* '<S136>/Unit Delay' */
  float32 UnitDelay_DSTATE_e1;         /* '<S49>/Unit Delay' */
  float32 UnitDelay_DSTATE_py;         /* '<S48>/Unit Delay' */
  float32 UnitDelay_DSTATE_lk;         /* '<S47>/Unit Delay' */
  float32 UnitDelay_DSTATE_lq;         /* '<S40>/Unit Delay' */
  float32 UnitDelay_DSTATE_h;          /* '<S32>/Unit Delay' */
  float32 UnitDelay_DSTATE_kc;         /* '<S29>/Unit Delay' */
  float32 UnitDelay_DSTATE_hz;         /* '<S27>/Unit Delay' */
  uint16 UnitDelay_DSTATE_g;           /* '<S69>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fi;           /* '<S378>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nh;           /* '<S368>/Unit Delay' */
  uint8 UnitDelay_DSTATE_dg;           /* '<S310>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jh;           /* '<S309>/Unit Delay' */
  uint8 UnitDelay_DSTATE_b;            /* '<S307>/Unit Delay' */
  uint8 UnitDelay_DSTATE_of;           /* '<S305>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gr;           /* '<S304>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jk;           /* '<S289>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pi;           /* '<S288>/Unit Delay' */
  uint8 UnitDelay_DSTATE_k3;           /* '<S276>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m;            /* '<S269>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hf;           /* '<S268>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hg;           /* '<S267>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ms;           /* '<S266>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ki;           /* '<S265>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ows;          /* '<S264>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ga;           /* '<S251>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nu;           /* '<S237>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gn;           /* '<S235>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jq;           /* '<S233>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lj;           /* '<S208>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ff;           /* '<S207>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nj;           /* '<S206>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jc;           /* '<S205>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hi;           /* '<S204>/Unit Delay' */
  uint8 UnitDelay_DSTATE_kv;           /* '<S194>/Unit Delay' */
  uint8 UnitDelay_DSTATE_da;           /* '<S180>/Unit Delay' */
  uint8 UnitDelay_DSTATE_i;            /* '<S179>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jhg;          /* '<S167>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ol;           /* '<S166>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mu;           /* '<S153>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ph;           /* '<S138>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nf;           /* '<S134>/Unit Delay' */
  uint8 UnitDelay_DSTATE_i5;           /* '<S133>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lg;           /* '<S132>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pc;           /* '<S131>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hl;           /* '<S130>/Unit Delay' */
  uint8 UnitDelay_DSTATE_euu;          /* '<S129>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ec;           /* '<S128>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ju;           /* '<S127>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mn;           /* '<S115>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c5;           /* '<S114>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c3;           /* '<S113>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ps;           /* '<S112>/Unit Delay' */
  uint8 UnitDelay_DSTATE_as;           /* '<S108>/Unit Delay' */
  uint8 UnitDelay_DSTATE_js;           /* '<S107>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nuf;          /* '<S106>/Unit Delay' */
  uint8 UnitDelay_DSTATE_np;           /* '<S105>/Unit Delay' */
  uint8 UnitDelay_DSTATE_a1;           /* '<S104>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ks;           /* '<S103>/Unit Delay' */
  uint8 UnitDelay_DSTATE_a5;           /* '<S102>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mj;           /* '<S100>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fiu;          /* '<S99>/Unit Delay' */
  uint8 UnitDelay_DSTATE_dk;           /* '<S98>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fq;           /* '<S95>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hig;          /* '<S94>/Unit Delay' */
  uint8 UnitDelay_DSTATE_kz;           /* '<S93>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h0;           /* '<S92>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lz;           /* '<S91>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fc;           /* '<S90>/Unit Delay' */
  uint8 UnitDelay_DSTATE_nfb;          /* '<S89>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jks;          /* '<S88>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ad;           /* '<S87>/Unit Delay' */
  uint8 UnitDelay_DSTATE_o3;           /* '<S86>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ap;           /* '<S85>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hv;           /* '<S84>/Unit Delay' */
  uint8 UnitDelay_DSTATE_bg;           /* '<S83>/Unit Delay' */
  uint8 UnitDelay_DSTATE_mv;           /* '<S80>/Unit Delay' */
  uint8 UnitDelay_DSTATE_cd;           /* '<S79>/Unit Delay' */
  uint8 UnitDelay_DSTATE_gw;           /* '<S78>/Unit Delay' */
  uint8 UnitDelay_DSTATE_fe;           /* '<S77>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jp;           /* '<S76>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jv;           /* '<S75>/Unit Delay' */
  uint8 UnitDelay_DSTATE_m2;           /* '<S74>/Unit Delay' */
  uint8 UnitDelay_DSTATE_px;           /* '<S73>/Unit Delay' */
  uint8 UnitDelay_DSTATE_af;           /* '<S72>/Unit Delay' */
  uint8 UnitDelay_DSTATE_no;           /* '<S68>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ah;           /* '<S67>/Unit Delay' */
  uint8 UnitDelay_DSTATE_jg0;          /* '<S66>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ke;           /* '<S65>/Unit Delay' */
  uint8 UnitDelay_DSTATE_iy;           /* '<S64>/Unit Delay' */
  uint8 UnitDelay_DSTATE_c4;           /* '<S59>/Unit Delay' */
  uint8 UnitDelay_DSTATE_h2;           /* '<S51>/Unit Delay' */
  uint8 UnitDelay_DSTATE_g5;           /* '<S50>/Unit Delay' */
  uint8 UnitDelay_DSTATE_iv;           /* '<S38>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pr;           /* '<S36>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ck;           /* '<S34>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pcn;          /* '<S30>/Unit Delay' */
  uint8 UnitDelay_DSTATE_lo;           /* '<S28>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ha;           /* '<S20>/Unit Delay' */
  uint8 UnitDelay_DSTATE_pyg;          /* '<S19>/Unit Delay' */
  uint8 UnitDelay_DSTATE_hzk;          /* '<S18>/Unit Delay' */
  uint8 UnitDelay_DSTATE_evy;          /* '<S17>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ge;           /* '<S16>/Unit Delay' */
  uint8 UnitDelay_DSTATE_ce;           /* '<S15>/Unit Delay' */
  EnumRegenModeSelct UnitDelay_DSTATE_ca;/* '<S81>/Unit Delay' */
  EnumDrvModeSelct UnitDelay_DSTATE_k0;/* '<S82>/Unit Delay' */
  EnumCrpModeEnbl UnitDelay_DSTATE_dt; /* '<S96>/Unit Delay' */
  EnumDCCActMd UnitDelay_DSTATE_ov;    /* '<S135>/Unit Delay' */
  EnumRegenTgtTqStat UnitDelay_DSTATE_n0;/* '<S175>/Unit Delay' */
  EnumEPBState UnitDelay_DSTATE_cj;    /* '<S178>/Unit Delay' */
  EnumINVActMd UnitDelay_DSTATE_cw;    /* '<S231>/Unit Delay' */
  EnumGrShftLvrPstnReq UnitDelay_DSTATE_n1;/* '<S256>/Unit Delay' */
  EnumACCMode UnitDelay_DSTATE_ecm;    /* '<S281>/Unit Delay' */
  boolean UnitDelay_DSTATE_fl;         /* '<S379>/Unit Delay' */
  boolean UnitDelay_DSTATE_ds;         /* '<S376>/Unit Delay' */
  boolean UnitDelay_DSTATE_ko;         /* '<S375>/Unit Delay' */
  boolean UnitDelay_DSTATE_cds;        /* '<S374>/Unit Delay' */
  boolean UnitDelay_DSTATE_oa;         /* '<S373>/Unit Delay' */
  boolean UnitDelay_DSTATE_du;         /* '<S372>/Unit Delay' */
  boolean UnitDelay_DSTATE_bc;         /* '<S371>/Unit Delay' */
  boolean UnitDelay_DSTATE_dcs;        /* '<S370>/Unit Delay' */
  boolean UnitDelay_DSTATE_f1;         /* '<S369>/Unit Delay' */
  boolean UnitDelay_DSTATE_i5p;        /* '<S366>/Unit Delay' */
  boolean UnitDelay_DSTATE_nz;         /* '<S365>/Unit Delay' */
  boolean UnitDelay_DSTATE_e1e;        /* '<S364>/Unit Delay' */
  boolean UnitDelay_DSTATE_dp;         /* '<S363>/Unit Delay' */
  boolean UnitDelay_DSTATE_b1;         /* '<S362>/Unit Delay' */
  boolean UnitDelay_DSTATE_p1;         /* '<S361>/Unit Delay' */
  boolean UnitDelay_DSTATE_it;         /* '<S360>/Unit Delay' */
  boolean UnitDelay_DSTATE_kd;         /* '<S359>/Unit Delay' */
  boolean UnitDelay_DSTATE_ab;         /* '<S358>/Unit Delay' */
  boolean UnitDelay_DSTATE_phn;        /* '<S357>/Unit Delay' */
  boolean UnitDelay_DSTATE_eo;         /* '<S356>/Unit Delay' */
  boolean UnitDelay_DSTATE_ei;         /* '<S355>/Unit Delay' */
  boolean UnitDelay_DSTATE_ah2;        /* '<S354>/Unit Delay' */
  boolean UnitDelay_DSTATE_ob;         /* '<S353>/Unit Delay' */
  boolean UnitDelay_DSTATE_bd;         /* '<S352>/Unit Delay' */
  boolean UnitDelay_DSTATE_go;         /* '<S351>/Unit Delay' */
  boolean UnitDelay_DSTATE_jb;         /* '<S350>/Unit Delay' */
  boolean UnitDelay_DSTATE_ky;         /* '<S349>/Unit Delay' */
  boolean UnitDelay_DSTATE_pz;         /* '<S348>/Unit Delay' */
  boolean UnitDelay_DSTATE_cr;         /* '<S347>/Unit Delay' */
  boolean UnitDelay_DSTATE_jn;         /* '<S320>/Unit Delay' */
  boolean UnitDelay_DSTATE_nv;         /* '<S306>/Unit Delay' */
  boolean UnitDelay_DSTATE_df;         /* '<S302>/Unit Delay' */
  boolean UnitDelay_DSTATE_cb;         /* '<S286>/Unit Delay' */
  boolean UnitDelay_DSTATE_m2f;        /* '<S284>/Unit Delay' */
  boolean UnitDelay_DSTATE_iv1;        /* '<S283>/Unit Delay' */
  boolean UnitDelay_DSTATE_g3;         /* '<S282>/Unit Delay' */
  boolean UnitDelay_DSTATE_jg0u;       /* '<S280>/Unit Delay' */
  boolean UnitDelay_DSTATE_ep;         /* '<S278>/Unit Delay' */
  boolean UnitDelay_DSTATE_ie;         /* '<S275>/Unit Delay' */
  boolean UnitDelay_DSTATE_mg;         /* '<S271>/Unit Delay' */
  boolean UnitDelay_DSTATE_pcv;        /* '<S260>/Unit Delay' */
  boolean UnitDelay_DSTATE_el;         /* '<S259>/Unit Delay' */
  boolean UnitDelay_DSTATE_ka;         /* '<S258>/Unit Delay' */
  boolean UnitDelay_DSTATE_jyd;        /* '<S257>/Unit Delay' */
  boolean UnitDelay_DSTATE_mvx;        /* '<S236>/Unit Delay' */
  boolean UnitDelay_DSTATE_ofi;        /* '<S215>/Unit Delay' */
  boolean UnitDelay_DSTATE_gg;         /* '<S213>/Unit Delay' */
  boolean UnitDelay_DSTATE_b3;         /* '<S197>/Unit Delay' */
  boolean UnitDelay_DSTATE_g2;         /* '<S195>/Unit Delay' */
  boolean UnitDelay_DSTATE_ieu;        /* '<S193>/Unit Delay' */
  boolean UnitDelay_DSTATE_a2;         /* '<S192>/Unit Delay' */
  boolean UnitDelay_DSTATE_lx;         /* '<S191>/Unit Delay' */
  boolean UnitDelay_DSTATE_fx;         /* '<S190>/Unit Delay' */
  boolean UnitDelay_DSTATE_a50;        /* '<S189>/Unit Delay' */
  boolean UnitDelay_DSTATE_dj;         /* '<S185>/Unit Delay' */
  boolean UnitDelay_DSTATE_ls;         /* '<S184>/Unit Delay' */
  boolean UnitDelay_DSTATE_pk;         /* '<S181>/Unit Delay' */
  boolean UnitDelay_DSTATE_cn;         /* '<S177>/Unit Delay' */
  boolean UnitDelay_DSTATE_aj;         /* '<S159>/Unit Delay' */
  boolean UnitDelay_DSTATE_f1x;        /* '<S147>/Unit Delay' */
  boolean UnitDelay_DSTATE_lku;        /* '<S139>/Unit Delay' */
  boolean UnitDelay_DSTATE_a2i;        /* '<S111>/Unit Delay' */
  boolean UnitDelay_DSTATE_et;         /* '<S110>/Unit Delay' */
  boolean UnitDelay_DSTATE_bo;         /* '<S109>/Unit Delay' */
  boolean UnitDelay_DSTATE_aq;         /* '<S101>/Unit Delay' */
  boolean UnitDelay_DSTATE_m2g;        /* '<S97>/Unit Delay' */
  boolean UnitDelay_DSTATE_kzl;        /* '<S46>/Unit Delay' */
  boolean UnitDelay_DSTATE_lg3;        /* '<S41>/Unit Delay' */
  boolean UnitDelay_DSTATE_ja;         /* '<S39>/Unit Delay' */
  boolean UnitDelay_DSTATE_bf;         /* '<S37>/Unit Delay' */
  boolean UnitDelay_DSTATE_ig;         /* '<S35>/Unit Delay' */
  boolean UnitDelay_DSTATE_ii;         /* '<S33>/Unit Delay' */
  boolean UnitDelay_DSTATE_do;         /* '<S31>/Unit Delay' */
  boolean UnitDelay_DSTATE_h2u;        /* '<S26>/Unit Delay' */
  boolean UnitDelay_DSTATE_ch;         /* '<S25>/Unit Delay' */
  boolean UnitDelay_DSTATE_g3l;        /* '<S24>/Unit Delay' */
} ARID_DEF_AppSwcIpm_T;

/* Imported (extern) states */
extern boolean VBSW_CANComCRCInstFlt_flg[100];/* '<S380>/Data Store Memory' */

/* PublicStructure Variables for Internal Data */
extern ARID_DEF_AppSwcIpm_T AppSwcIpm_ARID_DEF;/* '<S173>/BusCreator' */

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
 * Block '<S78>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S79>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S80>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * Block '<S93>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S94>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S95>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S97>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S98>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S99>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S100>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S101>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S102>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S103>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S104>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S105>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S106>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S107>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S109>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S110>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S111>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S112>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S113>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S114>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S115>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S122>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S123>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S127>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S128>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S129>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S130>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S131>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S132>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S134>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S136>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S137>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S138>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S139>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S142>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S143>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S147>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S148>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S150>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S153>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S157>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S158>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S159>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S160>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S166>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S167>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S176>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S177>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S179>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S180>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S181>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S183>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S184>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S185>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S186>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S189>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S190>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S191>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S192>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S193>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S194>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S195>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S196>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S197>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S198>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S201>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S202>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S204>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S205>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S206>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S207>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S208>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S209>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S210>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S211>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S212>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S213>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S214>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S215>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S216>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S217>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S232>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S233>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S234>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S235>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S236>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S237>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S240>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S241>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S243>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S247>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S248>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S251>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S257>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S258>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S259>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S260>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S264>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S265>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S266>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S267>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S268>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S269>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S271>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S275>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S276>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S277>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S278>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S279>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S280>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S282>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S283>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S284>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S285>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S286>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S287>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S288>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S289>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S302>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S303>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S304>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S305>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S306>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S307>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S309>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S310>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S312>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S313>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S314>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S315>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S320>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S322>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S323>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S324>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S325>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S326>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S332>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S333>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S334>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S335>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S347>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S348>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S349>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S350>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S351>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S352>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S353>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S354>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S355>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S356>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S357>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S358>/Data Type Conversion2' : Eliminate redundant data type conversion
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
 * Block '<S378>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S379>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion11' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion12' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion13' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion14' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion15' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion16' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion17' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<S380>/Data Type Conversion9' : Eliminate redundant data type conversion
 * Block '<S55>/Unit Delay' : Unused code path elimination
 * Block '<S56>/Unit Delay' : Unused code path elimination
 * Block '<S57>/Unit Delay' : Unused code path elimination
 * Block '<S58>/Unit Delay' : Unused code path elimination
 * Block '<S121>/Unit Delay' : Unused code path elimination
 * Block '<S122>/Unit Delay' : Unused code path elimination
 * Block '<S123>/Unit Delay' : Unused code path elimination
 * Block '<S142>/Unit Delay' : Unused code path elimination
 * Block '<S143>/Unit Delay' : Unused code path elimination
 * Block '<S146>/Unit Delay' : Unused code path elimination
 * Block '<S148>/Unit Delay' : Unused code path elimination
 * Block '<S149>/Unit Delay' : Unused code path elimination
 * Block '<S150>/Unit Delay' : Unused code path elimination
 * Block '<S151>/Unit Delay' : Unused code path elimination
 * Block '<S152>/Unit Delay' : Unused code path elimination
 * Block '<S157>/Unit Delay' : Unused code path elimination
 * Block '<S158>/Unit Delay' : Unused code path elimination
 * Block '<S160>/Unit Delay' : Unused code path elimination
 * Block '<S161>/Unit Delay' : Unused code path elimination
 * Block '<S201>/Unit Delay' : Unused code path elimination
 * Block '<S202>/Unit Delay' : Unused code path elimination
 * Block '<S203>/Unit Delay' : Unused code path elimination
 * Block '<S209>/Unit Delay' : Unused code path elimination
 * Block '<S210>/Unit Delay' : Unused code path elimination
 * Block '<S211>/Unit Delay' : Unused code path elimination
 * Block '<S212>/Unit Delay' : Unused code path elimination
 * Block '<S214>/Unit Delay' : Unused code path elimination
 * Block '<S216>/Unit Delay' : Unused code path elimination
 * Block '<S217>/Unit Delay' : Unused code path elimination
 * Block '<S240>/Unit Delay' : Unused code path elimination
 * Block '<S241>/Unit Delay' : Unused code path elimination
 * Block '<S242>/Unit Delay' : Unused code path elimination
 * Block '<S243>/Unit Delay' : Unused code path elimination
 * Block '<S247>/Unit Delay' : Unused code path elimination
 * Block '<S248>/Unit Delay' : Unused code path elimination
 * Block '<S270>/Unit Delay' : Unused code path elimination
 * Block '<S272>/Unit Delay' : Unused code path elimination
 * Block '<S273>/Unit Delay' : Unused code path elimination
 * Block '<S274>/Unit Delay' : Unused code path elimination
 * Block '<S301>/Unit Delay' : Unused code path elimination
 * Block '<S303>/Unit Delay' : Unused code path elimination
 * Block '<S308>/Unit Delay' : Unused code path elimination
 * Block '<S321>/Unit Delay' : Unused code path elimination
 * Block '<S322>/Unit Delay' : Unused code path elimination
 * Block '<S323>/Unit Delay' : Unused code path elimination
 * Block '<S324>/Unit Delay' : Unused code path elimination
 * Block '<S325>/Unit Delay' : Unused code path elimination
 * Block '<S326>/Unit Delay' : Unused code path elimination
 * Block '<S332>/Unit Delay' : Unused code path elimination
 * Block '<S333>/Unit Delay' : Unused code path elimination
 * Block '<S334>/Unit Delay' : Unused code path elimination
 * Block '<S335>/Unit Delay' : Unused code path elimination
 * Block '<S340>/Unit Delay' : Unused code path elimination
 * Block '<S341>/Unit Delay' : Unused code path elimination
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
 * '<S75>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUACUnlckVentSet_enum'
 * '<S76>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUAirInletModeSet_enum'
 * '<S77>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUBlwrModeSet_enum'
 * '<S78>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChgWiprMtMdSwSet_enum'
 * '<S79>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChrgngReq_enum'
 * '<S80>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUChrgngmode_enum'
 * '<S81>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUCstRecupModeSel_enum'
 * '<S82>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUDrvModeSel_enum'
 * '<S83>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUDrvPwrSet_cnt'
 * '<S84>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUFlwrMeHmCtrl_enum'
 * '<S85>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUFrntFanSpdSet_enum'
 * '<S86>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUHybEcoModeSet_enum'
 * '<S87>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndEntrySts_enum'
 * '<S88>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndLckSts_enum'
 * '<S89>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUIllmndUnlckSts_enum'
 * '<S90>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HULckHornOnSt_enum'
 * '<S91>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HULeftTempSet_enum'
 * '<S92>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUMaiDrvrSeatHeat_enum'
 * '<S93>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUManlDefrstCtl_enum'
 * '<S94>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUOvrspdCntrlLckSet_enum'
 * '<S95>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUParkAutoUnlckSet_enum'
 * '<S96>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUPeristalsisModeEnbl_enum'
 * '<S97>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUPwrOffReq_flg'
 * '<S98>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HURecupPwrSet_pct'
 * '<S99>'  : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HURrMirrHeat_enum'
 * '<S100>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUSteerWhlHeat_enum'
 * '<S101>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUTPMSRstReq_flg'
 * '<S102>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUTrnkLckSwCtrl_enum'
 * '<S103>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUVehMaxCurr_A'
 * '<S104>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_HUWiprIntlTmSet_enum'
 * '<S105>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXACRemtCtrlFlg_enum'
 * '<S106>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXACTempSet_enum'
 * '<S107>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXRmtPwrLck_enum'
 * '<S108>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUCCMSpdLimLvl_enum'
 * '<S109>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUChrgngConds_flg'
 * '<S110>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUOprtLic_flg'
 * '<S111>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBOXVCUVer_flg'
 * '<S112>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBoxOpenVentn_enum'
 * '<S113>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBoxRmtCarSearch_enum'
 * '<S114>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TBoxRmtLck_enum'
 * '<S115>' : 'AppSwcIpm/Ipm100ms/BacCAN_IN_100ms/Msg_HU_B_BAC/Subsys_VIPM_TboxRmtDefrstCtl_enum'
 * '<S116>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT'
 * '<S117>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT'
 * '<S118>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT'
 * '<S119>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT'
 * '<S120>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT'
 * '<S121>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempAve_C'
 * '<S122>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempMax_C'
 * '<S123>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/Subsys_VIPM_BMSHVBatCellTempMin_C'
 * '<S124>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in'
 * '<S125>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in1'
 * '<S126>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_BMS_5_BatTemp_EPT/rescale_in2'
 * '<S127>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData02_nu'
 * '<S128>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData03_nu'
 * '<S129>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData04_nu'
 * '<S130>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData05_nu'
 * '<S131>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData06_nu'
 * '<S132>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngData07_nu'
 * '<S133>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngSts_enum'
 * '<S134>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_INV_IMMO_Req_EPT/Subsys_VIPM_INVLrngSubID_cnt'
 * '<S135>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCActOprtMode_enum'
 * '<S136>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCLoVoltActCurnt_A'
 * '<S137>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCLoVoltActVolt_V'
 * '<S138>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUDCCSysFailSta_enum'
 * '<S139>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/Subsys_VIPM_IPUHVILFailSt_flg'
 * '<S140>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/rescale_in'
 * '<S141>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_1_State_EPT/rescale_in1'
 * '<S142>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/Subsys_VIPM_IPUDCCHiVoltActCurnt_A'
 * '<S143>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/Subsys_VIPM_IPUDCCHiVoltActVolt_V'
 * '<S144>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/rescale_in'
 * '<S145>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_DCC_2_ChrgInValue_EPT/rescale_in1'
 * '<S146>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCActOprtMode_enum'
 * '<S147>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCConnectMainSta_flg'
 * '<S148>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCHVDCActCur_A'
 * '<S149>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCHVDCActVol_V'
 * '<S150>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCInletActPwr_kW'
 * '<S151>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCInletConnectSta_enum'
 * '<S152>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCReq_enum'
 * '<S153>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/Subsys_VIPM_IPUOBCSysFailSta_enum'
 * '<S154>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/rescale_in'
 * '<S155>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_100ms/Msg_IPU_OBC_1_State_EPT/rescale_in1'
 * '<S156>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT'
 * '<S157>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUDeviceIntTemp_C'
 * '<S158>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW'
 * '<S159>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCS2State_flg'
 * '<S160>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCTempInt_C'
 * '<S161>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/Subsys_VIPM_IPUOBCWakeUpMode_enum'
 * '<S162>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in'
 * '<S163>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in1'
 * '<S164>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_200ms/Msg_IPU_OBC_2_Inlet_EPT/rescale_in2'
 * '<S165>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT'
 * '<S166>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_BMSBatCapcty_Ah'
 * '<S167>' : 'AppSwcIpm/Ipm100ms/EptCAN_IN_500ms/Msg_BMS_9_BattInfo_EPT/Subsys_VIPM_BMSPackID_enum'
 * '<S168>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms'
 * '<S169>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms'
 * '<S170>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA'
 * '<S171>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA'
 * '<S172>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA'
 * '<S173>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA'
 * '<S174>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPedlValPerc_pct'
 * '<S175>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum'
 * '<S176>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm'
 * '<S177>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBCDDActv_flg'
 * '<S178>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBEPBActuatorStR_enum'
 * '<S179>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBEPBDynAppSt_enum'
 * '<S180>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBFltLvl_enum'
 * '<S181>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/Subsys_VIPM_EHBReqBrkLiOn_flg'
 * '<S182>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EHB_B_CHA/rescale_in'
 * '<S183>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSRotSpd_degps'
 * '<S184>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAngCald_flg'
 * '<S185>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAngFailr_flg'
 * '<S186>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/Subsys_VIPM_EPSSteerWhlAng_deg'
 * '<S187>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/rescale_in'
 * '<S188>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_EPS_2_StrWhlAng_CHA/rescale_in1'
 * '<S189>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCABSActvSta_flg'
 * '<S190>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCCDPActv_flg'
 * '<S191>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCEBDActv_flg'
 * '<S192>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCESPActvSta_flg'
 * '<S193>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCESSActv_flg'
 * '<S194>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCFltLvl_enum'
 * '<S195>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCReqBrkLghtOn_flg'
 * '<S196>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCSlopPct_pct'
 * '<S197>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCTCSActvSta_flg'
 * '<S198>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/Subsys_VIPM_ESCVehSpd_kph'
 * '<S199>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/rescale_in'
 * '<S200>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_7_FuncStatus_CHA/rescale_in1'
 * '<S201>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCLatAccSnsrVal_g'
 * '<S202>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCLongAccSnsrVal_g'
 * '<S203>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCMstrCylPresr_bar'
 * '<S204>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCVehStandStillSta_enum'
 * '<S205>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnFL_enum'
 * '<S206>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnFR_enum'
 * '<S207>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnRL_enum'
 * '<S208>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlDirctnRR_enum'
 * '<S209>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphFL_kph'
 * '<S210>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphFR_kph'
 * '<S211>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphRL_kph'
 * '<S212>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlSpdKphRR_kph'
 * '<S213>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqDecReqActv_flg'
 * '<S214>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqDecReqVal_Nm'
 * '<S215>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqIncReqActv_flg'
 * '<S216>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCWhlTqIncReqVal_Nm'
 * '<S217>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/Subsys_VIPM_ESCYawRate_degps'
 * '<S218>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in'
 * '<S219>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in1'
 * '<S220>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in2'
 * '<S221>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in3'
 * '<S222>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in4'
 * '<S223>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in5'
 * '<S224>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in6'
 * '<S225>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in7'
 * '<S226>' : 'AppSwcIpm/Ipm10ms/CHACAN_IN_10ms/Msg_ESC_A_CHA/rescale_in8'
 * '<S227>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT'
 * '<S228>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT'
 * '<S229>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT'
 * '<S230>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_4_Value_EPT'
 * '<S231>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ActMode_enum'
 * '<S232>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ActTorq_Nm'
 * '<S233>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1AntithftAuthRslt_enum'
 * '<S234>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1MotSpd_rpm'
 * '<S235>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1PreChrgAllwd_enum'
 * '<S236>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1PreprogmFlg_flg'
 * '<S237>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/Subsys_VIPM_INV1ShutdownAllwd_enum'
 * '<S238>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/rescale_in'
 * '<S239>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_1_Value_EPT/rescale_in1'
 * '<S240>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2IgbtMaxTemp_C'
 * '<S241>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2InpCurnt_A'
 * '<S242>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2InpVolt_V'
 * '<S243>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/Subsys_VIPM_INV2MotorMaxTemp_C'
 * '<S244>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in'
 * '<S245>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in1'
 * '<S246>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_2_Value_EPT/rescale_in2'
 * '<S247>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/Subsys_VIPM_INV3DrvTqAllwdMax_Nm'
 * '<S248>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/Subsys_VIPM_INV3RecupTqAllwdMax_Nm'
 * '<S249>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/rescale_in'
 * '<S250>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_3_Value_EPT/rescale_in1'
 * '<S251>' : 'AppSwcIpm/Ipm10ms/EPTCAN_IN_10ms/Msg_INV_4_Value_EPT/Subsys_VIPM_INV4FltLvl_enum'
 * '<S252>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms'
 * '<S253>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms'
 * '<S254>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms'
 * '<S255>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD'
 * '<S256>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSGrShftLvrPstnReq_enum'
 * '<S257>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght11Sw_flg'
 * '<S258>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght12Sw_flg'
 * '<S259>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRght13Sw_flg'
 * '<S260>' : 'AppSwcIpm/Ipm20ms/BodCAN_IN_20ms/Msg_SCS_RiSwitchSts_BOD/Subsys_VIPM_SCSRghtSwVldty_flg'
 * '<S261>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA'
 * '<S262>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA'
 * '<S263>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA'
 * '<S264>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRBSDWarnLt_enum'
 * '<S265>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRBSDWarnRt_enum'
 * '<S266>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRDOWWarnLt_enum'
 * '<S267>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRDOWWarnRt_enum'
 * '<S268>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRRCTAWarnLt_enum'
 * '<S269>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_CRRR_A_CHA/Subsys_VIPM_CRRRRCTAWarnRt_enum'
 * '<S270>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBAVHAppldSt_enum'
 * '<S271>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBBLA_flg'
 * '<S272>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBActuatorStL_enum'
 * '<S273>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBSwitchSts_enum'
 * '<S274>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBEPBSysSt_enum'
 * '<S275>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_EHB_A_CHA/Subsys_VIPM_EHBHDCFucFault_flg'
 * '<S276>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCSdnMode_enum'
 * '<S277>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlDece_mps2'
 * '<S278>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlTqReqActv_flg'
 * '<S279>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMACCWhlTqReqVal_Nm'
 * '<S280>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAEBReq_flg'
 * '<S281>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccMode_enum'
 * '<S282>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccReqDriveOff_flg'
 * '<S283>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccReqStandstill_flg'
 * '<S284>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTarAccrnReqActv_flg'
 * '<S285>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTarAccrn_mps2'
 * '<S286>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTgtAxReq_flg'
 * '<S287>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMAccTgtAx_mps2'
 * '<S288>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMEPBReq_enum'
 * '<S289>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/Subsys_VIPM_FCMTrnLampReq_enum'
 * '<S290>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in'
 * '<S291>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in1'
 * '<S292>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in2'
 * '<S293>' : 'AppSwcIpm/Ipm20ms/ChaCAN_IN_20ms/Msg_FCM_B_CHA/rescale_in3'
 * '<S294>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT'
 * '<S295>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT'
 * '<S296>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT'
 * '<S297>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_3_DC_ChargeState_EPT'
 * '<S298>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT'
 * '<S299>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT'
 * '<S300>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT'
 * '<S301>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT/Subsys_VIPM_BMSDCSActOprtMode_enum'
 * '<S302>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_10_DC_ChargeStates_EPT/Subsys_VIPM_BMSDCSInletConnectSta_flg'
 * '<S303>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSActExchgCurnt_A'
 * '<S304>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSChrgInterlockSta_enum'
 * '<S305>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSDchrgInterlockSta_enum'
 * '<S306>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSEmgcySdnReq_flg'
 * '<S307>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSPwrTrainConnectSta_enum'
 * '<S308>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSRunSta_enum'
 * '<S309>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSSysFailSta_enum'
 * '<S310>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/Subsys_VIPM_BMSThermrunawayWrn_enum'
 * '<S311>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_1_MainState_EPT/rescale_in'
 * '<S312>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOCAct_pct'
 * '<S313>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOCRpt_pct'
 * '<S314>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSBatSOH_pct'
 * '<S315>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/Subsys_VIPM_BMSHVBatActVolt_V'
 * '<S316>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in'
 * '<S317>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in1'
 * '<S318>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in2'
 * '<S319>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_2_BatState_EPT/rescale_in3'
 * '<S320>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_3_DC_ChargeState_EPT/Subsys_VIPM_BMSDCSChrgReq_flg'
 * '<S321>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSACChrgAtclSta_enum'
 * '<S322>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSInletCooltActlTemp_C'
 * '<S323>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSIsoResist_MOhm'
 * '<S324>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSMaxChrgCurntAC_A'
 * '<S325>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSMaxChrgVoltAC_V'
 * '<S326>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/Subsys_VIPM_BMSOutlCooltActlTemp_C'
 * '<S327>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in'
 * '<S328>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in1'
 * '<S329>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in2'
 * '<S330>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in3'
 * '<S331>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_4_AC_ChargeState_EPT/rescale_in4'
 * '<S332>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxConChrgCurnt_A'
 * '<S333>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxConDisCurnt_A'
 * '<S334>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxInsChrgCurnt_A'
 * '<S335>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/Subsys_VIPM_BMSMaxInsDisCurnt_A'
 * '<S336>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in'
 * '<S337>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in1'
 * '<S338>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in2'
 * '<S339>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_6_DischrgRecup_EPT/rescale_in3'
 * '<S340>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT/Subsys_VIPM_BMSCellVoltMax_mV'
 * '<S341>' : 'AppSwcIpm/Ipm20ms/EptCAN_IN_20ms/Msg_BMS_7_CellVolt_EPT/Subsys_VIPM_BMSCellVoltMin_mV'
 * '<S342>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms'
 * '<S343>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms'
 * '<S344>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD'
 * '<S345>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_ESCL_ESCLStatus_BOD'
 * '<S346>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD'
 * '<S347>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPACAutoKey_flg'
 * '<S348>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPACSwKey_flg'
 * '<S349>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAVASOffKey_flg'
 * '<S350>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAVHKey_flg'
 * '<S351>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPAirInletModeKey_flg'
 * '<S352>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwngModeNextKey_flg'
 * '<S353>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwngModePrevKey_flg'
 * '<S354>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwrLvlAddKey_flg'
 * '<S355>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPBlwrLvlDecKey_flg'
 * '<S356>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPCenLckKey_flg'
 * '<S357>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPESCOffKey_flg'
 * '<S358>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPFrntWindDefrstKey_flg'
 * '<S359>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPHDCKey_flg'
 * '<S360>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPHzrdKey_flg'
 * '<S361>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPModeKey_flg'
 * '<S362>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPPwrRecupLvlKey_flg'
 * '<S363>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg'
 * '<S364>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTPMSKey_flg'
 * '<S365>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTempAddKey_flg'
 * '<S366>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_CCP_PanelStatus_BOD/Subsys_VIPM_CCPTempDecKey_flg'
 * '<S367>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_ESCL_ESCLStatus_BOD/Subsys_VIPM_ESCLUnOrLockfeedback_nu'
 * '<S368>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSFrntWiprSwtSt_enum'
 * '<S369>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSFrntWshrSwtSt_flg'
 * '<S370>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSHiBeamSwSt_flg'
 * '<S371>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLampAutoSt_flg'
 * '<S372>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLeTrnLmpSwSt_flg'
 * '<S373>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSLoBeamSwSt_flg'
 * '<S374>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSOvrVehBeamSwSt_flg'
 * '<S375>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSPstnLghtSwSt_flg'
 * '<S376>' : 'AppSwcIpm/Ipm50ms/BodCAN_IN_50ms/Msg_SCS_LeSwitchSts_BOD/Subsys_VIPM_SCSRiTrnLmpSwSt_flg'
 * '<S377>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA'
 * '<S378>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA/Subsys_VIPM_SRSCrashOutputSts_enum'
 * '<S379>' : 'AppSwcIpm/Ipm50ms/CHACAN_IN_50ms/Msg_SRS_1_Status_CHA/Subsys_VIPM_SRSDrvSeatbeltBkld_flg'
 * '<S380>' : 'AppSwcIpm/IpmMsgActv/CANCommCRCFlt'
 * '<S381>' : 'AppSwcIpm/IpmMsgActv/CANCommError'
 * '<S382>' : 'AppSwcIpm/IpmMsgActv/MsgActv'
 */
#endif                                 /* RTW_HEADER_AppSwcIpm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
