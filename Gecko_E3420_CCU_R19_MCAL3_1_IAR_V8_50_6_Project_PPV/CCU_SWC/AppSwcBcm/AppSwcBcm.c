/*
 * File: AppSwcBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1537
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Dec 30 17:33:19 2024
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

/* Named constants for Chart: '<S159>/Chart6' */
#define AppSwcBcm_IN_Off               ((uint8)1U)
#define AppSwcBcm_IN_On                ((uint8)2U)

/* Named constants for Chart: '<S136>/Chart' */
#define AppSwcBcm_IN_Off_m             ((uint8)1U)
#define AppSwcBcm_IN_On_h              ((uint8)2U)

/* Named constants for Chart: '<S136>/HeatFb' */
#define AppSwcBcm_IN_Fail              ((uint8)1U)
#define AppSwcBcm_IN_Init              ((uint8)2U)
#define AppSwcBcm_IN_Suc               ((uint8)3U)
#define AppSwcBcm_IN_Wait              ((uint8)4U)

/* Named constants for Chart: '<S144>/HeatCtl' */
#define AppSwcBcm_IN_Off_g             ((uint8)1U)
#define AppSwcBcm_IN_On_m              ((uint8)2U)

/* Named constants for Chart: '<S144>/HeatFb' */
#define AppSwcBcm_IN_Fail_n            ((uint8)1U)
#define AppSwcBcm_IN_Init_o            ((uint8)2U)
#define AppSwcBcm_IN_Suc_h             ((uint8)3U)
#define AppSwcBcm_IN_Wait_k            ((uint8)4U)

/* Named constants for Chart: '<S144>/HeatSet' */
#define AppSwcBcm_IN_OFF               ((uint8)1U)
#define AppSwcBcm_IN_ON                ((uint8)2U)

/* Named constants for Chart: '<S11>/DrvWinCtl' */
#define AppSwcBcm_IN_AutoDown          ((uint8)1U)
#define AppSwcBcm_IN_ManDown           ((uint8)2U)
#define AppSwcBcm_IN_ManUp             ((uint8)3U)
#define AppSwcBcm_IN_Standby           ((uint8)4U)

/* Named constants for Chart: '<S11>/PsgWinCtl' */
#define AppSwcBcm_IN_AutoDown_n        ((uint8)1U)
#define AppSwcBcm_IN_ManDown_h         ((uint8)2U)
#define AppSwcBcm_IN_ManUp_c           ((uint8)3U)
#define AppSwcBcm_IN_Standby_b         ((uint8)4U)

/* Named constants for Chart: '<S159>/Chart1' */
#define AppSwcBcm_IN_HoldOn            ((uint8)1U)
#define AppSwcBcm_IN_Off_d             ((uint8)2U)
#define AppSwcBcm_IN_On_i              ((uint8)3U)

/* Named constants for Chart: '<S159>/Chart11' */
#define AppSwcBcm_IN_Off_a             ((uint8)1U)
#define AppSwcBcm_IN_On_hd             ((uint8)2U)

/* Named constants for Chart: '<S245>/Chart' */
#define AppSwcBcm_IN_FobidKey          ((uint8)1U)
#define AppSwcBcm_IN_Init_h            ((uint8)2U)
#define AppSwcBcm_IN_RelesKey          ((uint8)3U)

/* Named constants for Chart: '<S246>/Chart' */
#define AppSwcBcm_IN_Init_p            ((uint8)1U)
#define AppSwcBcm_IN_KeyNotInCar       ((uint8)2U)

/* Named constants for Chart: '<S246>/Chart3' */
#define AppSwcBcm_IN_Finish            ((uint8)1U)
#define AppSwcBcm_IN_KeyValid          ((uint8)3U)

/* Named constants for Chart: '<S247>/Chart' */
#define AppSwcBcm_IN_LSeekKeyOut       ((uint8)2U)
#define AppSwcBcm_IN_RSeekKeyOut       ((uint8)3U)

/* Named constants for Chart: '<S247>/Chart3' */
#define AppSwcBcm_IN_KeyValid_e        ((uint8)2U)

/* Named constants for Chart: '<S248>/Chart' */
#define AppSwcBcm_IN_PSSeekKeyOut      ((uint8)2U)

/* Named constants for Chart: '<S248>/Chart1' */
#define AppSwcBcm_IN_IMMOKeyValid      ((uint8)1U)
#define AppSwcBcm_IN_RemoteKeyValid    ((uint8)3U)

/* Named constants for Chart: '<S248>/Chart2' */
#define AppSwcBcm_IN_NokeyTimecount    ((uint8)2U)
#define AppSwcBcm_IN_SendKeyCloser     ((uint8)3U)
#define AppSwcBcm_IN_SendNOKey         ((uint8)4U)

/* Named constants for Chart: '<S249>/Chart' */
#define AppSwcBcm_IN_LockWlcm          ((uint8)2U)
#define AppSwcBcm_IN_UnlockDay0to7     ((uint8)3U)
#define AppSwcBcm_IN_UnlockExcedDay7   ((uint8)4U)
#define AppSwcBcm_IN_WlcmLockReq       ((uint8)5U)
#define AppSwcBcm_IN_WlcmUnlockReq     ((uint8)6U)

/* Named constants for Chart: '<S314>/Alarm' */
#define AppSwcBcm_IN_SetON             ((uint8)1U)
#define AppSwcBcm_IN_SetOff            ((uint8)2U)

/* Named constants for Chart: '<S322>/Seek' */
#define AppSwcBcm_IN_RKESetON          ((uint8)1U)
#define AppSwcBcm_IN_TboxSetON         ((uint8)3U)

/* Named constants for Chart: '<S323>/Chart1' */
#define AppSwcBcm_IN_SetOff_i          ((uint8)1U)
#define AppSwcBcm_IN_SetOn             ((uint8)2U)

/* Named constants for Chart: '<S356>/Chart' */
#define AppSwcBcm_IN_HiSpd             ((uint8)1U)
#define AppSwcBcm_IN_Inr               ((uint8)2U)
#define AppSwcBcm_IN_LowSpd            ((uint8)3U)
#define AppSwcBcm_IN_Maint             ((uint8)1U)
#define AppSwcBcm_IN_Mist              ((uint8)4U)
#define AppSwcBcm_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define AppSwcBcm_IN_Nrm               ((uint8)2U)
#define AppSwcBcm_IN_Off_go            ((uint8)5U)
#define AppSwcBcm_IN_Wash              ((uint8)3U)

/* Named constants for Chart: '<S405>/AlmSysLogic' */
#define AppSwcBcm_IN_Alarm             ((uint8)1U)
#define AppSwcBcm_IN_Armed             ((uint8)2U)
#define AppSwcBcm_IN_Disarmed          ((uint8)3U)
#define AppSwcBcm_IN_Init_m            ((uint8)4U)
#define AppSwcBcm_IN_PartArmed         ((uint8)5U)

/* Named constants for Chart: '<S407>/DoorDrv' */
#define AppSwcBcm_IN_DrvIdle           ((uint8)1U)
#define AppSwcBcm_IN_InsDrvLck         ((uint8)2U)
#define AppSwcBcm_IN_InsDrvUnlck       ((uint8)3U)
#define AppSwcBcm_IN_OsDrvLck          ((uint8)4U)
#define AppSwcBcm_IN_OsDrvUnlck        ((uint8)5U)
#define AppSwcBcm_IN_TrunkUnlck        ((uint8)6U)

/* Named constants for Chart: '<S461>/Chart' */
#define AppSwcBcm_IN_Fail1             ((uint8)1U)
#define AppSwcBcm_IN_Init1             ((uint8)2U)
#define AppSwcBcm_IN_Suc1              ((uint8)3U)
#define AppSwcBcm_IN_Wait1             ((uint8)4U)

/* Named constants for Chart: '<S628>/Chart' */
#define AppSwcBcm_IN_Off_gk            ((uint8)1U)
#define AppSwcBcm_IN_On_in             ((uint8)2U)

/* Named constants for Chart: '<S632>/Chart' */
#define AppSwcBcm_IN_Day               ((uint8)1U)
#define AppSwcBcm_IN_Night             ((uint8)2U)

/* Named constants for Chart: '<S752>/Chart' */
#define AppSwcBcm_IN_NO_ACTIVE_CHILD_c ((uint8)0U)
#define AppSwcBcm_IN_SetOff_b          ((uint8)1U)
#define AppSwcBcm_IN_SetOn_o           ((uint8)2U)

/* Named constants for Chart: '<S753>/Chart' */
#define AppSwcBcm_IN_Off_i             ((uint8)1U)
#define AppSwcBcm_IN_On_c              ((uint8)2U)

/* Named constants for Chart: '<S755>/Chart1' */
#define AppSwcBcm_IN_CrashOff          ((uint8)1U)
#define AppSwcBcm_IN_CrashOn           ((uint8)2U)
#define AppSwcBcm_IN_Init_d            ((uint8)3U)

/* Named constants for Chart: '<S654>/HazardLightLogic' */
#define AppSwcBcm_IN_EmerON            ((uint8)1U)
#define AppSwcBcm_IN_OFF_i             ((uint8)2U)
#define AppSwcBcm_IN_ON_h              ((uint8)3U)

/* Named constants for Chart: '<S759>/Chart' */
#define AppSwcBcm_IN_SetOn1            ((uint8)2U)
#define AppSwcBcm_IN_SetOn2            ((uint8)3U)

/* Named constants for Chart: '<S763>/Chart' */
#define AppSwcBcm_IN_Delay             ((uint8)1U)
#define AppSwcBcm_IN_SetOff_h          ((uint8)2U)
#define AppSwcBcm_IN_SetOn_o0          ((uint8)3U)

/* Named constants for Chart: '<S654>/TurnIndcrArb2' */
#define AppSwcBcm_IN_AntiLck           ((uint8)1U)
#define AppSwcBcm_IN_Armed_p           ((uint8)2U)
#define AppSwcBcm_IN_Disarmed_n        ((uint8)3U)
#define AppSwcBcm_IN_PartArmed_g       ((uint8)4U)
#define AppSwcBcm_IN_Pri1              ((uint8)1U)
#define AppSwcBcm_IN_Pri2              ((uint8)2U)
#define AppSwcBcm_IN_Pri3              ((uint8)3U)
#define AppSwcBcm_IN_Pri4              ((uint8)4U)
#define AppSwcBcm_IN_Pri5              ((uint8)5U)
#define AppSwcBcm_IN_RodBeam           ((uint8)5U)
#define AppSwcBcm_IN_Seek              ((uint8)6U)
#define AppSwcBcm_IN_Trans             ((uint8)6U)
#define AppSwcBcm_IN_Trans_i           ((uint8)7U)
#define AppSwcBcm_IN_TrunkWarn         ((uint8)8U)
#define AppSwcBcm_IN_VehMode           ((uint8)9U)

/* Named constants for Chart: '<S654>/TurnIndcrLogic' */
#define AppSwcBcm_IN_LongFlash         ((uint8)1U)
#define AppSwcBcm_IN_OFF_p             ((uint8)1U)
#define AppSwcBcm_IN_ShortFlash        ((uint8)2U)
#define AppSwcBcm_IN_TurnL             ((uint8)2U)
#define AppSwcBcm_IN_TurnR             ((uint8)3U)

/* Named constants for Chart: '<S654>/TurnIndcrSelect' */
#define AppSwcBcm_IN_TurnLOn           ((uint8)2U)
#define AppSwcBcm_IN_TurnLROn          ((uint8)3U)
#define AppSwcBcm_IN_TurnROn           ((uint8)4U)

/* Named constants for Chart: '<S770>/Chart' */
#define AppSwcBcm_IN_Init_f            ((uint8)1U)
#define AppSwcBcm_IN_Limit             ((uint8)2U)
#define AppSwcBcm_IN_Nrm_p             ((uint8)3U)
#define AppSwcBcm_IN_Show              ((uint8)4U)

/* Named constants for Chart: '<S771>/Chart' */
#define AppSwcBcm_IN_RKESetOn          ((uint8)1U)
#define AppSwcBcm_IN_TboxSetOn         ((uint8)3U)

/* Named constants for Chart: '<S771>/SeekFb' */
#define AppSwcBcm_IN_Fail_k            ((uint8)1U)
#define AppSwcBcm_IN_Init_j            ((uint8)2U)
#define AppSwcBcm_IN_Suc_l             ((uint8)3U)
#define AppSwcBcm_IN_Wait_kv           ((uint8)4U)

/* Named constants for Chart: '<S412>/Chart' */
#define AppSwcBcm_IN_LocalOn           ((uint8)1U)
#define AppSwcBcm_IN_OTA1On            ((uint8)2U)
#define AppSwcBcm_IN_OTAOn             ((uint8)3U)
#define AppSwcBcm_IN_PSOff             ((uint8)4U)
#define AppSwcBcm_IN_RemoteOn          ((uint8)5U)

/* Named constants for Chart: '<S891>/BrkPwrOn' */
#define AppSwcBcm_IN_Invalid           ((uint8)1U)
#define AppSwcBcm_IN_Valid             ((uint8)2U)

/* Named constants for Chart: '<S891>/RemoteLck' */
#define AppSwcBcm_IN_Init_oy           ((uint8)1U)
#define AppSwcBcm_IN_Lck               ((uint8)2U)
#define AppSwcBcm_IN_Unlck             ((uint8)3U)

/* Named constants for Chart: '<S412>/RemtPwrCtlFb' */
#define AppSwcBcm_IN_Fail_p            ((uint8)1U)
#define AppSwcBcm_IN_Init_k            ((uint8)2U)
#define AppSwcBcm_IN_Suc_he            ((uint8)3U)
#define AppSwcBcm_IN_Wait_n            ((uint8)4U)

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S629>/Constant28' */

/* Invariant block signals (default storage) */
const ConstB_AppSwcBcm_T AppSwcBcm_ConstB = {
  0U,                                  /* '<S267>/Data Type Conversion39' */
  1,                                   /* '<S676>/Relational Operator' */
  1,                                   /* '<S677>/Relational Operator1' */
  1,                                   /* '<S489>/Relational Operator6' */
  1                                    /* '<S466>/Relational Operator1' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_AppSwcBcm_T AppSwcBcm_ARID_DEF;
#pragma default_function_attributes = @".iram_func"
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
static void AppSwcBcm_Lib_RiseEdgeDet_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_n_T
  *AppSwcBcm__ARID_DEF_arg);
static uint16 AppSwcBcm_BitShift1_m(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u);
static void AppSwcBcm_Lib_RiseEdgeDet_n(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_j_T
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
static void AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_d_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_n_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_n_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg);
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg);
static uint16 AppSwcBcm_BitShift1_k(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u);
static void AppSwcBcm_NrmOffLib_RiseEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_NrmOffLib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_l(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_a(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut);
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  rtu_LIB_bInit, boolean *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static uint16 AppSwcBcm_BitShift12_e(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift6(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u);
static void AppSwcBcm_LIB_TPD_10ms11_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms11(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms11_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
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
static boolean AppSwcBcm_Lib_FailEdgeDetHold(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDetHold_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
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
static boolean AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_m_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_DTCSet_Update(void);
static void AppSwcBcm_DTCSet(void);
static void AppSwcBcm_EEWriteCtl(void);
static void AppSwcBcm_IODID(void);
static void AppSwcBcm_RVMCtl(void);
static void AppSwcBcm_SeatCtl(void);
static void AppSwcBcm_SteerWhlCtl(void);
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
static void AppSwcBcm_LockedRotorProt_Init(void);
static void AppSwcBcm_LockedRotorProt(void);
static void AppSwcBcm_SignalProcess(void);
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
static void AppSwcBcm_DoorDrv_Init(void);
static void AppSwcBcm_DoorDrv(void);
static void AppSwcBcm_AntiLckProt(void);
static void AppSwcBcm_IllmndLckSet_Init(void);
static void AppSwcBcm_IllmndLckSet(void);
static void AppSwcBcm_IllmndUnlckSet_Init(void);
static void AppSwcBcm_IllmndUnlckSet(void);
static void AppSwcBcm_HULck(void);
static void AppSwcBcm_SpdLck_Init(void);
static void AppSwcBcm_SpdLck(void);
static void AppSwcBcm_InsideLck_Init(void);
static void AppSwcBcm_InsideLck(void);
static void AppSwcBcm_InsideUnlck(void);
static void AppSwcBcm_MotorProt(void);
static void AppSwcBcm_AutoLck_Init(void);
static void AppSwcBcm_AutoLck(void);
static void AppSwcBcm_MechLck_Init(void);
static void AppSwcBcm_MechLck(void);
static void AppSwcBcm_PELck(void);
static void AppSwcBcm_RKELck(void);
static void AppSwcBcm_TboxLck(void);
static void AppSwcBcm_TrunkAutoLck(void);
static void AppSwcBcm_WelcomeLck(void);
static void AppSwcBcm_OutsideLck_Init(void);
static void AppSwcBcm_OutsideLck(void);
static void AppSwcBcm_MechUnlck_Init(void);
static void AppSwcBcm_MechUnlck(void);
static void AppSwcBcm_PEUnlck(void);
static void AppSwcBcm_RKEUnlck(void);
static void AppSwcBcm_TboxUnlck(void);
static void AppSwcBcm_TrunkUnlck_Init(void);
static void AppSwcBcm_TrunkUnlck(void);
static void AppSwcBcm_WelcomeUnlck(void);
static void AppSwcBcm_OutsideUnlck_Init(void);
static void AppSwcBcm_OutsideUnlck(void);
static void AppSwcBcm_PECtl(void);
static void AppSwcBcm_ParkUnlckSet_Init(void);
static void AppSwcBcm_ParkUnlckSet(void);
static void AppSwcBcm_SpdLck_l_Const(void);
static void AppSwcBcm_TboxLckFb(void);
static void AppSwcBcm_DoorLckCtlLogic_Init(void);
static void AppSwcBcm_DoorLckCtlLogic_Const(void);
static void AppSwcBcm_DoorLckCtlLogic(void);
static void AppSwcBcm_SignalProcess_b_Const(void);
static void AppSwcBcm_SignalProcess_d(void);
static void AppSwcBcm_DoorLckCtl_Init(void);
static void AppSwcBcm_DoorLckCtl_Update(void);
static void AppSwcBcm_DoorLckCtl_Const(void);
static void AppSwcBcm_DoorLckCtl(void);
static void AppSwcBcm_DynDID(void);
static void AppSwcBcm_ESCLCtl_Init(void);
static void AppSwcBcm_ESCLCtl(void);
static void AppSwcBcm_IMMOCtl_Init(void);
static void AppSwcBcm_IMMOCtl(void);
static void AppSwcBcm_ADASLampCtl_Init(void);
static void AppSwcBcm_ADASLampCtl(void);
static void AppSwcBcm_AutoLampCtl_Init(void);
static void AppSwcBcm_AutoLampCtl(void);
static void AppSwcBcm_BackLampCtl_Init(void);
static void AppSwcBcm_BackLampCtl(void);
static void AppSwcBcm_BoxLampCtl_Init(void);
static void AppSwcBcm_BoxLampCtl(void);
static void AppSwcBcm_DayRunLampCtl(void);
static void AppSwcBcm_DomeLampCtl_Init(void);
static void AppSwcBcm_DomeLampCtl(void);
static void AppSwcBcm_FogLampRCtl(void);
static void AppSwcBcm_HiBeamCtl(void);
static void AppSwcBcm_KnobBeamDig(void);
static void AppSwcBcm_LampDelayCtl_Init(void);
static void AppSwcBcm_LampDelayCtl(void);
static void AppSwcBcm_LightIntstDet(void);
static void AppSwcBcm_LowBeamCtl_Init(void);
static void AppSwcBcm_LowBeamCtl(void);
static void AppSwcBcm_OTAPwrOffLight(void);
static void AppSwcBcm_BrakeLampCtl(void);
static void AppSwcBcm_ReverseLampCtl(void);
static void AppSwcBcm_PassLampFunc(void);
static void AppSwcBcm_PosLampCtl_Init(void);
static void AppSwcBcm_PosLampCtl(void);
static void AppSwcBcm_SignalProcess_b_Init(void);
static void AppSwcBcm_SignalProcess_j(void);
static void AppSwcBcm_TurnIndcrCtl_Init(void);
static void AppSwcBcm_TurnIndcrCtl(void);
static void AppSwcBcm_Lib_RiseEdgeDet_p(void);
static void AppSwcBcm_Lib_ChangeEdge_h(void);
static void AppSwcBcm_WelcomeLampCtl_Init(void);
static void AppSwcBcm_WelcomeLampCtl(void);
static void AppSwcBcm_LampCtl_Init(void);
static void AppSwcBcm_LampCtl_Update(void);
static void AppSwcBcm_LampCtl(void);
static void AppSwcBcm_Chart(void);
static void AppSwcBcm_PwrOff_Init(void);
static void AppSwcBcm_PwrOff(void);
static void AppSwcBcm_PwrOn_Init(void);
static void AppSwcBcm_PwrOn(void);
static void AppSwcBcm_RelayDig(void);
static void AppSwcBcm_StartReq_Init(void);
static void AppSwcBcm_StartReq(void);
static void AppSwcBcm_Subsystem(void);
static void AppSwcBcm_TruthTable_k(void);
static void AppSwcBcm_PDUCtl_Init(void);
static void AppSwcBcm_PDUCtl(void);
static void AppSwcBcm_NMCtl_Init(void);
static void AppSwcBcm_NMCtl(void);
static void AppSwcBcm_SleepCtl_Init(void);
static void AppSwcBcm_SleepCtl_Update(void);
static void AppSwcBcm_SleepCtl(void);
static void AppSwcBcm_WakeUpCtl_Init(void);
static void AppSwcBcm_WakeUpCtl_Update(void);
static void AppSwcBcm_WakeUpCtl(void);

/* Forward declaration for local functions */
static void AppSwcBcm_enter_internal_Off(void);
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

/* Forward declaration for local functions */
static boolean AppSwcBcm_EmerOff(void);
static boolean AppSwcBcm_HazardOff(void);
static boolean AppSwcBcm_TurnOff(void);
static boolean AppSwcBcm_CrashHazardOff(void);
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
static void AppSwcBcm_PwrOnDelayFunc(void);
static void AppSwcBcm_CrashClearFunc(void);
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

/* Outputs for atomic system: '<S1>/DTCSet' */
static void AppSwcBcm_DTCSet(void)
{
  uint8 rtb_DataTypeConversion;
  boolean rtb_RelationalOperator5;

  /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay5'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->HiBeamShortToBat != AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_g);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900512' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtb_RelationalOperator5) {
    /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
      )->HiBeamShortToBat;

    /* CCaller: '<S17>/C Caller' */
    App_Call_Event_DTC_0x900512_SetEventStatus(rtb_DataTypeConversion);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900512' */

  /* RelationalOperator: '<S5>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay4'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->LowBeamShortToBat != AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_b);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900412' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (rtb_RelationalOperator5) {
    /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
      )->LowBeamShortToBat;

    /* CCaller: '<S16>/C Caller' */
    App_Call_Event_DTC_0x900412_SetEventStatus(rtb_DataTypeConversion);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900412' */

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrLOpen != AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_au);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900013' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtb_RelationalOperator5) {
    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
      )->TurnIndcrLOpen;

    /* CCaller: '<S13>/C Caller' */
    App_Call_Event_DTC_0x900013_SetEventStatus(rtb_DataTypeConversion);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900013' */

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrLShort != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nn);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900011' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (rtb_RelationalOperator5) {
    /* DataTypeConversion: '<S12>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
      )->TurnIndcrLShort;

    /* CCaller: '<S12>/C Caller' */
    App_Call_Event_DTC_0x900011_SetEventStatus(rtb_DataTypeConversion);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900011' */

  /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay3'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrROpen != AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_dg);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900113' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (rtb_RelationalOperator5) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
      )->TurnIndcrROpen;

    /* CCaller: '<S15>/C Caller' */
    App_Call_Event_DTC_0x900113_SetEventStatus(rtb_DataTypeConversion);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900113' */

  /* RelationalOperator: '<S5>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrRShort != AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900111' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtb_RelationalOperator5) {
    /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
      )->TurnIndcrRShort;

    /* CCaller: '<S14>/C Caller' */
    App_Call_Event_DTC_0x900111_SetEventStatus(rtb_DataTypeConversion);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900111' */
}

/* Update for atomic system: '<S1>/DTCSet' */
static void AppSwcBcm_DTCSet_Update(void)
{
  /* Update for UnitDelay: '<S5>/Unit Delay5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->HiBeamShortToBat;

  /* Update for UnitDelay: '<S5>/Unit Delay4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_b =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->LowBeamShortToBat;

  /* Update for UnitDelay: '<S5>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_au =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrLOpen;

  /* Update for UnitDelay: '<S5>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrLShort;

  /* Update for UnitDelay: '<S5>/Unit Delay3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_dg =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrROpen;

  /* Update for UnitDelay: '<S5>/Unit Delay2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrRShort;
}

/* Output and update for atomic system: '<S1>/EEWriteCtl' */
static void AppSwcBcm_EEWriteCtl(void)
{
  uint16 tmp;
  uint8 i;

  /* Chart: '<S6>/EEWriteCtl' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   * */
  i = 0U;
  if (EEWriteCtl_ImmOvrdFlg_C) {
    NvmBcmBlock_Imm_WriteData((uint8 *)(const uint8 *)&EEWriteCtl_ImmOvrdVal_C[0],
      128U);
  } else {
    AppSwcBcm_ARID_DEF.data1_l[0] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->CrashSta;
    AppSwcBcm_ARID_DEF.data1_l[1] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())->BodyWarnSts;
    AppSwcBcm_ARID_DEF.data1_l[2] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->FlwrMeHomeCtlFb;
    AppSwcBcm_ARID_DEF.data1_l[3] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->BackLadjvalFb;
    AppSwcBcm_ARID_DEF.data1_l[4] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->HazardLightSta;
    AppSwcBcm_ARID_DEF.data1_l[5] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->IllmndLckSts;
    AppSwcBcm_ARID_DEF.data1_l[6] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->IllmndUnlockSts;
    AppSwcBcm_ARID_DEF.data1_l[7] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->SpdCtlLckSet;
    AppSwcBcm_ARID_DEF.data1_l[8] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;
    AppSwcBcm_ARID_DEF.data1_l[9] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_HornCtl_Bus())->LockHoornOnSt;
    AppSwcBcm_ARID_DEF.data1_l[10] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus())->WiprIntlTimeSetFb;
    tmp = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus())->InrTim;
    if (tmp > 255) {
      tmp = 255U;
    }

    AppSwcBcm_ARID_DEF.data1_l[11] = (uint8)tmp;
    AppSwcBcm_ARID_DEF.data1_l[12] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkLckSw;
    AppSwcBcm_ARID_DEF.data1_l[13] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DriverDoorLckSw;
    AppSwcBcm_ARID_DEF.data1_l[14] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarFLSw;
    AppSwcBcm_ARID_DEF.data1_l[15] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarFRSw;
    AppSwcBcm_ARID_DEF.data1_l[16] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkSw;
    AppSwcBcm_ARID_DEF.data1_l[17] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarRLSw;
    AppSwcBcm_ARID_DEF.data1_l[18] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DoorAjarRRSw;
    AppSwcBcm_ARID_DEF.data1_l[19] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkAjarSw;
    AppSwcBcm_ARID_DEF.data1_l[20] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->DrvSeatSw;
    AppSwcBcm_ARID_DEF.data1_l[21] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->RemotePwrLckSta;
    AppSwcBcm_ARID_DEF.data1_l[22] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.data1_l[23] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->StartReq;
    while (i < 10) {
      AppSwcBcm_ARID_DEF.data1_l[i + 29] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF230DoorOpRecord[i];
      AppSwcBcm_ARID_DEF.data1_l[i + 39] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF233RemoteStartUpFailRecord[i];
      AppSwcBcm_ARID_DEF.data1_l[i + 49] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF231TrunkOpRecord[i];
      AppSwcBcm_ARID_DEF.data1_l[i + 59] =
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus())
        ->DynDID_0xF232LocalStartUpFailRecord[i];
      i++;
    }
  }

  /* NvmBcmBlock02WriteData(data,8); */
  NvmBcmBlock_Imm_WriteData((uint8 *)&AppSwcBcm_ARID_DEF.data1_l[0], 128U);

  /* End of Chart: '<S6>/EEWriteCtl' */
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift'
 *    '<S7>/Bit Shift22'
 *    '<S7>/Bit Shift30'
 *    '<S7>/Bit Shift38'
 *    '<S7>/Bit Shift46'
 *    '<S7>/Bit Shift54'
 *    '<S7>/Bit Shift8'
 */
static uint8 AppSwcBcm_BitShift(uint8 rtu_u)
{
  /* MATLAB Function: '<S19>/bit_shift' */
  return rtu_u;
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift1'
 *    '<S7>/Bit Shift23'
 *    '<S7>/Bit Shift31'
 *    '<S7>/Bit Shift39'
 *    '<S7>/Bit Shift47'
 *    '<S7>/Bit Shift55'
 *    '<S7>/Bit Shift9'
 */
static uint8 AppSwcBcm_BitShift1(uint8 rtu_u)
{
  /* MATLAB Function: '<S20>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift10'
 *    '<S7>/Bit Shift16'
 *    '<S7>/Bit Shift2'
 *    '<S7>/Bit Shift24'
 *    '<S7>/Bit Shift32'
 *    '<S7>/Bit Shift40'
 *    '<S7>/Bit Shift48'
 */
static uint8 AppSwcBcm_BitShift10(uint8 rtu_u)
{
  /* MATLAB Function: '<S21>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 2);
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift11'
 *    '<S7>/Bit Shift17'
 *    '<S7>/Bit Shift25'
 *    '<S7>/Bit Shift3'
 *    '<S7>/Bit Shift33'
 *    '<S7>/Bit Shift41'
 *    '<S7>/Bit Shift49'
 */
static uint8 AppSwcBcm_BitShift11(uint8 rtu_u)
{
  /* MATLAB Function: '<S22>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift12'
 *    '<S7>/Bit Shift18'
 *    '<S7>/Bit Shift26'
 *    '<S7>/Bit Shift34'
 *    '<S7>/Bit Shift4'
 *    '<S7>/Bit Shift42'
 *    '<S7>/Bit Shift50'
 */
static uint8 AppSwcBcm_BitShift12(uint8 rtu_u)
{
  /* MATLAB Function: '<S23>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift13'
 *    '<S7>/Bit Shift19'
 *    '<S7>/Bit Shift27'
 *    '<S7>/Bit Shift35'
 *    '<S7>/Bit Shift43'
 *    '<S7>/Bit Shift5'
 *    '<S7>/Bit Shift51'
 */
static uint8 AppSwcBcm_BitShift13(uint8 rtu_u)
{
  /* MATLAB Function: '<S24>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift14'
 *    '<S7>/Bit Shift20'
 *    '<S7>/Bit Shift28'
 *    '<S7>/Bit Shift36'
 *    '<S7>/Bit Shift44'
 *    '<S7>/Bit Shift52'
 *    '<S7>/Bit Shift6'
 */
static uint8 AppSwcBcm_BitShift14(uint8 rtu_u)
{
  /* MATLAB Function: '<S25>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 6);
}

/*
 * Output and update for atomic system:
 *    '<S7>/Bit Shift15'
 *    '<S7>/Bit Shift21'
 *    '<S7>/Bit Shift29'
 *    '<S7>/Bit Shift37'
 *    '<S7>/Bit Shift45'
 *    '<S7>/Bit Shift53'
 *    '<S7>/Bit Shift7'
 */
static uint8 AppSwcBcm_BitShift15(uint8 rtu_u)
{
  /* MATLAB Function: '<S26>/bit_shift' */
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
  uint8 rtb_y_ax5;
  uint8 rtb_y_b;
  uint8 rtb_y_bb;
  uint8 rtb_y_bh;
  uint8 rtb_y_bx;
  uint8 rtb_y_c;
  uint8 rtb_y_c1;
  uint8 rtb_y_cn;
  uint8 rtb_y_cxq;
  uint8 rtb_y_d;
  uint8 rtb_y_d3;
  uint8 rtb_y_daj;
  uint8 rtb_y_dj;
  uint8 rtb_y_dz;
  uint8 rtb_y_e;
  uint8 rtb_y_eai;
  uint8 rtb_y_eb;
  uint8 rtb_y_fs;
  uint8 rtb_y_g;
  uint8 rtb_y_g2;
  uint8 rtb_y_g35;
  uint8 rtb_y_gn;
  uint8 rtb_y_h;
  uint8 rtb_y_h3;
  uint8 rtb_y_hi;
  uint8 rtb_y_hl;
  uint8 rtb_y_hu;
  uint8 rtb_y_hz;
  uint8 rtb_y_i0e;
  uint8 rtb_y_i3;
  uint8 rtb_y_ic;
  uint8 rtb_y_j0;
  uint8 rtb_y_j1;
  uint8 rtb_y_jr;
  uint8 rtb_y_k;
  uint8 rtb_y_k2;
  uint8 rtb_y_k5;
  uint8 rtb_y_kc;
  uint8 rtb_y_l;
  uint8 rtb_y_lb;
  uint8 rtb_y_lnu;
  uint8 rtb_y_lo;
  uint8 rtb_y_m;
  uint8 rtb_y_mi;
  uint8 rtb_y_n;
  uint8 rtb_y_n5;
  uint8 rtb_y_nq;
  uint8 rtb_y_nsz;
  uint8 rtb_y_o2;
  uint8 rtb_y_ob;
  uint8 rtb_y_p;
  uint8 rtb_y_pa;
  uint8 rtb_y_pm;
  uint8 rtb_y_pp;

  /* CCaller: '<S7>/C Caller' */
  App_Call_Event_IODID_0x3231_GetEventStatus(&rtb_CCaller[0]);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift' */
  rtb_y_cxq = AppSwcBcm_BitShift(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND' */
  IODID_TurnIndcrLCtlFlg = (uint8)(rtb_y_cxq & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift1' */
  rtb_y_c1 = AppSwcBcm_BitShift1(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift1' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND1' */
  IODID_TurnIndcrRCtlFlg = (uint8)(rtb_y_c1 & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift12' */
  rtb_y_dz = AppSwcBcm_BitShift12(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift12' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND12' */
  IODID_LowBeamCtlFlg = (uint8)(rtb_y_dz & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift13' */
  rtb_y_daj = AppSwcBcm_BitShift13(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift13' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND13' */
  IODID_HiBeamCtlFlg = (uint8)(rtb_y_daj & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift14' */
  rtb_y_d3 = AppSwcBcm_BitShift14(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift14' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND14' */
  IODID_FogLampFCtlFlg = (uint8)(rtb_y_d3 & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift15' */
  rtb_y_hl = AppSwcBcm_BitShift15(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift15' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND15' */
  IODID_FogLampRCtlFlg = (uint8)(rtb_y_hl & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift2' */
  rtb_y_h3 = AppSwcBcm_BitShift10(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift2' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND2' */
  IODID_BackLampCtlFlg = (uint8)(rtb_y_h3 & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift3' */
  rtb_y_g2 = AppSwcBcm_BitShift11(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift3' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND3' */
  IODID_BrakeLightCtlFlg = (uint8)(rtb_y_g2 & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift5' */
  rtb_y_pm = AppSwcBcm_BitShift13(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift5' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND5' */
  IODID_ReverseLampCtlFlg = (uint8)(rtb_y_pm & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift6' */
  rtb_y_cn = AppSwcBcm_BitShift14(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift6' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND6' */
  IODID_DayRunLightCtlFlg = (uint8)(rtb_y_cn & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift7' */
  rtb_y_ic = AppSwcBcm_BitShift15(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift7' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND7' */
  IODID_PosLampCtlFlg = (uint8)(rtb_y_ic & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift9' */
  rtb_y = AppSwcBcm_BitShift1(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift9' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND9' */
  IODID_DomeLampCtlFlg = (uint8)(rtb_y & 1);

  /* CCaller: '<S7>/C Caller1' */
  App_Call_Event_IODID_0x3232_GetEventStatus(&rtb_CCaller1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift16' */
  rtb_y_mi = AppSwcBcm_BitShift10(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift16' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND16' */
  IODID_DoorUnlckCtlFlg = (uint8)(rtb_y_mi & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift17' */
  rtb_y_bb = AppSwcBcm_BitShift11(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift17' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND17' */
  IODID_DoorLckCtlFlg = (uint8)(rtb_y_bb & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift22' */
  rtb_y_l = AppSwcBcm_BitShift(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift22' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND22' */
  IODID_TrunkUnlckCtlFlg = (uint8)(rtb_y_l & 1);

  /* CCaller: '<S7>/C Caller2' */
  App_Call_Event_IODID_0x3233_GetEventStatus(&rtb_CCaller2);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift30' */
  rtb_y_d = AppSwcBcm_BitShift(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift30' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND30' */
  IODID_WiperHiSpdCtlFlg = (uint8)(rtb_y_d & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift31' */
  rtb_y_j0 = AppSwcBcm_BitShift1(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift31' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND31' */
  IODID_WiperLowSpdCtlFlg = (uint8)(rtb_y_j0 & 1);

  /* CCaller: '<S7>/C Caller3' */
  App_Call_Event_IODID_0x3234_GetEventStatus(&rtb_CCaller3);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift32' */
  rtb_y_g35 = AppSwcBcm_BitShift10(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift32' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND32' */
  IODID_WinFRCloseFlg = (uint8)(rtb_y_g35 & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift33' */
  rtb_y_k = AppSwcBcm_BitShift11(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift33' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND33' */
  IODID_WinFROpenFlg = (uint8)(rtb_y_k & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift38' */
  rtb_y_dj = AppSwcBcm_BitShift(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift38' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND38' */
  IODID_WinFLCloseFlg = (uint8)(rtb_y_dj & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift39' */
  rtb_y_fs = AppSwcBcm_BitShift1(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift39' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND39' */
  IODID_WinFLOpenFlg = (uint8)(rtb_y_fs & 1);

  /* CCaller: '<S7>/C Caller4' */
  App_Call_Event_IODID_0x3235_GetEventStatus(&rtb_CCaller4);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift40' */
  rtb_y_i0e = AppSwcBcm_BitShift10(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift40' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND40' */
  IODID_HornCtlFlg = (uint8)(rtb_y_i0e & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift42' */
  rtb_y_a = AppSwcBcm_BitShift12(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift42' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND42' */
  IODID_BatSaveCtlFlg = (uint8)(rtb_y_a & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift43' */
  rtb_y_pa = AppSwcBcm_BitShift13(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift43' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND43' */
  IODID_BSDRightCtlFlg = (uint8)(rtb_y_pa & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift44' */
  rtb_y_c = AppSwcBcm_BitShift14(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift44' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND44' */
  IODID_BSDLeftCtlFlg = (uint8)(rtb_y_c & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift46' */
  rtb_y_nsz = AppSwcBcm_BitShift(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift46' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND46' */
  IODID_IG1RlyCtlFlg = (uint8)(rtb_y_nsz & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift47' */
  rtb_y_gn = AppSwcBcm_BitShift1(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift47' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND47' */
  IODID_IG2RlyCtlFlg = (uint8)(rtb_y_gn & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift41' */
  rtb_y_n = AppSwcBcm_BitShift11(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift41' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift45' */
  rtb_y_n5 = AppSwcBcm_BitShift15(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift45' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift34' */
  rtb_y_hu = AppSwcBcm_BitShift12(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift34' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift35' */
  rtb_y_h = AppSwcBcm_BitShift13(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift35' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift36' */
  rtb_y_hz = AppSwcBcm_BitShift14(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift36' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift37' */
  rtb_y_ax5 = AppSwcBcm_BitShift15(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift37' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift24' */
  rtb_y_j1 = AppSwcBcm_BitShift10(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift24' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift25' */
  rtb_y_pp = AppSwcBcm_BitShift11(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift25' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift26' */
  rtb_y_nq = AppSwcBcm_BitShift12(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift26' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift27' */
  rtb_y_k2 = AppSwcBcm_BitShift13(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift27' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift28' */
  rtb_y_bh = AppSwcBcm_BitShift14(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift28' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift29' */
  rtb_y_kc = AppSwcBcm_BitShift15(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift29' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift18' */
  rtb_y_o2 = AppSwcBcm_BitShift12(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift18' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift19' */
  rtb_y_lo = AppSwcBcm_BitShift13(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift19' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift20' */
  rtb_y_k5 = AppSwcBcm_BitShift14(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift20' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift21' */
  rtb_y_bx = AppSwcBcm_BitShift15(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift21' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift23' */
  rtb_y_p = AppSwcBcm_BitShift1(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift23' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift10' */
  rtb_y_eb = AppSwcBcm_BitShift10(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift10' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift11' */
  rtb_y_lnu = AppSwcBcm_BitShift11(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift4' */
  rtb_y_jr = AppSwcBcm_BitShift12(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift8' */
  rtb_y_e = AppSwcBcm_BitShift(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift8' */

  /* CCaller: '<S7>/C Caller5' */
  App_Call_Event_IODID_0x3236_GetEventStatus(&rtb_CCaller5);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift48' */
  rtb_y_eai = AppSwcBcm_BitShift10(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift48' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift49' */
  rtb_y_b = AppSwcBcm_BitShift11(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift49' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift50' */
  rtb_y_lb = AppSwcBcm_BitShift12(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift50' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift51' */
  rtb_y_ob = AppSwcBcm_BitShift13(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift51' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift52' */
  rtb_y_g = AppSwcBcm_BitShift14(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift52' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift53' */
  rtb_y_m = AppSwcBcm_BitShift15(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift53' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift54' */
  rtb_y_hi = AppSwcBcm_BitShift(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift54' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift55' */
  rtb_y_i3 = AppSwcBcm_BitShift1(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift55' */
}

/*
 * System reset for atomic system:
 *    '<S132>/Lib_RiseEdgeDet'
 *    '<S142>/Lib_RiseEdgeDet'
 *    '<S149>/Lib_RiseEdgeDet'
 *    '<S179>/Lib_RiseEdgeDet'
 *    '<S181>/Lib_RiseEdgeDet'
 *    '<S183>/Lib_RiseEdgeDet'
 *    '<S185>/Lib_RiseEdgeDet'
 *    '<S206>/Lib_RiseEdgeDet'
 *    '<S207>/Lib_RiseEdgeDet'
 *    '<S210>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_Reset(ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S134>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S132>/Lib_RiseEdgeDet'
 *    '<S142>/Lib_RiseEdgeDet'
 *    '<S149>/Lib_RiseEdgeDet'
 *    '<S179>/Lib_RiseEdgeDet'
 *    '<S181>/Lib_RiseEdgeDet'
 *    '<S183>/Lib_RiseEdgeDet'
 *    '<S185>/Lib_RiseEdgeDet'
 *    '<S206>/Lib_RiseEdgeDet'
 *    '<S207>/Lib_RiseEdgeDet'
 *    '<S210>/Lib_RiseEdgeDet'
 *    ...
 */
static boolean AppSwcBcm_Lib_RiseEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S134>/Logical Operator' incorporates:
   *  Logic: '<S134>/Logical Operator1'
   *  UnitDelay: '<S134>/Unit Delay'
   */
  rty_Lib_blOut_0 = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S134>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/*
 * System reset for atomic system:
 *    '<S132>/Lib_SR'
 *    '<S406>/Lib_SR'
 *    '<S624>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR_Reset(ARID_DEF_Lib_SR_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S135>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S132>/Lib_SR'
 *    '<S406>/Lib_SR'
 *    '<S624>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR(boolean rtu_S, boolean rtu_R, boolean *rty_Q,
  ARID_DEF_Lib_SR_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S135>/Constant'
   *  Logic: '<S135>/Logical Operator'
   *  UnitDelay: '<S135>/Unit Delay'
   */
  if (rtu_R) {
    *rty_Q = false;
  } else {
    *rty_Q = (rtu_S || AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);
  }

  /* End of Switch: '<S135>/Switch' */

  /* Update for UnitDelay: '<S135>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = *rty_Q;
}

/* Output and update for atomic system: '<S1>/RVMCtl' */
static void AppSwcBcm_RVMCtl(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator_f;

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S8>/RVMCtl' incorporates:
   *  EnablePort: '<S132>/Enable'
   */
  if (rtb_RelationalOperator_f) {
    if (!AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
      /* InitializeConditions for UnitDelay: '<S132>/Unit Delay' */
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = false;

      /* SystemReset for Atomic SubSystem: '<S132>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_Reset
        (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fb);

      /* End of SystemReset for SubSystem: '<S132>/Lib_RiseEdgeDet' */

      /* SystemReset for Chart: '<S132>/LIB_Tim' */
      AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_he = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;

      /* SystemReset for Atomic SubSystem: '<S132>/Lib_SR' */
      AppSwcBcm_Lib_SR_Reset(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_c);

      /* End of SystemReset for SubSystem: '<S132>/Lib_SR' */
      AppSwcBcm_ARID_DEF.RVMCtl_MODE = true;
    }

    /* RelationalOperator: '<S132>/Relational Operator1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator_f =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPRrViewMirrHeatgKey_flg;

    /* Outputs for Atomic SubSystem: '<S132>/Lib_RiseEdgeDet' */
    rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator_f,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fb);

    /* End of Outputs for SubSystem: '<S132>/Lib_RiseEdgeDet' */

    /* Chart: '<S132>/LIB_Tim' incorporates:
     *  Constant: '<S132>/Constant2'
     *  Constant: '<S132>/Constant7'
     *  UnitDelay: '<S132>/Unit Delay'
     */
    if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) {
      if (AppSwcBcm_ARID_DEF.Cnt_M_he >= RVMCtl_MaxHeatTimM_C) {
        rtb_RelationalOperator_f = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_Tick_a + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_Tick_a + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_Tick_a = (uint16)tmp;
        rtb_RelationalOperator_f = false;
        if (AppSwcBcm_ARID_DEF.Cnt_Tick_a >= 1.0F / RVMCtl_Ts_C) {
          tmp = AppSwcBcm_ARID_DEF.Cnt_S_b + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_S_b + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_S_b = (uint8)tmp;
          AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
        }

        if (AppSwcBcm_ARID_DEF.Cnt_S_b >= 60) {
          AppSwcBcm_ARID_DEF.Cnt_M_he++;
          AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;
        }

        if (AppSwcBcm_ARID_DEF.Cnt_M_he >= 60) {
          tmp = AppSwcBcm_ARID_DEF.Cnt_H_p + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_H_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_H_p = (uint8)tmp;
          AppSwcBcm_ARID_DEF.Cnt_M_he = 0U;
        }
      }
    } else {
      rtb_RelationalOperator_f = false;
      AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_he = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
    }

    /* End of Chart: '<S132>/LIB_Tim' */

    /* Outputs for Atomic SubSystem: '<S132>/Lib_SR' */
    /* Logic: '<S132>/Logical Operator2' incorporates:
     *  Logic: '<S132>/Logical Operator1'
     *  UnitDelay: '<S132>/Unit Delay'
     */
    AppSwcBcm_Lib_SR(rtb_LogicalOperator, (rtb_LogicalOperator &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) || rtb_RelationalOperator_f,
                     &AppSwcBcm_ARID_DEF.Switch_i,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_c);

    /* End of Outputs for SubSystem: '<S132>/Lib_SR' */

    /* Update for UnitDelay: '<S132>/Unit Delay' */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = AppSwcBcm_ARID_DEF.Switch_i;
  } else if (AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
    /* Disable for Switch: '<S135>/Switch' incorporates:
     *  Outport: '<S132>/RVMCtl_J42Heat'
     */
    AppSwcBcm_ARID_DEF.Switch_i = false;
    AppSwcBcm_ARID_DEF.RVMCtl_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S8>/RVMCtl' */

  /* Outputs for Atomic SubSystem: '<S8>/Ovrd' */
  /* Switch: '<S131>/Switch' incorporates:
   *  Constant: '<S8>/Constant18'
   */
  if (RVMCtl_J42HeatOvrdFlg_C) {
    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S8>/Constant19'
     */
    RVMCtl_J42Heat = RVMCtl_J42HeatOvrdVal_C;
  } else {
    /* Switch: '<S131>/Switch' */
    RVMCtl_J42Heat = AppSwcBcm_ARID_DEF.Switch_i;
  }

  /* End of Switch: '<S131>/Switch' */
  /* End of Outputs for SubSystem: '<S8>/Ovrd' */
}

/*
 * Output and update for function-call system:
 *    '<S138>/Lib_RiseEdgeDet'
 *    '<S146>/Lib_RiseEdgeDet'
 *    '<S175>/Lib_RiseEdgeDet'
 *    '<S176>/Lib_RiseEdgeDet'
 *    '<S177>/Lib_RiseEdgeDet'
 *    '<S178>/Lib_RiseEdgeDet'
 *    '<S189>/Lib_RiseEdgeDet'
 *    '<S189>/Lib_RiseEdgeDet1'
 *    '<S190>/Lib_RiseEdgeDet'
 *    '<S190>/Lib_RiseEdgeDet1'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_n_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S142>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S142>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S1>/SeatCtl' */
static void AppSwcBcm_SeatCtl(void)
{
  sint32 rtb_SeatCtl_CN167DrvSeatHtPWM;
  uint8 rtb_MultiportSwitch2;
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator1_le;

  /* Chart: '<S136>/LIB_TPD_Ts1' incorporates:
   *  Constant: '<S136>/Constant11'
   *  Constant: '<S136>/Constant15'
   *  Constant: '<S136>/Constant16'
   *  Constant: '<S136>/Constant17'
   *  DataTypeConversion: '<S136>/Data Type Conversion1'
   *  RelationalOperator: '<S136>/Relational Operator2'
   */
  if (BSW_CN744DrvSeatResis >= SeatCtl_NTCOpenResis_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_jp >= (float32)SeatCtl_NTCOpenValidTim_C /
         (SeatCtl_Ts_C * 100.0F)) && (SeatCtl_NTCOpenValidTim_C != 0xFFFF)) {
      SeatCtl_DrvNTCOpen = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_jp++;
      AppSwcBcm_ARID_DEF.cnt_heal_fp = (uint16)((float32)
        SeatCtl_NTCOpenInValidTim_C / (SeatCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_jp = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_fp == 0) {
      SeatCtl_DrvNTCOpen = false;
    } else if (SeatCtl_NTCOpenInValidTim_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_fp--;
    }
  }

  /* End of Chart: '<S136>/LIB_TPD_Ts1' */

  /* MultiPortSwitch: '<S136>/Multiport Switch2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  switch ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum) {
   case 1:
    /* MultiPortSwitch: '<S136>/Multiport Switch2' incorporates:
     *  Constant: '<S136>/Constant21'
     */
    rtb_MultiportSwitch2 = 2U;
    break;

   case 2:
    /* MultiPortSwitch: '<S136>/Multiport Switch2' incorporates:
     *  Constant: '<S136>/Constant22'
     */
    rtb_MultiportSwitch2 = 3U;
    break;

   case 3:
    /* MultiPortSwitch: '<S136>/Multiport Switch2' incorporates:
     *  Constant: '<S136>/Constant23'
     */
    rtb_MultiportSwitch2 = 4U;
    break;

   case 4:
    /* MultiPortSwitch: '<S136>/Multiport Switch2' incorporates:
     *  Constant: '<S136>/Constant24'
     */
    rtb_MultiportSwitch2 = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S136>/Multiport Switch2' incorporates:
     *  Constant: '<S136>/Constant25'
     */
    rtb_MultiportSwitch2 = 0U;
    break;
  }

  /* End of MultiPortSwitch: '<S136>/Multiport Switch2' */

  /* RelationalOperator: '<S136>/Relational Operator1' incorporates:
   *  Constant: '<S136>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_le = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S136>/Switch' */
  if (rtb_RelationalOperator1_le) {
    /* RelationalOperator: '<S136>/Relational Operator3' incorporates:
     *  Constant: '<S136>/Constant20'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator1_le =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
       ->VIPM_HUMaiDrvrSeatHeat_enum != 0);

    /* Switch: '<S136>/Switch1' */
    if (rtb_RelationalOperator1_le) {
      /* Switch: '<S136>/Switch' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
       *  Switch: '<S136>/Switch1'
       */
      rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
        ->VIPM_HUMaiDrvrSeatHeat_enum;
    } else {
      /* Switch: '<S136>/Switch' incorporates:
       *  Switch: '<S136>/Switch1'
       */
      rtb_Switch = rtb_MultiportSwitch2;
    }

    /* End of Switch: '<S136>/Switch1' */
  } else {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S136>/Constant10'
     */
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S136>/Switch' */

  /* MultiPortSwitch: '<S136>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S136>/Multiport Switch' incorporates:
     *  Constant: '<S136>/Constant1'
     */
    SeatCtl_MaiDrvSeatStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S136>/Multiport Switch' incorporates:
     *  Constant: '<S136>/Constant2'
     */
    SeatCtl_MaiDrvSeatStFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S136>/Multiport Switch' incorporates:
     *  Constant: '<S136>/Constant3'
     */
    SeatCtl_MaiDrvSeatStFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S136>/Multiport Switch' incorporates:
     *  Constant: '<S136>/Constant4'
     */
    SeatCtl_MaiDrvSeatStFb = 3U;
    break;
  }

  /* End of MultiPortSwitch: '<S136>/Multiport Switch' */

  /* MultiPortSwitch: '<S136>/Multiport Switch1' */
  switch (SeatCtl_MaiDrvSeatStFb) {
   case 1:
    /* MultiPortSwitch: '<S136>/Multiport Switch1' incorporates:
     *  Constant: '<S136>/Constant5'
     */
    rtb_Switch = SeatCtl_DrvTempLvl1_C;
    break;

   case 2:
    /* MultiPortSwitch: '<S136>/Multiport Switch1' incorporates:
     *  Constant: '<S136>/Constant6'
     */
    rtb_Switch = SeatCtl_DrvTempLvl2_C;
    break;

   case 3:
    /* MultiPortSwitch: '<S136>/Multiport Switch1' incorporates:
     *  Constant: '<S136>/Constant7'
     */
    rtb_Switch = SeatCtl_DrvTempLvl3_C;
    break;

   default:
    /* MultiPortSwitch: '<S136>/Multiport Switch1' incorporates:
     *  Constant: '<S136>/Constant8'
     */
    rtb_Switch = SeatCtl_DrvTempLvl0_C;
    break;
  }

  /* End of MultiPortSwitch: '<S136>/Multiport Switch1' */

  /* DataTypeConversion: '<S136>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S136>/Data Type Conversion1'
   *  Lookup_n-D: '<S136>/1-D Lookup Table2'
   */
  SeatCtl_DrvSeatTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_CN744DrvSeatResis, (const float32 *)&SeatCtl_DrvSeatTempLookUp_X[0], (
    const float32 *)&SeatCtl_DrvSeatTempLookUp_Y[0], 22U));

  /* Chart: '<S136>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S136>/Constant'
   *  Constant: '<S136>/Constant12'
   *  Constant: '<S136>/Constant13'
   *  Constant: '<S136>/Constant14'
   *  DataTypeConversion: '<S136>/Data Type Conversion1'
   *  RelationalOperator: '<S136>/Relational Operator'
   */
  if (BSW_CN744DrvSeatResis <= SeatCtl_NTCShortResis_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ph >= (float32)SeatCtl_NTCShortValidTim_C
         / (SeatCtl_Ts_C * 100.0F)) && (SeatCtl_NTCShortValidTim_C != 0xFFFF)) {
      SeatCtl_DrvNTCShort = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ph++;
      AppSwcBcm_ARID_DEF.cnt_heal_ox = (uint16)((float32)
        SeatCtl_NTCShortInValidTim_C / (SeatCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ph = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ox == 0) {
      SeatCtl_DrvNTCShort = false;
    } else if (SeatCtl_NTCShortInValidTim_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ox--;
    }
  }

  /* End of Chart: '<S136>/LIB_TPD_Ts' */

  /* Chart: '<S136>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_m;
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib == AppSwcBcm_IN_Off_m) {
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    if ((rtb_Switch - SeatCtl_DrvSeatTemp >= SeatCtl_HtDiffTemp_C) &&
        (rtb_Switch != 0) && (!SeatCtl_DrvNTCShort) && (!SeatCtl_DrvNTCOpen)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_On_h;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    }
  } else {
    /* case IN_On: */
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    if ((SeatCtl_DrvSeatTemp >= rtb_Switch) || (rtb_Switch == 0) ||
        SeatCtl_DrvNTCShort || SeatCtl_DrvNTCOpen) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_m;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    }
  }

  /* End of Chart: '<S136>/Chart' */

  /* Outputs for Atomic SubSystem: '<S136>/Ovrd' */
  /* Switch: '<S141>/Switch' incorporates:
   *  Constant: '<S136>/Constant18'
   */
  if (SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C) {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S136>/Constant19'
     */
    SeatCtl_CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;
  } else {
    /* Switch: '<S141>/Switch' */
    SeatCtl_CN167DrvSeatHtPWM = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
  }

  /* End of Switch: '<S141>/Switch' */
  /* End of Outputs for SubSystem: '<S136>/Ovrd' */

  /* Chart: '<S136>/HeatFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init;
    SeatCtl_RemtHeatFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_ki = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib) {
     case AppSwcBcm_IN_Fail:
      SeatCtl_RemtHeatFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_ki >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init;
        SeatCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_ki = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_ki++;
      }
      break;

     case AppSwcBcm_IN_Init:
      SeatCtl_RemtHeatFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_oov = ((rtb_MultiportSwitch2 == 1) ||
        (rtb_MultiportSwitch2 == 2) || (rtb_MultiportSwitch2 == 3) ||
        (rtb_MultiportSwitch2 == 4));

      /* Outputs for Function Call SubSystem: '<S138>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_oov,
        &AppSwcBcm_ARID_DEF.LogicalOperator_hr,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m4);

      /* End of Outputs for SubSystem: '<S138>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_hr) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Wait;
      }
      break;

     case AppSwcBcm_IN_Suc:
      SeatCtl_RemtHeatFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_ki >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init;
        SeatCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_ki = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_ki++;
      }
      break;

     default:
      /* case IN_Wait: */
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Suc;
        SeatCtl_RemtHeatFb = 1U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_ki + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_ki + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_ki = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      } else if (rtb_MultiportSwitch2 == 0) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Fail;
        SeatCtl_RemtHeatFb = 3U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_ki + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_ki + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_ki = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;
    }
  }

  /* End of Chart: '<S136>/HeatFb' */
}

/* Output and update for atomic system: '<S1>/SteerWhlCtl' */
static void AppSwcBcm_SteerWhlCtl(void)
{
  sint32 tmp;

  /* DataTypeConversion: '<S144>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S144>/Data Type Conversion1'
   *  Lookup_n-D: '<S144>/1-D Lookup Table1'
   */
  SteerWhlCtl_SteerWhlTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_J134SteerWhlResis, (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_X[0],
     (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_Y[0], 17U));

  /* Chart: '<S144>/HeatSet' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_OFF;
    SteerWhlCtl_SteerWhlHeatSts = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib == AppSwcBcm_IN_OFF) {
    SteerWhlCtl_SteerWhlHeatSts = 0U;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_HUSteerWhlHeat_enum == 2) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 2))) {
      AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_ON;
      SteerWhlCtl_SteerWhlHeatSts = 1U;
    }
  } else {
    /* case IN_ON: */
    SteerWhlCtl_SteerWhlHeatSts = 1U;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 0) ||
        ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
         ->VIPM_HUSteerWhlHeat_enum == 1) ||
        ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
         ->VIPM_TBOXRemtStrWhlHeatReq_enum == 1)) {
      AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_OFF;
      SteerWhlCtl_SteerWhlHeatSts = 0U;
    }
  }

  /* End of Chart: '<S144>/HeatSet' */

  /* Chart: '<S144>/HeatCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_g;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib == AppSwcBcm_IN_Off_g) {
    if ((SteerWhlCtl_SteerWhlHeatSts != 0) && (SteerWhlCtl_TrgtTemp_C -
         SteerWhlCtl_SteerWhlTemp >= SteerWhlCtl_DiffTemp_C)) {
      AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_On_m;
      AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = true;
    }

    /* case IN_On: */
  } else if ((SteerWhlCtl_SteerWhlHeatSts == 0) || (SteerWhlCtl_SteerWhlTemp >=
              SteerWhlCtl_TrgtTemp_C)) {
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_g;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  }

  /* End of Chart: '<S144>/HeatCtl' */

  /* Outputs for Atomic SubSystem: '<S144>/Ovrd' */
  /* Switch: '<S148>/Switch' incorporates:
   *  Constant: '<S144>/Constant18'
   */
  if (SteerWhlCtl_J447SteerWhlHtOvrdFlg_C) {
    /* Switch: '<S148>/Switch' incorporates:
     *  Constant: '<S144>/Constant19'
     */
    SteerWhlCtl_J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHtOvrdVal_C;
  } else {
    /* Switch: '<S148>/Switch' */
    SteerWhlCtl_J447SteerWhlHt = AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta;
  }

  /* End of Switch: '<S148>/Switch' */
  /* End of Outputs for SubSystem: '<S144>/Ovrd' */

  /* Chart: '<S144>/HeatFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_o;
    SteerWhlCtl_RemtHeatFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_k2 = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib) {
     case AppSwcBcm_IN_Fail_n:
      SteerWhlCtl_RemtHeatFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_k2 >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_o;
        SteerWhlCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_k2 = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_k2++;
      }
      break;

     case AppSwcBcm_IN_Init_o:
      SteerWhlCtl_RemtHeatFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_ax =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 2));

      /* Outputs for Function Call SubSystem: '<S146>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ax,
        &AppSwcBcm_ARID_DEF.LogicalOperator_my,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oc);

      /* End of Outputs for SubSystem: '<S146>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_my) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Wait_k;
      }
      break;

     case AppSwcBcm_IN_Suc_h:
      SteerWhlCtl_RemtHeatFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_k2 >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_o;
        SteerWhlCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_k2 = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_k2++;
      }
      break;

     default:
      /* case IN_Wait: */
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Fail_n;
        SteerWhlCtl_RemtHeatFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_k2 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_k2 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_k2 = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S144>/HeatFb' */
}

/* Output and update for atomic system: '<S11>/DrvWinCtl' */
static void AppSwcBcm_DrvWinCtl(void)
{
  /* Chart: '<S11>/DrvWinCtl' */
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
      if (WinCtl_DrvWinReq == 3) {
        AppSwcBcm_ARID_DEF.is_c111_WinCtl_Lib = AppSwcBcm_IN_AutoDown;
        WinCtl_DrvWinSta = 3U;
        AppSwcBcm_ARID_DEF.WinCtl_J51 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J53 = true;
      } else if (WinCtl_DrvWinReq != 2) {
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

  /* End of Chart: '<S11>/DrvWinCtl' */
}

/* Output and update for atomic system: '<S11>/PsgWinCtl' */
static void AppSwcBcm_PsgWinCtl(void)
{
  /* Chart: '<S11>/PsgWinCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c112_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c112_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
    WinCtl_PsgWinSta = 0U;
    AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
    AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib) {
     case AppSwcBcm_IN_AutoDown_n:
      WinCtl_PsgWinSta = 3U;
      if (WinCtl_PsgWinReq != 3) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManDown_h:
      WinCtl_PsgWinSta = 4U;
      if (WinCtl_PsgWinReq == 3) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_AutoDown_n;
        WinCtl_PsgWinSta = 3U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = true;
      } else if (WinCtl_PsgWinReq != 2) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManUp_c:
      WinCtl_PsgWinSta = 2U;
      if (WinCtl_PsgWinReq != 1) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
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
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManDown_h;
        WinCtl_PsgWinSta = 4U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = true;
        break;

       case 1:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManUp_c;
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

  /* End of Chart: '<S11>/PsgWinCtl' */
}

/*
 * Output and update for atomic system:
 *    '<S157>/Bit Shift1'
 *    '<S157>/Bit Shift7'
 *    '<S446>/Bit Shift3'
 *    '<S653>/Bit Shift1'
 */
static uint16 AppSwcBcm_BitShift1_m(uint16 rtu_u)
{
  /* MATLAB Function: '<S160>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S157>/Bit Shift3'
 *    '<S354>/Bit Shift5'
 *    '<S446>/Bit Shift5'
 *    '<S653>/Bit Shift'
 */
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u)
{
  /* MATLAB Function: '<S161>/bit_shift' */
  return rtu_u;
}

/* Output and update for atomic system: '<S11>/SigProc' */
static void AppSwcBcm_SigProc(void)
{
  uint16 rtb_Switch1_aw;
  boolean rtb_LogicalOperator1_ako;

  /* Outputs for Atomic SubSystem: '<S157>/Bit Shift3' */
  /* Constant: '<S157>/Constant11' */
  rtb_Switch1_aw = AppSwcBcm_BitShift3(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S157>/Bit Shift3' */

  /* Switch: '<S157>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S157>/Bitwise AND3'
   */
  if ((rtb_Switch1_aw & 1U) != 0U) {
    /* Switch: '<S157>/Switch1' incorporates:
     *  Constant: '<S157>/Constant15'
     */
    rtb_Switch1_aw = WinCtl_DrvWinSwResis_C;
  } else {
    /* Switch: '<S157>/Switch1' */
    rtb_Switch1_aw = BSW_J113DrvWinSwResis;
  }

  /* End of Switch: '<S157>/Switch3' */

  /* Logic: '<S157>/Logical Operator1' incorporates:
   *  Constant: '<S157>/Constant26'
   *  Constant: '<S157>/Constant31'
   *  RelationalOperator: '<S157>/Relational Operator2'
   *  RelationalOperator: '<S157>/Relational Operator3'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_DrvWinDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvWinDnMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S157>/Constant17'
   *  Constant: '<S157>/Constant18'
   *  Constant: '<S157>/Constant19'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_k4 >= (float32)WinCtl_DrvWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k4++;
      AppSwcBcm_ARID_DEF.cnt_heal_le = (uint16)((float32)
        WinCtl_DrvWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k4 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_le == 0) {
      WinCtl_DrvWinDnSw = false;
    } else if (WinCtl_DrvWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_le--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms1' */

  /* Logic: '<S157>/Logical Operator2' incorporates:
   *  Constant: '<S157>/Constant35'
   *  Constant: '<S157>/Constant36'
   *  RelationalOperator: '<S157>/Relational Operator4'
   *  RelationalOperator: '<S157>/Relational Operator5'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_DrvWinAutoDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvWinAutoDnMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S157>/Constant23'
   *  Constant: '<S157>/Constant24'
   *  Constant: '<S157>/Constant25'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_jc >= (float32)
         WinCtl_DrvWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_jc++;
      AppSwcBcm_ARID_DEF.cnt_heal_di = (uint16)((float32)
        WinCtl_DrvWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_jc = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_di == 0) {
      WinCtl_DrvWinAutoDnSw = false;
    } else if (WinCtl_DrvWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_di--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms2' */

  /* Logic: '<S157>/Logical Operator' incorporates:
   *  Constant: '<S157>/Constant20'
   *  Constant: '<S157>/Constant22'
   *  RelationalOperator: '<S157>/Relational Operator'
   *  RelationalOperator: '<S157>/Relational Operator1'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_DrvWinUpMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvWinUpMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S157>/Constant12'
   *  Constant: '<S157>/Constant13'
   *  Constant: '<S157>/Constant14'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_da >= (float32)WinCtl_DrvWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_da++;
      AppSwcBcm_ARID_DEF.cnt_heal_ai = (uint16)((float32)
        WinCtl_DrvWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_da = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ai == 0) {
      WinCtl_DrvWinUpSw = false;
    } else if (WinCtl_DrvWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ai--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S157>/Bit Shift7' */
  /* Constant: '<S157>/Constant21' */
  rtb_Switch1_aw = AppSwcBcm_BitShift1_m(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S157>/Bit Shift7' */

  /* Switch: '<S157>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S157>/Bitwise AND7'
   */
  if ((rtb_Switch1_aw & 1U) != 0U) {
    /* Switch: '<S157>/Switch1' incorporates:
     *  Constant: '<S157>/Constant30'
     */
    rtb_Switch1_aw = WinCtl_PsgWinSwResis_C;
  } else {
    /* Switch: '<S157>/Switch1' */
    rtb_Switch1_aw = BSW_J26PsgWinSwResis;
  }

  /* End of Switch: '<S157>/Switch6' */

  /* Logic: '<S157>/Logical Operator3' incorporates:
   *  Constant: '<S157>/Constant40'
   *  Constant: '<S157>/Constant41'
   *  RelationalOperator: '<S157>/Relational Operator6'
   *  RelationalOperator: '<S157>/Relational Operator7'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_PsgWinUpMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_PsgWinUpMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S157>/Constant27'
   *  Constant: '<S157>/Constant28'
   *  Constant: '<S157>/Constant29'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_am >= (float32)WinCtl_PsgWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_am++;
      AppSwcBcm_ARID_DEF.cnt_heal_na = (uint16)((float32)
        WinCtl_PsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_am = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_na == 0) {
      WinCtl_PsgWinUpSw = false;
    } else if (WinCtl_PsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_na--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms4' */

  /* Logic: '<S157>/Logical Operator4' incorporates:
   *  Constant: '<S157>/Constant42'
   *  Constant: '<S157>/Constant43'
   *  RelationalOperator: '<S157>/Relational Operator8'
   *  RelationalOperator: '<S157>/Relational Operator9'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_PsgWinDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_PsgWinDnMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S157>/Constant32'
   *  Constant: '<S157>/Constant33'
   *  Constant: '<S157>/Constant34'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_k >= (float32)WinCtl_PsgWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k++;
      AppSwcBcm_ARID_DEF.cnt_heal_km = (uint16)((float32)
        WinCtl_PsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_km == 0) {
      WinCtl_PsgWinDnSw = false;
    } else if (WinCtl_PsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_km--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms5' */

  /* Logic: '<S157>/Logical Operator5' incorporates:
   *  Constant: '<S157>/Constant44'
   *  Constant: '<S157>/Constant45'
   *  RelationalOperator: '<S157>/Relational Operator10'
   *  RelationalOperator: '<S157>/Relational Operator11'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_PsgWinAutoDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_PsgWinAutoDnMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S157>/Constant37'
   *  Constant: '<S157>/Constant38'
   *  Constant: '<S157>/Constant39'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_im >= (float32)
         WinCtl_PsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_PsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_im++;
      AppSwcBcm_ARID_DEF.cnt_heal_ip1 = (uint16)((float32)
        WinCtl_PsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_im = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ip1 == 0) {
      WinCtl_PsgWinAutoDnSw = false;
    } else if (WinCtl_PsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ip1--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S157>/Bit Shift1' */
  /* Constant: '<S157>/Constant1' */
  rtb_Switch1_aw = AppSwcBcm_BitShift1_m(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S157>/Bit Shift1' */

  /* Switch: '<S157>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S157>/Bitwise AND1'
   */
  if ((rtb_Switch1_aw & 1U) != 0U) {
    /* Switch: '<S157>/Switch1' incorporates:
     *  Constant: '<S157>/Constant5'
     */
    rtb_Switch1_aw = WinCtl_DrvPsgWinSwResis_C;
  } else {
    /* Switch: '<S157>/Switch1' */
    rtb_Switch1_aw = BSW_J126DrvPsgWinSwResis;
  }

  /* End of Switch: '<S157>/Switch1' */

  /* Logic: '<S157>/Logical Operator6' incorporates:
   *  Constant: '<S157>/Constant46'
   *  Constant: '<S157>/Constant47'
   *  RelationalOperator: '<S157>/Relational Operator14'
   *  RelationalOperator: '<S157>/Relational Operator15'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_DrvPsgWinUpMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvPsgWinUpMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S157>/Constant2'
   *  Constant: '<S157>/Constant3'
   *  Constant: '<S157>/Constant4'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_i2 >= (float32)
         WinCtl_DrvPsgWinUpTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_i2++;
      AppSwcBcm_ARID_DEF.cnt_heal_cd = (uint16)((float32)
        WinCtl_DrvPsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_i2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cd == 0) {
      WinCtl_DrvPsgWinUpSw = false;
    } else if (WinCtl_DrvPsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cd--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms7' */

  /* Logic: '<S157>/Logical Operator7' incorporates:
   *  Constant: '<S157>/Constant48'
   *  Constant: '<S157>/Constant49'
   *  RelationalOperator: '<S157>/Relational Operator16'
   *  RelationalOperator: '<S157>/Relational Operator17'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >= WinCtl_DrvPsgWinDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvPsgWinDnMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S157>/Constant6'
   *  Constant: '<S157>/Constant7'
   *  Constant: '<S157>/Constant8'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_as >= (float32)
         WinCtl_DrvPsgWinDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_as++;
      AppSwcBcm_ARID_DEF.cnt_heal_hq = (uint16)((float32)
        WinCtl_DrvPsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_as = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hq == 0) {
      WinCtl_DrvPsgWinDnSw = false;
    } else if (WinCtl_DrvPsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hq--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms8' */

  /* Logic: '<S157>/Logical Operator8' incorporates:
   *  Constant: '<S157>/Constant50'
   *  Constant: '<S157>/Constant51'
   *  RelationalOperator: '<S157>/Relational Operator12'
   *  RelationalOperator: '<S157>/Relational Operator13'
   */
  rtb_LogicalOperator1_ako = ((rtb_Switch1_aw >=
    WinCtl_DrvPsgWinAutoDnMinResis_C) && (rtb_Switch1_aw <=
    WinCtl_DrvPsgWinAutoDnMaxResis_C));

  /* Chart: '<S157>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S157>/Constant10'
   *  Constant: '<S157>/Constant16'
   *  Constant: '<S157>/Constant9'
   */
  if (rtb_LogicalOperator1_ako) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gj >= (float32)
         WinCtl_DrvPsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gj++;
      AppSwcBcm_ARID_DEF.cnt_heal_igy = (uint16)((float32)
        WinCtl_DrvPsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_igy == 0) {
      WinCtl_DrvPsgWinAutoDnSw = false;
    } else if (WinCtl_DrvPsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_igy--;
    }
  }

  /* End of Chart: '<S157>/LIB_TPD_10ms9' */
}

/* Output and update for atomic system: '<S11>/WinMotorProt' */
static void AppSwcBcm_WinMotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S158>/Logical Operator' incorporates:
   *  Constant: '<S158>/Constant'
   *  Constant: '<S158>/Constant4'
   *  RelationalOperator: '<S158>/Relational Operator'
   *  RelationalOperator: '<S158>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_mc = ((WinCtl_DrvWinSta == 4) || (WinCtl_DrvWinSta
    == 3));

  /* Chart: '<S158>/LIB_CntLimit1' incorporates:
   *  SubSystem: '<S176>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_mc,
    &AppSwcBcm_ARID_DEF.LogicalOperator_gf0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_kk);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_gf0 && (!WinCtl_DrvWinDnProt)) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_d + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_d + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_d = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_j = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_j + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_j + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_j = (uint16)tmp;
  }

  /* Constant: '<S158>/Constant1' */
  if (AppSwcBcm_ARID_DEF.Cnt2_j >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_d - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_d - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_d = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_j = 0U;
  }

  /* End of Constant: '<S158>/Constant1' */

  /* Constant: '<S158>/Constant2' */
  WinCtl_DrvWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_d > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S158>/Relational Operator1' incorporates:
   *  Constant: '<S158>/Constant3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_js = (WinCtl_DrvWinSta == 2);

  /* Chart: '<S158>/LIB_CntLimit' incorporates:
   *  SubSystem: '<S175>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_js,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ku,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ieu);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ku && (!WinCtl_DrvWinUpProt)) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_g5 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_g5 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_g5 = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_ja = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_ja + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_ja + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_ja = (uint16)tmp;
  }

  /* Constant: '<S158>/Constant14' */
  if (AppSwcBcm_ARID_DEF.Cnt2_ja >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_g5 - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_g5 - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_g5 = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_ja = 0U;
  }

  /* End of Constant: '<S158>/Constant14' */

  /* Constant: '<S158>/Constant15' */
  WinCtl_DrvWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_g5 > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S158>/Relational Operator4' incorporates:
   *  Constant: '<S158>/Constant10'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ik = (WinCtl_PsgWinSta == 2);

  /* Chart: '<S158>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S177>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ik,
    &AppSwcBcm_ARID_DEF.LogicalOperator_i3,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ox);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_i3 && (!WinCtl_PsgWinUpProt)) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ae + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ae + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_ae = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o0 = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_o0 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_o0 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_o0 = (uint16)tmp;
  }

  /* Constant: '<S158>/Constant8' */
  if (AppSwcBcm_ARID_DEF.Cnt2_o0 >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ae - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ae - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_ae = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o0 = 0U;
  }

  /* End of Constant: '<S158>/Constant8' */

  /* Constant: '<S158>/Constant9' */
  WinCtl_PsgWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_ae > WinCtl_WinProtNum_C);

  /* Logic: '<S158>/Logical Operator1' incorporates:
   *  Constant: '<S158>/Constant11'
   *  Constant: '<S158>/Constant7'
   *  RelationalOperator: '<S158>/Relational Operator3'
   *  RelationalOperator: '<S158>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_kb = ((WinCtl_PsgWinSta == 4) || (WinCtl_PsgWinSta
    == 3));

  /* Chart: '<S158>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S178>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kb,
    &AppSwcBcm_ARID_DEF.LogicalOperator_fw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ie);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_fw && (!WinCtl_PsgWinDnProt)) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_n + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_n + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_n = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_o + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_o + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_o = (uint16)tmp;
  }

  /* Constant: '<S158>/Constant5' */
  if (AppSwcBcm_ARID_DEF.Cnt2_o >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_n - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_n - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_n = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  }

  /* End of Constant: '<S158>/Constant5' */

  /* Constant: '<S158>/Constant6' */
  WinCtl_PsgWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_n > WinCtl_WinProtNum_C);
}

/*
 * Output and update for function-call system:
 *    '<S187>/Lib_RiseEdgeDet'
 *    '<S187>/Lib_RiseEdgeDet1'
 *    '<S188>/Lib_RiseEdgeDet'
 *    '<S191>/Lib_RiseEdgeDet'
 *    '<S191>/Lib_RiseEdgeDet1'
 *    '<S607>/Lib_RiseEdgeDet'
 *    '<S608>/Lib_RiseEdgeDet'
 */
static void AppSwcBcm_Lib_RiseEdgeDet_n(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_j_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S206>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S206>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S159>/Chart6'
 *    '<S159>/Chart7'
 *    '<S159>/Chart8'
 *    '<S159>/Chart9'
 */
static void AppSwcBcm_Chart6_Init(boolean *rty_Lib_Out)
{
  *rty_Lib_Out = false;
}

/*
 * Output and update for atomic system:
 *    '<S159>/Chart6'
 *    '<S159>/Chart7'
 *    '<S159>/Chart8'
 *    '<S159>/Chart9'
 */
static void AppSwcBcm_Chart6(boolean rtu_Lib_blIn1, boolean rtu_Lib_blIn2, uint8
  rtu_Lib_blIn3, boolean *rty_Lib_Out, ARID_DEF_Chart6_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S159>/Chart6' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c20_WinCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c20_WinCtl_Lib = 1U;
    AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  } else if (AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_Lib_blIn1;

    /* Outputs for Function Call SubSystem: '<S196>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

    /* End of Outputs for SubSystem: '<S196>/Lib_RiseEdgeDet' */
    if (AppSwcBcm__ARID_DEF_arg->LogicalOperator && (!rtu_Lib_blIn2)) {
      AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib = AppSwcBcm_IN_On;
      *rty_Lib_Out = true;
    }

    /* case IN_On: */
  } else if ((!rtu_Lib_blIn1) || rtu_Lib_blIn2 || (rtu_Lib_blIn3 == 0)) {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_Lib_blIn1;

    /* Outputs for Function Call SubSystem: '<S196>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

    /* End of Outputs for SubSystem: '<S196>/Lib_RiseEdgeDet' */
    AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  }

  /* End of Chart: '<S159>/Chart6' */
}

/*
 * System initialize for atomic system:
 *    '<S159>/LIB_NegPluse'
 *    '<S355>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S159>/LIB_NegPluse'
 *    '<S355>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_NegPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S159>/LIB_NegPluse' */
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

  /* End of Chart: '<S159>/LIB_NegPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S159>/LIB_PosPluse'
 *    '<S631>/LIB_Tim'
 *    '<S873>/LIB_Tim'
 *    '<S890>/LIB_PosPluse'
 *    '<S894>/LIB_PosPluse'
 *    '<S894>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S159>/LIB_PosPluse'
 *    '<S631>/LIB_Tim'
 *    '<S873>/LIB_Tim'
 *    '<S890>/LIB_PosPluse'
 *    '<S894>/LIB_PosPluse'
 *    '<S894>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_PosPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S159>/LIB_PosPluse' */
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

  /* End of Chart: '<S159>/LIB_PosPluse' */
}

/* System initialize for atomic system: '<S11>/WinSwArb' */
static void AppSwcBcm_WinSwArb_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_g;
  boolean rtb_LIB_blOut_c;

  /* SystemInitialize for Chart: '<S159>/Chart6' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_k);

  /* SystemInitialize for Chart: '<S159>/Chart7' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_o);

  /* SystemInitialize for Chart: '<S159>/Chart8' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_h);

  /* SystemInitialize for Chart: '<S159>/Chart9' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out);

  /* SystemInitialize for Chart: '<S159>/LIB_NegPluse' */
  AppSwcBcm_LIB_NegPluse_Init(&rtb_LIB_blOut_c);

  /* SystemInitialize for Chart: '<S159>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_g);
}

/* Output and update for atomic system: '<S11>/WinSwArb' */
static void AppSwcBcm_WinSwArb(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_g;
  boolean rtb_LIB_blOut_c;
  sint32 tmp;
  uint8 rtb_Switch;
  uint8 tmp_0;
  boolean guard1 = false;
  boolean rtb_LogicalOperator20;
  boolean rtb_LogicalOperator22;
  boolean rtb_LogicalOperator3_c;
  boolean rtb_LogicalOperator42;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator_dp;
  boolean rtb_UnitDelay1;

  /* Logic: '<S159>/Logical Operator20' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_LogicalOperator20 = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ov ||
    WinCtl_DrvWinUpSw || WinCtl_DrvWinAutoDnSw);

  /* Chart: '<S159>/Chart2' incorporates:
   *  UnitDelay: '<S159>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c11_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_DrvWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib == AppSwcBcm_IN_Off_a) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kq = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S192>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kq,
      &AppSwcBcm_ARID_DEF.LogicalOperator_l5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_da);

    /* End of Outputs for SubSystem: '<S192>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_l5 && (!rtb_LogicalOperator20) &&
        (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_On_hd;
      WinCtl_DrvWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinDnSw) || rtb_LogicalOperator20 || (WinCtl_DrvWinReq ==
              0)) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kq = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S192>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kq,
      &AppSwcBcm_ARID_DEF.LogicalOperator_l5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_da);

    /* End of Outputs for SubSystem: '<S192>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_DrvWinDnReq = false;
  }

  /* End of Chart: '<S159>/Chart2' */

  /* Logic: '<S159>/Logical Operator19' incorporates:
   *  UnitDelay: '<S11>/Unit Delay1'
   */
  rtb_LogicalOperator20 = (WinCtl_DrvWinUpSw ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ov);

  /* Chart: '<S159>/Chart10' incorporates:
   *  UnitDelay: '<S159>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_d;
    WinCtl_DrvWinAutoDnReq = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib) {
     case AppSwcBcm_IN_HoldOn:
      if ((!WinCtl_DrvWinAutoDnSw) && (!WinCtl_DrvWinDnSw)) {
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_On_i;
        WinCtl_DrvWinAutoDnReq = true;
      } else if ((WinCtl_DrvWinReq == 0) || rtb_LogicalOperator20) {
        AppSwcBcm_ARID_DEF.Lib_blIn_ac = WinCtl_DrvWinAutoDnSw;

        /* Outputs for Function Call SubSystem: '<S188>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pe);

        /* End of Outputs for SubSystem: '<S188>/Lib_RiseEdgeDet' */
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_d;
        WinCtl_DrvWinAutoDnReq = false;
      }
      break;

     case AppSwcBcm_IN_Off_d:
      AppSwcBcm_ARID_DEF.Lib_blIn_ac = WinCtl_DrvWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S188>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pe);

      /* End of Outputs for SubSystem: '<S188>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jm && (!rtb_LogicalOperator20)) {
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_HoldOn;
        WinCtl_DrvWinAutoDnReq = true;
      }
      break;

     default:
      /* case IN_On: */
      AppSwcBcm_ARID_DEF.Lib_blIn_ac = WinCtl_DrvWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S188>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pe);

      /* End of Outputs for SubSystem: '<S188>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jm || (WinCtl_DrvWinReq == 0) ||
          rtb_LogicalOperator20 || WinCtl_DrvWinDnSw) {
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_d;
        WinCtl_DrvWinAutoDnReq = false;
      }
      break;
    }
  }

  /* End of Chart: '<S159>/Chart10' */

  /* Logic: '<S159>/Logical Operator21' incorporates:
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  rtb_LogicalOperator20 = (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_d ||
    WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnSw);

  /* Chart: '<S159>/Chart3' incorporates:
   *  UnitDelay: '<S159>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c12_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c12_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_DrvWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib == AppSwcBcm_IN_Off_a) {
    AppSwcBcm_ARID_DEF.Lib_blIn_gc = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S193>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fg,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ax);

    /* End of Outputs for SubSystem: '<S193>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fg && (!rtb_LogicalOperator20) &&
        (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib = AppSwcBcm_IN_On_hd;
      WinCtl_DrvWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinUpSw) || rtb_LogicalOperator20 || (WinCtl_DrvWinReq ==
              0)) {
    AppSwcBcm_ARID_DEF.Lib_blIn_gc = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S193>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fg,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ax);

    /* End of Outputs for SubSystem: '<S193>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_DrvWinUpReq = false;
  }

  /* End of Chart: '<S159>/Chart3' */

  /* Switch: '<S159>/Switch' incorporates:
   *  Switch: '<S159>/Switch1'
   */
  if (WinCtl_DrvWinDnReq) {
    /* Switch: '<S159>/Switch' incorporates:
     *  Constant: '<S159>/Constant'
     */
    rtb_Switch = 2U;
  } else if (WinCtl_DrvWinAutoDnReq) {
    /* Switch: '<S159>/Switch1' incorporates:
     *  Constant: '<S159>/Constant1'
     *  Switch: '<S159>/Switch'
     */
    rtb_Switch = 3U;
  } else {
    /* Switch: '<S159>/Switch' incorporates:
     *  Switch: '<S159>/Switch1'
     *  Switch: '<S159>/Switch2'
     */
    rtb_Switch = WinCtl_DrvWinUpReq;
  }

  /* End of Switch: '<S159>/Switch' */

  /* RelationalOperator: '<S159>/Relational Operator4' incorporates:
   *  Constant: '<S159>/Constant19'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator20 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S159>/Relational Operator' incorporates:
   *  Constant: '<S159>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S159>/Relational Operator5'
   */
  rtb_RelationalOperator_dp = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 0);

  /* UnitDelay: '<S159>/Unit Delay1' incorporates:
   *  Constant: '<S159>/Constant31'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S159>/Relational Operator6'
   */
  rtb_UnitDelay1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())
                    ->BodyWarnSts == 3);

  /* Chart: '<S159>/LIB_NegPluse' incorporates:
   *  Constant: '<S159>/Constant20'
   *  Logic: '<S159>/Logical Operator12'
   *  Logic: '<S159>/Logical Operator17'
   */
  AppSwcBcm_LIB_NegPluse(rtb_LogicalOperator20 && (rtb_RelationalOperator_dp ||
    rtb_UnitDelay1), WinCtl_PwrOffWinValidTimMax_C, &rtb_LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse);

  /* UnitDelay: '<S159>/Unit Delay1' incorporates:
   *  Constant: '<S159>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S159>/Relational Operator3'
   */
  rtb_UnitDelay1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
                    ->SysPwrMode == 2);

  /* Logic: '<S159>/Logical Operator5' */
  rtb_LogicalOperator20 = (rtb_UnitDelay1 || rtb_LIB_blOut_c);

  /* UnitDelay: '<S159>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S159>/Relational Operator2'
   */
  rtb_UnitDelay1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
                    ->SysPwrMode == 0);

  /* RelationalOperator: '<S159>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S159>/Relational Operator11'
   */
  rtb_RelationalOperator_dp = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 5);

  /* Logic: '<S159>/Logical Operator9' */
  rtb_LogicalOperator9 = (rtb_UnitDelay1 && rtb_RelationalOperator_dp);

  /* Chart: '<S159>/Chart6' incorporates:
   *  Logic: '<S159>/Logical Operator13'
   *  UnitDelay: '<S11>/Unit Delay1'
   *  UnitDelay: '<S159>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, WinCtl_DrvWinUpSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ov || WinCtl_DrvWinDnSw ||
                   WinCtl_DrvWinAutoDnSw, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_k,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart6);

  /* RelationalOperator: '<S159>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_dp = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 6);

  /* Logic: '<S159>/Logical Operator3' */
  rtb_LogicalOperator3_c = (rtb_UnitDelay1 && rtb_RelationalOperator_dp);

  /* Chart: '<S159>/Chart7' incorporates:
   *  Logic: '<S159>/Logical Operator14'
   *  UnitDelay: '<S11>/Unit Delay3'
   *  UnitDelay: '<S159>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_c, WinCtl_DrvWinDnSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_d ||
                   WinCtl_DrvWinAutoDnSw || WinCtl_DrvWinUpSw, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_o,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart7);

  /* Chart: '<S159>/LIB_PosPluse' incorporates:
   *  Constant: '<S159>/Constant40'
   *  Logic: '<S159>/Logical Operator10'
   */
  AppSwcBcm_LIB_PosPluse(WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnReq ||
    WinCtl_DrvWinUpSw || rtb_LogicalOperator9 || rtb_LogicalOperator3_c,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_e);

  /* Chart: '<S159>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S159>/Constant34'
   *  Constant: '<S159>/Constant35'
   *  Constant: '<S159>/Constant36'
   *  Constant: '<S159>/Constant37'
   *  RelationalOperator: '<S159>/Relational Operator9'
   */
  if (BSW_DrvWinMotorCur >= WinCtl_WinMotorCurMax_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fv >= (float32)
         WinCtl_WinMotorCurTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_WinMotorCurTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinMotorLocked = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fv++;
      AppSwcBcm_ARID_DEF.cnt_heal_mo = (uint16)((float32)
        WinCtl_WinMotorCurTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fv = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mo == 0) {
      WinCtl_DrvWinMotorLocked = false;
    } else if (WinCtl_WinMotorCurTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mo--;
    }
  }

  /* End of Chart: '<S159>/LIB_TPD_10ms3' */

  /* Switch: '<S159>/Switch11' incorporates:
   *  Constant: '<S159>/Constant25'
   *  Logic: '<S159>/Logical Operator6'
   *  Logic: '<S159>/Logical Operator8'
   *  Switch: '<S159>/Switch8'
   */
  if (WinCtl_DrvWinMotorLocked || rtb_LIB_blOut_g) {
    WinCtl_DrvWinReq = 0U;
  } else {
    if (rtb_LogicalOperator20) {
      /* Switch: '<S159>/Switch8' */
      tmp_0 = rtb_Switch;
    } else {
      /* Switch: '<S159>/Switch8' incorporates:
       *  Constant: '<S159>/Constant32'
       */
      tmp_0 = 0U;
    }

    /* Switch: '<S159>/Switch7' incorporates:
     *  Switch: '<S159>/Switch12'
     *  Switch: '<S159>/Switch8'
     */
    if (tmp_0 != 0) {
      /* Switch: '<S159>/Switch7' */
      WinCtl_DrvWinReq = rtb_Switch;
    } else if (AppSwcBcm_ARID_DEF.Lib_Out_k) {
      /* Switch: '<S159>/Switch12' incorporates:
       *  Constant: '<S159>/Constant43'
       */
      WinCtl_DrvWinReq = 2U;
    } else {
      /* Switch: '<S159>/Switch12' incorporates:
       *  Switch: '<S159>/Switch3'
       */
      WinCtl_DrvWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_o;
    }

    /* End of Switch: '<S159>/Switch7' */
  }

  /* End of Switch: '<S159>/Switch11' */

  /* Chart: '<S159>/Chart8' incorporates:
   *  Logic: '<S159>/Logical Operator16'
   *  UnitDelay: '<S11>/Unit Delay2'
   *  UnitDelay: '<S159>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_c, WinCtl_PsgWinAutoDnSw ||
                   WinCtl_PsgWinDnSw || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_eq ||
                   WinCtl_PsgWinUpSw || WinCtl_DrvPsgWinAutoDnSw ||
                   WinCtl_DrvPsgWinUpSw || WinCtl_DrvPsgWinDnSw,
                   WinCtl_PsgWinReq, &AppSwcBcm_ARID_DEF.Lib_Out_h,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart8);

  /* Chart: '<S159>/Chart9' incorporates:
   *  Logic: '<S159>/Logical Operator15'
   *  UnitDelay: '<S11>/Unit Delay4'
   *  UnitDelay: '<S159>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, WinCtl_PsgWinUpSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_ig ||
                   WinCtl_PsgWinAutoDnSw || WinCtl_PsgWinDnSw ||
                   WinCtl_DrvPsgWinAutoDnSw || WinCtl_DrvPsgWinUpSw ||
                   WinCtl_DrvPsgWinDnSw, WinCtl_PsgWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart9);

  /* Chart: '<S159>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S159>/Constant10'
   *  Constant: '<S159>/Constant11'
   *  Constant: '<S159>/Constant44'
   *  Constant: '<S159>/Constant48'
   *  RelationalOperator: '<S159>/Relational Operator7'
   */
  if (BSW_PsgWinMotorCur >= WinCtl_WinMotorCurMax_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_os >= (float32)
         WinCtl_WinMotorCurTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_WinMotorCurTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinMotorLocked = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_os++;
      AppSwcBcm_ARID_DEF.cnt_heal_iw = (uint16)((float32)
        WinCtl_WinMotorCurTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_os = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_iw == 0) {
      WinCtl_PsgWinMotorLocked = false;
    } else if (WinCtl_WinMotorCurTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_iw--;
    }
  }

  /* End of Chart: '<S159>/LIB_TPD_10ms1' */

  /* Logic: '<S159>/Logical Operator18' incorporates:
   *  Logic: '<S159>/Logical Operator26'
   *  UnitDelay: '<S11>/Unit Delay4'
   *  UnitDelay: '<S159>/Unit Delay'
   */
  rtb_LogicalOperator22 = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_ig ||
    WinCtl_DrvPsgWinOvTimProt || WinCtl_PsgWinMotorLocked);

  /* Logic: '<S159>/Logical Operator25' incorporates:
   *  UnitDelay: '<S11>/Unit Delay4'
   *  UnitDelay: '<S159>/Unit Delay2'
   */
  rtb_UnitDelay1 = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_ig ||
                    WinCtl_PsgWinMotorLocked || WinCtl_PsgWinOvTimProt);

  /* Logic: '<S159>/Logical Operator33' incorporates:
   *  Logic: '<S159>/Logical Operator30'
   *  Logic: '<S159>/Logical Operator31'
   */
  rtb_RelationalOperator_dp = (WinCtl_DrvPsgWinUpSw || WinCtl_DrvPsgWinAutoDnSw ||
    WinCtl_DrvPsgWinDnSw);

  /* Logic: '<S159>/Logical Operator42' incorporates:
   *  Logic: '<S159>/Logical Operator33'
   *  Logic: '<S159>/Logical Operator41'
   *  UnitDelay: '<S159>/Unit Delay5'
   */
  rtb_LogicalOperator42 = (rtb_RelationalOperator_dp &&
    (!WinCtl_DrvPsgWinOvTimProt));

  /* Chart: '<S159>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_d;
    WinCtl_PsgWinAutoDnReq = false;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib) {
     case AppSwcBcm_IN_HoldOn:
      if ((!WinCtl_PsgWinAutoDnSw) && (!WinCtl_PsgWinDnSw)) {
        AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_On_i;
        WinCtl_PsgWinAutoDnReq = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_he = rtb_LogicalOperator42;

        /* Outputs for Function Call SubSystem: '<S187>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_he,
          &AppSwcBcm_ARID_DEF.LogicalOperator_lc,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

        /* End of Outputs for SubSystem: '<S187>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_lc || rtb_UnitDelay1) {
          AppSwcBcm_ARID_DEF.Lib_blIn_ao = WinCtl_PsgWinAutoDnSw;

          /* Outputs for Function Call SubSystem: '<S187>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ao,
            &AppSwcBcm_ARID_DEF.LogicalOperator_b0,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ft);

          /* End of Outputs for SubSystem: '<S187>/Lib_RiseEdgeDet' */
          AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_d;
          WinCtl_PsgWinAutoDnReq = false;
        }
      }
      break;

     case AppSwcBcm_IN_Off_d:
      AppSwcBcm_ARID_DEF.Lib_blIn_ao = WinCtl_PsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S187>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ao,
        &AppSwcBcm_ARID_DEF.LogicalOperator_b0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ft);

      /* End of Outputs for SubSystem: '<S187>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_b0 && (!rtb_UnitDelay1) &&
          (!rtb_LogicalOperator42)) {
        AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_HoldOn;
        WinCtl_PsgWinAutoDnReq = true;
      }
      break;

     default:
      /* case IN_On: */
      AppSwcBcm_ARID_DEF.Lib_blIn_ao = WinCtl_PsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S187>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ao,
        &AppSwcBcm_ARID_DEF.LogicalOperator_b0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ft);

      /* End of Outputs for SubSystem: '<S187>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_b0) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_he = rtb_LogicalOperator42;

        /* Outputs for Function Call SubSystem: '<S187>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_he,
          &AppSwcBcm_ARID_DEF.LogicalOperator_lc,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

        /* End of Outputs for SubSystem: '<S187>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_lc || rtb_UnitDelay1 ||
            WinCtl_PsgWinDnSw) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_d;
      WinCtl_PsgWinAutoDnReq = false;
    }
  }

  /* End of Chart: '<S159>/Chart1' */

  /* Logic: '<S159>/Logical Operator40' incorporates:
   *  Logic: '<S159>/Logical Operator34'
   *  Logic: '<S159>/Logical Operator39'
   *  UnitDelay: '<S159>/Unit Delay4'
   */
  rtb_UnitDelay1 = ((WinCtl_PsgWinUpSw || WinCtl_PsgWinAutoDnSw ||
                     WinCtl_PsgWinDnSw) && (!WinCtl_PsgWinOvTimProt));

  /* Chart: '<S159>/Chart13' */
  if (AppSwcBcm_ARID_DEF.is_active_c10_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c10_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_Off_d;
    WinCtl_DrvPsgWinAutoDnReq = false;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib) {
     case AppSwcBcm_IN_HoldOn:
      if ((!WinCtl_DrvPsgWinAutoDnSw) && (!WinCtl_DrvPsgWinDnSw)) {
        AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_On_i;
        WinCtl_DrvPsgWinAutoDnReq = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ju = rtb_UnitDelay1;

        /* Outputs for Function Call SubSystem: '<S191>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ju,
          &AppSwcBcm_ARID_DEF.LogicalOperator_bi,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_af);

        /* End of Outputs for SubSystem: '<S191>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_bi || rtb_LogicalOperator22) {
          AppSwcBcm_ARID_DEF.Lib_blIn_nq = WinCtl_DrvPsgWinAutoDnSw;

          /* Outputs for Function Call SubSystem: '<S191>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_nq,
            &AppSwcBcm_ARID_DEF.LogicalOperator_j2,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pb);

          /* End of Outputs for SubSystem: '<S191>/Lib_RiseEdgeDet' */
          AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_Off_d;
          WinCtl_DrvPsgWinAutoDnReq = false;
        }
      }
      break;

     case AppSwcBcm_IN_Off_d:
      AppSwcBcm_ARID_DEF.Lib_blIn_nq = WinCtl_DrvPsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S191>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_nq,
        &AppSwcBcm_ARID_DEF.LogicalOperator_j2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pb);

      /* End of Outputs for SubSystem: '<S191>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_j2 && (!rtb_LogicalOperator22) && (
           !rtb_UnitDelay1)) {
        AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_HoldOn;
        WinCtl_DrvPsgWinAutoDnReq = true;
      }
      break;

     default:
      /* case IN_On: */
      AppSwcBcm_ARID_DEF.Lib_blIn_nq = WinCtl_DrvPsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S191>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_nq,
        &AppSwcBcm_ARID_DEF.LogicalOperator_j2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pb);

      /* End of Outputs for SubSystem: '<S191>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_j2) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ju = rtb_UnitDelay1;

        /* Outputs for Function Call SubSystem: '<S191>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ju,
          &AppSwcBcm_ARID_DEF.LogicalOperator_bi,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_af);

        /* End of Outputs for SubSystem: '<S191>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_bi || rtb_LogicalOperator22 ||
            WinCtl_DrvPsgWinDnSw) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_Off_d;
      WinCtl_DrvPsgWinAutoDnReq = false;
    }
  }

  /* End of Chart: '<S159>/Chart13' */

  /* Logic: '<S159>/Logical Operator1' */
  rtb_UnitDelay1 = (WinCtl_PsgWinAutoDnReq || WinCtl_DrvPsgWinAutoDnReq);

  /* Chart: '<S159>/LIB_PosPluse1' incorporates:
   *  Constant: '<S159>/Constant8'
   *  Logic: '<S159>/Logical Operator11'
   */
  if (WinCtl_PsgWinUpSw || WinCtl_PsgWinDnSw || rtb_UnitDelay1 ||
      rtb_LogicalOperator9 || rtb_LogicalOperator3_c) {
    if (AppSwcBcm_ARID_DEF.Cnt_hn <= WinCtl_WinRunTimMax_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_hn + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_hn + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_hn = (uint16)tmp;
      WinCtl_PsgWinOvTimProt = false;
    } else {
      WinCtl_PsgWinOvTimProt = true;
    }
  } else {
    WinCtl_PsgWinOvTimProt = false;
    AppSwcBcm_ARID_DEF.Cnt_hn = 0U;
  }

  /* End of Chart: '<S159>/LIB_PosPluse1' */

  /* Logic: '<S159>/Logical Operator46' incorporates:
   *  Logic: '<S159>/Logical Operator29'
   *  Logic: '<S159>/Logical Operator45'
   */
  rtb_LogicalOperator42 = ((WinCtl_PsgWinAutoDnSw || WinCtl_PsgWinUpSw ||
    WinCtl_PsgWinDnSw) && (!WinCtl_PsgWinOvTimProt));

  /* Chart: '<S159>/Chart11' incorporates:
   *  Logic: '<S159>/Logical Operator18'
   *  UnitDelay: '<S159>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_DrvPsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib == AppSwcBcm_IN_Off_a) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ink = WinCtl_DrvPsgWinDnSw;

    /* Outputs for Function Call SubSystem: '<S189>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ink,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ne,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_lu);

    /* End of Outputs for SubSystem: '<S189>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ne && (!rtb_LogicalOperator22) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_cd = rtb_LogicalOperator42;

      /* Outputs for Function Call SubSystem: '<S189>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_cd,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_n);

      /* End of Outputs for SubSystem: '<S189>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_On_hd;
      WinCtl_DrvPsgWinDnReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_DrvPsgWinDnSw) || rtb_LogicalOperator22) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_cd = rtb_LogicalOperator42;

      /* Outputs for Function Call SubSystem: '<S189>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_cd,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_n);

      /* End of Outputs for SubSystem: '<S189>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_mp || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_ink = WinCtl_DrvPsgWinDnSw;

      /* Outputs for Function Call SubSystem: '<S189>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ink,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ne,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_lu);

      /* End of Outputs for SubSystem: '<S189>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_Off_a;
      WinCtl_DrvPsgWinDnReq = false;
    }
  }

  /* End of Chart: '<S159>/Chart11' */

  /* Logic: '<S159>/Logical Operator22' incorporates:
   *  UnitDelay: '<S11>/Unit Delay4'
   *  UnitDelay: '<S159>/Unit Delay1'
   */
  rtb_LogicalOperator22 = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_ig ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_bt || WinCtl_PsgWinMotorLocked);

  /* Chart: '<S159>/LIB_PosPluse2' incorporates:
   *  Constant: '<S159>/Constant47'
   *  Logic: '<S159>/Logical Operator27'
   */
  if (WinCtl_DrvPsgWinDnSw || WinCtl_DrvPsgWinUpSw || rtb_UnitDelay1 ||
      rtb_LogicalOperator9 || rtb_LogicalOperator3_c) {
    if (AppSwcBcm_ARID_DEF.Cnt_ge <= WinCtl_WinRunTimMax_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_ge + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_ge + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_ge = (uint16)tmp;
      WinCtl_DrvPsgWinOvTimProt = false;
    } else {
      WinCtl_DrvPsgWinOvTimProt = true;
    }
  } else {
    WinCtl_DrvPsgWinOvTimProt = false;
    AppSwcBcm_ARID_DEF.Cnt_ge = 0U;
  }

  /* End of Chart: '<S159>/LIB_PosPluse2' */

  /* Logic: '<S159>/Logical Operator44' incorporates:
   *  Logic: '<S159>/Logical Operator43'
   */
  rtb_LogicalOperator9 = (rtb_RelationalOperator_dp &&
    (!WinCtl_DrvPsgWinOvTimProt));

  /* Chart: '<S159>/Chart4' incorporates:
   *  UnitDelay: '<S159>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_PsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib == AppSwcBcm_IN_Off_a) {
    AppSwcBcm_ARID_DEF.Lib_blIn_p0 = WinCtl_PsgWinDnSw;

    /* Outputs for Function Call SubSystem: '<S194>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_p0,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ax3,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ch);

    /* End of Outputs for SubSystem: '<S194>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ax3 && (!rtb_LogicalOperator22) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_id = rtb_LogicalOperator9;

      /* Outputs for Function Call SubSystem: '<S194>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_id,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jx,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_ei);

      /* End of Outputs for SubSystem: '<S194>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_On_hd;
      WinCtl_PsgWinDnReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_PsgWinDnSw) || rtb_LogicalOperator22) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_id = rtb_LogicalOperator9;

      /* Outputs for Function Call SubSystem: '<S194>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_id,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jx,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_ei);

      /* End of Outputs for SubSystem: '<S194>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jx || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_p0 = WinCtl_PsgWinDnSw;

      /* Outputs for Function Call SubSystem: '<S194>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_p0,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ax3,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ch);

      /* End of Outputs for SubSystem: '<S194>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off_a;
      WinCtl_PsgWinDnReq = false;
    }
  }

  /* End of Chart: '<S159>/Chart4' */

  /* Logic: '<S159>/Logical Operator2' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_LogicalOperator9 = (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_eq ||
    WinCtl_DrvPsgWinOvTimProt || WinCtl_PsgWinMotorLocked);

  /* Logic: '<S159>/Logical Operator37' incorporates:
   *  Logic: '<S159>/Logical Operator32'
   *  Logic: '<S159>/Logical Operator38'
   */
  rtb_LogicalOperator3_c = ((WinCtl_PsgWinDnSw || WinCtl_PsgWinAutoDnSw ||
    WinCtl_PsgWinUpSw) && (!WinCtl_PsgWinOvTimProt));

  /* Chart: '<S159>/Chart12' incorporates:
   *  UnitDelay: '<S159>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c9_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_DrvPsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib == AppSwcBcm_IN_Off_a) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ly = WinCtl_DrvPsgWinUpSw;

    /* Outputs for Function Call SubSystem: '<S190>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ly,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ln,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o3);

    /* End of Outputs for SubSystem: '<S190>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ln && (!rtb_LogicalOperator9) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_gw = rtb_LogicalOperator3_c;

      /* Outputs for Function Call SubSystem: '<S190>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gw,
        &AppSwcBcm_ARID_DEF.LogicalOperator_a2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_m);

      /* End of Outputs for SubSystem: '<S190>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_On_hd;
      WinCtl_DrvPsgWinUpReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_DrvPsgWinUpSw) || rtb_LogicalOperator9) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_gw = rtb_LogicalOperator3_c;

      /* Outputs for Function Call SubSystem: '<S190>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gw,
        &AppSwcBcm_ARID_DEF.LogicalOperator_a2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_m);

      /* End of Outputs for SubSystem: '<S190>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_a2 || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_ly = WinCtl_DrvPsgWinUpSw;

      /* Outputs for Function Call SubSystem: '<S190>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ly,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ln,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o3);

      /* End of Outputs for SubSystem: '<S190>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_Off_a;
      WinCtl_DrvPsgWinUpReq = false;
    }
  }

  /* End of Chart: '<S159>/Chart12' */

  /* Logic: '<S159>/Logical Operator23' incorporates:
   *  UnitDelay: '<S11>/Unit Delay2'
   */
  rtb_LogicalOperator9 = (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_eq ||
    WinCtl_PsgWinOvTimProt || WinCtl_PsgWinMotorLocked);

  /* Logic: '<S159>/Logical Operator35' incorporates:
   *  Logic: '<S159>/Logical Operator36'
   */
  rtb_RelationalOperator_dp = (rtb_RelationalOperator_dp &&
    (!WinCtl_DrvPsgWinOvTimProt));

  /* Chart: '<S159>/Chart5' incorporates:
   *  UnitDelay: '<S159>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off_a;
    WinCtl_PsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib == AppSwcBcm_IN_Off_a) {
    AppSwcBcm_ARID_DEF.Lib_blIn_jl = WinCtl_PsgWinUpSw;

    /* Outputs for Function Call SubSystem: '<S195>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jl,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lt,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h2);

    /* End of Outputs for SubSystem: '<S195>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_lt && (!rtb_LogicalOperator9) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_k2 = rtb_RelationalOperator_dp;

      /* Outputs for Function Call SubSystem: '<S195>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_k2,
        &AppSwcBcm_ARID_DEF.LogicalOperator_iy,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

      /* End of Outputs for SubSystem: '<S195>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_On_hd;
      WinCtl_PsgWinUpReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_PsgWinUpSw) || rtb_LogicalOperator9) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_k2 = rtb_RelationalOperator_dp;

      /* Outputs for Function Call SubSystem: '<S195>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_k2,
        &AppSwcBcm_ARID_DEF.LogicalOperator_iy,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

      /* End of Outputs for SubSystem: '<S195>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_iy || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_jl = WinCtl_PsgWinUpSw;

      /* Outputs for Function Call SubSystem: '<S195>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jl,
        &AppSwcBcm_ARID_DEF.LogicalOperator_lt,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h2);

      /* End of Outputs for SubSystem: '<S195>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off_a;
      WinCtl_PsgWinUpReq = false;
    }
  }

  /* End of Chart: '<S159>/Chart5' */

  /* Switch: '<S159>/Switch4' incorporates:
   *  Logic: '<S159>/Logical Operator'
   *  Switch: '<S159>/Switch5'
   */
  if (WinCtl_DrvPsgWinDnReq || WinCtl_PsgWinDnReq) {
    /* Switch: '<S159>/Switch4' incorporates:
     *  Constant: '<S159>/Constant12'
     */
    WinCtl_PsgWinReq = 2U;
  } else if (rtb_UnitDelay1) {
    /* Switch: '<S159>/Switch5' incorporates:
     *  Constant: '<S159>/Constant13'
     *  Switch: '<S159>/Switch4'
     */
    WinCtl_PsgWinReq = 3U;
  } else {
    /* Switch: '<S159>/Switch4' incorporates:
     *  Logic: '<S159>/Logical Operator24'
     *  Switch: '<S159>/Switch5'
     */
    WinCtl_PsgWinReq = (uint8)(WinCtl_PsgWinUpReq || WinCtl_DrvPsgWinUpReq);
  }

  /* End of Switch: '<S159>/Switch4' */

  /* Switch: '<S159>/Switch10' incorporates:
   *  Constant: '<S159>/Constant27'
   *  Logic: '<S159>/Logical Operator28'
   *  Logic: '<S159>/Logical Operator4'
   *  Logic: '<S159>/Logical Operator7'
   *  Switch: '<S159>/Switch9'
   */
  if (WinCtl_PsgWinMotorLocked || (WinCtl_PsgWinOvTimProt &&
       WinCtl_DrvPsgWinOvTimProt)) {
    WinCtl_PsgWinReq = 0U;
  } else {
    if (rtb_LogicalOperator20) {
      /* Switch: '<S159>/Switch9' */
      tmp_0 = WinCtl_PsgWinReq;
    } else {
      /* Switch: '<S159>/Switch9' incorporates:
       *  Constant: '<S159>/Constant33'
       */
      tmp_0 = 0U;
    }

    /* Switch: '<S159>/Switch13' incorporates:
     *  Switch: '<S159>/Switch9'
     */
    if (tmp_0 == 0) {
      /* Switch: '<S159>/Switch14' */
      if (AppSwcBcm_ARID_DEF.Lib_Out) {
        /* Switch: '<S159>/Switch14' incorporates:
         *  Constant: '<S159>/Constant16'
         */
        WinCtl_PsgWinReq = 2U;
      } else {
        /* Switch: '<S159>/Switch14' incorporates:
         *  Switch: '<S159>/Switch15'
         */
        WinCtl_PsgWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_h;
      }

      /* End of Switch: '<S159>/Switch14' */
    }

    /* End of Switch: '<S159>/Switch13' */
  }

  /* End of Switch: '<S159>/Switch10' */

  /* Update for UnitDelay: '<S159>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_bt = WinCtl_PsgWinOvTimProt;
}

/* System initialize for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S11>/WinSwArb' */
  AppSwcBcm_WinSwArb_Init();

  /* End of SystemInitialize for SubSystem: '<S11>/WinSwArb' */
}

/* Output and update for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl(void)
{
  /* Outputs for Atomic SubSystem: '<S11>/SigProc' */
  AppSwcBcm_SigProc();

  /* End of Outputs for SubSystem: '<S11>/SigProc' */

  /* Outputs for Atomic SubSystem: '<S11>/WinSwArb' */
  AppSwcBcm_WinSwArb();

  /* End of Outputs for SubSystem: '<S11>/WinSwArb' */

  /* Chart: '<S11>/DrvWinCtl' */
  AppSwcBcm_DrvWinCtl();

  /* Outputs for Atomic SubSystem: '<S11>/Ovrd4' */
  /* Switch: '<S154>/Switch1' incorporates:
   *  Constant: '<S11>/Constant1'
   */
  if (WinCtl_J53DrvWinDnOvrdFlg_C) {
    /* Switch: '<S154>/Switch1' incorporates:
     *  Constant: '<S11>/Constant2'
     */
    WinCtl_J53DrvWinDn = WinCtl_J53DrvWinDnOvrdVal_C;
  } else {
    /* Switch: '<S154>/Switch1' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion1'
     *  Switch: '<S154>/Switch2'
     */
    WinCtl_J53DrvWinDn = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFLOpenFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J53);
  }

  /* End of Switch: '<S154>/Switch1' */
  /* End of Outputs for SubSystem: '<S11>/Ovrd4' */

  /* Chart: '<S11>/PsgWinCtl' */
  AppSwcBcm_PsgWinCtl();

  /* Outputs for Atomic SubSystem: '<S11>/WinMotorProt' */
  AppSwcBcm_WinMotorProt();

  /* End of Outputs for SubSystem: '<S11>/WinMotorProt' */

  /* Outputs for Atomic SubSystem: '<S11>/Ovrd2' */
  /* Switch: '<S153>/Switch1' incorporates:
   *  Constant: '<S11>/Constant5'
   */
  if (WinCtl_J57PsgWinDnOvrdFlg_C) {
    /* Switch: '<S153>/Switch1' incorporates:
     *  Constant: '<S11>/Constant6'
     */
    WinCtl_J57PsgWinDn = WinCtl_J57PsgWinDnOvrdVal_C;
  } else {
    /* Switch: '<S153>/Switch1' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion3'
     *  Switch: '<S153>/Switch2'
     */
    WinCtl_J57PsgWinDn = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFROpenFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J57);
  }

  /* End of Switch: '<S153>/Switch1' */
  /* End of Outputs for SubSystem: '<S11>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S11>/Ovrd5' */
  /* Switch: '<S155>/Switch1' incorporates:
   *  Constant: '<S11>/Constant3'
   */
  if (WinCtl_J55PsgWinUpOvrdFlg_C) {
    /* Switch: '<S155>/Switch1' incorporates:
     *  Constant: '<S11>/Constant4'
     */
    WinCtl_J55PsgWinUp = WinCtl_J55PsgWinUpOvrdVal_C;
  } else {
    /* Switch: '<S155>/Switch1' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion2'
     *  Switch: '<S155>/Switch2'
     */
    WinCtl_J55PsgWinUp = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFRCloselFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J55);
  }

  /* End of Switch: '<S155>/Switch1' */
  /* End of Outputs for SubSystem: '<S11>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S11>/Ovrd1' */
  /* Switch: '<S152>/Switch1' incorporates:
   *  Constant: '<S11>/Constant18'
   */
  if (WinCtl_J51DrvWinUpOvrdFlg_C) {
    /* Switch: '<S152>/Switch1' incorporates:
     *  Constant: '<S11>/Constant19'
     */
    WinCtl_J51DrvWinUp = WinCtl_J51DrvWinUpOvrdVal_C;
  } else {
    /* Switch: '<S152>/Switch1' incorporates:
     *  DataTypeConversion: '<S11>/Data Type Conversion'
     *  Switch: '<S152>/Switch2'
     */
    WinCtl_J51DrvWinUp = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFLCloselFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J51);
  }

  /* End of Switch: '<S152>/Switch1' */
  /* End of Outputs for SubSystem: '<S11>/Ovrd1' */

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_d = WinCtl_DrvWinUpProt;

  /* Update for UnitDelay: '<S11>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_eq = WinCtl_PsgWinUpProt;

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ov = WinCtl_DrvWinDnProt;

  /* Update for UnitDelay: '<S11>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_ig = WinCtl_PsgWinDnProt;
}

/* Outputs for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl(void)
{
  sint32 tmp;
  uint8 rtb_CCaller2;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_k4;
  boolean rtb_RelationalOperator3_k0;
  boolean rtb_RelationalOperator6_ie;
  boolean rtb_RelationalOperator_f;

  /* RelationalOperator: '<S247>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S249>/Relational Operator3'
   */
  rtb_RelationalOperator_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())
    ->BodyWarnSts > 0);

  /* Switch: '<S249>/Switch' incorporates:
   *  Constant: '<S249>/Constant4'
   *  Logic: '<S249>/Logical Operator5'
   *  RelationalOperator: '<S249>/Relational Operator2'
   *  UnitDelay: '<S249>/Unit Delay'
   *  UnitDelay: '<S249>/Unit Delay1'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k == 0) && rtb_RelationalOperator_f)
  {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_o = 1U;
  }

  /* End of Switch: '<S249>/Switch' */

  /* RelationalOperator: '<S247>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S249>/Relational Operator5'
   */
  rtb_RelationalOperator_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* Logic: '<S247>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S249>/Relational Operator1'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S248>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S249>/Relational Operator6'
   */
  rtb_RelationalOperator3_k0 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S247>/Logical Operator' incorporates:
   *  Logic: '<S249>/Logical Operator7'
   */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_RelationalOperator3_k0);

  /* Logic: '<S249>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S249>/Unit Delay1'
   */
  rtb_LogicalOperator_k4 = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_o != 0) &&
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC())
     ->VIPM_HUIllmndEntrySts_enum != 0) && rtb_RelationalOperator_f &&
    rtb_LogicalOperator);

  /* Logic: '<S249>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator1_b =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarRRSw);

  /* Switch: '<S249>/Switch1' incorporates:
   *  Logic: '<S249>/Logical Operator3'
   *  Logic: '<S249>/Logical Operator8'
   *  UnitDelay: '<S249>/Unit Delay2'
   *  UnitDelay: '<S249>/Unit Delay3'
   */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i =
    ((AppSwcBcm_ARID_DEF.LogicalOperator1_b &&
      (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_ky)) ||
     AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i);

  /* RelationalOperator: '<S248>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S249>/Logical Operator2'
   */
  rtb_RelationalOperator3_k0 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* RelationalOperator: '<S248>/Relational Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S249>/Relational Operator4'
   */
  rtb_RelationalOperator6_ie = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 0);

  /* Logic: '<S249>/Logical Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S249>/Logical Operator4'
   *  UnitDelay: '<S249>/Unit Delay3'
   */
  rtb_RelationalOperator3_k0 = (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i &&
    rtb_RelationalOperator3_k0 &&
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC())
     ->VIPM_HUIllmndEntrySts_enum != 0) && (!rtb_RelationalOperator_f) &&
    rtb_LogicalOperator && rtb_RelationalOperator6_ie);

  /* CCaller: '<S244>/C Caller2' */
  rtb_CCaller2 = Get_Wlcm_FunStatus();

  /* CCaller: '<S244>/C Caller3' */
  Get_PollingWork_State();

  /* Chart: '<S249>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    Clear_PollingCommd();
    PEPSCtl_UnlckWlcmReq = 0U;
    PEPSCtl_LckWlcmReq = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_p:
      PEPSCtl_UnlckWlcmReq = 0U;
      PEPSCtl_LckWlcmReq = 0U;
      if (rtb_LogicalOperator_k4) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_UnlockDay0to7;
        AppSwcBcm_ARID_DEF.u8PollingFuncRequest = 3U;
      } else if (rtb_RelationalOperator3_k0) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_LockWlcm;
        AppSwcBcm_ARID_DEF.u8PollingFuncRequest = 2U;
      }
      break;

     case AppSwcBcm_IN_LockWlcm:
      if (rtb_CCaller2 == 3) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmLockReq;
        PEPSCtl_LckWlcmReq = 1U;
        AppSwcBcm_ARID_DEF.count = 0.0;
      }
      break;

     case AppSwcBcm_IN_UnlockDay0to7:
      if (rtb_CCaller2 == 2) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmUnlockReq;
        PEPSCtl_UnlckWlcmReq = 1U;
        AppSwcBcm_ARID_DEF.count = 0.0;
      }
      break;

     case AppSwcBcm_IN_UnlockExcedDay7:
      break;

     case AppSwcBcm_IN_WlcmLockReq:
      PEPSCtl_LckWlcmReq = 1U;
      if (AppSwcBcm_ARID_DEF.count > 20.0) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count++;
      }
      break;

     default:
      /* case IN_WlcmUnlockReq: */
      PEPSCtl_UnlckWlcmReq = 1U;
      if (AppSwcBcm_ARID_DEF.count > 20.0) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count++;
      }
      break;
    }
  }

  /* End of Chart: '<S249>/Chart' */

  /* CCaller: '<S244>/C Caller6' */
  Set_Polling_FunReq(AppSwcBcm_ARID_DEF.u8PollingFuncRequest);

  /* RelationalOperator: '<S248>/Relational Operator6' incorporates:
   *  Constant: '<S251>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S251>/Compare'
   */
  rtb_RelationalOperator6_ie = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 0);

  /* Logic: '<S245>/Logical Operator' incorporates:
   *  Constant: '<S252>/Constant'
   *  RelationalOperator: '<S252>/Compare'
   *  UnitDelay: '<S245>/Unit Delay'
   */
  rtb_RelationalOperator3_k0 = (rtb_RelationalOperator6_ie &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jq > 0));

  /* CCaller: '<S245>/C Caller1' */
  rtb_CCaller2 = Get_FobdKeyNum();

  /* Chart: '<S245>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib) {
     case AppSwcBcm_IN_FobidKey:
      if ((PEPSCtl_FrbdnKeyNr > 0) || (AppSwcBcm_ARID_DEF.count_g > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
      } else if (rtb_RelationalOperator3_k0) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_g = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller2;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_g + 1;
        if (AppSwcBcm_ARID_DEF.count_g + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_g = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller2;
      }
      break;

     case AppSwcBcm_IN_Init_h:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->OsLckSta == 2) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_FobidKey;
        AppSwcBcm_ARID_DEF.count_g = 0U;
        Set_PSAuth_FobReq(2U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller2;
      } else if (rtb_RelationalOperator3_k0) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_g = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller2;
      }
      break;

     default:
      /* case IN_RelesKey: */
      if ((PEPSCtl_FrbdnKeyNr == 0) || (AppSwcBcm_ARID_DEF.count_g > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_g + 1;
        if (AppSwcBcm_ARID_DEF.count_g + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_g = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller2;
      }
      break;
    }
  }

  /* End of Chart: '<S245>/Chart' */

  /* RelationalOperator: '<S248>/Relational Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S246>/Logical Operator1'
   */
  rtb_RelationalOperator6_ie =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw);

  /* RelationalOperator: '<S248>/Relational Operator3' incorporates:
   *  Constant: '<S257>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S257>/Compare'
   */
  rtb_RelationalOperator3_k0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S246>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S246>/Logical Operator'
   *  Logic: '<S246>/Logical Operator2'
   *  RelationalOperator: '<S255>/Compare'
   *  RelationalOperator: '<S256>/Compare'
   *  UnitDelay: '<S246>/Unit Delay'
   *  UnitDelay: '<S246>/Unit Delay1'
   */
  rtb_RelationalOperator3_k0 = (rtb_RelationalOperator6_ie &&
    ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h0) ||
     (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ah)) && rtb_RelationalOperator3_k0 &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->VehStop &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw);

  /* CCaller: '<S246>/C Caller7' */
  rtb_CCaller2 = Get_PSAuth_FobStatus();

  /* Chart: '<S246>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_nl = AppSwcBcm_ARID_DEF.Power_Mode_start_i;
  AppSwcBcm_ARID_DEF.Power_Mode_start_i =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  if (AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_nl =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.KeyNotFound_flg = 0.0;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib == AppSwcBcm_IN_Init_p) {
    if (rtb_RelationalOperator3_k0) {
      AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_KeyNotInCar;
      AppSwcBcm_ARID_DEF.count_f = 0U;
      AppSwcBcm_ARID_DEF.count1 = 0.0;
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
      Set_PSAuth_FobReq(1U);
    }

    /* case IN_KeyNotInCar: */
  } else if ((AppSwcBcm_ARID_DEF.Warnkeyout_flg == 1) ||
             ((AppSwcBcm_ARID_DEF.Power_Mode_prev_nl !=
               AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
              (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 0))) {
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.KeyNotFound_flg = 0.0;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else {
    if (rtb_CCaller2 == 2) {
      AppSwcBcm_ARID_DEF.KeyNotFound_flg = 1.0;
      PEPSCtl_WarnKeyOutReminder = 1U;
    }

    if (AppSwcBcm_ARID_DEF.KeyNotFound_flg == 1.0) {
      if (AppSwcBcm_ARID_DEF.count_f >= 1000) {
        AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
        AppSwcBcm_ARID_DEF.count_f = 1000U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_f + 1;
        if (AppSwcBcm_ARID_DEF.count_f + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_f = (uint16)tmp;
      }
    }

    if (rtb_CCaller2 == 1) {
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
    }

    if (rtb_CCaller2 == 0) {
      if (AppSwcBcm_ARID_DEF.count1 >= 200.0) {
        AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
        AppSwcBcm_ARID_DEF.count1 = 200.0;
      } else {
        AppSwcBcm_ARID_DEF.count1++;
      }
    }
  }

  /* End of Chart: '<S246>/Chart' */

  /* RelationalOperator: '<S248>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S247>/Logical Operator2'
   */
  rtb_RelationalOperator3_k0 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* RelationalOperator: '<S247>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_f =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum <= 1);

  /* Logic: '<S247>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarRRSw);

  /* RelationalOperator: '<S248>/Relational Operator3' incorporates:
   *  Logic: '<S247>/Logical Operator3'
   */
  rtb_RelationalOperator3_k0 = (rtb_RelationalOperator3_k0 &&
    rtb_RelationalOperator_f && rtb_LogicalOperator);

  /* Logic: '<S247>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S260>/Compare'
   *  UnitDelay: '<S247>/Unit Delay'
   */
  rtb_RelationalOperator6_ie = ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c2e) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw &&
    rtb_RelationalOperator3_k0);

  /* CCaller: '<S244>/C Caller' */
  rtb_CCaller2 = Get_PEAuth_FobStatus();

  /* Logic: '<S247>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S261>/Compare'
   *  UnitDelay: '<S247>/Unit Delay1'
   */
  rtb_RelationalOperator3_k0 = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw &&
    rtb_RelationalOperator3_k0);

  /* Chart: '<S247>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    PEPSCtl_DrvPEAuthentAcsd = 0U;
    PEPSCtl_KeyInCarSta = 0U;
    AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
    PEPSCtl_FRPEAuthentAcsd = 0U;
    AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
    AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
    Clear_PEStatus();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_p:
      if (rtb_RelationalOperator6_ie) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_LSeekKeyOut;
        Set_PEAuth_FobReq(1U);
        AppSwcBcm_ARID_DEF.count_of = 0U;
        AppSwcBcm_ARID_DEF.count1_j = 0U;
      } else if (rtb_RelationalOperator3_k0) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_RSeekKeyOut;
        Set_PEAuth_FobReq(2U);
        AppSwcBcm_ARID_DEF.count_of = 0U;
        AppSwcBcm_ARID_DEF.count1_j = 0U;
      }
      break;

     case AppSwcBcm_IN_LSeekKeyOut:
      if ((AppSwcBcm_ARID_DEF.count_of >= 10) ||
          (AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        PEPSCtl_DrvPEAuthentAcsd = 0U;
        PEPSCtl_KeyInCarSta = 0U;
        AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
        PEPSCtl_FRPEAuthentAcsd = 0U;
        AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
        AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
        Clear_PEStatus();
      } else {
        if (rtb_CCaller2 == 1) {
          PEPSCtl_DrvPEAuthentAcsd = 1U;
          tmp = AppSwcBcm_ARID_DEF.count_of + 1;
          if (AppSwcBcm_ARID_DEF.count_of + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_of = (uint8)tmp;
        }

        if (rtb_CCaller2 == 2) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_of + 1;
          if (AppSwcBcm_ARID_DEF.count_of + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_of = (uint8)tmp;
        }

        if (rtb_CCaller2 == 3) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_of + 1;
          if (AppSwcBcm_ARID_DEF.count_of + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_of = (uint8)tmp;
        }

        if (rtb_CCaller2 == 0) {
          if (AppSwcBcm_ARID_DEF.count1_j >= 150) {
            PEPSCtl_DrvPEAuthentAcsd = 2U;
            AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 1U;
            AppSwcBcm_ARID_DEF.count1_j = 0U;
          } else {
            tmp = AppSwcBcm_ARID_DEF.count1_j + 1;
            if (AppSwcBcm_ARID_DEF.count1_j + 1 > 255) {
              tmp = 255;
            }

            AppSwcBcm_ARID_DEF.count1_j = (uint8)tmp;
          }
        }
      }
      break;

     default:
      /* case IN_RSeekKeyOut: */
      if ((AppSwcBcm_ARID_DEF.count_of >= 10) ||
          (AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        PEPSCtl_DrvPEAuthentAcsd = 0U;
        PEPSCtl_KeyInCarSta = 0U;
        AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
        PEPSCtl_FRPEAuthentAcsd = 0U;
        AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
        AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
        Clear_PEStatus();
      } else {
        if (rtb_CCaller2 == 1) {
          PEPSCtl_FRPEAuthentAcsd = 1U;
          tmp = AppSwcBcm_ARID_DEF.count_of + 1;
          if (AppSwcBcm_ARID_DEF.count_of + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_of = (uint8)tmp;
        }

        if (rtb_CCaller2 == 2) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_of + 1;
          if (AppSwcBcm_ARID_DEF.count_of + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_of = (uint8)tmp;
        }

        if (rtb_CCaller2 == 3) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_of + 1;
          if (AppSwcBcm_ARID_DEF.count_of + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_of = (uint8)tmp;
        }

        if (rtb_CCaller2 == 0) {
          if (AppSwcBcm_ARID_DEF.count1_j >= 150) {
            PEPSCtl_FRPEAuthentAcsd = 2U;
            AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 1U;
            AppSwcBcm_ARID_DEF.count1_j = 0U;
          } else {
            tmp = AppSwcBcm_ARID_DEF.count1_j + 1;
            if (AppSwcBcm_ARID_DEF.count1_j + 1 > 255) {
              tmp = 255;
            }

            AppSwcBcm_ARID_DEF.count1_j = (uint8)tmp;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S247>/Chart' */

  /* Chart: '<S247>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    AppSwcBcm_ARID_DEF.count_o = 0.0;
    PEPSCtl_AvaluebleKeyInCar = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib == AppSwcBcm_IN_Init_p) {
    PEPSCtl_AvaluebleKeyInCar = 0U;
    if (AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar == 1.0F) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_e;
      AppSwcBcm_ARID_DEF.count_o = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_AvaluebleKeyInCar = 1U;
    if (AppSwcBcm_ARID_DEF.count_o >= 1000.0) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
      AppSwcBcm_ARID_DEF.count_o = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count_o++;
    }
  }

  /* End of Chart: '<S247>/Chart3' */

  /* RelationalOperator: '<S248>/Relational Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S248>/Relational Operator2'
   */
  rtb_RelationalOperator6_ie = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus
    ())->DrvSeatSw;

  /* Logic: '<S248>/Logical Operator5' incorporates:
   *  RelationalOperator: '<S248>/Relational Operator1'
   *  UnitDelay: '<S248>/Unit Delay'
   */
  rtb_RelationalOperator3_k0 = ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fa) &&
    rtb_RelationalOperator6_ie);

  /* RelationalOperator: '<S248>/Relational Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S248>/Relational Operator5'
   */
  rtb_RelationalOperator6_ie = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus()
    )->BrakeLightSw;

  /* Logic: '<S248>/Logical Operator1' incorporates:
   *  Logic: '<S248>/Logical Operator3'
   *  RelationalOperator: '<S248>/Relational Operator4'
   *  UnitDelay: '<S248>/Unit Delay1'
   */
  rtb_LogicalOperator_k4 = (((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_kf) &&
    rtb_RelationalOperator6_ie) || rtb_RelationalOperator3_k0);

  /* RelationalOperator: '<S248>/Relational Operator6' incorporates:
   *  UnitDelay: '<S248>/Unit Delay2'
   */
  rtb_RelationalOperator6_ie = (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k == 0);

  /* RelationalOperator: '<S248>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_k0 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* CCaller: '<S244>/C Caller1' */
  rtb_CCaller2 = Get_PSAuth_FobStatus();

  /* Chart: '<S248>/Chart' incorporates:
   *  Logic: '<S248>/Logical Operator2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
    PEPSCtl_PSAuthentRes = 0U;
    AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
    AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
    PEPSCtl_PSReq = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib == AppSwcBcm_IN_Init_p) {
    PEPSCtl_PSReq = 0U;
    if (rtb_LogicalOperator_k4 && rtb_RelationalOperator6_ie &&
        rtb_RelationalOperator3_k0) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_PSSeekKeyOut;
      AppSwcBcm_ARID_DEF.count_e = 0U;
      AppSwcBcm_ARID_DEF.count1_g = 0U;
      Set_PSAuth_FobReq(1U);
      PEPSCtl_PSReq = 1U;
    }
  } else {
    /* case IN_PSSeekKeyOut: */
    PEPSCtl_PSReq = 1U;
    if (AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg == 1) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
      AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
      PEPSCtl_PSAuthentRes = 0U;
      AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
      AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
      PEPSCtl_PSReq = 0U;
      Clear_PSStatus();
    } else {
      tmp = AppSwcBcm_ARID_DEF.count_e + 1;
      if (AppSwcBcm_ARID_DEF.count_e + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.count_e = (uint16)tmp;
      if (rtb_CCaller2 == 1) {
        if (AppSwcBcm_ARID_DEF.count1_g >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 1U;
          tmp = AppSwcBcm_ARID_DEF.count1_g + 1;
          if (AppSwcBcm_ARID_DEF.count1_g + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_g = (uint8)tmp;
        }
      }

      if (rtb_CCaller2 == 2) {
        if (AppSwcBcm_ARID_DEF.count1_g >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          tmp = AppSwcBcm_ARID_DEF.count1_g + 1;
          if (AppSwcBcm_ARID_DEF.count1_g + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_g = (uint8)tmp;
        }
      }

      if (rtb_CCaller2 == 3) {
        if (AppSwcBcm_ARID_DEF.count1_g >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 3U;
          tmp = AppSwcBcm_ARID_DEF.count1_g + 1;
          if (AppSwcBcm_ARID_DEF.count1_g + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_g = (uint8)tmp;
        }
      }

      if (rtb_CCaller2 == 0) {
        if (AppSwcBcm_ARID_DEF.count_e >= 200) {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 0U;
        }
      }
    }
  }

  /* End of Chart: '<S248>/Chart' */

  /* Chart: '<S248>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
    AppSwcBcm_ARID_DEF.count_j = 0.0;
    PEPSCtl_KeySta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib) {
     case AppSwcBcm_IN_IMMOKeyValid:
      PEPSCtl_KeySta = 3U;
      if (AppSwcBcm_ARID_DEF.count_j >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
        AppSwcBcm_ARID_DEF.count_j = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_j++;
      }
      break;

     case AppSwcBcm_IN_Init_h:
      PEPSCtl_KeySta = 0U;
      switch (AppSwcBcm_ARID_DEF.BCM_KeySta) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_RemoteKeyValid;
        AppSwcBcm_ARID_DEF.count_j = 0.0;
        PEPSCtl_KeySta = 1U;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_IMMOKeyValid;
        AppSwcBcm_ARID_DEF.count_j = 0.0;
        PEPSCtl_KeySta = 3U;
        break;
      }
      break;

     default:
      /* case IN_RemoteKeyValid: */
      PEPSCtl_KeySta = 1U;
      if (AppSwcBcm_ARID_DEF.count_j >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
        AppSwcBcm_ARID_DEF.count_j = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_j++;
      }
      break;
    }
  }

  /* End of Chart: '<S248>/Chart1' */

  /* Chart: '<S248>/Chart2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_n = AppSwcBcm_ARID_DEF.Power_Mode_start_j;
  AppSwcBcm_ARID_DEF.Power_Mode_start_j =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_n =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
    AppSwcBcm_ARID_DEF.count_m = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    PEPSCtl_IndicationKeyCloser = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_p:
      PEPSCtl_WarnNoKeyFound = 0U;
      PEPSCtl_IndicationKeyCloser = 0U;
      if (AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound == 1) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_SendNOKey;
        AppSwcBcm_ARID_DEF.count_m = 0.0;
        PEPSCtl_WarnNoKeyFound = 1U;
      }
      break;

     case AppSwcBcm_IN_NokeyTimecount:
      PEPSCtl_WarnNoKeyFound = 0U;
      if ((AppSwcBcm_ARID_DEF.count_m < 2000.0) &&
          (AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound == 1)) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_SendKeyCloser;
        AppSwcBcm_ARID_DEF.count_m = 0.0;
        PEPSCtl_IndicationKeyCloser = 1U;
      } else if ((AppSwcBcm_ARID_DEF.count_m >= 2000.0) ||
                 ((AppSwcBcm_ARID_DEF.Power_Mode_prev_n !=
                   AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
                  (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 2)) ||
                 ((AppSwcBcm_ARID_DEF.Power_Mode_prev_n !=
                   AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
                  (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 0)) ||
                 ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
                   AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
                  (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        AppSwcBcm_ARID_DEF.count_m = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
        PEPSCtl_IndicationKeyCloser = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_m++;
      }
      break;

     case AppSwcBcm_IN_SendKeyCloser:
      PEPSCtl_IndicationKeyCloser = 1U;
      if ((AppSwcBcm_ARID_DEF.count_m >= 1000.0) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_n !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 2)) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_n !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 0)) ||
          ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
            AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
           (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        AppSwcBcm_ARID_DEF.count_m = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
        PEPSCtl_IndicationKeyCloser = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_m++;
      }
      break;

     default:
      /* case IN_SendNOKey: */
      PEPSCtl_WarnNoKeyFound = 1U;
      if (((AppSwcBcm_ARID_DEF.Power_Mode_prev_n !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 2)) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_n !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 0)) ||
          ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
            AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
           (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_p;
        AppSwcBcm_ARID_DEF.count_m = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
        PEPSCtl_IndicationKeyCloser = 0U;
      } else if (AppSwcBcm_ARID_DEF.count_m >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_NokeyTimecount;
        AppSwcBcm_ARID_DEF.count_m = 0.0;
        PEPSCtl_WarnNoKeyFound = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_m++;
      }
      break;
    }
  }

  /* End of Chart: '<S248>/Chart2' */

  /* Chart: '<S248>/Chart5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev = AppSwcBcm_ARID_DEF.Power_Mode_start;
  AppSwcBcm_ARID_DEF.Power_Mode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  if (AppSwcBcm_ARID_DEF.is_active_c12_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.is_active_c12_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
    PEPSCtl_IMMOKey = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib == AppSwcBcm_IN_IMMOKeyValid)
  {
    PEPSCtl_IMMOKey = 1U;
    if ((AppSwcBcm_ARID_DEF.Power_Mode_prev !=
         AppSwcBcm_ARID_DEF.Power_Mode_start) &&
        (AppSwcBcm_ARID_DEF.Power_Mode_start == 0)) {
      AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
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

  /* End of Chart: '<S248>/Chart5' */

  /* CCaller: '<S244>/C Caller7' */
  rtb_CCaller2 = Get_KeyBat_VolLow();

  /* Chart: '<S246>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c9_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Init_h;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Finish:
      PEPSCtl_KeyLoBattLvlWarn = 0U;
      break;

     case AppSwcBcm_IN_Init_h:
      if (rtb_CCaller2 == 1) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid;
        AppSwcBcm_ARID_DEF.count_i = 0.0;
        PEPSCtl_KeyLoBattLvlWarn = 1U;
      }
      break;

     default:
      /* case IN_KeyValid: */
      PEPSCtl_KeyLoBattLvlWarn = 1U;
      if (AppSwcBcm_ARID_DEF.count_i >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Finish;
        PEPSCtl_KeyLoBattLvlWarn = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_i++;
      }
      break;
    }
  }

  /* End of Chart: '<S246>/Chart3' */
}

/* Update for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl_Update(void)
{
  /* Update for UnitDelay: '<S249>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S249>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_ky =
    AppSwcBcm_ARID_DEF.LogicalOperator1_b;

  /* Update for UnitDelay: '<S245>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S246>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h0 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Update for UnitDelay: '<S246>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ah =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* Update for UnitDelay: '<S247>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c2e =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw;

  /* Update for UnitDelay: '<S247>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw;

  /* Update for UnitDelay: '<S248>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fa =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* Update for UnitDelay: '<S248>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_kf =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S248>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k = PEPSCtl_KeySta;
}

/* Output and update for atomic system: '<S267>/HwOutBCM' */
static void AppSwcBcm_HwOutBCM(void)
{
  uint8 rtb_DataTypeConversion33;
  boolean rtb_LogicalOperator1_in;

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion14'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J421IG1RlyCtl;

  /* CCaller: '<S271>/HwIG1RlyCls' */
  SetHw_IG1RlyCls(rtb_DataTypeConversion33);

  /* Logic: '<S297>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S297>/Logical Operator'
   *  RelationalOperator: '<S297>/Relational Operator'
   */
  rtb_LogicalOperator1_in = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->HazardLightSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->EmerHazardLightSta);
  rtb_LogicalOperator1_in = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrRSta && (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLSta && rtb_LogicalOperator1_in);

  /* CCaller: '<S271>/HwHzrdLampOn' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion16'
   */
  SetHw_HzrdLampOn(rtb_LogicalOperator1_in);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion22'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->DomeLampPwmDuty;

  /* CCaller: '<S271>/HwCabinLampPWM' incorporates:
   *  Constant: '<S271>/Constant43'
   */
  SetHw_CabinLampPWM(200U, rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion15'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J437IG2RlyCtl;

  /* CCaller: '<S271>/HwIG2RlyCls' */
  SetHw_IG2RlyCls(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion31'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->J408BackLampPWM;

  /* CCaller: '<S271>/HwBackLightCtl' incorporates:
   *  Constant: '<S271>/Constant'
   */
  SetHw_BackLightDrv(100U, rtb_DataTypeConversion33);

  /* CCaller: '<S271>/HwDrvSeatHeatCtl' incorporates:
   *  Constant: '<S271>/Constant1'
   */
  SetHw_DrvSeatHeat(200U, AppSwcBcm_ARID_DEF.SeatCtl_Bus.CN167DrvSeatHtPWM);

  /* CCaller: '<S271>/HwWiprOn' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion'
   */
  SetHw_WiprOn(AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv);

  /* CCaller: '<S271>/HwWiprHiSpd' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion1'
   */
  SetHw_WiprHiSpd(AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv);

  /* CCaller: '<S271>/HwFrntWshrOn' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion2'
   */
  SetHw_FrntWshrOn(AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion3'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J56DoorUnlck;

  /* CCaller: '<S271>/HwGlbDoorUnlck' */
  SetHw_GlbDoorUnlck(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion4'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J54DoorLck;

  /* CCaller: '<S271>/HwGlbDoorLck' */
  SetHw_GlbDoorLck(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion5'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J51DrvWinUp;

  /* CCaller: '<S271>/HwDrvrWinUp' */
  SetHw_DrvrWinUp(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion6'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J53DrvWinDn;

  /* CCaller: '<S271>/HwDrvrWinDwn' */
  SetHw_DrvrWinDwn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion7'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J55PsgWinUp;

  /* CCaller: '<S271>/HwPsngrWinUp' */
  SetHw_PsngrWinUp(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion8'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J57PsgWinDn;

  /* CCaller: '<S271>/HwPsngrWinDwn' */
  SetHw_PsngrWinDwn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion9'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->PosLampSta;

  /* CCaller: '<S271>/HwPstnLampOn' */
  SetHw_PstnLampOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion10'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLSta;

  /* CCaller: '<S271>/HwTurnLampOnLeft' */
  SetHw_TurnLampOnLeft(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion11'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrRSta;

  /* CCaller: '<S271>/HwTurnLampOnRght' */
  SetHw_TurnLampOnRght(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion12'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BrakeLightSta;

  /* CCaller: '<S271>/HwBrkLghtOn' */
  SetHw_BrkLghtOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion13'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->ReverseLampSta;

  /* CCaller: '<S271>/HwRvrsLampOn' */
  SetHw_RvrsLampOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion17'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->LowBeamSta;

  /* CCaller: '<S271>/HwLoBeamOn' */
  SetHw_LoBeamOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion18'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->HiBeamSta;

  /* CCaller: '<S271>/HwHiBeamOn' */
  SetHw_HiBeamOn(rtb_DataTypeConversion33);

  /* CCaller: '<S271>/HwAlrmHornOn' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion19'
   */
  SetHw_AlrmHornOn(AppSwcBcm_ARID_DEF.BusCreator9.HornDrv);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion20'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->FogLampRSta;

  /* CCaller: '<S271>/HwRearFogLampOn' */
  SetHw_RearFogLampOn(rtb_DataTypeConversion33);

  /* CCaller: '<S271>/HwSavePwrEnbl' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion21'
   */
  SetHw_SavePwrEnbl(AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion23'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->DayRunLightSta;

  /* CCaller: '<S271>/HwDayRunLghtOn' */
  SetHw_DayRunLghtOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion24'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J511TrunkUnlck;

  /* CCaller: '<S271>/HwTrunkUnlck' */
  Set_TrunkUnLock(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion25'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BSDLeftCtl;

  /* CCaller: '<S271>/HwBSDLeftCtl' */
  Set_BSDLeftCtl(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion26'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BSDRightCtl;

  /* CCaller: '<S271>/HwBSDRightCtl' */
  Set_BSDRightCtl(rtb_DataTypeConversion33);

  /* CCaller: '<S271>/HwESCLPwrSup' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion27'
   */
  SetHw_PwrSup(AppSwcBcm_ARID_DEF.ESCLCtl_Bus.J436PwrSup);

  /* CCaller: '<S271>/HwRVMHeatCtl' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion28'
   */
  SetHw_RearMirrorHeat(AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion29'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BoxLampSta;

  /* CCaller: '<S271>/HwBoxLampCtl' */
  SetHw_BoxLampSta(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S271>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S271>/DataTypeConversion30'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->FogLampFSta;

  /* CCaller: '<S271>/HwFrontFogLampCtl' */
  SetHw_FrontFogLamps(rtb_DataTypeConversion33);

  /* CCaller: '<S271>/HwSteerWhlHeat' incorporates:
   *  DataTypeConversion: '<S271>/DataTypeConversion33'
   */
  SetHw_SteerWhlHeat(AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.J447SteerWhlHt);
}

/*
 * System initialize for atomic system:
 *    '<S275>/Lib_RiseEdgeDelay'
 *    '<S276>/Lib_RiseEdgeDelay'
 *    '<S276>/Lib_RiseEdgeDelay1'
 *    '<S278>/Lib_RiseEdgeDelay'
 *    '<S278>/Lib_RiseEdgeDelay1'
 *    '<S874>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S275>/Lib_RiseEdgeDelay'
 *    '<S276>/Lib_RiseEdgeDelay'
 *    '<S276>/Lib_RiseEdgeDelay1'
 *    '<S278>/Lib_RiseEdgeDelay'
 *    '<S278>/Lib_RiseEdgeDelay1'
 *    '<S874>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16DelayTim, boolean *rty_LIB_blOut,
  ARID_DEF_Lib_RiseEdgeDelay_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rtb_LogicalOperator1_lt;

  /* Outputs for Function Call SubSystem: '<S298>/Lib_RiseEdgeDet' */
  /* Logic: '<S300>/Logical Operator1' incorporates:
   *  UnitDelay: '<S300>/Unit Delay'
   */
  rtb_LogicalOperator1_lt = !AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S300>/Unit Delay' incorporates:
   *  Chart: '<S275>/Lib_RiseEdgeDelay'
   */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_LIB_blIn;

  /* Chart: '<S275>/Lib_RiseEdgeDelay' incorporates:
   *  Logic: '<S300>/Logical Operator'
   */
  if (rtu_LIB_blIn && rtb_LogicalOperator1_lt) {
    AppSwcBcm__ARID_DEF_arg->Cnt = rtu_LIB_u16DelayTim;
    *rty_LIB_blOut = true;
  }

  /* End of Outputs for SubSystem: '<S298>/Lib_RiseEdgeDet' */
  if (AppSwcBcm__ARID_DEF_arg->Cnt <= 0) {
    *rty_LIB_blOut = false;
  } else {
    AppSwcBcm__ARID_DEF_arg->Cnt--;
  }
}

/* System initialize for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx_Init(void)
{
  boolean LIB_blOut_l5;

  /* SystemInitialize for Chart: '<S275>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_jm);

  /* SystemInitialize for Chart: '<S276>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_j);

  /* SystemInitialize for Chart: '<S276>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_kp);

  /* SystemInitialize for Chart: '<S278>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_l5);

  /* SystemInitialize for Chart: '<S278>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_l5);
}

/* Output and update for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx(void)
{
  uint8 rtb_MultiportSwitch;
  uint8 rtb_MultiportSwitch_c;
  boolean rtb_RelationalOperator_c0;

  /* DataTypeConversion: '<S267>/Data Type Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Left =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Right =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrRSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Rear =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampRSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLampSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PosLampSta;

  /* RelationalOperator: '<S287>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S280>/Logical Operator'
   *  Logic: '<S280>/Logical Operator1'
   *  RelationalOperator: '<S280>/Relational Operator'
   */
  rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->HazardLightSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->EmerHazardLightSta);
  rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->TurnIndcrRSta && (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLSta && rtb_RelationalOperator_c0);

  /* DataTypeConversion: '<S267>/Data Type Conversion4' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardLampSts =
    rtb_RelationalOperator_c0;

  /* DataTypeConversion: '<S267>/Data Type Conversion5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LowBeamSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Front =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampFSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AutoLampStatus =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->AutoLampSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion9' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLightSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->DayRunLightSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion10' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLampSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->ReverseLampSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion11' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLampSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BrakeLightSta;

  /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  switch ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrMod) {
   case 0:
    /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
     *  Constant: '<S272>/Constant'
     */
    rtb_MultiportSwitch = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
     *  Constant: '<S272>/Constant1'
     */
    rtb_MultiportSwitch = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
     *  Constant: '<S272>/Constant2'
     */
    rtb_MultiportSwitch = 4U;
    break;

   case 3:
    /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
     *  Constant: '<S272>/Constant3'
     */
    rtb_MultiportSwitch = 1U;
    break;

   case 4:
    /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
     *  Constant: '<S272>/Constant4'
     */
    rtb_MultiportSwitch = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S272>/Multiport Switch' incorporates:
     *  UnitDelay: '<S272>/Unit Delay'
     */
    rtb_MultiportSwitch = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p1;
    break;
  }

  /* End of MultiPortSwitch: '<S272>/Multiport Switch' */

  /* Switch: '<S273>/Switch' incorporates:
   *  Constant: '<S273>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S273>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLaneLSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 0U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLaneRSw)
  {
    /* Switch: '<S273>/Switch1' incorporates:
     *  Constant: '<S273>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 1U;
  } else {
    /* Switch: '<S273>/Switch1' incorporates:
     *  Constant: '<S273>/Constant'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 2U;
  }

  /* End of Switch: '<S273>/Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion15' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightIntensity =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LightIntstSta;

  /* Switch: '<S284>/Switch' incorporates:
   *  Constant: '<S284>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PosLampSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 1U;
  } else {
    /* Logic: '<S284>/Logical Operator' */
    rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
      ->LowBeamSw || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamSw);

    /* Switch: '<S284>/Switch1' incorporates:
     *  Switch: '<S284>/Switch2'
     */
    if (rtb_RelationalOperator_c0) {
      /* Switch: '<S284>/Switch1' incorporates:
       *  Constant: '<S284>/Constant1'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 2U;
    } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->AutoLampSw) {
      /* Switch: '<S284>/Switch2' incorporates:
       *  Constant: '<S284>/Constant'
       *  Switch: '<S284>/Switch1'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 3U;
    } else {
      /* Switch: '<S284>/Switch1' incorporates:
       *  Constant: '<S284>/Constant3'
       *  Switch: '<S284>/Switch2'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 0U;
    }

    /* End of Switch: '<S284>/Switch1' */
  }

  /* End of Switch: '<S284>/Switch' */

  /* Switch: '<S290>/Switch' incorporates:
   *  Constant: '<S290>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S290>/Switch1'
   *  Switch: '<S290>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LowBeamSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 0U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamSw) {
    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PassLightSw) {
    /* Switch: '<S290>/Switch2' incorporates:
     *  Constant: '<S290>/Constant'
     *  Switch: '<S290>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 2U;
  } else {
    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/Constant3'
     *  Switch: '<S290>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 3U;
  }

  /* End of Switch: '<S290>/Switch' */

  /* RelationalOperator: '<S287>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator7'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->HoodAjarSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion19' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Hood =
    rtb_RelationalOperator_c0;

  /* DataTypeConversion: '<S267>/Data Type Conversion20' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardWarningLightSwSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HazardLightSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion21' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntFogLiSwSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampFSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiSwSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampRSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion23' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FlwrMeHmCtrlFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FlwrMeHomeCtlFb;

  /* Switch: '<S291>/Switch' incorporates:
   *  Constant: '<S291>/Constant2'
   *  Constant: '<S291>/Constant4'
   *  Constant: '<S291>/Constant5'
   *  Logic: '<S291>/Logical Operator'
   *  RelationalOperator: '<S291>/Relational Operator'
   *  RelationalOperator: '<S291>/Relational Operator1'
   *  RelationalOperator: '<S291>/Relational Operator2'
   *  RelationalOperator: '<S291>/Relational Operator3'
   *  Switch: '<S291>/Switch1'
   *  Switch: '<S291>/Switch2'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator9.TrunkWarnSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.AntiLckSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.PartArmedSta == 1)) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.ArmedSta != 0) {
    /* Switch: '<S291>/Switch1' incorporates:
     *  Constant: '<S291>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.SeekSta != 0) {
    /* Switch: '<S291>/Switch2' incorporates:
     *  Constant: '<S291>/Constant'
     *  Switch: '<S291>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 4U;
  } else {
    /* Switch: '<S291>/Switch1' incorporates:
     *  Constant: '<S291>/Constant3'
     *  Switch: '<S291>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 0U;
  }

  /* End of Switch: '<S291>/Switch' */

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator6'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->TrunkAjarSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion25' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Trunk =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator2'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFLSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion26' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator3'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFRSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion27' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator4'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarRLSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion28' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator5'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarRRSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion29' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RR =
    rtb_RelationalOperator_c0;

  /* MultiPortSwitch: '<S292>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.BusCreator6.WiperSta) {
   case 0:
    /* MultiPortSwitch: '<S292>/Multiport Switch' incorporates:
     *  Constant: '<S292>/Constant'
     */
    rtb_MultiportSwitch_c = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S292>/Multiport Switch' incorporates:
     *  Constant: '<S292>/Constant1'
     */
    rtb_MultiportSwitch_c = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S292>/Multiport Switch' incorporates:
     *  Constant: '<S292>/Constant2'
     */
    rtb_MultiportSwitch_c = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S292>/Multiport Switch' incorporates:
     *  Constant: '<S292>/Constant3'
     */
    rtb_MultiportSwitch_c = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S292>/Multiport Switch' incorporates:
     *  Constant: '<S292>/Constant4'
     */
    rtb_MultiportSwitch_c = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S292>/Multiport Switch' incorporates:
     *  UnitDelay: '<S292>/Unit Delay'
     */
    rtb_MultiportSwitch_c = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m;
    break;
  }

  /* End of MultiPortSwitch: '<S292>/Multiport Switch' */

  /* MultiPortSwitch: '<S293>/Multiport Switch' incorporates:
   *  Constant: '<S293>/Constant'
   *  Constant: '<S293>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (!(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvSeatSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 2U;
  }

  /* End of MultiPortSwitch: '<S293>/Multiport Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion41' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntWshrSwSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WashSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion42' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWashSts =
    AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv;

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S294>/Constant2'
   *  Switch: '<S294>/Switch1'
   *  Switch: '<S294>/Switch2'
   *  Switch: '<S294>/Switch3'
   *  Switch: '<S294>/Switch4'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.WiperOffSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperLowSpdSw) {
    /* Switch: '<S294>/Switch1' incorporates:
     *  Constant: '<S294>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperHiSpdSw) {
    /* Switch: '<S294>/Switch2' incorporates:
     *  Constant: '<S294>/Constant'
     *  Switch: '<S294>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperMistSw) {
    /* Switch: '<S294>/Switch3' incorporates:
     *  Constant: '<S294>/Constant3'
     *  Switch: '<S294>/Switch1'
     *  Switch: '<S294>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperInrSw) {
    /* Switch: '<S294>/Switch4' incorporates:
     *  Constant: '<S294>/Constant4'
     *  Switch: '<S294>/Switch1'
     *  Switch: '<S294>/Switch2'
     *  Switch: '<S294>/Switch3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 4U;
  } else {
    /* Switch: '<S294>/Switch2' incorporates:
     *  Constant: '<S294>/Constant5'
     *  Switch: '<S294>/Switch1'
     *  Switch: '<S294>/Switch3'
     *  Switch: '<S294>/Switch4'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 6U;
  }

  /* End of Switch: '<S294>/Switch' */

  /* Switch: '<S295>/Switch' incorporates:
   *  Constant: '<S295>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S295>/Switch1'
   *  Switch: '<S295>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinUpSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinDnSw) {
    /* Switch: '<S295>/Switch1' incorporates:
     *  Constant: '<S295>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinAutoDnSw) {
    /* Switch: '<S295>/Switch2' incorporates:
     *  Constant: '<S295>/Constant'
     *  Switch: '<S295>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 4U;
  } else {
    /* Switch: '<S295>/Switch1' incorporates:
     *  Constant: '<S295>/Constant3'
     *  Switch: '<S295>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 0U;
  }

  /* End of Switch: '<S295>/Switch' */

  /* Switch: '<S296>/Switch' incorporates:
   *  Constant: '<S296>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S296>/Switch1'
   *  Switch: '<S296>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinUpSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinDnSw) {
    /* Switch: '<S296>/Switch1' incorporates:
     *  Constant: '<S296>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinAutoDnSw) {
    /* Switch: '<S296>/Switch2' incorporates:
     *  Constant: '<S296>/Constant'
     *  Switch: '<S296>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 4U;
  } else {
    /* Switch: '<S296>/Switch1' incorporates:
     *  Constant: '<S296>/Constant3'
     *  Switch: '<S296>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 0U;
  }

  /* End of Switch: '<S296>/Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion49' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion50' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinSta;

  /* Switch: '<S274>/Switch1' incorporates:
   *  Constant: '<S274>/Constant1'
   *  Logic: '<S274>/Logical Operator'
   *  Switch: '<S274>/Switch'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv &&
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts =
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv;
  }

  /* End of Switch: '<S274>/Switch1' */

  /* DataTypeConversion: '<S267>/Data Type Conversion52' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntLeDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvPESw;

  /* DataTypeConversion: '<S267>/Data Type Conversion53' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntRiDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->PsgPESw;

  /* DataTypeConversion: '<S267>/Data Type Conversion54' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkSwtSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkSw;

  /* DataTypeConversion: '<S267>/Data Type Conversion98' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnNoKeyFound =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnNoKeyFound;

  /* DataTypeConversion: '<S267>/Data Type Conversion55' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* DataTypeConversion: '<S267>/Data Type Conversion97' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSAuthentRes =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSAuthentRes;

  /* DataTypeConversion: '<S267>/Data Type Conversion96' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RKEReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->RKEReq;

  /* DataTypeConversion: '<S267>/Data Type Conversion95' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyInCarSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyInCarSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion94' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->DrvPEAuthentAcsd;

  /* DataTypeConversion: '<S267>/Data Type Conversion72' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FRPEAuthentAcsd;

  /* DataTypeConversion: '<S267>/Data Type Conversion71' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSReq;

  /* DataTypeConversion: '<S267>/Data Type Conversion57' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* DataTypeConversion: '<S267>/Data Type Conversion58' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChgWiperMtMdSwSetFb =
    AppSwcBcm_ARID_DEF.BusCreator6.WiperMaintSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion59' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ParkAutoUnlockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;

  /* DataTypeConversion: '<S267>/Data Type Conversion60' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_OverspdCntrlLockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->SpdCtlLckSetFb;

  /* DataTypeConversion: '<S267>/Data Type Conversion37' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrbdnKeyNr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FrbdnKeyNr;

  /* DataTypeConversion: '<S267>/Data Type Conversion101' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AvaluebleKeyInCar =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->AvaluebleKeyInCar;

  /* DataTypeConversion: '<S267>/Data Type Conversion104' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyLoBattLvlWarn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyLoBattLvlWarn;

  /* DataTypeConversion: '<S267>/Data Type Conversion70' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeySta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeySta;

  /* Chart: '<S275>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S275>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->WelcomeLampSta, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_jm,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_g);

  /* DataTypeConversion: '<S267>/Data Type Conversion64' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLampReq =
    AppSwcBcm_ARID_DEF.LIB_blOut_jm;

  /* Chart: '<S276>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S276>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeUnlck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_a);

  /* Chart: '<S276>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S276>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeLck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_kp,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1_b);

  /* Switch: '<S276>/Switch' incorporates:
   *  Constant: '<S276>/Constant2'
   *  Constant: '<S276>/Constant4'
   *  Switch: '<S276>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_j) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.LIB_blOut_kp) {
    /* Switch: '<S276>/Switch1' incorporates:
     *  Constant: '<S276>/Constant3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 0U;
  }

  /* End of Switch: '<S276>/Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion106' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnKeyOutReminder =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnKeyOutReminder;

  /* DataTypeConversion: '<S267>/Data Type Conversion107' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IndicationKeyCloser =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->IndicationKeyCloser;

  /* DataTypeConversion: '<S267>/Data Type Conversion67' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* DataTypeConversion: '<S267>/Data Type Conversion68' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLadjvalFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BackLadjvalFb;

  /* DataTypeConversion: '<S267>/Data Type Conversion82' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakePedalSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BrakeLightSw;

  /* BusCreator: '<S267>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S267>/Data Type Conversion83'
   *  DataTypeConversion: '<S267>/Data Type Conversion84'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;

  /* Switch: '<S279>/Switch' incorporates:
   *  Constant: '<S279>/Constant2'
   *  Constant: '<S279>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 1U;
  }

  /* End of Switch: '<S279>/Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion85' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;

  /* DataTypeConversion: '<S267>/Data Type Conversion86' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockSta_FL =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* BusCreator: '<S267>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S267>/Data Type Conversion126'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte15 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->RemotePwrLckSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion135' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndLckStsFb;

  /* DataTypeConversion: '<S267>/Data Type Conversion136' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndUnlockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndUnlockStsFb;

  /* Switch: '<S281>/Switch' incorporates:
   *  Constant: '<S281>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S281>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FlwrMeHomeSta) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->WelcomeLampSta)
  {
    /* Switch: '<S281>/Switch1' incorporates:
     *  Constant: '<S281>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 2U;
  } else {
    /* Switch: '<S281>/Switch1' incorporates:
     *  Constant: '<S281>/Constant2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 0U;
  }

  /* End of Switch: '<S281>/Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion138' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_VhclSeek =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta;

  /* Switch: '<S282>/Switch' incorporates:
   *  Constant: '<S282>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S282>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrRShort) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrROpen)
  {
    /* Switch: '<S282>/Switch1' incorporates:
     *  Constant: '<S282>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 2U;
  } else {
    /* Switch: '<S282>/Switch1' incorporates:
     *  Constant: '<S282>/Constant2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S282>/Switch' */

  /* Switch: '<S283>/Switch' incorporates:
   *  Constant: '<S283>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S283>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLShort) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLOpen)
  {
    /* Switch: '<S283>/Switch1' incorporates:
     *  Constant: '<S283>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 2U;
  } else {
    /* Switch: '<S283>/Switch1' incorporates:
     *  Constant: '<S283>/Constant2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S283>/Switch' */

  /* DataTypeConversion: '<S267>/Data Type Conversion148' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockOperationRecord =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DynDID_Bus())->DynDID_DoorOpRecord;

  /* Switch: '<S288>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S288>/Switch1'
   *  Switch: '<S288>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinUpSw) {
    /* BusCreator: '<S267>/Bus Creator1' incorporates:
     *  Constant: '<S288>/Constant2'
     *  DataTypeConversion: '<S267>/Data Type Conversion165'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinDnSw) {
    /* Switch: '<S288>/Switch1' incorporates:
     *  BusCreator: '<S267>/Bus Creator1'
     *  Constant: '<S288>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinAutoDnSw)
  {
    /* Switch: '<S288>/Switch2' incorporates:
     *  BusCreator: '<S267>/Bus Creator1'
     *  Constant: '<S288>/Constant'
     *  Switch: '<S288>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig = 4U;
  } else {
    /* BusCreator: '<S267>/Bus Creator1' incorporates:
     *  Constant: '<S288>/Constant3'
     *  Switch: '<S288>/Switch1'
     *  Switch: '<S288>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig = 0U;
  }

  /* End of Switch: '<S288>/Switch' */

  /* BusCreator: '<S267>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S267>/Data Type Conversion142'
   *  DataTypeConversion: '<S267>/Data Type Conversion143'
   *  DataTypeConversion: '<S267>/Data Type Conversion144'
   *  DataTypeConversion: '<S267>/Data Type Conversion153'
   *  DataTypeConversion: '<S267>/Data Type Conversion155'
   *  DataTypeConversion: '<S267>/Data Type Conversion162'
   *  DataTypeConversion: '<S267>/Data Type Conversion163'
   *  DataTypeConversion: '<S267>/Data Type Conversion164'
   *  DataTypeConversion: '<S267>/Data Type Conversion167'
   *  DataTypeConversion: '<S267>/Data Type Conversion78'
   *  DataTypeConversion: '<S267>/Data Type Conversion79'
   *  DataTypeConversion: '<S267>/Data Type Conversion80'
   *  Logic: '<S285>/Logical Operator'
   *  Logic: '<S286>/Logical Operator'
   *  RelationalOperator: '<S277>/Relational Operator'
   * */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorFlags =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinDnProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinUpProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinMotorLocked);
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorFlags =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinDnProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinUpProt ||
     (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinMotorLocked);
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamLiFaultFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamShortToBat;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamLiFaultFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LowBeamShortToBat;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemoteCarSearchFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekStaFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemoteLockFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RemoteLockFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemotePowerLockFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->RemotePwrLckFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemtPowerCtrlFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->RemotePwrCtlFb;

  /* RelationalOperator: '<S287>/Relational Operator' incorporates:
   *  Constant: '<S289>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S289>/Relational Operator'
   */
  rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->DomeLampPwmDuty > 0);

  /* BusCreator: '<S267>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S267>/Data Type Conversion170'
   *  DataTypeConversion: '<S267>/Data Type Conversion171'
   *  DataTypeConversion: '<S267>/Data Type Conversion75'
   *  DataTypeConversion: '<S267>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DomeLightSta =
    rtb_RelationalOperator_c0;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CarriageLightSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BoxLampSta;

  /* RelationalOperator: '<S287>/Relational Operator' incorporates:
   *  Constant: '<S287>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->J408BackLampPWM > 0);

  /* BusCreator: '<S267>/Bus Creator1' incorporates:
   *  Constant: '<S267>/Constant1'
   *  Constant: '<S267>/Constant10'
   *  Constant: '<S267>/Constant11'
   *  Constant: '<S267>/Constant12'
   *  Constant: '<S267>/Constant13'
   *  Constant: '<S267>/Constant15'
   *  Constant: '<S267>/Constant16'
   *  Constant: '<S267>/Constant17'
   *  Constant: '<S267>/Constant18'
   *  Constant: '<S267>/Constant19'
   *  Constant: '<S267>/Constant2'
   *  Constant: '<S267>/Constant20'
   *  Constant: '<S267>/Constant21'
   *  Constant: '<S267>/Constant22'
   *  Constant: '<S267>/Constant23'
   *  Constant: '<S267>/Constant24'
   *  Constant: '<S267>/Constant26'
   *  Constant: '<S267>/Constant29'
   *  Constant: '<S267>/Constant3'
   *  Constant: '<S267>/Constant37'
   *  Constant: '<S267>/Constant38'
   *  Constant: '<S267>/Constant39'
   *  Constant: '<S267>/Constant40'
   *  Constant: '<S267>/Constant41'
   *  Constant: '<S267>/Constant42'
   *  Constant: '<S267>/Constant43'
   *  Constant: '<S267>/Constant44'
   *  Constant: '<S267>/Constant45'
   *  Constant: '<S267>/Constant46'
   *  Constant: '<S267>/Constant5'
   *  Constant: '<S267>/Constant6'
   *  Constant: '<S267>/Constant7'
   *  Constant: '<S267>/Constant8'
   *  Constant: '<S267>/Constant9'
   *  DataTypeConversion: '<S267>/Data Type Conversion169'
   *  DataTypeConversion: '<S267>/Data Type Conversion172'
   *  DataTypeConversion: '<S267>/Data Type Conversion173'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiSwSig = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLiSts = rtb_MultiportSwitch;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarStaV_Hood = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LockHornOnStFb =
    AppSwcBcm_ARID_DEF.BusCreator9.LockHoornOnStFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AlrmHornReq =
    AppSwcBcm_ARID_DEF.BusCreator9.AlarmSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperCtrl_Front =
    rtb_MultiportSwitch_c;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WashLiquidLevelWarn =
    AppSwcBcm_ConstB.BCM_WashLiquidLevelWarn;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiprIntlGearSwtSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSig = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChrgLidLockReq = 0U;
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
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SteerWhlTemp =
    AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.SteerWhlTemp;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_MaiDrvrSeatTemp =
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.DrvSeatTemp;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_MaiDrvrSeatSts =
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.MaiDrvSeatStFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSwCtrlFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte0 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte1 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte2 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte3 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte4 = 0U;
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
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RFInitSta = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontFogLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LFInitSta = false;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.DrvLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.IntLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.PassLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemtMaiDrSeatHeatFb =
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.RemtHeatFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemtSteerWhlHeatFb =
    AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.RemtHeatFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperStopPosSta =
    AppSwcBcm_ARID_DEF.BusCreator6.WiperParkPosSw;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLampSta =
    rtb_RelationalOperator_c0;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SavePowerSta =
    AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr;

  /* BusCreator: '<S267>/Bus Creator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S267>/Data Type Conversion73'
   *  DataTypeConversion: '<S267>/Data Type Conversion74'
   *  DataTypeConversion: '<S267>/Data Type Conversion75'
   *  DataTypeConversion: '<S267>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFLSw;

  /* BusCreator: '<S267>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S267>/Data Type Conversion77'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator8'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFRSw;

  /* BusCreator: '<S267>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S267>/Data Type Conversion78'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator9'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarRLSw;

  /* BusCreator: '<S267>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S267>/Data Type Conversion79'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator_c0;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator10'
   */
  rtb_RelationalOperator_c0 = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarRRSw;

  /* BusCreator: '<S267>/Bus Creator2' incorporates:
   *  Constant: '<S267>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S267>/Data Type Conversion142'
   *  DataTypeConversion: '<S267>/Data Type Conversion143'
   *  DataTypeConversion: '<S267>/Data Type Conversion165'
   *  DataTypeConversion: '<S267>/Data Type Conversion67'
   *  DataTypeConversion: '<S267>/Data Type Conversion80'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAiarSta_RR =
    rtb_RelationalOperator_c0;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.AppSwcBcmVersion = 4U;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_NMReq_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.NMReq;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SleepAllwd_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.SleepAllwd;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* RelationalOperator: '<S277>/Relational Operator' incorporates:
   *  Constant: '<S267>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S267>/Logical Operator1'
   *  RelationalOperator: '<S267>/Relational Operator'
   */
  rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->PartArmedSta == 1);
  rtb_RelationalOperator_c0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->EmerSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLOpen || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrROpen || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->AntiLckSta || rtb_RelationalOperator_c0 ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TrunkWarnSta);

  /* DataTypeConversion: '<S267>/Data Type Conversion93' */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_b = rtb_RelationalOperator_c0;

  /* Switch: '<S277>/Switch' incorporates:
   *  Constant: '<S277>/Constant'
   *  Constant: '<S277>/Constant1'
   *  Constant: '<S277>/Constant2'
   *  Constant: '<S277>/Constant4'
   *  RelationalOperator: '<S277>/Relational Operator'
   *  RelationalOperator: '<S277>/Relational Operator1'
   *  Switch: '<S277>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 1) {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      282574488338432ULL;
  } else if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 2) {
    /* Switch: '<S277>/Switch1' incorporates:
     *  Constant: '<S277>/Constant3'
     *  Switch: '<S277>/Switch'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      564049465049088ULL;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl = 0ULL;
  }

  /* End of Switch: '<S277>/Switch' */

  /* Chart: '<S278>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S278>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HULck, 25, &rtb_RelationalOperator_c0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_o);

  /* Chart: '<S278>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S278>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HUUnlck, 25, &rtb_RelationalOperator_c0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1);

  /* DataTypeConversion: '<S267>/Data Type Conversion89' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_p =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion90' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_c =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PosLampSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion91' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_f =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->DayRunLightSta;

  /* DataTypeConversion: '<S267>/Data Type Conversion92' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrRSta;

  /* BusCreator: '<S267>/Bus Creator' */
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

  /* Outputs for Atomic SubSystem: '<S267>/HwOutBCM' */
  AppSwcBcm_HwOutBCM();

  /* End of Outputs for SubSystem: '<S267>/HwOutBCM' */

  /* Update for UnitDelay: '<S272>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p1 = rtb_MultiportSwitch;

  /* Update for UnitDelay: '<S292>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m = rtb_MultiportSwitch_c;
}

/* Output and update for atomic system: '<S3>/EEReadCtl' */
static void AppSwcBcm_EEReadCtl(void)
{
  uint8 i;

  /* Chart: '<S268>/EEReadCtl' */
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
  EEReadCtl_SysPwrMode = AppSwcBcm_ARID_DEF.data1[22];
  EEReadCtl_StartReq = AppSwcBcm_ARID_DEF.data1[23];
  for (i = 0U; i < 10; i++) {
    EEReadCtl_DoorOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 29];
    EEReadCtl_LocalStartFailOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 39];
    EEReadCtl_RemoteStartFailRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 49];
    EEReadCtl_TrunkOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 59];
  }

  /* End of Chart: '<S268>/EEReadCtl' */
}

/*
 * System initialize for function-call system:
 *    '<S325>/Lib_RiseEdgeDetInit'
 *    '<S333>/Lib_RiseEdgeDetInit'
 *    '<S339>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S327>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S325>/Lib_RiseEdgeDetInit'
 *    '<S333>/Lib_RiseEdgeDetInit'
 *    '<S339>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S327>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S327>/Logical Operator' incorporates:
   *  Delay: '<S327>/Delay'
   *  Logic: '<S327>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S327>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S319>/Lib_EdgeChgDet'
 *    '<S764>/Pri5.AntiLckFunc.Lib_EdgeChgDet'
 *    '<S764>/Pri5.SeekFunc.Lib_EdgeChgDet'
 *    '<S764>/Pri5.ArmedFunc.Lib_EdgeChgDet'
 *    '<S764>/Pri5.PartArmedFunc.Lib_EdgeChgDet'
 *    '<S764>/Pri5.DisarmedFunc.Lib_EdgeChgDet'
 *    '<S850>/Lib_EdgeChgDet'
 */
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S337>/Lib_EdgeChgDet' */
  /* RelationalOperator: '<S338>/Relational Operator' incorporates:
   *  UnitDelay: '<S338>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn != AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S338>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* End of Outputs for SubSystem: '<S337>/Lib_EdgeChgDet' */
}

/*
 * System initialize for atomic system:
 *    '<S348>/Lib_RiseEdgeDetInit'
 *    '<S773>/Lib_RiseEdgeDetInit'
 *    '<S777>/Lib_RiseEdgeDetInit'
 *    '<S780>/Lib_RiseEdgeDetInit'
 *    '<S781>/Lib_RiseEdgeDetInit'
 *    '<S791>/Lib_RiseEdgeDetInit'
 *    '<S819>/Lib_RiseEdgeDetInit'
 *    '<S854>/Lib_RiseEdgeDetInit'
 *    '<S855>/Lib_RiseEdgeDetInit'
 *    '<S856>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_d_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S349>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S348>/Lib_RiseEdgeDetInit'
 *    '<S773>/Lib_RiseEdgeDetInit'
 *    '<S777>/Lib_RiseEdgeDetInit'
 *    '<S780>/Lib_RiseEdgeDetInit'
 *    '<S781>/Lib_RiseEdgeDetInit'
 *    '<S791>/Lib_RiseEdgeDetInit'
 *    '<S819>/Lib_RiseEdgeDetInit'
 *    '<S854>/Lib_RiseEdgeDetInit'
 *    '<S855>/Lib_RiseEdgeDetInit'
 *    '<S856>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S349>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S349>/Logical Operator' incorporates:
   *  Delay: '<S349>/Delay'
   *  Logic: '<S349>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S349>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S347>/Lib_RiseEdgeDetInit'
 *    '<S772>/Lib_RiseEdgeDetInit'
 *    '<S776>/Lib_RiseEdgeDetInit'
 *    '<S790>/Lib_RiseEdgeDetInit'
 *    '<S818>/Lib_RiseEdgeDetInit'
 *    '<S853>/Lib_RiseEdgeDetInit'
 *    '<S853>/Lib_RiseEdgeDetInit1'
 *    '<S853>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_n_T *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S348>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S348>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S347>/Lib_RiseEdgeDetInit'
 *    '<S772>/Lib_RiseEdgeDetInit'
 *    '<S776>/Lib_RiseEdgeDetInit'
 *    '<S790>/Lib_RiseEdgeDetInit'
 *    '<S818>/Lib_RiseEdgeDetInit'
 *    '<S853>/Lib_RiseEdgeDetInit'
 *    '<S853>/Lib_RiseEdgeDetInit1'
 *    '<S853>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_n_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S348>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_e(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S348>/Lib_RiseEdgeDetInit' */
}

/* System initialize for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S317>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_my = true;

  /* SystemInitialize for Chart: '<S314>/Alarm' incorporates:
   *  SubSystem: '<S325>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

  /* SystemInitialize for Chart: '<S316>/Armed' incorporates:
   *  SubSystem: '<S333>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p4);

  /* SystemInitialize for Chart: '<S321>/PartArmed' incorporates:
   *  SubSystem: '<S339>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

  /* SystemInitialize for Chart: '<S323>/Chart1' incorporates:
   *  SubSystem: '<S347>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h3);
}

/* Output and update for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl(void)
{
  uint16 rtb_HornCtl_DemCnt;
  uint16 rtb_HornCtl_Prd;
  uint16 rtb_HornCtl_Wtd;
  uint8 rtb_HornCtl_Sta;
  boolean aVarTruthTableCondition_4;
  boolean aVarTruthTableCondition_5;
  boolean guard1 = false;
  boolean rtb_RelationalOperator_f;
  boolean tmp;

  /* Chart: '<S318>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S318>/Constant'
   *  Constant: '<S318>/Constant37'
   *  Constant: '<S318>/Constant38'
   *  Constant: '<S318>/Constant39'
   *  RelationalOperator: '<S318>/Relational Operator'
   */
  if (BSW_J319HornSw == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ojr >= (float32)HornCtl_HornSwTimValid_C /
         (HornCtl_Ts_C * 100.0F)) && (HornCtl_HornSwTimValid_C != 0xFFFF)) {
      HornCtl_HornSwCtl = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ojr++;
      AppSwcBcm_ARID_DEF.cnt_heal_l4 = (uint16)((float32)
        HornCtl_HornSwTimInvalid_C / (HornCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ojr = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_l4 == 0) {
      HornCtl_HornSwCtl = false;
    } else if (HornCtl_HornSwTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_l4--;
    }
  }

  /* End of Chart: '<S318>/LIB_TPD_10ms' */

  /* Chart: '<S314>/Alarm' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AlarmSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AlarmSta = 1U;
    AppSwcBcm_ARID_DEF.Lib_blIn_mu =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 2);

    /* Outputs for Function Call SubSystem: '<S325>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_mu,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ay,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

    /* End of Outputs for SubSystem: '<S325>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ay || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AlarmSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AlarmSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_mu =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S325>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_mu,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ay,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

    /* End of Outputs for SubSystem: '<S325>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ay) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_AlarmSta = 1U;
    }
  }

  /* End of Chart: '<S314>/Alarm' */

  /* RelationalOperator: '<S317>/Relational Operator' incorporates:
   *  Constant: '<S317>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S317>/Relational Operator1'
   */
  rtb_RelationalOperator_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S317>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_my) {
    /* Switch: '<S317>/Switch' incorporates:
     *  Constant: '<S317>/Constant'
     *  Constant: '<S317>/Constant5'
     *  RelationalOperator: '<S317>/Relational Operator'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_i = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_i =
        AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts;
    }

    /* End of Switch: '<S317>/Switch' */
  }

  /* Switch: '<S317>/Switch1' incorporates:
   *  Constant: '<S317>/Constant7'
   */
  if (rtb_RelationalOperator_f) {
    rtb_HornCtl_Sta = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HULckHornOnSt_enum;
  } else {
    rtb_HornCtl_Sta = 0U;
  }

  /* MultiPortSwitch: '<S317>/Multiport Switch' incorporates:
   *  Switch: '<S317>/Switch1'
   */
  switch (rtb_HornCtl_Sta) {
   case 1:
    /* MultiPortSwitch: '<S317>/Multiport Switch' incorporates:
     *  Constant: '<S317>/Constant1'
     */
    HornCtl_LockHoornOnSt = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S317>/Multiport Switch' incorporates:
     *  Constant: '<S317>/Constant2'
     */
    HornCtl_LockHoornOnSt = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S317>/Multiport Switch' incorporates:
     *  Delay: '<S317>/Delay'
     */
    HornCtl_LockHoornOnSt = AppSwcBcm_ARID_DEF.Delay_DSTATE_i;
    break;
  }

  /* End of MultiPortSwitch: '<S317>/Multiport Switch' */

  /* MultiPortSwitch: '<S317>/Multiport Switch1' */
  switch (HornCtl_LockHoornOnSt) {
   case 1:
    /* MultiPortSwitch: '<S317>/Multiport Switch1' incorporates:
     *  Constant: '<S317>/Constant3'
     */
    HornCtl_LockHoornOnStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S317>/Multiport Switch1' incorporates:
     *  Constant: '<S317>/Constant4'
     */
    HornCtl_LockHoornOnStFb = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S317>/Multiport Switch1' */

  /* Chart: '<S315>/AntiLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S269>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AntiLckSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AntiLckSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p >= 3) || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AntiLckSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AntiLckSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_pd =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck;

    /* Outputs for Function Call SubSystem: '<S328>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_pd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jk,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jd);

    /* End of Outputs for SubSystem: '<S328>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jk) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_nk =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck;

      /* Outputs for Function Call SubSystem: '<S328>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_nk,
        &AppSwcBcm_ARID_DEF.LogicalOperator_f0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_a);

      /* End of Outputs for SubSystem: '<S328>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_f0) {
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

  /* End of Chart: '<S315>/AntiLck' */

  /* Chart: '<S316>/Armed' incorporates:
   *  UnitDelay: '<S269>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_ArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_ArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p >= 1) ||
        (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) || HornCtl_HornSwCtl)
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_ArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_ArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_nt =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S333>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_nt,
      &AppSwcBcm_ARID_DEF.LogicalOperator_cw,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p4);

    /* End of Outputs for SubSystem: '<S333>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_cw && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_ArmedSta = 1U;
    }
  }

  /* End of Chart: '<S316>/Armed' */

  /* Chart: '<S321>/PartArmed' incorporates:
   *  UnitDelay: '<S269>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_PartArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_PartArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p >= 3) ||
        (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) || HornCtl_HornSwCtl)
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_PartArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_PartArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_bp =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3);

    /* Outputs for Function Call SubSystem: '<S339>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_bp,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fp,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

    /* End of Outputs for SubSystem: '<S339>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fp && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_PartArmedSta = 1U;
    }
  }

  /* End of Chart: '<S321>/PartArmed' */

  /* Chart: '<S322>/Seek' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S269>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_SeekSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib) {
     case AppSwcBcm_IN_RKESetON:
      HornCtl_SeekSta = 1U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta == 0) ||
          (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p >= 1) || HornCtl_HornSwCtl) {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_SeekSta = 0U;
      }
      break;

     case AppSwcBcm_IN_SetOff:
      HornCtl_SeekSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_f1 =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta == 1);

      /* Outputs for Function Call SubSystem: '<S342>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_f1,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ek,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_k);

      /* End of Outputs for SubSystem: '<S342>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ek && (HornCtl_LockHoornOnStFb == 1))
      {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_RKESetON;
        HornCtl_SeekSta = 1U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_nx =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta == 2);

        /* Outputs for Function Call SubSystem: '<S342>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_nx,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ev,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

        /* End of Outputs for SubSystem: '<S342>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ev &&
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
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta == 0) ||
          (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p >= 1) || HornCtl_HornSwCtl) {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_SeekSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S322>/Seek' */

  /* Chart: '<S323>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S269>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_HornCtl_Lib = AppSwcBcm_IN_SetOff_i;
    HornCtl_TrunkWarnSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c1_HornCtl_Lib == AppSwcBcm_IN_SetOff_i) {
    HornCtl_TrunkWarnSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_bf =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TrunkWarnSta;

    /* Outputs for Function Call SubSystem: '<S347>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_bf,
      &AppSwcBcm_ARID_DEF.LogicalOperator_bd,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h3);

    /* End of Outputs for SubSystem: '<S347>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_bd && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c1_HornCtl_Lib = AppSwcBcm_IN_SetOn;
      HornCtl_TrunkWarnSta = 1U;
    }
  } else {
    /* case IN_SetOn: */
    HornCtl_TrunkWarnSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p >= 3) ||
        (!(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TrunkWarnSta)) {
      AppSwcBcm_ARID_DEF.is_c1_HornCtl_Lib = AppSwcBcm_IN_SetOff_i;
      HornCtl_TrunkWarnSta = 0U;
    }
  }

  /* End of Chart: '<S323>/Chart1' */

  /* Truth Table: '<S269>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  rtb_RelationalOperator_f = (HornCtl_PartArmedSta == 1);

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
    tmp = !aVarTruthTableCondition_4;
    if (rtb_RelationalOperator_f && tmp) {
      /*  Example action 2 called from D3 column in condition table */
      rtb_HornCtl_DemCnt = 3U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 2U;
    } else if ((!rtb_RelationalOperator_f) && (HornCtl_ArmedSta == 1) && tmp) {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 3U;
    } else if (aVarTruthTableCondition_4) {
      rtb_HornCtl_DemCnt = MAX_uint16_T;
      rtb_HornCtl_Prd = 40U;
      rtb_HornCtl_Wtd = 20U;
      rtb_HornCtl_Sta = 4U;
    } else if (tmp && aVarTruthTableCondition_5) {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 6U;
    } else if (tmp && (!aVarTruthTableCondition_5) && (HornCtl_SeekSta == 2)) {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 9U;
    } else if (tmp && (HornCtl_AntiLckSta == 1)) {
      rtb_HornCtl_DemCnt = 3U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 7U;
    } else if (tmp && (HornCtl_TrunkWarnSta == 1)) {
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

  /* End of Truth Table: '<S269>/Truth Table' */

  /* RelationalOperator: '<S269>/Relational Operator' incorporates:
   *  UnitDelay: '<S269>/Unit Delay4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_gg = (rtb_HornCtl_Sta !=
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_l);

  /* Chart: '<S269>/LIB_Pulse' incorporates:
   *  SubSystem: '<S319>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_gg,
    &AppSwcBcm_ARID_DEF.RelationalOperator_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet_p);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_d) {
    AppSwcBcm_ARID_DEF.cnt_a = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p = 0U;
  }

  if (rtb_HornCtl_DemCnt >= 1) {
    if (rtb_HornCtl_DemCnt >= 65535) {
      AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_b = (AppSwcBcm_ARID_DEF.cnt_a <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_a >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_a = 0U;
      } else {
        AppSwcBcm_ARID_DEF.cnt_a++;
      }
    } else if (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p < rtb_HornCtl_DemCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_b = (AppSwcBcm_ARID_DEF.cnt_a <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_a >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_a = 0U;
        AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p++;
      } else {
        AppSwcBcm_ARID_DEF.cnt_a++;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_b = false;
    AppSwcBcm_ARID_DEF.cnt_a = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_p = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S269>/Ovrd1' */
  /* Switch: '<S320>/Switch1' incorporates:
   *  Constant: '<S269>/Constant18'
   */
  if (HornCtl_J430HornDrvOvrdFlg_C) {
    /* Switch: '<S320>/Switch1' incorporates:
     *  Constant: '<S269>/Constant19'
     */
    HornCtl_J430HornDrv = HornCtl_J430HornDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S269>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->HornCtlFlg != 0);

    /* Switch: '<S320>/Switch2' */
    if (rtb_RelationalOperator_f) {
      /* Switch: '<S320>/Switch1' incorporates:
       *  Switch: '<S320>/Switch2'
       */
      HornCtl_J430HornDrv = true;
    } else {
      /* Switch: '<S320>/Switch1' incorporates:
       *  Constant: '<S269>/Constant'
       *  RelationalOperator: '<S269>/Relational Operator1'
       *  Switch: '<S269>/Switch'
       *  Switch: '<S320>/Switch2'
       */
      HornCtl_J430HornDrv =
        ((AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum != 1) &&
         AppSwcBcm_ARID_DEF.LIB_blOut_b);
    }

    /* End of Switch: '<S320>/Switch2' */
  }

  /* End of Switch: '<S320>/Switch1' */
  /* End of Outputs for SubSystem: '<S269>/Ovrd1' */

  /* Update for Delay: '<S317>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_my = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_i = HornCtl_LockHoornOnSt;

  /* Update for UnitDelay: '<S269>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_l = rtb_HornCtl_Sta;
}

/*
 * System initialize for atomic system:
 *    '<S350>/LIB_TPD1'
 *    '<S350>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg)
{
  *rty_LIB_u8ErrFlg = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S350>/LIB_TPD1'
 *    '<S350>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg)
{
  boolean guard1 = false;

  /* Chart: '<S350>/LIB_TPD1' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blAllowRecov;

  /* Outputs for Function Call SubSystem: '<S363>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator_n,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S363>/Lib_RiseEdgeDet' */

  /* Chart: '<S350>/LIB_TPD1' */
  guard1 = false;
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator_n) {
    guard1 = true;
  } else {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn_k = rtu_LIB_blAllowRecov1;

    /* Outputs for Function Call SubSystem: '<S363>/Lib_RiseEdgeDet1' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn_k,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet1);

    /* End of Outputs for SubSystem: '<S363>/Lib_RiseEdgeDet1' */
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

/* System initialize for atomic system: '<S270>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt_Init(void)
{
  /* SystemInitialize for Chart: '<S350>/LIB_TPD1' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_n);

  /* SystemInitialize for Chart: '<S350>/LIB_TPD2' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg);
}

/* Output and update for atomic system: '<S270>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator3_h;

  /* Logic: '<S350>/Logical Operator' incorporates:
   *  UnitDelay: '<S270>/Unit Delay'
   *  UnitDelay: '<S270>/Unit Delay1'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_br ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ao);

  /* RelationalOperator: '<S350>/Relational Operator3' incorporates:
   *  Constant: '<S350>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_h = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S350>/LIB_TPD2' incorporates:
   *  Constant: '<S350>/Constant1'
   *  Constant: '<S350>/Constant2'
   *  Logic: '<S350>/Logical Operator1'
   *  RelationalOperator: '<S350>/Relational Operator'
   *  RelationalOperator: '<S350>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(rtb_LogicalOperator && (!WiperCtl_WiperParkPosSw),
                     WiperCtl_LockedRotorTimDef_C, WiperCtl_LockedRotorTimOk_C,
                     WiperCtl_WiperOffSw, rtb_RelationalOperator3_h,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD2);

  /* Chart: '<S350>/LIB_TPD1' incorporates:
   *  Constant: '<S350>/Constant4'
   *  Constant: '<S350>/Constant5'
   *  Logic: '<S350>/Logical Operator3'
   *  RelationalOperator: '<S350>/Relational Operator1'
   *  RelationalOperator: '<S350>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(WiperCtl_WiperParkPosSw && rtb_LogicalOperator,
                     WiperCtl_LockedRotorTimParkDef_C,
                     WiperCtl_LockedRotorTimParkOk_C, WiperCtl_WiperOffSw,
                     rtb_RelationalOperator3_h,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_n,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD1);

  /* Logic: '<S350>/Logical Operator2' */
  WiperCtl_LockedRotorProtSta = ((AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_n != 0) ||
    (AppSwcBcm_ARID_DEF.LIB_u8ErrFlg != 0));
}

/*
 * Output and update for atomic system:
 *    '<S354>/Bit Shift1'
 *    '<S446>/Bit Shift1'
 *    '<S653>/Bit Shift4'
 */
static uint16 AppSwcBcm_BitShift1_k(uint16 rtu_u)
{
  /* MATLAB Function: '<S373>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S354>/Bit Shift2'
 *    '<S446>/Bit Shift2'
 *    '<S653>/Bit Shift7'
 */
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u)
{
  /* MATLAB Function: '<S374>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 2);
}

/* Output and update for atomic system: '<S270>/SignalProcess' */
static void AppSwcBcm_SignalProcess(void)
{
  uint16 rtb_y;
  uint8 rtb_Switch5_k;
  boolean rtb_Switch1_ke;

  /* Outputs for Atomic SubSystem: '<S354>/Bit Shift5' */
  /* Constant: '<S354>/Constant59' */
  rtb_y = AppSwcBcm_BitShift3(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S354>/Bit Shift5' */

  /* Switch: '<S354>/Switch5' incorporates:
   *  RelationalOperator: '<S354>/Relational Operator'
   *  S-Function (sfix_bitop): '<S354>/Bitwise AND5'
   *  Switch: '<S354>/Switch'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S354>/Switch5' incorporates:
     *  Constant: '<S354>/Constant60'
     */
    rtb_Switch5_k = WiperCtl_WiperSwVal_C;
  } else if (SCS_WiprSwtStVD) {
    /* Switch: '<S354>/Switch' incorporates:
     *  Switch: '<S354>/Switch5'
     */
    rtb_Switch5_k = SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S354>/Switch5' incorporates:
     *  Constant: '<S354>/Constant23'
     *  Switch: '<S354>/Switch'
     */
    rtb_Switch5_k = 0U;
  }

  /* End of Switch: '<S354>/Switch5' */

  /* Chart: '<S354>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S354>/Constant14'
   *  Constant: '<S354>/Constant46'
   *  Constant: '<S354>/Constant47'
   *  Constant: '<S354>/Constant49'
   *  RelationalOperator: '<S354>/Relational Operator9'
   */
  if (rtb_Switch5_k == 4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fz >= (float32)WiperCtl_MistTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_MistTimValid_C != 0xFFFF)) {
      WiperCtl_WiperMistSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fz++;
      AppSwcBcm_ARID_DEF.cnt_heal_db = (uint16)((float32)
        WiperCtl_MistTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fz = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_db == 0) {
      WiperCtl_WiperMistSw = false;
    } else if (WiperCtl_MistTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_db--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms' */

  /* Chart: '<S354>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S354>/Constant1'
   *  Constant: '<S354>/Constant3'
   *  Constant: '<S354>/Constant4'
   *  Constant: '<S354>/Constant5'
   *  RelationalOperator: '<S354>/Relational Operator1'
   */
  if (rtb_Switch5_k == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d4 >= (float32)WiperCtl_OffTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_OffTimValid_C != 0xFFFF)) {
      WiperCtl_WiperOffSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d4++;
      AppSwcBcm_ARID_DEF.cnt_heal_a4 = (uint16)((float32)
        WiperCtl_OffTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d4 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a4 == 0) {
      WiperCtl_WiperOffSw = false;
    } else if (WiperCtl_OffTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a4--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms1' */

  /* Chart: '<S354>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S354>/Constant10'
   *  Constant: '<S354>/Constant2'
   *  Constant: '<S354>/Constant8'
   *  Constant: '<S354>/Constant9'
   *  RelationalOperator: '<S354>/Relational Operator2'
   */
  if (rtb_Switch5_k == 1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b2 >= (float32)WiperCtl_InrTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_InrTimValid_C != 0xFFFF)) {
      WiperCtl_WiperInrSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b2++;
      AppSwcBcm_ARID_DEF.cnt_heal_pf = (uint16)((float32)
        WiperCtl_InrTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pf == 0) {
      WiperCtl_WiperInrSw = false;
    } else if (WiperCtl_InrTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pf--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms2' */

  /* Chart: '<S354>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S354>/Constant11'
   *  Constant: '<S354>/Constant16'
   *  Constant: '<S354>/Constant17'
   *  Constant: '<S354>/Constant6'
   *  RelationalOperator: '<S354>/Relational Operator3'
   */
  if (rtb_Switch5_k == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ntv >= (float32)WiperCtl_LowSpdTimValid_C
         / (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_LowSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperLowSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ntv++;
      AppSwcBcm_ARID_DEF.cnt_heal_d = (uint16)((float32)
        WiperCtl_LowSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ntv = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d == 0) {
      WiperCtl_WiperLowSpdSw = false;
    } else if (WiperCtl_LowSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_d--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms3' */

  /* Chart: '<S354>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S354>/Constant18'
   *  Constant: '<S354>/Constant21'
   *  Constant: '<S354>/Constant22'
   *  Constant: '<S354>/Constant7'
   *  RelationalOperator: '<S354>/Relational Operator4'
   */
  if (rtb_Switch5_k == 3) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lt >= (float32)WiperCtl_HiSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_HiSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperHiSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lt++;
      AppSwcBcm_ARID_DEF.cnt_heal_k = (uint16)((float32)
        WiperCtl_HiSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lt = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k == 0) {
      WiperCtl_WiperHiSpdSw = false;
    } else if (WiperCtl_HiSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S354>/Bit Shift1' */
  /* Constant: '<S354>/Constant28' */
  rtb_y = AppSwcBcm_BitShift1_k(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S354>/Bit Shift1' */

  /* Switch: '<S354>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S354>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S354>/Switch1' incorporates:
     *  Constant: '<S354>/Constant29'
     */
    rtb_Switch1_ke = WiperCtl_WashVal_C;
  } else {
    /* Switch: '<S354>/Switch1' incorporates:
     *  RelationalOperator: '<S354>/Relational Operator5'
     *  Switch: '<S354>/Switch3'
     */
    rtb_Switch1_ke = (SCS_FrntWshrSwtStVD && SCS_FrntWshrSwtSt);
  }

  /* End of Switch: '<S354>/Switch1' */

  /* Chart: '<S354>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S354>/Constant25'
   *  Constant: '<S354>/Constant26'
   *  Constant: '<S354>/Constant27'
   */
  if (rtb_Switch1_ke) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l2 >= (float32)WiperCtl_WashTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashTimValid_C != 0xFFFF)) {
      WiperCtl_WashSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l2++;
      AppSwcBcm_ARID_DEF.cnt_heal_oj = (uint16)((float32)
        WiperCtl_WashTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_oj == 0) {
      WiperCtl_WashSw = false;
    } else if (WiperCtl_WashTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_oj--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S354>/Bit Shift2' */
  /* Constant: '<S354>/Constant35' */
  rtb_y = AppSwcBcm_BitShift2(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S354>/Bit Shift2' */

  /* Switch: '<S354>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S354>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S354>/Switch2' incorporates:
     *  Constant: '<S354>/Constant36'
     */
    rtb_Switch1_ke = WiperCtl_WiperParkPosVal_C;
  } else {
    /* Switch: '<S354>/Switch2' incorporates:
     *  DataTypeConversion: '<S354>/Data Type Conversion2'
     */
    rtb_Switch1_ke = (BSW_J334WiperParkPos != 0);
  }

  /* End of Switch: '<S354>/Switch2' */

  /* Chart: '<S354>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S354>/Constant32'
   *  Constant: '<S354>/Constant33'
   *  Constant: '<S354>/Constant34'
   *  Logic: '<S354>/Logical Operator5'
   */
  if (!rtb_Switch1_ke) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_cw >= (float32)
         WiperCtl_WiperParkPosTimValid_C / (WiperCtl_Ts_C * 100.0F)) &&
        (WiperCtl_WiperParkPosTimValid_C != 0xFFFF)) {
      WiperCtl_WiperParkPosSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_cw++;
      AppSwcBcm_ARID_DEF.cnt_heal_pp = (uint16)((float32)
        WiperCtl_WiperPosTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_cw = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pp == 0) {
      WiperCtl_WiperParkPosSw = false;
    } else if (WiperCtl_WiperPosTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pp--;
    }
  }

  /* End of Chart: '<S354>/LIB_TPD_10ms6' */
}

/* System initialize for atomic system: '<S270>/WashCtl' */
static void AppSwcBcm_WashCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S355>/LIB_Tim' */
  AppSwcBcm_LIB_NegPluse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_hy);
}

/* Output and update for atomic system: '<S270>/WashCtl' */
static void AppSwcBcm_WashCtl(void)
{
  boolean rtb_RelationalOperator1_ft;

  /* RelationalOperator: '<S355>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_ft = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Chart: '<S355>/LIB_Tim' incorporates:
   *  Constant: '<S355>/Constant'
   *  Logic: '<S355>/Logical Operator'
   *  RelationalOperator: '<S355>/Relational Operator'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator1_ft && WiperCtl_WashSw,
    WiperCtl_WashMaxTim_C, &AppSwcBcm_ARID_DEF.LIB_blOut_hy,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_m);

  /* Chart: '<S355>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S355>/Constant3'
   *  Constant: '<S355>/Constant34'
   *  Constant: '<S355>/Constant4'
   *  Logic: '<S355>/Logical Operator1'
   *  Logic: '<S355>/Logical Operator2'
   *  RelationalOperator: '<S355>/Relational Operator2'
   *  RelationalOperator: '<S355>/Relational Operator3'
   *  RelationalOperator: '<S355>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_hy && (WiperCtl_WiperInrSta ||
       WiperCtl_WiperOffSta) && (!AppSwcBcm_ARID_DEF.UnitDelay8_db)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fo >= (float32)WiperCtl_WashMinTim_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashMinTim_C != 0xFFFF)) {
      WiperCtl_WashWiperSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fo++;
      AppSwcBcm_ARID_DEF.cnt_heal_gw = (uint16)(1.0F / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fo = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gw == 0) {
      WiperCtl_WashWiperSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_gw--;
    }
  }

  /* End of Chart: '<S355>/LIB_TPD_10ms6' */
}

/*
 * Output and update for function-call system:
 *    '<S388>/Nrm.Off.Lib_RiseEdgeDet'
 *    '<S388>/Wash.Lib_RiseEdgeDet'
 *    '<S441>/Lib_RiseEdgeDet'
 *    '<S496>/Lib_RiseEdgeDet'
 *    '<S504>/Lib_RiseEdgeDet'
 *    '<S521>/Lib_RiseEdgeDet'
 *    '<S585>/Lib_RiseEdgeDet'
 *    '<S589>/Lib_RiseEdgeDet'
 *    '<S593>/Lib_RiseEdgeDet'
 *    '<S597>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_NrmOffLib_RiseEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_NrmOffLib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S395>/Logical Operator' incorporates:
   *  Logic: '<S395>/Logical Operator1'
   *  UnitDelay: '<S395>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S395>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S388>/Wash.Lib_RiseEdgeDetInit'
 *    '<S388>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S397>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S388>/Wash.Lib_RiseEdgeDetInit'
 *    '<S388>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S397>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S397>/Logical Operator' incorporates:
   *  Delay: '<S397>/Delay'
   *  Logic: '<S397>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S397>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S356>/Chart' */
static void AppSwcBcm_enter_internal_Off(void)
{
  sint32 tmp;
  WiperCtl_WiperSta = 0U;
  AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
  AppSwcBcm_ARID_DEF.Lib_blIn_ms =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

  /* Outputs for Function Call SubSystem: '<S388>/Nrm.Off.Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ms,
    &AppSwcBcm_ARID_DEF.LogicalOperator_fz,
    &AppSwcBcm_ARID_DEF.ARID_DEF_NrmOffLib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S388>/Nrm.Off.Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_fz) {
    AppSwcBcm_ARID_DEF.Flg_n = true;
    AppSwcBcm_ARID_DEF.Cnt_oj = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_n) {
    /* UnitDelay: '<S270>/Unit Delay2' */
    if ((AppSwcBcm_ARID_DEF.Cnt_oj >= WiperCtl_WiperReturnDelayTim_C) &&
        (!WiperCtl_WiperParkPosSw) && (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf))
    {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
    } else if ((AppSwcBcm_ARID_DEF.Cnt_oj >= WiperCtl_WiperReturnDelayTim_C) &&
               (WiperCtl_WiperParkPosSw ||
                AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf)) {
      AppSwcBcm_ARID_DEF.Flg_n = false;
      AppSwcBcm_ARID_DEF.Cnt_oj = 0U;
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_oj + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_oj + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_oj = (uint16)tmp;
    }

    /* End of UnitDelay: '<S270>/Unit Delay2' */
  } else {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
  }
}

/* Function for Chart: '<S356>/Chart' */
static void AppSwcBcm_enter_internal_Inr(void)
{
  WiperCtl_WiperSta = 4U;
  AppSwcBcm_ARID_DEF.cnt_k = 0U;
  if (WiperCtl_WiperInrSta) {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
    if ((WiperCtl_InrTim + AppSwcBcm_ARID_DEF.cnt2) - 1 > 0) {
      AppSwcBcm_ARID_DEF.cnt_k = 1U;
    }
  }
}

/* Function for Chart: '<S356>/Chart' */
static void AppSwcBcm_HiSpdFunc(void)
{
  AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
  AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = true;
  WiperCtl_WiperSta = 3U;
}

/* Function for Chart: '<S356>/Chart' */
static void AppSwcBcm_Nrm(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator1_f4n;
  if (WiperCtl_WashWiperSta) {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_Inr:
      AppSwcBcm_ARID_DEF.cnt_k = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     case AppSwcBcm_IN_Off_go:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     default:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;
    }

    AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Wash;
    WiperCtl_WiperSta = 5U;
    AppSwcBcm_ARID_DEF.after_cnt = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
    AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
    if (WiperCtl_WiperMistSta || WiperCtl_WiperHiSpdSta ||
        WiperCtl_WiperLowSpdSta) {
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_oo = WiperCtl_WiperInrSta;
      AppSwcBcm_ARID_DEF.Lib_blInit_n = WiperCtl_WiperInrSta;

      /* Outputs for Function Call SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_oo,
        AppSwcBcm_ARID_DEF.Lib_blInit_n, &AppSwcBcm_ARID_DEF.LogicalOperator_eo,
        &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
        AppSwcBcm_ARID_DEF.LogicalOperator_eo;
    }
  } else if (WiperCtl_WiperMaintSta) {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_Inr:
      AppSwcBcm_ARID_DEF.cnt_k = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     case AppSwcBcm_IN_Off_go:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     default:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;
    }

    AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Maint;
    WiperCtl_WiperSta = 6U;
    AppSwcBcm_ARID_DEF.Cnt_oj = 0U;
    if (WiperCtl_MaintWiperRunTim_C <= 0) {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;

      /* WiperCtl_MaintStaComp=1; */
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
      AppSwcBcm_ARID_DEF.Cnt_oj = 1U;

      /* WiperCtl_MaintStaComp=0; */
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_HiSpd:
      if (WiperCtl_WiperLowSpdSta || (!WiperCtl_WiperHiSpdSta) ||
          WiperCtl_WiperOffSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;

        /* UnitDelay: '<S270>/Unit Delay2' */
        /* (WiperCtl_WiperHiSpdSta==0||WiperCtl_WiperOffSta==1)&&WiperCtl_WiperParkPosSta==1||... */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
        AppSwcBcm_enter_internal_Off();
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
        AppSwcBcm_ARID_DEF.cnt_k = 0U;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if ((WiperCtl_WiperOffSta && WiperCtl_WiperParkPosSw) ||
                 AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf) {
        AppSwcBcm_ARID_DEF.cnt_k = 0U;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
        AppSwcBcm_enter_internal_Off();
      } else {
        rtb_LogicalOperator1_f4n = !WiperCtl_WiperInrSta;
        if (WiperCtl_WiperHiSpdSta && rtb_LogicalOperator1_f4n) {
          AppSwcBcm_ARID_DEF.cnt_k = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
        } else if (rtb_LogicalOperator1_f4n && WiperCtl_WiperLowSpdSta) {
          AppSwcBcm_ARID_DEF.cnt_k = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
        } else {
          if (WiperCtl_InrTimChg) {
            AppSwcBcm_ARID_DEF.cnt_k = 0U;
          }

          if (WiperCtl_WiperInrSta) {
            if (AppSwcBcm_ARID_DEF.cnt_k == 0) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
              AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
            } else {
              /* Outputs for Function Call SubSystem: '<S388>/Nrm.Inr.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.icLoad_lt) {
                /* Delay: '<S394>/Delay' */
                AppSwcBcm_ARID_DEF.Delay_DSTATE_bw = WiperCtl_WiperParkPosSw;
              }

              /* Logic: '<S394>/Logical Operator1' incorporates:
               *  Delay: '<S394>/Delay'
               */
              rtb_LogicalOperator1_f4n = !AppSwcBcm_ARID_DEF.Delay_DSTATE_bw;

              /* Update for Delay: '<S394>/Delay' */
              AppSwcBcm_ARID_DEF.icLoad_lt = false;
              AppSwcBcm_ARID_DEF.Delay_DSTATE_bw = WiperCtl_WiperParkPosSw;

              /* Logic: '<S394>/Logical Operator' */
              if (WiperCtl_WiperParkPosSw && rtb_LogicalOperator1_f4n &&
                  (AppSwcBcm_ARID_DEF.cnt_k > 10)) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
                AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
                AppSwcBcm_ARID_DEF.cnt2 = AppSwcBcm_ARID_DEF.cnt_k;
              }

              /* End of Logic: '<S394>/Logical Operator' */
              /* End of Outputs for SubSystem: '<S388>/Nrm.Inr.Lib_RiseEdgeDetInit' */
            }

            if (AppSwcBcm_ARID_DEF.cnt_k >= (WiperCtl_InrTim +
                 AppSwcBcm_ARID_DEF.cnt2) - 1) {
              AppSwcBcm_ARID_DEF.cnt_k = 0U;
            } else {
              tmp = AppSwcBcm_ARID_DEF.cnt_k + 1;
              if (AppSwcBcm_ARID_DEF.cnt_k + 1 > 65535) {
                tmp = 65535;
              }

              AppSwcBcm_ARID_DEF.cnt_k = (uint16)tmp;
            }
          }
        }
      }
      break;

     case AppSwcBcm_IN_LowSpd:
      /* UnitDelay: '<S270>/Unit Delay2' */
      if ((WiperCtl_WiperOffSta && WiperCtl_WiperParkPosSw) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
        AppSwcBcm_enter_internal_Off();
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
        WiperCtl_WiperSta = 2U;

        /* ex:WiperCtl_LowSpdDrv=0; */
      }
      break;

     case AppSwcBcm_IN_Mist:
      if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else if ((WiperCtl_WiperOffSta && WiperCtl_WiperParkPosSw) ||
                 AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
        AppSwcBcm_enter_internal_Off();
      } else if (WiperCtl_WiperLowSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
        WiperCtl_WiperSta = 1U;

        /* ex:WiperCtl_LowSpdDrv=0; */
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
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ms =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

        /* Outputs for Function Call SubSystem: '<S388>/Nrm.Off.Lib_RiseEdgeDet' */
        AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ms,
          &AppSwcBcm_ARID_DEF.LogicalOperator_fz,
          &AppSwcBcm_ARID_DEF.ARID_DEF_NrmOffLib_RiseEdgeDet);

        /* End of Outputs for SubSystem: '<S388>/Nrm.Off.Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_fz) {
          AppSwcBcm_ARID_DEF.Flg_n = true;
          AppSwcBcm_ARID_DEF.Cnt_oj = 0U;
        }

        if (AppSwcBcm_ARID_DEF.Flg_n) {
          /* UnitDelay: '<S270>/Unit Delay2' */
          if ((AppSwcBcm_ARID_DEF.Cnt_oj >= WiperCtl_WiperReturnDelayTim_C) && (
               !WiperCtl_WiperParkPosSw) &&
              (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf)) {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
          } else if ((AppSwcBcm_ARID_DEF.Cnt_oj >=
                      WiperCtl_WiperReturnDelayTim_C) &&
                     (WiperCtl_WiperParkPosSw ||
                      AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf)) {
            AppSwcBcm_ARID_DEF.Flg_n = false;
            AppSwcBcm_ARID_DEF.Cnt_oj = 0U;
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
          } else {
            tmp = AppSwcBcm_ARID_DEF.Cnt_oj + 1;
            if (AppSwcBcm_ARID_DEF.Cnt_oj + 1 > 65535) {
              tmp = 65535;
            }

            AppSwcBcm_ARID_DEF.Cnt_oj = (uint16)tmp;
          }
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
        }
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S270>/WiperDrv' */
static void AppSwcBcm_WiperDrv_Init(void)
{
  /* SystemInitialize for Chart: '<S356>/Chart' incorporates:
   *  SubSystem: '<S388>/Nrm.Inr.Lib_RiseEdgeDetInit'
   */
  /* InitializeConditions for Delay: '<S394>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_lt = true;

  /* SystemInitialize for Chart: '<S356>/Chart' incorporates:
   *  SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S356>/Chart' incorporates:
   *  SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);
}

/* Output and update for atomic system: '<S270>/WiperDrv' */
static void AppSwcBcm_WiperDrv(void)
{
  sint32 tmp;

  /* Chart: '<S356>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S270>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_WiperCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_WiperCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Nrm;
    AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
    AppSwcBcm_enter_internal_Off();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib) {
     case AppSwcBcm_IN_Maint:
      if ((!WiperCtl_WiperMaintSta) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf)
      {
        AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Nrm;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
        AppSwcBcm_enter_internal_Off();
      } else if (AppSwcBcm_ARID_DEF.Cnt_oj >= WiperCtl_MaintWiperRunTim_C) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;

        /* WiperCtl_MaintStaComp=1; */
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
        AppSwcBcm_ARID_DEF.Cnt_oj++;

        /* WiperCtl_MaintStaComp=0; */
      }
      break;

     case AppSwcBcm_IN_Nrm:
      AppSwcBcm_Nrm();
      break;

     default:
      /* case IN_Wash: */
      if (((!WiperCtl_WashWiperSta) && AppSwcBcm_ARID_DEF.WiperCtl_WashComp) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf ||
          (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) &&
           WiperCtl_WiperParkPosSw)) {
        AppSwcBcm_ARID_DEF.is_c8_WiperCtl_Lib = AppSwcBcm_IN_Nrm;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_go;
        AppSwcBcm_enter_internal_Off();
      } else {
        if (WiperCtl_WashWiperSta) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k = false;
          AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_f5 = WiperCtl_WiperParkPosSw;

          /* Outputs for Function Call SubSystem: '<S388>/Wash.Lib_RiseEdgeDet' */
          AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_f5,
            &AppSwcBcm_ARID_DEF.LogicalOperator_gk,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDet);

          /* End of Outputs for SubSystem: '<S388>/Wash.Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_gk) {
            tmp = AppSwcBcm_ARID_DEF.last_cnt - 1;
            if (AppSwcBcm_ARID_DEF.last_cnt - 1 < 0) {
              tmp = 0;
            }

            AppSwcBcm_ARID_DEF.last_cnt = (uint8)tmp;
          }

          if (AppSwcBcm_ARID_DEF.last_cnt == 0) {
            if (WiperCtl_WiperInrSta) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
              AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
            } else {
              tmp = AppSwcBcm_ARID_DEF.after_cnt + 1;
              if (AppSwcBcm_ARID_DEF.after_cnt + 1 > 65535) {
                tmp = 65535;
              }

              AppSwcBcm_ARID_DEF.after_cnt = (uint16)tmp;
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
            }

            if (AppSwcBcm_ARID_DEF.after_cnt >= WiperCtl_WashAfterTim_C) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = true;
              AppSwcBcm_ARID_DEF.Lib_blIn_et = WiperCtl_WiperParkPosSw;
              AppSwcBcm_ARID_DEF.Lib_blInit_c = true;

              /* Outputs for Function Call SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit' */
              AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_et,
                true, &AppSwcBcm_ARID_DEF.LogicalOperator_ci5,
                &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

              /* End of Outputs for SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_ci5) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p = false;
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
          AppSwcBcm_ARID_DEF.Lib_blIn_oo = WiperCtl_WiperInrSta;
          AppSwcBcm_ARID_DEF.Lib_blInit_n = WiperCtl_WiperInrSta;

          /* Outputs for Function Call SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_oo,
            AppSwcBcm_ARID_DEF.Lib_blInit_n,
            &AppSwcBcm_ARID_DEF.LogicalOperator_eo,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

          /* End of Outputs for SubSystem: '<S388>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
            (AppSwcBcm_ARID_DEF.LogicalOperator_eo ||
             AppSwcBcm_ARID_DEF.WiperCtl_WashComp);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S356>/Chart' */
}

/* Output and update for atomic system: '<S270>/WiperHiSpdCtl' */
static void AppSwcBcm_WiperHiSpdCtl(void)
{
  boolean rtb_RelationalOperator_omg;

  /* RelationalOperator: '<S357>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_omg = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S357>/Logical Operator' incorporates:
   *  RelationalOperator: '<S357>/Relational Operator1'
   *  RelationalOperator: '<S357>/Relational Operator2'
   */
  WiperCtl_WiperHiSpdSta = (rtb_RelationalOperator_omg && WiperCtl_WiperHiSpdSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay4_h));
}

/* System initialize for atomic system: '<S270>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S358>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_f = true;

  /* InitializeConditions for Delay: '<S358>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_gt = true;
}

/* Output and update for atomic system: '<S270>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl(void)
{
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator5;

  /* RelationalOperator: '<S358>/Relational Operator5' incorporates:
   *  Constant: '<S358>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S358>/Relational Operator'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S358>/Logical Operator' incorporates:
   *  RelationalOperator: '<S358>/Relational Operator2'
   */
  WiperCtl_WiperInrSta = (rtb_RelationalOperator5 && WiperCtl_WiperInrSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay5_f));

  /* Delay: '<S358>/Delay1' */
  if (AppSwcBcm_ARID_DEF.icLoad_f) {
    /* Switch: '<S358>/Switch1' incorporates:
     *  Constant: '<S358>/Constant20'
     *  Constant: '<S358>/Constant8'
     *  RelationalOperator: '<S358>/Relational Operator4'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.InrTim == 255) {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrLvl3Tim_C;
    } else {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = AppSwcBcm_ARID_DEF.BusCreator12.InrTim;
    }

    /* End of Switch: '<S358>/Switch1' */
  }

  /* RelationalOperator: '<S358>/Relational Operator5' incorporates:
   *  Constant: '<S358>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S358>/Relational Operator3'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S358>/Switch' */
  if (rtb_RelationalOperator5) {
    /* Switch: '<S358>/Switch' */
    rtb_Switch = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUWiprIntlTmSet_enum;
  } else {
    /* Switch: '<S358>/Switch' incorporates:
     *  Constant: '<S358>/Constant19'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S358>/Switch' */

  /* MultiPortSwitch: '<S358>/Multiport Switch' incorporates:
   *  Constant: '<S358>/Constant1'
   *  Constant: '<S358>/Constant2'
   *  Constant: '<S358>/Constant3'
   *  Constant: '<S358>/Constant4'
   *  Constant: '<S358>/Constant5'
   *  Constant: '<S358>/Constant6'
   *  Constant: '<S358>/Constant7'
   *  Delay: '<S358>/Delay1'
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

  /* End of MultiPortSwitch: '<S358>/Multiport Switch' */

  /* RelationalOperator: '<S358>/Relational Operator1' incorporates:
   *  UnitDelay: '<S358>/Unit Delay'
   */
  WiperCtl_InrTimChg = (WiperCtl_InrTim != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h);

  /* Delay: '<S358>/Delay2' */
  if (AppSwcBcm_ARID_DEF.icLoad_gt) {
    /* Switch: '<S358>/Switch2' incorporates:
     *  Constant: '<S358>/Constant15'
     *  Constant: '<S358>/Constant21'
     *  RelationalOperator: '<S358>/Relational Operator5'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE =
        AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb;
    }

    /* End of Switch: '<S358>/Switch2' */
  }

  /* MultiPortSwitch: '<S358>/Multiport Switch1' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant9'
     */
    WiperCtl_WiprIntlTimeSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant16'
     */
    WiperCtl_WiprIntlTimeSetFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant10'
     */
    WiperCtl_WiprIntlTimeSetFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant11'
     */
    WiperCtl_WiprIntlTimeSetFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant12'
     */
    WiperCtl_WiprIntlTimeSetFb = 4U;
    break;

   case 6:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant13'
     */
    WiperCtl_WiprIntlTimeSetFb = 5U;
    break;

   case 7:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Constant: '<S358>/Constant14'
     */
    WiperCtl_WiprIntlTimeSetFb = 6U;
    break;

   default:
    /* MultiPortSwitch: '<S358>/Multiport Switch1' incorporates:
     *  Delay: '<S358>/Delay2'
     */
    WiperCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.Delay2_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S358>/Multiport Switch1' */

  /* Update for Delay: '<S358>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_f = false;
  AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrTim;

  /* Update for UnitDelay: '<S358>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h = WiperCtl_InrTim;

  /* Update for Delay: '<S358>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_gt = false;
  AppSwcBcm_ARID_DEF.Delay2_DSTATE = WiperCtl_WiprIntlTimeSetFb;
}

/* Output and update for atomic system: '<S270>/WiperLowSpdCtl' */
static void AppSwcBcm_WiperLowSpdCtl(void)
{
  boolean rtb_RelationalOperator_c;

  /* RelationalOperator: '<S359>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S359>/Logical Operator' incorporates:
   *  RelationalOperator: '<S359>/Relational Operator1'
   *  RelationalOperator: '<S359>/Relational Operator2'
   */
  WiperCtl_WiperLowSpdSta = (rtb_RelationalOperator_c && WiperCtl_WiperLowSpdSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay7_j));
}

/* Output and update for atomic system: '<S270>/WiperMaintCtl' */
static void AppSwcBcm_WiperMaintCtl(void)
{
  boolean rtb_RelationalOperator6_kg;

  /* Chart: '<S360>/MaintOff' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S360>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mk) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kh =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

    /* Outputs for Function Call SubSystem: '<S400>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kh,
      &AppSwcBcm_ARID_DEF.LogicalOperator_es,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_me);

    /* End of Outputs for SubSystem: '<S400>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.Flg_hg = (AppSwcBcm_ARID_DEF.LogicalOperator_es ||
      AppSwcBcm_ARID_DEF.Flg_hg);
    if (AppSwcBcm_ARID_DEF.Flg_hg) {
      AppSwcBcm_ARID_DEF.Lib_blIn_az =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S400>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_az,
        &AppSwcBcm_ARID_DEF.LogicalOperator_a1,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_h);

      /* End of Outputs for SubSystem: '<S400>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff =
        (AppSwcBcm_ARID_DEF.LogicalOperator_a1 ||
         AppSwcBcm_ARID_DEF.WiperCtl_MaintOff);
    }
  } else {
    AppSwcBcm_ARID_DEF.Flg_hg = false;
    AppSwcBcm_ARID_DEF.WiperCtl_MaintOff = false;
  }

  /* End of Chart: '<S360>/MaintOff' */

  /* Outputs for Atomic SubSystem: '<S360>/Lib_SR' */
  /* Switch: '<S399>/Switch' incorporates:
   *  Constant: '<S360>/Constant2'
   *  Constant: '<S360>/Constant5'
   *  Constant: '<S399>/Constant'
   *  Logic: '<S360>/Logical Operator'
   *  Logic: '<S360>/Logical Operator1'
   *  Logic: '<S399>/Logical Operator'
   *  RelationalOperator: '<S360>/Relational Operator1'
   *  RelationalOperator: '<S360>/Relational Operator2'
   *  RelationalOperator: '<S360>/Relational Operator3'
   *  RelationalOperator: '<S360>/Relational Operator4'
   *  RelationalOperator: '<S360>/Relational Operator5'
   *  UnitDelay: '<S399>/Unit Delay'
   */
  if ((!WiperCtl_WiperOffSw) ||
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 1) ||
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff) {
    WiperCtl_WiperMaintSta = false;
  } else {
    /* RelationalOperator: '<S360>/Relational Operator6' incorporates:
     *  Constant: '<S360>/Constant3'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_kg = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    WiperCtl_WiperMaintSta = (((!AppSwcBcm_ARID_DEF.UnitDelay6_c) &&
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 2) &&
      WiperCtl_WiperParkPosSw && rtb_RelationalOperator6_kg) ||
      WiperCtl_WiperMaintSta);
  }

  /* End of Switch: '<S399>/Switch' */
  /* End of Outputs for SubSystem: '<S360>/Lib_SR' */

  /* Update for UnitDelay: '<S360>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mk = WiperCtl_WiperMaintSta;
}

/* Output and update for atomic system: '<S270>/WiperMistCtl' */
static void AppSwcBcm_WiperMistCtl(void)
{
  boolean rtb_RelationalOperator_f;

  /* RelationalOperator: '<S361>/Relational Operator' incorporates:
   *  Constant: '<S361>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S361>/Logical Operator' incorporates:
   *  RelationalOperator: '<S361>/Relational Operator1'
   *  RelationalOperator: '<S361>/Relational Operator2'
   */
  WiperCtl_WiperMistSta = (rtb_RelationalOperator_f && WiperCtl_WiperMistSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay3_o));
}

/* Output and update for atomic system: '<S270>/WiperOffCtl' */
static void AppSwcBcm_WiperOffCtl(void)
{
  boolean rtb_RelationalOperator_hb;

  /* RelationalOperator: '<S362>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_hb = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Logic: '<S362>/Logical Operator' incorporates:
   *  RelationalOperator: '<S362>/Relational Operator1'
   */
  WiperCtl_WiperOffSta = (rtb_RelationalOperator_hb || WiperCtl_WiperOffSw);
}

/* System initialize for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S270>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt_Init();

  /* End of SystemInitialize for SubSystem: '<S270>/LockedRotorProt' */

  /* SystemInitialize for Atomic SubSystem: '<S270>/WashCtl' */
  AppSwcBcm_WashCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S270>/WashCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S270>/WiperDrv' */
  AppSwcBcm_WiperDrv_Init();

  /* End of SystemInitialize for SubSystem: '<S270>/WiperDrv' */

  /* SystemInitialize for Atomic SubSystem: '<S270>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S270>/WiperInrCtl' */
}

/* Output and update for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl(void)
{
  boolean rtb_DataTypeConversion;

  /* SignalConversion: '<S270>/Signal Conversion' */
  SCS_FrntWiprSwtSt =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWiprSwtSt_enum;

  /* SignalConversion: '<S270>/Signal Conversion1' */
  SCS_FrntWshrSwtSt =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWshrSwtSt_flg;

  /* SignalConversion: '<S270>/Signal Conversion2' */
  SCS_FrntWshrSwtStVD =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWshrSwtStVld_flg;

  /* SignalConversion: '<S270>/Signal Conversion3' */
  SCS_WiprSwtStVD =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWiprSwtStVld_flg;

  /* Outputs for Atomic SubSystem: '<S270>/SignalProcess' */
  AppSwcBcm_SignalProcess();

  /* End of Outputs for SubSystem: '<S270>/SignalProcess' */

  /* UnitDelay: '<S270>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_f = WiperCtl_LockedRotorProtSta;

  /* Outputs for Atomic SubSystem: '<S270>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl();

  /* End of Outputs for SubSystem: '<S270>/WiperInrCtl' */

  /* Outputs for Atomic SubSystem: '<S270>/WiperOffCtl' */
  AppSwcBcm_WiperOffCtl();

  /* End of Outputs for SubSystem: '<S270>/WiperOffCtl' */

  /* UnitDelay: '<S270>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_db = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_c;

  /* Outputs for Atomic SubSystem: '<S270>/WashCtl' */
  AppSwcBcm_WashCtl();

  /* End of Outputs for SubSystem: '<S270>/WashCtl' */

  /* UnitDelay: '<S270>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_h = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i;

  /* Outputs for Atomic SubSystem: '<S270>/WiperHiSpdCtl' */
  AppSwcBcm_WiperHiSpdCtl();

  /* End of Outputs for SubSystem: '<S270>/WiperHiSpdCtl' */

  /* UnitDelay: '<S270>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_j = AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_a;

  /* Outputs for Atomic SubSystem: '<S270>/WiperLowSpdCtl' */
  AppSwcBcm_WiperLowSpdCtl();

  /* End of Outputs for SubSystem: '<S270>/WiperLowSpdCtl' */

  /* UnitDelay: '<S270>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_o = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_j;

  /* Outputs for Atomic SubSystem: '<S270>/WiperMistCtl' */
  AppSwcBcm_WiperMistCtl();

  /* End of Outputs for SubSystem: '<S270>/WiperMistCtl' */

  /* UnitDelay: '<S270>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_c = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_o;

  /* Outputs for Atomic SubSystem: '<S270>/WiperMaintCtl' */
  AppSwcBcm_WiperMaintCtl();

  /* End of Outputs for SubSystem: '<S270>/WiperMaintCtl' */

  /* Outputs for Atomic SubSystem: '<S270>/WiperDrv' */
  AppSwcBcm_WiperDrv();

  /* End of Outputs for SubSystem: '<S270>/WiperDrv' */

  /* Outputs for Atomic SubSystem: '<S270>/Ovrd1' */
  /* Switch: '<S351>/Switch1' incorporates:
   *  Constant: '<S270>/Constant1'
   */
  if (WiperCtl_LowSpdDrvOvrdFlg_C) {
    /* Switch: '<S351>/Switch1' incorporates:
     *  Constant: '<S270>/Constant2'
     */
    WiperCtl_LowSpdDrv = WiperCtl_LowSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S270>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus())
      ->WiperLowSpdCtlFlg != 0);

    /* Switch: '<S351>/Switch1' incorporates:
     *  Switch: '<S351>/Switch2'
     */
    WiperCtl_LowSpdDrv = (rtb_DataTypeConversion ||
                          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_p);
  }

  /* End of Switch: '<S351>/Switch1' */
  /* End of Outputs for SubSystem: '<S270>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S270>/Ovrd2' */
  /* Switch: '<S352>/Switch1' incorporates:
   *  Constant: '<S270>/Constant3'
   */
  if (WiperCtl_HiSpdDrvOvrdFlg_C) {
    /* Switch: '<S352>/Switch1' incorporates:
     *  Constant: '<S270>/Constant4'
     */
    WiperCtl_HiSpdDrv = WiperCtl_HiSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S270>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus())
      ->WiperHiSpdCtlFlg != 0);

    /* Switch: '<S352>/Switch1' incorporates:
     *  Switch: '<S352>/Switch2'
     */
    WiperCtl_HiSpdDrv = (rtb_DataTypeConversion ||
                         AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_k);
  }

  /* End of Switch: '<S352>/Switch1' */
  /* End of Outputs for SubSystem: '<S270>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S270>/Ovrd3' */
  /* Switch: '<S353>/Switch1' incorporates:
   *  Constant: '<S270>/Constant18'
   */
  if (WiperCtl_WashMotorDrvOvrdFlg_C) {
    /* Switch: '<S353>/Switch1' incorporates:
     *  Constant: '<S270>/Constant19'
     */
    WiperCtl_WashMotorDrv = WiperCtl_WashMotorDrvOvrdVal_C;
  } else {
    /* Switch: '<S353>/Switch1' incorporates:
     *  Switch: '<S353>/Switch2'
     */
    WiperCtl_WashMotorDrv = AppSwcBcm_ARID_DEF.LIB_blOut_hy;
  }

  /* End of Switch: '<S353>/Switch1' */
  /* End of Outputs for SubSystem: '<S270>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S270>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt();

  /* End of Outputs for SubSystem: '<S270>/LockedRotorProt' */

  /* Update for UnitDelay: '<S270>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_c = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S270>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S270>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_a = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S270>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_j = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S270>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_lf = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S270>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_o = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S270>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_br = WiperCtl_LowSpdDrv;

  /* Update for UnitDelay: '<S270>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ao = WiperCtl_HiSpdDrv;
}

/*
 * Output and update for atomic system:
 *    '<S415>/Lib_FailEdgeDet'
 *    '<S418>/Lib_FailEdgeDet'
 *    '<S416>/Lib_FailEdgeDet'
 *    '<S419>/Lib_FailEdgeDet'
 *    '<S417>/Lib_FailEdgeDet'
 *    '<S624>/Lib_FailEdgeDet'
 *    '<S624>/Lib_FailEdgeDet1'
 */
static void AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S423>/Logical Operator' incorporates:
   *  Logic: '<S423>/Logical Operator1'
   *  UnitDelay: '<S423>/Unit Delay'
   */
  *rty_Lib_blOut = ((!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S423>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S414>/Lib_FailEdgeDet'
 *    '<S414>/Lib_FailEdgeDet3'
 *    '<S414>/Lib_FailEdgeDet4'
 *    '<S414>/Lib_FailEdgeDet2'
 */
static void AppSwcBcm_Lib_FailEdgeDet_l(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S415>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S415>/Lib_FailEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S422>/Lib_RiseEdgeDetInit'
 *    '<S879>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S430>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S422>/Lib_RiseEdgeDetInit'
 *    '<S879>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_a(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S430>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S430>/Logical Operator' incorporates:
   *  Delay: '<S430>/Delay'
   *  Logic: '<S430>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S430>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Output and update for function-call system: '<S414>/Lib_FailEdgeDet1' */
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S416>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet(rtu_Lib_blIn, rty_Lib_lbOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S416>/Lib_FailEdgeDet' */
}

/* Function for Chart: '<S405>/AlmSysLogic' */
static void AppSwcBcm_AlmWarn(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_a = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_a,
    &AppSwcBcm_ARID_DEF.LogicalOperator_cl,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

  /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_cl) {
    /* Flg=1; */
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_pk = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet1' */
    AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_pk,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jg,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

    /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet1' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jg) {
      /* Flg=1; */
      AppSwcBcm_ARID_DEF.Cnt_h = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_m = AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

      /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet2' */
      AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_m,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jw,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

      /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jw) {
        /* Flg=1; */
        AppSwcBcm_ARID_DEF.Cnt_h = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_bo =
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet3' */
        AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_bo,
          &AppSwcBcm_ARID_DEF.LogicalOperator_at,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

        /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet3' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_at) {
          /* Flg=1; */
          AppSwcBcm_ARID_DEF.Cnt_h = 0U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_kz =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

          /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet4' */
          AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_kz,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

          /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet4' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
            /* Flg=1; */
            AppSwcBcm_ARID_DEF.Cnt_h = 0U;
          }
        }
      }
    }
  }

  if (AppSwcBcm_ARID_DEF.Cnt_h >= AlmSysCtl_AlrmTimLimit_C) {
    AlmSysCtl_AlrmWarnTimOut = true;

    /* Flg=0; */
  } else {
    AppSwcBcm_ARID_DEF.Cnt_h++;
    AlmSysCtl_AlrmWarnTimOut = false;
  }
}

/* System initialize for atomic system: '<S405>/AlmSysLogic' */
static void AppSwcBcm_AlmSysLogic_Init(void)
{
  /* SystemInitialize for Function Call SubSystem: '<S414>/Lib_RiseEdgeDetInit' */
  /* SystemInitialize for Atomic SubSystem: '<S422>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h);

  /* End of SystemInitialize for SubSystem: '<S422>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S414>/Lib_RiseEdgeDetInit' */
}

/* Output and update for atomic system: '<S405>/AlmSysLogic' */
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

  /* Chart: '<S405>/AlmSysLogic' incorporates:
   *  UnitDelay: '<S4>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_AlmSysCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_AlmSysCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Init_m;
    AlmSysCtl_BodyWarnSts = AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts;
    AppSwcBcm_ARID_DEF.Lib_blIn_a = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

    /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet' */
    AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_a,
      &AppSwcBcm_ARID_DEF.LogicalOperator_cl,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

    /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet' */
    AppSwcBcm_ARID_DEF.Lib_blIn_pk = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet1' */
    AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_pk,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jg,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

    /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet1' */
    AppSwcBcm_ARID_DEF.Lib_blIn_m = AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

    /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet2' */
    AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_m,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jw,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

    /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet2' */
    AppSwcBcm_ARID_DEF.Lib_blIn_bo = AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

    /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet3' */
    AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_bo,
      &AppSwcBcm_ARID_DEF.LogicalOperator_at,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

    /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet3' */
    AppSwcBcm_ARID_DEF.Lib_blIn_kz = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

    /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet4' */
    AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_kz,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

    /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet4' */
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
        AppSwcBcm_ARID_DEF.Lib_blIn_kw = (AppSwcBcm_ARID_DEF.UnitDelay4 == 1);

        /* Outputs for Function Call SubSystem: '<S414>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kw,
          &AppSwcBcm_ARID_DEF.LogicalOperator_bbk,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);

        /* End of Outputs for SubSystem: '<S414>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_bbk) {
          guard4 = true;
        } else if (((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) ||
                   AlmSysCtl_AlrmWarnTimOut) {
          /* UpdateSta(); */
          AppSwcBcm_ARID_DEF.Cnt_h = 0U;
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
          AlmSysCtl_BodyWarnSts = 1U;

          /* du:UpdateSta(); */
        } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                   ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                    (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
          /* UpdateSta(); */
          AppSwcBcm_ARID_DEF.Cnt_h = 0U;
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_AlmWarn();
        }
      }
      break;

     case AppSwcBcm_IN_Armed:
      if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
        guard5 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_kw = (AppSwcBcm_ARID_DEF.UnitDelay4 == 1);

        /* Outputs for Function Call SubSystem: '<S414>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kw,
          &AppSwcBcm_ARID_DEF.LogicalOperator_bbk,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);

        /* End of Outputs for SubSystem: '<S414>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_bbk) {
          guard5 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta == 1) {
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_a =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

          /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet' */
          AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_a,
            &AppSwcBcm_ARID_DEF.LogicalOperator_cl,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

          /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_cl) {
            guard8 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_pk =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

            /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet1' */
            AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_pk,
              &AppSwcBcm_ARID_DEF.LogicalOperator_jg,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

            /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet1' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_jg) {
              guard8 = true;
            } else {
              guard7 = true;
            }
          }
        }
      }
      break;

     case AppSwcBcm_IN_Disarmed:
      if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) {
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
      } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                 ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                  (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
      }
      break;

     case AppSwcBcm_IN_Init_m:
      switch (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
        break;

       case 2:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
        AlmSysCtl_BodyWarnSts = 2U;
        AlmSysCtl_AlrmWarnTimOut = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
        break;

       default:
        AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
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
        AppSwcBcm_ARID_DEF.Lib_blIn_ce =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;
        AppSwcBcm_ARID_DEF.Lib_blInit_b = true;

        /* Outputs for Function Call SubSystem: '<S414>/Lib_RiseEdgeDetInit' */
        /* Outputs for Atomic SubSystem: '<S422>/Lib_RiseEdgeDetInit' */
        AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_ce, true,
          &AppSwcBcm_ARID_DEF.LogicalOperator_lk,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h);

        /* End of Outputs for SubSystem: '<S422>/Lib_RiseEdgeDetInit' */
        /* End of Outputs for SubSystem: '<S414>/Lib_RiseEdgeDetInit' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_lk &&
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) {
          guard1 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
          guard2 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_kw = (AppSwcBcm_ARID_DEF.UnitDelay4 == 1);

          /* Outputs for Function Call SubSystem: '<S414>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kw,
            &AppSwcBcm_ARID_DEF.LogicalOperator_bbk,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);

          /* End of Outputs for SubSystem: '<S414>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_bbk) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_a =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

            /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet' */
            AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_a,
              &AppSwcBcm_ARID_DEF.LogicalOperator_cl,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

            /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_cl) {
              guard3 = true;
            } else {
              AppSwcBcm_ARID_DEF.Lib_blIn_pk =
                AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

              /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet1' */
              AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_pk,
                &AppSwcBcm_ARID_DEF.LogicalOperator_jg,
                &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

              /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet1' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_jg) {
                guard3 = true;
              } else {
                AppSwcBcm_ARID_DEF.Lib_blIn_kz =
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

                /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet4' */
                AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_kz,
                  &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
                  &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

                /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet4' */
                if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
                  guard3 = true;
                } else {
                  AppSwcBcm_ARID_DEF.Lib_blIn_np =
                    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k;

                  /* Outputs for Function Call SubSystem: '<S414>/Lib_RiseEdgeDet1' */
                  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_np,
                    &AppSwcBcm_ARID_DEF.LogicalOperator_a4,
                    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_e);

                  /* End of Outputs for SubSystem: '<S414>/Lib_RiseEdgeDet1' */
                  if (AppSwcBcm_ARID_DEF.LogicalOperator_a4) {
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
      AppSwcBcm_ARID_DEF.Lib_blIn_np = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k;

      /* Outputs for Function Call SubSystem: '<S414>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_np,
        &AppSwcBcm_ARID_DEF.LogicalOperator_a4,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_e);

      /* End of Outputs for SubSystem: '<S414>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_a4) {
        guard6 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_m =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

        /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet2' */
        AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_m,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jw,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

        /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_jw) {
          guard6 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_bo =
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

          /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet3' */
          AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_bo,
            &AppSwcBcm_ARID_DEF.LogicalOperator_at,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

          /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet3' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_at) {
            guard6 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_kz =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

            /* Outputs for Function Call SubSystem: '<S414>/Lib_FailEdgeDet4' */
            AppSwcBcm_Lib_FailEdgeDet_l(AppSwcBcm_ARID_DEF.Lib_blIn_kz,
              &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

            /* End of Outputs for SubSystem: '<S414>/Lib_FailEdgeDet4' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
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
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard4) {
      /* UpdateSta(); */
      AppSwcBcm_ARID_DEF.Cnt_h = 0U;
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard3) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_BodyWarnSts = 2U;
      AlmSysCtl_AlrmWarnTimOut = false;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
      AlmSysCtl_BodyWarnSts = 1U;

      /* du:UpdateSta(); */
    }
  }

  /* End of Chart: '<S405>/AlmSysLogic' */
}

/* System initialize for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S405>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic_Init();
}

/* Output and update for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl(void)
{
  /* DataTypeConversion: '<S405>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.DataTypeConversion10 =
    (AppSwcBcm_ARID_DEF.BusCreator14.SKSta != 0);

  /* Chart: '<S405>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic();
}

/*
 * System initialize for atomic system:
 *    '<S434>/Lib_BothEdgeDetInit'
 *    '<S434>/Lib_BothEdgeDetInit1'
 *    '<S434>/Lib_BothEdgeDetInit2'
 *    '<S434>/Lib_BothEdgeDetInit3'
 */
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S437>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S434>/Lib_BothEdgeDetInit'
 *    '<S434>/Lib_BothEdgeDetInit1'
 *    '<S434>/Lib_BothEdgeDetInit2'
 *    '<S434>/Lib_BothEdgeDetInit3'
 */
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Delay: '<S437>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S437>/Logical Operator2' incorporates:
   *  Delay: '<S437>/Delay'
   *  Logic: '<S437>/Logical Operator1'
   *  Logic: '<S437>/Logical Operator3'
   *  Logic: '<S437>/Logical Operator4'
   *  Logic: '<S437>/Logical Operator5'
   */
  rty_Lib_blOut_0 = ((AppSwcBcm__ARID_DEF_arg->Delay_DSTATE && (!rtu_Lib_blIn)) ||
                     (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE)));

  /* Update for Delay: '<S437>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S434>/Lib_BothEdgeDetInit' */

  /* SystemInitialize for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit1' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of SystemInitialize for SubSystem: '<S434>/Lib_BothEdgeDetInit1' */

  /* SystemInitialize for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit2' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of SystemInitialize for SubSystem: '<S434>/Lib_BothEdgeDetInit2' */

  /* SystemInitialize for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit3' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of SystemInitialize for SubSystem: '<S434>/Lib_BothEdgeDetInit3' */
}

/* Output and update for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion;
  boolean rtb_RelationalOperator2_hd;
  boolean rtb_RelationalOperator3_dj;
  boolean rtb_RelationalOperator4_e;
  boolean rtb_RelationalOperator_c;
  boolean rtb_Switch;

  /* RelationalOperator: '<S434>/Relational Operator' incorporates:
   *  Constant: '<S434>/Constant'
   */
  BatSaveCtl_PwrModeOn = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

  /* RelationalOperator: '<S434>/Relational Operator1' incorporates:
   *  Constant: '<S434>/Constant1'
   */
  BatSaveCtl_DoorUnlckPwrOn = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* Outputs for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit' */
  rtb_RelationalOperator_c = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of Outputs for SubSystem: '<S434>/Lib_BothEdgeDetInit' */

  /* Outputs for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit1' */
  rtb_RelationalOperator2_hd = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of Outputs for SubSystem: '<S434>/Lib_BothEdgeDetInit1' */

  /* Outputs for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit2' */
  rtb_RelationalOperator3_dj = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of Outputs for SubSystem: '<S434>/Lib_BothEdgeDetInit2' */

  /* Outputs for Atomic SubSystem: '<S434>/Lib_BothEdgeDetInit3' */
  rtb_RelationalOperator4_e = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of Outputs for SubSystem: '<S434>/Lib_BothEdgeDetInit3' */

  /* Logic: '<S434>/Logical Operator1' */
  BatSaveCtl_DoorChgSta = (rtb_RelationalOperator_c ||
    rtb_RelationalOperator2_hd || rtb_RelationalOperator3_dj ||
    rtb_RelationalOperator4_e);

  /* Logic: '<S434>/Logical Operator' */
  BatSaveCtl_PwrOn = (BatSaveCtl_PwrModeOn || BatSaveCtl_DoorUnlckPwrOn ||
                      BatSaveCtl_DoorChgSta);

  /* Chart: '<S433>/LIB_PosPluse' incorporates:
   *  Constant: '<S433>/Constant2'
   *  Constant: '<S433>/Constant4'
   *  Logic: '<S433>/Logical Operator2'
   *  Logic: '<S433>/Logical Operator3'
   *  Logic: '<S433>/Logical Operator5'
   *  Logic: '<S433>/Logical Operator8'
   *  RelationalOperator: '<S433>/Relational Operator'
   *  RelationalOperator: '<S433>/Relational Operator2'
   *  RelationalOperator: '<S433>/Relational Operator3'
   *  RelationalOperator: '<S433>/Relational Operator4'
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

  /* End of Chart: '<S433>/LIB_PosPluse' */

  /* Chart: '<S433>/LIB_PosPluse1' incorporates:
   *  Constant: '<S433>/Constant6'
   *  Constant: '<S433>/Constant7'
   *  RelationalOperator: '<S433>/Relational Operator6'
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

  /* End of Chart: '<S433>/LIB_PosPluse1' */

  /* Logic: '<S433>/Logical Operator' */
  BatSaveCtl_PwrOff = (BatSaveCtl_PwrModeOff || BatSaveCtl_DoorLckPwrOff);

  /* Outputs for Atomic SubSystem: '<S406>/Lib_SR' */
  AppSwcBcm_Lib_SR(BatSaveCtl_PwrOn, BatSaveCtl_PwrOff, &rtb_Switch,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_f);

  /* End of Outputs for SubSystem: '<S406>/Lib_SR' */

  /* Outputs for Atomic SubSystem: '<S406>/Ovrd1' */
  /* Switch: '<S432>/Switch1' incorporates:
   *  Constant: '<S406>/Constant18'
   */
  if (BatSaveCtl_J64SavePwrOvrdFlg_C) {
    /* Switch: '<S432>/Switch1' incorporates:
     *  Constant: '<S406>/Constant19'
     */
    BatSaveCtl_J64SavePwr = BatSaveCtl_J64SavePwrOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S406>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->BatSaveCtlFlg != 0);

    /* Switch: '<S432>/Switch1' incorporates:
     *  Switch: '<S432>/Switch2'
     */
    BatSaveCtl_J64SavePwr = (rtb_DataTypeConversion || rtb_Switch);
  }

  /* End of Switch: '<S432>/Switch1' */
  /* End of Outputs for SubSystem: '<S406>/Ovrd1' */
}

/* Function for Chart: '<S407>/DoorDrv' */
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

/* Function for Chart: '<S407>/DoorDrv' */
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

/* Function for Chart: '<S407>/DoorDrv' */
static void AppSwcBcm_InsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_ob = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ob,
    &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

  /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_pd ||
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

/* Function for Chart: '<S407>/DoorDrv' */
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

/* Function for Chart: '<S407>/DoorDrv' */
static void AppSwcBcm_OsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_ob = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ob,
    &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

  /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_pd ||
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

/* System initialize for atomic system: '<S407>/DoorDrv' */
static void AppSwcBcm_DoorDrv_Init(void)
{
  DoorLckCtl_TrunkLckSw = true;
}

/* Output and update for atomic system: '<S407>/DoorDrv' */
static void AppSwcBcm_DoorDrv(void)
{
  boolean tmp;
  boolean tmp_0;

  /* Chart: '<S407>/DoorDrv' incorporates:
   *  UnitDelay: '<S4>/Unit Delay6'
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
        tmp_0 = !AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_c;
        if (DoorLckCtl_InsLck && tmp && tmp_0) {
          AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_InsDrvLck;
        } else if (DoorLckCtl_OsLck && tmp && tmp_0) {
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

  /* End of Chart: '<S407>/DoorDrv' */
}

/* Output and update for atomic system: '<S442>/AntiLckProt' */
static void AppSwcBcm_AntiLckProt(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator2_bb;
  boolean rtb_RelationalOperator6_n;

  /* RelationalOperator: '<S449>/Relational Operator6' incorporates:
   *  Constant: '<S449>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator6_n =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S449>/Logical Operator2' incorporates:
   *  Constant: '<S449>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S449>/Relational Operator5'
   */
  rtb_LogicalOperator2_bb =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S449>/Logical Operator5' */
  rtb_RelationalOperator6_n = (rtb_RelationalOperator6_n ||
    rtb_LogicalOperator2_bb);

  /* Logic: '<S449>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S449>/Relational Operator2'
   *  RelationalOperator: '<S449>/Relational Operator3'
   *  RelationalOperator: '<S449>/Relational Operator4'
   */
  rtb_LogicalOperator2_bb = ((!DoorLckCtl_DoorAjarFLSw) ||
    (!DoorLckCtl_DoorAjarFRSw) || (!DoorLckCtl_DoorAjarRRSw));

  /* Logic: '<S449>/Logical Operator1' */
  DoorLckCtl_RKEAntiLck = (rtb_RelationalOperator6_n && rtb_LogicalOperator2_bb &&
    DoorLckCtl_RKELck);

  /* Logic: '<S449>/Logical Operator3' */
  DoorLckCtl_MechAntiLck = (DoorLckCtl_MechLck && rtb_LogicalOperator2_bb);

  /* Logic: '<S449>/Logical Operator4' incorporates:
   *  Constant: '<S449>/Constant1'
   *  Logic: '<S449>/Logical Operator'
   *  RelationalOperator: '<S449>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_fr = (DoorLckCtl_RKEAntiLck || (DoorLckCtl_HULck &&
    (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) && rtb_LogicalOperator2_bb) ||
    DoorLckCtl_MechAntiLck);

  /* Chart: '<S449>/LIB_Tim' incorporates:
   *  SubSystem: '<S462>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fr,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ja,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mj);
  AppSwcBcm_ARID_DEF.TempEn = (AppSwcBcm_ARID_DEF.LogicalOperator_ja ||
    AppSwcBcm_ARID_DEF.TempEn);
  if (AppSwcBcm_ARID_DEF.TempEn) {
    /* Constant: '<S449>/Constant' */
    if (AppSwcBcm_ARID_DEF.Cnt_jw <= DoorLckCtl_AntiLckProtTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_jw + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_jw + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_jw = (uint16)tmp;
      DoorLckCtl_DoorProtUnlck = false;
    } else {
      DoorLckCtl_DoorProtUnlck = true;
      AppSwcBcm_ARID_DEF.TempEn = false;
    }

    /* End of Constant: '<S449>/Constant' */
  } else {
    DoorLckCtl_DoorProtUnlck = false;
    AppSwcBcm_ARID_DEF.Cnt_jw = 0U;
  }
}

/* System initialize for atomic system: '<S442>/IllmndLckSet' */
static void AppSwcBcm_IllmndLckSet_Init(void)
{
  /* InitializeConditions for Delay: '<S451>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k5 = true;

  /* InitializeConditions for UnitDelay: '<S451>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fn = 1U;
}

/* Output and update for atomic system: '<S442>/IllmndLckSet' */
static void AppSwcBcm_IllmndLckSet(void)
{
  uint8 rtb_Switch;

  /* Delay: '<S451>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_k5) {
    /* Switch: '<S451>/Switch1' incorporates:
     *  Constant: '<S451>/Constant7'
     *  Constant: '<S451>/Constant8'
     *  RelationalOperator: '<S451>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_g = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_g =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts;
    }

    /* End of Switch: '<S451>/Switch1' */
  }

  /* Switch: '<S451>/Switch' incorporates:
   *  Constant: '<S451>/Constant5'
   *  RelationalOperator: '<S451>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S451>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndLckSts_enum;
  } else {
    /* Switch: '<S451>/Switch' incorporates:
     *  Constant: '<S451>/Constant6'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S451>/Switch' */

  /* MultiPortSwitch: '<S451>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S451>/Multiport Switch' incorporates:
     *  Constant: '<S451>/Constant1'
     */
    DoorLckCtl_IllmndLckSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S451>/Multiport Switch' incorporates:
     *  Constant: '<S451>/Constant2'
     */
    DoorLckCtl_IllmndLckSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S451>/Multiport Switch' incorporates:
     *  Delay: '<S451>/Delay'
     */
    DoorLckCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_g;
    break;
  }

  /* End of MultiPortSwitch: '<S451>/Multiport Switch' */

  /* MultiPortSwitch: '<S451>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndLckSts) {
   case 1:
    /* MultiPortSwitch: '<S451>/Multiport Switch1' incorporates:
     *  Constant: '<S451>/Constant3'
     */
    DoorLckCtl_IllmndLckStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S451>/Multiport Switch1' incorporates:
     *  Constant: '<S451>/Constant4'
     */
    DoorLckCtl_IllmndLckStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S451>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S451>/Unit Delay'
     */
    DoorLckCtl_IllmndLckStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fn;
    break;
  }

  /* End of MultiPortSwitch: '<S451>/Multiport Switch1' */

  /* Update for Delay: '<S451>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k5 = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_g = DoorLckCtl_IllmndLckSts;

  /* Update for UnitDelay: '<S451>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fn = DoorLckCtl_IllmndLckStsFb;
}

/* System initialize for atomic system: '<S442>/IllmndUnlckSet' */
static void AppSwcBcm_IllmndUnlckSet_Init(void)
{
  /* InitializeConditions for Delay: '<S452>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kx = true;

  /* InitializeConditions for UnitDelay: '<S452>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c = 1U;
}

/* Output and update for atomic system: '<S442>/IllmndUnlckSet' */
static void AppSwcBcm_IllmndUnlckSet(void)
{
  uint8 rtb_Switch;

  /* Delay: '<S452>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_kx) {
    /* Switch: '<S452>/Switch1' incorporates:
     *  Constant: '<S452>/Constant7'
     *  Constant: '<S452>/Constant8'
     *  RelationalOperator: '<S452>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_p = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_p =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts;
    }

    /* End of Switch: '<S452>/Switch1' */
  }

  /* Switch: '<S452>/Switch' incorporates:
   *  Constant: '<S452>/Constant5'
   *  RelationalOperator: '<S452>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S452>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndUnlckSts_enum;
  } else {
    /* Switch: '<S452>/Switch' incorporates:
     *  Constant: '<S452>/Constant6'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S452>/Switch' */

  /* MultiPortSwitch: '<S452>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S452>/Multiport Switch' incorporates:
     *  Constant: '<S452>/Constant1'
     */
    DoorLckCtl_IllmndUnlockSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S452>/Multiport Switch' incorporates:
     *  Constant: '<S452>/Constant2'
     */
    DoorLckCtl_IllmndUnlockSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S452>/Multiport Switch' incorporates:
     *  Delay: '<S452>/Delay'
     */
    DoorLckCtl_IllmndUnlockSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_p;
    break;
  }

  /* End of MultiPortSwitch: '<S452>/Multiport Switch' */

  /* MultiPortSwitch: '<S452>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndUnlockSts) {
   case 1:
    /* MultiPortSwitch: '<S452>/Multiport Switch1' incorporates:
     *  Constant: '<S452>/Constant3'
     */
    DoorLckCtl_IllmndUnlockStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S452>/Multiport Switch1' incorporates:
     *  Constant: '<S452>/Constant4'
     */
    DoorLckCtl_IllmndUnlockStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S452>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S452>/Unit Delay'
     */
    DoorLckCtl_IllmndUnlockStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c;
    break;
  }

  /* End of MultiPortSwitch: '<S452>/Multiport Switch1' */

  /* Update for Delay: '<S452>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kx = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_p = DoorLckCtl_IllmndUnlockSts;

  /* Update for UnitDelay: '<S452>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c = DoorLckCtl_IllmndUnlockStsFb;
}

/* Output and update for atomic system: '<S453>/HULck' */
static void AppSwcBcm_HULck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator2_if;

  /* RelationalOperator: '<S465>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_if =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S465>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator2_if,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mv);

  /* End of Outputs for SubSystem: '<S465>/Lib_RiseEdgeDet' */

  /* Logic: '<S465>/Logical Operator2' incorporates:
   *  Constant: '<S465>/Constant1'
   *  RelationalOperator: '<S465>/Relational Operator'
   *  RelationalOperator: '<S465>/Relational Operator1'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  DoorLckCtl_HULck = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) &&
                      rtb_LogicalOperator && (!DoorLckCtl_DriverDoorLckSw));
}

/*
 * System initialize for atomic system:
 *    '<S466>/LIB_TPD_10ms'
 *    '<S466>/LIB_TPD_10ms1'
 *    '<S516>/LIB_TPD_10ms1'
 *    '<S622>/LIB_TPD_10ms1'
 *    '<S676>/LIB_TPD_Ts'
 *    '<S676>/LIB_TPD_Ts1'
 *    '<S633>/LIB_TPD_10ms8'
 *    '<S651>/LIB_TPD_10ms8'
 *    '<S653>/LIB_TPD_10ms11'
 *    '<S653>/LIB_TPD_10ms13'
 *    '<S890>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S466>/LIB_TPD_10ms'
 *    '<S466>/LIB_TPD_10ms1'
 *    '<S516>/LIB_TPD_10ms1'
 *    '<S622>/LIB_TPD_10ms1'
 *    '<S676>/LIB_TPD_Ts'
 *    '<S676>/LIB_TPD_Ts1'
 *    '<S633>/LIB_TPD_10ms8'
 *    '<S651>/LIB_TPD_10ms8'
 *    '<S653>/LIB_TPD_10ms11'
 *    '<S653>/LIB_TPD_10ms13'
 *    '<S890>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S466>/LIB_TPD_10ms' */
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

  /* End of Chart: '<S466>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S453>/SpdLck' */
static void AppSwcBcm_SpdLck_Init(void)
{
  /* SystemInitialize for Chart: '<S466>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_p);

  /* SystemInitialize for Chart: '<S466>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_j);
}

/* Output and update for atomic system: '<S453>/SpdLck' */
static void AppSwcBcm_SpdLck(void)
{
  boolean rtb_LogicalOperator3_l;

  /* Logic: '<S466>/Logical Operator3' incorporates:
   *  Constant: '<S466>/Constant8'
   *  RelationalOperator: '<S466>/Relational Operator6'
   */
  rtb_LogicalOperator3_l = (AppSwcBcm_ConstB.RelationalOperator1_g &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Chart: '<S466>/Chart' incorporates:
   *  Logic: '<S466>/Logical Operator4'
   *  UnitDelay: '<S466>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Flg_jx = ((rtb_LogicalOperator3_l && DoorLckCtl_SpdLck) ||
    AppSwcBcm_ARID_DEF.Flg_jx);
  if (AppSwcBcm_ARID_DEF.Flg_jx && ((!DoorLckCtl_DoorAjarFRSw) ||
       (!DoorLckCtl_DoorAjarRRSw) || (!DoorLckCtl_TrunkAjarSw))) {
    AppSwcBcm_ARID_DEF.Door_Change = true;
    AppSwcBcm_ARID_DEF.Cnt_a2 = 0U;
  }

  if (DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarRRSw &&
      DoorLckCtl_TrunkAjarSw && AppSwcBcm_ARID_DEF.Flg_jx &&
      AppSwcBcm_ARID_DEF.Door_Change && (DoorLckCtl_VehSpd >=
       DoorLckCtl_SpdLck_C)) {
    if (AppSwcBcm_ARID_DEF.Cnt_a2 >= 40) {
      AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = true;
      AppSwcBcm_ARID_DEF.Door_Change = false;
      AppSwcBcm_ARID_DEF.Flg_jx = false;
      AppSwcBcm_ARID_DEF.Cnt_a2 = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_a2++;
    }
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = false;
  }

  /* End of Chart: '<S466>/Chart' */

  /* Chart: '<S466>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S466>/Constant'
   *  Constant: '<S466>/Constant2'
   *  Constant: '<S466>/Constant3'
   *  Constant: '<S466>/Constant49'
   *  RelationalOperator: '<S466>/Relational Operator'
   */
  AppSwcBcm_LIB_TPD_10ms(DoorLckCtl_VehSpd >= DoorLckCtl_SpdLck_C,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_l);

  /* Chart: '<S466>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S466>/Constant10'
   *  Constant: '<S466>/Constant11'
   *  Constant: '<S466>/Constant9'
   *  Logic: '<S466>/Logical Operator1'
   */
  AppSwcBcm_LIB_TPD_10ms(DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarFLSw &&
    DoorLckCtl_DoorAjarRRSw && DoorLckCtl_TrunkAjarSw,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_o3);

  /* Logic: '<S466>/Logical Operator2' incorporates:
   *  Logic: '<S466>/Logical Operator'
   *  RelationalOperator: '<S466>/Relational Operator2'
   */
  rtb_LogicalOperator3_l = ((AppSwcBcm_ARID_DEF.LIB_bErrFlg_j &&
    (!DoorLckCtl_DriverDoorLckSw) && AppSwcBcm_ARID_DEF.LIB_bErrFlg_p &&
    rtb_LogicalOperator3_l) || AppSwcBcm_ARID_DEF.DoorLckCtl_Lck);

  /* Logic: '<S471>/Logical Operator' incorporates:
   *  Logic: '<S471>/Logical Operator1'
   *  UnitDelay: '<S471>/Unit Delay'
   */
  DoorLckCtl_SpdLck = (rtb_LogicalOperator3_l &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hs));

  /* Update for UnitDelay: '<S471>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hs = rtb_LogicalOperator3_l;
}

/* System initialize for atomic system: '<S442>/InsideLck' */
static void AppSwcBcm_InsideLck_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S453>/SpdLck' */
  AppSwcBcm_SpdLck_Init();

  /* End of SystemInitialize for SubSystem: '<S453>/SpdLck' */
}

/* Output and update for atomic system: '<S442>/InsideLck' */
static void AppSwcBcm_InsideLck(void)
{
  /* Outputs for Atomic SubSystem: '<S453>/HULck' */
  AppSwcBcm_HULck();

  /* End of Outputs for SubSystem: '<S453>/HULck' */

  /* Outputs for Atomic SubSystem: '<S453>/SpdLck' */
  AppSwcBcm_SpdLck();

  /* End of Outputs for SubSystem: '<S453>/SpdLck' */

  /* Logic: '<S453>/Logical Operator' */
  DoorLckCtl_InsLck = (DoorLckCtl_HULck || DoorLckCtl_SpdLck);
}

/* Output and update for atomic system: '<S442>/InsideUnlck' */
static void AppSwcBcm_InsideUnlck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_fx;
  boolean rtb_RelationalOperator1_mq;

  /* RelationalOperator: '<S472>/Relational Operator' incorporates:
   *  UnitDelay: '<S4>/Unit Delay6'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_cj = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_c;

  /* Chart: '<S472>/Chart' incorporates:
   *  SubSystem: '<S476>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_cj,
    &AppSwcBcm_ARID_DEF.LogicalOperator_d3,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_co);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_d3) {
    AppSwcBcm_ARID_DEF.Flg_bx = true;
    DoorLckCtl_CrshUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_jh = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_bx) {
    if (AppSwcBcm_ARID_DEF.Cnt_jh >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_jh >= 20) {
        DoorLckCtl_CrshUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_bx = false;
      } else {
        DoorLckCtl_CrshUnlck = false;
        AppSwcBcm_ARID_DEF.Cnt_jh++;
      }
    } else {
      AppSwcBcm_ARID_DEF.Cnt_jh = 1U;
    }
  } else {
    DoorLckCtl_CrshUnlck = false;
  }

  /* RelationalOperator: '<S473>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_mq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S473>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator1_mq,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gx);

  /* End of Outputs for SubSystem: '<S473>/Lib_RiseEdgeDet' */

  /* Logic: '<S473>/Logical Operator' incorporates:
   *  Constant: '<S473>/Constant2'
   *  RelationalOperator: '<S473>/Relational Operator'
   *  RelationalOperator: '<S473>/Relational Operator2'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  DoorLckCtl_HUUnLck = (rtb_LogicalOperator && DoorLckCtl_DriverDoorLckSw &&
                        (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0));

  /* RelationalOperator: '<S474>/Relational Operator3' incorporates:
   *  Constant: '<S474>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_mq =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S474>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_fx = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator1_mq,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ff);

  /* End of Outputs for SubSystem: '<S474>/Lib_RiseEdgeDet' */

  /* Logic: '<S474>/Logical Operator' incorporates:
   *  Constant: '<S474>/Constant'
   *  Constant: '<S474>/Constant1'
   *  RelationalOperator: '<S474>/Relational Operator'
   *  RelationalOperator: '<S474>/Relational Operator1'
   *  RelationalOperator: '<S474>/Relational Operator2'
   */
  DoorLckCtl_ParkUnlck = ((DoorLckCtl_ParkAutoUnlockSetFb == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && DoorLckCtl_DriverDoorLckSw &&
    DoorLckCtl_VehStop && rtb_LogicalOperator_fx);

  /* Logic: '<S475>/Logical Operator2' incorporates:
   *  Constant: '<S475>/Constant1'
   *  Constant: '<S475>/Constant2'
   *  Logic: '<S475>/Logical Operator'
   *  Logic: '<S475>/Logical Operator1'
   *  RelationalOperator: '<S475>/Relational Operator'
   *  RelationalOperator: '<S475>/Relational Operator1'
   *  RelationalOperator: '<S475>/Relational Operator2'
   *  UnitDelay: '<S4>/Unit Delay7'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_lx = (AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_g &&
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) || ((AppSwcBcm_ARID_DEF.UnitDelay2 ==
    2) && DoorLckCtl_VehStop)));

  /* Chart: '<S475>/Chart' incorporates:
   *  SubSystem: '<S481>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_lx,
    &AppSwcBcm_ARID_DEF.LogicalOperator_pb,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_iz);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_pb) {
    AppSwcBcm_ARID_DEF.Flg_d = true;
    DoorLckCtl_ThermRunawayUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_kn = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_d) {
    if (AppSwcBcm_ARID_DEF.Cnt_kn >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_kn >= 20) {
        DoorLckCtl_ThermRunawayUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_d = false;
      } else {
        DoorLckCtl_ThermRunawayUnlck = false;
        AppSwcBcm_ARID_DEF.Cnt_kn++;
      }
    } else {
      AppSwcBcm_ARID_DEF.Cnt_kn = 1U;
    }
  } else {
    DoorLckCtl_ThermRunawayUnlck = false;
  }

  /* Logic: '<S454>/Logical Operator' */
  DoorLckCtl_InsUnlck = (DoorLckCtl_HUUnLck || DoorLckCtl_ParkUnlck ||
    DoorLckCtl_ThermRunawayUnlck || DoorLckCtl_CrshUnlck);
}

/* Output and update for atomic system: '<S442>/MotorProt' */
static void AppSwcBcm_MotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S455>/Logical Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_jj = (DoorLckCtl_InsLck || DoorLckCtl_OsLck ||
    DoorLckCtl_InsUnlck || DoorLckCtl_OsUnlck || DoorLckCtl_TrunkUnlck);

  /* Chart: '<S455>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S484>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jj,
    &AppSwcBcm_ARID_DEF.LogicalOperator_c1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_f);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_c1 && (!AppSwcBcm_ARID_DEF.LIB_blOut_c))
  {
    tmp = AppSwcBcm_ARID_DEF.Cnt_a + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_a + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_a = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_gg = 0U;

    /* LIB_blOut=0; */
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_gg + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_gg + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_gg = (uint16)tmp;
  }

  /* Constant: '<S455>/Constant' */
  if (AppSwcBcm_ARID_DEF.Cnt2_gg >= DoorLckCtl_CntSubTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_a - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_a - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_a = (uint16)tmp;
  }

  /* End of Constant: '<S455>/Constant' */

  /* Constant: '<S455>/Constant1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_fj = (AppSwcBcm_ARID_DEF.Cnt_a >
    DoorLckCtl_MotorWorkMax_C);

  /* Chart: '<S455>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S484>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fj,
    &AppSwcBcm_ARID_DEF.LogicalOperator_o1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_i);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_o1) {
    AppSwcBcm_ARID_DEF.LIB_blOut_c = true;
    AppSwcBcm_ARID_DEF.Cnt3_p = 0U;
  }

  if (AppSwcBcm_ARID_DEF.LIB_blOut_c) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3_p + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3_p + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3_p = (uint16)tmp;
  }

  /* Constant: '<S455>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt3_p >= DoorLckCtl_MotorProtTimMax_C) {
    AppSwcBcm_ARID_DEF.LIB_blOut_c = false;
    AppSwcBcm_ARID_DEF.Cnt_a = 0U;
    AppSwcBcm_ARID_DEF.Cnt2_gg = 0U;
    AppSwcBcm_ARID_DEF.Cnt3_p = 0U;
  }

  /* End of Constant: '<S455>/Constant2' */

  /* Switch: '<S455>/Switch' incorporates:
   *  UnitDelay: '<S4>/Unit Delay6'
   */
  DoorLckCtl_MotorProt = ((!AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_c) &&
    AppSwcBcm_ARID_DEF.LIB_blOut_c);
}

/*
 * System initialize for atomic system:
 *    '<S489>/LIB_PosPluse2'
 *    '<S671>/LIB_PosPluse2'
 *    '<S941>/LIB_NegPluse2'
 *    '<S942>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S489>/LIB_PosPluse2'
 *    '<S671>/LIB_PosPluse2'
 *    '<S941>/LIB_NegPluse2'
 *    '<S942>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S489>/LIB_PosPluse2' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blRst;

  /* Outputs for Function Call SubSystem: '<S496>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S496>/Lib_RiseEdgeDet' */

  /* Chart: '<S489>/LIB_PosPluse2' */
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

/* System initialize for atomic system: '<S456>/AutoLck' */
static void AppSwcBcm_AutoLck_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_h;

  /* SystemInitialize for Chart: '<S489>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_h);
}

/* Output and update for atomic system: '<S456>/AutoLck' */
static void AppSwcBcm_AutoLck(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_h;
  boolean rtb_LogicalOperator5_c;
  boolean rtb_RelationalOperator_f;
  boolean rtb_UnitDelay_cz;

  /* Logic: '<S489>/Logical Operator5' incorporates:
   *  Constant: '<S489>/Constant13'
   *  Constant: '<S489>/Constant14'
   *  Constant: '<S489>/Constant15'
   *  Logic: '<S489>/Logical Operator4'
   *  RelationalOperator: '<S489>/Relational Operator10'
   *  RelationalOperator: '<S489>/Relational Operator11'
   *  RelationalOperator: '<S489>/Relational Operator12'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_LogicalOperator5_c = (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Outputs for Atomic SubSystem: '<S489>/Lib_ChangeEdge' */
  /* RelationalOperator: '<S497>/Relational Operator' incorporates:
   *  Constant: '<S489>/Constant8'
   *  UnitDelay: '<S497>/Unit Delay'
   */
  rtb_RelationalOperator_f = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_li == 1);

  /* Update for UnitDelay: '<S497>/Unit Delay' incorporates:
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_li =
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a;

  /* End of Outputs for SubSystem: '<S489>/Lib_ChangeEdge' */

  /* UnitDelay: '<S498>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S489>/Relational Operator9'
   */
  rtb_UnitDelay_cz = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S489>/Lib_SR' */
  /* Switch: '<S499>/Switch' incorporates:
   *  Constant: '<S489>/Constant11'
   *  Logic: '<S489>/Logical Operator'
   *  Logic: '<S489>/Logical Operator2'
   *  Logic: '<S489>/Logical Operator3'
   *  Logic: '<S489>/Logical Operator7'
   *  RelationalOperator: '<S489>/Relational Operator13'
   *  RelationalOperator: '<S489>/Relational Operator2'
   *  RelationalOperator: '<S489>/Relational Operator3'
   *  RelationalOperator: '<S489>/Relational Operator4'
   *  RelationalOperator: '<S489>/Relational Operator5'
   *  RelationalOperator: '<S489>/Relational Operator7'
   *  RelationalOperator: '<S489>/Relational Operator8'
   */
  if ((!DoorLckCtl_DoorAjarFLSw) || (!DoorLckCtl_DoorAjarFRSw) ||
      (!DoorLckCtl_DoorAjarRRSw) || (!DoorLckCtl_TrunkAjarSw) ||
      (!AppSwcBcm_ConstB.RelationalOperator6) || ((AppSwcBcm_ARID_DEF.UnitDelay2
        != 0) && (!rtb_LogicalOperator5_c)) || rtb_UnitDelay_cz ||
      DoorLckCtl_OsLck) {
    /* Switch: '<S499>/Switch' incorporates:
     *  Constant: '<S499>/Constant'
     */
    DoorLckCtl_AutoLckSta = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S489>/Lib_ChangeEdge' */
    /* Switch: '<S499>/Switch' incorporates:
     *  Constant: '<S489>/Constant'
     *  Constant: '<S489>/Constant1'
     *  Logic: '<S489>/Logical Operator1'
     *  Logic: '<S489>/Logical Operator6'
     *  Logic: '<S497>/Logical Operator'
     *  Logic: '<S499>/Logical Operator'
     *  RelationalOperator: '<S489>/Relational Operator'
     *  RelationalOperator: '<S497>/Relational Operator1'
     *  UnitDelay: '<S499>/Unit Delay'
     *  UnitDelay: '<S4>/Unit Delay1'
     */
    DoorLckCtl_AutoLckSta = (((rtb_LogicalOperator5_c ||
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) &&
      ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) && rtb_RelationalOperator_f))
      || DoorLckCtl_AutoLckSta);

    /* End of Outputs for SubSystem: '<S489>/Lib_ChangeEdge' */
  }

  /* End of Switch: '<S499>/Switch' */
  /* End of Outputs for SubSystem: '<S489>/Lib_SR' */

  /* Chart: '<S489>/LIB_PosPluse2' incorporates:
   *  Constant: '<S489>/Constant7'
   *  RelationalOperator: '<S489>/Relational Operator1'
   */
  AppSwcBcm_LIB_PosPluse2(DoorLckCtl_AutoLckSta, DoorLckCtl_AutoLckDelayTim_C,
    DoorLckCtl_OsUnlck, &rtb_LIB_blOut_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2_o);

  /* Outputs for Atomic SubSystem: '<S489>/Lib_RiseEdgeDet' */
  /* Logic: '<S498>/Logical Operator' incorporates:
   *  Logic: '<S498>/Logical Operator1'
   *  UnitDelay: '<S498>/Unit Delay'
   */
  DoorLckCtl_AutoLck = (rtb_LIB_blOut_h &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pg));

  /* Update for UnitDelay: '<S498>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pg = rtb_LIB_blOut_h;

  /* End of Outputs for SubSystem: '<S489>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S490>/LIB_TPD_10ms1'
 *    '<S512>/LIB_TPD_10ms1'
 *    '<S512>/LIB_TPD_10ms2'
 */
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S490>/LIB_TPD_10ms1'
 *    '<S512>/LIB_TPD_10ms1'
 *    '<S512>/LIB_TPD_10ms2'
 */
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  rtu_LIB_bInit, boolean *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S490>/LIB_TPD_10ms1' */
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

  /* End of Chart: '<S490>/LIB_TPD_10ms1' */
}

/* System initialize for atomic system: '<S456>/MechLck' */
static void AppSwcBcm_MechLck_Init(void)
{
  /* InitializeConditions for Delay: '<S503>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_cx = true;

  /* SystemInitialize for Chart: '<S490>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_ay);
}

/* Output and update for atomic system: '<S456>/MechLck' */
static void AppSwcBcm_MechLck(void)
{
  boolean rtb_Delay_ft;
  boolean rtb_RelationalOperator_ms;

  /* RelationalOperator: '<S490>/Relational Operator' incorporates:
   *  Constant: '<S490>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_ms =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Delay: '<S503>/Delay' incorporates:
   *  Constant: '<S490>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S490>/Relational Operator1'
   */
  rtb_Delay_ft = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                  ->VGSM_VehActGearPstn_enum == 0);

  /* Chart: '<S490>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S490>/Constant40'
   *  Constant: '<S490>/Constant41'
   *  Constant: '<S490>/Constant42'
   *  Constant: '<S490>/Constant7'
   *  Logic: '<S490>/Logical Operator1'
   *  RelationalOperator: '<S490>/Relational Operator2'
   *  RelationalOperator: '<S490>/Relational Operator3'
   *  RelationalOperator: '<S490>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 10, 10,
    DoorLckCtl_Ts_C, true, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_ay,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_o);

  /* Delay: '<S503>/Delay' incorporates:
   *  RelationalOperator: '<S490>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_cx) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_k = DoorLckCtl_DriverDoorLckSw;
  }

  /* Logic: '<S490>/Logical Operator3' incorporates:
   *  Delay: '<S503>/Delay'
   *  Logic: '<S490>/Logical Operator'
   *  Logic: '<S503>/Logical Operator'
   *  Logic: '<S503>/Logical Operator1'
   *  RelationalOperator: '<S490>/Relational Operator4'
   *  RelationalOperator: '<S490>/Relational Operator6'
   */
  DoorLckCtl_MechLck = ((!DoorLckCtl_DrvSeatSw) && (rtb_Delay_ft ||
    rtb_RelationalOperator_ms) && (DoorLckCtl_DriverDoorLckSw &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_k)) && AppSwcBcm_ARID_DEF.LIB_bErrFlg_ay &&
                        DoorLckCtl_VehStop);

  /* Update for Delay: '<S503>/Delay' incorporates:
   *  RelationalOperator: '<S490>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.icLoad_cx = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_k = DoorLckCtl_DriverDoorLckSw;
}

/* Output and update for atomic system: '<S456>/PELck' */
static void AppSwcBcm_PELck(void)
{
  boolean rtb_RelationalOperator4_j;
  boolean rtb_RelationalOperator5;

  /* RelationalOperator: '<S491>/Relational Operator4' incorporates:
   *  Constant: '<S491>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator4_j =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S491>/Relational Operator5' incorporates:
   *  Constant: '<S491>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S491>/Logical Operator1' incorporates:
   *  Logic: '<S491>/Logical Operator2'
   *  Logic: '<S491>/Logical Operator3'
   *  RelationalOperator: '<S491>/Relational Operator1'
   *  RelationalOperator: '<S491>/Relational Operator2'
   *  RelationalOperator: '<S491>/Relational Operator3'
   */
  DoorLckCtl_PELck = (AppSwcBcm_ARID_DEF.LogicalOperator_mu &&
                      (!DoorLckCtl_DriverDoorLckSw) && (!DoorLckCtl_DrvSeatSw) &&
                      (rtb_RelationalOperator4_j || rtb_RelationalOperator5) &&
                      (DoorLckCtl_DoorAjarFLSw && DoorLckCtl_DoorAjarFRSw &&
                       DoorLckCtl_DoorAjarRRSw) && DoorLckCtl_VehStop);
}

/* Output and update for atomic system: '<S456>/RKELck' */
static void AppSwcBcm_RKELck(void)
{
  sint32 tmp;
  boolean rtb_RelationalOperator1_h;
  boolean rtb_RelationalOperator_i;
  boolean rtb_UnitDelay_f;

  /* RelationalOperator: '<S492>/Relational Operator' incorporates:
   *  Constant: '<S492>/Constant'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  rtb_RelationalOperator_i = (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 2);
  AppSwcBcm_ARID_DEF.Lib_blIn_f0 = rtb_RelationalOperator_i;

  /* Chart: '<S492>/ClearRKECommd' incorporates:
   *  SubSystem: '<S504>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_f0,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ou,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ou) {
    AppSwcBcm_ARID_DEF.flg_a = true;
    AppSwcBcm_ARID_DEF.Cnt_p3 = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_p3 - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_p3 - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_p3 = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_a && (AppSwcBcm_ARID_DEF.Cnt_p3 == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_a = false;
  }

  /* RelationalOperator: '<S492>/Relational Operator1' incorporates:
   *  Constant: '<S492>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_h =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* UnitDelay: '<S505>/Unit Delay' incorporates:
   *  Constant: '<S492>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S492>/Relational Operator2'
   */
  rtb_UnitDelay_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S492>/Logical Operator1' incorporates:
   *  Logic: '<S492>/Logical Operator3'
   *  RelationalOperator: '<S492>/Relational Operator3'
   */
  rtb_RelationalOperator_i = ((!DoorLckCtl_DrvSeatSw) &&
    rtb_RelationalOperator_i && (rtb_RelationalOperator1_h || rtb_UnitDelay_f) &&
    DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S492>/Lib_RiseEdgeDet' */
  /* Logic: '<S505>/Logical Operator' incorporates:
   *  Logic: '<S505>/Logical Operator1'
   *  UnitDelay: '<S505>/Unit Delay'
   */
  DoorLckCtl_RKELck = (rtb_RelationalOperator_i &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fh));

  /* Update for UnitDelay: '<S505>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fh = rtb_RelationalOperator_i;

  /* End of Outputs for SubSystem: '<S492>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S456>/TboxLck' */
static void AppSwcBcm_TboxLck(void)
{
  boolean rtb_RelationalOperator2_au;
  boolean rtb_RelationalOperator_k2;
  boolean rtb_UnitDelay_ip;

  /* RelationalOperator: '<S493>/Relational Operator' incorporates:
   *  Constant: '<S493>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_k2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBoxRmtLck_enum == 1);

  /* RelationalOperator: '<S493>/Relational Operator2' incorporates:
   *  Constant: '<S493>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_au =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* UnitDelay: '<S508>/Unit Delay' incorporates:
   *  Constant: '<S493>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S493>/Relational Operator3'
   */
  rtb_UnitDelay_ip = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                      ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S493>/Logical Operator1' incorporates:
   *  Logic: '<S493>/Logical Operator'
   *  RelationalOperator: '<S493>/Relational Operator1'
   */
  rtb_RelationalOperator_k2 = (rtb_RelationalOperator_k2 &&
    (!DoorLckCtl_DrvSeatSw) && (rtb_RelationalOperator2_au || rtb_UnitDelay_ip) &&
    DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S493>/Lib_RiseEdgeDet' */
  /* Logic: '<S508>/Logical Operator' incorporates:
   *  Logic: '<S508>/Logical Operator1'
   *  UnitDelay: '<S508>/Unit Delay'
   */
  DoorLckCtl_TboxLck = (rtb_RelationalOperator_k2 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0));

  /* Update for UnitDelay: '<S508>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0 = rtb_RelationalOperator_k2;

  /* End of Outputs for SubSystem: '<S493>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S456>/TrunkAutoLck' */
static void AppSwcBcm_TrunkAutoLck(void)
{
  boolean rtb_LIB_blOut_l1;
  boolean rtb_RelationalOperator2_g1;

  /* RelationalOperator: '<S494>/Relational Operator2' incorporates:
   *  Constant: '<S494>/Constant2'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_RelationalOperator2_g1 = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 3);

  /* Chart: '<S494>/LIB_PosPluse1' incorporates:
   *  Constant: '<S494>/Constant1'
   *  Constant: '<S494>/Constant5'
   *  Delay: '<S494>/Delay'
   *  Logic: '<S494>/Logical Operator'
   *  Logic: '<S494>/Logical Operator2'
   *  Logic: '<S494>/Logical Operator3'
   *  RelationalOperator: '<S494>/Relational Operator1'
   *  RelationalOperator: '<S494>/Relational Operator3'
   *  UnitDelay: '<S494>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.Delay_DSTATE_pn[0U]) {
    AppSwcBcm_ARID_DEF.Flg_b5 = true;
    AppSwcBcm_ARID_DEF.Cnt_k = 0U;
  }

  if ((!rtb_RelationalOperator2_g1) || (!DoorLckCtl_TrunkAjarSw) ||
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) || DoorLckCtl_TrunkAutoLck) {
    AppSwcBcm_ARID_DEF.Flg_b5 = false;
    AppSwcBcm_ARID_DEF.Cnt_k = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_b5) {
    if (AppSwcBcm_ARID_DEF.Cnt_k >= DoorLckCtl_TrunkAutoLckTim_C) {
      rtb_LIB_blOut_l1 = true;
      AppSwcBcm_ARID_DEF.Flg_b5 = false;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_k++;
      rtb_LIB_blOut_l1 = false;
    }
  } else {
    rtb_LIB_blOut_l1 = false;
    AppSwcBcm_ARID_DEF.Cnt_k = 0U;
  }

  /* End of Chart: '<S494>/LIB_PosPluse1' */

  /* Logic: '<S494>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S494>/Relational Operator3'
   */
  rtb_RelationalOperator2_g1 = (rtb_RelationalOperator2_g1 &&
    DoorLckCtl_TrunkAjarSw && rtb_LIB_blOut_l1);

  /* Outputs for Atomic SubSystem: '<S494>/Lib_RiseEdgeDet' */
  /* Logic: '<S510>/Logical Operator' incorporates:
   *  Logic: '<S510>/Logical Operator1'
   *  UnitDelay: '<S510>/Unit Delay'
   */
  DoorLckCtl_TrunkAutoLck = (rtb_RelationalOperator2_g1 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_oy));

  /* Update for UnitDelay: '<S510>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_oy = rtb_RelationalOperator2_g1;

  /* End of Outputs for SubSystem: '<S494>/Lib_RiseEdgeDet' */

  /* Update for Delay: '<S494>/Delay' incorporates:
   *  Constant: '<S494>/Constant'
   *  RelationalOperator: '<S494>/Relational Operator'
   *  UnitDelay: '<S407>/Unit Delay3'
   */
  AppSwcBcm_ARID_DEF.Delay_DSTATE_pn[0] = AppSwcBcm_ARID_DEF.Delay_DSTATE_pn[1];
  AppSwcBcm_ARID_DEF.Delay_DSTATE_pn[1] =
    (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_g == 1);
}

/* Output and update for atomic system: '<S456>/WelcomeLck' */
static void AppSwcBcm_WelcomeLck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator10_e;
  boolean rtb_RelationalOperator2_g1;
  boolean rtb_RelationalOperator3_bs;

  /* RelationalOperator: '<S495>/Relational Operator2' incorporates:
   *  Constant: '<S495>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_g1 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S495>/Relational Operator3' incorporates:
   *  Constant: '<S495>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_bs =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S495>/Relational Operator10' incorporates:
   *  Constant: '<S495>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator10_e = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->LckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S495>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator10_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_i);

  /* End of Outputs for SubSystem: '<S495>/Lib_RiseEdgeDet' */

  /* Logic: '<S495>/Logical Operator2' incorporates:
   *  Constant: '<S495>/Constant10'
   *  Logic: '<S495>/Logical Operator'
   *  Logic: '<S495>/Logical Operator1'
   *  Logic: '<S495>/Logical Operator3'
   *  RelationalOperator: '<S495>/Relational Operator'
   *  RelationalOperator: '<S495>/Relational Operator1'
   *  RelationalOperator: '<S495>/Relational Operator4'
   *  RelationalOperator: '<S495>/Relational Operator5'
   *  RelationalOperator: '<S495>/Relational Operator6'
   *  RelationalOperator: '<S495>/Relational Operator7'
   *  RelationalOperator: '<S495>/Relational Operator8'
   *  RelationalOperator: '<S495>/Relational Operator9'
   */
  DoorLckCtl_WelcomeLck = (rtb_LogicalOperator && ((DoorLckCtl_IllmndLckStsFb ==
    1) && (DoorLckCtl_EEIlluminatedEntrySys == 1) && (rtb_RelationalOperator2_g1
    || rtb_RelationalOperator3_bs) && (!DoorLckCtl_DriverDoorLckSw) &&
    (DoorLckCtl_DoorAjarFLSw && DoorLckCtl_DoorAjarFRSw &&
     DoorLckCtl_DoorAjarRRSw) && (DoorLckCtl_IllmndSts == 1) &&
    (!DoorLckCtl_DrvSeatSw) && DoorLckCtl_VehStop));
}

/* System initialize for atomic system: '<S442>/OutsideLck' */
static void AppSwcBcm_OutsideLck_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S456>/AutoLck' */
  AppSwcBcm_AutoLck_Init();

  /* End of SystemInitialize for SubSystem: '<S456>/AutoLck' */

  /* SystemInitialize for Atomic SubSystem: '<S456>/MechLck' */
  AppSwcBcm_MechLck_Init();

  /* End of SystemInitialize for SubSystem: '<S456>/MechLck' */
}

/* Output and update for atomic system: '<S442>/OutsideLck' */
static void AppSwcBcm_OutsideLck(void)
{
  /* Outputs for Atomic SubSystem: '<S456>/AutoLck' */
  AppSwcBcm_AutoLck();

  /* End of Outputs for SubSystem: '<S456>/AutoLck' */

  /* Outputs for Atomic SubSystem: '<S456>/MechLck' */
  AppSwcBcm_MechLck();

  /* End of Outputs for SubSystem: '<S456>/MechLck' */

  /* Outputs for Atomic SubSystem: '<S456>/PELck' */
  AppSwcBcm_PELck();

  /* End of Outputs for SubSystem: '<S456>/PELck' */

  /* Outputs for Atomic SubSystem: '<S456>/WelcomeLck' */
  AppSwcBcm_WelcomeLck();

  /* End of Outputs for SubSystem: '<S456>/WelcomeLck' */

  /* Outputs for Atomic SubSystem: '<S456>/RKELck' */
  AppSwcBcm_RKELck();

  /* End of Outputs for SubSystem: '<S456>/RKELck' */

  /* Outputs for Atomic SubSystem: '<S456>/TrunkAutoLck' */
  AppSwcBcm_TrunkAutoLck();

  /* End of Outputs for SubSystem: '<S456>/TrunkAutoLck' */

  /* Outputs for Atomic SubSystem: '<S456>/TboxLck' */
  AppSwcBcm_TboxLck();

  /* End of Outputs for SubSystem: '<S456>/TboxLck' */

  /* Logic: '<S456>/Logical Operator' */
  DoorLckCtl_OsLck = (DoorLckCtl_MechLck || DoorLckCtl_PELck ||
                      DoorLckCtl_AutoLck || DoorLckCtl_WelcomeLck ||
                      DoorLckCtl_RKELck || DoorLckCtl_TrunkAutoLck ||
                      DoorLckCtl_TboxLck);
}

/* System initialize for atomic system: '<S457>/MechUnlck' */
static void AppSwcBcm_MechUnlck_Init(void)
{
  /* InitializeConditions for Delay: '<S520>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = true;

  /* SystemInitialize for Chart: '<S512>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_lq);

  /* SystemInitialize for Chart: '<S512>/LIB_TPD_10ms2' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_e);
}

/* Output and update for atomic system: '<S457>/MechUnlck' */
static void AppSwcBcm_MechUnlck(void)
{
  boolean rtb_RelationalOperator3_j3;

  /* Chart: '<S512>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S512>/Constant'
   *  Constant: '<S512>/Constant40'
   *  Constant: '<S512>/Constant41'
   *  Constant: '<S512>/Constant42'
   *  Logic: '<S512>/Logical Operator1'
   *  RelationalOperator: '<S512>/Relational Operator1'
   *  RelationalOperator: '<S512>/Relational Operator2'
   *  RelationalOperator: '<S512>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 0,
    DoorLckCtl_Ts_C, true, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_lq,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_a);

  /* RelationalOperator: '<S512>/Relational Operator3' */
  rtb_RelationalOperator3_j3 = !DoorLckCtl_DriverDoorLckSw;

  /* Delay: '<S520>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_n) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_a0 = rtb_RelationalOperator3_j3;
  }

  /* Chart: '<S512>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S512>/Constant6'
   *  Constant: '<S512>/Constant7'
   *  Constant: '<S512>/Constant8'
   *  Constant: '<S512>/Constant9'
   *  RelationalOperator: '<S512>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_DoorProtUnlck, 0, 30, DoorLckCtl_Ts_C,
    false, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms2);

  /* Logic: '<S512>/Logical Operator' incorporates:
   *  Delay: '<S520>/Delay'
   *  Logic: '<S512>/Logical Operator2'
   *  Logic: '<S520>/Logical Operator'
   *  Logic: '<S520>/Logical Operator1'
   */
  DoorLckCtl_MechUnlck = ((!AppSwcBcm_ARID_DEF.LIB_bErrFlg_e) &&
    (rtb_RelationalOperator3_j3 && (!AppSwcBcm_ARID_DEF.Delay_DSTATE_a0)) &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_lq);

  /* Update for Delay: '<S520>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_a0 = rtb_RelationalOperator3_j3;
}

/* Output and update for atomic system: '<S457>/PEUnlck' */
static void AppSwcBcm_PEUnlck(void)
{
  boolean rtb_RelationalOperator7_ci;

  /* RelationalOperator: '<S513>/Relational Operator7' incorporates:
   *  Constant: '<S513>/Constant5'
   */
  rtb_RelationalOperator7_ci = (AppSwcBcm_ARID_DEF.UnitDelay2 == 2);

  /* Logic: '<S513>/Logical Operator1' incorporates:
   *  Constant: '<S513>/Constant2'
   *  Constant: '<S513>/Constant3'
   *  Constant: '<S513>/Constant4'
   *  Constant: '<S513>/Constant7'
   *  Constant: '<S513>/Constant8'
   *  Logic: '<S513>/Logical Operator2'
   *  Logic: '<S513>/Logical Operator3'
   *  Logic: '<S513>/Logical Operator4'
   *  Logic: '<S513>/Logical Operator5'
   *  Logic: '<S513>/Logical Operator6'
   *  RelationalOperator: '<S513>/Relational Operator1'
   *  RelationalOperator: '<S513>/Relational Operator2'
   *  RelationalOperator: '<S513>/Relational Operator3'
   *  RelationalOperator: '<S513>/Relational Operator4'
   *  RelationalOperator: '<S513>/Relational Operator5'
   *  RelationalOperator: '<S513>/Relational Operator6'
   *  RelationalOperator: '<S513>/Relational Operator8'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  DoorLckCtl_PEUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_mu &&
                        DoorLckCtl_DriverDoorLckSw &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0)) ||
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) &&
     rtb_RelationalOperator7_ci) || (rtb_RelationalOperator7_ci &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2))));
}

/* Output and update for atomic system: '<S457>/RKEUnlck' */
static void AppSwcBcm_RKEUnlck(void)
{
  sint32 tmp;
  boolean rtb_RelationalOperator_i3;

  /* RelationalOperator: '<S514>/Relational Operator' incorporates:
   *  Constant: '<S514>/Constant'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  rtb_RelationalOperator_i3 = (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 1);
  AppSwcBcm_ARID_DEF.Lib_blIn_in = rtb_RelationalOperator_i3;

  /* Chart: '<S514>/ClearRKECommd' incorporates:
   *  SubSystem: '<S521>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_in,
    &AppSwcBcm_ARID_DEF.LogicalOperator_j5,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_a);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_j5) {
    AppSwcBcm_ARID_DEF.flg_h = true;
    AppSwcBcm_ARID_DEF.Cnt_og = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_og - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_og - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_og = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_h && (AppSwcBcm_ARID_DEF.Cnt_og == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_h = false;
  }

  /* Logic: '<S514>/Logical Operator4' incorporates:
   *  Constant: '<S514>/Constant1'
   *  Constant: '<S514>/Constant2'
   *  Constant: '<S514>/Constant3'
   *  Constant: '<S514>/Constant4'
   *  Constant: '<S514>/Constant5'
   *  Constant: '<S514>/Constant6'
   *  Logic: '<S514>/Logical Operator'
   *  Logic: '<S514>/Logical Operator1'
   *  Logic: '<S514>/Logical Operator2'
   *  Logic: '<S514>/Logical Operator3'
   *  RelationalOperator: '<S514>/Relational Operator1'
   *  RelationalOperator: '<S514>/Relational Operator2'
   *  RelationalOperator: '<S514>/Relational Operator3'
   *  RelationalOperator: '<S514>/Relational Operator4'
   *  RelationalOperator: '<S514>/Relational Operator5'
   *  RelationalOperator: '<S514>/Relational Operator6'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_RelationalOperator_i3 = (rtb_RelationalOperator_i3 &&
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) ||
     (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
       (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
       (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2)) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 2))));

  /* Outputs for Atomic SubSystem: '<S514>/Lib_RiseEdgeDet' */
  /* Logic: '<S522>/Logical Operator' incorporates:
   *  Logic: '<S522>/Logical Operator1'
   *  UnitDelay: '<S522>/Unit Delay'
   */
  DoorLckCtl_RKEUnlck = (rtb_RelationalOperator_i3 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o1));

  /* Update for UnitDelay: '<S522>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o1 = rtb_RelationalOperator_i3;

  /* End of Outputs for SubSystem: '<S514>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S457>/TboxUnlck' */
static void AppSwcBcm_TboxUnlck(void)
{
  boolean rtb_UnitDelay_k3;

  /* UnitDelay: '<S525>/Unit Delay' incorporates:
   *  Constant: '<S515>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S515>/Relational Operator'
   */
  rtb_UnitDelay_k3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                      ->VIPM_TBoxRmtLck_enum == 2);

  /* Logic: '<S515>/Logical Operator3' incorporates:
   *  Constant: '<S515>/Constant1'
   *  Constant: '<S515>/Constant2'
   *  Constant: '<S515>/Constant3'
   *  Constant: '<S515>/Constant4'
   *  Constant: '<S515>/Constant5'
   *  Logic: '<S515>/Logical Operator'
   *  Logic: '<S515>/Logical Operator1'
   *  Logic: '<S515>/Logical Operator2'
   *  RelationalOperator: '<S515>/Relational Operator1'
   *  RelationalOperator: '<S515>/Relational Operator2'
   *  RelationalOperator: '<S515>/Relational Operator3'
   *  RelationalOperator: '<S515>/Relational Operator4'
   *  RelationalOperator: '<S515>/Relational Operator5'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_UnitDelay_k3 = (rtb_UnitDelay_k3 && ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) ||
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 2) &&
     ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5)))));

  /* Outputs for Atomic SubSystem: '<S515>/Lib_RiseEdgeDet' */
  /* Logic: '<S525>/Logical Operator' incorporates:
   *  Logic: '<S525>/Logical Operator1'
   *  UnitDelay: '<S525>/Unit Delay'
   */
  DoorLckCtl_TboxUnlck = (rtb_UnitDelay_k3 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f1));

  /* Update for UnitDelay: '<S525>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f1 = rtb_UnitDelay_k3;

  /* End of Outputs for SubSystem: '<S515>/Lib_RiseEdgeDet' */
}

/* System initialize for atomic system: '<S457>/TrunkUnlck' */
static void AppSwcBcm_TrunkUnlck_Init(void)
{
  /* SystemInitialize for Chart: '<S516>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_b);
}

/* Output and update for atomic system: '<S457>/TrunkUnlck' */
static void AppSwcBcm_TrunkUnlck(void)
{
  boolean rtb_LogicalOperator1_g;
  boolean rtb_RelationalOperator5;
  boolean rtb_UnitDelay_f;

  /* Chart: '<S516>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S516>/Constant'
   *  Constant: '<S516>/Constant2'
   *  Constant: '<S516>/Constant3'
   *  Constant: '<S516>/Constant4'
   *  RelationalOperator: '<S516>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  AppSwcBcm_LIB_TPD_10ms(AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 3,
    DoorLckCtl_TrunkUnlckTimValid_C, DoorLckCtl_TrunkUnlckTimInvalid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_e);

  /* Logic: '<S516>/Logical Operator1' incorporates:
   *  Constant: '<S516>/Constant6'
   *  RelationalOperator: '<S516>/Relational Operator3'
   */
  rtb_LogicalOperator1_g = ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_b && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S516>/Lib_RiseEdgeDet1' */
  /* Logic: '<S527>/Logical Operator' incorporates:
   *  Logic: '<S527>/Logical Operator1'
   *  UnitDelay: '<S527>/Unit Delay'
   */
  DoorLckCtl_TrunkRKEUnlck = (rtb_LogicalOperator1_g &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hz));

  /* Update for UnitDelay: '<S527>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hz = rtb_LogicalOperator1_g;

  /* End of Outputs for SubSystem: '<S516>/Lib_RiseEdgeDet1' */

  /* RelationalOperator: '<S516>/Relational Operator1' incorporates:
   *  Constant: '<S516>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_LogicalOperator1_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUTrnkLckSwCtrl_enum == 1);

  /* RelationalOperator: '<S516>/Relational Operator5' incorporates:
   *  Constant: '<S516>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* UnitDelay: '<S529>/Unit Delay' incorporates:
   *  Constant: '<S516>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S516>/Relational Operator6'
   */
  rtb_UnitDelay_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S516>/Lib_RiseEdgeDet2' */

  /* Logic: '<S516>/Logical Operator3' incorporates:
   *  Constant: '<S516>/Constant5'
   *  Constant: '<S516>/Constant7'
   *  Logic: '<S516>/Logical Operator2'
   *  RelationalOperator: '<S516>/Relational Operator2'
   *  RelationalOperator: '<S516>/Relational Operator4'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_gy = AppSwcBcm_Lib_RiseEdgeDet
    (DoorLckCtl_VehStop && rtb_LogicalOperator1_g &&
     (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) &&
     (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && (rtb_RelationalOperator5 ||
      rtb_UnitDelay_f), &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_a);

  /* End of Outputs for SubSystem: '<S516>/Lib_RiseEdgeDet2' */

  /* UnitDelay: '<S529>/Unit Delay' incorporates:
   *  Constant: '<S516>/Constant10'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S516>/Relational Operator7'
   */
  rtb_UnitDelay_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                     ->VIPM_TBoxRmtLck_enum == 3);

  /* Logic: '<S516>/Logical Operator4' incorporates:
   *  Constant: '<S516>/Constant11'
   *  RelationalOperator: '<S516>/Relational Operator8'
   */
  rtb_LogicalOperator1_g = (rtb_UnitDelay_f && (AppSwcBcm_ARID_DEF.UnitDelay2 ==
    0) && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S516>/Lib_RiseEdgeDet3' */
  /* Logic: '<S529>/Logical Operator' incorporates:
   *  Logic: '<S529>/Logical Operator1'
   *  UnitDelay: '<S529>/Unit Delay'
   */
  DoorLckCtl_TrunkTboxUnlck = (rtb_LogicalOperator1_g &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mr));

  /* Update for UnitDelay: '<S529>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mr = rtb_LogicalOperator1_g;

  /* End of Outputs for SubSystem: '<S516>/Lib_RiseEdgeDet3' */

  /* Logic: '<S516>/Logical Operator' */
  DoorLckCtl_TrunkUnlck = (DoorLckCtl_TrunkRKEUnlck ||
    AppSwcBcm_ARID_DEF.LogicalOperator_gy || DoorLckCtl_TrunkTboxUnlck);
}

/* Output and update for atomic system: '<S457>/WelcomeUnlck' */
static void AppSwcBcm_WelcomeUnlck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator4_nr0;

  /* RelationalOperator: '<S517>/Relational Operator4' incorporates:
   *  Constant: '<S517>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator4_nr0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->UnlckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S517>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator4_nr0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p5);

  /* End of Outputs for SubSystem: '<S517>/Lib_RiseEdgeDet' */

  /* Logic: '<S517>/Logical Operator1' incorporates:
   *  Constant: '<S517>/Constant1'
   *  Constant: '<S517>/Constant4'
   *  Constant: '<S517>/Constant5'
   *  Constant: '<S517>/Constant8'
   *  Logic: '<S517>/Logical Operator'
   *  RelationalOperator: '<S517>/Relational Operator'
   *  RelationalOperator: '<S517>/Relational Operator1'
   *  RelationalOperator: '<S517>/Relational Operator2'
   *  RelationalOperator: '<S517>/Relational Operator3'
   *  RelationalOperator: '<S517>/Relational Operator5'
   */
  DoorLckCtl_WelcomeUnlck = (rtb_LogicalOperator && (DoorLckCtl_DriverDoorLckSw &&
    (DoorLckCtl_IllmndUnlockStsFb == 1) && (DoorLckCtl_EEIlluminatedEntrySys ==
    1) && (AppSwcBcm_ARID_DEF.UnitDelay2 == 0) && (DoorLckCtl_IllmndSts == 1)));
}

/* System initialize for atomic system: '<S442>/OutsideUnlck' */
static void AppSwcBcm_OutsideUnlck_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S457>/MechUnlck' */
  AppSwcBcm_MechUnlck_Init();

  /* End of SystemInitialize for SubSystem: '<S457>/MechUnlck' */

  /* SystemInitialize for Atomic SubSystem: '<S457>/TrunkUnlck' */
  AppSwcBcm_TrunkUnlck_Init();

  /* End of SystemInitialize for SubSystem: '<S457>/TrunkUnlck' */
}

/* Output and update for atomic system: '<S442>/OutsideUnlck' */
static void AppSwcBcm_OutsideUnlck(void)
{
  /* Outputs for Atomic SubSystem: '<S457>/RKEUnlck' */
  AppSwcBcm_RKEUnlck();

  /* End of Outputs for SubSystem: '<S457>/RKEUnlck' */

  /* Outputs for Atomic SubSystem: '<S457>/PEUnlck' */
  AppSwcBcm_PEUnlck();

  /* End of Outputs for SubSystem: '<S457>/PEUnlck' */

  /* Outputs for Atomic SubSystem: '<S457>/WelcomeUnlck' */
  AppSwcBcm_WelcomeUnlck();

  /* End of Outputs for SubSystem: '<S457>/WelcomeUnlck' */

  /* Outputs for Atomic SubSystem: '<S457>/MechUnlck' */
  AppSwcBcm_MechUnlck();

  /* End of Outputs for SubSystem: '<S457>/MechUnlck' */

  /* Outputs for Atomic SubSystem: '<S457>/TboxUnlck' */
  AppSwcBcm_TboxUnlck();

  /* End of Outputs for SubSystem: '<S457>/TboxUnlck' */

  /* Logic: '<S457>/Logical Operator' */
  DoorLckCtl_OsUnlck = (DoorLckCtl_RKEUnlck || DoorLckCtl_PEUnlck ||
                        DoorLckCtl_WelcomeUnlck || DoorLckCtl_MechUnlck ||
                        DoorLckCtl_TboxUnlck);

  /* Outputs for Atomic SubSystem: '<S457>/TrunkUnlck' */
  AppSwcBcm_TrunkUnlck();

  /* End of Outputs for SubSystem: '<S457>/TrunkUnlck' */
}

/* Output and update for atomic system: '<S442>/PECtl' */
static void AppSwcBcm_PECtl(void)
{
  sint32 tmp;
  boolean rtb_RelationalOperator2_l4;
  boolean rtb_RelationalOperator6_eq;

  /* RelationalOperator: '<S458>/Relational Operator2' incorporates:
   *  Constant: '<S458>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator2_l4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->DrvPEAuthentAcsd == 1);

  /* RelationalOperator: '<S458>/Relational Operator6' incorporates:
   *  Constant: '<S458>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator6_eq = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->FRPEAuthentAcsd == 1);

  /* Logic: '<S458>/Logical Operator1' incorporates:
   *  Constant: '<S458>/Constant5'
   *  Logic: '<S458>/Logical Operator'
   *  Logic: '<S458>/Logical Operator3'
   *  RelationalOperator: '<S458>/Relational Operator'
   *  RelationalOperator: '<S458>/Relational Operator1'
   *  RelationalOperator: '<S458>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_jk = ((DoorLckCtl_DrvPESw || DoorLckCtl_PsgPESw) &&
    (rtb_RelationalOperator2_l4 || rtb_RelationalOperator6_eq) &&
    (DoorLckCtl_EEKeyEntry == 1));

  /* Chart: '<S458>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S531>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jk,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ai,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ai) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_by + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_by + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_by = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_h = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_h + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_h + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_h = (uint16)tmp;
  }

  /* Constant: '<S458>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt2_h >= DoorLckCtl_PEProtIntvlTim_C) {
    AppSwcBcm_ARID_DEF.Cnt_by = 0U;
    AppSwcBcm_ARID_DEF.LIB_blOut_h = false;
  }

  /* End of Constant: '<S458>/Constant2' */

  /* Constant: '<S458>/Constant3' */
  AppSwcBcm_ARID_DEF.LIB_blOut_h = ((AppSwcBcm_ARID_DEF.Cnt_by >=
    DoorLckCtl_PEProtCnt_C) || AppSwcBcm_ARID_DEF.LIB_blOut_h);

  /* Outputs for Atomic SubSystem: '<S458>/Lib_RiseEdgeDet' */
  /* Switch: '<S458>/Switch' */
  AppSwcBcm_ARID_DEF.LogicalOperator_mu = AppSwcBcm_Lib_RiseEdgeDet
    ((!AppSwcBcm_ARID_DEF.LIB_blOut_h) && AppSwcBcm_ARID_DEF.Lib_blIn_jk,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ct);

  /* End of Outputs for SubSystem: '<S458>/Lib_RiseEdgeDet' */
}

/* System initialize for atomic system: '<S442>/ParkUnlckSet' */
static void AppSwcBcm_ParkUnlckSet_Init(void)
{
  /* InitializeConditions for Delay: '<S459>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = true;
}

/* Output and update for atomic system: '<S442>/ParkUnlckSet' */
static void AppSwcBcm_ParkUnlckSet(void)
{
  uint8 rtb_Switch1_ea;

  /* Switch: '<S459>/Switch1' incorporates:
   *  Constant: '<S459>/Constant1'
   *  RelationalOperator: '<S459>/Relational Operator1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S459>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_ea = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUParkAutoUnlckSet_enum;
  } else {
    /* Switch: '<S459>/Switch1' incorporates:
     *  Constant: '<S459>/Constant4'
     */
    rtb_Switch1_ea = 0U;
  }

  /* End of Switch: '<S459>/Switch1' */

  /* Delay: '<S459>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_c) {
    /* Switch: '<S459>/Switch2' incorporates:
     *  Constant: '<S459>/Constant5'
     *  Constant: '<S459>/Constant6'
     *  RelationalOperator: '<S459>/Relational Operator3'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_a = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_a =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb;
    }

    /* End of Switch: '<S459>/Switch2' */
  }

  /* MultiPortSwitch: '<S459>/Multiport Switch' incorporates:
   *  Constant: '<S459>/Constant2'
   *  Constant: '<S459>/Constant3'
   *  Delay: '<S459>/Delay'
   */
  switch (rtb_Switch1_ea) {
   case 1:
    DoorLckCtl_ParkAutoUnlockSetFb = 0U;
    break;

   case 2:
    DoorLckCtl_ParkAutoUnlockSetFb = 1U;
    break;

   default:
    DoorLckCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_a;
    break;
  }

  /* End of MultiPortSwitch: '<S459>/Multiport Switch' */

  /* Update for Delay: '<S459>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_a = DoorLckCtl_ParkAutoUnlockSetFb;
}

/* ConstCode for atomic system: '<S442>/SpdLck' */
static void AppSwcBcm_SpdLck_l_Const(void)
{
  /* ConstCode for Constant: '<S460>/Constant8' */
  DoorLckCtl_SpdCtlLckSet = 1U;
}

/* Output and update for atomic system: '<S442>/TboxLckFb' */
static void AppSwcBcm_TboxLckFb(void)
{
  sint32 tmp;

  /* Chart: '<S461>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c12_DoorLckCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c12_DoorLckCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Init1;
    DoorLckCtl_RemoteLockFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_jv = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib) {
     case AppSwcBcm_IN_Fail1:
      DoorLckCtl_RemoteLockFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_jv >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Init1;
        DoorLckCtl_RemoteLockFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_jv = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_jv++;
      }
      break;

     case AppSwcBcm_IN_Init1:
      DoorLckCtl_RemoteLockFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_iq =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtLck_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtLck_enum == 2));

      /* Outputs for Function Call SubSystem: '<S535>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_iq,
        &AppSwcBcm_ARID_DEF.LogicalOperator_db,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c0);

      /* End of Outputs for SubSystem: '<S535>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_db) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Wait1;
      }
      break;

     case AppSwcBcm_IN_Suc1:
      DoorLckCtl_RemoteLockFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_jv >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Init1;
        DoorLckCtl_RemoteLockFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_jv = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_jv++;
      }
      break;

     default:
      /* case IN_Wait1: */
      if (DoorLckCtl_TboxLck || DoorLckCtl_TboxUnlck ||
          DoorLckCtl_TrunkTboxUnlck) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Suc1;
        DoorLckCtl_RemoteLockFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_jv + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_jv + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_jv = (uint8)tmp;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_TBoxRmtLck_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c12_DoorLckCtl_Lib = AppSwcBcm_IN_Fail1;
        DoorLckCtl_RemoteLockFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_jv + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_jv + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_jv = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S461>/Chart' */
}

/* System initialize for atomic system: '<S407>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S442>/IllmndLckSet' */
  AppSwcBcm_IllmndLckSet_Init();

  /* End of SystemInitialize for SubSystem: '<S442>/IllmndLckSet' */

  /* SystemInitialize for Atomic SubSystem: '<S442>/IllmndUnlckSet' */
  AppSwcBcm_IllmndUnlckSet_Init();

  /* End of SystemInitialize for SubSystem: '<S442>/IllmndUnlckSet' */

  /* SystemInitialize for Atomic SubSystem: '<S442>/InsideLck' */
  AppSwcBcm_InsideLck_Init();

  /* End of SystemInitialize for SubSystem: '<S442>/InsideLck' */

  /* SystemInitialize for Atomic SubSystem: '<S442>/OutsideLck' */
  AppSwcBcm_OutsideLck_Init();

  /* End of SystemInitialize for SubSystem: '<S442>/OutsideLck' */

  /* SystemInitialize for Atomic SubSystem: '<S442>/OutsideUnlck' */
  AppSwcBcm_OutsideUnlck_Init();

  /* End of SystemInitialize for SubSystem: '<S442>/OutsideUnlck' */

  /* SystemInitialize for Atomic SubSystem: '<S442>/ParkUnlckSet' */
  AppSwcBcm_ParkUnlckSet_Init();

  /* End of SystemInitialize for SubSystem: '<S442>/ParkUnlckSet' */
}

/* Outputs for atomic system: '<S407>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic(void)
{
  sint32 tmp;

  /* Outputs for Atomic SubSystem: '<S442>/PECtl' */
  AppSwcBcm_PECtl();

  /* End of Outputs for SubSystem: '<S442>/PECtl' */

  /* Outputs for Atomic SubSystem: '<S442>/IllmndLckSet' */
  AppSwcBcm_IllmndLckSet();

  /* End of Outputs for SubSystem: '<S442>/IllmndLckSet' */

  /* Outputs for Atomic SubSystem: '<S442>/OutsideLck' */
  AppSwcBcm_OutsideLck();

  /* End of Outputs for SubSystem: '<S442>/OutsideLck' */

  /* Outputs for Atomic SubSystem: '<S442>/InsideLck' */
  AppSwcBcm_InsideLck();

  /* End of Outputs for SubSystem: '<S442>/InsideLck' */

  /* Outputs for Atomic SubSystem: '<S442>/AntiLckProt' */
  AppSwcBcm_AntiLckProt();

  /* End of Outputs for SubSystem: '<S442>/AntiLckProt' */

  /* Outputs for Atomic SubSystem: '<S442>/IllmndUnlckSet' */
  AppSwcBcm_IllmndUnlckSet();

  /* End of Outputs for SubSystem: '<S442>/IllmndUnlckSet' */

  /* Outputs for Atomic SubSystem: '<S442>/OutsideUnlck' */
  AppSwcBcm_OutsideUnlck();

  /* End of Outputs for SubSystem: '<S442>/OutsideUnlck' */

  /* Chart: '<S442>/ClearRKECommd1' */
  if (DoorLckCtl_TrunkUnlck) {
    AppSwcBcm_ARID_DEF.flg_n = true;
    AppSwcBcm_ARID_DEF.Cnt_bi = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_bi - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_bi - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_bi = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_n && (AppSwcBcm_ARID_DEF.Cnt_bi == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_n = false;
  }

  /* End of Chart: '<S442>/ClearRKECommd1' */

  /* Outputs for Atomic SubSystem: '<S442>/ParkUnlckSet' */
  AppSwcBcm_ParkUnlckSet();

  /* End of Outputs for SubSystem: '<S442>/ParkUnlckSet' */

  /* Outputs for Atomic SubSystem: '<S442>/InsideUnlck' */
  AppSwcBcm_InsideUnlck();

  /* End of Outputs for SubSystem: '<S442>/InsideUnlck' */

  /* Outputs for Atomic SubSystem: '<S442>/MotorProt' */
  AppSwcBcm_MotorProt();

  /* End of Outputs for SubSystem: '<S442>/MotorProt' */

  /* Outputs for Atomic SubSystem: '<S442>/TboxLckFb' */
  AppSwcBcm_TboxLckFb();

  /* End of Outputs for SubSystem: '<S442>/TboxLckFb' */
}

/* ConstCode for atomic system: '<S407>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S442>/SpdLck' */
  AppSwcBcm_SpdLck_l_Const();

  /* End of ConstCode for SubSystem: '<S442>/SpdLck' */
}

/*
 * Output and update for atomic system:
 *    '<S446>/Bit Shift12'
 *    '<S653>/Bit Shift11'
 */
static uint16 AppSwcBcm_BitShift12_e(uint16 rtu_u)
{
  /* MATLAB Function: '<S539>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 11);
}

/*
 * Output and update for atomic system:
 *    '<S446>/Bit Shift4'
 *    '<S653>/Bit Shift2'
 */
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u)
{
  /* MATLAB Function: '<S545>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S446>/Bit Shift6'
 *    '<S653>/Bit Shift8'
 */
static uint16 AppSwcBcm_BitShift6(uint16 rtu_u)
{
  /* MATLAB Function: '<S547>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S446>/Bit Shift7'
 *    '<S653>/Bit Shift9'
 */
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u)
{
  /* MATLAB Function: '<S548>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 6);
}

/*
 * Output and update for atomic system:
 *    '<S446>/Bit Shift8'
 *    '<S653>/Bit Shift3'
 */
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u)
{
  /* MATLAB Function: '<S549>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S446>/Bit Shift9'
 *    '<S653>/Bit Shift10'
 */
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u)
{
  /* MATLAB Function: '<S550>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 8);
}

/* Output and update for atomic system: '<S407>/SignalProcess' */
static void AppSwcBcm_SignalProcess_d(void)
{
  uint16 rtb_Switch12_k;
  uint16 tmp;
  boolean rtb_RelationalOperator1_l;
  boolean rtb_RelationalOperator_p;
  boolean rtb_Switch1_o4;

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift1' */
  /* Constant: '<S446>/Constant5' */
  rtb_Switch12_k = AppSwcBcm_BitShift1_k(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift1' */

  /* Switch: '<S446>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND1'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch1' incorporates:
     *  Constant: '<S446>/Constant4'
     */
    rtb_Switch1_o4 = DoorLckCtl_DoorAjarFLVal_C;
  } else {
    /* Switch: '<S446>/Switch1' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion1'
     */
    rtb_Switch1_o4 = (BSW_J321DoorAjarFL != 0);
  }

  /* End of Switch: '<S446>/Switch1' */

  /* Chart: '<S446>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S446>/Constant1'
   *  Constant: '<S446>/Constant2'
   *  Constant: '<S446>/Constant3'
   *  DataTypeConversion: '<S446>/Data Type Conversion17'
   */
  if (!AppSwcBcm_ARID_DEF.flg_dt) {
    DoorLckCtl_DoorAjarFLSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarFLSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_dt = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l >= (float32)
         DoorLckCtl_DoorAjarFLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l++;
      AppSwcBcm_ARID_DEF.cnt_heal_e1 = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e1 >= (float32)
        DoorLckCtl_DoorAjarFLTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarFLSw = false;
    } else if (DoorLckCtl_DoorAjarFLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_e1++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift2' */
  /* Constant: '<S446>/Constant10' */
  rtb_Switch12_k = AppSwcBcm_BitShift2(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift2' */

  /* Switch: '<S446>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND2'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch2' incorporates:
     *  Constant: '<S446>/Constant9'
     */
    rtb_Switch1_o4 = DoorLckCtl_DoorAjarFRVal_C;
  } else {
    /* Switch: '<S446>/Switch2' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion2'
     */
    rtb_Switch1_o4 = (BSW_J310DoorAjarFR != 0);
  }

  /* End of Switch: '<S446>/Switch2' */

  /* Chart: '<S446>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S446>/Constant6'
   *  Constant: '<S446>/Constant7'
   *  Constant: '<S446>/Constant8'
   *  DataTypeConversion: '<S446>/Data Type Conversion16'
   */
  if (!AppSwcBcm_ARID_DEF.flg_i) {
    DoorLckCtl_DoorAjarFRSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarFRSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_i = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_pw >= (float32)
         DoorLckCtl_DoorAjarFRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_pw++;
      AppSwcBcm_ARID_DEF.cnt_heal_cl = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_pw = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cl >= (float32)
        DoorLckCtl_DoorAjarFRTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarFRSw = false;
    } else if (DoorLckCtl_DoorAjarFRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cl++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift5' */
  /* Constant: '<S446>/Constant59' */
  rtb_Switch12_k = AppSwcBcm_BitShift3(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift5' */

  /* Switch: '<S446>/Switch5' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND5'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch5' incorporates:
     *  Constant: '<S446>/Constant60'
     */
    rtb_Switch1_o4 = DoorLckCtl_DriverDoorLckVal_C;
  } else {
    /* Switch: '<S446>/Switch5' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion5'
     */
    rtb_Switch1_o4 = (BSW_J335DriverDoorLck != 0);
  }

  /* End of Switch: '<S446>/Switch5' */

  /* Chart: '<S446>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S446>/Constant46'
   *  Constant: '<S446>/Constant47'
   *  Constant: '<S446>/Constant49'
   *  DataTypeConversion: '<S446>/Data Type Conversion18'
   */
  if (!AppSwcBcm_ARID_DEF.flg_pj) {
    DoorLckCtl_DriverDoorLckSw =
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DriverDoorLckSw != 0);
    AppSwcBcm_ARID_DEF.flg_pj = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d3 >= (float32)
         DoorLckCtl_DriverDoorLckTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DriverDoorLckTimValid_C != 0xFFFF)) {
      DoorLckCtl_DriverDoorLckSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d3++;
      AppSwcBcm_ARID_DEF.cnt_heal_h = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d3 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h >= (float32)
        DoorLckCtl_DriverDoorLckTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DriverDoorLckSw = false;
    } else if (DoorLckCtl_DriverDoorLckTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_h++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift3' */
  /* Constant: '<S446>/Constant11' */
  rtb_Switch12_k = AppSwcBcm_BitShift1_m(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift3' */

  /* Switch: '<S446>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND3'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch3' incorporates:
     *  Constant: '<S446>/Constant12'
     */
    rtb_Switch1_o4 = DoorLckCtl_DrvPEVal_C;
  } else {
    /* Switch: '<S446>/Switch3' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion3'
     *  Logic: '<S446>/Logical Operator6'
     */
    rtb_Switch1_o4 = (BSW_J338DrvPE == 0);
  }

  /* End of Switch: '<S446>/Switch3' */

  /* Chart: '<S446>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S446>/Constant25'
   *  Constant: '<S446>/Constant26'
   *  Constant: '<S446>/Constant27'
   *  Constant: '<S446>/Constant77'
   */
  if (!AppSwcBcm_ARID_DEF.flg_ot) {
    DoorLckCtl_DrvPESw = false;
    AppSwcBcm_ARID_DEF.flg_ot = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b >= (float32)DoorLckCtl_DrvPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_DrvPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_DrvPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b++;
      AppSwcBcm_ARID_DEF.cnt_heal_nd = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_nd >= (float32)DoorLckCtl_DrvPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DrvPESw = false;
    } else if (DoorLckCtl_DrvPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_nd++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift4' */
  /* Constant: '<S446>/Constant13' */
  rtb_Switch12_k = AppSwcBcm_BitShift4(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift4' */

  /* Switch: '<S446>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND4'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch4' incorporates:
     *  Constant: '<S446>/Constant14'
     */
    rtb_Switch1_o4 = DoorLckCtl_PsgPEVal_C;
  } else {
    /* Switch: '<S446>/Switch4' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion4'
     *  Logic: '<S446>/Logical Operator7'
     */
    rtb_Switch1_o4 = (BSW_J337PsgPE == 0);
  }

  /* End of Switch: '<S446>/Switch4' */

  /* Chart: '<S446>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S446>/Constant28'
   *  Constant: '<S446>/Constant29'
   *  Constant: '<S446>/Constant30'
   *  Constant: '<S446>/Constant78'
   */
  if (!AppSwcBcm_ARID_DEF.flg_o) {
    DoorLckCtl_PsgPESw = false;
    AppSwcBcm_ARID_DEF.flg_o = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gu >= (float32)DoorLckCtl_PsgPETimValid_C
         / (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_PsgPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gu++;
      AppSwcBcm_ARID_DEF.cnt_heal_ju = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gu = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ju >= (float32)DoorLckCtl_PsgPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_PsgPESw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ju++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift6' */
  /* Constant: '<S446>/Constant15' */
  rtb_Switch12_k = AppSwcBcm_BitShift6(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift6' */

  /* Switch: '<S446>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND6'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch6' incorporates:
     *  Constant: '<S446>/Constant16'
     */
    rtb_Switch1_o4 = DoorLckCtl_TrunkSwVal_C;
  } else {
    /* Switch: '<S446>/Switch6' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion6'
     */
    rtb_Switch1_o4 = (BSW_J336Trunk != 0);
  }

  /* End of Switch: '<S446>/Switch6' */

  /* Chart: '<S446>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S446>/Constant31'
   *  Constant: '<S446>/Constant32'
   *  Constant: '<S446>/Constant33'
   *  DataTypeConversion: '<S446>/Data Type Conversion15'
   */
  if (!AppSwcBcm_ARID_DEF.flg_d) {
    DoorLckCtl_TrunkSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkSw != 0);
    AppSwcBcm_ARID_DEF.flg_d = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_g >= (float32)DoorLckCtl_PsgPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_TrunkSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_g++;
      AppSwcBcm_ARID_DEF.cnt_heal_fz = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_g = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_fz >= (float32)DoorLckCtl_PsgPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_TrunkSw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_fz++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift7' */
  /* Constant: '<S446>/Constant17' */
  rtb_Switch12_k = AppSwcBcm_BitShift7(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift7' */

  /* Switch: '<S446>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND7'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch7' incorporates:
     *  Constant: '<S446>/Constant18'
     */
    rtb_Switch1_o4 = DoorLckCtl_DoorAjarRLVal_C;
  } else {
    /* Switch: '<S446>/Switch7' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion7'
     */
    rtb_Switch1_o4 = (BSW_J320DoorAjarRL != 0);
  }

  /* End of Switch: '<S446>/Switch7' */

  /* Chart: '<S446>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S446>/Constant34'
   *  Constant: '<S446>/Constant35'
   *  Constant: '<S446>/Constant36'
   *  DataTypeConversion: '<S446>/Data Type Conversion14'
   */
  if (!AppSwcBcm_ARID_DEF.flg_e) {
    DoorLckCtl_DoorAjarRLSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarRLSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_e = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_j0 >= (float32)
         DoorLckCtl_DoorAjarRLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j0++;
      AppSwcBcm_ARID_DEF.cnt_heal_ip = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j0 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ip >= (float32)
        DoorLckCtl_DoorAjarRLTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarRLSw = false;
    } else if (DoorLckCtl_DoorAjarRLTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ip++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift8' */
  /* Constant: '<S446>/Constant19' */
  rtb_Switch12_k = AppSwcBcm_BitShift8(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift8' */

  /* Switch: '<S446>/Switch8' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND8'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch8' incorporates:
     *  Constant: '<S446>/Constant20'
     */
    rtb_Switch1_o4 = DoorLckCtl_DoorAjarRRVal_C;
  } else {
    /* Switch: '<S446>/Switch8' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion8'
     */
    rtb_Switch1_o4 = (BSW_J36DoorAjarRR != 0);
  }

  /* End of Switch: '<S446>/Switch8' */

  /* Chart: '<S446>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S446>/Constant37'
   *  Constant: '<S446>/Constant38'
   *  Constant: '<S446>/Constant39'
   *  DataTypeConversion: '<S446>/Data Type Conversion13'
   */
  if (!AppSwcBcm_ARID_DEF.flg_g) {
    DoorLckCtl_DoorAjarRRSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorAjarRRSw !=
      0);
    AppSwcBcm_ARID_DEF.flg_g = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_mw >= (float32)
         DoorLckCtl_DoorAjarRRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_mw++;
      AppSwcBcm_ARID_DEF.cnt_heal_cj = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_mw = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cj >= (float32)
        DoorLckCtl_DoorAjarRRTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarRRSw = false;
    } else if (DoorLckCtl_DoorAjarRRTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cj++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms7' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift9' */
  /* Constant: '<S446>/Constant21' */
  rtb_Switch12_k = AppSwcBcm_BitShift9(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift9' */

  /* Switch: '<S446>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND9'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S446>/Switch9' incorporates:
     *  Constant: '<S446>/Constant22'
     */
    rtb_Switch1_o4 = DoorLckCtl_TrunkAjarVal_C;
  } else {
    /* Switch: '<S446>/Switch9' incorporates:
     *  DataTypeConversion: '<S446>/Data Type Conversion9'
     */
    rtb_Switch1_o4 = (BSW_J37TrunkAjar != 0);
  }

  /* End of Switch: '<S446>/Switch9' */

  /* Chart: '<S446>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S446>/Constant40'
   *  Constant: '<S446>/Constant41'
   *  Constant: '<S446>/Constant42'
   *  DataTypeConversion: '<S446>/Data Type Conversion12'
   */
  if (!AppSwcBcm_ARID_DEF.flg) {
    DoorLckCtl_TrunkAjarSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkAjarSw != 0);
    AppSwcBcm_ARID_DEF.flg = true;
  }

  if (rtb_Switch1_o4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_i >= (float32)
         DoorLckCtl_TrunkAjarTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_TrunkAjarTimValid_C != 0xFFFF)) {
      DoorLckCtl_TrunkAjarSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_i++;
      AppSwcBcm_ARID_DEF.cnt_heal_n0 = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_i = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n0 >= (float32)
        DoorLckCtl_TrunkAjarTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_TrunkAjarSw = false;
    } else if (DoorLckCtl_TrunkAjarTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n0++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift12' */
  /* Constant: '<S446>/Constant62' */
  rtb_Switch12_k = AppSwcBcm_BitShift12_e(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S446>/Bit Shift12' */

  /* Switch: '<S446>/Switch12' incorporates:
   *  Constant: '<S446>/Constant63'
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND12'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    tmp = DoorLckCtl_DrvSeatResisVal_C;
  } else {
    tmp = BSW_J112DrvSeatResis;
  }

  /* Chart: '<S446>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S446>/Constant64'
   *  Constant: '<S446>/Constant65'
   *  Constant: '<S446>/Constant66'
   *  Constant: '<S446>/Constant67'
   *  DataTypeConversion: '<S446>/Data Type Conversion'
   *  RelationalOperator: '<S446>/Relational Operator6'
   *  Switch: '<S446>/Switch12'
   */
  if (!AppSwcBcm_ARID_DEF.flg_p) {
    DoorLckCtl_DrvSeatSw = (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DrvSeatSw != 0);
    AppSwcBcm_ARID_DEF.flg_p = true;
  }

  if (tmp <= DoorLckCtl_DrvSeatResisMin_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d >= (float32)
         DoorLckCtl_DrvSeatTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DrvSeatTimValid_C != 0xFFFF)) {
      DoorLckCtl_DrvSeatSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d++;
      AppSwcBcm_ARID_DEF.cnt_heal_jh = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_jh >= (float32)
        DoorLckCtl_DrvSeatTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DrvSeatSw = false;
    } else if (DoorLckCtl_DrvSeatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_jh++;
    }
  }

  /* End of Chart: '<S446>/LIB_TPD_10ms11' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift13' */
  /* Switch: '<S446>/Switch13' incorporates:
   *  Constant: '<S446>/Constant71'
   *  Constant: '<S446>/Constant72'
   *  MATLAB Function: '<S540>/bit_shift'
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND13'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 12 & 1U) != 0U) {
    DoorLckCtl_EEKeyEntry = DoorLckCtl_EEKeyEntry_C;
  } else {
    DoorLckCtl_EEKeyEntry = BSW_EEKeyEntry;
  }

  /* End of Switch: '<S446>/Switch13' */
  /* End of Outputs for SubSystem: '<S446>/Bit Shift13' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift14' */
  /* Switch: '<S446>/Switch14' incorporates:
   *  Constant: '<S446>/Constant73'
   *  Constant: '<S446>/Constant74'
   *  MATLAB Function: '<S541>/bit_shift'
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND14'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 13 & 1U) != 0U) {
    DoorLckCtl_EEIlluminatedEntrySys = DoorLckCtl_EEIlluminatedEntrySys_C;
  } else {
    DoorLckCtl_EEIlluminatedEntrySys = BSW_EEIlluminatedEntrySys;
  }

  /* End of Switch: '<S446>/Switch14' */
  /* End of Outputs for SubSystem: '<S446>/Bit Shift14' */

  /* Outputs for Atomic SubSystem: '<S446>/Bit Shift15' */
  /* Switch: '<S446>/Switch15' incorporates:
   *  Constant: '<S446>/Constant75'
   *  Constant: '<S446>/Constant76'
   *  MATLAB Function: '<S542>/bit_shift'
   *  S-Function (sfix_bitop): '<S446>/Bitwise AND15'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 14 & 1U) != 0U) {
    DoorLckCtl_IllmndSts = DoorLckCtl_IllmndSts_C;
  } else {
    DoorLckCtl_IllmndSts = BSW_IllmndSts;
  }

  /* End of Switch: '<S446>/Switch15' */
  /* End of Outputs for SubSystem: '<S446>/Bit Shift15' */

  /* Abs: '<S446>/Abs' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  DoorLckCtl_VehSpd = (float32)fabs
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())->VIPC_VehSpd_kph);

  /* RelationalOperator: '<S446>/Relational Operator' incorporates:
   *  Constant: '<S446>/Constant'
   */
  rtb_RelationalOperator_p = (DoorLckCtl_VehSpd < 3.0F);

  /* RelationalOperator: '<S446>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_l =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())->VIPC_VehSpdVld_flg;

  /* RelationalOperator: '<S446>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S446>/Relational Operator2'
   */
  rtb_Switch1_o4 = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehSpdVld_flg;

  /* Logic: '<S446>/Logical Operator1' incorporates:
   *  Logic: '<S446>/Logical Operator'
   */
  DoorLckCtl_VehStop = ((rtb_RelationalOperator_p && rtb_RelationalOperator1_l) ||
                        rtb_Switch1_o4);

  /* Logic: '<S446>/Logical Operator4' incorporates:
   *  Logic: '<S446>/Logical Operator2'
   *  Logic: '<S446>/Logical Operator3'
   */
  DoorLckCtl_VehRun = ((!rtb_RelationalOperator_p) && rtb_RelationalOperator1_l);

  /* RelationalOperator: '<S446>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_Switch1_o4 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehSpdVld_flg;

  /* Switch: '<S446>/Switch' incorporates:
   *  Constant: '<S446>/Constant54'
   */
  if (!rtb_Switch1_o4) {
    DoorLckCtl_VehSpd = 0.0F;
  }

  /* End of Switch: '<S446>/Switch' */
}

/* ConstCode for atomic system: '<S407>/SignalProcess' */
static void AppSwcBcm_SignalProcess_b_Const(void)
{
  /* ConstCode for Constant: '<S446>/Constant69' */
  DoorLckCtl_HoodAjarSw = true;
}

/* System initialize for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S407>/DoorDrv' */
  AppSwcBcm_DoorDrv_Init();

  /* SystemInitialize for Atomic SubSystem: '<S407>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Init();

  /* End of SystemInitialize for SubSystem: '<S407>/DoorLckCtlLogic' */
}

/* Outputs for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl(void)
{
  boolean rtb_DataTypeConversion1_p;

  /* Outputs for Atomic SubSystem: '<S407>/SignalProcess' */
  AppSwcBcm_SignalProcess_d();

  /* End of Outputs for SubSystem: '<S407>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S407>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic();

  /* End of Outputs for SubSystem: '<S407>/DoorLckCtlLogic' */

  /* Chart: '<S407>/DoorDrv' */
  AppSwcBcm_DoorDrv();

  /* Outputs for Atomic SubSystem: '<S407>/Ovrd1' */
  /* Switch: '<S443>/Switch1' incorporates:
   *  Constant: '<S407>/Constant1'
   *  Constant: '<S407>/Constant2'
   *  Switch: '<S443>/Switch2'
   */
  if (DoorLckCtl_J54DoorLckOvrdFlg_C) {
    DoorLckCtl_J54DoorLck = DoorLckCtl_J54DoorLckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S407>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorLlckCtlFlg != 0);
    DoorLckCtl_J54DoorLck = (rtb_DataTypeConversion1_p ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J54);
  }

  /* End of Switch: '<S443>/Switch1' */
  /* End of Outputs for SubSystem: '<S407>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S407>/Ovrd2' */
  /* Switch: '<S444>/Switch1' incorporates:
   *  Constant: '<S407>/Constant3'
   *  Constant: '<S407>/Constant4'
   *  Switch: '<S444>/Switch2'
   */
  if (DoorLckCtl_J511TrunkUnlckOvrdFlg_C) {
    DoorLckCtl_J511TrunkUnlck = DoorLckCtl_J511TrunkUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S407>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->TrunkUnlckCtlFlg != 0);
    DoorLckCtl_J511TrunkUnlck = (rtb_DataTypeConversion1_p ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J511);
  }

  /* End of Switch: '<S444>/Switch1' */
  /* End of Outputs for SubSystem: '<S407>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S407>/Ovrd3' */
  /* Switch: '<S445>/Switch1' incorporates:
   *  Constant: '<S407>/Constant18'
   *  Constant: '<S407>/Constant19'
   *  Switch: '<S445>/Switch2'
   */
  if (DoorLckCtl_J56DoorUnlckOvrdFlg_C) {
    DoorLckCtl_J56DoorUnlck = DoorLckCtl_J56DoorUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S407>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorUnlckCtlFlg != 0);
    DoorLckCtl_J56DoorUnlck = (rtb_DataTypeConversion1_p ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J56);
  }

  /* End of Switch: '<S445>/Switch1' */
  /* End of Outputs for SubSystem: '<S407>/Ovrd3' */
}

/* Update for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Update(void)
{
  /* Update for UnitDelay: '<S407>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_g = DoorLckCtl_TrunkLckSta;
}

/* ConstCode for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S407>/SignalProcess' */
  AppSwcBcm_SignalProcess_b_Const();

  /* End of ConstCode for SubSystem: '<S407>/SignalProcess' */

  /* ConstCode for Atomic SubSystem: '<S407>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Const();

  /* End of ConstCode for SubSystem: '<S407>/DoorLckCtlLogic' */
}

/* Output and update for atomic system: '<S4>/DynDID' */
static void AppSwcBcm_DynDID(void)
{
  sint32 i;
  uint8 rtb_RecordSta;
  boolean rtb_RelationalOperator1_ok;
  boolean rtb_Switch;

  /* Chart: '<S580>/Chart' */
  DynDID_0xF234ADSampleValue[1] = 0U;
  DynDID_0xF234ADSampleValue[2] = 0U;

  /* CCaller: '<S580>/C Caller' incorporates:
   *  Constant: '<S580>/Constant'
   *  Constant: '<S580>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF234ADSampleValue[0], 23U, 62004U);

  /* CCaller: '<S574>/C Caller' incorporates:
   *  Constant: '<S408>/Constant27'
   *  Constant: '<S574>/Constant'
   *  Constant: '<S574>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF22BFobInformation[0], 16U, 61995U);

  /* Truth Table: '<S579>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 3) ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 5)) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    rtb_RecordSta = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 1) {
    /*  Example action 2 called from D3 column in condition table */
    rtb_RecordSta = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw) {
    rtb_RecordSta = 3U;
  } else {
    /*  Default */
    rtb_RecordSta = 0U;
  }

  /* End of Truth Table: '<S579>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_ly) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF233RemoteStartUpFailRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.RemoteStartFailRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_ly = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_kf = (rtb_RecordSta != 0);

  /* Chart: '<S579>/Chart' incorporates:
   *  SubSystem: '<S597>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_kf,
    &AppSwcBcm_ARID_DEF.LogicalOperator_bb,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_md);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_bb) {
    i = AppSwcBcm_ARID_DEF.i + 1;
    if (AppSwcBcm_ARID_DEF.i + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i > 10) {
      AppSwcBcm_ARID_DEF.i = 1U;
    }
  }

  /* CCaller: '<S579>/C Caller' incorporates:
   *  Constant: '<S579>/Constant'
   *  Constant: '<S579>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF233RemoteStartUpFailRecord[0], 10U,
                     62003U);

  /* Truth Table: '<S576>/Truth Table' */
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
    rtb_RecordSta = 10U;
  } else {
    rtb_Switch = !AppSwcBcm_ARID_DEF.BusCreator4.CrshUnlck;
    if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck) {
      /*  Example action 2 called from D3 column in condition table */
      rtb_RecordSta = 15U;
    } else {
      rtb_Switch = (rtb_Switch &&
                    (!AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck));
      if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck) {
        rtb_RecordSta = 11U;
      } else {
        rtb_Switch = (rtb_Switch && (!AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck));
        if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck) {
          rtb_RecordSta = 8U;
        } else {
          rtb_Switch = (rtb_Switch && (!AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck));
          if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck) {
            rtb_RecordSta = 12U;
          } else {
            rtb_Switch = (rtb_Switch &&
                          (!AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck));
            if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck) {
              rtb_RecordSta = 13U;
            } else {
              rtb_Switch = (rtb_Switch &&
                            (!AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck));
              if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck) {
                rtb_RecordSta = 15U;
              } else {
                rtb_Switch = (rtb_Switch &&
                              (!AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck));
                if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck) {
                  rtb_RecordSta = 19U;
                } else {
                  rtb_Switch = (rtb_Switch &&
                                (!AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck));
                  if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck)
                  {
                    rtb_RecordSta = 17U;
                  } else {
                    rtb_Switch = (rtb_Switch &&
                                  (!AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck));
                    if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.MechLck) {
                      rtb_RecordSta = 7U;
                    } else {
                      rtb_Switch = (rtb_Switch &&
                                    (!AppSwcBcm_ARID_DEF.BusCreator4.MechLck));
                      if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.HULck) {
                        rtb_RecordSta = 1U;
                      } else {
                        rtb_Switch = (rtb_Switch &&
                                      (!AppSwcBcm_ARID_DEF.BusCreator4.HULck));
                        if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.SpdLck)
                        {
                          rtb_RecordSta = 2U;
                        } else {
                          rtb_Switch = (rtb_Switch &&
                                        (!AppSwcBcm_ARID_DEF.BusCreator4.SpdLck));
                          if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.PELck)
                          {
                            rtb_RecordSta = 5U;
                          } else {
                            rtb_Switch = (rtb_Switch &&
                                          (!AppSwcBcm_ARID_DEF.BusCreator4.PELck));
                            if (rtb_Switch &&
                                AppSwcBcm_ARID_DEF.BusCreator4.AutoLck) {
                              rtb_RecordSta = 3U;
                            } else {
                              rtb_Switch = (rtb_Switch &&
                                            (!AppSwcBcm_ARID_DEF.BusCreator4.AutoLck));
                              if (rtb_Switch &&
                                  AppSwcBcm_ARID_DEF.BusCreator4.RKELck) {
                                rtb_RecordSta = 4U;
                              } else if (rtb_Switch &&
                                         (!AppSwcBcm_ARID_DEF.BusCreator4.RKELck)
                                         &&
                                         AppSwcBcm_ARID_DEF.BusCreator4.WelcomeLck)
                              {
                                rtb_RecordSta = 18U;
                              } else {
                                /*  Default */
                                rtb_RecordSta = 0U;
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

  /* End of Truth Table: '<S576>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_mf) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF230DoorOpRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_mf = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_dc = (rtb_RecordSta != 0);

  /* Chart: '<S576>/Chart' incorporates:
   *  SubSystem: '<S585>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_dc,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ci,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h5);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ci) {
    i = AppSwcBcm_ARID_DEF.i_b + 1;
    if (AppSwcBcm_ARID_DEF.i_b + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_b = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_b > 10) {
      AppSwcBcm_ARID_DEF.i_b = 1U;
    }

    DynDID_0xF230DoorOpRecord[AppSwcBcm_ARID_DEF.i_b - 1] = rtb_RecordSta;
  }

  /* CCaller: '<S576>/C Caller' incorporates:
   *  Constant: '<S576>/Constant'
   *  Constant: '<S576>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF230DoorOpRecord[0], 10U, 62000U);

  /* Switch: '<S576>/Switch' incorporates:
   *  UnitDelay: '<S576>/Unit Delay'
   */
  if (rtb_RecordSta > 0) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = rtb_RecordSta;
  }

  /* End of Switch: '<S576>/Switch' */

  /* Truth Table: '<S577>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkRkEUnlck) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    rtb_RecordSta = 5U;
  } else {
    rtb_Switch = !AppSwcBcm_ARID_DEF.BusCreator4.TrunkRkEUnlck;
    if (rtb_Switch && AppSwcBcm_ARID_DEF.BusCreator4.TrunkHUUnlck) {
      /*  Example action 2 called from D3 column in condition table */
      rtb_RecordSta = 0U;
    } else if (rtb_Switch && (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkHUUnlck) &&
               AppSwcBcm_ARID_DEF.BusCreator4.TrunkAutoLck) {
      rtb_RecordSta = 0U;
    } else {
      /*  Default */
      rtb_RecordSta = 0U;
    }
  }

  /* End of Truth Table: '<S577>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_k) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF231TrunkOpRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_k = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_l1 = (rtb_RecordSta != 0);

  /* Chart: '<S577>/Chart' incorporates:
   *  SubSystem: '<S589>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_l1,
    &AppSwcBcm_ARID_DEF.LogicalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ja);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
    i = AppSwcBcm_ARID_DEF.i_m + 1;
    if (AppSwcBcm_ARID_DEF.i_m + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_m = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_m > 10) {
      AppSwcBcm_ARID_DEF.i_m = 1U;
    }

    DynDID_0xF231TrunkOpRecord[AppSwcBcm_ARID_DEF.i_m - 1] = rtb_RecordSta;
  }

  /* CCaller: '<S577>/C Caller' incorporates:
   *  Constant: '<S577>/Constant'
   *  Constant: '<S577>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF231TrunkOpRecord[0], 10U, 62001U);

  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Default */
  if (!AppSwcBcm_ARID_DEF.Flg_b) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF232LocalStartUpFailRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.LocalStartFailOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_b = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_b0 = false;

  /* Chart: '<S578>/Chart' incorporates:
   *  SubSystem: '<S593>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_b0,
    &AppSwcBcm_ARID_DEF.LogicalOperator_gf,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m3y);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_gf) {
    i = AppSwcBcm_ARID_DEF.i_e + 1;
    if (AppSwcBcm_ARID_DEF.i_e + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_e = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_e > 10) {
      AppSwcBcm_ARID_DEF.i_e = 1U;
    }
  }

  /* CCaller: '<S578>/C Caller' incorporates:
   *  Constant: '<S578>/Constant'
   *  Constant: '<S578>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF232LocalStartUpFailRecord[0], 10U,
                     62002U);

  /* Chart: '<S581>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S584>/Logical Operator'
   *  Logic: '<S584>/Logical Operator1'
   *  RelationalOperator: '<S408>/Relational Operator'
   */
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(DynDID_0xF235DigtInSampleValue[0] |
    AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.DataTypeConversion1 << 1 |
     DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.DataTypeConversion << 2 |
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
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw << 6 |
     DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)
    ((AppSwcBcm_ARID_DEF.BusCreator4.InsLck ||
      AppSwcBcm_ARID_DEF.BusCreator4.OsLck) << 7 |
     DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[1] = (uint8)
    ((AppSwcBcm_ARID_DEF.BusCreator4.InsUnlck ||
      AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck) | DynDID_0xF235DigtInSampleValue[1]);
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
    (AppSwcBcm_ARID_DEF.BusCreator5.HazardLightSw << 1 |
     DynDID_0xF235DigtInSampleValue[3]);
  DynDID_0xF235DigtInSampleValue[3] = (uint8)(AppSwcBcm_ARID_DEF.CCaller40 << 2 |
    DynDID_0xF235DigtInSampleValue[3]);

  /* CCaller: '<S581>/C Caller' incorporates:
   *  Constant: '<S581>/Constant'
   *  Constant: '<S581>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF235DigtInSampleValue[0], 5U, 62005U);

  /* Switch: '<S605>/Switch' incorporates:
   *  Constant: '<S605>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  RelationalOperator: '<S605>/Relational Operator'
   *  RelationalOperator: '<S605>/Relational Operator1'
   */
  rtb_Switch = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus())->DrvWinSta != 0);

  /* RelationalOperator: '<S605>/Relational Operator1' incorporates:
   *  Constant: '<S605>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  rtb_RelationalOperator1_ok = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus()
    )->PsgWinSta != 0);

  /* Chart: '<S582>/Chart' incorporates:
   *  Constant: '<S604>/Constant'
   *  Constant: '<S604>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S604>/Logical Operator'
   *  Logic: '<S604>/Logical Operator1'
   *  RelationalOperator: '<S604>/Relational Operator'
   *  RelationalOperator: '<S604>/Relational Operator1'
   *  RelationalOperator: '<S604>/Relational Operator2'
   *  RelationalOperator: '<S604>/Relational Operator3'
   *  Switch: '<S605>/Switch1'
   * */
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)(DynDID_0xF236DigtOutSampleValue[0]
    | AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLSta);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrRSta << 1 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.DataTypeConversion3 << 2 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw << 3 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.ReverseLampSta << 5 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[0] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.PosLampSta << 7 |
     DynDID_0xF236DigtOutSampleValue[0]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    (AppSwcBcm_ARID_DEF.DataTypeConversion2 << 1 |
     DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.LowBeamSta << 4 |
     DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.HiBeamSta << 5 |
     DynDID_0xF236DigtOutSampleValue[1]);
  DynDID_0xF236DigtOutSampleValue[1] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator5.FogLampFSw << 6 |
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
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)(rtb_RelationalOperator1_ok << 4 |
    DynDID_0xF236DigtOutSampleValue[3]);
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator1.J421IG1RlyCtl << 7 |
     DynDID_0xF236DigtOutSampleValue[3]);
  DynDID_0xF236DigtOutSampleValue[4] = (uint8)(DynDID_0xF236DigtOutSampleValue[4]
    | AppSwcBcm_ARID_DEF.BusCreator1.J437IG2RlyCtl);
  DynDID_0xF236DigtOutSampleValue[4] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornDrv << 1 |
     DynDID_0xF236DigtOutSampleValue[4]);

  /* CCaller: '<S582>/C Caller' incorporates:
   *  Constant: '<S582>/Constant'
   *  Constant: '<S582>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF236DigtOutSampleValue[0], 5U, 62006U);

  /* CCaller: '<S575>/C Caller' incorporates:
   *  Constant: '<S575>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts, 61996U);

  /* CCaller: '<S583>/C Caller' incorporates:
   *  Constant: '<S583>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts, 62007U);

  /* SignalConversion: '<S408>/Signal Conversion' */
  DynDID_0xF22CAntitheftSta = AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts;

  /* SignalConversion: '<S408>/Signal Conversion1' */
  DynDID_0xF237PwrModeSta = AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;
}

/*
 * System initialize for atomic system:
 *    '<S606>/LIB_TPD_10ms11'
 *    '<S622>/LIB_TPD_10ms'
 *    '<S891>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms11_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S606>/LIB_TPD_10ms11'
 *    '<S622>/LIB_TPD_10ms'
 *    '<S891>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms11(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms11_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  float32 tmp;

  /* Chart: '<S606>/LIB_TPD_10ms11' */
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

  /* End of Chart: '<S606>/LIB_TPD_10ms11' */
}

/* System initialize for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S606>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms11_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);

  /* SystemInitialize for Chart: '<S606>/Lib_RiseEdgeDelay' incorporates:
   *  SubSystem: '<S610>/Lib_RiseEdgeDet'
   */
  /* InitializeConditions for Delay: '<S619>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j4 = true;
}

/* Output and update for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl(void)
{
  sint32 tmp;
  uint8 rtb_Switch;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_fd;
  boolean rtb_RelationalOperator1_gg;

  /* Chart: '<S606>/Lib_RiseEdgeDelay' incorporates:
   *  SubSystem: '<S610>/Lib_RiseEdgeDet'
   */
  /* Delay: '<S619>/Delay' incorporates:
   *  RelationalOperator: '<S606>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_j4) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_iw = AppSwcBcm_ARID_DEF.BusCreator4.OsLck;
  }

  /* Logic: '<S619>/Logical Operator1' incorporates:
   *  Delay: '<S619>/Delay'
   */
  rtb_LogicalOperator1_fd = !AppSwcBcm_ARID_DEF.Delay_DSTATE_iw;

  /* Update for Delay: '<S619>/Delay' incorporates:
   *  RelationalOperator: '<S606>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.icLoad_j4 = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_iw = AppSwcBcm_ARID_DEF.BusCreator4.OsLck;

  /* Logic: '<S619>/Logical Operator' incorporates:
   *  Constant: '<S606>/Constant6'
   *  RelationalOperator: '<S606>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.OsLck && rtb_LogicalOperator1_fd) {
    AppSwcBcm_ARID_DEF.Cnt_b = 2U;
    AppSwcBcm_ARID_DEF.LIB_blOut_d = true;
  }

  /* End of Logic: '<S619>/Logical Operator' */
  if (AppSwcBcm_ARID_DEF.Cnt_b <= 0) {
    AppSwcBcm_ARID_DEF.LIB_blOut_d = false;
  } else {
    AppSwcBcm_ARID_DEF.Cnt_b--;
  }

  /* RelationalOperator: '<S606>/Relational Operator1' incorporates:
   *  Constant: '<S606>/Constant1'
   */
  rtb_LogicalOperator1_fd = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0);

  /* Logic: '<S606>/Logical Operator' incorporates:
   *  Constant: '<S606>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S606>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S612>/Relational Operator1' incorporates:
   *  Constant: '<S606>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S606>/Relational Operator3'
   */
  rtb_RelationalOperator1_gg =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S606>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_RelationalOperator1_gg);

  /* RelationalOperator: '<S612>/Relational Operator1' incorporates:
   *  Constant: '<S612>/Constant1'
   *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
   */
  rtb_RelationalOperator1_gg =
    ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
      ())->VIPM_ESCLUnOrLockfeedback_nu == 648518346341351424ULL);

  /* Switch: '<S612>/Switch' */
  if (rtb_RelationalOperator1_gg) {
    /* Switch: '<S612>/Switch' incorporates:
     *  Constant: '<S612>/Constant2'
     */
    rtb_Switch = 2U;
  } else {
    /* RelationalOperator: '<S612>/Relational Operator' incorporates:
     *  Constant: '<S612>/Constant'
     *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
     */
    rtb_RelationalOperator1_gg =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
        ())->VIPM_ESCLUnOrLockfeedback_nu == 1297036692682702848ULL);

    /* Switch: '<S612>/Switch' incorporates:
     *  Switch: '<S612>/Switch1'
     */
    rtb_Switch = rtb_RelationalOperator1_gg;
  }

  /* End of Switch: '<S612>/Switch' */

  /* Logic: '<S606>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S606>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_d3 = (AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
    AppSwcBcm_ARID_DEF.LIB_blOut_d && rtb_LogicalOperator1_fd &&
    rtb_LogicalOperator);

  /* Chart: '<S606>/ESCLLck' incorporates:
   *  SubSystem: '<S607>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_d3,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ow,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ow) {
    /* UnitDelay: '<S606>/Unit Delay' */
    if (ESCLCtl_Unlck == 1) {
      AppSwcBcm_ARID_DEF.Flg2_c = true;
      AppSwcBcm_ARID_DEF.Flg_f = false;
      AppSwcBcm_ARID_DEF.Cnt_jk = 0U;
      AppSwcBcm_ARID_DEF.ESCLCtl_UnlckPwrOff = true;
      AppSwcBcm_ARID_DEF.Cnt2_g = 0U;
      AppSwcBcm_ARID_DEF.Cnt3_f = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Flg_f = true;
      AppSwcBcm_ARID_DEF.Cnt_jk = 0U;
      ESCLCtl_J436Lck = true;
      AppSwcBcm_ARID_DEF.Cnt2_g = 0U;
      AppSwcBcm_ARID_DEF.Cnt3_f = 0U;
    }

    /* End of UnitDelay: '<S606>/Unit Delay' */
  }

  if (AppSwcBcm_ARID_DEF.Flg2_c) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3_f + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3_f + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3_f = (uint16)tmp;
  }

  if (AppSwcBcm_ARID_DEF.Cnt3_f > ESCLCtl_PwrOffDelay_C + 1) {
    AppSwcBcm_ARID_DEF.Flg2_c = false;
    AppSwcBcm_ARID_DEF.Flg_f = true;
    AppSwcBcm_ARID_DEF.Cnt_jk = 0U;
    ESCLCtl_J436Lck = true;
    AppSwcBcm_ARID_DEF.Cnt2_g = 0U;
    AppSwcBcm_ARID_DEF.Cnt3_f = 0U;
    AppSwcBcm_ARID_DEF.ESCLCtl_UnlckPwrOff = false;
  }

  if (AppSwcBcm_ARID_DEF.Flg_f) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_g + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_g + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_g = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_jk >= ESCLCtl_LckDelay_C) {
      ESCLCtl_Lck = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_jk++;
    }
  }

  /* UnitDelay: '<S606>/Unit Delay2' */
  if ((rtb_Switch == 2) || AppSwcBcm_ARID_DEF.ESCLCtl_LckPwrOff) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_f = false;
    ESCLCtl_Lck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2_g > ESCLCtl_LckTimMax_C) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_f = false;
    ESCLCtl_Lck = 0U;
  }

  /* End of UnitDelay: '<S606>/Unit Delay2' */

  /* Logic: '<S606>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S606>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_g4 = (AppSwcBcm_ARID_DEF.BusCreator1.PwrOn &&
    rtb_LogicalOperator && AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* Chart: '<S606>/ESCLUnlck' incorporates:
   *  SubSystem: '<S608>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_g4,
    &AppSwcBcm_ARID_DEF.LogicalOperator_b1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m3);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_b1) {
    /* UnitDelay: '<S606>/Unit Delay1' */
    if (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k == 2) {
      AppSwcBcm_ARID_DEF.Flg2 = 1.0;
      AppSwcBcm_ARID_DEF.Flg_lr = false;
      AppSwcBcm_ARID_DEF.Cnt_ca = 0U;
      AppSwcBcm_ARID_DEF.ESCLCtl_LckPwrOff = true;
      AppSwcBcm_ARID_DEF.Cnt2 = 0U;
      AppSwcBcm_ARID_DEF.Cnt3 = 0.0;
    } else {
      AppSwcBcm_ARID_DEF.Flg_lr = true;
      AppSwcBcm_ARID_DEF.Cnt_ca = 0U;
      ESCLCtl_J436Unlck = true;
      AppSwcBcm_ARID_DEF.Cnt2 = 0U;
      AppSwcBcm_ARID_DEF.Cnt3 = 0.0;
    }

    /* End of UnitDelay: '<S606>/Unit Delay1' */
  }

  if (AppSwcBcm_ARID_DEF.Flg2 == 1.0) {
    AppSwcBcm_ARID_DEF.Cnt3++;
  }

  if (AppSwcBcm_ARID_DEF.Cnt3 > (float64)ESCLCtl_PwrOffDelay_C + 1.0) {
    AppSwcBcm_ARID_DEF.Flg2 = 0.0;
    AppSwcBcm_ARID_DEF.Flg_lr = true;
    AppSwcBcm_ARID_DEF.Cnt_ca = 0U;
    ESCLCtl_J436Unlck = true;
    AppSwcBcm_ARID_DEF.Cnt2 = 0U;
    AppSwcBcm_ARID_DEF.Cnt3 = 0.0;
    AppSwcBcm_ARID_DEF.ESCLCtl_LckPwrOff = false;
  }

  if (AppSwcBcm_ARID_DEF.Flg_lr) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2 = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_ca >= ESCLCtl_UnlckDelay_C) {
      ESCLCtl_Unlck = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_ca++;
    }
  }

  /* UnitDelay: '<S606>/Unit Delay3' */
  if ((rtb_Switch == 1) || AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_b) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_lr = false;
    ESCLCtl_Unlck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2 > ESCLCtl_UnlckTimMax_C) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_lr = false;
    ESCLCtl_Unlck = 0U;
  }

  /* End of UnitDelay: '<S606>/Unit Delay3' */

  /* Outputs for Atomic SubSystem: '<S606>/Ovrd' */
  /* Switch: '<S611>/Switch' incorporates:
   *  Constant: '<S606>/Constant18'
   */
  if (ESCLCtl_J436PwrSupOvrdFlg_C) {
    /* Switch: '<S611>/Switch' incorporates:
     *  Constant: '<S606>/Constant19'
     */
    ESCLCtl_J436PwrSup = ESCLCtl_J436PwrSupOvrdVal_C;
  } else {
    /* Switch: '<S611>/Switch' incorporates:
     *  Logic: '<S606>/Logical Operator3'
     */
    ESCLCtl_J436PwrSup = (ESCLCtl_J436Lck || ESCLCtl_J436Unlck);
  }

  /* End of Switch: '<S611>/Switch' */
  /* End of Outputs for SubSystem: '<S606>/Ovrd' */

  /* Truth Table: '<S606>/Truth Table' */
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

  /* End of Truth Table: '<S606>/Truth Table' */

  /* Chart: '<S606>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S606>/Constant7'
   *  Constant: '<S606>/Constant8'
   */
  AppSwcBcm_LIB_TPD_10ms11(rtb_LogicalOperator1_fd, 5, 0.05F,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11_n);

  /* Update for UnitDelay: '<S606>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k = ESCLCtl_Lck;

  /* Update for UnitDelay: '<S606>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_b =
    AppSwcBcm_ARID_DEF.ESCLCtl_UnlckPwrOff;
}

/* System initialize for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl_Init(void)
{
  sint32 i;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for Chart: '<S410>/IMMOCtl' */
    AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[i] = MAX_uint8_T;

    /* SystemInitialize for SignalConversion generated from: '<S410>/IMMOCtl' */
    IMMOCtl_AuthResp[i] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[i];
  }

  for (i = 0; i < 16; i++) {
    /* SystemInitialize for SignalConversion generated from: '<S410>/IMMOCtl' */
    IMMOCtl_SKRead[i] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[i];
  }
}

/* Output and update for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl(void)
{
  sint32 exitg1;
  sint32 i_0;
  uint8 b_k;
  uint8 i;
  uint8 m;
  uint8 o;

  /* SignalConversion: '<S410>/Signal Conversion' incorporates:
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

  /* Chart: '<S410>/IMMOCtl' */
  BCM_SKRead((uint8 *)&AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[0], 16U);
  i = 0U;
  b_k = 0U;
  while (i < 16) {
    if ((AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[i] == 0xFF) ||
        (AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[i] == 0x00)) {
      b_k++;
    }

    i++;
  }

  if (INV_IMMO_Req_EPT_Rec_callout() == 1) {
    i = 2U;
    m = 0U;
    o = 0U;
    while (i < 8) {
      if (IMMOCtl_INVRandom[i] == 0xFF) {
        m++;
      }

      i++;
    }

    do {
      exitg1 = 0;
      if ((b_k != 16) && (m != 6)) {
        AppSwcBcm_ARID_DEF.Random[0] = (uint32)(IMMOCtl_INVRandom[0] << 24 |
          IMMOCtl_INVRandom[1] << 16 | IMMOCtl_INVRandom[2] << 8 |
          IMMOCtl_INVRandom[3]);
        AppSwcBcm_ARID_DEF.Random[1] = (uint32)(IMMOCtl_INVRandom[4] << 24 |
          IMMOCtl_INVRandom[5] << 16 | IMMOCtl_INVRandom[6] << 8 |
          IMMOCtl_INVRandom[7]);

        /* Random[0]=((INV_Random[0]&0x000000ff)<<24)|((INV_Random[0]&0x0000ff00)<<8)|((INV_Random[0]&0x00ff0000)>>8)|((INV_Random[0]&0xff000000)>>24);
           Random[1]=((INV_Random[1]&0x000000ff)<<24)|((INV_Random[1]&0x0000ff00)<<8)|((INV_Random[1]&0x00ff0000)>>8)|((INV_Random[1]&0xff000000)>>24); */
        AppSwcBcm_ARID_DEF.Key[0] = (uint32)
          (AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[0] << 24 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[1] << 16 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[2] << 8 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[3]);
        AppSwcBcm_ARID_DEF.Key[1] = (uint32)
          (AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[4] << 24 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[5] << 16 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[6] << 8 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[7]);
        AppSwcBcm_ARID_DEF.Key[2] = (uint32)
          (AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[8] << 24 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[9] << 16 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[10] << 8 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[11]);
        AppSwcBcm_ARID_DEF.Key[3] = (uint32)
          (AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[12] << 24 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[13] << 16 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[14] << 8 |
           AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[15]);
        encipher(32U, &AppSwcBcm_ARID_DEF.Random[0], &AppSwcBcm_ARID_DEF.Key[0]);
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[1] = (uint8)0xFF;
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[2] = (uint8)
          (AppSwcBcm_ARID_DEF.Random[0] >> 8 & (uint32)0xff);
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[3] = (uint8)
          (AppSwcBcm_ARID_DEF.Random[0] & (uint32)0xff);
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[4] = (uint8)
          (AppSwcBcm_ARID_DEF.Random[1] >> 24);
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[5] = (uint8)
          (AppSwcBcm_ARID_DEF.Random[1] >> 16 & (uint32)0xff);
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[6] = (uint8)
          (AppSwcBcm_ARID_DEF.Random[1] >> 8 & (uint32)0xff);
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[7] = (uint8)
          (AppSwcBcm_ARID_DEF.Random[1] & (uint32)0xff);
        exitg1 = 1;
      } else if (o < 8) {
        AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[o] = (uint8)0xFF;
        o++;
      } else {
        if (b_k == 16) {
          AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[1] = (uint8)0xF0;
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);

    BCM_IMMOAuthResp1_EPT_Send_Notication((uint8 *)
      &AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[0]);
    INV_IMMO_Req_EPT_Rec_ClaerFlg();
  }

  for (i_0 = 0; i_0 < 16; i_0++) {
    /* SignalConversion generated from: '<S410>/IMMOCtl' */
    IMMOCtl_SKRead[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[i_0];
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    /* SignalConversion generated from: '<S410>/IMMOCtl' */
    IMMOCtl_AuthResp[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[i_0];
  }

  /* SignalConversion generated from: '<S410>/IMMOCtl' incorporates:
   *  Chart: '<S410>/IMMOCtl'
   */
  IMMOCtl_SKSta = (uint8)(b_k == 16);
}

/*
 * System initialize for atomic system:
 *    '<S656>/LIB_Pulse'
 *    '<S656>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse_Init(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt)
{
  *rty_LIB_blOut = false;
  *rty_LIB_u16PrdSucCnt = 0U;
}

/*
 * System reset for atomic system:
 *    '<S656>/LIB_Pulse'
 *    '<S656>/LIB_Pulse1'
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
 *    '<S656>/LIB_Pulse'
 *    '<S656>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse(uint16 rtu_LIB_u16PrdDemCnt, uint16
  rtu_LIB_u16Prd, uint16 rtu_LIB_u16Wdt, boolean rtu_LIB_blReset, boolean
  *rty_LIB_blOut, uint16 *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S656>/LIB_Pulse' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blReset;

  /* Outputs for Function Call SubSystem: '<S657>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S657>/Lib_RiseEdgeDet' */

  /* Chart: '<S656>/LIB_Pulse' */
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
 *    '<S656>/Truth Table'
 *    '<S656>/Truth Table1'
 */
static void AppSwcBcm_TruthTable(boolean rtu_BSD_LightOn, boolean
  rtu_BSD_LightFlash, uint16 *rty_BSD_LightPrd, uint16 *rty_BSD_LightWdt)
{
  /*  Example condition 1 */
  /*  Example condition 2 */
  if (rtu_BSD_LightOn && (!rtu_BSD_LightFlash)) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    *rty_BSD_LightPrd = 5U;
    *rty_BSD_LightWdt = 5U;
  } else if ((!rtu_BSD_LightOn) && rtu_BSD_LightFlash) {
    *rty_BSD_LightPrd = 5U;
    *rty_BSD_LightWdt = 3U;
  } else {
    /*  Default */
    /*  Example action 2 called from D3 column in condition table */
    *rty_BSD_LightPrd = 0U;
    *rty_BSD_LightWdt = 0U;
  }
}

/* System initialize for atomic system: '<S411>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S621>/Enabled Subsystem' */

  /* SystemInitialize for Chart: '<S656>/LIB_Pulse' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_k,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_d);

  /* SystemInitialize for Chart: '<S656>/LIB_Pulse1' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_l,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt);

  /* End of SystemInitialize for SubSystem: '<S621>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<S411>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl(void)
{
  uint16 rtb_BSD_LightPrd;
  uint16 rtb_BSD_LightWdt;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator10_dy;
  boolean rtb_RelationalOperator8_g;
  boolean rtb_RelationalOperator9_b;

  /* Outputs for Enabled SubSystem: '<S621>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S656>/Enable'
   */
  /* Logic: '<S621>/Logical Operator' incorporates:
   *  Constant: '<S621>/Constant13'
   *  RelationalOperator: '<S621>/Relational Operator'
   *  RelationalOperator: '<S621>/Relational Operator2'
   */
  if ((!AppSwcBcm_ARID_DEF.LogicalOperator_cx) &&
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    if (!AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
      /* SystemReset for Chart: '<S656>/LIB_Pulse' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_k,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_d,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

      /* SystemReset for Chart: '<S656>/LIB_Pulse1' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_l,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);
      AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = true;
    }

    /* RelationalOperator: '<S656>/Relational Operator10' incorporates:
     *  Constant: '<S656>/Constant12'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator1'
     */
    rtb_RelationalOperator10_dy =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 1);

    /* RelationalOperator: '<S656>/Relational Operator8' incorporates:
     *  Constant: '<S656>/Constant3'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator3'
     */
    rtb_RelationalOperator8_g =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 1);

    /* RelationalOperator: '<S656>/Relational Operator9' incorporates:
     *  Constant: '<S656>/Constant4'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator4'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 1);

    /* Logic: '<S656>/Logical Operator' */
    rtb_LogicalOperator = (rtb_RelationalOperator10_dy ||
      rtb_RelationalOperator8_g || rtb_RelationalOperator9_b);

    /* RelationalOperator: '<S656>/Relational Operator9' incorporates:
     *  Constant: '<S656>/Constant1'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator12'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 2);

    /* RelationalOperator: '<S656>/Relational Operator8' incorporates:
     *  Constant: '<S656>/Constant11'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator11'
     */
    rtb_RelationalOperator8_g =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 2);

    /* RelationalOperator: '<S656>/Relational Operator10' incorporates:
     *  Constant: '<S656>/Constant10'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator7'
     */
    rtb_RelationalOperator10_dy =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 2);

    /* Truth Table: '<S656>/Truth Table' incorporates:
     *  Logic: '<S656>/Logical Operator2'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_b ||
                         rtb_RelationalOperator8_g ||
                         rtb_RelationalOperator10_dy, &rtb_BSD_LightWdt,
                         &rtb_BSD_LightPrd);

    /* Chart: '<S656>/LIB_Pulse' incorporates:
     *  Constant: '<S656>/Constant'
     *  Constant: '<S656>/Constant13'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightWdt, rtb_BSD_LightPrd, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_k,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_d,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

    /* SignalConversion generated from: '<S656>/LampCtl_J420BSDRightCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_k;

    /* RelationalOperator: '<S656>/Relational Operator9' incorporates:
     *  Constant: '<S656>/Constant5'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator5'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 1);

    /* RelationalOperator: '<S656>/Relational Operator8' incorporates:
     *  Constant: '<S656>/Constant2'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator2'
     */
    rtb_RelationalOperator8_g =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 1);

    /* RelationalOperator: '<S656>/Relational Operator10' incorporates:
     *  Constant: '<S656>/Constant6'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S656>/Relational Operator6'
     */
    rtb_RelationalOperator10_dy =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 1);

    /* Logic: '<S656>/Logical Operator3' */
    rtb_LogicalOperator = (rtb_RelationalOperator9_b ||
      rtb_RelationalOperator8_g || rtb_RelationalOperator10_dy);

    /* RelationalOperator: '<S656>/Relational Operator9' incorporates:
     *  Constant: '<S656>/Constant8'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 2);

    /* RelationalOperator: '<S656>/Relational Operator8' incorporates:
     *  Constant: '<S656>/Constant7'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator8_g =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 2);

    /* RelationalOperator: '<S656>/Relational Operator10' incorporates:
     *  Constant: '<S656>/Constant9'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator10_dy =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 2);

    /* Truth Table: '<S656>/Truth Table1' incorporates:
     *  Logic: '<S656>/Logical Operator1'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_b ||
                         rtb_RelationalOperator8_g ||
                         rtb_RelationalOperator10_dy, &rtb_BSD_LightPrd,
                         &rtb_BSD_LightWdt);

    /* Chart: '<S656>/LIB_Pulse1' incorporates:
     *  Constant: '<S656>/Constant14'
     *  Constant: '<S656>/Constant15'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightPrd, rtb_BSD_LightWdt, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_l,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);

    /* SignalConversion generated from: '<S656>/LampCtl_J422BSDLeftCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_l;
  } else if (AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
    /* Disable for SignalConversion generated from: '<S656>/LampCtl_J420BSDRightCtl' incorporates:
     *  Outport: '<S656>/LampCtl_J420BSDRightCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl = false;

    /* Disable for SignalConversion generated from: '<S656>/LampCtl_J422BSDLeftCtl' incorporates:
     *  Outport: '<S656>/LampCtl_J422BSDLeftCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl = false;
    AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = false;
  }

  /* End of Logic: '<S621>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S621>/Enabled Subsystem' */
}

/* System initialize for atomic system: '<S411>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S622>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms11_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_g);

  /* SystemInitialize for Chart: '<S622>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_a);
}

/* Output and update for atomic system: '<S411>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl(void)
{
  /* Chart: '<S622>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S622>/Constant4'
   *  Constant: '<S622>/Constant43'
   *  Constant: '<S622>/Constant45'
   *  RelationalOperator: '<S622>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms11(LampCtl_LightIntstSta == 2,
    LampCtl_AutoLampNightDelayTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_g, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms);

  /* Chart: '<S622>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S622>/Constant5'
   *  Constant: '<S622>/Constant6'
   *  Constant: '<S622>/Constant7'
   *  Constant: '<S622>/Constant8'
   *  Logic: '<S622>/Logical Operator3'
   *  RelationalOperator: '<S622>/Relational Operator5'
   *  UnitDelay: '<S622>/Unit Delay'
   */
  AppSwcBcm_LIB_TPD_10ms((LampCtl_LightIntstSta == 1) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jt, LampCtl_AutoLampDayDelayTim_C, 10,
    LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1);

  /* Switch: '<S667>/Switch' incorporates:
   *  Constant: '<S622>/Constant1'
   *  Logic: '<S622>/Logical Operator'
   *  RelationalOperator: '<S622>/Relational Operator1'
   *  RelationalOperator: '<S622>/Relational Operator2'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || (!LampCtl_AutoLampSw) ||
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_a) {
    /* Switch: '<S667>/Switch' incorporates:
     *  Constant: '<S667>/Constant'
     */
    LampCtl_AutoLampSta = false;
  } else {
    /* Switch: '<S667>/Switch' incorporates:
     *  Constant: '<S622>/Constant'
     *  Logic: '<S622>/Logical Operator1'
     *  Logic: '<S622>/Logical Operator2'
     *  Logic: '<S667>/Logical Operator'
     *  RelationalOperator: '<S622>/Relational Operator'
     *  UnitDelay: '<S667>/Unit Delay'
     */
    LampCtl_AutoLampSta = (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_g) || LampCtl_AutoLampSta);
  }

  /* End of Switch: '<S667>/Switch' */

  /* Update for UnitDelay: '<S622>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jt = LampCtl_AutoLampSta;
}

/* System initialize for atomic system: '<S411>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S623>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_lr = true;

  /* InitializeConditions for UnitDelay: '<S623>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 20U;
}

/* Output and update for atomic system: '<S411>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl(void)
{
  uint8 rtb_Switch1_d;
  boolean rtb_RelationalOperator_f3;

  /* RelationalOperator: '<S623>/Relational Operator' incorporates:
   *  Constant: '<S623>/Constant'
   */
  rtb_RelationalOperator_f3 = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

  /* Delay: '<S623>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_lr) {
    /* Switch: '<S623>/Switch2' incorporates:
     *  Constant: '<S623>/Constant13'
     *  Constant: '<S623>/Constant14'
     *  RelationalOperator: '<S623>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BackLadjvalFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_d = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_d =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BackLadjvalFb;
    }

    /* End of Switch: '<S623>/Switch2' */
  }

  /* Switch: '<S623>/Switch1' */
  if (rtb_RelationalOperator_f3) {
    /* Switch: '<S623>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_d = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_CDCBackLadjval_enum;
  } else {
    /* Switch: '<S623>/Switch1' incorporates:
     *  Constant: '<S623>/Constant12'
     */
    rtb_Switch1_d = 0U;
  }

  /* End of Switch: '<S623>/Switch1' */

  /* MultiPortSwitch: '<S623>/Multiport Switch' */
  switch (rtb_Switch1_d) {
   case 1:
    /* MultiPortSwitch: '<S623>/Multiport Switch' incorporates:
     *  Constant: '<S623>/Constant1'
     */
    LampCtl_BackLadjvalFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S623>/Multiport Switch' incorporates:
     *  Constant: '<S623>/Constant2'
     */
    LampCtl_BackLadjvalFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S623>/Multiport Switch' incorporates:
     *  Constant: '<S623>/Constant3'
     */
    LampCtl_BackLadjvalFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S623>/Multiport Switch' incorporates:
     *  Constant: '<S623>/Constant4'
     */
    LampCtl_BackLadjvalFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S623>/Multiport Switch' incorporates:
     *  Constant: '<S623>/Constant5'
     */
    LampCtl_BackLadjvalFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S623>/Multiport Switch' incorporates:
     *  Delay: '<S623>/Delay'
     */
    LampCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_d;
    break;
  }

  /* End of MultiPortSwitch: '<S623>/Multiport Switch' */

  /* MultiPortSwitch: '<S623>/Multiport Switch1' */
  switch (LampCtl_BackLadjvalFb) {
   case 0:
    /* MultiPortSwitch: '<S623>/Multiport Switch1' incorporates:
     *  Constant: '<S623>/Constant6'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 20U;
    break;

   case 1:
    /* MultiPortSwitch: '<S623>/Multiport Switch1' incorporates:
     *  Constant: '<S623>/Constant7'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 40U;
    break;

   case 2:
    /* MultiPortSwitch: '<S623>/Multiport Switch1' incorporates:
     *  Constant: '<S623>/Constant8'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S623>/Multiport Switch1' incorporates:
     *  Constant: '<S623>/Constant9'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 80U;
    break;

   case 4:
    /* MultiPortSwitch: '<S623>/Multiport Switch1' incorporates:
     *  Constant: '<S623>/Constant10'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = 100U;
    break;
  }

  /* End of MultiPortSwitch: '<S623>/Multiport Switch1' */

  /* Switch: '<S623>/Switch' incorporates:
   *  Logic: '<S623>/Logical Operator'
   *  Logic: '<S623>/Logical Operator1'
   */
  if (rtb_RelationalOperator_f3 && (LampCtl_PosLampSta || LampCtl_LowBeamSta)) {
    /* Switch: '<S623>/Switch' */
    AppSwcBcm_ARID_DEF.Switch = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p;
  } else {
    /* Switch: '<S623>/Switch' incorporates:
     *  Constant: '<S623>/Constant11'
     */
    AppSwcBcm_ARID_DEF.Switch = 0U;
  }

  /* End of Switch: '<S623>/Switch' */

  /* Update for Delay: '<S623>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_lr = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_d = LampCtl_BackLadjvalFb;
}

/* System initialize for atomic system: '<S411>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_m;

  /* SystemInitialize for Atomic SubSystem: '<S624>/Trunk10min' */

  /* SystemInitialize for Chart: '<S671>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_m);

  /* End of SystemInitialize for SubSystem: '<S624>/Trunk10min' */
}

/* Output and update for atomic system: '<S411>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_m;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_l3;
  boolean rtb_Switch;

  /* Switch: '<S624>/Switch' incorporates:
   *  Constant: '<S624>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S624>/Relational Operator2'
   */
  rtb_Switch = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                ->VIPM_HUBCMCargoLghtSet_enum == 2);

  /* Outputs for Atomic SubSystem: '<S624>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_LogicalOperator, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_o);

  /* End of Outputs for SubSystem: '<S624>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S624>/Lib_FailEdgeDet1' */
  AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_LogicalOperator_l3, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_i);

  /* End of Outputs for SubSystem: '<S624>/Lib_FailEdgeDet1' */

  /* Logic: '<S624>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator_l3);

  /* Outputs for Atomic SubSystem: '<S624>/Trunk10min' */

  /* Chart: '<S671>/LIB_PosPluse2' incorporates:
   *  Constant: '<S624>/Constant4'
   *  UnitDelay: '<S624>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fb,
    LampCtl_BoxLampOpenTimMax_C, rtb_LogicalOperator, &rtb_LIB_blOut_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2);

  /* End of Outputs for SubSystem: '<S624>/Trunk10min' */

  /* Outputs for Atomic SubSystem: '<S624>/Lib_SR' */

  /* Logic: '<S624>/Logical Operator1' */
  AppSwcBcm_Lib_SR(rtb_LogicalOperator, rtb_LIB_blOut_m ||
                   AppSwcBcm_ARID_DEF.BusCreator4.InsLck ||
                   AppSwcBcm_ARID_DEF.BusCreator4.OsLck, &rtb_LogicalOperator_l3,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR);

  /* End of Outputs for SubSystem: '<S624>/Lib_SR' */

  /* Logic: '<S624>/Logical Operator3' incorporates:
   *  Constant: '<S624>/Constant'
   *  Constant: '<S624>/Constant1'
   *  Logic: '<S624>/Logical Operator2'
   *  Logic: '<S624>/Logical Operator4'
   *  Logic: '<S624>/Logical Operator5'
   *  RelationalOperator: '<S624>/Relational Operator'
   *  RelationalOperator: '<S624>/Relational Operator1'
   *  RelationalOperator: '<S624>/Relational Operator5'
   *  Switch: '<S624>/Switch'
   *  UnitDelay: '<S624>/Unit Delay'
   *  UnitDelay: '<S624>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fb =
    ((((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
       (((LampCtl_LightIntstSta == 2) && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d)
        || rtb_Switch)) || rtb_LogicalOperator_l3) &&
     (!AppSwcBcm_ARID_DEF.LogicalOperator_cx));

  /* Update for UnitDelay: '<S624>/Unit Delay1' incorporates:
   *  UnitDelay: '<S624>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d =
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fb;
}

/* Output and update for atomic system: '<S411>/DayRunLampCtl' */
static void AppSwcBcm_DayRunLampCtl(void)
{
  boolean rtb_RelationalOperator1_al;
  boolean rtb_RelationalOperator8_po;

  /* RelationalOperator: '<S626>/Relational Operator8' incorporates:
   *  Constant: '<S626>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator8_po =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Outputs for Atomic SubSystem: '<S626>/Lib_SR' */
  /* Switch: '<S675>/Switch' incorporates:
   *  Constant: '<S626>/Constant'
   *  Constant: '<S626>/Constant6'
   *  Constant: '<S675>/Constant'
   *  Logic: '<S626>/Logical Operator'
   *  Logic: '<S626>/Logical Operator1'
   *  Logic: '<S675>/Logical Operator'
   *  RelationalOperator: '<S626>/Relational Operator'
   *  RelationalOperator: '<S626>/Relational Operator6'
   *  RelationalOperator: '<S626>/Relational Operator7'
   *  UnitDelay: '<S675>/Unit Delay'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || LampCtl_PosLampSta ||
      rtb_RelationalOperator8_po) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pt = false;
  } else {
    /* RelationalOperator: '<S626>/Relational Operator2' incorporates:
     *  Constant: '<S626>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator8_po =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
       ->VGSM_VehActGearPstn_enum != 0);

    /* RelationalOperator: '<S626>/Relational Operator1' incorporates:
     *  Constant: '<S626>/Constant1'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator1_al =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
       ->VHVM_PTActOprtMode_enum == 2);
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pt =
      (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
        rtb_RelationalOperator1_al && rtb_RelationalOperator8_po) ||
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pt);
  }

  /* End of Switch: '<S675>/Switch' */
  /* End of Outputs for SubSystem: '<S626>/Lib_SR' */
}

/*
 * Output and update for atomic system:
 *    '<S677>/Lib_FailEdgeDetHold'
 *    '<S677>/Lib_FailEdgeDetHold1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDetHold(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDetHold_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Switch: '<S690>/Switch' incorporates:
   *  Constant: '<S690>/Constant'
   *  Logic: '<S690>/Logical Operator2'
   *  UnitDelay: '<S690>/Unit Delay'
   *  UnitDelay: '<S690>/Unit Delay1'
   */
  if (rtu_Lib_blIn) {
    rty_Lib_blOut_0 = false;
  } else {
    rty_Lib_blOut_0 = (AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE ||
                       AppSwcBcm__ARID_DEF_arg->UnitDelay1_DSTATE);
  }

  /* End of Switch: '<S690>/Switch' */

  /* Update for UnitDelay: '<S690>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* Update for UnitDelay: '<S690>/Unit Delay1' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay1_DSTATE = rty_Lib_blOut_0;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S411>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S695>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = true;

  /* InitializeConditions for Delay: '<S696>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_jq = true;

  /* InitializeConditions for Delay: '<S697>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_p = true;

  /* SystemInitialize for Chart: '<S676>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_l);

  /* SystemInitialize for Chart: '<S676>/LIB_TPD_Ts1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_d);

  /* SystemInitialize for Atomic SubSystem: '<S678>/Lib_RateLimit' */
  /* InitializeConditions for Delay: '<S694>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kl = true;

  /* End of SystemInitialize for SubSystem: '<S678>/Lib_RateLimit' */

  /* SystemInitialize for Truth Table: '<S627>/Truth Table' */
  LampCtl_DomeLampOff = true;
}

/* Output and update for atomic system: '<S411>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl(void)
{
  sint32 rtb_Switch_fj;
  float32 rtb_Add;
  float32 rtb_Product;
  boolean rtb_Switch;
  boolean rtb_Switch_a1;
  boolean tmp;
  boolean tmp_0;

  /* Chart: '<S676>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S676>/Constant3'
   *  Constant: '<S676>/Constant4'
   *  Constant: '<S676>/Constant5'
   *  RelationalOperator: '<S676>/Relational Operator1'
   */
  AppSwcBcm_LIB_TPD_10ms(!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    LampCtl_DoorOpenFLValidTim_C, LampCtl_DoorOpenFLInValidTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_l, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts_n);

  /* Outputs for Atomic SubSystem: '<S676>/FL10min' */
  /* Chart: '<S682>/LIB_Tim' incorporates:
   *  Constant: '<S682>/Constant'
   *  Logic: '<S676>/Logical Operator1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && AppSwcBcm_ARID_DEF.LIB_bErrFlg_l) {
    if (AppSwcBcm_ARID_DEF.Cnt_lu <= 12000) {
      AppSwcBcm_ARID_DEF.Cnt_lu++;
      LampCtl_DomeLampFLOpen = true;
    } else {
      LampCtl_DomeLampFLOpen = false;
    }
  } else {
    LampCtl_DomeLampFLOpen = false;
    AppSwcBcm_ARID_DEF.Cnt_lu = 0U;
  }

  /* End of Chart: '<S682>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S676>/FL10min' */

  /* Chart: '<S676>/LIB_TPD_Ts1' incorporates:
   *  Constant: '<S676>/Constant6'
   *  Constant: '<S676>/Constant7'
   *  Constant: '<S676>/Constant8'
   *  RelationalOperator: '<S676>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD_10ms(!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    LampCtl_DoorOpenFRValidTim_C, LampCtl_DoorOpenFRInValidTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_d, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts1);

  /* Outputs for Atomic SubSystem: '<S676>/FR10min' */
  /* Chart: '<S683>/LIB_Tim' incorporates:
   *  Constant: '<S683>/Constant'
   *  Logic: '<S676>/Logical Operator2'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && AppSwcBcm_ARID_DEF.LIB_bErrFlg_d) {
    if (AppSwcBcm_ARID_DEF.Cnt_g <= 12000) {
      AppSwcBcm_ARID_DEF.Cnt_g++;
      LampCtl_DomeLampFROpen = true;
    } else {
      LampCtl_DomeLampFROpen = false;
    }
  } else {
    LampCtl_DomeLampFROpen = false;
    AppSwcBcm_ARID_DEF.Cnt_g = 0U;
  }

  /* End of Chart: '<S683>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S676>/FR10min' */

  /* Outputs for Atomic SubSystem: '<S677>/Lib_FailEdgeDetHold' */
  /* RelationalOperator: '<S677>/Relational Operator3' incorporates:
   *  Constant: '<S677>/Constant3'
   */
  rtb_Switch = AppSwcBcm_Lib_FailEdgeDetHold
    (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDetHold);

  /* End of Outputs for SubSystem: '<S677>/Lib_FailEdgeDetHold' */

  /* Outputs for Atomic SubSystem: '<S677>/30s' */
  /* Chart: '<S688>/LIB_Tim' incorporates:
   *  Constant: '<S688>/Constant'
   *  Logic: '<S677>/Logical Operator4'
   *  Logic: '<S677>/Logical Operator5'
   *  RelationalOperator: '<S677>/Relational Operator2'
   *  RelationalOperator: '<S677>/Relational Operator5'
   *  RelationalOperator: '<S677>/Relational Operator6'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw && rtb_Switch &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw) &&
      AppSwcBcm_ConstB.RelationalOperator1) {
    if (AppSwcBcm_ARID_DEF.Cnt_l <= 600) {
      AppSwcBcm_ARID_DEF.Cnt_l++;
      LampCtl_DomeLampPwrOff = true;
    } else {
      LampCtl_DomeLampPwrOff = false;
    }
  } else {
    LampCtl_DomeLampPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_l = 0U;
  }

  /* End of Chart: '<S688>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S677>/30s' */

  /* Outputs for Atomic SubSystem: '<S677>/Lib_FailEdgeDetHold1' */
  rtb_Switch_a1 = AppSwcBcm_Lib_FailEdgeDetHold
    (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDetHold1);

  /* End of Outputs for SubSystem: '<S677>/Lib_FailEdgeDetHold1' */

  /* Outputs for Atomic SubSystem: '<S677>/30s1' */
  /* Chart: '<S689>/LIB_Tim' incorporates:
   *  Constant: '<S677>/Constant4'
   *  Constant: '<S689>/Constant'
   *  Logic: '<S677>/Logical Operator1'
   *  RelationalOperator: '<S677>/Relational Operator4'
   */
  if (AppSwcBcm_ConstB.RelationalOperator1 && rtb_Switch_a1 &&
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0)) {
    if (AppSwcBcm_ARID_DEF.Cnt_iz <= 600) {
      AppSwcBcm_ARID_DEF.Cnt_iz++;
      LampCtl_DomeLampUnlock = true;
    } else {
      LampCtl_DomeLampUnlock = false;
    }
  } else {
    LampCtl_DomeLampUnlock = false;
    AppSwcBcm_ARID_DEF.Cnt_iz = 0U;
  }

  /* End of Chart: '<S689>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S677>/30s1' */

  /* Delay: '<S695>/Delay' incorporates:
   *  RelationalOperator: '<S679>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_k) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_b3 =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Logic: '<S695>/Logical Operator' incorporates:
   *  Delay: '<S695>/Delay'
   *  Logic: '<S695>/Logical Operator1'
   *  RelationalOperator: '<S679>/Relational Operator4'
   */
  LampCtl_DomeLampLockDoor = (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_b3));

  /* Delay: '<S696>/Delay' incorporates:
   *  RelationalOperator: '<S679>/Relational Operator8'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_jq) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_ok =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S697>/Delay' incorporates:
   *  RelationalOperator: '<S679>/Relational Operator9'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_p) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_be =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Logic: '<S679>/Logical Operator6' incorporates:
   *  Constant: '<S679>/Constant7'
   *  Delay: '<S696>/Delay'
   *  Delay: '<S697>/Delay'
   *  Logic: '<S696>/Logical Operator'
   *  Logic: '<S696>/Logical Operator1'
   *  Logic: '<S697>/Logical Operator'
   *  Logic: '<S697>/Logical Operator1'
   *  RelationalOperator: '<S679>/Relational Operator7'
   *  RelationalOperator: '<S679>/Relational Operator8'
   *  RelationalOperator: '<S679>/Relational Operator9'
   */
  LampCtl_DomeLampCloseDoor = ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_ok)) &&
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_be)));

  /* Truth Table: '<S627>/Truth Table' */
  /*  Open Door Dome Lamp Turn ON */
  /*  Power Off Or Unlock Door Dome Lamp Turn ON */
  /*  Lock Door or Power On and Close Door Turn Off Dome Lamp */
  /*  Condition #4 */
  /*  Condition #5 */
  /*  Condition #6 */
  tmp = !LampCtl_DomeLampLockDoor;
  tmp_0 = !LampCtl_DomeLampCloseDoor;
  if (LampCtl_DomeLampFLOpen && tmp && tmp_0) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S627>/Lib_SR' */
    /* Switch: '<S680>/Switch' incorporates:
     *  Logic: '<S680>/Logical Operator'
     *  UnitDelay: '<S680>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S627>/Lib_SR' */
  } else if (LampCtl_DomeLampFROpen && tmp && tmp_0) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S627>/Lib_SR' */
    /* Switch: '<S680>/Switch' incorporates:
     *  Logic: '<S680>/Logical Operator'
     *  UnitDelay: '<S680>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S627>/Lib_SR' */
  } else if (LampCtl_DomeLampPwrOff && tmp && tmp_0) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S627>/Lib_SR' */
    /* Switch: '<S680>/Switch' incorporates:
     *  Logic: '<S680>/Logical Operator'
     *  UnitDelay: '<S680>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S627>/Lib_SR' */
  } else if (LampCtl_DomeLampUnlock && tmp && tmp_0) {
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = true;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S627>/Lib_SR' */
    /* Switch: '<S680>/Switch' incorporates:
     *  Logic: '<S680>/Logical Operator'
     *  UnitDelay: '<S680>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S627>/Lib_SR' */
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

    /* Outputs for Atomic SubSystem: '<S627>/Lib_SR' */
    /* Switch: '<S680>/Switch' incorporates:
     *  Constant: '<S680>/Constant'
     */
    LampCtl_DomeLampCtl = false;

    /* End of Outputs for SubSystem: '<S627>/Lib_SR' */
  }

  /* End of Truth Table: '<S627>/Truth Table' */

  /* Switch: '<S678>/Switch' */
  if (LampCtl_DomeLampCtl) {
    /* Switch: '<S678>/Switch' incorporates:
     *  Constant: '<S678>/Constant'
     */
    rtb_Switch_fj = 100;
  } else {
    /* Switch: '<S678>/Switch' incorporates:
     *  Constant: '<S678>/Constant1'
     */
    rtb_Switch_fj = 0;
  }

  /* End of Switch: '<S678>/Switch' */

  /* Outputs for Atomic SubSystem: '<S678>/Lib_RateLimit' */
  /* Delay: '<S694>/Variable Integer Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_kl) {
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)rtb_Switch_fj;
  }

  /* Product: '<S694>/Product' incorporates:
   *  Constant: '<S678>/Constant2'
   *  Constant: '<S678>/Constant21'
   */
  rtb_Product = 66.7F * LampCtl_Ts_C;

  /* Sum: '<S694>/Add' incorporates:
   *  Delay: '<S694>/Variable Integer Delay'
   */
  rtb_Add = (float32)rtb_Switch_fj -
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;

  /* Switch: '<S694>/Switch' incorporates:
   *  RelationalOperator: '<S694>/Relational Operator'
   */
  if (rtb_Add > rtb_Product) {
    /* Switch: '<S694>/Switch' incorporates:
     *  Delay: '<S694>/Variable Integer Delay'
     *  Sum: '<S694>/Add1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += rtb_Product;
  } else {
    /* Product: '<S694>/Product1' incorporates:
     *  Constant: '<S678>/Constant21'
     *  Constant: '<S678>/Constant3'
     */
    rtb_Product = LampCtl_Ts_C * -66.7F;

    /* Switch: '<S694>/Switch1' incorporates:
     *  RelationalOperator: '<S694>/Relational Operator1'
     */
    if (rtb_Add < rtb_Product) {
      /* Switch: '<S694>/Switch' incorporates:
       *  Delay: '<S694>/Variable Integer Delay'
       *  Sum: '<S694>/Add2'
       *  Switch: '<S694>/Switch1'
       */
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += rtb_Product;
    } else {
      /* Switch: '<S694>/Switch' incorporates:
       *  Switch: '<S694>/Switch1'
       */
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)rtb_Switch_fj;
    }

    /* End of Switch: '<S694>/Switch1' */
  }

  /* End of Switch: '<S694>/Switch' */

  /* Update for Delay: '<S694>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kl = false;

  /* End of Outputs for SubSystem: '<S678>/Lib_RateLimit' */

  /* Switch: '<S627>/Switch' incorporates:
   *  RelationalOperator: '<S627>/Relational Operator5'
   */
  if (!AppSwcBcm_ARID_DEF.LogicalOperator_cx) {
    /* Switch: '<S678>/Switch1' incorporates:
     *  Switch: '<S678>/Switch2'
     */
    if (LampCtl_DomeLampOffGrad) {
      /* Switch: '<S627>/Switch' incorporates:
       *  DataTypeConversion: '<S678>/Data Type Conversion'
       */
      AppSwcBcm_ARID_DEF.Switch_k = (uint8)
        AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
    } else if (LampCtl_DomeLampOnGrad) {
      /* Switch: '<S678>/Switch2' incorporates:
       *  DataTypeConversion: '<S678>/Data Type Conversion'
       *  Switch: '<S627>/Switch'
       */
      AppSwcBcm_ARID_DEF.Switch_k = (uint8)
        AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
    } else {
      /* Switch: '<S627>/Switch' incorporates:
       *  DataTypeConversion: '<S678>/Data Type Conversion'
       *  Switch: '<S678>/Switch1'
       *  Switch: '<S678>/Switch2'
       */
      AppSwcBcm_ARID_DEF.Switch_k = (uint8)(float32)rtb_Switch_fj;
    }

    /* End of Switch: '<S678>/Switch1' */
  } else {
    /* Switch: '<S627>/Switch' incorporates:
     *  Constant: '<S627>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Switch_k = 0U;
  }

  /* End of Switch: '<S627>/Switch' */

  /* Update for Delay: '<S695>/Delay' incorporates:
   *  RelationalOperator: '<S679>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.icLoad_k = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_b3 =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S696>/Delay' incorporates:
   *  RelationalOperator: '<S679>/Relational Operator8'
   */
  AppSwcBcm_ARID_DEF.icLoad_jq = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_ok =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S697>/Delay' incorporates:
   *  RelationalOperator: '<S679>/Relational Operator9'
   */
  AppSwcBcm_ARID_DEF.icLoad_p = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_be =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
}

/* Output and update for atomic system: '<S411>/FogLampRCtl' */
static void AppSwcBcm_FogLampRCtl(void)
{
  boolean guard1 = false;
  boolean rtb_RelationalOperator5;

  /* Chart: '<S628>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c83_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c83_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_Off_gk;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_g = false;
  } else if (AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib == AppSwcBcm_IN_Off_gk) {
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && LampCtl_PosLampSta &&
        (BSW_FogLampFCfg == 1)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_oe = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S699>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_oe,
        &AppSwcBcm_ARID_DEF.LogicalOperator_hk,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jz);

      /* End of Outputs for SubSystem: '<S699>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_hk) {
        AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_On_in;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_g = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || (!LampCtl_PosLampSta))
    {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_oe = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S699>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_oe,
        &AppSwcBcm_ARID_DEF.LogicalOperator_hk,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jz);

      /* End of Outputs for SubSystem: '<S699>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_hk) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_Off_gk;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_g = false;
    }
  }

  /* End of Chart: '<S628>/Chart1' */

  /* Chart: '<S628>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_Off_gk;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_j = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib == AppSwcBcm_IN_Off_gk) {
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && LampCtl_PosLampSta &&
        ((LampCtl_LowBeamSta && (BSW_FogLampFCfg != 1)) || ((BSW_FogLampFCfg ==
           1) && (LampCtl_LowBeamSta || AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_g))))
    {
      AppSwcBcm_ARID_DEF.Lib_blIn_gx = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S698>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gx,
        &AppSwcBcm_ARID_DEF.LogicalOperator_m,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);

      /* End of Outputs for SubSystem: '<S698>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_m) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_On_in;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_j = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || (!LampCtl_PosLampSta))
    {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_gx = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S698>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gx,
        &AppSwcBcm_ARID_DEF.LogicalOperator_m,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);

      /* End of Outputs for SubSystem: '<S698>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_m) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_Off_gk;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_j = false;
    }
  }

  /* End of Chart: '<S628>/Chart' */

  /* RelationalOperator: '<S628>/Relational Operator5' */
  rtb_RelationalOperator5 = !AppSwcBcm_ARID_DEF.LogicalOperator_cx;

  /* Logic: '<S628>/Logical Operator' */
  AppSwcBcm_ARID_DEF.LogicalOperator_ok = (rtb_RelationalOperator5 &&
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_j);

  /* Logic: '<S628>/Logical Operator1' */
  AppSwcBcm_ARID_DEF.LogicalOperator1_i = (rtb_RelationalOperator5 &&
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_g);
}

/* Output and update for atomic system: '<S411>/HiBeamCtl' */
static void AppSwcBcm_HiBeamCtl(void)
{
  /* Logic: '<S629>/Logical Operator' incorporates:
   *  Logic: '<S629>/Logical Operator1'
   *  RelationalOperator: '<S629>/Relational Operator'
   *  RelationalOperator: '<S629>/Relational Operator1'
   *  RelationalOperator: '<S629>/Relational Operator2'
   *  RelationalOperator: '<S629>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_kh = (LampCtl_LowBeamSta &&
    (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && (LampCtl_HiBeamSw ||
    LampCtl_PassLightSta));

  /* CCaller: '<S629>/C Caller1' */
  BSW_HiBeamDigSts = GetHw_HiBeamDigSts();

  /* Chart: '<S629>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S629>/Constant28'
   *  Constant: '<S629>/Constant29'
   *  Constant: '<S629>/Constant30'
   *  RelationalOperator: '<S629>/Relational Operator4'
   */
  if (BSW_HiBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_jy >= (float32)
         LampCtl_HiBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HiBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_jy++;
      AppSwcBcm_ARID_DEF.cnt_heal_pz = (uint16)((float32)
        LampCtl_HiBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_jy = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pz == 0) {
      LampCtl_HiBeamShortToBat = false;
    } else if (LampCtl_HiBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pz--;
    }
  }

  /* End of Chart: '<S629>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S411>/KnobBeamDig' */
static void AppSwcBcm_KnobBeamDig(void)
{
  /* Chart: '<S630>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S630>/Constant'
   *  Constant: '<S630>/Constant21'
   *  Constant: '<S630>/Constant3'
   *  Constant: '<S630>/Constant4'
   *  Logic: '<S630>/Logical Operator'
   *  Logic: '<S630>/Logical Operator1'
   *  RelationalOperator: '<S630>/Relational Operator'
   *  RelationalOperator: '<S630>/Relational Operator1'
   *  RelationalOperator: '<S630>/Relational Operator2'
   */
  if (((!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwStVld_flg)
       || (!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwStVld_flg))
      && (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_cq >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_KnobBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_cq++;
      AppSwcBcm_ARID_DEF.cnt_heal_o = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_cq = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_o == 0) {
      LampCtl_KnobBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_o--;
    }
  }

  /* End of Chart: '<S630>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S411>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;

  /* SystemInitialize for Chart: '<S631>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_l);
}

/* Output and update for atomic system: '<S411>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;

  /* Chart: '<S631>/LIB_Tim' incorporates:
   *  Constant: '<S631>/Constant6'
   *  UnitDelay: '<S631>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ae,
    LampCtl_LampDelayTim_C, &rtb_LIB_blOut_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_j);

  /* Outputs for Atomic SubSystem: '<S631>/Lib_SR' */
  /* Switch: '<S708>/Switch' incorporates:
   *  Constant: '<S631>/Constant'
   *  Constant: '<S631>/Constant1'
   *  Logic: '<S631>/Logical Operator1'
   *  RelationalOperator: '<S631>/Relational Operator'
   *  RelationalOperator: '<S631>/Relational Operator1'
   *  RelationalOperator: '<S631>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) || (!LampCtl_AutoLampSw) ||
      rtb_LIB_blOut_l) {
    /* Switch: '<S708>/Switch' incorporates:
     *  Constant: '<S708>/Constant'
     */
    LampCtl_LampDelay = false;
  } else {
    /* Switch: '<S708>/Switch' incorporates:
     *  Constant: '<S631>/Constant3'
     *  Constant: '<S631>/Constant4'
     *  Constant: '<S631>/Constant5'
     *  Logic: '<S631>/Logical Operator'
     *  Logic: '<S707>/Logical Operator'
     *  Logic: '<S708>/Logical Operator'
     *  RelationalOperator: '<S631>/Relational Operator3'
     *  RelationalOperator: '<S707>/Relational Operator'
     *  RelationalOperator: '<S707>/Relational Operator1'
     *  UnitDelay: '<S707>/Unit Delay'
     *  UnitDelay: '<S708>/Unit Delay'
     */
    LampCtl_LampDelay = (((LampCtl_LightIntstSta == 2) &&
                          ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n == 2))) || LampCtl_LampDelay);
  }

  /* End of Switch: '<S708>/Switch' */
  /* End of Outputs for SubSystem: '<S631>/Lib_SR' */

  /* Update for UnitDelay: '<S631>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ae = LampCtl_LampDelay;

  /* Update for UnitDelay: '<S707>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode;
}

/* Output and update for atomic system: '<S411>/LightIntstDet' */
static void AppSwcBcm_LightIntstDet(void)
{
  /* Chart: '<S632>/Chart' */
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

  /* End of Chart: '<S632>/Chart' */
}

/* System initialize for atomic system: '<S411>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S633>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_oa);
}

/* Output and update for atomic system: '<S411>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl(void)
{
  /* Chart: '<S633>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S633>/Constant'
   *  Constant: '<S633>/Constant13'
   *  Constant: '<S633>/Constant4'
   *  Constant: '<S633>/Constant5'
   *  Logic: '<S633>/Logical Operator'
   *  Logic: '<S633>/Logical Operator1'
   *  Logic: '<S633>/Logical Operator2'
   *  Logic: '<S633>/Logical Operator3'
   *  RelationalOperator: '<S633>/Relational Operator'
   *  RelationalOperator: '<S633>/Relational Operator1'
   *  RelationalOperator: '<S633>/Relational Operator2'
   *  RelationalOperator: '<S633>/Relational Operator3'
   *  RelationalOperator: '<S633>/Relational Operator5'
   *  UnitDelay: '<S411>/Unit Delay'
   *  UnitDelay: '<S411>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms((!AppSwcBcm_ARID_DEF.LogicalOperator_cx) &&
    (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && (LampCtl_LowBeamSw ||
    LampCtl_PassLightSta || LampCtl_AutoLampSta || LampCtl_KnobBeamFaultSta)) ||
     AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l4 ||
     AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b || LampCtl_LampDelay),
    LampCtl_LowBeamStaTimValid_C, LampCtl_LowBeamStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_oa,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_a);

  /* CCaller: '<S633>/C Caller' */
  BSW_LowBeamDigSts = GetHw_LoBeamDigSts();

  /* Chart: '<S633>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S633>/Constant28'
   *  Constant: '<S633>/Constant29'
   *  Constant: '<S633>/Constant30'
   *  RelationalOperator: '<S633>/Relational Operator4'
   */
  if (BSW_LowBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_a >= (float32)
         LampCtl_LowBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_LowBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_a++;
      AppSwcBcm_ARID_DEF.cnt_heal_al = (uint16)((float32)
        LampCtl_LowBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_a = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_al == 0) {
      LampCtl_LowBeamShortToBat = false;
    } else if (LampCtl_LowBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_al--;
    }
  }

  /* End of Chart: '<S633>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S411>/OTAPwrOffLight' */
static void AppSwcBcm_OTAPwrOffLight(void)
{
  /* Logic: '<S634>/Logical Operator' incorporates:
   *  Constant: '<S634>/Constant'
   *  Constant: '<S634>/Constant1'
   *  Logic: '<S634>/Logical Operator1'
   *  RelationalOperator: '<S634>/Relational Operator'
   *  RelationalOperator: '<S634>/Relational Operator1'
   *  RelationalOperator: '<S634>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_cx =
    (((AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 5) ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 3)) &&
     (!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw));
}

/* Output and update for atomic system: '<S411>/BrakeLampCtl' */
static void AppSwcBcm_BrakeLampCtl(void)
{
  boolean rtb_RelationalOperator2_lx;
  boolean rtb_RelationalOperator8_f;
  boolean rtb_RelationalOperator_c;

  /* RelationalOperator: '<S625>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_c =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VVTM_RegenReqBrkLampOn_flg;

  /* RelationalOperator: '<S625>/Relational Operator8' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S625>/Relational Operator3'
   */
  rtb_RelationalOperator8_f =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLA_flg;

  /* RelationalOperator: '<S625>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S625>/Relational Operator6'
   */
  rtb_RelationalOperator2_lx =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLAVld_flg;

  /* Logic: '<S625>/Logical Operator6' incorporates:
   *  Constant: '<S625>/Constant2'
   *  Logic: '<S625>/Logical Operator'
   *  Logic: '<S625>/Logical Operator1'
   *  Logic: '<S625>/Logical Operator3'
   *  Logic: '<S625>/Logical Operator4'
   *  Logic: '<S625>/Logical Operator5'
   *  RelationalOperator: '<S625>/Relational Operator1'
   *  RelationalOperator: '<S625>/Relational Operator2'
   *  RelationalOperator: '<S625>/Relational Operator7'
   *  RelationalOperator: '<S625>/Relational Operator8'
   *  RelationalOperator: '<S625>/Relational Operator9'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator6 = ((!AppSwcBcm_ARID_DEF.LogicalOperator_cx)
    && (LampCtl_BrakeLightSw || ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)
    && (rtb_RelationalOperator_c || (rtb_RelationalOperator8_f &&
    rtb_RelationalOperator2_lx) ||
        (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCReqBrkLghtOn_flg &&
         AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCReqBrkLghtOnVld_flg)))));
}

/* Output and update for atomic system: '<S411>/ReverseLampCtl' */
static void AppSwcBcm_ReverseLampCtl(void)
{
  boolean rtb_RelationalOperator1_n;

  /* RelationalOperator: '<S652>/Relational Operator1' incorporates:
   *  Constant: '<S652>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_n =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 3);

  /* Logic: '<S652>/Logical Operator' incorporates:
   *  Constant: '<S652>/Constant'
   *  RelationalOperator: '<S652>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_o =
    ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
     rtb_RelationalOperator1_n);
}

/* Output and update for atomic system: '<S411>/PassLampFunc' */
static void AppSwcBcm_PassLampFunc(void)
{
  /* Chart: '<S650>/LIB_Tim' incorporates:
   *  Constant: '<S650>/Constant1'
   *  RelationalOperator: '<S650>/Relational Operator'
   */
  if (LampCtl_PassLightSw) {
    if (AppSwcBcm_ARID_DEF.Cnt_p <= 400) {
      AppSwcBcm_ARID_DEF.Cnt_p++;
      LampCtl_PassLightSta = true;
    } else {
      LampCtl_PassLightSta = false;
    }
  } else {
    LampCtl_PassLightSta = false;
    AppSwcBcm_ARID_DEF.Cnt_p = 0U;
  }

  /* End of Chart: '<S650>/LIB_Tim' */
}

/* System initialize for atomic system: '<S411>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S651>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_iz);
}

/* Output and update for atomic system: '<S411>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl(void)
{
  /* Chart: '<S651>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S651>/Constant'
   *  Constant: '<S651>/Constant13'
   *  Constant: '<S651>/Constant2'
   *  Constant: '<S651>/Constant4'
   *  Logic: '<S651>/Logical Operator'
   *  Logic: '<S651>/Logical Operator1'
   *  Logic: '<S651>/Logical Operator2'
   *  Logic: '<S651>/Logical Operator3'
   *  RelationalOperator: '<S651>/Relational Operator'
   *  RelationalOperator: '<S651>/Relational Operator1'
   *  RelationalOperator: '<S651>/Relational Operator2'
   *  RelationalOperator: '<S651>/Relational Operator3'
   *  UnitDelay: '<S411>/Unit Delay'
   *  UnitDelay: '<S411>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms((!AppSwcBcm_ARID_DEF.LogicalOperator_cx) &&
    (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && (LampCtl_PosLampSw ||
    LampCtl_LowBeamSw || LampCtl_AutoLampSta)) ||
     AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l4 ||
     AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b || LampCtl_KnobBeamFaultSta ||
     LampCtl_LampDelay), LampCtl_PosLampStaTimValid_C,
    LampCtl_PosLampStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_iz,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8);
}

/* System initialize for atomic system: '<S411>/SignalProcess' */
static void AppSwcBcm_SignalProcess_b_Init(void)
{
  /* SystemInitialize for Chart: '<S653>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_oc);

  /* SystemInitialize for Chart: '<S653>/LIB_TPD_10ms13' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);
}

/* Output and update for atomic system: '<S411>/SignalProcess' */
static void AppSwcBcm_SignalProcess_j(void)
{
  uint16 rtb_y;
  uint16 rtb_y_o;
  boolean rtb_LogicalOperator2_jz;
  boolean rtb_Switch;
  boolean rtb_Switch9_d;

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift' */
  /* Constant: '<S653>/Constant48' */
  rtb_y = AppSwcBcm_BitShift3(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift' */

  /* Switch: '<S653>/Switch' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S653>/Switch' incorporates:
     *  Constant: '<S653>/Constant50'
     */
    rtb_Switch = LampCtl_PosLampVal_C;
  } else {
    /* Switch: '<S653>/Switch' incorporates:
     *  Logic: '<S653>/Logical Operator6'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwStVld_flg);
  }

  /* End of Switch: '<S653>/Switch' */

  /* Chart: '<S653>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S653>/Constant19'
   *  Constant: '<S653>/Constant20'
   *  Constant: '<S653>/Constant21'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_of >= (float32)LampCtl_PosLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_PosLampTimValid_C != 0xFFFF)) {
      LampCtl_PosLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_of++;
      AppSwcBcm_ARID_DEF.cnt_heal_a = (uint16)((float32)
        LampCtl_PosLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_of = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a == 0) {
      LampCtl_PosLampSw = false;
    } else if (LampCtl_PosLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift4' */
  /* Constant: '<S653>/Constant1' */
  rtb_y_o = AppSwcBcm_BitShift1_k(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift4' */

  /* Switch: '<S653>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND4'
   */
  if ((rtb_y_o & 1U) != 0U) {
    /* Switch: '<S653>/Switch4' incorporates:
     *  Constant: '<S653>/Constant10'
     */
    rtb_Switch = LampCtl_LowBeamVal_C;
  } else {
    /* Switch: '<S653>/Switch4' incorporates:
     *  Logic: '<S653>/Logical Operator7'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwStVld_flg);
  }

  /* End of Switch: '<S653>/Switch4' */

  /* Chart: '<S653>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S653>/Constant22'
   *  Constant: '<S653>/Constant23'
   *  Constant: '<S653>/Constant24'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_p >= (float32)LampCtl_LowBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_LowBeamTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_p++;
      AppSwcBcm_ARID_DEF.cnt_heal_g = (uint16)((float32)
        LampCtl_LowBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_p = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g == 0) {
      LampCtl_LowBeamSw = false;
    } else if (LampCtl_LowBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_g--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift7' */
  /* Constant: '<S653>/Constant12' */
  rtb_y_o = AppSwcBcm_BitShift2(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift7' */

  /* Switch: '<S653>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND7'
   */
  if ((rtb_y_o & 1U) != 0U) {
    /* Switch: '<S653>/Switch7' incorporates:
     *  Constant: '<S653>/Constant11'
     */
    rtb_Switch = LampCtl_HiBeamVal_C;
  } else {
    /* Switch: '<S653>/Switch7' incorporates:
     *  Logic: '<S653>/Logical Operator8'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSHiBeamSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSHiBeamSwStVld_flg);
  }

  /* End of Switch: '<S653>/Switch7' */

  /* Chart: '<S653>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S653>/Constant25'
   *  Constant: '<S653>/Constant26'
   *  Constant: '<S653>/Constant27'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_j >= (float32)LampCtl_HiBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_HiBeamTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j++;
      AppSwcBcm_ARID_DEF.cnt_heal_p = (uint16)((float32)
        LampCtl_HiBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_p == 0) {
      LampCtl_HiBeamSw = false;
    } else if (LampCtl_HiBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_p--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift1' */
  /* Constant: '<S653>/Constant3' */
  rtb_y = AppSwcBcm_BitShift1_m(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift1' */

  /* Switch: '<S653>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S653>/Switch1' incorporates:
     *  Constant: '<S653>/Constant2'
     */
    rtb_Switch = LampCtl_PassLightVal_C;
  } else {
    /* Switch: '<S653>/Switch1' incorporates:
     *  Logic: '<S653>/Logical Operator1'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSOvrVehBeamSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSOvrVehBeamSwStVld_flg);
  }

  /* End of Switch: '<S653>/Switch1' */

  /* Chart: '<S653>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S653>/Constant28'
   *  Constant: '<S653>/Constant29'
   *  Constant: '<S653>/Constant30'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_nt >= (float32)
         LampCtl_PassLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_PassLightTimValid_C != 0xFFFF)) {
      LampCtl_PassLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_nt++;
      AppSwcBcm_ARID_DEF.cnt_heal_bx = (uint16)((float32)
        LampCtl_PassLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_nt = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bx == 0) {
      LampCtl_PassLightSw = false;
    } else if (LampCtl_PassLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bx--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift2' */
  /* Constant: '<S653>/Constant53' */
  rtb_y = AppSwcBcm_BitShift4(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift8' */
  /* Constant: '<S653>/Constant4' */
  rtb_y_o = AppSwcBcm_BitShift6(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift8' */

  /* Logic: '<S653>/Logical Operator3' */
  rtb_Switch =
    (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwSt_flg &&
     AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwStVld_flg);

  /* Logic: '<S653>/Logical Operator2' */
  rtb_LogicalOperator2_jz =
    (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwSt_flg &&
     AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwStVld_flg);

  /* Switch: '<S653>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND8'
   */
  if ((rtb_y_o & 1U) != 0U) {
    /* Switch: '<S653>/Switch9' incorporates:
     *  Constant: '<S653>/Constant5'
     */
    rtb_Switch9_d = LampCtl_TurnIndcrRVal_C;
  } else {
    /* Switch: '<S653>/Switch9' incorporates:
     *  Logic: '<S653>/Logical Operator'
     *  Logic: '<S653>/Logical Operator10'
     */
    rtb_Switch9_d = (rtb_Switch && (!rtb_LogicalOperator2_jz));
  }

  /* End of Switch: '<S653>/Switch9' */

  /* Chart: '<S653>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S653>/Constant37'
   *  Constant: '<S653>/Constant38'
   *  Constant: '<S653>/Constant39'
   */
  if (rtb_Switch9_d) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_nj >= (float32)
         LampCtl_TurnIndcrRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_nj++;
      AppSwcBcm_ARID_DEF.cnt_heal_ca = (uint16)((float32)
        LampCtl_TurnIndcrRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S653>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S653>/Constant37'
     *  Constant: '<S653>/Constant38'
     *  Constant: '<S653>/Constant39'
     *  Constant: '<S653>/Constant40'
     *  Constant: '<S653>/Constant41'
     *  Constant: '<S653>/Constant42'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_m >= (float32)
         LampCtl_TurnIndcrLaneRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m++;
      AppSwcBcm_ARID_DEF.cnt_heal_b = (uint16)((float32)
        LampCtl_TurnIndcrLaneRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_nj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ca == 0) {
      LampCtl_TurnIndcrRSw = false;
    } else if (LampCtl_TurnIndcrRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ca--;
    }

    /* Chart: '<S653>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S653>/Constant38'
     *  Constant: '<S653>/Constant41'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_m = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_b == 0) {
      LampCtl_TurnIndcrLaneRSw = false;
    } else if (LampCtl_TurnIndcrLaneRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_b--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms6' */

  /* Switch: '<S653>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S653>/Switch2' incorporates:
     *  Constant: '<S653>/Constant54'
     */
    rtb_LogicalOperator2_jz = LampCtl_TurnIndcrLVal_C;
  } else {
    /* Switch: '<S653>/Switch2' incorporates:
     *  Logic: '<S653>/Logical Operator12'
     *  Logic: '<S653>/Logical Operator5'
     *  UnitDelay: '<S653>/Unit Delay1'
     */
    rtb_LogicalOperator2_jz = (rtb_LogicalOperator2_jz &&
      (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k3));
  }

  /* End of Switch: '<S653>/Switch2' */

  /* Chart: '<S653>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S653>/Constant31'
   *  Constant: '<S653>/Constant32'
   *  Constant: '<S653>/Constant33'
   */
  if (rtb_LogicalOperator2_jz) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o5 >= (float32)
         LampCtl_TurnIndcrLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o5++;
      AppSwcBcm_ARID_DEF.cnt_heal_ig = (uint16)((float32)
        LampCtl_TurnIndcrLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S653>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S653>/Constant31'
     *  Constant: '<S653>/Constant32'
     *  Constant: '<S653>/Constant33'
     *  Constant: '<S653>/Constant34'
     *  Constant: '<S653>/Constant35'
     *  Constant: '<S653>/Constant36'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_oh >= (float32)
         LampCtl_TurnIndcrLaneLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_oh++;
      AppSwcBcm_ARID_DEF.cnt_heal_f = (uint16)((float32)
        LampCtl_TurnIndcrLaneLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o5 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ig == 0) {
      LampCtl_TurnIndcrLSw = false;
    } else if (LampCtl_TurnIndcrLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ig--;
    }

    /* Chart: '<S653>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S653>/Constant32'
     *  Constant: '<S653>/Constant35'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_oh = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_f == 0) {
      LampCtl_TurnIndcrLaneLSw = false;
    } else if (LampCtl_TurnIndcrLaneLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_f--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift3' */
  /* Constant: '<S653>/Constant55' */
  rtb_y_o = AppSwcBcm_BitShift8(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift3' */

  /* Switch: '<S653>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND3'
   */
  if ((rtb_y_o & 1U) != 0U) {
    /* Switch: '<S653>/Switch3' incorporates:
     *  Constant: '<S653>/Constant56'
     */
    rtb_LogicalOperator2_jz = LampCtl_FogLampRVal_C;
  } else {
    /* Switch: '<S653>/Switch3' incorporates:
     *  DataTypeConversion: '<S653>/Data Type Conversion3'
     *  Logic: '<S653>/Logical Operator9'
     */
    rtb_LogicalOperator2_jz = (BSW_J346FogLampR == 0);
  }

  /* End of Switch: '<S653>/Switch3' */

  /* Chart: '<S653>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S653>/Constant43'
   *  Constant: '<S653>/Constant44'
   *  Constant: '<S653>/Constant45'
   */
  if (rtb_LogicalOperator2_jz) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fe >= (float32)LampCtl_FogLampRTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampRTimValid_C != 0xFFFF)) {
      LampCtl_FogLampRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fe++;
      AppSwcBcm_ARID_DEF.cnt_heal_m = (uint16)((float32)
        LampCtl_FogLampRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fe = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m == 0) {
      LampCtl_FogLampRSw = false;
    } else if (LampCtl_FogLampRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_m--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms9' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift5' */
  /* Switch: '<S653>/Switch5' incorporates:
   *  Constant: '<S653>/Constant59'
   *  MATLAB Function: '<S721>/bit_shift'
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND5'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 9 & 1U) != 0U) {
    /* Switch: '<S653>/Switch5' incorporates:
     *  Constant: '<S653>/Constant60'
     */
    rtb_LogicalOperator2_jz = LampCtl_HazardLightVal_C;
  } else {
    /* Switch: '<S653>/Switch5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     *  DataTypeConversion: '<S653>/Data Type Conversion5'
     */
    rtb_LogicalOperator2_jz =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPHzrdKey_flg;
  }

  /* End of Switch: '<S653>/Switch5' */
  /* End of Outputs for SubSystem: '<S653>/Bit Shift5' */

  /* Chart: '<S653>/LIB_TPD_10ms10' incorporates:
   *  Constant: '<S653>/Constant46'
   *  Constant: '<S653>/Constant47'
   *  Constant: '<S653>/Constant49'
   */
  if (rtb_LogicalOperator2_jz) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_oj >= (float32)
         LampCtl_HazardLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HazardLightTimValid_C != 0xFFFF)) {
      LampCtl_HazardLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_oj++;
      AppSwcBcm_ARID_DEF.cnt_heal_n = (uint16)((float32)
        LampCtl_HazardLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_oj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n == 0) {
      LampCtl_HazardLightSw = false;
    } else if (LampCtl_HazardLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms10' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift11' */
  /* Constant: '<S653>/Constant73' */
  rtb_y = AppSwcBcm_BitShift12_e(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift6' */
  /* Switch: '<S653>/Switch6' incorporates:
   *  Constant: '<S653>/Constant61'
   *  Constant: '<S653>/Constant62'
   *  DataTypeConversion: '<S653>/Data Type Conversion6'
   *  MATLAB Function: '<S722>/bit_shift'
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND6'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 10 & 1U) != 0U) {
    rtb_LogicalOperator2_jz = LampCtl_BrakeLightVal_C;
  } else {
    rtb_LogicalOperator2_jz = (BSW_J313BrakeLoSw != 0);
  }

  /* End of Outputs for SubSystem: '<S653>/Bit Shift6' */

  /* Chart: '<S653>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S653>/Constant14'
   *  Constant: '<S653>/Constant15'
   *  Constant: '<S653>/Constant16'
   *  Switch: '<S653>/Switch6'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_LogicalOperator2_jz, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_oc,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11);

  /* Switch: '<S653>/Switch12' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND11'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S653>/Switch12' incorporates:
     *  Constant: '<S653>/Constant74'
     */
    rtb_LogicalOperator2_jz = LampCtl_BrakeLightVal_C;
  } else {
    /* Switch: '<S653>/Switch12' incorporates:
     *  DataTypeConversion: '<S653>/Data Type Conversion13'
     *  Logic: '<S653>/Logical Operator14'
     */
    rtb_LogicalOperator2_jz = (BSW_J339BrakeHiSw == 0);
  }

  /* End of Switch: '<S653>/Switch12' */

  /* Chart: '<S653>/LIB_TPD_10ms13' incorporates:
   *  Constant: '<S653>/Constant70'
   *  Constant: '<S653>/Constant71'
   *  Constant: '<S653>/Constant72'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_LogicalOperator2_jz, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms13);

  /* Logic: '<S653>/Logical Operator13' */
  LampCtl_BrakeLightSw = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_oc ||
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift9' */
  /* Constant: '<S653>/Constant6' */
  rtb_y_o = AppSwcBcm_BitShift7(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift9' */

  /* Switch: '<S653>/Switch10' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND9'
   */
  if ((rtb_y_o & 1U) != 0U) {
    /* Switch: '<S653>/Switch10' incorporates:
     *  Constant: '<S653>/Constant8'
     */
    rtb_LogicalOperator2_jz = LampCtl_AutoLampVal_C;
  } else {
    /* Switch: '<S653>/Switch10' incorporates:
     *  Logic: '<S653>/Logical Operator4'
     */
    rtb_LogicalOperator2_jz =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLampAutoSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLampAutoStVld_flg);
  }

  /* End of Switch: '<S653>/Switch10' */

  /* Chart: '<S653>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S653>/Constant13'
   *  Constant: '<S653>/Constant63'
   *  Constant: '<S653>/Constant9'
   */
  if (rtb_LogicalOperator2_jz) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o >= (float32)LampCtl_AutoLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_AutoLampTimValid_C != 0xFFFF)) {
      LampCtl_AutoLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o++;
      AppSwcBcm_ARID_DEF.cnt_heal_c = (uint16)((float32)
        LampCtl_AutoLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c == 0) {
      LampCtl_AutoLampSw = false;
    } else if (LampCtl_AutoLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_c--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S653>/Bit Shift10' */
  /* Constant: '<S653>/Constant68' */
  rtb_y = AppSwcBcm_BitShift9(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S653>/Bit Shift10' */

  /* Switch: '<S653>/Switch11' incorporates:
   *  S-Function (sfix_bitop): '<S653>/Bitwise AND10'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S653>/Switch11' incorporates:
     *  Constant: '<S653>/Constant69'
     */
    rtb_LogicalOperator2_jz = LampCtl_FogLampFVal_C;
  } else {
    /* Switch: '<S653>/Switch11' incorporates:
     *  DataTypeConversion: '<S653>/Data Type Conversion9'
     *  Logic: '<S653>/Logical Operator11'
     */
    rtb_LogicalOperator2_jz = (BSW_J322FogLampF == 0);
  }

  /* End of Switch: '<S653>/Switch11' */

  /* Chart: '<S653>/LIB_TPD_10ms12' incorporates:
   *  Constant: '<S653>/Constant64'
   *  Constant: '<S653>/Constant66'
   *  Constant: '<S653>/Constant67'
   */
  if (rtb_LogicalOperator2_jz) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fy >= (float32)LampCtl_FogLampFTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampFTimValid_C != 0xFFFF)) {
      LampCtl_FogLampFSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fy++;
      AppSwcBcm_ARID_DEF.cnt_heal_j = (uint16)((float32)
        LampCtl_FogLampFTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fy = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_j == 0) {
      LampCtl_FogLampFSw = false;
    } else if (LampCtl_FogLampFTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_j--;
    }
  }

  /* End of Chart: '<S653>/LIB_TPD_10ms12' */

  /* MultiPortSwitch: '<S653>/Multiport Switch' */
  switch (BSW_RKEReq) {
   case 0:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant'
     */
    LampCtl_RKEReq = 0U;
    break;

   case 17:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant17'
     */
    LampCtl_RKEReq = 1U;
    break;

   case 18:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant18'
     */
    LampCtl_RKEReq = 2U;
    break;

   case 35:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant51'
     */
    LampCtl_RKEReq = 3U;
    break;

   case 34:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant52'
     */
    LampCtl_RKEReq = 4U;
    break;

   case 49:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant57'
     */
    LampCtl_RKEReq = 5U;
    break;

   case 50:
    /* MultiPortSwitch: '<S653>/Multiport Switch' incorporates:
     *  Constant: '<S653>/Constant58'
     */
    LampCtl_RKEReq = 6U;
    break;
  }

  /* End of MultiPortSwitch: '<S653>/Multiport Switch' */

  /* DataTypeConversion: '<S653>/Data Type Conversion12' */
  LampCtl_LightIntstVal = BSW_J125LightIntst;

  /* Update for UnitDelay: '<S653>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k3 = rtb_Switch;
}

/*
 * System initialize for function-call system:
 *    '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
  (ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
   *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S780>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S780>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(boolean rtu_Lib_blIn,
  boolean *rty_Lib_blOut, ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S780>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_e(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S780>/Lib_RiseEdgeDetInit' */
}

/*
 * System initialize for function-call system:
 *    '<S805>/Lib_ChangeEdge'
 *    '<S805>/Lib_ChangeEdge1'
 *    '<S805>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge_Init(ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S809>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S805>/Lib_ChangeEdge'
 *    '<S805>/Lib_ChangeEdge1'
 *    '<S805>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge(float32 rtu_Lib_In, float32 rtu_Lib_InNow,
  float32 rtu_Lib_InBefore, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S809>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
  }

  /* Logic: '<S809>/Logical Operator' incorporates:
   *  Delay: '<S809>/Delay'
   *  RelationalOperator: '<S809>/Relational Operator'
   *  RelationalOperator: '<S809>/Relational Operator1'
   */
  *rty_Lib_blOut = ((rtu_Lib_InNow == rtu_Lib_In) &&
                    (AppSwcBcm__ARID_DEF_arg->Delay_DSTATE == rtu_Lib_InBefore));

  /* Update for Delay: '<S809>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
}

/*
 * System initialize for function-call system:
 *    '<S764>/Pri4Func.Turn'
 *    '<S764>/Pri4Func.Turn1'
 *    '<S764>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y)
{
  /* SystemInitialize for Chart: '<S821>/Turn' */
  *rty_y = false;
}

/*
 * Output and update for function-call system:
 *    '<S764>/Pri4Func.Turn'
 *    '<S764>/Pri4Func.Turn1'
 *    '<S764>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S821>/Turn' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c80_LampCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c80_LampCtl_Lib = 1U;
    *rty_y = !rtu_x;
  }

  /* End of Chart: '<S821>/Turn' */
}

/*
 * System initialize for atomic system:
 *    '<S765>/TurnIndcrDig'
 *    '<S765>/TurnIndcrDig1'
 *    '<S765>/TurnIndcrDig2'
 *    '<S765>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig_Init(boolean *rty_LIB_blErrFlg)
{
  *rty_LIB_blErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S765>/TurnIndcrDig'
 *    '<S765>/TurnIndcrDig1'
 *    '<S765>/TurnIndcrDig2'
 *    '<S765>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig(boolean rtu_LIB_blIn, boolean rtu_LIB_blIn2,
  boolean rtu_LIB_blRst, float32 rtu_LIB_s32Ts, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, uint8 rtu_LIB_u8Cnt, boolean *rty_LIB_blErrFlg,
  ARID_DEF_TurnIndcrDig_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;
  float32 tmp_0;

  /* Chart: '<S765>/TurnIndcrDig' */
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

  /* End of Chart: '<S765>/TurnIndcrDig' */
}

/*
 * Output and update for atomic system:
 *    '<S844>/Lib_BothEdgeDet'
 *    '<S890>/Lib_BothEdgeDet'
 *    '<S890>/Lib_BothEdgeDet1'
 *    '<S890>/Lib_BothEdgeDet2'
 *    '<S890>/Lib_BothEdgeDet3'
 */
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S845>/Logical Operator2' incorporates:
   *  Logic: '<S845>/Logical Operator1'
   *  Logic: '<S845>/Logical Operator3'
   *  Logic: '<S845>/Logical Operator4'
   *  Logic: '<S845>/Logical Operator5'
   *  UnitDelay: '<S845>/Unit Delay'
   */
  *rty_Lib_blOut = ((AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_Lib_blIn))
                    || (rtu_Lib_blIn &&
                        (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE)));

  /* Update for UnitDelay: '<S845>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S654>/HazardLightLogic' */
static boolean AppSwcBcm_EmerOff(void)
{
  boolean guard1 = false;
  boolean y;

  /* UnitDelay: '<S654>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.Lib_blIn_j = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_li;

  /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet1' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_j,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ko,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

  /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet1' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ko) {
    guard1 = true;
  } else {
    /* UnitDelay: '<S654>/Unit Delay5' */
    AppSwcBcm_ARID_DEF.Lib_blIn_nd = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_f;

    /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet2' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_nd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ib,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

    /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet2' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ib) {
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

/* Function for Chart: '<S654>/HazardLightLogic' */
static boolean AppSwcBcm_HazardOff(void)
{
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_dn = LampCtl_HazardLightSw;

  /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_dn,
    &AppSwcBcm_ARID_DEF.LogicalOperator_d1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);

  /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_d1) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
  } else {
    y = false;
  }

  return y;
}

/* Function for Chart: '<S654>/HazardLightLogic' */
static boolean AppSwcBcm_TurnOff(void)
{
  boolean guard1 = false;
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_dk = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 1);

  /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet4' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_dk,
    &AppSwcBcm_ARID_DEF.LogicalOperator_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet4);

  /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet4' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_e) {
    guard1 = true;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_py = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta ==
      2);

    /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet5' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_py,
      &AppSwcBcm_ARID_DEF.LogicalOperator_gh,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet5);

    /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet5' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_gh) {
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

/* Function for Chart: '<S654>/HazardLightLogic' */
static boolean AppSwcBcm_CrashHazardOff(void)
{
  boolean y;
  y = false;
  if (AppSwcBcm_ARID_DEF.CrashCnt >= 80) {
    AppSwcBcm_ARID_DEF.Lib_blIn_dn = LampCtl_HazardLightSw;

    /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_dn,
      &AppSwcBcm_ARID_DEF.LogicalOperator_d1,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);

    /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_d1) {
      y = true;
      AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
    }
  } else {
    AppSwcBcm_ARID_DEF.CrashCnt++;
  }

  return y;
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_TurnFunc(void)
{
  LampCtl_TurnIndcrRst = !LampCtl_TurnIndcrRst;
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_Pri1Func(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_EnFunc(void)
{
  LampCtl_TurnIndcrPrd = 0U;
  LampCtl_TurnIndcrWdt = 0U;
  LampCtl_TurnIndcrRFlashCnt = 0U;
  LampCtl_TurnIndcrLFlashCnt = 0U;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_Pri2Func(void)
{
  LampCtl_TurnIndcrPrd = 4U;
  LampCtl_TurnIndcrWdt = 2U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_Pri4Func(void)
{
  switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide) {
   case 2:
    AppSwcBcm_ARID_DEF.x = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S764>/Pri4Func.Turn' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x, &AppSwcBcm_ARID_DEF.y_g,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn);

    /* End of Outputs for SubSystem: '<S764>/Pri4Func.Turn' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_g;
    if (LampCtl_TurnIndcrMod == 1) {
      LampCtl_TurnIndcrPrd = 16U;
      LampCtl_TurnIndcrWdt = 8U;
      LampCtl_TurnIndcrRFlashCnt = 3U;
      LampCtl_TurnIndcrLFlashCnt = 0U;
    } else {
      LampCtl_TurnIndcrPrd = 16U;
      LampCtl_TurnIndcrWdt = 8U;
      LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
      LampCtl_TurnIndcrLFlashCnt = 0U;
    }
    break;

   case 3:
    AppSwcBcm_ARID_DEF.x_e = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S764>/Pri4Func.Turn1' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_e, &AppSwcBcm_ARID_DEF.y_k,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn1);

    /* End of Outputs for SubSystem: '<S764>/Pri4Func.Turn1' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_k;
    if (LampCtl_TurnIndcrMod == 3) {
      LampCtl_TurnIndcrPrd = 16U;
      LampCtl_TurnIndcrWdt = 8U;
      LampCtl_TurnIndcrRFlashCnt = 0U;
      LampCtl_TurnIndcrLFlashCnt = 3U;
    } else {
      LampCtl_TurnIndcrPrd = 16U;
      LampCtl_TurnIndcrWdt = 8U;
      LampCtl_TurnIndcrRFlashCnt = 0U;
      LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
    }
    break;

   case 1:
    LampCtl_TurnIndcrPrd = 16U;
    LampCtl_TurnIndcrWdt = 8U;
    LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
    LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
    AppSwcBcm_ARID_DEF.x_m = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S764>/Pri4Func.Turn2' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_m, &AppSwcBcm_ARID_DEF.y,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn2);

    /* End of Outputs for SubSystem: '<S764>/Pri4Func.Turn2' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y;
    break;
  }

  if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 3) &&
      LampCtl_TurnIndcrLOpen) {
    LampCtl_TurnIndcrPrd = 8U;
    LampCtl_TurnIndcrWdt = 4U;
  } else if (((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 3) ||
              (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 1)) &&
             LampCtl_TurnIndcrLShort) {
    LampCtl_TurnIndcrPrd = 0U;
    LampCtl_TurnIndcrWdt = 0U;
  }

  if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 2) &&
      LampCtl_TurnIndcrROpen) {
    LampCtl_TurnIndcrPrd = 8U;
    LampCtl_TurnIndcrWdt = 4U;
  } else if (((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 2) ||
              (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 1)) &&
             LampCtl_TurnIndcrRShort) {
    LampCtl_TurnIndcrPrd = 0U;
    LampCtl_TurnIndcrWdt = 0U;
  }
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_VehModeFunc(void)
{
  switch (LampCtl_VehModeSta) {
   case 1:
    LampCtl_TurnIndcrPrd = 16U;
    LampCtl_TurnIndcrWdt = 8U;
    LampCtl_TurnIndcrRFlashCnt = 1U;
    LampCtl_TurnIndcrLFlashCnt = 1U;
    break;

   case 2:
    LampCtl_TurnIndcrPrd = 16U;
    LampCtl_TurnIndcrWdt = 8U;
    LampCtl_TurnIndcrRFlashCnt = 2U;
    LampCtl_TurnIndcrLFlashCnt = 2U;
    break;

   case 3:
    LampCtl_TurnIndcrPrd = 16U;
    LampCtl_TurnIndcrWdt = 8U;
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

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_AntiLckFunc(void)
{
  LampCtl_TurnIndcrPrd = 8U;
  LampCtl_TurnIndcrWdt = 4U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_ov = AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;

  /* Outputs for Function Call SubSystem: '<S764>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_ov,
    &AppSwcBcm_ARID_DEF.RelationalOperator_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5AntiLckFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S764>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_c) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_ArmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 16U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
  AppSwcBcm_ARID_DEF.Lib_blIn_h3 = AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;

  /* Outputs for Function Call SubSystem: '<S764>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_h3,
    &AppSwcBcm_ARID_DEF.RelationalOperator_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5ArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S764>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_a) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_DisarmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_c0 = AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;

  /* Outputs for Function Call SubSystem: '<S764>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_c0,
    &AppSwcBcm_ARID_DEF.RelationalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5DisarmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S764>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_b) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_PartArmedFunc(void)
{
  if (LampCtl_PartArmedSta == 2) {
    LampCtl_TurnIndcrPrd = 16U;
    LampCtl_TurnIndcrWdt = 8U;
    LampCtl_TurnIndcrRFlashCnt = 3U;
    LampCtl_TurnIndcrLFlashCnt = 3U;
  } else {
    LampCtl_TurnIndcrPrd = 8U;
    LampCtl_TurnIndcrWdt = 4U;
    LampCtl_TurnIndcrRFlashCnt = 3U;
    LampCtl_TurnIndcrLFlashCnt = 3U;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_i = AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;

  /* Outputs for Function Call SubSystem: '<S764>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_i,
    &AppSwcBcm_ARID_DEF.RelationalOperator_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5PartArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S764>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_h) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_RodBeamFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_SeekFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = 10U;
  LampCtl_TurnIndcrLFlashCnt = 10U;
  AppSwcBcm_ARID_DEF.Lib_blIn_fg = AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;

  /* Outputs for Function Call SubSystem: '<S764>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_fg,
    &AppSwcBcm_ARID_DEF.RelationalOperator_hv,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5SeekFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S764>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_hv) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S654>/TurnIndcrArb2' */
static void AppSwcBcm_TrunkWarnFunc(void)
{
  LampCtl_TurnIndcrPrd = 8U;
  LampCtl_TurnIndcrWdt = 4U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
}

/* Function for Chart: '<S755>/Chart1' */
static void AppSwcBcm_PwrOnDelayFunc(void)
{
  sint32 tmp;
  if (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) {
    tmp = AppSwcBcm_ARID_DEF.DelayCnt + 1;
    if (AppSwcBcm_ARID_DEF.DelayCnt + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.DelayCnt = (uint16)tmp;
  }
}

/* Function for Chart: '<S755>/Chart1' */
static void AppSwcBcm_CrashClearFunc(void)
{
  if (AppSwcBcm_ARID_DEF.ClearCnt >= 80) {
    AppSwcBcm_ARID_DEF.Lib_blIn_em = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode ==
      0);

    /* Outputs for Function Call SubSystem: '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit' */
    AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_em,
      &AppSwcBcm_ARID_DEF.LogicalOperator_dl,
      &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

    /* End of Outputs for SubSystem: '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_dl) {
      AppSwcBcm_ARID_DEF.PwrOffFlg = true;
      AppSwcBcm_ARID_DEF.PwrOnFlg = false;
    }

    if (AppSwcBcm_ARID_DEF.PwrOffFlg) {
      AppSwcBcm_ARID_DEF.Lib_blIn_n0 =
        (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_n0,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ix,
        &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.PwrOnFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_ix ||
        AppSwcBcm_ARID_DEF.PwrOnFlg);
    }
  } else {
    AppSwcBcm_ARID_DEF.ClearCnt++;
  }
}

/* System initialize for atomic system: '<S411>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S752>/Chart' incorporates:
   *  SubSystem: '<S772>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_f);

  /* SystemInitialize for Chart: '<S754>/Chart' incorporates:
   *  SubSystem: '<S776>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_j);

  /* SystemInitialize for Chart: '<S755>/Chart1' incorporates:
   *  SubSystem: '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S755>/Chart1' incorporates:
   *  SubSystem: '<S779>/CrashClearFunc.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S756>/Chart' incorporates:
   *  SubSystem: '<S790>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_b);

  /* SystemInitialize for Chart: '<S759>/Chart' incorporates:
   *  SubSystem: '<S805>/Lib_ChangeEdge'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

  /* SystemInitialize for Chart: '<S759>/Chart' incorporates:
   *  SubSystem: '<S805>/Lib_ChangeEdge1'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

  /* SystemInitialize for Chart: '<S759>/Chart' incorporates:
   *  SubSystem: '<S805>/Lib_ChangeEdge2'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

  /* SystemInitialize for Chart: '<S763>/Chart' incorporates:
   *  SubSystem: '<S818>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_o);

  /* SystemInitialize for Chart: '<S654>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S764>/Pri4Func.Turn'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_g);

  /* SystemInitialize for Chart: '<S654>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S764>/Pri4Func.Turn1'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_k);

  /* SystemInitialize for Chart: '<S654>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S764>/Pri4Func.Turn2'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y);

  /* SystemInitialize for Chart: '<S765>/TurnIndcrDig' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_f);

  /* SystemInitialize for Chart: '<S765>/TurnIndcrDig1' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_o);

  /* SystemInitialize for Chart: '<S765>/TurnIndcrDig2' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_m);

  /* SystemInitialize for Chart: '<S765>/TurnIndcrDig3' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* SystemInitialize for Chart: '<S770>/Chart' incorporates:
   *  SubSystem: '<S853>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_l);

  /* SystemInitialize for Chart: '<S770>/Chart' incorporates:
   *  SubSystem: '<S853>/Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S770>/Chart' incorporates:
   *  SubSystem: '<S853>/Lib_RiseEdgeDetInit2'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);
}

/* Output and update for atomic system: '<S411>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl(void)
{
  sint32 tmp;
  uint8 rtb_RelationalOperator_d_tmp;
  boolean RelationalOperator;
  boolean RelationalOperator6;
  boolean RelationalOperator8_l;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_LogicalOperator10_fp;
  boolean rtb_LogicalOperator1_l5;
  boolean rtb_LogicalOperator4_kr;
  boolean rtb_LogicalOperator6_mt;
  boolean rtb_LogicalOperator8_h;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator11_e;
  boolean rtb_RelationalOperator14_j;
  boolean rtb_RelationalOperator19;
  boolean rtb_RelationalOperator1_ad;
  boolean rtb_RelationalOperator23;
  boolean rtb_RelationalOperator3_h;
  boolean rtb_RelationalOperator5;
  boolean rtb_RelationalOperator5_by;
  boolean rtb_RelationalOperator6_n;
  boolean rtb_RelationalOperator7_og;
  boolean rtb_RelationalOperator9_pm;
  boolean rtb_RelationalOperator_bx;

  /* RelationalOperator: '<S654>/Relational Operator5' */
  rtb_RelationalOperator5 = !AppSwcBcm_ARID_DEF.LogicalOperator_cx;

  /* RelationalOperator: '<S761>/Relational Operator6' incorporates:
   *  Inport: '<Root>/IPM_EHB_B_CHA'
   *  RelationalOperator: '<S757>/Relational Operator1'
   */
  rtb_RelationalOperator6_n =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA())
    ->VIPM_EHBReqBrkLiOn_flg;

  /* Logic: '<S757>/Logical Operator' incorporates:
   *  Constant: '<S757>/Constant'
   *  RelationalOperator: '<S757>/Relational Operator'
   */
  LampCtl_EmerSta = (rtb_RelationalOperator6_n &&
                     (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2));

  /* RelationalOperator: '<S760>/Relational Operator4' */
  rtb_RelationalOperator6_n = LampCtl_EmerSta;

  /* Chart: '<S654>/TurnIndcrLogic' incorporates:
   *  UnitDelay: '<S654>/Unit Delay2'
   *  UnitDelay: '<S654>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c100_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c100_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
    LampCtl_TurnIndcrMod = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib) {
     case AppSwcBcm_IN_OFF_p:
      if (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_p = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S767>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_p,
          &AppSwcBcm_ARID_DEF.LogicalOperator_a,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);

        /* End of Outputs for SubSystem: '<S767>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_a || LampCtl_TurnIndcrRSw) {
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
      if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) ||
          LampCtl_TurnIndcrLaneRSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnL == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrLSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 4U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_el = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S767>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_el,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_dh);

        /* End of Outputs for SubSystem: '<S767>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h) {
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
      if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) ||
          LampCtl_TurnIndcrLaneLSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnR == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_p;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrRSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_p = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S767>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_p,
          &AppSwcBcm_ARID_DEF.LogicalOperator_a,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);

        /* End of Outputs for SubSystem: '<S767>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_a) {
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
      if (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_el = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S767>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_el,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_dh);

        /* End of Outputs for SubSystem: '<S767>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h || LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_TurnL;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 2U;
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_ShortFlash;
        }
      }
    }
  }

  /* End of Chart: '<S654>/TurnIndcrLogic' */

  /* Chart: '<S654>/HazardLightLogic' incorporates:
   *  UnitDelay: '<S654>/Unit Delay4'
   *  UnitDelay: '<S654>/Unit Delay5'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c86_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c86_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_OFF_i;
    LampCtl_HazardLightSta = false;
    LampCtl_EmerHazardLightSta = false;
    AppSwcBcm_ARID_DEF.CrashCnt = 0U;
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib) {
     case AppSwcBcm_IN_EmerON:
      if (((!AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_f) &&
           (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_li)) ||
          AppSwcBcm_ARID_DEF.CrashHazardOff) {
        /* {Lib_RiseEdgeDet(LampCtl_HazardLightSw)} */
        AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_OFF_i;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
        AppSwcBcm_ARID_DEF.CrashCnt = 0U;
      } else {
        AppSwcBcm_ARID_DEF.CrashHazardOff = AppSwcBcm_CrashHazardOff();
      }
      break;

     case AppSwcBcm_IN_OFF_i:
      AppSwcBcm_ARID_DEF.Lib_blIn_j = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_li;

      /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_j,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ko,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

      /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ko) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_nd = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_f;

        /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_nd,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ib,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

        /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ib) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_dn = LampCtl_HazardLightSw;

          /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_dn,
            &AppSwcBcm_ARID_DEF.LogicalOperator_d1,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);

          /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_d1) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_j3 =
              (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.HazardLightSta == 1);

            /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet3' */
            AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_j3,
              &AppSwcBcm_ARID_DEF.LogicalOperator_nm,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_b);

            /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet3' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_nm ||
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
        AppSwcBcm_ARID_DEF.Lib_blIn_j3 =
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_j3,
          &AppSwcBcm_ARID_DEF.LogicalOperator_nm,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_b);

        /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_EmerON;
        LampCtl_EmerHazardLightSta = true;
        LampCtl_HazardLightSta = false;
      } else if (AppSwcBcm_HazardOff() || AppSwcBcm_TurnOff()) {
        AppSwcBcm_ARID_DEF.Lib_blIn_j3 =
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S758>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_j3,
          &AppSwcBcm_ARID_DEF.LogicalOperator_nm,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_b);

        /* End of Outputs for SubSystem: '<S758>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_OFF_i;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
        AppSwcBcm_ARID_DEF.CrashCnt = 0U;
      }
      break;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_ON_h;
      LampCtl_HazardLightSta = true;
      AppSwcBcm_TurnOff();
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_EmerON;
      LampCtl_EmerHazardLightSta = true;
      LampCtl_HazardLightSta = false;
    }
  }

  /* End of Chart: '<S654>/HazardLightLogic' */

  /* RelationalOperator: '<S760>/Relational Operator' */
  RelationalOperator = LampCtl_EmerHazardLightSta;

  /* Chart: '<S654>/TurnIndcrSelect' */
  if (AppSwcBcm_ARID_DEF.is_active_c118_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c118_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib) {
     case AppSwcBcm_IN_Off_i:
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
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_i;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 3U;
      }
      break;

     case AppSwcBcm_IN_TurnLROn:
      if (!LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_i;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 1U;
      }
      break;

     default:
      /* case IN_TurnROn: */
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_i;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S654>/TurnIndcrSelect' */

  /* RelationalOperator: '<S760>/Relational Operator8' incorporates:
   *  Constant: '<S760>/Constant8'
   */
  RelationalOperator8_l = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide != 0);

  /* Logic: '<S760>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S760>/Relational Operator'
   *  RelationalOperator: '<S760>/Relational Operator4'
   */
  rtb_LogicalOperator8_h = (LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* Chart: '<S752>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c37_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c37_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_AlrmSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib == AppSwcBcm_IN_SetOff_b) {
    AppSwcBcm_ARID_DEF.Lib_blIn_im =
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S772>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_im,
      &AppSwcBcm_ARID_DEF.LogicalOperator_bn,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_f);

    /* End of Outputs for SubSystem: '<S772>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_bn && (!rtb_LogicalOperator8_h)) {
      AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
      LampCtl_AlrmSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 2) ||
             rtb_LogicalOperator8_h) {
    AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_AlrmSta = false;
  }

  /* End of Chart: '<S752>/Chart' */

  /* RelationalOperator: '<S760>/Relational Operator6' */
  RelationalOperator6 = LampCtl_AlrmSta;

  /* Logic: '<S760>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S760>/Relational Operator'
   *  RelationalOperator: '<S760>/Relational Operator4'
   *  RelationalOperator: '<S760>/Relational Operator6'
   */
  rtb_LogicalOperator1_l5 = (RelationalOperator8_l || LampCtl_AlrmSta ||
    LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* RelationalOperator: '<S771>/Relational Operator' incorporates:
   *  Constant: '<S771>/Constant'
   */
  rtb_RelationalOperator_bx = (LampCtl_RKEReq == 4);

  /* Chart: '<S771>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c123_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c123_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_h;
    LampCtl_VehSeekSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib) {
     case AppSwcBcm_IN_RKESetOn:
      if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i >= 10) ||
          (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 1) ||
          rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_h;
        LampCtl_VehSeekSta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_c = rtb_RelationalOperator_bx;

        /* Outputs for Function Call SubSystem: '<S860>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_c,
          &AppSwcBcm_ARID_DEF.LogicalOperator_g2,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gu);

        /* End of Outputs for SubSystem: '<S860>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_g2) {
          AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
            !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
          LampCtl_VehSeekSta = 0U;
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_RKESetOn;
        } else {
          LampCtl_VehSeekSta = 1U;
          Clear_RKECommd();
        }
      }
      break;

     case AppSwcBcm_IN_SetOff_h:
      if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1) {
        AppSwcBcm_ARID_DEF.Lib_blIn_c = rtb_RelationalOperator_bx;

        /* Outputs for Function Call SubSystem: '<S860>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_c,
          &AppSwcBcm_ARID_DEF.LogicalOperator_g2,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gu);

        /* End of Outputs for SubSystem: '<S860>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_g2 && (!rtb_LogicalOperator1_l5))
        {
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_RKESetOn;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     default:
      /* case IN_TboxSetOn: */
      if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i >= 10) ||
          (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 1) ||
          rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_h;
        LampCtl_VehSeekSta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_lf =
          (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 1) ||
           ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 2));

        /* Outputs for Function Call SubSystem: '<S860>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_lf,
          &AppSwcBcm_ARID_DEF.LogicalOperator_b,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_d);

        /* End of Outputs for SubSystem: '<S860>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_b) {
          AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
            !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_TboxSetOn;
          LampCtl_VehSeekSta = 2U;
        }
      }
      break;
    }

    if (guard1) {
      if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1) {
        AppSwcBcm_ARID_DEF.Lib_blIn_lf =
          (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 1) ||
           ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 2));

        /* Outputs for Function Call SubSystem: '<S860>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_lf,
          &AppSwcBcm_ARID_DEF.LogicalOperator_b,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_d);

        /* End of Outputs for SubSystem: '<S860>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_b && (!rtb_LogicalOperator1_l5))
        {
          AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_TboxSetOn;
          LampCtl_VehSeekSta = 2U;
        }
      }
    }
  }

  /* End of Chart: '<S771>/Chart' */

  /* Chart: '<S753>/Chart' incorporates:
   *  UnitDelay: '<S654>/Unit Delay10'
   *  UnitDelay: '<S654>/Unit Delay11'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c38_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c38_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib == AppSwcBcm_IN_Off_i) {
    if ((AppSwcBcm_ARID_DEF.BusCreator4.MechAntiLck ||
         AppSwcBcm_ARID_DEF.BusCreator4.RKEAntiLck) && (!rtb_LogicalOperator1_l5))
    {
      AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_On_c;
      LampCtl_AntiLckSta = true;
    }

    /* case IN_On: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE >= 3) ||
             rtb_LogicalOperator1_l5 || (LampCtl_VehSeekSta == 1)) {
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.BusCreator4.MechAntiLck ||
             AppSwcBcm_ARID_DEF.BusCreator4.RKEAntiLck) {
    AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_On_c;
    LampCtl_AntiLckSta = true;
  }

  /* End of Chart: '<S753>/Chart' */

  /* Chart: '<S754>/Chart' */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1 < 31U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c40_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c40_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib == AppSwcBcm_IN_SetOff_b) {
    AppSwcBcm_ARID_DEF.Lib_blIn_be =
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S776>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_be,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fr,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_j);

    /* End of Outputs for SubSystem: '<S776>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_fr ||
         ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1))) &&
        (!rtb_LogicalOperator1_l5)) {
      AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
      AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
      LampCtl_ArmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.temporalCounter_i1 >= 20U) ||
             (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 1) ||
             (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_l5) {
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) {
    AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt = !AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
    AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
    LampCtl_ArmedSta = true;
  }

  /* End of Chart: '<S754>/Chart' */

  /* Chart: '<S756>/Chart' incorporates:
   *  UnitDelay: '<S654>/Unit Delay8'
   *  UnitDelay: '<S654>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c42_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c42_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib == AppSwcBcm_IN_SetOff_b) {
    AppSwcBcm_ARID_DEF.Lib_blIn_j4 =
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 0);

    /* Outputs for Function Call SubSystem: '<S790>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_j4,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lf,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_b);

    /* End of Outputs for SubSystem: '<S790>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_lf ||
         ((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 0) &&
          (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1))) &&
        (!rtb_LogicalOperator1_l5)) {
      AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
      LampCtl_DisarmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 0) ||
             (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_l5) {
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
    AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
    LampCtl_DisarmedSta = true;
  }

  /* End of Chart: '<S756>/Chart' */

  /* Chart: '<S759>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c5_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c5_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_PartArmedSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib) {
     case AppSwcBcm_IN_SetOff_b:
      LampCtl_PartArmedSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_In_f = AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts;
      AppSwcBcm_ARID_DEF.Lib_InNow_c = 3.0F;
      AppSwcBcm_ARID_DEF.Lib_InBefore_o = 1.0F;

      /* Outputs for Function Call SubSystem: '<S805>/Lib_ChangeEdge2' */
      AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_f,
        AppSwcBcm_ARID_DEF.Lib_InNow_c, AppSwcBcm_ARID_DEF.Lib_InBefore_o,
        &AppSwcBcm_ARID_DEF.LogicalOperator_gv,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

      /* End of Outputs for SubSystem: '<S805>/Lib_ChangeEdge2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_gv) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn2;
        LampCtl_PartArmedSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_In = AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts;
        AppSwcBcm_ARID_DEF.Lib_InNow = 3.0F;
        AppSwcBcm_ARID_DEF.Lib_InBefore = 0.0F;

        /* Outputs for Function Call SubSystem: '<S805>/Lib_ChangeEdge' */
        AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In,
          AppSwcBcm_ARID_DEF.Lib_InNow, AppSwcBcm_ARID_DEF.Lib_InBefore,
          &AppSwcBcm_ARID_DEF.LogicalOperator_li,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

        /* End of Outputs for SubSystem: '<S805>/Lib_ChangeEdge' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_li) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_In_c =
            AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts;
          AppSwcBcm_ARID_DEF.Lib_InNow_i = 3.0F;
          AppSwcBcm_ARID_DEF.Lib_InBefore_d = 2.0F;

          /* Outputs for Function Call SubSystem: '<S805>/Lib_ChangeEdge1' */
          AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_c,
            AppSwcBcm_ARID_DEF.Lib_InNow_i, AppSwcBcm_ARID_DEF.Lib_InBefore_d,
            &AppSwcBcm_ARID_DEF.LogicalOperator_n,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

          /* End of Outputs for SubSystem: '<S805>/Lib_ChangeEdge1' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_n ||
              ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
               (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 3))) {
            guard1 = true;
          }
        }
      }
      break;

     case AppSwcBcm_IN_SetOn1:
      LampCtl_PartArmedSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
        LampCtl_PartArmedSta = 0U;
      } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) {
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
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
        LampCtl_PartArmedSta = 0U;
      } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;
    }

    if (guard1) {
      if (!rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c5_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
    }
  }

  /* End of Chart: '<S759>/Chart' */

  /* RelationalOperator: '<S761>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S760>/Relational Operator12'
   */
  rtb_LogicalOperator6_mt = !LampCtl_ArmedSta;

  /* RelationalOperator: '<S761>/Relational Operator2' incorporates:
   *  RelationalOperator: '<S760>/Relational Operator15'
   */
  rtb_RelationalOperator3_h = !LampCtl_DisarmedSta;

  /* RelationalOperator: '<S761>/Relational Operator7' incorporates:
   *  RelationalOperator: '<S760>/Relational Operator17'
   */
  rtb_LogicalOperator4_kr = !LampCtl_AntiLckSta;

  /* Chart: '<S761>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S761>/Constant'
   *  Constant: '<S761>/Constant2'
   *  Constant: '<S761>/Constant21'
   *  Constant: '<S761>/Constant3'
   *  Constant: '<S761>/Constant5'
   *  Constant: '<S761>/Constant7'
   *  Logic: '<S761>/Logical Operator'
   *  Logic: '<S761>/Logical Operator1'
   *  Logic: '<S761>/Logical Operator2'
   *  RelationalOperator: '<S761>/Relational Operator'
   *  RelationalOperator: '<S761>/Relational Operator1'
   *  RelationalOperator: '<S761>/Relational Operator2'
   *  RelationalOperator: '<S761>/Relational Operator3'
   *  RelationalOperator: '<S761>/Relational Operator4'
   *  RelationalOperator: '<S761>/Relational Operator5'
   *  RelationalOperator: '<S761>/Relational Operator6'
   *  RelationalOperator: '<S761>/Relational Operator7'
   */
  if (rtb_LogicalOperator4_kr && rtb_RelationalOperator3_h &&
      (LampCtl_PartArmedSta == 0) && rtb_LogicalOperator6_mt &&
      (LampCtl_VehSeekSta == 0) &&
      ((!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwStVld_flg)
       ||
       (!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwStVld_flg))
      && (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_n >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_RodBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_n++;
      AppSwcBcm_ARID_DEF.cnt_heal_e = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_n = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e == 0) {
      LampCtl_RodBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_e--;
    }
  }

  /* End of Chart: '<S761>/LIB_TPD_10ms' */

  /* Chart: '<S770>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c119_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c119_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
    LampCtl_VehModeSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib) {
     case AppSwcBcm_IN_Init_f:
      LampCtl_VehModeSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_h =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
         ->VIPC_VehHiddenMode_enum == 1);

      /* Outputs for Function Call SubSystem: '<S853>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_h,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ka,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_l);

      /* End of Outputs for SubSystem: '<S853>/Lib_RiseEdgeDetInit' */
      rtb_RelationalOperator_bx = !rtb_LogicalOperator1_l5;
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ka && rtb_RelationalOperator_bx) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Show;
        LampCtl_VehModeSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_o1 =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
           ->VIPC_VehHiddenMode_enum == 2);

        /* Outputs for Function Call SubSystem: '<S853>/Lib_RiseEdgeDetInit1' */
        AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_o1,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jh,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

        /* End of Outputs for SubSystem: '<S853>/Lib_RiseEdgeDetInit1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_jh && rtb_RelationalOperator_bx)
        {
          AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Limit;
          LampCtl_VehModeSta = 3U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_d =
            ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
             ->VIPC_VehHiddenMode_enum == 0);

          /* Outputs for Function Call SubSystem: '<S853>/Lib_RiseEdgeDetInit2' */
          AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_d,
            &AppSwcBcm_ARID_DEF.LogicalOperator_k,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);

          /* End of Outputs for SubSystem: '<S853>/Lib_RiseEdgeDetInit2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_k && rtb_RelationalOperator_bx)
          {
            AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Nrm_p;
            LampCtl_VehModeSta = 1U;
          }
        }
      }
      break;

     case AppSwcBcm_IN_Limit:
      LampCtl_VehModeSta = 3U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 3) ||
          rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
        LampCtl_VehModeSta = 0U;
      }
      break;

     case AppSwcBcm_IN_Nrm_p:
      LampCtl_VehModeSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 1) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 1) ||
          rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
        LampCtl_VehModeSta = 0U;
      }
      break;

     default:
      /* case IN_Show: */
      LampCtl_VehModeSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 2) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 2) ||
          rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
        LampCtl_VehModeSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S770>/Chart' */

  /* Chart: '<S763>/Chart' incorporates:
   *  UnitDelay: '<S654>/Unit Delay14'
   *  UnitDelay: '<S654>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c47_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c47_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_h;
    LampCtl_TrunkWarnSta = false;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib) {
     case AppSwcBcm_IN_Delay:
      if ((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_l5 ||
          (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw)) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_h;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      } else if ((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 3) &&
                 (AppSwcBcm_ARID_DEF.TrunkWarnCnt >= LampCtl_TrunkWarnTim_C)) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOn_o0;
        LampCtl_TrunkWarnSta = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff_h:
      AppSwcBcm_ARID_DEF.Lib_blIn_g = AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S818>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_g,
        &AppSwcBcm_ARID_DEF.LogicalOperator_k2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_o);

      /* End of Outputs for SubSystem: '<S818>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_k2 && (!rtb_LogicalOperator1_l5) &&
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 3)) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_Delay;
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
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts != 3) ||
          (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_h;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S763>/Chart' */

  /* RelationalOperator: '<S760>/Relational Operator10' */
  rtb_RelationalOperator_bx = LampCtl_ArmedSta;

  /* RelationalOperator: '<S760>/Relational Operator11' incorporates:
   *  Constant: '<S760>/Constant12'
   */
  rtb_RelationalOperator11_e = (LampCtl_VehSeekSta != 0);

  /* RelationalOperator: '<S760>/Relational Operator14' */
  rtb_RelationalOperator14_j = LampCtl_DisarmedSta;

  /* Logic: '<S760>/Logical Operator10' incorporates:
   *  Constant: '<S760>/Constant16'
   *  Constant: '<S760>/Constant26'
   *  RelationalOperator: '<S760>/Relational Operator16'
   *  RelationalOperator: '<S760>/Relational Operator25'
   */
  rtb_LogicalOperator10_fp = ((LampCtl_PartArmedSta == 2) ||
    (LampCtl_PartArmedSta == 1));

  /* RelationalOperator: '<S760>/Relational Operator1' */
  rtb_RelationalOperator1_ad = LampCtl_RodBeamFaultSta;

  /* RelationalOperator: '<S760>/Relational Operator19' */
  rtb_RelationalOperator19 = LampCtl_AntiLckSta;

  /* Logic: '<S760>/Logical Operator9' incorporates:
   *  Constant: '<S760>/Constant20'
   *  Constant: '<S760>/Constant21'
   *  Constant: '<S760>/Constant23'
   *  RelationalOperator: '<S760>/Relational Operator20'
   *  RelationalOperator: '<S760>/Relational Operator22'
   *  RelationalOperator: '<S760>/Relational Operator3'
   */
  rtb_LogicalOperator9 = ((LampCtl_VehModeSta == 1) || (LampCtl_VehModeSta == 2)
    || (LampCtl_VehModeSta == 3));

  /* RelationalOperator: '<S760>/Relational Operator23' */
  rtb_RelationalOperator23 = LampCtl_TrunkWarnSta;

  /* RelationalOperator: '<S760>/Relational Operator5' */
  rtb_RelationalOperator5_by = !LampCtl_EmerSta;

  /* RelationalOperator: '<S760>/Relational Operator7' */
  rtb_RelationalOperator7_og = !LampCtl_AlrmSta;

  /* RelationalOperator: '<S760>/Relational Operator9' incorporates:
   *  Constant: '<S760>/Constant9'
   */
  rtb_RelationalOperator9_pm = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 0);

  /* Logic: '<S760>/Logical Operator6' incorporates:
   *  Constant: '<S760>/Constant13'
   *  Constant: '<S760>/Constant17'
   *  Constant: '<S760>/Constant22'
   *  RelationalOperator: '<S760>/Relational Operator13'
   *  RelationalOperator: '<S760>/Relational Operator18'
   *  RelationalOperator: '<S760>/Relational Operator2'
   *  RelationalOperator: '<S760>/Relational Operator21'
   *  RelationalOperator: '<S760>/Relational Operator24'
   */
  rtb_LogicalOperator6_mt = (rtb_LogicalOperator6_mt && (LampCtl_VehSeekSta == 0)
    && rtb_RelationalOperator3_h && (LampCtl_PartArmedSta == 0) &&
    (!LampCtl_RodBeamFaultSta) && rtb_LogicalOperator4_kr && (LampCtl_VehModeSta
    == 0) && (!LampCtl_TrunkWarnSta));

  /* RelationalOperator: '<S765>/Relational Operator' incorporates:
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S765>/Relational Operator5'
   */
  rtb_RelationalOperator_d_tmp =
    Rte_IRead_Runbl_AppSwcBcm_50ms_FCLL_TiWngSt_FCLL_TiWngSt();

  /* Logic: '<S765>/Logical Operator4' incorporates:
   *  UnitDelay: '<S654>/Unit Delay16'
   */
  rtb_LogicalOperator4_kr = (LampCtl_TurnIndcrLaneLSw &&
    AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE);

  /* Outputs for Enabled SubSystem: '<S765>/Enabled Subsystem3' incorporates:
   *  EnablePort: '<S838>/Enable'
   */
  if (rtb_LogicalOperator4_kr) {
    /* CCaller: '<S838>/C Caller' incorporates:
     *  Constant: '<S838>/Constant17'
     */
    LampCtl_TurnIndcrLVol = GetHw_TurnIndcrVol(0U);
  }

  /* End of Outputs for SubSystem: '<S765>/Enabled Subsystem3' */

  /* RelationalOperator: '<S765>/Relational Operator3' */
  rtb_RelationalOperator3_h = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0);

  /* Chart: '<S765>/TurnIndcrDig3' incorporates:
   *  Constant: '<S765>/Constant17'
   *  Constant: '<S765>/Constant21'
   *  Constant: '<S765>/Constant43'
   *  Constant: '<S765>/Constant44'
   *  Constant: '<S765>/Constant45'
   *  RelationalOperator: '<S765>/Relational Operator1'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_kr, LampCtl_TurnIndcrLVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_h, LampCtl_Ts_C,
    LampCtl_TurnIndcrLOpenTimValid_C, LampCtl_TurnIndcrLOpenTimInValid_C,
    LampCtl_LOpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig3);

  /* Logic: '<S765>/Logical Operator' incorporates:
   *  Constant: '<S765>/Constant'
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S765>/Relational Operator'
   */
  LampCtl_TurnIndcrLOpen = ((rtb_RelationalOperator_d_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* Chart: '<S765>/TurnIndcrDig2' incorporates:
   *  Constant: '<S765>/Constant10'
   *  Constant: '<S765>/Constant18'
   *  Constant: '<S765>/Constant19'
   *  Constant: '<S765>/Constant4'
   *  Constant: '<S765>/Constant9'
   *  RelationalOperator: '<S765>/Relational Operator4'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_kr, LampCtl_TurnIndcrLVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_h, LampCtl_Ts_C,
    LampCtl_TurnIndcrLShortTimValid_C, LampCtl_TurnIndcrLShortTimInValid_C,
    LampCtl_LShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig2);

  /* Logic: '<S765>/Logical Operator2' incorporates:
   *  Constant: '<S765>/Constant7'
   *  RelationalOperator: '<S765>/Relational Operator5'
   */
  LampCtl_TurnIndcrLShort = ((rtb_RelationalOperator_d_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_m);

  /* RelationalOperator: '<S765>/Relational Operator2' incorporates:
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S765>/Relational Operator6'
   */
  rtb_RelationalOperator_d_tmp =
    Rte_IRead_Runbl_AppSwcBcm_50ms_FCLR_TiWngSt_FCLR_TiWngSt();

  /* Logic: '<S765>/Logical Operator5' incorporates:
   *  UnitDelay: '<S654>/Unit Delay17'
   */
  rtb_LogicalOperator4_kr = (LampCtl_TurnIndcrLaneRSw &&
    AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE);

  /* Outputs for Enabled SubSystem: '<S765>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S837>/Enable'
   */
  if (rtb_LogicalOperator4_kr) {
    /* CCaller: '<S837>/C Caller' incorporates:
     *  Constant: '<S837>/Constant17'
     */
    LampCtl_TurnIndcrRVol = GetHw_TurnIndcrVol(1U);
  }

  /* End of Outputs for SubSystem: '<S765>/Enabled Subsystem1' */

  /* Chart: '<S765>/TurnIndcrDig' incorporates:
   *  Constant: '<S765>/Constant11'
   *  Constant: '<S765>/Constant2'
   *  Constant: '<S765>/Constant3'
   *  Constant: '<S765>/Constant6'
   *  Constant: '<S765>/Constant8'
   *  RelationalOperator: '<S765>/Relational Operator7'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_kr, LampCtl_TurnIndcrRVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_h, LampCtl_Ts_C,
    LampCtl_TurnIndcrROpenTimValid_C, LampCtl_TurnIndcrROpenTimInValid_C,
    LampCtl_ROpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig);

  /* Logic: '<S765>/Logical Operator1' incorporates:
   *  Constant: '<S765>/Constant5'
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S765>/Relational Operator2'
   */
  LampCtl_TurnIndcrROpen = ((rtb_RelationalOperator_d_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_f);

  /* Chart: '<S765>/TurnIndcrDig1' incorporates:
   *  Constant: '<S765>/Constant12'
   *  Constant: '<S765>/Constant13'
   *  Constant: '<S765>/Constant14'
   *  Constant: '<S765>/Constant16'
   *  Constant: '<S765>/Constant20'
   *  RelationalOperator: '<S765>/Relational Operator8'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_kr, LampCtl_TurnIndcrRVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_h, LampCtl_Ts_C,
    LampCtl_TurnIndcrRShortTimValid_C, LampCtl_TurnIndcrRShortTimInValid_C,
    LampCtl_RShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig1);

  /* Logic: '<S765>/Logical Operator3' incorporates:
   *  Constant: '<S765>/Constant15'
   *  RelationalOperator: '<S765>/Relational Operator6'
   */
  LampCtl_TurnIndcrRShort = ((rtb_RelationalOperator_d_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_o);

  /* Chart: '<S654>/TurnIndcrArb2' incorporates:
   *  Logic: '<S760>/Logical Operator'
   *  Logic: '<S760>/Logical Operator2'
   *  Logic: '<S760>/Logical Operator3'
   *  Logic: '<S760>/Logical Operator4'
   *  Logic: '<S760>/Logical Operator5'
   *  Logic: '<S760>/Logical Operator7'
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
      if (rtb_RelationalOperator5_by || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri2Func();
      }
      break;

     case AppSwcBcm_IN_Pri3:
      if (rtb_RelationalOperator7_og || rtb_LogicalOperator8_h) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri4:
      if (rtb_RelationalOperator9_pm || RelationalOperator6 ||
          rtb_RelationalOperator6_n || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri4Func();
      }
      break;

     case AppSwcBcm_IN_Pri5:
      if (rtb_LogicalOperator6_mt || rtb_LogicalOperator1_l5) {
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_NO_ACTIVE_CHILD_c;
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        switch (AppSwcBcm_ARID_DEF.is_Pri5) {
         case AppSwcBcm_IN_AntiLck:
          if (!LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_AntiLckFunc();
          }
          break;

         case AppSwcBcm_IN_Armed_p:
          if (!LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_ArmedFunc();
          }
          break;

         case AppSwcBcm_IN_Disarmed_n:
          if (!LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_DisarmedFunc();
          }
          break;

         case AppSwcBcm_IN_PartArmed_g:
          if (LampCtl_PartArmedSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_PartArmedFunc();
          }
          break;

         case AppSwcBcm_IN_RodBeam:
          if (!LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_RodBeamFunc();
          }
          break;

         case AppSwcBcm_IN_Seek:
          if (LampCtl_VehSeekSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_SeekFunc();
          }
          break;

         case AppSwcBcm_IN_Trans_i:
          if (LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Armed_p;
          } else if (LampCtl_PartArmedSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_PartArmed_g;
          } else if (LampCtl_VehSeekSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Seek;
          } else if (LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Disarmed_n;
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
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_TrunkWarnFunc();
          }
          break;

         default:
          /* case IN_VehMode: */
          if (LampCtl_VehModeSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
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
      } else if (rtb_RelationalOperator6_n) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri2;
      } else if (RelationalOperator6) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri3;
      } else if (RelationalOperator8_l) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri4;
      } else if (rtb_RelationalOperator_bx || rtb_RelationalOperator11_e ||
                 rtb_RelationalOperator14_j || rtb_LogicalOperator10_fp ||
                 rtb_RelationalOperator1_ad || rtb_RelationalOperator19 ||
                 rtb_LogicalOperator9 || rtb_RelationalOperator23) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri5;
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_i;
        AppSwcBcm_TurnFunc();
      }
      break;
    }
  }

  /* End of Chart: '<S654>/TurnIndcrArb2' */
  AppSwcBcm_ARID_DEF.Lib_blIn_l3 = LampCtl_TurnIndcrRst;

  /* Chart: '<S768>/LIB_Pulse' incorporates:
   *  SubSystem: '<S850>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_l3,
    &AppSwcBcm_ARID_DEF.RelationalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_p) {
    AppSwcBcm_ARID_DEF.cnt = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  if (LampCtl_TurnIndcrRFlashCnt >= 1) {
    if (LampCtl_TurnIndcrRFlashCnt >= 65535) {
      LampCtl_PrdSucCntR = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_e = (AppSwcBcm_ARID_DEF.cnt <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt + 1;
        if (AppSwcBcm_ARID_DEF.cnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntR < LampCtl_TurnIndcrRFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_e = (AppSwcBcm_ARID_DEF.cnt <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt = 0U;
        tmp = LampCtl_PrdSucCntR + 1;
        if (LampCtl_PrdSucCntR + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntR = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt + 1;
        if (AppSwcBcm_ARID_DEF.cnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_e = false;
    AppSwcBcm_ARID_DEF.cnt = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  /* Logic: '<S654>/Logical Operator' incorporates:
   *  UnitDelay: '<S654>/Unit Delay17'
   */
  AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE = (AppSwcBcm_ARID_DEF.LIB_blOut_e &&
    rtb_RelationalOperator5);
  AppSwcBcm_ARID_DEF.Lib_blIn_k = LampCtl_TurnIndcrRst;

  /* Chart: '<S766>/LIB_Pulse' incorporates:
   *  SubSystem: '<S843>/Lib_BothEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S844>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_k,
    &AppSwcBcm_ARID_DEF.LogicalOperator2_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet_l);

  /* End of Outputs for SubSystem: '<S844>/Lib_BothEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator2_b) {
    AppSwcBcm_ARID_DEF.cnt_h = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  if (LampCtl_TurnIndcrLFlashCnt >= 1) {
    if (LampCtl_TurnIndcrLFlashCnt >= 65535) {
      LampCtl_PrdSucCntL = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_n = (AppSwcBcm_ARID_DEF.cnt_h <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_h >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_h = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_h + 1;
        if (AppSwcBcm_ARID_DEF.cnt_h + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_h = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntL < LampCtl_TurnIndcrLFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_n = (AppSwcBcm_ARID_DEF.cnt_h <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_h >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_h = 0U;
        tmp = LampCtl_PrdSucCntL + 1;
        if (LampCtl_PrdSucCntL + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntL = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_h + 1;
        if (AppSwcBcm_ARID_DEF.cnt_h + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_h = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_n = false;
    AppSwcBcm_ARID_DEF.cnt_h = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  /* Logic: '<S654>/Logical Operator1' incorporates:
   *  UnitDelay: '<S654>/Unit Delay16'
   */
  AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE = (rtb_RelationalOperator5 &&
    AppSwcBcm_ARID_DEF.LIB_blOut_n);

  /* Chart: '<S771>/SeekFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Init_j;
    LampCtl_VehSeekStaFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_io = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib) {
     case AppSwcBcm_IN_Fail_k:
      LampCtl_VehSeekStaFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_io >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Init_j;
        LampCtl_VehSeekStaFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_io = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_io + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_io + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_io = (uint8)tmp;
      }
      break;

     case AppSwcBcm_IN_Init_j:
      LampCtl_VehSeekStaFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_n =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtCarSearch_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtCarSearch_enum == 2));

      /* Outputs for Function Call SubSystem: '<S861>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_n,
        &AppSwcBcm_ARID_DEF.LogicalOperator_c,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_j);

      /* End of Outputs for SubSystem: '<S861>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_c) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Wait_kv;
      }
      break;

     case AppSwcBcm_IN_Suc_l:
      LampCtl_VehSeekStaFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_io >= 5) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Init_j;
        LampCtl_VehSeekStaFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_io = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_io + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_io + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_io = (uint8)tmp;
      }
      break;

     default:
      /* case IN_Wait: */
      if (LampCtl_VehSeekSta == 2) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Suc_l;
        LampCtl_VehSeekStaFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_io + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_io + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_io = (uint8)tmp;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_TBoxRmtCarSearch_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c85_LampCtl_Lib = AppSwcBcm_IN_Fail_k;
        LampCtl_VehSeekStaFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_io + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_io + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_io = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S771>/SeekFb' */

  /* Chart: '<S755>/Chart1' incorporates:
   *  Inport: '<Root>/IPM_SRS_1_Status_CHA'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c43_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c43_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_Init_d;
    AppSwcBcm_ARID_DEF.PwrOnFlg = false;
    AppSwcBcm_ARID_DEF.DelayCnt = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib) {
     case AppSwcBcm_IN_CrashOff:
      if (AppSwcBcm_ARID_DEF.PwrOnFlg ||
          (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0)) {
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_Init_d;
        AppSwcBcm_ARID_DEF.PwrOnFlg = false;
        AppSwcBcm_ARID_DEF.DelayCnt = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ea =
          (((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 1) ||
           ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 2) ||
           ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 4) ||
           ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 5));

        /* Outputs for Function Call SubSystem: '<S779>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ea,
          &AppSwcBcm_ARID_DEF.LogicalOperator_dc,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_b);

        /* End of Outputs for SubSystem: '<S779>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_dc) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_bn = (BSW_CrashPWMSta == 1);

          /* Outputs for Function Call SubSystem: '<S779>/Lib_RiseEdgeDet2' */
          AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_bn,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ab,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_e);

          /* End of Outputs for SubSystem: '<S779>/Lib_RiseEdgeDet2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ab) {
            guard1 = true;
          }
        }
      }
      break;

     case AppSwcBcm_IN_CrashOn:
      if (AppSwcBcm_ARID_DEF.PwrOffFlg && AppSwcBcm_ARID_DEF.PwrOnFlg) {
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
        LampCtl_CrashSta = false;
        AppSwcBcm_ARID_DEF.PwrOffFlg = false;
        AppSwcBcm_ARID_DEF.ClearCnt = 0U;
      } else {
        AppSwcBcm_CrashClearFunc();
        AppSwcBcm_ARID_DEF.Lib_blIn_hy =
          (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.CrashSta == 1);

        /* Outputs for Function Call SubSystem: '<S779>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_hy,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ki,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_da);

        /* End of Outputs for SubSystem: '<S779>/Lib_RiseEdgeDet1' */
      }
      break;

     default:
      /* case IN_Init: */
      AppSwcBcm_ARID_DEF.Lib_blIn_hy =
        (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.CrashSta == 1);

      /* Outputs for Function Call SubSystem: '<S779>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_hy,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ki,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_da);

      /* End of Outputs for SubSystem: '<S779>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ki) {
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
        LampCtl_CrashSta = true;
      } else if (AppSwcBcm_ARID_DEF.DelayCnt >= 80) {
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
        LampCtl_CrashSta = false;
        AppSwcBcm_ARID_DEF.PwrOffFlg = false;
        AppSwcBcm_ARID_DEF.ClearCnt = 0U;
      } else {
        AppSwcBcm_PwrOnDelayFunc();
      }
      break;
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
      LampCtl_CrashSta = true;
    }
  }

  /* End of Chart: '<S755>/Chart1' */

  /* Chart: '<S762>/Chart' incorporates:
   *  Inport: '<Root>/IPM_BMS_1_MainState_EPT'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c46_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c46_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
    LampCtl_ThermalrunawaySta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib == AppSwcBcm_IN_SetOff_b) {
    AppSwcBcm_ARID_DEF.Lib_blIn_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
        ())->VIPM_BMSThermrunawayWrn_enum == 1);

    /* Outputs for Function Call SubSystem: '<S813>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_b,
      &AppSwcBcm_ARID_DEF.LogicalOperator_l,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nu);

    /* End of Outputs for SubSystem: '<S813>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_l) {
      AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
    }
  } else {
    /* case IN_SetOn: */
    guard1 = false;
    if ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
         ())->VIPM_BMSThermrunawayWrn_enum == 0) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_ha = LampCtl_HazardLightSw;

      /* Outputs for Function Call SubSystem: '<S813>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ha,
        &AppSwcBcm_ARID_DEF.LogicalOperator_kn,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_b);

      /* End of Outputs for SubSystem: '<S813>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_kn) {
        guard1 = true;
      } else {
        LampCtl_ThermalrunawaySta = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOff_b;
      LampCtl_ThermalrunawaySta = false;
    }
  }

  /* End of Chart: '<S762>/Chart' */

  /* Update for UnitDelay: '<S654>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S654>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_li = LampCtl_CrashSta;

  /* Update for UnitDelay: '<S654>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_f = LampCtl_ThermalrunawaySta;

  /* Update for UnitDelay: '<S654>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S654>/Unit Delay11' */
  AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay10' */
  AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S654>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S654>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S654>/Unit Delay13' */
  AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay12' */
  AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S654>/Unit Delay15' */
  AppSwcBcm_ARID_DEF.UnitDelay15_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S654>/Unit Delay14' */
  AppSwcBcm_ARID_DEF.UnitDelay14_DSTATE = LampCtl_PrdSucCntR;
}

/* Output and update for atomic system: '<S869>/Lib_RiseEdgeDet' */
static void AppSwcBcm_Lib_RiseEdgeDet_p(void)
{
  /* Logic: '<S878>/Logical Operator' incorporates:
   *  Logic: '<S878>/Logical Operator1'
   *  UnitDelay: '<S878>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_i = (AppSwcBcm_ARID_DEF.LIB_blOut_i &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kl));

  /* Update for UnitDelay: '<S878>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kl = AppSwcBcm_ARID_DEF.LIB_blOut_i;
}

/* Output and update for atomic system: '<S873>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge_h(void)
{
  /* Logic: '<S941>/Logical Operator10' incorporates:
   *  Constant: '<S873>/Constant3'
   *  Constant: '<S873>/Constant4'
   *  Logic: '<S882>/Logical Operator'
   *  RelationalOperator: '<S882>/Relational Operator'
   *  RelationalOperator: '<S882>/Relational Operator1'
   *  UnitDelay: '<S882>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 =
    ((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1) &&
     (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 0));

  /* Update for UnitDelay: '<S882>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l =
    AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts;
}

/* System initialize for atomic system: '<S411>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_b;

  /* InitializeConditions for UnitDelay: '<S655>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = 60U;

  /* InitializeConditions for Delay: '<S870>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_l = true;

  /* SystemInitialize for Chart: '<S869>/LIB_PosPluseInit' incorporates:
   *  SubSystem: '<S877>/Lib_RiseEdgeDet'
   */

  /* SystemInitialize for Atomic SubSystem: '<S879>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_i_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S879>/Lib_RiseEdgeDetInit' */

  /* SystemInitialize for Chart: '<S873>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_b);

  /* SystemInitialize for Chart: '<S874>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut);
}

/* Output and update for atomic system: '<S411>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_b;
  sint32 tmp;
  uint8 rtb_Switch;
  boolean rtb_LIB_blOut_p;
  boolean rtb_LogicalOperator;

  /* Chart: '<S868>/LIB_Tim' incorporates:
   *  Constant: '<S868>/Constant5'
   *  Logic: '<S868>/Logical Operator1'
   *  Logic: '<S868>/Logical Operator2'
   *  Product: '<S868>/Product'
   *  RelationalOperator: '<S868>/Relational Operator3'
   *  UnitDelay: '<S655>/Unit Delay1'
   *  UnitDelay: '<S655>/Unit Delay2'
   */
  if ((!AppSwcBcm_ARID_DEF.BusCreator4.OsLck) &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f) {
    if (AppSwcBcm_ARID_DEF.Cnt_f <= (uint16)(20U *
         AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE)) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_f + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_f + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_f = (uint16)tmp;
      rtb_LIB_blOut_p = false;
    } else {
      rtb_LIB_blOut_p = true;
    }
  } else {
    rtb_LIB_blOut_p = false;
    AppSwcBcm_ARID_DEF.Cnt_f = 0U;
  }

  /* End of Chart: '<S868>/LIB_Tim' */

  /* Outputs for Atomic SubSystem: '<S868>/Lib_RiseEdgeDet3' */
  /* RelationalOperator: '<S868>/Relational Operator1' incorporates:
   *  Constant: '<S868>/Constant1'
   */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(LampCtl_VehSeekSta == 1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3);

  /* End of Outputs for SubSystem: '<S868>/Lib_RiseEdgeDet3' */

  /* Switch: '<S870>/Switch' incorporates:
   *  Constant: '<S870>/Constant5'
   *  RelationalOperator: '<S870>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) {
    /* Switch: '<S870>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUFlwrMeHmCtrl_enum;
  } else {
    /* Switch: '<S870>/Switch' incorporates:
     *  Constant: '<S870>/Constant11'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S870>/Switch' */

  /* Delay: '<S870>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_l) {
    /* Switch: '<S870>/Switch1' incorporates:
     *  Constant: '<S870>/Constant12'
     *  Constant: '<S870>/Constant13'
     *  RelationalOperator: '<S870>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.FlwrMeHomeCtlFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.FlwrMeHomeCtlFb;
    }

    /* End of Switch: '<S870>/Switch1' */
  }

  /* MultiPortSwitch: '<S870>/Multiport Switch1' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S870>/Multiport Switch1' incorporates:
     *  Constant: '<S870>/Constant6'
     */
    LampCtl_FlwrMeHomeCtlFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S870>/Multiport Switch1' incorporates:
     *  Constant: '<S870>/Constant7'
     */
    LampCtl_FlwrMeHomeCtlFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S870>/Multiport Switch1' incorporates:
     *  Constant: '<S870>/Constant8'
     */
    LampCtl_FlwrMeHomeCtlFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S870>/Multiport Switch1' incorporates:
     *  Constant: '<S870>/Constant9'
     */
    LampCtl_FlwrMeHomeCtlFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S870>/Multiport Switch1' incorporates:
     *  Constant: '<S870>/Constant10'
     */
    LampCtl_FlwrMeHomeCtlFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S870>/Multiport Switch1' incorporates:
     *  Delay: '<S870>/Delay'
     */
    LampCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.Delay_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S870>/Multiport Switch1' */

  /* Logic: '<S869>/Logical Operator2' incorporates:
   *  Constant: '<S869>/Constant1'
   *  Constant: '<S869>/Constant3'
   *  Constant: '<S869>/Constant4'
   *  RelationalOperator: '<S869>/Relational Operator1'
   *  RelationalOperator: '<S869>/Relational Operator3'
   *  RelationalOperator: '<S869>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_fa = ((LampCtl_FlwrMeHomeCtlFb != 0) &&
    (LampCtl_LightIntstSta == 2) &&
    (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1));
  AppSwcBcm_ARID_DEF.Lib_blInit = AppSwcBcm_ARID_DEF.Lib_blIn_fa;

  /* Chart: '<S869>/LIB_PosPluseInit' incorporates:
   *  SubSystem: '<S877>/Lib_RiseEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S879>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_fa,
    AppSwcBcm_ARID_DEF.Lib_blInit, &AppSwcBcm_ARID_DEF.LogicalOperator_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S879>/Lib_RiseEdgeDetInit' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_j) {
    AppSwcBcm_ARID_DEF.Flg_m = true;
    AppSwcBcm_ARID_DEF.Cnt_co = 0U;
  }

  /* Logic: '<S869>/Logical Operator' */
  if (!AppSwcBcm_ARID_DEF.Lib_blIn_fa) {
    AppSwcBcm_ARID_DEF.Flg_m = false;
    AppSwcBcm_ARID_DEF.Cnt_co = 0U;
  }

  /* End of Logic: '<S869>/Logical Operator' */
  if (AppSwcBcm_ARID_DEF.Flg_m) {
    /* Constant: '<S869>/Constant43' */
    if (AppSwcBcm_ARID_DEF.Cnt_co >= LampCtl_FlwrMeHomeTimValid_C) {
      AppSwcBcm_ARID_DEF.LIB_blOut_i = true;
      AppSwcBcm_ARID_DEF.Flg_m = false;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_co++;
      AppSwcBcm_ARID_DEF.LIB_blOut_i = false;
    }

    /* End of Constant: '<S869>/Constant43' */
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_i = false;
    AppSwcBcm_ARID_DEF.Cnt_co = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S869>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_p();

  /* End of Outputs for SubSystem: '<S869>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S655>/Lib_SR1' */
  /* Switch: '<S872>/Switch' incorporates:
   *  Constant: '<S868>/Constant'
   *  Logic: '<S868>/Logical Operator'
   *  RelationalOperator: '<S868>/Relational Operator'
   *  RelationalOperator: '<S868>/Relational Operator2'
   */
  if (rtb_LIB_blOut_p || (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) ||
      AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck || rtb_LogicalOperator) {
    /* Switch: '<S872>/Switch' incorporates:
     *  Constant: '<S872>/Constant'
     */
    LampCtl_FlwrMeHomeSta = false;
  } else {
    /* Switch: '<S872>/Switch' incorporates:
     *  Logic: '<S872>/Logical Operator'
     *  UnitDelay: '<S872>/Unit Delay'
     */
    LampCtl_FlwrMeHomeSta = (AppSwcBcm_ARID_DEF.LogicalOperator_i ||
      LampCtl_FlwrMeHomeSta);
  }

  /* End of Switch: '<S872>/Switch' */
  /* End of Outputs for SubSystem: '<S655>/Lib_SR1' */

  /* MultiPortSwitch: '<S870>/Multiport Switch' */
  switch (LampCtl_FlwrMeHomeCtlFb) {
   case 0:
    /* MultiPortSwitch: '<S870>/Multiport Switch' incorporates:
     *  Constant: '<S870>/Constant4'
     */
    LampCtl_FlwrMeHomeTim = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S870>/Multiport Switch' incorporates:
     *  Constant: '<S870>/Constant'
     */
    LampCtl_FlwrMeHomeTim = 30U;
    break;

   case 2:
    /* MultiPortSwitch: '<S870>/Multiport Switch' incorporates:
     *  Constant: '<S870>/Constant1'
     */
    LampCtl_FlwrMeHomeTim = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S870>/Multiport Switch' incorporates:
     *  Constant: '<S870>/Constant2'
     */
    LampCtl_FlwrMeHomeTim = 90U;
    break;

   case 4:
    /* MultiPortSwitch: '<S870>/Multiport Switch' incorporates:
     *  Constant: '<S870>/Constant3'
     */
    LampCtl_FlwrMeHomeTim = 120U;
    break;
  }

  /* End of MultiPortSwitch: '<S870>/Multiport Switch' */

  /* Chart: '<S873>/LIB_Tim' incorporates:
   *  Constant: '<S873>/Constant6'
   *  Logic: '<S873>/Logical Operator1'
   *  Logic: '<S873>/Logical Operator2'
   *  RelationalOperator: '<S873>/Relational Operator2'
   *  UnitDelay: '<S655>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse((!AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p0, LampCtl_WelcomeLampTimMax_C,
    &rtb_LIB_blOut_b, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim);

  /* Outputs for Atomic SubSystem: '<S873>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge_h();

  /* End of Outputs for SubSystem: '<S873>/Lib_ChangeEdge' */

  /* Chart: '<S874>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S874>/Constant'
   *  Constant: '<S874>/Constant1'
   *  Constant: '<S874>/Constant3'
   *  Logic: '<S874>/Logical Operator1'
   *  RelationalOperator: '<S874>/Relational Operator'
   *  RelationalOperator: '<S874>/Relational Operator1'
   *  RelationalOperator: '<S874>/Relational Operator2'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts == 1)
    && AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck &&
    (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0), LampCtl_OsUnlckDelayTim_C,
    &AppSwcBcm_ARID_DEF.LIB_blOut,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay);

  /* Outputs for Atomic SubSystem: '<S655>/Lib_SR' */
  /* Switch: '<S871>/Switch' incorporates:
   *  Constant: '<S873>/Constant1'
   *  Logic: '<S873>/Logical Operator'
   *  RelationalOperator: '<S873>/Relational Operator1'
   */
  if (rtb_LIB_blOut_b || AppSwcBcm_ARID_DEF.LogicalOperator10 ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    /* Switch: '<S871>/Switch' incorporates:
     *  Constant: '<S871>/Constant'
     */
    LampCtl_WelcomeLampSta = false;
  } else {
    /* Switch: '<S871>/Switch' incorporates:
     *  Constant: '<S874>/Constant4'
     *  Logic: '<S871>/Logical Operator'
     *  Logic: '<S874>/Logical Operator2'
     *  RelationalOperator: '<S874>/Relational Operator4'
     *  UnitDelay: '<S871>/Unit Delay'
     */
    LampCtl_WelcomeLampSta = ((AppSwcBcm_ARID_DEF.LIB_blOut &&
      (LampCtl_LightIntstSta == 2)) || LampCtl_WelcomeLampSta);
  }

  /* End of Switch: '<S871>/Switch' */
  /* End of Outputs for SubSystem: '<S655>/Lib_SR' */

  /* Update for UnitDelay: '<S655>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f = LampCtl_FlwrMeHomeSta;

  /* Update for UnitDelay: '<S655>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = LampCtl_FlwrMeHomeTim;

  /* Update for Delay: '<S870>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_l = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE = LampCtl_FlwrMeHomeCtlFb;

  /* Update for UnitDelay: '<S655>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p0 = LampCtl_WelcomeLampSta;
}

/* System initialize for atomic system: '<S4>/LampCtl' */
static void AppSwcBcm_LampCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S411>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/ADASLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/AutoLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/BackLampCtl' */
  AppSwcBcm_BackLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/BackLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/BoxLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/DomeLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/LampDelayCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/LowBeamCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/PosLampCtl' */
  AppSwcBcm_PosLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/PosLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/SignalProcess' */
  AppSwcBcm_SignalProcess_b_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/SignalProcess' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/TurnIndcrCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S411>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S411>/WelcomeLampCtl' */
}

/* Outputs for atomic system: '<S4>/LampCtl' */
static void AppSwcBcm_LampCtl(void)
{
  boolean rtb_DataTypeConversion3_d0;

  /* Outputs for Atomic SubSystem: '<S411>/OTAPwrOffLight' */
  AppSwcBcm_OTAPwrOffLight();

  /* End of Outputs for SubSystem: '<S411>/OTAPwrOffLight' */

  /* Outputs for Atomic SubSystem: '<S411>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl();

  /* End of Outputs for SubSystem: '<S411>/ADASLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd3' */
  /* Switch: '<S643>/Switch1' incorporates:
   *  Constant: '<S411>/Constant5'
   */
  if (LampCtl_J420BSDRightCtlOvrdFlg_C) {
    /* Switch: '<S643>/Switch1' incorporates:
     *  Constant: '<S411>/Constant6'
     */
    LampCtl_J420BSDRightCtl = LampCtl_J420BSDRightCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion3' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->BSDRightCtlFlg != 0);

    /* Switch: '<S643>/Switch1' incorporates:
     *  Switch: '<S643>/Switch2'
     */
    LampCtl_J420BSDRightCtl = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl);
  }

  /* End of Switch: '<S643>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd4' */
  /* Switch: '<S644>/Switch1' incorporates:
   *  Constant: '<S411>/Constant7'
   */
  if (LampCtl_J422BSDLeftCtlOvrdFlg_C) {
    /* Switch: '<S644>/Switch1' incorporates:
     *  Constant: '<S411>/Constant8'
     */
    LampCtl_J422BSDLeftCtl = LampCtl_J422BSDLeftCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion4' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->BSDLeftCtlFlg != 0);

    /* Switch: '<S644>/Switch1' incorporates:
     *  Switch: '<S644>/Switch2'
     */
    LampCtl_J422BSDLeftCtl = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl);
  }

  /* End of Switch: '<S644>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd4' */

  /* Outputs for Atomic SubSystem: '<S411>/SignalProcess' */
  AppSwcBcm_SignalProcess_j();

  /* End of Outputs for SubSystem: '<S411>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd2' */
  /* Switch: '<S642>/Switch1' incorporates:
   *  Constant: '<S411>/Constant3'
   */
  if (LampCtl_BrakeLightStaOvrdFlg_C) {
    /* Switch: '<S642>/Switch1' incorporates:
     *  Constant: '<S411>/Constant4'
     */
    LampCtl_BrakeLightSta = LampCtl_BrakeLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->BrakeLightCtlFlg != 0);

    /* Switch: '<S642>/Switch2' */
    if (rtb_DataTypeConversion3_d0) {
      /* Switch: '<S642>/Switch1' incorporates:
       *  Switch: '<S642>/Switch2'
       */
      LampCtl_BrakeLightSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S411>/BrakeLampCtl' */
      AppSwcBcm_BrakeLampCtl();

      /* End of Outputs for SubSystem: '<S411>/BrakeLampCtl' */

      /* Switch: '<S642>/Switch1' incorporates:
       *  Switch: '<S642>/Switch2'
       */
      LampCtl_BrakeLightSta = AppSwcBcm_ARID_DEF.LogicalOperator6;
    }

    /* End of Switch: '<S642>/Switch2' */
  }

  /* End of Switch: '<S642>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S411>/LightIntstDet' */
  AppSwcBcm_LightIntstDet();

  /* End of Outputs for SubSystem: '<S411>/LightIntstDet' */

  /* Outputs for Atomic SubSystem: '<S411>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl();

  /* End of Outputs for SubSystem: '<S411>/AutoLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/KnobBeamDig' */
  AppSwcBcm_KnobBeamDig();

  /* End of Outputs for SubSystem: '<S411>/KnobBeamDig' */

  /* Outputs for Atomic SubSystem: '<S411>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl();

  /* End of Outputs for SubSystem: '<S411>/LampDelayCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/PosLampCtl' */
  AppSwcBcm_PosLampCtl();

  /* End of Outputs for SubSystem: '<S411>/PosLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd' */
  /* Switch: '<S635>/Switch1' incorporates:
   *  Constant: '<S411>/Constant18'
   *  Constant: '<S411>/Constant19'
   *  Switch: '<S635>/Switch2'
   */
  if (LampCtl_PosLampStaOvrdFlg_C) {
    LampCtl_PosLampSta = LampCtl_PosLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->PosLampCtlFlg != 0);
    LampCtl_PosLampSta = (rtb_DataTypeConversion3_d0 ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_iz);
  }

  /* End of Switch: '<S635>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd' */

  /* Outputs for Atomic SubSystem: '<S411>/PassLampFunc' */
  AppSwcBcm_PassLampFunc();

  /* End of Outputs for SubSystem: '<S411>/PassLampFunc' */

  /* Outputs for Atomic SubSystem: '<S411>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl();

  /* End of Outputs for SubSystem: '<S411>/LowBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd5' */
  /* Switch: '<S645>/Switch1' incorporates:
   *  Constant: '<S411>/Constant10'
   *  Constant: '<S411>/Constant9'
   *  Switch: '<S645>/Switch2'
   */
  if (LampCtl_LowBeamStaOvrdFlg_C) {
    LampCtl_LowBeamSta = LampCtl_LowBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->LowBeamCtlFlg != 0);
    LampCtl_LowBeamSta = (rtb_DataTypeConversion3_d0 ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_oa);
  }

  /* End of Switch: '<S645>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S411>/BackLampCtl' */
  AppSwcBcm_BackLampCtl();

  /* End of Outputs for SubSystem: '<S411>/BackLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd14' */
  /* Switch: '<S641>/Switch1' incorporates:
   *  Constant: '<S411>/Constant30'
   */
  if (LampCtl_J408BackLampPWMOvrdFlg_C) {
    /* Switch: '<S641>/Switch1' incorporates:
     *  Constant: '<S411>/Constant29'
     */
    LampCtl_J408BackLampPWM = LampCtl_J408BackLampPWMOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion14' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->BackLampCtlFlg != 0);

    /* Switch: '<S641>/Switch2' */
    if (rtb_DataTypeConversion3_d0) {
      /* Switch: '<S641>/Switch1' incorporates:
       *  Constant: '<S411>/Constant32'
       */
      LampCtl_J408BackLampPWM = 100U;
    } else {
      /* Switch: '<S641>/Switch1' */
      LampCtl_J408BackLampPWM = AppSwcBcm_ARID_DEF.Switch;
    }

    /* End of Switch: '<S641>/Switch2' */
  }

  /* End of Switch: '<S641>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd14' */

  /* Outputs for Atomic SubSystem: '<S411>/HiBeamCtl' */
  AppSwcBcm_HiBeamCtl();

  /* End of Outputs for SubSystem: '<S411>/HiBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd9' */
  /* Switch: '<S649>/Switch1' incorporates:
   *  Constant: '<S411>/Constant20'
   */
  if (LampCtl_HiBeamStaOvrdFlg_C) {
    /* Switch: '<S649>/Switch1' incorporates:
     *  Constant: '<S411>/Constant17'
     */
    LampCtl_HiBeamSta = LampCtl_HiBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion9' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->HiBeamCtlFlg != 0);

    /* Switch: '<S649>/Switch1' incorporates:
     *  Switch: '<S649>/Switch2'
     */
    LampCtl_HiBeamSta = (rtb_DataTypeConversion3_d0 ||
                         AppSwcBcm_ARID_DEF.LogicalOperator_kh);
  }

  /* End of Switch: '<S649>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd9' */

  /* Outputs for Atomic SubSystem: '<S411>/FogLampRCtl' */
  AppSwcBcm_FogLampRCtl();

  /* End of Outputs for SubSystem: '<S411>/FogLampRCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd6' */
  /* Switch: '<S646>/Switch1' incorporates:
   *  Constant: '<S411>/Constant12'
   */
  if (LampCtl_FogLampRStaOvrdFlg_C) {
    /* Switch: '<S646>/Switch1' incorporates:
     *  Constant: '<S411>/Constant11'
     */
    LampCtl_FogLampRSta = LampCtl_FogLampRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion6' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->FogLampRCtlFlg != 0);

    /* Switch: '<S646>/Switch1' incorporates:
     *  Switch: '<S646>/Switch2'
     */
    LampCtl_FogLampRSta = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.LogicalOperator_ok);
  }

  /* End of Switch: '<S646>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd6' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd7' */
  /* Switch: '<S647>/Switch1' incorporates:
   *  Constant: '<S411>/Constant14'
   */
  if (LampCtl_FogLampFStaOvrdFlg_C) {
    /* Switch: '<S647>/Switch1' incorporates:
     *  Constant: '<S411>/Constant13'
     */
    LampCtl_FogLampFSta = LampCtl_FogLampFStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion7' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->FogLampFCtlFlg != 0);

    /* Switch: '<S647>/Switch1' incorporates:
     *  Switch: '<S647>/Switch2'
     */
    LampCtl_FogLampFSta = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.LogicalOperator1_i);
  }

  /* End of Switch: '<S647>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd7' */

  /* Outputs for Atomic SubSystem: '<S411>/DayRunLampCtl' */
  AppSwcBcm_DayRunLampCtl();

  /* End of Outputs for SubSystem: '<S411>/DayRunLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd1' */
  /* Switch: '<S636>/Switch1' incorporates:
   *  Constant: '<S411>/Constant1'
   */
  if (LampCtl_DayRunLightStaOvrdFlg_C) {
    /* Switch: '<S636>/Switch1' incorporates:
     *  Constant: '<S411>/Constant2'
     */
    LampCtl_DayRunLightSta = LampCtl_DayRunLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->DayRunLightCtlFlg != 0);

    /* Switch: '<S636>/Switch1' incorporates:
     *  Switch: '<S636>/Switch2'
     *  UnitDelay: '<S675>/Unit Delay'
     */
    LampCtl_DayRunLightSta = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pt);
  }

  /* End of Switch: '<S636>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S411>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl();

  /* End of Outputs for SubSystem: '<S411>/BoxLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd13' */
  /* Switch: '<S640>/Switch1' incorporates:
   *  Constant: '<S411>/Constant28'
   */
  if (LampCtl_J449BoxLampOvrdFlg_C) {
    /* Switch: '<S640>/Switch1' incorporates:
     *  Constant: '<S411>/Constant27'
     */
    LampCtl_J449BoxLamp = LampCtl_J449BoxLampOvrdVal_C;
  } else {
    /* Switch: '<S640>/Switch1' incorporates:
     *  Switch: '<S640>/Switch2'
     *  UnitDelay: '<S624>/Unit Delay'
     */
    LampCtl_J449BoxLamp = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fb;
  }

  /* End of Switch: '<S640>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd13' */

  /* Outputs for Atomic SubSystem: '<S411>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl();

  /* End of Outputs for SubSystem: '<S411>/TurnIndcrCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl();

  /* End of Outputs for SubSystem: '<S411>/WelcomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd11' */
  /* Switch: '<S638>/Switch1' incorporates:
   *  Constant: '<S411>/Constant23'
   */
  if (LampCtl_TurnIndcrRStaOvrdFlg_C) {
    /* Switch: '<S638>/Switch1' incorporates:
     *  Constant: '<S411>/Constant24'
     */
    LampCtl_TurnIndcrRSta = LampCtl_TurnIndcrRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion11' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->TurnIndcrRCtlFlg != 0);

    /* Switch: '<S638>/Switch1' incorporates:
     *  Switch: '<S638>/Switch2'
     *  UnitDelay: '<S654>/Unit Delay17'
     */
    LampCtl_TurnIndcrRSta = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE);
  }

  /* End of Switch: '<S638>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd11' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd12' */
  /* Switch: '<S639>/Switch1' incorporates:
   *  Constant: '<S411>/Constant25'
   */
  if (LampCtl_TurnIndcrLStaOvrdFlg_C) {
    /* Switch: '<S639>/Switch1' incorporates:
     *  Constant: '<S411>/Constant26'
     */
    LampCtl_TurnIndcrLSta = LampCtl_TurnIndcrLStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion12' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->TurnIndcrLCtlFlg != 0);

    /* Switch: '<S639>/Switch1' incorporates:
     *  Switch: '<S639>/Switch2'
     *  UnitDelay: '<S654>/Unit Delay16'
     */
    LampCtl_TurnIndcrLSta = (rtb_DataTypeConversion3_d0 ||
      AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE);
  }

  /* End of Switch: '<S639>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd12' */

  /* Outputs for Atomic SubSystem: '<S411>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl();

  /* End of Outputs for SubSystem: '<S411>/DomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd10' */
  /* Switch: '<S637>/Switch1' incorporates:
   *  Constant: '<S411>/Constant22'
   */
  if (LampCtl_DomeLampPwmDutyOvrdFlg_C) {
    /* Switch: '<S637>/Switch1' incorporates:
     *  Constant: '<S411>/Constant21'
     */
    LampCtl_DomeLampPwmDuty = LampCtl_DomeLampPwmDutyOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion10' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->DomeLampCtlFlg != 0);

    /* Switch: '<S637>/Switch2' */
    if (rtb_DataTypeConversion3_d0) {
      /* Switch: '<S637>/Switch1' incorporates:
       *  Constant: '<S411>/Constant31'
       */
      LampCtl_DomeLampPwmDuty = 100U;
    } else {
      /* Switch: '<S637>/Switch1' */
      LampCtl_DomeLampPwmDuty = AppSwcBcm_ARID_DEF.Switch_k;
    }

    /* End of Switch: '<S637>/Switch2' */
  }

  /* End of Switch: '<S637>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd10' */

  /* Outputs for Atomic SubSystem: '<S411>/Ovrd8' */
  /* Switch: '<S648>/Switch1' incorporates:
   *  Constant: '<S411>/Constant16'
   */
  if (LampCtl_ReverseLampStaOvrdFlg_C) {
    /* Switch: '<S648>/Switch1' incorporates:
     *  Constant: '<S411>/Constant15'
     */
    LampCtl_ReverseLampSta = LampCtl_ReverseLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S411>/Data Type Conversion8' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_d0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->ReverseLampCtlFlg != 0);

    /* Switch: '<S648>/Switch2' */
    if (rtb_DataTypeConversion3_d0) {
      /* Switch: '<S648>/Switch1' incorporates:
       *  Switch: '<S648>/Switch2'
       */
      LampCtl_ReverseLampSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S411>/ReverseLampCtl' */
      AppSwcBcm_ReverseLampCtl();

      /* End of Outputs for SubSystem: '<S411>/ReverseLampCtl' */

      /* Switch: '<S648>/Switch1' incorporates:
       *  Switch: '<S648>/Switch2'
       */
      LampCtl_ReverseLampSta = AppSwcBcm_ARID_DEF.LogicalOperator_o;
    }

    /* End of Switch: '<S648>/Switch2' */
  }

  /* End of Switch: '<S648>/Switch1' */
  /* End of Outputs for SubSystem: '<S411>/Ovrd8' */
}

/* Update for atomic system: '<S4>/LampCtl' */
static void AppSwcBcm_LampCtl_Update(void)
{
  /* Update for UnitDelay: '<S411>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l4 = LampCtl_WelcomeLampSta;

  /* Update for UnitDelay: '<S411>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b = LampCtl_FlwrMeHomeSta;
}

/* Output and update for atomic system: '<S412>/Chart' */
static void AppSwcBcm_Chart(void)
{
  /* Chart: '<S412>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S412>/Unit Delay6'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
    PDUCtl_SysPowerSts = 0U;
    AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib) {
     case AppSwcBcm_IN_LocalOn:
      PDUCtl_SysPowerSts = 1U;
      if (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_g == 0) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = false;
      }
      break;

     case AppSwcBcm_IN_OTA1On:
      PDUCtl_SysPowerSts = 5U;
      if (PDUCtl_PwrOff) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = false;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_HUBCMOTAModeSet_enum == 3) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTAOn;
        PDUCtl_SysPowerSts = 3U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = true;
      }
      break;

     case AppSwcBcm_IN_OTAOn:
      PDUCtl_SysPowerSts = 3U;
      if (PDUCtl_PwrOff) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = false;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_HUBCMOTAModeSet_enum == 1) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTA1On;
        PDUCtl_SysPowerSts = 5U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = true;
      }
      break;

     case AppSwcBcm_IN_PSOff:
      PDUCtl_SysPowerSts = 0U;
      if (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_g == 2) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      } else if (PDUCtl_RemtPwrOn) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_RemoteOn;
        PDUCtl_SysPowerSts = 2U;
      } else {
        switch ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                ->VIPM_HUBCMOTAModeSet_enum) {
         case 1:
          AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTAOn;
          PDUCtl_SysPowerSts = 3U;
          AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = true;
          break;

         case 3:
          AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTA1On;
          PDUCtl_SysPowerSts = 5U;
          AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = true;
          break;
        }
      }
      break;

     default:
      /* case IN_RemoteOn: */
      PDUCtl_SysPowerSts = 2U;
      if (PDUCtl_PwrOff) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d = false;
      } else if (PDUCtl_KeyChk) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S412>/Chart' */
}

/* System initialize for atomic system: '<S412>/PwrOff' */
static void AppSwcBcm_PwrOff_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_li;

  /* SystemInitialize for Chart: '<S890>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_li);

  /* SystemInitialize for Chart: '<S890>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_o);
}

/* Output and update for atomic system: '<S412>/PwrOff' */
static void AppSwcBcm_PwrOff(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_li;
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_le;
  boolean rtb_LogicalOperator2_f5;
  boolean rtb_LogicalOperator2_na;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator11_c;
  boolean rtb_RelationalOperator22_d;
  boolean rtb_RelationalOperator5;
  boolean rtb_SysResetPwrOff;

  /* Chart: '<S890>/Chart' */
  if ((!AppSwcBcm_ARID_DEF.Flg_jj) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.SysPwrMode == 0)) {
    rtb_SysResetPwrOff = true;
    AppSwcBcm_ARID_DEF.Flg_jj = true;
  } else {
    rtb_SysResetPwrOff = false;
  }

  /* End of Chart: '<S890>/Chart' */

  /* RelationalOperator: '<S890>/Relational Operator11' */
  rtb_RelationalOperator11_c = !AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;

  /* Logic: '<S890>/Logical Operator' incorporates:
   *  Constant: '<S890>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S890>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S890>/Logical Operator1' incorporates:
   *  Constant: '<S890>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S890>/Relational Operator3'
   */
  rtb_LogicalOperator1_le =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S890>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator1_le);

  /* Logic: '<S890>/Logical Operator1' incorporates:
   *  Constant: '<S890>/Constant'
   *  Constant: '<S890>/Constant10'
   *  Constant: '<S890>/Constant11'
   *  Logic: '<S890>/Logical Operator7'
   *  RelationalOperator: '<S890>/Relational Operator'
   *  RelationalOperator: '<S890>/Relational Operator6'
   *  RelationalOperator: '<S890>/Relational Operator7'
   *  UnitDelay: '<S412>/Unit Delay2'
   *  UnitDelay: '<S412>/Unit Delay5'
   */
  rtb_LogicalOperator1_le = (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 2) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 1)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p == 2) && rtb_LogicalOperator);

  /* Outputs for Atomic SubSystem: '<S890>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    &rtb_LogicalOperator2_na, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet);

  /* End of Outputs for SubSystem: '<S890>/Lib_BothEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S890>/Lib_BothEdgeDet1' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    &rtb_LogicalOperator2_f5, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet1);

  /* End of Outputs for SubSystem: '<S890>/Lib_BothEdgeDet1' */

  /* Outputs for Atomic SubSystem: '<S890>/Lib_BothEdgeDet2' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_LogicalOperator9, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet2);

  /* End of Outputs for SubSystem: '<S890>/Lib_BothEdgeDet2' */

  /* Outputs for Atomic SubSystem: '<S890>/Lib_BothEdgeDet3' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_RelationalOperator5, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet3);

  /* End of Outputs for SubSystem: '<S890>/Lib_BothEdgeDet3' */

  /* Logic: '<S890>/Logical Operator2' incorporates:
   *  Logic: '<S890>/Logical Operator3'
   */
  rtb_RelationalOperator5 = ((!rtb_LogicalOperator2_na) &&
    (!rtb_LogicalOperator2_f5) && (!rtb_LogicalOperator9) &&
    (!rtb_RelationalOperator5));

  /* Logic: '<S890>/Logical Operator9' incorporates:
   *  Constant: '<S890>/Constant17'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S890>/Relational Operator1'
   */
  rtb_LogicalOperator9 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehHiddenMode_enum != 1);

  /* Chart: '<S890>/LIB_Tim' incorporates:
   *  Constant: '<S890>/Constant4'
   *  Constant: '<S890>/Constant5'
   *  Constant: '<S890>/Constant6'
   *  Constant: '<S890>/Constant7'
   *  Logic: '<S890>/Logical Operator4'
   *  RelationalOperator: '<S890>/Relational Operator12'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator11_c &&
      rtb_LogicalOperator1_le && rtb_RelationalOperator5 && rtb_LogicalOperator9)
  {
    if ((AppSwcBcm_ARID_DEF.Cnt_H_c >= PDUCtl_TimOutPwrOffH_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_M_h >= PDUCtl_TimOutPwrOffM_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_S_n >= PDUCtl_TimOutPwrOffS_C)) {
      PDUCtl_DelayTimPwrOff = true;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_Tick_g + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick_g + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_Tick_g = (uint16)tmp;
      PDUCtl_DelayTimPwrOff = false;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick_g >= 1.0F / PDUCtl_Ts_C) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_S_n + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_S_n + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_S_n = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_Tick_g = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_S_n >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_M_h + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_M_h + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_M_h = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_S_n = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_M_h >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_H_c + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_H_c + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_H_c = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      }
    }
  } else {
    PDUCtl_DelayTimPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_Tick_g = 0U;
    AppSwcBcm_ARID_DEF.Cnt_S_n = 0U;
    AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
    AppSwcBcm_ARID_DEF.Cnt_H_c = 0U;
  }

  /* End of Chart: '<S890>/LIB_Tim' */

  /* Chart: '<S890>/LIB_Tim1' incorporates:
   *  Constant: '<S890>/Constant25'
   *  Constant: '<S890>/Constant26'
   *  Constant: '<S890>/Constant27'
   *  Constant: '<S890>/Constant28'
   *  Constant: '<S890>/Constant29'
   *  Logic: '<S890>/Logical Operator14'
   *  Logic: '<S890>/Logical Operator15'
   *  RelationalOperator: '<S890>/Relational Operator16'
   *  UnitDelay: '<S412>/Unit Delay2'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 2) && (!PDUCtl_RemtPwrOn)) {
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

  /* End of Chart: '<S890>/LIB_Tim1' */

  /* RelationalOperator: '<S890>/Relational Operator13' incorporates:
   *  Constant: '<S890>/Constant22'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_LogicalOperator2_na = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC()
    )->VIPM_TBOXRemtPwrCtrlReq_enum == 2);

  /* Logic: '<S890>/Logical Operator12' incorporates:
   *  Constant: '<S890>/Constant23'
   *  Constant: '<S890>/Constant24'
   *  Logic: '<S908>/Logical Operator'
   *  Logic: '<S908>/Logical Operator1'
   *  RelationalOperator: '<S890>/Relational Operator14'
   *  RelationalOperator: '<S890>/Relational Operator15'
   *  UnitDelay: '<S412>/Unit Delay2'
   *  UnitDelay: '<S412>/Unit Delay5'
   *  UnitDelay: '<S908>/Unit Delay'
   */
  PDUCtl_RemtPwrOff = (rtb_LogicalOperator2_na &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fe) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p == 2) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 2));

  /* Chart: '<S890>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S890>/Constant19'
   *  Constant: '<S890>/Constant20'
   *  Constant: '<S890>/Constant21'
   *  UnitDelay: '<S4>/Unit Delay9'
   */
  AppSwcBcm_LIB_TPD_10ms(AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_j,
    PDUCtl_EmerPwrOffTimValid_C, PDUCtl_EmerPwrOffTimInValid_C, PDUCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_o, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts_p);

  /* Logic: '<S890>/Logical Operator13' incorporates:
   *  RelationalOperator: '<S890>/Relational Operator12'
   */
  PDUCtl_EmerPwrOff = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_o &&
                       AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* RelationalOperator: '<S890>/Relational Operator18' incorporates:
   *  Constant: '<S890>/Constant31'
   */
  rtb_LogicalOperator2_f5 = (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 1);

  /* Chart: '<S890>/LIB_PosPluse' incorporates:
   *  Constant: '<S890>/Constant33'
   *  UnitDelay: '<S4>/Unit Delay8'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i,
    PDUCtl_RemtPasvBrkSwTimValid_C, &rtb_LIB_blOut_li,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_l);

  /* Logic: '<S890>/Logical Operator16' incorporates:
   *  Constant: '<S890>/Constant30'
   *  Logic: '<S890>/Logical Operator17'
   *  Logic: '<S890>/Logical Operator18'
   *  Logic: '<S907>/Logical Operator'
   *  Logic: '<S907>/Logical Operator1'
   *  RelationalOperator: '<S890>/Relational Operator17'
   *  RelationalOperator: '<S890>/Relational Operator19'
   *  UnitDelay: '<S412>/Unit Delay2'
   *  UnitDelay: '<S907>/Unit Delay'
   */
  PDUCtl_RemtPasvPwrOff = ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 2) &&
    ((rtb_LogicalOperator2_f5 && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh)) ||
     (rtb_LIB_blOut_li && (!AppSwcBcm_ARID_DEF.LogicalOperator10))));

  /* Logic: '<S890>/Logical Operator9' incorporates:
   *  Constant: '<S890>/Constant34'
   *  Constant: '<S890>/Constant35'
   *  Logic: '<S890>/Logical Operator19'
   *  RelationalOperator: '<S890>/Relational Operator20'
   *  RelationalOperator: '<S890>/Relational Operator21'
   *  UnitDelay: '<S412>/Unit Delay2'
   */
  rtb_LogicalOperator9 = ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 3) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a == 5));

  /* Chart: '<S890>/LIB_PosPluse1' incorporates:
   *  Constant: '<S890>/Constant37'
   *  Logic: '<S890>/Logical Operator22'
   */
  if (rtb_LogicalOperator9) {
    if (AppSwcBcm_ARID_DEF.Cnt_j <= PDUCtl_OTAOverTimPwrOff_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_j + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_j + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_j = (uint16)tmp;
      PDUCtl_OTAOverTimPwrOff = false;
    } else {
      PDUCtl_OTAOverTimPwrOff = true;
    }
  } else {
    PDUCtl_OTAOverTimPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_j = 0U;
  }

  /* End of Chart: '<S890>/LIB_PosPluse1' */

  /* RelationalOperator: '<S890>/Relational Operator22' incorporates:
   *  Constant: '<S890>/Constant36'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator22_d = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUBCMOTAModeSet_enum == 2);

  /* Logic: '<S890>/Logical Operator20' incorporates:
   *  Logic: '<S909>/Logical Operator'
   *  Logic: '<S909>/Logical Operator1'
   *  UnitDelay: '<S909>/Unit Delay'
   */
  PDUCtl_OTAPwrOff = (rtb_RelationalOperator22_d &&
                      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_iu) &&
                      rtb_LogicalOperator9);

  /* Logic: '<S890>/Logical Operator5' incorporates:
   *  Constant: '<S890>/Constant12'
   *  Constant: '<S890>/Constant13'
   *  Constant: '<S890>/Constant14'
   *  Logic: '<S890>/Logical Operator10'
   *  Logic: '<S890>/Logical Operator11'
   *  Logic: '<S890>/Logical Operator9'
   *  RelationalOperator: '<S890>/Relational Operator10'
   *  RelationalOperator: '<S890>/Relational Operator12'
   *  RelationalOperator: '<S890>/Relational Operator4'
   *  RelationalOperator: '<S890>/Relational Operator8'
   *  RelationalOperator: '<S890>/Relational Operator9'
   *  UnitDelay: '<S412>/Unit Delay2'
   *  UnitDelay: '<S412>/Unit Delay5'
   */
  PDUCtl_OsLckPwrOff = (rtb_LogicalOperator && rtb_RelationalOperator11_c &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a != 3) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a != 5)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p == 2)) &&
                        AppSwcBcm_ARID_DEF.BusCreator4.OsLck &&
                        (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) &&
                        AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* RelationalOperator: '<S890>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUPwrOffReq_flg;

  /* Logic: '<S890>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S890>/Relational Operator12'
   */
  PDUCtl_HUPwrOff = (rtb_RelationalOperator5 &&
                     AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
                     rtb_LogicalOperator1_le);

  /* Logic: '<S890>/Logical Operator6' incorporates:
   *  Logic: '<S890>/Logical Operator21'
   */
  PDUCtl_PwrOff = (PDUCtl_OsLckPwrOff || PDUCtl_HUPwrOff ||
                   PDUCtl_DelayTimPwrOff || PDUCtl_EmerPwrOff ||
                   PDUCtl_RemtPwrOff || PDUCtl_RemtOverTimPwrOff ||
                   PDUCtl_RemtPasvPwrOff || (PDUCtl_OTAPwrOff ||
    PDUCtl_OTAOverTimPwrOff) || rtb_SysResetPwrOff);

  /* Update for UnitDelay: '<S908>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fe = rtb_LogicalOperator2_na;

  /* Update for UnitDelay: '<S907>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh = rtb_LogicalOperator2_f5;

  /* Update for UnitDelay: '<S909>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_iu = rtb_RelationalOperator22_d;
}

/*
 * Output and update for atomic system:
 *    '<S891>/Lib_FailEdgeDet'
 *    '<S891>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_m_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S914>/Logical Operator' incorporates:
   *  Logic: '<S914>/Logical Operator1'
   *  UnitDelay: '<S914>/Unit Delay'
   */
  rty_Lib_blOut_0 = ((!rtu_Lib_blIn) &&
                     AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S914>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S412>/PwrOn' */
static void AppSwcBcm_PwrOn_Init(void)
{
  /* SystemInitialize for Chart: '<S891>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms11_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg);
}

/* Output and update for atomic system: '<S412>/PwrOn' */
static void AppSwcBcm_PwrOn(void)
{
  sint32 tmp;
  boolean rtb_LIB_blOut_i;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator2_jn;
  boolean rtb_RelationalOperator2_lk;
  boolean rtb_RelationalOperator5;

  /* Chart: '<S891>/BrkPwrOn' incorporates:
   *  Constant: '<S891>/Constant3'
   *  UnitDelay: '<S412>/Unit Delay4'
   *  UnitDelay: '<S4>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib == AppSwcBcm_IN_Invalid) {
    AppSwcBcm_ARID_DEF.Lib_blIn_e = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i;

    /* Outputs for Function Call SubSystem: '<S910>/Lib_RiseEdgeDet' */
    AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_e,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fq,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_n);

    /* End of Outputs for SubSystem: '<S910>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fq) {
      AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib = AppSwcBcm_IN_Valid;
      tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_i = (uint16)tmp;
      AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;
    }

    /* case IN_Valid: */
  } else if ((!AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i) ||
             (AppSwcBcm_ARID_DEF.Cnt_i > PDUCtl_PwrOnPSTimValid_C) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a) {
    AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_i = (uint16)tmp;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;

    /* Lib_RiseEdgeDetInit(LampCtl_BrakeLightSw); */
  }

  /* End of Chart: '<S891>/BrkPwrOn' */

  /* RelationalOperator: '<S891>/Relational Operator5' incorporates:
   *  Constant: '<S891>/Constant8'
   */
  rtb_RelationalOperator5 = (AppSwcBcm_ARID_DEF.BusCreator14.SKSta == 1);

  /* Switch: '<S918>/Switch' incorporates:
   *  Constant: '<S891>/Constant10'
   *  Constant: '<S891>/Constant9'
   *  Logic: '<S891>/Logical Operator7'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    AppSwcBcm_ARID_DEF.LogicalOperator10 = PDUCtl_KeyValidOvrdVal_C;
  } else {
    /* RelationalOperator: '<S891>/Relational Operator2' incorporates:
     *  Constant: '<S891>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
     */
    rtb_RelationalOperator2_jn = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus
      ())->KeySta != 0);
    AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator2_jn ||
      rtb_RelationalOperator5);
  }

  /* End of Switch: '<S918>/Switch' */

  /* Logic: '<S891>/Logical Operator5' */
  PDUCtl_KeyChk = (AppSwcBcm_ARID_DEF.BrkPwrOnValid &&
                   AppSwcBcm_ARID_DEF.LogicalOperator10);

  /* Logic: '<S891>/Logical Operator3' incorporates:
   *  Constant: '<S891>/Constant4'
   *  Constant: '<S891>/Constant5'
   *  RelationalOperator: '<S891>/Relational Operator'
   *  RelationalOperator: '<S891>/Relational Operator3'
   *  UnitDelay: '<S412>/Unit Delay'
   *  UnitDelay: '<S412>/Unit Delay1'
   */
  rtb_RelationalOperator2_jn = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ds == 0));

  /* Logic: '<S891>/Logical Operator1' */
  PDUCtl_BrkPwrOn = (rtb_RelationalOperator2_jn && PDUCtl_KeyChk);

  /* Chart: '<S891>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S891>/Constant16'
   *  Constant: '<S891>/Constant17'
   */
  AppSwcBcm_LIB_TPD_10ms11(AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrOn_d,
    PDUCtl_OTAPwrOnDelayTim_C, PDUCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts);

  /* Logic: '<S917>/Logical Operator' incorporates:
   *  Logic: '<S917>/Logical Operator1'
   *  UnitDelay: '<S917>/Unit Delay'
   */
  PDUCtl_OTAPwrOn = (AppSwcBcm_ARID_DEF.LIB_bErrFlg &&
                     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kr));

  /* RelationalOperator: '<S891>/Relational Operator4' incorporates:
   *  Constant: '<S891>/Constant'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_f = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* RelationalOperator: '<S921>/Relational Operator2' incorporates:
   *  UnitDelay: '<S891>/Unit Delay'
   */
  rtb_RelationalOperator2_lk = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o;

  /* Logic: '<S891>/Logical Operator8' incorporates:
   *  Constant: '<S891>/Constant7'
   *  RelationalOperator: '<S891>/Relational Operator6'
   *  UnitDelay: '<S891>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_l = (AppSwcBcm_ARID_DEF.Lib_blIn_f ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o ||
    (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2));

  /* Chart: '<S891>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S912>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_l,
    &AppSwcBcm_ARID_DEF.LogicalOperator_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_d) {
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
    AppSwcBcm_ARID_DEF.Flg_l = false;
  }

  /* Chart: '<S891>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S912>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_f,
    &AppSwcBcm_ARID_DEF.LogicalOperator_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_g) {
    AppSwcBcm_ARID_DEF.Flg_l = true;
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_l) {
    /* Constant: '<S891>/Constant6' */
    if (AppSwcBcm_ARID_DEF.Cnt_c <= PDUCtl_OpenDoorPwrOnTimValid) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_c + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_c + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_c = (uint16)tmp;
      rtb_LIB_blOut_i = true;
    } else {
      rtb_LIB_blOut_i = false;
      AppSwcBcm_ARID_DEF.Flg_l = false;
    }

    /* End of Constant: '<S891>/Constant6' */
  } else {
    rtb_LIB_blOut_i = false;
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S891>/Lib_FailEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet_a
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S891>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S891>/Lib_FailEdgeDet1' */
  rtb_RelationalOperator2_lk = AppSwcBcm_Lib_FailEdgeDet_a
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1);

  /* End of Outputs for SubSystem: '<S891>/Lib_FailEdgeDet1' */

  /* Switch: '<S919>/Switch' incorporates:
   *  Constant: '<S891>/Constant11'
   *  Constant: '<S891>/Constant12'
   *  Logic: '<S891>/Logical Operator6'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    rtb_RelationalOperator5 = PDUCtl_KeyValidOvrdVal_C;
  } else {
    rtb_RelationalOperator5 = (rtb_LIB_blOut_i || rtb_RelationalOperator5);
  }

  /* Logic: '<S891>/Logical Operator' incorporates:
   *  Logic: '<S891>/Logical Operator4'
   *  Switch: '<S919>/Switch'
   */
  PDUCtl_OpenDoorPwrOn = (rtb_RelationalOperator5 && (rtb_RelationalOperator2_lk
    || rtb_LogicalOperator) && rtb_RelationalOperator2_jn);

  /* RelationalOperator: '<S891>/Relational Operator7' incorporates:
   *  Constant: '<S891>/Constant13'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC()
    )->VIPM_TBOXRemtPwrCtrlReq_enum == 1);

  /* Logic: '<S891>/Logical Operator9' incorporates:
   *  Constant: '<S891>/Constant15'
   *  Logic: '<S916>/Logical Operator'
   *  Logic: '<S916>/Logical Operator1'
   *  RelationalOperator: '<S891>/Relational Operator9'
   *  UnitDelay: '<S412>/Unit Delay'
   *  UnitDelay: '<S916>/Unit Delay'
   */
  PDUCtl_RemtPwrOn = (rtb_RelationalOperator5 &&
                      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pw) &&
                      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ds == 0));

  /* Logic: '<S891>/Logical Operator2' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o = (PDUCtl_OpenDoorPwrOn ||
    PDUCtl_BrkPwrOn || PDUCtl_RemtPwrOn || PDUCtl_OTAPwrOn);

  /* Chart: '<S891>/RemoteLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Init_oy;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib) {
     case AppSwcBcm_IN_Init_oy:
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

  /* End of Chart: '<S891>/RemoteLck' */

  /* Chart: '<S891>/Chart' */
  if ((!AppSwcBcm_ARID_DEF.Flg_j) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.SysPwrMode == 2)) {
    rtb_RelationalOperator2_jn = true;
    AppSwcBcm_ARID_DEF.Flg_j = true;
  } else {
    rtb_RelationalOperator2_jn = false;
  }

  /* End of Chart: '<S891>/Chart' */

  /* Logic: '<S891>/Logical Operator11' incorporates:
   *  Constant: '<S891>/Constant1'
   *  Logic: '<S891>/Logical Operator10'
   *  RelationalOperator: '<S891>/Relational Operator1'
   */
  PDUCtl_PwrOn = ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o &&
                   (PDUCtl_RemotePwrLckSta == 0)) || rtb_RelationalOperator2_jn);

  /* RelationalOperator: '<S921>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_jn = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLckVld_flg;

  /* RelationalOperator: '<S921>/Relational Operator2' incorporates:
   *  Constant: '<S921>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S921>/Relational Operator'
   */
  rtb_RelationalOperator2_lk = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLck_enum == 1);

  /* Logic: '<S921>/Logical Operator' */
  rtb_LIB_blOut_i = (rtb_RelationalOperator2_lk && rtb_RelationalOperator2_jn);

  /* RelationalOperator: '<S921>/Relational Operator2' incorporates:
   *  Constant: '<S921>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_lk = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLck_enum == 2);

  /* Switch: '<S921>/Switch' incorporates:
   *  Logic: '<S921>/Logical Operator1'
   *  Logic: '<S921>/Logical Operator2'
   */
  PDUCtl_RemotePwrLckFb = ((rtb_RelationalOperator2_lk &&
    rtb_RelationalOperator2_jn) || rtb_LIB_blOut_i);

  /* Update for UnitDelay: '<S917>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kr = AppSwcBcm_ARID_DEF.LIB_bErrFlg;

  /* Update for UnitDelay: '<S916>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pw = rtb_RelationalOperator5;
}

/* Output and update for atomic system: '<S412>/RelayDig' */
static void AppSwcBcm_RelayDig(void)
{
  float32 tmp;
  boolean rtb_RelationalOperator3_fr;
  boolean rtb_RelationalOperator7_k;

  /* RelationalOperator: '<S892>/Relational Operator3' incorporates:
   *  Constant: '<S892>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S892>/Relational Operator2'
   */
  rtb_RelationalOperator3_fr =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* RelationalOperator: '<S892>/Relational Operator7' incorporates:
   *  Constant: '<S892>/Constant'
   *  Logic: '<S892>/Logical Operator'
   *  RelationalOperator: '<S892>/Relational Operator'
   */
  rtb_RelationalOperator7_k = ((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator3_fr);

  /* RelationalOperator: '<S892>/Relational Operator3' incorporates:
   *  Constant: '<S892>/Constant3'
   */
  rtb_RelationalOperator3_fr = (PDUCtl_SysPwrMode == 0);

  /* RelationalOperator: '<S892>/Relational Operator7' incorporates:
   *  Logic: '<S892>/Logical Operator1'
   */
  rtb_RelationalOperator7_k = (rtb_RelationalOperator3_fr ||
    rtb_RelationalOperator7_k);

  /* Chart: '<S892>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S892>/Constant6'
   *  Constant: '<S892>/Constant7'
   *  Logic: '<S892>/Logical Operator3'
   *  RelationalOperator: '<S892>/Relational Operator5'
   */
  if (rtb_RelationalOperator7_k && (PDUCtl_J437IG2RlyCtl !=
       AppSwcBcm_ARID_DEF.Switch_k)) {
    tmp = 50.0F / (PDUCtl_Ts_C * 100.0F);
    if (AppSwcBcm_ARID_DEF.cnt_defect_c >= tmp) {
      PDUCtl_IG2RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c++;
      AppSwcBcm_ARID_DEF.cnt_heal_l = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_l == 0) {
      PDUCtl_IG2RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_l--;
    }
  }

  /* End of Chart: '<S892>/LIB_TPD_10ms1' */

  /* Chart: '<S892>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S892>/Constant4'
   *  Constant: '<S892>/Constant5'
   *  Constant: '<S892>/Constant8'
   *  Logic: '<S892>/Logical Operator2'
   *  RelationalOperator: '<S892>/Relational Operator4'
   */
  if (rtb_RelationalOperator7_k && (PDUCtl_J421IG1RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller35)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_f >= 50.0F / (PDUCtl_Ts_C * 100.0F)) {
      PDUCtl_IG1RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_f++;
      AppSwcBcm_ARID_DEF.cnt_heal_i = (uint16)(50.0F / (PDUCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_f = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_i == 0) {
      PDUCtl_IG1RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_i--;
    }
  }

  /* End of Chart: '<S892>/LIB_TPD_10ms2' */

  /* Switch: '<S892>/Switch' incorporates:
   *  Logic: '<S892>/Logical Operator4'
   */
  PDUCtl_SysPwrModeV = ((!PDUCtl_IG1RelayFault) && (!PDUCtl_IG2RelayFault));

  /* Chart: '<S892>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S892>/Constant1'
   *  Constant: '<S892>/Constant12'
   *  Constant: '<S892>/Constant13'
   *  Constant: '<S892>/Constant14'
   *  Constant: '<S892>/Constant15'
   *  Constant: '<S892>/Constant16'
   *  Constant: '<S892>/Constant17'
   *  Constant: '<S892>/Constant18'
   *  Logic: '<S892>/Logical Operator5'
   *  Logic: '<S892>/Logical Operator6'
   *  Logic: '<S892>/Logical Operator7'
   *  RelationalOperator: '<S892>/Relational Operator1'
   *  RelationalOperator: '<S892>/Relational Operator6'
   *  RelationalOperator: '<S892>/Relational Operator7'
   *  RelationalOperator: '<S892>/Relational Operator8'
   *  RelationalOperator: '<S892>/Relational Operator9'
   */
  if (((AppSwcBcm_ARID_DEF.Switch_k == 1) || (AppSwcBcm_ARID_DEF.CCaller35 == 1))
      && ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 2)) &&
      rtb_RelationalOperator3_fr) {
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

  /* End of Chart: '<S892>/LIB_TPD_10ms3' */
}

/* System initialize for atomic system: '<S412>/StartReq' */
static void AppSwcBcm_StartReq_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ce;
  boolean rtb_LIB_blOut_gn;

  /* SystemInitialize for Chart: '<S894>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_gn);

  /* SystemInitialize for Chart: '<S894>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_ce);
}

/* Output and update for atomic system: '<S412>/StartReq' */
static void AppSwcBcm_StartReq(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ce;
  boolean rtb_LIB_blOut_gn;
  boolean rtb_RelationalOperator6_k3;
  boolean rtb_SysResetStartOff;
  boolean rtb_SysResetStartOn;

  /* Chart: '<S894>/Chart' */
  if ((!AppSwcBcm_ARID_DEF.Flg_h) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.StartReq == 1)) {
    rtb_SysResetStartOn = true;
    AppSwcBcm_ARID_DEF.Flg_h = true;
  } else {
    rtb_SysResetStartOn = false;
  }

  /* End of Chart: '<S894>/Chart' */

  /* Chart: '<S894>/LIB_PosPluse' incorporates:
   *  Constant: '<S894>/Constant3'
   *  Constant: '<S894>/Constant4'
   *  Logic: '<S894>/Logical Operator'
   *  RelationalOperator: '<S894>/Relational Operator3'
   *  UnitDelay: '<S4>/Unit Delay8'
   */
  AppSwcBcm_LIB_PosPluse((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i, PDUCtl_StartReqTimValid_C,
    &rtb_LIB_blOut_gn, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse);

  /* RelationalOperator: '<S894>/Relational Operator6' incorporates:
   *  Constant: '<S894>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S894>/Relational Operator1'
   */
  rtb_RelationalOperator6_k3 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Logic: '<S894>/Logical Operator5' incorporates:
   *  Constant: '<S894>/Constant1'
   *  Logic: '<S894>/Logical Operator1'
   *  RelationalOperator: '<S894>/Relational Operator'
   *  RelationalOperator: '<S894>/Relational Operator2'
   *  RelationalOperator: '<S894>/Relational Operator7'
   */
  rtb_SysResetStartOn = (rtb_SysResetStartOn || (PDUCtl_SysPwrModeV &&
    PDUCtl_KeyChk && rtb_LIB_blOut_gn && (PDUCtl_SysPowerSts == 1) &&
    rtb_RelationalOperator6_k3));

  /* Chart: '<S894>/Chart1' */
  if ((!AppSwcBcm_ARID_DEF.Flg) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.StartReq == 0)) {
    rtb_SysResetStartOff = true;
    AppSwcBcm_ARID_DEF.Flg = true;
  } else {
    rtb_SysResetStartOff = false;
  }

  /* End of Chart: '<S894>/Chart1' */

  /* RelationalOperator: '<S894>/Relational Operator6' incorporates:
   *  Constant: '<S894>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S894>/Relational Operator5'
   */
  rtb_RelationalOperator6_k3 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S894>/LIB_PosPluse1' incorporates:
   *  Constant: '<S894>/Constant5'
   *  Logic: '<S894>/Logical Operator3'
   *  UnitDelay: '<S894>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(rtb_RelationalOperator6_k3 &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ke, PDUCtl_StartReqOverTimValid_C,
    &rtb_LIB_blOut_ce, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1);

  /* Outputs for Atomic SubSystem: '<S894>/Lib_SR' */
  /* Outputs for Atomic SubSystem: '<S894>/Lib_RiseEdgeDetHold' */
  /* Switch: '<S938>/Switch' incorporates:
   *  Constant: '<S894>/Constant6'
   *  Logic: '<S894>/Logical Operator2'
   *  Logic: '<S894>/Logical Operator4'
   *  Logic: '<S937>/Logical Operator'
   *  Logic: '<S937>/Logical Operator1'
   *  RelationalOperator: '<S894>/Relational Operator4'
   *  RelationalOperator: '<S894>/Relational Operator6'
   *  RelationalOperator: '<S894>/Relational Operator8'
   *  Switch: '<S939>/Switch'
   *  UnitDelay: '<S937>/Unit Delay'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
       ((!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw) &&
        AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mb) &&
       (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) || (PDUCtl_SysPwrMode ==
       0) || rtb_SysResetStartOff || rtb_LIB_blOut_ce) {
    /* Switch: '<S938>/Switch' incorporates:
     *  Constant: '<S938>/Constant'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p = false;

    /* Switch: '<S939>/Switch' incorporates:
     *  Constant: '<S939>/Constant'
     */
    PDUCtl_StartReq = false;
  } else {
    /* Switch: '<S938>/Switch' incorporates:
     *  Logic: '<S938>/Logical Operator'
     *  Logic: '<S938>/Logical Operator1'
     *  Logic: '<S938>/Logical Operator2'
     *  UnitDelay: '<S938>/Unit Delay'
     *  UnitDelay: '<S938>/Unit Delay1'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p = ((rtb_SysResetStartOn &&
      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_lr)) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p);

    /* Switch: '<S939>/Switch' incorporates:
     *  Logic: '<S939>/Logical Operator'
     *  UnitDelay: '<S939>/Unit Delay'
     */
    PDUCtl_StartReq = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p || PDUCtl_StartReq);
  }

  /* End of Switch: '<S938>/Switch' */
  /* End of Outputs for SubSystem: '<S894>/Lib_SR' */

  /* Update for UnitDelay: '<S938>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_lr = rtb_SysResetStartOn;

  /* End of Outputs for SubSystem: '<S894>/Lib_RiseEdgeDetHold' */

  /* Update for UnitDelay: '<S894>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ke = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S937>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mb =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;
}

/* Output and update for atomic system: '<S412>/Subsystem' */
static void AppSwcBcm_Subsystem(void)
{
  boolean rtb_RelationalOperator1_hb;
  boolean rtb_RelationalOperator_jq;

  /* RelationalOperator: '<S895>/Relational Operator' incorporates:
   *  Constant: '<S895>/Constant'
   */
  rtb_RelationalOperator_jq = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S895>/Relational Operator1' incorporates:
   *  Constant: '<S895>/Constant1'
   */
  rtb_RelationalOperator1_hb = (AppSwcBcm_ARID_DEF.Switch_k == 1);

  /* Switch: '<S895>/Switch' incorporates:
   *  Logic: '<S895>/Logical Operator'
   *  Logic: '<S895>/Logical Operator1'
   *  Logic: '<S895>/Logical Operator2'
   *  Logic: '<S895>/Logical Operator3'
   *  Switch: '<S895>/Switch1'
   */
  if (rtb_RelationalOperator_jq && rtb_RelationalOperator1_hb) {
    /* Switch: '<S895>/Switch' incorporates:
     *  Constant: '<S895>/Constant2'
     */
    PDUCtl_SysPwrModeAct = 2U;
  } else if ((!rtb_RelationalOperator_jq) && (!rtb_RelationalOperator1_hb)) {
    /* Switch: '<S895>/Switch1' incorporates:
     *  Constant: '<S895>/Constant3'
     *  Switch: '<S895>/Switch'
     */
    PDUCtl_SysPwrModeAct = 0U;
  }

  /* End of Switch: '<S895>/Switch' */
}

/* Output and update for atomic system: '<S412>/Truth Table' */
static void AppSwcBcm_TruthTable_k(void)
{
  /* UnitDelay: '<S887>/Unit Delay' */
  /*  Example condition 1 */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dd) {
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

  /* End of UnitDelay: '<S887>/Unit Delay' */
}

/* System initialize for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S412>/PwrOff' */
  AppSwcBcm_PwrOff_Init();

  /* End of SystemInitialize for SubSystem: '<S412>/PwrOff' */

  /* SystemInitialize for Atomic SubSystem: '<S412>/PwrOn' */
  AppSwcBcm_PwrOn_Init();

  /* End of SystemInitialize for SubSystem: '<S412>/PwrOn' */

  /* SystemInitialize for Atomic SubSystem: '<S412>/StartReq' */
  AppSwcBcm_StartReq_Init();

  /* End of SystemInitialize for SubSystem: '<S412>/StartReq' */
}

/* Output and update for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion;

  /* Chart: '<S412>/Chart' */
  AppSwcBcm_Chart();

  /* Outputs for Atomic SubSystem: '<S412>/PwrOn' */
  AppSwcBcm_PwrOn();

  /* End of Outputs for SubSystem: '<S412>/PwrOn' */

  /* Outputs for Atomic SubSystem: '<S412>/PwrOff' */
  AppSwcBcm_PwrOff();

  /* End of Outputs for SubSystem: '<S412>/PwrOff' */

  /* Chart: '<S412>/RemtPwrCtlFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c12_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c12_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Init_k;
    PDUCtl_RemtPwrCtlFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_b2 = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib) {
     case AppSwcBcm_IN_Fail_p:
      PDUCtl_RemtPwrCtlFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_b2 >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Init_k;
        PDUCtl_RemtPwrCtlFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_b2 = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_b2++;
      }
      break;

     case AppSwcBcm_IN_Init_k:
      PDUCtl_RemtPwrCtlFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_o =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtPwrCtrlReq_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtPwrCtrlReq_enum == 2));

      /* Outputs for Function Call SubSystem: '<S893>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_o,
        &AppSwcBcm_ARID_DEF.LogicalOperator_f,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g);

      /* End of Outputs for SubSystem: '<S893>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_f) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Wait_n;
      }
      break;

     case AppSwcBcm_IN_Suc_he:
      PDUCtl_RemtPwrCtlFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_b2 >= 5) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Init_k;
        PDUCtl_RemtPwrCtlFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_b2 = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_b2++;
      }
      break;

     default:
      /* case IN_Wait: */
      if (PDUCtl_RemtPwrOff || PDUCtl_RemtPwrOn) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Suc_he;
        PDUCtl_RemtPwrCtlFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_b2 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_b2 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_b2 = (uint8)tmp;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_TBOXRemtPwrCtrlReq_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c12_PDUCtl_Lib = AppSwcBcm_IN_Fail_p;
        PDUCtl_RemtPwrCtlFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_b2 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_b2 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_b2 = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S412>/RemtPwrCtlFb' */

  /* Outputs for Atomic SubSystem: '<S412>/Lib_SR' */
  /* Switch: '<S887>/Switch' incorporates:
   *  Constant: '<S887>/Constant'
   *  Logic: '<S887>/Logical Operator'
   *  UnitDelay: '<S887>/Unit Delay'
   */
  if (PDUCtl_PwrOff) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dd = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dd = (PDUCtl_PwrOn ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dd);
  }

  /* End of Switch: '<S887>/Switch' */
  /* End of Outputs for SubSystem: '<S412>/Lib_SR' */

  /* Truth Table: '<S412>/Truth Table' */
  AppSwcBcm_TruthTable_k();

  /* Outputs for Atomic SubSystem: '<S412>/Ovrd1' */
  /* Switch: '<S888>/Switch1' incorporates:
   *  Constant: '<S412>/Constant18'
   *  Constant: '<S412>/Constant19'
   */
  if (PDUCtl_J421IG1RlyCtlOvrdFlg_C) {
    PDUCtl_J421IG1RlyCtl = (uint8)PDUCtl_J421IG1RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S412>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->IG1RlyCtlFlg != 0);

    /* Switch: '<S888>/Switch2' */
    if (rtb_DataTypeConversion) {
      PDUCtl_J421IG1RlyCtl = 1U;
    } else {
      PDUCtl_J421IG1RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J421;
    }

    /* End of Switch: '<S888>/Switch2' */
  }

  /* End of Switch: '<S888>/Switch1' */
  /* End of Outputs for SubSystem: '<S412>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S412>/Ovrd2' */
  /* Switch: '<S889>/Switch1' incorporates:
   *  Constant: '<S412>/Constant1'
   *  Constant: '<S412>/Constant2'
   */
  if (PDUCtl_J437IG2RlyCtlOvrdFlg_C) {
    PDUCtl_J437IG2RlyCtl = (uint8)PDUCtl_J437IG2RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S412>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus())
      ->IG2RlyCtlFlg != 0);

    /* Switch: '<S889>/Switch2' */
    if (rtb_DataTypeConversion) {
      PDUCtl_J437IG2RlyCtl = 1U;
    } else {
      PDUCtl_J437IG2RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J437;
    }

    /* End of Switch: '<S889>/Switch2' */
  }

  /* End of Switch: '<S889>/Switch1' */
  /* End of Outputs for SubSystem: '<S412>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S412>/RelayDig' */
  AppSwcBcm_RelayDig();

  /* End of Outputs for SubSystem: '<S412>/RelayDig' */

  /* Outputs for Atomic SubSystem: '<S412>/StartReq' */
  AppSwcBcm_StartReq();

  /* End of Outputs for SubSystem: '<S412>/StartReq' */

  /* Outputs for Atomic SubSystem: '<S412>/Subsystem' */
  AppSwcBcm_Subsystem();

  /* End of Outputs for SubSystem: '<S412>/Subsystem' */

  /* Update for UnitDelay: '<S412>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_g = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S412>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ds = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S412>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c = PDUCtl_SysPowerSts;

  /* Update for UnitDelay: '<S412>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S412>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S412>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_a = PDUCtl_SysPowerSts;
}

/* System initialize for atomic system: '<S940>/NMCtl' */
static void AppSwcBcm_NMCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;

  /* InitializeConditions for Delay: '<S945>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = true;

  /* InitializeConditions for Delay: '<S946>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = true;

  /* InitializeConditions for Delay: '<S947>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a = true;

  /* InitializeConditions for Delay: '<S948>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = true;

  /* InitializeConditions for Delay: '<S949>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = true;

  /* SystemInitialize for Chart: '<S941>/LIB_NegPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_o);
}

/* Output and update for atomic system: '<S940>/NMCtl' */
static void AppSwcBcm_NMCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;
  sint32 tmp;
  boolean rtb_LIB_blOut_jr;
  boolean rtb_LogicalOperator6_et;
  boolean rtb_LogicalOperator7_kh;
  boolean rtb_RelationalOperator26;
  boolean rtb_RelationalOperator27;
  boolean rtb_RelationalOperator28;

  /* RelationalOperator: '<S941>/Relational Operator26' incorporates:
   *  Constant: '<S941>/Constant28'
   */
  rtb_RelationalOperator26 = (AppSwcBcm_ARID_DEF.BusCreator5.RKEReq != 0);

  /* Delay: '<S945>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_j) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_f =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S946>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_m) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_o =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Delay: '<S947>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_a) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_bd =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Delay: '<S948>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_g) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_br =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;
  }

  /* Delay: '<S949>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_b) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_gt =
      AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;
  }

  /* Logic: '<S941>/Logical Operator10' incorporates:
   *  Delay: '<S945>/Delay'
   *  Delay: '<S946>/Delay'
   *  Delay: '<S947>/Delay'
   *  Delay: '<S948>/Delay'
   *  Delay: '<S949>/Delay'
   *  Logic: '<S945>/Logical Operator1'
   *  Logic: '<S945>/Logical Operator2'
   *  Logic: '<S945>/Logical Operator3'
   *  Logic: '<S945>/Logical Operator4'
   *  Logic: '<S945>/Logical Operator5'
   *  Logic: '<S946>/Logical Operator1'
   *  Logic: '<S946>/Logical Operator2'
   *  Logic: '<S946>/Logical Operator3'
   *  Logic: '<S946>/Logical Operator4'
   *  Logic: '<S946>/Logical Operator5'
   *  Logic: '<S947>/Logical Operator1'
   *  Logic: '<S947>/Logical Operator2'
   *  Logic: '<S947>/Logical Operator3'
   *  Logic: '<S947>/Logical Operator4'
   *  Logic: '<S947>/Logical Operator5'
   *  Logic: '<S948>/Logical Operator1'
   *  Logic: '<S948>/Logical Operator2'
   *  Logic: '<S948>/Logical Operator3'
   *  Logic: '<S948>/Logical Operator4'
   *  Logic: '<S948>/Logical Operator5'
   *  Logic: '<S949>/Logical Operator1'
   *  Logic: '<S949>/Logical Operator2'
   *  Logic: '<S949>/Logical Operator3'
   *  Logic: '<S949>/Logical Operator4'
   *  Logic: '<S949>/Logical Operator5'
   *  Logic: '<S951>/Logical Operator'
   *  Logic: '<S951>/Logical Operator1'
   *  UnitDelay: '<S951>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator26 ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_f &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_f))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_o &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_o))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_bd &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_bd))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_br &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_br))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_gt &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_gt))) ||
    (AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a5)));

  /* RelationalOperator: '<S941>/Relational Operator27' incorporates:
   *  Constant: '<S941>/Constant29'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->DrvPEAuthentAcsd == 1);

  /* Logic: '<S941>/Logical Operator6' */
  rtb_LogicalOperator6_et = (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    rtb_RelationalOperator27);

  /* RelationalOperator: '<S941>/Relational Operator28' incorporates:
   *  Constant: '<S941>/Constant30'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator28 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->FRPEAuthentAcsd == 1);

  /* Logic: '<S941>/Logical Operator7' */
  rtb_LogicalOperator7_kh = (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
    rtb_RelationalOperator28);

  /* Logic: '<S941>/Logical Operator9' incorporates:
   *  Logic: '<S952>/Logical Operator'
   *  Logic: '<S952>/Logical Operator1'
   *  Logic: '<S953>/Logical Operator'
   *  Logic: '<S953>/Logical Operator1'
   *  UnitDelay: '<S952>/Unit Delay'
   *  UnitDelay: '<S953>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (rtb_LogicalOperator6_et && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ly)) ||
    (rtb_LogicalOperator7_kh && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ey)));

  /* Chart: '<S941>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S943>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn,
    &AppSwcBcm_ARID_DEF.LogicalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet);
  if (AppSwcBcm_ARID_DEF.LogicalOperator) {
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* Logic: '<S941>/Logical Operator5' incorporates:
   *  Constant: '<S941>/Constant3'
   *  Constant: '<S941>/Constant4'
   *  Constant: '<S941>/Constant5'
   *  RelationalOperator: '<S941>/Relational Operator3'
   *  RelationalOperator: '<S941>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 0) ||
      (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3)) {
    if (AppSwcBcm_ARID_DEF.Cnt <= WakeUpCtl_WinCtlDelayTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt + 1;
      if (AppSwcBcm_ARID_DEF.Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt = (uint16)tmp;
      rtb_LIB_blOut_jr = false;
    } else {
      rtb_LIB_blOut_jr = true;
    }
  } else {
    rtb_LIB_blOut_jr = true;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* End of Logic: '<S941>/Logical Operator5' */

  /* Chart: '<S941>/LIB_NegPluse2' incorporates:
   *  Constant: '<S941>/Constant'
   *  Constant: '<S941>/Constant19'
   *  Constant: '<S941>/Constant22'
   *  Logic: '<S941>/Logical Operator'
   *  Logic: '<S941>/Logical Operator1'
   *  Logic: '<S941>/Logical Operator3'
   *  RelationalOperator: '<S941>/Relational Operator'
   *  RelationalOperator: '<S941>/Relational Operator1'
   *  RelationalOperator: '<S941>/Relational Operator15'
   *  RelationalOperator: '<S941>/Relational Operator16'
   *  RelationalOperator: '<S941>/Relational Operator17'
   *  RelationalOperator: '<S941>/Relational Operator18'
   *  RelationalOperator: '<S941>/Relational Operator19'
   *  RelationalOperator: '<S941>/Relational Operator2'
   *  RelationalOperator: '<S941>/Relational Operator20'
   *  RelationalOperator: '<S941>/Relational Operator21'
   */
  AppSwcBcm_LIB_PosPluse2((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.PosLampSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.LowBeamSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.HiBeamSta) &&
    (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 2) && rtb_LIB_blOut_jr &&
    ((!AppSwcBcm_ARID_DEF.BusCreator4.AutoLckSta) ||
     AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.HazardLightSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.EmerHazardLightSta),
    WakeUpCtl_CANSleepDelayTim_C, AppSwcBcm_ARID_DEF.Lib_blIn, &rtb_LIB_blOut_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse2);

  /* Logic: '<S941>/Logical Operator2' incorporates:
   *  Logic: '<S941>/Logical Operator11'
   *  Logic: '<S941>/Logical Operator12'
   *  Logic: '<S941>/Logical Operator4'
   */
  rtb_RelationalOperator26 = ((rtb_RelationalOperator26 &&
    AppSwcBcm_ARID_DEF.DataTypeConversion3) ||
    AppSwcBcm_ARID_DEF.DataTypeConversion2 ||
    AppSwcBcm_ARID_DEF.DataTypeConversion1 ||
    AppSwcBcm_ARID_DEF.DataTypeConversion ||
    AppSwcBcm_ARID_DEF.RelationalOperator7 ||
    AppSwcBcm_ARID_DEF.RelationalOperator8 ||
    AppSwcBcm_ARID_DEF.RelationalOperator4 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator9 && rtb_RelationalOperator27) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator10 && rtb_RelationalOperator28) ||
    AppSwcBcm_ARID_DEF.RelationalOperator12);

  /* Switch: '<S954>/Switch' */
  if (rtb_LIB_blOut_o) {
    /* Switch: '<S954>/Switch' incorporates:
     *  Constant: '<S954>/Constant'
     */
    WakeUpCtl_NMReq = false;
  } else {
    /* Switch: '<S954>/Switch' incorporates:
     *  Logic: '<S941>/Logical Operator8'
     *  Logic: '<S950>/Logical Operator'
     *  Logic: '<S950>/Logical Operator1'
     *  Logic: '<S954>/Logical Operator'
     *  UnitDelay: '<S950>/Unit Delay'
     *  UnitDelay: '<S954>/Unit Delay'
     */
    WakeUpCtl_NMReq = ((rtb_RelationalOperator26 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d3)) ||
                       AppSwcBcm_ARID_DEF.Lib_blIn || WakeUpCtl_NMReq);
  }

  /* End of Switch: '<S954>/Switch' */

  /* Update for Delay: '<S945>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_f =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S946>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_o =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

  /* Update for Delay: '<S947>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_bd =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S948>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_br =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

  /* Update for Delay: '<S949>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_gt =
    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

  /* Update for UnitDelay: '<S951>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a5 =
    AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw;

  /* Update for UnitDelay: '<S952>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ly = rtb_LogicalOperator6_et;

  /* Update for UnitDelay: '<S953>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ey = rtb_LogicalOperator7_kh;

  /* Update for UnitDelay: '<S950>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d3 = rtb_RelationalOperator26;
}

/* System initialize for atomic system: '<S940>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;

  /* InitializeConditions for Delay: '<S960>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad = true;

  /* SystemInitialize for Chart: '<S942>/LIB_NegPluse1' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_k);
}

/* Outputs for atomic system: '<S940>/SleepCtl' */
static void AppSwcBcm_SleepCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_ao;

  /* RelationalOperator: '<S942>/Relational Operator29' incorporates:
   *  Constant: '<S942>/Constant31'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator29 = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S942>/Relational Operator30' incorporates:
   *  Constant: '<S942>/Constant32'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator30 = (AppSwcBcm_ARID_DEF.CCaller40 == 1);

  /* Delay: '<S960>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.icLoad) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;
  }

  /* Logic: '<S963>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S960>/Logical Operator1'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl;

  /* Logic: '<S962>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Delay: '<S960>/Delay'
   *  Logic: '<S960>/Logical Operator3'
   *  Logic: '<S960>/Logical Operator4'
   */
  rtb_LogicalOperator_ao = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl && (!AppSwcBcm_ARID_DEF.Delay_DSTATE_b));

  /* Logic: '<S942>/Logical Operator13' incorporates:
   *  Delay: '<S960>/Delay'
   *  Logic: '<S960>/Logical Operator2'
   *  Logic: '<S960>/Logical Operator5'
   *  Logic: '<S962>/Logical Operator'
   *  Logic: '<S962>/Logical Operator1'
   *  Logic: '<S963>/Logical Operator'
   *  Logic: '<S963>/Logical Operator1'
   *  Logic: '<S964>/Logical Operator'
   *  Logic: '<S964>/Logical Operator1'
   *  Logic: '<S965>/Logical Operator'
   *  Logic: '<S965>/Logical Operator1'
   *  UnitDelay: '<S962>/Unit Delay'
   *  UnitDelay: '<S963>/Unit Delay'
   *  UnitDelay: '<S964>/Unit Delay'
   *  UnitDelay: '<S965>/Unit Delay'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator29 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_em)) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator30 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kz)) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_b && rtb_LogicalOperator) ||
     rtb_LogicalOperator_ao) || (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cl)) ||
    (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du)));

  /* Chart: '<S942>/LIB_NegPluse1' incorporates:
   *  Constant: '<S942>/Constant27'
   *  Logic: '<S942>/Logical Operator4'
   *  RelationalOperator: '<S942>/Relational Operator23'
   *  RelationalOperator: '<S942>/Relational Operator24'
   *  RelationalOperator: '<S942>/Relational Operator25'
   */
  AppSwcBcm_LIB_PosPluse2((!WakeUpCtl_NMReq) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.BoxLampSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr), WakeUpCtl_LocalSleepDelayTim_C,
    rtb_LogicalOperator, &rtb_LIB_blOut_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse1);

  /* Logic: '<S942>/Logical Operator3' */
  AppSwcBcm_ARID_DEF.LogicalOperator3 = (AppSwcBcm_ARID_DEF.DataTypeConversion3 ||
    AppSwcBcm_ARID_DEF.DataTypeConversion2 ||
    AppSwcBcm_ARID_DEF.DataTypeConversion1 ||
    AppSwcBcm_ARID_DEF.DataTypeConversion ||
    AppSwcBcm_ARID_DEF.RelationalOperator7 ||
    AppSwcBcm_ARID_DEF.RelationalOperator8 ||
    AppSwcBcm_ARID_DEF.RelationalOperator4 ||
    AppSwcBcm_ARID_DEF.RelationalOperator9 ||
    AppSwcBcm_ARID_DEF.RelationalOperator10 ||
    AppSwcBcm_ARID_DEF.RelationalOperator22 ||
    AppSwcBcm_ARID_DEF.RelationalOperator12);

  /* Switch: '<S966>/Switch' incorporates:
   *  Constant: '<S966>/Constant'
   *  Logic: '<S942>/Logical Operator14'
   *  Logic: '<S961>/Logical Operator'
   *  Logic: '<S961>/Logical Operator1'
   *  Logic: '<S966>/Logical Operator'
   *  UnitDelay: '<S961>/Unit Delay'
   *  UnitDelay: '<S966>/Unit Delay'
   */
  if (rtb_LIB_blOut_k) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1 = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1 =
      ((AppSwcBcm_ARID_DEF.LogicalOperator3 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_an)) || rtb_LogicalOperator ||
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1);
  }

  /* End of Switch: '<S966>/Switch' */

  /* Logic: '<S942>/Logical Operator5' incorporates:
   *  UnitDelay: '<S966>/Unit Delay'
   */
  WakeUpCtl_SleepAllwd = !AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1;
}

/* Update for atomic system: '<S940>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Update(void)
{
  /* Update for UnitDelay: '<S964>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_em =
    AppSwcBcm_ARID_DEF.RelationalOperator29;

  /* Update for UnitDelay: '<S965>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kz =
    AppSwcBcm_ARID_DEF.RelationalOperator30;

  /* Update for Delay: '<S960>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.icLoad = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;

  /* Update for UnitDelay: '<S962>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cl =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw;

  /* Update for UnitDelay: '<S963>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du =
    AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw;

  /* Update for UnitDelay: '<S961>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_an = AppSwcBcm_ARID_DEF.LogicalOperator3;
}

/* System initialize for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S940>/NMCtl' */
  AppSwcBcm_NMCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S940>/NMCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S940>/SleepCtl' */
  AppSwcBcm_SleepCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S940>/SleepCtl' */
}

/* Outputs for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl(void)
{
  /* SignalConversion: '<S413>/Signal Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  BSW_WakeupReas = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VBSW_WakeupReasn_enum;

  /* RelationalOperator: '<S940>/Relational Operator14' incorporates:
   *  Constant: '<S940>/Constant14'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion3 = (BSW_WakeupReas == 49);

  /* RelationalOperator: '<S940>/Relational Operator1' incorporates:
   *  Constant: '<S940>/Constant1'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion2 = (BSW_WakeupReas == 54);

  /* RelationalOperator: '<S940>/Relational Operator5' incorporates:
   *  Constant: '<S940>/Constant5'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion1 = (BSW_WakeupReas == 58);

  /* RelationalOperator: '<S940>/Relational Operator6' incorporates:
   *  Constant: '<S940>/Constant6'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion = (BSW_WakeupReas == 59);

  /* RelationalOperator: '<S940>/Relational Operator7' incorporates:
   *  Constant: '<S940>/Constant7'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator7 = (BSW_WakeupReas == 61);

  /* RelationalOperator: '<S940>/Relational Operator8' incorporates:
   *  Constant: '<S940>/Constant8'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8 = (BSW_WakeupReas == 62);

  /* RelationalOperator: '<S940>/Relational Operator4' incorporates:
   *  Constant: '<S940>/Constant4'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4 = (BSW_WakeupReas == 57);

  /* RelationalOperator: '<S940>/Relational Operator9' incorporates:
   *  Constant: '<S940>/Constant9'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9 = (BSW_WakeupReas == 63);

  /* RelationalOperator: '<S940>/Relational Operator10' incorporates:
   *  Constant: '<S940>/Constant10'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator10 = (BSW_WakeupReas == 64);

  /* RelationalOperator: '<S940>/Relational Operator13' incorporates:
   *  Constant: '<S940>/Constant13'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 17);

  /* Outputs for Atomic SubSystem: '<S940>/NMCtl' */
  AppSwcBcm_NMCtl();

  /* End of Outputs for SubSystem: '<S940>/NMCtl' */

  /* RelationalOperator: '<S940>/Relational Operator12' incorporates:
   *  Constant: '<S940>/Constant12'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 66);

  /* RelationalOperator: '<S940>/Relational Operator22' incorporates:
   *  Constant: '<S940>/Constant23'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator22 = (BSW_WakeupReas == 50);

  /* Outputs for Atomic SubSystem: '<S940>/SleepCtl' */
  AppSwcBcm_SleepCtl();

  /* End of Outputs for SubSystem: '<S940>/SleepCtl' */
}

/* Update for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S940>/SleepCtl' */
  AppSwcBcm_SleepCtl_Update();

  /* End of Update for SubSystem: '<S940>/SleepCtl' */
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
  DT_IPM_CCP_PanelStatus_BOD rtb_IPM_CCP_PanelStatus_BOD;
  DT_IPM_ESC_7_FuncStatus_CHA rtb_IPM_ESC_7_FuncStatus_CHA;
  sint32 i;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.BatSaveCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.ESCLCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.IMMOCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IMMOCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.RVMCtl_Bus = *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.SeatCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_SeatCtl_Bus();

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
  AppSwcBcm_ARID_DEF.BusCreator12.SysPwrMode = EEReadCtl_SysPwrMode;
  AppSwcBcm_ARID_DEF.BusCreator12.StartReq = EEReadCtl_StartReq;

  /* End of BusCreator: '<S3>/Bus Creator12' */

  /* CCaller: '<S3>/C Caller31' */
  BSW_J319HornSw = GetHw_AlrmHornSw();

  /* SignalConversion generated from: '<S3>/IPM_HU_B_BAC' incorporates:
   *  Inport: '<Root>/IPM_HU_B_BAC'
   */
  AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC();

  /* SignalConversion generated from: '<S3>/Vcu2BcmTms_outputs' incorporates:
   *  Inport: '<Root>/Vcu2BcmTms_outputs'
   */
  AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs();

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

  /* SignalConversion generated from: '<S3>/IPM_SCS_LeSwitchSts_BOD' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
    ();

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

  /* SignalConversion generated from: '<S3>/IPM_CCP_PanelStatus_BOD' incorporates:
   *  Inport: '<Root>/IPM_CCP_PanelStatus_BOD'
   */
  rtb_IPM_CCP_PanelStatus_BOD =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
    ();

  /* SignalConversion generated from: '<S3>/IPM_ESC_7_FuncStatus_CHA' incorporates:
   *  Inport: '<Root>/IPM_ESC_7_FuncStatus_CHA'
   */
  rtb_IPM_ESC_7_FuncStatus_CHA =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
    ();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator9);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' incorporates:
   *  SignalConversion generated from: '<S3>/Vcu2BcmTms_outputs'
   */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs
    (&AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD
    (&rtb_IPM_CCP_PanelStatus_BOD);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC
    (&AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator12);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD
    (&AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA
    (&rtb_IPM_ESC_7_FuncStatus_CHA);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus(&AppSwcBcm_ARID_DEF.BusCreator6);

  /* Outport: '<Root>/Bcm2OpmBAC_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m);

  /* Outport: '<Root>/Bcm2OpmEPT_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmEPT_outputs_Bcm2OpmEPT_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmEPT_outputs_c);

  /* Outport: '<Root>/Bcm2OpmOBD_outputs' incorporates:
   *  BusCreator: '<S267>/Bus Creator3'
   */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmOBD_outputs_Bcm2OpmOBD_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k);

  /* Outport: '<Root>/Bcm2VcuTms_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c);

  /* Outport: '<Root>/Sig_Cmd_DrlLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_DrlLightReq_Sig_Cmd_DrlLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_f);

  /* Outport: '<Root>/Sig_Cmd_PosLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_PosLightReq_Sig_Cmd_PosLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_c);

  /* Outport: '<Root>/Sig_Cmd_TiLeLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiLeLightReq_Sig_Cmd_TiLeLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_p);

  /* Outport: '<Root>/Sig_Cmd_TiRiLightReq' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiRiLightReq_Sig_Cmd_TiRiLightReq
    (AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_g);

  /* Outport: '<Root>/Sig_Cmd_TiWngFBSt' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Sig_Cmd_TiWngFBSt_Sig_Cmd_TiWngFBSt
    (AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_b);
}

/* Model step function for TID3 */
void Runbl_AppSwcBcm_50ms(void)        /* Explicit Task: Runbl_AppSwcBcm_50ms */
{
  DynDID rtb_BusCreator;
  ESCLCtl rtb_BusCreator3;
  WakeUpCtl rtb_BusCreator15;
  sint32 i;
  uint8 rtb_CCaller11;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.EEReadCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_SCS_LeSwitchSts_BOD();

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_50ms'
   */
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
    AppSwcBcm_ARID_DEF.LogicalOperator_gy;
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

  /* UnitDelay: '<S4>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4 = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE;

  /* Outputs for Atomic SubSystem: '<S4>/AlmSysCtl' */
  AppSwcBcm_AlmSysCtl();

  /* End of Outputs for SubSystem: '<S4>/AlmSysCtl' */

  /* BusCreator: '<S4>/Bus Creator2' */
  AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts = AlmSysCtl_BodyWarnSts;
  AppSwcBcm_ARID_DEF.BusCreator2.AlrmWarnTimOut = AlmSysCtl_AlrmWarnTimOut;

  /* CCaller: '<S4>/C Caller9' */
  AppSwcBcm_ARID_DEF.Switch_k = GetHw_KL15A();

  /* CCaller: '<S4>/C Caller10' */
  AppSwcBcm_ARID_DEF.CCaller35 = GetHw_KL15B();

  /* CCaller: '<S4>/C Caller8' */
  AppSwcBcm_ARID_DEF.CCaller40 = Get_EcuResetStatus();

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

  /* CCaller: '<S4>/C Caller15' */
  BSW_CrashPWMSta = GetHw_CrashSig_Flag();

  /* CCaller: '<S4>/C Caller3' */
  BSW_FogLampFCfg = GetVehCfg_FrontFogLamp();

  /* CCaller: '<S4>/C Caller30' */
  BSW_J125LightIntst = GetHw_Lightlntst();

  /* CCaller: '<S4>/C Caller7' */
  BSW_J313BrakeLoSw = GetHw_BrkSwLo();

  /* CCaller: '<S4>/C Caller4' */
  BSW_J322FogLampF = GetHw_FrontFogLampSw();

  /* CCaller: '<S4>/C Caller33' */
  BSW_J339BrakeHiSw = GetHw_BrkSwHi();

  /* CCaller: '<S4>/C Caller13' */
  BSW_J346FogLampR = GetHw_RearFogLampSw();

  /* CCaller: '<S4>/C Caller32' */
  BSW_RKEReq = GetFobKeyCmdRequest();

  /* Outputs for Atomic SubSystem: '<S4>/LampCtl' */
  AppSwcBcm_LampCtl();

  /* End of Outputs for SubSystem: '<S4>/LampCtl' */

  /* Outputs for Atomic SubSystem: '<S4>/BatSaveCtl' */
  AppSwcBcm_BatSaveCtl();

  /* End of Outputs for SubSystem: '<S4>/BatSaveCtl' */

  /* CCaller: '<S4>/C Caller36' */
  AppSwcBcm_ARID_DEF.CCaller40 = GetHw_KL15A();

  /* CCaller: '<S4>/C Caller35' */
  AppSwcBcm_ARID_DEF.CCaller35 = GetHw_KL15B();

  /* BusCreator: '<S4>/Bus Creator8' */
  AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr = BatSaveCtl_J64SavePwr;

  /* BusCreator: '<S4>/Bus Creator5' */
  AppSwcBcm_ARID_DEF.BusCreator5.PosLampSw = LampCtl_PosLampSw;
  AppSwcBcm_ARID_DEF.BusCreator5.LowBeamSw = LampCtl_LowBeamSw;
  AppSwcBcm_ARID_DEF.BusCreator5.HiBeamSw = LampCtl_HiBeamSw;
  AppSwcBcm_ARID_DEF.BusCreator5.PassLightSw = LampCtl_PassLightSw;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLSw = LampCtl_TurnIndcrLSw;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLaneLSw = LampCtl_TurnIndcrLaneLSw;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrRSw = LampCtl_TurnIndcrRSw;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLaneRSw = LampCtl_TurnIndcrLaneRSw;
  AppSwcBcm_ARID_DEF.BusCreator5.FogLampRSw = LampCtl_FogLampRSw;
  AppSwcBcm_ARID_DEF.BusCreator5.HazardLightSw = LampCtl_HazardLightSw;
  AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw = LampCtl_BrakeLightSw;
  AppSwcBcm_ARID_DEF.BusCreator5.LightIntstVal = LampCtl_LightIntstVal;
  AppSwcBcm_ARID_DEF.BusCreator5.AutoLampSw = LampCtl_AutoLampSw;
  AppSwcBcm_ARID_DEF.BusCreator5.PosLampSta = LampCtl_PosLampSta;
  AppSwcBcm_ARID_DEF.BusCreator5.DayRunLightSta = LampCtl_DayRunLightSta;
  AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSta = LampCtl_BrakeLightSta;
  AppSwcBcm_ARID_DEF.BusCreator5.BSDRightCtl = LampCtl_J420BSDRightCtl;
  AppSwcBcm_ARID_DEF.BusCreator5.BSDLeftCtl = LampCtl_J422BSDLeftCtl;
  AppSwcBcm_ARID_DEF.BusCreator5.LowBeamSta = LampCtl_LowBeamSta;
  AppSwcBcm_ARID_DEF.BusCreator5.FogLampRSta = LampCtl_FogLampRSta;
  AppSwcBcm_ARID_DEF.BusCreator5.ReverseLampSta = LampCtl_ReverseLampSta;
  AppSwcBcm_ARID_DEF.BusCreator5.LightIntstSta = LampCtl_LightIntstSta;
  AppSwcBcm_ARID_DEF.BusCreator5.HiBeamSta = LampCtl_HiBeamSta;
  AppSwcBcm_ARID_DEF.BusCreator5.DomeLampPwmDuty = LampCtl_DomeLampPwmDuty;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrRSta = LampCtl_TurnIndcrRSta;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLSta = LampCtl_TurnIndcrLSta;
  AppSwcBcm_ARID_DEF.BusCreator5.VehSeekSta = LampCtl_VehSeekSta;
  AppSwcBcm_ARID_DEF.BusCreator5.ThermalrunawaySta = LampCtl_ThermalrunawaySta;
  AppSwcBcm_ARID_DEF.BusCreator5.EmerSta = LampCtl_EmerSta;
  AppSwcBcm_ARID_DEF.BusCreator5.ArmedSta = LampCtl_ArmedSta;
  AppSwcBcm_ARID_DEF.BusCreator5.CrashSta = LampCtl_CrashSta;
  AppSwcBcm_ARID_DEF.BusCreator5.DisarmedSta = LampCtl_DisarmedSta;
  AppSwcBcm_ARID_DEF.BusCreator5.PartArmedSta = LampCtl_PartArmedSta;
  AppSwcBcm_ARID_DEF.BusCreator5.AlrmSta = LampCtl_AlrmSta;
  AppSwcBcm_ARID_DEF.BusCreator5.EmerHazardLightSta = LampCtl_EmerHazardLightSta;
  AppSwcBcm_ARID_DEF.BusCreator5.HazardLightSta = LampCtl_HazardLightSta;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrMod = LampCtl_TurnIndcrMod;
  AppSwcBcm_ARID_DEF.BusCreator5.PassLightSta = LampCtl_PassLightSta;
  AppSwcBcm_ARID_DEF.BusCreator5.AutoLampSta = LampCtl_AutoLampSta;
  AppSwcBcm_ARID_DEF.BusCreator5.BoxLampSta = LampCtl_J449BoxLamp;
  AppSwcBcm_ARID_DEF.BusCreator5.WelcomeLampSta = LampCtl_WelcomeLampSta;
  AppSwcBcm_ARID_DEF.BusCreator5.FlwrMeHomeSta = LampCtl_FlwrMeHomeSta;
  AppSwcBcm_ARID_DEF.BusCreator5.FlwrMeHomeCtlFb = LampCtl_FlwrMeHomeCtlFb;
  AppSwcBcm_ARID_DEF.BusCreator5.FlwrMeHomeTim = LampCtl_FlwrMeHomeTim;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLOpen = LampCtl_TurnIndcrLOpen;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrLShort = LampCtl_TurnIndcrLShort;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrROpen = LampCtl_TurnIndcrROpen;
  AppSwcBcm_ARID_DEF.BusCreator5.TurnIndcrRShort = LampCtl_TurnIndcrRShort;
  AppSwcBcm_ARID_DEF.BusCreator5.RKEReq = LampCtl_RKEReq;
  AppSwcBcm_ARID_DEF.BusCreator5.KnobBeamFaultSta = LampCtl_KnobBeamFaultSta;
  AppSwcBcm_ARID_DEF.BusCreator5.RodBeamFaultSta = LampCtl_RodBeamFaultSta;
  AppSwcBcm_ARID_DEF.BusCreator5.BackLadjvalFb = LampCtl_BackLadjvalFb;
  AppSwcBcm_ARID_DEF.BusCreator5.J408BackLampPWM = LampCtl_J408BackLampPWM;
  AppSwcBcm_ARID_DEF.BusCreator5.FogLampFSw = LampCtl_FogLampFSw;
  AppSwcBcm_ARID_DEF.BusCreator5.FogLampFSta = LampCtl_FogLampFSta;
  AppSwcBcm_ARID_DEF.BusCreator5.LampDelay = LampCtl_LampDelay;
  AppSwcBcm_ARID_DEF.BusCreator5.AntiLckSta = LampCtl_AntiLckSta;
  AppSwcBcm_ARID_DEF.BusCreator5.TrunkWarnSta = LampCtl_TrunkWarnSta;
  AppSwcBcm_ARID_DEF.BusCreator5.LowBeamShortToBat = LampCtl_LowBeamShortToBat;
  AppSwcBcm_ARID_DEF.BusCreator5.HiBeamShortToBat = LampCtl_HiBeamShortToBat;
  AppSwcBcm_ARID_DEF.BusCreator5.VehSeekStaFb = LampCtl_VehSeekStaFb;

  /* Outputs for Atomic SubSystem: '<S4>/WakeUpCtl' */
  AppSwcBcm_WakeUpCtl();

  /* End of Outputs for SubSystem: '<S4>/WakeUpCtl' */

  /* CCaller: '<S4>/C Caller11' incorporates:
   *  CCaller: '<S4>/C Caller39'
   */
  rtb_CCaller11 = GetHw_KL15A();

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  AppSwcBcm_ARID_DEF.DataTypeConversion = (rtb_CCaller11 != 0);

  /* CCaller: '<S4>/C Caller11' */
  rtb_CCaller11 = GetHw_KL15B();

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  AppSwcBcm_ARID_DEF.DataTypeConversion1 = (rtb_CCaller11 != 0);

  /* CCaller: '<S4>/C Caller40' */
  AppSwcBcm_ARID_DEF.CCaller40 = GetHw_WiprStopPstnDtct();

  /* DataTypeConversion: '<S4>/Data Type Conversion2' */
  AppSwcBcm_ARID_DEF.DataTypeConversion2 =
    (AppSwcBcm_ARID_DEF.BusCreator5.DomeLampPwmDuty != 0);

  /* DataTypeConversion: '<S4>/Data Type Conversion3' */
  AppSwcBcm_ARID_DEF.DataTypeConversion3 =
    (AppSwcBcm_ARID_DEF.BusCreator5.J408BackLampPWM != 0);

  /* Outputs for Atomic SubSystem: '<S4>/DynDID' */
  AppSwcBcm_DynDID();

  /* End of Outputs for SubSystem: '<S4>/DynDID' */

  /* BusCreator: '<S4>/Bus Creator' incorporates:
   *  UnitDelay: '<S576>/Unit Delay'
   */
  rtb_BusCreator.DynDID_0xF22CAntitheftSta = DynDID_0xF22CAntitheftSta;
  for (i = 0; i < 10; i++) {
    rtb_BusCreator.DynDID_0xF230DoorOpRecord[i] = DynDID_0xF230DoorOpRecord[i];
    rtb_BusCreator.DynDID_0xF231TrunkOpRecord[i] = DynDID_0xF231TrunkOpRecord[i];
  }

  for (i = 0; i < 23; i++) {
    rtb_BusCreator.DynDID_0xF234ADSampleValue[i] = DynDID_0xF234ADSampleValue[i];
  }

  for (i = 0; i < 10; i++) {
    rtb_BusCreator.DynDID_0xF232LocalStartUpFailRecord[i] =
      DynDID_0xF232LocalStartUpFailRecord[i];
    rtb_BusCreator.DynDID_0xF233RemoteStartUpFailRecord[i] =
      DynDID_0xF233RemoteStartUpFailRecord[i];
  }

  rtb_BusCreator.DynDID_0xF237PwrModeSta = DynDID_0xF237PwrModeSta;
  for (i = 0; i < 5; i++) {
    rtb_BusCreator.DynDID_0xF236DigtOutSampleValue[i] =
      DynDID_0xF236DigtOutSampleValue[i];
    rtb_BusCreator.DynDID_0xF235DigtInSampleValue[i] =
      DynDID_0xF235DigtInSampleValue[i];
  }

  rtb_BusCreator.DynDID_DoorOpRecord = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j;

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

  /* Update for UnitDelay: '<S4>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a =
    AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts;

  /* Update for UnitDelay: '<S4>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_c =
    AppSwcBcm_ARID_DEF.BusCreator5.CrashSta;

  /* Update for UnitDelay: '<S4>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE = AppSwcBcm_ARID_DEF.BusCreator5.RKEReq;

  /* Update for UnitDelay: '<S4>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_g =
    AppSwcBcm_ARID_DEF.BusCreator5.ThermalrunawaySta;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* Update for UnitDelay: '<S4>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_j =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode;

  /* Update for Atomic SubSystem: '<S4>/DoorLckCtl' */
  AppSwcBcm_DoorLckCtl_Update();

  /* End of Update for SubSystem: '<S4>/DoorLckCtl' */

  /* Update for UnitDelay: '<S4>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k =
    AppSwcBcm_ARID_DEF.BusCreator1.IGRlyIIgCls;

  /* Update for UnitDelay: '<S4>/Unit Delay4' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* Update for UnitDelay: '<S4>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i =
    AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw;

  /* Update for UnitDelay: '<S4>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_j =
    AppSwcBcm_ARID_DEF.BusCreator5.HazardLightSw;

  /* Update for Atomic SubSystem: '<S4>/LampCtl' */
  AppSwcBcm_LampCtl_Update();

  /* End of Update for SubSystem: '<S4>/LampCtl' */

  /* Update for Atomic SubSystem: '<S4>/WakeUpCtl' */
  AppSwcBcm_WakeUpCtl_Update();

  /* End of Update for SubSystem: '<S4>/WakeUpCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator2);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator4);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DynDID_Bus(&rtb_BusCreator);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_LampCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator5);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(&AppSwcBcm_ARID_DEF.BusCreator1);

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
  RVMCtl rtb_BusCreator7;
  SeatCtl rtb_BusCreator11;
  SteerWhlCtl rtb_BusCreator13;
  WinCtl rtb_BusCreator5;

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

  /* Outputs for Atomic SubSystem: '<S1>/IODID' */
  AppSwcBcm_IODID();

  /* End of Outputs for SubSystem: '<S1>/IODID' */

  /* BusCreator: '<S1>/Bus Creator16' */
  AppSwcBcm_ARID_DEF.BusCreator16.TurnIndcrLCtlFlg = IODID_TurnIndcrLCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.TurnIndcrRCtlFlg = IODID_TurnIndcrRCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.BackLampCtlFlg = IODID_BackLampCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.BrakeLightCtlFlg = IODID_BrakeLightCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.ReverseLampCtlFlg = IODID_ReverseLampCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.DayRunLightCtlFlg = IODID_DayRunLightCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.PosLampCtlFlg = IODID_PosLampCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.DomeLampCtlFlg = IODID_DomeLampCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.LowBeamCtlFlg = IODID_LowBeamCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.HiBeamCtlFlg = IODID_HiBeamCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.FogLampFCtlFlg = IODID_FogLampFCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.FogLampRCtlFlg = IODID_FogLampRCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.TrunkUnlckCtlFlg = IODID_TrunkUnlckCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.DoorUnlckCtlFlg = IODID_DoorUnlckCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.DoorLlckCtlFlg = IODID_DoorLckCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.WiperHiSpdCtlFlg = IODID_WiperHiSpdCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.WiperLowSpdCtlFlg = IODID_WiperLowSpdCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.WinFRCloselFlg = IODID_WinFRCloseFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.WinFROpenFlg = IODID_WinFROpenFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.IG1RlyCtlFlg = IODID_IG1RlyCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.IG2RlyCtlFlg = IODID_IG2RlyCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.HornCtlFlg = IODID_HornCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.BatSaveCtlFlg = IODID_BatSaveCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.BSDRightCtlFlg = IODID_BSDRightCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.BSDLeftCtlFlg = IODID_BSDLeftCtlFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.WinFLCloselFlg = IODID_WinFLCloseFlg;
  AppSwcBcm_ARID_DEF.BusCreator16.WinFLOpenFlg = IODID_WinFLOpenFlg;

  /* Outputs for Atomic SubSystem: '<S1>/WinCtl' */
  AppSwcBcm_WinCtl();

  /* End of Outputs for SubSystem: '<S1>/WinCtl' */

  /* Outputs for Atomic SubSystem: '<S1>/RVMCtl' */
  AppSwcBcm_RVMCtl();

  /* End of Outputs for SubSystem: '<S1>/RVMCtl' */

  /* Outputs for Atomic SubSystem: '<S1>/DTCSet' */
  AppSwcBcm_DTCSet();

  /* End of Outputs for SubSystem: '<S1>/DTCSet' */

  /* Outputs for Atomic SubSystem: '<S1>/EEWriteCtl' */
  AppSwcBcm_EEWriteCtl();

  /* End of Outputs for SubSystem: '<S1>/EEWriteCtl' */

  /* CCaller: '<S1>/C Caller14' */
  BSW_CN744DrvSeatResis = GetHw_DrvSeatTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SeatCtl' */
  AppSwcBcm_SeatCtl();

  /* End of Outputs for SubSystem: '<S1>/SeatCtl' */

  /* BusCreator: '<S1>/Bus Creator11' */
  rtb_BusCreator11.MaiDrvSeatStFb = SeatCtl_MaiDrvSeatStFb;
  rtb_BusCreator11.CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWM;
  rtb_BusCreator11.DrvSeatTemp = SeatCtl_DrvSeatTemp;
  rtb_BusCreator11.DrvNTCShort = SeatCtl_DrvNTCShort;
  rtb_BusCreator11.DrvNTCOpen = SeatCtl_DrvNTCOpen;
  rtb_BusCreator11.RemtHeatFb = SeatCtl_RemtHeatFb;

  /* CCaller: '<S1>/C Caller34' */
  BSW_J134SteerWhlResis = GetHw_SteerWhlTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SteerWhlCtl' */
  AppSwcBcm_SteerWhlCtl();

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

  /* BusCreator: '<S1>/Bus Creator7' */
  rtb_BusCreator7.J42Heat = RVMCtl_J42Heat;

  /* Update for Atomic SubSystem: '<S1>/DTCSet' */
  AppSwcBcm_DTCSet_Update();

  /* End of Update for SubSystem: '<S1>/DTCSet' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus(&AppSwcBcm_ARID_DEF.BusCreator16);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_RVMCtl_Bus(&rtb_BusCreator7);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SeatCtl_Bus(&rtb_BusCreator11);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_SteerWhlCtl_Bus(&rtb_BusCreator13);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_WinCtl_Bus(&rtb_BusCreator5);
}

/* Model initialize function */
void AppSwcBcm_Init(void)
{
  {
    sint32 i;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_20ms'
     */
    /* SystemInitialize for Atomic SubSystem: '<S3>/BCMTx' */
    AppSwcBcm_BCMTx_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/BCMTx' */

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
    AppSwcBcm_ARID_DEF.BusCreator12.SysPwrMode = EEReadCtl_SysPwrMode;
    AppSwcBcm_ARID_DEF.BusCreator12.StartReq = EEReadCtl_StartReq;

    /* End of SystemInitialize for BusCreator: '<S3>/Bus Creator12' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/HornCtl' */
    AppSwcBcm_HornCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/HornCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/WiperCtl' */
    AppSwcBcm_WiperCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/WiperCtl' */
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

    /* SystemInitialize for Atomic SubSystem: '<S4>/LampCtl' */
    AppSwcBcm_LampCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/LampCtl' */

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
#pragma default_function_attributes =
/*
 * File trailer for generated code.
 *
 * [EOF]
 */
