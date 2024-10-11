/*
 * File: AppSwcOpm_types.h
 *
 * Code generated for Simulink model 'AppSwcOpm'.
 *
 * Model version                  : 9.95
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep 25 10:30:11 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_AppSwcOpm_types_h_
#define RTW_HEADER_AppSwcOpm_types_h_
#include "rtwtypes.h"
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

#ifndef DEFINED_TYPEDEF_FOR_EnumAccPedSnsrSt_
#define DEFINED_TYPEDEF_FOR_EnumAccPedSnsrSt_

/* N/A */
typedef uint8 EnumAccPedSnsrSt;

/* enum EnumAccPedSnsrSt */
#define EnumAccPedSnsrSt_Invalid       ((EnumAccPedSnsrSt)0U)    /* Default value */
#define EnumAccPedSnsrSt_Normal        ((EnumAccPedSnsrSt)1U)
#define EnumAccPedSnsrSt_Estimated     ((EnumAccPedSnsrSt)2U)
#define EnumAccPedSnsrSt_Faulty        ((EnumAccPedSnsrSt)3U)
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

#ifndef DEFINED_TYPEDEF_FOR_EnumEPBReq_
#define DEFINED_TYPEDEF_FOR_EnumEPBReq_

/* N/A */
typedef uint8 EnumEPBReq;

/* enum EnumEPBReq */
#define EnumEPBReq_NoCmd               ((EnumEPBReq)0U)          /* Default value */
#define EnumEPBReq_Apply               ((EnumEPBReq)1U)
#define EnumEPBReq_Release             ((EnumEPBReq)2U)
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

#ifndef DEFINED_TYPEDEF_FOR_EnumChrgEnaAC_
#define DEFINED_TYPEDEF_FOR_EnumChrgEnaAC_

/* N/A */
typedef uint8 EnumChrgEnaAC;

/* enum EnumChrgEnaAC */
#define EnumChrgEnaAC_Disable          ((EnumChrgEnaAC)0U)       /* Default value */
#define EnumChrgEnaAC_ChrgEnbl         ((EnumChrgEnaAC)1U)
#define EnumChrgEnaAC_DchaEnbl         ((EnumChrgEnaAC)2U)
#define EnumChrgEnaAC_Rsrvd            ((EnumChrgEnaAC)3U)
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

#ifndef DEFINED_TYPEDEF_FOR_EnumCrpModeAct_
#define DEFINED_TYPEDEF_FOR_EnumCrpModeAct_

/* N/A */
typedef uint8 EnumCrpModeAct;

/* enum EnumCrpModeAct */
#define EnumCrpModeAct_Open            ((EnumCrpModeAct)0U)      /* Default value */
#define EnumCrpModeAct_Closed          ((EnumCrpModeAct)1U)
#define EnumCrpModeAct_StandStill      ((EnumCrpModeAct)2U)
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
#endif                                 /* RTW_HEADER_AppSwcOpm_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
