/*
 * File: AppSwcVcu_types.h
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.642
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 20 11:28:45 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AppSwcVcu_types_h_
#define RTW_HEADER_AppSwcVcu_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_EnumPGearSwSts_
#define DEFINED_TYPEDEF_FOR_EnumPGearSwSts_

/* N/A */
typedef uint8 EnumPGearSwSts;

/* enum EnumPGearSwSts */
#define EnumPGearSwSts_Reld            ((EnumPGearSwSts)0U)      /* Default value */
#define EnumPGearSwSts_Prsd            ((EnumPGearSwSts)1U)
#define EnumPGearSwSts_ShtGnd          ((EnumPGearSwSts)2U)
#define EnumPGearSwSts_ShtBat          ((EnumPGearSwSts)3U)
#define EnumPGearSwSts_Unknown         ((EnumPGearSwSts)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDrvModeAct_
#define DEFINED_TYPEDEF_FOR_EnumDrvModeAct_

/* N/A */
typedef uint8 EnumDrvModeAct;

/* enum EnumDrvModeAct */
#define EnumDrvModeAct_Invalid         ((EnumDrvModeAct)0U)      /* Default value */
#define EnumDrvModeAct_Eco             ((EnumDrvModeAct)1U)
#define EnumDrvModeAct_Auto            ((EnumDrvModeAct)2U)
#define EnumDrvModeAct_Manual          ((EnumDrvModeAct)3U)
#define EnumDrvModeAct_Eped            ((EnumDrvModeAct)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCrpModeAct_
#define DEFINED_TYPEDEF_FOR_EnumCrpModeAct_

/* N/A */
typedef uint8 EnumCrpModeAct;

/* enum EnumCrpModeAct */
#define EnumCrpModeAct_Open            ((EnumCrpModeAct)0U)      /* Default value */
#define EnumCrpModeAct_Closed          ((EnumCrpModeAct)1U)
#define EnumCrpModeAct_StandStill      ((EnumCrpModeAct)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumiTPMSSt_
#define DEFINED_TYPEDEF_FOR_EnumiTPMSSt_

/* N/A */
typedef uint8 EnumiTPMSSt;

/* enum EnumiTPMSSt */
#define EnumiTPMSSt_Init               ((EnumiTPMSSt)0U)         /* Default value */
#define EnumiTPMSSt_WaitLrn            ((EnumiTPMSSt)1U)
#define EnumiTPMSSt_Lrning             ((EnumiTPMSSt)2U)
#define EnumiTPMSSt_LrnFail            ((EnumiTPMSSt)3U)
#define EnumiTPMSSt_Normal             ((EnumiTPMSSt)4U)
#define EnumiTPMSSt_Warning            ((EnumiTPMSSt)5U)
#define EnumiTPMSSt_Fault              ((EnumiTPMSSt)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumTBOXLimSt_
#define DEFINED_TYPEDEF_FOR_EnumTBOXLimSt_

/* N/A */
typedef uint8 EnumTBOXLimSt;

/* enum EnumTBOXLimSt */
#define EnumTBOXLimSt_Normal           ((EnumTBOXLimSt)0U)       /* Default value */
#define EnumTBOXLimSt_Level1           ((EnumTBOXLimSt)1U)
#define EnumTBOXLimSt_Level2           ((EnumTBOXLimSt)2U)
#define EnumTBOXLimSt_Level3           ((EnumTBOXLimSt)3U)
#define EnumTBOXLimSt_Storage          ((EnumTBOXLimSt)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumXWhlDistErrRefSt_
#define DEFINED_TYPEDEF_FOR_EnumXWhlDistErrRefSt_

/* N/A */
typedef uint8 EnumXWhlDistErrRefSt;

/* enum EnumXWhlDistErrRefSt */
#define EnumXWhlDistErrRefSt_Init      ((EnumXWhlDistErrRefSt)0U) /* Default value */
#define EnumXWhlDistErrRefSt_Uncmplt   ((EnumXWhlDistErrRefSt)1U)
#define EnumXWhlDistErrRefSt_Cmpltd    ((EnumXWhlDistErrRefSt)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumRegenModeAct_
#define DEFINED_TYPEDEF_FOR_EnumRegenModeAct_

/* N/A */
typedef uint8 EnumRegenModeAct;

