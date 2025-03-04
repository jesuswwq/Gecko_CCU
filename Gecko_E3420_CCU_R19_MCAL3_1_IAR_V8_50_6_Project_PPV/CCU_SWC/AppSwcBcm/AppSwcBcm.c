/*
 * File: AppSwcBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1584
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Feb 28 11:17:19 2025
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

/* Named constants for Chart: '<S171>/Chart6' */
#define AppSwcBcm_IN_Off               ((uint8)1U)
#define AppSwcBcm_IN_On                ((uint8)2U)

/* Named constants for Chart: '<S145>/Chart' */
#define AppSwcBcm_IN_Off_f             ((uint8)1U)
#define AppSwcBcm_IN_On_c              ((uint8)2U)

/* Named constants for Chart: '<S145>/HeatFb' */
#define AppSwcBcm_IN_Fail              ((uint8)1U)
#define AppSwcBcm_IN_Init              ((uint8)2U)
#define AppSwcBcm_IN_Suc               ((uint8)3U)
#define AppSwcBcm_IN_Wait              ((uint8)4U)

/* Named constants for Chart: '<S153>/HeatCtl' */
#define AppSwcBcm_IN_Off_a             ((uint8)1U)
#define AppSwcBcm_IN_On_n              ((uint8)2U)

/* Named constants for Chart: '<S153>/HeatFb' */
#define AppSwcBcm_IN_Fail_f            ((uint8)1U)
#define AppSwcBcm_IN_Init_j            ((uint8)2U)
#define AppSwcBcm_IN_Suc_l             ((uint8)3U)
#define AppSwcBcm_IN_Wait_h            ((uint8)4U)

/* Named constants for Chart: '<S153>/HeatSet' */
#define AppSwcBcm_IN_OFF               ((uint8)1U)
#define AppSwcBcm_IN_ON                ((uint8)2U)

/* Named constants for Chart: '<S12>/DrvWinCtl' */
#define AppSwcBcm_IN_AutoDown          ((uint8)1U)
#define AppSwcBcm_IN_ManDown           ((uint8)2U)
#define AppSwcBcm_IN_ManUp             ((uint8)3U)
#define AppSwcBcm_IN_Standby           ((uint8)4U)

/* Named constants for Chart: '<S12>/PsgWinCtl' */
#define AppSwcBcm_IN_AutoDown_n        ((uint8)1U)
#define AppSwcBcm_IN_ManDown_h         ((uint8)2U)
#define AppSwcBcm_IN_ManUp_c           ((uint8)3U)
#define AppSwcBcm_IN_Standby_b         ((uint8)4U)

/* Named constants for Chart: '<S171>/Chart1' */
#define AppSwcBcm_IN_HoldOn            ((uint8)1U)
#define AppSwcBcm_IN_Off_d             ((uint8)2U)
#define AppSwcBcm_IN_On_i              ((uint8)3U)

/* Named constants for Chart: '<S171>/Chart11' */
#define AppSwcBcm_IN_Off_at            ((uint8)1U)
#define AppSwcBcm_IN_On_h              ((uint8)2U)

/* Named constants for Chart: '<S257>/Chart' */
#define AppSwcBcm_IN_FobidKey          ((uint8)1U)
#define AppSwcBcm_IN_Init_l            ((uint8)2U)
#define AppSwcBcm_IN_RelesKey          ((uint8)3U)

/* Named constants for Chart: '<S258>/Chart' */
#define AppSwcBcm_IN_Init_k            ((uint8)1U)
#define AppSwcBcm_IN_KeyNotInCar       ((uint8)2U)

/* Named constants for Chart: '<S258>/Chart3' */
#define AppSwcBcm_IN_Finish            ((uint8)1U)
#define AppSwcBcm_IN_KeyValid          ((uint8)3U)

/* Named constants for Chart: '<S259>/Chart' */
#define AppSwcBcm_IN_LSeekKeyOut       ((uint8)2U)
#define AppSwcBcm_IN_RSeekKeyOut       ((uint8)3U)

/* Named constants for Chart: '<S259>/Chart3' */
#define AppSwcBcm_IN_KeyValid_h        ((uint8)2U)

/* Named constants for Chart: '<S260>/Chart' */
#define AppSwcBcm_IN_PSSeekKeyOut      ((uint8)2U)

/* Named constants for Chart: '<S260>/Chart1' */
#define AppSwcBcm_IN_IMMOKeyValid      ((uint8)1U)
#define AppSwcBcm_IN_RemoteKeyValid    ((uint8)3U)

/* Named constants for Chart: '<S260>/Chart2' */
#define AppSwcBcm_IN_NokeyTimecount    ((uint8)2U)
#define AppSwcBcm_IN_SendKeyCloser     ((uint8)3U)
#define AppSwcBcm_IN_SendNOKey         ((uint8)4U)

/* Named constants for Chart: '<S261>/Chart' */
#define AppSwcBcm_IN_LockWlcm          ((uint8)2U)
#define AppSwcBcm_IN_UnlockDay0to7     ((uint8)3U)
#define AppSwcBcm_IN_UnlockExcedDay7   ((uint8)4U)
#define AppSwcBcm_IN_WlcmLockReq       ((uint8)5U)
#define AppSwcBcm_IN_WlcmUnlockReq     ((uint8)6U)

/* Named constants for Chart: '<S336>/Alarm' */
#define AppSwcBcm_IN_SetON             ((uint8)1U)
#define AppSwcBcm_IN_SetOff            ((uint8)2U)

/* Named constants for Chart: '<S344>/Seek' */
#define AppSwcBcm_IN_RKESetON          ((uint8)1U)
#define AppSwcBcm_IN_TboxSetON         ((uint8)3U)

/* Named constants for Chart: '<S345>/Chart1' */
#define AppSwcBcm_IN_SetOff_i          ((uint8)1U)
#define AppSwcBcm_IN_SetOn             ((uint8)2U)

/* Named constants for Chart: '<S378>/Chart' */
#define AppSwcBcm_IN_HiSpd             ((uint8)1U)
#define AppSwcBcm_IN_Inr               ((uint8)2U)
#define AppSwcBcm_IN_LowSpd            ((uint8)3U)
#define AppSwcBcm_IN_Maint             ((uint8)1U)
#define AppSwcBcm_IN_Mist              ((uint8)4U)
#define AppSwcBcm_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define AppSwcBcm_IN_Nrm               ((uint8)2U)
#define AppSwcBcm_IN_Off_d1            ((uint8)5U)
#define AppSwcBcm_IN_Wash              ((uint8)3U)

/* Named constants for Chart: '<S429>/AlmSysLogic' */
#define AppSwcBcm_IN_Alarm             ((uint8)1U)
#define AppSwcBcm_IN_Armed             ((uint8)2U)
#define AppSwcBcm_IN_Disarmed          ((uint8)3U)
#define AppSwcBcm_IN_Init_jx           ((uint8)4U)
#define AppSwcBcm_IN_PartArmed         ((uint8)5U)

/* Named constants for Chart: '<S431>/DoorDrv' */
#define AppSwcBcm_IN_DrvIdle           ((uint8)1U)
#define AppSwcBcm_IN_InsDrvLck         ((uint8)2U)
#define AppSwcBcm_IN_InsDrvUnlck       ((uint8)3U)
#define AppSwcBcm_IN_OsDrvLck          ((uint8)4U)
#define AppSwcBcm_IN_OsDrvUnlck        ((uint8)5U)
#define AppSwcBcm_IN_TrunkUnlck        ((uint8)6U)

/* Named constants for Chart: '<S484>/Chart2' */
#define AppSwcBcm_IN_Fail_k            ((uint8)1U)
#define AppSwcBcm_IN_Init_c            ((uint8)2U)
#define AppSwcBcm_IN_Suc_m             ((uint8)3U)
#define AppSwcBcm_IN_Trans             ((uint8)4U)

/* Named constants for Chart: '<S642>/AutoHiBeamCtl' */
#define AppSwcBcm_IN_Inhb              ((uint8)1U)
#define AppSwcBcm_IN_OFF_d             ((uint8)2U)
#define AppSwcBcm_IN_ON_d              ((uint8)3U)

/* Named constants for Chart: '<S649>/Chart' */
#define AppSwcBcm_IN_Off_i             ((uint8)1U)
#define AppSwcBcm_IN_On_p              ((uint8)2U)

/* Named constants for Chart: '<S653>/Chart' */
#define AppSwcBcm_IN_Day               ((uint8)1U)
#define AppSwcBcm_IN_Night             ((uint8)2U)

/* Named constants for Chart: '<S779>/Chart' */
#define AppSwcBcm_IN_NO_ACTIVE_CHILD_h ((uint8)0U)
#define AppSwcBcm_IN_SetOff_d          ((uint8)1U)
#define AppSwcBcm_IN_SetOn_j           ((uint8)2U)

/* Named constants for Chart: '<S780>/Chart' */
#define AppSwcBcm_IN_Off_n             ((uint8)1U)
#define AppSwcBcm_IN_On_ix             ((uint8)2U)

/* Named constants for Chart: '<S782>/Chart1' */
#define AppSwcBcm_IN_CrashOff          ((uint8)1U)
#define AppSwcBcm_IN_CrashOn           ((uint8)2U)
#define AppSwcBcm_IN_Init_l0           ((uint8)3U)

/* Named constants for Chart: '<S675>/HazardLightLogic' */
#define AppSwcBcm_IN_EmerON            ((uint8)1U)
#define AppSwcBcm_IN_OFF_g             ((uint8)2U)
#define AppSwcBcm_IN_ON_e              ((uint8)3U)

/* Named constants for Chart: '<S786>/Chart' */
#define AppSwcBcm_IN_SetOn1            ((uint8)2U)
#define AppSwcBcm_IN_SetOn2            ((uint8)3U)

/* Named constants for Chart: '<S790>/Chart' */
#define AppSwcBcm_IN_Delay             ((uint8)1U)
#define AppSwcBcm_IN_SetOff_k          ((uint8)2U)
#define AppSwcBcm_IN_SetOn_d           ((uint8)3U)

/* Named constants for Chart: '<S675>/TurnIndcrArb2' */
#define AppSwcBcm_IN_AntiLck           ((uint8)1U)
#define AppSwcBcm_IN_Armed_p           ((uint8)2U)
#define AppSwcBcm_IN_Disarmed_k        ((uint8)3U)
#define AppSwcBcm_IN_PartArmed_a       ((uint8)4U)
#define AppSwcBcm_IN_Pri1              ((uint8)1U)
#define AppSwcBcm_IN_Pri2              ((uint8)2U)
#define AppSwcBcm_IN_Pri3              ((uint8)3U)
#define AppSwcBcm_IN_Pri4              ((uint8)4U)
#define AppSwcBcm_IN_Pri5              ((uint8)5U)
#define AppSwcBcm_IN_RodBeam           ((uint8)5U)
#define AppSwcBcm_IN_Seek              ((uint8)6U)
#define AppSwcBcm_IN_Trans_m           ((uint8)6U)
#define AppSwcBcm_IN_Trans_mc          ((uint8)7U)
#define AppSwcBcm_IN_TrunkWarn         ((uint8)8U)
#define AppSwcBcm_IN_VehMode           ((uint8)9U)

/* Named constants for Chart: '<S675>/TurnIndcrLogic' */
#define AppSwcBcm_IN_LongFlash         ((uint8)1U)
#define AppSwcBcm_IN_OFF_m             ((uint8)1U)
#define AppSwcBcm_IN_ShortFlash        ((uint8)2U)
#define AppSwcBcm_IN_TurnL             ((uint8)2U)
#define AppSwcBcm_IN_TurnR             ((uint8)3U)

/* Named constants for Chart: '<S675>/TurnIndcrSelect' */
#define AppSwcBcm_IN_TurnLOn           ((uint8)2U)
#define AppSwcBcm_IN_TurnLROn          ((uint8)3U)
#define AppSwcBcm_IN_TurnROn           ((uint8)4U)

/* Named constants for Chart: '<S797>/Chart' */
#define AppSwcBcm_IN_Init_e            ((uint8)1U)
#define AppSwcBcm_IN_Limit             ((uint8)2U)
#define AppSwcBcm_IN_Nrm_g             ((uint8)3U)
#define AppSwcBcm_IN_Show              ((uint8)4U)

/* Named constants for Chart: '<S798>/Chart' */
#define AppSwcBcm_IN_RKESetOn          ((uint8)1U)
#define AppSwcBcm_IN_TboxSetOn         ((uint8)3U)

/* Named constants for Chart: '<S798>/SeekFb' */
#define AppSwcBcm_IN_Fail_a            ((uint8)1U)
#define AppSwcBcm_IN_Init_d            ((uint8)2U)
#define AppSwcBcm_IN_Suc_a             ((uint8)3U)
#define AppSwcBcm_IN_Wait_a            ((uint8)4U)

/* Named constants for Chart: '<S436>/Chart' */
#define AppSwcBcm_IN_LocalOn           ((uint8)1U)
#define AppSwcBcm_IN_OTA1On            ((uint8)2U)
#define AppSwcBcm_IN_OTAOn             ((uint8)3U)
#define AppSwcBcm_IN_PSOff             ((uint8)4U)
#define AppSwcBcm_IN_RemoteOn          ((uint8)5U)

/* Named constants for Chart: '<S918>/BrkPwrOn' */
#define AppSwcBcm_IN_Invalid           ((uint8)1U)
#define AppSwcBcm_IN_Valid             ((uint8)2U)

/* Named constants for Chart: '<S918>/RemoteLck' */
#define AppSwcBcm_IN_Init_jy           ((uint8)1U)
#define AppSwcBcm_IN_Lck               ((uint8)2U)
#define AppSwcBcm_IN_Unlck             ((uint8)3U)

/* Named constants for Chart: '<S436>/RemtPwrCtlFb' */
#define AppSwcBcm_IN_Fail_o            ((uint8)1U)
#define AppSwcBcm_IN_Init_h            ((uint8)2U)
#define AppSwcBcm_IN_Suc_i             ((uint8)3U)
#define AppSwcBcm_IN_Trans_mq          ((uint8)4U)

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S650>/Constant28' */

/* Invariant block signals (default storage) */
const ConstB_AppSwcBcm_T AppSwcBcm_ConstB = {
  0U,                                  /* '<S285>/Data Type Conversion39' */
  1,                                   /* '<S700>/Relational Operator' */
  1,                                   /* '<S701>/Relational Operator1' */
  1,                                   /* '<S514>/Relational Operator6' */
  1                                    /* '<S489>/Relational Operator1' */
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
static void AppSwcBcm_Lib_RiseEdgeDet_p(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_g_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
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
static uint16 AppSwcBcm_BitShift1_i(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u);
static void AppSwcBcm_NrmOffLib_RiseEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_NrmOffLib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_m_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_p(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_g_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_a(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_g_T *AppSwcBcm__ARID_DEF_arg);
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
static uint16 AppSwcBcm_BitShift12_d(uint16 rtu_u);
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
static boolean AppSwcBcm_Lib_FailEdgeDet_f(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_g_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_DTCSet_Update(void);
static void AppSwcBcm_DTCSet(void);
static void AppSwcBcm_EEWriteCtl(void);
static void AppSwcBcm_IODID(void);
static void AppSwcBcm_RVMCtl(void);
static void AppSwcBcm_SeatCtl(void);
static void AppSwcBcm_SteerWhlCtl(void);
static void AppSwcBcm_TboxTim(void);
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
static void AppSwcBcm_SpdLck_e_Const(void);
static void AppSwcBcm_TboxLckFb(void);
static void AppSwcBcm_DoorLckCtlLogic_Init(void);
static void AppSwcBcm_DoorLckCtlLogic_Const(void);
static void AppSwcBcm_DoorLckCtlLogic(void);
static void AppSwcBcm_SignalProcess_n_Const(void);
static void AppSwcBcm_SignalProcess_h(void);
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
static void AppSwcBcm_AutoHiBeamCtl(void);
static void AppSwcBcm_AutoLampCtl_Init(void);
static void AppSwcBcm_AutoLampCtl(void);
static void AppSwcBcm_BackLampCtl_Init(void);
static void AppSwcBcm_BackLampCtl(void);
static void AppSwcBcm_BoxLampCtl_Init(void);
static void AppSwcBcm_BoxLampCtl(void);
static void AppSwcBcm_BrakeLampCtl(void);
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
static void AppSwcBcm_ReverseLampCtl(void);
static void AppSwcBcm_PassLampFunc(void);
static void AppSwcBcm_PosLampCtl_Init(void);
static void AppSwcBcm_PosLampCtl(void);
static void AppSwcBcm_SignalProcess_p_Init(void);
static void AppSwcBcm_SignalProcess_n(void);
static void AppSwcBcm_TurnIndcrCtl_Init(void);
static void AppSwcBcm_TurnIndcrCtl(void);
static void AppSwcBcm_Lib_RiseEdgeDet_g(void);
static void AppSwcBcm_Lib_ChangeEdge_i_Update(void);
static void AppSwcBcm_Lib_ChangeEdge_f(void);
static void AppSwcBcm_WelcomeLampCtl_Init(void);
static void AppSwcBcm_WelcomeLampCtl_Update(void);
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
static void AppSwcBcm_TruthTable_o(void);
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
static void AppSwcBcm_InhbFunc(void);

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
  uint8 rtb_DataTypeConversion_iy;
  boolean rtb_RelationalOperator6;

  /* RelationalOperator: '<S5>/Relational Operator6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay6'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->BrkLampShortToBatOrOpen != AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_f);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900213' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S18>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->BrkLampShortToBatOrOpen;

    /* CCaller: '<S18>/C Caller' */
    App_Call_Event_DTC_0x900213_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900213' */

  /* CCaller: '<S5>/C Caller2' incorporates:
   *  CCaller: '<S5>/C Caller'
   *  Constant: '<S5>/Constant'
   */
  rtb_DataTypeConversion_iy = Get_DiagAnt_CV(2U);

  /* RelationalOperator: '<S5>/Relational Operator12' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (rtb_DataTypeConversion_iy == 1);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900923' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator8' incorporates:
   *  UnitDelay: '<S5>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.RelationalOperator12 !=
      AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_c) {
    /* CCaller: '<S21>/C Caller' incorporates:
     *  DataTypeConversion: '<S21>/Data Type Conversion'
     */
    App_Call_Event_DTC_0x900923_SetEventStatus
      (AppSwcBcm_ARID_DEF.RelationalOperator12);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator8' */
  /* End of Outputs for SubSystem: '<S5>/DTC0x900923' */

  /* RelationalOperator: '<S5>/Relational Operator13' incorporates:
   *  Constant: '<S5>/Constant2'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator13 = (rtb_DataTypeConversion_iy == 2);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900924' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator9' incorporates:
   *  UnitDelay: '<S5>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.RelationalOperator13 !=
      AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_k) {
    /* CCaller: '<S22>/C Caller' incorporates:
     *  DataTypeConversion: '<S22>/Data Type Conversion'
     */
    App_Call_Event_DTC_0x900924_SetEventStatus
      (AppSwcBcm_ARID_DEF.RelationalOperator13);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator9' */
  /* End of Outputs for SubSystem: '<S5>/DTC0x900924' */

  /* RelationalOperator: '<S5>/Relational Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay7'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->BrkLampShortToGnd != AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_m);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900211' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S17>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->BrkLampShortToGnd;

    /* CCaller: '<S17>/C Caller' */
    App_Call_Event_DTC_0x900211_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900211' */

  /* CCaller: '<S5>/C Caller2' incorporates:
   *  CCaller: '<S5>/C Caller1'
   *  Constant: '<S5>/Constant3'
   */
  rtb_DataTypeConversion_iy = Get_DiagAnt_CV(3U);

  /* RelationalOperator: '<S5>/Relational Operator14' incorporates:
   *  Constant: '<S5>/Constant4'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator14 = (rtb_DataTypeConversion_iy == 1);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900A23' incorporates:
   *  EnablePort: '<S23>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator15' incorporates:
   *  UnitDelay: '<S5>/Unit Delay12'
   */
  if (AppSwcBcm_ARID_DEF.RelationalOperator14 !=
      AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE_p) {
    /* CCaller: '<S23>/C Caller' incorporates:
     *  DataTypeConversion: '<S23>/Data Type Conversion'
     */
    App_Call_Event_DTC_0x900A23_SetEventStatus
      (AppSwcBcm_ARID_DEF.RelationalOperator14);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator15' */
  /* End of Outputs for SubSystem: '<S5>/DTC0x900A23' */

  /* RelationalOperator: '<S5>/Relational Operator16' incorporates:
   *  Constant: '<S5>/Constant5'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator16 = (rtb_DataTypeConversion_iy == 1);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900A24' incorporates:
   *  EnablePort: '<S24>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator10' incorporates:
   *  UnitDelay: '<S5>/Unit Delay10'
   */
  if (AppSwcBcm_ARID_DEF.RelationalOperator16 !=
      AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE_a) {
    /* CCaller: '<S24>/C Caller' incorporates:
     *  DataTypeConversion: '<S24>/Data Type Conversion'
     */
    App_Call_Event_DTC_0x900A24_SetEventStatus
      (AppSwcBcm_ARID_DEF.RelationalOperator16);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator10' */
  /* End of Outputs for SubSystem: '<S5>/DTC0x900A24' */

  /* RelationalOperator: '<S5>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay5'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->HiBeamShortToBat != AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_my);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900512' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S20>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->HiBeamShortToBat;

    /* CCaller: '<S20>/C Caller' */
    App_Call_Event_DTC_0x900512_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900512' */

  /* CCaller: '<S5>/C Caller2' incorporates:
   *  Constant: '<S5>/Constant6'
   */
  rtb_DataTypeConversion_iy = Get_DiagAnt_CV(4U);

  /* RelationalOperator: '<S5>/Relational Operator17' incorporates:
   *  Constant: '<S5>/Constant7'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator17 = (rtb_DataTypeConversion_iy == 1);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900D23' incorporates:
   *  EnablePort: '<S25>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator18' incorporates:
   *  UnitDelay: '<S5>/Unit Delay13'
   */
  if (AppSwcBcm_ARID_DEF.RelationalOperator17 !=
      AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE_a) {
    /* CCaller: '<S25>/C Caller' incorporates:
     *  DataTypeConversion: '<S25>/Data Type Conversion'
     */
    App_Call_Event_DTC_0x900D23_SetEventStatus
      (AppSwcBcm_ARID_DEF.RelationalOperator17);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator18' */
  /* End of Outputs for SubSystem: '<S5>/DTC0x900D23' */

  /* RelationalOperator: '<S5>/Relational Operator19' incorporates:
   *  Constant: '<S5>/Constant8'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator19 = (rtb_DataTypeConversion_iy == 2);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900D24' incorporates:
   *  EnablePort: '<S26>/Enable'
   */
  /* RelationalOperator: '<S5>/Relational Operator11' incorporates:
   *  UnitDelay: '<S5>/Unit Delay11'
   */
  if (AppSwcBcm_ARID_DEF.RelationalOperator19 !=
      AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE_b) {
    /* CCaller: '<S26>/C Caller' incorporates:
     *  DataTypeConversion: '<S26>/Data Type Conversion'
     */
    App_Call_Event_DTC_0x900D24_SetEventStatus
      (AppSwcBcm_ARID_DEF.RelationalOperator19);
  }

  /* End of RelationalOperator: '<S5>/Relational Operator11' */
  /* End of Outputs for SubSystem: '<S5>/DTC0x900D24' */

  /* RelationalOperator: '<S5>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay4'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->LowBeamShortToBat != AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_m);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900412' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S19>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->LowBeamShortToBat;

    /* CCaller: '<S19>/C Caller' */
    App_Call_Event_DTC_0x900412_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900412' */

  /* RelationalOperator: '<S5>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay1'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrLOpen != AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900013' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->TurnIndcrLOpen;

    /* CCaller: '<S14>/C Caller' */
    App_Call_Event_DTC_0x900013_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900013' */

  /* RelationalOperator: '<S5>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrLShort != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cw);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900011' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S13>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->TurnIndcrLShort;

    /* CCaller: '<S13>/C Caller' */
    App_Call_Event_DTC_0x900011_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900011' */

  /* RelationalOperator: '<S5>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay3'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrROpen != AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_f);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900113' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->TurnIndcrROpen;

    /* CCaller: '<S16>/C Caller' */
    App_Call_Event_DTC_0x900113_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900113' */

  /* RelationalOperator: '<S5>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S5>/Unit Delay2'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus()
    )->TurnIndcrRShort != AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_dg);

  /* Outputs for Enabled SubSystem: '<S5>/DTC0x900111' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  if (rtb_RelationalOperator6) {
    /* DataTypeConversion: '<S15>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_DataTypeConversion_iy = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
      ->TurnIndcrRShort;

    /* CCaller: '<S15>/C Caller' */
    App_Call_Event_DTC_0x900111_SetEventStatus(rtb_DataTypeConversion_iy);
  }

  /* End of Outputs for SubSystem: '<S5>/DTC0x900111' */
}

/* Update for atomic system: '<S1>/DTCSet' */
static void AppSwcBcm_DTCSet_Update(void)
{
  /* Update for UnitDelay: '<S5>/Unit Delay6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_f =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->BrkLampShortToBatOrOpen;

  /* Update for UnitDelay: '<S5>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_c =
    AppSwcBcm_ARID_DEF.RelationalOperator12;

  /* Update for UnitDelay: '<S5>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_k =
    AppSwcBcm_ARID_DEF.RelationalOperator13;

  /* Update for UnitDelay: '<S5>/Unit Delay7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_m =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->BrkLampShortToGnd;

  /* Update for UnitDelay: '<S5>/Unit Delay12' */
  AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE_p =
    AppSwcBcm_ARID_DEF.RelationalOperator14;

  /* Update for UnitDelay: '<S5>/Unit Delay10' */
  AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE_a =
    AppSwcBcm_ARID_DEF.RelationalOperator16;

  /* Update for UnitDelay: '<S5>/Unit Delay5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_my =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->HiBeamShortToBat;

  /* Update for UnitDelay: '<S5>/Unit Delay13' */
  AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE_a =
    AppSwcBcm_ARID_DEF.RelationalOperator17;

  /* Update for UnitDelay: '<S5>/Unit Delay11' */
  AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE_b =
    AppSwcBcm_ARID_DEF.RelationalOperator19;

  /* Update for UnitDelay: '<S5>/Unit Delay4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_m =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->LowBeamShortToBat;

  /* Update for UnitDelay: '<S5>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrLOpen;

  /* Update for UnitDelay: '<S5>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cw =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrLShort;

  /* Update for UnitDelay: '<S5>/Unit Delay3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_f =
    (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->TurnIndcrROpen;

  /* Update for UnitDelay: '<S5>/Unit Delay2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_dg =
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
    AppSwcBcm_ARID_DEF.data1_o[22] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.data1_o[23] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->StartReq;
    AppSwcBcm_ARID_DEF.data1_o[24] = AppSwcBcm_ARID_DEF.BusCreator.BJSTimeDay;
    AppSwcBcm_ARID_DEF.data1_o[25] = AppSwcBcm_ARID_DEF.BusCreator.BJSTimeHour;
    AppSwcBcm_ARID_DEF.data1_o[26] = AppSwcBcm_ARID_DEF.BusCreator.BJSTimeMonth;
    tmp = AppSwcBcm_ARID_DEF.BusCreator.BJSTimeYear;
    if (AppSwcBcm_ARID_DEF.BusCreator.BJSTimeYear > 255) {
      tmp = 255U;
    }

    AppSwcBcm_ARID_DEF.data1_o[27] = (uint8)tmp;
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
  /* MATLAB Function: '<S28>/bit_shift' */
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
  /* MATLAB Function: '<S29>/bit_shift' */
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
  /* MATLAB Function: '<S30>/bit_shift' */
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
  /* MATLAB Function: '<S31>/bit_shift' */
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
  /* MATLAB Function: '<S32>/bit_shift' */
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
  /* MATLAB Function: '<S33>/bit_shift' */
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
  /* MATLAB Function: '<S34>/bit_shift' */
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
  /* MATLAB Function: '<S35>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 7);
}

/* Output and update for atomic system: '<S1>/IODID' */
static void AppSwcBcm_IODID(void)
{
  uint8 rtb_CCaller[2];
  uint8 rtb_CCaller1;
  uint8 rtb_CCaller2_o;
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
  App_Call_Event_IODID_0x3233_GetEventStatus(&rtb_CCaller2_o);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift30' */
  rtb_y_d = AppSwcBcm_BitShift(rtb_CCaller2_o);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift30' */

  /* S-Function (sfix_bitop): '<S7>/Bitwise AND30' */
  IODID_WiperHiSpdCtlFlg = (uint8)(rtb_y_d & 1);

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift31' */
  rtb_y_j0 = AppSwcBcm_BitShift1(rtb_CCaller2_o);

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
  rtb_y_j1 = AppSwcBcm_BitShift10(rtb_CCaller2_o);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift24' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift25' */
  rtb_y_pp = AppSwcBcm_BitShift11(rtb_CCaller2_o);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift25' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift26' */
  rtb_y_nq = AppSwcBcm_BitShift12(rtb_CCaller2_o);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift26' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift27' */
  rtb_y_k2 = AppSwcBcm_BitShift13(rtb_CCaller2_o);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift27' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift28' */
  rtb_y_bh = AppSwcBcm_BitShift14(rtb_CCaller2_o);

  /* End of Outputs for SubSystem: '<S7>/Bit Shift28' */

  /* Outputs for Atomic SubSystem: '<S7>/Bit Shift29' */
  rtb_y_kc = AppSwcBcm_BitShift15(rtb_CCaller2_o);

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
 *    '<S141>/Lib_RiseEdgeDet'
 *    '<S151>/Lib_RiseEdgeDet'
 *    '<S158>/Lib_RiseEdgeDet'
 *    '<S191>/Lib_RiseEdgeDet'
 *    '<S193>/Lib_RiseEdgeDet'
 *    '<S195>/Lib_RiseEdgeDet'
 *    '<S197>/Lib_RiseEdgeDet'
 *    '<S218>/Lib_RiseEdgeDet'
 *    '<S219>/Lib_RiseEdgeDet'
 *    '<S222>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_Reset(ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S143>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S141>/Lib_RiseEdgeDet'
 *    '<S151>/Lib_RiseEdgeDet'
 *    '<S158>/Lib_RiseEdgeDet'
 *    '<S191>/Lib_RiseEdgeDet'
 *    '<S193>/Lib_RiseEdgeDet'
 *    '<S195>/Lib_RiseEdgeDet'
 *    '<S197>/Lib_RiseEdgeDet'
 *    '<S218>/Lib_RiseEdgeDet'
 *    '<S219>/Lib_RiseEdgeDet'
 *    '<S222>/Lib_RiseEdgeDet'
 *    ...
 */
static boolean AppSwcBcm_Lib_RiseEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S143>/Logical Operator' incorporates:
   *  Logic: '<S143>/Logical Operator1'
   *  UnitDelay: '<S143>/Unit Delay'
   */
  rty_Lib_blOut_0 = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S143>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/*
 * System reset for atomic system:
 *    '<S141>/Lib_SR'
 *    '<S430>/Lib_SR'
 *    '<S645>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR_Reset(ARID_DEF_Lib_SR_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S144>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S141>/Lib_SR'
 *    '<S430>/Lib_SR'
 *    '<S645>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR(boolean rtu_S, boolean rtu_R, boolean *rty_Q,
  ARID_DEF_Lib_SR_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Switch: '<S144>/Switch' incorporates:
   *  Constant: '<S144>/Constant'
   *  Logic: '<S144>/Logical Operator'
   *  UnitDelay: '<S144>/Unit Delay'
   */
  if (rtu_R) {
    *rty_Q = false;
  } else {
    *rty_Q = (rtu_S || AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);
  }

  /* End of Switch: '<S144>/Switch' */

  /* Update for UnitDelay: '<S144>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = *rty_Q;
}

/* Output and update for atomic system: '<S1>/RVMCtl' */
static void AppSwcBcm_RVMCtl(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator_kc;

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_kc = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S8>/RVMCtl' incorporates:
   *  EnablePort: '<S141>/Enable'
   */
  if (rtb_RelationalOperator_kc) {
    if (!AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
      /* InitializeConditions for UnitDelay: '<S141>/Unit Delay' */
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = false;

      /* SystemReset for Atomic SubSystem: '<S141>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_Reset
        (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m4);

      /* End of SystemReset for SubSystem: '<S141>/Lib_RiseEdgeDet' */

      /* SystemReset for Chart: '<S141>/LIB_Tim' */
      AppSwcBcm_ARID_DEF.Cnt_Tick_av = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;

      /* SystemReset for Atomic SubSystem: '<S141>/Lib_SR' */
      AppSwcBcm_Lib_SR_Reset(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_h);

      /* End of SystemReset for SubSystem: '<S141>/Lib_SR' */
      AppSwcBcm_ARID_DEF.RVMCtl_MODE = true;
    }

    /* RelationalOperator: '<S141>/Relational Operator1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator_kc =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPRrViewMirrHeatgKey_flg;

    /* Outputs for Atomic SubSystem: '<S141>/Lib_RiseEdgeDet' */
    rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator_kc,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m4);

    /* End of Outputs for SubSystem: '<S141>/Lib_RiseEdgeDet' */

    /* Chart: '<S141>/LIB_Tim' incorporates:
     *  Constant: '<S141>/Constant2'
     *  Constant: '<S141>/Constant7'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) {
      if (AppSwcBcm_ARID_DEF.Cnt_M_h >= RVMCtl_MaxHeatTimM_C) {
        rtb_RelationalOperator_kc = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_Tick_av + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_Tick_av + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_Tick_av = (uint16)tmp;
        rtb_RelationalOperator_kc = false;
        if (AppSwcBcm_ARID_DEF.Cnt_Tick_av >= 1.0F / RVMCtl_Ts_C) {
          tmp = AppSwcBcm_ARID_DEF.Cnt_S_b + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_S_b + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_S_b = (uint8)tmp;
          AppSwcBcm_ARID_DEF.Cnt_Tick_av = 0U;
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
      rtb_RelationalOperator_kc = false;
      AppSwcBcm_ARID_DEF.Cnt_Tick_av = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
    }

    /* End of Chart: '<S141>/LIB_Tim' */

    /* Outputs for Atomic SubSystem: '<S141>/Lib_SR' */
    /* Logic: '<S141>/Logical Operator2' incorporates:
     *  Logic: '<S141>/Logical Operator1'
     *  UnitDelay: '<S141>/Unit Delay'
     */
    AppSwcBcm_Lib_SR(rtb_LogicalOperator, (rtb_LogicalOperator &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) || rtb_RelationalOperator_kc,
                     &AppSwcBcm_ARID_DEF.Switch_i,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_h);

    /* End of Outputs for SubSystem: '<S141>/Lib_SR' */

    /* Update for UnitDelay: '<S141>/Unit Delay' */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = AppSwcBcm_ARID_DEF.Switch_i;
  } else if (AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
    /* Disable for Switch: '<S144>/Switch' incorporates:
     *  Outport: '<S141>/RVMCtl_J42Heat'
     */
    AppSwcBcm_ARID_DEF.Switch_i = false;
    AppSwcBcm_ARID_DEF.RVMCtl_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S8>/RVMCtl' */

  /* Outputs for Atomic SubSystem: '<S8>/Ovrd' */
  /* Switch: '<S140>/Switch' incorporates:
   *  Constant: '<S8>/Constant18'
   */
  if (RVMCtl_J42HeatOvrdFlg_C) {
    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S8>/Constant19'
     */
    RVMCtl_J42Heat = RVMCtl_J42HeatOvrdVal_C;
  } else {
    /* Switch: '<S140>/Switch' */
    RVMCtl_J42Heat = AppSwcBcm_ARID_DEF.Switch_i;
  }

  /* End of Switch: '<S140>/Switch' */
  /* End of Outputs for SubSystem: '<S8>/Ovrd' */
}

/*
 * Output and update for function-call system:
 *    '<S147>/Lib_RiseEdgeDet'
 *    '<S155>/Lib_RiseEdgeDet'
 *    '<S187>/Lib_RiseEdgeDet'
 *    '<S188>/Lib_RiseEdgeDet'
 *    '<S189>/Lib_RiseEdgeDet'
 *    '<S190>/Lib_RiseEdgeDet'
 *    '<S201>/Lib_RiseEdgeDet'
 *    '<S201>/Lib_RiseEdgeDet1'
 *    '<S202>/Lib_RiseEdgeDet'
 *    '<S202>/Lib_RiseEdgeDet1'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_p(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_g_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S151>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S151>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S1>/SeatCtl' */
static void AppSwcBcm_SeatCtl(void)
{
  sint32 rtb_SeatCtl_CN167DrvSeatHtPWM;
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator1_mh;

  /* Chart: '<S145>/LIB_TPD_Ts1' incorporates:
   *  Constant: '<S145>/Constant11'
   *  Constant: '<S145>/Constant15'
   *  Constant: '<S145>/Constant16'
   *  Constant: '<S145>/Constant17'
   *  DataTypeConversion: '<S145>/Data Type Conversion1'
   *  RelationalOperator: '<S145>/Relational Operator2'
   */
  if (BSW_CN744DrvSeatResis >= SeatCtl_NTCOpenResis_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fs >= (float32)SeatCtl_NTCOpenValidTim_C /
         (SeatCtl_Ts_C * 100.0F)) && (SeatCtl_NTCOpenValidTim_C != 0xFFFF)) {
      SeatCtl_DrvNTCOpen = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fs++;
      AppSwcBcm_ARID_DEF.cnt_heal_jk = (uint16)((float32)
        SeatCtl_NTCOpenInValidTim_C / (SeatCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fs = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_jk == 0) {
      SeatCtl_DrvNTCOpen = false;
    } else if (SeatCtl_NTCOpenInValidTim_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_jk--;
    }
  }

  /* End of Chart: '<S145>/LIB_TPD_Ts1' */

  /* RelationalOperator: '<S145>/Relational Operator1' incorporates:
   *  Constant: '<S145>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_mh = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S145>/Switch' */
  if (rtb_RelationalOperator1_mh) {
    /* RelationalOperator: '<S145>/Relational Operator3' incorporates:
     *  Constant: '<S145>/Constant20'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator1_mh =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
       ->VIPM_HUMaiDrvrSeatHeat_enum != 0);

    /* Switch: '<S145>/Switch1' */
    if (rtb_RelationalOperator1_mh) {
      /* Switch: '<S145>/Switch' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
       *  Switch: '<S145>/Switch1'
       */
      rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
        ->VIPM_HUMaiDrvrSeatHeat_enum;
    } else {
      /* RelationalOperator: '<S145>/Relational Operator4' incorporates:
       *  Constant: '<S145>/Constant26'
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
       */
      rtb_RelationalOperator1_mh =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPowerSts == 2);

      /* Switch: '<S145>/Switch2' */
      if (rtb_RelationalOperator1_mh) {
        /* MultiPortSwitch: '<S145>/Multiport Switch2' incorporates:
         *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
         */
        switch ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
                ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum) {
         case 1:
          /* Switch: '<S145>/Switch' incorporates:
           *  Constant: '<S145>/Constant21'
           *  MultiPortSwitch: '<S145>/Multiport Switch2'
           *  Switch: '<S145>/Switch2'
           */
          rtb_Switch = 2U;
          break;

         case 2:
          /* Switch: '<S145>/Switch' incorporates:
           *  Constant: '<S145>/Constant22'
           *  MultiPortSwitch: '<S145>/Multiport Switch2'
           *  Switch: '<S145>/Switch2'
           */
          rtb_Switch = 3U;
          break;

         case 3:
          /* Switch: '<S145>/Switch' incorporates:
           *  Constant: '<S145>/Constant23'
           *  MultiPortSwitch: '<S145>/Multiport Switch2'
           *  Switch: '<S145>/Switch2'
           */
          rtb_Switch = 4U;
          break;

         case 4:
          /* Switch: '<S145>/Switch' incorporates:
           *  Constant: '<S145>/Constant24'
           *  MultiPortSwitch: '<S145>/Multiport Switch2'
           *  Switch: '<S145>/Switch2'
           */
          rtb_Switch = 1U;
          break;

         default:
          /* Switch: '<S145>/Switch' incorporates:
           *  Constant: '<S145>/Constant25'
           *  MultiPortSwitch: '<S145>/Multiport Switch2'
           *  Switch: '<S145>/Switch2'
           */
          rtb_Switch = 0U;
          break;
        }

        /* End of MultiPortSwitch: '<S145>/Multiport Switch2' */
      } else {
        /* Switch: '<S145>/Switch' incorporates:
         *  Constant: '<S145>/Constant27'
         *  Switch: '<S145>/Switch2'
         */
        rtb_Switch = 0U;
      }

      /* End of Switch: '<S145>/Switch2' */
    }

    /* End of Switch: '<S145>/Switch1' */
  } else {
    /* Switch: '<S145>/Switch' incorporates:
     *  Constant: '<S145>/Constant10'
     */
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S145>/Switch' */

  /* MultiPortSwitch: '<S145>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S145>/Multiport Switch' incorporates:
     *  Constant: '<S145>/Constant1'
     */
    SeatCtl_MaiDrvSeatStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S145>/Multiport Switch' incorporates:
     *  Constant: '<S145>/Constant2'
     */
    SeatCtl_MaiDrvSeatStFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S145>/Multiport Switch' incorporates:
     *  Constant: '<S145>/Constant3'
     */
    SeatCtl_MaiDrvSeatStFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S145>/Multiport Switch' incorporates:
     *  Constant: '<S145>/Constant4'
     */
    SeatCtl_MaiDrvSeatStFb = 3U;
    break;
  }

  /* End of MultiPortSwitch: '<S145>/Multiport Switch' */

  /* MultiPortSwitch: '<S145>/Multiport Switch1' */
  switch (SeatCtl_MaiDrvSeatStFb) {
   case 1:
    /* MultiPortSwitch: '<S145>/Multiport Switch1' incorporates:
     *  Constant: '<S145>/Constant5'
     */
    rtb_Switch = SeatCtl_DrvTempLvl1_C;
    break;

   case 2:
    /* MultiPortSwitch: '<S145>/Multiport Switch1' incorporates:
     *  Constant: '<S145>/Constant6'
     */
    rtb_Switch = SeatCtl_DrvTempLvl2_C;
    break;

   case 3:
    /* MultiPortSwitch: '<S145>/Multiport Switch1' incorporates:
     *  Constant: '<S145>/Constant7'
     */
    rtb_Switch = SeatCtl_DrvTempLvl3_C;
    break;

   default:
    /* MultiPortSwitch: '<S145>/Multiport Switch1' incorporates:
     *  Constant: '<S145>/Constant8'
     */
    rtb_Switch = SeatCtl_DrvTempLvl0_C;
    break;
  }

  /* End of MultiPortSwitch: '<S145>/Multiport Switch1' */

  /* DataTypeConversion: '<S145>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S145>/Data Type Conversion1'
   *  Lookup_n-D: '<S145>/1-D Lookup Table2'
   */
  SeatCtl_DrvSeatTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_CN744DrvSeatResis, (const float32 *)&SeatCtl_DrvSeatTempLookUp_X[0], (
    const float32 *)&SeatCtl_DrvSeatTempLookUp_Y[0], 22U));

  /* Chart: '<S145>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S145>/Constant12'
   *  Constant: '<S145>/Constant13'
   *  Constant: '<S145>/Constant14'
   *  DataTypeConversion: '<S145>/Data Type Conversion1'
   *  RelationalOperator: '<S145>/Relational Operator'
   */
  if (BSW_CN744DrvSeatResis <= SeatCtl_NTCShortResis_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_n >= (float32)SeatCtl_NTCShortValidTim_C /
         (SeatCtl_Ts_C * 100.0F)) && (SeatCtl_NTCShortValidTim_C != 0xFFFF)) {
      SeatCtl_DrvNTCShort = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_n++;
      AppSwcBcm_ARID_DEF.cnt_heal_fg = (uint16)((float32)
        SeatCtl_NTCShortInValidTim_C / (SeatCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_n = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_fg == 0) {
      SeatCtl_DrvNTCShort = false;
    } else if (SeatCtl_NTCShortInValidTim_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_fg--;
    }
  }

  /* End of Chart: '<S145>/LIB_TPD_Ts' */

  /* Chart: '<S145>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_f;
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib == AppSwcBcm_IN_Off_f) {
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    if ((rtb_Switch - SeatCtl_DrvSeatTemp >= SeatCtl_HtDiffTemp_C) &&
        (rtb_Switch != 0) && (!SeatCtl_DrvNTCShort) && (!SeatCtl_DrvNTCOpen)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_On_c;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    }
  } else {
    /* case IN_On: */
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    if ((SeatCtl_DrvSeatTemp >= rtb_Switch) || (rtb_Switch == 0) ||
        SeatCtl_DrvNTCShort || SeatCtl_DrvNTCOpen) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_f;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    }
  }

  /* End of Chart: '<S145>/Chart' */

  /* Outputs for Atomic SubSystem: '<S145>/Ovrd' */
  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S145>/Constant18'
   */
  if (SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C) {
    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<S145>/Constant19'
     */
    SeatCtl_CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;
  } else {
    /* Switch: '<S150>/Switch' */
    SeatCtl_CN167DrvSeatHtPWM = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
  }

  /* End of Switch: '<S150>/Switch' */
  /* End of Outputs for SubSystem: '<S145>/Ovrd' */

  /* Chart: '<S145>/HeatFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init;
    SeatCtl_RemtHeatFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_cn = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib) {
     case AppSwcBcm_IN_Fail:
      SeatCtl_RemtHeatFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_cn >= SeatCtl_RemtCmdFdCnt_C) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init;
        SeatCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_cn = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_cn++;
      }
      break;

     case AppSwcBcm_IN_Init:
      SeatCtl_RemtHeatFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_cc =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum == 2) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum == 3) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum == 4));

      /* Outputs for Function Call SubSystem: '<S147>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cc,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ja,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fb);

      /* End of Outputs for SubSystem: '<S147>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ja) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Wait;
      }
      break;

     case AppSwcBcm_IN_Suc:
      SeatCtl_RemtHeatFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_cn >= SeatCtl_RemtCmdFdCnt_C) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Init;
        SeatCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_cn = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_cn++;
      }
      break;

     default:
      /* case IN_Wait: */
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPowerSts == 2) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Suc;
        SeatCtl_RemtHeatFb = 1U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_cn + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_cn + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_cn = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
                 ->VIPM_TBOXRemtMaiDrSeatHeatReq_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c85_SeatCtl_Lib = AppSwcBcm_IN_Fail;
        SeatCtl_RemtHeatFb = 3U;
        rtb_SeatCtl_CN167DrvSeatHtPWM = AppSwcBcm_ARID_DEF.Cnt_cn + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_cn + 1 > 255) {
          rtb_SeatCtl_CN167DrvSeatHtPWM = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_cn = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
      }
      break;
    }
  }

  /* End of Chart: '<S145>/HeatFb' */
}

/* Output and update for atomic system: '<S1>/SteerWhlCtl' */
static void AppSwcBcm_SteerWhlCtl(void)
{
  sint32 tmp;

  /* DataTypeConversion: '<S153>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S153>/Data Type Conversion1'
   *  Lookup_n-D: '<S153>/1-D Lookup Table1'
   */
  SteerWhlCtl_SteerWhlTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_J134SteerWhlResis, (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_X[0],
     (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_Y[0], 17U));

  /* Chart: '<S153>/HeatSet' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_OFF;
    SteerWhlCtl_SteerWhlHeatSts = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib == AppSwcBcm_IN_OFF) {
    SteerWhlCtl_SteerWhlHeatSts = 0U;
    if ((((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 2) &&
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_HUSteerWhlHeat_enum == 2)) ||
        (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPowerSts == 2) &&
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 1))) {
      AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_ON;
      SteerWhlCtl_SteerWhlHeatSts = 1U;
    }
  } else {
    /* case IN_ON: */
    SteerWhlCtl_SteerWhlHeatSts = 1U;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 0) ||
        ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
         ->VIPM_HUSteerWhlHeat_enum == 1) ||
        (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPowerSts == 2) &&
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 2))) {
      AppSwcBcm_ARID_DEF.is_c1_SteerWhlCtl_Lib = AppSwcBcm_IN_OFF;
      SteerWhlCtl_SteerWhlHeatSts = 0U;
    }
  }

  /* End of Chart: '<S153>/HeatSet' */

  /* Chart: '<S153>/HeatCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_a;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib == AppSwcBcm_IN_Off_a) {
    if ((SteerWhlCtl_SteerWhlHeatSts != 0) && (SteerWhlCtl_TrgtTemp_C -
         SteerWhlCtl_SteerWhlTemp >= SteerWhlCtl_DiffTemp_C)) {
      AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_On_n;
      AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = true;
    }

    /* case IN_On: */
  } else if ((SteerWhlCtl_SteerWhlHeatSts == 0) || (SteerWhlCtl_SteerWhlTemp >=
              SteerWhlCtl_TrgtTemp_C)) {
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_a;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  }

  /* End of Chart: '<S153>/HeatCtl' */

  /* Outputs for Atomic SubSystem: '<S153>/Ovrd' */
  /* Switch: '<S157>/Switch' incorporates:
   *  Constant: '<S153>/Constant18'
   */
  if (SteerWhlCtl_J447SteerWhlHtOvrdFlg_C) {
    /* Switch: '<S157>/Switch' incorporates:
     *  Constant: '<S153>/Constant19'
     */
    SteerWhlCtl_J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHtOvrdVal_C;
  } else {
    /* Switch: '<S157>/Switch' */
    SteerWhlCtl_J447SteerWhlHt = AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta;
  }

  /* End of Switch: '<S157>/Switch' */
  /* End of Outputs for SubSystem: '<S153>/Ovrd' */

  /* Chart: '<S153>/HeatFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c85_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c85_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_j;
    SteerWhlCtl_RemtHeatFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_gv = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib) {
     case AppSwcBcm_IN_Fail_f:
      SteerWhlCtl_RemtHeatFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_gv >= SteerWhlCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_j;
        SteerWhlCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_gv = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_gv++;
      }
      break;

     case AppSwcBcm_IN_Init_j:
      SteerWhlCtl_RemtHeatFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_jh =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtStrWhlHeatReq_enum == 2));

      /* Outputs for Function Call SubSystem: '<S155>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_jh,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ftq,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cu);

      /* End of Outputs for SubSystem: '<S155>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ftq) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Wait_h;
      }
      break;

     case AppSwcBcm_IN_Suc_l:
      SteerWhlCtl_RemtHeatFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_gv >= SteerWhlCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Init_j;
        SteerWhlCtl_RemtHeatFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_gv = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_gv++;
      }
      break;

     default:
      /* case IN_Wait: */
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPowerSts == 2) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Suc_l;
        SteerWhlCtl_RemtHeatFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_gv + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_gv + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_gv = (uint8)tmp;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
                 ->VIPM_TBOXRemtStrWhlHeatReq_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c85_SteerWhlCtl_Lib = AppSwcBcm_IN_Fail_f;
        SteerWhlCtl_RemtHeatFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_gv + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_gv + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_gv = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S153>/HeatFb' */
}

/*
 * Output and update for function-call system:
 *    '<S160>/Lib_FailEdgeDet'
 *    '<S554>/Lib_FailEdgeDet'
 *    '<S920>/Lib_FailEdgeDet'
 */
static void AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S162>/Logical Operator' incorporates:
   *  Logic: '<S162>/Logical Operator1'
   *  UnitDelay: '<S162>/Unit Delay'
   */
  *rty_Lib_blOut = ((!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S162>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/* Output and update for atomic system: '<S1>/TboxTim' */
static void AppSwcBcm_TboxTim(void)
{
  sint32 tmp_0;
  uint8 tmp;
  boolean guard1 = false;
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.CCaller9 == 1) {
    if ((!AppSwcBcm_ARID_DEF.Flg_pr) && (AppSwcBcm_ARID_DEF.Cnt_kt >= 50)) {
      /* Inport: '<Root>/IPM_TBOX_BJS_Time_BAC' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
       */
      if ((Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
           ())->VIPM_TBOXBJSTimeMonth_nu == 2) {
        if ((((Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
               ())->VIPM_TBOXBJSTimeYear_nu % 4 == 0) &&
             ((Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
               ())->VIPM_TBOXBJSTimeYear_nu % 100 != 0)) ||
            ((Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
              ())->VIPM_TBOXBJSTimeYear_nu % 400 == 0)) {
          tmp = 29U;
        } else {
          tmp = 28U;
        }
      } else if
          ((Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
            ())->VIPM_TBOXBJSTimeMonth_nu % 2 == 0) {
        tmp = 30U;
      } else {
        tmp = 31U;
      }

      tmp_0 =
        (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
         ())->VIPM_TBOXBJSTimeYear_nu -
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus())->BJSTimeYear;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      } else if (tmp_0 > 255) {
        tmp_0 = 255;
      }

      /* Inport: '<Root>/IPM_TBOX_BJS_Time_BAC' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
       */
      tmp_0 = (tmp_0 * 12 +
               (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
                ())->VIPM_TBOXBJSTimeMonth_nu) -
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus())->BJSTimeMonth;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      } else if (tmp_0 > 255) {
        tmp_0 = 255;
      }

      /* Inport: '<Root>/IPM_TBOX_BJS_Time_BAC' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
       */
      tmp_0 = (tmp_0 * tmp +
               (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
                ())->VIPM_TBOXBJSTimeDay_nu) -
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus())->BJSTimeDay;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      } else if (tmp_0 > 255) {
        tmp_0 = 255;
      }

      /* Inport: '<Root>/IPM_TBOX_BJS_Time_BAC' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
       */
      tmp_0 = (tmp_0 * 24 +
               (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
                ())->VIPM_TBOXBJSTimeHour_nu) -
        (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus())->BJSTimeHour;
      if (tmp_0 < 0) {
        tmp_0 = 0;
      } else if (tmp_0 > 255) {
        tmp_0 = 255;
      }

      TboxTim_HourDiff = (uint8)tmp_0;
      AppSwcBcm_ARID_DEF.Flg_pr = true;
    } else {
      tmp_0 = AppSwcBcm_ARID_DEF.Cnt_kt + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_kt + 1 > 255) {
        tmp_0 = 255;
      }

      AppSwcBcm_ARID_DEF.Cnt_kt = (uint8)tmp_0;
      guard1 = true;
    }
  } else {
    AppSwcBcm_ARID_DEF.Cnt_kt = 0U;
    guard1 = true;
  }

  if (guard1) {
    if (!AppSwcBcm_ARID_DEF.Flg1) {
      /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
      TboxTim_BJSTimeYear = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus()
        )->BJSTimeYear;
      TboxTim_BJSTimeMonth = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus())
        ->BJSTimeMonth;
      TboxTim_BJSTimeDay = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus()
        )->BJSTimeDay;
      TboxTim_BJSTimeHour = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_EEReadCtl_Bus()
        )->BJSTimeHour;
      AppSwcBcm_ARID_DEF.Flg1 = true;
    }
  }

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.Lib_blIn_ohb =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())->SysPwrMode == 2);

  /* Chart: '<S11>/TboxTim' incorporates:
   *  SubSystem: '<S160>/Lib_FailEdgeDet'
   */
  AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ohb,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ao,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_m);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ao) {
    /* Inport: '<Root>/IPM_TBOX_BJS_Time_BAC' */
    TboxTim_BJSTimeYear =
      (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
       ())->VIPM_TBOXBJSTimeYear_nu;
    TboxTim_BJSTimeMonth =
      (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
       ())->VIPM_TBOXBJSTimeMonth_nu;
    TboxTim_BJSTimeDay =
      (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
       ())->VIPM_TBOXBJSTimeDay_nu;
    TboxTim_BJSTimeHour =
      (Rte_IRead_Runbl_AppSwcBcm_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
       ())->VIPM_TBOXBJSTimeHour_nu;
  }
}

/* Output and update for atomic system: '<S12>/DrvWinCtl' */
static void AppSwcBcm_DrvWinCtl(void)
{
  /* Chart: '<S12>/DrvWinCtl' */
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

  /* End of Chart: '<S12>/DrvWinCtl' */
}

/* Output and update for atomic system: '<S12>/PsgWinCtl' */
static void AppSwcBcm_PsgWinCtl(void)
{
  /* Chart: '<S12>/PsgWinCtl' */
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

  /* End of Chart: '<S12>/PsgWinCtl' */
}

/*
 * Output and update for atomic system:
 *    '<S169>/Bit Shift1'
 *    '<S169>/Bit Shift7'
 *    '<S470>/Bit Shift3'
 *    '<S674>/Bit Shift1'
 */
static uint16 AppSwcBcm_BitShift1_m(uint16 rtu_u)
{
  /* MATLAB Function: '<S172>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S169>/Bit Shift3'
 *    '<S376>/Bit Shift5'
 *    '<S470>/Bit Shift5'
 *    '<S674>/Bit Shift'
 */
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u)
{
  /* MATLAB Function: '<S173>/bit_shift' */
  return rtu_u;
}

/* Output and update for atomic system: '<S12>/SigProc' */
static void AppSwcBcm_SigProc(void)
{
  uint16 rtb_Switch1_aw;
  boolean rtb_LogicalOperator1_ey;

  /* Outputs for Atomic SubSystem: '<S169>/Bit Shift3' */
  /* Constant: '<S169>/Constant11' */
  rtb_Switch1_aw = AppSwcBcm_BitShift3(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S169>/Bit Shift3' */

  /* Switch: '<S169>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S169>/Bitwise AND3'
   */
  if ((rtb_Switch1_aw & 1U) != 0U) {
    /* Switch: '<S169>/Switch1' incorporates:
     *  Constant: '<S169>/Constant15'
     */
    rtb_Switch1_aw = WinCtl_DrvWinSwResis_C;
  } else {
    /* Switch: '<S169>/Switch1' */
    rtb_Switch1_aw = BSW_J113DrvWinSwResis;
  }

  /* End of Switch: '<S169>/Switch3' */

  /* Logic: '<S169>/Logical Operator1' incorporates:
   *  Constant: '<S169>/Constant26'
   *  Constant: '<S169>/Constant31'
   *  RelationalOperator: '<S169>/Relational Operator2'
   *  RelationalOperator: '<S169>/Relational Operator3'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_DrvWinDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvWinDnMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S169>/Constant17'
   *  Constant: '<S169>/Constant18'
   *  Constant: '<S169>/Constant19'
   */
  if (rtb_LogicalOperator1_ey) {
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

  /* End of Chart: '<S169>/LIB_TPD_10ms1' */

  /* Logic: '<S169>/Logical Operator2' incorporates:
   *  Constant: '<S169>/Constant35'
   *  Constant: '<S169>/Constant36'
   *  RelationalOperator: '<S169>/Relational Operator4'
   *  RelationalOperator: '<S169>/Relational Operator5'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_DrvWinAutoDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvWinAutoDnMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S169>/Constant23'
   *  Constant: '<S169>/Constant24'
   *  Constant: '<S169>/Constant25'
   */
  if (rtb_LogicalOperator1_ey) {
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

  /* End of Chart: '<S169>/LIB_TPD_10ms2' */

  /* Logic: '<S169>/Logical Operator' incorporates:
   *  Constant: '<S169>/Constant20'
   *  Constant: '<S169>/Constant22'
   *  RelationalOperator: '<S169>/Relational Operator'
   *  RelationalOperator: '<S169>/Relational Operator1'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_DrvWinUpMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvWinUpMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S169>/Constant12'
   *  Constant: '<S169>/Constant13'
   *  Constant: '<S169>/Constant14'
   */
  if (rtb_LogicalOperator1_ey) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_da >= (float32)WinCtl_DrvWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_da++;
      AppSwcBcm_ARID_DEF.cnt_heal_a = (uint16)((float32)
        WinCtl_DrvWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_da = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a == 0) {
      WinCtl_DrvWinUpSw = false;
    } else if (WinCtl_DrvWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a--;
    }
  }

  /* End of Chart: '<S169>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S169>/Bit Shift7' */
  /* Constant: '<S169>/Constant21' */
  rtb_Switch1_aw = AppSwcBcm_BitShift1_m(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S169>/Bit Shift7' */

  /* Switch: '<S169>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S169>/Bitwise AND7'
   */
  if ((rtb_Switch1_aw & 1U) != 0U) {
    /* Switch: '<S169>/Switch1' incorporates:
     *  Constant: '<S169>/Constant30'
     */
    rtb_Switch1_aw = WinCtl_PsgWinSwResis_C;
  } else {
    /* Switch: '<S169>/Switch1' */
    rtb_Switch1_aw = BSW_J26PsgWinSwResis;
  }

  /* End of Switch: '<S169>/Switch6' */

  /* Logic: '<S169>/Logical Operator3' incorporates:
   *  Constant: '<S169>/Constant40'
   *  Constant: '<S169>/Constant41'
   *  RelationalOperator: '<S169>/Relational Operator6'
   *  RelationalOperator: '<S169>/Relational Operator7'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_PsgWinUpMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_PsgWinUpMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S169>/Constant27'
   *  Constant: '<S169>/Constant28'
   *  Constant: '<S169>/Constant29'
   */
  if (rtb_LogicalOperator1_ey) {
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

  /* End of Chart: '<S169>/LIB_TPD_10ms4' */

  /* Logic: '<S169>/Logical Operator4' incorporates:
   *  Constant: '<S169>/Constant42'
   *  Constant: '<S169>/Constant43'
   *  RelationalOperator: '<S169>/Relational Operator8'
   *  RelationalOperator: '<S169>/Relational Operator9'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_PsgWinDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_PsgWinDnMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S169>/Constant32'
   *  Constant: '<S169>/Constant33'
   *  Constant: '<S169>/Constant34'
   */
  if (rtb_LogicalOperator1_ey) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_kj >= (float32)WinCtl_PsgWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_kj++;
      AppSwcBcm_ARID_DEF.cnt_heal_km = (uint16)((float32)
        WinCtl_PsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_kj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_km == 0) {
      WinCtl_PsgWinDnSw = false;
    } else if (WinCtl_PsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_km--;
    }
  }

  /* End of Chart: '<S169>/LIB_TPD_10ms5' */

  /* Logic: '<S169>/Logical Operator5' incorporates:
   *  Constant: '<S169>/Constant44'
   *  Constant: '<S169>/Constant45'
   *  RelationalOperator: '<S169>/Relational Operator10'
   *  RelationalOperator: '<S169>/Relational Operator11'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_PsgWinAutoDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_PsgWinAutoDnMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S169>/Constant37'
   *  Constant: '<S169>/Constant38'
   *  Constant: '<S169>/Constant39'
   */
  if (rtb_LogicalOperator1_ey) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_im >= (float32)
         WinCtl_PsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_PsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_im++;
      AppSwcBcm_ARID_DEF.cnt_heal_ip = (uint16)((float32)
        WinCtl_PsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_im = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ip == 0) {
      WinCtl_PsgWinAutoDnSw = false;
    } else if (WinCtl_PsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ip--;
    }
  }

  /* End of Chart: '<S169>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S169>/Bit Shift1' */
  /* Constant: '<S169>/Constant1' */
  rtb_Switch1_aw = AppSwcBcm_BitShift1_m(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S169>/Bit Shift1' */

  /* Switch: '<S169>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S169>/Bitwise AND1'
   */
  if ((rtb_Switch1_aw & 1U) != 0U) {
    /* Switch: '<S169>/Switch1' incorporates:
     *  Constant: '<S169>/Constant5'
     */
    rtb_Switch1_aw = WinCtl_DrvPsgWinSwResis_C;
  } else {
    /* Switch: '<S169>/Switch1' */
    rtb_Switch1_aw = BSW_J126DrvPsgWinSwResis;
  }

  /* End of Switch: '<S169>/Switch1' */

  /* Logic: '<S169>/Logical Operator6' incorporates:
   *  Constant: '<S169>/Constant46'
   *  Constant: '<S169>/Constant47'
   *  RelationalOperator: '<S169>/Relational Operator14'
   *  RelationalOperator: '<S169>/Relational Operator15'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_DrvPsgWinUpMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvPsgWinUpMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S169>/Constant2'
   *  Constant: '<S169>/Constant3'
   *  Constant: '<S169>/Constant4'
   */
  if (rtb_LogicalOperator1_ey) {
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

  /* End of Chart: '<S169>/LIB_TPD_10ms7' */

  /* Logic: '<S169>/Logical Operator7' incorporates:
   *  Constant: '<S169>/Constant48'
   *  Constant: '<S169>/Constant49'
   *  RelationalOperator: '<S169>/Relational Operator16'
   *  RelationalOperator: '<S169>/Relational Operator17'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_DrvPsgWinDnMinResis_C) &&
    (rtb_Switch1_aw <= WinCtl_DrvPsgWinDnMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S169>/Constant6'
   *  Constant: '<S169>/Constant7'
   *  Constant: '<S169>/Constant8'
   */
  if (rtb_LogicalOperator1_ey) {
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

  /* End of Chart: '<S169>/LIB_TPD_10ms8' */

  /* Logic: '<S169>/Logical Operator8' incorporates:
   *  Constant: '<S169>/Constant50'
   *  Constant: '<S169>/Constant51'
   *  RelationalOperator: '<S169>/Relational Operator12'
   *  RelationalOperator: '<S169>/Relational Operator13'
   */
  rtb_LogicalOperator1_ey = ((rtb_Switch1_aw >= WinCtl_DrvPsgWinAutoDnMinResis_C)
    && (rtb_Switch1_aw <= WinCtl_DrvPsgWinAutoDnMaxResis_C));

  /* Chart: '<S169>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S169>/Constant10'
   *  Constant: '<S169>/Constant16'
   *  Constant: '<S169>/Constant9'
   */
  if (rtb_LogicalOperator1_ey) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gj >= (float32)
         WinCtl_DrvPsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gj++;
      AppSwcBcm_ARID_DEF.cnt_heal_ig = (uint16)((float32)
        WinCtl_DrvPsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ig == 0) {
      WinCtl_DrvPsgWinAutoDnSw = false;
    } else if (WinCtl_DrvPsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ig--;
    }
  }

  /* End of Chart: '<S169>/LIB_TPD_10ms9' */
}

/* Output and update for atomic system: '<S12>/WinMotorProt' */
static void AppSwcBcm_WinMotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S170>/Logical Operator' incorporates:
   *  Constant: '<S170>/Constant'
   *  Constant: '<S170>/Constant4'
   *  RelationalOperator: '<S170>/Relational Operator'
   *  RelationalOperator: '<S170>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_mc = ((WinCtl_DrvWinSta == 4) || (WinCtl_DrvWinSta
    == 3));

  /* Chart: '<S170>/LIB_CntLimit1' incorporates:
   *  SubSystem: '<S188>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_mc,
    &AppSwcBcm_ARID_DEF.LogicalOperator_gf,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ieu);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_gf && (!WinCtl_DrvWinDnProt)) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_dh + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_dh + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_dh = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_j = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_j + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_j + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_j = (uint16)tmp;
  }

  /* Constant: '<S170>/Constant1' */
  if (AppSwcBcm_ARID_DEF.Cnt2_j >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_dh - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_dh - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_dh = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_j = 0U;
  }

  /* End of Constant: '<S170>/Constant1' */

  /* Constant: '<S170>/Constant2' */
  WinCtl_DrvWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_dh > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S170>/Relational Operator1' incorporates:
   *  Constant: '<S170>/Constant3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_js = (WinCtl_DrvWinSta == 2);

  /* Chart: '<S170>/LIB_CntLimit' incorporates:
   *  SubSystem: '<S187>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_js,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ku,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_oc);
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

  /* Constant: '<S170>/Constant14' */
  if (AppSwcBcm_ARID_DEF.Cnt2_ja >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_g5 - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_g5 - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_g5 = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_ja = 0U;
  }

  /* End of Constant: '<S170>/Constant14' */

  /* Constant: '<S170>/Constant15' */
  WinCtl_DrvWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_g5 > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S170>/Relational Operator4' incorporates:
   *  Constant: '<S170>/Constant10'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ik = (WinCtl_PsgWinSta == 2);

  /* Chart: '<S170>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S189>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ik,
    &AppSwcBcm_ARID_DEF.LogicalOperator_i3,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_k);
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

  /* Constant: '<S170>/Constant8' */
  if (AppSwcBcm_ARID_DEF.Cnt2_o0 >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ae - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ae - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_ae = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o0 = 0U;
  }

  /* End of Constant: '<S170>/Constant8' */

  /* Constant: '<S170>/Constant9' */
  WinCtl_PsgWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_ae > WinCtl_WinProtNum_C);

  /* Logic: '<S170>/Logical Operator1' incorporates:
   *  Constant: '<S170>/Constant11'
   *  Constant: '<S170>/Constant7'
   *  RelationalOperator: '<S170>/Relational Operator3'
   *  RelationalOperator: '<S170>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_kb = ((WinCtl_PsgWinSta == 4) || (WinCtl_PsgWinSta
    == 3));

  /* Chart: '<S170>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S190>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kb,
    &AppSwcBcm_ARID_DEF.LogicalOperator_fw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ox);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_fw && (!WinCtl_PsgWinDnProt)) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_no + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_no + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_no = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_o + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_o + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_o = (uint16)tmp;
  }

  /* Constant: '<S170>/Constant5' */
  if (AppSwcBcm_ARID_DEF.Cnt2_o >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_no - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_no - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_no = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  }

  /* End of Constant: '<S170>/Constant5' */

  /* Constant: '<S170>/Constant6' */
  WinCtl_PsgWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_no > WinCtl_WinProtNum_C);
}

/*
 * Output and update for function-call system:
 *    '<S199>/Lib_RiseEdgeDet'
 *    '<S199>/Lib_RiseEdgeDet1'
 *    '<S200>/Lib_RiseEdgeDet'
 *    '<S203>/Lib_RiseEdgeDet'
 *    '<S203>/Lib_RiseEdgeDet1'
 *    '<S627>/Lib_RiseEdgeDet'
 *    '<S628>/Lib_RiseEdgeDet'
 */
static void AppSwcBcm_Lib_RiseEdgeDet_n(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_j_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S218>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S218>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S171>/Chart6'
 *    '<S171>/Chart7'
 *    '<S171>/Chart8'
 *    '<S171>/Chart9'
 */
static void AppSwcBcm_Chart6_Init(boolean *rty_Lib_Out)
{
  *rty_Lib_Out = false;
}

/*
 * Output and update for atomic system:
 *    '<S171>/Chart6'
 *    '<S171>/Chart7'
 *    '<S171>/Chart8'
 *    '<S171>/Chart9'
 */
static void AppSwcBcm_Chart6(boolean rtu_Lib_blIn1, boolean rtu_Lib_blIn2, uint8
  rtu_Lib_blIn3, boolean *rty_Lib_Out, ARID_DEF_Chart6_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S171>/Chart6' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c20_WinCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c20_WinCtl_Lib = 1U;
    AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  } else if (AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_Lib_blIn1;

    /* Outputs for Function Call SubSystem: '<S208>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

    /* End of Outputs for SubSystem: '<S208>/Lib_RiseEdgeDet' */
    if (AppSwcBcm__ARID_DEF_arg->LogicalOperator && (!rtu_Lib_blIn2)) {
      AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib = AppSwcBcm_IN_On;
      *rty_Lib_Out = true;
    }

    /* case IN_On: */
  } else if ((!rtu_Lib_blIn1) || rtu_Lib_blIn2 || (rtu_Lib_blIn3 == 0)) {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_Lib_blIn1;

    /* Outputs for Function Call SubSystem: '<S208>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

    /* End of Outputs for SubSystem: '<S208>/Lib_RiseEdgeDet' */
    AppSwcBcm__ARID_DEF_arg->is_c20_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  }

  /* End of Chart: '<S171>/Chart6' */
}

/*
 * System initialize for atomic system:
 *    '<S171>/LIB_NegPluse'
 *    '<S377>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S171>/LIB_NegPluse'
 *    '<S377>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_NegPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S171>/LIB_NegPluse' */
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

  /* End of Chart: '<S171>/LIB_NegPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S171>/LIB_PosPluse'
 *    '<S652>/LIB_Tim'
 *    '<S900>/LIB_Tim'
 *    '<S917>/LIB_PosPluse'
 *    '<S921>/LIB_PosPluse'
 *    '<S921>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S171>/LIB_PosPluse'
 *    '<S652>/LIB_Tim'
 *    '<S900>/LIB_Tim'
 *    '<S917>/LIB_PosPluse'
 *    '<S921>/LIB_PosPluse'
 *    '<S921>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_PosPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S171>/LIB_PosPluse' */
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

  /* End of Chart: '<S171>/LIB_PosPluse' */
}

/* System initialize for atomic system: '<S12>/WinSwArb' */
static void AppSwcBcm_WinSwArb_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_g;
  boolean rtb_LIB_blOut_c;

  /* SystemInitialize for Chart: '<S171>/Chart6' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_k);

  /* SystemInitialize for Chart: '<S171>/Chart7' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_o);

  /* SystemInitialize for Chart: '<S171>/Chart8' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_h);

  /* SystemInitialize for Chart: '<S171>/Chart9' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out);

  /* SystemInitialize for Chart: '<S171>/LIB_NegPluse' */
  AppSwcBcm_LIB_NegPluse_Init(&rtb_LIB_blOut_c);

  /* SystemInitialize for Chart: '<S171>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_g);
}

/* Output and update for atomic system: '<S12>/WinSwArb' */
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
  boolean rtb_LogicalOperator3_om;
  boolean rtb_LogicalOperator42;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator_bc;
  boolean rtb_UnitDelay1;

  /* Logic: '<S171>/Logical Operator20' incorporates:
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_LogicalOperator20 = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_o ||
    WinCtl_DrvWinUpSw || WinCtl_DrvWinAutoDnSw);

  /* Chart: '<S171>/Chart2' incorporates:
   *  UnitDelay: '<S171>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c11_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_DrvWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib == AppSwcBcm_IN_Off_at) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kqc = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S204>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kqc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_l5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_af2);

    /* End of Outputs for SubSystem: '<S204>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_l5 && (!rtb_LogicalOperator20) &&
        (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_On_h;
      WinCtl_DrvWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinDnSw) || rtb_LogicalOperator20 || (WinCtl_DrvWinReq ==
              0)) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kqc = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S204>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kqc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_l5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_af2);

    /* End of Outputs for SubSystem: '<S204>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.is_c11_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_DrvWinDnReq = false;
  }

  /* End of Chart: '<S171>/Chart2' */

  /* Logic: '<S171>/Logical Operator19' incorporates:
   *  UnitDelay: '<S12>/Unit Delay1'
   */
  rtb_LogicalOperator20 = (WinCtl_DrvWinUpSw ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_o);

  /* Chart: '<S171>/Chart10' incorporates:
   *  UnitDelay: '<S171>/Unit Delay9'
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

        /* Outputs for Function Call SubSystem: '<S200>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pt);

        /* End of Outputs for SubSystem: '<S200>/Lib_RiseEdgeDet' */
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_d;
        WinCtl_DrvWinAutoDnReq = false;
      }
      break;

     case AppSwcBcm_IN_Off_d:
      AppSwcBcm_ARID_DEF.Lib_blIn_ac = WinCtl_DrvWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S200>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pt);

      /* End of Outputs for SubSystem: '<S200>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jm && (!rtb_LogicalOperator20)) {
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_HoldOn;
        WinCtl_DrvWinAutoDnReq = true;
      }
      break;

     default:
      /* case IN_On: */
      AppSwcBcm_ARID_DEF.Lib_blIn_ac = WinCtl_DrvWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S200>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ac,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pt);

      /* End of Outputs for SubSystem: '<S200>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jm || (WinCtl_DrvWinReq == 0) ||
          rtb_LogicalOperator20 || WinCtl_DrvWinDnSw) {
        AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_d;
        WinCtl_DrvWinAutoDnReq = false;
      }
      break;
    }
  }

  /* End of Chart: '<S171>/Chart10' */

  /* Logic: '<S171>/Logical Operator21' incorporates:
   *  UnitDelay: '<S12>/Unit Delay3'
   */
  rtb_LogicalOperator20 = (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_d ||
    WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnSw);

  /* Chart: '<S171>/Chart3' incorporates:
   *  UnitDelay: '<S171>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c12_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c12_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_DrvWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib == AppSwcBcm_IN_Off_at) {
    AppSwcBcm_ARID_DEF.Lib_blIn_gc = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S205>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_gc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fgp,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_da);

    /* End of Outputs for SubSystem: '<S205>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fgp && (!rtb_LogicalOperator20) &&
        (WinCtl_DrvWinReq == 0)) {
      AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib = AppSwcBcm_IN_On_h;
      WinCtl_DrvWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinUpSw) || rtb_LogicalOperator20 || (WinCtl_DrvWinReq ==
              0)) {
    AppSwcBcm_ARID_DEF.Lib_blIn_gc = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S205>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_gc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fgp,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_da);

    /* End of Outputs for SubSystem: '<S205>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.is_c12_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_DrvWinUpReq = false;
  }

  /* End of Chart: '<S171>/Chart3' */

  /* Switch: '<S171>/Switch' incorporates:
   *  Switch: '<S171>/Switch1'
   */
  if (WinCtl_DrvWinDnReq) {
    /* Switch: '<S171>/Switch' incorporates:
     *  Constant: '<S171>/Constant'
     */
    rtb_Switch = 2U;
  } else if (WinCtl_DrvWinAutoDnReq) {
    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S171>/Constant1'
     *  Switch: '<S171>/Switch'
     */
    rtb_Switch = 3U;
  } else {
    /* Switch: '<S171>/Switch' incorporates:
     *  Switch: '<S171>/Switch1'
     *  Switch: '<S171>/Switch2'
     */
    rtb_Switch = WinCtl_DrvWinUpReq;
  }

  /* End of Switch: '<S171>/Switch' */

  /* RelationalOperator: '<S171>/Relational Operator4' incorporates:
   *  Constant: '<S171>/Constant19'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator20 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S171>/Relational Operator' incorporates:
   *  Constant: '<S171>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S171>/Relational Operator5'
   */
  rtb_RelationalOperator_bc = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 0);

  /* UnitDelay: '<S171>/Unit Delay1' incorporates:
   *  Constant: '<S171>/Constant31'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S171>/Relational Operator6'
   */
  rtb_UnitDelay1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())
                    ->BodyWarnSts == 3);

  /* Chart: '<S171>/LIB_NegPluse' incorporates:
   *  Constant: '<S171>/Constant20'
   *  Logic: '<S171>/Logical Operator12'
   *  Logic: '<S171>/Logical Operator17'
   */
  AppSwcBcm_LIB_NegPluse(rtb_LogicalOperator20 && (rtb_RelationalOperator_bc ||
    rtb_UnitDelay1), WinCtl_PwrOffWinValidTimMax_C, &rtb_LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse);

  /* UnitDelay: '<S171>/Unit Delay1' incorporates:
   *  Constant: '<S171>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S171>/Relational Operator3'
   */
  rtb_UnitDelay1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
                    ->SysPwrMode == 2);

  /* Logic: '<S171>/Logical Operator5' */
  rtb_LogicalOperator20 = (rtb_UnitDelay1 || rtb_LIB_blOut_c);

  /* UnitDelay: '<S171>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S171>/Relational Operator2'
   */
  rtb_UnitDelay1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
                    ->SysPwrMode == 0);

  /* RelationalOperator: '<S171>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S171>/Relational Operator11'
   */
  rtb_RelationalOperator_bc = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 5);

  /* Logic: '<S171>/Logical Operator9' */
  rtb_LogicalOperator9 = (rtb_UnitDelay1 && rtb_RelationalOperator_bc);

  /* Chart: '<S171>/Chart6' incorporates:
   *  Logic: '<S171>/Logical Operator13'
   *  UnitDelay: '<S12>/Unit Delay1'
   *  UnitDelay: '<S171>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, WinCtl_DrvWinUpSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_o || WinCtl_DrvWinDnSw ||
                   WinCtl_DrvWinAutoDnSw, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_k,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart6);

  /* RelationalOperator: '<S171>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_bc = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 6);

  /* Logic: '<S171>/Logical Operator3' */
  rtb_LogicalOperator3_om = (rtb_UnitDelay1 && rtb_RelationalOperator_bc);

  /* Chart: '<S171>/Chart7' incorporates:
   *  Logic: '<S171>/Logical Operator14'
   *  UnitDelay: '<S12>/Unit Delay3'
   *  UnitDelay: '<S171>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_om, WinCtl_DrvWinDnSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_d ||
                   WinCtl_DrvWinAutoDnSw || WinCtl_DrvWinUpSw, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_o,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart7);

  /* Chart: '<S171>/LIB_PosPluse' incorporates:
   *  Constant: '<S171>/Constant40'
   *  Logic: '<S171>/Logical Operator10'
   */
  AppSwcBcm_LIB_PosPluse(WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnReq ||
    WinCtl_DrvWinUpSw || rtb_LogicalOperator9 || rtb_LogicalOperator3_om,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_f);

  /* Chart: '<S171>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S171>/Constant34'
   *  Constant: '<S171>/Constant35'
   *  Constant: '<S171>/Constant36'
   *  Constant: '<S171>/Constant37'
   *  RelationalOperator: '<S171>/Relational Operator9'
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

  /* End of Chart: '<S171>/LIB_TPD_10ms3' */

  /* Switch: '<S171>/Switch11' incorporates:
   *  Constant: '<S171>/Constant25'
   *  Logic: '<S171>/Logical Operator6'
   *  Logic: '<S171>/Logical Operator8'
   *  Switch: '<S171>/Switch8'
   */
  if (WinCtl_DrvWinMotorLocked || rtb_LIB_blOut_g) {
    WinCtl_DrvWinReq = 0U;
  } else {
    if (rtb_LogicalOperator20) {
      /* Switch: '<S171>/Switch8' */
      tmp_0 = rtb_Switch;
    } else {
      /* Switch: '<S171>/Switch8' incorporates:
       *  Constant: '<S171>/Constant32'
       */
      tmp_0 = 0U;
    }

    /* Switch: '<S171>/Switch7' incorporates:
     *  Switch: '<S171>/Switch12'
     *  Switch: '<S171>/Switch8'
     */
    if (tmp_0 != 0) {
      /* Switch: '<S171>/Switch7' */
      WinCtl_DrvWinReq = rtb_Switch;
    } else if (AppSwcBcm_ARID_DEF.Lib_Out_k) {
      /* Switch: '<S171>/Switch12' incorporates:
       *  Constant: '<S171>/Constant43'
       */
      WinCtl_DrvWinReq = 2U;
    } else {
      /* Switch: '<S171>/Switch12' incorporates:
       *  Switch: '<S171>/Switch3'
       */
      WinCtl_DrvWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_o;
    }

    /* End of Switch: '<S171>/Switch7' */
  }

  /* End of Switch: '<S171>/Switch11' */

  /* Chart: '<S171>/Chart8' incorporates:
   *  Logic: '<S171>/Logical Operator16'
   *  UnitDelay: '<S12>/Unit Delay2'
   *  UnitDelay: '<S171>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_om, WinCtl_PsgWinAutoDnSw ||
                   WinCtl_PsgWinDnSw || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e ||
                   WinCtl_PsgWinUpSw || WinCtl_DrvPsgWinAutoDnSw ||
                   WinCtl_DrvPsgWinUpSw || WinCtl_DrvPsgWinDnSw,
                   WinCtl_PsgWinReq, &AppSwcBcm_ARID_DEF.Lib_Out_h,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart8);

  /* Chart: '<S171>/Chart9' incorporates:
   *  Logic: '<S171>/Logical Operator15'
   *  UnitDelay: '<S12>/Unit Delay4'
   *  UnitDelay: '<S171>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, WinCtl_PsgWinUpSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i ||
                   WinCtl_PsgWinAutoDnSw || WinCtl_PsgWinDnSw ||
                   WinCtl_DrvPsgWinAutoDnSw || WinCtl_DrvPsgWinUpSw ||
                   WinCtl_DrvPsgWinDnSw, WinCtl_PsgWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart9);

  /* Chart: '<S171>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S171>/Constant10'
   *  Constant: '<S171>/Constant11'
   *  Constant: '<S171>/Constant44'
   *  Constant: '<S171>/Constant48'
   *  RelationalOperator: '<S171>/Relational Operator7'
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

  /* End of Chart: '<S171>/LIB_TPD_10ms1' */

  /* Logic: '<S171>/Logical Operator18' incorporates:
   *  Logic: '<S171>/Logical Operator26'
   *  UnitDelay: '<S12>/Unit Delay4'
   *  UnitDelay: '<S171>/Unit Delay'
   */
  rtb_LogicalOperator22 = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i ||
    WinCtl_DrvPsgWinOvTimProt || WinCtl_PsgWinMotorLocked);

  /* Logic: '<S171>/Logical Operator25' incorporates:
   *  UnitDelay: '<S12>/Unit Delay4'
   *  UnitDelay: '<S171>/Unit Delay2'
   */
  rtb_UnitDelay1 = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i ||
                    WinCtl_PsgWinMotorLocked || WinCtl_PsgWinOvTimProt);

  /* Logic: '<S171>/Logical Operator33' incorporates:
   *  Logic: '<S171>/Logical Operator30'
   *  Logic: '<S171>/Logical Operator31'
   */
  rtb_RelationalOperator_bc = (WinCtl_DrvPsgWinUpSw || WinCtl_DrvPsgWinAutoDnSw ||
    WinCtl_DrvPsgWinDnSw);

  /* Logic: '<S171>/Logical Operator42' incorporates:
   *  Logic: '<S171>/Logical Operator33'
   *  Logic: '<S171>/Logical Operator41'
   *  UnitDelay: '<S171>/Unit Delay5'
   */
  rtb_LogicalOperator42 = (rtb_RelationalOperator_bc &&
    (!WinCtl_DrvPsgWinOvTimProt));

  /* Chart: '<S171>/Chart1' */
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

        /* Outputs for Function Call SubSystem: '<S199>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_he,
          &AppSwcBcm_ARID_DEF.LogicalOperator_lc,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

        /* End of Outputs for SubSystem: '<S199>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_lc || rtb_UnitDelay1) {
          AppSwcBcm_ARID_DEF.Lib_blIn_ao = WinCtl_PsgWinAutoDnSw;

          /* Outputs for Function Call SubSystem: '<S199>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ao,
            &AppSwcBcm_ARID_DEF.LogicalOperator_b0,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ie);

          /* End of Outputs for SubSystem: '<S199>/Lib_RiseEdgeDet' */
          AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_d;
          WinCtl_PsgWinAutoDnReq = false;
        }
      }
      break;

     case AppSwcBcm_IN_Off_d:
      AppSwcBcm_ARID_DEF.Lib_blIn_ao = WinCtl_PsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S199>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ao,
        &AppSwcBcm_ARID_DEF.LogicalOperator_b0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ie);

      /* End of Outputs for SubSystem: '<S199>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_b0 && (!rtb_UnitDelay1) &&
          (!rtb_LogicalOperator42)) {
        AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_HoldOn;
        WinCtl_PsgWinAutoDnReq = true;
      }
      break;

     default:
      /* case IN_On: */
      AppSwcBcm_ARID_DEF.Lib_blIn_ao = WinCtl_PsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S199>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ao,
        &AppSwcBcm_ARID_DEF.LogicalOperator_b0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ie);

      /* End of Outputs for SubSystem: '<S199>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_b0) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_he = rtb_LogicalOperator42;

        /* Outputs for Function Call SubSystem: '<S199>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_he,
          &AppSwcBcm_ARID_DEF.LogicalOperator_lc,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

        /* End of Outputs for SubSystem: '<S199>/Lib_RiseEdgeDet1' */
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

  /* End of Chart: '<S171>/Chart1' */

  /* Logic: '<S171>/Logical Operator40' incorporates:
   *  Logic: '<S171>/Logical Operator34'
   *  Logic: '<S171>/Logical Operator39'
   *  UnitDelay: '<S171>/Unit Delay4'
   */
  rtb_UnitDelay1 = ((WinCtl_PsgWinUpSw || WinCtl_PsgWinAutoDnSw ||
                     WinCtl_PsgWinDnSw) && (!WinCtl_PsgWinOvTimProt));

  /* Chart: '<S171>/Chart13' */
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

        /* Outputs for Function Call SubSystem: '<S203>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ju,
          &AppSwcBcm_ARID_DEF.LogicalOperator_bi,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

        /* End of Outputs for SubSystem: '<S203>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_bi || rtb_LogicalOperator22) {
          AppSwcBcm_ARID_DEF.Lib_blIn_nq = WinCtl_DrvPsgWinAutoDnSw;

          /* Outputs for Function Call SubSystem: '<S203>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_nq,
            &AppSwcBcm_ARID_DEF.LogicalOperator_j2,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ms);

          /* End of Outputs for SubSystem: '<S203>/Lib_RiseEdgeDet' */
          AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_Off_d;
          WinCtl_DrvPsgWinAutoDnReq = false;
        }
      }
      break;

     case AppSwcBcm_IN_Off_d:
      AppSwcBcm_ARID_DEF.Lib_blIn_nq = WinCtl_DrvPsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S203>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_nq,
        &AppSwcBcm_ARID_DEF.LogicalOperator_j2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ms);

      /* End of Outputs for SubSystem: '<S203>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_j2 && (!rtb_LogicalOperator22) && (
           !rtb_UnitDelay1)) {
        AppSwcBcm_ARID_DEF.is_c10_WinCtl_Lib = AppSwcBcm_IN_HoldOn;
        WinCtl_DrvPsgWinAutoDnReq = true;
      }
      break;

     default:
      /* case IN_On: */
      AppSwcBcm_ARID_DEF.Lib_blIn_nq = WinCtl_DrvPsgWinAutoDnSw;

      /* Outputs for Function Call SubSystem: '<S203>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_nq,
        &AppSwcBcm_ARID_DEF.LogicalOperator_j2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ms);

      /* End of Outputs for SubSystem: '<S203>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_j2) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ju = rtb_UnitDelay1;

        /* Outputs for Function Call SubSystem: '<S203>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_ju,
          &AppSwcBcm_ARID_DEF.LogicalOperator_bi,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

        /* End of Outputs for SubSystem: '<S203>/Lib_RiseEdgeDet1' */
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

  /* End of Chart: '<S171>/Chart13' */

  /* Logic: '<S171>/Logical Operator1' */
  rtb_UnitDelay1 = (WinCtl_PsgWinAutoDnReq || WinCtl_DrvPsgWinAutoDnReq);

  /* Chart: '<S171>/LIB_PosPluse1' incorporates:
   *  Constant: '<S171>/Constant8'
   *  Logic: '<S171>/Logical Operator11'
   */
  if (WinCtl_PsgWinUpSw || WinCtl_PsgWinDnSw || rtb_UnitDelay1 ||
      rtb_LogicalOperator9 || rtb_LogicalOperator3_om) {
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

  /* End of Chart: '<S171>/LIB_PosPluse1' */

  /* Logic: '<S171>/Logical Operator46' incorporates:
   *  Logic: '<S171>/Logical Operator29'
   *  Logic: '<S171>/Logical Operator45'
   */
  rtb_LogicalOperator42 = ((WinCtl_PsgWinAutoDnSw || WinCtl_PsgWinUpSw ||
    WinCtl_PsgWinDnSw) && (!WinCtl_PsgWinOvTimProt));

  /* Chart: '<S171>/Chart11' incorporates:
   *  Logic: '<S171>/Logical Operator18'
   *  UnitDelay: '<S171>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c8_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_DrvPsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib == AppSwcBcm_IN_Off_at) {
    AppSwcBcm_ARID_DEF.Lib_blIn_in = WinCtl_DrvPsgWinDnSw;

    /* Outputs for Function Call SubSystem: '<S201>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_in,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ne,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pe);

    /* End of Outputs for SubSystem: '<S201>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ne && (!rtb_LogicalOperator22) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_cd = rtb_LogicalOperator42;

      /* Outputs for Function Call SubSystem: '<S201>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cd,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_lu);

      /* End of Outputs for SubSystem: '<S201>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_On_h;
      WinCtl_DrvPsgWinDnReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_DrvPsgWinDnSw) || rtb_LogicalOperator22) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_cd = rtb_LogicalOperator42;

      /* Outputs for Function Call SubSystem: '<S201>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cd,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_lu);

      /* End of Outputs for SubSystem: '<S201>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_mp || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_in = WinCtl_DrvPsgWinDnSw;

      /* Outputs for Function Call SubSystem: '<S201>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_in,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ne,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pe);

      /* End of Outputs for SubSystem: '<S201>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c8_WinCtl_Lib = AppSwcBcm_IN_Off_at;
      WinCtl_DrvPsgWinDnReq = false;
    }
  }

  /* End of Chart: '<S171>/Chart11' */

  /* Logic: '<S171>/Logical Operator22' incorporates:
   *  UnitDelay: '<S12>/Unit Delay4'
   *  UnitDelay: '<S171>/Unit Delay1'
   */
  rtb_LogicalOperator22 = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_bt || WinCtl_PsgWinMotorLocked);

  /* Chart: '<S171>/LIB_PosPluse2' incorporates:
   *  Constant: '<S171>/Constant47'
   *  Logic: '<S171>/Logical Operator27'
   */
  if (WinCtl_DrvPsgWinDnSw || WinCtl_DrvPsgWinUpSw || rtb_UnitDelay1 ||
      rtb_LogicalOperator9 || rtb_LogicalOperator3_om) {
    if (AppSwcBcm_ARID_DEF.Cnt_g <= WinCtl_WinRunTimMax_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_g + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_g + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_g = (uint16)tmp;
      WinCtl_DrvPsgWinOvTimProt = false;
    } else {
      WinCtl_DrvPsgWinOvTimProt = true;
    }
  } else {
    WinCtl_DrvPsgWinOvTimProt = false;
    AppSwcBcm_ARID_DEF.Cnt_g = 0U;
  }

  /* End of Chart: '<S171>/LIB_PosPluse2' */

  /* Logic: '<S171>/Logical Operator44' incorporates:
   *  Logic: '<S171>/Logical Operator43'
   */
  rtb_LogicalOperator9 = (rtb_RelationalOperator_bc &&
    (!WinCtl_DrvPsgWinOvTimProt));

  /* Chart: '<S171>/Chart4' incorporates:
   *  UnitDelay: '<S171>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_PsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib == AppSwcBcm_IN_Off_at) {
    AppSwcBcm_ARID_DEF.Lib_blIn_p0n = WinCtl_PsgWinDnSw;

    /* Outputs for Function Call SubSystem: '<S206>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_p0n,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ax,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ax);

    /* End of Outputs for SubSystem: '<S206>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ax && (!rtb_LogicalOperator22) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_id4 = rtb_LogicalOperator9;

      /* Outputs for Function Call SubSystem: '<S206>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_id4,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jx,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

      /* End of Outputs for SubSystem: '<S206>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_On_h;
      WinCtl_PsgWinDnReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_PsgWinDnSw) || rtb_LogicalOperator22) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_id4 = rtb_LogicalOperator9;

      /* Outputs for Function Call SubSystem: '<S206>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_id4,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jx,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

      /* End of Outputs for SubSystem: '<S206>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jx || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_p0n = WinCtl_PsgWinDnSw;

      /* Outputs for Function Call SubSystem: '<S206>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_p0n,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ax,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ax);

      /* End of Outputs for SubSystem: '<S206>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off_at;
      WinCtl_PsgWinDnReq = false;
    }
  }

  /* End of Chart: '<S171>/Chart4' */

  /* Logic: '<S171>/Logical Operator2' incorporates:
   *  UnitDelay: '<S12>/Unit Delay2'
   */
  rtb_LogicalOperator9 = (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e ||
    WinCtl_DrvPsgWinOvTimProt || WinCtl_PsgWinMotorLocked);

  /* Logic: '<S171>/Logical Operator37' incorporates:
   *  Logic: '<S171>/Logical Operator32'
   *  Logic: '<S171>/Logical Operator38'
   */
  rtb_LogicalOperator3_om = ((WinCtl_PsgWinDnSw || WinCtl_PsgWinAutoDnSw ||
    WinCtl_PsgWinUpSw) && (!WinCtl_PsgWinOvTimProt));

  /* Chart: '<S171>/Chart12' incorporates:
   *  UnitDelay: '<S171>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c9_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_DrvPsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib == AppSwcBcm_IN_Off_at) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ly = WinCtl_DrvPsgWinUpSw;

    /* Outputs for Function Call SubSystem: '<S202>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ly,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ln,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

    /* End of Outputs for SubSystem: '<S202>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ln && (!rtb_LogicalOperator9) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_gw = rtb_LogicalOperator3_om;

      /* Outputs for Function Call SubSystem: '<S202>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_gw,
        &AppSwcBcm_ARID_DEF.LogicalOperator_a2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_o3);

      /* End of Outputs for SubSystem: '<S202>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_On_h;
      WinCtl_DrvPsgWinUpReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_DrvPsgWinUpSw) || rtb_LogicalOperator9) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_gw = rtb_LogicalOperator3_om;

      /* Outputs for Function Call SubSystem: '<S202>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_gw,
        &AppSwcBcm_ARID_DEF.LogicalOperator_a2,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_o3);

      /* End of Outputs for SubSystem: '<S202>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_a2 || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_ly = WinCtl_DrvPsgWinUpSw;

      /* Outputs for Function Call SubSystem: '<S202>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ly,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ln,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

      /* End of Outputs for SubSystem: '<S202>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c9_WinCtl_Lib = AppSwcBcm_IN_Off_at;
      WinCtl_DrvPsgWinUpReq = false;
    }
  }

  /* End of Chart: '<S171>/Chart12' */

  /* Logic: '<S171>/Logical Operator23' incorporates:
   *  UnitDelay: '<S12>/Unit Delay2'
   */
  rtb_LogicalOperator9 = (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e ||
    WinCtl_PsgWinOvTimProt || WinCtl_PsgWinMotorLocked);

  /* Logic: '<S171>/Logical Operator35' incorporates:
   *  Logic: '<S171>/Logical Operator36'
   */
  rtb_RelationalOperator_bc = (rtb_RelationalOperator_bc &&
    (!WinCtl_DrvPsgWinOvTimProt));

  /* Chart: '<S171>/Chart5' incorporates:
   *  UnitDelay: '<S171>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off_at;
    WinCtl_PsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib == AppSwcBcm_IN_Off_at) {
    AppSwcBcm_ARID_DEF.Lib_blIn_jl = WinCtl_PsgWinUpSw;

    /* Outputs for Function Call SubSystem: '<S207>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_jl,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ltp,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ei);

    /* End of Outputs for SubSystem: '<S207>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ltp && (!rtb_LogicalOperator9) &&
        (WinCtl_PsgWinReq == 0)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_k2w = rtb_RelationalOperator_bc;

      /* Outputs for Function Call SubSystem: '<S207>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_k2w,
        &AppSwcBcm_ARID_DEF.LogicalOperator_iy,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_h2);

      /* End of Outputs for SubSystem: '<S207>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_On_h;
      WinCtl_PsgWinUpReq = true;
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((!WinCtl_PsgWinUpSw) || rtb_LogicalOperator9) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_k2w = rtb_RelationalOperator_bc;

      /* Outputs for Function Call SubSystem: '<S207>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_k2w,
        &AppSwcBcm_ARID_DEF.LogicalOperator_iy,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_h2);

      /* End of Outputs for SubSystem: '<S207>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_iy || (WinCtl_PsgWinReq == 0)) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_jl = WinCtl_PsgWinUpSw;

      /* Outputs for Function Call SubSystem: '<S207>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_jl,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ltp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ei);

      /* End of Outputs for SubSystem: '<S207>/Lib_RiseEdgeDet' */
      AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off_at;
      WinCtl_PsgWinUpReq = false;
    }
  }

  /* End of Chart: '<S171>/Chart5' */

  /* Switch: '<S171>/Switch4' incorporates:
   *  Logic: '<S171>/Logical Operator'
   *  Switch: '<S171>/Switch5'
   */
  if (WinCtl_DrvPsgWinDnReq || WinCtl_PsgWinDnReq) {
    /* Switch: '<S171>/Switch4' incorporates:
     *  Constant: '<S171>/Constant12'
     */
    WinCtl_PsgWinReq = 2U;
  } else if (rtb_UnitDelay1) {
    /* Switch: '<S171>/Switch5' incorporates:
     *  Constant: '<S171>/Constant13'
     *  Switch: '<S171>/Switch4'
     */
    WinCtl_PsgWinReq = 3U;
  } else {
    /* Switch: '<S171>/Switch4' incorporates:
     *  Logic: '<S171>/Logical Operator24'
     *  Switch: '<S171>/Switch5'
     */
    WinCtl_PsgWinReq = (uint8)(WinCtl_PsgWinUpReq || WinCtl_DrvPsgWinUpReq);
  }

  /* End of Switch: '<S171>/Switch4' */

  /* Switch: '<S171>/Switch10' incorporates:
   *  Constant: '<S171>/Constant27'
   *  Logic: '<S171>/Logical Operator28'
   *  Logic: '<S171>/Logical Operator4'
   *  Logic: '<S171>/Logical Operator7'
   *  Switch: '<S171>/Switch9'
   */
  if (WinCtl_PsgWinMotorLocked || (WinCtl_PsgWinOvTimProt &&
       WinCtl_DrvPsgWinOvTimProt)) {
    WinCtl_PsgWinReq = 0U;
  } else {
    if (rtb_LogicalOperator20) {
      /* Switch: '<S171>/Switch9' */
      tmp_0 = WinCtl_PsgWinReq;
    } else {
      /* Switch: '<S171>/Switch9' incorporates:
       *  Constant: '<S171>/Constant33'
       */
      tmp_0 = 0U;
    }

    /* Switch: '<S171>/Switch13' incorporates:
     *  Switch: '<S171>/Switch9'
     */
    if (tmp_0 == 0) {
      /* Switch: '<S171>/Switch14' */
      if (AppSwcBcm_ARID_DEF.Lib_Out) {
        /* Switch: '<S171>/Switch14' incorporates:
         *  Constant: '<S171>/Constant16'
         */
        WinCtl_PsgWinReq = 2U;
      } else {
        /* Switch: '<S171>/Switch14' incorporates:
         *  Switch: '<S171>/Switch15'
         */
        WinCtl_PsgWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_h;
      }

      /* End of Switch: '<S171>/Switch14' */
    }

    /* End of Switch: '<S171>/Switch13' */
  }

  /* End of Switch: '<S171>/Switch10' */

  /* Update for UnitDelay: '<S171>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_bt = WinCtl_PsgWinOvTimProt;
}

/* System initialize for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S12>/WinSwArb' */
  AppSwcBcm_WinSwArb_Init();

  /* End of SystemInitialize for SubSystem: '<S12>/WinSwArb' */
}

/* Output and update for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl(void)
{
  /* Outputs for Atomic SubSystem: '<S12>/SigProc' */
  AppSwcBcm_SigProc();

  /* End of Outputs for SubSystem: '<S12>/SigProc' */

  /* Outputs for Atomic SubSystem: '<S12>/WinSwArb' */
  AppSwcBcm_WinSwArb();

  /* End of Outputs for SubSystem: '<S12>/WinSwArb' */

  /* Chart: '<S12>/DrvWinCtl' */
  AppSwcBcm_DrvWinCtl();

  /* Outputs for Atomic SubSystem: '<S12>/Ovrd4' */
  /* Switch: '<S166>/Switch1' incorporates:
   *  Constant: '<S12>/Constant1'
   */
  if (WinCtl_J53DrvWinDnOvrdFlg_C) {
    /* Switch: '<S166>/Switch1' incorporates:
     *  Constant: '<S12>/Constant2'
     */
    WinCtl_J53DrvWinDn = WinCtl_J53DrvWinDnOvrdVal_C;
  } else {
    /* Switch: '<S166>/Switch1' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion1'
     *  Switch: '<S166>/Switch2'
     */
    WinCtl_J53DrvWinDn = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFLOpenFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J53);
  }

  /* End of Switch: '<S166>/Switch1' */
  /* End of Outputs for SubSystem: '<S12>/Ovrd4' */

  /* Chart: '<S12>/PsgWinCtl' */
  AppSwcBcm_PsgWinCtl();

  /* Outputs for Atomic SubSystem: '<S12>/WinMotorProt' */
  AppSwcBcm_WinMotorProt();

  /* End of Outputs for SubSystem: '<S12>/WinMotorProt' */

  /* Outputs for Atomic SubSystem: '<S12>/Ovrd2' */
  /* Switch: '<S165>/Switch1' incorporates:
   *  Constant: '<S12>/Constant5'
   */
  if (WinCtl_J57PsgWinDnOvrdFlg_C) {
    /* Switch: '<S165>/Switch1' incorporates:
     *  Constant: '<S12>/Constant6'
     */
    WinCtl_J57PsgWinDn = WinCtl_J57PsgWinDnOvrdVal_C;
  } else {
    /* Switch: '<S165>/Switch1' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion3'
     *  Switch: '<S165>/Switch2'
     */
    WinCtl_J57PsgWinDn = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFROpenFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J57);
  }

  /* End of Switch: '<S165>/Switch1' */
  /* End of Outputs for SubSystem: '<S12>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S12>/Ovrd5' */
  /* Switch: '<S167>/Switch1' incorporates:
   *  Constant: '<S12>/Constant3'
   */
  if (WinCtl_J55PsgWinUpOvrdFlg_C) {
    /* Switch: '<S167>/Switch1' incorporates:
     *  Constant: '<S12>/Constant4'
     */
    WinCtl_J55PsgWinUp = WinCtl_J55PsgWinUpOvrdVal_C;
  } else {
    /* Switch: '<S167>/Switch1' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion2'
     *  Switch: '<S167>/Switch2'
     */
    WinCtl_J55PsgWinUp = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFRCloselFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J55);
  }

  /* End of Switch: '<S167>/Switch1' */
  /* End of Outputs for SubSystem: '<S12>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S12>/Ovrd1' */
  /* Switch: '<S164>/Switch1' incorporates:
   *  Constant: '<S12>/Constant18'
   */
  if (WinCtl_J51DrvWinUpOvrdFlg_C) {
    /* Switch: '<S164>/Switch1' incorporates:
     *  Constant: '<S12>/Constant19'
     */
    WinCtl_J51DrvWinUp = WinCtl_J51DrvWinUpOvrdVal_C;
  } else {
    /* Switch: '<S164>/Switch1' incorporates:
     *  DataTypeConversion: '<S12>/Data Type Conversion'
     *  Switch: '<S164>/Switch2'
     */
    WinCtl_J51DrvWinUp = ((AppSwcBcm_ARID_DEF.BusCreator16.WinFLCloselFlg != 0) ||
                          AppSwcBcm_ARID_DEF.WinCtl_J51);
  }

  /* End of Switch: '<S164>/Switch1' */
  /* End of Outputs for SubSystem: '<S12>/Ovrd1' */

  /* Update for UnitDelay: '<S12>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_d = WinCtl_DrvWinUpProt;

  /* Update for UnitDelay: '<S12>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e = WinCtl_PsgWinUpProt;

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_o = WinCtl_DrvWinDnProt;

  /* Update for UnitDelay: '<S12>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_i = WinCtl_PsgWinDnProt;
}

/* Outputs for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl(void)
{
  sint32 tmp;
  uint8 rtb_CCaller;
  boolean rtb_Compare_a;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator2_m4;
  boolean rtb_LogicalOperator4_m2;
  boolean rtb_LogicalOperator7_n;
  boolean rtb_RelationalOperator8_il;

  /* CCaller: '<S256>/C Caller' */
  rtb_CCaller = Get_PEAuth_FobStatus();

  /* Logic: '<S261>/Logical Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S259>/Logical Operator2'
   */
  rtb_LogicalOperator7_n = !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus()
    )->DrvSeatSw;

  /* RelationalOperator: '<S269>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S259>/Relational Operator'
   */
  rtb_Compare_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VGSM_VehActGearPstn_enum <= 1);

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S259>/Logical Operator'
   */
  rtb_LogicalOperator2_m4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarRRSw);

  /* Logic: '<S261>/Logical Operator7' incorporates:
   *  Logic: '<S259>/Logical Operator3'
   */
  rtb_LogicalOperator7_n = (rtb_LogicalOperator7_n && rtb_Compare_a &&
    rtb_LogicalOperator2_m4);

  /* Logic: '<S259>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S272>/Compare'
   *  UnitDelay: '<S259>/Unit Delay'
   */
  rtb_Compare_a = ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ksc) &&
                   (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw
                   && rtb_LogicalOperator7_n);

  /* Logic: '<S259>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S273>/Compare'
   *  UnitDelay: '<S259>/Unit Delay1'
   */
  rtb_LogicalOperator7_n = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cj) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw &&
    rtb_LogicalOperator7_n);

  /* Chart: '<S259>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
    PEPSCtl_DrvPEAuthentAcsd = 0U;
    PEPSCtl_KeyInCarSta = 0U;
    AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
    PEPSCtl_FRPEAuthentAcsd = 0U;
    AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
    AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
    Clear_PEStatus();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_k:
      if (rtb_Compare_a) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_LSeekKeyOut;
        Set_PEAuth_FobReq(1U);
        AppSwcBcm_ARID_DEF.count_p = 0U;
        AppSwcBcm_ARID_DEF.count1_j = 0U;
      } else if (rtb_LogicalOperator7_n) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_RSeekKeyOut;
        Set_PEAuth_FobReq(2U);
        AppSwcBcm_ARID_DEF.count_p = 0U;
        AppSwcBcm_ARID_DEF.count1_j = 0U;
      }
      break;

     case AppSwcBcm_IN_LSeekKeyOut:
      if ((AppSwcBcm_ARID_DEF.count_p >= 10) ||
          (AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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
          tmp = AppSwcBcm_ARID_DEF.count_p + 1;
          if (AppSwcBcm_ARID_DEF.count_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_p = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_p + 1;
          if (AppSwcBcm_ARID_DEF.count_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_p = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_p + 1;
          if (AppSwcBcm_ARID_DEF.count_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_p = (uint8)tmp;
        }

        if (rtb_CCaller == 0) {
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
      if ((AppSwcBcm_ARID_DEF.count_p >= 10) ||
          (AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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
          tmp = AppSwcBcm_ARID_DEF.count_p + 1;
          if (AppSwcBcm_ARID_DEF.count_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_p = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_p + 1;
          if (AppSwcBcm_ARID_DEF.count_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_p = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_p + 1;
          if (AppSwcBcm_ARID_DEF.count_p + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_p = (uint8)tmp;
        }

        if (rtb_CCaller == 0) {
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

  /* End of Chart: '<S259>/Chart' */

  /* Chart: '<S259>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
    AppSwcBcm_ARID_DEF.count_l = 0.0;
    PEPSCtl_AvaluebleKeyInCar = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib == AppSwcBcm_IN_Init_k) {
    PEPSCtl_AvaluebleKeyInCar = 0U;
    if (AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar == 1.0F) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_h;
      AppSwcBcm_ARID_DEF.count_l = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_AvaluebleKeyInCar = 1U;
    if (AppSwcBcm_ARID_DEF.count_l >= 1000.0) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
      AppSwcBcm_ARID_DEF.count_l = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count_l++;
    }
  }

  /* End of Chart: '<S259>/Chart3' */

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  Constant: '<S263>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S263>/Compare'
   */
  rtb_LogicalOperator2_m4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus()
    )->BodyWarnSts == 0);

  /* Logic: '<S257>/Logical Operator' incorporates:
   *  Constant: '<S264>/Constant'
   *  RelationalOperator: '<S264>/Compare'
   *  UnitDelay: '<S257>/Unit Delay'
   */
  rtb_LogicalOperator7_n = (rtb_LogicalOperator2_m4 &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c > 0));

  /* CCaller: '<S257>/C Caller1' */
  rtb_CCaller = Get_FobdKeyNum();

  /* Chart: '<S257>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib) {
     case AppSwcBcm_IN_FobidKey:
      if ((PEPSCtl_FrbdnKeyNr > 0) || (AppSwcBcm_ARID_DEF.count_n > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      } else if (rtb_LogicalOperator7_n) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_n = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_n + 1;
        if (AppSwcBcm_ARID_DEF.count_n + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_n = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     case AppSwcBcm_IN_Init_l:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->OsLckSta == 2) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_FobidKey;
        AppSwcBcm_ARID_DEF.count_n = 0U;
        Set_PSAuth_FobReq(2U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else if (rtb_LogicalOperator7_n) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_n = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     default:
      /* case IN_RelesKey: */
      if ((PEPSCtl_FrbdnKeyNr == 0) || (AppSwcBcm_ARID_DEF.count_n > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_n + 1;
        if (AppSwcBcm_ARID_DEF.count_n + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_n = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;
    }
  }

  /* End of Chart: '<S257>/Chart' */

  /* CCaller: '<S256>/C Caller1' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S260>/Relational Operator5'
   */
  rtb_LogicalOperator2_m4 = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())
    ->BrakeLightSw;

  /* Logic: '<S260>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S260>/Relational Operator4'
   *  UnitDelay: '<S260>/Unit Delay1'
   */
  rtb_LogicalOperator7_n = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m) &&
    rtb_LogicalOperator2_m4);

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S260>/Relational Operator2'
   */
  rtb_LogicalOperator2_m4 = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus()
    )->DrvSeatSw;

  /* RelationalOperator: '<S269>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S260>/Relational Operator3'
   */
  rtb_Compare_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S260>/Chart' incorporates:
   *  Logic: '<S260>/Logical Operator1'
   *  Logic: '<S260>/Logical Operator2'
   *  Logic: '<S260>/Logical Operator5'
   *  RelationalOperator: '<S260>/Relational Operator1'
   *  RelationalOperator: '<S260>/Relational Operator6'
   *  UnitDelay: '<S260>/Unit Delay'
   *  UnitDelay: '<S260>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
    AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
    PEPSCtl_PSAuthentRes = 0U;
    AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
    AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
    PEPSCtl_PSReq = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib == AppSwcBcm_IN_Init_k) {
    PEPSCtl_PSReq = 0U;
    if ((rtb_LogicalOperator7_n || ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_io) &&
          rtb_LogicalOperator2_m4)) && (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_m ==
         0) && rtb_Compare_a) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_PSSeekKeyOut;
      AppSwcBcm_ARID_DEF.count_e = 0U;
      AppSwcBcm_ARID_DEF.count1_k = 0U;
      Set_PSAuth_FobReq(1U);
      PEPSCtl_PSReq = 1U;
    }
  } else {
    /* case IN_PSSeekKeyOut: */
    PEPSCtl_PSReq = 1U;
    if (AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg == 1) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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
      if (rtb_CCaller == 1) {
        if (AppSwcBcm_ARID_DEF.count1_k >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 1U;
          tmp = AppSwcBcm_ARID_DEF.count1_k + 1;
          if (AppSwcBcm_ARID_DEF.count1_k + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_k = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 2) {
        if (AppSwcBcm_ARID_DEF.count1_k >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          tmp = AppSwcBcm_ARID_DEF.count1_k + 1;
          if (AppSwcBcm_ARID_DEF.count1_k + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_k = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 3) {
        if (AppSwcBcm_ARID_DEF.count1_k >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 3U;
          tmp = AppSwcBcm_ARID_DEF.count1_k + 1;
          if (AppSwcBcm_ARID_DEF.count1_k + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1_k = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 0) {
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

  /* End of Chart: '<S260>/Chart' */

  /* Chart: '<S260>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count_k = 0.0;
    PEPSCtl_KeySta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib) {
     case AppSwcBcm_IN_IMMOKeyValid:
      PEPSCtl_KeySta = 3U;
      if (AppSwcBcm_ARID_DEF.count_k >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        AppSwcBcm_ARID_DEF.count_k = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_k++;
      }
      break;

     case AppSwcBcm_IN_Init_l:
      PEPSCtl_KeySta = 0U;
      switch (AppSwcBcm_ARID_DEF.BCM_KeySta) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_RemoteKeyValid;
        AppSwcBcm_ARID_DEF.count_k = 0.0;
        PEPSCtl_KeySta = 1U;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_IMMOKeyValid;
        AppSwcBcm_ARID_DEF.count_k = 0.0;
        PEPSCtl_KeySta = 3U;
        break;
      }
      break;

     default:
      /* case IN_RemoteKeyValid: */
      PEPSCtl_KeySta = 1U;
      if (AppSwcBcm_ARID_DEF.count_k >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        AppSwcBcm_ARID_DEF.count_k = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_k++;
      }
      break;
    }
  }

  /* End of Chart: '<S260>/Chart1' */

  /* Chart: '<S260>/Chart2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_i = AppSwcBcm_ARID_DEF.Power_Mode_start_g;
  AppSwcBcm_ARID_DEF.Power_Mode_start_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_i =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
    AppSwcBcm_ARID_DEF.count = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    PEPSCtl_IndicationKeyCloser = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_k:
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
                 ((AppSwcBcm_ARID_DEF.Power_Mode_prev_i !=
                   AppSwcBcm_ARID_DEF.Power_Mode_start_g) &&
                  (AppSwcBcm_ARID_DEF.Power_Mode_start_g == 2)) ||
                 ((AppSwcBcm_ARID_DEF.Power_Mode_prev_i !=
                   AppSwcBcm_ARID_DEF.Power_Mode_start_g) &&
                  (AppSwcBcm_ARID_DEF.Power_Mode_start_g == 0)) ||
                 ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
                   AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
                  (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_i !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_g) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_g == 2)) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_i !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_g) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_g == 0)) ||
          ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
            AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
           (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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
      if (((AppSwcBcm_ARID_DEF.Power_Mode_prev_i !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_g) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_g == 2)) ||
          ((AppSwcBcm_ARID_DEF.Power_Mode_prev_i !=
            AppSwcBcm_ARID_DEF.Power_Mode_start_g) &&
           (AppSwcBcm_ARID_DEF.Power_Mode_start_g == 0)) ||
          ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
            AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
           (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
        AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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

  /* End of Chart: '<S260>/Chart2' */

  /* Chart: '<S260>/Chart5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev = AppSwcBcm_ARID_DEF.Power_Mode_start;
  AppSwcBcm_ARID_DEF.Power_Mode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  if (AppSwcBcm_ARID_DEF.is_active_c12_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.is_active_c12_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_IMMOKey = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib == AppSwcBcm_IN_IMMOKeyValid)
  {
    PEPSCtl_IMMOKey = 1U;
    if ((AppSwcBcm_ARID_DEF.Power_Mode_prev !=
         AppSwcBcm_ARID_DEF.Power_Mode_start) &&
        (AppSwcBcm_ARID_DEF.Power_Mode_start == 0)) {
      AppSwcBcm_ARID_DEF.is_c12_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
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

  /* End of Chart: '<S260>/Chart5' */

  /* CCaller: '<S256>/C Caller2' */
  rtb_CCaller = Get_Wlcm_FunStatus();

  /* CCaller: '<S256>/C Caller3' */
  Get_PollingWork_State();

  /* RelationalOperator: '<S284>/FixPt Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S284>/Delay Input1'
   *
   * Block description for '<S284>/Delay Input1':
   *
   *  Store in Global RAM
   */
  rtb_LogicalOperator7_n = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus()
    )->BodyWarnSts != AppSwcBcm_ARID_DEF.DelayInput1_DSTATE);

  /* Switch: '<S261>/Switch' incorporates:
   *  Constant: '<S261>/Constant'
   *  Constant: '<S279>/Constant'
   *  Logic: '<S261>/Logical Operator3'
   *  Logic: '<S261>/Logical Operator5'
   *  RelationalOperator: '<S279>/Compare'
   *  UnitDelay: '<S261>/Unit Delay1'
   *  UnitDelay: '<S261>/Unit Delay2'
   */
  if (rtb_LogicalOperator7_n && (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p == 0)) {
    AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_f = true;
  } else {
    /* RelationalOperator: '<S281>/Compare' incorporates:
     *  Constant: '<S281>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_Compare_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())
                     ->BodyWarnSts == 0);
    AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_f = (((!rtb_LogicalOperator7_n) ||
      (!rtb_Compare_a)) && AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_f);
  }

  /* End of Switch: '<S261>/Switch' */

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S261>/Relational Operator7'
   */
  rtb_LogicalOperator2_m4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_EEReadCtl_Bus()
    )->IllmndUnlckSts == 2);

  /* RelationalOperator: '<S269>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S261>/Relational Operator5'
   */
  rtb_Compare_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode ==
                   0);

  /* Logic: '<S261>/Logical Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S261>/Relational Operator1'
   */
  rtb_LogicalOperator7_n =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S261>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S261>/Relational Operator6'
   */
  rtb_RelationalOperator8_il =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S261>/Logical Operator7' */
  rtb_LogicalOperator7_n = (rtb_LogicalOperator7_n || rtb_RelationalOperator8_il);

  /* Logic: '<S261>/Logical Operator' incorporates:
   *  UnitDelay: '<S261>/Unit Delay2'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_f &&
    rtb_LogicalOperator2_m4 && rtb_Compare_a && rtb_LogicalOperator7_n);

  /* Logic: '<S261>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator1_a =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarRRSw);

  /* Switch: '<S261>/Switch2' incorporates:
   *  Constant: '<S261>/Constant3'
   *  Logic: '<S261>/Logical Operator8'
   *  Logic: '<S261>/Logical Operator9'
   *  RelationalOperator: '<S280>/Compare'
   *  Switch: '<S261>/Switch3'
   *  UnitDelay: '<S261>/Unit Delay3'
   *  UnitDelay: '<S261>/Unit Delay4'
   */
  if (AppSwcBcm_ARID_DEF.LogicalOperator1_a &&
      (!AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_kk)) {
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE = 1.0;
  } else if (!AppSwcBcm_ARID_DEF.LogicalOperator1_a) {
    /* Switch: '<S261>/Switch3' incorporates:
     *  Constant: '<S261>/Constant4'
     *  UnitDelay: '<S261>/Unit Delay4'
     */
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE = 0.0;
  }

  /* End of Switch: '<S261>/Switch2' */

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  Constant: '<S282>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S282>/Compare'
   */
  rtb_LogicalOperator2_m4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus()
    )->BodyWarnSts == 0);

  /* Switch: '<S261>/Switch5' incorporates:
   *  Constant: '<S261>/Constant12'
   *  Constant: '<S283>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S261>/Logical Operator11'
   *  RelationalOperator: '<S283>/Compare'
   *  Switch: '<S261>/Switch4'
   *  UnitDelay: '<S261>/Unit Delay5'
   *  UnitDelay: '<S261>/Unit Delay6'
   */
  if (AppSwcBcm_ARID_DEF.LogicalOperator1_a && rtb_LogicalOperator2_m4 &&
      (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_o > 0)) {
    AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE = 1.0;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts !=
             0) {
    /* Switch: '<S261>/Switch4' incorporates:
     *  Constant: '<S261>/Constant5'
     *  UnitDelay: '<S261>/Unit Delay6'
     */
    AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE = 0.0;
  }

  /* End of Switch: '<S261>/Switch5' */

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S261>/Logical Operator2'
   */
  rtb_LogicalOperator2_m4 = !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DrvSeatSw;

  /* RelationalOperator: '<S261>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator8_il = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_EEReadCtl_Bus
    ())->IllmndLckSts == 2);

  /* Logic: '<S261>/Logical Operator4' */
  rtb_LogicalOperator4_m2 = !rtb_Compare_a;

  /* RelationalOperator: '<S269>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S261>/Relational Operator4'
   */
  rtb_Compare_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())
                   ->BodyWarnSts == 0);

  /* Logic: '<S261>/Logical Operator6' incorporates:
   *  Logic: '<S261>/Logical Operator12'
   *  UnitDelay: '<S261>/Unit Delay4'
   *  UnitDelay: '<S261>/Unit Delay6'
   */
  rtb_LogicalOperator7_n = (((AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE != 0.0) ||
    (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE != 0.0)) && rtb_LogicalOperator2_m4 &&
    rtb_RelationalOperator8_il && rtb_LogicalOperator4_m2 &&
    rtb_LogicalOperator7_n && rtb_Compare_a);

  /* Chart: '<S261>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
    Clear_PollingCommd();
    PEPSCtl_UnlckWlcmReq = 0U;
    PEPSCtl_LckWlcmReq = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_k:
      PEPSCtl_UnlckWlcmReq = 0U;
      PEPSCtl_LckWlcmReq = 0U;
      if (rtb_LogicalOperator) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_UnlockDay0to7;
        Set_Polling_FunReq(3U);

        /*   */
      } else if (!rtb_LogicalOperator7_n) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_UnlockExcedDay7;
        Set_Polling_FunReq(1U);
      } else {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_LockWlcm;
        Set_Polling_FunReq(2U);
      }
      break;

     case AppSwcBcm_IN_LockWlcm:
      if (rtb_CCaller == 3) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmLockReq;
        PEPSCtl_LckWlcmReq = 1U;
        AppSwcBcm_ARID_DEF.count_lr = 0U;
      } else if (!rtb_LogicalOperator7_n) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      }
      break;

     case AppSwcBcm_IN_UnlockDay0to7:
      if (rtb_CCaller == 2) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmUnlockReq;
        PEPSCtl_UnlckWlcmReq = 1U;
        AppSwcBcm_ARID_DEF.count_lr = 0U;
      } else if (!rtb_LogicalOperator) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      }
      break;

     case AppSwcBcm_IN_UnlockExcedDay7:
      if (rtb_LogicalOperator || rtb_LogicalOperator7_n) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      }
      break;

     case AppSwcBcm_IN_WlcmLockReq:
      PEPSCtl_LckWlcmReq = 1U;
      if (AppSwcBcm_ARID_DEF.count_lr > 20) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_lr + 1;
        if (AppSwcBcm_ARID_DEF.count_lr + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_lr = (uint16)tmp;
      }
      break;

     default:
      /* case IN_WlcmUnlockReq: */
      PEPSCtl_UnlckWlcmReq = 1U;
      if (AppSwcBcm_ARID_DEF.count_lr > 20) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
        Clear_PollingCommd();
        PEPSCtl_UnlckWlcmReq = 0U;
        PEPSCtl_LckWlcmReq = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_lr + 1;
        if (AppSwcBcm_ARID_DEF.count_lr + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_lr = (uint16)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S261>/Chart' */

  /* Logic: '<S258>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S258>/Logical Operator1'
   */
  rtb_LogicalOperator2_m4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw);

  /* RelationalOperator: '<S269>/Compare' incorporates:
   *  Constant: '<S269>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_Compare_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode ==
                   2);

  /* Logic: '<S258>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S258>/Logical Operator'
   *  Logic: '<S258>/Logical Operator2'
   *  RelationalOperator: '<S267>/Compare'
   *  RelationalOperator: '<S268>/Compare'
   *  UnitDelay: '<S258>/Unit Delay'
   *  UnitDelay: '<S258>/Unit Delay1'
   */
  rtb_LogicalOperator7_n = (rtb_LogicalOperator2_m4 &&
    ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kc) ||
     (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_j)) && rtb_Compare_a &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->VehStop &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw);

  /* CCaller: '<S258>/C Caller7' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Chart: '<S258>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_o = AppSwcBcm_ARID_DEF.Power_Mode_start_f;
  AppSwcBcm_ARID_DEF.Power_Mode_start_f =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  if (AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_o =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.KeyNotFound_flg = 0.0;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib == AppSwcBcm_IN_Init_k) {
    if (rtb_LogicalOperator7_n) {
      AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_KeyNotInCar;
      AppSwcBcm_ARID_DEF.count_o = 0U;
      AppSwcBcm_ARID_DEF.count1 = 0.0;
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
      Set_PSAuth_FobReq(1U);
    }

    /* case IN_KeyNotInCar: */
  } else if ((AppSwcBcm_ARID_DEF.Warnkeyout_flg == 1) ||
             ((AppSwcBcm_ARID_DEF.Power_Mode_prev_o !=
               AppSwcBcm_ARID_DEF.Power_Mode_start_f) &&
              (AppSwcBcm_ARID_DEF.Power_Mode_start_f == 0))) {
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_k;
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
      if (AppSwcBcm_ARID_DEF.count_o >= 1000) {
        AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
        AppSwcBcm_ARID_DEF.count_o = 1000U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_o + 1;
        if (AppSwcBcm_ARID_DEF.count_o + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_o = (uint16)tmp;
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

  /* End of Chart: '<S258>/Chart' */

  /* CCaller: '<S256>/C Caller7' */
  rtb_CCaller = Get_KeyBat_VolLow();

  /* Chart: '<S258>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c9_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Finish:
      PEPSCtl_KeyLoBattLvlWarn = 0U;
      break;

     case AppSwcBcm_IN_Init_l:
      if (rtb_CCaller == 1) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid;
        AppSwcBcm_ARID_DEF.count_lm = 0.0;
        PEPSCtl_KeyLoBattLvlWarn = 1U;
      }
      break;

     default:
      /* case IN_KeyValid: */
      PEPSCtl_KeyLoBattLvlWarn = 1U;
      if (AppSwcBcm_ARID_DEF.count_lm >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Finish;
        PEPSCtl_KeyLoBattLvlWarn = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_lm++;
      }
      break;
    }
  }

  /* End of Chart: '<S258>/Chart3' */
}

/* Update for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl_Update(void)
{
  /* Update for UnitDelay: '<S259>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ksc =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw;

  /* Update for UnitDelay: '<S259>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cj =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw;

  /* Update for UnitDelay: '<S257>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S260>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S260>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_io =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* Update for UnitDelay: '<S260>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_m = PEPSCtl_KeySta;

  /* Update for UnitDelay: '<S284>/Delay Input1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *
   * Block description for '<S284>/Delay Input1':
   *
   *  Store in Global RAM
   */
  AppSwcBcm_ARID_DEF.DelayInput1_DSTATE =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S261>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S261>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_kk =
    AppSwcBcm_ARID_DEF.LogicalOperator1_a;

  /* Update for UnitDelay: '<S261>/Unit Delay5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_o =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S258>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kc =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Update for UnitDelay: '<S258>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_j =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw;
}

/* Output and update for atomic system: '<S285>/HwOutBCM' */
static void AppSwcBcm_HwOutBCM(void)
{
  uint8 rtb_DataTypeConversion33;
  boolean rtb_LogicalOperator1_ox;

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion14'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J421IG1RlyCtl;

  /* CCaller: '<S289>/HwIG1RlyCls' */
  SetHw_IG1RlyCls(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion10' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLSta;

  /* Chart: '<S289>/HwTurnLampOnLeft' incorporates:
   *  Constant: '<S289>/Constant2'
   */
  if (BCMTx_TRMode_C) {
    SetHw_TurnLampOnLeft(rtb_DataTypeConversion33);
    SetHw_DrvTurnLo_Tr(200U, (uint8)(rtb_DataTypeConversion33 * 100U));
  } else {
    SetHw_TurnLampOnLeft(rtb_DataTypeConversion33);
  }

  /* End of Chart: '<S289>/HwTurnLampOnLeft' */

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion15'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J437IG2RlyCtl;

  /* CCaller: '<S289>/HwIG2RlyCls' */
  SetHw_IG2RlyCls(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion11' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrRSta;

  /* Chart: '<S289>/HwTurnLampOnRight' incorporates:
   *  Constant: '<S289>/Constant3'
   */
  if (BCMTx_TRMode_C) {
    SetHw_TurnLampOnRght(rtb_DataTypeConversion33);
    SetHw_DrvTurnRo_Tr(200U, (uint8)(rtb_DataTypeConversion33 * 100U));
  } else {
    SetHw_TurnLampOnRght(rtb_DataTypeConversion33);
  }

  /* End of Chart: '<S289>/HwTurnLampOnRight' */

  /* CCaller: '<S289>/HwWiprOn' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion'
   */
  SetHw_WiprOn(AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv);

  /* Logic: '<S319>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S319>/Logical Operator'
   *  RelationalOperator: '<S319>/Relational Operator'
   */
  rtb_LogicalOperator1_ox = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->HazardLightSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->EmerHazardLightSta);
  rtb_LogicalOperator1_ox = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrRSta && (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLSta && rtb_LogicalOperator1_ox);

  /* CCaller: '<S289>/HwHzrdLampOn' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion16'
   */
  SetHw_HzrdLampOn(rtb_LogicalOperator1_ox);

  /* Chart: '<S289>/HwSavePwrEnbl' incorporates:
   *  Constant: '<S289>/Constant4'
   *  DataTypeConversion: '<S289>/DataTypeConversion21'
   */
  if (BCMTx_TRMode_C) {
    SetHw_DrvPwrOut(200U, (uint8)(AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr *
      100U));
  } else {
    SetHw_SavePwrEnbl(AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr);
  }

  /* End of Chart: '<S289>/HwSavePwrEnbl' */

  /* CCaller: '<S289>/HwWiprHiSpd' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion1'
   */
  SetHw_WiprHiSpd(AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion22'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->DomeLampPwmDuty;

  /* CCaller: '<S289>/HwCabinLampPWM' incorporates:
   *  Constant: '<S289>/Constant43'
   */
  SetHw_CabinLampPWM(200U, rtb_DataTypeConversion33);

  /* CCaller: '<S289>/HwFrntWshrOn' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion2'
   */
  SetHw_FrntWshrOn(AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion31'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->J408BackLampPWM;

  /* CCaller: '<S289>/HwBackLightCtl' incorporates:
   *  Constant: '<S289>/Constant'
   */
  SetHw_BackLightDrv(100U, rtb_DataTypeConversion33);

  /* Chart: '<S289>/HwDrvSeatHeatCtl' incorporates:
   *  Constant: '<S289>/Constant1'
   */
  if (BCMTx_TRMode_C) {
    SetHw_DrvSeatHeat_TR(200U, AppSwcBcm_ARID_DEF.SeatCtl_Bus.CN167DrvSeatHtPWM);
  } else {
    SetHw_DrvSeatHeat(200U, AppSwcBcm_ARID_DEF.SeatCtl_Bus.CN167DrvSeatHtPWM);
  }

  /* End of Chart: '<S289>/HwDrvSeatHeatCtl' */

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion3'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J56DoorUnlck;

  /* CCaller: '<S289>/HwGlbDoorUnlck' */
  SetHw_GlbDoorUnlck(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion4'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J54DoorLck;

  /* CCaller: '<S289>/HwGlbDoorLck' */
  SetHw_GlbDoorLck(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion5'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J51DrvWinUp;

  /* CCaller: '<S289>/HwDrvrWinUp' */
  SetHw_DrvrWinUp(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion6'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J53DrvWinDn;

  /* CCaller: '<S289>/HwDrvrWinDwn' */
  SetHw_DrvrWinDwn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion7'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J55PsgWinUp;

  /* CCaller: '<S289>/HwPsngrWinUp' */
  SetHw_PsngrWinUp(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion8'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J57PsgWinDn;

  /* CCaller: '<S289>/HwPsngrWinDwn' */
  SetHw_PsngrWinDwn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion9'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->PosLampSta;

  /* CCaller: '<S289>/HwPstnLampOn' */
  SetHw_PstnLampOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion12'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BrakeLightSta;

  /* CCaller: '<S289>/HwBrkLghtOn' */
  SetHw_BrkLghtOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion13'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->ReverseLampSta;

  /* CCaller: '<S289>/HwRvrsLampOn' */
  SetHw_RvrsLampOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion17'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->LowBeamSta;

  /* CCaller: '<S289>/HwLoBeamOn' */
  SetHw_LoBeamOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion18'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->HiBeamSta;

  /* CCaller: '<S289>/HwHiBeamOn' */
  SetHw_HiBeamOn(rtb_DataTypeConversion33);

  /* CCaller: '<S289>/HwAlrmHornOn' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion19'
   */
  SetHw_AlrmHornOn(AppSwcBcm_ARID_DEF.BusCreator9.HornDrv);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion20'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->FogLampRSta;

  /* CCaller: '<S289>/HwRearFogLampOn' */
  SetHw_RearFogLampOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion23'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->DayRunLightSta;

  /* CCaller: '<S289>/HwDayRunLghtOn' */
  SetHw_DayRunLghtOn(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion24'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J511TrunkUnlck;

  /* CCaller: '<S289>/HwTrunkUnlck' */
  Set_TrunkUnLock(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion25'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BSDLeftCtl;

  /* CCaller: '<S289>/HwBSDLeftCtl' */
  Set_BSDLeftCtl(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion26'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BSDRightCtl;

  /* CCaller: '<S289>/HwBSDRightCtl' */
  Set_BSDRightCtl(rtb_DataTypeConversion33);

  /* CCaller: '<S289>/HwESCLPwrSup' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion27'
   */
  SetHw_PwrSup(AppSwcBcm_ARID_DEF.ESCLCtl_Bus.J436PwrSup);

  /* CCaller: '<S289>/HwRVMHeatCtl' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion28'
   */
  SetHw_RearMirrorHeat(AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion29'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->BoxLampSta;

  /* CCaller: '<S289>/HwBoxLampCtl' */
  SetHw_BoxLampSta(rtb_DataTypeConversion33);

  /* DataTypeConversion: '<S289>/DataTypeConversion33' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S289>/DataTypeConversion30'
   */
  rtb_DataTypeConversion33 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->FogLampFSta;

  /* CCaller: '<S289>/HwFrontFogLampCtl' */
  SetHw_FrontFogLamps(rtb_DataTypeConversion33);

  /* CCaller: '<S289>/HwSteerWhlHeat' incorporates:
   *  DataTypeConversion: '<S289>/DataTypeConversion33'
   */
  SetHw_SteerWhlHeat(AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.J447SteerWhlHt);
}

/*
 * System initialize for atomic system:
 *    '<S293>/Lib_RiseEdgeDelay'
 *    '<S294>/Lib_RiseEdgeDelay'
 *    '<S294>/Lib_RiseEdgeDelay1'
 *    '<S296>/Lib_RiseEdgeDelay'
 *    '<S296>/Lib_RiseEdgeDelay1'
 *    '<S901>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S293>/Lib_RiseEdgeDelay'
 *    '<S294>/Lib_RiseEdgeDelay'
 *    '<S294>/Lib_RiseEdgeDelay1'
 *    '<S296>/Lib_RiseEdgeDelay'
 *    '<S296>/Lib_RiseEdgeDelay1'
 *    '<S901>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16DelayTim, boolean *rty_LIB_blOut,
  ARID_DEF_Lib_RiseEdgeDelay_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rtb_LogicalOperator1_nyp;

  /* Outputs for Function Call SubSystem: '<S320>/Lib_RiseEdgeDet' */
  /* Logic: '<S322>/Logical Operator1' incorporates:
   *  UnitDelay: '<S322>/Unit Delay'
   */
  rtb_LogicalOperator1_nyp = !AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S322>/Unit Delay' incorporates:
   *  Chart: '<S293>/Lib_RiseEdgeDelay'
   */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_LIB_blIn;

  /* Chart: '<S293>/Lib_RiseEdgeDelay' incorporates:
   *  Logic: '<S322>/Logical Operator'
   */
  if (rtu_LIB_blIn && rtb_LogicalOperator1_nyp) {
    AppSwcBcm__ARID_DEF_arg->Cnt = rtu_LIB_u16DelayTim;
    *rty_LIB_blOut = true;
  }

  /* End of Outputs for SubSystem: '<S320>/Lib_RiseEdgeDet' */
  if (AppSwcBcm__ARID_DEF_arg->Cnt <= 0) {
    *rty_LIB_blOut = false;
  } else {
    AppSwcBcm__ARID_DEF_arg->Cnt--;
  }
}

/* System initialize for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx_Init(void)
{
  boolean LIB_blOut_ek;

  /* SystemInitialize for Chart: '<S293>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_mf);

  /* SystemInitialize for Chart: '<S294>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_my);

  /* SystemInitialize for Chart: '<S294>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_f);

  /* SystemInitialize for Chart: '<S296>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_ek);

  /* SystemInitialize for Chart: '<S296>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_ek);
}

/* Output and update for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx(void)
{
  uint8 rtb_MultiportSwitch;
  uint8 rtb_MultiportSwitch_dq;
  boolean rtb_RelationalOperator_p;

  /* DataTypeConversion: '<S285>/Data Type Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Left =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Right =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrRSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Rear =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampRSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLampSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PosLampSta;

  /* RelationalOperator: '<S305>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S298>/Logical Operator'
   *  Logic: '<S298>/Logical Operator1'
   *  RelationalOperator: '<S298>/Relational Operator'
   */
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->HazardLightSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->EmerHazardLightSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->EmerSta);
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->TurnIndcrRSta && (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLSta && rtb_RelationalOperator_p);

  /* DataTypeConversion: '<S285>/Data Type Conversion4' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardLampSts =
    rtb_RelationalOperator_p;

  /* DataTypeConversion: '<S285>/Data Type Conversion5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LowBeamSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Front =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampFSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AutoLampStatus =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->AutoLampSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion9' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLightSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->DayRunLightSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion10' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLampSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->ReverseLampSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion11' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLampSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BrakeLightSta;

  /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  switch ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrMod) {
   case 0:
    /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
     *  Constant: '<S290>/Constant'
     */
    rtb_MultiportSwitch = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
     *  Constant: '<S290>/Constant1'
     */
    rtb_MultiportSwitch = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
     *  Constant: '<S290>/Constant2'
     */
    rtb_MultiportSwitch = 4U;
    break;

   case 3:
    /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
     *  Constant: '<S290>/Constant3'
     */
    rtb_MultiportSwitch = 1U;
    break;

   case 4:
    /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
     *  Constant: '<S290>/Constant4'
     */
    rtb_MultiportSwitch = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S290>/Multiport Switch' incorporates:
     *  UnitDelay: '<S290>/Unit Delay'
     */
    rtb_MultiportSwitch = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ni;
    break;
  }

  /* End of MultiPortSwitch: '<S290>/Multiport Switch' */

  /* Switch: '<S291>/Switch' incorporates:
   *  Constant: '<S291>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S291>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLaneLSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 0U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLaneRSw)
  {
    /* Switch: '<S291>/Switch1' incorporates:
     *  Constant: '<S291>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 1U;
  } else {
    /* Switch: '<S291>/Switch1' incorporates:
     *  Constant: '<S291>/Constant'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 2U;
  }

  /* End of Switch: '<S291>/Switch' */

  /* DataTypeConversion: '<S285>/Data Type Conversion15' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightIntensity =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LightIntstSta;

  /* Switch: '<S302>/Switch' incorporates:
   *  Constant: '<S302>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PosLampSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 1U;
  } else {
    /* Logic: '<S302>/Logical Operator' */
    rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
      ->LowBeamSw || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamSw);

    /* Switch: '<S302>/Switch1' incorporates:
     *  Switch: '<S302>/Switch2'
     */
    if (rtb_RelationalOperator_p) {
      /* Switch: '<S302>/Switch1' incorporates:
       *  Constant: '<S302>/Constant1'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 2U;
    } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->AutoLampSw) {
      /* Switch: '<S302>/Switch2' incorporates:
       *  Constant: '<S302>/Constant'
       *  Switch: '<S302>/Switch1'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 3U;
    } else {
      /* Switch: '<S302>/Switch1' incorporates:
       *  Constant: '<S302>/Constant3'
       *  Switch: '<S302>/Switch2'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 0U;
    }

    /* End of Switch: '<S302>/Switch1' */
  }

  /* End of Switch: '<S302>/Switch' */

  /* Switch: '<S308>/Switch' incorporates:
   *  Constant: '<S308>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S308>/Switch1'
   *  Switch: '<S308>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->LowBeamSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 0U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HiBeamSw) {
    /* Switch: '<S308>/Switch1' incorporates:
     *  Constant: '<S308>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PassLightSw) {
    /* Switch: '<S308>/Switch2' incorporates:
     *  Constant: '<S308>/Constant'
     *  Switch: '<S308>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 2U;
  } else {
    /* Switch: '<S308>/Switch1' incorporates:
     *  Constant: '<S308>/Constant3'
     *  Switch: '<S308>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 3U;
  }

  /* End of Switch: '<S308>/Switch' */

  /* RelationalOperator: '<S305>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator7'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HoodAjarSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion19' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Hood =
    rtb_RelationalOperator_p;

  /* DataTypeConversion: '<S285>/Data Type Conversion20' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardWarningLightSwSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->HazardLightSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion21' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntFogLiSwSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampFSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiSwSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FogLampRSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion23' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FlwrMeHmCtrlFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FlwrMeHomeCtlFb;

  /* Switch: '<S309>/Switch' incorporates:
   *  Constant: '<S309>/Constant2'
   *  Constant: '<S309>/Constant4'
   *  Constant: '<S309>/Constant5'
   *  Logic: '<S309>/Logical Operator'
   *  RelationalOperator: '<S309>/Relational Operator'
   *  RelationalOperator: '<S309>/Relational Operator1'
   *  RelationalOperator: '<S309>/Relational Operator2'
   *  RelationalOperator: '<S309>/Relational Operator3'
   *  Switch: '<S309>/Switch1'
   *  Switch: '<S309>/Switch2'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator9.TrunkWarnSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.AntiLckSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.PartArmedSta == 1)) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.ArmedSta != 0) {
    /* Switch: '<S309>/Switch1' incorporates:
     *  Constant: '<S309>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.SeekSta != 0) {
    /* Switch: '<S309>/Switch2' incorporates:
     *  Constant: '<S309>/Constant'
     *  Switch: '<S309>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 4U;
  } else {
    /* Switch: '<S309>/Switch1' incorporates:
     *  Constant: '<S309>/Constant3'
     *  Switch: '<S309>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 0U;
  }

  /* End of Switch: '<S309>/Switch' */

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator6'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->TrunkAjarSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion25' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Trunk =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator2'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion26' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator3'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion27' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator4'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarRLSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion28' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator5'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarRRSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion29' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RR =
    rtb_RelationalOperator_p;

  /* MultiPortSwitch: '<S310>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.BusCreator6.WiperSta) {
   case 0:
    /* MultiPortSwitch: '<S310>/Multiport Switch' incorporates:
     *  Constant: '<S310>/Constant'
     */
    rtb_MultiportSwitch_dq = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S310>/Multiport Switch' incorporates:
     *  Constant: '<S310>/Constant1'
     */
    rtb_MultiportSwitch_dq = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S310>/Multiport Switch' incorporates:
     *  Constant: '<S310>/Constant2'
     */
    rtb_MultiportSwitch_dq = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S310>/Multiport Switch' incorporates:
     *  Constant: '<S310>/Constant3'
     */
    rtb_MultiportSwitch_dq = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S310>/Multiport Switch' incorporates:
     *  Constant: '<S310>/Constant4'
     */
    rtb_MultiportSwitch_dq = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S310>/Multiport Switch' incorporates:
     *  UnitDelay: '<S310>/Unit Delay'
     */
    rtb_MultiportSwitch_dq = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_lc;
    break;
  }

  /* End of MultiPortSwitch: '<S310>/Multiport Switch' */

  /* MultiPortSwitch: '<S311>/Multiport Switch' incorporates:
   *  Constant: '<S311>/Constant'
   *  Constant: '<S311>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (!(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvSeatSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 2U;
  }

  /* End of MultiPortSwitch: '<S311>/Multiport Switch' */

  /* DataTypeConversion: '<S285>/Data Type Conversion41' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntWshrSwSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WashSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion42' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWashSts =
    AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv;

  /* Switch: '<S312>/Switch' incorporates:
   *  Constant: '<S312>/Constant2'
   *  Switch: '<S312>/Switch1'
   *  Switch: '<S312>/Switch2'
   *  Switch: '<S312>/Switch3'
   *  Switch: '<S312>/Switch4'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.WiperOffSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperLowSpdSw) {
    /* Switch: '<S312>/Switch1' incorporates:
     *  Constant: '<S312>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperHiSpdSw) {
    /* Switch: '<S312>/Switch2' incorporates:
     *  Constant: '<S312>/Constant'
     *  Switch: '<S312>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperMistSw) {
    /* Switch: '<S312>/Switch3' incorporates:
     *  Constant: '<S312>/Constant3'
     *  Switch: '<S312>/Switch1'
     *  Switch: '<S312>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperInrSw) {
    /* Switch: '<S312>/Switch4' incorporates:
     *  Constant: '<S312>/Constant4'
     *  Switch: '<S312>/Switch1'
     *  Switch: '<S312>/Switch2'
     *  Switch: '<S312>/Switch3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 4U;
  } else {
    /* Switch: '<S312>/Switch2' incorporates:
     *  Constant: '<S312>/Constant5'
     *  Switch: '<S312>/Switch1'
     *  Switch: '<S312>/Switch3'
     *  Switch: '<S312>/Switch4'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 6U;
  }

  /* End of Switch: '<S312>/Switch' */

  /* Switch: '<S313>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S313>/Switch1'
   *  Switch: '<S313>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinUpSw) {
    /* Switch: '<S313>/Switch' incorporates:
     *  Constant: '<S313>/Constant2'
     */
    BCM_DriverWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinDnSw) {
    /* Switch: '<S313>/Switch1' incorporates:
     *  Constant: '<S313>/Constant1'
     *  Switch: '<S313>/Switch'
     */
    BCM_DriverWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinAutoDnSw) {
    /* Switch: '<S313>/Switch2' incorporates:
     *  Constant: '<S313>/Constant'
     *  Switch: '<S313>/Switch'
     *  Switch: '<S313>/Switch1'
     */
    BCM_DriverWinSwSig = 4U;
  } else {
    /* Switch: '<S313>/Switch' incorporates:
     *  Constant: '<S313>/Constant3'
     *  Switch: '<S313>/Switch1'
     *  Switch: '<S313>/Switch2'
     */
    BCM_DriverWinSwSig = 0U;
  }

  /* End of Switch: '<S313>/Switch' */

  /* Switch: '<S314>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S314>/Switch1'
   *  Switch: '<S314>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinUpSw) {
    /* Switch: '<S314>/Switch' incorporates:
     *  Constant: '<S314>/Constant2'
     */
    BCM_PassWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinDnSw) {
    /* Switch: '<S314>/Switch1' incorporates:
     *  Constant: '<S314>/Constant1'
     *  Switch: '<S314>/Switch'
     */
    BCM_PassWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinAutoDnSw) {
    /* Switch: '<S314>/Switch2' incorporates:
     *  Constant: '<S314>/Constant'
     *  Switch: '<S314>/Switch'
     *  Switch: '<S314>/Switch1'
     */
    BCM_PassWinSwSig = 4U;
  } else {
    /* Switch: '<S314>/Switch' incorporates:
     *  Constant: '<S314>/Constant3'
     *  Switch: '<S314>/Switch1'
     *  Switch: '<S314>/Switch2'
     */
    BCM_PassWinSwSig = 0U;
  }

  /* End of Switch: '<S314>/Switch' */

  /* DataTypeConversion: '<S285>/Data Type Conversion49' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion50' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinSta;

  /* Switch: '<S292>/Switch1' incorporates:
   *  Constant: '<S292>/Constant1'
   *  Logic: '<S292>/Logical Operator'
   *  Switch: '<S292>/Switch'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv &&
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts =
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv;
  }

  /* End of Switch: '<S292>/Switch1' */

  /* DataTypeConversion: '<S285>/Data Type Conversion52' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntLeDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvPESw;

  /* DataTypeConversion: '<S285>/Data Type Conversion53' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntRiDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->PsgPESw;

  /* DataTypeConversion: '<S285>/Data Type Conversion54' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkSwtSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkSw;

  /* DataTypeConversion: '<S285>/Data Type Conversion98' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnNoKeyFound =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnNoKeyFound;

  /* DataTypeConversion: '<S285>/Data Type Conversion55' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* DataTypeConversion: '<S285>/Data Type Conversion97' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSAuthentRes =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSAuthentRes;

  /* DataTypeConversion: '<S285>/Data Type Conversion96' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RKEReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->RKEReq;

  /* DataTypeConversion: '<S285>/Data Type Conversion95' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyInCarSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyInCarSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion94' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->DrvPEAuthentAcsd;

  /* DataTypeConversion: '<S285>/Data Type Conversion72' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FRPEAuthentAcsd;

  /* DataTypeConversion: '<S285>/Data Type Conversion71' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSReq;

  /* DataTypeConversion: '<S285>/Data Type Conversion57' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* DataTypeConversion: '<S285>/Data Type Conversion58' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChgWiperMtMdSwSetFb =
    AppSwcBcm_ARID_DEF.BusCreator6.WiperMaintSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion59' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ParkAutoUnlockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;

  /* DataTypeConversion: '<S285>/Data Type Conversion60' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_OverspdCntrlLockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->SpdCtlLckSetFb;

  /* DataTypeConversion: '<S285>/Data Type Conversion37' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrbdnKeyNr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FrbdnKeyNr;

  /* DataTypeConversion: '<S285>/Data Type Conversion101' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AvaluebleKeyInCar =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->AvaluebleKeyInCar;

  /* DataTypeConversion: '<S285>/Data Type Conversion104' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyLoBattLvlWarn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyLoBattLvlWarn;

  /* DataTypeConversion: '<S285>/Data Type Conversion70' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeySta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeySta;

  /* Chart: '<S293>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S293>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->WelcomeLampSta, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_mf,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_e);

  /* DataTypeConversion: '<S285>/Data Type Conversion64' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLampReq =
    AppSwcBcm_ARID_DEF.LIB_blOut_mf;

  /* Chart: '<S294>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S294>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeUnlck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_my,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_g);

  /* Chart: '<S294>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S294>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeLck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1_a);

  /* Switch: '<S294>/Switch' incorporates:
   *  Constant: '<S294>/Constant2'
   *  Constant: '<S294>/Constant4'
   *  Switch: '<S294>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_my) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.LIB_blOut_f) {
    /* Switch: '<S294>/Switch1' incorporates:
     *  Constant: '<S294>/Constant3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 0U;
  }

  /* End of Switch: '<S294>/Switch' */

  /* DataTypeConversion: '<S285>/Data Type Conversion106' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnKeyOutReminder =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnKeyOutReminder;

  /* DataTypeConversion: '<S285>/Data Type Conversion107' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IndicationKeyCloser =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->IndicationKeyCloser;

  /* DataTypeConversion: '<S285>/Data Type Conversion67' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* DataTypeConversion: '<S285>/Data Type Conversion68' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLadjvalFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BackLadjvalFb;

  /* DataTypeConversion: '<S285>/Data Type Conversion82' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakePedalSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BrakeLightSw;

  /* BusCreator: '<S285>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion83'
   *  DataTypeConversion: '<S285>/Data Type Conversion84'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;

  /* Switch: '<S297>/Switch' incorporates:
   *  Constant: '<S297>/Constant2'
   *  Constant: '<S297>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 1U;
  }

  /* End of Switch: '<S297>/Switch' */

  /* DataTypeConversion: '<S285>/Data Type Conversion85' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;

  /* DataTypeConversion: '<S285>/Data Type Conversion86' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockSta_FL =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* BusCreator: '<S285>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion126'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte15 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->RemotePwrLckSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion135' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndLckStsFb;

  /* DataTypeConversion: '<S285>/Data Type Conversion136' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndUnlockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndUnlockStsFb;

  /* Switch: '<S299>/Switch' incorporates:
   *  Constant: '<S299>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S299>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->FlwrMeHomeSta) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->WelcomeLampSta)
  {
    /* Switch: '<S299>/Switch1' incorporates:
     *  Constant: '<S299>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 2U;
  } else {
    /* Switch: '<S299>/Switch1' incorporates:
     *  Constant: '<S299>/Constant2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 0U;
  }

  /* End of Switch: '<S299>/Switch' */

  /* DataTypeConversion: '<S285>/Data Type Conversion138' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_VhclSeek =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta;

  /* Switch: '<S300>/Switch' incorporates:
   *  Constant: '<S300>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S300>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrRShort) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrROpen)
  {
    /* Switch: '<S300>/Switch1' incorporates:
     *  Constant: '<S300>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 2U;
  } else {
    /* Switch: '<S300>/Switch1' incorporates:
     *  Constant: '<S300>/Constant2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S300>/Switch' */

  /* Switch: '<S301>/Switch' incorporates:
   *  Constant: '<S301>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Switch: '<S301>/Switch1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLShort) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLOpen)
  {
    /* Switch: '<S301>/Switch1' incorporates:
     *  Constant: '<S301>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 2U;
  } else {
    /* Switch: '<S301>/Switch1' incorporates:
     *  Constant: '<S301>/Constant2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S301>/Switch' */

  /* BusCreator: '<S285>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion148'
   *  DataTypeConversion: '<S285>/Data Type Conversion165'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockOperationRecord =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DynDID_Bus())->DynDID_DoorOpRecord;

  /* Switch: '<S306>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S306>/Switch1'
   *  Switch: '<S306>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinUpSw) {
    /* Switch: '<S306>/Switch' incorporates:
     *  Constant: '<S306>/Constant2'
     */
    BCM_DrvPassWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinDnSw) {
    /* Switch: '<S306>/Switch1' incorporates:
     *  Constant: '<S306>/Constant1'
     *  Switch: '<S306>/Switch'
     */
    BCM_DrvPassWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinAutoDnSw)
  {
    /* Switch: '<S306>/Switch2' incorporates:
     *  Constant: '<S306>/Constant'
     *  Switch: '<S306>/Switch'
     *  Switch: '<S306>/Switch1'
     */
    BCM_DrvPassWinSwSig = 4U;
  } else {
    /* Switch: '<S306>/Switch' incorporates:
     *  Constant: '<S306>/Constant3'
     *  Switch: '<S306>/Switch1'
     *  Switch: '<S306>/Switch2'
     */
    BCM_DrvPassWinSwSig = 0U;
  }

  /* End of Switch: '<S306>/Switch' */

  /* BusCreator: '<S285>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion142'
   *  DataTypeConversion: '<S285>/Data Type Conversion143'
   *  DataTypeConversion: '<S285>/Data Type Conversion144'
   *  DataTypeConversion: '<S285>/Data Type Conversion153'
   *  DataTypeConversion: '<S285>/Data Type Conversion155'
   *  DataTypeConversion: '<S285>/Data Type Conversion162'
   *  DataTypeConversion: '<S285>/Data Type Conversion163'
   *  DataTypeConversion: '<S285>/Data Type Conversion164'
   *  DataTypeConversion: '<S285>/Data Type Conversion167'
   *  DataTypeConversion: '<S285>/Data Type Conversion78'
   *  DataTypeConversion: '<S285>/Data Type Conversion79'
   *  DataTypeConversion: '<S285>/Data Type Conversion80'
   *  Logic: '<S303>/Logical Operator'
   *  Logic: '<S304>/Logical Operator'
   *  RelationalOperator: '<S295>/Relational Operator'
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

  /* RelationalOperator: '<S305>/Relational Operator' incorporates:
   *  Constant: '<S307>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S307>/Relational Operator'
   */
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->DomeLampPwmDuty > 0);

  /* BusCreator: '<S285>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion170'
   *  DataTypeConversion: '<S285>/Data Type Conversion171'
   *  DataTypeConversion: '<S285>/Data Type Conversion75'
   *  DataTypeConversion: '<S285>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DomeLightSta =
    rtb_RelationalOperator_p;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CarriageLightSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->BoxLampSta;

  /* RelationalOperator: '<S305>/Relational Operator' incorporates:
   *  Constant: '<S305>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->J408BackLampPWM > 0);

  /* BusCreator: '<S285>/Bus Creator1' incorporates:
   *  Constant: '<S285>/Constant1'
   *  Constant: '<S285>/Constant10'
   *  Constant: '<S285>/Constant11'
   *  Constant: '<S285>/Constant12'
   *  Constant: '<S285>/Constant13'
   *  Constant: '<S285>/Constant15'
   *  Constant: '<S285>/Constant16'
   *  Constant: '<S285>/Constant17'
   *  Constant: '<S285>/Constant18'
   *  Constant: '<S285>/Constant19'
   *  Constant: '<S285>/Constant2'
   *  Constant: '<S285>/Constant20'
   *  Constant: '<S285>/Constant21'
   *  Constant: '<S285>/Constant22'
   *  Constant: '<S285>/Constant23'
   *  Constant: '<S285>/Constant24'
   *  Constant: '<S285>/Constant26'
   *  Constant: '<S285>/Constant29'
   *  Constant: '<S285>/Constant3'
   *  Constant: '<S285>/Constant37'
   *  Constant: '<S285>/Constant38'
   *  Constant: '<S285>/Constant39'
   *  Constant: '<S285>/Constant40'
   *  Constant: '<S285>/Constant41'
   *  Constant: '<S285>/Constant42'
   *  Constant: '<S285>/Constant43'
   *  Constant: '<S285>/Constant44'
   *  Constant: '<S285>/Constant45'
   *  Constant: '<S285>/Constant46'
   *  Constant: '<S285>/Constant5'
   *  Constant: '<S285>/Constant6'
   *  Constant: '<S285>/Constant7'
   *  Constant: '<S285>/Constant8'
   *  Constant: '<S285>/Constant9'
   *  DataTypeConversion: '<S285>/Data Type Conversion169'
   *  DataTypeConversion: '<S285>/Data Type Conversion172'
   *  DataTypeConversion: '<S285>/Data Type Conversion173'
   *  Logic: '<S285>/Logical Operator11'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiSwSig = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLiSts = rtb_MultiportSwitch;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarStaV_Hood = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LockHornOnStFb =
    AppSwcBcm_ARID_DEF.BusCreator9.LockHoornOnStFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AlrmHornReq =
    AppSwcBcm_ARID_DEF.BusCreator9.AlarmSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperCtrl_Front =
    rtb_MultiportSwitch_dq;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WashLiquidLevelWarn =
    AppSwcBcm_ConstB.BCM_WashLiquidLevelWarn;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiprIntlGearSwtSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSig = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig =
    BCM_DriverWinSwSig;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = BCM_PassWinSwSig;
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
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig =
    BCM_DrvPassWinSwSig;
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
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperStopPosSta = (uint8)
    !AppSwcBcm_ARID_DEF.BusCreator6.WiperParkPosSw;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLampSta =
    rtb_RelationalOperator_p;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SavePowerSta =
    AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr;

  /* BusCreator: '<S285>/Bus Creator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion73'
   *  DataTypeConversion: '<S285>/Data Type Conversion74'
   *  DataTypeConversion: '<S285>/Data Type Conversion75'
   *  DataTypeConversion: '<S285>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw;

  /* BusCreator: '<S285>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S285>/Data Type Conversion77'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator8'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw;

  /* BusCreator: '<S285>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S285>/Data Type Conversion78'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator9'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarRLSw;

  /* BusCreator: '<S285>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S285>/Data Type Conversion79'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator_p;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator10'
   */
  rtb_RelationalOperator_p = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarRRSw;

  /* BusCreator: '<S285>/Bus Creator2' incorporates:
   *  Constant: '<S285>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S285>/Data Type Conversion142'
   *  DataTypeConversion: '<S285>/Data Type Conversion143'
   *  DataTypeConversion: '<S285>/Data Type Conversion165'
   *  DataTypeConversion: '<S285>/Data Type Conversion67'
   *  DataTypeConversion: '<S285>/Data Type Conversion80'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAiarSta_RR =
    rtb_RelationalOperator_p;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.AppSwcBcmVersion = 6U;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_NMReq_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.NMReq;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SleepAllwd_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.SleepAllwd;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* RelationalOperator: '<S295>/Relational Operator' incorporates:
   *  Constant: '<S285>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S285>/Logical Operator1'
   *  RelationalOperator: '<S285>/Relational Operator'
   */
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->PartArmedSta == 1);
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus()
    )->EmerSta || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrLOpen || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->TurnIndcrROpen || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())
    ->AntiLckSta || rtb_RelationalOperator_p ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TrunkWarnSta);

  /* DataTypeConversion: '<S285>/Data Type Conversion93' */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_b = rtb_RelationalOperator_p;

  /* Switch: '<S295>/Switch' incorporates:
   *  Constant: '<S295>/Constant'
   *  Constant: '<S295>/Constant1'
   *  Constant: '<S295>/Constant2'
   *  Constant: '<S295>/Constant4'
   *  RelationalOperator: '<S295>/Relational Operator'
   *  RelationalOperator: '<S295>/Relational Operator1'
   *  Switch: '<S295>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 1) {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      282574488338432ULL;
  } else if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 2) {
    /* Switch: '<S295>/Switch1' incorporates:
     *  Constant: '<S295>/Constant3'
     *  Switch: '<S295>/Switch'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      564049465049088ULL;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl = 0ULL;
  }

  /* End of Switch: '<S295>/Switch' */

  /* Chart: '<S296>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S296>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HULck, 25, &rtb_RelationalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_b);

  /* Chart: '<S296>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S296>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HUUnlck, 25, &rtb_RelationalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1);

  /* DataTypeConversion: '<S285>/Data Type Conversion89' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_p =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrLSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion90' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_c =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->PosLampSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion91' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_f =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->DayRunLightSta;

  /* DataTypeConversion: '<S285>/Data Type Conversion92' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TurnIndcrRSta;

  /* BusCreator: '<S285>/Bus Creator' */
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

  /* Outputs for Atomic SubSystem: '<S285>/HwOutBCM' */
  AppSwcBcm_HwOutBCM();

  /* End of Outputs for SubSystem: '<S285>/HwOutBCM' */

  /* Update for UnitDelay: '<S290>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ni = rtb_MultiportSwitch;

  /* Update for UnitDelay: '<S310>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_lc = rtb_MultiportSwitch_dq;
}

/* Output and update for atomic system: '<S3>/EEReadCtl' */
static void AppSwcBcm_EEReadCtl(void)
{
  uint8 i;

  /* Chart: '<S286>/EEReadCtl' */
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
  EEReadCtl_BJSTimeDay = AppSwcBcm_ARID_DEF.data1[24];
  EEReadCtl_BJSTimeHour = AppSwcBcm_ARID_DEF.data1[25];
  EEReadCtl_BJSTimeMonth = AppSwcBcm_ARID_DEF.data1[26];
  EEReadCtl_BJSTimeYear = AppSwcBcm_ARID_DEF.data1[27];
  for (i = 0U; i < 10; i++) {
    EEReadCtl_DoorOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 29];
    EEReadCtl_LocalStartFailOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 39];
    EEReadCtl_RemoteStartFailRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 49];
    EEReadCtl_TrunkOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 59];
  }

  /* End of Chart: '<S286>/EEReadCtl' */
}

/*
 * System initialize for function-call system:
 *    '<S347>/Lib_RiseEdgeDetInit'
 *    '<S355>/Lib_RiseEdgeDetInit'
 *    '<S361>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S349>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S347>/Lib_RiseEdgeDetInit'
 *    '<S355>/Lib_RiseEdgeDetInit'
 *    '<S361>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
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
 * Output and update for function-call system:
 *    '<S341>/Lib_EdgeChgDet'
 *    '<S791>/Pri5.AntiLckFunc.Lib_EdgeChgDet'
 *    '<S791>/Pri5.SeekFunc.Lib_EdgeChgDet'
 *    '<S791>/Pri5.ArmedFunc.Lib_EdgeChgDet'
 *    '<S791>/Pri5.PartArmedFunc.Lib_EdgeChgDet'
 *    '<S791>/Pri5.DisarmedFunc.Lib_EdgeChgDet'
 *    '<S877>/Lib_EdgeChgDet'
 */
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S359>/Lib_EdgeChgDet' */
  /* RelationalOperator: '<S360>/Relational Operator' incorporates:
   *  UnitDelay: '<S360>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn != AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S360>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* End of Outputs for SubSystem: '<S359>/Lib_EdgeChgDet' */
}

/*
 * System initialize for atomic system:
 *    '<S370>/Lib_RiseEdgeDetInit'
 *    '<S800>/Lib_RiseEdgeDetInit'
 *    '<S804>/Lib_RiseEdgeDetInit'
 *    '<S807>/Lib_RiseEdgeDetInit'
 *    '<S808>/Lib_RiseEdgeDetInit'
 *    '<S818>/Lib_RiseEdgeDetInit'
 *    '<S846>/Lib_RiseEdgeDetInit'
 *    '<S881>/Lib_RiseEdgeDetInit'
 *    '<S882>/Lib_RiseEdgeDetInit'
 *    '<S883>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_d_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S371>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S370>/Lib_RiseEdgeDetInit'
 *    '<S800>/Lib_RiseEdgeDetInit'
 *    '<S804>/Lib_RiseEdgeDetInit'
 *    '<S807>/Lib_RiseEdgeDetInit'
 *    '<S808>/Lib_RiseEdgeDetInit'
 *    '<S818>/Lib_RiseEdgeDetInit'
 *    '<S846>/Lib_RiseEdgeDetInit'
 *    '<S881>/Lib_RiseEdgeDetInit'
 *    '<S882>/Lib_RiseEdgeDetInit'
 *    '<S883>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S371>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S371>/Logical Operator' incorporates:
   *  Delay: '<S371>/Delay'
   *  Logic: '<S371>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S371>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S369>/Lib_RiseEdgeDetInit'
 *    '<S799>/Lib_RiseEdgeDetInit'
 *    '<S803>/Lib_RiseEdgeDetInit'
 *    '<S817>/Lib_RiseEdgeDetInit'
 *    '<S845>/Lib_RiseEdgeDetInit'
 *    '<S880>/Lib_RiseEdgeDetInit'
 *    '<S880>/Lib_RiseEdgeDetInit1'
 *    '<S880>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_n_T *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S370>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S370>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S369>/Lib_RiseEdgeDetInit'
 *    '<S799>/Lib_RiseEdgeDetInit'
 *    '<S803>/Lib_RiseEdgeDetInit'
 *    '<S817>/Lib_RiseEdgeDetInit'
 *    '<S845>/Lib_RiseEdgeDetInit'
 *    '<S880>/Lib_RiseEdgeDetInit'
 *    '<S880>/Lib_RiseEdgeDetInit1'
 *    '<S880>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_n_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S370>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_e(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S370>/Lib_RiseEdgeDetInit' */
}

/* System initialize for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S339>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_my = true;

  /* SystemInitialize for Chart: '<S336>/Alarm' incorporates:
   *  SubSystem: '<S347>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ol);

  /* SystemInitialize for Chart: '<S338>/Armed' incorporates:
   *  SubSystem: '<S355>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_a);

  /* SystemInitialize for Chart: '<S343>/PartArmed' incorporates:
   *  SubSystem: '<S361>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

  /* SystemInitialize for Chart: '<S345>/Chart1' incorporates:
   *  SubSystem: '<S369>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_c);
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
  boolean rtb_RelationalOperator_o3;
  boolean tmp;

  /* Chart: '<S340>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S340>/Constant'
   *  Constant: '<S340>/Constant37'
   *  Constant: '<S340>/Constant38'
   *  Constant: '<S340>/Constant39'
   *  RelationalOperator: '<S340>/Relational Operator'
   */
  if (BSW_J319HornSw == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_oj >= (float32)HornCtl_HornSwTimValid_C /
         (HornCtl_Ts_C * 100.0F)) && (HornCtl_HornSwTimValid_C != 0xFFFF)) {
      HornCtl_HornSwCtl = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_oj++;
      AppSwcBcm_ARID_DEF.cnt_heal_l4 = (uint16)((float32)
        HornCtl_HornSwTimInvalid_C / (HornCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_oj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_l4 == 0) {
      HornCtl_HornSwCtl = false;
    } else if (HornCtl_HornSwTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_l4--;
    }
  }

  /* End of Chart: '<S340>/LIB_TPD_10ms' */

  /* Chart: '<S336>/Alarm' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AlarmSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AlarmSta = 1U;
    AppSwcBcm_ARID_DEF.Lib_blIn_mu =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 2);

    /* Outputs for Function Call SubSystem: '<S347>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_mu,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ay,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ol);

    /* End of Outputs for SubSystem: '<S347>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ay || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AlarmSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AlarmSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_mu =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S347>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_mu,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ay,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_ol);

    /* End of Outputs for SubSystem: '<S347>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ay) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_AlarmSta = 1U;
    }
  }

  /* End of Chart: '<S336>/Alarm' */

  /* RelationalOperator: '<S339>/Relational Operator' incorporates:
   *  Constant: '<S339>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S339>/Relational Operator1'
   */
  rtb_RelationalOperator_o3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Delay: '<S339>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_my) {
    /* Switch: '<S339>/Switch' incorporates:
     *  Constant: '<S339>/Constant'
     *  Constant: '<S339>/Constant5'
     *  RelationalOperator: '<S339>/Relational Operator'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_i = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_i =
        AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts;
    }

    /* End of Switch: '<S339>/Switch' */
  }

  /* Switch: '<S339>/Switch1' incorporates:
   *  Constant: '<S339>/Constant7'
   */
  if (rtb_RelationalOperator_o3) {
    rtb_HornCtl_Sta = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HULckHornOnSt_enum;
  } else {
    rtb_HornCtl_Sta = 0U;
  }

  /* MultiPortSwitch: '<S339>/Multiport Switch' incorporates:
   *  Switch: '<S339>/Switch1'
   */
  switch (rtb_HornCtl_Sta) {
   case 1:
    /* MultiPortSwitch: '<S339>/Multiport Switch' incorporates:
     *  Constant: '<S339>/Constant1'
     */
    HornCtl_LockHoornOnSt = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S339>/Multiport Switch' incorporates:
     *  Constant: '<S339>/Constant2'
     */
    HornCtl_LockHoornOnSt = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S339>/Multiport Switch' incorporates:
     *  Delay: '<S339>/Delay'
     */
    HornCtl_LockHoornOnSt = AppSwcBcm_ARID_DEF.Delay_DSTATE_i;
    break;
  }

  /* End of MultiPortSwitch: '<S339>/Multiport Switch' */

  /* MultiPortSwitch: '<S339>/Multiport Switch1' */
  switch (HornCtl_LockHoornOnSt) {
   case 1:
    /* MultiPortSwitch: '<S339>/Multiport Switch1' incorporates:
     *  Constant: '<S339>/Constant3'
     */
    HornCtl_LockHoornOnStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S339>/Multiport Switch1' incorporates:
     *  Constant: '<S339>/Constant4'
     */
    HornCtl_LockHoornOnStFb = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S339>/Multiport Switch1' */

  /* Chart: '<S337>/AntiLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S287>/Unit Delay3'
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

    /* Outputs for Function Call SubSystem: '<S350>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_pd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jk,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_e);

    /* End of Outputs for SubSystem: '<S350>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jk) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_nk =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck;

      /* Outputs for Function Call SubSystem: '<S350>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_nk,
        &AppSwcBcm_ARID_DEF.LogicalOperator_f0,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_j);

      /* End of Outputs for SubSystem: '<S350>/Lib_RiseEdgeDet1' */
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

  /* End of Chart: '<S337>/AntiLck' */

  /* Chart: '<S338>/Armed' incorporates:
   *  UnitDelay: '<S287>/Unit Delay'
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

    /* Outputs for Function Call SubSystem: '<S355>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_nt,
      &AppSwcBcm_ARID_DEF.LogicalOperator_cw,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_a);

    /* End of Outputs for SubSystem: '<S355>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_cw && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_ArmedSta = 1U;
    }
  }

  /* End of Chart: '<S338>/Armed' */

  /* Chart: '<S343>/PartArmed' incorporates:
   *  UnitDelay: '<S287>/Unit Delay1'
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

    /* Outputs for Function Call SubSystem: '<S361>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_bp,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fp,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

    /* End of Outputs for SubSystem: '<S361>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fp && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_PartArmedSta = 1U;
    }
  }

  /* End of Chart: '<S343>/PartArmed' */

  /* Chart: '<S344>/Seek' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S287>/Unit Delay2'
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

      /* Outputs for Function Call SubSystem: '<S364>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_f1,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ek,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pc);

      /* End of Outputs for SubSystem: '<S364>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ek && (HornCtl_LockHoornOnStFb == 1))
      {
        AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_RKESetON;
        HornCtl_SeekSta = 1U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_nx =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->VehSeekSta == 2);

        /* Outputs for Function Call SubSystem: '<S364>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_nx,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ev,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_k);

        /* End of Outputs for SubSystem: '<S364>/Lib_RiseEdgeDet1' */
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

  /* End of Chart: '<S344>/Seek' */

  /* Chart: '<S345>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S287>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_HornCtl_Lib = AppSwcBcm_IN_SetOff_i;
    HornCtl_TrunkWarnSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c1_HornCtl_Lib == AppSwcBcm_IN_SetOff_i) {
    HornCtl_TrunkWarnSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_bf =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_LampCtl_Bus())->TrunkWarnSta;

    /* Outputs for Function Call SubSystem: '<S369>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_bf,
      &AppSwcBcm_ARID_DEF.LogicalOperator_bd,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_c);

    /* End of Outputs for SubSystem: '<S369>/Lib_RiseEdgeDetInit' */
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

  /* End of Chart: '<S345>/Chart1' */

  /* Truth Table: '<S287>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  rtb_RelationalOperator_o3 = (HornCtl_PartArmedSta == 1);

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
    if (rtb_RelationalOperator_o3 && tmp) {
      /*  Example action 2 called from D3 column in condition table */
      rtb_HornCtl_DemCnt = 3U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 2U;
    } else if ((!rtb_RelationalOperator_o3) && (HornCtl_ArmedSta == 1) && tmp) {
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

  /* End of Truth Table: '<S287>/Truth Table' */

  /* RelationalOperator: '<S287>/Relational Operator' incorporates:
   *  UnitDelay: '<S287>/Unit Delay4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ggl = (rtb_HornCtl_Sta !=
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_l);

  /* Chart: '<S287>/LIB_Pulse' incorporates:
   *  SubSystem: '<S341>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_ggl,
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

  /* Outputs for Atomic SubSystem: '<S287>/Ovrd1' */
  /* Switch: '<S342>/Switch1' incorporates:
   *  Constant: '<S287>/Constant18'
   */
  if (HornCtl_J430HornDrvOvrdFlg_C) {
    /* Switch: '<S342>/Switch1' incorporates:
     *  Constant: '<S287>/Constant19'
     */
    HornCtl_J430HornDrv = HornCtl_J430HornDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S287>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator_o3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->HornCtlFlg != 0);

    /* Switch: '<S342>/Switch2' */
    if (rtb_RelationalOperator_o3) {
      /* Switch: '<S342>/Switch1' incorporates:
       *  Switch: '<S342>/Switch2'
       */
      HornCtl_J430HornDrv = true;
    } else {
      /* Switch: '<S342>/Switch1' incorporates:
       *  Constant: '<S287>/Constant'
       *  RelationalOperator: '<S287>/Relational Operator1'
       *  Switch: '<S287>/Switch'
       *  Switch: '<S342>/Switch2'
       */
      HornCtl_J430HornDrv =
        ((AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum != 1) &&
         AppSwcBcm_ARID_DEF.LIB_blOut_b);
    }

    /* End of Switch: '<S342>/Switch2' */
  }

  /* End of Switch: '<S342>/Switch1' */
  /* End of Outputs for SubSystem: '<S287>/Ovrd1' */

  /* Update for Delay: '<S339>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_my = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_i = HornCtl_LockHoornOnSt;

  /* Update for UnitDelay: '<S287>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_l = rtb_HornCtl_Sta;
}

/*
 * System initialize for atomic system:
 *    '<S372>/LIB_TPD1'
 *    '<S372>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg)
{
  *rty_LIB_u8ErrFlg = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S372>/LIB_TPD1'
 *    '<S372>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg)
{
  boolean guard1 = false;

  /* Chart: '<S372>/LIB_TPD1' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blAllowRecov;

  /* Outputs for Function Call SubSystem: '<S385>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator_i,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S385>/Lib_RiseEdgeDet' */

  /* Chart: '<S372>/LIB_TPD1' */
  guard1 = false;
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator_i) {
    guard1 = true;
  } else {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn_n = rtu_LIB_blAllowRecov1;

    /* Outputs for Function Call SubSystem: '<S385>/Lib_RiseEdgeDet1' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm__ARID_DEF_arg->Lib_blIn_n,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet1);

    /* End of Outputs for SubSystem: '<S385>/Lib_RiseEdgeDet1' */
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

/* System initialize for atomic system: '<S288>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt_Init(void)
{
  /* SystemInitialize for Chart: '<S372>/LIB_TPD1' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_b);

  /* SystemInitialize for Chart: '<S372>/LIB_TPD2' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg);
}

/* Output and update for atomic system: '<S288>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator3_ea;

  /* Logic: '<S372>/Logical Operator' incorporates:
   *  UnitDelay: '<S288>/Unit Delay'
   *  UnitDelay: '<S288>/Unit Delay1'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_fz);

  /* RelationalOperator: '<S372>/Relational Operator3' incorporates:
   *  Constant: '<S372>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_ea = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S372>/LIB_TPD2' incorporates:
   *  Constant: '<S372>/Constant1'
   *  Constant: '<S372>/Constant2'
   *  Logic: '<S372>/Logical Operator1'
   *  RelationalOperator: '<S372>/Relational Operator'
   *  RelationalOperator: '<S372>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(rtb_LogicalOperator && (!WiperCtl_WiperParkPosSw),
                     WiperCtl_LockedRotorTimDef_C, WiperCtl_LockedRotorTimOk_C,
                     WiperCtl_WiperOffSw, rtb_RelationalOperator3_ea,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD2);

  /* Chart: '<S372>/LIB_TPD1' incorporates:
   *  Constant: '<S372>/Constant4'
   *  Constant: '<S372>/Constant5'
   *  Logic: '<S372>/Logical Operator3'
   *  RelationalOperator: '<S372>/Relational Operator1'
   *  RelationalOperator: '<S372>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(WiperCtl_WiperParkPosSw && rtb_LogicalOperator,
                     WiperCtl_LockedRotorTimParkDef_C,
                     WiperCtl_LockedRotorTimParkOk_C, WiperCtl_WiperOffSw,
                     rtb_RelationalOperator3_ea,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_b,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD1);

  /* Logic: '<S372>/Logical Operator2' */
  WiperCtl_LockedRotorProtSta = ((AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_b != 0) ||
    (AppSwcBcm_ARID_DEF.LIB_u8ErrFlg != 0));
}

/*
 * Output and update for atomic system:
 *    '<S376>/Bit Shift1'
 *    '<S470>/Bit Shift1'
 *    '<S674>/Bit Shift4'
 */
static uint16 AppSwcBcm_BitShift1_i(uint16 rtu_u)
{
  /* MATLAB Function: '<S395>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S376>/Bit Shift2'
 *    '<S470>/Bit Shift2'
 *    '<S674>/Bit Shift7'
 */
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u)
{
  /* MATLAB Function: '<S396>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 2);
}

/* Output and update for atomic system: '<S288>/SignalProcess' */
static void AppSwcBcm_SignalProcess(void)
{
  uint16 rtb_y;
  uint8 rtb_Switch5_d;
  boolean rtb_Switch1_p;

  /* Outputs for Atomic SubSystem: '<S376>/Bit Shift5' */
  /* Constant: '<S376>/Constant59' */
  rtb_y = AppSwcBcm_BitShift3(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S376>/Bit Shift5' */

  /* Switch: '<S376>/Switch5' incorporates:
   *  RelationalOperator: '<S376>/Relational Operator'
   *  S-Function (sfix_bitop): '<S376>/Bitwise AND5'
   *  Switch: '<S376>/Switch'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S376>/Switch5' incorporates:
     *  Constant: '<S376>/Constant60'
     */
    rtb_Switch5_d = WiperCtl_WiperSwVal_C;
  } else if (SCS_WiprSwtStVD) {
    /* Switch: '<S376>/Switch' incorporates:
     *  Switch: '<S376>/Switch5'
     */
    rtb_Switch5_d = SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S376>/Switch5' incorporates:
     *  Constant: '<S376>/Constant23'
     *  Switch: '<S376>/Switch'
     */
    rtb_Switch5_d = 0U;
  }

  /* End of Switch: '<S376>/Switch5' */

  /* Chart: '<S376>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S376>/Constant14'
   *  Constant: '<S376>/Constant46'
   *  Constant: '<S376>/Constant47'
   *  Constant: '<S376>/Constant49'
   *  RelationalOperator: '<S376>/Relational Operator9'
   */
  if (rtb_Switch5_d == 4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_dy >= (float32)WiperCtl_MistTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_MistTimValid_C != 0xFFFF)) {
      WiperCtl_WiperMistSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_dy++;
      AppSwcBcm_ARID_DEF.cnt_heal_htn = (uint16)((float32)
        WiperCtl_MistTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_dy = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_htn == 0) {
      WiperCtl_WiperMistSw = false;
    } else if (WiperCtl_MistTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_htn--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms' */

  /* Chart: '<S376>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S376>/Constant1'
   *  Constant: '<S376>/Constant3'
   *  Constant: '<S376>/Constant4'
   *  Constant: '<S376>/Constant5'
   *  RelationalOperator: '<S376>/Relational Operator1'
   */
  if (rtb_Switch5_d == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o1 >= (float32)WiperCtl_OffTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_OffTimValid_C != 0xFFFF)) {
      WiperCtl_WiperOffSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o1++;
      AppSwcBcm_ARID_DEF.cnt_heal_ej = (uint16)((float32)
        WiperCtl_OffTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ej == 0) {
      WiperCtl_WiperOffSw = false;
    } else if (WiperCtl_OffTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ej--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms1' */

  /* Chart: '<S376>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S376>/Constant10'
   *  Constant: '<S376>/Constant2'
   *  Constant: '<S376>/Constant8'
   *  Constant: '<S376>/Constant9'
   *  RelationalOperator: '<S376>/Relational Operator2'
   */
  if (rtb_Switch5_d == 1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_dw >= (float32)WiperCtl_InrTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_InrTimValid_C != 0xFFFF)) {
      WiperCtl_WiperInrSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_dw++;
      AppSwcBcm_ARID_DEF.cnt_heal_lc = (uint16)((float32)
        WiperCtl_InrTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_dw = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lc == 0) {
      WiperCtl_WiperInrSw = false;
    } else if (WiperCtl_InrTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_lc--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms2' */

  /* Chart: '<S376>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S376>/Constant11'
   *  Constant: '<S376>/Constant16'
   *  Constant: '<S376>/Constant17'
   *  Constant: '<S376>/Constant6'
   *  RelationalOperator: '<S376>/Relational Operator3'
   */
  if (rtb_Switch5_d == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_dd >= (float32)WiperCtl_LowSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_LowSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperLowSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_dd++;
      AppSwcBcm_ARID_DEF.cnt_heal_jt = (uint16)((float32)
        WiperCtl_LowSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_dd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_jt == 0) {
      WiperCtl_WiperLowSpdSw = false;
    } else if (WiperCtl_LowSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_jt--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms3' */

  /* Chart: '<S376>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S376>/Constant18'
   *  Constant: '<S376>/Constant21'
   *  Constant: '<S376>/Constant22'
   *  Constant: '<S376>/Constant7'
   *  RelationalOperator: '<S376>/Relational Operator4'
   */
  if (rtb_Switch5_d == 3) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_iq >= (float32)WiperCtl_HiSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_HiSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperHiSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_iq++;
      AppSwcBcm_ARID_DEF.cnt_heal_ht = (uint16)((float32)
        WiperCtl_HiSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_iq = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ht == 0) {
      WiperCtl_WiperHiSpdSw = false;
    } else if (WiperCtl_HiSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ht--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S376>/Bit Shift1' */
  /* Constant: '<S376>/Constant28' */
  rtb_y = AppSwcBcm_BitShift1_i(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S376>/Bit Shift1' */

  /* Switch: '<S376>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S376>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S376>/Switch1' incorporates:
     *  Constant: '<S376>/Constant29'
     */
    rtb_Switch1_p = WiperCtl_WashVal_C;
  } else {
    /* Switch: '<S376>/Switch1' incorporates:
     *  RelationalOperator: '<S376>/Relational Operator5'
     *  Switch: '<S376>/Switch3'
     */
    rtb_Switch1_p = (SCS_FrntWshrSwtStVD && SCS_FrntWshrSwtSt);
  }

  /* End of Switch: '<S376>/Switch1' */

  /* Chart: '<S376>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S376>/Constant25'
   *  Constant: '<S376>/Constant26'
   *  Constant: '<S376>/Constant27'
   */
  if (rtb_Switch1_p) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_iv >= (float32)WiperCtl_WashTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashTimValid_C != 0xFFFF)) {
      WiperCtl_WashSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_iv++;
      AppSwcBcm_ARID_DEF.cnt_heal_oc = (uint16)((float32)
        WiperCtl_WashTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_iv = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_oc == 0) {
      WiperCtl_WashSw = false;
    } else if (WiperCtl_WashTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_oc--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S376>/Bit Shift2' */
  /* Constant: '<S376>/Constant35' */
  rtb_y = AppSwcBcm_BitShift2(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S376>/Bit Shift2' */

  /* Switch: '<S376>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S376>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S376>/Switch2' incorporates:
     *  Constant: '<S376>/Constant36'
     */
    rtb_Switch1_p = WiperCtl_WiperParkPosVal_C;
  } else {
    /* Switch: '<S376>/Switch2' incorporates:
     *  DataTypeConversion: '<S376>/Data Type Conversion2'
     */
    rtb_Switch1_p = (BSW_J334WiperParkPos != 0);
  }

  /* End of Switch: '<S376>/Switch2' */

  /* Chart: '<S376>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S376>/Constant32'
   *  Constant: '<S376>/Constant33'
   *  Constant: '<S376>/Constant34'
   *  Logic: '<S376>/Logical Operator5'
   */
  if (!rtb_Switch1_p) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ii >= (float32)
         WiperCtl_WiperParkPosTimValid_C / (WiperCtl_Ts_C * 100.0F)) &&
        (WiperCtl_WiperParkPosTimValid_C != 0xFFFF)) {
      WiperCtl_WiperParkPosSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ii++;
      AppSwcBcm_ARID_DEF.cnt_heal_da = (uint16)((float32)
        WiperCtl_WiperPosTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ii = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_da == 0) {
      WiperCtl_WiperParkPosSw = false;
    } else if (WiperCtl_WiperPosTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_da--;
    }
  }

  /* End of Chart: '<S376>/LIB_TPD_10ms6' */
}

/* System initialize for atomic system: '<S288>/WashCtl' */
static void AppSwcBcm_WashCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S377>/LIB_Tim' */
  AppSwcBcm_LIB_NegPluse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_a2);
}

/* Output and update for atomic system: '<S288>/WashCtl' */
static void AppSwcBcm_WashCtl(void)
{
  boolean rtb_RelationalOperator1_e2;

  /* RelationalOperator: '<S377>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_e2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Chart: '<S377>/LIB_Tim' incorporates:
   *  Constant: '<S377>/Constant'
   *  Logic: '<S377>/Logical Operator'
   *  RelationalOperator: '<S377>/Relational Operator'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator1_e2 && WiperCtl_WashSw,
    WiperCtl_WashMaxTim_C, &AppSwcBcm_ARID_DEF.LIB_blOut_a2,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_h);

  /* Chart: '<S377>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S377>/Constant3'
   *  Constant: '<S377>/Constant34'
   *  Constant: '<S377>/Constant4'
   *  Logic: '<S377>/Logical Operator1'
   *  Logic: '<S377>/Logical Operator2'
   *  RelationalOperator: '<S377>/Relational Operator2'
   *  RelationalOperator: '<S377>/Relational Operator3'
   *  RelationalOperator: '<S377>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_a2 && (WiperCtl_WiperInrSta ||
       WiperCtl_WiperOffSta) && (!AppSwcBcm_ARID_DEF.UnitDelay8_c)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_h2 >= (float32)WiperCtl_WashMinTim_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashMinTim_C != 0xFFFF)) {
      WiperCtl_WashWiperSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_h2++;
      AppSwcBcm_ARID_DEF.cnt_heal_b = (uint16)(1.0F / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_h2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_b == 0) {
      WiperCtl_WashWiperSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_b--;
    }
  }

  /* End of Chart: '<S377>/LIB_TPD_10ms6' */
}

/*
 * Output and update for function-call system:
 *    '<S410>/Nrm.Off.Lib_RiseEdgeDet'
 *    '<S410>/Wash.Lib_RiseEdgeDet'
 *    '<S410>/Lib_RiseEdgeDet'
 *    '<S465>/Lib_RiseEdgeDet'
 *    '<S521>/Lib_RiseEdgeDet'
 *    '<S605>/Lib_RiseEdgeDet'
 *    '<S609>/Lib_RiseEdgeDet'
 *    '<S613>/Lib_RiseEdgeDet'
 *    '<S617>/Lib_RiseEdgeDet'
 *    '<S678>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_NrmOffLib_RiseEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_NrmOffLib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S419>/Logical Operator' incorporates:
   *  Logic: '<S419>/Logical Operator1'
   *  UnitDelay: '<S419>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S419>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S410>/Wash.Lib_RiseEdgeDetInit'
 *    '<S410>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S421>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S410>/Wash.Lib_RiseEdgeDetInit'
 *    '<S410>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S421>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S421>/Logical Operator' incorporates:
   *  Delay: '<S421>/Delay'
   *  Logic: '<S421>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S421>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S378>/Chart' */
static void AppSwcBcm_enter_internal_Off(void)
{
  sint32 tmp;
  WiperCtl_WiperSta = 0U;
  AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
  AppSwcBcm_ARID_DEF.Lib_blIn_cb =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

  /* Outputs for Function Call SubSystem: '<S410>/Nrm.Off.Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_cb,
    &AppSwcBcm_ARID_DEF.LogicalOperator_lx,
    &AppSwcBcm_ARID_DEF.ARID_DEF_NrmOffLib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S410>/Nrm.Off.Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_lx) {
    AppSwcBcm_ARID_DEF.Flg_du = true;
    AppSwcBcm_ARID_DEF.Cnt_jp = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_du) {
    /* UnitDelay: '<S288>/Unit Delay2' */
    if ((AppSwcBcm_ARID_DEF.Cnt_jp >= WiperCtl_WiperReturnDelayTim_C) &&
        (!WiperCtl_WiperParkPosSw) && (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h))
    {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
    } else if ((AppSwcBcm_ARID_DEF.Cnt_jp >= WiperCtl_WiperReturnDelayTim_C) &&
               (WiperCtl_WiperParkPosSw ||
                AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h)) {
      AppSwcBcm_ARID_DEF.Flg_du = false;
      AppSwcBcm_ARID_DEF.Cnt_jp = 0U;
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_jp + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_jp + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_jp = (uint16)tmp;
    }

    /* End of UnitDelay: '<S288>/Unit Delay2' */
  } else {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
  }
}

/* Function for Chart: '<S378>/Chart' */
static void AppSwcBcm_enter_internal_Inr(void)
{
  WiperCtl_WiperSta = 4U;
  AppSwcBcm_ARID_DEF.cnt_g = 0U;
  if (WiperCtl_WiperInrSta) {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
    if ((WiperCtl_InrTim + AppSwcBcm_ARID_DEF.cnt2) - 1 > 0) {
      AppSwcBcm_ARID_DEF.cnt_g = 1U;
    }
  }
}

/* Function for Chart: '<S378>/Chart' */
static void AppSwcBcm_HiSpdFunc(void)
{
  AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
  AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = true;
  WiperCtl_WiperSta = 3U;
}

/* Function for Chart: '<S378>/Chart' */
static void AppSwcBcm_Nrm(void)
{
  sint32 tmp;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_LogicalOperator1_ny;
  if (WiperCtl_WashWiperSta) {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_Inr:
      AppSwcBcm_ARID_DEF.cnt_g = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     case AppSwcBcm_IN_Off_d1:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     default:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;
    }

    AppSwcBcm_ARID_DEF.is_c9_WiperCtl_Lib = AppSwcBcm_IN_Wash;
    WiperCtl_WiperSta = 5U;
    AppSwcBcm_ARID_DEF.after_cnt = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
    AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
    if (WiperCtl_WiperMistSta || WiperCtl_WiperHiSpdSta ||
        WiperCtl_WiperLowSpdSta) {
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_gb = WiperCtl_WiperInrSta;
      AppSwcBcm_ARID_DEF.Lib_blInit_p = WiperCtl_WiperInrSta;

      /* Outputs for Function Call SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_gb,
        AppSwcBcm_ARID_DEF.Lib_blInit_p, &AppSwcBcm_ARID_DEF.LogicalOperator_ml,
        &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
        AppSwcBcm_ARID_DEF.LogicalOperator_ml;
    }
  } else if (WiperCtl_WiperMaintSta) {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_Inr:
      AppSwcBcm_ARID_DEF.cnt_g = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     case AppSwcBcm_IN_Off_d1:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;

     default:
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD;
      break;
    }

    AppSwcBcm_ARID_DEF.is_c9_WiperCtl_Lib = AppSwcBcm_IN_Maint;
    WiperCtl_WiperSta = 6U;
    AppSwcBcm_ARID_DEF.Cnt_jp = 0U;
    if (WiperCtl_MaintWiperRunTim_C <= 0) {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;

      /* WiperCtl_MaintStaComp=1; */
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
      AppSwcBcm_ARID_DEF.Cnt_jp = 1U;

      /* WiperCtl_MaintStaComp=0; */
    }
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_HiSpd:
      if (WiperCtl_WiperLowSpdSta || (!WiperCtl_WiperHiSpdSta) ||
          WiperCtl_WiperOffSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;

        /* UnitDelay: '<S288>/Unit Delay2' */
        /* (WiperCtl_WiperHiSpdSta==0||WiperCtl_WiperOffSta==1)&&WiperCtl_WiperParkPosSta==1||... */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
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
        AppSwcBcm_ARID_DEF.cnt_g = 0U;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if ((WiperCtl_WiperOffSta && WiperCtl_WiperParkPosSw) ||
                 AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h) {
        AppSwcBcm_ARID_DEF.cnt_g = 0U;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
        AppSwcBcm_enter_internal_Off();
      } else {
        rtb_LogicalOperator1_ny = !WiperCtl_WiperInrSta;
        if (WiperCtl_WiperHiSpdSta && rtb_LogicalOperator1_ny) {
          AppSwcBcm_ARID_DEF.cnt_g = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
        } else if (rtb_LogicalOperator1_ny && WiperCtl_WiperLowSpdSta) {
          AppSwcBcm_ARID_DEF.cnt_g = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
        } else {
          if (WiperCtl_InrTimChg) {
            AppSwcBcm_ARID_DEF.cnt_g = 0U;
          }

          if (WiperCtl_WiperInrSta) {
            if (AppSwcBcm_ARID_DEF.cnt_g == 0) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
              AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
            } else {
              /* Outputs for Function Call SubSystem: '<S410>/Nrm.Inr.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.icLoad_jl) {
                /* Delay: '<S418>/Delay' */
                AppSwcBcm_ARID_DEF.Delay_DSTATE_k = WiperCtl_WiperParkPosSw;
              }

              /* Logic: '<S418>/Logical Operator1' incorporates:
               *  Delay: '<S418>/Delay'
               */
              rtb_LogicalOperator1_ny = !AppSwcBcm_ARID_DEF.Delay_DSTATE_k;

              /* Update for Delay: '<S418>/Delay' */
              AppSwcBcm_ARID_DEF.icLoad_jl = false;
              AppSwcBcm_ARID_DEF.Delay_DSTATE_k = WiperCtl_WiperParkPosSw;

              /* Logic: '<S418>/Logical Operator' */
              if (WiperCtl_WiperParkPosSw && rtb_LogicalOperator1_ny &&
                  (AppSwcBcm_ARID_DEF.cnt_g > 10)) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
                AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
                AppSwcBcm_ARID_DEF.cnt2 = AppSwcBcm_ARID_DEF.cnt_g;
              }

              /* End of Logic: '<S418>/Logical Operator' */
              /* End of Outputs for SubSystem: '<S410>/Nrm.Inr.Lib_RiseEdgeDetInit' */
            }

            if (AppSwcBcm_ARID_DEF.cnt_g >= (WiperCtl_InrTim +
                 AppSwcBcm_ARID_DEF.cnt2) - 1) {
              AppSwcBcm_ARID_DEF.cnt_g = 0U;
            } else {
              tmp = AppSwcBcm_ARID_DEF.cnt_g + 1;
              if (AppSwcBcm_ARID_DEF.cnt_g + 1 > 65535) {
                tmp = 65535;
              }

              AppSwcBcm_ARID_DEF.cnt_g = (uint16)tmp;
            }
          }
        }
      }
      break;

     case AppSwcBcm_IN_LowSpd:
      /* UnitDelay: '<S288>/Unit Delay2' */
      if ((WiperCtl_WiperOffSta && WiperCtl_WiperParkPosSw) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
        AppSwcBcm_enter_internal_Off();
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
        WiperCtl_WiperSta = 2U;

        /* ex:WiperCtl_LowSpdDrv=0; */
      }
      break;

     case AppSwcBcm_IN_Mist:
      if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else if (WiperCtl_WiperOffSta) {
        AppSwcBcm_ARID_DEF.Lib_blIn_jg = WiperCtl_WiperParkPosSw;

        /* Outputs for Function Call SubSystem: '<S410>/Lib_RiseEdgeDet' */
        AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_jg,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jz,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mc);

        /* End of Outputs for SubSystem: '<S410>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_jz) {
          guard1 = true;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
      break;

     default:
      /* case IN_Off: */
      if (WiperCtl_WiperMistSta) {
        AppSwcBcm_ARID_DEF.Lib_blIn_jg = WiperCtl_WiperParkPosSw;

        /* Outputs for Function Call SubSystem: '<S410>/Lib_RiseEdgeDet' */
        AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_jg,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jz,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mc);

        /* End of Outputs for SubSystem: '<S410>/Lib_RiseEdgeDet' */
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Mist;
      } else if (WiperCtl_WiperInrSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Inr;
        AppSwcBcm_enter_internal_Inr();
      } else if (WiperCtl_WiperLowSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_cb =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

        /* Outputs for Function Call SubSystem: '<S410>/Nrm.Off.Lib_RiseEdgeDet' */
        AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_cb,
          &AppSwcBcm_ARID_DEF.LogicalOperator_lx,
          &AppSwcBcm_ARID_DEF.ARID_DEF_NrmOffLib_RiseEdgeDet);

        /* End of Outputs for SubSystem: '<S410>/Nrm.Off.Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_lx) {
          AppSwcBcm_ARID_DEF.Flg_du = true;
          AppSwcBcm_ARID_DEF.Cnt_jp = 0U;
        }

        if (AppSwcBcm_ARID_DEF.Flg_du) {
          /* UnitDelay: '<S288>/Unit Delay2' */
          if ((AppSwcBcm_ARID_DEF.Cnt_jp >= WiperCtl_WiperReturnDelayTim_C) && (
               !WiperCtl_WiperParkPosSw) &&
              (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h)) {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
          } else if ((AppSwcBcm_ARID_DEF.Cnt_jp >=
                      WiperCtl_WiperReturnDelayTim_C) &&
                     (WiperCtl_WiperParkPosSw ||
                      AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h)) {
            AppSwcBcm_ARID_DEF.Flg_du = false;
            AppSwcBcm_ARID_DEF.Cnt_jp = 0U;
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
          } else {
            tmp = AppSwcBcm_ARID_DEF.Cnt_jp + 1;
            if (AppSwcBcm_ARID_DEF.Cnt_jp + 1 > 65535) {
              tmp = 65535;
            }

            AppSwcBcm_ARID_DEF.Cnt_jp = (uint16)tmp;
          }
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
        }
      }
      break;
    }

    if (guard2) {
      if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h) {
        guard1 = true;
      } else if (WiperCtl_WiperLowSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
      } else if (WiperCtl_WiperHiSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
        WiperCtl_WiperSta = 1U;

        /* ex:WiperCtl_LowSpdDrv=0; */
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
      AppSwcBcm_enter_internal_Off();
    }
  }
}

/* System initialize for atomic system: '<S288>/WiperDrv' */
static void AppSwcBcm_WiperDrv_Init(void)
{
  /* SystemInitialize for Chart: '<S378>/Chart' incorporates:
   *  SubSystem: '<S410>/Nrm.Inr.Lib_RiseEdgeDetInit'
   */
  /* InitializeConditions for Delay: '<S418>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_jl = true;

  /* SystemInitialize for Chart: '<S378>/Chart' incorporates:
   *  SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S378>/Chart' incorporates:
   *  SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);
}

/* Output and update for atomic system: '<S288>/WiperDrv' */
static void AppSwcBcm_WiperDrv(void)
{
  sint32 tmp;

  /* Chart: '<S378>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S288>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c9_WiperCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c9_WiperCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c9_WiperCtl_Lib = AppSwcBcm_IN_Nrm;
    AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
    AppSwcBcm_enter_internal_Off();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c9_WiperCtl_Lib) {
     case AppSwcBcm_IN_Maint:
      if ((!WiperCtl_WiperMaintSta) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h) {
        AppSwcBcm_ARID_DEF.is_c9_WiperCtl_Lib = AppSwcBcm_IN_Nrm;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
        AppSwcBcm_enter_internal_Off();
      } else if (AppSwcBcm_ARID_DEF.Cnt_jp >= WiperCtl_MaintWiperRunTim_C) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;

        /* WiperCtl_MaintStaComp=1; */
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
        AppSwcBcm_ARID_DEF.Cnt_jp++;

        /* WiperCtl_MaintStaComp=0; */
      }
      break;

     case AppSwcBcm_IN_Nrm:
      AppSwcBcm_Nrm();
      break;

     default:
      /* case IN_Wash: */
      if (((!WiperCtl_WashWiperSta) && AppSwcBcm_ARID_DEF.WiperCtl_WashComp) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h ||
          (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) &&
           WiperCtl_WiperParkPosSw)) {
        AppSwcBcm_ARID_DEF.is_c9_WiperCtl_Lib = AppSwcBcm_IN_Nrm;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d1;
        AppSwcBcm_enter_internal_Off();
      } else {
        if (WiperCtl_WashWiperSta) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_pz = WiperCtl_WiperParkPosSw;

          /* Outputs for Function Call SubSystem: '<S410>/Wash.Lib_RiseEdgeDet' */
          AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_pz,
            &AppSwcBcm_ARID_DEF.LogicalOperator_at,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDet);

          /* End of Outputs for SubSystem: '<S410>/Wash.Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_at) {
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
              AppSwcBcm_ARID_DEF.Lib_blIn_gg = WiperCtl_WiperParkPosSw;
              AppSwcBcm_ARID_DEF.Lib_blInit_j = true;

              /* Outputs for Function Call SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit' */
              AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_gg,
                true, &AppSwcBcm_ARID_DEF.LogicalOperator_cc,
                &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

              /* End of Outputs for SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_cc) {
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
          AppSwcBcm_ARID_DEF.Lib_blIn_gb = WiperCtl_WiperInrSta;
          AppSwcBcm_ARID_DEF.Lib_blInit_p = WiperCtl_WiperInrSta;

          /* Outputs for Function Call SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_gb,
            AppSwcBcm_ARID_DEF.Lib_blInit_p,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ml,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

          /* End of Outputs for SubSystem: '<S410>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
            (AppSwcBcm_ARID_DEF.LogicalOperator_ml ||
             AppSwcBcm_ARID_DEF.WiperCtl_WashComp);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S378>/Chart' */
}

/* Output and update for atomic system: '<S288>/WiperHiSpdCtl' */
static void AppSwcBcm_WiperHiSpdCtl(void)
{
  boolean rtb_RelationalOperator_p;

  /* RelationalOperator: '<S379>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S379>/Logical Operator' incorporates:
   *  RelationalOperator: '<S379>/Relational Operator1'
   *  RelationalOperator: '<S379>/Relational Operator2'
   */
  WiperCtl_WiperHiSpdSta = (rtb_RelationalOperator_p && WiperCtl_WiperHiSpdSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay4_p));
}

/* System initialize for atomic system: '<S288>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S380>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_c = true;

  /* InitializeConditions for Delay: '<S380>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_ce = true;
}

/* Output and update for atomic system: '<S288>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl(void)
{
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator5_lx;

  /* RelationalOperator: '<S380>/Relational Operator5' incorporates:
   *  Constant: '<S380>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S380>/Relational Operator'
   */
  rtb_RelationalOperator5_lx = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S380>/Logical Operator' incorporates:
   *  RelationalOperator: '<S380>/Relational Operator2'
   */
  WiperCtl_WiperInrSta = (rtb_RelationalOperator5_lx && WiperCtl_WiperInrSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay5_j5));

  /* Delay: '<S380>/Delay1' */
  if (AppSwcBcm_ARID_DEF.icLoad_c) {
    /* Switch: '<S380>/Switch1' incorporates:
     *  Constant: '<S380>/Constant20'
     *  Constant: '<S380>/Constant8'
     *  RelationalOperator: '<S380>/Relational Operator4'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.InrTim == 255) {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrLvl3Tim_C;
    } else {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = AppSwcBcm_ARID_DEF.BusCreator12.InrTim;
    }

    /* End of Switch: '<S380>/Switch1' */
  }

  /* RelationalOperator: '<S380>/Relational Operator5' incorporates:
   *  Constant: '<S380>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S380>/Relational Operator3'
   */
  rtb_RelationalOperator5_lx = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Switch: '<S380>/Switch' */
  if (rtb_RelationalOperator5_lx) {
    /* Switch: '<S380>/Switch' */
    rtb_Switch = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUWiprIntlTmSet_enum;
  } else {
    /* Switch: '<S380>/Switch' incorporates:
     *  Constant: '<S380>/Constant19'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S380>/Switch' */

  /* MultiPortSwitch: '<S380>/Multiport Switch' incorporates:
   *  Constant: '<S380>/Constant1'
   *  Constant: '<S380>/Constant2'
   *  Constant: '<S380>/Constant3'
   *  Constant: '<S380>/Constant4'
   *  Constant: '<S380>/Constant5'
   *  Constant: '<S380>/Constant6'
   *  Constant: '<S380>/Constant7'
   *  Delay: '<S380>/Delay1'
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

  /* End of MultiPortSwitch: '<S380>/Multiport Switch' */

  /* RelationalOperator: '<S380>/Relational Operator1' incorporates:
   *  UnitDelay: '<S380>/Unit Delay'
   */
  WiperCtl_InrTimChg = (WiperCtl_InrTim != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a);

  /* Delay: '<S380>/Delay2' */
  if (AppSwcBcm_ARID_DEF.icLoad_ce) {
    /* Switch: '<S380>/Switch2' incorporates:
     *  Constant: '<S380>/Constant15'
     *  Constant: '<S380>/Constant21'
     *  RelationalOperator: '<S380>/Relational Operator5'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE =
        AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb;
    }

    /* End of Switch: '<S380>/Switch2' */
  }

  /* MultiPortSwitch: '<S380>/Multiport Switch1' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant9'
     */
    WiperCtl_WiprIntlTimeSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant16'
     */
    WiperCtl_WiprIntlTimeSetFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant10'
     */
    WiperCtl_WiprIntlTimeSetFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant11'
     */
    WiperCtl_WiprIntlTimeSetFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant12'
     */
    WiperCtl_WiprIntlTimeSetFb = 4U;
    break;

   case 6:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant13'
     */
    WiperCtl_WiprIntlTimeSetFb = 5U;
    break;

   case 7:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Constant: '<S380>/Constant14'
     */
    WiperCtl_WiprIntlTimeSetFb = 6U;
    break;

   default:
    /* MultiPortSwitch: '<S380>/Multiport Switch1' incorporates:
     *  Delay: '<S380>/Delay2'
     */
    WiperCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.Delay2_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S380>/Multiport Switch1' */

  /* Update for Delay: '<S380>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_c = false;
  AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrTim;

  /* Update for UnitDelay: '<S380>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a = WiperCtl_InrTim;

  /* Update for Delay: '<S380>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_ce = false;
  AppSwcBcm_ARID_DEF.Delay2_DSTATE = WiperCtl_WiprIntlTimeSetFb;
}

/* Output and update for atomic system: '<S288>/WiperLowSpdCtl' */
static void AppSwcBcm_WiperLowSpdCtl(void)
{
  boolean rtb_RelationalOperator_ob;

  /* RelationalOperator: '<S381>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_ob = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S381>/Logical Operator' incorporates:
   *  RelationalOperator: '<S381>/Relational Operator1'
   *  RelationalOperator: '<S381>/Relational Operator2'
   */
  WiperCtl_WiperLowSpdSta = (rtb_RelationalOperator_ob && WiperCtl_WiperLowSpdSw
    && (!AppSwcBcm_ARID_DEF.UnitDelay7_l));
}

/* Output and update for atomic system: '<S288>/WiperMaintCtl' */
static void AppSwcBcm_WiperMaintCtl(void)
{
  boolean rtb_RelationalOperator6;

  /* Chart: '<S382>/MaintOff' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S382>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_db) {
    AppSwcBcm_ARID_DEF.Lib_blIn_lo =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

    /* Outputs for Function Call SubSystem: '<S424>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_lo,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lr,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_me);

    /* End of Outputs for SubSystem: '<S424>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.Flg_gq = (AppSwcBcm_ARID_DEF.LogicalOperator_lr ||
      AppSwcBcm_ARID_DEF.Flg_gq);
    if (AppSwcBcm_ARID_DEF.Flg_gq) {
      AppSwcBcm_ARID_DEF.Lib_blIn_cp =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S424>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cp,
        &AppSwcBcm_ARID_DEF.LogicalOperator_hr,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_h);

      /* End of Outputs for SubSystem: '<S424>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff =
        (AppSwcBcm_ARID_DEF.LogicalOperator_hr ||
         AppSwcBcm_ARID_DEF.WiperCtl_MaintOff);
    }
  } else {
    AppSwcBcm_ARID_DEF.Flg_gq = false;
    AppSwcBcm_ARID_DEF.WiperCtl_MaintOff = false;
  }

  /* End of Chart: '<S382>/MaintOff' */

  /* Outputs for Atomic SubSystem: '<S382>/Lib_SR' */
  /* Switch: '<S423>/Switch' incorporates:
   *  Constant: '<S382>/Constant2'
   *  Constant: '<S382>/Constant5'
   *  Constant: '<S423>/Constant'
   *  Logic: '<S382>/Logical Operator'
   *  Logic: '<S382>/Logical Operator1'
   *  Logic: '<S423>/Logical Operator'
   *  RelationalOperator: '<S382>/Relational Operator1'
   *  RelationalOperator: '<S382>/Relational Operator2'
   *  RelationalOperator: '<S382>/Relational Operator3'
   *  RelationalOperator: '<S382>/Relational Operator4'
   *  RelationalOperator: '<S382>/Relational Operator5'
   *  UnitDelay: '<S423>/Unit Delay'
   */
  if ((!WiperCtl_WiperOffSw) ||
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 1) ||
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff) {
    WiperCtl_WiperMaintSta = false;
  } else {
    /* RelationalOperator: '<S382>/Relational Operator6' incorporates:
     *  Constant: '<S382>/Constant3'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
      )->SysPwrMode == 2);
    WiperCtl_WiperMaintSta = (((!AppSwcBcm_ARID_DEF.UnitDelay6_e) &&
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 2) &&
      WiperCtl_WiperParkPosSw && rtb_RelationalOperator6) ||
      WiperCtl_WiperMaintSta);
  }

  /* End of Switch: '<S423>/Switch' */
  /* End of Outputs for SubSystem: '<S382>/Lib_SR' */

  /* Update for UnitDelay: '<S382>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_db = WiperCtl_WiperMaintSta;
}

/* Output and update for atomic system: '<S288>/WiperMistCtl' */
static void AppSwcBcm_WiperMistCtl(void)
{
  boolean rtb_RelationalOperator_cz;

  /* RelationalOperator: '<S383>/Relational Operator' incorporates:
   *  Constant: '<S383>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_cz = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S383>/Logical Operator' incorporates:
   *  RelationalOperator: '<S383>/Relational Operator1'
   *  RelationalOperator: '<S383>/Relational Operator2'
   */
  WiperCtl_WiperMistSta = (rtb_RelationalOperator_cz && WiperCtl_WiperMistSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay3_p));
}

/* Output and update for atomic system: '<S288>/WiperOffCtl' */
static void AppSwcBcm_WiperOffCtl(void)
{
  boolean rtb_RelationalOperator_l1k;

  /* RelationalOperator: '<S384>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator_l1k = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Logic: '<S384>/Logical Operator' incorporates:
   *  RelationalOperator: '<S384>/Relational Operator1'
   */
  WiperCtl_WiperOffSta = (rtb_RelationalOperator_l1k || WiperCtl_WiperOffSw);
}

/* System initialize for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S288>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt_Init();

  /* End of SystemInitialize for SubSystem: '<S288>/LockedRotorProt' */

  /* SystemInitialize for Atomic SubSystem: '<S288>/WashCtl' */
  AppSwcBcm_WashCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S288>/WashCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S288>/WiperDrv' */
  AppSwcBcm_WiperDrv_Init();

  /* End of SystemInitialize for SubSystem: '<S288>/WiperDrv' */

  /* SystemInitialize for Atomic SubSystem: '<S288>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S288>/WiperInrCtl' */
}

/* Output and update for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl(void)
{
  boolean rtb_DataTypeConversion_m2;

  /* SignalConversion: '<S288>/Signal Conversion' */
  SCS_FrntWiprSwtSt =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWiprSwtSt_enum;

  /* SignalConversion: '<S288>/Signal Conversion1' */
  SCS_FrntWshrSwtSt =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWshrSwtSt_flg;

  /* SignalConversion: '<S288>/Signal Conversion2' */
  SCS_FrntWshrSwtStVD =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWshrSwtStVld_flg;

  /* SignalConversion: '<S288>/Signal Conversion3' */
  SCS_WiprSwtStVD =
    AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_g.VIPM_SCSFrntWiprSwtStVld_flg;

  /* Outputs for Atomic SubSystem: '<S288>/SignalProcess' */
  AppSwcBcm_SignalProcess();

  /* End of Outputs for SubSystem: '<S288>/SignalProcess' */

  /* UnitDelay: '<S288>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_j5 = WiperCtl_LockedRotorProtSta;

  /* Outputs for Atomic SubSystem: '<S288>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl();

  /* End of Outputs for SubSystem: '<S288>/WiperInrCtl' */

  /* Outputs for Atomic SubSystem: '<S288>/WiperOffCtl' */
  AppSwcBcm_WiperOffCtl();

  /* End of Outputs for SubSystem: '<S288>/WiperOffCtl' */

  /* UnitDelay: '<S288>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_c = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_h;

  /* Outputs for Atomic SubSystem: '<S288>/WashCtl' */
  AppSwcBcm_WashCtl();

  /* End of Outputs for SubSystem: '<S288>/WashCtl' */

  /* UnitDelay: '<S288>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_p = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_h;

  /* Outputs for Atomic SubSystem: '<S288>/WiperHiSpdCtl' */
  AppSwcBcm_WiperHiSpdCtl();

  /* End of Outputs for SubSystem: '<S288>/WiperHiSpdCtl' */

  /* UnitDelay: '<S288>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_l = AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_f;

  /* Outputs for Atomic SubSystem: '<S288>/WiperLowSpdCtl' */
  AppSwcBcm_WiperLowSpdCtl();

  /* End of Outputs for SubSystem: '<S288>/WiperLowSpdCtl' */

  /* UnitDelay: '<S288>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_p = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_g;

  /* Outputs for Atomic SubSystem: '<S288>/WiperMistCtl' */
  AppSwcBcm_WiperMistCtl();

  /* End of Outputs for SubSystem: '<S288>/WiperMistCtl' */

  /* UnitDelay: '<S288>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_e = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_k;

  /* Outputs for Atomic SubSystem: '<S288>/WiperMaintCtl' */
  AppSwcBcm_WiperMaintCtl();

  /* End of Outputs for SubSystem: '<S288>/WiperMaintCtl' */

  /* Outputs for Atomic SubSystem: '<S288>/WiperDrv' */
  AppSwcBcm_WiperDrv();

  /* End of Outputs for SubSystem: '<S288>/WiperDrv' */

  /* Outputs for Atomic SubSystem: '<S288>/Ovrd1' */
  /* Switch: '<S373>/Switch1' incorporates:
   *  Constant: '<S288>/Constant1'
   */
  if (WiperCtl_LowSpdDrvOvrdFlg_C) {
    /* Switch: '<S373>/Switch1' incorporates:
     *  Constant: '<S288>/Constant2'
     */
    WiperCtl_LowSpdDrv = WiperCtl_LowSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S288>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_m2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperLowSpdCtlFlg != 0);

    /* Switch: '<S373>/Switch1' incorporates:
     *  Switch: '<S373>/Switch2'
     */
    WiperCtl_LowSpdDrv = (rtb_DataTypeConversion_m2 ||
                          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_e);
  }

  /* End of Switch: '<S373>/Switch1' */
  /* End of Outputs for SubSystem: '<S288>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S288>/Ovrd2' */
  /* Switch: '<S374>/Switch1' incorporates:
   *  Constant: '<S288>/Constant3'
   */
  if (WiperCtl_HiSpdDrvOvrdFlg_C) {
    /* Switch: '<S374>/Switch1' incorporates:
     *  Constant: '<S288>/Constant4'
     */
    WiperCtl_HiSpdDrv = WiperCtl_HiSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S288>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_m2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperHiSpdCtlFlg != 0);

    /* Switch: '<S374>/Switch1' incorporates:
     *  Switch: '<S374>/Switch2'
     */
    WiperCtl_HiSpdDrv = (rtb_DataTypeConversion_m2 ||
                         AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_g);
  }

  /* End of Switch: '<S374>/Switch1' */
  /* End of Outputs for SubSystem: '<S288>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S288>/Ovrd3' */
  /* Switch: '<S375>/Switch1' incorporates:
   *  Constant: '<S288>/Constant18'
   */
  if (WiperCtl_WashMotorDrvOvrdFlg_C) {
    /* Switch: '<S375>/Switch1' incorporates:
     *  Constant: '<S288>/Constant19'
     */
    WiperCtl_WashMotorDrv = WiperCtl_WashMotorDrvOvrdVal_C;
  } else {
    /* Switch: '<S375>/Switch1' incorporates:
     *  Switch: '<S375>/Switch2'
     */
    WiperCtl_WashMotorDrv = AppSwcBcm_ARID_DEF.LIB_blOut_a2;
  }

  /* End of Switch: '<S375>/Switch1' */
  /* End of Outputs for SubSystem: '<S288>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S288>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt();

  /* End of Outputs for SubSystem: '<S288>/LockedRotorProt' */

  /* Update for UnitDelay: '<S288>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_h = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S288>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_h = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S288>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_f = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S288>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_g = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S288>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S288>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_k = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S288>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nh = WiperCtl_LowSpdDrv;

  /* Update for UnitDelay: '<S288>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_fz = WiperCtl_HiSpdDrv;
}

/*
 * Output and update for atomic system:
 *    '<S439>/Lib_FailEdgeDet'
 *    '<S442>/Lib_FailEdgeDet'
 *    '<S440>/Lib_FailEdgeDet'
 *    '<S443>/Lib_FailEdgeDet'
 *    '<S441>/Lib_FailEdgeDet'
 *    '<S645>/Lib_FailEdgeDet'
 *    '<S645>/Lib_FailEdgeDet1'
 */
static void AppSwcBcm_Lib_FailEdgeDet_e(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_m_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S447>/Logical Operator' incorporates:
   *  Logic: '<S447>/Logical Operator1'
   *  UnitDelay: '<S447>/Unit Delay'
   */
  *rty_Lib_blOut = ((!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S447>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S438>/Lib_FailEdgeDet'
 *    '<S438>/Lib_FailEdgeDet3'
 *    '<S438>/Lib_FailEdgeDet4'
 *    '<S438>/Lib_FailEdgeDet2'
 */
static void AppSwcBcm_Lib_FailEdgeDet_p(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_d_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S439>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_e(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S439>/Lib_FailEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S446>/Lib_RiseEdgeDetInit'
 *    '<S906>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_g_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S454>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S446>/Lib_RiseEdgeDetInit'
 *    '<S906>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_a(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_g_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S454>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S454>/Logical Operator' incorporates:
   *  Delay: '<S454>/Delay'
   *  Logic: '<S454>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S454>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Output and update for function-call system: '<S438>/Lib_FailEdgeDet1' */
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S440>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_e(rtu_Lib_blIn, rty_Lib_lbOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S440>/Lib_FailEdgeDet' */
}

/* Function for Chart: '<S429>/AlmSysLogic' */
static void AppSwcBcm_AlmWarn(void)
{
  if (AppSwcBcm_ARID_DEF.AlmDelayCnt >= 9) {
    AlmSysCtl_BodyWarnSts = 2U;
    AppSwcBcm_ARID_DEF.Lib_blIn_g5 = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

    /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet' */
    AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
      &AppSwcBcm_ARID_DEF.LogicalOperator_az,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

    /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_az) {
      /* Flg=1; */
      AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_br =
        AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

      /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet1' */
      AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_br,
        &AppSwcBcm_ARID_DEF.LogicalOperator_hs,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

      /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_hs) {
        /* Flg=1; */
        AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_do =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

        /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet2' */
        AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_do,
          &AppSwcBcm_ARID_DEF.LogicalOperator_gw,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

        /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_gw) {
          /* Flg=1; */
          AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_cf =
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

          /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet3' */
          AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cf,
            &AppSwcBcm_ARID_DEF.LogicalOperator_oh,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

          /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet3' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_oh) {
            /* Flg=1; */
            AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_bc =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

            /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet4' */
            AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_bc,
              &AppSwcBcm_ARID_DEF.LogicalOperator_od,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

            /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet4' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_od) {
              /* Flg=1; */
              AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
            }
          }
        }
      }
    }

    if (AppSwcBcm_ARID_DEF.Cnt_jt >= AlmSysCtl_AlrmTimLimit_C) {
      AlmSysCtl_AlrmWarnTimOut = true;

      /* Flg=0; */
    } else {
      AppSwcBcm_ARID_DEF.Cnt_jt++;
      AlmSysCtl_AlrmWarnTimOut = false;
    }
  } else {
    AppSwcBcm_ARID_DEF.AlmDelayCnt++;
  }
}

/* System initialize for atomic system: '<S429>/AlmSysLogic' */
static void AppSwcBcm_AlmSysLogic_Init(void)
{
  /* SystemInitialize for Function Call SubSystem: '<S438>/Lib_RiseEdgeDetInit' */
  /* SystemInitialize for Atomic SubSystem: '<S446>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h);

  /* End of SystemInitialize for SubSystem: '<S446>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S438>/Lib_RiseEdgeDetInit' */
}

/* Output and update for atomic system: '<S429>/AlmSysLogic' */
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

  /* Chart: '<S429>/AlmSysLogic' incorporates:
   *  UnitDelay: '<S4>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_AlmSysCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_AlmSysCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Init_jx;
    AlmSysCtl_BodyWarnSts = AppSwcBcm_ARID_DEF.DataTypeConversion6;
    AppSwcBcm_ARID_DEF.Lib_blIn_g5 = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

    /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet' */
    AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
      &AppSwcBcm_ARID_DEF.LogicalOperator_az,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

    /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet' */
    AppSwcBcm_ARID_DEF.Lib_blIn_br = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet1' */
    AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_br,
      &AppSwcBcm_ARID_DEF.LogicalOperator_hs,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

    /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet1' */
    AppSwcBcm_ARID_DEF.Lib_blIn_do = AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

    /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet2' */
    AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_do,
      &AppSwcBcm_ARID_DEF.LogicalOperator_gw,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

    /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet2' */
    AppSwcBcm_ARID_DEF.Lib_blIn_cf = AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

    /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet3' */
    AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cf,
      &AppSwcBcm_ARID_DEF.LogicalOperator_oh,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

    /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet3' */
    AppSwcBcm_ARID_DEF.Lib_blIn_bc = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

    /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet4' */
    AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_bc,
      &AppSwcBcm_ARID_DEF.LogicalOperator_od,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

    /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet4' */
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    guard8 = false;
    switch (AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib) {
     case AppSwcBcm_IN_Alarm:
      if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
        guard4 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_dc = (AppSwcBcm_ARID_DEF.UnitDelay4 == 1);

        /* Outputs for Function Call SubSystem: '<S438>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_dc,
          &AppSwcBcm_ARID_DEF.LogicalOperator_i4,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);

        /* End of Outputs for SubSystem: '<S438>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_i4) {
          guard4 = true;
        } else if (((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) ||
                   AlmSysCtl_AlrmWarnTimOut) {
          AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
          AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
          AlmSysCtl_BodyWarnSts = 1U;

          /* du:UpdateSta(); */
        } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                   ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                    (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
          AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
          AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
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
        AppSwcBcm_ARID_DEF.Lib_blIn_dc = (AppSwcBcm_ARID_DEF.UnitDelay4 == 1);

        /* Outputs for Function Call SubSystem: '<S438>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_dc,
          &AppSwcBcm_ARID_DEF.LogicalOperator_i4,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);

        /* End of Outputs for SubSystem: '<S438>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_i4) {
          guard5 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta == 1) {
          AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

          /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet' */
          AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
            &AppSwcBcm_ARID_DEF.LogicalOperator_az,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

          /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_az) {
            guard8 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_br =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

            /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet1' */
            AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_br,
              &AppSwcBcm_ARID_DEF.LogicalOperator_hs,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

            /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet1' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_hs) {
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
        AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
      } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                 ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                  (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
        AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
      }
      break;

     case AppSwcBcm_IN_Init_jx:
      switch (AppSwcBcm_ARID_DEF.DataTypeConversion6) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
        break;

       case 2:
        AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
        AlmSysCtl_AlrmWarnTimOut = false;
        AppSwcBcm_ARID_DEF.AlmDelayCnt = 0U;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
        break;

       default:
        AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
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
        AppSwcBcm_ARID_DEF.Lib_blIn_io =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;
        AppSwcBcm_ARID_DEF.Lib_blInit_o = true;

        /* Outputs for Function Call SubSystem: '<S438>/Lib_RiseEdgeDetInit' */
        /* Outputs for Atomic SubSystem: '<S446>/Lib_RiseEdgeDetInit' */
        AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_io, true,
          &AppSwcBcm_ARID_DEF.LogicalOperator_nj,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h);

        /* End of Outputs for SubSystem: '<S446>/Lib_RiseEdgeDetInit' */
        /* End of Outputs for SubSystem: '<S438>/Lib_RiseEdgeDetInit' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_nj &&
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) {
          guard1 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
          guard2 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_dc = (AppSwcBcm_ARID_DEF.UnitDelay4 == 1);

          /* Outputs for Function Call SubSystem: '<S438>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_dc,
            &AppSwcBcm_ARID_DEF.LogicalOperator_i4,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);

          /* End of Outputs for SubSystem: '<S438>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_i4) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

            /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet' */
            AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
              &AppSwcBcm_ARID_DEF.LogicalOperator_az,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_l);

            /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_az) {
              guard3 = true;
            } else {
              AppSwcBcm_ARID_DEF.Lib_blIn_br =
                AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

              /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet1' */
              AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_br,
                &AppSwcBcm_ARID_DEF.LogicalOperator_hs,
                &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_p);

              /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet1' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_hs) {
                guard3 = true;
              } else {
                AppSwcBcm_ARID_DEF.Lib_blIn_bc =
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

                /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet4' */
                AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_bc,
                  &AppSwcBcm_ARID_DEF.LogicalOperator_od,
                  &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

                /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet4' */
                if (AppSwcBcm_ARID_DEF.LogicalOperator_od) {
                  guard3 = true;
                } else {
                  AppSwcBcm_ARID_DEF.Lib_blIn_hs =
                    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0;

                  /* Outputs for Function Call SubSystem: '<S438>/Lib_RiseEdgeDet1' */
                  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_hs,
                    &AppSwcBcm_ARID_DEF.LogicalOperator_mc,
                    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_e);

                  /* End of Outputs for SubSystem: '<S438>/Lib_RiseEdgeDet1' */
                  if (AppSwcBcm_ARID_DEF.LogicalOperator_mc) {
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
      AppSwcBcm_ARID_DEF.Lib_blIn_hs = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0;

      /* Outputs for Function Call SubSystem: '<S438>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_hs,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mc,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_e);

      /* End of Outputs for SubSystem: '<S438>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_mc) {
        guard6 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_do =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

        /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet2' */
        AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_do,
          &AppSwcBcm_ARID_DEF.LogicalOperator_gw,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

        /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_gw) {
          guard6 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_cf =
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

          /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet3' */
          AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_cf,
            &AppSwcBcm_ARID_DEF.LogicalOperator_oh,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

          /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet3' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_oh) {
            guard6 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_bc =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

            /* Outputs for Function Call SubSystem: '<S438>/Lib_FailEdgeDet4' */
            AppSwcBcm_Lib_FailEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_bc,
              &AppSwcBcm_ARID_DEF.LogicalOperator_od,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

            /* End of Outputs for SubSystem: '<S438>/Lib_FailEdgeDet4' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_od) {
              guard6 = true;
            }
          }
        }
      }
    }

    if (guard6) {
      AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_AlrmWarnTimOut = false;
      AppSwcBcm_ARID_DEF.AlmDelayCnt = 0U;
    }

    if (guard5) {
      AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard4) {
      AppSwcBcm_ARID_DEF.Cnt_jt = 0U;
      AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard3) {
      AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_AlrmWarnTimOut = false;
      AppSwcBcm_ARID_DEF.AlmDelayCnt = 0U;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c3_AlmSysCtl_Lib = AppSwcBcm_IN_Armed;
      AlmSysCtl_BodyWarnSts = 1U;

      /* du:UpdateSta(); */
    }
  }

  /* End of Chart: '<S429>/AlmSysLogic' */
}

/* System initialize for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S429>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic_Init();
}

/* Output and update for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl(void)
{
  /* DataTypeConversion: '<S429>/Data Type Conversion6' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion6 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts;

  /* DataTypeConversion: '<S429>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.DataTypeConversion10 =
    (AppSwcBcm_ARID_DEF.BusCreator14.SKSta != 0);

  /* Chart: '<S429>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic();
}

/*
 * System initialize for atomic system:
 *    '<S458>/Lib_BothEdgeDetInit'
 *    '<S458>/Lib_BothEdgeDetInit1'
 *    '<S458>/Lib_BothEdgeDetInit2'
 *    '<S458>/Lib_BothEdgeDetInit3'
 */
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S461>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S458>/Lib_BothEdgeDetInit'
 *    '<S458>/Lib_BothEdgeDetInit1'
 *    '<S458>/Lib_BothEdgeDetInit2'
 *    '<S458>/Lib_BothEdgeDetInit3'
 */
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Delay: '<S461>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S461>/Logical Operator2' incorporates:
   *  Delay: '<S461>/Delay'
   *  Logic: '<S461>/Logical Operator1'
   *  Logic: '<S461>/Logical Operator3'
   *  Logic: '<S461>/Logical Operator4'
   *  Logic: '<S461>/Logical Operator5'
   */
  rty_Lib_blOut_0 = ((AppSwcBcm__ARID_DEF_arg->Delay_DSTATE && (!rtu_Lib_blIn)) ||
                     (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE)));

  /* Update for Delay: '<S461>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S458>/Lib_BothEdgeDetInit' */

  /* SystemInitialize for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit1' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of SystemInitialize for SubSystem: '<S458>/Lib_BothEdgeDetInit1' */

  /* SystemInitialize for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit2' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of SystemInitialize for SubSystem: '<S458>/Lib_BothEdgeDetInit2' */

  /* SystemInitialize for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit3' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of SystemInitialize for SubSystem: '<S458>/Lib_BothEdgeDetInit3' */
}

/* Output and update for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion_m;
  boolean rtb_RelationalOperator2_hd;
  boolean rtb_RelationalOperator3_iy;
  boolean rtb_RelationalOperator4_lc;
  boolean rtb_RelationalOperator_bp;
  boolean rtb_Switch;

  /* RelationalOperator: '<S458>/Relational Operator' incorporates:
   *  Constant: '<S458>/Constant'
   */
  BatSaveCtl_PwrModeOn = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

  /* RelationalOperator: '<S458>/Relational Operator1' incorporates:
   *  Constant: '<S458>/Constant1'
   */
  BatSaveCtl_DoorUnlckPwrOn = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* Outputs for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit' */
  rtb_RelationalOperator_bp = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of Outputs for SubSystem: '<S458>/Lib_BothEdgeDetInit' */

  /* Outputs for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit1' */
  rtb_RelationalOperator2_hd = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of Outputs for SubSystem: '<S458>/Lib_BothEdgeDetInit1' */

  /* Outputs for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit2' */
  rtb_RelationalOperator3_iy = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of Outputs for SubSystem: '<S458>/Lib_BothEdgeDetInit2' */

  /* Outputs for Atomic SubSystem: '<S458>/Lib_BothEdgeDetInit3' */
  rtb_RelationalOperator4_lc = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of Outputs for SubSystem: '<S458>/Lib_BothEdgeDetInit3' */

  /* Logic: '<S458>/Logical Operator1' */
  BatSaveCtl_DoorChgSta = (rtb_RelationalOperator_bp ||
    rtb_RelationalOperator2_hd || rtb_RelationalOperator3_iy ||
    rtb_RelationalOperator4_lc);

  /* Logic: '<S458>/Logical Operator' */
  BatSaveCtl_PwrOn = (BatSaveCtl_PwrModeOn || BatSaveCtl_DoorUnlckPwrOn ||
                      BatSaveCtl_DoorChgSta);

  /* Chart: '<S457>/LIB_PosPluse' incorporates:
   *  Constant: '<S457>/Constant2'
   *  Constant: '<S457>/Constant4'
   *  Logic: '<S457>/Logical Operator2'
   *  Logic: '<S457>/Logical Operator3'
   *  Logic: '<S457>/Logical Operator5'
   *  Logic: '<S457>/Logical Operator8'
   *  RelationalOperator: '<S457>/Relational Operator'
   *  RelationalOperator: '<S457>/Relational Operator2'
   *  RelationalOperator: '<S457>/Relational Operator3'
   *  RelationalOperator: '<S457>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
      ((!BatSaveCtl_DoorChgSta) && ((AppSwcBcm_ARID_DEF.BusCreator4.InsLckSta !=
         1) && (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta != 1) &&
        (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta != 1)))) {
    if (AppSwcBcm_ARID_DEF.Cnt_mo <= BatSaveCtl_DlyTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_mo + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_mo + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_mo = (uint16)tmp;
      BatSaveCtl_PwrModeOff = false;
    } else {
      BatSaveCtl_PwrModeOff = true;
    }
  } else {
    BatSaveCtl_PwrModeOff = false;
    AppSwcBcm_ARID_DEF.Cnt_mo = 0U;
  }

  /* End of Chart: '<S457>/LIB_PosPluse' */

  /* Chart: '<S457>/LIB_PosPluse1' incorporates:
   *  Constant: '<S457>/Constant6'
   *  Constant: '<S457>/Constant7'
   *  RelationalOperator: '<S457>/Relational Operator6'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) {
    if (AppSwcBcm_ARID_DEF.Cnt_od <= BatSaveCtl_LckDlyTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_od + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_od + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_od = (uint16)tmp;
      BatSaveCtl_DoorLckPwrOff = false;
    } else {
      BatSaveCtl_DoorLckPwrOff = true;
    }
  } else {
    BatSaveCtl_DoorLckPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_od = 0U;
  }

  /* End of Chart: '<S457>/LIB_PosPluse1' */

  /* Logic: '<S457>/Logical Operator' */
  BatSaveCtl_PwrOff = (BatSaveCtl_PwrModeOff || BatSaveCtl_DoorLckPwrOff);

  /* Outputs for Atomic SubSystem: '<S430>/Lib_SR' */
  AppSwcBcm_Lib_SR(BatSaveCtl_PwrOn, BatSaveCtl_PwrOff, &rtb_Switch,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_f);

  /* End of Outputs for SubSystem: '<S430>/Lib_SR' */

  /* Outputs for Atomic SubSystem: '<S430>/Ovrd1' */
  /* Switch: '<S456>/Switch1' incorporates:
   *  Constant: '<S430>/Constant18'
   */
  if (BatSaveCtl_J64SavePwrOvrdFlg_C) {
    /* Switch: '<S456>/Switch1' incorporates:
     *  Constant: '<S430>/Constant19'
     */
    BatSaveCtl_J64SavePwr = BatSaveCtl_J64SavePwrOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S430>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_m = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BatSaveCtlFlg != 0);

    /* Switch: '<S456>/Switch1' incorporates:
     *  Switch: '<S456>/Switch2'
     */
    BatSaveCtl_J64SavePwr = (rtb_DataTypeConversion_m || rtb_Switch);
  }

  /* End of Switch: '<S456>/Switch1' */
  /* End of Outputs for SubSystem: '<S430>/Ovrd1' */
}

/* Function for Chart: '<S431>/DoorDrv' */
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

/* Function for Chart: '<S431>/DoorDrv' */
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
    DoorLckCtl_TrunkLckSta = 2U;
    DoorLckCtl_TrunkLckSw = true;
  }

  if ((AppSwcBcm_ARID_DEF.InsLck_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) ||
      ((DoorLckCtl_InsLckSta == 2) && (DoorLckCtl_TrunkLckSta == 2))) {
    AppSwcBcm_ARID_DEF.LckFin = true;
    AppSwcBcm_ARID_DEF.InsLck_Cnt = 0U;
  }
}

/* Function for Chart: '<S431>/DoorDrv' */
static void AppSwcBcm_InsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_jc = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S465>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_jc,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ik,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

  /* End of Outputs for SubSystem: '<S465>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_ik ||
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

/* Function for Chart: '<S431>/DoorDrv' */
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
    DoorLckCtl_TrunkLckSta = 2U;
    DoorLckCtl_TrunkLckSw = true;
  }

  if ((AppSwcBcm_ARID_DEF.OsLck_Cnt >= DoorLckCtl_LckStaCfmMaxTim_C) ||
      ((DoorLckCtl_OsLckSta == 2) && (DoorLckCtl_TrunkLckSta == 2))) {
    AppSwcBcm_ARID_DEF.LckFin = true;
    AppSwcBcm_ARID_DEF.OsLck_Cnt = 0U;
  }
}

/* Function for Chart: '<S431>/DoorDrv' */
static void AppSwcBcm_OsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_jc = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S465>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_jc,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ik,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

  /* End of Outputs for SubSystem: '<S465>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_ik ||
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

/* Output and update for atomic system: '<S431>/DoorDrv' */
static void AppSwcBcm_DoorDrv(void)
{
  boolean tmp;
  boolean tmp_0;

  /* Chart: '<S431>/DoorDrv' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S4>/Unit Delay6'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c19_DoorLckCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c19_DoorLckCtl_Lib = 1U;
    if (!AppSwcBcm_ARID_DEF.Flg_hv) {
      DoorLckCtl_TrunkLckSw = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
        ->TrunkLckSw != 0);
      AppSwcBcm_ARID_DEF.Flg_hv = true;
    }

    AppSwcBcm_ARID_DEF.is_c19_DoorLckCtl_Lib = AppSwcBcm_IN_DrvIdle;

    /* InitFunc(); */
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

        /* InitFunc(); */
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

        /* InitFunc(); */
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

        /* InitFunc(); */
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

        /* InitFunc(); */
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

        /* InitFunc(); */
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

  /* End of Chart: '<S431>/DoorDrv' */
}

/* Output and update for atomic system: '<S466>/AntiLckProt' */
static void AppSwcBcm_AntiLckProt(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator2_l;

  /* Logic: '<S473>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S473>/Relational Operator2'
   *  RelationalOperator: '<S473>/Relational Operator3'
   *  RelationalOperator: '<S473>/Relational Operator4'
   */
  rtb_LogicalOperator2_l = ((!DoorLckCtl_DoorAjarFLSw) ||
    (!DoorLckCtl_DoorAjarFRSw) || (!DoorLckCtl_DoorAjarRRSw));

  /* Logic: '<S473>/Logical Operator5' */
  DoorLckCtl_TboxAntiLck = (DoorLckCtl_TboxLck && rtb_LogicalOperator2_l);

  /* Logic: '<S473>/Logical Operator1' */
  DoorLckCtl_RKEAntiLck = (rtb_LogicalOperator2_l && DoorLckCtl_RKELck);

  /* Logic: '<S473>/Logical Operator3' */
  DoorLckCtl_MechAntiLck = (DoorLckCtl_MechLck && rtb_LogicalOperator2_l);

  /* Logic: '<S473>/Logical Operator4' incorporates:
   *  Logic: '<S473>/Logical Operator'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ci = (DoorLckCtl_TboxAntiLck ||
    DoorLckCtl_RKEAntiLck || (DoorLckCtl_HULck && rtb_LogicalOperator2_l) ||
    DoorLckCtl_MechAntiLck);

  /* Chart: '<S473>/LIB_Tim' incorporates:
   *  SubSystem: '<S485>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ci,
    &AppSwcBcm_ARID_DEF.LogicalOperator_m1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mj);
  AppSwcBcm_ARID_DEF.TempEn = (AppSwcBcm_ARID_DEF.LogicalOperator_m1 ||
    AppSwcBcm_ARID_DEF.TempEn);
  if (AppSwcBcm_ARID_DEF.TempEn) {
    /* Constant: '<S473>/Constant' */
    if (AppSwcBcm_ARID_DEF.Cnt_at <= DoorLckCtl_AntiLckProtTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_at + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_at + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_at = (uint16)tmp;
      DoorLckCtl_DoorProtUnlck = false;
    } else {
      DoorLckCtl_DoorProtUnlck = true;
      AppSwcBcm_ARID_DEF.TempEn = false;
    }

    /* End of Constant: '<S473>/Constant' */
  } else {
    DoorLckCtl_DoorProtUnlck = false;
    AppSwcBcm_ARID_DEF.Cnt_at = 0U;
  }
}

/* System initialize for atomic system: '<S466>/IllmndLckSet' */
static void AppSwcBcm_IllmndLckSet_Init(void)
{
  /* InitializeConditions for Delay: '<S474>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_lt = true;

  /* InitializeConditions for UnitDelay: '<S474>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dv = 1U;
}

/* Output and update for atomic system: '<S466>/IllmndLckSet' */
static void AppSwcBcm_IllmndLckSet(void)
{
  uint8 rtb_Switch1_k;
  boolean rtb_RelationalOperator_m;

  /* RelationalOperator: '<S474>/Relational Operator' incorporates:
   *  Constant: '<S474>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S474>/Relational Operator1'
   */
  rtb_RelationalOperator_m = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->IllmndLckSts == 255);

  /* Switch: '<S474>/Switch1' */
  if (rtb_RelationalOperator_m) {
    /* Switch: '<S474>/Switch1' incorporates:
     *  Constant: '<S474>/Constant8'
     */
    rtb_Switch1_k = 2U;
  } else {
    /* Switch: '<S474>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_k = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
      ->IllmndLckSts;
  }

  /* End of Switch: '<S474>/Switch1' */

  /* Delay: '<S474>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_lt) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_e = rtb_Switch1_k;
  }

  /* Switch: '<S474>/Switch' incorporates:
   *  Constant: '<S474>/Constant5'
   *  RelationalOperator: '<S474>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S474>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_k = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndLckSts_enum;
  } else {
    /* Switch: '<S474>/Switch' incorporates:
     *  Constant: '<S474>/Constant6'
     */
    rtb_Switch1_k = 0U;
  }

  /* End of Switch: '<S474>/Switch' */

  /* MultiPortSwitch: '<S474>/Multiport Switch' */
  switch (rtb_Switch1_k) {
   case 1:
    /* MultiPortSwitch: '<S474>/Multiport Switch' incorporates:
     *  Constant: '<S474>/Constant1'
     */
    DoorLckCtl_IllmndLckSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S474>/Multiport Switch' incorporates:
     *  Constant: '<S474>/Constant2'
     */
    DoorLckCtl_IllmndLckSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S474>/Multiport Switch' incorporates:
     *  Delay: '<S474>/Delay'
     */
    DoorLckCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_e;
    break;
  }

  /* End of MultiPortSwitch: '<S474>/Multiport Switch' */

  /* MultiPortSwitch: '<S474>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndLckSts) {
   case 1:
    /* MultiPortSwitch: '<S474>/Multiport Switch1' incorporates:
     *  Constant: '<S474>/Constant3'
     */
    DoorLckCtl_IllmndLckStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S474>/Multiport Switch1' incorporates:
     *  Constant: '<S474>/Constant4'
     */
    DoorLckCtl_IllmndLckStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S474>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S474>/Unit Delay'
     */
    DoorLckCtl_IllmndLckStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dv;
    break;
  }

  /* End of MultiPortSwitch: '<S474>/Multiport Switch1' */

  /* Update for Delay: '<S474>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_lt = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_e = DoorLckCtl_IllmndLckSts;

  /* Update for UnitDelay: '<S474>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dv = DoorLckCtl_IllmndLckStsFb;
}

/* System initialize for atomic system: '<S466>/IllmndUnlckSet' */
static void AppSwcBcm_IllmndUnlckSet_Init(void)
{
  /* InitializeConditions for Delay: '<S475>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = true;

  /* InitializeConditions for UnitDelay: '<S475>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = 1U;
}

/* Output and update for atomic system: '<S466>/IllmndUnlckSet' */
static void AppSwcBcm_IllmndUnlckSet(void)
{
  uint8 rtb_Switch1_f;
  boolean rtb_RelationalOperator_gl;

  /* RelationalOperator: '<S475>/Relational Operator' incorporates:
   *  Constant: '<S475>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S475>/Relational Operator1'
   */
  rtb_RelationalOperator_gl = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->IllmndUnlckSts == 255);

  /* Switch: '<S475>/Switch1' */
  if (rtb_RelationalOperator_gl) {
    /* Switch: '<S475>/Switch1' incorporates:
     *  Constant: '<S475>/Constant8'
     */
    rtb_Switch1_f = 2U;
  } else {
    /* Switch: '<S475>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_f = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
      ->IllmndUnlckSts;
  }

  /* End of Switch: '<S475>/Switch1' */

  /* Delay: '<S475>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_k) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_j = rtb_Switch1_f;
  }

  /* Switch: '<S475>/Switch' incorporates:
   *  Constant: '<S475>/Constant5'
   *  RelationalOperator: '<S475>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S475>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_f = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndUnlckSts_enum;
  } else {
    /* Switch: '<S475>/Switch' incorporates:
     *  Constant: '<S475>/Constant6'
     */
    rtb_Switch1_f = 0U;
  }

  /* End of Switch: '<S475>/Switch' */

  /* MultiPortSwitch: '<S475>/Multiport Switch' */
  switch (rtb_Switch1_f) {
   case 1:
    /* MultiPortSwitch: '<S475>/Multiport Switch' incorporates:
     *  Constant: '<S475>/Constant1'
     */
    DoorLckCtl_IllmndUnlockSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S475>/Multiport Switch' incorporates:
     *  Constant: '<S475>/Constant2'
     */
    DoorLckCtl_IllmndUnlockSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S475>/Multiport Switch' incorporates:
     *  Delay: '<S475>/Delay'
     */
    DoorLckCtl_IllmndUnlockSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_j;
    break;
  }

  /* End of MultiPortSwitch: '<S475>/Multiport Switch' */

  /* MultiPortSwitch: '<S475>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndUnlockSts) {
   case 1:
    /* MultiPortSwitch: '<S475>/Multiport Switch1' incorporates:
     *  Constant: '<S475>/Constant3'
     */
    DoorLckCtl_IllmndUnlockStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S475>/Multiport Switch1' incorporates:
     *  Constant: '<S475>/Constant4'
     */
    DoorLckCtl_IllmndUnlockStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S475>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S475>/Unit Delay'
     */
    DoorLckCtl_IllmndUnlockStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g;
    break;
  }

  /* End of MultiPortSwitch: '<S475>/Multiport Switch1' */

  /* Update for Delay: '<S475>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_j = DoorLckCtl_IllmndUnlockSts;

  /* Update for UnitDelay: '<S475>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = DoorLckCtl_IllmndUnlockStsFb;
}

/* Output and update for atomic system: '<S476>/HULck' */
static void AppSwcBcm_HULck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator2_pl;

  /* RelationalOperator: '<S488>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_pl =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S488>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator2_pl,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mv);

  /* End of Outputs for SubSystem: '<S488>/Lib_RiseEdgeDet' */

  /* Logic: '<S488>/Logical Operator2' incorporates:
   *  Constant: '<S488>/Constant1'
   *  RelationalOperator: '<S488>/Relational Operator'
   *  RelationalOperator: '<S488>/Relational Operator1'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  DoorLckCtl_HULck = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) &&
                      rtb_LogicalOperator && (!DoorLckCtl_DriverDoorLckSw));
}

/*
 * System initialize for atomic system:
 *    '<S489>/LIB_TPD_10ms'
 *    '<S489>/LIB_TPD_10ms1'
 *    '<S538>/LIB_TPD_10ms1'
 *    '<S643>/LIB_TPD_10ms1'
 *    '<S700>/LIB_TPD_Ts'
 *    '<S700>/LIB_TPD_Ts1'
 *    '<S654>/LIB_TPD_10ms8'
 *    '<S672>/LIB_TPD_10ms8'
 *    '<S674>/LIB_TPD_10ms11'
 *    '<S674>/LIB_TPD_10ms13'
 *    '<S917>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S489>/LIB_TPD_10ms'
 *    '<S489>/LIB_TPD_10ms1'
 *    '<S538>/LIB_TPD_10ms1'
 *    '<S643>/LIB_TPD_10ms1'
 *    '<S700>/LIB_TPD_Ts'
 *    '<S700>/LIB_TPD_Ts1'
 *    '<S654>/LIB_TPD_10ms8'
 *    '<S672>/LIB_TPD_10ms8'
 *    '<S674>/LIB_TPD_10ms11'
 *    '<S674>/LIB_TPD_10ms13'
 *    '<S917>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S489>/LIB_TPD_10ms' */
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

  /* End of Chart: '<S489>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S476>/SpdLck' */
static void AppSwcBcm_SpdLck_Init(void)
{
  /* SystemInitialize for Chart: '<S489>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_pi);

  /* SystemInitialize for Chart: '<S489>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_ct);
}

/* Output and update for atomic system: '<S476>/SpdLck' */
static void AppSwcBcm_SpdLck(void)
{
  boolean rtb_LogicalOperator2_c;
  if ((!DoorLckCtl_DoorAjarFRSw) || (!DoorLckCtl_DoorAjarRRSw) ||
      (!DoorLckCtl_TrunkAjarSw) || (!DoorLckCtl_DoorAjarFLSw)) {
    AppSwcBcm_ARID_DEF.Door_Change = true;
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_ot = DoorLckCtl_DriverDoorLckSw;

  /* Chart: '<S489>/Chart' incorporates:
   *  SubSystem: '<S491>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ot,
    &AppSwcBcm_ARID_DEF.LogicalOperator_k2,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_k2) {
    AppSwcBcm_ARID_DEF.Door_Change = false;
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
  }

  if (DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarRRSw &&
      DoorLckCtl_TrunkAjarSw && DoorLckCtl_DoorAjarFLSw &&
      AppSwcBcm_ARID_DEF.Door_Change && (DoorLckCtl_SpdCtlLckSet == 1) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && (DoorLckCtl_VehSpd >=
       DoorLckCtl_SpdLck_C)) {
    if (AppSwcBcm_ARID_DEF.Cnt_d >= 40) {
      AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = true;
      AppSwcBcm_ARID_DEF.Door_Change = false;
      AppSwcBcm_ARID_DEF.Cnt_d = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_d++;
    }
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = false;
  }

  /* Chart: '<S489>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S489>/Constant'
   *  Constant: '<S489>/Constant2'
   *  Constant: '<S489>/Constant3'
   *  Constant: '<S489>/Constant49'
   *  RelationalOperator: '<S489>/Relational Operator'
   */
  AppSwcBcm_LIB_TPD_10ms(DoorLckCtl_VehSpd >= DoorLckCtl_SpdLck_C,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_pi,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_o);

  /* Chart: '<S489>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S489>/Constant10'
   *  Constant: '<S489>/Constant11'
   *  Constant: '<S489>/Constant9'
   *  Logic: '<S489>/Logical Operator1'
   */
  AppSwcBcm_LIB_TPD_10ms(DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarFLSw &&
    DoorLckCtl_DoorAjarRRSw && DoorLckCtl_TrunkAjarSw,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_ct,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_c);

  /* Logic: '<S489>/Logical Operator2' incorporates:
   *  Constant: '<S489>/Constant8'
   *  Logic: '<S489>/Logical Operator'
   *  Logic: '<S489>/Logical Operator3'
   *  RelationalOperator: '<S489>/Relational Operator2'
   *  RelationalOperator: '<S489>/Relational Operator6'
   */
  rtb_LogicalOperator2_c = ((AppSwcBcm_ARID_DEF.LIB_bErrFlg_ct &&
    (!DoorLckCtl_DriverDoorLckSw) && AppSwcBcm_ARID_DEF.LIB_bErrFlg_pi &&
    (AppSwcBcm_ConstB.RelationalOperator1_e && (AppSwcBcm_ARID_DEF.UnitDelay2 ==
    2))) || AppSwcBcm_ARID_DEF.DoorLckCtl_Lck);

  /* Logic: '<S494>/Logical Operator' incorporates:
   *  Logic: '<S494>/Logical Operator1'
   *  UnitDelay: '<S494>/Unit Delay'
   */
  DoorLckCtl_SpdLck = (rtb_LogicalOperator2_c &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cv));

  /* Update for UnitDelay: '<S494>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cv = rtb_LogicalOperator2_c;
}

/* System initialize for atomic system: '<S466>/InsideLck' */
static void AppSwcBcm_InsideLck_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S476>/SpdLck' */
  AppSwcBcm_SpdLck_Init();

  /* End of SystemInitialize for SubSystem: '<S476>/SpdLck' */
}

/* Output and update for atomic system: '<S466>/InsideLck' */
static void AppSwcBcm_InsideLck(void)
{
  /* Outputs for Atomic SubSystem: '<S476>/HULck' */
  AppSwcBcm_HULck();

  /* End of Outputs for SubSystem: '<S476>/HULck' */

  /* Outputs for Atomic SubSystem: '<S476>/SpdLck' */
  AppSwcBcm_SpdLck();

  /* End of Outputs for SubSystem: '<S476>/SpdLck' */

  /* Logic: '<S476>/Logical Operator' */
  DoorLckCtl_InsLck = (DoorLckCtl_HULck || DoorLckCtl_SpdLck);
}

/* Output and update for atomic system: '<S466>/InsideUnlck' */
static void AppSwcBcm_InsideUnlck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_fg;
  boolean rtb_RelationalOperator1_od;

  /* RelationalOperator: '<S497>/Relational Operator' incorporates:
   *  UnitDelay: '<S4>/Unit Delay6'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_or = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_c;

  /* Chart: '<S497>/Chart' incorporates:
   *  SubSystem: '<S501>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_or,
    &AppSwcBcm_ARID_DEF.LogicalOperator_hf,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gx);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_hf) {
    AppSwcBcm_ARID_DEF.Flg_b = true;
    DoorLckCtl_CrshUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_l = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_b) {
    if (AppSwcBcm_ARID_DEF.Cnt_l >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_l >= 20) {
        DoorLckCtl_CrshUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_b = false;
      } else {
        DoorLckCtl_CrshUnlck = false;
        AppSwcBcm_ARID_DEF.Cnt_l++;
      }
    } else {
      AppSwcBcm_ARID_DEF.Cnt_l = 1U;
    }
  } else {
    DoorLckCtl_CrshUnlck = false;
  }

  /* RelationalOperator: '<S498>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_od =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S498>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator1_od,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ff);

  /* End of Outputs for SubSystem: '<S498>/Lib_RiseEdgeDet' */

  /* Logic: '<S498>/Logical Operator' incorporates:
   *  Constant: '<S498>/Constant2'
   *  RelationalOperator: '<S498>/Relational Operator'
   *  RelationalOperator: '<S498>/Relational Operator2'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  DoorLckCtl_HUUnLck = (rtb_LogicalOperator && DoorLckCtl_DriverDoorLckSw &&
                        (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0));

  /* RelationalOperator: '<S499>/Relational Operator3' incorporates:
   *  Constant: '<S499>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_od =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S499>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_fg = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator1_od,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_iz);

  /* End of Outputs for SubSystem: '<S499>/Lib_RiseEdgeDet' */

  /* Logic: '<S499>/Logical Operator' incorporates:
   *  Constant: '<S499>/Constant'
   *  Constant: '<S499>/Constant1'
   *  RelationalOperator: '<S499>/Relational Operator'
   *  RelationalOperator: '<S499>/Relational Operator1'
   *  RelationalOperator: '<S499>/Relational Operator2'
   */
  DoorLckCtl_ParkUnlck = ((DoorLckCtl_ParkAutoUnlockSetFb == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && DoorLckCtl_DriverDoorLckSw &&
    DoorLckCtl_VehStop && rtb_LogicalOperator_fg);

  /* Logic: '<S500>/Logical Operator2' incorporates:
   *  Constant: '<S500>/Constant1'
   *  Constant: '<S500>/Constant2'
   *  Logic: '<S500>/Logical Operator'
   *  Logic: '<S500>/Logical Operator1'
   *  RelationalOperator: '<S500>/Relational Operator'
   *  RelationalOperator: '<S500>/Relational Operator1'
   *  RelationalOperator: '<S500>/Relational Operator2'
   *  UnitDelay: '<S4>/Unit Delay7'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ht = (AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_g &&
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) || ((AppSwcBcm_ARID_DEF.UnitDelay2 ==
    2) && DoorLckCtl_VehStop)));

  /* Chart: '<S500>/Chart' incorporates:
   *  SubSystem: '<S506>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ht,
    &AppSwcBcm_ARID_DEF.LogicalOperator_io,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_f);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_io) {
    AppSwcBcm_ARID_DEF.Flg_i = true;
    DoorLckCtl_ThermRunawayUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_op = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_i) {
    if (AppSwcBcm_ARID_DEF.Cnt_op >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_op >= 20) {
        DoorLckCtl_ThermRunawayUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_i = false;
      } else {
        DoorLckCtl_ThermRunawayUnlck = false;
        AppSwcBcm_ARID_DEF.Cnt_op++;
      }
    } else {
      AppSwcBcm_ARID_DEF.Cnt_op = 1U;
    }
  } else {
    DoorLckCtl_ThermRunawayUnlck = false;
  }

  /* Logic: '<S477>/Logical Operator' */
  DoorLckCtl_InsUnlck = (DoorLckCtl_HUUnLck || DoorLckCtl_ParkUnlck ||
    DoorLckCtl_ThermRunawayUnlck || DoorLckCtl_CrshUnlck);
}

/* Output and update for atomic system: '<S466>/MotorProt' */
static void AppSwcBcm_MotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S478>/Logical Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_bo = (DoorLckCtl_InsLck || DoorLckCtl_OsLck ||
    DoorLckCtl_InsUnlck || DoorLckCtl_OsUnlck || DoorLckCtl_TrunkUnlck);

  /* Chart: '<S478>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S509>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_bo,
    &AppSwcBcm_ARID_DEF.LogicalOperator_au,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ip);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_au && (!AppSwcBcm_ARID_DEF.LIB_blOut_eq))
  {
    tmp = AppSwcBcm_ARID_DEF.Cnt_er + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_er + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_er = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;

    /* LIB_blOut=0; */
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_i = (uint16)tmp;
  }

  /* Constant: '<S478>/Constant' */
  if (AppSwcBcm_ARID_DEF.Cnt2_i >= DoorLckCtl_CntSubTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_er - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_er - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_er = (uint16)tmp;
  }

  /* End of Constant: '<S478>/Constant' */

  /* Constant: '<S478>/Constant1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_ga = (AppSwcBcm_ARID_DEF.Cnt_er >
    DoorLckCtl_MotorWorkMax_C);

  /* Chart: '<S478>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S509>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ga,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ag,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_o);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ag) {
    AppSwcBcm_ARID_DEF.LIB_blOut_eq = true;
    AppSwcBcm_ARID_DEF.Cnt3_k = 0U;
  }

  if (AppSwcBcm_ARID_DEF.LIB_blOut_eq) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3_k + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3_k + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3_k = (uint16)tmp;
  }

  /* Constant: '<S478>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt3_k >= DoorLckCtl_MotorProtTimMax_C) {
    AppSwcBcm_ARID_DEF.LIB_blOut_eq = false;
    AppSwcBcm_ARID_DEF.Cnt_er = 0U;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;
    AppSwcBcm_ARID_DEF.Cnt3_k = 0U;
  }

  /* End of Constant: '<S478>/Constant2' */

  /* Switch: '<S478>/Switch' incorporates:
   *  UnitDelay: '<S4>/Unit Delay6'
   */
  DoorLckCtl_MotorProt = ((!AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_c) &&
    AppSwcBcm_ARID_DEF.LIB_blOut_eq);
}

/*
 * System initialize for atomic system:
 *    '<S514>/LIB_PosPluse2'
 *    '<S693>/LIB_PosPluse2'
 *    '<S968>/LIB_NegPluse2'
 *    '<S969>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S514>/LIB_PosPluse2'
 *    '<S693>/LIB_PosPluse2'
 *    '<S968>/LIB_NegPluse2'
 *    '<S969>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S514>/LIB_PosPluse2' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blRst;

  /* Outputs for Function Call SubSystem: '<S521>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S521>/Lib_RiseEdgeDet' */

  /* Chart: '<S514>/LIB_PosPluse2' */
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

/* System initialize for atomic system: '<S479>/AutoLck' */
static void AppSwcBcm_AutoLck_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_gz;

  /* SystemInitialize for Chart: '<S514>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_gz);
}

/* Output and update for atomic system: '<S479>/AutoLck' */
static void AppSwcBcm_AutoLck(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_gz;
  boolean rtb_LogicalOperator5_gm;
  boolean rtb_RelationalOperator_m;
  boolean rtb_UnitDelay_g3;

  /* Logic: '<S514>/Logical Operator5' incorporates:
   *  Constant: '<S514>/Constant13'
   *  Constant: '<S514>/Constant14'
   *  Constant: '<S514>/Constant15'
   *  Logic: '<S514>/Logical Operator4'
   *  RelationalOperator: '<S514>/Relational Operator10'
   *  RelationalOperator: '<S514>/Relational Operator11'
   *  RelationalOperator: '<S514>/Relational Operator12'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_LogicalOperator5_gm = (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Outputs for Atomic SubSystem: '<S514>/Lib_ChangeEdge' */
  /* RelationalOperator: '<S522>/Relational Operator' incorporates:
   *  Constant: '<S514>/Constant8'
   *  UnitDelay: '<S522>/Unit Delay'
   */
  rtb_RelationalOperator_m = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o == 1);

  /* Update for UnitDelay: '<S522>/Unit Delay' incorporates:
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o = AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a;

  /* End of Outputs for SubSystem: '<S514>/Lib_ChangeEdge' */

  /* UnitDelay: '<S523>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S514>/Relational Operator9'
   */
  rtb_UnitDelay_g3 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S514>/Lib_SR' */
  /* Switch: '<S524>/Switch' incorporates:
   *  Constant: '<S514>/Constant11'
   *  Logic: '<S514>/Logical Operator'
   *  Logic: '<S514>/Logical Operator2'
   *  Logic: '<S514>/Logical Operator3'
   *  Logic: '<S514>/Logical Operator7'
   *  RelationalOperator: '<S514>/Relational Operator13'
   *  RelationalOperator: '<S514>/Relational Operator2'
   *  RelationalOperator: '<S514>/Relational Operator3'
   *  RelationalOperator: '<S514>/Relational Operator4'
   *  RelationalOperator: '<S514>/Relational Operator5'
   *  RelationalOperator: '<S514>/Relational Operator7'
   *  RelationalOperator: '<S514>/Relational Operator8'
   */
  if ((!DoorLckCtl_DoorAjarFLSw) || (!DoorLckCtl_DoorAjarFRSw) ||
      (!DoorLckCtl_DoorAjarRRSw) || (!DoorLckCtl_TrunkAjarSw) ||
      (!AppSwcBcm_ConstB.RelationalOperator6) || ((AppSwcBcm_ARID_DEF.UnitDelay2
        != 0) && (!rtb_LogicalOperator5_gm)) || rtb_UnitDelay_g3 ||
      DoorLckCtl_OsLck) {
    /* Switch: '<S524>/Switch' incorporates:
     *  Constant: '<S524>/Constant'
     */
    DoorLckCtl_AutoLckSta = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S514>/Lib_ChangeEdge' */
    /* Switch: '<S524>/Switch' incorporates:
     *  Constant: '<S514>/Constant'
     *  Constant: '<S514>/Constant1'
     *  Logic: '<S514>/Logical Operator1'
     *  Logic: '<S514>/Logical Operator6'
     *  Logic: '<S522>/Logical Operator'
     *  Logic: '<S524>/Logical Operator'
     *  RelationalOperator: '<S514>/Relational Operator'
     *  RelationalOperator: '<S522>/Relational Operator1'
     *  UnitDelay: '<S4>/Unit Delay1'
     *  UnitDelay: '<S524>/Unit Delay'
     */
    DoorLckCtl_AutoLckSta = (((rtb_LogicalOperator5_gm ||
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) &&
      ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) && rtb_RelationalOperator_m))
      || DoorLckCtl_AutoLckSta);

    /* End of Outputs for SubSystem: '<S514>/Lib_ChangeEdge' */
  }

  /* End of Switch: '<S524>/Switch' */
  /* End of Outputs for SubSystem: '<S514>/Lib_SR' */

  /* Chart: '<S514>/LIB_PosPluse2' incorporates:
   *  Constant: '<S514>/Constant7'
   *  RelationalOperator: '<S514>/Relational Operator1'
   */
  AppSwcBcm_LIB_PosPluse2(DoorLckCtl_AutoLckSta, DoorLckCtl_AutoLckDelayTim_C,
    DoorLckCtl_OsUnlck, &rtb_LIB_blOut_gz,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2_o);

  /* Outputs for Atomic SubSystem: '<S514>/Lib_RiseEdgeDet' */
  /* Logic: '<S523>/Logical Operator' incorporates:
   *  Logic: '<S523>/Logical Operator1'
   *  UnitDelay: '<S523>/Unit Delay'
   */
  DoorLckCtl_AutoLck = (rtb_LIB_blOut_gz &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ej));

  /* Update for UnitDelay: '<S523>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ej = rtb_LIB_blOut_gz;

  /* End of Outputs for SubSystem: '<S514>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S515>/LIB_TPD_10ms1'
 *    '<S534>/LIB_TPD_10ms1'
 *    '<S534>/LIB_TPD_10ms2'
 */
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S515>/LIB_TPD_10ms1'
 *    '<S534>/LIB_TPD_10ms1'
 *    '<S534>/LIB_TPD_10ms2'
 */
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  rtu_LIB_bInit, boolean *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S515>/LIB_TPD_10ms1' */
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

  /* End of Chart: '<S515>/LIB_TPD_10ms1' */
}

/* System initialize for atomic system: '<S479>/MechLck' */
static void AppSwcBcm_MechLck_Init(void)
{
  /* InitializeConditions for Delay: '<S528>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_oy = true;

  /* SystemInitialize for Chart: '<S515>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_je);
}

/* Output and update for atomic system: '<S479>/MechLck' */
static void AppSwcBcm_MechLck(void)
{
  boolean rtb_Delay_i1;
  boolean rtb_RelationalOperator_kl;

  /* RelationalOperator: '<S515>/Relational Operator' incorporates:
   *  Constant: '<S515>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_kl =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Delay: '<S528>/Delay' incorporates:
   *  Constant: '<S515>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S515>/Relational Operator1'
   */
  rtb_Delay_i1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                  ->VGSM_VehActGearPstn_enum == 0);

  /* Chart: '<S515>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S515>/Constant40'
   *  Constant: '<S515>/Constant41'
   *  Constant: '<S515>/Constant42'
   *  Constant: '<S515>/Constant7'
   *  Logic: '<S515>/Logical Operator1'
   *  RelationalOperator: '<S515>/Relational Operator2'
   *  RelationalOperator: '<S515>/Relational Operator3'
   *  RelationalOperator: '<S515>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 10, 10,
    DoorLckCtl_Ts_C, true, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_je,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_l);

  /* Delay: '<S528>/Delay' incorporates:
   *  RelationalOperator: '<S515>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_oy) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_jk = DoorLckCtl_DriverDoorLckSw;
  }

  /* Logic: '<S515>/Logical Operator3' incorporates:
   *  Delay: '<S528>/Delay'
   *  Logic: '<S515>/Logical Operator'
   *  Logic: '<S528>/Logical Operator'
   *  Logic: '<S528>/Logical Operator1'
   *  RelationalOperator: '<S515>/Relational Operator4'
   *  RelationalOperator: '<S515>/Relational Operator6'
   */
  DoorLckCtl_MechLck = ((!DoorLckCtl_DrvSeatSw) && (rtb_Delay_i1 ||
    rtb_RelationalOperator_kl) && (DoorLckCtl_DriverDoorLckSw &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_jk)) && AppSwcBcm_ARID_DEF.LIB_bErrFlg_je &&
                        DoorLckCtl_VehStop);

  /* Update for Delay: '<S528>/Delay' incorporates:
   *  RelationalOperator: '<S515>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.icLoad_oy = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_jk = DoorLckCtl_DriverDoorLckSw;
}

/* Output and update for atomic system: '<S479>/PELck' */
static void AppSwcBcm_PELck(void)
{
  boolean rtb_RelationalOperator4_l;
  boolean rtb_RelationalOperator5_m5;

  /* RelationalOperator: '<S516>/Relational Operator4' incorporates:
   *  Constant: '<S516>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator4_l =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S516>/Relational Operator5' incorporates:
   *  Constant: '<S516>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_m5 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S516>/Logical Operator1' incorporates:
   *  Logic: '<S516>/Logical Operator2'
   *  Logic: '<S516>/Logical Operator3'
   *  RelationalOperator: '<S516>/Relational Operator1'
   *  RelationalOperator: '<S516>/Relational Operator2'
   *  RelationalOperator: '<S516>/Relational Operator3'
   */
  DoorLckCtl_PELck = (AppSwcBcm_ARID_DEF.LogicalOperator_ft &&
                      (!DoorLckCtl_DriverDoorLckSw) && (!DoorLckCtl_DrvSeatSw) &&
                      (rtb_RelationalOperator4_l || rtb_RelationalOperator5_m5) &&
                      (DoorLckCtl_DoorAjarFLSw && DoorLckCtl_DoorAjarFRSw &&
                       DoorLckCtl_DoorAjarRRSw) && DoorLckCtl_VehStop);
}

/* Output and update for atomic system: '<S479>/RKELck' */
static void AppSwcBcm_RKELck(void)
{
  boolean rtb_RelationalOperator1_nk;
  boolean rtb_UnitDelay_jc;

  /* RelationalOperator: '<S517>/Relational Operator1' incorporates:
   *  Constant: '<S517>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_nk =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* UnitDelay: '<S529>/Unit Delay' incorporates:
   *  Constant: '<S517>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S517>/Relational Operator2'
   */
  rtb_UnitDelay_jc = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                      ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S517>/Logical Operator1' incorporates:
   *  Constant: '<S517>/Constant'
   *  Logic: '<S517>/Logical Operator3'
   *  RelationalOperator: '<S517>/Relational Operator'
   *  RelationalOperator: '<S517>/Relational Operator3'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  rtb_RelationalOperator1_nk = ((!DoorLckCtl_DrvSeatSw) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 2) && (rtb_RelationalOperator1_nk ||
    rtb_UnitDelay_jc) && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S517>/Lib_RiseEdgeDet' */
  /* Logic: '<S529>/Logical Operator' incorporates:
   *  Logic: '<S529>/Logical Operator1'
   *  UnitDelay: '<S529>/Unit Delay'
   */
  DoorLckCtl_RKELck = (rtb_RelationalOperator1_nk &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bt));

  /* Update for UnitDelay: '<S529>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bt = rtb_RelationalOperator1_nk;

  /* End of Outputs for SubSystem: '<S517>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S479>/TboxLck' */
static void AppSwcBcm_TboxLck(void)
{
  boolean rtb_RelationalOperator2_fl;
  boolean rtb_RelationalOperator_gn;
  boolean rtb_UnitDelay_gt;

  /* RelationalOperator: '<S518>/Relational Operator' incorporates:
   *  Constant: '<S518>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_gn = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBoxRmtLck_enum == 1);

  /* RelationalOperator: '<S518>/Relational Operator2' incorporates:
   *  Constant: '<S518>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_fl =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* UnitDelay: '<S530>/Unit Delay' incorporates:
   *  Constant: '<S518>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S518>/Relational Operator3'
   */
  rtb_UnitDelay_gt = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                      ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S518>/Logical Operator1' incorporates:
   *  Logic: '<S518>/Logical Operator'
   *  RelationalOperator: '<S518>/Relational Operator1'
   */
  rtb_RelationalOperator_gn = (rtb_RelationalOperator_gn &&
    (!DoorLckCtl_DrvSeatSw) && (rtb_RelationalOperator2_fl || rtb_UnitDelay_gt) &&
    DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S518>/Lib_RiseEdgeDet' */
  /* Logic: '<S530>/Logical Operator' incorporates:
   *  Logic: '<S530>/Logical Operator1'
   *  UnitDelay: '<S530>/Unit Delay'
   */
  DoorLckCtl_TboxLck = (rtb_RelationalOperator_gn &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nd));

  /* Update for UnitDelay: '<S530>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nd = rtb_RelationalOperator_gn;

  /* End of Outputs for SubSystem: '<S518>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S479>/TrunkAutoLck' */
static void AppSwcBcm_TrunkAutoLck(void)
{
  boolean rtb_LIB_blOut_md;
  boolean rtb_RelationalOperator2_p4;

  /* RelationalOperator: '<S519>/Relational Operator2' incorporates:
   *  Constant: '<S519>/Constant2'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_RelationalOperator2_p4 = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 3);

  /* Chart: '<S519>/LIB_PosPluse1' incorporates:
   *  Constant: '<S519>/Constant1'
   *  Constant: '<S519>/Constant5'
   *  Delay: '<S519>/Delay'
   *  Logic: '<S519>/Logical Operator'
   *  Logic: '<S519>/Logical Operator2'
   *  Logic: '<S519>/Logical Operator3'
   *  RelationalOperator: '<S519>/Relational Operator1'
   *  RelationalOperator: '<S519>/Relational Operator3'
   *  UnitDelay: '<S519>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.Delay_DSTATE_d3[0U]) {
    AppSwcBcm_ARID_DEF.Flg_hw = true;
    AppSwcBcm_ARID_DEF.Cnt_n2 = 0U;
  }

  if ((!rtb_RelationalOperator2_p4) || (!DoorLckCtl_TrunkAjarSw) ||
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) || DoorLckCtl_TrunkAutoLck) {
    AppSwcBcm_ARID_DEF.Flg_hw = false;
    AppSwcBcm_ARID_DEF.Cnt_n2 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_hw) {
    if (AppSwcBcm_ARID_DEF.Cnt_n2 >= DoorLckCtl_TrunkAutoLckTim_C) {
      rtb_LIB_blOut_md = true;
      AppSwcBcm_ARID_DEF.Flg_hw = false;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_n2++;
      rtb_LIB_blOut_md = false;
    }
  } else {
    rtb_LIB_blOut_md = false;
    AppSwcBcm_ARID_DEF.Cnt_n2 = 0U;
  }

  /* End of Chart: '<S519>/LIB_PosPluse1' */

  /* Logic: '<S519>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S519>/Relational Operator3'
   */
  rtb_RelationalOperator2_p4 = (rtb_RelationalOperator2_p4 &&
    DoorLckCtl_TrunkAjarSw && rtb_LIB_blOut_md);

  /* Outputs for Atomic SubSystem: '<S519>/Lib_RiseEdgeDet' */
  /* Logic: '<S532>/Logical Operator' incorporates:
   *  Logic: '<S532>/Logical Operator1'
   *  UnitDelay: '<S532>/Unit Delay'
   */
  DoorLckCtl_TrunkAutoLck = (rtb_RelationalOperator2_p4 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fa));

  /* Update for UnitDelay: '<S532>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fa = rtb_RelationalOperator2_p4;

  /* End of Outputs for SubSystem: '<S519>/Lib_RiseEdgeDet' */

  /* Update for Delay: '<S519>/Delay' incorporates:
   *  Constant: '<S519>/Constant'
   *  RelationalOperator: '<S519>/Relational Operator'
   *  UnitDelay: '<S431>/Unit Delay3'
   */
  AppSwcBcm_ARID_DEF.Delay_DSTATE_d3[0] = AppSwcBcm_ARID_DEF.Delay_DSTATE_d3[1];
  AppSwcBcm_ARID_DEF.Delay_DSTATE_d3[1] =
    (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k == 1);
}

/* Output and update for atomic system: '<S479>/WelcomeLck' */
static void AppSwcBcm_WelcomeLck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator10_i;
  boolean rtb_RelationalOperator2_n3;
  boolean rtb_RelationalOperator3_b4;

  /* RelationalOperator: '<S520>/Relational Operator2' incorporates:
   *  Constant: '<S520>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_n3 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S520>/Relational Operator3' incorporates:
   *  Constant: '<S520>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_b4 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S520>/Relational Operator10' incorporates:
   *  Constant: '<S520>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator10_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->LckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S520>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator10_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_i);

  /* End of Outputs for SubSystem: '<S520>/Lib_RiseEdgeDet' */

  /* Logic: '<S520>/Logical Operator2' incorporates:
   *  Constant: '<S520>/Constant10'
   *  Logic: '<S520>/Logical Operator'
   *  Logic: '<S520>/Logical Operator1'
   *  Logic: '<S520>/Logical Operator3'
   *  RelationalOperator: '<S520>/Relational Operator'
   *  RelationalOperator: '<S520>/Relational Operator1'
   *  RelationalOperator: '<S520>/Relational Operator4'
   *  RelationalOperator: '<S520>/Relational Operator5'
   *  RelationalOperator: '<S520>/Relational Operator6'
   *  RelationalOperator: '<S520>/Relational Operator7'
   *  RelationalOperator: '<S520>/Relational Operator8'
   *  RelationalOperator: '<S520>/Relational Operator9'
   */
  DoorLckCtl_WelcomeLck = (rtb_LogicalOperator && ((DoorLckCtl_IllmndLckStsFb ==
    1) && (DoorLckCtl_EEIlluminatedEntrySys == 1) && (rtb_RelationalOperator2_n3
    || rtb_RelationalOperator3_b4) && (!DoorLckCtl_DriverDoorLckSw) &&
    (DoorLckCtl_DoorAjarFLSw && DoorLckCtl_DoorAjarFRSw &&
     DoorLckCtl_DoorAjarRRSw) && (DoorLckCtl_IllmndSts == 1) &&
    (!DoorLckCtl_DrvSeatSw) && DoorLckCtl_VehStop));
}

/* System initialize for atomic system: '<S466>/OutsideLck' */
static void AppSwcBcm_OutsideLck_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S479>/AutoLck' */
  AppSwcBcm_AutoLck_Init();

  /* End of SystemInitialize for SubSystem: '<S479>/AutoLck' */

  /* SystemInitialize for Atomic SubSystem: '<S479>/MechLck' */
  AppSwcBcm_MechLck_Init();

  /* End of SystemInitialize for SubSystem: '<S479>/MechLck' */
}

/* Output and update for atomic system: '<S466>/OutsideLck' */
static void AppSwcBcm_OutsideLck(void)
{
  /* Outputs for Atomic SubSystem: '<S479>/AutoLck' */
  AppSwcBcm_AutoLck();

  /* End of Outputs for SubSystem: '<S479>/AutoLck' */

  /* Outputs for Atomic SubSystem: '<S479>/MechLck' */
  AppSwcBcm_MechLck();

  /* End of Outputs for SubSystem: '<S479>/MechLck' */

  /* Outputs for Atomic SubSystem: '<S479>/PELck' */
  AppSwcBcm_PELck();

  /* End of Outputs for SubSystem: '<S479>/PELck' */

  /* Outputs for Atomic SubSystem: '<S479>/WelcomeLck' */
  AppSwcBcm_WelcomeLck();

  /* End of Outputs for SubSystem: '<S479>/WelcomeLck' */

  /* Outputs for Atomic SubSystem: '<S479>/RKELck' */
  AppSwcBcm_RKELck();

  /* End of Outputs for SubSystem: '<S479>/RKELck' */

  /* Outputs for Atomic SubSystem: '<S479>/TrunkAutoLck' */
  AppSwcBcm_TrunkAutoLck();

  /* End of Outputs for SubSystem: '<S479>/TrunkAutoLck' */

  /* Outputs for Atomic SubSystem: '<S479>/TboxLck' */
  AppSwcBcm_TboxLck();

  /* End of Outputs for SubSystem: '<S479>/TboxLck' */

  /* Logic: '<S479>/Logical Operator' */
  DoorLckCtl_OsLck = (DoorLckCtl_MechLck || DoorLckCtl_PELck ||
                      DoorLckCtl_AutoLck || DoorLckCtl_WelcomeLck ||
                      DoorLckCtl_RKELck || DoorLckCtl_TrunkAutoLck ||
                      DoorLckCtl_TboxLck);
}

/* System initialize for atomic system: '<S480>/MechUnlck' */
static void AppSwcBcm_MechUnlck_Init(void)
{
  /* InitializeConditions for Delay: '<S542>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_aa = true;

  /* SystemInitialize for Chart: '<S534>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_a);

  /* SystemInitialize for Chart: '<S534>/LIB_TPD_10ms2' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_n);
}

/* Output and update for atomic system: '<S480>/MechUnlck' */
static void AppSwcBcm_MechUnlck(void)
{
  boolean rtb_RelationalOperator3_g2;

  /* Chart: '<S534>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S534>/Constant'
   *  Constant: '<S534>/Constant40'
   *  Constant: '<S534>/Constant41'
   *  Constant: '<S534>/Constant42'
   *  Logic: '<S534>/Logical Operator1'
   *  RelationalOperator: '<S534>/Relational Operator1'
   *  RelationalOperator: '<S534>/Relational Operator2'
   *  RelationalOperator: '<S534>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 0,
    DoorLckCtl_Ts_C, true, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_as);

  /* RelationalOperator: '<S534>/Relational Operator3' */
  rtb_RelationalOperator3_g2 = !DoorLckCtl_DriverDoorLckSw;

  /* Delay: '<S542>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_aa) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_dt = rtb_RelationalOperator3_g2;
  }

  /* Chart: '<S534>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S534>/Constant6'
   *  Constant: '<S534>/Constant7'
   *  Constant: '<S534>/Constant8'
   *  Constant: '<S534>/Constant9'
   *  RelationalOperator: '<S534>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_DoorProtUnlck, 0, 30, DoorLckCtl_Ts_C,
    false, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms2);

  /* Logic: '<S534>/Logical Operator' incorporates:
   *  Delay: '<S542>/Delay'
   *  Logic: '<S534>/Logical Operator2'
   *  Logic: '<S542>/Logical Operator'
   *  Logic: '<S542>/Logical Operator1'
   */
  DoorLckCtl_MechUnlck = ((!AppSwcBcm_ARID_DEF.LIB_bErrFlg_n) &&
    (rtb_RelationalOperator3_g2 && (!AppSwcBcm_ARID_DEF.Delay_DSTATE_dt)) &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_a);

  /* Update for Delay: '<S542>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_aa = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_dt = rtb_RelationalOperator3_g2;
}

/* Output and update for atomic system: '<S480>/PEUnlck' */
static void AppSwcBcm_PEUnlck(void)
{
  boolean rtb_RelationalOperator7_e;

  /* RelationalOperator: '<S535>/Relational Operator7' incorporates:
   *  Constant: '<S535>/Constant5'
   */
  rtb_RelationalOperator7_e = (AppSwcBcm_ARID_DEF.UnitDelay2 == 2);

  /* Logic: '<S535>/Logical Operator1' incorporates:
   *  Constant: '<S535>/Constant2'
   *  Constant: '<S535>/Constant3'
   *  Constant: '<S535>/Constant4'
   *  Constant: '<S535>/Constant7'
   *  Constant: '<S535>/Constant8'
   *  Logic: '<S535>/Logical Operator2'
   *  Logic: '<S535>/Logical Operator3'
   *  Logic: '<S535>/Logical Operator4'
   *  Logic: '<S535>/Logical Operator5'
   *  Logic: '<S535>/Logical Operator6'
   *  RelationalOperator: '<S535>/Relational Operator1'
   *  RelationalOperator: '<S535>/Relational Operator2'
   *  RelationalOperator: '<S535>/Relational Operator3'
   *  RelationalOperator: '<S535>/Relational Operator4'
   *  RelationalOperator: '<S535>/Relational Operator5'
   *  RelationalOperator: '<S535>/Relational Operator6'
   *  RelationalOperator: '<S535>/Relational Operator8'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  DoorLckCtl_PEUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_ft &&
                        DoorLckCtl_DriverDoorLckSw &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0)) ||
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) && rtb_RelationalOperator7_e)
    || (rtb_RelationalOperator7_e && (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2))));
}

/* Output and update for atomic system: '<S480>/RKEUnlck' */
static void AppSwcBcm_RKEUnlck(void)
{
  boolean rtb_LogicalOperator4_fs;

  /* Logic: '<S536>/Logical Operator4' incorporates:
   *  Constant: '<S536>/Constant'
   *  Constant: '<S536>/Constant1'
   *  Constant: '<S536>/Constant2'
   *  Constant: '<S536>/Constant3'
   *  Constant: '<S536>/Constant4'
   *  Constant: '<S536>/Constant5'
   *  Constant: '<S536>/Constant6'
   *  Logic: '<S536>/Logical Operator'
   *  Logic: '<S536>/Logical Operator1'
   *  Logic: '<S536>/Logical Operator2'
   *  Logic: '<S536>/Logical Operator3'
   *  RelationalOperator: '<S536>/Relational Operator'
   *  RelationalOperator: '<S536>/Relational Operator1'
   *  RelationalOperator: '<S536>/Relational Operator2'
   *  RelationalOperator: '<S536>/Relational Operator3'
   *  RelationalOperator: '<S536>/Relational Operator4'
   *  RelationalOperator: '<S536>/Relational Operator5'
   *  RelationalOperator: '<S536>/Relational Operator6'
   *  UnitDelay: '<S4>/Unit Delay'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  rtb_LogicalOperator4_fs = ((AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 1) &&
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) ||
     (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
       (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
       (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2)) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 2))));

  /* Outputs for Atomic SubSystem: '<S536>/Lib_RiseEdgeDet' */
  /* Logic: '<S543>/Logical Operator' incorporates:
   *  Logic: '<S543>/Logical Operator1'
   *  UnitDelay: '<S543>/Unit Delay'
   */
  DoorLckCtl_RKEUnlck = (rtb_LogicalOperator4_fs &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_oe));

  /* Update for UnitDelay: '<S543>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_oe = rtb_LogicalOperator4_fs;

  /* End of Outputs for SubSystem: '<S536>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S480>/TboxUnlck' */
static void AppSwcBcm_TboxUnlck(void)
{
  boolean rtb_UnitDelay_f5;

  /* UnitDelay: '<S544>/Unit Delay' incorporates:
   *  Constant: '<S537>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S537>/Relational Operator'
   */
  rtb_UnitDelay_f5 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                      ->VIPM_TBoxRmtLck_enum == 2);

  /* Logic: '<S537>/Logical Operator3' incorporates:
   *  Constant: '<S537>/Constant1'
   *  Constant: '<S537>/Constant2'
   *  Constant: '<S537>/Constant3'
   *  Constant: '<S537>/Constant4'
   *  Constant: '<S537>/Constant5'
   *  Logic: '<S537>/Logical Operator'
   *  Logic: '<S537>/Logical Operator1'
   *  Logic: '<S537>/Logical Operator2'
   *  RelationalOperator: '<S537>/Relational Operator1'
   *  RelationalOperator: '<S537>/Relational Operator2'
   *  RelationalOperator: '<S537>/Relational Operator3'
   *  RelationalOperator: '<S537>/Relational Operator4'
   *  RelationalOperator: '<S537>/Relational Operator5'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_UnitDelay_f5 = (rtb_UnitDelay_f5 && ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) ||
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 2) &&
     ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5)))));

  /* Outputs for Atomic SubSystem: '<S537>/Lib_RiseEdgeDet' */
  /* Logic: '<S544>/Logical Operator' incorporates:
   *  Logic: '<S544>/Logical Operator1'
   *  UnitDelay: '<S544>/Unit Delay'
   */
  DoorLckCtl_TboxUnlck = (rtb_UnitDelay_f5 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fj));

  /* Update for UnitDelay: '<S544>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fj = rtb_UnitDelay_f5;

  /* End of Outputs for SubSystem: '<S537>/Lib_RiseEdgeDet' */
}

/* System initialize for atomic system: '<S480>/TrunkUnlck' */
static void AppSwcBcm_TrunkUnlck_Init(void)
{
  /* SystemInitialize for Chart: '<S538>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_g);
}

/* Output and update for atomic system: '<S480>/TrunkUnlck' */
static void AppSwcBcm_TrunkUnlck(void)
{
  boolean rtb_LogicalOperator1_j1;
  boolean rtb_RelationalOperator5_ef;
  boolean rtb_UnitDelay_hi;

  /* Chart: '<S538>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S538>/Constant'
   *  Constant: '<S538>/Constant2'
   *  Constant: '<S538>/Constant3'
   *  Constant: '<S538>/Constant4'
   *  RelationalOperator: '<S538>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  AppSwcBcm_LIB_TPD_10ms(AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 3,
    DoorLckCtl_TrunkUnlckTimValid_C, DoorLckCtl_TrunkUnlckTimInvalid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_a);

  /* Logic: '<S538>/Logical Operator1' incorporates:
   *  Constant: '<S538>/Constant6'
   *  RelationalOperator: '<S538>/Relational Operator3'
   */
  rtb_LogicalOperator1_j1 = ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_g && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S538>/Lib_RiseEdgeDet1' */
  /* Logic: '<S546>/Logical Operator' incorporates:
   *  Logic: '<S546>/Logical Operator1'
   *  UnitDelay: '<S546>/Unit Delay'
   */
  DoorLckCtl_TrunkRKEUnlck = (rtb_LogicalOperator1_j1 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pa));

  /* Update for UnitDelay: '<S546>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pa = rtb_LogicalOperator1_j1;

  /* End of Outputs for SubSystem: '<S538>/Lib_RiseEdgeDet1' */

  /* RelationalOperator: '<S538>/Relational Operator1' incorporates:
   *  Constant: '<S538>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_LogicalOperator1_j1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC()
    )->VIPM_HUTrnkLckSwCtrl_enum == 1);

  /* RelationalOperator: '<S538>/Relational Operator5' incorporates:
   *  Constant: '<S538>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_ef =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* UnitDelay: '<S548>/Unit Delay' incorporates:
   *  Constant: '<S538>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S538>/Relational Operator6'
   */
  rtb_UnitDelay_hi = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                      ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S538>/Lib_RiseEdgeDet2' */

  /* Logic: '<S538>/Logical Operator3' incorporates:
   *  Constant: '<S538>/Constant5'
   *  Constant: '<S538>/Constant7'
   *  Logic: '<S538>/Logical Operator2'
   *  RelationalOperator: '<S538>/Relational Operator2'
   *  RelationalOperator: '<S538>/Relational Operator4'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_n2 = AppSwcBcm_Lib_RiseEdgeDet
    (DoorLckCtl_VehStop && rtb_LogicalOperator1_j1 &&
     (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) &&
     (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && (rtb_RelationalOperator5_ef ||
      rtb_UnitDelay_hi), &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_ev);

  /* End of Outputs for SubSystem: '<S538>/Lib_RiseEdgeDet2' */

  /* UnitDelay: '<S548>/Unit Delay' incorporates:
   *  Constant: '<S538>/Constant10'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S538>/Relational Operator7'
   */
  rtb_UnitDelay_hi = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                      ->VIPM_TBoxRmtLck_enum == 3);

  /* Logic: '<S538>/Logical Operator4' incorporates:
   *  Constant: '<S538>/Constant11'
   *  RelationalOperator: '<S538>/Relational Operator8'
   */
  rtb_LogicalOperator1_j1 = (rtb_UnitDelay_hi && (AppSwcBcm_ARID_DEF.UnitDelay2 ==
    0) && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S538>/Lib_RiseEdgeDet3' */
  /* Logic: '<S548>/Logical Operator' incorporates:
   *  Logic: '<S548>/Logical Operator1'
   *  UnitDelay: '<S548>/Unit Delay'
   */
  DoorLckCtl_TrunkTboxUnlck = (rtb_LogicalOperator1_j1 &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fd));

  /* Update for UnitDelay: '<S548>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fd = rtb_LogicalOperator1_j1;

  /* End of Outputs for SubSystem: '<S538>/Lib_RiseEdgeDet3' */

  /* Logic: '<S538>/Logical Operator' */
  DoorLckCtl_TrunkUnlck = (DoorLckCtl_TrunkRKEUnlck ||
    AppSwcBcm_ARID_DEF.LogicalOperator_n2 || DoorLckCtl_TrunkTboxUnlck);
}

/* Output and update for atomic system: '<S480>/WelcomeUnlck' */
static void AppSwcBcm_WelcomeUnlck(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator4_p;

  /* RelationalOperator: '<S539>/Relational Operator4' incorporates:
   *  Constant: '<S539>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator4_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->UnlckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S539>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator4_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_af);

  /* End of Outputs for SubSystem: '<S539>/Lib_RiseEdgeDet' */

  /* Logic: '<S539>/Logical Operator1' incorporates:
   *  Constant: '<S539>/Constant1'
   *  Constant: '<S539>/Constant4'
   *  Constant: '<S539>/Constant5'
   *  Constant: '<S539>/Constant8'
   *  Logic: '<S539>/Logical Operator'
   *  RelationalOperator: '<S539>/Relational Operator'
   *  RelationalOperator: '<S539>/Relational Operator1'
   *  RelationalOperator: '<S539>/Relational Operator2'
   *  RelationalOperator: '<S539>/Relational Operator3'
   *  RelationalOperator: '<S539>/Relational Operator5'
   */
  DoorLckCtl_WelcomeUnlck = (rtb_LogicalOperator && (DoorLckCtl_DriverDoorLckSw &&
    (DoorLckCtl_IllmndUnlockStsFb == 1) && (DoorLckCtl_EEIlluminatedEntrySys ==
    1) && (AppSwcBcm_ARID_DEF.UnitDelay2 == 0) && (DoorLckCtl_IllmndSts == 1)));
}

/* System initialize for atomic system: '<S466>/OutsideUnlck' */
static void AppSwcBcm_OutsideUnlck_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S480>/MechUnlck' */
  AppSwcBcm_MechUnlck_Init();

  /* End of SystemInitialize for SubSystem: '<S480>/MechUnlck' */

  /* SystemInitialize for Atomic SubSystem: '<S480>/TrunkUnlck' */
  AppSwcBcm_TrunkUnlck_Init();

  /* End of SystemInitialize for SubSystem: '<S480>/TrunkUnlck' */
}

/* Output and update for atomic system: '<S466>/OutsideUnlck' */
static void AppSwcBcm_OutsideUnlck(void)
{
  /* Outputs for Atomic SubSystem: '<S480>/RKEUnlck' */
  AppSwcBcm_RKEUnlck();

  /* End of Outputs for SubSystem: '<S480>/RKEUnlck' */

  /* Outputs for Atomic SubSystem: '<S480>/PEUnlck' */
  AppSwcBcm_PEUnlck();

  /* End of Outputs for SubSystem: '<S480>/PEUnlck' */

  /* Outputs for Atomic SubSystem: '<S480>/WelcomeUnlck' */
  AppSwcBcm_WelcomeUnlck();

  /* End of Outputs for SubSystem: '<S480>/WelcomeUnlck' */

  /* Outputs for Atomic SubSystem: '<S480>/MechUnlck' */
  AppSwcBcm_MechUnlck();

  /* End of Outputs for SubSystem: '<S480>/MechUnlck' */

  /* Outputs for Atomic SubSystem: '<S480>/TboxUnlck' */
  AppSwcBcm_TboxUnlck();

  /* End of Outputs for SubSystem: '<S480>/TboxUnlck' */

  /* Logic: '<S480>/Logical Operator' */
  DoorLckCtl_OsUnlck = (DoorLckCtl_RKEUnlck || DoorLckCtl_PEUnlck ||
                        DoorLckCtl_WelcomeUnlck || DoorLckCtl_MechUnlck ||
                        DoorLckCtl_TboxUnlck);

  /* Outputs for Atomic SubSystem: '<S480>/TrunkUnlck' */
  AppSwcBcm_TrunkUnlck();

  /* End of Outputs for SubSystem: '<S480>/TrunkUnlck' */
}

/* Output and update for atomic system: '<S466>/PECtl' */
static void AppSwcBcm_PECtl(void)
{
  sint32 tmp;
  boolean rtb_RelationalOperator2_bp;
  boolean rtb_RelationalOperator6;

  /* RelationalOperator: '<S481>/Relational Operator2' incorporates:
   *  Constant: '<S481>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator2_bp = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->DrvPEAuthentAcsd == 1);

  /* RelationalOperator: '<S481>/Relational Operator6' incorporates:
   *  Constant: '<S481>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator6 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->FRPEAuthentAcsd == 1);

  /* Logic: '<S481>/Logical Operator1' incorporates:
   *  Constant: '<S481>/Constant5'
   *  Logic: '<S481>/Logical Operator'
   *  Logic: '<S481>/Logical Operator3'
   *  RelationalOperator: '<S481>/Relational Operator'
   *  RelationalOperator: '<S481>/Relational Operator1'
   *  RelationalOperator: '<S481>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_hg = ((DoorLckCtl_DrvPESw || DoorLckCtl_PsgPESw) &&
    (rtb_RelationalOperator2_bp || rtb_RelationalOperator6) &&
    (DoorLckCtl_EEKeyEntry == 1));

  /* Chart: '<S481>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S550>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_hg,
    &AppSwcBcm_ARID_DEF.LogicalOperator_g2,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p5);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_g2) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ik + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ik + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_ik = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_b = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_b + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_b + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_b = (uint16)tmp;
  }

  /* Constant: '<S481>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt2_b >= DoorLckCtl_PEProtIntvlTim_C) {
    AppSwcBcm_ARID_DEF.Cnt_ik = 0U;
    AppSwcBcm_ARID_DEF.LIB_blOut_cj = false;
  }

  /* End of Constant: '<S481>/Constant2' */

  /* Constant: '<S481>/Constant3' */
  AppSwcBcm_ARID_DEF.LIB_blOut_cj = ((AppSwcBcm_ARID_DEF.Cnt_ik >=
    DoorLckCtl_PEProtCnt_C) || AppSwcBcm_ARID_DEF.LIB_blOut_cj);

  /* Outputs for Atomic SubSystem: '<S481>/Lib_RiseEdgeDet' */
  /* Switch: '<S481>/Switch' */
  AppSwcBcm_ARID_DEF.LogicalOperator_ft = AppSwcBcm_Lib_RiseEdgeDet
    ((!AppSwcBcm_ARID_DEF.LIB_blOut_cj) && AppSwcBcm_ARID_DEF.Lib_blIn_hg,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p);

  /* End of Outputs for SubSystem: '<S481>/Lib_RiseEdgeDet' */
}

/* System initialize for atomic system: '<S466>/ParkUnlckSet' */
static void AppSwcBcm_ParkUnlckSet_Init(void)
{
  /* InitializeConditions for Delay: '<S482>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_gf = true;
}

/* Output and update for atomic system: '<S466>/ParkUnlckSet' */
static void AppSwcBcm_ParkUnlckSet(void)
{
  uint8 rtb_Switch1_o;
  uint8 rtb_Switch2_nx;
  boolean rtb_RelationalOperator3_dew;

  /* Switch: '<S482>/Switch1' incorporates:
   *  Constant: '<S482>/Constant1'
   *  RelationalOperator: '<S482>/Relational Operator1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S482>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch1_o = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUParkAutoUnlckSet_enum;
  } else {
    /* Switch: '<S482>/Switch1' incorporates:
     *  Constant: '<S482>/Constant4'
     */
    rtb_Switch1_o = 0U;
  }

  /* End of Switch: '<S482>/Switch1' */

  /* RelationalOperator: '<S482>/Relational Operator3' incorporates:
   *  Constant: '<S482>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_dew =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->ParkAutoUnlockSetFb ==
     255);

  /* Switch: '<S482>/Switch2' */
  if (rtb_RelationalOperator3_dew) {
    /* Switch: '<S482>/Switch2' incorporates:
     *  Constant: '<S482>/Constant6'
     */
    rtb_Switch2_nx = 1U;
  } else {
    /* Switch: '<S482>/Switch2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch2_nx = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
      ->ParkAutoUnlockSetFb;
  }

  /* End of Switch: '<S482>/Switch2' */

  /* Delay: '<S482>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_gf) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_h = rtb_Switch2_nx;
  }

  /* MultiPortSwitch: '<S482>/Multiport Switch' incorporates:
   *  Constant: '<S482>/Constant2'
   *  Constant: '<S482>/Constant3'
   *  Delay: '<S482>/Delay'
   */
  switch (rtb_Switch1_o) {
   case 1:
    DoorLckCtl_ParkAutoUnlockSetFb = 0U;
    break;

   case 2:
    DoorLckCtl_ParkAutoUnlockSetFb = 1U;
    break;

   default:
    DoorLckCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_h;
    break;
  }

  /* End of MultiPortSwitch: '<S482>/Multiport Switch' */

  /* Update for Delay: '<S482>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_gf = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_h = DoorLckCtl_ParkAutoUnlockSetFb;
}

/* ConstCode for atomic system: '<S466>/SpdLck' */
static void AppSwcBcm_SpdLck_e_Const(void)
{
  /* ConstCode for Constant: '<S483>/Constant8' */
  DoorLckCtl_SpdCtlLckSet = 1U;
}

/* Output and update for atomic system: '<S466>/TboxLckFb' */
static void AppSwcBcm_TboxLckFb(void)
{
  sint32 tmp;

  /* Chart: '<S484>/Chart2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c31_DoorLckCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c31_DoorLckCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib = AppSwcBcm_IN_Init_c;
    DoorLckCtl_RemoteLockFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_ke = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib) {
     case AppSwcBcm_IN_Fail_k:
      DoorLckCtl_RemoteLockFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_ke >= DoorLckCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib = AppSwcBcm_IN_Trans;
        DoorLckCtl_RemoteLockFb = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_ke++;
      }
      break;

     case AppSwcBcm_IN_Init_c:
      DoorLckCtl_RemoteLockFb = 0U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBoxRmtLck_enum != 0) && ((DoorLckCtl_TboxLck &&
            (!DoorLckCtl_TboxAntiLck)) || DoorLckCtl_TboxUnlck ||
           DoorLckCtl_TrunkTboxUnlck)) {
        AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib = AppSwcBcm_IN_Suc_m;
        DoorLckCtl_RemoteLockFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_ke + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_ke + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_ke = (uint8)tmp;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_cr =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBoxRmtLck_enum != 0);

        /* Outputs for Function Call SubSystem: '<S554>/Lib_FailEdgeDet' */
        AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_cr,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ir,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_c);

        /* End of Outputs for SubSystem: '<S554>/Lib_FailEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ir && ((!DoorLckCtl_TboxLck) && (
              !DoorLckCtl_TboxUnlck) && (!DoorLckCtl_TrunkTboxUnlck))) {
          AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib = AppSwcBcm_IN_Fail_k;
          DoorLckCtl_RemoteLockFb = 3U;
          tmp = AppSwcBcm_ARID_DEF.Cnt_ke + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_ke + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_ke = (uint8)tmp;
        }
      }
      break;

     case AppSwcBcm_IN_Suc_m:
      DoorLckCtl_RemoteLockFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_ke >= DoorLckCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib = AppSwcBcm_IN_Trans;
        DoorLckCtl_RemoteLockFb = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_ke++;
      }
      break;

     default:
      /* case IN_Trans: */
      DoorLckCtl_RemoteLockFb = 0U;
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtLck_enum == 0) {
        AppSwcBcm_ARID_DEF.Lib_blIn_cr =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBoxRmtLck_enum != 0);

        /* Outputs for Function Call SubSystem: '<S554>/Lib_FailEdgeDet' */
        AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_cr,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ir,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_c);

        /* End of Outputs for SubSystem: '<S554>/Lib_FailEdgeDet' */
        AppSwcBcm_ARID_DEF.is_c31_DoorLckCtl_Lib = AppSwcBcm_IN_Init_c;
        AppSwcBcm_ARID_DEF.Cnt_ke = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S484>/Chart2' */
}

/* System initialize for atomic system: '<S431>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S466>/IllmndLckSet' */
  AppSwcBcm_IllmndLckSet_Init();

  /* End of SystemInitialize for SubSystem: '<S466>/IllmndLckSet' */

  /* SystemInitialize for Atomic SubSystem: '<S466>/IllmndUnlckSet' */
  AppSwcBcm_IllmndUnlckSet_Init();

  /* End of SystemInitialize for SubSystem: '<S466>/IllmndUnlckSet' */

  /* SystemInitialize for Atomic SubSystem: '<S466>/InsideLck' */
  AppSwcBcm_InsideLck_Init();

  /* End of SystemInitialize for SubSystem: '<S466>/InsideLck' */

  /* SystemInitialize for Atomic SubSystem: '<S466>/OutsideLck' */
  AppSwcBcm_OutsideLck_Init();

  /* End of SystemInitialize for SubSystem: '<S466>/OutsideLck' */

  /* SystemInitialize for Atomic SubSystem: '<S466>/OutsideUnlck' */
  AppSwcBcm_OutsideUnlck_Init();

  /* End of SystemInitialize for SubSystem: '<S466>/OutsideUnlck' */

  /* SystemInitialize for Atomic SubSystem: '<S466>/ParkUnlckSet' */
  AppSwcBcm_ParkUnlckSet_Init();

  /* End of SystemInitialize for SubSystem: '<S466>/ParkUnlckSet' */
}

/* Outputs for atomic system: '<S431>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic(void)
{
  /* Outputs for Atomic SubSystem: '<S466>/PECtl' */
  AppSwcBcm_PECtl();

  /* End of Outputs for SubSystem: '<S466>/PECtl' */

  /* Outputs for Atomic SubSystem: '<S466>/IllmndLckSet' */
  AppSwcBcm_IllmndLckSet();

  /* End of Outputs for SubSystem: '<S466>/IllmndLckSet' */

  /* Outputs for Atomic SubSystem: '<S466>/OutsideLck' */
  AppSwcBcm_OutsideLck();

  /* End of Outputs for SubSystem: '<S466>/OutsideLck' */

  /* Outputs for Atomic SubSystem: '<S466>/InsideLck' */
  AppSwcBcm_InsideLck();

  /* End of Outputs for SubSystem: '<S466>/InsideLck' */

  /* Outputs for Atomic SubSystem: '<S466>/AntiLckProt' */
  AppSwcBcm_AntiLckProt();

  /* End of Outputs for SubSystem: '<S466>/AntiLckProt' */

  /* Outputs for Atomic SubSystem: '<S466>/IllmndUnlckSet' */
  AppSwcBcm_IllmndUnlckSet();

  /* End of Outputs for SubSystem: '<S466>/IllmndUnlckSet' */

  /* Outputs for Atomic SubSystem: '<S466>/OutsideUnlck' */
  AppSwcBcm_OutsideUnlck();

  /* End of Outputs for SubSystem: '<S466>/OutsideUnlck' */

  /* Outputs for Atomic SubSystem: '<S466>/ParkUnlckSet' */
  AppSwcBcm_ParkUnlckSet();

  /* End of Outputs for SubSystem: '<S466>/ParkUnlckSet' */

  /* Outputs for Atomic SubSystem: '<S466>/InsideUnlck' */
  AppSwcBcm_InsideUnlck();

  /* End of Outputs for SubSystem: '<S466>/InsideUnlck' */

  /* Outputs for Atomic SubSystem: '<S466>/MotorProt' */
  AppSwcBcm_MotorProt();

  /* End of Outputs for SubSystem: '<S466>/MotorProt' */

  /* Outputs for Atomic SubSystem: '<S466>/TboxLckFb' */
  AppSwcBcm_TboxLckFb();

  /* End of Outputs for SubSystem: '<S466>/TboxLckFb' */
}

/* ConstCode for atomic system: '<S431>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S466>/SpdLck' */
  AppSwcBcm_SpdLck_e_Const();

  /* End of ConstCode for SubSystem: '<S466>/SpdLck' */
}

/*
 * Output and update for atomic system:
 *    '<S470>/Bit Shift12'
 *    '<S674>/Bit Shift11'
 */
static uint16 AppSwcBcm_BitShift12_d(uint16 rtu_u)
{
  /* MATLAB Function: '<S558>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 11);
}

/*
 * Output and update for atomic system:
 *    '<S470>/Bit Shift4'
 *    '<S674>/Bit Shift2'
 */
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u)
{
  /* MATLAB Function: '<S564>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S470>/Bit Shift6'
 *    '<S674>/Bit Shift8'
 */
static uint16 AppSwcBcm_BitShift6(uint16 rtu_u)
{
  /* MATLAB Function: '<S566>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S470>/Bit Shift7'
 *    '<S674>/Bit Shift9'
 */
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u)
{
  /* MATLAB Function: '<S567>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 6);
}

/*
 * Output and update for atomic system:
 *    '<S470>/Bit Shift8'
 *    '<S674>/Bit Shift3'
 */
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u)
{
  /* MATLAB Function: '<S568>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S470>/Bit Shift9'
 *    '<S674>/Bit Shift10'
 */
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u)
{
  /* MATLAB Function: '<S569>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 8);
}

/* Output and update for atomic system: '<S431>/SignalProcess' */
static void AppSwcBcm_SignalProcess_h(void)
{
  uint16 rtb_Switch12_k;
  uint16 tmp;
  boolean rtb_DataTypeConversion17;
  boolean rtb_RelationalOperator1_jm;
  boolean rtb_Switch1_k;

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift1' */
  /* Constant: '<S470>/Constant5' */
  rtb_Switch12_k = AppSwcBcm_BitShift1_i(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift1' */

  /* Switch: '<S470>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND1'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch1' incorporates:
     *  Constant: '<S470>/Constant4'
     */
    rtb_Switch1_k = DoorLckCtl_DoorAjarFLVal_C;
  } else {
    /* Switch: '<S470>/Switch1' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion1'
     */
    rtb_Switch1_k = (BSW_J321DoorAjarFL != 0);
  }

  /* End of Switch: '<S470>/Switch1' */

  /* DataTypeConversion: '<S470>/Data Type Conversion17' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->DoorAjarFLSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S470>/Constant1'
   *  Constant: '<S470>/Constant2'
   *  Constant: '<S470>/Constant3'
   */
  if (!AppSwcBcm_ARID_DEF.flg_ko) {
    DoorLckCtl_DoorAjarFLSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_ko = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_iz >= (float32)
         DoorLckCtl_DoorAjarFLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_iz++;
      AppSwcBcm_ARID_DEF.cnt_heal_mf = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_iz = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mf >= (float32)
        DoorLckCtl_DoorAjarFLTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarFLSw = false;
    } else if (DoorLckCtl_DoorAjarFLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mf++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift2' */
  /* Constant: '<S470>/Constant10' */
  rtb_Switch12_k = AppSwcBcm_BitShift2(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift2' */

  /* Switch: '<S470>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND2'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch2' incorporates:
     *  Constant: '<S470>/Constant9'
     */
    rtb_Switch1_k = DoorLckCtl_DoorAjarFRVal_C;
  } else {
    /* Switch: '<S470>/Switch2' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion2'
     */
    rtb_Switch1_k = (BSW_J310DoorAjarFR != 0);
  }

  /* End of Switch: '<S470>/Switch2' */

  /* DataTypeConversion: '<S470>/Data Type Conversion16' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->DoorAjarFRSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S470>/Constant6'
   *  Constant: '<S470>/Constant7'
   *  Constant: '<S470>/Constant8'
   */
  if (!AppSwcBcm_ARID_DEF.flg_f) {
    DoorLckCtl_DoorAjarFRSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_f = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_a >= (float32)
         DoorLckCtl_DoorAjarFRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_a++;
      AppSwcBcm_ARID_DEF.cnt_heal_od = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_a = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_od >= (float32)
        DoorLckCtl_DoorAjarFRTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarFRSw = false;
    } else if (DoorLckCtl_DoorAjarFRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_od++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift5' */
  /* Constant: '<S470>/Constant59' */
  rtb_Switch12_k = AppSwcBcm_BitShift3(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift5' */

  /* Switch: '<S470>/Switch5' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND5'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch5' incorporates:
     *  Constant: '<S470>/Constant60'
     */
    rtb_Switch1_k = DoorLckCtl_DriverDoorLckVal_C;
  } else {
    /* Switch: '<S470>/Switch5' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion5'
     */
    rtb_Switch1_k = (BSW_J335DriverDoorLck != 0);
  }

  /* End of Switch: '<S470>/Switch5' */

  /* DataTypeConversion: '<S470>/Data Type Conversion18' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->DriverDoorLckSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S470>/Constant46'
   *  Constant: '<S470>/Constant47'
   *  Constant: '<S470>/Constant49'
   */
  if (!AppSwcBcm_ARID_DEF.flg_d) {
    DoorLckCtl_DriverDoorLckSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_d = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hl >= (float32)
         DoorLckCtl_DriverDoorLckTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DriverDoorLckTimValid_C != 0xFFFF)) {
      DoorLckCtl_DriverDoorLckSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hl++;
      AppSwcBcm_ARID_DEF.cnt_heal_n3 = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hl = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n3 >= (float32)
        DoorLckCtl_DriverDoorLckTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DriverDoorLckSw = false;
    } else if (DoorLckCtl_DriverDoorLckTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n3++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift3' */
  /* Constant: '<S470>/Constant11' */
  rtb_Switch12_k = AppSwcBcm_BitShift1_m(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift3' */

  /* Switch: '<S470>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND3'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch3' incorporates:
     *  Constant: '<S470>/Constant12'
     */
    rtb_Switch1_k = DoorLckCtl_DrvPEVal_C;
  } else {
    /* Switch: '<S470>/Switch3' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion3'
     *  Logic: '<S470>/Logical Operator6'
     */
    rtb_Switch1_k = (BSW_J338DrvPE == 0);
  }

  /* End of Switch: '<S470>/Switch3' */

  /* Chart: '<S470>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S470>/Constant25'
   *  Constant: '<S470>/Constant26'
   *  Constant: '<S470>/Constant27'
   *  Constant: '<S470>/Constant77'
   */
  if (!AppSwcBcm_ARID_DEF.flg_e) {
    DoorLckCtl_DrvPESw = false;
    AppSwcBcm_ARID_DEF.flg_e = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_bm >= (float32)DoorLckCtl_DrvPETimValid_C
         / (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_DrvPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_DrvPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_bm++;
      AppSwcBcm_ARID_DEF.cnt_heal_mm = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_bm = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mm >= (float32)DoorLckCtl_DrvPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DrvPESw = false;
    } else if (DoorLckCtl_DrvPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mm++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift4' */
  /* Constant: '<S470>/Constant13' */
  rtb_Switch12_k = AppSwcBcm_BitShift4(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift4' */

  /* Switch: '<S470>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND4'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch4' incorporates:
     *  Constant: '<S470>/Constant14'
     */
    rtb_Switch1_k = DoorLckCtl_PsgPEVal_C;
  } else {
    /* Switch: '<S470>/Switch4' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion4'
     *  Logic: '<S470>/Logical Operator7'
     */
    rtb_Switch1_k = (BSW_J337PsgPE == 0);
  }

  /* End of Switch: '<S470>/Switch4' */

  /* Chart: '<S470>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S470>/Constant28'
   *  Constant: '<S470>/Constant29'
   *  Constant: '<S470>/Constant30'
   *  Constant: '<S470>/Constant78'
   */
  if (!AppSwcBcm_ARID_DEF.flg_a) {
    DoorLckCtl_PsgPESw = false;
    AppSwcBcm_ARID_DEF.flg_a = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_he >= (float32)DoorLckCtl_PsgPETimValid_C
         / (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_PsgPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_he++;
      AppSwcBcm_ARID_DEF.cnt_heal_ko = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_he = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ko >= (float32)DoorLckCtl_PsgPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_PsgPESw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ko++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift6' */
  /* Constant: '<S470>/Constant15' */
  rtb_Switch12_k = AppSwcBcm_BitShift6(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift6' */

  /* Switch: '<S470>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND6'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch6' incorporates:
     *  Constant: '<S470>/Constant16'
     */
    rtb_Switch1_k = DoorLckCtl_TrunkSwVal_C;
  } else {
    /* Switch: '<S470>/Switch6' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion6'
     */
    rtb_Switch1_k = (BSW_J336Trunk != 0);
  }

  /* End of Switch: '<S470>/Switch6' */

  /* DataTypeConversion: '<S470>/Data Type Conversion15' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->TrunkSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S470>/Constant31'
   *  Constant: '<S470>/Constant32'
   *  Constant: '<S470>/Constant33'
   */
  if (!AppSwcBcm_ARID_DEF.flg_l) {
    DoorLckCtl_TrunkSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_l = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_bj >= (float32)DoorLckCtl_PsgPETimValid_C
         / (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_TrunkSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_bj++;
      AppSwcBcm_ARID_DEF.cnt_heal_i0 = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_bj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_i0 >= (float32)DoorLckCtl_PsgPETimInvalid_C /
        (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_TrunkSw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_i0++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift7' */
  /* Constant: '<S470>/Constant17' */
  rtb_Switch12_k = AppSwcBcm_BitShift7(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift7' */

  /* Switch: '<S470>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND7'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch7' incorporates:
     *  Constant: '<S470>/Constant18'
     */
    rtb_Switch1_k = DoorLckCtl_DoorAjarRLVal_C;
  } else {
    /* Switch: '<S470>/Switch7' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion7'
     */
    rtb_Switch1_k = (BSW_J320DoorAjarRL != 0);
  }

  /* End of Switch: '<S470>/Switch7' */

  /* DataTypeConversion: '<S470>/Data Type Conversion14' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->DoorAjarRLSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S470>/Constant34'
   *  Constant: '<S470>/Constant35'
   *  Constant: '<S470>/Constant36'
   */
  if (!AppSwcBcm_ARID_DEF.flg_n) {
    DoorLckCtl_DoorAjarRLSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_n = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_mg >= (float32)
         DoorLckCtl_DoorAjarRLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_mg++;
      AppSwcBcm_ARID_DEF.cnt_heal_i = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_mg = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_i >= (float32)
        DoorLckCtl_DoorAjarRLTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarRLSw = false;
    } else if (DoorLckCtl_DoorAjarRLTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_i++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift8' */
  /* Constant: '<S470>/Constant19' */
  rtb_Switch12_k = AppSwcBcm_BitShift8(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift8' */

  /* Switch: '<S470>/Switch8' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND8'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch8' incorporates:
     *  Constant: '<S470>/Constant20'
     */
    rtb_Switch1_k = DoorLckCtl_DoorAjarRRVal_C;
  } else {
    /* Switch: '<S470>/Switch8' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion8'
     */
    rtb_Switch1_k = (BSW_J36DoorAjarRR != 0);
  }

  /* End of Switch: '<S470>/Switch8' */

  /* DataTypeConversion: '<S470>/Data Type Conversion13' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->DoorAjarRRSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S470>/Constant37'
   *  Constant: '<S470>/Constant38'
   *  Constant: '<S470>/Constant39'
   */
  if (!AppSwcBcm_ARID_DEF.flg_i) {
    DoorLckCtl_DoorAjarRRSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_i = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_g >= (float32)
         DoorLckCtl_DoorAjarRRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_g++;
      AppSwcBcm_ARID_DEF.cnt_heal_e = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_g = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e >= (float32)
        DoorLckCtl_DoorAjarRRTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DoorAjarRRSw = false;
    } else if (DoorLckCtl_DoorAjarRRTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_e++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms7' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift9' */
  /* Constant: '<S470>/Constant21' */
  rtb_Switch12_k = AppSwcBcm_BitShift9(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift9' */

  /* Switch: '<S470>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND9'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    /* Switch: '<S470>/Switch9' incorporates:
     *  Constant: '<S470>/Constant22'
     */
    rtb_Switch1_k = DoorLckCtl_TrunkAjarVal_C;
  } else {
    /* Switch: '<S470>/Switch9' incorporates:
     *  DataTypeConversion: '<S470>/Data Type Conversion9'
     */
    rtb_Switch1_k = (BSW_J37TrunkAjar != 0);
  }

  /* End of Switch: '<S470>/Switch9' */

  /* DataTypeConversion: '<S470>/Data Type Conversion12' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->TrunkAjarSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S470>/Constant40'
   *  Constant: '<S470>/Constant41'
   *  Constant: '<S470>/Constant42'
   */
  if (!AppSwcBcm_ARID_DEF.flg_h) {
    DoorLckCtl_TrunkAjarSw = rtb_DataTypeConversion17;
    AppSwcBcm_ARID_DEF.flg_h = true;
  }

  if (rtb_Switch1_k) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fd >= (float32)
         DoorLckCtl_TrunkAjarTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_TrunkAjarTimValid_C != 0xFFFF)) {
      DoorLckCtl_TrunkAjarSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fd++;
      AppSwcBcm_ARID_DEF.cnt_heal_o = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_o >= (float32)
        DoorLckCtl_TrunkAjarTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_TrunkAjarSw = false;
    } else if (DoorLckCtl_TrunkAjarTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_o++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift12' */
  /* Constant: '<S470>/Constant62' */
  rtb_Switch12_k = AppSwcBcm_BitShift12_d(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S470>/Bit Shift12' */

  /* Switch: '<S470>/Switch12' incorporates:
   *  Constant: '<S470>/Constant63'
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND12'
   */
  if ((rtb_Switch12_k & 1U) != 0U) {
    tmp = DoorLckCtl_DrvSeatResisVal_C;
  } else {
    tmp = BSW_J112DrvSeatResis;
  }

  /* DataTypeConversion: '<S470>/Data Type Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_Switch1_k = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
                   ->DrvSeatSw != 0);

  /* Chart: '<S470>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S470>/Constant64'
   *  Constant: '<S470>/Constant65'
   *  Constant: '<S470>/Constant66'
   *  Constant: '<S470>/Constant67'
   *  RelationalOperator: '<S470>/Relational Operator6'
   *  Switch: '<S470>/Switch12'
   */
  if (!AppSwcBcm_ARID_DEF.flg_k) {
    DoorLckCtl_DrvSeatSw = rtb_Switch1_k;
    AppSwcBcm_ARID_DEF.flg_k = true;
  }

  if (tmp <= DoorLckCtl_DrvSeatResisMin_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ev >= (float32)
         DoorLckCtl_DrvSeatTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DrvSeatTimValid_C != 0xFFFF)) {
      DoorLckCtl_DrvSeatSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ev++;
      AppSwcBcm_ARID_DEF.cnt_heal_h1r = 0U;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ev = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h1r >= (float32)
        DoorLckCtl_DrvSeatTimInValid_C / (DoorLckCtl_Ts_C * 100.0F)) {
      DoorLckCtl_DrvSeatSw = false;
    } else if (DoorLckCtl_DrvSeatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_h1r++;
    }
  }

  /* End of Chart: '<S470>/LIB_TPD_10ms11' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift13' */
  /* Switch: '<S470>/Switch13' incorporates:
   *  Constant: '<S470>/Constant71'
   *  Constant: '<S470>/Constant72'
   *  MATLAB Function: '<S559>/bit_shift'
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND13'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 12 & 1U) != 0U) {
    DoorLckCtl_EEKeyEntry = DoorLckCtl_EEKeyEntry_C;
  } else {
    DoorLckCtl_EEKeyEntry = BSW_EEKeyEntry;
  }

  /* End of Switch: '<S470>/Switch13' */
  /* End of Outputs for SubSystem: '<S470>/Bit Shift13' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift14' */
  /* Switch: '<S470>/Switch14' incorporates:
   *  Constant: '<S470>/Constant73'
   *  Constant: '<S470>/Constant74'
   *  MATLAB Function: '<S560>/bit_shift'
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND14'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 13 & 1U) != 0U) {
    DoorLckCtl_EEIlluminatedEntrySys = DoorLckCtl_EEIlluminatedEntrySys_C;
  } else {
    DoorLckCtl_EEIlluminatedEntrySys = BSW_EEIlluminatedEntrySys;
  }

  /* End of Switch: '<S470>/Switch14' */
  /* End of Outputs for SubSystem: '<S470>/Bit Shift14' */

  /* Outputs for Atomic SubSystem: '<S470>/Bit Shift15' */
  /* Switch: '<S470>/Switch15' incorporates:
   *  Constant: '<S470>/Constant75'
   *  Constant: '<S470>/Constant76'
   *  MATLAB Function: '<S561>/bit_shift'
   *  S-Function (sfix_bitop): '<S470>/Bitwise AND15'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 14 & 1U) != 0U) {
    DoorLckCtl_IllmndSts = DoorLckCtl_IllmndSts_C;
  } else {
    DoorLckCtl_IllmndSts = BSW_IllmndSts;
  }

  /* End of Switch: '<S470>/Switch15' */
  /* End of Outputs for SubSystem: '<S470>/Bit Shift15' */

  /* Abs: '<S470>/Abs' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  DoorLckCtl_VehSpd = (float32)fabs
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())->VIPC_VehSpd_kph);

  /* RelationalOperator: '<S470>/Relational Operator' incorporates:
   *  Constant: '<S470>/Constant'
   */
  rtb_DataTypeConversion17 = (DoorLckCtl_VehSpd < 3.0F);

  /* RelationalOperator: '<S470>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_jm =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())->VIPC_VehSpdVld_flg;

  /* RelationalOperator: '<S470>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S470>/Relational Operator2'
   */
  rtb_Switch1_k = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehSpdVld_flg;

  /* Logic: '<S470>/Logical Operator1' incorporates:
   *  Logic: '<S470>/Logical Operator'
   */
  DoorLckCtl_VehStop = ((rtb_DataTypeConversion17 && rtb_RelationalOperator1_jm)
                        || rtb_Switch1_k);

  /* Logic: '<S470>/Logical Operator4' incorporates:
   *  Logic: '<S470>/Logical Operator2'
   *  Logic: '<S470>/Logical Operator3'
   */
  DoorLckCtl_VehRun = ((!rtb_DataTypeConversion17) && rtb_RelationalOperator1_jm);

  /* RelationalOperator: '<S470>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_Switch1_k = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehSpdVld_flg;

  /* Switch: '<S470>/Switch' incorporates:
   *  Constant: '<S470>/Constant54'
   */
  if (!rtb_Switch1_k) {
    DoorLckCtl_VehSpd = 0.0F;
  }

  /* End of Switch: '<S470>/Switch' */
}

/* ConstCode for atomic system: '<S431>/SignalProcess' */
static void AppSwcBcm_SignalProcess_n_Const(void)
{
  /* ConstCode for Constant: '<S470>/Constant69' */
  DoorLckCtl_HoodAjarSw = true;
}

/* System initialize for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S431>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Init();

  /* End of SystemInitialize for SubSystem: '<S431>/DoorLckCtlLogic' */
}

/* Outputs for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl(void)
{
  boolean rtb_DataTypeConversion1_f;

  /* Outputs for Atomic SubSystem: '<S431>/SignalProcess' */
  AppSwcBcm_SignalProcess_h();

  /* End of Outputs for SubSystem: '<S431>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S431>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic();

  /* End of Outputs for SubSystem: '<S431>/DoorLckCtlLogic' */

  /* Chart: '<S431>/DoorDrv' */
  AppSwcBcm_DoorDrv();

  /* Outputs for Atomic SubSystem: '<S431>/Ovrd1' */
  /* Switch: '<S467>/Switch1' incorporates:
   *  Constant: '<S431>/Constant1'
   *  Constant: '<S431>/Constant2'
   *  Switch: '<S467>/Switch2'
   */
  if (DoorLckCtl_J54DoorLckOvrdFlg_C) {
    DoorLckCtl_J54DoorLck = DoorLckCtl_J54DoorLckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S431>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorLlckCtlFlg != 0);
    DoorLckCtl_J54DoorLck = (rtb_DataTypeConversion1_f ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J54);
  }

  /* End of Switch: '<S467>/Switch1' */
  /* End of Outputs for SubSystem: '<S431>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S431>/Ovrd2' */
  /* Switch: '<S468>/Switch1' incorporates:
   *  Constant: '<S431>/Constant3'
   *  Constant: '<S431>/Constant4'
   *  Switch: '<S468>/Switch2'
   */
  if (DoorLckCtl_J511TrunkUnlckOvrdFlg_C) {
    DoorLckCtl_J511TrunkUnlck = DoorLckCtl_J511TrunkUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S431>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->TrunkUnlckCtlFlg != 0);
    DoorLckCtl_J511TrunkUnlck = (rtb_DataTypeConversion1_f ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J511);
  }

  /* End of Switch: '<S468>/Switch1' */
  /* End of Outputs for SubSystem: '<S431>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S431>/Ovrd3' */
  /* Switch: '<S469>/Switch1' incorporates:
   *  Constant: '<S431>/Constant18'
   *  Constant: '<S431>/Constant19'
   *  Switch: '<S469>/Switch2'
   */
  if (DoorLckCtl_J56DoorUnlckOvrdFlg_C) {
    DoorLckCtl_J56DoorUnlck = DoorLckCtl_J56DoorUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S431>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorUnlckCtlFlg != 0);
    DoorLckCtl_J56DoorUnlck = (rtb_DataTypeConversion1_f ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J56);
  }

  /* End of Switch: '<S469>/Switch1' */
  /* End of Outputs for SubSystem: '<S431>/Ovrd3' */
}

/* Update for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Update(void)
{
  /* Update for UnitDelay: '<S431>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k = DoorLckCtl_TrunkLckSta;
}

/* ConstCode for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S431>/SignalProcess' */
  AppSwcBcm_SignalProcess_n_Const();

  /* End of ConstCode for SubSystem: '<S431>/SignalProcess' */

  /* ConstCode for Atomic SubSystem: '<S431>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Const();

  /* End of ConstCode for SubSystem: '<S431>/DoorLckCtlLogic' */
}

/* Output and update for atomic system: '<S4>/DynDID' */
static void AppSwcBcm_DynDID(void)
{
  const EEReadCtl *tmp;
  const EEReadCtl *tmp_0;
  const EEReadCtl *tmp_1;
  const EEReadCtl *tmp_2;
  sint32 i;
  uint8 rtb_RecordSta;
  boolean rtb_RelationalOperator1_m0;
  boolean rtb_Switch;

  /* Chart: '<S600>/Chart' */
  DynDID_0xF234ADSampleValue[1] = 0U;
  DynDID_0xF234ADSampleValue[2] = 0U;

  /* CCaller: '<S600>/C Caller' incorporates:
   *  Constant: '<S600>/Constant'
   *  Constant: '<S600>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF234ADSampleValue[0], 23U, 62004U);

  /* CCaller: '<S594>/C Caller' incorporates:
   *  Constant: '<S432>/Constant27'
   *  Constant: '<S594>/Constant'
   *  Constant: '<S594>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF22BFobInformation[0], 16U, 61995U);

  /* Truth Table: '<S599>/Truth Table' */
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

  /* End of Truth Table: '<S599>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_c) {
    /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
    tmp = Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();
    for (i = 0; i < 10; i++) {
      /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
      DynDID_0xF233RemoteStartUpFailRecord[i] = tmp->RemoteStartFailRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_c = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_bt = (rtb_RecordSta != 0);

  /* Chart: '<S599>/Chart' incorporates:
   *  SubSystem: '<S617>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_bt,
    &AppSwcBcm_ARID_DEF.LogicalOperator_pv,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m3);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_pv) {
    i = AppSwcBcm_ARID_DEF.i + 1;
    if (AppSwcBcm_ARID_DEF.i + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i > 10) {
      AppSwcBcm_ARID_DEF.i = 1U;
    }
  }

  /* CCaller: '<S599>/C Caller' incorporates:
   *  Constant: '<S599>/Constant'
   *  Constant: '<S599>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF233RemoteStartUpFailRecord[0], 10U,
                     62003U);

  /* Truth Table: '<S596>/Truth Table' */
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

  /* End of Truth Table: '<S596>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_p) {
    /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
    tmp_0 = Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();
    for (i = 0; i < 10; i++) {
      /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
      DynDID_0xF230DoorOpRecord[i] = tmp_0->DoorOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_p = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_a0 = (rtb_RecordSta != 0);

  /* Chart: '<S596>/Chart' incorporates:
   *  SubSystem: '<S605>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_a0,
    &AppSwcBcm_ARID_DEF.LogicalOperator_aj,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c0);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_aj) {
    i = AppSwcBcm_ARID_DEF.i_lr + 1;
    if (AppSwcBcm_ARID_DEF.i_lr + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_lr = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_lr > 10) {
      AppSwcBcm_ARID_DEF.i_lr = 1U;
    }

    DynDID_0xF230DoorOpRecord[AppSwcBcm_ARID_DEF.i_lr - 1] = rtb_RecordSta;
  }

  /* CCaller: '<S596>/C Caller' incorporates:
   *  Constant: '<S596>/Constant'
   *  Constant: '<S596>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF230DoorOpRecord[0], 10U, 62000U);

  /* Switch: '<S596>/Switch' */
  if (rtb_RecordSta > 0) {
    /* Switch: '<S596>/Switch' */
    DynDID_DoorOpRecord = rtb_RecordSta;
  }

  /* End of Switch: '<S596>/Switch' */

  /* Truth Table: '<S597>/Truth Table' */
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

  /* End of Truth Table: '<S597>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_f) {
    /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
    tmp_1 = Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();
    for (i = 0; i < 10; i++) {
      /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
      DynDID_0xF231TrunkOpRecord[i] = tmp_1->TrunkOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_f = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_h1 = (rtb_RecordSta != 0);

  /* Chart: '<S597>/Chart' incorporates:
   *  SubSystem: '<S609>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_h1,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ms,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h5);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ms) {
    i = AppSwcBcm_ARID_DEF.i_l + 1;
    if (AppSwcBcm_ARID_DEF.i_l + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_l = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_l > 10) {
      AppSwcBcm_ARID_DEF.i_l = 1U;
    }

    DynDID_0xF231TrunkOpRecord[AppSwcBcm_ARID_DEF.i_l - 1] = rtb_RecordSta;
  }

  /* CCaller: '<S597>/C Caller' incorporates:
   *  Constant: '<S597>/Constant'
   *  Constant: '<S597>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF231TrunkOpRecord[0], 10U, 62001U);

  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Default */
  if (!AppSwcBcm_ARID_DEF.Flg_g) {
    /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
    tmp_2 = Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();
    for (i = 0; i < 10; i++) {
      /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
      DynDID_0xF232LocalStartUpFailRecord[i] = tmp_2->LocalStartFailOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_g = true;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_ai = false;

  /* Chart: '<S598>/Chart' incorporates:
   *  SubSystem: '<S613>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ai,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ih,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ja);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ih) {
    i = AppSwcBcm_ARID_DEF.i_a + 1;
    if (AppSwcBcm_ARID_DEF.i_a + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_a = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_a > 10) {
      AppSwcBcm_ARID_DEF.i_a = 1U;
    }
  }

  /* CCaller: '<S598>/C Caller' incorporates:
   *  Constant: '<S598>/Constant'
   *  Constant: '<S598>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF232LocalStartUpFailRecord[0], 10U,
                     62002U);

  /* Chart: '<S601>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S604>/Logical Operator'
   *  Logic: '<S604>/Logical Operator1'
   *  RelationalOperator: '<S432>/Relational Operator'
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

  /* CCaller: '<S601>/C Caller' incorporates:
   *  Constant: '<S601>/Constant'
   *  Constant: '<S601>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF235DigtInSampleValue[0], 5U, 62005U);

  /* Switch: '<S625>/Switch' incorporates:
   *  Constant: '<S625>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  RelationalOperator: '<S625>/Relational Operator'
   *  RelationalOperator: '<S625>/Relational Operator1'
   */
  rtb_Switch = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus())->DrvWinSta != 0);

  /* RelationalOperator: '<S625>/Relational Operator1' incorporates:
   *  Constant: '<S625>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  rtb_RelationalOperator1_m0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus()
    )->PsgWinSta != 0);

  /* Chart: '<S602>/Chart' incorporates:
   *  Constant: '<S624>/Constant'
   *  Constant: '<S624>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S624>/Logical Operator'
   *  Logic: '<S624>/Logical Operator1'
   *  RelationalOperator: '<S624>/Relational Operator'
   *  RelationalOperator: '<S624>/Relational Operator1'
   *  RelationalOperator: '<S624>/Relational Operator2'
   *  RelationalOperator: '<S624>/Relational Operator3'
   *  Switch: '<S625>/Switch1'
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
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)(rtb_RelationalOperator1_m0 << 4 |
    DynDID_0xF236DigtOutSampleValue[3]);
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator1.J421IG1RlyCtl << 7 |
     DynDID_0xF236DigtOutSampleValue[3]);
  DynDID_0xF236DigtOutSampleValue[4] = (uint8)(DynDID_0xF236DigtOutSampleValue[4]
    | AppSwcBcm_ARID_DEF.BusCreator1.J437IG2RlyCtl);
  DynDID_0xF236DigtOutSampleValue[4] = (uint8)
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornDrv << 1 |
     DynDID_0xF236DigtOutSampleValue[4]);

  /* CCaller: '<S602>/C Caller' incorporates:
   *  Constant: '<S602>/Constant'
   *  Constant: '<S602>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF236DigtOutSampleValue[0], 5U, 62006U);

  /* CCaller: '<S595>/C Caller' incorporates:
   *  Constant: '<S595>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts, 61996U);

  /* CCaller: '<S603>/C Caller' incorporates:
   *  Constant: '<S603>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts, 62007U);

  /* SignalConversion: '<S432>/Signal Conversion' */
  DynDID_0xF22CAntitheftSta = AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts;

  /* SignalConversion: '<S432>/Signal Conversion1' */
  DynDID_0xF237PwrModeSta = AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* CCaller: '<S593>/C Caller' incorporates:
   *  Constant: '<S593>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode, 61952U);

  /* SignalConversion: '<S432>/Signal Conversion2' */
  DynDID_0xF200ECUPwrMode = AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode;
}

/*
 * System initialize for atomic system:
 *    '<S626>/LIB_TPD_10ms11'
 *    '<S643>/LIB_TPD_10ms'
 *    '<S918>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms11_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S626>/LIB_TPD_10ms11'
 *    '<S643>/LIB_TPD_10ms'
 *    '<S918>/LIB_TPD_Ts'
 */
static void AppSwcBcm_LIB_TPD_10ms11(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms11_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  float32 tmp;

  /* Chart: '<S626>/LIB_TPD_10ms11' */
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

  /* End of Chart: '<S626>/LIB_TPD_10ms11' */
}

/* System initialize for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S626>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms11_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_bf);

  /* SystemInitialize for Chart: '<S626>/Lib_RiseEdgeDelay' incorporates:
   *  SubSystem: '<S630>/Lib_RiseEdgeDet'
   */
  /* InitializeConditions for Delay: '<S639>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = true;
}

/* Output and update for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl(void)
{
  sint32 tmp;
  uint8 rtb_Switch;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_bh1;
  boolean rtb_RelationalOperator1_ix;
  boolean rtb_RelationalOperator2_bg;

  /* Chart: '<S626>/Lib_RiseEdgeDelay' incorporates:
   *  SubSystem: '<S630>/Lib_RiseEdgeDet'
   */
  /* Delay: '<S639>/Delay' incorporates:
   *  RelationalOperator: '<S626>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_i) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_ox = AppSwcBcm_ARID_DEF.BusCreator4.OsLck;
  }

  /* Logic: '<S639>/Logical Operator1' incorporates:
   *  Delay: '<S639>/Delay'
   */
  rtb_LogicalOperator1_bh1 = !AppSwcBcm_ARID_DEF.Delay_DSTATE_ox;

  /* Update for Delay: '<S639>/Delay' incorporates:
   *  RelationalOperator: '<S626>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.icLoad_i = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_ox = AppSwcBcm_ARID_DEF.BusCreator4.OsLck;

  /* Logic: '<S639>/Logical Operator' incorporates:
   *  Constant: '<S626>/Constant6'
   *  RelationalOperator: '<S626>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.OsLck && rtb_LogicalOperator1_bh1) {
    AppSwcBcm_ARID_DEF.Cnt_kl = 2U;
    AppSwcBcm_ARID_DEF.LIB_blOut_a = true;
  }

  /* End of Logic: '<S639>/Logical Operator' */
  if (AppSwcBcm_ARID_DEF.Cnt_kl <= 0) {
    AppSwcBcm_ARID_DEF.LIB_blOut_a = false;
  } else {
    AppSwcBcm_ARID_DEF.Cnt_kl--;
  }

  /* RelationalOperator: '<S626>/Relational Operator1' incorporates:
   *  Constant: '<S626>/Constant1'
   */
  rtb_LogicalOperator1_bh1 = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0);

  /* Logic: '<S626>/Logical Operator' incorporates:
   *  Constant: '<S626>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S626>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S632>/Relational Operator2' incorporates:
   *  Constant: '<S626>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S626>/Relational Operator3'
   */
  rtb_RelationalOperator2_bg =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S626>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_RelationalOperator2_bg);

  /* RelationalOperator: '<S632>/Relational Operator2' incorporates:
   *  Constant: '<S632>/Constant5'
   *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
   */
  rtb_RelationalOperator2_bg =
    ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
      ())->VIPM_ESCLUnOrLockfeedback_nu == 576460752303423488ULL);

  /* RelationalOperator: '<S632>/Relational Operator1' incorporates:
   *  Constant: '<S632>/Constant1'
   *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
   */
  rtb_RelationalOperator1_ix =
    ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
      ())->VIPM_ESCLUnOrLockfeedback_nu == 648518346341351424ULL);

  /* Switch: '<S632>/Switch' incorporates:
   *  Logic: '<S632>/Logical Operator'
   */
  if (rtb_RelationalOperator2_bg || rtb_RelationalOperator1_ix) {
    /* Switch: '<S632>/Switch' incorporates:
     *  Constant: '<S632>/Constant2'
     */
    rtb_Switch = 2U;
  } else {
    /* RelationalOperator: '<S632>/Relational Operator3' incorporates:
     *  Constant: '<S632>/Constant6'
     *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
     */
    rtb_RelationalOperator2_bg =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
        ())->VIPM_ESCLUnOrLockfeedback_nu == 1152921504606846976ULL);

    /* RelationalOperator: '<S632>/Relational Operator' incorporates:
     *  Constant: '<S632>/Constant'
     *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
     */
    rtb_RelationalOperator1_ix =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
        ())->VIPM_ESCLUnOrLockfeedback_nu == 1297036692682702848ULL);

    /* Switch: '<S632>/Switch' incorporates:
     *  Logic: '<S632>/Logical Operator1'
     */
    rtb_Switch = (uint8)(rtb_RelationalOperator1_ix ||
                         rtb_RelationalOperator2_bg);
  }

  /* End of Switch: '<S632>/Switch' */

  /* Logic: '<S626>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S626>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_k2 = (AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
    AppSwcBcm_ARID_DEF.LIB_blOut_a && rtb_LogicalOperator1_bh1 &&
    rtb_LogicalOperator);

  /* Chart: '<S626>/ESCLLck' incorporates:
   *  SubSystem: '<S627>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_k2,
    &AppSwcBcm_ARID_DEF.LogicalOperator_my,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_md);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_my) {
    /* UnitDelay: '<S626>/Unit Delay' */
    if (ESCLCtl_Unlck == 1) {
      AppSwcBcm_ARID_DEF.Flg2_j = true;
      AppSwcBcm_ARID_DEF.Flg_ay = false;
      AppSwcBcm_ARID_DEF.Cnt_e = 0U;
      AppSwcBcm_ARID_DEF.ESCLCtl_UnlckPwrOff = true;
      AppSwcBcm_ARID_DEF.Cnt2_c = 0U;
      AppSwcBcm_ARID_DEF.Cnt3_m = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Flg_ay = true;
      AppSwcBcm_ARID_DEF.Cnt_e = 0U;
      ESCLCtl_J436Lck = true;
      AppSwcBcm_ARID_DEF.Cnt2_c = 0U;
      AppSwcBcm_ARID_DEF.Cnt3_m = 0U;
    }

    /* End of UnitDelay: '<S626>/Unit Delay' */
  }

  if (AppSwcBcm_ARID_DEF.Flg2_j) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3_m + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3_m + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3_m = (uint16)tmp;
  }

  if (AppSwcBcm_ARID_DEF.Cnt3_m > ESCLCtl_PwrOffDelay_C + 1) {
    AppSwcBcm_ARID_DEF.Flg2_j = false;
    AppSwcBcm_ARID_DEF.Flg_ay = true;
    AppSwcBcm_ARID_DEF.Cnt_e = 0U;
    ESCLCtl_J436Lck = true;
    AppSwcBcm_ARID_DEF.Cnt2_c = 0U;
    AppSwcBcm_ARID_DEF.Cnt3_m = 0U;
    AppSwcBcm_ARID_DEF.ESCLCtl_UnlckPwrOff = false;
  }

  if (AppSwcBcm_ARID_DEF.Flg_ay) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_c + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_c + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_c = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_e >= ESCLCtl_LckDelay_C) {
      ESCLCtl_Lck = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_e++;
    }
  }

  /* UnitDelay: '<S626>/Unit Delay2' */
  if ((rtb_Switch == 2) || AppSwcBcm_ARID_DEF.ESCLCtl_LckPwrOff) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_ay = false;
    ESCLCtl_Lck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2_c > ESCLCtl_LckTimMax_C) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_ay = false;
    ESCLCtl_Lck = 0U;
  }

  /* End of UnitDelay: '<S626>/Unit Delay2' */

  /* Logic: '<S626>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S626>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_lay = (AppSwcBcm_ARID_DEF.BusCreator1.PwrOn &&
    rtb_LogicalOperator && AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* Chart: '<S626>/ESCLUnlck' incorporates:
   *  SubSystem: '<S628>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_n(AppSwcBcm_ARID_DEF.Lib_blIn_lay,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ba,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_ba) {
    /* UnitDelay: '<S626>/Unit Delay1' */
    if (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_n == 2) {
      AppSwcBcm_ARID_DEF.Flg2 = 1.0;
      AppSwcBcm_ARID_DEF.Flg_m = false;
      AppSwcBcm_ARID_DEF.Cnt_b = 0U;
      AppSwcBcm_ARID_DEF.ESCLCtl_LckPwrOff = true;
      AppSwcBcm_ARID_DEF.Cnt2 = 0U;
      AppSwcBcm_ARID_DEF.Cnt3 = 0.0;
    } else {
      AppSwcBcm_ARID_DEF.Flg_m = true;
      AppSwcBcm_ARID_DEF.Cnt_b = 0U;
      ESCLCtl_J436Unlck = true;
      AppSwcBcm_ARID_DEF.Cnt2 = 0U;
      AppSwcBcm_ARID_DEF.Cnt3 = 0.0;
    }

    /* End of UnitDelay: '<S626>/Unit Delay1' */
  }

  if (AppSwcBcm_ARID_DEF.Flg2 == 1.0) {
    AppSwcBcm_ARID_DEF.Cnt3++;
  }

  if (AppSwcBcm_ARID_DEF.Cnt3 > (float64)ESCLCtl_PwrOffDelay_C + 1.0) {
    AppSwcBcm_ARID_DEF.Flg2 = 0.0;
    AppSwcBcm_ARID_DEF.Flg_m = true;
    AppSwcBcm_ARID_DEF.Cnt_b = 0U;
    ESCLCtl_J436Unlck = true;
    AppSwcBcm_ARID_DEF.Cnt2 = 0U;
    AppSwcBcm_ARID_DEF.Cnt3 = 0.0;
    AppSwcBcm_ARID_DEF.ESCLCtl_LckPwrOff = false;
  }

  if (AppSwcBcm_ARID_DEF.Flg_m) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2 = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_b >= ESCLCtl_UnlckDelay_C) {
      ESCLCtl_Unlck = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_b++;
    }
  }

  /* UnitDelay: '<S626>/Unit Delay3' */
  if ((rtb_Switch == 1) || AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_j) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_m = false;
    ESCLCtl_Unlck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2 > ESCLCtl_UnlckTimMax_C) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_m = false;
    ESCLCtl_Unlck = 0U;
  }

  /* End of UnitDelay: '<S626>/Unit Delay3' */

  /* Outputs for Atomic SubSystem: '<S626>/Ovrd' */
  /* Switch: '<S631>/Switch' incorporates:
   *  Constant: '<S626>/Constant18'
   */
  if (ESCLCtl_J436PwrSupOvrdFlg_C) {
    /* Switch: '<S631>/Switch' incorporates:
     *  Constant: '<S626>/Constant19'
     */
    ESCLCtl_J436PwrSup = ESCLCtl_J436PwrSupOvrdVal_C;
  } else {
    /* Switch: '<S631>/Switch' incorporates:
     *  Logic: '<S626>/Logical Operator3'
     */
    ESCLCtl_J436PwrSup = (ESCLCtl_J436Lck || ESCLCtl_J436Unlck);
  }

  /* End of Switch: '<S631>/Switch' */
  /* End of Outputs for SubSystem: '<S626>/Ovrd' */

  /* Truth Table: '<S626>/Truth Table' */
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

  /* End of Truth Table: '<S626>/Truth Table' */

  /* Chart: '<S626>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S626>/Constant7'
   *  Constant: '<S626>/Constant8'
   */
  AppSwcBcm_LIB_TPD_10ms11(rtb_LogicalOperator1_bh1, 5, 0.05F,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_bf,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11_m);

  /* Update for UnitDelay: '<S626>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_n = ESCLCtl_Lck;

  /* Update for UnitDelay: '<S626>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_j =
    AppSwcBcm_ARID_DEF.ESCLCtl_UnlckPwrOff;
}

/* System initialize for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl_Init(void)
{
  sint32 i;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for Chart: '<S434>/IMMOCtl' */
    AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[i] = MAX_uint8_T;

    /* SystemInitialize for SignalConversion generated from: '<S434>/IMMOCtl' */
    IMMOCtl_AuthResp[i] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[i];
  }

  for (i = 0; i < 16; i++) {
    /* SystemInitialize for SignalConversion generated from: '<S434>/IMMOCtl' */
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

  /* SignalConversion: '<S434>/Signal Conversion' incorporates:
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

  /* Chart: '<S434>/IMMOCtl' */
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
    /* SignalConversion generated from: '<S434>/IMMOCtl' */
    IMMOCtl_SKRead[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_l[i_0];
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    /* SignalConversion generated from: '<S434>/IMMOCtl' */
    IMMOCtl_AuthResp[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_i[i_0];
  }

  /* SignalConversion generated from: '<S434>/IMMOCtl' incorporates:
   *  Chart: '<S434>/IMMOCtl'
   */
  IMMOCtl_SKSta = (uint8)(b_k == 16);
}

/*
 * System initialize for atomic system:
 *    '<S677>/LIB_Pulse'
 *    '<S677>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse_Init(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt)
{
  *rty_LIB_blOut = false;
  *rty_LIB_u16PrdSucCnt = 0U;
}

/*
 * System reset for atomic system:
 *    '<S677>/LIB_Pulse'
 *    '<S677>/LIB_Pulse1'
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
 *    '<S677>/LIB_Pulse'
 *    '<S677>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse(uint16 rtu_LIB_u16PrdDemCnt, uint16
  rtu_LIB_u16Prd, uint16 rtu_LIB_u16Wdt, boolean rtu_LIB_blReset, boolean
  *rty_LIB_blOut, uint16 *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S677>/LIB_Pulse' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blReset;

  /* Outputs for Function Call SubSystem: '<S678>/Lib_RiseEdgeDet' */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S678>/Lib_RiseEdgeDet' */

  /* Chart: '<S677>/LIB_Pulse' */
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
 *    '<S677>/Truth Table'
 *    '<S677>/Truth Table1'
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

/* System initialize for atomic system: '<S435>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S641>/Enabled Subsystem' */

  /* SystemInitialize for Chart: '<S677>/LIB_Pulse' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_m,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_d);

  /* SystemInitialize for Chart: '<S677>/LIB_Pulse1' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt);

  /* End of SystemInitialize for SubSystem: '<S641>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<S435>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl(void)
{
  uint16 rtb_BSD_LightPrd;
  uint16 rtb_BSD_LightWdt;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator10_b;
  boolean rtb_RelationalOperator8_o4;
  boolean rtb_RelationalOperator9_b;

  /* Outputs for Enabled SubSystem: '<S641>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S677>/Enable'
   */
  /* Logic: '<S641>/Logical Operator' incorporates:
   *  Constant: '<S641>/Constant13'
   *  RelationalOperator: '<S641>/Relational Operator'
   *  RelationalOperator: '<S641>/Relational Operator2'
   */
  if ((!AppSwcBcm_ARID_DEF.RelationalOperator22) &&
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    if (!AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
      /* SystemReset for Chart: '<S677>/LIB_Pulse' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_m,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_d,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

      /* SystemReset for Chart: '<S677>/LIB_Pulse1' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_c,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);
      AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = true;
    }

    /* RelationalOperator: '<S677>/Relational Operator10' incorporates:
     *  Constant: '<S677>/Constant12'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator1'
     */
    rtb_RelationalOperator10_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 1);

    /* RelationalOperator: '<S677>/Relational Operator8' incorporates:
     *  Constant: '<S677>/Constant3'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator3'
     */
    rtb_RelationalOperator8_o4 =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 1);

    /* RelationalOperator: '<S677>/Relational Operator9' incorporates:
     *  Constant: '<S677>/Constant4'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator4'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 1);

    /* Logic: '<S677>/Logical Operator' */
    rtb_LogicalOperator = (rtb_RelationalOperator10_b ||
      rtb_RelationalOperator8_o4 || rtb_RelationalOperator9_b);

    /* RelationalOperator: '<S677>/Relational Operator9' incorporates:
     *  Constant: '<S677>/Constant1'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator12'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 2);

    /* RelationalOperator: '<S677>/Relational Operator8' incorporates:
     *  Constant: '<S677>/Constant11'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator11'
     */
    rtb_RelationalOperator8_o4 =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 2);

    /* RelationalOperator: '<S677>/Relational Operator10' incorporates:
     *  Constant: '<S677>/Constant10'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator7'
     */
    rtb_RelationalOperator10_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 2);

    /* Truth Table: '<S677>/Truth Table' incorporates:
     *  Logic: '<S677>/Logical Operator2'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_b ||
                         rtb_RelationalOperator8_o4 ||
                         rtb_RelationalOperator10_b, &rtb_BSD_LightWdt,
                         &rtb_BSD_LightPrd);

    /* Chart: '<S677>/LIB_Pulse' incorporates:
     *  Constant: '<S677>/Constant'
     *  Constant: '<S677>/Constant13'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightWdt, rtb_BSD_LightPrd, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_m,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_d,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

    /* SignalConversion generated from: '<S677>/LampCtl_J420BSDRightCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_m;

    /* RelationalOperator: '<S677>/Relational Operator9' incorporates:
     *  Constant: '<S677>/Constant5'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator5'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 1);

    /* RelationalOperator: '<S677>/Relational Operator8' incorporates:
     *  Constant: '<S677>/Constant2'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator2'
     */
    rtb_RelationalOperator8_o4 =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 1);

    /* RelationalOperator: '<S677>/Relational Operator10' incorporates:
     *  Constant: '<S677>/Constant6'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S677>/Relational Operator6'
     */
    rtb_RelationalOperator10_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 1);

    /* Logic: '<S677>/Logical Operator3' */
    rtb_LogicalOperator = (rtb_RelationalOperator9_b ||
      rtb_RelationalOperator8_o4 || rtb_RelationalOperator10_b);

    /* RelationalOperator: '<S677>/Relational Operator9' incorporates:
     *  Constant: '<S677>/Constant8'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator9_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 2);

    /* RelationalOperator: '<S677>/Relational Operator8' incorporates:
     *  Constant: '<S677>/Constant7'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator8_o4 =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 2);

    /* RelationalOperator: '<S677>/Relational Operator10' incorporates:
     *  Constant: '<S677>/Constant9'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator10_b =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 2);

    /* Truth Table: '<S677>/Truth Table1' incorporates:
     *  Logic: '<S677>/Logical Operator1'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_b ||
                         rtb_RelationalOperator8_o4 ||
                         rtb_RelationalOperator10_b, &rtb_BSD_LightPrd,
                         &rtb_BSD_LightWdt);

    /* Chart: '<S677>/LIB_Pulse1' incorporates:
     *  Constant: '<S677>/Constant14'
     *  Constant: '<S677>/Constant15'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightPrd, rtb_BSD_LightWdt, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_c,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);

    /* SignalConversion generated from: '<S677>/LampCtl_J422BSDLeftCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_c;
  } else if (AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
    /* Disable for SignalConversion generated from: '<S677>/LampCtl_J420BSDRightCtl' incorporates:
     *  Outport: '<S677>/LampCtl_J420BSDRightCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl = false;

    /* Disable for SignalConversion generated from: '<S677>/LampCtl_J422BSDLeftCtl' incorporates:
     *  Outport: '<S677>/LampCtl_J422BSDLeftCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl = false;
    AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = false;
  }

  /* End of Logic: '<S641>/Logical Operator' */
  /* End of Outputs for SubSystem: '<S641>/Enabled Subsystem' */
}

/* Function for Chart: '<S642>/AutoHiBeamCtl' */
static void AppSwcBcm_InhbFunc(void)
{
  sint32 tmp;
  if (!LampCtl_PassLightSta) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_au + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_au + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_au = (uint16)tmp;
  } else {
    AppSwcBcm_ARID_DEF.Cnt_au = 0U;
  }
}

/* Output and update for atomic system: '<S435>/AutoHiBeamCtl' */
static void AppSwcBcm_AutoHiBeamCtl(void)
{
  /* Chart: '<S642>/AutoHiBeamCtl' incorporates:
   *  Inport: '<Root>/IPM_FCM_A_CHA'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
    LampCtl_AutoHiBeam = false;
    AppSwcBcm_ARID_DEF.Cnt_au = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib) {
     case AppSwcBcm_IN_Inhb:
      if ((!(Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA())
           ->VIPM_FCMHMASetFb_flg) || (BSW_HMACfg != 2) ||
          (!(Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA())
           ->VIPM_FCMHMAHiBeamReq_flg) || (!LampCtl_LowBeamSta) ||
          (!LampCtl_AutoLampSw) || LampCtl_HiBeamSw) {
        AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
        LampCtl_AutoHiBeam = false;
        AppSwcBcm_ARID_DEF.Cnt_au = 0U;
      } else if (AppSwcBcm_ARID_DEF.Cnt_au >= LampCtl_AutoHiBeamInhbTim_C) {
        AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib = AppSwcBcm_IN_ON_d;
        LampCtl_AutoHiBeam = true;
        AppSwcBcm_ARID_DEF.Cnt_au = 0U;
      } else {
        AppSwcBcm_InhbFunc();
      }
      break;

     case AppSwcBcm_IN_OFF_d:
      if ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA())
          ->VIPM_FCMHMASetFb_flg && (BSW_HMACfg == 2) &&
          (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA())
          ->VIPM_FCMHMAHiBeamReq_flg && LampCtl_LowBeamSta && LampCtl_AutoLampSw
          && (!LampCtl_HiBeamSw)) {
        AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib = AppSwcBcm_IN_ON_d;
        LampCtl_AutoHiBeam = true;
        AppSwcBcm_ARID_DEF.Cnt_au = 0U;
      }
      break;

     default:
      /* case IN_ON: */
      if ((!(Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA())
           ->VIPM_FCMHMASetFb_flg) || (BSW_HMACfg != 2) ||
          (!(Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA())
           ->VIPM_FCMHMAHiBeamReq_flg) || (!LampCtl_LowBeamSta) ||
          (!LampCtl_AutoLampSw) || LampCtl_HiBeamSw) {
        AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib = AppSwcBcm_IN_OFF_d;
        LampCtl_AutoHiBeam = false;
        AppSwcBcm_ARID_DEF.Cnt_au = 0U;
      } else if (LampCtl_PassLightSta) {
        AppSwcBcm_ARID_DEF.is_c3_LampCtl_Lib = AppSwcBcm_IN_Inhb;
        LampCtl_AutoHiBeam = false;
        AppSwcBcm_InhbFunc();
      }
      break;
    }
  }

  /* End of Chart: '<S642>/AutoHiBeamCtl' */
}

/* System initialize for atomic system: '<S435>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S643>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms11_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_p0);

  /* SystemInitialize for Chart: '<S643>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_p);
}

/* Output and update for atomic system: '<S435>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl(void)
{
  /* Chart: '<S643>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S643>/Constant4'
   *  Constant: '<S643>/Constant43'
   *  Constant: '<S643>/Constant45'
   *  RelationalOperator: '<S643>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms11(LampCtl_LightIntstSta == 2,
    LampCtl_AutoLampNightDelayTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_p0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms);

  /* Chart: '<S643>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S643>/Constant5'
   *  Constant: '<S643>/Constant6'
   *  Constant: '<S643>/Constant7'
   *  Constant: '<S643>/Constant8'
   *  Logic: '<S643>/Logical Operator3'
   *  RelationalOperator: '<S643>/Relational Operator5'
   *  UnitDelay: '<S643>/Unit Delay'
   */
  AppSwcBcm_LIB_TPD_10ms((LampCtl_LightIntstSta == 1) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_et, LampCtl_AutoLampDayDelayTim_C, 10,
    LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1);

  /* Switch: '<S689>/Switch' incorporates:
   *  Constant: '<S643>/Constant1'
   *  Logic: '<S643>/Logical Operator'
   *  RelationalOperator: '<S643>/Relational Operator1'
   *  RelationalOperator: '<S643>/Relational Operator2'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || (!LampCtl_AutoLampSw) ||
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_p) {
    /* Switch: '<S689>/Switch' incorporates:
     *  Constant: '<S689>/Constant'
     */
    LampCtl_AutoLampSta = false;
  } else {
    /* Switch: '<S689>/Switch' incorporates:
     *  Constant: '<S643>/Constant'
     *  Logic: '<S643>/Logical Operator1'
     *  Logic: '<S643>/Logical Operator2'
     *  Logic: '<S689>/Logical Operator'
     *  RelationalOperator: '<S643>/Relational Operator'
     *  UnitDelay: '<S689>/Unit Delay'
     */
    LampCtl_AutoLampSta = (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_p0) || LampCtl_AutoLampSta);
  }

  /* End of Switch: '<S689>/Switch' */

  /* Update for UnitDelay: '<S643>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_et = LampCtl_AutoLampSta;
}

/* System initialize for atomic system: '<S435>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S644>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_gs = true;

  /* InitializeConditions for UnitDelay: '<S644>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = 20U;
}

/* Output and update for atomic system: '<S435>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl(void)
{
  uint8 rtb_Switch2_ca;
  boolean rtb_RelationalOperator1_ed;
  boolean rtb_RelationalOperator_cu;

  /* RelationalOperator: '<S644>/Relational Operator' incorporates:
   *  Constant: '<S644>/Constant'
   */
  rtb_RelationalOperator_cu = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

  /* RelationalOperator: '<S644>/Relational Operator1' incorporates:
   *  Constant: '<S644>/Constant14'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_ed = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus
    ())->BackLadjvalFb == 255);

  /* Switch: '<S644>/Switch2' */
  if (rtb_RelationalOperator1_ed) {
    /* Switch: '<S644>/Switch2' incorporates:
     *  Constant: '<S644>/Constant13'
     */
    rtb_Switch2_ca = 0U;
  } else {
    /* Switch: '<S644>/Switch2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch2_ca = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
      ->BackLadjvalFb;
  }

  /* End of Switch: '<S644>/Switch2' */

  /* Delay: '<S644>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_gs) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_g = rtb_Switch2_ca;
  }

  /* Switch: '<S644>/Switch1' */
  if (rtb_RelationalOperator_cu) {
    /* Switch: '<S644>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch2_ca = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_CDCBackLadjval_enum;
  } else {
    /* Switch: '<S644>/Switch1' incorporates:
     *  Constant: '<S644>/Constant12'
     */
    rtb_Switch2_ca = 0U;
  }

  /* End of Switch: '<S644>/Switch1' */

  /* MultiPortSwitch: '<S644>/Multiport Switch' */
  switch (rtb_Switch2_ca) {
   case 1:
    /* MultiPortSwitch: '<S644>/Multiport Switch' incorporates:
     *  Constant: '<S644>/Constant1'
     */
    LampCtl_BackLadjvalFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S644>/Multiport Switch' incorporates:
     *  Constant: '<S644>/Constant2'
     */
    LampCtl_BackLadjvalFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S644>/Multiport Switch' incorporates:
     *  Constant: '<S644>/Constant3'
     */
    LampCtl_BackLadjvalFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S644>/Multiport Switch' incorporates:
     *  Constant: '<S644>/Constant4'
     */
    LampCtl_BackLadjvalFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S644>/Multiport Switch' incorporates:
     *  Constant: '<S644>/Constant5'
     */
    LampCtl_BackLadjvalFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S644>/Multiport Switch' incorporates:
     *  Delay: '<S644>/Delay'
     */
    LampCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_g;
    break;
  }

  /* End of MultiPortSwitch: '<S644>/Multiport Switch' */

  /* MultiPortSwitch: '<S644>/Multiport Switch1' */
  switch (LampCtl_BackLadjvalFb) {
   case 0:
    /* MultiPortSwitch: '<S644>/Multiport Switch1' incorporates:
     *  Constant: '<S644>/Constant6'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = 20U;
    break;

   case 1:
    /* MultiPortSwitch: '<S644>/Multiport Switch1' incorporates:
     *  Constant: '<S644>/Constant7'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = 40U;
    break;

   case 2:
    /* MultiPortSwitch: '<S644>/Multiport Switch1' incorporates:
     *  Constant: '<S644>/Constant8'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S644>/Multiport Switch1' incorporates:
     *  Constant: '<S644>/Constant9'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = 80U;
    break;

   case 4:
    /* MultiPortSwitch: '<S644>/Multiport Switch1' incorporates:
     *  Constant: '<S644>/Constant10'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = 100U;
    break;
  }

  /* End of MultiPortSwitch: '<S644>/Multiport Switch1' */

  /* Switch: '<S644>/Switch' incorporates:
   *  Logic: '<S644>/Logical Operator'
   *  Logic: '<S644>/Logical Operator1'
   */
  if (rtb_RelationalOperator_cu && (LampCtl_PosLampSta || LampCtl_LowBeamSta)) {
    /* Switch: '<S644>/Switch' */
    AppSwcBcm_ARID_DEF.Switch_b = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l;
  } else {
    /* Switch: '<S644>/Switch' incorporates:
     *  Constant: '<S644>/Constant11'
     */
    AppSwcBcm_ARID_DEF.Switch_b = 0U;
  }

  /* End of Switch: '<S644>/Switch' */

  /* Update for Delay: '<S644>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_gs = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_g = LampCtl_BackLadjvalFb;
}

/* System initialize for atomic system: '<S435>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_gn;

  /* SystemInitialize for Atomic SubSystem: '<S645>/Trunk10min' */

  /* SystemInitialize for Chart: '<S693>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_gn);

  /* End of SystemInitialize for SubSystem: '<S645>/Trunk10min' */
}

/* Output and update for atomic system: '<S435>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_gn;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_o;
  boolean rtb_Switch;

  /* Switch: '<S645>/Switch' incorporates:
   *  Constant: '<S645>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S645>/Relational Operator2'
   */
  rtb_Switch = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                ->VIPM_HUBCMCargoLghtSet_enum == 2);

  /* Outputs for Atomic SubSystem: '<S645>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_e(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_LogicalOperator, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_n);

  /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S645>/Lib_FailEdgeDet1' */
  AppSwcBcm_Lib_FailEdgeDet_e(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_LogicalOperator_o, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o);

  /* End of Outputs for SubSystem: '<S645>/Lib_FailEdgeDet1' */

  /* Logic: '<S645>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator_o);

  /* Outputs for Atomic SubSystem: '<S645>/Trunk10min' */

  /* Chart: '<S693>/LIB_PosPluse2' incorporates:
   *  Constant: '<S645>/Constant4'
   *  UnitDelay: '<S645>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bj,
    LampCtl_BoxLampOpenTimMax_C, rtb_LogicalOperator, &rtb_LIB_blOut_gn,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2);

  /* End of Outputs for SubSystem: '<S645>/Trunk10min' */

  /* Outputs for Atomic SubSystem: '<S645>/Lib_SR' */

  /* Logic: '<S645>/Logical Operator1' */
  AppSwcBcm_Lib_SR(rtb_LogicalOperator, rtb_LIB_blOut_gn ||
                   AppSwcBcm_ARID_DEF.BusCreator4.InsLck ||
                   AppSwcBcm_ARID_DEF.BusCreator4.OsLck, &rtb_LogicalOperator_o,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR);

  /* End of Outputs for SubSystem: '<S645>/Lib_SR' */

  /* Logic: '<S645>/Logical Operator3' incorporates:
   *  Constant: '<S645>/Constant'
   *  Constant: '<S645>/Constant1'
   *  Logic: '<S645>/Logical Operator2'
   *  Logic: '<S645>/Logical Operator4'
   *  Logic: '<S645>/Logical Operator5'
   *  RelationalOperator: '<S645>/Relational Operator'
   *  RelationalOperator: '<S645>/Relational Operator1'
   *  RelationalOperator: '<S645>/Relational Operator5'
   *  Switch: '<S645>/Switch'
   *  UnitDelay: '<S645>/Unit Delay'
   *  UnitDelay: '<S645>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bj =
    ((((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
       (((LampCtl_LightIntstSta == 2) && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l)
        || rtb_Switch)) || rtb_LogicalOperator_o) &&
     (!AppSwcBcm_ARID_DEF.RelationalOperator22));

  /* Update for UnitDelay: '<S645>/Unit Delay1' incorporates:
   *  UnitDelay: '<S645>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l =
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bj;
}

/* Output and update for atomic system: '<S435>/BrakeLampCtl' */
static void AppSwcBcm_BrakeLampCtl(void)
{
  boolean rtb_RelationalOperator2_d1;
  boolean rtb_RelationalOperator8_o4;
  boolean rtb_RelationalOperator_bv;

  /* RelationalOperator: '<S646>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_bv =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VVTM_RegenReqBrkLampOn_flg;

  /* RelationalOperator: '<S646>/Relational Operator8' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S646>/Relational Operator3'
   */
  rtb_RelationalOperator8_o4 =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLA_flg;

  /* RelationalOperator: '<S646>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S646>/Relational Operator6'
   */
  rtb_RelationalOperator2_d1 =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLAVld_flg;

  /* Logic: '<S646>/Logical Operator6' incorporates:
   *  Constant: '<S646>/Constant2'
   *  Logic: '<S646>/Logical Operator'
   *  Logic: '<S646>/Logical Operator1'
   *  Logic: '<S646>/Logical Operator3'
   *  Logic: '<S646>/Logical Operator4'
   *  Logic: '<S646>/Logical Operator5'
   *  RelationalOperator: '<S646>/Relational Operator1'
   *  RelationalOperator: '<S646>/Relational Operator2'
   *  RelationalOperator: '<S646>/Relational Operator7'
   *  RelationalOperator: '<S646>/Relational Operator8'
   *  RelationalOperator: '<S646>/Relational Operator9'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator6 =
    ((!AppSwcBcm_ARID_DEF.RelationalOperator22) && (LampCtl_BrakeLightSw ||
      ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
       (rtb_RelationalOperator_bv || (rtb_RelationalOperator8_o4 &&
         rtb_RelationalOperator2_d1) ||
        (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCReqBrkLghtOn_flg &&
         AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCReqBrkLghtOnVld_flg)))));

  /* CCaller: '<S646>/C Caller' incorporates:
   *  Constant: '<S646>/Constant12'
   *  Constant: '<S646>/Constant13'
   */
  BSW_BrkLampDigSts = Get_Diag7x_CV(0U, 0U);

  /* Chart: '<S646>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S646>/Constant11'
   *  Constant: '<S646>/Constant14'
   *  Constant: '<S646>/Constant28'
   *  Constant: '<S646>/Constant29'
   *  Constant: '<S646>/Constant30'
   *  Logic: '<S646>/Logical Operator7'
   *  RelationalOperator: '<S646>/Relational Operator10'
   *  RelationalOperator: '<S646>/Relational Operator11'
   */
  if ((BSW_BrkLampDigSts == 3) || (BSW_BrkLampDigSts == 2)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d1 >= (float32)
         LampCtl_BrkLampShortToBatOrOpenTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_BrkLampShortToBatOrOpenTimValid_C != 0xFFFF)) {
      LampCtl_BrkLampShortToBatOrOpen = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d1++;
      AppSwcBcm_ARID_DEF.cnt_heal_lv = (uint16)((float32)
        LampCtl_BrkLampShortToBatOrOpenTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lv == 0) {
      LampCtl_BrkLampShortToBatOrOpen = false;
    } else if (LampCtl_BrkLampShortToBatOrOpenTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_lv--;
    }
  }

  /* End of Chart: '<S646>/LIB_TPD_10ms3' */

  /* Chart: '<S646>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S646>/Constant15'
   *  Constant: '<S646>/Constant16'
   *  Constant: '<S646>/Constant17'
   *  Constant: '<S646>/Constant18'
   *  RelationalOperator: '<S646>/Relational Operator12'
   */
  if (BSW_BrkLampDigSts == 1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_db >= (float32)
         LampCtl_BrkLampShortToGndTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_BrkLampShortToGndTimValid_C != 0xFFFF)) {
      LampCtl_BrkLampShortToGnd = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_db++;
      AppSwcBcm_ARID_DEF.cnt_heal_h1 = (uint16)((float32)
        LampCtl_BrkLampShortToGndTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_db = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h1 == 0) {
      LampCtl_BrkLampShortToGnd = false;
    } else if (LampCtl_BrkLampShortToGndTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_h1--;
    }
  }

  /* End of Chart: '<S646>/LIB_TPD_10ms1' */
}

/* Output and update for atomic system: '<S435>/DayRunLampCtl' */
static void AppSwcBcm_DayRunLampCtl(void)
{
  boolean rtb_RelationalOperator1_ex;
  boolean rtb_RelationalOperator8_d;

  /* RelationalOperator: '<S647>/Relational Operator8' incorporates:
   *  Constant: '<S647>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator8_d =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Outputs for Atomic SubSystem: '<S647>/Lib_SR' */
  /* Switch: '<S699>/Switch' incorporates:
   *  Constant: '<S647>/Constant'
   *  Constant: '<S647>/Constant6'
   *  Constant: '<S699>/Constant'
   *  Logic: '<S647>/Logical Operator'
   *  Logic: '<S647>/Logical Operator1'
   *  Logic: '<S699>/Logical Operator'
   *  RelationalOperator: '<S647>/Relational Operator'
   *  RelationalOperator: '<S647>/Relational Operator6'
   *  RelationalOperator: '<S647>/Relational Operator7'
   *  UnitDelay: '<S699>/Unit Delay'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || LampCtl_PosLampSta ||
      rtb_RelationalOperator8_d) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ng = false;
  } else {
    /* RelationalOperator: '<S647>/Relational Operator2' incorporates:
     *  Constant: '<S647>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator8_d =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
       ->VGSM_VehActGearPstn_enum != 0);

    /* RelationalOperator: '<S647>/Relational Operator1' incorporates:
     *  Constant: '<S647>/Constant1'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator1_ex =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
       ->VHVM_PTActOprtMode_enum == 2);
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ng =
      (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
        rtb_RelationalOperator1_ex && rtb_RelationalOperator8_d) ||
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ng);
  }

  /* End of Switch: '<S699>/Switch' */
  /* End of Outputs for SubSystem: '<S647>/Lib_SR' */
}

/*
 * Output and update for atomic system:
 *    '<S701>/Lib_FailEdgeDetHold'
 *    '<S701>/Lib_FailEdgeDetHold1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDetHold(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDetHold_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Switch: '<S714>/Switch' incorporates:
   *  Constant: '<S714>/Constant'
   *  Logic: '<S714>/Logical Operator2'
   *  UnitDelay: '<S714>/Unit Delay'
   *  UnitDelay: '<S714>/Unit Delay1'
   */
  if (rtu_Lib_blIn) {
    rty_Lib_blOut_0 = false;
  } else {
    rty_Lib_blOut_0 = (AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE ||
                       AppSwcBcm__ARID_DEF_arg->UnitDelay1_DSTATE);
  }

  /* End of Switch: '<S714>/Switch' */

  /* Update for UnitDelay: '<S714>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* Update for UnitDelay: '<S714>/Unit Delay1' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay1_DSTATE = rty_Lib_blOut_0;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S435>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S719>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_l = true;

  /* InitializeConditions for Delay: '<S720>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_lh = true;

  /* InitializeConditions for Delay: '<S721>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_om = true;

  /* SystemInitialize for Chart: '<S700>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_is);

  /* SystemInitialize for Chart: '<S700>/LIB_TPD_Ts1' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_m);

  /* SystemInitialize for Atomic SubSystem: '<S702>/Lib_RateLimit' */
  /* InitializeConditions for Delay: '<S718>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_h = true;

  /* End of SystemInitialize for SubSystem: '<S702>/Lib_RateLimit' */

  /* SystemInitialize for Truth Table: '<S648>/Truth Table' */
  LampCtl_DomeLampOff = true;
}

/* Output and update for atomic system: '<S435>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl(void)
{
  sint32 rtb_Switch_p;
  float32 rtb_Add;
  float32 rtb_Product;
  boolean rtb_Switch;
  boolean rtb_Switch_kb;
  boolean tmp;
  boolean tmp_0;

  /* Chart: '<S700>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S700>/Constant3'
   *  Constant: '<S700>/Constant4'
   *  Constant: '<S700>/Constant5'
   *  RelationalOperator: '<S700>/Relational Operator1'
   */
  AppSwcBcm_LIB_TPD_10ms(!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    LampCtl_DoorOpenFLValidTim_C, LampCtl_DoorOpenFLInValidTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_is,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts_i);

  /* Outputs for Atomic SubSystem: '<S700>/FL10min' */
  /* Chart: '<S706>/LIB_Tim' incorporates:
   *  Constant: '<S706>/Constant'
   *  Logic: '<S700>/Logical Operator1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && AppSwcBcm_ARID_DEF.LIB_bErrFlg_is)
  {
    if (AppSwcBcm_ARID_DEF.Cnt_ko <= 12000) {
      AppSwcBcm_ARID_DEF.Cnt_ko++;
      LampCtl_DomeLampFLOpen = true;
    } else {
      LampCtl_DomeLampFLOpen = false;
    }
  } else {
    LampCtl_DomeLampFLOpen = false;
    AppSwcBcm_ARID_DEF.Cnt_ko = 0U;
  }

  /* End of Chart: '<S706>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S700>/FL10min' */

  /* Chart: '<S700>/LIB_TPD_Ts1' incorporates:
   *  Constant: '<S700>/Constant6'
   *  Constant: '<S700>/Constant7'
   *  Constant: '<S700>/Constant8'
   *  RelationalOperator: '<S700>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD_10ms(!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    LampCtl_DoorOpenFRValidTim_C, LampCtl_DoorOpenFRInValidTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_m, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts1);

  /* Outputs for Atomic SubSystem: '<S700>/FR10min' */
  /* Chart: '<S707>/LIB_Tim' incorporates:
   *  Constant: '<S707>/Constant'
   *  Logic: '<S700>/Logical Operator2'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && AppSwcBcm_ARID_DEF.LIB_bErrFlg_m) {
    if (AppSwcBcm_ARID_DEF.Cnt_j <= 12000) {
      AppSwcBcm_ARID_DEF.Cnt_j++;
      LampCtl_DomeLampFROpen = true;
    } else {
      LampCtl_DomeLampFROpen = false;
    }
  } else {
    LampCtl_DomeLampFROpen = false;
    AppSwcBcm_ARID_DEF.Cnt_j = 0U;
  }

  /* End of Chart: '<S707>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S700>/FR10min' */

  /* Outputs for Atomic SubSystem: '<S701>/Lib_FailEdgeDetHold' */
  /* RelationalOperator: '<S701>/Relational Operator3' incorporates:
   *  Constant: '<S701>/Constant3'
   */
  rtb_Switch = AppSwcBcm_Lib_FailEdgeDetHold
    (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDetHold);

  /* End of Outputs for SubSystem: '<S701>/Lib_FailEdgeDetHold' */

  /* Outputs for Atomic SubSystem: '<S701>/30s' */
  /* Chart: '<S712>/LIB_Tim' incorporates:
   *  Constant: '<S712>/Constant'
   *  Logic: '<S701>/Logical Operator4'
   *  Logic: '<S701>/Logical Operator5'
   *  RelationalOperator: '<S701>/Relational Operator2'
   *  RelationalOperator: '<S701>/Relational Operator5'
   *  RelationalOperator: '<S701>/Relational Operator6'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw && rtb_Switch &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw) &&
      AppSwcBcm_ConstB.RelationalOperator1) {
    if (AppSwcBcm_ARID_DEF.Cnt_k <= 600) {
      AppSwcBcm_ARID_DEF.Cnt_k++;
      LampCtl_DomeLampPwrOff = true;
    } else {
      LampCtl_DomeLampPwrOff = false;
    }
  } else {
    LampCtl_DomeLampPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_k = 0U;
  }

  /* End of Chart: '<S712>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S701>/30s' */

  /* Outputs for Atomic SubSystem: '<S701>/Lib_FailEdgeDetHold1' */
  rtb_Switch_kb = AppSwcBcm_Lib_FailEdgeDetHold
    (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDetHold1);

  /* End of Outputs for SubSystem: '<S701>/Lib_FailEdgeDetHold1' */

  /* Outputs for Atomic SubSystem: '<S701>/30s1' */
  /* Chart: '<S713>/LIB_Tim' incorporates:
   *  Constant: '<S701>/Constant4'
   *  Constant: '<S713>/Constant'
   *  Logic: '<S701>/Logical Operator1'
   *  RelationalOperator: '<S701>/Relational Operator4'
   */
  if (AppSwcBcm_ConstB.RelationalOperator1 && rtb_Switch_kb &&
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0)) {
    if (AppSwcBcm_ARID_DEF.Cnt_o <= 600) {
      AppSwcBcm_ARID_DEF.Cnt_o++;
      LampCtl_DomeLampUnlock = true;
    } else {
      LampCtl_DomeLampUnlock = false;
    }
  } else {
    LampCtl_DomeLampUnlock = false;
    AppSwcBcm_ARID_DEF.Cnt_o = 0U;
  }

  /* End of Chart: '<S713>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S701>/30s1' */

  /* Delay: '<S719>/Delay' incorporates:
   *  RelationalOperator: '<S703>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_l) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_n =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Logic: '<S719>/Logical Operator' incorporates:
   *  Delay: '<S719>/Delay'
   *  Logic: '<S719>/Logical Operator1'
   *  RelationalOperator: '<S703>/Relational Operator4'
   */
  LampCtl_DomeLampLockDoor = (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_n));

  /* Delay: '<S720>/Delay' incorporates:
   *  RelationalOperator: '<S703>/Relational Operator8'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_lh) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_bg =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S721>/Delay' incorporates:
   *  RelationalOperator: '<S703>/Relational Operator9'
   */
  if (AppSwcBcm_ARID_DEF.icLoad_om) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_d =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Logic: '<S703>/Logical Operator6' incorporates:
   *  Constant: '<S703>/Constant7'
   *  Delay: '<S720>/Delay'
   *  Delay: '<S721>/Delay'
   *  Logic: '<S720>/Logical Operator'
   *  Logic: '<S720>/Logical Operator1'
   *  Logic: '<S721>/Logical Operator'
   *  Logic: '<S721>/Logical Operator1'
   *  RelationalOperator: '<S703>/Relational Operator7'
   *  RelationalOperator: '<S703>/Relational Operator8'
   *  RelationalOperator: '<S703>/Relational Operator9'
   */
  LampCtl_DomeLampCloseDoor = ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_bg)) &&
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_d)));

  /* Truth Table: '<S648>/Truth Table' */
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

    /* Outputs for Atomic SubSystem: '<S648>/Lib_SR' */
    /* Switch: '<S704>/Switch' incorporates:
     *  Logic: '<S704>/Logical Operator'
     *  UnitDelay: '<S704>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S648>/Lib_SR' */
  } else if (LampCtl_DomeLampFROpen && tmp && tmp_0) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S648>/Lib_SR' */
    /* Switch: '<S704>/Switch' incorporates:
     *  Logic: '<S704>/Logical Operator'
     *  UnitDelay: '<S704>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S648>/Lib_SR' */
  } else if (LampCtl_DomeLampPwrOff && tmp && tmp_0) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S648>/Lib_SR' */
    /* Switch: '<S704>/Switch' incorporates:
     *  Logic: '<S704>/Logical Operator'
     *  UnitDelay: '<S704>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S648>/Lib_SR' */
  } else if (LampCtl_DomeLampUnlock && tmp && tmp_0) {
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = true;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S648>/Lib_SR' */
    /* Switch: '<S704>/Switch' incorporates:
     *  Logic: '<S704>/Logical Operator'
     *  UnitDelay: '<S704>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S648>/Lib_SR' */
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

    /* Outputs for Atomic SubSystem: '<S648>/Lib_SR' */
    /* Switch: '<S704>/Switch' incorporates:
     *  Constant: '<S704>/Constant'
     */
    LampCtl_DomeLampCtl = false;

    /* End of Outputs for SubSystem: '<S648>/Lib_SR' */
  }

  /* End of Truth Table: '<S648>/Truth Table' */

  /* Switch: '<S702>/Switch' */
  if (LampCtl_DomeLampCtl) {
    /* Switch: '<S702>/Switch' incorporates:
     *  Constant: '<S702>/Constant'
     */
    rtb_Switch_p = 100;
  } else {
    /* Switch: '<S702>/Switch' incorporates:
     *  Constant: '<S702>/Constant1'
     */
    rtb_Switch_p = 0;
  }

  /* End of Switch: '<S702>/Switch' */

  /* Outputs for Atomic SubSystem: '<S702>/Lib_RateLimit' */
  /* Delay: '<S718>/Variable Integer Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_h) {
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)rtb_Switch_p;
  }

  /* Product: '<S718>/Product' incorporates:
   *  Constant: '<S702>/Constant2'
   *  Constant: '<S702>/Constant21'
   */
  rtb_Product = 66.7F * LampCtl_Ts_C;

  /* Sum: '<S718>/Add' incorporates:
   *  Delay: '<S718>/Variable Integer Delay'
   */
  rtb_Add = (float32)rtb_Switch_p -
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;

  /* Switch: '<S718>/Switch' incorporates:
   *  RelationalOperator: '<S718>/Relational Operator'
   */
  if (rtb_Add > rtb_Product) {
    /* Switch: '<S718>/Switch' incorporates:
     *  Delay: '<S718>/Variable Integer Delay'
     *  Sum: '<S718>/Add1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += rtb_Product;
  } else {
    /* Product: '<S718>/Product1' incorporates:
     *  Constant: '<S702>/Constant21'
     *  Constant: '<S702>/Constant3'
     */
    rtb_Product = LampCtl_Ts_C * -66.7F;

    /* Switch: '<S718>/Switch1' incorporates:
     *  RelationalOperator: '<S718>/Relational Operator1'
     */
    if (rtb_Add < rtb_Product) {
      /* Switch: '<S718>/Switch' incorporates:
       *  Delay: '<S718>/Variable Integer Delay'
       *  Sum: '<S718>/Add2'
       *  Switch: '<S718>/Switch1'
       */
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += rtb_Product;
    } else {
      /* Switch: '<S718>/Switch' incorporates:
       *  Switch: '<S718>/Switch1'
       */
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)rtb_Switch_p;
    }

    /* End of Switch: '<S718>/Switch1' */
  }

  /* End of Switch: '<S718>/Switch' */

  /* Update for Delay: '<S718>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_h = false;

  /* End of Outputs for SubSystem: '<S702>/Lib_RateLimit' */

  /* Switch: '<S648>/Switch' incorporates:
   *  RelationalOperator: '<S648>/Relational Operator5'
   */
  if (!AppSwcBcm_ARID_DEF.RelationalOperator22) {
    /* Switch: '<S702>/Switch1' incorporates:
     *  Switch: '<S702>/Switch2'
     */
    if (LampCtl_DomeLampOffGrad) {
      /* Switch: '<S648>/Switch' incorporates:
       *  DataTypeConversion: '<S702>/Data Type Conversion'
       */
      AppSwcBcm_ARID_DEF.Switch = (uint8)
        AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
    } else if (LampCtl_DomeLampOnGrad) {
      /* Switch: '<S702>/Switch2' incorporates:
       *  DataTypeConversion: '<S702>/Data Type Conversion'
       *  Switch: '<S648>/Switch'
       */
      AppSwcBcm_ARID_DEF.Switch = (uint8)
        AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
    } else {
      /* Switch: '<S648>/Switch' incorporates:
       *  DataTypeConversion: '<S702>/Data Type Conversion'
       *  Switch: '<S702>/Switch1'
       *  Switch: '<S702>/Switch2'
       */
      AppSwcBcm_ARID_DEF.Switch = (uint8)(float32)rtb_Switch_p;
    }

    /* End of Switch: '<S702>/Switch1' */
  } else {
    /* Switch: '<S648>/Switch' incorporates:
     *  Constant: '<S648>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Switch = 0U;
  }

  /* End of Switch: '<S648>/Switch' */

  /* Update for Delay: '<S719>/Delay' incorporates:
   *  RelationalOperator: '<S703>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.icLoad_l = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_n =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S720>/Delay' incorporates:
   *  RelationalOperator: '<S703>/Relational Operator8'
   */
  AppSwcBcm_ARID_DEF.icLoad_lh = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_bg =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S721>/Delay' incorporates:
   *  RelationalOperator: '<S703>/Relational Operator9'
   */
  AppSwcBcm_ARID_DEF.icLoad_om = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_d =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
}

/* Output and update for atomic system: '<S435>/FogLampRCtl' */
static void AppSwcBcm_FogLampRCtl(void)
{
  boolean guard1 = false;
  boolean rtb_RelationalOperator5_ew;

  /* Chart: '<S649>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c83_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c83_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_e = false;
  } else if (AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib == AppSwcBcm_IN_Off_i) {
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && LampCtl_PosLampSta &&
        (BSW_FogLampFCfg == 1)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_oh = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S723>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_oh,
        &AppSwcBcm_ARID_DEF.LogicalOperator_j1,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);

      /* End of Outputs for SubSystem: '<S723>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_j1) {
        AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_On_p;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_e = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || (!LampCtl_PosLampSta))
    {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_oh = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S723>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_oh,
        &AppSwcBcm_ARID_DEF.LogicalOperator_j1,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);

      /* End of Outputs for SubSystem: '<S723>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_j1) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c83_LampCtl_Lib = AppSwcBcm_IN_Off_i;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_e = false;
    }
  }

  /* End of Chart: '<S649>/Chart1' */

  /* Chart: '<S649>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib == AppSwcBcm_IN_Off_i) {
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && LampCtl_PosLampSta &&
        ((LampCtl_LowBeamSta && (BSW_FogLampFCfg != 1)) || ((BSW_FogLampFCfg ==
           1) && (LampCtl_LowBeamSta || AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_e))))
    {
      AppSwcBcm_ARID_DEF.Lib_blIn_c = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S722>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_c,
        &AppSwcBcm_ARID_DEF.LogicalOperator_kl,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ny);

      /* End of Outputs for SubSystem: '<S722>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_kl) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_On_p;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) || (!LampCtl_PosLampSta))
    {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_c = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S722>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_c,
        &AppSwcBcm_ARID_DEF.LogicalOperator_kl,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ny);

      /* End of Outputs for SubSystem: '<S722>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_kl) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_Off_i;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e = false;
    }
  }

  /* End of Chart: '<S649>/Chart' */

  /* RelationalOperator: '<S649>/Relational Operator5' */
  rtb_RelationalOperator5_ew = !AppSwcBcm_ARID_DEF.RelationalOperator22;

  /* Logic: '<S649>/Logical Operator' */
  AppSwcBcm_ARID_DEF.LogicalOperator_b = (rtb_RelationalOperator5_ew &&
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e);

  /* Logic: '<S649>/Logical Operator1' */
  AppSwcBcm_ARID_DEF.LogicalOperator1_i = (rtb_RelationalOperator5_ew &&
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_e);
}

/* Output and update for atomic system: '<S435>/HiBeamCtl' */
static void AppSwcBcm_HiBeamCtl(void)
{
  /* Logic: '<S650>/Logical Operator' incorporates:
   *  Logic: '<S650>/Logical Operator1'
   *  RelationalOperator: '<S650>/Relational Operator'
   *  RelationalOperator: '<S650>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_lw = (LampCtl_LowBeamSta &&
    (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && (LampCtl_HiBeamSw ||
    LampCtl_AutoHiBeam || LampCtl_PassLightSta));

  /* CCaller: '<S650>/C Caller1' */
  BSW_HiBeamDigSts = GetHw_HiBeamDigSts();

  /* Chart: '<S650>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S650>/Constant28'
   *  Constant: '<S650>/Constant29'
   *  Constant: '<S650>/Constant30'
   *  RelationalOperator: '<S650>/Relational Operator4'
   */
  if (BSW_HiBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_k >= (float32)
         LampCtl_HiBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HiBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k++;
      AppSwcBcm_ARID_DEF.cnt_heal_c3 = (uint16)((float32)
        LampCtl_HiBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c3 == 0) {
      LampCtl_HiBeamShortToBat = false;
    } else if (LampCtl_HiBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_c3--;
    }
  }

  /* End of Chart: '<S650>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S435>/KnobBeamDig' */
static void AppSwcBcm_KnobBeamDig(void)
{
  /* Chart: '<S651>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S651>/Constant'
   *  Constant: '<S651>/Constant21'
   *  Constant: '<S651>/Constant3'
   *  Constant: '<S651>/Constant4'
   *  Logic: '<S651>/Logical Operator'
   *  Logic: '<S651>/Logical Operator1'
   *  RelationalOperator: '<S651>/Relational Operator'
   *  RelationalOperator: '<S651>/Relational Operator1'
   *  RelationalOperator: '<S651>/Relational Operator2'
   */
  if (((!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwStVld_flg)
       || (!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwStVld_flg))
      && (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_lc >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_KnobBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lc++;
      AppSwcBcm_ARID_DEF.cnt_heal_lt = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lc = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lt == 0) {
      LampCtl_KnobBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_lt--;
    }
  }

  /* End of Chart: '<S651>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S435>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_f;

  /* SystemInitialize for Chart: '<S652>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_f);
}

/* Output and update for atomic system: '<S435>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_f;
  boolean rtb_RelationalOperator_hg;

  /* RelationalOperator: '<S652>/Relational Operator' incorporates:
   *  Constant: '<S652>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_hg = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
    ->BodyWarnSts == 1);

  /* Chart: '<S652>/LIB_Tim' incorporates:
   *  Constant: '<S652>/Constant6'
   *  UnitDelay: '<S652>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ij,
    LampCtl_LampDelayTim_C, &rtb_LIB_blOut_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_j);

  /* Outputs for Atomic SubSystem: '<S652>/Lib_SR' */
  /* Switch: '<S732>/Switch' incorporates:
   *  Constant: '<S652>/Constant1'
   *  Logic: '<S652>/Logical Operator1'
   *  RelationalOperator: '<S652>/Relational Operator1'
   *  RelationalOperator: '<S652>/Relational Operator4'
   */
  if (rtb_RelationalOperator_hg || (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode ==
       2) || (!LampCtl_AutoLampSw) || rtb_LIB_blOut_f) {
    /* Switch: '<S732>/Switch' incorporates:
     *  Constant: '<S732>/Constant'
     */
    LampCtl_LampDelay = false;
  } else {
    /* Switch: '<S732>/Switch' incorporates:
     *  Constant: '<S652>/Constant3'
     *  Constant: '<S652>/Constant4'
     *  Constant: '<S652>/Constant5'
     *  Logic: '<S652>/Logical Operator'
     *  Logic: '<S731>/Logical Operator'
     *  Logic: '<S732>/Logical Operator'
     *  RelationalOperator: '<S652>/Relational Operator3'
     *  RelationalOperator: '<S731>/Relational Operator'
     *  RelationalOperator: '<S731>/Relational Operator1'
     *  UnitDelay: '<S731>/Unit Delay'
     *  UnitDelay: '<S732>/Unit Delay'
     */
    LampCtl_LampDelay = (((LampCtl_LightIntstSta == 2) &&
                          ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f == 2))) || LampCtl_LampDelay);
  }

  /* End of Switch: '<S732>/Switch' */
  /* End of Outputs for SubSystem: '<S652>/Lib_SR' */

  /* Update for UnitDelay: '<S652>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ij = LampCtl_LampDelay;

  /* Update for UnitDelay: '<S731>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode;
}

/* Output and update for atomic system: '<S435>/LightIntstDet' */
static void AppSwcBcm_LightIntstDet(void)
{
  /* Chart: '<S653>/Chart' */
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

  /* End of Chart: '<S653>/Chart' */
}

/* System initialize for atomic system: '<S435>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S654>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_c);
}

/* Output and update for atomic system: '<S435>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl(void)
{
  /* Chart: '<S654>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S654>/Constant'
   *  Constant: '<S654>/Constant13'
   *  Constant: '<S654>/Constant4'
   *  Constant: '<S654>/Constant5'
   *  Logic: '<S654>/Logical Operator'
   *  Logic: '<S654>/Logical Operator1'
   *  Logic: '<S654>/Logical Operator2'
   *  Logic: '<S654>/Logical Operator3'
   *  RelationalOperator: '<S654>/Relational Operator'
   *  RelationalOperator: '<S654>/Relational Operator1'
   *  RelationalOperator: '<S654>/Relational Operator2'
   *  RelationalOperator: '<S654>/Relational Operator3'
   *  RelationalOperator: '<S654>/Relational Operator5'
   *  UnitDelay: '<S435>/Unit Delay'
   *  UnitDelay: '<S435>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms((!AppSwcBcm_ARID_DEF.RelationalOperator22) &&
    (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && (LampCtl_LowBeamSw ||
    LampCtl_PassLightSta || LampCtl_AutoLampSta || LampCtl_KnobBeamFaultSta)) ||
     AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fu ||
     AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b || LampCtl_LampDelay),
    LampCtl_LowBeamStaTimValid_C, LampCtl_LowBeamStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_j);

  /* CCaller: '<S654>/C Caller' */
  BSW_LowBeamDigSts = GetHw_LoBeamDigSts();

  /* Chart: '<S654>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S654>/Constant28'
   *  Constant: '<S654>/Constant29'
   *  Constant: '<S654>/Constant30'
   *  RelationalOperator: '<S654>/Relational Operator4'
   */
  if (BSW_LowBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_pb >= (float32)
         LampCtl_LowBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_LowBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_pb++;
      AppSwcBcm_ARID_DEF.cnt_heal_mw = (uint16)((float32)
        LampCtl_LowBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_pb = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mw == 0) {
      LampCtl_LowBeamShortToBat = false;
    } else if (LampCtl_LowBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mw--;
    }
  }

  /* End of Chart: '<S654>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S435>/OTAPwrOffLight' */
static void AppSwcBcm_OTAPwrOffLight(void)
{
  /* Logic: '<S655>/Logical Operator' incorporates:
   *  Constant: '<S655>/Constant'
   *  Constant: '<S655>/Constant1'
   *  Logic: '<S655>/Logical Operator1'
   *  RelationalOperator: '<S655>/Relational Operator'
   *  RelationalOperator: '<S655>/Relational Operator1'
   *  RelationalOperator: '<S655>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator22 =
    (((AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 5) ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 3)) &&
     (!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw));
}

/* Output and update for atomic system: '<S435>/ReverseLampCtl' */
static void AppSwcBcm_ReverseLampCtl(void)
{
  boolean rtb_RelationalOperator1_ot;

  /* RelationalOperator: '<S673>/Relational Operator1' incorporates:
   *  Constant: '<S673>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_ot =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 3);

  /* Logic: '<S673>/Logical Operator' incorporates:
   *  Constant: '<S673>/Constant'
   *  RelationalOperator: '<S673>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_poq =
    ((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) &&
     rtb_RelationalOperator1_ot);
}

/* Output and update for atomic system: '<S435>/PassLampFunc' */
static void AppSwcBcm_PassLampFunc(void)
{
  sint32 tmp;

  /* Chart: '<S671>/LIB_Tim' incorporates:
   *  Constant: '<S671>/Constant1'
   *  RelationalOperator: '<S671>/Relational Operator'
   */
  if (LampCtl_PassLightSw) {
    if (AppSwcBcm_ARID_DEF.Cnt_n <= LampCtl_PassLightMaxTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_n + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_n + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_n = (uint16)tmp;
      LampCtl_PassLightSta = true;
    } else {
      LampCtl_PassLightSta = false;
    }
  } else {
    LampCtl_PassLightSta = false;
    AppSwcBcm_ARID_DEF.Cnt_n = 0U;
  }

  /* End of Chart: '<S671>/LIB_Tim' */
}

/* System initialize for atomic system: '<S435>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S672>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_j);
}

/* Output and update for atomic system: '<S435>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl(void)
{
  /* Chart: '<S672>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S672>/Constant'
   *  Constant: '<S672>/Constant13'
   *  Constant: '<S672>/Constant2'
   *  Constant: '<S672>/Constant4'
   *  Logic: '<S672>/Logical Operator'
   *  Logic: '<S672>/Logical Operator1'
   *  Logic: '<S672>/Logical Operator2'
   *  Logic: '<S672>/Logical Operator3'
   *  RelationalOperator: '<S672>/Relational Operator'
   *  RelationalOperator: '<S672>/Relational Operator1'
   *  RelationalOperator: '<S672>/Relational Operator2'
   *  RelationalOperator: '<S672>/Relational Operator3'
   *  UnitDelay: '<S435>/Unit Delay'
   *  UnitDelay: '<S435>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms((!AppSwcBcm_ARID_DEF.RelationalOperator22) &&
    (((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) && (LampCtl_PosLampSw ||
    LampCtl_LowBeamSw || LampCtl_AutoLampSta)) ||
     AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fu ||
     AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b || LampCtl_KnobBeamFaultSta ||
     LampCtl_LampDelay), LampCtl_PosLampStaTimValid_C,
    LampCtl_PosLampStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8);
}

/* System initialize for atomic system: '<S435>/SignalProcess' */
static void AppSwcBcm_SignalProcess_p_Init(void)
{
  /* SystemInitialize for Chart: '<S674>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);

  /* SystemInitialize for Chart: '<S674>/LIB_TPD_10ms13' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);
}

/* Output and update for atomic system: '<S435>/SignalProcess' */
static void AppSwcBcm_SignalProcess_n(void)
{
  sint32 tmp;
  uint16 rtb_y;
  uint16 rtb_y_p;
  uint16 tmp_0;
  boolean rtb_LogicalOperator2_c5;
  boolean rtb_Switch;
  boolean rtb_Switch9_p;

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift' */
  /* Constant: '<S674>/Constant48' */
  rtb_y = AppSwcBcm_BitShift3(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift' */

  /* Switch: '<S674>/Switch' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S674>/Switch' incorporates:
     *  Constant: '<S674>/Constant50'
     */
    rtb_Switch = LampCtl_PosLampVal_C;
  } else {
    /* Switch: '<S674>/Switch' incorporates:
     *  Logic: '<S674>/Logical Operator6'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSPstnLghtSwStVld_flg);
  }

  /* End of Switch: '<S674>/Switch' */

  /* Chart: '<S674>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S674>/Constant19'
   *  Constant: '<S674>/Constant20'
   *  Constant: '<S674>/Constant21'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_e >= (float32)LampCtl_PosLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_PosLampTimValid_C != 0xFFFF)) {
      LampCtl_PosLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_e++;
      AppSwcBcm_ARID_DEF.cnt_heal_j = (uint16)((float32)
        LampCtl_PosLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_e = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_j == 0) {
      LampCtl_PosLampSw = false;
    } else if (LampCtl_PosLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_j--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift4' */
  /* Constant: '<S674>/Constant1' */
  rtb_y_p = AppSwcBcm_BitShift1_i(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift4' */

  /* Switch: '<S674>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND4'
   */
  if ((rtb_y_p & 1U) != 0U) {
    /* Switch: '<S674>/Switch4' incorporates:
     *  Constant: '<S674>/Constant10'
     */
    rtb_Switch = LampCtl_LowBeamVal_C;
  } else {
    /* Switch: '<S674>/Switch4' incorporates:
     *  Logic: '<S674>/Logical Operator7'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLoBeamSwStVld_flg);
  }

  /* End of Switch: '<S674>/Switch4' */

  /* Chart: '<S674>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S674>/Constant22'
   *  Constant: '<S674>/Constant23'
   *  Constant: '<S674>/Constant24'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_je >= (float32)LampCtl_LowBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_LowBeamTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_je++;
      AppSwcBcm_ARID_DEF.cnt_heal_l = (uint16)((float32)
        LampCtl_LowBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_je = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_l == 0) {
      LampCtl_LowBeamSw = false;
    } else if (LampCtl_LowBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_l--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift7' */
  /* Constant: '<S674>/Constant12' */
  rtb_y_p = AppSwcBcm_BitShift2(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift7' */

  /* Switch: '<S674>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND7'
   */
  if ((rtb_y_p & 1U) != 0U) {
    /* Switch: '<S674>/Switch7' incorporates:
     *  Constant: '<S674>/Constant11'
     */
    rtb_Switch = LampCtl_HiBeamVal_C;
  } else {
    /* Switch: '<S674>/Switch7' incorporates:
     *  Logic: '<S674>/Logical Operator8'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSHiBeamSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSHiBeamSwStVld_flg);
  }

  /* End of Switch: '<S674>/Switch7' */

  /* Chart: '<S674>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S674>/Constant25'
   *  Constant: '<S674>/Constant26'
   *  Constant: '<S674>/Constant27'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_f >= (float32)LampCtl_HiBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_HiBeamTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_f++;
      AppSwcBcm_ARID_DEF.cnt_heal_ka = (uint16)((float32)
        LampCtl_HiBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_f = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ka == 0) {
      LampCtl_HiBeamSw = false;
    } else if (LampCtl_HiBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ka--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift1' */
  /* Constant: '<S674>/Constant3' */
  rtb_y = AppSwcBcm_BitShift1_m(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift1' */

  /* Switch: '<S674>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S674>/Switch1' incorporates:
     *  Constant: '<S674>/Constant2'
     */
    rtb_Switch = LampCtl_PassLightVal_C;
  } else {
    /* Switch: '<S674>/Switch1' incorporates:
     *  Logic: '<S674>/Logical Operator1'
     */
    rtb_Switch =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSOvrVehBeamSwSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSOvrVehBeamSwStVld_flg);
  }

  /* End of Switch: '<S674>/Switch1' */

  /* Chart: '<S674>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S674>/Constant28'
   *  Constant: '<S674>/Constant29'
   *  Constant: '<S674>/Constant30'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_i >= (float32)LampCtl_PassLightTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_PassLightTimValid_C != 0xFFFF))
    {
      LampCtl_PassLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_i++;
      AppSwcBcm_ARID_DEF.cnt_heal_d = (uint16)((float32)
        LampCtl_PassLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_i = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d == 0) {
      LampCtl_PassLightSw = false;
    } else if (LampCtl_PassLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_d--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift2' */
  /* Constant: '<S674>/Constant53' */
  rtb_y = AppSwcBcm_BitShift4(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift8' */
  /* Constant: '<S674>/Constant4' */
  rtb_y_p = AppSwcBcm_BitShift6(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift8' */

  /* Logic: '<S674>/Logical Operator3' */
  rtb_Switch =
    (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwSt_flg &&
     AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwStVld_flg);

  /* Logic: '<S674>/Logical Operator2' */
  rtb_LogicalOperator2_c5 =
    (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwSt_flg &&
     AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwStVld_flg);

  /* Switch: '<S674>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND8'
   */
  if ((rtb_y_p & 1U) != 0U) {
    /* Switch: '<S674>/Switch9' incorporates:
     *  Constant: '<S674>/Constant5'
     */
    rtb_Switch9_p = LampCtl_TurnIndcrRVal_C;
  } else {
    /* Switch: '<S674>/Switch9' incorporates:
     *  Logic: '<S674>/Logical Operator'
     *  Logic: '<S674>/Logical Operator10'
     */
    rtb_Switch9_p = (rtb_Switch && (!rtb_LogicalOperator2_c5));
  }

  /* End of Switch: '<S674>/Switch9' */

  /* Chart: '<S674>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S674>/Constant37'
   *  Constant: '<S674>/Constant38'
   *  Constant: '<S674>/Constant39'
   */
  if (rtb_Switch9_p) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o0 >= (float32)
         LampCtl_TurnIndcrRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o0++;
      AppSwcBcm_ARID_DEF.cnt_heal_k = (uint16)((float32)
        LampCtl_TurnIndcrRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S674>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S674>/Constant37'
     *  Constant: '<S674>/Constant38'
     *  Constant: '<S674>/Constant39'
     *  Constant: '<S674>/Constant40'
     *  Constant: '<S674>/Constant41'
     *  Constant: '<S674>/Constant42'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o >= (float32)
         LampCtl_TurnIndcrLaneRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o++;
      AppSwcBcm_ARID_DEF.cnt_heal_m3 = (uint16)((float32)
        LampCtl_TurnIndcrLaneRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o0 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k == 0) {
      LampCtl_TurnIndcrRSw = false;
    } else if (LampCtl_TurnIndcrRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k--;
    }

    /* Chart: '<S674>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S674>/Constant38'
     *  Constant: '<S674>/Constant41'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_o = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m3 == 0) {
      LampCtl_TurnIndcrLaneRSw = false;
    } else if (LampCtl_TurnIndcrLaneRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_m3--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms6' */

  /* Switch: '<S674>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S674>/Switch2' incorporates:
     *  Constant: '<S674>/Constant54'
     */
    rtb_LogicalOperator2_c5 = LampCtl_TurnIndcrLVal_C;
  } else {
    /* Switch: '<S674>/Switch2' incorporates:
     *  Logic: '<S674>/Logical Operator12'
     *  Logic: '<S674>/Logical Operator5'
     *  UnitDelay: '<S674>/Unit Delay1'
     */
    rtb_LogicalOperator2_c5 = (rtb_LogicalOperator2_c5 &&
      (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i));
  }

  /* End of Switch: '<S674>/Switch2' */

  /* Chart: '<S674>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S674>/Constant31'
   *  Constant: '<S674>/Constant32'
   *  Constant: '<S674>/Constant33'
   */
  if (rtb_LogicalOperator2_c5) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hd >= (float32)
         LampCtl_TurnIndcrLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hd++;
      AppSwcBcm_ARID_DEF.cnt_heal_g = (uint16)((float32)
        LampCtl_TurnIndcrLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S674>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S674>/Constant31'
     *  Constant: '<S674>/Constant32'
     *  Constant: '<S674>/Constant33'
     *  Constant: '<S674>/Constant34'
     *  Constant: '<S674>/Constant35'
     *  Constant: '<S674>/Constant36'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_h >= (float32)
         LampCtl_TurnIndcrLaneLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_h++;
      AppSwcBcm_ARID_DEF.cnt_heal_c = (uint16)((float32)
        LampCtl_TurnIndcrLaneLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g == 0) {
      LampCtl_TurnIndcrLSw = false;
    } else if (LampCtl_TurnIndcrLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_g--;
    }

    /* Chart: '<S674>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S674>/Constant32'
     *  Constant: '<S674>/Constant35'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_h = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c == 0) {
      LampCtl_TurnIndcrLaneLSw = false;
    } else if (LampCtl_TurnIndcrLaneLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_c--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift3' */
  /* Constant: '<S674>/Constant55' */
  rtb_y_p = AppSwcBcm_BitShift8(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift3' */

  /* Switch: '<S674>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND3'
   */
  if ((rtb_y_p & 1U) != 0U) {
    /* Switch: '<S674>/Switch3' incorporates:
     *  Constant: '<S674>/Constant56'
     */
    rtb_LogicalOperator2_c5 = LampCtl_FogLampRVal_C;
  } else {
    /* Switch: '<S674>/Switch3' incorporates:
     *  DataTypeConversion: '<S674>/Data Type Conversion3'
     *  Logic: '<S674>/Logical Operator9'
     */
    rtb_LogicalOperator2_c5 = (BSW_J346FogLampR == 0);
  }

  /* End of Switch: '<S674>/Switch3' */

  /* Chart: '<S674>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S674>/Constant43'
   *  Constant: '<S674>/Constant44'
   *  Constant: '<S674>/Constant45'
   */
  if (rtb_LogicalOperator2_c5) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d >= (float32)LampCtl_FogLampRTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampRTimValid_C != 0xFFFF)) {
      LampCtl_FogLampRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d++;
      AppSwcBcm_ARID_DEF.cnt_heal_fr = (uint16)((float32)
        LampCtl_FogLampRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_fr == 0) {
      LampCtl_FogLampRSw = false;
    } else if (LampCtl_FogLampRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_fr--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms9' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift5' */
  /* Switch: '<S674>/Switch5' incorporates:
   *  Constant: '<S674>/Constant59'
   *  MATLAB Function: '<S745>/bit_shift'
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND5'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 9 & 1U) != 0U) {
    /* Switch: '<S674>/Switch5' incorporates:
     *  Constant: '<S674>/Constant60'
     */
    rtb_LogicalOperator2_c5 = LampCtl_HazardLightVal_C;
  } else {
    /* Switch: '<S674>/Switch5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     *  DataTypeConversion: '<S674>/Data Type Conversion5'
     */
    rtb_LogicalOperator2_c5 =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPHzrdKey_flg;
  }

  /* End of Switch: '<S674>/Switch5' */
  /* End of Outputs for SubSystem: '<S674>/Bit Shift5' */

  /* Chart: '<S674>/LIB_TPD_10ms10' incorporates:
   *  Constant: '<S674>/Constant46'
   *  Constant: '<S674>/Constant47'
   *  Constant: '<S674>/Constant49'
   */
  if (rtb_LogicalOperator2_c5) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b >= (float32)
         LampCtl_HazardLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HazardLightTimValid_C != 0xFFFF)) {
      LampCtl_HazardLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b++;
      AppSwcBcm_ARID_DEF.cnt_heal_gc = (uint16)((float32)
        LampCtl_HazardLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gc == 0) {
      LampCtl_HazardLightSw = false;
    } else if (LampCtl_HazardLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_gc--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms10' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift11' */
  /* Constant: '<S674>/Constant73' */
  rtb_y = AppSwcBcm_BitShift12_d(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift6' */
  /* Switch: '<S674>/Switch6' incorporates:
   *  Constant: '<S674>/Constant61'
   *  Constant: '<S674>/Constant62'
   *  DataTypeConversion: '<S674>/Data Type Conversion6'
   *  MATLAB Function: '<S746>/bit_shift'
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND6'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 10 & 1U) != 0U) {
    rtb_LogicalOperator2_c5 = LampCtl_BrakeLightVal_C;
  } else {
    rtb_LogicalOperator2_c5 = (BSW_J313BrakeLoSw != 0);
  }

  /* End of Outputs for SubSystem: '<S674>/Bit Shift6' */

  /* Chart: '<S674>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S674>/Constant14'
   *  Constant: '<S674>/Constant15'
   *  Constant: '<S674>/Constant16'
   *  Switch: '<S674>/Switch6'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_LogicalOperator2_c5, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11);

  /* Switch: '<S674>/Switch12' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND11'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S674>/Switch12' incorporates:
     *  Constant: '<S674>/Constant74'
     */
    rtb_LogicalOperator2_c5 = LampCtl_BrakeLightVal_C;
  } else {
    /* Switch: '<S674>/Switch12' incorporates:
     *  DataTypeConversion: '<S674>/Data Type Conversion13'
     *  Logic: '<S674>/Logical Operator14'
     */
    rtb_LogicalOperator2_c5 = (BSW_J339BrakeHiSw == 0);
  }

  /* End of Switch: '<S674>/Switch12' */

  /* Chart: '<S674>/LIB_TPD_10ms13' incorporates:
   *  Constant: '<S674>/Constant70'
   *  Constant: '<S674>/Constant71'
   *  Constant: '<S674>/Constant72'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_LogicalOperator2_c5, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms13);

  /* Logic: '<S674>/Logical Operator13' */
  LampCtl_BrakeLightSw = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_i ||
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift9' */
  /* Constant: '<S674>/Constant6' */
  rtb_y_p = AppSwcBcm_BitShift7(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift9' */

  /* Switch: '<S674>/Switch10' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND9'
   */
  if ((rtb_y_p & 1U) != 0U) {
    /* Switch: '<S674>/Switch10' incorporates:
     *  Constant: '<S674>/Constant8'
     */
    rtb_LogicalOperator2_c5 = LampCtl_AutoLampVal_C;
  } else {
    /* Switch: '<S674>/Switch10' incorporates:
     *  Logic: '<S674>/Logical Operator4'
     */
    rtb_LogicalOperator2_c5 =
      (AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLampAutoSt_flg &&
       AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLampAutoStVld_flg);
  }

  /* End of Switch: '<S674>/Switch10' */

  /* Chart: '<S674>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S674>/Constant13'
   *  Constant: '<S674>/Constant63'
   *  Constant: '<S674>/Constant9'
   */
  if (rtb_LogicalOperator2_c5) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_p >= (float32)LampCtl_AutoLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_AutoLampTimValid_C != 0xFFFF)) {
      LampCtl_AutoLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_p++;
      AppSwcBcm_ARID_DEF.cnt_heal_h = (uint16)((float32)
        LampCtl_AutoLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_p = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h == 0) {
      LampCtl_AutoLampSw = false;
    } else if (LampCtl_AutoLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_h--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S674>/Bit Shift10' */
  /* Constant: '<S674>/Constant68' */
  rtb_y = AppSwcBcm_BitShift9(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S674>/Bit Shift10' */

  /* Switch: '<S674>/Switch11' incorporates:
   *  S-Function (sfix_bitop): '<S674>/Bitwise AND10'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S674>/Switch11' incorporates:
     *  Constant: '<S674>/Constant69'
     */
    rtb_LogicalOperator2_c5 = LampCtl_FogLampFVal_C;
  } else {
    /* Switch: '<S674>/Switch11' incorporates:
     *  DataTypeConversion: '<S674>/Data Type Conversion9'
     *  Logic: '<S674>/Logical Operator11'
     */
    rtb_LogicalOperator2_c5 = (BSW_J322FogLampF == 0);
  }

  /* End of Switch: '<S674>/Switch11' */

  /* Chart: '<S674>/LIB_TPD_10ms12' incorporates:
   *  Constant: '<S674>/Constant64'
   *  Constant: '<S674>/Constant66'
   *  Constant: '<S674>/Constant67'
   */
  if (rtb_LogicalOperator2_c5) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_oi >= (float32)LampCtl_FogLampFTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampFTimValid_C != 0xFFFF)) {
      LampCtl_FogLampFSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_oi++;
      AppSwcBcm_ARID_DEF.cnt_heal_dm = (uint16)((float32)
        LampCtl_FogLampFTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_oi = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_dm == 0) {
      LampCtl_FogLampFSw = false;
    } else if (LampCtl_FogLampFTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_dm--;
    }
  }

  /* End of Chart: '<S674>/LIB_TPD_10ms12' */

  /* MultiPortSwitch: '<S674>/Multiport Switch' */
  switch (BSW_RKEReq) {
   case 0:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant'
     */
    LampCtl_RKEReq = 0U;
    break;

   case 17:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant17'
     */
    LampCtl_RKEReq = 1U;
    break;

   case 18:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant18'
     */
    LampCtl_RKEReq = 2U;
    break;

   case 35:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant51'
     */
    LampCtl_RKEReq = 3U;
    break;

   case 34:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant52'
     */
    LampCtl_RKEReq = 4U;
    break;

   case 49:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant57'
     */
    LampCtl_RKEReq = 5U;
    break;

   case 50:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant58'
     */
    LampCtl_RKEReq = 6U;
    break;

   case 33:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant75'
     */
    LampCtl_RKEReq = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant76'
     */
    LampCtl_RKEReq = MAX_uint8_T;
    break;
  }

  /* End of MultiPortSwitch: '<S674>/Multiport Switch' */
  AppSwcBcm_ARID_DEF.Lib_blIn_db = ((LampCtl_RKEReq != 0) && (LampCtl_RKEReq !=
    5) && (LampCtl_RKEReq != 6));

  /* Chart: '<S674>/ClearRKECommd' incorporates:
   *  SubSystem: '<S750>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_db,
    &AppSwcBcm_ARID_DEF.LogicalOperator_kx,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_a);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_kx) {
    AppSwcBcm_ARID_DEF.flg = true;
    tmp_0 = LampCtl_RKECmdClearCnt_C;
    if (LampCtl_RKECmdClearCnt_C > 255) {
      tmp_0 = 255U;
    }

    AppSwcBcm_ARID_DEF.Cnt_gc = (uint8)tmp_0;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_gc - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_gc - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_gc = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg && (AppSwcBcm_ARID_DEF.Cnt_gc == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg = false;
  }

  /* DataTypeConversion: '<S674>/Data Type Conversion12' */
  LampCtl_LightIntstVal = BSW_J125LightIntst;

  /* Update for UnitDelay: '<S674>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i = rtb_Switch;
}

/*
 * System initialize for function-call system:
 *    '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
  (ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
   *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S807>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_k_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S807>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(boolean rtu_Lib_blIn,
  boolean *rty_Lib_blOut, ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S807>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_e(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S807>/Lib_RiseEdgeDetInit' */
}

/*
 * System initialize for function-call system:
 *    '<S832>/Lib_ChangeEdge'
 *    '<S832>/Lib_ChangeEdge1'
 *    '<S832>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge_Init(ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S836>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S832>/Lib_ChangeEdge'
 *    '<S832>/Lib_ChangeEdge1'
 *    '<S832>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge(float32 rtu_Lib_In, float32 rtu_Lib_InNow,
  float32 rtu_Lib_InBefore, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S836>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
  }

  /* Logic: '<S836>/Logical Operator' incorporates:
   *  Delay: '<S836>/Delay'
   *  RelationalOperator: '<S836>/Relational Operator'
   *  RelationalOperator: '<S836>/Relational Operator1'
   */
  *rty_Lib_blOut = ((rtu_Lib_InNow == rtu_Lib_In) &&
                    (AppSwcBcm__ARID_DEF_arg->Delay_DSTATE == rtu_Lib_InBefore));

  /* Update for Delay: '<S836>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
}

/*
 * System initialize for function-call system:
 *    '<S791>/Pri4Func.Turn'
 *    '<S791>/Pri4Func.Turn1'
 *    '<S791>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y)
{
  /* SystemInitialize for Chart: '<S848>/Turn' */
  *rty_y = false;
}

/*
 * Output and update for function-call system:
 *    '<S791>/Pri4Func.Turn'
 *    '<S791>/Pri4Func.Turn1'
 *    '<S791>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S848>/Turn' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c121_LampCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c121_LampCtl_Lib = 1U;
    *rty_y = !rtu_x;
  }

  /* End of Chart: '<S848>/Turn' */
}

/*
 * System initialize for atomic system:
 *    '<S792>/TurnIndcrDig'
 *    '<S792>/TurnIndcrDig1'
 *    '<S792>/TurnIndcrDig2'
 *    '<S792>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig_Init(boolean *rty_LIB_blErrFlg)
{
  *rty_LIB_blErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S792>/TurnIndcrDig'
 *    '<S792>/TurnIndcrDig1'
 *    '<S792>/TurnIndcrDig2'
 *    '<S792>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig(boolean rtu_LIB_blIn, boolean rtu_LIB_blIn2,
  boolean rtu_LIB_blRst, float32 rtu_LIB_s32Ts, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, uint8 rtu_LIB_u8Cnt, boolean *rty_LIB_blErrFlg,
  ARID_DEF_TurnIndcrDig_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;
  float32 tmp_0;

  /* Chart: '<S792>/TurnIndcrDig' */
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

  /* End of Chart: '<S792>/TurnIndcrDig' */
}

/*
 * Output and update for atomic system:
 *    '<S871>/Lib_BothEdgeDet'
 *    '<S917>/Lib_BothEdgeDet'
 *    '<S917>/Lib_BothEdgeDet1'
 *    '<S917>/Lib_BothEdgeDet2'
 *    '<S917>/Lib_BothEdgeDet3'
 */
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S872>/Logical Operator2' incorporates:
   *  Logic: '<S872>/Logical Operator1'
   *  Logic: '<S872>/Logical Operator3'
   *  Logic: '<S872>/Logical Operator4'
   *  Logic: '<S872>/Logical Operator5'
   *  UnitDelay: '<S872>/Unit Delay'
   */
  *rty_Lib_blOut = ((AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_Lib_blIn))
                    || (rtu_Lib_blIn &&
                        (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE)));

  /* Update for UnitDelay: '<S872>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S675>/HazardLightLogic' */
static boolean AppSwcBcm_EmerOff(void)
{
  boolean guard1 = false;
  boolean y;

  /* UnitDelay: '<S675>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.Lib_blIn_e5 = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_k;

  /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet1' */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_e5,
    &AppSwcBcm_ARID_DEF.LogicalOperator_fz,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

  /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet1' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_fz) {
    guard1 = true;
  } else {
    /* UnitDelay: '<S675>/Unit Delay5' */
    AppSwcBcm_ARID_DEF.Lib_blIn_p = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_od;

    /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet2' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_p,
      &AppSwcBcm_ARID_DEF.LogicalOperator_mu,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

    /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet2' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_mu) {
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

/* Function for Chart: '<S675>/HazardLightLogic' */
static boolean AppSwcBcm_HazardOff(void)
{
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_ej = LampCtl_HazardLightSw;

  /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ej,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mz,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);

  /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_mz) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
  } else {
    y = false;
  }

  return y;
}

/* Function for Chart: '<S675>/HazardLightLogic' */
static boolean AppSwcBcm_TurnOff(void)
{
  boolean guard1 = false;
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_ne = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 1);

  /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet4' */
  AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ne,
    &AppSwcBcm_ARID_DEF.LogicalOperator_k5,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet4);

  /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet4' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_k5) {
    guard1 = true;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_g = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta ==
      2);

    /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet5' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_g,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lt,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet5);

    /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet5' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_lt) {
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

/* Function for Chart: '<S675>/HazardLightLogic' */
static boolean AppSwcBcm_CrashHazardOff(void)
{
  boolean y;
  y = false;
  if (AppSwcBcm_ARID_DEF.CrashCnt >= 80) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ej = LampCtl_HazardLightSw;

    /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ej,
      &AppSwcBcm_ARID_DEF.LogicalOperator_mz,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);

    /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_mz) {
      y = true;
      AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
    }
  } else {
    AppSwcBcm_ARID_DEF.CrashCnt++;
  }

  return y;
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_TurnFunc(void)
{
  LampCtl_TurnIndcrRst = !LampCtl_TurnIndcrRst;
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_Pri1Func(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_EnFunc(void)
{
  LampCtl_TurnIndcrPrd = 0U;
  LampCtl_TurnIndcrWdt = 0U;
  LampCtl_TurnIndcrRFlashCnt = 0U;
  LampCtl_TurnIndcrLFlashCnt = 0U;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_Pri2Func(void)
{
  LampCtl_TurnIndcrPrd = 4U;
  LampCtl_TurnIndcrWdt = 2U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_Pri4Func(void)
{
  switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide) {
   case 2:
    AppSwcBcm_ARID_DEF.x = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S791>/Pri4Func.Turn' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x, &AppSwcBcm_ARID_DEF.y_k,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn);

    /* End of Outputs for SubSystem: '<S791>/Pri4Func.Turn' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_k;
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
    AppSwcBcm_ARID_DEF.x_h = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S791>/Pri4Func.Turn1' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_h, &AppSwcBcm_ARID_DEF.y_i,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn1);

    /* End of Outputs for SubSystem: '<S791>/Pri4Func.Turn1' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_i;
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
    AppSwcBcm_ARID_DEF.x_k = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S791>/Pri4Func.Turn2' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_k, &AppSwcBcm_ARID_DEF.y,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn2);

    /* End of Outputs for SubSystem: '<S791>/Pri4Func.Turn2' */
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

/* Function for Chart: '<S675>/TurnIndcrArb2' */
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

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_AntiLckFunc(void)
{
  LampCtl_TurnIndcrPrd = 8U;
  LampCtl_TurnIndcrWdt = 4U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_fm = AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;

  /* Outputs for Function Call SubSystem: '<S791>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_fm,
    &AppSwcBcm_ARID_DEF.RelationalOperator_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5AntiLckFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S791>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_f) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_ArmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 16U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
  AppSwcBcm_ARID_DEF.Lib_blIn_dx = AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;

  /* Outputs for Function Call SubSystem: '<S791>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_dx,
    &AppSwcBcm_ARID_DEF.RelationalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5ArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S791>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_b) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_DisarmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_jm = AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;

  /* Outputs for Function Call SubSystem: '<S791>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_jm,
    &AppSwcBcm_ARID_DEF.RelationalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5DisarmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S791>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_p) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
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

  AppSwcBcm_ARID_DEF.Lib_blIn_n = AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;

  /* Outputs for Function Call SubSystem: '<S791>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_n,
    &AppSwcBcm_ARID_DEF.RelationalOperator_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5PartArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S791>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_o) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_RodBeamFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_SeekFunc(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = 10U;
  LampCtl_TurnIndcrLFlashCnt = 10U;
  AppSwcBcm_ARID_DEF.Lib_blIn_fr = AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;

  /* Outputs for Function Call SubSystem: '<S791>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_fr,
    &AppSwcBcm_ARID_DEF.RelationalOperator_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5SeekFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S791>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_a) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S675>/TurnIndcrArb2' */
static void AppSwcBcm_TrunkWarnFunc(void)
{
  LampCtl_TurnIndcrPrd = 8U;
  LampCtl_TurnIndcrWdt = 4U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
}

/* Function for Chart: '<S782>/Chart1' */
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

/* Function for Chart: '<S782>/Chart1' */
static void AppSwcBcm_CrashClearFunc(void)
{
  if (AppSwcBcm_ARID_DEF.ClearCnt >= 80) {
    AppSwcBcm_ARID_DEF.Lib_blIn_o = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode ==
      0);

    /* Outputs for Function Call SubSystem: '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit' */
    AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_o,
      &AppSwcBcm_ARID_DEF.LogicalOperator_py,
      &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

    /* End of Outputs for SubSystem: '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_py) {
      AppSwcBcm_ARID_DEF.PwrOffFlg = true;
      AppSwcBcm_ARID_DEF.PwrOnFlg = false;
    }

    if (AppSwcBcm_ARID_DEF.PwrOffFlg) {
      AppSwcBcm_ARID_DEF.Lib_blIn_m4 =
        (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_m4,
        &AppSwcBcm_ARID_DEF.LogicalOperator_d,
        &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.PwrOnFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_d ||
        AppSwcBcm_ARID_DEF.PwrOnFlg);
    }
  } else {
    AppSwcBcm_ARID_DEF.ClearCnt++;
  }
}

/* System initialize for atomic system: '<S435>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S779>/Chart' incorporates:
   *  SubSystem: '<S799>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_f);

  /* SystemInitialize for Chart: '<S781>/Chart' incorporates:
   *  SubSystem: '<S803>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_j);

  /* SystemInitialize for Chart: '<S782>/Chart1' incorporates:
   *  SubSystem: '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S782>/Chart1' incorporates:
   *  SubSystem: '<S806>/CrashClearFunc.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S783>/Chart' incorporates:
   *  SubSystem: '<S817>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_b);

  /* SystemInitialize for Chart: '<S786>/Chart' incorporates:
   *  SubSystem: '<S832>/Lib_ChangeEdge'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

  /* SystemInitialize for Chart: '<S786>/Chart' incorporates:
   *  SubSystem: '<S832>/Lib_ChangeEdge1'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

  /* SystemInitialize for Chart: '<S786>/Chart' incorporates:
   *  SubSystem: '<S832>/Lib_ChangeEdge2'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

  /* SystemInitialize for Chart: '<S790>/Chart' incorporates:
   *  SubSystem: '<S845>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_o);

  /* SystemInitialize for Chart: '<S675>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S791>/Pri4Func.Turn'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_k);

  /* SystemInitialize for Chart: '<S675>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S791>/Pri4Func.Turn1'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_i);

  /* SystemInitialize for Chart: '<S675>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S791>/Pri4Func.Turn2'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y);

  /* SystemInitialize for Chart: '<S792>/TurnIndcrDig' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_o);

  /* SystemInitialize for Chart: '<S792>/TurnIndcrDig1' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_g);

  /* SystemInitialize for Chart: '<S792>/TurnIndcrDig2' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_c);

  /* SystemInitialize for Chart: '<S792>/TurnIndcrDig3' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* SystemInitialize for Chart: '<S797>/Chart' incorporates:
   *  SubSystem: '<S880>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_l);

  /* SystemInitialize for Chart: '<S797>/Chart' incorporates:
   *  SubSystem: '<S880>/Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S797>/Chart' incorporates:
   *  SubSystem: '<S880>/Lib_RiseEdgeDetInit2'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_f_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);
}

/* Output and update for atomic system: '<S435>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl(void)
{
  sint32 tmp;
  uint8 rtb_RelationalOperator_ol_tmp;
  boolean RelationalOperator;
  boolean RelationalOperator6;
  boolean RelationalOperator8_l;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_LogicalOperator10_k;
  boolean rtb_LogicalOperator1_ij;
  boolean rtb_LogicalOperator4_m3;
  boolean rtb_LogicalOperator6_j;
  boolean rtb_LogicalOperator8_h2;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator11_g;
  boolean rtb_RelationalOperator14_j;
  boolean rtb_RelationalOperator19;
  boolean rtb_RelationalOperator1_lz;
  boolean rtb_RelationalOperator23;
  boolean rtb_RelationalOperator3_pn;
  boolean rtb_RelationalOperator5_ek;
  boolean rtb_RelationalOperator5_lq;
  boolean rtb_RelationalOperator6;
  boolean rtb_RelationalOperator7_is;
  boolean rtb_RelationalOperator9_pb;
  boolean rtb_RelationalOperator_fx;

  /* RelationalOperator: '<S675>/Relational Operator5' */
  rtb_RelationalOperator5_ek = !AppSwcBcm_ARID_DEF.RelationalOperator22;

  /* RelationalOperator: '<S788>/Relational Operator6' incorporates:
   *  Inport: '<Root>/IPM_EHB_B_CHA'
   *  RelationalOperator: '<S784>/Relational Operator1'
   */
  rtb_RelationalOperator6 =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA())
    ->VIPM_EHBReqBrkLiOn_flg;

  /* Logic: '<S784>/Logical Operator' incorporates:
   *  Constant: '<S784>/Constant'
   *  RelationalOperator: '<S784>/Relational Operator'
   */
  LampCtl_EmerSta = (rtb_RelationalOperator6 &&
                     (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2));

  /* RelationalOperator: '<S787>/Relational Operator4' */
  rtb_RelationalOperator6 = LampCtl_EmerSta;

  /* Chart: '<S675>/TurnIndcrLogic' incorporates:
   *  UnitDelay: '<S675>/Unit Delay2'
   *  UnitDelay: '<S675>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c136_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c136_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
    LampCtl_TurnIndcrMod = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib) {
     case AppSwcBcm_IN_OFF_m:
      if (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_kq = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S794>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kq,
          &AppSwcBcm_ARID_DEF.LogicalOperator_m,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);

        /* End of Outputs for SubSystem: '<S794>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_m || LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_TurnR;
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
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
        AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnL == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
          AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
        AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrLSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 4U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ax = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S794>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ax,
          &AppSwcBcm_ARID_DEF.LogicalOperator_hm,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_dh);

        /* End of Outputs for SubSystem: '<S794>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_hm) {
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
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
        AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnR == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
          AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
        AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_OFF_m;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrRSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_kq = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S794>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kq,
          &AppSwcBcm_ARID_DEF.LogicalOperator_m,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);

        /* End of Outputs for SubSystem: '<S794>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_m) {
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
        AppSwcBcm_ARID_DEF.Lib_blIn_ax = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S794>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ax,
          &AppSwcBcm_ARID_DEF.LogicalOperator_hm,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_dh);

        /* End of Outputs for SubSystem: '<S794>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_hm || LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_c136_LampCtl_Lib = AppSwcBcm_IN_TurnL;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 2U;
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_ShortFlash;
        }
      }
    }
  }

  /* End of Chart: '<S675>/TurnIndcrLogic' */

  /* Chart: '<S675>/HazardLightLogic' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S675>/Unit Delay4'
   *  UnitDelay: '<S675>/Unit Delay5'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c95_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c95_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib = AppSwcBcm_IN_OFF_g;
    LampCtl_HazardLightSta = false;
    LampCtl_EmerHazardLightSta = false;
    AppSwcBcm_ARID_DEF.CrashCnt = 0U;
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib) {
     case AppSwcBcm_IN_EmerON:
      if (((!AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_od) &&
           (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_k)) ||
          AppSwcBcm_CrashHazardOff()) {
        /* {Lib_RiseEdgeDet(LampCtl_HazardLightSw)} */
        AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib = AppSwcBcm_IN_OFF_g;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
        AppSwcBcm_ARID_DEF.CrashCnt = 0U;
      } else {
        /* CrashHazardOff=CrashHazardOff(); */
      }
      break;

     case AppSwcBcm_IN_OFF_g:
      AppSwcBcm_ARID_DEF.Lib_blIn_e5 = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_k;

      /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_e5,
        &AppSwcBcm_ARID_DEF.LogicalOperator_fz,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

      /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_fz) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_p = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_od;

        /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_p,
          &AppSwcBcm_ARID_DEF.LogicalOperator_mu,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

        /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_mu) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_ej = LampCtl_HazardLightSw;

          /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_ej,
            &AppSwcBcm_ARID_DEF.LogicalOperator_mz,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);

          /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_mz) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_e1 =
              ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
               ->HazardLightSta == 1);

            /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet3' */
            AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_e1,
              &AppSwcBcm_ARID_DEF.LogicalOperator_he,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_b);

            /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet3' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_he ||
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
        AppSwcBcm_ARID_DEF.Lib_blIn_e1 =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->HazardLightSta ==
           1);

        /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_e1,
          &AppSwcBcm_ARID_DEF.LogicalOperator_he,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_b);

        /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib = AppSwcBcm_IN_EmerON;
        LampCtl_EmerHazardLightSta = true;
        LampCtl_HazardLightSta = false;
      } else if (AppSwcBcm_HazardOff() || AppSwcBcm_TurnOff()) {
        AppSwcBcm_ARID_DEF.Lib_blIn_e1 =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->HazardLightSta ==
           1);

        /* Outputs for Function Call SubSystem: '<S785>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_e1,
          &AppSwcBcm_ARID_DEF.LogicalOperator_he,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_b);

        /* End of Outputs for SubSystem: '<S785>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib = AppSwcBcm_IN_OFF_g;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
        AppSwcBcm_ARID_DEF.CrashCnt = 0U;
      }
      break;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib = AppSwcBcm_IN_ON_e;
      LampCtl_HazardLightSta = true;
      AppSwcBcm_TurnOff();
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c95_LampCtl_Lib = AppSwcBcm_IN_EmerON;
      LampCtl_EmerHazardLightSta = true;
      LampCtl_HazardLightSta = false;
    }
  }

  /* End of Chart: '<S675>/HazardLightLogic' */

  /* RelationalOperator: '<S787>/Relational Operator' */
  RelationalOperator = LampCtl_EmerHazardLightSta;

  /* Chart: '<S675>/TurnIndcrSelect' */
  if (AppSwcBcm_ARID_DEF.is_active_c138_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c138_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_Off_n;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib) {
     case AppSwcBcm_IN_Off_n:
      if (LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_TurnLROn;
      } else {
        switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta) {
         case 1:
          AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_TurnROn;
          break;

         case 2:
          AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_TurnLOn;
          break;
        }
      }
      break;

     case AppSwcBcm_IN_TurnLOn:
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_Off_n;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 3U;
      }
      break;

     case AppSwcBcm_IN_TurnLROn:
      if (!LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_Off_n;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 1U;
      }
      break;

     default:
      /* case IN_TurnROn: */
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c138_LampCtl_Lib = AppSwcBcm_IN_Off_n;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S675>/TurnIndcrSelect' */

  /* RelationalOperator: '<S787>/Relational Operator8' incorporates:
   *  Constant: '<S787>/Constant8'
   */
  RelationalOperator8_l = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide != 0);

  /* Logic: '<S787>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S787>/Relational Operator'
   *  RelationalOperator: '<S787>/Relational Operator4'
   */
  rtb_LogicalOperator8_h2 = (LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* Chart: '<S779>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c86_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c86_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_AlrmSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib == AppSwcBcm_IN_SetOff_d) {
    AppSwcBcm_ARID_DEF.Lib_blIn_h =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S799>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_h,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fd,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_f);

    /* End of Outputs for SubSystem: '<S799>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fd && (!rtb_LogicalOperator8_h2)) {
      AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
      LampCtl_AlrmSta = true;
    }

    /* case IN_SetOn: */
  } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts
              != 2) || rtb_LogicalOperator8_h2) {
    AppSwcBcm_ARID_DEF.is_c86_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_AlrmSta = false;
  }

  /* End of Chart: '<S779>/Chart' */

  /* RelationalOperator: '<S787>/Relational Operator6' */
  RelationalOperator6 = LampCtl_AlrmSta;

  /* Logic: '<S787>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S787>/Relational Operator'
   *  RelationalOperator: '<S787>/Relational Operator4'
   *  RelationalOperator: '<S787>/Relational Operator6'
   */
  rtb_LogicalOperator1_ij = (RelationalOperator8_l || LampCtl_AlrmSta ||
    LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* RelationalOperator: '<S798>/Relational Operator' incorporates:
   *  Constant: '<S798>/Constant'
   */
  rtb_RelationalOperator_fx = (LampCtl_RKEReq == 4);

  /* Chart: '<S798>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   * */
  if (AppSwcBcm_ARID_DEF.is_active_c140_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c140_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_SetOff_k;
    LampCtl_VehSeekSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib) {
     case AppSwcBcm_IN_RKESetOn:
      if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k >= 10) ||
          (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts != 1)
          || rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_SetOff_k;
        LampCtl_VehSeekSta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_d = rtb_RelationalOperator_fx;

        /* Outputs for Function Call SubSystem: '<S887>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_d,
          &AppSwcBcm_ARID_DEF.LogicalOperator_fi,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g);

        /* End of Outputs for SubSystem: '<S887>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_fi) {
          AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
            !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
          LampCtl_VehSeekSta = 0U;
          AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_RKESetOn;
        } else {
          LampCtl_VehSeekSta = 1U;
          Clear_RKECommd();
        }
      }
      break;

     case AppSwcBcm_IN_SetOff_k:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 1)
      {
        AppSwcBcm_ARID_DEF.Lib_blIn_d = rtb_RelationalOperator_fx;

        /* Outputs for Function Call SubSystem: '<S887>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_d,
          &AppSwcBcm_ARID_DEF.LogicalOperator_fi,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g);

        /* End of Outputs for SubSystem: '<S887>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_fi && (!rtb_LogicalOperator1_ij))
        {
          AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_RKESetOn;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     default:
      /* case IN_TboxSetOn: */
      if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k >= 10) ||
          (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts != 1)
          || rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_SetOff_k;
        LampCtl_VehSeekSta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_kn =
          (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 1) ||
           ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 2));

        /* Outputs for Function Call SubSystem: '<S887>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kn,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_d);

        /* End of Outputs for SubSystem: '<S887>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h) {
          AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
            !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
          AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_TboxSetOn;
          LampCtl_VehSeekSta = 2U;
        }
      }
      break;
    }

    if (guard1) {
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 1)
      {
        AppSwcBcm_ARID_DEF.Lib_blIn_kn =
          (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 1) ||
           ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
            ->VIPM_TBoxRmtCarSearch_enum == 2));

        /* Outputs for Function Call SubSystem: '<S887>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_kn,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_d);

        /* End of Outputs for SubSystem: '<S887>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h && (!rtb_LogicalOperator1_ij))
        {
          AppSwcBcm_ARID_DEF.is_c140_LampCtl_Lib = AppSwcBcm_IN_TboxSetOn;
          LampCtl_VehSeekSta = 2U;
        }
      }
    }
  }

  /* End of Chart: '<S798>/Chart' */

  /* Chart: '<S780>/Chart' incorporates:
   *  UnitDelay: '<S675>/Unit Delay10'
   *  UnitDelay: '<S675>/Unit Delay11'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c90_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c90_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c90_LampCtl_Lib = AppSwcBcm_IN_Off_n;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c90_LampCtl_Lib == AppSwcBcm_IN_Off_n) {
    if ((AppSwcBcm_ARID_DEF.BusCreator4.MechAntiLck ||
         AppSwcBcm_ARID_DEF.BusCreator4.RKEAntiLck) && (!rtb_LogicalOperator1_ij))
    {
      AppSwcBcm_ARID_DEF.is_c90_LampCtl_Lib = AppSwcBcm_IN_On_ix;
      LampCtl_AntiLckSta = true;
    }

    /* case IN_On: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE >= 3) ||
             rtb_LogicalOperator1_ij || (LampCtl_VehSeekSta == 1)) {
    AppSwcBcm_ARID_DEF.is_c90_LampCtl_Lib = AppSwcBcm_IN_Off_n;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.BusCreator4.MechAntiLck ||
             AppSwcBcm_ARID_DEF.BusCreator4.RKEAntiLck) {
    AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;
    AppSwcBcm_ARID_DEF.is_c90_LampCtl_Lib = AppSwcBcm_IN_On_ix;
    LampCtl_AntiLckSta = true;
  }

  /* End of Chart: '<S780>/Chart' */

  /* Chart: '<S781>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1 < 31U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c91_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c91_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c91_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c91_LampCtl_Lib == AppSwcBcm_IN_SetOff_d) {
    AppSwcBcm_ARID_DEF.Lib_blIn_la =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S803>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_la,
      &AppSwcBcm_ARID_DEF.LogicalOperator_o,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_j);

    /* End of Outputs for SubSystem: '<S803>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_o ||
         ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 1)))
        && (!rtb_LogicalOperator1_ij)) {
      AppSwcBcm_ARID_DEF.is_c91_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
      AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
      LampCtl_ArmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.temporalCounter_i1 >= 20U) ||
             ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts
              != 1) || (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_ij) {
    AppSwcBcm_ARID_DEF.is_c91_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) {
    AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt = !AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;
    AppSwcBcm_ARID_DEF.is_c91_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
    AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
    LampCtl_ArmedSta = true;
  }

  /* End of Chart: '<S781>/Chart' */

  /* Chart: '<S783>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S675>/Unit Delay8'
   *  UnitDelay: '<S675>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c94_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c94_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c94_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c94_LampCtl_Lib == AppSwcBcm_IN_SetOff_d) {
    AppSwcBcm_ARID_DEF.Lib_blIn_j1 =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 0);

    /* Outputs for Function Call SubSystem: '<S817>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_j1,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ac,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_b);

    /* End of Outputs for SubSystem: '<S817>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_ac ||
         (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 0)
          && (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1))) &&
        (!rtb_LogicalOperator1_ij)) {
      AppSwcBcm_ARID_DEF.is_c94_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
      LampCtl_DisarmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE >= 3) ||
             ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts
              != 0) || (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_ij) {
    AppSwcBcm_ARID_DEF.is_c94_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
    AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;
    AppSwcBcm_ARID_DEF.is_c94_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
    LampCtl_DisarmedSta = true;
  }

  /* End of Chart: '<S783>/Chart' */

  /* Chart: '<S786>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c96_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c96_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_PartArmedSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib) {
     case AppSwcBcm_IN_SetOff_d:
      LampCtl_PartArmedSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_In_k =
        (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts;
      AppSwcBcm_ARID_DEF.Lib_InNow_a = 3.0F;
      AppSwcBcm_ARID_DEF.Lib_InBefore_gr = 1.0F;

      /* Outputs for Function Call SubSystem: '<S832>/Lib_ChangeEdge2' */
      AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_k,
        AppSwcBcm_ARID_DEF.Lib_InNow_a, AppSwcBcm_ARID_DEF.Lib_InBefore_gr,
        &AppSwcBcm_ARID_DEF.LogicalOperator_po,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

      /* End of Outputs for SubSystem: '<S832>/Lib_ChangeEdge2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
        AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOn2;
        LampCtl_PartArmedSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_In =
          (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts;
        AppSwcBcm_ARID_DEF.Lib_InNow = 3.0F;
        AppSwcBcm_ARID_DEF.Lib_InBefore = 0.0F;

        /* Outputs for Function Call SubSystem: '<S832>/Lib_ChangeEdge' */
        AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In,
          AppSwcBcm_ARID_DEF.Lib_InNow, AppSwcBcm_ARID_DEF.Lib_InBefore,
          &AppSwcBcm_ARID_DEF.LogicalOperator_n,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

        /* End of Outputs for SubSystem: '<S832>/Lib_ChangeEdge' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_n) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_In_a =
            (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts;
          AppSwcBcm_ARID_DEF.Lib_InNow_n = 3.0F;
          AppSwcBcm_ARID_DEF.Lib_InBefore_g = 2.0F;

          /* Outputs for Function Call SubSystem: '<S832>/Lib_ChangeEdge1' */
          AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_a,
            AppSwcBcm_ARID_DEF.Lib_InNow_n, AppSwcBcm_ARID_DEF.Lib_InBefore_g,
            &AppSwcBcm_ARID_DEF.LogicalOperator_cq,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

          /* End of Outputs for SubSystem: '<S832>/Lib_ChangeEdge1' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_cq ||
              ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
               ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts
                == 3))) {
            guard1 = true;
          }
        }
      }
      break;

     case AppSwcBcm_IN_SetOn1:
      LampCtl_PartArmedSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_m >= 3) ||
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts != 3)
          || (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
        LampCtl_PartArmedSta = 0U;
      } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;

     default:
      /* case IN_SetOn2: */
      LampCtl_PartArmedSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_m >= 3) ||
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts != 3)
          || (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
        LampCtl_PartArmedSta = 0U;
      } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;
    }

    if (guard1) {
      if (!rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c96_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
    }
  }

  /* End of Chart: '<S786>/Chart' */

  /* RelationalOperator: '<S788>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S787>/Relational Operator12'
   */
  rtb_LogicalOperator6_j = !LampCtl_ArmedSta;

  /* RelationalOperator: '<S788>/Relational Operator2' incorporates:
   *  RelationalOperator: '<S787>/Relational Operator15'
   */
  rtb_RelationalOperator3_pn = !LampCtl_DisarmedSta;

  /* RelationalOperator: '<S788>/Relational Operator7' incorporates:
   *  RelationalOperator: '<S787>/Relational Operator17'
   */
  rtb_LogicalOperator4_m3 = !LampCtl_AntiLckSta;

  /* Chart: '<S788>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S788>/Constant'
   *  Constant: '<S788>/Constant2'
   *  Constant: '<S788>/Constant21'
   *  Constant: '<S788>/Constant3'
   *  Constant: '<S788>/Constant5'
   *  Constant: '<S788>/Constant7'
   *  Logic: '<S788>/Logical Operator'
   *  Logic: '<S788>/Logical Operator1'
   *  Logic: '<S788>/Logical Operator2'
   *  RelationalOperator: '<S788>/Relational Operator'
   *  RelationalOperator: '<S788>/Relational Operator1'
   *  RelationalOperator: '<S788>/Relational Operator2'
   *  RelationalOperator: '<S788>/Relational Operator3'
   *  RelationalOperator: '<S788>/Relational Operator4'
   *  RelationalOperator: '<S788>/Relational Operator5'
   *  RelationalOperator: '<S788>/Relational Operator6'
   *  RelationalOperator: '<S788>/Relational Operator7'
   */
  if (rtb_LogicalOperator4_m3 && rtb_RelationalOperator3_pn &&
      (LampCtl_PartArmedSta == 0) && rtb_LogicalOperator6_j &&
      (LampCtl_VehSeekSta == 0) &&
      ((!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSLeTrnLmpSwStVld_flg)
       ||
       (!AppSwcBcm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD.VIPM_SCSRiTrnLmpSwStVld_flg))
      && (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_m >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_RodBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m++;
      AppSwcBcm_ARID_DEF.cnt_heal_m = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m == 0) {
      LampCtl_RodBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_m--;
    }
  }

  /* End of Chart: '<S788>/LIB_TPD_10ms' */

  /* Chart: '<S797>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c139_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c139_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Init_e;
    LampCtl_VehModeSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib) {
     case AppSwcBcm_IN_Init_e:
      LampCtl_VehModeSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_ec =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
         ->VIPC_VehHiddenMode_enum == 1);

      /* Outputs for Function Call SubSystem: '<S880>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_ec,
        &AppSwcBcm_ARID_DEF.LogicalOperator_pe,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_l);

      /* End of Outputs for SubSystem: '<S880>/Lib_RiseEdgeDetInit' */
      rtb_RelationalOperator_fx = !rtb_LogicalOperator1_ij;
      if (AppSwcBcm_ARID_DEF.LogicalOperator_pe && rtb_RelationalOperator_fx) {
        AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Show;
        LampCtl_VehModeSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_dd =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
           ->VIPC_VehHiddenMode_enum == 2);

        /* Outputs for Function Call SubSystem: '<S880>/Lib_RiseEdgeDetInit1' */
        AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_dd,
          &AppSwcBcm_ARID_DEF.LogicalOperator_p3,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

        /* End of Outputs for SubSystem: '<S880>/Lib_RiseEdgeDetInit1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_p3 && rtb_RelationalOperator_fx)
        {
          AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Limit;
          LampCtl_VehModeSta = 3U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_b =
            ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
             ->VIPC_VehHiddenMode_enum == 0);

          /* Outputs for Function Call SubSystem: '<S880>/Lib_RiseEdgeDetInit2' */
          AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_b,
            &AppSwcBcm_ARID_DEF.LogicalOperator_g,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);

          /* End of Outputs for SubSystem: '<S880>/Lib_RiseEdgeDetInit2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_g && rtb_RelationalOperator_fx)
          {
            AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Nrm_g;
            LampCtl_VehModeSta = 1U;
          }
        }
      }
      break;

     case AppSwcBcm_IN_Limit:
      LampCtl_VehModeSta = 3U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 3) ||
          rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Init_e;
        LampCtl_VehModeSta = 0U;
      }
      break;

     case AppSwcBcm_IN_Nrm_g:
      LampCtl_VehModeSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 1) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 1) ||
          rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Init_e;
        LampCtl_VehModeSta = 0U;
      }
      break;

     default:
      /* case IN_Show: */
      LampCtl_VehModeSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 2) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 2) ||
          rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c139_LampCtl_Lib = AppSwcBcm_IN_Init_e;
        LampCtl_VehModeSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S797>/Chart' */

  /* Chart: '<S790>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S675>/Unit Delay14'
   *  UnitDelay: '<S675>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c101_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c101_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c101_LampCtl_Lib = AppSwcBcm_IN_SetOff_k;
    LampCtl_TrunkWarnSta = false;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c101_LampCtl_Lib) {
     case AppSwcBcm_IN_Delay:
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts != 3)
          || (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_ij ||
          (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw)) {
        AppSwcBcm_ARID_DEF.is_c101_LampCtl_Lib = AppSwcBcm_IN_SetOff_k;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
                  ->BodyWarnSts == 3) && (AppSwcBcm_ARID_DEF.TrunkWarnCnt >=
                  LampCtl_TrunkWarnTim_C)) {
        AppSwcBcm_ARID_DEF.is_c101_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
        LampCtl_TrunkWarnSta = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff_k:
      AppSwcBcm_ARID_DEF.Lib_blIn_jy =
        AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S845>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_j(AppSwcBcm_ARID_DEF.Lib_blIn_jy,
        &AppSwcBcm_ARID_DEF.LogicalOperator_e,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_o);

      /* End of Outputs for SubSystem: '<S845>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_e && (!rtb_LogicalOperator1_ij) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts == 3))
      {
        AppSwcBcm_ARID_DEF.is_c101_LampCtl_Lib = AppSwcBcm_IN_Delay;
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
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts != 3)
          || (LampCtl_VehSeekSta == 1) || rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_c101_LampCtl_Lib = AppSwcBcm_IN_SetOff_k;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S790>/Chart' */

  /* RelationalOperator: '<S787>/Relational Operator10' */
  rtb_RelationalOperator_fx = LampCtl_ArmedSta;

  /* RelationalOperator: '<S787>/Relational Operator11' incorporates:
   *  Constant: '<S787>/Constant12'
   */
  rtb_RelationalOperator11_g = (LampCtl_VehSeekSta != 0);

  /* RelationalOperator: '<S787>/Relational Operator14' */
  rtb_RelationalOperator14_j = LampCtl_DisarmedSta;

  /* Logic: '<S787>/Logical Operator10' incorporates:
   *  Constant: '<S787>/Constant16'
   *  Constant: '<S787>/Constant26'
   *  RelationalOperator: '<S787>/Relational Operator16'
   *  RelationalOperator: '<S787>/Relational Operator25'
   */
  rtb_LogicalOperator10_k = ((LampCtl_PartArmedSta == 2) ||
    (LampCtl_PartArmedSta == 1));

  /* RelationalOperator: '<S787>/Relational Operator1' */
  rtb_RelationalOperator1_lz = LampCtl_RodBeamFaultSta;

  /* RelationalOperator: '<S787>/Relational Operator19' */
  rtb_RelationalOperator19 = LampCtl_AntiLckSta;

  /* Logic: '<S787>/Logical Operator9' incorporates:
   *  Constant: '<S787>/Constant20'
   *  Constant: '<S787>/Constant21'
   *  Constant: '<S787>/Constant23'
   *  RelationalOperator: '<S787>/Relational Operator20'
   *  RelationalOperator: '<S787>/Relational Operator22'
   *  RelationalOperator: '<S787>/Relational Operator3'
   */
  rtb_LogicalOperator9 = ((LampCtl_VehModeSta == 1) || (LampCtl_VehModeSta == 2)
    || (LampCtl_VehModeSta == 3));

  /* RelationalOperator: '<S787>/Relational Operator23' */
  rtb_RelationalOperator23 = LampCtl_TrunkWarnSta;

  /* RelationalOperator: '<S787>/Relational Operator5' */
  rtb_RelationalOperator5_lq = !LampCtl_EmerSta;

  /* RelationalOperator: '<S787>/Relational Operator7' */
  rtb_RelationalOperator7_is = !LampCtl_AlrmSta;

  /* RelationalOperator: '<S787>/Relational Operator9' incorporates:
   *  Constant: '<S787>/Constant9'
   */
  rtb_RelationalOperator9_pb = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 0);

  /* Logic: '<S787>/Logical Operator6' incorporates:
   *  Constant: '<S787>/Constant13'
   *  Constant: '<S787>/Constant17'
   *  Constant: '<S787>/Constant22'
   *  RelationalOperator: '<S787>/Relational Operator13'
   *  RelationalOperator: '<S787>/Relational Operator18'
   *  RelationalOperator: '<S787>/Relational Operator2'
   *  RelationalOperator: '<S787>/Relational Operator21'
   *  RelationalOperator: '<S787>/Relational Operator24'
   */
  rtb_LogicalOperator6_j = (rtb_LogicalOperator6_j && (LampCtl_VehSeekSta == 0) &&
    rtb_RelationalOperator3_pn && (LampCtl_PartArmedSta == 0) &&
    (!LampCtl_RodBeamFaultSta) && rtb_LogicalOperator4_m3 && (LampCtl_VehModeSta
    == 0) && (!LampCtl_TrunkWarnSta));

  /* RelationalOperator: '<S792>/Relational Operator' incorporates:
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S792>/Relational Operator5'
   */
  rtb_RelationalOperator_ol_tmp =
    Rte_IRead_Runbl_AppSwcBcm_50ms_FCLL_TiWngSt_FCLL_TiWngSt();

  /* Logic: '<S792>/Logical Operator4' incorporates:
   *  UnitDelay: '<S675>/Unit Delay16'
   */
  rtb_LogicalOperator4_m3 = (LampCtl_TurnIndcrLaneLSw &&
    AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE);

  /* Outputs for Enabled SubSystem: '<S792>/Enabled Subsystem3' incorporates:
   *  EnablePort: '<S865>/Enable'
   */
  if (rtb_LogicalOperator4_m3) {
    /* CCaller: '<S865>/C Caller' incorporates:
     *  Constant: '<S865>/Constant17'
     */
    LampCtl_TurnIndcrLVol = GetHw_TurnIndcrVol(0U);
  }

  /* End of Outputs for SubSystem: '<S792>/Enabled Subsystem3' */

  /* RelationalOperator: '<S792>/Relational Operator3' */
  rtb_RelationalOperator3_pn = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0);

  /* Chart: '<S792>/TurnIndcrDig3' incorporates:
   *  Constant: '<S792>/Constant17'
   *  Constant: '<S792>/Constant21'
   *  Constant: '<S792>/Constant43'
   *  Constant: '<S792>/Constant44'
   *  Constant: '<S792>/Constant45'
   *  RelationalOperator: '<S792>/Relational Operator1'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_m3, LampCtl_TurnIndcrLVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_pn, LampCtl_Ts_C,
    LampCtl_TurnIndcrLOpenTimValid_C, LampCtl_TurnIndcrLOpenTimInValid_C,
    LampCtl_LOpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig3);

  /* Logic: '<S792>/Logical Operator' incorporates:
   *  Constant: '<S792>/Constant'
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S792>/Relational Operator'
   */
  LampCtl_TurnIndcrLOpen = ((rtb_RelationalOperator_ol_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* Chart: '<S792>/TurnIndcrDig2' incorporates:
   *  Constant: '<S792>/Constant10'
   *  Constant: '<S792>/Constant18'
   *  Constant: '<S792>/Constant19'
   *  Constant: '<S792>/Constant4'
   *  Constant: '<S792>/Constant9'
   *  RelationalOperator: '<S792>/Relational Operator4'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_m3, LampCtl_TurnIndcrLVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_pn, LampCtl_Ts_C,
    LampCtl_TurnIndcrLShortTimValid_C, LampCtl_TurnIndcrLShortTimInValid_C,
    LampCtl_LShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig2);

  /* Logic: '<S792>/Logical Operator2' incorporates:
   *  Constant: '<S792>/Constant7'
   *  RelationalOperator: '<S792>/Relational Operator5'
   */
  LampCtl_TurnIndcrLShort = ((rtb_RelationalOperator_ol_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_c);

  /* RelationalOperator: '<S792>/Relational Operator2' incorporates:
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S792>/Relational Operator6'
   */
  rtb_RelationalOperator_ol_tmp =
    Rte_IRead_Runbl_AppSwcBcm_50ms_FCLR_TiWngSt_FCLR_TiWngSt();

  /* Logic: '<S792>/Logical Operator5' incorporates:
   *  UnitDelay: '<S675>/Unit Delay17'
   */
  rtb_LogicalOperator4_m3 = (LampCtl_TurnIndcrLaneRSw &&
    AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE);

  /* Outputs for Enabled SubSystem: '<S792>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S864>/Enable'
   */
  if (rtb_LogicalOperator4_m3) {
    /* CCaller: '<S864>/C Caller' incorporates:
     *  Constant: '<S864>/Constant17'
     */
    LampCtl_TurnIndcrRVol = GetHw_TurnIndcrVol(1U);
  }

  /* End of Outputs for SubSystem: '<S792>/Enabled Subsystem1' */

  /* Chart: '<S792>/TurnIndcrDig' incorporates:
   *  Constant: '<S792>/Constant11'
   *  Constant: '<S792>/Constant2'
   *  Constant: '<S792>/Constant3'
   *  Constant: '<S792>/Constant6'
   *  Constant: '<S792>/Constant8'
   *  RelationalOperator: '<S792>/Relational Operator7'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_m3, LampCtl_TurnIndcrRVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_pn, LampCtl_Ts_C,
    LampCtl_TurnIndcrROpenTimValid_C, LampCtl_TurnIndcrROpenTimInValid_C,
    LampCtl_ROpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig);

  /* Logic: '<S792>/Logical Operator1' incorporates:
   *  Constant: '<S792>/Constant5'
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S792>/Relational Operator2'
   */
  LampCtl_TurnIndcrROpen = ((rtb_RelationalOperator_ol_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_o);

  /* Chart: '<S792>/TurnIndcrDig1' incorporates:
   *  Constant: '<S792>/Constant12'
   *  Constant: '<S792>/Constant13'
   *  Constant: '<S792>/Constant14'
   *  Constant: '<S792>/Constant16'
   *  Constant: '<S792>/Constant20'
   *  RelationalOperator: '<S792>/Relational Operator8'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_m3, LampCtl_TurnIndcrRVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_pn, LampCtl_Ts_C,
    LampCtl_TurnIndcrRShortTimValid_C, LampCtl_TurnIndcrRShortTimInValid_C,
    LampCtl_RShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig1);

  /* Logic: '<S792>/Logical Operator3' incorporates:
   *  Constant: '<S792>/Constant15'
   *  RelationalOperator: '<S792>/Relational Operator6'
   */
  LampCtl_TurnIndcrRShort = ((rtb_RelationalOperator_ol_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_g);

  /* Chart: '<S675>/TurnIndcrArb2' incorporates:
   *  Logic: '<S787>/Logical Operator'
   *  Logic: '<S787>/Logical Operator2'
   *  Logic: '<S787>/Logical Operator3'
   *  Logic: '<S787>/Logical Operator4'
   *  Logic: '<S787>/Logical Operator5'
   *  Logic: '<S787>/Logical Operator7'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c114_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c114_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Trans_m;
    AppSwcBcm_EnFunc();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib) {
     case AppSwcBcm_IN_Pri1:
      if (!RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Trans_m;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri2:
      if (rtb_RelationalOperator5_lq || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Trans_m;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri2Func();
      }
      break;

     case AppSwcBcm_IN_Pri3:
      if (rtb_RelationalOperator7_is || rtb_LogicalOperator8_h2) {
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Trans_m;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri4:
      if (rtb_RelationalOperator9_pb || RelationalOperator6 ||
          rtb_RelationalOperator6 || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Trans_m;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri4Func();
      }
      break;

     case AppSwcBcm_IN_Pri5:
      if (rtb_LogicalOperator6_j || rtb_LogicalOperator1_ij) {
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_NO_ACTIVE_CHILD_h;
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Trans_m;
        AppSwcBcm_EnFunc();
      } else {
        switch (AppSwcBcm_ARID_DEF.is_Pri5) {
         case AppSwcBcm_IN_AntiLck:
          if (!LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_AntiLckFunc();
          }
          break;

         case AppSwcBcm_IN_Armed_p:
          if (!LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_ArmedFunc();
          }
          break;

         case AppSwcBcm_IN_Disarmed_k:
          if (!LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_DisarmedFunc();
          }
          break;

         case AppSwcBcm_IN_PartArmed_a:
          if (LampCtl_PartArmedSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_PartArmedFunc();
          }
          break;

         case AppSwcBcm_IN_RodBeam:
          if (!LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_RodBeamFunc();
          }
          break;

         case AppSwcBcm_IN_Seek:
          if (LampCtl_VehSeekSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_SeekFunc();
          }
          break;

         case AppSwcBcm_IN_Trans_mc:
          if (LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Armed_p;
            AppSwcBcm_ArmedFunc();
          } else if (LampCtl_PartArmedSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_PartArmed_a;
            AppSwcBcm_PartArmedFunc();
          } else if (LampCtl_VehSeekSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Seek;
            AppSwcBcm_SeekFunc();
          } else if (LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Disarmed_k;
            AppSwcBcm_DisarmedFunc();
          } else if (LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_RodBeam;
            AppSwcBcm_RodBeamFunc();
          } else if (LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_AntiLck;
            AppSwcBcm_AntiLckFunc();
          } else if (LampCtl_VehModeSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_VehMode;
            AppSwcBcm_VehModeFunc();
          } else if (LampCtl_TrunkWarnSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_TrunkWarn;
            AppSwcBcm_TrunkWarnFunc();
          }
          break;

         case AppSwcBcm_IN_TrunkWarn:
          if (!LampCtl_TrunkWarnSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_TrunkWarnFunc();
          }
          break;

         default:
          /* case IN_VehMode: */
          if (LampCtl_VehModeSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
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
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Pri1;
      } else if (rtb_RelationalOperator6) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Pri2;
      } else if (RelationalOperator6) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Pri3;
      } else if (RelationalOperator8_l) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Pri4;
      } else if (rtb_RelationalOperator_fx || rtb_RelationalOperator11_g ||
                 rtb_RelationalOperator14_j || rtb_LogicalOperator10_k ||
                 rtb_RelationalOperator1_lz || rtb_RelationalOperator19 ||
                 rtb_LogicalOperator9 || rtb_RelationalOperator23) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c114_LampCtl_Lib = AppSwcBcm_IN_Pri5;
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_mc;
        AppSwcBcm_TurnFunc();
      }
      break;
    }
  }

  /* End of Chart: '<S675>/TurnIndcrArb2' */
  AppSwcBcm_ARID_DEF.Lib_blIn_i = LampCtl_TurnIndcrRst;

  /* Chart: '<S795>/LIB_Pulse' incorporates:
   *  SubSystem: '<S877>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_i,
    &AppSwcBcm_ARID_DEF.RelationalOperator_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_i) {
    AppSwcBcm_ARID_DEF.cnt = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  if (LampCtl_TurnIndcrRFlashCnt >= 1) {
    if (LampCtl_TurnIndcrRFlashCnt >= 65535) {
      LampCtl_PrdSucCntR = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_n = (AppSwcBcm_ARID_DEF.cnt <
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
      AppSwcBcm_ARID_DEF.LIB_blOut_n = (AppSwcBcm_ARID_DEF.cnt <
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
    AppSwcBcm_ARID_DEF.LIB_blOut_n = false;
    AppSwcBcm_ARID_DEF.cnt = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  /* Logic: '<S675>/Logical Operator' incorporates:
   *  UnitDelay: '<S675>/Unit Delay17'
   */
  AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE = (AppSwcBcm_ARID_DEF.LIB_blOut_n &&
    rtb_RelationalOperator5_ek);
  AppSwcBcm_ARID_DEF.Lib_blIn_bn = LampCtl_TurnIndcrRst;

  /* Chart: '<S793>/LIB_Pulse' incorporates:
   *  SubSystem: '<S870>/Lib_BothEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S871>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_bn,
    &AppSwcBcm_ARID_DEF.LogicalOperator2_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet_l);

  /* End of Outputs for SubSystem: '<S871>/Lib_BothEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator2_h) {
    AppSwcBcm_ARID_DEF.cnt_k = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  if (LampCtl_TurnIndcrLFlashCnt >= 1) {
    if (LampCtl_TurnIndcrLFlashCnt >= 65535) {
      LampCtl_PrdSucCntL = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_g = (AppSwcBcm_ARID_DEF.cnt_k <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_k >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_k = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.cnt_k + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_k = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntL < LampCtl_TurnIndcrLFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_g = (AppSwcBcm_ARID_DEF.cnt_k <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_k >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_k = 0U;
        tmp = LampCtl_PrdSucCntL + 1;
        if (LampCtl_PrdSucCntL + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntL = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.cnt_k + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_k = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_g = false;
    AppSwcBcm_ARID_DEF.cnt_k = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  /* Logic: '<S675>/Logical Operator1' incorporates:
   *  UnitDelay: '<S675>/Unit Delay16'
   */
  AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE = (rtb_RelationalOperator5_ek &&
    AppSwcBcm_ARID_DEF.LIB_blOut_g);

  /* Chart: '<S798>/SeekFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c142_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c142_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib = AppSwcBcm_IN_Init_d;
    LampCtl_VehSeekStaFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_a4 = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib) {
     case AppSwcBcm_IN_Fail_a:
      LampCtl_VehSeekStaFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_a4 >= LampCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib = AppSwcBcm_IN_Init_d;
        LampCtl_VehSeekStaFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_a4 = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_a4 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_a4 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_a4 = (uint8)tmp;
      }
      break;

     case AppSwcBcm_IN_Init_d:
      LampCtl_VehSeekStaFb = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_a =
        (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtCarSearch_enum == 1) ||
         ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBoxRmtCarSearch_enum == 2));

      /* Outputs for Function Call SubSystem: '<S888>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_a,
        &AppSwcBcm_ARID_DEF.LogicalOperator_fg,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_j);

      /* End of Outputs for SubSystem: '<S888>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_fg) {
        AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib = AppSwcBcm_IN_Wait_a;
      }
      break;

     case AppSwcBcm_IN_Suc_a:
      LampCtl_VehSeekStaFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_a4 >= LampCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib = AppSwcBcm_IN_Init_d;
        LampCtl_VehSeekStaFb = 0U;
        AppSwcBcm_ARID_DEF.Cnt_a4 = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_a4 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_a4 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_a4 = (uint8)tmp;
      }
      break;

     default:
      /* case IN_Wait: */
      if (LampCtl_VehSeekSta == 2) {
        AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib = AppSwcBcm_IN_Suc_a;
        LampCtl_VehSeekStaFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_a4 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_a4 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_a4 = (uint8)tmp;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_TBoxRmtCarSearch_enum == 0) {
        AppSwcBcm_ARID_DEF.is_c142_LampCtl_Lib = AppSwcBcm_IN_Fail_a;
        LampCtl_VehSeekStaFb = 3U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_a4 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_a4 + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_a4 = (uint8)tmp;
      }
      break;
    }
  }

  /* End of Chart: '<S798>/SeekFb' */

  /* Chart: '<S782>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Inport: '<Root>/IPM_SRS_1_Status_CHA'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c93_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c93_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib = AppSwcBcm_IN_Init_l0;
    AppSwcBcm_ARID_DEF.PwrOnFlg = false;
    AppSwcBcm_ARID_DEF.DelayCnt = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib) {
     case AppSwcBcm_IN_CrashOff:
      if (AppSwcBcm_ARID_DEF.PwrOnFlg ||
          (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0)) {
        AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib = AppSwcBcm_IN_Init_l0;
        AppSwcBcm_ARID_DEF.PwrOnFlg = false;
        AppSwcBcm_ARID_DEF.DelayCnt = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_mg =
          (((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 1) ||
           ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 2) ||
           ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 4) ||
           ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
             ())->VIPM_SRSCrashOutputSts_enum == 5));

        /* Outputs for Function Call SubSystem: '<S806>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_mg,
          &AppSwcBcm_ARID_DEF.LogicalOperator_i0,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_b);

        /* End of Outputs for SubSystem: '<S806>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_i0) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_p0 = (BSW_CrashPWMSta == 1);

          /* Outputs for Function Call SubSystem: '<S806>/Lib_RiseEdgeDet2' */
          AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_p0,
            &AppSwcBcm_ARID_DEF.LogicalOperator_go,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_e);

          /* End of Outputs for SubSystem: '<S806>/Lib_RiseEdgeDet2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_go) {
            guard1 = true;
          }
        }
      }
      break;

     case AppSwcBcm_IN_CrashOn:
      if (AppSwcBcm_ARID_DEF.PwrOffFlg && AppSwcBcm_ARID_DEF.PwrOnFlg) {
        AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
        LampCtl_CrashSta = false;
        AppSwcBcm_ARID_DEF.PwrOffFlg = false;
        AppSwcBcm_ARID_DEF.ClearCnt = 0U;
      } else {
        AppSwcBcm_CrashClearFunc();
        AppSwcBcm_ARID_DEF.Lib_blIn_px =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->CrashSta == 1);

        /* Outputs for Function Call SubSystem: '<S806>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_px,
          &AppSwcBcm_ARID_DEF.LogicalOperator_i,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_da);

        /* End of Outputs for SubSystem: '<S806>/Lib_RiseEdgeDet1' */
      }
      break;

     default:
      /* case IN_Init: */
      AppSwcBcm_ARID_DEF.Lib_blIn_px =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->CrashSta == 1);

      /* Outputs for Function Call SubSystem: '<S806>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_px,
        &AppSwcBcm_ARID_DEF.LogicalOperator_i,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_da);

      /* End of Outputs for SubSystem: '<S806>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_i) {
        AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
        LampCtl_CrashSta = true;
      } else if (AppSwcBcm_ARID_DEF.DelayCnt >= 80) {
        AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
        LampCtl_CrashSta = false;
        AppSwcBcm_ARID_DEF.PwrOffFlg = false;
        AppSwcBcm_ARID_DEF.ClearCnt = 0U;
      } else {
        AppSwcBcm_PwrOnDelayFunc();
      }
      break;
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c93_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
      LampCtl_CrashSta = true;
    }
  }

  /* End of Chart: '<S782>/Chart1' */

  /* Chart: '<S789>/Chart' incorporates:
   *  Inport: '<Root>/IPM_BMS_1_MainState_EPT'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c98_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c98_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c98_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
    LampCtl_ThermalrunawaySta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c98_LampCtl_Lib == AppSwcBcm_IN_SetOff_d) {
    AppSwcBcm_ARID_DEF.Lib_blIn_id =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
        ())->VIPM_BMSThermrunawayWrn_enum == 1);

    /* Outputs for Function Call SubSystem: '<S840>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_id,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ps,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nu);

    /* End of Outputs for SubSystem: '<S840>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ps) {
      AppSwcBcm_ARID_DEF.is_c98_LampCtl_Lib = AppSwcBcm_IN_SetOn_j;
    }
  } else {
    /* case IN_SetOn: */
    guard1 = false;
    if ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
         ())->VIPM_BMSThermrunawayWrn_enum == 0) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_m = LampCtl_HazardLightSw;

      /* Outputs for Function Call SubSystem: '<S840>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_p(AppSwcBcm_ARID_DEF.Lib_blIn_m,
        &AppSwcBcm_ARID_DEF.LogicalOperator_lb,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_b);

      /* End of Outputs for SubSystem: '<S840>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_lb) {
        guard1 = true;
      } else {
        LampCtl_ThermalrunawaySta = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c98_LampCtl_Lib = AppSwcBcm_IN_SetOff_d;
      LampCtl_ThermalrunawaySta = false;
    }
  }

  /* End of Chart: '<S789>/Chart' */

  /* Update for UnitDelay: '<S675>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S675>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_k = LampCtl_CrashSta;

  /* Update for UnitDelay: '<S675>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_od = LampCtl_ThermalrunawaySta;

  /* Update for UnitDelay: '<S675>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S675>/Unit Delay11' */
  AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay10' */
  AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S675>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S675>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_m = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S675>/Unit Delay13' */
  AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay12' */
  AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S675>/Unit Delay15' */
  AppSwcBcm_ARID_DEF.UnitDelay15_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S675>/Unit Delay14' */
  AppSwcBcm_ARID_DEF.UnitDelay14_DSTATE = LampCtl_PrdSucCntR;
}

/* Output and update for atomic system: '<S896>/Lib_RiseEdgeDet' */
static void AppSwcBcm_Lib_RiseEdgeDet_g(void)
{
  /* Logic: '<S905>/Logical Operator' incorporates:
   *  Logic: '<S905>/Logical Operator1'
   *  UnitDelay: '<S905>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_k = (AppSwcBcm_ARID_DEF.LIB_blOut_e &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_br));

  /* Update for UnitDelay: '<S905>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_br = AppSwcBcm_ARID_DEF.LIB_blOut_e;
}

/* Outputs for atomic system: '<S900>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge_f(void)
{
  boolean rtb_RelationalOperator1_by;

  /* RelationalOperator: '<S909>/Relational Operator1' incorporates:
   *  Constant: '<S900>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_by = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus
    ())->BodyWarnSts == 1);

  /* Logic: '<S968>/Logical Operator10' incorporates:
   *  Constant: '<S900>/Constant4'
   *  Logic: '<S909>/Logical Operator'
   *  RelationalOperator: '<S909>/Relational Operator'
   *  UnitDelay: '<S909>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator1_by &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bh == 0));
}

/* Update for atomic system: '<S900>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge_i_Update(void)
{
  /* Update for UnitDelay: '<S909>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bh =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->BodyWarnSts;
}

/* System initialize for atomic system: '<S435>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j;

  /* InitializeConditions for UnitDelay: '<S676>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = 60U;

  /* InitializeConditions for Delay: '<S897>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_o = true;

  /* SystemInitialize for Chart: '<S896>/LIB_PosPluseInit' incorporates:
   *  SubSystem: '<S904>/Lib_RiseEdgeDet'
   */

  /* SystemInitialize for Atomic SubSystem: '<S906>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S906>/Lib_RiseEdgeDetInit' */

  /* SystemInitialize for Chart: '<S900>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_j);

  /* SystemInitialize for Chart: '<S901>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut);
}

/* Outputs for atomic system: '<S435>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j;
  sint32 tmp;
  uint8 rtb_Switch;
  boolean rtb_LIB_blOut_l;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator1_k1;

  /* Chart: '<S895>/LIB_Tim' incorporates:
   *  Constant: '<S895>/Constant5'
   *  Logic: '<S895>/Logical Operator1'
   *  Logic: '<S895>/Logical Operator2'
   *  Product: '<S895>/Product'
   *  RelationalOperator: '<S895>/Relational Operator3'
   *  UnitDelay: '<S676>/Unit Delay1'
   *  UnitDelay: '<S676>/Unit Delay2'
   */
  if ((!AppSwcBcm_ARID_DEF.BusCreator4.OsLck) &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_fs) {
    if (AppSwcBcm_ARID_DEF.Cnt_h <= (uint16)(20U *
         AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE)) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_h + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_h + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_h = (uint16)tmp;
      rtb_LIB_blOut_l = false;
    } else {
      rtb_LIB_blOut_l = true;
    }
  } else {
    rtb_LIB_blOut_l = false;
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  }

  /* End of Chart: '<S895>/LIB_Tim' */

  /* RelationalOperator: '<S895>/Relational Operator1' incorporates:
   *  Constant: '<S895>/Constant1'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator1 = (LampCtl_VehSeekSta == 1);

  /* Outputs for Atomic SubSystem: '<S895>/Lib_RiseEdgeDet3' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet
    (AppSwcBcm_ARID_DEF.RelationalOperator1,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3);

  /* End of Outputs for SubSystem: '<S895>/Lib_RiseEdgeDet3' */

  /* Switch: '<S897>/Switch' incorporates:
   *  Constant: '<S897>/Constant5'
   *  RelationalOperator: '<S897>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) {
    /* Switch: '<S897>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUFlwrMeHmCtrl_enum;
  } else {
    /* Switch: '<S897>/Switch' incorporates:
     *  Constant: '<S897>/Constant11'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S897>/Switch' */

  /* RelationalOperator: '<S901>/Relational Operator1' incorporates:
   *  Constant: '<S897>/Constant12'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S897>/Relational Operator1'
   */
  rtb_RelationalOperator1_k1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus
    ())->FlwrMeHomeCtlFb == 255);

  /* Switch: '<S897>/Switch1' */
  if (rtb_RelationalOperator1_k1) {
    /* Switch: '<S897>/Switch1' incorporates:
     *  Constant: '<S897>/Constant13'
     */
    AppSwcBcm_ARID_DEF.Switch1 = 0U;
  } else {
    /* Switch: '<S897>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    AppSwcBcm_ARID_DEF.Switch1 =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->FlwrMeHomeCtlFb;
  }

  /* End of Switch: '<S897>/Switch1' */

  /* Delay: '<S897>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_o) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE = AppSwcBcm_ARID_DEF.Switch1;
  }

  /* MultiPortSwitch: '<S897>/Multiport Switch1' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S897>/Multiport Switch1' incorporates:
     *  Constant: '<S897>/Constant6'
     */
    LampCtl_FlwrMeHomeCtlFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S897>/Multiport Switch1' incorporates:
     *  Constant: '<S897>/Constant7'
     */
    LampCtl_FlwrMeHomeCtlFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S897>/Multiport Switch1' incorporates:
     *  Constant: '<S897>/Constant8'
     */
    LampCtl_FlwrMeHomeCtlFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S897>/Multiport Switch1' incorporates:
     *  Constant: '<S897>/Constant9'
     */
    LampCtl_FlwrMeHomeCtlFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S897>/Multiport Switch1' incorporates:
     *  Constant: '<S897>/Constant10'
     */
    LampCtl_FlwrMeHomeCtlFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S897>/Multiport Switch1' incorporates:
     *  Delay: '<S897>/Delay'
     */
    LampCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.Delay_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S897>/Multiport Switch1' */

  /* RelationalOperator: '<S901>/Relational Operator1' incorporates:
   *  Constant: '<S896>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S896>/Relational Operator3'
   */
  rtb_RelationalOperator1_k1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus
    ())->BodyWarnSts == 1);

  /* Logic: '<S896>/Logical Operator2' incorporates:
   *  Constant: '<S896>/Constant1'
   *  Constant: '<S896>/Constant4'
   *  RelationalOperator: '<S896>/Relational Operator1'
   *  RelationalOperator: '<S896>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_f = ((LampCtl_FlwrMeHomeCtlFb != 0) &&
    (LampCtl_LightIntstSta == 2) && rtb_RelationalOperator1_k1);
  AppSwcBcm_ARID_DEF.Lib_blInit = AppSwcBcm_ARID_DEF.Lib_blIn_f;

  /* Chart: '<S896>/LIB_PosPluseInit' incorporates:
   *  SubSystem: '<S904>/Lib_RiseEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S906>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_f,
    AppSwcBcm_ARID_DEF.Lib_blInit, &AppSwcBcm_ARID_DEF.LogicalOperator_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S906>/Lib_RiseEdgeDetInit' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_a) {
    AppSwcBcm_ARID_DEF.Flg_h = true;
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
  }

  /* Logic: '<S896>/Logical Operator' */
  if (!AppSwcBcm_ARID_DEF.Lib_blIn_f) {
    AppSwcBcm_ARID_DEF.Flg_h = false;
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
  }

  /* End of Logic: '<S896>/Logical Operator' */
  if (AppSwcBcm_ARID_DEF.Flg_h) {
    /* Constant: '<S896>/Constant43' */
    if (AppSwcBcm_ARID_DEF.Cnt_i >= LampCtl_FlwrMeHomeTimValid_C) {
      AppSwcBcm_ARID_DEF.LIB_blOut_e = true;
      AppSwcBcm_ARID_DEF.Flg_h = false;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_i++;
      AppSwcBcm_ARID_DEF.LIB_blOut_e = false;
    }

    /* End of Constant: '<S896>/Constant43' */
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_e = false;
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S896>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_g();

  /* End of Outputs for SubSystem: '<S896>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S676>/Lib_SR1' */
  /* Switch: '<S899>/Switch' incorporates:
   *  Constant: '<S895>/Constant'
   *  Logic: '<S895>/Logical Operator'
   *  RelationalOperator: '<S895>/Relational Operator'
   *  RelationalOperator: '<S895>/Relational Operator2'
   */
  if (rtb_LIB_blOut_l || (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2) ||
      AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck || rtb_LogicalOperator) {
    /* Switch: '<S899>/Switch' incorporates:
     *  Constant: '<S899>/Constant'
     */
    LampCtl_FlwrMeHomeSta = false;
  } else {
    /* Switch: '<S899>/Switch' incorporates:
     *  Logic: '<S899>/Logical Operator'
     *  UnitDelay: '<S899>/Unit Delay'
     */
    LampCtl_FlwrMeHomeSta = (AppSwcBcm_ARID_DEF.LogicalOperator_k ||
      LampCtl_FlwrMeHomeSta);
  }

  /* End of Switch: '<S899>/Switch' */
  /* End of Outputs for SubSystem: '<S676>/Lib_SR1' */

  /* MultiPortSwitch: '<S897>/Multiport Switch' */
  switch (LampCtl_FlwrMeHomeCtlFb) {
   case 0:
    /* MultiPortSwitch: '<S897>/Multiport Switch' incorporates:
     *  Constant: '<S897>/Constant4'
     */
    LampCtl_FlwrMeHomeTim = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S897>/Multiport Switch' incorporates:
     *  Constant: '<S897>/Constant'
     */
    LampCtl_FlwrMeHomeTim = 30U;
    break;

   case 2:
    /* MultiPortSwitch: '<S897>/Multiport Switch' incorporates:
     *  Constant: '<S897>/Constant1'
     */
    LampCtl_FlwrMeHomeTim = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S897>/Multiport Switch' incorporates:
     *  Constant: '<S897>/Constant2'
     */
    LampCtl_FlwrMeHomeTim = 90U;
    break;

   case 4:
    /* MultiPortSwitch: '<S897>/Multiport Switch' incorporates:
     *  Constant: '<S897>/Constant3'
     */
    LampCtl_FlwrMeHomeTim = 120U;
    break;
  }

  /* End of MultiPortSwitch: '<S897>/Multiport Switch' */

  /* Chart: '<S900>/LIB_Tim' incorporates:
   *  Constant: '<S900>/Constant6'
   *  Logic: '<S900>/Logical Operator1'
   *  Logic: '<S900>/Logical Operator2'
   *  RelationalOperator: '<S900>/Relational Operator2'
   *  UnitDelay: '<S676>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse((!AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fr, LampCtl_WelcomeLampTimMax_C,
    &rtb_LIB_blOut_j, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim);

  /* Outputs for Atomic SubSystem: '<S900>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge_f();

  /* End of Outputs for SubSystem: '<S900>/Lib_ChangeEdge' */

  /* RelationalOperator: '<S901>/Relational Operator1' incorporates:
   *  Constant: '<S901>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_k1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus
    ())->BodyWarnSts == 1);

  /* Chart: '<S901>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S901>/Constant'
   *  Constant: '<S901>/Constant3'
   *  Logic: '<S901>/Logical Operator1'
   *  RelationalOperator: '<S901>/Relational Operator'
   *  RelationalOperator: '<S901>/Relational Operator2'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(rtb_RelationalOperator1_k1 &&
    AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck &&
    (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0), LampCtl_OsUnlckDelayTim_C,
    &AppSwcBcm_ARID_DEF.LIB_blOut,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay);

  /* Outputs for Atomic SubSystem: '<S676>/Lib_SR' */
  /* Switch: '<S898>/Switch' incorporates:
   *  Constant: '<S900>/Constant1'
   *  Logic: '<S900>/Logical Operator'
   *  RelationalOperator: '<S900>/Relational Operator1'
   */
  if (rtb_LIB_blOut_j || AppSwcBcm_ARID_DEF.LogicalOperator10 ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2)) {
    /* Switch: '<S898>/Switch' incorporates:
     *  Constant: '<S898>/Constant'
     */
    LampCtl_WelcomeLampSta = false;
  } else {
    /* Switch: '<S898>/Switch' incorporates:
     *  Constant: '<S901>/Constant4'
     *  Logic: '<S898>/Logical Operator'
     *  Logic: '<S901>/Logical Operator2'
     *  RelationalOperator: '<S901>/Relational Operator4'
     *  UnitDelay: '<S898>/Unit Delay'
     */
    LampCtl_WelcomeLampSta = ((AppSwcBcm_ARID_DEF.LIB_blOut &&
      (LampCtl_LightIntstSta == 2)) || LampCtl_WelcomeLampSta);
  }

  /* End of Switch: '<S898>/Switch' */
  /* End of Outputs for SubSystem: '<S676>/Lib_SR' */
}

/* Update for atomic system: '<S435>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Update(void)
{
  /* Update for UnitDelay: '<S676>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_fs = LampCtl_FlwrMeHomeSta;

  /* Update for UnitDelay: '<S676>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = LampCtl_FlwrMeHomeTim;

  /* Update for Delay: '<S897>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_o = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE = LampCtl_FlwrMeHomeCtlFb;

  /* Update for UnitDelay: '<S676>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fr = LampCtl_WelcomeLampSta;

  /* Update for Atomic SubSystem: '<S900>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge_i_Update();

  /* End of Update for SubSystem: '<S900>/Lib_ChangeEdge' */
}

/* System initialize for atomic system: '<S4>/LampCtl' */
static void AppSwcBcm_LampCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S435>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/ADASLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/AutoLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/BackLampCtl' */
  AppSwcBcm_BackLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/BackLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/BoxLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/DomeLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/LampDelayCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/LowBeamCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/PosLampCtl' */
  AppSwcBcm_PosLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/PosLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/SignalProcess' */
  AppSwcBcm_SignalProcess_p_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/SignalProcess' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/TurnIndcrCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S435>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S435>/WelcomeLampCtl' */
}

/* Outputs for atomic system: '<S4>/LampCtl' */
static void AppSwcBcm_LampCtl(void)
{
  boolean rtb_DataTypeConversion3_g;

  /* Outputs for Atomic SubSystem: '<S435>/OTAPwrOffLight' */
  AppSwcBcm_OTAPwrOffLight();

  /* End of Outputs for SubSystem: '<S435>/OTAPwrOffLight' */

  /* Outputs for Atomic SubSystem: '<S435>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl();

  /* End of Outputs for SubSystem: '<S435>/ADASLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd3' */
  /* Switch: '<S664>/Switch1' incorporates:
   *  Constant: '<S435>/Constant5'
   */
  if (LampCtl_J420BSDRightCtlOvrdFlg_C) {
    /* Switch: '<S664>/Switch1' incorporates:
     *  Constant: '<S435>/Constant6'
     */
    LampCtl_J420BSDRightCtl = LampCtl_J420BSDRightCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion3' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BSDRightCtlFlg != 0);

    /* Switch: '<S664>/Switch1' incorporates:
     *  Switch: '<S664>/Switch2'
     */
    LampCtl_J420BSDRightCtl = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl);
  }

  /* End of Switch: '<S664>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd4' */
  /* Switch: '<S665>/Switch1' incorporates:
   *  Constant: '<S435>/Constant7'
   */
  if (LampCtl_J422BSDLeftCtlOvrdFlg_C) {
    /* Switch: '<S665>/Switch1' incorporates:
     *  Constant: '<S435>/Constant8'
     */
    LampCtl_J422BSDLeftCtl = LampCtl_J422BSDLeftCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion4' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BSDLeftCtlFlg != 0);

    /* Switch: '<S665>/Switch1' incorporates:
     *  Switch: '<S665>/Switch2'
     */
    LampCtl_J422BSDLeftCtl = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl);
  }

  /* End of Switch: '<S665>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd4' */

  /* Outputs for Atomic SubSystem: '<S435>/SignalProcess' */
  AppSwcBcm_SignalProcess_n();

  /* End of Outputs for SubSystem: '<S435>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S435>/BrakeLampCtl' */
  AppSwcBcm_BrakeLampCtl();

  /* End of Outputs for SubSystem: '<S435>/BrakeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd2' */
  /* Switch: '<S663>/Switch1' incorporates:
   *  Constant: '<S435>/Constant3'
   */
  if (LampCtl_BrakeLightStaOvrdFlg_C) {
    /* Switch: '<S663>/Switch1' incorporates:
     *  Constant: '<S435>/Constant4'
     */
    LampCtl_BrakeLightSta = LampCtl_BrakeLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BrakeLightCtlFlg != 0);

    /* Switch: '<S663>/Switch1' incorporates:
     *  Switch: '<S663>/Switch2'
     */
    LampCtl_BrakeLightSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LogicalOperator6);
  }

  /* End of Switch: '<S663>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S435>/PassLampFunc' */
  AppSwcBcm_PassLampFunc();

  /* End of Outputs for SubSystem: '<S435>/PassLampFunc' */

  /* Outputs for Atomic SubSystem: '<S435>/LightIntstDet' */
  AppSwcBcm_LightIntstDet();

  /* End of Outputs for SubSystem: '<S435>/LightIntstDet' */

  /* Outputs for Atomic SubSystem: '<S435>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl();

  /* End of Outputs for SubSystem: '<S435>/AutoLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/KnobBeamDig' */
  AppSwcBcm_KnobBeamDig();

  /* End of Outputs for SubSystem: '<S435>/KnobBeamDig' */

  /* Outputs for Atomic SubSystem: '<S435>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl();

  /* End of Outputs for SubSystem: '<S435>/LampDelayCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl();

  /* End of Outputs for SubSystem: '<S435>/LowBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd5' */
  /* Switch: '<S666>/Switch1' incorporates:
   *  Constant: '<S435>/Constant10'
   *  Constant: '<S435>/Constant9'
   *  Switch: '<S666>/Switch2'
   */
  if (LampCtl_LowBeamStaOvrdFlg_C) {
    LampCtl_LowBeamSta = LampCtl_LowBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->LowBeamCtlFlg != 0);
    LampCtl_LowBeamSta = (rtb_DataTypeConversion3_g ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_c);
  }

  /* End of Switch: '<S666>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S435>/AutoHiBeamCtl' */
  AppSwcBcm_AutoHiBeamCtl();

  /* End of Outputs for SubSystem: '<S435>/AutoHiBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/HiBeamCtl' */
  AppSwcBcm_HiBeamCtl();

  /* End of Outputs for SubSystem: '<S435>/HiBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd9' */
  /* Switch: '<S670>/Switch1' incorporates:
   *  Constant: '<S435>/Constant20'
   */
  if (LampCtl_HiBeamStaOvrdFlg_C) {
    /* Switch: '<S670>/Switch1' incorporates:
     *  Constant: '<S435>/Constant17'
     */
    LampCtl_HiBeamSta = LampCtl_HiBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion9' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->HiBeamCtlFlg != 0);

    /* Switch: '<S670>/Switch1' incorporates:
     *  Switch: '<S670>/Switch2'
     */
    LampCtl_HiBeamSta = (rtb_DataTypeConversion3_g ||
                         AppSwcBcm_ARID_DEF.LogicalOperator_lw);
  }

  /* End of Switch: '<S670>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd9' */

  /* Outputs for Atomic SubSystem: '<S435>/PosLampCtl' */
  AppSwcBcm_PosLampCtl();

  /* End of Outputs for SubSystem: '<S435>/PosLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd' */
  /* Switch: '<S656>/Switch1' incorporates:
   *  Constant: '<S435>/Constant18'
   *  Constant: '<S435>/Constant19'
   *  Switch: '<S656>/Switch2'
   */
  if (LampCtl_PosLampStaOvrdFlg_C) {
    LampCtl_PosLampSta = LampCtl_PosLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->PosLampCtlFlg != 0);
    LampCtl_PosLampSta = (rtb_DataTypeConversion3_g ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_j);
  }

  /* End of Switch: '<S656>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd' */

  /* Outputs for Atomic SubSystem: '<S435>/BackLampCtl' */
  AppSwcBcm_BackLampCtl();

  /* End of Outputs for SubSystem: '<S435>/BackLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd14' */
  /* Switch: '<S662>/Switch1' incorporates:
   *  Constant: '<S435>/Constant30'
   */
  if (LampCtl_J408BackLampPWMOvrdFlg_C) {
    /* Switch: '<S662>/Switch1' incorporates:
     *  Constant: '<S435>/Constant29'
     */
    LampCtl_J408BackLampPWM = LampCtl_J408BackLampPWMOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion14' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BackLampCtlFlg != 0);

    /* Switch: '<S662>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S662>/Switch1' incorporates:
       *  Constant: '<S435>/Constant32'
       */
      LampCtl_J408BackLampPWM = 100U;
    } else {
      /* Switch: '<S662>/Switch1' */
      LampCtl_J408BackLampPWM = AppSwcBcm_ARID_DEF.Switch_b;
    }

    /* End of Switch: '<S662>/Switch2' */
  }

  /* End of Switch: '<S662>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd14' */

  /* Outputs for Atomic SubSystem: '<S435>/DayRunLampCtl' */
  AppSwcBcm_DayRunLampCtl();

  /* End of Outputs for SubSystem: '<S435>/DayRunLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd1' */
  /* Switch: '<S657>/Switch1' incorporates:
   *  Constant: '<S435>/Constant1'
   */
  if (LampCtl_DayRunLightStaOvrdFlg_C) {
    /* Switch: '<S657>/Switch1' incorporates:
     *  Constant: '<S435>/Constant2'
     */
    LampCtl_DayRunLightSta = LampCtl_DayRunLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DayRunLightCtlFlg != 0);

    /* Switch: '<S657>/Switch1' incorporates:
     *  Switch: '<S657>/Switch2'
     *  UnitDelay: '<S699>/Unit Delay'
     */
    LampCtl_DayRunLightSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ng);
  }

  /* End of Switch: '<S657>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S435>/FogLampRCtl' */
  AppSwcBcm_FogLampRCtl();

  /* End of Outputs for SubSystem: '<S435>/FogLampRCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd6' */
  /* Switch: '<S667>/Switch1' incorporates:
   *  Constant: '<S435>/Constant12'
   */
  if (LampCtl_FogLampRStaOvrdFlg_C) {
    /* Switch: '<S667>/Switch1' incorporates:
     *  Constant: '<S435>/Constant11'
     */
    LampCtl_FogLampRSta = LampCtl_FogLampRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion6' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->FogLampRCtlFlg != 0);

    /* Switch: '<S667>/Switch1' incorporates:
     *  Switch: '<S667>/Switch2'
     */
    LampCtl_FogLampRSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LogicalOperator_b);
  }

  /* End of Switch: '<S667>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd6' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd7' */
  /* Switch: '<S668>/Switch1' incorporates:
   *  Constant: '<S435>/Constant14'
   */
  if (LampCtl_FogLampFStaOvrdFlg_C) {
    /* Switch: '<S668>/Switch1' incorporates:
     *  Constant: '<S435>/Constant13'
     */
    LampCtl_FogLampFSta = LampCtl_FogLampFStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion7' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->FogLampFCtlFlg != 0);

    /* Switch: '<S668>/Switch1' incorporates:
     *  Switch: '<S668>/Switch2'
     */
    LampCtl_FogLampFSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LogicalOperator1_i);
  }

  /* End of Switch: '<S668>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd7' */

  /* Outputs for Atomic SubSystem: '<S435>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl();

  /* End of Outputs for SubSystem: '<S435>/BoxLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd13' */
  /* Switch: '<S661>/Switch1' incorporates:
   *  Constant: '<S435>/Constant28'
   */
  if (LampCtl_J449BoxLampOvrdFlg_C) {
    /* Switch: '<S661>/Switch1' incorporates:
     *  Constant: '<S435>/Constant27'
     */
    LampCtl_J449BoxLamp = LampCtl_J449BoxLampOvrdVal_C;
  } else {
    /* Switch: '<S661>/Switch1' incorporates:
     *  Switch: '<S661>/Switch2'
     *  UnitDelay: '<S645>/Unit Delay'
     */
    LampCtl_J449BoxLamp = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bj;
  }

  /* End of Switch: '<S661>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd13' */

  /* Outputs for Atomic SubSystem: '<S435>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl();

  /* End of Outputs for SubSystem: '<S435>/TurnIndcrCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl();

  /* End of Outputs for SubSystem: '<S435>/WelcomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd11' */
  /* Switch: '<S659>/Switch1' incorporates:
   *  Constant: '<S435>/Constant23'
   */
  if (LampCtl_TurnIndcrRStaOvrdFlg_C) {
    /* Switch: '<S659>/Switch1' incorporates:
     *  Constant: '<S435>/Constant24'
     */
    LampCtl_TurnIndcrRSta = LampCtl_TurnIndcrRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion11' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->TurnIndcrRCtlFlg != 0);

    /* Switch: '<S659>/Switch1' incorporates:
     *  Switch: '<S659>/Switch2'
     *  UnitDelay: '<S675>/Unit Delay17'
     */
    LampCtl_TurnIndcrRSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE);
  }

  /* End of Switch: '<S659>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd11' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd12' */
  /* Switch: '<S660>/Switch1' incorporates:
   *  Constant: '<S435>/Constant25'
   */
  if (LampCtl_TurnIndcrLStaOvrdFlg_C) {
    /* Switch: '<S660>/Switch1' incorporates:
     *  Constant: '<S435>/Constant26'
     */
    LampCtl_TurnIndcrLSta = LampCtl_TurnIndcrLStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion12' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->TurnIndcrLCtlFlg != 0);

    /* Switch: '<S660>/Switch1' incorporates:
     *  Switch: '<S660>/Switch2'
     *  UnitDelay: '<S675>/Unit Delay16'
     */
    LampCtl_TurnIndcrLSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE);
  }

  /* End of Switch: '<S660>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd12' */

  /* Outputs for Atomic SubSystem: '<S435>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl();

  /* End of Outputs for SubSystem: '<S435>/DomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd10' */
  /* Switch: '<S658>/Switch1' incorporates:
   *  Constant: '<S435>/Constant22'
   */
  if (LampCtl_DomeLampPwmDutyOvrdFlg_C) {
    /* Switch: '<S658>/Switch1' incorporates:
     *  Constant: '<S435>/Constant21'
     */
    LampCtl_DomeLampPwmDuty = LampCtl_DomeLampPwmDutyOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion10' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DomeLampCtlFlg != 0);

    /* Switch: '<S658>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S658>/Switch1' incorporates:
       *  Constant: '<S435>/Constant31'
       */
      LampCtl_DomeLampPwmDuty = 100U;
    } else {
      /* Switch: '<S658>/Switch1' */
      LampCtl_DomeLampPwmDuty = AppSwcBcm_ARID_DEF.Switch;
    }

    /* End of Switch: '<S658>/Switch2' */
  }

  /* End of Switch: '<S658>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd10' */

  /* Outputs for Atomic SubSystem: '<S435>/Ovrd8' */
  /* Switch: '<S669>/Switch1' incorporates:
   *  Constant: '<S435>/Constant16'
   */
  if (LampCtl_ReverseLampStaOvrdFlg_C) {
    /* Switch: '<S669>/Switch1' incorporates:
     *  Constant: '<S435>/Constant15'
     */
    LampCtl_ReverseLampSta = LampCtl_ReverseLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S435>/Data Type Conversion8' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->ReverseLampCtlFlg != 0);

    /* Switch: '<S669>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S669>/Switch1' incorporates:
       *  Switch: '<S669>/Switch2'
       */
      LampCtl_ReverseLampSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S435>/ReverseLampCtl' */
      AppSwcBcm_ReverseLampCtl();

      /* End of Outputs for SubSystem: '<S435>/ReverseLampCtl' */

      /* Switch: '<S669>/Switch1' incorporates:
       *  Switch: '<S669>/Switch2'
       */
      LampCtl_ReverseLampSta = AppSwcBcm_ARID_DEF.LogicalOperator_poq;
    }

    /* End of Switch: '<S669>/Switch2' */
  }

  /* End of Switch: '<S669>/Switch1' */
  /* End of Outputs for SubSystem: '<S435>/Ovrd8' */
}

/* Update for atomic system: '<S4>/LampCtl' */
static void AppSwcBcm_LampCtl_Update(void)
{
  /* Update for UnitDelay: '<S435>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fu = LampCtl_WelcomeLampSta;

  /* Update for UnitDelay: '<S435>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b = LampCtl_FlwrMeHomeSta;

  /* Update for Atomic SubSystem: '<S435>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Update();

  /* End of Update for SubSystem: '<S435>/WelcomeLampCtl' */
}

/* Output and update for atomic system: '<S436>/Chart' */
static void AppSwcBcm_Chart(void)
{
  /* Chart: '<S436>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S436>/Unit Delay6'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
    PDUCtl_SysPowerSts = 0U;
    AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 0U;
    AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib) {
     case AppSwcBcm_IN_LocalOn:
      PDUCtl_SysPowerSts = 1U;
      if (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_n == 0) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 0U;
        AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 0U;
      }
      break;

     case AppSwcBcm_IN_OTA1On:
      PDUCtl_SysPowerSts = 5U;
      AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 1U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_HUBCMOTAModeSet_enum == 2) || PDUCtl_PwrOff) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 0U;
        AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_HUBCMOTAModeSet_enum == 1) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTAOn;
        PDUCtl_SysPowerSts = 3U;
      }
      break;

     case AppSwcBcm_IN_OTAOn:
      PDUCtl_SysPowerSts = 3U;
      AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 1U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_HUBCMOTAModeSet_enum == 2) || PDUCtl_PwrOff) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 0U;
        AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                 ->VIPM_HUBCMOTAModeSet_enum == 3) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTA1On;
        PDUCtl_SysPowerSts = 5U;
      }
      break;

     case AppSwcBcm_IN_PSOff:
      PDUCtl_SysPowerSts = 0U;
      AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 0U;
      AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 0U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRemtPwrCtrlReq_enum == 2) && (PDUCtl_RemotePwrLckSta == 0)
          && (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1)) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_RemoteOn;
        PDUCtl_SysPowerSts = 2U;
        AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 1U;
      } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                  ->VIPM_HUBCMOTAModeSet_enum == 1) && (PDUCtl_RemotePwrLckSta ==
                  0)) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTAOn;
        PDUCtl_SysPowerSts = 3U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 1U;
      } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                  ->VIPM_HUBCMOTAModeSet_enum == 3) && (PDUCtl_RemotePwrLckSta ==
                  0)) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_OTA1On;
        PDUCtl_SysPowerSts = 5U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 1U;
      } else if (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_n == 2) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      }
      break;

     default:
      /* case IN_RemoteOn: */
      PDUCtl_SysPowerSts = 2U;
      AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 1U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRemtPwrCtrlReq_enum == 1) || PDUCtl_PwrOff) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
        PDUCtl_SysPowerSts = 0U;
        AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode = 0U;
        AppSwcBcm_ARID_DEF.PDU_RemtPwrMode = 0U;
      } else if (AppSwcBcm_ARID_DEF.UnitDelay8_n) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      }
      break;
    }
  }

  /* End of Chart: '<S436>/Chart' */
}

/* System initialize for atomic system: '<S436>/PwrOff' */
static void AppSwcBcm_PwrOff_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ct;

  /* SystemInitialize for Chart: '<S917>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_ct);

  /* SystemInitialize for Chart: '<S917>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_b);
}

/* Output and update for atomic system: '<S436>/PwrOff' */
static void AppSwcBcm_PwrOff(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ct;
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_i3;
  boolean rtb_LogicalOperator2_kt;
  boolean rtb_LogicalOperator2_nv;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator11_l;
  boolean rtb_RelationalOperator22_n;
  boolean rtb_RelationalOperator5_f0;
  boolean rtb_SysResetPwrOff;

  /* Chart: '<S917>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if ((!AppSwcBcm_ARID_DEF.Flg_k) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->SysPwrMode == 0)) {
    rtb_SysResetPwrOff = true;
    AppSwcBcm_ARID_DEF.Flg_k = true;
  } else {
    rtb_SysResetPwrOff = false;
  }

  /* End of Chart: '<S917>/Chart' */

  /* RelationalOperator: '<S917>/Relational Operator11' */
  rtb_RelationalOperator11_l = !AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;

  /* Logic: '<S917>/Logical Operator' incorporates:
   *  Constant: '<S917>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S917>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S917>/Logical Operator1' incorporates:
   *  Constant: '<S917>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S917>/Relational Operator3'
   */
  rtb_LogicalOperator1_i3 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S917>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator1_i3);

  /* Logic: '<S917>/Logical Operator1' incorporates:
   *  Constant: '<S917>/Constant'
   *  Constant: '<S917>/Constant10'
   *  Constant: '<S917>/Constant11'
   *  Logic: '<S917>/Logical Operator7'
   *  RelationalOperator: '<S917>/Relational Operator'
   *  RelationalOperator: '<S917>/Relational Operator6'
   *  RelationalOperator: '<S917>/Relational Operator7'
   *  UnitDelay: '<S436>/Unit Delay2'
   *  UnitDelay: '<S436>/Unit Delay5'
   */
  rtb_LogicalOperator1_i3 = (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 2) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 1)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_i == 2) && rtb_LogicalOperator);

  /* Outputs for Atomic SubSystem: '<S917>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    &rtb_LogicalOperator2_nv, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet);

  /* End of Outputs for SubSystem: '<S917>/Lib_BothEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S917>/Lib_BothEdgeDet1' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    &rtb_LogicalOperator2_kt, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet1);

  /* End of Outputs for SubSystem: '<S917>/Lib_BothEdgeDet1' */

  /* Outputs for Atomic SubSystem: '<S917>/Lib_BothEdgeDet2' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_LogicalOperator9, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet2);

  /* End of Outputs for SubSystem: '<S917>/Lib_BothEdgeDet2' */

  /* Outputs for Atomic SubSystem: '<S917>/Lib_BothEdgeDet3' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_RelationalOperator5_f0, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet3);

  /* End of Outputs for SubSystem: '<S917>/Lib_BothEdgeDet3' */

  /* Logic: '<S917>/Logical Operator2' incorporates:
   *  Logic: '<S917>/Logical Operator3'
   */
  rtb_RelationalOperator5_f0 = ((!rtb_LogicalOperator2_nv) &&
    (!rtb_LogicalOperator2_kt) && (!rtb_LogicalOperator9) &&
    (!rtb_RelationalOperator5_f0));

  /* Logic: '<S917>/Logical Operator9' incorporates:
   *  Constant: '<S917>/Constant17'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S917>/Relational Operator1'
   */
  rtb_LogicalOperator9 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VIPC_VehHiddenMode_enum != 1);

  /* Chart: '<S917>/LIB_Tim' incorporates:
   *  Constant: '<S917>/Constant4'
   *  Constant: '<S917>/Constant5'
   *  Constant: '<S917>/Constant6'
   *  Constant: '<S917>/Constant7'
   *  Logic: '<S917>/Logical Operator4'
   *  RelationalOperator: '<S917>/Relational Operator12'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator11_l &&
      rtb_LogicalOperator1_i3 && rtb_RelationalOperator5_f0 &&
      rtb_LogicalOperator9) {
    if ((AppSwcBcm_ARID_DEF.Cnt_H_k >= PDUCtl_TimOutPwrOffH_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_M_l >= PDUCtl_TimOutPwrOffM_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_S_o >= PDUCtl_TimOutPwrOffS_C)) {
      PDUCtl_DelayTimPwrOff = true;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_Tick_a + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick_a + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_Tick_a = (uint16)tmp;
      PDUCtl_DelayTimPwrOff = false;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick_a >= 1.0F / PDUCtl_Ts_C) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_S_o + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_S_o + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_S_o = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_S_o >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_M_l + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_M_l + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_M_l = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_S_o = 0U;
      }

      if (AppSwcBcm_ARID_DEF.Cnt_M_l >= 60) {
        tmp = AppSwcBcm_ARID_DEF.Cnt_H_k + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_H_k + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_H_k = (uint8)tmp;
        AppSwcBcm_ARID_DEF.Cnt_M_l = 0U;
      }
    }
  } else {
    PDUCtl_DelayTimPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
    AppSwcBcm_ARID_DEF.Cnt_S_o = 0U;
    AppSwcBcm_ARID_DEF.Cnt_M_l = 0U;
    AppSwcBcm_ARID_DEF.Cnt_H_k = 0U;
  }

  /* End of Chart: '<S917>/LIB_Tim' */

  /* Logic: '<S917>/Logical Operator9' incorporates:
   *  Constant: '<S917>/Constant39'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S917>/Relational Operator23'
   */
  rtb_LogicalOperator9 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRemtPwrCtrlReq_enum == 1);

  /* Chart: '<S917>/LIB_Tim1' incorporates:
   *  Constant: '<S917>/Constant25'
   *  Constant: '<S917>/Constant26'
   *  Constant: '<S917>/Constant27'
   *  Constant: '<S917>/Constant28'
   *  Constant: '<S917>/Constant29'
   *  Logic: '<S917>/Logical Operator14'
   *  Logic: '<S917>/Logical Operator15'
   *  RelationalOperator: '<S917>/Relational Operator16'
   *  UnitDelay: '<S436>/Unit Delay2'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 2) && (!rtb_LogicalOperator9))
  {
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

  /* End of Chart: '<S917>/LIB_Tim1' */

  /* RelationalOperator: '<S917>/Relational Operator13' incorporates:
   *  Constant: '<S917>/Constant22'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_LogicalOperator2_nv = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC()
    )->VIPM_TBOXRemtPwrCtrlReq_enum == 1);

  /* Logic: '<S917>/Logical Operator12' incorporates:
   *  Constant: '<S917>/Constant23'
   *  Constant: '<S917>/Constant24'
   *  Logic: '<S935>/Logical Operator'
   *  Logic: '<S935>/Logical Operator1'
   *  RelationalOperator: '<S917>/Relational Operator14'
   *  RelationalOperator: '<S917>/Relational Operator15'
   *  UnitDelay: '<S436>/Unit Delay2'
   *  UnitDelay: '<S436>/Unit Delay5'
   *  UnitDelay: '<S935>/Unit Delay'
   */
  PDUCtl_RemtPwrOff = (rtb_LogicalOperator2_nv &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ct) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_i == 2) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 2));

  /* Chart: '<S917>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S917>/Constant19'
   *  Constant: '<S917>/Constant20'
   *  Constant: '<S917>/Constant21'
   *  UnitDelay: '<S4>/Unit Delay9'
   */
  AppSwcBcm_LIB_TPD_10ms(AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_jn,
    PDUCtl_EmerPwrOffTimValid_C, PDUCtl_EmerPwrOffTimInValid_C, PDUCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_b, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts_p);

  /* Logic: '<S917>/Logical Operator13' incorporates:
   *  RelationalOperator: '<S917>/Relational Operator12'
   */
  PDUCtl_EmerPwrOff = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_b &&
                       AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* RelationalOperator: '<S917>/Relational Operator18' incorporates:
   *  Constant: '<S917>/Constant31'
   */
  rtb_LogicalOperator2_kt = (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 1);

  /* Chart: '<S917>/LIB_PosPluse' incorporates:
   *  Constant: '<S917>/Constant33'
   *  UnitDelay: '<S4>/Unit Delay8'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i,
    PDUCtl_RemtPasvBrkSwTimValid_C, &rtb_LIB_blOut_ct,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_l);

  /* Logic: '<S917>/Logical Operator16' incorporates:
   *  Constant: '<S917>/Constant30'
   *  Logic: '<S917>/Logical Operator17'
   *  Logic: '<S917>/Logical Operator18'
   *  Logic: '<S934>/Logical Operator'
   *  Logic: '<S934>/Logical Operator1'
   *  RelationalOperator: '<S917>/Relational Operator17'
   *  RelationalOperator: '<S917>/Relational Operator19'
   *  UnitDelay: '<S436>/Unit Delay2'
   *  UnitDelay: '<S934>/Unit Delay'
   */
  PDUCtl_RemtPasvPwrOff = ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 2) &&
    ((rtb_LogicalOperator2_kt && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ds)) ||
     (rtb_LIB_blOut_ct && (!AppSwcBcm_ARID_DEF.LogicalOperator10))));

  /* Logic: '<S917>/Logical Operator9' incorporates:
   *  Constant: '<S917>/Constant34'
   *  Constant: '<S917>/Constant35'
   *  Logic: '<S917>/Logical Operator19'
   *  RelationalOperator: '<S917>/Relational Operator20'
   *  RelationalOperator: '<S917>/Relational Operator21'
   *  UnitDelay: '<S436>/Unit Delay2'
   */
  rtb_LogicalOperator9 = ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 3) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d == 5));

  /* Chart: '<S917>/LIB_PosPluse1' incorporates:
   *  Constant: '<S917>/Constant37'
   *  Logic: '<S917>/Logical Operator22'
   */
  if (rtb_LogicalOperator9) {
    if (AppSwcBcm_ARID_DEF.Cnt_m <= PDUCtl_OTAOverTimPwrOff_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_m + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_m + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_m = (uint16)tmp;
      PDUCtl_OTAOverTimPwrOff = false;
    } else {
      PDUCtl_OTAOverTimPwrOff = true;
    }
  } else {
    PDUCtl_OTAOverTimPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_m = 0U;
  }

  /* End of Chart: '<S917>/LIB_PosPluse1' */

  /* RelationalOperator: '<S917>/Relational Operator22' incorporates:
   *  Constant: '<S917>/Constant36'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator22_n = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUBCMOTAModeSet_enum == 2);

  /* Logic: '<S917>/Logical Operator20' incorporates:
   *  Logic: '<S936>/Logical Operator'
   *  Logic: '<S936>/Logical Operator1'
   *  UnitDelay: '<S936>/Unit Delay'
   */
  PDUCtl_OTAPwrOff = (rtb_RelationalOperator22_n &&
                      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fk) &&
                      rtb_LogicalOperator9);

  /* Logic: '<S917>/Logical Operator5' incorporates:
   *  Constant: '<S917>/Constant12'
   *  Constant: '<S917>/Constant13'
   *  Constant: '<S917>/Constant14'
   *  Logic: '<S917>/Logical Operator10'
   *  Logic: '<S917>/Logical Operator11'
   *  Logic: '<S917>/Logical Operator9'
   *  RelationalOperator: '<S917>/Relational Operator10'
   *  RelationalOperator: '<S917>/Relational Operator12'
   *  RelationalOperator: '<S917>/Relational Operator4'
   *  RelationalOperator: '<S917>/Relational Operator8'
   *  RelationalOperator: '<S917>/Relational Operator9'
   *  UnitDelay: '<S436>/Unit Delay2'
   *  UnitDelay: '<S436>/Unit Delay5'
   */
  PDUCtl_OsLckPwrOff = (rtb_LogicalOperator && rtb_RelationalOperator11_l &&
                        ((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d != 3) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d != 5) &&
    (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_i == 2)) &&
                        AppSwcBcm_ARID_DEF.BusCreator4.OsLck &&
                        (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) &&
                        AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* RelationalOperator: '<S917>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_f0 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUPwrOffReq_flg;

  /* Logic: '<S917>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S917>/Relational Operator12'
   */
  PDUCtl_HUPwrOff = (rtb_RelationalOperator5_f0 &&
                     AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
                     rtb_LogicalOperator1_i3);

  /* Logic: '<S917>/Logical Operator6' incorporates:
   *  Logic: '<S917>/Logical Operator21'
   */
  PDUCtl_PwrOff = (PDUCtl_OsLckPwrOff || PDUCtl_HUPwrOff ||
                   PDUCtl_DelayTimPwrOff || PDUCtl_EmerPwrOff ||
                   PDUCtl_RemtPwrOff || PDUCtl_RemtOverTimPwrOff ||
                   PDUCtl_RemtPasvPwrOff || (PDUCtl_OTAPwrOff ||
    PDUCtl_OTAOverTimPwrOff) || rtb_SysResetPwrOff);

  /* Update for UnitDelay: '<S935>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ct = rtb_LogicalOperator2_nv;

  /* Update for UnitDelay: '<S934>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ds = rtb_LogicalOperator2_kt;

  /* Update for UnitDelay: '<S936>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fk = rtb_RelationalOperator22_n;
}

/*
 * Output and update for atomic system:
 *    '<S918>/Lib_FailEdgeDet'
 *    '<S918>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet_f(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_g_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S941>/Logical Operator' incorporates:
   *  Logic: '<S941>/Logical Operator1'
   *  UnitDelay: '<S941>/Unit Delay'
   */
  rty_Lib_blOut_0 = ((!rtu_Lib_blIn) &&
                     AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S941>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S436>/PwrOn' */
static void AppSwcBcm_PwrOn_Init(void)
{
  /* SystemInitialize for Chart: '<S918>/LIB_TPD_Ts' */
  AppSwcBcm_LIB_TPD_10ms11_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg);
}

/* Output and update for atomic system: '<S436>/PwrOn' */
static void AppSwcBcm_PwrOn(void)
{
  sint32 tmp;
  boolean rtb_LIB_blOut_ja;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator2_em;
  boolean rtb_RelationalOperator2_p2;
  boolean rtb_RelationalOperator5_b1;

  /* Chart: '<S918>/BrkPwrOn' incorporates:
   *  Constant: '<S918>/Constant3'
   *  UnitDelay: '<S436>/Unit Delay4'
   *  UnitDelay: '<S4>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib == AppSwcBcm_IN_Invalid) {
    AppSwcBcm_ARID_DEF.Lib_blIn_k = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i;

    /* Outputs for Function Call SubSystem: '<S937>/Lib_RiseEdgeDet' */
    AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_k,
      &AppSwcBcm_ARID_DEF.LogicalOperator_j,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_n);

    /* End of Outputs for SubSystem: '<S937>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_j) {
      AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib = AppSwcBcm_IN_Valid;
      tmp = AppSwcBcm_ARID_DEF.Cnt_c + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_c + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_c = (uint16)tmp;
      AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;
    }

    /* case IN_Valid: */
  } else if ((!AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i) ||
             (AppSwcBcm_ARID_DEF.Cnt_c > PDUCtl_PwrOnPSTimValid_C) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_b) {
    AppSwcBcm_ARID_DEF.is_c14_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
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

  /* End of Chart: '<S918>/BrkPwrOn' */

  /* RelationalOperator: '<S918>/Relational Operator5' incorporates:
   *  Constant: '<S918>/Constant8'
   */
  rtb_RelationalOperator5_b1 = (AppSwcBcm_ARID_DEF.BusCreator14.SKSta == 1);

  /* Switch: '<S945>/Switch' incorporates:
   *  Constant: '<S918>/Constant10'
   *  Constant: '<S918>/Constant9'
   *  Logic: '<S918>/Logical Operator7'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    AppSwcBcm_ARID_DEF.LogicalOperator10 = PDUCtl_KeyValidOvrdVal_C;
  } else {
    /* RelationalOperator: '<S918>/Relational Operator2' incorporates:
     *  Constant: '<S918>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
     */
    rtb_RelationalOperator2_p2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus
      ())->KeySta != 0);
    AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator2_p2 ||
      rtb_RelationalOperator5_b1);
  }

  /* End of Switch: '<S945>/Switch' */

  /* Logic: '<S918>/Logical Operator5' */
  PDUCtl_KeyChk = (AppSwcBcm_ARID_DEF.BrkPwrOnValid &&
                   AppSwcBcm_ARID_DEF.LogicalOperator10);

  /* Logic: '<S918>/Logical Operator3' incorporates:
   *  Constant: '<S918>/Constant4'
   *  Constant: '<S918>/Constant5'
   *  RelationalOperator: '<S918>/Relational Operator'
   *  RelationalOperator: '<S918>/Relational Operator3'
   *  UnitDelay: '<S436>/Unit Delay'
   *  UnitDelay: '<S436>/Unit Delay1'
   */
  rtb_RelationalOperator2_p2 = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p == 0));

  /* Logic: '<S918>/Logical Operator1' */
  PDUCtl_BrkPwrOn = (rtb_RelationalOperator2_p2 && PDUCtl_KeyChk);

  /* Chart: '<S918>/LIB_TPD_Ts' incorporates:
   *  Constant: '<S918>/Constant16'
   *  Constant: '<S918>/Constant17'
   *  Constant: '<S918>/Constant18'
   *  RelationalOperator: '<S918>/Relational Operator10'
   *  UnitDelay: '<S436>/Unit Delay9'
   */
  AppSwcBcm_LIB_TPD_10ms11(AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_j == 1,
    PDUCtl_OTAPwrOnDelayTim_C, PDUCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_Ts);

  /* Logic: '<S944>/Logical Operator' incorporates:
   *  Logic: '<S944>/Logical Operator1'
   *  UnitDelay: '<S944>/Unit Delay'
   */
  PDUCtl_OTAPwrOn = (AppSwcBcm_ARID_DEF.LIB_bErrFlg &&
                     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j));

  /* RelationalOperator: '<S918>/Relational Operator4' incorporates:
   *  Constant: '<S918>/Constant'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_l = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* RelationalOperator: '<S948>/Relational Operator2' incorporates:
   *  UnitDelay: '<S918>/Unit Delay'
   */
  rtb_RelationalOperator2_em = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac;

  /* Logic: '<S918>/Logical Operator8' incorporates:
   *  Constant: '<S918>/Constant7'
   *  RelationalOperator: '<S918>/Relational Operator6'
   *  UnitDelay: '<S918>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_j = (AppSwcBcm_ARID_DEF.Lib_blIn_l ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac ||
    (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2));

  /* Chart: '<S918>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S939>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_j,
    &AppSwcBcm_ARID_DEF.LogicalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
    AppSwcBcm_ARID_DEF.Cnt_a = 0U;
    AppSwcBcm_ARID_DEF.Flg_d = false;
  }

  /* Chart: '<S918>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S939>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_l,
    &AppSwcBcm_ARID_DEF.LogicalOperator_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_l) {
    AppSwcBcm_ARID_DEF.Flg_d = true;
    AppSwcBcm_ARID_DEF.Cnt_a = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_d) {
    /* Constant: '<S918>/Constant6' */
    if (AppSwcBcm_ARID_DEF.Cnt_a <= PDUCtl_OpenDoorPwrOnTimValid) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_a + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_a + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_a = (uint16)tmp;
      rtb_LIB_blOut_ja = true;
    } else {
      rtb_LIB_blOut_ja = false;
      AppSwcBcm_ARID_DEF.Flg_d = false;
    }

    /* End of Constant: '<S918>/Constant6' */
  } else {
    rtb_LIB_blOut_ja = false;
    AppSwcBcm_ARID_DEF.Cnt_a = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S918>/Lib_FailEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet_f
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_g);

  /* End of Outputs for SubSystem: '<S918>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S918>/Lib_FailEdgeDet1' */
  rtb_RelationalOperator2_em = AppSwcBcm_Lib_FailEdgeDet_f
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1);

  /* End of Outputs for SubSystem: '<S918>/Lib_FailEdgeDet1' */

  /* Switch: '<S946>/Switch' incorporates:
   *  Constant: '<S918>/Constant11'
   *  Constant: '<S918>/Constant12'
   *  Logic: '<S918>/Logical Operator6'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    rtb_RelationalOperator5_b1 = PDUCtl_KeyValidOvrdVal_C;
  } else {
    rtb_RelationalOperator5_b1 = (rtb_LIB_blOut_ja || rtb_RelationalOperator5_b1);
  }

  /* Logic: '<S918>/Logical Operator' incorporates:
   *  Logic: '<S918>/Logical Operator4'
   *  Switch: '<S946>/Switch'
   */
  PDUCtl_OpenDoorPwrOn = (rtb_RelationalOperator5_b1 &&
    (rtb_RelationalOperator2_em || rtb_LogicalOperator) &&
    rtb_RelationalOperator2_p2);

  /* RelationalOperator: '<S918>/Relational Operator7' incorporates:
   *  Constant: '<S918>/Constant13'
   *  UnitDelay: '<S436>/Unit Delay7'
   */
  rtb_RelationalOperator5_b1 = (AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_n == 1);

  /* Logic: '<S918>/Logical Operator9' incorporates:
   *  Constant: '<S918>/Constant15'
   *  Logic: '<S943>/Logical Operator'
   *  Logic: '<S943>/Logical Operator1'
   *  RelationalOperator: '<S918>/Relational Operator9'
   *  UnitDelay: '<S436>/Unit Delay'
   *  UnitDelay: '<S943>/Unit Delay'
   */
  PDUCtl_RemtPwrOn = (rtb_RelationalOperator5_b1 &&
                      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j4) &&
                      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p == 0));

  /* Logic: '<S918>/Logical Operator2' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac = (PDUCtl_OpenDoorPwrOn ||
    PDUCtl_BrkPwrOn || PDUCtl_RemtPwrOn || PDUCtl_OTAPwrOn);

  /* Chart: '<S918>/RemoteLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   * */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Init_jy;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib) {
     case AppSwcBcm_IN_Init_jy:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->RemotePwrLckSta
          != 1) {
        AppSwcBcm_ARID_DEF.is_c8_PDUCtl_Lib = AppSwcBcm_IN_Unlck;
        PDUCtl_RemotePwrLckSta = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())
                 ->RemotePwrLckSta == 1) {
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

  /* End of Chart: '<S918>/RemoteLck' */

  /* Chart: '<S918>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if ((!AppSwcBcm_ARID_DEF.Flg_j) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->SysPwrMode == 2)) {
    rtb_RelationalOperator2_p2 = true;
    AppSwcBcm_ARID_DEF.Flg_j = true;
  } else {
    rtb_RelationalOperator2_p2 = false;
  }

  /* End of Chart: '<S918>/Chart' */

  /* Logic: '<S918>/Logical Operator11' incorporates:
   *  Constant: '<S918>/Constant1'
   *  Logic: '<S918>/Logical Operator10'
   *  RelationalOperator: '<S918>/Relational Operator1'
   */
  PDUCtl_PwrOn = ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac &&
                   (PDUCtl_RemotePwrLckSta == 0)) || rtb_RelationalOperator2_p2);

  /* RelationalOperator: '<S948>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_p2 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLckVld_flg;

  /* RelationalOperator: '<S948>/Relational Operator2' incorporates:
   *  Constant: '<S948>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S948>/Relational Operator'
   */
  rtb_RelationalOperator2_em = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLck_enum == 1);

  /* Logic: '<S948>/Logical Operator' */
  rtb_LIB_blOut_ja = (rtb_RelationalOperator2_em && rtb_RelationalOperator2_p2);

  /* RelationalOperator: '<S948>/Relational Operator2' incorporates:
   *  Constant: '<S948>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_em = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_TBOXRmtPwrLck_enum == 2);

  /* Switch: '<S948>/Switch' incorporates:
   *  Logic: '<S948>/Logical Operator1'
   *  Logic: '<S948>/Logical Operator2'
   */
  PDUCtl_RemotePwrLckFb = ((rtb_RelationalOperator2_em &&
    rtb_RelationalOperator2_p2) || rtb_LIB_blOut_ja);

  /* Update for UnitDelay: '<S944>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = AppSwcBcm_ARID_DEF.LIB_bErrFlg;

  /* Update for UnitDelay: '<S943>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j4 = rtb_RelationalOperator5_b1;
}

/* Output and update for atomic system: '<S436>/RelayDig' */
static void AppSwcBcm_RelayDig(void)
{
  float32 tmp;
  boolean rtb_RelationalOperator3_b;
  boolean rtb_RelationalOperator7_e3;

  /* RelationalOperator: '<S919>/Relational Operator3' incorporates:
   *  Constant: '<S919>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S919>/Relational Operator2'
   */
  rtb_RelationalOperator3_b =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* RelationalOperator: '<S919>/Relational Operator7' incorporates:
   *  Constant: '<S919>/Constant'
   *  Logic: '<S919>/Logical Operator'
   *  RelationalOperator: '<S919>/Relational Operator'
   */
  rtb_RelationalOperator7_e3 = ((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator3_b);

  /* RelationalOperator: '<S919>/Relational Operator3' incorporates:
   *  Constant: '<S919>/Constant3'
   */
  rtb_RelationalOperator3_b = (PDUCtl_SysPwrMode == 0);

  /* RelationalOperator: '<S919>/Relational Operator7' incorporates:
   *  Logic: '<S919>/Logical Operator1'
   */
  rtb_RelationalOperator7_e3 = (rtb_RelationalOperator3_b ||
    rtb_RelationalOperator7_e3);

  /* Chart: '<S919>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S919>/Constant6'
   *  Constant: '<S919>/Constant7'
   *  Logic: '<S919>/Logical Operator3'
   *  RelationalOperator: '<S919>/Relational Operator5'
   */
  if (rtb_RelationalOperator7_e3 && (PDUCtl_J437IG2RlyCtl !=
       AppSwcBcm_ARID_DEF.Switch1)) {
    tmp = 50.0F / (PDUCtl_Ts_C * 100.0F);
    if (AppSwcBcm_ARID_DEF.cnt_defect_l >= tmp) {
      PDUCtl_IG2RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l++;
      AppSwcBcm_ARID_DEF.cnt_heal_f = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_f == 0) {
      PDUCtl_IG2RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_f--;
    }
  }

  /* End of Chart: '<S919>/LIB_TPD_10ms1' */

  /* Chart: '<S919>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S919>/Constant4'
   *  Constant: '<S919>/Constant5'
   *  Constant: '<S919>/Constant8'
   *  Logic: '<S919>/Logical Operator2'
   *  RelationalOperator: '<S919>/Relational Operator4'
   */
  if (rtb_RelationalOperator7_e3 && (PDUCtl_J421IG1RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller35)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_j >= 50.0F / (PDUCtl_Ts_C * 100.0F)) {
      PDUCtl_IG1RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j++;
      AppSwcBcm_ARID_DEF.cnt_heal_n = (uint16)(50.0F / (PDUCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n == 0) {
      PDUCtl_IG1RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_n--;
    }
  }

  /* End of Chart: '<S919>/LIB_TPD_10ms2' */

  /* Switch: '<S919>/Switch' incorporates:
   *  Logic: '<S919>/Logical Operator4'
   */
  PDUCtl_SysPwrModeV = ((!PDUCtl_IG1RelayFault) && (!PDUCtl_IG2RelayFault));

  /* Chart: '<S919>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S919>/Constant1'
   *  Constant: '<S919>/Constant12'
   *  Constant: '<S919>/Constant13'
   *  Constant: '<S919>/Constant14'
   *  Constant: '<S919>/Constant15'
   *  Constant: '<S919>/Constant16'
   *  Constant: '<S919>/Constant17'
   *  Constant: '<S919>/Constant18'
   *  Logic: '<S919>/Logical Operator5'
   *  Logic: '<S919>/Logical Operator6'
   *  Logic: '<S919>/Logical Operator7'
   *  RelationalOperator: '<S919>/Relational Operator1'
   *  RelationalOperator: '<S919>/Relational Operator6'
   *  RelationalOperator: '<S919>/Relational Operator7'
   *  RelationalOperator: '<S919>/Relational Operator8'
   *  RelationalOperator: '<S919>/Relational Operator9'
   */
  if (((AppSwcBcm_ARID_DEF.Switch1 == 1) || (AppSwcBcm_ARID_DEF.CCaller35 == 1))
      && ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 2)) &&
      rtb_RelationalOperator3_b) {
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

  /* End of Chart: '<S919>/LIB_TPD_10ms3' */
}

/* System initialize for atomic system: '<S436>/StartReq' */
static void AppSwcBcm_StartReq_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j0;
  boolean rtb_LIB_blOut_mk;

  /* SystemInitialize for Chart: '<S921>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_mk);

  /* SystemInitialize for Chart: '<S921>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_j0);
}

/* Output and update for atomic system: '<S436>/StartReq' */
static void AppSwcBcm_StartReq(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j0;
  boolean rtb_LIB_blOut_mk;
  boolean rtb_RelationalOperator6;
  boolean rtb_SysResetStartOff;
  boolean rtb_SysResetStartOn;

  /* Chart: '<S921>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if ((!AppSwcBcm_ARID_DEF.Flg_a) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->StartReq == 1)) {
    rtb_SysResetStartOn = true;
    AppSwcBcm_ARID_DEF.Flg_a = true;
  } else {
    rtb_SysResetStartOn = false;
  }

  /* End of Chart: '<S921>/Chart' */

  /* Chart: '<S921>/LIB_PosPluse' incorporates:
   *  Constant: '<S921>/Constant3'
   *  Constant: '<S921>/Constant4'
   *  Logic: '<S921>/Logical Operator'
   *  RelationalOperator: '<S921>/Relational Operator3'
   *  UnitDelay: '<S4>/Unit Delay8'
   */
  AppSwcBcm_LIB_PosPluse((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i, PDUCtl_StartReqTimValid_C,
    &rtb_LIB_blOut_mk, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse);

  /* RelationalOperator: '<S921>/Relational Operator6' incorporates:
   *  Constant: '<S921>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S921>/Relational Operator1'
   */
  rtb_RelationalOperator6 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Logic: '<S921>/Logical Operator5' incorporates:
   *  Constant: '<S921>/Constant1'
   *  Logic: '<S921>/Logical Operator1'
   *  RelationalOperator: '<S921>/Relational Operator'
   *  RelationalOperator: '<S921>/Relational Operator2'
   *  RelationalOperator: '<S921>/Relational Operator7'
   */
  rtb_SysResetStartOn = (rtb_SysResetStartOn || (PDUCtl_SysPwrModeV &&
    PDUCtl_KeyChk && rtb_LIB_blOut_mk && (PDUCtl_SysPowerSts == 1) &&
    rtb_RelationalOperator6));

  /* Chart: '<S921>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if ((!AppSwcBcm_ARID_DEF.Flg) && (AppSwcBcm_ARID_DEF.CCaller40 == 0x05) &&
      ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus())->StartReq == 0)) {
    rtb_SysResetStartOff = true;
    AppSwcBcm_ARID_DEF.Flg = true;
  } else {
    rtb_SysResetStartOff = false;
  }

  /* End of Chart: '<S921>/Chart1' */

  /* RelationalOperator: '<S921>/Relational Operator6' incorporates:
   *  Constant: '<S921>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S921>/Relational Operator5'
   */
  rtb_RelationalOperator6 =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S921>/LIB_PosPluse1' incorporates:
   *  Constant: '<S921>/Constant5'
   *  Logic: '<S921>/Logical Operator3'
   *  UnitDelay: '<S921>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(rtb_RelationalOperator6 &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pd, PDUCtl_StartReqOverTimValid_C,
    &rtb_LIB_blOut_j0, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1);

  /* Outputs for Atomic SubSystem: '<S921>/Lib_SR' */
  /* Outputs for Atomic SubSystem: '<S921>/Lib_RiseEdgeDetHold' */
  /* Switch: '<S965>/Switch' incorporates:
   *  Constant: '<S921>/Constant6'
   *  Logic: '<S921>/Logical Operator2'
   *  Logic: '<S921>/Logical Operator4'
   *  Logic: '<S964>/Logical Operator'
   *  Logic: '<S964>/Logical Operator1'
   *  RelationalOperator: '<S921>/Relational Operator4'
   *  RelationalOperator: '<S921>/Relational Operator6'
   *  RelationalOperator: '<S921>/Relational Operator8'
   *  Switch: '<S966>/Switch'
   *  UnitDelay: '<S964>/Unit Delay'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
       ((!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw) &&
        AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aw) &&
       (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) || (PDUCtl_SysPwrMode ==
       0) || rtb_SysResetStartOff || rtb_LIB_blOut_j0) {
    /* Switch: '<S965>/Switch' incorporates:
     *  Constant: '<S965>/Constant'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_pr = false;

    /* Switch: '<S966>/Switch' incorporates:
     *  Constant: '<S966>/Constant'
     */
    PDUCtl_StartReq = false;
  } else {
    /* Switch: '<S965>/Switch' incorporates:
     *  Logic: '<S965>/Logical Operator'
     *  Logic: '<S965>/Logical Operator1'
     *  Logic: '<S965>/Logical Operator2'
     *  UnitDelay: '<S965>/Unit Delay'
     *  UnitDelay: '<S965>/Unit Delay1'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_pr = ((rtb_SysResetStartOn &&
      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ks)) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_pr);

    /* Switch: '<S966>/Switch' incorporates:
     *  Logic: '<S966>/Logical Operator'
     *  UnitDelay: '<S966>/Unit Delay'
     */
    PDUCtl_StartReq = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_pr ||
                       PDUCtl_StartReq);
  }

  /* End of Switch: '<S965>/Switch' */
  /* End of Outputs for SubSystem: '<S921>/Lib_SR' */

  /* Update for UnitDelay: '<S965>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ks = rtb_SysResetStartOn;

  /* End of Outputs for SubSystem: '<S921>/Lib_RiseEdgeDetHold' */

  /* Update for UnitDelay: '<S921>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pd = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S964>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aw =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;
}

/* Output and update for atomic system: '<S436>/Subsystem' */
static void AppSwcBcm_Subsystem(void)
{
  boolean rtb_RelationalOperator1_et;
  boolean rtb_RelationalOperator_ij;

  /* RelationalOperator: '<S922>/Relational Operator' incorporates:
   *  Constant: '<S922>/Constant'
   */
  rtb_RelationalOperator_ij = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S922>/Relational Operator1' incorporates:
   *  Constant: '<S922>/Constant1'
   */
  rtb_RelationalOperator1_et = (AppSwcBcm_ARID_DEF.Switch1 == 1);

  /* Switch: '<S922>/Switch' incorporates:
   *  Logic: '<S922>/Logical Operator'
   *  Logic: '<S922>/Logical Operator1'
   *  Logic: '<S922>/Logical Operator2'
   *  Logic: '<S922>/Logical Operator3'
   *  Switch: '<S922>/Switch1'
   */
  if (rtb_RelationalOperator_ij && rtb_RelationalOperator1_et) {
    /* Switch: '<S922>/Switch' incorporates:
     *  Constant: '<S922>/Constant2'
     */
    PDUCtl_SysPwrModeAct = 2U;
  } else if ((!rtb_RelationalOperator_ij) && (!rtb_RelationalOperator1_et)) {
    /* Switch: '<S922>/Switch1' incorporates:
     *  Constant: '<S922>/Constant3'
     *  Switch: '<S922>/Switch'
     */
    PDUCtl_SysPwrModeAct = 0U;
  }

  /* End of Switch: '<S922>/Switch' */
}

/* Output and update for atomic system: '<S436>/Truth Table' */
static void AppSwcBcm_TruthTable_o(void)
{
  /* UnitDelay: '<S914>/Unit Delay' */
  /*  Example condition 1 */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kd) {
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

  /* End of UnitDelay: '<S914>/Unit Delay' */
}

/* System initialize for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S436>/PwrOff' */
  AppSwcBcm_PwrOff_Init();

  /* End of SystemInitialize for SubSystem: '<S436>/PwrOff' */

  /* SystemInitialize for Atomic SubSystem: '<S436>/PwrOn' */
  AppSwcBcm_PwrOn_Init();

  /* End of SystemInitialize for SubSystem: '<S436>/PwrOn' */

  /* SystemInitialize for Atomic SubSystem: '<S436>/StartReq' */
  AppSwcBcm_StartReq_Init();

  /* End of SystemInitialize for SubSystem: '<S436>/StartReq' */
}

/* Output and update for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion_a;

  /* UnitDelay: '<S436>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_n = PDUCtl_KeyChk;

  /* Outputs for Atomic SubSystem: '<S436>/PwrOn' */
  AppSwcBcm_PwrOn();

  /* End of Outputs for SubSystem: '<S436>/PwrOn' */

  /* Chart: '<S436>/Chart' */
  AppSwcBcm_Chart();

  /* Outputs for Atomic SubSystem: '<S436>/PwrOff' */
  AppSwcBcm_PwrOff();

  /* End of Outputs for SubSystem: '<S436>/PwrOff' */

  /* Outputs for Atomic SubSystem: '<S436>/Lib_SR' */
  /* Switch: '<S914>/Switch' incorporates:
   *  Constant: '<S914>/Constant'
   *  Logic: '<S914>/Logical Operator'
   *  UnitDelay: '<S914>/Unit Delay'
   */
  if (PDUCtl_PwrOff) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kd = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kd = (PDUCtl_PwrOn ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kd);
  }

  /* End of Switch: '<S914>/Switch' */
  /* End of Outputs for SubSystem: '<S436>/Lib_SR' */

  /* Truth Table: '<S436>/Truth Table' */
  AppSwcBcm_TruthTable_o();

  /* Outputs for Atomic SubSystem: '<S436>/Ovrd1' */
  /* Switch: '<S915>/Switch1' incorporates:
   *  Constant: '<S436>/Constant18'
   *  Constant: '<S436>/Constant19'
   */
  if (PDUCtl_J421IG1RlyCtlOvrdFlg_C) {
    PDUCtl_J421IG1RlyCtl = (uint8)PDUCtl_J421IG1RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S436>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG1RlyCtlFlg != 0);

    /* Switch: '<S915>/Switch2' */
    if (rtb_DataTypeConversion_a) {
      PDUCtl_J421IG1RlyCtl = 1U;
    } else {
      PDUCtl_J421IG1RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J421;
    }

    /* End of Switch: '<S915>/Switch2' */
  }

  /* End of Switch: '<S915>/Switch1' */
  /* End of Outputs for SubSystem: '<S436>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S436>/Ovrd2' */
  /* Switch: '<S916>/Switch1' incorporates:
   *  Constant: '<S436>/Constant1'
   *  Constant: '<S436>/Constant2'
   */
  if (PDUCtl_J437IG2RlyCtlOvrdFlg_C) {
    PDUCtl_J437IG2RlyCtl = (uint8)PDUCtl_J437IG2RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S436>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG2RlyCtlFlg != 0);

    /* Switch: '<S916>/Switch2' */
    if (rtb_DataTypeConversion_a) {
      PDUCtl_J437IG2RlyCtl = 1U;
    } else {
      PDUCtl_J437IG2RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J437;
    }

    /* End of Switch: '<S916>/Switch2' */
  }

  /* End of Switch: '<S916>/Switch1' */
  /* End of Outputs for SubSystem: '<S436>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S436>/RelayDig' */
  AppSwcBcm_RelayDig();

  /* End of Outputs for SubSystem: '<S436>/RelayDig' */

  /* Outputs for Atomic SubSystem: '<S436>/StartReq' */
  AppSwcBcm_StartReq();

  /* End of Outputs for SubSystem: '<S436>/StartReq' */

  /* Chart: '<S436>/RemtPwrCtlFb' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c20_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c20_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib = AppSwcBcm_IN_Init_h;
    PDUCtl_RemtPwrCtlFb = 0U;
    AppSwcBcm_ARID_DEF.Cnt_kb = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib) {
     case AppSwcBcm_IN_Fail_o:
      PDUCtl_RemtPwrCtlFb = 3U;
      if (AppSwcBcm_ARID_DEF.Cnt_kb >= PDUCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib = AppSwcBcm_IN_Trans_mq;
        PDUCtl_RemtPwrCtlFb = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_kb++;
      }
      break;

     case AppSwcBcm_IN_Init_h:
      PDUCtl_RemtPwrCtlFb = 0U;
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRemtPwrCtrlReq_enum != 0) && (PDUCtl_RemtPwrOff ||
           PDUCtl_RemtPwrOn)) {
        AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib = AppSwcBcm_IN_Suc_i;
        PDUCtl_RemtPwrCtlFb = 1U;
        tmp = AppSwcBcm_ARID_DEF.Cnt_kb + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_kb + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_kb = (uint8)tmp;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_e =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRemtPwrCtrlReq_enum != 0);

        /* Outputs for Function Call SubSystem: '<S920>/Lib_FailEdgeDet' */
        AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_e,
          &AppSwcBcm_ARID_DEF.LogicalOperator_c,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet);

        /* End of Outputs for SubSystem: '<S920>/Lib_FailEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_c && (!PDUCtl_RemtPwrOff) &&
            (!PDUCtl_RemtPwrOn)) {
          AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib = AppSwcBcm_IN_Fail_o;
          PDUCtl_RemtPwrCtlFb = 3U;
          tmp = AppSwcBcm_ARID_DEF.Cnt_kb + 1;
          if (AppSwcBcm_ARID_DEF.Cnt_kb + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.Cnt_kb = (uint8)tmp;
        }
      }
      break;

     case AppSwcBcm_IN_Suc_i:
      PDUCtl_RemtPwrCtlFb = 1U;
      if (AppSwcBcm_ARID_DEF.Cnt_kb >= PDUCtl_RemtCmdFbCnt_C) {
        AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib = AppSwcBcm_IN_Trans_mq;
        PDUCtl_RemtPwrCtlFb = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Cnt_kb++;
      }
      break;

     default:
      /* case IN_Trans: */
      PDUCtl_RemtPwrCtlFb = 0U;
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
          ->VIPM_TBOXRemtPwrCtrlReq_enum == 0) {
        AppSwcBcm_ARID_DEF.Lib_blIn_e =
          ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
           ->VIPM_TBOXRemtPwrCtrlReq_enum != 0);

        /* Outputs for Function Call SubSystem: '<S920>/Lib_FailEdgeDet' */
        AppSwcBcm_Lib_FailEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_e,
          &AppSwcBcm_ARID_DEF.LogicalOperator_c,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet);

        /* End of Outputs for SubSystem: '<S920>/Lib_FailEdgeDet' */
        AppSwcBcm_ARID_DEF.is_c20_PDUCtl_Lib = AppSwcBcm_IN_Init_h;
        AppSwcBcm_ARID_DEF.Cnt_kb = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S436>/RemtPwrCtlFb' */

  /* Outputs for Atomic SubSystem: '<S436>/Subsystem' */
  AppSwcBcm_Subsystem();

  /* End of Outputs for SubSystem: '<S436>/Subsystem' */

  /* Update for UnitDelay: '<S436>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_n = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S436>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S436>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f = PDUCtl_SysPowerSts;

  /* Update for UnitDelay: '<S436>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_b = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S436>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_n = AppSwcBcm_ARID_DEF.PDU_RemtPwrMode;

  /* Update for UnitDelay: '<S436>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_j = AppSwcBcm_ARID_DEF.PDUCtl_OTAPwrMode;

  /* Update for UnitDelay: '<S436>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_i = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S436>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d = PDUCtl_SysPowerSts;
}

/* System initialize for atomic system: '<S967>/NMCtl' */
static void AppSwcBcm_NMCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;

  /* InitializeConditions for Delay: '<S972>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = true;

  /* InitializeConditions for Delay: '<S973>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = true;

  /* InitializeConditions for Delay: '<S974>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a = true;

  /* InitializeConditions for Delay: '<S975>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = true;

  /* InitializeConditions for Delay: '<S976>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = true;

  /* SystemInitialize for Chart: '<S968>/LIB_NegPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_o);
}

/* Output and update for atomic system: '<S967>/NMCtl' */
static void AppSwcBcm_NMCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;
  sint32 tmp;
  boolean rtb_LIB_blOut_li;
  boolean rtb_LogicalOperator6_a;
  boolean rtb_LogicalOperator7_j;
  boolean rtb_RelationalOperator26;
  boolean rtb_RelationalOperator27;
  boolean rtb_RelationalOperator28;

  /* RelationalOperator: '<S968>/Relational Operator26' incorporates:
   *  Constant: '<S968>/Constant28'
   */
  rtb_RelationalOperator26 = (AppSwcBcm_ARID_DEF.BusCreator5.RKEReq != 0);

  /* Delay: '<S972>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_j) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_f =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S973>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_m) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_o =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Delay: '<S974>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_a) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_bd =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Delay: '<S975>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_g) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_br =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;
  }

  /* Delay: '<S976>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_b) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_gt =
      AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;
  }

  /* Logic: '<S968>/Logical Operator10' incorporates:
   *  Delay: '<S972>/Delay'
   *  Delay: '<S973>/Delay'
   *  Delay: '<S974>/Delay'
   *  Delay: '<S975>/Delay'
   *  Delay: '<S976>/Delay'
   *  Logic: '<S972>/Logical Operator1'
   *  Logic: '<S972>/Logical Operator2'
   *  Logic: '<S972>/Logical Operator3'
   *  Logic: '<S972>/Logical Operator4'
   *  Logic: '<S972>/Logical Operator5'
   *  Logic: '<S973>/Logical Operator1'
   *  Logic: '<S973>/Logical Operator2'
   *  Logic: '<S973>/Logical Operator3'
   *  Logic: '<S973>/Logical Operator4'
   *  Logic: '<S973>/Logical Operator5'
   *  Logic: '<S974>/Logical Operator1'
   *  Logic: '<S974>/Logical Operator2'
   *  Logic: '<S974>/Logical Operator3'
   *  Logic: '<S974>/Logical Operator4'
   *  Logic: '<S974>/Logical Operator5'
   *  Logic: '<S975>/Logical Operator1'
   *  Logic: '<S975>/Logical Operator2'
   *  Logic: '<S975>/Logical Operator3'
   *  Logic: '<S975>/Logical Operator4'
   *  Logic: '<S975>/Logical Operator5'
   *  Logic: '<S976>/Logical Operator1'
   *  Logic: '<S976>/Logical Operator2'
   *  Logic: '<S976>/Logical Operator3'
   *  Logic: '<S976>/Logical Operator4'
   *  Logic: '<S976>/Logical Operator5'
   *  Logic: '<S978>/Logical Operator'
   *  Logic: '<S978>/Logical Operator1'
   *  UnitDelay: '<S978>/Unit Delay'
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

  /* RelationalOperator: '<S968>/Relational Operator27' incorporates:
   *  Constant: '<S968>/Constant29'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->DrvPEAuthentAcsd == 1);

  /* Logic: '<S968>/Logical Operator6' */
  rtb_LogicalOperator6_a = (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    rtb_RelationalOperator27);

  /* RelationalOperator: '<S968>/Relational Operator28' incorporates:
   *  Constant: '<S968>/Constant30'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator28 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->FRPEAuthentAcsd == 1);

  /* Logic: '<S968>/Logical Operator7' */
  rtb_LogicalOperator7_j = (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
    rtb_RelationalOperator28);

  /* Logic: '<S968>/Logical Operator9' incorporates:
   *  Logic: '<S979>/Logical Operator'
   *  Logic: '<S979>/Logical Operator1'
   *  Logic: '<S980>/Logical Operator'
   *  Logic: '<S980>/Logical Operator1'
   *  UnitDelay: '<S979>/Unit Delay'
   *  UnitDelay: '<S980>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (rtb_LogicalOperator6_a && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ly)) ||
    (rtb_LogicalOperator7_j && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ey)));

  /* Chart: '<S968>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S970>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_NrmOffLib_RiseEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn,
    &AppSwcBcm_ARID_DEF.LogicalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet);
  if (AppSwcBcm_ARID_DEF.LogicalOperator) {
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* Logic: '<S968>/Logical Operator5' incorporates:
   *  Constant: '<S968>/Constant3'
   *  Constant: '<S968>/Constant4'
   *  Constant: '<S968>/Constant5'
   *  RelationalOperator: '<S968>/Relational Operator3'
   *  RelationalOperator: '<S968>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 0) ||
      (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3)) {
    if (AppSwcBcm_ARID_DEF.Cnt <= WakeUpCtl_WinCtlDelayTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt + 1;
      if (AppSwcBcm_ARID_DEF.Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt = (uint16)tmp;
      rtb_LIB_blOut_li = false;
    } else {
      rtb_LIB_blOut_li = true;
    }
  } else {
    rtb_LIB_blOut_li = true;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* End of Logic: '<S968>/Logical Operator5' */

  /* Chart: '<S968>/LIB_NegPluse2' incorporates:
   *  Constant: '<S968>/Constant'
   *  Constant: '<S968>/Constant19'
   *  Constant: '<S968>/Constant22'
   *  Logic: '<S968>/Logical Operator'
   *  Logic: '<S968>/Logical Operator1'
   *  Logic: '<S968>/Logical Operator3'
   *  RelationalOperator: '<S968>/Relational Operator'
   *  RelationalOperator: '<S968>/Relational Operator1'
   *  RelationalOperator: '<S968>/Relational Operator15'
   *  RelationalOperator: '<S968>/Relational Operator16'
   *  RelationalOperator: '<S968>/Relational Operator17'
   *  RelationalOperator: '<S968>/Relational Operator18'
   *  RelationalOperator: '<S968>/Relational Operator19'
   *  RelationalOperator: '<S968>/Relational Operator2'
   *  RelationalOperator: '<S968>/Relational Operator20'
   *  RelationalOperator: '<S968>/Relational Operator21'
   */
  AppSwcBcm_LIB_PosPluse2((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.PosLampSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.LowBeamSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.HiBeamSta) &&
    (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 2) && rtb_LIB_blOut_li &&
    ((!AppSwcBcm_ARID_DEF.BusCreator4.AutoLckSta) ||
     AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.HazardLightSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.EmerHazardLightSta),
    WakeUpCtl_CANSleepDelayTim_C, AppSwcBcm_ARID_DEF.Lib_blIn, &rtb_LIB_blOut_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse2);

  /* Logic: '<S968>/Logical Operator2' incorporates:
   *  Logic: '<S968>/Logical Operator11'
   *  Logic: '<S968>/Logical Operator12'
   *  Logic: '<S968>/Logical Operator4'
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
    AppSwcBcm_ARID_DEF.RelationalOperator12_j);

  /* Switch: '<S981>/Switch' */
  if (rtb_LIB_blOut_o) {
    /* Switch: '<S981>/Switch' incorporates:
     *  Constant: '<S981>/Constant'
     */
    WakeUpCtl_NMReq = false;
  } else {
    /* Switch: '<S981>/Switch' incorporates:
     *  Logic: '<S968>/Logical Operator8'
     *  Logic: '<S977>/Logical Operator'
     *  Logic: '<S977>/Logical Operator1'
     *  Logic: '<S981>/Logical Operator'
     *  UnitDelay: '<S977>/Unit Delay'
     *  UnitDelay: '<S981>/Unit Delay'
     */
    WakeUpCtl_NMReq = ((rtb_RelationalOperator26 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d3)) ||
                       AppSwcBcm_ARID_DEF.Lib_blIn || WakeUpCtl_NMReq);
  }

  /* End of Switch: '<S981>/Switch' */

  /* Update for Delay: '<S972>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_f =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S973>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_o =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

  /* Update for Delay: '<S974>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_a = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_bd =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S975>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_br =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

  /* Update for Delay: '<S976>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_gt =
    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

  /* Update for UnitDelay: '<S978>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a5 =
    AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw;

  /* Update for UnitDelay: '<S979>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ly = rtb_LogicalOperator6_a;

  /* Update for UnitDelay: '<S980>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ey = rtb_LogicalOperator7_j;

  /* Update for UnitDelay: '<S977>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d3 = rtb_RelationalOperator26;
}

/* System initialize for atomic system: '<S967>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;

  /* InitializeConditions for Delay: '<S987>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad = true;

  /* SystemInitialize for Chart: '<S969>/LIB_NegPluse1' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_k);
}

/* Outputs for atomic system: '<S967>/SleepCtl' */
static void AppSwcBcm_SleepCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_ao;

  /* RelationalOperator: '<S969>/Relational Operator29' incorporates:
   *  Constant: '<S969>/Constant31'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator29 = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S969>/Relational Operator30' incorporates:
   *  Constant: '<S969>/Constant32'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator30 = (AppSwcBcm_ARID_DEF.CCaller40 == 1);

  /* Delay: '<S987>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.icLoad) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;
  }

  /* Logic: '<S990>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S987>/Logical Operator1'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl;

  /* Logic: '<S989>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Delay: '<S987>/Delay'
   *  Logic: '<S987>/Logical Operator3'
   *  Logic: '<S987>/Logical Operator4'
   */
  rtb_LogicalOperator_ao = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl && (!AppSwcBcm_ARID_DEF.Delay_DSTATE_b));

  /* Logic: '<S969>/Logical Operator13' incorporates:
   *  Delay: '<S987>/Delay'
   *  Logic: '<S987>/Logical Operator2'
   *  Logic: '<S987>/Logical Operator5'
   *  Logic: '<S989>/Logical Operator'
   *  Logic: '<S989>/Logical Operator1'
   *  Logic: '<S990>/Logical Operator'
   *  Logic: '<S990>/Logical Operator1'
   *  Logic: '<S991>/Logical Operator'
   *  Logic: '<S991>/Logical Operator1'
   *  Logic: '<S992>/Logical Operator'
   *  Logic: '<S992>/Logical Operator1'
   *  UnitDelay: '<S989>/Unit Delay'
   *  UnitDelay: '<S990>/Unit Delay'
   *  UnitDelay: '<S991>/Unit Delay'
   *  UnitDelay: '<S992>/Unit Delay'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator29 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e)) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator30 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kz)) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_b && rtb_LogicalOperator) ||
     rtb_LogicalOperator_ao) || (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cl)) ||
    (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du)));

  /* Chart: '<S969>/LIB_NegPluse1' incorporates:
   *  Constant: '<S969>/Constant27'
   *  Logic: '<S969>/Logical Operator4'
   *  RelationalOperator: '<S969>/Relational Operator23'
   *  RelationalOperator: '<S969>/Relational Operator24'
   *  RelationalOperator: '<S969>/Relational Operator25'
   */
  AppSwcBcm_LIB_PosPluse2((!WakeUpCtl_NMReq) &&
    (!AppSwcBcm_ARID_DEF.BusCreator5.BoxLampSta) &&
    (!AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr), WakeUpCtl_LocalSleepDelayTim_C,
    rtb_LogicalOperator, &rtb_LIB_blOut_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse1);

  /* Logic: '<S969>/Logical Operator3' */
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
    AppSwcBcm_ARID_DEF.RelationalOperator12_j);

  /* Switch: '<S993>/Switch' incorporates:
   *  Constant: '<S993>/Constant'
   *  Logic: '<S969>/Logical Operator14'
   *  Logic: '<S988>/Logical Operator'
   *  Logic: '<S988>/Logical Operator1'
   *  Logic: '<S993>/Logical Operator'
   *  UnitDelay: '<S988>/Unit Delay'
   *  UnitDelay: '<S993>/Unit Delay'
   */
  if (rtb_LIB_blOut_k) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1 = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1 =
      ((AppSwcBcm_ARID_DEF.LogicalOperator3 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_an)) || rtb_LogicalOperator ||
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1);
  }

  /* End of Switch: '<S993>/Switch' */

  /* Logic: '<S969>/Logical Operator5' incorporates:
   *  UnitDelay: '<S993>/Unit Delay'
   */
  WakeUpCtl_SleepAllwd = !AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l1;
}

/* Update for atomic system: '<S967>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Update(void)
{
  /* Update for UnitDelay: '<S991>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e =
    AppSwcBcm_ARID_DEF.RelationalOperator29;

  /* Update for UnitDelay: '<S992>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kz =
    AppSwcBcm_ARID_DEF.RelationalOperator30;

  /* Update for Delay: '<S987>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.icLoad = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;

  /* Update for UnitDelay: '<S989>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cl =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw;

  /* Update for UnitDelay: '<S990>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du =
    AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw;

  /* Update for UnitDelay: '<S988>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_an = AppSwcBcm_ARID_DEF.LogicalOperator3;
}

/* System initialize for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S967>/NMCtl' */
  AppSwcBcm_NMCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S967>/NMCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S967>/SleepCtl' */
  AppSwcBcm_SleepCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S967>/SleepCtl' */
}

/* Outputs for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl(void)
{
  /* SignalConversion: '<S437>/Signal Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  BSW_WakeupReas = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VBSW_WakeupReasn_enum;

  /* RelationalOperator: '<S967>/Relational Operator14' incorporates:
   *  Constant: '<S967>/Constant14'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion3 = (BSW_WakeupReas == 49);

  /* RelationalOperator: '<S967>/Relational Operator1' incorporates:
   *  Constant: '<S967>/Constant1'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion2 = (BSW_WakeupReas == 54);

  /* RelationalOperator: '<S967>/Relational Operator5' incorporates:
   *  Constant: '<S967>/Constant5'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion1 = (BSW_WakeupReas == 58);

  /* RelationalOperator: '<S967>/Relational Operator6' incorporates:
   *  Constant: '<S967>/Constant6'
   */
  AppSwcBcm_ARID_DEF.DataTypeConversion = (BSW_WakeupReas == 59);

  /* RelationalOperator: '<S967>/Relational Operator7' incorporates:
   *  Constant: '<S967>/Constant7'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator7 = (BSW_WakeupReas == 61);

  /* RelationalOperator: '<S967>/Relational Operator8' incorporates:
   *  Constant: '<S967>/Constant8'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8 = (BSW_WakeupReas == 62);

  /* RelationalOperator: '<S967>/Relational Operator4' incorporates:
   *  Constant: '<S967>/Constant4'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4 = (BSW_WakeupReas == 57);

  /* RelationalOperator: '<S967>/Relational Operator9' incorporates:
   *  Constant: '<S967>/Constant9'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9 = (BSW_WakeupReas == 63);

  /* RelationalOperator: '<S967>/Relational Operator10' incorporates:
   *  Constant: '<S967>/Constant10'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator10 = (BSW_WakeupReas == 64);

  /* RelationalOperator: '<S967>/Relational Operator13' incorporates:
   *  Constant: '<S967>/Constant13'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12_j = (BSW_WakeupReas == 17);

  /* Outputs for Atomic SubSystem: '<S967>/NMCtl' */
  AppSwcBcm_NMCtl();

  /* End of Outputs for SubSystem: '<S967>/NMCtl' */

  /* RelationalOperator: '<S967>/Relational Operator12' incorporates:
   *  Constant: '<S967>/Constant12'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12_j = (BSW_WakeupReas == 66);

  /* RelationalOperator: '<S967>/Relational Operator22' incorporates:
   *  Constant: '<S967>/Constant23'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator22 = (BSW_WakeupReas == 50);

  /* Outputs for Atomic SubSystem: '<S967>/SleepCtl' */
  AppSwcBcm_SleepCtl();

  /* End of Outputs for SubSystem: '<S967>/SleepCtl' */
}

/* Update for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S967>/SleepCtl' */
  AppSwcBcm_SleepCtl_Update();

  /* End of Update for SubSystem: '<S967>/SleepCtl' */
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
  AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeDay = EEReadCtl_BJSTimeDay;
  AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeHour = EEReadCtl_BJSTimeHour;
  AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeMonth = EEReadCtl_BJSTimeMonth;
  AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeYear = EEReadCtl_BJSTimeYear;

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

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator12);

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
   *  BusCreator: '<S285>/Bus Creator3'
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
    AppSwcBcm_ARID_DEF.LogicalOperator_n2;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkAutoLck = DoorLckCtl_TrunkAutoLck;
  AppSwcBcm_ARID_DEF.BusCreator4.TboxLck = DoorLckCtl_TboxLck;
  AppSwcBcm_ARID_DEF.BusCreator4.TboxUnlck = DoorLckCtl_TboxUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkTboxUnlck = DoorLckCtl_TrunkTboxUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.RemoteLockFb = DoorLckCtl_RemoteLockFb;
  AppSwcBcm_ARID_DEF.BusCreator4.TboxAntiLck = DoorLckCtl_TboxAntiLck;

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
  AppSwcBcm_ARID_DEF.UnitDelay4 = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a;

  /* Outputs for Atomic SubSystem: '<S4>/AlmSysCtl' */
  AppSwcBcm_AlmSysCtl();

  /* End of Outputs for SubSystem: '<S4>/AlmSysCtl' */

  /* BusCreator: '<S4>/Bus Creator2' */
  AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts = AlmSysCtl_BodyWarnSts;
  AppSwcBcm_ARID_DEF.BusCreator2.AlrmWarnTimOut = AlmSysCtl_AlrmWarnTimOut;

  /* CCaller: '<S4>/C Caller9' */
  AppSwcBcm_ARID_DEF.Switch1 = GetHw_KL15A();

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

  /* CCaller: '<S4>/C Caller12' */
  BSW_HMACfg = GetVehCfg_HMACfg();

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
  AppSwcBcm_ARID_DEF.BusCreator5.AutoHiBeam = LampCtl_AutoHiBeam;
  AppSwcBcm_ARID_DEF.BusCreator5.BrkLampShortToBatOrOpen =
    LampCtl_BrkLampShortToBatOrOpen;
  AppSwcBcm_ARID_DEF.BusCreator5.BrkLampShortToGnd = LampCtl_BrkLampShortToGnd;

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

  /* BusCreator: '<S4>/Bus Creator' */
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

  rtb_BusCreator.DynDID_DoorOpRecord = DynDID_DoorOpRecord;
  rtb_BusCreator.DynDID_0xF200ECUPwrMode = DynDID_0xF200ECUPwrMode;

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
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0 =
    AppSwcBcm_ARID_DEF.BusCreator1.IGRlyIIgCls;

  /* Update for UnitDelay: '<S4>/Unit Delay4' incorporates:
   *  UnitDelay: '<S4>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a =
    AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* Update for UnitDelay: '<S4>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i =
    AppSwcBcm_ARID_DEF.BusCreator5.BrakeLightSw;

  /* Update for UnitDelay: '<S4>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE_jn =
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

  /* CCaller: '<S1>/C Caller9' */
  AppSwcBcm_ARID_DEF.CCaller9 = Get_NetWorkWakeup();

  /* Outputs for Atomic SubSystem: '<S1>/TboxTim' */
  AppSwcBcm_TboxTim();

  /* End of Outputs for SubSystem: '<S1>/TboxTim' */

  /* BusCreator: '<S1>/Bus Creator' */
  AppSwcBcm_ARID_DEF.BusCreator.BJSTimeDay = TboxTim_BJSTimeDay;
  AppSwcBcm_ARID_DEF.BusCreator.BJSTimeHour = TboxTim_BJSTimeHour;
  AppSwcBcm_ARID_DEF.BusCreator.BJSTimeMonth = TboxTim_BJSTimeMonth;
  AppSwcBcm_ARID_DEF.BusCreator.BJSTimeYear = TboxTim_BJSTimeYear;
  AppSwcBcm_ARID_DEF.BusCreator.HourDiff = TboxTim_HourDiff;

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
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_TboxTim_Bus(&AppSwcBcm_ARID_DEF.BusCreator);

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
    AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeDay = EEReadCtl_BJSTimeDay;
    AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeHour = EEReadCtl_BJSTimeHour;
    AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeMonth = EEReadCtl_BJSTimeMonth;
    AppSwcBcm_ARID_DEF.BusCreator12.BJSTimeYear = EEReadCtl_BJSTimeYear;

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

    /* SystemInitialize for BusCreator: '<S1>/Bus Creator' */
    AppSwcBcm_ARID_DEF.BusCreator.BJSTimeDay = TboxTim_BJSTimeDay;
    AppSwcBcm_ARID_DEF.BusCreator.BJSTimeHour = TboxTim_BJSTimeHour;
    AppSwcBcm_ARID_DEF.BusCreator.BJSTimeMonth = TboxTim_BJSTimeMonth;
    AppSwcBcm_ARID_DEF.BusCreator.BJSTimeYear = TboxTim_BJSTimeYear;
    AppSwcBcm_ARID_DEF.BusCreator.HourDiff = TboxTim_HourDiff;

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

    /* SystemInitialize for DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
    Rte_IrvIWrite_AppSwcBcm_Init_TboxTim_Bus(&AppSwcBcm_ARID_DEF.BusCreator);

    /* ConstCode for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_50ms'
     */
    /* ConstCode for Constant: '<S4>/Constant3' */
    BSW_IllmndSts = 1U;

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
