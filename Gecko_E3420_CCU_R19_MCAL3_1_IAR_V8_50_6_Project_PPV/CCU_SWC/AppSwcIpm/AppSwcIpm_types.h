/*
 * File: AppSwcIpm_types.h
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

#ifndef RTW_HEADER_AppSwcIpm_types_h_
#define RTW_HEADER_AppSwcIpm_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_EnumRegenModeSelct_
#define DEFINED_TYPEDEF_FOR_EnumRegenModeSelct_

/* N/A */
typedef uint8 EnumRegenModeSelct;

/* enum EnumRegenModeSelct */
#define EnumRegenModeSelct_NoCmd       ((EnumRegenModeSelct)0U)  /* Default value */
#define EnumRegenModeSelct_Weak        ((EnumRegenModeSelct)1U)
#define EnumRegenModeSelct_Strong      ((EnumRegenModeSelct)2U)
#define EnumRegenModeSelct_Off         ((EnumRegenModeSelct)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDrvModeSelct_
#define DEFINED_TYPEDEF_FOR_EnumDrvModeSelct_

/* N/A */
typedef uint8 EnumDrvModeSelct;

/* enum EnumDrvModeSelct */
#define EnumDrvModeSelct_NoCmd         ((EnumDrvModeSelct)0U)    /* Default value */
#define EnumDrvModeSelct_Eco           ((EnumDrvModeSelct)1U)
#define EnumDrvModeSelct_Auto          ((EnumDrvModeSelct)2U)
#define EnumDrvModeSelct_Manual        ((EnumDrvModeSelct)3U)
#define EnumDrvModeSelct_Eped          ((EnumDrvModeSelct)4U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumCrpModeEnbl_
#define DEFINED_TYPEDEF_FOR_EnumCrpModeEnbl_

/* N/A */
typedef uint8 EnumCrpModeEnbl;

/* enum EnumCrpModeEnbl */
#define EnumCrpModeEnbl_NoCmd          ((EnumCrpModeEnbl)0U)     /* Default value */
#define EnumCrpModeEnbl_Enabled        ((EnumCrpModeEnbl)1U)
#define EnumCrpModeEnbl_Disabled       ((EnumCrpModeEnbl)2U)
#define EnumCrpModeEnbl_Reserved       ((EnumCrpModeEnbl)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumDCCActMd_
#define DEFINED_TYPEDEF_FOR_EnumDCCActMd_

/* N/A */
typedef uint8 EnumDCCActMd;

/* enum EnumDCCActMd */
#define EnumDCCActMd_Init              ((EnumDCCActMd)0U)        /* Default value */
#define EnumDCCActMd_Standby           ((EnumDCCActMd)1U)
#define EnumDCCActMd_Prechrg           ((EnumDCCActMd)2U)
#define EnumDCCActMd_Buck              ((EnumDCCActMd)3U)
#define EnumDCCActMd_Boost             ((EnumDCCActMd)4U)
#define EnumDCCActMd_Fault             ((EnumDCCActMd)5U)
#define EnumDCCActMd_OFF               ((EnumDCCActMd)6U)
#define EnumDCCActMd_Rsrvd             ((EnumDCCActMd)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumOBCActMd_
#define DEFINED_TYPEDEF_FOR_EnumOBCActMd_

/* N/A */
typedef uint8 EnumOBCActMd;

/* enum EnumOBCActMd */
#define EnumOBCActMd_Init              ((EnumOBCActMd)0U)        /* Default value */
#define EnumOBCActMd_ChrgStrt          ((EnumOBCActMd)1U)
#define EnumOBCActMd_Charging          ((EnumOBCActMd)2U)
#define EnumOBCActMd_ChrgStop          ((EnumOBCActMd)3U)
#define EnumOBCActMd_V2VDchaStrtg      ((EnumOBCActMd)4U)
#define EnumOBCActMd_V2LDchaStrtg      ((EnumOBCActMd)5U)
#define EnumOBCActMd_DchaStrt          ((EnumOBCActMd)6U)
#define EnumOBCActMd_V2VDischrging     ((EnumOBCActMd)7U)
#define EnumOBCActMd_V2LDischrging     ((EnumOBCActMd)8U)
#define EnumOBCActMd_Dischrging        ((EnumOBCActMd)9U)
#define EnumOBCActMd_DchaStop          ((EnumOBCActMd)10U)
#define EnumOBCActMd_PreSleep          ((EnumOBCActMd)11U)
#define EnumOBCActMd_Sleep             ((EnumOBCActMd)12U)
#define EnumOBCActMd_Rsrvd1            ((EnumOBCActMd)13U)
#define EnumOBCActMd_Rsrvd2            ((EnumOBCActMd)14U)
#define EnumOBCActMd_Rsrvd3            ((EnumOBCActMd)15U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumOBCPlugSt_
#define DEFINED_TYPEDEF_FOR_EnumOBCPlugSt_