/* enum EnumRegenModeAct */
#define EnumRegenModeAct_Off           ((EnumRegenModeAct)0U)    /* Default value */
#define EnumRegenModeAct_Weak          ((EnumRegenModeAct)1U)
#define EnumRegenModeAct_Strong        ((EnumRegenModeAct)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumIBSChrgSt_
#define DEFINED_TYPEDEF_FOR_EnumIBSChrgSt_

/* N/A */
typedef uint8 EnumIBSChrgSt;

/* enum EnumIBSChrgSt */
#define EnumIBSChrgSt_Idle             ((EnumIBSChrgSt)0U)       /* Default value */
#define EnumIBSChrgSt_Charging         ((EnumIBSChrgSt)1U)
#define EnumIBSChrgSt_ChrgCmpld        ((EnumIBSChrgSt)2U)
#define EnumIBSChrgSt_Fail             ((EnumIBSChrgSt)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumSysSta_
#define DEFINED_TYPEDEF_FOR_EnumSysSta_

/* N/A */
typedef uint8 EnumSysSta;

/* enum EnumSysSta */
#define EnumSysSta_Sleep               ((EnumSysSta)0U)          /* Default value */
#define EnumSysSta_WakeUp              ((EnumSysSta)10U)
#define EnumSysSta_HVSetUp             ((EnumSysSta)20U)
#define EnumSysSta_HVCheck             ((EnumSysSta)21U)
#define EnumSysSta_PTStby              ((EnumSysSta)30U)
#define EnumSysSta_PTRdy               ((EnumSysSta)31U)
#define EnumSysSta_DCChrging           ((EnumSysSta)40U)
#define EnumSysSta_DCChrgOver          ((EnumSysSta)41U)
#define EnumSysSta_ACChrgEnbl          ((EnumSysSta)50U)
#define EnumSysSta_ACChrging           ((EnumSysSta)51U)
#define EnumSysSta_ACChrgStop          ((EnumSysSta)52U)
#define EnumSysSta_ACChrgOver          ((EnumSysSta)53U)
#define EnumSysSta_ACDschrging         ((EnumSysSta)60U)
#define EnumSysSta_ACDchaStop          ((EnumSysSta)61U)
#define EnumSysSta_ACDchaOver          ((EnumSysSta)62U)
#define EnumSysSta_HVDeviceOff         ((EnumSysSta)70U)
#define EnumSysSta_HVCutOff            ((EnumSysSta)71U)
#define EnumSysSta_HVDschrg            ((EnumSysSta)72U)
#define EnumSysSta_EmgcyPwrDwn         ((EnumSysSta)73U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumTBOXLimGrd_
#define DEFINED_TYPEDEF_FOR_EnumTBOXLimGrd_

/* N/A */
typedef uint8 EnumTBOXLimGrd;

/* enum EnumTBOXLimGrd */
#define EnumTBOXLimGrd_Normal          ((EnumTBOXLimGrd)0U)      /* Default value */
#define EnumTBOXLimGrd_Level1          ((EnumTBOXLimGrd)1U)
#define EnumTBOXLimGrd_Level2          ((EnumTBOXLimGrd)2U)
#define EnumTBOXLimGrd_Level3          ((EnumTBOXLimGrd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCruiseStatus_
#define DEFINED_TYPEDEF_FOR_EnumCruiseStatus_

/* N/A */
typedef uint8 EnumCruiseStatus;

/* enum EnumCruiseStatus */
#define EnumCruiseStatus_NormOff       ((EnumCruiseStatus)0U)    /* Default value */
#define EnumCruiseStatus_ErrOff        ((EnumCruiseStatus)1U)
#define EnumCruiseStatus_OutRngStby    ((EnumCruiseStatus)2U)
#define EnumCruiseStatus_NormStby      ((EnumCruiseStatus)3U)
#define EnumCruiseStatus_NormActv      ((EnumCruiseStatus)4U)
#define EnumCruiseStatus_OvrdActv      ((EnumCruiseStatus)5U)
#define EnumCruiseStatus_SpdLmt        ((EnumCruiseStatus)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCCState_
#define DEFINED_TYPEDEF_FOR_EnumCCState_

/* N/A */
typedef uint8 EnumCCState;

/* enum EnumCCState */
#define EnumCCState_Off                ((EnumCCState)0U)         /* Default value */
#define EnumCCState_Standby            ((EnumCCState)1U)
#define EnumCCState_Active             ((EnumCCState)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCCTgtSpdSt_
#define DEFINED_TYPEDEF_FOR_EnumCCTgtSpdSt_

/* N/A */
typedef uint8 EnumCCTgtSpdSt;

