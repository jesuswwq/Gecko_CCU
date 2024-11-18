/*
 * File: AppSwcBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1500
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 13 14:02:59 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AppSwcBcm.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "calPrmsBcm.h"
#include "monPrmsBcm.h"

/* Named constants for Chart: '<S152>/Chart6' */
#define AppSwcBcm_IN_Off               ((uint8)1U)
#define AppSwcBcm_IN_On                ((uint8)2U)

/* Named constants for Chart: '<S10>/DrvWinCtl' */
#define AppSwcBcm_IN_AutoDown          ((uint8)1U)
#define AppSwcBcm_IN_ManDown           ((uint8)2U)
#define AppSwcBcm_IN_ManUp             ((uint8)3U)
#define AppSwcBcm_IN_Standby           ((uint8)4U)

/* Named constants for Chart: '<S10>/PsgWinCtl' */
#define AppSwcBcm_IN_AutoDown_n        ((uint8)1U)
#define AppSwcBcm_IN_ManDown_k         ((uint8)2U)
#define AppSwcBcm_IN_ManUp_g           ((uint8)3U)
#define AppSwcBcm_IN_Standby_j         ((uint8)4U)

/* Named constants for Chart: '<S152>/Chart1' */
#define AppSwcBcm_IN_Off_m             ((uint8)1U)
#define AppSwcBcm_IN_On_k              ((uint8)2U)

/* Named constants for Chart: '<S216>/Chart' */
#define AppSwcBcm_IN_FobidKey          ((uint8)1U)
#define AppSwcBcm_IN_Init              ((uint8)2U)
#define AppSwcBcm_IN_RelesKey          ((uint8)3U)

/* Named constants for Chart: '<S217>/Chart' */
#define AppSwcBcm_IN_Init_l            ((uint8)1U)
#define AppSwcBcm_IN_KeyNotInCar       ((uint8)2U)

/* Named constants for Chart: '<S217>/Chart3' */
#define AppSwcBcm_IN_Finish            ((uint8)1U)
#define AppSwcBcm_IN_KeyValid          ((uint8)3U)

/* Named constants for Chart: '<S218>/Chart' */
#define AppSwcBcm_IN_LSeekKeyOut       ((uint8)2U)
#define AppSwcBcm_IN_RSeekKeyOut       ((uint8)3U)

/* Named constants for Chart: '<S218>/Chart3' */
#define AppSwcBcm_IN_KeyValid_g        ((uint8)2U)

/* Named constants for Chart: '<S219>/Chart' */
#define AppSwcBcm_IN_PSSeekKeyOut      ((uint8)2U)

/* Named constants for Chart: '<S219>/Chart1' */
#define AppSwcBcm_IN_IMMOKeyValid      ((uint8)1U)
#define AppSwcBcm_IN_RemoteKeyValid    ((uint8)3U)

/* Named constants for Chart: '<S219>/Chart2' */
#define AppSwcBcm_IN_NokeyTimecount    ((uint8)2U)
#define AppSwcBcm_IN_SendKeyCloser     ((uint8)3U)
#define AppSwcBcm_IN_SendNOKey         ((uint8)4U)

/* Named constants for Chart: '<S220>/Chart' */
#define AppSwcBcm_IN_LockWlcm          ((uint8)2U)
#define AppSwcBcm_IN_UnlockDay0to7     ((uint8)3U)
#define AppSwcBcm_IN_UnlockExcedDay7   ((uint8)4U)
#define AppSwcBcm_IN_WlcmLockReq       ((uint8)5U)
#define AppSwcBcm_IN_WlcmUnlockReq     ((uint8)6U)

/* Named constants for Chart: '<S283>/Alarm' */
#define AppSwcBcm_IN_SetON             ((uint8)1U)
#define AppSwcBcm_IN_SetOff            ((uint8)2U)

/* Named constants for Chart: '<S291>/Seek' */
#define AppSwcBcm_IN_RKESetON          ((uint8)1U)
#define AppSwcBcm_IN_TboxSetON         ((uint8)3U)

/* Named constants for Chart: '<S292>/Chart' */
#define AppSwcBcm_IN_Delay             ((uint8)1U)
#define AppSwcBcm_IN_SetOn             ((uint8)3U)

/* Named constants for Chart: '<S326>/Chart' */
#define AppSwcBcm_IN_Off_a             ((uint8)1U)
#define AppSwcBcm_IN_On_j              ((uint8)2U)

/* Named constants for Chart: '<S330>/Chart' */
#define AppSwcBcm_IN_Day               ((uint8)1U)
#define AppSwcBcm_IN_Night             ((uint8)2U)

/* Named constants for Chart: '<S449>/Chart' */
#define AppSwcBcm_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define AppSwcBcm_IN_SetOff_n          ((uint8)1U)
#define AppSwcBcm_IN_SetOn_o           ((uint8)2U)

/* Named constants for Chart: '<S450>/Chart' */
#define AppSwcBcm_IN_Off_ah            ((uint8)1U)
#define AppSwcBcm_IN_On_i              ((uint8)2U)

/* Named constants for Chart: '<S452>/Chart' */
#define AppSwcBcm_IN_CrashDelay        ((uint8)1U)
#define AppSwcBcm_IN_CrashOff          ((uint8)2U)
#define AppSwcBcm_IN_CrashOn           ((uint8)3U)

/* Named constants for Chart: '<S351>/HazardLightLogic' */
#define AppSwcBcm_IN_EmerON            ((uint8)1U)
#define AppSwcBcm_IN_OFF               ((uint8)2U)
#define AppSwcBcm_IN_ON                ((uint8)3U)

/* Named constants for Chart: '<S456>/Chart' */
#define AppSwcBcm_IN_SetOn1            ((uint8)2U)
#define AppSwcBcm_IN_SetOn2            ((uint8)3U)

/* Named constants for Chart: '<S460>/Chart' */
#define AppSwcBcm_IN_Delay_b           ((uint8)1U)
#define AppSwcBcm_IN_SetOff_c          ((uint8)2U)
#define AppSwcBcm_IN_SetOn_j           ((uint8)3U)

/* Named constants for Chart: '<S351>/TurnIndcrArb2' */
#define AppSwcBcm_IN_AntiLck           ((uint8)1U)
#define AppSwcBcm_IN_Armed             ((uint8)2U)
#define AppSwcBcm_IN_Disarmed          ((uint8)3U)
#define AppSwcBcm_IN_PartArmed         ((uint8)4U)
#define AppSwcBcm_IN_Pri1              ((uint8)1U)
#define AppSwcBcm_IN_Pri2              ((uint8)2U)
#define AppSwcBcm_IN_Pri3              ((uint8)3U)
#define AppSwcBcm_IN_Pri4              ((uint8)4U)
#define AppSwcBcm_IN_Pri5              ((uint8)5U)
#define AppSwcBcm_IN_RodBeam           ((uint8)5U)
#define AppSwcBcm_IN_Seek              ((uint8)6U)
#define AppSwcBcm_IN_Trans             ((uint8)6U)
#define AppSwcBcm_IN_Trans_p           ((uint8)7U)
#define AppSwcBcm_IN_TrunkWarn         ((uint8)8U)
#define AppSwcBcm_IN_VehMode           ((uint8)9U)

/* Named constants for Chart: '<S351>/TurnIndcrLogic' */
#define AppSwcBcm_IN_LongFlash         ((uint8)1U)
#define AppSwcBcm_IN_OFF_d             ((uint8)1U)
#define AppSwcBcm_IN_ShortFlash        ((uint8)2U)
#define AppSwcBcm_IN_TurnL             ((uint8)2U)
#define AppSwcBcm_IN_TurnR             ((uint8)3U)

/* Named constants for Chart: '<S351>/TurnIndcrSelect' */
#define AppSwcBcm_IN_TurnLOn           ((uint8)2U)
#define AppSwcBcm_IN_TurnLROn          ((uint8)3U)
#define AppSwcBcm_IN_TurnROn           ((uint8)4U)

/* Named constants for Chart: '<S467>/Chart' */
#define AppSwcBcm_IN_Init_li           ((uint8)1U)
#define AppSwcBcm_IN_Limit             ((uint8)2U)
#define AppSwcBcm_IN_Nrm               ((uint8)3U)
#define AppSwcBcm_IN_Show              ((uint8)4U)

/* Named constants for Chart: '<S468>/Chart' */
#define AppSwcBcm_IN_RKESetOn          ((uint8)1U)
#define AppSwcBcm_IN_TboxSetOn         ((uint8)3U)

/* Named constants for Chart: '<S468>/SeekFb' */
#define AppSwcBcm_IN_Fail              ((uint8)1U)
#define AppSwcBcm_IN_Init_b            ((uint8)2U)
#define AppSwcBcm_IN_Suc               ((uint8)3U)
#define AppSwcBcm_IN_Wait              ((uint8)4U)

/* Named constants for Chart: '<S589>/Chart' */
#define AppSwcBcm_IN_HiSpd             ((uint8)1U)
#define AppSwcBcm_IN_Inr               ((uint8)2U)
#define AppSwcBcm_IN_LowSpd            ((uint8)3U)
#define AppSwcBcm_IN_Maint             ((uint8)1U)
#define AppSwcBcm_IN_Mist              ((uint8)4U)
#define AppSwcBcm_IN_NO_ACTIVE_CHILD_a ((uint8)0U)
#define AppSwcBcm_IN_Nrm_k             ((uint8)2U)
#define AppSwcBcm_IN_Off_h             ((uint8)5U)
#define AppSwcBcm_IN_Wash              ((uint8)3U)

/* Named constants for Chart: '<S636>/AlmSysLogic' */
#define AppSwcBcm_IN_Alarm             ((uint8)1U)
#define AppSwcBcm_IN_Armed_a           ((uint8)2U)
#define AppSwcBcm_IN_Disarmed_e        ((uint8)3U)
#define AppSwcBcm_IN_Init_h            ((uint8)4U)
#define AppSwcBcm_IN_PartArmed_j       ((uint8)5U)

/* Named constants for Chart: '<S639>/DoorDrv' */
#define AppSwcBcm_IN_DrvIdle           ((uint8)1U)
#define AppSwcBcm_IN_InsDrvLck         ((uint8)2U)
#define AppSwcBcm_IN_InsDrvUnlck       ((uint8)3U)
#define AppSwcBcm_IN_OsDrvLck          ((uint8)4U)
#define AppSwcBcm_IN_OsDrvUnlck        ((uint8)5U)
#define AppSwcBcm_IN_TrunkUnlck        ((uint8)6U)

/* Named constants for Chart: '<S692>/Chart' */
#define AppSwcBcm_IN_Fail1             ((uint8)1U)
#define AppSwcBcm_IN_Init1             ((uint8)2U)
#define AppSwcBcm_IN_Suc1              ((uint8)3U)
#define AppSwcBcm_IN_Wait1             ((uint8)4U)

/* Named constants for Chart: '<S643>/Chart' */
#define AppSwcBcm_IN_LocalOn           ((uint8)1U)
#define AppSwcBcm_IN_OTA1On            ((uint8)2U)
#define AppSwcBcm_IN_OTAOn             ((uint8)3U)
#define AppSwcBcm_IN_PSOff             ((uint8)4U)
#define AppSwcBcm_IN_RemoteOn          ((uint8)5U)

/* Named constants for Chart: '<S867>/BrkPwrOn' */
#define AppSwcBcm_IN_Invalid           ((uint8)1U)
#define AppSwcBcm_IN_Valid             ((uint8)2U)

/* Named constants for Chart: '<S867>/RemoteLck' */
#define AppSwcBcm_IN_Init_n            ((uint8)1U)
#define AppSwcBcm_IN_Lck               ((uint8)2U)
#define AppSwcBcm_IN_Unlck             ((uint8)3U)

/* Named constants for Chart: '<S643>/RemtPwrCtlFb' */
#define AppSwcBcm_IN_Fail_g            ((uint8)1U)
#define AppSwcBcm_IN_Init_be           ((uint8)2U)
#define AppSwcBcm_IN_Suc_c             ((uint8)3U)
#define AppSwcBcm_IN_Wait_l            ((uint8)4U)

/* Named constants for Chart: '<S129>/Chart' */
#define AppSwcBcm_IN_Off_j             ((uint8)1U)
#define AppSwcBcm_IN_On_e              ((uint8)2U)

/* Named constants for Chart: '<S129>/HeatFb' */
#define AppSwcBcm_IN_Fail_j            ((uint8)1U)
#define AppSwcBcm_IN_Init_d            ((uint8)2U)
#define AppSwcBcm_IN_Suc_n             ((uint8)3U)
#define AppSwcBcm_IN_Wait_g            ((uint8)4U)

/* Named constants for Chart: '<S137>/HeatSet' */
#define AppSwcBcm_IN_OFF_b             ((uint8)1U)
#define AppSwcBcm_IN_ON_j              ((uint8)2U)

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S327>/Constant28' */

/* Invariant block signals (default storage) */
const ConstB_AppSwcBcm_T AppSwcBcm_ConstB = {
  1.33399987F,                         /* '<S391>/Product' */
  -1.33399987F,                        /* '<S391>/Product1' */
  0U,                                  /* '<S238>/Data Type Conversion39' */
  0,                                   /* '<S867>/Relational Operator7' */
  0,                                   /* '<S866>/Relational Operator13' */
  1,                                   /* '<S697>/Relational Operator1' */
  1,                                   /* '<S727>/Relational Operator6' */
  1,                                   /* '<S373>/Relational Operator' */
  1                                    /* '<S374>/Relational Operator1' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_AppSwcBcm_T AppSwcBcm_ARID_DEF;
static float32 look1_iflf_binlca(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex);
static uint8 AppSwcBcm_BitShift(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift1(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift10(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift11(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift12(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift13(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift14(uint8 rtu_u);
static uint8 AppSwcBcm_BitShift15(uint8 rtu_u);
static void AppSwcBcm_Lib_RiseEdgeDet_Reset(ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_RiseEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_SR_Reset(ARID_DEF_Lib_SR_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_SR(boolean rtu_S, boolean rtu_R, boolean *rty_Q,
  ARID_DEF_Lib_SR_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDet_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg);
static uint16 AppSwcBcm_BitShift1_k(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u);
static void AppSwcBcm_Lib_RiseEdgeDet_h(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_c_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Chart6_Init(boolean *rty_Lib_Out);
static void AppSwcBcm_Chart6(boolean rtu_Lib_blIn1, boolean rtu_Lib_blIn2, uint8
  rtu_Lib_blIn3, boolean *rty_Lib_Out, ARID_DEF_Chart6_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_NegPluse_Init(boolean *rty_LIB_blOut);
static void AppSwcBcm_LIB_NegPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_NegPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_PosPluse_Init(boolean *rty_LIB_blOut);
static void AppSwcBcm_LIB_PosPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_PosPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDelay_Init(boolean *rty_LIB_blOut);
static void AppSwcBcm_Lib_RiseEdgeDelay(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16DelayTim, boolean *rty_LIB_blOut,
  ARID_DEF_Lib_RiseEdgeDelay_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_e_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_n(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_f_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_nw(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDet_g(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_o_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_Pulse_Init(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt);
static void AppSwcBcm_LIB_Pulse_Reset(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_Pulse(uint16 rtu_LIB_u16PrdDemCnt, uint16
  rtu_LIB_u16Prd, uint16 rtu_LIB_u16Wdt, boolean rtu_LIB_blReset, boolean
  *rty_LIB_blOut, uint16 *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_TruthTable(boolean rtu_BSD_LightOn, boolean
  rtu_BSD_LightFlash, uint16 *rty_BSD_LightPrd, uint16 *rty_BSD_LightWdt);
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_Update(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut);
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static uint16 AppSwcBcm_BitShift10_b(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift11_p(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3_d(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u);
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
  (ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
   *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(boolean rtu_Lib_blIn,
  boolean *rty_Lib_blOut, ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_ChangeEdge_Init(ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_ChangeEdge(float32 rtu_Lib_In, float32 rtu_Lib_InNow,
  float32 rtu_Lib_InBefore, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y);
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_TurnIndcrDig_Init(boolean *rty_LIB_blErrFlg);
static void AppSwcBcm_TurnIndcrDig(boolean rtu_LIB_blIn, boolean rtu_LIB_blIn2,
  boolean rtu_LIB_blRst, float32 rtu_LIB_s32Ts, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, uint8 rtu_LIB_u8Cnt, boolean *rty_LIB_blErrFlg,
  ARID_DEF_TurnIndcrDig_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_k_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_nr(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_k_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg);
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_h_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_TPD_10ms1_m_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms1_h(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  rtu_LIB_bInit, boolean *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_h_T *
  AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_FailEdgeDet_jv(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_c_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_EEWriteCtl(void);
static void AppSwcBcm_IODID(void);
static void AppSwcBcm_RVMCtl(void);
static void AppSwcBcm_DrvWinCtl(void);
static void AppSwcBcm_PsgWinCtl(void);
static void AppSwcBcm_SigProc(void);
static void AppSwcBcm_WinMotorProt(void);
static void AppSwcBcm_WinSwArb_Init(void);
static void AppSwcBcm_WinSwArb(void);
static void AppSwcBcm_WinCtl_Init(void);
static void AppSwcBcm_WinCtl(void);
static void AppSwcBcm_PEPSCtl_Update(void);
static void AppSwcBcm_PEPSCtl(void);
static void AppSwcBcm_HwOutBCM(void);
static void AppSwcBcm_BCMTx_Init(void);
static void AppSwcBcm_BCMTx(void);
static void AppSwcBcm_EEReadCtl(void);
static void AppSwcBcm_HornCtl_Init(void);
static void AppSwcBcm_HornCtl(void);
static void AppSwcBcm_ADASLampCtl_Init(void);
static void AppSwcBcm_ADASLampCtl(void);
static void AppSwcBcm_AutoLampCtl_Init(void);
static void AppSwcBcm_AutoLampCtl(void);
static void AppSwcBcm_BackLampCtl_Init(void);
static void AppSwcBcm_BackLampCtl(void);
static void AppSwcBcm_BoxLampCtl_Init(void);
static void AppSwcBcm_BoxLampCtl_Update(void);
static void AppSwcBcm_BoxLampCtl(void);
static void AppSwcBcm_DayRunLampCtl(void);
static void AppSwcBcm_DomeLampCtl_Init(void);
static void AppSwcBcm_DomeLampCtl_Update(void);
static void AppSwcBcm_DomeLampCtl(void);
static void AppSwcBcm_FogLampRCtl(void);
static void AppSwcBcm_HiBeamCtl(void);
static void AppSwcBcm_KnobBeamDig(void);
static void AppSwcBcm_LampDelayCtl_Init(void);
static void AppSwcBcm_LampDelayCtl_Update(void);
static void AppSwcBcm_LampDelayCtl(void);
static void AppSwcBcm_LightIntstDet(void);
static void AppSwcBcm_LowBeamCtl_Init(void);
static void AppSwcBcm_LowBeamCtl(void);
static void AppSwcBcm_BrakeLampCtl(void);
static void AppSwcBcm_ReverseLampCtl(void);
static void AppSwcBcm_PassLampFunc(void);
static void AppSwcBcm_PosLampCtl_Init(void);
static void AppSwcBcm_PosLampCtl(void);
static void AppSwcBcm_SignalProcess_Init(void);
static void AppSwcBcm_SignalProcess(void);
static void AppSwcBcm_TurnIndcrCtl_Init(void);
static void AppSwcBcm_TurnIndcrCtl(void);
static void AppSwcBcm_Lib_RiseEdgeDet_c(void);
static void AppSwcBcm_Lib_ChangeEdge_p(void);
static void AppSwcBcm_WelcomeLampCtl_Init(void);
static void AppSwcBcm_WelcomeLampCtl(void);
static void AppSwcBcm_LampCtl_Init(void);
static void AppSwcBcm_LampCtl_Update(void);
static void AppSwcBcm_LampCtl(void);
static void AppSwcBcm_LockedRotorProt_Init(void);
static void AppSwcBcm_LockedRotorProt(void);
static void AppSwcBcm_SignalProcess_m(void);
static void AppSwcBcm_WashCtl_Init(void);
static void AppSwcBcm_WashCtl(void);
static void AppSwcBcm_WiperDrv_Init(void);
static void AppSwcBcm_WiperDrv(void);
static void AppSwcBcm_WiperHiSpdCtl(void);
static void AppSwcBcm_WiperInrCtl_Init(void);
static void AppSwcBcm_WiperInrCtl(void);
static void AppSwcBcm_WiperLowSpdCtl(void);
static void AppSwcBcm_WiperMaintCtl(void);
static void AppSwcBcm_WiperMistCtl(void);
static void AppSwcBcm_WiperOffCtl(void);
static void AppSwcBcm_WiperCtl_Init(void);
static void AppSwcBcm_WiperCtl(void);
static void AppSwcBcm_AlmSysLogic_Init(void);
static void AppSwcBcm_AlmSysLogic(void);
static void AppSwcBcm_AlmSysCtl_Init(void);
static void AppSwcBcm_AlmSysCtl(void);
static void AppSwcBcm_BatSaveCtl_Init(void);
static void AppSwcBcm_BatSaveCtl(void);
static void AppSwcBcm_DTCCtl(void);
static void AppSwcBcm_DoorDrv_Init(void);
static void AppSwcBcm_DoorDrv(void);
static void AppSwcBcm_DoorLckCtlLogic_Init(void);
static void AppSwcBcm_DoorLckCtlLogic_Const(void);
static void AppSwcBcm_DoorLckCtlLogic(void);
static void AppSwcBcm_SignalProcess_f_Const(void);
static void AppSwcBcm_SignalProcess_n(void);
static void AppSwcBcm_DoorLckCtl_Init(void);
static void AppSwcBcm_DoorLckCtl_Const(void);
static void AppSwcBcm_DoorLckCtl(void);
static void AppSwcBcm_ESCLCtl_Init(void);
static void AppSwcBcm_ESCLCtl(void);
static void AppSwcBcm_IMMOCtl_Init(void);
static void AppSwcBcm_IMMOCtl(void);
static void AppSwcBcm_Chart(void);
static void AppSwcBcm_PwrOff_Init(void);
static void AppSwcBcm_PwrOff(void);
static void AppSwcBcm_PwrOn(void);
static void AppSwcBcm_RelayDig(void);
static void AppSwcBcm_StartReq_Init(void);
static void AppSwcBcm_StartReq(void);
static void AppSwcBcm_Subsystem(void);
static void AppSwcBcm_TruthTable_n(void);
static void AppSwcBcm_PDUCtl_Init(void);
static void AppSwcBcm_PDUCtl(void);
static void AppSwcBcm_NMCtl_Init(void);
static void AppSwcBcm_NMCtl_Update(void);
static void AppSwcBcm_NMCtl(void);
static void AppSwcBcm_SleepCtl_Init(void);
static void AppSwcBcm_SleepCtl_Update(void);
static void AppSwcBcm_SleepCtl(void);
static void AppSwcBcm_WakeUpCtl_Init(void);
static void AppSwcBcm_WakeUpCtl_Update(void);
static void AppSwcBcm_WakeUpCtl(void);

/* Forward declaration for local functions */
static boolean AppSwcBcm_EmerOff(void);
static boolean AppSwcBcm_HazardOff(void);
static boolean AppSwcBcm_TurnOff(void);
static void AppSwcBcm_TurnFunc(void);
static void AppSwcBcm_Pri1Func(void);
static void AppSwcBcm_EnFunc(void);
static void AppSwcBcm_Pri2Func(void);
static void AppSwcBcm_Pri4Func(void);
static void AppSwcBcm_VehModeFunc(void);
static void AppSwcBcm_AntiLckFunc(void);
static void AppSwcBcm_ArmedFunc(void);
static void AppSwcBcm_DisarmedFunc(void);
static void AppSwcBcm_PartArmedFunc(void);
static void AppSwcBcm_RodBeamFunc(void);
static void AppSwcBcm_SeekFunc(void);
static void AppSwcBcm_TrunkWarnFunc(void);
static void AppSwcBcm_CrashClearFunc(void);

/* Forward declaration for local functions */
static void AppSwcBcm_enter_internal_Inr(void);
static void AppSwcBcm_HiSpdFunc(void);
static void AppSwcBcm_Nrm(void);

/* Forward declaration for local functions */
static void AppSwcBcm_AlmWarn(void);

/* Forward declaration for local functions */
static void AppSwcBcm_TrunkStaFunc(void);
static void AppSwcBcm_InsLckFunc(void);
static void AppSwcBcm_InsUnlckFunc(void);
static void AppSwcBcm_OsLckFunc(void);
static void AppSwcBcm_OsUnlckFunc(void);
static float32 look1_iflf_binlca(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

/* Output and update for atomic system: '<S1>/EEWriteCtl' */
static void AppSwcBcm_EEWriteCtl(void)
{
  uint16 tmp;
  uint8 i;

  /* Chart: '<S5>/EEWriteCtl' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   * */
  i = 0U;
  if (EEWriteCtl_ImmOvrdFlg_C) {
    NvmBcmBlock_Imm_WriteData((uint8 *)(const uint8 *)&EEWriteCtl_ImmOvrdVal_C[0],
      128U);
  } else {
    AppSwcBcm_ARID_DEF.data1_o[0] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->CrashSta;
    AppSwcBcm_ARID_DEF.data1_o[1] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())->BodyWarnSts;
    AppSwcBcm_ARID_DEF.data1_o[2] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->FlwrMeHomeCtlFb;
    AppSwcBcm_ARID_DEF.data1_o[3] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->BackLadjvalFb;
    AppSwcBcm_ARID_DEF.data1_o[4] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->HazardLightSta;
    AppSwcBcm_ARID_DEF.data1_o[5] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->IllmndLckSts;
    AppSwcBcm_ARID_DEF.data1_o[6] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->IllmndUnlockSts;
    AppSwcBcm_ARID_DEF.data1_o[7] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->SpdCtlLckSet;
    AppSwcBcm_ARID_DEF.data1_o[8] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;
    AppSwcBcm_ARID_DEF.data1_o[9] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_HornCtl_Bus())->LockHoornOnSt;
    AppSwcBcm_ARID_DEF.data1_o[10] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus())->WiprIntlTimeSetFb;
    tmp = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus())->InrTim;
    if (tmp > 255) {
      tmp = 255U;
    }

    AppSwcBcm_ARID_DEF.data1_o[11] = (uint8)tmp;
    AppSwcBcm_ARID_DEF.data1_o[12] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkLckSw;
    AppSwcBcm_ARID_DEF.data1_o[13] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DriverDoorLckSw;
    AppSwcBcm_ARID_DEF.data1_o[14] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarFLSw;
    AppSwcBcm_ARID_DEF.data1_o[15] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarFRSw;
    AppSwcBcm_ARID_DEF.data1_o[16] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkSw;
    AppSwcBcm_ARID_DEF.data1_o[17] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarRLSw;
    AppSwcBcm_ARID_DEF.data1_o[18] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarRRSw;
    AppSwcBcm_ARID_DEF.data1_o[19] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkAjarSw;
    AppSwcBcm_ARID_DEF.data1_o[20] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DrvSeatSw;
    AppSwcBcm_ARID_DEF.data1_o[21] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->RemotePwrLckSta;
    while (i < 10) {
      AppSwcBcm_ARID_DEF.data1_o[i + 29] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF230DoorOpRecord[i];
      AppSwcBcm_ARID_DEF.data1_o[i + 39] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF233RemoteStartUpFailRecord[i];
      AppSwcBcm_ARID_DEF.data1_o[i + 49] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF231TrunkOpRecord[i];
      AppSwcBcm_ARID_DEF.data1_o[i + 59] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF232LocalStartUpFailRecord[i];
      i++;
    }
  }

  /* NvmBcmBlock02WriteData(data,8); */
  NvmBcmBlock_Imm_WriteData((uint8 *)&AppSwcBcm_ARID_DEF.data1_o[0], 128U);

  /* End of Chart: '<S5>/EEWriteCtl' */
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift'
 *    '<S6>/Bit Shift22'
 *    '<S6>/Bit Shift30'
 *    '<S6>/Bit Shift38'
 *    '<S6>/Bit Shift46'
 *    '<S6>/Bit Shift54'
 *    '<S6>/Bit Shift8'
 */
static uint8 AppSwcBcm_BitShift(uint8 rtu_u)
{
  /* MATLAB Function: '<S12>/bit_shift' */
  return rtu_u;
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift1'
 *    '<S6>/Bit Shift23'
 *    '<S6>/Bit Shift31'
 *    '<S6>/Bit Shift39'
 *    '<S6>/Bit Shift47'
 *    '<S6>/Bit Shift55'
 *    '<S6>/Bit Shift9'
 */
static uint8 AppSwcBcm_BitShift1(uint8 rtu_u)
{
  /* MATLAB Function: '<S13>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift10'
 *    '<S6>/Bit Shift16'
 *    '<S6>/Bit Shift2'
 *    '<S6>/Bit Shift24'
 *    '<S6>/Bit Shift32'
 *    '<S6>/Bit Shift40'
 *    '<S6>/Bit Shift48'
 */
static uint8 AppSwcBcm_BitShift10(uint8 rtu_u)
{
  /* MATLAB Function: '<S14>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 2);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift11'
 *    '<S6>/Bit Shift17'
 *    '<S6>/Bit Shift25'
 *    '<S6>/Bit Shift3'
 *    '<S6>/Bit Shift33'
 *    '<S6>/Bit Shift41'
 *    '<S6>/Bit Shift49'
 */
static uint8 AppSwcBcm_BitShift11(uint8 rtu_u)
{
  /* MATLAB Function: '<S15>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift12'
 *    '<S6>/Bit Shift18'
 *    '<S6>/Bit Shift26'
 *    '<S6>/Bit Shift34'
 *    '<S6>/Bit Shift4'
 *    '<S6>/Bit Shift42'
 *    '<S6>/Bit Shift50'
 */
static uint8 AppSwcBcm_BitShift12(uint8 rtu_u)
{
  /* MATLAB Function: '<S16>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift13'
 *    '<S6>/Bit Shift19'
 *    '<S6>/Bit Shift27'
 *    '<S6>/Bit Shift35'
 *    '<S6>/Bit Shift43'
 *    '<S6>/Bit Shift5'
 *    '<S6>/Bit Shift51'
 */
static uint8 AppSwcBcm_BitShift13(uint8 rtu_u)
{
  /* MATLAB Function: '<S17>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift14'
 *    '<S6>/Bit Shift20'
 *    '<S6>/Bit Shift28'
 *    '<S6>/Bit Shift36'
 *    '<S6>/Bit Shift44'
 *    '<S6>/Bit Shift52'
 *    '<S6>/Bit Shift6'
 */
static uint8 AppSwcBcm_BitShift14(uint8 rtu_u)
{
  /* MATLAB Function: '<S18>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 6);
}

/*
 * Output and update for atomic system:
 *    '<S6>/Bit Shift15'
 *    '<S6>/Bit Shift21'
 *    '<S6>/Bit Shift29'
 *    '<S6>/Bit Shift37'
 *    '<S6>/Bit Shift45'
 *    '<S6>/Bit Shift53'
 *    '<S6>/Bit Shift7'
 */
static uint8 AppSwcBcm_BitShift15(uint8 rtu_u)
{
  /* MATLAB Function: '<S19>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 7);
}

/* Output and update for atomic system: '<S1>/IODID' */
static void AppSwcBcm_IODID(void)
{
  uint8 rtb_CCaller[2];
  uint8 rtb_CCaller1;
  uint8 rtb_CCaller2;
  uint8 rtb_CCaller3;
  uint8 rtb_CCaller4;
  uint8 rtb_CCaller5;
  uint8 rtb_y;
  uint8 rtb_y_a;
  uint8 rtb_y_a2;
  uint8 rtb_y_ab;
  uint8 rtb_y_aj;
  uint8 rtb_y_aq;
  uint8 rtb_y_b;
  uint8 rtb_y_b5;
  uint8 rtb_y_bf;
  uint8 rtb_y_c;
  uint8 rtb_y_ci;
  uint8 rtb_y_cn;
  uint8 rtb_y_cur;
  uint8 rtb_y_cv;
  uint8 rtb_y_dp;
  uint8 rtb_y_e;
  uint8 rtb_y_ead;
  uint8 rtb_y_ed;
  uint8 rtb_y_ei;
  uint8 rtb_y_es;
  uint8 rtb_y_f;
  uint8 rtb_y_f5;
  uint8 rtb_y_fco;
  uint8 rtb_y_ff;
  uint8 rtb_y_ft;
  uint8 rtb_y_g;
  uint8 rtb_y_h5;
  uint8 rtb_y_hau;
  uint8 rtb_y_hl;
  uint8 rtb_y_i;
  uint8 rtb_y_ik;
  uint8 rtb_y_iq;
  uint8 rtb_y_iv1;
  uint8 rtb_y_k;
  uint8 rtb_y_ka;
  uint8 rtb_y_kl;
  uint8 rtb_y_kt;
  uint8 rtb_y_kyn;
  uint8 rtb_y_l;
  uint8 rtb_y_l2;
  uint8 rtb_y_la;
  uint8 rtb_y_ld;
  uint8 rtb_y_lml;
  uint8 rtb_y_lq;
  uint8 rtb_y_lr;
  uint8 rtb_y_m3;
  uint8 rtb_y_me;
  uint8 rtb_y_ms;
  uint8 rtb_y_mv;
  uint8 rtb_y_n2;
  uint8 rtb_y_nn;
  uint8 rtb_y_no;
  uint8 rtb_y_o;
  uint8 rtb_y_o2;
  uint8 rtb_y_p5;
  uint8 rtb_y_px4;

  /* CCaller: '<S6>/C Caller' */
  App_Call_Event_IODID_0x3231_GetEventStatus(&rtb_CCaller[0]);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift' */
  rtb_y_aq = AppSwcBcm_BitShift(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND' */
  IODID_TurnIndcrLCtlFlg = (uint8)(rtb_y_aq & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift1' */
  rtb_y_aj = AppSwcBcm_BitShift1(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift1' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND1' */
  IODID_TurnIndcrRCtlFlg = (uint8)(rtb_y_aj & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift12' */
  rtb_y_ed = AppSwcBcm_BitShift12(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift12' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND12' */
  IODID_LowBeamCtlFlg = (uint8)(rtb_y_ed & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift13' */
  rtb_y_ld = AppSwcBcm_BitShift13(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift13' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND13' */
  IODID_HiBeamCtlFlg = (uint8)(rtb_y_ld & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift14' */
  rtb_y_ft = AppSwcBcm_BitShift14(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift14' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND14' */
  IODID_FogLampFCtlFlg = (uint8)(rtb_y_ft & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift15' */
  rtb_y_a2 = AppSwcBcm_BitShift15(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift15' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND15' */
  IODID_FogLampRCtlFlg = (uint8)(rtb_y_a2 & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift2' */
  rtb_y_l2 = AppSwcBcm_BitShift10(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift2' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND2' */
  IODID_BackLampCtlFlg = (uint8)(rtb_y_l2 & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift3' */
  rtb_y_lq = AppSwcBcm_BitShift11(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift3' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND3' */
  IODID_BrakeLightCtlFlg = (uint8)(rtb_y_lq & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift5' */
  rtb_y_m3 = AppSwcBcm_BitShift13(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift5' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND5' */
  IODID_ReverseLampCtlFlg = (uint8)(rtb_y_m3 & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift6' */
  rtb_y_fco = AppSwcBcm_BitShift14(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift6' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND6' */
  IODID_DayRunLightCtlFlg = (uint8)(rtb_y_fco & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift7' */
  rtb_y_i = AppSwcBcm_BitShift15(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift7' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND7' */
  IODID_PosLampCtlFlg = (uint8)(rtb_y_i & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift9' */
  rtb_y = AppSwcBcm_BitShift1(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift9' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND9' */
  IODID_DomeLampCtlFlg = (uint8)(rtb_y & 1);

  /* CCaller: '<S6>/C Caller1' */
  App_Call_Event_IODID_0x3232_GetEventStatus(&rtb_CCaller1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift16' */
  rtb_y_bf = AppSwcBcm_BitShift10(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift16' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND16' */
  IODID_DoorUnlckCtlFlg = (uint8)(rtb_y_bf & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift17' */
  rtb_y_p5 = AppSwcBcm_BitShift11(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift17' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND17' */
  IODID_DoorLckCtlFlg = (uint8)(rtb_y_p5 & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift22' */
  rtb_y_b = AppSwcBcm_BitShift(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift22' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND22' */
  IODID_TrunkUnlckCtlFlg = (uint8)(rtb_y_b & 1);

  /* CCaller: '<S6>/C Caller2' */
  App_Call_Event_IODID_0x3233_GetEventStatus(&rtb_CCaller2);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift30' */
  rtb_y_ms = AppSwcBcm_BitShift(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift30' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND30' */
  IODID_WiperHiSpdCtlFlg = (uint8)(rtb_y_ms & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift31' */
  rtb_y_b5 = AppSwcBcm_BitShift1(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift31' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND31' */
  IODID_WiperLowSpdCtlFlg = (uint8)(rtb_y_b5 & 1);

  /* CCaller: '<S6>/C Caller3' */
  App_Call_Event_IODID_0x3234_GetEventStatus(&rtb_CCaller3);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift32' */
  rtb_y_hl = AppSwcBcm_BitShift10(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift32' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND32' */
  IODID_WinFLCtlFlg = (uint8)(rtb_y_hl & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift33' */
  rtb_y_f5 = AppSwcBcm_BitShift11(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift33' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND33' */
  IODID_WinFRCtlFlg = (uint8)(rtb_y_f5 & 1);

  /* CCaller: '<S6>/C Caller4' */
  App_Call_Event_IODID_0x3235_GetEventStatus(&rtb_CCaller4);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift40' */
  rtb_y_h5 = AppSwcBcm_BitShift10(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift40' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND40' */
  IODID_HornCtlFlg = (uint8)(rtb_y_h5 & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift42' */
  rtb_y_ci = AppSwcBcm_BitShift12(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift42' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND42' */
  IODID_BatSaveCtlFlg = (uint8)(rtb_y_ci & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift43' */
  rtb_y_l = AppSwcBcm_BitShift13(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift43' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND43' */
  IODID_BSDRightCtlFlg = (uint8)(rtb_y_l & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift44' */
  rtb_y_dp = AppSwcBcm_BitShift14(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift44' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND44' */
  IODID_BSDLeftCtlFlg = (uint8)(rtb_y_dp & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift46' */
  rtb_y_cur = AppSwcBcm_BitShift(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift46' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND46' */
  IODID_IG1RlyCtlFlg = (uint8)(rtb_y_cur & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift47' */
  rtb_y_iq = AppSwcBcm_BitShift1(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift47' */

  /* S-Function (sfix_bitop): '<S6>/Bitwise AND47' */
  IODID_IG2RlyCtlFlg = (uint8)(rtb_y_iq & 1);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift41' */
  rtb_y_k = AppSwcBcm_BitShift11(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift41' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift45' */
  rtb_y_kl = AppSwcBcm_BitShift15(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift45' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift34' */
  rtb_y_nn = AppSwcBcm_BitShift12(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift34' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift35' */
  rtb_y_kyn = AppSwcBcm_BitShift13(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift35' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift36' */
  rtb_y_es = AppSwcBcm_BitShift14(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift36' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift37' */
  rtb_y_ab = AppSwcBcm_BitShift15(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift37' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift38' */
  rtb_y_me = AppSwcBcm_BitShift(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift38' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift39' */
  rtb_y_e = AppSwcBcm_BitShift1(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift39' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift24' */
  rtb_y_ei = AppSwcBcm_BitShift10(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift24' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift25' */
  rtb_y_c = AppSwcBcm_BitShift11(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift25' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift26' */
  rtb_y_no = AppSwcBcm_BitShift12(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift26' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift27' */
  rtb_y_iv1 = AppSwcBcm_BitShift13(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift27' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift28' */
  rtb_y_o = AppSwcBcm_BitShift14(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift28' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift29' */
  rtb_y_lr = AppSwcBcm_BitShift15(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift29' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift18' */
  rtb_y_ff = AppSwcBcm_BitShift12(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift18' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift19' */
  rtb_y_cv = AppSwcBcm_BitShift13(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift19' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift20' */
  rtb_y_cn = AppSwcBcm_BitShift14(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift20' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift21' */
  rtb_y_ead = AppSwcBcm_BitShift15(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift21' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift23' */
  rtb_y_ik = AppSwcBcm_BitShift1(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift23' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift10' */
  rtb_y_o2 = AppSwcBcm_BitShift10(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift10' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift11' */
  rtb_y_kt = AppSwcBcm_BitShift11(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift4' */
  rtb_y_ka = AppSwcBcm_BitShift12(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift8' */
  rtb_y_f = AppSwcBcm_BitShift(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift8' */

  /* CCaller: '<S6>/C Caller5' */
  App_Call_Event_IODID_0x3236_GetEventStatus(&rtb_CCaller5);

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift48' */
  rtb_y_a = AppSwcBcm_BitShift10(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift48' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift49' */
  rtb_y_px4 = AppSwcBcm_BitShift11(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift49' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift50' */
  rtb_y_la = AppSwcBcm_BitShift12(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift50' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift51' */
  rtb_y_n2 = AppSwcBcm_BitShift13(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift51' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift52' */
  rtb_y_mv = AppSwcBcm_BitShift14(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift52' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift53' */
  rtb_y_g = AppSwcBcm_BitShift15(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift53' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift54' */
  rtb_y_hau = AppSwcBcm_BitShift(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift54' */

  /* Outputs for Atomic SubSystem: '<S6>/Bit Shift55' */
  rtb_y_lml = AppSwcBcm_BitShift1(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift55' */
}

/*
 * System reset for atomic system:
 *    '<S125>/Lib_RiseEdgeDet'
 *    '<S135>/Lib_RiseEdgeDet'
 *    '<S142>/Lib_RiseEdgeDet'
 *    '<S172>/Lib_RiseEdgeDet'
 *    '<S174>/Lib_RiseEdgeDet'
 *    '<S176>/Lib_RiseEdgeDet'
 *    '<S178>/Lib_RiseEdgeDet'
 *    '<S195>/Lib_RiseEdgeDet'
 *    '<S197>/Lib_RiseEdgeDet'
 *    '<S199>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_Reset(ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S127>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S125>/Lib_RiseEdgeDet'
 *    '<S135>/Lib_RiseEdgeDet'
 *    '<S142>/Lib_RiseEdgeDet'
 *    '<S172>/Lib_RiseEdgeDet'
 *    '<S174>/Lib_RiseEdgeDet'
 *    '<S176>/Lib_RiseEdgeDet'
 *    '<S178>/Lib_RiseEdgeDet'
 *    '<S195>/Lib_RiseEdgeDet'
 *    '<S197>/Lib_RiseEdgeDet'
 *    '<S199>/Lib_RiseEdgeDet'
 *    ...
 */
static boolean AppSwcBcm_Lib_RiseEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S127>/Logical Operator' incorporates:
   *  Logic: '<S127>/Logical Operator1'
   *  UnitDelay: '<S127>/Unit Delay'
   */
  rty_Lib_blOut_0 = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S127>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/*
 * System reset for atomic system:
 *    '<S125>/Lib_SR'
 *    '<S322>/Lib_SR'
 *    '<S637>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR_Reset(ARID_DEF_Lib_SR_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S128>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S125>/Lib_SR'
 *    '<S322>/Lib_SR'
 *    '<S637>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR(boolean rtu_S, boolean rtu_R, boolean *rty_Q,
  ARID_DEF_Lib_SR_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Switch: '<S128>/Switch' incorporates:
   *  Constant: '<S128>/Constant'
   *  Logic: '<S128>/Logical Operator'
   *  UnitDelay: '<S128>/Unit Delay'
   */
  if (rtu_R) {
    *rty_Q = false;
  } else {
    *rty_Q = (rtu_S || AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);
  }

  /* End of Switch: '<S128>/Switch' */

  /* Update for UnitDelay: '<S128>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = *rty_Q;
}

/* Output and update for atomic system: '<S1>/RVMCtl' */
static void AppSwcBcm_RVMCtl(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S7>/RVMCtl' incorporates:
   *  EnablePort: '<S125>/Enable'
   */
  if (rtb_RelationalOperator) {
    if (!AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
      /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = false;

      /* SystemReset for Atomic SubSystem: '<S125>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_Reset
        (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oc);

      /* End of SystemReset for SubSystem: '<S125>/Lib_RiseEdgeDet' */

      /* SystemReset for Chart: '<S125>/LIB_Tim' */
      AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;

      /* SystemReset for Atomic SubSystem: '<S125>/Lib_SR' */
      AppSwcBcm_Lib_SR_Reset(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_i);

      /* End of SystemReset for SubSystem: '<S125>/Lib_SR' */
      AppSwcBcm_ARID_DEF.RVMCtl_MODE = true;
    }

    /* RelationalOperator: '<S125>/Relational Operator1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPRrViewMirrHeatgKey_flg;

    /* Outputs for Atomic SubSystem: '<S125>/Lib_RiseEdgeDet' */
    rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oc);

    /* End of Outputs for SubSystem: '<S125>/Lib_RiseEdgeDet' */

    /* Chart: '<S125>/LIB_Tim' incorporates:
     *  Constant: '<S125>/Constant2'
     *  Constant: '<S125>/Constant7'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) {
      if (AppSwcBcm_ARID_DEF.Cnt_M_h >= RVMCtl_MaxHeatTimM_C) {
        rtb_RelationalOperator = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_Tick_a + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_Tick_a + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_Tick_a = (uint16)tmp;
        rtb_RelationalOperator = false;
        if (AppSwcBcm_ARID_DEF.Cnt_Tick_a >= 1.0F / RVMCtl_Ts_C) {
          tmp = AppSwcBcm_ARID_DEF.Cnt_S_b + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_S_b + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_S_b = (uint8)tmp;
          AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
        }

        if (AppSwcBcm_ARID_DEF.Cnt_S_b >= 60) {
          AppSwcBcm_ARID_DEF.Cnt_M_h++;
          AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;
        }

        if (AppSwcBcm_ARID_DEF.Cnt_M_h >= 60) {
          tmp = AppSwcBcm_ARID_DEF.Cnt_H_p + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_H_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_H_p = (uint8)tmp;
          AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
        }
      }
    } else {
      rtb_RelationalOperator = false;
      AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
    }

    /* End of Chart: '<S125>/LIB_Tim' */

    /* Outputs for Atomic SubSystem: '<S125>/Lib_SR' */
    /* Logic: '<S125>/Logical Operator2' incorporates:
     *  Logic: '<S125>/Logical Operator1'
     *  UnitDelay: '<S125>/Unit Delay'
     */
    AppSwcBcm_Lib_SR(rtb_LogicalOperator, (rtb_LogicalOperator &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) || rtb_RelationalOperator,
                     &AppSwcBcm_ARID_DEF.Switch_i,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_i);

    /* End of Outputs for SubSystem: '<S125>/Lib_SR' */

    /* Update for UnitDelay: '<S125>/Unit Delay' */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = AppSwcBcm_ARID_DEF.Switch_i;
  } else if (AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
    /* Disable for Switch: '<S128>/Switch' incorporates:
     *  Outport: '<S125>/RVMCtl_J42Heat'
     */
    AppSwcBcm_ARID_DEF.Switch_i = false;
    AppSwcBcm_ARID_DEF.RVMCtl_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S7>/RVMCtl' */

  /* Outputs for Atomic SubSystem: '<S7>/Ovrd' */
  /* Switch: '<S124>/Switch' incorporates:
   *  Constant: '<S7>/Constant18'
   */
  if (RVMCtl_J42HeatOvrdFlg_C) {
    /* Switch: '<S124>/Switch' incorporates:
     *  Constant: '<S7>/Constant19'
     */
    RVMCtl_J42Heat = RVMCtl_J42HeatOvrdVal_C;
  } else {
    /* Switch: '<S124>/Switch' */
    RVMCtl_J42Heat = AppSwcBcm_ARID_DEF.Switch_i;
  }

  /* End of Switch: '<S124>/Switch' */
  /* End of Outputs for SubSystem: '<S7>/Ovrd' */
}

/*
 * Output and update for function-call system:
 *    '<S131>/Lib_RiseEdgeDet'
 *    '<S139>/Lib_RiseEdgeDet'
 *    '<S168>/Lib_RiseEdgeDet'
 *    '<S169>/Lib_RiseEdgeDet'
 *    '<S170>/Lib_RiseEdgeDet'
 *    '<S171>/Lib_RiseEdgeDet'
 *    '<S182>/Lib_RiseEdgeDet'
 *    '<S183>/Lib_RiseEdgeDet'
 *    '<S184>/Lib_RiseEdgeDet'
 *    '<S185>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S135>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S135>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S10>/DrvWinCtl' */
static void AppSwcBcm_DrvWinCtl(void)
{
  /* Chart: '<S10>/DrvWinCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c111_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c111_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_Standby;
    WinCtl_DrvWinSta = 0U;
    AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
    AppSwcBcm_ARID_DEF.WinCtl_J53 = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib) {
     case AppSwcBcm_IN_AutoDown:
      WinCtl_DrvWinSta = 3U;
      if (WinCtl_DrvWinReq != 3) {
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_Standby;
        WinCtl_DrvWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = false;
      }
      break;

     case AppSwcBcm_IN_ManDown:
      WinCtl_DrvWinSta = 4U;
      if (WinCtl_DrvWinReq != 2) {
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_Standby;
        WinCtl_DrvWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = false;
      }
      break;

     case AppSwcBcm_IN_ManUp:
      WinCtl_DrvWinSta = 2U;
      if (WinCtl_DrvWinReq != 1) {
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_Standby;
        WinCtl_DrvWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = false;
      }
      break;

     default:
      /* case IN_Standby: */
      WinCtl_DrvWinSta = 0U;
      switch (WinCtl_DrvWinReq) {
       case 2:
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_ManDown;
        WinCtl_DrvWinSta = 4U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = true;
        break;

       case 1:
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_ManUp;
        WinCtl_DrvWinSta = 2U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = true;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_AutoDown;
        WinCtl_DrvWinSta = 3U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = true;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S10>/DrvWinCtl' */
}

/* Output and update for atomic system: '<S10>/PsgWinCtl' */
static void AppSwcBcm_PsgWinCtl(void)
{
  /* Chart: '<S10>/PsgWinCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c112_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c112_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_j;
    WinCtl_PsgWinSta = 0U;
    AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
    AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib) {
     case AppSwcBcm_IN_AutoDown_n:
      WinCtl_PsgWinSta = 3U;
      if (WinCtl_PsgWinReq != 3) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_j;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManDown_k:
      WinCtl_PsgWinSta = 4U;
      if (WinCtl_PsgWinReq != 2) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_j;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManUp_g:
      WinCtl_PsgWinSta = 2U;
      if (WinCtl_PsgWinReq != 1) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_j;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     default:
      /* case IN_Standby: */
      WinCtl_PsgWinSta = 0U;
      switch (WinCtl_PsgWinReq) {
       case 2:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManDown_k;
        WinCtl_PsgWinSta = 4U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = true;
        break;

       case 1:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManUp_g;
        WinCtl_PsgWinSta = 2U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = true;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_AutoDown_n;
        WinCtl_PsgWinSta = 3U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = true;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S10>/PsgWinCtl' */
}

/*
 * Output and update for atomic system:
 *    '<S150>/Bit Shift1'
 *    '<S150>/Bit Shift7'
 *    '<S350>/Bit Shift1'
 *    '<S677>/Bit Shift3'
 */
static uint16 AppSwcBcm_BitShift1_k(uint16 rtu_u)
{
  /* MATLAB Function: '<S153>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S150>/Bit Shift3'
 *    '<S350>/Bit Shift'
 *    '<S587>/Bit Shift5'
 *    '<S677>/Bit Shift5'
 */
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u)
{
  /* MATLAB Function: '<S154>/bit_shift' */
  return rtu_u;
}

/* Output and update for atomic system: '<S10>/SigProc' */
static void AppSwcBcm_SigProc(void)
{
  uint16 rtb_Switch1;
  boolean rtb_LogicalOperator1_ea;

  /* Outputs for Atomic SubSystem: '<S150>/Bit Shift3' */
  /* Constant: '<S150>/Constant11' */
  rtb_Switch1 = AppSwcBcm_BitShift3(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S150>/Bit Shift3' */

  /* Switch: '<S150>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S150>/Bitwise AND3'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant15'
     */
    rtb_Switch1 = WinCtl_DrvWinSwResis_C;
  } else {
    /* Switch: '<S150>/Switch1' */
    rtb_Switch1 = BSW_J113DrvWinSwResis;
  }

  /* End of Switch: '<S150>/Switch3' */

  /* Logic: '<S150>/Logical Operator1' incorporates:
   *  Constant: '<S150>/Constant26'
   *  Constant: '<S150>/Constant31'
   *  RelationalOperator: '<S150>/Relational Operator2'
   *  RelationalOperator: '<S150>/Relational Operator3'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_DrvWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinDnMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S150>/Constant17'
   *  Constant: '<S150>/Constant18'
   *  Constant: '<S150>/Constant19'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_f5 >= (float32)WinCtl_DrvWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_f5++;
      AppSwcBcm_ARID_DEF.cnt_heal_bu = (uint16)((float32)
        WinCtl_DrvWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_f5 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bu == 0) {
      WinCtl_DrvWinDnSw = false;
    } else if (WinCtl_DrvWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bu--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms1' */

  /* Logic: '<S150>/Logical Operator2' incorporates:
   *  Constant: '<S150>/Constant35'
   *  Constant: '<S150>/Constant36'
   *  RelationalOperator: '<S150>/Relational Operator4'
   *  RelationalOperator: '<S150>/Relational Operator5'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_DrvWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinAutoDnMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S150>/Constant23'
   *  Constant: '<S150>/Constant24'
   *  Constant: '<S150>/Constant25'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_me >= (float32)
         WinCtl_DrvWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_me++;
      AppSwcBcm_ARID_DEF.cnt_heal_bc = (uint16)((float32)
        WinCtl_DrvWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_me = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bc == 0) {
      WinCtl_DrvWinAutoDnSw = false;
    } else if (WinCtl_DrvWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bc--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms2' */

  /* Logic: '<S150>/Logical Operator' incorporates:
   *  Constant: '<S150>/Constant20'
   *  Constant: '<S150>/Constant22'
   *  RelationalOperator: '<S150>/Relational Operator'
   *  RelationalOperator: '<S150>/Relational Operator1'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_DrvWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinUpMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S150>/Constant12'
   *  Constant: '<S150>/Constant13'
   *  Constant: '<S150>/Constant14'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_io >= (float32)WinCtl_DrvWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_io++;
      AppSwcBcm_ARID_DEF.cnt_heal_a1 = (uint16)((float32)
        WinCtl_DrvWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_io = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a1 == 0) {
      WinCtl_DrvWinUpSw = false;
    } else if (WinCtl_DrvWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a1--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S150>/Bit Shift7' */
  /* Constant: '<S150>/Constant21' */
  rtb_Switch1 = AppSwcBcm_BitShift1_k(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S150>/Bit Shift7' */

  /* Switch: '<S150>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S150>/Bitwise AND7'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant30'
     */
    rtb_Switch1 = WinCtl_PsgWinSwResis_C;
  } else {
    /* Switch: '<S150>/Switch1' */
    rtb_Switch1 = BSW_J26PsgWinSwResis;
  }

  /* End of Switch: '<S150>/Switch6' */

  /* Logic: '<S150>/Logical Operator3' incorporates:
   *  Constant: '<S150>/Constant40'
   *  Constant: '<S150>/Constant41'
   *  RelationalOperator: '<S150>/Relational Operator6'
   *  RelationalOperator: '<S150>/Relational Operator7'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_PsgWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinUpMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S150>/Constant27'
   *  Constant: '<S150>/Constant28'
   *  Constant: '<S150>/Constant29'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_mf >= (float32)WinCtl_PsgWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_mf++;
      AppSwcBcm_ARID_DEF.cnt_heal_nv = (uint16)((float32)
        WinCtl_PsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_mf = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_nv == 0) {
      WinCtl_PsgWinUpSw = false;
    } else if (WinCtl_PsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_nv--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms4' */

  /* Logic: '<S150>/Logical Operator4' incorporates:
   *  Constant: '<S150>/Constant42'
   *  Constant: '<S150>/Constant43'
   *  RelationalOperator: '<S150>/Relational Operator8'
   *  RelationalOperator: '<S150>/Relational Operator9'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_PsgWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinDnMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S150>/Constant32'
   *  Constant: '<S150>/Constant33'
   *  Constant: '<S150>/Constant34'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_iz >= (float32)WinCtl_PsgWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_iz++;
      AppSwcBcm_ARID_DEF.cnt_heal_n2 = (uint16)((float32)
        WinCtl_PsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_iz = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n2 == 0) {
      WinCtl_PsgWinDnSw = false;
    } else if (WinCtl_PsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n2--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms5' */

  /* Logic: '<S150>/Logical Operator5' incorporates:
   *  Constant: '<S150>/Constant44'
   *  Constant: '<S150>/Constant45'
   *  RelationalOperator: '<S150>/Relational Operator10'
   *  RelationalOperator: '<S150>/Relational Operator11'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_PsgWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinAutoDnMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S150>/Constant37'
   *  Constant: '<S150>/Constant38'
   *  Constant: '<S150>/Constant39'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b2 >= (float32)
         WinCtl_PsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_PsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b2++;
      AppSwcBcm_ARID_DEF.cnt_heal_ac = (uint16)((float32)
        WinCtl_PsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ac == 0) {
      WinCtl_PsgWinAutoDnSw = false;
    } else if (WinCtl_PsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ac--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S150>/Bit Shift1' */
  /* Constant: '<S150>/Constant1' */
  rtb_Switch1 = AppSwcBcm_BitShift1_k(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S150>/Bit Shift1' */

  /* Switch: '<S150>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S150>/Bitwise AND1'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant5'
     */
    rtb_Switch1 = WinCtl_DrvPsgWinSwResis_C;
  } else {
    /* Switch: '<S150>/Switch1' */
    rtb_Switch1 = BSW_J126DrvPsgWinSwResis;
  }

  /* End of Switch: '<S150>/Switch1' */

  /* Logic: '<S150>/Logical Operator6' incorporates:
   *  Constant: '<S150>/Constant46'
   *  Constant: '<S150>/Constant47'
   *  RelationalOperator: '<S150>/Relational Operator14'
   *  RelationalOperator: '<S150>/Relational Operator15'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_DrvPsgWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinUpMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S150>/Constant2'
   *  Constant: '<S150>/Constant3'
   *  Constant: '<S150>/Constant4'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_cd >= (float32)
         WinCtl_DrvPsgWinUpTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_cd++;
      AppSwcBcm_ARID_DEF.cnt_heal_hi = (uint16)((float32)
        WinCtl_DrvPsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_cd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hi == 0) {
      WinCtl_DrvPsgWinUpSw = false;
    } else if (WinCtl_DrvPsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hi--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms7' */

  /* Logic: '<S150>/Logical Operator7' incorporates:
   *  Constant: '<S150>/Constant48'
   *  Constant: '<S150>/Constant49'
   *  RelationalOperator: '<S150>/Relational Operator16'
   *  RelationalOperator: '<S150>/Relational Operator17'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_DrvPsgWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinDnMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S150>/Constant6'
   *  Constant: '<S150>/Constant7'
   *  Constant: '<S150>/Constant8'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_jd >= (float32)
         WinCtl_DrvPsgWinDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_jd++;
      AppSwcBcm_ARID_DEF.cnt_heal_fy = (uint16)((float32)
        WinCtl_DrvPsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_jd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_fy == 0) {
      WinCtl_DrvPsgWinDnSw = false;
    } else if (WinCtl_DrvPsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_fy--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms8' */

  /* Logic: '<S150>/Logical Operator8' incorporates:
   *  Constant: '<S150>/Constant50'
   *  Constant: '<S150>/Constant51'
   *  RelationalOperator: '<S150>/Relational Operator12'
   *  RelationalOperator: '<S150>/Relational Operator13'
   */
  rtb_LogicalOperator1_ea = ((rtb_Switch1 >= WinCtl_DrvPsgWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinAutoDnMaxResis_C));

  /* Chart: '<S150>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S150>/Constant10'
   *  Constant: '<S150>/Constant16'
   *  Constant: '<S150>/Constant9'
   */
  if (rtb_LogicalOperator1_ea) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_e >= (float32)
         WinCtl_DrvPsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_e++;
      AppSwcBcm_ARID_DEF.cnt_heal_oo = (uint16)((float32)
        WinCtl_DrvPsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_e = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_oo == 0) {
      WinCtl_DrvPsgWinAutoDnSw = false;
    } else if (WinCtl_DrvPsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_oo--;
    }
  }

  /* End of Chart: '<S150>/LIB_TPD_10ms9' */
}

/* Output and update for atomic system: '<S10>/WinMotorProt' */
static void AppSwcBcm_WinMotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S151>/Logical Operator' incorporates:
   *  Constant: '<S151>/Constant'
   *  Constant: '<S151>/Constant4'
   *  RelationalOperator: '<S151>/Relational Operator'
   *  RelationalOperator: '<S151>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_az = ((WinCtl_DrvWinSta == 4) || (WinCtl_DrvWinSta
    == 3));

  /* Chart: '<S151>/LIB_CntLimit1' incorporates:
   *  SubSystem: '<S169>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_az,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ck,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ft);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ck) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_cg + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_cg + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_cg = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_mm = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_mm + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_mm + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_mm = (uint16)tmp;
  }

  /* Constant: '<S151>/Constant1' */
  if (AppSwcBcm_ARID_DEF.Cnt2_mm >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_cg - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_cg - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_cg = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_mm = 0U;
  }

  /* End of Constant: '<S151>/Constant1' */

  /* Constant: '<S151>/Constant2' */
  WinCtl_DrvWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_cg > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S151>/Relational Operator1' incorporates:
   *  Constant: '<S151>/Constant3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_lu = (WinCtl_DrvWinSta == 2);

  /* Chart: '<S151>/LIB_CntLimit' incorporates:
   *  SubSystem: '<S168>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_lu,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ecm,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ie);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ecm) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_eg + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_eg + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_eg = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_bk = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_bk + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_bk + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_bk = (uint16)tmp;
  }

  /* Constant: '<S151>/Constant14' */
  if (AppSwcBcm_ARID_DEF.Cnt2_bk >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_eg - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_eg - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_eg = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_bk = 0U;
  }

  /* End of Constant: '<S151>/Constant14' */

  /* Constant: '<S151>/Constant15' */
  WinCtl_DrvWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_eg > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S151>/Relational Operator4' incorporates:
   *  Constant: '<S151>/Constant10'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_dx = (WinCtl_PsgWinSta == 2);

  /* Chart: '<S151>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S170>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_dx,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ku,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pt);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ku) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_cp + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_cp + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_cp = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_m = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_m + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_m + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_m = (uint16)tmp;
  }

  /* Constant: '<S151>/Constant8' */
  if (AppSwcBcm_ARID_DEF.Cnt2_m >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_cp - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_cp - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_cp = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_m = 0U;
  }

  /* End of Constant: '<S151>/Constant8' */

  /* Constant: '<S151>/Constant9' */
  WinCtl_PsgWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_cp > WinCtl_WinProtNum_C);

  /* Logic: '<S151>/Logical Operator1' incorporates:
   *  Constant: '<S151>/Constant11'
   *  Constant: '<S151>/Constant7'
   *  RelationalOperator: '<S151>/Relational Operator3'
   *  RelationalOperator: '<S151>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_nhh = ((WinCtl_PsgWinSta == 4) ||
    (WinCtl_PsgWinSta == 3));

  /* Chart: '<S151>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S171>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_nhh,
    &AppSwcBcm_ARID_DEF.LogicalOperator_m4,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pe);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_m4) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_mr + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_mr + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_mr = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_i = (uint16)tmp;
  }

  /* Constant: '<S151>/Constant5' */
  if (AppSwcBcm_ARID_DEF.Cnt2_i >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_mr - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_mr - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_mr = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;
  }

  /* End of Constant: '<S151>/Constant5' */

  /* Constant: '<S151>/Constant6' */
  WinCtl_PsgWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_mr > WinCtl_WinProtNum_C);
}

/*
 * Output and update for function-call system:
 *    '<S180>/Lib_RiseEdgeDet'
 *    '<S181>/Lib_RiseEdgeDet'
 *    '<S848>/Lib_RiseEdgeDet'
 *    '<S849>/Lib_RiseEdgeDet'
 */
static void AppSwcBcm_Lib_RiseEdgeDet_h(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_c_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S195>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S195>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S152>/Chart6'
 *    '<S152>/Chart7'
 *    '<S152>/Chart8'
 *    '<S152>/Chart9'
 */
static void AppSwcBcm_Chart6_Init(boolean *rty_Lib_Out)
{
  *rty_Lib_Out = false;
}

/*
 * Output and update for atomic system:
 *    '<S152>/Chart6'
 *    '<S152>/Chart7'
 *    '<S152>/Chart8'
 *    '<S152>/Chart9'
 */
static void AppSwcBcm_Chart6(boolean rtu_Lib_blIn1, boolean rtu_Lib_blIn2, uint8
  rtu_Lib_blIn3, boolean *rty_Lib_Out, ARID_DEF_Chart6_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S152>/Chart6' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c12_WinCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c12_WinCtl_Lib = 1U;
    AppSwcBcm__ARID_DEF_arg->is_c12_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  } else if (AppSwcBcm__ARID_DEF_arg->is_c12_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_Lib_blIn1;

    /* Outputs for Function Call SubSystem: '<S186>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

    /* End of Outputs for SubSystem: '<S186>/Lib_RiseEdgeDet' */
    if (AppSwcBcm__ARID_DEF_arg->LogicalOperator && (!rtu_Lib_blIn2)) {
      AppSwcBcm__ARID_DEF_arg->is_c12_WinCtl_Lib = AppSwcBcm_IN_On;
      *rty_Lib_Out = true;
    }

    /* case IN_On: */
  } else if ((!rtu_Lib_blIn1) || rtu_Lib_blIn2 || (rtu_Lib_blIn3 == 0)) {
    AppSwcBcm__ARID_DEF_arg->is_c12_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  }

  /* End of Chart: '<S152>/Chart6' */
}

/*
 * System initialize for atomic system:
 *    '<S152>/LIB_NegPluse'
 *    '<S588>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S152>/LIB_NegPluse'
 *    '<S588>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_NegPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S152>/LIB_NegPluse' */
  if (rtu_LIB_blEn) {
    if (AppSwcBcm__ARID_DEF_arg->Cnt <= rtu_LIB_u16Limit) {
      tmp = AppSwcBcm__ARID_DEF_arg->Cnt + 1;
      if (AppSwcBcm__ARID_DEF_arg->Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm__ARID_DEF_arg->Cnt = (uint16)tmp;
      *rty_LIB_blOut = true;
    } else {
      *rty_LIB_blOut = false;
    }
  } else {
    *rty_LIB_blOut = false;
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }

  /* End of Chart: '<S152>/LIB_NegPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S152>/LIB_PosPluse'
 *    '<S152>/LIB_PosPluse1'
 *    '<S329>/LIB_Tim'
 *    '<S570>/LIB_Tim'
 *    '<S866>/LIB_PosPluse'
 *    '<S870>/LIB_PosPluse'
 *    '<S870>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S152>/LIB_PosPluse'
 *    '<S152>/LIB_PosPluse1'
 *    '<S329>/LIB_Tim'
 *    '<S570>/LIB_Tim'
 *    '<S866>/LIB_PosPluse'
 *    '<S870>/LIB_PosPluse'
 *    '<S870>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_PosPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S152>/LIB_PosPluse' */
  if (rtu_LIB_blEn) {
    if (AppSwcBcm__ARID_DEF_arg->Cnt <= rtu_LIB_u16Limit) {
      tmp = AppSwcBcm__ARID_DEF_arg->Cnt + 1;
      if (AppSwcBcm__ARID_DEF_arg->Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm__ARID_DEF_arg->Cnt = (uint16)tmp;
      *rty_LIB_blOut = false;
    } else {
      *rty_LIB_blOut = true;
    }
  } else {
    *rty_LIB_blOut = false;
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }

  /* End of Chart: '<S152>/LIB_PosPluse' */
}

/* System initialize for atomic system: '<S10>/WinSwArb' */
static void AppSwcBcm_WinSwArb_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j;
  boolean rtb_LIB_blOut_p;
  boolean rtb_LIB_blOut_c;

  /* SystemInitialize for Chart: '<S152>/Chart6' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_l);

  /* SystemInitialize for Chart: '<S152>/Chart7' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_i);

  /* SystemInitialize for Chart: '<S152>/Chart8' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_c);

  /* SystemInitialize for Chart: '<S152>/Chart9' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out);

  /* SystemInitialize for Chart: '<S152>/LIB_NegPluse' */
  AppSwcBcm_LIB_NegPluse_Init(&rtb_LIB_blOut_c);

  /* SystemInitialize for Chart: '<S152>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_p);

  /* SystemInitialize for Chart: '<S152>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_j);
}

/* Output and update for atomic system: '<S10>/WinSwArb' */
static void AppSwcBcm_WinSwArb(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j;
  boolean rtb_LIB_blOut_p;
  boolean rtb_LIB_blOut_c;
  uint8 rtb_Switch;
  uint8 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_ph;
  boolean rtb_LogicalOperator2_iz;
  boolean rtb_LogicalOperator3_ba;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator4_lz;
  boolean rtb_RelationalOperator5_oz;

  /* Logic: '<S152>/Logical Operator1' */
  rtb_LogicalOperator1_ph = (WinCtl_PsgWinAutoDnSw || WinCtl_DrvPsgWinAutoDnSw);

  /* Logic: '<S152>/Logical Operator' */
  rtb_LogicalOperator = (WinCtl_PsgWinDnSw || WinCtl_DrvPsgWinDnSw);

  /* RelationalOperator: '<S152>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S152>/Relational Operator2'
   */
  rtb_RelationalOperator5_oz = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S152>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S152>/Relational Operator'
   */
  rtb_RelationalOperator4_lz = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 6);

  /* Logic: '<S152>/Logical Operator3' */
  rtb_LogicalOperator3_ba = (rtb_RelationalOperator5_oz &&
    rtb_RelationalOperator4_lz);

  /* Chart: '<S152>/Chart8' incorporates:
   *  Logic: '<S152>/Logical Operator16'
   *  UnitDelay: '<S10>/Unit Delay2'
   *  UnitDelay: '<S152>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_ba, rtb_LogicalOperator1_ph ||
                   rtb_LogicalOperator ||
                   AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_cw, WinCtl_PsgWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_c,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart8);

  /* RelationalOperator: '<S152>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S152>/Relational Operator11'
   */
  rtb_RelationalOperator4_lz = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 5);

  /* Logic: '<S152>/Logical Operator9' */
  rtb_LogicalOperator9 = (rtb_RelationalOperator5_oz &&
    rtb_RelationalOperator4_lz);

  /* Logic: '<S152>/Logical Operator2' */
  rtb_LogicalOperator2_iz = (WinCtl_DrvPsgWinUpSw || WinCtl_PsgWinUpSw);

  /* Chart: '<S152>/Chart9' incorporates:
   *  Logic: '<S152>/Logical Operator15'
   *  UnitDelay: '<S10>/Unit Delay4'
   *  UnitDelay: '<S152>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, rtb_LogicalOperator2_iz ||
                   AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j, WinCtl_PsgWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart9);

  /* Chart: '<S152>/Chart4' incorporates:
   *  UnitDelay: '<S10>/Unit Delay4'
   *  UnitDelay: '<S152>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c10_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c10_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_PsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib == AppSwcBcm_IN_Off_m) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ca = rtb_LogicalOperator;

    /* Outputs for Function Call SubSystem: '<S184>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ca,
      &AppSwcBcm_ARID_DEF.LogicalOperator_aa,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p);

    /* End of Outputs for SubSystem: '<S184>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_aa &&
        (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j) && (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_PsgWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!rtb_LogicalOperator) || AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j ||
             (WinCtl_PsgWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_PsgWinDnReq = false;
  }

  /* End of Chart: '<S152>/Chart4' */

  /* Chart: '<S152>/Chart1' incorporates:
   *  Logic: '<S152>/Logical Operator19'
   *  UnitDelay: '<S10>/Unit Delay4'
   *  UnitDelay: '<S152>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_PsgWinAutoDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib == AppSwcBcm_IN_Off_m) {
    AppSwcBcm_ARID_DEF.Lib_blIn_jy = rtb_LogicalOperator1_ph;

    /* Outputs for Function Call SubSystem: '<S180>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_h(AppSwcBcm_ARID_DEF.Lib_blIn_jy,
      &AppSwcBcm_ARID_DEF.LogicalOperator_eb,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_lu);

    /* End of Outputs for SubSystem: '<S180>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_eb && (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_PsgWinAutoDnReq = true;
    }
  } else {
    /* case IN_On: */
    AppSwcBcm_ARID_DEF.Lib_blIn_jy = rtb_LogicalOperator1_ph;

    /* Outputs for Function Call SubSystem: '<S180>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_h(AppSwcBcm_ARID_DEF.Lib_blIn_jy,
      &AppSwcBcm_ARID_DEF.LogicalOperator_eb,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_lu);

    /* End of Outputs for SubSystem: '<S180>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_eb || (rtb_LogicalOperator ||
         rtb_LogicalOperator2_iz || AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j) ||
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_m;
      WinCtl_PsgWinAutoDnReq = false;
    }
  }

  /* End of Chart: '<S152>/Chart1' */

  /* Chart: '<S152>/Chart5' incorporates:
   *  UnitDelay: '<S10>/Unit Delay2'
   *  UnitDelay: '<S152>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c11_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_PsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib == AppSwcBcm_IN_Off_m) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kd = rtb_LogicalOperator2_iz;

    /* Outputs for Function Call SubSystem: '<S185>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_kd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_aq,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_af);

    /* End of Outputs for SubSystem: '<S185>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_aq &&
        (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_cw) && (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_PsgWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!rtb_LogicalOperator2_iz) ||
             AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_cw || (WinCtl_PsgWinReq == 0))
  {
    AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_PsgWinUpReq = false;
  }

  /* End of Chart: '<S152>/Chart5' */

  /* Switch: '<S152>/Switch4' incorporates:
   *  Switch: '<S152>/Switch5'
   */
  if (WinCtl_PsgWinDnReq) {
    /* Switch: '<S152>/Switch4' incorporates:
     *  Constant: '<S152>/Constant12'
     */
    WinCtl_PsgWinReq = 2U;
  } else if (WinCtl_PsgWinAutoDnReq) {
    /* Switch: '<S152>/Switch5' incorporates:
     *  Constant: '<S152>/Constant13'
     *  Switch: '<S152>/Switch4'
     */
    WinCtl_PsgWinReq = 3U;
  } else {
    /* Switch: '<S152>/Switch4' incorporates:
     *  Switch: '<S152>/Switch5'
     *  Switch: '<S152>/Switch6'
     */
    WinCtl_PsgWinReq = (uint8)WinCtl_PsgWinUpReq;
  }

  /* End of Switch: '<S152>/Switch4' */

  /* RelationalOperator: '<S152>/Relational Operator4' incorporates:
   *  Constant: '<S152>/Constant19'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator4_lz = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S152>/Relational Operator5' incorporates:
   *  Constant: '<S152>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator5_oz =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())->BodyWarnSts == 0);

  /* RelationalOperator: '<S152>/Relational Operator3' incorporates:
   *  Constant: '<S152>/Constant31'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S152>/Relational Operator6'
   */
  rtb_LogicalOperator1_ph = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())
    ->BodyWarnSts == 3);

  /* Chart: '<S152>/LIB_NegPluse' incorporates:
   *  Constant: '<S152>/Constant20'
   *  Logic: '<S152>/Logical Operator12'
   *  Logic: '<S152>/Logical Operator17'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator4_lz &&
    (rtb_RelationalOperator5_oz || rtb_LogicalOperator1_ph),
    WinCtl_PwrOffWinValidTimMax_C, &rtb_LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse);

  /* RelationalOperator: '<S152>/Relational Operator3' incorporates:
   *  Constant: '<S152>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator1_ph = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S152>/Logical Operator5' */
  rtb_RelationalOperator5_oz = (rtb_LogicalOperator1_ph || rtb_LIB_blOut_c);

  /* Chart: '<S152>/LIB_PosPluse1' incorporates:
   *  Constant: '<S152>/Constant8'
   *  Logic: '<S152>/Logical Operator11'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator2_iz || rtb_LogicalOperator ||
    WinCtl_PsgWinAutoDnReq || rtb_LogicalOperator9 || rtb_LogicalOperator3_ba,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1_a);

  /* Chart: '<S152>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S152>/Constant10'
   *  Constant: '<S152>/Constant11'
   *  Constant: '<S152>/Constant44'
   *  Constant: '<S152>/Constant48'
   *  RelationalOperator: '<S152>/Relational Operator7'
   */
  if (BSW_PsgWinMotorCur >= WinCtl_WinMotorCurMax_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_mt >= (float32)
         WinCtl_WinMotorCurTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_WinMotorCurTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinMotorLocked = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_mt++;
      AppSwcBcm_ARID_DEF.cnt_heal_cm = (uint16)((float32)
        WinCtl_WinMotorCurTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_mt = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cm == 0) {
      WinCtl_PsgWinMotorLocked = false;
    } else if (WinCtl_WinMotorCurTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cm--;
    }
  }

  /* End of Chart: '<S152>/LIB_TPD_10ms1' */

  /* Switch: '<S152>/Switch10' incorporates:
   *  Constant: '<S152>/Constant27'
   *  Logic: '<S152>/Logical Operator4'
   *  Logic: '<S152>/Logical Operator7'
   *  Switch: '<S152>/Switch9'
   */
  if (WinCtl_PsgWinMotorLocked || rtb_LIB_blOut_j) {
    WinCtl_PsgWinReq = 0U;
  } else {
    if (rtb_RelationalOperator5_oz) {
      /* Switch: '<S152>/Switch9' */
      tmp = WinCtl_PsgWinReq;
    } else {
      /* Switch: '<S152>/Switch9' incorporates:
       *  Constant: '<S152>/Constant33'
       */
      tmp = 0U;
    }

    /* Switch: '<S152>/Switch13' incorporates:
     *  Switch: '<S152>/Switch9'
     */
    if (tmp == 0) {
      /* Switch: '<S152>/Switch14' */
      if (AppSwcBcm_ARID_DEF.Lib_Out) {
        /* Switch: '<S152>/Switch14' incorporates:
         *  Constant: '<S152>/Constant16'
         */
        WinCtl_PsgWinReq = 2U;
      } else {
        /* Switch: '<S152>/Switch14' incorporates:
         *  Switch: '<S152>/Switch15'
         */
        WinCtl_PsgWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_c;
      }

      /* End of Switch: '<S152>/Switch14' */
    }

    /* End of Switch: '<S152>/Switch13' */
  }

  /* End of Switch: '<S152>/Switch10' */

  /* Chart: '<S152>/Chart2' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S152>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_DrvWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib == AppSwcBcm_IN_Off_m) {
    AppSwcBcm_ARID_DEF.Lib_blIn_jf = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S182>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_jf,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jd,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o3v);

    /* End of Outputs for SubSystem: '<S182>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jd &&
        (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_iq) && (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_DrvWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinDnSw) || AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_iq ||
             (WinCtl_DrvWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_DrvWinDnReq = false;
  }

  /* End of Chart: '<S152>/Chart2' */

  /* Chart: '<S152>/Chart10' incorporates:
   *  Logic: '<S152>/Logical Operator18'
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S152>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_DrvWinAutoDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib == AppSwcBcm_IN_Off_m) {
    AppSwcBcm_ARID_DEF.Lib_blIn_e3 = WinCtl_DrvWinAutoDnSw;

    /* Outputs for Function Call SubSystem: '<S181>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_h(AppSwcBcm_ARID_DEF.Lib_blIn_e3,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

    /* End of Outputs for SubSystem: '<S181>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jm && (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_DrvWinAutoDnReq = true;
    }
  } else {
    /* case IN_On: */
    AppSwcBcm_ARID_DEF.Lib_blIn_e3 = WinCtl_DrvWinAutoDnSw;

    /* Outputs for Function Call SubSystem: '<S181>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_h(AppSwcBcm_ARID_DEF.Lib_blIn_e3,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

    /* End of Outputs for SubSystem: '<S181>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jm || (WinCtl_DrvWinDnSw ||
         WinCtl_DrvWinUpSw || AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_iq) ||
        (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_m;
      WinCtl_DrvWinAutoDnReq = false;
    }
  }

  /* End of Chart: '<S152>/Chart10' */

  /* Chart: '<S152>/Chart3' incorporates:
   *  UnitDelay: '<S10>/Unit Delay3'
   *  UnitDelay: '<S152>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c9_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_DrvWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib == AppSwcBcm_IN_Off_m) {
    AppSwcBcm_ARID_DEF.Lib_blIn_fd = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S183>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_fd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_gv,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ms);

    /* End of Outputs for SubSystem: '<S183>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_gv &&
        (!AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_p) && (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_DrvWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinUpSw) || AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_p ||
             (WinCtl_DrvWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_Off_m;
    WinCtl_DrvWinUpReq = false;
  }

  /* End of Chart: '<S152>/Chart3' */

  /* Switch: '<S152>/Switch' incorporates:
   *  Switch: '<S152>/Switch1'
   */
  if (WinCtl_DrvWinDnReq) {
    /* Switch: '<S152>/Switch' incorporates:
     *  Constant: '<S152>/Constant'
     */
    rtb_Switch = 2U;
  } else if (WinCtl_DrvWinAutoDnReq) {
    /* Switch: '<S152>/Switch1' incorporates:
     *  Constant: '<S152>/Constant1'
     *  Switch: '<S152>/Switch'
     */
    rtb_Switch = 3U;
  } else {
    /* Switch: '<S152>/Switch' incorporates:
     *  Switch: '<S152>/Switch1'
     *  Switch: '<S152>/Switch2'
     */
    rtb_Switch = WinCtl_DrvWinUpReq;
  }

  /* End of Switch: '<S152>/Switch' */

  /* Chart: '<S152>/Chart6' incorporates:
   *  Logic: '<S152>/Logical Operator13'
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S152>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, WinCtl_DrvWinUpSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_iq, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_l,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart6);

  /* Chart: '<S152>/Chart7' incorporates:
   *  Logic: '<S152>/Logical Operator14'
   *  UnitDelay: '<S10>/Unit Delay3'
   *  UnitDelay: '<S152>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_ba, WinCtl_DrvWinDnSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_p ||
                   WinCtl_DrvWinAutoDnSw, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_i,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart7);

  /* Chart: '<S152>/LIB_PosPluse' incorporates:
   *  Constant: '<S152>/Constant40'
   *  Logic: '<S152>/Logical Operator10'
   */
  AppSwcBcm_LIB_PosPluse(WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnReq ||
    WinCtl_DrvWinUpSw || rtb_LogicalOperator9 || rtb_LogicalOperator3_ba,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_d);

  /* Chart: '<S152>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S152>/Constant34'
   *  Constant: '<S152>/Constant35'
   *  Constant: '<S152>/Constant36'
   *  Constant: '<S152>/Constant37'
   *  RelationalOperator: '<S152>/Relational Operator9'
   */
  if (BSW_DrvWinMotorCur >= WinCtl_WinMotorCurMax_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_om >= (float32)
         WinCtl_WinMotorCurTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_WinMotorCurTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinMotorLocked = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_om++;
      AppSwcBcm_ARID_DEF.cnt_heal_mr = (uint16)((float32)
        WinCtl_WinMotorCurTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_om = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mr == 0) {
      WinCtl_DrvWinMotorLocked = false;
    } else if (WinCtl_WinMotorCurTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mr--;
    }
  }

  /* End of Chart: '<S152>/LIB_TPD_10ms3' */

  /* Switch: '<S152>/Switch11' incorporates:
   *  Constant: '<S152>/Constant25'
   *  Logic: '<S152>/Logical Operator6'
   *  Logic: '<S152>/Logical Operator8'
   *  Switch: '<S152>/Switch8'
   */
  if (WinCtl_DrvWinMotorLocked || rtb_LIB_blOut_p) {
    WinCtl_DrvWinReq = 0U;
  } else {
    if (rtb_RelationalOperator5_oz) {
      /* Switch: '<S152>/Switch8' */
      tmp = rtb_Switch;
    } else {
      /* Switch: '<S152>/Switch8' incorporates:
       *  Constant: '<S152>/Constant32'
       */
      tmp = 0U;
    }

    /* Switch: '<S152>/Switch7' incorporates:
     *  Switch: '<S152>/Switch12'
     *  Switch: '<S152>/Switch8'
     */
    if (tmp != 0) {
      /* Switch: '<S152>/Switch7' */
      WinCtl_DrvWinReq = rtb_Switch;
    } else if (AppSwcBcm_ARID_DEF.Lib_Out_l) {
      /* Switch: '<S152>/Switch12' incorporates:
       *  Constant: '<S152>/Constant43'
       */
      WinCtl_DrvWinReq = 2U;
    } else {
      /* Switch: '<S152>/Switch12' incorporates:
       *  Switch: '<S152>/Switch3'
       */
      WinCtl_DrvWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_i;
    }

    /* End of Switch: '<S152>/Switch7' */
  }

  /* End of Switch: '<S152>/Switch11' */
}

/* System initialize for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S10>/WinSwArb' */
  AppSwcBcm_WinSwArb_Init();

  /* End of SystemInitialize for SubSystem: '<S10>/WinSwArb' */
}

/* Output and update for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl(void)
{
  /* Outputs for Atomic SubSystem: '<S10>/SigProc' */
  AppSwcBcm_SigProc();

  /* End of Outputs for SubSystem: '<S10>/SigProc' */

  /* Outputs for Atomic SubSystem: '<S10>/WinSwArb' */
  AppSwcBcm_WinSwArb();

  /* End of Outputs for SubSystem: '<S10>/WinSwArb' */

  /* Chart: '<S10>/DrvWinCtl' */
  AppSwcBcm_DrvWinCtl();

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd4' */
  /* Switch: '<S148>/Switch1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  if (WinCtl_J53DrvWinDnOvrdFlg_C) {
    /* Switch: '<S148>/Switch1' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    WinCtl_J53DrvWinDn = WinCtl_J53DrvWinDnOvrdVal_C;
  } else {
    /* Switch: '<S148>/Switch1' incorporates:
     *  Switch: '<S148>/Switch2'
     */
    WinCtl_J53DrvWinDn = AppSwcBcm_ARID_DEF.WinCtl_J53;
  }

  /* End of Switch: '<S148>/Switch1' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd4' */

  /* Chart: '<S10>/PsgWinCtl' */
  AppSwcBcm_PsgWinCtl();

  /* Outputs for Atomic SubSystem: '<S10>/WinMotorProt' */
  AppSwcBcm_WinMotorProt();

  /* End of Outputs for SubSystem: '<S10>/WinMotorProt' */

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd2' */
  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  if (WinCtl_J55PsgWinUpOvrdFlg_C) {
    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S10>/Constant4'
     */
    WinCtl_J55PsgWinUp = WinCtl_J55PsgWinUpOvrdVal_C;
  } else {
    /* Switch: '<S146>/Switch' */
    WinCtl_J55PsgWinUp = AppSwcBcm_ARID_DEF.WinCtl_J55;
  }

  /* End of Switch: '<S146>/Switch' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd3' */
  /* Switch: '<S147>/Switch' incorporates:
   *  Constant: '<S10>/Constant5'
   */
  if (WinCtl_J57PsgWinDnOvrdFlg_C) {
    /* Switch: '<S147>/Switch' incorporates:
     *  Constant: '<S10>/Constant6'
     */
    WinCtl_J57PsgWinDn = WinCtl_J57PsgWinDnOvrdVal_C;
  } else {
    /* Switch: '<S147>/Switch' */
    WinCtl_J57PsgWinDn = AppSwcBcm_ARID_DEF.WinCtl_J57;
  }

  /* End of Switch: '<S147>/Switch' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd1' */
  /* Switch: '<S145>/Switch1' incorporates:
   *  Constant: '<S10>/Constant18'
   */
  if (WinCtl_J51DrvWinUpOvrdFlg_C) {
    /* Switch: '<S145>/Switch1' incorporates:
     *  Constant: '<S10>/Constant19'
     */
    WinCtl_J51DrvWinUp = WinCtl_J51DrvWinUpOvrdVal_C;
  } else {
    /* Switch: '<S145>/Switch1' incorporates:
     *  Switch: '<S145>/Switch2'
     */
    WinCtl_J51DrvWinUp = AppSwcBcm_ARID_DEF.WinCtl_J51;
  }

  /* End of Switch: '<S145>/Switch1' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd1' */

  /* Update for UnitDelay: '<S10>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_p = WinCtl_DrvWinUpProt;

  /* Update for UnitDelay: '<S10>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_cw = WinCtl_PsgWinUpProt;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_iq = WinCtl_DrvWinDnProt;

  /* Update for UnitDelay: '<S10>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j = WinCtl_PsgWinDnProt;
}

/* Outputs for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl(void)
{
  sint32 tmp;
  uint8 rtb_CCaller;
  boolean rtb_Compare_l;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator2_f4z;
  boolean rtb_RelationalOperator4_f2;

  /* CCaller: '<S215>/C Caller' */
  rtb_CCaller = Get_PEAuth_FobStatus();

  /* RelationalOperator: '<S220>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S218>/Logical Operator2'
   */
  rtb_RelationalOperator4_f2 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* RelationalOperator: '<S228>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S218>/Relational Operator'
   */
  rtb_Compare_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VGSM_VehActGearPstn_enum <= 1);

  /* Logic: '<S217>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S218>/Logical Operator'
   */
  rtb_LogicalOperator2_f4z = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarRRSw);

  /* RelationalOperator: '<S220>/Relational Operator4' incorporates:
   *  Logic: '<S218>/Logical Operator3'
   */
  rtb_RelationalOperator4_f2 = (rtb_RelationalOperator4_f2 && rtb_Compare_l &&
    rtb_LogicalOperator2_f4z);

  /* Logic: '<S218>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S231>/Compare'
   *  UnitDelay: '<S218>/Unit Delay'
   */
  rtb_Compare_l = ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cs) &&
                   (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw
                   && rtb_RelationalOperator4_f2);

  /* Logic: '<S218>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S232>/Compare'
   *  UnitDelay: '<S218>/Unit Delay1'
   */
  rtb_RelationalOperator4_f2 = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_j) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw &&
    rtb_RelationalOperator4_f2);

  /* Chart: '<S218>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_DrvPEAuthentAcsd = 0U;
    PEPSCtl_KeyInCarSta = 0U;
    AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
    PEPSCtl_FRPEAuthentAcsd = 0U;
    AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
    AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
    Clear_PEStatus();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_l:
      if (rtb_Compare_l) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_LSeekKeyOut;
        Set_PEAuth_FobReq(1U);
        AppSwcBcm_ARID_DEF.count_j = 0U;
        AppSwcBcm_ARID_DEF.count1_e = 0U;
      } else if (rtb_RelationalOperator4_f2) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_RSeekKeyOut;
        Set_PEAuth_FobReq(2U);
        AppSwcBcm_ARID_DEF.count_j = 0U;
        AppSwcBcm_ARID_DEF.count1_e = 0U;
      }
      break;

     case AppSwcBcm_IN_LSeekKeyOut:
      if ((AppSwcBcm_ARID_DEF.count_j >= 10) ||
          (AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        PEPSCtl_DrvPEAuthentAcsd = 0U;
        PEPSCtl_KeyInCarSta = 0U;
        AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
        PEPSCtl_FRPEAuthentAcsd = 0U;
        AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
        AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
        Clear_PEStatus();
      } else {
        if (rtb_CCaller == 1) {
          PEPSCtl_DrvPEAuthentAcsd = 1U;
          tmp = AppSwcBcm_ARID_DEF.count_j + 1;
          if (AppSwcBcm_ARID_DEF.count_j + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_j = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_j + 1;
          if (AppSwcBcm_ARID_DEF.count_j + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_j = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_j + 1;
          if (AppSwcBcm_ARID_DEF.count_j + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_j = (uint8)tmp;
        }

        if (rtb_CCaller == 0) {
          if (AppSwcBcm_ARID_DEF.count1_e >= 150) {
            PEPSCtl_DrvPEAuthentAcsd = 2U;
            AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 1U;
            AppSwcBcm_ARID_DEF.count1_e = 0U;
          } else {
            tmp = AppSwcBcm_ARID_DEF.count1_e + 1;
            if (AppSwcBcm_ARID_DEF.count1_e + 1 > 255) {
              tmp = 255;
            }

            AppSwcBcm_ARID_DEF.count1_e = (uint8)tmp;
          }
        }
      }
      break;

     default:
      /* case IN_RSeekKeyOut: */
      if ((AppSwcBcm_ARID_DEF.count_j >= 10) ||
          (AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        PEPSCtl_DrvPEAuthentAcsd = 0U;
        PEPSCtl_KeyInCarSta = 0U;
        AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
        PEPSCtl_FRPEAuthentAcsd = 0U;
        AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
        AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
        Clear_PEStatus();
      } else {
        if (rtb_CCaller == 1) {
          PEPSCtl_FRPEAuthentAcsd = 1U;
          tmp = AppSwcBcm_ARID_DEF.count_j + 1;
          if (AppSwcBcm_ARID_DEF.count_j + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_j = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_j + 1;
          if (AppSwcBcm_ARID_DEF.count_j + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_j = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_j + 1;
          if (AppSwcBcm_ARID_DEF.count_j + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_j = (uint8)tmp;
        }

        if (rtb_CCaller == 0) {
          if (AppSwcBcm_ARID_DEF.count1_e >= 150) {
            PEPSCtl_FRPEAuthentAcsd = 2U;
            AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 1U;
            AppSwcBcm_ARID_DEF.count1_e = 0U;
          } else {
            tmp = AppSwcBcm_ARID_DEF.count1_e + 1;
            if (AppSwcBcm_ARID_DEF.count1_e + 1 > 255) {
              tmp = 255;
            }

            AppSwcBcm_ARID_DEF.count1_e = (uint8)tmp;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S218>/Chart' */

  /* Chart: '<S218>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count_h = 0.0;
    PEPSCtl_AvaluebleKeyInCar = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    PEPSCtl_AvaluebleKeyInCar = 0U;
    if (AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar == 1.0F) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_g;
      AppSwcBcm_ARID_DEF.count_h = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_AvaluebleKeyInCar = 1U;
    if (AppSwcBcm_ARID_DEF.count_h >= 1000.0) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      AppSwcBcm_ARID_DEF.count_h = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count_h++;
    }
  }

  /* End of Chart: '<S218>/Chart3' */

  /* Logic: '<S217>/Logical Operator2' incorporates:
   *  Constant: '<S222>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S222>/Compare'
   */
  rtb_LogicalOperator2_f4z = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())
    ->BodyWarnSts == 0);

  /* Logic: '<S216>/Logical Operator' incorporates:
   *  Constant: '<S223>/Constant'
   *  RelationalOperator: '<S223>/Compare'
   *  UnitDelay: '<S216>/Unit Delay'
   */
  rtb_RelationalOperator4_f2 = (rtb_LogicalOperator2_f4z &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o2 > 0));

  /* CCaller: '<S216>/C Caller1' */
  rtb_CCaller = Get_FobdKeyNum();

  /* Chart: '<S216>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib) {
     case AppSwcBcm_IN_FobidKey:
      if ((PEPSCtl_FrbdnKeyNr > 0) || (AppSwcBcm_ARID_DEF.count_bj > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      } else if (rtb_RelationalOperator4_f2) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_bj = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_bj + 1;
        if (AppSwcBcm_ARID_DEF.count_bj + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_bj = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     case AppSwcBcm_IN_Init:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->OsLckSta == 2) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_FobidKey;
        AppSwcBcm_ARID_DEF.count_bj = 0U;
        Set_PSAuth_FobReq(2U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else if (rtb_RelationalOperator4_f2) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_bj = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     default:
      /* case IN_RelesKey: */
      if ((PEPSCtl_FrbdnKeyNr == 0) || (AppSwcBcm_ARID_DEF.count_bj > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_bj + 1;
        if (AppSwcBcm_ARID_DEF.count_bj + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_bj = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;
    }
  }

  /* End of Chart: '<S216>/Chart' */

  /* CCaller: '<S215>/C Caller1' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Logic: '<S217>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S219>/Relational Operator5'
   */
  rtb_LogicalOperator2_f4z = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())
    ->BrakeLightSw;

  /* Logic: '<S219>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S219>/Relational Operator4'
   *  UnitDelay: '<S219>/Unit Delay1'
   */
  rtb_RelationalOperator4_f2 = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_n) &&
    rtb_LogicalOperator2_f4z);

  /* Logic: '<S217>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S219>/Relational Operator2'
   */
  rtb_LogicalOperator2_f4z = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DrvSeatSw;

  /* RelationalOperator: '<S228>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S219>/Relational Operator3'
   */
  rtb_Compare_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S219>/Chart' incorporates:
   *  Logic: '<S219>/Logical Operator1'
   *  Logic: '<S219>/Logical Operator2'
   *  Logic: '<S219>/Logical Operator5'
   *  RelationalOperator: '<S219>/Relational Operator1'
   *  RelationalOperator: '<S219>/Relational Operator6'
   *  UnitDelay: '<S219>/Unit Delay'
   *  UnitDelay: '<S219>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
    PEPSCtl_PSAuthentRes = 0U;
    AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
    AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
    PEPSCtl_PSReq = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    PEPSCtl_PSReq = 0U;
    if ((rtb_RelationalOperator4_f2 || ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jf)
          && rtb_LogicalOperator2_f4z)) &&
        (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k == 0) && rtb_Compare_l) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_PSSeekKeyOut;
      AppSwcBcm_ARID_DEF.count_l = 0U;
      AppSwcBcm_ARID_DEF.count1_d = 0U;
      Set_PSAuth_FobReq(1U);
      PEPSCtl_PSReq = 1U;
    }
  } else {
    /* case IN_PSSeekKeyOut: */
    PEPSCtl_PSReq = 1U;
    if (AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg == 1) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
      PEPSCtl_PSAuthentRes = 0U;
      AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
      AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
      PEPSCtl_PSReq = 0U;
      Clear_PSStatus();
    } else {
      tmp = AppSwcBcm_ARID_DEF.count_l + 1;
      if (AppSwcBcm_ARID_DEF.count_l + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.count_l = (uint16)tmp;
      if (rtb_CCaller == 1) {
        if (AppSwcBcm_ARID_DEF.count1_d >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 1U;
          tmp = AppSwcBcm_ARID_DEF.count1_d + 1;
          if (AppSwcBcm_ARID_DEF.count1_d + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_d = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 2) {
        if (AppSwcBcm_ARID_DEF.count1_d >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          tmp = AppSwcBcm_ARID_DEF.count1_d + 1;
          if (AppSwcBcm_ARID_DEF.count1_d + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_d = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 3) {
        if (AppSwcBcm_ARID_DEF.count1_d >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 3U;
          tmp = AppSwcBcm_ARID_DEF.count1_d + 1;
          if (AppSwcBcm_ARID_DEF.count1_d + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_d = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 0) {
        if (AppSwcBcm_ARID_DEF.count_l >= 200) {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 0U;
        }
      }
    }
  }

  /* End of Chart: '<S219>/Chart' */

  /* Chart: '<S219>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
    AppSwcBcm_ARID_DEF.count_n = 0.0;
    PEPSCtl_KeySta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib) {
     case AppSwcBcm_IN_IMMOKeyValid:
      PEPSCtl_KeySta = 3U;
      if (AppSwcBcm_ARID_DEF.count_n >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
        AppSwcBcm_ARID_DEF.count_n = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_n++;
      }
      break;

     case AppSwcBcm_IN_Init:
      PEPSCtl_KeySta = 0U;
      switch (AppSwcBcm_ARID_DEF.BCM_KeySta) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_RemoteKeyValid;
        AppSwcBcm_ARID_DEF.count_n = 0.0;
        PEPSCtl_KeySta = 1U;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_IMMOKeyValid;
        AppSwcBcm_ARID_DEF.count_n = 0.0;
        PEPSCtl_KeySta = 3U;
        break;
      }
      break;

     default:
      /* case IN_RemoteKeyValid: */
      PEPSCtl_KeySta = 1U;
      if (AppSwcBcm_ARID_DEF.count_n >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
        AppSwcBcm_ARID_DEF.count_n = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_n++;
      }
      break;
    }
  }

  /* End of Chart: '<S219>/Chart1' */

  /* Chart: '<S219>/Chart2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_m = AppSwcBcm_ARID_DEF.Power_Mode_start_i;
  AppSwcBcm_ARID_DEF.Power_Mode_start_i =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_m =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    PEPSCtl_IndicationKeyCloser = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_l:
      PEPSCtl_WarnNoKeyFound = 0U;
      PEPSCtl_IndicationKeyCloser = 0U;
      if (AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound == 1) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_SendNOKey;
        AppSwcBcm_ARID_DEF.count = 0.0;
        PEPSCtl_WarnNoKeyFound = 1U;
      }
      break;

     case AppSwcBcm_IN_NokeyTimecount:
      PEPSCtl_WarnNoKeyFound = 0U;
      if ((AppSwcBcm_ARID_DEF.count < 2000.0) &&
          (AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound == 1)) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_SendKeyCloser;
        AppSwcBcm_ARID_DEF.count = 0.0;
        PEPSCtl_IndicationKeyCloser = 1U;
      } else if ((AppSwcBcm_ARID_DEF.count >= 2000.0) ||
                 ((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
                   AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
                  (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 2)) ||
                 ((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
                   AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
                  (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 0)) ||
                 ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
                   AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
                  (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        AppSwcBcm_ARID_DEF.count = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
        PEPSCtl_IndicationKeyCloser = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count++;
      }
      break;

     case AppSwcBcm_IN_SendKeyCloser:
      PEPSCtl_IndicationKeyCloser = 1U;
      if ((AppSwcBcm_ARID_DEF.count >= 1000.0) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 2)) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 0)) ||
          ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
            AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
           (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        AppSwcBcm_ARID_DEF.count = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
        PEPSCtl_IndicationKeyCloser = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count++;
      }
      break;

     default:
      /* case IN_SendNOKey: */
      PEPSCtl_WarnNoKeyFound = 1U;
      if (((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 2)) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 0)) ||
          ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
            AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
           (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        AppSwcBcm_ARID_DEF.count = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
        PEPSCtl_IndicationKeyCloser = 0U;
      } else if (AppSwcBcm_ARID_DEF.count >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_NokeyTimecount;
        AppSwcBcm_ARID_DEF.count = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count++;
      }
      break;
    }
  }

  /* End of Chart: '<S219>/Chart2' */

  /* Chart: '<S219>/Chart5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev = AppSwcBcm_ARID_DEF.Power_Mode_start;
  AppSwcBcm_ARID_DEF.Power_Mode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  if (AppSwcBcm_ARID_DEF.is_active_c12_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.is_active_c12_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_Init;
    PEPSCtl_IMMOKey = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib == AppSwcBcm_IN_IMMOKeyValid)
  {
    PEPSCtl_IMMOKey = 1U;
    if ((AppSwcBcm_ARID_DEF.Power_Mode_prev !=
         AppSwcBcm_ARID_DEF.Power_Mode_start) &&
        (AppSwcBcm_ARID_DEF.Power_Mode_start == 0)) {
      AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      PEPSCtl_IMMOKey = 0U;
    }
  } else {
    /* case IN_Init: */
    PEPSCtl_IMMOKey = 0U;
    if (AppSwcBcm_ARID_DEF.BCM_KeySta == 3) {
      AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_IMMOKeyValid;
      PEPSCtl_IMMOKey = 1U;
    }
  }

  /* End of Chart: '<S219>/Chart5' */

  /* CCaller: '<S215>/C Caller2' */
  rtb_CCaller = Get_Wlcm_FunStatus();

  /* CCaller: '<S215>/C Caller3' */
  Get_PollingWork_State();

  /* RelationalOperator: '<S228>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S220>/Relational Operator3'
   */
  rtb_Compare_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())
                   ->BodyWarnSts > 0);

  /* Switch: '<S220>/Switch' incorporates:
   *  Constant: '<S220>/Constant4'
   *  Logic: '<S220>/Logical Operator5'
   *  RelationalOperator: '<S220>/Relational Operator2'
   *  UnitDelay: '<S220>/Unit Delay'
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i != 0) || (!rtb_Compare_l)) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p = 0U;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Logic: '<S217>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S220>/Relational Operator5'
   */
  rtb_LogicalOperator2_f4z = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S228>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S220>/Relational Operator1'
   */
  rtb_Compare_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S220>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S220>/Relational Operator6'
   */
  rtb_RelationalOperator4_f2 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S228>/Compare' incorporates:
   *  Logic: '<S220>/Logical Operator7'
   */
  rtb_Compare_l = (rtb_Compare_l || rtb_RelationalOperator4_f2);

  /* Logic: '<S220>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  rtb_LogicalOperator = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p != 0) &&
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC())
     ->VIPM_HUIllmndEntrySts_enum != 0) && rtb_LogicalOperator2_f4z &&
    rtb_Compare_l);

  /* Logic: '<S220>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator1 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarRRSw);

  /* Switch: '<S220>/Switch1' incorporates:
   *  Logic: '<S220>/Logical Operator2'
   *  Logic: '<S220>/Logical Operator3'
   *  UnitDelay: '<S220>/Unit Delay2'
   *  UnitDelay: '<S220>/Unit Delay3'
   */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_m =
    ((!AppSwcBcm_ARID_DEF.LogicalOperator1) &&
     AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_f &&
     AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_m);

  /* RelationalOperator: '<S220>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator4_f2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 0);

  /* Logic: '<S220>/Logical Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S220>/Logical Operator4'
   *  UnitDelay: '<S220>/Unit Delay3'
   */
  rtb_RelationalOperator4_f2 = (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_m &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw &&
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC())
     ->VIPM_HUIllmndEntrySts_enum != 0) && (!rtb_LogicalOperator2_f4z) &&
    rtb_Compare_l && rtb_RelationalOperator4_f2);

  /* Chart: '<S220>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_l:
      if (rtb_LogicalOperator) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_UnlockDay0to7;
      } else if (rtb_RelationalOperator4_f2) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_LockWlcm;
      }
      break;

     case AppSwcBcm_IN_LockWlcm:
      if (rtb_CCaller == 3) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmLockReq;
        PEPSCtl_LckWlcmReq = 1U;
        AppSwcBcm_ARID_DEF.count_lg = 0U;
      }
      break;

     case AppSwcBcm_IN_UnlockDay0to7:
      if (rtb_CCaller == 2) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmUnlockReq;
        PEPSCtl_UnlckWlcmReq = 1U;
        AppSwcBcm_ARID_DEF.count_lg = 0U;
      }
      break;

     case AppSwcBcm_IN_UnlockExcedDay7:
      break;

     case AppSwcBcm_IN_WlcmLockReq:
      PEPSCtl_LckWlcmReq = 1U;
      if (AppSwcBcm_ARID_DEF.count_lg > 20) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      } else {
        tmp = (sint32)(AppSwcBcm_ARID_DEF.count_lg + 1U);
        if (AppSwcBcm_ARID_DEF.count_lg + 1U > 255U) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.count_lg = (uint8)tmp;
      }
      break;

     default:
      /* case IN_WlcmUnlockReq: */
      PEPSCtl_UnlckWlcmReq = 1U;
      if (AppSwcBcm_ARID_DEF.count_lg > 20) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      } else {
        tmp = (sint32)(AppSwcBcm_ARID_DEF.count_lg + 1U);
        if (AppSwcBcm_ARID_DEF.count_lg + 1U > 255U) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.count_lg = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S220>/Chart' */

  /* Logic: '<S217>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator1'
   */
  rtb_LogicalOperator2_f4z = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw);

  /* RelationalOperator: '<S228>/Compare' incorporates:
   *  Constant: '<S228>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_Compare_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode ==
                   2);

  /* Logic: '<S217>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator'
   *  Logic: '<S217>/Logical Operator2'
   *  RelationalOperator: '<S226>/Compare'
   *  RelationalOperator: '<S227>/Compare'
   *  UnitDelay: '<S217>/Unit Delay'
   *  UnitDelay: '<S217>/Unit Delay1'
   */
  rtb_RelationalOperator4_f2 = (rtb_LogicalOperator2_f4z &&
    ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nj) ||
     (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i3)) && rtb_Compare_l &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->VehStop &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw);

  /* CCaller: '<S217>/C Caller7' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Chart: '<S217>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.KeyNotFound_flg = 0.0;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    if (rtb_RelationalOperator4_f2) {
      AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_KeyNotInCar;
      AppSwcBcm_ARID_DEF.count_c = 0U;
      AppSwcBcm_ARID_DEF.count1 = 0.0;
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
      Set_PSAuth_FobReq(1U);
    }

    /* case IN_KeyNotInCar: */
  } else if (AppSwcBcm_ARID_DEF.Warnkeyout_flg == 1) {
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.KeyNotFound_flg = 0.0;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else {
    if (rtb_CCaller == 2) {
      AppSwcBcm_ARID_DEF.KeyNotFound_flg = 1.0;
      PEPSCtl_WarnKeyOutReminder = 1U;
    }

    if (AppSwcBcm_ARID_DEF.KeyNotFound_flg == 1.0) {
      if (AppSwcBcm_ARID_DEF.count_c >= 1000) {
        AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
        AppSwcBcm_ARID_DEF.count_c = 1000U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_c + 1;
        if (AppSwcBcm_ARID_DEF.count_c + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_c = (uint16)tmp;
      }
    }

    if (rtb_CCaller == 1) {
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
    }

    if (rtb_CCaller == 0) {
      if (AppSwcBcm_ARID_DEF.count1 >= 200.0) {
        AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
        AppSwcBcm_ARID_DEF.count1 = 200.0;
      } else {
        AppSwcBcm_ARID_DEF.count1++;
      }
    }
  }

  /* End of Chart: '<S217>/Chart' */

  /* CCaller: '<S215>/C Caller7' */
  rtb_CCaller = Get_KeyBat_VolLow();

  /* Chart: '<S217>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c9_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Init;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Finish:
      PEPSCtl_KeyLoBattLvlWarn = 0U;
      break;

     case AppSwcBcm_IN_Init:
      if (rtb_CCaller == 1) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid;
        AppSwcBcm_ARID_DEF.count_b = 0.0;
        PEPSCtl_KeyLoBattLvlWarn = 1U;
      }
      break;

     default:
      /* case IN_KeyValid: */
      PEPSCtl_KeyLoBattLvlWarn = 1U;
      if (AppSwcBcm_ARID_DEF.count_b >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Finish;
        PEPSCtl_KeyLoBattLvlWarn = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_b++;
      }
      break;
    }
  }

  /* End of Chart: '<S217>/Chart3' */
}

/* Update for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl_Update(void)
{
  /* Update for UnitDelay: '<S218>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cs =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw;

  /* Update for UnitDelay: '<S218>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_j =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw;

  /* Update for UnitDelay: '<S216>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o2 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S219>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_n =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S219>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jf =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* Update for UnitDelay: '<S219>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k = PEPSCtl_KeySta;

  /* Update for UnitDelay: '<S220>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S220>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_f = AppSwcBcm_ARID_DEF.LogicalOperator1;

  /* Update for UnitDelay: '<S217>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nj =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Update for UnitDelay: '<S217>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i3 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw;
}

/* Output and update for atomic system: '<S238>/HwOutBCM' */
static void AppSwcBcm_HwOutBCM(void)
{
  uint8 rtb_DataTypeConversion30;

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion14'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J421IG1RlyCtl;

  /* CCaller: '<S243>/HwIG1RlyCls' */
  SetHw_IG1RlyCls(rtb_DataTypeConversion30);

  /* CCaller: '<S243>/HwHzrdLampOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion16'
   *  Logic: '<S266>/Logical Operator'
   *  Logic: '<S266>/Logical Operator1'
   *  RelationalOperator: '<S266>/Relational Operator'
   */
  SetHw_HzrdLampOn((uint8)(AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta &&
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta &&
    (AppSwcBcm_ARID_DEF.BusCreator.HazardLightSta ||
     AppSwcBcm_ARID_DEF.BusCreator.EmerHazardLightSta)));

  /* CCaller: '<S243>/HwCabinLampPWM' incorporates:
   *  Constant: '<S243>/Constant43'
   */
  SetHw_CabinLampPWM(200U, AppSwcBcm_ARID_DEF.BusCreator.DomeLampPwmDuty);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion15'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J437IG2RlyCtl;

  /* CCaller: '<S243>/HwIG2RlyCls' */
  SetHw_IG2RlyCls(rtb_DataTypeConversion30);

  /* CCaller: '<S243>/HwBackLightCtl' incorporates:
   *  Constant: '<S243>/Constant'
   */
  SetHw_BackLightDrv(100U, AppSwcBcm_ARID_DEF.BusCreator.J408BackLampPWM);

  /* CCaller: '<S243>/HwDrvSeatHeatCtl' incorporates:
   *  Constant: '<S243>/Constant1'
   */
  SetHw_DrvSeatHeat(200U, AppSwcBcm_ARID_DEF.SeatCtl_Bus.CN167DrvSeatHtPWM);

  /* CCaller: '<S243>/HwWiprOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion'
   */
  SetHw_WiprOn(AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv);

  /* CCaller: '<S243>/HwWiprHiSpd' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion1'
   */
  SetHw_WiprHiSpd(AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv);

  /* CCaller: '<S243>/HwFrntWshrOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion2'
   */
  SetHw_FrntWshrOn(AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion3'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J56DoorUnlck;

  /* CCaller: '<S243>/HwGlbDoorUnlck' */
  SetHw_GlbDoorUnlck(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion4'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J54DoorLck;

  /* CCaller: '<S243>/HwGlbDoorLck' */
  SetHw_GlbDoorLck(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion5'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J51DrvWinUp;

  /* CCaller: '<S243>/HwDrvrWinUp' */
  SetHw_DrvrWinUp(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion6'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J53DrvWinDn;

  /* CCaller: '<S243>/HwDrvrWinDwn' */
  SetHw_DrvrWinDwn(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion7'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J55PsgWinUp;

  /* CCaller: '<S243>/HwPsngrWinUp' */
  SetHw_PsngrWinUp(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion8'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J57PsgWinDn;

  /* CCaller: '<S243>/HwPsngrWinDwn' */
  SetHw_PsngrWinDwn(rtb_DataTypeConversion30);

  /* CCaller: '<S243>/HwPstnLampOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion9'
   */
  SetHw_PstnLampOn(AppSwcBcm_ARID_DEF.BusCreator.PosLampSta);

  /* CCaller: '<S243>/HwTurnLampOnLeft' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion10'
   */
  SetHw_TurnLampOnLeft(AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta);

  /* CCaller: '<S243>/HwTurnLampOnRght' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion11'
   */
  SetHw_TurnLampOnRght(AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta);

  /* CCaller: '<S243>/HwBrkLghtOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion12'
   */
  SetHw_BrkLghtOn(AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSta);

  /* CCaller: '<S243>/HwRvrsLampOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion13'
   */
  SetHw_RvrsLampOn(AppSwcBcm_ARID_DEF.BusCreator.ReverseLampSta);

  /* CCaller: '<S243>/HwLoBeamOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion17'
   */
  SetHw_LoBeamOn(AppSwcBcm_ARID_DEF.BusCreator.LowBeamSta);

  /* CCaller: '<S243>/HwHiBeamOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion18'
   */
  SetHw_HiBeamOn(AppSwcBcm_ARID_DEF.BusCreator.HiBeamSta);

  /* CCaller: '<S243>/HwAlrmHornOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion19'
   */
  SetHw_AlrmHornOn(AppSwcBcm_ARID_DEF.BusCreator9.HornDrv);

  /* CCaller: '<S243>/HwRearFogLampOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion20'
   */
  SetHw_RearFogLampOn(AppSwcBcm_ARID_DEF.BusCreator.FogLampRSta);

  /* CCaller: '<S243>/HwSavePwrEnbl' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion21'
   */
  SetHw_SavePwrEnbl(AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr);

  /* CCaller: '<S243>/HwDayRunLghtOn' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion23'
   */
  SetHw_DayRunLghtOn(AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta);

  /* DataTypeConversion: '<S243>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S243>/DataTypeConversion24'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J511TrunkUnlck;

  /* CCaller: '<S243>/HwTrunkUnlck' */
  Set_TrunkUnLock(rtb_DataTypeConversion30);

  /* CCaller: '<S243>/HwBSDLeftCtl' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion25'
   */
  Set_BSDLeftCtl(AppSwcBcm_ARID_DEF.BusCreator.BSDLeftCtl);

  /* CCaller: '<S243>/HwBSDRightCtl' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion26'
   */
  Set_BSDRightCtl(AppSwcBcm_ARID_DEF.BusCreator.BSDRightCtl);

  /* CCaller: '<S243>/HwESCLPwrSup' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion27'
   */
  SetHw_PwrSup(AppSwcBcm_ARID_DEF.ESCLCtl_Bus.J436PwrSup);

  /* CCaller: '<S243>/HwRVMHeatCtl' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion28'
   */
  SetHw_RearMirrorHeat(AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat);

  /* CCaller: '<S243>/HwBoxLampCtl' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion29'
   */
  SetHw_BoxLampSta(AppSwcBcm_ARID_DEF.BusCreator.BoxLampSta);

  /* CCaller: '<S243>/HwFrontFogLampCtl' incorporates:
   *  DataTypeConversion: '<S243>/DataTypeConversion30'
   */
  SetHw_FrontFogLamps(AppSwcBcm_ARID_DEF.BusCreator.FogLampFSta);
}

/*
 * System initialize for atomic system:
 *    '<S247>/Lib_RiseEdgeDelay'
 *    '<S248>/Lib_RiseEdgeDelay'
 *    '<S248>/Lib_RiseEdgeDelay1'
 *    '<S250>/Lib_RiseEdgeDelay'
 *    '<S250>/Lib_RiseEdgeDelay1'
 *    '<S571>/Lib_RiseEdgeDelay'
 *    '<S847>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S247>/Lib_RiseEdgeDelay'
 *    '<S248>/Lib_RiseEdgeDelay'
 *    '<S248>/Lib_RiseEdgeDelay1'
 *    '<S250>/Lib_RiseEdgeDelay'
 *    '<S250>/Lib_RiseEdgeDelay1'
 *    '<S571>/Lib_RiseEdgeDelay'
 *    '<S847>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16DelayTim, boolean *rty_LIB_blOut,
  ARID_DEF_Lib_RiseEdgeDelay_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rtb_LogicalOperator1_lu;

  /* Outputs for Function Call SubSystem: '<S267>/Lib_RiseEdgeDet' */
  /* Logic: '<S269>/Logical Operator1' incorporates:
   *  UnitDelay: '<S269>/Unit Delay'
   */
  rtb_LogicalOperator1_lu = !AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S269>/Unit Delay' incorporates:
   *  Chart: '<S247>/Lib_RiseEdgeDelay'
   */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_LIB_blIn;

  /* Chart: '<S247>/Lib_RiseEdgeDelay' incorporates:
   *  Logic: '<S269>/Logical Operator'
   */
  if (rtu_LIB_blIn && rtb_LogicalOperator1_lu) {
    AppSwcBcm__ARID_DEF_arg->Cnt = rtu_LIB_u16DelayTim;
    *rty_LIB_blOut = true;
  }

  /* End of Outputs for SubSystem: '<S267>/Lib_RiseEdgeDet' */
  if (AppSwcBcm__ARID_DEF_arg->Cnt <= 0) {
    *rty_LIB_blOut = false;
  } else {
    AppSwcBcm__ARID_DEF_arg->Cnt--;
  }
}

/* System initialize for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx_Init(void)
{
  boolean LIB_blOut_g1;

  /* SystemInitialize for Chart: '<S247>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_go);

  /* SystemInitialize for Chart: '<S248>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_o);

  /* SystemInitialize for Chart: '<S248>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_kz);

  /* SystemInitialize for Chart: '<S250>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_g1);

  /* SystemInitialize for Chart: '<S250>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_g1);
}

/* Output and update for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx(void)
{
  uint8 rtb_MultiportSwitch;
  uint8 rtb_MultiportSwitch_m;
  boolean rtb_RelationalOperator2_op;

  /* DataTypeConversion: '<S238>/Data Type Conversion' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Left =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion1' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Right =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion2' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Rear =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampRSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion3' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLampSta =
    AppSwcBcm_ARID_DEF.BusCreator.PosLampSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion4' incorporates:
   *  Logic: '<S252>/Logical Operator'
   *  Logic: '<S252>/Logical Operator1'
   *  RelationalOperator: '<S252>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardLampSts = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta &&
     AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta &&
     (AppSwcBcm_ARID_DEF.BusCreator.HazardLightSta ||
      AppSwcBcm_ARID_DEF.BusCreator.EmerHazardLightSta));

  /* DataTypeConversion: '<S238>/Data Type Conversion5' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSta =
    AppSwcBcm_ARID_DEF.BusCreator.HiBeamSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion6' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamSta =
    AppSwcBcm_ARID_DEF.BusCreator.LowBeamSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion7' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Front =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampFSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion8' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AutoLampStatus =
    AppSwcBcm_ARID_DEF.BusCreator.AutoLampSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion9' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLightSta =
    AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLampSta =
    AppSwcBcm_ARID_DEF.BusCreator.ReverseLampSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion11' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLampSta =
    AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSta;

  /* MultiPortSwitch: '<S244>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrMod) {
   case 0:
    /* MultiPortSwitch: '<S244>/Multiport Switch' incorporates:
     *  Constant: '<S244>/Constant'
     */
    rtb_MultiportSwitch = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S244>/Multiport Switch' incorporates:
     *  Constant: '<S244>/Constant1'
     */
    rtb_MultiportSwitch = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S244>/Multiport Switch' incorporates:
     *  Constant: '<S244>/Constant2'
     */
    rtb_MultiportSwitch = 4U;
    break;

   case 3:
    /* MultiPortSwitch: '<S244>/Multiport Switch' incorporates:
     *  Constant: '<S244>/Constant3'
     */
    rtb_MultiportSwitch = 1U;
    break;

   case 4:
    /* MultiPortSwitch: '<S244>/Multiport Switch' incorporates:
     *  Constant: '<S244>/Constant4'
     */
    rtb_MultiportSwitch = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S244>/Multiport Switch' incorporates:
     *  UnitDelay: '<S244>/Unit Delay'
     */
    rtb_MultiportSwitch = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g3;
    break;
  }

  /* End of MultiPortSwitch: '<S244>/Multiport Switch' */

  /* Switch: '<S245>/Switch' incorporates:
   *  Constant: '<S245>/Constant'
   *  Constant: '<S245>/Constant2'
   *  Switch: '<S245>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLaneLSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLaneRSw) {
    /* Switch: '<S245>/Switch1' incorporates:
     *  Constant: '<S245>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 2U;
  }

  /* End of Switch: '<S245>/Switch' */

  /* Switch: '<S256>/Switch' incorporates:
   *  Constant: '<S256>/Constant2'
   *  Logic: '<S256>/Logical Operator'
   *  Switch: '<S256>/Switch1'
   *  Switch: '<S256>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.PosLampSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.LowBeamSw ||
             AppSwcBcm_ARID_DEF.BusCreator.HiBeamSw) {
    /* Switch: '<S256>/Switch1' incorporates:
     *  Constant: '<S256>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.AutoLampSw) {
    /* Switch: '<S256>/Switch2' incorporates:
     *  Constant: '<S256>/Constant'
     *  Switch: '<S256>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 3U;
  } else {
    /* Switch: '<S256>/Switch1' incorporates:
     *  Constant: '<S256>/Constant3'
     *  Switch: '<S256>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 0U;
  }

  /* End of Switch: '<S256>/Switch' */

  /* Switch: '<S259>/Switch' incorporates:
   *  Constant: '<S259>/Constant2'
   *  Switch: '<S259>/Switch1'
   *  Switch: '<S259>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.LowBeamSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.HiBeamSw) {
    /* Switch: '<S259>/Switch1' incorporates:
     *  Constant: '<S259>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.PassLightSw) {
    /* Switch: '<S259>/Switch2' incorporates:
     *  Constant: '<S259>/Constant'
     *  Switch: '<S259>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 2U;
  } else {
    /* Switch: '<S259>/Switch1' incorporates:
     *  Constant: '<S259>/Constant3'
     *  Switch: '<S259>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 3U;
  }

  /* End of Switch: '<S259>/Switch' */

  /* RelationalOperator: '<S260>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator7'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->HoodAjarSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion19' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Hood =
    rtb_RelationalOperator2_op;

  /* DataTypeConversion: '<S238>/Data Type Conversion20' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardWarningLightSwSig =
    AppSwcBcm_ARID_DEF.BusCreator.HazardLightSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion21' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntFogLiSwSig =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampFSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion22' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiSwSig =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampRSw;

  /* Switch: '<S260>/Switch' incorporates:
   *  Constant: '<S260>/Constant2'
   *  Constant: '<S260>/Constant4'
   *  Constant: '<S260>/Constant5'
   *  Logic: '<S260>/Logical Operator'
   *  RelationalOperator: '<S260>/Relational Operator'
   *  RelationalOperator: '<S260>/Relational Operator1'
   *  RelationalOperator: '<S260>/Relational Operator2'
   *  RelationalOperator: '<S260>/Relational Operator3'
   *  Switch: '<S260>/Switch1'
   *  Switch: '<S260>/Switch2'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator9.TrunkWarnSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.AntiLckSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.PartArmedSta == 1)) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.ArmedSta != 0) {
    /* Switch: '<S260>/Switch1' incorporates:
     *  Constant: '<S260>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.SeekSta != 0) {
    /* Switch: '<S260>/Switch2' incorporates:
     *  Constant: '<S260>/Constant'
     *  Switch: '<S260>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 4U;
  } else {
    /* Switch: '<S260>/Switch1' incorporates:
     *  Constant: '<S260>/Constant3'
     *  Switch: '<S260>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 0U;
  }

  /* End of Switch: '<S260>/Switch' */

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator6'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion25' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Trunk =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator2'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion26' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator3'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion27' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator4'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRLSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion28' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator5'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion29' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RR =
    rtb_RelationalOperator2_op;

  /* MultiPortSwitch: '<S261>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.BusCreator6.WiperSta) {
   case 0:
    /* MultiPortSwitch: '<S261>/Multiport Switch' incorporates:
     *  Constant: '<S261>/Constant'
     */
    rtb_MultiportSwitch_m = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S261>/Multiport Switch' incorporates:
     *  Constant: '<S261>/Constant1'
     */
    rtb_MultiportSwitch_m = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S261>/Multiport Switch' incorporates:
     *  Constant: '<S261>/Constant2'
     */
    rtb_MultiportSwitch_m = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S261>/Multiport Switch' incorporates:
     *  Constant: '<S261>/Constant3'
     */
    rtb_MultiportSwitch_m = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S261>/Multiport Switch' incorporates:
     *  Constant: '<S261>/Constant4'
     */
    rtb_MultiportSwitch_m = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S261>/Multiport Switch' incorporates:
     *  UnitDelay: '<S261>/Unit Delay'
     */
    rtb_MultiportSwitch_m = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_al;
    break;
  }

  /* End of MultiPortSwitch: '<S261>/Multiport Switch' */

  /* MultiPortSwitch: '<S262>/Multiport Switch' incorporates:
   *  Constant: '<S262>/Constant'
   *  Constant: '<S262>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (!(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvSeatSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 2U;
  }

  /* End of MultiPortSwitch: '<S262>/Multiport Switch' */

  /* DataTypeConversion: '<S238>/Data Type Conversion41' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntWshrSwSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WashSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion42' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWashSts =
    AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv;

  /* Switch: '<S263>/Switch' incorporates:
   *  Constant: '<S263>/Constant2'
   *  Switch: '<S263>/Switch1'
   *  Switch: '<S263>/Switch2'
   *  Switch: '<S263>/Switch3'
   *  Switch: '<S263>/Switch4'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.WiperOffSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperLowSpdSw) {
    /* Switch: '<S263>/Switch1' incorporates:
     *  Constant: '<S263>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperHiSpdSw) {
    /* Switch: '<S263>/Switch2' incorporates:
     *  Constant: '<S263>/Constant'
     *  Switch: '<S263>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperMistSw) {
    /* Switch: '<S263>/Switch3' incorporates:
     *  Constant: '<S263>/Constant3'
     *  Switch: '<S263>/Switch1'
     *  Switch: '<S263>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperInrSw) {
    /* Switch: '<S263>/Switch4' incorporates:
     *  Constant: '<S263>/Constant4'
     *  Switch: '<S263>/Switch1'
     *  Switch: '<S263>/Switch2'
     *  Switch: '<S263>/Switch3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 4U;
  } else {
    /* Switch: '<S263>/Switch2' incorporates:
     *  Constant: '<S263>/Constant5'
     *  Switch: '<S263>/Switch1'
     *  Switch: '<S263>/Switch3'
     *  Switch: '<S263>/Switch4'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 6U;
  }

  /* End of Switch: '<S263>/Switch' */

  /* Switch: '<S264>/Switch' incorporates:
   *  Constant: '<S264>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S264>/Switch1'
   *  Switch: '<S264>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinUpSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinDnSw) {
    /* Switch: '<S264>/Switch1' incorporates:
     *  Constant: '<S264>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinAutoDnSw) {
    /* Switch: '<S264>/Switch2' incorporates:
     *  Constant: '<S264>/Constant'
     *  Switch: '<S264>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 4U;
  } else {
    /* Switch: '<S264>/Switch1' incorporates:
     *  Constant: '<S264>/Constant3'
     *  Switch: '<S264>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 0U;
  }

  /* End of Switch: '<S264>/Switch' */

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Logic: '<S265>/Logical Operator'
   */
  rtb_RelationalOperator2_op = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus()
    )->PsgWinUpSw || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->DrvPsgWinUpSw);

  /* Switch: '<S265>/Switch' incorporates:
   *  Constant: '<S265>/Constant2'
   */
  if (rtb_RelationalOperator2_op) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 1U;
  } else {
    /* Logic: '<S265>/Logical Operator1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator2_op = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
      ->PsgWinDnSw || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
      ->DrvPsgWinDnSw);

    /* Switch: '<S265>/Switch1' */
    if (rtb_RelationalOperator2_op) {
      /* Switch: '<S265>/Switch1' incorporates:
       *  Constant: '<S265>/Constant1'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 3U;
    } else {
      /* Logic: '<S265>/Logical Operator2' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
       */
      rtb_RelationalOperator2_op =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinAutoDnSw ||
         (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinAutoDnSw);

      /* Switch: '<S265>/Switch2' */
      if (rtb_RelationalOperator2_op) {
        /* Switch: '<S265>/Switch1' incorporates:
         *  Constant: '<S265>/Constant'
         */
        AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 4U;
      } else {
        /* Switch: '<S265>/Switch1' incorporates:
         *  Constant: '<S265>/Constant3'
         */
        AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 0U;
      }

      /* End of Switch: '<S265>/Switch2' */
    }

    /* End of Switch: '<S265>/Switch1' */
  }

  /* End of Switch: '<S265>/Switch' */

  /* DataTypeConversion: '<S238>/Data Type Conversion49' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion50' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinSta;

  /* Switch: '<S246>/Switch1' incorporates:
   *  Constant: '<S246>/Constant1'
   *  Logic: '<S246>/Logical Operator'
   *  Switch: '<S246>/Switch'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv &&
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts =
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv;
  }

  /* End of Switch: '<S246>/Switch1' */

  /* DataTypeConversion: '<S238>/Data Type Conversion52' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntLeDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvPESw;

  /* DataTypeConversion: '<S238>/Data Type Conversion53' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntRiDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->PsgPESw;

  /* DataTypeConversion: '<S238>/Data Type Conversion54' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkSwtSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion98' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnNoKeyFound =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnNoKeyFound;

  /* DataTypeConversion: '<S238>/Data Type Conversion55' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* DataTypeConversion: '<S238>/Data Type Conversion97' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSAuthentRes =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSAuthentRes;

  /* DataTypeConversion: '<S238>/Data Type Conversion95' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyInCarSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyInCarSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion94' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->DrvPEAuthentAcsd;

  /* DataTypeConversion: '<S238>/Data Type Conversion72' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FRPEAuthentAcsd;

  /* DataTypeConversion: '<S238>/Data Type Conversion71' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSReq;

  /* DataTypeConversion: '<S238>/Data Type Conversion57' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* DataTypeConversion: '<S238>/Data Type Conversion58' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChgWiperMtMdSwSetFb =
    AppSwcBcm_ARID_DEF.BusCreator6.WiperMaintSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion59' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ParkAutoUnlockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;

  /* DataTypeConversion: '<S238>/Data Type Conversion60' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_OverspdCntrlLockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->SpdCtlLckSetFb;

  /* DataTypeConversion: '<S238>/Data Type Conversion37' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrbdnKeyNr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FrbdnKeyNr;

  /* DataTypeConversion: '<S238>/Data Type Conversion101' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AvaluebleKeyInCar =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->AvaluebleKeyInCar;

  /* DataTypeConversion: '<S238>/Data Type Conversion104' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyLoBattLvlWarn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyLoBattLvlWarn;

  /* DataTypeConversion: '<S238>/Data Type Conversion70' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeySta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeySta;

  /* Chart: '<S247>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S247>/Constant'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(AppSwcBcm_ARID_DEF.BusCreator.WelcomeLampSta, 25,
    &AppSwcBcm_ARID_DEF.LIB_blOut_go,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_c);

  /* DataTypeConversion: '<S238>/Data Type Conversion64' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLampReq =
    AppSwcBcm_ARID_DEF.LIB_blOut_go;

  /* Chart: '<S248>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S248>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeUnlck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_e);

  /* Chart: '<S248>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S248>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeLck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_kz,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1_h);

  /* Switch: '<S248>/Switch' incorporates:
   *  Constant: '<S248>/Constant2'
   *  Constant: '<S248>/Constant4'
   *  Switch: '<S248>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_o) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.LIB_blOut_kz) {
    /* Switch: '<S248>/Switch1' incorporates:
     *  Constant: '<S248>/Constant3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 0U;
  }

  /* End of Switch: '<S248>/Switch' */

  /* DataTypeConversion: '<S238>/Data Type Conversion106' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnKeyOutReminder =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnKeyOutReminder;

  /* DataTypeConversion: '<S238>/Data Type Conversion107' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IndicationKeyCloser =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->IndicationKeyCloser;

  /* DataTypeConversion: '<S238>/Data Type Conversion110' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SteerWhlTemp = (uint8)
    AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.SteerWhlTemp;

  /* DataTypeConversion: '<S238>/Data Type Conversion66' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_MaiDrvrSeatTemp = (uint8)
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.DrvSeatTemp;

  /* DataTypeConversion: '<S238>/Data Type Conversion67' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* DataTypeConversion: '<S238>/Data Type Conversion82' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakePedalSta =
    AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSw;

  /* BusCreator: '<S238>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S238>/Data Type Conversion83'
   *  DataTypeConversion: '<S238>/Data Type Conversion84'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;

  /* Switch: '<S251>/Switch' incorporates:
   *  Constant: '<S251>/Constant2'
   *  Constant: '<S251>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 1U;
  }

  /* End of Switch: '<S251>/Switch' */

  /* DataTypeConversion: '<S238>/Data Type Conversion85' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;

  /* DataTypeConversion: '<S238>/Data Type Conversion86' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockSta_FL =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* DataTypeConversion: '<S238>/Data Type Conversion111' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte0 =
    AppSwcBcm_ARID_DEF.BusCreator6.WiperParkPosSw;

  /* BusCreator: '<S238>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S238>/Data Type Conversion135'
   *  DataTypeConversion: '<S238>/Data Type Conversion136'
   *  DataTypeConversion: '<S238>/Data Type Conversion142'
   *  DataTypeConversion: '<S238>/Data Type Conversion143'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndLckStsFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndUnlockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndUnlockStsFb;

  /* Switch: '<S253>/Switch' incorporates:
   *  Switch: '<S253>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.FlwrMeHomeSta) {
    /* BusCreator: '<S238>/Bus Creator1' incorporates:
     *  Constant: '<S253>/Constant'
     *  DataTypeConversion: '<S238>/Data Type Conversion80'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.WelcomeLampSta) {
    /* Switch: '<S253>/Switch1' incorporates:
     *  BusCreator: '<S238>/Bus Creator1'
     *  Constant: '<S253>/Constant1'
     *  DataTypeConversion: '<S238>/Data Type Conversion80'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 2U;
  } else {
    /* BusCreator: '<S238>/Bus Creator1' incorporates:
     *  Constant: '<S253>/Constant2'
     *  DataTypeConversion: '<S238>/Data Type Conversion80'
     *  Switch: '<S253>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 0U;
  }

  /* End of Switch: '<S253>/Switch' */

  /* Switch: '<S254>/Switch' incorporates:
   *  Switch: '<S254>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRShort) {
    /* BusCreator: '<S238>/Bus Creator1' incorporates:
     *  Constant: '<S254>/Constant'
     *  DataTypeConversion: '<S238>/Data Type Conversion79'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrROpen) {
    /* Switch: '<S254>/Switch1' incorporates:
     *  BusCreator: '<S238>/Bus Creator1'
     *  Constant: '<S254>/Constant1'
     *  DataTypeConversion: '<S238>/Data Type Conversion79'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 2U;
  } else {
    /* BusCreator: '<S238>/Bus Creator1' incorporates:
     *  Constant: '<S254>/Constant2'
     *  DataTypeConversion: '<S238>/Data Type Conversion79'
     *  Switch: '<S254>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S254>/Switch' */

  /* Switch: '<S255>/Switch' incorporates:
   *  Switch: '<S255>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLShort) {
    /* BusCreator: '<S238>/Bus Creator1' incorporates:
     *  Constant: '<S255>/Constant'
     *  DataTypeConversion: '<S238>/Data Type Conversion78'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLOpen) {
    /* Switch: '<S255>/Switch1' incorporates:
     *  BusCreator: '<S238>/Bus Creator1'
     *  Constant: '<S255>/Constant1'
     *  DataTypeConversion: '<S238>/Data Type Conversion78'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 2U;
  } else {
    /* BusCreator: '<S238>/Bus Creator1' incorporates:
     *  Constant: '<S255>/Constant2'
     *  DataTypeConversion: '<S238>/Data Type Conversion78'
     *  Switch: '<S255>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S255>/Switch' */

  /* BusCreator: '<S238>/Bus Creator1' incorporates:
   *  Constant: '<S238>/Constant1'
   *  Constant: '<S238>/Constant10'
   *  Constant: '<S238>/Constant12'
   *  Constant: '<S238>/Constant16'
   *  Constant: '<S238>/Constant17'
   *  Constant: '<S238>/Constant18'
   *  Constant: '<S238>/Constant19'
   *  Constant: '<S238>/Constant2'
   *  Constant: '<S238>/Constant20'
   *  Constant: '<S238>/Constant21'
   *  Constant: '<S238>/Constant23'
   *  Constant: '<S238>/Constant24'
   *  Constant: '<S238>/Constant26'
   *  Constant: '<S238>/Constant29'
   *  Constant: '<S238>/Constant3'
   *  Constant: '<S238>/Constant37'
   *  Constant: '<S238>/Constant38'
   *  Constant: '<S238>/Constant39'
   *  Constant: '<S238>/Constant40'
   *  Constant: '<S238>/Constant41'
   *  Constant: '<S238>/Constant42'
   *  Constant: '<S238>/Constant43'
   *  Constant: '<S238>/Constant44'
   *  Constant: '<S238>/Constant45'
   *  Constant: '<S238>/Constant46'
   *  Constant: '<S238>/Constant47'
   *  Constant: '<S238>/Constant5'
   *  Constant: '<S238>/Constant6'
   *  Constant: '<S238>/Constant7'
   *  Constant: '<S238>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S238>/Data Type Conversion113'
   *  DataTypeConversion: '<S238>/Data Type Conversion114'
   *  DataTypeConversion: '<S238>/Data Type Conversion148'
   *  DataTypeConversion: '<S238>/Data Type Conversion153'
   *  DataTypeConversion: '<S238>/Data Type Conversion155'
   *  DataTypeConversion: '<S238>/Data Type Conversion163'
   *  DataTypeConversion: '<S238>/Data Type Conversion164'
   *  DataTypeConversion: '<S238>/Data Type Conversion73'
   *  DataTypeConversion: '<S238>/Data Type Conversion74'
   *  DataTypeConversion: '<S238>/Data Type Conversion77'
   *  Logic: '<S238>/Logical Operator1'
   *  Logic: '<S257>/Logical Operator'
   *  Logic: '<S258>/Logical Operator'
   * */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockOperationRecord =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DynDID_Bus())->DynDID_DoorOpRecord;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorFlags =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinDnProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinUpProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinMotorLocked);
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorFlags =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinDnProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinUpProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinMotorLocked);
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemoteLockFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RemoteLockFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemotePowerLockFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->RemotePwrLckFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiSwSig = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLiSts = rtb_MultiportSwitch;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightIntensity =
    AppSwcBcm_ARID_DEF.BusCreator.LightIntstSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarStaV_Hood = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FlwrMeHmCtrlFb =
    AppSwcBcm_ARID_DEF.BusCreator.FlwrMeHomeCtlFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LockHornOnStFb =
    AppSwcBcm_ARID_DEF.BusCreator9.LockHoornOnStFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AlrmHornReq =
    AppSwcBcm_ARID_DEF.BusCreator9.AlarmSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperCtrl_Front =
    rtb_MultiportSwitch_m;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WashLiquidLevelWarn =
    AppSwcBcm_ConstB.BCM_WashLiquidLevelWarn;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiprIntlGearSwtSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSig = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChrgLidLockReq = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RKEReq =
    AppSwcBcm_ARID_DEF.BusCreator.RKEReq;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiprIntlTimeSetFb =
    AppSwcBcm_ARID_DEF.BusCreator6.WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkLockSta =
    AppSwcBcm_ARID_DEF.BusCreator12.TrunkLckSw;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkLockSwCtrlFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AuthentKeyNr = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyFrbdn = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyIDFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyLocn = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndEntryStsFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyBattLvlSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyBattLvl = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IndicationShifttoNeutral = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SteerWhlHeatSts =
    AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.SteerWhlHeatSts;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLadjvalFb =
    AppSwcBcm_ARID_DEF.BusCreator.BackLadjvalFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_MaiDrvrSeatSts =
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.MaiDrvSeatStFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSwCtrlFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte1 =
    AppSwcBcm_ARID_DEF.BusCreator.DomeLampPwmDuty;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte2 =
    AppSwcBcm_ARID_DEF.BusCreator.BoxLampSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte3 =
    AppSwcBcm_ARID_DEF.BusCreator.CrashSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte4 =
    AppSwcBcm_ARID_DEF.BusCreator.PartArmedSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte5 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte6 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte7 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte8 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte9 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte10 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte11 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte12 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte13 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte14 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte15 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_VhclSeek =
    AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RFInitSta = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontFogLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamLiFaultFb =
    AppSwcBcm_ARID_DEF.BusCreator.HiBeamShortToBat;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LFInitSta = false;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamLiFaultFb =
    AppSwcBcm_ARID_DEF.BusCreator.LowBeamShortToBat;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.DrvLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.IntLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.PassLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemoteCarSearchFb =
    AppSwcBcm_ARID_DEF.BusCreator.VehSeekStaFb;

  /* BusCreator: '<S238>/Bus Creator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S238>/Data Type Conversion73'
   *  DataTypeConversion: '<S238>/Data Type Conversion74'
   *  DataTypeConversion: '<S238>/Data Type Conversion75'
   *  DataTypeConversion: '<S238>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* BusCreator: '<S238>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion77'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator8'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* BusCreator: '<S238>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion78'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator9'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRLSw;

  /* BusCreator: '<S238>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion79'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator2_op;

  /* Logic: '<S238>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S238>/Logical Operator10'
   */
  rtb_RelationalOperator2_op =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw;

  /* BusCreator: '<S238>/Bus Creator2' incorporates:
   *  Constant: '<S238>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S238>/Data Type Conversion142'
   *  DataTypeConversion: '<S238>/Data Type Conversion143'
   *  DataTypeConversion: '<S238>/Data Type Conversion165'
   *  DataTypeConversion: '<S238>/Data Type Conversion67'
   *  DataTypeConversion: '<S238>/Data Type Conversion80'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAiarSta_RR =
    rtb_RelationalOperator2_op;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.AppSwcBcmVersion = 2U;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_NMReq_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.NMReq;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SleepAllwd_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.SleepAllwd;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* Switch: '<S249>/Switch' incorporates:
   *  Constant: '<S249>/Constant'
   *  Constant: '<S249>/Constant1'
   *  Constant: '<S249>/Constant2'
   *  Constant: '<S249>/Constant4'
   *  RelationalOperator: '<S249>/Relational Operator'
   *  RelationalOperator: '<S249>/Relational Operator1'
   *  Switch: '<S249>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 1) {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      282574488338432ULL;
  } else if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 2) {
    /* Switch: '<S249>/Switch1' incorporates:
     *  Constant: '<S249>/Constant3'
     *  Switch: '<S249>/Switch'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      564049465049088ULL;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl = 0ULL;
  }

  /* End of Switch: '<S249>/Switch' */

  /* Chart: '<S250>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S250>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HULck, 25, &rtb_RelationalOperator2_op,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_f);

  /* Chart: '<S250>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S250>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HUUnlck, 25, &rtb_RelationalOperator2_op,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1);

  /* DataTypeConversion: '<S238>/Data Type Conversion89' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_b =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion90' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion3'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_p =
    AppSwcBcm_ARID_DEF.BusCreator.PosLampSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion91' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion9'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_c =
    AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion92' incorporates:
   *  DataTypeConversion: '<S238>/Data Type Conversion1'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_f =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta;

  /* DataTypeConversion: '<S238>/Data Type Conversion93' incorporates:
   *  Logic: '<S238>/Logical Operator1'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_g = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator.EmerSta ||
     AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLOpen ||
     AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrROpen);

  /* BusCreator: '<S238>/Bus Creator' */
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_subID =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[0];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Status =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[1];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Data_02 =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[2];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Data_03 =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[3];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Data_04 =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[4];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Data_05 =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[5];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Data_06 =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[6];
  AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c.BCM_Learning_Data_07 =
    AppSwcBcm_ARID_DEF.IMMOCtl_Bus.AuthResp[7];

  /* Outputs for Atomic SubSystem: '<S238>/HwOutBCM' */
  AppSwcBcm_HwOutBCM();

  /* End of Outputs for SubSystem: '<S238>/HwOutBCM' */

  /* Update for UnitDelay: '<S244>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g3 = rtb_MultiportSwitch;

  /* Update for UnitDelay: '<S261>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_al = rtb_MultiportSwitch_m;
}

/* Output and update for atomic system: '<S3>/EEReadCtl' */
static void AppSwcBcm_EEReadCtl(void)
{
  uint8 i;

  /* Chart: '<S239>/EEReadCtl' */
  NvmBCmBlock_Imm_ReadData((uint8 *)&AppSwcBcm_ARID_DEF.data1[0], 128U);
  EEReadCtl_CrashSta = AppSwcBcm_ARID_DEF.data1[0];
  EEReadCtl_BodyWarnSts = AppSwcBcm_ARID_DEF.data1[1];
  EEReadCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.data1[2];
  EEReadCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.data1[3];
  EEReadCtl_HazardLightSta = AppSwcBcm_ARID_DEF.data1[4];
  EEReadCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.data1[5];
  EEReadCtl_IllmndUnlckSts = AppSwcBcm_ARID_DEF.data1[6];
  EEReadCtl_SpdCtlLckSet = AppSwcBcm_ARID_DEF.data1[7];
  EEReadCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.data1[8];
  EEReadCtl_LockHoornOnSts = AppSwcBcm_ARID_DEF.data1[9];
  EEReadCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.data1[10];
  EEReadCtl_InrTim = AppSwcBcm_ARID_DEF.data1[11];
  EEReadCtl_TrunkLckSw = AppSwcBcm_ARID_DEF.data1[12];
  EEReadCtl_DriverDoorLckSw = AppSwcBcm_ARID_DEF.data1[13];
  EEReadCtl_DoorAjarFLSw = AppSwcBcm_ARID_DEF.data1[14];
  EEReadCtl_DoorAjarFRSw = AppSwcBcm_ARID_DEF.data1[15];
  EEReadCtl_TrunkSw = AppSwcBcm_ARID_DEF.data1[16];
  EEReadCtl_DoorAjarRLSw = AppSwcBcm_ARID_DEF.data1[17];
  EEReadCtl_DoorAjarRRSw = AppSwcBcm_ARID_DEF.data1[18];
  EEReadCtl_TrunkAjarSw = AppSwcBcm_ARID_DEF.data1[19];
  EEReadCtl_DrvSeatSw = AppSwcBcm_ARID_DEF.data1[20];
  EEReadCtl_RemotePwrLckSta = AppSwcBcm_ARID_DEF.data1[21];
  for (i = 0U; i < 10; i++) {
    EEReadCtl_DoorOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 29];
    EEReadCtl_LocalStartFailOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 39];
    EEReadCtl_RemoteStartFailRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 49];
    EEReadCtl_TrunkOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 59];
  }

  /* End of Chart: '<S239>/EEReadCtl' */
}

/*
 * System initialize for function-call system:
 *    '<S294>/Lib_RiseEdgeDetInit'
 *    '<S302>/Lib_RiseEdgeDetInit'
 *    '<S308>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S296>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S294>/Lib_RiseEdgeDetInit'
 *    '<S302>/Lib_RiseEdgeDetInit'
 *    '<S308>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S296>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S296>/Logical Operator' incorporates:
   *  Delay: '<S296>/Delay'
   *  Logic: '<S296>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S296>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S288>/Lib_EdgeChgDet'
 *    '<S461>/Pri5.AntiLckFunc.Lib_EdgeChgDet'
 *    '<S461>/Pri5.SeekFunc.Lib_EdgeChgDet'
 *    '<S461>/Pri5.ArmedFunc.Lib_EdgeChgDet'
 *    '<S461>/Pri5.PartArmedFunc.Lib_EdgeChgDet'
 *    '<S461>/Pri5.DisarmedFunc.Lib_EdgeChgDet'
 *    '<S547>/Lib_EdgeChgDet'
 */
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S306>/Lib_EdgeChgDet' */
  /* RelationalOperator: '<S307>/Relational Operator' incorporates:
   *  UnitDelay: '<S307>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn != AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S307>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* End of Outputs for SubSystem: '<S306>/Lib_EdgeChgDet' */
}

/*
 * System initialize for atomic system:
 *    '<S317>/Lib_RiseEdgeDetInit'
 *    '<S470>/Lib_RiseEdgeDetInit'
 *    '<S474>/Lib_RiseEdgeDetInit'
 *    '<S477>/Lib_RiseEdgeDetInit'
 *    '<S478>/Lib_RiseEdgeDetInit'
 *    '<S488>/Lib_RiseEdgeDetInit'
 *    '<S516>/Lib_RiseEdgeDetInit'
 *    '<S551>/Lib_RiseEdgeDetInit'
 *    '<S552>/Lib_RiseEdgeDetInit'
 *    '<S553>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_e_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S318>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S317>/Lib_RiseEdgeDetInit'
 *    '<S470>/Lib_RiseEdgeDetInit'
 *    '<S474>/Lib_RiseEdgeDetInit'
 *    '<S477>/Lib_RiseEdgeDetInit'
 *    '<S478>/Lib_RiseEdgeDetInit'
 *    '<S488>/Lib_RiseEdgeDetInit'
 *    '<S516>/Lib_RiseEdgeDetInit'
 *    '<S551>/Lib_RiseEdgeDetInit'
 *    '<S552>/Lib_RiseEdgeDetInit'
 *    '<S553>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_n(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S318>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S318>/Logical Operator' incorporates:
   *  Delay: '<S318>/Delay'
   *  Logic: '<S318>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S318>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S316>/Lib_RiseEdgeDetInit'
 *    '<S469>/Lib_RiseEdgeDetInit'
 *    '<S473>/Lib_RiseEdgeDetInit'
 *    '<S487>/Lib_RiseEdgeDetInit'
 *    '<S515>/Lib_RiseEdgeDetInit'
 *    '<S550>/Lib_RiseEdgeDetInit'
 *    '<S550>/Lib_RiseEdgeDetInit1'
 *    '<S550>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_f_T *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S317>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_e_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S317>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S316>/Lib_RiseEdgeDetInit'
 *    '<S469>/Lib_RiseEdgeDetInit'
 *    '<S473>/Lib_RiseEdgeDetInit'
 *    '<S487>/Lib_RiseEdgeDetInit'
 *    '<S515>/Lib_RiseEdgeDetInit'
 *    '<S550>/Lib_RiseEdgeDetInit'
 *    '<S550>/Lib_RiseEdgeDetInit1'
 *    '<S550>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_nw(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S317>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_n(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S317>/Lib_RiseEdgeDetInit' */
}

/* System initialize for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S286>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_fs = true;

  /* SystemInitialize for Chart: '<S283>/Alarm' incorporates:
   *  SubSystem: '<S294>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ex);

  /* SystemInitialize for Chart: '<S285>/Armed' incorporates:
   *  SubSystem: '<S302>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_b);

  /* SystemInitialize for Chart: '<S290>/PartArmed' incorporates:
   *  SubSystem: '<S308>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

  /* SystemInitialize for Chart: '<S292>/Chart' incorporates:
   *  SubSystem: '<S316>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p4);
}

/* Output and update for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl(void)
{
  sint32 tmp;
  uint16 rtb_HornCtl_DemCnt;
  uint16 rtb_HornCtl_Prd;
  uint16 rtb_HornCtl_Wtd;
  uint8 rtb_HornCtl_Sta;
  boolean aVarTruthTableCondition_4;
  boolean aVarTruthTableCondition_5;
  boolean guard1 = false;
  boolean rtb_RelationalOperator;
  boolean tmp_0;

  /* Chart: '<S287>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S287>/Constant'
   *  Constant: '<S287>/Constant37'
   *  Constant: '<S287>/Constant38'
   *  Constant: '<S287>/Constant39'
   *  RelationalOperator: '<S287>/Relational Operator'
   */
  if (BSW_J319HornSw == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ny >= (float32)HornCtl_HornSwTimValid_C /
         (HornCtl_Ts_C * 100.0F)) && (HornCtl_HornSwTimValid_C != 0xFFFF)) {
      HornCtl_HornSwCtl = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ny++;
      AppSwcBcm_ARID_DEF.cnt_heal_pn = (uint16)((float32)
        HornCtl_HornSwTimInvalid_C / (HornCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ny = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pn == 0) {
      HornCtl_HornSwCtl = false;
    } else if (HornCtl_HornSwTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pn--;
    }
  }

  /* End of Chart: '<S287>/LIB_TPD_10ms' */

  /* Chart: '<S283>/Alarm' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AlarmSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AlarmSta = 1U;
    AppSwcBcm_ARID_DEF.Lib_blIn_pj =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 2);

    /* Outputs for Function Call SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_pj,
      &AppSwcBcm_ARID_DEF.LogicalOperator_hfr,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ex);

    /* End of Outputs for SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_hfr || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AlarmSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AlarmSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_pj =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_pj,
      &AppSwcBcm_ARID_DEF.LogicalOperator_hfr,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ex);

    /* End of Outputs for SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_hfr) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_AlarmSta = 1U;
    }
  }

  /* End of Chart: '<S283>/Alarm' */

  /* RelationalOperator: '<S286>/Relational Operator' incorporates:
   *  Constant: '<S286>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S286>/Relational Operator1'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S286>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_fs) {
    /* Switch: '<S286>/Switch' incorporates:
     *  Constant: '<S286>/Constant'
     *  Constant: '<S286>/Constant5'
     *  RelationalOperator: '<S286>/Relational Operator'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_f = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_f =
        AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts;
    }

    /* End of Switch: '<S286>/Switch' */
  }

  /* Switch: '<S286>/Switch1' incorporates:
   *  Constant: '<S286>/Constant7'
   */
  if (rtb_RelationalOperator) {
    rtb_HornCtl_Sta = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HULckHornOnSt_enum;
  } else {
    rtb_HornCtl_Sta = 0U;
  }

  /* MultiPortSwitch: '<S286>/Multiport Switch' incorporates:
   *  Switch: '<S286>/Switch1'
   */
  switch (rtb_HornCtl_Sta) {
   case 1:
    /* MultiPortSwitch: '<S286>/Multiport Switch' incorporates:
     *  Constant: '<S286>/Constant1'
     */
    HornCtl_LockHoornOnSt = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S286>/Multiport Switch' incorporates:
     *  Constant: '<S286>/Constant2'
     */
    HornCtl_LockHoornOnSt = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S286>/Multiport Switch' incorporates:
     *  Delay: '<S286>/Delay'
     */
    HornCtl_LockHoornOnSt = AppSwcBcm_ARID_DEF.Delay_DSTATE_f;
    break;
  }

  /* End of MultiPortSwitch: '<S286>/Multiport Switch' */

  /* MultiPortSwitch: '<S286>/Multiport Switch1' */
  switch (HornCtl_LockHoornOnSt) {
   case 1:
    /* MultiPortSwitch: '<S286>/Multiport Switch1' incorporates:
     *  Constant: '<S286>/Constant3'
     */
    HornCtl_LockHoornOnStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S286>/Multiport Switch1' incorporates:
     *  Constant: '<S286>/Constant4'
     */
    HornCtl_LockHoornOnStFb = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S286>/Multiport Switch1' */

  /* Chart: '<S284>/AntiLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S240>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AntiLckSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AntiLckSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e >= 3) || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AntiLckSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AntiLckSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_fa =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck;

    /* Outputs for Function Call SubSystem: '<S297>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_fa,
      &AppSwcBcm_ARID_DEF.LogicalOperator_bu,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g2);

    /* End of Outputs for SubSystem: '<S297>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_bu) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_h4 =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck;

      /* Outputs for Function Call SubSystem: '<S297>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_h4,
        &AppSwcBcm_ARID_DEF.LogicalOperator_er,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_ao);

      /* End of Outputs for SubSystem: '<S297>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_er) {
        guard1 = true;
      }
    }

    if (guard1) {
      if (HornCtl_LockHoornOnStFb == 1) {
        AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetON;
        HornCtl_AntiLckSta = 1U;
      }
    }
  }

  /* End of Chart: '<S284>/AntiLck' */

  /* Chart: '<S285>/Armed' incorporates:
   *  UnitDelay: '<S240>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_ArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_ArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e >= 1) ||
        (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) || HornCtl_HornSwCtl)
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_ArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_ArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_pe =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S302>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_pe,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fr,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_b);

    /* End of Outputs for SubSystem: '<S302>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fr && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_ArmedSta = 1U;
    }
  }

  /* End of Chart: '<S285>/Armed' */

  /* Chart: '<S290>/PartArmed' incorporates:
   *  UnitDelay: '<S240>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_PartArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_PartArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e >= 3) ||
        (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) || HornCtl_HornSwCtl)
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_PartArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_PartArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_ab =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3);

    /* Outputs for Function Call SubSystem: '<S308>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_ab,
      &AppSwcBcm_ARID_DEF.LogicalOperator_k5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

    /* End of Outputs for SubSystem: '<S308>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_k5 && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_PartArmedSta = 1U;
    }
  }

  /* End of Chart: '<S290>/PartArmed' */

  /* Chart: '<S291>/Seek' incorporates:
   *  UnitDelay: '<S240>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_SeekSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib) {
     case AppSwcBcm_IN_RKESetON:
      HornCtl_SeekSta = 1U;
      if ((AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta == 0) ||
          (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e >= 1) || HornCtl_HornSwCtl) {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_SeekSta = 0U;
      }
      break;

     case AppSwcBcm_IN_SetOff:
      HornCtl_SeekSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_il = (AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta
        == 1);

      /* Outputs for Function Call SubSystem: '<S311>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_il,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ms,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jd);

      /* End of Outputs for SubSystem: '<S311>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ms && (HornCtl_LockHoornOnStFb == 1))
      {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_RKESetON;
        HornCtl_SeekSta = 1U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_gl =
          (AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta == 2);

        /* Outputs for Function Call SubSystem: '<S311>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_gl,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ai,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_ap);

        /* End of Outputs for SubSystem: '<S311>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ai &&
            (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 2))
        {
          AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_TboxSetON;
          HornCtl_SeekSta = 2U;
        }
      }
      break;

     default:
      /* case IN_TboxSetON: */
      HornCtl_SeekSta = 2U;
      if ((AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta == 0) ||
          (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e >= 1) || HornCtl_HornSwCtl) {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_SeekSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S291>/Seek' */

  /* Chart: '<S292>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S240>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c55_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c55_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_TrunkWarnSta = 0U;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt_e = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib) {
     case AppSwcBcm_IN_Delay:
      if (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_TrunkWarnSta = 0U;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt_e = 0U;
      } else if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3) &&
                 (AppSwcBcm_ARID_DEF.TrunkWarnCnt_e >= HornCtl_TrunkWarnTim_C))
      {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOn;
        HornCtl_TrunkWarnSta = 1U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt_e + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt_e + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt_e = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff:
      HornCtl_TrunkWarnSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_c4 =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S316>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_c4,
        &AppSwcBcm_ARID_DEF.LogicalOperator_af,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p4);

      /* End of Outputs for SubSystem: '<S316>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_af && (HornCtl_LockHoornOnStFb == 1)
          && (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3)) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_Delay;
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt_e + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt_e + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt_e = (uint16)tmp;
      }
      break;

     default:
      /* case IN_SetOn: */
      HornCtl_TrunkWarnSta = 1U;
      if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e >= 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3)) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_TrunkWarnSta = 0U;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt_e = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S292>/Chart' */

  /* Truth Table: '<S240>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  rtb_RelationalOperator = (HornCtl_PartArmedSta == 1);

  /*  Condition #3 */
  /*  Condition #4 */
  aVarTruthTableCondition_4 = (HornCtl_AlarmSta == 1);

  /*  Condition #5 */
  aVarTruthTableCondition_5 = (HornCtl_SeekSta == 1);

  /*  Condition #6 */
  /*  Condition #7 */
  /*  Condition #8 */
  if (HornCtl_HornSwCtl) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    rtb_HornCtl_DemCnt = MAX_uint16_T;
    rtb_HornCtl_Prd = 40U;
    rtb_HornCtl_Wtd = 40U;
    rtb_HornCtl_Sta = 1U;
  } else {
    tmp_0 = !aVarTruthTableCondition_4;
    if (rtb_RelationalOperator && tmp_0) {
      /*  Example action 2 called from D3 column in condition table */
      rtb_HornCtl_DemCnt = 3U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 2U;
    } else if ((!rtb_RelationalOperator) && (HornCtl_ArmedSta == 1) && tmp_0) {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 3U;
    } else if (aVarTruthTableCondition_4) {
      rtb_HornCtl_DemCnt = MAX_uint16_T;
      rtb_HornCtl_Prd = 40U;
      rtb_HornCtl_Wtd = 20U;
      rtb_HornCtl_Sta = 4U;
    } else if (tmp_0 && aVarTruthTableCondition_5) {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 6U;
    } else if (tmp_0 && (!aVarTruthTableCondition_5) && (HornCtl_SeekSta == 2))
    {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 9U;
    } else if (tmp_0 && (HornCtl_AntiLckSta == 1)) {
      rtb_HornCtl_DemCnt = 3U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 7U;
    } else if (tmp_0 && (HornCtl_TrunkWarnSta == 1)) {
      rtb_HornCtl_DemCnt = 3U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 8U;
    } else {
      /*  Default */
      rtb_HornCtl_DemCnt = 0U;
      rtb_HornCtl_Prd = 0U;
      rtb_HornCtl_Wtd = 0U;
      rtb_HornCtl_Sta = 5U;
    }
  }

  /* End of Truth Table: '<S240>/Truth Table' */

  /* RelationalOperator: '<S240>/Relational Operator' incorporates:
   *  UnitDelay: '<S240>/Unit Delay4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_o2 = (rtb_HornCtl_Sta !=
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a);

  /* Chart: '<S240>/LIB_Pulse' incorporates:
   *  SubSystem: '<S288>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_o2,
    &AppSwcBcm_ARID_DEF.RelationalOperator_nr,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet_o);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_nr) {
    AppSwcBcm_ARID_DEF.cnt_c = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e = 0U;
  }

  if (rtb_HornCtl_DemCnt >= 1) {
    if (rtb_HornCtl_DemCnt >= 65535) {
      AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_gd = (AppSwcBcm_ARID_DEF.cnt_c <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_c >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_c = 0U;
      } else {
        AppSwcBcm_ARID_DEF.cnt_c++;
      }
    } else if (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e < rtb_HornCtl_DemCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_gd = (AppSwcBcm_ARID_DEF.cnt_c <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_c >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_c = 0U;
        AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e++;
      } else {
        AppSwcBcm_ARID_DEF.cnt_c++;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_gd = false;
    AppSwcBcm_ARID_DEF.cnt_c = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_e = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S240>/Ovrd1' */
  /* Switch: '<S289>/Switch1' incorporates:
   *  Constant: '<S240>/Constant18'
   */
  if (HornCtl_J430HornDrvOvrdFlg_C) {
    /* Switch: '<S289>/Switch1' incorporates:
     *  Constant: '<S240>/Constant19'
     */
    HornCtl_J430HornDrv = HornCtl_J430HornDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S240>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus())
      ->HornCtlFlg != 0);

    /* Switch: '<S289>/Switch2' */
    if (rtb_RelationalOperator) {
      /* Switch: '<S289>/Switch1' incorporates:
       *  Switch: '<S289>/Switch2'
       */
      HornCtl_J430HornDrv = true;
    } else {
      /* Switch: '<S289>/Switch1' incorporates:
       *  Constant: '<S240>/Constant'
       *  RelationalOperator: '<S240>/Relational Operator1'
       *  Switch: '<S240>/Switch'
       *  Switch: '<S289>/Switch2'
       */
      HornCtl_J430HornDrv =
        ((AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum != 1) &&
         AppSwcBcm_ARID_DEF.LIB_blOut_gd);
    }

    /* End of Switch: '<S289>/Switch2' */
  }

  /* End of Switch: '<S289>/Switch1' */
  /* End of Outputs for SubSystem: '<S240>/Ovrd1' */

  /* Update for Delay: '<S286>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_fs = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_f = HornCtl_LockHoornOnSt;

  /* Update for UnitDelay: '<S240>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a = rtb_HornCtl_Sta;
}

/*
 * Output and update for function-call system:
 *    '<S354>/Lib_RiseEdgeDet'
 *    '<S355>/Lib_RiseEdgeDet'
 *    '<S369>/Lib_RiseEdgeDet'
 *    '<S621>/Wash.Lib_RiseEdgeDet'
 *    '<S672>/Lib_RiseEdgeDet'
 *    '<S734>/Lib_RiseEdgeDet'
 *    '<S742>/Lib_RiseEdgeDet'
 *    '<S747>/Lib_RiseEdgeDet'
 *    '<S762>/Lib_RiseEdgeDet'
 *    '<S826>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_g(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_o_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S359>/Logical Operator' incorporates:
   *  Logic: '<S359>/Logical Operator1'
   *  UnitDelay: '<S359>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S359>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S353>/LIB_Pulse'
 *    '<S353>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse_Init(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt)
{
  *rty_LIB_blOut = false;
  *rty_LIB_u16PrdSucCnt = 0U;
}

/*
 * System reset for atomic system:
 *    '<S353>/LIB_Pulse'
 *    '<S353>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse_Reset(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  AppSwcBcm__ARID_DEF_arg->cnt = 0U;
  *rty_LIB_blOut = false;
  *rty_LIB_u16PrdSucCnt = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S353>/LIB_Pulse'
 *    '<S353>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse(uint16 rtu_LIB_u16PrdDemCnt, uint16
  rtu_LIB_u16Prd, uint16 rtu_LIB_u16Wdt, boolean rtu_LIB_blReset, boolean
  *rty_LIB_blOut, uint16 *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S353>/LIB_Pulse' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blReset;

  /* Outputs for Function Call SubSystem: '<S354>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S354>/Lib_RiseEdgeDet' */

  /* Chart: '<S353>/LIB_Pulse' */
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator) {
    AppSwcBcm__ARID_DEF_arg->cnt = 0U;
  }

  if (rtu_LIB_u16PrdDemCnt >= 1) {
    if (rtu_LIB_u16PrdDemCnt >= 65535) {
      *rty_LIB_blOut = (AppSwcBcm__ARID_DEF_arg->cnt < rtu_LIB_u16Wdt);
      if (AppSwcBcm__ARID_DEF_arg->cnt >= rtu_LIB_u16Prd - 1) {
        AppSwcBcm__ARID_DEF_arg->cnt = 0U;
        *rty_LIB_u16PrdSucCnt = 3U;
      } else {
        AppSwcBcm__ARID_DEF_arg->cnt++;
      }
    } else if (*rty_LIB_u16PrdSucCnt < rtu_LIB_u16PrdDemCnt) {
      *rty_LIB_blOut = (AppSwcBcm__ARID_DEF_arg->cnt < rtu_LIB_u16Wdt);
      if (AppSwcBcm__ARID_DEF_arg->cnt >= rtu_LIB_u16Prd - 1) {
        AppSwcBcm__ARID_DEF_arg->cnt = 0U;
        tmp = *rty_LIB_u16PrdSucCnt + 1;
        if (*rty_LIB_u16PrdSucCnt + 1 > 65535) {
          tmp = 65535;
        }

        *rty_LIB_u16PrdSucCnt = (uint16)tmp;
      } else {
        AppSwcBcm__ARID_DEF_arg->cnt++;
      }
    }
  } else {
    *rty_LIB_blOut = false;
    AppSwcBcm__ARID_DEF_arg->cnt = 0U;
    *rty_LIB_u16PrdSucCnt = 0U;
  }
}

/*
 * Output and update for atomic system:
 *    '<S353>/Truth Table'
 *    '<S353>/Truth Table1'
 */
static void AppSwcBcm_TruthTable(boolean rtu_BSD_LightOn, boolean
  rtu_BSD_LightFlash, uint16 *rty_BSD_LightPrd, uint16 *rty_BSD_LightWdt)
{
  /*  Example condition 1 */
  /*  Example condition 2 */
  if (rtu_BSD_LightOn && (!rtu_BSD_LightFlash)) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    *rty_BSD_LightPrd = 13U;
    *rty_BSD_LightWdt = 13U;
  } else if ((!rtu_BSD_LightOn) && rtu_BSD_LightFlash) {
    *rty_BSD_LightPrd = 13U;
    *rty_BSD_LightWdt = 7U;
  } else {
    /*  Default */
    /*  Example action 2 called from D3 column in condition table */
    *rty_BSD_LightPrd = 0U;
    *rty_BSD_LightWdt = 0U;
  }
}

/* System initialize for atomic system: '<S241>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S319>/Enabled Subsystem' */

  /* SystemInitialize for Chart: '<S353>/LIB_Pulse' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_by,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_f);

  /* SystemInitialize for Chart: '<S353>/LIB_Pulse1' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_g,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt);

  /* End of SystemInitialize for SubSystem: '<S319>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<S241>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl(void)
{
  uint16 rtb_BSD_LightPrd;
  uint16 rtb_BSD_LightWdt;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator8_l;
  boolean rtb_RelationalOperator9_it;

  /* RelationalOperator: '<S319>/Relational Operator' incorporates:
   *  Constant: '<S319>/Constant13'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S319>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S353>/Enable'
   */
  if (rtb_RelationalOperator) {
    if (!AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
      /* SystemReset for Chart: '<S353>/LIB_Pulse' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_by,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_f,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

      /* SystemReset for Chart: '<S353>/LIB_Pulse1' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_g,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);
      AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = true;
    }

    /* RelationalOperator: '<S353>/Relational Operator10' incorporates:
     *  Constant: '<S353>/Constant12'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator1'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 1);

    /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
     *  Constant: '<S353>/Constant3'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator3'
     */
    rtb_RelationalOperator8_l =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 1);

    /* RelationalOperator: '<S353>/Relational Operator9' incorporates:
     *  Constant: '<S353>/Constant4'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator4'
     */
    rtb_RelationalOperator9_it =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 1);

    /* Logic: '<S353>/Logical Operator' */
    rtb_LogicalOperator = (rtb_RelationalOperator || rtb_RelationalOperator8_l ||
      rtb_RelationalOperator9_it);

    /* RelationalOperator: '<S353>/Relational Operator9' incorporates:
     *  Constant: '<S353>/Constant1'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator12'
     */
    rtb_RelationalOperator9_it =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 2);

    /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
     *  Constant: '<S353>/Constant11'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator11'
     */
    rtb_RelationalOperator8_l =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 2);

    /* RelationalOperator: '<S353>/Relational Operator10' incorporates:
     *  Constant: '<S353>/Constant10'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator7'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 2);

    /* Truth Table: '<S353>/Truth Table' incorporates:
     *  Logic: '<S353>/Logical Operator2'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_it ||
                         rtb_RelationalOperator8_l || rtb_RelationalOperator,
                         &rtb_BSD_LightWdt, &rtb_BSD_LightPrd);

    /* Chart: '<S353>/LIB_Pulse' incorporates:
     *  Constant: '<S353>/Constant'
     *  Constant: '<S353>/Constant13'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightWdt, rtb_BSD_LightPrd, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_by,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_f,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

    /* SignalConversion generated from: '<S353>/LampCtl_J420BSDRightCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_by;

    /* RelationalOperator: '<S353>/Relational Operator9' incorporates:
     *  Constant: '<S353>/Constant5'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator5'
     */
    rtb_RelationalOperator9_it =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 1);

    /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
     *  Constant: '<S353>/Constant2'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator2'
     */
    rtb_RelationalOperator8_l =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 1);

    /* RelationalOperator: '<S353>/Relational Operator10' incorporates:
     *  Constant: '<S353>/Constant6'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S353>/Relational Operator6'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 1);

    /* Logic: '<S353>/Logical Operator3' */
    rtb_LogicalOperator = (rtb_RelationalOperator9_it ||
      rtb_RelationalOperator8_l || rtb_RelationalOperator);

    /* RelationalOperator: '<S353>/Relational Operator9' incorporates:
     *  Constant: '<S353>/Constant8'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator9_it =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 2);

    /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
     *  Constant: '<S353>/Constant7'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator8_l =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 2);

    /* RelationalOperator: '<S353>/Relational Operator10' incorporates:
     *  Constant: '<S353>/Constant9'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 2);

    /* Truth Table: '<S353>/Truth Table1' incorporates:
     *  Logic: '<S353>/Logical Operator1'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_it ||
                         rtb_RelationalOperator8_l || rtb_RelationalOperator,
                         &rtb_BSD_LightPrd, &rtb_BSD_LightWdt);

    /* Chart: '<S353>/LIB_Pulse1' incorporates:
     *  Constant: '<S353>/Constant14'
     *  Constant: '<S353>/Constant15'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightPrd, rtb_BSD_LightWdt, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_g,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);

    /* SignalConversion generated from: '<S353>/LampCtl_J422BSDLeftCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_g;
  } else if (AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
    /* Disable for SignalConversion generated from: '<S353>/LampCtl_J420BSDRightCtl' incorporates:
     *  Outport: '<S353>/LampCtl_J420BSDRightCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl = false;

    /* Disable for SignalConversion generated from: '<S353>/LampCtl_J422BSDLeftCtl' incorporates:
     *  Outport: '<S353>/LampCtl_J422BSDLeftCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl = false;
    AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S319>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S320>/LIB_TPD_10ms'
 *    '<S847>/LIB_TPD_10ms11'
 */
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S320>/LIB_TPD_10ms'
 *    '<S847>/LIB_TPD_10ms11'
 */
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  float32 tmp;

  /* Chart: '<S320>/LIB_TPD_10ms' */
  if (rtu_LIB_blIn) {
    tmp = (float32)rtu_LIB_u16tiToDef / (rtu_LIB_s32Ts * 100.0F);
    if ((AppSwcBcm__ARID_DEF_arg->cnt_defect >= tmp) && (rtu_LIB_u16tiToDef !=
         0xFFFF)) {
      *rty_LIB_bErrFlg = true;
    } else {
      AppSwcBcm__ARID_DEF_arg->cnt_defect++;
      AppSwcBcm__ARID_DEF_arg->cnt_heal = (uint16)tmp;
    }
  } else {
    AppSwcBcm__ARID_DEF_arg->cnt_defect = 0U;
    if (AppSwcBcm__ARID_DEF_arg->cnt_heal == 0) {
      *rty_LIB_bErrFlg = false;
    } else if (rtu_LIB_u16tiToDef != 0xFFFF) {
      AppSwcBcm__ARID_DEF_arg->cnt_heal--;
    }
  }

  /* End of Chart: '<S320>/LIB_TPD_10ms' */
}

/*
 * System initialize for atomic system:
 *    '<S320>/LIB_TPD_10ms1'
 *    '<S373>/LIB_TPD_Ts'
 *    '<S373>/LIB_TPD_Ts1'
 *    '<S331>/LIB_TPD_10ms8'
 *    '<S348>/LIB_TPD_10ms8'
 *    '<S350>/LIB_TPD_10ms11'
 *    '<S350>/LIB_TPD_10ms13'
 *    '<S697>/LIB_TPD_10ms'
 *    '<S697>/LIB_TPD_10ms1'
 *    '<S709>/LIB_TPD_10ms'
 *    ...
 */
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S320>/LIB_TPD_10ms1'
 *    '<S373>/LIB_TPD_Ts'
 *    '<S373>/LIB_TPD_Ts1'
 *    '<S331>/LIB_TPD_10ms8'
 *    '<S348>/LIB_TPD_10ms8'
 *    '<S350>/LIB_TPD_10ms11'
 *    '<S350>/LIB_TPD_10ms13'
 *    '<S697>/LIB_TPD_10ms'
 *    '<S697>/LIB_TPD_10ms1'
 *    '<S709>/LIB_TPD_10ms'
 *    ...
 */
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S320>/LIB_TPD_10ms1' */
  if (rtu_LIB_blIn) {
    if ((AppSwcBcm__ARID_DEF_arg->cnt_defect >= (float32)rtu_LIB_u16tiToDef /
         (rtu_LIB_s32Ts * 100.0F)) && (rtu_LIB_u16tiToDef != 0xFFFF)) {
      *rty_LIB_bErrFlg = true;
    } else {
      AppSwcBcm__ARID_DEF_arg->cnt_defect++;
      AppSwcBcm__ARID_DEF_arg->cnt_heal = (uint16)((float32)rtu_LIB_u16tiToOk /
        (rtu_LIB_s32Ts * 100.0F));
    }
  } else {
    AppSwcBcm__ARID_DEF_arg->cnt_defect = 0U;
    if (AppSwcBcm__ARID_DEF_arg->cnt_heal == 0) {
      *rty_LIB_bErrFlg = false;
    } else if (rtu_LIB_u16tiToOk != 0xFFFF) {
      AppSwcBcm__ARID_DEF_arg->cnt_heal--;
    }
  }

  /* End of Chart: '<S320>/LIB_TPD_10ms1' */
}

/* System initialize for atomic system: '<S241>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S320>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);

  /* SystemInitialize for Chart: '<S320>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_bt);
}

/* Output and update for atomic system: '<S241>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl(void)
{
  boolean rtb_RelationalOperator1_fg;

  /* Chart: '<S320>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S320>/Constant4'
   *  Constant: '<S320>/Constant43'
   *  Constant: '<S320>/Constant45'
   *  RelationalOperator: '<S320>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms(LampCtl_LightIntstSta == 2,
    LampCtl_AutoLampNightDelayTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_p);

  /* Chart: '<S320>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S320>/Constant5'
   *  Constant: '<S320>/Constant6'
   *  Constant: '<S320>/Constant7'
   *  Constant: '<S320>/Constant8'
   *  Logic: '<S320>/Logical Operator3'
   *  RelationalOperator: '<S320>/Relational Operator5'
   *  UnitDelay: '<S320>/Unit Delay'
   */
  AppSwcBcm_LIB_TPD_10ms1((LampCtl_LightIntstSta == 1) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mo, LampCtl_AutoLampDayDelayTim_C, 10,
    LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_bt,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_p);

  /* RelationalOperator: '<S320>/Relational Operator1' incorporates:
   *  Constant: '<S320>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_fg = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Switch: '<S364>/Switch' incorporates:
   *  Logic: '<S320>/Logical Operator'
   *  RelationalOperator: '<S320>/Relational Operator2'
   */
  if (rtb_RelationalOperator1_fg || (!LampCtl_AutoLampSw) ||
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_bt) {
    /* Switch: '<S364>/Switch' incorporates:
     *  Constant: '<S364>/Constant'
     */
    LampCtl_AutoLampSta = false;
  } else {
    /* RelationalOperator: '<S320>/Relational Operator' incorporates:
     *  Constant: '<S320>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator1_fg = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);

    /* Switch: '<S364>/Switch' incorporates:
     *  Logic: '<S320>/Logical Operator1'
     *  Logic: '<S320>/Logical Operator2'
     *  Logic: '<S364>/Logical Operator'
     *  UnitDelay: '<S364>/Unit Delay'
     */
    LampCtl_AutoLampSta = ((rtb_RelationalOperator1_fg &&
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_i) || LampCtl_AutoLampSta);
  }

  /* End of Switch: '<S364>/Switch' */

  /* Update for UnitDelay: '<S320>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mo = LampCtl_AutoLampSta;
}

/* System initialize for atomic system: '<S241>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S321>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_e = true;

  /* InitializeConditions for UnitDelay: '<S321>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 20U;
}

/* Output and update for atomic system: '<S241>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl(void)
{
  uint8 tmp;
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S321>/Relational Operator' incorporates:
   *  Constant: '<S321>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S321>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_e) {
    /* Switch: '<S321>/Switch2' incorporates:
     *  Constant: '<S321>/Constant13'
     *  Constant: '<S321>/Constant14'
     *  RelationalOperator: '<S321>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_k = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_k =
        AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb;
    }

    /* End of Switch: '<S321>/Switch2' */
  }

  /* Switch: '<S321>/Switch1' incorporates:
   *  Constant: '<S321>/Constant12'
   */
  if (rtb_RelationalOperator) {
    tmp = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_CDCBackLadjval_enum;
  } else {
    tmp = 0U;
  }

  /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
   *  Switch: '<S321>/Switch1'
   */
  switch (tmp) {
   case 1:
    /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
     *  Constant: '<S321>/Constant1'
     */
    LampCtl_BackLadjvalFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
     *  Constant: '<S321>/Constant2'
     */
    LampCtl_BackLadjvalFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
     *  Constant: '<S321>/Constant3'
     */
    LampCtl_BackLadjvalFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
     *  Constant: '<S321>/Constant4'
     */
    LampCtl_BackLadjvalFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
     *  Constant: '<S321>/Constant5'
     */
    LampCtl_BackLadjvalFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S321>/Multiport Switch' incorporates:
     *  Delay: '<S321>/Delay'
     */
    LampCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_k;
    break;
  }

  /* End of MultiPortSwitch: '<S321>/Multiport Switch' */

  /* MultiPortSwitch: '<S321>/Multiport Switch1' */
  switch (LampCtl_BackLadjvalFb) {
   case 0:
    /* MultiPortSwitch: '<S321>/Multiport Switch1' incorporates:
     *  Constant: '<S321>/Constant6'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 20U;
    break;

   case 1:
    /* MultiPortSwitch: '<S321>/Multiport Switch1' incorporates:
     *  Constant: '<S321>/Constant7'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 40U;
    break;

   case 2:
    /* MultiPortSwitch: '<S321>/Multiport Switch1' incorporates:
     *  Constant: '<S321>/Constant8'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S321>/Multiport Switch1' incorporates:
     *  Constant: '<S321>/Constant9'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 80U;
    break;

   case 4:
    /* MultiPortSwitch: '<S321>/Multiport Switch1' incorporates:
     *  Constant: '<S321>/Constant10'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 100U;
    break;
  }

  /* End of MultiPortSwitch: '<S321>/Multiport Switch1' */

  /* Switch: '<S321>/Switch' incorporates:
   *  Logic: '<S321>/Logical Operator'
   *  Logic: '<S321>/Logical Operator1'
   */
  if (rtb_RelationalOperator && (LampCtl_PosLampSta || LampCtl_LowBeamSta)) {
    /* Switch: '<S321>/Switch' */
    AppSwcBcm_ARID_DEF.Switch_k = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g;
  } else {
    /* Switch: '<S321>/Switch' incorporates:
     *  Constant: '<S321>/Constant11'
     */
    AppSwcBcm_ARID_DEF.Switch_k = 0U;
  }

  /* End of Switch: '<S321>/Switch' */

  /* Update for Delay: '<S321>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_e = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_k = LampCtl_BackLadjvalFb;
}

/*
 * Outputs for atomic system:
 *    '<S322>/Lib_FailEdgeDet'
 *    '<S322>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S365>/Logical Operator' incorporates:
   *  Logic: '<S365>/Logical Operator1'
   *  UnitDelay: '<S365>/Unit Delay'
   */
  return (!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;
}

/*
 * Update for atomic system:
 *    '<S322>/Lib_FailEdgeDet'
 *    '<S322>/Lib_FailEdgeDet1'
 */
static void AppSwcBcm_Lib_FailEdgeDet_Update(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Update for UnitDelay: '<S365>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S368>/LIB_PosPluse2'
 *    '<S727>/LIB_PosPluse2'
 *    '<S909>/LIB_NegPluse2'
 *    '<S910>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S368>/LIB_PosPluse2'
 *    '<S727>/LIB_PosPluse2'
 *    '<S909>/LIB_NegPluse2'
 *    '<S910>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S368>/LIB_PosPluse2' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blRst;

  /* Outputs for Function Call SubSystem: '<S369>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S369>/Lib_RiseEdgeDet' */

  /* Chart: '<S368>/LIB_PosPluse2' */
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator) {
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }

  if (rtu_LIB_blEn) {
    if (AppSwcBcm__ARID_DEF_arg->Cnt <= rtu_LIB_u16Limit) {
      tmp = AppSwcBcm__ARID_DEF_arg->Cnt + 1;
      if (AppSwcBcm__ARID_DEF_arg->Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm__ARID_DEF_arg->Cnt = (uint16)tmp;
      *rty_LIB_blOut = false;
    } else {
      *rty_LIB_blOut = true;
    }
  } else {
    *rty_LIB_blOut = false;
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }
}

/* System initialize for atomic system: '<S241>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;

  /* SystemInitialize for Atomic SubSystem: '<S322>/Trunk10min' */

  /* SystemInitialize for Chart: '<S368>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_l);

  /* End of SystemInitialize for SubSystem: '<S322>/Trunk10min' */
}

/* Outputs for atomic system: '<S241>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_oo;
  boolean rtb_LogicalOperator2_jd;
  boolean rtb_LogicalOperator_j;
  boolean rtb_LogicalOperator_o;
  boolean rtb_Switch;

  /* Logic: '<S366>/Logical Operator' incorporates:
   *  Constant: '<S322>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S322>/Relational Operator1'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S322>/Logical Operator2' incorporates:
   *  Constant: '<S322>/Constant'
   *  RelationalOperator: '<S322>/Relational Operator'
   *  UnitDelay: '<S322>/Unit Delay1'
   */
  rtb_LogicalOperator2_jd = (rtb_LogicalOperator && (LampCtl_LightIntstSta == 2)
    && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_mb);

  /* Outputs for Atomic SubSystem: '<S322>/Lib_FailEdgeDet' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  rtb_LogicalOperator_o = AppSwcBcm_Lib_FailEdgeDet
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_k);

  /* End of Outputs for SubSystem: '<S322>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S322>/Lib_FailEdgeDet1' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_c);

  /* End of Outputs for SubSystem: '<S322>/Lib_FailEdgeDet1' */

  /* Logic: '<S322>/Logical Operator' */
  rtb_LogicalOperator_j = (rtb_LogicalOperator_o || rtb_LogicalOperator);

  /* Outputs for Atomic SubSystem: '<S322>/Trunk10min' */

  /* Chart: '<S368>/LIB_PosPluse2' incorporates:
   *  Constant: '<S322>/Constant4'
   *  UnitDelay: '<S322>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nr,
    LampCtl_BoxLampOpenTimMax_C, rtb_LogicalOperator_j, &rtb_LIB_blOut_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2_m);

  /* End of Outputs for SubSystem: '<S322>/Trunk10min' */

  /* Logic: '<S322>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator1_oo = (rtb_LIB_blOut_l ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->InsLck ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLck);

  /* Outputs for Atomic SubSystem: '<S322>/Lib_SR' */
  AppSwcBcm_Lib_SR(rtb_LogicalOperator_j, rtb_LogicalOperator1_oo, &rtb_Switch,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_h);

  /* End of Outputs for SubSystem: '<S322>/Lib_SR' */

  /* Switch: '<S322>/Switch' incorporates:
   *  UnitDelay: '<S322>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nr = (rtb_LogicalOperator2_jd ||
    rtb_Switch);
}

/* Update for atomic system: '<S241>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Update(void)
{
  /* Update for UnitDelay: '<S322>/Unit Delay1' incorporates:
   *  UnitDelay: '<S322>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_mb =
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nr;

  /* Update for Atomic SubSystem: '<S322>/Lib_FailEdgeDet' */

  /* Update for DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_Lib_FailEdgeDet_Update
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_k);

  /* End of Update for SubSystem: '<S322>/Lib_FailEdgeDet' */

  /* Update for Atomic SubSystem: '<S322>/Lib_FailEdgeDet1' */
  AppSwcBcm_Lib_FailEdgeDet_Update
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_c);

  /* End of Update for SubSystem: '<S322>/Lib_FailEdgeDet1' */
}

/* Output and update for atomic system: '<S241>/DayRunLampCtl' */
static void AppSwcBcm_DayRunLampCtl(void)
{
  boolean rtb_RelationalOperator6_hr;

  /* RelationalOperator: '<S324>/Relational Operator6' incorporates:
   *  Constant: '<S324>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator6_hr = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Outputs for Atomic SubSystem: '<S324>/Lib_SR' */
  /* Switch: '<S372>/Switch' incorporates:
   *  Constant: '<S324>/Constant1'
   *  Constant: '<S324>/Constant2'
   *  Constant: '<S324>/Constant8'
   *  Constant: '<S372>/Constant'
   *  Logic: '<S324>/Logical Operator'
   *  Logic: '<S324>/Logical Operator1'
   *  Logic: '<S372>/Logical Operator'
   *  RelationalOperator: '<S324>/Relational Operator1'
   *  RelationalOperator: '<S324>/Relational Operator2'
   *  RelationalOperator: '<S324>/Relational Operator7'
   *  RelationalOperator: '<S324>/Relational Operator8'
   *  UnitDelay: '<S372>/Unit Delay'
   */
  if (rtb_RelationalOperator6_hr || LampCtl_PosLampSta ||
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VHVM_PTActOprtMode_enum != 2)) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cg = false;
  } else {
    /* RelationalOperator: '<S324>/Relational Operator' incorporates:
     *  Constant: '<S324>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_hr = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cg = ((rtb_RelationalOperator6_hr &&
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VHVM_PTActOprtMode_enum == 2) &&
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VGSM_VehActGearPstn_enum != 0)) ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cg);
  }

  /* End of Switch: '<S372>/Switch' */
  /* End of Outputs for SubSystem: '<S324>/Lib_SR' */
}

/* System initialize for atomic system: '<S241>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S392>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kv = true;

  /* InitializeConditions for Delay: '<S393>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_h = true;

  /* InitializeConditions for Delay: '<S394>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_no = true;

  /* SystemInitialize for Chart: '<S373>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_ow);

  /* SystemInitialize for Chart: '<S373>/LIB_TPD_Ts1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_k);

  /* SystemInitialize for Atomic SubSystem: '<S375>/Lib_RateLimit' */
  /* InitializeConditions for Delay: '<S391>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_p = true;

  /* End of SystemInitialize for SubSystem: '<S375>/Lib_RateLimit' */

  /* SystemInitialize for Truth Table: '<S325>/Truth Table' */
  LampCtl_DomeLampOff = true;
}

/* Outputs for atomic system: '<S241>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl(void)
{
  sint32 Switch;
  float32 rtb_Add;
  boolean rtb_RelationalOperator1_dx;
  boolean rtb_RelationalOperator5_mt;

  /* RelationalOperator: '<S373>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_dx =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Chart: '<S373>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S373>/Constant3'
   *  Constant: '<S373>/Constant4'
   *  Constant: '<S373>/Constant5'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_RelationalOperator1_dx,
    LampCtl_DoorOpenFLValidTim_C, LampCtl_DoorOpenFLInValidTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_ow,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts_m);

  /* Outputs for Atomic SubSystem: '<S373>/FL10min' */
  /* Chart: '<S379>/LIB_Tim' incorporates:
   *  Constant: '<S379>/Constant'
   *  Logic: '<S373>/Logical Operator1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && AppSwcBcm_ARID_DEF.LIB_bErrFlg_ow)
  {
    if (AppSwcBcm_ARID_DEF.Cnt_j <= 30000) {
      AppSwcBcm_ARID_DEF.Cnt_j++;
      LampCtl_DomeLampFLOpen = true;
    } else {
      LampCtl_DomeLampFLOpen = false;
    }
  } else {
    LampCtl_DomeLampFLOpen = false;
    AppSwcBcm_ARID_DEF.Cnt_j = 0U;
  }

  /* End of Chart: '<S379>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S373>/FL10min' */

  /* RelationalOperator: '<S373>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_dx =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* Chart: '<S373>/LIB_TPD_Ts1' incorporates:
   *  Constant: '<S373>/Constant6'
   *  Constant: '<S373>/Constant7'
   *  Constant: '<S373>/Constant8'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_RelationalOperator1_dx,
    LampCtl_DoorOpenFRValidTim_C, LampCtl_DoorOpenFRInValidTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_k, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts1);

  /* Outputs for Atomic SubSystem: '<S373>/FR10min' */
  /* Chart: '<S380>/LIB_Tim' incorporates:
   *  Constant: '<S380>/Constant'
   *  Logic: '<S373>/Logical Operator2'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && AppSwcBcm_ARID_DEF.LIB_bErrFlg_k) {
    if (AppSwcBcm_ARID_DEF.Cnt_hk <= 30000) {
      AppSwcBcm_ARID_DEF.Cnt_hk++;
      LampCtl_DomeLampFROpen = true;
    } else {
      LampCtl_DomeLampFROpen = false;
    }
  } else {
    LampCtl_DomeLampFROpen = false;
    AppSwcBcm_ARID_DEF.Cnt_hk = 0U;
  }

  /* End of Chart: '<S380>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S373>/FR10min' */

  /* RelationalOperator: '<S374>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator5_mt = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFLSw;

  /* RelationalOperator: '<S376>/Relational Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S374>/Relational Operator6'
   */
  rtb_RelationalOperator1_dx = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFRSw;

  /* Logic: '<S374>/Logical Operator5' */
  rtb_RelationalOperator5_mt = (rtb_RelationalOperator5_mt &&
    rtb_RelationalOperator1_dx);

  /* RelationalOperator: '<S374>/Relational Operator3' incorporates:
   *  Constant: '<S374>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_dx = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Outputs for Atomic SubSystem: '<S374>/Lib_FailEdgeDetHold' */
  /* Switch: '<S387>/Switch' incorporates:
   *  Constant: '<S387>/Constant'
   *  Logic: '<S387>/Logical Operator2'
   *  UnitDelay: '<S387>/Unit Delay'
   *  UnitDelay: '<S387>/Unit Delay1'
   */
  if (rtb_RelationalOperator1_dx) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f =
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fgd ||
       AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f);
  }

  /* End of Switch: '<S387>/Switch' */

  /* Update for UnitDelay: '<S387>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fgd = rtb_RelationalOperator1_dx;

  /* End of Outputs for SubSystem: '<S374>/Lib_FailEdgeDetHold' */

  /* RelationalOperator: '<S376>/Relational Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S374>/Relational Operator2'
   */
  rtb_RelationalOperator1_dx =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* Outputs for Atomic SubSystem: '<S374>/30s' */
  /* Chart: '<S385>/LIB_Tim' incorporates:
   *  Constant: '<S385>/Constant'
   *  Logic: '<S374>/Logical Operator4'
   *  UnitDelay: '<S387>/Unit Delay1'
   */
  if (rtb_RelationalOperator5_mt && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f &&
      rtb_RelationalOperator1_dx && AppSwcBcm_ConstB.RelationalOperator1_j) {
    if (AppSwcBcm_ARID_DEF.Cnt_eq <= 1500) {
      AppSwcBcm_ARID_DEF.Cnt_eq++;
      LampCtl_DomeLampPwrOff = true;
    } else {
      LampCtl_DomeLampPwrOff = false;
    }
  } else {
    LampCtl_DomeLampPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_eq = 0U;
  }

  /* End of Chart: '<S385>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S374>/30s' */

  /* Outputs for Atomic SubSystem: '<S374>/Lib_FailEdgeDetHold1' */
  /* Switch: '<S388>/Switch' incorporates:
   *  Constant: '<S388>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S388>/Logical Operator'
   *  Logic: '<S388>/Logical Operator2'
   *  UnitDelay: '<S388>/Unit Delay'
   *  UnitDelay: '<S388>/Unit Delay1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l = false;
  } else {
    /* Logic: '<S388>/Logical Operator1' */
    rtb_RelationalOperator1_dx =
      !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l = ((rtb_RelationalOperator1_dx &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gk) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l);
  }

  /* End of Switch: '<S388>/Switch' */
  /* End of Outputs for SubSystem: '<S374>/Lib_FailEdgeDetHold1' */

  /* RelationalOperator: '<S376>/Relational Operator7' incorporates:
   *  Constant: '<S374>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S374>/Relational Operator4'
   */
  rtb_RelationalOperator1_dx = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Outputs for Atomic SubSystem: '<S374>/30s1' */
  /* Chart: '<S386>/LIB_Tim' incorporates:
   *  Constant: '<S386>/Constant'
   *  Logic: '<S374>/Logical Operator1'
   *  UnitDelay: '<S388>/Unit Delay1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator1_j &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l && rtb_RelationalOperator1_dx) {
    if (AppSwcBcm_ARID_DEF.Cnt_hv <= 1500) {
      AppSwcBcm_ARID_DEF.Cnt_hv++;
      LampCtl_DomeLampUnlock = true;
    } else {
      LampCtl_DomeLampUnlock = false;
    }
  } else {
    LampCtl_DomeLampUnlock = false;
    AppSwcBcm_ARID_DEF.Cnt_hv = 0U;
  }

  /* End of Chart: '<S386>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S374>/30s1' */

  /* RelationalOperator: '<S376>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4_l =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* Delay: '<S392>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_kv) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_mm =
      AppSwcBcm_ARID_DEF.RelationalOperator4_l;
  }

  /* Logic: '<S392>/Logical Operator' incorporates:
   *  Delay: '<S392>/Delay'
   *  Logic: '<S392>/Logical Operator1'
   */
  LampCtl_DomeLampLockDoor = (AppSwcBcm_ARID_DEF.RelationalOperator4_l &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_mm));

  /* RelationalOperator: '<S376>/Relational Operator7' incorporates:
   *  Constant: '<S376>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_dx = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* RelationalOperator: '<S376>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8_i =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Delay: '<S393>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_h) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_n2 =
      AppSwcBcm_ARID_DEF.RelationalOperator8_i;
  }

  /* RelationalOperator: '<S376>/Relational Operator9' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9_m =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* Delay: '<S394>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_no) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_bf =
      AppSwcBcm_ARID_DEF.RelationalOperator9_m;
  }

  /* Logic: '<S376>/Logical Operator6' incorporates:
   *  Delay: '<S393>/Delay'
   *  Delay: '<S394>/Delay'
   *  Logic: '<S393>/Logical Operator'
   *  Logic: '<S393>/Logical Operator1'
   *  Logic: '<S394>/Logical Operator'
   *  Logic: '<S394>/Logical Operator1'
   */
  LampCtl_DomeLampCloseDoor = (rtb_RelationalOperator1_dx &&
    (AppSwcBcm_ARID_DEF.RelationalOperator8_i &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_n2)) &&
    (AppSwcBcm_ARID_DEF.RelationalOperator9_m &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_bf)));

  /* Truth Table: '<S325>/Truth Table' */
  /*  Open Door Dome Lamp Turn ON */
  /*  Power Off Or Unlock Door Dome Lamp Turn ON */
  /*  Lock Door or Power On and Close Door Turn Off Dome Lamp */
  /*  Condition #4 */
  /*  Condition #5 */
  /*  Condition #6 */
  rtb_RelationalOperator1_dx = !LampCtl_DomeLampLockDoor;
  rtb_RelationalOperator5_mt = !LampCtl_DomeLampCloseDoor;
  if (LampCtl_DomeLampFLOpen && rtb_RelationalOperator1_dx &&
      rtb_RelationalOperator5_mt) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S325>/Lib_SR' */
    /* Switch: '<S377>/Switch' incorporates:
     *  Logic: '<S377>/Logical Operator'
     *  UnitDelay: '<S377>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S325>/Lib_SR' */
  } else if (LampCtl_DomeLampFROpen && rtb_RelationalOperator1_dx &&
             rtb_RelationalOperator5_mt) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S325>/Lib_SR' */
    /* Switch: '<S377>/Switch' incorporates:
     *  Logic: '<S377>/Logical Operator'
     *  UnitDelay: '<S377>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S325>/Lib_SR' */
  } else if (LampCtl_DomeLampPwrOff && rtb_RelationalOperator1_dx &&
             rtb_RelationalOperator5_mt) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S325>/Lib_SR' */
    /* Switch: '<S377>/Switch' incorporates:
     *  Logic: '<S377>/Logical Operator'
     *  UnitDelay: '<S377>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S325>/Lib_SR' */
  } else if (LampCtl_DomeLampUnlock && rtb_RelationalOperator1_dx &&
             rtb_RelationalOperator5_mt) {
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = true;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S325>/Lib_SR' */
    /* Switch: '<S377>/Switch' incorporates:
     *  Logic: '<S377>/Logical Operator'
     *  UnitDelay: '<S377>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S325>/Lib_SR' */
  } else {
    if (LampCtl_DomeLampLockDoor) {
      /*  Example action 2 called from D3 column in condition table */
      LampCtl_DomeLampOff = true;
      LampCtl_DomeLampOn = false;
      LampCtl_DomeLampOnGrad = false;
      LampCtl_DomeLampOffGrad = true;
    } else if (LampCtl_DomeLampCloseDoor) {
      /*  Example action 2 called from D3 column in condition table */
      LampCtl_DomeLampOff = true;
      LampCtl_DomeLampOn = false;
      LampCtl_DomeLampOnGrad = false;
      LampCtl_DomeLampOffGrad = true;
    } else {
      /*  Default */
      /*  Example action 2 called from D3 column in condition table */
      LampCtl_DomeLampOff = true;
      LampCtl_DomeLampOn = false;
      LampCtl_DomeLampOnGrad = false;
      LampCtl_DomeLampOffGrad = true;
    }

    /* Outputs for Atomic SubSystem: '<S325>/Lib_SR' */
    /* Switch: '<S377>/Switch' incorporates:
     *  Constant: '<S377>/Constant'
     */
    LampCtl_DomeLampCtl = false;

    /* End of Outputs for SubSystem: '<S325>/Lib_SR' */
  }

  /* End of Truth Table: '<S325>/Truth Table' */

  /* Switch: '<S375>/Switch' */
  if (LampCtl_DomeLampCtl) {
    /* Switch: '<S375>/Switch' incorporates:
     *  Constant: '<S375>/Constant'
     */
    Switch = 100;
  } else {
    /* Switch: '<S375>/Switch' incorporates:
     *  Constant: '<S375>/Constant1'
     */
    Switch = 0;
  }

  /* End of Switch: '<S375>/Switch' */

  /* Outputs for Atomic SubSystem: '<S375>/Lib_RateLimit' */
  /* Delay: '<S391>/Variable Integer Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_p) {
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)Switch;
  }

  /* Sum: '<S391>/Add' incorporates:
   *  Delay: '<S391>/Variable Integer Delay'
   */
  rtb_Add = (float32)Switch - AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;

  /* Switch: '<S391>/Switch' incorporates:
   *  RelationalOperator: '<S391>/Relational Operator'
   *  RelationalOperator: '<S391>/Relational Operator1'
   *  Switch: '<S391>/Switch1'
   */
  if (rtb_Add > AppSwcBcm_ConstB.Product) {
    /* Switch: '<S391>/Switch' incorporates:
     *  Delay: '<S391>/Variable Integer Delay'
     *  Sum: '<S391>/Add1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += AppSwcBcm_ConstB.Product;
  } else if (rtb_Add < AppSwcBcm_ConstB.Product1) {
    /* Switch: '<S391>/Switch1' incorporates:
     *  Delay: '<S391>/Variable Integer Delay'
     *  Sum: '<S391>/Add2'
     *  Switch: '<S391>/Switch'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += AppSwcBcm_ConstB.Product1;
  } else {
    /* Switch: '<S391>/Switch' incorporates:
     *  Switch: '<S391>/Switch1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)Switch;
  }

  /* End of Switch: '<S391>/Switch' */

  /* Update for Delay: '<S391>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_p = false;

  /* End of Outputs for SubSystem: '<S375>/Lib_RateLimit' */

  /* Switch: '<S375>/Switch1' incorporates:
   *  Switch: '<S375>/Switch2'
   */
  if (LampCtl_DomeLampOffGrad) {
    /* DataTypeConversion: '<S375>/Data Type Conversion' */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
  } else if (LampCtl_DomeLampOnGrad) {
    /* Switch: '<S375>/Switch2' incorporates:
     *  DataTypeConversion: '<S375>/Data Type Conversion'
     */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
  } else {
    /* DataTypeConversion: '<S375>/Data Type Conversion' incorporates:
     *  Switch: '<S375>/Switch1'
     *  Switch: '<S375>/Switch2'
     */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)(float32)Switch;
  }

  /* End of Switch: '<S375>/Switch1' */
}

/* Update for atomic system: '<S241>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S374>/Lib_FailEdgeDetHold1' */
  /* Update for UnitDelay: '<S388>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gk =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* End of Update for SubSystem: '<S374>/Lib_FailEdgeDetHold1' */

  /* Update for Delay: '<S392>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kv = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_mm = AppSwcBcm_ARID_DEF.RelationalOperator4_l;

  /* Update for Delay: '<S393>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_h = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_n2 = AppSwcBcm_ARID_DEF.RelationalOperator8_i;

  /* Update for Delay: '<S394>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_no = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_bf = AppSwcBcm_ARID_DEF.RelationalOperator9_m;
}

/* Output and update for atomic system: '<S241>/FogLampRCtl' */
static void AppSwcBcm_FogLampRCtl(void)
{
  boolean guard1 = false;

  /* Chart: '<S326>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c83_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c83_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_Off_a;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_l = false;
  } else if (AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib == AppSwcBcm_IN_Off_a) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        LampCtl_PosLampSta && (BSW_FogLampFCfg == 1)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_bf = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S396>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_bf,
        &AppSwcBcm_ARID_DEF.LogicalOperator_pr,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l5);

      /* End of Outputs for SubSystem: '<S396>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_pr) {
        AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_On_j;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_l = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) || (
         !LampCtl_PosLampSta) || (BSW_FogLampFCfg == 0)) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_bf = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S396>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_bf,
        &AppSwcBcm_ARID_DEF.LogicalOperator_pr,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l5);

      /* End of Outputs for SubSystem: '<S396>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_pr) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_Off_a;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_l = false;
    }
  }

  /* End of Chart: '<S326>/Chart1' */

  /* Chart: '<S326>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_Off_a;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_f = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib == AppSwcBcm_IN_Off_a) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        LampCtl_PosLampSta && ((LampCtl_LowBeamSta && (BSW_FogLampFCfg != 1)) ||
         ((BSW_FogLampFCfg == 1) && (LampCtl_LowBeamSta ||
           AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_l)))) {
      AppSwcBcm_ARID_DEF.Lib_blIn_jhf = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S395>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_jhf,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mlz,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h2);

      /* End of Outputs for SubSystem: '<S395>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_mlz) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_On_j;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_f = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) || (
         !LampCtl_PosLampSta)) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_jhf = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S395>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_jhf,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mlz,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h2);

      /* End of Outputs for SubSystem: '<S395>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_mlz) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_Off_a;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_f = false;
    }
  }

  /* End of Chart: '<S326>/Chart' */
}

/* Output and update for atomic system: '<S241>/HiBeamCtl' */
static void AppSwcBcm_HiBeamCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S327>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S327>/Logical Operator' incorporates:
   *  Logic: '<S327>/Logical Operator1'
   *  RelationalOperator: '<S327>/Relational Operator1'
   *  RelationalOperator: '<S327>/Relational Operator2'
   *  RelationalOperator: '<S327>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_eq2 = (LampCtl_LowBeamSta &&
    rtb_RelationalOperator && (LampCtl_HiBeamSw || LampCtl_PassLightSta));

  /* CCaller: '<S327>/C Caller1' */
  BSW_HiBeamDigSts = GetHw_HiBeamDigSts();

  /* Chart: '<S327>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S327>/Constant28'
   *  Constant: '<S327>/Constant29'
   *  Constant: '<S327>/Constant30'
   *  RelationalOperator: '<S327>/Relational Operator4'
   */
  if (BSW_HiBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ml >= (float32)
         LampCtl_HiBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HiBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ml++;
      AppSwcBcm_ARID_DEF.cnt_heal_i = (uint16)((float32)
        LampCtl_HiBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ml = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_i == 0) {
      LampCtl_HiBeamShortToBat = false;
    } else if (LampCtl_HiBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_i--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S241>/KnobBeamDig' */
static void AppSwcBcm_KnobBeamDig(void)
{
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_fo;
  boolean rtb_RelationalOperator2_ba;

  /* RelationalOperator: '<S328>/Relational Operator' incorporates:
   *  Constant: '<S328>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S328>/Relational Operator1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator1_fo =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSPstnLghtSwStVld_flg;

  /* RelationalOperator: '<S328>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator2_ba =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLoBeamSwStVld_flg;

  /* Chart: '<S328>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S328>/Constant21'
   *  Constant: '<S328>/Constant3'
   *  Constant: '<S328>/Constant4'
   *  Logic: '<S328>/Logical Operator'
   *  Logic: '<S328>/Logical Operator1'
   */
  if ((rtb_RelationalOperator1_fo || rtb_RelationalOperator2_ba) &&
      rtb_RelationalOperator) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_a5 >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_KnobBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_a5++;
      AppSwcBcm_ARID_DEF.cnt_heal_gg = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_a5 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gg == 0) {
      LampCtl_KnobBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_gg--;
    }
  }

  /* End of Chart: '<S328>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S241>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_i;

  /* SystemInitialize for Chart: '<S329>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_i);
}

/* Outputs for atomic system: '<S241>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_i;
  boolean rtb_RelationalOperator1_c;

  /* Chart: '<S329>/LIB_Tim' incorporates:
   *  Constant: '<S329>/Constant6'
   *  UnitDelay: '<S329>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m5,
    LampCtl_LampDelayTim_C, &rtb_LIB_blOut_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_h);

  /* RelationalOperator: '<S329>/Relational Operator1' incorporates:
   *  Constant: '<S329>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Outputs for Atomic SubSystem: '<S329>/Lib_SR' */
  /* Switch: '<S405>/Switch' incorporates:
   *  Constant: '<S329>/Constant'
   *  Logic: '<S329>/Logical Operator1'
   *  RelationalOperator: '<S329>/Relational Operator'
   *  RelationalOperator: '<S329>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) ||
      rtb_RelationalOperator1_c || (!LampCtl_AutoLampSw) || rtb_LIB_blOut_i) {
    /* Switch: '<S405>/Switch' incorporates:
     *  Constant: '<S405>/Constant'
     */
    LampCtl_LampDelay = false;
  } else {
    /* RelationalOperator: '<S404>/Relational Operator1' incorporates:
     *  Constant: '<S329>/Constant5'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator1_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 0);

    /* Switch: '<S405>/Switch' incorporates:
     *  Constant: '<S329>/Constant3'
     *  Constant: '<S329>/Constant4'
     *  Logic: '<S329>/Logical Operator'
     *  Logic: '<S404>/Logical Operator'
     *  Logic: '<S405>/Logical Operator'
     *  RelationalOperator: '<S329>/Relational Operator3'
     *  RelationalOperator: '<S404>/Relational Operator'
     *  UnitDelay: '<S404>/Unit Delay'
     *  UnitDelay: '<S405>/Unit Delay'
     */
    LampCtl_LampDelay = (((LampCtl_LightIntstSta == 2) &&
                          (rtb_RelationalOperator1_c &&
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f0 == 2))) || LampCtl_LampDelay);
  }

  /* End of Switch: '<S405>/Switch' */
  /* End of Outputs for SubSystem: '<S329>/Lib_SR' */
}

/* Update for atomic system: '<S241>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Update(void)
{
  /* Update for UnitDelay: '<S329>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m5 = LampCtl_LampDelay;

  /* Update for UnitDelay: '<S404>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f0 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
}

/* Output and update for atomic system: '<S241>/LightIntstDet' */
static void AppSwcBcm_LightIntstDet(void)
{
  /* Chart: '<S330>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c51_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c51_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c51_LampCtl_Lib = AppSwcBcm_IN_Day;
  } else if (AppSwcBcm_ARID_DEF.is_c51_LampCtl_Lib == AppSwcBcm_IN_Day) {
    if (LampCtl_LightIntstVal >= LampCtl_NightVal_C) {
      AppSwcBcm_ARID_DEF.is_c51_LampCtl_Lib = AppSwcBcm_IN_Night;
    } else {
      LampCtl_LightIntstSta = 1U;
    }

    /* case IN_Night: */
  } else if (LampCtl_LightIntstVal <= LampCtl_DayTimeVal_C) {
    AppSwcBcm_ARID_DEF.is_c51_LampCtl_Lib = AppSwcBcm_IN_Day;
  } else {
    LampCtl_LightIntstSta = 2U;
  }

  /* End of Chart: '<S330>/Chart' */
}

/* System initialize for atomic system: '<S241>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S331>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_c5);
}

/* Output and update for atomic system: '<S241>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S331>/Relational Operator' incorporates:
   *  Constant: '<S331>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Chart: '<S331>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S331>/Constant13'
   *  Constant: '<S331>/Constant4'
   *  Constant: '<S331>/Constant5'
   *  Logic: '<S331>/Logical Operator'
   *  Logic: '<S331>/Logical Operator1'
   *  Logic: '<S331>/Logical Operator2'
   *  RelationalOperator: '<S331>/Relational Operator1'
   *  RelationalOperator: '<S331>/Relational Operator2'
   *  RelationalOperator: '<S331>/Relational Operator3'
   *  UnitDelay: '<S241>/Unit Delay'
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms1((rtb_RelationalOperator && (LampCtl_LowBeamSw ||
    LampCtl_PassLightSta || LampCtl_AutoLampSta || LampCtl_KnobBeamFaultSta)) ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pz ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e || LampCtl_LampDelay,
    LampCtl_LowBeamStaTimValid_C, LampCtl_LowBeamStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_c5,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_o);

  /* CCaller: '<S331>/C Caller' */
  BSW_LowBeamDigSts = GetHw_LoBeamDigSts();

  /* Chart: '<S331>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S331>/Constant28'
   *  Constant: '<S331>/Constant29'
   *  Constant: '<S331>/Constant30'
   *  RelationalOperator: '<S331>/Relational Operator4'
   */
  if (BSW_LowBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_i >= (float32)
         LampCtl_LowBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_LowBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_i++;
      AppSwcBcm_ARID_DEF.cnt_heal_g1 = (uint16)((float32)
        LampCtl_LowBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_i = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g1 == 0) {
      LampCtl_LowBeamShortToBat = false;
    } else if (LampCtl_LowBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_g1--;
    }
  }

  /* End of Chart: '<S331>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S241>/BrakeLampCtl' */
static void AppSwcBcm_BrakeLampCtl(void)
{
  boolean rtb_RelationalOperator2_cm;
  boolean rtb_RelationalOperator8_e;

  /* RelationalOperator: '<S323>/Relational Operator8' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S323>/Relational Operator3'
   */
  rtb_RelationalOperator8_e =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLA_flg;

  /* RelationalOperator: '<S323>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S323>/Relational Operator6'
   */
  rtb_RelationalOperator2_cm =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLAVld_flg;

  /* Logic: '<S323>/Logical Operator4' */
  rtb_RelationalOperator8_e = (rtb_RelationalOperator8_e &&
    rtb_RelationalOperator2_cm);

  /* RelationalOperator: '<S323>/Relational Operator2' incorporates:
   *  Constant: '<S323>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator2_cm = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S323>/Logical Operator' incorporates:
   *  Logic: '<S323>/Logical Operator1'
   *  Logic: '<S323>/Logical Operator3'
   *  Logic: '<S323>/Logical Operator5'
   *  RelationalOperator: '<S323>/Relational Operator'
   *  RelationalOperator: '<S323>/Relational Operator1'
   *  RelationalOperator: '<S323>/Relational Operator7'
   *  RelationalOperator: '<S323>/Relational Operator8'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_ez = (LampCtl_BrakeLightSw ||
    (rtb_RelationalOperator2_cm &&
     (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VVTM_RegenReqBrkLampOn_flg ||
      rtb_RelationalOperator8_e ||
      (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCReqBrkLghtOn_flg &&
       AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCReqBrkLghtOnVld_flg))));
}

/* Output and update for atomic system: '<S241>/ReverseLampCtl' */
static void AppSwcBcm_ReverseLampCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S349>/Relational Operator' incorporates:
   *  Constant: '<S349>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S349>/Logical Operator' incorporates:
   *  Constant: '<S349>/Constant1'
   *  RelationalOperator: '<S349>/Relational Operator1'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_gx = (rtb_RelationalOperator &&
    (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VGSM_VehActGearPstn_enum == 3));
}

/* Output and update for atomic system: '<S241>/PassLampFunc' */
static void AppSwcBcm_PassLampFunc(void)
{
  /* Chart: '<S347>/LIB_Tim' incorporates:
   *  Constant: '<S347>/Constant1'
   *  RelationalOperator: '<S347>/Relational Operator'
   */
  if (LampCtl_PassLightSw) {
    if (AppSwcBcm_ARID_DEF.Cnt_p <= 1000) {
      AppSwcBcm_ARID_DEF.Cnt_p++;
      LampCtl_PassLightSta = true;
    } else {
      LampCtl_PassLightSta = false;
    }
  } else {
    LampCtl_PassLightSta = false;
    AppSwcBcm_ARID_DEF.Cnt_p = 0U;
  }

  /* End of Chart: '<S347>/LIB_Tim' */
}

/* System initialize for atomic system: '<S241>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S348>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_cs);
}

/* Output and update for atomic system: '<S241>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S348>/Relational Operator' incorporates:
   *  Constant: '<S348>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Chart: '<S348>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S348>/Constant13'
   *  Constant: '<S348>/Constant2'
   *  Constant: '<S348>/Constant4'
   *  Logic: '<S348>/Logical Operator'
   *  Logic: '<S348>/Logical Operator1'
   *  Logic: '<S348>/Logical Operator2'
   *  RelationalOperator: '<S348>/Relational Operator1'
   *  RelationalOperator: '<S348>/Relational Operator3'
   *  UnitDelay: '<S241>/Unit Delay'
   *  UnitDelay: '<S241>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms1((rtb_RelationalOperator && (LampCtl_PosLampSw ||
    LampCtl_LowBeamSw || LampCtl_AutoLampSta)) ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pz ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e || LampCtl_KnobBeamFaultSta ||
    LampCtl_LampDelay, LampCtl_PosLampStaTimValid_C,
    LampCtl_PosLampStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_cs,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift10'
 *    '<S677>/Bit Shift9'
 */
static uint16 AppSwcBcm_BitShift10_b(uint16 rtu_u)
{
  /* MATLAB Function: '<S413>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 8);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift11'
 *    '<S677>/Bit Shift12'
 */
static uint16 AppSwcBcm_BitShift11_p(uint16 rtu_u)
{
  /* MATLAB Function: '<S414>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 11);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift2'
 *    '<S677>/Bit Shift4'
 */
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u)
{
  /* MATLAB Function: '<S415>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift3'
 *    '<S677>/Bit Shift8'
 */
static uint16 AppSwcBcm_BitShift3_d(uint16 rtu_u)
{
  /* MATLAB Function: '<S416>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift4'
 *    '<S587>/Bit Shift1'
 *    '<S677>/Bit Shift1'
 */
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u)
{
  /* MATLAB Function: '<S417>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift7'
 *    '<S587>/Bit Shift2'
 *    '<S677>/Bit Shift2'
 */
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u)
{
  /* MATLAB Function: '<S420>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 2);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift8'
 *    '<S677>/Bit Shift6'
 */
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u)
{
  /* MATLAB Function: '<S421>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S350>/Bit Shift9'
 *    '<S677>/Bit Shift7'
 */
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u)
{
  /* MATLAB Function: '<S422>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 6);
}

/* System initialize for atomic system: '<S241>/SignalProcess' */
static void AppSwcBcm_SignalProcess_Init(void)
{
  /* SystemInitialize for Chart: '<S350>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_fa);

  /* SystemInitialize for Chart: '<S350>/LIB_TPD_10ms13' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);
}

/* Output and update for atomic system: '<S241>/SignalProcess' */
static void AppSwcBcm_SignalProcess(void)
{
  uint16 rtb_y;
  uint16 rtb_y_c;
  boolean rtb_LogicalOperator2_f;
  boolean rtb_Switch;
  boolean rtb_Switch9_g;

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift' */
  /* Constant: '<S350>/Constant48' */
  rtb_y = AppSwcBcm_BitShift3(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift' */

  /* Switch: '<S350>/Switch' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S350>/Switch' incorporates:
     *  Constant: '<S350>/Constant50'
     */
    rtb_Switch = LampCtl_PosLampVal_C;
  } else {
    /* Switch: '<S350>/Switch' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S350>/Logical Operator6'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSPstnLghtSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSPstnLghtSwStVld_flg);
  }

  /* End of Switch: '<S350>/Switch' */

  /* Chart: '<S350>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S350>/Constant19'
   *  Constant: '<S350>/Constant20'
   *  Constant: '<S350>/Constant21'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ob >= (float32)LampCtl_PosLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_PosLampTimValid_C != 0xFFFF)) {
      LampCtl_PosLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ob++;
      AppSwcBcm_ARID_DEF.cnt_heal_cx = (uint16)((float32)
        LampCtl_PosLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ob = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cx == 0) {
      LampCtl_PosLampSw = false;
    } else if (LampCtl_PosLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cx--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift4' */
  /* Constant: '<S350>/Constant1' */
  rtb_y_c = AppSwcBcm_BitShift4(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift4' */

  /* Switch: '<S350>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND4'
   */
  if ((rtb_y_c & 1U) != 0U) {
    /* Switch: '<S350>/Switch4' incorporates:
     *  Constant: '<S350>/Constant10'
     */
    rtb_Switch = LampCtl_LowBeamVal_C;
  } else {
    /* Switch: '<S350>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S350>/Logical Operator7'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLoBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLoBeamSwStVld_flg);
  }

  /* End of Switch: '<S350>/Switch4' */

  /* Chart: '<S350>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S350>/Constant22'
   *  Constant: '<S350>/Constant23'
   *  Constant: '<S350>/Constant24'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_k2 >= (float32)LampCtl_LowBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_LowBeamTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k2++;
      AppSwcBcm_ARID_DEF.cnt_heal_de = (uint16)((float32)
        LampCtl_LowBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_de == 0) {
      LampCtl_LowBeamSw = false;
    } else if (LampCtl_LowBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_de--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift7' */
  /* Constant: '<S350>/Constant12' */
  rtb_y_c = AppSwcBcm_BitShift7(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift7' */

  /* Switch: '<S350>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND7'
   */
  if ((rtb_y_c & 1U) != 0U) {
    /* Switch: '<S350>/Switch7' incorporates:
     *  Constant: '<S350>/Constant11'
     */
    rtb_Switch = LampCtl_HiBeamVal_C;
  } else {
    /* Switch: '<S350>/Switch7' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S350>/Logical Operator8'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSHiBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSHiBeamSwStVld_flg);
  }

  /* End of Switch: '<S350>/Switch7' */

  /* Chart: '<S350>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S350>/Constant25'
   *  Constant: '<S350>/Constant26'
   *  Constant: '<S350>/Constant27'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l4 >= (float32)LampCtl_HiBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_HiBeamTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l4++;
      AppSwcBcm_ARID_DEF.cnt_heal_hk = (uint16)((float32)
        LampCtl_HiBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l4 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hk == 0) {
      LampCtl_HiBeamSw = false;
    } else if (LampCtl_HiBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hk--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift1' */
  /* Constant: '<S350>/Constant3' */
  rtb_y = AppSwcBcm_BitShift1_k(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift1' */

  /* Switch: '<S350>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S350>/Switch1' incorporates:
     *  Constant: '<S350>/Constant2'
     */
    rtb_Switch = LampCtl_PassLightVal_C;
  } else {
    /* Switch: '<S350>/Switch1' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S350>/Logical Operator1'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSOvrVehBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSOvrVehBeamSwStVld_flg);
  }

  /* End of Switch: '<S350>/Switch1' */

  /* Chart: '<S350>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S350>/Constant28'
   *  Constant: '<S350>/Constant29'
   *  Constant: '<S350>/Constant30'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_nw >= (float32)
         LampCtl_PassLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_PassLightTimValid_C != 0xFFFF)) {
      LampCtl_PassLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_nw++;
      AppSwcBcm_ARID_DEF.cnt_heal_g0 = (uint16)((float32)
        LampCtl_PassLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_nw = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g0 == 0) {
      LampCtl_PassLightSw = false;
    } else if (LampCtl_PassLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_g0--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift2' */
  /* Constant: '<S350>/Constant53' */
  rtb_y = AppSwcBcm_BitShift2(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift8' */
  /* Constant: '<S350>/Constant4' */
  rtb_y_c = AppSwcBcm_BitShift8(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift8' */

  /* Logic: '<S350>/Logical Operator3' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_Switch =
    ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwSt_flg &&
     (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwStVld_flg);

  /* Logic: '<S350>/Logical Operator2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_LogicalOperator2_f =
    ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwSt_flg &&
     (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwStVld_flg);

  /* Switch: '<S350>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND8'
   */
  if ((rtb_y_c & 1U) != 0U) {
    /* Switch: '<S350>/Switch9' incorporates:
     *  Constant: '<S350>/Constant5'
     */
    rtb_Switch9_g = LampCtl_TurnIndcrRVal_C;
  } else {
    /* Switch: '<S350>/Switch9' incorporates:
     *  Logic: '<S350>/Logical Operator'
     *  Logic: '<S350>/Logical Operator10'
     */
    rtb_Switch9_g = (rtb_Switch && (!rtb_LogicalOperator2_f));
  }

  /* End of Switch: '<S350>/Switch9' */

  /* Chart: '<S350>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S350>/Constant37'
   *  Constant: '<S350>/Constant38'
   *  Constant: '<S350>/Constant39'
   */
  if (rtb_Switch9_g) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_jy >= (float32)
         LampCtl_TurnIndcrRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_jy++;
      AppSwcBcm_ARID_DEF.cnt_heal_d1 = (uint16)((float32)
        LampCtl_TurnIndcrRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S350>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S350>/Constant37'
     *  Constant: '<S350>/Constant38'
     *  Constant: '<S350>/Constant39'
     *  Constant: '<S350>/Constant40'
     *  Constant: '<S350>/Constant41'
     *  Constant: '<S350>/Constant42'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_dv >= (float32)
         LampCtl_TurnIndcrLaneRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_dv++;
      AppSwcBcm_ARID_DEF.cnt_heal_e2 = (uint16)((float32)
        LampCtl_TurnIndcrLaneRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_jy = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d1 == 0) {
      LampCtl_TurnIndcrRSw = false;
    } else if (LampCtl_TurnIndcrRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_d1--;
    }

    /* Chart: '<S350>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S350>/Constant38'
     *  Constant: '<S350>/Constant41'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_dv = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e2 == 0) {
      LampCtl_TurnIndcrLaneRSw = false;
    } else if (LampCtl_TurnIndcrLaneRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_e2--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms6' */

  /* Switch: '<S350>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S350>/Switch2' incorporates:
     *  Constant: '<S350>/Constant54'
     */
    rtb_LogicalOperator2_f = LampCtl_TurnIndcrLVal_C;
  } else {
    /* Switch: '<S350>/Switch2' incorporates:
     *  Logic: '<S350>/Logical Operator12'
     *  Logic: '<S350>/Logical Operator5'
     *  UnitDelay: '<S350>/Unit Delay1'
     */
    rtb_LogicalOperator2_f = (rtb_LogicalOperator2_f &&
      (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k));
  }

  /* End of Switch: '<S350>/Switch2' */

  /* Chart: '<S350>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S350>/Constant31'
   *  Constant: '<S350>/Constant32'
   *  Constant: '<S350>/Constant33'
   */
  if (rtb_LogicalOperator2_f) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fe >= (float32)
         LampCtl_TurnIndcrLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fe++;
      AppSwcBcm_ARID_DEF.cnt_heal_ej = (uint16)((float32)
        LampCtl_TurnIndcrLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S350>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S350>/Constant31'
     *  Constant: '<S350>/Constant32'
     *  Constant: '<S350>/Constant33'
     *  Constant: '<S350>/Constant34'
     *  Constant: '<S350>/Constant35'
     *  Constant: '<S350>/Constant36'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_aj >= (float32)
         LampCtl_TurnIndcrLaneLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_aj++;
      AppSwcBcm_ARID_DEF.cnt_heal_n = (uint16)((float32)
        LampCtl_TurnIndcrLaneLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fe = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ej == 0) {
      LampCtl_TurnIndcrLSw = false;
    } else if (LampCtl_TurnIndcrLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ej--;
    }

    /* Chart: '<S350>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S350>/Constant32'
     *  Constant: '<S350>/Constant35'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_aj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n == 0) {
      LampCtl_TurnIndcrLaneLSw = false;
    } else if (LampCtl_TurnIndcrLaneLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift3' */
  /* Constant: '<S350>/Constant55' */
  rtb_y_c = AppSwcBcm_BitShift3_d(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift3' */

  /* Switch: '<S350>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND3'
   */
  if ((rtb_y_c & 1U) != 0U) {
    /* Switch: '<S350>/Switch3' incorporates:
     *  Constant: '<S350>/Constant56'
     */
    rtb_LogicalOperator2_f = LampCtl_FogLampRVal_C;
  } else {
    /* Switch: '<S350>/Switch3' incorporates:
     *  DataTypeConversion: '<S350>/Data Type Conversion3'
     *  Logic: '<S350>/Logical Operator9'
     */
    rtb_LogicalOperator2_f = (BSW_J346FogLampR == 0);
  }

  /* End of Switch: '<S350>/Switch3' */

  /* Chart: '<S350>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S350>/Constant43'
   *  Constant: '<S350>/Constant44'
   *  Constant: '<S350>/Constant45'
   */
  if (rtb_LogicalOperator2_f) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c2 >= (float32)LampCtl_FogLampRTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampRTimValid_C != 0xFFFF)) {
      LampCtl_FogLampRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c2++;
      AppSwcBcm_ARID_DEF.cnt_heal_dfd = (uint16)((float32)
        LampCtl_FogLampRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_dfd == 0) {
      LampCtl_FogLampRSw = false;
    } else if (LampCtl_FogLampRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_dfd--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms9' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift5' */
  /* S-Function (sfix_bitop): '<S350>/Bitwise AND5' incorporates:
   *  Constant: '<S350>/Constant59'
   *  MATLAB Function: '<S418>/bit_shift'
   */
  rtb_y_c = (uint16)((sint32)((uint32)LampCtl_InportCalSwBit_C >> 9) & 1);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift5' */

  /* Switch: '<S350>/Switch5' */
  if (rtb_y_c != 0) {
    /* Switch: '<S350>/Switch5' incorporates:
     *  Constant: '<S350>/Constant60'
     */
    rtb_LogicalOperator2_f = LampCtl_HazardLightVal_C;
  } else {
    /* Switch: '<S350>/Switch5' */
    rtb_LogicalOperator2_f =
      AppSwcBcm_ARID_DEF.IPM_CCP_PanelStatus_BOD_d.VIPM_CCPHzrdKey_flg;
  }

  /* End of Switch: '<S350>/Switch5' */

  /* Chart: '<S350>/LIB_TPD_10ms10' incorporates:
   *  Constant: '<S350>/Constant46'
   *  Constant: '<S350>/Constant47'
   *  Constant: '<S350>/Constant49'
   */
  if (rtb_LogicalOperator2_f) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_bv >= (float32)
         LampCtl_HazardLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HazardLightTimValid_C != 0xFFFF)) {
      LampCtl_HazardLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_bv++;
      AppSwcBcm_ARID_DEF.cnt_heal_be = (uint16)((float32)
        LampCtl_HazardLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_bv = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_be == 0) {
      LampCtl_HazardLightSw = false;
    } else if (LampCtl_HazardLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_be--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms10' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift11' */
  /* Constant: '<S350>/Constant73' */
  rtb_y = AppSwcBcm_BitShift11_p(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift6' */
  /* Switch: '<S350>/Switch6' incorporates:
   *  Constant: '<S350>/Constant61'
   *  Constant: '<S350>/Constant62'
   *  DataTypeConversion: '<S350>/Data Type Conversion6'
   *  MATLAB Function: '<S419>/bit_shift'
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND6'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 10 & 1U) != 0U) {
    rtb_LogicalOperator2_f = LampCtl_BrakeLightVal_C;
  } else {
    rtb_LogicalOperator2_f = (BSW_J313BrakeLoSw != 0);
  }

  /* End of Outputs for SubSystem: '<S350>/Bit Shift6' */

  /* Chart: '<S350>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S350>/Constant14'
   *  Constant: '<S350>/Constant15'
   *  Constant: '<S350>/Constant16'
   *  Switch: '<S350>/Switch6'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_LogicalOperator2_f, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_fa,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11_e);

  /* Switch: '<S350>/Switch12' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND11'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S350>/Switch12' incorporates:
     *  Constant: '<S350>/Constant74'
     */
    rtb_LogicalOperator2_f = LampCtl_BrakeLightVal_C;
  } else {
    /* Switch: '<S350>/Switch12' incorporates:
     *  DataTypeConversion: '<S350>/Data Type Conversion13'
     *  Logic: '<S350>/Logical Operator14'
     */
    rtb_LogicalOperator2_f = (BSW_J339BrakeHiSw == 0);
  }

  /* End of Switch: '<S350>/Switch12' */

  /* Chart: '<S350>/LIB_TPD_10ms13' incorporates:
   *  Constant: '<S350>/Constant70'
   *  Constant: '<S350>/Constant71'
   *  Constant: '<S350>/Constant72'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_LogicalOperator2_f, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms13);

  /* Logic: '<S350>/Logical Operator13' */
  LampCtl_BrakeLightSw = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_fa ||
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift9' */
  /* Constant: '<S350>/Constant6' */
  rtb_y_c = AppSwcBcm_BitShift9(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift9' */

  /* Switch: '<S350>/Switch10' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND9'
   */
  if ((rtb_y_c & 1U) != 0U) {
    /* Switch: '<S350>/Switch10' incorporates:
     *  Constant: '<S350>/Constant8'
     */
    rtb_LogicalOperator2_f = LampCtl_AutoLampVal_C;
  } else {
    /* Switch: '<S350>/Switch10' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S350>/Logical Operator4'
     */
    rtb_LogicalOperator2_f =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLampAutoSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLampAutoStVld_flg);
  }

  /* End of Switch: '<S350>/Switch10' */

  /* Chart: '<S350>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S350>/Constant13'
   *  Constant: '<S350>/Constant63'
   *  Constant: '<S350>/Constant9'
   */
  if (rtb_LogicalOperator2_f) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b >= (float32)LampCtl_AutoLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_AutoLampTimValid_C != 0xFFFF)) {
      LampCtl_AutoLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b++;
      AppSwcBcm_ARID_DEF.cnt_heal_gc = (uint16)((float32)
        LampCtl_AutoLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gc == 0) {
      LampCtl_AutoLampSw = false;
    } else if (LampCtl_AutoLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_gc--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S350>/Bit Shift10' */
  /* Constant: '<S350>/Constant68' */
  rtb_y = AppSwcBcm_BitShift10_b(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S350>/Bit Shift10' */

  /* Switch: '<S350>/Switch11' incorporates:
   *  S-Function (sfix_bitop): '<S350>/Bitwise AND10'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S350>/Switch11' incorporates:
     *  Constant: '<S350>/Constant69'
     */
    rtb_LogicalOperator2_f = LampCtl_FogLampFVal_C;
  } else {
    /* Switch: '<S350>/Switch11' incorporates:
     *  DataTypeConversion: '<S350>/Data Type Conversion9'
     *  Logic: '<S350>/Logical Operator11'
     */
    rtb_LogicalOperator2_f = (BSW_J322FogLampF == 0);
  }

  /* End of Switch: '<S350>/Switch11' */

  /* Chart: '<S350>/LIB_TPD_10ms12' incorporates:
   *  Constant: '<S350>/Constant64'
   *  Constant: '<S350>/Constant66'
   *  Constant: '<S350>/Constant67'
   */
  if (rtb_LogicalOperator2_f) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_bf >= (float32)LampCtl_FogLampFTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampFTimValid_C != 0xFFFF)) {
      LampCtl_FogLampFSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_bf++;
      AppSwcBcm_ARID_DEF.cnt_heal_k4 = (uint16)((float32)
        LampCtl_FogLampFTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_bf = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k4 == 0) {
      LampCtl_FogLampFSw = false;
    } else if (LampCtl_FogLampFTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k4--;
    }
  }

  /* End of Chart: '<S350>/LIB_TPD_10ms12' */

  /* MultiPortSwitch: '<S350>/Multiport Switch' */
  switch (BSW_RKEReq) {
   case 0:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant'
     */
    LampCtl_RKEReq = 0U;
    break;

   case 17:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant17'
     */
    LampCtl_RKEReq = 1U;
    break;

   case 18:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant18'
     */
    LampCtl_RKEReq = 2U;
    break;

   case 19:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant51'
     */
    LampCtl_RKEReq = 3U;
    break;

   case 34:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant52'
     */
    LampCtl_RKEReq = 4U;
    break;

   case 49:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant57'
     */
    LampCtl_RKEReq = 5U;
    break;

   case 50:
    /* MultiPortSwitch: '<S350>/Multiport Switch' incorporates:
     *  Constant: '<S350>/Constant58'
     */
    LampCtl_RKEReq = 6U;
    break;
  }

  /* End of MultiPortSwitch: '<S350>/Multiport Switch' */

  /* DataTypeConversion: '<S350>/Data Type Conversion12' */
  LampCtl_LightIntstVal = BSW_J125LightIntst;

  /* Update for UnitDelay: '<S350>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k = rtb_Switch;
}

/*
 * System initialize for function-call system:
 *    '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
  (ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
   *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S477>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_e_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S477>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(boolean rtu_Lib_blIn,
  boolean *rty_Lib_blOut, ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S477>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_n(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S477>/Lib_RiseEdgeDetInit' */
}

/*
 * System initialize for function-call system:
 *    '<S502>/Lib_ChangeEdge'
 *    '<S502>/Lib_ChangeEdge1'
 *    '<S502>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge_Init(ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S506>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S502>/Lib_ChangeEdge'
 *    '<S502>/Lib_ChangeEdge1'
 *    '<S502>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge(float32 rtu_Lib_In, float32 rtu_Lib_InNow,
  float32 rtu_Lib_InBefore, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S506>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
  }

  /* Logic: '<S506>/Logical Operator' incorporates:
   *  Delay: '<S506>/Delay'
   *  RelationalOperator: '<S506>/Relational Operator'
   *  RelationalOperator: '<S506>/Relational Operator1'
   */
  *rty_Lib_blOut = ((rtu_Lib_InNow == rtu_Lib_In) &&
                    (AppSwcBcm__ARID_DEF_arg->Delay_DSTATE == rtu_Lib_InBefore));

  /* Update for Delay: '<S506>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
}

/*
 * System initialize for function-call system:
 *    '<S461>/Pri4Func.Turn'
 *    '<S461>/Pri4Func.Turn1'
 *    '<S461>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y)
{
  /* SystemInitialize for Chart: '<S518>/Turn' */
  *rty_y = false;
}

/*
 * Output and update for function-call system:
 *    '<S461>/Pri4Func.Turn'
 *    '<S461>/Pri4Func.Turn1'
 *    '<S461>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S518>/Turn' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c80_LampCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c80_LampCtl_Lib = 1U;
    *rty_y = !rtu_x;
  }

  /* End of Chart: '<S518>/Turn' */
}

/*
 * System initialize for atomic system:
 *    '<S462>/TurnIndcrDig'
 *    '<S462>/TurnIndcrDig1'
 *    '<S462>/TurnIndcrDig2'
 *    '<S462>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig_Init(boolean *rty_LIB_blErrFlg)
{
  *rty_LIB_blErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S462>/TurnIndcrDig'
 *    '<S462>/TurnIndcrDig1'
 *    '<S462>/TurnIndcrDig2'
 *    '<S462>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig(boolean rtu_LIB_blIn, boolean rtu_LIB_blIn2,
  boolean rtu_LIB_blRst, float32 rtu_LIB_s32Ts, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, uint8 rtu_LIB_u8Cnt, boolean *rty_LIB_blErrFlg,
  ARID_DEF_TurnIndcrDig_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;
  float32 tmp_0;

  /* Chart: '<S462>/TurnIndcrDig' */
  if (rtu_LIB_blIn) {
    if (rtu_LIB_blIn2 && (!AppSwcBcm__ARID_DEF_arg->Cnt_SubFlg) &&
        (!AppSwcBcm__ARID_DEF_arg->Cnt_AddFlg)) {
      if (AppSwcBcm__ARID_DEF_arg->cnt_defect >= (float32)rtu_LIB_u16tiToDef /
          (rtu_LIB_s32Ts * 100.0F)) {
        tmp = AppSwcBcm__ARID_DEF_arg->ErrCnt + 1;
        if (AppSwcBcm__ARID_DEF_arg->ErrCnt + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm__ARID_DEF_arg->ErrCnt = (uint8)tmp;
        AppSwcBcm__ARID_DEF_arg->Cnt_AddFlg = true;
      } else {
        tmp = AppSwcBcm__ARID_DEF_arg->cnt_defect + 1;
        if (AppSwcBcm__ARID_DEF_arg->cnt_defect + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm__ARID_DEF_arg->cnt_defect = (uint16)tmp;
        tmp_0 = (float32)rtu_LIB_u16tiToOk / (rtu_LIB_s32Ts * 100.0F);
        if (tmp_0 < 65536.0F) {
          if (tmp_0 >= 0.0F) {
            AppSwcBcm__ARID_DEF_arg->cnt_heal = (uint16)tmp_0;
          } else {
            AppSwcBcm__ARID_DEF_arg->cnt_heal = 0U;
          }
        } else {
          AppSwcBcm__ARID_DEF_arg->cnt_heal = MAX_uint16_T;
        }
      }

      /* cnt_defect=0; */
    } else if (AppSwcBcm__ARID_DEF_arg->cnt_heal == 0) {
      *rty_LIB_blErrFlg = false;
      AppSwcBcm__ARID_DEF_arg->ErrCnt = 0U;
      AppSwcBcm__ARID_DEF_arg->Cnt_SubFlg = true;
    } else if (!AppSwcBcm__ARID_DEF_arg->Cnt_AddFlg) {
      AppSwcBcm__ARID_DEF_arg->cnt_heal--;
    }

    *rty_LIB_blErrFlg = ((AppSwcBcm__ARID_DEF_arg->ErrCnt >= rtu_LIB_u8Cnt) || (*
      rty_LIB_blErrFlg));
  } else {
    AppSwcBcm__ARID_DEF_arg->cnt_defect = 0U;
    tmp_0 = (float32)rtu_LIB_u16tiToOk / (rtu_LIB_s32Ts * 100.0F);
    if (tmp_0 < 65536.0F) {
      if (tmp_0 >= 0.0F) {
        AppSwcBcm__ARID_DEF_arg->cnt_heal = (uint16)tmp_0;
      } else {
        AppSwcBcm__ARID_DEF_arg->cnt_heal = 0U;
      }
    } else {
      AppSwcBcm__ARID_DEF_arg->cnt_heal = MAX_uint16_T;
    }

    AppSwcBcm__ARID_DEF_arg->Cnt_AddFlg = false;
    AppSwcBcm__ARID_DEF_arg->Cnt_SubFlg = false;
  }

  *rty_LIB_blErrFlg = ((!rtu_LIB_blRst) && (*rty_LIB_blErrFlg));

  /* End of Chart: '<S462>/TurnIndcrDig' */
}

/*
 * Output and update for atomic system:
 *    '<S541>/Lib_BothEdgeDet'
 *    '<S866>/Lib_BothEdgeDet'
 *    '<S866>/Lib_BothEdgeDet1'
 *    '<S866>/Lib_BothEdgeDet2'
 *    '<S866>/Lib_BothEdgeDet3'
 */
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S542>/Logical Operator2' incorporates:
   *  Logic: '<S542>/Logical Operator1'
   *  Logic: '<S542>/Logical Operator3'
   *  Logic: '<S542>/Logical Operator4'
   *  Logic: '<S542>/Logical Operator5'
   *  UnitDelay: '<S542>/Unit Delay'
   */
  *rty_Lib_blOut = ((AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_Lib_blIn))
                    || (rtu_Lib_blIn &&
                        (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE)));

  /* Update for UnitDelay: '<S542>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S351>/HazardLightLogic' */
static boolean AppSwcBcm_EmerOff(void)
{
  boolean guard1 = false;
  boolean y;

  /* UnitDelay: '<S351>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.Lib_blIn_g5r = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_c;

  /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet1' */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_g5r,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ki,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_g);

  /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet1' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ki) {
    guard1 = true;
  } else {
    /* UnitDelay: '<S351>/Unit Delay5' */
    AppSwcBcm_ARID_DEF.Lib_blIn_n4 = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_b;

    /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet2' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_n4,
      &AppSwcBcm_ARID_DEF.LogicalOperator_at,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_c);

    /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet2' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_at) {
      guard1 = true;
    } else {
      y = false;
    }
  }

  if (guard1) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = true;
  }

  return y;
}

/* Function for Chart: '<S351>/HazardLightLogic' */
static boolean AppSwcBcm_HazardOff(void)
{
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_oa = LampCtl_HazardLightSw;

  /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_oa,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mx,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o3);

  /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_mx) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
  } else {
    y = false;
  }

  return y;
}

/* Function for Chart: '<S351>/HazardLightLogic' */
static boolean AppSwcBcm_TurnOff(void)
{
  boolean guard1 = false;
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_kr = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 1);

  /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet4' */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_kr,
    &AppSwcBcm_ARID_DEF.LogicalOperator_kt,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet4);

  /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet4' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_kt) {
    guard1 = true;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_ix = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta ==
      2);

    /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet5' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ix,
      &AppSwcBcm_ARID_DEF.LogicalOperator_mh,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet5);

    /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet5' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_mh) {
      guard1 = true;
    } else {
      y = false;
    }
  }

  if (guard1) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = true;
  }

  return y;
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_TurnFunc(void)
{
  LampCtl_TurnIndcrRst = !LampCtl_TurnIndcrRst;
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_Pri1Func(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_EnFunc(void)
{
  LampCtl_TurnIndcrPrd = 0U;
  LampCtl_TurnIndcrWdt = 0U;
  LampCtl_TurnIndcrRFlashCnt = 0U;
  LampCtl_TurnIndcrLFlashCnt = 0U;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_Pri2Func(void)
{
  LampCtl_TurnIndcrPrd = 10U;
  LampCtl_TurnIndcrWdt = 5U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_Pri4Func(void)
{
  switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide) {
   case 2:
    AppSwcBcm_ARID_DEF.x = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S461>/Pri4Func.Turn' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x, &AppSwcBcm_ARID_DEF.y_k,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn);

    /* End of Outputs for SubSystem: '<S461>/Pri4Func.Turn' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_k;
    if (LampCtl_TurnIndcrMod == 1) {
      LampCtl_TurnIndcrPrd = 40U;
      LampCtl_TurnIndcrWdt = 20U;
      LampCtl_TurnIndcrRFlashCnt = 3U;
      LampCtl_TurnIndcrLFlashCnt = 0U;
    } else {
      LampCtl_TurnIndcrPrd = 40U;
      LampCtl_TurnIndcrWdt = 20U;
      LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
      LampCtl_TurnIndcrLFlashCnt = 0U;
    }
    break;

   case 3:
    AppSwcBcm_ARID_DEF.x_g = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S461>/Pri4Func.Turn1' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_g, &AppSwcBcm_ARID_DEF.y_h,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn1);

    /* End of Outputs for SubSystem: '<S461>/Pri4Func.Turn1' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_h;
    if (LampCtl_TurnIndcrMod == 3) {
      LampCtl_TurnIndcrPrd = 40U;
      LampCtl_TurnIndcrWdt = 20U;
      LampCtl_TurnIndcrRFlashCnt = 0U;
      LampCtl_TurnIndcrLFlashCnt = 3U;
    } else {
      LampCtl_TurnIndcrPrd = 40U;
      LampCtl_TurnIndcrWdt = 20U;
      LampCtl_TurnIndcrRFlashCnt = 0U;
      LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
    }
    break;

   case 1:
    LampCtl_TurnIndcrPrd = 40U;
    LampCtl_TurnIndcrWdt = 20U;
    LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
    LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
    AppSwcBcm_ARID_DEF.x_e = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S461>/Pri4Func.Turn2' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_e, &AppSwcBcm_ARID_DEF.y,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn2);

    /* End of Outputs for SubSystem: '<S461>/Pri4Func.Turn2' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y;
    break;
  }

  if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 3) &&
      LampCtl_TurnIndcrLOpen) {
    LampCtl_TurnIndcrPrd = 20U;
    LampCtl_TurnIndcrWdt = 10U;
  } else if (((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 3) ||
              (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 1)) &&
             LampCtl_TurnIndcrLShort) {
    LampCtl_TurnIndcrPrd = 0U;
    LampCtl_TurnIndcrWdt = 0U;
  }

  if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 2) &&
      LampCtl_TurnIndcrROpen) {
    LampCtl_TurnIndcrPrd = 20U;
    LampCtl_TurnIndcrWdt = 10U;
  } else if (((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 2) ||
              (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 1)) &&
             LampCtl_TurnIndcrRShort) {
    LampCtl_TurnIndcrPrd = 0U;
    LampCtl_TurnIndcrWdt = 0U;
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_VehModeFunc(void)
{
  switch (LampCtl_VehModeSta) {
   case 1:
    LampCtl_TurnIndcrPrd = 40U;
    LampCtl_TurnIndcrWdt = 20U;
    LampCtl_TurnIndcrRFlashCnt = 1U;
    LampCtl_TurnIndcrLFlashCnt = 1U;
    break;

   case 2:
    LampCtl_TurnIndcrPrd = 40U;
    LampCtl_TurnIndcrWdt = 20U;
    LampCtl_TurnIndcrRFlashCnt = 2U;
    LampCtl_TurnIndcrLFlashCnt = 2U;
    break;

   case 3:
    LampCtl_TurnIndcrPrd = 40U;
    LampCtl_TurnIndcrWdt = 20U;
    LampCtl_TurnIndcrRFlashCnt = 3U;
    LampCtl_TurnIndcrLFlashCnt = 3U;
    break;

   default:
    LampCtl_TurnIndcrPrd = 0U;
    LampCtl_TurnIndcrWdt = 0U;
    LampCtl_TurnIndcrRFlashCnt = 0U;
    LampCtl_TurnIndcrLFlashCnt = 0U;
    break;
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_AntiLckFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_d = AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;

  /* Outputs for Function Call SubSystem: '<S461>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_d,
    &AppSwcBcm_ARID_DEF.RelationalOperator_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5AntiLckFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S461>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_l) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_ArmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 40U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
  AppSwcBcm_ARID_DEF.Lib_blIn_pi = AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;

  /* Outputs for Function Call SubSystem: '<S461>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_pi,
    &AppSwcBcm_ARID_DEF.RelationalOperator_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5ArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S461>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_i) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_DisarmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_et = AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;

  /* Outputs for Function Call SubSystem: '<S461>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_et,
    &AppSwcBcm_ARID_DEF.RelationalOperator_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5DisarmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S461>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_e) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_PartArmedFunc(void)
{
  if (LampCtl_PartArmedSta == 2) {
    LampCtl_TurnIndcrPrd = 40U;
    LampCtl_TurnIndcrWdt = 20U;
    LampCtl_TurnIndcrRFlashCnt = 3U;
    LampCtl_TurnIndcrLFlashCnt = 3U;
  } else {
    LampCtl_TurnIndcrPrd = 20U;
    LampCtl_TurnIndcrWdt = 10U;
    LampCtl_TurnIndcrRFlashCnt = 3U;
    LampCtl_TurnIndcrLFlashCnt = 3U;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_dc = AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;

  /* Outputs for Function Call SubSystem: '<S461>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_dc,
    &AppSwcBcm_ARID_DEF.RelationalOperator_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5PartArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S461>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_n) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_RodBeamFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_SeekFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = 10U;
  LampCtl_TurnIndcrLFlashCnt = 10U;
  AppSwcBcm_ARID_DEF.Lib_blIn_f5o = AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;

  /* Outputs for Function Call SubSystem: '<S461>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_f5o,
    &AppSwcBcm_ARID_DEF.RelationalOperator_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5SeekFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S461>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_o) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S351>/TurnIndcrArb2' */
static void AppSwcBcm_TrunkWarnFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
}

/* Function for Chart: '<S452>/Chart' */
static void AppSwcBcm_CrashClearFunc(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_al =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

  /* Outputs for Function Call SubSystem: '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit' */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_al,
    &AppSwcBcm_ARID_DEF.LogicalOperator_dt,
    &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit' */
  AppSwcBcm_ARID_DEF.PwrOffFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_dt ||
    AppSwcBcm_ARID_DEF.PwrOffFlg);
  if (AppSwcBcm_ARID_DEF.PwrOffFlg) {
    AppSwcBcm_ARID_DEF.Lib_blIn_n3 =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

    /* Outputs for Function Call SubSystem: '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
    AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_n3,
      &AppSwcBcm_ARID_DEF.LogicalOperator_es4,
      &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

    /* End of Outputs for SubSystem: '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
    AppSwcBcm_ARID_DEF.PwrOnFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_es4 ||
      AppSwcBcm_ARID_DEF.PwrOnFlg);
  }
}

/* System initialize for atomic system: '<S241>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S449>/Chart' incorporates:
   *  SubSystem: '<S469>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

  /* SystemInitialize for Chart: '<S451>/Chart' incorporates:
   *  SubSystem: '<S473>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_f);

  /* SystemInitialize for Chart: '<S452>/Chart' incorporates:
   *  SubSystem: '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S452>/Chart' incorporates:
   *  SubSystem: '<S476>/CrashClearFunc.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S453>/Chart' incorporates:
   *  SubSystem: '<S487>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_l);

  /* SystemInitialize for Chart: '<S456>/Chart' incorporates:
   *  SubSystem: '<S502>/Lib_ChangeEdge'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

  /* SystemInitialize for Chart: '<S456>/Chart' incorporates:
   *  SubSystem: '<S502>/Lib_ChangeEdge1'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

  /* SystemInitialize for Chart: '<S456>/Chart' incorporates:
   *  SubSystem: '<S502>/Lib_ChangeEdge2'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

  /* SystemInitialize for Chart: '<S460>/Chart' incorporates:
   *  SubSystem: '<S515>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ip);

  /* SystemInitialize for Chart: '<S351>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S461>/Pri4Func.Turn'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_k);

  /* SystemInitialize for Chart: '<S351>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S461>/Pri4Func.Turn1'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_h);

  /* SystemInitialize for Chart: '<S351>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S461>/Pri4Func.Turn2'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y);

  /* SystemInitialize for Chart: '<S462>/TurnIndcrDig' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_l);

  /* SystemInitialize for Chart: '<S462>/TurnIndcrDig1' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_j);

  /* SystemInitialize for Chart: '<S462>/TurnIndcrDig2' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_d);

  /* SystemInitialize for Chart: '<S462>/TurnIndcrDig3' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* SystemInitialize for Chart: '<S467>/Chart' incorporates:
   *  SubSystem: '<S550>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_i);

  /* SystemInitialize for Chart: '<S467>/Chart' incorporates:
   *  SubSystem: '<S550>/Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S467>/Chart' incorporates:
   *  SubSystem: '<S550>/Lib_RiseEdgeDetInit2'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_c_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);
}

/* Output and update for atomic system: '<S241>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl(void)
{
  sint32 tmp;
  uint8 rtb_RelationalOperator_o5_tmp;
  boolean RelationalOperator;
  boolean RelationalOperator4_j;
  boolean RelationalOperator6_p;
  boolean RelationalOperator8_h;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_LogicalOperator1_d;
  boolean rtb_LogicalOperator4_g;
  boolean rtb_LogicalOperator6_lx;
  boolean rtb_LogicalOperator8_o;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator11_g;
  boolean rtb_RelationalOperator14_a;
  boolean rtb_RelationalOperator19;
  boolean rtb_RelationalOperator1_fb;
  boolean rtb_RelationalOperator23;
  boolean rtb_RelationalOperator3_li;
  boolean rtb_RelationalOperator6_p;
  boolean rtb_RelationalOperator7_j;
  boolean rtb_RelationalOperator9_gr;
  boolean rtb_UnitDelay17;

  /* RelationalOperator: '<S458>/Relational Operator6' incorporates:
   *  Constant: '<S454>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S454>/Relational Operator'
   */
  rtb_RelationalOperator6_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* UnitDelay: '<S351>/Unit Delay17' incorporates:
   *  Inport: '<Root>/IPM_EHB_B_CHA'
   *  RelationalOperator: '<S454>/Relational Operator1'
   */
  rtb_UnitDelay17 = (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA())
    ->VIPM_EHBReqBrkLiOn_flg;

  /* Logic: '<S454>/Logical Operator' */
  LampCtl_EmerSta = (rtb_UnitDelay17 && rtb_RelationalOperator6_p);

  /* RelationalOperator: '<S457>/Relational Operator4' */
  RelationalOperator4_j = LampCtl_EmerSta;

  /* Chart: '<S351>/TurnIndcrLogic' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S351>/Unit Delay2'
   *  UnitDelay: '<S351>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c100_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c100_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
    LampCtl_TurnIndcrMod = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib) {
     case AppSwcBcm_IN_OFF_d:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_na = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S464>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_na,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ek,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oj);

        /* End of Outputs for SubSystem: '<S464>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ek || LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_TurnR;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 1U;
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_ShortFlash;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case AppSwcBcm_IN_TurnL:
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) ||
          LampCtl_TurnIndcrLaneRSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnL == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_l >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrLSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 4U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_h2 = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S464>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_h2,
          &AppSwcBcm_ARID_DEF.LogicalOperator_p1,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

        /* End of Outputs for SubSystem: '<S464>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_p1) {
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_ShortFlash;
        } else {
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 2U;
          LampCtl_TurnIndcrMod = 3U;
        }
      }
      break;

     default:
      /* case IN_TurnR: */
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) ||
          LampCtl_TurnIndcrLaneLSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnR == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrRSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_na = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S464>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_na,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ek,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oj);

        /* End of Outputs for SubSystem: '<S464>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ek) {
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_ShortFlash;
        } else {
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 1U;
          LampCtl_TurnIndcrMod = 1U;
        }
      }
      break;
    }

    if (guard1) {
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_h2 = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S464>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_h2,
          &AppSwcBcm_ARID_DEF.LogicalOperator_p1,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

        /* End of Outputs for SubSystem: '<S464>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_p1 || LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_TurnL;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 2U;
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_ShortFlash;
        }
      }
    }
  }

  /* End of Chart: '<S351>/TurnIndcrLogic' */

  /* Chart: '<S351>/HazardLightLogic' incorporates:
   *  UnitDelay: '<S351>/Unit Delay4'
   *  UnitDelay: '<S351>/Unit Delay5'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c43_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c43_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_OFF;
    LampCtl_HazardLightSta = false;
    LampCtl_EmerHazardLightSta = false;
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib) {
     case AppSwcBcm_IN_EmerON:
      if (((!AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_b) &&
           (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_c)) || AppSwcBcm_HazardOff())
      {
        /* {Lib_RiseEdgeDet(LampCtl_HazardLightSw)} */
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_OFF;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
      }
      break;

     case AppSwcBcm_IN_OFF:
      AppSwcBcm_ARID_DEF.Lib_blIn_g5r = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_c;

      /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_g5r,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ki,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_g);

      /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ki) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_n4 = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_b;

        /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_n4,
          &AppSwcBcm_ARID_DEF.LogicalOperator_at,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_c);

        /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_at) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_oa = LampCtl_HazardLightSw;

          /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_oa,
            &AppSwcBcm_ARID_DEF.LogicalOperator_mx,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o3);

          /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_mx) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_gs =
              (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

            /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet3' */
            AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_gs,
              &AppSwcBcm_ARID_DEF.LogicalOperator_ec,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_f);

            /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet3' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_ec ||
                (AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst &&
                 (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0))) {
              guard2 = true;
            }
          }
        }
      }
      break;

     default:
      /* case IN_ON: */
      if (AppSwcBcm_EmerOff()) {
        AppSwcBcm_ARID_DEF.Lib_blIn_gs =
          (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_gs,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ec,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_f);

        /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_EmerON;
        LampCtl_EmerHazardLightSta = true;
        LampCtl_HazardLightSta = false;
      } else if (AppSwcBcm_HazardOff() || AppSwcBcm_TurnOff()) {
        AppSwcBcm_ARID_DEF.Lib_blIn_gs =
          (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_gs,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ec,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_f);

        /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_OFF;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
      }
      break;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_ON;
      LampCtl_HazardLightSta = true;
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_EmerON;
      LampCtl_EmerHazardLightSta = true;
      LampCtl_HazardLightSta = false;
    }
  }

  /* End of Chart: '<S351>/HazardLightLogic' */

  /* RelationalOperator: '<S457>/Relational Operator' */
  RelationalOperator = LampCtl_EmerHazardLightSta;

  /* Logic: '<S457>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S457>/Relational Operator'
   *  RelationalOperator: '<S457>/Relational Operator4'
   */
  rtb_LogicalOperator8_o = (LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* Chart: '<S449>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c37_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c37_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_AlrmSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib == AppSwcBcm_IN_SetOff_n) {
    AppSwcBcm_ARID_DEF.Lib_blIn_pv =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S469>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_pv,
      &AppSwcBcm_ARID_DEF.LogicalOperator_f1,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

    /* End of Outputs for SubSystem: '<S469>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_f1 && (!rtb_LogicalOperator8_o)) {
      AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
      LampCtl_AlrmSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 2) ||
             rtb_LogicalOperator8_o) {
    AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_AlrmSta = false;
  }

  /* End of Chart: '<S449>/Chart' */

  /* RelationalOperator: '<S457>/Relational Operator6' */
  RelationalOperator6_p = LampCtl_AlrmSta;

  /* Chart: '<S351>/TurnIndcrSelect' */
  if (AppSwcBcm_ARID_DEF.is_active_c118_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c118_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_ah;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib) {
     case AppSwcBcm_IN_Off_ah:
      if (LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_TurnLROn;
      } else {
        switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta) {
         case 1:
          AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_TurnROn;
          break;

         case 2:
          AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_TurnLOn;
          break;
        }
      }
      break;

     case AppSwcBcm_IN_TurnLOn:
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_ah;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 3U;
      }
      break;

     case AppSwcBcm_IN_TurnLROn:
      if (!LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_ah;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 1U;
      }
      break;

     default:
      /* case IN_TurnROn: */
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_ah;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S351>/TurnIndcrSelect' */

  /* RelationalOperator: '<S457>/Relational Operator9' incorporates:
   *  Constant: '<S457>/Constant9'
   */
  rtb_RelationalOperator9_gr = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 0);

  /* RelationalOperator: '<S457>/Relational Operator8' incorporates:
   *  Constant: '<S457>/Constant8'
   */
  RelationalOperator8_h = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide != 0);

  /* Logic: '<S457>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S457>/Relational Operator'
   *  RelationalOperator: '<S457>/Relational Operator4'
   *  RelationalOperator: '<S457>/Relational Operator6'
   */
  rtb_LogicalOperator1_d = (RelationalOperator8_h || LampCtl_AlrmSta ||
    LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* RelationalOperator: '<S468>/Relational Operator' incorporates:
   *  Constant: '<S468>/Constant'
   */
  rtb_RelationalOperator = (LampCtl_RKEReq == 4);

  /* Chart: '<S468>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c123_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c123_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_c;
    LampCtl_VehSeekSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib) {
     case AppSwcBcm_IN_RKESetOn:
      LampCtl_VehSeekSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_np >= 10) ||
          (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) ||
          rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_c;
        LampCtl_VehSeekSta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_pc = rtb_RelationalOperator;

        /* Outputs for Function Call SubSystem: '<S557>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_pc,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h5,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_as);

        /* End of Outputs for SubSystem: '<S557>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h5) {
          AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
            !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_RKESetOn;
          LampCtl_VehSeekSta = 1U;
        }
      }
      break;

     case AppSwcBcm_IN_SetOff_c:
      LampCtl_VehSeekSta = 0U;
      if (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) {
        AppSwcBcm_ARID_DEF.Lib_blIn_pc = rtb_RelationalOperator;

        /* Outputs for Function Call SubSystem: '<S557>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_pc,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h5,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_as);

        /* End of Outputs for SubSystem: '<S557>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h5 && (!rtb_LogicalOperator1_d))
        {
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_RKESetOn;
          LampCtl_VehSeekSta = 1U;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     default:
      /* case IN_TboxSetOn: */
      LampCtl_VehSeekSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_np >= 10) ||
          (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) ||
          rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_c;
        LampCtl_VehSeekSta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_cr =
          ((AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 1) ||
           (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 2));

        /* Outputs for Function Call SubSystem: '<S557>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_cr,
          &AppSwcBcm_ARID_DEF.LogicalOperator_dy,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_a);

        /* End of Outputs for SubSystem: '<S557>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_dy) {
          AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
            !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_TboxSetOn;
          LampCtl_VehSeekSta = 2U;
        }
      }
      break;
    }

    if (guard1) {
      if (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) {
        AppSwcBcm_ARID_DEF.Lib_blIn_cr =
          ((AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 1) ||
           (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 2));

        /* Outputs for Function Call SubSystem: '<S557>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_cr,
          &AppSwcBcm_ARID_DEF.LogicalOperator_dy,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_a);

        /* End of Outputs for SubSystem: '<S557>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_dy && (!rtb_LogicalOperator1_d))
        {
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_TboxSetOn;
          LampCtl_VehSeekSta = 2U;
        }
      }
    }
  }

  /* End of Chart: '<S468>/Chart' */

  /* Chart: '<S450>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S351>/Unit Delay10'
   *  UnitDelay: '<S351>/Unit Delay11'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c38_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c38_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_Off_ah;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib == AppSwcBcm_IN_Off_ah) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck ||
         (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck) &&
        (!rtb_LogicalOperator1_d)) {
      AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_On_i;
      LampCtl_AntiLckSta = true;
    }

    /* case IN_On: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE >= 3) ||
             rtb_LogicalOperator1_d || (LampCtl_VehSeekSta == 1)) {
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_Off_ah;
    LampCtl_AntiLckSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck ||
             (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck) {
    AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_On_i;
    LampCtl_AntiLckSta = true;
  }

  /* End of Chart: '<S450>/Chart' */

  /* Chart: '<S451>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1 < 63U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c40_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c40_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib == AppSwcBcm_IN_SetOff_n) {
    AppSwcBcm_ARID_DEF.Lib_blIn_n5 =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S473>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_n5,
      &AppSwcBcm_ARID_DEF.LogicalOperator_hs,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_f);

    /* End of Outputs for SubSystem: '<S473>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_hs ||
         (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2) &&
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1))) &&
        (!rtb_LogicalOperator1_d)) {
      AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
      AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
      LampCtl_ArmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.temporalCounter_i1 >= 50U) ||
             (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) ||
             (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_d) {
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_ArmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2)
  {
    AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt = !AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
    AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
    LampCtl_ArmedSta = true;
  }

  /* End of Chart: '<S451>/Chart' */

  /* Chart: '<S453>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S351>/Unit Delay8'
   *  UnitDelay: '<S351>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c42_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c42_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib == AppSwcBcm_IN_SetOff_n) {
    AppSwcBcm_ARID_DEF.Lib_blIn_m1 =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 0);

    /* Outputs for Function Call SubSystem: '<S487>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_m1,
      &AppSwcBcm_ARID_DEF.LogicalOperator_bv,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_l);

    /* End of Outputs for SubSystem: '<S487>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_bv ||
         ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 0) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 1)))
        && (!rtb_LogicalOperator1_d)) {
      AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
      LampCtl_DisarmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 0) ||
             (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_d) {
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_DisarmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 1)
  {
    AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
    LampCtl_DisarmedSta = true;
  }

  /* End of Chart: '<S453>/Chart' */

  /* Chart: '<S456>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c5_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c5_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_PartArmedSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib) {
     case AppSwcBcm_IN_SetOff_n:
      LampCtl_PartArmedSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_In_d = AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
      AppSwcBcm_ARID_DEF.Lib_InNow_f = 3.0F;
      AppSwcBcm_ARID_DEF.Lib_InBefore_j = 1.0F;

      /* Outputs for Function Call SubSystem: '<S502>/Lib_ChangeEdge2' */
      AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_d,
        AppSwcBcm_ARID_DEF.Lib_InNow_f, AppSwcBcm_ARID_DEF.Lib_InBefore_j,
        &AppSwcBcm_ARID_DEF.LogicalOperator_p0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

      /* End of Outputs for SubSystem: '<S502>/Lib_ChangeEdge2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_p0) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn2;
        LampCtl_PartArmedSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_In = AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
        AppSwcBcm_ARID_DEF.Lib_InNow = 3.0F;
        AppSwcBcm_ARID_DEF.Lib_InBefore = 0.0F;

        /* Outputs for Function Call SubSystem: '<S502>/Lib_ChangeEdge' */
        AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In,
          AppSwcBcm_ARID_DEF.Lib_InNow, AppSwcBcm_ARID_DEF.Lib_InBefore,
          &AppSwcBcm_ARID_DEF.LogicalOperator_eq,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

        /* End of Outputs for SubSystem: '<S502>/Lib_ChangeEdge' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_eq) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_In_p =
            AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
          AppSwcBcm_ARID_DEF.Lib_InNow_d = 3.0F;
          AppSwcBcm_ARID_DEF.Lib_InBefore_n = 2.0F;

          /* Outputs for Function Call SubSystem: '<S502>/Lib_ChangeEdge1' */
          AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_p,
            AppSwcBcm_ARID_DEF.Lib_InNow_d, AppSwcBcm_ARID_DEF.Lib_InBefore_n,
            &AppSwcBcm_ARID_DEF.LogicalOperator_hf,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

          /* End of Outputs for SubSystem: '<S502>/Lib_ChangeEdge1' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_hf ||
              (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta ==
                2) && (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3))) {
            guard1 = true;
          }
        }
      }
      break;

     case AppSwcBcm_IN_SetOn1:
      LampCtl_PartArmedSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
        LampCtl_PartArmedSta = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta ==
                 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;

     default:
      /* case IN_SetOn2: */
      LampCtl_PartArmedSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
        LampCtl_PartArmedSta = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta ==
                 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;
    }

    if (guard1) {
      if (!rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
    }
  }

  /* End of Chart: '<S456>/Chart' */

  /* RelationalOperator: '<S457>/Relational Operator5' */
  rtb_RelationalOperator = !LampCtl_EmerSta;

  /* RelationalOperator: '<S457>/Relational Operator7' */
  rtb_RelationalOperator7_j = !LampCtl_AlrmSta;

  /* UnitDelay: '<S351>/Unit Delay17' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   *  RelationalOperator: '<S458>/Relational Operator1'
   */
  rtb_UnitDelay17 =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwStVld_flg;

  /* RelationalOperator: '<S458>/Relational Operator6' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator6_p =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwStVld_flg;

  /* Logic: '<S458>/Logical Operator2' */
  rtb_RelationalOperator6_p = (rtb_UnitDelay17 || rtb_RelationalOperator6_p);

  /* UnitDelay: '<S351>/Unit Delay17' incorporates:
   *  Constant: '<S458>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S458>/Relational Operator'
   */
  rtb_UnitDelay17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
                     ->SysPwrMode == 2);

  /* RelationalOperator: '<S458>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S457>/Relational Operator12'
   */
  rtb_LogicalOperator6_lx = !LampCtl_ArmedSta;

  /* RelationalOperator: '<S458>/Relational Operator2' incorporates:
   *  RelationalOperator: '<S457>/Relational Operator15'
   */
  rtb_RelationalOperator3_li = !LampCtl_DisarmedSta;

  /* RelationalOperator: '<S458>/Relational Operator7' incorporates:
   *  RelationalOperator: '<S457>/Relational Operator17'
   */
  rtb_LogicalOperator4_g = !LampCtl_AntiLckSta;

  /* Chart: '<S458>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S458>/Constant2'
   *  Constant: '<S458>/Constant21'
   *  Constant: '<S458>/Constant3'
   *  Constant: '<S458>/Constant5'
   *  Constant: '<S458>/Constant7'
   *  Logic: '<S458>/Logical Operator'
   *  Logic: '<S458>/Logical Operator1'
   *  RelationalOperator: '<S458>/Relational Operator2'
   *  RelationalOperator: '<S458>/Relational Operator3'
   *  RelationalOperator: '<S458>/Relational Operator4'
   *  RelationalOperator: '<S458>/Relational Operator5'
   *  RelationalOperator: '<S458>/Relational Operator7'
   */
  if (rtb_LogicalOperator4_g && rtb_RelationalOperator3_li &&
      (LampCtl_PartArmedSta == 0) && rtb_LogicalOperator6_lx &&
      (LampCtl_VehSeekSta == 0) && rtb_RelationalOperator6_p && rtb_UnitDelay17)
  {
    if (AppSwcBcm_ARID_DEF.cnt_defect_m4 >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_RodBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m4++;
      AppSwcBcm_ARID_DEF.cnt_heal_g = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m4 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g == 0) {
      LampCtl_RodBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_g--;
    }
  }

  /* End of Chart: '<S458>/LIB_TPD_10ms' */

  /* Chart: '<S467>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c119_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c119_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_li;
    LampCtl_VehModeSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib) {
     case AppSwcBcm_IN_Init_li:
      LampCtl_VehModeSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_la =
        (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum == 1);

      /* Outputs for Function Call SubSystem: '<S550>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_la,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ns,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_i);

      /* End of Outputs for SubSystem: '<S550>/Lib_RiseEdgeDetInit' */
      rtb_UnitDelay17 = !rtb_LogicalOperator1_d;
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ns && rtb_UnitDelay17) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Show;
        LampCtl_VehModeSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ir =
          (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum == 2);

        /* Outputs for Function Call SubSystem: '<S550>/Lib_RiseEdgeDetInit1' */
        AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_ir,
          &AppSwcBcm_ARID_DEF.LogicalOperator_k1,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

        /* End of Outputs for SubSystem: '<S550>/Lib_RiseEdgeDetInit1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_k1 && rtb_UnitDelay17) {
          AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Limit;
          LampCtl_VehModeSta = 3U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_ol2 =
            (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum ==
             0);

          /* Outputs for Function Call SubSystem: '<S550>/Lib_RiseEdgeDetInit2' */
          AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_ol2,
            &AppSwcBcm_ARID_DEF.LogicalOperator_jq,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);

          /* End of Outputs for SubSystem: '<S550>/Lib_RiseEdgeDetInit2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_jq && rtb_UnitDelay17) {
            AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Nrm;
            LampCtl_VehModeSta = 1U;
          }
        }
      }
      break;

     case AppSwcBcm_IN_Limit:
      LampCtl_VehModeSta = 3U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 3) || rtb_LogicalOperator1_d)
      {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_li;
        LampCtl_VehModeSta = 0U;
      }
      break;

     case AppSwcBcm_IN_Nrm:
      LampCtl_VehModeSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 1) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 1) || rtb_LogicalOperator1_d)
      {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_li;
        LampCtl_VehModeSta = 0U;
      }
      break;

     default:
      /* case IN_Show: */
      LampCtl_VehModeSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 2) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 2) || rtb_LogicalOperator1_d)
      {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_li;
        LampCtl_VehModeSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S467>/Chart' */

  /* Chart: '<S460>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S351>/Unit Delay14'
   *  UnitDelay: '<S351>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c47_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c47_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_c;
    LampCtl_TrunkWarnSta = false;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib) {
     case AppSwcBcm_IN_Delay_b:
      if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_c;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      } else if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3) &&
                 (AppSwcBcm_ARID_DEF.TrunkWarnCnt >= LampCtl_TrunkWarnTim_C)) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
        LampCtl_TrunkWarnSta = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff_c:
      AppSwcBcm_ARID_DEF.Lib_blIn_en =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S515>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_nw(AppSwcBcm_ARID_DEF.Lib_blIn_en,
        &AppSwcBcm_ARID_DEF.LogicalOperator_f,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ip);

      /* End of Outputs for SubSystem: '<S515>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_f && (!rtb_LogicalOperator1_d) &&
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3)) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_Delay_b;
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt = (uint16)tmp;
      }
      break;

     default:
      /* case IN_SetOn: */
      if ((AppSwcBcm_ARID_DEF.UnitDelay14_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay15_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_c;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S460>/Chart' */

  /* Logic: '<S457>/Logical Operator10' incorporates:
   *  Constant: '<S457>/Constant16'
   *  Constant: '<S457>/Constant26'
   *  RelationalOperator: '<S457>/Relational Operator16'
   *  RelationalOperator: '<S457>/Relational Operator25'
   */
  rtb_UnitDelay17 = ((LampCtl_PartArmedSta == 2) || (LampCtl_PartArmedSta == 1));

  /* RelationalOperator: '<S457>/Relational Operator10' */
  rtb_RelationalOperator6_p = LampCtl_ArmedSta;

  /* RelationalOperator: '<S457>/Relational Operator11' incorporates:
   *  Constant: '<S457>/Constant12'
   */
  rtb_RelationalOperator11_g = (LampCtl_VehSeekSta != 0);

  /* RelationalOperator: '<S457>/Relational Operator14' */
  rtb_RelationalOperator14_a = LampCtl_DisarmedSta;

  /* RelationalOperator: '<S457>/Relational Operator1' */
  rtb_RelationalOperator1_fb = LampCtl_RodBeamFaultSta;

  /* RelationalOperator: '<S457>/Relational Operator19' */
  rtb_RelationalOperator19 = LampCtl_AntiLckSta;

  /* Logic: '<S457>/Logical Operator9' incorporates:
   *  Constant: '<S457>/Constant20'
   *  Constant: '<S457>/Constant21'
   *  Constant: '<S457>/Constant23'
   *  RelationalOperator: '<S457>/Relational Operator20'
   *  RelationalOperator: '<S457>/Relational Operator22'
   *  RelationalOperator: '<S457>/Relational Operator3'
   */
  rtb_LogicalOperator9 = ((LampCtl_VehModeSta == 1) || (LampCtl_VehModeSta == 2)
    || (LampCtl_VehModeSta == 3));

  /* RelationalOperator: '<S457>/Relational Operator23' */
  rtb_RelationalOperator23 = LampCtl_TrunkWarnSta;

  /* Logic: '<S457>/Logical Operator6' incorporates:
   *  Constant: '<S457>/Constant13'
   *  Constant: '<S457>/Constant17'
   *  Constant: '<S457>/Constant22'
   *  RelationalOperator: '<S457>/Relational Operator13'
   *  RelationalOperator: '<S457>/Relational Operator18'
   *  RelationalOperator: '<S457>/Relational Operator2'
   *  RelationalOperator: '<S457>/Relational Operator21'
   *  RelationalOperator: '<S457>/Relational Operator24'
   */
  rtb_LogicalOperator6_lx = (rtb_LogicalOperator6_lx && (LampCtl_VehSeekSta == 0)
    && rtb_RelationalOperator3_li && (LampCtl_PartArmedSta == 0) &&
    (!LampCtl_RodBeamFaultSta) && rtb_LogicalOperator4_g && (LampCtl_VehModeSta ==
    0) && (!LampCtl_TrunkWarnSta));

  /* RelationalOperator: '<S462>/Relational Operator' incorporates:
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S462>/Relational Operator5'
   */
  rtb_RelationalOperator_o5_tmp =
    Rte_IRead_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt();

  /* Logic: '<S462>/Logical Operator4' incorporates:
   *  UnitDelay: '<S351>/Unit Delay16'
   */
  rtb_LogicalOperator4_g = (LampCtl_TurnIndcrLaneLSw &&
    AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE);

  /* Outputs for Enabled SubSystem: '<S462>/Enabled Subsystem3' incorporates:
   *  EnablePort: '<S535>/Enable'
   */
  if (rtb_LogicalOperator4_g) {
    /* CCaller: '<S535>/C Caller' incorporates:
     *  Constant: '<S535>/Constant17'
     */
    LampCtl_TurnIndcrLVol = GetHw_TurnIndcrVol(0U);
  }

  /* End of Outputs for SubSystem: '<S462>/Enabled Subsystem3' */

  /* RelationalOperator: '<S462>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_li = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S462>/TurnIndcrDig3' incorporates:
   *  Constant: '<S462>/Constant17'
   *  Constant: '<S462>/Constant21'
   *  Constant: '<S462>/Constant43'
   *  Constant: '<S462>/Constant44'
   *  Constant: '<S462>/Constant45'
   *  RelationalOperator: '<S462>/Relational Operator1'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_g, LampCtl_TurnIndcrLVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_li, LampCtl_Ts_C,
    LampCtl_TurnIndcrLOpenTimValid_C, LampCtl_TurnIndcrLOpenTimInValid_C,
    LampCtl_LOpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig3);

  /* Logic: '<S462>/Logical Operator' incorporates:
   *  Constant: '<S462>/Constant'
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S462>/Relational Operator'
   */
  LampCtl_TurnIndcrLOpen = ((rtb_RelationalOperator_o5_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* Chart: '<S462>/TurnIndcrDig2' incorporates:
   *  Constant: '<S462>/Constant10'
   *  Constant: '<S462>/Constant18'
   *  Constant: '<S462>/Constant19'
   *  Constant: '<S462>/Constant4'
   *  Constant: '<S462>/Constant9'
   *  RelationalOperator: '<S462>/Relational Operator4'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_g, LampCtl_TurnIndcrLVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_li, LampCtl_Ts_C,
    LampCtl_TurnIndcrLShortTimValid_C, LampCtl_TurnIndcrLShortTimInValid_C,
    LampCtl_LShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig2);

  /* Logic: '<S462>/Logical Operator2' incorporates:
   *  Constant: '<S462>/Constant7'
   *  RelationalOperator: '<S462>/Relational Operator5'
   */
  LampCtl_TurnIndcrLShort = ((rtb_RelationalOperator_o5_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_d);

  /* RelationalOperator: '<S462>/Relational Operator2' incorporates:
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S462>/Relational Operator6'
   */
  rtb_RelationalOperator_o5_tmp =
    Rte_IRead_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt();

  /* Logic: '<S462>/Logical Operator5' incorporates:
   *  UnitDelay: '<S351>/Unit Delay17'
   */
  rtb_LogicalOperator4_g = (LampCtl_TurnIndcrLaneRSw &&
    AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE);

  /* Outputs for Enabled SubSystem: '<S462>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S534>/Enable'
   */
  if (rtb_LogicalOperator4_g) {
    /* CCaller: '<S534>/C Caller' incorporates:
     *  Constant: '<S534>/Constant17'
     */
    LampCtl_TurnIndcrRVol = GetHw_TurnIndcrVol(1U);
  }

  /* End of Outputs for SubSystem: '<S462>/Enabled Subsystem1' */

  /* Chart: '<S462>/TurnIndcrDig' incorporates:
   *  Constant: '<S462>/Constant11'
   *  Constant: '<S462>/Constant2'
   *  Constant: '<S462>/Constant3'
   *  Constant: '<S462>/Constant6'
   *  Constant: '<S462>/Constant8'
   *  RelationalOperator: '<S462>/Relational Operator7'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_g, LampCtl_TurnIndcrRVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_li, LampCtl_Ts_C,
    LampCtl_TurnIndcrROpenTimValid_C, LampCtl_TurnIndcrROpenTimInValid_C,
    LampCtl_ROpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig);

  /* Logic: '<S462>/Logical Operator1' incorporates:
   *  Constant: '<S462>/Constant5'
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S462>/Relational Operator2'
   */
  LampCtl_TurnIndcrROpen = ((rtb_RelationalOperator_o5_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_l);

  /* Chart: '<S462>/TurnIndcrDig1' incorporates:
   *  Constant: '<S462>/Constant12'
   *  Constant: '<S462>/Constant13'
   *  Constant: '<S462>/Constant14'
   *  Constant: '<S462>/Constant16'
   *  Constant: '<S462>/Constant20'
   *  RelationalOperator: '<S462>/Relational Operator8'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_g, LampCtl_TurnIndcrRVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_li, LampCtl_Ts_C,
    LampCtl_TurnIndcrRShortTimValid_C, LampCtl_TurnIndcrRShortTimInValid_C,
    LampCtl_RShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig1);

  /* Logic: '<S462>/Logical Operator3' incorporates:
   *  Constant: '<S462>/Constant15'
   *  RelationalOperator: '<S462>/Relational Operator6'
   */
  LampCtl_TurnIndcrRShort = ((rtb_RelationalOperator_o5_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_j);

  /* Chart: '<S351>/TurnIndcrArb2' incorporates:
   *  Logic: '<S457>/Logical Operator'
   *  Logic: '<S457>/Logical Operator2'
   *  Logic: '<S457>/Logical Operator3'
   *  Logic: '<S457>/Logical Operator4'
   *  Logic: '<S457>/Logical Operator5'
   *  Logic: '<S457>/Logical Operator7'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c75_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c75_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
    AppSwcBcm_EnFunc();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib) {
     case AppSwcBcm_IN_Pri1:
      if (!RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri2:
      if (rtb_RelationalOperator || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri2Func();
      }
      break;

     case AppSwcBcm_IN_Pri3:
      if (rtb_RelationalOperator7_j || rtb_LogicalOperator8_o) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri4:
      if (rtb_RelationalOperator9_gr || RelationalOperator6_p ||
          RelationalOperator4_j || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri4Func();
      }
      break;

     case AppSwcBcm_IN_Pri5:
      if (rtb_LogicalOperator6_lx || rtb_LogicalOperator1_d) {
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        switch (AppSwcBcm_ARID_DEF.is_Pri5) {
         case AppSwcBcm_IN_AntiLck:
          if (!LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_AntiLckFunc();
          }
          break;

         case AppSwcBcm_IN_Armed:
          if (!LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_ArmedFunc();
          }
          break;

         case AppSwcBcm_IN_Disarmed:
          if (!LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_DisarmedFunc();
          }
          break;

         case AppSwcBcm_IN_PartArmed:
          if (LampCtl_PartArmedSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_PartArmedFunc();
          }
          break;

         case AppSwcBcm_IN_RodBeam:
          if (!LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_RodBeamFunc();
          }
          break;

         case AppSwcBcm_IN_Seek:
          if (LampCtl_VehSeekSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_SeekFunc();
          }
          break;

         case AppSwcBcm_IN_Trans_p:
          if (LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Armed;
          } else if (LampCtl_PartArmedSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_PartArmed;
          } else if (LampCtl_VehSeekSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Seek;
          } else if (LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Disarmed;
          } else if (LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_RodBeam;
          } else if (LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_AntiLck;
          } else if (LampCtl_VehModeSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_VehMode;
          } else if (LampCtl_TrunkWarnSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_TrunkWarn;
          }
          break;

         case AppSwcBcm_IN_TrunkWarn:
          if (!LampCtl_TrunkWarnSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_TrunkWarnFunc();
          }
          break;

         default:
          /* case IN_VehMode: */
          if (LampCtl_VehModeSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_VehModeFunc();
          }
          break;
        }
      }
      break;

     default:
      /* case IN_Trans: */
      if (RelationalOperator) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri1;
      } else if (RelationalOperator4_j) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri2;
      } else if (RelationalOperator6_p) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri3;
      } else if (RelationalOperator8_h) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri4;
      } else if (rtb_RelationalOperator6_p || rtb_RelationalOperator11_g ||
                 rtb_RelationalOperator14_a || rtb_UnitDelay17 ||
                 rtb_RelationalOperator1_fb || rtb_RelationalOperator19 ||
                 rtb_LogicalOperator9 || rtb_RelationalOperator23) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri5;
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_p;
        AppSwcBcm_TurnFunc();
      }
      break;
    }
  }

  /* End of Chart: '<S351>/TurnIndcrArb2' */
  AppSwcBcm_ARID_DEF.Lib_blIn_b4 = LampCtl_TurnIndcrRst;

  /* Chart: '<S463>/LIB_Pulse' incorporates:
   *  SubSystem: '<S540>/Lib_BothEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S541>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_b4,
    &AppSwcBcm_ARID_DEF.LogicalOperator2_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet_o);

  /* End of Outputs for SubSystem: '<S541>/Lib_BothEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator2_g) {
    AppSwcBcm_ARID_DEF.cnt_j = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  if (LampCtl_TurnIndcrLFlashCnt >= 1) {
    if (LampCtl_TurnIndcrLFlashCnt >= 65535) {
      LampCtl_PrdSucCntL = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_i = (AppSwcBcm_ARID_DEF.cnt_j <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_j >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_j = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_j + 1;
        if (AppSwcBcm_ARID_DEF.cnt_j + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_j = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntL < LampCtl_TurnIndcrLFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_i = (AppSwcBcm_ARID_DEF.cnt_j <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_j >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_j = 0U;
        tmp = LampCtl_PrdSucCntL + 1;
        if (LampCtl_PrdSucCntL + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntL = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_j + 1;
        if (AppSwcBcm_ARID_DEF.cnt_j + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_j = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_i = false;
    AppSwcBcm_ARID_DEF.cnt_j = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_hb = LampCtl_TurnIndcrRst;

  /* Chart: '<S465>/LIB_Pulse' incorporates:
   *  SubSystem: '<S547>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_hb,
    &AppSwcBcm_ARID_DEF.RelationalOperator_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_g) {
    AppSwcBcm_ARID_DEF.cnt_b = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  if (LampCtl_TurnIndcrRFlashCnt >= 1) {
    if (LampCtl_TurnIndcrRFlashCnt >= 65535) {
      LampCtl_PrdSucCntR = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_p = (AppSwcBcm_ARID_DEF.cnt_b <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_b >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_b = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_b + 1;
        if (AppSwcBcm_ARID_DEF.cnt_b + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_b = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntR < LampCtl_TurnIndcrRFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_p = (AppSwcBcm_ARID_DEF.cnt_b <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_b >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_b = 0U;
        tmp = LampCtl_PrdSucCntR + 1;
        if (LampCtl_PrdSucCntR + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntR = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_b + 1;
        if (AppSwcBcm_ARID_DEF.cnt_b + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_b = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_p = false;
    AppSwcBcm_ARID_DEF.cnt_b = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  /* Chart: '<S468>/SeekFb' */
  if (AppSwcBcm_ARID_DEF.is_active_c85_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Init_b;
    LampCtl_VehSeekStaFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_jg = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib) {
     case AppSwcBcm_IN_Fail:
      LampCtl_VehSeekStaFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_jg >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Init_b;
        LampCtl_VehSeekStaFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_jg = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_jg + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_jg + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_jg = (uint8)tmp;
      }
      break;

     case AppSwcBcm_IN_Init_b:
      LampCtl_VehSeekStaFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_l3 =
        ((AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 1) ||
         (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum == 2));

      /* Outputs for Function Call SubSystem: '<S558>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_l3,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ic,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_e);

      /* End of Outputs for SubSystem: '<S558>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ic) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Wait;
      }
      break;

     case AppSwcBcm_IN_Suc:
      LampCtl_VehSeekStaFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_jg >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Init_b;
        LampCtl_VehSeekStaFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_jg = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_jg + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_jg + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_jg = (uint8)tmp;
      }
      break;

     default:
      /* case IN_Wait: */
      if (LampCtl_VehSeekSta == 2) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Suc;
        LampCtl_VehSeekStaFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_jg + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_jg + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_jg = (uint8)tmp;
      } else if (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_TBoxRmtCarSearch_enum ==
                 0) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Fail;
        LampCtl_VehSeekStaFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_jg + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_jg + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_jg = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S468>/SeekFb' */

  /* Chart: '<S452>/Chart' incorporates:
   *  Inport: '<Root>/IPM_SRS_1_Status_CHA'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c41_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c41_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
    LampCtl_CrashSta = false;
    AppSwcBcm_ARID_DEF.PwrOffFlg = false;
    AppSwcBcm_ARID_DEF.PwrOnFlg = false;
    AppSwcBcm_ARID_DEF.Cnt_d2 = 0U;
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib) {
     case AppSwcBcm_IN_CrashDelay:
      if (AppSwcBcm_ARID_DEF.Cnt_d2 >= 50) {
        AppSwcBcm_ARID_DEF.Lib_blIn_nh =
          (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 1);

        /* Outputs for Function Call SubSystem: '<S476>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_nh,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ew,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_mv);

        /* End of Outputs for SubSystem: '<S476>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ew) {
          AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
          LampCtl_CrashSta = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 0) {
          AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashDelay;
          AppSwcBcm_ARID_DEF.Cnt_d2 = 0U;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case AppSwcBcm_IN_CrashOff:
      AppSwcBcm_ARID_DEF.Lib_blIn_pm =
        (((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 1) ||
         ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 2) ||
         ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 4) ||
         ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 5));

      /* Outputs for Function Call SubSystem: '<S476>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_pm,
        &AppSwcBcm_ARID_DEF.LogicalOperator_dx,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

      /* End of Outputs for SubSystem: '<S476>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_dx) {
        guard2 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ldw = (BSW_CrashPWMSta == 1);

        /* Outputs for Function Call SubSystem: '<S476>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ldw,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ob,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_m);

        /* End of Outputs for SubSystem: '<S476>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ob) {
          guard2 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 1) {
          AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashDelay;
          AppSwcBcm_ARID_DEF.Cnt_d2 = 0U;
        }
      }
      break;

     default:
      /* case IN_CrashOn: */
      if (AppSwcBcm_ARID_DEF.PwrOffFlg && AppSwcBcm_ARID_DEF.PwrOnFlg) {
        /* ||BSW_EECrshSta==0] */
        AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
        LampCtl_CrashSta = false;
        AppSwcBcm_ARID_DEF.PwrOffFlg = false;
        AppSwcBcm_ARID_DEF.PwrOnFlg = false;
        AppSwcBcm_ARID_DEF.Cnt_d2 = 0U;
      } else {
        AppSwcBcm_CrashClearFunc();
      }
      break;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
      LampCtl_CrashSta = true;
    }

    if (guard1) {
      if (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 0) {
        AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
        LampCtl_CrashSta = false;
        AppSwcBcm_ARID_DEF.PwrOffFlg = false;
        AppSwcBcm_ARID_DEF.PwrOnFlg = false;
        AppSwcBcm_ARID_DEF.Cnt_d2 = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_d2 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_d2 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_d2 = (uint8)tmp;
      }
    }
  }

  /* End of Chart: '<S452>/Chart' */

  /* Chart: '<S459>/Chart' incorporates:
   *  Inport: '<Root>/IPM_BMS_1_MainState_EPT'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c46_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c46_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
    LampCtl_ThermalrunawaySta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib == AppSwcBcm_IN_SetOff_n) {
    AppSwcBcm_ARID_DEF.Lib_blIn_br =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
        ())->VIPM_BMSThermrunawayWrn_enum == 1);

    /* Outputs for Function Call SubSystem: '<S510>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_br,
      &AppSwcBcm_ARID_DEF.LogicalOperator_km,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_i);

    /* End of Outputs for SubSystem: '<S510>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_km) {
      AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
    }
  } else {
    /* case IN_SetOn: */
    guard1 = false;
    if ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
         ())->VIPM_BMSThermrunawayWrn_enum == 0) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_jh = LampCtl_HazardLightSw;

      /* Outputs for Function Call SubSystem: '<S510>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_jh,
        &AppSwcBcm_ARID_DEF.LogicalOperator_nd,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

      /* End of Outputs for SubSystem: '<S510>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_nd) {
        guard1 = true;
      } else {
        LampCtl_ThermalrunawaySta = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOff_n;
      LampCtl_ThermalrunawaySta = false;
    }
  }

  /* End of Chart: '<S459>/Chart' */

  /* Update for UnitDelay: '<S351>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_c = LampCtl_CrashSta;

  /* Update for UnitDelay: '<S351>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_b = LampCtl_ThermalrunawaySta;

  /* Update for UnitDelay: '<S351>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_l = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_np = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay11' */
  AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay10' */
  AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay13' */
  AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay12' */
  AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay15' */
  AppSwcBcm_ARID_DEF.UnitDelay15_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S351>/Unit Delay14' */
  AppSwcBcm_ARID_DEF.UnitDelay14_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S351>/Unit Delay16' */
  AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE = AppSwcBcm_ARID_DEF.LIB_blOut_i;

  /* Update for UnitDelay: '<S351>/Unit Delay17' */
  AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE = AppSwcBcm_ARID_DEF.LIB_blOut_p;
}

/*
 * System initialize for atomic system:
 *    '<S576>/Lib_RiseEdgeDetInit'
 *    '<S653>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_k_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S577>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S576>/Lib_RiseEdgeDetInit'
 *    '<S653>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_nr(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_k_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S577>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S577>/Logical Operator' incorporates:
   *  Delay: '<S577>/Delay'
   *  Logic: '<S577>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S577>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Output and update for atomic system: '<S566>/Lib_RiseEdgeDet' */
static void AppSwcBcm_Lib_RiseEdgeDet_c(void)
{
  /* Logic: '<S575>/Logical Operator' incorporates:
   *  Logic: '<S575>/Logical Operator1'
   *  UnitDelay: '<S575>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_db = (AppSwcBcm_ARID_DEF.LIB_blOut_e &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_io));

  /* Update for UnitDelay: '<S575>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_io = AppSwcBcm_ARID_DEF.LIB_blOut_e;
}

/* Output and update for atomic system: '<S570>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge_p(void)
{
  /* Logic: '<S579>/Logical Operator' incorporates:
   *  Constant: '<S570>/Constant3'
   *  Constant: '<S570>/Constant4'
   *  RelationalOperator: '<S579>/Relational Operator'
   *  RelationalOperator: '<S579>/Relational Operator1'
   *  UnitDelay: '<S579>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4_l =
    ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) &&
     (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fg == 0));

  /* Update for UnitDelay: '<S579>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fg =
    AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
}

/* System initialize for atomic system: '<S241>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_iq;

  /* InitializeConditions for UnitDelay: '<S352>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = 60U;

  /* InitializeConditions for Delay: '<S567>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_f = true;

  /* SystemInitialize for Chart: '<S566>/LIB_PosPluseInit' incorporates:
   *  SubSystem: '<S574>/Lib_RiseEdgeDet'
   */

  /* SystemInitialize for Atomic SubSystem: '<S576>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_a);

  /* End of SystemInitialize for SubSystem: '<S576>/Lib_RiseEdgeDetInit' */

  /* SystemInitialize for Chart: '<S570>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_iq);

  /* SystemInitialize for Chart: '<S571>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_b);
}

/* Output and update for atomic system: '<S241>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_iq;
  sint32 tmp;
  uint8 tmp_0;
  boolean rtb_LIB_blOut_e;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator1_k0;
  boolean rtb_RelationalOperator2_n5;

  /* RelationalOperator: '<S571>/Relational Operator2' incorporates:
   *  Constant: '<S565>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S565>/Relational Operator'
   */
  rtb_RelationalOperator2_n5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* RelationalOperator: '<S571>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S565>/Relational Operator3'
   */
  rtb_RelationalOperator1_k0 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->OsLck;

  /* Chart: '<S565>/LIB_Tim' incorporates:
   *  Constant: '<S565>/Constant5'
   *  Logic: '<S565>/Logical Operator1'
   *  Logic: '<S565>/Logical Operator2'
   *  Product: '<S565>/Product'
   *  UnitDelay: '<S352>/Unit Delay1'
   *  UnitDelay: '<S352>/Unit Delay2'
   */
  if ((!rtb_RelationalOperator1_k0) && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_h) {
    if (AppSwcBcm_ARID_DEF.Cnt_b <= (uint16)(50U *
         AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE)) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_b + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_b + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_b = (uint16)tmp;
      rtb_LIB_blOut_e = false;
    } else {
      rtb_LIB_blOut_e = true;
    }
  } else {
    rtb_LIB_blOut_e = false;
    AppSwcBcm_ARID_DEF.Cnt_b = 0U;
  }

  /* End of Chart: '<S565>/LIB_Tim' */

  /* Outputs for Atomic SubSystem: '<S565>/Lib_RiseEdgeDet3' */
  /* RelationalOperator: '<S565>/Relational Operator1' incorporates:
   *  Constant: '<S565>/Constant1'
   */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(LampCtl_VehSeekSta == 1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3);

  /* End of Outputs for SubSystem: '<S565>/Lib_RiseEdgeDet3' */

  /* RelationalOperator: '<S571>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S565>/Relational Operator2'
   */
  rtb_RelationalOperator1_k0 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->OsUnlck;

  /* Logic: '<S565>/Logical Operator' */
  rtb_RelationalOperator2_n5 = (rtb_LIB_blOut_e || rtb_RelationalOperator2_n5 ||
    rtb_RelationalOperator1_k0 || rtb_LogicalOperator);

  /* RelationalOperator: '<S571>/Relational Operator1' incorporates:
   *  Constant: '<S567>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S567>/Relational Operator'
   */
  rtb_RelationalOperator1_k0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Delay: '<S567>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_f) {
    /* Switch: '<S567>/Switch1' incorporates:
     *  Constant: '<S567>/Constant12'
     *  Constant: '<S567>/Constant13'
     *  RelationalOperator: '<S567>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_m = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_m =
        AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb;
    }

    /* End of Switch: '<S567>/Switch1' */
  }

  /* Switch: '<S567>/Switch' incorporates:
   *  Constant: '<S567>/Constant11'
   */
  if (rtb_RelationalOperator1_k0) {
    tmp_0 = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUFlwrMeHmCtrl_enum;
  } else {
    tmp_0 = 0U;
  }

  /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
   *  Switch: '<S567>/Switch'
   */
  switch (tmp_0) {
   case 1:
    /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
     *  Constant: '<S567>/Constant6'
     */
    LampCtl_FlwrMeHomeCtlFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
     *  Constant: '<S567>/Constant7'
     */
    LampCtl_FlwrMeHomeCtlFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
     *  Constant: '<S567>/Constant8'
     */
    LampCtl_FlwrMeHomeCtlFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
     *  Constant: '<S567>/Constant9'
     */
    LampCtl_FlwrMeHomeCtlFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
     *  Constant: '<S567>/Constant10'
     */
    LampCtl_FlwrMeHomeCtlFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S567>/Multiport Switch1' incorporates:
     *  Delay: '<S567>/Delay'
     */
    LampCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_m;
    break;
  }

  /* End of MultiPortSwitch: '<S567>/Multiport Switch1' */

  /* Logic: '<S566>/Logical Operator2' incorporates:
   *  Constant: '<S566>/Constant1'
   *  Constant: '<S566>/Constant3'
   *  Constant: '<S566>/Constant4'
   *  RelationalOperator: '<S566>/Relational Operator1'
   *  RelationalOperator: '<S566>/Relational Operator3'
   *  RelationalOperator: '<S566>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ek = ((LampCtl_FlwrMeHomeCtlFb != 0) &&
    (LampCtl_LightIntstSta == 2) && (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts
    == 1));
  AppSwcBcm_ARID_DEF.Lib_blInit_j = AppSwcBcm_ARID_DEF.Lib_blIn_ek;

  /* Chart: '<S566>/LIB_PosPluseInit' incorporates:
   *  SubSystem: '<S574>/Lib_RiseEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S576>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_nr(AppSwcBcm_ARID_DEF.Lib_blIn_ek,
    AppSwcBcm_ARID_DEF.Lib_blInit_j, &AppSwcBcm_ARID_DEF.LogicalOperator_es,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_a);

  /* End of Outputs for SubSystem: '<S576>/Lib_RiseEdgeDetInit' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_es) {
    AppSwcBcm_ARID_DEF.Flg_e0 = true;
    AppSwcBcm_ARID_DEF.Cnt_l = 0U;
  }

  /* Logic: '<S566>/Logical Operator' */
  if (!AppSwcBcm_ARID_DEF.Lib_blIn_ek) {
    AppSwcBcm_ARID_DEF.Flg_e0 = false;
    AppSwcBcm_ARID_DEF.Cnt_l = 0U;
  }

  /* End of Logic: '<S566>/Logical Operator' */
  if (AppSwcBcm_ARID_DEF.Flg_e0) {
    /* Constant: '<S566>/Constant43' */
    if (AppSwcBcm_ARID_DEF.Cnt_l >= LampCtl_FlwrMeHomeTimValid_C) {
      AppSwcBcm_ARID_DEF.LIB_blOut_e = true;
      AppSwcBcm_ARID_DEF.Flg_e0 = false;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_l++;
      AppSwcBcm_ARID_DEF.LIB_blOut_e = false;
    }

    /* End of Constant: '<S566>/Constant43' */
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_e = false;
    AppSwcBcm_ARID_DEF.Cnt_l = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S566>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c();

  /* End of Outputs for SubSystem: '<S566>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S352>/Lib_SR1' */
  /* Switch: '<S569>/Switch' */
  if (rtb_RelationalOperator2_n5) {
    /* Switch: '<S569>/Switch' incorporates:
     *  Constant: '<S569>/Constant'
     */
    LampCtl_FlwrMeHomeSta = false;
  } else {
    /* Switch: '<S569>/Switch' incorporates:
     *  Logic: '<S569>/Logical Operator'
     *  UnitDelay: '<S569>/Unit Delay'
     */
    LampCtl_FlwrMeHomeSta = (AppSwcBcm_ARID_DEF.LogicalOperator_db ||
      LampCtl_FlwrMeHomeSta);
  }

  /* End of Switch: '<S569>/Switch' */
  /* End of Outputs for SubSystem: '<S352>/Lib_SR1' */

  /* MultiPortSwitch: '<S567>/Multiport Switch' */
  switch (LampCtl_FlwrMeHomeCtlFb) {
   case 0:
    /* MultiPortSwitch: '<S567>/Multiport Switch' incorporates:
     *  Constant: '<S567>/Constant4'
     */
    LampCtl_FlwrMeHomeTim = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S567>/Multiport Switch' incorporates:
     *  Constant: '<S567>/Constant'
     */
    LampCtl_FlwrMeHomeTim = 30U;
    break;

   case 2:
    /* MultiPortSwitch: '<S567>/Multiport Switch' incorporates:
     *  Constant: '<S567>/Constant1'
     */
    LampCtl_FlwrMeHomeTim = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S567>/Multiport Switch' incorporates:
     *  Constant: '<S567>/Constant2'
     */
    LampCtl_FlwrMeHomeTim = 90U;
    break;

   case 4:
    /* MultiPortSwitch: '<S567>/Multiport Switch' incorporates:
     *  Constant: '<S567>/Constant3'
     */
    LampCtl_FlwrMeHomeTim = 120U;
    break;
  }

  /* End of MultiPortSwitch: '<S567>/Multiport Switch' */

  /* RelationalOperator: '<S571>/Relational Operator1' incorporates:
   *  Constant: '<S570>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S570>/Relational Operator1'
   */
  rtb_RelationalOperator1_k0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* RelationalOperator: '<S571>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S570>/Relational Operator2'
   */
  rtb_RelationalOperator2_n5 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->OsUnlck;

  /* Chart: '<S570>/LIB_Tim' incorporates:
   *  Constant: '<S570>/Constant6'
   *  Logic: '<S570>/Logical Operator1'
   *  Logic: '<S570>/Logical Operator2'
   *  UnitDelay: '<S352>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse((!rtb_RelationalOperator2_n5) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fgr, LampCtl_WelcomeLampTimMax_C,
    &rtb_LIB_blOut_iq, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_p);

  /* Outputs for Atomic SubSystem: '<S570>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge_p();

  /* End of Outputs for SubSystem: '<S570>/Lib_ChangeEdge' */

  /* RelationalOperator: '<S571>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator2_n5 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->OsUnlck;

  /* RelationalOperator: '<S571>/Relational Operator' incorporates:
   *  Constant: '<S571>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LIB_blOut_e = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
                     ->SysPwrMode == 0);

  /* Chart: '<S571>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S571>/Constant1'
   *  Constant: '<S571>/Constant3'
   *  Logic: '<S571>/Logical Operator1'
   *  RelationalOperator: '<S571>/Relational Operator1'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1)
    && rtb_RelationalOperator2_n5 && rtb_LIB_blOut_e, LampCtl_OsUnlckDelayTim_C,
    &AppSwcBcm_ARID_DEF.LIB_blOut_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_p);

  /* Outputs for Atomic SubSystem: '<S352>/Lib_SR' */
  /* Switch: '<S568>/Switch' incorporates:
   *  Logic: '<S570>/Logical Operator'
   */
  if (rtb_LIB_blOut_iq || AppSwcBcm_ARID_DEF.RelationalOperator4_l ||
      rtb_RelationalOperator1_k0) {
    /* Switch: '<S568>/Switch' incorporates:
     *  Constant: '<S568>/Constant'
     */
    LampCtl_WelcomeLampSta = false;
  } else {
    /* Switch: '<S568>/Switch' incorporates:
     *  Constant: '<S571>/Constant4'
     *  Logic: '<S568>/Logical Operator'
     *  Logic: '<S571>/Logical Operator2'
     *  RelationalOperator: '<S571>/Relational Operator4'
     *  UnitDelay: '<S568>/Unit Delay'
     */
    LampCtl_WelcomeLampSta = ((AppSwcBcm_ARID_DEF.LIB_blOut_b &&
      (LampCtl_LightIntstSta == 2)) || LampCtl_WelcomeLampSta);
  }

  /* End of Switch: '<S568>/Switch' */
  /* End of Outputs for SubSystem: '<S352>/Lib_SR' */

  /* Update for UnitDelay: '<S352>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_h = LampCtl_FlwrMeHomeSta;

  /* Update for UnitDelay: '<S352>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = LampCtl_FlwrMeHomeTim;

  /* Update for Delay: '<S567>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_f = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_m = LampCtl_FlwrMeHomeCtlFb;

  /* Update for UnitDelay: '<S352>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fgr = LampCtl_WelcomeLampSta;
}

/* System initialize for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S241>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/ADASLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/AutoLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/BackLampCtl' */
  AppSwcBcm_BackLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/BackLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/BoxLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/DomeLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/LampDelayCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/LowBeamCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/PosLampCtl' */
  AppSwcBcm_PosLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/PosLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/SignalProcess' */
  AppSwcBcm_SignalProcess_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/SignalProcess' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/TurnIndcrCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S241>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S241>/WelcomeLampCtl' */
}

/* Outputs for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl(void)
{
  boolean rtb_DataTypeConversion3_i;

  /* Outputs for Atomic SubSystem: '<S241>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl();

  /* End of Outputs for SubSystem: '<S241>/ADASLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd3' */
  /* Switch: '<S340>/Switch1' incorporates:
   *  Constant: '<S241>/Constant5'
   */
  if (LampCtl_J420BSDRightCtlOvrdFlg_C) {
    /* Switch: '<S340>/Switch1' incorporates:
     *  Constant: '<S241>/Constant6'
     */
    LampCtl_J420BSDRightCtl = LampCtl_J420BSDRightCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion3' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BSDRightCtlFlg != 0);

    /* Switch: '<S340>/Switch1' incorporates:
     *  Switch: '<S340>/Switch2'
     */
    LampCtl_J420BSDRightCtl = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl);
  }

  /* End of Switch: '<S340>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd4' */
  /* Switch: '<S341>/Switch1' incorporates:
   *  Constant: '<S241>/Constant7'
   */
  if (LampCtl_J422BSDLeftCtlOvrdFlg_C) {
    /* Switch: '<S341>/Switch1' incorporates:
     *  Constant: '<S241>/Constant8'
     */
    LampCtl_J422BSDLeftCtl = LampCtl_J422BSDLeftCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion4' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BSDLeftCtlFlg != 0);

    /* Switch: '<S341>/Switch1' incorporates:
     *  Switch: '<S341>/Switch2'
     */
    LampCtl_J422BSDLeftCtl = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl);
  }

  /* End of Switch: '<S341>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd4' */

  /* Outputs for Atomic SubSystem: '<S241>/SignalProcess' */
  AppSwcBcm_SignalProcess();

  /* End of Outputs for SubSystem: '<S241>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S241>/LightIntstDet' */
  AppSwcBcm_LightIntstDet();

  /* End of Outputs for SubSystem: '<S241>/LightIntstDet' */

  /* Outputs for Atomic SubSystem: '<S241>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl();

  /* End of Outputs for SubSystem: '<S241>/AutoLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/KnobBeamDig' */
  AppSwcBcm_KnobBeamDig();

  /* End of Outputs for SubSystem: '<S241>/KnobBeamDig' */

  /* Outputs for Atomic SubSystem: '<S241>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl();

  /* End of Outputs for SubSystem: '<S241>/LampDelayCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/PosLampCtl' */
  AppSwcBcm_PosLampCtl();

  /* End of Outputs for SubSystem: '<S241>/PosLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd' */
  /* Switch: '<S332>/Switch1' incorporates:
   *  Constant: '<S241>/Constant18'
   *  Constant: '<S241>/Constant19'
   *  Switch: '<S332>/Switch2'
   */
  if (LampCtl_PosLampStaOvrdFlg_C) {
    LampCtl_PosLampSta = LampCtl_PosLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->PosLampCtlFlg != 0);
    LampCtl_PosLampSta = (rtb_DataTypeConversion3_i ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_cs);
  }

  /* End of Switch: '<S332>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd' */

  /* Outputs for Atomic SubSystem: '<S241>/PassLampFunc' */
  AppSwcBcm_PassLampFunc();

  /* End of Outputs for SubSystem: '<S241>/PassLampFunc' */

  /* Outputs for Atomic SubSystem: '<S241>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl();

  /* End of Outputs for SubSystem: '<S241>/LowBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd5' */
  /* Switch: '<S342>/Switch1' incorporates:
   *  Constant: '<S241>/Constant10'
   *  Constant: '<S241>/Constant9'
   *  Switch: '<S342>/Switch2'
   */
  if (LampCtl_LowBeamStaOvrdFlg_C) {
    LampCtl_LowBeamSta = LampCtl_LowBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->LowBeamCtlFlg != 0);
    LampCtl_LowBeamSta = (rtb_DataTypeConversion3_i ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_c5);
  }

  /* End of Switch: '<S342>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S241>/BackLampCtl' */
  AppSwcBcm_BackLampCtl();

  /* End of Outputs for SubSystem: '<S241>/BackLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd14' */
  /* Switch: '<S338>/Switch1' incorporates:
   *  Constant: '<S241>/Constant30'
   */
  if (LampCtl_J408BackLampPWMOvrdFlg_C) {
    /* Switch: '<S338>/Switch1' incorporates:
     *  Constant: '<S241>/Constant29'
     */
    LampCtl_J408BackLampPWM = LampCtl_J408BackLampPWMOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion14' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BackLampCtlFlg != 0);

    /* Switch: '<S338>/Switch2' */
    if (rtb_DataTypeConversion3_i) {
      /* Switch: '<S338>/Switch1' incorporates:
       *  Constant: '<S241>/Constant32'
       */
      LampCtl_J408BackLampPWM = 100U;
    } else {
      /* Switch: '<S338>/Switch1' */
      LampCtl_J408BackLampPWM = AppSwcBcm_ARID_DEF.Switch_k;
    }

    /* End of Switch: '<S338>/Switch2' */
  }

  /* End of Switch: '<S338>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd14' */

  /* Outputs for Atomic SubSystem: '<S241>/FogLampRCtl' */
  AppSwcBcm_FogLampRCtl();

  /* End of Outputs for SubSystem: '<S241>/FogLampRCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd6' */
  /* Switch: '<S343>/Switch1' incorporates:
   *  Constant: '<S241>/Constant12'
   */
  if (LampCtl_FogLampRStaOvrdFlg_C) {
    /* Switch: '<S343>/Switch1' incorporates:
     *  Constant: '<S241>/Constant11'
     */
    LampCtl_FogLampRSta = LampCtl_FogLampRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion6' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->FogLampRCtlFlg != 0);

    /* Switch: '<S343>/Switch1' incorporates:
     *  Switch: '<S343>/Switch2'
     */
    LampCtl_FogLampRSta = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_f);
  }

  /* End of Switch: '<S343>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd6' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd7' */
  /* Switch: '<S344>/Switch1' incorporates:
   *  Constant: '<S241>/Constant14'
   */
  if (LampCtl_FogLampFStaOvrdFlg_C) {
    /* Switch: '<S344>/Switch1' incorporates:
     *  Constant: '<S241>/Constant13'
     */
    LampCtl_FogLampFSta = LampCtl_FogLampFStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion7' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->FogLampFCtlFlg != 0);

    /* Switch: '<S344>/Switch1' incorporates:
     *  Switch: '<S344>/Switch2'
     */
    LampCtl_FogLampFSta = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_l);
  }

  /* End of Switch: '<S344>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd7' */

  /* Outputs for Atomic SubSystem: '<S241>/HiBeamCtl' */
  AppSwcBcm_HiBeamCtl();

  /* End of Outputs for SubSystem: '<S241>/HiBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd9' */
  /* Switch: '<S346>/Switch1' incorporates:
   *  Constant: '<S241>/Constant20'
   */
  if (LampCtl_HiBeamStaOvrdFlg_C) {
    /* Switch: '<S346>/Switch1' incorporates:
     *  Constant: '<S241>/Constant17'
     */
    LampCtl_HiBeamSta = LampCtl_HiBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion9' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->HiBeamCtlFlg != 0);

    /* Switch: '<S346>/Switch1' incorporates:
     *  Switch: '<S346>/Switch2'
     */
    LampCtl_HiBeamSta = (rtb_DataTypeConversion3_i ||
                         AppSwcBcm_ARID_DEF.LogicalOperator_eq2);
  }

  /* End of Switch: '<S346>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd9' */

  /* Outputs for Atomic SubSystem: '<S241>/DayRunLampCtl' */
  AppSwcBcm_DayRunLampCtl();

  /* End of Outputs for SubSystem: '<S241>/DayRunLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd1' */
  /* Switch: '<S333>/Switch1' incorporates:
   *  Constant: '<S241>/Constant1'
   */
  if (LampCtl_DayRunLightStaOvrdFlg_C) {
    /* Switch: '<S333>/Switch1' incorporates:
     *  Constant: '<S241>/Constant2'
     */
    LampCtl_DayRunLightSta = LampCtl_DayRunLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->DayRunLightCtlFlg != 0);

    /* Switch: '<S333>/Switch1' incorporates:
     *  Switch: '<S333>/Switch2'
     *  UnitDelay: '<S372>/Unit Delay'
     */
    LampCtl_DayRunLightSta = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cg);
  }

  /* End of Switch: '<S333>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S241>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl();

  /* End of Outputs for SubSystem: '<S241>/BoxLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd13' */
  /* Switch: '<S337>/Switch1' incorporates:
   *  Constant: '<S241>/Constant28'
   */
  if (LampCtl_J449BoxLampOvrdFlg_C) {
    /* Switch: '<S337>/Switch1' incorporates:
     *  Constant: '<S241>/Constant27'
     */
    LampCtl_J449BoxLamp = LampCtl_J449BoxLampOvrdVal_C;
  } else {
    /* Switch: '<S337>/Switch1' incorporates:
     *  Switch: '<S337>/Switch2'
     *  UnitDelay: '<S322>/Unit Delay'
     */
    LampCtl_J449BoxLamp = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nr;
  }

  /* End of Switch: '<S337>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd13' */

  /* Outputs for Atomic SubSystem: '<S241>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl();

  /* End of Outputs for SubSystem: '<S241>/TurnIndcrCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl();

  /* End of Outputs for SubSystem: '<S241>/WelcomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd11' */
  /* Switch: '<S335>/Switch1' incorporates:
   *  Constant: '<S241>/Constant23'
   */
  if (LampCtl_TurnIndcrRStaOvrdFlg_C) {
    /* Switch: '<S335>/Switch1' incorporates:
     *  Constant: '<S241>/Constant24'
     */
    LampCtl_TurnIndcrRSta = LampCtl_TurnIndcrRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion11' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->TurnIndcrRCtlFlg != 0);

    /* Switch: '<S335>/Switch1' incorporates:
     *  Switch: '<S335>/Switch2'
     */
    LampCtl_TurnIndcrRSta = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.LIB_blOut_p);
  }

  /* End of Switch: '<S335>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd11' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd12' */
  /* Switch: '<S336>/Switch1' incorporates:
   *  Constant: '<S241>/Constant25'
   */
  if (LampCtl_TurnIndcrLStaOvrdFlg_C) {
    /* Switch: '<S336>/Switch1' incorporates:
     *  Constant: '<S241>/Constant26'
     */
    LampCtl_TurnIndcrLSta = LampCtl_TurnIndcrLStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion12' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->TurnIndcrLCtlFlg != 0);

    /* Switch: '<S336>/Switch1' incorporates:
     *  Switch: '<S336>/Switch2'
     */
    LampCtl_TurnIndcrLSta = (rtb_DataTypeConversion3_i ||
      AppSwcBcm_ARID_DEF.LIB_blOut_i);
  }

  /* End of Switch: '<S336>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd12' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd2' */
  /* Switch: '<S339>/Switch1' incorporates:
   *  Constant: '<S241>/Constant3'
   */
  if (LampCtl_BrakeLightStaOvrdFlg_C) {
    /* Switch: '<S339>/Switch1' incorporates:
     *  Constant: '<S241>/Constant4'
     */
    LampCtl_BrakeLightSta = LampCtl_BrakeLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BrakeLightCtlFlg != 0);

    /* Switch: '<S339>/Switch2' */
    if (rtb_DataTypeConversion3_i) {
      /* Switch: '<S339>/Switch1' incorporates:
       *  Switch: '<S339>/Switch2'
       */
      LampCtl_BrakeLightSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S241>/BrakeLampCtl' */
      AppSwcBcm_BrakeLampCtl();

      /* End of Outputs for SubSystem: '<S241>/BrakeLampCtl' */

      /* Switch: '<S339>/Switch1' incorporates:
       *  Switch: '<S339>/Switch2'
       */
      LampCtl_BrakeLightSta = AppSwcBcm_ARID_DEF.LogicalOperator_ez;
    }

    /* End of Switch: '<S339>/Switch2' */
  }

  /* End of Switch: '<S339>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S241>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl();

  /* End of Outputs for SubSystem: '<S241>/DomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd10' */
  /* Switch: '<S334>/Switch1' incorporates:
   *  Constant: '<S241>/Constant22'
   */
  if (LampCtl_DomeLampPwmDutyOvrdFlg_C) {
    /* Switch: '<S334>/Switch1' incorporates:
     *  Constant: '<S241>/Constant21'
     */
    LampCtl_DomeLampPwmDuty = LampCtl_DomeLampPwmDutyOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion10' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->DomeLampCtlFlg != 0);

    /* Switch: '<S334>/Switch2' */
    if (rtb_DataTypeConversion3_i) {
      /* Switch: '<S334>/Switch1' incorporates:
       *  Constant: '<S241>/Constant31'
       */
      LampCtl_DomeLampPwmDuty = 100U;
    } else {
      /* Switch: '<S334>/Switch1' */
      LampCtl_DomeLampPwmDuty = AppSwcBcm_ARID_DEF.DataTypeConversion;
    }

    /* End of Switch: '<S334>/Switch2' */
  }

  /* End of Switch: '<S334>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd10' */

  /* Outputs for Atomic SubSystem: '<S241>/Ovrd8' */
  /* Switch: '<S345>/Switch1' incorporates:
   *  Constant: '<S241>/Constant16'
   */
  if (LampCtl_ReverseLampStaOvrdFlg_C) {
    /* Switch: '<S345>/Switch1' incorporates:
     *  Constant: '<S241>/Constant15'
     */
    LampCtl_ReverseLampSta = LampCtl_ReverseLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S241>/Data Type Conversion8' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->ReverseLampCtlFlg != 0);

    /* Switch: '<S345>/Switch2' */
    if (rtb_DataTypeConversion3_i) {
      /* Switch: '<S345>/Switch1' incorporates:
       *  Switch: '<S345>/Switch2'
       */
      LampCtl_ReverseLampSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S241>/ReverseLampCtl' */
      AppSwcBcm_ReverseLampCtl();

      /* End of Outputs for SubSystem: '<S241>/ReverseLampCtl' */

      /* Switch: '<S345>/Switch1' incorporates:
       *  Switch: '<S345>/Switch2'
       */
      LampCtl_ReverseLampSta = AppSwcBcm_ARID_DEF.LogicalOperator_gx;
    }

    /* End of Switch: '<S345>/Switch2' */
  }

  /* End of Switch: '<S345>/Switch1' */
  /* End of Outputs for SubSystem: '<S241>/Ovrd8' */
}

/* Update for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl_Update(void)
{
  /* Update for UnitDelay: '<S241>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pz = LampCtl_WelcomeLampSta;

  /* Update for UnitDelay: '<S241>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e = LampCtl_FlwrMeHomeSta;

  /* Update for Atomic SubSystem: '<S241>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Update();

  /* End of Update for SubSystem: '<S241>/LampDelayCtl' */

  /* Update for Atomic SubSystem: '<S241>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Update();

  /* End of Update for SubSystem: '<S241>/BoxLampCtl' */

  /* Update for Atomic SubSystem: '<S241>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Update();

  /* End of Update for SubSystem: '<S241>/DomeLampCtl' */
}

/*
 * System initialize for atomic system:
 *    '<S583>/LIB_TPD1'
 *    '<S583>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg)
{
  *rty_LIB_u8ErrFlg = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S583>/LIB_TPD1'
 *    '<S583>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg)
{
  boolean guard1 = false;

  /* Chart: '<S583>/LIB_TPD1' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blAllowRecov;

  /* Outputs for Function Call SubSystem: '<S596>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator_b,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S596>/Lib_RiseEdgeDet' */

  /* Chart: '<S583>/LIB_TPD1' */
  guard1 = false;
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator_b) {
    guard1 = true;
  } else {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn_n = rtu_LIB_blAllowRecov1;

    /* Outputs for Function Call SubSystem: '<S596>/Lib_RiseEdgeDet1' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm__ARID_DEF_arg->Lib_blIn_n,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet1);

    /* End of Outputs for SubSystem: '<S596>/Lib_RiseEdgeDet1' */
    if (AppSwcBcm__ARID_DEF_arg->LogicalOperator) {
      guard1 = true;
    }
  }

  if (guard1) {
    *rty_LIB_u8ErrFlg = 0U;
    AppSwcBcm__ARID_DEF_arg->cnt_defect = 0U;
    AppSwcBcm__ARID_DEF_arg->cnt_heal = 0U;
  }

  if (rtu_LIB_blIn) {
    if ((AppSwcBcm__ARID_DEF_arg->cnt_defect >= rtu_LIB_u16tiToDef) &&
        (rtu_LIB_u16tiToDef != 0xFFFF)) {
      *rty_LIB_u8ErrFlg = 1U;
    } else {
      AppSwcBcm__ARID_DEF_arg->cnt_defect++;
      AppSwcBcm__ARID_DEF_arg->cnt_heal = rtu_LIB_u16tiToOk;
    }
  } else {
    AppSwcBcm__ARID_DEF_arg->cnt_defect = 0U;
    if (AppSwcBcm__ARID_DEF_arg->cnt_heal == 0) {
      *rty_LIB_u8ErrFlg = 0U;
    } else if ((*rty_LIB_u8ErrFlg == 0) && (rtu_LIB_u16tiToOk != 0xFFFF)) {
      AppSwcBcm__ARID_DEF_arg->cnt_heal--;
    }
  }
}

/* System initialize for atomic system: '<S242>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt_Init(void)
{
  /* SystemInitialize for Chart: '<S583>/LIB_TPD1' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_k);

  /* SystemInitialize for Chart: '<S583>/LIB_TPD2' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg);
}

/* Output and update for atomic system: '<S242>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator3_da;

  /* Logic: '<S583>/Logical Operator' incorporates:
   *  UnitDelay: '<S242>/Unit Delay'
   *  UnitDelay: '<S242>/Unit Delay1'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cw ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i);

  /* RelationalOperator: '<S583>/Relational Operator3' incorporates:
   *  Constant: '<S583>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_da = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S583>/LIB_TPD2' incorporates:
   *  Constant: '<S583>/Constant1'
   *  Constant: '<S583>/Constant2'
   *  Logic: '<S583>/Logical Operator1'
   *  RelationalOperator: '<S583>/Relational Operator'
   *  RelationalOperator: '<S583>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(rtb_LogicalOperator && (!WiperCtl_WiperParkPosSw),
                     WiperCtl_LockedRotorTimDef_C, WiperCtl_LockedRotorTimOk_C,
                     WiperCtl_WiperOffSw, rtb_RelationalOperator3_da,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD2);

  /* Chart: '<S583>/LIB_TPD1' incorporates:
   *  Constant: '<S583>/Constant4'
   *  Constant: '<S583>/Constant5'
   *  Logic: '<S583>/Logical Operator3'
   *  RelationalOperator: '<S583>/Relational Operator1'
   *  RelationalOperator: '<S583>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(WiperCtl_WiperParkPosSw && rtb_LogicalOperator,
                     WiperCtl_LockedRotorTimParkDef_C,
                     WiperCtl_LockedRotorTimParkOk_C, WiperCtl_WiperOffSw,
                     rtb_RelationalOperator3_da,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_k,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD1);

  /* Logic: '<S583>/Logical Operator2' */
  WiperCtl_LockedRotorProtSta = ((AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_k != 0) ||
    (AppSwcBcm_ARID_DEF.LIB_u8ErrFlg != 0));
}

/* Output and update for atomic system: '<S242>/SignalProcess' */
static void AppSwcBcm_SignalProcess_m(void)
{
  uint16 rtb_y;
  uint8 rtb_Switch5_d;
  boolean rtb_Switch1;

  /* Outputs for Atomic SubSystem: '<S587>/Bit Shift5' */
  /* Constant: '<S587>/Constant59' */
  rtb_y = AppSwcBcm_BitShift3(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S587>/Bit Shift5' */

  /* Switch: '<S587>/Switch5' incorporates:
   *  RelationalOperator: '<S587>/Relational Operator'
   *  S-Function (sfix_bitop): '<S587>/Bitwise AND5'
   *  Switch: '<S587>/Switch'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S587>/Switch5' incorporates:
     *  Constant: '<S587>/Constant60'
     */
    rtb_Switch5_d = WiperCtl_WiperSwVal_C;
  } else if (SCS_WiprSwtStVD) {
    /* Switch: '<S587>/Switch' incorporates:
     *  Switch: '<S587>/Switch5'
     */
    rtb_Switch5_d = SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S587>/Switch5' incorporates:
     *  Constant: '<S587>/Constant23'
     *  Switch: '<S587>/Switch'
     */
    rtb_Switch5_d = 0U;
  }

  /* End of Switch: '<S587>/Switch5' */

  /* Chart: '<S587>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S587>/Constant14'
   *  Constant: '<S587>/Constant46'
   *  Constant: '<S587>/Constant47'
   *  Constant: '<S587>/Constant49'
   *  RelationalOperator: '<S587>/Relational Operator9'
   */
  if (rtb_Switch5_d == 4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_g >= (float32)WiperCtl_MistTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_MistTimValid_C != 0xFFFF)) {
      WiperCtl_WiperMistSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_g++;
      AppSwcBcm_ARID_DEF.cnt_heal_df = (uint16)((float32)
        WiperCtl_MistTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_g = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_df == 0) {
      WiperCtl_WiperMistSw = false;
    } else if (WiperCtl_MistTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_df--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms' */

  /* Chart: '<S587>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S587>/Constant1'
   *  Constant: '<S587>/Constant3'
   *  Constant: '<S587>/Constant4'
   *  Constant: '<S587>/Constant5'
   *  RelationalOperator: '<S587>/Relational Operator1'
   */
  if (rtb_Switch5_d == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_m2 >= (float32)WiperCtl_OffTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_OffTimValid_C != 0xFFFF)) {
      WiperCtl_WiperOffSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m2++;
      AppSwcBcm_ARID_DEF.cnt_heal_mz = (uint16)((float32)
        WiperCtl_OffTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mz == 0) {
      WiperCtl_WiperOffSw = false;
    } else if (WiperCtl_OffTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mz--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms1' */

  /* Chart: '<S587>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S587>/Constant10'
   *  Constant: '<S587>/Constant2'
   *  Constant: '<S587>/Constant8'
   *  Constant: '<S587>/Constant9'
   *  RelationalOperator: '<S587>/Relational Operator2'
   */
  if (rtb_Switch5_d == 1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_j >= (float32)WiperCtl_InrTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_InrTimValid_C != 0xFFFF)) {
      WiperCtl_WiperInrSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j++;
      AppSwcBcm_ARID_DEF.cnt_heal_ok = (uint16)((float32)
        WiperCtl_InrTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ok == 0) {
      WiperCtl_WiperInrSw = false;
    } else if (WiperCtl_InrTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ok--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms2' */

  /* Chart: '<S587>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S587>/Constant11'
   *  Constant: '<S587>/Constant16'
   *  Constant: '<S587>/Constant17'
   *  Constant: '<S587>/Constant6'
   *  RelationalOperator: '<S587>/Relational Operator3'
   */
  if (rtb_Switch5_d == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_p5 >= (float32)WiperCtl_LowSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_LowSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperLowSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_p5++;
      AppSwcBcm_ARID_DEF.cnt_heal_a4 = (uint16)((float32)
        WiperCtl_LowSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_p5 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a4 == 0) {
      WiperCtl_WiperLowSpdSw = false;
    } else if (WiperCtl_LowSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a4--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms3' */

  /* Chart: '<S587>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S587>/Constant18'
   *  Constant: '<S587>/Constant21'
   *  Constant: '<S587>/Constant22'
   *  Constant: '<S587>/Constant7'
   *  RelationalOperator: '<S587>/Relational Operator4'
   */
  if (rtb_Switch5_d == 3) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_n >= (float32)WiperCtl_HiSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_HiSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperHiSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_n++;
      AppSwcBcm_ARID_DEF.cnt_heal_ar = (uint16)((float32)
        WiperCtl_HiSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_n = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ar == 0) {
      WiperCtl_WiperHiSpdSw = false;
    } else if (WiperCtl_HiSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ar--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S587>/Bit Shift1' */
  /* Constant: '<S587>/Constant28' */
  rtb_y = AppSwcBcm_BitShift4(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S587>/Bit Shift1' */

  /* Switch: '<S587>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S587>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S587>/Switch1' incorporates:
     *  Constant: '<S587>/Constant29'
     */
    rtb_Switch1 = WiperCtl_WashVal_C;
  } else {
    /* Switch: '<S587>/Switch1' incorporates:
     *  RelationalOperator: '<S587>/Relational Operator5'
     *  Switch: '<S587>/Switch3'
     */
    rtb_Switch1 = (SCS_FrntWshrSwtStVD && SCS_FrntWshrSwtSt);
  }

  /* End of Switch: '<S587>/Switch1' */

  /* Chart: '<S587>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S587>/Constant25'
   *  Constant: '<S587>/Constant26'
   *  Constant: '<S587>/Constant27'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d >= (float32)WiperCtl_WashTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashTimValid_C != 0xFFFF)) {
      WiperCtl_WashSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d++;
      AppSwcBcm_ARID_DEF.cnt_heal_d4 = (uint16)((float32)
        WiperCtl_WashTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d4 == 0) {
      WiperCtl_WashSw = false;
    } else if (WiperCtl_WashTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_d4--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S587>/Bit Shift2' */
  /* Constant: '<S587>/Constant35' */
  rtb_y = AppSwcBcm_BitShift7(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S587>/Bit Shift2' */

  /* Switch: '<S587>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S587>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S587>/Switch2' incorporates:
     *  Constant: '<S587>/Constant36'
     */
    rtb_Switch1 = WiperCtl_WiperParkPosVal_C;
  } else {
    /* Switch: '<S587>/Switch2' incorporates:
     *  DataTypeConversion: '<S587>/Data Type Conversion2'
     */
    rtb_Switch1 = (BSW_J334WiperParkPos != 0);
  }

  /* End of Switch: '<S587>/Switch2' */

  /* Chart: '<S587>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S587>/Constant32'
   *  Constant: '<S587>/Constant33'
   *  Constant: '<S587>/Constant34'
   *  Logic: '<S587>/Logical Operator5'
   */
  if (!rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_od >= (float32)
         WiperCtl_WiperParkPosTimValid_C / (WiperCtl_Ts_C * 100.0F)) &&
        (WiperCtl_WiperParkPosTimValid_C != 0xFFFF)) {
      WiperCtl_WiperParkPosSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_od++;
      AppSwcBcm_ARID_DEF.cnt_heal_k = (uint16)((float32)
        WiperCtl_WiperPosTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_od = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k == 0) {
      WiperCtl_WiperParkPosSw = false;
    } else if (WiperCtl_WiperPosTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k--;
    }
  }

  /* End of Chart: '<S587>/LIB_TPD_10ms6' */
}

/* System initialize for atomic system: '<S242>/WashCtl' */
static void AppSwcBcm_WashCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S588>/LIB_Tim' */
  AppSwcBcm_LIB_NegPluse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_l);
}

/* Output and update for atomic system: '<S242>/WashCtl' */
static void AppSwcBcm_WashCtl(void)
{
  boolean rtb_RelationalOperator1_c;

  /* RelationalOperator: '<S588>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Chart: '<S588>/LIB_Tim' incorporates:
   *  Constant: '<S588>/Constant'
   *  Logic: '<S588>/Logical Operator'
   *  RelationalOperator: '<S588>/Relational Operator'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator1_c && WiperCtl_WashSw,
    WiperCtl_WashMaxTim_C, &AppSwcBcm_ARID_DEF.LIB_blOut_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim);

  /* Chart: '<S588>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S588>/Constant3'
   *  Constant: '<S588>/Constant34'
   *  Constant: '<S588>/Constant4'
   *  Logic: '<S588>/Logical Operator1'
   *  Logic: '<S588>/Logical Operator2'
   *  RelationalOperator: '<S588>/Relational Operator2'
   *  RelationalOperator: '<S588>/Relational Operator3'
   *  RelationalOperator: '<S588>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_l && (WiperCtl_WiperInrSta ||
       WiperCtl_WiperOffSta) && (!AppSwcBcm_ARID_DEF.UnitDelay8)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_f >= (float32)WiperCtl_WashMinTim_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashMinTim_C != 0xFFFF)) {
      WiperCtl_WashWiperSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_f++;
      AppSwcBcm_ARID_DEF.cnt_heal_f = (uint16)(1.0F / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_f = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_f == 0) {
      WiperCtl_WashWiperSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_f--;
    }
  }

  /* End of Chart: '<S588>/LIB_TPD_10ms6' */
}

/*
 * System initialize for function-call system:
 *    '<S621>/Wash.Lib_RiseEdgeDetInit'
 *    '<S621>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S628>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S621>/Wash.Lib_RiseEdgeDetInit'
 *    '<S621>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S628>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S628>/Logical Operator' incorporates:
   *  Delay: '<S628>/Delay'
   *  Logic: '<S628>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S628>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S589>/Chart' */
static void AppSwcBcm_enter_internal_Inr(void)
{
  WiperCtl_WiperSta = 4U;
  AppSwcBcm_ARID_DEF.cnt = 0U;
  if (WiperCtl_WiperInrSta) {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    if ((WiperCtl_InrTim + AppSwcBcm_ARID_DEF.cnt2) - 1 > 0) {
      AppSwcBcm_ARID_DEF.cnt = 1U;
    }
  }
}

/* Function for Chart: '<S589>/Chart' */
static void AppSwcBcm_HiSpdFunc(void)
{
  AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
  AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = true;
  WiperCtl_WiperSta = 3U;
}

/* Function for Chart: '<S589>/Chart' */
static void AppSwcBcm_Nrm(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator1_aa;
  if (WiperCtl_WashWiperSta) {
    if (AppSwcBcm_ARID_DEF.is_Nrm == AppSwcBcm_IN_Inr) {
      AppSwcBcm_ARID_DEF.cnt = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_a;
    } else {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_a;
    }

    AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Wash;
    WiperCtl_WiperSta = 5U;
    AppSwcBcm_ARID_DEF.after_cnt = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
    if (WiperCtl_WiperMistSta || WiperCtl_WiperHiSpdSta ||
        WiperCtl_WiperLowSpdSta) {
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_fbi = WiperCtl_WiperInrSta;
      AppSwcBcm_ARID_DEF.Lib_blInit_e = WiperCtl_WiperInrSta;

      /* Outputs for Function Call SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_fbi,
        AppSwcBcm_ARID_DEF.Lib_blInit_e, &AppSwcBcm_ARID_DEF.LogicalOperator_el,
        &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
        AppSwcBcm_ARID_DEF.LogicalOperator_el;
    }
  } else if (WiperCtl_WiperMaintSta) {
    if (AppSwcBcm_ARID_DEF.is_Nrm == AppSwcBcm_IN_Inr) {
      AppSwcBcm_ARID_DEF.cnt = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_a;
    } else {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_a;
    }

    AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Maint;
    WiperCtl_WiperSta = 6U;
    AppSwcBcm_ARID_DEF.Cnt_h4 = 0U;
    if (WiperCtl_MaintWiperRunTim_C <= 0) {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;

      /* WiperCtl_MaintStaComp=1; */
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      AppSwcBcm_ARID_DEF.Cnt_h4 = 1U;

      /* WiperCtl_MaintStaComp=0; */
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_HiSpd:
      if (WiperCtl_WiperLowSpdSta || (!WiperCtl_WiperHiSpdSta) ||
          WiperCtl_WiperOffSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;

        /* UnitDelay: '<S242>/Unit Delay2' */
        /* (WiperCtl_WiperHiSpdSta==0||WiperCtl_WiperOffSta==1)&&WiperCtl_WiperParkPosSta==1||... */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else {
        AppSwcBcm_HiSpdFunc();
      }
      break;

     case AppSwcBcm_IN_Inr:
      if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.cnt = 0U;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else {
        rtb_LogicalOperator1_aa = !WiperCtl_WiperInrSta;

        /* UnitDelay: '<S242>/Unit Delay2' incorporates:
         *  Delay: '<S626>/Delay'
         *  Logic: '<S626>/Logical Operator'
         */
        if (((rtb_LogicalOperator1_aa || WiperCtl_WiperOffSta) &&
             WiperCtl_WiperParkPosSw) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)
        {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
          WiperCtl_WiperSta = 0U;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
          if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2)
              && (!WiperCtl_WiperParkPosSw) &&
              (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)) {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
          } else {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
          }
        } else if (WiperCtl_WiperHiSpdSta && rtb_LogicalOperator1_aa) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
        } else if (rtb_LogicalOperator1_aa && WiperCtl_WiperLowSpdSta) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
        } else {
          if (WiperCtl_InrTimChg) {
            AppSwcBcm_ARID_DEF.cnt = 0U;
          }

          if (WiperCtl_WiperInrSta) {
            if (AppSwcBcm_ARID_DEF.cnt == 0) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
              AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
            } else {
              /* Outputs for Function Call SubSystem: '<S621>/Nrm.Inr.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.icLoad_m0) {
                /* Delay: '<S626>/Delay' */
                AppSwcBcm_ARID_DEF.Delay_DSTATE_n = WiperCtl_WiperParkPosSw;
              }

              /* Logic: '<S626>/Logical Operator1' incorporates:
               *  Delay: '<S626>/Delay'
               */
              rtb_LogicalOperator1_aa = !AppSwcBcm_ARID_DEF.Delay_DSTATE_n;

              /* Update for Delay: '<S626>/Delay' */
              AppSwcBcm_ARID_DEF.icLoad_m0 = false;
              AppSwcBcm_ARID_DEF.Delay_DSTATE_n = WiperCtl_WiperParkPosSw;
              if (WiperCtl_WiperParkPosSw && rtb_LogicalOperator1_aa &&
                  (AppSwcBcm_ARID_DEF.cnt > 10)) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
                AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
                AppSwcBcm_ARID_DEF.cnt2 = AppSwcBcm_ARID_DEF.cnt;
              }

              /* End of Outputs for SubSystem: '<S621>/Nrm.Inr.Lib_RiseEdgeDetInit' */
            }

            if (AppSwcBcm_ARID_DEF.cnt >= (WiperCtl_InrTim +
                 AppSwcBcm_ARID_DEF.cnt2) - 1) {
              AppSwcBcm_ARID_DEF.cnt = 0U;
            } else {
              tmp = AppSwcBcm_ARID_DEF.cnt + 1;
              if (AppSwcBcm_ARID_DEF.cnt + 1 > 65535) {
                tmp = 65535;
              }

              AppSwcBcm_ARID_DEF.cnt = (uint16)tmp;
            }
          }
        }
      }
      break;

     case AppSwcBcm_IN_LowSpd:
      /* UnitDelay: '<S242>/Unit Delay2' */
      if (((((!WiperCtl_WiperLowSpdSta) && (!WiperCtl_WiperHiSpdSta)) ||
            WiperCtl_WiperOffSta) && WiperCtl_WiperParkPosSw) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        }
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        WiperCtl_WiperSta = 2U;
      }
      break;

     case AppSwcBcm_IN_Mist:
      /* UnitDelay: '<S242>/Unit Delay2' */
      if ((((!WiperCtl_WiperMistSta) || WiperCtl_WiperOffSta) &&
           WiperCtl_WiperParkPosSw) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        }
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else if (WiperCtl_WiperLowSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        WiperCtl_WiperSta = 1U;
      }
      break;

     default:
      /* case IN_Off: */
      if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else if (WiperCtl_WiperLowSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode ==
                  2) && (!WiperCtl_WiperParkPosSw) &&
                 (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S242>/WiperDrv' */
static void AppSwcBcm_WiperDrv_Init(void)
{
  /* SystemInitialize for Chart: '<S589>/Chart' incorporates:
   *  SubSystem: '<S621>/Nrm.Inr.Lib_RiseEdgeDetInit'
   */
  /* InitializeConditions for Delay: '<S626>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m0 = true;

  /* SystemInitialize for Chart: '<S589>/Chart' incorporates:
   *  SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S589>/Chart' incorporates:
   *  SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);
}

/* Output and update for atomic system: '<S242>/WiperDrv' */
static void AppSwcBcm_WiperDrv(void)
{
  sint32 tmp;

  /* Chart: '<S589>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S242>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_WiperCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_WiperCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Nrm_k;
    AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
    WiperCtl_WiperSta = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) && (
         !WiperCtl_WiperParkPosSw) && (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o))
    {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib) {
     case AppSwcBcm_IN_Maint:
      if ((!WiperCtl_WiperMaintSta) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o) {
        AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Nrm_k;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        }
      } else if (AppSwcBcm_ARID_DEF.Cnt_h4 >= WiperCtl_MaintWiperRunTim_C) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;

        /* WiperCtl_MaintStaComp=1; */
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        AppSwcBcm_ARID_DEF.Cnt_h4++;

        /* WiperCtl_MaintStaComp=0; */
      }
      break;

     case AppSwcBcm_IN_Nrm_k:
      AppSwcBcm_Nrm();
      break;

     default:
      /* case IN_Wash: */
      if (((!WiperCtl_WashWiperSta) && AppSwcBcm_ARID_DEF.WiperCtl_WashComp) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o ||
          (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) &&
           WiperCtl_WiperParkPosSw)) {
        AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Nrm_k;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_h;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        }
      } else {
        if (WiperCtl_WashWiperSta) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
          AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_hlc = WiperCtl_WiperParkPosSw;

          /* Outputs for Function Call SubSystem: '<S621>/Wash.Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_hlc,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ng,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDet);

          /* End of Outputs for SubSystem: '<S621>/Wash.Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ng) {
            tmp = AppSwcBcm_ARID_DEF.last_cnt - 1;
            if (AppSwcBcm_ARID_DEF.last_cnt - 1 < 0) {
              tmp = 0;
            }

            AppSwcBcm_ARID_DEF.last_cnt = (uint8)tmp;
          }

          if (AppSwcBcm_ARID_DEF.last_cnt == 0) {
            if (WiperCtl_WiperInrSta) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
              AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
            } else {
              tmp = AppSwcBcm_ARID_DEF.after_cnt + 1;
              if (AppSwcBcm_ARID_DEF.after_cnt + 1 > 65535) {
                tmp = 65535;
              }

              AppSwcBcm_ARID_DEF.after_cnt = (uint16)tmp;
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
            }

            if (AppSwcBcm_ARID_DEF.after_cnt >= WiperCtl_WashAfterTim_C) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
              AppSwcBcm_ARID_DEF.Lib_blIn_ay = WiperCtl_WiperParkPosSw;
              AppSwcBcm_ARID_DEF.Lib_blInit_f = true;

              /* Outputs for Function Call SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit' */
              AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_ay,
                true, &AppSwcBcm_ARID_DEF.LogicalOperator_ml,
                &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

              /* End of Outputs for SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_ml) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
                AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
              }
            }
          } else {
            /* after_cnt=0;
               last_cnt=0; */
          }
        }

        if (WiperCtl_WiperMistSta || WiperCtl_WiperHiSpdSta ||
            WiperCtl_WiperLowSpdSta) {
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_fbi = WiperCtl_WiperInrSta;
          AppSwcBcm_ARID_DEF.Lib_blInit_e = WiperCtl_WiperInrSta;

          /* Outputs for Function Call SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_fbi,
            AppSwcBcm_ARID_DEF.Lib_blInit_e,
            &AppSwcBcm_ARID_DEF.LogicalOperator_el,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

          /* End of Outputs for SubSystem: '<S621>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
            (AppSwcBcm_ARID_DEF.LogicalOperator_el ||
             AppSwcBcm_ARID_DEF.WiperCtl_WashComp);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S589>/Chart' */
}

/* Output and update for atomic system: '<S242>/WiperHiSpdCtl' */
static void AppSwcBcm_WiperHiSpdCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S590>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S590>/Logical Operator' incorporates:
   *  RelationalOperator: '<S590>/Relational Operator1'
   *  RelationalOperator: '<S590>/Relational Operator2'
   */
  WiperCtl_WiperHiSpdSta = (rtb_RelationalOperator && WiperCtl_WiperHiSpdSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay4_p));
}

/* System initialize for atomic system: '<S242>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S591>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_kp = true;

  /* InitializeConditions for Delay: '<S591>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_bw = true;
}

/* Output and update for atomic system: '<S242>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl(void)
{
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator5_i2;

  /* RelationalOperator: '<S591>/Relational Operator5' incorporates:
   *  Constant: '<S591>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S591>/Relational Operator'
   */
  rtb_RelationalOperator5_i2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S591>/Logical Operator' incorporates:
   *  RelationalOperator: '<S591>/Relational Operator2'
   */
  WiperCtl_WiperInrSta = (rtb_RelationalOperator5_i2 && WiperCtl_WiperInrSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay5_c));

  /* Delay: '<S591>/Delay1' */
  if (AppSwcBcm_ARID_DEF.icLoad_kp) {
    /* Switch: '<S591>/Switch1' incorporates:
     *  Constant: '<S591>/Constant20'
     *  Constant: '<S591>/Constant8'
     *  RelationalOperator: '<S591>/Relational Operator4'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.InrTim == 255) {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrLvl3Tim_C;
    } else {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = AppSwcBcm_ARID_DEF.BusCreator12.InrTim;
    }

    /* End of Switch: '<S591>/Switch1' */
  }

  /* RelationalOperator: '<S591>/Relational Operator5' incorporates:
   *  Constant: '<S591>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S591>/Relational Operator3'
   */
  rtb_RelationalOperator5_i2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Switch: '<S591>/Switch' */
  if (rtb_RelationalOperator5_i2) {
    /* Switch: '<S591>/Switch' */
    rtb_Switch = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUWiprIntlTmSet_enum;
  } else {
    /* Switch: '<S591>/Switch' incorporates:
     *  Constant: '<S591>/Constant19'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S591>/Switch' */

  /* MultiPortSwitch: '<S591>/Multiport Switch' incorporates:
   *  Constant: '<S591>/Constant1'
   *  Constant: '<S591>/Constant2'
   *  Constant: '<S591>/Constant3'
   *  Constant: '<S591>/Constant4'
   *  Constant: '<S591>/Constant5'
   *  Constant: '<S591>/Constant6'
   *  Constant: '<S591>/Constant7'
   *  Delay: '<S591>/Delay1'
   */
  switch (rtb_Switch) {
   case 1:
    WiperCtl_InrTim = WiperCtl_InrLvl1Tim_C;
    break;

   case 2:
    WiperCtl_InrTim = WiperCtl_InrLvl2Tim_C;
    break;

   case 3:
    WiperCtl_InrTim = WiperCtl_InrLvl3Tim_C;
    break;

   case 4:
    WiperCtl_InrTim = WiperCtl_InrLvl4Tim_C;
    break;

   case 5:
    WiperCtl_InrTim = WiperCtl_InrLvl5Tim_C;
    break;

   case 6:
    WiperCtl_InrTim = WiperCtl_InrLvl6Tim_C;
    break;

   case 7:
    WiperCtl_InrTim = WiperCtl_InrLvl7Tim_C;
    break;

   default:
    WiperCtl_InrTim = AppSwcBcm_ARID_DEF.Delay1_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S591>/Multiport Switch' */

  /* RelationalOperator: '<S591>/Relational Operator1' incorporates:
   *  UnitDelay: '<S591>/Unit Delay'
   */
  WiperCtl_InrTimChg = (WiperCtl_InrTim != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE);

  /* Delay: '<S591>/Delay2' */
  if (AppSwcBcm_ARID_DEF.icLoad_bw) {
    /* Switch: '<S591>/Switch2' incorporates:
     *  Constant: '<S591>/Constant15'
     *  Constant: '<S591>/Constant21'
     *  RelationalOperator: '<S591>/Relational Operator5'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE =
        AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb;
    }

    /* End of Switch: '<S591>/Switch2' */
  }

  /* MultiPortSwitch: '<S591>/Multiport Switch1' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant9'
     */
    WiperCtl_WiprIntlTimeSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant16'
     */
    WiperCtl_WiprIntlTimeSetFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant10'
     */
    WiperCtl_WiprIntlTimeSetFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant11'
     */
    WiperCtl_WiprIntlTimeSetFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant12'
     */
    WiperCtl_WiprIntlTimeSetFb = 4U;
    break;

   case 6:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant13'
     */
    WiperCtl_WiprIntlTimeSetFb = 5U;
    break;

   case 7:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Constant: '<S591>/Constant14'
     */
    WiperCtl_WiprIntlTimeSetFb = 6U;
    break;

   default:
    /* MultiPortSwitch: '<S591>/Multiport Switch1' incorporates:
     *  Delay: '<S591>/Delay2'
     */
    WiperCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.Delay2_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S591>/Multiport Switch1' */

  /* Update for Delay: '<S591>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_kp = false;
  AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrTim;

  /* Update for UnitDelay: '<S591>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE = WiperCtl_InrTim;

  /* Update for Delay: '<S591>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_bw = false;
  AppSwcBcm_ARID_DEF.Delay2_DSTATE = WiperCtl_WiprIntlTimeSetFb;
}

/* Output and update for atomic system: '<S242>/WiperLowSpdCtl' */
static void AppSwcBcm_WiperLowSpdCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S592>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S592>/Logical Operator' incorporates:
   *  RelationalOperator: '<S592>/Relational Operator1'
   *  RelationalOperator: '<S592>/Relational Operator2'
   */
  WiperCtl_WiperLowSpdSta = (rtb_RelationalOperator && WiperCtl_WiperLowSpdSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay7));
}

/* Output and update for atomic system: '<S242>/WiperMaintCtl' */
static void AppSwcBcm_WiperMaintCtl(void)
{
  boolean rtb_RelationalOperator6_mc;

  /* Chart: '<S593>/MaintOff' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S593>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ff) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kh =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

    /* Outputs for Function Call SubSystem: '<S631>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_kh,
      &AppSwcBcm_ARID_DEF.LogicalOperator_n2,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ct);

    /* End of Outputs for SubSystem: '<S631>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.Flg_p0 = (AppSwcBcm_ARID_DEF.LogicalOperator_n2 ||
      AppSwcBcm_ARID_DEF.Flg_p0);
    if (AppSwcBcm_ARID_DEF.Flg_p0) {
      AppSwcBcm_ARID_DEF.Lib_blIn_hl =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S631>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_hl,
        &AppSwcBcm_ARID_DEF.LogicalOperator_i,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

      /* End of Outputs for SubSystem: '<S631>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff =
        (AppSwcBcm_ARID_DEF.LogicalOperator_i ||
         AppSwcBcm_ARID_DEF.WiperCtl_MaintOff);
    }
  } else {
    AppSwcBcm_ARID_DEF.Flg_p0 = false;
    AppSwcBcm_ARID_DEF.WiperCtl_MaintOff = false;
  }

  /* End of Chart: '<S593>/MaintOff' */

  /* Outputs for Atomic SubSystem: '<S593>/Lib_SR' */
  /* Switch: '<S630>/Switch' incorporates:
   *  Constant: '<S593>/Constant2'
   *  Constant: '<S593>/Constant5'
   *  Constant: '<S630>/Constant'
   *  Logic: '<S593>/Logical Operator'
   *  Logic: '<S593>/Logical Operator1'
   *  Logic: '<S630>/Logical Operator'
   *  RelationalOperator: '<S593>/Relational Operator1'
   *  RelationalOperator: '<S593>/Relational Operator2'
   *  RelationalOperator: '<S593>/Relational Operator3'
   *  RelationalOperator: '<S593>/Relational Operator4'
   *  RelationalOperator: '<S593>/Relational Operator5'
   *  UnitDelay: '<S630>/Unit Delay'
   */
  if ((!WiperCtl_WiperOffSw) ||
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 1) ||
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff) {
    WiperCtl_WiperMaintSta = false;
  } else {
    /* RelationalOperator: '<S593>/Relational Operator6' incorporates:
     *  Constant: '<S593>/Constant3'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_mc = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    WiperCtl_WiperMaintSta = (((!AppSwcBcm_ARID_DEF.UnitDelay6) &&
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 2) &&
      WiperCtl_WiperParkPosSw && rtb_RelationalOperator6_mc) ||
      WiperCtl_WiperMaintSta);
  }

  /* End of Switch: '<S630>/Switch' */
  /* End of Outputs for SubSystem: '<S593>/Lib_SR' */

  /* Update for UnitDelay: '<S593>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ff = WiperCtl_WiperMaintSta;
}

/* Output and update for atomic system: '<S242>/WiperMistCtl' */
static void AppSwcBcm_WiperMistCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S594>/Relational Operator' incorporates:
   *  Constant: '<S594>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S594>/Logical Operator' incorporates:
   *  RelationalOperator: '<S594>/Relational Operator1'
   *  RelationalOperator: '<S594>/Relational Operator2'
   */
  WiperCtl_WiperMistSta = (rtb_RelationalOperator && WiperCtl_WiperMistSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay3_l));
}

/* Output and update for atomic system: '<S242>/WiperOffCtl' */
static void AppSwcBcm_WiperOffCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S595>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* Logic: '<S595>/Logical Operator' incorporates:
   *  RelationalOperator: '<S595>/Relational Operator1'
   */
  WiperCtl_WiperOffSta = (rtb_RelationalOperator || WiperCtl_WiperOffSw);
}

/* System initialize for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S242>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt_Init();

  /* End of SystemInitialize for SubSystem: '<S242>/LockedRotorProt' */

  /* SystemInitialize for Atomic SubSystem: '<S242>/WashCtl' */
  AppSwcBcm_WashCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S242>/WashCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S242>/WiperDrv' */
  AppSwcBcm_WiperDrv_Init();

  /* End of SystemInitialize for SubSystem: '<S242>/WiperDrv' */

  /* SystemInitialize for Atomic SubSystem: '<S242>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S242>/WiperInrCtl' */
}

/* Output and update for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl(void)
{
  boolean rtb_DataTypeConversion_g;

  /* SignalConversion: '<S242>/Signal Conversion' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWiprSwtSt =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWiprSwtSt_enum;

  /* SignalConversion: '<S242>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWshrSwtSt =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWshrSwtSt_flg;

  /* SignalConversion: '<S242>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWshrSwtStVD =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWshrSwtStVld_flg;

  /* SignalConversion: '<S242>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_WiprSwtStVD =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWiprSwtStVld_flg;

  /* Outputs for Atomic SubSystem: '<S242>/SignalProcess' */
  AppSwcBcm_SignalProcess_m();

  /* End of Outputs for SubSystem: '<S242>/SignalProcess' */

  /* UnitDelay: '<S242>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_c = WiperCtl_LockedRotorProtSta;

  /* Outputs for Atomic SubSystem: '<S242>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl();

  /* End of Outputs for SubSystem: '<S242>/WiperInrCtl' */

  /* Outputs for Atomic SubSystem: '<S242>/WiperOffCtl' */
  AppSwcBcm_WiperOffCtl();

  /* End of Outputs for SubSystem: '<S242>/WiperOffCtl' */

  /* UnitDelay: '<S242>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8 = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_f;

  /* Outputs for Atomic SubSystem: '<S242>/WashCtl' */
  AppSwcBcm_WashCtl();

  /* End of Outputs for SubSystem: '<S242>/WashCtl' */

  /* UnitDelay: '<S242>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_p = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_e;

  /* Outputs for Atomic SubSystem: '<S242>/WiperHiSpdCtl' */
  AppSwcBcm_WiperHiSpdCtl();

  /* End of Outputs for SubSystem: '<S242>/WiperHiSpdCtl' */

  /* UnitDelay: '<S242>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7 = AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_n;

  /* Outputs for Atomic SubSystem: '<S242>/WiperLowSpdCtl' */
  AppSwcBcm_WiperLowSpdCtl();

  /* End of Outputs for SubSystem: '<S242>/WiperLowSpdCtl' */

  /* UnitDelay: '<S242>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_l = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_c;

  /* Outputs for Atomic SubSystem: '<S242>/WiperMistCtl' */
  AppSwcBcm_WiperMistCtl();

  /* End of Outputs for SubSystem: '<S242>/WiperMistCtl' */

  /* UnitDelay: '<S242>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6 = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_n;

  /* Outputs for Atomic SubSystem: '<S242>/WiperMaintCtl' */
  AppSwcBcm_WiperMaintCtl();

  /* End of Outputs for SubSystem: '<S242>/WiperMaintCtl' */

  /* Outputs for Atomic SubSystem: '<S242>/WiperDrv' */
  AppSwcBcm_WiperDrv();

  /* End of Outputs for SubSystem: '<S242>/WiperDrv' */

  /* Outputs for Atomic SubSystem: '<S242>/Ovrd1' */
  /* Switch: '<S584>/Switch1' incorporates:
   *  Constant: '<S242>/Constant1'
   */
  if (WiperCtl_LowSpdDrvOvrdFlg_C) {
    /* Switch: '<S584>/Switch1' incorporates:
     *  Constant: '<S242>/Constant2'
     */
    WiperCtl_LowSpdDrv = WiperCtl_LowSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S242>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperLowSpdCtlFlg != 0);

    /* Switch: '<S584>/Switch1' incorporates:
     *  Switch: '<S584>/Switch2'
     */
    WiperCtl_LowSpdDrv = (rtb_DataTypeConversion_g ||
                          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e);
  }

  /* End of Switch: '<S584>/Switch1' */
  /* End of Outputs for SubSystem: '<S242>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S242>/Ovrd2' */
  /* Switch: '<S585>/Switch1' incorporates:
   *  Constant: '<S242>/Constant3'
   */
  if (WiperCtl_HiSpdDrvOvrdFlg_C) {
    /* Switch: '<S585>/Switch1' incorporates:
     *  Constant: '<S242>/Constant4'
     */
    WiperCtl_HiSpdDrv = WiperCtl_HiSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S242>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperHiSpdCtlFlg != 0);

    /* Switch: '<S585>/Switch1' incorporates:
     *  Switch: '<S585>/Switch2'
     */
    WiperCtl_HiSpdDrv = (rtb_DataTypeConversion_g ||
                         AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o);
  }

  /* End of Switch: '<S585>/Switch1' */
  /* End of Outputs for SubSystem: '<S242>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S242>/Ovrd3' */
  /* Switch: '<S586>/Switch1' incorporates:
   *  Constant: '<S242>/Constant18'
   */
  if (WiperCtl_WashMotorDrvOvrdFlg_C) {
    /* Switch: '<S586>/Switch1' incorporates:
     *  Constant: '<S242>/Constant19'
     */
    WiperCtl_WashMotorDrv = WiperCtl_WashMotorDrvOvrdVal_C;
  } else {
    /* Switch: '<S586>/Switch1' incorporates:
     *  Switch: '<S586>/Switch2'
     */
    WiperCtl_WashMotorDrv = AppSwcBcm_ARID_DEF.LIB_blOut_l;
  }

  /* End of Switch: '<S586>/Switch1' */
  /* End of Outputs for SubSystem: '<S242>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S242>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt();

  /* End of Outputs for SubSystem: '<S242>/LockedRotorProt' */

  /* Update for UnitDelay: '<S242>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_f = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S242>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_e = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S242>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_n = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S242>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_c = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S242>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_o = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S242>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_n = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S242>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cw = WiperCtl_LowSpdDrv;

  /* Update for UnitDelay: '<S242>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i = WiperCtl_HiSpdDrv;
}

/*
 * Output and update for atomic system:
 *    '<S646>/Lib_FailEdgeDet'
 *    '<S649>/Lib_FailEdgeDet'
 *    '<S647>/Lib_FailEdgeDet'
 *    '<S650>/Lib_FailEdgeDet'
 *    '<S648>/Lib_FailEdgeDet'
 */
static void AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_h_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S654>/Logical Operator' incorporates:
   *  Logic: '<S654>/Logical Operator1'
   *  UnitDelay: '<S654>/Unit Delay'
   */
  *rty_Lib_blOut = ((!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S654>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S645>/Lib_FailEdgeDet'
 *    '<S645>/Lib_FailEdgeDet3'
 *    '<S645>/Lib_FailEdgeDet4'
 *    '<S645>/Lib_FailEdgeDet2'
 */
static void AppSwcBcm_Lib_FailEdgeDet_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S646>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_a(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S646>/Lib_FailEdgeDet' */
}

/* Output and update for function-call system: '<S645>/Lib_FailEdgeDet1' */
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S647>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_a(rtu_Lib_blIn, rty_Lib_lbOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S647>/Lib_FailEdgeDet' */
}

/* Function for Chart: '<S636>/AlmSysLogic' */
static void AppSwcBcm_AlmWarn(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_hj = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_hj,
    &AppSwcBcm_ARID_DEF.LogicalOperator_po,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

  /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
    /* Flg=1; */
    AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_bd = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet1' */
    AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_bd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_j0,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_m);

    /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet1' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_j0) {
      /* Flg=1; */
      AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_m = AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

      /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet2' */
      AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_m,
        &AppSwcBcm_ARID_DEF.LogicalOperator_g3,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

      /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_g3) {
        /* Flg=1; */
        AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ld =
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet3' */
        AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_ld,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ht,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

        /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet3' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ht) {
          /* Flg=1; */
          AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

          /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet4' */
          AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
            &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

          /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet4' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_pd) {
            /* Flg=1; */
            AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
          }
        }
      }
    }
  }

  if (AppSwcBcm_ARID_DEF.Cnt_eh >= AlmSysCtl_AlrmTimLimit_C) {
    AlmSysCtl_AlrmWarnTimOut = true;

    /* Flg=0; */
  } else {
    AppSwcBcm_ARID_DEF.Cnt_eh++;
    AlmSysCtl_AlrmWarnTimOut = false;
  }
}

/* System initialize for atomic system: '<S636>/AlmSysLogic' */
static void AppSwcBcm_AlmSysLogic_Init(void)
{
  /* SystemInitialize for Function Call SubSystem: '<S645>/Lib_RiseEdgeDetInit' */
  /* SystemInitialize for Atomic SubSystem: '<S653>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S653>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S645>/Lib_RiseEdgeDetInit' */
}

/* Output and update for atomic system: '<S636>/AlmSysLogic' */
static void AppSwcBcm_AlmSysLogic(void)
{
  boolean guard1 = false;
  boolean guard2 = false;
  boolean guard3 = false;
  boolean guard4 = false;
  boolean guard5 = false;
  boolean guard6 = false;
  boolean guard7 = false;
  boolean guard8 = false;

  /* Chart: '<S636>/AlmSysLogic' incorporates:
   *  UnitDelay: '<S4>/Unit Delay3'
   *  UnitDelay: '<S4>/Unit Delay4'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_AlmSysCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_AlmSysCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Init_h;
    AlmSysCtl_BodyWarnSts = AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    guard8 = false;
    switch (AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib) {
     case AppSwcBcm_IN_Alarm:
      if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
        guard4 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_g = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE ==
          1);

        /* Outputs for Function Call SubSystem: '<S645>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_g,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ja);

        /* End of Outputs for SubSystem: '<S645>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
          guard4 = true;
        } else if (((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) ||
                   AlmSysCtl_AlrmWarnTimOut) {
          /* UpdateSta(); */
          AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_a;
          AlmSysCtl_BodyWarnSts = 1U;

          /* du:UpdateSta(); */
        } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                   ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                    (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
          /* UpdateSta(); */
          AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_j;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_AlmWarn();
        }
      }
      break;

     case AppSwcBcm_IN_Armed_a:
      if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
        guard5 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_g = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE ==
          1);

        /* Outputs for Function Call SubSystem: '<S645>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_g,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ja);

        /* End of Outputs for SubSystem: '<S645>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
          guard5 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta == 1) {
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_j;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_hj =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

          /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet' */
          AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_hj,
            &AppSwcBcm_ARID_DEF.LogicalOperator_po,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

          /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
            guard8 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_bd =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

            /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet1' */
            AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_bd,
              &AppSwcBcm_ARID_DEF.LogicalOperator_j0,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_m);

            /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet1' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_j0) {
              guard8 = true;
            } else {
              guard7 = true;
            }
          }
        }
      }
      break;

     case AppSwcBcm_IN_Disarmed_e:
      if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) {
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_a;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
      } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                 ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                  (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_j;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
      }
      break;

     case AppSwcBcm_IN_Init_h:
      switch (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_a;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
        break;

       case 2:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
        AlmSysCtl_BodyWarnSts = 2U;
        AlmSysCtl_AlrmWarnTimOut = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_j;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
        break;

       default:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_e;
        AlmSysCtl_BodyWarnSts = 0U;

        /* du:UpdateSta(); */
        break;
      }
      break;

     default:
      /* case IN_PartArmed: */
      if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
          (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2)) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ip =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;
        AppSwcBcm_ARID_DEF.Lib_blInit = true;

        /* Outputs for Function Call SubSystem: '<S645>/Lib_RiseEdgeDetInit' */
        /* Outputs for Atomic SubSystem: '<S653>/Lib_RiseEdgeDetInit' */
        AppSwcBcm_Lib_RiseEdgeDetInit_nr(AppSwcBcm_ARID_DEF.Lib_blIn_ip, true,
          &AppSwcBcm_ARID_DEF.LogicalOperator_l0,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

        /* End of Outputs for SubSystem: '<S653>/Lib_RiseEdgeDetInit' */
        /* End of Outputs for SubSystem: '<S645>/Lib_RiseEdgeDetInit' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_l0 &&
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) {
          guard1 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
          guard2 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_g = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE ==
            1);

          /* Outputs for Function Call SubSystem: '<S645>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_g,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ja);

          /* End of Outputs for SubSystem: '<S645>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_hj =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

            /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet' */
            AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_hj,
              &AppSwcBcm_ARID_DEF.LogicalOperator_po,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

            /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
              guard3 = true;
            } else {
              AppSwcBcm_ARID_DEF.Lib_blIn_bd =
                AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

              /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet1' */
              AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_bd,
                &AppSwcBcm_ARID_DEF.LogicalOperator_j0,
                &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_m);

              /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet1' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_j0) {
                guard3 = true;
              } else {
                AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

                /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet4' */
                AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
                  &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
                  &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

                /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet4' */
                if (AppSwcBcm_ARID_DEF.LogicalOperator_pd) {
                  guard3 = true;
                } else {
                  AppSwcBcm_ARID_DEF.Lib_blIn_ol =
                    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0;

                  /* Outputs for Function Call SubSystem: '<S645>/Lib_RiseEdgeDet1' */
                  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ol,
                    &AppSwcBcm_ARID_DEF.LogicalOperator_o4,
                    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_m);

                  /* End of Outputs for SubSystem: '<S645>/Lib_RiseEdgeDet1' */
                  if (AppSwcBcm_ARID_DEF.LogicalOperator_o4) {
                    guard3 = true;
                  }
                }
              }
            }
          }
        }
      }
      break;
    }

    if (guard8) {
      if (!AppSwcBcm_ARID_DEF.DataTypeConversion10) {
        guard6 = true;
      } else {
        guard7 = true;
      }
    }

    if (guard7) {
      AppSwcBcm_ARID_DEF.Lib_blIn_ol = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0;

      /* Outputs for Function Call SubSystem: '<S645>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ol,
        &AppSwcBcm_ARID_DEF.LogicalOperator_o4,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_m);

      /* End of Outputs for SubSystem: '<S645>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_o4) {
        guard6 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_m =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

        /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet2' */
        AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_m,
          &AppSwcBcm_ARID_DEF.LogicalOperator_g3,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

        /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_g3) {
          guard6 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_ld =
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

          /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet3' */
          AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_ld,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ht,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

          /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet3' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ht) {
            guard6 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

            /* Outputs for Function Call SubSystem: '<S645>/Lib_FailEdgeDet4' */
            AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
              &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

            /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet4' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_pd) {
              guard6 = true;
            }
          }
        }
      }
    }

    if (guard6) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_BodyWarnSts = 2U;
      AlmSysCtl_AlrmWarnTimOut = false;
    }

    if (guard5) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_e;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard4) {
      /* UpdateSta(); */
      AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_e;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard3) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_BodyWarnSts = 2U;
      AlmSysCtl_AlrmWarnTimOut = false;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_e;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_a;
      AlmSysCtl_BodyWarnSts = 1U;

      /* du:UpdateSta(); */
    }
  }

  /* End of Chart: '<S636>/AlmSysLogic' */
}

/* System initialize for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S636>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic_Init();
}

/* Output and update for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl(void)
{
  /* DataTypeConversion: '<S636>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.DataTypeConversion10 =
    (AppSwcBcm_ARID_DEF.BusCreator14.SKSta != 0);

  /* Chart: '<S636>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic();
}

/*
 * System initialize for atomic system:
 *    '<S665>/Lib_BothEdgeDetInit'
 *    '<S665>/Lib_BothEdgeDetInit1'
 *    '<S665>/Lib_BothEdgeDetInit2'
 *    '<S665>/Lib_BothEdgeDetInit3'
 */
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S668>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S665>/Lib_BothEdgeDetInit'
 *    '<S665>/Lib_BothEdgeDetInit1'
 *    '<S665>/Lib_BothEdgeDetInit2'
 *    '<S665>/Lib_BothEdgeDetInit3'
 */
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Delay: '<S668>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S668>/Logical Operator2' incorporates:
   *  Delay: '<S668>/Delay'
   *  Logic: '<S668>/Logical Operator1'
   *  Logic: '<S668>/Logical Operator3'
   *  Logic: '<S668>/Logical Operator4'
   *  Logic: '<S668>/Logical Operator5'
   */
  rty_Lib_blOut_0 = ((AppSwcBcm__ARID_DEF_arg->Delay_DSTATE && (!rtu_Lib_blIn)) ||
                     (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE)));

  /* Update for Delay: '<S668>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S665>/Lib_BothEdgeDetInit' */

  /* SystemInitialize for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit1' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of SystemInitialize for SubSystem: '<S665>/Lib_BothEdgeDetInit1' */

  /* SystemInitialize for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit2' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of SystemInitialize for SubSystem: '<S665>/Lib_BothEdgeDetInit2' */

  /* SystemInitialize for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit3' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of SystemInitialize for SubSystem: '<S665>/Lib_BothEdgeDetInit3' */
}

/* Output and update for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion_j;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator2_oj5;
  boolean rtb_RelationalOperator3_f;
  boolean rtb_RelationalOperator4_mm;
  boolean rtb_Switch;

  /* RelationalOperator: '<S665>/Relational Operator' incorporates:
   *  Constant: '<S665>/Constant'
   */
  BatSaveCtl_PwrModeOn = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

  /* RelationalOperator: '<S665>/Relational Operator1' incorporates:
   *  Constant: '<S665>/Constant1'
   */
  BatSaveCtl_DoorUnlckPwrOn = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* Outputs for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit' */
  rtb_RelationalOperator = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of Outputs for SubSystem: '<S665>/Lib_BothEdgeDetInit' */

  /* Outputs for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit1' */
  rtb_RelationalOperator2_oj5 = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of Outputs for SubSystem: '<S665>/Lib_BothEdgeDetInit1' */

  /* Outputs for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit2' */
  rtb_RelationalOperator3_f = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of Outputs for SubSystem: '<S665>/Lib_BothEdgeDetInit2' */

  /* Outputs for Atomic SubSystem: '<S665>/Lib_BothEdgeDetInit3' */
  rtb_RelationalOperator4_mm = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of Outputs for SubSystem: '<S665>/Lib_BothEdgeDetInit3' */

  /* Logic: '<S665>/Logical Operator1' */
  BatSaveCtl_DoorChgSta = (rtb_RelationalOperator || rtb_RelationalOperator2_oj5
    || rtb_RelationalOperator3_f || rtb_RelationalOperator4_mm);

  /* Logic: '<S665>/Logical Operator' */
  BatSaveCtl_PwrOn = (BatSaveCtl_PwrModeOn || BatSaveCtl_DoorUnlckPwrOn ||
                      BatSaveCtl_DoorChgSta);

  /* Chart: '<S664>/LIB_PosPluse' incorporates:
   *  Constant: '<S664>/Constant2'
   *  Constant: '<S664>/Constant4'
   *  Logic: '<S664>/Logical Operator2'
   *  Logic: '<S664>/Logical Operator3'
   *  Logic: '<S664>/Logical Operator5'
   *  Logic: '<S664>/Logical Operator8'
   *  RelationalOperator: '<S664>/Relational Operator'
   *  RelationalOperator: '<S664>/Relational Operator2'
   *  RelationalOperator: '<S664>/Relational Operator3'
   *  RelationalOperator: '<S664>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
      ((!BatSaveCtl_DoorChgSta) && ((AppSwcBcm_ARID_DEF.BusCreator4.InsLckSta !=
         1) && (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta != 1) &&
        (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta != 1)))) {
    if (AppSwcBcm_ARID_DEF.Cnt_m <= BatSaveCtl_DlyTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_m + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_m + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_m = (uint16)tmp;
      BatSaveCtl_PwrModeOff = false;
    } else {
      BatSaveCtl_PwrModeOff = true;
    }
  } else {
    BatSaveCtl_PwrModeOff = false;
    AppSwcBcm_ARID_DEF.Cnt_m = 0U;
  }

  /* End of Chart: '<S664>/LIB_PosPluse' */

  /* Chart: '<S664>/LIB_PosPluse1' incorporates:
   *  Constant: '<S664>/Constant6'
   *  Constant: '<S664>/Constant7'
   *  RelationalOperator: '<S664>/Relational Operator6'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) {
    if (AppSwcBcm_ARID_DEF.Cnt_o <= BatSaveCtl_LckDlyTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_o + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_o + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_o = (uint16)tmp;
      BatSaveCtl_DoorLckPwrOff = false;
    } else {
      BatSaveCtl_DoorLckPwrOff = true;
    }
  } else {
    BatSaveCtl_DoorLckPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_o = 0U;
  }

  /* End of Chart: '<S664>/LIB_PosPluse1' */

  /* Logic: '<S664>/Logical Operator' */
  BatSaveCtl_PwrOff = (BatSaveCtl_PwrModeOff || BatSaveCtl_DoorLckPwrOff);

  /* Outputs for Atomic SubSystem: '<S637>/Lib_SR' */
  AppSwcBcm_Lib_SR(BatSaveCtl_PwrOn, BatSaveCtl_PwrOff, &rtb_Switch,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR);

  /* End of Outputs for SubSystem: '<S637>/Lib_SR' */

  /* Outputs for Atomic SubSystem: '<S637>/Ovrd1' */
  /* Switch: '<S663>/Switch1' incorporates:
   *  Constant: '<S637>/Constant18'
   */
  if (BatSaveCtl_J64SavePwrOvrdFlg_C) {
    /* Switch: '<S663>/Switch1' incorporates:
     *  Constant: '<S637>/Constant19'
     */
    BatSaveCtl_J64SavePwr = BatSaveCtl_J64SavePwrOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S637>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BatSaveCtlFlg != 0);

    /* Switch: '<S663>/Switch1' incorporates:
     *  Switch: '<S663>/Switch2'
     */
    BatSaveCtl_J64SavePwr = (rtb_DataTypeConversion_j || rtb_Switch);
  }

  /* End of Switch: '<S663>/Switch1' */
  /* End of Outputs for SubSystem: '<S637>/Ovrd1' */
}

/* Output and update for atomic system: '<S4>/DTCCtl' */
static void AppSwcBcm_DTCCtl(void)
{
  uint8 rtb_DataTypeConversion22;

  /* DataTypeConversion: '<S638>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S638>/Data Type Conversion'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrLShort;

  /* CCaller: '<S638>/C Caller' */
  App_Call_Event_DTC_0x900011_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S638>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S638>/Data Type Conversion1'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrLOpen;

  /* CCaller: '<S638>/C Caller1' */
  App_Call_Event_DTC_0x900013_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S638>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S638>/Data Type Conversion2'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrRShort;

  /* CCaller: '<S638>/C Caller2' */
  App_Call_Event_DTC_0x900111_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S638>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S638>/Data Type Conversion3'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrROpen;

  /* CCaller: '<S638>/C Caller3' */
  App_Call_Event_DTC_0x900113_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S638>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S638>/Data Type Conversion8'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->LowBeamShortToBat;

  /* CCaller: '<S638>/C Caller8' */
  App_Call_Event_DTC_0x900412_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S638>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HiBeamShortToBat;

  /* CCaller: '<S638>/C Caller9' */
  App_Call_Event_DTC_0x900512_SetEventStatus(rtb_DataTypeConversion22);

  /* CCaller: '<S638>/C Caller10' */
  App_Call_Event_DTC_0x900711_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller11' */
  App_Call_Event_DTC_0x900811_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller12' */
  App_Call_Event_DTC_0x900923_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller13' */
  App_Call_Event_DTC_0x900924_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller14' */
  App_Call_Event_DTC_0x900A23_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller15' */
  App_Call_Event_DTC_0x900A24_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller16' */
  App_Call_Event_DTC_0x900B23_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller17' */
  App_Call_Event_DTC_0x900B24_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller18' */
  App_Call_Event_DTC_0x900C23_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller19' */
  App_Call_Event_DTC_0x900C24_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller20' */
  App_Call_Event_DTC_0x900D23_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller21' */
  App_Call_Event_DTC_0x900D24_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller22' */
  App_Call_Event_DTC_0x900E23_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller23' */
  App_Call_Event_DTC_0x900E24_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller24' */
  App_Call_Event_DTC_0x901016_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller25' */
  App_Call_Event_DTC_0x901031_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller27' */
  App_Call_Event_DTC_0x901231_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller29' */
  App_Call_Event_DTC_0x901331_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller30' */
  App_Call_Event_DTC_0x90141C_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller31' */
  App_Call_Event_DTC_0x901116_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller32' */
  App_Call_Event_DTC_0x901216_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller33' */
  App_Call_Event_DTC_0x901316_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller34' */
  App_Call_Event_DTC_0x901131_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller4' */
  App_Call_Event_DTC_0x900211_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller5' */
  App_Call_Event_DTC_0x900213_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller6' */
  App_Call_Event_DTC_0x900311_SetEventStatus(0U);

  /* CCaller: '<S638>/C Caller7' */
  App_Call_Event_DTC_0x900313_SetEventStatus(0U);
}

/* Function for Chart: '<S639>/DoorDrv' */
static void AppSwcBcm_TrunkStaFunc(void)
{
  sint32 tmp;
  tmp = AppSwcBcm_ARID_DEF.Trunk_Cnt + 1;
  if (AppSwcBcm_ARID_DEF.Trunk_Cnt + 1 > 65535) {
    tmp = 65535;
  }

  AppSwcBcm_ARID_DEF.Trunk_Cnt = (uint16)tmp;
  AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = true;
  if (AppSwcBcm_ARID_DEF.Trunk_Cnt >= DoorLckCtl_LckStaCfmMinTim_C) {
    DoorLckCtl_TrunkLckSta = 1U;
    AppSwcBcm_ARID_DEF.TrunkUnlckFin = true;
    AppSwcBcm_ARID_DEF.Trunk_Cnt = 0U;
    DoorLckCtl_TrunkLckSw = false;
  }

  if (AppSwcBcm_ARID_DEF.Trunk_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) {
    AppSwcBcm_ARID_DEF.TrunkUnlckFin = true;
    AppSwcBcm_ARID_DEF.Trunk_Cnt = 0U;
  }
}

/* Function for Chart: '<S639>/DoorDrv' */
static void AppSwcBcm_InsLckFunc(void)
{
  sint32 tmp;
  tmp = AppSwcBcm_ARID_DEF.InsLck_Cnt + 1;
  if (AppSwcBcm_ARID_DEF.InsLck_Cnt + 1 > 65535) {
    tmp = 65535;
  }

  AppSwcBcm_ARID_DEF.InsLck_Cnt = (uint16)tmp;
  if (!DoorLckCtl_TrunkAjarSw) {
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = true;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = true;
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = true;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
  }

  if (DoorLckCtl_DriverDoorLckSw && (AppSwcBcm_ARID_DEF.InsLck_Cnt >=
       DoorLckCtl_LckStaCfmMinTim_C)) {
    DoorLckCtl_InsLckSta = 2U;
  }

  if (AppSwcBcm_ARID_DEF.InsLck_Cnt >= DoorLckCtl_LckStaCfmMinTim_C) {
    DoorLckCtl_TrunkLckSta = 2U;
    DoorLckCtl_TrunkLckSw = true;
  }

  if ((AppSwcBcm_ARID_DEF.InsLck_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) ||
      ((DoorLckCtl_InsLckSta == 2) || (DoorLckCtl_TrunkLckSta == 2))) {
    AppSwcBcm_ARID_DEF.LckFin = true;
    AppSwcBcm_ARID_DEF.InsLck_Cnt = 0U;
  }
}

/* Function for Chart: '<S639>/DoorDrv' */
static void AppSwcBcm_InsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_cv = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S672>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_cv,
    &AppSwcBcm_ARID_DEF.LogicalOperator_gm,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);

  /* End of Outputs for SubSystem: '<S672>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_gm ||
    AppSwcBcm_ARID_DEF.MotorProtUnlck);
  if ((!DoorLckCtl_MotorProt) || AppSwcBcm_ARID_DEF.MotorProtUnlck) {
    tmp = AppSwcBcm_ARID_DEF.InsUnlck_Cnt + 1;
    if (AppSwcBcm_ARID_DEF.InsUnlck_Cnt + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.InsUnlck_Cnt = (uint16)tmp;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = true;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = true;
    if ((!DoorLckCtl_DriverDoorLckSw) && (AppSwcBcm_ARID_DEF.InsUnlck_Cnt >=
         DoorLckCtl_LckStaCfmMinTim_C)) {
      DoorLckCtl_InsLckSta = 1U;
      AppSwcBcm_ARID_DEF.UnlckFin = true;
      AppSwcBcm_ARID_DEF.InsUnlck_Cnt = 0U;
      AppSwcBcm_ARID_DEF.MotorProtUnlck = false;
    }

    if (AppSwcBcm_ARID_DEF.InsUnlck_Cnt >= DoorLckCtl_LckStaCfmMinTim_C) {
      DoorLckCtl_TrunkLckSta = 1U;
      DoorLckCtl_TrunkLckSw = false;
    }

    if (AppSwcBcm_ARID_DEF.InsUnlck_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) {
      AppSwcBcm_ARID_DEF.UnlckFin = true;
      AppSwcBcm_ARID_DEF.InsUnlck_Cnt = 0U;
      AppSwcBcm_ARID_DEF.MotorProtUnlck = false;
    }
  } else {
    AppSwcBcm_ARID_DEF.UnlckFin = true;
  }
}

/* Function for Chart: '<S639>/DoorDrv' */
static void AppSwcBcm_OsLckFunc(void)
{
  sint32 tmp;
  tmp = AppSwcBcm_ARID_DEF.OsLck_Cnt + 1;
  if (AppSwcBcm_ARID_DEF.OsLck_Cnt + 1 > 65535) {
    tmp = 65535;
  }

  AppSwcBcm_ARID_DEF.OsLck_Cnt = (uint16)tmp;
  if (!DoorLckCtl_TrunkAjarSw) {
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = true;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = true;
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = true;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
  }

  if (DoorLckCtl_DriverDoorLckSw && (AppSwcBcm_ARID_DEF.OsLck_Cnt >=
       DoorLckCtl_LckStaCfmMinTim_C)) {
    DoorLckCtl_OsLckSta = 2U;
  }

  if (AppSwcBcm_ARID_DEF.OsLck_Cnt >= DoorLckCtl_LckStaCfmMinTim_C) {
    DoorLckCtl_TrunkLckSta = 2U;
    DoorLckCtl_TrunkLckSw = true;
  }

  if ((AppSwcBcm_ARID_DEF.OsLck_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) ||
      ((DoorLckCtl_OsLckSta == 2) || (DoorLckCtl_TrunkLckSta == 2))) {
    AppSwcBcm_ARID_DEF.LckFin = true;
    AppSwcBcm_ARID_DEF.OsLck_Cnt = 0U;
  }
}

/* Function for Chart: '<S639>/DoorDrv' */
static void AppSwcBcm_OsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_cv = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S672>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_cv,
    &AppSwcBcm_ARID_DEF.LogicalOperator_gm,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);

  /* End of Outputs for SubSystem: '<S672>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_gm ||
    AppSwcBcm_ARID_DEF.MotorProtUnlck);
  if ((!DoorLckCtl_MotorProt) || AppSwcBcm_ARID_DEF.MotorProtUnlck) {
    tmp = AppSwcBcm_ARID_DEF.OsUnlck_Cnt + 1;
    if (AppSwcBcm_ARID_DEF.OsUnlck_Cnt + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.OsUnlck_Cnt = (uint16)tmp;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = true;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = true;
    if ((!DoorLckCtl_DriverDoorLckSw) && (AppSwcBcm_ARID_DEF.OsUnlck_Cnt >=
         DoorLckCtl_LckStaCfmMinTim_C)) {
      DoorLckCtl_OsLckSta = 1U;
      AppSwcBcm_ARID_DEF.UnlckFin = true;
      AppSwcBcm_ARID_DEF.OsUnlck_Cnt = 0U;
      AppSwcBcm_ARID_DEF.MotorProtUnlck = false;
    }

    if (AppSwcBcm_ARID_DEF.OsUnlck_Cnt >= DoorLckCtl_LckStaCfmMinTim_C) {
      DoorLckCtl_TrunkLckSta = 1U;
      DoorLckCtl_TrunkLckSw = false;
    }

    if (AppSwcBcm_ARID_DEF.OsUnlck_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) {
      AppSwcBcm_ARID_DEF.UnlckFin = true;
      AppSwcBcm_ARID_DEF.OsUnlck_Cnt = 0U;
      AppSwcBcm_ARID_DEF.MotorProtUnlck = false;
    }
  } else {
    AppSwcBcm_ARID_DEF.UnlckFin = true;
  }
}

/* System initialize for atomic system: '<S639>/DoorDrv' */
static void AppSwcBcm_DoorDrv_Init(void)
{
  DoorLckCtl_TrunkLckSw = true;
}

/* Output and update for atomic system: '<S639>/DoorDrv' */
static void AppSwcBcm_DoorDrv(void)
{
  boolean tmp;

  /* Chart: '<S639>/DoorDrv' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c19_DoorLckCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c19_DoorLckCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
    AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
    AppSwcBcm_ARID_DEF.UnlckFin = false;
    AppSwcBcm_ARID_DEF.LckFin = false;
    AppSwcBcm_ARID_DEF.TrunkUnlckFin = false;
    DoorLckCtl_InsLckSta = 0U;
    DoorLckCtl_OsLckSta = 0U;
    DoorLckCtl_TrunkLckSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib) {
     case AppSwcBcm_IN_DrvIdle:
      if (DoorLckCtl_InsUnlck || DoorLckCtl_DoorProtUnlck) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_InsDrvUnlck;
      } else if (DoorLckCtl_OsUnlck) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_OsDrvUnlck;
      } else {
        tmp = !DoorLckCtl_MotorProt;
        if (DoorLckCtl_InsLck && tmp &&
            (!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->CrashSta)) {
          AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_InsDrvLck;
        } else if (DoorLckCtl_OsLck && tmp &&
                   (!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->CrashSta))
        {
          AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_OsDrvLck;
        } else if (DoorLckCtl_TrunkUnlck && tmp) {
          AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_TrunkUnlck;
        }
      }
      break;

     case AppSwcBcm_IN_InsDrvLck:
      if (AppSwcBcm_ARID_DEF.LckFin) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
        AppSwcBcm_ARID_DEF.UnlckFin = false;
        AppSwcBcm_ARID_DEF.LckFin = false;
        AppSwcBcm_ARID_DEF.TrunkUnlckFin = false;
        DoorLckCtl_InsLckSta = 0U;
        DoorLckCtl_OsLckSta = 0U;
        DoorLckCtl_TrunkLckSta = 0U;
      } else {
        /* DoorLckCtl_J56=0;
           DoorLckCtl_J54=1;
           DoorLckCtl_J511=1; */
        AppSwcBcm_InsLckFunc();

        /* on after(DoorLckCtl_DrvTim_C,msec):
           DoorLckCtl_J56=0;
           DoorLckCtl_J54=0;
           DoorLckCtl_J511=0; */
      }
      break;

     case AppSwcBcm_IN_InsDrvUnlck:
      if (AppSwcBcm_ARID_DEF.UnlckFin) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
        AppSwcBcm_ARID_DEF.UnlckFin = false;
        AppSwcBcm_ARID_DEF.LckFin = false;
        AppSwcBcm_ARID_DEF.TrunkUnlckFin = false;
        DoorLckCtl_InsLckSta = 0U;
        DoorLckCtl_OsLckSta = 0U;
        DoorLckCtl_TrunkLckSta = 0U;
      } else {
        /* DoorLckCtl_J56=1;
           DoorLckCtl_J54=0; */
        AppSwcBcm_InsUnlckFunc();

        /* on after(DoorLckCtl_DrvTim_C,msec):
           DoorLckCtl_J56=0;
           DoorLckCtl_J54=0; */
      }
      break;

     case AppSwcBcm_IN_OsDrvLck:
      if (AppSwcBcm_ARID_DEF.LckFin) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
        AppSwcBcm_ARID_DEF.UnlckFin = false;
        AppSwcBcm_ARID_DEF.LckFin = false;
        AppSwcBcm_ARID_DEF.TrunkUnlckFin = false;
        DoorLckCtl_InsLckSta = 0U;
        DoorLckCtl_OsLckSta = 0U;
        DoorLckCtl_TrunkLckSta = 0U;
      } else {
        /* DoorLckCtl_J56=0;
           DoorLckCtl_J54=1;
           DoorLckCtl_J511=1; */
        AppSwcBcm_OsLckFunc();

        /* on after(DoorLckCtl_DrvTim_C,msec):
           DoorLckCtl_J56=0;
           DoorLckCtl_J54=0;
           DoorLckCtl_J511=0; */
      }
      break;

     case AppSwcBcm_IN_OsDrvUnlck:
      if (AppSwcBcm_ARID_DEF.UnlckFin) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
        AppSwcBcm_ARID_DEF.UnlckFin = false;
        AppSwcBcm_ARID_DEF.LckFin = false;
        AppSwcBcm_ARID_DEF.TrunkUnlckFin = false;
        DoorLckCtl_InsLckSta = 0U;
        DoorLckCtl_OsLckSta = 0U;
        DoorLckCtl_TrunkLckSta = 0U;
      } else {
        /* DoorLckCtl_J56=1;
           DoorLckCtl_J54=0; */
        AppSwcBcm_OsUnlckFunc();

        /* on after(DoorLckCtl_DrvTim_C,msec):
           DoorLckCtl_J56=0;
           DoorLckCtl_J54=0; */
      }
      break;

     default:
      /* case IN_TrunkUnlck: */
      if (AppSwcBcm_ARID_DEF.TrunkUnlckFin) {
        AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J56 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J54 = false;
        AppSwcBcm_ARID_DEF.DoorLckCtl_J511 = false;
        AppSwcBcm_ARID_DEF.UnlckFin = false;
        AppSwcBcm_ARID_DEF.LckFin = false;
        AppSwcBcm_ARID_DEF.TrunkUnlckFin = false;
        DoorLckCtl_InsLckSta = 0U;
        DoorLckCtl_OsLckSta = 0U;
        DoorLckCtl_TrunkLckSta = 0U;
      } else {
        /* DoorLckCtl_J511=1; */
        AppSwcBcm_TrunkStaFunc();

        /* on after(DoorLckCtl_DrvTim_C,msec):
           DoorLckCtl_J511=0; */
      }
      break;
    }
  }

  /* End of Chart: '<S639>/DoorDrv' */
}

/*
 * System initialize for atomic system:
 *    '<S728>/LIB_TPD_10ms1'
 *    '<S754>/LIB_TPD_10ms1'
 */
static void AppSwcBcm_LIB_TPD_10ms1_m_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S728>/LIB_TPD_10ms1'
 *    '<S754>/LIB_TPD_10ms1'
 */
static void AppSwcBcm_LIB_TPD_10ms1_h(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  rtu_LIB_bInit, boolean *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_h_T *
  AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S728>/LIB_TPD_10ms1' */
  if (!AppSwcBcm__ARID_DEF_arg->flg) {
    *rty_LIB_bErrFlg = rtu_LIB_bInit;
    AppSwcBcm__ARID_DEF_arg->flg = true;
  }

  if (rtu_LIB_blIn) {
    if ((AppSwcBcm__ARID_DEF_arg->cnt_defect >= (float32)rtu_LIB_u16tiToDef /
         (rtu_LIB_s32Ts * 100.0F)) && (rtu_LIB_u16tiToDef != 0xFFFF)) {
      *rty_LIB_bErrFlg = true;
    } else {
      AppSwcBcm__ARID_DEF_arg->cnt_defect++;
      AppSwcBcm__ARID_DEF_arg->cnt_heal = 0U;
    }
  } else {
    AppSwcBcm__ARID_DEF_arg->cnt_defect = 0U;
    if (AppSwcBcm__ARID_DEF_arg->cnt_heal >= (float32)rtu_LIB_u16tiToOk /
        (rtu_LIB_s32Ts * 100.0F)) {
      *rty_LIB_bErrFlg = false;
    } else if (rtu_LIB_u16tiToOk != 0xFFFF) {
      AppSwcBcm__ARID_DEF_arg->cnt_heal++;
    }
  }

  /* End of Chart: '<S728>/LIB_TPD_10ms1' */
}

/* System initialize for atomic system: '<S639>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_m;

  /* InitializeConditions for Delay: '<S741>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a4 = true;

  /* InitializeConditions for Delay: '<S682>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = true;

  /* InitializeConditions for UnitDelay: '<S682>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 1U;

  /* InitializeConditions for Delay: '<S748>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = true;

  /* InitializeConditions for Delay: '<S690>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = true;

  /* InitializeConditions for Delay: '<S683>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = true;

  /* InitializeConditions for UnitDelay: '<S683>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ps = 1U;

  /* InitializeConditions for Delay: '<S761>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_in = true;

  /* SystemInitialize for Chart: '<S697>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_cw);

  /* SystemInitialize for Chart: '<S697>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_o);

  /* SystemInitialize for Chart: '<S709>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_h);

  /* SystemInitialize for Chart: '<S727>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_m);

  /* SystemInitialize for Chart: '<S728>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_m_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_bn);

  /* SystemInitialize for Chart: '<S754>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_m_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_b);

  /* SystemInitialize for Chart: '<S758>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_c);
}

/* Output and update for atomic system: '<S639>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_m;
  sint32 tmp;
  uint8 rtb_Switch;
  boolean guard1 = false;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_ex;
  boolean rtb_LogicalOperator1_kf;
  boolean rtb_LogicalOperator5_a5;
  boolean rtb_LogicalOperator5_jv;
  boolean rtb_LogicalOperator_cr;
  boolean rtb_LogicalOperator_ii;
  boolean rtb_LogicalOperator_kt;
  boolean rtb_LogicalOperator_mu;
  boolean rtb_LogicalOperator_p4;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator10_df;
  boolean rtb_RelationalOperator2_c5;
  boolean rtb_RelationalOperator2_gx;
  boolean rtb_RelationalOperator3_de;
  boolean rtb_RelationalOperator_ja;

  /* Logic: '<S680>/Logical Operator2' incorporates:
   *  Logic: '<S727>/Logical Operator'
   *  RelationalOperator: '<S680>/Relational Operator2'
   *  RelationalOperator: '<S680>/Relational Operator3'
   *  RelationalOperator: '<S680>/Relational Operator4'
   */
  rtb_RelationalOperator10_df = ((!DoorLckCtl_DoorAjarFLSw) ||
    (!DoorLckCtl_DoorAjarFRSw) || (!DoorLckCtl_DoorAjarRRSw));

  /* RelationalOperator: '<S696>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_c5 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S696>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator2_c5,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nv);

  /* End of Outputs for SubSystem: '<S696>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S696>/Relational Operator1' incorporates:
   *  RelationalOperator: '<S697>/Relational Operator2'
   *  RelationalOperator: '<S729>/Relational Operator2'
   *  RelationalOperator: '<S733>/Relational Operator4'
   *  RelationalOperator: '<S754>/Relational Operator3'
   */
  rtb_RelationalOperator2_c5 = !DoorLckCtl_DriverDoorLckSw;

  /* Logic: '<S696>/Logical Operator2' incorporates:
   *  Constant: '<S696>/Constant1'
   *  RelationalOperator: '<S696>/Relational Operator'
   *  RelationalOperator: '<S696>/Relational Operator1'
   */
  DoorLckCtl_HULck = ((AppSwcBcm_ARID_DEF.UnitDelay1 == 0) &&
                      rtb_LogicalOperator && rtb_RelationalOperator2_c5);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S680>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S680>/Relational Operator6'
   */
  rtb_RelationalOperator3_de =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S680>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S680>/Relational Operator5'
   */
  rtb_RelationalOperator2_gx =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S680>/Logical Operator5' */
  rtb_LogicalOperator5_jv = (rtb_RelationalOperator3_de ||
    rtb_RelationalOperator2_gx);

  /* RelationalOperator: '<S730>/Relational Operator' incorporates:
   *  Constant: '<S730>/Constant'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  rtb_RelationalOperator = (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 2);

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S730>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S730>/Relational Operator1'
   */
  rtb_RelationalOperator2_gx =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S730>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S730>/Relational Operator2'
   */
  rtb_RelationalOperator3_de =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S730>/Relational Operator3' incorporates:
   *  RelationalOperator: '<S728>/Relational Operator6'
   *  RelationalOperator: '<S729>/Relational Operator3'
   *  RelationalOperator: '<S731>/Relational Operator1'
   *  RelationalOperator: '<S733>/Relational Operator9'
   */
  rtb_LogicalOperator1_kf = !DoorLckCtl_DrvSeatSw;

  /* Logic: '<S730>/Logical Operator1' incorporates:
   *  Logic: '<S730>/Logical Operator3'
   *  RelationalOperator: '<S730>/Relational Operator3'
   */
  rtb_LogicalOperator1_ex = (rtb_LogicalOperator1_kf && rtb_RelationalOperator &&
    (rtb_RelationalOperator2_gx || rtb_RelationalOperator3_de) &&
    DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S730>/Lib_RiseEdgeDet' */
  /* Logic: '<S743>/Logical Operator' incorporates:
   *  Logic: '<S743>/Logical Operator1'
   *  UnitDelay: '<S743>/Unit Delay'
   */
  DoorLckCtl_RKELck = (rtb_LogicalOperator1_ex &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mn));

  /* Update for UnitDelay: '<S743>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mn = rtb_LogicalOperator1_ex;

  /* End of Outputs for SubSystem: '<S730>/Lib_RiseEdgeDet' */

  /* Logic: '<S680>/Logical Operator1' incorporates:
   *  Logic: '<S680>/Logical Operator2'
   */
  DoorLckCtl_RKEAntiLck = (rtb_LogicalOperator5_jv &&
    rtb_RelationalOperator10_df && DoorLckCtl_RKELck);

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S728>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S728>/Relational Operator1'
   */
  rtb_RelationalOperator2_gx =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S728>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S728>/Relational Operator'
   */
  rtb_RelationalOperator3_de =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S728>/Relational Operator4' */
  rtb_LogicalOperator5_jv = DoorLckCtl_DriverDoorLckSw;

  /* Delay: '<S741>/Delay' incorporates:
   *  RelationalOperator: '<S728>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_a4) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_e = DoorLckCtl_DriverDoorLckSw;
  }

  /* Chart: '<S728>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S728>/Constant40'
   *  Constant: '<S728>/Constant41'
   *  Constant: '<S728>/Constant42'
   *  Constant: '<S728>/Constant7'
   *  Logic: '<S728>/Logical Operator1'
   *  RelationalOperator: '<S728>/Relational Operator2'
   *  RelationalOperator: '<S728>/Relational Operator3'
   *  RelationalOperator: '<S728>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1_h((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 10, 10,
    DoorLckCtl_Ts_C, true, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_bn,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_d);

  /* Logic: '<S728>/Logical Operator3' incorporates:
   *  Delay: '<S741>/Delay'
   *  Logic: '<S728>/Logical Operator'
   *  Logic: '<S741>/Logical Operator'
   *  Logic: '<S741>/Logical Operator1'
   *  RelationalOperator: '<S728>/Relational Operator4'
   */
  DoorLckCtl_MechLck = (rtb_LogicalOperator1_kf && (rtb_RelationalOperator2_gx ||
    rtb_RelationalOperator3_de) && (DoorLckCtl_DriverDoorLckSw &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_e)) && AppSwcBcm_ARID_DEF.LIB_bErrFlg_bn &&
                        DoorLckCtl_VehStop);

  /* Logic: '<S680>/Logical Operator3' incorporates:
   *  Logic: '<S680>/Logical Operator2'
   */
  DoorLckCtl_MechAntiLck = (DoorLckCtl_MechLck && rtb_RelationalOperator10_df);

  /* Logic: '<S680>/Logical Operator4' incorporates:
   *  Constant: '<S680>/Constant1'
   *  Logic: '<S680>/Logical Operator'
   *  Logic: '<S680>/Logical Operator2'
   *  RelationalOperator: '<S680>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_fb = (DoorLckCtl_RKEAntiLck || (DoorLckCtl_HULck &&
    (AppSwcBcm_ARID_DEF.UnitDelay1 == 0) && rtb_RelationalOperator10_df) ||
    DoorLckCtl_MechAntiLck);

  /* Chart: '<S680>/LIB_Tim' incorporates:
   *  SubSystem: '<S693>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_fb,
    &AppSwcBcm_ARID_DEF.LogicalOperator_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m3);
  AppSwcBcm_ARID_DEF.TempEn = (AppSwcBcm_ARID_DEF.LogicalOperator_j ||
    AppSwcBcm_ARID_DEF.TempEn);
  if (AppSwcBcm_ARID_DEF.TempEn) {
    /* Constant: '<S680>/Constant' */
    if (AppSwcBcm_ARID_DEF.Cnt_fq <= DoorLckCtl_AntiLckProtTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_fq + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_fq + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_fq = (uint16)tmp;
      DoorLckCtl_DoorProtUnlck = false;
    } else {
      DoorLckCtl_DoorProtUnlck = true;
      AppSwcBcm_ARID_DEF.TempEn = false;
    }

    /* End of Constant: '<S680>/Constant' */
  } else {
    DoorLckCtl_DoorProtUnlck = false;
    AppSwcBcm_ARID_DEF.Cnt_fq = 0U;
    AppSwcBcm_ARID_DEF.TempEn = false;
  }

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S689>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   *  RelationalOperator: '<S689>/Relational Operator2'
   */
  rtb_RelationalOperator2_gx = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->DrvPEAuthentAcsd == 1);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S689>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   *  RelationalOperator: '<S689>/Relational Operator6'
   */
  rtb_RelationalOperator3_de = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->FRPEAuthentAcsd == 1);

  /* Logic: '<S689>/Logical Operator1' incorporates:
   *  Constant: '<S689>/Constant5'
   *  Logic: '<S689>/Logical Operator'
   *  Logic: '<S689>/Logical Operator3'
   *  RelationalOperator: '<S689>/Relational Operator'
   *  RelationalOperator: '<S689>/Relational Operator1'
   *  RelationalOperator: '<S689>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_p = ((DoorLckCtl_DrvPESw || DoorLckCtl_PsgPESw) &&
    (rtb_RelationalOperator2_gx || rtb_RelationalOperator3_de) &&
    (DoorLckCtl_EEKeyEntry == 1));

  /* Chart: '<S689>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S772>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_p,
    &AppSwcBcm_ARID_DEF.LogicalOperator_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_m) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_f + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_f + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_f = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_o + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_o + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_o = (uint16)tmp;
  }

  /* Constant: '<S689>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt2_o >= DoorLckCtl_PEProtIntvlTim_C) {
    AppSwcBcm_ARID_DEF.Cnt_f = 0U;
    AppSwcBcm_ARID_DEF.LIB_blOut_n = false;
  }

  /* End of Constant: '<S689>/Constant2' */

  /* Constant: '<S689>/Constant3' */
  AppSwcBcm_ARID_DEF.LIB_blOut_n = ((AppSwcBcm_ARID_DEF.Cnt_f >=
    DoorLckCtl_PEProtCnt_C) || AppSwcBcm_ARID_DEF.LIB_blOut_n);

  /* Outputs for Atomic SubSystem: '<S689>/Lib_RiseEdgeDet' */
  /* Switch: '<S689>/Switch' */
  rtb_LogicalOperator_kt = AppSwcBcm_Lib_RiseEdgeDet
    ((!AppSwcBcm_ARID_DEF.LIB_blOut_n) && AppSwcBcm_ARID_DEF.Lib_blIn_p,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_lx);

  /* End of Outputs for SubSystem: '<S689>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S729>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S729>/Relational Operator4'
   */
  rtb_RelationalOperator2_gx =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S729>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S729>/Relational Operator5'
   */
  rtb_RelationalOperator3_de =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S729>/Logical Operator3' incorporates:
   *  Logic: '<S733>/Logical Operator'
   */
  rtb_LogicalOperator1_ex = (DoorLckCtl_DoorAjarFLSw && DoorLckCtl_DoorAjarFRSw &&
    DoorLckCtl_DoorAjarRRSw);

  /* Logic: '<S729>/Logical Operator1' incorporates:
   *  Logic: '<S729>/Logical Operator2'
   *  Logic: '<S729>/Logical Operator3'
   *  RelationalOperator: '<S729>/Relational Operator1'
   */
  DoorLckCtl_PELck = (rtb_LogicalOperator_kt && rtb_RelationalOperator2_c5 &&
                      rtb_LogicalOperator1_kf && (rtb_RelationalOperator2_gx ||
    rtb_RelationalOperator3_de) && rtb_LogicalOperator1_ex && DoorLckCtl_VehStop);

  /* Logic: '<S727>/Logical Operator5' incorporates:
   *  Constant: '<S727>/Constant13'
   *  Constant: '<S727>/Constant14'
   *  Constant: '<S727>/Constant15'
   *  Logic: '<S727>/Logical Operator4'
   *  RelationalOperator: '<S727>/Relational Operator10'
   *  RelationalOperator: '<S727>/Relational Operator11'
   *  RelationalOperator: '<S727>/Relational Operator12'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_LogicalOperator5_a5 = (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Outputs for Atomic SubSystem: '<S727>/Lib_ChangeEdge' */
  /* RelationalOperator: '<S735>/Relational Operator' incorporates:
   *  Constant: '<S727>/Constant8'
   *  UnitDelay: '<S735>/Unit Delay'
   */
  rtb_RelationalOperator_ja = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f == 1);

  /* Update for UnitDelay: '<S735>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = AppSwcBcm_ARID_DEF.UnitDelay1;

  /* End of Outputs for SubSystem: '<S727>/Lib_ChangeEdge' */

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S727>/Relational Operator9'
   */
  rtb_RelationalOperator2_gx =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* RelationalOperator: '<S727>/Relational Operator5' incorporates:
   *  Logic: '<S732>/Logical Operator'
   */
  rtb_RelationalOperator3_de = !DoorLckCtl_TrunkAjarSw;

  /* Outputs for Atomic SubSystem: '<S727>/Lib_SR' */
  /* Switch: '<S737>/Switch' incorporates:
   *  Constant: '<S727>/Constant11'
   *  Logic: '<S727>/Logical Operator'
   *  Logic: '<S727>/Logical Operator2'
   *  Logic: '<S727>/Logical Operator3'
   *  Logic: '<S727>/Logical Operator7'
   *  RelationalOperator: '<S727>/Relational Operator13'
   *  RelationalOperator: '<S727>/Relational Operator5'
   *  RelationalOperator: '<S727>/Relational Operator8'
   *  UnitDelay: '<S687>/Unit Delay'
   */
  if (rtb_RelationalOperator10_df || rtb_RelationalOperator3_de ||
      (!AppSwcBcm_ConstB.RelationalOperator6) || ((AppSwcBcm_ARID_DEF.UnitDelay2
        != 0) && (!rtb_LogicalOperator5_a5)) || rtb_RelationalOperator2_gx ||
      DoorLckCtl_OsLck) {
    /* Switch: '<S737>/Switch' incorporates:
     *  Constant: '<S737>/Constant'
     */
    DoorLckCtl_AutoLckSta = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S727>/Lib_ChangeEdge' */
    /* Switch: '<S737>/Switch' incorporates:
     *  Constant: '<S727>/Constant'
     *  Constant: '<S727>/Constant1'
     *  Logic: '<S727>/Logical Operator1'
     *  Logic: '<S727>/Logical Operator6'
     *  Logic: '<S735>/Logical Operator'
     *  Logic: '<S737>/Logical Operator'
     *  RelationalOperator: '<S727>/Relational Operator'
     *  RelationalOperator: '<S735>/Relational Operator1'
     *  UnitDelay: '<S737>/Unit Delay'
     */
    DoorLckCtl_AutoLckSta = (((rtb_LogicalOperator5_a5 ||
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) && ((AppSwcBcm_ARID_DEF.UnitDelay1 ==
      0) && rtb_RelationalOperator_ja)) || DoorLckCtl_AutoLckSta);

    /* End of Outputs for SubSystem: '<S727>/Lib_ChangeEdge' */
  }

  /* End of Switch: '<S737>/Switch' */
  /* End of Outputs for SubSystem: '<S727>/Lib_SR' */

  /* Chart: '<S727>/LIB_PosPluse2' incorporates:
   *  Constant: '<S727>/Constant7'
   *  UnitDelay: '<S673>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(DoorLckCtl_AutoLckSta, DoorLckCtl_AutoLckDelayTim_C,
    DoorLckCtl_OsUnlck, &rtb_LIB_blOut_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2);

  /* Outputs for Atomic SubSystem: '<S727>/Lib_RiseEdgeDet' */
  /* Logic: '<S736>/Logical Operator' incorporates:
   *  Logic: '<S736>/Logical Operator1'
   *  UnitDelay: '<S736>/Unit Delay'
   */
  DoorLckCtl_AutoLck = (rtb_LIB_blOut_m &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d5q));

  /* Update for UnitDelay: '<S736>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d5q = rtb_LIB_blOut_m;

  /* End of Outputs for SubSystem: '<S727>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S733>/Relational Operator10' incorporates:
   *  Constant: '<S733>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator10_df = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->LckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S733>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_p4 = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator10_df,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ln);

  /* End of Outputs for SubSystem: '<S733>/Lib_RiseEdgeDet' */

  /* Delay: '<S682>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_c) {
    /* Switch: '<S682>/Switch1' incorporates:
     *  Constant: '<S682>/Constant7'
     *  Constant: '<S682>/Constant8'
     *  RelationalOperator: '<S682>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts;
    }

    /* End of Switch: '<S682>/Switch1' */
  }

  /* Switch: '<S682>/Switch' incorporates:
   *  Constant: '<S682>/Constant5'
   *  RelationalOperator: '<S682>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S682>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndLckSts_enum;
  } else {
    /* Switch: '<S682>/Switch' incorporates:
     *  Constant: '<S682>/Constant6'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S682>/Switch' */

  /* MultiPortSwitch: '<S682>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S682>/Multiport Switch' incorporates:
     *  Constant: '<S682>/Constant1'
     */
    DoorLckCtl_IllmndLckSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S682>/Multiport Switch' incorporates:
     *  Constant: '<S682>/Constant2'
     */
    DoorLckCtl_IllmndLckSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S682>/Multiport Switch' incorporates:
     *  Delay: '<S682>/Delay'
     */
    DoorLckCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.Delay_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S682>/Multiport Switch' */

  /* MultiPortSwitch: '<S682>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndLckSts) {
   case 1:
    /* MultiPortSwitch: '<S682>/Multiport Switch1' incorporates:
     *  Constant: '<S682>/Constant3'
     */
    DoorLckCtl_IllmndLckStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S682>/Multiport Switch1' incorporates:
     *  Constant: '<S682>/Constant4'
     */
    DoorLckCtl_IllmndLckStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S682>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S682>/Unit Delay'
     */
    DoorLckCtl_IllmndLckStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p;
    break;
  }

  /* End of MultiPortSwitch: '<S682>/Multiport Switch1' */

  /* RelationalOperator: '<S758>/Relational Operator6' incorporates:
   *  Constant: '<S733>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S733>/Relational Operator2'
   */
  rtb_LogicalOperator5_a5 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* UnitDelay: '<S766>/Unit Delay' incorporates:
   *  Constant: '<S733>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S733>/Relational Operator3'
   */
  rtb_RelationalOperator10_df =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S733>/Logical Operator2' incorporates:
   *  Constant: '<S733>/Constant10'
   *  Logic: '<S733>/Logical Operator1'
   *  Logic: '<S733>/Logical Operator3'
   *  RelationalOperator: '<S733>/Relational Operator'
   *  RelationalOperator: '<S733>/Relational Operator1'
   *  RelationalOperator: '<S733>/Relational Operator8'
   */
  DoorLckCtl_WelcomeLck = (rtb_LogicalOperator_p4 && ((DoorLckCtl_IllmndLckStsFb
    == 1) && (DoorLckCtl_EEIlluminatedEntrySys == 1) && (rtb_LogicalOperator5_a5
    || rtb_RelationalOperator10_df) && rtb_RelationalOperator2_c5 &&
    rtb_LogicalOperator1_ex && (DoorLckCtl_IllmndSts == 1) &&
    rtb_LogicalOperator1_kf && DoorLckCtl_VehStop));

  /* Logic: '<S732>/Logical Operator2' incorporates:
   *  UnitDelay: '<S732>/Unit Delay'
   */
  rtb_RelationalOperator10_df = (rtb_RelationalOperator3_de ||
    DoorLckCtl_TrunkAutoLck);

  /* Delay: '<S748>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_k) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_o = AppSwcBcm_ARID_DEF.UnitDelay1;
  }

  /* Switch: '<S750>/Switch' */
  if (rtb_RelationalOperator10_df) {
    /* Switch: '<S750>/Switch' incorporates:
     *  Constant: '<S750>/Constant'
     */
    rtb_LogicalOperator1_ex = false;
  } else {
    /* Switch: '<S750>/Switch' incorporates:
     *  Constant: '<S732>/Constant2'
     *  Constant: '<S732>/Constant4'
     *  Delay: '<S748>/Delay'
     *  Logic: '<S748>/Logical Operator'
     *  Logic: '<S750>/Logical Operator'
     *  RelationalOperator: '<S748>/Relational Operator'
     *  RelationalOperator: '<S748>/Relational Operator1'
     *  UnitDelay: '<S750>/Unit Delay'
     */
    rtb_LogicalOperator1_ex = (((AppSwcBcm_ARID_DEF.UnitDelay1 == 3) &&
      (AppSwcBcm_ARID_DEF.Delay_DSTATE_o == 1)) ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cp);
  }

  /* End of Switch: '<S750>/Switch' */

  /* Chart: '<S758>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S758>/Constant'
   *  Constant: '<S758>/Constant2'
   *  Constant: '<S758>/Constant3'
   *  Constant: '<S758>/Constant4'
   *  RelationalOperator: '<S758>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  AppSwcBcm_LIB_TPD_10ms1(AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 3,
    DoorLckCtl_TrunkUnlckTimValid_C, DoorLckCtl_TrunkUnlckTimInvalid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1);

  /* Logic: '<S758>/Logical Operator1' incorporates:
   *  Constant: '<S758>/Constant6'
   *  RelationalOperator: '<S758>/Relational Operator3'
   */
  rtb_RelationalOperator2_gx = ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_c && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S758>/Lib_RiseEdgeDet1' */
  /* Logic: '<S768>/Logical Operator' incorporates:
   *  Logic: '<S768>/Logical Operator1'
   *  UnitDelay: '<S768>/Unit Delay'
   */
  DoorLckCtl_TrunkRKEUnlck = (rtb_RelationalOperator2_gx &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hg));

  /* Update for UnitDelay: '<S768>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hg = rtb_RelationalOperator2_gx;

  /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet1' */

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S758>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S758>/Relational Operator1'
   */
  rtb_RelationalOperator2_gx = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUTrnkLckSwCtrl_enum == 1);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S758>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S758>/Relational Operator5'
   */
  rtb_RelationalOperator3_de =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S758>/Relational Operator6' incorporates:
   *  Constant: '<S758>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_LogicalOperator5_a5 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S758>/Lib_RiseEdgeDet2' */
  /* Logic: '<S758>/Logical Operator3' incorporates:
   *  Constant: '<S758>/Constant5'
   *  Constant: '<S758>/Constant7'
   *  Logic: '<S758>/Logical Operator2'
   *  RelationalOperator: '<S758>/Relational Operator2'
   *  RelationalOperator: '<S758>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_e = AppSwcBcm_Lib_RiseEdgeDet
    (DoorLckCtl_VehStop && rtb_RelationalOperator2_gx &&
     (AppSwcBcm_ARID_DEF.UnitDelay1 == 0) && (AppSwcBcm_ARID_DEF.UnitDelay2 == 2)
     && (rtb_RelationalOperator3_de || rtb_LogicalOperator5_a5),
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

  /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet2' */

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S758>/Constant10'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S758>/Relational Operator7'
   */
  rtb_RelationalOperator2_gx = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBoxRmtLck_enum == 3);

  /* Logic: '<S758>/Logical Operator4' incorporates:
   *  Constant: '<S758>/Constant11'
   *  RelationalOperator: '<S758>/Relational Operator8'
   */
  rtb_RelationalOperator2_gx = (rtb_RelationalOperator2_gx &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 0) && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S758>/Lib_RiseEdgeDet3' */
  /* Logic: '<S770>/Logical Operator' incorporates:
   *  Logic: '<S770>/Logical Operator1'
   *  UnitDelay: '<S770>/Unit Delay'
   */
  DoorLckCtl_TrunkTboxUnlck = (rtb_RelationalOperator2_gx &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_go));

  /* Update for UnitDelay: '<S770>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_go = rtb_RelationalOperator2_gx;

  /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet3' */

  /* Logic: '<S758>/Logical Operator' */
  DoorLckCtl_TrunkUnlck = (DoorLckCtl_TrunkRKEUnlck ||
    AppSwcBcm_ARID_DEF.LogicalOperator_e || DoorLckCtl_TrunkTboxUnlck);

  /* RelationalOperator: '<S732>/Relational Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_e5 = DoorLckCtl_TrunkUnlck;

  /* Chart: '<S732>/LIB_PosPluse1' incorporates:
   *  SubSystem: '<S747>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_e5,
    &AppSwcBcm_ARID_DEF.LogicalOperator_g4,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_g4) {
    AppSwcBcm_ARID_DEF.Flg_e = true;
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  }

  if (rtb_RelationalOperator10_df) {
    AppSwcBcm_ARID_DEF.Flg_e = false;
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_e) {
    /* Constant: '<S732>/Constant1' */
    if (AppSwcBcm_ARID_DEF.Cnt_h >= DoorLckCtl_TrunkAutoLckTim_C) {
      rtb_RelationalOperator10_df = true;
      AppSwcBcm_ARID_DEF.Flg_e = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_h + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_h + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_h = (uint16)tmp;
      rtb_RelationalOperator10_df = false;
    }

    /* End of Constant: '<S732>/Constant1' */
  } else {
    rtb_RelationalOperator10_df = false;
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  }

  /* Logic: '<S732>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S732>/Relational Operator3'
   */
  rtb_RelationalOperator10_df = (rtb_LogicalOperator1_ex &&
    DoorLckCtl_TrunkAjarSw && rtb_RelationalOperator10_df);

  /* Outputs for Atomic SubSystem: '<S732>/Lib_RiseEdgeDet' */
  /* Logic: '<S749>/Logical Operator' incorporates:
   *  Logic: '<S749>/Logical Operator1'
   *  UnitDelay: '<S749>/Unit Delay'
   */
  DoorLckCtl_TrunkAutoLck = (rtb_RelationalOperator10_df &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bk));

  /* Update for UnitDelay: '<S749>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bk = rtb_RelationalOperator10_df;

  /* End of Outputs for SubSystem: '<S732>/Lib_RiseEdgeDet' */

  /* UnitDelay: '<S766>/Unit Delay' incorporates:
   *  Constant: '<S731>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S731>/Relational Operator'
   */
  rtb_RelationalOperator10_df = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC
    ())->VIPM_TBoxRmtLck_enum == 1);

  /* RelationalOperator: '<S731>/Relational Operator2' incorporates:
   *  Constant: '<S731>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_gx =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S731>/Relational Operator3' incorporates:
   *  Constant: '<S731>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_de =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S731>/Logical Operator1' incorporates:
   *  Logic: '<S731>/Logical Operator'
   */
  rtb_LogicalOperator1_kf = (rtb_RelationalOperator10_df &&
    rtb_LogicalOperator1_kf && (rtb_RelationalOperator2_gx ||
    rtb_RelationalOperator3_de) && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S731>/Lib_RiseEdgeDet' */
  /* Logic: '<S746>/Logical Operator' incorporates:
   *  Logic: '<S746>/Logical Operator1'
   *  UnitDelay: '<S746>/Unit Delay'
   */
  DoorLckCtl_TboxLck = (rtb_LogicalOperator1_kf &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ez));

  /* Update for UnitDelay: '<S746>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ez = rtb_LogicalOperator1_kf;

  /* End of Outputs for SubSystem: '<S731>/Lib_RiseEdgeDet' */

  /* Logic: '<S687>/Logical Operator' */
  DoorLckCtl_OsLck = (DoorLckCtl_MechLck || DoorLckCtl_PELck ||
                      DoorLckCtl_AutoLck || DoorLckCtl_WelcomeLck ||
                      DoorLckCtl_RKELck || DoorLckCtl_TrunkAutoLck ||
                      DoorLckCtl_TboxLck);

  /* Chart: '<S697>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S697>/Constant10'
   *  Constant: '<S697>/Constant11'
   *  Constant: '<S697>/Constant9'
   *  Logic: '<S697>/Logical Operator1'
   *  RelationalOperator: '<S697>/Relational Operator3'
   *  RelationalOperator: '<S697>/Relational Operator4'
   *  RelationalOperator: '<S697>/Relational Operator5'
   *  RelationalOperator: '<S697>/Relational Operator7'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarFLSw &&
    DoorLckCtl_DoorAjarRRSw && DoorLckCtl_TrunkAjarSw,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_j);

  /* Chart: '<S697>/Chart' */
  if (DoorLckCtl_DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.Lib_blIn_i1 = DoorLckCtl_DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S699>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_i1,
      &AppSwcBcm_ARID_DEF.LogicalOperator_mi,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oy);

    /* End of Outputs for SubSystem: '<S699>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_mi) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_l1 = DoorLckCtl_DoorAjarRRSw;

      /* Outputs for Function Call SubSystem: '<S699>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_l1,
        &AppSwcBcm_ARID_DEF.LogicalOperator_nn,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_i);

      /* End of Outputs for SubSystem: '<S699>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_nn) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ac = DoorLckCtl_TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S699>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
          &AppSwcBcm_ARID_DEF.LogicalOperator_d,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_n);

        /* End of Outputs for SubSystem: '<S699>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_d) {
          guard1 = true;
        }
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Door_Change = true;
      AppSwcBcm_ARID_DEF.Cnt_a = 0U;
    }
  }

  if (AppSwcBcm_ARID_DEF.Door_Change) {
    if (AppSwcBcm_ARID_DEF.Cnt_a >= 40) {
      AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = true;
      AppSwcBcm_ARID_DEF.Door_Change = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_a + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_a + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_a = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = false;
  }

  /* End of Chart: '<S697>/Chart' */

  /* Chart: '<S697>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S697>/Constant'
   *  Constant: '<S697>/Constant2'
   *  Constant: '<S697>/Constant3'
   *  Constant: '<S697>/Constant49'
   *  RelationalOperator: '<S697>/Relational Operator'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_VehSpd >= DoorLckCtl_SpdLck_C,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_cw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_o);

  /* Logic: '<S697>/Logical Operator' incorporates:
   *  Constant: '<S697>/Constant8'
   *  Logic: '<S697>/Logical Operator2'
   *  RelationalOperator: '<S697>/Relational Operator6'
   */
  rtb_LogicalOperator1_kf = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_o &&
    (rtb_RelationalOperator2_c5 || AppSwcBcm_ARID_DEF.DoorLckCtl_Lck) &&
    AppSwcBcm_ConstB.RelationalOperator1 && AppSwcBcm_ARID_DEF.LIB_bErrFlg_cw &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Logic: '<S702>/Logical Operator' incorporates:
   *  Logic: '<S702>/Logical Operator1'
   *  UnitDelay: '<S702>/Unit Delay'
   */
  DoorLckCtl_SpdLck = (rtb_LogicalOperator1_kf &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e1));

  /* Logic: '<S684>/Logical Operator' */
  DoorLckCtl_InsLck = (DoorLckCtl_HULck || DoorLckCtl_SpdLck);

  /* UnitDelay: '<S766>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S709>/Relational Operator'
   */
  rtb_RelationalOperator10_df = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->CrashSta;

  /* Chart: '<S709>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S709>/Constant2'
   *  Constant: '<S709>/Constant3'
   *  Constant: '<S709>/Constant4'
   *  Constant: '<S709>/Constant6'
   *  RelationalOperator: '<S709>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD_10ms1(AppSwcBcm_ARID_DEF.UnitDelay2 == 2,
    DoorLckCtl_CrshPwrOnTimValid_C, DoorLckCtl_CrshPwrOnTimInValid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms);

  /* Logic: '<S709>/Logical Operator1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_f5 = (rtb_RelationalOperator10_df &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_h);

  /* Chart: '<S709>/Chart' incorporates:
   *  SubSystem: '<S713>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_f5,
    &AppSwcBcm_ARID_DEF.LogicalOperator_lc,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ju);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_lc) {
    AppSwcBcm_ARID_DEF.Flg_px = true;
    DoorLckCtl_CrshUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_ee = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_px) {
    if (AppSwcBcm_ARID_DEF.Cnt_ee >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_ee >= 20) {
        DoorLckCtl_CrshUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_px = false;
      } else {
        DoorLckCtl_CrshUnlck = false;
        tmp = AppSwcBcm_ARID_DEF.Cnt_ee + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_ee + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_ee = (uint16)tmp;
      }
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_ee + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_ee + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_ee = (uint16)tmp;
    }
  } else {
    DoorLckCtl_CrshUnlck = false;
  }

  /* RelationalOperator: '<S710>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator10_df =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S710>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_mu = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator10_df,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_a);

  /* End of Outputs for SubSystem: '<S710>/Lib_RiseEdgeDet' */

  /* Logic: '<S710>/Logical Operator' incorporates:
   *  Constant: '<S710>/Constant2'
   *  RelationalOperator: '<S710>/Relational Operator'
   *  RelationalOperator: '<S710>/Relational Operator2'
   */
  DoorLckCtl_HUUnLck = (rtb_LogicalOperator_mu && DoorLckCtl_DriverDoorLckSw &&
                        (AppSwcBcm_ARID_DEF.UnitDelay1 == 0));

  /* Switch: '<S690>/Switch1' incorporates:
   *  Constant: '<S690>/Constant1'
   *  RelationalOperator: '<S690>/Relational Operator1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S690>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUParkAutoUnlckSet_enum;
  } else {
    /* Switch: '<S690>/Switch1' incorporates:
     *  Constant: '<S690>/Constant4'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S690>/Switch1' */

  /* Delay: '<S690>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_n) {
    /* Switch: '<S690>/Switch2' incorporates:
     *  Constant: '<S690>/Constant5'
     *  Constant: '<S690>/Constant6'
     *  RelationalOperator: '<S690>/Relational Operator3'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_p = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_p =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb;
    }

    /* End of Switch: '<S690>/Switch2' */
  }

  /* MultiPortSwitch: '<S690>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S690>/Multiport Switch' incorporates:
     *  Constant: '<S690>/Constant2'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S690>/Multiport Switch' incorporates:
     *  Constant: '<S690>/Constant3'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S690>/Multiport Switch' incorporates:
     *  Delay: '<S690>/Delay'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_p;
    break;
  }

  /* End of MultiPortSwitch: '<S690>/Multiport Switch' */

  /* RelationalOperator: '<S711>/Relational Operator3' incorporates:
   *  Constant: '<S711>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator10_df =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S711>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_cr = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator10_df,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_f);

  /* End of Outputs for SubSystem: '<S711>/Lib_RiseEdgeDet' */

  /* Logic: '<S711>/Logical Operator' incorporates:
   *  Constant: '<S711>/Constant'
   *  Constant: '<S711>/Constant1'
   *  RelationalOperator: '<S711>/Relational Operator'
   *  RelationalOperator: '<S711>/Relational Operator1'
   *  RelationalOperator: '<S711>/Relational Operator2'
   */
  DoorLckCtl_ParkUnlck = ((DoorLckCtl_ParkAutoUnlockSetFb == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && DoorLckCtl_DriverDoorLckSw &&
    DoorLckCtl_VehStop && rtb_LogicalOperator_cr);

  /* UnitDelay: '<S766>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S712>/Relational Operator'
   */
  rtb_RelationalOperator10_df = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->ThermalrunawaySta;

  /* Logic: '<S712>/Logical Operator2' incorporates:
   *  Constant: '<S712>/Constant1'
   *  Constant: '<S712>/Constant2'
   *  Logic: '<S712>/Logical Operator'
   *  Logic: '<S712>/Logical Operator1'
   *  RelationalOperator: '<S712>/Relational Operator1'
   *  RelationalOperator: '<S712>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ba = (rtb_RelationalOperator10_df &&
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) || ((AppSwcBcm_ARID_DEF.UnitDelay2 ==
    2) && DoorLckCtl_VehStop)));

  /* Chart: '<S712>/Chart' incorporates:
   *  SubSystem: '<S719>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ba,
    &AppSwcBcm_ARID_DEF.LogicalOperator_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jz);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_o) {
    AppSwcBcm_ARID_DEF.Flg_hw = true;
    DoorLckCtl_ThermRunawayUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_g = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_hw) {
    if (AppSwcBcm_ARID_DEF.Cnt_g >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_g >= 20) {
        DoorLckCtl_ThermRunawayUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_hw = false;
      } else {
        DoorLckCtl_ThermRunawayUnlck = false;
        tmp = AppSwcBcm_ARID_DEF.Cnt_g + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_g + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_g = (uint16)tmp;
      }
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_g + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_g + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_g = (uint16)tmp;
    }
  } else {
    DoorLckCtl_ThermRunawayUnlck = false;
  }

  /* Logic: '<S685>/Logical Operator' */
  DoorLckCtl_InsUnlck = (DoorLckCtl_HUUnLck || DoorLckCtl_ParkUnlck ||
    DoorLckCtl_ThermRunawayUnlck || DoorLckCtl_CrshUnlck);

  /* RelationalOperator: '<S756>/Relational Operator' incorporates:
   *  Constant: '<S756>/Constant'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ci = (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 1);

  /* Logic: '<S756>/Logical Operator4' incorporates:
   *  Constant: '<S756>/Constant1'
   *  Constant: '<S756>/Constant2'
   *  Constant: '<S756>/Constant3'
   *  Constant: '<S756>/Constant4'
   *  Constant: '<S756>/Constant5'
   *  Constant: '<S756>/Constant6'
   *  Logic: '<S756>/Logical Operator'
   *  Logic: '<S756>/Logical Operator1'
   *  Logic: '<S756>/Logical Operator2'
   *  Logic: '<S756>/Logical Operator3'
   *  RelationalOperator: '<S756>/Relational Operator1'
   *  RelationalOperator: '<S756>/Relational Operator2'
   *  RelationalOperator: '<S756>/Relational Operator3'
   *  RelationalOperator: '<S756>/Relational Operator4'
   *  RelationalOperator: '<S756>/Relational Operator5'
   *  RelationalOperator: '<S756>/Relational Operator6'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_RelationalOperator10_df = (AppSwcBcm_ARID_DEF.Lib_blIn_ci &&
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) ||
     (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
       (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
       (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2)) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 2))));

  /* Outputs for Atomic SubSystem: '<S756>/Lib_RiseEdgeDet' */
  /* Logic: '<S763>/Logical Operator' incorporates:
   *  Logic: '<S763>/Logical Operator1'
   *  UnitDelay: '<S763>/Unit Delay'
   */
  DoorLckCtl_RKEUnlck = (rtb_RelationalOperator10_df &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_la));

  /* Update for UnitDelay: '<S763>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_la = rtb_RelationalOperator10_df;

  /* End of Outputs for SubSystem: '<S756>/Lib_RiseEdgeDet' */

  /* UnitDelay: '<S766>/Unit Delay' incorporates:
   *  Constant: '<S755>/Constant5'
   *  RelationalOperator: '<S755>/Relational Operator7'
   */
  rtb_RelationalOperator10_df = (AppSwcBcm_ARID_DEF.UnitDelay2 == 2);

  /* Logic: '<S755>/Logical Operator1' incorporates:
   *  Constant: '<S755>/Constant2'
   *  Constant: '<S755>/Constant3'
   *  Constant: '<S755>/Constant4'
   *  Constant: '<S755>/Constant7'
   *  Constant: '<S755>/Constant8'
   *  Logic: '<S755>/Logical Operator2'
   *  Logic: '<S755>/Logical Operator3'
   *  Logic: '<S755>/Logical Operator4'
   *  Logic: '<S755>/Logical Operator5'
   *  Logic: '<S755>/Logical Operator6'
   *  RelationalOperator: '<S755>/Relational Operator1'
   *  RelationalOperator: '<S755>/Relational Operator2'
   *  RelationalOperator: '<S755>/Relational Operator3'
   *  RelationalOperator: '<S755>/Relational Operator4'
   *  RelationalOperator: '<S755>/Relational Operator5'
   *  RelationalOperator: '<S755>/Relational Operator6'
   *  RelationalOperator: '<S755>/Relational Operator8'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  DoorLckCtl_PEUnlck = (rtb_LogicalOperator_kt && DoorLckCtl_DriverDoorLckSw &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0)) ||
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) &&
     rtb_RelationalOperator10_df) || (rtb_RelationalOperator10_df &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2))));

  /* RelationalOperator: '<S759>/Relational Operator4' incorporates:
   *  Constant: '<S759>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator10_df = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->UnlckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S759>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_ii = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator10_df,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_b);

  /* End of Outputs for SubSystem: '<S759>/Lib_RiseEdgeDet' */

  /* Delay: '<S683>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_i) {
    /* Switch: '<S683>/Switch1' incorporates:
     *  Constant: '<S683>/Constant7'
     *  Constant: '<S683>/Constant8'
     *  RelationalOperator: '<S683>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_h = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_h =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts;
    }

    /* End of Switch: '<S683>/Switch1' */
  }

  /* Switch: '<S683>/Switch' incorporates:
   *  Constant: '<S683>/Constant5'
   *  RelationalOperator: '<S683>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S683>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndUnlckSts_enum;
  } else {
    /* Switch: '<S683>/Switch' incorporates:
     *  Constant: '<S683>/Constant6'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S683>/Switch' */

  /* MultiPortSwitch: '<S683>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S683>/Multiport Switch' incorporates:
     *  Constant: '<S683>/Constant1'
     */
    DoorLckCtl_IllmndUnlockSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S683>/Multiport Switch' incorporates:
     *  Constant: '<S683>/Constant2'
     */
    DoorLckCtl_IllmndUnlockSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S683>/Multiport Switch' incorporates:
     *  Delay: '<S683>/Delay'
     */
    DoorLckCtl_IllmndUnlockSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_h;
    break;
  }

  /* End of MultiPortSwitch: '<S683>/Multiport Switch' */

  /* MultiPortSwitch: '<S683>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndUnlockSts) {
   case 1:
    /* MultiPortSwitch: '<S683>/Multiport Switch1' incorporates:
     *  Constant: '<S683>/Constant3'
     */
    DoorLckCtl_IllmndUnlockStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S683>/Multiport Switch1' incorporates:
     *  Constant: '<S683>/Constant4'
     */
    DoorLckCtl_IllmndUnlockStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S683>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S683>/Unit Delay'
     */
    DoorLckCtl_IllmndUnlockStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ps;
    break;
  }

  /* End of MultiPortSwitch: '<S683>/Multiport Switch1' */

  /* Logic: '<S759>/Logical Operator1' incorporates:
   *  Constant: '<S759>/Constant1'
   *  Constant: '<S759>/Constant4'
   *  Constant: '<S759>/Constant5'
   *  Constant: '<S759>/Constant8'
   *  Logic: '<S759>/Logical Operator'
   *  RelationalOperator: '<S759>/Relational Operator'
   *  RelationalOperator: '<S759>/Relational Operator1'
   *  RelationalOperator: '<S759>/Relational Operator2'
   *  RelationalOperator: '<S759>/Relational Operator3'
   *  RelationalOperator: '<S759>/Relational Operator5'
   */
  DoorLckCtl_WelcomeUnlck = (rtb_LogicalOperator_ii &&
    (DoorLckCtl_DriverDoorLckSw && (DoorLckCtl_IllmndUnlockStsFb == 1) &&
     (DoorLckCtl_EEIlluminatedEntrySys == 1) && (AppSwcBcm_ARID_DEF.UnitDelay2 ==
    0) && (DoorLckCtl_IllmndSts == 1)));

  /* Delay: '<S761>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_in) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_hh = rtb_RelationalOperator2_c5;
  }

  /* Chart: '<S754>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S754>/Constant'
   *  Constant: '<S754>/Constant40'
   *  Constant: '<S754>/Constant41'
   *  Constant: '<S754>/Constant42'
   *  Logic: '<S754>/Logical Operator1'
   *  RelationalOperator: '<S754>/Relational Operator1'
   *  RelationalOperator: '<S754>/Relational Operator2'
   *  RelationalOperator: '<S754>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1_h((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 50,
    DoorLckCtl_Ts_C, true, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_b);

  /* Logic: '<S754>/Logical Operator' incorporates:
   *  Delay: '<S761>/Delay'
   *  Logic: '<S761>/Logical Operator'
   *  Logic: '<S761>/Logical Operator1'
   */
  DoorLckCtl_MechUnlck = (rtb_RelationalOperator2_c5 &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_hh) && AppSwcBcm_ARID_DEF.LIB_bErrFlg_b);

  /* UnitDelay: '<S766>/Unit Delay' incorporates:
   *  Constant: '<S757>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S757>/Relational Operator'
   */
  rtb_RelationalOperator10_df = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC
    ())->VIPM_TBoxRmtLck_enum == 2);

  /* Logic: '<S757>/Logical Operator3' incorporates:
   *  Constant: '<S757>/Constant1'
   *  Constant: '<S757>/Constant2'
   *  Constant: '<S757>/Constant3'
   *  Constant: '<S757>/Constant4'
   *  Constant: '<S757>/Constant5'
   *  Logic: '<S757>/Logical Operator'
   *  Logic: '<S757>/Logical Operator1'
   *  Logic: '<S757>/Logical Operator2'
   *  RelationalOperator: '<S757>/Relational Operator1'
   *  RelationalOperator: '<S757>/Relational Operator2'
   *  RelationalOperator: '<S757>/Relational Operator3'
   *  RelationalOperator: '<S757>/Relational Operator4'
   *  RelationalOperator: '<S757>/Relational Operator5'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_RelationalOperator10_df = (rtb_RelationalOperator10_df &&
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) || ((AppSwcBcm_ARID_DEF.UnitDelay2 ==
    2) && ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2) ||
           (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
           (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5)))));

  /* Outputs for Atomic SubSystem: '<S757>/Lib_RiseEdgeDet' */
  /* Logic: '<S766>/Logical Operator' incorporates:
   *  Logic: '<S766>/Logical Operator1'
   *  UnitDelay: '<S766>/Unit Delay'
   */
  DoorLckCtl_TboxUnlck = (rtb_RelationalOperator10_df &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kp));

  /* Update for UnitDelay: '<S766>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kp = rtb_RelationalOperator10_df;

  /* End of Outputs for SubSystem: '<S757>/Lib_RiseEdgeDet' */

  /* Logic: '<S688>/Logical Operator' */
  DoorLckCtl_OsUnlck = (DoorLckCtl_RKEUnlck || DoorLckCtl_PEUnlck ||
                        DoorLckCtl_WelcomeUnlck || DoorLckCtl_MechUnlck ||
                        DoorLckCtl_TboxUnlck);

  /* Logic: '<S686>/Logical Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_o = (DoorLckCtl_InsLck || DoorLckCtl_OsLck ||
    DoorLckCtl_InsUnlck || DoorLckCtl_OsUnlck || DoorLckCtl_TrunkUnlck);

  /* Chart: '<S686>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S722>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_o,
    &AppSwcBcm_ARID_DEF.LogicalOperator_li,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_bj);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_li) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ni + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ni + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_ni = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_e = 0U;

    /* LIB_blOut=0; */
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_e + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_e + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_e = (uint16)tmp;
  }

  /* Constant: '<S686>/Constant' */
  if (AppSwcBcm_ARID_DEF.Cnt2_e >= DoorLckCtl_CntSubTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ni - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ni - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_ni = (uint16)tmp;
  }

  /* End of Constant: '<S686>/Constant' */

  /* Constant: '<S686>/Constant1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_io = (AppSwcBcm_ARID_DEF.Cnt_ni >=
    DoorLckCtl_MotorWorkMax_C);

  /* Chart: '<S686>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S722>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_io,
    &AppSwcBcm_ARID_DEF.LogicalOperator_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_e);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_n) {
    AppSwcBcm_ARID_DEF.LIB_blOut_nq = true;
    AppSwcBcm_ARID_DEF.Cnt3 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.LIB_blOut_nq) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3 = (uint16)tmp;
  }

  /* Constant: '<S686>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt3 >= DoorLckCtl_MotorProtTimMax_C) {
    AppSwcBcm_ARID_DEF.LIB_blOut_nq = false;
    AppSwcBcm_ARID_DEF.Cnt_ni = 0U;
    AppSwcBcm_ARID_DEF.Cnt2_e = 0U;
    AppSwcBcm_ARID_DEF.Cnt3 = 0U;
  }

  /* End of Constant: '<S686>/Constant2' */

  /* Switch: '<S686>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  DoorLckCtl_MotorProt = ((!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->CrashSta) && AppSwcBcm_ARID_DEF.LIB_blOut_nq);

  /* Chart: '<S692>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c12_DoorLckCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c12_DoorLckCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Init1;
    DoorLckCtl_RemoteLockFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib) {
     case AppSwcBcm_IN_Fail1:
      DoorLckCtl_RemoteLockFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_i >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Init1;
        DoorLckCtl_RemoteLockFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_i = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_i = (uint8)tmp;
      }
      break;

     case AppSwcBcm_IN_Init1:
      DoorLckCtl_RemoteLockFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_a =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtLck_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtLck_enum == 2));

      /* Outputs for Function Call SubSystem: '<S776>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_a,
        &AppSwcBcm_ARID_DEF.LogicalOperator_cx,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dy);

      /* End of Outputs for SubSystem: '<S776>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_cx) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Wait1;
      }
      break;

     case AppSwcBcm_IN_Suc1:
      DoorLckCtl_RemoteLockFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_i >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Init1;
        DoorLckCtl_RemoteLockFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_i = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_i = (uint8)tmp;
      }
      break;

     default:
      /* case IN_Wait1: */
      if (DoorLckCtl_TboxLck || DoorLckCtl_TboxUnlck ||
          DoorLckCtl_TrunkTboxUnlck) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Suc1;
        DoorLckCtl_RemoteLockFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_i = (uint8)tmp;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_TBoxRmtLck_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Fail1;
        DoorLckCtl_RemoteLockFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_i = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S692>/Chart' */

  /* Chart: '<S756>/ClearRKECommd' incorporates:
   *  SubSystem: '<S762>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_ci,
    &AppSwcBcm_ARID_DEF.LogicalOperator_eo,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nu);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_eo) {
    AppSwcBcm_ARID_DEF.flg_bz = true;
    AppSwcBcm_ARID_DEF.Cnt_l4 = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_l4 - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_l4 - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_l4 = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_bz && (AppSwcBcm_ARID_DEF.Cnt_l4 == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_bz = false;
  }

  /* Chart: '<S673>/ClearRKECommd1' */
  if (DoorLckCtl_TrunkUnlck) {
    AppSwcBcm_ARID_DEF.flg_gp = true;
    AppSwcBcm_ARID_DEF.Cnt_dz = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_dz - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_dz - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_dz = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_gp && (AppSwcBcm_ARID_DEF.Cnt_dz == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_gp = false;
  }

  /* End of Chart: '<S673>/ClearRKECommd1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_i3 = rtb_RelationalOperator;

  /* Chart: '<S730>/ClearRKECommd' incorporates:
   *  SubSystem: '<S742>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_i3,
    &AppSwcBcm_ARID_DEF.LogicalOperator_lq,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_bn);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_lq) {
    AppSwcBcm_ARID_DEF.flg_m = true;
    AppSwcBcm_ARID_DEF.Cnt_ib = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_ib - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_ib - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_ib = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_m && (AppSwcBcm_ARID_DEF.Cnt_ib == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_m = false;
  }

  /* Update for Delay: '<S741>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a4 = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_e = rtb_LogicalOperator5_jv;

  /* Update for Delay: '<S682>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE = DoorLckCtl_IllmndLckSts;

  /* Update for UnitDelay: '<S682>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = DoorLckCtl_IllmndLckStsFb;

  /* Update for Delay: '<S748>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_o = AppSwcBcm_ARID_DEF.UnitDelay1;

  /* Update for UnitDelay: '<S750>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cp = rtb_LogicalOperator1_ex;

  /* Update for UnitDelay: '<S702>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e1 = rtb_LogicalOperator1_kf;

  /* Update for Delay: '<S690>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_p = DoorLckCtl_ParkAutoUnlockSetFb;

  /* Update for Delay: '<S683>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_h = DoorLckCtl_IllmndUnlockSts;

  /* Update for UnitDelay: '<S683>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ps = DoorLckCtl_IllmndUnlockStsFb;

  /* Update for Delay: '<S761>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_in = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_hh = rtb_RelationalOperator2_c5;
}

/* ConstCode for atomic system: '<S639>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Const(void)
{
  /* ConstCode for Constant: '<S691>/Constant8' */
  DoorLckCtl_SpdCtlLckSet = 1U;
}

/* Output and update for atomic system: '<S639>/SignalProcess' */
static void AppSwcBcm_SignalProcess_n(void)
{
  uint16 rtb_Switch12_d;
  uint16 tmp;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_jh;
  boolean rtb_Switch1;

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift1' */
  /* Constant: '<S677>/Constant5' */
  rtb_Switch12_d = AppSwcBcm_BitShift4(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift1' */

  /* Switch: '<S677>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND1'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch1' incorporates:
     *  Constant: '<S677>/Constant4'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarFLVal_C;
  } else {
    /* Switch: '<S677>/Switch1' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion1'
     */
    rtb_Switch1 = (BSW_J321DoorAjarFL != 0);
  }

  /* End of Switch: '<S677>/Switch1' */

  /* Chart: '<S677>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S677>/Constant1'
   *  Constant: '<S677>/Constant2'
   *  Constant: '<S677>/Constant3'
   *  DataTypeConversion: '<S677>/Data Type Conversion17'
   */
  if (!AppSwcBcm_ARID_DEF.flg_gs) {
    DoorLckCtl_DoorAjarFLSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarFLSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_gs = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hl >= (float32)
         DoorLckCtl_DoorAjarFLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hl++;
      AppSwcBcm_ARID_DEF.cnt_heal_o = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hl = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_o >= (float32)
        DoorLckCtl_DoorAjarFLTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarFLSw = false;
    } else if (DoorLckCtl_DoorAjarFLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_o++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift2' */
  /* Constant: '<S677>/Constant10' */
  rtb_Switch12_d = AppSwcBcm_BitShift7(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift2' */

  /* Switch: '<S677>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND2'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch2' incorporates:
     *  Constant: '<S677>/Constant9'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarFRVal_C;
  } else {
    /* Switch: '<S677>/Switch2' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion2'
     */
    rtb_Switch1 = (BSW_J310DoorAjarFR != 0);
  }

  /* End of Switch: '<S677>/Switch2' */

  /* Chart: '<S677>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S677>/Constant6'
   *  Constant: '<S677>/Constant7'
   *  Constant: '<S677>/Constant8'
   *  DataTypeConversion: '<S677>/Data Type Conversion16'
   */
  if (!AppSwcBcm_ARID_DEF.flg_k) {
    DoorLckCtl_DoorAjarFRSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarFRSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_k = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c4 >= (float32)
         DoorLckCtl_DoorAjarFRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c4++;
      AppSwcBcm_ARID_DEF.cnt_heal_a = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c4 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a >= (float32)
        DoorLckCtl_DoorAjarFRTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarFRSw = false;
    } else if (DoorLckCtl_DoorAjarFRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift5' */
  /* Constant: '<S677>/Constant59' */
  rtb_Switch12_d = AppSwcBcm_BitShift3(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift5' */

  /* Switch: '<S677>/Switch5' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND5'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch5' incorporates:
     *  Constant: '<S677>/Constant60'
     */
    rtb_Switch1 = DoorLckCtl_DriverDoorLckVal_C;
  } else {
    /* Switch: '<S677>/Switch5' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion5'
     */
    rtb_Switch1 = (BSW_J335DriverDoorLck != 0);
  }

  /* End of Switch: '<S677>/Switch5' */

  /* Chart: '<S677>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S677>/Constant46'
   *  Constant: '<S677>/Constant47'
   *  Constant: '<S677>/Constant49'
   *  DataTypeConversion: '<S677>/Data Type Conversion18'
   */
  if (!AppSwcBcm_ARID_DEF.flg_h) {
    DoorLckCtl_DriverDoorLckSw =
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DriverDoorLckSw != 0);
    AppSwcBcm_ARID_DEF.flg_h = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l >= (float32)
         DoorLckCtl_DriverDoorLckTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DriverDoorLckTimValid_C != 0xFFFF)) {
      DoorLckCtl_DriverDoorLckSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l++;
      AppSwcBcm_ARID_DEF.cnt_heal_c = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c >= (float32)
        DoorLckCtl_DriverDoorLckTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DriverDoorLckSw = false;
    } else if (DoorLckCtl_DriverDoorLckTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_c++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift3' */
  /* Constant: '<S677>/Constant11' */
  rtb_Switch12_d = AppSwcBcm_BitShift1_k(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift3' */

  /* Switch: '<S677>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND3'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch3' incorporates:
     *  Constant: '<S677>/Constant12'
     */
    rtb_Switch1 = DoorLckCtl_DrvPEVal_C;
  } else {
    /* Switch: '<S677>/Switch3' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion3'
     *  Logic: '<S677>/Logical Operator6'
     */
    rtb_Switch1 = (BSW_J338DrvPE == 0);
  }

  /* End of Switch: '<S677>/Switch3' */

  /* Chart: '<S677>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S677>/Constant25'
   *  Constant: '<S677>/Constant26'
   *  Constant: '<S677>/Constant27'
   *  Constant: '<S677>/Constant77'
   */
  if (!AppSwcBcm_ARID_DEF.flg_b) {
    DoorLckCtl_DrvPESw = false;
    AppSwcBcm_ARID_DEF.flg_b = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_kr >= (float32)DoorLckCtl_DrvPETimValid_C
         / (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_DrvPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_DrvPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_kr++;
      AppSwcBcm_ARID_DEF.cnt_heal_d = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_kr = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d >= (float32)DoorLckCtl_DrvPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DrvPESw = false;
    } else if (DoorLckCtl_DrvPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_d++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift4' */
  /* Constant: '<S677>/Constant13' */
  rtb_Switch12_d = AppSwcBcm_BitShift2(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift4' */

  /* Switch: '<S677>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND4'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch4' incorporates:
     *  Constant: '<S677>/Constant14'
     */
    rtb_Switch1 = DoorLckCtl_PsgPEVal_C;
  } else {
    /* Switch: '<S677>/Switch4' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion4'
     *  Logic: '<S677>/Logical Operator7'
     */
    rtb_Switch1 = (BSW_J337PsgPE == 0);
  }

  /* End of Switch: '<S677>/Switch4' */

  /* Chart: '<S677>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S677>/Constant28'
   *  Constant: '<S677>/Constant29'
   *  Constant: '<S677>/Constant30'
   *  Constant: '<S677>/Constant78'
   */
  if (!AppSwcBcm_ARID_DEF.flg_g) {
    DoorLckCtl_PsgPESw = false;
    AppSwcBcm_ARID_DEF.flg_g = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_h >= (float32)DoorLckCtl_PsgPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_PsgPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_h++;
      AppSwcBcm_ARID_DEF.cnt_heal_e0 = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_h = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e0 >= (float32)DoorLckCtl_PsgPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_PsgPESw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_e0++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift6' */
  /* Constant: '<S677>/Constant15' */
  rtb_Switch12_d = AppSwcBcm_BitShift8(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift6' */

  /* Switch: '<S677>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND6'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch6' incorporates:
     *  Constant: '<S677>/Constant16'
     */
    rtb_Switch1 = DoorLckCtl_TrunkSwVal_C;
  } else {
    /* Switch: '<S677>/Switch6' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion6'
     */
    rtb_Switch1 = (BSW_J336Trunk != 0);
  }

  /* End of Switch: '<S677>/Switch6' */

  /* Chart: '<S677>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S677>/Constant31'
   *  Constant: '<S677>/Constant32'
   *  Constant: '<S677>/Constant33'
   *  DataTypeConversion: '<S677>/Data Type Conversion15'
   */
  if (!AppSwcBcm_ARID_DEF.flg_ew) {
    DoorLckCtl_TrunkSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkSw != 0);
    AppSwcBcm_ARID_DEF.flg_ew = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o >= (float32)DoorLckCtl_PsgPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_TrunkSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o++;
      AppSwcBcm_ARID_DEF.cnt_heal_b = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_b >= (float32)DoorLckCtl_PsgPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_TrunkSw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_b++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift7' */
  /* Constant: '<S677>/Constant17' */
  rtb_Switch12_d = AppSwcBcm_BitShift9(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift7' */

  /* Switch: '<S677>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND7'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch7' incorporates:
     *  Constant: '<S677>/Constant18'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarRLVal_C;
  } else {
    /* Switch: '<S677>/Switch7' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion7'
     */
    rtb_Switch1 = (BSW_J320DoorAjarRL != 0);
  }

  /* End of Switch: '<S677>/Switch7' */

  /* Chart: '<S677>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S677>/Constant34'
   *  Constant: '<S677>/Constant35'
   *  Constant: '<S677>/Constant36'
   *  DataTypeConversion: '<S677>/Data Type Conversion14'
   */
  if (!AppSwcBcm_ARID_DEF.flg_p) {
    DoorLckCtl_DoorAjarRLSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarRLSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_p = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_m >= (float32)
         DoorLckCtl_DoorAjarRLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m++;
      AppSwcBcm_ARID_DEF.cnt_heal_hg = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hg >= (float32)
        DoorLckCtl_DoorAjarRLTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarRLSw = false;
    } else if (DoorLckCtl_DoorAjarRLTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hg++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift8' */
  /* Constant: '<S677>/Constant19' */
  rtb_Switch12_d = AppSwcBcm_BitShift3_d(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift8' */

  /* Switch: '<S677>/Switch8' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND8'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch8' incorporates:
     *  Constant: '<S677>/Constant20'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarRRVal_C;
  } else {
    /* Switch: '<S677>/Switch8' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion8'
     */
    rtb_Switch1 = (BSW_J36DoorAjarRR != 0);
  }

  /* End of Switch: '<S677>/Switch8' */

  /* Chart: '<S677>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S677>/Constant37'
   *  Constant: '<S677>/Constant38'
   *  Constant: '<S677>/Constant39'
   *  DataTypeConversion: '<S677>/Data Type Conversion13'
   */
  if (!AppSwcBcm_ARID_DEF.flg_e) {
    DoorLckCtl_DoorAjarRRSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarRRSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_e = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_pl >= (float32)
         DoorLckCtl_DoorAjarRRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_pl++;
      AppSwcBcm_ARID_DEF.cnt_heal_ew = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_pl = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ew >= (float32)
        DoorLckCtl_DoorAjarRRTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarRRSw = false;
    } else if (DoorLckCtl_DoorAjarRRTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ew++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms7' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift9' */
  /* Constant: '<S677>/Constant21' */
  rtb_Switch12_d = AppSwcBcm_BitShift10_b(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift9' */

  /* Switch: '<S677>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND9'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    /* Switch: '<S677>/Switch9' incorporates:
     *  Constant: '<S677>/Constant22'
     */
    rtb_Switch1 = DoorLckCtl_TrunkAjarVal_C;
  } else {
    /* Switch: '<S677>/Switch9' incorporates:
     *  DataTypeConversion: '<S677>/Data Type Conversion9'
     */
    rtb_Switch1 = (BSW_J37TrunkAjar != 0);
  }

  /* End of Switch: '<S677>/Switch9' */

  /* Chart: '<S677>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S677>/Constant40'
   *  Constant: '<S677>/Constant41'
   *  Constant: '<S677>/Constant42'
   *  DataTypeConversion: '<S677>/Data Type Conversion12'
   */
  if (!AppSwcBcm_ARID_DEF.flg) {
    DoorLckCtl_TrunkAjarSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkAjarSw != 0);
    AppSwcBcm_ARID_DEF.flg = true;
  }

  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c >= (float32)
         DoorLckCtl_TrunkAjarTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_TrunkAjarTimValid_C != 0xFFFF)) {
      DoorLckCtl_TrunkAjarSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c++;
      AppSwcBcm_ARID_DEF.cnt_heal_h = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h >= (float32)
        DoorLckCtl_TrunkAjarTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_TrunkAjarSw = false;
    } else if (DoorLckCtl_TrunkAjarTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_h++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift12' */
  /* Constant: '<S677>/Constant62' */
  rtb_Switch12_d = AppSwcBcm_BitShift11_p(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S677>/Bit Shift12' */

  /* Switch: '<S677>/Switch12' incorporates:
   *  Constant: '<S677>/Constant63'
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND12'
   */
  if ((rtb_Switch12_d & 1U) != 0U) {
    tmp = DoorLckCtl_DrvSeatResisVal_C;
  } else {
    tmp = BSW_J112DrvSeatResis;
  }

  /* Chart: '<S677>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S677>/Constant64'
   *  Constant: '<S677>/Constant65'
   *  Constant: '<S677>/Constant66'
   *  Constant: '<S677>/Constant67'
   *  DataTypeConversion: '<S677>/Data Type Conversion'
   *  RelationalOperator: '<S677>/Relational Operator6'
   *  Switch: '<S677>/Switch12'
   */
  if (!AppSwcBcm_ARID_DEF.flg_j) {
    DoorLckCtl_DrvSeatSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DrvSeatSw != 0);
    AppSwcBcm_ARID_DEF.flg_j = true;
  }

  if (tmp <= DoorLckCtl_DrvSeatResisMin_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_a >= (float32)
         DoorLckCtl_DrvSeatTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DrvSeatTimValid_C != 0xFFFF)) {
      DoorLckCtl_DrvSeatSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_a++;
      AppSwcBcm_ARID_DEF.cnt_heal_p = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_a = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_p >= (float32)DoorLckCtl_DrvSeatTimInValid_C
        / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DrvSeatSw = false;
    } else if (DoorLckCtl_DrvSeatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_p++;
    }
  }

  /* End of Chart: '<S677>/LIB_TPD_10ms11' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift13' */
  /* Switch: '<S677>/Switch13' incorporates:
   *  Constant: '<S677>/Constant71'
   *  Constant: '<S677>/Constant72'
   *  MATLAB Function: '<S781>/bit_shift'
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND13'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 12 & 1U) != 0U) {
    DoorLckCtl_EEKeyEntry = DoorLckCtl_EEKeyEntry_C;
  } else {
    DoorLckCtl_EEKeyEntry = BSW_EEKeyEntry;
  }

  /* End of Switch: '<S677>/Switch13' */
  /* End of Outputs for SubSystem: '<S677>/Bit Shift13' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift14' */
  /* Switch: '<S677>/Switch14' incorporates:
   *  Constant: '<S677>/Constant73'
   *  Constant: '<S677>/Constant74'
   *  MATLAB Function: '<S782>/bit_shift'
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND14'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 13 & 1U) != 0U) {
    DoorLckCtl_EEIlluminatedEntrySys = DoorLckCtl_EEIlluminatedEntrySys_C;
  } else {
    DoorLckCtl_EEIlluminatedEntrySys = BSW_EEIlluminatedEntrySys;
  }

  /* End of Switch: '<S677>/Switch14' */
  /* End of Outputs for SubSystem: '<S677>/Bit Shift14' */

  /* Outputs for Atomic SubSystem: '<S677>/Bit Shift15' */
  /* Switch: '<S677>/Switch15' incorporates:
   *  Constant: '<S677>/Constant75'
   *  Constant: '<S677>/Constant76'
   *  MATLAB Function: '<S783>/bit_shift'
   *  S-Function (sfix_bitop): '<S677>/Bitwise AND15'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 14 & 1U) != 0U) {
    DoorLckCtl_IllmndSts = DoorLckCtl_IllmndSts_C;
  } else {
    DoorLckCtl_IllmndSts = BSW_IllmndSts;
  }

  /* End of Switch: '<S677>/Switch15' */
  /* End of Outputs for SubSystem: '<S677>/Bit Shift15' */

  /* Abs: '<S677>/Abs' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  DoorLckCtl_VehSpd = (float32)fabs
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())->VIPC_VehSpd_kph);

  /* RelationalOperator: '<S677>/Relational Operator' incorporates:
   *  Constant: '<S677>/Constant'
   */
  rtb_RelationalOperator = (DoorLckCtl_VehSpd < 3.0F);

  /* RelationalOperator: '<S677>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_jh =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())->VIPC_VehSpdVld_flg;

  /* RelationalOperator: '<S677>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S677>/Relational Operator2'
   */
  rtb_Switch1 = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehSpdVld_flg;

  /* Logic: '<S677>/Logical Operator1' incorporates:
   *  Logic: '<S677>/Logical Operator'
   */
  DoorLckCtl_VehStop = ((rtb_RelationalOperator && rtb_RelationalOperator1_jh) ||
                        rtb_Switch1);

  /* Logic: '<S677>/Logical Operator4' incorporates:
   *  Logic: '<S677>/Logical Operator2'
   *  Logic: '<S677>/Logical Operator3'
   */
  DoorLckCtl_VehRun = ((!rtb_RelationalOperator) && rtb_RelationalOperator1_jh);

  /* RelationalOperator: '<S677>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_Switch1 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehSpdVld_flg;

  /* Switch: '<S677>/Switch' incorporates:
   *  Constant: '<S677>/Constant54'
   */
  if (!rtb_Switch1) {
    DoorLckCtl_VehSpd = 0.0F;
  }

  /* End of Switch: '<S677>/Switch' */
}

/* ConstCode for atomic system: '<S639>/SignalProcess' */
static void AppSwcBcm_SignalProcess_f_Const(void)
{
  /* ConstCode for Constant: '<S677>/Constant69' */
  DoorLckCtl_HoodAjarSw = true;
}

/* System initialize for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S639>/DoorDrv' */
  AppSwcBcm_DoorDrv_Init();

  /* SystemInitialize for Atomic SubSystem: '<S639>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Init();

  /* End of SystemInitialize for SubSystem: '<S639>/DoorLckCtlLogic' */
}

/* Outputs for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl(void)
{
  boolean rtb_DataTypeConversion1_lm;

  /* Outputs for Atomic SubSystem: '<S639>/SignalProcess' */
  AppSwcBcm_SignalProcess_n();

  /* End of Outputs for SubSystem: '<S639>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S639>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic();

  /* End of Outputs for SubSystem: '<S639>/DoorLckCtlLogic' */

  /* Chart: '<S639>/DoorDrv' */
  AppSwcBcm_DoorDrv();

  /* Outputs for Atomic SubSystem: '<S639>/Ovrd1' */
  /* Switch: '<S674>/Switch1' incorporates:
   *  Constant: '<S639>/Constant1'
   *  Constant: '<S639>/Constant2'
   *  Switch: '<S674>/Switch2'
   */
  if (DoorLckCtl_J54DoorLckOvrdFlg_C) {
    DoorLckCtl_J54DoorLck = DoorLckCtl_J54DoorLckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S639>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_lm = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->DoorLlckCtlFlg != 0);
    DoorLckCtl_J54DoorLck = (rtb_DataTypeConversion1_lm ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J54);
  }

  /* End of Switch: '<S674>/Switch1' */
  /* End of Outputs for SubSystem: '<S639>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S639>/Ovrd2' */
  /* Switch: '<S675>/Switch1' incorporates:
   *  Constant: '<S639>/Constant3'
   *  Constant: '<S639>/Constant4'
   *  Switch: '<S675>/Switch2'
   */
  if (DoorLckCtl_J511TrunkUnlckOvrdFlg_C) {
    DoorLckCtl_J511TrunkUnlck = DoorLckCtl_J511TrunkUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S639>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_lm = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->TrunkUnlckCtlFlg != 0);
    DoorLckCtl_J511TrunkUnlck = (rtb_DataTypeConversion1_lm ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J511);
  }

  /* End of Switch: '<S675>/Switch1' */
  /* End of Outputs for SubSystem: '<S639>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S639>/Ovrd3' */
  /* Switch: '<S676>/Switch1' incorporates:
   *  Constant: '<S639>/Constant18'
   *  Constant: '<S639>/Constant19'
   *  Switch: '<S676>/Switch2'
   */
  if (DoorLckCtl_J56DoorUnlckOvrdFlg_C) {
    DoorLckCtl_J56DoorUnlck = DoorLckCtl_J56DoorUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S639>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_lm = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->DoorUnlckCtlFlg != 0);
    DoorLckCtl_J56DoorUnlck = (rtb_DataTypeConversion1_lm ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J56);
  }

  /* End of Switch: '<S676>/Switch1' */
  /* End of Outputs for SubSystem: '<S639>/Ovrd3' */
}

/* ConstCode for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S639>/SignalProcess' */
  AppSwcBcm_SignalProcess_f_Const();

  /* End of ConstCode for SubSystem: '<S639>/SignalProcess' */

  /* ConstCode for Atomic SubSystem: '<S639>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Const();

  /* End of ConstCode for SubSystem: '<S639>/DoorLckCtlLogic' */
}

/* System initialize for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S847>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_m);

  /* SystemInitialize for Chart: '<S847>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut);
}

/* Output and update for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl(void)
{
  sint32 tmp;
  uint8 rtb_Switch;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator1_c;
  boolean rtb_RelationalOperator3_g;

  /* Chart: '<S847>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S847>/Constant6'
   *  RelationalOperator: '<S847>/Relational Operator'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(AppSwcBcm_ARID_DEF.BusCreator4.OsLck, 2,
    &AppSwcBcm_ARID_DEF.LIB_blOut,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay);

  /* RelationalOperator: '<S847>/Relational Operator1' incorporates:
   *  Constant: '<S847>/Constant1'
   */
  rtb_RelationalOperator1_c = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0);

  /* Logic: '<S847>/Logical Operator' incorporates:
   *  Constant: '<S847>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S847>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S847>/Relational Operator3' incorporates:
   *  Constant: '<S847>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_g =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S847>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_RelationalOperator3_g);

  /* SignalConversion: '<S847>/Signal Copy' incorporates:
   *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
   */
  ESCCtl_UnOrLockfeedback =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
     ())->VIPM_ESCLUnOrLockfeedback_nu;

  /* Switch: '<S853>/Switch' incorporates:
   *  Constant: '<S853>/Constant1'
   *  RelationalOperator: '<S853>/Relational Operator1'
   *  SignalConversion: '<S847>/Signal Copy'
   */
  if (ESCCtl_UnOrLockfeedback == 648518346341351424ULL) {
    /* Switch: '<S853>/Switch' incorporates:
     *  Constant: '<S853>/Constant2'
     */
    rtb_Switch = 2U;
  } else {
    /* Switch: '<S853>/Switch' incorporates:
     *  Constant: '<S853>/Constant'
     *  RelationalOperator: '<S853>/Relational Operator'
     */
    rtb_Switch = (uint8)(ESCCtl_UnOrLockfeedback == 1297036692682702848ULL);
  }

  /* End of Switch: '<S853>/Switch' */

  /* Logic: '<S847>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S847>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_e = (AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
    AppSwcBcm_ARID_DEF.LIB_blOut && rtb_RelationalOperator1_c &&
    rtb_LogicalOperator);

  /* Chart: '<S847>/ESCLLck' incorporates:
   *  SubSystem: '<S848>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_h(AppSwcBcm_ARID_DEF.Lib_blIn_e,
    &AppSwcBcm_ARID_DEF.LogicalOperator_bk,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_j);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_bk) {
    AppSwcBcm_ARID_DEF.Flg_p = true;
    AppSwcBcm_ARID_DEF.Cnt_n = 0U;
    ESCLCtl_J436Lck = true;
    AppSwcBcm_ARID_DEF.Cnt2_b = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_p) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_b + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_b + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_b = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_n >= ESCLCtl_LckDelay_C) {
      ESCLCtl_Lck = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_n++;
    }
  }

  if (rtb_Switch == 2) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_p = false;
    ESCLCtl_Lck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2_b >= ESCLCtl_LckTimMax_C) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_p = false;
    ESCLCtl_Lck = 0U;
  }

  /* Chart: '<S847>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S847>/Constant7'
   *  Constant: '<S847>/Constant8'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_RelationalOperator1_c, 5, 0.05F,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11);

  /* Logic: '<S847>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S847>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_i = (AppSwcBcm_ARID_DEF.BusCreator1.PwrOn &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_m && rtb_LogicalOperator &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* Chart: '<S847>/ESCLUnlck' incorporates:
   *  SubSystem: '<S849>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_h(AppSwcBcm_ARID_DEF.Lib_blIn_i,
    &AppSwcBcm_ARID_DEF.LogicalOperator_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_c) {
    AppSwcBcm_ARID_DEF.Flg_m = true;
    AppSwcBcm_ARID_DEF.Cnt_e = 0U;
    ESCLCtl_J436Unlck = true;
    AppSwcBcm_ARID_DEF.Cnt2 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_m) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2 = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_e >= ESCLCtl_UnlckDelay_C) {
      ESCLCtl_Unlck = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_e++;
    }
  }

  if (rtb_Switch == 1) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_m = false;
    ESCLCtl_Unlck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2 >= ESCLCtl_UnlckTimMax_C) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_m = false;
    ESCLCtl_Unlck = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S847>/Ovrd' */
  /* Switch: '<S852>/Switch' incorporates:
   *  Constant: '<S847>/Constant18'
   */
  if (ESCLCtl_J436PwrSupOvrdFlg_C) {
    /* Switch: '<S852>/Switch' incorporates:
     *  Constant: '<S847>/Constant19'
     */
    ESCLCtl_J436PwrSup = ESCLCtl_J436PwrSupOvrdVal_C;
  } else {
    /* Switch: '<S852>/Switch' incorporates:
     *  Logic: '<S847>/Logical Operator3'
     */
    ESCLCtl_J436PwrSup = (ESCLCtl_J436Lck || ESCLCtl_J436Unlck);
  }

  /* End of Switch: '<S852>/Switch' */
  /* End of Outputs for SubSystem: '<S847>/Ovrd' */

  /* Truth Table: '<S847>/Truth Table' */
  /*  Condition #1 */
  /*  Condition #2 */
  if (ESCLCtl_Unlck == 1) {
    /*  Example action 2 called from D3 column in condition table */
    ESCLCtl_UnOrLockCrtl = 1U;
  } else if (ESCLCtl_Lck == 2) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    ESCLCtl_UnOrLockCrtl = 2U;
  } else {
    /*  Default */
    ESCLCtl_UnOrLockCrtl = 0U;
  }

  /* End of Truth Table: '<S847>/Truth Table' */
}

/* System initialize for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl_Init(void)
{
  sint32 i;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for Chart: '<S642>/IMMOCtl' */
    AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i] = MAX_uint8_T;

    /* SystemInitialize for SignalConversion generated from: '<S642>/IMMOCtl' */
    IMMOCtl_AuthResp[i] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i];
  }

  for (i = 0; i < 16; i++) {
    /* SystemInitialize for SignalConversion generated from: '<S642>/IMMOCtl' */
    IMMOCtl_SKRead[i] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[i];
  }
}

/* Output and update for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl(void)
{
  sint32 exitg1;
  sint32 i_0;
  uint8 b_k;
  uint8 b_n;
  uint8 i;
  uint8 m;
  uint8 o;

  /* SignalConversion: '<S642>/Signal Conversion' incorporates:
   *  Inport: '<Root>/IPM_INV_IMMO_Req_EPT'
   */
  IMMOCtl_INVRandom[0] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngSubID_cnt;
  IMMOCtl_INVRandom[1] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngSts_enum;
  IMMOCtl_INVRandom[2] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngData02_nu;
  IMMOCtl_INVRandom[3] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngData03_nu;
  IMMOCtl_INVRandom[4] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngData04_nu;
  IMMOCtl_INVRandom[5] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngData05_nu;
  IMMOCtl_INVRandom[6] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngData06_nu;
  IMMOCtl_INVRandom[7] =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT()
    )->VIPM_INVLrngData07_nu;

  /* Chart: '<S642>/IMMOCtl' */
  BCM_SKRead((uint8 *)&AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[0], 16U);
  i = 0U;
  b_k = 0U;
  while (i < 16) {
    if ((AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[i] == 0xFF) ||
        (AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[i] == 0x00)) {
      i_0 = b_k + 1;
      if (b_k + 1 > 255) {
        i_0 = 255;
      }

      b_k = (uint8)i_0;
    }

    i++;
  }

  if (INV_IMMO_Req_EPT_Rec_callout() == 1) {
    i = 2U;
    m = 0U;
    b_n = 0U;
    o = 0U;
    while (i < 8) {
      if (IMMOCtl_INVRandom[i] == 0xFF) {
        i_0 = m + 1;
        if (m + 1 > 255) {
          i_0 = 255;
        }

        m = (uint8)i_0;
      }

      i++;
    }

    do {
      exitg1 = 0;
      if ((b_k != 16) && (m != 6)) {
        encipher(32U, (uint32 *)(uint8 *)&IMMOCtl_INVRandom[0], (uint32 *)
                 &AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[0]);
        while (b_n < 6) {
          AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[b_n + 2] = IMMOCtl_INVRandom[b_n];
          b_n++;
        }

        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[1] = (uint8)0xFF;
        exitg1 = 1;
      } else if (o < 8) {
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[o] = (uint8)0xFF;
        o++;
      } else {
        if (b_k == 16) {
          AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[1] = (uint8)0xF0;
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    BCM_IMMOAuthResp1_EPT_Send_Notication((uint8 *)
      &AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[0]);
    INV_IMMO_Req_EPT_Rec_ClaerFlg();
  }

  for (i_0 = 0; i_0 < 16; i_0++) {
    /* SignalConversion generated from: '<S642>/IMMOCtl' */
    IMMOCtl_SKRead[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[i_0];
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    /* SignalConversion generated from: '<S642>/IMMOCtl' */
    IMMOCtl_AuthResp[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i_0];
  }

  /* SignalConversion generated from: '<S642>/IMMOCtl' incorporates:
   *  Chart: '<S642>/IMMOCtl'
   */
  IMMOCtl_SKSta = (uint8)(b_k == 16);
}

/* Output and update for atomic system: '<S643>/Chart' */
static void AppSwcBcm_Chart(void)
{
  /* Chart: '<S643>/Chart' incorporates:
   *  UnitDelay: '<S643>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
    PDUCtl_SysPowerSts = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib) {
     case AppSwcBcm_IN_LocalOn:
      PDUCtl_SysPowerSts = 1U;
      if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k == 0) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
      }
      break;

     case AppSwcBcm_IN_OTA1On:
      AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
      PDUCtl_SysPowerSts = 0U;
      break;

     case AppSwcBcm_IN_OTAOn:
      AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
      PDUCtl_SysPowerSts = 0U;
      break;

     case AppSwcBcm_IN_PSOff:
      PDUCtl_SysPowerSts = 0U;
      if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k == 2) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      } else if (PDUCtl_RemtPwrOn) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_RemoteOn;
        PDUCtl_SysPowerSts = 2U;
      }
      break;

     default:
      /* case IN_RemoteOn: */
      PDUCtl_SysPowerSts = 2U;
      if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k == 0) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
      } else if (PDUCtl_KeyChk) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S643>/Chart' */
}

/* System initialize for atomic system: '<S643>/PwrOff' */
static void AppSwcBcm_PwrOff_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_d;

  /* SystemInitialize for Chart: '<S866>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_d);

  /* SystemInitialize for Chart: '<S866>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg);
}

/* Output and update for atomic system: '<S643>/PwrOff' */
static void AppSwcBcm_PwrOff(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_d;
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_h2p;
  boolean rtb_LogicalOperator2_aa;
  boolean rtb_LogicalOperator2_ls;
  boolean rtb_RelationalOperator11_f;
  boolean rtb_RelationalOperator4_kh;
  boolean rtb_RelationalOperator5_ky;

  /* Logic: '<S866>/Logical Operator' incorporates:
   *  Constant: '<S866>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S866>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S866>/Logical Operator1' incorporates:
   *  Constant: '<S866>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S866>/Relational Operator3'
   */
  rtb_LogicalOperator1_h2p =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S866>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator1_h2p);

  /* Logic: '<S866>/Logical Operator1' incorporates:
   *  Constant: '<S866>/Constant'
   *  Constant: '<S866>/Constant10'
   *  Constant: '<S866>/Constant11'
   *  Logic: '<S866>/Logical Operator7'
   *  RelationalOperator: '<S866>/Relational Operator'
   *  RelationalOperator: '<S866>/Relational Operator6'
   *  RelationalOperator: '<S866>/Relational Operator7'
   *  UnitDelay: '<S643>/Unit Delay2'
   *  UnitDelay: '<S643>/Unit Delay5'
   */
  rtb_LogicalOperator1_h2p = (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c == 2) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c == 1)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_c == 2) && rtb_LogicalOperator);

  /* RelationalOperator: '<S866>/Relational Operator11' */
  rtb_RelationalOperator11_f = !AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;

  /* Outputs for Atomic SubSystem: '<S866>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    &rtb_LogicalOperator2_aa, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet);

  /* End of Outputs for SubSystem: '<S866>/Lib_BothEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S866>/Lib_BothEdgeDet1' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    &rtb_LogicalOperator2_ls, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet1);

  /* End of Outputs for SubSystem: '<S866>/Lib_BothEdgeDet1' */

  /* Outputs for Atomic SubSystem: '<S866>/Lib_BothEdgeDet2' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_RelationalOperator4_kh, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet2);

  /* End of Outputs for SubSystem: '<S866>/Lib_BothEdgeDet2' */

  /* Outputs for Atomic SubSystem: '<S866>/Lib_BothEdgeDet3' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_RelationalOperator5_ky, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet3);

  /* End of Outputs for SubSystem: '<S866>/Lib_BothEdgeDet3' */

  /* Logic: '<S866>/Logical Operator2' incorporates:
   *  Logic: '<S866>/Logical Operator3'
   */
  rtb_RelationalOperator5_ky = ((!rtb_LogicalOperator2_aa) &&
    (!rtb_LogicalOperator2_ls) && (!rtb_RelationalOperator4_kh) &&
    (!rtb_RelationalOperator5_ky));

  /* RelationalOperator: '<S866>/Relational Operator4' incorporates:
   *  Constant: '<S866>/Constant17'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S866>/Relational Operator1'
   */
  rtb_RelationalOperator4_kh =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VIPC_VehHiddenMode_enum != 1);

  /* Chart: '<S866>/LIB_Tim' incorporates:
   *  Constant: '<S866>/Constant4'
   *  Constant: '<S866>/Constant5'
   *  Constant: '<S866>/Constant6'
   *  Constant: '<S866>/Constant7'
   *  Logic: '<S866>/Logical Operator4'
   *  RelationalOperator: '<S866>/Relational Operator12'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator11_f &&
      rtb_LogicalOperator1_h2p && rtb_RelationalOperator5_ky &&
      rtb_RelationalOperator4_kh) {
    if ((AppSwcBcm_ARID_DEF.Cnt_H_j >= PDUCtl_TimOutPwrOffH_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_M_b >= PDUCtl_TimOutPwrOffM_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_S_l >= PDUCtl_TimOutPwrOffS_C)) {
      PDUCtl_DelayTimPwrOff = true;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_Tick_p + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick_p + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_Tick_p = (uint16)tmp;
      PDUCtl_DelayTimPwrOff = false;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick_p >= 1.0F / PDUCtl_Ts_C) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_S_l + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_S_l + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_S_l = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_Tick_p = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_S_l >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_M_b + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_M_b + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_M_b = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_S_l = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_M_b >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_H_j + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_H_j + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_H_j = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_M_b = 0U;
      }
    }
  } else {
    PDUCtl_DelayTimPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_Tick_p = 0U;
    AppSwcBcm_ARID_DEF.Cnt_S_l = 0U;
    AppSwcBcm_ARID_DEF.Cnt_M_b = 0U;
    AppSwcBcm_ARID_DEF.Cnt_H_j = 0U;
  }

  /* End of Chart: '<S866>/LIB_Tim' */

  /* Chart: '<S866>/LIB_Tim1' incorporates:
   *  Constant: '<S866>/Constant25'
   *  Constant: '<S866>/Constant26'
   *  Constant: '<S866>/Constant27'
   *  Constant: '<S866>/Constant28'
   *  Constant: '<S866>/Constant29'
   *  Logic: '<S866>/Logical Operator14'
   *  Logic: '<S866>/Logical Operator15'
   *  RelationalOperator: '<S866>/Relational Operator16'
   *  UnitDelay: '<S643>/Unit Delay2'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c == 2) && (!PDUCtl_RemtPwrOn)) {
    if ((AppSwcBcm_ARID_DEF.Cnt_H >= PDUCtl_RemtTimOutPwrOffH_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_M >= PDUCtl_RemtTimOutPwrOffM_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_S >= PDUCtl_RemtTimOutPwrOffS_C)) {
      PDUCtl_RemtOverTimPwrOff = true;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_Tick + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_Tick = (uint16)tmp;
      PDUCtl_RemtOverTimPwrOff = false;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick >= 1.0F / PDUCtl_Ts_C) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_S + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_S + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_S = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_Tick = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_S >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_M + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_M + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_M = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_S = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_M >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_H + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_H + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_H = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_M = 0U;
      }
    }
  } else {
    PDUCtl_RemtOverTimPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_Tick = 0U;
    AppSwcBcm_ARID_DEF.Cnt_S = 0U;
    AppSwcBcm_ARID_DEF.Cnt_M = 0U;
    AppSwcBcm_ARID_DEF.Cnt_H = 0U;
  }

  /* End of Chart: '<S866>/LIB_Tim1' */

  /* Logic: '<S866>/Logical Operator12' incorporates:
   *  Constant: '<S866>/Constant23'
   *  Constant: '<S866>/Constant24'
   *  Logic: '<S882>/Logical Operator'
   *  Logic: '<S882>/Logical Operator1'
   *  RelationalOperator: '<S866>/Relational Operator14'
   *  RelationalOperator: '<S866>/Relational Operator15'
   *  UnitDelay: '<S643>/Unit Delay2'
   *  UnitDelay: '<S643>/Unit Delay5'
   *  UnitDelay: '<S882>/Unit Delay'
   */
  PDUCtl_RemtPwrOff = (AppSwcBcm_ConstB.RelationalOperator13 &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fq) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_c == 2) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c == 2));

  /* Chart: '<S866>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S866>/Constant19'
   *  Constant: '<S866>/Constant20'
   *  Constant: '<S866>/Constant21'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_LIB_TPD_10ms1((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HazardLightSw, PDUCtl_EmerPwrOffTimValid_C, PDUCtl_EmerPwrOffTimInValid_C,
    PDUCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts);

  /* Logic: '<S866>/Logical Operator13' incorporates:
   *  RelationalOperator: '<S866>/Relational Operator12'
   */
  PDUCtl_EmerPwrOff = (AppSwcBcm_ARID_DEF.LIB_bErrFlg &&
                       AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* RelationalOperator: '<S866>/Relational Operator18' incorporates:
   *  Constant: '<S866>/Constant31'
   */
  rtb_RelationalOperator4_kh = (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 1);

  /* Chart: '<S866>/LIB_PosPluse' incorporates:
   *  Constant: '<S866>/Constant33'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_LIB_PosPluse((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BrakeLightSw, PDUCtl_RemtPasvBrkSwTimValid_C, &rtb_LIB_blOut_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_p);

  /* Logic: '<S866>/Logical Operator16' incorporates:
   *  Constant: '<S866>/Constant30'
   *  Logic: '<S866>/Logical Operator17'
   *  Logic: '<S866>/Logical Operator18'
   *  Logic: '<S881>/Logical Operator'
   *  Logic: '<S881>/Logical Operator1'
   *  RelationalOperator: '<S866>/Relational Operator17'
   *  RelationalOperator: '<S866>/Relational Operator19'
   *  UnitDelay: '<S643>/Unit Delay2'
   *  UnitDelay: '<S881>/Unit Delay'
   */
  PDUCtl_RemtPasvPwrOff = ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c == 2) &&
    ((rtb_RelationalOperator4_kh && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kh)) ||
     (rtb_LIB_blOut_d && (!AppSwcBcm_ARID_DEF.LogicalOperator10))));

  /* Logic: '<S866>/Logical Operator5' incorporates:
   *  Constant: '<S866>/Constant12'
   *  Constant: '<S866>/Constant13'
   *  Constant: '<S866>/Constant14'
   *  Logic: '<S866>/Logical Operator10'
   *  Logic: '<S866>/Logical Operator11'
   *  Logic: '<S866>/Logical Operator9'
   *  RelationalOperator: '<S866>/Relational Operator10'
   *  RelationalOperator: '<S866>/Relational Operator12'
   *  RelationalOperator: '<S866>/Relational Operator4'
   *  RelationalOperator: '<S866>/Relational Operator8'
   *  RelationalOperator: '<S866>/Relational Operator9'
   *  UnitDelay: '<S643>/Unit Delay2'
   *  UnitDelay: '<S643>/Unit Delay5'
   */
  PDUCtl_OsLckPwrOff = (rtb_LogicalOperator && rtb_RelationalOperator11_f &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c != 3) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c != 5)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_c == 2)) &&
                        AppSwcBcm_ARID_DEF.BusCreator4.OsLck &&
                        (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) &&
                        AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* RelationalOperator: '<S866>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_ky = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUPwrOffReq_flg;

  /* Logic: '<S866>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S866>/Relational Operator12'
   */
  PDUCtl_HUPwrOff = (rtb_RelationalOperator5_ky &&
                     AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
                     rtb_LogicalOperator1_h2p);

  /* Logic: '<S866>/Logical Operator6' */
  PDUCtl_PwrOff = (PDUCtl_OsLckPwrOff || PDUCtl_HUPwrOff ||
                   PDUCtl_DelayTimPwrOff || PDUCtl_EmerPwrOff ||
                   PDUCtl_RemtPwrOff || PDUCtl_RemtOverTimPwrOff ||
                   PDUCtl_RemtPasvPwrOff);

  /* Update for UnitDelay: '<S882>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fq = AppSwcBcm_ConstB.RelationalOperator13;

  /* Update for UnitDelay: '<S881>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kh = rtb_RelationalOperator4_kh;
}

/*
 * Output and update for atomic system:
 *    '<S867>/Lib_FailEdgeDet'
 *    '<S867>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet_jv(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_c_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S885>/Logical Operator' incorporates:
   *  Logic: '<S885>/Logical Operator1'
   *  UnitDelay: '<S885>/Unit Delay'
   */
  rty_Lib_blOut_0 = ((!rtu_Lib_blIn) &&
                     AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S885>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* Output and update for atomic system: '<S643>/PwrOn' */
static void AppSwcBcm_PwrOn(void)
{
  sint32 tmp;
  boolean rtb_LIB_blOut_f;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator2_d5;
  boolean rtb_RelationalOperator2_eg;
  boolean rtb_RelationalOperator5_ap;

  /* Chart: '<S867>/BrkPwrOn' incorporates:
   *  Constant: '<S867>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S643>/Unit Delay4'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c7_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c7_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else if (AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib == AppSwcBcm_IN_Invalid) {
    AppSwcBcm_ARID_DEF.Lib_blIn_k =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw;

    /* Outputs for Function Call SubSystem: '<S883>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_k,
      &AppSwcBcm_ARID_DEF.LogicalOperator_b,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_n);

    /* End of Outputs for SubSystem: '<S883>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_b) {
      AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib = AppSwcBcm_IN_Valid;
      tmp = AppSwcBcm_ARID_DEF.Cnt_c + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_c + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_c = (uint16)tmp;
      AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;
    }

    /* case IN_Valid: */
  } else if ((!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw) ||
             (AppSwcBcm_ARID_DEF.Cnt_c > PDUCtl_PwrOnPSTimValid_C) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_aa) {
    AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt_c + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_c + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_c = (uint16)tmp;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;

    /* Lib_RiseEdgeDetInit(LampCtl_BrakeLightSw); */
  }

  /* End of Chart: '<S867>/BrkPwrOn' */

  /* RelationalOperator: '<S867>/Relational Operator5' incorporates:
   *  Constant: '<S867>/Constant8'
   */
  rtb_RelationalOperator5_ap = (AppSwcBcm_ARID_DEF.BusCreator14.SKSta == 1);

  /* Switch: '<S888>/Switch' incorporates:
   *  Constant: '<S867>/Constant10'
   *  Constant: '<S867>/Constant9'
   *  Logic: '<S867>/Logical Operator7'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    AppSwcBcm_ARID_DEF.LogicalOperator10 = PDUCtl_KeyValidOvrdVal_C;
  } else {
    /* RelationalOperator: '<S867>/Relational Operator2' incorporates:
     *  Constant: '<S867>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
     */
    rtb_RelationalOperator2_eg = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus
      ())->KeySta != 0);
    AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator2_eg ||
      rtb_RelationalOperator5_ap);
  }

  /* End of Switch: '<S888>/Switch' */

  /* Logic: '<S867>/Logical Operator5' */
  PDUCtl_KeyChk = (AppSwcBcm_ARID_DEF.BrkPwrOnValid &&
                   AppSwcBcm_ARID_DEF.LogicalOperator10);

  /* Logic: '<S867>/Logical Operator3' incorporates:
   *  Constant: '<S867>/Constant4'
   *  Constant: '<S867>/Constant5'
   *  RelationalOperator: '<S867>/Relational Operator'
   *  RelationalOperator: '<S867>/Relational Operator3'
   *  UnitDelay: '<S643>/Unit Delay'
   *  UnitDelay: '<S643>/Unit Delay1'
   */
  rtb_RelationalOperator2_eg = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_g == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j == 0));

  /* Logic: '<S867>/Logical Operator1' */
  PDUCtl_BrkPwrOn = (rtb_RelationalOperator2_eg && PDUCtl_KeyChk);

  /* RelationalOperator: '<S867>/Relational Operator4' incorporates:
   *  Constant: '<S867>/Constant'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_lv = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* RelationalOperator: '<S891>/Relational Operator2' incorporates:
   *  UnitDelay: '<S867>/Unit Delay'
   */
  rtb_RelationalOperator2_d5 = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fx;

  /* Logic: '<S867>/Logical Operator8' incorporates:
   *  Constant: '<S867>/Constant7'
   *  RelationalOperator: '<S867>/Relational Operator6'
   *  UnitDelay: '<S867>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_c = (AppSwcBcm_ARID_DEF.Lib_blIn_lv ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fx ||
    (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2));

  /* Chart: '<S867>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S884>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_c,
    &AppSwcBcm_ARID_DEF.LogicalOperator_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_g) {
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
    AppSwcBcm_ARID_DEF.Flg = false;
  }

  /* Chart: '<S867>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S884>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_lv,
    &AppSwcBcm_ARID_DEF.LogicalOperator_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_a) {
    AppSwcBcm_ARID_DEF.Flg = true;
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg) {
    /* Constant: '<S867>/Constant6' */
    if (AppSwcBcm_ARID_DEF.Cnt_d <= PDUCtl_OpenDoorPwrOnTimValid) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_d + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_d + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_d = (uint16)tmp;
      rtb_LIB_blOut_f = true;
    } else {
      rtb_LIB_blOut_f = false;
      AppSwcBcm_ARID_DEF.Flg = false;
    }

    /* End of Constant: '<S867>/Constant6' */
  } else {
    rtb_LIB_blOut_f = false;
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S867>/Lib_FailEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet_jv
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S867>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S867>/Lib_FailEdgeDet1' */
  rtb_RelationalOperator2_d5 = AppSwcBcm_Lib_FailEdgeDet_jv
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1);

  /* End of Outputs for SubSystem: '<S867>/Lib_FailEdgeDet1' */

  /* Switch: '<S889>/Switch' incorporates:
   *  Constant: '<S867>/Constant11'
   *  Constant: '<S867>/Constant12'
   *  Logic: '<S867>/Logical Operator6'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    rtb_RelationalOperator5_ap = PDUCtl_KeyValidOvrdVal_C;
  } else {
    rtb_RelationalOperator5_ap = (rtb_LIB_blOut_f || rtb_RelationalOperator5_ap);
  }

  /* Logic: '<S867>/Logical Operator' incorporates:
   *  Logic: '<S867>/Logical Operator4'
   *  Switch: '<S889>/Switch'
   */
  PDUCtl_OpenDoorPwrOn = (rtb_RelationalOperator5_ap &&
    (rtb_RelationalOperator2_d5 || rtb_LogicalOperator) &&
    rtb_RelationalOperator2_eg);

  /* Logic: '<S867>/Logical Operator9' incorporates:
   *  Constant: '<S867>/Constant14'
   *  Constant: '<S867>/Constant15'
   *  Logic: '<S887>/Logical Operator'
   *  Logic: '<S887>/Logical Operator1'
   *  RelationalOperator: '<S867>/Relational Operator8'
   *  RelationalOperator: '<S867>/Relational Operator9'
   *  UnitDelay: '<S643>/Unit Delay'
   *  UnitDelay: '<S887>/Unit Delay'
   */
  PDUCtl_RemtPwrOn = (AppSwcBcm_ConstB.RelationalOperator7 &&
                      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k4) &&
                      (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) &&
                      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j == 0));

  /* Logic: '<S867>/Logical Operator2' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fx = (PDUCtl_OpenDoorPwrOn ||
    PDUCtl_BrkPwrOn || PDUCtl_RemtPwrOn);

  /* Chart: '<S867>/RemoteLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Init_n;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib) {
     case AppSwcBcm_IN_Init_n:
      if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.RemotePwrLckSta != 1) {
        AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Unlck;
        PDUCtl_RemotePwrLckSta = 0U;
      } else if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.RemotePwrLckSta == 1) {
        AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Lck;
        PDUCtl_RemotePwrLckSta = 1U;
      }
      break;

     case AppSwcBcm_IN_Lck:
      PDUCtl_RemotePwrLckSta = 1U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRmtPwrLck_enum == 2) &&
          (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRmtPwrLckVld_flg) {
        AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Unlck;
        PDUCtl_RemotePwrLckSta = 0U;
      }
      break;

     default:
      /* case IN_Unlck: */
      PDUCtl_RemotePwrLckSta = 0U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRmtPwrLck_enum == 1) &&
          (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRmtPwrLckVld_flg) {
        AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Lck;
        PDUCtl_RemotePwrLckSta = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S867>/RemoteLck' */

  /* Logic: '<S867>/Logical Operator10' incorporates:
   *  Constant: '<S867>/Constant1'
   *  RelationalOperator: '<S867>/Relational Operator1'
   */
  PDUCtl_PwrOn = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fx &&
                  (PDUCtl_RemotePwrLckSta == 0));

  /* RelationalOperator: '<S891>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_ap = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLckVld_flg;

  /* RelationalOperator: '<S891>/Relational Operator2' incorporates:
   *  Constant: '<S891>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S891>/Relational Operator'
   */
  rtb_RelationalOperator2_d5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLck_enum == 1);

  /* Logic: '<S891>/Logical Operator' */
  rtb_RelationalOperator2_eg = (rtb_RelationalOperator2_d5 &&
    rtb_RelationalOperator5_ap);

  /* RelationalOperator: '<S891>/Relational Operator2' incorporates:
   *  Constant: '<S891>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_d5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLck_enum == 2);

  /* Switch: '<S891>/Switch' incorporates:
   *  Logic: '<S891>/Logical Operator1'
   *  Logic: '<S891>/Logical Operator2'
   */
  PDUCtl_RemotePwrLckFb = ((rtb_RelationalOperator2_d5 &&
    rtb_RelationalOperator5_ap) || rtb_RelationalOperator2_eg);

  /* Update for UnitDelay: '<S887>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k4 = AppSwcBcm_ConstB.RelationalOperator7;
}

/* Output and update for atomic system: '<S643>/RelayDig' */
static void AppSwcBcm_RelayDig(void)
{
  float32 tmp;
  boolean rtb_RelationalOperator3_ih;
  boolean rtb_RelationalOperator7_od;

  /* RelationalOperator: '<S868>/Relational Operator3' incorporates:
   *  Constant: '<S868>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S868>/Relational Operator2'
   */
  rtb_RelationalOperator3_ih =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* RelationalOperator: '<S868>/Relational Operator7' incorporates:
   *  Constant: '<S868>/Constant'
   *  Logic: '<S868>/Logical Operator'
   *  RelationalOperator: '<S868>/Relational Operator'
   */
  rtb_RelationalOperator7_od = ((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator3_ih);

  /* RelationalOperator: '<S868>/Relational Operator3' incorporates:
   *  Constant: '<S868>/Constant3'
   */
  rtb_RelationalOperator3_ih = (PDUCtl_SysPwrMode == 0);

  /* RelationalOperator: '<S868>/Relational Operator7' incorporates:
   *  Logic: '<S868>/Logical Operator1'
   */
  rtb_RelationalOperator7_od = (rtb_RelationalOperator3_ih ||
    rtb_RelationalOperator7_od);

  /* Chart: '<S868>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S868>/Constant6'
   *  Constant: '<S868>/Constant7'
   *  Logic: '<S868>/Logical Operator3'
   *  RelationalOperator: '<S868>/Relational Operator5'
   */
  if (rtb_RelationalOperator7_od && (PDUCtl_J437IG2RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller35)) {
    tmp = 50.0F / (PDUCtl_Ts_C * 100.0F);
    if (AppSwcBcm_ARID_DEF.cnt_defect_p >= tmp) {
      PDUCtl_IG2RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_p++;
      AppSwcBcm_ARID_DEF.cnt_heal_m = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_p = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m == 0) {
      PDUCtl_IG2RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_m--;
    }
  }

  /* End of Chart: '<S868>/LIB_TPD_10ms1' */

  /* Chart: '<S868>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S868>/Constant4'
   *  Constant: '<S868>/Constant5'
   *  Constant: '<S868>/Constant8'
   *  Logic: '<S868>/Logical Operator2'
   *  RelationalOperator: '<S868>/Relational Operator4'
   */
  if (rtb_RelationalOperator7_od && (PDUCtl_J421IG1RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller36)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_k >= 50.0F / (PDUCtl_Ts_C * 100.0F)) {
      PDUCtl_IG1RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k++;
      AppSwcBcm_ARID_DEF.cnt_heal_e = (uint16)(50.0F / (PDUCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e == 0) {
      PDUCtl_IG1RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_e--;
    }
  }

  /* End of Chart: '<S868>/LIB_TPD_10ms2' */

  /* Switch: '<S868>/Switch' incorporates:
   *  Logic: '<S868>/Logical Operator4'
   */
  PDUCtl_SysPwrModeV = ((!PDUCtl_IG1RelayFault) && (!PDUCtl_IG2RelayFault));

  /* Chart: '<S868>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S868>/Constant1'
   *  Constant: '<S868>/Constant12'
   *  Constant: '<S868>/Constant13'
   *  Constant: '<S868>/Constant14'
   *  Constant: '<S868>/Constant15'
   *  Constant: '<S868>/Constant16'
   *  Constant: '<S868>/Constant17'
   *  Constant: '<S868>/Constant18'
   *  Logic: '<S868>/Logical Operator5'
   *  Logic: '<S868>/Logical Operator6'
   *  Logic: '<S868>/Logical Operator7'
   *  RelationalOperator: '<S868>/Relational Operator1'
   *  RelationalOperator: '<S868>/Relational Operator6'
   *  RelationalOperator: '<S868>/Relational Operator7'
   *  RelationalOperator: '<S868>/Relational Operator8'
   *  RelationalOperator: '<S868>/Relational Operator9'
   */
  if (((AppSwcBcm_ARID_DEF.CCaller35 == 1) || (AppSwcBcm_ARID_DEF.CCaller36 == 1))
      && ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 2)) &&
      rtb_RelationalOperator3_ih) {
    if (AppSwcBcm_ARID_DEF.cnt_defect >= 50.0F / (PDUCtl_Ts_C * 100.0F)) {
      PDUCtl_IGRlyIlgCls = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect++;
      AppSwcBcm_ARID_DEF.cnt_heal = (uint16)(10.0F / (PDUCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal == 0) {
      PDUCtl_IGRlyIlgCls = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal--;
    }
  }

  /* End of Chart: '<S868>/LIB_TPD_10ms3' */
}

/* System initialize for atomic system: '<S643>/StartReq' */
static void AppSwcBcm_StartReq_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_b1;
  boolean rtb_LIB_blOut_is;

  /* SystemInitialize for Chart: '<S870>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_is);

  /* SystemInitialize for Chart: '<S870>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_b1);
}

/* Output and update for atomic system: '<S643>/StartReq' */
static void AppSwcBcm_StartReq(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_b1;
  boolean rtb_LIB_blOut_is;
  boolean rtb_LogicalOperator;
  boolean rtb_UnitDelay_fp;

  /* UnitDelay: '<S905>/Unit Delay' incorporates:
   *  Constant: '<S870>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S870>/Relational Operator1'
   */
  rtb_UnitDelay_fp = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                      ->VHVM_PTActOprtMode_enum != 2);

  /* Logic: '<S870>/Logical Operator' incorporates:
   *  Constant: '<S870>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S870>/Relational Operator3'
   */
  rtb_LogicalOperator = ((PDUCtl_SysPwrMode == 2) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw);

  /* Chart: '<S870>/LIB_PosPluse' incorporates:
   *  Constant: '<S870>/Constant4'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator, PDUCtl_StartReqTimValid_C,
    &rtb_LIB_blOut_is, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse);

  /* Logic: '<S870>/Logical Operator1' incorporates:
   *  Constant: '<S870>/Constant1'
   *  RelationalOperator: '<S870>/Relational Operator'
   *  RelationalOperator: '<S870>/Relational Operator2'
   *  RelationalOperator: '<S870>/Relational Operator7'
   */
  rtb_UnitDelay_fp = (PDUCtl_SysPwrModeV && PDUCtl_KeyChk && rtb_LIB_blOut_is &&
                      (PDUCtl_SysPowerSts == 1) && rtb_UnitDelay_fp);

  /* RelationalOperator: '<S870>/Relational Operator6' incorporates:
   *  Constant: '<S870>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S870>/Relational Operator5'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S870>/LIB_PosPluse1' incorporates:
   *  Constant: '<S870>/Constant5'
   *  Logic: '<S870>/Logical Operator3'
   *  UnitDelay: '<S870>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cn, PDUCtl_StartReqOverTimValid_C,
    &rtb_LIB_blOut_b1, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1);

  /* Outputs for Atomic SubSystem: '<S870>/Lib_SR' */
  /* Outputs for Atomic SubSystem: '<S870>/Lib_RiseEdgeDetHold' */
  /* Switch: '<S906>/Switch' incorporates:
   *  Constant: '<S870>/Constant6'
   *  Logic: '<S870>/Logical Operator2'
   *  Logic: '<S870>/Logical Operator4'
   *  Logic: '<S905>/Logical Operator'
   *  Logic: '<S905>/Logical Operator1'
   *  RelationalOperator: '<S870>/Relational Operator4'
   *  RelationalOperator: '<S870>/Relational Operator6'
   *  Switch: '<S907>/Switch'
   *  UnitDelay: '<S905>/Unit Delay'
   */
  if (((!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw) &&
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b &&
       (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) || (PDUCtl_SysPwrMode ==
       0) || rtb_LIB_blOut_b1) {
    /* Switch: '<S906>/Switch' incorporates:
     *  Constant: '<S906>/Constant'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c = false;

    /* Switch: '<S907>/Switch' incorporates:
     *  Constant: '<S907>/Constant'
     */
    PDUCtl_StartReq = false;
  } else {
    /* Switch: '<S906>/Switch' incorporates:
     *  Logic: '<S906>/Logical Operator'
     *  Logic: '<S906>/Logical Operator1'
     *  Logic: '<S906>/Logical Operator2'
     *  UnitDelay: '<S906>/Unit Delay'
     *  UnitDelay: '<S906>/Unit Delay1'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c = ((rtb_UnitDelay_fp &&
      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jx)) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c);

    /* Switch: '<S907>/Switch' incorporates:
     *  Logic: '<S907>/Logical Operator'
     *  UnitDelay: '<S907>/Unit Delay'
     */
    PDUCtl_StartReq = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c || PDUCtl_StartReq);
  }

  /* End of Switch: '<S906>/Switch' */
  /* End of Outputs for SubSystem: '<S870>/Lib_SR' */

  /* Update for UnitDelay: '<S906>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jx = rtb_UnitDelay_fp;

  /* End of Outputs for SubSystem: '<S870>/Lib_RiseEdgeDetHold' */

  /* Update for UnitDelay: '<S870>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cn = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S905>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;
}

/* Output and update for atomic system: '<S643>/Subsystem' */
static void AppSwcBcm_Subsystem(void)
{
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_ck;

  /* RelationalOperator: '<S871>/Relational Operator' incorporates:
   *  Constant: '<S871>/Constant'
   */
  rtb_RelationalOperator = (AppSwcBcm_ARID_DEF.CCaller36 == 1);

  /* RelationalOperator: '<S871>/Relational Operator1' incorporates:
   *  Constant: '<S871>/Constant1'
   */
  rtb_RelationalOperator1_ck = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* Switch: '<S871>/Switch' incorporates:
   *  Logic: '<S871>/Logical Operator'
   *  Logic: '<S871>/Logical Operator1'
   *  Logic: '<S871>/Logical Operator2'
   *  Logic: '<S871>/Logical Operator3'
   *  Switch: '<S871>/Switch1'
   */
  if (rtb_RelationalOperator && rtb_RelationalOperator1_ck) {
    /* Switch: '<S871>/Switch' incorporates:
     *  Constant: '<S871>/Constant2'
     */
    PDUCtl_SysPwrModeAct = 2U;
  } else if ((!rtb_RelationalOperator) && (!rtb_RelationalOperator1_ck)) {
    /* Switch: '<S871>/Switch1' incorporates:
     *  Constant: '<S871>/Constant3'
     *  Switch: '<S871>/Switch'
     */
    PDUCtl_SysPwrModeAct = 0U;
  }

  /* End of Switch: '<S871>/Switch' */
}

/* Output and update for atomic system: '<S643>/Truth Table' */
static void AppSwcBcm_TruthTable_n(void)
{
  /* UnitDelay: '<S863>/Unit Delay' */
  /*  Example condition 1 */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    AppSwcBcm_ARID_DEF.PDUCtl_J421 = 1U;
    AppSwcBcm_ARID_DEF.PDUCtl_J437 = 1U;
    PDUCtl_SysPwrMode = 2U;
  } else {
    /*  Default */
    /*  Example action 2 called from D3 column in condition table */
    AppSwcBcm_ARID_DEF.PDUCtl_J421 = 0U;
    AppSwcBcm_ARID_DEF.PDUCtl_J437 = 0U;
    PDUCtl_SysPwrMode = 0U;
  }

  /* End of UnitDelay: '<S863>/Unit Delay' */
}

/* System initialize for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S643>/PwrOff' */
  AppSwcBcm_PwrOff_Init();

  /* End of SystemInitialize for SubSystem: '<S643>/PwrOff' */

  /* SystemInitialize for Atomic SubSystem: '<S643>/StartReq' */
  AppSwcBcm_StartReq_Init();

  /* End of SystemInitialize for SubSystem: '<S643>/StartReq' */
}

/* Output and update for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion_i;

  /* Outputs for Atomic SubSystem: '<S643>/PwrOn' */
  AppSwcBcm_PwrOn();

  /* End of Outputs for SubSystem: '<S643>/PwrOn' */

  /* Chart: '<S643>/Chart' */
  AppSwcBcm_Chart();

  /* Outputs for Atomic SubSystem: '<S643>/PwrOff' */
  AppSwcBcm_PwrOff();

  /* End of Outputs for SubSystem: '<S643>/PwrOff' */

  /* Outputs for Atomic SubSystem: '<S643>/Lib_SR' */
  /* Switch: '<S863>/Switch' incorporates:
   *  Constant: '<S863>/Constant'
   *  Logic: '<S863>/Logical Operator'
   *  UnitDelay: '<S863>/Unit Delay'
   */
  if (PDUCtl_PwrOff) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh = (PDUCtl_PwrOn ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh);
  }

  /* End of Switch: '<S863>/Switch' */
  /* End of Outputs for SubSystem: '<S643>/Lib_SR' */

  /* Truth Table: '<S643>/Truth Table' */
  AppSwcBcm_TruthTable_n();

  /* Outputs for Atomic SubSystem: '<S643>/Ovrd1' */
  /* Switch: '<S864>/Switch1' incorporates:
   *  Constant: '<S643>/Constant18'
   *  Constant: '<S643>/Constant19'
   */
  if (PDUCtl_J421IG1RlyCtlOvrdFlg_C) {
    PDUCtl_J421IG1RlyCtl = (uint8)PDUCtl_J421IG1RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S643>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG1RlyCtlFlg != 0);

    /* Switch: '<S864>/Switch2' */
    if (rtb_DataTypeConversion_i) {
      PDUCtl_J421IG1RlyCtl = 1U;
    } else {
      PDUCtl_J421IG1RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J421;
    }

    /* End of Switch: '<S864>/Switch2' */
  }

  /* End of Switch: '<S864>/Switch1' */
  /* End of Outputs for SubSystem: '<S643>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S643>/Ovrd2' */
  /* Switch: '<S865>/Switch1' incorporates:
   *  Constant: '<S643>/Constant1'
   *  Constant: '<S643>/Constant2'
   */
  if (PDUCtl_J437IG2RlyCtlOvrdFlg_C) {
    PDUCtl_J437IG2RlyCtl = (uint8)PDUCtl_J437IG2RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S643>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG2RlyCtlFlg != 0);

    /* Switch: '<S865>/Switch2' */
    if (rtb_DataTypeConversion_i) {
      PDUCtl_J437IG2RlyCtl = 1U;
    } else {
      PDUCtl_J437IG2RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J437;
    }

    /* End of Switch: '<S865>/Switch2' */
  }

  /* End of Switch: '<S865>/Switch1' */
  /* End of Outputs for SubSystem: '<S643>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S643>/RelayDig' */
  AppSwcBcm_RelayDig();

  /* End of Outputs for SubSystem: '<S643>/RelayDig' */

  /* Outputs for Atomic SubSystem: '<S643>/StartReq' */
  AppSwcBcm_StartReq();

  /* End of Outputs for SubSystem: '<S643>/StartReq' */

  /* Chart: '<S643>/RemtPwrCtlFb' incorporates:
   *  Constant: '<S4>/Constant14'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c12_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c12_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Init_be;
    PDUCtl_RemtPwrCtlFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_ow = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib) {
     case AppSwcBcm_IN_Fail_g:
      PDUCtl_RemtPwrCtlFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_ow >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Init_be;
        PDUCtl_RemtPwrCtlFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_ow = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_ow++;
      }
      break;

     case AppSwcBcm_IN_Init_be:
      PDUCtl_RemtPwrCtlFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_l = false;

      /* Outputs for Function Call SubSystem: '<S869>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(false, &AppSwcBcm_ARID_DEF.LogicalOperator_h,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g);

      /* End of Outputs for SubSystem: '<S869>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_h) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Wait_l;
      }
      break;

     case AppSwcBcm_IN_Suc_c:
      PDUCtl_RemtPwrCtlFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_ow >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Init_be;
        PDUCtl_RemtPwrCtlFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_ow = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_ow++;
      }
      break;

     default:
      /* case IN_Wait: */
      if (PDUCtl_RemtPwrOff || PDUCtl_RemtPwrOn) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Suc_c;
        PDUCtl_RemtPwrCtlFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_ow + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_ow + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_ow = (uint8)tmp;
      } else {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Fail_g;
        PDUCtl_RemtPwrCtlFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_ow + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_ow + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_ow = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S643>/RemtPwrCtlFb' */

  /* Outputs for Atomic SubSystem: '<S643>/Subsystem' */
  AppSwcBcm_Subsystem();

  /* End of Outputs for SubSystem: '<S643>/Subsystem' */

  /* Update for UnitDelay: '<S643>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S643>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_g = PDUCtl_SysPowerSts;

  /* Update for UnitDelay: '<S643>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_aa = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S643>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S643>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_c = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S643>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c = PDUCtl_SysPowerSts;
}

/* System initialize for atomic system: '<S908>/NMCtl' */
static void AppSwcBcm_NMCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;

  /* InitializeConditions for Delay: '<S913>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = true;

  /* InitializeConditions for Delay: '<S914>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = true;

  /* InitializeConditions for Delay: '<S915>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a = true;

  /* InitializeConditions for Delay: '<S916>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = true;

  /* InitializeConditions for Delay: '<S917>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = true;

  /* SystemInitialize for Chart: '<S909>/LIB_NegPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_o);
}

/* Outputs for atomic system: '<S908>/NMCtl' */
static void AppSwcBcm_NMCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;
  sint32 tmp;
  boolean rtb_LIB_blOut_kz;
  boolean rtb_RelationalOperator15_eo;
  boolean rtb_RelationalOperator16_g;
  boolean rtb_RelationalOperator17_cs;
  boolean rtb_RelationalOperator18_m;
  boolean rtb_RelationalOperator1_lx;
  boolean rtb_RelationalOperator26;
  boolean rtb_RelationalOperator27;
  boolean rtb_RelationalOperator28;
  boolean rtb_RelationalOperator2_ak;

  /* RelationalOperator: '<S909>/Relational Operator26' incorporates:
   *  Constant: '<S909>/Constant28'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator26 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->RKEReq != 0);

  /* Delay: '<S913>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_j) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_fz =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S914>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_m) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_on =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Delay: '<S915>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_a) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_bd =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Delay: '<S916>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_g) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_br =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;
  }

  /* Delay: '<S917>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_b) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_g =
      AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;
  }

  /* RelationalOperator: '<S909>/Relational Operator27' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S919>/Logical Operator'
   *  Logic: '<S919>/Logical Operator1'
   *  UnitDelay: '<S919>/Unit Delay'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->BrakeLightSw && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a5));

  /* Logic: '<S909>/Logical Operator10' incorporates:
   *  Delay: '<S913>/Delay'
   *  Delay: '<S914>/Delay'
   *  Delay: '<S915>/Delay'
   *  Delay: '<S916>/Delay'
   *  Delay: '<S917>/Delay'
   *  Logic: '<S913>/Logical Operator1'
   *  Logic: '<S913>/Logical Operator2'
   *  Logic: '<S913>/Logical Operator3'
   *  Logic: '<S913>/Logical Operator4'
   *  Logic: '<S913>/Logical Operator5'
   *  Logic: '<S914>/Logical Operator1'
   *  Logic: '<S914>/Logical Operator2'
   *  Logic: '<S914>/Logical Operator3'
   *  Logic: '<S914>/Logical Operator4'
   *  Logic: '<S914>/Logical Operator5'
   *  Logic: '<S915>/Logical Operator1'
   *  Logic: '<S915>/Logical Operator2'
   *  Logic: '<S915>/Logical Operator3'
   *  Logic: '<S915>/Logical Operator4'
   *  Logic: '<S915>/Logical Operator5'
   *  Logic: '<S916>/Logical Operator1'
   *  Logic: '<S916>/Logical Operator2'
   *  Logic: '<S916>/Logical Operator3'
   *  Logic: '<S916>/Logical Operator4'
   *  Logic: '<S916>/Logical Operator5'
   *  Logic: '<S917>/Logical Operator1'
   *  Logic: '<S917>/Logical Operator2'
   *  Logic: '<S917>/Logical Operator3'
   *  Logic: '<S917>/Logical Operator4'
   *  Logic: '<S917>/Logical Operator5'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator26 ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_fz &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_fz))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_on &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_on))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_bd &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_bd))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_br &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_br))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_g &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_g))) || rtb_RelationalOperator27);

  /* RelationalOperator: '<S909>/Relational Operator27' incorporates:
   *  Constant: '<S909>/Constant29'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->DrvPEAuthentAcsd == 1);

  /* Logic: '<S909>/Logical Operator6' */
  AppSwcBcm_ARID_DEF.LogicalOperator6 = (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    rtb_RelationalOperator27);

  /* RelationalOperator: '<S909>/Relational Operator28' incorporates:
   *  Constant: '<S909>/Constant30'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator28 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->FRPEAuthentAcsd == 1);

  /* Logic: '<S909>/Logical Operator7' */
  AppSwcBcm_ARID_DEF.LogicalOperator7 = (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
    rtb_RelationalOperator28);

  /* Logic: '<S909>/Logical Operator9' incorporates:
   *  Logic: '<S920>/Logical Operator'
   *  Logic: '<S920>/Logical Operator1'
   *  Logic: '<S921>/Logical Operator'
   *  Logic: '<S921>/Logical Operator1'
   *  UnitDelay: '<S920>/Unit Delay'
   *  UnitDelay: '<S921>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.LogicalOperator6 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ly)) ||
    (AppSwcBcm_ARID_DEF.LogicalOperator7 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ey)));

  /* Chart: '<S909>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S911>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn,
    &AppSwcBcm_ARID_DEF.LogicalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet);
  if (AppSwcBcm_ARID_DEF.LogicalOperator) {
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* Logic: '<S909>/Logical Operator5' incorporates:
   *  Constant: '<S909>/Constant3'
   *  Constant: '<S909>/Constant4'
   *  Constant: '<S909>/Constant5'
   *  RelationalOperator: '<S909>/Relational Operator3'
   *  RelationalOperator: '<S909>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 0) ||
      (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3)) {
    if (AppSwcBcm_ARID_DEF.Cnt <= WakeUpCtl_WinCtlDelayTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt + 1;
      if (AppSwcBcm_ARID_DEF.Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt = (uint16)tmp;
      rtb_LIB_blOut_kz = false;
    } else {
      rtb_LIB_blOut_kz = true;
    }
  } else {
    rtb_LIB_blOut_kz = true;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* End of Logic: '<S909>/Logical Operator5' */

  /* RelationalOperator: '<S909>/Relational Operator15' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator15_eo = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BrakeLightSw;

  /* RelationalOperator: '<S909>/Relational Operator16' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator16_g = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->PosLampSta;

  /* RelationalOperator: '<S909>/Relational Operator17' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator17_cs = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->LowBeamSta;

  /* RelationalOperator: '<S909>/Relational Operator18' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator18_m = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HiBeamSta;

  /* RelationalOperator: '<S909>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_lx = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HazardLightSta;

  /* RelationalOperator: '<S909>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_ak = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->EmerHazardLightSta;

  /* Chart: '<S909>/LIB_NegPluse2' incorporates:
   *  Constant: '<S909>/Constant'
   *  Constant: '<S909>/Constant19'
   *  Constant: '<S909>/Constant22'
   *  Logic: '<S909>/Logical Operator'
   *  Logic: '<S909>/Logical Operator1'
   *  Logic: '<S909>/Logical Operator3'
   *  RelationalOperator: '<S909>/Relational Operator'
   *  RelationalOperator: '<S909>/Relational Operator19'
   *  RelationalOperator: '<S909>/Relational Operator20'
   *  RelationalOperator: '<S909>/Relational Operator21'
   */
  AppSwcBcm_LIB_PosPluse2((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
    rtb_RelationalOperator15_eo && rtb_RelationalOperator16_g &&
    rtb_RelationalOperator17_cs && rtb_RelationalOperator18_m &&
    (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 2) && rtb_LIB_blOut_kz &&
    ((!AppSwcBcm_ARID_DEF.BusCreator4.AutoLckSta) ||
     AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw) &&
    rtb_RelationalOperator1_lx && rtb_RelationalOperator2_ak,
    WakeUpCtl_CANSleepDelayTim_C, AppSwcBcm_ARID_DEF.Lib_blIn, &rtb_LIB_blOut_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse2);

  /* Logic: '<S909>/Logical Operator2' incorporates:
   *  Logic: '<S909>/Logical Operator11'
   *  Logic: '<S909>/Logical Operator12'
   *  Logic: '<S909>/Logical Operator4'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator2 = ((rtb_RelationalOperator26 &&
    AppSwcBcm_ARID_DEF.RelationalOperator14) ||
    AppSwcBcm_ARID_DEF.RelationalOperator1 ||
    AppSwcBcm_ARID_DEF.RelationalOperator5 ||
    AppSwcBcm_ARID_DEF.RelationalOperator6 ||
    AppSwcBcm_ARID_DEF.RelationalOperator7 ||
    AppSwcBcm_ARID_DEF.RelationalOperator8 ||
    AppSwcBcm_ARID_DEF.RelationalOperator4 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator9 && rtb_RelationalOperator27) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator10 && rtb_RelationalOperator28) ||
    AppSwcBcm_ARID_DEF.RelationalOperator12);

  /* Switch: '<S922>/Switch' */
  if (rtb_LIB_blOut_o) {
    /* Switch: '<S922>/Switch' incorporates:
     *  Constant: '<S922>/Constant'
     */
    WakeUpCtl_NMReq = false;
  } else {
    /* Switch: '<S922>/Switch' incorporates:
     *  Logic: '<S909>/Logical Operator8'
     *  Logic: '<S918>/Logical Operator'
     *  Logic: '<S918>/Logical Operator1'
     *  Logic: '<S922>/Logical Operator'
     *  UnitDelay: '<S918>/Unit Delay'
     *  UnitDelay: '<S922>/Unit Delay'
     */
    WakeUpCtl_NMReq = ((AppSwcBcm_ARID_DEF.LogicalOperator2 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d3)) ||
                       AppSwcBcm_ARID_DEF.Lib_blIn || WakeUpCtl_NMReq);
  }

  /* End of Switch: '<S922>/Switch' */
}

/* Update for atomic system: '<S908>/NMCtl' */
static void AppSwcBcm_NMCtl_Update(void)
{
  /* Update for Delay: '<S913>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_fz =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S914>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_on =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

  /* Update for Delay: '<S915>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_bd =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S916>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_br =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

  /* Update for Delay: '<S917>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_g = AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

  /* Update for UnitDelay: '<S919>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a5 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S920>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ly = AppSwcBcm_ARID_DEF.LogicalOperator6;

  /* Update for UnitDelay: '<S921>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ey = AppSwcBcm_ARID_DEF.LogicalOperator7;

  /* Update for UnitDelay: '<S918>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d3 = AppSwcBcm_ARID_DEF.LogicalOperator2;
}

/* System initialize for atomic system: '<S908>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;

  /* InitializeConditions for Delay: '<S928>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad = true;

  /* SystemInitialize for Chart: '<S910>/LIB_NegPluse1' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_k);
}

/* Outputs for atomic system: '<S908>/SleepCtl' */
static void AppSwcBcm_SleepCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator4_py;
  boolean rtb_LogicalOperator_p;

  /* Logic: '<S931>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S910>/Relational Operator24'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BoxLampSta;

  /* Logic: '<S910>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S910>/Relational Operator23'
   *  RelationalOperator: '<S910>/Relational Operator25'
   */
  rtb_LogicalOperator4_py = ((!WakeUpCtl_NMReq) && rtb_LogicalOperator &&
    (!AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr));

  /* RelationalOperator: '<S910>/Relational Operator29' incorporates:
   *  Constant: '<S910>/Constant31'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator29 = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S910>/Relational Operator30' incorporates:
   *  Constant: '<S910>/Constant32'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator30 = (AppSwcBcm_ARID_DEF.CCaller36 == 1);

  /* Delay: '<S928>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.icLoad) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;
  }

  /* Logic: '<S931>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S928>/Logical Operator1'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl;

  /* Logic: '<S930>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Delay: '<S928>/Delay'
   *  Logic: '<S928>/Logical Operator3'
   *  Logic: '<S928>/Logical Operator4'
   */
  rtb_LogicalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl && (!AppSwcBcm_ARID_DEF.Delay_DSTATE_b));

  /* Logic: '<S910>/Logical Operator13' incorporates:
   *  Delay: '<S928>/Delay'
   *  Logic: '<S928>/Logical Operator2'
   *  Logic: '<S928>/Logical Operator5'
   *  Logic: '<S930>/Logical Operator'
   *  Logic: '<S930>/Logical Operator1'
   *  Logic: '<S931>/Logical Operator'
   *  Logic: '<S931>/Logical Operator1'
   *  Logic: '<S932>/Logical Operator'
   *  Logic: '<S932>/Logical Operator1'
   *  Logic: '<S933>/Logical Operator'
   *  Logic: '<S933>/Logical Operator1'
   *  UnitDelay: '<S930>/Unit Delay'
   *  UnitDelay: '<S931>/Unit Delay'
   *  UnitDelay: '<S932>/Unit Delay'
   *  UnitDelay: '<S933>/Unit Delay'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator29 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e)) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator30 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kz)) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_b && rtb_LogicalOperator) ||
     rtb_LogicalOperator_p) || (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c)) ||
    (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du)));

  /* Chart: '<S910>/LIB_NegPluse1' incorporates:
   *  Constant: '<S910>/Constant27'
   */
  AppSwcBcm_LIB_PosPluse2(rtb_LogicalOperator4_py,
    WakeUpCtl_LocalSleepDelayTim_C, rtb_LogicalOperator, &rtb_LIB_blOut_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse1);

  /* Logic: '<S910>/Logical Operator3' */
  AppSwcBcm_ARID_DEF.LogicalOperator3 = (AppSwcBcm_ARID_DEF.RelationalOperator14
    || AppSwcBcm_ARID_DEF.RelationalOperator1 ||
    AppSwcBcm_ARID_DEF.RelationalOperator5 ||
    AppSwcBcm_ARID_DEF.RelationalOperator6 ||
    AppSwcBcm_ARID_DEF.RelationalOperator7 ||
    AppSwcBcm_ARID_DEF.RelationalOperator8 ||
    AppSwcBcm_ARID_DEF.RelationalOperator4 ||
    AppSwcBcm_ARID_DEF.RelationalOperator9 ||
    AppSwcBcm_ARID_DEF.RelationalOperator10 ||
    AppSwcBcm_ARID_DEF.RelationalOperator22 ||
    AppSwcBcm_ARID_DEF.RelationalOperator12);

  /* Switch: '<S934>/Switch' incorporates:
   *  Constant: '<S934>/Constant'
   *  Logic: '<S910>/Logical Operator14'
   *  Logic: '<S929>/Logical Operator'
   *  Logic: '<S929>/Logical Operator1'
   *  Logic: '<S934>/Logical Operator'
   *  UnitDelay: '<S929>/Unit Delay'
   *  UnitDelay: '<S934>/Unit Delay'
   */
  if (rtb_LIB_blOut_k) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1 = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1 =
      ((AppSwcBcm_ARID_DEF.LogicalOperator3 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_an)) || rtb_LogicalOperator ||
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1);
  }

  /* End of Switch: '<S934>/Switch' */

  /* Logic: '<S910>/Logical Operator5' incorporates:
   *  UnitDelay: '<S934>/Unit Delay'
   */
  WakeUpCtl_SleepAllwd = !AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1;
}

/* Update for atomic system: '<S908>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Update(void)
{
  /* Update for UnitDelay: '<S932>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e =
    AppSwcBcm_ARID_DEF.RelationalOperator29;

  /* Update for UnitDelay: '<S933>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kz =
    AppSwcBcm_ARID_DEF.RelationalOperator30;

  /* Update for Delay: '<S928>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.icLoad = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;

  /* Update for UnitDelay: '<S930>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c = AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw;

  /* Update for UnitDelay: '<S931>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du =
    AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw;

  /* Update for UnitDelay: '<S929>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_an = AppSwcBcm_ARID_DEF.LogicalOperator3;
}

/* System initialize for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S908>/NMCtl' */
  AppSwcBcm_NMCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S908>/NMCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S908>/SleepCtl' */
  AppSwcBcm_SleepCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S908>/SleepCtl' */
}

/* Outputs for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl(void)
{
  /* SignalConversion: '<S644>/Signal Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  BSW_WakeupReas = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VBSW_WakeupReasn_enum;

  /* RelationalOperator: '<S908>/Relational Operator14' incorporates:
   *  Constant: '<S908>/Constant14'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator14 = (BSW_WakeupReas == 49);

  /* RelationalOperator: '<S908>/Relational Operator1' incorporates:
   *  Constant: '<S908>/Constant1'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator1 = (BSW_WakeupReas == 54);

  /* RelationalOperator: '<S908>/Relational Operator5' incorporates:
   *  Constant: '<S908>/Constant5'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator5 = (BSW_WakeupReas == 58);

  /* RelationalOperator: '<S908>/Relational Operator6' incorporates:
   *  Constant: '<S908>/Constant6'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator6 = (BSW_WakeupReas == 59);

  /* RelationalOperator: '<S908>/Relational Operator7' incorporates:
   *  Constant: '<S908>/Constant7'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator7 = (BSW_WakeupReas == 61);

  /* RelationalOperator: '<S908>/Relational Operator8' incorporates:
   *  Constant: '<S908>/Constant8'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8 = (BSW_WakeupReas == 62);

  /* RelationalOperator: '<S908>/Relational Operator4' incorporates:
   *  Constant: '<S908>/Constant4'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4 = (BSW_WakeupReas == 57);

  /* RelationalOperator: '<S908>/Relational Operator9' incorporates:
   *  Constant: '<S908>/Constant9'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9 = (BSW_WakeupReas == 63);

  /* RelationalOperator: '<S908>/Relational Operator10' incorporates:
   *  Constant: '<S908>/Constant10'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator10 = (BSW_WakeupReas == 64);

  /* RelationalOperator: '<S908>/Relational Operator13' incorporates:
   *  Constant: '<S908>/Constant13'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 17);

  /* Outputs for Atomic SubSystem: '<S908>/NMCtl' */
  AppSwcBcm_NMCtl();

  /* End of Outputs for SubSystem: '<S908>/NMCtl' */

  /* RelationalOperator: '<S908>/Relational Operator12' incorporates:
   *  Constant: '<S908>/Constant12'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 66);

  /* RelationalOperator: '<S908>/Relational Operator22' incorporates:
   *  Constant: '<S908>/Constant23'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator22 = (BSW_WakeupReas == 50);

  /* Outputs for Atomic SubSystem: '<S908>/SleepCtl' */
  AppSwcBcm_SleepCtl();

  /* End of Outputs for SubSystem: '<S908>/SleepCtl' */
}

/* Update for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S908>/NMCtl' */
  AppSwcBcm_NMCtl_Update();

  /* End of Update for SubSystem: '<S908>/NMCtl' */

  /* Update for Atomic SubSystem: '<S908>/SleepCtl' */
  AppSwcBcm_SleepCtl_Update();

  /* End of Update for SubSystem: '<S908>/SleepCtl' */
}

/* Model step function for TID1 */
void Runbl_AppSwcBcm_10ms(void)        /* Explicit Task: Runbl_AppSwcBcm_10ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_10ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_10ms'
   */
  /* Outputs for Atomic SubSystem: '<S2>/PEPSCtl' */
  AppSwcBcm_PEPSCtl();

  /* End of Outputs for SubSystem: '<S2>/PEPSCtl' */

  /* BusCreator: '<S2>/Bus Creator10' */
  AppSwcBcm_ARID_DEF.BusCreator10.KeyInCarSta = PEPSCtl_KeyInCarSta;
  AppSwcBcm_ARID_DEF.BusCreator10.FRPEAuthentAcsd = PEPSCtl_FRPEAuthentAcsd;
  AppSwcBcm_ARID_DEF.BusCreator10.DrvPEAuthentAcsd = PEPSCtl_DrvPEAuthentAcsd;
  AppSwcBcm_ARID_DEF.BusCreator10.AvaluebleKeyInCar = PEPSCtl_AvaluebleKeyInCar;
  AppSwcBcm_ARID_DEF.BusCreator10.PSAuthentRes = PEPSCtl_PSAuthentRes;
  AppSwcBcm_ARID_DEF.BusCreator10.WarnNoKeyFound = PEPSCtl_WarnNoKeyFound;
  AppSwcBcm_ARID_DEF.BusCreator10.KeySta = PEPSCtl_KeySta;
  AppSwcBcm_ARID_DEF.BusCreator10.IndicationKeyCloser =
    PEPSCtl_IndicationKeyCloser;
  AppSwcBcm_ARID_DEF.BusCreator10.UnlckWlcmReq = PEPSCtl_UnlckWlcmReq;
  AppSwcBcm_ARID_DEF.BusCreator10.LckWlcmReq = PEPSCtl_LckWlcmReq;
  AppSwcBcm_ARID_DEF.BusCreator10.FrbdnKeyNr = PEPSCtl_FrbdnKeyNr;
  AppSwcBcm_ARID_DEF.BusCreator10.KeyLoBattLvlWarn = PEPSCtl_KeyLoBattLvlWarn;
  AppSwcBcm_ARID_DEF.BusCreator10.WarnKeyOutReminder =
    PEPSCtl_WarnKeyOutReminder;
  AppSwcBcm_ARID_DEF.BusCreator10.PSReq = PEPSCtl_PSReq;
  AppSwcBcm_ARID_DEF.BusCreator10.IMMOKey = PEPSCtl_IMMOKey;

  /* Update for Atomic SubSystem: '<S2>/PEPSCtl' */
  AppSwcBcm_PEPSCtl_Update();

  /* End of Update for SubSystem: '<S2>/PEPSCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_10ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_10ms_PEPSCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator10);
}

/* Model step function for TID2 */
void Runbl_AppSwcBcm_20ms(void)        /* Explicit Task: Runbl_AppSwcBcm_20ms */
{
  sint32 i;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.BatSaveCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.ESCLCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.RVMCtl_Bus = *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.SeatCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.IMMOCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SteerWhlCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.WakeUpCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WakeUpCtl_Bus();

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_20ms'
   */
  /* Outputs for Atomic SubSystem: '<S3>/EEReadCtl' */
  AppSwcBcm_EEReadCtl();

  /* End of Outputs for SubSystem: '<S3>/EEReadCtl' */

  /* BusCreator: '<S3>/Bus Creator12' */
  AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts = EEReadCtl_BodyWarnSts;
  AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb = EEReadCtl_FlwrMeHomeCtlFb;
  AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb = EEReadCtl_BackLadjvalFb;
  AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta = EEReadCtl_HazardLightSta;
  AppSwcBcm_ARID_DEF.BusCreator12.IllmndLckSts = EEReadCtl_IllmndLckSts;
  AppSwcBcm_ARID_DEF.BusCreator12.SpdCtlLckSet = EEReadCtl_SpdCtlLckSet;
  AppSwcBcm_ARID_DEF.BusCreator12.ParkAutoUnlockSetFb =
    EEReadCtl_ParkAutoUnlockSetFb;
  AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts = EEReadCtl_LockHoornOnSts;
  AppSwcBcm_ARID_DEF.BusCreator12.CrashSta = EEReadCtl_CrashSta;
  AppSwcBcm_ARID_DEF.BusCreator12.IllmndUnlckSts = EEReadCtl_IllmndUnlckSts;
  AppSwcBcm_ARID_DEF.BusCreator12.InrTim = EEReadCtl_InrTim;
  AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb =
    EEReadCtl_WiprIntlTimeSetFb;
  for (i = 0; i < 10; i++) {
    AppSwcBcm_ARID_DEF.BusCreator12.DoorOpRecord[i] = EEReadCtl_DoorOpRecord[i];
    AppSwcBcm_ARID_DEF.BusCreator12.LocalStartFailOpRecord[i] =
      EEReadCtl_LocalStartFailOpRecord[i];
    AppSwcBcm_ARID_DEF.BusCreator12.RemoteStartFailRecord[i] =
      EEReadCtl_RemoteStartFailRecord[i];
    AppSwcBcm_ARID_DEF.BusCreator12.TrunkOpRecord[i] = EEReadCtl_TrunkOpRecord[i];
  }

  AppSwcBcm_ARID_DEF.BusCreator12.TrunkLckSw = EEReadCtl_TrunkLckSw;
  AppSwcBcm_ARID_DEF.BusCreator12.DriverDoorLckSw = EEReadCtl_DriverDoorLckSw;
  AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarFLSw = EEReadCtl_DoorAjarFLSw;
  AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarFRSw = EEReadCtl_DoorAjarFRSw;
  AppSwcBcm_ARID_DEF.BusCreator12.TrunkSw = EEReadCtl_TrunkSw;
  AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarRLSw = EEReadCtl_DoorAjarRLSw;
  AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarRRSw = EEReadCtl_DoorAjarRRSw;
  AppSwcBcm_ARID_DEF.BusCreator12.TrunkAjarSw = EEReadCtl_TrunkAjarSw;
  AppSwcBcm_ARID_DEF.BusCreator12.DrvSeatSw = EEReadCtl_DrvSeatSw;
  AppSwcBcm_ARID_DEF.BusCreator12.RemotePwrLckSta = EEReadCtl_RemotePwrLckSta;

  /* End of BusCreator: '<S3>/Bus Creator12' */

  /* CCaller: '<S3>/C Caller31' */
  BSW_J319HornSw = GetHw_AlrmHornSw();

  /* SignalConversion generated from: '<S3>/IPM_HU_B_BAC' incorporates:
   *  Inport: '<Root>/IPM_HU_B_BAC'
   */
  AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC();

  /* CCaller: '<S3>/C Caller15' */
  BSW_CrashPWMSta = GetHw_CrashSig_Flag();

  /* CCaller: '<S3>/C Caller1' */
  BSW_FogLampFCfg = GetVehCfg_FrontFogLamp();

  /* CCaller: '<S3>/C Caller30' */
  BSW_J125LightIntst = GetHw_Lightlntst();

  /* CCaller: '<S3>/C Caller4' */
  BSW_J313BrakeLoSw = GetHw_BrkSwLo();

  /* CCaller: '<S3>/C Caller3' */
  BSW_J322FogLampF = GetHw_FrontFogLampSw();

  /* CCaller: '<S3>/C Caller33' */
  BSW_J339BrakeHiSw = GetHw_BrkSwHi();

  /* CCaller: '<S3>/C Caller13' */
  BSW_J346FogLampR = GetHw_RearFogLampSw();

  /* CCaller: '<S3>/C Caller32' */
  BSW_RKEReq = GetFobKeyCmdRequest();

  /* SignalConversion generated from: '<S3>/IPM_CCP_PanelStatus_BOD' incorporates:
   *  Inport: '<Root>/IPM_CCP_PanelStatus_BOD'
   */
  AppSwcBcm_ARID_DEF.IPM_CCP_PanelStatus_BOD_d =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
    ();

  /* SignalConversion generated from: '<S3>/IPM_ESC_7_FuncStatus_CHA' incorporates:
   *  Inport: '<Root>/IPM_ESC_7_FuncStatus_CHA'
   */
  AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
    ();

  /* SignalConversion generated from: '<S3>/Vcu2BcmTms_outputs' incorporates:
   *  Inport: '<Root>/Vcu2BcmTms_outputs'
   */
  AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs();

  /* Outputs for Atomic SubSystem: '<S3>/LampCtl' */
  AppSwcBcm_LampCtl();

  /* End of Outputs for SubSystem: '<S3>/LampCtl' */

  /* BusCreator: '<S3>/Bus Creator' */
  AppSwcBcm_ARID_DEF.BusCreator.PosLampSw = LampCtl_PosLampSw;
  AppSwcBcm_ARID_DEF.BusCreator.LowBeamSw = LampCtl_LowBeamSw;
  AppSwcBcm_ARID_DEF.BusCreator.HiBeamSw = LampCtl_HiBeamSw;
  AppSwcBcm_ARID_DEF.BusCreator.PassLightSw = LampCtl_PassLightSw;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSw = LampCtl_TurnIndcrLSw;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLaneLSw = LampCtl_TurnIndcrLaneLSw;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSw = LampCtl_TurnIndcrRSw;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLaneRSw = LampCtl_TurnIndcrLaneRSw;
  AppSwcBcm_ARID_DEF.BusCreator.FogLampRSw = LampCtl_FogLampRSw;
  AppSwcBcm_ARID_DEF.BusCreator.HazardLightSw = LampCtl_HazardLightSw;
  AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSw = LampCtl_BrakeLightSw;
  AppSwcBcm_ARID_DEF.BusCreator.LightIntstVal = LampCtl_LightIntstVal;
  AppSwcBcm_ARID_DEF.BusCreator.AutoLampSw = LampCtl_AutoLampSw;
  AppSwcBcm_ARID_DEF.BusCreator.PosLampSta = LampCtl_PosLampSta;
  AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta = LampCtl_DayRunLightSta;
  AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSta = LampCtl_BrakeLightSta;
  AppSwcBcm_ARID_DEF.BusCreator.BSDRightCtl = LampCtl_J420BSDRightCtl;
  AppSwcBcm_ARID_DEF.BusCreator.BSDLeftCtl = LampCtl_J422BSDLeftCtl;
  AppSwcBcm_ARID_DEF.BusCreator.LowBeamSta = LampCtl_LowBeamSta;
  AppSwcBcm_ARID_DEF.BusCreator.FogLampRSta = LampCtl_FogLampRSta;
  AppSwcBcm_ARID_DEF.BusCreator.ReverseLampSta = LampCtl_ReverseLampSta;
  AppSwcBcm_ARID_DEF.BusCreator.LightIntstSta = LampCtl_LightIntstSta;
  AppSwcBcm_ARID_DEF.BusCreator.HiBeamSta = LampCtl_HiBeamSta;
  AppSwcBcm_ARID_DEF.BusCreator.DomeLampPwmDuty = LampCtl_DomeLampPwmDuty;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta = LampCtl_TurnIndcrRSta;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta = LampCtl_TurnIndcrLSta;
  AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta = LampCtl_VehSeekSta;
  AppSwcBcm_ARID_DEF.BusCreator.ThermalrunawaySta = LampCtl_ThermalrunawaySta;
  AppSwcBcm_ARID_DEF.BusCreator.EmerSta = LampCtl_EmerSta;
  AppSwcBcm_ARID_DEF.BusCreator.ArmedSta = LampCtl_ArmedSta;
  AppSwcBcm_ARID_DEF.BusCreator.CrashSta = LampCtl_CrashSta;
  AppSwcBcm_ARID_DEF.BusCreator.DisarmedSta = LampCtl_DisarmedSta;
  AppSwcBcm_ARID_DEF.BusCreator.PartArmedSta = LampCtl_PartArmedSta;
  AppSwcBcm_ARID_DEF.BusCreator.AlrmSta = LampCtl_AlrmSta;
  AppSwcBcm_ARID_DEF.BusCreator.EmerHazardLightSta = LampCtl_EmerHazardLightSta;
  AppSwcBcm_ARID_DEF.BusCreator.HazardLightSta = LampCtl_HazardLightSta;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrMod = LampCtl_TurnIndcrMod;
  AppSwcBcm_ARID_DEF.BusCreator.PassLightSta = LampCtl_PassLightSta;
  AppSwcBcm_ARID_DEF.BusCreator.AutoLampSta = LampCtl_AutoLampSta;
  AppSwcBcm_ARID_DEF.BusCreator.BoxLampSta = LampCtl_J449BoxLamp;
  AppSwcBcm_ARID_DEF.BusCreator.WelcomeLampSta = LampCtl_WelcomeLampSta;
  AppSwcBcm_ARID_DEF.BusCreator.FlwrMeHomeSta = LampCtl_FlwrMeHomeSta;
  AppSwcBcm_ARID_DEF.BusCreator.FlwrMeHomeCtlFb = LampCtl_FlwrMeHomeCtlFb;
  AppSwcBcm_ARID_DEF.BusCreator.FlwrMeHomeTim = LampCtl_FlwrMeHomeTim;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLOpen = LampCtl_TurnIndcrLOpen;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLShort = LampCtl_TurnIndcrLShort;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrROpen = LampCtl_TurnIndcrROpen;
  AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRShort = LampCtl_TurnIndcrRShort;
  AppSwcBcm_ARID_DEF.BusCreator.RKEReq = LampCtl_RKEReq;
  AppSwcBcm_ARID_DEF.BusCreator.KnobBeamFaultSta = LampCtl_KnobBeamFaultSta;
  AppSwcBcm_ARID_DEF.BusCreator.RodBeamFaultSta = LampCtl_RodBeamFaultSta;
  AppSwcBcm_ARID_DEF.BusCreator.BackLadjvalFb = LampCtl_BackLadjvalFb;
  AppSwcBcm_ARID_DEF.BusCreator.J408BackLampPWM = LampCtl_J408BackLampPWM;
  AppSwcBcm_ARID_DEF.BusCreator.FogLampFSw = LampCtl_FogLampFSw;
  AppSwcBcm_ARID_DEF.BusCreator.FogLampFSta = LampCtl_FogLampFSta;
  AppSwcBcm_ARID_DEF.BusCreator.LampDelay = LampCtl_LampDelay;
  AppSwcBcm_ARID_DEF.BusCreator.AntiLckSta = LampCtl_AntiLckSta;
  AppSwcBcm_ARID_DEF.BusCreator.TrunkWarnSta = LampCtl_TrunkWarnSta;
  AppSwcBcm_ARID_DEF.BusCreator.LowBeamShortToBat = LampCtl_LowBeamShortToBat;
  AppSwcBcm_ARID_DEF.BusCreator.HiBeamShortToBat = LampCtl_HiBeamShortToBat;
  AppSwcBcm_ARID_DEF.BusCreator.VehSeekStaFb = LampCtl_VehSeekStaFb;

  /* Outputs for Atomic SubSystem: '<S3>/HornCtl' */
  AppSwcBcm_HornCtl();

  /* End of Outputs for SubSystem: '<S3>/HornCtl' */

  /* BusCreator: '<S3>/Bus Creator9' */
  AppSwcBcm_ARID_DEF.BusCreator9.HornDrv = HornCtl_J430HornDrv;
  AppSwcBcm_ARID_DEF.BusCreator9.LockHoornOnStFb = HornCtl_LockHoornOnStFb;
  AppSwcBcm_ARID_DEF.BusCreator9.LockHoornOnSt = HornCtl_LockHoornOnSt;
  AppSwcBcm_ARID_DEF.BusCreator9.HornSwCtl = HornCtl_HornSwCtl;
  AppSwcBcm_ARID_DEF.BusCreator9.PartArmedSta = HornCtl_PartArmedSta;
  AppSwcBcm_ARID_DEF.BusCreator9.ArmedSta = HornCtl_ArmedSta;
  AppSwcBcm_ARID_DEF.BusCreator9.AlarmSta = HornCtl_AlarmSta;
  AppSwcBcm_ARID_DEF.BusCreator9.SeekSta = HornCtl_SeekSta;
  AppSwcBcm_ARID_DEF.BusCreator9.AntiLckSta = HornCtl_AntiLckSta;
  AppSwcBcm_ARID_DEF.BusCreator9.TrunkWarnSta = HornCtl_TrunkWarnSta;

  /* CCaller: '<S3>/C Caller8' */
  BSW_J334WiperParkPos = GetHw_WiprStopPstnDtct();

  /* Outputs for Atomic SubSystem: '<S3>/WiperCtl' */
  AppSwcBcm_WiperCtl();

  /* End of Outputs for SubSystem: '<S3>/WiperCtl' */

  /* BusCreator: '<S3>/Bus Creator6' */
  AppSwcBcm_ARID_DEF.BusCreator6.WiperMistSw = WiperCtl_WiperMistSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WashSw = WiperCtl_WashSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperParkPosSw = WiperCtl_WiperParkPosSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperOffSw = WiperCtl_WiperOffSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperInrSw = WiperCtl_WiperInrSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperLowSpdSw = WiperCtl_WiperLowSpdSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperHiSpdSw = WiperCtl_WiperHiSpdSw;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperMistSta = WiperCtl_WiperMistSta;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperInrSta = WiperCtl_WiperInrSta;
  AppSwcBcm_ARID_DEF.BusCreator6.InrTim = WiperCtl_InrTim;
  AppSwcBcm_ARID_DEF.BusCreator6.WiprIntlTimeSetFb = WiperCtl_WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.BusCreator6.InrTimChg = WiperCtl_InrTimChg;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperOffSta = WiperCtl_WiperOffSta;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperMaintSta = WiperCtl_WiperMaintSta;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperHiSpdSta = WiperCtl_WiperHiSpdSta;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperLowSpdSta = WiperCtl_WiperLowSpdSta;
  AppSwcBcm_ARID_DEF.BusCreator6.LockedRotorProtSta =
    WiperCtl_LockedRotorProtSta;
  AppSwcBcm_ARID_DEF.BusCreator6.WashSta = WiperCtl_WashWiperSta;
  AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv = WiperCtl_WashMotorDrv;
  AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv = WiperCtl_LowSpdDrv;
  AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv = WiperCtl_HiSpdDrv;
  AppSwcBcm_ARID_DEF.BusCreator6.WiperSta = WiperCtl_WiperSta;

  /* Outputs for Atomic SubSystem: '<S3>/BCMTx' */
  AppSwcBcm_BCMTx();

  /* End of Outputs for SubSystem: '<S3>/BCMTx' */

  /* Update for Atomic SubSystem: '<S3>/LampCtl' */
  AppSwcBcm_LampCtl_Update();

  /* End of Update for SubSystem: '<S3>/LampCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator9);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus(&AppSwcBcm_ARID_DEF.BusCreator6);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD
    (&AppSwcBcm_ARID_DEF.IPM_CCP_PanelStatus_BOD_d);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC
    (&AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' incorporates:
   *  SignalConversion generated from: '<S3>/Vcu2BcmTms_outputs'
   */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs
    (&AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator12);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA
    (&AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA);

  /* Outport: '<Root>/Bcm2OpmBAC_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m);

  /* Outport: '<Root>/Bcm2OpmOBD_outputs' incorporates:
   *  BusCreator: '<S238>/Bus Creator3'
   */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k);

  /* Outport: '<Root>/Bcm2OpmEPT_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c);

  /* Outport: '<Root>/Bcm2VcuTms_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c);

  /* Outport: '<Root>/Sig_Cmd_TiLeLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_b);

  /* Outport: '<Root>/Sig_Cmd_TiRiLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_f);

  /* Outport: '<Root>/Sig_Cmd_TiWngFBSt' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt
    (AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_g);

  /* Outport: '<Root>/Sig_Cmd_PosLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_p);

  /* Outport: '<Root>/Sig_Cmd_DrlLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_c);
}

/* Model step function for TID3 */
void Runbl_AppSwcBcm_50ms(void)        /* Explicit Task: Runbl_AppSwcBcm_50ms */
{
  DynDID rtb_BusCreator;
  ESCLCtl rtb_BusCreator3;
  WakeUpCtl rtb_BusCreator15;
  sint32 i;
  uint8 rtb_CCaller40;
  uint8 rtb_RecordSta_g;
  uint8 rtb_RecordSta_m;
  boolean rtb_DataTypeConversion2_i;
  boolean rtb_DataTypeConversion3_i;
  boolean rtb_RelationalOperator1_jz;
  boolean rtb_Switch;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.EEReadCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_50ms'
   */
  /* UnitDelay: '<S4>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1 = AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a;

  /* CCaller: '<S4>/C Caller37' */
  BSW_EEIlluminatedEntrySys = GetVehCfg_IlluminatedEntrySys();

  /* CCaller: '<S4>/C Caller38' */
  BSW_EEKeyEntry = GetVehCfg_KeylessEntry();

  /* CCaller: '<S4>/C Caller16' */
  BSW_J112DrvSeatResis = GetHw_DrvSeatResis();

  /* CCaller: '<S4>/C Caller2' */
  BSW_J310DoorAjarFR = GetHw_PsngrDoorAjarSts();

  /* CCaller: '<S4>/C Caller17' */
  BSW_J320DoorAjarRL = GetHw_DoorAjarRL();

  /* CCaller: '<S4>/C Caller1' */
  BSW_J321DoorAjarFL = GetHw_DrvrDoorAjarSts();

  /* CCaller: '<S4>/C Caller' */
  BSW_J335DriverDoorLck = GetHw_DrvrDoorLckSts();

  /* CCaller: '<S4>/C Caller18' */
  BSW_J336Trunk = GetHw_TrunkSts();

  /* CCaller: '<S4>/C Caller6' */
  BSW_J337PsgPE = GetHw_FRPESwSta();

  /* CCaller: '<S4>/C Caller5' */
  BSW_J338DrvPE = GetHw_FLPESwSta();

  /* CCaller: '<S4>/C Caller20' */
  BSW_J36DoorAjarRR = GetHw_DoorAjarRR();

  /* CCaller: '<S4>/C Caller21' */
  BSW_J37TrunkAjar = GetHw_TrunkAjarSts();

  /* UnitDelay: '<S4>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2 = AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_j;

  /* Outputs for Atomic SubSystem: '<S4>/DoorLckCtl' */
  AppSwcBcm_DoorLckCtl();

  /* End of Outputs for SubSystem: '<S4>/DoorLckCtl' */

  /* BusCreator: '<S4>/Bus Creator4' */
  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw = DoorLckCtl_DoorAjarFLSw;
  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw = DoorLckCtl_DoorAjarFRSw;
  AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw = DoorLckCtl_DriverDoorLckSw;
  AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw = DoorLckCtl_DrvPESw;
  AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw = DoorLckCtl_PsgPESw;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkSw = DoorLckCtl_TrunkSw;
  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRLSw = DoorLckCtl_DoorAjarRLSw;
  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw = DoorLckCtl_DoorAjarRRSw;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw = DoorLckCtl_TrunkAjarSw;
  AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw = DoorLckCtl_HoodAjarSw;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSw = DoorLckCtl_TrunkLckSw;
  AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw = DoorLckCtl_DrvSeatSw;
  AppSwcBcm_ARID_DEF.BusCreator4.InsLck = DoorLckCtl_InsLck;
  AppSwcBcm_ARID_DEF.BusCreator4.InsUnlck = DoorLckCtl_InsUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.OsLck = DoorLckCtl_OsLck;
  AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck = DoorLckCtl_OsUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkUnlck = DoorLckCtl_TrunkUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.MotorProt = DoorLckCtl_MotorProt;
  AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck = DoorLckCtl_DoorProtUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.ParkAutoUnlockSetFb =
    DoorLckCtl_ParkAutoUnlockSetFb;
  AppSwcBcm_ARID_DEF.BusCreator4.CrshUnlck = DoorLckCtl_CrshUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.J56DoorUnlck = DoorLckCtl_J56DoorUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.J54DoorLck = DoorLckCtl_J54DoorLck;
  AppSwcBcm_ARID_DEF.BusCreator4.J511TrunkUnlck = DoorLckCtl_J511TrunkUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta = DoorLckCtl_TrunkLckSta;
  AppSwcBcm_ARID_DEF.BusCreator4.InsLckSta = DoorLckCtl_InsLckSta;
  AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta = DoorLckCtl_OsLckSta;
  AppSwcBcm_ARID_DEF.BusCreator4.RKEAntiLck = DoorLckCtl_RKEAntiLck;
  AppSwcBcm_ARID_DEF.BusCreator4.MechAntiLck = DoorLckCtl_MechAntiLck;
  AppSwcBcm_ARID_DEF.BusCreator4.SpdCtlLckSetFb = DoorLckCtl_SpdCtlLckSetFb;
  AppSwcBcm_ARID_DEF.BusCreator4.SpdCtlLckSet = DoorLckCtl_SpdCtlLckSet;
  AppSwcBcm_ARID_DEF.BusCreator4.WelcomeLck = DoorLckCtl_WelcomeLck;
  AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck = DoorLckCtl_WelcomeUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.HULck = DoorLckCtl_HULck;
  AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck = DoorLckCtl_HUUnLck;
  AppSwcBcm_ARID_DEF.BusCreator4.VehStop = DoorLckCtl_VehStop;
  AppSwcBcm_ARID_DEF.BusCreator4.AutoLckSta = DoorLckCtl_AutoLckSta;
  AppSwcBcm_ARID_DEF.BusCreator4.AutoLck = DoorLckCtl_AutoLck;
  AppSwcBcm_ARID_DEF.BusCreator4.PELck = DoorLckCtl_PELck;
  AppSwcBcm_ARID_DEF.BusCreator4.IllmndUnlockStsFb =
    DoorLckCtl_IllmndUnlockStsFb;
  AppSwcBcm_ARID_DEF.BusCreator4.IllmndUnlockSts = DoorLckCtl_IllmndUnlockSts;
  AppSwcBcm_ARID_DEF.BusCreator4.IllmndLckSts = DoorLckCtl_IllmndLckSts;
  AppSwcBcm_ARID_DEF.BusCreator4.IllmndLckStsFb = DoorLckCtl_IllmndLckStsFb;
  AppSwcBcm_ARID_DEF.BusCreator4.MechLck = DoorLckCtl_MechLck;
  AppSwcBcm_ARID_DEF.BusCreator4.RKELck = DoorLckCtl_RKELck;
  AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck = DoorLckCtl_RKEUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck = DoorLckCtl_PEUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck = DoorLckCtl_MechUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck = DoorLckCtl_ParkUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck =
    DoorLckCtl_ThermRunawayUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.SpdLck = DoorLckCtl_SpdLck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkRkEUnlck = DoorLckCtl_TrunkRKEUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkHUUnlck =
    AppSwcBcm_ARID_DEF.LogicalOperator_e;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkAutoLck = DoorLckCtl_TrunkAutoLck;
  AppSwcBcm_ARID_DEF.BusCreator4.TboxLck = DoorLckCtl_TboxLck;
  AppSwcBcm_ARID_DEF.BusCreator4.TboxUnlck = DoorLckCtl_TboxUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkTboxUnlck = DoorLckCtl_TrunkTboxUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.RemoteLockFb = DoorLckCtl_RemoteLockFb;

  /* Outputs for Atomic SubSystem: '<S4>/IMMOCtl' */
  AppSwcBcm_IMMOCtl();

  /* End of Outputs for SubSystem: '<S4>/IMMOCtl' */

  /* BusCreator: '<S4>/Bus Creator14' */
  for (i = 0; i < 8; i++) {
    AppSwcBcm_ARID_DEF.BusCreator14.AuthResp[i] = IMMOCtl_AuthResp[i];
  }

  AppSwcBcm_ARID_DEF.BusCreator14.SKSta = IMMOCtl_SKSta;
  for (i = 0; i < 16; i++) {
    AppSwcBcm_ARID_DEF.BusCreator14.SKRead[i] = IMMOCtl_SKRead[i];
  }

  /* End of BusCreator: '<S4>/Bus Creator14' */

  /* Outputs for Atomic SubSystem: '<S4>/AlmSysCtl' */
  AppSwcBcm_AlmSysCtl();

  /* End of Outputs for SubSystem: '<S4>/AlmSysCtl' */

  /* BusCreator: '<S4>/Bus Creator2' */
  AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts = AlmSysCtl_BodyWarnSts;
  AppSwcBcm_ARID_DEF.BusCreator2.AlrmWarnTimOut = AlmSysCtl_AlrmWarnTimOut;

  /* CCaller: '<S4>/C Caller9' */
  AppSwcBcm_ARID_DEF.CCaller35 = GetHw_KL15A();

  /* CCaller: '<S4>/C Caller10' */
  AppSwcBcm_ARID_DEF.CCaller36 = GetHw_KL15B();

  /* Outputs for Atomic SubSystem: '<S4>/PDUCtl' */
  AppSwcBcm_PDUCtl();

  /* End of Outputs for SubSystem: '<S4>/PDUCtl' */

  /* BusCreator: '<S4>/Bus Creator1' */
  AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode = PDUCtl_SysPwrMode;
  AppSwcBcm_ARID_DEF.BusCreator1.J421IG1RlyCtl = PDUCtl_J421IG1RlyCtl;
  AppSwcBcm_ARID_DEF.BusCreator1.J437IG2RlyCtl = PDUCtl_J437IG2RlyCtl;
  AppSwcBcm_ARID_DEF.BusCreator1.IG1RelayFault = PDUCtl_IG1RelayFault;
  AppSwcBcm_ARID_DEF.BusCreator1.IG2RelayFault = PDUCtl_IG2RelayFault;
  AppSwcBcm_ARID_DEF.BusCreator1.SysPwrModeV = PDUCtl_SysPwrModeV;
  AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts = PDUCtl_SysPowerSts;
  AppSwcBcm_ARID_DEF.BusCreator1.PwrOn = PDUCtl_PwrOn;
  AppSwcBcm_ARID_DEF.BusCreator1.SysPwrModeAct = PDUCtl_SysPwrModeAct;
  AppSwcBcm_ARID_DEF.BusCreator1.StartReq = PDUCtl_StartReq;
  AppSwcBcm_ARID_DEF.BusCreator1.IGRlyIIgCls = PDUCtl_IGRlyIlgCls;
  AppSwcBcm_ARID_DEF.BusCreator1.RemotePwrLckSta = PDUCtl_RemotePwrLckSta;
  AppSwcBcm_ARID_DEF.BusCreator1.RemotePwrLckFb = PDUCtl_RemotePwrLckFb;
  AppSwcBcm_ARID_DEF.BusCreator1.RemotePwrCtlFb = PDUCtl_RemtPwrCtlFb;

  /* Outputs for Atomic SubSystem: '<S4>/ESCLCtl' */
  AppSwcBcm_ESCLCtl();

  /* End of Outputs for SubSystem: '<S4>/ESCLCtl' */

  /* Outputs for Atomic SubSystem: '<S4>/BatSaveCtl' */
  AppSwcBcm_BatSaveCtl();

  /* End of Outputs for SubSystem: '<S4>/BatSaveCtl' */

  /* CCaller: '<S4>/C Caller36' */
  AppSwcBcm_ARID_DEF.CCaller36 = GetHw_KL15A();

  /* CCaller: '<S4>/C Caller35' */
  AppSwcBcm_ARID_DEF.CCaller35 = GetHw_KL15B();

  /* BusCreator: '<S4>/Bus Creator8' */
  AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr = BatSaveCtl_J64SavePwr;

  /* Outputs for Atomic SubSystem: '<S4>/WakeUpCtl' */
  AppSwcBcm_WakeUpCtl();

  /* End of Outputs for SubSystem: '<S4>/WakeUpCtl' */

  /* Outputs for Atomic SubSystem: '<S4>/DTCCtl' */
  AppSwcBcm_DTCCtl();

  /* End of Outputs for SubSystem: '<S4>/DTCCtl' */

  /* SignalConversion: '<S640>/Signal Conversion' */
  DynDID_0xF22CAntitheftSta = AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts;

  /* Truth Table: '<S817>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  /*  Condition #4 */
  /*  Condition #5 */
  /*  Condition #6 */
  /*  Condition #7 */
  /*  Condition #8 */
  /*  Condition #9 */
  /*  Condition #10 */
  /*  Condition #11 */
  /*  Condition #12 */
  /*  Condition #13 */
  /*  Condition #14 */
  /*  Condition #15 */
  /*  Condition #16 */
  /*  Condition #17 */
  /*  Condition #18 */
  /*  Condition #19 */
  if (AppSwcBcm_ARID_DEF.BusCreator4.CrshUnlck) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    rtb_RecordSta_m = 10U;
  } else {
    rtb_DataTypeConversion3_i = !AppSwcBcm_ARID_DEF.BusCreator4.CrshUnlck;
    if (rtb_DataTypeConversion3_i &&
        AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck) {
      /*  Example action 2 called from D3 column in condition table */
      rtb_RecordSta_m = 15U;
    } else {
      rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
        (!AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck));
      if (rtb_DataTypeConversion3_i && AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck)
      {
        rtb_RecordSta_m = 11U;
      } else {
        rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
          (!AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck));
        if (rtb_DataTypeConversion3_i && AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck)
        {
          rtb_RecordSta_m = 8U;
        } else {
          rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
            (!AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck));
          if (rtb_DataTypeConversion3_i &&
              AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck) {
            rtb_RecordSta_m = 12U;
          } else {
            rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
              (!AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck));
            if (rtb_DataTypeConversion3_i &&
                AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck) {
              rtb_RecordSta_m = 13U;
            } else {
              rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                (!AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck));
              if (rtb_DataTypeConversion3_i &&
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck) {
                rtb_RecordSta_m = 15U;
              } else {
                rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                  (!AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck));
                if (rtb_DataTypeConversion3_i &&
                    AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck) {
                  rtb_RecordSta_m = 19U;
                } else {
                  rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                    (!AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck));
                  if (rtb_DataTypeConversion3_i &&
                      AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck) {
                    rtb_RecordSta_m = 17U;
                  } else {
                    rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                      (!AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck));
                    if (rtb_DataTypeConversion3_i &&
                        AppSwcBcm_ARID_DEF.BusCreator4.MechLck) {
                      rtb_RecordSta_m = 7U;
                    } else {
                      rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                        (!AppSwcBcm_ARID_DEF.BusCreator4.MechLck));
                      if (rtb_DataTypeConversion3_i &&
                          AppSwcBcm_ARID_DEF.BusCreator4.HULck) {
                        rtb_RecordSta_m = 1U;
                      } else {
                        rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                          (!AppSwcBcm_ARID_DEF.BusCreator4.HULck));
                        if (rtb_DataTypeConversion3_i &&
                            AppSwcBcm_ARID_DEF.BusCreator4.SpdLck) {
                          rtb_RecordSta_m = 2U;
                        } else {
                          rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i
                            && (!AppSwcBcm_ARID_DEF.BusCreator4.SpdLck));
                          if (rtb_DataTypeConversion3_i &&
                              AppSwcBcm_ARID_DEF.BusCreator4.PELck) {
                            rtb_RecordSta_m = 5U;
                          } else {
                            rtb_DataTypeConversion3_i =
                              (rtb_DataTypeConversion3_i &&
                               (!AppSwcBcm_ARID_DEF.BusCreator4.PELck));
                            if (rtb_DataTypeConversion3_i &&
                                AppSwcBcm_ARID_DEF.BusCreator4.AutoLck) {
                              rtb_RecordSta_m = 3U;
                            } else {
                              rtb_DataTypeConversion3_i =
                                (rtb_DataTypeConversion3_i &&
                                 (!AppSwcBcm_ARID_DEF.BusCreator4.AutoLck));
                              if (rtb_DataTypeConversion3_i &&
                                  AppSwcBcm_ARID_DEF.BusCreator4.RKELck) {
                                rtb_RecordSta_m = 4U;
                              } else if (rtb_DataTypeConversion3_i &&
                                         (!AppSwcBcm_ARID_DEF.BusCreator4.RKELck)
                                         &&
                                         AppSwcBcm_ARID_DEF.BusCreator4.WelcomeLck)
                              {
                                rtb_RecordSta_m = 18U;
                              } else {
                                /*  Default */
                                rtb_RecordSta_m = 0U;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  /* End of Truth Table: '<S817>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_j) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF230DoorOpRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_j = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_f = (rtb_RecordSta_m != 0);

  /* Chart: '<S817>/Chart' incorporates:
   *  SubSystem: '<S826>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_f,
    &AppSwcBcm_ARID_DEF.LogicalOperator_hh,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dh);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_hh) {
    i = AppSwcBcm_ARID_DEF.i_a + 1;
    if (AppSwcBcm_ARID_DEF.i_a + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_a = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_a > 10) {
      AppSwcBcm_ARID_DEF.i_a = 1U;
    }

    DynDID_0xF230DoorOpRecord[AppSwcBcm_ARID_DEF.i_a - 1] = rtb_RecordSta_m;
  }

  /* Truth Table: '<S818>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkRkEUnlck) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    rtb_RecordSta_g = 5U;
  } else {
    rtb_DataTypeConversion3_i = !AppSwcBcm_ARID_DEF.BusCreator4.TrunkRkEUnlck;
    if (rtb_DataTypeConversion3_i && AppSwcBcm_ARID_DEF.BusCreator4.TrunkHUUnlck)
    {
      /*  Example action 2 called from D3 column in condition table */
      rtb_RecordSta_g = 0U;
    } else if (rtb_DataTypeConversion3_i &&
               (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkHUUnlck) &&
               AppSwcBcm_ARID_DEF.BusCreator4.TrunkAutoLck) {
      rtb_RecordSta_g = 0U;
    } else {
      /*  Default */
      rtb_RecordSta_g = 0U;
    }
  }

  /* End of Truth Table: '<S818>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_d) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF231TrunkOpRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_d = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_b = (rtb_RecordSta_g != 0);

  /* Chart: '<S818>/Chart' incorporates:
   *  SubSystem: '<S830>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_b,
    &AppSwcBcm_ARID_DEF.LogicalOperator_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ld);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_k) {
    i = AppSwcBcm_ARID_DEF.i_k + 1;
    if (AppSwcBcm_ARID_DEF.i_k + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_k = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_k > 10) {
      AppSwcBcm_ARID_DEF.i_k = 1U;
    }

    DynDID_0xF231TrunkOpRecord[AppSwcBcm_ARID_DEF.i_k - 1] = rtb_RecordSta_g;
  }

  /* Chart: '<S821>/Chart' */
  DynDID_0xF234ADSampleValue[1] = 0U;
  DynDID_0xF234ADSampleValue[2] = 0U;

  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Default */
  if (!AppSwcBcm_ARID_DEF.Flg_h) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF232LocalStartUpFailRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.LocalStartFailOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_h = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_h = false;

  /* Chart: '<S819>/Chart' incorporates:
   *  SubSystem: '<S834>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_h,
    &AppSwcBcm_ARID_DEF.LogicalOperator_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gu);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_l) {
    i = AppSwcBcm_ARID_DEF.i_m + 1;
    if (AppSwcBcm_ARID_DEF.i_m + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_m = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_m > 10) {
      AppSwcBcm_ARID_DEF.i_m = 1U;
    }
  }

  /* Truth Table: '<S820>/Truth Table' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 3) ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 5)) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    rtb_RecordSta_g = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 1) {
    /*  Example action 2 called from D3 column in condition table */
    rtb_RecordSta_g = 2U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw) {
    rtb_RecordSta_g = 3U;
  } else {
    /*  Default */
    rtb_RecordSta_g = 0U;
  }

  /* End of Truth Table: '<S820>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_g) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF233RemoteStartUpFailRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.RemoteStartFailRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_g = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_n = (rtb_RecordSta_g != 0);

  /* Chart: '<S820>/Chart' incorporates:
   *  SubSystem: '<S838>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_g(AppSwcBcm_ARID_DEF.Lib_blIn_n,
    &AppSwcBcm_ARID_DEF.LogicalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
    i = AppSwcBcm_ARID_DEF.i + 1;
    if (AppSwcBcm_ARID_DEF.i + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i > 10) {
      AppSwcBcm_ARID_DEF.i = 1U;
    }
  }

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion3_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->J408BackLampPWM != 0);

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion2_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->DomeLampPwmDuty != 0);

  /* Switch: '<S846>/Switch' incorporates:
   *  Constant: '<S846>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  RelationalOperator: '<S846>/Relational Operator'
   *  RelationalOperator: '<S846>/Relational Operator1'
   */
  rtb_Switch = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus())->DrvWinSta != 0);

  /* RelationalOperator: '<S846>/Relational Operator1' incorporates:
   *  Constant: '<S846>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  rtb_RelationalOperator1_jz = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus()
    )->PsgWinSta != 0);

  /* Chart: '<S823>/Chart' incorporates:
   *  Constant: '<S845>/Constant'
   *  Constant: '<S845>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S845>/Logical Operator'
   *  Logic: '<S845>/Logical Operator1'
   *  RelationalOperator: '<S845>/Relational Operator'
   *  RelationalOperator: '<S845>/Relational Operator1'
   *  RelationalOperator: '<S845>/Relational Operator2'
   *  RelationalOperator: '<S845>/Relational Operator3'
   *  Switch: '<S846>/Switch1'
   * */
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)(DynDID_0xF236DigtOutSampleValue[0]
    | (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->TurnIndcrLSta);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->TurnIndcrRSta << 1 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)(rtb_DataTypeConversion3_i << 2 |
    DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw << 3 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->ReverseLampSta << 5 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->PosLampSta << 7 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)(rtb_DataTypeConversion2_i << 1 |
    DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->LowBeamSta << 4 |
     DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->HiBeamSta << 5 |
     DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->FogLampFSw << 6 |
     DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[2] = (uint8)(DynDID_0xF236DigtOutSampleValue[2]
    | AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta);
  DynDID_0xF236DigtOutSampleValue[2] = (uint8)
    (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw << 1 |
     DynDID_0xF236DigtOutSampleValue[2]);
  DynDID_0xF236DigtOutSampleValue[2] = (uint8)
    (((AppSwcBcm_ARID_DEF.BusCreator4.InsLckSta == 2) ||
      (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2)) << 2 |
     DynDID_0xF236DigtOutSampleValue[2]);
  DynDID_0xF236DigtOutSampleValue[2] = (uint8)
    (((AppSwcBcm_ARID_DEF.BusCreator4.InsLckSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1)) << 3 |
     DynDID_0xF236DigtOutSampleValue[2]);
  DynDID_0xF236DigtOutSampleValue[2] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Wiper_Bus())->WiperHiSpdSta << 6 |
     DynDID_0xF236DigtOutSampleValue[2]);
  DynDID_0xF236DigtOutSampleValue[2] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Wiper_Bus())->WiperLowSpdSta << 7 |
     DynDID_0xF236DigtOutSampleValue[2]);
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)(rtb_Switch << 3 |
    DynDID_0xF236DigtOutSampleValue[3]);
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)(rtb_RelationalOperator1_jz << 4 |
    DynDID_0xF236DigtOutSampleValue[3]);
  i = AppSwcBcm_ARID_DEF.BusCreator1.J421IG1RlyCtl << 7 |
    DynDID_0xF236DigtOutSampleValue[3];
  if (i > 255) {
    i = 255;
  }

  DynDID_0xF236DigtOutSampleValue[3] = (uint8)i;
  DynDID_0xF236DigtOutSampleValue[4] = (uint8)(DynDID_0xF236DigtOutSampleValue[4]
    | AppSwcBcm_ARID_DEF.BusCreator1.J437IG2RlyCtl);
  DynDID_0xF236DigtOutSampleValue[4] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornDrv << 1 |
     DynDID_0xF236DigtOutSampleValue[4]);

  /* End of Chart: '<S823>/Chart' */

  /* SignalConversion: '<S640>/Signal Conversion1' */
  DynDID_0xF237PwrModeSta = AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* CCaller: '<S4>/C Caller39' incorporates:
   *  CCaller: '<S4>/C Caller11'
   */
  rtb_RecordSta_g = GetHw_KL15B();

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  rtb_DataTypeConversion3_i = (rtb_RecordSta_g != 0);

  /* CCaller: '<S4>/C Caller39' */
  rtb_RecordSta_g = GetHw_KL15A();

  /* RelationalOperator: '<S640>/Relational Operator' */
  rtb_DataTypeConversion2_i = !AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Logic: '<S825>/Logical Operator' */
  rtb_Switch = (AppSwcBcm_ARID_DEF.BusCreator4.InsLck ||
                AppSwcBcm_ARID_DEF.BusCreator4.OsLck);

  /* Logic: '<S825>/Logical Operator1' */
  rtb_RelationalOperator1_jz = (AppSwcBcm_ARID_DEF.BusCreator4.InsUnlck ||
    AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck);

  /* CCaller: '<S4>/C Caller40' */
  rtb_CCaller40 = GetHw_WiprStopPstnDtct();

  /* Chart: '<S822>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  RelationalOperator: '<S640>/Relational Operator'
   * */
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(DynDID_0xF235DigtInSampleValue[0] |
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(rtb_DataTypeConversion3_i << 1 |
    DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)((rtb_RecordSta_g != 0) << 2 |
    DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Wiper_Bus())->WiperHiSpdSw << 3 |
     DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Wiper_Bus())->WiperLowSpdSw << 4 |
     DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkUnlck << 5 |
     DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(rtb_DataTypeConversion2_i << 6 |
    DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(rtb_Switch << 7 |
    DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[1] = (uint8)(DynDID_0xF235DigtInSampleValue[1] |
    rtb_RelationalOperator1_jz);
  DynDID_0xF235DigtInSampleValue[1] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw << 3 |
     DynDID_0xF235DigtInSampleValue[1]);
  DynDID_0xF235DigtInSampleValue[1] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw << 4 |
     DynDID_0xF235DigtInSampleValue[1]);
  DynDID_0xF235DigtInSampleValue[2] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw << 1 |
     DynDID_0xF235DigtInSampleValue[2]);
  DynDID_0xF235DigtInSampleValue[2] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw << 3 |
     DynDID_0xF235DigtInSampleValue[2]);
  DynDID_0xF235DigtInSampleValue[2] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw << 4 |
     DynDID_0xF235DigtInSampleValue[2]);
  DynDID_0xF235DigtInSampleValue[2] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRLSw << 5 |
     DynDID_0xF235DigtInSampleValue[2]);
  DynDID_0xF235DigtInSampleValue[2] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw << 6 |
     DynDID_0xF235DigtInSampleValue[2]);
  DynDID_0xF235DigtInSampleValue[2] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw << 7 |
     DynDID_0xF235DigtInSampleValue[2]);
  DynDID_0xF235DigtInSampleValue[3] = (uint8)(DynDID_0xF235DigtInSampleValue[3] |
    AppSwcBcm_ARID_DEF.BusCreator4.TrunkSw);
  DynDID_0xF235DigtInSampleValue[3] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->HazardLightSw << 1 |
     DynDID_0xF235DigtInSampleValue[3]);
  i = rtb_CCaller40 << 2 | DynDID_0xF235DigtInSampleValue[3];
  if (i > 255) {
    i = 255;
  }

  DynDID_0xF235DigtInSampleValue[3] = (uint8)i;

  /* End of Chart: '<S822>/Chart' */

  /* Switch: '<S817>/Switch' incorporates:
   *  UnitDelay: '<S817>/Unit Delay'
   */
  if (rtb_RecordSta_m > 0) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dg = rtb_RecordSta_m;
  }

  /* End of Switch: '<S817>/Switch' */

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  UnitDelay: '<S817>/Unit Delay'
   */
  rtb_BusCreator.DynDID_0xF22CAntitheftSta = DynDID_0xF22CAntitheftSta;
  for (i = 0; i < 10; i++) {
    rtb_BusCreator.DynDID_0xF230DoorOpRecord[i] = DynDID_0xF230DoorOpRecord[i];
  }

  for (i = 0; i < 10; i++) {
    rtb_BusCreator.DynDID_0xF231TrunkOpRecord[i] = DynDID_0xF231TrunkOpRecord[i];
  }

  for (i = 0; i < 23; i++) {
    rtb_BusCreator.DynDID_0xF234ADSampleValue[i] = DynDID_0xF234ADSampleValue[i];
  }

  for (i = 0; i < 10; i++) {
    rtb_BusCreator.DynDID_0xF232LocalStartUpFailRecord[i] =
      DynDID_0xF232LocalStartUpFailRecord[i];
  }

  for (i = 0; i < 10; i++) {
    rtb_BusCreator.DynDID_0xF233RemoteStartUpFailRecord[i] =
      DynDID_0xF233RemoteStartUpFailRecord[i];
  }

  for (i = 0; i < 5; i++) {
    rtb_BusCreator.DynDID_0xF236DigtOutSampleValue[i] =
      DynDID_0xF236DigtOutSampleValue[i];
  }

  rtb_BusCreator.DynDID_0xF237PwrModeSta = DynDID_0xF237PwrModeSta;
  for (i = 0; i < 5; i++) {
    rtb_BusCreator.DynDID_0xF235DigtInSampleValue[i] =
      DynDID_0xF235DigtInSampleValue[i];
  }

  rtb_BusCreator.DynDID_DoorOpRecord = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dg;

  /* End of BusCreator: '<S4>/Bus Creator' */

  /* BusCreator: '<S4>/Bus Creator15' */
  rtb_BusCreator15.NMReq = WakeUpCtl_NMReq;
  rtb_BusCreator15.SleepAllwd = WakeUpCtl_SleepAllwd;

  /* BusCreator: '<S4>/Bus Creator3' */
  rtb_BusCreator3.UnOrLockCrtl = ESCLCtl_UnOrLockCrtl;
  rtb_BusCreator3.J436PwrSup = ESCLCtl_J436PwrSup;

  /* CCaller: '<S4>/C Caller19' */
  BSW_J349TrunkLck = GetHw_TrunkLckSts();

  /* CCaller: '<S4>/C Caller22' */
  BSW_J38HoodAjar = GetHw_HoodAjarSts();

  /* CCaller: '<S816>/C Caller' incorporates:
   *  Constant: '<S816>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts, 61996U);

  /* CCaller: '<S820>/C Caller' incorporates:
   *  Constant: '<S820>/Constant'
   *  Constant: '<S820>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF233RemoteStartUpFailRecord[0], 10U,
                     62003U);

  /* CCaller: '<S823>/C Caller' incorporates:
   *  Constant: '<S823>/Constant'
   *  Constant: '<S823>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF236DigtOutSampleValue[0], 5U, 62006U);

  /* CCaller: '<S824>/C Caller' incorporates:
   *  Constant: '<S824>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts, 62007U);

  /* CCaller: '<S817>/C Caller' incorporates:
   *  Constant: '<S817>/Constant'
   *  Constant: '<S817>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF230DoorOpRecord[0], 10U, 62000U);

  /* CCaller: '<S818>/C Caller' incorporates:
   *  Constant: '<S818>/Constant'
   *  Constant: '<S818>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF231TrunkOpRecord[0], 10U, 62001U);

  /* CCaller: '<S821>/C Caller' incorporates:
   *  Constant: '<S821>/Constant'
   *  Constant: '<S821>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF234ADSampleValue[0], 23U, 62004U);

  /* CCaller: '<S819>/C Caller' incorporates:
   *  Constant: '<S819>/Constant'
   *  Constant: '<S819>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF232LocalStartUpFailRecord[0], 10U,
                     62002U);

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a =
    AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts;

  /* Update for UnitDelay: '<S4>/Unit Delay5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->RKEReq;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_j =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode;

  /* Update for UnitDelay: '<S4>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0 =
    AppSwcBcm_ARID_DEF.BusCreator1.IGRlyIIgCls;

  /* Update for UnitDelay: '<S4>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* Update for Atomic SubSystem: '<S4>/WakeUpCtl' */
  AppSwcBcm_WakeUpCtl_Update();

  /* End of Update for SubSystem: '<S4>/WakeUpCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator2);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator1);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator4);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DynDID_Bus(&rtb_BusCreator);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_BatSaveCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator8);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_ESCLCtl_Bus(&rtb_BusCreator3);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_IMMOCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator14);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_WakeUpCtl_Bus(&rtb_BusCreator15);
}

/* Model step function for TID4 */
void Runbl_AppSwcBcm_100ms(void)      /* Explicit Task: Runbl_AppSwcBcm_100ms */
{
  IODID rtb_BusCreator16;
  RVMCtl rtb_BusCreator7;
  SeatCtl rtb_BusCreator11;
  SteerWhlCtl rtb_BusCreator13;
  WinCtl rtb_BusCreator5;
  sint32 rtb_SeatCtl_CN167DrvSeatHtPWM;
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator1_c;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_100ms'
   */
  /* CCaller: '<S1>/C Caller25' */
  BSW_DrvWinMotorCur = GetHw_DrvWinMotorCur();

  /* CCaller: '<S1>/C Caller26' */
  BSW_J113DrvWinSwResis = GetHw_DrvWinSwResis();

  /* CCaller: '<S1>/C Caller27' */
  BSW_J126DrvPsgWinSwResis = GetHw_DrvPsgWinSwResis();

  /* CCaller: '<S1>/C Caller28' */
  BSW_J26PsgWinSwResis = GetHw_PsgWinSwResis();

  /* CCaller: '<S1>/C Caller29' */
  BSW_PsgWinMotorCur = GetHw_PsgWinMotorCur();

  /* Outputs for Atomic SubSystem: '<S1>/WinCtl' */
  AppSwcBcm_WinCtl();

  /* End of Outputs for SubSystem: '<S1>/WinCtl' */

  /* Outputs for Atomic SubSystem: '<S1>/IODID' */
  AppSwcBcm_IODID();

  /* End of Outputs for SubSystem: '<S1>/IODID' */

  /* BusCreator: '<S1>/Bus Creator16' */
  rtb_BusCreator16.TurnIndcrLCtlFlg = IODID_TurnIndcrLCtlFlg;
  rtb_BusCreator16.TurnIndcrRCtlFlg = IODID_TurnIndcrRCtlFlg;
  rtb_BusCreator16.BackLampCtlFlg = IODID_BackLampCtlFlg;
  rtb_BusCreator16.BrakeLightCtlFlg = IODID_BrakeLightCtlFlg;
  rtb_BusCreator16.ReverseLampCtlFlg = IODID_ReverseLampCtlFlg;
  rtb_BusCreator16.DayRunLightCtlFlg = IODID_DayRunLightCtlFlg;
  rtb_BusCreator16.PosLampCtlFlg = IODID_PosLampCtlFlg;
  rtb_BusCreator16.DomeLampCtlFlg = IODID_DomeLampCtlFlg;
  rtb_BusCreator16.LowBeamCtlFlg = IODID_LowBeamCtlFlg;
  rtb_BusCreator16.HiBeamCtlFlg = IODID_HiBeamCtlFlg;
  rtb_BusCreator16.FogLampFCtlFlg = IODID_FogLampFCtlFlg;
  rtb_BusCreator16.FogLampRCtlFlg = IODID_FogLampRCtlFlg;
  rtb_BusCreator16.TrunkUnlckCtlFlg = IODID_TrunkUnlckCtlFlg;
  rtb_BusCreator16.DoorUnlckCtlFlg = IODID_DoorUnlckCtlFlg;
  rtb_BusCreator16.DoorLlckCtlFlg = IODID_DoorLckCtlFlg;
  rtb_BusCreator16.WiperHiSpdCtlFlg = IODID_WiperHiSpdCtlFlg;
  rtb_BusCreator16.WiperLowSpdCtlFlg = IODID_WiperLowSpdCtlFlg;
  rtb_BusCreator16.WinFLCtlFlg = IODID_WinFLCtlFlg;
  rtb_BusCreator16.WinFRCtlFlg = IODID_WinFRCtlFlg;
  rtb_BusCreator16.IG1RlyCtlFlg = IODID_IG1RlyCtlFlg;
  rtb_BusCreator16.IG2RlyCtlFlg = IODID_IG2RlyCtlFlg;
  rtb_BusCreator16.HornCtlFlg = IODID_HornCtlFlg;
  rtb_BusCreator16.BatSaveCtlFlg = IODID_BatSaveCtlFlg;
  rtb_BusCreator16.BSDRightCtlFlg = IODID_BSDRightCtlFlg;
  rtb_BusCreator16.BSDLeftCtlFlg = IODID_BSDLeftCtlFlg;

  /* Outputs for Atomic SubSystem: '<S1>/RVMCtl' */
  AppSwcBcm_RVMCtl();

  /* End of Outputs for SubSystem: '<S1>/RVMCtl' */

  /* BusCreator: '<S1>/Bus Creator7' */
  rtb_BusCreator7.J42Heat = RVMCtl_J42Heat;

  /* CCaller: '<S1>/C Caller34' */
  BSW_J134SteerWhlResis = GetHw_SteerWhlTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SteerWhlCtl' */
  /* DataTypeConversion: '<S137>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S137>/Data Type Conversion1'
   *  Lookup_n-D: '<S137>/1-D Lookup Table1'
   */
  SteerWhlCtl_SteerWhlTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_J134SteerWhlResis, (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_X[0],
     (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_Y[0], 17U));

  /* Chart: '<S137>/HeatSet' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_OFF_b;
    SteerWhlCtl_SteerWhlHeatSts = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib == AppSwcBcm_IN_OFF_b) {
    SteerWhlCtl_SteerWhlHeatSts = 0U;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
         ->VIPM_HUSteerWhlHeat_enum == 2)) {
      AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_ON_j;
      SteerWhlCtl_SteerWhlHeatSts = 1U;
    }
  } else {
    /* case IN_ON: */
    SteerWhlCtl_SteerWhlHeatSts = 1U;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 0) ||
        ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
         ->VIPM_HUSteerWhlHeat_enum == 1)) {
      AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_OFF_b;
      SteerWhlCtl_SteerWhlHeatSts = 0U;
    }
  }

  /* End of Chart: '<S137>/HeatSet' */

  /* Chart: '<S137>/HeatCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_j;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib == AppSwcBcm_IN_Off_j) {
    if ((SteerWhlCtl_SteerWhlHeatSts != 0) && (SteerWhlCtl_TrgtTemp_C -
         SteerWhlCtl_SteerWhlTemp >= SteerWhlCtl_DiffTemp_C)) {
      AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_On_e;
      AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = true;
    }

    /* case IN_On: */
  } else if ((SteerWhlCtl_SteerWhlHeatSts == 0) || (SteerWhlCtl_SteerWhlTemp >=
              SteerWhlCtl_TrgtTemp_C)) {
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_j;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  }

  /* End of Chart: '<S137>/HeatCtl' */

  /* Outputs for Atomic SubSystem: '<S137>/Ovrd' */
  /* Switch: '<S141>/Switch' incorporates:
   *  Constant: '<S137>/Constant18'
   */
  if (SteerWhlCtl_J447SteerWhlHtOvrdFlg_C) {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S137>/Constant19'
     */
    SteerWhlCtl_J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHtOvrdVal_C;
  } else {
    /* Switch: '<S141>/Switch' */
    SteerWhlCtl_J447SteerWhlHt = AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta;
  }

  /* End of Switch: '<S141>/Switch' */
  /* End of Outputs for SubSystem: '<S137>/Ovrd' */

  /* Chart: '<S137>/HeatFb' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_d;
    SteerWhlCtl_RemtHeatFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_k = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib) {
     case AppSwcBcm_IN_Fail_j:
      SteerWhlCtl_RemtHeatFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_k >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_d;
        SteerWhlCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_k = 0U;
      } else {
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_k + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_k = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;

     case AppSwcBcm_IN_Init_d:
      SteerWhlCtl_RemtHeatFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_ax = false;

      /* Outputs for Function Call SubSystem: '<S139>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_ax,
        &AppSwcBcm_ARID_DEF.LogicalOperator_my,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ox);

      /* End of Outputs for SubSystem: '<S139>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_my) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Wait_g;
      }
      break;

     case AppSwcBcm_IN_Suc_n:
      SteerWhlCtl_RemtHeatFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_k >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_d;
        SteerWhlCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_k = 0U;
      } else {
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_k + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_k = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;

     default:
      /* case IN_Wait: */
      if (SteerWhlCtl_SteerWhlHeatSts == 2) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Suc_n;
        SteerWhlCtl_RemtHeatFb = 1U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_k + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_k = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      } else {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Fail_j;
        SteerWhlCtl_RemtHeatFb = 3U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_k + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_k = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;
    }
  }

  /* End of Chart: '<S137>/HeatFb' */
  /* End of Outputs for SubSystem: '<S1>/SteerWhlCtl' */

  /* BusCreator: '<S1>/Bus Creator13' */
  rtb_BusCreator13.SteerWhlHeatSts = SteerWhlCtl_SteerWhlHeatSts;
  rtb_BusCreator13.J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHt;
  rtb_BusCreator13.SteerWhlTemp = SteerWhlCtl_SteerWhlTemp;
  rtb_BusCreator13.RemtHeatFb = SteerWhlCtl_RemtHeatFb;

  /* BusCreator: '<S1>/Bus Creator5' */
  rtb_BusCreator5.DrvWinUpSw = WinCtl_DrvWinUpSw;
  rtb_BusCreator5.DrvWinDnSw = WinCtl_DrvWinDnSw;
  rtb_BusCreator5.DrvWinAutoDnSw = WinCtl_DrvWinAutoDnSw;
  rtb_BusCreator5.PsgWinUpSw = WinCtl_PsgWinUpSw;
  rtb_BusCreator5.PsgWinDnSw = WinCtl_PsgWinDnSw;
  rtb_BusCreator5.PsgWinAutoDnSw = WinCtl_PsgWinAutoDnSw;
  rtb_BusCreator5.DrvPsgWinUpSw = WinCtl_DrvPsgWinUpSw;
  rtb_BusCreator5.DrvPsgWinDnSw = WinCtl_DrvPsgWinDnSw;
  rtb_BusCreator5.DrvPsgWinAutoDnSw = WinCtl_DrvPsgWinAutoDnSw;
  rtb_BusCreator5.DrvWinSta = WinCtl_DrvWinSta;
  rtb_BusCreator5.J51DrvWinUp = WinCtl_J51DrvWinUp;
  rtb_BusCreator5.J53DrvWinDn = WinCtl_J53DrvWinDn;
  rtb_BusCreator5.PsgWinSta = WinCtl_PsgWinSta;
  rtb_BusCreator5.J55PsgWinUp = WinCtl_J55PsgWinUp;
  rtb_BusCreator5.J57PsgWinDn = WinCtl_J57PsgWinDn;
  rtb_BusCreator5.DrvWinUpProt = WinCtl_DrvWinUpProt;
  rtb_BusCreator5.PsgWinUpProt = WinCtl_PsgWinUpProt;
  rtb_BusCreator5.DrvWinDnProt = WinCtl_DrvWinDnProt;
  rtb_BusCreator5.PsgWinDnProt = WinCtl_PsgWinDnProt;
  rtb_BusCreator5.DrvWinMotorLocked = WinCtl_DrvWinMotorLocked;
  rtb_BusCreator5.PsgWinMotorLocked = WinCtl_PsgWinMotorLocked;

  /* CCaller: '<S1>/C Caller14' */
  BSW_CN744DrvSeatResis = GetHw_DrvSeatTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SeatCtl' */
  /* Chart: '<S129>/LIB_TPD_Ts1' incorporates:
   *  Constant: '<S129>/Constant11'
   *  Constant: '<S129>/Constant15'
   *  Constant: '<S129>/Constant16'
   *  Constant: '<S129>/Constant17'
   *  DataTypeConversion: '<S129>/Data Type Conversion1'
   *  RelationalOperator: '<S129>/Relational Operator2'
   */
  if (BSW_CN744DrvSeatResis >= SeatCtl_NTCOpenResis_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gi >= (float32)SeatCtl_NTCOpenValidTim_C /
         (SeatCtl_Ts_C * 100.0F)) && (SeatCtl_NTCOpenValidTim_C != 0xFFFF)) {
      SeatCtl_DrvNTCOpen = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gi++;
      AppSwcBcm_ARID_DEF.cnt_heal_ox = (uint16)((float32)
        SeatCtl_NTCOpenInValidTim_C / (SeatCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gi = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ox == 0) {
      SeatCtl_DrvNTCOpen = false;
    } else if (SeatCtl_NTCOpenInValidTim_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ox--;
    }
  }

  /* End of Chart: '<S129>/LIB_TPD_Ts1' */

  /* RelationalOperator: '<S129>/Relational Operator1' incorporates:
   *  Constant: '<S129>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Switch: '<S129>/Switch' */
  if (rtb_RelationalOperator1_c) {
    /* RelationalOperator: '<S129>/Relational Operator3' incorporates:
     *  Constant: '<S129>/Constant20'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator1_c =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
       ->VIPM_HUMaiDrvrSeatHeat_enum != 0);

    /* Switch: '<S129>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator1_c = (rtb_RelationalOperator1_c &&
      ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
       ->VIPM_HUMaiDrvrSeatHeat_enum != 0));

    /* Switch: '<S129>/Switch' */
    rtb_Switch = rtb_RelationalOperator1_c;
  } else {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S129>/Constant10'
     */
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S129>/Switch' */

  /* MultiPortSwitch: '<S129>/Multiport Switch' */
  if (rtb_Switch == 1) {
    /* MultiPortSwitch: '<S129>/Multiport Switch' incorporates:
     *  Constant: '<S129>/Constant1'
     */
    SeatCtl_MaiDrvSeatStFb = 0U;
  }

  /* End of MultiPortSwitch: '<S129>/Multiport Switch' */

  /* MultiPortSwitch: '<S129>/Multiport Switch1' */
  switch (SeatCtl_MaiDrvSeatStFb) {
   case 1:
    /* MultiPortSwitch: '<S129>/Multiport Switch1' incorporates:
     *  Constant: '<S129>/Constant5'
     */
    rtb_Switch = SeatCtl_DrvTempLvl1_C;
    break;

   case 2:
    /* MultiPortSwitch: '<S129>/Multiport Switch1' incorporates:
     *  Constant: '<S129>/Constant6'
     */
    rtb_Switch = SeatCtl_DrvTempLvl2_C;
    break;

   case 3:
    /* MultiPortSwitch: '<S129>/Multiport Switch1' incorporates:
     *  Constant: '<S129>/Constant7'
     */
    rtb_Switch = SeatCtl_DrvTempLvl3_C;
    break;

   default:
    /* MultiPortSwitch: '<S129>/Multiport Switch1' incorporates:
     *  Constant: '<S129>/Constant8'
     */
    rtb_Switch = SeatCtl_DrvTempLvl0_C;
    break;
  }

  /* End of MultiPortSwitch: '<S129>/Multiport Switch1' */

  /* DataTypeConversion: '<S129>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S129>/Data Type Conversion1'
   *  Lookup_n-D: '<S129>/1-D Lookup Table2'
   */
  SeatCtl_DrvSeatTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_CN744DrvSeatResis, (const float32 *)&SeatCtl_DrvSeatTempLookUp_X[0], (
    const float32 *)&SeatCtl_DrvSeatTempLookUp_Y[0], 23U));

  /* Chart: '<S129>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S129>/Constant'
   *  Constant: '<S129>/Constant12'
   *  Constant: '<S129>/Constant13'
   *  Constant: '<S129>/Constant14'
   *  DataTypeConversion: '<S129>/Data Type Conversion1'
   *  RelationalOperator: '<S129>/Relational Operator'
   */
  if (BSW_CN744DrvSeatResis <= SeatCtl_NTCShortResis_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_k0 >= (float32)SeatCtl_NTCShortValidTim_C
         / (SeatCtl_Ts_C * 100.0F)) && (SeatCtl_NTCShortValidTim_C != 0xFFFF)) {
      SeatCtl_DrvNTCShort = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k0++;
      AppSwcBcm_ARID_DEF.cnt_heal_j = (uint16)((float32)
        SeatCtl_NTCShortInValidTim_C / (SeatCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k0 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_j == 0) {
      SeatCtl_DrvNTCShort = false;
    } else if (SeatCtl_NTCShortInValidTim_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_j--;
    }
  }

  /* End of Chart: '<S129>/LIB_TPD_Ts' */

  /* Chart: '<S129>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_j;
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib == AppSwcBcm_IN_Off_j) {
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    if ((rtb_Switch - SeatCtl_DrvSeatTemp >= SeatCtl_HtDiffTemp_C) &&
        (rtb_Switch != 0) && (!SeatCtl_DrvNTCShort) && (!SeatCtl_DrvNTCOpen)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_On_e;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    }
  } else {
    /* case IN_On: */
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    if ((SeatCtl_DrvSeatTemp >= rtb_Switch) || (rtb_Switch == 0) ||
        SeatCtl_DrvNTCShort || SeatCtl_DrvNTCOpen) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_j;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    }
  }

  /* End of Chart: '<S129>/Chart' */

  /* Outputs for Atomic SubSystem: '<S129>/Ovrd' */
  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S129>/Constant18'
   */
  if (SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C) {
    /* Switch: '<S134>/Switch' incorporates:
     *  Constant: '<S129>/Constant19'
     */
    SeatCtl_CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;
  } else {
    /* Switch: '<S134>/Switch' */
    SeatCtl_CN167DrvSeatHtPWM = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
  }

  /* End of Switch: '<S134>/Switch' */
  /* End of Outputs for SubSystem: '<S129>/Ovrd' */

  /* Chart: '<S129>/HeatFb' incorporates:
   *  Constant: '<S1>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init_d;
    SeatCtl_RemtHeatFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_on = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib) {
     case AppSwcBcm_IN_Fail_j:
      SeatCtl_RemtHeatFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_on >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init_d;
        SeatCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_on = 0U;
      } else {
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_on + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_on + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_on = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;

     case AppSwcBcm_IN_Init_d:
      SeatCtl_RemtHeatFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_g0 = false;

      /* Outputs for Function Call SubSystem: '<S131>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_e(AppSwcBcm_ARID_DEF.Lib_blIn_g0,
        &AppSwcBcm_ARID_DEF.LogicalOperator_nc,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_k);

      /* End of Outputs for SubSystem: '<S131>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_nc) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Wait_g;
      }
      break;

     case AppSwcBcm_IN_Suc_n:
      SeatCtl_RemtHeatFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_on >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init_d;
        SeatCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_on = 0U;
      } else {
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_on + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_on + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_on = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;

     default:
      /* case IN_Wait: */
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Suc_n;
        SeatCtl_RemtHeatFb = 1U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_on + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_on + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_on = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      } else {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Fail_j;
        SeatCtl_RemtHeatFb = 3U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_on + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_on + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_on = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;
    }
  }

  /* End of Chart: '<S129>/HeatFb' */
  /* End of Outputs for SubSystem: '<S1>/SeatCtl' */

  /* BusCreator: '<S1>/Bus Creator11' */
  rtb_BusCreator11.MaiDrvSeatStFb = SeatCtl_MaiDrvSeatStFb;
  rtb_BusCreator11.CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWM;
  rtb_BusCreator11.DrvSeatTemp = SeatCtl_DrvSeatTemp;
  rtb_BusCreator11.DrvNTCShort = SeatCtl_DrvNTCShort;
  rtb_BusCreator11.DrvNTCOpen = SeatCtl_DrvNTCOpen;
  rtb_BusCreator11.RemtHeatFb = SeatCtl_RemtHeatFb;

  /* Outputs for Atomic SubSystem: '<S1>/EEWriteCtl' */
  AppSwcBcm_EEWriteCtl();

  /* End of Outputs for SubSystem: '<S1>/EEWriteCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus(&rtb_BusCreator11);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus(&rtb_BusCreator5);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus(&rtb_BusCreator16);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus(&rtb_BusCreator7);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus(&rtb_BusCreator13);
}

/* Model initialize function */
void AppSwcBcm_Init(void)
{
  {
    sint32 i;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_20ms'
     */
    /* SystemInitialize for BusCreator: '<S3>/Bus Creator12' */
    AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts = EEReadCtl_BodyWarnSts;
    AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb = EEReadCtl_FlwrMeHomeCtlFb;
    AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb = EEReadCtl_BackLadjvalFb;
    AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta = EEReadCtl_HazardLightSta;
    AppSwcBcm_ARID_DEF.BusCreator12.IllmndLckSts = EEReadCtl_IllmndLckSts;
    AppSwcBcm_ARID_DEF.BusCreator12.SpdCtlLckSet = EEReadCtl_SpdCtlLckSet;
    AppSwcBcm_ARID_DEF.BusCreator12.ParkAutoUnlockSetFb =
      EEReadCtl_ParkAutoUnlockSetFb;
    AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts = EEReadCtl_LockHoornOnSts;
    AppSwcBcm_ARID_DEF.BusCreator12.CrashSta = EEReadCtl_CrashSta;
    AppSwcBcm_ARID_DEF.BusCreator12.IllmndUnlckSts = EEReadCtl_IllmndUnlckSts;
    AppSwcBcm_ARID_DEF.BusCreator12.InrTim = EEReadCtl_InrTim;
    AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb =
      EEReadCtl_WiprIntlTimeSetFb;
    for (i = 0; i < 10; i++) {
      AppSwcBcm_ARID_DEF.BusCreator12.DoorOpRecord[i] = EEReadCtl_DoorOpRecord[i];
      AppSwcBcm_ARID_DEF.BusCreator12.LocalStartFailOpRecord[i] =
        EEReadCtl_LocalStartFailOpRecord[i];
      AppSwcBcm_ARID_DEF.BusCreator12.RemoteStartFailRecord[i] =
        EEReadCtl_RemoteStartFailRecord[i];
      AppSwcBcm_ARID_DEF.BusCreator12.TrunkOpRecord[i] =
        EEReadCtl_TrunkOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.BusCreator12.TrunkLckSw = EEReadCtl_TrunkLckSw;
    AppSwcBcm_ARID_DEF.BusCreator12.DriverDoorLckSw = EEReadCtl_DriverDoorLckSw;
    AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarFLSw = EEReadCtl_DoorAjarFLSw;
    AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarFRSw = EEReadCtl_DoorAjarFRSw;
    AppSwcBcm_ARID_DEF.BusCreator12.TrunkSw = EEReadCtl_TrunkSw;
    AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarRLSw = EEReadCtl_DoorAjarRLSw;
    AppSwcBcm_ARID_DEF.BusCreator12.DoorAjarRRSw = EEReadCtl_DoorAjarRRSw;
    AppSwcBcm_ARID_DEF.BusCreator12.TrunkAjarSw = EEReadCtl_TrunkAjarSw;
    AppSwcBcm_ARID_DEF.BusCreator12.DrvSeatSw = EEReadCtl_DrvSeatSw;
    AppSwcBcm_ARID_DEF.BusCreator12.RemotePwrLckSta = EEReadCtl_RemotePwrLckSta;

    /* End of SystemInitialize for BusCreator: '<S3>/Bus Creator12' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/HornCtl' */
    AppSwcBcm_HornCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/HornCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/LampCtl' */
    AppSwcBcm_LampCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/LampCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/WiperCtl' */
    AppSwcBcm_WiperCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/WiperCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/BCMTx' */
    AppSwcBcm_BCMTx_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/BCMTx' */
    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' */

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_50ms'
     */
    /* SystemInitialize for Atomic SubSystem: '<S4>/DoorLckCtl' */
    AppSwcBcm_DoorLckCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/DoorLckCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/PDUCtl' */
    AppSwcBcm_PDUCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/PDUCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/AlmSysCtl' */
    AppSwcBcm_AlmSysCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/AlmSysCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/ESCLCtl' */
    AppSwcBcm_ESCLCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/ESCLCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/IMMOCtl' */
    AppSwcBcm_IMMOCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/IMMOCtl' */

    /* SystemInitialize for BusCreator: '<S4>/Bus Creator14' */
    for (i = 0; i < 8; i++) {
      AppSwcBcm_ARID_DEF.BusCreator14.AuthResp[i] = IMMOCtl_AuthResp[i];
    }

    AppSwcBcm_ARID_DEF.BusCreator14.SKSta = IMMOCtl_SKSta;
    for (i = 0; i < 16; i++) {
      AppSwcBcm_ARID_DEF.BusCreator14.SKRead[i] = IMMOCtl_SKRead[i];
    }

    /* End of SystemInitialize for BusCreator: '<S4>/Bus Creator14' */

    /* SystemInitialize for BusCreator: '<S4>/Bus Creator2' */
    AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts = AlmSysCtl_BodyWarnSts;
    AppSwcBcm_ARID_DEF.BusCreator2.AlrmWarnTimOut = AlmSysCtl_AlrmWarnTimOut;

    /* SystemInitialize for Atomic SubSystem: '<S4>/BatSaveCtl' */
    AppSwcBcm_BatSaveCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/BatSaveCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/WakeUpCtl' */
    AppSwcBcm_WakeUpCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/WakeUpCtl' */
    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' */

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_100ms'
     */
    /* SystemInitialize for Atomic SubSystem: '<S1>/WinCtl' */
    AppSwcBcm_WinCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S1>/WinCtl' */
    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' */

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_10ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_10ms'
     */
    /* SystemInitialize for BusCreator: '<S2>/Bus Creator10' */
    AppSwcBcm_ARID_DEF.BusCreator10.KeyInCarSta = PEPSCtl_KeyInCarSta;
    AppSwcBcm_ARID_DEF.BusCreator10.FRPEAuthentAcsd = PEPSCtl_FRPEAuthentAcsd;
    AppSwcBcm_ARID_DEF.BusCreator10.DrvPEAuthentAcsd = PEPSCtl_DrvPEAuthentAcsd;
    AppSwcBcm_ARID_DEF.BusCreator10.AvaluebleKeyInCar =
      PEPSCtl_AvaluebleKeyInCar;
    AppSwcBcm_ARID_DEF.BusCreator10.PSAuthentRes = PEPSCtl_PSAuthentRes;
    AppSwcBcm_ARID_DEF.BusCreator10.WarnNoKeyFound = PEPSCtl_WarnNoKeyFound;
    AppSwcBcm_ARID_DEF.BusCreator10.KeySta = PEPSCtl_KeySta;
    AppSwcBcm_ARID_DEF.BusCreator10.IndicationKeyCloser =
      PEPSCtl_IndicationKeyCloser;
    AppSwcBcm_ARID_DEF.BusCreator10.UnlckWlcmReq = PEPSCtl_UnlckWlcmReq;
    AppSwcBcm_ARID_DEF.BusCreator10.LckWlcmReq = PEPSCtl_LckWlcmReq;
    AppSwcBcm_ARID_DEF.BusCreator10.FrbdnKeyNr = PEPSCtl_FrbdnKeyNr;
    AppSwcBcm_ARID_DEF.BusCreator10.KeyLoBattLvlWarn = PEPSCtl_KeyLoBattLvlWarn;
    AppSwcBcm_ARID_DEF.BusCreator10.WarnKeyOutReminder =
      PEPSCtl_WarnKeyOutReminder;
    AppSwcBcm_ARID_DEF.BusCreator10.PSReq = PEPSCtl_PSReq;
    AppSwcBcm_ARID_DEF.BusCreator10.IMMOKey = PEPSCtl_IMMOKey;

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_10ms' */

    /* SystemInitialize for DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
    Rte_IrvIWrite_AppSwcBcm_Init_AlmSysCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator2);

    /* SystemInitialize for DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
    Rte_IrvIWrite_AppSwcBcm_Init_EEReadCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator12);

    /* SystemInitialize for DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
    Rte_IrvIWrite_AppSwcBcm_Init_IMMOCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator14);

    /* SystemInitialize for DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms' */
    Rte_IrvIWrite_AppSwcBcm_Init_PEPSCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator10);

    /* ConstCode for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_50ms'
     */
    /* ConstCode for Atomic SubSystem: '<S4>/DoorLckCtl' */
    AppSwcBcm_DoorLckCtl_Const();

    /* End of ConstCode for SubSystem: '<S4>/DoorLckCtl' */
    /* End of ConstCode for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