/* N/A */
typedef uint8 EnumOBCPlugSt;

/* enum EnumOBCPlugSt */
#define EnumOBCPlugSt_NoPlug           ((EnumOBCPlugSt)0U)       /* Default value */
#define EnumOBCPlugSt_HalfPlug         ((EnumOBCPlugSt)1U)
#define EnumOBCPlugSt_Plug             ((EnumOBCPlugSt)2U)
#define EnumOBCPlugSt_Rsrvd            ((EnumOBCPlugSt)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumOBCReq_
#define DEFINED_TYPEDEF_FOR_EnumOBCReq_

/* N/A */
typedef uint8 EnumOBCReq;

/* enum EnumOBCReq */
#define EnumOBCReq_NoReq               ((EnumOBCReq)0U)          /* Default value */
#define EnumOBCReq_Charge              ((EnumOBCReq)1U)
#define EnumOBCReq_DisChrg             ((EnumOBCReq)2U)
#define EnumOBCReq_Rsrvd               ((EnumOBCReq)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumOBCWakeUpMd_
#define DEFINED_TYPEDEF_FOR_EnumOBCWakeUpMd_

/* N/A */
typedef uint8 EnumOBCWakeUpMd;

/* enum EnumOBCWakeUpMd */
#define EnumOBCWakeUpMd_Invld          ((EnumOBCWakeUpMd)0U)     /* Default value */
#define EnumOBCWakeUpMd_ACChrg         ((EnumOBCWakeUpMd)1U)
#define EnumOBCWakeUpMd_V2VDcha        ((EnumOBCWakeUpMd)2U)
#define EnumOBCWakeUpMd_V2LDcha        ((EnumOBCWakeUpMd)3U)
#define EnumOBCWakeUpMd_InDcha         ((EnumOBCWakeUpMd)4U)
#define EnumOBCWakeUpMd_Rsrvd1         ((EnumOBCWakeUpMd)5U)
#define EnumOBCWakeUpMd_Rsrvd2         ((EnumOBCWakeUpMd)6U)
#define EnumOBCWakeUpMd_Rsrvd3         ((EnumOBCWakeUpMd)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumRegenTgtTqStat_
#define DEFINED_TYPEDEF_FOR_EnumRegenTgtTqStat_

/* N/A */
typedef uint8 EnumRegenTgtTqStat;

/* enum EnumRegenTgtTqStat */
#define EnumRegenTgtTqStat_NotInit     ((EnumRegenTgtTqStat)0U)  /* Default value */
#define EnumRegenTgtTqStat_Inactive    ((EnumRegenTgtTqStat)1U)
#define EnumRegenTgtTqStat_Active      ((EnumRegenTgtTqStat)2U)
#define EnumRegenTgtTqStat_Fault       ((EnumRegenTgtTqStat)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumEPBState_
#define DEFINED_TYPEDEF_FOR_EnumEPBState_

/* N/A */
typedef uint8 EnumEPBState;

/* enum EnumEPBState */
#define EnumEPBState_Releasing         ((EnumEPBState)0U)        /* Default value */
#define EnumEPBState_Applied           ((EnumEPBState)1U)
#define EnumEPBState_Released          ((EnumEPBState)2U)
#define EnumEPBState_Applying          ((EnumEPBState)3U)
#define EnumEPBState_CmpltReleased     ((EnumEPBState)4U)
#define EnumEPBState_Unknown           ((EnumEPBState)5U)
#define EnumEPBState_Hold              ((EnumEPBState)6U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumINVActMd_
#define DEFINED_TYPEDEF_FOR_EnumINVActMd_

/* N/A */
typedef uint8 EnumINVActMd;