/* enum EnumCCTgtSpdSt */
#define EnumCCTgtSpdSt_Reset           ((EnumCCTgtSpdSt)0U)      /* Default value */
#define EnumCCTgtSpdSt_Hold            ((EnumCCTgtSpdSt)1U)
#define EnumCCTgtSpdSt_Set             ((EnumCCTgtSpdSt)2U)
#define EnumCCTgtSpdSt_TapDwn          ((EnumCCTgtSpdSt)3U)
#define EnumCCTgtSpdSt_TapUp           ((EnumCCTgtSpdSt)4U)
#define EnumCCTgtSpdSt_Decelerate      ((EnumCCTgtSpdSt)5U)
#define EnumCCTgtSpdSt_Accelerate      ((EnumCCTgtSpdSt)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumHDCState_
#define DEFINED_TYPEDEF_FOR_EnumHDCState_

/* N/A */
typedef uint8 EnumHDCState;

/* enum EnumHDCState */
#define EnumHDCState_Idle              ((EnumHDCState)0U)        /* Default value */
#define EnumHDCState_Standby           ((EnumHDCState)1U)
#define EnumHDCState_Active            ((EnumHDCState)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumMotorDirReq_
#define DEFINED_TYPEDEF_FOR_EnumMotorDirReq_

/* N/A */
typedef uint8 EnumMotorDirReq;

/* enum EnumMotorDirReq */
#define EnumMotorDirReq_Stdby          ((EnumMotorDirReq)0U)     /* Default value */
#define EnumMotorDirReq_Forward        ((EnumMotorDirReq)1U)
#define EnumMotorDirReq_Reverse        ((EnumMotorDirReq)2U)
#define EnumMotorDirReq_Invalid        ((EnumMotorDirReq)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumMotorModeReq_
#define DEFINED_TYPEDEF_FOR_EnumMotorModeReq_

/* N/A */
typedef uint8 EnumMotorModeReq;

/* enum EnumMotorModeReq */
#define EnumMotorModeReq_Stdby         ((EnumMotorModeReq)0U)    /* Default value */
#define EnumMotorModeReq_TqCtrl        ((EnumMotorModeReq)1U)
#define EnumMotorModeReq_SpdCtrl       ((EnumMotorModeReq)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumTZXStat_
#define DEFINED_TYPEDEF_FOR_EnumTZXStat_

/* N/A */
typedef uint8 EnumTZXStat;

/* enum EnumTZXStat */
#define EnumTZXStat_NTRL               ((EnumTZXStat)0U)         /* Default value */
#define EnumTZXStat_NZ                 ((EnumTZXStat)1U)
#define EnumTZXStat_AZD                ((EnumTZXStat)2U)
#define EnumTZXStat_BZI                ((EnumTZXStat)3U)
#define EnumTZXStat_ZXD                ((EnumTZXStat)4U)
#define EnumTZXStat_ZXI                ((EnumTZXStat)5U)
#define EnumTZXStat_BZD                ((EnumTZXStat)6U)
#define EnumTZXStat_AZI                ((EnumTZXStat)7U)
#define EnumTZXStat_PZ                 ((EnumTZXStat)8U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumOBCOprtCmd_
#define DEFINED_TYPEDEF_FOR_EnumOBCOprtCmd_

/* N/A */
typedef uint8 EnumOBCOprtCmd;

/* enum EnumOBCOprtCmd */
#define EnumOBCOprtCmd_Standby         ((EnumOBCOprtCmd)0U)      /* Default value */
#define EnumOBCOprtCmd_Charge          ((EnumOBCOprtCmd)1U)
#define EnumOBCOprtCmd_Rsrvd           ((EnumOBCOprtCmd)2U)
#define EnumOBCOprtCmd_ChrgCmpl        ((EnumOBCOprtCmd)3U)
#define EnumOBCOprtCmd_Discharge       ((EnumOBCOprtCmd)4U)
#define EnumOBCOprtCmd_DchaCmpl        ((EnumOBCOprtCmd)5U)
#define EnumOBCOprtCmd_ChrgAftOTA      ((EnumOBCOprtCmd)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumVCUMode_
#define DEFINED_TYPEDEF_FOR_EnumVCUMode_

/* N/A */
typedef uint8 EnumVCUMode;

