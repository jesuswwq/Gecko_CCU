/*
 * File: AppSwcBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1421
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct  9 16:23:34 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AppSwcBcm.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include <math.h>
#include "calPrmsBcm.h"
#include "monPrmsBcm.h"

/* Named constants for Chart: '<S143>/Chart6' */
#define AppSwcBcm_IN_Off               ((uint8)1U)
#define AppSwcBcm_IN_On                ((uint8)2U)

/* Named constants for Chart: '<S10>/DrvWinCtl' */
#define AppSwcBcm_IN_AutoDown          ((uint8)1U)
#define AppSwcBcm_IN_ManDown           ((uint8)2U)
#define AppSwcBcm_IN_ManUp             ((uint8)3U)
#define AppSwcBcm_IN_Standby           ((uint8)4U)

/* Named constants for Chart: '<S10>/PsgWinCtl' */
#define AppSwcBcm_IN_AutoDown_o        ((uint8)1U)
#define AppSwcBcm_IN_ManDown_h         ((uint8)2U)
#define AppSwcBcm_IN_ManUp_d           ((uint8)3U)
#define AppSwcBcm_IN_Standby_o         ((uint8)4U)

/* Named constants for Chart: '<S143>/Chart' */
#define AppSwcBcm_IN_Off_i             ((uint8)1U)
#define AppSwcBcm_IN_On_k              ((uint8)2U)

/* Named constants for Chart: '<S207>/Chart' */
#define AppSwcBcm_IN_FobidKey          ((uint8)1U)
#define AppSwcBcm_IN_Init              ((uint8)2U)
#define AppSwcBcm_IN_RelesKey          ((uint8)3U)

/* Named constants for Chart: '<S208>/Chart' */
#define AppSwcBcm_IN_Init_b            ((uint8)1U)
#define AppSwcBcm_IN_KeyNotInCar       ((uint8)2U)

/* Named constants for Chart: '<S208>/Chart3' */
#define AppSwcBcm_IN_Finish            ((uint8)1U)
#define AppSwcBcm_IN_KeyValid          ((uint8)3U)

/* Named constants for Chart: '<S209>/Chart' */
#define AppSwcBcm_IN_LSeekKeyOut       ((uint8)2U)
#define AppSwcBcm_IN_RSeekKeyOut       ((uint8)3U)

/* Named constants for Chart: '<S209>/Chart3' */
#define AppSwcBcm_IN_KeyValid_l        ((uint8)2U)

/* Named constants for Chart: '<S210>/Chart' */
#define AppSwcBcm_IN_PSSeekKeyOut      ((uint8)2U)

/* Named constants for Chart: '<S210>/Chart1' */
#define AppSwcBcm_IN_IMMOKeyValid      ((uint8)1U)
#define AppSwcBcm_IN_RemoteKeyValid    ((uint8)3U)

/* Named constants for Chart: '<S210>/Chart2' */
#define AppSwcBcm_IN_NOKeyValid        ((uint8)2U)

/* Named constants for Chart: '<S211>/Chart' */
#define AppSwcBcm_IN_LockWlcm          ((uint8)2U)
#define AppSwcBcm_IN_UnlockDay0to4     ((uint8)3U)
#define AppSwcBcm_IN_UnlockDay4to7     ((uint8)4U)
#define AppSwcBcm_IN_UnlockExcedDay7   ((uint8)5U)
#define AppSwcBcm_IN_WlcmLockReq       ((uint8)6U)
#define AppSwcBcm_IN_WlcmUnlockReq     ((uint8)7U)

/* Named constants for Chart: '<S273>/Alarm' */
#define AppSwcBcm_IN_SetON             ((uint8)1U)
#define AppSwcBcm_IN_SetOff            ((uint8)2U)

/* Named constants for Chart: '<S282>/Chart' */
#define AppSwcBcm_IN_Delay             ((uint8)1U)
#define AppSwcBcm_IN_SetOn             ((uint8)3U)

/* Named constants for Chart: '<S314>/Chart' */
#define AppSwcBcm_IN_Off_k             ((uint8)1U)
#define AppSwcBcm_IN_On_i              ((uint8)2U)

/* Named constants for Chart: '<S318>/Chart' */
#define AppSwcBcm_IN_Day               ((uint8)1U)
#define AppSwcBcm_IN_Night             ((uint8)2U)

/* Named constants for Chart: '<S435>/Chart' */
#define AppSwcBcm_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define AppSwcBcm_IN_SetOff_o          ((uint8)1U)
#define AppSwcBcm_IN_SetOn_d           ((uint8)2U)

/* Named constants for Chart: '<S436>/Chart' */
#define AppSwcBcm_IN_Off_g             ((uint8)1U)
#define AppSwcBcm_IN_On_km             ((uint8)2U)

/* Named constants for Chart: '<S438>/Chart' */
#define AppSwcBcm_IN_CrashDelay        ((uint8)1U)
#define AppSwcBcm_IN_CrashOff          ((uint8)2U)
#define AppSwcBcm_IN_CrashOn           ((uint8)3U)

/* Named constants for Chart: '<S339>/HazardLightLogic' */
#define AppSwcBcm_IN_EmerON            ((uint8)1U)
#define AppSwcBcm_IN_OFF               ((uint8)2U)
#define AppSwcBcm_IN_ON                ((uint8)3U)

/* Named constants for Chart: '<S442>/Chart' */
#define AppSwcBcm_IN_SetOn1            ((uint8)2U)
#define AppSwcBcm_IN_SetOn2            ((uint8)3U)

/* Named constants for Chart: '<S446>/Chart' */
#define AppSwcBcm_IN_Delay_b           ((uint8)1U)
#define AppSwcBcm_IN_SetOff_i          ((uint8)2U)
#define AppSwcBcm_IN_SetOn_a           ((uint8)3U)

/* Named constants for Chart: '<S339>/TurnIndcrArb2' */
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
#define AppSwcBcm_IN_Trans_l           ((uint8)7U)
#define AppSwcBcm_IN_TrunkWarn         ((uint8)8U)
#define AppSwcBcm_IN_VehMode           ((uint8)9U)

/* Named constants for Chart: '<S339>/TurnIndcrLogic' */
#define AppSwcBcm_IN_LongFlash         ((uint8)1U)
#define AppSwcBcm_IN_OFF_c             ((uint8)1U)
#define AppSwcBcm_IN_ShortFlash        ((uint8)2U)
#define AppSwcBcm_IN_TurnL             ((uint8)2U)
#define AppSwcBcm_IN_TurnR             ((uint8)3U)

/* Named constants for Chart: '<S339>/TurnIndcrSelect' */
#define AppSwcBcm_IN_TurnLOn           ((uint8)2U)
#define AppSwcBcm_IN_TurnLROn          ((uint8)3U)
#define AppSwcBcm_IN_TurnROn           ((uint8)4U)

/* Named constants for Chart: '<S453>/Chart' */
#define AppSwcBcm_IN_Init_f            ((uint8)1U)
#define AppSwcBcm_IN_Limit             ((uint8)2U)
#define AppSwcBcm_IN_Nrm               ((uint8)3U)
#define AppSwcBcm_IN_Show              ((uint8)4U)

/* Named constants for Chart: '<S573>/Chart' */
#define AppSwcBcm_IN_HiSpd             ((uint8)1U)
#define AppSwcBcm_IN_Inr               ((uint8)2U)
#define AppSwcBcm_IN_LowSpd            ((uint8)3U)
#define AppSwcBcm_IN_Maint             ((uint8)1U)
#define AppSwcBcm_IN_Mist              ((uint8)4U)
#define AppSwcBcm_IN_NO_ACTIVE_CHILD_f ((uint8)0U)
#define AppSwcBcm_IN_Nrm_j             ((uint8)2U)
#define AppSwcBcm_IN_Off_l             ((uint8)5U)
#define AppSwcBcm_IN_Wash              ((uint8)3U)

/* Named constants for Chart: '<S620>/AlmSysLogic' */
#define AppSwcBcm_IN_Alarm             ((uint8)1U)
#define AppSwcBcm_IN_Armed_a           ((uint8)2U)
#define AppSwcBcm_IN_Disarmed_e        ((uint8)3U)
#define AppSwcBcm_IN_Init_h            ((uint8)4U)
#define AppSwcBcm_IN_PartArmed_j       ((uint8)5U)

/* Named constants for Chart: '<S623>/DoorDrv' */
#define AppSwcBcm_IN_DrvIdle           ((uint8)1U)
#define AppSwcBcm_IN_InsDrvLck         ((uint8)2U)
#define AppSwcBcm_IN_InsDrvUnlck       ((uint8)3U)
#define AppSwcBcm_IN_OsDrvLck          ((uint8)4U)
#define AppSwcBcm_IN_OsDrvUnlck        ((uint8)5U)
#define AppSwcBcm_IN_TrunkUnlck        ((uint8)6U)

/* Named constants for Chart: '<S627>/Chart' */
#define AppSwcBcm_IN_LocalOn           ((uint8)1U)
#define AppSwcBcm_IN_OTA1On            ((uint8)2U)
#define AppSwcBcm_IN_OTAOn             ((uint8)3U)
#define AppSwcBcm_IN_PSOff             ((uint8)4U)

/* Named constants for Chart: '<S840>/BrkPwrOn' */
#define AppSwcBcm_IN_Invalid           ((uint8)1U)
#define AppSwcBcm_IN_Valid             ((uint8)2U)

/* Named constants for Chart: '<S129>/Chart' */
#define AppSwcBcm_IN_Off_p             ((uint8)1U)
#define AppSwcBcm_IN_On_a              ((uint8)2U)

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S315>/Constant28' */

/* Invariant block signals (default storage) */
const ConstB_AppSwcBcm_T AppSwcBcm_ConstB = {
  1.33399987F,                         /* '<S377>/Product' */
  -1.33399987F,                        /* '<S377>/Product1' */
  0U,                                  /* '<S230>/Data Type Conversion39' */
  1,                                   /* '<S680>/Relational Operator1' */
  1,                                   /* '<S710>/Relational Operator6' */
  1,                                   /* '<S361>/Relational Operator' */
  1                                    /* '<S362>/Relational Operator1' */
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
static uint16 AppSwcBcm_BitShift1_p(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u);
static void AppSwcBcm_Lib_RiseEdgeDet_c(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_a_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDet_d(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_n_T
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
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg);
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
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
static void AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_h_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_h_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDet_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_i_T
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
static void AppSwcBcm_Lib_FailEdgeDet_Update(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut);
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static uint16 AppSwcBcm_BitShift10_i(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift11_i(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3_f(uint16 rtu_u);
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
static void AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_c_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_d(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_c_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_PosPluseInit_Init(boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluseInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_LIB_PosPluseInit(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluseInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
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
static void AppSwcBcm_Lib_ChgDet(float32 rtu_Lib_In, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_FailEdgeDet_p(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_l_T *AppSwcBcm__ARID_DEF_arg);
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
static void AppSwcBcm_Lib_RiseEdgeDet_ou(void);
static void AppSwcBcm_Lib_ChangeEdge_d(void);
static void AppSwcBcm_WelcomeLampCtl_Init(void);
static void AppSwcBcm_WelcomeLampCtl(void);
static void AppSwcBcm_LampCtl_Init(void);
static void AppSwcBcm_LampCtl_Update(void);
static void AppSwcBcm_LampCtl(void);
static void AppSwcBcm_LockedRotorProt_Init(void);
static void AppSwcBcm_LockedRotorProt(void);
static void AppSwcBcm_SignalProcess_l(void);
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
static void AppSwcBcm_SignalProcess_b_Init(void);
static void AppSwcBcm_SignalProcess_c_Const(void);
static void AppSwcBcm_SignalProcess_m(void);
static void AppSwcBcm_DoorLckCtl_Init(void);
static void AppSwcBcm_DoorLckCtl_Const(void);
static void AppSwcBcm_DoorLckCtl(void);
static void AppSwcBcm_ESCLCtl_Init(void);
static void AppSwcBcm_ESCLCtl(void);
static void AppSwcBcm_IMMOCtl_Init(void);
static void AppSwcBcm_IMMOCtl(void);
static void AppSwcBcm_Chart(void);
static void AppSwcBcm_PwrOff(void);
static void AppSwcBcm_PwrOn(void);
static void AppSwcBcm_RelayDig(void);
static void AppSwcBcm_StartReq_Init(void);
static void AppSwcBcm_StartReq(void);
static void AppSwcBcm_Subsystem(void);
static void AppSwcBcm_TruthTable_m(void);
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
    AppSwcBcm_ARID_DEF.data1_p[0] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->CrashSta;
    AppSwcBcm_ARID_DEF.data1_p[1] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())->BodyWarnSts;
    AppSwcBcm_ARID_DEF.data1_p[2] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->FlwrMeHomeCtlFb;
    AppSwcBcm_ARID_DEF.data1_p[3] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->BackLadjvalFb;
    AppSwcBcm_ARID_DEF.data1_p[4] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())->HazardLightSta;
    AppSwcBcm_ARID_DEF.data1_p[5] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->IllmndLckSts;
    AppSwcBcm_ARID_DEF.data1_p[6] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->IllmndUnlockSts;
    AppSwcBcm_ARID_DEF.data1_p[7] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->SpdCtlLckSet;
    AppSwcBcm_ARID_DEF.data1_p[8] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;
    AppSwcBcm_ARID_DEF.data1_p[9] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_HornCtl_Bus())->LockHoornOnSt;
    AppSwcBcm_ARID_DEF.data1_p[10] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus())->WiprIntlTimeSetFb;
    tmp = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_Wiper_Bus())->InrTim;
    if (tmp > 255) {
      tmp = 255U;
    }

    AppSwcBcm_ARID_DEF.data1_p[11] = (uint8)tmp;
    AppSwcBcm_ARID_DEF.data1_p[12] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DoorLckCtl_Bus())->TrunkLckSw;
    while (i < 10) {
      AppSwcBcm_ARID_DEF.data1_p[i + 29] =
        AppSwcBcm_ARID_DEF.DynDID_Bus.DynDID_0xF230DoorOpRecord[i];
      AppSwcBcm_ARID_DEF.data1_p[i + 39] =
        AppSwcBcm_ARID_DEF.DynDID_Bus.DynDID_0xF233RemoteStartUpFailRecord[i];
      AppSwcBcm_ARID_DEF.data1_p[i + 49] =
        AppSwcBcm_ARID_DEF.DynDID_Bus.DynDID_0xF231TrunkOpRecord[i];
      AppSwcBcm_ARID_DEF.data1_p[i + 59] =
        AppSwcBcm_ARID_DEF.DynDID_Bus.DynDID_0xF232LocalStartUpFailRecord[i];
      i++;
    }
  }

  /* NvmBcmBlock02WriteData(data,8); */
  NvmBcmBlock_Imm_WriteData((uint8 *)&AppSwcBcm_ARID_DEF.data1_p[0], 128U);

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
  uint8 rtb_y_kz;
  uint8 rtb_y_l;
  uint8 rtb_y_l2;
  uint8 rtb_y_la;
  uint8 rtb_y_ld;
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
  rtb_y_kz = AppSwcBcm_BitShift1(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S6>/Bit Shift55' */
}

/*
 * System reset for atomic system:
 *    '<S125>/Lib_RiseEdgeDet'
 *    '<S163>/Lib_RiseEdgeDet'
 *    '<S165>/Lib_RiseEdgeDet'
 *    '<S167>/Lib_RiseEdgeDet'
 *    '<S169>/Lib_RiseEdgeDet'
 *    '<S186>/Lib_RiseEdgeDet'
 *    '<S188>/Lib_RiseEdgeDet'
 *    '<S190>/Lib_RiseEdgeDet'
 *    '<S192>/Lib_RiseEdgeDet'
 *    '<S194>/Lib_RiseEdgeDet'
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
 *    '<S163>/Lib_RiseEdgeDet'
 *    '<S165>/Lib_RiseEdgeDet'
 *    '<S167>/Lib_RiseEdgeDet'
 *    '<S169>/Lib_RiseEdgeDet'
 *    '<S186>/Lib_RiseEdgeDet'
 *    '<S188>/Lib_RiseEdgeDet'
 *    '<S190>/Lib_RiseEdgeDet'
 *    '<S192>/Lib_RiseEdgeDet'
 *    '<S194>/Lib_RiseEdgeDet'
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
 *    '<S310>/Lib_SR'
 *    '<S621>/Lib_SR'
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
 *    '<S310>/Lib_SR'
 *    '<S621>/Lib_SR'
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
        (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

      /* End of SystemReset for SubSystem: '<S125>/Lib_RiseEdgeDet' */

      /* SystemReset for Chart: '<S125>/LIB_Tim' */
      AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;

      /* SystemReset for Atomic SubSystem: '<S125>/Lib_SR' */
      AppSwcBcm_Lib_SR_Reset(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_o);

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
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

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
                     &AppSwcBcm_ARID_DEF.Switch_i5,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_o);

    /* End of Outputs for SubSystem: '<S125>/Lib_SR' */

    /* Update for UnitDelay: '<S125>/Unit Delay' */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = AppSwcBcm_ARID_DEF.Switch_i5;
  } else if (AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
    /* Disable for Switch: '<S128>/Switch' incorporates:
     *  Outport: '<S125>/RVMCtl_J42Heat'
     */
    AppSwcBcm_ARID_DEF.Switch_i5 = false;
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
    RVMCtl_J42Heat = AppSwcBcm_ARID_DEF.Switch_i5;
  }

  /* End of Switch: '<S124>/Switch' */
  /* End of Outputs for SubSystem: '<S7>/Ovrd' */
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
    AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_o;
    WinCtl_PsgWinSta = 0U;
    AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
    AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib) {
     case AppSwcBcm_IN_AutoDown_o:
      WinCtl_PsgWinSta = 3U;
      if (WinCtl_PsgWinReq != 3) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_o;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManDown_h:
      WinCtl_PsgWinSta = 4U;
      if (WinCtl_PsgWinReq != 2) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_o;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManUp_d:
      WinCtl_PsgWinSta = 2U;
      if (WinCtl_PsgWinReq != 1) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_o;
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
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManUp_d;
        WinCtl_PsgWinSta = 2U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = true;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_AutoDown_o;
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
 *    '<S141>/Bit Shift1'
 *    '<S141>/Bit Shift7'
 *    '<S338>/Bit Shift1'
 *    '<S661>/Bit Shift3'
 */
static uint16 AppSwcBcm_BitShift1_p(uint16 rtu_u)
{
  /* MATLAB Function: '<S144>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S141>/Bit Shift3'
 *    '<S338>/Bit Shift'
 *    '<S571>/Bit Shift5'
 *    '<S661>/Bit Shift5'
 */
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u)
{
  /* MATLAB Function: '<S145>/bit_shift' */
  return rtu_u;
}

/* Output and update for atomic system: '<S10>/SigProc' */
static void AppSwcBcm_SigProc(void)
{
  uint16 rtb_Switch1;
  boolean rtb_LogicalOperator1_d3m;

  /* Outputs for Atomic SubSystem: '<S141>/Bit Shift3' */
  /* Constant: '<S141>/Constant11' */
  rtb_Switch1 = AppSwcBcm_BitShift3(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S141>/Bit Shift3' */

  /* Switch: '<S141>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S141>/Bitwise AND3'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S141>/Switch1' incorporates:
     *  Constant: '<S141>/Constant15'
     */
    rtb_Switch1 = WinCtl_DrvWinSwResis_C;
  } else {
    /* Switch: '<S141>/Switch1' */
    rtb_Switch1 = BSW_J113DrvWinSwResis;
  }

  /* End of Switch: '<S141>/Switch3' */

  /* Logic: '<S141>/Logical Operator1' incorporates:
   *  Constant: '<S141>/Constant26'
   *  Constant: '<S141>/Constant31'
   *  RelationalOperator: '<S141>/Relational Operator2'
   *  RelationalOperator: '<S141>/Relational Operator3'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_DrvWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinDnMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S141>/Constant17'
   *  Constant: '<S141>/Constant18'
   *  Constant: '<S141>/Constant19'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_de >= (float32)WinCtl_DrvWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_de++;
      AppSwcBcm_ARID_DEF.cnt_heal_bi1 = (uint16)((float32)
        WinCtl_DrvWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_de = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bi1 == 0) {
      WinCtl_DrvWinDnSw = false;
    } else if (WinCtl_DrvWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bi1--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms1' */

  /* Logic: '<S141>/Logical Operator2' incorporates:
   *  Constant: '<S141>/Constant35'
   *  Constant: '<S141>/Constant36'
   *  RelationalOperator: '<S141>/Relational Operator4'
   *  RelationalOperator: '<S141>/Relational Operator5'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_DrvWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinAutoDnMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S141>/Constant23'
   *  Constant: '<S141>/Constant24'
   *  Constant: '<S141>/Constant25'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ej >= (float32)
         WinCtl_DrvWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ej++;
      AppSwcBcm_ARID_DEF.cnt_heal_gd = (uint16)((float32)
        WinCtl_DrvWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ej = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gd == 0) {
      WinCtl_DrvWinAutoDnSw = false;
    } else if (WinCtl_DrvWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_gd--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms2' */

  /* Logic: '<S141>/Logical Operator' incorporates:
   *  Constant: '<S141>/Constant20'
   *  Constant: '<S141>/Constant22'
   *  RelationalOperator: '<S141>/Relational Operator'
   *  RelationalOperator: '<S141>/Relational Operator1'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_DrvWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinUpMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S141>/Constant12'
   *  Constant: '<S141>/Constant13'
   *  Constant: '<S141>/Constant14'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hc >= (float32)WinCtl_DrvWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hc++;
      AppSwcBcm_ARID_DEF.cnt_heal_bi = (uint16)((float32)
        WinCtl_DrvWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hc = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bi == 0) {
      WinCtl_DrvWinUpSw = false;
    } else if (WinCtl_DrvWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bi--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S141>/Bit Shift7' */
  /* Constant: '<S141>/Constant21' */
  rtb_Switch1 = AppSwcBcm_BitShift1_p(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S141>/Bit Shift7' */

  /* Switch: '<S141>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S141>/Bitwise AND7'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S141>/Switch1' incorporates:
     *  Constant: '<S141>/Constant30'
     */
    rtb_Switch1 = WinCtl_PsgWinSwResis_C;
  } else {
    /* Switch: '<S141>/Switch1' */
    rtb_Switch1 = BSW_J26PsgWinSwResis;
  }

  /* End of Switch: '<S141>/Switch6' */

  /* Logic: '<S141>/Logical Operator3' incorporates:
   *  Constant: '<S141>/Constant40'
   *  Constant: '<S141>/Constant41'
   *  RelationalOperator: '<S141>/Relational Operator6'
   *  RelationalOperator: '<S141>/Relational Operator7'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_PsgWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinUpMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S141>/Constant27'
   *  Constant: '<S141>/Constant28'
   *  Constant: '<S141>/Constant29'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fq >= (float32)WinCtl_PsgWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fq++;
      AppSwcBcm_ARID_DEF.cnt_heal_ms = (uint16)((float32)
        WinCtl_PsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fq = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ms == 0) {
      WinCtl_PsgWinUpSw = false;
    } else if (WinCtl_PsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ms--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms4' */

  /* Logic: '<S141>/Logical Operator4' incorporates:
   *  Constant: '<S141>/Constant42'
   *  Constant: '<S141>/Constant43'
   *  RelationalOperator: '<S141>/Relational Operator8'
   *  RelationalOperator: '<S141>/Relational Operator9'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_PsgWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinDnMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S141>/Constant32'
   *  Constant: '<S141>/Constant33'
   *  Constant: '<S141>/Constant34'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gw >= (float32)WinCtl_PsgWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gw++;
      AppSwcBcm_ARID_DEF.cnt_heal_pd = (uint16)((float32)
        WinCtl_PsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gw = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pd == 0) {
      WinCtl_PsgWinDnSw = false;
    } else if (WinCtl_PsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pd--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms5' */

  /* Logic: '<S141>/Logical Operator5' incorporates:
   *  Constant: '<S141>/Constant44'
   *  Constant: '<S141>/Constant45'
   *  RelationalOperator: '<S141>/Relational Operator10'
   *  RelationalOperator: '<S141>/Relational Operator11'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_PsgWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinAutoDnMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S141>/Constant37'
   *  Constant: '<S141>/Constant38'
   *  Constant: '<S141>/Constant39'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b1 >= (float32)
         WinCtl_PsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_PsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b1++;
      AppSwcBcm_ARID_DEF.cnt_heal_bf = (uint16)((float32)
        WinCtl_PsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bf == 0) {
      WinCtl_PsgWinAutoDnSw = false;
    } else if (WinCtl_PsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bf--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S141>/Bit Shift1' */
  /* Constant: '<S141>/Constant1' */
  rtb_Switch1 = AppSwcBcm_BitShift1_p(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S141>/Bit Shift1' */

  /* Switch: '<S141>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S141>/Bitwise AND1'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S141>/Switch1' incorporates:
     *  Constant: '<S141>/Constant5'
     */
    rtb_Switch1 = WinCtl_DrvPsgWinSwResis_C;
  } else {
    /* Switch: '<S141>/Switch1' */
    rtb_Switch1 = BSW_J126DrvPsgWinSwResis;
  }

  /* End of Switch: '<S141>/Switch1' */

  /* Logic: '<S141>/Logical Operator6' incorporates:
   *  Constant: '<S141>/Constant46'
   *  Constant: '<S141>/Constant47'
   *  RelationalOperator: '<S141>/Relational Operator14'
   *  RelationalOperator: '<S141>/Relational Operator15'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_DrvPsgWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinUpMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S141>/Constant2'
   *  Constant: '<S141>/Constant3'
   *  Constant: '<S141>/Constant4'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ak >= (float32)
         WinCtl_DrvPsgWinUpTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ak++;
      AppSwcBcm_ARID_DEF.cnt_heal_m5 = (uint16)((float32)
        WinCtl_DrvPsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ak = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m5 == 0) {
      WinCtl_DrvPsgWinUpSw = false;
    } else if (WinCtl_DrvPsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_m5--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms7' */

  /* Logic: '<S141>/Logical Operator7' incorporates:
   *  Constant: '<S141>/Constant48'
   *  Constant: '<S141>/Constant49'
   *  RelationalOperator: '<S141>/Relational Operator16'
   *  RelationalOperator: '<S141>/Relational Operator17'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_DrvPsgWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinDnMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S141>/Constant6'
   *  Constant: '<S141>/Constant7'
   *  Constant: '<S141>/Constant8'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_pn >= (float32)
         WinCtl_DrvPsgWinDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_pn++;
      AppSwcBcm_ARID_DEF.cnt_heal_ln = (uint16)((float32)
        WinCtl_DrvPsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_pn = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ln == 0) {
      WinCtl_DrvPsgWinDnSw = false;
    } else if (WinCtl_DrvPsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ln--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms8' */

  /* Logic: '<S141>/Logical Operator8' incorporates:
   *  Constant: '<S141>/Constant50'
   *  Constant: '<S141>/Constant51'
   *  RelationalOperator: '<S141>/Relational Operator12'
   *  RelationalOperator: '<S141>/Relational Operator13'
   */
  rtb_LogicalOperator1_d3m = ((rtb_Switch1 >= WinCtl_DrvPsgWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinAutoDnMaxResis_C));

  /* Chart: '<S141>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S141>/Constant10'
   *  Constant: '<S141>/Constant16'
   *  Constant: '<S141>/Constant9'
   */
  if (rtb_LogicalOperator1_d3m) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_kp >= (float32)
         WinCtl_DrvPsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_kp++;
      AppSwcBcm_ARID_DEF.cnt_heal_in = (uint16)((float32)
        WinCtl_DrvPsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_kp = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_in == 0) {
      WinCtl_DrvPsgWinAutoDnSw = false;
    } else if (WinCtl_DrvPsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_in--;
    }
  }

  /* End of Chart: '<S141>/LIB_TPD_10ms9' */
}

/*
 * Output and update for function-call system:
 *    '<S159>/Lib_RiseEdgeDet'
 *    '<S160>/Lib_RiseEdgeDet'
 *    '<S161>/Lib_RiseEdgeDet'
 *    '<S162>/Lib_RiseEdgeDet'
 *    '<S173>/Lib_RiseEdgeDet'
 *    '<S174>/Lib_RiseEdgeDet'
 *    '<S175>/Lib_RiseEdgeDet'
 *    '<S176>/Lib_RiseEdgeDet'
 *    '<S177>/Lib_RiseEdgeDet'
 *    '<S178>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_c(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_a_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S163>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S163>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S10>/WinMotorProt' */
static void AppSwcBcm_WinMotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S142>/Logical Operator' incorporates:
   *  Constant: '<S142>/Constant'
   *  Constant: '<S142>/Constant4'
   *  RelationalOperator: '<S142>/Relational Operator'
   *  RelationalOperator: '<S142>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ik = ((WinCtl_DrvWinSta == 4) || (WinCtl_DrvWinSta
    == 3));

  /* Chart: '<S142>/LIB_CntLimit1' incorporates:
   *  SubSystem: '<S160>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ik,
    &AppSwcBcm_ARID_DEF.LogicalOperator_j0m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pb);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_j0m) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_p3 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_p3 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_p3 = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_jt = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_jt + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_jt + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_jt = (uint16)tmp;
  }

  /* Constant: '<S142>/Constant1' */
  if (AppSwcBcm_ARID_DEF.Cnt2_jt >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_p3 - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_p3 - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_p3 = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_jt = 0U;
  }

  /* End of Constant: '<S142>/Constant1' */

  /* Constant: '<S142>/Constant2' */
  WinCtl_DrvWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_p3 > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S142>/Relational Operator1' incorporates:
   *  Constant: '<S142>/Constant3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_lx = (WinCtl_DrvWinSta == 2);

  /* Chart: '<S142>/LIB_CntLimit' incorporates:
   *  SubSystem: '<S159>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_lx,
    &AppSwcBcm_ARID_DEF.LogicalOperator_gu,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ms);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_gu) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_lu + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_lu + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_lu = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_p = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_p + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_p + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_p = (uint16)tmp;
  }

  /* Constant: '<S142>/Constant14' */
  if (AppSwcBcm_ARID_DEF.Cnt2_p >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_lu - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_lu - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_lu = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_p = 0U;
  }

  /* End of Constant: '<S142>/Constant14' */

  /* Constant: '<S142>/Constant15' */
  WinCtl_DrvWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_lu > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S142>/Relational Operator4' incorporates:
   *  Constant: '<S142>/Constant10'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_jp = (WinCtl_PsgWinSta == 2);

  /* Chart: '<S142>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S161>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_jp,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mj,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_af);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_mj) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_i = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_d = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_d + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_d + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_d = (uint16)tmp;
  }

  /* Constant: '<S142>/Constant8' */
  if (AppSwcBcm_ARID_DEF.Cnt2_d >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_i - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_i - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_i = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_d = 0U;
  }

  /* End of Constant: '<S142>/Constant8' */

  /* Constant: '<S142>/Constant9' */
  WinCtl_PsgWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_i > WinCtl_WinProtNum_C);

  /* Logic: '<S142>/Logical Operator1' incorporates:
   *  Constant: '<S142>/Constant11'
   *  Constant: '<S142>/Constant7'
   *  RelationalOperator: '<S142>/Relational Operator3'
   *  RelationalOperator: '<S142>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_kw = ((WinCtl_PsgWinSta == 4) || (WinCtl_PsgWinSta
    == 3));

  /* Chart: '<S142>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S162>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_kw,
    &AppSwcBcm_ARID_DEF.LogicalOperator_bo,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dau);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_bo) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_f + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_f + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_f = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_a = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_a + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_a + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_a = (uint16)tmp;
  }

  /* Constant: '<S142>/Constant5' */
  if (AppSwcBcm_ARID_DEF.Cnt2_a >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_f - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_f - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_f = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_a = 0U;
  }

  /* End of Constant: '<S142>/Constant5' */

  /* Constant: '<S142>/Constant6' */
  WinCtl_PsgWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_f > WinCtl_WinProtNum_C);
}

/*
 * Output and update for function-call system:
 *    '<S171>/Lib_RiseEdgeDet'
 *    '<S172>/Lib_RiseEdgeDet'
 *    '<S821>/Lib_RiseEdgeDet'
 *    '<S822>/Lib_RiseEdgeDet'
 */
static void AppSwcBcm_Lib_RiseEdgeDet_d(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_n_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S186>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S186>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S143>/Chart6'
 *    '<S143>/Chart7'
 *    '<S143>/Chart8'
 *    '<S143>/Chart9'
 */
static void AppSwcBcm_Chart6_Init(boolean *rty_Lib_Out)
{
  *rty_Lib_Out = false;
}

/*
 * Output and update for atomic system:
 *    '<S143>/Chart6'
 *    '<S143>/Chart7'
 *    '<S143>/Chart8'
 *    '<S143>/Chart9'
 */
static void AppSwcBcm_Chart6(boolean rtu_Lib_blIn1, boolean rtu_Lib_blIn2, uint8
  rtu_Lib_blIn3, boolean *rty_Lib_Out, ARID_DEF_Chart6_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S143>/Chart6' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c8_WinCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c8_WinCtl_Lib = 1U;
    AppSwcBcm__ARID_DEF_arg->is_c8_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  } else if (AppSwcBcm__ARID_DEF_arg->is_c8_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_Lib_blIn1;

    /* Outputs for Function Call SubSystem: '<S177>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

    /* End of Outputs for SubSystem: '<S177>/Lib_RiseEdgeDet' */
    if (AppSwcBcm__ARID_DEF_arg->LogicalOperator && (!rtu_Lib_blIn2)) {
      AppSwcBcm__ARID_DEF_arg->is_c8_WinCtl_Lib = AppSwcBcm_IN_On;
      *rty_Lib_Out = true;
    }

    /* case IN_On: */
  } else if ((!rtu_Lib_blIn1) || rtu_Lib_blIn2 || (rtu_Lib_blIn3 == 0)) {
    AppSwcBcm__ARID_DEF_arg->is_c8_WinCtl_Lib = AppSwcBcm_IN_Off;
    *rty_Lib_Out = false;
  }

  /* End of Chart: '<S143>/Chart6' */
}

/*
 * System initialize for atomic system:
 *    '<S143>/LIB_NegPluse'
 *    '<S572>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S143>/LIB_NegPluse'
 *    '<S572>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_NegPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S143>/LIB_NegPluse' */
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

  /* End of Chart: '<S143>/LIB_NegPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S143>/LIB_PosPluse'
 *    '<S143>/LIB_PosPluse1'
 *    '<S317>/LIB_Tim'
 *    '<S551>/LIB_Tim'
 *    '<S842>/LIB_PosPluse'
 *    '<S842>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S143>/LIB_PosPluse'
 *    '<S143>/LIB_PosPluse1'
 *    '<S317>/LIB_Tim'
 *    '<S551>/LIB_Tim'
 *    '<S842>/LIB_PosPluse'
 *    '<S842>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_PosPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S143>/LIB_PosPluse' */
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

  /* End of Chart: '<S143>/LIB_PosPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S143>/LIB_TPD_10ms1'
 *    '<S143>/LIB_TPD_10ms3'
 *    '<S308>/LIB_TPD_10ms1'
 *    '<S319>/LIB_TPD_10ms8'
 *    '<S336>/LIB_TPD_10ms8'
 *    '<S338>/LIB_TPD_10ms11'
 *    '<S338>/LIB_TPD_10ms13'
 *    '<S680>/LIB_TPD_10ms'
 *    '<S680>/LIB_TPD_10ms1'
 *    '<S692>/LIB_TPD_10ms'
 *    ...
 */
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S143>/LIB_TPD_10ms1'
 *    '<S143>/LIB_TPD_10ms3'
 *    '<S308>/LIB_TPD_10ms1'
 *    '<S319>/LIB_TPD_10ms8'
 *    '<S336>/LIB_TPD_10ms8'
 *    '<S338>/LIB_TPD_10ms11'
 *    '<S338>/LIB_TPD_10ms13'
 *    '<S680>/LIB_TPD_10ms'
 *    '<S680>/LIB_TPD_10ms1'
 *    '<S692>/LIB_TPD_10ms'
 *    ...
 */
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S143>/LIB_TPD_10ms1' */
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

  /* End of Chart: '<S143>/LIB_TPD_10ms1' */
}

/* System initialize for atomic system: '<S10>/WinSwArb' */
static void AppSwcBcm_WinSwArb_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;
  boolean rtb_LIB_blOut_n;
  boolean rtb_LIB_blOut_e;

  /* SystemInitialize for Chart: '<S143>/Chart6' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_g);

  /* SystemInitialize for Chart: '<S143>/Chart7' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_k);

  /* SystemInitialize for Chart: '<S143>/Chart8' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out_i);

  /* SystemInitialize for Chart: '<S143>/Chart9' */
  AppSwcBcm_Chart6_Init(&AppSwcBcm_ARID_DEF.Lib_Out);

  /* SystemInitialize for Chart: '<S143>/LIB_NegPluse' */
  AppSwcBcm_LIB_NegPluse_Init(&rtb_LIB_blOut_e);

  /* SystemInitialize for Chart: '<S143>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_n);

  /* SystemInitialize for Chart: '<S143>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_l);

  /* SystemInitialize for Chart: '<S143>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_j5);

  /* SystemInitialize for Chart: '<S143>/LIB_TPD_10ms3' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_m1);
}

/* Output and update for atomic system: '<S10>/WinSwArb' */
static void AppSwcBcm_WinSwArb(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;
  boolean rtb_LIB_blOut_n;
  boolean rtb_LIB_blOut_e;
  uint8 rtb_Switch;
  uint8 tmp;
  boolean rtb_LogicalOperator1_nrr;
  boolean rtb_LogicalOperator2_cs;
  boolean rtb_LogicalOperator3_fp;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator3_kr;
  boolean rtb_RelationalOperator5_hn;

  /* Chart: '<S143>/Chart' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S143>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1_n < 3U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1_n++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_DrvWinAutoDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib == AppSwcBcm_IN_Off_i) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ie = WinCtl_DrvWinAutoDnSw;

    /* Outputs for Function Call SubSystem: '<S171>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_d(AppSwcBcm_ARID_DEF.Lib_blIn_ie,
      &AppSwcBcm_ARID_DEF.LogicalOperator_c0,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ax);

    /* End of Outputs for SubSystem: '<S171>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_c0 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_nh)) {
      AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_On_k;
      AppSwcBcm_ARID_DEF.temporalCounter_i1_n = 0U;
      WinCtl_DrvWinAutoDnReq = true;
    }

    /* case IN_On: */
  } else if (((WinCtl_DrvWinReq != 3) &&
              (AppSwcBcm_ARID_DEF.temporalCounter_i1_n >= 2)) ||
             AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_nh) {
    AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_DrvWinAutoDnReq = false;
  }

  /* End of Chart: '<S143>/Chart' */

  /* RelationalOperator: '<S143>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S143>/Relational Operator2'
   */
  rtb_RelationalOperator5_hn = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S143>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S143>/Relational Operator11'
   */
  rtb_RelationalOperator3_kr = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 5);

  /* Logic: '<S143>/Logical Operator9' */
  rtb_LogicalOperator9 = (rtb_RelationalOperator5_hn &&
    rtb_RelationalOperator3_kr);

  /* RelationalOperator: '<S143>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S143>/Relational Operator'
   */
  rtb_RelationalOperator3_kr = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 6);

  /* Logic: '<S143>/Logical Operator3' */
  rtb_LogicalOperator3_fp = (rtb_RelationalOperator5_hn &&
    rtb_RelationalOperator3_kr);

  /* Chart: '<S143>/LIB_PosPluse' incorporates:
   *  Constant: '<S143>/Constant40'
   *  Logic: '<S143>/Logical Operator10'
   */
  AppSwcBcm_LIB_PosPluse(WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnReq ||
    WinCtl_DrvWinUpSw || rtb_LogicalOperator9 || rtb_LogicalOperator3_fp,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_g);

  /* Chart: '<S143>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S143>/Constant34'
   *  Constant: '<S143>/Constant35'
   *  Constant: '<S143>/Constant36'
   *  Constant: '<S143>/Constant37'
   *  RelationalOperator: '<S143>/Relational Operator9'
   */
  AppSwcBcm_LIB_TPD_10ms1(BSW_DrvWinMotorCur >= WinCtl_WinMotorCurMax_C,
    WinCtl_WinMotorCurTimValid_C, WinCtl_WinMotorCurTimInValid_C, WinCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_m1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms3);

  /* Chart: '<S143>/Chart2' incorporates:
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S143>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_DrvWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib == AppSwcBcm_IN_Off_i) {
    AppSwcBcm_ARID_DEF.Lib_blIn_j3 = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S173>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_j3,
      &AppSwcBcm_ARID_DEF.LogicalOperator_di,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ei);

    /* End of Outputs for SubSystem: '<S173>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_di &&
        (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_nh)) {
      AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_DrvWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinDnSw) || AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_nh ||
             (WinCtl_DrvWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_DrvWinDnReq = false;
  }

  /* End of Chart: '<S143>/Chart2' */

  /* Chart: '<S143>/Chart3' incorporates:
   *  UnitDelay: '<S10>/Unit Delay3'
   *  UnitDelay: '<S143>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_DrvWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib == AppSwcBcm_IN_Off_i) {
    AppSwcBcm_ARID_DEF.Lib_blIn_nx = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S174>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_nx,
      &AppSwcBcm_ARID_DEF.LogicalOperator_d0,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h2);

    /* End of Outputs for SubSystem: '<S174>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_d0 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_n)) {
      AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_DrvWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinUpSw) || AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_n ||
             (WinCtl_DrvWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_DrvWinUpReq = false;
  }

  /* End of Chart: '<S143>/Chart3' */

  /* Switch: '<S143>/Switch' incorporates:
   *  Switch: '<S143>/Switch1'
   */
  if (WinCtl_DrvWinDnReq) {
    /* Switch: '<S143>/Switch' incorporates:
     *  Constant: '<S143>/Constant'
     */
    rtb_Switch = 2U;
  } else if (WinCtl_DrvWinAutoDnReq) {
    /* Switch: '<S143>/Switch1' incorporates:
     *  Constant: '<S143>/Constant1'
     *  Switch: '<S143>/Switch'
     */
    rtb_Switch = 3U;
  } else {
    /* Switch: '<S143>/Switch' incorporates:
     *  Switch: '<S143>/Switch1'
     *  Switch: '<S143>/Switch2'
     */
    rtb_Switch = WinCtl_DrvWinUpReq;
  }

  /* End of Switch: '<S143>/Switch' */

  /* RelationalOperator: '<S143>/Relational Operator3' incorporates:
   *  Constant: '<S143>/Constant19'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S143>/Relational Operator4'
   */
  rtb_RelationalOperator3_kr = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S143>/Relational Operator5' incorporates:
   *  Constant: '<S143>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator5_hn =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())->BodyWarnSts == 0);

  /* Chart: '<S143>/LIB_NegPluse' incorporates:
   *  Constant: '<S143>/Constant20'
   *  Logic: '<S143>/Logical Operator12'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator3_kr &&
    rtb_RelationalOperator5_hn, WinCtl_PwrOffWinValidTimMax_C, &rtb_LIB_blOut_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse);

  /* RelationalOperator: '<S143>/Relational Operator3' incorporates:
   *  Constant: '<S143>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_kr = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S143>/Logical Operator5' */
  rtb_RelationalOperator5_hn = (rtb_RelationalOperator3_kr || rtb_LIB_blOut_e);

  /* Chart: '<S143>/Chart6' incorporates:
   *  Logic: '<S143>/Logical Operator13'
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S143>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, WinCtl_DrvWinUpSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_nh, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_g,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart6);

  /* Chart: '<S143>/Chart7' incorporates:
   *  Logic: '<S143>/Logical Operator14'
   *  UnitDelay: '<S10>/Unit Delay3'
   *  UnitDelay: '<S143>/Unit Delay9'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_fp, WinCtl_DrvWinDnSw ||
                   AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_n ||
                   WinCtl_DrvWinAutoDnSw, WinCtl_DrvWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_k,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart7);

  /* Switch: '<S143>/Switch11' incorporates:
   *  Constant: '<S143>/Constant25'
   *  Logic: '<S143>/Logical Operator6'
   *  Logic: '<S143>/Logical Operator8'
   *  Switch: '<S143>/Switch8'
   */
  if (AppSwcBcm_ARID_DEF.LIB_bErrFlg_m1 || rtb_LIB_blOut_n) {
    WinCtl_DrvWinReq = 0U;
  } else {
    if (rtb_RelationalOperator5_hn) {
      /* Switch: '<S143>/Switch8' */
      tmp = rtb_Switch;
    } else {
      /* Switch: '<S143>/Switch8' incorporates:
       *  Constant: '<S143>/Constant32'
       */
      tmp = 0U;
    }

    /* Switch: '<S143>/Switch7' incorporates:
     *  Switch: '<S143>/Switch12'
     *  Switch: '<S143>/Switch8'
     */
    if (tmp != 0) {
      /* Switch: '<S143>/Switch7' */
      WinCtl_DrvWinReq = rtb_Switch;
    } else if (AppSwcBcm_ARID_DEF.Lib_Out_g) {
      /* Switch: '<S143>/Switch12' incorporates:
       *  Constant: '<S143>/Constant43'
       */
      WinCtl_DrvWinReq = 2U;
    } else {
      /* Switch: '<S143>/Switch12' incorporates:
       *  Switch: '<S143>/Switch3'
       */
      WinCtl_DrvWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_k;
    }

    /* End of Switch: '<S143>/Switch7' */
  }

  /* End of Switch: '<S143>/Switch11' */

  /* Logic: '<S143>/Logical Operator' */
  rtb_RelationalOperator3_kr = (WinCtl_PsgWinDnSw || WinCtl_DrvPsgWinDnSw);

  /* Chart: '<S143>/Chart4' incorporates:
   *  UnitDelay: '<S10>/Unit Delay4'
   *  UnitDelay: '<S143>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_PsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib == AppSwcBcm_IN_Off_i) {
    AppSwcBcm_ARID_DEF.Lib_blIn_fw = rtb_RelationalOperator3_kr;

    /* Outputs for Function Call SubSystem: '<S175>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_fw,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ka,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fi);

    /* End of Outputs for SubSystem: '<S175>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ka &&
        (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a)) {
      AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_PsgWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!rtb_RelationalOperator3_kr) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a || (WinCtl_PsgWinReq == 0))
  {
    AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_PsgWinDnReq = false;
  }

  /* End of Chart: '<S143>/Chart4' */

  /* Logic: '<S143>/Logical Operator1' */
  rtb_LogicalOperator1_nrr = (WinCtl_PsgWinAutoDnSw || WinCtl_DrvPsgWinAutoDnSw);

  /* Chart: '<S143>/Chart1' incorporates:
   *  UnitDelay: '<S10>/Unit Delay4'
   *  UnitDelay: '<S143>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1_o < 3U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1_o++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c2_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_PsgWinAutoDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib == AppSwcBcm_IN_Off_i) {
    AppSwcBcm_ARID_DEF.Lib_blIn_pf = rtb_LogicalOperator1_nrr;

    /* Outputs for Function Call SubSystem: '<S172>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_d(AppSwcBcm_ARID_DEF.Lib_blIn_pf,
      &AppSwcBcm_ARID_DEF.LogicalOperator_i1,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ch);

    /* End of Outputs for SubSystem: '<S172>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_i1 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a)) {
      AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib = AppSwcBcm_IN_On_k;
      AppSwcBcm_ARID_DEF.temporalCounter_i1_o = 0U;
      WinCtl_PsgWinAutoDnReq = true;
    }

    /* case IN_On: */
  } else if (((WinCtl_PsgWinReq != 3) &&
              (AppSwcBcm_ARID_DEF.temporalCounter_i1_o >= 2)) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a) {
    AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_PsgWinAutoDnReq = false;
  }

  /* End of Chart: '<S143>/Chart1' */

  /* Logic: '<S143>/Logical Operator2' */
  rtb_LogicalOperator2_cs = (WinCtl_DrvPsgWinUpSw || WinCtl_PsgWinUpSw);

  /* Chart: '<S143>/Chart5' incorporates:
   *  UnitDelay: '<S10>/Unit Delay2'
   *  UnitDelay: '<S143>/Unit Delay8'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c22_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c22_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_PsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib == AppSwcBcm_IN_Off_i) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ok = rtb_LogicalOperator2_cs;

    /* Outputs for Function Call SubSystem: '<S176>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ok,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ex,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_e);

    /* End of Outputs for SubSystem: '<S176>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ex &&
        (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_nh)) {
      AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib = AppSwcBcm_IN_On_k;
      WinCtl_PsgWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!rtb_LogicalOperator2_cs) ||
             AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_nh || (WinCtl_PsgWinReq == 0))
  {
    AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib = AppSwcBcm_IN_Off_i;
    WinCtl_PsgWinUpReq = false;
  }

  /* End of Chart: '<S143>/Chart5' */

  /* Switch: '<S143>/Switch4' incorporates:
   *  Switch: '<S143>/Switch5'
   */
  if (WinCtl_PsgWinDnReq) {
    /* Switch: '<S143>/Switch4' incorporates:
     *  Constant: '<S143>/Constant12'
     */
    rtb_Switch = 2U;
  } else if (WinCtl_PsgWinAutoDnReq) {
    /* Switch: '<S143>/Switch5' incorporates:
     *  Constant: '<S143>/Constant13'
     *  Switch: '<S143>/Switch4'
     */
    rtb_Switch = 3U;
  } else {
    /* Switch: '<S143>/Switch4' incorporates:
     *  Switch: '<S143>/Switch5'
     *  Switch: '<S143>/Switch6'
     */
    rtb_Switch = WinCtl_PsgWinUpReq;
  }

  /* End of Switch: '<S143>/Switch4' */

  /* Chart: '<S143>/Chart9' incorporates:
   *  Logic: '<S143>/Logical Operator15'
   *  UnitDelay: '<S10>/Unit Delay4'
   *  UnitDelay: '<S143>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator9, rtb_LogicalOperator2_cs ||
                   AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a, WinCtl_PsgWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart9);

  /* Chart: '<S143>/Chart8' incorporates:
   *  Logic: '<S143>/Logical Operator16'
   *  UnitDelay: '<S10>/Unit Delay2'
   *  UnitDelay: '<S143>/Unit Delay8'
   */
  AppSwcBcm_Chart6(rtb_LogicalOperator3_fp, rtb_LogicalOperator1_nrr ||
                   rtb_RelationalOperator3_kr ||
                   AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_nh, WinCtl_PsgWinReq,
                   &AppSwcBcm_ARID_DEF.Lib_Out_i,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Chart8);

  /* Chart: '<S143>/LIB_PosPluse1' incorporates:
   *  Constant: '<S143>/Constant8'
   *  Logic: '<S143>/Logical Operator11'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator2_cs || rtb_RelationalOperator3_kr ||
    WinCtl_PsgWinAutoDnReq || rtb_LogicalOperator9 || rtb_LogicalOperator3_fp,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1_a);

  /* Chart: '<S143>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S143>/Constant10'
   *  Constant: '<S143>/Constant11'
   *  Constant: '<S143>/Constant44'
   *  Constant: '<S143>/Constant48'
   *  RelationalOperator: '<S143>/Relational Operator7'
   */
  AppSwcBcm_LIB_TPD_10ms1(BSW_PsgWinMotorCur >= WinCtl_WinMotorCurMax_C,
    WinCtl_WinMotorCurTimValid_C, WinCtl_WinMotorCurTimInValid_C, WinCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_j5,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_b);

  /* Switch: '<S143>/Switch10' incorporates:
   *  Constant: '<S143>/Constant27'
   *  Logic: '<S143>/Logical Operator4'
   *  Logic: '<S143>/Logical Operator7'
   *  Switch: '<S143>/Switch9'
   */
  if (AppSwcBcm_ARID_DEF.LIB_bErrFlg_j5 || rtb_LIB_blOut_l) {
    WinCtl_PsgWinReq = 0U;
  } else {
    if (rtb_RelationalOperator5_hn) {
      /* Switch: '<S143>/Switch9' */
      tmp = rtb_Switch;
    } else {
      /* Switch: '<S143>/Switch9' incorporates:
       *  Constant: '<S143>/Constant33'
       */
      tmp = 0U;
    }

    /* Switch: '<S143>/Switch13' incorporates:
     *  Switch: '<S143>/Switch14'
     *  Switch: '<S143>/Switch9'
     */
    if (tmp != 0) {
      /* Switch: '<S143>/Switch13' */
      WinCtl_PsgWinReq = rtb_Switch;
    } else if (AppSwcBcm_ARID_DEF.Lib_Out) {
      /* Switch: '<S143>/Switch14' incorporates:
       *  Constant: '<S143>/Constant16'
       */
      WinCtl_PsgWinReq = 2U;
    } else {
      /* Switch: '<S143>/Switch14' incorporates:
       *  Switch: '<S143>/Switch15'
       */
      WinCtl_PsgWinReq = (uint8)AppSwcBcm_ARID_DEF.Lib_Out_i;
    }

    /* End of Switch: '<S143>/Switch13' */
  }

  /* End of Switch: '<S143>/Switch10' */
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
  /* Switch: '<S139>/Switch1' incorporates:
   *  Constant: '<S10>/Constant1'
   */
  if (WinCtl_J53DrvWinDnOvrdFlg_C) {
    /* Switch: '<S139>/Switch1' incorporates:
     *  Constant: '<S10>/Constant2'
     */
    WinCtl_J53DrvWinDn = WinCtl_J53DrvWinDnOvrdVal_C;
  } else {
    /* Switch: '<S139>/Switch1' incorporates:
     *  Switch: '<S139>/Switch2'
     */
    WinCtl_J53DrvWinDn = AppSwcBcm_ARID_DEF.WinCtl_J53;
  }

  /* End of Switch: '<S139>/Switch1' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd4' */

  /* Chart: '<S10>/PsgWinCtl' */
  AppSwcBcm_PsgWinCtl();

  /* Outputs for Atomic SubSystem: '<S10>/WinMotorProt' */
  AppSwcBcm_WinMotorProt();

  /* End of Outputs for SubSystem: '<S10>/WinMotorProt' */

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd2' */
  /* Switch: '<S137>/Switch' incorporates:
   *  Constant: '<S10>/Constant3'
   */
  if (WinCtl_J55PsgWinUpOvrdFlg_C) {
    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S10>/Constant4'
     */
    WinCtl_J55PsgWinUp = WinCtl_J55PsgWinUpOvrdVal_C;
  } else {
    /* Switch: '<S137>/Switch' */
    WinCtl_J55PsgWinUp = AppSwcBcm_ARID_DEF.WinCtl_J55;
  }

  /* End of Switch: '<S137>/Switch' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd3' */
  /* Switch: '<S138>/Switch' incorporates:
   *  Constant: '<S10>/Constant5'
   */
  if (WinCtl_J57PsgWinDnOvrdFlg_C) {
    /* Switch: '<S138>/Switch' incorporates:
     *  Constant: '<S10>/Constant6'
     */
    WinCtl_J57PsgWinDn = WinCtl_J57PsgWinDnOvrdVal_C;
  } else {
    /* Switch: '<S138>/Switch' */
    WinCtl_J57PsgWinDn = AppSwcBcm_ARID_DEF.WinCtl_J57;
  }

  /* End of Switch: '<S138>/Switch' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S10>/Ovrd1' */
  /* Switch: '<S136>/Switch1' incorporates:
   *  Constant: '<S10>/Constant18'
   */
  if (WinCtl_J51DrvWinUpOvrdFlg_C) {
    /* Switch: '<S136>/Switch1' incorporates:
     *  Constant: '<S10>/Constant19'
     */
    WinCtl_J51DrvWinUp = WinCtl_J51DrvWinUpOvrdVal_C;
  } else {
    /* Switch: '<S136>/Switch1' incorporates:
     *  Switch: '<S136>/Switch2'
     */
    WinCtl_J51DrvWinUp = AppSwcBcm_ARID_DEF.WinCtl_J51;
  }

  /* End of Switch: '<S136>/Switch1' */
  /* End of Outputs for SubSystem: '<S10>/Ovrd1' */

  /* Update for UnitDelay: '<S10>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_n = WinCtl_DrvWinUpProt;

  /* Update for UnitDelay: '<S10>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_nh = WinCtl_PsgWinUpProt;

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_nh = WinCtl_DrvWinDnProt;

  /* Update for UnitDelay: '<S10>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_a = WinCtl_PsgWinDnProt;
}

/* Outputs for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl(void)
{
  sint32 tmp;
  uint8 rtb_CCaller;
  boolean rtb_Compare_p;
  boolean rtb_LogicalOperator2_a;
  boolean rtb_LogicalOperator3_pm;

  /* CCaller: '<S206>/C Caller' */
  rtb_CCaller = Get_PEAuth_FobStatus();

  /* Logic: '<S209>/Logical Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S209>/Logical Operator2'
   */
  rtb_LogicalOperator3_pm = !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DrvSeatSw;

  /* RelationalOperator: '<S219>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S209>/Relational Operator'
   */
  rtb_Compare_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VGSM_VehActGearPstn_enum <= 1);

  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S209>/Logical Operator'
   */
  rtb_LogicalOperator2_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus()
    )->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarRRSw);

  /* Logic: '<S209>/Logical Operator3' */
  rtb_LogicalOperator3_pm = (rtb_LogicalOperator3_pm && rtb_Compare_p &&
    rtb_LogicalOperator2_a);

  /* Logic: '<S209>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S222>/Compare'
   *  UnitDelay: '<S209>/Unit Delay'
   */
  rtb_Compare_p = ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_av) &&
                   (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw
                   && rtb_LogicalOperator3_pm);

  /* Logic: '<S209>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S223>/Compare'
   *  UnitDelay: '<S209>/Unit Delay1'
   */
  rtb_LogicalOperator3_pm = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_n) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw &&
    rtb_LogicalOperator3_pm);

  /* Chart: '<S209>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    PEPSCtl_DrvPEAuthentAcsd = 0U;
    PEPSCtl_KeyInCarSta = 0U;
    AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
    PEPSCtl_FRPEAuthentAcsd = 0U;
    AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 0U;
    AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 0U;
    Clear_PEStatus();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_b:
      if (rtb_Compare_p) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_LSeekKeyOut;
        Set_PEAuth_FobReq(1U);
        AppSwcBcm_ARID_DEF.count_ik = 0U;
        AppSwcBcm_ARID_DEF.count1_l = 0U;
      } else if (rtb_LogicalOperator3_pm) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_RSeekKeyOut;
        Set_PEAuth_FobReq(2U);
        AppSwcBcm_ARID_DEF.count_ik = 0U;
        AppSwcBcm_ARID_DEF.count1_l = 0U;
      }
      break;

     case AppSwcBcm_IN_LSeekKeyOut:
      if ((AppSwcBcm_ARID_DEF.count_ik >= 10) ||
          (AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
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
          tmp = AppSwcBcm_ARID_DEF.count_ik + 1;
          if (AppSwcBcm_ARID_DEF.count_ik + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_ik = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_ik + 1;
          if (AppSwcBcm_ARID_DEF.count_ik + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_ik = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_ik + 1;
          if (AppSwcBcm_ARID_DEF.count_ik + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_ik = (uint8)tmp;
        }

        if (rtb_CCaller == 0) {
          if (AppSwcBcm_ARID_DEF.count1_l >= 150) {
            PEPSCtl_DrvPEAuthentAcsd = 2U;
            AppSwcBcm_ARID_DEF.DrvPEAuth_Tmout_flg = 1U;
            AppSwcBcm_ARID_DEF.count1_l = 0U;
          } else {
            tmp = AppSwcBcm_ARID_DEF.count1_l + 1;
            if (AppSwcBcm_ARID_DEF.count1_l + 1 > 255) {
              tmp = 255;
            }

            AppSwcBcm_ARID_DEF.count1_l = (uint8)tmp;
          }
        }
      }
      break;

     default:
      /* case IN_RSeekKeyOut: */
      if ((AppSwcBcm_ARID_DEF.count_ik >= 10) ||
          (AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg == 1)) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
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
          tmp = AppSwcBcm_ARID_DEF.count_ik + 1;
          if (AppSwcBcm_ARID_DEF.count_ik + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_ik = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_ik + 1;
          if (AppSwcBcm_ARID_DEF.count_ik + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_ik = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_ik + 1;
          if (AppSwcBcm_ARID_DEF.count_ik + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_ik = (uint8)tmp;
        }

        if (rtb_CCaller == 0) {
          if (AppSwcBcm_ARID_DEF.count1_l >= 150) {
            PEPSCtl_FRPEAuthentAcsd = 2U;
            AppSwcBcm_ARID_DEF.FRPEAuth_Tmout_flg = 1U;
            AppSwcBcm_ARID_DEF.count1_l = 0U;
          } else {
            tmp = AppSwcBcm_ARID_DEF.count1_l + 1;
            if (AppSwcBcm_ARID_DEF.count1_l + 1 > 255) {
              tmp = 255;
            }

            AppSwcBcm_ARID_DEF.count1_l = (uint8)tmp;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S209>/Chart' */

  /* Chart: '<S209>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    AppSwcBcm_ARID_DEF.count_cw = 0.0;
    PEPSCtl_AvaluebleKeyInCar = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib == AppSwcBcm_IN_Init_b) {
    PEPSCtl_AvaluebleKeyInCar = 0U;
    if (AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar == 1.0F) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_l;
      AppSwcBcm_ARID_DEF.count_cw = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_AvaluebleKeyInCar = 1U;
    if (AppSwcBcm_ARID_DEF.count_cw >= 1000.0) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
      AppSwcBcm_ARID_DEF.count_cw = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count_cw++;
    }
  }

  /* End of Chart: '<S209>/Chart3' */

  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  Constant: '<S213>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S213>/Compare'
   */
  rtb_LogicalOperator2_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus()
    )->BodyWarnSts == 0);

  /* Logic: '<S207>/Logical Operator' incorporates:
   *  Constant: '<S214>/Constant'
   *  RelationalOperator: '<S214>/Compare'
   *  UnitDelay: '<S207>/Unit Delay'
   */
  rtb_LogicalOperator3_pm = (rtb_LogicalOperator2_a &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jk > 0));

  /* CCaller: '<S207>/C Caller1' */
  rtb_CCaller = Get_FobdKeyNum();

  /* Chart: '<S207>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib) {
     case AppSwcBcm_IN_FobidKey:
      if ((PEPSCtl_FrbdnKeyNr > 0) || (AppSwcBcm_ARID_DEF.count_l > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      } else if (rtb_LogicalOperator3_pm) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_l = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_l + 1;
        if (AppSwcBcm_ARID_DEF.count_l + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_l = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     case AppSwcBcm_IN_Init:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->OsLckSta == 1) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_FobidKey;
        AppSwcBcm_ARID_DEF.count_l = 0U;
        Set_PSAuth_FobReq(2U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else if (rtb_LogicalOperator3_pm) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_l = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     default:
      /* case IN_RelesKey: */
      if ((PEPSCtl_FrbdnKeyNr == 0) || (AppSwcBcm_ARID_DEF.count_l > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_l + 1;
        if (AppSwcBcm_ARID_DEF.count_l + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_l = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;
    }
  }

  /* End of Chart: '<S207>/Chart' */

  /* CCaller: '<S206>/C Caller1' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S210>/Relational Operator5'
   */
  rtb_LogicalOperator2_a = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())
    ->BrakeLightSw;

  /* Logic: '<S210>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S210>/Relational Operator4'
   *  UnitDelay: '<S210>/Unit Delay1'
   */
  rtb_LogicalOperator3_pm = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k) &&
    rtb_LogicalOperator2_a);

  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S210>/Relational Operator2'
   */
  rtb_LogicalOperator2_a = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus()
    )->DrvSeatSw;

  /* RelationalOperator: '<S219>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S210>/Relational Operator3'
   */
  rtb_Compare_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S210>/Chart' incorporates:
   *  Logic: '<S210>/Logical Operator1'
   *  Logic: '<S210>/Logical Operator2'
   *  Logic: '<S210>/Logical Operator5'
   *  RelationalOperator: '<S210>/Relational Operator1'
   *  RelationalOperator: '<S210>/Relational Operator6'
   *  UnitDelay: '<S210>/Unit Delay'
   *  UnitDelay: '<S210>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
    PEPSCtl_PSAuthentRes = 0U;
    AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
    AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
    PEPSCtl_PSReq = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib == AppSwcBcm_IN_Init_b) {
    PEPSCtl_PSReq = 0U;
    if ((rtb_LogicalOperator3_pm || ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ct) &&
          rtb_LogicalOperator2_a)) && (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e ==
         0) && rtb_Compare_p) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_PSSeekKeyOut;
      AppSwcBcm_ARID_DEF.count_g = 0U;
      AppSwcBcm_ARID_DEF.count1 = 0U;
      Set_PSAuth_FobReq(1U);
      PEPSCtl_PSReq = 1U;
    }
  } else {
    /* case IN_PSSeekKeyOut: */
    PEPSCtl_PSReq = 1U;
    if (AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg == 1) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
      AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 0U;
      PEPSCtl_PSAuthentRes = 0U;
      AppSwcBcm_ARID_DEF.BCM_KeySta = 0U;
      AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 0U;
      PEPSCtl_PSReq = 0U;
      Clear_PSStatus();
    } else {
      tmp = AppSwcBcm_ARID_DEF.count_g + 1;
      if (AppSwcBcm_ARID_DEF.count_g + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.count_g = (uint16)tmp;
      if (rtb_CCaller == 1) {
        if (AppSwcBcm_ARID_DEF.count1 >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 1U;
          tmp = AppSwcBcm_ARID_DEF.count1 + 1;
          if (AppSwcBcm_ARID_DEF.count1 + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1 = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 2) {
        if (AppSwcBcm_ARID_DEF.count1 >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          tmp = AppSwcBcm_ARID_DEF.count1 + 1;
          if (AppSwcBcm_ARID_DEF.count1 + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1 = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 3) {
        if (AppSwcBcm_ARID_DEF.count1 >= 10) {
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 1U;
          AppSwcBcm_ARID_DEF.BCM_KeySta = 3U;
          tmp = AppSwcBcm_ARID_DEF.count1 + 1;
          if (AppSwcBcm_ARID_DEF.count1 + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count1 = (uint8)tmp;
        }
      }

      if (rtb_CCaller == 0) {
        if (AppSwcBcm_ARID_DEF.count_g >= 200) {
          AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound = 1U;
          PEPSCtl_PSAuthentRes = 2U;
          AppSwcBcm_ARID_DEF.PSSeekKey_Finish_flg = 1U;
        } else {
          PEPSCtl_PSAuthentRes = 0U;
        }
      }
    }
  }

  /* End of Chart: '<S210>/Chart' */

  /* Chart: '<S210>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
    AppSwcBcm_ARID_DEF.count_c = 0.0;
    PEPSCtl_KeySta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib) {
     case AppSwcBcm_IN_IMMOKeyValid:
      PEPSCtl_KeySta = 3U;
      if (AppSwcBcm_ARID_DEF.count_c >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
        AppSwcBcm_ARID_DEF.count_c = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_c++;
      }
      break;

     case AppSwcBcm_IN_Init:
      PEPSCtl_KeySta = 0U;
      switch (AppSwcBcm_ARID_DEF.BCM_KeySta) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_RemoteKeyValid;
        AppSwcBcm_ARID_DEF.count_c = 0.0;
        PEPSCtl_KeySta = 1U;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_IMMOKeyValid;
        AppSwcBcm_ARID_DEF.count_c = 0.0;
        PEPSCtl_KeySta = 3U;
        break;
      }
      break;

     default:
      /* case IN_RemoteKeyValid: */
      PEPSCtl_KeySta = 1U;
      if (AppSwcBcm_ARID_DEF.count_c >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
        AppSwcBcm_ARID_DEF.count_c = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_c++;
      }
      break;
    }
  }

  /* End of Chart: '<S210>/Chart1' */

  /* Chart: '<S210>/Chart2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_h = AppSwcBcm_ARID_DEF.Power_Mode_start_j;
  AppSwcBcm_ARID_DEF.Power_Mode_start_j =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev_i =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_d;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_d =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_h =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev_i =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    AppSwcBcm_ARID_DEF.count_i = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    AppSwcBcm_ARID_DEF.Cur_IndicationKeyCloser = 0.0;
    AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
  } else if (AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib == AppSwcBcm_IN_Init_b) {
    if (AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound == 1) {
      AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_NOKeyValid;
      AppSwcBcm_ARID_DEF.count_i = 0.0;
      AppSwcBcm_ARID_DEF.NoKey_count++;
      AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
    } else {
      AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
      if (AppSwcBcm_ARID_DEF.NoKey_Tmcount >= 3000.0) {
        AppSwcBcm_ARID_DEF.NoKey_count = 0.0;
        AppSwcBcm_ARID_DEF.NoKey_Tmcount = 0.0;
      }
    }

    /* case IN_NOKeyValid: */
  } else if ((AppSwcBcm_ARID_DEF.count_i >= 1000.0) ||
             ((AppSwcBcm_ARID_DEF.Power_Mode_prev_h !=
               AppSwcBcm_ARID_DEF.Power_Mode_start_j) &&
              (AppSwcBcm_ARID_DEF.Power_Mode_start_j == 2)) ||
             ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev_i !=
               AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_d) &&
              (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_d == 2))) {
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    AppSwcBcm_ARID_DEF.count_i = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    AppSwcBcm_ARID_DEF.Cur_IndicationKeyCloser = 0.0;
    AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
  } else {
    AppSwcBcm_ARID_DEF.count_i++;
    AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
    if (AppSwcBcm_ARID_DEF.NoKey_count >= 2.0) {
      AppSwcBcm_ARID_DEF.Cur_IndicationKeyCloser = 1.0;
      PEPSCtl_WarnNoKeyFound = 0U;
    } else {
      PEPSCtl_WarnNoKeyFound = 1U;
    }

    if (AppSwcBcm_ARID_DEF.NoKey_Tmcount >= 3000.0) {
      AppSwcBcm_ARID_DEF.NoKey_count = 0.0;
      AppSwcBcm_ARID_DEF.NoKey_Tmcount = 0.0;
    }
  }

  /* End of Chart: '<S210>/Chart2' */

  /* Chart: '<S210>/Chart3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_m = AppSwcBcm_ARID_DEF.Power_Mode_start_k;
  AppSwcBcm_ARID_DEF.Power_Mode_start_k =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c7_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_m =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c7_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    AppSwcBcm_ARID_DEF.count = 0.0;
    PEPSCtl_IndicationKeyCloser = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib == AppSwcBcm_IN_Init_b) {
    PEPSCtl_IndicationKeyCloser = 0U;
    if (AppSwcBcm_ARID_DEF.Cur_IndicationKeyCloser == 1.0) {
      AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_l;
      AppSwcBcm_ARID_DEF.count = 0.0;
      PEPSCtl_IndicationKeyCloser = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_IndicationKeyCloser = 1U;
    if ((AppSwcBcm_ARID_DEF.count >= 1000.0) ||
        ((AppSwcBcm_ARID_DEF.Power_Mode_prev_m !=
          AppSwcBcm_ARID_DEF.Power_Mode_start_k) &&
         (AppSwcBcm_ARID_DEF.Power_Mode_start_k == 2)) ||
        ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
          AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
         (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
      AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
      AppSwcBcm_ARID_DEF.count = 0.0;
      PEPSCtl_IndicationKeyCloser = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count++;
    }
  }

  /* End of Chart: '<S210>/Chart3' */

  /* Chart: '<S210>/Chart5' incorporates:
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

  /* End of Chart: '<S210>/Chart5' */

  /* CCaller: '<S206>/C Caller2' */
  rtb_CCaller = Get_Wlcm_FunStatus();

  /* CCaller: '<S206>/C Caller3' */
  Get_PollingWork_State();

  /* RelationalOperator: '<S219>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S211>/Relational Operator3'
   */
  rtb_Compare_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())
                   ->BodyWarnSts > 0);

  /* Switch: '<S211>/Switch' incorporates:
   *  Constant: '<S211>/Constant4'
   *  Logic: '<S211>/Logical Operator5'
   *  RelationalOperator: '<S211>/Relational Operator2'
   *  UnitDelay: '<S211>/Unit Delay'
   *  UnitDelay: '<S211>/Unit Delay1'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gj != 0) || (!rtb_Compare_p)) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i = 0U;
  }

  /* End of Switch: '<S211>/Switch' */

  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S211>/Relational Operator5'
   */
  rtb_LogicalOperator2_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S219>/Compare' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S211>/Relational Operator1'
   */
  rtb_Compare_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
                   ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S211>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S211>/Unit Delay1'
   */
  rtb_LogicalOperator3_pm = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i != 0) &&
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC())
     ->VIPM_HUIllmndEntrySts_enum != 0) && rtb_LogicalOperator2_a &&
    rtb_Compare_p);

  /* Chart: '<S211>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_b:
      if (rtb_LogicalOperator3_pm) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_UnlockDay0to4;
      }
      break;

     case AppSwcBcm_IN_LockWlcm:
      if (rtb_CCaller == 3) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmLockReq;
        PEPSCtl_LckWlcmReq = 1U;
      }
      break;

     case AppSwcBcm_IN_UnlockDay0to4:
      if (rtb_CCaller == 2) {
        AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_WlcmUnlockReq;
        PEPSCtl_UnlckWlcmReq = 1U;
      }
      break;

     case AppSwcBcm_IN_UnlockDay4to7:
     case AppSwcBcm_IN_UnlockExcedDay7:
      break;

     case AppSwcBcm_IN_WlcmLockReq:
      PEPSCtl_LckWlcmReq = 1U;
      break;

     default:
      /* case IN_WlcmUnlockReq: */
      PEPSCtl_UnlckWlcmReq = 1U;
      break;
    }
  }

  /* End of Chart: '<S211>/Chart' */

  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S208>/Logical Operator1'
   */
  rtb_LogicalOperator2_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus()
    )->DoorAjarFLSw && (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw);

  /* RelationalOperator: '<S219>/Compare' incorporates:
   *  Constant: '<S219>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_Compare_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode ==
                   2);

  /* Logic: '<S208>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S208>/Logical Operator'
   *  Logic: '<S208>/Logical Operator2'
   *  RelationalOperator: '<S217>/Compare'
   *  RelationalOperator: '<S218>/Compare'
   *  UnitDelay: '<S208>/Unit Delay'
   *  UnitDelay: '<S208>/Unit Delay1'
   */
  rtb_LogicalOperator3_pm = (rtb_LogicalOperator2_a &&
    ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pi) ||
     (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b0)) && rtb_Compare_p &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->VehStop &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw);

  /* CCaller: '<S208>/C Caller7' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Chart: '<S208>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else if (AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib == AppSwcBcm_IN_Init_b) {
    if (rtb_LogicalOperator3_pm) {
      AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_KeyNotInCar;
      AppSwcBcm_ARID_DEF.count_o = 0U;
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
      Set_PSAuth_FobReq(1U);
    }

    /* case IN_KeyNotInCar: */
  } else if (AppSwcBcm_ARID_DEF.count_o >= 1000) {
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_b;
    PEPSCtl_WarnKeyOutReminder = 0U;
    AppSwcBcm_ARID_DEF.Warnkeyout_flg = 0U;
    Clear_PSStatus();
  } else {
    if (rtb_CCaller == 2) {
      AppSwcBcm_ARID_DEF.Warnkeyout_flg = 1U;
      PEPSCtl_WarnKeyOutReminder = 1U;
    }

    if (AppSwcBcm_ARID_DEF.Warnkeyout_flg == 1) {
      tmp = AppSwcBcm_ARID_DEF.count_o + 1;
      if (AppSwcBcm_ARID_DEF.count_o + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.count_o = (uint16)tmp;
    }
  }

  /* End of Chart: '<S208>/Chart' */

  /* CCaller: '<S206>/C Caller7' */
  rtb_CCaller = Get_KeyBat_VolLow();

  /* Chart: '<S208>/Chart3' */
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

  /* End of Chart: '<S208>/Chart3' */
}

/* Update for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl_Update(void)
{
  /* Update for UnitDelay: '<S209>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_av =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw;

  /* Update for UnitDelay: '<S209>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_n =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw;

  /* Update for UnitDelay: '<S207>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jk =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S210>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S210>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ct =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* Update for UnitDelay: '<S210>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_e = PEPSCtl_KeySta;

  /* Update for UnitDelay: '<S211>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gj =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S208>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pi =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Update for UnitDelay: '<S208>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b0 =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw;
}

/* Output and update for atomic system: '<S230>/HwOutBCM' */
static void AppSwcBcm_HwOutBCM(void)
{
  uint8 rtb_DataTypeConversion30;

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion14'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J421IG1RlyCtl;

  /* CCaller: '<S235>/HwIG1RlyCls' */
  SetHw_IG1RlyCls(rtb_DataTypeConversion30);

  /* CCaller: '<S235>/HwHzrdLampOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion16'
   *  Logic: '<S256>/Logical Operator'
   *  Logic: '<S256>/Logical Operator1'
   *  RelationalOperator: '<S256>/Relational Operator'
   */
  SetHw_HzrdLampOn((uint8)(AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta &&
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta &&
    (AppSwcBcm_ARID_DEF.BusCreator.HazardLightSta ||
     AppSwcBcm_ARID_DEF.BusCreator.EmerHazardLightSta)));

  /* CCaller: '<S235>/HwCabinLampPWM' incorporates:
   *  Constant: '<S235>/Constant43'
   */
  SetHw_CabinLampPWM(200U, AppSwcBcm_ARID_DEF.BusCreator.DomeLampPwmDuty);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion15'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J437IG2RlyCtl;

  /* CCaller: '<S235>/HwIG2RlyCls' */
  SetHw_IG2RlyCls(rtb_DataTypeConversion30);

  /* CCaller: '<S235>/HwBackLightCtl' incorporates:
   *  Constant: '<S235>/Constant'
   */
  SetHw_BackLightDrv(100U, AppSwcBcm_ARID_DEF.BusCreator.J408BackLampPWM);

  /* CCaller: '<S235>/HwDrvSeatHeatCtl' incorporates:
   *  Constant: '<S235>/Constant1'
   */
  SetHw_DrvSeatHeat(200U, AppSwcBcm_ARID_DEF.SeatCtl_Bus.CN167DrvSeatHtPWM);

  /* CCaller: '<S235>/HwWiprOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion'
   */
  SetHw_WiprOn(AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv);

  /* CCaller: '<S235>/HwWiprHiSpd' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion1'
   */
  SetHw_WiprHiSpd(AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv);

  /* CCaller: '<S235>/HwFrntWshrOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion2'
   */
  SetHw_FrntWshrOn(AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion3'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J56DoorUnlck;

  /* CCaller: '<S235>/HwGlbDoorUnlck' */
  SetHw_GlbDoorUnlck(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion4'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J54DoorLck;

  /* CCaller: '<S235>/HwGlbDoorLck' */
  SetHw_GlbDoorLck(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion5'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J51DrvWinUp;

  /* CCaller: '<S235>/HwDrvrWinUp' */
  SetHw_DrvrWinUp(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion6'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J53DrvWinDn;

  /* CCaller: '<S235>/HwDrvrWinDwn' */
  SetHw_DrvrWinDwn(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion7'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J55PsgWinUp;

  /* CCaller: '<S235>/HwPsngrWinUp' */
  SetHw_PsngrWinUp(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion8'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->J57PsgWinDn;

  /* CCaller: '<S235>/HwPsngrWinDwn' */
  SetHw_PsngrWinDwn(rtb_DataTypeConversion30);

  /* CCaller: '<S235>/HwPstnLampOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion9'
   */
  SetHw_PstnLampOn(AppSwcBcm_ARID_DEF.BusCreator.PosLampSta);

  /* CCaller: '<S235>/HwTurnLampOnLeft' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion10'
   */
  SetHw_TurnLampOnLeft(AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta);

  /* CCaller: '<S235>/HwTurnLampOnRght' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion11'
   */
  SetHw_TurnLampOnRght(AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta);

  /* CCaller: '<S235>/HwBrkLghtOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion12'
   */
  SetHw_BrkLghtOn(AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSta);

  /* CCaller: '<S235>/HwRvrsLampOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion13'
   */
  SetHw_RvrsLampOn(AppSwcBcm_ARID_DEF.BusCreator.ReverseLampSta);

  /* CCaller: '<S235>/HwLoBeamOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion17'
   */
  SetHw_LoBeamOn(AppSwcBcm_ARID_DEF.BusCreator.LowBeamSta);

  /* CCaller: '<S235>/HwHiBeamOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion18'
   */
  SetHw_HiBeamOn(AppSwcBcm_ARID_DEF.BusCreator.HiBeamSta);

  /* CCaller: '<S235>/HwAlrmHornOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion19'
   */
  SetHw_AlrmHornOn(AppSwcBcm_ARID_DEF.BusCreator9.HornDrv);

  /* CCaller: '<S235>/HwRearFogLampOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion20'
   */
  SetHw_RearFogLampOn(AppSwcBcm_ARID_DEF.BusCreator.FogLampRSta);

  /* CCaller: '<S235>/HwSavePwrEnbl' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion21'
   */
  SetHw_SavePwrEnbl(AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr);

  /* CCaller: '<S235>/HwDayRunLghtOn' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion23'
   */
  SetHw_DayRunLghtOn(AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta);

  /* DataTypeConversion: '<S235>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S235>/DataTypeConversion24'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J511TrunkUnlck;

  /* CCaller: '<S235>/HwTrunkUnlck' */
  Set_TrunkUnLock(rtb_DataTypeConversion30);

  /* CCaller: '<S235>/HwBSDLeftCtl' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion25'
   */
  Set_BSDLeftCtl(AppSwcBcm_ARID_DEF.BusCreator.BSDLeftCtl);

  /* CCaller: '<S235>/HwBSDRightCtl' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion26'
   */
  Set_BSDRightCtl(AppSwcBcm_ARID_DEF.BusCreator.BSDRightCtl);

  /* CCaller: '<S235>/HwESCLPwrSup' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion27'
   */
  SetHw_PwrSup(AppSwcBcm_ARID_DEF.ESCLCtl_Bus.J436PwrSup);

  /* CCaller: '<S235>/HwRVMHeatCtl' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion28'
   */
  SetHw_RearMirrorHeat(AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat);

  /* CCaller: '<S235>/HwBoxLampCtl' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion29'
   */
  SetHw_BoxLampSta(AppSwcBcm_ARID_DEF.BusCreator.BoxLampSta);

  /* CCaller: '<S235>/HwFrontFogLampCtl' incorporates:
   *  DataTypeConversion: '<S235>/DataTypeConversion30'
   */
  SetHw_FrontFogLamps(AppSwcBcm_ARID_DEF.BusCreator.FogLampFSta);
}

/*
 * System initialize for atomic system:
 *    '<S239>/Lib_RiseEdgeDelay'
 *    '<S240>/Lib_RiseEdgeDelay'
 *    '<S240>/Lib_RiseEdgeDelay1'
 *    '<S242>/Lib_RiseEdgeDelay'
 *    '<S242>/Lib_RiseEdgeDelay1'
 *    '<S552>/Lib_RiseEdgeDelay'
 *    '<S820>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S239>/Lib_RiseEdgeDelay'
 *    '<S240>/Lib_RiseEdgeDelay'
 *    '<S240>/Lib_RiseEdgeDelay1'
 *    '<S242>/Lib_RiseEdgeDelay'
 *    '<S242>/Lib_RiseEdgeDelay1'
 *    '<S552>/Lib_RiseEdgeDelay'
 *    '<S820>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16DelayTim, boolean *rty_LIB_blOut,
  ARID_DEF_Lib_RiseEdgeDelay_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rtb_LogicalOperator1_d4;

  /* Outputs for Function Call SubSystem: '<S257>/Lib_RiseEdgeDet' */
  /* Logic: '<S259>/Logical Operator1' incorporates:
   *  UnitDelay: '<S259>/Unit Delay'
   */
  rtb_LogicalOperator1_d4 = !AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S259>/Unit Delay' incorporates:
   *  Chart: '<S239>/Lib_RiseEdgeDelay'
   */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_LIB_blIn;

  /* Chart: '<S239>/Lib_RiseEdgeDelay' incorporates:
   *  Logic: '<S259>/Logical Operator'
   */
  if (rtu_LIB_blIn && rtb_LogicalOperator1_d4) {
    AppSwcBcm__ARID_DEF_arg->Cnt = rtu_LIB_u16DelayTim;
    *rty_LIB_blOut = true;
  }

  /* End of Outputs for SubSystem: '<S257>/Lib_RiseEdgeDet' */
  if (AppSwcBcm__ARID_DEF_arg->Cnt <= 0) {
    *rty_LIB_blOut = false;
  } else {
    AppSwcBcm__ARID_DEF_arg->Cnt--;
  }
}

/* System initialize for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx_Init(void)
{
  boolean LIB_blOut_pp;

  /* SystemInitialize for Chart: '<S239>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_ch);

  /* SystemInitialize for Chart: '<S240>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_ob);

  /* SystemInitialize for Chart: '<S240>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_d);

  /* SystemInitialize for Chart: '<S242>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_pp);

  /* SystemInitialize for Chart: '<S242>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_pp);
}

/* Output and update for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx(void)
{
  uint8 rtb_MultiportSwitch;
  uint8 rtb_MultiportSwitch_m;
  boolean rtb_RelationalOperator2_p4;

  /* DataTypeConversion: '<S230>/Data Type Conversion' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Left =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion1' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Right =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion2' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Rear =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampRSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion3' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLampSta =
    AppSwcBcm_ARID_DEF.BusCreator.PosLampSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion4' incorporates:
   *  Logic: '<S244>/Logical Operator'
   *  Logic: '<S244>/Logical Operator1'
   *  RelationalOperator: '<S244>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardLampSts = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta &&
     AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta &&
     (AppSwcBcm_ARID_DEF.BusCreator.HazardLightSta ||
      AppSwcBcm_ARID_DEF.BusCreator.EmerHazardLightSta));

  /* DataTypeConversion: '<S230>/Data Type Conversion5' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSta =
    AppSwcBcm_ARID_DEF.BusCreator.HiBeamSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion6' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamSta =
    AppSwcBcm_ARID_DEF.BusCreator.LowBeamSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion7' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Front =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampFSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion8' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AutoLampStatus =
    AppSwcBcm_ARID_DEF.BusCreator.AutoLampSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion9' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLightSta =
    AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLampSta =
    AppSwcBcm_ARID_DEF.BusCreator.ReverseLampSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion11' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLampSta =
    AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSta;

  /* MultiPortSwitch: '<S236>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrMod) {
   case 0:
    /* MultiPortSwitch: '<S236>/Multiport Switch' incorporates:
     *  Constant: '<S236>/Constant'
     */
    rtb_MultiportSwitch = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S236>/Multiport Switch' incorporates:
     *  Constant: '<S236>/Constant1'
     */
    rtb_MultiportSwitch = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S236>/Multiport Switch' incorporates:
     *  Constant: '<S236>/Constant2'
     */
    rtb_MultiportSwitch = 4U;
    break;

   case 3:
    /* MultiPortSwitch: '<S236>/Multiport Switch' incorporates:
     *  Constant: '<S236>/Constant3'
     */
    rtb_MultiportSwitch = 1U;
    break;

   case 4:
    /* MultiPortSwitch: '<S236>/Multiport Switch' incorporates:
     *  Constant: '<S236>/Constant4'
     */
    rtb_MultiportSwitch = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S236>/Multiport Switch' incorporates:
     *  UnitDelay: '<S236>/Unit Delay'
     */
    rtb_MultiportSwitch = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ez;
    break;
  }

  /* End of MultiPortSwitch: '<S236>/Multiport Switch' */

  /* Switch: '<S237>/Switch' incorporates:
   *  Constant: '<S237>/Constant'
   *  Constant: '<S237>/Constant2'
   *  Switch: '<S237>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLaneLSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLaneRSw) {
    /* Switch: '<S237>/Switch1' incorporates:
     *  Constant: '<S237>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 2U;
  }

  /* End of Switch: '<S237>/Switch' */

  /* Switch: '<S248>/Switch' incorporates:
   *  Constant: '<S248>/Constant2'
   *  Logic: '<S248>/Logical Operator'
   *  Switch: '<S248>/Switch1'
   *  Switch: '<S248>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.PosLampSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.LowBeamSw ||
             AppSwcBcm_ARID_DEF.BusCreator.HiBeamSw) {
    /* Switch: '<S248>/Switch1' incorporates:
     *  Constant: '<S248>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.AutoLampSw) {
    /* Switch: '<S248>/Switch2' incorporates:
     *  Constant: '<S248>/Constant'
     *  Switch: '<S248>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 3U;
  } else {
    /* Switch: '<S248>/Switch1' incorporates:
     *  Constant: '<S248>/Constant3'
     *  Switch: '<S248>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 0U;
  }

  /* End of Switch: '<S248>/Switch' */

  /* Switch: '<S249>/Switch' incorporates:
   *  Constant: '<S249>/Constant2'
   *  Switch: '<S249>/Switch1'
   *  Switch: '<S249>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.LowBeamSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.HiBeamSw) {
    /* Switch: '<S249>/Switch1' incorporates:
     *  Constant: '<S249>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.PassLightSw) {
    /* Switch: '<S249>/Switch2' incorporates:
     *  Constant: '<S249>/Constant'
     *  Switch: '<S249>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 2U;
  } else {
    /* Switch: '<S249>/Switch1' incorporates:
     *  Constant: '<S249>/Constant3'
     *  Switch: '<S249>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 3U;
  }

  /* End of Switch: '<S249>/Switch' */

  /* RelationalOperator: '<S250>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator7'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->HoodAjarSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion19' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Hood =
    rtb_RelationalOperator2_p4;

  /* DataTypeConversion: '<S230>/Data Type Conversion20' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardWarningLightSwSig =
    AppSwcBcm_ARID_DEF.BusCreator.HazardLightSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion21' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntFogLiSwSig =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampFSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion22' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiSwSig =
    AppSwcBcm_ARID_DEF.BusCreator.FogLampRSw;

  /* Switch: '<S250>/Switch' incorporates:
   *  Constant: '<S250>/Constant2'
   *  Constant: '<S250>/Constant4'
   *  Logic: '<S250>/Logical Operator'
   *  RelationalOperator: '<S250>/Relational Operator'
   *  RelationalOperator: '<S250>/Relational Operator1'
   *  RelationalOperator: '<S250>/Relational Operator2'
   *  Switch: '<S250>/Switch1'
   *  Switch: '<S250>/Switch2'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator9.TrunkWarnSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.AntiLckSta == 1) ||
      (AppSwcBcm_ARID_DEF.BusCreator9.PartArmedSta == 1)) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.ArmedSta != 0) {
    /* Switch: '<S250>/Switch1' incorporates:
     *  Constant: '<S250>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator9.SeekSta != 0) {
    /* Switch: '<S250>/Switch2' incorporates:
     *  Constant: '<S250>/Constant'
     *  Switch: '<S250>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 4U;
  } else {
    /* Switch: '<S250>/Switch1' incorporates:
     *  Constant: '<S250>/Constant3'
     *  Switch: '<S250>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 0U;
  }

  /* End of Switch: '<S250>/Switch' */

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator6'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion25' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Trunk =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator2'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion26' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator3'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion27' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator4'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRLSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion28' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator5'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion29' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RR =
    rtb_RelationalOperator2_p4;

  /* MultiPortSwitch: '<S251>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.BusCreator6.WiperSta) {
   case 0:
    /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
     *  Constant: '<S251>/Constant'
     */
    rtb_MultiportSwitch_m = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
     *  Constant: '<S251>/Constant1'
     */
    rtb_MultiportSwitch_m = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
     *  Constant: '<S251>/Constant2'
     */
    rtb_MultiportSwitch_m = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
     *  Constant: '<S251>/Constant3'
     */
    rtb_MultiportSwitch_m = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
     *  Constant: '<S251>/Constant4'
     */
    rtb_MultiportSwitch_m = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S251>/Multiport Switch' incorporates:
     *  UnitDelay: '<S251>/Unit Delay'
     */
    rtb_MultiportSwitch_m = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fd;
    break;
  }

  /* End of MultiPortSwitch: '<S251>/Multiport Switch' */

  /* MultiPortSwitch: '<S252>/Multiport Switch' incorporates:
   *  Constant: '<S252>/Constant'
   *  Constant: '<S252>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (!(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvSeatSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 2U;
  }

  /* End of MultiPortSwitch: '<S252>/Multiport Switch' */

  /* DataTypeConversion: '<S230>/Data Type Conversion41' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntWshrSwSig =
    AppSwcBcm_ARID_DEF.BusCreator6.WashSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion42' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWashSts =
    AppSwcBcm_ARID_DEF.BusCreator6.WashMotorDrv;

  /* Switch: '<S253>/Switch' incorporates:
   *  Constant: '<S253>/Constant2'
   *  Switch: '<S253>/Switch1'
   *  Switch: '<S253>/Switch2'
   *  Switch: '<S253>/Switch3'
   *  Switch: '<S253>/Switch4'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.WiperOffSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperLowSpdSw) {
    /* Switch: '<S253>/Switch1' incorporates:
     *  Constant: '<S253>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperHiSpdSw) {
    /* Switch: '<S253>/Switch2' incorporates:
     *  Constant: '<S253>/Constant'
     *  Switch: '<S253>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperMistSw) {
    /* Switch: '<S253>/Switch3' incorporates:
     *  Constant: '<S253>/Constant3'
     *  Switch: '<S253>/Switch1'
     *  Switch: '<S253>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator6.WiperInrSw) {
    /* Switch: '<S253>/Switch4' incorporates:
     *  Constant: '<S253>/Constant4'
     *  Switch: '<S253>/Switch1'
     *  Switch: '<S253>/Switch2'
     *  Switch: '<S253>/Switch3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 4U;
  } else {
    /* Switch: '<S253>/Switch2' incorporates:
     *  Constant: '<S253>/Constant5'
     *  Switch: '<S253>/Switch1'
     *  Switch: '<S253>/Switch3'
     *  Switch: '<S253>/Switch4'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 6U;
  }

  /* End of Switch: '<S253>/Switch' */

  /* Switch: '<S254>/Switch' incorporates:
   *  Constant: '<S254>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Switch: '<S254>/Switch1'
   *  Switch: '<S254>/Switch2'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinUpSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 1U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinDnSw) {
    /* Switch: '<S254>/Switch1' incorporates:
     *  Constant: '<S254>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 3U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinAutoDnSw) {
    /* Switch: '<S254>/Switch2' incorporates:
     *  Constant: '<S254>/Constant'
     *  Switch: '<S254>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 4U;
  } else {
    /* Switch: '<S254>/Switch1' incorporates:
     *  Constant: '<S254>/Constant3'
     *  Switch: '<S254>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 0U;
  }

  /* End of Switch: '<S254>/Switch' */

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  Logic: '<S255>/Logical Operator'
   */
  rtb_RelationalOperator2_p4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus()
    )->PsgWinUpSw || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
    ->DrvPsgWinUpSw);

  /* Switch: '<S255>/Switch' incorporates:
   *  Constant: '<S255>/Constant2'
   */
  if (rtb_RelationalOperator2_p4) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 1U;
  } else {
    /* Logic: '<S255>/Logical Operator1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator2_p4 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
      ->PsgWinDnSw || (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())
      ->DrvPsgWinDnSw);

    /* Switch: '<S255>/Switch1' */
    if (rtb_RelationalOperator2_p4) {
      /* Switch: '<S255>/Switch1' incorporates:
       *  Constant: '<S255>/Constant1'
       */
      AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 3U;
    } else {
      /* Logic: '<S255>/Logical Operator2' incorporates:
       *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
       */
      rtb_RelationalOperator2_p4 =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinAutoDnSw ||
         (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvPsgWinAutoDnSw);

      /* Switch: '<S255>/Switch2' */
      if (rtb_RelationalOperator2_p4) {
        /* Switch: '<S255>/Switch1' incorporates:
         *  Constant: '<S255>/Constant'
         */
        AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 4U;
      } else {
        /* Switch: '<S255>/Switch1' incorporates:
         *  Constant: '<S255>/Constant3'
         */
        AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 0U;
      }

      /* End of Switch: '<S255>/Switch2' */
    }

    /* End of Switch: '<S255>/Switch1' */
  }

  /* End of Switch: '<S255>/Switch' */

  /* DataTypeConversion: '<S230>/Data Type Conversion49' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->DrvWinSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion50' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus())->PsgWinSta;

  /* Switch: '<S238>/Switch1' incorporates:
   *  Constant: '<S238>/Constant1'
   *  Logic: '<S238>/Logical Operator'
   *  Switch: '<S238>/Switch'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator6.HiSpdDrv &&
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts =
      AppSwcBcm_ARID_DEF.BusCreator6.LowSpdDrv;
  }

  /* End of Switch: '<S238>/Switch1' */

  /* DataTypeConversion: '<S230>/Data Type Conversion52' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntLeDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvPESw;

  /* DataTypeConversion: '<S230>/Data Type Conversion53' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntRiDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->PsgPESw;

  /* DataTypeConversion: '<S230>/Data Type Conversion54' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkSwtSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkSw;

  /* DataTypeConversion: '<S230>/Data Type Conversion98' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnNoKeyFound =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnNoKeyFound;

  /* DataTypeConversion: '<S230>/Data Type Conversion55' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* DataTypeConversion: '<S230>/Data Type Conversion97' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSAuthentRes =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSAuthentRes;

  /* DataTypeConversion: '<S230>/Data Type Conversion95' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyInCarSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyInCarSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion94' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->DrvPEAuthentAcsd;

  /* DataTypeConversion: '<S230>/Data Type Conversion72' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FRPEAuthentAcsd;

  /* DataTypeConversion: '<S230>/Data Type Conversion71' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSReq;

  /* DataTypeConversion: '<S230>/Data Type Conversion57' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* DataTypeConversion: '<S230>/Data Type Conversion58' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChgWiperMtMdSwSetFb =
    AppSwcBcm_ARID_DEF.BusCreator6.WiperMaintSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion59' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ParkAutoUnlockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;

  /* DataTypeConversion: '<S230>/Data Type Conversion60' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_OverspdCntrlLockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->SpdCtlLckSetFb;

  /* DataTypeConversion: '<S230>/Data Type Conversion37' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrbdnKeyNr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FrbdnKeyNr;

  /* DataTypeConversion: '<S230>/Data Type Conversion101' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AvaluebleKeyInCar =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->AvaluebleKeyInCar;

  /* DataTypeConversion: '<S230>/Data Type Conversion104' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyLoBattLvlWarn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyLoBattLvlWarn;

  /* DataTypeConversion: '<S230>/Data Type Conversion70' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeySta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeySta;

  /* Chart: '<S239>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S239>/Constant'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(AppSwcBcm_ARID_DEF.BusCreator.WelcomeLampSta, 25,
    &AppSwcBcm_ARID_DEF.LIB_blOut_ch,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_o);

  /* DataTypeConversion: '<S230>/Data Type Conversion64' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLampReq =
    AppSwcBcm_ARID_DEF.LIB_blOut_ch;

  /* Chart: '<S240>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S240>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeUnlck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_ob,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_e);

  /* Chart: '<S240>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S240>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeLck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1_j);

  /* Switch: '<S240>/Switch' incorporates:
   *  Constant: '<S240>/Constant2'
   *  Constant: '<S240>/Constant4'
   *  Switch: '<S240>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_ob) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.LIB_blOut_d) {
    /* Switch: '<S240>/Switch1' incorporates:
     *  Constant: '<S240>/Constant3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 0U;
  }

  /* End of Switch: '<S240>/Switch' */

  /* DataTypeConversion: '<S230>/Data Type Conversion106' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnKeyOutReminder =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnKeyOutReminder;

  /* DataTypeConversion: '<S230>/Data Type Conversion107' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IndicationKeyCloser =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->IndicationKeyCloser;

  /* DataTypeConversion: '<S230>/Data Type Conversion110' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SteerWhlTemp = (uint8)
    AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.SteerWhlTemp;

  /* DataTypeConversion: '<S230>/Data Type Conversion66' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_MaiDrvrSeatTemp = (uint8)
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.DrvSeatTemp;

  /* DataTypeConversion: '<S230>/Data Type Conversion67' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* DataTypeConversion: '<S230>/Data Type Conversion82' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion11'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakePedalSta =
    AppSwcBcm_ARID_DEF.BusCreator.BrakeLightSta;

  /* BusCreator: '<S230>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S230>/Data Type Conversion143'
   *  DataTypeConversion: '<S230>/Data Type Conversion144'
   *  DataTypeConversion: '<S230>/Data Type Conversion83'
   *  DataTypeConversion: '<S230>/Data Type Conversion84'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;

  /* Switch: '<S243>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S243>/Constant2'
     *  DataTypeConversion: '<S230>/Data Type Conversion142'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 2U;
  } else {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S243>/Constant3'
     *  DataTypeConversion: '<S230>/Data Type Conversion142'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 1U;
  }

  /* End of Switch: '<S243>/Switch' */

  /* BusCreator: '<S230>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S230>/Data Type Conversion135'
   *  DataTypeConversion: '<S230>/Data Type Conversion136'
   *  DataTypeConversion: '<S230>/Data Type Conversion77'
   *  DataTypeConversion: '<S230>/Data Type Conversion78'
   *  DataTypeConversion: '<S230>/Data Type Conversion79'
   *  DataTypeConversion: '<S230>/Data Type Conversion80'
   *  DataTypeConversion: '<S230>/Data Type Conversion85'
   *  DataTypeConversion: '<S230>/Data Type Conversion86'
   * */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockSta_FL =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndLckStsFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndUnlockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndUnlockStsFb;

  /* Switch: '<S245>/Switch' incorporates:
   *  Switch: '<S245>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.FlwrMeHomeSta) {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S245>/Constant'
     *  DataTypeConversion: '<S230>/Data Type Conversion76'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.WelcomeLampSta) {
    /* Switch: '<S245>/Switch1' incorporates:
     *  BusCreator: '<S230>/Bus Creator1'
     *  Constant: '<S245>/Constant1'
     *  DataTypeConversion: '<S230>/Data Type Conversion76'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 2U;
  } else {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S245>/Constant2'
     *  DataTypeConversion: '<S230>/Data Type Conversion76'
     *  Switch: '<S245>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 0U;
  }

  /* End of Switch: '<S245>/Switch' */

  /* Switch: '<S246>/Switch' incorporates:
   *  Switch: '<S246>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRShort) {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S246>/Constant'
     *  DataTypeConversion: '<S230>/Data Type Conversion74'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrROpen) {
    /* Switch: '<S246>/Switch1' incorporates:
     *  BusCreator: '<S230>/Bus Creator1'
     *  Constant: '<S246>/Constant1'
     *  DataTypeConversion: '<S230>/Data Type Conversion74'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 2U;
  } else {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S246>/Constant2'
     *  DataTypeConversion: '<S230>/Data Type Conversion74'
     *  Switch: '<S246>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S246>/Switch' */

  /* Switch: '<S247>/Switch' incorporates:
   *  Switch: '<S247>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLShort) {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S247>/Constant'
     *  DataTypeConversion: '<S230>/Data Type Conversion73'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLOpen) {
    /* Switch: '<S247>/Switch1' incorporates:
     *  BusCreator: '<S230>/Bus Creator1'
     *  Constant: '<S247>/Constant1'
     *  DataTypeConversion: '<S230>/Data Type Conversion73'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 2U;
  } else {
    /* BusCreator: '<S230>/Bus Creator1' incorporates:
     *  Constant: '<S247>/Constant2'
     *  DataTypeConversion: '<S230>/Data Type Conversion73'
     *  Switch: '<S247>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S247>/Switch' */

  /* BusCreator: '<S230>/Bus Creator1' incorporates:
   *  Constant: '<S230>/Constant1'
   *  Constant: '<S230>/Constant10'
   *  Constant: '<S230>/Constant12'
   *  Constant: '<S230>/Constant16'
   *  Constant: '<S230>/Constant17'
   *  Constant: '<S230>/Constant18'
   *  Constant: '<S230>/Constant19'
   *  Constant: '<S230>/Constant2'
   *  Constant: '<S230>/Constant20'
   *  Constant: '<S230>/Constant21'
   *  Constant: '<S230>/Constant23'
   *  Constant: '<S230>/Constant24'
   *  Constant: '<S230>/Constant26'
   *  Constant: '<S230>/Constant29'
   *  Constant: '<S230>/Constant3'
   *  Constant: '<S230>/Constant32'
   *  Constant: '<S230>/Constant33'
   *  Constant: '<S230>/Constant34'
   *  Constant: '<S230>/Constant35'
   *  Constant: '<S230>/Constant36'
   *  Constant: '<S230>/Constant37'
   *  Constant: '<S230>/Constant38'
   *  Constant: '<S230>/Constant39'
   *  Constant: '<S230>/Constant40'
   *  Constant: '<S230>/Constant41'
   *  Constant: '<S230>/Constant42'
   *  Constant: '<S230>/Constant43'
   *  Constant: '<S230>/Constant44'
   *  Constant: '<S230>/Constant45'
   *  Constant: '<S230>/Constant46'
   *  Constant: '<S230>/Constant47'
   *  Constant: '<S230>/Constant5'
   *  Constant: '<S230>/Constant6'
   *  Constant: '<S230>/Constant7'
   *  Constant: '<S230>/Constant8'
   *  DataTypeConversion: '<S230>/Data Type Conversion138'
   */
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
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighFreqSigData_Byte15 = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_VhclSeek =
    AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RFInitSta = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BackLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockOperationRecord = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPassWinSwSig = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorFlags = false;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorFlags = false;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontFogLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LFInitSta = false;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLiFaultFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.DrvLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.IntLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.PassLfAnt_DiagStatus = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemoteCarSearchFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemoteLockFb = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.CCU_RemotePowerLockFb = 0U;

  /* BusCreator: '<S230>/Bus Creator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S230>/Data Type Conversion73'
   *  DataTypeConversion: '<S230>/Data Type Conversion74'
   *  DataTypeConversion: '<S230>/Data Type Conversion75'
   *  DataTypeConversion: '<S230>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* BusCreator: '<S230>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion77'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator8'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* BusCreator: '<S230>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion78'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator9'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRLSw;

  /* BusCreator: '<S230>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion79'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator2_p4;

  /* Logic: '<S230>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S230>/Logical Operator10'
   */
  rtb_RelationalOperator2_p4 =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw;

  /* BusCreator: '<S230>/Bus Creator2' incorporates:
   *  Constant: '<S230>/Constant'
   *  DataTypeConversion: '<S230>/Data Type Conversion142'
   *  DataTypeConversion: '<S230>/Data Type Conversion143'
   *  DataTypeConversion: '<S230>/Data Type Conversion67'
   *  DataTypeConversion: '<S230>/Data Type Conversion80'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAiarSta_RR =
    rtb_RelationalOperator2_p4;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.AppSwcBcmVersion = 17U;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_NMReq_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.NMReq;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SleepAllwd_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.SleepAllwd;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* Switch: '<S241>/Switch' incorporates:
   *  Constant: '<S241>/Constant'
   *  Constant: '<S241>/Constant1'
   *  Constant: '<S241>/Constant2'
   *  Constant: '<S241>/Constant4'
   *  RelationalOperator: '<S241>/Relational Operator'
   *  RelationalOperator: '<S241>/Relational Operator1'
   *  Switch: '<S241>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 1) {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      282574488338432ULL;
  } else if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 2) {
    /* Switch: '<S241>/Switch1' incorporates:
     *  Constant: '<S241>/Constant3'
     *  Switch: '<S241>/Switch'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      564049465049088ULL;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl = 0ULL;
  }

  /* End of Switch: '<S241>/Switch' */

  /* Chart: '<S242>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S242>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HULck, 25, &rtb_RelationalOperator2_p4,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_a);

  /* Chart: '<S242>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S242>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HUUnlck, 25, &rtb_RelationalOperator2_p4,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1);

  /* DataTypeConversion: '<S230>/Data Type Conversion89' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_b =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion90' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion3'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_p =
    AppSwcBcm_ARID_DEF.BusCreator.PosLampSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion91' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion9'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_c =
    AppSwcBcm_ARID_DEF.BusCreator.DayRunLightSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion92' incorporates:
   *  DataTypeConversion: '<S230>/Data Type Conversion1'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_f =
    AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrRSta;

  /* DataTypeConversion: '<S230>/Data Type Conversion93' incorporates:
   *  Logic: '<S230>/Logical Operator1'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_g = (uint8)
    (AppSwcBcm_ARID_DEF.BusCreator.EmerSta ||
     AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrLOpen ||
     AppSwcBcm_ARID_DEF.BusCreator.TurnIndcrROpen);

  /* BusCreator: '<S230>/Bus Creator' */
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

  /* Outputs for Atomic SubSystem: '<S230>/HwOutBCM' */
  AppSwcBcm_HwOutBCM();

  /* End of Outputs for SubSystem: '<S230>/HwOutBCM' */

  /* Update for UnitDelay: '<S236>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ez = rtb_MultiportSwitch;

  /* Update for UnitDelay: '<S251>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fd = rtb_MultiportSwitch_m;
}

/* Output and update for atomic system: '<S3>/EEReadCtl' */
static void AppSwcBcm_EEReadCtl(void)
{
  uint8 i;

  /* Chart: '<S231>/EEReadCtl' */
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
  for (i = 0U; i < 10; i++) {
    EEReadCtl_DoorOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 29];
    EEReadCtl_LocalStartFailOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 39];
    EEReadCtl_RemoteStartFailRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 49];
    EEReadCtl_TrunkOpRecord[i] = AppSwcBcm_ARID_DEF.data1[i + 59];
  }

  /* End of Chart: '<S231>/EEReadCtl' */
}

/*
 * System initialize for function-call system:
 *    '<S284>/Lib_RiseEdgeDetInit'
 *    '<S292>/Lib_RiseEdgeDetInit'
 *    '<S298>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S286>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S284>/Lib_RiseEdgeDetInit'
 *    '<S292>/Lib_RiseEdgeDetInit'
 *    '<S298>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S286>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S286>/Logical Operator' incorporates:
   *  Delay: '<S286>/Delay'
   *  Logic: '<S286>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S286>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S278>/Lib_EdgeChgDet'
 *    '<S447>/Pri5.AntiLckFunc.Lib_EdgeChgDet'
 *    '<S447>/Pri5.SeekFunc.Lib_EdgeChgDet'
 *    '<S447>/Pri5.ArmedFunc.Lib_EdgeChgDet'
 *    '<S447>/Pri5.PartArmedFunc.Lib_EdgeChgDet'
 *    '<S447>/Pri5.DisarmedFunc.Lib_EdgeChgDet'
 *    '<S533>/Lib_EdgeChgDet'
 */
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S296>/Lib_EdgeChgDet' */
  /* RelationalOperator: '<S297>/Relational Operator' incorporates:
   *  UnitDelay: '<S297>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn != AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S297>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* End of Outputs for SubSystem: '<S296>/Lib_EdgeChgDet' */
}

/*
 * System initialize for atomic system:
 *    '<S305>/Lib_RiseEdgeDetInit'
 *    '<S456>/Lib_RiseEdgeDetInit'
 *    '<S460>/Lib_RiseEdgeDetInit'
 *    '<S463>/Lib_RiseEdgeDetInit'
 *    '<S464>/Lib_RiseEdgeDetInit'
 *    '<S474>/Lib_RiseEdgeDetInit'
 *    '<S502>/Lib_RiseEdgeDetInit'
 *    '<S537>/Lib_RiseEdgeDetInit'
 *    '<S538>/Lib_RiseEdgeDetInit'
 *    '<S539>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S306>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S305>/Lib_RiseEdgeDetInit'
 *    '<S456>/Lib_RiseEdgeDetInit'
 *    '<S460>/Lib_RiseEdgeDetInit'
 *    '<S463>/Lib_RiseEdgeDetInit'
 *    '<S464>/Lib_RiseEdgeDetInit'
 *    '<S474>/Lib_RiseEdgeDetInit'
 *    '<S502>/Lib_RiseEdgeDetInit'
 *    '<S537>/Lib_RiseEdgeDetInit'
 *    '<S538>/Lib_RiseEdgeDetInit'
 *    '<S539>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_i_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S306>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S306>/Logical Operator' incorporates:
   *  Delay: '<S306>/Delay'
   *  Logic: '<S306>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S306>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S304>/Lib_RiseEdgeDetInit'
 *    '<S455>/Lib_RiseEdgeDetInit'
 *    '<S459>/Lib_RiseEdgeDetInit'
 *    '<S473>/Lib_RiseEdgeDetInit'
 *    '<S501>/Lib_RiseEdgeDetInit'
 *    '<S536>/Lib_RiseEdgeDetInit'
 *    '<S536>/Lib_RiseEdgeDetInit1'
 *    '<S536>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_h_T *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S305>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S305>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S304>/Lib_RiseEdgeDetInit'
 *    '<S455>/Lib_RiseEdgeDetInit'
 *    '<S459>/Lib_RiseEdgeDetInit'
 *    '<S473>/Lib_RiseEdgeDetInit'
 *    '<S501>/Lib_RiseEdgeDetInit'
 *    '<S536>/Lib_RiseEdgeDetInit'
 *    '<S536>/Lib_RiseEdgeDetInit1'
 *    '<S536>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_h_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S305>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_o(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S305>/Lib_RiseEdgeDetInit' */
}

/* System initialize for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S276>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kp = true;

  /* SystemInitialize for Chart: '<S273>/Alarm' incorporates:
   *  SubSystem: '<S284>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

  /* SystemInitialize for Chart: '<S275>/Armed' incorporates:
   *  SubSystem: '<S292>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_k);

  /* SystemInitialize for Chart: '<S280>/PartArmed' incorporates:
   *  SubSystem: '<S298>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h);

  /* SystemInitialize for Chart: '<S282>/Chart' incorporates:
   *  SubSystem: '<S304>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_m);
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
  boolean guard1 = false;
  boolean rtb_RelationalOperator;
  boolean tmp_0;

  /* Chart: '<S277>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S277>/Constant'
   *  Constant: '<S277>/Constant37'
   *  Constant: '<S277>/Constant38'
   *  Constant: '<S277>/Constant39'
   *  RelationalOperator: '<S277>/Relational Operator'
   */
  if (BSW_J319HornSw == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_e3 >= (float32)HornCtl_HornSwTimValid_C /
         (HornCtl_Ts_C * 100.0F)) && (HornCtl_HornSwTimValid_C != 0xFFFF)) {
      HornCtl_HornSwCtl = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_e3++;
      AppSwcBcm_ARID_DEF.cnt_heal_iy = (uint16)((float32)
        HornCtl_HornSwTimInvalid_C / (HornCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_e3 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_iy == 0) {
      HornCtl_HornSwCtl = false;
    } else if (HornCtl_HornSwTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_iy--;
    }
  }

  /* End of Chart: '<S277>/LIB_TPD_10ms' */

  /* Chart: '<S273>/Alarm' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AlarmSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AlarmSta = 1U;
    AppSwcBcm_ARID_DEF.Lib_blIn_ev =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 2);

    /* Outputs for Function Call SubSystem: '<S284>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_ev,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jif,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

    /* End of Outputs for SubSystem: '<S284>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jif || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AlarmSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AlarmSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_ev =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S284>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_ev,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jif,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_p);

    /* End of Outputs for SubSystem: '<S284>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jif) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_AlarmSta = 1U;
    }
  }

  /* End of Chart: '<S273>/Alarm' */

  /* RelationalOperator: '<S276>/Relational Operator' incorporates:
   *  Constant: '<S276>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S276>/Relational Operator1'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S276>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_kp) {
    /* Switch: '<S276>/Switch' incorporates:
     *  Constant: '<S276>/Constant'
     *  Constant: '<S276>/Constant5'
     *  RelationalOperator: '<S276>/Relational Operator'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_on = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_on =
        AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts;
    }

    /* End of Switch: '<S276>/Switch' */
  }

  /* Switch: '<S276>/Switch1' incorporates:
   *  Constant: '<S276>/Constant7'
   */
  if (rtb_RelationalOperator) {
    rtb_HornCtl_Sta = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HULckHornOnSt_enum;
  } else {
    rtb_HornCtl_Sta = 0U;
  }

  /* MultiPortSwitch: '<S276>/Multiport Switch' incorporates:
   *  Switch: '<S276>/Switch1'
   */
  switch (rtb_HornCtl_Sta) {
   case 1:
    /* MultiPortSwitch: '<S276>/Multiport Switch' incorporates:
     *  Constant: '<S276>/Constant1'
     */
    HornCtl_LockHoornOnSt = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S276>/Multiport Switch' incorporates:
     *  Constant: '<S276>/Constant2'
     */
    HornCtl_LockHoornOnSt = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S276>/Multiport Switch' incorporates:
     *  Delay: '<S276>/Delay'
     */
    HornCtl_LockHoornOnSt = AppSwcBcm_ARID_DEF.Delay_DSTATE_on;
    break;
  }

  /* End of MultiPortSwitch: '<S276>/Multiport Switch' */

  /* MultiPortSwitch: '<S276>/Multiport Switch1' */
  switch (HornCtl_LockHoornOnSt) {
   case 1:
    /* MultiPortSwitch: '<S276>/Multiport Switch1' incorporates:
     *  Constant: '<S276>/Constant3'
     */
    HornCtl_LockHoornOnStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S276>/Multiport Switch1' incorporates:
     *  Constant: '<S276>/Constant4'
     */
    HornCtl_LockHoornOnStFb = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S276>/Multiport Switch1' */

  /* Chart: '<S274>/AntiLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S232>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AntiLckSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AntiLckSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k >= 3) || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AntiLckSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AntiLckSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_aj =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck;

    /* Outputs for Function Call SubSystem: '<S287>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_aj,
      &AppSwcBcm_ARID_DEF.LogicalOperator_iz,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_px);

    /* End of Outputs for SubSystem: '<S287>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_iz) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_bk =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck;

      /* Outputs for Function Call SubSystem: '<S287>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_bk,
        &AppSwcBcm_ARID_DEF.LogicalOperator_c5,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_pc);

      /* End of Outputs for SubSystem: '<S287>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_c5) {
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

  /* End of Chart: '<S274>/AntiLck' */

  /* Chart: '<S275>/Armed' incorporates:
   *  UnitDelay: '<S232>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_ArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_ArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k >= 1) ||
        (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) || HornCtl_HornSwCtl)
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_ArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_ArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_dr =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S292>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_dr,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fy,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_k);

    /* End of Outputs for SubSystem: '<S292>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fy && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_ArmedSta = 1U;
    }
  }

  /* End of Chart: '<S275>/Armed' */

  /* Chart: '<S280>/PartArmed' incorporates:
   *  UnitDelay: '<S232>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_PartArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_PartArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k >= 3) ||
        (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) || HornCtl_HornSwCtl)
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_PartArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_PartArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_eh =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3);

    /* Outputs for Function Call SubSystem: '<S298>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_eh,
      &AppSwcBcm_ARID_DEF.LogicalOperator_b2,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_h);

    /* End of Outputs for SubSystem: '<S298>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_b2 && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_PartArmedSta = 1U;
    }
  }

  /* End of Chart: '<S280>/PartArmed' */

  /* Chart: '<S281>/Seek' incorporates:
   *  UnitDelay: '<S232>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_SeekSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_SeekSta = 1U;
    if ((!AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta) ||
        (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k >= 1) || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_SeekSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_SeekSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_is = AppSwcBcm_ARID_DEF.BusCreator.VehSeekSta;

    /* Outputs for Function Call SubSystem: '<S301>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_is,
      &AppSwcBcm_ARID_DEF.LogicalOperator_dg,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mc);

    /* End of Outputs for SubSystem: '<S301>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_dg && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_SeekSta = 1U;
    }
  }

  /* End of Chart: '<S281>/Seek' */

  /* Chart: '<S282>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S232>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c55_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c55_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_TrunkWarnSta = 0U;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt_j = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib) {
     case AppSwcBcm_IN_Delay:
      if (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_TrunkWarnSta = 0U;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt_j = 0U;
      } else if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3) &&
                 (AppSwcBcm_ARID_DEF.TrunkWarnCnt_j >= HornCtl_TrunkWarnTim_C))
      {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOn;
        HornCtl_TrunkWarnSta = 1U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt_j + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt_j + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt_j = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff:
      HornCtl_TrunkWarnSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_mk =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S304>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_mk,
        &AppSwcBcm_ARID_DEF.LogicalOperator_n,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_m);

      /* End of Outputs for SubSystem: '<S304>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_n && (HornCtl_LockHoornOnStFb == 1)
          && (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3)) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_Delay;
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt_j + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt_j + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt_j = (uint16)tmp;
      }
      break;

     default:
      /* case IN_SetOn: */
      HornCtl_TrunkWarnSta = 1U;
      if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k >= 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3)) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_TrunkWarnSta = 0U;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt_j = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S282>/Chart' */

  /* Truth Table: '<S232>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  rtb_RelationalOperator = (HornCtl_PartArmedSta == 1);

  /*  Condition #3 */
  /*  Condition #4 */
  aVarTruthTableCondition_4 = (HornCtl_AlarmSta == 1);

  /*  Condition #5 */
  /*  Condition #6 */
  /*  Condition #7 */
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
    } else if (tmp_0 && (HornCtl_SeekSta == 1)) {
      rtb_HornCtl_DemCnt = 1U;
      rtb_HornCtl_Prd = 10U;
      rtb_HornCtl_Wtd = 1U;
      rtb_HornCtl_Sta = 6U;
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

  /* End of Truth Table: '<S232>/Truth Table' */

  /* RelationalOperator: '<S232>/Relational Operator' incorporates:
   *  UnitDelay: '<S232>/Unit Delay4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_pm = (rtb_HornCtl_Sta !=
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_b);

  /* Chart: '<S232>/LIB_Pulse' incorporates:
   *  SubSystem: '<S278>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_pm,
    &AppSwcBcm_ARID_DEF.RelationalOperator_p3,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet_c);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_p3) {
    AppSwcBcm_ARID_DEF.cnt_g = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k = 0U;
  }

  if (rtb_HornCtl_DemCnt >= 1) {
    if (rtb_HornCtl_DemCnt >= 65535) {
      AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_k = (AppSwcBcm_ARID_DEF.cnt_g <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_g >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_g = 0U;
      } else {
        AppSwcBcm_ARID_DEF.cnt_g++;
      }
    } else if (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k < rtb_HornCtl_DemCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_k = (AppSwcBcm_ARID_DEF.cnt_g <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_g >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_g = 0U;
        AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k++;
      } else {
        AppSwcBcm_ARID_DEF.cnt_g++;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_k = false;
    AppSwcBcm_ARID_DEF.cnt_g = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_k = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S232>/Ovrd1' */
  /* Switch: '<S279>/Switch1' incorporates:
   *  Constant: '<S232>/Constant18'
   */
  if (HornCtl_J430HornDrvOvrdFlg_C) {
    /* Switch: '<S279>/Switch1' incorporates:
     *  Constant: '<S232>/Constant19'
     */
    HornCtl_J430HornDrv = HornCtl_J430HornDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S232>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus())
      ->HornCtlFlg != 0);

    /* Switch: '<S279>/Switch2' */
    if (rtb_RelationalOperator) {
      /* Switch: '<S279>/Switch1' incorporates:
       *  Switch: '<S279>/Switch2'
       */
      HornCtl_J430HornDrv = true;
    } else {
      /* Switch: '<S279>/Switch1' incorporates:
       *  Constant: '<S232>/Constant'
       *  RelationalOperator: '<S232>/Relational Operator1'
       *  Switch: '<S232>/Switch'
       *  Switch: '<S279>/Switch2'
       */
      HornCtl_J430HornDrv =
        ((AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum != 1) &&
         AppSwcBcm_ARID_DEF.LIB_blOut_k);
    }

    /* End of Switch: '<S279>/Switch2' */
  }

  /* End of Switch: '<S279>/Switch1' */
  /* End of Outputs for SubSystem: '<S232>/Ovrd1' */

  /* Update for Delay: '<S276>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_kp = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_on = HornCtl_LockHoornOnSt;

  /* Update for UnitDelay: '<S232>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_b = rtb_HornCtl_Sta;
}

/*
 * Output and update for function-call system:
 *    '<S342>/Lib_RiseEdgeDet'
 *    '<S343>/Lib_RiseEdgeDet'
 *    '<S357>/Lib_RiseEdgeDet'
 *    '<S605>/Wash.Lib_RiseEdgeDet'
 *    '<S656>/Lib_RiseEdgeDet'
 *    '<S716>/Lib_RiseEdgeDet'
 *    '<S724>/Lib_RiseEdgeDet'
 *    '<S728>/Lib_RiseEdgeDet'
 *    '<S740>/Lib_RiseEdgeDet'
 *    '<S850>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_i_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S347>/Logical Operator' incorporates:
   *  Logic: '<S347>/Logical Operator1'
   *  UnitDelay: '<S347>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S347>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S341>/LIB_Pulse'
 *    '<S341>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse_Init(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt)
{
  *rty_LIB_blOut = false;
  *rty_LIB_u16PrdSucCnt = 0U;
}

/*
 * System reset for atomic system:
 *    '<S341>/LIB_Pulse'
 *    '<S341>/LIB_Pulse1'
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
 *    '<S341>/LIB_Pulse'
 *    '<S341>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse(uint16 rtu_LIB_u16PrdDemCnt, uint16
  rtu_LIB_u16Prd, uint16 rtu_LIB_u16Wdt, boolean rtu_LIB_blReset, boolean
  *rty_LIB_blOut, uint16 *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S341>/LIB_Pulse' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blReset;

  /* Outputs for Function Call SubSystem: '<S342>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S342>/Lib_RiseEdgeDet' */

  /* Chart: '<S341>/LIB_Pulse' */
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
 *    '<S341>/Truth Table'
 *    '<S341>/Truth Table1'
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

/* System initialize for atomic system: '<S233>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S307>/Enabled Subsystem' */

  /* SystemInitialize for Chart: '<S341>/LIB_Pulse' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_g,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_n);

  /* SystemInitialize for Chart: '<S341>/LIB_Pulse1' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_p,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt);

  /* End of SystemInitialize for SubSystem: '<S307>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<S233>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl(void)
{
  uint16 rtb_BSD_LightPrd;
  uint16 rtb_BSD_LightWdt;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator8_j1;
  boolean rtb_RelationalOperator9_ax;

  /* RelationalOperator: '<S307>/Relational Operator' incorporates:
   *  Constant: '<S307>/Constant13'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S307>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S341>/Enable'
   */
  if (rtb_RelationalOperator) {
    if (!AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
      /* SystemReset for Chart: '<S341>/LIB_Pulse' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_g,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_n,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

      /* SystemReset for Chart: '<S341>/LIB_Pulse1' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_p,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);
      AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = true;
    }

    /* RelationalOperator: '<S341>/Relational Operator10' incorporates:
     *  Constant: '<S341>/Constant12'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator1'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 1);

    /* RelationalOperator: '<S341>/Relational Operator8' incorporates:
     *  Constant: '<S341>/Constant3'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator3'
     */
    rtb_RelationalOperator8_j1 =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 1);

    /* RelationalOperator: '<S341>/Relational Operator9' incorporates:
     *  Constant: '<S341>/Constant4'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator4'
     */
    rtb_RelationalOperator9_ax =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 1);

    /* Logic: '<S341>/Logical Operator' */
    rtb_LogicalOperator = (rtb_RelationalOperator || rtb_RelationalOperator8_j1 ||
      rtb_RelationalOperator9_ax);

    /* RelationalOperator: '<S341>/Relational Operator9' incorporates:
     *  Constant: '<S341>/Constant1'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator12'
     */
    rtb_RelationalOperator9_ax =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 2);

    /* RelationalOperator: '<S341>/Relational Operator8' incorporates:
     *  Constant: '<S341>/Constant11'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator11'
     */
    rtb_RelationalOperator8_j1 =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 2);

    /* RelationalOperator: '<S341>/Relational Operator10' incorporates:
     *  Constant: '<S341>/Constant10'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator7'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 2);

    /* Truth Table: '<S341>/Truth Table' incorporates:
     *  Logic: '<S341>/Logical Operator2'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_ax ||
                         rtb_RelationalOperator8_j1 || rtb_RelationalOperator,
                         &rtb_BSD_LightWdt, &rtb_BSD_LightPrd);

    /* Chart: '<S341>/LIB_Pulse' incorporates:
     *  Constant: '<S341>/Constant'
     *  Constant: '<S341>/Constant13'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightWdt, rtb_BSD_LightPrd, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_g,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_n,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

    /* SignalConversion generated from: '<S341>/LampCtl_J420BSDRightCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_g;

    /* RelationalOperator: '<S341>/Relational Operator9' incorporates:
     *  Constant: '<S341>/Constant5'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator5'
     */
    rtb_RelationalOperator9_ax =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 1);

    /* RelationalOperator: '<S341>/Relational Operator8' incorporates:
     *  Constant: '<S341>/Constant2'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator2'
     */
    rtb_RelationalOperator8_j1 =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 1);

    /* RelationalOperator: '<S341>/Relational Operator10' incorporates:
     *  Constant: '<S341>/Constant6'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S341>/Relational Operator6'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 1);

    /* Logic: '<S341>/Logical Operator3' */
    rtb_LogicalOperator = (rtb_RelationalOperator9_ax ||
      rtb_RelationalOperator8_j1 || rtb_RelationalOperator);

    /* RelationalOperator: '<S341>/Relational Operator9' incorporates:
     *  Constant: '<S341>/Constant8'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator9_ax =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 2);

    /* RelationalOperator: '<S341>/Relational Operator8' incorporates:
     *  Constant: '<S341>/Constant7'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator8_j1 =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 2);

    /* RelationalOperator: '<S341>/Relational Operator10' incorporates:
     *  Constant: '<S341>/Constant9'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 2);

    /* Truth Table: '<S341>/Truth Table1' incorporates:
     *  Logic: '<S341>/Logical Operator1'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_ax ||
                         rtb_RelationalOperator8_j1 || rtb_RelationalOperator,
                         &rtb_BSD_LightPrd, &rtb_BSD_LightWdt);

    /* Chart: '<S341>/LIB_Pulse1' incorporates:
     *  Constant: '<S341>/Constant14'
     *  Constant: '<S341>/Constant15'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightPrd, rtb_BSD_LightWdt, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_p,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);

    /* SignalConversion generated from: '<S341>/LampCtl_J422BSDLeftCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_p;
  } else if (AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
    /* Disable for SignalConversion generated from: '<S341>/LampCtl_J420BSDRightCtl' incorporates:
     *  Outport: '<S341>/LampCtl_J420BSDRightCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl = false;

    /* Disable for SignalConversion generated from: '<S341>/LampCtl_J422BSDLeftCtl' incorporates:
     *  Outport: '<S341>/LampCtl_J422BSDLeftCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl = false;
    AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S307>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S308>/LIB_TPD_10ms'
 *    '<S820>/LIB_TPD_10ms11'
 */
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S308>/LIB_TPD_10ms'
 *    '<S820>/LIB_TPD_10ms11'
 */
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  float32 tmp;

  /* Chart: '<S308>/LIB_TPD_10ms' */
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

  /* End of Chart: '<S308>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S233>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S308>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_j);

  /* SystemInitialize for Chart: '<S308>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_is);
}

/* Output and update for atomic system: '<S233>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl(void)
{
  boolean rtb_RelationalOperator1_lz;

  /* Chart: '<S308>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S308>/Constant4'
   *  Constant: '<S308>/Constant43'
   *  Constant: '<S308>/Constant45'
   *  RelationalOperator: '<S308>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms(LampCtl_LightIntstSta == 2,
    LampCtl_AutoLampNightDelayTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_h);

  /* Chart: '<S308>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S308>/Constant5'
   *  Constant: '<S308>/Constant6'
   *  Constant: '<S308>/Constant7'
   *  Constant: '<S308>/Constant8'
   *  Logic: '<S308>/Logical Operator3'
   *  RelationalOperator: '<S308>/Relational Operator5'
   *  UnitDelay: '<S308>/Unit Delay'
   */
  AppSwcBcm_LIB_TPD_10ms1((LampCtl_LightIntstSta == 1) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ms, LampCtl_AutoLampDayDelayTim_C, 10,
    LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_is,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_l);

  /* RelationalOperator: '<S308>/Relational Operator1' incorporates:
   *  Constant: '<S308>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_lz = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Switch: '<S352>/Switch' incorporates:
   *  Logic: '<S308>/Logical Operator'
   *  RelationalOperator: '<S308>/Relational Operator2'
   */
  if (rtb_RelationalOperator1_lz || (!LampCtl_AutoLampSw) ||
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_is) {
    /* Switch: '<S352>/Switch' incorporates:
     *  Constant: '<S352>/Constant'
     */
    LampCtl_AutoLampSta = false;
  } else {
    /* RelationalOperator: '<S308>/Relational Operator' incorporates:
     *  Constant: '<S308>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator1_lz = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);

    /* Switch: '<S352>/Switch' incorporates:
     *  Logic: '<S308>/Logical Operator1'
     *  Logic: '<S308>/Logical Operator2'
     *  Logic: '<S352>/Logical Operator'
     *  UnitDelay: '<S352>/Unit Delay'
     */
    LampCtl_AutoLampSta = ((rtb_RelationalOperator1_lz &&
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_j) || LampCtl_AutoLampSta);
  }

  /* End of Switch: '<S352>/Switch' */

  /* Update for UnitDelay: '<S308>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ms = LampCtl_AutoLampSta;
}

/* System initialize for atomic system: '<S233>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S309>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = true;

  /* InitializeConditions for UnitDelay: '<S309>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm = 20U;
}

/* Output and update for atomic system: '<S233>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl(void)
{
  uint8 tmp;
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S309>/Relational Operator' incorporates:
   *  Constant: '<S309>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S309>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_c) {
    /* Switch: '<S309>/Switch2' incorporates:
     *  Constant: '<S309>/Constant13'
     *  Constant: '<S309>/Constant14'
     *  RelationalOperator: '<S309>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_o = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_o =
        AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb;
    }

    /* End of Switch: '<S309>/Switch2' */
  }

  /* Switch: '<S309>/Switch1' incorporates:
   *  Constant: '<S309>/Constant12'
   */
  if (rtb_RelationalOperator) {
    tmp = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_CDCBackLadjval_enum;
  } else {
    tmp = 0U;
  }

  /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
   *  Switch: '<S309>/Switch1'
   */
  switch (tmp) {
   case 1:
    /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
     *  Constant: '<S309>/Constant1'
     */
    LampCtl_BackLadjvalFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
     *  Constant: '<S309>/Constant2'
     */
    LampCtl_BackLadjvalFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
     *  Constant: '<S309>/Constant3'
     */
    LampCtl_BackLadjvalFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
     *  Constant: '<S309>/Constant4'
     */
    LampCtl_BackLadjvalFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
     *  Constant: '<S309>/Constant5'
     */
    LampCtl_BackLadjvalFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S309>/Multiport Switch' incorporates:
     *  Delay: '<S309>/Delay'
     */
    LampCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_o;
    break;
  }

  /* End of MultiPortSwitch: '<S309>/Multiport Switch' */

  /* MultiPortSwitch: '<S309>/Multiport Switch1' */
  switch (LampCtl_BackLadjvalFb) {
   case 0:
    /* MultiPortSwitch: '<S309>/Multiport Switch1' incorporates:
     *  Constant: '<S309>/Constant6'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm = 20U;
    break;

   case 1:
    /* MultiPortSwitch: '<S309>/Multiport Switch1' incorporates:
     *  Constant: '<S309>/Constant7'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm = 40U;
    break;

   case 2:
    /* MultiPortSwitch: '<S309>/Multiport Switch1' incorporates:
     *  Constant: '<S309>/Constant8'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S309>/Multiport Switch1' incorporates:
     *  Constant: '<S309>/Constant9'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm = 80U;
    break;

   case 4:
    /* MultiPortSwitch: '<S309>/Multiport Switch1' incorporates:
     *  Constant: '<S309>/Constant10'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm = 100U;
    break;
  }

  /* End of MultiPortSwitch: '<S309>/Multiport Switch1' */

  /* Switch: '<S309>/Switch' incorporates:
   *  Logic: '<S309>/Logical Operator'
   *  Logic: '<S309>/Logical Operator1'
   */
  if (rtb_RelationalOperator && (LampCtl_PosLampSta || LampCtl_LowBeamSta)) {
    /* Switch: '<S309>/Switch' */
    AppSwcBcm_ARID_DEF.Switch_j = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gm;
  } else {
    /* Switch: '<S309>/Switch' incorporates:
     *  Constant: '<S309>/Constant11'
     */
    AppSwcBcm_ARID_DEF.Switch_j = 0U;
  }

  /* End of Switch: '<S309>/Switch' */

  /* Update for Delay: '<S309>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_o = LampCtl_BackLadjvalFb;
}

/*
 * Outputs for atomic system:
 *    '<S310>/Lib_FailEdgeDet'
 *    '<S310>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S353>/Logical Operator' incorporates:
   *  Logic: '<S353>/Logical Operator1'
   *  UnitDelay: '<S353>/Unit Delay'
   */
  return (!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;
}

/*
 * Update for atomic system:
 *    '<S310>/Lib_FailEdgeDet'
 *    '<S310>/Lib_FailEdgeDet1'
 */
static void AppSwcBcm_Lib_FailEdgeDet_Update(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Update for UnitDelay: '<S353>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S356>/LIB_PosPluse2'
 *    '<S710>/LIB_PosPluse2'
 *    '<S871>/LIB_NegPluse2'
 *    '<S872>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S356>/LIB_PosPluse2'
 *    '<S710>/LIB_PosPluse2'
 *    '<S871>/LIB_NegPluse2'
 *    '<S872>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S356>/LIB_PosPluse2' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blRst;

  /* Outputs for Function Call SubSystem: '<S357>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S357>/Lib_RiseEdgeDet' */

  /* Chart: '<S356>/LIB_PosPluse2' */
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

/* System initialize for atomic system: '<S233>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_na;

  /* SystemInitialize for Atomic SubSystem: '<S310>/Trunk10min' */

  /* SystemInitialize for Chart: '<S356>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_na);

  /* End of SystemInitialize for SubSystem: '<S310>/Trunk10min' */
}

/* Outputs for atomic system: '<S233>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_na;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_bh;
  boolean rtb_LogicalOperator2_ph;
  boolean rtb_LogicalOperator_da;
  boolean rtb_LogicalOperator_hr;
  boolean rtb_Switch;

  /* Logic: '<S354>/Logical Operator' incorporates:
   *  Constant: '<S310>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S310>/Relational Operator1'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S310>/Logical Operator2' incorporates:
   *  Constant: '<S310>/Constant'
   *  RelationalOperator: '<S310>/Relational Operator'
   */
  rtb_LogicalOperator2_ph = (rtb_LogicalOperator && (LampCtl_LightIntstSta == 2));

  /* Outputs for Atomic SubSystem: '<S310>/Lib_FailEdgeDet' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  rtb_LogicalOperator_hr = AppSwcBcm_Lib_FailEdgeDet
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

  /* End of Outputs for SubSystem: '<S310>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S310>/Lib_FailEdgeDet1' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o);

  /* End of Outputs for SubSystem: '<S310>/Lib_FailEdgeDet1' */

  /* Logic: '<S310>/Logical Operator' */
  rtb_LogicalOperator_da = (rtb_LogicalOperator_hr || rtb_LogicalOperator);

  /* Outputs for Atomic SubSystem: '<S310>/Trunk10min' */

  /* Chart: '<S356>/LIB_PosPluse2' incorporates:
   *  Constant: '<S310>/Constant4'
   *  UnitDelay: '<S310>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jo,
    LampCtl_BoxLampOpenTimMax_C, rtb_LogicalOperator_da, &rtb_LIB_blOut_na,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2_p);

  /* End of Outputs for SubSystem: '<S310>/Trunk10min' */

  /* Logic: '<S310>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator1_bh = (rtb_LIB_blOut_na ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->InsLck ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLck);

  /* Outputs for Atomic SubSystem: '<S310>/Lib_SR' */
  AppSwcBcm_Lib_SR(rtb_LogicalOperator_da, rtb_LogicalOperator1_bh, &rtb_Switch,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_e);

  /* End of Outputs for SubSystem: '<S310>/Lib_SR' */

  /* Switch: '<S310>/Switch' incorporates:
   *  UnitDelay: '<S310>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jo = (rtb_LogicalOperator2_ph ||
    rtb_Switch);
}

/* Update for atomic system: '<S233>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S310>/Lib_FailEdgeDet' */

  /* Update for DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_Lib_FailEdgeDet_Update
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

  /* End of Update for SubSystem: '<S310>/Lib_FailEdgeDet' */

  /* Update for Atomic SubSystem: '<S310>/Lib_FailEdgeDet1' */
  AppSwcBcm_Lib_FailEdgeDet_Update
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o);

  /* End of Update for SubSystem: '<S310>/Lib_FailEdgeDet1' */
}

/* Output and update for atomic system: '<S233>/DayRunLampCtl' */
static void AppSwcBcm_DayRunLampCtl(void)
{
  boolean rtb_RelationalOperator6_j;

  /* RelationalOperator: '<S312>/Relational Operator6' incorporates:
   *  Constant: '<S312>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator6_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Outputs for Atomic SubSystem: '<S312>/Lib_SR' */
  /* Switch: '<S360>/Switch' incorporates:
   *  Constant: '<S312>/Constant1'
   *  Constant: '<S312>/Constant2'
   *  Constant: '<S312>/Constant8'
   *  Constant: '<S360>/Constant'
   *  Logic: '<S312>/Logical Operator'
   *  Logic: '<S312>/Logical Operator1'
   *  Logic: '<S360>/Logical Operator'
   *  RelationalOperator: '<S312>/Relational Operator1'
   *  RelationalOperator: '<S312>/Relational Operator2'
   *  RelationalOperator: '<S312>/Relational Operator7'
   *  RelationalOperator: '<S312>/Relational Operator8'
   *  UnitDelay: '<S360>/Unit Delay'
   */
  if (rtb_RelationalOperator6_j || LampCtl_PosLampSta ||
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VHVM_PTActOprtMode_enum != 2)) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy = false;
  } else {
    /* RelationalOperator: '<S312>/Relational Operator' incorporates:
     *  Constant: '<S312>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy = ((rtb_RelationalOperator6_j &&
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VHVM_PTActOprtMode_enum == 2) &&
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VGSM_VehActGearPstn_enum != 0)) ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy);
  }

  /* End of Switch: '<S360>/Switch' */
  /* End of Outputs for SubSystem: '<S312>/Lib_SR' */
}

/* System initialize for atomic system: '<S233>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S378>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = true;

  /* InitializeConditions for Delay: '<S379>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ms = true;

  /* InitializeConditions for Delay: '<S380>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = true;

  /* SystemInitialize for Atomic SubSystem: '<S363>/Lib_RateLimit' */
  /* InitializeConditions for Delay: '<S377>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_p = true;

  /* End of SystemInitialize for SubSystem: '<S363>/Lib_RateLimit' */

  /* SystemInitialize for Truth Table: '<S313>/Truth Table' */
  LampCtl_DomeLampOff = true;
}

/* Outputs for atomic system: '<S233>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl(void)
{
  sint32 Switch;
  float32 rtb_Add;
  boolean RelationalOperator3;
  boolean rtb_RelationalOperator5_b;
  boolean rtb_RelationalOperator7_b;

  /* RelationalOperator: '<S362>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S361>/Relational Operator1'
   */
  rtb_RelationalOperator5_b = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFLSw;

  /* Outputs for Atomic SubSystem: '<S361>/FL10min' */
  /* Chart: '<S367>/LIB_Tim' incorporates:
   *  Constant: '<S367>/Constant'
   *  Logic: '<S361>/Logical Operator1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && rtb_RelationalOperator5_b) {
    if (AppSwcBcm_ARID_DEF.Cnt_dy <= 30000) {
      AppSwcBcm_ARID_DEF.Cnt_dy++;
      LampCtl_DomeLampFLOpen = true;
    } else {
      LampCtl_DomeLampFLOpen = false;
    }
  } else {
    LampCtl_DomeLampFLOpen = false;
    AppSwcBcm_ARID_DEF.Cnt_dy = 0U;
  }

  /* End of Chart: '<S367>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S361>/FL10min' */

  /* RelationalOperator: '<S362>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S361>/Relational Operator2'
   */
  rtb_RelationalOperator5_b = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFRSw;

  /* Outputs for Atomic SubSystem: '<S361>/FR10min' */
  /* Chart: '<S368>/LIB_Tim' incorporates:
   *  Constant: '<S368>/Constant'
   *  Logic: '<S361>/Logical Operator2'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && rtb_RelationalOperator5_b) {
    if (AppSwcBcm_ARID_DEF.Cnt_h <= 30000) {
      AppSwcBcm_ARID_DEF.Cnt_h++;
      LampCtl_DomeLampFROpen = true;
    } else {
      LampCtl_DomeLampFROpen = false;
    }
  } else {
    LampCtl_DomeLampFROpen = false;
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  }

  /* End of Chart: '<S368>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S361>/FR10min' */

  /* RelationalOperator: '<S362>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator5_b = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFLSw;

  /* RelationalOperator: '<S364>/Relational Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S362>/Relational Operator6'
   */
  rtb_RelationalOperator7_b = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw;

  /* RelationalOperator: '<S362>/Relational Operator3' incorporates:
   *  Constant: '<S362>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  RelationalOperator3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Atomic SubSystem: '<S362>/Lib_FailEdgeDetHold' */
  /* Switch: '<S373>/Switch' incorporates:
   *  Constant: '<S373>/Constant'
   *  Logic: '<S373>/Logical Operator2'
   *  UnitDelay: '<S373>/Unit Delay'
   *  UnitDelay: '<S373>/Unit Delay1'
   */
  if (RelationalOperator3) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ht = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ht =
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b3 ||
       AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ht);
  }

  /* End of Switch: '<S373>/Switch' */

  /* Update for UnitDelay: '<S373>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b3 = RelationalOperator3;

  /* End of Outputs for SubSystem: '<S362>/Lib_FailEdgeDetHold' */

  /* Outputs for Atomic SubSystem: '<S362>/30s' */
  /* Chart: '<S371>/LIB_Tim' incorporates:
   *  Constant: '<S371>/Constant'
   *  Logic: '<S362>/Logical Operator4'
   *  Logic: '<S362>/Logical Operator5'
   *  UnitDelay: '<S373>/Unit Delay1'
   */
  if (rtb_RelationalOperator5_b && rtb_RelationalOperator7_b &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ht &&
      AppSwcBcm_ConstB.RelationalOperator1_p) {
    if (AppSwcBcm_ARID_DEF.Cnt_d <= 1500) {
      AppSwcBcm_ARID_DEF.Cnt_d++;
      LampCtl_DomeLampPwrOff = true;
    } else {
      LampCtl_DomeLampPwrOff = false;
    }
  } else {
    LampCtl_DomeLampPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
  }

  /* End of Chart: '<S371>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S362>/30s' */

  /* Outputs for Atomic SubSystem: '<S362>/Lib_FailEdgeDetHold1' */
  /* Switch: '<S374>/Switch' incorporates:
   *  Constant: '<S374>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S374>/Logical Operator'
   *  Logic: '<S374>/Logical Operator2'
   *  UnitDelay: '<S374>/Unit Delay'
   *  UnitDelay: '<S374>/Unit Delay1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b = false;
  } else {
    /* Logic: '<S374>/Logical Operator1' */
    rtb_RelationalOperator7_b =
      !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b = ((rtb_RelationalOperator7_b &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gd) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b);
  }

  /* End of Switch: '<S374>/Switch' */
  /* End of Outputs for SubSystem: '<S362>/Lib_FailEdgeDetHold1' */

  /* RelationalOperator: '<S364>/Relational Operator7' incorporates:
   *  Constant: '<S362>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S362>/Relational Operator4'
   */
  rtb_RelationalOperator7_b = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Outputs for Atomic SubSystem: '<S362>/30s1' */
  /* Chart: '<S372>/LIB_Tim' incorporates:
   *  Constant: '<S372>/Constant'
   *  Logic: '<S362>/Logical Operator1'
   *  UnitDelay: '<S374>/Unit Delay1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator1_p &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b && rtb_RelationalOperator7_b) {
    if (AppSwcBcm_ARID_DEF.Cnt_pi <= 1500) {
      AppSwcBcm_ARID_DEF.Cnt_pi++;
      LampCtl_DomeLampUnlock = true;
    } else {
      LampCtl_DomeLampUnlock = false;
    }
  } else {
    LampCtl_DomeLampUnlock = false;
    AppSwcBcm_ARID_DEF.Cnt_pi = 0U;
  }

  /* End of Chart: '<S372>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S362>/30s1' */

  /* RelationalOperator: '<S364>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* Delay: '<S378>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_m) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_kl =
      AppSwcBcm_ARID_DEF.RelationalOperator4_g;
  }

  /* Logic: '<S378>/Logical Operator' incorporates:
   *  Delay: '<S378>/Delay'
   *  Logic: '<S378>/Logical Operator1'
   */
  LampCtl_DomeLampLockDoor = (AppSwcBcm_ARID_DEF.RelationalOperator4_g &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_kl));

  /* RelationalOperator: '<S364>/Relational Operator7' incorporates:
   *  Constant: '<S364>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator7_b = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* RelationalOperator: '<S364>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Delay: '<S379>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_ms) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_nk =
      AppSwcBcm_ARID_DEF.RelationalOperator8_g;
  }

  /* RelationalOperator: '<S364>/Relational Operator9' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9_k =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* Delay: '<S380>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_k) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_pv =
      AppSwcBcm_ARID_DEF.RelationalOperator9_k;
  }

  /* Logic: '<S364>/Logical Operator6' incorporates:
   *  Delay: '<S379>/Delay'
   *  Delay: '<S380>/Delay'
   *  Logic: '<S379>/Logical Operator'
   *  Logic: '<S379>/Logical Operator1'
   *  Logic: '<S380>/Logical Operator'
   *  Logic: '<S380>/Logical Operator1'
   */
  LampCtl_DomeLampCloseDoor = (rtb_RelationalOperator7_b &&
    (AppSwcBcm_ARID_DEF.RelationalOperator8_g &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_nk)) &&
    (AppSwcBcm_ARID_DEF.RelationalOperator9_k &&
     (!AppSwcBcm_ARID_DEF.Delay_DSTATE_pv)));

  /* Truth Table: '<S313>/Truth Table' */
  /*  Open Door Dome Lamp Turn ON */
  /*  Power Off Or Unlock Door Dome Lamp Turn ON */
  /*  Lock Door or Power On and Close Door Turn Off Dome Lamp */
  /*  Condition #4 */
  /*  Condition #5 */
  /*  Condition #6 */
  rtb_RelationalOperator7_b = !LampCtl_DomeLampLockDoor;
  rtb_RelationalOperator5_b = !LampCtl_DomeLampCloseDoor;
  if (LampCtl_DomeLampFLOpen && rtb_RelationalOperator7_b &&
      rtb_RelationalOperator5_b) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S313>/Lib_SR' */
    /* Switch: '<S365>/Switch' incorporates:
     *  Logic: '<S365>/Logical Operator'
     *  UnitDelay: '<S365>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S313>/Lib_SR' */
  } else if (LampCtl_DomeLampFROpen && rtb_RelationalOperator7_b &&
             rtb_RelationalOperator5_b) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S313>/Lib_SR' */
    /* Switch: '<S365>/Switch' incorporates:
     *  Logic: '<S365>/Logical Operator'
     *  UnitDelay: '<S365>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S313>/Lib_SR' */
  } else if (LampCtl_DomeLampPwrOff && rtb_RelationalOperator7_b &&
             rtb_RelationalOperator5_b) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S313>/Lib_SR' */
    /* Switch: '<S365>/Switch' incorporates:
     *  Logic: '<S365>/Logical Operator'
     *  UnitDelay: '<S365>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S313>/Lib_SR' */
  } else if (LampCtl_DomeLampUnlock && rtb_RelationalOperator7_b &&
             rtb_RelationalOperator5_b) {
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = true;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S313>/Lib_SR' */
    /* Switch: '<S365>/Switch' incorporates:
     *  Logic: '<S365>/Logical Operator'
     *  UnitDelay: '<S365>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S313>/Lib_SR' */
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

    /* Outputs for Atomic SubSystem: '<S313>/Lib_SR' */
    /* Switch: '<S365>/Switch' incorporates:
     *  Constant: '<S365>/Constant'
     */
    LampCtl_DomeLampCtl = false;

    /* End of Outputs for SubSystem: '<S313>/Lib_SR' */
  }

  /* End of Truth Table: '<S313>/Truth Table' */

  /* Switch: '<S363>/Switch' */
  if (LampCtl_DomeLampCtl) {
    /* Switch: '<S363>/Switch' incorporates:
     *  Constant: '<S363>/Constant'
     */
    Switch = 100;
  } else {
    /* Switch: '<S363>/Switch' incorporates:
     *  Constant: '<S363>/Constant1'
     */
    Switch = 0;
  }

  /* End of Switch: '<S363>/Switch' */

  /* Outputs for Atomic SubSystem: '<S363>/Lib_RateLimit' */
  /* Delay: '<S377>/Variable Integer Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_p) {
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)Switch;
  }

  /* Sum: '<S377>/Add' incorporates:
   *  Delay: '<S377>/Variable Integer Delay'
   */
  rtb_Add = (float32)Switch - AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;

  /* Switch: '<S377>/Switch' incorporates:
   *  RelationalOperator: '<S377>/Relational Operator'
   *  RelationalOperator: '<S377>/Relational Operator1'
   *  Switch: '<S377>/Switch1'
   */
  if (rtb_Add > AppSwcBcm_ConstB.Product) {
    /* Switch: '<S377>/Switch' incorporates:
     *  Delay: '<S377>/Variable Integer Delay'
     *  Sum: '<S377>/Add1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += AppSwcBcm_ConstB.Product;
  } else if (rtb_Add < AppSwcBcm_ConstB.Product1) {
    /* Switch: '<S377>/Switch1' incorporates:
     *  Delay: '<S377>/Variable Integer Delay'
     *  Sum: '<S377>/Add2'
     *  Switch: '<S377>/Switch'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += AppSwcBcm_ConstB.Product1;
  } else {
    /* Switch: '<S377>/Switch' incorporates:
     *  Switch: '<S377>/Switch1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)Switch;
  }

  /* End of Switch: '<S377>/Switch' */

  /* Update for Delay: '<S377>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_p = false;

  /* End of Outputs for SubSystem: '<S363>/Lib_RateLimit' */

  /* Switch: '<S363>/Switch1' incorporates:
   *  Switch: '<S363>/Switch2'
   */
  if (LampCtl_DomeLampOffGrad) {
    /* DataTypeConversion: '<S363>/Data Type Conversion' */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
  } else if (LampCtl_DomeLampOnGrad) {
    /* Switch: '<S363>/Switch2' incorporates:
     *  DataTypeConversion: '<S363>/Data Type Conversion'
     */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
  } else {
    /* DataTypeConversion: '<S363>/Data Type Conversion' incorporates:
     *  Switch: '<S363>/Switch1'
     *  Switch: '<S363>/Switch2'
     */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)(float32)Switch;
  }

  /* End of Switch: '<S363>/Switch1' */
}

/* Update for atomic system: '<S233>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S362>/Lib_FailEdgeDetHold1' */
  /* Update for UnitDelay: '<S374>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* End of Update for SubSystem: '<S362>/Lib_FailEdgeDetHold1' */

  /* Update for Delay: '<S378>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_kl = AppSwcBcm_ARID_DEF.RelationalOperator4_g;

  /* Update for Delay: '<S379>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ms = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_nk = AppSwcBcm_ARID_DEF.RelationalOperator8_g;

  /* Update for Delay: '<S380>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_k = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_pv = AppSwcBcm_ARID_DEF.RelationalOperator9_k;
}

/* Output and update for atomic system: '<S233>/FogLampRCtl' */
static void AppSwcBcm_FogLampRCtl(void)
{
  boolean guard1 = false;

  /* Chart: '<S314>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c19_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c19_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib = AppSwcBcm_IN_Off_k;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_b = false;
  } else if (AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib == AppSwcBcm_IN_Off_k) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        LampCtl_PosLampSta && (BSW_FogLampFCfg == 1)) {
      AppSwcBcm_ARID_DEF.Lib_blIn_a1 = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S382>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_a1,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ky,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

      /* End of Outputs for SubSystem: '<S382>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ky) {
        AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib = AppSwcBcm_IN_On_i;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_b = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) || (
         !LampCtl_PosLampSta) || (BSW_FogLampFCfg == 0)) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_a1 = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S382>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_a1,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ky,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_cn);

      /* End of Outputs for SubSystem: '<S382>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ky) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib = AppSwcBcm_IN_Off_k;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_b = false;
    }
  }

  /* End of Chart: '<S314>/Chart1' */

  /* Chart: '<S314>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c17_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c17_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib = AppSwcBcm_IN_Off_k;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e = false;
  } else if (AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib == AppSwcBcm_IN_Off_k) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        LampCtl_PosLampSta && ((LampCtl_LowBeamSta && (BSW_FogLampFCfg == 0)) ||
         ((BSW_FogLampFCfg == 1) && (LampCtl_LowBeamSta ||
           AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_b)))) {
      AppSwcBcm_ARID_DEF.Lib_blIn_db = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S381>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_db,
        &AppSwcBcm_ARID_DEF.LogicalOperator_fk,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fm);

      /* End of Outputs for SubSystem: '<S381>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_fk) {
        AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib = AppSwcBcm_IN_On_i;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) || (
         !LampCtl_PosLampSta)) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_db = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S381>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_db,
        &AppSwcBcm_ARID_DEF.LogicalOperator_fk,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fm);

      /* End of Outputs for SubSystem: '<S381>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_fk) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib = AppSwcBcm_IN_Off_k;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e = false;
    }
  }

  /* End of Chart: '<S314>/Chart' */
}

/* Output and update for atomic system: '<S233>/HiBeamCtl' */
static void AppSwcBcm_HiBeamCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S315>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S315>/Logical Operator' incorporates:
   *  Logic: '<S315>/Logical Operator1'
   *  RelationalOperator: '<S315>/Relational Operator1'
   *  RelationalOperator: '<S315>/Relational Operator2'
   *  RelationalOperator: '<S315>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_gc = (LampCtl_LowBeamSta &&
    rtb_RelationalOperator && (LampCtl_HiBeamSw || LampCtl_PassLightSta));

  /* CCaller: '<S315>/C Caller1' */
  BSW_HiBeamDigSts = GetHw_HiBeamDigSts();

  /* Chart: '<S315>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S315>/Constant28'
   *  Constant: '<S315>/Constant29'
   *  Constant: '<S315>/Constant30'
   *  RelationalOperator: '<S315>/Relational Operator4'
   */
  if (BSW_HiBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ia0 >= (float32)
         LampCtl_HiBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HiBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ia0++;
      AppSwcBcm_ARID_DEF.cnt_heal_gf = (uint16)((float32)
        LampCtl_HiBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ia0 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gf == 0) {
      LampCtl_HiBeamShortToBat = false;
    } else if (LampCtl_HiBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_gf--;
    }
  }

  /* End of Chart: '<S315>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S233>/KnobBeamDig' */
static void AppSwcBcm_KnobBeamDig(void)
{
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_pn;
  boolean rtb_RelationalOperator2_eu;

  /* RelationalOperator: '<S316>/Relational Operator' incorporates:
   *  Constant: '<S316>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S316>/Relational Operator1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator1_pn =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSPstnLghtSwStVld_flg;

  /* RelationalOperator: '<S316>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator2_eu =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLoBeamSwStVld_flg;

  /* Chart: '<S316>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S316>/Constant21'
   *  Constant: '<S316>/Constant3'
   *  Constant: '<S316>/Constant4'
   *  Logic: '<S316>/Logical Operator'
   *  Logic: '<S316>/Logical Operator1'
   */
  if ((rtb_RelationalOperator1_pn || rtb_RelationalOperator2_eu) &&
      rtb_RelationalOperator) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_o1 >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_KnobBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o1++;
      AppSwcBcm_ARID_DEF.cnt_heal_py = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_py == 0) {
      LampCtl_KnobBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_py--;
    }
  }

  /* End of Chart: '<S316>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S233>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_a;

  /* SystemInitialize for Chart: '<S317>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_a);
}

/* Outputs for atomic system: '<S233>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_a;
  boolean rtb_RelationalOperator1_ko;

  /* Chart: '<S317>/LIB_Tim' incorporates:
   *  Constant: '<S317>/Constant6'
   *  UnitDelay: '<S317>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pm,
    LampCtl_LampDelayTim_C, &rtb_LIB_blOut_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_m);

  /* RelationalOperator: '<S317>/Relational Operator1' incorporates:
   *  Constant: '<S317>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_ko = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Outputs for Atomic SubSystem: '<S317>/Lib_SR' */
  /* Switch: '<S391>/Switch' incorporates:
   *  Constant: '<S317>/Constant'
   *  Logic: '<S317>/Logical Operator1'
   *  RelationalOperator: '<S317>/Relational Operator'
   *  RelationalOperator: '<S317>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) ||
      rtb_RelationalOperator1_ko || (!LampCtl_AutoLampSw) || rtb_LIB_blOut_a) {
    /* Switch: '<S391>/Switch' incorporates:
     *  Constant: '<S391>/Constant'
     */
    LampCtl_LampDelay = false;
  } else {
    /* RelationalOperator: '<S390>/Relational Operator1' incorporates:
     *  Constant: '<S317>/Constant5'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator1_ko = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 0);

    /* Switch: '<S391>/Switch' incorporates:
     *  Constant: '<S317>/Constant3'
     *  Constant: '<S317>/Constant4'
     *  Logic: '<S317>/Logical Operator'
     *  Logic: '<S390>/Logical Operator'
     *  Logic: '<S391>/Logical Operator'
     *  RelationalOperator: '<S317>/Relational Operator3'
     *  RelationalOperator: '<S390>/Relational Operator'
     *  UnitDelay: '<S390>/Unit Delay'
     *  UnitDelay: '<S391>/Unit Delay'
     */
    LampCtl_LampDelay = (((LampCtl_LightIntstSta == 2) &&
                          (rtb_RelationalOperator1_ko &&
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hk == 2))) || LampCtl_LampDelay);
  }

  /* End of Switch: '<S391>/Switch' */
  /* End of Outputs for SubSystem: '<S317>/Lib_SR' */
}

/* Update for atomic system: '<S233>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Update(void)
{
  /* Update for UnitDelay: '<S317>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pm = LampCtl_LampDelay;

  /* Update for UnitDelay: '<S390>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hk =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
}

/* Output and update for atomic system: '<S233>/LightIntstDet' */
static void AppSwcBcm_LightIntstDet(void)
{
  /* Chart: '<S318>/Chart' */
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

  /* End of Chart: '<S318>/Chart' */
}

/* System initialize for atomic system: '<S233>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S319>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);
}

/* Output and update for atomic system: '<S233>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S319>/Relational Operator' incorporates:
   *  Constant: '<S319>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Chart: '<S319>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S319>/Constant13'
   *  Constant: '<S319>/Constant4'
   *  Constant: '<S319>/Constant5'
   *  Logic: '<S319>/Logical Operator'
   *  Logic: '<S319>/Logical Operator1'
   *  Logic: '<S319>/Logical Operator2'
   *  RelationalOperator: '<S319>/Relational Operator1'
   *  RelationalOperator: '<S319>/Relational Operator2'
   *  RelationalOperator: '<S319>/Relational Operator3'
   *  UnitDelay: '<S233>/Unit Delay'
   *  UnitDelay: '<S233>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms1((rtb_RelationalOperator && (LampCtl_LowBeamSw ||
    LampCtl_PassLightSta || LampCtl_AutoLampSta || LampCtl_KnobBeamFaultSta)) ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m || LampCtl_LampDelay,
    LampCtl_LowBeamStaTimValid_C, LampCtl_LowBeamStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_m);

  /* CCaller: '<S319>/C Caller' */
  BSW_LowBeamDigSts = GetHw_LoBeamDigSts();

  /* Chart: '<S319>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S319>/Constant28'
   *  Constant: '<S319>/Constant29'
   *  Constant: '<S319>/Constant30'
   *  RelationalOperator: '<S319>/Relational Operator4'
   */
  if (BSW_LowBeamDigSts == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_an >= (float32)
         LampCtl_LowBeamShortToBatTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_LowBeamShortToBatTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamShortToBat = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_an++;
      AppSwcBcm_ARID_DEF.cnt_heal_ax = (uint16)((float32)
        LampCtl_LowBeamShortToBatTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_an = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ax == 0) {
      LampCtl_LowBeamShortToBat = false;
    } else if (LampCtl_LowBeamShortToBatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ax--;
    }
  }

  /* End of Chart: '<S319>/LIB_TPD_10ms3' */
}

/* Output and update for atomic system: '<S233>/BrakeLampCtl' */
static void AppSwcBcm_BrakeLampCtl(void)
{
  boolean rtb_RelationalOperator2_m;
  boolean rtb_RelationalOperator8_n;

  /* RelationalOperator: '<S311>/Relational Operator8' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S311>/Relational Operator3'
   */
  rtb_RelationalOperator8_n =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLA_flg;

  /* RelationalOperator: '<S311>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S311>/Relational Operator6'
   */
  rtb_RelationalOperator2_m =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLAVld_flg;

  /* Logic: '<S311>/Logical Operator4' */
  rtb_RelationalOperator8_n = (rtb_RelationalOperator8_n &&
    rtb_RelationalOperator2_m);

  /* RelationalOperator: '<S311>/Relational Operator2' incorporates:
   *  Constant: '<S311>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator2_m = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S311>/Logical Operator' incorporates:
   *  Logic: '<S311>/Logical Operator1'
   *  Logic: '<S311>/Logical Operator3'
   *  Logic: '<S311>/Logical Operator5'
   *  RelationalOperator: '<S311>/Relational Operator'
   *  RelationalOperator: '<S311>/Relational Operator1'
   *  RelationalOperator: '<S311>/Relational Operator7'
   *  RelationalOperator: '<S311>/Relational Operator8'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_ib = (LampCtl_BrakeLightSw ||
    (rtb_RelationalOperator2_m &&
     (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VVTM_RegenReqBrkLampOn_flg ||
      rtb_RelationalOperator8_n ||
      (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e.VIPM_ESCReqBrkLghtOn_flg &&
       AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e.VIPM_ESCReqBrkLghtOnVld_flg))));
}

/* Output and update for atomic system: '<S233>/ReverseLampCtl' */
static void AppSwcBcm_ReverseLampCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S337>/Relational Operator' incorporates:
   *  Constant: '<S337>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S337>/Logical Operator' incorporates:
   *  Constant: '<S337>/Constant1'
   *  RelationalOperator: '<S337>/Relational Operator1'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_fq = (rtb_RelationalOperator &&
    (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VGSM_VehActGearPstn_enum == 3));
}

/* Output and update for atomic system: '<S233>/PassLampFunc' */
static void AppSwcBcm_PassLampFunc(void)
{
  /* Chart: '<S335>/LIB_Tim' incorporates:
   *  Constant: '<S335>/Constant1'
   *  RelationalOperator: '<S335>/Relational Operator'
   */
  if (LampCtl_PassLightSw) {
    if (AppSwcBcm_ARID_DEF.Cnt_a <= 1000) {
      AppSwcBcm_ARID_DEF.Cnt_a++;
      LampCtl_PassLightSta = true;
    } else {
      LampCtl_PassLightSta = false;
    }
  } else {
    LampCtl_PassLightSta = false;
    AppSwcBcm_ARID_DEF.Cnt_a = 0U;
  }

  /* End of Chart: '<S335>/LIB_Tim' */
}

/* System initialize for atomic system: '<S233>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S336>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_e);
}

/* Output and update for atomic system: '<S233>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S336>/Relational Operator' incorporates:
   *  Constant: '<S336>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Chart: '<S336>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S336>/Constant13'
   *  Constant: '<S336>/Constant2'
   *  Constant: '<S336>/Constant4'
   *  Logic: '<S336>/Logical Operator'
   *  Logic: '<S336>/Logical Operator1'
   *  Logic: '<S336>/Logical Operator2'
   *  RelationalOperator: '<S336>/Relational Operator1'
   *  RelationalOperator: '<S336>/Relational Operator3'
   *  UnitDelay: '<S233>/Unit Delay'
   *  UnitDelay: '<S233>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms1((rtb_RelationalOperator && (LampCtl_PosLampSw ||
    LampCtl_LowBeamSw || LampCtl_AutoLampSta)) ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m || LampCtl_KnobBeamFaultSta ||
    LampCtl_LampDelay, LampCtl_PosLampStaTimValid_C,
    LampCtl_PosLampStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_l);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift10'
 *    '<S661>/Bit Shift9'
 */
static uint16 AppSwcBcm_BitShift10_i(uint16 rtu_u)
{
  /* MATLAB Function: '<S399>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 8);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift11'
 *    '<S661>/Bit Shift12'
 */
static uint16 AppSwcBcm_BitShift11_i(uint16 rtu_u)
{
  /* MATLAB Function: '<S400>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 11);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift2'
 *    '<S661>/Bit Shift4'
 */
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u)
{
  /* MATLAB Function: '<S401>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift3'
 *    '<S661>/Bit Shift8'
 */
static uint16 AppSwcBcm_BitShift3_f(uint16 rtu_u)
{
  /* MATLAB Function: '<S402>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift4'
 *    '<S571>/Bit Shift1'
 *    '<S661>/Bit Shift1'
 */
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u)
{
  /* MATLAB Function: '<S403>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift7'
 *    '<S571>/Bit Shift2'
 *    '<S661>/Bit Shift2'
 */
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u)
{
  /* MATLAB Function: '<S406>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 2);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift8'
 *    '<S661>/Bit Shift6'
 */
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u)
{
  /* MATLAB Function: '<S407>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S338>/Bit Shift9'
 *    '<S661>/Bit Shift7'
 */
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u)
{
  /* MATLAB Function: '<S408>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 6);
}

/* System initialize for atomic system: '<S233>/SignalProcess' */
static void AppSwcBcm_SignalProcess_Init(void)
{
  /* SystemInitialize for Chart: '<S338>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_m);

  /* SystemInitialize for Chart: '<S338>/LIB_TPD_10ms13' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_n);
}

/* Output and update for atomic system: '<S233>/SignalProcess' */
static void AppSwcBcm_SignalProcess(void)
{
  uint16 rtb_y;
  uint16 rtb_y_d;
  boolean rtb_LogicalOperator2_o;
  boolean rtb_Switch;
  boolean rtb_Switch9_l;

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift' */
  /* Constant: '<S338>/Constant48' */
  rtb_y = AppSwcBcm_BitShift3(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift' */

  /* Switch: '<S338>/Switch' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S338>/Switch' incorporates:
     *  Constant: '<S338>/Constant50'
     */
    rtb_Switch = LampCtl_PosLampVal_C;
  } else {
    /* Switch: '<S338>/Switch' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S338>/Logical Operator6'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSPstnLghtSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSPstnLghtSwStVld_flg);
  }

  /* End of Switch: '<S338>/Switch' */

  /* Chart: '<S338>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S338>/Constant19'
   *  Constant: '<S338>/Constant20'
   *  Constant: '<S338>/Constant21'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_i1 >= (float32)LampCtl_PosLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_PosLampTimValid_C != 0xFFFF)) {
      LampCtl_PosLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_i1++;
      AppSwcBcm_ARID_DEF.cnt_heal_kt = (uint16)((float32)
        LampCtl_PosLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_i1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_kt == 0) {
      LampCtl_PosLampSw = false;
    } else if (LampCtl_PosLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_kt--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift4' */
  /* Constant: '<S338>/Constant1' */
  rtb_y_d = AppSwcBcm_BitShift4(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift4' */

  /* Switch: '<S338>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND4'
   */
  if ((rtb_y_d & 1U) != 0U) {
    /* Switch: '<S338>/Switch4' incorporates:
     *  Constant: '<S338>/Constant10'
     */
    rtb_Switch = LampCtl_LowBeamVal_C;
  } else {
    /* Switch: '<S338>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S338>/Logical Operator7'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLoBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLoBeamSwStVld_flg);
  }

  /* End of Switch: '<S338>/Switch4' */

  /* Chart: '<S338>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S338>/Constant22'
   *  Constant: '<S338>/Constant23'
   *  Constant: '<S338>/Constant24'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ia >= (float32)LampCtl_LowBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_LowBeamTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ia++;
      AppSwcBcm_ARID_DEF.cnt_heal_cb = (uint16)((float32)
        LampCtl_LowBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ia = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cb == 0) {
      LampCtl_LowBeamSw = false;
    } else if (LampCtl_LowBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cb--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift7' */
  /* Constant: '<S338>/Constant12' */
  rtb_y_d = AppSwcBcm_BitShift7(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift7' */

  /* Switch: '<S338>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND7'
   */
  if ((rtb_y_d & 1U) != 0U) {
    /* Switch: '<S338>/Switch7' incorporates:
     *  Constant: '<S338>/Constant11'
     */
    rtb_Switch = LampCtl_HiBeamVal_C;
  } else {
    /* Switch: '<S338>/Switch7' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S338>/Logical Operator8'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSHiBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSHiBeamSwStVld_flg);
  }

  /* End of Switch: '<S338>/Switch7' */

  /* Chart: '<S338>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S338>/Constant25'
   *  Constant: '<S338>/Constant26'
   *  Constant: '<S338>/Constant27'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_j5 >= (float32)LampCtl_HiBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_HiBeamTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j5++;
      AppSwcBcm_ARID_DEF.cnt_heal_hd = (uint16)((float32)
        LampCtl_HiBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j5 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hd == 0) {
      LampCtl_HiBeamSw = false;
    } else if (LampCtl_HiBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hd--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift1' */
  /* Constant: '<S338>/Constant3' */
  rtb_y = AppSwcBcm_BitShift1_p(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift1' */

  /* Switch: '<S338>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S338>/Switch1' incorporates:
     *  Constant: '<S338>/Constant2'
     */
    rtb_Switch = LampCtl_PassLightVal_C;
  } else {
    /* Switch: '<S338>/Switch1' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S338>/Logical Operator1'
     */
    rtb_Switch =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSOvrVehBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSOvrVehBeamSwStVld_flg);
  }

  /* End of Switch: '<S338>/Switch1' */

  /* Chart: '<S338>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S338>/Constant28'
   *  Constant: '<S338>/Constant29'
   *  Constant: '<S338>/Constant30'
   */
  if (rtb_Switch) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_j >= (float32)LampCtl_PassLightTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_PassLightTimValid_C != 0xFFFF))
    {
      LampCtl_PassLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j++;
      AppSwcBcm_ARID_DEF.cnt_heal_ef = (uint16)((float32)
        LampCtl_PassLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ef == 0) {
      LampCtl_PassLightSw = false;
    } else if (LampCtl_PassLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ef--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift2' */
  /* Constant: '<S338>/Constant53' */
  rtb_y = AppSwcBcm_BitShift2(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift8' */
  /* Constant: '<S338>/Constant4' */
  rtb_y_d = AppSwcBcm_BitShift8(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift8' */

  /* Logic: '<S338>/Logical Operator3' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_Switch =
    ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwSt_flg &&
     (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwStVld_flg);

  /* Logic: '<S338>/Logical Operator2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_LogicalOperator2_o =
    ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwSt_flg &&
     (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwStVld_flg);

  /* Switch: '<S338>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND8'
   */
  if ((rtb_y_d & 1U) != 0U) {
    /* Switch: '<S338>/Switch9' incorporates:
     *  Constant: '<S338>/Constant5'
     */
    rtb_Switch9_l = LampCtl_TurnIndcrRVal_C;
  } else {
    /* Switch: '<S338>/Switch9' incorporates:
     *  Logic: '<S338>/Logical Operator'
     *  Logic: '<S338>/Logical Operator10'
     */
    rtb_Switch9_l = (rtb_Switch && (!rtb_LogicalOperator2_o));
  }

  /* End of Switch: '<S338>/Switch9' */

  /* Chart: '<S338>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S338>/Constant37'
   *  Constant: '<S338>/Constant38'
   *  Constant: '<S338>/Constant39'
   */
  if (rtb_Switch9_l) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hz >= (float32)
         LampCtl_TurnIndcrRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hz++;
      AppSwcBcm_ARID_DEF.cnt_heal_lw = (uint16)((float32)
        LampCtl_TurnIndcrRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S338>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S338>/Constant37'
     *  Constant: '<S338>/Constant38'
     *  Constant: '<S338>/Constant39'
     *  Constant: '<S338>/Constant40'
     *  Constant: '<S338>/Constant41'
     *  Constant: '<S338>/Constant42'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c2 >= (float32)
         LampCtl_TurnIndcrLaneRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c2++;
      AppSwcBcm_ARID_DEF.cnt_heal_ld = (uint16)((float32)
        LampCtl_TurnIndcrLaneRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hz = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lw == 0) {
      LampCtl_TurnIndcrRSw = false;
    } else if (LampCtl_TurnIndcrRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_lw--;
    }

    /* Chart: '<S338>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S338>/Constant38'
     *  Constant: '<S338>/Constant41'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_c2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ld == 0) {
      LampCtl_TurnIndcrLaneRSw = false;
    } else if (LampCtl_TurnIndcrLaneRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ld--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms6' */

  /* Switch: '<S338>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S338>/Switch2' incorporates:
     *  Constant: '<S338>/Constant54'
     */
    rtb_LogicalOperator2_o = LampCtl_TurnIndcrLVal_C;
  } else {
    /* Switch: '<S338>/Switch2' incorporates:
     *  Logic: '<S338>/Logical Operator12'
     *  Logic: '<S338>/Logical Operator5'
     *  UnitDelay: '<S338>/Unit Delay1'
     */
    rtb_LogicalOperator2_o = (rtb_LogicalOperator2_o &&
      (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m2));
  }

  /* End of Switch: '<S338>/Switch2' */

  /* Chart: '<S338>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S338>/Constant31'
   *  Constant: '<S338>/Constant32'
   *  Constant: '<S338>/Constant33'
   */
  if (rtb_LogicalOperator2_o) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lf >= (float32)
         LampCtl_TurnIndcrLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lf++;
      AppSwcBcm_ARID_DEF.cnt_heal_lj = (uint16)((float32)
        LampCtl_TurnIndcrLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S338>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S338>/Constant31'
     *  Constant: '<S338>/Constant32'
     *  Constant: '<S338>/Constant33'
     *  Constant: '<S338>/Constant34'
     *  Constant: '<S338>/Constant35'
     *  Constant: '<S338>/Constant36'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_g >= (float32)
         LampCtl_TurnIndcrLaneLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_g++;
      AppSwcBcm_ARID_DEF.cnt_heal_c2 = (uint16)((float32)
        LampCtl_TurnIndcrLaneLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lf = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lj == 0) {
      LampCtl_TurnIndcrLSw = false;
    } else if (LampCtl_TurnIndcrLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_lj--;
    }

    /* Chart: '<S338>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S338>/Constant32'
     *  Constant: '<S338>/Constant35'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_g = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c2 == 0) {
      LampCtl_TurnIndcrLaneLSw = false;
    } else if (LampCtl_TurnIndcrLaneLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_c2--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift3' */
  /* Constant: '<S338>/Constant55' */
  rtb_y_d = AppSwcBcm_BitShift3_f(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift3' */

  /* Switch: '<S338>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND3'
   */
  if ((rtb_y_d & 1U) != 0U) {
    /* Switch: '<S338>/Switch3' incorporates:
     *  Constant: '<S338>/Constant56'
     */
    rtb_LogicalOperator2_o = LampCtl_FogLampRVal_C;
  } else {
    /* Switch: '<S338>/Switch3' incorporates:
     *  DataTypeConversion: '<S338>/Data Type Conversion3'
     *  Logic: '<S338>/Logical Operator9'
     */
    rtb_LogicalOperator2_o = (BSW_J346FogLampR == 0);
  }

  /* End of Switch: '<S338>/Switch3' */

  /* Chart: '<S338>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S338>/Constant43'
   *  Constant: '<S338>/Constant44'
   *  Constant: '<S338>/Constant45'
   */
  if (rtb_LogicalOperator2_o) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lu >= (float32)LampCtl_FogLampRTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampRTimValid_C != 0xFFFF)) {
      LampCtl_FogLampRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lu++;
      AppSwcBcm_ARID_DEF.cnt_heal_hh = (uint16)((float32)
        LampCtl_FogLampRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lu = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hh == 0) {
      LampCtl_FogLampRSw = false;
    } else if (LampCtl_FogLampRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hh--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms9' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift5' */
  /* S-Function (sfix_bitop): '<S338>/Bitwise AND5' incorporates:
   *  Constant: '<S338>/Constant59'
   *  MATLAB Function: '<S404>/bit_shift'
   */
  rtb_y_d = (uint16)((sint32)((uint32)LampCtl_InportCalSwBit_C >> 9) & 1);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift5' */

  /* Switch: '<S338>/Switch5' */
  if (rtb_y_d != 0) {
    /* Switch: '<S338>/Switch5' incorporates:
     *  Constant: '<S338>/Constant60'
     */
    rtb_LogicalOperator2_o = LampCtl_HazardLightVal_C;
  } else {
    /* Switch: '<S338>/Switch5' */
    rtb_LogicalOperator2_o =
      AppSwcBcm_ARID_DEF.IPM_CCP_PanelStatus_BOD_d.VIPM_CCPHzrdKey_flg;
  }

  /* End of Switch: '<S338>/Switch5' */

  /* Chart: '<S338>/LIB_TPD_10ms10' incorporates:
   *  Constant: '<S338>/Constant46'
   *  Constant: '<S338>/Constant47'
   *  Constant: '<S338>/Constant49'
   */
  if (rtb_LogicalOperator2_o) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_kt >= (float32)
         LampCtl_HazardLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HazardLightTimValid_C != 0xFFFF)) {
      LampCtl_HazardLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_kt++;
      AppSwcBcm_ARID_DEF.cnt_heal_i = (uint16)((float32)
        LampCtl_HazardLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_kt = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_i == 0) {
      LampCtl_HazardLightSw = false;
    } else if (LampCtl_HazardLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_i--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms10' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift11' */
  /* Constant: '<S338>/Constant73' */
  rtb_y = AppSwcBcm_BitShift11_i(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift6' */
  /* Switch: '<S338>/Switch6' incorporates:
   *  Constant: '<S338>/Constant61'
   *  Constant: '<S338>/Constant62'
   *  DataTypeConversion: '<S338>/Data Type Conversion6'
   *  MATLAB Function: '<S405>/bit_shift'
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND6'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 10 & 1U) != 0U) {
    rtb_LogicalOperator2_o = LampCtl_BrakeLightVal_C;
  } else {
    rtb_LogicalOperator2_o = (BSW_J313BrakeLoSw != 0);
  }

  /* End of Outputs for SubSystem: '<S338>/Bit Shift6' */

  /* Chart: '<S338>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S338>/Constant14'
   *  Constant: '<S338>/Constant15'
   *  Constant: '<S338>/Constant16'
   *  Switch: '<S338>/Switch6'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_LogicalOperator2_o, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11_o);

  /* Switch: '<S338>/Switch12' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND11'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S338>/Switch12' incorporates:
     *  Constant: '<S338>/Constant74'
     */
    rtb_LogicalOperator2_o = LampCtl_BrakeLightVal_C;
  } else {
    /* Switch: '<S338>/Switch12' incorporates:
     *  DataTypeConversion: '<S338>/Data Type Conversion13'
     *  Logic: '<S338>/Logical Operator14'
     */
    rtb_LogicalOperator2_o = (BSW_J339BrakeHiSw == 0);
  }

  /* End of Switch: '<S338>/Switch12' */

  /* Chart: '<S338>/LIB_TPD_10ms13' incorporates:
   *  Constant: '<S338>/Constant70'
   *  Constant: '<S338>/Constant71'
   *  Constant: '<S338>/Constant72'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_LogicalOperator2_o, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms13);

  /* Logic: '<S338>/Logical Operator13' */
  LampCtl_BrakeLightSw = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_m ||
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_n);

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift9' */
  /* Constant: '<S338>/Constant6' */
  rtb_y_d = AppSwcBcm_BitShift9(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift9' */

  /* Switch: '<S338>/Switch10' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND9'
   */
  if ((rtb_y_d & 1U) != 0U) {
    /* Switch: '<S338>/Switch10' incorporates:
     *  Constant: '<S338>/Constant8'
     */
    rtb_LogicalOperator2_o = LampCtl_AutoLampVal_C;
  } else {
    /* Switch: '<S338>/Switch10' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S338>/Logical Operator4'
     */
    rtb_LogicalOperator2_o =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLampAutoSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLampAutoStVld_flg);
  }

  /* End of Switch: '<S338>/Switch10' */

  /* Chart: '<S338>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S338>/Constant13'
   *  Constant: '<S338>/Constant63'
   *  Constant: '<S338>/Constant9'
   */
  if (rtb_LogicalOperator2_o) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_a >= (float32)LampCtl_AutoLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_AutoLampTimValid_C != 0xFFFF)) {
      LampCtl_AutoLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_a++;
      AppSwcBcm_ARID_DEF.cnt_heal_a = (uint16)((float32)
        LampCtl_AutoLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_a = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a == 0) {
      LampCtl_AutoLampSw = false;
    } else if (LampCtl_AutoLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_a--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S338>/Bit Shift10' */
  /* Constant: '<S338>/Constant68' */
  rtb_y = AppSwcBcm_BitShift10_i(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S338>/Bit Shift10' */

  /* Switch: '<S338>/Switch11' incorporates:
   *  S-Function (sfix_bitop): '<S338>/Bitwise AND10'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S338>/Switch11' incorporates:
     *  Constant: '<S338>/Constant69'
     */
    rtb_LogicalOperator2_o = LampCtl_FogLampFVal_C;
  } else {
    /* Switch: '<S338>/Switch11' incorporates:
     *  DataTypeConversion: '<S338>/Data Type Conversion9'
     *  Logic: '<S338>/Logical Operator11'
     */
    rtb_LogicalOperator2_o = (BSW_J322FogLampF == 0);
  }

  /* End of Switch: '<S338>/Switch11' */

  /* Chart: '<S338>/LIB_TPD_10ms12' incorporates:
   *  Constant: '<S338>/Constant64'
   *  Constant: '<S338>/Constant66'
   *  Constant: '<S338>/Constant67'
   */
  if (rtb_LogicalOperator2_o) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hl >= (float32)LampCtl_FogLampFTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampFTimValid_C != 0xFFFF)) {
      LampCtl_FogLampFSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hl++;
      AppSwcBcm_ARID_DEF.cnt_heal_mq = (uint16)((float32)
        LampCtl_FogLampFTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hl = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mq == 0) {
      LampCtl_FogLampFSw = false;
    } else if (LampCtl_FogLampFTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mq--;
    }
  }

  /* End of Chart: '<S338>/LIB_TPD_10ms12' */

  /* MultiPortSwitch: '<S338>/Multiport Switch' */
  switch (BSW_RKEReq) {
   case 0:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant'
     */
    LampCtl_RKEReq = 0U;
    break;

   case 17:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant17'
     */
    LampCtl_RKEReq = 1U;
    break;

   case 18:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant18'
     */
    LampCtl_RKEReq = 2U;
    break;

   case 19:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant51'
     */
    LampCtl_RKEReq = 3U;
    break;

   case 34:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant52'
     */
    LampCtl_RKEReq = 4U;
    break;

   case 49:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant57'
     */
    LampCtl_RKEReq = 5U;
    break;

   case 50:
    /* MultiPortSwitch: '<S338>/Multiport Switch' incorporates:
     *  Constant: '<S338>/Constant58'
     */
    LampCtl_RKEReq = 6U;
    break;
  }

  /* End of MultiPortSwitch: '<S338>/Multiport Switch' */

  /* DataTypeConversion: '<S338>/Data Type Conversion12' */
  LampCtl_LightIntstVal = BSW_J125LightIntst;

  /* Update for UnitDelay: '<S338>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m2 = rtb_Switch;
}

/*
 * System initialize for function-call system:
 *    '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
  (ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
   *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S463>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_o_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S463>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(boolean rtu_Lib_blIn,
  boolean *rty_Lib_blOut, ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S463>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_o(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S463>/Lib_RiseEdgeDetInit' */
}

/*
 * System initialize for function-call system:
 *    '<S488>/Lib_ChangeEdge'
 *    '<S488>/Lib_ChangeEdge1'
 *    '<S488>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge_Init(ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S492>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S488>/Lib_ChangeEdge'
 *    '<S488>/Lib_ChangeEdge1'
 *    '<S488>/Lib_ChangeEdge2'
 */
static void AppSwcBcm_Lib_ChangeEdge(float32 rtu_Lib_In, float32 rtu_Lib_InNow,
  float32 rtu_Lib_InBefore, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChangeEdge_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S492>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
  }

  /* Logic: '<S492>/Logical Operator' incorporates:
   *  Delay: '<S492>/Delay'
   *  RelationalOperator: '<S492>/Relational Operator'
   *  RelationalOperator: '<S492>/Relational Operator1'
   */
  *rty_Lib_blOut = ((rtu_Lib_InNow == rtu_Lib_In) &&
                    (AppSwcBcm__ARID_DEF_arg->Delay_DSTATE == rtu_Lib_InBefore));

  /* Update for Delay: '<S492>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_In;
}

/*
 * System initialize for function-call system:
 *    '<S447>/Pri4Func.Turn'
 *    '<S447>/Pri4Func.Turn1'
 *    '<S447>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y)
{
  /* SystemInitialize for Chart: '<S504>/Turn' */
  *rty_y = false;
}

/*
 * Output and update for function-call system:
 *    '<S447>/Pri4Func.Turn'
 *    '<S447>/Pri4Func.Turn1'
 *    '<S447>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S504>/Turn' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c80_LampCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c80_LampCtl_Lib = 1U;
    *rty_y = !rtu_x;
  }

  /* End of Chart: '<S504>/Turn' */
}

/*
 * System initialize for atomic system:
 *    '<S448>/TurnIndcrDig'
 *    '<S448>/TurnIndcrDig1'
 *    '<S448>/TurnIndcrDig2'
 *    '<S448>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig_Init(boolean *rty_LIB_blErrFlg)
{
  *rty_LIB_blErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S448>/TurnIndcrDig'
 *    '<S448>/TurnIndcrDig1'
 *    '<S448>/TurnIndcrDig2'
 *    '<S448>/TurnIndcrDig3'
 */
static void AppSwcBcm_TurnIndcrDig(boolean rtu_LIB_blIn, boolean rtu_LIB_blIn2,
  boolean rtu_LIB_blRst, float32 rtu_LIB_s32Ts, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, uint8 rtu_LIB_u8Cnt, boolean *rty_LIB_blErrFlg,
  ARID_DEF_TurnIndcrDig_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;
  float32 tmp_0;

  /* Chart: '<S448>/TurnIndcrDig' */
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

  /* End of Chart: '<S448>/TurnIndcrDig' */
}

/*
 * Output and update for atomic system:
 *    '<S527>/Lib_BothEdgeDet'
 *    '<S839>/Lib_BothEdgeDet'
 *    '<S839>/Lib_BothEdgeDet1'
 *    '<S839>/Lib_BothEdgeDet2'
 *    '<S839>/Lib_BothEdgeDet3'
 */
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S528>/Logical Operator2' incorporates:
   *  Logic: '<S528>/Logical Operator1'
   *  Logic: '<S528>/Logical Operator3'
   *  Logic: '<S528>/Logical Operator4'
   *  Logic: '<S528>/Logical Operator5'
   *  UnitDelay: '<S528>/Unit Delay'
   */
  *rty_Lib_blOut = ((AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_Lib_blIn))
                    || (rtu_Lib_blIn &&
                        (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE)));

  /* Update for UnitDelay: '<S528>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S339>/HazardLightLogic' */
static boolean AppSwcBcm_EmerOff(void)
{
  boolean guard1 = false;
  boolean y;

  /* UnitDelay: '<S339>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.Lib_blIn_k = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g;

  /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet1' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_k,
    &AppSwcBcm_ARID_DEF.LogicalOperator_lw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

  /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet1' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_lw) {
    guard1 = true;
  } else {
    /* UnitDelay: '<S339>/Unit Delay5' */
    AppSwcBcm_ARID_DEF.Lib_blIn_ed = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p;

    /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet2' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ed,
      &AppSwcBcm_ARID_DEF.LogicalOperator_h2,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_o);

    /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet2' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_h2) {
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

/* Function for Chart: '<S339>/HazardLightLogic' */
static boolean AppSwcBcm_HazardOff(void)
{
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_ld = LampCtl_HazardLightSw;

  /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ld,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mk,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o2);

  /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_mk) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
  } else {
    y = false;
  }

  return y;
}

/* Function for Chart: '<S339>/HazardLightLogic' */
static boolean AppSwcBcm_TurnOff(void)
{
  boolean guard1 = false;
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_ce = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 1);

  /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet4' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ce,
    &AppSwcBcm_ARID_DEF.LogicalOperator_bw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet4);

  /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet4' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_bw) {
    guard1 = true;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_gr = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta ==
      2);

    /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet5' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_gr,
      &AppSwcBcm_ARID_DEF.LogicalOperator_g5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet5);

    /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet5' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_g5) {
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

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_TurnFunc(void)
{
  LampCtl_TurnIndcrRst = !LampCtl_TurnIndcrRst;
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_Pri1Func(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_EnFunc(void)
{
  LampCtl_TurnIndcrPrd = 0U;
  LampCtl_TurnIndcrWdt = 0U;
  LampCtl_TurnIndcrRFlashCnt = 0U;
  LampCtl_TurnIndcrLFlashCnt = 0U;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_Pri2Func(void)
{
  LampCtl_TurnIndcrPrd = 16U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_Pri4Func(void)
{
  switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide) {
   case 2:
    AppSwcBcm_ARID_DEF.x = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S447>/Pri4Func.Turn' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x, &AppSwcBcm_ARID_DEF.y_p,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn);

    /* End of Outputs for SubSystem: '<S447>/Pri4Func.Turn' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_p;
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
    AppSwcBcm_ARID_DEF.x_f = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S447>/Pri4Func.Turn1' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_f, &AppSwcBcm_ARID_DEF.y_j,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn1);

    /* End of Outputs for SubSystem: '<S447>/Pri4Func.Turn1' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_j;
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

    /* Outputs for Function Call SubSystem: '<S447>/Pri4Func.Turn2' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_e, &AppSwcBcm_ARID_DEF.y,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn2);

    /* End of Outputs for SubSystem: '<S447>/Pri4Func.Turn2' */
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

/* Function for Chart: '<S339>/TurnIndcrArb2' */
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

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_AntiLckFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_nj = AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;

  /* Outputs for Function Call SubSystem: '<S447>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_nj,
    &AppSwcBcm_ARID_DEF.RelationalOperator_nh,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5AntiLckFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S447>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_nh) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_ArmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 40U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
  AppSwcBcm_ARID_DEF.Lib_blIn_jt = AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;

  /* Outputs for Function Call SubSystem: '<S447>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_jt,
    &AppSwcBcm_ARID_DEF.RelationalOperator_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5ArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S447>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_f) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_DisarmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_et = AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;

  /* Outputs for Function Call SubSystem: '<S447>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_et,
    &AppSwcBcm_ARID_DEF.RelationalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5DisarmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S447>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_p) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
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

  AppSwcBcm_ARID_DEF.Lib_blIn_a4 = AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;

  /* Outputs for Function Call SubSystem: '<S447>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_a4,
    &AppSwcBcm_ARID_DEF.RelationalOperator_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5PartArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S447>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_e) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_RodBeamFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_SeekFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = 10U;
  LampCtl_TurnIndcrLFlashCnt = 10U;
  AppSwcBcm_ARID_DEF.Lib_blIn_mq = AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;

  /* Outputs for Function Call SubSystem: '<S447>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_mq,
    &AppSwcBcm_ARID_DEF.RelationalOperator_px,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5SeekFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S447>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_px) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S339>/TurnIndcrArb2' */
static void AppSwcBcm_TrunkWarnFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
}

/* Function for Chart: '<S438>/Chart' */
static void AppSwcBcm_CrashClearFunc(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_hn =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

  /* Outputs for Function Call SubSystem: '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit' */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_hn,
    &AppSwcBcm_ARID_DEF.LogicalOperator_ow,
    &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit' */
  AppSwcBcm_ARID_DEF.PwrOffFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_ow ||
    AppSwcBcm_ARID_DEF.PwrOffFlg);
  if (AppSwcBcm_ARID_DEF.PwrOffFlg) {
    AppSwcBcm_ARID_DEF.Lib_blIn_lb =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

    /* Outputs for Function Call SubSystem: '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
    AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_lb,
      &AppSwcBcm_ARID_DEF.LogicalOperator_mh,
      &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

    /* End of Outputs for SubSystem: '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
    AppSwcBcm_ARID_DEF.PwrOnFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_mh ||
      AppSwcBcm_ARID_DEF.PwrOnFlg);
  }
}

/* System initialize for atomic system: '<S233>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S435>/Chart' incorporates:
   *  SubSystem: '<S455>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_co);

  /* SystemInitialize for Chart: '<S437>/Chart' incorporates:
   *  SubSystem: '<S459>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_g);

  /* SystemInitialize for Chart: '<S438>/Chart' incorporates:
   *  SubSystem: '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S438>/Chart' incorporates:
   *  SubSystem: '<S462>/CrashClearFunc.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S439>/Chart' incorporates:
   *  SubSystem: '<S473>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_i);

  /* SystemInitialize for Chart: '<S442>/Chart' incorporates:
   *  SubSystem: '<S488>/Lib_ChangeEdge'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

  /* SystemInitialize for Chart: '<S442>/Chart' incorporates:
   *  SubSystem: '<S488>/Lib_ChangeEdge1'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

  /* SystemInitialize for Chart: '<S442>/Chart' incorporates:
   *  SubSystem: '<S488>/Lib_ChangeEdge2'
   */
  AppSwcBcm_Lib_ChangeEdge_Init(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

  /* SystemInitialize for Chart: '<S446>/Chart' incorporates:
   *  SubSystem: '<S501>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

  /* SystemInitialize for Chart: '<S339>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S447>/Pri4Func.Turn'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_p);

  /* SystemInitialize for Chart: '<S339>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S447>/Pri4Func.Turn1'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_j);

  /* SystemInitialize for Chart: '<S339>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S447>/Pri4Func.Turn2'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y);

  /* SystemInitialize for Chart: '<S448>/TurnIndcrDig' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_b);

  /* SystemInitialize for Chart: '<S448>/TurnIndcrDig1' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_l);

  /* SystemInitialize for Chart: '<S448>/TurnIndcrDig2' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg_h);

  /* SystemInitialize for Chart: '<S448>/TurnIndcrDig3' */
  AppSwcBcm_TurnIndcrDig_Init(&AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* SystemInitialize for Chart: '<S453>/Chart' incorporates:
   *  SubSystem: '<S536>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_c);

  /* SystemInitialize for Chart: '<S453>/Chart' incorporates:
   *  SubSystem: '<S536>/Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S453>/Chart' incorporates:
   *  SubSystem: '<S536>/Lib_RiseEdgeDetInit2'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_d_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);
}

/* Output and update for atomic system: '<S233>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl(void)
{
  sint32 tmp;
  uint8 rtb_RelationalOperator_fr_tmp;
  boolean RelationalOperator4_b;
  boolean RelationalOperator6_f;
  boolean RelationalOperator8_p;
  boolean RelationalOperator_jr;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_LogicalOperator1_hp;
  boolean rtb_LogicalOperator4_l;
  boolean rtb_LogicalOperator6_le;
  boolean rtb_LogicalOperator8_p;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator14_d;
  boolean rtb_RelationalOperator16_c;
  boolean rtb_RelationalOperator19;
  boolean rtb_RelationalOperator1_ma;
  boolean rtb_RelationalOperator23;
  boolean rtb_RelationalOperator3_i0;
  boolean rtb_RelationalOperator6_o1;
  boolean rtb_RelationalOperator7_iu;
  boolean rtb_RelationalOperator9_m;
  boolean rtb_UnitDelay17;
  boolean tmp_0;

  /* RelationalOperator: '<S444>/Relational Operator6' incorporates:
   *  Constant: '<S440>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S440>/Relational Operator'
   */
  rtb_RelationalOperator6_o1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* UnitDelay: '<S339>/Unit Delay17' incorporates:
   *  Inport: '<Root>/IPM_EHB_B_CHA'
   *  RelationalOperator: '<S440>/Relational Operator1'
   */
  rtb_UnitDelay17 = (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA())
    ->VIPM_EHBReqBrkLiOn_flg;

  /* Logic: '<S440>/Logical Operator' */
  LampCtl_EmerSta = (rtb_UnitDelay17 && rtb_RelationalOperator6_o1);

  /* RelationalOperator: '<S443>/Relational Operator4' */
  RelationalOperator4_b = LampCtl_EmerSta;

  /* Chart: '<S339>/TurnIndcrLogic' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S339>/Unit Delay2'
   *  UnitDelay: '<S339>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c100_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c100_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
    LampCtl_TurnIndcrMod = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib) {
     case AppSwcBcm_IN_OFF_c:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_gv = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S450>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_gv,
          &AppSwcBcm_ARID_DEF.LogicalOperator_gy,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p);

        /* End of Outputs for SubSystem: '<S450>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_gy || LampCtl_TurnIndcrRSw) {
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
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnL == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrLSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 4U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_a5 = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S450>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_a5,
          &AppSwcBcm_ARID_DEF.LogicalOperator_dr,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

        /* End of Outputs for SubSystem: '<S450>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_dr) {
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
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnR == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_OFF_c;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrRSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_gv = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S450>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_gv,
          &AppSwcBcm_ARID_DEF.LogicalOperator_gy,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p);

        /* End of Outputs for SubSystem: '<S450>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_gy) {
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
        AppSwcBcm_ARID_DEF.Lib_blIn_a5 = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S450>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_a5,
          &AppSwcBcm_ARID_DEF.LogicalOperator_dr,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

        /* End of Outputs for SubSystem: '<S450>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_dr || LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_c100_LampCtl_Lib = AppSwcBcm_IN_TurnL;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 2U;
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_ShortFlash;
        }
      }
    }
  }

  /* End of Chart: '<S339>/TurnIndcrLogic' */

  /* Chart: '<S339>/HazardLightLogic' incorporates:
   *  UnitDelay: '<S339>/Unit Delay4'
   *  UnitDelay: '<S339>/Unit Delay5'
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
      if (((!AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p) &&
           (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g)) || AppSwcBcm_HazardOff())
      {
        /* {Lib_RiseEdgeDet(LampCtl_HazardLightSw)} */
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_OFF;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
      }
      break;

     case AppSwcBcm_IN_OFF:
      AppSwcBcm_ARID_DEF.Lib_blIn_k = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g;

      /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_k,
        &AppSwcBcm_ARID_DEF.LogicalOperator_lw,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);

      /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_lw) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_ed = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p;

        /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ed,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h2,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_o);

        /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h2) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_ld = LampCtl_HazardLightSw;

          /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ld,
            &AppSwcBcm_ARID_DEF.LogicalOperator_mk,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o2);

          /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_mk) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_ix =
              (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

            /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet3' */
            AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ix,
              &AppSwcBcm_ARID_DEF.LogicalOperator_om,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_i);

            /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet3' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_om ||
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
        AppSwcBcm_ARID_DEF.Lib_blIn_ix =
          (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ix,
          &AppSwcBcm_ARID_DEF.LogicalOperator_om,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_i);

        /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c43_LampCtl_Lib = AppSwcBcm_IN_EmerON;
        LampCtl_EmerHazardLightSta = true;
        LampCtl_HazardLightSta = false;
      } else if (AppSwcBcm_HazardOff() || AppSwcBcm_TurnOff()) {
        AppSwcBcm_ARID_DEF.Lib_blIn_ix =
          (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S441>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ix,
          &AppSwcBcm_ARID_DEF.LogicalOperator_om,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_i);

        /* End of Outputs for SubSystem: '<S441>/Lib_RiseEdgeDet3' */
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

  /* End of Chart: '<S339>/HazardLightLogic' */

  /* RelationalOperator: '<S443>/Relational Operator' */
  RelationalOperator_jr = LampCtl_EmerHazardLightSta;

  /* Logic: '<S443>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S443>/Relational Operator'
   *  RelationalOperator: '<S443>/Relational Operator4'
   */
  rtb_LogicalOperator8_p = (LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* Chart: '<S435>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c37_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c37_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_AlrmSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_psj =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S455>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_psj,
      &AppSwcBcm_ARID_DEF.LogicalOperator_an,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_co);

    /* End of Outputs for SubSystem: '<S455>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_an && (!rtb_LogicalOperator8_p)) {
      AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
      LampCtl_AlrmSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 2) ||
             rtb_LogicalOperator8_p) {
    AppSwcBcm_ARID_DEF.is_c37_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_AlrmSta = false;
  }

  /* End of Chart: '<S435>/Chart' */

  /* RelationalOperator: '<S443>/Relational Operator6' */
  RelationalOperator6_f = LampCtl_AlrmSta;

  /* Chart: '<S339>/TurnIndcrSelect' */
  if (AppSwcBcm_ARID_DEF.is_active_c118_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c118_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_g;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib) {
     case AppSwcBcm_IN_Off_g:
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
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_g;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 3U;
      }
      break;

     case AppSwcBcm_IN_TurnLROn:
      if (!LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_g;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 1U;
      }
      break;

     default:
      /* case IN_TurnROn: */
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c118_LampCtl_Lib = AppSwcBcm_IN_Off_g;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S339>/TurnIndcrSelect' */

  /* RelationalOperator: '<S443>/Relational Operator9' incorporates:
   *  Constant: '<S443>/Constant9'
   */
  rtb_RelationalOperator9_m = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 0);

  /* RelationalOperator: '<S443>/Relational Operator8' incorporates:
   *  Constant: '<S443>/Constant8'
   */
  RelationalOperator8_p = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide != 0);

  /* Logic: '<S443>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S443>/Relational Operator'
   *  RelationalOperator: '<S443>/Relational Operator4'
   *  RelationalOperator: '<S443>/Relational Operator6'
   */
  rtb_LogicalOperator1_hp = (RelationalOperator8_p || LampCtl_AlrmSta ||
    LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* RelationalOperator: '<S454>/Relational Operator' incorporates:
   *  Constant: '<S454>/Constant'
   */
  rtb_RelationalOperator = (LampCtl_RKEReq == 4);

  /* Chart: '<S454>/Chart' incorporates:
   *  UnitDelay: '<S339>/Unit Delay'
   *  UnitDelay: '<S339>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c123_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c123_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_VehSeekSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    if (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_ma = rtb_RelationalOperator;

      /* Outputs for Function Call SubSystem: '<S543>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ma,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ip,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);

      /* End of Outputs for SubSystem: '<S543>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ip && (!rtb_LogicalOperator1_hp)) {
        AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
        LampCtl_VehSeekSta = true;
      }
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e >= 10) ||
             (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE >= 10) ||
             (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) ||
             rtb_LogicalOperator1_hp) {
    AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_VehSeekSta = false;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_ma = rtb_RelationalOperator;

    /* Outputs for Function Call SubSystem: '<S543>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ma,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ip,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);

    /* End of Outputs for SubSystem: '<S543>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ip) {
      AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
        !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
      AppSwcBcm_ARID_DEF.is_c123_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
      LampCtl_VehSeekSta = true;
    }
  }

  /* End of Chart: '<S454>/Chart' */

  /* Chart: '<S436>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S339>/Unit Delay10'
   *  UnitDelay: '<S339>/Unit Delay11'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c38_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c38_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_Off_g;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib == AppSwcBcm_IN_Off_g) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck ||
         (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck) &&
        (!rtb_LogicalOperator1_hp)) {
      AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_On_km;
      LampCtl_AntiLckSta = true;
    }

    /* case IN_On: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE >= 3) ||
             rtb_LogicalOperator1_hp || LampCtl_VehSeekSta) {
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_Off_g;
    LampCtl_AntiLckSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck ||
             (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck) {
    AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;
    AppSwcBcm_ARID_DEF.is_c38_LampCtl_Lib = AppSwcBcm_IN_On_km;
    LampCtl_AntiLckSta = true;
  }

  /* End of Chart: '<S436>/Chart' */

  /* Chart: '<S437>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1 < 63U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c40_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c40_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_eq =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S459>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_eq,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fp,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_g);

    /* End of Outputs for SubSystem: '<S459>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_fp ||
         (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2) &&
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1))) &&
        (!rtb_LogicalOperator1_hp)) {
      AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
      AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
      LampCtl_ArmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.temporalCounter_i1 >= 50U) ||
             (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 1) ||
             LampCtl_VehSeekSta || rtb_LogicalOperator1_hp) {
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_ArmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2)
  {
    AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt = !AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;
    AppSwcBcm_ARID_DEF.is_c40_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
    AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
    LampCtl_ArmedSta = true;
  }

  /* End of Chart: '<S437>/Chart' */

  /* Chart: '<S439>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S339>/Unit Delay8'
   *  UnitDelay: '<S339>/Unit Delay9'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c42_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c42_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_na =
      (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 0);

    /* Outputs for Function Call SubSystem: '<S473>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_na,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jy,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_i);

    /* End of Outputs for SubSystem: '<S473>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_jy ||
         ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 0) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 1)))
        && (!rtb_LogicalOperator1_hp)) {
      AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
      LampCtl_DisarmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 0) ||
             LampCtl_VehSeekSta || rtb_LogicalOperator1_hp) {
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_DisarmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 1)
  {
    AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;
    AppSwcBcm_ARID_DEF.is_c42_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
    LampCtl_DisarmedSta = true;
  }

  /* End of Chart: '<S439>/Chart' */

  /* Chart: '<S442>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_PartArmedSta = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib) {
     case AppSwcBcm_IN_SetOff_o:
      LampCtl_PartArmedSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_In_d = AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
      AppSwcBcm_ARID_DEF.Lib_InNow_l = 3.0F;
      AppSwcBcm_ARID_DEF.Lib_InBefore_h = 1.0F;

      /* Outputs for Function Call SubSystem: '<S488>/Lib_ChangeEdge2' */
      AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_d,
        AppSwcBcm_ARID_DEF.Lib_InNow_l, AppSwcBcm_ARID_DEF.Lib_InBefore_h,
        &AppSwcBcm_ARID_DEF.LogicalOperator_bp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge2);

      /* End of Outputs for SubSystem: '<S488>/Lib_ChangeEdge2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_bp) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOn2;
        LampCtl_PartArmedSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_In_i =
          AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
        AppSwcBcm_ARID_DEF.Lib_InNow = 3.0F;
        AppSwcBcm_ARID_DEF.Lib_InBefore = 0.0F;

        /* Outputs for Function Call SubSystem: '<S488>/Lib_ChangeEdge' */
        AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_i,
          AppSwcBcm_ARID_DEF.Lib_InNow, AppSwcBcm_ARID_DEF.Lib_InBefore,
          &AppSwcBcm_ARID_DEF.LogicalOperator_f,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge);

        /* End of Outputs for SubSystem: '<S488>/Lib_ChangeEdge' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_f) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_In_a =
            AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
          AppSwcBcm_ARID_DEF.Lib_InNow_h = 3.0F;
          AppSwcBcm_ARID_DEF.Lib_InBefore_p = 2.0F;

          /* Outputs for Function Call SubSystem: '<S488>/Lib_ChangeEdge1' */
          AppSwcBcm_Lib_ChangeEdge(AppSwcBcm_ARID_DEF.Lib_In_a,
            AppSwcBcm_ARID_DEF.Lib_InNow_h, AppSwcBcm_ARID_DEF.Lib_InBefore_p,
            &AppSwcBcm_ARID_DEF.LogicalOperator_i0,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChangeEdge1);

          /* End of Outputs for SubSystem: '<S488>/Lib_ChangeEdge1' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_i0 ||
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
          LampCtl_VehSeekSta || rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
        LampCtl_PartArmedSta = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta ==
                 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;

     default:
      /* case IN_SetOn2: */
      LampCtl_PartArmedSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) ||
          LampCtl_VehSeekSta || rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
        LampCtl_PartArmedSta = 0U;
      } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta ==
                 2) {
        AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
          !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
      break;
    }

    if (guard1) {
      if (!rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c14_LampCtl_Lib = AppSwcBcm_IN_SetOn1;
        LampCtl_PartArmedSta = 1U;
      }
    }
  }

  /* End of Chart: '<S442>/Chart' */

  /* RelationalOperator: '<S443>/Relational Operator5' */
  rtb_RelationalOperator = !LampCtl_EmerSta;

  /* RelationalOperator: '<S443>/Relational Operator7' */
  rtb_RelationalOperator7_iu = !LampCtl_AlrmSta;

  /* UnitDelay: '<S339>/Unit Delay17' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   *  RelationalOperator: '<S444>/Relational Operator1'
   */
  rtb_UnitDelay17 =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwStVld_flg;

  /* RelationalOperator: '<S444>/Relational Operator6' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator6_o1 =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwStVld_flg;

  /* Logic: '<S444>/Logical Operator2' */
  rtb_RelationalOperator6_o1 = (rtb_UnitDelay17 || rtb_RelationalOperator6_o1);

  /* UnitDelay: '<S339>/Unit Delay17' incorporates:
   *  Constant: '<S444>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S444>/Relational Operator'
   */
  rtb_UnitDelay17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
                     ->SysPwrMode == 2);

  /* RelationalOperator: '<S444>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S443>/Relational Operator12'
   */
  rtb_LogicalOperator6_le = !LampCtl_ArmedSta;

  /* RelationalOperator: '<S444>/Relational Operator5' incorporates:
   *  RelationalOperator: '<S443>/Relational Operator13'
   */
  rtb_RelationalOperator3_i0 = !LampCtl_VehSeekSta;

  /* RelationalOperator: '<S444>/Relational Operator2' incorporates:
   *  RelationalOperator: '<S443>/Relational Operator15'
   */
  rtb_LogicalOperator4_l = !LampCtl_DisarmedSta;

  /* RelationalOperator: '<S444>/Relational Operator7' incorporates:
   *  RelationalOperator: '<S443>/Relational Operator17'
   */
  tmp_0 = !LampCtl_AntiLckSta;

  /* Chart: '<S444>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S444>/Constant2'
   *  Constant: '<S444>/Constant21'
   *  Constant: '<S444>/Constant3'
   *  Constant: '<S444>/Constant5'
   *  Logic: '<S444>/Logical Operator'
   *  Logic: '<S444>/Logical Operator1'
   *  RelationalOperator: '<S444>/Relational Operator2'
   *  RelationalOperator: '<S444>/Relational Operator3'
   *  RelationalOperator: '<S444>/Relational Operator4'
   *  RelationalOperator: '<S444>/Relational Operator5'
   *  RelationalOperator: '<S444>/Relational Operator7'
   */
  if (tmp_0 && rtb_LogicalOperator4_l && (LampCtl_PartArmedSta == 0) &&
      rtb_LogicalOperator6_le && rtb_RelationalOperator3_i0 &&
      rtb_RelationalOperator6_o1 && rtb_UnitDelay17) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_fgy >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_RodBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fgy++;
      AppSwcBcm_ARID_DEF.cnt_heal_kk = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fgy = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_kk == 0) {
      LampCtl_RodBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_kk--;
    }
  }

  /* End of Chart: '<S444>/LIB_TPD_10ms' */

  /* Chart: '<S453>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c119_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c119_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
    LampCtl_VehModeSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib) {
     case AppSwcBcm_IN_Init_f:
      LampCtl_VehModeSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_go =
        (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum == 1);

      /* Outputs for Function Call SubSystem: '<S536>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_go,
        &AppSwcBcm_ARID_DEF.LogicalOperator_oe,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_c);

      /* End of Outputs for SubSystem: '<S536>/Lib_RiseEdgeDetInit' */
      rtb_UnitDelay17 = !rtb_LogicalOperator1_hp;
      if (AppSwcBcm_ARID_DEF.LogicalOperator_oe && rtb_UnitDelay17) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Show;
        LampCtl_VehModeSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_i5 =
          (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum == 2);

        /* Outputs for Function Call SubSystem: '<S536>/Lib_RiseEdgeDetInit1' */
        AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_i5,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ch,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

        /* End of Outputs for SubSystem: '<S536>/Lib_RiseEdgeDetInit1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ch && rtb_UnitDelay17) {
          AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Limit;
          LampCtl_VehModeSta = 3U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_f =
            (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum ==
             0);

          /* Outputs for Function Call SubSystem: '<S536>/Lib_RiseEdgeDetInit2' */
          AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_f,
            &AppSwcBcm_ARID_DEF.LogicalOperator_c4,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);

          /* End of Outputs for SubSystem: '<S536>/Lib_RiseEdgeDetInit2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_c4 && rtb_UnitDelay17) {
            AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Nrm;
            LampCtl_VehModeSta = 1U;
          }
        }
      }
      break;

     case AppSwcBcm_IN_Limit:
      LampCtl_VehModeSta = 3U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 3) ||
          rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
        LampCtl_VehModeSta = 0U;
      }
      break;

     case AppSwcBcm_IN_Nrm:
      LampCtl_VehModeSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 1) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 1) ||
          rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
        LampCtl_VehModeSta = 0U;
      }
      break;

     default:
      /* case IN_Show: */
      LampCtl_VehModeSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 2) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 2) ||
          rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c119_LampCtl_Lib = AppSwcBcm_IN_Init_f;
        LampCtl_VehModeSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S453>/Chart' */

  /* Chart: '<S446>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S339>/Unit Delay14'
   *  UnitDelay: '<S339>/Unit Delay15'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c47_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c47_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_i;
    LampCtl_TrunkWarnSta = false;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib) {
     case AppSwcBcm_IN_Delay_b:
      if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts != 3) ||
          LampCtl_VehSeekSta || rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_i;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      } else if ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 3) &&
                 (AppSwcBcm_ARID_DEF.TrunkWarnCnt >= LampCtl_TrunkWarnTim_C)) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOn_a;
        LampCtl_TrunkWarnSta = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff_i:
      AppSwcBcm_ARID_DEF.Lib_blIn_fd =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S501>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_a(AppSwcBcm_ARID_DEF.Lib_blIn_fd,
        &AppSwcBcm_ARID_DEF.LogicalOperator_il,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_e);

      /* End of Outputs for SubSystem: '<S501>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_il && (!rtb_LogicalOperator1_hp) &&
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
          LampCtl_VehSeekSta || rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_c47_LampCtl_Lib = AppSwcBcm_IN_SetOff_i;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S446>/Chart' */

  /* RelationalOperator: '<S443>/Relational Operator10' */
  rtb_UnitDelay17 = LampCtl_ArmedSta;

  /* RelationalOperator: '<S443>/Relational Operator11' */
  rtb_RelationalOperator6_o1 = LampCtl_VehSeekSta;

  /* RelationalOperator: '<S443>/Relational Operator14' */
  rtb_RelationalOperator14_d = LampCtl_DisarmedSta;

  /* RelationalOperator: '<S443>/Relational Operator16' incorporates:
   *  Constant: '<S443>/Constant16'
   */
  rtb_RelationalOperator16_c = (LampCtl_PartArmedSta == 1);

  /* RelationalOperator: '<S443>/Relational Operator1' */
  rtb_RelationalOperator1_ma = LampCtl_RodBeamFaultSta;

  /* RelationalOperator: '<S443>/Relational Operator19' */
  rtb_RelationalOperator19 = LampCtl_AntiLckSta;

  /* Logic: '<S443>/Logical Operator9' incorporates:
   *  Constant: '<S443>/Constant20'
   *  Constant: '<S443>/Constant21'
   *  Constant: '<S443>/Constant23'
   *  RelationalOperator: '<S443>/Relational Operator20'
   *  RelationalOperator: '<S443>/Relational Operator22'
   *  RelationalOperator: '<S443>/Relational Operator3'
   */
  rtb_LogicalOperator9 = ((LampCtl_VehModeSta == 1) || (LampCtl_VehModeSta == 2)
    || (LampCtl_VehModeSta == 3));

  /* RelationalOperator: '<S443>/Relational Operator23' */
  rtb_RelationalOperator23 = LampCtl_TrunkWarnSta;

  /* Logic: '<S443>/Logical Operator6' incorporates:
   *  Constant: '<S443>/Constant17'
   *  Constant: '<S443>/Constant22'
   *  RelationalOperator: '<S443>/Relational Operator18'
   *  RelationalOperator: '<S443>/Relational Operator2'
   *  RelationalOperator: '<S443>/Relational Operator21'
   *  RelationalOperator: '<S443>/Relational Operator24'
   */
  rtb_LogicalOperator6_le = (rtb_LogicalOperator6_le &&
    rtb_RelationalOperator3_i0 && rtb_LogicalOperator4_l &&
    (LampCtl_PartArmedSta == 0) && (!LampCtl_RodBeamFaultSta) && tmp_0 &&
    (LampCtl_VehModeSta == 0) && (!LampCtl_TrunkWarnSta));

  /* RelationalOperator: '<S448>/Relational Operator' incorporates:
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S448>/Relational Operator5'
   */
  rtb_RelationalOperator_fr_tmp =
    Rte_IRead_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt();

  /* Logic: '<S448>/Logical Operator4' incorporates:
   *  UnitDelay: '<S339>/Unit Delay16'
   */
  rtb_LogicalOperator4_l = (LampCtl_TurnIndcrLaneLSw &&
    AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE);

  /* Outputs for Enabled SubSystem: '<S448>/Enabled Subsystem3' incorporates:
   *  EnablePort: '<S521>/Enable'
   */
  if (rtb_LogicalOperator4_l) {
    /* CCaller: '<S521>/C Caller' incorporates:
     *  Constant: '<S521>/Constant17'
     */
    LampCtl_TurnIndcrLVol = GetHw_TurnIndcrVol(0U);
  }

  /* End of Outputs for SubSystem: '<S448>/Enabled Subsystem3' */

  /* RelationalOperator: '<S448>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_i0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S448>/TurnIndcrDig3' incorporates:
   *  Constant: '<S448>/Constant17'
   *  Constant: '<S448>/Constant21'
   *  Constant: '<S448>/Constant43'
   *  Constant: '<S448>/Constant44'
   *  Constant: '<S448>/Constant45'
   *  RelationalOperator: '<S448>/Relational Operator1'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_l, LampCtl_TurnIndcrLVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_i0, LampCtl_Ts_C,
    LampCtl_TurnIndcrLOpenTimValid_C, LampCtl_TurnIndcrLOpenTimInValid_C,
    LampCtl_LOpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig3);

  /* Logic: '<S448>/Logical Operator' incorporates:
   *  Constant: '<S448>/Constant'
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S448>/Relational Operator'
   */
  LampCtl_TurnIndcrLOpen = ((rtb_RelationalOperator_fr_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg);

  /* Chart: '<S448>/TurnIndcrDig2' incorporates:
   *  Constant: '<S448>/Constant10'
   *  Constant: '<S448>/Constant18'
   *  Constant: '<S448>/Constant19'
   *  Constant: '<S448>/Constant4'
   *  Constant: '<S448>/Constant9'
   *  RelationalOperator: '<S448>/Relational Operator4'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_l, LampCtl_TurnIndcrLVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_i0, LampCtl_Ts_C,
    LampCtl_TurnIndcrLShortTimValid_C, LampCtl_TurnIndcrLShortTimInValid_C,
    LampCtl_LShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig2);

  /* Logic: '<S448>/Logical Operator2' incorporates:
   *  Constant: '<S448>/Constant7'
   *  RelationalOperator: '<S448>/Relational Operator5'
   */
  LampCtl_TurnIndcrLShort = ((rtb_RelationalOperator_fr_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_h);

  /* RelationalOperator: '<S448>/Relational Operator2' incorporates:
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S448>/Relational Operator6'
   */
  rtb_RelationalOperator_fr_tmp =
    Rte_IRead_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt();

  /* Logic: '<S448>/Logical Operator5' incorporates:
   *  UnitDelay: '<S339>/Unit Delay17'
   */
  rtb_LogicalOperator4_l = (LampCtl_TurnIndcrLaneRSw &&
    AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE);

  /* Outputs for Enabled SubSystem: '<S448>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S520>/Enable'
   */
  if (rtb_LogicalOperator4_l) {
    /* CCaller: '<S520>/C Caller' incorporates:
     *  Constant: '<S520>/Constant17'
     */
    LampCtl_TurnIndcrRVol = GetHw_TurnIndcrVol(1U);
  }

  /* End of Outputs for SubSystem: '<S448>/Enabled Subsystem1' */

  /* Chart: '<S448>/TurnIndcrDig' incorporates:
   *  Constant: '<S448>/Constant11'
   *  Constant: '<S448>/Constant2'
   *  Constant: '<S448>/Constant3'
   *  Constant: '<S448>/Constant6'
   *  Constant: '<S448>/Constant8'
   *  RelationalOperator: '<S448>/Relational Operator7'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_l, LampCtl_TurnIndcrRVol <=
    LampCtl_TurnIndcrOpenCur_C, rtb_RelationalOperator3_i0, LampCtl_Ts_C,
    LampCtl_TurnIndcrROpenTimValid_C, LampCtl_TurnIndcrROpenTimInValid_C,
    LampCtl_ROpenCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig);

  /* Logic: '<S448>/Logical Operator1' incorporates:
   *  Constant: '<S448>/Constant5'
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S448>/Relational Operator2'
   */
  LampCtl_TurnIndcrROpen = ((rtb_RelationalOperator_fr_tmp == 1) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_b);

  /* Chart: '<S448>/TurnIndcrDig1' incorporates:
   *  Constant: '<S448>/Constant12'
   *  Constant: '<S448>/Constant13'
   *  Constant: '<S448>/Constant14'
   *  Constant: '<S448>/Constant16'
   *  Constant: '<S448>/Constant20'
   *  RelationalOperator: '<S448>/Relational Operator8'
   */
  AppSwcBcm_TurnIndcrDig(rtb_LogicalOperator4_l, LampCtl_TurnIndcrRVol >=
    LampCtl_TurnIndcrShortCur_C, rtb_RelationalOperator3_i0, LampCtl_Ts_C,
    LampCtl_TurnIndcrRShortTimValid_C, LampCtl_TurnIndcrRShortTimInValid_C,
    LampCtl_RShortCnt_C, &AppSwcBcm_ARID_DEF.LIB_blErrFlg_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_TurnIndcrDig1);

  /* Logic: '<S448>/Logical Operator3' incorporates:
   *  Constant: '<S448>/Constant15'
   *  RelationalOperator: '<S448>/Relational Operator6'
   */
  LampCtl_TurnIndcrRShort = ((rtb_RelationalOperator_fr_tmp == 2) ||
    AppSwcBcm_ARID_DEF.LIB_blErrFlg_l);

  /* Chart: '<S339>/TurnIndcrArb2' incorporates:
   *  Logic: '<S443>/Logical Operator'
   *  Logic: '<S443>/Logical Operator2'
   *  Logic: '<S443>/Logical Operator3'
   *  Logic: '<S443>/Logical Operator4'
   *  Logic: '<S443>/Logical Operator5'
   *  Logic: '<S443>/Logical Operator7'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c75_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c75_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
    AppSwcBcm_EnFunc();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib) {
     case AppSwcBcm_IN_Pri1:
      if (!RelationalOperator_jr) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri2:
      if (rtb_RelationalOperator || RelationalOperator_jr) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri2Func();
      }
      break;

     case AppSwcBcm_IN_Pri3:
      if (rtb_RelationalOperator7_iu || rtb_LogicalOperator8_p) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri4:
      if (rtb_RelationalOperator9_m || RelationalOperator6_f ||
          RelationalOperator4_b || RelationalOperator_jr) {
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri4Func();
      }
      break;

     case AppSwcBcm_IN_Pri5:
      if (rtb_LogicalOperator6_le || rtb_LogicalOperator1_hp) {
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        switch (AppSwcBcm_ARID_DEF.is_Pri5) {
         case AppSwcBcm_IN_AntiLck:
          if (!LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_AntiLckFunc();
          }
          break;

         case AppSwcBcm_IN_Armed:
          if (!LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_ArmedFunc();
          }
          break;

         case AppSwcBcm_IN_Disarmed:
          if (!LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_DisarmedFunc();
          }
          break;

         case AppSwcBcm_IN_PartArmed:
          if (LampCtl_PartArmedSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_PartArmedFunc();
          }
          break;

         case AppSwcBcm_IN_RodBeam:
          if (!LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_RodBeamFunc();
          }
          break;

         case AppSwcBcm_IN_Seek:
          if (!LampCtl_VehSeekSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_SeekFunc();
          }
          break;

         case AppSwcBcm_IN_Trans_l:
          if (LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Armed;
          } else if (LampCtl_PartArmedSta != 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_PartArmed;
          } else if (LampCtl_VehSeekSta) {
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
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_TrunkWarnFunc();
          }
          break;

         default:
          /* case IN_VehMode: */
          if (LampCtl_VehModeSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
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
      if (RelationalOperator_jr) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri1;
      } else if (RelationalOperator4_b) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri2;
      } else if (RelationalOperator6_f) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri3;
      } else if (RelationalOperator8_p) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri4;
      } else if (rtb_UnitDelay17 || rtb_RelationalOperator6_o1 ||
                 rtb_RelationalOperator14_d || rtb_RelationalOperator16_c ||
                 rtb_RelationalOperator1_ma || rtb_RelationalOperator19 ||
                 rtb_LogicalOperator9 || rtb_RelationalOperator23) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c75_LampCtl_Lib = AppSwcBcm_IN_Pri5;
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_l;
        AppSwcBcm_TurnFunc();
      }
      break;
    }
  }

  /* End of Chart: '<S339>/TurnIndcrArb2' */
  AppSwcBcm_ARID_DEF.Lib_blIn_ps = LampCtl_TurnIndcrRst;

  /* Chart: '<S449>/LIB_Pulse' incorporates:
   *  SubSystem: '<S526>/Lib_BothEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S527>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ps,
    &AppSwcBcm_ARID_DEF.LogicalOperator2_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet_a);

  /* End of Outputs for SubSystem: '<S527>/Lib_BothEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator2_o) {
    AppSwcBcm_ARID_DEF.cnt_c = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  if (LampCtl_TurnIndcrLFlashCnt >= 1) {
    if (LampCtl_TurnIndcrLFlashCnt >= 65535) {
      LampCtl_PrdSucCntL = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_j = (AppSwcBcm_ARID_DEF.cnt_c <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_c >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_c = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_c + 1;
        if (AppSwcBcm_ARID_DEF.cnt_c + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_c = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntL < LampCtl_TurnIndcrLFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_j = (AppSwcBcm_ARID_DEF.cnt_c <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_c >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_c = 0U;
        tmp = LampCtl_PrdSucCntL + 1;
        if (LampCtl_PrdSucCntL + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntL = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_c + 1;
        if (AppSwcBcm_ARID_DEF.cnt_c + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_c = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_j = false;
    AppSwcBcm_ARID_DEF.cnt_c = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_f0 = LampCtl_TurnIndcrRst;

  /* Chart: '<S451>/LIB_Pulse' incorporates:
   *  SubSystem: '<S533>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_f0,
    &AppSwcBcm_ARID_DEF.RelationalOperator_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_n) {
    AppSwcBcm_ARID_DEF.cnt_i = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  if (LampCtl_TurnIndcrRFlashCnt >= 1) {
    if (LampCtl_TurnIndcrRFlashCnt >= 65535) {
      LampCtl_PrdSucCntR = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_m5 = (AppSwcBcm_ARID_DEF.cnt_i <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_i >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_i = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_i + 1;
        if (AppSwcBcm_ARID_DEF.cnt_i + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_i = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntR < LampCtl_TurnIndcrRFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_m5 = (AppSwcBcm_ARID_DEF.cnt_i <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_i >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_i = 0U;
        tmp = LampCtl_PrdSucCntR + 1;
        if (LampCtl_PrdSucCntR + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntR = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_i + 1;
        if (AppSwcBcm_ARID_DEF.cnt_i + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_i = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_m5 = false;
    AppSwcBcm_ARID_DEF.cnt_i = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  /* Chart: '<S438>/Chart' incorporates:
   *  Inport: '<Root>/IPM_SRS_1_Status_CHA'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c41_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c41_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
    LampCtl_CrashSta = false;
    AppSwcBcm_ARID_DEF.PwrOffFlg = false;
    AppSwcBcm_ARID_DEF.PwrOnFlg = false;
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib) {
     case AppSwcBcm_IN_CrashDelay:
      if (AppSwcBcm_ARID_DEF.Cnt_k >= 50) {
        AppSwcBcm_ARID_DEF.Lib_blIn_f3 =
          (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 1);

        /* Outputs for Function Call SubSystem: '<S462>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_f3,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ke,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

        /* End of Outputs for SubSystem: '<S462>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ke) {
          AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
          LampCtl_CrashSta = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 0) {
          AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashDelay;
          AppSwcBcm_ARID_DEF.Cnt_k = 0U;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case AppSwcBcm_IN_CrashOff:
      AppSwcBcm_ARID_DEF.Lib_blIn_hw =
        (((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 1) ||
         ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 2) ||
         ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 4) ||
         ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
           ())->VIPM_SRSCrashOutputSts_enum == 5));

      /* Outputs for Function Call SubSystem: '<S462>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_hw,
        &AppSwcBcm_ARID_DEF.LogicalOperator_kv,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_f);

      /* End of Outputs for SubSystem: '<S462>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_kv) {
        guard2 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_dk = (AppSwcBcm_ARID_DEF.CCaller15 == 1);

        /* Outputs for Function Call SubSystem: '<S462>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_dk,
          &AppSwcBcm_ARID_DEF.LogicalOperator_kb,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_i);

        /* End of Outputs for SubSystem: '<S462>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_kb) {
          guard2 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 1) {
          AppSwcBcm_ARID_DEF.is_c41_LampCtl_Lib = AppSwcBcm_IN_CrashDelay;
          AppSwcBcm_ARID_DEF.Cnt_k = 0U;
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
      } else {
        tmp = AppSwcBcm_ARID_DEF.Cnt_k + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_k + 1 > 255) {
          tmp = 255;
        }

        AppSwcBcm_ARID_DEF.Cnt_k = (uint8)tmp;
      }
    }
  }

  /* End of Chart: '<S438>/Chart' */

  /* Chart: '<S445>/Chart' incorporates:
   *  Inport: '<Root>/IPM_BMS_1_MainState_EPT'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c46_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c46_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_ThermalrunawaySta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ep =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
        ())->VIPM_BMSThermrunawayWrn_enum == 1);

    /* Outputs for Function Call SubSystem: '<S496>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ep,
      &AppSwcBcm_ARID_DEF.LogicalOperator_cui,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_a);

    /* End of Outputs for SubSystem: '<S496>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_cui) {
      AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOn_d;
    }
  } else {
    /* case IN_SetOn: */
    guard1 = false;
    if ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
         ())->VIPM_BMSThermrunawayWrn_enum == 0) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_hz = LampCtl_HazardLightSw;

      /* Outputs for Function Call SubSystem: '<S496>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_hz,
        &AppSwcBcm_ARID_DEF.LogicalOperator_e,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_ax);

      /* End of Outputs for SubSystem: '<S496>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_e) {
        guard1 = true;
      } else {
        LampCtl_ThermalrunawaySta = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c46_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
      LampCtl_ThermalrunawaySta = false;
    }
  }

  /* End of Chart: '<S445>/Chart' */

  /* Update for UnitDelay: '<S339>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g = LampCtl_CrashSta;

  /* Update for UnitDelay: '<S339>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_p = LampCtl_ThermalrunawaySta;

  /* Update for UnitDelay: '<S339>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay11' */
  AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay10' */
  AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay13' */
  AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay12' */
  AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay15' */
  AppSwcBcm_ARID_DEF.UnitDelay15_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S339>/Unit Delay14' */
  AppSwcBcm_ARID_DEF.UnitDelay14_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S339>/Unit Delay16' */
  AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE = AppSwcBcm_ARID_DEF.LIB_blOut_j;

  /* Update for UnitDelay: '<S339>/Unit Delay17' */
  AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE = AppSwcBcm_ARID_DEF.LIB_blOut_m5;
}

/*
 * System initialize for atomic system:
 *    '<S557>/Lib_RiseEdgeDetInit'
 *    '<S563>/Lib_RiseEdgeDetInit'
 *    '<S637>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_c_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S558>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S557>/Lib_RiseEdgeDetInit'
 *    '<S563>/Lib_RiseEdgeDetInit'
 *    '<S637>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_d(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_c_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S558>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S558>/Logical Operator' incorporates:
   *  Delay: '<S558>/Delay'
   *  Logic: '<S558>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S558>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S547>/LIB_PosPluseInit'
 *    '<S552>/LIB_PosPluseInit'
 */
static void AppSwcBcm_LIB_PosPluseInit_Init(boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluseInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  *rty_LIB_blOut = false;

  /* SystemInitialize for Function Call SubSystem: '<S555>/Lib_RiseEdgeDet' */
  /* SystemInitialize for Atomic SubSystem: '<S557>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S557>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S555>/Lib_RiseEdgeDet' */
}

/*
 * Output and update for atomic system:
 *    '<S547>/LIB_PosPluseInit'
 *    '<S552>/LIB_PosPluseInit'
 */
static void AppSwcBcm_LIB_PosPluseInit(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluseInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S547>/LIB_PosPluseInit' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blEn;
  AppSwcBcm__ARID_DEF_arg->Lib_blInit = rtu_LIB_blEn;

  /* Outputs for Function Call SubSystem: '<S555>/Lib_RiseEdgeDet' */
  /* Outputs for Atomic SubSystem: '<S557>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_d(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    AppSwcBcm__ARID_DEF_arg->Lib_blInit,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S557>/Lib_RiseEdgeDetInit' */
  /* End of Outputs for SubSystem: '<S555>/Lib_RiseEdgeDet' */

  /* Chart: '<S547>/LIB_PosPluseInit' */
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator) {
    AppSwcBcm__ARID_DEF_arg->Flg = true;
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }

  if (rtu_LIB_blRst) {
    AppSwcBcm__ARID_DEF_arg->Flg = false;
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }

  if (AppSwcBcm__ARID_DEF_arg->Flg) {
    if (AppSwcBcm__ARID_DEF_arg->Cnt >= rtu_LIB_u16Limit) {
      *rty_LIB_blOut = true;
      AppSwcBcm__ARID_DEF_arg->Flg = false;
    } else {
      AppSwcBcm__ARID_DEF_arg->Cnt++;
      *rty_LIB_blOut = false;
    }
  } else {
    *rty_LIB_blOut = false;
    AppSwcBcm__ARID_DEF_arg->Cnt = 0U;
  }
}

/* Output and update for atomic system: '<S547>/Lib_RiseEdgeDet' */
static void AppSwcBcm_Lib_RiseEdgeDet_ou(void)
{
  /* Logic: '<S556>/Logical Operator' incorporates:
   *  Logic: '<S556>/Logical Operator1'
   *  UnitDelay: '<S556>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_k = (AppSwcBcm_ARID_DEF.LIB_blOut_mn &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kd));

  /* Update for UnitDelay: '<S556>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kd = AppSwcBcm_ARID_DEF.LIB_blOut_mn;
}

/* Output and update for atomic system: '<S551>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge_d(void)
{
  /* Logic: '<S560>/Logical Operator' incorporates:
   *  Constant: '<S551>/Constant3'
   *  Constant: '<S551>/Constant4'
   *  RelationalOperator: '<S560>/Relational Operator'
   *  RelationalOperator: '<S560>/Relational Operator1'
   *  UnitDelay: '<S560>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4_g =
    ((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) &&
     (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dy == 0));

  /* Update for UnitDelay: '<S560>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dy =
    AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts;
}

/* System initialize for atomic system: '<S233>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ao;
  boolean rtb_LIB_blOut_i;

  /* InitializeConditions for UnitDelay: '<S340>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = 60U;

  /* InitializeConditions for Delay: '<S548>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_np = true;

  /* SystemInitialize for Chart: '<S547>/LIB_PosPluseInit' */
  AppSwcBcm_LIB_PosPluseInit_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_mn,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit_h);

  /* SystemInitialize for Chart: '<S551>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_i);

  /* SystemInitialize for Chart: '<S552>/LIB_PosPluseInit' */
  AppSwcBcm_LIB_PosPluseInit_Init(&rtb_LIB_blOut_ao,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit);

  /* SystemInitialize for Chart: '<S552>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_e);
}

/* Output and update for atomic system: '<S233>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ao;
  boolean rtb_LIB_blOut_i;
  sint32 tmp;
  uint8 tmp_0;
  boolean rtb_LIB_blOut_bz;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator2_be;
  boolean rtb_RelationalOperator1_d1;

  /* Logic: '<S552>/Logical Operator2' incorporates:
   *  Constant: '<S546>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S546>/Relational Operator'
   */
  rtb_LogicalOperator2_be = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S552>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S546>/Relational Operator3'
   */
  rtb_RelationalOperator1_d1 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->OsLck;

  /* Chart: '<S546>/LIB_Tim' incorporates:
   *  Constant: '<S546>/Constant5'
   *  Logic: '<S546>/Logical Operator1'
   *  Logic: '<S546>/Logical Operator2'
   *  Product: '<S546>/Product'
   *  UnitDelay: '<S340>/Unit Delay1'
   *  UnitDelay: '<S340>/Unit Delay2'
   */
  if ((!rtb_RelationalOperator1_d1) && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ih)
  {
    if (AppSwcBcm_ARID_DEF.Cnt_mi <= (uint16)(50U *
         AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE)) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_mi + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_mi + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_mi = (uint16)tmp;
      rtb_LIB_blOut_bz = false;
    } else {
      rtb_LIB_blOut_bz = true;
    }
  } else {
    rtb_LIB_blOut_bz = false;
    AppSwcBcm_ARID_DEF.Cnt_mi = 0U;
  }

  /* End of Chart: '<S546>/LIB_Tim' */

  /* Outputs for Atomic SubSystem: '<S546>/Lib_RiseEdgeDet3' */
  /* RelationalOperator: '<S546>/Relational Operator1' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(LampCtl_VehSeekSta,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3);

  /* End of Outputs for SubSystem: '<S546>/Lib_RiseEdgeDet3' */

  /* RelationalOperator: '<S552>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S546>/Relational Operator2'
   */
  rtb_RelationalOperator1_d1 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->OsUnlck;

  /* Logic: '<S546>/Logical Operator' */
  rtb_LogicalOperator2_be = (rtb_LIB_blOut_bz || rtb_LogicalOperator2_be ||
    rtb_RelationalOperator1_d1 || rtb_LogicalOperator);

  /* RelationalOperator: '<S552>/Relational Operator1' incorporates:
   *  Constant: '<S548>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S548>/Relational Operator'
   */
  rtb_RelationalOperator1_d1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Delay: '<S548>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_np) {
    /* Switch: '<S548>/Switch1' incorporates:
     *  Constant: '<S548>/Constant12'
     *  Constant: '<S548>/Constant13'
     *  RelationalOperator: '<S548>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_e = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_e =
        AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb;
    }

    /* End of Switch: '<S548>/Switch1' */
  }

  /* Switch: '<S548>/Switch' incorporates:
   *  Constant: '<S548>/Constant11'
   */
  if (rtb_RelationalOperator1_d1) {
    tmp_0 = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUFlwrMeHmCtrl_enum;
  } else {
    tmp_0 = 0U;
  }

  /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
   *  Switch: '<S548>/Switch'
   */
  switch (tmp_0) {
   case 1:
    /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
     *  Constant: '<S548>/Constant6'
     */
    LampCtl_FlwrMeHomeCtlFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
     *  Constant: '<S548>/Constant7'
     */
    LampCtl_FlwrMeHomeCtlFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
     *  Constant: '<S548>/Constant8'
     */
    LampCtl_FlwrMeHomeCtlFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
     *  Constant: '<S548>/Constant9'
     */
    LampCtl_FlwrMeHomeCtlFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
     *  Constant: '<S548>/Constant10'
     */
    LampCtl_FlwrMeHomeCtlFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S548>/Multiport Switch1' incorporates:
     *  Delay: '<S548>/Delay'
     */
    LampCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_e;
    break;
  }

  /* End of MultiPortSwitch: '<S548>/Multiport Switch1' */

  /* Logic: '<S547>/Logical Operator2' incorporates:
   *  Constant: '<S547>/Constant1'
   *  Constant: '<S547>/Constant3'
   *  Constant: '<S547>/Constant4'
   *  RelationalOperator: '<S547>/Relational Operator1'
   *  RelationalOperator: '<S547>/Relational Operator3'
   *  RelationalOperator: '<S547>/Relational Operator4'
   */
  rtb_RelationalOperator1_d1 = ((LampCtl_FlwrMeHomeCtlFb != 0) &&
    (LampCtl_LightIntstSta == 2) && (AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts
    == 1));

  /* Chart: '<S547>/LIB_PosPluseInit' incorporates:
   *  Constant: '<S547>/Constant43'
   *  Logic: '<S547>/Logical Operator'
   */
  AppSwcBcm_LIB_PosPluseInit(rtb_RelationalOperator1_d1,
    LampCtl_FlwrMeHomeTimValid_C, !rtb_RelationalOperator1_d1,
    &AppSwcBcm_ARID_DEF.LIB_blOut_mn,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit_h);

  /* Outputs for Atomic SubSystem: '<S547>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_ou();

  /* End of Outputs for SubSystem: '<S547>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S340>/Lib_SR1' */
  /* Switch: '<S550>/Switch' */
  if (rtb_LogicalOperator2_be) {
    /* Switch: '<S550>/Switch' incorporates:
     *  Constant: '<S550>/Constant'
     */
    LampCtl_FlwrMeHomeSta = false;
  } else {
    /* Switch: '<S550>/Switch' incorporates:
     *  Logic: '<S550>/Logical Operator'
     *  UnitDelay: '<S550>/Unit Delay'
     */
    LampCtl_FlwrMeHomeSta = (AppSwcBcm_ARID_DEF.LogicalOperator_k ||
      LampCtl_FlwrMeHomeSta);
  }

  /* End of Switch: '<S550>/Switch' */
  /* End of Outputs for SubSystem: '<S340>/Lib_SR1' */

  /* MultiPortSwitch: '<S548>/Multiport Switch' */
  switch (LampCtl_FlwrMeHomeCtlFb) {
   case 0:
    /* MultiPortSwitch: '<S548>/Multiport Switch' incorporates:
     *  Constant: '<S548>/Constant4'
     */
    LampCtl_FlwrMeHomeTim = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S548>/Multiport Switch' incorporates:
     *  Constant: '<S548>/Constant'
     */
    LampCtl_FlwrMeHomeTim = 30U;
    break;

   case 2:
    /* MultiPortSwitch: '<S548>/Multiport Switch' incorporates:
     *  Constant: '<S548>/Constant1'
     */
    LampCtl_FlwrMeHomeTim = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S548>/Multiport Switch' incorporates:
     *  Constant: '<S548>/Constant2'
     */
    LampCtl_FlwrMeHomeTim = 90U;
    break;

   case 4:
    /* MultiPortSwitch: '<S548>/Multiport Switch' incorporates:
     *  Constant: '<S548>/Constant3'
     */
    LampCtl_FlwrMeHomeTim = 120U;
    break;
  }

  /* End of MultiPortSwitch: '<S548>/Multiport Switch' */

  /* RelationalOperator: '<S552>/Relational Operator1' incorporates:
   *  Constant: '<S551>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S551>/Relational Operator1'
   */
  rtb_RelationalOperator1_d1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S552>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S551>/Relational Operator2'
   */
  rtb_LogicalOperator2_be = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->OsUnlck;

  /* Chart: '<S551>/LIB_Tim' incorporates:
   *  Constant: '<S551>/Constant6'
   *  Logic: '<S551>/Logical Operator1'
   *  Logic: '<S551>/Logical Operator2'
   *  UnitDelay: '<S340>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse((!rtb_LogicalOperator2_be) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fq, LampCtl_WelcomeLampTimMax_C,
    &rtb_LIB_blOut_i, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_j);

  /* Outputs for Atomic SubSystem: '<S551>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge_d();

  /* End of Outputs for SubSystem: '<S551>/Lib_ChangeEdge' */

  /* RelationalOperator: '<S552>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator2_be = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->OsUnlck;

  /* Chart: '<S552>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S552>/Constant5'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(rtb_LogicalOperator2_be, 8,
    &AppSwcBcm_ARID_DEF.LIB_blOut_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_m);

  /* Logic: '<S552>/Logical Operator2' incorporates:
   *  Constant: '<S552>/Constant'
   *  Constant: '<S552>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S552>/Relational Operator'
   *  RelationalOperator: '<S552>/Relational Operator4'
   */
  rtb_LogicalOperator2_be = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 0);
  rtb_LogicalOperator2_be = ((LampCtl_LightIntstSta == 2) &&
    rtb_LogicalOperator2_be);

  /* Chart: '<S552>/LIB_PosPluseInit' incorporates:
   *  Constant: '<S552>/Constant1'
   *  Constant: '<S552>/Constant3'
   *  Logic: '<S552>/Logical Operator'
   *  Logic: '<S552>/Logical Operator1'
   *  RelationalOperator: '<S552>/Relational Operator1'
   */
  AppSwcBcm_LIB_PosPluseInit((AppSwcBcm_ARID_DEF.BusCreator12.BodyWarnSts == 1) &&
    AppSwcBcm_ARID_DEF.LIB_blOut_e && rtb_LogicalOperator2_be,
    LampCtl_OsUnlckDelayTim_C, !rtb_LogicalOperator2_be, &rtb_LIB_blOut_ao,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit);

  /* Outputs for Atomic SubSystem: '<S340>/Lib_SR' */
  /* Switch: '<S549>/Switch' incorporates:
   *  Logic: '<S551>/Logical Operator'
   */
  if (rtb_LIB_blOut_i || AppSwcBcm_ARID_DEF.RelationalOperator4_g ||
      rtb_RelationalOperator1_d1) {
    /* Switch: '<S549>/Switch' incorporates:
     *  Constant: '<S549>/Constant'
     */
    LampCtl_WelcomeLampSta = false;
  } else {
    /* Switch: '<S549>/Switch' incorporates:
     *  Logic: '<S549>/Logical Operator'
     *  UnitDelay: '<S549>/Unit Delay'
     */
    LampCtl_WelcomeLampSta = (rtb_LIB_blOut_ao || LampCtl_WelcomeLampSta);
  }

  /* End of Switch: '<S549>/Switch' */
  /* End of Outputs for SubSystem: '<S340>/Lib_SR' */

  /* Update for UnitDelay: '<S340>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ih = LampCtl_FlwrMeHomeSta;

  /* Update for UnitDelay: '<S340>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE = LampCtl_FlwrMeHomeTim;

  /* Update for Delay: '<S548>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_np = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_e = LampCtl_FlwrMeHomeCtlFb;

  /* Update for UnitDelay: '<S340>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fq = LampCtl_WelcomeLampSta;
}

/* System initialize for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S233>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/ADASLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/AutoLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/BackLampCtl' */
  AppSwcBcm_BackLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/BackLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/BoxLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/DomeLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/LampDelayCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/LowBeamCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/PosLampCtl' */
  AppSwcBcm_PosLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/PosLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/SignalProcess' */
  AppSwcBcm_SignalProcess_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/SignalProcess' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/TurnIndcrCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S233>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S233>/WelcomeLampCtl' */
}

/* Outputs for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl(void)
{
  boolean rtb_DataTypeConversion3_o;

  /* Outputs for Atomic SubSystem: '<S233>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl();

  /* End of Outputs for SubSystem: '<S233>/ADASLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd3' */
  /* Switch: '<S328>/Switch1' incorporates:
   *  Constant: '<S233>/Constant5'
   */
  if (LampCtl_J420BSDRightCtlOvrdFlg_C) {
    /* Switch: '<S328>/Switch1' incorporates:
     *  Constant: '<S233>/Constant6'
     */
    LampCtl_J420BSDRightCtl = LampCtl_J420BSDRightCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion3' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BSDRightCtlFlg != 0);

    /* Switch: '<S328>/Switch1' incorporates:
     *  Switch: '<S328>/Switch2'
     */
    LampCtl_J420BSDRightCtl = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl);
  }

  /* End of Switch: '<S328>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd4' */
  /* Switch: '<S329>/Switch1' incorporates:
   *  Constant: '<S233>/Constant7'
   */
  if (LampCtl_J422BSDLeftCtlOvrdFlg_C) {
    /* Switch: '<S329>/Switch1' incorporates:
     *  Constant: '<S233>/Constant8'
     */
    LampCtl_J422BSDLeftCtl = LampCtl_J422BSDLeftCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion4' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BSDLeftCtlFlg != 0);

    /* Switch: '<S329>/Switch1' incorporates:
     *  Switch: '<S329>/Switch2'
     */
    LampCtl_J422BSDLeftCtl = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl);
  }

  /* End of Switch: '<S329>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd4' */

  /* Outputs for Atomic SubSystem: '<S233>/SignalProcess' */
  AppSwcBcm_SignalProcess();

  /* End of Outputs for SubSystem: '<S233>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S233>/LightIntstDet' */
  AppSwcBcm_LightIntstDet();

  /* End of Outputs for SubSystem: '<S233>/LightIntstDet' */

  /* Outputs for Atomic SubSystem: '<S233>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl();

  /* End of Outputs for SubSystem: '<S233>/AutoLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/KnobBeamDig' */
  AppSwcBcm_KnobBeamDig();

  /* End of Outputs for SubSystem: '<S233>/KnobBeamDig' */

  /* Outputs for Atomic SubSystem: '<S233>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl();

  /* End of Outputs for SubSystem: '<S233>/LampDelayCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/PosLampCtl' */
  AppSwcBcm_PosLampCtl();

  /* End of Outputs for SubSystem: '<S233>/PosLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd' */
  /* Switch: '<S320>/Switch1' incorporates:
   *  Constant: '<S233>/Constant18'
   *  Constant: '<S233>/Constant19'
   *  Switch: '<S320>/Switch2'
   */
  if (LampCtl_PosLampStaOvrdFlg_C) {
    LampCtl_PosLampSta = LampCtl_PosLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->PosLampCtlFlg != 0);
    LampCtl_PosLampSta = (rtb_DataTypeConversion3_o ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_e);
  }

  /* End of Switch: '<S320>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd' */

  /* Outputs for Atomic SubSystem: '<S233>/PassLampFunc' */
  AppSwcBcm_PassLampFunc();

  /* End of Outputs for SubSystem: '<S233>/PassLampFunc' */

  /* Outputs for Atomic SubSystem: '<S233>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl();

  /* End of Outputs for SubSystem: '<S233>/LowBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd5' */
  /* Switch: '<S330>/Switch1' incorporates:
   *  Constant: '<S233>/Constant10'
   *  Constant: '<S233>/Constant9'
   *  Switch: '<S330>/Switch2'
   */
  if (LampCtl_LowBeamStaOvrdFlg_C) {
    LampCtl_LowBeamSta = LampCtl_LowBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->LowBeamCtlFlg != 0);
    LampCtl_LowBeamSta = (rtb_DataTypeConversion3_o ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);
  }

  /* End of Switch: '<S330>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S233>/BackLampCtl' */
  AppSwcBcm_BackLampCtl();

  /* End of Outputs for SubSystem: '<S233>/BackLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd14' */
  /* Switch: '<S326>/Switch1' incorporates:
   *  Constant: '<S233>/Constant30'
   */
  if (LampCtl_J408BackLampPWMOvrdFlg_C) {
    /* Switch: '<S326>/Switch1' incorporates:
     *  Constant: '<S233>/Constant29'
     */
    LampCtl_J408BackLampPWM = LampCtl_J408BackLampPWMOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion14' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BackLampCtlFlg != 0);

    /* Switch: '<S326>/Switch2' */
    if (rtb_DataTypeConversion3_o) {
      /* Switch: '<S326>/Switch1' incorporates:
       *  Constant: '<S233>/Constant32'
       */
      LampCtl_J408BackLampPWM = 100U;
    } else {
      /* Switch: '<S326>/Switch1' */
      LampCtl_J408BackLampPWM = AppSwcBcm_ARID_DEF.Switch_j;
    }

    /* End of Switch: '<S326>/Switch2' */
  }

  /* End of Switch: '<S326>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd14' */

  /* Outputs for Atomic SubSystem: '<S233>/FogLampRCtl' */
  AppSwcBcm_FogLampRCtl();

  /* End of Outputs for SubSystem: '<S233>/FogLampRCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd6' */
  /* Switch: '<S331>/Switch1' incorporates:
   *  Constant: '<S233>/Constant12'
   */
  if (LampCtl_FogLampRStaOvrdFlg_C) {
    /* Switch: '<S331>/Switch1' incorporates:
     *  Constant: '<S233>/Constant11'
     */
    LampCtl_FogLampRSta = LampCtl_FogLampRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion6' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->FogLampRCtlFlg != 0);

    /* Switch: '<S331>/Switch1' incorporates:
     *  Switch: '<S331>/Switch2'
     */
    LampCtl_FogLampRSta = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_e);
  }

  /* End of Switch: '<S331>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd6' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd7' */
  /* Switch: '<S332>/Switch1' incorporates:
   *  Constant: '<S233>/Constant14'
   */
  if (LampCtl_FogLampFStaOvrdFlg_C) {
    /* Switch: '<S332>/Switch1' incorporates:
     *  Constant: '<S233>/Constant13'
     */
    LampCtl_FogLampFSta = LampCtl_FogLampFStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion7' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->FogLampFCtlFlg != 0);

    /* Switch: '<S332>/Switch1' incorporates:
     *  Switch: '<S332>/Switch2'
     */
    LampCtl_FogLampFSta = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_b);
  }

  /* End of Switch: '<S332>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd7' */

  /* Outputs for Atomic SubSystem: '<S233>/HiBeamCtl' */
  AppSwcBcm_HiBeamCtl();

  /* End of Outputs for SubSystem: '<S233>/HiBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd9' */
  /* Switch: '<S334>/Switch1' incorporates:
   *  Constant: '<S233>/Constant20'
   */
  if (LampCtl_HiBeamStaOvrdFlg_C) {
    /* Switch: '<S334>/Switch1' incorporates:
     *  Constant: '<S233>/Constant17'
     */
    LampCtl_HiBeamSta = LampCtl_HiBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion9' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->HiBeamCtlFlg != 0);

    /* Switch: '<S334>/Switch1' incorporates:
     *  Switch: '<S334>/Switch2'
     */
    LampCtl_HiBeamSta = (rtb_DataTypeConversion3_o ||
                         AppSwcBcm_ARID_DEF.LogicalOperator_gc);
  }

  /* End of Switch: '<S334>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd9' */

  /* Outputs for Atomic SubSystem: '<S233>/DayRunLampCtl' */
  AppSwcBcm_DayRunLampCtl();

  /* End of Outputs for SubSystem: '<S233>/DayRunLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd1' */
  /* Switch: '<S321>/Switch1' incorporates:
   *  Constant: '<S233>/Constant1'
   */
  if (LampCtl_DayRunLightStaOvrdFlg_C) {
    /* Switch: '<S321>/Switch1' incorporates:
     *  Constant: '<S233>/Constant2'
     */
    LampCtl_DayRunLightSta = LampCtl_DayRunLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->DayRunLightCtlFlg != 0);

    /* Switch: '<S321>/Switch1' incorporates:
     *  Switch: '<S321>/Switch2'
     *  UnitDelay: '<S360>/Unit Delay'
     */
    LampCtl_DayRunLightSta = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy);
  }

  /* End of Switch: '<S321>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S233>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl();

  /* End of Outputs for SubSystem: '<S233>/BoxLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd13' */
  /* Switch: '<S325>/Switch1' incorporates:
   *  Constant: '<S233>/Constant28'
   */
  if (LampCtl_J449BoxLampOvrdFlg_C) {
    /* Switch: '<S325>/Switch1' incorporates:
     *  Constant: '<S233>/Constant27'
     */
    LampCtl_J449BoxLamp = LampCtl_J449BoxLampOvrdVal_C;
  } else {
    /* Switch: '<S325>/Switch1' incorporates:
     *  Switch: '<S325>/Switch2'
     *  UnitDelay: '<S310>/Unit Delay'
     */
    LampCtl_J449BoxLamp = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jo;
  }

  /* End of Switch: '<S325>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd13' */

  /* Outputs for Atomic SubSystem: '<S233>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl();

  /* End of Outputs for SubSystem: '<S233>/TurnIndcrCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl();

  /* End of Outputs for SubSystem: '<S233>/WelcomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd11' */
  /* Switch: '<S323>/Switch1' incorporates:
   *  Constant: '<S233>/Constant23'
   */
  if (LampCtl_TurnIndcrRStaOvrdFlg_C) {
    /* Switch: '<S323>/Switch1' incorporates:
     *  Constant: '<S233>/Constant24'
     */
    LampCtl_TurnIndcrRSta = LampCtl_TurnIndcrRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion11' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->TurnIndcrRCtlFlg != 0);

    /* Switch: '<S323>/Switch1' incorporates:
     *  Switch: '<S323>/Switch2'
     */
    LampCtl_TurnIndcrRSta = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.LIB_blOut_m5);
  }

  /* End of Switch: '<S323>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd11' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd12' */
  /* Switch: '<S324>/Switch1' incorporates:
   *  Constant: '<S233>/Constant25'
   */
  if (LampCtl_TurnIndcrLStaOvrdFlg_C) {
    /* Switch: '<S324>/Switch1' incorporates:
     *  Constant: '<S233>/Constant26'
     */
    LampCtl_TurnIndcrLSta = LampCtl_TurnIndcrLStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion12' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->TurnIndcrLCtlFlg != 0);

    /* Switch: '<S324>/Switch1' incorporates:
     *  Switch: '<S324>/Switch2'
     */
    LampCtl_TurnIndcrLSta = (rtb_DataTypeConversion3_o ||
      AppSwcBcm_ARID_DEF.LIB_blOut_j);
  }

  /* End of Switch: '<S324>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd12' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd2' */
  /* Switch: '<S327>/Switch1' incorporates:
   *  Constant: '<S233>/Constant3'
   */
  if (LampCtl_BrakeLightStaOvrdFlg_C) {
    /* Switch: '<S327>/Switch1' incorporates:
     *  Constant: '<S233>/Constant4'
     */
    LampCtl_BrakeLightSta = LampCtl_BrakeLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BrakeLightCtlFlg != 0);

    /* Switch: '<S327>/Switch2' */
    if (rtb_DataTypeConversion3_o) {
      /* Switch: '<S327>/Switch1' incorporates:
       *  Switch: '<S327>/Switch2'
       */
      LampCtl_BrakeLightSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S233>/BrakeLampCtl' */
      AppSwcBcm_BrakeLampCtl();

      /* End of Outputs for SubSystem: '<S233>/BrakeLampCtl' */

      /* Switch: '<S327>/Switch1' incorporates:
       *  Switch: '<S327>/Switch2'
       */
      LampCtl_BrakeLightSta = AppSwcBcm_ARID_DEF.LogicalOperator_ib;
    }

    /* End of Switch: '<S327>/Switch2' */
  }

  /* End of Switch: '<S327>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S233>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl();

  /* End of Outputs for SubSystem: '<S233>/DomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd10' */
  /* Switch: '<S322>/Switch1' incorporates:
   *  Constant: '<S233>/Constant22'
   */
  if (LampCtl_DomeLampPwmDutyOvrdFlg_C) {
    /* Switch: '<S322>/Switch1' incorporates:
     *  Constant: '<S233>/Constant21'
     */
    LampCtl_DomeLampPwmDuty = LampCtl_DomeLampPwmDutyOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion10' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->DomeLampCtlFlg != 0);

    /* Switch: '<S322>/Switch2' */
    if (rtb_DataTypeConversion3_o) {
      /* Switch: '<S322>/Switch1' incorporates:
       *  Constant: '<S233>/Constant31'
       */
      LampCtl_DomeLampPwmDuty = 100U;
    } else {
      /* Switch: '<S322>/Switch1' */
      LampCtl_DomeLampPwmDuty = AppSwcBcm_ARID_DEF.DataTypeConversion;
    }

    /* End of Switch: '<S322>/Switch2' */
  }

  /* End of Switch: '<S322>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd10' */

  /* Outputs for Atomic SubSystem: '<S233>/Ovrd8' */
  /* Switch: '<S333>/Switch1' incorporates:
   *  Constant: '<S233>/Constant16'
   */
  if (LampCtl_ReverseLampStaOvrdFlg_C) {
    /* Switch: '<S333>/Switch1' incorporates:
     *  Constant: '<S233>/Constant15'
     */
    LampCtl_ReverseLampSta = LampCtl_ReverseLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S233>/Data Type Conversion8' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_o = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->ReverseLampCtlFlg != 0);

    /* Switch: '<S333>/Switch2' */
    if (rtb_DataTypeConversion3_o) {
      /* Switch: '<S333>/Switch1' incorporates:
       *  Switch: '<S333>/Switch2'
       */
      LampCtl_ReverseLampSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S233>/ReverseLampCtl' */
      AppSwcBcm_ReverseLampCtl();

      /* End of Outputs for SubSystem: '<S233>/ReverseLampCtl' */

      /* Switch: '<S333>/Switch1' incorporates:
       *  Switch: '<S333>/Switch2'
       */
      LampCtl_ReverseLampSta = AppSwcBcm_ARID_DEF.LogicalOperator_fq;
    }

    /* End of Switch: '<S333>/Switch2' */
  }

  /* End of Switch: '<S333>/Switch1' */
  /* End of Outputs for SubSystem: '<S233>/Ovrd8' */
}

/* Update for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl_Update(void)
{
  /* Update for UnitDelay: '<S233>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ac = LampCtl_WelcomeLampSta;

  /* Update for UnitDelay: '<S233>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_m = LampCtl_FlwrMeHomeSta;

  /* Update for Atomic SubSystem: '<S233>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Update();

  /* End of Update for SubSystem: '<S233>/LampDelayCtl' */

  /* Update for Atomic SubSystem: '<S233>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Update();

  /* End of Update for SubSystem: '<S233>/BoxLampCtl' */

  /* Update for Atomic SubSystem: '<S233>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Update();

  /* End of Update for SubSystem: '<S233>/DomeLampCtl' */
}

/*
 * System initialize for atomic system:
 *    '<S567>/LIB_TPD1'
 *    '<S567>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg)
{
  *rty_LIB_u8ErrFlg = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S567>/LIB_TPD1'
 *    '<S567>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg)
{
  boolean guard1 = false;

  /* Chart: '<S567>/LIB_TPD1' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blAllowRecov;

  /* Outputs for Function Call SubSystem: '<S580>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator_o,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S580>/Lib_RiseEdgeDet' */

  /* Chart: '<S567>/LIB_TPD1' */
  guard1 = false;
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator_o) {
    guard1 = true;
  } else {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn_k = rtu_LIB_blAllowRecov1;

    /* Outputs for Function Call SubSystem: '<S580>/Lib_RiseEdgeDet1' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm__ARID_DEF_arg->Lib_blIn_k,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet1);

    /* End of Outputs for SubSystem: '<S580>/Lib_RiseEdgeDet1' */
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

/* System initialize for atomic system: '<S234>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt_Init(void)
{
  /* SystemInitialize for Chart: '<S567>/LIB_TPD1' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_l);

  /* SystemInitialize for Chart: '<S567>/LIB_TPD2' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg);
}

/* Output and update for atomic system: '<S234>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator3_b;

  /* Logic: '<S567>/Logical Operator' incorporates:
   *  UnitDelay: '<S234>/Unit Delay'
   *  UnitDelay: '<S234>/Unit Delay1'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_as ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f);

  /* RelationalOperator: '<S567>/Relational Operator3' incorporates:
   *  Constant: '<S567>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_b = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S567>/LIB_TPD2' incorporates:
   *  Constant: '<S567>/Constant1'
   *  Constant: '<S567>/Constant2'
   *  Logic: '<S567>/Logical Operator1'
   *  RelationalOperator: '<S567>/Relational Operator'
   *  RelationalOperator: '<S567>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(rtb_LogicalOperator && (!WiperCtl_WiperParkPosSw),
                     WiperCtl_LockedRotorTimDef_C, WiperCtl_LockedRotorTimOk_C,
                     WiperCtl_WiperOffSw, rtb_RelationalOperator3_b,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD2);

  /* Chart: '<S567>/LIB_TPD1' incorporates:
   *  Constant: '<S567>/Constant4'
   *  Constant: '<S567>/Constant5'
   *  Logic: '<S567>/Logical Operator3'
   *  RelationalOperator: '<S567>/Relational Operator1'
   *  RelationalOperator: '<S567>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(WiperCtl_WiperParkPosSw && rtb_LogicalOperator,
                     WiperCtl_LockedRotorTimParkDef_C,
                     WiperCtl_LockedRotorTimParkOk_C, WiperCtl_WiperOffSw,
                     rtb_RelationalOperator3_b,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_l,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD1);

  /* Logic: '<S567>/Logical Operator2' */
  WiperCtl_LockedRotorProtSta = ((AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_l != 0) ||
    (AppSwcBcm_ARID_DEF.LIB_u8ErrFlg != 0));
}

/* Output and update for atomic system: '<S234>/SignalProcess' */
static void AppSwcBcm_SignalProcess_l(void)
{
  uint16 rtb_y;
  uint8 rtb_Switch5_o;
  boolean rtb_Switch1;

  /* Outputs for Atomic SubSystem: '<S571>/Bit Shift5' */
  /* Constant: '<S571>/Constant59' */
  rtb_y = AppSwcBcm_BitShift3(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S571>/Bit Shift5' */

  /* Switch: '<S571>/Switch5' incorporates:
   *  RelationalOperator: '<S571>/Relational Operator'
   *  S-Function (sfix_bitop): '<S571>/Bitwise AND5'
   *  Switch: '<S571>/Switch'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S571>/Switch5' incorporates:
     *  Constant: '<S571>/Constant60'
     */
    rtb_Switch5_o = WiperCtl_WiperSwVal_C;
  } else if (SCS_WiprSwtStVD) {
    /* Switch: '<S571>/Switch' incorporates:
     *  Switch: '<S571>/Switch5'
     */
    rtb_Switch5_o = SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S571>/Switch5' incorporates:
     *  Constant: '<S571>/Constant23'
     *  Switch: '<S571>/Switch'
     */
    rtb_Switch5_o = 0U;
  }

  /* End of Switch: '<S571>/Switch5' */

  /* Chart: '<S571>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S571>/Constant14'
   *  Constant: '<S571>/Constant46'
   *  Constant: '<S571>/Constant47'
   *  Constant: '<S571>/Constant49'
   *  RelationalOperator: '<S571>/Relational Operator9'
   */
  if (rtb_Switch5_o == 4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_m >= (float32)WiperCtl_MistTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_MistTimValid_C != 0xFFFF)) {
      WiperCtl_WiperMistSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m++;
      AppSwcBcm_ARID_DEF.cnt_heal_l = (uint16)((float32)
        WiperCtl_MistTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_l == 0) {
      WiperCtl_WiperMistSw = false;
    } else if (WiperCtl_MistTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_l--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms' */

  /* Chart: '<S571>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S571>/Constant1'
   *  Constant: '<S571>/Constant3'
   *  Constant: '<S571>/Constant4'
   *  Constant: '<S571>/Constant5'
   *  RelationalOperator: '<S571>/Relational Operator1'
   */
  if (rtb_Switch5_o == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lx >= (float32)WiperCtl_OffTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_OffTimValid_C != 0xFFFF)) {
      WiperCtl_WiperOffSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lx++;
      AppSwcBcm_ARID_DEF.cnt_heal_o = (uint16)((float32)WiperCtl_OffTimInValid_C
        / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lx = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_o == 0) {
      WiperCtl_WiperOffSw = false;
    } else if (WiperCtl_OffTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_o--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms1' */

  /* Chart: '<S571>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S571>/Constant10'
   *  Constant: '<S571>/Constant2'
   *  Constant: '<S571>/Constant8'
   *  Constant: '<S571>/Constant9'
   *  RelationalOperator: '<S571>/Relational Operator2'
   */
  if (rtb_Switch5_o == 1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_oa >= (float32)WiperCtl_InrTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_InrTimValid_C != 0xFFFF)) {
      WiperCtl_WiperInrSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_oa++;
      AppSwcBcm_ARID_DEF.cnt_heal_f = (uint16)((float32)WiperCtl_InrTimInValid_C
        / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_oa = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_f == 0) {
      WiperCtl_WiperInrSw = false;
    } else if (WiperCtl_InrTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_f--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms2' */

  /* Chart: '<S571>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S571>/Constant11'
   *  Constant: '<S571>/Constant16'
   *  Constant: '<S571>/Constant17'
   *  Constant: '<S571>/Constant6'
   *  RelationalOperator: '<S571>/Relational Operator3'
   */
  if (rtb_Switch5_o == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_i >= (float32)WiperCtl_LowSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_LowSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperLowSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_i++;
      AppSwcBcm_ARID_DEF.cnt_heal_d = (uint16)((float32)
        WiperCtl_LowSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_i = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d == 0) {
      WiperCtl_WiperLowSpdSw = false;
    } else if (WiperCtl_LowSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_d--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms3' */

  /* Chart: '<S571>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S571>/Constant18'
   *  Constant: '<S571>/Constant21'
   *  Constant: '<S571>/Constant22'
   *  Constant: '<S571>/Constant7'
   *  RelationalOperator: '<S571>/Relational Operator4'
   */
  if (rtb_Switch5_o == 3) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b >= (float32)WiperCtl_HiSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_HiSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperHiSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b++;
      AppSwcBcm_ARID_DEF.cnt_heal_cn = (uint16)((float32)
        WiperCtl_HiSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cn == 0) {
      WiperCtl_WiperHiSpdSw = false;
    } else if (WiperCtl_HiSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cn--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S571>/Bit Shift1' */
  /* Constant: '<S571>/Constant28' */
  rtb_y = AppSwcBcm_BitShift4(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S571>/Bit Shift1' */

  /* Switch: '<S571>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S571>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S571>/Switch1' incorporates:
     *  Constant: '<S571>/Constant29'
     */
    rtb_Switch1 = WiperCtl_WashVal_C;
  } else {
    /* Switch: '<S571>/Switch1' incorporates:
     *  RelationalOperator: '<S571>/Relational Operator5'
     *  Switch: '<S571>/Switch3'
     */
    rtb_Switch1 = (SCS_FrntWshrSwtStVD && SCS_FrntWshrSwtSt);
  }

  /* End of Switch: '<S571>/Switch1' */

  /* Chart: '<S571>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S571>/Constant25'
   *  Constant: '<S571>/Constant26'
   *  Constant: '<S571>/Constant27'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_k >= (float32)WiperCtl_WashTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashTimValid_C != 0xFFFF)) {
      WiperCtl_WashSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k++;
      AppSwcBcm_ARID_DEF.cnt_heal_g = (uint16)((float32)
        WiperCtl_WashTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g == 0) {
      WiperCtl_WashSw = false;
    } else if (WiperCtl_WashTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_g--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S571>/Bit Shift2' */
  /* Constant: '<S571>/Constant35' */
  rtb_y = AppSwcBcm_BitShift7(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S571>/Bit Shift2' */

  /* Switch: '<S571>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S571>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S571>/Switch2' incorporates:
     *  Constant: '<S571>/Constant36'
     */
    rtb_Switch1 = WiperCtl_WiperParkPosVal_C;
  } else {
    /* Switch: '<S571>/Switch2' incorporates:
     *  DataTypeConversion: '<S571>/Data Type Conversion2'
     */
    rtb_Switch1 = (BSW_J334WiperParkPos != 0);
  }

  /* End of Switch: '<S571>/Switch2' */

  /* Chart: '<S571>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S571>/Constant32'
   *  Constant: '<S571>/Constant33'
   *  Constant: '<S571>/Constant34'
   *  Logic: '<S571>/Logical Operator5'
   */
  if (!rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_om >= (float32)
         WiperCtl_WiperParkPosTimValid_C / (WiperCtl_Ts_C * 100.0F)) &&
        (WiperCtl_WiperParkPosTimValid_C != 0xFFFF)) {
      WiperCtl_WiperParkPosSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_om++;
      AppSwcBcm_ARID_DEF.cnt_heal_hv = (uint16)((float32)
        WiperCtl_WiperPosTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_om = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hv == 0) {
      WiperCtl_WiperParkPosSw = false;
    } else if (WiperCtl_WiperPosTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hv--;
    }
  }

  /* End of Chart: '<S571>/LIB_TPD_10ms6' */
}

/* System initialize for atomic system: '<S234>/WashCtl' */
static void AppSwcBcm_WashCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S572>/LIB_Tim' */
  AppSwcBcm_LIB_NegPluse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_m);
}

/* Output and update for atomic system: '<S234>/WashCtl' */
static void AppSwcBcm_WashCtl(void)
{
  boolean rtb_RelationalOperator1_e3;

  /* RelationalOperator: '<S572>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_e3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Chart: '<S572>/LIB_Tim' incorporates:
   *  Constant: '<S572>/Constant'
   *  Logic: '<S572>/Logical Operator'
   *  RelationalOperator: '<S572>/Relational Operator'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator1_e3 && WiperCtl_WashSw,
    WiperCtl_WashMaxTim_C, &AppSwcBcm_ARID_DEF.LIB_blOut_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim);

  /* Chart: '<S572>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S572>/Constant3'
   *  Constant: '<S572>/Constant34'
   *  Constant: '<S572>/Constant4'
   *  Logic: '<S572>/Logical Operator1'
   *  Logic: '<S572>/Logical Operator2'
   *  RelationalOperator: '<S572>/Relational Operator2'
   *  RelationalOperator: '<S572>/Relational Operator3'
   *  RelationalOperator: '<S572>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_m && (WiperCtl_WiperInrSta ||
       WiperCtl_WiperOffSta) && (!AppSwcBcm_ARID_DEF.UnitDelay8)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lo >= (float32)WiperCtl_WashMinTim_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashMinTim_C != 0xFFFF)) {
      WiperCtl_WashWiperSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lo++;
      AppSwcBcm_ARID_DEF.cnt_heal_po = (uint16)(1.0F / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lo = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_po == 0) {
      WiperCtl_WashWiperSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_po--;
    }
  }

  /* End of Chart: '<S572>/LIB_TPD_10ms6' */
}

/*
 * System initialize for function-call system:
 *    '<S605>/Wash.Lib_RiseEdgeDetInit'
 *    '<S605>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S612>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S605>/Wash.Lib_RiseEdgeDetInit'
 *    '<S605>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S612>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S612>/Logical Operator' incorporates:
   *  Delay: '<S612>/Delay'
   *  Logic: '<S612>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S612>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S573>/Chart' */
static void AppSwcBcm_enter_internal_Inr(void)
{
  WiperCtl_WiperSta = 4U;
  AppSwcBcm_ARID_DEF.cnt = 0U;
  if (WiperCtl_WiperInrSta) {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    if ((WiperCtl_InrTim + AppSwcBcm_ARID_DEF.cnt2) - 1 > 0) {
      AppSwcBcm_ARID_DEF.cnt = 1U;
    }
  }
}

/* Function for Chart: '<S573>/Chart' */
static void AppSwcBcm_HiSpdFunc(void)
{
  AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
  AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = true;
  WiperCtl_WiperSta = 3U;
}

/* Function for Chart: '<S573>/Chart' */
static void AppSwcBcm_Nrm(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator1_f4;
  if (WiperCtl_WashWiperSta) {
    if (AppSwcBcm_ARID_DEF.is_Nrm == AppSwcBcm_IN_Inr) {
      AppSwcBcm_ARID_DEF.cnt = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_f;
    } else {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_f;
    }

    AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Wash;
    WiperCtl_WiperSta = 5U;
    AppSwcBcm_ARID_DEF.after_cnt = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
    if (WiperCtl_WiperMistSta || WiperCtl_WiperHiSpdSta ||
        WiperCtl_WiperLowSpdSta) {
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_p2 = WiperCtl_WiperInrSta;
      AppSwcBcm_ARID_DEF.Lib_blInit_n = WiperCtl_WiperInrSta;

      /* Outputs for Function Call SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_p2,
        AppSwcBcm_ARID_DEF.Lib_blInit_n, &AppSwcBcm_ARID_DEF.LogicalOperator_ay,
        &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
        AppSwcBcm_ARID_DEF.LogicalOperator_ay;
    }
  } else if (WiperCtl_WiperMaintSta) {
    if (AppSwcBcm_ARID_DEF.is_Nrm == AppSwcBcm_IN_Inr) {
      AppSwcBcm_ARID_DEF.cnt = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_f;
    } else {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_f;
    }

    AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Maint;
    WiperCtl_WiperSta = 6U;
    AppSwcBcm_ARID_DEF.Cnt_pz = 0U;
    if (WiperCtl_MaintWiperRunTim_C <= 0) {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;

      /* WiperCtl_MaintStaComp=1; */
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      AppSwcBcm_ARID_DEF.Cnt_pz = 1U;

      /* WiperCtl_MaintStaComp=0; */
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_HiSpd:
      if (WiperCtl_WiperLowSpdSta || (!WiperCtl_WiperHiSpdSta) ||
          WiperCtl_WiperOffSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;

        /* UnitDelay: '<S234>/Unit Delay2' */
        /* (WiperCtl_WiperHiSpdSta==0||WiperCtl_WiperOffSta==1)&&WiperCtl_WiperParkPosSta==1||... */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
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
        rtb_LogicalOperator1_f4 = !WiperCtl_WiperInrSta;

        /* UnitDelay: '<S234>/Unit Delay2' incorporates:
         *  Delay: '<S610>/Delay'
         *  Logic: '<S610>/Logical Operator'
         */
        if (((rtb_LogicalOperator1_f4 || WiperCtl_WiperOffSta) &&
             WiperCtl_WiperParkPosSw) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)
        {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
          WiperCtl_WiperSta = 0U;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
          if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2)
              && (!WiperCtl_WiperParkPosSw) &&
              (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
          } else {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
          }
        } else if (WiperCtl_WiperHiSpdSta && rtb_LogicalOperator1_f4) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
        } else if (rtb_LogicalOperator1_f4 && WiperCtl_WiperLowSpdSta) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
        } else {
          if (WiperCtl_InrTimChg) {
            AppSwcBcm_ARID_DEF.cnt = 0U;
          }

          if (WiperCtl_WiperInrSta) {
            if (AppSwcBcm_ARID_DEF.cnt == 0) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
              AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
            } else {
              /* Outputs for Function Call SubSystem: '<S605>/Nrm.Inr.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.icLoad_hu) {
                /* Delay: '<S610>/Delay' */
                AppSwcBcm_ARID_DEF.Delay_DSTATE_c = WiperCtl_WiperParkPosSw;
              }

              /* Logic: '<S610>/Logical Operator1' incorporates:
               *  Delay: '<S610>/Delay'
               */
              rtb_LogicalOperator1_f4 = !AppSwcBcm_ARID_DEF.Delay_DSTATE_c;

              /* Update for Delay: '<S610>/Delay' */
              AppSwcBcm_ARID_DEF.icLoad_hu = false;
              AppSwcBcm_ARID_DEF.Delay_DSTATE_c = WiperCtl_WiperParkPosSw;
              if (WiperCtl_WiperParkPosSw && rtb_LogicalOperator1_f4) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
                AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
                AppSwcBcm_ARID_DEF.cnt2 = AppSwcBcm_ARID_DEF.cnt;
              }

              /* End of Outputs for SubSystem: '<S605>/Nrm.Inr.Lib_RiseEdgeDetInit' */
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
      /* UnitDelay: '<S234>/Unit Delay2' */
      if (((((!WiperCtl_WiperLowSpdSta) && (!WiperCtl_WiperHiSpdSta)) ||
            WiperCtl_WiperOffSta) && WiperCtl_WiperParkPosSw) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
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
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        WiperCtl_WiperSta = 2U;
      }
      break;

     case AppSwcBcm_IN_Mist:
      /* UnitDelay: '<S234>/Unit Delay2' */
      if ((((!WiperCtl_WiperMistSta) || WiperCtl_WiperOffSta) &&
           WiperCtl_WiperParkPosSw) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
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
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
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
                 (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S234>/WiperDrv' */
static void AppSwcBcm_WiperDrv_Init(void)
{
  /* SystemInitialize for Chart: '<S573>/Chart' incorporates:
   *  SubSystem: '<S605>/Nrm.Inr.Lib_RiseEdgeDetInit'
   */
  /* InitializeConditions for Delay: '<S610>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_hu = true;

  /* SystemInitialize for Chart: '<S573>/Chart' incorporates:
   *  SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S573>/Chart' incorporates:
   *  SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);
}

/* Output and update for atomic system: '<S234>/WiperDrv' */
static void AppSwcBcm_WiperDrv(void)
{
  sint32 tmp;

  /* Chart: '<S573>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S234>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c11_WiperCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_WiperCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Nrm_j;
    AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
    WiperCtl_WiperSta = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) && (
         !WiperCtl_WiperParkPosSw) && (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k))
    {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib) {
     case AppSwcBcm_IN_Maint:
      if ((!WiperCtl_WiperMaintSta) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Nrm_j;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        }
      } else if (AppSwcBcm_ARID_DEF.Cnt_pz >= WiperCtl_MaintWiperRunTim_C) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;

        /* WiperCtl_MaintStaComp=1; */
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        AppSwcBcm_ARID_DEF.Cnt_pz++;

        /* WiperCtl_MaintStaComp=0; */
      }
      break;

     case AppSwcBcm_IN_Nrm_j:
      AppSwcBcm_Nrm();
      break;

     default:
      /* case IN_Wash: */
      if (((!WiperCtl_WashWiperSta) && AppSwcBcm_ARID_DEF.WiperCtl_WashComp) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k ||
          (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) &&
           WiperCtl_WiperParkPosSw)) {
        AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Nrm_j;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_l;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
        }
      } else {
        if (WiperCtl_WashWiperSta) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o = false;
          AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_jd = WiperCtl_WiperParkPosSw;

          /* Outputs for Function Call SubSystem: '<S605>/Wash.Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jd,
            &AppSwcBcm_ARID_DEF.LogicalOperator_hz,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDet);

          /* End of Outputs for SubSystem: '<S605>/Wash.Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_hz) {
            tmp = AppSwcBcm_ARID_DEF.last_cnt - 1;
            if (AppSwcBcm_ARID_DEF.last_cnt - 1 < 0) {
              tmp = 0;
            }

            AppSwcBcm_ARID_DEF.last_cnt = (uint8)tmp;
          }

          if (AppSwcBcm_ARID_DEF.last_cnt == 0) {
            if (WiperCtl_WiperInrSta) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
              AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
            } else {
              tmp = AppSwcBcm_ARID_DEF.after_cnt + 1;
              if (AppSwcBcm_ARID_DEF.after_cnt + 1 > 65535) {
                tmp = 65535;
              }

              AppSwcBcm_ARID_DEF.after_cnt = (uint16)tmp;
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
            }

            if (AppSwcBcm_ARID_DEF.after_cnt >= WiperCtl_WashAfterTim_C) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
              AppSwcBcm_ARID_DEF.Lib_blIn_n = WiperCtl_WiperParkPosSw;
              AppSwcBcm_ARID_DEF.Lib_blInit_d = true;

              /* Outputs for Function Call SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit' */
              AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_n,
                true, &AppSwcBcm_ARID_DEF.LogicalOperator_d5,
                &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

              /* End of Outputs for SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_d5) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
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
          AppSwcBcm_ARID_DEF.Lib_blIn_p2 = WiperCtl_WiperInrSta;
          AppSwcBcm_ARID_DEF.Lib_blInit_n = WiperCtl_WiperInrSta;

          /* Outputs for Function Call SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_p2,
            AppSwcBcm_ARID_DEF.Lib_blInit_n,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ay,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

          /* End of Outputs for SubSystem: '<S605>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
            (AppSwcBcm_ARID_DEF.LogicalOperator_ay ||
             AppSwcBcm_ARID_DEF.WiperCtl_WashComp);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S573>/Chart' */
}

/* Output and update for atomic system: '<S234>/WiperHiSpdCtl' */
static void AppSwcBcm_WiperHiSpdCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S574>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S574>/Logical Operator' incorporates:
   *  RelationalOperator: '<S574>/Relational Operator1'
   *  RelationalOperator: '<S574>/Relational Operator2'
   */
  WiperCtl_WiperHiSpdSta = (rtb_RelationalOperator && WiperCtl_WiperHiSpdSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay4_n));
}

/* System initialize for atomic system: '<S234>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S575>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_eg = true;

  /* InitializeConditions for Delay: '<S575>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_o5 = true;
}

/* Output and update for atomic system: '<S234>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl(void)
{
  uint8 rtb_Switch;
  boolean rtb_RelationalOperator5_i;

  /* RelationalOperator: '<S575>/Relational Operator5' incorporates:
   *  Constant: '<S575>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S575>/Relational Operator'
   */
  rtb_RelationalOperator5_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S575>/Logical Operator' incorporates:
   *  RelationalOperator: '<S575>/Relational Operator2'
   */
  WiperCtl_WiperInrSta = (rtb_RelationalOperator5_i && WiperCtl_WiperInrSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay5_b));

  /* Delay: '<S575>/Delay1' */
  if (AppSwcBcm_ARID_DEF.icLoad_eg) {
    /* Switch: '<S575>/Switch1' incorporates:
     *  Constant: '<S575>/Constant20'
     *  Constant: '<S575>/Constant8'
     *  RelationalOperator: '<S575>/Relational Operator4'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.InrTim == 255) {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrLvl3Tim_C;
    } else {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = AppSwcBcm_ARID_DEF.BusCreator12.InrTim;
    }

    /* End of Switch: '<S575>/Switch1' */
  }

  /* RelationalOperator: '<S575>/Relational Operator5' incorporates:
   *  Constant: '<S575>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S575>/Relational Operator3'
   */
  rtb_RelationalOperator5_i = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Switch: '<S575>/Switch' */
  if (rtb_RelationalOperator5_i) {
    /* Switch: '<S575>/Switch' */
    rtb_Switch = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUWiprIntlTmSet_enum;
  } else {
    /* Switch: '<S575>/Switch' incorporates:
     *  Constant: '<S575>/Constant19'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S575>/Switch' */

  /* MultiPortSwitch: '<S575>/Multiport Switch' incorporates:
   *  Constant: '<S575>/Constant1'
   *  Constant: '<S575>/Constant2'
   *  Constant: '<S575>/Constant3'
   *  Constant: '<S575>/Constant4'
   *  Constant: '<S575>/Constant5'
   *  Constant: '<S575>/Constant6'
   *  Constant: '<S575>/Constant7'
   *  Delay: '<S575>/Delay1'
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

  /* End of MultiPortSwitch: '<S575>/Multiport Switch' */

  /* RelationalOperator: '<S575>/Relational Operator1' incorporates:
   *  UnitDelay: '<S575>/Unit Delay'
   */
  WiperCtl_InrTimChg = (WiperCtl_InrTim != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE);

  /* Delay: '<S575>/Delay2' */
  if (AppSwcBcm_ARID_DEF.icLoad_o5) {
    /* Switch: '<S575>/Switch2' incorporates:
     *  Constant: '<S575>/Constant15'
     *  Constant: '<S575>/Constant21'
     *  RelationalOperator: '<S575>/Relational Operator5'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE =
        AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb;
    }

    /* End of Switch: '<S575>/Switch2' */
  }

  /* MultiPortSwitch: '<S575>/Multiport Switch1' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant9'
     */
    WiperCtl_WiprIntlTimeSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant16'
     */
    WiperCtl_WiprIntlTimeSetFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant10'
     */
    WiperCtl_WiprIntlTimeSetFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant11'
     */
    WiperCtl_WiprIntlTimeSetFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant12'
     */
    WiperCtl_WiprIntlTimeSetFb = 4U;
    break;

   case 6:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant13'
     */
    WiperCtl_WiprIntlTimeSetFb = 5U;
    break;

   case 7:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Constant: '<S575>/Constant14'
     */
    WiperCtl_WiprIntlTimeSetFb = 6U;
    break;

   default:
    /* MultiPortSwitch: '<S575>/Multiport Switch1' incorporates:
     *  Delay: '<S575>/Delay2'
     */
    WiperCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.Delay2_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S575>/Multiport Switch1' */

  /* Update for Delay: '<S575>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_eg = false;
  AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrTim;

  /* Update for UnitDelay: '<S575>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE = WiperCtl_InrTim;

  /* Update for Delay: '<S575>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_o5 = false;
  AppSwcBcm_ARID_DEF.Delay2_DSTATE = WiperCtl_WiprIntlTimeSetFb;
}

/* Output and update for atomic system: '<S234>/WiperLowSpdCtl' */
static void AppSwcBcm_WiperLowSpdCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S576>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S576>/Logical Operator' incorporates:
   *  RelationalOperator: '<S576>/Relational Operator1'
   *  RelationalOperator: '<S576>/Relational Operator2'
   */
  WiperCtl_WiperLowSpdSta = (rtb_RelationalOperator && WiperCtl_WiperLowSpdSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay7));
}

/* Output and update for atomic system: '<S234>/WiperMaintCtl' */
static void AppSwcBcm_WiperMaintCtl(void)
{
  boolean rtb_RelationalOperator6_n;

  /* Chart: '<S577>/MaintOff' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S577>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_co) {
    AppSwcBcm_ARID_DEF.Lib_blIn_c =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

    /* Outputs for Function Call SubSystem: '<S615>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_c,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ji,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_md);

    /* End of Outputs for SubSystem: '<S615>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.Flg_h = (AppSwcBcm_ARID_DEF.LogicalOperator_ji ||
      AppSwcBcm_ARID_DEF.Flg_h);
    if (AppSwcBcm_ARID_DEF.Flg_h) {
      AppSwcBcm_ARID_DEF.Lib_blIn_jb =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S615>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_jb,
        &AppSwcBcm_ARID_DEF.LogicalOperator_at,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

      /* End of Outputs for SubSystem: '<S615>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff =
        (AppSwcBcm_ARID_DEF.LogicalOperator_at ||
         AppSwcBcm_ARID_DEF.WiperCtl_MaintOff);
    }
  } else {
    AppSwcBcm_ARID_DEF.Flg_h = false;
    AppSwcBcm_ARID_DEF.WiperCtl_MaintOff = false;
  }

  /* End of Chart: '<S577>/MaintOff' */

  /* Outputs for Atomic SubSystem: '<S577>/Lib_SR' */
  /* Switch: '<S614>/Switch' incorporates:
   *  Constant: '<S577>/Constant2'
   *  Constant: '<S577>/Constant5'
   *  Constant: '<S614>/Constant'
   *  Logic: '<S577>/Logical Operator'
   *  Logic: '<S577>/Logical Operator1'
   *  Logic: '<S614>/Logical Operator'
   *  RelationalOperator: '<S577>/Relational Operator1'
   *  RelationalOperator: '<S577>/Relational Operator2'
   *  RelationalOperator: '<S577>/Relational Operator3'
   *  RelationalOperator: '<S577>/Relational Operator4'
   *  RelationalOperator: '<S577>/Relational Operator5'
   *  UnitDelay: '<S614>/Unit Delay'
   */
  if ((!WiperCtl_WiperOffSw) ||
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 1) ||
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff) {
    WiperCtl_WiperMaintSta = false;
  } else {
    /* RelationalOperator: '<S577>/Relational Operator6' incorporates:
     *  Constant: '<S577>/Constant3'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_n = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    WiperCtl_WiperMaintSta = (((!AppSwcBcm_ARID_DEF.UnitDelay6) &&
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 2) &&
      WiperCtl_WiperParkPosSw && rtb_RelationalOperator6_n) ||
      WiperCtl_WiperMaintSta);
  }

  /* End of Switch: '<S614>/Switch' */
  /* End of Outputs for SubSystem: '<S577>/Lib_SR' */

  /* Update for UnitDelay: '<S577>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_co = WiperCtl_WiperMaintSta;
}

/* Output and update for atomic system: '<S234>/WiperMistCtl' */
static void AppSwcBcm_WiperMistCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S578>/Relational Operator' incorporates:
   *  Constant: '<S578>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S578>/Logical Operator' incorporates:
   *  RelationalOperator: '<S578>/Relational Operator1'
   *  RelationalOperator: '<S578>/Relational Operator2'
   */
  WiperCtl_WiperMistSta = (rtb_RelationalOperator && WiperCtl_WiperMistSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay3_l));
}

/* Output and update for atomic system: '<S234>/WiperOffCtl' */
static void AppSwcBcm_WiperOffCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S579>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* Logic: '<S579>/Logical Operator' incorporates:
   *  RelationalOperator: '<S579>/Relational Operator1'
   */
  WiperCtl_WiperOffSta = (rtb_RelationalOperator || WiperCtl_WiperOffSw);
}

/* System initialize for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S234>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt_Init();

  /* End of SystemInitialize for SubSystem: '<S234>/LockedRotorProt' */

  /* SystemInitialize for Atomic SubSystem: '<S234>/WashCtl' */
  AppSwcBcm_WashCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S234>/WashCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S234>/WiperDrv' */
  AppSwcBcm_WiperDrv_Init();

  /* End of SystemInitialize for SubSystem: '<S234>/WiperDrv' */

  /* SystemInitialize for Atomic SubSystem: '<S234>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S234>/WiperInrCtl' */
}

/* Output and update for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl(void)
{
  boolean rtb_DataTypeConversion_j0;

  /* SignalConversion: '<S234>/Signal Conversion' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWiprSwtSt =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWiprSwtSt_enum;

  /* SignalConversion: '<S234>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWshrSwtSt =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWshrSwtSt_flg;

  /* SignalConversion: '<S234>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWshrSwtStVD =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWshrSwtStVld_flg;

  /* SignalConversion: '<S234>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_WiprSwtStVD =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWiprSwtStVld_flg;

  /* Outputs for Atomic SubSystem: '<S234>/SignalProcess' */
  AppSwcBcm_SignalProcess_l();

  /* End of Outputs for SubSystem: '<S234>/SignalProcess' */

  /* UnitDelay: '<S234>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_b = WiperCtl_LockedRotorProtSta;

  /* Outputs for Atomic SubSystem: '<S234>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl();

  /* End of Outputs for SubSystem: '<S234>/WiperInrCtl' */

  /* Outputs for Atomic SubSystem: '<S234>/WiperOffCtl' */
  AppSwcBcm_WiperOffCtl();

  /* End of Outputs for SubSystem: '<S234>/WiperOffCtl' */

  /* UnitDelay: '<S234>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8 = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i;

  /* Outputs for Atomic SubSystem: '<S234>/WashCtl' */
  AppSwcBcm_WashCtl();

  /* End of Outputs for SubSystem: '<S234>/WashCtl' */

  /* UnitDelay: '<S234>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_n = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_m;

  /* Outputs for Atomic SubSystem: '<S234>/WiperHiSpdCtl' */
  AppSwcBcm_WiperHiSpdCtl();

  /* End of Outputs for SubSystem: '<S234>/WiperHiSpdCtl' */

  /* UnitDelay: '<S234>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7 = AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_i;

  /* Outputs for Atomic SubSystem: '<S234>/WiperLowSpdCtl' */
  AppSwcBcm_WiperLowSpdCtl();

  /* End of Outputs for SubSystem: '<S234>/WiperLowSpdCtl' */

  /* UnitDelay: '<S234>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_l = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_j;

  /* Outputs for Atomic SubSystem: '<S234>/WiperMistCtl' */
  AppSwcBcm_WiperMistCtl();

  /* End of Outputs for SubSystem: '<S234>/WiperMistCtl' */

  /* UnitDelay: '<S234>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6 = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_k;

  /* Outputs for Atomic SubSystem: '<S234>/WiperMaintCtl' */
  AppSwcBcm_WiperMaintCtl();

  /* End of Outputs for SubSystem: '<S234>/WiperMaintCtl' */

  /* Outputs for Atomic SubSystem: '<S234>/WiperDrv' */
  AppSwcBcm_WiperDrv();

  /* End of Outputs for SubSystem: '<S234>/WiperDrv' */

  /* Outputs for Atomic SubSystem: '<S234>/Ovrd1' */
  /* Switch: '<S568>/Switch1' incorporates:
   *  Constant: '<S234>/Constant1'
   */
  if (WiperCtl_LowSpdDrvOvrdFlg_C) {
    /* Switch: '<S568>/Switch1' incorporates:
     *  Constant: '<S234>/Constant2'
     */
    WiperCtl_LowSpdDrv = WiperCtl_LowSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S234>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_j0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperLowSpdCtlFlg != 0);

    /* Switch: '<S568>/Switch1' incorporates:
     *  Switch: '<S568>/Switch2'
     */
    WiperCtl_LowSpdDrv = (rtb_DataTypeConversion_j0 ||
                          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g);
  }

  /* End of Switch: '<S568>/Switch1' */
  /* End of Outputs for SubSystem: '<S234>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S234>/Ovrd2' */
  /* Switch: '<S569>/Switch1' incorporates:
   *  Constant: '<S234>/Constant3'
   */
  if (WiperCtl_HiSpdDrvOvrdFlg_C) {
    /* Switch: '<S569>/Switch1' incorporates:
     *  Constant: '<S234>/Constant4'
     */
    WiperCtl_HiSpdDrv = WiperCtl_HiSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S234>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_j0 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperHiSpdCtlFlg != 0);

    /* Switch: '<S569>/Switch1' incorporates:
     *  Switch: '<S569>/Switch2'
     */
    WiperCtl_HiSpdDrv = (rtb_DataTypeConversion_j0 ||
                         AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_o);
  }

  /* End of Switch: '<S569>/Switch1' */
  /* End of Outputs for SubSystem: '<S234>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S234>/Ovrd3' */
  /* Switch: '<S570>/Switch1' incorporates:
   *  Constant: '<S234>/Constant18'
   */
  if (WiperCtl_WashMotorDrvOvrdFlg_C) {
    /* Switch: '<S570>/Switch1' incorporates:
     *  Constant: '<S234>/Constant19'
     */
    WiperCtl_WashMotorDrv = WiperCtl_WashMotorDrvOvrdVal_C;
  } else {
    /* Switch: '<S570>/Switch1' incorporates:
     *  Switch: '<S570>/Switch2'
     */
    WiperCtl_WashMotorDrv = AppSwcBcm_ARID_DEF.LIB_blOut_m;
  }

  /* End of Switch: '<S570>/Switch1' */
  /* End of Outputs for SubSystem: '<S234>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S234>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt();

  /* End of Outputs for SubSystem: '<S234>/LockedRotorProt' */

  /* Update for UnitDelay: '<S234>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_i = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S234>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_m = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S234>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_i = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S234>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_j = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S234>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S234>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_k = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S234>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_as = WiperCtl_LowSpdDrv;

  /* Update for UnitDelay: '<S234>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f = WiperCtl_HiSpdDrv;
}

/*
 * Output and update for atomic system:
 *    '<S630>/Lib_FailEdgeDet'
 *    '<S633>/Lib_FailEdgeDet'
 *    '<S631>/Lib_FailEdgeDet'
 *    '<S634>/Lib_FailEdgeDet'
 *    '<S632>/Lib_FailEdgeDet'
 */
static void AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_h_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S638>/Logical Operator' incorporates:
   *  Logic: '<S638>/Logical Operator1'
   *  UnitDelay: '<S638>/Unit Delay'
   */
  *rty_Lib_blOut = ((!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S638>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S629>/Lib_FailEdgeDet'
 *    '<S629>/Lib_FailEdgeDet3'
 *    '<S629>/Lib_FailEdgeDet4'
 *    '<S629>/Lib_FailEdgeDet2'
 */
static void AppSwcBcm_Lib_FailEdgeDet_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_f_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S630>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_a(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S630>/Lib_FailEdgeDet' */
}

/* Output and update for function-call system: '<S629>/Lib_FailEdgeDet1' */
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S631>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_a(rtu_Lib_blIn, rty_Lib_lbOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S631>/Lib_FailEdgeDet' */
}

/* Function for Chart: '<S620>/AlmSysLogic' */
static void AppSwcBcm_AlmWarn(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_hj = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_hj,
    &AppSwcBcm_ARID_DEF.LogicalOperator_po,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_m);

  /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
    /* Flg=1; */
    AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_b = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet1' */
    AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_b,
      &AppSwcBcm_ARID_DEF.LogicalOperator_j0,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_i);

    /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet1' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_j0) {
      /* Flg=1; */
      AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_m = AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

      /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet2' */
      AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_m,
        &AppSwcBcm_ARID_DEF.LogicalOperator_g3,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

      /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_g3) {
        /* Flg=1; */
        AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_l =
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet3' */
        AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_l,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ht,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

        /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet3' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ht) {
          /* Flg=1; */
          AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

          /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet4' */
          AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
            &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

          /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet4' */
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

/* System initialize for atomic system: '<S620>/AlmSysLogic' */
static void AppSwcBcm_AlmSysLogic_Init(void)
{
  /* SystemInitialize for Function Call SubSystem: '<S629>/Lib_RiseEdgeDetInit' */
  /* SystemInitialize for Atomic SubSystem: '<S637>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S637>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S629>/Lib_RiseEdgeDetInit' */
}

/* Output and update for atomic system: '<S620>/AlmSysLogic' */
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

  /* Chart: '<S620>/AlmSysLogic' incorporates:
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

        /* Outputs for Function Call SubSystem: '<S629>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_g,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nv);

        /* End of Outputs for SubSystem: '<S629>/Lib_RiseEdgeDet' */
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

        /* Outputs for Function Call SubSystem: '<S629>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_g,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nv);

        /* End of Outputs for SubSystem: '<S629>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
          guard5 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta == 1) {
          AppSwcBcm_ARID_DEF.is_c1_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_j;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_hj =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

          /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet' */
          AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_hj,
            &AppSwcBcm_ARID_DEF.LogicalOperator_po,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_m);

          /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
            guard8 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_b =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

            /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet1' */
            AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_b,
              &AppSwcBcm_ARID_DEF.LogicalOperator_j0,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_i);

            /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet1' */
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

        /* Outputs for Function Call SubSystem: '<S629>/Lib_RiseEdgeDetInit' */
        /* Outputs for Atomic SubSystem: '<S637>/Lib_RiseEdgeDetInit' */
        AppSwcBcm_Lib_RiseEdgeDetInit_d(AppSwcBcm_ARID_DEF.Lib_blIn_ip, true,
          &AppSwcBcm_ARID_DEF.LogicalOperator_l0,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

        /* End of Outputs for SubSystem: '<S637>/Lib_RiseEdgeDetInit' */
        /* End of Outputs for SubSystem: '<S629>/Lib_RiseEdgeDetInit' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_l0 &&
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) {
          guard1 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
          guard2 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_g = (AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE ==
            1);

          /* Outputs for Function Call SubSystem: '<S629>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_g,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nv);

          /* End of Outputs for SubSystem: '<S629>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_hj =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

            /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet' */
            AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_hj,
              &AppSwcBcm_ARID_DEF.LogicalOperator_po,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_m);

            /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_po) {
              guard3 = true;
            } else {
              AppSwcBcm_ARID_DEF.Lib_blIn_b =
                AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

              /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet1' */
              AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_b,
                &AppSwcBcm_ARID_DEF.LogicalOperator_j0,
                &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_i);

              /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet1' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_j0) {
                guard3 = true;
              } else {
                AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

                /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet4' */
                AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
                  &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
                  &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

                /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet4' */
                if (AppSwcBcm_ARID_DEF.LogicalOperator_pd) {
                  guard3 = true;
                } else {
                  AppSwcBcm_ARID_DEF.Lib_blIn_ol =
                    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_k0;

                  /* Outputs for Function Call SubSystem: '<S629>/Lib_RiseEdgeDet1' */
                  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ol,
                    &AppSwcBcm_ARID_DEF.LogicalOperator_o4,
                    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_o);

                  /* End of Outputs for SubSystem: '<S629>/Lib_RiseEdgeDet1' */
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

      /* Outputs for Function Call SubSystem: '<S629>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ol,
        &AppSwcBcm_ARID_DEF.LogicalOperator_o4,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_o);

      /* End of Outputs for SubSystem: '<S629>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_o4) {
        guard6 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_m =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

        /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet2' */
        AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_m,
          &AppSwcBcm_ARID_DEF.LogicalOperator_g3,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

        /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_g3) {
          guard6 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_l =
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

          /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet3' */
          AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_l,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ht,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

          /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet3' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ht) {
            guard6 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

            /* Outputs for Function Call SubSystem: '<S629>/Lib_FailEdgeDet4' */
            AppSwcBcm_Lib_FailEdgeDet_j(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
              &AppSwcBcm_ARID_DEF.LogicalOperator_pd,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

            /* End of Outputs for SubSystem: '<S629>/Lib_FailEdgeDet4' */
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

  /* End of Chart: '<S620>/AlmSysLogic' */
}

/* System initialize for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S620>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic_Init();
}

/* Output and update for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl(void)
{
  /* DataTypeConversion: '<S620>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.DataTypeConversion10 =
    (AppSwcBcm_ARID_DEF.BusCreator14.SKSta != 0);

  /* Chart: '<S620>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic();
}

/*
 * System initialize for atomic system:
 *    '<S649>/Lib_BothEdgeDetInit'
 *    '<S649>/Lib_BothEdgeDetInit1'
 *    '<S649>/Lib_BothEdgeDetInit2'
 *    '<S649>/Lib_BothEdgeDetInit3'
 */
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S652>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S649>/Lib_BothEdgeDetInit'
 *    '<S649>/Lib_BothEdgeDetInit1'
 *    '<S649>/Lib_BothEdgeDetInit2'
 *    '<S649>/Lib_BothEdgeDetInit3'
 */
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Delay: '<S652>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S652>/Logical Operator2' incorporates:
   *  Delay: '<S652>/Delay'
   *  Logic: '<S652>/Logical Operator1'
   *  Logic: '<S652>/Logical Operator3'
   *  Logic: '<S652>/Logical Operator4'
   *  Logic: '<S652>/Logical Operator5'
   */
  rty_Lib_blOut_0 = ((AppSwcBcm__ARID_DEF_arg->Delay_DSTATE && (!rtu_Lib_blIn)) ||
                     (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE)));

  /* Update for Delay: '<S652>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S649>/Lib_BothEdgeDetInit' */

  /* SystemInitialize for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit1' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of SystemInitialize for SubSystem: '<S649>/Lib_BothEdgeDetInit1' */

  /* SystemInitialize for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit2' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of SystemInitialize for SubSystem: '<S649>/Lib_BothEdgeDetInit2' */

  /* SystemInitialize for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit3' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of SystemInitialize for SubSystem: '<S649>/Lib_BothEdgeDetInit3' */
}

/* Output and update for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion_a;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator2_fg;
  boolean rtb_RelationalOperator3_a3;
  boolean rtb_RelationalOperator4_e;
  boolean rtb_Switch;

  /* RelationalOperator: '<S649>/Relational Operator' incorporates:
   *  Constant: '<S649>/Constant'
   */
  BatSaveCtl_PwrModeOn = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 2);

  /* RelationalOperator: '<S649>/Relational Operator1' incorporates:
   *  Constant: '<S649>/Constant1'
   */
  BatSaveCtl_DoorUnlckPwrOn = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* Outputs for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit' */
  rtb_RelationalOperator = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of Outputs for SubSystem: '<S649>/Lib_BothEdgeDetInit' */

  /* Outputs for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit1' */
  rtb_RelationalOperator2_fg = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of Outputs for SubSystem: '<S649>/Lib_BothEdgeDetInit1' */

  /* Outputs for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit2' */
  rtb_RelationalOperator3_a3 = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of Outputs for SubSystem: '<S649>/Lib_BothEdgeDetInit2' */

  /* Outputs for Atomic SubSystem: '<S649>/Lib_BothEdgeDetInit3' */
  rtb_RelationalOperator4_e = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of Outputs for SubSystem: '<S649>/Lib_BothEdgeDetInit3' */

  /* Logic: '<S649>/Logical Operator1' */
  BatSaveCtl_DoorChgSta = (rtb_RelationalOperator || rtb_RelationalOperator2_fg ||
    rtb_RelationalOperator3_a3 || rtb_RelationalOperator4_e);

  /* Logic: '<S649>/Logical Operator' */
  BatSaveCtl_PwrOn = (BatSaveCtl_PwrModeOn || BatSaveCtl_DoorUnlckPwrOn ||
                      BatSaveCtl_DoorChgSta);

  /* Chart: '<S648>/LIB_PosPluse' incorporates:
   *  Constant: '<S648>/Constant2'
   *  Constant: '<S648>/Constant4'
   *  Logic: '<S648>/Logical Operator2'
   *  Logic: '<S648>/Logical Operator3'
   *  Logic: '<S648>/Logical Operator5'
   *  Logic: '<S648>/Logical Operator8'
   *  RelationalOperator: '<S648>/Relational Operator'
   *  RelationalOperator: '<S648>/Relational Operator2'
   *  RelationalOperator: '<S648>/Relational Operator3'
   *  RelationalOperator: '<S648>/Relational Operator4'
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

  /* End of Chart: '<S648>/LIB_PosPluse' */

  /* Chart: '<S648>/LIB_PosPluse1' incorporates:
   *  Constant: '<S648>/Constant6'
   *  Constant: '<S648>/Constant7'
   *  RelationalOperator: '<S648>/Relational Operator6'
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

  /* End of Chart: '<S648>/LIB_PosPluse1' */

  /* Logic: '<S648>/Logical Operator' */
  BatSaveCtl_PwrOff = (BatSaveCtl_PwrModeOff || BatSaveCtl_DoorLckPwrOff);

  /* Outputs for Atomic SubSystem: '<S621>/Lib_SR' */
  AppSwcBcm_Lib_SR(BatSaveCtl_PwrOn, BatSaveCtl_PwrOff, &rtb_Switch,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR);

  /* End of Outputs for SubSystem: '<S621>/Lib_SR' */

  /* Outputs for Atomic SubSystem: '<S621>/Ovrd1' */
  /* Switch: '<S647>/Switch1' incorporates:
   *  Constant: '<S621>/Constant18'
   */
  if (BatSaveCtl_J64SavePwrOvrdFlg_C) {
    /* Switch: '<S647>/Switch1' incorporates:
     *  Constant: '<S621>/Constant19'
     */
    BatSaveCtl_J64SavePwr = BatSaveCtl_J64SavePwrOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S621>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_a = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BatSaveCtlFlg != 0);

    /* Switch: '<S647>/Switch1' incorporates:
     *  Switch: '<S647>/Switch2'
     */
    BatSaveCtl_J64SavePwr = (rtb_DataTypeConversion_a || rtb_Switch);
  }

  /* End of Switch: '<S647>/Switch1' */
  /* End of Outputs for SubSystem: '<S621>/Ovrd1' */
}

/* Output and update for atomic system: '<S4>/DTCCtl' */
static void AppSwcBcm_DTCCtl(void)
{
  uint8 rtb_DataTypeConversion22;

  /* DataTypeConversion: '<S622>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S622>/Data Type Conversion'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrLShort;

  /* CCaller: '<S622>/C Caller' */
  App_Call_Event_DTC_0x900011_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S622>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S622>/Data Type Conversion1'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrLOpen;

  /* CCaller: '<S622>/C Caller1' */
  App_Call_Event_DTC_0x900013_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S622>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S622>/Data Type Conversion2'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrRShort;

  /* CCaller: '<S622>/C Caller2' */
  App_Call_Event_DTC_0x900111_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S622>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S622>/Data Type Conversion3'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->TurnIndcrROpen;

  /* CCaller: '<S622>/C Caller3' */
  App_Call_Event_DTC_0x900113_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S622>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S622>/Data Type Conversion8'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->LowBeamShortToBat;

  /* CCaller: '<S622>/C Caller8' */
  App_Call_Event_DTC_0x900412_SetEventStatus(rtb_DataTypeConversion22);

  /* DataTypeConversion: '<S622>/Data Type Conversion22' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion22 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HiBeamShortToBat;

  /* CCaller: '<S622>/C Caller9' */
  App_Call_Event_DTC_0x900512_SetEventStatus(rtb_DataTypeConversion22);

  /* CCaller: '<S622>/C Caller10' */
  App_Call_Event_DTC_0x900711_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller11' */
  App_Call_Event_DTC_0x900811_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller12' */
  App_Call_Event_DTC_0x900923_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller13' */
  App_Call_Event_DTC_0x900924_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller14' */
  App_Call_Event_DTC_0x900A23_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller15' */
  App_Call_Event_DTC_0x900A24_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller16' */
  App_Call_Event_DTC_0x900B23_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller17' */
  App_Call_Event_DTC_0x900B24_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller18' */
  App_Call_Event_DTC_0x900C23_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller19' */
  App_Call_Event_DTC_0x900C24_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller20' */
  App_Call_Event_DTC_0x900D23_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller21' */
  App_Call_Event_DTC_0x900D24_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller22' */
  App_Call_Event_DTC_0x900E23_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller23' */
  App_Call_Event_DTC_0x900E24_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller24' */
  App_Call_Event_DTC_0x901016_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller25' */
  App_Call_Event_DTC_0x901031_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller27' */
  App_Call_Event_DTC_0x901231_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller29' */
  App_Call_Event_DTC_0x901331_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller30' */
  App_Call_Event_DTC_0x90141C_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller31' */
  App_Call_Event_DTC_0x901116_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller32' */
  App_Call_Event_DTC_0x901216_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller33' */
  App_Call_Event_DTC_0x901316_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller34' */
  App_Call_Event_DTC_0x901131_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller4' */
  App_Call_Event_DTC_0x900211_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller5' */
  App_Call_Event_DTC_0x900213_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller6' */
  App_Call_Event_DTC_0x900311_SetEventStatus(0U);

  /* CCaller: '<S622>/C Caller7' */
  App_Call_Event_DTC_0x900313_SetEventStatus(0U);
}

/* Function for Chart: '<S623>/DoorDrv' */
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

/* Function for Chart: '<S623>/DoorDrv' */
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

/* Function for Chart: '<S623>/DoorDrv' */
static void AppSwcBcm_InsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_i4 = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S656>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_i4,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mn,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ny);

  /* End of Outputs for SubSystem: '<S656>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_mn ||
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

/* Function for Chart: '<S623>/DoorDrv' */
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

/* Function for Chart: '<S623>/DoorDrv' */
static void AppSwcBcm_OsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_i4 = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S656>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_i4,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mn,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ny);

  /* End of Outputs for SubSystem: '<S656>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_mn ||
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

/* System initialize for atomic system: '<S623>/DoorDrv' */
static void AppSwcBcm_DoorDrv_Init(void)
{
  DoorLckCtl_TrunkLckSw = true;
}

/* Output and update for atomic system: '<S623>/DoorDrv' */
static void AppSwcBcm_DoorDrv(void)
{
  boolean tmp;

  /* Chart: '<S623>/DoorDrv' incorporates:
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

  /* End of Chart: '<S623>/DoorDrv' */
}

/* System initialize for atomic system: '<S623>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j0;

  /* InitializeConditions for Delay: '<S666>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_f = true;

  /* InitializeConditions for UnitDelay: '<S666>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h = 1U;

  /* InitializeConditions for Delay: '<S674>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_o = true;

  /* InitializeConditions for Delay: '<S667>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ox = true;

  /* InitializeConditions for UnitDelay: '<S667>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 1U;

  /* SystemInitialize for Chart: '<S680>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_h);

  /* SystemInitialize for Chart: '<S680>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_po);

  /* SystemInitialize for Chart: '<S692>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_p);

  /* SystemInitialize for Chart: '<S710>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_j0);

  /* SystemInitialize for Chart: '<S711>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_a);

  /* SystemInitialize for Chart: '<S733>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_o);

  /* SystemInitialize for Chart: '<S736>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_b);
}

/* Output and update for atomic system: '<S623>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_j0;
  sint32 tmp;
  uint8 rtb_Switch;
  boolean DoorLckCtl_PELck_tmp;
  boolean guard1 = false;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_cm3_tmp;
  boolean rtb_LogicalOperator5_na;
  boolean rtb_LogicalOperator_co;
  boolean rtb_LogicalOperator_cs;
  boolean rtb_LogicalOperator_ia;
  boolean rtb_LogicalOperator_id;
  boolean rtb_LogicalOperator_mx;
  boolean rtb_LogicalOperator_ph0;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator2_mr;
  boolean rtb_RelationalOperator5_ft;
  boolean rtb_RelationalOperator6_p;
  boolean rtb_UnitDelay_j;

  /* Logic: '<S664>/Logical Operator2' incorporates:
   *  Logic: '<S710>/Logical Operator'
   *  RelationalOperator: '<S664>/Relational Operator2'
   *  RelationalOperator: '<S664>/Relational Operator3'
   *  RelationalOperator: '<S664>/Relational Operator4'
   */
  rtb_RelationalOperator6_p = ((!DoorLckCtl_DoorAjarFLSw) ||
    (!DoorLckCtl_DoorAjarFRSw) || (!DoorLckCtl_DoorAjarRRSw));

  /* RelationalOperator: '<S679>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_mr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S679>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator2_mr,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jz);

  /* End of Outputs for SubSystem: '<S679>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S679>/Relational Operator1' incorporates:
   *  RelationalOperator: '<S680>/Relational Operator2'
   *  RelationalOperator: '<S712>/Relational Operator2'
   *  RelationalOperator: '<S715>/Relational Operator4'
   */
  rtb_LogicalOperator_mx = !DoorLckCtl_DriverDoorLckSw;

  /* Logic: '<S679>/Logical Operator2' incorporates:
   *  Constant: '<S679>/Constant1'
   *  RelationalOperator: '<S679>/Relational Operator'
   *  RelationalOperator: '<S679>/Relational Operator1'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  DoorLckCtl_HULck = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) &&
                      rtb_LogicalOperator && rtb_LogicalOperator_mx);

  /* RelationalOperator: '<S736>/Relational Operator5' incorporates:
   *  Constant: '<S664>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S664>/Relational Operator6'
   */
  rtb_RelationalOperator5_ft =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  Constant: '<S664>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S664>/Relational Operator5'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S664>/Logical Operator5' */
  rtb_LogicalOperator5_na = (rtb_RelationalOperator5_ft || rtb_UnitDelay_j);

  /* RelationalOperator: '<S713>/Relational Operator' incorporates:
   *  Constant: '<S713>/Constant'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  rtb_RelationalOperator2_mr = (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 2);

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  Constant: '<S713>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S713>/Relational Operator1'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S736>/Relational Operator5' incorporates:
   *  Constant: '<S713>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S713>/Relational Operator2'
   */
  rtb_RelationalOperator5_ft =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S713>/Relational Operator3' incorporates:
   *  RelationalOperator: '<S711>/Relational Operator6'
   *  RelationalOperator: '<S712>/Relational Operator3'
   *  RelationalOperator: '<S715>/Relational Operator9'
   */
  rtb_LogicalOperator1_cm3_tmp = !DoorLckCtl_DrvSeatSw;

  /* Logic: '<S713>/Logical Operator1' incorporates:
   *  Logic: '<S713>/Logical Operator3'
   *  RelationalOperator: '<S713>/Relational Operator3'
   */
  rtb_UnitDelay_j = (rtb_LogicalOperator1_cm3_tmp && rtb_RelationalOperator2_mr &&
                     (rtb_UnitDelay_j || rtb_RelationalOperator5_ft));

  /* Outputs for Atomic SubSystem: '<S713>/Lib_RiseEdgeDet' */
  /* Logic: '<S725>/Logical Operator' incorporates:
   *  Logic: '<S725>/Logical Operator1'
   *  UnitDelay: '<S725>/Unit Delay'
   */
  DoorLckCtl_RKELck = (rtb_UnitDelay_j &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b));

  /* Update for UnitDelay: '<S725>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b = rtb_UnitDelay_j;

  /* End of Outputs for SubSystem: '<S713>/Lib_RiseEdgeDet' */

  /* Logic: '<S664>/Logical Operator1' incorporates:
   *  Logic: '<S664>/Logical Operator2'
   */
  DoorLckCtl_RKEAntiLck = (rtb_LogicalOperator5_na && rtb_RelationalOperator6_p &&
    DoorLckCtl_RKELck);

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  Constant: '<S711>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S711>/Relational Operator1'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S736>/Relational Operator5' incorporates:
   *  Constant: '<S711>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S711>/Relational Operator'
   */
  rtb_RelationalOperator5_ft =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Chart: '<S711>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S711>/Constant40'
   *  Constant: '<S711>/Constant41'
   *  Constant: '<S711>/Constant42'
   *  Logic: '<S711>/Logical Operator1'
   *  RelationalOperator: '<S711>/Relational Operator2'
   *  RelationalOperator: '<S711>/Relational Operator3'
   *  RelationalOperator: '<S711>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 1,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms);

  /* Logic: '<S711>/Logical Operator3' incorporates:
   *  Logic: '<S711>/Logical Operator'
   *  UnitDelay: '<S711>/Unit Delay'
   */
  DoorLckCtl_MechLck = (rtb_LogicalOperator1_cm3_tmp && (rtb_UnitDelay_j ||
    rtb_RelationalOperator5_ft) && AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ls &&
                        AppSwcBcm_ARID_DEF.LIB_bErrFlg_a);

  /* Logic: '<S664>/Logical Operator3' incorporates:
   *  Logic: '<S664>/Logical Operator2'
   */
  DoorLckCtl_MechAntiLck = (DoorLckCtl_MechLck && rtb_RelationalOperator6_p);

  /* Logic: '<S664>/Logical Operator4' incorporates:
   *  Constant: '<S664>/Constant1'
   *  Logic: '<S664>/Logical Operator'
   *  Logic: '<S664>/Logical Operator2'
   *  RelationalOperator: '<S664>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_p = (DoorLckCtl_RKEAntiLck || (DoorLckCtl_HULck &&
    (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) && rtb_RelationalOperator6_p) ||
    DoorLckCtl_MechAntiLck);

  /* Chart: '<S664>/LIB_Tim' incorporates:
   *  SubSystem: '<S676>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_p,
    &AppSwcBcm_ARID_DEF.LogicalOperator_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o4);
  AppSwcBcm_ARID_DEF.TempEn = (AppSwcBcm_ARID_DEF.LogicalOperator_l ||
    AppSwcBcm_ARID_DEF.TempEn);
  if (AppSwcBcm_ARID_DEF.TempEn) {
    /* Constant: '<S664>/Constant' */
    if (AppSwcBcm_ARID_DEF.Cnt_lh <= DoorLckCtl_AntiLckProtTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_lh + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_lh + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_lh = (uint16)tmp;
      DoorLckCtl_DoorProtUnlck = false;
    } else {
      DoorLckCtl_DoorProtUnlck = true;
      AppSwcBcm_ARID_DEF.TempEn = false;
    }

    /* End of Constant: '<S664>/Constant' */
  } else {
    DoorLckCtl_DoorProtUnlck = false;
    AppSwcBcm_ARID_DEF.Cnt_lh = 0U;
    AppSwcBcm_ARID_DEF.TempEn = false;
  }

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  Constant: '<S673>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   *  RelationalOperator: '<S673>/Relational Operator2'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
                     ->DrvPEAuthentAcsd == 1);

  /* RelationalOperator: '<S736>/Relational Operator5' incorporates:
   *  Constant: '<S673>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   *  RelationalOperator: '<S673>/Relational Operator6'
   */
  rtb_RelationalOperator5_ft = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->FRPEAuthentAcsd == 1);

  /* Logic: '<S673>/Logical Operator1' incorporates:
   *  Constant: '<S673>/Constant5'
   *  Logic: '<S673>/Logical Operator'
   *  Logic: '<S673>/Logical Operator3'
   *  RelationalOperator: '<S673>/Relational Operator'
   *  RelationalOperator: '<S673>/Relational Operator1'
   *  RelationalOperator: '<S673>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_ha = ((DoorLckCtl_DrvPESw || DoorLckCtl_PsgPESw) &&
    (rtb_UnitDelay_j || rtb_RelationalOperator5_ft) && (DoorLckCtl_EEKeyEntry ==
    1));

  /* Chart: '<S673>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S748>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ha,
    &AppSwcBcm_ARID_DEF.LogicalOperator_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gu);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_g) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_j + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_j + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_j = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_j = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_j + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_j + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_j = (uint16)tmp;
  }

  /* Constant: '<S673>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt2_j >= DoorLckCtl_PEProtIntvlTim_C) {
    AppSwcBcm_ARID_DEF.Cnt_j = 0U;
    AppSwcBcm_ARID_DEF.LIB_blOut_c = false;
  }

  /* End of Constant: '<S673>/Constant2' */

  /* Constant: '<S673>/Constant3' */
  AppSwcBcm_ARID_DEF.LIB_blOut_c = ((AppSwcBcm_ARID_DEF.Cnt_j >=
    DoorLckCtl_PEProtCnt_C) || AppSwcBcm_ARID_DEF.LIB_blOut_c);

  /* Outputs for Atomic SubSystem: '<S673>/Lib_RiseEdgeDet' */
  /* Switch: '<S673>/Switch' */
  rtb_LogicalOperator_id = AppSwcBcm_Lib_RiseEdgeDet
    ((!AppSwcBcm_ARID_DEF.LIB_blOut_c) && AppSwcBcm_ARID_DEF.Lib_blIn_ha,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);

  /* End of Outputs for SubSystem: '<S673>/Lib_RiseEdgeDet' */

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  Constant: '<S712>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S712>/Relational Operator4'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S736>/Relational Operator5' incorporates:
   *  Constant: '<S712>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S712>/Relational Operator5'
   */
  rtb_RelationalOperator5_ft =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S712>/Logical Operator3' incorporates:
   *  Logic: '<S715>/Logical Operator'
   */
  DoorLckCtl_PELck_tmp = (DoorLckCtl_DoorAjarFLSw && DoorLckCtl_DoorAjarFRSw &&
    DoorLckCtl_DoorAjarRRSw);

  /* Logic: '<S712>/Logical Operator1' incorporates:
   *  Logic: '<S712>/Logical Operator2'
   *  Logic: '<S712>/Logical Operator3'
   *  RelationalOperator: '<S712>/Relational Operator1'
   */
  DoorLckCtl_PELck = (rtb_LogicalOperator_id && rtb_LogicalOperator_mx &&
                      rtb_LogicalOperator1_cm3_tmp && (rtb_UnitDelay_j ||
    rtb_RelationalOperator5_ft) && DoorLckCtl_PELck_tmp);

  /* Logic: '<S710>/Logical Operator5' incorporates:
   *  Constant: '<S710>/Constant13'
   *  Constant: '<S710>/Constant14'
   *  Constant: '<S710>/Constant15'
   *  Logic: '<S710>/Logical Operator4'
   *  RelationalOperator: '<S710>/Relational Operator10'
   *  RelationalOperator: '<S710>/Relational Operator11'
   *  RelationalOperator: '<S710>/Relational Operator12'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_RelationalOperator5_ft = (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Outputs for Atomic SubSystem: '<S710>/Lib_ChangeEdge' */
  /* RelationalOperator: '<S717>/Relational Operator' incorporates:
   *  Constant: '<S710>/Constant8'
   *  UnitDelay: '<S717>/Unit Delay'
   */
  rtb_RelationalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g == 1);

  /* Update for UnitDelay: '<S717>/Unit Delay' incorporates:
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g = AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a;

  /* End of Outputs for SubSystem: '<S710>/Lib_ChangeEdge' */

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S710>/Relational Operator9'
   */
  rtb_UnitDelay_j = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* RelationalOperator: '<S710>/Relational Operator5' incorporates:
   *  Logic: '<S714>/Logical Operator'
   */
  rtb_LogicalOperator5_na = !DoorLckCtl_TrunkAjarSw;

  /* Outputs for Atomic SubSystem: '<S710>/Lib_SR' */
  /* Switch: '<S719>/Switch' incorporates:
   *  Constant: '<S710>/Constant11'
   *  Logic: '<S710>/Logical Operator'
   *  Logic: '<S710>/Logical Operator2'
   *  Logic: '<S710>/Logical Operator3'
   *  Logic: '<S710>/Logical Operator7'
   *  RelationalOperator: '<S710>/Relational Operator13'
   *  RelationalOperator: '<S710>/Relational Operator5'
   *  RelationalOperator: '<S710>/Relational Operator8'
   *  UnitDelay: '<S671>/Unit Delay'
   */
  if (rtb_RelationalOperator6_p || rtb_LogicalOperator5_na ||
      (!AppSwcBcm_ConstB.RelationalOperator6) || ((AppSwcBcm_ARID_DEF.UnitDelay2
        != 0) && (!rtb_RelationalOperator5_ft)) || rtb_UnitDelay_j ||
      DoorLckCtl_OsLck) {
    /* Switch: '<S719>/Switch' incorporates:
     *  Constant: '<S719>/Constant'
     */
    DoorLckCtl_AutoLckSta = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S710>/Lib_ChangeEdge' */
    /* Switch: '<S719>/Switch' incorporates:
     *  Constant: '<S710>/Constant'
     *  Constant: '<S710>/Constant1'
     *  Logic: '<S710>/Logical Operator1'
     *  Logic: '<S710>/Logical Operator6'
     *  Logic: '<S717>/Logical Operator'
     *  Logic: '<S719>/Logical Operator'
     *  RelationalOperator: '<S710>/Relational Operator'
     *  RelationalOperator: '<S717>/Relational Operator1'
     *  UnitDelay: '<S4>/Unit Delay1'
     *  UnitDelay: '<S719>/Unit Delay'
     */
    DoorLckCtl_AutoLckSta = (((rtb_RelationalOperator5_ft ||
      (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) &&
      ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) && rtb_RelationalOperator))
      || DoorLckCtl_AutoLckSta);

    /* End of Outputs for SubSystem: '<S710>/Lib_ChangeEdge' */
  }

  /* End of Switch: '<S719>/Switch' */
  /* End of Outputs for SubSystem: '<S710>/Lib_SR' */

  /* Chart: '<S710>/LIB_PosPluse2' incorporates:
   *  Constant: '<S710>/Constant7'
   *  UnitDelay: '<S657>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(DoorLckCtl_AutoLckSta, DoorLckCtl_AutoLckDelayTim_C,
    DoorLckCtl_OsUnlck, &rtb_LIB_blOut_j0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2);

  /* Outputs for Atomic SubSystem: '<S710>/Lib_RiseEdgeDet' */
  /* Logic: '<S718>/Logical Operator' incorporates:
   *  Logic: '<S718>/Logical Operator1'
   *  UnitDelay: '<S718>/Unit Delay'
   */
  DoorLckCtl_AutoLck = (rtb_LIB_blOut_j0 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mi));

  /* Update for UnitDelay: '<S718>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mi = rtb_LIB_blOut_j0;

  /* End of Outputs for SubSystem: '<S710>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S715>/Relational Operator10' incorporates:
   *  Constant: '<S715>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
                     ->LckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S715>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_co = AppSwcBcm_Lib_RiseEdgeDet(rtb_UnitDelay_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_lx);

  /* End of Outputs for SubSystem: '<S715>/Lib_RiseEdgeDet' */

  /* Delay: '<S666>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_f) {
    /* Switch: '<S666>/Switch1' incorporates:
     *  Constant: '<S666>/Constant7'
     *  Constant: '<S666>/Constant8'
     *  RelationalOperator: '<S666>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts;
    }

    /* End of Switch: '<S666>/Switch1' */
  }

  /* Switch: '<S666>/Switch' incorporates:
   *  Constant: '<S666>/Constant5'
   *  RelationalOperator: '<S666>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S666>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndLckSts_enum;
  } else {
    /* Switch: '<S666>/Switch' incorporates:
     *  Constant: '<S666>/Constant6'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S666>/Switch' */

  /* MultiPortSwitch: '<S666>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S666>/Multiport Switch' incorporates:
     *  Constant: '<S666>/Constant1'
     */
    DoorLckCtl_IllmndLckSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S666>/Multiport Switch' incorporates:
     *  Constant: '<S666>/Constant2'
     */
    DoorLckCtl_IllmndLckSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S666>/Multiport Switch' incorporates:
     *  Delay: '<S666>/Delay'
     */
    DoorLckCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.Delay_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S666>/Multiport Switch' */

  /* MultiPortSwitch: '<S666>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndLckSts) {
   case 1:
    /* MultiPortSwitch: '<S666>/Multiport Switch1' incorporates:
     *  Constant: '<S666>/Constant3'
     */
    DoorLckCtl_IllmndLckStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S666>/Multiport Switch1' incorporates:
     *  Constant: '<S666>/Constant4'
     */
    DoorLckCtl_IllmndLckStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S666>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S666>/Unit Delay'
     */
    DoorLckCtl_IllmndLckStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h;
    break;
  }

  /* End of MultiPortSwitch: '<S666>/Multiport Switch1' */

  /* RelationalOperator: '<S736>/Relational Operator6' incorporates:
   *  Constant: '<S715>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S715>/Relational Operator2'
   */
  rtb_RelationalOperator6_p =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* UnitDelay: '<S733>/Unit Delay' incorporates:
   *  Constant: '<S715>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S715>/Relational Operator3'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S715>/Logical Operator2' incorporates:
   *  Constant: '<S715>/Constant10'
   *  Logic: '<S715>/Logical Operator1'
   *  Logic: '<S715>/Logical Operator3'
   *  RelationalOperator: '<S715>/Relational Operator'
   *  RelationalOperator: '<S715>/Relational Operator1'
   *  RelationalOperator: '<S715>/Relational Operator8'
   */
  DoorLckCtl_WelcomeLck = (rtb_LogicalOperator_co && ((DoorLckCtl_IllmndLckStsFb
    == 1) && (DoorLckCtl_EEIlluminatedEntrySys == 1) &&
    (rtb_RelationalOperator6_p || rtb_UnitDelay_j) && rtb_LogicalOperator_mx &&
    DoorLckCtl_PELck_tmp && (DoorLckCtl_IllmndSts == 1) &&
    rtb_LogicalOperator1_cm3_tmp));

  /* Chart: '<S736>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S736>/Constant'
   *  Constant: '<S736>/Constant2'
   *  Constant: '<S736>/Constant3'
   *  Constant: '<S736>/Constant4'
   *  RelationalOperator: '<S736>/Relational Operator'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  AppSwcBcm_LIB_TPD_10ms1(AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 3,
    DoorLckCtl_TrunkUnlckTimValid_C, DoorLckCtl_TrunkUnlckTimInvalid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1);

  /* Logic: '<S736>/Logical Operator1' incorporates:
   *  Constant: '<S736>/Constant6'
   *  RelationalOperator: '<S736>/Relational Operator3'
   */
  rtb_UnitDelay_j = ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
                     AppSwcBcm_ARID_DEF.LIB_bErrFlg_b && DoorLckCtl_VehStop);

  /* Outputs for Atomic SubSystem: '<S736>/Lib_RiseEdgeDet1' */
  /* Logic: '<S745>/Logical Operator' incorporates:
   *  Logic: '<S745>/Logical Operator1'
   *  UnitDelay: '<S745>/Unit Delay'
   */
  DoorLckCtl_TrunkRKEUnlck = (rtb_UnitDelay_j &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nd));

  /* Update for UnitDelay: '<S745>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nd = rtb_UnitDelay_j;

  /* End of Outputs for SubSystem: '<S736>/Lib_RiseEdgeDet1' */

  /* UnitDelay: '<S714>/Unit Delay' incorporates:
   *  Constant: '<S736>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S736>/Relational Operator1'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
                     ->VIPM_HUTrnkLckSwCtrl_enum == 1);

  /* RelationalOperator: '<S736>/Relational Operator5' incorporates:
   *  Constant: '<S736>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_ft =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S736>/Relational Operator6' incorporates:
   *  Constant: '<S736>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator6_p =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S736>/Logical Operator3' incorporates:
   *  Constant: '<S736>/Constant5'
   *  Constant: '<S736>/Constant7'
   *  Logic: '<S736>/Logical Operator2'
   *  RelationalOperator: '<S736>/Relational Operator2'
   *  RelationalOperator: '<S736>/Relational Operator4'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  rtb_UnitDelay_j = (DoorLckCtl_VehStop && rtb_UnitDelay_j &&
                     (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0) &&
                     (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) &&
                     (rtb_RelationalOperator5_ft || rtb_RelationalOperator6_p));

  /* Outputs for Atomic SubSystem: '<S736>/Lib_RiseEdgeDet2' */
  /* Logic: '<S746>/Logical Operator' incorporates:
   *  Logic: '<S746>/Logical Operator1'
   *  UnitDelay: '<S746>/Unit Delay'
   */
  DoorLckCtl_TrunkHUUnlck = (rtb_UnitDelay_j &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dw));

  /* Update for UnitDelay: '<S746>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dw = rtb_UnitDelay_j;

  /* End of Outputs for SubSystem: '<S736>/Lib_RiseEdgeDet2' */

  /* Logic: '<S736>/Logical Operator' */
  DoorLckCtl_TrunkUnlck = (DoorLckCtl_TrunkRKEUnlck || DoorLckCtl_TrunkHUUnlck);

  /* RelationalOperator: '<S714>/Relational Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_o = DoorLckCtl_TrunkUnlck;

  /* Chart: '<S714>/LIB_PosPluse1' incorporates:
   *  SubSystem: '<S728>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_o,
    &AppSwcBcm_ARID_DEF.LogicalOperator_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_m) {
    AppSwcBcm_ARID_DEF.Flg_j = true;
    AppSwcBcm_ARID_DEF.Cnt_nz = 0U;
  }

  /* Logic: '<S714>/Logical Operator2' incorporates:
   *  UnitDelay: '<S714>/Unit Delay'
   */
  if (rtb_LogicalOperator5_na || DoorLckCtl_TrunkAutoLck) {
    AppSwcBcm_ARID_DEF.Flg_j = false;
    AppSwcBcm_ARID_DEF.Cnt_nz = 0U;
  }

  /* End of Logic: '<S714>/Logical Operator2' */
  if (AppSwcBcm_ARID_DEF.Flg_j) {
    /* Constant: '<S714>/Constant1' */
    if (AppSwcBcm_ARID_DEF.Cnt_nz >= DoorLckCtl_TrunkAutoLckTim_C) {
      rtb_UnitDelay_j = true;
      AppSwcBcm_ARID_DEF.Flg_j = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_nz + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_nz + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_nz = (uint16)tmp;
      rtb_UnitDelay_j = false;
    }

    /* End of Constant: '<S714>/Constant1' */
  } else {
    rtb_UnitDelay_j = false;
    AppSwcBcm_ARID_DEF.Cnt_nz = 0U;
  }

  /* Logic: '<S714>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S714>/Relational Operator3'
   */
  rtb_UnitDelay_j = (DoorLckCtl_TrunkAjarSw && rtb_UnitDelay_j);

  /* Outputs for Atomic SubSystem: '<S714>/Lib_RiseEdgeDet' */
  /* Logic: '<S729>/Logical Operator' incorporates:
   *  Logic: '<S729>/Logical Operator1'
   *  UnitDelay: '<S729>/Unit Delay'
   */
  DoorLckCtl_TrunkAutoLck = (rtb_UnitDelay_j &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i4));

  /* Update for UnitDelay: '<S729>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i4 = rtb_UnitDelay_j;

  /* End of Outputs for SubSystem: '<S714>/Lib_RiseEdgeDet' */

  /* Logic: '<S671>/Logical Operator' */
  DoorLckCtl_OsLck = (DoorLckCtl_MechLck || DoorLckCtl_PELck ||
                      DoorLckCtl_AutoLck || DoorLckCtl_WelcomeLck ||
                      DoorLckCtl_RKELck || DoorLckCtl_TrunkAutoLck);

  /* Chart: '<S680>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S680>/Constant10'
   *  Constant: '<S680>/Constant11'
   *  Constant: '<S680>/Constant9'
   *  Logic: '<S680>/Logical Operator1'
   *  RelationalOperator: '<S680>/Relational Operator3'
   *  RelationalOperator: '<S680>/Relational Operator4'
   *  RelationalOperator: '<S680>/Relational Operator5'
   *  RelationalOperator: '<S680>/Relational Operator7'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarFLSw &&
    DoorLckCtl_DoorAjarRRSw && DoorLckCtl_TrunkAjarSw,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_po,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_j);

  /* Chart: '<S680>/Chart' */
  if (DoorLckCtl_DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.Lib_blIn_hq = DoorLckCtl_DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S682>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_hq,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ja,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_j);

    /* End of Outputs for SubSystem: '<S682>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ja) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_oj = DoorLckCtl_DoorAjarRRSw;

      /* Outputs for Function Call SubSystem: '<S682>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_oj,
        &AppSwcBcm_ARID_DEF.LogicalOperator_i,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_a);

      /* End of Outputs for SubSystem: '<S682>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_i) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_hb = DoorLckCtl_TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S682>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_hb,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jh,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

        /* End of Outputs for SubSystem: '<S682>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_jh) {
          guard1 = true;
        }
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Door_Change = true;
      AppSwcBcm_ARID_DEF.Cnt_et = 0U;
    }
  }

  if (AppSwcBcm_ARID_DEF.Door_Change) {
    if (AppSwcBcm_ARID_DEF.Cnt_et >= 40) {
      AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = true;
      AppSwcBcm_ARID_DEF.Door_Change = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_et + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_et + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_et = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = false;
  }

  /* End of Chart: '<S680>/Chart' */

  /* Chart: '<S680>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S680>/Constant'
   *  Constant: '<S680>/Constant2'
   *  Constant: '<S680>/Constant3'
   *  Constant: '<S680>/Constant49'
   *  RelationalOperator: '<S680>/Relational Operator'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_VehSpd >= DoorLckCtl_SpdLck_C,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_f);

  /* Logic: '<S680>/Logical Operator' incorporates:
   *  Constant: '<S680>/Constant8'
   *  Logic: '<S680>/Logical Operator2'
   *  RelationalOperator: '<S680>/Relational Operator6'
   */
  rtb_LogicalOperator_mx = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_po &&
    (rtb_LogicalOperator_mx || AppSwcBcm_ARID_DEF.DoorLckCtl_Lck) &&
    AppSwcBcm_ConstB.RelationalOperator1 && AppSwcBcm_ARID_DEF.LIB_bErrFlg_h &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2));

  /* Logic: '<S685>/Logical Operator' incorporates:
   *  Logic: '<S685>/Logical Operator1'
   *  UnitDelay: '<S685>/Unit Delay'
   */
  DoorLckCtl_SpdLck = (rtb_LogicalOperator_mx &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n5));

  /* Logic: '<S668>/Logical Operator' */
  DoorLckCtl_InsLck = (DoorLckCtl_HULck || DoorLckCtl_SpdLck);

  /* UnitDelay: '<S733>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S692>/Relational Operator'
   */
  rtb_UnitDelay_j = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->CrashSta;

  /* Chart: '<S692>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S692>/Constant2'
   *  Constant: '<S692>/Constant3'
   *  Constant: '<S692>/Constant4'
   *  Constant: '<S692>/Constant6'
   *  RelationalOperator: '<S692>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD_10ms1(AppSwcBcm_ARID_DEF.UnitDelay2 == 2,
    DoorLckCtl_CrshPwrOnTimValid_C, DoorLckCtl_CrshPwrOnTimInValid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_e);

  /* Logic: '<S692>/Logical Operator1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_d = (rtb_UnitDelay_j &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_p);

  /* Chart: '<S692>/Chart' incorporates:
   *  SubSystem: '<S696>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_d,
    &AppSwcBcm_ARID_DEF.LogicalOperator_h,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_bj);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_h) {
    AppSwcBcm_ARID_DEF.Flg_n = true;
    DoorLckCtl_CrshUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_e5 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_n) {
    if (AppSwcBcm_ARID_DEF.Cnt_e5 >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_e5 >= 20) {
        DoorLckCtl_CrshUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_n = false;
      } else {
        DoorLckCtl_CrshUnlck = false;
        tmp = AppSwcBcm_ARID_DEF.Cnt_e5 + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_e5 + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_e5 = (uint16)tmp;
      }
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_e5 + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_e5 + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_e5 = (uint16)tmp;
    }
  } else {
    DoorLckCtl_CrshUnlck = false;
  }

  /* RelationalOperator: '<S693>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_UnitDelay_j = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S693>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_ia = AppSwcBcm_Lib_RiseEdgeDet(rtb_UnitDelay_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_da);

  /* End of Outputs for SubSystem: '<S693>/Lib_RiseEdgeDet' */

  /* Logic: '<S693>/Logical Operator' incorporates:
   *  Constant: '<S693>/Constant2'
   *  RelationalOperator: '<S693>/Relational Operator'
   *  RelationalOperator: '<S693>/Relational Operator2'
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  DoorLckCtl_HUUnLck = (rtb_LogicalOperator_ia && DoorLckCtl_DriverDoorLckSw &&
                        (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_a == 0));

  /* Switch: '<S674>/Switch1' incorporates:
   *  Constant: '<S674>/Constant1'
   *  RelationalOperator: '<S674>/Relational Operator1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S674>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUParkAutoUnlckSet_enum;
  } else {
    /* Switch: '<S674>/Switch1' incorporates:
     *  Constant: '<S674>/Constant4'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S674>/Switch1' */

  /* Delay: '<S674>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_o) {
    /* Switch: '<S674>/Switch2' incorporates:
     *  Constant: '<S674>/Constant5'
     *  Constant: '<S674>/Constant6'
     *  RelationalOperator: '<S674>/Relational Operator3'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_l = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_l =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb;
    }

    /* End of Switch: '<S674>/Switch2' */
  }

  /* MultiPortSwitch: '<S674>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant2'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Constant: '<S674>/Constant3'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S674>/Multiport Switch' incorporates:
     *  Delay: '<S674>/Delay'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_l;
    break;
  }

  /* End of MultiPortSwitch: '<S674>/Multiport Switch' */

  /* RelationalOperator: '<S694>/Relational Operator3' incorporates:
   *  Constant: '<S694>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S694>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_cs = AppSwcBcm_Lib_RiseEdgeDet(rtb_UnitDelay_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_bn);

  /* End of Outputs for SubSystem: '<S694>/Lib_RiseEdgeDet' */

  /* Logic: '<S694>/Logical Operator' incorporates:
   *  Constant: '<S694>/Constant'
   *  Constant: '<S694>/Constant1'
   *  RelationalOperator: '<S694>/Relational Operator'
   *  RelationalOperator: '<S694>/Relational Operator1'
   *  RelationalOperator: '<S694>/Relational Operator2'
   */
  DoorLckCtl_ParkUnlck = ((DoorLckCtl_ParkAutoUnlockSetFb == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) && DoorLckCtl_DriverDoorLckSw &&
    DoorLckCtl_VehStop && rtb_LogicalOperator_cs);

  /* UnitDelay: '<S733>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S695>/Relational Operator'
   */
  rtb_UnitDelay_j = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->ThermalrunawaySta;

  /* Logic: '<S695>/Logical Operator2' incorporates:
   *  Constant: '<S695>/Constant1'
   *  Constant: '<S695>/Constant2'
   *  Logic: '<S695>/Logical Operator'
   *  Logic: '<S695>/Logical Operator1'
   *  RelationalOperator: '<S695>/Relational Operator1'
   *  RelationalOperator: '<S695>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_j4 = (rtb_UnitDelay_j &&
    ((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) || ((AppSwcBcm_ARID_DEF.UnitDelay2 ==
    2) && DoorLckCtl_VehStop)));

  /* Chart: '<S695>/Chart' incorporates:
   *  SubSystem: '<S702>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_j4,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mf,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_mf) {
    AppSwcBcm_ARID_DEF.Flg_pz = true;
    DoorLckCtl_ThermRunawayUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_o = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_pz) {
    if (AppSwcBcm_ARID_DEF.Cnt_o >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_o >= 20) {
        DoorLckCtl_ThermRunawayUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_pz = false;
      } else {
        DoorLckCtl_ThermRunawayUnlck = false;
        tmp = AppSwcBcm_ARID_DEF.Cnt_o + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_o + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_o = (uint16)tmp;
      }
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_o + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_o + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_o = (uint16)tmp;
    }
  } else {
    DoorLckCtl_ThermRunawayUnlck = false;
  }

  /* Logic: '<S669>/Logical Operator' */
  DoorLckCtl_InsUnlck = (DoorLckCtl_HUUnLck || DoorLckCtl_ParkUnlck ||
    DoorLckCtl_ThermRunawayUnlck || DoorLckCtl_CrshUnlck);

  /* RelationalOperator: '<S735>/Relational Operator' incorporates:
   *  Constant: '<S735>/Constant'
   *  UnitDelay: '<S4>/Unit Delay5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_a = (AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE == 1);

  /* Logic: '<S735>/Logical Operator4' incorporates:
   *  Constant: '<S735>/Constant1'
   *  Constant: '<S735>/Constant2'
   *  Constant: '<S735>/Constant3'
   *  Constant: '<S735>/Constant4'
   *  Constant: '<S735>/Constant5'
   *  Constant: '<S735>/Constant6'
   *  Logic: '<S735>/Logical Operator'
   *  Logic: '<S735>/Logical Operator1'
   *  Logic: '<S735>/Logical Operator2'
   *  Logic: '<S735>/Logical Operator3'
   *  RelationalOperator: '<S735>/Relational Operator1'
   *  RelationalOperator: '<S735>/Relational Operator2'
   *  RelationalOperator: '<S735>/Relational Operator3'
   *  RelationalOperator: '<S735>/Relational Operator4'
   *  RelationalOperator: '<S735>/Relational Operator5'
   *  RelationalOperator: '<S735>/Relational Operator6'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  rtb_UnitDelay_j = (AppSwcBcm_ARID_DEF.Lib_blIn_a &&
                     (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay2 == 0)) ||
                      (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
                        (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3) ||
                        (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2)) &&
                       (AppSwcBcm_ARID_DEF.UnitDelay2 == 2))));

  /* Outputs for Atomic SubSystem: '<S735>/Lib_RiseEdgeDet' */
  /* Logic: '<S741>/Logical Operator' incorporates:
   *  Logic: '<S741>/Logical Operator1'
   *  UnitDelay: '<S741>/Unit Delay'
   */
  DoorLckCtl_RKEUnlck = (rtb_UnitDelay_j &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p));

  /* Update for UnitDelay: '<S741>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_p = rtb_UnitDelay_j;

  /* End of Outputs for SubSystem: '<S735>/Lib_RiseEdgeDet' */

  /* UnitDelay: '<S733>/Unit Delay' incorporates:
   *  Constant: '<S734>/Constant5'
   *  RelationalOperator: '<S734>/Relational Operator7'
   */
  rtb_UnitDelay_j = (AppSwcBcm_ARID_DEF.UnitDelay2 == 2);

  /* Logic: '<S734>/Logical Operator1' incorporates:
   *  Constant: '<S734>/Constant2'
   *  Constant: '<S734>/Constant3'
   *  Constant: '<S734>/Constant4'
   *  Constant: '<S734>/Constant7'
   *  Constant: '<S734>/Constant8'
   *  Logic: '<S734>/Logical Operator2'
   *  Logic: '<S734>/Logical Operator3'
   *  Logic: '<S734>/Logical Operator4'
   *  Logic: '<S734>/Logical Operator5'
   *  Logic: '<S734>/Logical Operator6'
   *  RelationalOperator: '<S734>/Relational Operator1'
   *  RelationalOperator: '<S734>/Relational Operator2'
   *  RelationalOperator: '<S734>/Relational Operator3'
   *  RelationalOperator: '<S734>/Relational Operator4'
   *  RelationalOperator: '<S734>/Relational Operator5'
   *  RelationalOperator: '<S734>/Relational Operator6'
   *  RelationalOperator: '<S734>/Relational Operator8'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  DoorLckCtl_PEUnlck = (rtb_LogicalOperator_id && DoorLckCtl_DriverDoorLckSw &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay2 == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 0)) ||
    (((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 5) ||
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 3)) && rtb_UnitDelay_j) ||
    (rtb_UnitDelay_j && (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d == 2))));

  /* RelationalOperator: '<S737>/Relational Operator4' incorporates:
   *  Constant: '<S737>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_UnitDelay_j = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
                     ->UnlckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S737>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_ph0 = AppSwcBcm_Lib_RiseEdgeDet(rtb_UnitDelay_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l);

  /* End of Outputs for SubSystem: '<S737>/Lib_RiseEdgeDet' */

  /* Delay: '<S667>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_ox) {
    /* Switch: '<S667>/Switch1' incorporates:
     *  Constant: '<S667>/Constant7'
     *  Constant: '<S667>/Constant8'
     *  RelationalOperator: '<S667>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_lf = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_lf =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts;
    }

    /* End of Switch: '<S667>/Switch1' */
  }

  /* Switch: '<S667>/Switch' incorporates:
   *  Constant: '<S667>/Constant5'
   *  RelationalOperator: '<S667>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2 == 2) {
    /* Switch: '<S667>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndUnlckSts_enum;
  } else {
    /* Switch: '<S667>/Switch' incorporates:
     *  Constant: '<S667>/Constant6'
     */
    rtb_Switch = 0U;
  }

  /* End of Switch: '<S667>/Switch' */

  /* MultiPortSwitch: '<S667>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S667>/Multiport Switch' incorporates:
     *  Constant: '<S667>/Constant1'
     */
    DoorLckCtl_IllmndUnlockSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S667>/Multiport Switch' incorporates:
     *  Constant: '<S667>/Constant2'
     */
    DoorLckCtl_IllmndUnlockSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S667>/Multiport Switch' incorporates:
     *  Delay: '<S667>/Delay'
     */
    DoorLckCtl_IllmndUnlockSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_lf;
    break;
  }

  /* End of MultiPortSwitch: '<S667>/Multiport Switch' */

  /* MultiPortSwitch: '<S667>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndUnlockSts) {
   case 1:
    /* MultiPortSwitch: '<S667>/Multiport Switch1' incorporates:
     *  Constant: '<S667>/Constant3'
     */
    DoorLckCtl_IllmndUnlockStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S667>/Multiport Switch1' incorporates:
     *  Constant: '<S667>/Constant4'
     */
    DoorLckCtl_IllmndUnlockStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S667>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S667>/Unit Delay'
     */
    DoorLckCtl_IllmndUnlockStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j;
    break;
  }

  /* End of MultiPortSwitch: '<S667>/Multiport Switch1' */

  /* Logic: '<S737>/Logical Operator1' incorporates:
   *  Constant: '<S737>/Constant1'
   *  Constant: '<S737>/Constant4'
   *  Constant: '<S737>/Constant5'
   *  Constant: '<S737>/Constant8'
   *  Logic: '<S737>/Logical Operator'
   *  RelationalOperator: '<S737>/Relational Operator'
   *  RelationalOperator: '<S737>/Relational Operator1'
   *  RelationalOperator: '<S737>/Relational Operator2'
   *  RelationalOperator: '<S737>/Relational Operator3'
   *  RelationalOperator: '<S737>/Relational Operator5'
   */
  DoorLckCtl_WelcomeUnlck = (rtb_LogicalOperator_ph0 &&
    (DoorLckCtl_DriverDoorLckSw && (DoorLckCtl_IllmndUnlockStsFb == 1) &&
     (DoorLckCtl_EEIlluminatedEntrySys == 1) && (AppSwcBcm_ARID_DEF.UnitDelay2 ==
    0) && (DoorLckCtl_IllmndSts == 1)));

  /* Chart: '<S733>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S733>/Constant40'
   *  Constant: '<S733>/Constant41'
   *  Constant: '<S733>/Constant42'
   *  Logic: '<S733>/Logical Operator1'
   *  RelationalOperator: '<S733>/Relational Operator1'
   *  RelationalOperator: '<S733>/Relational Operator2'
   *  RelationalOperator: '<S733>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 1,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8);

  /* Logic: '<S733>/Logical Operator' incorporates:
   *  UnitDelay: '<S733>/Unit Delay'
   */
  DoorLckCtl_MechUnlck = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a1 &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_o);

  /* Logic: '<S672>/Logical Operator' */
  DoorLckCtl_OsUnlck = (DoorLckCtl_RKEUnlck || DoorLckCtl_PEUnlck ||
                        DoorLckCtl_WelcomeUnlck || DoorLckCtl_MechUnlck);

  /* Logic: '<S670>/Logical Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_ap = (DoorLckCtl_InsLck || DoorLckCtl_OsLck ||
    DoorLckCtl_InsUnlck || DoorLckCtl_OsUnlck || DoorLckCtl_TrunkUnlck);

  /* Chart: '<S670>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S705>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ap,
    &AppSwcBcm_ARID_DEF.LogicalOperator_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ln);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_l + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_l + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_l = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;

    /* LIB_blOut=0; */
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_i = (uint16)tmp;
  }

  /* Constant: '<S670>/Constant' */
  if (AppSwcBcm_ARID_DEF.Cnt2_i >= DoorLckCtl_CntSubTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_l - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_l - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_l = (uint16)tmp;
  }

  /* End of Constant: '<S670>/Constant' */

  /* Constant: '<S670>/Constant1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_ei = (AppSwcBcm_ARID_DEF.Cnt_l >=
    DoorLckCtl_MotorWorkMax_C);

  /* Chart: '<S670>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S705>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ei,
    &AppSwcBcm_ARID_DEF.LogicalOperator_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_b);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_o) {
    AppSwcBcm_ARID_DEF.LIB_blOut_n = true;
    AppSwcBcm_ARID_DEF.Cnt3 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.LIB_blOut_n) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3 = (uint16)tmp;
  }

  /* Constant: '<S670>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt3 >= DoorLckCtl_MotorProtTimMax_C) {
    AppSwcBcm_ARID_DEF.LIB_blOut_n = false;
    AppSwcBcm_ARID_DEF.Cnt_l = 0U;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;
    AppSwcBcm_ARID_DEF.Cnt3 = 0U;
  }

  /* End of Constant: '<S670>/Constant2' */

  /* Switch: '<S670>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  DoorLckCtl_MotorProt = ((!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->CrashSta) && AppSwcBcm_ARID_DEF.LIB_blOut_n);

  /* Chart: '<S735>/ClearRKECommd' incorporates:
   *  SubSystem: '<S740>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_a,
    &AppSwcBcm_ARID_DEF.LogicalOperator_cu,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dh);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_cu) {
    AppSwcBcm_ARID_DEF.flg = true;
    AppSwcBcm_ARID_DEF.Cnt_dp = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_dp - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_dp - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_dp = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg && (AppSwcBcm_ARID_DEF.Cnt_dp == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg = false;
  }

  /* Chart: '<S657>/ClearRKECommd1' */
  if (DoorLckCtl_TrunkUnlck) {
    AppSwcBcm_ARID_DEF.flg_l = true;
    AppSwcBcm_ARID_DEF.Cnt_mc = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_mc - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_mc - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_mc = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_l && (AppSwcBcm_ARID_DEF.Cnt_mc == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_l = false;
  }

  /* End of Chart: '<S657>/ClearRKECommd1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_j = rtb_RelationalOperator2_mr;

  /* Chart: '<S713>/ClearRKECommd' incorporates:
   *  SubSystem: '<S724>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_j,
    &AppSwcBcm_ARID_DEF.LogicalOperator_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_b);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_j) {
    AppSwcBcm_ARID_DEF.flg_a = true;
    AppSwcBcm_ARID_DEF.Cnt_f3 = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_f3 - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_f3 - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_f3 = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_a && (AppSwcBcm_ARID_DEF.Cnt_f3 == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_a = false;
  }

  /* Outputs for Atomic SubSystem: '<S711>/Lib_RiseEdgeDet' */
  /* Update for UnitDelay: '<S711>/Unit Delay' incorporates:
   *  RelationalOperator: '<S711>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ls = AppSwcBcm_Lib_RiseEdgeDet
    (DoorLckCtl_DriverDoorLckSw, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nu);

  /* End of Outputs for SubSystem: '<S711>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S733>/Lib_RiseEdgeDet' */
  /* Update for UnitDelay: '<S733>/Unit Delay' incorporates:
   *  RelationalOperator: '<S733>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_a1 = AppSwcBcm_Lib_RiseEdgeDet
    (!DoorLckCtl_DriverDoorLckSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dy);

  /* End of Outputs for SubSystem: '<S733>/Lib_RiseEdgeDet' */

  /* Update for Delay: '<S666>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_f = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE = DoorLckCtl_IllmndLckSts;

  /* Update for UnitDelay: '<S666>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h = DoorLckCtl_IllmndLckStsFb;

  /* Update for UnitDelay: '<S685>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n5 = rtb_LogicalOperator_mx;

  /* Update for Delay: '<S674>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_o = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_l = DoorLckCtl_ParkAutoUnlockSetFb;

  /* Update for Delay: '<S667>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ox = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_lf = DoorLckCtl_IllmndUnlockSts;

  /* Update for UnitDelay: '<S667>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = DoorLckCtl_IllmndUnlockStsFb;
}

/* ConstCode for atomic system: '<S623>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Const(void)
{
  /* ConstCode for Constant: '<S675>/Constant8' */
  DoorLckCtl_SpdCtlLckSet = 1U;
}

/* System initialize for atomic system: '<S623>/SignalProcess' */
static void AppSwcBcm_SignalProcess_b_Init(void)
{
  /* SystemInitialize for Chart: '<S661>/LIB_TPD_10ms1' */
  AppSwcBcm_ARID_DEF.cnt_heal_m = 50U;
  DoorLckCtl_DoorAjarFLSw = true;

  /* SystemInitialize for Chart: '<S661>/LIB_TPD_10ms2' */
  AppSwcBcm_ARID_DEF.cnt_heal_hj = 50U;
  DoorLckCtl_DoorAjarFRSw = true;

  /* SystemInitialize for Chart: '<S661>/LIB_TPD_10ms' */
  AppSwcBcm_ARID_DEF.cnt_heal_p = 50U;
  DoorLckCtl_DriverDoorLckSw = true;

  /* SystemInitialize for Chart: '<S661>/LIB_TPD_10ms6' */
  AppSwcBcm_ARID_DEF.cnt_heal_n = 50U;
  DoorLckCtl_DoorAjarRLSw = true;

  /* SystemInitialize for Chart: '<S661>/LIB_TPD_10ms7' */
  AppSwcBcm_ARID_DEF.cnt_heal_e = 50U;
  DoorLckCtl_DoorAjarRRSw = true;

  /* SystemInitialize for Chart: '<S661>/LIB_TPD_10ms8' */
  AppSwcBcm_ARID_DEF.cnt_heal_k = 50U;
  DoorLckCtl_TrunkAjarSw = true;
}

/* Output and update for atomic system: '<S623>/SignalProcess' */
static void AppSwcBcm_SignalProcess_m(void)
{
  uint16 rtb_Switch12_c;
  uint16 tmp;
  boolean rtb_Switch1;

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift1' */
  /* Constant: '<S661>/Constant5' */
  rtb_Switch12_c = AppSwcBcm_BitShift4(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift1' */

  /* Switch: '<S661>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND1'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch1' incorporates:
     *  Constant: '<S661>/Constant4'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarFLVal_C;
  } else {
    /* Switch: '<S661>/Switch1' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion1'
     */
    rtb_Switch1 = (BSW_J321DoorAjarFL != 0);
  }

  /* End of Switch: '<S661>/Switch1' */

  /* Chart: '<S661>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S661>/Constant1'
   *  Constant: '<S661>/Constant2'
   *  Constant: '<S661>/Constant3'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_e >= (float32)
         DoorLckCtl_DoorAjarFLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_e++;
      AppSwcBcm_ARID_DEF.cnt_heal_m = (uint16)((float32)
        DoorLckCtl_DoorAjarFLTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_e = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m == 0) {
      DoorLckCtl_DoorAjarFLSw = false;
    } else if (DoorLckCtl_DoorAjarFLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_m--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift2' */
  /* Constant: '<S661>/Constant10' */
  rtb_Switch12_c = AppSwcBcm_BitShift7(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift2' */

  /* Switch: '<S661>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND2'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch2' incorporates:
     *  Constant: '<S661>/Constant9'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarFRVal_C;
  } else {
    /* Switch: '<S661>/Switch2' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion2'
     */
    rtb_Switch1 = (BSW_J310DoorAjarFR != 0);
  }

  /* End of Switch: '<S661>/Switch2' */

  /* Chart: '<S661>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S661>/Constant6'
   *  Constant: '<S661>/Constant7'
   *  Constant: '<S661>/Constant8'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l >= (float32)
         DoorLckCtl_DoorAjarFRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l++;
      AppSwcBcm_ARID_DEF.cnt_heal_hj = (uint16)((float32)
        DoorLckCtl_DoorAjarFRTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_hj == 0) {
      DoorLckCtl_DoorAjarFRSw = false;
    } else if (DoorLckCtl_DoorAjarFRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_hj--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift5' */
  /* Constant: '<S661>/Constant59' */
  rtb_Switch12_c = AppSwcBcm_BitShift3(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift5' */

  /* Switch: '<S661>/Switch5' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND5'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch5' incorporates:
     *  Constant: '<S661>/Constant60'
     */
    rtb_Switch1 = DoorLckCtl_DriverDoorLckVal_C;
  } else {
    /* Switch: '<S661>/Switch5' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion5'
     */
    rtb_Switch1 = (BSW_J335DriverDoorLck != 0);
  }

  /* End of Switch: '<S661>/Switch5' */

  /* Chart: '<S661>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S661>/Constant46'
   *  Constant: '<S661>/Constant47'
   *  Constant: '<S661>/Constant49'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lh >= (float32)
         DoorLckCtl_DriverDoorLckTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DriverDoorLckTimValid_C != 0xFFFF)) {
      DoorLckCtl_DriverDoorLckSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lh++;
      AppSwcBcm_ARID_DEF.cnt_heal_p = (uint16)((float32)
        DoorLckCtl_DriverDoorLckTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lh = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_p == 0) {
      DoorLckCtl_DriverDoorLckSw = false;
    } else if (DoorLckCtl_DriverDoorLckTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_p--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift3' */
  /* Constant: '<S661>/Constant11' */
  rtb_Switch12_c = AppSwcBcm_BitShift1_p(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift3' */

  /* Switch: '<S661>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND3'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch3' incorporates:
     *  Constant: '<S661>/Constant12'
     */
    rtb_Switch1 = DoorLckCtl_DrvPEVal_C;
  } else {
    /* Switch: '<S661>/Switch3' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion3'
     *  Logic: '<S661>/Logical Operator6'
     */
    rtb_Switch1 = (BSW_J338DrvPE == 0);
  }

  /* End of Switch: '<S661>/Switch3' */

  /* Chart: '<S661>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S661>/Constant25'
   *  Constant: '<S661>/Constant26'
   *  Constant: '<S661>/Constant27'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_h >= (float32)DoorLckCtl_DrvPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_DrvPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_DrvPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_h++;
      AppSwcBcm_ARID_DEF.cnt_heal_j = (uint16)((float32)
        DoorLckCtl_DrvPETimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_h = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_j == 0) {
      DoorLckCtl_DrvPESw = false;
    } else if (DoorLckCtl_DrvPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_j--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift4' */
  /* Constant: '<S661>/Constant13' */
  rtb_Switch12_c = AppSwcBcm_BitShift2(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift4' */

  /* Switch: '<S661>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND4'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch4' incorporates:
     *  Constant: '<S661>/Constant14'
     */
    rtb_Switch1 = DoorLckCtl_PsgPEVal_C;
  } else {
    /* Switch: '<S661>/Switch4' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion4'
     *  Logic: '<S661>/Logical Operator7'
     */
    rtb_Switch1 = (BSW_J337PsgPE == 0);
  }

  /* End of Switch: '<S661>/Switch4' */

  /* Chart: '<S661>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S661>/Constant28'
   *  Constant: '<S661>/Constant29'
   *  Constant: '<S661>/Constant30'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d >= (float32)DoorLckCtl_PsgPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_PsgPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d++;
      AppSwcBcm_ARID_DEF.cnt_heal_bn = (uint16)((float32)
        DoorLckCtl_PsgPETimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bn == 0) {
      DoorLckCtl_PsgPESw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bn--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift6' */
  /* Constant: '<S661>/Constant15' */
  rtb_Switch12_c = AppSwcBcm_BitShift8(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift6' */

  /* Switch: '<S661>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND6'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch6' incorporates:
     *  Constant: '<S661>/Constant16'
     */
    rtb_Switch1 = DoorLckCtl_TrunkSwVal_C;
  } else {
    /* Switch: '<S661>/Switch6' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion6'
     */
    rtb_Switch1 = (BSW_J336Trunk != 0);
  }

  /* End of Switch: '<S661>/Switch6' */

  /* Chart: '<S661>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S661>/Constant31'
   *  Constant: '<S661>/Constant32'
   *  Constant: '<S661>/Constant33'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ps >= (float32)DoorLckCtl_PsgPETimValid_C
         / (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_TrunkSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ps++;
      AppSwcBcm_ARID_DEF.cnt_heal_h = (uint16)((float32)
        DoorLckCtl_PsgPETimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ps = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h == 0) {
      DoorLckCtl_TrunkSw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_h--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift7' */
  /* Constant: '<S661>/Constant17' */
  rtb_Switch12_c = AppSwcBcm_BitShift9(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift7' */

  /* Switch: '<S661>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND7'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch7' incorporates:
     *  Constant: '<S661>/Constant18'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarRLVal_C;
  } else {
    /* Switch: '<S661>/Switch7' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion7'
     */
    rtb_Switch1 = (BSW_J320DoorAjarRL != 0);
  }

  /* End of Switch: '<S661>/Switch7' */

  /* Chart: '<S661>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S661>/Constant34'
   *  Constant: '<S661>/Constant35'
   *  Constant: '<S661>/Constant36'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fg >= (float32)
         DoorLckCtl_DoorAjarRLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fg++;
      AppSwcBcm_ARID_DEF.cnt_heal_n = (uint16)((float32)
        DoorLckCtl_DoorAjarRLTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fg = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n == 0) {
      DoorLckCtl_DoorAjarRLSw = false;
    } else if (DoorLckCtl_DoorAjarRLTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift8' */
  /* Constant: '<S661>/Constant19' */
  rtb_Switch12_c = AppSwcBcm_BitShift3_f(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift8' */

  /* Switch: '<S661>/Switch8' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND8'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch8' incorporates:
     *  Constant: '<S661>/Constant20'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarRRVal_C;
  } else {
    /* Switch: '<S661>/Switch8' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion8'
     */
    rtb_Switch1 = (BSW_J36DoorAjarRR != 0);
  }

  /* End of Switch: '<S661>/Switch8' */

  /* Chart: '<S661>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S661>/Constant37'
   *  Constant: '<S661>/Constant38'
   *  Constant: '<S661>/Constant39'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_f >= (float32)
         DoorLckCtl_DoorAjarRRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_f++;
      AppSwcBcm_ARID_DEF.cnt_heal_e = (uint16)((float32)
        DoorLckCtl_DoorAjarRRTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_f = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e == 0) {
      DoorLckCtl_DoorAjarRRSw = false;
    } else if (DoorLckCtl_DoorAjarRRTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_e--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms7' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift9' */
  /* Constant: '<S661>/Constant21' */
  rtb_Switch12_c = AppSwcBcm_BitShift10_i(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift9' */

  /* Switch: '<S661>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND9'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    /* Switch: '<S661>/Switch9' incorporates:
     *  Constant: '<S661>/Constant22'
     */
    rtb_Switch1 = DoorLckCtl_TrunkAjarVal_C;
  } else {
    /* Switch: '<S661>/Switch9' incorporates:
     *  DataTypeConversion: '<S661>/Data Type Conversion9'
     */
    rtb_Switch1 = (BSW_J37TrunkAjar != 0);
  }

  /* End of Switch: '<S661>/Switch9' */

  /* Chart: '<S661>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S661>/Constant40'
   *  Constant: '<S661>/Constant41'
   *  Constant: '<S661>/Constant42'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_n >= (float32)
         DoorLckCtl_TrunkAjarTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_TrunkAjarTimValid_C != 0xFFFF)) {
      DoorLckCtl_TrunkAjarSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_n++;
      AppSwcBcm_ARID_DEF.cnt_heal_k = (uint16)((float32)
        DoorLckCtl_TrunkAjarTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_n = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k == 0) {
      DoorLckCtl_TrunkAjarSw = false;
    } else if (DoorLckCtl_TrunkAjarTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift12' */
  /* Constant: '<S661>/Constant62' */
  rtb_Switch12_c = AppSwcBcm_BitShift11_i(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S661>/Bit Shift12' */

  /* Switch: '<S661>/Switch12' incorporates:
   *  Constant: '<S661>/Constant63'
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND12'
   */
  if ((rtb_Switch12_c & 1U) != 0U) {
    tmp = DoorLckCtl_DrvSeatResisVal_C;
  } else {
    tmp = BSW_J112DrvSeatResis;
  }

  /* Chart: '<S661>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S661>/Constant64'
   *  Constant: '<S661>/Constant65'
   *  Constant: '<S661>/Constant66'
   *  Constant: '<S661>/Constant67'
   *  RelationalOperator: '<S661>/Relational Operator6'
   *  Switch: '<S661>/Switch12'
   */
  if (tmp <= DoorLckCtl_DrvSeatResisMin_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c >= (float32)
         DoorLckCtl_DrvSeatTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DrvSeatTimValid_C != 0xFFFF)) {
      DoorLckCtl_DrvSeatSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c++;
      AppSwcBcm_ARID_DEF.cnt_heal_bp = (uint16)((float32)
        DoorLckCtl_DrvSeatTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bp == 0) {
      DoorLckCtl_DrvSeatSw = false;
    } else if (DoorLckCtl_DrvSeatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bp--;
    }
  }

  /* End of Chart: '<S661>/LIB_TPD_10ms11' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift13' */
  /* Switch: '<S661>/Switch13' incorporates:
   *  Constant: '<S661>/Constant71'
   *  Constant: '<S661>/Constant72'
   *  MATLAB Function: '<S754>/bit_shift'
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND13'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 12 & 1U) != 0U) {
    DoorLckCtl_EEKeyEntry = DoorLckCtl_EEKeyEntry_C;
  } else {
    DoorLckCtl_EEKeyEntry = BSW_EEKeyEntry;
  }

  /* End of Switch: '<S661>/Switch13' */
  /* End of Outputs for SubSystem: '<S661>/Bit Shift13' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift14' */
  /* Switch: '<S661>/Switch14' incorporates:
   *  Constant: '<S661>/Constant73'
   *  Constant: '<S661>/Constant74'
   *  MATLAB Function: '<S755>/bit_shift'
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND14'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 13 & 1U) != 0U) {
    DoorLckCtl_EEIlluminatedEntrySys = DoorLckCtl_EEIlluminatedEntrySys_C;
  } else {
    DoorLckCtl_EEIlluminatedEntrySys = BSW_EEIlluminatedEntrySys;
  }

  /* End of Switch: '<S661>/Switch14' */
  /* End of Outputs for SubSystem: '<S661>/Bit Shift14' */

  /* Outputs for Atomic SubSystem: '<S661>/Bit Shift15' */
  /* Switch: '<S661>/Switch15' incorporates:
   *  Constant: '<S661>/Constant75'
   *  Constant: '<S661>/Constant76'
   *  MATLAB Function: '<S756>/bit_shift'
   *  S-Function (sfix_bitop): '<S661>/Bitwise AND15'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 14 & 1U) != 0U) {
    DoorLckCtl_IllmndSts = DoorLckCtl_IllmndSts_C;
  } else {
    DoorLckCtl_IllmndSts = BSW_IllmndSts;
  }

  /* End of Switch: '<S661>/Switch15' */
  /* End of Outputs for SubSystem: '<S661>/Bit Shift15' */

  /* RelationalOperator: '<S661>/Relational Operator' incorporates:
   *  Constant: '<S661>/Constant'
   */
  rtb_Switch1 = (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpd_kph <
                 3.0F);

  /* Logic: '<S661>/Logical Operator1' incorporates:
   *  Logic: '<S661>/Logical Operator'
   *  RelationalOperator: '<S661>/Relational Operator2'
   */
  DoorLckCtl_VehStop =
    ((!AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg) ||
     rtb_Switch1);

  /* Logic: '<S661>/Logical Operator4' incorporates:
   *  Logic: '<S661>/Logical Operator2'
   *  Logic: '<S661>/Logical Operator3'
   *  RelationalOperator: '<S661>/Relational Operator1'
   */
  DoorLckCtl_VehRun = ((!rtb_Switch1) &&
                       AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg);

  /* Switch: '<S661>/Switch' incorporates:
   *  Constant: '<S661>/Constant54'
   *  RelationalOperator: '<S661>/Relational Operator5'
   */
  if (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg) {
    DoorLckCtl_VehSpd =
      AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpd_kph;
  } else {
    DoorLckCtl_VehSpd = 0.0F;
  }

  /* End of Switch: '<S661>/Switch' */
}

/* ConstCode for atomic system: '<S623>/SignalProcess' */
static void AppSwcBcm_SignalProcess_c_Const(void)
{
  /* ConstCode for Constant: '<S661>/Constant69' */
  DoorLckCtl_HoodAjarSw = true;
}

/* System initialize for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S623>/DoorDrv' */
  AppSwcBcm_DoorDrv_Init();

  /* SystemInitialize for Atomic SubSystem: '<S623>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Init();

  /* End of SystemInitialize for SubSystem: '<S623>/DoorLckCtlLogic' */

  /* SystemInitialize for Atomic SubSystem: '<S623>/SignalProcess' */
  AppSwcBcm_SignalProcess_b_Init();

  /* End of SystemInitialize for SubSystem: '<S623>/SignalProcess' */
}

/* Outputs for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl(void)
{
  boolean rtb_DataTypeConversion1_e;

  /* Outputs for Atomic SubSystem: '<S623>/SignalProcess' */
  AppSwcBcm_SignalProcess_m();

  /* End of Outputs for SubSystem: '<S623>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S623>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic();

  /* End of Outputs for SubSystem: '<S623>/DoorLckCtlLogic' */

  /* Chart: '<S623>/DoorDrv' */
  AppSwcBcm_DoorDrv();

  /* Outputs for Atomic SubSystem: '<S623>/Ovrd1' */
  /* Switch: '<S658>/Switch1' incorporates:
   *  Constant: '<S623>/Constant1'
   *  Constant: '<S623>/Constant2'
   *  Switch: '<S658>/Switch2'
   */
  if (DoorLckCtl_J54DoorLckOvrdFlg_C) {
    DoorLckCtl_J54DoorLck = DoorLckCtl_J54DoorLckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S623>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_e = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorLlckCtlFlg != 0);
    DoorLckCtl_J54DoorLck = (rtb_DataTypeConversion1_e ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J54);
  }

  /* End of Switch: '<S658>/Switch1' */
  /* End of Outputs for SubSystem: '<S623>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S623>/Ovrd2' */
  /* Switch: '<S659>/Switch1' incorporates:
   *  Constant: '<S623>/Constant3'
   *  Constant: '<S623>/Constant4'
   *  Switch: '<S659>/Switch2'
   */
  if (DoorLckCtl_J511TrunkUnlckOvrdFlg_C) {
    DoorLckCtl_J511TrunkUnlck = DoorLckCtl_J511TrunkUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S623>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_e = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->TrunkUnlckCtlFlg != 0);
    DoorLckCtl_J511TrunkUnlck = (rtb_DataTypeConversion1_e ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J511);
  }

  /* End of Switch: '<S659>/Switch1' */
  /* End of Outputs for SubSystem: '<S623>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S623>/Ovrd3' */
  /* Switch: '<S660>/Switch1' incorporates:
   *  Constant: '<S623>/Constant18'
   *  Constant: '<S623>/Constant19'
   *  Switch: '<S660>/Switch2'
   */
  if (DoorLckCtl_J56DoorUnlckOvrdFlg_C) {
    DoorLckCtl_J56DoorUnlck = DoorLckCtl_J56DoorUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S623>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_e = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorUnlckCtlFlg != 0);
    DoorLckCtl_J56DoorUnlck = (rtb_DataTypeConversion1_e ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J56);
  }

  /* End of Switch: '<S660>/Switch1' */
  /* End of Outputs for SubSystem: '<S623>/Ovrd3' */
}

/* ConstCode for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S623>/SignalProcess' */
  AppSwcBcm_SignalProcess_c_Const();

  /* End of ConstCode for SubSystem: '<S623>/SignalProcess' */

  /* ConstCode for Atomic SubSystem: '<S623>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Const();

  /* End of ConstCode for SubSystem: '<S623>/DoorLckCtlLogic' */
}

/*
 * Output and update for function-call system:
 *    '<S799>/Lib_ChgDet'
 *    '<S803>/Lib_ChgDet'
 *    '<S807>/Lib_ChgDet'
 *    '<S811>/Lib_ChgDet'
 */
static void AppSwcBcm_Lib_ChgDet(float32 rtu_Lib_In, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_ChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* RelationalOperator: '<S802>/Relational Operator' incorporates:
   *  UnitDelay: '<S802>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_In != AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S802>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_In;
}

/* System initialize for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S820>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg);

  /* SystemInitialize for Chart: '<S820>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut);
}

/* Output and update for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl(void)
{
  sint32 tmp;
  uint8 rtb_Switch;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator1_p1;
  boolean rtb_RelationalOperator3_g;

  /* Chart: '<S820>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S820>/Constant6'
   *  RelationalOperator: '<S820>/Relational Operator'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(AppSwcBcm_ARID_DEF.BusCreator4.OsLck, 2,
    &AppSwcBcm_ARID_DEF.LIB_blOut,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay);

  /* RelationalOperator: '<S820>/Relational Operator1' incorporates:
   *  Constant: '<S820>/Constant1'
   */
  rtb_RelationalOperator1_p1 = (AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0);

  /* Logic: '<S820>/Logical Operator' incorporates:
   *  Constant: '<S820>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S820>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S820>/Relational Operator3' incorporates:
   *  Constant: '<S820>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator3_g =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S820>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_RelationalOperator3_g);

  /* SignalConversion: '<S820>/Signal Copy' incorporates:
   *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
   */
  ESCCtl_UnOrLockfeedback =
    (Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
     ())->VIPM_ESCLUnOrLockfeedback_nu;

  /* Switch: '<S826>/Switch' incorporates:
   *  Constant: '<S826>/Constant1'
   *  RelationalOperator: '<S826>/Relational Operator1'
   *  SignalConversion: '<S820>/Signal Copy'
   */
  if (ESCCtl_UnOrLockfeedback == 648518346341351424ULL) {
    /* Switch: '<S826>/Switch' incorporates:
     *  Constant: '<S826>/Constant2'
     */
    rtb_Switch = 2U;
  } else {
    /* Switch: '<S826>/Switch' incorporates:
     *  Constant: '<S826>/Constant'
     *  RelationalOperator: '<S826>/Relational Operator'
     */
    rtb_Switch = (uint8)(ESCCtl_UnOrLockfeedback == 1297036692682702848ULL);
  }

  /* End of Switch: '<S826>/Switch' */

  /* Logic: '<S820>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S820>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_e5 = (AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
    AppSwcBcm_ARID_DEF.LIB_blOut && rtb_RelationalOperator1_p1 &&
    rtb_LogicalOperator);

  /* Chart: '<S820>/ESCLLck' incorporates:
   *  SubSystem: '<S821>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_d(AppSwcBcm_ARID_DEF.Lib_blIn_e5,
    &AppSwcBcm_ARID_DEF.LogicalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_n);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_b) {
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

  /* Chart: '<S820>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S820>/Constant7'
   *  Constant: '<S820>/Constant8'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_RelationalOperator1_p1, 5, 0.05F,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11);

  /* Logic: '<S820>/Logical Operator2' incorporates:
   *  RelationalOperator: '<S820>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_i = (AppSwcBcm_ARID_DEF.BusCreator1.PwrOn &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg && rtb_LogicalOperator &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop);

  /* Chart: '<S820>/ESCLUnlck' incorporates:
   *  SubSystem: '<S822>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_d(AppSwcBcm_ARID_DEF.Lib_blIn_i,
    &AppSwcBcm_ARID_DEF.LogicalOperator_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m);
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

  /* Outputs for Atomic SubSystem: '<S820>/Ovrd' */
  /* Switch: '<S825>/Switch' incorporates:
   *  Constant: '<S820>/Constant18'
   */
  if (ESCLCtl_J436PwrSupOvrdFlg_C) {
    /* Switch: '<S825>/Switch' incorporates:
     *  Constant: '<S820>/Constant19'
     */
    ESCLCtl_J436PwrSup = ESCLCtl_J436PwrSupOvrdVal_C;
  } else {
    /* Switch: '<S825>/Switch' incorporates:
     *  Logic: '<S820>/Logical Operator3'
     */
    ESCLCtl_J436PwrSup = (ESCLCtl_J436Lck || ESCLCtl_J436Unlck);
  }

  /* End of Switch: '<S825>/Switch' */
  /* End of Outputs for SubSystem: '<S820>/Ovrd' */

  /* Truth Table: '<S820>/Truth Table' */
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

  /* End of Truth Table: '<S820>/Truth Table' */
}

/* System initialize for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl_Init(void)
{
  sint32 i;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for Chart: '<S626>/IMMOCtl' */
    AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i] = MAX_uint8_T;

    /* SystemInitialize for SignalConversion generated from: '<S626>/IMMOCtl' */
    IMMOCtl_AuthResp[i] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i];
  }

  for (i = 0; i < 16; i++) {
    /* SystemInitialize for SignalConversion generated from: '<S626>/IMMOCtl' */
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

  /* SignalConversion: '<S626>/Signal Conversion' incorporates:
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

  /* Chart: '<S626>/IMMOCtl' */
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
    /* SignalConversion generated from: '<S626>/IMMOCtl' */
    IMMOCtl_SKRead[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[i_0];
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    /* SignalConversion generated from: '<S626>/IMMOCtl' */
    IMMOCtl_AuthResp[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i_0];
  }

  /* SignalConversion generated from: '<S626>/IMMOCtl' incorporates:
   *  Chart: '<S626>/IMMOCtl'
   */
  IMMOCtl_SKSta = (uint8)(b_k == 16);
}

/* Output and update for atomic system: '<S627>/Chart' */
static void AppSwcBcm_Chart(void)
{
  /* Chart: '<S627>/Chart' incorporates:
   *  UnitDelay: '<S627>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c105_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
    PDUCtl_SysPowerSts = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib) {
     case AppSwcBcm_IN_LocalOn:
      PDUCtl_SysPowerSts = 1U;
      if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i == 0) {
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
      if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i == 2) {
        AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_LocalOn;
        PDUCtl_SysPowerSts = 1U;
      }
      break;

     default:
      /* case IN_RemoteOn: */
      AppSwcBcm_ARID_DEF.is_c105_PDUCtl_Lib = AppSwcBcm_IN_PSOff;
      PDUCtl_SysPowerSts = 0U;
      break;
    }
  }

  /* End of Chart: '<S627>/Chart' */
}

/* Output and update for atomic system: '<S627>/PwrOff' */
static void AppSwcBcm_PwrOff(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_kl;
  boolean rtb_LogicalOperator2_aq;
  boolean rtb_LogicalOperator2_n;
  boolean rtb_RelationalOperator11_g;
  boolean rtb_RelationalOperator4_le;
  boolean rtb_RelationalOperator5_l5;

  /* Logic: '<S839>/Logical Operator' incorporates:
   *  Constant: '<S839>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S839>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S839>/Logical Operator1' incorporates:
   *  Constant: '<S839>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S839>/Relational Operator3'
   */
  rtb_LogicalOperator1_kl =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S839>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator1_kl);

  /* Logic: '<S839>/Logical Operator1' incorporates:
   *  Constant: '<S839>/Constant'
   *  Constant: '<S839>/Constant10'
   *  Constant: '<S839>/Constant11'
   *  Logic: '<S839>/Logical Operator7'
   *  RelationalOperator: '<S839>/Relational Operator'
   *  RelationalOperator: '<S839>/Relational Operator6'
   *  RelationalOperator: '<S839>/Relational Operator7'
   *  UnitDelay: '<S627>/Unit Delay'
   *  UnitDelay: '<S627>/Unit Delay2'
   */
  rtb_LogicalOperator1_kl = (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn == 2) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn == 1)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 2) && rtb_LogicalOperator);

  /* RelationalOperator: '<S839>/Relational Operator11' */
  rtb_RelationalOperator11_g = !AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;

  /* Outputs for Atomic SubSystem: '<S839>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    &rtb_LogicalOperator2_n, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet);

  /* End of Outputs for SubSystem: '<S839>/Lib_BothEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S839>/Lib_BothEdgeDet1' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    &rtb_LogicalOperator2_aq, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet1);

  /* End of Outputs for SubSystem: '<S839>/Lib_BothEdgeDet1' */

  /* Outputs for Atomic SubSystem: '<S839>/Lib_BothEdgeDet2' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_RelationalOperator4_le, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet2);

  /* End of Outputs for SubSystem: '<S839>/Lib_BothEdgeDet2' */

  /* Outputs for Atomic SubSystem: '<S839>/Lib_BothEdgeDet3' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_RelationalOperator5_l5, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet3);

  /* End of Outputs for SubSystem: '<S839>/Lib_BothEdgeDet3' */

  /* Logic: '<S839>/Logical Operator2' incorporates:
   *  Logic: '<S839>/Logical Operator3'
   */
  rtb_RelationalOperator5_l5 = ((!rtb_LogicalOperator2_n) &&
    (!rtb_LogicalOperator2_aq) && (!rtb_RelationalOperator4_le) &&
    (!rtb_RelationalOperator5_l5));

  /* RelationalOperator: '<S839>/Relational Operator4' incorporates:
   *  Constant: '<S839>/Constant17'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S839>/Relational Operator1'
   */
  rtb_RelationalOperator4_le =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VIPC_VehHiddenMode_enum != 1);

  /* Chart: '<S839>/LIB_Tim' incorporates:
   *  Constant: '<S839>/Constant4'
   *  Constant: '<S839>/Constant5'
   *  Constant: '<S839>/Constant6'
   *  Constant: '<S839>/Constant7'
   *  Logic: '<S839>/Logical Operator4'
   *  RelationalOperator: '<S839>/Relational Operator12'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator11_g &&
      rtb_LogicalOperator1_kl && rtb_RelationalOperator5_l5 &&
      rtb_RelationalOperator4_le) {
    if ((AppSwcBcm_ARID_DEF.Cnt_H >= PDUCtl_TimOutPwrOffH_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_M >= PDUCtl_TimOutPwrOffM_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_S >= PDUCtl_TimOutPwrOffS_C)) {
      rtb_RelationalOperator4_le = true;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_Tick + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_Tick = (uint16)tmp;
      rtb_RelationalOperator4_le = false;
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
    rtb_RelationalOperator4_le = false;
    AppSwcBcm_ARID_DEF.Cnt_Tick = 0U;
    AppSwcBcm_ARID_DEF.Cnt_S = 0U;
    AppSwcBcm_ARID_DEF.Cnt_M = 0U;
    AppSwcBcm_ARID_DEF.Cnt_H = 0U;
  }

  /* End of Chart: '<S839>/LIB_Tim' */

  /* RelationalOperator: '<S839>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_l5 = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUPwrOffReq_flg;

  /* Logic: '<S839>/Logical Operator6' incorporates:
   *  Constant: '<S839>/Constant12'
   *  Constant: '<S839>/Constant13'
   *  Constant: '<S839>/Constant14'
   *  Logic: '<S839>/Logical Operator10'
   *  Logic: '<S839>/Logical Operator11'
   *  Logic: '<S839>/Logical Operator5'
   *  Logic: '<S839>/Logical Operator8'
   *  Logic: '<S839>/Logical Operator9'
   *  RelationalOperator: '<S839>/Relational Operator10'
   *  RelationalOperator: '<S839>/Relational Operator12'
   *  RelationalOperator: '<S839>/Relational Operator4'
   *  RelationalOperator: '<S839>/Relational Operator8'
   *  RelationalOperator: '<S839>/Relational Operator9'
   *  UnitDelay: '<S627>/Unit Delay'
   *  UnitDelay: '<S627>/Unit Delay2'
   */
  PDUCtl_PwrOff = ((rtb_LogicalOperator && rtb_RelationalOperator11_g &&
                    (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn != 3) ||
                      (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn != 5)) &&
                     (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 2)) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.OsLck &&
                    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                     AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                     AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.VehStop) ||
                   (rtb_RelationalOperator5_l5 &&
                    AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
                    rtb_LogicalOperator1_kl) || rtb_RelationalOperator4_le);
}

/*
 * Output and update for atomic system:
 *    '<S840>/Lib_FailEdgeDet'
 *    '<S840>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet_p(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_l_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S852>/Logical Operator' incorporates:
   *  Logic: '<S852>/Logical Operator1'
   *  UnitDelay: '<S852>/Unit Delay'
   */
  rty_Lib_blOut_0 = ((!rtu_Lib_blIn) &&
                     AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S852>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* Output and update for atomic system: '<S627>/PwrOn' */
static void AppSwcBcm_PwrOn(void)
{
  sint32 tmp;
  boolean rtb_LIB_blOut_cl;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator_hv;
  boolean rtb_RelationalOperator2_b2;
  boolean rtb_RelationalOperator5_l;

  /* Chart: '<S840>/BrkPwrOn' incorporates:
   *  Constant: '<S840>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S627>/Unit Delay4'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c7_PDUCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c7_PDUCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_p = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else if (AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib == AppSwcBcm_IN_Invalid) {
    AppSwcBcm_ARID_DEF.Lib_blIn_e =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw;

    /* Outputs for Function Call SubSystem: '<S850>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_e,
      &AppSwcBcm_ARID_DEF.LogicalOperator_a,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g);

    /* End of Outputs for SubSystem: '<S850>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_a) {
      AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib = AppSwcBcm_IN_Valid;
      tmp = AppSwcBcm_ARID_DEF.Cnt_p + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_p + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_p = (uint16)tmp;
      AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;
    }

    /* case IN_Valid: */
  } else if ((!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw) ||
             (AppSwcBcm_ARID_DEF.Cnt_p > PDUCtl_PwrOnPSTimValid_C) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_k) {
    AppSwcBcm_ARID_DEF.is_c7_PDUCtl_Lib = AppSwcBcm_IN_Invalid;
    AppSwcBcm_ARID_DEF.Cnt_p = 0U;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = false;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt_p + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_p + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_p = (uint16)tmp;
    AppSwcBcm_ARID_DEF.BrkPwrOnValid = true;

    /* Lib_RiseEdgeDetInit(LampCtl_BrakeLightSw); */
  }

  /* End of Chart: '<S840>/BrkPwrOn' */

  /* RelationalOperator: '<S840>/Relational Operator5' incorporates:
   *  Constant: '<S840>/Constant8'
   */
  rtb_RelationalOperator5_l = (AppSwcBcm_ARID_DEF.BusCreator14.SKSta == 1);

  /* Switch: '<S854>/Switch' incorporates:
   *  Constant: '<S840>/Constant9'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    /* Logic: '<S840>/Logical Operator3' incorporates:
     *  Constant: '<S840>/Constant10'
     */
    rtb_RelationalOperator2_b2 = PDUCtl_KeyValidOvrdVal_C;
  } else {
    /* RelationalOperator: '<S840>/Relational Operator2' incorporates:
     *  Constant: '<S840>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
     */
    rtb_RelationalOperator2_b2 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus
      ())->KeySta != 0);

    /* Logic: '<S840>/Logical Operator3' incorporates:
     *  Logic: '<S840>/Logical Operator7'
     */
    rtb_RelationalOperator2_b2 = (rtb_RelationalOperator2_b2 ||
      rtb_RelationalOperator5_l);
  }

  /* End of Switch: '<S854>/Switch' */

  /* Logic: '<S871>/Logical Operator10' incorporates:
   *  Logic: '<S840>/Logical Operator5'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (AppSwcBcm_ARID_DEF.BrkPwrOnValid &&
    rtb_RelationalOperator2_b2);

  /* Logic: '<S840>/Logical Operator3' incorporates:
   *  Constant: '<S840>/Constant4'
   *  Constant: '<S840>/Constant5'
   *  RelationalOperator: '<S840>/Relational Operator'
   *  RelationalOperator: '<S840>/Relational Operator3'
   *  UnitDelay: '<S627>/Unit Delay'
   *  UnitDelay: '<S627>/Unit Delay1'
   */
  rtb_RelationalOperator2_b2 = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_h == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 0));

  /* RelationalOperator: '<S840>/Relational Operator4' incorporates:
   *  Constant: '<S840>/Constant'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_h = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* Logic: '<S853>/Logical Operator' incorporates:
   *  UnitDelay: '<S840>/Unit Delay'
   */
  rtb_LogicalOperator = PDUCtl_PwrOn;

  /* Logic: '<S840>/Logical Operator8' incorporates:
   *  Constant: '<S840>/Constant7'
   *  RelationalOperator: '<S840>/Relational Operator6'
   *  UnitDelay: '<S840>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn = (AppSwcBcm_ARID_DEF.Lib_blIn_h || PDUCtl_PwrOn ||
    (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2));

  /* Chart: '<S840>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S851>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn,
    &AppSwcBcm_ARID_DEF.LogicalOperator_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_d) {
    AppSwcBcm_ARID_DEF.Cnt = 0U;
    AppSwcBcm_ARID_DEF.Flg = false;
  }

  /* Chart: '<S840>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S851>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_h,
    &AppSwcBcm_ARID_DEF.LogicalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1);
  if (AppSwcBcm_ARID_DEF.LogicalOperator) {
    AppSwcBcm_ARID_DEF.Flg = true;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg) {
    /* Constant: '<S840>/Constant6' */
    if (AppSwcBcm_ARID_DEF.Cnt <= PDUCtl_OpenDoorPwrOnTimValid) {
      tmp = AppSwcBcm_ARID_DEF.Cnt + 1;
      if (AppSwcBcm_ARID_DEF.Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt = (uint16)tmp;
      rtb_LIB_blOut_cl = true;
    } else {
      rtb_LIB_blOut_cl = false;
      AppSwcBcm_ARID_DEF.Flg = false;
    }

    /* End of Constant: '<S840>/Constant6' */
  } else {
    rtb_LIB_blOut_cl = false;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S840>/Lib_FailEdgeDet' */
  rtb_LogicalOperator_hv = AppSwcBcm_Lib_FailEdgeDet_p
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S840>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S840>/Lib_FailEdgeDet1' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet_p
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1);

  /* End of Outputs for SubSystem: '<S840>/Lib_FailEdgeDet1' */

  /* Switch: '<S855>/Switch' incorporates:
   *  Constant: '<S840>/Constant11'
   *  Constant: '<S840>/Constant12'
   *  Logic: '<S840>/Logical Operator6'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    rtb_RelationalOperator5_l = PDUCtl_KeyValidOvrdVal_C;
  } else {
    rtb_RelationalOperator5_l = (rtb_LIB_blOut_cl || rtb_RelationalOperator5_l);
  }

  /* Logic: '<S840>/Logical Operator2' incorporates:
   *  Logic: '<S840>/Logical Operator'
   *  Logic: '<S840>/Logical Operator1'
   *  Logic: '<S840>/Logical Operator4'
   *  Switch: '<S855>/Switch'
   */
  PDUCtl_PwrOn = ((rtb_RelationalOperator5_l && (rtb_LogicalOperator ||
    rtb_LogicalOperator_hv) && rtb_RelationalOperator2_b2) ||
                  (rtb_RelationalOperator2_b2 &&
                   AppSwcBcm_ARID_DEF.LogicalOperator10));
}

/* Output and update for atomic system: '<S627>/RelayDig' */
static void AppSwcBcm_RelayDig(void)
{
  float32 tmp;
  boolean rtb_RelationalOperator3_i0j;
  boolean rtb_RelationalOperator7_b;

  /* RelationalOperator: '<S841>/Relational Operator3' incorporates:
   *  Constant: '<S841>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S841>/Relational Operator2'
   */
  rtb_RelationalOperator3_i0j =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* RelationalOperator: '<S841>/Relational Operator7' incorporates:
   *  Constant: '<S841>/Constant'
   *  Logic: '<S841>/Logical Operator'
   *  RelationalOperator: '<S841>/Relational Operator'
   */
  rtb_RelationalOperator7_b = ((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator3_i0j);

  /* RelationalOperator: '<S841>/Relational Operator3' incorporates:
   *  Constant: '<S841>/Constant3'
   */
  rtb_RelationalOperator3_i0j = (PDUCtl_SysPwrMode == 0);

  /* RelationalOperator: '<S841>/Relational Operator7' incorporates:
   *  Logic: '<S841>/Logical Operator1'
   */
  rtb_RelationalOperator7_b = (rtb_RelationalOperator3_i0j ||
    rtb_RelationalOperator7_b);

  /* Chart: '<S841>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S841>/Constant6'
   *  Constant: '<S841>/Constant7'
   *  Logic: '<S841>/Logical Operator3'
   *  RelationalOperator: '<S841>/Relational Operator5'
   */
  if (rtb_RelationalOperator7_b && (PDUCtl_J437IG2RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller35)) {
    tmp = 50.0F / (PDUCtl_Ts_C * 100.0F);
    if (AppSwcBcm_ARID_DEF.cnt_defect_p >= tmp) {
      PDUCtl_IG2RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_p++;
      AppSwcBcm_ARID_DEF.cnt_heal_c = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_p = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c == 0) {
      PDUCtl_IG2RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_c--;
    }
  }

  /* End of Chart: '<S841>/LIB_TPD_10ms1' */

  /* Chart: '<S841>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S841>/Constant4'
   *  Constant: '<S841>/Constant5'
   *  Constant: '<S841>/Constant8'
   *  Logic: '<S841>/Logical Operator2'
   *  RelationalOperator: '<S841>/Relational Operator4'
   */
  if (rtb_RelationalOperator7_b && (PDUCtl_J421IG1RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller36)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_o >= 50.0F / (PDUCtl_Ts_C * 100.0F)) {
      PDUCtl_IG1RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o++;
      AppSwcBcm_ARID_DEF.cnt_heal_b = (uint16)(50.0F / (PDUCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_b == 0) {
      PDUCtl_IG1RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_b--;
    }
  }

  /* End of Chart: '<S841>/LIB_TPD_10ms2' */

  /* Switch: '<S841>/Switch' incorporates:
   *  Logic: '<S841>/Logical Operator4'
   */
  PDUCtl_SysPwrModeV = ((!PDUCtl_IG1RelayFault) && (!PDUCtl_IG2RelayFault));

  /* Chart: '<S841>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S841>/Constant1'
   *  Constant: '<S841>/Constant12'
   *  Constant: '<S841>/Constant13'
   *  Constant: '<S841>/Constant14'
   *  Constant: '<S841>/Constant15'
   *  Constant: '<S841>/Constant16'
   *  Constant: '<S841>/Constant17'
   *  Constant: '<S841>/Constant18'
   *  Logic: '<S841>/Logical Operator5'
   *  Logic: '<S841>/Logical Operator6'
   *  Logic: '<S841>/Logical Operator7'
   *  RelationalOperator: '<S841>/Relational Operator1'
   *  RelationalOperator: '<S841>/Relational Operator6'
   *  RelationalOperator: '<S841>/Relational Operator7'
   *  RelationalOperator: '<S841>/Relational Operator8'
   *  RelationalOperator: '<S841>/Relational Operator9'
   */
  if (((AppSwcBcm_ARID_DEF.CCaller35 == 1) || (AppSwcBcm_ARID_DEF.CCaller36 == 1))
      && ((AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 1) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 3) ||
          (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts == 2)) &&
      rtb_RelationalOperator3_i0j) {
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

  /* End of Chart: '<S841>/LIB_TPD_10ms3' */
}

/* System initialize for atomic system: '<S627>/StartReq' */
static void AppSwcBcm_StartReq_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;
  boolean rtb_LIB_blOut_f;

  /* SystemInitialize for Chart: '<S842>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_f);

  /* SystemInitialize for Chart: '<S842>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_k);
}

/* Output and update for atomic system: '<S627>/StartReq' */
static void AppSwcBcm_StartReq(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_k;
  boolean rtb_LIB_blOut_f;
  boolean rtb_LogicalOperator;
  boolean rtb_UnitDelay_c;

  /* UnitDelay: '<S867>/Unit Delay' incorporates:
   *  Constant: '<S842>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S842>/Relational Operator1'
   */
  rtb_UnitDelay_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                     ->VHVM_PTActOprtMode_enum != 2);

  /* Logic: '<S842>/Logical Operator' incorporates:
   *  Constant: '<S842>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S842>/Relational Operator3'
   */
  rtb_LogicalOperator = ((PDUCtl_SysPwrMode == 2) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw);

  /* Chart: '<S842>/LIB_PosPluse' incorporates:
   *  Constant: '<S842>/Constant4'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator, PDUCtl_StartReqTimValid_C,
    &rtb_LIB_blOut_f, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse);

  /* Logic: '<S842>/Logical Operator1' incorporates:
   *  Constant: '<S842>/Constant1'
   *  RelationalOperator: '<S842>/Relational Operator'
   *  RelationalOperator: '<S842>/Relational Operator2'
   *  RelationalOperator: '<S842>/Relational Operator7'
   */
  rtb_UnitDelay_c = (PDUCtl_SysPwrModeV && AppSwcBcm_ARID_DEF.LogicalOperator10 &&
                     rtb_LIB_blOut_f && (PDUCtl_SysPowerSts == 1) &&
                     rtb_UnitDelay_c);

  /* RelationalOperator: '<S842>/Relational Operator6' incorporates:
   *  Constant: '<S842>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S842>/Relational Operator5'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S842>/LIB_PosPluse1' incorporates:
   *  Constant: '<S842>/Constant5'
   *  Logic: '<S842>/Logical Operator3'
   *  UnitDelay: '<S842>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jh, PDUCtl_StartReqOverTimValid_C,
    &rtb_LIB_blOut_k, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1);

  /* Outputs for Atomic SubSystem: '<S842>/Lib_SR' */
  /* Outputs for Atomic SubSystem: '<S842>/Lib_RiseEdgeDetHold' */
  /* Switch: '<S868>/Switch' incorporates:
   *  Constant: '<S842>/Constant6'
   *  Logic: '<S842>/Logical Operator2'
   *  Logic: '<S842>/Logical Operator4'
   *  Logic: '<S867>/Logical Operator'
   *  Logic: '<S867>/Logical Operator1'
   *  RelationalOperator: '<S842>/Relational Operator4'
   *  RelationalOperator: '<S842>/Relational Operator6'
   *  Switch: '<S869>/Switch'
   *  UnitDelay: '<S867>/Unit Delay'
   */
  if (((!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw) &&
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hx &&
       (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) || (PDUCtl_SysPwrMode ==
       0) || rtb_LIB_blOut_k) {
    /* Switch: '<S868>/Switch' incorporates:
     *  Constant: '<S868>/Constant'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e = false;

    /* Switch: '<S869>/Switch' incorporates:
     *  Constant: '<S869>/Constant'
     */
    PDUCtl_StartReq = false;
  } else {
    /* Switch: '<S868>/Switch' incorporates:
     *  Logic: '<S868>/Logical Operator'
     *  Logic: '<S868>/Logical Operator1'
     *  Logic: '<S868>/Logical Operator2'
     *  UnitDelay: '<S868>/Unit Delay'
     *  UnitDelay: '<S868>/Unit Delay1'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e = ((rtb_UnitDelay_c &&
      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k)) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e);

    /* Switch: '<S869>/Switch' incorporates:
     *  Logic: '<S869>/Logical Operator'
     *  UnitDelay: '<S869>/Unit Delay'
     */
    PDUCtl_StartReq = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e || PDUCtl_StartReq);
  }

  /* End of Switch: '<S868>/Switch' */
  /* End of Outputs for SubSystem: '<S842>/Lib_SR' */

  /* Update for UnitDelay: '<S868>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_k = rtb_UnitDelay_c;

  /* End of Outputs for SubSystem: '<S842>/Lib_RiseEdgeDetHold' */

  /* Update for UnitDelay: '<S842>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jh = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S867>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hx =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;
}

/* Output and update for atomic system: '<S627>/Subsystem' */
static void AppSwcBcm_Subsystem(void)
{
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_n;

  /* RelationalOperator: '<S843>/Relational Operator' incorporates:
   *  Constant: '<S843>/Constant'
   */
  rtb_RelationalOperator = (AppSwcBcm_ARID_DEF.CCaller36 == 1);

  /* RelationalOperator: '<S843>/Relational Operator1' incorporates:
   *  Constant: '<S843>/Constant1'
   */
  rtb_RelationalOperator1_n = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* Switch: '<S843>/Switch' incorporates:
   *  Logic: '<S843>/Logical Operator'
   *  Logic: '<S843>/Logical Operator1'
   *  Logic: '<S843>/Logical Operator2'
   *  Logic: '<S843>/Logical Operator3'
   *  Switch: '<S843>/Switch1'
   */
  if (rtb_RelationalOperator && rtb_RelationalOperator1_n) {
    /* Switch: '<S843>/Switch' incorporates:
     *  Constant: '<S843>/Constant2'
     */
    PDUCtl_SysPwrModeAct = 2U;
  } else if ((!rtb_RelationalOperator) && (!rtb_RelationalOperator1_n)) {
    /* Switch: '<S843>/Switch1' incorporates:
     *  Constant: '<S843>/Constant3'
     *  Switch: '<S843>/Switch'
     */
    PDUCtl_SysPwrModeAct = 0U;
  }

  /* End of Switch: '<S843>/Switch' */
}

/* Output and update for atomic system: '<S627>/Truth Table' */
static void AppSwcBcm_TruthTable_m(void)
{
  /* UnitDelay: '<S836>/Unit Delay' */
  /*  Example condition 1 */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aud) {
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

  /* End of UnitDelay: '<S836>/Unit Delay' */
}

/* System initialize for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S627>/StartReq' */
  AppSwcBcm_StartReq_Init();

  /* End of SystemInitialize for SubSystem: '<S627>/StartReq' */
}

/* Output and update for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl(void)
{
  boolean rtb_DataTypeConversion_l;

  /* Chart: '<S627>/Chart' */
  AppSwcBcm_Chart();

  /* Outputs for Atomic SubSystem: '<S627>/PwrOn' */
  AppSwcBcm_PwrOn();

  /* End of Outputs for SubSystem: '<S627>/PwrOn' */

  /* Outputs for Atomic SubSystem: '<S627>/PwrOff' */
  AppSwcBcm_PwrOff();

  /* End of Outputs for SubSystem: '<S627>/PwrOff' */

  /* Outputs for Atomic SubSystem: '<S627>/Lib_SR' */
  /* Switch: '<S836>/Switch' incorporates:
   *  Constant: '<S836>/Constant'
   *  Logic: '<S836>/Logical Operator'
   *  UnitDelay: '<S836>/Unit Delay'
   */
  if (PDUCtl_PwrOff) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aud = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aud = (PDUCtl_PwrOn ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aud);
  }

  /* End of Switch: '<S836>/Switch' */
  /* End of Outputs for SubSystem: '<S627>/Lib_SR' */

  /* Truth Table: '<S627>/Truth Table' */
  AppSwcBcm_TruthTable_m();

  /* Outputs for Atomic SubSystem: '<S627>/Ovrd1' */
  /* Switch: '<S837>/Switch1' incorporates:
   *  Constant: '<S627>/Constant18'
   *  Constant: '<S627>/Constant19'
   */
  if (PDUCtl_J421IG1RlyCtlOvrdFlg_C) {
    PDUCtl_J421IG1RlyCtl = (uint8)PDUCtl_J421IG1RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S627>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG1RlyCtlFlg != 0);

    /* Switch: '<S837>/Switch2' */
    if (rtb_DataTypeConversion_l) {
      PDUCtl_J421IG1RlyCtl = 1U;
    } else {
      PDUCtl_J421IG1RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J421;
    }

    /* End of Switch: '<S837>/Switch2' */
  }

  /* End of Switch: '<S837>/Switch1' */
  /* End of Outputs for SubSystem: '<S627>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S627>/Ovrd2' */
  /* Switch: '<S838>/Switch1' incorporates:
   *  Constant: '<S627>/Constant1'
   *  Constant: '<S627>/Constant2'
   */
  if (PDUCtl_J437IG2RlyCtlOvrdFlg_C) {
    PDUCtl_J437IG2RlyCtl = (uint8)PDUCtl_J437IG2RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S627>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_l = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG2RlyCtlFlg != 0);

    /* Switch: '<S838>/Switch2' */
    if (rtb_DataTypeConversion_l) {
      PDUCtl_J437IG2RlyCtl = 1U;
    } else {
      PDUCtl_J437IG2RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J437;
    }

    /* End of Switch: '<S838>/Switch2' */
  }

  /* End of Switch: '<S838>/Switch1' */
  /* End of Outputs for SubSystem: '<S627>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S627>/RelayDig' */
  AppSwcBcm_RelayDig();

  /* End of Outputs for SubSystem: '<S627>/RelayDig' */

  /* Outputs for Atomic SubSystem: '<S627>/StartReq' */
  AppSwcBcm_StartReq();

  /* End of Outputs for SubSystem: '<S627>/StartReq' */

  /* Outputs for Atomic SubSystem: '<S627>/Subsystem' */
  AppSwcBcm_Subsystem();

  /* End of Outputs for SubSystem: '<S627>/Subsystem' */

  /* Update for UnitDelay: '<S627>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S627>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S627>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_h = PDUCtl_SysPowerSts;

  /* Update for UnitDelay: '<S627>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_k = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S627>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jn = PDUCtl_SysPowerSts;
}

/* System initialize for atomic system: '<S870>/NMCtl' */
static void AppSwcBcm_NMCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;

  /* InitializeConditions for Delay: '<S874>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = true;

  /* InitializeConditions for Delay: '<S875>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = true;

  /* InitializeConditions for Delay: '<S876>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_e = true;

  /* InitializeConditions for Delay: '<S877>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_h = true;

  /* InitializeConditions for Delay: '<S878>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ii = true;

  /* SystemInitialize for Chart: '<S871>/LIB_NegPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_o);
}

/* Outputs for atomic system: '<S870>/NMCtl' */
static void AppSwcBcm_NMCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_o;
  boolean rtb_LogicalOperator9;
  boolean rtb_RelationalOperator15_f;
  boolean rtb_RelationalOperator16_d;
  boolean rtb_RelationalOperator17_h;
  boolean rtb_RelationalOperator18_m;
  boolean rtb_RelationalOperator26;
  boolean rtb_RelationalOperator27;
  boolean rtb_RelationalOperator28;

  /* RelationalOperator: '<S871>/Relational Operator15' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator15_f = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BrakeLightSw;

  /* RelationalOperator: '<S871>/Relational Operator16' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator16_d = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->PosLampSta;

  /* RelationalOperator: '<S871>/Relational Operator17' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator17_h = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->LowBeamSta;

  /* RelationalOperator: '<S871>/Relational Operator18' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator18_m = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HiBeamSta;

  /* RelationalOperator: '<S871>/Relational Operator26' incorporates:
   *  Constant: '<S871>/Constant28'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator26 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->RKEReq != 0);

  /* Delay: '<S874>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_i) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_k =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S875>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_n) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_j =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Delay: '<S876>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_e) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_m =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Delay: '<S877>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_h) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_n =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;
  }

  /* Delay: '<S878>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_ii) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_p =
      AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;
  }

  /* RelationalOperator: '<S871>/Relational Operator27' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S880>/Logical Operator'
   *  Logic: '<S880>/Logical Operator1'
   *  UnitDelay: '<S880>/Unit Delay'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->BrakeLightSw && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dyw));

  /* Logic: '<S871>/Logical Operator10' incorporates:
   *  Delay: '<S874>/Delay'
   *  Delay: '<S875>/Delay'
   *  Delay: '<S876>/Delay'
   *  Delay: '<S877>/Delay'
   *  Delay: '<S878>/Delay'
   *  Logic: '<S874>/Logical Operator1'
   *  Logic: '<S874>/Logical Operator2'
   *  Logic: '<S874>/Logical Operator3'
   *  Logic: '<S874>/Logical Operator4'
   *  Logic: '<S874>/Logical Operator5'
   *  Logic: '<S875>/Logical Operator1'
   *  Logic: '<S875>/Logical Operator2'
   *  Logic: '<S875>/Logical Operator3'
   *  Logic: '<S875>/Logical Operator4'
   *  Logic: '<S875>/Logical Operator5'
   *  Logic: '<S876>/Logical Operator1'
   *  Logic: '<S876>/Logical Operator2'
   *  Logic: '<S876>/Logical Operator3'
   *  Logic: '<S876>/Logical Operator4'
   *  Logic: '<S876>/Logical Operator5'
   *  Logic: '<S877>/Logical Operator1'
   *  Logic: '<S877>/Logical Operator2'
   *  Logic: '<S877>/Logical Operator3'
   *  Logic: '<S877>/Logical Operator4'
   *  Logic: '<S877>/Logical Operator5'
   *  Logic: '<S878>/Logical Operator1'
   *  Logic: '<S878>/Logical Operator2'
   *  Logic: '<S878>/Logical Operator3'
   *  Logic: '<S878>/Logical Operator4'
   *  Logic: '<S878>/Logical Operator5'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator26 ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_k &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_k))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_j &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_j))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_m &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_m))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_n &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_n))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_p &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_p))) || rtb_RelationalOperator27);

  /* RelationalOperator: '<S871>/Relational Operator27' incorporates:
   *  Constant: '<S871>/Constant29'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->DrvPEAuthentAcsd == 1);

  /* Logic: '<S871>/Logical Operator6' */
  AppSwcBcm_ARID_DEF.LogicalOperator6 = (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    rtb_RelationalOperator27);

  /* RelationalOperator: '<S871>/Relational Operator28' incorporates:
   *  Constant: '<S871>/Constant30'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator28 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->FRPEAuthentAcsd == 1);

  /* Logic: '<S871>/Logical Operator7' */
  AppSwcBcm_ARID_DEF.LogicalOperator7 = (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
    rtb_RelationalOperator28);

  /* Logic: '<S871>/Logical Operator9' incorporates:
   *  Logic: '<S881>/Logical Operator'
   *  Logic: '<S881>/Logical Operator1'
   *  Logic: '<S882>/Logical Operator'
   *  Logic: '<S882>/Logical Operator1'
   *  UnitDelay: '<S881>/Unit Delay'
   *  UnitDelay: '<S882>/Unit Delay'
   */
  rtb_LogicalOperator9 = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.LogicalOperator6 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jp)) ||
    (AppSwcBcm_ARID_DEF.LogicalOperator7 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cr)));

  /* Chart: '<S871>/LIB_NegPluse2' incorporates:
   *  Constant: '<S871>/Constant'
   *  Constant: '<S871>/Constant19'
   *  Constant: '<S871>/Constant22'
   *  Logic: '<S871>/Logical Operator'
   *  Logic: '<S871>/Logical Operator1'
   *  Logic: '<S871>/Logical Operator3'
   *  RelationalOperator: '<S871>/Relational Operator'
   *  RelationalOperator: '<S871>/Relational Operator19'
   *  RelationalOperator: '<S871>/Relational Operator20'
   *  RelationalOperator: '<S871>/Relational Operator21'
   */
  AppSwcBcm_LIB_PosPluse2((AppSwcBcm_ARID_DEF.BusCreator1.SysPwrMode == 0) &&
    rtb_RelationalOperator15_f && rtb_RelationalOperator16_d &&
    rtb_RelationalOperator17_h && rtb_RelationalOperator18_m &&
    (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 2) &&
    ((!AppSwcBcm_ARID_DEF.BusCreator4.AutoLckSta) ||
     AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw),
    WakeUpCtl_CANSleepDelayTim_C, rtb_LogicalOperator9, &rtb_LIB_blOut_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse2);

  /* Logic: '<S871>/Logical Operator2' incorporates:
   *  Logic: '<S871>/Logical Operator11'
   *  Logic: '<S871>/Logical Operator12'
   *  Logic: '<S871>/Logical Operator4'
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

  /* Switch: '<S883>/Switch' */
  if (rtb_LIB_blOut_o) {
    /* Switch: '<S883>/Switch' incorporates:
     *  Constant: '<S883>/Constant'
     */
    WakeUpCtl_NMReq = false;
  } else {
    /* Switch: '<S883>/Switch' incorporates:
     *  Logic: '<S871>/Logical Operator8'
     *  Logic: '<S879>/Logical Operator'
     *  Logic: '<S879>/Logical Operator1'
     *  Logic: '<S883>/Logical Operator'
     *  UnitDelay: '<S879>/Unit Delay'
     *  UnitDelay: '<S883>/Unit Delay'
     */
    WakeUpCtl_NMReq = ((AppSwcBcm_ARID_DEF.LogicalOperator2 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m)) ||
                       rtb_LogicalOperator9 || WakeUpCtl_NMReq);
  }

  /* End of Switch: '<S883>/Switch' */
}

/* Update for atomic system: '<S870>/NMCtl' */
static void AppSwcBcm_NMCtl_Update(void)
{
  /* Update for Delay: '<S874>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_k =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S875>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_j =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

  /* Update for Delay: '<S876>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_e = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_m =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S877>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_h = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_n =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

  /* Update for Delay: '<S878>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ii = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_p = AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

  /* Update for UnitDelay: '<S880>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dyw =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S881>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jp = AppSwcBcm_ARID_DEF.LogicalOperator6;

  /* Update for UnitDelay: '<S882>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_cr = AppSwcBcm_ARID_DEF.LogicalOperator7;

  /* Update for UnitDelay: '<S879>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m = AppSwcBcm_ARID_DEF.LogicalOperator2;
}

/* System initialize for atomic system: '<S870>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_m;

  /* InitializeConditions for Delay: '<S887>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad = true;

  /* SystemInitialize for Chart: '<S872>/LIB_NegPluse1' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_m);
}

/* Outputs for atomic system: '<S870>/SleepCtl' */
static void AppSwcBcm_SleepCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_m;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator4_jy;
  boolean rtb_LogicalOperator_au;

  /* Logic: '<S890>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S872>/Relational Operator24'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BoxLampSta;

  /* Logic: '<S872>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S872>/Relational Operator23'
   *  RelationalOperator: '<S872>/Relational Operator25'
   */
  rtb_LogicalOperator4_jy = ((!WakeUpCtl_NMReq) && rtb_LogicalOperator &&
    (!AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr));

  /* RelationalOperator: '<S872>/Relational Operator29' incorporates:
   *  Constant: '<S872>/Constant31'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator29 = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S872>/Relational Operator30' incorporates:
   *  Constant: '<S872>/Constant32'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator30 = (AppSwcBcm_ARID_DEF.CCaller36 == 1);

  /* Delay: '<S887>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  if (AppSwcBcm_ARID_DEF.icLoad) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_g =
      (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;
  }

  /* Logic: '<S890>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S887>/Logical Operator1'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl;

  /* Logic: '<S889>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Delay: '<S887>/Delay'
   *  Logic: '<S887>/Logical Operator3'
   *  Logic: '<S887>/Logical Operator4'
   */
  rtb_LogicalOperator_au = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())
    ->HornSwCtl && (!AppSwcBcm_ARID_DEF.Delay_DSTATE_g));

  /* Logic: '<S872>/Logical Operator13' incorporates:
   *  Delay: '<S887>/Delay'
   *  Logic: '<S887>/Logical Operator2'
   *  Logic: '<S887>/Logical Operator5'
   *  Logic: '<S889>/Logical Operator'
   *  Logic: '<S889>/Logical Operator1'
   *  Logic: '<S890>/Logical Operator'
   *  Logic: '<S890>/Logical Operator1'
   *  Logic: '<S891>/Logical Operator'
   *  Logic: '<S891>/Logical Operator1'
   *  Logic: '<S892>/Logical Operator'
   *  Logic: '<S892>/Logical Operator1'
   *  UnitDelay: '<S889>/Unit Delay'
   *  UnitDelay: '<S890>/Unit Delay'
   *  UnitDelay: '<S891>/Unit Delay'
   *  UnitDelay: '<S892>/Unit Delay'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator29 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aj)) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator30 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e2)) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_g && rtb_LogicalOperator) ||
     rtb_LogicalOperator_au) || (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nj)) ||
    (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fj)));

  /* Chart: '<S872>/LIB_NegPluse1' incorporates:
   *  Constant: '<S872>/Constant27'
   */
  AppSwcBcm_LIB_PosPluse2(rtb_LogicalOperator4_jy,
    WakeUpCtl_LocalSleepDelayTim_C, rtb_LogicalOperator, &rtb_LIB_blOut_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse1);

  /* Logic: '<S872>/Logical Operator3' */
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

  /* Switch: '<S893>/Switch' incorporates:
   *  Constant: '<S893>/Constant'
   *  Logic: '<S872>/Logical Operator14'
   *  Logic: '<S888>/Logical Operator'
   *  Logic: '<S888>/Logical Operator1'
   *  Logic: '<S893>/Logical Operator'
   *  UnitDelay: '<S888>/Unit Delay'
   *  UnitDelay: '<S893>/Unit Delay'
   */
  if (rtb_LIB_blOut_m) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hz = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hz =
      ((AppSwcBcm_ARID_DEF.LogicalOperator3 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_eg)) || rtb_LogicalOperator ||
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hz);
  }

  /* End of Switch: '<S893>/Switch' */

  /* Logic: '<S872>/Logical Operator5' incorporates:
   *  UnitDelay: '<S893>/Unit Delay'
   */
  WakeUpCtl_SleepAllwd = !AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hz;
}

/* Update for atomic system: '<S870>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Update(void)
{
  /* Update for UnitDelay: '<S891>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_aj =
    AppSwcBcm_ARID_DEF.RelationalOperator29;

  /* Update for UnitDelay: '<S892>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e2 =
    AppSwcBcm_ARID_DEF.RelationalOperator30;

  /* Update for Delay: '<S887>/Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.icLoad = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus())->HornSwCtl;

  /* Update for UnitDelay: '<S889>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nj =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw;

  /* Update for UnitDelay: '<S890>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_fj =
    AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw;

  /* Update for UnitDelay: '<S888>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_eg = AppSwcBcm_ARID_DEF.LogicalOperator3;
}

/* System initialize for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S870>/NMCtl' */
  AppSwcBcm_NMCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S870>/NMCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S870>/SleepCtl' */
  AppSwcBcm_SleepCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S870>/SleepCtl' */
}

/* Outputs for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl(void)
{
  /* SignalConversion: '<S628>/Signal Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  BSW_WakeupReas = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VBSW_WakeupReasn_enum;

  /* RelationalOperator: '<S870>/Relational Operator14' incorporates:
   *  Constant: '<S870>/Constant14'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator14 = (BSW_WakeupReas == 49);

  /* RelationalOperator: '<S870>/Relational Operator1' incorporates:
   *  Constant: '<S870>/Constant1'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator1 = (BSW_WakeupReas == 54);

  /* RelationalOperator: '<S870>/Relational Operator5' incorporates:
   *  Constant: '<S870>/Constant5'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator5 = (BSW_WakeupReas == 58);

  /* RelationalOperator: '<S870>/Relational Operator6' incorporates:
   *  Constant: '<S870>/Constant6'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator6 = (BSW_WakeupReas == 59);

  /* RelationalOperator: '<S870>/Relational Operator7' incorporates:
   *  Constant: '<S870>/Constant7'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator7 = (BSW_WakeupReas == 61);

  /* RelationalOperator: '<S870>/Relational Operator8' incorporates:
   *  Constant: '<S870>/Constant8'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8 = (BSW_WakeupReas == 62);

  /* RelationalOperator: '<S870>/Relational Operator4' incorporates:
   *  Constant: '<S870>/Constant4'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4 = (BSW_WakeupReas == 57);

  /* RelationalOperator: '<S870>/Relational Operator9' incorporates:
   *  Constant: '<S870>/Constant9'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9 = (BSW_WakeupReas == 63);

  /* RelationalOperator: '<S870>/Relational Operator10' incorporates:
   *  Constant: '<S870>/Constant10'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator10 = (BSW_WakeupReas == 64);

  /* RelationalOperator: '<S870>/Relational Operator13' incorporates:
   *  Constant: '<S870>/Constant13'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 17);

  /* Outputs for Atomic SubSystem: '<S870>/NMCtl' */
  AppSwcBcm_NMCtl();

  /* End of Outputs for SubSystem: '<S870>/NMCtl' */

  /* RelationalOperator: '<S870>/Relational Operator12' incorporates:
   *  Constant: '<S870>/Constant12'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 66);

  /* RelationalOperator: '<S870>/Relational Operator22' incorporates:
   *  Constant: '<S870>/Constant23'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator22 = (BSW_WakeupReas == 50);

  /* Outputs for Atomic SubSystem: '<S870>/SleepCtl' */
  AppSwcBcm_SleepCtl();

  /* End of Outputs for SubSystem: '<S870>/SleepCtl' */
}

/* Update for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S870>/NMCtl' */
  AppSwcBcm_NMCtl_Update();

  /* End of Update for SubSystem: '<S870>/NMCtl' */

  /* Update for Atomic SubSystem: '<S870>/SleepCtl' */
  AppSwcBcm_SleepCtl_Update();

  /* End of Update for SubSystem: '<S870>/SleepCtl' */
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

  /* End of BusCreator: '<S3>/Bus Creator12' */

  /* CCaller: '<S3>/C Caller31' */
  BSW_J319HornSw = GetHw_AlrmHornSw();

  /* SignalConversion generated from: '<S3>/IPM_HU_B_BAC' incorporates:
   *  Inport: '<Root>/IPM_HU_B_BAC'
   */
  AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC();

  /* CCaller: '<S3>/C Caller15' */
  AppSwcBcm_ARID_DEF.CCaller15 = GetHw_CrashPWMSta();

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
  AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e =
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
    (&AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e);

  /* Outport: '<Root>/Bcm2OpmBAC_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m);

  /* Outport: '<Root>/Bcm2OpmOBD_outputs' incorporates:
   *  BusCreator: '<S230>/Bus Creator3'
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
  uint8 rtb_CCaller39;
  uint8 rtb_CCaller40;
  boolean rtb_DataTypeConversion2_i;
  boolean rtb_DataTypeConversion3_i;
  boolean rtb_RelationalOperator1_bk;
  boolean rtb_Switch;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.EEReadCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();

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
  AppSwcBcm_ARID_DEF.UnitDelay2 = AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jc;

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
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkHUUnlck = DoorLckCtl_TrunkHUUnlck;
  AppSwcBcm_ARID_DEF.BusCreator4.TrunkAutoLck = DoorLckCtl_TrunkAutoLck;

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

  /* SignalConversion: '<S624>/Signal Conversion' */
  DynDID_0xF22CAntitheftSta = AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts;

  /* Truth Table: '<S790>/Truth Table' */
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
    /* Switch: '<S790>/Switch' incorporates:
     *  UnitDelay: '<S790>/Unit Delay'
     */
    /*  Example action 1 called from D1 & D2 column in condition table */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 10U;
  } else {
    rtb_DataTypeConversion3_i = !AppSwcBcm_ARID_DEF.BusCreator4.CrshUnlck;
    if (rtb_DataTypeConversion3_i &&
        AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck) {
      /* Switch: '<S790>/Switch' incorporates:
       *  UnitDelay: '<S790>/Unit Delay'
       */
      /*  Example action 2 called from D3 column in condition table */
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 15U;
    } else {
      rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
        (!AppSwcBcm_ARID_DEF.BusCreator4.ThermRunawayUnlck));
      if (rtb_DataTypeConversion3_i && AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck)
      {
        /* Switch: '<S790>/Switch' incorporates:
         *  UnitDelay: '<S790>/Unit Delay'
         */
        AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 11U;
      } else {
        rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
          (!AppSwcBcm_ARID_DEF.BusCreator4.MechUnlck));
        if (rtb_DataTypeConversion3_i && AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck)
        {
          /* Switch: '<S790>/Switch' incorporates:
           *  UnitDelay: '<S790>/Unit Delay'
           */
          AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 8U;
        } else {
          rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
            (!AppSwcBcm_ARID_DEF.BusCreator4.HUUnlck));
          if (rtb_DataTypeConversion3_i &&
              AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck) {
            /* Switch: '<S790>/Switch' incorporates:
             *  UnitDelay: '<S790>/Unit Delay'
             */
            AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 12U;
          } else {
            rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
              (!AppSwcBcm_ARID_DEF.BusCreator4.RKEUnlck));
            if (rtb_DataTypeConversion3_i &&
                AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck) {
              /* Switch: '<S790>/Switch' incorporates:
               *  UnitDelay: '<S790>/Unit Delay'
               */
              AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 13U;
            } else {
              rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                (!AppSwcBcm_ARID_DEF.BusCreator4.PEUnlck));
              if (rtb_DataTypeConversion3_i &&
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck) {
                /* Switch: '<S790>/Switch' incorporates:
                 *  UnitDelay: '<S790>/Unit Delay'
                 */
                AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 15U;
              } else {
                rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                  (!AppSwcBcm_ARID_DEF.BusCreator4.DoorProtUnlck));
                if (rtb_DataTypeConversion3_i &&
                    AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck) {
                  /* Switch: '<S790>/Switch' incorporates:
                   *  UnitDelay: '<S790>/Unit Delay'
                   */
                  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 19U;
                } else {
                  rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                    (!AppSwcBcm_ARID_DEF.BusCreator4.ParkUnlck));
                  if (rtb_DataTypeConversion3_i &&
                      AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck) {
                    /* Switch: '<S790>/Switch' incorporates:
                     *  UnitDelay: '<S790>/Unit Delay'
                     */
                    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 17U;
                  } else {
                    rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                      (!AppSwcBcm_ARID_DEF.BusCreator4.WelcomeUnlck));
                    if (rtb_DataTypeConversion3_i &&
                        AppSwcBcm_ARID_DEF.BusCreator4.MechLck) {
                      /* Switch: '<S790>/Switch' incorporates:
                       *  UnitDelay: '<S790>/Unit Delay'
                       */
                      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 7U;
                    } else {
                      rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                        (!AppSwcBcm_ARID_DEF.BusCreator4.MechLck));
                      if (rtb_DataTypeConversion3_i &&
                          AppSwcBcm_ARID_DEF.BusCreator4.HULck) {
                        /* Switch: '<S790>/Switch' incorporates:
                         *  UnitDelay: '<S790>/Unit Delay'
                         */
                        AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 1U;
                      } else {
                        rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i &&
                          (!AppSwcBcm_ARID_DEF.BusCreator4.HULck));
                        if (rtb_DataTypeConversion3_i &&
                            AppSwcBcm_ARID_DEF.BusCreator4.SpdLck) {
                          /* Switch: '<S790>/Switch' incorporates:
                           *  UnitDelay: '<S790>/Unit Delay'
                           */
                          AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 2U;
                        } else {
                          rtb_DataTypeConversion3_i = (rtb_DataTypeConversion3_i
                            && (!AppSwcBcm_ARID_DEF.BusCreator4.SpdLck));
                          if (rtb_DataTypeConversion3_i &&
                              AppSwcBcm_ARID_DEF.BusCreator4.PELck) {
                            /* Switch: '<S790>/Switch' incorporates:
                             *  UnitDelay: '<S790>/Unit Delay'
                             */
                            AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 5U;
                          } else {
                            rtb_DataTypeConversion3_i =
                              (rtb_DataTypeConversion3_i &&
                               (!AppSwcBcm_ARID_DEF.BusCreator4.PELck));
                            if (rtb_DataTypeConversion3_i &&
                                AppSwcBcm_ARID_DEF.BusCreator4.AutoLck) {
                              /* Switch: '<S790>/Switch' incorporates:
                               *  UnitDelay: '<S790>/Unit Delay'
                               */
                              AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 3U;
                            } else {
                              rtb_DataTypeConversion3_i =
                                (rtb_DataTypeConversion3_i &&
                                 (!AppSwcBcm_ARID_DEF.BusCreator4.AutoLck));
                              if (rtb_DataTypeConversion3_i &&
                                  AppSwcBcm_ARID_DEF.BusCreator4.RKELck) {
                                /* Switch: '<S790>/Switch' incorporates:
                                 *  UnitDelay: '<S790>/Unit Delay'
                                 */
                                AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 4U;
                              } else if (rtb_DataTypeConversion3_i &&
                                         (!AppSwcBcm_ARID_DEF.BusCreator4.RKELck)
                                         &&
                                         AppSwcBcm_ARID_DEF.BusCreator4.WelcomeLck)
                              {
                                /* Switch: '<S790>/Switch' incorporates:
                                 *  UnitDelay: '<S790>/Unit Delay'
                                 */
                                AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = 18U;
                              } else {
                                /*  Default */
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

  /* End of Truth Table: '<S790>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_g) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF230DoorOpRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.DoorOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_g = true;
  }

  /* UnitDelay: '<S790>/Unit Delay' */
  AppSwcBcm_ARID_DEF.Lib_In_h = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f;

  /* Chart: '<S790>/Chart' incorporates:
   *  SubSystem: '<S799>/Lib_ChgDet'
   */
  AppSwcBcm_Lib_ChgDet(AppSwcBcm_ARID_DEF.Lib_In_h,
                       &AppSwcBcm_ARID_DEF.RelationalOperator_k,
                       &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChgDet_j);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_k) {
    i = AppSwcBcm_ARID_DEF.i_j + 1;
    if (AppSwcBcm_ARID_DEF.i_j + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_j = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_j > 10) {
      AppSwcBcm_ARID_DEF.i_j = 1U;
    }

    /* UnitDelay: '<S790>/Unit Delay' */
    DynDID_0xF230DoorOpRecord[AppSwcBcm_ARID_DEF.i_j - 1] =
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f;
  }

  /* Truth Table: '<S791>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkRkEUnlck) {
    /* Switch: '<S791>/Switch' incorporates:
     *  UnitDelay: '<S791>/Unit Delay'
     */
    /*  Example action 1 called from D1 & D2 column in condition table */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_de = 5U;
  }

  /* End of Truth Table: '<S791>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_e) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF231TrunkOpRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.TrunkOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_e = true;
  }

  /* UnitDelay: '<S791>/Unit Delay' */
  AppSwcBcm_ARID_DEF.Lib_In_b = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_de;

  /* Chart: '<S791>/Chart' incorporates:
   *  SubSystem: '<S803>/Lib_ChgDet'
   */
  AppSwcBcm_Lib_ChgDet(AppSwcBcm_ARID_DEF.Lib_In_b,
                       &AppSwcBcm_ARID_DEF.RelationalOperator_a,
                       &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChgDet_l);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_a) {
    i = AppSwcBcm_ARID_DEF.i_g + 1;
    if (AppSwcBcm_ARID_DEF.i_g + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_g = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_g > 10) {
      AppSwcBcm_ARID_DEF.i_g = 1U;
    }

    /* UnitDelay: '<S791>/Unit Delay' */
    DynDID_0xF231TrunkOpRecord[AppSwcBcm_ARID_DEF.i_g - 1] =
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_de;
  }

  /* Chart: '<S794>/Chart' */
  DynDID_0xF234ADSampleValue[1] = 0U;
  DynDID_0xF234ADSampleValue[2] = 0U;

  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Default */
  if (!AppSwcBcm_ARID_DEF.Flg_an) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF232LocalStartUpFailRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.LocalStartFailOpRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_an = true;
  }

  /* UnitDelay: '<S792>/Unit Delay' */
  AppSwcBcm_ARID_DEF.Lib_In_k = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_es;

  /* Chart: '<S792>/Chart' incorporates:
   *  SubSystem: '<S807>/Lib_ChgDet'
   */
  AppSwcBcm_Lib_ChgDet(AppSwcBcm_ARID_DEF.Lib_In_k,
                       &AppSwcBcm_ARID_DEF.RelationalOperator_j,
                       &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChgDet_p);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_j) {
    i = AppSwcBcm_ARID_DEF.i_o + 1;
    if (AppSwcBcm_ARID_DEF.i_o + 1 > 255) {
      i = 255;
    }

    AppSwcBcm_ARID_DEF.i_o = (uint8)i;
    if (AppSwcBcm_ARID_DEF.i_o > 10) {
      AppSwcBcm_ARID_DEF.i_o = 1U;
    }
  }

  /* Truth Table: '<S793>/Truth Table' */
  /*  Example condition 1 */
  /*  Example condition 2 */
  /*  Condition #3 */
  if ((AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 3) ||
      (AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts == 5)) {
    /* Switch: '<S793>/Switch' incorporates:
     *  UnitDelay: '<S793>/Unit Delay'
     */
    /*  Example action 1 called from D1 & D2 column in condition table */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c = 1U;
  } else if (AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts != 1) {
    /* Switch: '<S793>/Switch' incorporates:
     *  UnitDelay: '<S793>/Unit Delay'
     */
    /*  Example action 2 called from D3 column in condition table */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c = 2U;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw) {
    /* Switch: '<S793>/Switch' incorporates:
     *  UnitDelay: '<S793>/Unit Delay'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c = 3U;
  } else {
    /*  Default */
  }

  /* End of Truth Table: '<S793>/Truth Table' */
  if (!AppSwcBcm_ARID_DEF.Flg_a) {
    for (i = 0; i < 10; i++) {
      DynDID_0xF233RemoteStartUpFailRecord[i] =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.RemoteStartFailRecord[i];
    }

    AppSwcBcm_ARID_DEF.Flg_a = true;
  }

  /* UnitDelay: '<S793>/Unit Delay' */
  AppSwcBcm_ARID_DEF.Lib_In = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_c;

  /* Chart: '<S793>/Chart' incorporates:
   *  SubSystem: '<S811>/Lib_ChgDet'
   */
  AppSwcBcm_Lib_ChgDet(AppSwcBcm_ARID_DEF.Lib_In,
                       &AppSwcBcm_ARID_DEF.RelationalOperator,
                       &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_ChgDet);
  if (AppSwcBcm_ARID_DEF.RelationalOperator) {
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

  /* Switch: '<S819>/Switch' incorporates:
   *  Constant: '<S819>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   *  RelationalOperator: '<S819>/Relational Operator'
   *  RelationalOperator: '<S819>/Relational Operator1'
   */
  rtb_Switch = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus())->DrvWinSta != 0);

  /* RelationalOperator: '<S819>/Relational Operator1' incorporates:
   *  Constant: '<S819>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
   */
  rtb_RelationalOperator1_bk = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_WinCtl_Bus()
    )->PsgWinSta != 0);

  /* Chart: '<S796>/Chart' incorporates:
   *  Constant: '<S818>/Constant'
   *  Constant: '<S818>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S818>/Logical Operator'
   *  Logic: '<S818>/Logical Operator1'
   *  RelationalOperator: '<S818>/Relational Operator'
   *  RelationalOperator: '<S818>/Relational Operator1'
   *  RelationalOperator: '<S818>/Relational Operator2'
   *  RelationalOperator: '<S818>/Relational Operator3'
   *  Switch: '<S819>/Switch1'
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
  DynDID_0xF236DigtOutSampleValue[3] = (uint8)(rtb_RelationalOperator1_bk << 4 |
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

  /* End of Chart: '<S796>/Chart' */

  /* SignalConversion: '<S624>/Signal Conversion1' */
  DynDID_0xF237PwrModeSta = AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts;

  /* CCaller: '<S4>/C Caller39' incorporates:
   *  CCaller: '<S4>/C Caller11'
   */
  rtb_CCaller39 = GetHw_KL15B();

  /* DataTypeConversion: '<S4>/Data Type Conversion1' */
  rtb_DataTypeConversion3_i = (rtb_CCaller39 != 0);

  /* CCaller: '<S4>/C Caller39' */
  rtb_CCaller39 = GetHw_KL15A();

  /* RelationalOperator: '<S624>/Relational Operator' */
  rtb_DataTypeConversion2_i = !AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Logic: '<S798>/Logical Operator' */
  rtb_Switch = (AppSwcBcm_ARID_DEF.BusCreator4.InsLck ||
                AppSwcBcm_ARID_DEF.BusCreator4.OsLck);

  /* Logic: '<S798>/Logical Operator1' */
  rtb_RelationalOperator1_bk = (AppSwcBcm_ARID_DEF.BusCreator4.InsUnlck ||
    AppSwcBcm_ARID_DEF.BusCreator4.OsUnlck);

  /* CCaller: '<S4>/C Caller40' */
  rtb_CCaller40 = GetHw_WiprStopPstnDtct();

  /* Chart: '<S795>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   *  RelationalOperator: '<S624>/Relational Operator'
   * */
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(DynDID_0xF235DigtInSampleValue[0] |
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)(rtb_DataTypeConversion3_i << 1 |
    DynDID_0xF235DigtInSampleValue[0]);
  DynDID_0xF235DigtInSampleValue[0] = (uint8)((rtb_CCaller39 != 0) << 2 |
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
    rtb_RelationalOperator1_bk);
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

  /* End of Chart: '<S795>/Chart' */

  /* BusCreator: '<S4>/Bus Creator' */
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

  /* CCaller: '<S789>/C Caller' incorporates:
   *  Constant: '<S789>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator2.BodyWarnSts, 61996U);

  /* CCaller: '<S793>/C Caller' incorporates:
   *  Constant: '<S793>/Constant'
   *  Constant: '<S793>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF233RemoteStartUpFailRecord[0], 10U,
                     62003U);

  /* CCaller: '<S796>/C Caller' incorporates:
   *  Constant: '<S796>/Constant'
   *  Constant: '<S796>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF236DigtOutSampleValue[0], 5U, 62006U);

  /* CCaller: '<S797>/C Caller' incorporates:
   *  Constant: '<S797>/Constant'
   */
  UpdateDIDData(AppSwcBcm_ARID_DEF.BusCreator1.SysPowerSts, 62007U);

  /* CCaller: '<S790>/C Caller' incorporates:
   *  Constant: '<S790>/Constant'
   *  Constant: '<S790>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF230DoorOpRecord[0], 10U, 62000U);

  /* CCaller: '<S791>/C Caller' incorporates:
   *  Constant: '<S791>/Constant'
   *  Constant: '<S791>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF231TrunkOpRecord[0], 10U, 62001U);

  /* CCaller: '<S794>/C Caller' incorporates:
   *  Constant: '<S794>/Constant'
   *  Constant: '<S794>/Constant1'
   */
  UpdateDIDDataArray((uint8 *)&DynDID_0xF234ADSampleValue[0], 23U, 62004U);

  /* CCaller: '<S792>/C Caller' incorporates:
   *  Constant: '<S792>/Constant'
   *  Constant: '<S792>/Constant1'
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
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_jc =
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
  boolean rtb_RelationalOperator;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.DynDID_Bus = *Rte_IrvIRead_Runbl_AppSwcBcm_100ms_DynDID_Bus
    ();

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

  /* CCaller: '<S1>/C Caller14' */
  BSW_CN744DrvSeatResis = GetHw_DrvSeatTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SeatCtl' */
  /* DataTypeConversion: '<S129>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S129>/Data Type Conversion1'
   *  Lookup_n-D: '<S129>/1-D Lookup Table2'
   */
  SeatCtl_DrvSeatTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_CN744DrvSeatResis, (const float32 *)&SeatCtl_DrvSeatTempLookUp_X[0], (
    const float32 *)&SeatCtl_DrvSeatTempLookUp_Y[0], 23U));

  /* RelationalOperator: '<S132>/Relational Operator' incorporates:
   *  Constant: '<S129>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S129>/Relational Operator1'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S129>/Switch' */
  if (rtb_RelationalOperator) {
    /* Switch: '<S129>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
      ->VIPM_HUMaiDrvrSeatHeat_enum;
  } else {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S129>/Constant10'
     */
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S129>/Switch' */

  /* MultiPortSwitch: '<S129>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S129>/Multiport Switch' incorporates:
     *  Constant: '<S129>/Constant1'
     */
    SeatCtl_MaiDrvSeatStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S129>/Multiport Switch' incorporates:
     *  Constant: '<S129>/Constant2'
     */
    SeatCtl_MaiDrvSeatStFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S129>/Multiport Switch' incorporates:
     *  Constant: '<S129>/Constant3'
     */
    SeatCtl_MaiDrvSeatStFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S129>/Multiport Switch' incorporates:
     *  Constant: '<S129>/Constant4'
     */
    SeatCtl_MaiDrvSeatStFb = 3U;
    break;
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

  /* Chart: '<S129>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_p;
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib == AppSwcBcm_IN_Off_p) {
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    if ((rtb_Switch - SeatCtl_DrvSeatTemp >= SeatCtl_HtDiffTemp_C) &&
        (rtb_Switch != 0)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_On_a;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    }
  } else {
    /* case IN_On: */
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    if ((SeatCtl_DrvSeatTemp >= rtb_Switch) || (rtb_Switch == 0)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_p;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    }
  }

  /* End of Chart: '<S129>/Chart' */

  /* Outputs for Atomic SubSystem: '<S129>/Ovrd' */
  /* Switch: '<S131>/Switch' incorporates:
   *  Constant: '<S129>/Constant18'
   */
  if (SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C) {
    /* Switch: '<S131>/Switch' incorporates:
     *  Constant: '<S129>/Constant19'
     */
    SeatCtl_CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;
  } else {
    /* Switch: '<S131>/Switch' */
    SeatCtl_CN167DrvSeatHtPWM = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
  }

  /* End of Switch: '<S131>/Switch' */
  /* End of Outputs for SubSystem: '<S129>/Ovrd' */
  /* End of Outputs for SubSystem: '<S1>/SeatCtl' */

  /* BusCreator: '<S1>/Bus Creator11' */
  rtb_BusCreator11.MaiDrvSeatStFb = SeatCtl_MaiDrvSeatStFb;
  rtb_BusCreator11.CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWM;
  rtb_BusCreator11.DrvSeatTemp = SeatCtl_DrvSeatTemp;

  /* CCaller: '<S1>/C Caller34' */
  BSW_J134SteerWhlResis = GetHw_SteerWhlTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SteerWhlCtl' */
  /* DataTypeConversion: '<S132>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S132>/Data Type Conversion1'
   *  Lookup_n-D: '<S132>/1-D Lookup Table1'
   */
  SteerWhlCtl_SteerWhlTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_J134SteerWhlResis, (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_X[0],
     (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_Y[0], 2U));

  /* RelationalOperator: '<S132>/Relational Operator' incorporates:
   *  Constant: '<S132>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S132>/Switch' */
  if (rtb_RelationalOperator) {
    /* Switch: '<S132>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
      ->VIPM_HUSteerWhlHeat_enum;
  } else {
    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S132>/Constant4'
     */
    rtb_Switch = 1U;
  }

  /* End of Switch: '<S132>/Switch' */

  /* MultiPortSwitch: '<S132>/Multiport Switch' */
  switch (rtb_Switch) {
   case 1:
    /* MultiPortSwitch: '<S132>/Multiport Switch' incorporates:
     *  Constant: '<S132>/Constant1'
     */
    SteerWhlCtl_SteerWhlHeatSts = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S132>/Multiport Switch' incorporates:
     *  Constant: '<S132>/Constant2'
     */
    SteerWhlCtl_SteerWhlHeatSts = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S132>/Multiport Switch' */

  /* Chart: '<S132>/HeatCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_p;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib == AppSwcBcm_IN_Off_p) {
    if ((SteerWhlCtl_SteerWhlHeatSts != 0) && (SteerWhlCtl_TrgtTemp_C -
         SteerWhlCtl_SteerWhlTemp >= SteerWhlCtl_DiffTemp_C)) {
      AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_On_a;
      AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = true;
    }

    /* case IN_On: */
  } else if ((SteerWhlCtl_SteerWhlHeatSts == 0) || (SteerWhlCtl_SteerWhlTemp >=
              SteerWhlCtl_TrgtTemp_C)) {
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_p;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  }

  /* End of Chart: '<S132>/HeatCtl' */

  /* Outputs for Atomic SubSystem: '<S132>/Ovrd' */
  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S132>/Constant18'
   */
  if (SteerWhlCtl_J447SteerWhlHtOvrdFlg_C) {
    /* Switch: '<S134>/Switch' incorporates:
     *  Constant: '<S132>/Constant19'
     */
    SteerWhlCtl_J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHtOvrdVal_C;
  } else {
    /* Switch: '<S134>/Switch' */
    SteerWhlCtl_J447SteerWhlHt = AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta;
  }

  /* End of Switch: '<S134>/Switch' */
  /* End of Outputs for SubSystem: '<S132>/Ovrd' */
  /* End of Outputs for SubSystem: '<S1>/SteerWhlCtl' */

  /* BusCreator: '<S1>/Bus Creator13' */
  rtb_BusCreator13.SteerWhlHeatSts = SteerWhlCtl_SteerWhlHeatSts;
  rtb_BusCreator13.J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHt;
  rtb_BusCreator13.SteerWhlTemp = SteerWhlCtl_SteerWhlTemp;

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