/* enum EnumINVActMd */
#define EnumINVActMd_Invld             ((EnumINVActMd)0U)        /* Default value */
#define EnumINVActMd_IniCmpld          ((EnumINVActMd)1U)
#define EnumINVActMd_IniUncmplt        ((EnumINVActMd)2U)
#define EnumINVActMd_Standby           ((EnumINVActMd)3U)
#define EnumINVActMd_Run               ((EnumINVActMd)4U)
#define EnumINVActMd_OFF               ((EnumINVActMd)5U)
#define EnumINVActMd_Rsrvd1            ((EnumINVActMd)6U)
#define EnumINVActMd_Rsrvd2            ((EnumINVActMd)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumGrShftLvrPstnReq_
#define DEFINED_TYPEDEF_FOR_EnumGrShftLvrPstnReq_

/* N/A */
typedef uint8 EnumGrShftLvrPstnReq;

/* enum EnumGrShftLvrPstnReq */
#define EnumGrShftLvrPstnReq_Invalid   ((EnumGrShftLvrPstnReq)0U) /* Default value */
#define EnumGrShftLvrPstnReq_DfltPstn  ((EnumGrShftLvrPstnReq)1U)
#define EnumGrShftLvrPstnReq_F1        ((EnumGrShftLvrPstnReq)2U)
#define EnumGrShftLvrPstnReq_F2        ((EnumGrShftLvrPstnReq)3U)
#define EnumGrShftLvrPstnReq_R1        ((EnumGrShftLvrPstnReq)4U)
#define EnumGrShftLvrPstnReq_R2        ((EnumGrShftLvrPstnReq)5U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumAVHSt_
#define DEFINED_TYPEDEF_FOR_EnumAVHSt_

/* N/A */
typedef uint8 EnumAVHSt;

/* enum EnumAVHSt */
#define EnumAVHSt_Off                  ((EnumAVHSt)0U)           /* Default value */
#define EnumAVHSt_Ready                ((EnumAVHSt)1U)
#define EnumAVHSt_Clmpng               ((EnumAVHSt)2U)
#define EnumAVHSt_Clmpd                ((EnumAVHSt)3U)
#define EnumAVHSt_Releasing            ((EnumAVHSt)4U)
#define EnumAVHSt_Released             ((EnumAVHSt)5U)
#define EnumAVHSt_Fail                 ((EnumAVHSt)6U)
#define EnumAVHSt_TempOff              ((EnumAVHSt)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumEPBSwSt_
#define DEFINED_TYPEDEF_FOR_EnumEPBSwSt_

/* N/A */
typedef uint8 EnumEPBSwSt;

/* enum EnumEPBSwSt */
#define EnumEPBSwSt_Neutral            ((EnumEPBSwSt)0U)         /* Default value */
#define EnumEPBSwSt_Release            ((EnumEPBSwSt)1U)
#define EnumEPBSwSt_Apply              ((EnumEPBSwSt)2U)
#define EnumEPBSwSt_Invalid            ((EnumEPBSwSt)3U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumEPBSysSt_
#define DEFINED_TYPEDEF_FOR_EnumEPBSysSt_

/* N/A */
typedef uint8 EnumEPBSysSt;

/* enum EnumEPBSysSt */
#define EnumEPBSysSt_NotInit           ((EnumEPBSysSt)0U)        /* Default value */
#define EnumEPBSysSt_Released          ((EnumEPBSysSt)1U)
#define EnumEPBSysSt_Applied           ((EnumEPBSysSt)2U)
#define EnumEPBSysSt_Applying          ((EnumEPBSysSt)3U)
#define EnumEPBSysSt_Releasing         ((EnumEPBSysSt)4U)
#define EnumEPBSysSt_Unknown           ((EnumEPBSysSt)5U)
#define EnumEPBSysSt_TrctnReld         ((EnumEPBSysSt)6U)
#define EnumEPBSysSt_ReprRelng         ((EnumEPBSysSt)7U)
#define EnumEPBSysSt_ReprReld          ((EnumEPBSysSt)8U)
#define EnumEPBSysSt_DrumClmpng        ((EnumEPBSysSt)9U)
#define EnumEPBSysSt_DrumClmpd         ((EnumEPBSysSt)10U)
#define EnumEPBSysSt_ReqBrk            ((EnumEPBSysSt)11U)
#define EnumEPBSysSt_DynBrk            ((EnumEPBSysSt)12U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumACCMode_
#define DEFINED_TYPEDEF_FOR_EnumACCMode_

/* N/A */
typedef uint8 EnumACCMode;