/* enum EnumVCUMode */
#define EnumVCUMode_PwrOff             ((EnumVCUMode)0U)         /* Default value */
#define EnumVCUMode_WakeUp             ((EnumVCUMode)1U)
#define EnumVCUMode_PwrUp              ((EnumVCUMode)2U)
#define EnumVCUMode_PwrOnDrv           ((EnumVCUMode)3U)
#define EnumVCUMode_PwrOnDCChrg        ((EnumVCUMode)4U)
#define EnumVCUMode_PwrOnACChrg        ((EnumVCUMode)5U)
#define EnumVCUMode_PwrOnACDcha        ((EnumVCUMode)6U)
#define EnumVCUMode_PwrDwn             ((EnumVCUMode)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBMSSdnCmd_
#define DEFINED_TYPEDEF_FOR_EnumBMSSdnCmd_

/* N/A */
typedef uint8 EnumBMSSdnCmd;

/* enum EnumBMSSdnCmd */
#define EnumBMSSdnCmd_Normal           ((EnumBMSSdnCmd)0U)       /* Default value */
#define EnumBMSSdnCmd_Shutdwn          ((EnumBMSSdnCmd)1U)
#define EnumBMSSdnCmd_EmgcySdn         ((EnumBMSSdnCmd)2U)
#define EnumBMSSdnCmd_Rsrvd            ((EnumBMSSdnCmd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumChrgAllwCmd_
#define DEFINED_TYPEDEF_FOR_EnumChrgAllwCmd_

/* N/A */
typedef uint8 EnumChrgAllwCmd;

/* enum EnumChrgAllwCmd */
#define EnumChrgAllwCmd_NotAllwd       ((EnumChrgAllwCmd)0U)     /* Default value */
#define EnumChrgAllwCmd_DCChrg         ((EnumChrgAllwCmd)1U)
#define EnumChrgAllwCmd_ACChrg         ((EnumChrgAllwCmd)2U)
#define EnumChrgAllwCmd_ACDcha         ((EnumChrgAllwCmd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumPTActMd_
#define DEFINED_TYPEDEF_FOR_EnumPTActMd_

/* N/A */
typedef uint8 EnumPTActMd;

/* enum EnumPTActMd */
#define EnumPTActMd_OFF                ((EnumPTActMd)0U)         /* Default value */
#define EnumPTActMd_Standby            ((EnumPTActMd)1U)
#define EnumPTActMd_Ready              ((EnumPTActMd)2U)
#define EnumPTActMd_EmgcySdn           ((EnumPTActMd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCCOprtCmd_
#define DEFINED_TYPEDEF_FOR_EnumDCCOprtCmd_

/* N/A */
typedef uint8 EnumDCCOprtCmd;

/* enum EnumDCCOprtCmd */
#define EnumDCCOprtCmd_Off             ((EnumDCCOprtCmd)4U)      /* Default value */
#define EnumDCCOprtCmd_Standby         ((EnumDCCOprtCmd)0U)
#define EnumDCCOprtCmd_Buck            ((EnumDCCOprtCmd)2U)
#define EnumDCCOprtCmd_Boost           ((EnumDCCOprtCmd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBMSWakeUpMd_
#define DEFINED_TYPEDEF_FOR_EnumBMSWakeUpMd_

/* N/A */
typedef uint8 EnumBMSWakeUpMd;

/* enum EnumBMSWakeUpMd */
#define EnumBMSWakeUpMd_Invld          ((EnumBMSWakeUpMd)0U)     /* Default value */
#define EnumBMSWakeUpMd_ACChrg         ((EnumBMSWakeUpMd)1U)
#define EnumBMSWakeUpMd_ACDcha         ((EnumBMSWakeUpMd)2U)
#define EnumBMSWakeUpMd_DisChrg        ((EnumBMSWakeUpMd)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumEPBReq_
#define DEFINED_TYPEDEF_FOR_EnumEPBReq_

/* N/A */
typedef uint8 EnumEPBReq;

/* enum EnumEPBReq */
#define EnumEPBReq_NoCmd               ((EnumEPBReq)0U)          /* Default value */
#define EnumEPBReq_Apply               ((EnumEPBReq)1U)
#define EnumEPBReq_Release             ((EnumEPBReq)2U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumGearPstn_
#define DEFINED_TYPEDEF_FOR_EnumGearPstn_

/* N/A */
typedef uint8 EnumGearPstn;

/* enum EnumGearPstn */
#define EnumGearPstn_P                 ((EnumGearPstn)0U)        /* Default value */
#define EnumGearPstn_N                 ((EnumGearPstn)1U)
#define EnumGearPstn_D                 ((EnumGearPstn)2U)
#define EnumGearPstn_R                 ((EnumGearPstn)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumTgtGearPstn_
#define DEFINED_TYPEDEF_FOR_EnumTgtGearPstn_

/* N/A */
typedef uint8 EnumTgtGearPstn;

/* enum EnumTgtGearPstn */
#define EnumTgtGearPstn_NoReq          ((EnumTgtGearPstn)0U)     /* Default value */
#define EnumTgtGearPstn_P              ((EnumTgtGearPstn)1U)
#define EnumTgtGearPstn_N              ((EnumTgtGearPstn)2U)
#define EnumTgtGearPstn_D              ((EnumTgtGearPstn)3U)
#define EnumTgtGearPstn_R              ((EnumTgtGearPstn)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_11mA3pBF0WJgD7qpwLWW6B_
#define DEFINED_TYPEDEF_FOR_struct_11mA3pBF0WJgD7qpwLWW6B_

typedef struct {
  float32 VVSO_YawRateBas_degps;
  boolean VVSO_YawRateBasVld_flg;
  float32 VVSO_ALgtSnsr_mps2;
  boolean VVSO_ALgtSnsrVld_flg;
  float32 VVSO_ALatSnsr_mps2;
  boolean VVSO_ALatSnsrVld_flg;
  float32 VVSO_WhlAcceltnFL_mps2;
  float32 VVSO_WhlAcceltnFR_mps2;
  float32 VVSO_WhlAcceltnRL_mps2;
  float32 VVSO_WhlAcceltnRR_mps2;
} struct_11mA3pBF0WJgD7qpwLWW6B;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_TL7bRvi8fo8bvtPg3PDUfH_
#define DEFINED_TYPEDEF_FOR_struct_TL7bRvi8fo8bvtPg3PDUfH_

typedef struct {
  float32 VVSO_RoadSlopEst_pct;
  boolean VVSO_RoadSlopEstVld_flg;
  float32 VVSO_RoadSlopTqEst_Nm;
  float32 VVSO_VehDrvResistTq_Nm;
} struct_TL7bRvi8fo8bvtPg3PDUfH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BM6Id6DOB8B86XPfiqSZiD_
#define DEFINED_TYPEDEF_FOR_struct_BM6Id6DOB8B86XPfiqSZiD_

typedef struct {
  float32 VVSO_VehMassEst_kg;
  boolean VVSO_VehMassConf_flg;
  uint8 VVSO_VehMassDistb_enum;
  float32 VVSO_VehSpd_mps;
} struct_BM6Id6DOB8B86XPfiqSZiD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_DMJG9y1gAAdrdFyTNH5fi_
#define DEFINED_TYPEDEF_FOR_struct_DMJG9y1gAAdrdFyTNH5fi_

typedef struct {
  float32 VCPT_WhlDrvMaxTq_Nm;
  float32 VCPT_WhlDrgMaxTq_Nm;
  float32 VCPT_MotorDrvMaxTq_Nm;
  float32 VCPT_MotorDrgMaxTq_Nm;
  boolean VCPT_MotorSpdRvrs_flg;
} struct_DMJG9y1gAAdrdFyTNH5fi;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_kyba7AjMdSuKPQINgiZQQE_
#define DEFINED_TYPEDEF_FOR_struct_kyba7AjMdSuKPQINgiZQQE_

typedef struct {
  float32 VDAC_DrvAsstTqTgt_Nm;
  uint8 VDAC_DrvAsstTqSts_enum;
  float32 VDAC_VirtPedPstn_pct;
  float32 VDAC_VirtAccPedPstn_pct;
  boolean VDAC_ACCEnbl_flg;
  boolean VDAC_ACCOvrd_flg;
  boolean VDAC_ACCAvail_flg;
  uint8 VDAC_CruzCtrlStat_enum;
  float32 VDAC_CCTgtSpd_kph;
  uint8 VDAC_VirtAccPedPstnSta_enum;
  boolean VDAC_TqRespFastReq_flg;
  boolean VDAC_CruzMainSwOn_flg;
  boolean VDAC_AccReqStandstill_flg;
  uint8 VDAC_ACCStat_enum;
  boolean VDAC_OPDAvail_flg;
  boolean VDAC_OPDActv_flg;
  uint8 VDAC_AutoBrkReq_enum;
  boolean VDAC_OPDTqRespSprt_flg;
  boolean VDAC_EnblEHBBrkRun_flg;
  float32 VDAC_MstrCylPresrReq_bar;
  uint8 VDAC_HDCSt_enum;
} struct_kyba7AjMdSuKPQINgiZQQE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_3gsZ366RBeJnmJmNOO5AhC_
#define DEFINED_TYPEDEF_FOR_struct_3gsZ366RBeJnmJmNOO5AhC_