/* enum EnumACCMode */
#define EnumACCMode_Off                ((EnumACCMode)0U)         /* Default value */
#define EnumACCMode_Passive            ((EnumACCMode)1U)
#define EnumACCMode_Standby            ((EnumACCMode)2U)
#define EnumACCMode_Active             ((EnumACCMode)3U)
#define EnumACCMode_StandWait          ((EnumACCMode)4U)
#define EnumACCMode_Override           ((EnumACCMode)5U)
#define EnumACCMode_StandStill         ((EnumACCMode)6U)
#define EnumACCMode_Failure            ((EnumACCMode)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBMSDCSMd_
#define DEFINED_TYPEDEF_FOR_EnumBMSDCSMd_

/* N/A */
typedef uint8 EnumBMSDCSMd;

/* enum EnumBMSDCSMd */
#define EnumBMSDCSMd_OFF               ((EnumBMSDCSMd)0U)        /* Default value */
#define EnumBMSDCSMd_Standby           ((EnumBMSDCSMd)1U)
#define EnumBMSDCSMd_Connectng2Chrg    ((EnumBMSDCSMd)2U)
#define EnumBMSDCSMd_Connected2Chrg    ((EnumBMSDCSMd)3U)
#define EnumBMSDCSMd_ConnectChrgFail   ((EnumBMSDCSMd)4U)
#define EnumBMSDCSMd_ChrgnginPrgs      ((EnumBMSDCSMd)5U)
#define EnumBMSDCSMd_ChrgngFinshd      ((EnumBMSDCSMd)6U)
#define EnumBMSDCSMd_EmgcySdn          ((EnumBMSDCSMd)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBMSRunSt_
#define DEFINED_TYPEDEF_FOR_EnumBMSRunSt_

/* N/A */
typedef uint8 EnumBMSRunSt;

/* enum EnumBMSRunSt */
#define EnumBMSRunSt_Invld             ((EnumBMSRunSt)0U)        /* Default value */
#define EnumBMSRunSt_OFF               ((EnumBMSRunSt)1U)
#define EnumBMSRunSt_PwrHld            ((EnumBMSRunSt)2U)
#define EnumBMSRunSt_Norm              ((EnumBMSRunSt)3U)
#define EnumBMSRunSt_Standby           ((EnumBMSRunSt)4U)
#define EnumBMSRunSt_ChrgHeating       ((EnumBMSRunSt)5U)
#define EnumBMSRunSt_Rsrvd2            ((EnumBMSRunSt)6U)
#define EnumBMSRunSt_Rsrvd3            ((EnumBMSRunSt)7U)
#endif

#ifndef DEFINED_TYPEDEF_FOR_EnumBMSACChrgSt_
#define DEFINED_TYPEDEF_FOR_EnumBMSACChrgSt_

/* N/A */
typedef uint8 EnumBMSACChrgSt;

/* enum EnumBMSACChrgSt */
#define EnumBMSACChrgSt_ChrgOff        ((EnumBMSACChrgSt)0U)     /* Default value */
#define EnumBMSACChrgSt_ChrgInPrgs     ((EnumBMSACChrgSt)1U)
#define EnumBMSACChrgSt_ChrgRdy        ((EnumBMSACChrgSt)2U)
#define EnumBMSACChrgSt_ChrgFinshd     ((EnumBMSACChrgSt)3U)
#define EnumBMSACChrgSt_FailrStop      ((EnumBMSACChrgSt)4U)
#define EnumBMSACChrgSt_Standby        ((EnumBMSACChrgSt)5U)
#define EnumBMSACChrgSt_DisChrgRdy     ((EnumBMSACChrgSt)6U)
#define EnumBMSACChrgSt_DisChrging     ((EnumBMSACChrgSt)7U)
#define EnumBMSACChrgSt_DisChrgFinshd  ((EnumBMSACChrgSt)8U)
#define EnumBMSACChrgSt_Rsrvd1         ((EnumBMSACChrgSt)9U)
#define EnumBMSACChrgSt_Rsrvd2         ((EnumBMSACChrgSt)10U)
#define EnumBMSACChrgSt_Rsrvd3         ((EnumBMSACChrgSt)11U)
#define EnumBMSACChrgSt_Rsrvd4         ((EnumBMSACChrgSt)12U)
#define EnumBMSACChrgSt_Rsrvd5         ((EnumBMSACChrgSt)13U)
#define EnumBMSACChrgSt_Rsrvd6         ((EnumBMSACChrgSt)14U)
#define EnumBMSACChrgSt_Invld          ((EnumBMSACChrgSt)15U)
#endif
#endif                                 /* RTW_HEADER_AppSwcIpm_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