typedef struct {
  float32 VTQC_DrvTqReqWhl_Nm;
  float32 VTQC_MotorTqReq_Nm;
  boolean VTQC_RBSActv_flg;
  float32 VTQC_BrkRegenMaxTqWhl_Nm;
  float32 VTQC_BrkRegenTgtTqWhl_Nm;
  float32 VTQC_DrvTqReqWhlRBS_Nm;
} struct_3gsZ366RBeJnmJmNOO5AhC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_kcLkTIQ2zXDWpSEWLgR2JH_
#define DEFINED_TYPEDEF_FOR_struct_kcLkTIQ2zXDWpSEWLgR2JH_

typedef struct {
  float32 VTQD_DrvTqReqWhl_Nm;
  float32 VTQD_FullPedDrvTqWhl_Nm;
  float32 VTQD_CstRegenTqReqWhl_Nm;
  float32 VTQD_CstRegenEndPstn_pct;
  boolean VTQD_BrkRegenEnbl_flg;
  boolean VTQD_TqZeroFast_flg;
  boolean VTQD_TqZeroSlow_flg;
  boolean VTQD_TqZero_flg;
  boolean VTQD_BkwdDrv_flg;
  float32 VTQD_PedalTqReqWhlRaw_Nm;
  float32 VTQD_DrvTqReqWhlMrg_Nm;
  float32 VTQD_CstRegenDrtFac_c;
} struct_kcLkTIQ2zXDWpSEWLgR2JH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_0QSRD16kBJ7rQhI25gjD8C_
#define DEFINED_TYPEDEF_FOR_struct_0QSRD16kBJ7rQhI25gjD8C_

typedef struct {
  float32 VTQF_DrvTqReqWhl_Nm;
  float32 VTQF_TqRateLimInc_Nmps;
  float32 VTQF_TqRateLimDec_Nmps;
} struct_0QSRD16kBJ7rQhI25gjD8C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_1RLNpbOd508kNyZReFR7OE_
#define DEFINED_TYPEDEF_FOR_struct_1RLNpbOd508kNyZReFR7OE_

typedef struct {
  uint8 VTQR_MotorModeReq_enum;
  float32 VTQR_MotorSpdReq_rpm;
  float32 VTQR_MotorTqReq_Nm;
  uint8 VTQR_MotorDirReq_enum;
  boolean VTQR_MotDampngEnbl_flg;
  float32 VTQR_MotDampngLmt_Nm;
} struct_1RLNpbOd508kNyZReFR7OE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_khZ7q4WM2i0FlIv5GQIv3F_
#define DEFINED_TYPEDEF_FOR_struct_khZ7q4WM2i0FlIv5GQIv3F_

typedef struct {
  float32 VVTM_VehSpd_kph;
  float32 VVTM_VehAcceltn_mps2;
  float32 VVTM_MotorSpd_rpm;
  uint8 VVTM_VehActGrPstn_enum;
  boolean VVTM_BrkPedReld_flg;
  boolean VVTM_ESPIntvActv_flg;
  boolean VVTM_AutoHoldIntv_flg;
  float32 VVTM_DrvPwrIntnsty_pct;
  float32 VVTM_RegenPwrIntnsty_pct;
} struct_khZ7q4WM2i0FlIv5GQIv3F;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_4t2rZ1ShKYtehtDWB50ACH_
#define DEFINED_TYPEDEF_FOR_struct_4t2rZ1ShKYtehtDWB50ACH_

typedef struct {
  float32 VDAG_LVBatActVolt_V;
  boolean HW_KL15_flg;
  boolean OBC_WakeUp_flg;
  boolean BMS_WakeUp_flg;
  boolean VDAG_HWWakeUp_flg;
  boolean VDAG_WakeUp_flg;
  boolean VDAG_StandStillPN_flg;
  boolean VDAG_VehSpdLo_flg;
  boolean VDAG_ClrDTCReq_flg;
} struct_4t2rZ1ShKYtehtDWB50ACH;

#endif
#endif                                 /* RTW_HEADER_AppSwcVcu_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
