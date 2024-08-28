/*
 * File: AppSwcBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1254
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 23 17:11:12 2024
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
#include "monPrmsBcm.h"
#include "calPrmsBcm.h"

/* Named constants for Chart: '<S9>/DrvWinCtl' */
#define AppSwcBcm_IN_AutoDown          ((uint8)1U)
#define AppSwcBcm_IN_ManDown           ((uint8)2U)
#define AppSwcBcm_IN_ManUp             ((uint8)3U)
#define AppSwcBcm_IN_Standby           ((uint8)4U)

/* Named constants for Chart: '<S9>/PsgWinCtl' */
#define AppSwcBcm_IN_AutoDown_g        ((uint8)1U)
#define AppSwcBcm_IN_ManDown_a         ((uint8)2U)
#define AppSwcBcm_IN_ManUp_m           ((uint8)3U)
#define AppSwcBcm_IN_Standby_b         ((uint8)4U)

/* Named constants for Chart: '<S141>/Chart' */
#define AppSwcBcm_IN_Off               ((uint8)1U)
#define AppSwcBcm_IN_On                ((uint8)2U)

/* Named constants for Chart: '<S193>/Chart' */
#define AppSwcBcm_IN_FobidKey          ((uint8)1U)
#define AppSwcBcm_IN_Init              ((uint8)2U)
#define AppSwcBcm_IN_RelesKey          ((uint8)3U)

/* Named constants for Chart: '<S194>/Chart' */
#define AppSwcBcm_IN_Init_l            ((uint8)1U)
#define AppSwcBcm_IN_KeyNotInCar       ((uint8)2U)

/* Named constants for Chart: '<S194>/Chart3' */
#define AppSwcBcm_IN_Finish            ((uint8)1U)
#define AppSwcBcm_IN_KeyValid          ((uint8)3U)

/* Named constants for Chart: '<S195>/Chart' */
#define AppSwcBcm_IN_LSeekKeyOut       ((uint8)2U)
#define AppSwcBcm_IN_RSeekKeyOut       ((uint8)3U)

/* Named constants for Chart: '<S195>/Chart3' */
#define AppSwcBcm_IN_KeyValid_e        ((uint8)2U)

/* Named constants for Chart: '<S196>/Chart' */
#define AppSwcBcm_IN_PSSeekKeyOut      ((uint8)2U)

/* Named constants for Chart: '<S196>/Chart1' */
#define AppSwcBcm_IN_IMMOKeyValid      ((uint8)1U)
#define AppSwcBcm_IN_RemoteKeyValid    ((uint8)3U)

/* Named constants for Chart: '<S196>/Chart2' */
#define AppSwcBcm_IN_NOKeyValid        ((uint8)2U)

/* Named constants for Chart: '<S197>/Chart' */
#define AppSwcBcm_IN_LockWlcm          ((uint8)2U)
#define AppSwcBcm_IN_UnlockDay0to4     ((uint8)3U)
#define AppSwcBcm_IN_UnlockDay4to7     ((uint8)4U)
#define AppSwcBcm_IN_UnlockExcedDay7   ((uint8)5U)
#define AppSwcBcm_IN_WlcmLockReq       ((uint8)6U)
#define AppSwcBcm_IN_WlcmUnlockReq     ((uint8)7U)

/* Named constants for Chart: '<S262>/Alarm' */
#define AppSwcBcm_IN_SetON             ((uint8)1U)
#define AppSwcBcm_IN_SetOff            ((uint8)2U)

/* Named constants for Chart: '<S271>/Chart' */
#define AppSwcBcm_IN_Delay             ((uint8)1U)
#define AppSwcBcm_IN_SetOn             ((uint8)3U)

/* Named constants for Chart: '<S303>/Chart' */
#define AppSwcBcm_IN_Off_i             ((uint8)1U)
#define AppSwcBcm_IN_On_i              ((uint8)2U)

/* Named constants for Chart: '<S307>/Chart' */
#define AppSwcBcm_IN_Day               ((uint8)1U)
#define AppSwcBcm_IN_Night             ((uint8)2U)

/* Named constants for Chart: '<S419>/Chart' */
#define AppSwcBcm_IN_NO_ACTIVE_CHILD   ((uint8)0U)
#define AppSwcBcm_IN_SetOff_o          ((uint8)1U)
#define AppSwcBcm_IN_SetOn_c           ((uint8)2U)

/* Named constants for Chart: '<S420>/Chart' */
#define AppSwcBcm_IN_Off_a             ((uint8)1U)
#define AppSwcBcm_IN_On_n              ((uint8)2U)

/* Named constants for Chart: '<S422>/Chart' */
#define AppSwcBcm_IN_CrashOff          ((uint8)1U)
#define AppSwcBcm_IN_CrashOn           ((uint8)2U)

/* Named constants for Chart: '<S328>/HazardLightLogic' */
#define AppSwcBcm_IN_EmerON            ((uint8)1U)
#define AppSwcBcm_IN_OFF               ((uint8)2U)
#define AppSwcBcm_IN_ON                ((uint8)3U)

/* Named constants for Chart: '<S430>/Chart' */
#define AppSwcBcm_IN_Delay_j           ((uint8)1U)
#define AppSwcBcm_IN_SetOff_a          ((uint8)2U)
#define AppSwcBcm_IN_SetOn_o           ((uint8)3U)

/* Named constants for Chart: '<S328>/TurnIndcrArb2' */
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
#define AppSwcBcm_IN_Trans_a           ((uint8)7U)
#define AppSwcBcm_IN_TrunkWarn         ((uint8)8U)
#define AppSwcBcm_IN_VehMode           ((uint8)9U)

/* Named constants for Chart: '<S328>/TurnIndcrLogic' */
#define AppSwcBcm_IN_LongFlash         ((uint8)1U)
#define AppSwcBcm_IN_OFF_l             ((uint8)1U)
#define AppSwcBcm_IN_ShortFlash        ((uint8)2U)
#define AppSwcBcm_IN_TurnL             ((uint8)2U)
#define AppSwcBcm_IN_TurnR             ((uint8)3U)

/* Named constants for Chart: '<S328>/TurnIndcrSelect' */
#define AppSwcBcm_IN_TurnLOn           ((uint8)2U)
#define AppSwcBcm_IN_TurnLROn          ((uint8)3U)
#define AppSwcBcm_IN_TurnROn           ((uint8)4U)

/* Named constants for Chart: '<S437>/Chart' */
#define AppSwcBcm_IN_Init_o            ((uint8)1U)
#define AppSwcBcm_IN_Limit             ((uint8)2U)
#define AppSwcBcm_IN_Nrm               ((uint8)3U)
#define AppSwcBcm_IN_Show              ((uint8)4U)

/* Named constants for Chart: '<S551>/Chart' */
#define AppSwcBcm_IN_HiSpd             ((uint8)1U)
#define AppSwcBcm_IN_Inr               ((uint8)2U)
#define AppSwcBcm_IN_LowSpd            ((uint8)3U)
#define AppSwcBcm_IN_Maint             ((uint8)1U)
#define AppSwcBcm_IN_Mist              ((uint8)4U)
#define AppSwcBcm_IN_NO_ACTIVE_CHILD_m ((uint8)0U)
#define AppSwcBcm_IN_Nrm_n             ((uint8)2U)
#define AppSwcBcm_IN_Off_d             ((uint8)5U)
#define AppSwcBcm_IN_Wash              ((uint8)3U)

/* Named constants for Chart: '<S598>/AlmSysLogic' */
#define AppSwcBcm_IN_Alarm             ((uint8)1U)
#define AppSwcBcm_IN_Armed_c           ((uint8)2U)
#define AppSwcBcm_IN_Disarmed_o        ((uint8)3U)
#define AppSwcBcm_IN_Init_a            ((uint8)4U)
#define AppSwcBcm_IN_PartArmed_g       ((uint8)5U)

/* Named constants for Chart: '<S601>/DoorDrv' */
#define AppSwcBcm_IN_DrvIdle           ((uint8)1U)
#define AppSwcBcm_IN_InsDrvLck         ((uint8)2U)
#define AppSwcBcm_IN_InsDrvUnlck       ((uint8)3U)
#define AppSwcBcm_IN_OsDrvLck          ((uint8)4U)
#define AppSwcBcm_IN_OsDrvUnlck        ((uint8)5U)
#define AppSwcBcm_IN_TrunkUnlck        ((uint8)6U)

/* Named constants for Chart: '<S604>/Chart' */
#define AppSwcBcm_IN_LocalOn           ((uint8)1U)
#define AppSwcBcm_IN_OTA1On            ((uint8)2U)
#define AppSwcBcm_IN_OTAOn             ((uint8)3U)
#define AppSwcBcm_IN_PSOff             ((uint8)4U)

/* Named constants for Chart: '<S127>/Chart' */
#define AppSwcBcm_IN_Off_dh            ((uint8)1U)
#define AppSwcBcm_IN_On_b              ((uint8)2U)

/* Invariant block signals (default storage) */
const ConstB_AppSwcBcm_T AppSwcBcm_ConstB = {
  1.33399987F,                         /* '<S366>/Product' */
  -1.33399987F,                        /* '<S366>/Product1' */
  0U,                                  /* '<S217>/Data Type Conversion39' */
  1,                                   /* '<S660>/Relational Operator1' */
  1,                                   /* '<S690>/Relational Operator6' */
  0,                                   /* '<S424>/Relational Operator1' */
  1,                                   /* '<S350>/Relational Operator' */
  1                                    /* '<S351>/Relational Operator1' */
};

/* PublicStructure Variables for Internal Data */
ARID_DEF_AppSwcBcm_T AppSwcBcm_ARID_DEF;
static float32 look1_iflf_binlx(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex);
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
static uint16 AppSwcBcm_BitShift1_j(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u);
static void AppSwcBcm_Lib_RiseEdgeDet_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_l_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDet_m(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_j_T
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
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_l_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_l_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_k(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDet_c(boolean rtu_Lib_blIn, boolean
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
static uint16 AppSwcBcm_BitShift10_k(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift11_f(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u);
static uint16 AppSwcBcm_BitShift3_b(uint16 rtu_u);
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
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y);
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_l_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_a_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_RiseEdgeDetInit_h(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_a_T *AppSwcBcm__ARID_DEF_arg);
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
static void AppSwcBcm_Lib_FailEdgeDet_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_l_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_b_T
  *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg);
static boolean AppSwcBcm_Lib_FailEdgeDet_ja(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_k_T *AppSwcBcm__ARID_DEF_arg);
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
static void AppSwcBcm_EEWriteCtl(void);
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
static void AppSwcBcm_KnobBeamDig(void);
static void AppSwcBcm_LampDelayCtl_Init(void);
static void AppSwcBcm_LampDelayCtl_Update(void);
static void AppSwcBcm_LampDelayCtl(void);
static void AppSwcBcm_LightIntstDet(void);
static void AppSwcBcm_LowBeamCtl_Init(void);
static void AppSwcBcm_LowBeamCtl(void);
static void AppSwcBcm_BrakeLampCtl(void);
static void AppSwcBcm_ReverseLampCtl(void);
static void AppSwcBcm_HiBeamCtl(void);
static void AppSwcBcm_PassLampFunc(void);
static void AppSwcBcm_PosLampCtl_Init(void);
static void AppSwcBcm_PosLampCtl(void);
static void AppSwcBcm_SignalProcess_Init(void);
static void AppSwcBcm_SignalProcess(void);
static void AppSwcBcm_TurnIndcrCtl_Init(void);
static void AppSwcBcm_TurnIndcrCtl(void);
static void AppSwcBcm_Lib_RiseEdgeDet_b(void);
static void AppSwcBcm_Lib_ChangeEdge_Update(void);
static void AppSwcBcm_Lib_ChangeEdge(void);
static void AppSwcBcm_WelcomeLampCtl_Init(void);
static void AppSwcBcm_WelcomeLampCtl_Update(void);
static void AppSwcBcm_WelcomeLampCtl(void);
static void AppSwcBcm_LampCtl_Init(void);
static void AppSwcBcm_LampCtl_Update(void);
static void AppSwcBcm_LampCtl(void);
static void AppSwcBcm_LockedRotorProt_Init(void);
static void AppSwcBcm_LockedRotorProt(void);
static void AppSwcBcm_SignalProcess_d(void);
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
static void AppSwcBcm_SignalProcess_m_Init(void);
static void AppSwcBcm_SignalProcess_g_Const(void);
static void AppSwcBcm_SignalProcess_a(void);
static void AppSwcBcm_DoorLckCtl_Init(void);
static void AppSwcBcm_DoorLckCtl_Const(void);
static void AppSwcBcm_DoorLckCtl(void);
static void AppSwcBcm_ESCLCtl_Init(void);
static void AppSwcBcm_ESCLCtl(void);
static void AppSwcBcm_IMMOCtl_Init(void);
static void AppSwcBcm_IMMOCtl(void);
static void AppSwcBcm_Chart(void);
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
static void AppSwcBcm_NMCtl_Update(void);
static void AppSwcBcm_NMCtl(void);
static void AppSwcBcm_SleepCtl_Init(void);
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
static float32 look1_iflf_binlx(float32 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
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
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
}

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

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift'
 *    '<S5>/Bit Shift22'
 *    '<S5>/Bit Shift30'
 *    '<S5>/Bit Shift38'
 *    '<S5>/Bit Shift46'
 *    '<S5>/Bit Shift54'
 *    '<S5>/Bit Shift8'
 */
static uint8 AppSwcBcm_BitShift(uint8 rtu_u)
{
  /* MATLAB Function: '<S10>/bit_shift' */
  return rtu_u;
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift1'
 *    '<S5>/Bit Shift23'
 *    '<S5>/Bit Shift31'
 *    '<S5>/Bit Shift39'
 *    '<S5>/Bit Shift47'
 *    '<S5>/Bit Shift55'
 *    '<S5>/Bit Shift9'
 */
static uint8 AppSwcBcm_BitShift1(uint8 rtu_u)
{
  /* MATLAB Function: '<S11>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift10'
 *    '<S5>/Bit Shift16'
 *    '<S5>/Bit Shift2'
 *    '<S5>/Bit Shift24'
 *    '<S5>/Bit Shift32'
 *    '<S5>/Bit Shift40'
 *    '<S5>/Bit Shift48'
 */
static uint8 AppSwcBcm_BitShift10(uint8 rtu_u)
{
  /* MATLAB Function: '<S12>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 2);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift11'
 *    '<S5>/Bit Shift17'
 *    '<S5>/Bit Shift25'
 *    '<S5>/Bit Shift3'
 *    '<S5>/Bit Shift33'
 *    '<S5>/Bit Shift41'
 *    '<S5>/Bit Shift49'
 */
static uint8 AppSwcBcm_BitShift11(uint8 rtu_u)
{
  /* MATLAB Function: '<S13>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift12'
 *    '<S5>/Bit Shift18'
 *    '<S5>/Bit Shift26'
 *    '<S5>/Bit Shift34'
 *    '<S5>/Bit Shift4'
 *    '<S5>/Bit Shift42'
 *    '<S5>/Bit Shift50'
 */
static uint8 AppSwcBcm_BitShift12(uint8 rtu_u)
{
  /* MATLAB Function: '<S14>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift13'
 *    '<S5>/Bit Shift19'
 *    '<S5>/Bit Shift27'
 *    '<S5>/Bit Shift35'
 *    '<S5>/Bit Shift43'
 *    '<S5>/Bit Shift5'
 *    '<S5>/Bit Shift51'
 */
static uint8 AppSwcBcm_BitShift13(uint8 rtu_u)
{
  /* MATLAB Function: '<S15>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift14'
 *    '<S5>/Bit Shift20'
 *    '<S5>/Bit Shift28'
 *    '<S5>/Bit Shift36'
 *    '<S5>/Bit Shift44'
 *    '<S5>/Bit Shift52'
 *    '<S5>/Bit Shift6'
 */
static uint8 AppSwcBcm_BitShift14(uint8 rtu_u)
{
  /* MATLAB Function: '<S16>/bit_shift' */
  return (uint8)((uint32)rtu_u >> 6);
}

/*
 * Output and update for atomic system:
 *    '<S5>/Bit Shift15'
 *    '<S5>/Bit Shift21'
 *    '<S5>/Bit Shift29'
 *    '<S5>/Bit Shift37'
 *    '<S5>/Bit Shift45'
 *    '<S5>/Bit Shift53'
 *    '<S5>/Bit Shift7'
 */
static uint8 AppSwcBcm_BitShift15(uint8 rtu_u)
{
  /* MATLAB Function: '<S17>/bit_shift' */
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

  /* CCaller: '<S5>/C Caller' */
  App_Call_Event_IODID_0x3231_GetEventStatus(&rtb_CCaller[0]);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift' */
  rtb_y_aq = AppSwcBcm_BitShift(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND' */
  IODID_TurnIndcrLCtlFlg = (uint8)(rtb_y_aq & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift1' */
  rtb_y_aj = AppSwcBcm_BitShift1(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift1' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND1' */
  IODID_TurnIndcrRCtlFlg = (uint8)(rtb_y_aj & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift12' */
  rtb_y_ed = AppSwcBcm_BitShift12(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift12' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND12' */
  IODID_LowBeamCtlFlg = (uint8)(rtb_y_ed & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift13' */
  rtb_y_ld = AppSwcBcm_BitShift13(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift13' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND13' */
  IODID_HiBeamCtlFlg = (uint8)(rtb_y_ld & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift14' */
  rtb_y_ft = AppSwcBcm_BitShift14(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift14' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND14' */
  IODID_FogLampFCtlFlg = (uint8)(rtb_y_ft & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift15' */
  rtb_y_a2 = AppSwcBcm_BitShift15(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift15' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND15' */
  IODID_FogLampRCtlFlg = (uint8)(rtb_y_a2 & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift2' */
  rtb_y_l2 = AppSwcBcm_BitShift10(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift2' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND2' */
  IODID_BackLampCtlFlg = (uint8)(rtb_y_l2 & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift3' */
  rtb_y_lq = AppSwcBcm_BitShift11(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift3' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND3' */
  IODID_BrakeLightCtlFlg = (uint8)(rtb_y_lq & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift5' */
  rtb_y_m3 = AppSwcBcm_BitShift13(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift5' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND5' */
  IODID_ReverseLampCtlFlg = (uint8)(rtb_y_m3 & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift6' */
  rtb_y_fco = AppSwcBcm_BitShift14(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift6' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND6' */
  IODID_DayRunLightCtlFlg = (uint8)(rtb_y_fco & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift7' */
  rtb_y_i = AppSwcBcm_BitShift15(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift7' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND7' */
  IODID_PosLampCtlFlg = (uint8)(rtb_y_i & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift9' */
  rtb_y = AppSwcBcm_BitShift1(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift9' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND9' */
  IODID_DomeLampCtlFlg = (uint8)(rtb_y & 1);

  /* CCaller: '<S5>/C Caller1' */
  App_Call_Event_IODID_0x3232_GetEventStatus(&rtb_CCaller1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift16' */
  rtb_y_bf = AppSwcBcm_BitShift10(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift16' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND16' */
  IODID_DoorUnlckCtlFlg = (uint8)(rtb_y_bf & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift17' */
  rtb_y_p5 = AppSwcBcm_BitShift11(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift17' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND17' */
  IODID_DoorLckCtlFlg = (uint8)(rtb_y_p5 & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift22' */
  rtb_y_b = AppSwcBcm_BitShift(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift22' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND22' */
  IODID_TrunkUnlckCtlFlg = (uint8)(rtb_y_b & 1);

  /* CCaller: '<S5>/C Caller2' */
  App_Call_Event_IODID_0x3233_GetEventStatus(&rtb_CCaller2);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift30' */
  rtb_y_ms = AppSwcBcm_BitShift(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift30' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND30' */
  IODID_WiperHiSpdCtlFlg = (uint8)(rtb_y_ms & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift31' */
  rtb_y_b5 = AppSwcBcm_BitShift1(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift31' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND31' */
  IODID_WiperLowSpdCtlFlg = (uint8)(rtb_y_b5 & 1);

  /* CCaller: '<S5>/C Caller3' */
  App_Call_Event_IODID_0x3234_GetEventStatus(&rtb_CCaller3);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift32' */
  rtb_y_hl = AppSwcBcm_BitShift10(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift32' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND32' */
  IODID_WinFLCtlFlg = (uint8)(rtb_y_hl & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift33' */
  rtb_y_f5 = AppSwcBcm_BitShift11(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift33' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND33' */
  IODID_WinFRCtlFlg = (uint8)(rtb_y_f5 & 1);

  /* CCaller: '<S5>/C Caller4' */
  App_Call_Event_IODID_0x3235_GetEventStatus(&rtb_CCaller4);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift40' */
  rtb_y_h5 = AppSwcBcm_BitShift10(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift40' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND40' */
  IODID_HornCtlFlg = (uint8)(rtb_y_h5 & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift42' */
  rtb_y_ci = AppSwcBcm_BitShift12(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift42' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND42' */
  IODID_BatSaveCtlFlg = (uint8)(rtb_y_ci & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift43' */
  rtb_y_l = AppSwcBcm_BitShift13(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift43' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND43' */
  IODID_BSDRightCtlFlg = (uint8)(rtb_y_l & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift44' */
  rtb_y_dp = AppSwcBcm_BitShift14(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift44' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND44' */
  IODID_BSDLeftCtlFlg = (uint8)(rtb_y_dp & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift46' */
  rtb_y_cur = AppSwcBcm_BitShift(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift46' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND46' */
  IODID_IG1RlyCtlFlg = (uint8)(rtb_y_cur & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift47' */
  rtb_y_iq = AppSwcBcm_BitShift1(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift47' */

  /* S-Function (sfix_bitop): '<S5>/Bitwise AND47' */
  IODID_IG2RlyCtlFlg = (uint8)(rtb_y_iq & 1);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift41' */
  rtb_y_k = AppSwcBcm_BitShift11(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift41' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift45' */
  rtb_y_kl = AppSwcBcm_BitShift15(rtb_CCaller4);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift45' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift34' */
  rtb_y_nn = AppSwcBcm_BitShift12(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift34' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift35' */
  rtb_y_kyn = AppSwcBcm_BitShift13(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift35' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift36' */
  rtb_y_es = AppSwcBcm_BitShift14(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift36' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift37' */
  rtb_y_ab = AppSwcBcm_BitShift15(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift37' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift38' */
  rtb_y_me = AppSwcBcm_BitShift(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift38' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift39' */
  rtb_y_e = AppSwcBcm_BitShift1(rtb_CCaller3);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift39' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift24' */
  rtb_y_ei = AppSwcBcm_BitShift10(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift24' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift25' */
  rtb_y_c = AppSwcBcm_BitShift11(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift25' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift26' */
  rtb_y_no = AppSwcBcm_BitShift12(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift26' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift27' */
  rtb_y_iv1 = AppSwcBcm_BitShift13(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift27' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift28' */
  rtb_y_o = AppSwcBcm_BitShift14(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift28' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift29' */
  rtb_y_lr = AppSwcBcm_BitShift15(rtb_CCaller2);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift29' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift18' */
  rtb_y_ff = AppSwcBcm_BitShift12(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift18' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift19' */
  rtb_y_cv = AppSwcBcm_BitShift13(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift19' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift20' */
  rtb_y_cn = AppSwcBcm_BitShift14(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift20' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift21' */
  rtb_y_ead = AppSwcBcm_BitShift15(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift21' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift23' */
  rtb_y_ik = AppSwcBcm_BitShift1(rtb_CCaller1);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift23' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift10' */
  rtb_y_o2 = AppSwcBcm_BitShift10(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift10' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift11' */
  rtb_y_kt = AppSwcBcm_BitShift11(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift4' */
  rtb_y_ka = AppSwcBcm_BitShift12(rtb_CCaller[0]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift4' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift8' */
  rtb_y_f = AppSwcBcm_BitShift(rtb_CCaller[1]);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift8' */

  /* CCaller: '<S5>/C Caller5' */
  App_Call_Event_IODID_0x3236_GetEventStatus(&rtb_CCaller5);

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift48' */
  rtb_y_a = AppSwcBcm_BitShift10(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift48' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift49' */
  rtb_y_px4 = AppSwcBcm_BitShift11(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift49' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift50' */
  rtb_y_la = AppSwcBcm_BitShift12(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift50' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift51' */
  rtb_y_n2 = AppSwcBcm_BitShift13(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift51' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift52' */
  rtb_y_mv = AppSwcBcm_BitShift14(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift52' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift53' */
  rtb_y_g = AppSwcBcm_BitShift15(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift53' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift54' */
  rtb_y_hau = AppSwcBcm_BitShift(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift54' */

  /* Outputs for Atomic SubSystem: '<S5>/Bit Shift55' */
  rtb_y_kz = AppSwcBcm_BitShift1(rtb_CCaller5);

  /* End of Outputs for SubSystem: '<S5>/Bit Shift55' */
}

/*
 * System reset for atomic system:
 *    '<S123>/Lib_RiseEdgeDet'
 *    '<S161>/Lib_RiseEdgeDet'
 *    '<S163>/Lib_RiseEdgeDet'
 *    '<S165>/Lib_RiseEdgeDet'
 *    '<S167>/Lib_RiseEdgeDet'
 *    '<S180>/Lib_RiseEdgeDet'
 *    '<S182>/Lib_RiseEdgeDet'
 *    '<S184>/Lib_RiseEdgeDet'
 *    '<S186>/Lib_RiseEdgeDet'
 *    '<S188>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_Reset(ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S125>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S123>/Lib_RiseEdgeDet'
 *    '<S161>/Lib_RiseEdgeDet'
 *    '<S163>/Lib_RiseEdgeDet'
 *    '<S165>/Lib_RiseEdgeDet'
 *    '<S167>/Lib_RiseEdgeDet'
 *    '<S180>/Lib_RiseEdgeDet'
 *    '<S182>/Lib_RiseEdgeDet'
 *    '<S184>/Lib_RiseEdgeDet'
 *    '<S186>/Lib_RiseEdgeDet'
 *    '<S188>/Lib_RiseEdgeDet'
 *    ...
 */
static boolean AppSwcBcm_Lib_RiseEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S125>/Logical Operator' incorporates:
   *  Logic: '<S125>/Logical Operator1'
   *  UnitDelay: '<S125>/Unit Delay'
   */
  rty_Lib_blOut_0 = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S125>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/*
 * System reset for atomic system:
 *    '<S123>/Lib_SR'
 *    '<S299>/Lib_SR'
 *    '<S599>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR_Reset(ARID_DEF_Lib_SR_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for UnitDelay: '<S126>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = false;
}

/*
 * Output and update for atomic system:
 *    '<S123>/Lib_SR'
 *    '<S299>/Lib_SR'
 *    '<S599>/Lib_SR'
 */
static void AppSwcBcm_Lib_SR(boolean rtu_S, boolean rtu_R, boolean *rty_Q,
  ARID_DEF_Lib_SR_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Switch: '<S126>/Switch' incorporates:
   *  Constant: '<S126>/Constant'
   *  Logic: '<S126>/Logical Operator'
   *  UnitDelay: '<S126>/Unit Delay'
   */
  if (rtu_R) {
    *rty_Q = false;
  } else {
    *rty_Q = (rtu_S || AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);
  }

  /* End of Switch: '<S126>/Switch' */

  /* Update for UnitDelay: '<S126>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = *rty_Q;
}

/* Output and update for atomic system: '<S1>/RVMCtl' */
static void AppSwcBcm_RVMCtl(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S6>/Relational Operator' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S6>/RVMCtl' incorporates:
   *  EnablePort: '<S123>/Enable'
   */
  if (rtb_RelationalOperator) {
    if (!AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
      /* InitializeConditions for UnitDelay: '<S123>/Unit Delay' */
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = false;

      /* SystemReset for Atomic SubSystem: '<S123>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_Reset
        (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

      /* End of SystemReset for SubSystem: '<S123>/Lib_RiseEdgeDet' */

      /* SystemReset for Chart: '<S123>/LIB_Tim' */
      AppSwcBcm_ARID_DEF.Cnt_Tick_a = 0U;
      AppSwcBcm_ARID_DEF.Cnt_H_p = 0U;
      AppSwcBcm_ARID_DEF.Cnt_M_h = 0U;
      AppSwcBcm_ARID_DEF.Cnt_S_b = 0U;

      /* SystemReset for Atomic SubSystem: '<S123>/Lib_SR' */
      AppSwcBcm_Lib_SR_Reset(&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_o);

      /* End of SystemReset for SubSystem: '<S123>/Lib_SR' */
      AppSwcBcm_ARID_DEF.RVMCtl_MODE = true;
    }

    /* RelationalOperator: '<S123>/Relational Operator1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_RelationalOperator =
      (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPRrViewMirrHeatgKey_flg;

    /* Outputs for Atomic SubSystem: '<S123>/Lib_RiseEdgeDet' */
    rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nh);

    /* End of Outputs for SubSystem: '<S123>/Lib_RiseEdgeDet' */

    /* Chart: '<S123>/LIB_Tim' incorporates:
     *  Constant: '<S123>/Constant2'
     *  Constant: '<S123>/Constant7'
     *  UnitDelay: '<S123>/Unit Delay'
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

    /* End of Chart: '<S123>/LIB_Tim' */

    /* Outputs for Atomic SubSystem: '<S123>/Lib_SR' */
    /* Logic: '<S123>/Logical Operator2' incorporates:
     *  Logic: '<S123>/Logical Operator1'
     *  UnitDelay: '<S123>/Unit Delay'
     */
    AppSwcBcm_Lib_SR(rtb_LogicalOperator, (rtb_LogicalOperator &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc) || rtb_RelationalOperator,
                     &AppSwcBcm_ARID_DEF.Switch_i5,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_o);

    /* End of Outputs for SubSystem: '<S123>/Lib_SR' */

    /* Update for UnitDelay: '<S123>/Unit Delay' */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bc = AppSwcBcm_ARID_DEF.Switch_i5;
  } else if (AppSwcBcm_ARID_DEF.RVMCtl_MODE) {
    /* Disable for Switch: '<S126>/Switch' incorporates:
     *  Outport: '<S123>/RVMCtl_J42Heat'
     */
    AppSwcBcm_ARID_DEF.Switch_i5 = false;
    AppSwcBcm_ARID_DEF.RVMCtl_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S6>/RVMCtl' */

  /* Outputs for Atomic SubSystem: '<S6>/Ovrd' */
  /* Switch: '<S122>/Switch' incorporates:
   *  Constant: '<S6>/Constant18'
   */
  if (RVMCtl_J42HeatOvrdFlg_C) {
    /* Switch: '<S122>/Switch' incorporates:
     *  Constant: '<S6>/Constant19'
     */
    RVMCtl_J42Heat = RVMCtl_J42HeatOvrdVal_C;
  } else {
    /* Switch: '<S122>/Switch' */
    RVMCtl_J42Heat = AppSwcBcm_ARID_DEF.Switch_i5;
  }

  /* End of Switch: '<S122>/Switch' */
  /* End of Outputs for SubSystem: '<S6>/Ovrd' */
}

/* Output and update for atomic system: '<S9>/DrvWinCtl' */
static void AppSwcBcm_DrvWinCtl(void)
{
  /* Chart: '<S9>/DrvWinCtl' */
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

  /* End of Chart: '<S9>/DrvWinCtl' */
}

/* Output and update for atomic system: '<S9>/PsgWinCtl' */
static void AppSwcBcm_PsgWinCtl(void)
{
  /* Chart: '<S9>/PsgWinCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c112_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c112_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
    WinCtl_PsgWinSta = 0U;
    AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
    AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib) {
     case AppSwcBcm_IN_AutoDown_g:
      WinCtl_PsgWinSta = 3U;
      if (WinCtl_PsgWinReq != 3) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManDown_a:
      WinCtl_PsgWinSta = 4U;
      if (WinCtl_PsgWinReq != 2) {
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_Standby_b;
        WinCtl_PsgWinSta = 0U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
      }
      break;

     case AppSwcBcm_IN_ManUp_m:
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
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManDown_a;
        WinCtl_PsgWinSta = 4U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = true;
        break;

       case 1:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_ManUp_m;
        WinCtl_PsgWinSta = 2U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = true;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c112_WinCtl_Lib = AppSwcBcm_IN_AutoDown_g;
        WinCtl_PsgWinSta = 3U;
        AppSwcBcm_ARID_DEF.WinCtl_J55 = false;
        AppSwcBcm_ARID_DEF.WinCtl_J57 = true;
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S9>/PsgWinCtl' */
}

/*
 * Output and update for atomic system:
 *    '<S139>/Bit Shift1'
 *    '<S139>/Bit Shift7'
 *    '<S327>/Bit Shift1'
 *    '<S641>/Bit Shift3'
 */
static uint16 AppSwcBcm_BitShift1_j(uint16 rtu_u)
{
  /* MATLAB Function: '<S142>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 3);
}

/*
 * Output and update for atomic system:
 *    '<S139>/Bit Shift3'
 *    '<S327>/Bit Shift'
 *    '<S549>/Bit Shift5'
 *    '<S641>/Bit Shift5'
 */
static uint16 AppSwcBcm_BitShift3(uint16 rtu_u)
{
  /* MATLAB Function: '<S143>/bit_shift' */
  return rtu_u;
}

/* Output and update for atomic system: '<S9>/SigProc' */
static void AppSwcBcm_SigProc(void)
{
  uint16 rtb_Switch1;
  boolean rtb_LogicalOperator1_bj;

  /* Outputs for Atomic SubSystem: '<S139>/Bit Shift3' */
  /* Constant: '<S139>/Constant11' */
  rtb_Switch1 = AppSwcBcm_BitShift3(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S139>/Bit Shift3' */

  /* Switch: '<S139>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S139>/Bitwise AND3'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S139>/Switch1' incorporates:
     *  Constant: '<S139>/Constant15'
     */
    rtb_Switch1 = WinCtl_DrvWinSwResis_C;
  } else {
    /* Switch: '<S139>/Switch1' */
    rtb_Switch1 = BSW_J113DrvWinSwResis;
  }

  /* End of Switch: '<S139>/Switch3' */

  /* Logic: '<S139>/Logical Operator1' incorporates:
   *  Constant: '<S139>/Constant26'
   *  Constant: '<S139>/Constant31'
   *  RelationalOperator: '<S139>/Relational Operator2'
   *  RelationalOperator: '<S139>/Relational Operator3'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_DrvWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinDnMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S139>/Constant17'
   *  Constant: '<S139>/Constant18'
   *  Constant: '<S139>/Constant19'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_cc >= (float32)WinCtl_DrvWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_cc++;
      AppSwcBcm_ARID_DEF.cnt_heal_kb = (uint16)((float32)
        WinCtl_DrvWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_cc = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_kb == 0) {
      WinCtl_DrvWinDnSw = false;
    } else if (WinCtl_DrvWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_kb--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms1' */

  /* Logic: '<S139>/Logical Operator2' incorporates:
   *  Constant: '<S139>/Constant35'
   *  Constant: '<S139>/Constant36'
   *  RelationalOperator: '<S139>/Relational Operator4'
   *  RelationalOperator: '<S139>/Relational Operator5'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_DrvWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinAutoDnMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S139>/Constant23'
   *  Constant: '<S139>/Constant24'
   *  Constant: '<S139>/Constant25'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_kx >= (float32)
         WinCtl_DrvWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_kx++;
      AppSwcBcm_ARID_DEF.cnt_heal_dc = (uint16)((float32)
        WinCtl_DrvWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_kx = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_dc == 0) {
      WinCtl_DrvWinAutoDnSw = false;
    } else if (WinCtl_DrvWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_dc--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms2' */

  /* Logic: '<S139>/Logical Operator' incorporates:
   *  Constant: '<S139>/Constant20'
   *  Constant: '<S139>/Constant22'
   *  RelationalOperator: '<S139>/Relational Operator'
   *  RelationalOperator: '<S139>/Relational Operator1'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_DrvWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvWinUpMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S139>/Constant12'
   *  Constant: '<S139>/Constant13'
   *  Constant: '<S139>/Constant14'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_mg >= (float32)WinCtl_DrvWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_DrvWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_mg++;
      AppSwcBcm_ARID_DEF.cnt_heal_dm = (uint16)((float32)
        WinCtl_DrvWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_mg = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_dm == 0) {
      WinCtl_DrvWinUpSw = false;
    } else if (WinCtl_DrvWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_dm--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S139>/Bit Shift7' */
  /* Constant: '<S139>/Constant21' */
  rtb_Switch1 = AppSwcBcm_BitShift1_j(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S139>/Bit Shift7' */

  /* Switch: '<S139>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S139>/Bitwise AND7'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S139>/Switch1' incorporates:
     *  Constant: '<S139>/Constant30'
     */
    rtb_Switch1 = WinCtl_PsgWinSwResis_C;
  } else {
    /* Switch: '<S139>/Switch1' */
    rtb_Switch1 = BSW_J26PsgWinSwResis;
  }

  /* End of Switch: '<S139>/Switch6' */

  /* Logic: '<S139>/Logical Operator3' incorporates:
   *  Constant: '<S139>/Constant40'
   *  Constant: '<S139>/Constant41'
   *  RelationalOperator: '<S139>/Relational Operator6'
   *  RelationalOperator: '<S139>/Relational Operator7'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_PsgWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinUpMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S139>/Constant27'
   *  Constant: '<S139>/Constant28'
   *  Constant: '<S139>/Constant29'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hb >= (float32)WinCtl_PsgWinUpTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hb++;
      AppSwcBcm_ARID_DEF.cnt_heal_do = (uint16)((float32)
        WinCtl_PsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hb = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_do == 0) {
      WinCtl_PsgWinUpSw = false;
    } else if (WinCtl_PsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_do--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms4' */

  /* Logic: '<S139>/Logical Operator4' incorporates:
   *  Constant: '<S139>/Constant42'
   *  Constant: '<S139>/Constant43'
   *  RelationalOperator: '<S139>/Relational Operator8'
   *  RelationalOperator: '<S139>/Relational Operator9'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_PsgWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinDnMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S139>/Constant32'
   *  Constant: '<S139>/Constant33'
   *  Constant: '<S139>/Constant34'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_eu >= (float32)WinCtl_PsgWinDnTimValid_C /
         (WinCtl_Ts_C * 100.0F)) && (WinCtl_PsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_eu++;
      AppSwcBcm_ARID_DEF.cnt_heal_gg = (uint16)((float32)
        WinCtl_PsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_eu = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gg == 0) {
      WinCtl_PsgWinDnSw = false;
    } else if (WinCtl_PsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_gg--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms5' */

  /* Logic: '<S139>/Logical Operator5' incorporates:
   *  Constant: '<S139>/Constant44'
   *  Constant: '<S139>/Constant45'
   *  RelationalOperator: '<S139>/Relational Operator10'
   *  RelationalOperator: '<S139>/Relational Operator11'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_PsgWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_PsgWinAutoDnMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S139>/Constant37'
   *  Constant: '<S139>/Constant38'
   *  Constant: '<S139>/Constant39'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l2 >= (float32)
         WinCtl_PsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_PsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_PsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l2++;
      AppSwcBcm_ARID_DEF.cnt_heal_mn = (uint16)((float32)
        WinCtl_PsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l2 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mn == 0) {
      WinCtl_PsgWinAutoDnSw = false;
    } else if (WinCtl_PsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mn--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S139>/Bit Shift1' */
  /* Constant: '<S139>/Constant1' */
  rtb_Switch1 = AppSwcBcm_BitShift1_j(WinCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S139>/Bit Shift1' */

  /* Switch: '<S139>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S139>/Bitwise AND1'
   */
  if ((rtb_Switch1 & 1U) != 0U) {
    /* Switch: '<S139>/Switch1' incorporates:
     *  Constant: '<S139>/Constant5'
     */
    rtb_Switch1 = WinCtl_DrvPsgWinSwResis_C;
  } else {
    /* Switch: '<S139>/Switch1' */
    rtb_Switch1 = BSW_J126DrvPsgWinSwResis;
  }

  /* End of Switch: '<S139>/Switch1' */

  /* Logic: '<S139>/Logical Operator6' incorporates:
   *  Constant: '<S139>/Constant46'
   *  Constant: '<S139>/Constant47'
   *  RelationalOperator: '<S139>/Relational Operator14'
   *  RelationalOperator: '<S139>/Relational Operator15'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_DrvPsgWinUpMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinUpMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S139>/Constant2'
   *  Constant: '<S139>/Constant3'
   *  Constant: '<S139>/Constant4'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_nj >= (float32)
         WinCtl_DrvPsgWinUpTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinUpTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinUpSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_nj++;
      AppSwcBcm_ARID_DEF.cnt_heal_f5 = (uint16)((float32)
        WinCtl_DrvPsgWinUpTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_nj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_f5 == 0) {
      WinCtl_DrvPsgWinUpSw = false;
    } else if (WinCtl_DrvPsgWinUpTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_f5--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms7' */

  /* Logic: '<S139>/Logical Operator7' incorporates:
   *  Constant: '<S139>/Constant48'
   *  Constant: '<S139>/Constant49'
   *  RelationalOperator: '<S139>/Relational Operator16'
   *  RelationalOperator: '<S139>/Relational Operator17'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_DrvPsgWinDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinDnMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S139>/Constant6'
   *  Constant: '<S139>/Constant7'
   *  Constant: '<S139>/Constant8'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_kg >= (float32)
         WinCtl_DrvPsgWinDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_kg++;
      AppSwcBcm_ARID_DEF.cnt_heal_lg = (uint16)((float32)
        WinCtl_DrvPsgWinDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_kg = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lg == 0) {
      WinCtl_DrvPsgWinDnSw = false;
    } else if (WinCtl_DrvPsgWinDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_lg--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms8' */

  /* Logic: '<S139>/Logical Operator8' incorporates:
   *  Constant: '<S139>/Constant50'
   *  Constant: '<S139>/Constant51'
   *  RelationalOperator: '<S139>/Relational Operator12'
   *  RelationalOperator: '<S139>/Relational Operator13'
   */
  rtb_LogicalOperator1_bj = ((rtb_Switch1 >= WinCtl_DrvPsgWinAutoDnMinResis_C) &&
    (rtb_Switch1 <= WinCtl_DrvPsgWinAutoDnMaxResis_C));

  /* Chart: '<S139>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S139>/Constant10'
   *  Constant: '<S139>/Constant16'
   *  Constant: '<S139>/Constant9'
   */
  if (rtb_LogicalOperator1_bj) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gn >= (float32)
         WinCtl_DrvPsgWinAutoDnTimValid_C / (WinCtl_Ts_C * 100.0F)) &&
        (WinCtl_DrvPsgWinAutoDnTimValid_C != 0xFFFF)) {
      WinCtl_DrvPsgWinAutoDnSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gn++;
      AppSwcBcm_ARID_DEF.cnt_heal_dg = (uint16)((float32)
        WinCtl_DrvPsgWinAutoDnTimInValid_C / (WinCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gn = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_dg == 0) {
      WinCtl_DrvPsgWinAutoDnSw = false;
    } else if (WinCtl_DrvPsgWinAutoDnTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_dg--;
    }
  }

  /* End of Chart: '<S139>/LIB_TPD_10ms9' */
}

/*
 * Output and update for function-call system:
 *    '<S157>/Lib_RiseEdgeDet'
 *    '<S158>/Lib_RiseEdgeDet'
 *    '<S159>/Lib_RiseEdgeDet'
 *    '<S160>/Lib_RiseEdgeDet'
 *    '<S171>/Lib_RiseEdgeDet'
 *    '<S172>/Lib_RiseEdgeDet'
 *    '<S173>/Lib_RiseEdgeDet'
 *    '<S174>/Lib_RiseEdgeDet'
 *    '<S273>/Lib_RiseEdgeDet'
 *    '<S276>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_o(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_l_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S161>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S161>/Lib_RiseEdgeDet' */
}

/* Output and update for atomic system: '<S9>/WinMotorProt' */
static void AppSwcBcm_WinMotorProt(void)
{
  sint32 tmp;

  /* Logic: '<S140>/Logical Operator' incorporates:
   *  Constant: '<S140>/Constant'
   *  Constant: '<S140>/Constant4'
   *  RelationalOperator: '<S140>/Relational Operator'
   *  RelationalOperator: '<S140>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_dy = ((WinCtl_DrvWinSta == 4) || (WinCtl_DrvWinSta
    == 3));

  /* Chart: '<S140>/LIB_CntLimit1' incorporates:
   *  SubSystem: '<S158>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_dy,
    &AppSwcBcm_ARID_DEF.LogicalOperator_o1,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pb);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_o1) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ch + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ch + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_ch = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_o + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_o + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_o = (uint16)tmp;
  }

  /* Constant: '<S140>/Constant1' */
  if (AppSwcBcm_ARID_DEF.Cnt2_o >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_ch - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_ch - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_ch = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_o = 0U;
  }

  /* End of Constant: '<S140>/Constant1' */

  /* Constant: '<S140>/Constant2' */
  WinCtl_DrvWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_ch > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S140>/Relational Operator1' incorporates:
   *  Constant: '<S140>/Constant3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_pp = (WinCtl_DrvWinSta == 2);

  /* Chart: '<S140>/LIB_CntLimit' incorporates:
   *  SubSystem: '<S157>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_pp,
    &AppSwcBcm_ARID_DEF.LogicalOperator_am,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ms);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_am) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_g + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_g + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_g = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_iw = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_iw + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_iw + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_iw = (uint16)tmp;
  }

  /* Constant: '<S140>/Constant14' */
  if (AppSwcBcm_ARID_DEF.Cnt2_iw >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_g - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_g - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_g = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_iw = 0U;
  }

  /* End of Constant: '<S140>/Constant14' */

  /* Constant: '<S140>/Constant15' */
  WinCtl_DrvWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_g > WinCtl_WinProtNum_C);

  /* RelationalOperator: '<S140>/Relational Operator4' incorporates:
   *  Constant: '<S140>/Constant10'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_hq = (WinCtl_PsgWinSta == 2);

  /* Chart: '<S140>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S159>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_hq,
    &AppSwcBcm_ARID_DEF.LogicalOperator_h2,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_af);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_h2) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_m + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_m + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_m = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_n = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_n + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_n + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_n = (uint16)tmp;
  }

  /* Constant: '<S140>/Constant8' */
  if (AppSwcBcm_ARID_DEF.Cnt2_n >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_m - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_m - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_m = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_n = 0U;
  }

  /* End of Constant: '<S140>/Constant8' */

  /* Constant: '<S140>/Constant9' */
  WinCtl_PsgWinUpProt = (AppSwcBcm_ARID_DEF.Cnt_m > WinCtl_WinProtNum_C);

  /* Logic: '<S140>/Logical Operator1' incorporates:
   *  Constant: '<S140>/Constant11'
   *  Constant: '<S140>/Constant7'
   *  RelationalOperator: '<S140>/Relational Operator3'
   *  RelationalOperator: '<S140>/Relational Operator5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_jd = ((WinCtl_PsgWinSta == 4) || (WinCtl_PsgWinSta
    == 3));

  /* Chart: '<S140>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S160>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jd,
    &AppSwcBcm_ARID_DEF.LogicalOperator_mnb,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_da);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_mnb) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_oe + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_oe + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_oe = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_i = (uint16)tmp;
  }

  /* Constant: '<S140>/Constant5' */
  if (AppSwcBcm_ARID_DEF.Cnt2_i >= WinCtl_WinProtTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_oe - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_oe - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_oe = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_i = 0U;
  }

  /* End of Constant: '<S140>/Constant5' */

  /* Constant: '<S140>/Constant6' */
  WinCtl_PsgWinDnProt = (AppSwcBcm_ARID_DEF.Cnt_oe > WinCtl_WinProtNum_C);
}

/*
 * Output and update for function-call system:
 *    '<S169>/Lib_RiseEdgeDet'
 *    '<S170>/Lib_RiseEdgeDet'
 *    '<S769>/Lib_RiseEdgeDet'
 *    '<S770>/Lib_RiseEdgeDet'
 */
static void AppSwcBcm_Lib_RiseEdgeDet_m(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_j_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S180>/Lib_RiseEdgeDet' */
  *rty_Lib_blOut = AppSwcBcm_Lib_RiseEdgeDet(rtu_Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S180>/Lib_RiseEdgeDet' */
}

/*
 * System initialize for atomic system:
 *    '<S141>/LIB_NegPluse'
 *    '<S550>/LIB_Tim'
 *    '<S788>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S141>/LIB_NegPluse'
 *    '<S550>/LIB_Tim'
 *    '<S788>/LIB_Tim'
 */
static void AppSwcBcm_LIB_NegPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_NegPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S141>/LIB_NegPluse' */
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

  /* End of Chart: '<S141>/LIB_NegPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S141>/LIB_PosPluse'
 *    '<S141>/LIB_PosPluse1'
 *    '<S306>/LIB_Tim'
 *    '<S529>/LIB_Tim'
 *    '<S790>/LIB_PosPluse'
 *    '<S790>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S141>/LIB_PosPluse'
 *    '<S141>/LIB_PosPluse1'
 *    '<S306>/LIB_Tim'
 *    '<S529>/LIB_Tim'
 *    '<S790>/LIB_PosPluse'
 *    '<S790>/LIB_PosPluse1'
 */
static void AppSwcBcm_LIB_PosPluse(boolean rtu_LIB_blEn, uint16 rtu_LIB_u16Limit,
  boolean *rty_LIB_blOut, ARID_DEF_LIB_PosPluse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S141>/LIB_PosPluse' */
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

  /* End of Chart: '<S141>/LIB_PosPluse' */
}

/*
 * System initialize for atomic system:
 *    '<S141>/LIB_TPD_10ms1'
 *    '<S141>/LIB_TPD_10ms3'
 *    '<S297>/LIB_TPD_10ms1'
 *    '<S308>/LIB_TPD_10ms8'
 *    '<S325>/LIB_TPD_10ms8'
 *    '<S327>/LIB_TPD_10ms11'
 *    '<S327>/LIB_TPD_10ms13'
 *    '<S660>/LIB_TPD_10ms'
 *    '<S660>/LIB_TPD_10ms1'
 *    '<S672>/LIB_TPD_10ms'
 *    ...
 */
static void AppSwcBcm_LIB_TPD_10ms1_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S141>/LIB_TPD_10ms1'
 *    '<S141>/LIB_TPD_10ms3'
 *    '<S297>/LIB_TPD_10ms1'
 *    '<S308>/LIB_TPD_10ms8'
 *    '<S325>/LIB_TPD_10ms8'
 *    '<S327>/LIB_TPD_10ms11'
 *    '<S327>/LIB_TPD_10ms13'
 *    '<S660>/LIB_TPD_10ms'
 *    '<S660>/LIB_TPD_10ms1'
 *    '<S672>/LIB_TPD_10ms'
 *    ...
 */
static void AppSwcBcm_LIB_TPD_10ms1(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, uint16 rtu_LIB_u16tiToOk, float32 rtu_LIB_s32Ts, boolean
  *rty_LIB_bErrFlg, ARID_DEF_LIB_TPD_10ms1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S141>/LIB_TPD_10ms1' */
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

  /* End of Chart: '<S141>/LIB_TPD_10ms1' */
}

/* System initialize for atomic system: '<S9>/WinSwArb' */
static void AppSwcBcm_WinSwArb_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_d;
  boolean rtb_LIB_blOut_o;
  boolean rtb_LIB_blOut_k;

  /* SystemInitialize for Chart: '<S141>/LIB_NegPluse' */
  AppSwcBcm_LIB_NegPluse_Init(&rtb_LIB_blOut_k);

  /* SystemInitialize for Chart: '<S141>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_o);

  /* SystemInitialize for Chart: '<S141>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_d);

  /* SystemInitialize for Chart: '<S141>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_k3);

  /* SystemInitialize for Chart: '<S141>/LIB_TPD_10ms3' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_l);
}

/* Output and update for atomic system: '<S9>/WinSwArb' */
static void AppSwcBcm_WinSwArb(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_d;
  boolean rtb_LIB_blOut_o;
  boolean rtb_LIB_blOut_k;
  uint8 rtb_Switch12;
  uint8 tmp;
  boolean rtb_LogicalOperator2_ad;
  boolean rtb_RelationalOperator3_pv;
  boolean rtb_RelationalOperator5_gh;

  /* Chart: '<S141>/Chart' incorporates:
   *  UnitDelay: '<S141>/Unit Delay9'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1_m < 3U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1_m++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_DrvWinAutoDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm_ARID_DEF.Lib_blIn_hf = WinCtl_DrvWinAutoDnSw;

    /* Outputs for Function Call SubSystem: '<S169>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_m(AppSwcBcm_ARID_DEF.Lib_blIn_hf,
      &AppSwcBcm_ARID_DEF.LogicalOperator_c0,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_axz);

    /* End of Outputs for SubSystem: '<S169>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_c0 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ln)) {
      AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_On;
      AppSwcBcm_ARID_DEF.temporalCounter_i1_m = 0U;
      WinCtl_DrvWinAutoDnReq = true;
    }

    /* case IN_On: */
  } else if (((WinCtl_DrvWinReq != 3) &&
              (AppSwcBcm_ARID_DEF.temporalCounter_i1_m >= 2)) ||
             AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ln) {
    AppSwcBcm_ARID_DEF.is_c1_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_DrvWinAutoDnReq = false;
  }

  /* End of Chart: '<S141>/Chart' */

  /* RelationalOperator: '<S141>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S141>/Relational Operator2'
   */
  rtb_RelationalOperator5_gh = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S141>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S141>/Relational Operator11'
   */
  rtb_RelationalOperator3_pv = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 5);

  /* Logic: '<S141>/Logical Operator9' */
  WinCtl_WinDnRKEReq = (rtb_RelationalOperator5_gh && rtb_RelationalOperator3_pv);

  /* RelationalOperator: '<S141>/Relational Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S141>/Relational Operator'
   */
  rtb_RelationalOperator3_pv = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_LampCtl_Bus())
    ->RKEReq == 6);

  /* Logic: '<S141>/Logical Operator3' */
  WinCtl_WinUpRKEReq = (rtb_RelationalOperator5_gh && rtb_RelationalOperator3_pv);

  /* Chart: '<S141>/LIB_PosPluse' incorporates:
   *  Constant: '<S141>/Constant40'
   *  Logic: '<S141>/Logical Operator10'
   */
  AppSwcBcm_LIB_PosPluse(WinCtl_DrvWinDnSw || WinCtl_DrvWinAutoDnReq ||
    WinCtl_DrvWinUpSw || WinCtl_WinDnRKEReq || WinCtl_WinUpRKEReq,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse_g);

  /* Chart: '<S141>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S141>/Constant34'
   *  Constant: '<S141>/Constant35'
   *  Constant: '<S141>/Constant36'
   *  Constant: '<S141>/Constant37'
   *  RelationalOperator: '<S141>/Relational Operator9'
   */
  AppSwcBcm_LIB_TPD_10ms1(BSW_DrvWinMotorCur >= WinCtl_WinMotorCurMax_C,
    WinCtl_WinMotorCurTimValid_C, WinCtl_WinMotorCurTimInValid_C, WinCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms3);

  /* Chart: '<S141>/Chart2' incorporates:
   *  UnitDelay: '<S141>/Unit Delay9'
   *  UnitDelay: '<S9>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_DrvWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm_ARID_DEF.Lib_blIn_iew = WinCtl_DrvWinDnSw;

    /* Outputs for Function Call SubSystem: '<S171>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_iew,
      &AppSwcBcm_ARID_DEF.LogicalOperator_p2,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ei);

    /* End of Outputs for SubSystem: '<S171>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_p2 &&
        (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ln)) {
      AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_On;
      WinCtl_DrvWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinDnSw) || AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ln ||
             (WinCtl_DrvWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c3_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_DrvWinDnReq = false;
  }

  /* End of Chart: '<S141>/Chart2' */

  /* Chart: '<S141>/Chart3' incorporates:
   *  UnitDelay: '<S141>/Unit Delay9'
   *  UnitDelay: '<S9>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c14_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_DrvWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm_ARID_DEF.Lib_blIn_ot = WinCtl_DrvWinUpSw;

    /* Outputs for Function Call SubSystem: '<S172>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ot,
      &AppSwcBcm_ARID_DEF.LogicalOperator_aj,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h2);

    /* End of Outputs for SubSystem: '<S172>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_aj &&
        (!AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_in)) {
      AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_On;
      WinCtl_DrvWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!WinCtl_DrvWinUpSw) || AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_in ||
             (WinCtl_DrvWinReq == 0)) {
    AppSwcBcm_ARID_DEF.is_c14_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_DrvWinUpReq = false;
  }

  /* End of Chart: '<S141>/Chart3' */

  /* Switch: '<S141>/Switch' incorporates:
   *  Switch: '<S141>/Switch1'
   */
  if (WinCtl_DrvWinDnReq) {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S141>/Constant'
     */
    WinCtl_DrvWinReq = 2U;
  } else if (WinCtl_DrvWinAutoDnReq) {
    /* Switch: '<S141>/Switch1' incorporates:
     *  Constant: '<S141>/Constant1'
     *  Switch: '<S141>/Switch'
     */
    WinCtl_DrvWinReq = 3U;
  } else {
    /* Switch: '<S141>/Switch' incorporates:
     *  Switch: '<S141>/Switch1'
     *  Switch: '<S141>/Switch2'
     */
    WinCtl_DrvWinReq = (uint8)WinCtl_DrvWinUpReq;
  }

  /* End of Switch: '<S141>/Switch' */

  /* Switch: '<S141>/Switch12' */
  if (WinCtl_WinDnRKEReq) {
    /* Switch: '<S141>/Switch12' incorporates:
     *  Constant: '<S141>/Constant43'
     */
    rtb_Switch12 = 2U;
  } else {
    /* Switch: '<S141>/Switch12' incorporates:
     *  Switch: '<S141>/Switch3'
     */
    rtb_Switch12 = WinCtl_WinUpRKEReq;
  }

  /* End of Switch: '<S141>/Switch12' */

  /* RelationalOperator: '<S141>/Relational Operator3' incorporates:
   *  Constant: '<S141>/Constant19'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S141>/Relational Operator4'
   */
  rtb_RelationalOperator3_pv = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* RelationalOperator: '<S141>/Relational Operator5' incorporates:
   *  Constant: '<S141>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator5_gh =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_AlmSysCtl_Bus())->BodyWarnSts == 0);

  /* Chart: '<S141>/LIB_NegPluse' incorporates:
   *  Constant: '<S141>/Constant20'
   *  Logic: '<S141>/Logical Operator12'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator3_pv &&
    rtb_RelationalOperator5_gh, WinCtl_PwrOffWinValidTimMax_C, &rtb_LIB_blOut_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse);

  /* RelationalOperator: '<S141>/Relational Operator3' incorporates:
   *  Constant: '<S141>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_pv = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S141>/Logical Operator5' */
  rtb_RelationalOperator5_gh = (rtb_RelationalOperator3_pv || rtb_LIB_blOut_k);

  /* Switch: '<S141>/Switch11' incorporates:
   *  Constant: '<S141>/Constant25'
   *  Logic: '<S141>/Logical Operator6'
   *  Logic: '<S141>/Logical Operator8'
   *  Switch: '<S141>/Switch8'
   */
  if (AppSwcBcm_ARID_DEF.LIB_bErrFlg_l || rtb_LIB_blOut_o) {
    WinCtl_DrvWinReq = 0U;
  } else {
    if (rtb_RelationalOperator5_gh) {
      /* Switch: '<S141>/Switch8' */
      tmp = WinCtl_DrvWinReq;
    } else {
      /* Switch: '<S141>/Switch8' incorporates:
       *  Constant: '<S141>/Constant32'
       */
      tmp = 0U;
    }

    /* Switch: '<S141>/Switch7' incorporates:
     *  Switch: '<S141>/Switch8'
     */
    if (tmp == 0) {
      WinCtl_DrvWinReq = rtb_Switch12;
    }

    /* End of Switch: '<S141>/Switch7' */
  }

  /* End of Switch: '<S141>/Switch11' */

  /* Logic: '<S141>/Logical Operator' */
  rtb_RelationalOperator3_pv = (WinCtl_PsgWinDnSw || WinCtl_DrvPsgWinDnSw);

  /* Chart: '<S141>/Chart4' incorporates:
   *  UnitDelay: '<S141>/Unit Delay8'
   *  UnitDelay: '<S9>/Unit Delay4'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c15_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_PsgWinDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm_ARID_DEF.Lib_blIn_kz = rtb_RelationalOperator3_pv;

    /* Outputs for Function Call SubSystem: '<S173>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_kz,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ce,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fi);

    /* End of Outputs for SubSystem: '<S173>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ce &&
        (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g)) {
      AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_On;
      WinCtl_PsgWinDnReq = true;
    }

    /* case IN_On: */
  } else if ((!rtb_RelationalOperator3_pv) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g || (WinCtl_PsgWinReq == 0))
  {
    AppSwcBcm_ARID_DEF.is_c15_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_PsgWinDnReq = false;
  }

  /* End of Chart: '<S141>/Chart4' */

  /* Chart: '<S141>/Chart1' incorporates:
   *  Logic: '<S141>/Logical Operator1'
   *  UnitDelay: '<S141>/Unit Delay8'
   *  UnitDelay: '<S9>/Unit Delay4'
   */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1_f < 3U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1_f++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c2_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_PsgWinAutoDnReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm_ARID_DEF.Lib_blIn_nj = (WinCtl_PsgWinAutoDnSw ||
      WinCtl_DrvPsgWinAutoDnSw);

    /* Outputs for Function Call SubSystem: '<S170>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_m(AppSwcBcm_ARID_DEF.Lib_blIn_nj,
      &AppSwcBcm_ARID_DEF.LogicalOperator_oy,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ch);

    /* End of Outputs for SubSystem: '<S170>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_oy &&
        (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g)) {
      AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib = AppSwcBcm_IN_On;
      AppSwcBcm_ARID_DEF.temporalCounter_i1_f = 0U;
      WinCtl_PsgWinAutoDnReq = true;
    }

    /* case IN_On: */
  } else if (((WinCtl_PsgWinReq != 3) &&
              (AppSwcBcm_ARID_DEF.temporalCounter_i1_f >= 2)) ||
             AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g) {
    AppSwcBcm_ARID_DEF.is_c2_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_PsgWinAutoDnReq = false;
  }

  /* End of Chart: '<S141>/Chart1' */

  /* Logic: '<S141>/Logical Operator2' */
  rtb_LogicalOperator2_ad = (WinCtl_DrvPsgWinUpSw || WinCtl_PsgWinUpSw);

  /* Chart: '<S141>/Chart5' incorporates:
   *  UnitDelay: '<S141>/Unit Delay8'
   *  UnitDelay: '<S9>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c22_WinCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c22_WinCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_PsgWinUpReq = false;
  } else if (AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib == AppSwcBcm_IN_Off) {
    AppSwcBcm_ARID_DEF.Lib_blIn_m4 = rtb_LogicalOperator2_ad;

    /* Outputs for Function Call SubSystem: '<S174>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_m4,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ir,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_e);

    /* End of Outputs for SubSystem: '<S174>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ir &&
        (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_iw)) {
      AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib = AppSwcBcm_IN_On;
      WinCtl_PsgWinUpReq = true;
    }

    /* case IN_On: */
  } else if ((!rtb_LogicalOperator2_ad) ||
             AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_iw || (WinCtl_PsgWinReq == 0))
  {
    AppSwcBcm_ARID_DEF.is_c22_WinCtl_Lib = AppSwcBcm_IN_Off;
    WinCtl_PsgWinUpReq = false;
  }

  /* End of Chart: '<S141>/Chart5' */

  /* Switch: '<S141>/Switch4' incorporates:
   *  Switch: '<S141>/Switch5'
   */
  if (WinCtl_PsgWinDnReq) {
    /* Switch: '<S141>/Switch4' incorporates:
     *  Constant: '<S141>/Constant12'
     */
    WinCtl_PsgWinReq = 2U;
  } else if (WinCtl_PsgWinAutoDnReq) {
    /* Switch: '<S141>/Switch5' incorporates:
     *  Constant: '<S141>/Constant13'
     *  Switch: '<S141>/Switch4'
     */
    WinCtl_PsgWinReq = 3U;
  } else {
    /* Switch: '<S141>/Switch4' incorporates:
     *  Switch: '<S141>/Switch5'
     *  Switch: '<S141>/Switch6'
     */
    WinCtl_PsgWinReq = (uint8)WinCtl_PsgWinUpReq;
  }

  /* End of Switch: '<S141>/Switch4' */

  /* Chart: '<S141>/LIB_PosPluse1' incorporates:
   *  Constant: '<S141>/Constant8'
   *  Logic: '<S141>/Logical Operator11'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator2_ad || rtb_RelationalOperator3_pv ||
    WinCtl_PsgWinAutoDnReq || WinCtl_WinDnRKEReq || WinCtl_WinUpRKEReq,
    WinCtl_WinRunTimMax_C, &rtb_LIB_blOut_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1_a);

  /* Chart: '<S141>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S141>/Constant10'
   *  Constant: '<S141>/Constant11'
   *  Constant: '<S141>/Constant44'
   *  Constant: '<S141>/Constant48'
   *  RelationalOperator: '<S141>/Relational Operator7'
   */
  AppSwcBcm_LIB_TPD_10ms1(BSW_PsgWinMotorCur >= WinCtl_WinMotorCurMax_C,
    WinCtl_WinMotorCurTimValid_C, WinCtl_WinMotorCurTimInValid_C, WinCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_k3,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_bb);

  /* Switch: '<S141>/Switch10' incorporates:
   *  Constant: '<S141>/Constant27'
   *  Logic: '<S141>/Logical Operator4'
   *  Logic: '<S141>/Logical Operator7'
   *  Switch: '<S141>/Switch9'
   */
  if (AppSwcBcm_ARID_DEF.LIB_bErrFlg_k3 || rtb_LIB_blOut_d) {
    WinCtl_PsgWinReq = 0U;
  } else {
    if (rtb_RelationalOperator5_gh) {
      /* Switch: '<S141>/Switch9' */
      tmp = WinCtl_PsgWinReq;
    } else {
      /* Switch: '<S141>/Switch9' incorporates:
       *  Constant: '<S141>/Constant33'
       */
      tmp = 0U;
    }

    /* Switch: '<S141>/Switch13' incorporates:
     *  Switch: '<S141>/Switch9'
     */
    if (tmp == 0) {
      WinCtl_PsgWinReq = rtb_Switch12;
    }

    /* End of Switch: '<S141>/Switch13' */
  }

  /* End of Switch: '<S141>/Switch10' */
}

/* System initialize for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S9>/WinSwArb' */
  AppSwcBcm_WinSwArb_Init();

  /* End of SystemInitialize for SubSystem: '<S9>/WinSwArb' */
}

/* Output and update for atomic system: '<S1>/WinCtl' */
static void AppSwcBcm_WinCtl(void)
{
  /* Outputs for Atomic SubSystem: '<S9>/SigProc' */
  AppSwcBcm_SigProc();

  /* End of Outputs for SubSystem: '<S9>/SigProc' */

  /* Outputs for Atomic SubSystem: '<S9>/WinSwArb' */
  AppSwcBcm_WinSwArb();

  /* End of Outputs for SubSystem: '<S9>/WinSwArb' */

  /* Chart: '<S9>/DrvWinCtl' */
  AppSwcBcm_DrvWinCtl();

  /* Outputs for Atomic SubSystem: '<S9>/Ovrd4' */
  /* Switch: '<S137>/Switch1' incorporates:
   *  Constant: '<S9>/Constant1'
   */
  if (WinCtl_J53DrvWinDnOvrdFlg_C) {
    /* Switch: '<S137>/Switch1' incorporates:
     *  Constant: '<S9>/Constant2'
     */
    WinCtl_J53DrvWinDn = WinCtl_J53DrvWinDnOvrdVal_C;
  } else {
    /* Switch: '<S137>/Switch1' incorporates:
     *  Switch: '<S137>/Switch2'
     */
    WinCtl_J53DrvWinDn = AppSwcBcm_ARID_DEF.WinCtl_J53;
  }

  /* End of Switch: '<S137>/Switch1' */
  /* End of Outputs for SubSystem: '<S9>/Ovrd4' */

  /* Chart: '<S9>/PsgWinCtl' */
  AppSwcBcm_PsgWinCtl();

  /* Outputs for Atomic SubSystem: '<S9>/WinMotorProt' */
  AppSwcBcm_WinMotorProt();

  /* End of Outputs for SubSystem: '<S9>/WinMotorProt' */

  /* Outputs for Atomic SubSystem: '<S9>/Ovrd2' */
  /* Switch: '<S135>/Switch' incorporates:
   *  Constant: '<S9>/Constant3'
   */
  if (WinCtl_J55PsgWinUpOvrdFlg_C) {
    /* Switch: '<S135>/Switch' incorporates:
     *  Constant: '<S9>/Constant4'
     */
    WinCtl_J55PsgWinUp = WinCtl_J55PsgWinUpOvrdVal_C;
  } else {
    /* Switch: '<S135>/Switch' */
    WinCtl_J55PsgWinUp = AppSwcBcm_ARID_DEF.WinCtl_J55;
  }

  /* End of Switch: '<S135>/Switch' */
  /* End of Outputs for SubSystem: '<S9>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S9>/Ovrd3' */
  /* Switch: '<S136>/Switch' incorporates:
   *  Constant: '<S9>/Constant5'
   */
  if (WinCtl_J57PsgWinDnOvrdFlg_C) {
    /* Switch: '<S136>/Switch' incorporates:
     *  Constant: '<S9>/Constant6'
     */
    WinCtl_J57PsgWinDn = WinCtl_J57PsgWinDnOvrdVal_C;
  } else {
    /* Switch: '<S136>/Switch' */
    WinCtl_J57PsgWinDn = AppSwcBcm_ARID_DEF.WinCtl_J57;
  }

  /* End of Switch: '<S136>/Switch' */
  /* End of Outputs for SubSystem: '<S9>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S9>/Ovrd1' */
  /* Switch: '<S134>/Switch1' incorporates:
   *  Constant: '<S9>/Constant18'
   */
  if (WinCtl_J51DrvWinUpOvrdFlg_C) {
    /* Switch: '<S134>/Switch1' incorporates:
     *  Constant: '<S9>/Constant19'
     */
    WinCtl_J51DrvWinUp = WinCtl_J51DrvWinUpOvrdVal_C;
  } else {
    /* Switch: '<S134>/Switch1' incorporates:
     *  Switch: '<S134>/Switch2'
     */
    WinCtl_J51DrvWinUp = AppSwcBcm_ARID_DEF.WinCtl_J51;
  }

  /* End of Switch: '<S134>/Switch1' */
  /* End of Outputs for SubSystem: '<S9>/Ovrd1' */

  /* Update for UnitDelay: '<S9>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_in = WinCtl_DrvWinUpProt;

  /* Update for UnitDelay: '<S9>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_iw = WinCtl_PsgWinUpProt;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_ln = WinCtl_DrvWinDnProt;

  /* Update for UnitDelay: '<S9>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_g = WinCtl_PsgWinDnProt;
}

/* Outputs for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl(void)
{
  sint32 tmp;
  uint8 rtb_CCaller;
  boolean rtb_LogicalOperator3_gx;
  boolean rtb_RelationalOperator1_gf;
  boolean rtb_RelationalOperator5_ei;

  /* CCaller: '<S192>/C Caller' */
  rtb_CCaller = Get_PEAuth_FobStatus();

  /* Logic: '<S195>/Logical Operator3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S195>/Logical Operator2'
   */
  rtb_LogicalOperator3_gx = !(Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())
    ->DrvSeatSw;

  /* RelationalOperator: '<S197>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S195>/Relational Operator'
   */
  rtb_RelationalOperator1_gf =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum <= 1);

  /* RelationalOperator: '<S197>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S195>/Logical Operator'
   */
  rtb_RelationalOperator5_ei =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarRRSw);

  /* Logic: '<S195>/Logical Operator3' */
  rtb_LogicalOperator3_gx = (rtb_LogicalOperator3_gx &&
    rtb_RelationalOperator1_gf && rtb_RelationalOperator5_ei);

  /* Logic: '<S195>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S209>/Compare'
   *  UnitDelay: '<S195>/Unit Delay'
   */
  rtb_RelationalOperator1_gf = ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ocg) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw &&
    rtb_LogicalOperator3_gx);

  /* Logic: '<S195>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S210>/Compare'
   *  UnitDelay: '<S195>/Unit Delay1'
   */
  rtb_LogicalOperator3_gx = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cb) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw &&
    rtb_LogicalOperator3_gx);

  /* Chart: '<S195>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_DrvPEAuthentAcsd = 0U;
    PEPSCtl_KeyInCarSta = 0U;
    AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
    PEPSCtl_FRPEAuthentAcsd = 0U;
    Clear_PEStatus();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_l:
      if (rtb_RelationalOperator1_gf) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_LSeekKeyOut;
        Set_PEAuth_FobReq(1U);
        AppSwcBcm_ARID_DEF.count_jv = 0U;
      } else if (rtb_LogicalOperator3_gx) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_RSeekKeyOut;
        Set_PEAuth_FobReq(2U);
        AppSwcBcm_ARID_DEF.count_jv = 0U;
      }
      break;

     case AppSwcBcm_IN_LSeekKeyOut:
      if (AppSwcBcm_ARID_DEF.count_jv >= 10) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        PEPSCtl_DrvPEAuthentAcsd = 0U;
        PEPSCtl_KeyInCarSta = 0U;
        AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
        PEPSCtl_FRPEAuthentAcsd = 0U;
        Clear_PEStatus();
      } else {
        if (rtb_CCaller == 1) {
          PEPSCtl_DrvPEAuthentAcsd = 1U;
          tmp = AppSwcBcm_ARID_DEF.count_jv + 1;
          if (AppSwcBcm_ARID_DEF.count_jv + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_jv = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_jv + 1;
          if (AppSwcBcm_ARID_DEF.count_jv + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_jv = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_DrvPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_jv + 1;
          if (AppSwcBcm_ARID_DEF.count_jv + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_jv = (uint8)tmp;
        }
      }
      break;

     default:
      /* case IN_RSeekKeyOut: */
      if (AppSwcBcm_ARID_DEF.count_jv >= 10) {
        AppSwcBcm_ARID_DEF.is_c3_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
        PEPSCtl_DrvPEAuthentAcsd = 0U;
        PEPSCtl_KeyInCarSta = 0U;
        AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 0.0F;
        PEPSCtl_FRPEAuthentAcsd = 0U;
        Clear_PEStatus();
      } else {
        if (rtb_CCaller == 1) {
          PEPSCtl_FRPEAuthentAcsd = 1U;
          tmp = AppSwcBcm_ARID_DEF.count_jv + 1;
          if (AppSwcBcm_ARID_DEF.count_jv + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_jv = (uint8)tmp;
        }

        if (rtb_CCaller == 2) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          tmp = AppSwcBcm_ARID_DEF.count_jv + 1;
          if (AppSwcBcm_ARID_DEF.count_jv + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_jv = (uint8)tmp;
        }

        if (rtb_CCaller == 3) {
          PEPSCtl_FRPEAuthentAcsd = 2U;
          PEPSCtl_KeyInCarSta = 1U;
          AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar = 1.0F;
          tmp = AppSwcBcm_ARID_DEF.count_jv + 1;
          if (AppSwcBcm_ARID_DEF.count_jv + 1 > 255) {
            tmp = 255;
          }

          AppSwcBcm_ARID_DEF.count_jv = (uint8)tmp;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S195>/Chart' */

  /* Chart: '<S195>/Chart3' */
  if (AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c8_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count_b = 0.0;
    PEPSCtl_AvaluebleKeyInCar = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    PEPSCtl_AvaluebleKeyInCar = 0U;
    if (AppSwcBcm_ARID_DEF.BCM_AvaluebleKeyInCar == 1.0F) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_e;
      AppSwcBcm_ARID_DEF.count_b = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_AvaluebleKeyInCar = 1U;
    if (AppSwcBcm_ARID_DEF.count_b >= 1000.0) {
      AppSwcBcm_ARID_DEF.is_c8_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      AppSwcBcm_ARID_DEF.count_b = 0.0;
      PEPSCtl_AvaluebleKeyInCar = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count_b++;
    }
  }

  /* End of Chart: '<S195>/Chart3' */

  /* RelationalOperator: '<S197>/Relational Operator5' incorporates:
   *  Constant: '<S199>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S199>/Compare'
   */
  rtb_RelationalOperator5_ei = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 0);

  /* Logic: '<S193>/Logical Operator' incorporates:
   *  Constant: '<S200>/Constant'
   *  RelationalOperator: '<S200>/Compare'
   *  UnitDelay: '<S193>/Unit Delay'
   */
  rtb_LogicalOperator3_gx = (rtb_RelationalOperator5_ei &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hr > 0));

  /* CCaller: '<S193>/C Caller1' */
  rtb_CCaller = Get_FobdKeyNum();

  /* Chart: '<S193>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c6_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib) {
     case AppSwcBcm_IN_FobidKey:
      if ((PEPSCtl_FrbdnKeyNr > 0) || (AppSwcBcm_ARID_DEF.count_j > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      } else if (rtb_LogicalOperator3_gx) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_j = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_j + 1;
        if (AppSwcBcm_ARID_DEF.count_j + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_j = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     case AppSwcBcm_IN_Init:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->OsLckSta == 1) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_FobidKey;
        AppSwcBcm_ARID_DEF.count_j = 0U;
        Set_PSAuth_FobReq(2U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      } else if (rtb_LogicalOperator3_gx) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_RelesKey;
        AppSwcBcm_ARID_DEF.count_j = 0U;
        Set_PSAuth_FobReq(3U);
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;

     default:
      /* case IN_RelesKey: */
      if ((PEPSCtl_FrbdnKeyNr == 0) || (AppSwcBcm_ARID_DEF.count_j > 20)) {
        AppSwcBcm_ARID_DEF.is_c6_PEPSCtl_Lib = AppSwcBcm_IN_Init;
      } else {
        tmp = AppSwcBcm_ARID_DEF.count_j + 1;
        if (AppSwcBcm_ARID_DEF.count_j + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.count_j = (uint16)tmp;
        PEPSCtl_FrbdnKeyNr = rtb_CCaller;
      }
      break;
    }
  }

  /* End of Chart: '<S193>/Chart' */

  /* CCaller: '<S192>/C Caller1' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* RelationalOperator: '<S197>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S196>/Relational Operator5'
   */
  rtb_RelationalOperator5_ei = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus()
    )->BrakeLightSw;

  /* Logic: '<S196>/Logical Operator3' incorporates:
   *  RelationalOperator: '<S196>/Relational Operator4'
   *  UnitDelay: '<S196>/Unit Delay1'
   */
  rtb_LogicalOperator3_gx = ((!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_lv) &&
    rtb_RelationalOperator5_ei);

  /* RelationalOperator: '<S197>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S196>/Relational Operator2'
   */
  rtb_RelationalOperator5_ei = (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus
    ())->DrvSeatSw;

  /* RelationalOperator: '<S197>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S196>/Relational Operator3'
   */
  rtb_RelationalOperator1_gf =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S196>/Chart' incorporates:
   *  Logic: '<S196>/Logical Operator1'
   *  Logic: '<S196>/Logical Operator2'
   *  Logic: '<S196>/Logical Operator5'
   *  RelationalOperator: '<S196>/Relational Operator1'
   *  RelationalOperator: '<S196>/Relational Operator6'
   *  UnitDelay: '<S196>/Unit Delay'
   *  UnitDelay: '<S196>/Unit Delay2'
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
    if ((rtb_LogicalOperator3_gx || ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pf) &&
          rtb_RelationalOperator5_ei)) &&
        (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n4 == 0) &&
        rtb_RelationalOperator1_gf) {
      AppSwcBcm_ARID_DEF.is_c1_PEPSCtl_Lib = AppSwcBcm_IN_PSSeekKeyOut;
      AppSwcBcm_ARID_DEF.count_l = 0U;
      AppSwcBcm_ARID_DEF.count1 = 0U;
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

  /* End of Chart: '<S196>/Chart' */

  /* Switch: '<S194>/Switch1' incorporates:
   *  Constant: '<S194>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S194>/Unit Delay3'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode != 0) {
    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_e = false;
  } else {
    /* Switch: '<S194>/Switch' incorporates:
     *  Constant: '<S205>/Constant'
     *  Constant: '<S206>/Constant'
     *  Logic: '<S194>/Logical Operator3'
     *  RelationalOperator: '<S205>/Compare'
     *  RelationalOperator: '<S206>/Compare'
     *  UnitDelay: '<S194>/Unit Delay2'
     *  UnitDelay: '<S194>/Unit Delay3'
     */
    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_e = (((PEPSCtl_PSAuthentRes == 1) &&
      (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c != 1)) ||
      AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_e);
  }

  /* End of Switch: '<S194>/Switch1' */

  /* RelationalOperator: '<S197>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S194>/Logical Operator1'
   */
  rtb_RelationalOperator5_ei =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw &&
     (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw);

  /* Logic: '<S194>/Logical Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S194>/Logical Operator'
   *  Logic: '<S194>/Logical Operator2'
   *  RelationalOperator: '<S203>/Compare'
   *  RelationalOperator: '<S204>/Compare'
   *  UnitDelay: '<S194>/Unit Delay'
   *  UnitDelay: '<S194>/Unit Delay1'
   *  UnitDelay: '<S194>/Unit Delay3'
   */
  rtb_LogicalOperator3_gx = (rtb_RelationalOperator5_ei &&
    ((!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kk) ||
     (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k)) &&
    AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_e &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->VehStop &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw);

  /* CCaller: '<S194>/C Caller7' */
  rtb_CCaller = Get_PSAuth_FobStatus();

  /* Chart: '<S194>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c10_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_WarnKeyOutReminder = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    if (rtb_LogicalOperator3_gx) {
      AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_KeyNotInCar;
      AppSwcBcm_ARID_DEF.count_e = 0U;
      Set_PSAuth_FobReq(1U);
    }

    /* case IN_KeyNotInCar: */
  } else if (AppSwcBcm_ARID_DEF.count_e >= 1000) {
    AppSwcBcm_ARID_DEF.is_c10_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    PEPSCtl_WarnKeyOutReminder = 0U;
  } else if (rtb_CCaller == 2) {
    PEPSCtl_WarnKeyOutReminder = 1U;
    tmp = AppSwcBcm_ARID_DEF.count_e + 1;
    if (AppSwcBcm_ARID_DEF.count_e + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.count_e = (uint16)tmp;
  }

  /* End of Chart: '<S194>/Chart' */

  /* Chart: '<S196>/Chart1' */
  if (AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c4_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
    AppSwcBcm_ARID_DEF.count_k = 0.0;
    PEPSCtl_KeySta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib) {
     case AppSwcBcm_IN_IMMOKeyValid:
      PEPSCtl_KeySta = 3U;
      if (AppSwcBcm_ARID_DEF.count_k >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
        AppSwcBcm_ARID_DEF.count_k = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_k++;
      }
      break;

     case AppSwcBcm_IN_Init:
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
        AppSwcBcm_ARID_DEF.is_c4_PEPSCtl_Lib = AppSwcBcm_IN_Init;
        AppSwcBcm_ARID_DEF.count_k = 0.0;
        PEPSCtl_KeySta = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_k++;
      }
      break;
    }
  }

  /* End of Chart: '<S196>/Chart1' */

  /* Chart: '<S196>/Chart2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_h = AppSwcBcm_ARID_DEF.Power_Mode_start_o;
  AppSwcBcm_ARID_DEF.Power_Mode_start_o =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev_g =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_n;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_n =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_h =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev_g =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c5_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count_h = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
  } else if (AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    if (AppSwcBcm_ARID_DEF.BCM_WarnNoKeyFound == 1) {
      AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_NOKeyValid;
      AppSwcBcm_ARID_DEF.count_h = 0.0;
      AppSwcBcm_ARID_DEF.NoKey_count++;
      AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
    } else {
      AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
      if (AppSwcBcm_ARID_DEF.NoKey_Tmcount >= 6000.0) {
        AppSwcBcm_ARID_DEF.NoKey_count = 0.0;
        AppSwcBcm_ARID_DEF.NoKey_Tmcount = 0.0;
      }
    }

    /* case IN_NOKeyValid: */
  } else if ((AppSwcBcm_ARID_DEF.count_h >= 1000.0) ||
             ((AppSwcBcm_ARID_DEF.Power_Mode_prev_h !=
               AppSwcBcm_ARID_DEF.Power_Mode_start_o) &&
              (AppSwcBcm_ARID_DEF.Power_Mode_start_o == 2)) ||
             ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev_g !=
               AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_n) &&
              (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start_n == 2))) {
    AppSwcBcm_ARID_DEF.is_c5_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count_h = 0.0;
    PEPSCtl_WarnNoKeyFound = 0U;
    AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
  } else {
    AppSwcBcm_ARID_DEF.count_h++;
    AppSwcBcm_ARID_DEF.NoKey_Tmcount++;
    if (AppSwcBcm_ARID_DEF.NoKey_count >= 2.0) {
      AppSwcBcm_ARID_DEF.Cur_IndicationKeyCloser = 1.0;
      PEPSCtl_WarnNoKeyFound = 0U;
    } else {
      PEPSCtl_WarnNoKeyFound = 1U;
    }

    if (AppSwcBcm_ARID_DEF.NoKey_Tmcount >= 6000.0) {
      AppSwcBcm_ARID_DEF.NoKey_count = 0.0;
      AppSwcBcm_ARID_DEF.NoKey_Tmcount = 0.0;
    }
  }

  /* End of Chart: '<S196>/Chart2' */

  /* Chart: '<S196>/Chart3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Power_Mode_prev_o = AppSwcBcm_ARID_DEF.Power_Mode_start_i;
  AppSwcBcm_ARID_DEF.Power_Mode_start_i =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start;
  AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum;
  if (AppSwcBcm_ARID_DEF.is_active_c7_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.Power_Mode_prev_o =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus())->SysPwrMode;
    AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev =
      (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
      ->VHVM_PTActOprtMode_enum;
    AppSwcBcm_ARID_DEF.is_active_c7_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
    AppSwcBcm_ARID_DEF.count = 0.0;
    PEPSCtl_IndicationKeyCloser = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib == AppSwcBcm_IN_Init_l) {
    PEPSCtl_IndicationKeyCloser = 0U;
    if (AppSwcBcm_ARID_DEF.Cur_IndicationKeyCloser == 1.0) {
      AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib = AppSwcBcm_IN_KeyValid_e;
      AppSwcBcm_ARID_DEF.count = 0.0;
      PEPSCtl_IndicationKeyCloser = 1U;
    }
  } else {
    /* case IN_KeyValid: */
    PEPSCtl_IndicationKeyCloser = 1U;
    if ((AppSwcBcm_ARID_DEF.count >= 1000.0) ||
        ((AppSwcBcm_ARID_DEF.Power_Mode_prev_o !=
          AppSwcBcm_ARID_DEF.Power_Mode_start_i) &&
         (AppSwcBcm_ARID_DEF.Power_Mode_start_i == 2)) ||
        ((AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_prev !=
          AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start) &&
         (AppSwcBcm_ARID_DEF.VCU_PTActlOprtMode_start == 2))) {
      AppSwcBcm_ARID_DEF.is_c7_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
      AppSwcBcm_ARID_DEF.count = 0.0;
      PEPSCtl_IndicationKeyCloser = 0U;
    } else {
      AppSwcBcm_ARID_DEF.count++;
    }
  }

  /* End of Chart: '<S196>/Chart3' */

  /* Chart: '<S196>/Chart5' incorporates:
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

  /* End of Chart: '<S196>/Chart5' */

  /* CCaller: '<S192>/C Caller2' */
  rtb_CCaller = Get_Wlcm_FunStatus();

  /* CCaller: '<S192>/C Caller3' */
  Get_PollingWork_State();

  /* RelationalOperator: '<S197>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S197>/Relational Operator3'
   */
  rtb_RelationalOperator1_gf = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus
    ())->BodyWarnSts > 0);

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/Constant4'
   *  Logic: '<S197>/Logical Operator5'
   *  RelationalOperator: '<S197>/Relational Operator2'
   *  UnitDelay: '<S197>/Unit Delay'
   *  UnitDelay: '<S197>/Unit Delay1'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g != 0) ||
      (!rtb_RelationalOperator1_gf)) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_pg = 0U;
  }

  /* End of Switch: '<S197>/Switch' */

  /* RelationalOperator: '<S197>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator5_ei = ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* RelationalOperator: '<S197>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_gf =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S197>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  UnitDelay: '<S197>/Unit Delay1'
   */
  rtb_LogicalOperator3_gx = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_pg != 0) &&
    ((Rte_IrvIRead_Runbl_AppSwcBcm_10ms_IPM_HU_B_BAC())
     ->VIPM_HUIllmndEntrySts_enum != 0) && rtb_RelationalOperator5_ei &&
    rtb_RelationalOperator1_gf);

  /* Chart: '<S197>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c2_PEPSCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib = AppSwcBcm_IN_Init_l;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c2_PEPSCtl_Lib) {
     case AppSwcBcm_IN_Init_l:
      if (rtb_LogicalOperator3_gx) {
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

  /* End of Chart: '<S197>/Chart' */

  /* CCaller: '<S192>/C Caller7' */
  rtb_CCaller = Get_KeyBat_VolLow();

  /* Chart: '<S194>/Chart3' */
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
        AppSwcBcm_ARID_DEF.count_d = 0.0;
        PEPSCtl_KeyLoBattLvlWarn = 1U;
      }
      break;

     default:
      /* case IN_KeyValid: */
      PEPSCtl_KeyLoBattLvlWarn = 1U;
      if (AppSwcBcm_ARID_DEF.count_d >= 1000.0) {
        AppSwcBcm_ARID_DEF.is_c9_PEPSCtl_Lib = AppSwcBcm_IN_Finish;
        PEPSCtl_KeyLoBattLvlWarn = 0U;
      } else {
        AppSwcBcm_ARID_DEF.count_d++;
      }
      break;
    }
  }

  /* End of Chart: '<S194>/Chart3' */
}

/* Update for atomic system: '<S2>/PEPSCtl' */
static void AppSwcBcm_PEPSCtl_Update(void)
{
  /* Update for UnitDelay: '<S195>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ocg =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvPESw;

  /* Update for UnitDelay: '<S195>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->PsgPESw;

  /* Update for UnitDelay: '<S193>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* Update for UnitDelay: '<S196>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_lv =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S196>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pf =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DrvSeatSw;

  /* Update for UnitDelay: '<S196>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n4 = AppSwcBcm_ARID_DEF.BCM_KeySta;

  /* Update for UnitDelay: '<S194>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_c = PEPSCtl_PSAuthentRes;

  /* Update for UnitDelay: '<S194>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kk =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Update for UnitDelay: '<S194>/Unit Delay1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_k =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* Update for UnitDelay: '<S197>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_g =
    (Rte_IrvIRead_Runbl_AppSwcBcm_10ms_AlmSysCtl_Bus())->BodyWarnSts;
}

/* Output and update for atomic system: '<S217>/HwOutBCM' */
static void AppSwcBcm_HwOutBCM(void)
{
  uint8 rtb_DataTypeConversion30;

  /* DataTypeConversion: '<S223>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S223>/DataTypeConversion14'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J421IG1RlyCtl;

  /* CCaller: '<S223>/HwIG1RlyCls' */
  SetHw_IG1RlyCls(rtb_DataTypeConversion30);

  /* CCaller: '<S223>/HwHzrdLampOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion16'
   *  Logic: '<S244>/Logical Operator'
   *  Logic: '<S244>/Logical Operator1'
   *  RelationalOperator: '<S244>/Relational Operator'
   */
  SetHw_HzrdLampOn((uint8)(AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrRSta &&
    AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLSta &&
    (AppSwcBcm_ARID_DEF.UnitDelay2.HazardLightSta ||
     AppSwcBcm_ARID_DEF.UnitDelay2.EmerHazardLightSta)));

  /* CCaller: '<S223>/HwCabinLampPWM' incorporates:
   *  Constant: '<S223>/Constant43'
   */
  SetHw_CabinLampPWM(200U, AppSwcBcm_ARID_DEF.UnitDelay2.DomeLampPwmDuty);

  /* DataTypeConversion: '<S223>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S223>/DataTypeConversion15'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->J437IG2RlyCtl;

  /* CCaller: '<S223>/HwIG2RlyCls' */
  SetHw_IG2RlyCls(rtb_DataTypeConversion30);

  /* CCaller: '<S223>/HwBackLightCtl' incorporates:
   *  Constant: '<S223>/Constant'
   */
  SetHw_BackLightDrv(100U, AppSwcBcm_ARID_DEF.UnitDelay2.J408BackLampPWM);

  /* CCaller: '<S223>/HwDrvSeatHeatCtl' incorporates:
   *  Constant: '<S223>/Constant1'
   */
  SetHw_DrvSeatHeat(200U, AppSwcBcm_ARID_DEF.SeatCtl_Bus.CN167DrvSeatHtPWM);

  /* CCaller: '<S223>/HwWiprOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion'
   */
  SetHw_WiprOn(AppSwcBcm_ARID_DEF.UnitDelay3.LowSpdDrv);

  /* CCaller: '<S223>/HwWiprHiSpd' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion1'
   */
  SetHw_WiprHiSpd(AppSwcBcm_ARID_DEF.UnitDelay3.HiSpdDrv);

  /* CCaller: '<S223>/HwFrntWshrOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion2'
   */
  SetHw_FrntWshrOn(AppSwcBcm_ARID_DEF.UnitDelay3.WashMotorDrv);

  /* DataTypeConversion: '<S223>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S223>/DataTypeConversion3'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J56DoorUnlck;

  /* CCaller: '<S223>/HwGlbDoorUnlck' */
  SetHw_GlbDoorUnlck(rtb_DataTypeConversion30);

  /* DataTypeConversion: '<S223>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S223>/DataTypeConversion4'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J54DoorLck;

  /* CCaller: '<S223>/HwGlbDoorLck' */
  SetHw_GlbDoorLck(rtb_DataTypeConversion30);

  /* CCaller: '<S223>/HwDrvrWinUp' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion5'
   */
  SetHw_DrvrWinUp(AppSwcBcm_ARID_DEF.WinCtl_Bus.J51DrvWinUp);

  /* CCaller: '<S223>/HwDrvrWinDwn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion6'
   */
  SetHw_DrvrWinDwn(AppSwcBcm_ARID_DEF.WinCtl_Bus.J53DrvWinDn);

  /* CCaller: '<S223>/HwPsngrWinUp' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion7'
   */
  SetHw_PsngrWinUp(AppSwcBcm_ARID_DEF.WinCtl_Bus.J55PsgWinUp);

  /* CCaller: '<S223>/HwPsngrWinDwn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion8'
   */
  SetHw_PsngrWinDwn(AppSwcBcm_ARID_DEF.WinCtl_Bus.J57PsgWinDn);

  /* CCaller: '<S223>/HwPstnLampOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion9'
   */
  SetHw_PstnLampOn(AppSwcBcm_ARID_DEF.UnitDelay2.PosLampSta);

  /* CCaller: '<S223>/HwTurnLampOnLeft' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion10'
   */
  SetHw_TurnLampOnLeft(AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLSta);

  /* CCaller: '<S223>/HwTurnLampOnRght' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion11'
   */
  SetHw_TurnLampOnRght(AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrRSta);

  /* CCaller: '<S223>/HwBrkLghtOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion12'
   */
  SetHw_BrkLghtOn(AppSwcBcm_ARID_DEF.UnitDelay2.BrakeLightSta);

  /* CCaller: '<S223>/HwRvrsLampOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion13'
   */
  SetHw_RvrsLampOn(AppSwcBcm_ARID_DEF.UnitDelay2.ReverseLampSta);

  /* CCaller: '<S223>/HwLoBeamOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion17'
   */
  SetHw_LoBeamOn(AppSwcBcm_ARID_DEF.UnitDelay2.LowBeamSta);

  /* CCaller: '<S223>/HwHiBeamOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion18'
   */
  SetHw_HiBeamOn(AppSwcBcm_ARID_DEF.UnitDelay2.HiBeamSta);

  /* CCaller: '<S223>/HwAlrmHornOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion19'
   */
  SetHw_AlrmHornOn(AppSwcBcm_ARID_DEF.UnitDelay1_h.HornDrv);

  /* CCaller: '<S223>/HwRearFogLampOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion20'
   */
  SetHw_RearFogLampOn(AppSwcBcm_ARID_DEF.UnitDelay2.FogLampRSta);

  /* CCaller: '<S223>/HwSavePwrEnbl' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion21'
   */
  SetHw_SavePwrEnbl(AppSwcBcm_ARID_DEF.BatSaveCtl_Bus.J64SavePwr);

  /* CCaller: '<S223>/HwDayRunLghtOn' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion23'
   */
  SetHw_DayRunLghtOn(AppSwcBcm_ARID_DEF.UnitDelay2.DayRunLightSta);

  /* DataTypeConversion: '<S223>/DataTypeConversion30' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S223>/DataTypeConversion24'
   */
  rtb_DataTypeConversion30 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->J511TrunkUnlck;

  /* CCaller: '<S223>/HwTrunkUnlck' */
  Set_TrunkUnLock(rtb_DataTypeConversion30);

  /* CCaller: '<S223>/HwBSDLeftCtl' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion25'
   */
  Set_BSDLeftCtl(AppSwcBcm_ARID_DEF.UnitDelay2.BSDLeftCtl);

  /* CCaller: '<S223>/HwBSDRightCtl' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion26'
   */
  Set_BSDRightCtl(AppSwcBcm_ARID_DEF.UnitDelay2.BSDRightCtl);

  /* CCaller: '<S223>/HwESCLPwrSup' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion27'
   */
  SetHw_PwrSup(AppSwcBcm_ARID_DEF.ESCLCtl_Bus.J436PwrSup);

  /* CCaller: '<S223>/HwRVMHeatCtl' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion28'
   */
  SetHw_RearMirrorHeat(AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat);

  /* CCaller: '<S223>/HwBoxLampCtl' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion29'
   */
  SetHw_BoxLampSta(AppSwcBcm_ARID_DEF.UnitDelay2.BoxLampSta);

  /* CCaller: '<S223>/HwFrontFogLampCtl' incorporates:
   *  DataTypeConversion: '<S223>/DataTypeConversion30'
   */
  SetHw_FrontFogLamps(AppSwcBcm_ARID_DEF.UnitDelay2.FogLampFSta);
}

/*
 * System initialize for atomic system:
 *    '<S227>/Lib_RiseEdgeDelay'
 *    '<S228>/Lib_RiseEdgeDelay'
 *    '<S228>/Lib_RiseEdgeDelay1'
 *    '<S230>/Lib_RiseEdgeDelay'
 *    '<S230>/Lib_RiseEdgeDelay1'
 *    '<S530>/Lib_RiseEdgeDelay'
 *    '<S768>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S227>/Lib_RiseEdgeDelay'
 *    '<S228>/Lib_RiseEdgeDelay'
 *    '<S228>/Lib_RiseEdgeDelay1'
 *    '<S230>/Lib_RiseEdgeDelay'
 *    '<S230>/Lib_RiseEdgeDelay1'
 *    '<S530>/Lib_RiseEdgeDelay'
 *    '<S768>/Lib_RiseEdgeDelay'
 */
static void AppSwcBcm_Lib_RiseEdgeDelay(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16DelayTim, boolean *rty_LIB_blOut,
  ARID_DEF_Lib_RiseEdgeDelay_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rtb_LogicalOperator1_d4;

  /* Outputs for Function Call SubSystem: '<S245>/Lib_RiseEdgeDet' */
  /* Logic: '<S247>/Logical Operator1' incorporates:
   *  UnitDelay: '<S247>/Unit Delay'
   */
  rtb_LogicalOperator1_d4 = !AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;

  /* Update for UnitDelay: '<S247>/Unit Delay' incorporates:
   *  Chart: '<S227>/Lib_RiseEdgeDelay'
   */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_LIB_blIn;

  /* Chart: '<S227>/Lib_RiseEdgeDelay' incorporates:
   *  Logic: '<S247>/Logical Operator'
   */
  if (rtu_LIB_blIn && rtb_LogicalOperator1_d4) {
    AppSwcBcm__ARID_DEF_arg->Cnt = rtu_LIB_u16DelayTim;
    *rty_LIB_blOut = true;
  }

  /* End of Outputs for SubSystem: '<S245>/Lib_RiseEdgeDet' */
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

  /* SystemInitialize for Chart: '<S227>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_c);

  /* SystemInitialize for Chart: '<S228>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_ob);

  /* SystemInitialize for Chart: '<S228>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_d);

  /* SystemInitialize for Chart: '<S230>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_pp);

  /* SystemInitialize for Chart: '<S230>/Lib_RiseEdgeDelay1' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&LIB_blOut_pp);
}

/* Output and update for atomic system: '<S3>/BCMTx' */
static void AppSwcBcm_BCMTx(void)
{
  uint8 rtb_MultiportSwitch;
  uint8 rtb_MultiportSwitch_m;
  boolean rtb_RelationalOperator;

  /* DataTypeConversion: '<S217>/Data Type Conversion' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Left =
    AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion1' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLampSta_Right =
    AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrRSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion2' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Rear =
    AppSwcBcm_ARID_DEF.UnitDelay2.FogLampRSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion3' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PosLampSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.PosLampSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion4' incorporates:
   *  Logic: '<S232>/Logical Operator'
   *  Logic: '<S232>/Logical Operator1'
   *  RelationalOperator: '<S232>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardLampSts = (uint8)
    (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrRSta &&
     AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLSta &&
     (AppSwcBcm_ARID_DEF.UnitDelay2.HazardLightSta ||
      AppSwcBcm_ARID_DEF.UnitDelay2.EmerHazardLightSta));

  /* DataTypeConversion: '<S217>/Data Type Conversion5' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.HiBeamSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion6' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LowBeamSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.LowBeamSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion7' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FogLampSta_Front =
    AppSwcBcm_ARID_DEF.UnitDelay2.FogLampFSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion8' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AutoLampStatus =
    AppSwcBcm_ARID_DEF.UnitDelay2.AutoLampSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion9' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLightSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.DayRunLightSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ReverseLampSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.ReverseLampSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion11' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakeLampSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.BrakeLightSta;

  /* MultiPortSwitch: '<S224>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrMod) {
   case 0:
    /* MultiPortSwitch: '<S224>/Multiport Switch' incorporates:
     *  Constant: '<S224>/Constant'
     */
    rtb_MultiportSwitch = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S224>/Multiport Switch' incorporates:
     *  Constant: '<S224>/Constant1'
     */
    rtb_MultiportSwitch = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S224>/Multiport Switch' incorporates:
     *  Constant: '<S224>/Constant2'
     */
    rtb_MultiportSwitch = 4U;
    break;

   case 3:
    /* MultiPortSwitch: '<S224>/Multiport Switch' incorporates:
     *  Constant: '<S224>/Constant3'
     */
    rtb_MultiportSwitch = 1U;
    break;

   case 4:
    /* MultiPortSwitch: '<S224>/Multiport Switch' incorporates:
     *  Constant: '<S224>/Constant4'
     */
    rtb_MultiportSwitch = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S224>/Multiport Switch' incorporates:
     *  UnitDelay: '<S224>/Unit Delay'
     */
    rtb_MultiportSwitch = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ez;
    break;
  }

  /* End of MultiPortSwitch: '<S224>/Multiport Switch' */

  /* Switch: '<S225>/Switch' incorporates:
   *  Constant: '<S225>/Constant'
   *  Constant: '<S225>/Constant2'
   *  Switch: '<S225>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLaneLSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLaneRSw) {
    /* Switch: '<S225>/Switch1' incorporates:
     *  Constant: '<S225>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnngLiSwSig = 2U;
  }

  /* End of Switch: '<S225>/Switch' */

  /* Switch: '<S236>/Switch' incorporates:
   *  Constant: '<S236>/Constant2'
   *  Logic: '<S236>/Logical Operator'
   *  Switch: '<S236>/Switch1'
   *  Switch: '<S236>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2.PosLampSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.LowBeamSw ||
             AppSwcBcm_ARID_DEF.UnitDelay2.HiBeamSw) {
    /* Switch: '<S236>/Switch1' incorporates:
     *  Constant: '<S236>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.AutoLampSw) {
    /* Switch: '<S236>/Switch2' incorporates:
     *  Constant: '<S236>/Constant'
     *  Switch: '<S236>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 3U;
  } else {
    /* Switch: '<S236>/Switch1' incorporates:
     *  Constant: '<S236>/Constant3'
     *  Switch: '<S236>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightSwSig = 0U;
  }

  /* End of Switch: '<S236>/Switch' */

  /* Switch: '<S237>/Switch' incorporates:
   *  Constant: '<S237>/Constant2'
   *  Switch: '<S237>/Switch1'
   *  Switch: '<S237>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2.LowBeamSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.HiBeamSw) {
    /* Switch: '<S237>/Switch1' incorporates:
     *  Constant: '<S237>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.PassLightSw) {
    /* Switch: '<S237>/Switch2' incorporates:
     *  Constant: '<S237>/Constant'
     *  Switch: '<S237>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 2U;
  } else {
    /* Switch: '<S237>/Switch1' incorporates:
     *  Constant: '<S237>/Constant3'
     *  Switch: '<S237>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HighBeamSwSig = 3U;
  }

  /* End of Switch: '<S237>/Switch' */

  /* RelationalOperator: '<S238>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator7'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->HoodAjarSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion19' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Hood =
    rtb_RelationalOperator;

  /* DataTypeConversion: '<S217>/Data Type Conversion20' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_HazardWarningLightSwSig =
    AppSwcBcm_ARID_DEF.UnitDelay2.HazardLightSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion21' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntFogLiSwSig =
    AppSwcBcm_ARID_DEF.UnitDelay2.FogLampFSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion22' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearFogLiSwSig =
    AppSwcBcm_ARID_DEF.UnitDelay2.FogLampRSw;

  /* Switch: '<S238>/Switch' incorporates:
   *  Constant: '<S238>/Constant2'
   *  Constant: '<S238>/Constant4'
   *  Logic: '<S238>/Logical Operator'
   *  RelationalOperator: '<S238>/Relational Operator'
   *  RelationalOperator: '<S238>/Relational Operator1'
   *  Switch: '<S238>/Switch1'
   *  Switch: '<S238>/Switch2'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay1_h.AntiLckSta == 1) ||
      (AppSwcBcm_ARID_DEF.UnitDelay1_h.PartArmedSta == 1)) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay1_h.ArmedSta != 0) {
    /* Switch: '<S238>/Switch1' incorporates:
     *  Constant: '<S238>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 3U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay1_h.SeekSta != 0) {
    /* Switch: '<S238>/Switch2' incorporates:
     *  Constant: '<S238>/Constant'
     *  Switch: '<S238>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 4U;
  } else {
    /* Switch: '<S238>/Switch1' incorporates:
     *  Constant: '<S238>/Constant3'
     *  Switch: '<S238>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BassHornReq = 0U;
  }

  /* End of Switch: '<S238>/Switch' */

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator6'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->TrunkAjarSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion25' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarSta_Trunk =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator2'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarFLSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion26' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator3'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarFRSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion27' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator4'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarRLSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion28' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator5'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarRRSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion29' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorAjarSta_RR =
    rtb_RelationalOperator;

  /* MultiPortSwitch: '<S239>/Multiport Switch' */
  switch (AppSwcBcm_ARID_DEF.UnitDelay3.WiperSta) {
   case 0:
    /* MultiPortSwitch: '<S239>/Multiport Switch' incorporates:
     *  Constant: '<S239>/Constant'
     */
    rtb_MultiportSwitch_m = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S239>/Multiport Switch' incorporates:
     *  Constant: '<S239>/Constant1'
     */
    rtb_MultiportSwitch_m = 3U;
    break;

   case 2:
    /* MultiPortSwitch: '<S239>/Multiport Switch' incorporates:
     *  Constant: '<S239>/Constant2'
     */
    rtb_MultiportSwitch_m = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S239>/Multiport Switch' incorporates:
     *  Constant: '<S239>/Constant3'
     */
    rtb_MultiportSwitch_m = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S239>/Multiport Switch' incorporates:
     *  Constant: '<S239>/Constant4'
     */
    rtb_MultiportSwitch_m = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S239>/Multiport Switch' incorporates:
     *  UnitDelay: '<S239>/Unit Delay'
     */
    rtb_MultiportSwitch_m = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f;
    break;
  }

  /* End of MultiPortSwitch: '<S239>/Multiport Switch' */

  /* MultiPortSwitch: '<S240>/Multiport Switch' incorporates:
   *  Constant: '<S240>/Constant'
   *  Constant: '<S240>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (!(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvSeatSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 1U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvSeatOccupantSensorSts = 2U;
  }

  /* End of MultiPortSwitch: '<S240>/Multiport Switch' */

  /* DataTypeConversion: '<S217>/Data Type Conversion41' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntWshrSwSig =
    AppSwcBcm_ARID_DEF.UnitDelay3.WashSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion42' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWashSts =
    AppSwcBcm_ARID_DEF.UnitDelay3.WashMotorDrv;

  /* Switch: '<S241>/Switch' incorporates:
   *  Constant: '<S241>/Constant2'
   *  Switch: '<S241>/Switch1'
   *  Switch: '<S241>/Switch2'
   *  Switch: '<S241>/Switch3'
   *  Switch: '<S241>/Switch4'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay3.WiperOffSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 0U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay3.WiperLowSpdSw) {
    /* Switch: '<S241>/Switch1' incorporates:
     *  Constant: '<S241>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay3.WiperHiSpdSw) {
    /* Switch: '<S241>/Switch2' incorporates:
     *  Constant: '<S241>/Constant'
     *  Switch: '<S241>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 2U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay3.WiperMistSw) {
    /* Switch: '<S241>/Switch3' incorporates:
     *  Constant: '<S241>/Constant3'
     *  Switch: '<S241>/Switch1'
     *  Switch: '<S241>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay3.WiperInrSw) {
    /* Switch: '<S241>/Switch4' incorporates:
     *  Constant: '<S241>/Constant4'
     *  Switch: '<S241>/Switch1'
     *  Switch: '<S241>/Switch2'
     *  Switch: '<S241>/Switch3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 4U;
  } else {
    /* Switch: '<S241>/Switch2' incorporates:
     *  Constant: '<S241>/Constant5'
     *  Switch: '<S241>/Switch1'
     *  Switch: '<S241>/Switch3'
     *  Switch: '<S241>/Switch4'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperSwSig = 6U;
  }

  /* End of Switch: '<S241>/Switch' */

  /* Switch: '<S242>/Switch' incorporates:
   *  Constant: '<S242>/Constant2'
   *  Switch: '<S242>/Switch1'
   *  Switch: '<S242>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvWinUpSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvWinDnSw) {
    /* Switch: '<S242>/Switch1' incorporates:
     *  Constant: '<S242>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvWinAutoDnSw) {
    /* Switch: '<S242>/Switch2' incorporates:
     *  Constant: '<S242>/Constant'
     *  Switch: '<S242>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 4U;
  } else {
    /* Switch: '<S242>/Switch1' incorporates:
     *  Constant: '<S242>/Constant3'
     *  Switch: '<S242>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DriverWinSwSig = 0U;
  }

  /* End of Switch: '<S242>/Switch' */

  /* Switch: '<S243>/Switch' incorporates:
   *  Constant: '<S243>/Constant2'
   *  Logic: '<S243>/Logical Operator'
   *  Logic: '<S243>/Logical Operator1'
   *  Logic: '<S243>/Logical Operator2'
   *  Switch: '<S243>/Switch1'
   *  Switch: '<S243>/Switch2'
   */
  if (AppSwcBcm_ARID_DEF.WinCtl_Bus.PsgWinUpSw ||
      AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvPsgWinUpSw) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 1U;
  } else if (AppSwcBcm_ARID_DEF.WinCtl_Bus.PsgWinDnSw ||
             AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvPsgWinDnSw) {
    /* Switch: '<S243>/Switch1' incorporates:
     *  Constant: '<S243>/Constant1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 3U;
  } else if (AppSwcBcm_ARID_DEF.WinCtl_Bus.PsgWinAutoDnSw ||
             AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvPsgWinAutoDnSw) {
    /* Switch: '<S243>/Switch2' incorporates:
     *  Constant: '<S243>/Constant'
     *  Switch: '<S243>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 4U;
  } else {
    /* Switch: '<S243>/Switch1' incorporates:
     *  Constant: '<S243>/Constant3'
     *  Switch: '<S243>/Switch2'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PassWinSwSig = 0U;
  }

  /* End of Switch: '<S243>/Switch' */

  /* Switch: '<S226>/Switch1' incorporates:
   *  Constant: '<S226>/Constant1'
   *  Logic: '<S226>/Logical Operator'
   *  Switch: '<S226>/Switch'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay3.HiSpdDrv &&
      AppSwcBcm_ARID_DEF.UnitDelay3.LowSpdDrv) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrontWiperMotorSts =
      AppSwcBcm_ARID_DEF.UnitDelay3.LowSpdDrv;
  }

  /* End of Switch: '<S226>/Switch1' */

  /* DataTypeConversion: '<S217>/Data Type Conversion52' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntLeDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DrvPESw;

  /* DataTypeConversion: '<S217>/Data Type Conversion53' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrntRiDoorHndlSwt =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->PsgPESw;

  /* DataTypeConversion: '<S217>/Data Type Conversion54' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkSwtSig =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion98' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnNoKeyFound =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnNoKeyFound;

  /* DataTypeConversion: '<S217>/Data Type Conversion55' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BodyWarnSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;

  /* DataTypeConversion: '<S217>/Data Type Conversion97' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSAuthentRes =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSAuthentRes;

  /* DataTypeConversion: '<S217>/Data Type Conversion95' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyInCarSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyInCarSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion94' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DrvPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->DrvPEAuthentAcsd;

  /* DataTypeConversion: '<S217>/Data Type Conversion72' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRPEAuthentAcsd =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FRPEAuthentAcsd;

  /* DataTypeConversion: '<S217>/Data Type Conversion71' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_PSReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->PSReq;

  /* DataTypeConversion: '<S217>/Data Type Conversion57' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* DataTypeConversion: '<S217>/Data Type Conversion58' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChgWiperMtMdSwSetFb =
    AppSwcBcm_ARID_DEF.UnitDelay3.WiperMaintSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion59' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ParkAutoUnlockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;

  /* DataTypeConversion: '<S217>/Data Type Conversion60' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_OverspdCntrlLockSetFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->SpdCtlLckSetFb;

  /* DataTypeConversion: '<S217>/Data Type Conversion61' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TrunkLockSta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkLckSw;

  /* DataTypeConversion: '<S217>/Data Type Conversion37' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FrbdnKeyNr =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->FrbdnKeyNr;

  /* DataTypeConversion: '<S217>/Data Type Conversion101' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AvaluebleKeyInCar =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->AvaluebleKeyInCar;

  /* DataTypeConversion: '<S217>/Data Type Conversion104' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeyLoBattLvlWarn =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeyLoBattLvlWarn;

  /* DataTypeConversion: '<S217>/Data Type Conversion70' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_KeySta =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->KeySta;

  /* Chart: '<S227>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S227>/Constant'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(AppSwcBcm_ARID_DEF.UnitDelay2.WelcomeLampSta, 25,
    &AppSwcBcm_ARID_DEF.LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_o);

  /* DataTypeConversion: '<S217>/Data Type Conversion64' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLampReq =
    AppSwcBcm_ARID_DEF.LIB_blOut_c;

  /* Chart: '<S228>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S228>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeUnlck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_ob,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_e);

  /* Chart: '<S228>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S228>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->WelcomeLck, 25, &AppSwcBcm_ARID_DEF.LIB_blOut_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1_j);

  /* Switch: '<S228>/Switch' incorporates:
   *  Constant: '<S228>/Constant2'
   *  Constant: '<S228>/Constant4'
   *  Switch: '<S228>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_ob) {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 1U;
  } else if (AppSwcBcm_ARID_DEF.LIB_blOut_d) {
    /* Switch: '<S228>/Switch1' incorporates:
     *  Constant: '<S228>/Constant3'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 2U;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockReq = 0U;
  }

  /* End of Switch: '<S228>/Switch' */

  /* DataTypeConversion: '<S217>/Data Type Conversion106' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WarnKeyOutReminder =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->WarnKeyOutReminder;

  /* DataTypeConversion: '<S217>/Data Type Conversion107' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IndicationKeyCloser =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PEPSCtl_Bus())->IndicationKeyCloser;

  /* DataTypeConversion: '<S217>/Data Type Conversion110' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SteerWhlTemp = (uint8)
    AppSwcBcm_ARID_DEF.SteerWhlCtl_Bus.SteerWhlTemp;

  /* DataTypeConversion: '<S217>/Data Type Conversion66' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_MaiDrvrSeatTemp = (uint8)
    AppSwcBcm_ARID_DEF.SeatCtl_Bus.DrvSeatTemp;

  /* DataTypeConversion: '<S217>/Data Type Conversion67' */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RearMirrorHeatSts =
    AppSwcBcm_ARID_DEF.RVMCtl_Bus.J42Heat;

  /* DataTypeConversion: '<S217>/Data Type Conversion82' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion11'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_BrakePedalSta =
    AppSwcBcm_ARID_DEF.UnitDelay2.BrakeLightSta;

  /* BusCreator: '<S217>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S217>/Data Type Conversion143'
   *  DataTypeConversion: '<S217>/Data Type Conversion83'
   *  DataTypeConversion: '<S217>/Data Type Conversion84'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;

  /* Switch: '<S231>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S231>/Constant2'
     *  DataTypeConversion: '<S217>/Data Type Conversion142'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 2U;
  } else {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S231>/Constant3'
     *  DataTypeConversion: '<S217>/Data Type Conversion142'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_CentralLockSts = 1U;
  }

  /* End of Switch: '<S231>/Switch' */

  /* BusCreator: '<S217>/Bus Creator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S217>/Data Type Conversion135'
   *  DataTypeConversion: '<S217>/Data Type Conversion136'
   *  DataTypeConversion: '<S217>/Data Type Conversion77'
   *  DataTypeConversion: '<S217>/Data Type Conversion78'
   *  DataTypeConversion: '<S217>/Data Type Conversion79'
   *  DataTypeConversion: '<S217>/Data Type Conversion80'
   *  DataTypeConversion: '<S217>/Data Type Conversion85'
   *  DataTypeConversion: '<S217>/Data Type Conversion86'
   * */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DoorLockSta_FL =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndLockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndLckStsFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_IllmndUnlockStsFb =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndUnlockStsFb;

  /* Switch: '<S233>/Switch' incorporates:
   *  Switch: '<S233>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2.FlwrMeHomeSta) {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S233>/Constant'
     *  DataTypeConversion: '<S217>/Data Type Conversion76'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.WelcomeLampSta) {
    /* Switch: '<S233>/Switch1' incorporates:
     *  BusCreator: '<S217>/Bus Creator1'
     *  Constant: '<S233>/Constant1'
     *  DataTypeConversion: '<S217>/Data Type Conversion76'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 2U;
  } else {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S233>/Constant2'
     *  DataTypeConversion: '<S217>/Data Type Conversion76'
     *  Switch: '<S233>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LogoActiveFlag = 0U;
  }

  /* End of Switch: '<S233>/Switch' */

  /* Switch: '<S234>/Switch' incorporates:
   *  Switch: '<S234>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrRShort) {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S234>/Constant'
     *  DataTypeConversion: '<S217>/Data Type Conversion74'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrROpen) {
    /* Switch: '<S234>/Switch1' incorporates:
     *  BusCreator: '<S217>/Bus Creator1'
     *  Constant: '<S234>/Constant1'
     *  DataTypeConversion: '<S217>/Data Type Conversion74'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 2U;
  } else {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S234>/Constant2'
     *  DataTypeConversion: '<S217>/Data Type Conversion74'
     *  Switch: '<S234>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RiTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S234>/Switch' */

  /* Switch: '<S235>/Switch' incorporates:
   *  Switch: '<S235>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLShort) {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S235>/Constant'
     *  DataTypeConversion: '<S217>/Data Type Conversion73'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 1U;
  } else if (AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLOpen) {
    /* Switch: '<S235>/Switch1' incorporates:
     *  BusCreator: '<S217>/Bus Creator1'
     *  Constant: '<S235>/Constant1'
     *  DataTypeConversion: '<S217>/Data Type Conversion73'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 2U;
  } else {
    /* BusCreator: '<S217>/Bus Creator1' incorporates:
     *  Constant: '<S235>/Constant2'
     *  DataTypeConversion: '<S217>/Data Type Conversion73'
     *  Switch: '<S235>/Switch1'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LeTurnLiFaultFb = 0U;
  }

  /* End of Switch: '<S235>/Switch' */

  /* BusCreator: '<S217>/Bus Creator1' incorporates:
   *  Constant: '<S217>/Constant1'
   *  Constant: '<S217>/Constant10'
   *  Constant: '<S217>/Constant12'
   *  Constant: '<S217>/Constant16'
   *  Constant: '<S217>/Constant17'
   *  Constant: '<S217>/Constant18'
   *  Constant: '<S217>/Constant19'
   *  Constant: '<S217>/Constant2'
   *  Constant: '<S217>/Constant20'
   *  Constant: '<S217>/Constant21'
   *  Constant: '<S217>/Constant23'
   *  Constant: '<S217>/Constant24'
   *  Constant: '<S217>/Constant26'
   *  Constant: '<S217>/Constant29'
   *  Constant: '<S217>/Constant3'
   *  Constant: '<S217>/Constant32'
   *  Constant: '<S217>/Constant33'
   *  Constant: '<S217>/Constant34'
   *  Constant: '<S217>/Constant35'
   *  Constant: '<S217>/Constant36'
   *  Constant: '<S217>/Constant37'
   *  Constant: '<S217>/Constant38'
   *  Constant: '<S217>/Constant39'
   *  Constant: '<S217>/Constant40'
   *  Constant: '<S217>/Constant41'
   *  Constant: '<S217>/Constant42'
   *  Constant: '<S217>/Constant43'
   *  Constant: '<S217>/Constant44'
   *  Constant: '<S217>/Constant45'
   *  Constant: '<S217>/Constant46'
   *  Constant: '<S217>/Constant47'
   *  Constant: '<S217>/Constant5'
   *  Constant: '<S217>/Constant6'
   *  Constant: '<S217>/Constant7'
   *  Constant: '<S217>/Constant8'
   *  DataTypeConversion: '<S217>/Data Type Conversion138'
   */
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_DayRunLiSwSig = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_TurnLiSts = rtb_MultiportSwitch;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LightIntensity =
    AppSwcBcm_ARID_DEF.UnitDelay2.LightIntstSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AjarStaV_Hood = 1U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FlwrMeHmCtrlFb =
    AppSwcBcm_ARID_DEF.UnitDelay2.FlwrMeHomeCtlFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_LockHornOnStFb =
    AppSwcBcm_ARID_DEF.UnitDelay1_h.LockHoornOnStFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_AlrmHornReq =
    AppSwcBcm_ARID_DEF.UnitDelay1_h.AlarmSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiperCtrl_Front =
    rtb_MultiportSwitch_m;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WashLiquidLevelWarn =
    AppSwcBcm_ConstB.BCM_WashLiquidLevelWarn;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiprIntlGearSwtSig =
    AppSwcBcm_ARID_DEF.UnitDelay3.WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WinLockSig = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowSts = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FLWindowmotorSts =
    AppSwcBcm_ARID_DEF.WinCtl_Bus.DrvWinSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_FRWindowmotorSts =
    AppSwcBcm_ARID_DEF.WinCtl_Bus.PsgWinSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_ChrgLidLockReq = 0U;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RKEReq =
    AppSwcBcm_ARID_DEF.UnitDelay2.RKEReq;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_WiprIntlTimeSetFb =
    AppSwcBcm_ARID_DEF.UnitDelay3.WiprIntlTimeSetFb;
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
    AppSwcBcm_ARID_DEF.UnitDelay2.BackLadjvalFb;
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
    AppSwcBcm_ARID_DEF.UnitDelay2.VehSeekSta;
  AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m.BCM_RFInitSta = 0U;

  /* BusCreator: '<S217>/Bus Creator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  DataTypeConversion: '<S217>/Data Type Conversion73'
   *  DataTypeConversion: '<S217>/Data Type Conversion74'
   *  DataTypeConversion: '<S217>/Data Type Conversion75'
   *  DataTypeConversion: '<S217>/Data Type Conversion76'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrMode =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPwrModeV =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrModeV;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SysPowerSts =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPowerSts;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_StartReq =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->StartReq;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarFLSw;

  /* BusCreator: '<S217>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion77'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FL =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator8'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarFRSw;

  /* BusCreator: '<S217>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion78'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_FR =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator9'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarRLSw;

  /* BusCreator: '<S217>/Bus Creator2' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion79'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAjarSta_RL =
    rtb_RelationalOperator;

  /* Logic: '<S217>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S217>/Logical Operator10'
   */
  rtb_RelationalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->DoorAjarRRSw;

  /* BusCreator: '<S217>/Bus Creator2' incorporates:
   *  Constant: '<S217>/Constant'
   *  DataTypeConversion: '<S217>/Data Type Conversion142'
   *  DataTypeConversion: '<S217>/Data Type Conversion143'
   *  DataTypeConversion: '<S217>/Data Type Conversion80'
   */
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_DoorAiarSta_RR =
    rtb_RelationalOperator;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.AppSwcBcmVersion = 14U;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_NMReq_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.NMReq;
  AppSwcBcm_ARID_DEF.Bcm2VcuTms_outputs_c.BCM_SleepAllwd_flg =
    AppSwcBcm_ARID_DEF.WakeUpCtl_Bus.SleepAllwd;

  /* Switch: '<S229>/Switch' incorporates:
   *  Constant: '<S229>/Constant'
   *  Constant: '<S229>/Constant1'
   *  Constant: '<S229>/Constant2'
   *  Constant: '<S229>/Constant4'
   *  RelationalOperator: '<S229>/Relational Operator'
   *  RelationalOperator: '<S229>/Relational Operator1'
   *  Switch: '<S229>/Switch1'
   */
  if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 1) {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      282574488338432ULL;
  } else if (AppSwcBcm_ARID_DEF.ESCLCtl_Bus.UnOrLockCrtl == 2) {
    /* Switch: '<S229>/Switch1' incorporates:
     *  Constant: '<S229>/Constant3'
     *  Switch: '<S229>/Switch'
     */
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl =
      564049465049088ULL;
  } else {
    AppSwcBcm_ARID_DEF.Bcm2OpmOBD_outputs_k.ESCL_UnOrLockCrtl = 0ULL;
  }

  /* End of Switch: '<S229>/Switch' */

  /* Chart: '<S230>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S230>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HULck, 25, &rtb_RelationalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_a);

  /* Chart: '<S230>/Lib_RiseEdgeDelay1' incorporates:
   *  Constant: '<S230>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_Lib_RiseEdgeDelay((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->HUUnlck, 25, &rtb_RelationalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay1);

  /* DataTypeConversion: '<S217>/Data Type Conversion89' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiLeLightReq_b =
    AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion90' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion3'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_PosLightReq_p =
    AppSwcBcm_ARID_DEF.UnitDelay2.PosLampSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion91' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion9'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_DrlLightReq_c =
    AppSwcBcm_ARID_DEF.UnitDelay2.DayRunLightSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion92' incorporates:
   *  DataTypeConversion: '<S217>/Data Type Conversion1'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiRiLightReq_f =
    AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrRSta;

  /* DataTypeConversion: '<S217>/Data Type Conversion93' incorporates:
   *  Logic: '<S217>/Logical Operator1'
   */
  AppSwcBcm_ARID_DEF.Sig_Cmd_TiWngFBSt_g = (uint8)
    (AppSwcBcm_ARID_DEF.UnitDelay2.EmerSta ||
     AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrLOpen ||
     AppSwcBcm_ARID_DEF.UnitDelay2.TurnIndcrROpen);

  /* BusCreator: '<S217>/Bus Creator' */
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

  /* Outputs for Atomic SubSystem: '<S217>/HwOutBCM' */
  AppSwcBcm_HwOutBCM();

  /* End of Outputs for SubSystem: '<S217>/HwOutBCM' */

  /* Update for UnitDelay: '<S224>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ez = rtb_MultiportSwitch;

  /* Update for UnitDelay: '<S239>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_f = rtb_MultiportSwitch_m;
}

/* Output and update for atomic system: '<S3>/EEReadCtl' */
static void AppSwcBcm_EEReadCtl(void)
{
  /* Chart: '<S218>/EEReadCtl' */
  NvmBCmBlock_Imm_ReadData((uint8 *)&AppSwcBcm_ARID_DEF.data1_b[0], 9U);
  EEReadCtl_CrashSta = AppSwcBcm_ARID_DEF.data1_b[0];
  EEReadCtl_BodyWarnSts = AppSwcBcm_ARID_DEF.data1_b[1];
  EEReadCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.data1_b[2];
  EEReadCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.data1_b[3];
  EEReadCtl_HazardLightSta = AppSwcBcm_ARID_DEF.data1_b[4];
  EEReadCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.data1_b[5];
  EEReadCtl_IllmndUnlckSts = AppSwcBcm_ARID_DEF.data1_b[6];
  EEReadCtl_SpdCtlLckSet = AppSwcBcm_ARID_DEF.data1_b[7];
  EEReadCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.data1_b[8];
  EEReadCtl_LockHoornOnSts = AppSwcBcm_ARID_DEF.data1_b[9];
  EEReadCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.data1_b[10];
  EEReadCtl_InrTim = AppSwcBcm_ARID_DEF.data1_b[11];
}

/* Output and update for atomic system: '<S3>/EEWriteCtl' */
static void AppSwcBcm_EEWriteCtl(void)
{
  uint16 tmp;

  /* Chart: '<S219>/EEWriteCtl' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   * */
  if (EEWriteCtl_ImmOvrdFlg_C) {
    NvmBcmBlock_Imm_WriteData((uint8 *)(const uint8 *)&EEWriteCtl_ImmOvrdVal_C[0],
      10U);
  } else {
    AppSwcBcm_ARID_DEF.data1[0] = AppSwcBcm_ARID_DEF.UnitDelay2.CrashSta;
    AppSwcBcm_ARID_DEF.data1[1] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;
    AppSwcBcm_ARID_DEF.data1[2] = AppSwcBcm_ARID_DEF.UnitDelay2.FlwrMeHomeCtlFb;
    AppSwcBcm_ARID_DEF.data1[3] = AppSwcBcm_ARID_DEF.UnitDelay2.BackLadjvalFb;
    AppSwcBcm_ARID_DEF.data1[4] = AppSwcBcm_ARID_DEF.UnitDelay2.HazardLightSta;
    AppSwcBcm_ARID_DEF.data1[5] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndLckSts;
    AppSwcBcm_ARID_DEF.data1[6] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->IllmndUnlockSts;
    AppSwcBcm_ARID_DEF.data1[7] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->SpdCtlLckSet;
    AppSwcBcm_ARID_DEF.data1[8] =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->ParkAutoUnlockSetFb;
    AppSwcBcm_ARID_DEF.data1[9] = AppSwcBcm_ARID_DEF.UnitDelay1_h.LockHoornOnSt;
    AppSwcBcm_ARID_DEF.data1[10] =
      AppSwcBcm_ARID_DEF.UnitDelay3.WiprIntlTimeSetFb;
    tmp = AppSwcBcm_ARID_DEF.UnitDelay3.InrTim;
    if (AppSwcBcm_ARID_DEF.UnitDelay3.InrTim > 255) {
      tmp = 255U;
    }

    AppSwcBcm_ARID_DEF.data1[11] = (uint8)tmp;

    /* NvmBcmBlock02WriteData(data,8); */
    NvmBcmBlock_Imm_WriteData((uint8 *)&AppSwcBcm_ARID_DEF.data1[0], 12U);
  }

  /* End of Chart: '<S219>/EEWriteCtl' */
}

/*
 * Output and update for function-call system:
 *    '<S267>/Lib_EdgeChgDet'
 *    '<S431>/Pri5.AntiLckFunc.Lib_EdgeChgDet'
 *    '<S431>/Pri5.SeekFunc.Lib_EdgeChgDet'
 *    '<S431>/Pri5.ArmedFunc.Lib_EdgeChgDet'
 *    '<S431>/Pri5.PartArmedFunc.Lib_EdgeChgDet'
 *    '<S431>/Pri5.DisarmedFunc.Lib_EdgeChgDet'
 *    '<S511>/Lib_EdgeChgDet'
 */
static void AppSwcBcm_Lib_EdgeChgDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_EdgeChgDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S285>/Lib_EdgeChgDet' */
  /* RelationalOperator: '<S286>/Relational Operator' incorporates:
   *  UnitDelay: '<S286>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn != AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S286>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;

  /* End of Outputs for SubSystem: '<S285>/Lib_EdgeChgDet' */
}

/*
 * System initialize for atomic system:
 *    '<S294>/Lib_RiseEdgeDetInit'
 *    '<S440>/Lib_RiseEdgeDetInit'
 *    '<S444>/Lib_RiseEdgeDetInit'
 *    '<S447>/Lib_RiseEdgeDetInit'
 *    '<S448>/Lib_RiseEdgeDetInit'
 *    '<S458>/Lib_RiseEdgeDetInit'
 *    '<S473>/Lib_RiseEdgeDetInit'
 *    '<S482>/Lib_RiseEdgeDetInit'
 *    '<S515>/Lib_RiseEdgeDetInit'
 *    '<S516>/Lib_RiseEdgeDetInit'
 *    '<S517>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_l_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S295>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S294>/Lib_RiseEdgeDetInit'
 *    '<S440>/Lib_RiseEdgeDetInit'
 *    '<S444>/Lib_RiseEdgeDetInit'
 *    '<S447>/Lib_RiseEdgeDetInit'
 *    '<S448>/Lib_RiseEdgeDetInit'
 *    '<S458>/Lib_RiseEdgeDetInit'
 *    '<S473>/Lib_RiseEdgeDetInit'
 *    '<S482>/Lib_RiseEdgeDetInit'
 *    '<S515>/Lib_RiseEdgeDetInit'
 *    '<S516>/Lib_RiseEdgeDetInit'
 *    '<S517>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_l_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S295>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S295>/Logical Operator' incorporates:
   *  Delay: '<S295>/Delay'
   *  Logic: '<S295>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S295>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for function-call system:
 *    '<S293>/Lib_RiseEdgeDetInit'
 *    '<S439>/Lib_RiseEdgeDetInit'
 *    '<S443>/Lib_RiseEdgeDetInit'
 *    '<S457>/Lib_RiseEdgeDetInit'
 *    '<S472>/Lib_RiseEdgeDetInit'
 *    '<S481>/Lib_RiseEdgeDetInit'
 *    '<S514>/Lib_RiseEdgeDetInit'
 *    '<S514>/Lib_RiseEdgeDetInit1'
 *    '<S514>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S293>/Lib_RiseEdgeDetInit'
 *    '<S439>/Lib_RiseEdgeDetInit'
 *    '<S443>/Lib_RiseEdgeDetInit'
 *    '<S457>/Lib_RiseEdgeDetInit'
 *    '<S472>/Lib_RiseEdgeDetInit'
 *    '<S481>/Lib_RiseEdgeDetInit'
 *    '<S514>/Lib_RiseEdgeDetInit'
 *    '<S514>/Lib_RiseEdgeDetInit1'
 *    '<S514>/Lib_RiseEdgeDetInit2'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_k(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S294>/Lib_RiseEdgeDetInit' */
}

/* System initialize for atomic system: '<S3>/HornCtl' */
static void AppSwcBcm_HornCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S265>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = true;

  /* SystemInitialize for Chart: '<S271>/Chart' incorporates:
   *  SubSystem: '<S293>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
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

  /* Chart: '<S266>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S266>/Constant'
   *  Constant: '<S266>/Constant37'
   *  Constant: '<S266>/Constant38'
   *  Constant: '<S266>/Constant39'
   *  RelationalOperator: '<S266>/Relational Operator'
   */
  if (BSW_J319HornSw == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_km >= (float32)HornCtl_HornSwTimValid_C /
         (HornCtl_Ts_C * 100.0F)) && (HornCtl_HornSwTimValid_C != 0xFFFF)) {
      HornCtl_HornSwCtl = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_km++;
      AppSwcBcm_ARID_DEF.cnt_heal_k3 = (uint16)((float32)
        HornCtl_HornSwTimInvalid_C / (HornCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_km = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k3 == 0) {
      HornCtl_HornSwCtl = false;
    } else if (HornCtl_HornSwTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k3--;
    }
  }

  /* End of Chart: '<S266>/LIB_TPD_10ms' */

  /* Chart: '<S262>/Alarm' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AlarmSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AlarmSta = 1U;
    AppSwcBcm_ARID_DEF.Lib_blIn_fn =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 2);

    /* Outputs for Function Call SubSystem: '<S273>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fn,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lz,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p4);

    /* End of Outputs for SubSystem: '<S273>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_lz || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AlarmSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AlarmSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_fn =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S273>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fn,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lz,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p4);

    /* End of Outputs for SubSystem: '<S273>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_lz) {
      AppSwcBcm_ARID_DEF.is_c3_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_AlarmSta = 1U;
    }
  }

  /* End of Chart: '<S262>/Alarm' */

  /* RelationalOperator: '<S265>/Relational Operator' incorporates:
   *  Constant: '<S265>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S265>/Relational Operator1'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S265>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_i) {
    /* Switch: '<S265>/Switch' incorporates:
     *  Constant: '<S265>/Constant'
     *  Constant: '<S265>/Constant5'
     *  RelationalOperator: '<S265>/Relational Operator'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_m = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_m =
        AppSwcBcm_ARID_DEF.BusCreator12.LockHoornOnSts;
    }

    /* End of Switch: '<S265>/Switch' */
  }

  /* Switch: '<S265>/Switch1' incorporates:
   *  Constant: '<S265>/Constant7'
   */
  if (rtb_RelationalOperator) {
    rtb_HornCtl_Sta = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HULckHornOnSt_enum;
  } else {
    rtb_HornCtl_Sta = 0U;
  }

  /* MultiPortSwitch: '<S265>/Multiport Switch' incorporates:
   *  Switch: '<S265>/Switch1'
   */
  switch (rtb_HornCtl_Sta) {
   case 1:
    /* MultiPortSwitch: '<S265>/Multiport Switch' incorporates:
     *  Constant: '<S265>/Constant1'
     */
    HornCtl_LockHoornOnSt = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S265>/Multiport Switch' incorporates:
     *  Constant: '<S265>/Constant2'
     */
    HornCtl_LockHoornOnSt = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S265>/Multiport Switch' incorporates:
     *  Delay: '<S265>/Delay'
     */
    HornCtl_LockHoornOnSt = AppSwcBcm_ARID_DEF.Delay_DSTATE_m;
    break;
  }

  /* End of MultiPortSwitch: '<S265>/Multiport Switch' */

  /* MultiPortSwitch: '<S265>/Multiport Switch1' */
  switch (HornCtl_LockHoornOnSt) {
   case 1:
    /* MultiPortSwitch: '<S265>/Multiport Switch1' incorporates:
     *  Constant: '<S265>/Constant3'
     */
    HornCtl_LockHoornOnStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S265>/Multiport Switch1' incorporates:
     *  Constant: '<S265>/Constant4'
     */
    HornCtl_LockHoornOnStFb = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S265>/Multiport Switch1' */

  /* Chart: '<S263>/AntiLck' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S220>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c155_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_AntiLckSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_AntiLckSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g >= 3) || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c155_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_AntiLckSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_AntiLckSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_ab =
      (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck;

    /* Outputs for Function Call SubSystem: '<S276>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ab,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ey,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_pxv);

    /* End of Outputs for SubSystem: '<S276>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ey) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_k5 =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck;

      /* Outputs for Function Call SubSystem: '<S276>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_k5,
        &AppSwcBcm_ARID_DEF.LogicalOperator_fo,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_p);

      /* End of Outputs for SubSystem: '<S276>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_fo) {
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

  /* End of Chart: '<S263>/AntiLck' */

  /* Chart: '<S264>/Armed' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S220>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c99_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_ArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_ArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g >= 1) ||
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 1) ||
        HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_ArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_ArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_ks =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S281>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ks,
      &AppSwcBcm_ARID_DEF.LogicalOperator_mw,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_k);

    /* End of Outputs for SubSystem: '<S281>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_mw && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c99_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_ArmedSta = 1U;
    }
  }

  /* End of Chart: '<S264>/Armed' */

  /* Chart: '<S269>/PartArmed' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S220>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c102_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_PartArmedSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_PartArmedSta = 1U;
    if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g >= 3) ||
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 3) ||
        HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_PartArmedSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_PartArmedSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_ia =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 3);

    /* Outputs for Function Call SubSystem: '<S287>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ia,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fz,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h3);

    /* End of Outputs for SubSystem: '<S287>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_fz && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c102_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_PartArmedSta = 1U;
    }
  }

  /* End of Chart: '<S269>/PartArmed' */

  /* Chart: '<S270>/Seek' incorporates:
   *  UnitDelay: '<S220>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c153_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_SeekSta = 0U;
  } else if (AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib == AppSwcBcm_IN_SetON) {
    HornCtl_SeekSta = 1U;
    if ((!AppSwcBcm_ARID_DEF.UnitDelay2.VehSeekSta) ||
        (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g >= 1) || HornCtl_HornSwCtl) {
      AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetOff;
      HornCtl_SeekSta = 0U;
    }
  } else {
    /* case IN_SetOff: */
    HornCtl_SeekSta = 0U;
    AppSwcBcm_ARID_DEF.Lib_blIn_hd = AppSwcBcm_ARID_DEF.UnitDelay2.VehSeekSta;

    /* Outputs for Function Call SubSystem: '<S290>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_hd,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ie,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_mc);

    /* End of Outputs for SubSystem: '<S290>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ie && (HornCtl_LockHoornOnStFb == 1))
    {
      AppSwcBcm_ARID_DEF.is_c153_HornCtl_Lib = AppSwcBcm_IN_SetON;
      HornCtl_SeekSta = 1U;
    }
  }

  /* End of Chart: '<S270>/Seek' */

  /* Chart: '<S271>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S220>/Unit Delay15'
   * */
  if (AppSwcBcm_ARID_DEF.is_active_c55_HornCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c55_HornCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
    HornCtl_TrunkWarnSta = 0U;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt_m = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib) {
     case AppSwcBcm_IN_Delay:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 3)
      {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_TrunkWarnSta = 0U;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt_m = 0U;
      } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())
                  ->BodyWarnSts == 3) && (AppSwcBcm_ARID_DEF.TrunkWarnCnt_m >=
                  HornCtl_TrunkWarnTim_C)) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOn;
        HornCtl_TrunkWarnSta = 1U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt_m + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt_m + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt_m = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff:
      HornCtl_TrunkWarnSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_mg =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S293>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_mg,
        &AppSwcBcm_ARID_DEF.LogicalOperator_h5,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_m);

      /* End of Outputs for SubSystem: '<S293>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_h5 && (HornCtl_LockHoornOnStFb == 1)
          && ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts ==
              3)) {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_Delay;
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt_m + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt_m + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt_m = (uint16)tmp;
      }
      break;

     default:
      /* case IN_SetOn: */
      HornCtl_TrunkWarnSta = 1U;
      if ((AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g >= 3) ||
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 3))
      {
        AppSwcBcm_ARID_DEF.is_c55_HornCtl_Lib = AppSwcBcm_IN_SetOff;
        HornCtl_TrunkWarnSta = 0U;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt_m = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S271>/Chart' */

  /* Truth Table: '<S220>/Truth Table' */
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

  /* End of Truth Table: '<S220>/Truth Table' */

  /* RelationalOperator: '<S220>/Relational Operator' incorporates:
   *  UnitDelay: '<S220>/Unit Delay4'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_js = (rtb_HornCtl_Sta !=
    AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE);

  /* Chart: '<S220>/LIB_Pulse' incorporates:
   *  SubSystem: '<S267>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_js,
    &AppSwcBcm_ARID_DEF.RelationalOperator_m,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet_c);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_m) {
    AppSwcBcm_ARID_DEF.cnt_f = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g = 0U;
  }

  if (rtb_HornCtl_DemCnt >= 1) {
    if (rtb_HornCtl_DemCnt >= 65535) {
      AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_m0 = (AppSwcBcm_ARID_DEF.cnt_f <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_f >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_f = 0U;
      } else {
        AppSwcBcm_ARID_DEF.cnt_f++;
      }
    } else if (AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g < rtb_HornCtl_DemCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_m0 = (AppSwcBcm_ARID_DEF.cnt_f <
        rtb_HornCtl_Wtd);
      if (AppSwcBcm_ARID_DEF.cnt_f >= rtb_HornCtl_Prd - 1) {
        AppSwcBcm_ARID_DEF.cnt_f = 0U;
        AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g++;
      } else {
        AppSwcBcm_ARID_DEF.cnt_f++;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_m0 = false;
    AppSwcBcm_ARID_DEF.cnt_f = 0U;
    AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_g = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S220>/Ovrd1' */
  /* Switch: '<S268>/Switch1' incorporates:
   *  Constant: '<S220>/Constant18'
   */
  if (HornCtl_J430HornDrvOvrdFlg_C) {
    /* Switch: '<S268>/Switch1' incorporates:
     *  Constant: '<S220>/Constant19'
     */
    HornCtl_J430HornDrv = HornCtl_J430HornDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S220>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus())
      ->HornCtlFlg != 0);

    /* Switch: '<S268>/Switch2' */
    if (rtb_RelationalOperator) {
      /* Switch: '<S268>/Switch1' incorporates:
       *  Switch: '<S268>/Switch2'
       */
      HornCtl_J430HornDrv = true;
    } else {
      /* Switch: '<S268>/Switch1' incorporates:
       *  Constant: '<S220>/Constant'
       *  RelationalOperator: '<S220>/Relational Operator1'
       *  Switch: '<S220>/Switch'
       *  Switch: '<S268>/Switch2'
       */
      HornCtl_J430HornDrv =
        ((AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum != 1) &&
         AppSwcBcm_ARID_DEF.LIB_blOut_m0);
    }

    /* End of Switch: '<S268>/Switch2' */
  }

  /* End of Switch: '<S268>/Switch1' */
  /* End of Outputs for SubSystem: '<S220>/Ovrd1' */

  /* Update for Delay: '<S265>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_i = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_m = HornCtl_LockHoornOnSt;

  /* Update for UnitDelay: '<S220>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE = rtb_HornCtl_Sta;
}

/*
 * Output and update for function-call system:
 *    '<S331>/Lib_RiseEdgeDet'
 *    '<S332>/Lib_RiseEdgeDet'
 *    '<S346>/Lib_RiseEdgeDet'
 *    '<S583>/Nrm.Inr.Lib_RiseEdgeDet'
 *    '<S583>/Wash.Lib_RiseEdgeDet'
 *    '<S627>/Lib_RiseEdgeDet'
 *    '<S636>/Lib_RiseEdgeDet'
 *    '<S696>/Lib_RiseEdgeDet'
 *    '<S704>/Lib_RiseEdgeDet'
 *    '<S708>/Lib_RiseEdgeDet'
 *    ...
 */
static void AppSwcBcm_Lib_RiseEdgeDet_c(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_RiseEdgeDet_AppSwcBcm_i_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S336>/Logical Operator' incorporates:
   *  Logic: '<S336>/Logical Operator1'
   *  UnitDelay: '<S336>/Unit Delay'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE));

  /* Update for UnitDelay: '<S336>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S330>/LIB_Pulse'
 *    '<S330>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse_Init(boolean *rty_LIB_blOut, uint16
  *rty_LIB_u16PrdSucCnt)
{
  *rty_LIB_blOut = false;
  *rty_LIB_u16PrdSucCnt = 0U;
}

/*
 * System reset for atomic system:
 *    '<S330>/LIB_Pulse'
 *    '<S330>/LIB_Pulse1'
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
 *    '<S330>/LIB_Pulse'
 *    '<S330>/LIB_Pulse1'
 */
static void AppSwcBcm_LIB_Pulse(uint16 rtu_LIB_u16PrdDemCnt, uint16
  rtu_LIB_u16Prd, uint16 rtu_LIB_u16Wdt, boolean rtu_LIB_blReset, boolean
  *rty_LIB_blOut, uint16 *rty_LIB_u16PrdSucCnt, ARID_DEF_LIB_Pulse_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S330>/LIB_Pulse' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blReset;

  /* Outputs for Function Call SubSystem: '<S331>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S331>/Lib_RiseEdgeDet' */

  /* Chart: '<S330>/LIB_Pulse' */
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
 *    '<S330>/Truth Table'
 *    '<S330>/Truth Table1'
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

/* System initialize for atomic system: '<S221>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S296>/Enabled Subsystem' */

  /* SystemInitialize for Chart: '<S330>/LIB_Pulse' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_m,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_l);

  /* SystemInitialize for Chart: '<S330>/LIB_Pulse1' */
  AppSwcBcm_LIB_Pulse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_f,
    &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt);

  /* End of SystemInitialize for SubSystem: '<S296>/Enabled Subsystem' */
}

/* Output and update for atomic system: '<S221>/ADASLampCtl' */
static void AppSwcBcm_ADASLampCtl(void)
{
  uint16 rtb_BSD_LightPrd;
  uint16 rtb_BSD_LightWdt;
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator8_j;
  boolean rtb_RelationalOperator9_n;

  /* RelationalOperator: '<S296>/Relational Operator' incorporates:
   *  Constant: '<S296>/Constant13'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Enabled SubSystem: '<S296>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S330>/Enable'
   */
  if (rtb_RelationalOperator) {
    if (!AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
      /* SystemReset for Chart: '<S330>/LIB_Pulse' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_m,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_l,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

      /* SystemReset for Chart: '<S330>/LIB_Pulse1' */
      AppSwcBcm_LIB_Pulse_Reset(&AppSwcBcm_ARID_DEF.LIB_blOut_f,
        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);
      AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = true;
    }

    /* RelationalOperator: '<S330>/Relational Operator10' incorporates:
     *  Constant: '<S330>/Constant12'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator1'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 1);

    /* RelationalOperator: '<S330>/Relational Operator8' incorporates:
     *  Constant: '<S330>/Constant3'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator3'
     */
    rtb_RelationalOperator8_j =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 1);

    /* RelationalOperator: '<S330>/Relational Operator9' incorporates:
     *  Constant: '<S330>/Constant4'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator4'
     */
    rtb_RelationalOperator9_n =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 1);

    /* Logic: '<S330>/Logical Operator' */
    rtb_LogicalOperator = (rtb_RelationalOperator || rtb_RelationalOperator8_j ||
      rtb_RelationalOperator9_n);

    /* RelationalOperator: '<S330>/Relational Operator9' incorporates:
     *  Constant: '<S330>/Constant1'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator12'
     */
    rtb_RelationalOperator9_n =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnRt_enum == 2);

    /* RelationalOperator: '<S330>/Relational Operator8' incorporates:
     *  Constant: '<S330>/Constant11'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator11'
     */
    rtb_RelationalOperator8_j =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnRt_enum == 2);

    /* RelationalOperator: '<S330>/Relational Operator10' incorporates:
     *  Constant: '<S330>/Constant10'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator7'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnRt_enum == 2);

    /* Truth Table: '<S330>/Truth Table' incorporates:
     *  Logic: '<S330>/Logical Operator2'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_n ||
                         rtb_RelationalOperator8_j || rtb_RelationalOperator,
                         &rtb_BSD_LightWdt, &rtb_BSD_LightPrd);

    /* Chart: '<S330>/LIB_Pulse' incorporates:
     *  Constant: '<S330>/Constant'
     *  Constant: '<S330>/Constant13'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightWdt, rtb_BSD_LightPrd, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_m,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt_l,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse);

    /* SignalConversion generated from: '<S330>/LampCtl_J420BSDRightCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_m;

    /* RelationalOperator: '<S330>/Relational Operator9' incorporates:
     *  Constant: '<S330>/Constant5'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator5'
     */
    rtb_RelationalOperator9_n =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 1);

    /* RelationalOperator: '<S330>/Relational Operator8' incorporates:
     *  Constant: '<S330>/Constant2'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator2'
     */
    rtb_RelationalOperator8_j =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 1);

    /* RelationalOperator: '<S330>/Relational Operator10' incorporates:
     *  Constant: '<S330>/Constant6'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     *  RelationalOperator: '<S330>/Relational Operator6'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 1);

    /* Logic: '<S330>/Logical Operator3' */
    rtb_LogicalOperator = (rtb_RelationalOperator9_n ||
      rtb_RelationalOperator8_j || rtb_RelationalOperator);

    /* RelationalOperator: '<S330>/Relational Operator9' incorporates:
     *  Constant: '<S330>/Constant8'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator9_n =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRBSDWarnLt_enum == 2);

    /* RelationalOperator: '<S330>/Relational Operator8' incorporates:
     *  Constant: '<S330>/Constant7'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator8_j =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRRCTAWarnLt_enum == 2);

    /* RelationalOperator: '<S330>/Relational Operator10' incorporates:
     *  Constant: '<S330>/Constant9'
     *  Inport: '<Root>/IPM_CRRR_A_CHA'
     */
    rtb_RelationalOperator =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA())
       ->VIPM_CRRRDOWWarnLt_enum == 2);

    /* Truth Table: '<S330>/Truth Table1' incorporates:
     *  Logic: '<S330>/Logical Operator1'
     */
    AppSwcBcm_TruthTable(rtb_LogicalOperator, rtb_RelationalOperator9_n ||
                         rtb_RelationalOperator8_j || rtb_RelationalOperator,
                         &rtb_BSD_LightPrd, &rtb_BSD_LightWdt);

    /* Chart: '<S330>/LIB_Pulse1' incorporates:
     *  Constant: '<S330>/Constant14'
     *  Constant: '<S330>/Constant15'
     */
    AppSwcBcm_LIB_Pulse(MAX_uint16_T, rtb_BSD_LightPrd, rtb_BSD_LightWdt, false,
                        &AppSwcBcm_ARID_DEF.LIB_blOut_f,
                        &AppSwcBcm_ARID_DEF.LIB_u16PrdSucCnt,
                        &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Pulse1);

    /* SignalConversion generated from: '<S330>/LampCtl_J422BSDLeftCtl' */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl =
      AppSwcBcm_ARID_DEF.LIB_blOut_f;
  } else if (AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE) {
    /* Disable for SignalConversion generated from: '<S330>/LampCtl_J420BSDRightCtl' incorporates:
     *  Outport: '<S330>/LampCtl_J420BSDRightCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl = false;

    /* Disable for SignalConversion generated from: '<S330>/LampCtl_J422BSDLeftCtl' incorporates:
     *  Outport: '<S330>/LampCtl_J422BSDLeftCtl'
     */
    AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl = false;
    AppSwcBcm_ARID_DEF.EnabledSubsystem_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S296>/Enabled Subsystem' */
}

/*
 * System initialize for atomic system:
 *    '<S297>/LIB_TPD_10ms'
 *    '<S768>/LIB_TPD_10ms11'
 */
static void AppSwcBcm_LIB_TPD_10ms_Init(boolean *rty_LIB_bErrFlg)
{
  *rty_LIB_bErrFlg = false;
}

/*
 * Output and update for atomic system:
 *    '<S297>/LIB_TPD_10ms'
 *    '<S768>/LIB_TPD_10ms11'
 */
static void AppSwcBcm_LIB_TPD_10ms(boolean rtu_LIB_blIn, uint16
  rtu_LIB_u16tiToDef, float32 rtu_LIB_s32Ts, boolean *rty_LIB_bErrFlg,
  ARID_DEF_LIB_TPD_10ms_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  float32 tmp;

  /* Chart: '<S297>/LIB_TPD_10ms' */
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

  /* End of Chart: '<S297>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S221>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S297>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_d);

  /* SystemInitialize for Chart: '<S297>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_el);
}

/* Output and update for atomic system: '<S221>/AutoLampCtl' */
static void AppSwcBcm_AutoLampCtl(void)
{
  boolean rtb_RelationalOperator1_ll;

  /* Chart: '<S297>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S297>/Constant4'
   *  Constant: '<S297>/Constant43'
   *  Constant: '<S297>/Constant45'
   *  RelationalOperator: '<S297>/Relational Operator4'
   */
  AppSwcBcm_LIB_TPD_10ms(LampCtl_LightIntstSta == 2,
    LampCtl_AutoLampNightDelayTim_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_h);

  /* Chart: '<S297>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S297>/Constant5'
   *  Constant: '<S297>/Constant6'
   *  Constant: '<S297>/Constant7'
   *  Constant: '<S297>/Constant8'
   *  Logic: '<S297>/Logical Operator3'
   *  RelationalOperator: '<S297>/Relational Operator5'
   *  UnitDelay: '<S297>/Unit Delay'
   */
  AppSwcBcm_LIB_TPD_10ms1((LampCtl_LightIntstSta == 1) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hh, LampCtl_AutoLampDayDelayTim_C, 10,
    LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_el,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_l);

  /* RelationalOperator: '<S297>/Relational Operator1' incorporates:
   *  Constant: '<S297>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_ll = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Switch: '<S341>/Switch' incorporates:
   *  Logic: '<S297>/Logical Operator'
   *  RelationalOperator: '<S297>/Relational Operator2'
   */
  if (rtb_RelationalOperator1_ll || (!LampCtl_AutoLampSw) ||
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_el) {
    /* Switch: '<S341>/Switch' incorporates:
     *  Constant: '<S341>/Constant'
     */
    LampCtl_AutoLampSta = false;
  } else {
    /* RelationalOperator: '<S297>/Relational Operator' incorporates:
     *  Constant: '<S297>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator1_ll = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);

    /* Switch: '<S341>/Switch' incorporates:
     *  Logic: '<S297>/Logical Operator1'
     *  Logic: '<S297>/Logical Operator2'
     *  Logic: '<S341>/Logical Operator'
     *  UnitDelay: '<S341>/Unit Delay'
     */
    LampCtl_AutoLampSta = ((rtb_RelationalOperator1_ll &&
      AppSwcBcm_ARID_DEF.LIB_bErrFlg_d) || LampCtl_AutoLampSta);
  }

  /* End of Switch: '<S341>/Switch' */

  /* Update for UnitDelay: '<S297>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hh = LampCtl_AutoLampSta;
}

/* System initialize for atomic system: '<S221>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S298>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_e = true;

  /* InitializeConditions for UnitDelay: '<S298>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 20U;
}

/* Output and update for atomic system: '<S221>/BackLampCtl' */
static void AppSwcBcm_BackLampCtl(void)
{
  uint8 tmp;
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S298>/Relational Operator' incorporates:
   *  Constant: '<S298>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Delay: '<S298>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_e) {
    /* Switch: '<S298>/Switch2' incorporates:
     *  Constant: '<S298>/Constant13'
     *  Constant: '<S298>/Constant14'
     *  RelationalOperator: '<S298>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_a = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_a =
        AppSwcBcm_ARID_DEF.BusCreator12.BackLadjvalFb;
    }

    /* End of Switch: '<S298>/Switch2' */
  }

  /* Switch: '<S298>/Switch1' incorporates:
   *  Constant: '<S298>/Constant12'
   */
  if (rtb_RelationalOperator) {
    tmp = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_CDCBackLadjval_enum;
  } else {
    tmp = 0U;
  }

  /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
   *  Switch: '<S298>/Switch1'
   */
  switch (tmp) {
   case 1:
    /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
     *  Constant: '<S298>/Constant1'
     */
    LampCtl_BackLadjvalFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
     *  Constant: '<S298>/Constant2'
     */
    LampCtl_BackLadjvalFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
     *  Constant: '<S298>/Constant3'
     */
    LampCtl_BackLadjvalFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
     *  Constant: '<S298>/Constant4'
     */
    LampCtl_BackLadjvalFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
     *  Constant: '<S298>/Constant5'
     */
    LampCtl_BackLadjvalFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S298>/Multiport Switch' incorporates:
     *  Delay: '<S298>/Delay'
     */
    LampCtl_BackLadjvalFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_a;
    break;
  }

  /* End of MultiPortSwitch: '<S298>/Multiport Switch' */

  /* MultiPortSwitch: '<S298>/Multiport Switch1' */
  switch (LampCtl_BackLadjvalFb) {
   case 0:
    /* MultiPortSwitch: '<S298>/Multiport Switch1' incorporates:
     *  Constant: '<S298>/Constant6'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 20U;
    break;

   case 1:
    /* MultiPortSwitch: '<S298>/Multiport Switch1' incorporates:
     *  Constant: '<S298>/Constant7'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 40U;
    break;

   case 2:
    /* MultiPortSwitch: '<S298>/Multiport Switch1' incorporates:
     *  Constant: '<S298>/Constant8'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S298>/Multiport Switch1' incorporates:
     *  Constant: '<S298>/Constant9'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 80U;
    break;

   case 4:
    /* MultiPortSwitch: '<S298>/Multiport Switch1' incorporates:
     *  Constant: '<S298>/Constant10'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j = 100U;
    break;
  }

  /* End of MultiPortSwitch: '<S298>/Multiport Switch1' */

  /* Switch: '<S298>/Switch' incorporates:
   *  Logic: '<S298>/Logical Operator'
   *  Logic: '<S298>/Logical Operator1'
   */
  if (rtb_RelationalOperator && (LampCtl_PosLampSta || LampCtl_LowBeamSta)) {
    /* Switch: '<S298>/Switch' */
    AppSwcBcm_ARID_DEF.Switch_a = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j;
  } else {
    /* Switch: '<S298>/Switch' incorporates:
     *  Constant: '<S298>/Constant11'
     */
    AppSwcBcm_ARID_DEF.Switch_a = 0U;
  }

  /* End of Switch: '<S298>/Switch' */

  /* Update for Delay: '<S298>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_e = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_a = LampCtl_BackLadjvalFb;
}

/*
 * Outputs for atomic system:
 *    '<S299>/Lib_FailEdgeDet'
 *    '<S299>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S342>/Logical Operator' incorporates:
   *  Logic: '<S342>/Logical Operator1'
   *  UnitDelay: '<S342>/Unit Delay'
   */
  return (!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE;
}

/*
 * Update for atomic system:
 *    '<S299>/Lib_FailEdgeDet'
 *    '<S299>/Lib_FailEdgeDet1'
 */
static void AppSwcBcm_Lib_FailEdgeDet_Update(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Update for UnitDelay: '<S342>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S345>/LIB_PosPluse2'
 *    '<S690>/LIB_PosPluse2'
 *    '<S817>/LIB_NegPluse2'
 *    '<S818>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2_Init(boolean *rty_LIB_blOut)
{
  *rty_LIB_blOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S345>/LIB_PosPluse2'
 *    '<S690>/LIB_PosPluse2'
 *    '<S817>/LIB_NegPluse2'
 *    '<S818>/LIB_NegPluse1'
 */
static void AppSwcBcm_LIB_PosPluse2(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluse2_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  sint32 tmp;

  /* Chart: '<S345>/LIB_PosPluse2' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blRst;

  /* Outputs for Function Call SubSystem: '<S346>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S346>/Lib_RiseEdgeDet' */

  /* Chart: '<S345>/LIB_PosPluse2' */
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

/* System initialize for atomic system: '<S221>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_i;

  /* SystemInitialize for Atomic SubSystem: '<S299>/Trunk10min' */

  /* SystemInitialize for Chart: '<S345>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_i);

  /* End of SystemInitialize for SubSystem: '<S299>/Trunk10min' */
}

/* Outputs for atomic system: '<S221>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_i;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_k2;
  boolean rtb_LogicalOperator2_fm;
  boolean rtb_LogicalOperator_cp;
  boolean rtb_LogicalOperator_g3g;
  boolean rtb_Switch_k0;

  /* Logic: '<S343>/Logical Operator' incorporates:
   *  Constant: '<S299>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S299>/Relational Operator1'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S299>/Logical Operator2' incorporates:
   *  Constant: '<S299>/Constant'
   *  RelationalOperator: '<S299>/Relational Operator'
   */
  rtb_LogicalOperator2_fm = (rtb_LogicalOperator && (LampCtl_LightIntstSta == 2));

  /* Outputs for Atomic SubSystem: '<S299>/Lib_FailEdgeDet' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  rtb_LogicalOperator_g3g = AppSwcBcm_Lib_FailEdgeDet
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

  /* End of Outputs for SubSystem: '<S299>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S299>/Lib_FailEdgeDet1' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o4);

  /* End of Outputs for SubSystem: '<S299>/Lib_FailEdgeDet1' */

  /* Logic: '<S299>/Logical Operator' */
  rtb_LogicalOperator_cp = (rtb_LogicalOperator_g3g || rtb_LogicalOperator);

  /* Outputs for Atomic SubSystem: '<S299>/Trunk10min' */

  /* Chart: '<S345>/LIB_PosPluse2' incorporates:
   *  Constant: '<S299>/Constant4'
   *  UnitDelay: '<S299>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0c,
    LampCtl_BoxLampOpenTimMax_C, rtb_LogicalOperator_cp, &rtb_LIB_blOut_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2_p);

  /* End of Outputs for SubSystem: '<S299>/Trunk10min' */

  /* Logic: '<S299>/Logical Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator1_k2 = (rtb_LIB_blOut_i ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->InsLck ||
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLck);

  /* Outputs for Atomic SubSystem: '<S299>/Lib_SR' */
  AppSwcBcm_Lib_SR(rtb_LogicalOperator_cp, rtb_LogicalOperator1_k2,
                   &rtb_Switch_k0, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR_e);

  /* End of Outputs for SubSystem: '<S299>/Lib_SR' */

  /* Switch: '<S299>/Switch' incorporates:
   *  UnitDelay: '<S299>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0c = (rtb_LogicalOperator2_fm ||
    rtb_Switch_k0);
}

/* Update for atomic system: '<S221>/BoxLampCtl' */
static void AppSwcBcm_BoxLampCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S299>/Lib_FailEdgeDet' */

  /* Update for DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_Lib_FailEdgeDet_Update
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_h);

  /* End of Update for SubSystem: '<S299>/Lib_FailEdgeDet' */

  /* Update for Atomic SubSystem: '<S299>/Lib_FailEdgeDet1' */
  AppSwcBcm_Lib_FailEdgeDet_Update
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o4);

  /* End of Update for SubSystem: '<S299>/Lib_FailEdgeDet1' */
}

/* Output and update for atomic system: '<S221>/DayRunLampCtl' */
static void AppSwcBcm_DayRunLampCtl(void)
{
  boolean rtb_RelationalOperator6_f;

  /* RelationalOperator: '<S301>/Relational Operator6' incorporates:
   *  Constant: '<S301>/Constant6'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator6_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Outputs for Atomic SubSystem: '<S301>/Lib_SR' */
  /* Switch: '<S349>/Switch' incorporates:
   *  Constant: '<S301>/Constant1'
   *  Constant: '<S301>/Constant2'
   *  Constant: '<S301>/Constant8'
   *  Constant: '<S349>/Constant'
   *  Logic: '<S301>/Logical Operator'
   *  Logic: '<S301>/Logical Operator1'
   *  Logic: '<S349>/Logical Operator'
   *  RelationalOperator: '<S301>/Relational Operator1'
   *  RelationalOperator: '<S301>/Relational Operator2'
   *  RelationalOperator: '<S301>/Relational Operator7'
   *  RelationalOperator: '<S301>/Relational Operator8'
   *  UnitDelay: '<S349>/Unit Delay'
   */
  if (rtb_RelationalOperator6_f || LampCtl_PosLampSta ||
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VHVM_PTActOprtMode_enum != 2)) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ezv = false;
  } else {
    /* RelationalOperator: '<S301>/Relational Operator' incorporates:
     *  Constant: '<S301>/Constant'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ezv = ((rtb_RelationalOperator6_f &&
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VHVM_PTActOprtMode_enum == 2) &&
      (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VGSM_VehActGearPstn_enum != 0)) ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ezv);
  }

  /* End of Switch: '<S349>/Switch' */
  /* End of Outputs for SubSystem: '<S301>/Lib_SR' */
}

/* System initialize for atomic system: '<S221>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S352>/Lib_RateLimit' */
  /* InitializeConditions for Delay: '<S366>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ce = true;

  /* End of SystemInitialize for SubSystem: '<S352>/Lib_RateLimit' */

  /* SystemInitialize for Truth Table: '<S302>/Truth Table' */
  LampCtl_DomeLampOff = true;
}

/* Outputs for atomic system: '<S221>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl(void)
{
  sint32 Switch;
  float32 rtb_Add;
  boolean RelationalOperator3;
  boolean rtb_RelationalOperator7_d;
  boolean rtb_RelationalOperator8_ll;

  /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S350>/Relational Operator1'
   */
  rtb_RelationalOperator8_ll =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFLSw;

  /* Outputs for Atomic SubSystem: '<S350>/FL10min' */
  /* Chart: '<S356>/LIB_Tim' incorporates:
   *  Constant: '<S356>/Constant'
   *  Logic: '<S350>/Logical Operator1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && rtb_RelationalOperator8_ll) {
    if (AppSwcBcm_ARID_DEF.Cnt_pi <= 30000) {
      AppSwcBcm_ARID_DEF.Cnt_pi++;
      LampCtl_DomeLampFLOpen = true;
    } else {
      LampCtl_DomeLampFLOpen = false;
    }
  } else {
    LampCtl_DomeLampFLOpen = false;
    AppSwcBcm_ARID_DEF.Cnt_pi = 0U;
  }

  /* End of Chart: '<S356>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S350>/FL10min' */

  /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S350>/Relational Operator2'
   */
  rtb_RelationalOperator8_ll =
    !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DoorAjarFRSw;

  /* Outputs for Atomic SubSystem: '<S350>/FR10min' */
  /* Chart: '<S357>/LIB_Tim' incorporates:
   *  Constant: '<S357>/Constant'
   *  Logic: '<S350>/Logical Operator2'
   */
  if (AppSwcBcm_ConstB.RelationalOperator && rtb_RelationalOperator8_ll) {
    if (AppSwcBcm_ARID_DEF.Cnt_dd <= 30000) {
      AppSwcBcm_ARID_DEF.Cnt_dd++;
      LampCtl_DomeLampFROpen = true;
    } else {
      LampCtl_DomeLampFROpen = false;
    }
  } else {
    LampCtl_DomeLampFROpen = false;
    AppSwcBcm_ARID_DEF.Cnt_dd = 0U;
  }

  /* End of Chart: '<S357>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S350>/FR10min' */

  /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S351>/Relational Operator5'
   */
  rtb_RelationalOperator8_ll = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFLSw;

  /* RelationalOperator: '<S353>/Relational Operator7' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S351>/Relational Operator6'
   */
  rtb_RelationalOperator7_d = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw;

  /* RelationalOperator: '<S351>/Relational Operator3' incorporates:
   *  Constant: '<S351>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  RelationalOperator3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Outputs for Atomic SubSystem: '<S351>/Lib_FailEdgeDetHold' */
  /* Switch: '<S362>/Switch' incorporates:
   *  Constant: '<S362>/Constant'
   *  Logic: '<S362>/Logical Operator2'
   *  UnitDelay: '<S362>/Unit Delay'
   *  UnitDelay: '<S362>/Unit Delay1'
   */
  if (RelationalOperator3) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f =
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j4 ||
       AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f);
  }

  /* End of Switch: '<S362>/Switch' */

  /* Update for UnitDelay: '<S362>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_j4 = RelationalOperator3;

  /* End of Outputs for SubSystem: '<S351>/Lib_FailEdgeDetHold' */

  /* Outputs for Atomic SubSystem: '<S351>/30s' */
  /* Chart: '<S360>/LIB_Tim' incorporates:
   *  Constant: '<S360>/Constant'
   *  Logic: '<S351>/Logical Operator4'
   *  Logic: '<S351>/Logical Operator5'
   *  UnitDelay: '<S362>/Unit Delay1'
   */
  if (rtb_RelationalOperator8_ll && rtb_RelationalOperator7_d &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_f &&
      AppSwcBcm_ConstB.RelationalOperator1_h) {
    if (AppSwcBcm_ARID_DEF.Cnt_j <= 1500) {
      AppSwcBcm_ARID_DEF.Cnt_j++;
      LampCtl_DomeLampPwrOff = true;
    } else {
      LampCtl_DomeLampPwrOff = false;
    }
  } else {
    LampCtl_DomeLampPwrOff = false;
    AppSwcBcm_ARID_DEF.Cnt_j = 0U;
  }

  /* End of Chart: '<S360>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S351>/30s' */

  /* Outputs for Atomic SubSystem: '<S351>/Lib_FailEdgeDetHold1' */
  /* Switch: '<S363>/Switch' incorporates:
   *  Constant: '<S363>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  Logic: '<S363>/Logical Operator'
   *  Logic: '<S363>/Logical Operator2'
   *  UnitDelay: '<S363>/Unit Delay'
   *  UnitDelay: '<S363>/Unit Delay1'
   */
  if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cc = false;
  } else {
    /* Logic: '<S363>/Logical Operator1' */
    rtb_RelationalOperator8_ll =
      !(Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cc = ((rtb_RelationalOperator8_ll &&
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jh) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cc);
  }

  /* End of Switch: '<S363>/Switch' */
  /* End of Outputs for SubSystem: '<S351>/Lib_FailEdgeDetHold1' */

  /* RelationalOperator: '<S353>/Relational Operator7' incorporates:
   *  Constant: '<S351>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S351>/Relational Operator4'
   */
  rtb_RelationalOperator7_d = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Outputs for Atomic SubSystem: '<S351>/30s1' */
  /* Chart: '<S361>/LIB_Tim' incorporates:
   *  Constant: '<S361>/Constant'
   *  Logic: '<S351>/Logical Operator1'
   *  UnitDelay: '<S363>/Unit Delay1'
   */
  if (AppSwcBcm_ConstB.RelationalOperator1_h &&
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_cc && rtb_RelationalOperator7_d) {
    if (AppSwcBcm_ARID_DEF.Cnt_c2 <= 1500) {
      AppSwcBcm_ARID_DEF.Cnt_c2++;
      LampCtl_DomeLampUnlock = true;
    } else {
      LampCtl_DomeLampUnlock = false;
    }
  } else {
    LampCtl_DomeLampUnlock = false;
    AppSwcBcm_ARID_DEF.Cnt_c2 = 0U;
  }

  /* End of Chart: '<S361>/LIB_Tim' */
  /* End of Outputs for SubSystem: '<S351>/30s1' */

  /* RelationalOperator: '<S353>/Relational Operator4' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  LampCtl_DomeLampLockDoor = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DriverDoorLckSw;

  /* RelationalOperator: '<S353>/Relational Operator7' incorporates:
   *  Constant: '<S353>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator7_d = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* RelationalOperator: '<S353>/Relational Operator8' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator8_ll = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus
    ())->DoorAjarFLSw;

  /* RelationalOperator: '<S353>/Relational Operator9' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  RelationalOperator3 = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->DoorAjarFRSw;

  /* Logic: '<S353>/Logical Operator6' */
  LampCtl_DomeLampCloseDoor = (rtb_RelationalOperator7_d &&
    rtb_RelationalOperator8_ll && RelationalOperator3);

  /* Truth Table: '<S302>/Truth Table' */
  /*  Open Door Dome Lamp Turn ON */
  /*  Power Off Or Unlock Door Dome Lamp Turn ON */
  /*  Lock Door or Power On and Close Door Turn Off Dome Lamp */
  /*  Condition #4 */
  /*  Condition #5 */
  /*  Condition #6 */
  rtb_RelationalOperator8_ll = !LampCtl_DomeLampLockDoor;
  rtb_RelationalOperator7_d = !LampCtl_DomeLampCloseDoor;
  if (LampCtl_DomeLampFLOpen && rtb_RelationalOperator8_ll &&
      rtb_RelationalOperator7_d) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S302>/Lib_SR' */
    /* Switch: '<S354>/Switch' incorporates:
     *  Logic: '<S354>/Logical Operator'
     *  UnitDelay: '<S354>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S302>/Lib_SR' */
  } else if (LampCtl_DomeLampFROpen && rtb_RelationalOperator8_ll &&
             rtb_RelationalOperator7_d) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S302>/Lib_SR' */
    /* Switch: '<S354>/Switch' incorporates:
     *  Logic: '<S354>/Logical Operator'
     *  UnitDelay: '<S354>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S302>/Lib_SR' */
  } else if (LampCtl_DomeLampPwrOff && rtb_RelationalOperator8_ll &&
             rtb_RelationalOperator7_d) {
    /*  Example action 1 called from D1 & D2 column in condition table */
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = false;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S302>/Lib_SR' */
    /* Switch: '<S354>/Switch' incorporates:
     *  Logic: '<S354>/Logical Operator'
     *  UnitDelay: '<S354>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S302>/Lib_SR' */
  } else if (LampCtl_DomeLampUnlock && rtb_RelationalOperator8_ll &&
             rtb_RelationalOperator7_d) {
    LampCtl_DomeLampOn = true;
    LampCtl_DomeLampOff = false;
    LampCtl_DomeLampOnGrad = true;
    LampCtl_DomeLampOffGrad = false;

    /* Outputs for Atomic SubSystem: '<S302>/Lib_SR' */
    /* Switch: '<S354>/Switch' incorporates:
     *  Logic: '<S354>/Logical Operator'
     *  UnitDelay: '<S354>/Unit Delay'
     */
    LampCtl_DomeLampCtl = (LampCtl_DomeLampOn || LampCtl_DomeLampCtl);

    /* End of Outputs for SubSystem: '<S302>/Lib_SR' */
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

    /* Outputs for Atomic SubSystem: '<S302>/Lib_SR' */
    /* Switch: '<S354>/Switch' incorporates:
     *  Constant: '<S354>/Constant'
     */
    LampCtl_DomeLampCtl = false;

    /* End of Outputs for SubSystem: '<S302>/Lib_SR' */
  }

  /* End of Truth Table: '<S302>/Truth Table' */

  /* Switch: '<S352>/Switch' */
  if (LampCtl_DomeLampCtl) {
    /* Switch: '<S352>/Switch' incorporates:
     *  Constant: '<S352>/Constant'
     */
    Switch = 100;
  } else {
    /* Switch: '<S352>/Switch' incorporates:
     *  Constant: '<S352>/Constant1'
     */
    Switch = 0;
  }

  /* End of Switch: '<S352>/Switch' */

  /* Outputs for Atomic SubSystem: '<S352>/Lib_RateLimit' */
  /* Delay: '<S366>/Variable Integer Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_ce) {
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)Switch;
  }

  /* Sum: '<S366>/Add' incorporates:
   *  Delay: '<S366>/Variable Integer Delay'
   */
  rtb_Add = (float32)Switch - AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;

  /* Switch: '<S366>/Switch' incorporates:
   *  RelationalOperator: '<S366>/Relational Operator'
   *  RelationalOperator: '<S366>/Relational Operator1'
   *  Switch: '<S366>/Switch1'
   */
  if (rtb_Add > AppSwcBcm_ConstB.Product) {
    /* Switch: '<S366>/Switch' incorporates:
     *  Delay: '<S366>/Variable Integer Delay'
     *  Sum: '<S366>/Add1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += AppSwcBcm_ConstB.Product;
  } else if (rtb_Add < AppSwcBcm_ConstB.Product1) {
    /* Switch: '<S366>/Switch1' incorporates:
     *  Delay: '<S366>/Variable Integer Delay'
     *  Sum: '<S366>/Add2'
     *  Switch: '<S366>/Switch'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE += AppSwcBcm_ConstB.Product1;
  } else {
    /* Switch: '<S366>/Switch' incorporates:
     *  Switch: '<S366>/Switch1'
     */
    AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE = (float32)Switch;
  }

  /* End of Switch: '<S366>/Switch' */

  /* Update for Delay: '<S366>/Variable Integer Delay' */
  AppSwcBcm_ARID_DEF.icLoad_ce = false;

  /* End of Outputs for SubSystem: '<S352>/Lib_RateLimit' */

  /* Switch: '<S352>/Switch1' incorporates:
   *  Switch: '<S352>/Switch2'
   */
  if (LampCtl_DomeLampOffGrad) {
    /* DataTypeConversion: '<S352>/Data Type Conversion' */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
  } else if (LampCtl_DomeLampOnGrad) {
    /* Switch: '<S352>/Switch2' incorporates:
     *  DataTypeConversion: '<S352>/Data Type Conversion'
     */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)
      AppSwcBcm_ARID_DEF.VariableIntegerDelay_DSTATE;
  } else {
    /* DataTypeConversion: '<S352>/Data Type Conversion' incorporates:
     *  Switch: '<S352>/Switch1'
     *  Switch: '<S352>/Switch2'
     */
    AppSwcBcm_ARID_DEF.DataTypeConversion = (uint8)(float32)Switch;
  }

  /* End of Switch: '<S352>/Switch1' */
}

/* Update for atomic system: '<S221>/DomeLampCtl' */
static void AppSwcBcm_DomeLampCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S351>/Lib_FailEdgeDetHold1' */
  /* Update for UnitDelay: '<S363>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jh =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->DriverDoorLckSw;

  /* End of Update for SubSystem: '<S351>/Lib_FailEdgeDetHold1' */
}

/* Output and update for atomic system: '<S221>/FogLampRCtl' */
static void AppSwcBcm_FogLampRCtl(void)
{
  boolean guard1 = false;

  /* Chart: '<S303>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c17_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c17_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_c = false;
  } else if (AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib == AppSwcBcm_IN_Off_i) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        LampCtl_PosLampSta && LampCtl_LowBeamSta) {
      AppSwcBcm_ARID_DEF.Lib_blIn_bm = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S367>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_bm,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ad,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fm);

      /* End of Outputs for SubSystem: '<S367>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ad) {
        AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib = AppSwcBcm_IN_On_i;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_c = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) || (
         !LampCtl_PosLampSta)) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_bm = LampCtl_FogLampRSw;

      /* Outputs for Function Call SubSystem: '<S367>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_bm,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ad,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_fm);

      /* End of Outputs for SubSystem: '<S367>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ad) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c17_LampCtl_Lib = AppSwcBcm_IN_Off_i;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_c = false;
    }
  }

  /* End of Chart: '<S303>/Chart' */

  /* Chart: '<S303>/Chart1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c19_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c19_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib = AppSwcBcm_IN_Off_i;
    AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_k = false;
  } else if (AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib == AppSwcBcm_IN_Off_i) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
        LampCtl_PosLampSta) {
      AppSwcBcm_ARID_DEF.Lib_blIn_e0 = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S368>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_e0,
        &AppSwcBcm_ARID_DEF.LogicalOperator_o3,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);

      /* End of Outputs for SubSystem: '<S368>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_o3) {
        AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib = AppSwcBcm_IN_On_i;
        AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_k = true;
      }
    }
  } else {
    /* case IN_On: */
    guard1 = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) || (
         !LampCtl_PosLampSta)) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_e0 = LampCtl_FogLampFSw;

      /* Outputs for Function Call SubSystem: '<S368>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_e0,
        &AppSwcBcm_ARID_DEF.LogicalOperator_o3,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_c);

      /* End of Outputs for SubSystem: '<S368>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_o3) {
        guard1 = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c19_LampCtl_Lib = AppSwcBcm_IN_Off_i;
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_k = false;
    }
  }

  /* End of Chart: '<S303>/Chart1' */
}

/* Output and update for atomic system: '<S221>/KnobBeamDig' */
static void AppSwcBcm_KnobBeamDig(void)
{
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_fh;
  boolean rtb_RelationalOperator2_ha;

  /* RelationalOperator: '<S305>/Relational Operator' incorporates:
   *  Constant: '<S305>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S305>/Relational Operator1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator1_fh =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSPstnLghtSwStVld_flg;

  /* RelationalOperator: '<S305>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator2_ha =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLoBeamSwStVld_flg;

  /* Chart: '<S305>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S305>/Constant21'
   *  Constant: '<S305>/Constant3'
   *  Constant: '<S305>/Constant4'
   *  Logic: '<S305>/Logical Operator'
   *  Logic: '<S305>/Logical Operator1'
   */
  if ((rtb_RelationalOperator1_fh || rtb_RelationalOperator2_ha) &&
      rtb_RelationalOperator) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_dj >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_KnobBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_dj++;
      AppSwcBcm_ARID_DEF.cnt_heal_cc = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_dj = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cc == 0) {
      LampCtl_KnobBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_cc--;
    }
  }

  /* End of Chart: '<S305>/LIB_TPD_10ms' */
}

/* System initialize for atomic system: '<S221>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_b;

  /* SystemInitialize for Chart: '<S306>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_b);
}

/* Outputs for atomic system: '<S221>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_b;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_os;

  /* RelationalOperator: '<S306>/Relational Operator' incorporates:
   *  Constant: '<S306>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus()
    )->BodyWarnSts == 1);

  /* Chart: '<S306>/LIB_Tim' incorporates:
   *  Constant: '<S306>/Constant6'
   *  UnitDelay: '<S306>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i,
    LampCtl_LampDelayTim_C, &rtb_LIB_blOut_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_mj);

  /* RelationalOperator: '<S306>/Relational Operator1' incorporates:
   *  Constant: '<S306>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_os = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Outputs for Atomic SubSystem: '<S306>/Lib_SR' */
  /* Switch: '<S376>/Switch' incorporates:
   *  Logic: '<S306>/Logical Operator1'
   *  RelationalOperator: '<S306>/Relational Operator4'
   */
  if (rtb_RelationalOperator || rtb_RelationalOperator1_os ||
      (!LampCtl_AutoLampSw) || rtb_LIB_blOut_b) {
    /* Switch: '<S376>/Switch' incorporates:
     *  Constant: '<S376>/Constant'
     */
    LampCtl_LampDelay = false;
  } else {
    /* RelationalOperator: '<S375>/Relational Operator1' incorporates:
     *  Constant: '<S306>/Constant5'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 0);

    /* Switch: '<S376>/Switch' incorporates:
     *  Constant: '<S306>/Constant3'
     *  Constant: '<S306>/Constant4'
     *  Logic: '<S306>/Logical Operator'
     *  Logic: '<S375>/Logical Operator'
     *  Logic: '<S376>/Logical Operator'
     *  RelationalOperator: '<S306>/Relational Operator3'
     *  RelationalOperator: '<S375>/Relational Operator'
     *  UnitDelay: '<S375>/Unit Delay'
     *  UnitDelay: '<S376>/Unit Delay'
     */
    LampCtl_LampDelay = (((LampCtl_LightIntstSta == 2) &&
                          (rtb_RelationalOperator &&
      (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e == 2))) || LampCtl_LampDelay);
  }

  /* End of Switch: '<S376>/Switch' */
  /* End of Outputs for SubSystem: '<S306>/Lib_SR' */
}

/* Update for atomic system: '<S221>/LampDelayCtl' */
static void AppSwcBcm_LampDelayCtl_Update(void)
{
  /* Update for UnitDelay: '<S306>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_i = LampCtl_LampDelay;

  /* Update for UnitDelay: '<S375>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_e =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode;
}

/* Output and update for atomic system: '<S221>/LightIntstDet' */
static void AppSwcBcm_LightIntstDet(void)
{
  /* Chart: '<S307>/Chart' */
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

  /* End of Chart: '<S307>/Chart' */
}

/* System initialize for atomic system: '<S221>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S308>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_e);
}

/* Output and update for atomic system: '<S221>/LowBeamCtl' */
static void AppSwcBcm_LowBeamCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S308>/Relational Operator' incorporates:
   *  Constant: '<S308>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Chart: '<S308>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S308>/Constant13'
   *  Constant: '<S308>/Constant4'
   *  Constant: '<S308>/Constant5'
   *  Logic: '<S308>/Logical Operator'
   *  Logic: '<S308>/Logical Operator1'
   *  Logic: '<S308>/Logical Operator2'
   *  RelationalOperator: '<S308>/Relational Operator1'
   *  RelationalOperator: '<S308>/Relational Operator2'
   *  RelationalOperator: '<S308>/Relational Operator3'
   *  UnitDelay: '<S221>/Unit Delay'
   *  UnitDelay: '<S221>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms1((rtb_RelationalOperator && (LampCtl_LowBeamSw ||
    LampCtl_PassLightSta || LampCtl_AutoLampSta || LampCtl_KnobBeamFaultSta)) ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b || LampCtl_LampDelay,
    LampCtl_LowBeamStaTimValid_C, LampCtl_LowBeamStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_m);
}

/* Output and update for atomic system: '<S221>/BrakeLampCtl' */
static void AppSwcBcm_BrakeLampCtl(void)
{
  boolean rtb_RelationalOperator2_e1;
  boolean rtb_RelationalOperator8_o;

  /* RelationalOperator: '<S300>/Relational Operator8' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S300>/Relational Operator3'
   */
  rtb_RelationalOperator8_o =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLA_flg;

  /* RelationalOperator: '<S300>/Relational Operator2' incorporates:
   *  Inport: '<Root>/IPM_EHB_A_CHA'
   *  RelationalOperator: '<S300>/Relational Operator6'
   */
  rtb_RelationalOperator2_e1 =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA())
    ->VIPM_EHBBLAVld_flg;

  /* Logic: '<S300>/Logical Operator4' */
  rtb_RelationalOperator8_o = (rtb_RelationalOperator8_o &&
    rtb_RelationalOperator2_e1);

  /* RelationalOperator: '<S300>/Relational Operator2' incorporates:
   *  Constant: '<S300>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator2_e1 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S300>/Logical Operator' incorporates:
   *  Logic: '<S300>/Logical Operator1'
   *  Logic: '<S300>/Logical Operator3'
   *  Logic: '<S300>/Logical Operator5'
   *  RelationalOperator: '<S300>/Relational Operator'
   *  RelationalOperator: '<S300>/Relational Operator1'
   *  RelationalOperator: '<S300>/Relational Operator7'
   *  RelationalOperator: '<S300>/Relational Operator8'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_op = (LampCtl_BrakeLightSw ||
    (rtb_RelationalOperator2_e1 &&
     (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VVTM_RegenReqBrkLampOn_flg ||
      rtb_RelationalOperator8_o ||
      (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e.VIPM_ESCReqBrkLghtOn_flg &&
       AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e.VIPM_ESCReqBrkLghtOnVld_flg))));
}

/* Output and update for atomic system: '<S221>/ReverseLampCtl' */
static void AppSwcBcm_ReverseLampCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S326>/Relational Operator' incorporates:
   *  Constant: '<S326>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S326>/Logical Operator' incorporates:
   *  Constant: '<S326>/Constant1'
   *  RelationalOperator: '<S326>/Relational Operator1'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_pf = (rtb_RelationalOperator &&
    (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VGSM_VehActGearPstn_enum == 3));
}

/* Output and update for atomic system: '<S221>/HiBeamCtl' */
static void AppSwcBcm_HiBeamCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S304>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S304>/Logical Operator' incorporates:
   *  Logic: '<S304>/Logical Operator1'
   *  RelationalOperator: '<S304>/Relational Operator1'
   *  RelationalOperator: '<S304>/Relational Operator2'
   *  RelationalOperator: '<S304>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_kh = (LampCtl_LowBeamSta &&
    rtb_RelationalOperator && (LampCtl_HiBeamSw || LampCtl_PassLightSta));
}

/* Output and update for atomic system: '<S221>/PassLampFunc' */
static void AppSwcBcm_PassLampFunc(void)
{
  /* Chart: '<S324>/LIB_Tim' incorporates:
   *  Constant: '<S324>/Constant1'
   *  RelationalOperator: '<S324>/Relational Operator'
   */
  if (LampCtl_PassLightSw) {
    if (AppSwcBcm_ARID_DEF.Cnt_cq <= 1000) {
      AppSwcBcm_ARID_DEF.Cnt_cq++;
      LampCtl_PassLightSta = true;
    } else {
      LampCtl_PassLightSta = false;
    }
  } else {
    LampCtl_PassLightSta = false;
    AppSwcBcm_ARID_DEF.Cnt_cq = 0U;
  }

  /* End of Chart: '<S324>/LIB_Tim' */
}

/* System initialize for atomic system: '<S221>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S325>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_km);
}

/* Output and update for atomic system: '<S221>/PosLampCtl' */
static void AppSwcBcm_PosLampCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S325>/Relational Operator' incorporates:
   *  Constant: '<S325>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Chart: '<S325>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S325>/Constant13'
   *  Constant: '<S325>/Constant2'
   *  Constant: '<S325>/Constant4'
   *  Logic: '<S325>/Logical Operator'
   *  Logic: '<S325>/Logical Operator1'
   *  Logic: '<S325>/Logical Operator2'
   *  RelationalOperator: '<S325>/Relational Operator1'
   *  RelationalOperator: '<S325>/Relational Operator3'
   *  UnitDelay: '<S221>/Unit Delay'
   *  UnitDelay: '<S221>/Unit Delay1'
   */
  AppSwcBcm_LIB_TPD_10ms1((rtb_RelationalOperator && (LampCtl_PosLampSw ||
    LampCtl_LowBeamSw || LampCtl_AutoLampSta)) ||
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b || LampCtl_KnobBeamFaultSta ||
    LampCtl_LampDelay, LampCtl_PosLampStaTimValid_C,
    LampCtl_PosLampStaTimInValid_C, LampCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_km,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8_l);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift10'
 *    '<S641>/Bit Shift9'
 */
static uint16 AppSwcBcm_BitShift10_k(uint16 rtu_u)
{
  /* MATLAB Function: '<S383>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 8);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift11'
 *    '<S641>/Bit Shift12'
 */
static uint16 AppSwcBcm_BitShift11_f(uint16 rtu_u)
{
  /* MATLAB Function: '<S384>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 11);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift2'
 *    '<S641>/Bit Shift4'
 */
static uint16 AppSwcBcm_BitShift2(uint16 rtu_u)
{
  /* MATLAB Function: '<S385>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 4);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift3'
 *    '<S641>/Bit Shift8'
 */
static uint16 AppSwcBcm_BitShift3_b(uint16 rtu_u)
{
  /* MATLAB Function: '<S386>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 7);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift4'
 *    '<S549>/Bit Shift1'
 *    '<S641>/Bit Shift1'
 */
static uint16 AppSwcBcm_BitShift4(uint16 rtu_u)
{
  /* MATLAB Function: '<S387>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 1);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift7'
 *    '<S549>/Bit Shift2'
 *    '<S641>/Bit Shift2'
 */
static uint16 AppSwcBcm_BitShift7(uint16 rtu_u)
{
  /* MATLAB Function: '<S390>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 2);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift8'
 *    '<S641>/Bit Shift6'
 */
static uint16 AppSwcBcm_BitShift8(uint16 rtu_u)
{
  /* MATLAB Function: '<S391>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 5);
}

/*
 * Output and update for atomic system:
 *    '<S327>/Bit Shift9'
 *    '<S641>/Bit Shift7'
 */
static uint16 AppSwcBcm_BitShift9(uint16 rtu_u)
{
  /* MATLAB Function: '<S392>/bit_shift' */
  return (uint16)((uint32)rtu_u >> 6);
}

/* System initialize for atomic system: '<S221>/SignalProcess' */
static void AppSwcBcm_SignalProcess_Init(void)
{
  /* SystemInitialize for Chart: '<S327>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_j);

  /* SystemInitialize for Chart: '<S327>/LIB_TPD_10ms13' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_fr);
}

/* Output and update for atomic system: '<S221>/SignalProcess' */
static void AppSwcBcm_SignalProcess(void)
{
  uint16 rtb_y;
  uint16 rtb_y_i;
  boolean rtb_LogicalOperator2_cl;
  boolean rtb_Switch9_f;
  boolean rtb_Switch_gc;

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift' */
  /* Constant: '<S327>/Constant48' */
  rtb_y = AppSwcBcm_BitShift3(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift' */

  /* Switch: '<S327>/Switch' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S327>/Switch' incorporates:
     *  Constant: '<S327>/Constant50'
     */
    rtb_Switch_gc = LampCtl_PosLampVal_C;
  } else {
    /* Switch: '<S327>/Switch' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S327>/Logical Operator6'
     */
    rtb_Switch_gc =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSPstnLghtSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSPstnLghtSwStVld_flg);
  }

  /* End of Switch: '<S327>/Switch' */

  /* Chart: '<S327>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S327>/Constant19'
   *  Constant: '<S327>/Constant20'
   *  Constant: '<S327>/Constant21'
   */
  if (rtb_Switch_gc) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_eq >= (float32)LampCtl_PosLampTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_PosLampTimValid_C != 0xFFFF)) {
      LampCtl_PosLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_eq++;
      AppSwcBcm_ARID_DEF.cnt_heal_db = (uint16)((float32)
        LampCtl_PosLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_eq = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_db == 0) {
      LampCtl_PosLampSw = false;
    } else if (LampCtl_PosLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_db--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift4' */
  /* Constant: '<S327>/Constant1' */
  rtb_y_i = AppSwcBcm_BitShift4(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift4' */

  /* Switch: '<S327>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND4'
   */
  if ((rtb_y_i & 1U) != 0U) {
    /* Switch: '<S327>/Switch4' incorporates:
     *  Constant: '<S327>/Constant10'
     */
    rtb_Switch_gc = LampCtl_LowBeamVal_C;
  } else {
    /* Switch: '<S327>/Switch4' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S327>/Logical Operator7'
     */
    rtb_Switch_gc =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLoBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLoBeamSwStVld_flg);
  }

  /* End of Switch: '<S327>/Switch4' */

  /* Chart: '<S327>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S327>/Constant22'
   *  Constant: '<S327>/Constant23'
   *  Constant: '<S327>/Constant24'
   */
  if (rtb_Switch_gc) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_cr >= (float32)LampCtl_LowBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_LowBeamTimValid_C != 0xFFFF)) {
      LampCtl_LowBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_cr++;
      AppSwcBcm_ARID_DEF.cnt_heal_pf = (uint16)((float32)
        LampCtl_LowBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_cr = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pf == 0) {
      LampCtl_LowBeamSw = false;
    } else if (LampCtl_LowBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pf--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift7' */
  /* Constant: '<S327>/Constant12' */
  rtb_y_i = AppSwcBcm_BitShift7(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift7' */

  /* Switch: '<S327>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND7'
   */
  if ((rtb_y_i & 1U) != 0U) {
    /* Switch: '<S327>/Switch7' incorporates:
     *  Constant: '<S327>/Constant11'
     */
    rtb_Switch_gc = LampCtl_HiBeamVal_C;
  } else {
    /* Switch: '<S327>/Switch7' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S327>/Logical Operator8'
     */
    rtb_Switch_gc =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSHiBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSHiBeamSwStVld_flg);
  }

  /* End of Switch: '<S327>/Switch7' */

  /* Chart: '<S327>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S327>/Constant25'
   *  Constant: '<S327>/Constant26'
   *  Constant: '<S327>/Constant27'
   */
  if (rtb_Switch_gc) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_nd >= (float32)LampCtl_HiBeamTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_HiBeamTimValid_C != 0xFFFF)) {
      LampCtl_HiBeamSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_nd++;
      AppSwcBcm_ARID_DEF.cnt_heal_nm = (uint16)((float32)
        LampCtl_HiBeamTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_nd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_nm == 0) {
      LampCtl_HiBeamSw = false;
    } else if (LampCtl_HiBeamTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_nm--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift1' */
  /* Constant: '<S327>/Constant3' */
  rtb_y = AppSwcBcm_BitShift1_j(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift1' */

  /* Switch: '<S327>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S327>/Switch1' incorporates:
     *  Constant: '<S327>/Constant2'
     */
    rtb_Switch_gc = LampCtl_PassLightVal_C;
  } else {
    /* Switch: '<S327>/Switch1' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S327>/Logical Operator1'
     */
    rtb_Switch_gc =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSOvrVehBeamSwSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSOvrVehBeamSwStVld_flg);
  }

  /* End of Switch: '<S327>/Switch1' */

  /* Chart: '<S327>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S327>/Constant28'
   *  Constant: '<S327>/Constant29'
   *  Constant: '<S327>/Constant30'
   */
  if (rtb_Switch_gc) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_ld >= (float32)
         LampCtl_PassLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_PassLightTimValid_C != 0xFFFF)) {
      LampCtl_PassLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_ld++;
      AppSwcBcm_ARID_DEF.cnt_heal_bns = (uint16)((float32)
        LampCtl_PassLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_ld = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bns == 0) {
      LampCtl_PassLightSw = false;
    } else if (LampCtl_PassLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bns--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift2' */
  /* Constant: '<S327>/Constant53' */
  rtb_y = AppSwcBcm_BitShift2(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift2' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift8' */
  /* Constant: '<S327>/Constant4' */
  rtb_y_i = AppSwcBcm_BitShift8(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift8' */

  /* Logic: '<S327>/Logical Operator3' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_Switch_gc =
    ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwSt_flg &&
     (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwStVld_flg);

  /* Logic: '<S327>/Logical Operator2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_LogicalOperator2_cl =
    ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwSt_flg &&
     (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwStVld_flg);

  /* Switch: '<S327>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND8'
   */
  if ((rtb_y_i & 1U) != 0U) {
    /* Switch: '<S327>/Switch9' incorporates:
     *  Constant: '<S327>/Constant5'
     */
    rtb_Switch9_f = LampCtl_TurnIndcrRVal_C;
  } else {
    /* Switch: '<S327>/Switch9' incorporates:
     *  Logic: '<S327>/Logical Operator'
     *  Logic: '<S327>/Logical Operator10'
     */
    rtb_Switch9_f = (rtb_Switch_gc && (!rtb_LogicalOperator2_cl));
  }

  /* End of Switch: '<S327>/Switch9' */

  /* Chart: '<S327>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S327>/Constant37'
   *  Constant: '<S327>/Constant38'
   *  Constant: '<S327>/Constant39'
   */
  if (rtb_Switch9_f) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c1 >= (float32)
         LampCtl_TurnIndcrRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c1++;
      AppSwcBcm_ARID_DEF.cnt_heal_dv = (uint16)((float32)
        LampCtl_TurnIndcrRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S327>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S327>/Constant37'
     *  Constant: '<S327>/Constant38'
     *  Constant: '<S327>/Constant39'
     *  Constant: '<S327>/Constant40'
     *  Constant: '<S327>/Constant41'
     *  Constant: '<S327>/Constant42'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d0h >= (float32)
         LampCtl_TurnIndcrLaneRTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneRTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d0h++;
      AppSwcBcm_ARID_DEF.cnt_heal_fm = (uint16)((float32)
        LampCtl_TurnIndcrLaneRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_dv == 0) {
      LampCtl_TurnIndcrRSw = false;
    } else if (LampCtl_TurnIndcrRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_dv--;
    }

    /* Chart: '<S327>/LIB_TPD_10ms7' incorporates:
     *  Constant: '<S327>/Constant38'
     *  Constant: '<S327>/Constant41'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_d0h = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_fm == 0) {
      LampCtl_TurnIndcrLaneRSw = false;
    } else if (LampCtl_TurnIndcrLaneRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_fm--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms6' */

  /* Switch: '<S327>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S327>/Switch2' incorporates:
     *  Constant: '<S327>/Constant54'
     */
    rtb_LogicalOperator2_cl = LampCtl_TurnIndcrLVal_C;
  } else {
    /* Switch: '<S327>/Switch2' incorporates:
     *  Logic: '<S327>/Logical Operator12'
     *  Logic: '<S327>/Logical Operator5'
     *  UnitDelay: '<S327>/Unit Delay1'
     */
    rtb_LogicalOperator2_cl = (rtb_LogicalOperator2_cl &&
      (!AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i));
  }

  /* End of Switch: '<S327>/Switch2' */

  /* Chart: '<S327>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S327>/Constant31'
   *  Constant: '<S327>/Constant32'
   *  Constant: '<S327>/Constant33'
   */
  if (rtb_LogicalOperator2_cl) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gy >= (float32)
         LampCtl_TurnIndcrLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gy++;
      AppSwcBcm_ARID_DEF.cnt_heal_oc = (uint16)((float32)
        LampCtl_TurnIndcrLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }

    /* Chart: '<S327>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S327>/Constant31'
     *  Constant: '<S327>/Constant32'
     *  Constant: '<S327>/Constant33'
     *  Constant: '<S327>/Constant34'
     *  Constant: '<S327>/Constant35'
     *  Constant: '<S327>/Constant36'
     */
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fu >= (float32)
         LampCtl_TurnIndcrLaneLTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrLaneLTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLaneLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fu++;
      AppSwcBcm_ARID_DEF.cnt_heal_pq = (uint16)((float32)
        LampCtl_TurnIndcrLaneLTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gy = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_oc == 0) {
      LampCtl_TurnIndcrLSw = false;
    } else if (LampCtl_TurnIndcrLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_oc--;
    }

    /* Chart: '<S327>/LIB_TPD_10ms5' incorporates:
     *  Constant: '<S327>/Constant32'
     *  Constant: '<S327>/Constant35'
     */
    AppSwcBcm_ARID_DEF.cnt_defect_fu = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_pq == 0) {
      LampCtl_TurnIndcrLaneLSw = false;
    } else if (LampCtl_TurnIndcrLaneLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_pq--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift3' */
  /* Constant: '<S327>/Constant55' */
  rtb_y_i = AppSwcBcm_BitShift3_b(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift3' */

  /* Switch: '<S327>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND3'
   */
  if ((rtb_y_i & 1U) != 0U) {
    /* Switch: '<S327>/Switch3' incorporates:
     *  Constant: '<S327>/Constant56'
     */
    rtb_LogicalOperator2_cl = LampCtl_FogLampRVal_C;
  } else {
    /* Switch: '<S327>/Switch3' incorporates:
     *  DataTypeConversion: '<S327>/Data Type Conversion3'
     *  Logic: '<S327>/Logical Operator9'
     */
    rtb_LogicalOperator2_cl = (BSW_J346FogLampR == 0);
  }

  /* End of Switch: '<S327>/Switch3' */

  /* Chart: '<S327>/LIB_TPD_10ms9' incorporates:
   *  Constant: '<S327>/Constant43'
   *  Constant: '<S327>/Constant44'
   *  Constant: '<S327>/Constant45'
   */
  if (rtb_LogicalOperator2_cl) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_o >= (float32)LampCtl_FogLampRTimValid_C /
         (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampRTimValid_C != 0xFFFF)) {
      LampCtl_FogLampRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_o++;
      AppSwcBcm_ARID_DEF.cnt_heal_bn = (uint16)((float32)
        LampCtl_FogLampRTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_o = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_bn == 0) {
      LampCtl_FogLampRSw = false;
    } else if (LampCtl_FogLampRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_bn--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms9' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift5' */
  /* S-Function (sfix_bitop): '<S327>/Bitwise AND5' incorporates:
   *  Constant: '<S327>/Constant59'
   *  MATLAB Function: '<S388>/bit_shift'
   */
  rtb_y_i = (uint16)((sint32)((uint32)LampCtl_InportCalSwBit_C >> 9) & 1);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift5' */

  /* Switch: '<S327>/Switch5' */
  if (rtb_y_i != 0) {
    /* Switch: '<S327>/Switch5' incorporates:
     *  Constant: '<S327>/Constant60'
     */
    rtb_LogicalOperator2_cl = LampCtl_HazardLightVal_C;
  } else {
    /* Switch: '<S327>/Switch5' */
    rtb_LogicalOperator2_cl =
      AppSwcBcm_ARID_DEF.IPM_CCP_PanelStatus_BOD_d.VIPM_CCPHzrdKey_flg;
  }

  /* End of Switch: '<S327>/Switch5' */

  /* Chart: '<S327>/LIB_TPD_10ms10' incorporates:
   *  Constant: '<S327>/Constant46'
   *  Constant: '<S327>/Constant47'
   *  Constant: '<S327>/Constant49'
   */
  if (rtb_LogicalOperator2_cl) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hx >= (float32)
         LampCtl_HazardLightTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_HazardLightTimValid_C != 0xFFFF)) {
      LampCtl_HazardLightSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hx++;
      AppSwcBcm_ARID_DEF.cnt_heal_nd = (uint16)((float32)
        LampCtl_HazardLightTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hx = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_nd == 0) {
      LampCtl_HazardLightSw = false;
    } else if (LampCtl_HazardLightTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_nd--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms10' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift11' */
  /* Constant: '<S327>/Constant73' */
  rtb_y = AppSwcBcm_BitShift11_f(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift11' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift6' */
  /* Switch: '<S327>/Switch6' incorporates:
   *  Constant: '<S327>/Constant61'
   *  Constant: '<S327>/Constant62'
   *  DataTypeConversion: '<S327>/Data Type Conversion6'
   *  MATLAB Function: '<S389>/bit_shift'
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND6'
   */
  if (((uint32)LampCtl_InportCalSwBit_C >> 10 & 1U) != 0U) {
    rtb_LogicalOperator2_cl = LampCtl_BrakeLightVal_C;
  } else {
    rtb_LogicalOperator2_cl = (BSW_J313BrakeLoSw != 0);
  }

  /* End of Outputs for SubSystem: '<S327>/Bit Shift6' */

  /* Chart: '<S327>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S327>/Constant14'
   *  Constant: '<S327>/Constant15'
   *  Constant: '<S327>/Constant16'
   *  Switch: '<S327>/Switch6'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_LogicalOperator2_cl, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11_o);

  /* Switch: '<S327>/Switch12' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND11'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S327>/Switch12' incorporates:
     *  Constant: '<S327>/Constant74'
     */
    rtb_LogicalOperator2_cl = LampCtl_BrakeLightVal_C;
  } else {
    /* Switch: '<S327>/Switch12' incorporates:
     *  DataTypeConversion: '<S327>/Data Type Conversion13'
     *  Logic: '<S327>/Logical Operator14'
     */
    rtb_LogicalOperator2_cl = (BSW_J339BrakeHiSw == 0);
  }

  /* End of Switch: '<S327>/Switch12' */

  /* Chart: '<S327>/LIB_TPD_10ms13' incorporates:
   *  Constant: '<S327>/Constant70'
   *  Constant: '<S327>/Constant71'
   *  Constant: '<S327>/Constant72'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_LogicalOperator2_cl, LampCtl_BrakeSwTimValid_C,
    LampCtl_BrakeSwInValid_C, LampCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_fr,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms13);

  /* Logic: '<S327>/Logical Operator13' */
  LampCtl_BrakeLightSw = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_j ||
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_fr);

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift9' */
  /* Constant: '<S327>/Constant6' */
  rtb_y_i = AppSwcBcm_BitShift9(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift9' */

  /* Switch: '<S327>/Switch10' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND9'
   */
  if ((rtb_y_i & 1U) != 0U) {
    /* Switch: '<S327>/Switch10' incorporates:
     *  Constant: '<S327>/Constant8'
     */
    rtb_LogicalOperator2_cl = LampCtl_AutoLampVal_C;
  } else {
    /* Switch: '<S327>/Switch10' incorporates:
     *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
     *  Logic: '<S327>/Logical Operator4'
     */
    rtb_LogicalOperator2_cl =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLampAutoSt_flg &&
       (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
        ())->VIPM_SCSLampAutoStVld_flg);
  }

  /* End of Switch: '<S327>/Switch10' */

  /* Chart: '<S327>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S327>/Constant13'
   *  Constant: '<S327>/Constant63'
   *  Constant: '<S327>/Constant9'
   */
  if (rtb_LogicalOperator2_cl) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_am >= (float32)LampCtl_AutoLampTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_AutoLampTimValid_C != 0xFFFF)) {
      LampCtl_AutoLampSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_am++;
      AppSwcBcm_ARID_DEF.cnt_heal_lf = (uint16)((float32)
        LampCtl_AutoLampTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_am = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_lf == 0) {
      LampCtl_AutoLampSw = false;
    } else if (LampCtl_AutoLampTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_lf--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S327>/Bit Shift10' */
  /* Constant: '<S327>/Constant68' */
  rtb_y = AppSwcBcm_BitShift10_k(LampCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S327>/Bit Shift10' */

  /* Switch: '<S327>/Switch11' incorporates:
   *  S-Function (sfix_bitop): '<S327>/Bitwise AND10'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S327>/Switch11' incorporates:
     *  Constant: '<S327>/Constant69'
     */
    rtb_LogicalOperator2_cl = LampCtl_FogLampFVal_C;
  } else {
    /* Switch: '<S327>/Switch11' incorporates:
     *  DataTypeConversion: '<S327>/Data Type Conversion9'
     *  Logic: '<S327>/Logical Operator11'
     */
    rtb_LogicalOperator2_cl = (BSW_J322FogLampF == 0);
  }

  /* End of Switch: '<S327>/Switch11' */

  /* Chart: '<S327>/LIB_TPD_10ms12' incorporates:
   *  Constant: '<S327>/Constant64'
   *  Constant: '<S327>/Constant66'
   *  Constant: '<S327>/Constant67'
   */
  if (rtb_LogicalOperator2_cl) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_dz >= (float32)LampCtl_FogLampFTimValid_C
         / (LampCtl_Ts_C * 100.0F)) && (LampCtl_FogLampFTimValid_C != 0xFFFF)) {
      LampCtl_FogLampFSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_dz++;
      AppSwcBcm_ARID_DEF.cnt_heal_cm = (uint16)((float32)
        LampCtl_FogLampFTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_dz = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_cm == 0) {
      LampCtl_FogLampFSw = false;
    } else if (LampCtl_FogLampFTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_cm--;
    }
  }

  /* End of Chart: '<S327>/LIB_TPD_10ms12' */

  /* MultiPortSwitch: '<S327>/Multiport Switch' */
  switch (BSW_RKEReq) {
   case 0:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant'
     */
    LampCtl_RKEReq = 0U;
    break;

   case 17:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant17'
     */
    LampCtl_RKEReq = 1U;
    break;

   case 18:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant18'
     */
    LampCtl_RKEReq = 2U;
    break;

   case 19:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant51'
     */
    LampCtl_RKEReq = 3U;
    break;

   case 34:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant52'
     */
    LampCtl_RKEReq = 4U;
    break;

   case 49:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant57'
     */
    LampCtl_RKEReq = 5U;
    break;

   case 50:
    /* MultiPortSwitch: '<S327>/Multiport Switch' incorporates:
     *  Constant: '<S327>/Constant58'
     */
    LampCtl_RKEReq = 6U;
    break;
  }

  /* End of MultiPortSwitch: '<S327>/Multiport Switch' */

  /* DataTypeConversion: '<S327>/Data Type Conversion12' */
  LampCtl_LightIntstVal = BSW_J125LightIntst;

  /* Update for UnitDelay: '<S327>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_i = rtb_Switch_gc;
}

/*
 * System initialize for function-call system:
 *    '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
  (ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
   *AppSwcBcm__ARID_DEF_arg)
{
  /* SystemInitialize for Atomic SubSystem: '<S447>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S447>/Lib_RiseEdgeDetInit' */
}

/*
 * Output and update for function-call system:
 *    '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit'
 *    '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(boolean rtu_Lib_blIn,
  boolean *rty_Lib_blOut, ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit_AppSwcBcm_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S447>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S447>/Lib_RiseEdgeDetInit' */
}

/*
 * System initialize for function-call system:
 *    '<S431>/Pri4Func.Turn'
 *    '<S431>/Pri4Func.Turn1'
 *    '<S431>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn_Init(boolean *rty_y)
{
  /* SystemInitialize for Chart: '<S484>/Turn' */
  *rty_y = false;
}

/*
 * Output and update for function-call system:
 *    '<S431>/Pri4Func.Turn'
 *    '<S431>/Pri4Func.Turn1'
 *    '<S431>/Pri4Func.Turn2'
 */
static void AppSwcBcm_Pri4FuncTurn(boolean rtu_x, boolean *rty_y,
  ARID_DEF_Pri4FuncTurn_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S484>/Turn' */
  if (AppSwcBcm__ARID_DEF_arg->is_active_c107_LampCtl_Lib == 0U) {
    AppSwcBcm__ARID_DEF_arg->is_active_c107_LampCtl_Lib = 1U;
    *rty_y = !rtu_x;
  }

  /* End of Chart: '<S484>/Turn' */
}

/*
 * Output and update for atomic system:
 *    '<S505>/Lib_BothEdgeDet'
 *    '<S787>/Lib_BothEdgeDet'
 *    '<S787>/Lib_BothEdgeDet1'
 *    '<S787>/Lib_BothEdgeDet2'
 *    '<S787>/Lib_BothEdgeDet3'
 */
static void AppSwcBcm_Lib_BothEdgeDet(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_BothEdgeDet_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S506>/Logical Operator2' incorporates:
   *  Logic: '<S506>/Logical Operator1'
   *  Logic: '<S506>/Logical Operator3'
   *  Logic: '<S506>/Logical Operator4'
   *  Logic: '<S506>/Logical Operator5'
   *  UnitDelay: '<S506>/Unit Delay'
   */
  *rty_Lib_blOut = ((AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE && (!rtu_Lib_blIn))
                    || (rtu_Lib_blIn &&
                        (!AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE)));

  /* Update for UnitDelay: '<S506>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S328>/HazardLightLogic' */
static boolean AppSwcBcm_EmerOff(void)
{
  boolean guard1 = false;
  boolean y;

  /* UnitDelay: '<S328>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.Lib_blIn_fe = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j;

  /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet1' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fe,
    &AppSwcBcm_ARID_DEF.LogicalOperator_me,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_lt);

  /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet1' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_me) {
    guard1 = true;
  } else {
    /* UnitDelay: '<S328>/Unit Delay5' */
    AppSwcBcm_ARID_DEF.Lib_blIn_bx = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_n;

    /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet2' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_bx,
      &AppSwcBcm_ARID_DEF.LogicalOperator_hf,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_o);

    /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet2' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_hf) {
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

/* Function for Chart: '<S328>/HazardLightLogic' */
static boolean AppSwcBcm_HazardOff(void)
{
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_pe = LampCtl_HazardLightSw;

  /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_pe,
    &AppSwcBcm_ARID_DEF.LogicalOperator_og,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o2);

  /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_og) {
    y = true;
    AppSwcBcm_ARID_DEF.LampCtl_HazardLightHst = false;
  } else {
    y = false;
  }

  return y;
}

/* Function for Chart: '<S328>/HazardLightLogic' */
static boolean AppSwcBcm_TurnOff(void)
{
  boolean guard1 = false;
  boolean y;
  AppSwcBcm_ARID_DEF.Lib_blIn_pf = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 1);

  /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet4' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_pf,
    &AppSwcBcm_ARID_DEF.LogicalOperator_eb,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet4);

  /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet4' */
  guard1 = false;
  if (AppSwcBcm_ARID_DEF.LogicalOperator_eb) {
    guard1 = true;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_a = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta ==
      2);

    /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet5' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_a,
      &AppSwcBcm_ARID_DEF.LogicalOperator_gs,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet5);

    /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet5' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_gs) {
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

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_TurnFunc(void)
{
  LampCtl_TurnIndcrRst = !LampCtl_TurnIndcrRst;
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_Pri1Func(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_EnFunc(void)
{
  LampCtl_TurnIndcrPrd = 0U;
  LampCtl_TurnIndcrWdt = 0U;
  LampCtl_TurnIndcrRFlashCnt = 0U;
  LampCtl_TurnIndcrLFlashCnt = 0U;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_Pri2Func(void)
{
  LampCtl_TurnIndcrPrd = 15U;
  LampCtl_TurnIndcrWdt = 8U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;

  /* LampCtl_TurnIndcrRst=Turn(LampCtl_TurnIndcrRst); */
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_Pri4Func(void)
{
  switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide) {
   case 2:
    AppSwcBcm_ARID_DEF.x = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S431>/Pri4Func.Turn' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x, &AppSwcBcm_ARID_DEF.y_f,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn);

    /* End of Outputs for SubSystem: '<S431>/Pri4Func.Turn' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_f;
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
    AppSwcBcm_ARID_DEF.x_d = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S431>/Pri4Func.Turn1' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_d, &AppSwcBcm_ARID_DEF.y_g,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn1);

    /* End of Outputs for SubSystem: '<S431>/Pri4Func.Turn1' */
    LampCtl_TurnIndcrRst = AppSwcBcm_ARID_DEF.y_g;
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
    AppSwcBcm_ARID_DEF.x_o = LampCtl_TurnIndcrRst;

    /* Outputs for Function Call SubSystem: '<S431>/Pri4Func.Turn2' */
    AppSwcBcm_Pri4FuncTurn(AppSwcBcm_ARID_DEF.x_o, &AppSwcBcm_ARID_DEF.y,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Pri4FuncTurn2);

    /* End of Outputs for SubSystem: '<S431>/Pri4Func.Turn2' */
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

/* Function for Chart: '<S328>/TurnIndcrArb2' */
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

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_AntiLckFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_bd = AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;

  /* Outputs for Function Call SubSystem: '<S431>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_bd,
    &AppSwcBcm_ARID_DEF.RelationalOperator_d0,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5AntiLckFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S431>/Pri5.AntiLckFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_d0) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_ArmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 40U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
  AppSwcBcm_ARID_DEF.Lib_blIn_ko = AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;

  /* Outputs for Function Call SubSystem: '<S431>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_ko,
    &AppSwcBcm_ARID_DEF.RelationalOperator_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5ArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S431>/Pri5.ArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_a) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_DisarmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_kp = AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;

  /* Outputs for Function Call SubSystem: '<S431>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_kp,
    &AppSwcBcm_ARID_DEF.RelationalOperator_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5DisarmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S431>/Pri5.DisarmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_c) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_PartArmedFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
  AppSwcBcm_ARID_DEF.Lib_blIn_kof = AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;

  /* Outputs for Function Call SubSystem: '<S431>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_kof,
    &AppSwcBcm_ARID_DEF.RelationalOperator_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5PartArmedFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S431>/Pri5.PartArmedFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_d) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_RodBeamFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = MAX_uint16_T;
  LampCtl_TurnIndcrLFlashCnt = MAX_uint16_T;
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_SeekFunc(void)
{
  LampCtl_TurnIndcrPrd = 40U;
  LampCtl_TurnIndcrWdt = 20U;
  LampCtl_TurnIndcrRFlashCnt = 10U;
  LampCtl_TurnIndcrLFlashCnt = 10U;
  AppSwcBcm_ARID_DEF.Lib_blIn_bq = AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;

  /* Outputs for Function Call SubSystem: '<S431>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_bq,
    &AppSwcBcm_ARID_DEF.RelationalOperator_cl,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Pri5SeekFuncLib_EdgeChgDet);

  /* End of Outputs for SubSystem: '<S431>/Pri5.SeekFunc.Lib_EdgeChgDet' */
  if (AppSwcBcm_ARID_DEF.RelationalOperator_cl) {
    AppSwcBcm_TurnFunc();
  }
}

/* Function for Chart: '<S328>/TurnIndcrArb2' */
static void AppSwcBcm_TrunkWarnFunc(void)
{
  LampCtl_TurnIndcrPrd = 20U;
  LampCtl_TurnIndcrWdt = 10U;
  LampCtl_TurnIndcrRFlashCnt = 3U;
  LampCtl_TurnIndcrLFlashCnt = 3U;
}

/* Function for Chart: '<S422>/Chart' */
static void AppSwcBcm_CrashClearFunc(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_jc =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

  /* Outputs for Function Call SubSystem: '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit' */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_jc,
    &AppSwcBcm_ARID_DEF.LogicalOperator_eq,
    &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit' */
  AppSwcBcm_ARID_DEF.PwrOffFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_eq ||
    AppSwcBcm_ARID_DEF.PwrOffFlg);
  if (AppSwcBcm_ARID_DEF.PwrOffFlg) {
    AppSwcBcm_ARID_DEF.Lib_blIn_fs =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

    /* Outputs for Function Call SubSystem: '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
    AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_fs,
      &AppSwcBcm_ARID_DEF.LogicalOperator_fc,
      &AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

    /* End of Outputs for SubSystem: '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit1' */
    AppSwcBcm_ARID_DEF.PwrOnFlg = (AppSwcBcm_ARID_DEF.LogicalOperator_fc ||
      AppSwcBcm_ARID_DEF.PwrOnFlg);
  }
}

/* System initialize for atomic system: '<S221>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S419>/Chart' incorporates:
   *  SubSystem: '<S439>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_co);

  /* SystemInitialize for Chart: '<S421>/Chart' incorporates:
   *  SubSystem: '<S443>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_g);

  /* SystemInitialize for Chart: '<S422>/Chart' incorporates:
   *  SubSystem: '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S422>/Chart' incorporates:
   *  SubSystem: '<S446>/CrashClearFunc.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_CrashClearFuncLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_CrashClearFuncLib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S423>/Chart' incorporates:
   *  SubSystem: '<S457>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_i);

  /* SystemInitialize for Chart: '<S426>/Chart' incorporates:
   *  SubSystem: '<S472>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_as);

  /* SystemInitialize for Chart: '<S430>/Chart' incorporates:
   *  SubSystem: '<S481>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_a);

  /* SystemInitialize for Chart: '<S328>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S431>/Pri4Func.Turn'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_f);

  /* SystemInitialize for Chart: '<S328>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S431>/Pri4Func.Turn1'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y_g);

  /* SystemInitialize for Chart: '<S328>/TurnIndcrArb2' incorporates:
   *  SubSystem: '<S431>/Pri4Func.Turn2'
   */
  AppSwcBcm_Pri4FuncTurn_Init(&AppSwcBcm_ARID_DEF.y);

  /* SystemInitialize for Chart: '<S437>/Chart' incorporates:
   *  SubSystem: '<S514>/Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_c);

  /* SystemInitialize for Chart: '<S437>/Chart' incorporates:
   *  SubSystem: '<S514>/Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

  /* SystemInitialize for Chart: '<S437>/Chart' incorporates:
   *  SubSystem: '<S514>/Lib_RiseEdgeDetInit2'
   */
  AppSwcBcm_Lib_RiseEdgeDetInit_h_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);
}

/* Output and update for atomic system: '<S221>/TurnIndcrCtl' */
static void AppSwcBcm_TurnIndcrCtl(void)
{
  sint32 tmp;
  uint16 rtb_Switch1;
  uint8 rtb_RelationalOperator_gn_tmp;
  boolean RelationalOperator;
  boolean RelationalOperator4_l;
  boolean RelationalOperator6_m;
  boolean RelationalOperator8_e;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_LogicalOperator1_ge;
  boolean rtb_LogicalOperator2_hr;
  boolean rtb_LogicalOperator8_b;
  boolean rtb_LogicalOperator9_l;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator14_h;
  boolean rtb_RelationalOperator16_jq;
  boolean rtb_RelationalOperator19;
  boolean rtb_RelationalOperator1_cc;
  boolean rtb_RelationalOperator1_niw;
  boolean rtb_RelationalOperator23;
  boolean rtb_RelationalOperator7_ke;
  boolean rtb_RelationalOperator9_c;
  boolean rtb_UnitDelay17;
  boolean tmp_0;
  boolean tmp_1;
  boolean tmp_2;
  boolean tmp_3;

  /* Chart: '<S328>/TurnIndcrLogic' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S328>/Unit Delay2'
   *  UnitDelay: '<S328>/Unit Delay3'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c115_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c115_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
    LampCtl_TurnIndcrMod = 0U;
  } else {
    guard1 = false;
    switch (AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib) {
     case AppSwcBcm_IN_OFF_l:
      if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) {
        AppSwcBcm_ARID_DEF.Lib_blIn_h2d = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S434>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_h2d,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_px);

        /* End of Outputs for SubSystem: '<S434>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h || LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_TurnR;
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
        AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnL == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
          AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrLSw) {
        AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 4U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_nn = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S434>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_nn,
          &AppSwcBcm_ARID_DEF.LogicalOperator_c3,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

        /* End of Outputs for SubSystem: '<S434>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_c3) {
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
        AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (AppSwcBcm_ARID_DEF.is_TurnR == AppSwcBcm_IN_LongFlash) {
        if (!LampCtl_TurnIndcrRSw) {
          AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
          AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
          LampCtl_TurnIndcrMod = 0U;
        }

        /* case IN_ShortFlash: */
      } else if (AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_o >= 3) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_OFF_l;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 0U;
        LampCtl_TurnIndcrMod = 0U;
      } else if (LampCtl_TurnIndcrRSw) {
        AppSwcBcm_ARID_DEF.is_TurnR = AppSwcBcm_IN_LongFlash;
        LampCtl_TurnIndcrMod = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_h2d = LampCtl_TurnIndcrLaneRSw;

        /* Outputs for Function Call SubSystem: '<S434>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_h2d,
          &AppSwcBcm_ARID_DEF.LogicalOperator_h,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_px);

        /* End of Outputs for SubSystem: '<S434>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_h) {
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
        AppSwcBcm_ARID_DEF.Lib_blIn_nn = LampCtl_TurnIndcrLaneLSw;

        /* Outputs for Function Call SubSystem: '<S434>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_nn,
          &AppSwcBcm_ARID_DEF.LogicalOperator_c3,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_c);

        /* End of Outputs for SubSystem: '<S434>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_c3 || LampCtl_TurnIndcrLSw) {
          AppSwcBcm_ARID_DEF.is_c115_LampCtl_Lib = AppSwcBcm_IN_TurnL;
          AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta = 2U;
          AppSwcBcm_ARID_DEF.is_TurnL = AppSwcBcm_IN_ShortFlash;
        }
      }
    }
  }

  /* End of Chart: '<S328>/TurnIndcrLogic' */

  /* Chart: '<S328>/HazardLightLogic' incorporates:
   *  UnitDelay: '<S328>/Unit Delay4'
   *  UnitDelay: '<S328>/Unit Delay5'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c62_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c62_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib = AppSwcBcm_IN_OFF;
    LampCtl_HazardLightSta = false;
    LampCtl_EmerHazardLightSta = false;
  } else {
    guard1 = false;
    guard2 = false;
    switch (AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib) {
     case AppSwcBcm_IN_EmerON:
      if (((!AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_n) &&
           (!AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j)) || AppSwcBcm_HazardOff())
      {
        /* {Lib_RiseEdgeDet(LampCtl_HazardLightSw)} */
        AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib = AppSwcBcm_IN_OFF;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
      }
      break;

     case AppSwcBcm_IN_OFF:
      AppSwcBcm_ARID_DEF.Lib_blIn_fe = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j;

      /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fe,
        &AppSwcBcm_ARID_DEF.LogicalOperator_me,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_lt);

      /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_me) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_bx = AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_n;

        /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_bx,
          &AppSwcBcm_ARID_DEF.LogicalOperator_hf,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_o);

        /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_hf) {
          guard1 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_pe = LampCtl_HazardLightSw;

          /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_pe,
            &AppSwcBcm_ARID_DEF.LogicalOperator_og,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o2);

          /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_og) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_f5e =
              (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

            /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet3' */
            AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_f5e,
              &AppSwcBcm_ARID_DEF.LogicalOperator_ky,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_i);

            /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet3' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_ky ||
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
        AppSwcBcm_ARID_DEF.Lib_blIn_f5e =
          (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_f5e,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ky,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_i);

        /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib = AppSwcBcm_IN_EmerON;
        LampCtl_EmerHazardLightSta = true;
        LampCtl_HazardLightSta = false;
      } else if (AppSwcBcm_HazardOff() || AppSwcBcm_TurnOff()) {
        AppSwcBcm_ARID_DEF.Lib_blIn_f5e =
          (AppSwcBcm_ARID_DEF.BusCreator12.HazardLightSta == 1);

        /* Outputs for Function Call SubSystem: '<S425>/Lib_RiseEdgeDet3' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_f5e,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ky,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3_i);

        /* End of Outputs for SubSystem: '<S425>/Lib_RiseEdgeDet3' */
        AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib = AppSwcBcm_IN_OFF;
        LampCtl_HazardLightSta = false;
        LampCtl_EmerHazardLightSta = false;
      }
      break;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib = AppSwcBcm_IN_ON;
      LampCtl_HazardLightSta = true;
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c62_LampCtl_Lib = AppSwcBcm_IN_EmerON;
      LampCtl_EmerHazardLightSta = true;
      LampCtl_HazardLightSta = false;
    }
  }

  /* End of Chart: '<S328>/HazardLightLogic' */

  /* RelationalOperator: '<S427>/Relational Operator' */
  RelationalOperator = LampCtl_EmerHazardLightSta;

  /* RelationalOperator: '<S428>/Relational Operator1' incorporates:
   *  Constant: '<S424>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S424>/Relational Operator'
   */
  rtb_RelationalOperator1_niw = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S424>/Logical Operator' */
  LampCtl_EmerSta = (AppSwcBcm_ConstB.RelationalOperator1_d &&
                     rtb_RelationalOperator1_niw);

  /* RelationalOperator: '<S427>/Relational Operator4' */
  RelationalOperator4_l = LampCtl_EmerSta;

  /* Chart: '<S328>/TurnIndcrSelect' */
  if (AppSwcBcm_ARID_DEF.is_active_c117_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c117_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_Off_a;
    AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib) {
     case AppSwcBcm_IN_Off_a:
      if (LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_TurnLROn;
      } else {
        switch (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta) {
         case 1:
          AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_TurnROn;
          break;

         case 2:
          AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_TurnLOn;
          break;
        }
      }
      break;

     case AppSwcBcm_IN_TurnLOn:
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_Off_a;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 3U;
      }
      break;

     case AppSwcBcm_IN_TurnLROn:
      if (!LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_Off_a;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 1U;
      }
      break;

     default:
      /* case IN_TurnROn: */
      if ((AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrSta == 0) ||
          LampCtl_HazardLightSta) {
        AppSwcBcm_ARID_DEF.is_c117_LampCtl_Lib = AppSwcBcm_IN_Off_a;
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 0U;
      } else {
        AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide = 2U;
      }
      break;
    }
  }

  /* End of Chart: '<S328>/TurnIndcrSelect' */

  /* RelationalOperator: '<S427>/Relational Operator8' incorporates:
   *  Constant: '<S427>/Constant8'
   */
  RelationalOperator8_e = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide != 0);

  /* Logic: '<S427>/Logical Operator8' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator'
   *  RelationalOperator: '<S427>/Relational Operator4'
   */
  rtb_LogicalOperator8_b = (LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* Chart: '<S419>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c11_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_AlrmSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c11_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_og =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 2);

    /* Outputs for Function Call SubSystem: '<S439>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_og,
      &AppSwcBcm_ARID_DEF.LogicalOperator_py,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_co);

    /* End of Outputs for SubSystem: '<S439>/Lib_RiseEdgeDetInit' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_py && (!rtb_LogicalOperator8_b)) {
      AppSwcBcm_ARID_DEF.is_c11_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
      LampCtl_AlrmSta = true;
    }

    /* case IN_SetOn: */
  } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts
              != 2) || rtb_LogicalOperator8_b) {
    AppSwcBcm_ARID_DEF.is_c11_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_AlrmSta = false;
  }

  /* End of Chart: '<S419>/Chart' */

  /* RelationalOperator: '<S427>/Relational Operator6' */
  RelationalOperator6_m = LampCtl_AlrmSta;

  /* Logic: '<S427>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator'
   *  RelationalOperator: '<S427>/Relational Operator4'
   *  RelationalOperator: '<S427>/Relational Operator6'
   */
  rtb_LogicalOperator1_ge = (RelationalOperator8_e || LampCtl_AlrmSta ||
    LampCtl_EmerSta || LampCtl_EmerHazardLightSta);

  /* RelationalOperator: '<S438>/Relational Operator' incorporates:
   *  Constant: '<S438>/Constant'
   */
  rtb_RelationalOperator = (LampCtl_RKEReq == 4);

  /* Chart: '<S438>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S328>/Unit Delay'
   *  UnitDelay: '<S328>/Unit Delay1'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c121_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c121_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c121_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_VehSeekSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c121_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 1) {
      AppSwcBcm_ARID_DEF.Lib_blIn_f5 = rtb_RelationalOperator;

      /* Outputs for Function Call SubSystem: '<S521>/Lib_RiseEdgeDet' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_f5,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jr,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h5);

      /* End of Outputs for SubSystem: '<S521>/Lib_RiseEdgeDet' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jr && (!rtb_LogicalOperator1_ge)) {
        AppSwcBcm_ARID_DEF.is_c121_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
        LampCtl_VehSeekSta = true;
      }
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h >= 10) ||
             (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p >= 10) ||
             ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts
              != 1) || rtb_LogicalOperator1_ge) {
    AppSwcBcm_ARID_DEF.is_c121_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_VehSeekSta = false;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_f5 = rtb_RelationalOperator;

    /* Outputs for Function Call SubSystem: '<S521>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_f5,
      &AppSwcBcm_ARID_DEF.LogicalOperator_jr,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h5);

    /* End of Outputs for SubSystem: '<S521>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_jr) {
      AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt =
        !AppSwcBcm_ARID_DEF.LampCtl_VehSeekRpt;
      AppSwcBcm_ARID_DEF.is_c121_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
      LampCtl_VehSeekSta = true;
    }
  }

  /* End of Chart: '<S438>/Chart' */

  /* Chart: '<S420>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S328>/Unit Delay10'
   *  UnitDelay: '<S328>/Unit Delay11'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c16_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c16_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c16_LampCtl_Lib = AppSwcBcm_IN_Off_a;
    LampCtl_AntiLckSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c16_LampCtl_Lib == AppSwcBcm_IN_Off_a) {
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck ||
         (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck) &&
        (!rtb_LogicalOperator1_ge)) {
      AppSwcBcm_ARID_DEF.is_c16_LampCtl_Lib = AppSwcBcm_IN_On_n;
      LampCtl_AntiLckSta = true;
    }

    /* case IN_On: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE >= 3) ||
             rtb_LogicalOperator1_ge || LampCtl_VehSeekSta) {
    AppSwcBcm_ARID_DEF.is_c16_LampCtl_Lib = AppSwcBcm_IN_Off_a;
    LampCtl_AntiLckSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->MechAntiLck ||
             (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->RKEAntiLck) {
    AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_AntiLckRpt;
    AppSwcBcm_ARID_DEF.is_c16_LampCtl_Lib = AppSwcBcm_IN_On_n;
    LampCtl_AntiLckSta = true;
  }

  /* End of Chart: '<S420>/Chart' */

  /* Chart: '<S421>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   * */
  if (AppSwcBcm_ARID_DEF.temporalCounter_i1 < 63U) {
    AppSwcBcm_ARID_DEF.temporalCounter_i1++;
  }

  if (AppSwcBcm_ARID_DEF.is_active_c18_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c18_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c18_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_ArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c18_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_o5 =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 1);

    /* Outputs for Function Call SubSystem: '<S443>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_o5,
      &AppSwcBcm_ARID_DEF.LogicalOperator_cc,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_g);

    /* End of Outputs for SubSystem: '<S443>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_cc ||
         (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 1)))
        && (!rtb_LogicalOperator1_ge)) {
      AppSwcBcm_ARID_DEF.is_c18_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
      AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
      LampCtl_ArmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.temporalCounter_i1 >= 50U) ||
             ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts
              != 1) || LampCtl_VehSeekSta || rtb_LogicalOperator1_ge) {
    AppSwcBcm_ARID_DEF.is_c18_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_ArmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2)
  {
    AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt = !AppSwcBcm_ARID_DEF.LampCtl_ArmedRpt;
    AppSwcBcm_ARID_DEF.is_c18_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
    AppSwcBcm_ARID_DEF.temporalCounter_i1 = 0U;
    LampCtl_ArmedSta = true;
  }

  /* End of Chart: '<S421>/Chart' */

  /* Chart: '<S423>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S328>/Unit Delay8'
   *  UnitDelay: '<S328>/Unit Delay9'
   * */
  if (AppSwcBcm_ARID_DEF.is_active_c23_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c23_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c23_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_DisarmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c23_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_nx =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 0);

    /* Outputs for Function Call SubSystem: '<S457>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_nx,
      &AppSwcBcm_ARID_DEF.LogicalOperator_lc,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_i);

    /* End of Outputs for SubSystem: '<S457>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_lc ||
         (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 0)
          && ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta ==
              1))) && (!rtb_LogicalOperator1_ge)) {
      AppSwcBcm_ARID_DEF.is_c23_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
      LampCtl_DisarmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE >= 3) ||
             ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts
              != 0) || LampCtl_VehSeekSta || rtb_LogicalOperator1_ge) {
    AppSwcBcm_ARID_DEF.is_c23_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_DisarmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 1)
  {
    AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_DisarmedRpt;
    AppSwcBcm_ARID_DEF.is_c23_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
    LampCtl_DisarmedSta = true;
  }

  /* End of Chart: '<S423>/Chart' */

  /* Chart: '<S426>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S328>/Unit Delay6'
   *  UnitDelay: '<S328>/Unit Delay7'
   * */
  if (AppSwcBcm_ARID_DEF.is_active_c63_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c63_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c63_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_PartArmedSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c63_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_df =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 3);

    /* Outputs for Function Call SubSystem: '<S472>/Lib_RiseEdgeDetInit' */
    AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_df,
      &AppSwcBcm_ARID_DEF.LogicalOperator_b3,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_as);

    /* End of Outputs for SubSystem: '<S472>/Lib_RiseEdgeDetInit' */
    if ((AppSwcBcm_ARID_DEF.LogicalOperator_b3 ||
         (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 3)))
        && (!rtb_LogicalOperator1_ge)) {
      AppSwcBcm_ARID_DEF.is_c63_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
      LampCtl_PartArmedSta = true;
    }

    /* case IN_SetOn: */
  } else if ((AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE >= 3) ||
             (AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE >= 3) ||
             ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts
              != 3) || LampCtl_VehSeekSta || rtb_LogicalOperator1_ge) {
    AppSwcBcm_ARID_DEF.is_c63_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_PartArmedSta = false;
  } else if ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->OsLckSta == 2)
  {
    AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt =
      !AppSwcBcm_ARID_DEF.LampCtl_PartArmedRpt;
    AppSwcBcm_ARID_DEF.is_c63_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
    LampCtl_PartArmedSta = true;
  }

  /* End of Chart: '<S426>/Chart' */

  /* RelationalOperator: '<S427>/Relational Operator5' */
  rtb_RelationalOperator = !LampCtl_EmerSta;

  /* RelationalOperator: '<S427>/Relational Operator7' */
  rtb_RelationalOperator7_ke = !LampCtl_AlrmSta;

  /* RelationalOperator: '<S427>/Relational Operator9' incorporates:
   *  Constant: '<S427>/Constant9'
   */
  rtb_RelationalOperator9_c = (AppSwcBcm_ARID_DEF.LampCtl_TurnIndcrDecide == 0);

  /* RelationalOperator: '<S428>/Relational Operator1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  rtb_RelationalOperator1_niw =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSLeTrnLmpSwStVld_flg;

  /* UnitDelay: '<S328>/Unit Delay17' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   *  RelationalOperator: '<S428>/Relational Operator6'
   */
  rtb_UnitDelay17 =
    !(Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
      ())->VIPM_SCSRiTrnLmpSwStVld_flg;

  /* Logic: '<S428>/Logical Operator2' */
  rtb_LogicalOperator2_hr = (rtb_RelationalOperator1_niw || rtb_UnitDelay17);

  /* UnitDelay: '<S328>/Unit Delay17' incorporates:
   *  Constant: '<S428>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S428>/Relational Operator'
   */
  rtb_UnitDelay17 = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
                     ->SysPwrMode == 2);

  /* RelationalOperator: '<S428>/Relational Operator4' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator12'
   */
  rtb_RelationalOperator1_niw = !LampCtl_ArmedSta;

  /* RelationalOperator: '<S428>/Relational Operator5' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator13'
   */
  tmp_0 = !LampCtl_VehSeekSta;

  /* RelationalOperator: '<S428>/Relational Operator2' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator15'
   */
  tmp_1 = !LampCtl_DisarmedSta;

  /* RelationalOperator: '<S428>/Relational Operator3' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator18'
   */
  tmp_2 = !LampCtl_PartArmedSta;

  /* RelationalOperator: '<S428>/Relational Operator7' incorporates:
   *  RelationalOperator: '<S427>/Relational Operator17'
   */
  tmp_3 = !LampCtl_AntiLckSta;

  /* Chart: '<S428>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S428>/Constant2'
   *  Constant: '<S428>/Constant21'
   *  Constant: '<S428>/Constant3'
   *  Logic: '<S428>/Logical Operator'
   *  Logic: '<S428>/Logical Operator1'
   *  RelationalOperator: '<S428>/Relational Operator2'
   *  RelationalOperator: '<S428>/Relational Operator3'
   *  RelationalOperator: '<S428>/Relational Operator4'
   *  RelationalOperator: '<S428>/Relational Operator5'
   *  RelationalOperator: '<S428>/Relational Operator7'
   */
  if (tmp_3 && tmp_1 && tmp_2 && rtb_RelationalOperator1_niw && tmp_0 &&
      rtb_LogicalOperator2_hr && rtb_UnitDelay17) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_k >= 50.0F / (LampCtl_Ts_C * 100.0F)) {
      LampCtl_RodBeamFaultSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_k++;
      AppSwcBcm_ARID_DEF.cnt_heal_d = (uint16)(2.0F / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_k = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_d == 0) {
      LampCtl_RodBeamFaultSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_d--;
    }
  }

  /* End of Chart: '<S428>/LIB_TPD_10ms' */

  /* Chart: '<S437>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c120_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c120_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Init_o;
    LampCtl_VehModeSta = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib) {
     case AppSwcBcm_IN_Init_o:
      LampCtl_VehModeSta = 0U;
      AppSwcBcm_ARID_DEF.Lib_blIn_ou =
        (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum == 1);

      /* Outputs for Function Call SubSystem: '<S514>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_ou,
        &AppSwcBcm_ARID_DEF.LogicalOperator_nf,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_c);

      /* End of Outputs for SubSystem: '<S514>/Lib_RiseEdgeDetInit' */
      rtb_UnitDelay17 = !rtb_LogicalOperator1_ge;
      if (AppSwcBcm_ARID_DEF.LogicalOperator_nf && rtb_UnitDelay17) {
        AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Show;
        LampCtl_VehModeSta = 2U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_jp =
          (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum == 2);

        /* Outputs for Function Call SubSystem: '<S514>/Lib_RiseEdgeDetInit1' */
        AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_jp,
          &AppSwcBcm_ARID_DEF.LogicalOperator_f,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit1);

        /* End of Outputs for SubSystem: '<S514>/Lib_RiseEdgeDetInit1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_f && rtb_UnitDelay17) {
          AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Limit;
          LampCtl_VehModeSta = 3U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_bz =
            (AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d.VIPC_VehHiddenMode_enum ==
             0);

          /* Outputs for Function Call SubSystem: '<S514>/Lib_RiseEdgeDetInit2' */
          AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_bz,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ak,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit2);

          /* End of Outputs for SubSystem: '<S514>/Lib_RiseEdgeDetInit2' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ak && rtb_UnitDelay17) {
            AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Nrm;
            LampCtl_VehModeSta = 1U;
          }
        }
      }
      break;

     case AppSwcBcm_IN_Limit:
      LampCtl_VehModeSta = 3U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 3) ||
          rtb_LogicalOperator1_ge) {
        AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Init_o;
        LampCtl_VehModeSta = 0U;
      }
      break;

     case AppSwcBcm_IN_Nrm:
      LampCtl_VehModeSta = 1U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 1) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 1) ||
          rtb_LogicalOperator1_ge) {
        AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Init_o;
        LampCtl_VehModeSta = 0U;
      }
      break;

     default:
      /* case IN_Show: */
      LampCtl_VehModeSta = 2U;
      if ((AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE >= 2) ||
          (AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE >= 2) ||
          rtb_LogicalOperator1_ge) {
        AppSwcBcm_ARID_DEF.is_c120_LampCtl_Lib = AppSwcBcm_IN_Init_o;
        LampCtl_VehModeSta = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S437>/Chart' */

  /* Chart: '<S430>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S328>/Unit Delay14'
   *  UnitDelay: '<S328>/Unit Delay15'
   * */
  if (AppSwcBcm_ARID_DEF.is_active_c69_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c69_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c69_LampCtl_Lib = AppSwcBcm_IN_SetOff_a;
    LampCtl_TrunkWarnSta = false;
    AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c69_LampCtl_Lib) {
     case AppSwcBcm_IN_Delay_j:
      if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 3)
          || LampCtl_VehSeekSta || rtb_LogicalOperator1_ge) {
        AppSwcBcm_ARID_DEF.is_c69_LampCtl_Lib = AppSwcBcm_IN_SetOff_a;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      } else if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())
                  ->BodyWarnSts == 3) && (AppSwcBcm_ARID_DEF.TrunkWarnCnt >=
                  LampCtl_TrunkWarnTim_C)) {
        AppSwcBcm_ARID_DEF.is_c69_LampCtl_Lib = AppSwcBcm_IN_SetOn_o;
        LampCtl_TrunkWarnSta = true;
      } else {
        tmp = AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1;
        if (AppSwcBcm_ARID_DEF.TrunkWarnCnt + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.TrunkWarnCnt = (uint16)tmp;
      }
      break;

     case AppSwcBcm_IN_SetOff_a:
      AppSwcBcm_ARID_DEF.Lib_blIn_id =
        (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())->TrunkAjarSw;

      /* Outputs for Function Call SubSystem: '<S481>/Lib_RiseEdgeDetInit' */
      AppSwcBcm_Lib_RiseEdgeDetInit_k(AppSwcBcm_ARID_DEF.Lib_blIn_id,
        &AppSwcBcm_ARID_DEF.LogicalOperator_lp,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit_a);

      /* End of Outputs for SubSystem: '<S481>/Lib_RiseEdgeDetInit' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_lp && (!rtb_LogicalOperator1_ge) &&
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts == 3))
      {
        AppSwcBcm_ARID_DEF.is_c69_LampCtl_Lib = AppSwcBcm_IN_Delay_j;
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
          ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts != 3)
          || LampCtl_VehSeekSta || rtb_LogicalOperator1_ge) {
        AppSwcBcm_ARID_DEF.is_c69_LampCtl_Lib = AppSwcBcm_IN_SetOff_a;
        LampCtl_TrunkWarnSta = false;
        AppSwcBcm_ARID_DEF.TrunkWarnCnt = 0U;
      }
      break;
    }
  }

  /* End of Chart: '<S430>/Chart' */

  /* RelationalOperator: '<S427>/Relational Operator10' */
  rtb_UnitDelay17 = LampCtl_ArmedSta;

  /* RelationalOperator: '<S427>/Relational Operator11' */
  rtb_LogicalOperator2_hr = LampCtl_VehSeekSta;

  /* RelationalOperator: '<S427>/Relational Operator14' */
  rtb_RelationalOperator14_h = LampCtl_DisarmedSta;

  /* RelationalOperator: '<S427>/Relational Operator16' */
  rtb_RelationalOperator16_jq = LampCtl_PartArmedSta;

  /* RelationalOperator: '<S427>/Relational Operator1' */
  rtb_RelationalOperator1_cc = LampCtl_RodBeamFaultSta;

  /* RelationalOperator: '<S427>/Relational Operator19' */
  rtb_RelationalOperator19 = LampCtl_AntiLckSta;

  /* Logic: '<S427>/Logical Operator9' incorporates:
   *  Constant: '<S427>/Constant20'
   *  Constant: '<S427>/Constant21'
   *  Constant: '<S427>/Constant23'
   *  RelationalOperator: '<S427>/Relational Operator20'
   *  RelationalOperator: '<S427>/Relational Operator22'
   *  RelationalOperator: '<S427>/Relational Operator3'
   */
  rtb_LogicalOperator9_l = ((LampCtl_VehModeSta == 1) || (LampCtl_VehModeSta ==
    2) || (LampCtl_VehModeSta == 3));

  /* RelationalOperator: '<S427>/Relational Operator23' */
  rtb_RelationalOperator23 = LampCtl_TrunkWarnSta;

  /* Logic: '<S427>/Logical Operator6' incorporates:
   *  Constant: '<S427>/Constant22'
   *  RelationalOperator: '<S427>/Relational Operator2'
   *  RelationalOperator: '<S427>/Relational Operator21'
   *  RelationalOperator: '<S427>/Relational Operator24'
   */
  rtb_RelationalOperator1_niw = (rtb_RelationalOperator1_niw && tmp_0 && tmp_1 &&
    tmp_2 && (!LampCtl_RodBeamFaultSta) && tmp_3 && (LampCtl_VehModeSta == 0) &&
    (!LampCtl_TrunkWarnSta));

  /* RelationalOperator: '<S432>/Relational Operator' incorporates:
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  RelationalOperator: '<S432>/Relational Operator5'
   */
  rtb_RelationalOperator_gn_tmp =
    Rte_IRead_Runbl_AppSwcBcm_20ms_FCLL_TiWngSt_FCLL_TiWngSt();

  /* CCaller: '<S432>/C Caller' incorporates:
   *  Constant: '<S432>/Constant17'
   */
  LampCtl_TurnIndcrLVol = GetHw_TurnIndcrVol(0U);

  /* Switch: '<S432>/Switch' incorporates:
   *  Logic: '<S432>/Logical Operator4'
   *  UnitDelay: '<S328>/Unit Delay16'
   */
  if (LampCtl_TurnIndcrLaneLSw && AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE) {
    /* Switch: '<S432>/Switch1' */
    rtb_Switch1 = LampCtl_TurnIndcrLVol;
  } else {
    /* Switch: '<S432>/Switch1' incorporates:
     *  Constant: '<S432>/Constant20'
     */
    rtb_Switch1 = 2000U;
  }

  /* End of Switch: '<S432>/Switch' */

  /* Chart: '<S432>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S432>/Constant'
   *  Constant: '<S432>/Constant21'
   *  Constant: '<S432>/Constant43'
   *  Constant: '<S432>/Constant44'
   *  Constant: '<S432>/Constant45'
   *  Inport: '<Root>/FCLL_TiWngSt'
   *  Logic: '<S432>/Logical Operator'
   *  RelationalOperator: '<S432>/Relational Operator'
   *  RelationalOperator: '<S432>/Relational Operator1'
   */
  if ((rtb_RelationalOperator_gn_tmp == 1) || (rtb_Switch1 <=
       LampCtl_TurnIndcrOpenCur_C)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_c >= (float32)
         LampCtl_TurnIndcrFLOpenTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrFLOpenTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLOpen = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_c++;
      AppSwcBcm_ARID_DEF.cnt_heal_po = (uint16)((float32)
        LampCtl_TurnIndcrRLOpenTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_c = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_po == 0) {
      LampCtl_TurnIndcrLOpen = false;
    } else if (LampCtl_TurnIndcrRLOpenTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_po--;
    }
  }

  /* End of Chart: '<S432>/LIB_TPD_10ms' */

  /* Chart: '<S432>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S432>/Constant10'
   *  Constant: '<S432>/Constant11'
   *  Constant: '<S432>/Constant4'
   *  Constant: '<S432>/Constant7'
   *  Constant: '<S432>/Constant9'
   *  Logic: '<S432>/Logical Operator2'
   *  RelationalOperator: '<S432>/Relational Operator4'
   *  RelationalOperator: '<S432>/Relational Operator5'
   */
  if ((rtb_RelationalOperator_gn_tmp == 2) || (LampCtl_TurnIndcrShortCur_C <=
       rtb_Switch1)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_gd >= (float32)
         LampCtl_TurnIndcrFLOpenTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrFLOpenTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrLShort = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_gd++;
      AppSwcBcm_ARID_DEF.cnt_heal_f = (uint16)((float32)
        LampCtl_TurnIndcrRLOpenTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_gd = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_f == 0) {
      LampCtl_TurnIndcrLShort = false;
    } else if (LampCtl_TurnIndcrRLOpenTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_f--;
    }
  }

  /* End of Chart: '<S432>/LIB_TPD_10ms2' */

  /* RelationalOperator: '<S432>/Relational Operator2' incorporates:
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  RelationalOperator: '<S432>/Relational Operator6'
   */
  rtb_RelationalOperator_gn_tmp =
    Rte_IRead_Runbl_AppSwcBcm_20ms_FCLR_TiWngSt_FCLR_TiWngSt();

  /* CCaller: '<S432>/C Caller1' incorporates:
   *  Constant: '<S432>/Constant18'
   */
  LampCtl_TurnIndcrRVol = GetHw_TurnIndcrVol(1U);

  /* Switch: '<S432>/Switch1' incorporates:
   *  Logic: '<S432>/Logical Operator5'
   *  UnitDelay: '<S328>/Unit Delay17'
   */
  if (LampCtl_TurnIndcrLaneRSw && AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE) {
    /* Switch: '<S432>/Switch1' */
    rtb_Switch1 = LampCtl_TurnIndcrRVol;
  } else {
    /* Switch: '<S432>/Switch1' incorporates:
     *  Constant: '<S432>/Constant19'
     */
    rtb_Switch1 = 2000U;
  }

  /* End of Switch: '<S432>/Switch1' */

  /* Chart: '<S432>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S432>/Constant1'
   *  Constant: '<S432>/Constant2'
   *  Constant: '<S432>/Constant3'
   *  Constant: '<S432>/Constant5'
   *  Constant: '<S432>/Constant6'
   *  Inport: '<Root>/FCLR_TiWngSt'
   *  Logic: '<S432>/Logical Operator1'
   *  RelationalOperator: '<S432>/Relational Operator2'
   *  RelationalOperator: '<S432>/Relational Operator3'
   */
  if ((rtb_RelationalOperator_gn_tmp == 1) || (rtb_Switch1 <=
       LampCtl_TurnIndcrOpenCur_C)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_m1 >= (float32)
         LampCtl_TurnIndcrFROpenTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrFROpenTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrROpen = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m1++;
      AppSwcBcm_ARID_DEF.cnt_heal_mhm = (uint16)((float32)
        LampCtl_TurnIndcrRROpenTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m1 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mhm == 0) {
      LampCtl_TurnIndcrROpen = false;
    } else if (LampCtl_TurnIndcrRROpenTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mhm--;
    }
  }

  /* End of Chart: '<S432>/LIB_TPD_10ms1' */

  /* Chart: '<S432>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S432>/Constant12'
   *  Constant: '<S432>/Constant13'
   *  Constant: '<S432>/Constant14'
   *  Constant: '<S432>/Constant15'
   *  Constant: '<S432>/Constant16'
   *  Logic: '<S432>/Logical Operator3'
   *  RelationalOperator: '<S432>/Relational Operator6'
   *  RelationalOperator: '<S432>/Relational Operator7'
   */
  if ((rtb_RelationalOperator_gn_tmp == 2) || (LampCtl_TurnIndcrShortCur_C <=
       rtb_Switch1)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b3 >= (float32)
         LampCtl_TurnIndcrFLOpenTimValid_C / (LampCtl_Ts_C * 100.0F)) &&
        (LampCtl_TurnIndcrFLOpenTimValid_C != 0xFFFF)) {
      LampCtl_TurnIndcrRShort = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b3++;
      AppSwcBcm_ARID_DEF.cnt_heal_o4 = (uint16)((float32)
        LampCtl_TurnIndcrRLOpenTimInValid_C / (LampCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b3 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_o4 == 0) {
      LampCtl_TurnIndcrRShort = false;
    } else if (LampCtl_TurnIndcrRLOpenTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_o4--;
    }
  }

  /* End of Chart: '<S432>/LIB_TPD_10ms3' */

  /* Chart: '<S328>/TurnIndcrArb2' incorporates:
   *  Logic: '<S427>/Logical Operator'
   *  Logic: '<S427>/Logical Operator2'
   *  Logic: '<S427>/Logical Operator3'
   *  Logic: '<S427>/Logical Operator4'
   *  Logic: '<S427>/Logical Operator5'
   *  Logic: '<S427>/Logical Operator7'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c102_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c102_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Trans;
    AppSwcBcm_EnFunc();
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib) {
     case AppSwcBcm_IN_Pri1:
      if (!RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri2:
      if (rtb_RelationalOperator || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri2Func();
      }
      break;

     case AppSwcBcm_IN_Pri3:
      if (rtb_RelationalOperator7_ke || rtb_LogicalOperator8_b) {
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri1Func();
      }
      break;

     case AppSwcBcm_IN_Pri4:
      if (rtb_RelationalOperator9_c || RelationalOperator6_m ||
          RelationalOperator4_l || RelationalOperator) {
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        AppSwcBcm_Pri4Func();
      }
      break;

     case AppSwcBcm_IN_Pri5:
      if (rtb_RelationalOperator1_niw || rtb_LogicalOperator1_ge) {
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_NO_ACTIVE_CHILD;
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Trans;
        AppSwcBcm_EnFunc();
      } else {
        switch (AppSwcBcm_ARID_DEF.is_Pri5) {
         case AppSwcBcm_IN_AntiLck:
          if (!LampCtl_AntiLckSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_AntiLckFunc();
          }
          break;

         case AppSwcBcm_IN_Armed:
          if (!LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_ArmedFunc();
          }
          break;

         case AppSwcBcm_IN_Disarmed:
          if (!LampCtl_DisarmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_DisarmedFunc();
          }
          break;

         case AppSwcBcm_IN_PartArmed:
          if (!LampCtl_PartArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_PartArmedFunc();
          }
          break;

         case AppSwcBcm_IN_RodBeam:
          if (!LampCtl_RodBeamFaultSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_RodBeamFunc();
          }
          break;

         case AppSwcBcm_IN_Seek:
          if (!LampCtl_VehSeekSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_SeekFunc();
          }
          break;

         case AppSwcBcm_IN_Trans_a:
          if (LampCtl_ArmedSta) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Armed;
          } else if (LampCtl_PartArmedSta) {
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
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
            AppSwcBcm_TurnFunc();
          } else {
            AppSwcBcm_TrunkWarnFunc();
          }
          break;

         default:
          /* case IN_VehMode: */
          if (LampCtl_VehModeSta == 0) {
            AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
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
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Pri1;
      } else if (RelationalOperator4_l) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Pri2;
      } else if (RelationalOperator6_m) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Pri3;
      } else if (RelationalOperator8_e) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Pri4;
      } else if (rtb_UnitDelay17 || rtb_LogicalOperator2_hr ||
                 rtb_RelationalOperator14_h || rtb_RelationalOperator16_jq ||
                 rtb_RelationalOperator1_cc || rtb_RelationalOperator19 ||
                 rtb_LogicalOperator9_l || rtb_RelationalOperator23) {
        AppSwcBcm_TurnFunc();
        AppSwcBcm_ARID_DEF.is_c102_LampCtl_Lib = AppSwcBcm_IN_Pri5;
        AppSwcBcm_ARID_DEF.is_Pri5 = AppSwcBcm_IN_Trans_a;
        AppSwcBcm_TurnFunc();
      }
      break;
    }
  }

  /* End of Chart: '<S328>/TurnIndcrArb2' */
  AppSwcBcm_ARID_DEF.Lib_blIn_ieo = LampCtl_TurnIndcrRst;

  /* Chart: '<S433>/LIB_Pulse' incorporates:
   *  SubSystem: '<S504>/Lib_BothEdgeDet'
   */
  /* Outputs for Atomic SubSystem: '<S505>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.Lib_blIn_ieo,
    &AppSwcBcm_ARID_DEF.LogicalOperator2_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet_p);

  /* End of Outputs for SubSystem: '<S505>/Lib_BothEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator2_p) {
    AppSwcBcm_ARID_DEF.cnt_p = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  if (LampCtl_TurnIndcrLFlashCnt >= 1) {
    if (LampCtl_TurnIndcrLFlashCnt >= 65535) {
      LampCtl_PrdSucCntL = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_kg = (AppSwcBcm_ARID_DEF.cnt_p <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_p >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_p = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_p + 1;
        if (AppSwcBcm_ARID_DEF.cnt_p + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_p = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntL < LampCtl_TurnIndcrLFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_kg = (AppSwcBcm_ARID_DEF.cnt_p <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_p >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_p = 0U;
        tmp = LampCtl_PrdSucCntL + 1;
        if (LampCtl_PrdSucCntL + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntL = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_p + 1;
        if (AppSwcBcm_ARID_DEF.cnt_p + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_p = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_kg = false;
    AppSwcBcm_ARID_DEF.cnt_p = 0U;
    LampCtl_PrdSucCntL = 0U;
  }

  AppSwcBcm_ARID_DEF.Lib_blIn_md = LampCtl_TurnIndcrRst;

  /* Chart: '<S435>/LIB_Pulse' incorporates:
   *  SubSystem: '<S511>/Lib_EdgeChgDet'
   */
  AppSwcBcm_Lib_EdgeChgDet(AppSwcBcm_ARID_DEF.Lib_blIn_md,
    &AppSwcBcm_ARID_DEF.RelationalOperator_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_EdgeChgDet);
  if (AppSwcBcm_ARID_DEF.RelationalOperator_f) {
    AppSwcBcm_ARID_DEF.cnt_d = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  if (LampCtl_TurnIndcrRFlashCnt >= 1) {
    if (LampCtl_TurnIndcrRFlashCnt >= 65535) {
      LampCtl_PrdSucCntR = 0U;
      AppSwcBcm_ARID_DEF.LIB_blOut_n = (AppSwcBcm_ARID_DEF.cnt_d <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_d >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_d = 0U;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_d + 1;
        if (AppSwcBcm_ARID_DEF.cnt_d + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_d = (uint16)tmp;
      }
    } else if (LampCtl_PrdSucCntR < LampCtl_TurnIndcrRFlashCnt) {
      AppSwcBcm_ARID_DEF.LIB_blOut_n = (AppSwcBcm_ARID_DEF.cnt_d <
        LampCtl_TurnIndcrWdt);
      if (AppSwcBcm_ARID_DEF.cnt_d >= LampCtl_TurnIndcrPrd - 1) {
        AppSwcBcm_ARID_DEF.cnt_d = 0U;
        tmp = LampCtl_PrdSucCntR + 1;
        if (LampCtl_PrdSucCntR + 1 > 65535) {
          tmp = 65535;
        }

        LampCtl_PrdSucCntR = (uint16)tmp;
      } else {
        tmp = AppSwcBcm_ARID_DEF.cnt_d + 1;
        if (AppSwcBcm_ARID_DEF.cnt_d + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.cnt_d = (uint16)tmp;
      }
    }
  } else {
    AppSwcBcm_ARID_DEF.LIB_blOut_n = false;
    AppSwcBcm_ARID_DEF.cnt_d = 0U;
    LampCtl_PrdSucCntR = 0U;
  }

  /* Chart: '<S422>/Chart' incorporates:
   *  Inport: '<Root>/IPM_SRS_1_Status_CHA'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c20_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c20_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c20_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
    LampCtl_CrashSta = false;
    AppSwcBcm_ARID_DEF.PwrOffFlg = false;
    AppSwcBcm_ARID_DEF.PwrOnFlg = false;
  } else if (AppSwcBcm_ARID_DEF.is_c20_LampCtl_Lib == AppSwcBcm_IN_CrashOff) {
    AppSwcBcm_ARID_DEF.Lib_blIn_co =
      (((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
         ())->VIPM_SRSCrashOutputSts_enum == 1) ||
       ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
         ())->VIPM_SRSCrashOutputSts_enum == 2) ||
       ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
         ())->VIPM_SRSCrashOutputSts_enum == 4) ||
       ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
         ())->VIPM_SRSCrashOutputSts_enum == 5));

    /* Outputs for Function Call SubSystem: '<S446>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_co,
      &AppSwcBcm_ARID_DEF.LogicalOperator_md,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ff);

    /* End of Outputs for SubSystem: '<S446>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_md) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_e3 = (AppSwcBcm_ARID_DEF.CCaller15 == 1);

      /* Outputs for Function Call SubSystem: '<S446>/Lib_RiseEdgeDet2' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_e3,
        &AppSwcBcm_ARID_DEF.LogicalOperator_fcm,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_i);

      /* End of Outputs for SubSystem: '<S446>/Lib_RiseEdgeDet2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_fcm) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_m0 =
          (AppSwcBcm_ARID_DEF.BusCreator12.CrashSta == 1);

        /* Outputs for Function Call SubSystem: '<S446>/Lib_RiseEdgeDet1' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_m0,
          &AppSwcBcm_ARID_DEF.LogicalOperator_kxw,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_f);

        /* End of Outputs for SubSystem: '<S446>/Lib_RiseEdgeDet1' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_kxw) {
          guard1 = true;
        }
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c20_LampCtl_Lib = AppSwcBcm_IN_CrashOn;
      LampCtl_CrashSta = true;
    }

    /* case IN_CrashOn: */
  } else if (AppSwcBcm_ARID_DEF.PwrOffFlg && AppSwcBcm_ARID_DEF.PwrOnFlg) {
    /* ||BSW_EECrshSta==0] */
    AppSwcBcm_ARID_DEF.is_c20_LampCtl_Lib = AppSwcBcm_IN_CrashOff;
    LampCtl_CrashSta = false;
    AppSwcBcm_ARID_DEF.PwrOffFlg = false;
    AppSwcBcm_ARID_DEF.PwrOnFlg = false;
  } else {
    AppSwcBcm_CrashClearFunc();
  }

  /* End of Chart: '<S422>/Chart' */

  /* Chart: '<S429>/Chart' incorporates:
   *  Inport: '<Root>/IPM_BMS_1_MainState_EPT'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c65_LampCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c65_LampCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c65_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
    LampCtl_ThermalrunawaySta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c65_LampCtl_Lib == AppSwcBcm_IN_SetOff_o) {
    AppSwcBcm_ARID_DEF.Lib_blIn_py =
      ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
        ())->VIPM_BMSThermrunawayWrn_enum == 1);

    /* Outputs for Function Call SubSystem: '<S476>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_py,
      &AppSwcBcm_ARID_DEF.LogicalOperator_cif,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ax);

    /* End of Outputs for SubSystem: '<S476>/Lib_RiseEdgeDet' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_cif) {
      AppSwcBcm_ARID_DEF.is_c65_LampCtl_Lib = AppSwcBcm_IN_SetOn_c;
    }
  } else {
    /* case IN_SetOn: */
    guard1 = false;
    if ((Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
         ())->VIPM_BMSThermrunawayWrn_enum == 0) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_ei = LampCtl_HazardLightSw;

      /* Outputs for Function Call SubSystem: '<S476>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ei,
        &AppSwcBcm_ARID_DEF.LogicalOperator_jm,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_e);

      /* End of Outputs for SubSystem: '<S476>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_jm) {
        guard1 = true;
      } else {
        LampCtl_ThermalrunawaySta = true;
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c65_LampCtl_Lib = AppSwcBcm_IN_SetOff_o;
      LampCtl_ThermalrunawaySta = false;
    }
  }

  /* End of Chart: '<S429>/Chart' */

  /* Update for UnitDelay: '<S328>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_j = LampCtl_CrashSta;

  /* Update for UnitDelay: '<S328>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5_DSTATE_n = LampCtl_ThermalrunawaySta;

  /* Update for UnitDelay: '<S328>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_h = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_o = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_h = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_p = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay11' */
  AppSwcBcm_ARID_DEF.UnitDelay11_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay10' */
  AppSwcBcm_ARID_DEF.UnitDelay10_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay9' */
  AppSwcBcm_ARID_DEF.UnitDelay9_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay13' */
  AppSwcBcm_ARID_DEF.UnitDelay13_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay12' */
  AppSwcBcm_ARID_DEF.UnitDelay12_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay15' */
  AppSwcBcm_ARID_DEF.UnitDelay15_DSTATE = LampCtl_PrdSucCntL;

  /* Update for UnitDelay: '<S328>/Unit Delay14' */
  AppSwcBcm_ARID_DEF.UnitDelay14_DSTATE = LampCtl_PrdSucCntR;

  /* Update for UnitDelay: '<S328>/Unit Delay16' */
  AppSwcBcm_ARID_DEF.UnitDelay16_DSTATE = AppSwcBcm_ARID_DEF.LIB_blOut_kg;

  /* Update for UnitDelay: '<S328>/Unit Delay17' */
  AppSwcBcm_ARID_DEF.UnitDelay17_DSTATE = AppSwcBcm_ARID_DEF.LIB_blOut_n;
}

/*
 * System initialize for atomic system:
 *    '<S535>/Lib_RiseEdgeDetInit'
 *    '<S541>/Lib_RiseEdgeDetInit'
 *    '<S614>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_l_Init
  (ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_a_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S536>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S535>/Lib_RiseEdgeDetInit'
 *    '<S541>/Lib_RiseEdgeDetInit'
 *    '<S614>/Lib_RiseEdgeDetInit'
 */
static void AppSwcBcm_Lib_RiseEdgeDetInit_h(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_Lib_RiseEdgeDetInit_AppSwcBcm_a_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S536>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S536>/Logical Operator' incorporates:
   *  Delay: '<S536>/Delay'
   *  Logic: '<S536>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S536>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/*
 * System initialize for atomic system:
 *    '<S525>/LIB_PosPluseInit'
 *    '<S530>/LIB_PosPluseInit'
 */
static void AppSwcBcm_LIB_PosPluseInit_Init(boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluseInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  *rty_LIB_blOut = false;

  /* SystemInitialize for Function Call SubSystem: '<S533>/Lib_RiseEdgeDet' */
  /* SystemInitialize for Atomic SubSystem: '<S535>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_l_Init
    (&AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S535>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S533>/Lib_RiseEdgeDet' */
}

/*
 * Output and update for atomic system:
 *    '<S525>/LIB_PosPluseInit'
 *    '<S530>/LIB_PosPluseInit'
 */
static void AppSwcBcm_LIB_PosPluseInit(boolean rtu_LIB_blEn, uint16
  rtu_LIB_u16Limit, boolean rtu_LIB_blRst, boolean *rty_LIB_blOut,
  ARID_DEF_LIB_PosPluseInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Chart: '<S525>/LIB_PosPluseInit' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blEn;
  AppSwcBcm__ARID_DEF_arg->Lib_blInit = rtu_LIB_blEn;

  /* Outputs for Function Call SubSystem: '<S533>/Lib_RiseEdgeDet' */
  /* Outputs for Atomic SubSystem: '<S535>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_h(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    AppSwcBcm__ARID_DEF_arg->Lib_blInit,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of Outputs for SubSystem: '<S535>/Lib_RiseEdgeDetInit' */
  /* End of Outputs for SubSystem: '<S533>/Lib_RiseEdgeDet' */

  /* Chart: '<S525>/LIB_PosPluseInit' */
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

/* Output and update for atomic system: '<S525>/Lib_RiseEdgeDet' */
static void AppSwcBcm_Lib_RiseEdgeDet_b(void)
{
  /* Logic: '<S534>/Logical Operator' incorporates:
   *  Logic: '<S534>/Logical Operator1'
   *  UnitDelay: '<S534>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_gn = (AppSwcBcm_ARID_DEF.LIB_blOut_b &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mh));

  /* Update for UnitDelay: '<S534>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mh = AppSwcBcm_ARID_DEF.LIB_blOut_b;
}

/* Outputs for atomic system: '<S529>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge(void)
{
  boolean rtb_RelationalOperator1_hz;

  /* RelationalOperator: '<S538>/Relational Operator1' incorporates:
   *  Constant: '<S529>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_hz = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus
    ())->BodyWarnSts == 1);

  /* Logic: '<S538>/Logical Operator' incorporates:
   *  Constant: '<S529>/Constant4'
   *  RelationalOperator: '<S538>/Relational Operator'
   *  UnitDelay: '<S538>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_dy = (rtb_RelationalOperator1_hz &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mz == 0));
}

/* Update for atomic system: '<S529>/Lib_ChangeEdge' */
static void AppSwcBcm_Lib_ChangeEdge_Update(void)
{
  /* Update for UnitDelay: '<S538>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mz =
    (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())->BodyWarnSts;
}

/* System initialize for atomic system: '<S221>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_c;
  boolean rtb_LIB_blOut_ku;

  /* InitializeConditions for UnitDelay: '<S329>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d = 60U;

  /* InitializeConditions for Delay: '<S526>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = true;

  /* SystemInitialize for Chart: '<S525>/LIB_PosPluseInit' */
  AppSwcBcm_LIB_PosPluseInit_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit_j);

  /* SystemInitialize for Chart: '<S529>/LIB_Tim' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_ku);

  /* SystemInitialize for Chart: '<S530>/LIB_PosPluseInit' */
  AppSwcBcm_LIB_PosPluseInit_Init(&rtb_LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit);

  /* SystemInitialize for Chart: '<S530>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_k);
}

/* Outputs for atomic system: '<S221>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_c;
  boolean rtb_LIB_blOut_ku;
  sint32 tmp;
  uint8 tmp_0;
  boolean rtb_LIB_blOut_j;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator2_ai;
  boolean rtb_RelationalOperator1_g;

  /* Logic: '<S530>/Logical Operator2' incorporates:
   *  Constant: '<S524>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S524>/Relational Operator'
   */
  rtb_LogicalOperator2_ai = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S524>/Relational Operator3'
   */
  rtb_RelationalOperator1_g = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->OsLck;

  /* Chart: '<S524>/LIB_Tim' incorporates:
   *  Constant: '<S524>/Constant5'
   *  Logic: '<S524>/Logical Operator1'
   *  Logic: '<S524>/Logical Operator2'
   *  Product: '<S524>/Product'
   *  UnitDelay: '<S329>/Unit Delay1'
   *  UnitDelay: '<S329>/Unit Delay2'
   */
  if ((!rtb_RelationalOperator1_g) && AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c) {
    if (AppSwcBcm_ARID_DEF.Cnt_og <= (uint16)(100U *
         AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d)) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_og + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_og + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_og = (uint16)tmp;
      rtb_LIB_blOut_j = false;
    } else {
      rtb_LIB_blOut_j = true;
    }
  } else {
    rtb_LIB_blOut_j = false;
    AppSwcBcm_ARID_DEF.Cnt_og = 0U;
  }

  /* End of Chart: '<S524>/LIB_Tim' */

  /* RelationalOperator: '<S524>/Relational Operator1' */
  AppSwcBcm_ARID_DEF.RelationalOperator1_m = LampCtl_VehSeekSta;

  /* Outputs for Atomic SubSystem: '<S524>/Lib_RiseEdgeDet3' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet
    (AppSwcBcm_ARID_DEF.RelationalOperator1_m,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet3);

  /* End of Outputs for SubSystem: '<S524>/Lib_RiseEdgeDet3' */

  /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S524>/Relational Operator2'
   */
  rtb_RelationalOperator1_g = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus())
    ->OsUnlck;

  /* Logic: '<S524>/Logical Operator' */
  rtb_LogicalOperator2_ai = (rtb_LIB_blOut_j || rtb_LogicalOperator2_ai ||
    rtb_RelationalOperator1_g || rtb_LogicalOperator);

  /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
   *  Constant: '<S526>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S526>/Relational Operator'
   */
  rtb_RelationalOperator1_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Delay: '<S526>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_g) {
    /* Switch: '<S526>/Switch1' incorporates:
     *  Constant: '<S526>/Constant12'
     *  Constant: '<S526>/Constant13'
     *  RelationalOperator: '<S526>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_b = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_b =
        AppSwcBcm_ARID_DEF.BusCreator12.FlwrMeHomeCtlFb;
    }

    /* End of Switch: '<S526>/Switch1' */
  }

  /* Switch: '<S526>/Switch' incorporates:
   *  Constant: '<S526>/Constant11'
   */
  if (rtb_RelationalOperator1_g) {
    tmp_0 = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUFlwrMeHmCtrl_enum;
  } else {
    tmp_0 = 0U;
  }

  /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
   *  Switch: '<S526>/Switch'
   */
  switch (tmp_0) {
   case 1:
    /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
     *  Constant: '<S526>/Constant6'
     */
    LampCtl_FlwrMeHomeCtlFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
     *  Constant: '<S526>/Constant7'
     */
    LampCtl_FlwrMeHomeCtlFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
     *  Constant: '<S526>/Constant8'
     */
    LampCtl_FlwrMeHomeCtlFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
     *  Constant: '<S526>/Constant9'
     */
    LampCtl_FlwrMeHomeCtlFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
     *  Constant: '<S526>/Constant10'
     */
    LampCtl_FlwrMeHomeCtlFb = 4U;
    break;

   default:
    /* MultiPortSwitch: '<S526>/Multiport Switch1' incorporates:
     *  Delay: '<S526>/Delay'
     */
    LampCtl_FlwrMeHomeCtlFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_b;
    break;
  }

  /* End of MultiPortSwitch: '<S526>/Multiport Switch1' */

  /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
   *  Constant: '<S525>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S525>/Relational Operator3'
   */
  rtb_RelationalOperator1_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())
    ->BodyWarnSts == 1);

  /* Logic: '<S525>/Logical Operator2' incorporates:
   *  Constant: '<S525>/Constant1'
   *  Constant: '<S525>/Constant4'
   *  RelationalOperator: '<S525>/Relational Operator1'
   *  RelationalOperator: '<S525>/Relational Operator4'
   */
  rtb_RelationalOperator1_g = ((LampCtl_FlwrMeHomeCtlFb != 0) &&
    (LampCtl_LightIntstSta == 2) && rtb_RelationalOperator1_g);

  /* Chart: '<S525>/LIB_PosPluseInit' incorporates:
   *  Constant: '<S525>/Constant43'
   *  Logic: '<S525>/Logical Operator'
   */
  AppSwcBcm_LIB_PosPluseInit(rtb_RelationalOperator1_g,
    LampCtl_FlwrMeHomeTimValid_C, !rtb_RelationalOperator1_g,
    &AppSwcBcm_ARID_DEF.LIB_blOut_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit_j);

  /* Outputs for Atomic SubSystem: '<S525>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_b();

  /* End of Outputs for SubSystem: '<S525>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S329>/Lib_SR1' */
  /* Switch: '<S528>/Switch' */
  if (rtb_LogicalOperator2_ai) {
    /* Switch: '<S528>/Switch' incorporates:
     *  Constant: '<S528>/Constant'
     */
    LampCtl_FlwrMeHomeSta = false;
  } else {
    /* Switch: '<S528>/Switch' incorporates:
     *  Logic: '<S528>/Logical Operator'
     *  UnitDelay: '<S528>/Unit Delay'
     */
    LampCtl_FlwrMeHomeSta = (AppSwcBcm_ARID_DEF.LogicalOperator_gn ||
      LampCtl_FlwrMeHomeSta);
  }

  /* End of Switch: '<S528>/Switch' */
  /* End of Outputs for SubSystem: '<S329>/Lib_SR1' */

  /* MultiPortSwitch: '<S526>/Multiport Switch' */
  switch (LampCtl_FlwrMeHomeCtlFb) {
   case 0:
    /* MultiPortSwitch: '<S526>/Multiport Switch' incorporates:
     *  Constant: '<S526>/Constant4'
     */
    LampCtl_FlwrMeHomeTim = 0U;
    break;

   case 1:
    /* MultiPortSwitch: '<S526>/Multiport Switch' incorporates:
     *  Constant: '<S526>/Constant'
     */
    LampCtl_FlwrMeHomeTim = 30U;
    break;

   case 2:
    /* MultiPortSwitch: '<S526>/Multiport Switch' incorporates:
     *  Constant: '<S526>/Constant1'
     */
    LampCtl_FlwrMeHomeTim = 60U;
    break;

   case 3:
    /* MultiPortSwitch: '<S526>/Multiport Switch' incorporates:
     *  Constant: '<S526>/Constant2'
     */
    LampCtl_FlwrMeHomeTim = 90U;
    break;

   case 4:
    /* MultiPortSwitch: '<S526>/Multiport Switch' incorporates:
     *  Constant: '<S526>/Constant3'
     */
    LampCtl_FlwrMeHomeTim = 120U;
    break;
  }

  /* End of MultiPortSwitch: '<S526>/Multiport Switch' */

  /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
   *  Constant: '<S529>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S529>/Relational Operator1'
   */
  rtb_RelationalOperator1_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S530>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S529>/Relational Operator2'
   */
  rtb_LogicalOperator2_ai = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->OsUnlck;

  /* Chart: '<S529>/LIB_Tim' incorporates:
   *  Constant: '<S529>/Constant6'
   *  Logic: '<S529>/Logical Operator1'
   *  Logic: '<S529>/Logical Operator2'
   *  UnitDelay: '<S329>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse((!rtb_LogicalOperator2_ai) &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nm, LampCtl_WelcomeLampTimMax_C,
    &rtb_LIB_blOut_ku, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_m);

  /* Outputs for Atomic SubSystem: '<S529>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge();

  /* End of Outputs for SubSystem: '<S529>/Lib_ChangeEdge' */

  /* Logic: '<S529>/Logical Operator' */
  rtb_LIB_blOut_j = (rtb_LIB_blOut_ku || AppSwcBcm_ARID_DEF.LogicalOperator_dy ||
                     rtb_RelationalOperator1_g);

  /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
   *  Constant: '<S530>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_AlmSysCtl_Bus())
    ->BodyWarnSts == 1);

  /* RelationalOperator: '<S530>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_LogicalOperator2_ai = (Rte_IrvIRead_Runbl_AppSwcBcm_20ms_DoorLckCtl_Bus()
    )->OsUnlck;

  /* Chart: '<S530>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S530>/Constant5'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(rtb_LogicalOperator2_ai, 8,
    &AppSwcBcm_ARID_DEF.LIB_blOut_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay_m);

  /* Logic: '<S530>/Logical Operator2' incorporates:
   *  Constant: '<S530>/Constant'
   *  Constant: '<S530>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S530>/Relational Operator'
   *  RelationalOperator: '<S530>/Relational Operator4'
   */
  rtb_LogicalOperator2_ai = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 0);
  rtb_LogicalOperator2_ai = ((LampCtl_LightIntstSta == 2) &&
    rtb_LogicalOperator2_ai);

  /* Chart: '<S530>/LIB_PosPluseInit' incorporates:
   *  Constant: '<S530>/Constant3'
   *  Logic: '<S530>/Logical Operator'
   *  Logic: '<S530>/Logical Operator1'
   */
  AppSwcBcm_LIB_PosPluseInit(rtb_RelationalOperator1_g &&
    AppSwcBcm_ARID_DEF.LIB_blOut_k && rtb_LogicalOperator2_ai,
    LampCtl_OsUnlckDelayTim_C, !rtb_LogicalOperator2_ai, &rtb_LIB_blOut_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluseInit);

  /* Outputs for Atomic SubSystem: '<S329>/Lib_SR' */
  /* Switch: '<S527>/Switch' */
  if (rtb_LIB_blOut_j) {
    /* Switch: '<S527>/Switch' incorporates:
     *  Constant: '<S527>/Constant'
     */
    LampCtl_WelcomeLampSta = false;
  } else {
    /* Switch: '<S527>/Switch' incorporates:
     *  Logic: '<S527>/Logical Operator'
     *  UnitDelay: '<S527>/Unit Delay'
     */
    LampCtl_WelcomeLampSta = (rtb_LIB_blOut_c || LampCtl_WelcomeLampSta);
  }

  /* End of Switch: '<S527>/Switch' */
  /* End of Outputs for SubSystem: '<S329>/Lib_SR' */
}

/* Update for atomic system: '<S221>/WelcomeLampCtl' */
static void AppSwcBcm_WelcomeLampCtl_Update(void)
{
  /* Update for UnitDelay: '<S329>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_c = LampCtl_FlwrMeHomeSta;

  /* Update for UnitDelay: '<S329>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_d = LampCtl_FlwrMeHomeTim;

  /* Update for Delay: '<S526>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_g = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_b = LampCtl_FlwrMeHomeCtlFb;

  /* Update for UnitDelay: '<S329>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_nm = LampCtl_WelcomeLampSta;

  /* Update for Atomic SubSystem: '<S529>/Lib_ChangeEdge' */
  AppSwcBcm_Lib_ChangeEdge_Update();

  /* End of Update for SubSystem: '<S529>/Lib_ChangeEdge' */
}

/* System initialize for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S221>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/ADASLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/AutoLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/BackLampCtl' */
  AppSwcBcm_BackLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/BackLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/BoxLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/DomeLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/LampDelayCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/LowBeamCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/PosLampCtl' */
  AppSwcBcm_PosLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/PosLampCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/SignalProcess' */
  AppSwcBcm_SignalProcess_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/SignalProcess' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/TurnIndcrCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S221>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S221>/WelcomeLampCtl' */
}

/* Outputs for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl(void)
{
  boolean rtb_DataTypeConversion3_g;

  /* Outputs for Atomic SubSystem: '<S221>/ADASLampCtl' */
  AppSwcBcm_ADASLampCtl();

  /* End of Outputs for SubSystem: '<S221>/ADASLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd3' */
  /* Switch: '<S317>/Switch1' incorporates:
   *  Constant: '<S221>/Constant5'
   */
  if (LampCtl_J420BSDRightCtlOvrdFlg_C) {
    /* Switch: '<S317>/Switch1' incorporates:
     *  Constant: '<S221>/Constant6'
     */
    LampCtl_J420BSDRightCtl = LampCtl_J420BSDRightCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion3' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BSDRightCtlFlg != 0);

    /* Switch: '<S317>/Switch1' incorporates:
     *  Switch: '<S317>/Switch2'
     */
    LampCtl_J420BSDRightCtl = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J420BSDRightCtl);
  }

  /* End of Switch: '<S317>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd4' */
  /* Switch: '<S318>/Switch1' incorporates:
   *  Constant: '<S221>/Constant7'
   */
  if (LampCtl_J422BSDLeftCtlOvrdFlg_C) {
    /* Switch: '<S318>/Switch1' incorporates:
     *  Constant: '<S221>/Constant8'
     */
    LampCtl_J422BSDLeftCtl = LampCtl_J422BSDLeftCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion4' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BSDLeftCtlFlg != 0);

    /* Switch: '<S318>/Switch1' incorporates:
     *  Switch: '<S318>/Switch2'
     */
    LampCtl_J422BSDLeftCtl = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.OutportBufferForLampCtl_J422BSDLeftCtl);
  }

  /* End of Switch: '<S318>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd4' */

  /* Outputs for Atomic SubSystem: '<S221>/SignalProcess' */
  AppSwcBcm_SignalProcess();

  /* End of Outputs for SubSystem: '<S221>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S221>/LightIntstDet' */
  AppSwcBcm_LightIntstDet();

  /* End of Outputs for SubSystem: '<S221>/LightIntstDet' */

  /* Outputs for Atomic SubSystem: '<S221>/AutoLampCtl' */
  AppSwcBcm_AutoLampCtl();

  /* End of Outputs for SubSystem: '<S221>/AutoLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/KnobBeamDig' */
  AppSwcBcm_KnobBeamDig();

  /* End of Outputs for SubSystem: '<S221>/KnobBeamDig' */

  /* Outputs for Atomic SubSystem: '<S221>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl();

  /* End of Outputs for SubSystem: '<S221>/LampDelayCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/PosLampCtl' */
  AppSwcBcm_PosLampCtl();

  /* End of Outputs for SubSystem: '<S221>/PosLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd' */
  /* Switch: '<S309>/Switch1' incorporates:
   *  Constant: '<S221>/Constant18'
   *  Constant: '<S221>/Constant19'
   *  Switch: '<S309>/Switch2'
   */
  if (LampCtl_PosLampStaOvrdFlg_C) {
    LampCtl_PosLampSta = LampCtl_PosLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->PosLampCtlFlg != 0);
    LampCtl_PosLampSta = (rtb_DataTypeConversion3_g ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_km);
  }

  /* End of Switch: '<S309>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd' */

  /* Outputs for Atomic SubSystem: '<S221>/PassLampFunc' */
  AppSwcBcm_PassLampFunc();

  /* End of Outputs for SubSystem: '<S221>/PassLampFunc' */

  /* Outputs for Atomic SubSystem: '<S221>/LowBeamCtl' */
  AppSwcBcm_LowBeamCtl();

  /* End of Outputs for SubSystem: '<S221>/LowBeamCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd5' */
  /* Switch: '<S319>/Switch1' incorporates:
   *  Constant: '<S221>/Constant10'
   *  Constant: '<S221>/Constant9'
   *  Switch: '<S319>/Switch2'
   */
  if (LampCtl_LowBeamStaOvrdFlg_C) {
    LampCtl_LowBeamSta = LampCtl_LowBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion5' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->LowBeamCtlFlg != 0);
    LampCtl_LowBeamSta = (rtb_DataTypeConversion3_g ||
                          AppSwcBcm_ARID_DEF.LIB_bErrFlg_e);
  }

  /* End of Switch: '<S319>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd5' */

  /* Outputs for Atomic SubSystem: '<S221>/BackLampCtl' */
  AppSwcBcm_BackLampCtl();

  /* End of Outputs for SubSystem: '<S221>/BackLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd14' */
  /* Switch: '<S315>/Switch1' incorporates:
   *  Constant: '<S221>/Constant30'
   */
  if (LampCtl_J408BackLampPWMOvrdFlg_C) {
    /* Switch: '<S315>/Switch1' incorporates:
     *  Constant: '<S221>/Constant29'
     */
    LampCtl_J408BackLampPWM = LampCtl_J408BackLampPWMOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion14' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BackLampCtlFlg != 0);

    /* Switch: '<S315>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S315>/Switch1' incorporates:
       *  Constant: '<S221>/Constant32'
       */
      LampCtl_J408BackLampPWM = 100U;
    } else {
      /* Switch: '<S315>/Switch1' */
      LampCtl_J408BackLampPWM = AppSwcBcm_ARID_DEF.Switch_a;
    }

    /* End of Switch: '<S315>/Switch2' */
  }

  /* End of Switch: '<S315>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd14' */

  /* Outputs for Atomic SubSystem: '<S221>/FogLampRCtl' */
  AppSwcBcm_FogLampRCtl();

  /* End of Outputs for SubSystem: '<S221>/FogLampRCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd6' */
  /* Switch: '<S320>/Switch1' incorporates:
   *  Constant: '<S221>/Constant12'
   */
  if (LampCtl_FogLampRStaOvrdFlg_C) {
    /* Switch: '<S320>/Switch1' incorporates:
     *  Constant: '<S221>/Constant11'
     */
    LampCtl_FogLampRSta = LampCtl_FogLampRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion6' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->FogLampRCtlFlg != 0);

    /* Switch: '<S320>/Switch1' incorporates:
     *  Switch: '<S320>/Switch2'
     */
    LampCtl_FogLampRSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LampCtl_FogLampRSta_c);
  }

  /* End of Switch: '<S320>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd6' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd7' */
  /* Switch: '<S321>/Switch1' incorporates:
   *  Constant: '<S221>/Constant14'
   */
  if (LampCtl_FogLampFStaOvrdFlg_C) {
    /* Switch: '<S321>/Switch1' incorporates:
     *  Constant: '<S221>/Constant13'
     */
    LampCtl_FogLampFSta = LampCtl_FogLampFStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion7' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->FogLampFCtlFlg != 0);

    /* Switch: '<S321>/Switch1' incorporates:
     *  Switch: '<S321>/Switch2'
     */
    LampCtl_FogLampFSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LampCtl_FogLampFSta_k);
  }

  /* End of Switch: '<S321>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd7' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd9' */
  /* Switch: '<S323>/Switch1' incorporates:
   *  Constant: '<S221>/Constant20'
   */
  if (LampCtl_HiBeamStaOvrdFlg_C) {
    /* Switch: '<S323>/Switch1' incorporates:
     *  Constant: '<S221>/Constant17'
     */
    LampCtl_HiBeamSta = LampCtl_HiBeamStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion9' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->HiBeamCtlFlg != 0);

    /* Switch: '<S323>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S323>/Switch1' incorporates:
       *  Switch: '<S323>/Switch2'
       */
      LampCtl_HiBeamSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S221>/HiBeamCtl' */
      AppSwcBcm_HiBeamCtl();

      /* End of Outputs for SubSystem: '<S221>/HiBeamCtl' */

      /* Switch: '<S323>/Switch1' incorporates:
       *  Switch: '<S323>/Switch2'
       */
      LampCtl_HiBeamSta = AppSwcBcm_ARID_DEF.LogicalOperator_kh;
    }

    /* End of Switch: '<S323>/Switch2' */
  }

  /* End of Switch: '<S323>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd9' */

  /* Outputs for Atomic SubSystem: '<S221>/DayRunLampCtl' */
  AppSwcBcm_DayRunLampCtl();

  /* End of Outputs for SubSystem: '<S221>/DayRunLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd1' */
  /* Switch: '<S310>/Switch1' incorporates:
   *  Constant: '<S221>/Constant1'
   */
  if (LampCtl_DayRunLightStaOvrdFlg_C) {
    /* Switch: '<S310>/Switch1' incorporates:
     *  Constant: '<S221>/Constant2'
     */
    LampCtl_DayRunLightSta = LampCtl_DayRunLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->DayRunLightCtlFlg != 0);

    /* Switch: '<S310>/Switch1' incorporates:
     *  Switch: '<S310>/Switch2'
     *  UnitDelay: '<S349>/Unit Delay'
     */
    LampCtl_DayRunLightSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ezv);
  }

  /* End of Switch: '<S310>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S221>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl();

  /* End of Outputs for SubSystem: '<S221>/BoxLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd13' */
  /* Switch: '<S314>/Switch1' incorporates:
   *  Constant: '<S221>/Constant28'
   */
  if (LampCtl_J449BoxLampOvrdFlg_C) {
    /* Switch: '<S314>/Switch1' incorporates:
     *  Constant: '<S221>/Constant27'
     */
    LampCtl_J449BoxLamp = LampCtl_J449BoxLampOvrdVal_C;
  } else {
    /* Switch: '<S314>/Switch1' incorporates:
     *  Switch: '<S314>/Switch2'
     *  UnitDelay: '<S299>/Unit Delay'
     */
    LampCtl_J449BoxLamp = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0c;
  }

  /* End of Switch: '<S314>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd13' */

  /* Outputs for Atomic SubSystem: '<S221>/TurnIndcrCtl' */
  AppSwcBcm_TurnIndcrCtl();

  /* End of Outputs for SubSystem: '<S221>/TurnIndcrCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl();

  /* End of Outputs for SubSystem: '<S221>/WelcomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd11' */
  /* Switch: '<S312>/Switch1' incorporates:
   *  Constant: '<S221>/Constant23'
   */
  if (LampCtl_TurnIndcrRStaOvrdFlg_C) {
    /* Switch: '<S312>/Switch1' incorporates:
     *  Constant: '<S221>/Constant24'
     */
    LampCtl_TurnIndcrRSta = LampCtl_TurnIndcrRStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion11' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->TurnIndcrRCtlFlg != 0);

    /* Switch: '<S312>/Switch1' incorporates:
     *  Switch: '<S312>/Switch2'
     */
    LampCtl_TurnIndcrRSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LIB_blOut_n);
  }

  /* End of Switch: '<S312>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd11' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd12' */
  /* Switch: '<S313>/Switch1' incorporates:
   *  Constant: '<S221>/Constant25'
   */
  if (LampCtl_TurnIndcrLStaOvrdFlg_C) {
    /* Switch: '<S313>/Switch1' incorporates:
     *  Constant: '<S221>/Constant26'
     */
    LampCtl_TurnIndcrLSta = LampCtl_TurnIndcrLStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion12' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->TurnIndcrLCtlFlg != 0);

    /* Switch: '<S313>/Switch1' incorporates:
     *  Switch: '<S313>/Switch2'
     */
    LampCtl_TurnIndcrLSta = (rtb_DataTypeConversion3_g ||
      AppSwcBcm_ARID_DEF.LIB_blOut_kg);
  }

  /* End of Switch: '<S313>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd12' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd2' */
  /* Switch: '<S316>/Switch1' incorporates:
   *  Constant: '<S221>/Constant3'
   */
  if (LampCtl_BrakeLightStaOvrdFlg_C) {
    /* Switch: '<S316>/Switch1' incorporates:
     *  Constant: '<S221>/Constant4'
     */
    LampCtl_BrakeLightSta = LampCtl_BrakeLightStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->BrakeLightCtlFlg != 0);

    /* Switch: '<S316>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S316>/Switch1' incorporates:
       *  Switch: '<S316>/Switch2'
       */
      LampCtl_BrakeLightSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S221>/BrakeLampCtl' */
      AppSwcBcm_BrakeLampCtl();

      /* End of Outputs for SubSystem: '<S221>/BrakeLampCtl' */

      /* Switch: '<S316>/Switch1' incorporates:
       *  Switch: '<S316>/Switch2'
       */
      LampCtl_BrakeLightSta = AppSwcBcm_ARID_DEF.LogicalOperator_op;
    }

    /* End of Switch: '<S316>/Switch2' */
  }

  /* End of Switch: '<S316>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S221>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl();

  /* End of Outputs for SubSystem: '<S221>/DomeLampCtl' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd10' */
  /* Switch: '<S311>/Switch1' incorporates:
   *  Constant: '<S221>/Constant22'
   */
  if (LampCtl_DomeLampPwmDutyOvrdFlg_C) {
    /* Switch: '<S311>/Switch1' incorporates:
     *  Constant: '<S221>/Constant21'
     */
    LampCtl_DomeLampPwmDuty = LampCtl_DomeLampPwmDutyOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion10' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->DomeLampCtlFlg != 0);

    /* Switch: '<S311>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S311>/Switch1' incorporates:
       *  Constant: '<S221>/Constant31'
       */
      LampCtl_DomeLampPwmDuty = 100U;
    } else {
      /* Switch: '<S311>/Switch1' */
      LampCtl_DomeLampPwmDuty = AppSwcBcm_ARID_DEF.DataTypeConversion;
    }

    /* End of Switch: '<S311>/Switch2' */
  }

  /* End of Switch: '<S311>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd10' */

  /* Outputs for Atomic SubSystem: '<S221>/Ovrd8' */
  /* Switch: '<S322>/Switch1' incorporates:
   *  Constant: '<S221>/Constant16'
   */
  if (LampCtl_ReverseLampStaOvrdFlg_C) {
    /* Switch: '<S322>/Switch1' incorporates:
     *  Constant: '<S221>/Constant15'
     */
    LampCtl_ReverseLampSta = LampCtl_ReverseLampStaOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S221>/Data Type Conversion8' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion3_g = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->ReverseLampCtlFlg != 0);

    /* Switch: '<S322>/Switch2' */
    if (rtb_DataTypeConversion3_g) {
      /* Switch: '<S322>/Switch1' incorporates:
       *  Switch: '<S322>/Switch2'
       */
      LampCtl_ReverseLampSta = true;
    } else {
      /* Outputs for Atomic SubSystem: '<S221>/ReverseLampCtl' */
      AppSwcBcm_ReverseLampCtl();

      /* End of Outputs for SubSystem: '<S221>/ReverseLampCtl' */

      /* Switch: '<S322>/Switch1' incorporates:
       *  Switch: '<S322>/Switch2'
       */
      LampCtl_ReverseLampSta = AppSwcBcm_ARID_DEF.LogicalOperator_pf;
    }

    /* End of Switch: '<S322>/Switch2' */
  }

  /* End of Switch: '<S322>/Switch1' */
  /* End of Outputs for SubSystem: '<S221>/Ovrd8' */
}

/* Update for atomic system: '<S3>/LampCtl' */
static void AppSwcBcm_LampCtl_Update(void)
{
  /* Update for UnitDelay: '<S221>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_jy = LampCtl_WelcomeLampSta;

  /* Update for UnitDelay: '<S221>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_b = LampCtl_FlwrMeHomeSta;

  /* Update for Atomic SubSystem: '<S221>/LampDelayCtl' */
  AppSwcBcm_LampDelayCtl_Update();

  /* End of Update for SubSystem: '<S221>/LampDelayCtl' */

  /* Update for Atomic SubSystem: '<S221>/BoxLampCtl' */
  AppSwcBcm_BoxLampCtl_Update();

  /* End of Update for SubSystem: '<S221>/BoxLampCtl' */

  /* Update for Atomic SubSystem: '<S221>/WelcomeLampCtl' */
  AppSwcBcm_WelcomeLampCtl_Update();

  /* End of Update for SubSystem: '<S221>/WelcomeLampCtl' */

  /* Update for Atomic SubSystem: '<S221>/DomeLampCtl' */
  AppSwcBcm_DomeLampCtl_Update();

  /* End of Update for SubSystem: '<S221>/DomeLampCtl' */
}

/*
 * System initialize for atomic system:
 *    '<S545>/LIB_TPD1'
 *    '<S545>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1_Init(uint8 *rty_LIB_u8ErrFlg)
{
  *rty_LIB_u8ErrFlg = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S545>/LIB_TPD1'
 *    '<S545>/LIB_TPD2'
 */
static void AppSwcBcm_LIB_TPD1(boolean rtu_LIB_blIn, uint16 rtu_LIB_u16tiToDef,
  uint16 rtu_LIB_u16tiToOk, boolean rtu_LIB_blAllowRecov, boolean
  rtu_LIB_blAllowRecov1, uint8 *rty_LIB_u8ErrFlg, ARID_DEF_LIB_TPD1_AppSwcBcm_T *
  AppSwcBcm__ARID_DEF_arg)
{
  boolean guard1 = false;

  /* Chart: '<S545>/LIB_TPD1' */
  AppSwcBcm__ARID_DEF_arg->Lib_blIn = rtu_LIB_blAllowRecov;

  /* Outputs for Function Call SubSystem: '<S558>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn,
    &AppSwcBcm__ARID_DEF_arg->LogicalOperator_l,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet);

  /* End of Outputs for SubSystem: '<S558>/Lib_RiseEdgeDet' */

  /* Chart: '<S545>/LIB_TPD1' */
  guard1 = false;
  if (AppSwcBcm__ARID_DEF_arg->LogicalOperator_l) {
    guard1 = true;
  } else {
    AppSwcBcm__ARID_DEF_arg->Lib_blIn_f = rtu_LIB_blAllowRecov1;

    /* Outputs for Function Call SubSystem: '<S558>/Lib_RiseEdgeDet1' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm__ARID_DEF_arg->Lib_blIn_f,
      &AppSwcBcm__ARID_DEF_arg->LogicalOperator,
      &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_RiseEdgeDet1);

    /* End of Outputs for SubSystem: '<S558>/Lib_RiseEdgeDet1' */
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

/* System initialize for atomic system: '<S222>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt_Init(void)
{
  /* SystemInitialize for Chart: '<S545>/LIB_TPD1' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_b);

  /* SystemInitialize for Chart: '<S545>/LIB_TPD2' */
  AppSwcBcm_LIB_TPD1_Init(&AppSwcBcm_ARID_DEF.LIB_u8ErrFlg);
}

/* Output and update for atomic system: '<S222>/LockedRotorProt' */
static void AppSwcBcm_LockedRotorProt(void)
{
  boolean rtb_LogicalOperator;
  boolean rtb_RelationalOperator3_m;

  /* Logic: '<S545>/Logical Operator' incorporates:
   *  UnitDelay: '<S222>/Unit Delay'
   *  UnitDelay: '<S222>/Unit Delay1'
   */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hy ||
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l);

  /* RelationalOperator: '<S545>/Relational Operator3' incorporates:
   *  Constant: '<S545>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator3_m = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 0);

  /* Chart: '<S545>/LIB_TPD2' incorporates:
   *  Constant: '<S545>/Constant1'
   *  Constant: '<S545>/Constant2'
   *  Logic: '<S545>/Logical Operator1'
   *  RelationalOperator: '<S545>/Relational Operator'
   *  RelationalOperator: '<S545>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(rtb_LogicalOperator && (!WiperCtl_WiperParkPosSw),
                     WiperCtl_LockedRotorTimDef_C, WiperCtl_LockedRotorTimOk_C,
                     WiperCtl_WiperOffSw, rtb_RelationalOperator3_m,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD2);

  /* Chart: '<S545>/LIB_TPD1' incorporates:
   *  Constant: '<S545>/Constant4'
   *  Constant: '<S545>/Constant5'
   *  Logic: '<S545>/Logical Operator3'
   *  RelationalOperator: '<S545>/Relational Operator1'
   *  RelationalOperator: '<S545>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD1(WiperCtl_WiperParkPosSw && rtb_LogicalOperator,
                     WiperCtl_LockedRotorTimParkDef_C,
                     WiperCtl_LockedRotorTimParkOk_C, WiperCtl_WiperOffSw,
                     rtb_RelationalOperator3_m,
                     &AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_b,
                     &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD1);

  /* Logic: '<S545>/Logical Operator2' */
  WiperCtl_LockedRotorProtSta = ((AppSwcBcm_ARID_DEF.LIB_u8ErrFlg_b != 0) ||
    (AppSwcBcm_ARID_DEF.LIB_u8ErrFlg != 0));
}

/* Output and update for atomic system: '<S222>/SignalProcess' */
static void AppSwcBcm_SignalProcess_d(void)
{
  uint16 rtb_y;
  uint8 rtb_Switch5_c;
  boolean rtb_Switch1;

  /* Outputs for Atomic SubSystem: '<S549>/Bit Shift5' */
  /* Constant: '<S549>/Constant59' */
  rtb_y = AppSwcBcm_BitShift3(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S549>/Bit Shift5' */

  /* Switch: '<S549>/Switch5' incorporates:
   *  RelationalOperator: '<S549>/Relational Operator'
   *  S-Function (sfix_bitop): '<S549>/Bitwise AND5'
   *  Switch: '<S549>/Switch'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S549>/Switch5' incorporates:
     *  Constant: '<S549>/Constant60'
     */
    rtb_Switch5_c = WiperCtl_WiperSwVal_C;
  } else if (SCS_WiprSwtStVD) {
    /* Switch: '<S549>/Switch' incorporates:
     *  Switch: '<S549>/Switch5'
     */
    rtb_Switch5_c = SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S549>/Switch5' incorporates:
     *  Constant: '<S549>/Constant23'
     *  Switch: '<S549>/Switch'
     */
    rtb_Switch5_c = 0U;
  }

  /* End of Switch: '<S549>/Switch5' */

  /* Chart: '<S549>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S549>/Constant14'
   *  Constant: '<S549>/Constant46'
   *  Constant: '<S549>/Constant47'
   *  Constant: '<S549>/Constant49'
   *  RelationalOperator: '<S549>/Relational Operator9'
   */
  if (rtb_Switch5_c == 4) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hp >= (float32)WiperCtl_MistTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_MistTimValid_C != 0xFFFF)) {
      WiperCtl_WiperMistSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hp++;
      AppSwcBcm_ARID_DEF.cnt_heal_oe = (uint16)((float32)
        WiperCtl_MistTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hp = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_oe == 0) {
      WiperCtl_WiperMistSw = false;
    } else if (WiperCtl_MistTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_oe--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms' */

  /* Chart: '<S549>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S549>/Constant1'
   *  Constant: '<S549>/Constant3'
   *  Constant: '<S549>/Constant4'
   *  Constant: '<S549>/Constant5'
   *  RelationalOperator: '<S549>/Relational Operator1'
   */
  if (rtb_Switch5_c == 0) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_fe >= (float32)WiperCtl_OffTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_OffTimValid_C != 0xFFFF)) {
      WiperCtl_WiperOffSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_fe++;
      AppSwcBcm_ARID_DEF.cnt_heal_nq = (uint16)((float32)
        WiperCtl_OffTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_fe = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_nq == 0) {
      WiperCtl_WiperOffSw = false;
    } else if (WiperCtl_OffTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_nq--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms1' */

  /* Chart: '<S549>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S549>/Constant10'
   *  Constant: '<S549>/Constant2'
   *  Constant: '<S549>/Constant8'
   *  Constant: '<S549>/Constant9'
   *  RelationalOperator: '<S549>/Relational Operator2'
   */
  if (rtb_Switch5_c == 1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_a >= (float32)WiperCtl_InrTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_InrTimValid_C != 0xFFFF)) {
      WiperCtl_WiperInrSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_a++;
      AppSwcBcm_ARID_DEF.cnt_heal_gm = (uint16)((float32)
        WiperCtl_InrTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_a = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_gm == 0) {
      WiperCtl_WiperInrSw = false;
    } else if (WiperCtl_InrTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_gm--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms2' */

  /* Chart: '<S549>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S549>/Constant11'
   *  Constant: '<S549>/Constant16'
   *  Constant: '<S549>/Constant17'
   *  Constant: '<S549>/Constant6'
   *  RelationalOperator: '<S549>/Relational Operator3'
   */
  if (rtb_Switch5_c == 2) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_b >= (float32)WiperCtl_LowSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_LowSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperLowSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_b++;
      AppSwcBcm_ARID_DEF.cnt_heal_kg = (uint16)((float32)
        WiperCtl_LowSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_b = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_kg == 0) {
      WiperCtl_WiperLowSpdSw = false;
    } else if (WiperCtl_LowSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_kg--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms3' */

  /* Chart: '<S549>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S549>/Constant18'
   *  Constant: '<S549>/Constant21'
   *  Constant: '<S549>/Constant22'
   *  Constant: '<S549>/Constant7'
   *  RelationalOperator: '<S549>/Relational Operator4'
   */
  if (rtb_Switch5_c == 3) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d0 >= (float32)WiperCtl_HiSpdTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_HiSpdTimValid_C != 0xFFFF)) {
      WiperCtl_WiperHiSpdSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d0++;
      AppSwcBcm_ARID_DEF.cnt_heal_c = (uint16)((float32)
        WiperCtl_HiSpdTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d0 = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_c == 0) {
      WiperCtl_WiperHiSpdSw = false;
    } else if (WiperCtl_HiSpdTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_c--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S549>/Bit Shift1' */
  /* Constant: '<S549>/Constant28' */
  rtb_y = AppSwcBcm_BitShift4(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S549>/Bit Shift1' */

  /* Switch: '<S549>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S549>/Bitwise AND1'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S549>/Switch1' incorporates:
     *  Constant: '<S549>/Constant29'
     */
    rtb_Switch1 = WiperCtl_WashVal_C;
  } else {
    /* Switch: '<S549>/Switch1' incorporates:
     *  RelationalOperator: '<S549>/Relational Operator5'
     *  Switch: '<S549>/Switch3'
     */
    rtb_Switch1 = (SCS_FrntWshrSwtStVD && SCS_FrntWshrSwtSt);
  }

  /* End of Switch: '<S549>/Switch1' */

  /* Chart: '<S549>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S549>/Constant25'
   *  Constant: '<S549>/Constant26'
   *  Constant: '<S549>/Constant27'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_le >= (float32)WiperCtl_WashTimValid_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashTimValid_C != 0xFFFF)) {
      WiperCtl_WashSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_le++;
      AppSwcBcm_ARID_DEF.cnt_heal_g = (uint16)((float32)
        WiperCtl_WashTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_le = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_g == 0) {
      WiperCtl_WashSw = false;
    } else if (WiperCtl_WashTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_g--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S549>/Bit Shift2' */
  /* Constant: '<S549>/Constant35' */
  rtb_y = AppSwcBcm_BitShift7(WiperCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S549>/Bit Shift2' */

  /* Switch: '<S549>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S549>/Bitwise AND2'
   */
  if ((rtb_y & 1U) != 0U) {
    /* Switch: '<S549>/Switch2' incorporates:
     *  Constant: '<S549>/Constant36'
     */
    rtb_Switch1 = WiperCtl_WiperParkPosVal_C;
  } else {
    /* Switch: '<S549>/Switch2' incorporates:
     *  DataTypeConversion: '<S549>/Data Type Conversion2'
     */
    rtb_Switch1 = (BSW_J334WiperParkPos != 0);
  }

  /* End of Switch: '<S549>/Switch2' */

  /* Chart: '<S549>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S549>/Constant32'
   *  Constant: '<S549>/Constant33'
   *  Constant: '<S549>/Constant34'
   *  Logic: '<S549>/Logical Operator5'
   */
  if (!rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_js >= (float32)
         WiperCtl_WiperParkPosTimValid_C / (WiperCtl_Ts_C * 100.0F)) &&
        (WiperCtl_WiperParkPosTimValid_C != 0xFFFF)) {
      WiperCtl_WiperParkPosSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_js++;
      AppSwcBcm_ARID_DEF.cnt_heal_l = (uint16)((float32)
        WiperCtl_WiperPosTimInValid_C / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_js = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_l == 0) {
      WiperCtl_WiperParkPosSw = false;
    } else if (WiperCtl_WiperPosTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_l--;
    }
  }

  /* End of Chart: '<S549>/LIB_TPD_10ms6' */
}

/* System initialize for atomic system: '<S222>/WashCtl' */
static void AppSwcBcm_WashCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S550>/LIB_Tim' */
  AppSwcBcm_LIB_NegPluse_Init(&AppSwcBcm_ARID_DEF.LIB_blOut_i);
}

/* Output and update for atomic system: '<S222>/WashCtl' */
static void AppSwcBcm_WashCtl(void)
{
  boolean rtb_RelationalOperator1_as;

  /* RelationalOperator: '<S550>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator1_as = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Chart: '<S550>/LIB_Tim' incorporates:
   *  Constant: '<S550>/Constant'
   *  Logic: '<S550>/Logical Operator'
   *  RelationalOperator: '<S550>/Relational Operator'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator1_as && WiperCtl_WashSw,
    WiperCtl_WashMaxTim_C, &AppSwcBcm_ARID_DEF.LIB_blOut_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim_c);

  /* Chart: '<S550>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S550>/Constant3'
   *  Constant: '<S550>/Constant34'
   *  Constant: '<S550>/Constant4'
   *  Logic: '<S550>/Logical Operator1'
   *  Logic: '<S550>/Logical Operator2'
   *  RelationalOperator: '<S550>/Relational Operator2'
   *  RelationalOperator: '<S550>/Relational Operator3'
   *  RelationalOperator: '<S550>/Relational Operator4'
   */
  if (AppSwcBcm_ARID_DEF.LIB_blOut_i && (WiperCtl_WiperInrSta ||
       WiperCtl_WiperOffSta) && (!AppSwcBcm_ARID_DEF.UnitDelay8)) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_nh >= (float32)WiperCtl_WashMinTim_C /
         (WiperCtl_Ts_C * 100.0F)) && (WiperCtl_WashMinTim_C != 0xFFFF)) {
      WiperCtl_WashWiperSta = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_nh++;
      AppSwcBcm_ARID_DEF.cnt_heal_b = (uint16)(1.0F / (WiperCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_nh = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_b == 0) {
      WiperCtl_WashWiperSta = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_b--;
    }
  }

  /* End of Chart: '<S550>/LIB_TPD_10ms6' */
}

/*
 * System initialize for function-call system:
 *    '<S583>/Wash.Lib_RiseEdgeDetInit'
 *    '<S583>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit_Init
  (ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S590>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for function-call system:
 *    '<S583>/Wash.Lib_RiseEdgeDetInit'
 *    '<S583>/Wash.Lib_RiseEdgeDetInit1'
 */
static void AppSwcBcm_WashLib_RiseEdgeDetInit(boolean rtu_Lib_blIn, boolean
  rtu_Lib_blInit, boolean *rty_Lib_blOut,
  ARID_DEF_WashLib_RiseEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Delay: '<S590>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blInit;
  }

  /* Logic: '<S590>/Logical Operator' incorporates:
   *  Delay: '<S590>/Delay'
   *  Logic: '<S590>/Logical Operator1'
   */
  *rty_Lib_blOut = (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE));

  /* Update for Delay: '<S590>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
}

/* Function for Chart: '<S551>/Chart' */
static void AppSwcBcm_enter_internal_Inr(void)
{
  WiperCtl_WiperSta = 4U;
  AppSwcBcm_ARID_DEF.cnt = 0U;
  if (WiperCtl_WiperInrSta) {
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
    if ((WiperCtl_InrTim + AppSwcBcm_ARID_DEF.cnt2) - 1 > 0) {
      AppSwcBcm_ARID_DEF.cnt = 1U;
    }
  }
}

/* Function for Chart: '<S551>/Chart' */
static void AppSwcBcm_HiSpdFunc(void)
{
  AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
  AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = true;
  WiperCtl_WiperSta = 3U;
  AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = (WiperCtl_WiperHiSpdSta &&
    (!WiperCtl_WiperOffSta) && AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f);
}

/* Function for Chart: '<S551>/Chart' */
static void AppSwcBcm_Nrm(void)
{
  sint32 tmp;
  boolean tmp_0;
  if (WiperCtl_WashWiperSta) {
    if (AppSwcBcm_ARID_DEF.is_Nrm == AppSwcBcm_IN_Inr) {
      AppSwcBcm_ARID_DEF.cnt = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_m;
    } else {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_m;
    }

    AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Wash;
    WiperCtl_WiperSta = 5U;
    AppSwcBcm_ARID_DEF.after_cnt = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
    AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
    AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
    if (WiperCtl_WiperMistSta || WiperCtl_WiperHiSpdSta ||
        WiperCtl_WiperLowSpdSta) {
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_pl = WiperCtl_WiperInrSta;
      AppSwcBcm_ARID_DEF.Lib_blInit_a = WiperCtl_WiperInrSta;

      /* Outputs for Function Call SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_pl,
        AppSwcBcm_ARID_DEF.Lib_blInit_a, &AppSwcBcm_ARID_DEF.LogicalOperator_oi,
        &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

      /* End of Outputs for SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit1' */
      AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
        AppSwcBcm_ARID_DEF.LogicalOperator_oi;
    }
  } else if (WiperCtl_WiperMaintSta) {
    if (AppSwcBcm_ARID_DEF.is_Nrm == AppSwcBcm_IN_Inr) {
      AppSwcBcm_ARID_DEF.cnt = 0U;
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_m;
    } else {
      AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_NO_ACTIVE_CHILD_m;
    }

    AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Maint;
    WiperCtl_WiperSta = 6U;
    AppSwcBcm_ARID_DEF.Cnt_c = 0U;
    if (WiperCtl_MaintWiperRunTim_C <= 0) {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;

      /* WiperCtl_MaintStaComp=1; */
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
      AppSwcBcm_ARID_DEF.Cnt_c = 1U;

      /* WiperCtl_MaintStaComp=0; */
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_Nrm) {
     case AppSwcBcm_IN_HiSpd:
      if (WiperCtl_WiperLowSpdSta) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
      } else if ((((!WiperCtl_WiperHiSpdSta) || WiperCtl_WiperOffSta) &&
                  WiperCtl_WiperParkPosSw) ||
                 AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;

        /* UnitDelay: '<S222>/Unit Delay2' */
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        }
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
        tmp_0 = !WiperCtl_WiperInrSta;

        /* UnitDelay: '<S222>/Unit Delay2' */
        if (((tmp_0 || WiperCtl_WiperOffSta) && WiperCtl_WiperParkPosSw) ||
            AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
          WiperCtl_WiperSta = 0U;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
          if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2)
              && (!WiperCtl_WiperParkPosSw) &&
              (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
          } else {
            AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
            AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
          }
        } else if (WiperCtl_WiperHiSpdSta && tmp_0) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_HiSpd;
        } else if (tmp_0 && WiperCtl_WiperLowSpdSta) {
          AppSwcBcm_ARID_DEF.cnt = 0U;
          AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_LowSpd;
        } else {
          if (WiperCtl_InrTimChg) {
            AppSwcBcm_ARID_DEF.cnt = 0U;
          }

          if (WiperCtl_WiperInrSta) {
            if (AppSwcBcm_ARID_DEF.cnt == 0) {
              AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
              AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
            } else {
              AppSwcBcm_ARID_DEF.Lib_blIn_eq = WiperCtl_WiperParkPosSw;

              /* Outputs for Function Call SubSystem: '<S583>/Nrm.Inr.Lib_RiseEdgeDet' */
              AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_eq,
                &AppSwcBcm_ARID_DEF.LogicalOperator_ch,
                &AppSwcBcm_ARID_DEF.ARID_DEF_NrmInrLib_RiseEdgeDet);

              /* End of Outputs for SubSystem: '<S583>/Nrm.Inr.Lib_RiseEdgeDet' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_ch) {
                AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
                AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
                AppSwcBcm_ARID_DEF.cnt2 = AppSwcBcm_ARID_DEF.cnt;
              }
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
      /* UnitDelay: '<S222>/Unit Delay2' */
      if ((((!WiperCtl_WiperLowSpdSta) || WiperCtl_WiperOffSta) &&
           WiperCtl_WiperParkPosSw) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
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
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        WiperCtl_WiperSta = 2U;
      }
      break;

     case AppSwcBcm_IN_Mist:
      /* UnitDelay: '<S222>/Unit Delay2' */
      if ((((!WiperCtl_WiperMistSta) || WiperCtl_WiperOffSta) &&
           WiperCtl_WiperParkPosSw) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
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
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
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
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
      }
      break;
    }
  }
}

/* System initialize for atomic system: '<S222>/WiperDrv' */
static void AppSwcBcm_WiperDrv_Init(void)
{
  /* SystemInitialize for Chart: '<S551>/Chart' incorporates:
   *  SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

  /* SystemInitialize for Chart: '<S551>/Chart' incorporates:
   *  SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit1'
   */
  AppSwcBcm_WashLib_RiseEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);
}

/* Output and update for atomic system: '<S222>/WiperDrv' */
static void AppSwcBcm_WiperDrv(void)
{
  sint32 tmp;

  /* Chart: '<S551>/Chart' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S222>/Unit Delay2'
   */
  if (AppSwcBcm_ARID_DEF.is_active_c11_WiperCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_WiperCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Nrm_n;
    AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
    WiperCtl_WiperSta = 0U;
    AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
    if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) && (
         !WiperCtl_WiperParkPosSw) && (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k))
    {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
    } else {
      AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
      AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
    }
  } else {
    switch (AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib) {
     case AppSwcBcm_IN_Maint:
      if ((!WiperCtl_WiperMaintSta) || AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k) {
        AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Nrm_n;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        }
      } else if (AppSwcBcm_ARID_DEF.Cnt_c >= WiperCtl_MaintWiperRunTim_C) {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;

        /* WiperCtl_MaintStaComp=1; */
      } else {
        AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
        AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        AppSwcBcm_ARID_DEF.Cnt_c++;

        /* WiperCtl_MaintStaComp=0; */
      }
      break;

     case AppSwcBcm_IN_Nrm_n:
      AppSwcBcm_Nrm();
      break;

     default:
      /* case IN_Wash: */
      if (((!WiperCtl_WashWiperSta) && AppSwcBcm_ARID_DEF.WiperCtl_WashComp) ||
          AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k ||
          (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0) &&
           WiperCtl_WiperParkPosSw)) {
        AppSwcBcm_ARID_DEF.is_c11_WiperCtl_Lib = AppSwcBcm_IN_Nrm_n;
        AppSwcBcm_ARID_DEF.is_Nrm = AppSwcBcm_IN_Off_d;
        WiperCtl_WiperSta = 0U;
        AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        if (((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2) &&
            (!WiperCtl_WiperParkPosSw) &&
            (!AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k)) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        } else {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = false;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
        }
      } else {
        if (WiperCtl_WashWiperSta) {
          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g = true;
          AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f = false;
          AppSwcBcm_ARID_DEF.last_cnt = WiperCtl_WashAfterNum_C;
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp = false;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_ip = WiperCtl_WiperParkPosSw;

          /* Outputs for Function Call SubSystem: '<S583>/Wash.Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_ip,
            &AppSwcBcm_ARID_DEF.LogicalOperator_ba,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDet);

          /* End of Outputs for SubSystem: '<S583>/Wash.Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_ba) {
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
              AppSwcBcm_ARID_DEF.Lib_blIn_on = WiperCtl_WiperParkPosSw;
              AppSwcBcm_ARID_DEF.Lib_blInit_i = true;

              /* Outputs for Function Call SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit' */
              AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_on,
                true, &AppSwcBcm_ARID_DEF.LogicalOperator_bb,
                &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit);

              /* End of Outputs for SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_bb) {
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
          AppSwcBcm_ARID_DEF.Lib_blIn_pl = WiperCtl_WiperInrSta;
          AppSwcBcm_ARID_DEF.Lib_blInit_a = WiperCtl_WiperInrSta;

          /* Outputs for Function Call SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_WashLib_RiseEdgeDetInit(AppSwcBcm_ARID_DEF.Lib_blIn_pl,
            AppSwcBcm_ARID_DEF.Lib_blInit_a,
            &AppSwcBcm_ARID_DEF.LogicalOperator_oi,
            &AppSwcBcm_ARID_DEF.ARID_DEF_WashLib_RiseEdgeDetInit1);

          /* End of Outputs for SubSystem: '<S583>/Wash.Lib_RiseEdgeDetInit1' */
          AppSwcBcm_ARID_DEF.WiperCtl_WashComp =
            (AppSwcBcm_ARID_DEF.LogicalOperator_oi ||
             AppSwcBcm_ARID_DEF.WiperCtl_WashComp);
        }
      }
      break;
    }
  }

  /* End of Chart: '<S551>/Chart' */
}

/* Output and update for atomic system: '<S222>/WiperHiSpdCtl' */
static void AppSwcBcm_WiperHiSpdCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S552>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S552>/Logical Operator' incorporates:
   *  RelationalOperator: '<S552>/Relational Operator1'
   *  RelationalOperator: '<S552>/Relational Operator2'
   */
  WiperCtl_WiperHiSpdSta = (rtb_RelationalOperator && WiperCtl_WiperHiSpdSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay4));
}

/* System initialize for atomic system: '<S222>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl_Init(void)
{
  /* InitializeConditions for Delay: '<S553>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_ol = true;

  /* InitializeConditions for Delay: '<S553>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_a = true;
}

/* Output and update for atomic system: '<S222>/WiperInrCtl' */
static void AppSwcBcm_WiperInrCtl(void)
{
  uint8 rtb_Switch_g4;
  boolean rtb_RelationalOperator5_da;

  /* RelationalOperator: '<S553>/Relational Operator5' incorporates:
   *  Constant: '<S553>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S553>/Relational Operator'
   */
  rtb_RelationalOperator5_da = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Logic: '<S553>/Logical Operator' incorporates:
   *  RelationalOperator: '<S553>/Relational Operator2'
   */
  WiperCtl_WiperInrSta = (rtb_RelationalOperator5_da && WiperCtl_WiperInrSw && (
    !AppSwcBcm_ARID_DEF.UnitDelay5));

  /* Delay: '<S553>/Delay1' */
  if (AppSwcBcm_ARID_DEF.icLoad_ol) {
    /* Switch: '<S553>/Switch1' incorporates:
     *  Constant: '<S553>/Constant20'
     *  Constant: '<S553>/Constant8'
     *  RelationalOperator: '<S553>/Relational Operator4'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.InrTim == 255) {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrLvl3Tim_C;
    } else {
      AppSwcBcm_ARID_DEF.Delay1_DSTATE = AppSwcBcm_ARID_DEF.BusCreator12.InrTim;
    }

    /* End of Switch: '<S553>/Switch1' */
  }

  /* RelationalOperator: '<S553>/Relational Operator5' incorporates:
   *  Constant: '<S553>/Constant18'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S553>/Relational Operator3'
   */
  rtb_RelationalOperator5_da = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus()
    )->SysPwrMode == 2);

  /* Switch: '<S553>/Switch' */
  if (rtb_RelationalOperator5_da) {
    /* Switch: '<S553>/Switch' */
    rtb_Switch_g4 = AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUWiprIntlTmSet_enum;
  } else {
    /* Switch: '<S553>/Switch' incorporates:
     *  Constant: '<S553>/Constant19'
     */
    rtb_Switch_g4 = 0U;
  }

  /* End of Switch: '<S553>/Switch' */

  /* MultiPortSwitch: '<S553>/Multiport Switch' incorporates:
   *  Constant: '<S553>/Constant1'
   *  Constant: '<S553>/Constant2'
   *  Constant: '<S553>/Constant3'
   *  Constant: '<S553>/Constant4'
   *  Constant: '<S553>/Constant5'
   *  Constant: '<S553>/Constant6'
   *  Constant: '<S553>/Constant7'
   *  Delay: '<S553>/Delay1'
   */
  switch (rtb_Switch_g4) {
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

  /* End of MultiPortSwitch: '<S553>/Multiport Switch' */

  /* RelationalOperator: '<S553>/Relational Operator1' incorporates:
   *  UnitDelay: '<S553>/Unit Delay'
   */
  WiperCtl_InrTimChg = (WiperCtl_InrTim != AppSwcBcm_ARID_DEF.UnitDelay_DSTATE);

  /* Delay: '<S553>/Delay2' */
  if (AppSwcBcm_ARID_DEF.icLoad_a) {
    /* Switch: '<S553>/Switch2' incorporates:
     *  Constant: '<S553>/Constant15'
     *  Constant: '<S553>/Constant21'
     *  RelationalOperator: '<S553>/Relational Operator5'
     */
    if (AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay2_DSTATE =
        AppSwcBcm_ARID_DEF.BusCreator12.WiperIntlTimeSetFb;
    }

    /* End of Switch: '<S553>/Switch2' */
  }

  /* MultiPortSwitch: '<S553>/Multiport Switch1' */
  switch (rtb_Switch_g4) {
   case 1:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant9'
     */
    WiperCtl_WiprIntlTimeSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant16'
     */
    WiperCtl_WiprIntlTimeSetFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant10'
     */
    WiperCtl_WiprIntlTimeSetFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant11'
     */
    WiperCtl_WiprIntlTimeSetFb = 3U;
    break;

   case 5:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant12'
     */
    WiperCtl_WiprIntlTimeSetFb = 4U;
    break;

   case 6:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant13'
     */
    WiperCtl_WiprIntlTimeSetFb = 5U;
    break;

   case 7:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Constant: '<S553>/Constant14'
     */
    WiperCtl_WiprIntlTimeSetFb = 6U;
    break;

   default:
    /* MultiPortSwitch: '<S553>/Multiport Switch1' incorporates:
     *  Delay: '<S553>/Delay2'
     */
    WiperCtl_WiprIntlTimeSetFb = AppSwcBcm_ARID_DEF.Delay2_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S553>/Multiport Switch1' */

  /* Update for Delay: '<S553>/Delay1' */
  AppSwcBcm_ARID_DEF.icLoad_ol = false;
  AppSwcBcm_ARID_DEF.Delay1_DSTATE = WiperCtl_InrTim;

  /* Update for UnitDelay: '<S553>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE = WiperCtl_InrTim;

  /* Update for Delay: '<S553>/Delay2' */
  AppSwcBcm_ARID_DEF.icLoad_a = false;
  AppSwcBcm_ARID_DEF.Delay2_DSTATE = WiperCtl_WiprIntlTimeSetFb;
}

/* Output and update for atomic system: '<S222>/WiperLowSpdCtl' */
static void AppSwcBcm_WiperLowSpdCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S554>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S554>/Logical Operator' incorporates:
   *  RelationalOperator: '<S554>/Relational Operator1'
   *  RelationalOperator: '<S554>/Relational Operator2'
   */
  WiperCtl_WiperLowSpdSta = (rtb_RelationalOperator && WiperCtl_WiperLowSpdSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay7));
}

/* Output and update for atomic system: '<S222>/WiperMaintCtl' */
static void AppSwcBcm_WiperMaintCtl(void)
{
  boolean rtb_RelationalOperator6_f;

  /* Chart: '<S555>/MaintOff' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  UnitDelay: '<S555>/Unit Delay'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gk) {
    AppSwcBcm_ARID_DEF.Lib_blIn_d =
      ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 0);

    /* Outputs for Function Call SubSystem: '<S593>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_d,
      &AppSwcBcm_ARID_DEF.LogicalOperator_e5,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m3);

    /* End of Outputs for SubSystem: '<S593>/Lib_RiseEdgeDet' */
    AppSwcBcm_ARID_DEF.Flg_c = (AppSwcBcm_ARID_DEF.LogicalOperator_e5 ||
      AppSwcBcm_ARID_DEF.Flg_c);
    if (AppSwcBcm_ARID_DEF.Flg_c) {
      AppSwcBcm_ARID_DEF.Lib_blIn_ie =
        ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())->SysPwrMode == 2);

      /* Outputs for Function Call SubSystem: '<S593>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_ie,
        &AppSwcBcm_ARID_DEF.LogicalOperator_mn,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_nv);

      /* End of Outputs for SubSystem: '<S593>/Lib_RiseEdgeDet1' */
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff =
        (AppSwcBcm_ARID_DEF.LogicalOperator_mn ||
         AppSwcBcm_ARID_DEF.WiperCtl_MaintOff);
    }
  } else {
    AppSwcBcm_ARID_DEF.Flg_c = false;
    AppSwcBcm_ARID_DEF.WiperCtl_MaintOff = false;
  }

  /* End of Chart: '<S555>/MaintOff' */

  /* Outputs for Atomic SubSystem: '<S555>/Lib_SR' */
  /* Switch: '<S592>/Switch' incorporates:
   *  Constant: '<S555>/Constant2'
   *  Constant: '<S555>/Constant5'
   *  Constant: '<S592>/Constant'
   *  Logic: '<S555>/Logical Operator'
   *  Logic: '<S555>/Logical Operator1'
   *  Logic: '<S592>/Logical Operator'
   *  RelationalOperator: '<S555>/Relational Operator1'
   *  RelationalOperator: '<S555>/Relational Operator2'
   *  RelationalOperator: '<S555>/Relational Operator3'
   *  RelationalOperator: '<S555>/Relational Operator4'
   *  RelationalOperator: '<S555>/Relational Operator5'
   *  UnitDelay: '<S592>/Unit Delay'
   */
  if ((!WiperCtl_WiperOffSw) ||
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 1) ||
      AppSwcBcm_ARID_DEF.WiperCtl_MaintOff) {
    WiperCtl_WiperMaintSta = false;
  } else {
    /* RelationalOperator: '<S555>/Relational Operator6' incorporates:
     *  Constant: '<S555>/Constant3'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
     */
    rtb_RelationalOperator6_f = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
      ->SysPwrMode == 2);
    WiperCtl_WiperMaintSta = (((!AppSwcBcm_ARID_DEF.UnitDelay6) &&
      (AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c.VIPM_HUChgWiprMtMdSwSet_enum == 2) &&
      WiperCtl_WiperParkPosSw && rtb_RelationalOperator6_f) ||
      WiperCtl_WiperMaintSta);
  }

  /* End of Switch: '<S592>/Switch' */
  /* End of Outputs for SubSystem: '<S555>/Lib_SR' */

  /* Update for UnitDelay: '<S555>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_gk = WiperCtl_WiperMaintSta;
}

/* Output and update for atomic system: '<S222>/WiperMistCtl' */
static void AppSwcBcm_WiperMistCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S556>/Relational Operator' incorporates:
   *  Constant: '<S556>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Logic: '<S556>/Logical Operator' incorporates:
   *  RelationalOperator: '<S556>/Relational Operator1'
   *  RelationalOperator: '<S556>/Relational Operator2'
   */
  WiperCtl_WiperMistSta = (rtb_RelationalOperator && WiperCtl_WiperMistSw &&
    (!AppSwcBcm_ARID_DEF.UnitDelay3_o));
}

/* Output and update for atomic system: '<S222>/WiperOffCtl' */
static void AppSwcBcm_WiperOffCtl(void)
{
  boolean rtb_RelationalOperator;

  /* RelationalOperator: '<S557>/Relational Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_PDUCtl_Bus())
    ->SysPwrMode == 0);

  /* Logic: '<S557>/Logical Operator' incorporates:
   *  RelationalOperator: '<S557>/Relational Operator1'
   */
  WiperCtl_WiperOffSta = (rtb_RelationalOperator || WiperCtl_WiperOffSw);
}

/* System initialize for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S222>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt_Init();

  /* End of SystemInitialize for SubSystem: '<S222>/LockedRotorProt' */

  /* SystemInitialize for Atomic SubSystem: '<S222>/WashCtl' */
  AppSwcBcm_WashCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S222>/WashCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S222>/WiperDrv' */
  AppSwcBcm_WiperDrv_Init();

  /* End of SystemInitialize for SubSystem: '<S222>/WiperDrv' */

  /* SystemInitialize for Atomic SubSystem: '<S222>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S222>/WiperInrCtl' */
}

/* Output and update for atomic system: '<S3>/WiperCtl' */
static void AppSwcBcm_WiperCtl(void)
{
  boolean rtb_DataTypeConversion_mm;

  /* SignalConversion: '<S222>/Signal Conversion' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWiprSwtSt =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWiprSwtSt_enum;

  /* SignalConversion: '<S222>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWshrSwtSt =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWshrSwtSt_flg;

  /* SignalConversion: '<S222>/Signal Conversion2' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_FrntWshrSwtStVD =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWshrSwtStVld_flg;

  /* SignalConversion: '<S222>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/IPM_SCS_LeSwitchSts_BOD'
   */
  SCS_WiprSwtStVD =
    (Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
     ())->VIPM_SCSFrntWiprSwtStVld_flg;

  /* Outputs for Atomic SubSystem: '<S222>/SignalProcess' */
  AppSwcBcm_SignalProcess_d();

  /* End of Outputs for SubSystem: '<S222>/SignalProcess' */

  /* UnitDelay: '<S222>/Unit Delay5' */
  AppSwcBcm_ARID_DEF.UnitDelay5 = WiperCtl_LockedRotorProtSta;

  /* Outputs for Atomic SubSystem: '<S222>/WiperInrCtl' */
  AppSwcBcm_WiperInrCtl();

  /* End of Outputs for SubSystem: '<S222>/WiperInrCtl' */

  /* Outputs for Atomic SubSystem: '<S222>/WiperOffCtl' */
  AppSwcBcm_WiperOffCtl();

  /* End of Outputs for SubSystem: '<S222>/WiperOffCtl' */

  /* UnitDelay: '<S222>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8 = AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_g;

  /* Outputs for Atomic SubSystem: '<S222>/WashCtl' */
  AppSwcBcm_WashCtl();

  /* End of Outputs for SubSystem: '<S222>/WashCtl' */

  /* UnitDelay: '<S222>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4 = AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_c;

  /* Outputs for Atomic SubSystem: '<S222>/WiperHiSpdCtl' */
  AppSwcBcm_WiperHiSpdCtl();

  /* End of Outputs for SubSystem: '<S222>/WiperHiSpdCtl' */

  /* UnitDelay: '<S222>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7 = AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_g;

  /* Outputs for Atomic SubSystem: '<S222>/WiperLowSpdCtl' */
  AppSwcBcm_WiperLowSpdCtl();

  /* End of Outputs for SubSystem: '<S222>/WiperLowSpdCtl' */

  /* UnitDelay: '<S222>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_o = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_m;

  /* Outputs for Atomic SubSystem: '<S222>/WiperMistCtl' */
  AppSwcBcm_WiperMistCtl();

  /* End of Outputs for SubSystem: '<S222>/WiperMistCtl' */

  /* UnitDelay: '<S222>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6 = AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_h;

  /* Outputs for Atomic SubSystem: '<S222>/WiperMaintCtl' */
  AppSwcBcm_WiperMaintCtl();

  /* End of Outputs for SubSystem: '<S222>/WiperMaintCtl' */

  /* Outputs for Atomic SubSystem: '<S222>/WiperDrv' */
  AppSwcBcm_WiperDrv();

  /* End of Outputs for SubSystem: '<S222>/WiperDrv' */

  /* Outputs for Atomic SubSystem: '<S222>/Ovrd1' */
  /* Switch: '<S546>/Switch1' incorporates:
   *  Constant: '<S222>/Constant1'
   */
  if (WiperCtl_LowSpdDrvOvrdFlg_C) {
    /* Switch: '<S546>/Switch1' incorporates:
     *  Constant: '<S222>/Constant2'
     */
    WiperCtl_LowSpdDrv = WiperCtl_LowSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S222>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_mm = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperLowSpdCtlFlg != 0);

    /* Switch: '<S546>/Switch1' incorporates:
     *  Switch: '<S546>/Switch2'
     */
    WiperCtl_LowSpdDrv = (rtb_DataTypeConversion_mm ||
                          AppSwcBcm_ARID_DEF.WiperCtl_LowSpdDrv_g);
  }

  /* End of Switch: '<S546>/Switch1' */
  /* End of Outputs for SubSystem: '<S222>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S222>/Ovrd2' */
  /* Switch: '<S547>/Switch1' incorporates:
   *  Constant: '<S222>/Constant3'
   */
  if (WiperCtl_HiSpdDrvOvrdFlg_C) {
    /* Switch: '<S547>/Switch1' incorporates:
     *  Constant: '<S222>/Constant4'
     */
    WiperCtl_HiSpdDrv = WiperCtl_HiSpdDrvOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S222>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_mm = ((Rte_IrvIRead_Runbl_AppSwcBcm_20ms_IODID_Bus()
      )->WiperHiSpdCtlFlg != 0);

    /* Switch: '<S547>/Switch1' incorporates:
     *  Switch: '<S547>/Switch2'
     */
    WiperCtl_HiSpdDrv = (rtb_DataTypeConversion_mm ||
                         AppSwcBcm_ARID_DEF.WiperCtl_HiSpdDrv_f);
  }

  /* End of Switch: '<S547>/Switch1' */
  /* End of Outputs for SubSystem: '<S222>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S222>/Ovrd3' */
  /* Switch: '<S548>/Switch1' incorporates:
   *  Constant: '<S222>/Constant18'
   */
  if (WiperCtl_WashMotorDrvOvrdFlg_C) {
    /* Switch: '<S548>/Switch1' incorporates:
     *  Constant: '<S222>/Constant19'
     */
    WiperCtl_WashMotorDrv = WiperCtl_WashMotorDrvOvrdVal_C;
  } else {
    /* Switch: '<S548>/Switch1' incorporates:
     *  Switch: '<S548>/Switch2'
     */
    WiperCtl_WashMotorDrv = AppSwcBcm_ARID_DEF.LIB_blOut_i;
  }

  /* End of Switch: '<S548>/Switch1' */
  /* End of Outputs for SubSystem: '<S222>/Ovrd3' */

  /* Outputs for Atomic SubSystem: '<S222>/LockedRotorProt' */
  AppSwcBcm_LockedRotorProt();

  /* End of Outputs for SubSystem: '<S222>/LockedRotorProt' */

  /* Update for UnitDelay: '<S222>/Unit Delay8' */
  AppSwcBcm_ARID_DEF.UnitDelay8_DSTATE_g = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S222>/Unit Delay4' */
  AppSwcBcm_ARID_DEF.UnitDelay4_DSTATE_c = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S222>/Unit Delay7' */
  AppSwcBcm_ARID_DEF.UnitDelay7_DSTATE_g = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S222>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_m = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S222>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_k = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S222>/Unit Delay6' */
  AppSwcBcm_ARID_DEF.UnitDelay6_DSTATE_h = WiperCtl_LockedRotorProtSta;

  /* Update for UnitDelay: '<S222>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hy = WiperCtl_LowSpdDrv;

  /* Update for UnitDelay: '<S222>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_l = WiperCtl_HiSpdDrv;
}

/*
 * Output and update for atomic system:
 *    '<S607>/Lib_FailEdgeDet'
 *    '<S610>/Lib_FailEdgeDet'
 *    '<S608>/Lib_FailEdgeDet'
 *    '<S611>/Lib_FailEdgeDet'
 *    '<S609>/Lib_FailEdgeDet'
 */
static void AppSwcBcm_Lib_FailEdgeDet_j(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_l_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Logic: '<S615>/Logical Operator' incorporates:
   *  Logic: '<S615>/Logical Operator1'
   *  UnitDelay: '<S615>/Unit Delay'
   */
  *rty_Lib_blOut = ((!rtu_Lib_blIn) && AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S615>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
}

/*
 * Output and update for function-call system:
 *    '<S606>/Lib_FailEdgeDet'
 *    '<S606>/Lib_FailEdgeDet3'
 *    '<S606>/Lib_FailEdgeDet4'
 *    '<S606>/Lib_FailEdgeDet2'
 */
static void AppSwcBcm_Lib_FailEdgeDet_a(boolean rtu_Lib_blIn, boolean
  *rty_Lib_blOut, ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_b_T
  *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S607>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_j(rtu_Lib_blIn, rty_Lib_blOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S607>/Lib_FailEdgeDet' */
}

/* Output and update for function-call system: '<S606>/Lib_FailEdgeDet1' */
static void AppSwcBcm_Lib_FailEdgeDet1(boolean rtu_Lib_blIn, boolean
  *rty_Lib_lbOut, ARID_DEF_Lib_FailEdgeDet1_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* Outputs for Atomic SubSystem: '<S608>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_j(rtu_Lib_blIn, rty_Lib_lbOut,
    &AppSwcBcm__ARID_DEF_arg->ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S608>/Lib_FailEdgeDet' */
}

/* Function for Chart: '<S598>/AlmSysLogic' */
static void AppSwcBcm_AlmWarn(void)
{
  AppSwcBcm_ARID_DEF.Lib_blIn_lu = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet' */
  AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_lu,
    &AppSwcBcm_ARID_DEF.LogicalOperator_kw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_o);

  /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet' */
  if (AppSwcBcm_ARID_DEF.LogicalOperator_kw) {
    /* Flg=1; */
    AppSwcBcm_ARID_DEF.Cnt_a = 0U;
  } else {
    AppSwcBcm_ARID_DEF.Lib_blIn_h2 = AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet1' */
    AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_h2,
      &AppSwcBcm_ARID_DEF.LogicalOperator_ci,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o);

    /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet1' */
    if (AppSwcBcm_ARID_DEF.LogicalOperator_ci) {
      /* Flg=1; */
      AppSwcBcm_ARID_DEF.Cnt_a = 0U;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_hn = AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

      /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet2' */
      AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_hn,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

      /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet2' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
        /* Flg=1; */
        AppSwcBcm_ARID_DEF.Cnt_a = 0U;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_kg =
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet3' */
        AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_kg,
          &AppSwcBcm_ARID_DEF.LogicalOperator_jo,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

        /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet3' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_jo) {
          /* Flg=1; */
          AppSwcBcm_ARID_DEF.Cnt_a = 0U;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

          /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet4' */
          AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
            &AppSwcBcm_ARID_DEF.LogicalOperator_p,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

          /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet4' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
            /* Flg=1; */
            AppSwcBcm_ARID_DEF.Cnt_a = 0U;
          }
        }
      }
    }
  }

  if (AppSwcBcm_ARID_DEF.Cnt_a >= AlmSysCtl_AlrmTimLimit_C) {
    AlmSysCtl_AlrmWarnTimOut = true;

    /* Flg=0; */
  } else {
    AppSwcBcm_ARID_DEF.Cnt_a++;
    AlmSysCtl_AlrmWarnTimOut = false;
  }
}

/* System initialize for atomic system: '<S598>/AlmSysLogic' */
static void AppSwcBcm_AlmSysLogic_Init(void)
{
  /* SystemInitialize for Function Call SubSystem: '<S606>/Lib_RiseEdgeDetInit' */
  /* SystemInitialize for Atomic SubSystem: '<S614>/Lib_RiseEdgeDetInit' */
  AppSwcBcm_Lib_RiseEdgeDetInit_l_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S614>/Lib_RiseEdgeDetInit' */
  /* End of SystemInitialize for SubSystem: '<S606>/Lib_RiseEdgeDetInit' */
}

/* Output and update for atomic system: '<S598>/AlmSysLogic' */
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

  /* Chart: '<S598>/AlmSysLogic' */
  if (AppSwcBcm_ARID_DEF.is_active_c11_AlmSysCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c11_AlmSysCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Init_a;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    guard6 = false;
    guard7 = false;
    guard8 = false;
    switch (AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib) {
     case AppSwcBcm_IN_Alarm:
      AlmSysCtl_BodyWarnSts = 2U;
      if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
        guard4 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_fj =
          (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 1);

        /* Outputs for Function Call SubSystem: '<S606>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fj,
          &AppSwcBcm_ARID_DEF.LogicalOperator_gq,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_i);

        /* End of Outputs for SubSystem: '<S606>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_gq) {
          guard4 = true;
        } else if (((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
                    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) ||
                   AlmSysCtl_AlrmWarnTimOut) {
          /* UpdateSta(); */
          AppSwcBcm_ARID_DEF.Cnt_a = 0U;
          AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_c;
          AlmSysCtl_BodyWarnSts = 1U;

          /* du:UpdateSta(); */
        } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                   AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                   ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                    (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
          /* UpdateSta(); */
          AppSwcBcm_ARID_DEF.Cnt_a = 0U;
          AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_g;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_AlmWarn();
        }
      }
      break;

     case AppSwcBcm_IN_Armed_c:
      AlmSysCtl_BodyWarnSts = 1U;
      if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
        guard5 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_fj =
          (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 1);

        /* Outputs for Function Call SubSystem: '<S606>/Lib_RiseEdgeDet' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fj,
          &AppSwcBcm_ARID_DEF.LogicalOperator_gq,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_i);

        /* End of Outputs for SubSystem: '<S606>/Lib_RiseEdgeDet' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_gq) {
          guard5 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta == 1) {
          AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_g;
          AlmSysCtl_BodyWarnSts = 3U;

          /* du:UpdateSta(); */
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_lu =
            AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

          /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet' */
          AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_lu,
            &AppSwcBcm_ARID_DEF.LogicalOperator_kw,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_o);

          /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_kw) {
            guard8 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_h2 =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

            /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet1' */
            AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_h2,
              &AppSwcBcm_ARID_DEF.LogicalOperator_ci,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o);

            /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet1' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_ci) {
              guard8 = true;
            } else {
              guard7 = true;
            }
          }
        }
      }
      break;

     case AppSwcBcm_IN_Disarmed_o:
      AlmSysCtl_BodyWarnSts = 0U;
      if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) {
        AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_c;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
      } else if ((AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2) &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                 AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
                 ((!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) ||
                  (!AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw))) {
        AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_g;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
      }
      break;

     case AppSwcBcm_IN_Init_a:
      switch (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.BodyWarnSts) {
       case 1:
        AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_c;
        AlmSysCtl_BodyWarnSts = 1U;

        /* du:UpdateSta(); */
        break;

       case 2:
        AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
        AlmSysCtl_BodyWarnSts = 2U;
        AlmSysCtl_AlrmWarnTimOut = false;
        break;

       case 3:
        AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_PartArmed_g;
        AlmSysCtl_BodyWarnSts = 3U;

        /* du:UpdateSta(); */
        break;

       default:
        AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_o;
        AlmSysCtl_BodyWarnSts = 0U;

        /* du:UpdateSta(); */
        break;
      }
      break;

     default:
      /* case IN_PartArmed: */
      AlmSysCtl_BodyWarnSts = 3U;
      if (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw &&
          (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2)) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_b =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;
        AppSwcBcm_ARID_DEF.Lib_blInit = true;

        /* Outputs for Function Call SubSystem: '<S606>/Lib_RiseEdgeDetInit' */
        /* Outputs for Atomic SubSystem: '<S614>/Lib_RiseEdgeDetInit' */
        AppSwcBcm_Lib_RiseEdgeDetInit_h(AppSwcBcm_ARID_DEF.Lib_blIn_b, true,
          &AppSwcBcm_ARID_DEF.LogicalOperator_n0,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDetInit);

        /* End of Outputs for SubSystem: '<S614>/Lib_RiseEdgeDetInit' */
        /* End of Outputs for SubSystem: '<S606>/Lib_RiseEdgeDetInit' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_n0 &&
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw) {
          guard1 = true;
        } else if (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1) {
          guard2 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_fj =
            (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 1);

          /* Outputs for Function Call SubSystem: '<S606>/Lib_RiseEdgeDet' */
          AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_fj,
            &AppSwcBcm_ARID_DEF.LogicalOperator_gq,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_i);

          /* End of Outputs for SubSystem: '<S606>/Lib_RiseEdgeDet' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_gq) {
            guard2 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_lu =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

            /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet' */
            AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_lu,
              &AppSwcBcm_ARID_DEF.LogicalOperator_kw,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet_o);

            /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_kw) {
              guard3 = true;
            } else {
              AppSwcBcm_ARID_DEF.Lib_blIn_h2 =
                AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

              /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet1' */
              AppSwcBcm_Lib_FailEdgeDet1(AppSwcBcm_ARID_DEF.Lib_blIn_h2,
                &AppSwcBcm_ARID_DEF.LogicalOperator_ci,
                &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1_o);

              /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet1' */
              if (AppSwcBcm_ARID_DEF.LogicalOperator_ci) {
                guard3 = true;
              } else {
                AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
                  AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

                /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet4' */
                AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
                  &AppSwcBcm_ARID_DEF.LogicalOperator_p,
                  &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

                /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet4' */
                if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
                  guard3 = true;
                } else {
                  AppSwcBcm_ARID_DEF.Lib_blIn_i =
                    AppSwcBcm_ARID_DEF.UnitDelay1.IGRlyIIgCls;

                  /* Outputs for Function Call SubSystem: '<S606>/Lib_RiseEdgeDet1' */
                  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_i,
                    &AppSwcBcm_ARID_DEF.LogicalOperator_ci1,
                    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_n);

                  /* End of Outputs for SubSystem: '<S606>/Lib_RiseEdgeDet1' */
                  if (AppSwcBcm_ARID_DEF.LogicalOperator_ci1) {
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
      AppSwcBcm_ARID_DEF.Lib_blIn_i = AppSwcBcm_ARID_DEF.UnitDelay1.IGRlyIIgCls;

      /* Outputs for Function Call SubSystem: '<S606>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_i,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ci1,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_n);

      /* End of Outputs for SubSystem: '<S606>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ci1) {
        guard6 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_hn =
          AppSwcBcm_ARID_DEF.BusCreator4.HoodAjarSw;

        /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet2' */
        AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_hn,
          &AppSwcBcm_ARID_DEF.LogicalOperator_ga,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet2);

        /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_ga) {
          guard6 = true;
        } else {
          AppSwcBcm_ARID_DEF.Lib_blIn_kg =
            AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

          /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet3' */
          AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_kg,
            &AppSwcBcm_ARID_DEF.LogicalOperator_jo,
            &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet3);

          /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet3' */
          if (AppSwcBcm_ARID_DEF.LogicalOperator_jo) {
            guard6 = true;
          } else {
            AppSwcBcm_ARID_DEF.Lib_blIn_g5 =
              AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

            /* Outputs for Function Call SubSystem: '<S606>/Lib_FailEdgeDet4' */
            AppSwcBcm_Lib_FailEdgeDet_a(AppSwcBcm_ARID_DEF.Lib_blIn_g5,
              &AppSwcBcm_ARID_DEF.LogicalOperator_p,
              &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet4);

            /* End of Outputs for SubSystem: '<S606>/Lib_FailEdgeDet4' */
            if (AppSwcBcm_ARID_DEF.LogicalOperator_p) {
              guard6 = true;
            }
          }
        }
      }
    }

    if (guard6) {
      AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_BodyWarnSts = 2U;
      AlmSysCtl_AlrmWarnTimOut = false;
    }

    if (guard5) {
      AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_o;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard4) {
      /* UpdateSta(); */
      AppSwcBcm_ARID_DEF.Cnt_a = 0U;
      AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_o;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard3) {
      AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Alarm;
      AlmSysCtl_BodyWarnSts = 2U;
      AlmSysCtl_AlrmWarnTimOut = false;
    }

    if (guard2) {
      AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Disarmed_o;
      AlmSysCtl_BodyWarnSts = 0U;

      /* du:UpdateSta(); */
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.is_c11_AlmSysCtl_Lib = AppSwcBcm_IN_Armed_c;
      AlmSysCtl_BodyWarnSts = 1U;

      /* du:UpdateSta(); */
    }
  }

  /* End of Chart: '<S598>/AlmSysLogic' */
}

/* System initialize for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S598>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic_Init();
}

/* Output and update for atomic system: '<S4>/AlmSysCtl' */
static void AppSwcBcm_AlmSysCtl(void)
{
  /* DataTypeConversion: '<S598>/Data Type Conversion10' */
  AppSwcBcm_ARID_DEF.DataTypeConversion10 =
    (AppSwcBcm_ARID_DEF.BusCreator14.SKSta != 0);

  /* Chart: '<S598>/AlmSysLogic' */
  AppSwcBcm_AlmSysLogic();
}

/*
 * System initialize for atomic system:
 *    '<S626>/Lib_BothEdgeDetInit'
 *    '<S626>/Lib_BothEdgeDetInit1'
 *    '<S626>/Lib_BothEdgeDetInit2'
 *    '<S626>/Lib_BothEdgeDetInit3'
 */
static void AppSwcBcm_Lib_BothEdgeDetInit_Init
  (ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  /* InitializeConditions for Delay: '<S631>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = true;
}

/*
 * Output and update for atomic system:
 *    '<S626>/Lib_BothEdgeDetInit'
 *    '<S626>/Lib_BothEdgeDetInit1'
 *    '<S626>/Lib_BothEdgeDetInit2'
 *    '<S626>/Lib_BothEdgeDetInit3'
 */
static boolean AppSwcBcm_Lib_BothEdgeDetInit(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_BothEdgeDetInit_AppSwcBcm_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Delay: '<S631>/Delay' */
  if (AppSwcBcm__ARID_DEF_arg->icLoad) {
    AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  }

  /* Logic: '<S631>/Logical Operator2' incorporates:
   *  Delay: '<S631>/Delay'
   *  Logic: '<S631>/Logical Operator1'
   *  Logic: '<S631>/Logical Operator3'
   *  Logic: '<S631>/Logical Operator4'
   *  Logic: '<S631>/Logical Operator5'
   */
  rty_Lib_blOut_0 = ((AppSwcBcm__ARID_DEF_arg->Delay_DSTATE && (!rtu_Lib_blIn)) ||
                     (rtu_Lib_blIn && (!AppSwcBcm__ARID_DEF_arg->Delay_DSTATE)));

  /* Update for Delay: '<S631>/Delay' */
  AppSwcBcm__ARID_DEF_arg->icLoad = false;
  AppSwcBcm__ARID_DEF_arg->Delay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of SystemInitialize for SubSystem: '<S626>/Lib_BothEdgeDetInit' */

  /* SystemInitialize for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit1' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of SystemInitialize for SubSystem: '<S626>/Lib_BothEdgeDetInit1' */

  /* SystemInitialize for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit2' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of SystemInitialize for SubSystem: '<S626>/Lib_BothEdgeDetInit2' */

  /* SystemInitialize for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit3' */
  AppSwcBcm_Lib_BothEdgeDetInit_Init
    (&AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of SystemInitialize for SubSystem: '<S626>/Lib_BothEdgeDetInit3' */

  /* SystemInitialize for Atomic SubSystem: '<S626>/Lib_RiseEdgeDetInit' */
  /* InitializeConditions for Delay: '<S635>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = true;

  /* End of SystemInitialize for SubSystem: '<S626>/Lib_RiseEdgeDetInit' */
}

/* Output and update for atomic system: '<S4>/BatSaveCtl' */
static void AppSwcBcm_BatSaveCtl(void)
{
  sint32 tmp;
  boolean rtb_DataTypeConversion_e;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_lf;
  boolean rtb_RelationalOperator2_gn;
  boolean rtb_RelationalOperator3_hy;
  boolean rtb_RelationalOperator4_fn;

  /* RelationalOperator: '<S626>/Relational Operator' incorporates:
   *  Constant: '<S626>/Constant'
   */
  BatSaveCtl_PwrModeOn = (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2);

  /* RelationalOperator: '<S626>/Relational Operator1' */
  rtb_RelationalOperator1_lf = !AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Outputs for Atomic SubSystem: '<S626>/Lib_RiseEdgeDetInit' */
  /* Delay: '<S635>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_n) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_ch = rtb_RelationalOperator1_lf;
  }

  /* RelationalOperator: '<S625>/Relational Operator4' incorporates:
   *  Delay: '<S635>/Delay'
   */
  rtb_RelationalOperator4_fn = AppSwcBcm_ARID_DEF.Delay_DSTATE_ch;

  /* Logic: '<S635>/Logical Operator' incorporates:
   *  Delay: '<S635>/Delay'
   *  Logic: '<S635>/Logical Operator1'
   */
  BatSaveCtl_DoorUnlckPwrOn = (rtb_RelationalOperator1_lf &&
    (!AppSwcBcm_ARID_DEF.Delay_DSTATE_ch));

  /* Update for Delay: '<S635>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_n = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_ch = rtb_RelationalOperator1_lf;

  /* End of Outputs for SubSystem: '<S626>/Lib_RiseEdgeDetInit' */

  /* Outputs for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit' */
  rtb_RelationalOperator = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit);

  /* End of Outputs for SubSystem: '<S626>/Lib_BothEdgeDetInit' */

  /* Outputs for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit1' */
  rtb_RelationalOperator2_gn = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit1);

  /* End of Outputs for SubSystem: '<S626>/Lib_BothEdgeDetInit1' */

  /* Outputs for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit2' */
  rtb_RelationalOperator3_hy = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit2);

  /* End of Outputs for SubSystem: '<S626>/Lib_BothEdgeDetInit2' */

  /* Outputs for Atomic SubSystem: '<S626>/Lib_BothEdgeDetInit3' */
  rtb_RelationalOperator4_fn = AppSwcBcm_Lib_BothEdgeDetInit
    (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDetInit3);

  /* End of Outputs for SubSystem: '<S626>/Lib_BothEdgeDetInit3' */

  /* Logic: '<S626>/Logical Operator1' */
  BatSaveCtl_DoorChgSta = (rtb_RelationalOperator || rtb_RelationalOperator2_gn ||
    rtb_RelationalOperator3_hy || rtb_RelationalOperator4_fn);

  /* Logic: '<S626>/Logical Operator' */
  BatSaveCtl_PwrOn = (BatSaveCtl_PwrModeOn || BatSaveCtl_DoorUnlckPwrOn ||
                      BatSaveCtl_DoorChgSta);

  /* Chart: '<S625>/LIB_PosPluse' incorporates:
   *  Constant: '<S625>/Constant2'
   *  Constant: '<S625>/Constant4'
   *  Logic: '<S625>/Logical Operator2'
   *  Logic: '<S625>/Logical Operator3'
   *  Logic: '<S625>/Logical Operator5'
   *  Logic: '<S625>/Logical Operator8'
   *  RelationalOperator: '<S625>/Relational Operator'
   *  RelationalOperator: '<S625>/Relational Operator2'
   *  RelationalOperator: '<S625>/Relational Operator3'
   *  RelationalOperator: '<S625>/Relational Operator4'
   */
  if ((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0) &&
      ((!BatSaveCtl_DoorChgSta) && ((AppSwcBcm_ARID_DEF.BusCreator4.InsLckSta !=
         1) && (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta != 1) &&
        (AppSwcBcm_ARID_DEF.BusCreator4.TrunkLckSta != 1)))) {
    if (AppSwcBcm_ARID_DEF.Cnt_f <= BatSaveCtl_DlyTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_f + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_f + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_f = (uint16)tmp;
      BatSaveCtl_PwrModeOff = false;
    } else {
      BatSaveCtl_PwrModeOff = true;
    }
  } else {
    BatSaveCtl_PwrModeOff = false;
    AppSwcBcm_ARID_DEF.Cnt_f = 0U;
  }

  /* End of Chart: '<S625>/LIB_PosPluse' */

  /* RelationalOperator: '<S625>/Relational Operator5' incorporates:
   *  Constant: '<S625>/Constant5'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_k = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2);

  /* Chart: '<S625>/LIB_NegPluse6' incorporates:
   *  SubSystem: '<S627>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_k,
    &AppSwcBcm_ARID_DEF.LogicalOperator_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jz5);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_a) {
    AppSwcBcm_ARID_DEF.Flg_m = true;
    AppSwcBcm_ARID_DEF.Cnt_n = 0U;
  }

  /* RelationalOperator: '<S625>/Relational Operator1' incorporates:
   *  Constant: '<S625>/Constant3'
   */
  if (AppSwcBcm_ARID_DEF.Flg_m && AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw)
  {
    if (AppSwcBcm_ARID_DEF.Cnt_n >= BatSaveCtl_LckDlyTim_C) {
      BatSaveCtl_DoorLckPwrOff = true;
      AppSwcBcm_ARID_DEF.Flg_m = false;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_n++;
      BatSaveCtl_DoorLckPwrOff = false;
    }
  } else {
    AppSwcBcm_ARID_DEF.Cnt_n = 0U;
    BatSaveCtl_DoorLckPwrOff = false;
    AppSwcBcm_ARID_DEF.Flg_m = false;
  }

  /* End of RelationalOperator: '<S625>/Relational Operator1' */

  /* Logic: '<S625>/Logical Operator' */
  BatSaveCtl_PwrOff = (BatSaveCtl_PwrModeOff || BatSaveCtl_DoorLckPwrOff);

  /* Outputs for Atomic SubSystem: '<S599>/Lib_SR' */
  AppSwcBcm_Lib_SR(BatSaveCtl_PwrOn, BatSaveCtl_PwrOff,
                   &rtb_RelationalOperator1_lf,
                   &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_SR);

  /* End of Outputs for SubSystem: '<S599>/Lib_SR' */

  /* Outputs for Atomic SubSystem: '<S599>/Ovrd1' */
  /* Switch: '<S624>/Switch1' incorporates:
   *  Constant: '<S599>/Constant18'
   */
  if (BatSaveCtl_J64SavePwrOvrdFlg_C) {
    /* Switch: '<S624>/Switch1' incorporates:
     *  Constant: '<S599>/Constant19'
     */
    BatSaveCtl_J64SavePwr = BatSaveCtl_J64SavePwrOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S599>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_e = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->BatSaveCtlFlg != 0);

    /* Switch: '<S624>/Switch1' incorporates:
     *  Switch: '<S624>/Switch2'
     */
    BatSaveCtl_J64SavePwr = (rtb_DataTypeConversion_e ||
      rtb_RelationalOperator1_lf);
  }

  /* End of Switch: '<S624>/Switch1' */
  /* End of Outputs for SubSystem: '<S599>/Ovrd1' */
}

/* Output and update for atomic system: '<S4>/DTCCtl' */
static void AppSwcBcm_DTCCtl(void)
{
  uint8 rtb_DataTypeConversion3_c;

  /* DataTypeConversion: '<S600>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S600>/Data Type Conversion'
   */
  rtb_DataTypeConversion3_c = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->TurnIndcrLShort;

  /* CCaller: '<S600>/C Caller' */
  App_Call_Event_DTC_0x900011_SetEventStatus(rtb_DataTypeConversion3_c);

  /* DataTypeConversion: '<S600>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S600>/Data Type Conversion1'
   */
  rtb_DataTypeConversion3_c = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->TurnIndcrLOpen;

  /* CCaller: '<S600>/C Caller1' */
  App_Call_Event_DTC_0x900013_SetEventStatus(rtb_DataTypeConversion3_c);

  /* DataTypeConversion: '<S600>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  DataTypeConversion: '<S600>/Data Type Conversion2'
   */
  rtb_DataTypeConversion3_c = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->TurnIndcrRShort;

  /* CCaller: '<S600>/C Caller2' */
  App_Call_Event_DTC_0x900111_SetEventStatus(rtb_DataTypeConversion3_c);

  /* DataTypeConversion: '<S600>/Data Type Conversion3' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_DataTypeConversion3_c = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->TurnIndcrROpen;

  /* CCaller: '<S600>/C Caller3' */
  App_Call_Event_DTC_0x900113_SetEventStatus(rtb_DataTypeConversion3_c);

  /* CCaller: '<S600>/C Caller10' */
  App_Call_Event_DTC_0x900711_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller11' */
  App_Call_Event_DTC_0x900811_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller12' */
  App_Call_Event_DTC_0x900923_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller13' */
  App_Call_Event_DTC_0x900924_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller14' */
  App_Call_Event_DTC_0x900A23_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller15' */
  App_Call_Event_DTC_0x900A24_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller16' */
  App_Call_Event_DTC_0x900B23_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller17' */
  App_Call_Event_DTC_0x900B24_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller18' */
  App_Call_Event_DTC_0x900C23_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller19' */
  App_Call_Event_DTC_0x900C24_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller20' */
  App_Call_Event_DTC_0x900D23_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller21' */
  App_Call_Event_DTC_0x900D24_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller22' */
  App_Call_Event_DTC_0x900E23_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller23' */
  App_Call_Event_DTC_0x900E24_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller24' */
  App_Call_Event_DTC_0x901016_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller25' */
  App_Call_Event_DTC_0x901031_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller27' */
  App_Call_Event_DTC_0x901231_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller29' */
  App_Call_Event_DTC_0x901331_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller30' */
  App_Call_Event_DTC_0x90141C_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller31' */
  App_Call_Event_DTC_0x901116_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller32' */
  App_Call_Event_DTC_0x901216_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller33' */
  App_Call_Event_DTC_0x901316_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller34' */
  App_Call_Event_DTC_0x901131_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller4' */
  App_Call_Event_DTC_0x900211_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller5' */
  App_Call_Event_DTC_0x900213_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller6' */
  App_Call_Event_DTC_0x900311_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller7' */
  App_Call_Event_DTC_0x900313_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller8' */
  App_Call_Event_DTC_0x900412_SetEventStatus(0U);

  /* CCaller: '<S600>/C Caller9' */
  App_Call_Event_DTC_0x900512_SetEventStatus(0U);
}

/* Function for Chart: '<S601>/DoorDrv' */
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

/* Function for Chart: '<S601>/DoorDrv' */
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

/* Function for Chart: '<S601>/DoorDrv' */
static void AppSwcBcm_InsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_f = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S636>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_f,
    &AppSwcBcm_ARID_DEF.LogicalOperator_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ju);

  /* End of Outputs for SubSystem: '<S636>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_c ||
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

/* Function for Chart: '<S601>/DoorDrv' */
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

/* Function for Chart: '<S601>/DoorDrv' */
static void AppSwcBcm_OsUnlckFunc(void)
{
  sint32 tmp;
  AppSwcBcm_ARID_DEF.Lib_blIn_f = DoorLckCtl_MotorProt;

  /* Outputs for Function Call SubSystem: '<S636>/Lib_RiseEdgeDet' */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_f,
    &AppSwcBcm_ARID_DEF.LogicalOperator_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ju);

  /* End of Outputs for SubSystem: '<S636>/Lib_RiseEdgeDet' */
  AppSwcBcm_ARID_DEF.MotorProtUnlck = (AppSwcBcm_ARID_DEF.LogicalOperator_c ||
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

/* System initialize for atomic system: '<S601>/DoorDrv' */
static void AppSwcBcm_DoorDrv_Init(void)
{
  DoorLckCtl_TrunkLckSw = true;
}

/* Output and update for atomic system: '<S601>/DoorDrv' */
static void AppSwcBcm_DoorDrv(void)
{
  boolean tmp;

  /* Chart: '<S601>/DoorDrv' incorporates:
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

  /* End of Chart: '<S601>/DoorDrv' */
}

/* System initialize for atomic system: '<S601>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_a;

  /* InitializeConditions for Delay: '<S646>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_o = true;

  /* InitializeConditions for UnitDelay: '<S646>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n = 1U;

  /* InitializeConditions for Delay: '<S654>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = true;

  /* InitializeConditions for Delay: '<S647>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_bs = true;

  /* InitializeConditions for UnitDelay: '<S647>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m = 1U;

  /* SystemInitialize for Chart: '<S660>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_i);

  /* SystemInitialize for Chart: '<S660>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_c);

  /* SystemInitialize for Chart: '<S672>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_p);

  /* SystemInitialize for Chart: '<S690>/LIB_PosPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_a);

  /* SystemInitialize for Chart: '<S691>/LIB_TPD_10ms' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_k);

  /* SystemInitialize for Chart: '<S713>/LIB_TPD_10ms8' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_o);

  /* SystemInitialize for Chart: '<S716>/LIB_TPD_10ms1' */
  AppSwcBcm_LIB_TPD_10ms1_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);
}

/* Output and update for atomic system: '<S601>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_a;
  sint32 tmp;
  uint8 rtb_Switch_p;
  boolean guard1 = false;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator5_hp;
  boolean rtb_LogicalOperator_aw;
  boolean rtb_LogicalOperator_db;
  boolean rtb_LogicalOperator_ia;
  boolean rtb_LogicalOperator_jg;
  boolean rtb_LogicalOperator_oj;
  boolean rtb_LogicalOperator_ot;
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_aw;
  boolean rtb_RelationalOperator2_b;
  boolean rtb_RelationalOperator2_ly_tmp;
  boolean rtb_RelationalOperator4_dw;
  boolean rtb_RelationalOperator8_e;
  boolean rtb_RelationalOperator_b;

  /* Logic: '<S644>/Logical Operator2' incorporates:
   *  Logic: '<S690>/Logical Operator'
   *  RelationalOperator: '<S644>/Relational Operator2'
   *  RelationalOperator: '<S644>/Relational Operator3'
   *  RelationalOperator: '<S644>/Relational Operator4'
   */
  rtb_RelationalOperator2_ly_tmp = ((!DoorLckCtl_DoorAjarFLSw) ||
    (!DoorLckCtl_DoorAjarFRSw) || (!DoorLckCtl_DoorAjarRRSw));

  /* RelationalOperator: '<S659>/Relational Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_b =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S659>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator2_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_f);

  /* End of Outputs for SubSystem: '<S659>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S659>/Relational Operator1' incorporates:
   *  RelationalOperator: '<S660>/Relational Operator2'
   *  RelationalOperator: '<S692>/Relational Operator2'
   *  RelationalOperator: '<S695>/Relational Operator4'
   */
  rtb_LogicalOperator_aw = !DoorLckCtl_DriverDoorLckSw;

  /* Logic: '<S659>/Logical Operator2' incorporates:
   *  Constant: '<S659>/Constant1'
   *  RelationalOperator: '<S659>/Relational Operator'
   *  RelationalOperator: '<S659>/Relational Operator1'
   */
  DoorLckCtl_HULck = ((AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 0) &&
                      rtb_LogicalOperator && rtb_LogicalOperator_aw);

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  Constant: '<S644>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S644>/Relational Operator6'
   */
  rtb_RelationalOperator1_aw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S716>/Relational Operator4' incorporates:
   *  Constant: '<S644>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S644>/Relational Operator5'
   */
  rtb_RelationalOperator4_dw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S644>/Logical Operator5' */
  rtb_LogicalOperator5_hp = (rtb_RelationalOperator1_aw ||
    rtb_RelationalOperator4_dw);

  /* RelationalOperator: '<S693>/Relational Operator' incorporates:
   *  Constant: '<S693>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator2_b = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->RKEReq == 2);

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  Constant: '<S693>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S693>/Relational Operator1'
   */
  rtb_RelationalOperator1_aw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S716>/Relational Operator4' incorporates:
   *  Constant: '<S693>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S693>/Relational Operator2'
   */
  rtb_RelationalOperator4_dw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* RelationalOperator: '<S693>/Relational Operator3' incorporates:
   *  RelationalOperator: '<S691>/Relational Operator6'
   *  RelationalOperator: '<S692>/Relational Operator3'
   *  RelationalOperator: '<S695>/Relational Operator9'
   */
  rtb_RelationalOperator_b = !DoorLckCtl_DrvSeatSw;

  /* Logic: '<S693>/Logical Operator1' incorporates:
   *  Logic: '<S693>/Logical Operator3'
   *  RelationalOperator: '<S693>/Relational Operator3'
   */
  rtb_RelationalOperator1_aw = (rtb_RelationalOperator_b &&
    rtb_RelationalOperator2_b && (rtb_RelationalOperator1_aw ||
    rtb_RelationalOperator4_dw));

  /* Outputs for Atomic SubSystem: '<S693>/Lib_RiseEdgeDet' */
  /* Logic: '<S705>/Logical Operator' incorporates:
   *  Logic: '<S705>/Logical Operator1'
   *  UnitDelay: '<S705>/Unit Delay'
   */
  DoorLckCtl_RKELck = (rtb_RelationalOperator1_aw &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_at));

  /* Update for UnitDelay: '<S705>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_at = rtb_RelationalOperator1_aw;

  /* End of Outputs for SubSystem: '<S693>/Lib_RiseEdgeDet' */

  /* Logic: '<S644>/Logical Operator1' incorporates:
   *  Logic: '<S644>/Logical Operator2'
   */
  DoorLckCtl_RKEAntiLck = (rtb_LogicalOperator5_hp &&
    rtb_RelationalOperator2_ly_tmp && DoorLckCtl_RKELck);

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  Constant: '<S691>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S691>/Relational Operator1'
   */
  rtb_RelationalOperator1_aw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S716>/Relational Operator4' incorporates:
   *  Constant: '<S691>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S691>/Relational Operator'
   */
  rtb_RelationalOperator4_dw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Chart: '<S691>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S691>/Constant40'
   *  Constant: '<S691>/Constant41'
   *  Constant: '<S691>/Constant42'
   *  Logic: '<S691>/Logical Operator1'
   *  RelationalOperator: '<S691>/Relational Operator2'
   *  RelationalOperator: '<S691>/Relational Operator3'
   *  RelationalOperator: '<S691>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 1,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms);

  /* Logic: '<S691>/Logical Operator3' incorporates:
   *  Logic: '<S691>/Logical Operator'
   *  UnitDelay: '<S691>/Unit Delay'
   */
  DoorLckCtl_MechLck = (rtb_RelationalOperator_b && (rtb_RelationalOperator1_aw ||
    rtb_RelationalOperator4_dw) && AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o5 &&
                        AppSwcBcm_ARID_DEF.LIB_bErrFlg_k);

  /* Logic: '<S644>/Logical Operator3' incorporates:
   *  Logic: '<S644>/Logical Operator2'
   */
  DoorLckCtl_MechAntiLck = (DoorLckCtl_MechLck && rtb_RelationalOperator2_ly_tmp);

  /* Logic: '<S644>/Logical Operator4' incorporates:
   *  Constant: '<S644>/Constant1'
   *  Logic: '<S644>/Logical Operator'
   *  Logic: '<S644>/Logical Operator2'
   *  RelationalOperator: '<S644>/Relational Operator'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_lh = (DoorLckCtl_RKEAntiLck || (DoorLckCtl_HULck &&
    (AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 0) &&
    rtb_RelationalOperator2_ly_tmp) || DoorLckCtl_MechAntiLck);

  /* Chart: '<S644>/LIB_Tim' incorporates:
   *  SubSystem: '<S656>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_lh,
    &AppSwcBcm_ARID_DEF.LogicalOperator_k5,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_a);
  AppSwcBcm_ARID_DEF.TempEn = (AppSwcBcm_ARID_DEF.LogicalOperator_k5 ||
    AppSwcBcm_ARID_DEF.TempEn);
  if (AppSwcBcm_ARID_DEF.TempEn) {
    /* Constant: '<S644>/Constant' */
    if (AppSwcBcm_ARID_DEF.Cnt_dw <= DoorLckCtl_AntiLckProtTim_C) {
      tmp = AppSwcBcm_ARID_DEF.Cnt_dw + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_dw + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_dw = (uint16)tmp;
      DoorLckCtl_DoorProtUnlck = false;
    } else {
      DoorLckCtl_DoorProtUnlck = true;
      AppSwcBcm_ARID_DEF.TempEn = false;
    }

    /* End of Constant: '<S644>/Constant' */
  } else {
    DoorLckCtl_DoorProtUnlck = false;
    AppSwcBcm_ARID_DEF.Cnt_dw = 0U;
    AppSwcBcm_ARID_DEF.TempEn = false;
  }

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  Constant: '<S653>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   *  RelationalOperator: '<S653>/Relational Operator2'
   */
  rtb_RelationalOperator1_aw = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->DrvPEAuthentAcsd == 1);

  /* RelationalOperator: '<S716>/Relational Operator2' incorporates:
   *  Constant: '<S653>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   *  RelationalOperator: '<S653>/Relational Operator6'
   */
  rtb_LogicalOperator5_hp = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->FRPEAuthentAcsd == 1);

  /* Logic: '<S653>/Logical Operator1' incorporates:
   *  Constant: '<S653>/Constant5'
   *  Logic: '<S653>/Logical Operator'
   *  Logic: '<S653>/Logical Operator3'
   *  RelationalOperator: '<S653>/Relational Operator'
   *  RelationalOperator: '<S653>/Relational Operator1'
   *  RelationalOperator: '<S653>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_m = ((DoorLckCtl_DrvPESw || DoorLckCtl_PsgPESw) &&
    (rtb_RelationalOperator1_aw || rtb_LogicalOperator5_hp) &&
    (DoorLckCtl_EEKeyEntry == 1));

  /* Chart: '<S653>/LIB_CntLimit3' incorporates:
   *  SubSystem: '<S728>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_m,
    &AppSwcBcm_ARID_DEF.LogicalOperator_g,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_p);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_g) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_i + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_i + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_i = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_h = 0U;
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_h + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_h + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_h = (uint16)tmp;
  }

  /* Constant: '<S653>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt2_h >= DoorLckCtl_PEProtIntvlTim_C) {
    AppSwcBcm_ARID_DEF.Cnt_i = 0U;
    AppSwcBcm_ARID_DEF.LIB_blOut_p = false;
  }

  /* End of Constant: '<S653>/Constant2' */

  /* Constant: '<S653>/Constant3' */
  AppSwcBcm_ARID_DEF.LIB_blOut_p = ((AppSwcBcm_ARID_DEF.Cnt_i >=
    DoorLckCtl_PEProtCnt_C) || AppSwcBcm_ARID_DEF.LIB_blOut_p);

  /* Outputs for Atomic SubSystem: '<S653>/Lib_RiseEdgeDet' */
  /* Switch: '<S653>/Switch' */
  rtb_LogicalOperator_oj = AppSwcBcm_Lib_RiseEdgeDet
    ((!AppSwcBcm_ARID_DEF.LIB_blOut_p) && AppSwcBcm_ARID_DEF.Lib_blIn_m,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_n);

  /* End of Outputs for SubSystem: '<S653>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  Constant: '<S692>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S692>/Relational Operator4'
   */
  rtb_RelationalOperator1_aw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S716>/Relational Operator2' incorporates:
   *  Constant: '<S692>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S692>/Relational Operator5'
   */
  rtb_LogicalOperator5_hp =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S692>/Logical Operator3' incorporates:
   *  Logic: '<S695>/Logical Operator'
   */
  rtb_RelationalOperator8_e = (DoorLckCtl_DoorAjarFLSw &&
    DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarRRSw);

  /* Logic: '<S692>/Logical Operator1' incorporates:
   *  Logic: '<S692>/Logical Operator2'
   *  Logic: '<S692>/Logical Operator3'
   *  RelationalOperator: '<S692>/Relational Operator1'
   */
  DoorLckCtl_PELck = (rtb_LogicalOperator_oj && rtb_LogicalOperator_aw &&
                      rtb_RelationalOperator_b && (rtb_RelationalOperator1_aw ||
    rtb_LogicalOperator5_hp) && rtb_RelationalOperator8_e);

  /* Logic: '<S690>/Logical Operator5' incorporates:
   *  Constant: '<S690>/Constant13'
   *  Constant: '<S690>/Constant14'
   *  Constant: '<S690>/Constant15'
   *  Logic: '<S690>/Logical Operator4'
   *  RelationalOperator: '<S690>/Relational Operator10'
   *  RelationalOperator: '<S690>/Relational Operator11'
   *  RelationalOperator: '<S690>/Relational Operator12'
   */
  rtb_RelationalOperator4_dw = (((AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 5)
    || (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 3)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2));

  /* Outputs for Atomic SubSystem: '<S690>/Lib_ChangeEdge' */
  /* RelationalOperator: '<S697>/Relational Operator' incorporates:
   *  Constant: '<S690>/Constant8'
   *  UnitDelay: '<S697>/Unit Delay'
   */
  rtb_RelationalOperator = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b1 == 1);

  /* Update for UnitDelay: '<S697>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b1 =
    AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts;

  /* End of Outputs for SubSystem: '<S690>/Lib_ChangeEdge' */

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S690>/Relational Operator9'
   */
  rtb_RelationalOperator1_aw =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* RelationalOperator: '<S690>/Relational Operator5' incorporates:
   *  Logic: '<S694>/Logical Operator'
   */
  rtb_LogicalOperator5_hp = !DoorLckCtl_TrunkAjarSw;

  /* Outputs for Atomic SubSystem: '<S690>/Lib_SR' */
  /* Switch: '<S699>/Switch' incorporates:
   *  Constant: '<S690>/Constant11'
   *  Logic: '<S690>/Logical Operator'
   *  Logic: '<S690>/Logical Operator2'
   *  Logic: '<S690>/Logical Operator3'
   *  Logic: '<S690>/Logical Operator7'
   *  RelationalOperator: '<S690>/Relational Operator13'
   *  RelationalOperator: '<S690>/Relational Operator5'
   *  RelationalOperator: '<S690>/Relational Operator8'
   *  UnitDelay: '<S651>/Unit Delay'
   */
  if (rtb_RelationalOperator2_ly_tmp || rtb_LogicalOperator5_hp ||
      (!AppSwcBcm_ConstB.RelationalOperator6) ||
      ((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode != 0) &&
       (!rtb_RelationalOperator4_dw)) || rtb_RelationalOperator1_aw ||
      DoorLckCtl_OsLck) {
    /* Switch: '<S699>/Switch' incorporates:
     *  Constant: '<S699>/Constant'
     */
    DoorLckCtl_AutoLckSta = false;
  } else {
    /* Outputs for Atomic SubSystem: '<S690>/Lib_ChangeEdge' */
    /* Switch: '<S699>/Switch' incorporates:
     *  Constant: '<S690>/Constant'
     *  Constant: '<S690>/Constant1'
     *  Logic: '<S690>/Logical Operator1'
     *  Logic: '<S690>/Logical Operator6'
     *  Logic: '<S697>/Logical Operator'
     *  Logic: '<S699>/Logical Operator'
     *  RelationalOperator: '<S690>/Relational Operator'
     *  RelationalOperator: '<S697>/Relational Operator1'
     *  UnitDelay: '<S699>/Unit Delay'
     */
    DoorLckCtl_AutoLckSta = (((rtb_RelationalOperator4_dw ||
      (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0)) &&
      ((AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 0) &&
       rtb_RelationalOperator)) || DoorLckCtl_AutoLckSta);

    /* End of Outputs for SubSystem: '<S690>/Lib_ChangeEdge' */
  }

  /* End of Switch: '<S699>/Switch' */
  /* End of Outputs for SubSystem: '<S690>/Lib_SR' */

  /* Chart: '<S690>/LIB_PosPluse2' incorporates:
   *  Constant: '<S690>/Constant7'
   *  UnitDelay: '<S637>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse2(DoorLckCtl_AutoLckSta, DoorLckCtl_AutoLckDelayTim_C,
    DoorLckCtl_OsUnlck, &rtb_LIB_blOut_a,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse2);

  /* Outputs for Atomic SubSystem: '<S690>/Lib_RiseEdgeDet' */
  /* Logic: '<S698>/Logical Operator' incorporates:
   *  Logic: '<S698>/Logical Operator1'
   *  UnitDelay: '<S698>/Unit Delay'
   */
  DoorLckCtl_AutoLck = (rtb_LIB_blOut_a &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_as));

  /* Update for UnitDelay: '<S698>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_as = rtb_LIB_blOut_a;

  /* End of Outputs for SubSystem: '<S690>/Lib_RiseEdgeDet' */

  /* RelationalOperator: '<S695>/Relational Operator10' incorporates:
   *  Constant: '<S695>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator1_aw = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus())
    ->LckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S695>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_db = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator1_aw,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_gu);

  /* End of Outputs for SubSystem: '<S695>/Lib_RiseEdgeDet' */

  /* Delay: '<S646>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_o) {
    /* Switch: '<S646>/Switch1' incorporates:
     *  Constant: '<S646>/Constant7'
     *  Constant: '<S646>/Constant8'
     *  RelationalOperator: '<S646>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndLckSts;
    }

    /* End of Switch: '<S646>/Switch1' */
  }

  /* Switch: '<S646>/Switch' incorporates:
   *  Constant: '<S646>/Constant5'
   *  RelationalOperator: '<S646>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2) {
    /* Switch: '<S646>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch_p = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndLckSts_enum;
  } else {
    /* Switch: '<S646>/Switch' incorporates:
     *  Constant: '<S646>/Constant6'
     */
    rtb_Switch_p = 0U;
  }

  /* End of Switch: '<S646>/Switch' */

  /* MultiPortSwitch: '<S646>/Multiport Switch' */
  switch (rtb_Switch_p) {
   case 1:
    /* MultiPortSwitch: '<S646>/Multiport Switch' incorporates:
     *  Constant: '<S646>/Constant1'
     */
    DoorLckCtl_IllmndLckSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S646>/Multiport Switch' incorporates:
     *  Constant: '<S646>/Constant2'
     */
    DoorLckCtl_IllmndLckSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S646>/Multiport Switch' incorporates:
     *  Delay: '<S646>/Delay'
     */
    DoorLckCtl_IllmndLckSts = AppSwcBcm_ARID_DEF.Delay_DSTATE;
    break;
  }

  /* End of MultiPortSwitch: '<S646>/Multiport Switch' */

  /* MultiPortSwitch: '<S646>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndLckSts) {
   case 1:
    /* MultiPortSwitch: '<S646>/Multiport Switch1' incorporates:
     *  Constant: '<S646>/Constant3'
     */
    DoorLckCtl_IllmndLckStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S646>/Multiport Switch1' incorporates:
     *  Constant: '<S646>/Constant4'
     */
    DoorLckCtl_IllmndLckStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S646>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S646>/Unit Delay'
     */
    DoorLckCtl_IllmndLckStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n;
    break;
  }

  /* End of MultiPortSwitch: '<S646>/Multiport Switch1' */

  /* RelationalOperator: '<S716>/Relational Operator4' incorporates:
   *  Constant: '<S695>/Constant4'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S695>/Relational Operator2'
   */
  rtb_RelationalOperator4_dw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S715>/Relational Operator6' incorporates:
   *  Constant: '<S695>/Constant5'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S695>/Relational Operator3'
   */
  rtb_RelationalOperator1_aw =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S695>/Logical Operator2' incorporates:
   *  Constant: '<S695>/Constant10'
   *  Logic: '<S695>/Logical Operator1'
   *  Logic: '<S695>/Logical Operator3'
   *  RelationalOperator: '<S695>/Relational Operator'
   *  RelationalOperator: '<S695>/Relational Operator1'
   *  RelationalOperator: '<S695>/Relational Operator8'
   */
  DoorLckCtl_WelcomeLck = (rtb_LogicalOperator_db && ((DoorLckCtl_IllmndLckStsFb
    == 1) && (DoorLckCtl_EEIlluminatedEntrySys == 1) &&
    (rtb_RelationalOperator4_dw || rtb_RelationalOperator1_aw) &&
    rtb_LogicalOperator_aw && rtb_RelationalOperator8_e && (DoorLckCtl_IllmndSts
    == 1) && rtb_RelationalOperator_b));

  /* RelationalOperator: '<S716>/Relational Operator' incorporates:
   *  Constant: '<S716>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_b = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->RKEReq == 3);

  /* Chart: '<S716>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S716>/Constant2'
   *  Constant: '<S716>/Constant3'
   *  Constant: '<S716>/Constant4'
   */
  AppSwcBcm_LIB_TPD_10ms1(rtb_RelationalOperator_b,
    DoorLckCtl_TrunkUnlckTimValid_C, DoorLckCtl_TrunkUnlckTimInvalid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_f,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1);

  /* Logic: '<S716>/Logical Operator1' incorporates:
   *  Constant: '<S716>/Constant6'
   *  RelationalOperator: '<S716>/Relational Operator3'
   */
  rtb_RelationalOperator_b = ((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0) &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_f);

  /* Outputs for Atomic SubSystem: '<S716>/Lib_RiseEdgeDet1' */
  /* Logic: '<S725>/Logical Operator' incorporates:
   *  Logic: '<S725>/Logical Operator1'
   *  UnitDelay: '<S725>/Unit Delay'
   */
  DoorLckCtl_TrunkRKEUnlck = (rtb_RelationalOperator_b &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_na));

  /* Update for UnitDelay: '<S725>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_na = rtb_RelationalOperator_b;

  /* End of Outputs for SubSystem: '<S716>/Lib_RiseEdgeDet1' */

  /* RelationalOperator: '<S716>/Relational Operator1' incorporates:
   *  Constant: '<S716>/Constant1'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_aw = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUTrnkLckSwCtrl_enum == 1);

  /* RelationalOperator: '<S714>/Relational Operator8' incorporates:
   *  Constant: '<S716>/Constant8'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S716>/Relational Operator5'
   */
  rtb_RelationalOperator8_e =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* UnitDelay: '<S713>/Unit Delay' incorporates:
   *  Constant: '<S716>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S716>/Relational Operator6'
   */
  rtb_RelationalOperator_b =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S716>/Lib_RiseEdgeDet2' */
  /* Logic: '<S716>/Logical Operator3' incorporates:
   *  Constant: '<S716>/Constant5'
   *  Constant: '<S716>/Constant7'
   *  Logic: '<S716>/Logical Operator2'
   *  RelationalOperator: '<S716>/Relational Operator2'
   *  RelationalOperator: '<S716>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator_gw = AppSwcBcm_Lib_RiseEdgeDet
    (rtb_RelationalOperator1_aw && (AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts ==
      0) && (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2) &&
     (rtb_RelationalOperator8_e || rtb_RelationalOperator_b),
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2);

  /* End of Outputs for SubSystem: '<S716>/Lib_RiseEdgeDet2' */

  /* Logic: '<S716>/Logical Operator' */
  DoorLckCtl_TrunkUnlck = (DoorLckCtl_TrunkRKEUnlck ||
    AppSwcBcm_ARID_DEF.LogicalOperator_gw);

  /* RelationalOperator: '<S694>/Relational Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_j = DoorLckCtl_TrunkUnlck;

  /* Chart: '<S694>/LIB_PosPluse1' incorporates:
   *  SubSystem: '<S708>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_j,
    &AppSwcBcm_ARID_DEF.LogicalOperator_k,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_ld);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_k) {
    AppSwcBcm_ARID_DEF.Flg_l = true;
    AppSwcBcm_ARID_DEF.Cnt_o = 0U;
  }

  /* Logic: '<S694>/Logical Operator2' incorporates:
   *  UnitDelay: '<S694>/Unit Delay'
   */
  if (rtb_LogicalOperator5_hp || DoorLckCtl_TrunkAutoLck) {
    AppSwcBcm_ARID_DEF.Flg_l = false;
    AppSwcBcm_ARID_DEF.Cnt_o = 0U;
  }

  /* End of Logic: '<S694>/Logical Operator2' */
  if (AppSwcBcm_ARID_DEF.Flg_l) {
    /* Constant: '<S694>/Constant1' */
    if (AppSwcBcm_ARID_DEF.Cnt_o >= DoorLckCtl_TrunkAutoLckTim_C) {
      rtb_RelationalOperator_b = true;
      AppSwcBcm_ARID_DEF.Flg_l = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_o + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_o + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_o = (uint16)tmp;
      rtb_RelationalOperator_b = false;
    }

    /* End of Constant: '<S694>/Constant1' */
  } else {
    rtb_RelationalOperator_b = false;
    AppSwcBcm_ARID_DEF.Cnt_o = 0U;
  }

  /* Logic: '<S694>/Logical Operator1' incorporates:
   *  RelationalOperator: '<S694>/Relational Operator3'
   */
  rtb_RelationalOperator_b = (DoorLckCtl_TrunkAjarSw && rtb_RelationalOperator_b);

  /* Outputs for Atomic SubSystem: '<S694>/Lib_RiseEdgeDet' */
  /* Logic: '<S709>/Logical Operator' incorporates:
   *  Logic: '<S709>/Logical Operator1'
   *  UnitDelay: '<S709>/Unit Delay'
   */
  DoorLckCtl_TrunkAutoLck = (rtb_RelationalOperator_b &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ln));

  /* Update for UnitDelay: '<S709>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ln = rtb_RelationalOperator_b;

  /* End of Outputs for SubSystem: '<S694>/Lib_RiseEdgeDet' */

  /* Logic: '<S651>/Logical Operator' */
  DoorLckCtl_OsLck = (DoorLckCtl_MechLck || DoorLckCtl_PELck ||
                      DoorLckCtl_AutoLck || DoorLckCtl_WelcomeLck ||
                      DoorLckCtl_RKELck || DoorLckCtl_TrunkAutoLck);

  /* Chart: '<S660>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S660>/Constant10'
   *  Constant: '<S660>/Constant11'
   *  Constant: '<S660>/Constant9'
   *  Logic: '<S660>/Logical Operator1'
   *  RelationalOperator: '<S660>/Relational Operator3'
   *  RelationalOperator: '<S660>/Relational Operator4'
   *  RelationalOperator: '<S660>/Relational Operator5'
   *  RelationalOperator: '<S660>/Relational Operator7'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_DoorAjarFRSw && DoorLckCtl_DoorAjarFLSw &&
    DoorLckCtl_DoorAjarRRSw && DoorLckCtl_TrunkAjarSw,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_c,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms1_b);

  /* Chart: '<S660>/Chart' */
  if (DoorLckCtl_DriverDoorLckSw) {
    AppSwcBcm_ARID_DEF.Lib_blIn_p = DoorLckCtl_DoorAjarFRSw;

    /* Outputs for Function Call SubSystem: '<S662>/Lib_RiseEdgeDet' */
    AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_p,
      &AppSwcBcm_ARID_DEF.LogicalOperator_bl,
      &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_jz);

    /* End of Outputs for SubSystem: '<S662>/Lib_RiseEdgeDet' */
    guard1 = false;
    if (AppSwcBcm_ARID_DEF.LogicalOperator_bl) {
      guard1 = true;
    } else {
      AppSwcBcm_ARID_DEF.Lib_blIn_pg = DoorLckCtl_DoorAjarRRSw;

      /* Outputs for Function Call SubSystem: '<S662>/Lib_RiseEdgeDet1' */
      AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_pg,
        &AppSwcBcm_ARID_DEF.LogicalOperator_ka,
        &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_b);

      /* End of Outputs for SubSystem: '<S662>/Lib_RiseEdgeDet1' */
      if (AppSwcBcm_ARID_DEF.LogicalOperator_ka) {
        guard1 = true;
      } else {
        AppSwcBcm_ARID_DEF.Lib_blIn_n = DoorLckCtl_TrunkAjarSw;

        /* Outputs for Function Call SubSystem: '<S662>/Lib_RiseEdgeDet2' */
        AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_n,
          &AppSwcBcm_ARID_DEF.LogicalOperator_m,
          &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet2_e);

        /* End of Outputs for SubSystem: '<S662>/Lib_RiseEdgeDet2' */
        if (AppSwcBcm_ARID_DEF.LogicalOperator_m) {
          guard1 = true;
        }
      }
    }

    if (guard1) {
      AppSwcBcm_ARID_DEF.Door_Change = true;
      AppSwcBcm_ARID_DEF.Cnt_iy = 0U;
    }
  }

  if (AppSwcBcm_ARID_DEF.Door_Change) {
    if (AppSwcBcm_ARID_DEF.Cnt_iy >= 40) {
      AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = true;
      AppSwcBcm_ARID_DEF.Door_Change = false;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_iy + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_iy + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_iy = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.DoorLckCtl_Lck = false;
  }

  /* End of Chart: '<S660>/Chart' */

  /* Chart: '<S660>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S660>/Constant'
   *  Constant: '<S660>/Constant2'
   *  Constant: '<S660>/Constant3'
   *  Constant: '<S660>/Constant49'
   *  RelationalOperator: '<S660>/Relational Operator'
   */
  AppSwcBcm_LIB_TPD_10ms1(DoorLckCtl_VehSpd >= DoorLckCtl_SpdLck_C,
    DoorLckCtl_SpdLckTimValid_C, DoorLckCtl_SpdLckTimInValid_C, DoorLckCtl_Ts_C,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_d);

  /* Logic: '<S660>/Logical Operator' incorporates:
   *  Constant: '<S660>/Constant8'
   *  Logic: '<S660>/Logical Operator2'
   *  RelationalOperator: '<S660>/Relational Operator6'
   */
  rtb_LogicalOperator_aw = (AppSwcBcm_ARID_DEF.LIB_bErrFlg_c &&
    (rtb_LogicalOperator_aw || AppSwcBcm_ARID_DEF.DoorLckCtl_Lck) &&
    AppSwcBcm_ConstB.RelationalOperator1 && AppSwcBcm_ARID_DEF.LIB_bErrFlg_i &&
    (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2));

  /* Logic: '<S665>/Logical Operator' incorporates:
   *  Logic: '<S665>/Logical Operator1'
   *  UnitDelay: '<S665>/Unit Delay'
   */
  DoorLckCtl_SpdLck = (rtb_LogicalOperator_aw &&
                       (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hl));

  /* Logic: '<S648>/Logical Operator' */
  DoorLckCtl_InsLck = (DoorLckCtl_HULck || DoorLckCtl_SpdLck);

  /* UnitDelay: '<S713>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S672>/Relational Operator'
   */
  rtb_RelationalOperator_b = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->CrashSta;

  /* Chart: '<S672>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S672>/Constant2'
   *  Constant: '<S672>/Constant3'
   *  Constant: '<S672>/Constant4'
   *  Constant: '<S672>/Constant6'
   *  RelationalOperator: '<S672>/Relational Operator2'
   */
  AppSwcBcm_LIB_TPD_10ms1(AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2,
    DoorLckCtl_CrshPwrOnTimValid_C, DoorLckCtl_CrshPwrOnTimInValid_C,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_p,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms_l);

  /* Logic: '<S672>/Logical Operator1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_l = (rtb_RelationalOperator_b &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_p);

  /* Chart: '<S672>/Chart' incorporates:
   *  SubSystem: '<S676>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_l,
    &AppSwcBcm_ARID_DEF.LogicalOperator_kx,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_h);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_kx) {
    AppSwcBcm_ARID_DEF.Flg_g = true;
    DoorLckCtl_CrshUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_eh = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_g) {
    if (AppSwcBcm_ARID_DEF.Cnt_eh >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_eh >= 20) {
        DoorLckCtl_CrshUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_g = false;
      } else {
        DoorLckCtl_CrshUnlck = false;
        tmp = AppSwcBcm_ARID_DEF.Cnt_eh + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_eh + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_eh = (uint16)tmp;
      }
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_eh + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_eh + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_eh = (uint16)tmp;
    }
  } else {
    DoorLckCtl_CrshUnlck = false;
  }

  /* RelationalOperator: '<S673>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_b =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_CCP_PanelStatus_BOD())
    ->VIPM_CCPCenLckKey_flg;

  /* Outputs for Atomic SubSystem: '<S673>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_jg = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_bs);

  /* End of Outputs for SubSystem: '<S673>/Lib_RiseEdgeDet' */

  /* Logic: '<S673>/Logical Operator' incorporates:
   *  Constant: '<S673>/Constant2'
   *  RelationalOperator: '<S673>/Relational Operator'
   *  RelationalOperator: '<S673>/Relational Operator2'
   */
  DoorLckCtl_HUUnLck = (rtb_LogicalOperator_jg && DoorLckCtl_DriverDoorLckSw &&
                        (AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 0));

  /* Switch: '<S654>/Switch1' incorporates:
   *  Constant: '<S654>/Constant1'
   *  RelationalOperator: '<S654>/Relational Operator1'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2) {
    /* Switch: '<S654>/Switch1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch_p = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUParkAutoUnlckSet_enum;
  } else {
    /* Switch: '<S654>/Switch1' incorporates:
     *  Constant: '<S654>/Constant4'
     */
    rtb_Switch_p = 0U;
  }

  /* End of Switch: '<S654>/Switch1' */

  /* Delay: '<S654>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_j) {
    /* Switch: '<S654>/Switch2' incorporates:
     *  Constant: '<S654>/Constant5'
     *  Constant: '<S654>/Constant6'
     *  RelationalOperator: '<S654>/Relational Operator3'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_g = 1U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_g =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.ParkAutoUnlockSetFb;
    }

    /* End of Switch: '<S654>/Switch2' */
  }

  /* MultiPortSwitch: '<S654>/Multiport Switch' */
  switch (rtb_Switch_p) {
   case 1:
    /* MultiPortSwitch: '<S654>/Multiport Switch' incorporates:
     *  Constant: '<S654>/Constant2'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S654>/Multiport Switch' incorporates:
     *  Constant: '<S654>/Constant3'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S654>/Multiport Switch' incorporates:
     *  Delay: '<S654>/Delay'
     */
    DoorLckCtl_ParkAutoUnlockSetFb = AppSwcBcm_ARID_DEF.Delay_DSTATE_g;
    break;
  }

  /* End of MultiPortSwitch: '<S654>/Multiport Switch' */

  /* RelationalOperator: '<S674>/Relational Operator3' incorporates:
   *  Constant: '<S674>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator_b =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 0);

  /* Outputs for Atomic SubSystem: '<S674>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_ot = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_nu);

  /* End of Outputs for SubSystem: '<S674>/Lib_RiseEdgeDet' */

  /* Logic: '<S674>/Logical Operator' incorporates:
   *  Constant: '<S674>/Constant'
   *  Constant: '<S674>/Constant1'
   *  RelationalOperator: '<S674>/Relational Operator'
   *  RelationalOperator: '<S674>/Relational Operator1'
   *  RelationalOperator: '<S674>/Relational Operator2'
   */
  DoorLckCtl_ParkUnlck = ((DoorLckCtl_ParkAutoUnlockSetFb == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2) &&
    DoorLckCtl_DriverDoorLckSw && DoorLckCtl_VehStop && rtb_LogicalOperator_ot);

  /* UnitDelay: '<S713>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S675>/Relational Operator'
   */
  rtb_RelationalOperator_b = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->ThermalrunawaySta;

  /* Logic: '<S675>/Logical Operator2' incorporates:
   *  Constant: '<S675>/Constant1'
   *  Constant: '<S675>/Constant2'
   *  Logic: '<S675>/Logical Operator'
   *  Logic: '<S675>/Logical Operator1'
   *  RelationalOperator: '<S675>/Relational Operator1'
   *  RelationalOperator: '<S675>/Relational Operator2'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_jg = (rtb_RelationalOperator_b &&
    ((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0) ||
     ((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2) && DoorLckCtl_VehStop)));

  /* Chart: '<S675>/Chart' incorporates:
   *  SubSystem: '<S682>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_jg,
    &AppSwcBcm_ARID_DEF.LogicalOperator_e,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_b);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_e) {
    AppSwcBcm_ARID_DEF.Flg_b = true;
    DoorLckCtl_ThermRunawayUnlck = true;
    AppSwcBcm_ARID_DEF.Cnt_h = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_b) {
    if (AppSwcBcm_ARID_DEF.Cnt_h >= 1) {
      if (AppSwcBcm_ARID_DEF.Cnt_h >= 20) {
        DoorLckCtl_ThermRunawayUnlck = true;
        AppSwcBcm_ARID_DEF.Flg_b = false;
      } else {
        DoorLckCtl_ThermRunawayUnlck = false;
        tmp = AppSwcBcm_ARID_DEF.Cnt_h + 1;
        if (AppSwcBcm_ARID_DEF.Cnt_h + 1 > 65535) {
          tmp = 65535;
        }

        AppSwcBcm_ARID_DEF.Cnt_h = (uint16)tmp;
      }
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_h + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_h + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_h = (uint16)tmp;
    }
  } else {
    DoorLckCtl_ThermRunawayUnlck = false;
  }

  /* Logic: '<S649>/Logical Operator' */
  DoorLckCtl_InsUnlck = (DoorLckCtl_HUUnLck || DoorLckCtl_ParkUnlck ||
    DoorLckCtl_ThermRunawayUnlck || DoorLckCtl_CrshUnlck);

  /* RelationalOperator: '<S715>/Relational Operator' incorporates:
   *  Constant: '<S715>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_o =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->RKEReq == 1);

  /* Logic: '<S715>/Logical Operator4' incorporates:
   *  Constant: '<S715>/Constant1'
   *  Constant: '<S715>/Constant2'
   *  Constant: '<S715>/Constant3'
   *  Constant: '<S715>/Constant4'
   *  Constant: '<S715>/Constant5'
   *  Constant: '<S715>/Constant6'
   *  Logic: '<S715>/Logical Operator'
   *  Logic: '<S715>/Logical Operator1'
   *  Logic: '<S715>/Logical Operator2'
   *  Logic: '<S715>/Logical Operator3'
   *  RelationalOperator: '<S715>/Relational Operator1'
   *  RelationalOperator: '<S715>/Relational Operator2'
   *  RelationalOperator: '<S715>/Relational Operator3'
   *  RelationalOperator: '<S715>/Relational Operator4'
   *  RelationalOperator: '<S715>/Relational Operator5'
   *  RelationalOperator: '<S715>/Relational Operator6'
   */
  rtb_RelationalOperator_b = (AppSwcBcm_ARID_DEF.Lib_blIn_o &&
    (((AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 0) &&
      (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0)) ||
     (((AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 5) ||
       (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 3) ||
       (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 2)) &&
      (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2))));

  /* Outputs for Atomic SubSystem: '<S715>/Lib_RiseEdgeDet' */
  /* Logic: '<S721>/Logical Operator' incorporates:
   *  Logic: '<S721>/Logical Operator1'
   *  UnitDelay: '<S721>/Unit Delay'
   */
  DoorLckCtl_RKEUnlck = (rtb_RelationalOperator_b &&
    (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pu));

  /* Update for UnitDelay: '<S721>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_pu = rtb_RelationalOperator_b;

  /* End of Outputs for SubSystem: '<S715>/Lib_RiseEdgeDet' */

  /* UnitDelay: '<S713>/Unit Delay' incorporates:
   *  Constant: '<S714>/Constant5'
   *  RelationalOperator: '<S714>/Relational Operator7'
   */
  rtb_RelationalOperator_b = (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2);

  /* Logic: '<S714>/Logical Operator1' incorporates:
   *  Constant: '<S714>/Constant2'
   *  Constant: '<S714>/Constant3'
   *  Constant: '<S714>/Constant4'
   *  Constant: '<S714>/Constant7'
   *  Constant: '<S714>/Constant8'
   *  Logic: '<S714>/Logical Operator2'
   *  Logic: '<S714>/Logical Operator3'
   *  Logic: '<S714>/Logical Operator4'
   *  Logic: '<S714>/Logical Operator5'
   *  Logic: '<S714>/Logical Operator6'
   *  RelationalOperator: '<S714>/Relational Operator1'
   *  RelationalOperator: '<S714>/Relational Operator2'
   *  RelationalOperator: '<S714>/Relational Operator3'
   *  RelationalOperator: '<S714>/Relational Operator4'
   *  RelationalOperator: '<S714>/Relational Operator5'
   *  RelationalOperator: '<S714>/Relational Operator6'
   *  RelationalOperator: '<S714>/Relational Operator8'
   */
  DoorLckCtl_PEUnlck = (rtb_LogicalOperator_oj && DoorLckCtl_DriverDoorLckSw &&
                        (((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 0)) ||
    (((AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 5) ||
      (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 3)) &&
     rtb_RelationalOperator_b) || (rtb_RelationalOperator_b &&
    (AppSwcBcm_ARID_DEF.UnitDelay1.SysPowerSts == 2))));

  /* RelationalOperator: '<S717>/Relational Operator4' incorporates:
   *  Constant: '<S717>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator_b = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->UnlckWlcmReq == 1);

  /* Outputs for Atomic SubSystem: '<S717>/Lib_RiseEdgeDet' */
  rtb_LogicalOperator_ia = AppSwcBcm_Lib_RiseEdgeDet(rtb_RelationalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_l);

  /* End of Outputs for SubSystem: '<S717>/Lib_RiseEdgeDet' */

  /* Delay: '<S647>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_bs) {
    /* Switch: '<S647>/Switch1' incorporates:
     *  Constant: '<S647>/Constant7'
     *  Constant: '<S647>/Constant8'
     *  RelationalOperator: '<S647>/Relational Operator1'
     */
    if (AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts == 255) {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_i = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Delay_DSTATE_i =
        AppSwcBcm_ARID_DEF.EEReadCtl_Bus.IllmndUnlckSts;
    }

    /* End of Switch: '<S647>/Switch1' */
  }

  /* Switch: '<S647>/Switch' incorporates:
   *  Constant: '<S647>/Constant5'
   *  RelationalOperator: '<S647>/Relational Operator'
   */
  if (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 2) {
    /* Switch: '<S647>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch_p = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
      ->VIPM_HUIllmndUnlckSts_enum;
  } else {
    /* Switch: '<S647>/Switch' incorporates:
     *  Constant: '<S647>/Constant6'
     */
    rtb_Switch_p = 0U;
  }

  /* End of Switch: '<S647>/Switch' */

  /* MultiPortSwitch: '<S647>/Multiport Switch' */
  switch (rtb_Switch_p) {
   case 1:
    /* MultiPortSwitch: '<S647>/Multiport Switch' incorporates:
     *  Constant: '<S647>/Constant1'
     */
    DoorLckCtl_IllmndUnlockSts = 1U;
    break;

   case 2:
    /* MultiPortSwitch: '<S647>/Multiport Switch' incorporates:
     *  Constant: '<S647>/Constant2'
     */
    DoorLckCtl_IllmndUnlockSts = 2U;
    break;

   default:
    /* MultiPortSwitch: '<S647>/Multiport Switch' incorporates:
     *  Delay: '<S647>/Delay'
     */
    DoorLckCtl_IllmndUnlockSts = AppSwcBcm_ARID_DEF.Delay_DSTATE_i;
    break;
  }

  /* End of MultiPortSwitch: '<S647>/Multiport Switch' */

  /* MultiPortSwitch: '<S647>/Multiport Switch1' */
  switch (DoorLckCtl_IllmndUnlockSts) {
   case 1:
    /* MultiPortSwitch: '<S647>/Multiport Switch1' incorporates:
     *  Constant: '<S647>/Constant3'
     */
    DoorLckCtl_IllmndUnlockStsFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S647>/Multiport Switch1' incorporates:
     *  Constant: '<S647>/Constant4'
     */
    DoorLckCtl_IllmndUnlockStsFb = 1U;
    break;

   default:
    /* MultiPortSwitch: '<S647>/Multiport Switch1' incorporates:
     *  UnitDelay: '<S647>/Unit Delay'
     */
    DoorLckCtl_IllmndUnlockStsFb = AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m;
    break;
  }

  /* End of MultiPortSwitch: '<S647>/Multiport Switch1' */

  /* Logic: '<S717>/Logical Operator1' incorporates:
   *  Constant: '<S717>/Constant1'
   *  Constant: '<S717>/Constant4'
   *  Constant: '<S717>/Constant5'
   *  Constant: '<S717>/Constant8'
   *  Logic: '<S717>/Logical Operator'
   *  RelationalOperator: '<S717>/Relational Operator'
   *  RelationalOperator: '<S717>/Relational Operator1'
   *  RelationalOperator: '<S717>/Relational Operator2'
   *  RelationalOperator: '<S717>/Relational Operator3'
   *  RelationalOperator: '<S717>/Relational Operator5'
   */
  DoorLckCtl_WelcomeUnlck = (rtb_LogicalOperator_ia &&
    (DoorLckCtl_DriverDoorLckSw && (DoorLckCtl_IllmndUnlockStsFb == 1) &&
     (DoorLckCtl_EEIlluminatedEntrySys == 1) &&
     (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0) && (DoorLckCtl_IllmndSts ==
    1)));

  /* Chart: '<S713>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S713>/Constant40'
   *  Constant: '<S713>/Constant41'
   *  Constant: '<S713>/Constant42'
   *  Logic: '<S713>/Logical Operator1'
   *  RelationalOperator: '<S713>/Relational Operator1'
   *  RelationalOperator: '<S713>/Relational Operator2'
   *  RelationalOperator: '<S713>/Relational Operator5'
   */
  AppSwcBcm_LIB_TPD_10ms1((!DoorLckCtl_J511TrunkUnlck) &&
    (!DoorLckCtl_J56DoorUnlck) && (!DoorLckCtl_J54DoorLck), 50, 1,
    DoorLckCtl_Ts_C, &AppSwcBcm_ARID_DEF.LIB_bErrFlg_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms8);

  /* Logic: '<S713>/Logical Operator' incorporates:
   *  UnitDelay: '<S713>/Unit Delay'
   */
  DoorLckCtl_MechUnlck = (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kg &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg_o);

  /* Logic: '<S652>/Logical Operator' */
  DoorLckCtl_OsUnlck = (DoorLckCtl_RKEUnlck || DoorLckCtl_PEUnlck ||
                        DoorLckCtl_WelcomeUnlck || DoorLckCtl_MechUnlck);

  /* Logic: '<S650>/Logical Operator' */
  AppSwcBcm_ARID_DEF.Lib_blIn_gm = (DoorLckCtl_InsLck || DoorLckCtl_OsLck ||
    DoorLckCtl_InsUnlck || DoorLckCtl_OsUnlck || DoorLckCtl_TrunkUnlck);

  /* Chart: '<S650>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S685>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_gm,
    &AppSwcBcm_ARID_DEF.LogicalOperator_o,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_o);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_o) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_p + 1;
    if (AppSwcBcm_ARID_DEF.Cnt_p + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt_p = (uint16)tmp;
    AppSwcBcm_ARID_DEF.Cnt2_b = 0U;

    /* LIB_blOut=0; */
  } else {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_b + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_b + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_b = (uint16)tmp;
  }

  /* Constant: '<S650>/Constant' */
  if (AppSwcBcm_ARID_DEF.Cnt2_b >= DoorLckCtl_CntSubTim_C) {
    tmp = AppSwcBcm_ARID_DEF.Cnt_p - 1;
    if (AppSwcBcm_ARID_DEF.Cnt_p - 1 < 0) {
      tmp = 0;
    }

    AppSwcBcm_ARID_DEF.Cnt_p = (uint16)tmp;
  }

  /* End of Constant: '<S650>/Constant' */

  /* Constant: '<S650>/Constant1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_c = (AppSwcBcm_ARID_DEF.Cnt_p >=
    DoorLckCtl_MotorWorkMax_C);

  /* Chart: '<S650>/LIB_CntLimit2' incorporates:
   *  SubSystem: '<S685>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_o(AppSwcBcm_ARID_DEF.Lib_blIn_c,
    &AppSwcBcm_ARID_DEF.LogicalOperator_n,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1_l);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_n) {
    AppSwcBcm_ARID_DEF.LIB_blOut_h = true;
    AppSwcBcm_ARID_DEF.Cnt3 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.LIB_blOut_h) {
    tmp = AppSwcBcm_ARID_DEF.Cnt3 + 1;
    if (AppSwcBcm_ARID_DEF.Cnt3 + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt3 = (uint16)tmp;
  }

  /* Constant: '<S650>/Constant2' */
  if (AppSwcBcm_ARID_DEF.Cnt3 >= DoorLckCtl_MotorProtTimMax_C) {
    AppSwcBcm_ARID_DEF.LIB_blOut_h = false;
    AppSwcBcm_ARID_DEF.Cnt_p = 0U;
    AppSwcBcm_ARID_DEF.Cnt2_b = 0U;
    AppSwcBcm_ARID_DEF.Cnt3 = 0U;
  }

  /* End of Constant: '<S650>/Constant2' */

  /* Switch: '<S650>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  DoorLckCtl_MotorProt = ((!(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->CrashSta) && AppSwcBcm_ARID_DEF.LIB_blOut_h);

  /* Chart: '<S715>/ClearRKECommd' incorporates:
   *  SubSystem: '<S720>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_o,
    &AppSwcBcm_ARID_DEF.LogicalOperator_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_j);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_l) {
    AppSwcBcm_ARID_DEF.flg = true;
    AppSwcBcm_ARID_DEF.Cnt_m1 = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_m1 - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_m1 - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_m1 = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg && (AppSwcBcm_ARID_DEF.Cnt_m1 == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg = false;
  }

  /* Chart: '<S637>/ClearRKECommd1' */
  if (DoorLckCtl_TrunkUnlck) {
    AppSwcBcm_ARID_DEF.flg_o = true;
    AppSwcBcm_ARID_DEF.Cnt_mz = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_mz - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_mz - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_mz = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_o && (AppSwcBcm_ARID_DEF.Cnt_mz == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_o = false;
  }

  /* End of Chart: '<S637>/ClearRKECommd1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_gb = rtb_RelationalOperator2_b;

  /* Chart: '<S693>/ClearRKECommd' incorporates:
   *  SubSystem: '<S704>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_gb,
    &AppSwcBcm_ARID_DEF.LogicalOperator_b,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dh);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_b) {
    AppSwcBcm_ARID_DEF.flg_e = true;
    AppSwcBcm_ARID_DEF.Cnt_d1 = 4U;
  }

  tmp = AppSwcBcm_ARID_DEF.Cnt_d1 - 1;
  if (AppSwcBcm_ARID_DEF.Cnt_d1 - 1 < 0) {
    tmp = 0;
  }

  AppSwcBcm_ARID_DEF.Cnt_d1 = (uint8)tmp;
  if (AppSwcBcm_ARID_DEF.flg_e && (AppSwcBcm_ARID_DEF.Cnt_d1 == 0)) {
    Clear_RKECommd();
    AppSwcBcm_ARID_DEF.flg_e = false;
  }

  /* Outputs for Atomic SubSystem: '<S691>/Lib_RiseEdgeDet' */
  /* Update for UnitDelay: '<S691>/Unit Delay' incorporates:
   *  RelationalOperator: '<S691>/Relational Operator4'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o5 = AppSwcBcm_Lib_RiseEdgeDet
    (DoorLckCtl_DriverDoorLckSw, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_dy);

  /* End of Outputs for SubSystem: '<S691>/Lib_RiseEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S713>/Lib_RiseEdgeDet' */
  /* Update for UnitDelay: '<S713>/Unit Delay' incorporates:
   *  RelationalOperator: '<S713>/Relational Operator3'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_kg = AppSwcBcm_Lib_RiseEdgeDet
    (!DoorLckCtl_DriverDoorLckSw, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_d);

  /* End of Outputs for SubSystem: '<S713>/Lib_RiseEdgeDet' */

  /* Update for Delay: '<S646>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_o = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE = DoorLckCtl_IllmndLckSts;

  /* Update for UnitDelay: '<S646>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n = DoorLckCtl_IllmndLckStsFb;

  /* Update for UnitDelay: '<S665>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hl = rtb_LogicalOperator_aw;

  /* Update for Delay: '<S654>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_j = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_g = DoorLckCtl_ParkAutoUnlockSetFb;

  /* Update for Delay: '<S647>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_bs = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_i = DoorLckCtl_IllmndUnlockSts;

  /* Update for UnitDelay: '<S647>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_m = DoorLckCtl_IllmndUnlockStsFb;
}

/* ConstCode for atomic system: '<S601>/DoorLckCtlLogic' */
static void AppSwcBcm_DoorLckCtlLogic_Const(void)
{
  /* ConstCode for Constant: '<S655>/Constant8' */
  DoorLckCtl_SpdCtlLckSet = 1U;
}

/* System initialize for atomic system: '<S601>/SignalProcess' */
static void AppSwcBcm_SignalProcess_m_Init(void)
{
  /* SystemInitialize for Chart: '<S641>/LIB_TPD_10ms1' */
  AppSwcBcm_ARID_DEF.cnt_heal_p = 50U;
  DoorLckCtl_DoorAjarFLSw = true;

  /* SystemInitialize for Chart: '<S641>/LIB_TPD_10ms2' */
  AppSwcBcm_ARID_DEF.cnt_heal_e = 50U;
  DoorLckCtl_DoorAjarFRSw = true;

  /* SystemInitialize for Chart: '<S641>/LIB_TPD_10ms' */
  AppSwcBcm_ARID_DEF.cnt_heal_os = 50U;
  DoorLckCtl_DriverDoorLckSw = true;

  /* SystemInitialize for Chart: '<S641>/LIB_TPD_10ms6' */
  AppSwcBcm_ARID_DEF.cnt_heal_k = 50U;
  DoorLckCtl_DoorAjarRLSw = true;

  /* SystemInitialize for Chart: '<S641>/LIB_TPD_10ms7' */
  AppSwcBcm_ARID_DEF.cnt_heal_o = 50U;
  DoorLckCtl_DoorAjarRRSw = true;

  /* SystemInitialize for Chart: '<S641>/LIB_TPD_10ms8' */
  AppSwcBcm_ARID_DEF.cnt_heal_n = 50U;
  DoorLckCtl_TrunkAjarSw = true;
}

/* Output and update for atomic system: '<S601>/SignalProcess' */
static void AppSwcBcm_SignalProcess_a(void)
{
  uint16 rtb_Switch12;
  uint16 tmp;
  boolean rtb_Switch1;

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift1' */
  /* Constant: '<S641>/Constant5' */
  rtb_Switch12 = AppSwcBcm_BitShift4(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift1' */

  /* Switch: '<S641>/Switch1' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND1'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch1' incorporates:
     *  Constant: '<S641>/Constant4'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarFLVal_C;
  } else {
    /* Switch: '<S641>/Switch1' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion1'
     */
    rtb_Switch1 = (BSW_J321DoorAjarFL != 0);
  }

  /* End of Switch: '<S641>/Switch1' */

  /* Chart: '<S641>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S641>/Constant1'
   *  Constant: '<S641>/Constant2'
   *  Constant: '<S641>/Constant3'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_lt >= (float32)
         DoorLckCtl_DoorAjarFLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_lt++;
      AppSwcBcm_ARID_DEF.cnt_heal_p = (uint16)((float32)
        DoorLckCtl_DoorAjarFLTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_lt = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_p == 0) {
      DoorLckCtl_DoorAjarFLSw = false;
    } else if (DoorLckCtl_DoorAjarFLTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_p--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms1' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift2' */
  /* Constant: '<S641>/Constant10' */
  rtb_Switch12 = AppSwcBcm_BitShift7(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift2' */

  /* Switch: '<S641>/Switch2' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND2'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch2' incorporates:
     *  Constant: '<S641>/Constant9'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarFRVal_C;
  } else {
    /* Switch: '<S641>/Switch2' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion2'
     */
    rtb_Switch1 = (BSW_J310DoorAjarFR != 0);
  }

  /* End of Switch: '<S641>/Switch2' */

  /* Chart: '<S641>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S641>/Constant6'
   *  Constant: '<S641>/Constant7'
   *  Constant: '<S641>/Constant8'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_l >= (float32)
         DoorLckCtl_DoorAjarFRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarFRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarFRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_l++;
      AppSwcBcm_ARID_DEF.cnt_heal_e = (uint16)((float32)
        DoorLckCtl_DoorAjarFRTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_l = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_e == 0) {
      DoorLckCtl_DoorAjarFRSw = false;
    } else if (DoorLckCtl_DoorAjarFRTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_e--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms2' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift5' */
  /* Constant: '<S641>/Constant59' */
  rtb_Switch12 = AppSwcBcm_BitShift3(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift5' */

  /* Switch: '<S641>/Switch5' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND5'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch5' incorporates:
     *  Constant: '<S641>/Constant60'
     */
    rtb_Switch1 = DoorLckCtl_DriverDoorLckVal_C;
  } else {
    /* Switch: '<S641>/Switch5' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion5'
     */
    rtb_Switch1 = (BSW_J335DriverDoorLck != 0);
  }

  /* End of Switch: '<S641>/Switch5' */

  /* Chart: '<S641>/LIB_TPD_10ms' incorporates:
   *  Constant: '<S641>/Constant46'
   *  Constant: '<S641>/Constant47'
   *  Constant: '<S641>/Constant49'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_e >= (float32)
         DoorLckCtl_DriverDoorLckTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DriverDoorLckTimValid_C != 0xFFFF)) {
      DoorLckCtl_DriverDoorLckSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_e++;
      AppSwcBcm_ARID_DEF.cnt_heal_os = (uint16)((float32)
        DoorLckCtl_DriverDoorLckTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_e = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_os == 0) {
      DoorLckCtl_DriverDoorLckSw = false;
    } else if (DoorLckCtl_DriverDoorLckTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_os--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift3' */
  /* Constant: '<S641>/Constant11' */
  rtb_Switch12 = AppSwcBcm_BitShift1_j(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift3' */

  /* Switch: '<S641>/Switch3' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND3'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch3' incorporates:
     *  Constant: '<S641>/Constant12'
     */
    rtb_Switch1 = DoorLckCtl_DrvPEVal_C;
  } else {
    /* Switch: '<S641>/Switch3' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion3'
     *  Logic: '<S641>/Logical Operator6'
     */
    rtb_Switch1 = (BSW_J338DrvPE == 0);
  }

  /* End of Switch: '<S641>/Switch3' */

  /* Chart: '<S641>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S641>/Constant25'
   *  Constant: '<S641>/Constant26'
   *  Constant: '<S641>/Constant27'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_h >= (float32)DoorLckCtl_DrvPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_DrvPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_DrvPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_h++;
      AppSwcBcm_ARID_DEF.cnt_heal_mh = (uint16)((float32)
        DoorLckCtl_DrvPETimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_h = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_mh == 0) {
      DoorLckCtl_DrvPESw = false;
    } else if (DoorLckCtl_DrvPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_mh--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms3' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift4' */
  /* Constant: '<S641>/Constant13' */
  rtb_Switch12 = AppSwcBcm_BitShift2(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift4' */

  /* Switch: '<S641>/Switch4' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND4'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch4' incorporates:
     *  Constant: '<S641>/Constant14'
     */
    rtb_Switch1 = DoorLckCtl_PsgPEVal_C;
  } else {
    /* Switch: '<S641>/Switch4' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion4'
     *  Logic: '<S641>/Logical Operator7'
     */
    rtb_Switch1 = (BSW_J337PsgPE == 0);
  }

  /* End of Switch: '<S641>/Switch4' */

  /* Chart: '<S641>/LIB_TPD_10ms4' incorporates:
   *  Constant: '<S641>/Constant28'
   *  Constant: '<S641>/Constant29'
   *  Constant: '<S641>/Constant30'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_f >= (float32)DoorLckCtl_PsgPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_PsgPESw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_f++;
      AppSwcBcm_ARID_DEF.cnt_heal_ho = (uint16)((float32)
        DoorLckCtl_PsgPETimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_f = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_ho == 0) {
      DoorLckCtl_PsgPESw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_ho--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms4' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift6' */
  /* Constant: '<S641>/Constant15' */
  rtb_Switch12 = AppSwcBcm_BitShift8(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift6' */

  /* Switch: '<S641>/Switch6' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND6'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch6' incorporates:
     *  Constant: '<S641>/Constant16'
     */
    rtb_Switch1 = DoorLckCtl_TrunkSwVal_C;
  } else {
    /* Switch: '<S641>/Switch6' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion6'
     */
    rtb_Switch1 = (BSW_J336Trunk != 0);
  }

  /* End of Switch: '<S641>/Switch6' */

  /* Chart: '<S641>/LIB_TPD_10ms5' incorporates:
   *  Constant: '<S641>/Constant31'
   *  Constant: '<S641>/Constant32'
   *  Constant: '<S641>/Constant33'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_d >= (float32)DoorLckCtl_PsgPETimValid_C /
         (DoorLckCtl_Ts_C * 100.0F)) && (DoorLckCtl_PsgPETimValid_C != 0xFFFF))
    {
      DoorLckCtl_TrunkSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_d++;
      AppSwcBcm_ARID_DEF.cnt_heal_m = (uint16)((float32)
        DoorLckCtl_PsgPETimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_d = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_m == 0) {
      DoorLckCtl_TrunkSw = false;
    } else if (DoorLckCtl_PsgPETimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_m--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms5' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift7' */
  /* Constant: '<S641>/Constant17' */
  rtb_Switch12 = AppSwcBcm_BitShift9(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift7' */

  /* Switch: '<S641>/Switch7' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND7'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch7' incorporates:
     *  Constant: '<S641>/Constant18'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarRLVal_C;
  } else {
    /* Switch: '<S641>/Switch7' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion7'
     */
    rtb_Switch1 = (BSW_J320DoorAjarRL != 0);
  }

  /* End of Switch: '<S641>/Switch7' */

  /* Chart: '<S641>/LIB_TPD_10ms6' incorporates:
   *  Constant: '<S641>/Constant34'
   *  Constant: '<S641>/Constant35'
   *  Constant: '<S641>/Constant36'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_g >= (float32)
         DoorLckCtl_DoorAjarRLTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRLTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRLSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_g++;
      AppSwcBcm_ARID_DEF.cnt_heal_k = (uint16)((float32)
        DoorLckCtl_DoorAjarRLTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_g = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_k == 0) {
      DoorLckCtl_DoorAjarRLSw = false;
    } else if (DoorLckCtl_DoorAjarRLTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_k--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms6' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift8' */
  /* Constant: '<S641>/Constant19' */
  rtb_Switch12 = AppSwcBcm_BitShift3_b(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift8' */

  /* Switch: '<S641>/Switch8' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND8'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch8' incorporates:
     *  Constant: '<S641>/Constant20'
     */
    rtb_Switch1 = DoorLckCtl_DoorAjarRRVal_C;
  } else {
    /* Switch: '<S641>/Switch8' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion8'
     */
    rtb_Switch1 = (BSW_J36DoorAjarRR != 0);
  }

  /* End of Switch: '<S641>/Switch8' */

  /* Chart: '<S641>/LIB_TPD_10ms7' incorporates:
   *  Constant: '<S641>/Constant37'
   *  Constant: '<S641>/Constant38'
   *  Constant: '<S641>/Constant39'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_n >= (float32)
         DoorLckCtl_DoorAjarRRTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DoorAjarRRTimValid_C != 0xFFFF)) {
      DoorLckCtl_DoorAjarRRSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_n++;
      AppSwcBcm_ARID_DEF.cnt_heal_o = (uint16)((float32)
        DoorLckCtl_DoorAjarRRTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_n = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_o == 0) {
      DoorLckCtl_DoorAjarRRSw = false;
    } else if (DoorLckCtl_DoorAjarRRTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_o--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms7' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift9' */
  /* Constant: '<S641>/Constant21' */
  rtb_Switch12 = AppSwcBcm_BitShift10_k(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift9' */

  /* Switch: '<S641>/Switch9' incorporates:
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND9'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    /* Switch: '<S641>/Switch9' incorporates:
     *  Constant: '<S641>/Constant22'
     */
    rtb_Switch1 = DoorLckCtl_TrunkAjarVal_C;
  } else {
    /* Switch: '<S641>/Switch9' incorporates:
     *  DataTypeConversion: '<S641>/Data Type Conversion9'
     */
    rtb_Switch1 = (BSW_J37TrunkAjar != 0);
  }

  /* End of Switch: '<S641>/Switch9' */

  /* Chart: '<S641>/LIB_TPD_10ms8' incorporates:
   *  Constant: '<S641>/Constant40'
   *  Constant: '<S641>/Constant41'
   *  Constant: '<S641>/Constant42'
   */
  if (rtb_Switch1) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_j >= (float32)
         DoorLckCtl_TrunkAjarTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_TrunkAjarTimValid_C != 0xFFFF)) {
      DoorLckCtl_TrunkAjarSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_j++;
      AppSwcBcm_ARID_DEF.cnt_heal_n = (uint16)((float32)
        DoorLckCtl_TrunkAjarTimInvalid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_j = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_n == 0) {
      DoorLckCtl_TrunkAjarSw = false;
    } else if (DoorLckCtl_TrunkAjarTimInvalid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_n--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms8' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift12' */
  /* Constant: '<S641>/Constant62' */
  rtb_Switch12 = AppSwcBcm_BitShift11_f(DoorLckCtl_InportCalSwBit_C);

  /* End of Outputs for SubSystem: '<S641>/Bit Shift12' */

  /* Switch: '<S641>/Switch12' incorporates:
   *  Constant: '<S641>/Constant63'
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND12'
   */
  if ((rtb_Switch12 & 1U) != 0U) {
    tmp = DoorLckCtl_DrvSeatResisVal_C;
  } else {
    tmp = BSW_J112DrvSeatResis;
  }

  /* Chart: '<S641>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S641>/Constant64'
   *  Constant: '<S641>/Constant65'
   *  Constant: '<S641>/Constant66'
   *  Constant: '<S641>/Constant67'
   *  RelationalOperator: '<S641>/Relational Operator6'
   *  Switch: '<S641>/Switch12'
   */
  if (tmp <= DoorLckCtl_DrvSeatResisMin_C) {
    if ((AppSwcBcm_ARID_DEF.cnt_defect_hu >= (float32)
         DoorLckCtl_DrvSeatTimValid_C / (DoorLckCtl_Ts_C * 100.0F)) &&
        (DoorLckCtl_DrvSeatTimValid_C != 0xFFFF)) {
      DoorLckCtl_DrvSeatSw = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_hu++;
      AppSwcBcm_ARID_DEF.cnt_heal_j = (uint16)((float32)
        DoorLckCtl_DrvSeatTimInValid_C / (DoorLckCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_hu = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_j == 0) {
      DoorLckCtl_DrvSeatSw = false;
    } else if (DoorLckCtl_DrvSeatTimInValid_C != 0xFFFF) {
      AppSwcBcm_ARID_DEF.cnt_heal_j--;
    }
  }

  /* End of Chart: '<S641>/LIB_TPD_10ms11' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift13' */
  /* Switch: '<S641>/Switch13' incorporates:
   *  Constant: '<S641>/Constant71'
   *  Constant: '<S641>/Constant72'
   *  MATLAB Function: '<S734>/bit_shift'
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND13'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 12 & 1U) != 0U) {
    DoorLckCtl_EEKeyEntry = DoorLckCtl_EEKeyEntry_C;
  } else {
    DoorLckCtl_EEKeyEntry = BSW_EEKeyEntry;
  }

  /* End of Switch: '<S641>/Switch13' */
  /* End of Outputs for SubSystem: '<S641>/Bit Shift13' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift14' */
  /* Switch: '<S641>/Switch14' incorporates:
   *  Constant: '<S641>/Constant73'
   *  Constant: '<S641>/Constant74'
   *  MATLAB Function: '<S735>/bit_shift'
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND14'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 13 & 1U) != 0U) {
    DoorLckCtl_EEIlluminatedEntrySys = DoorLckCtl_EEIlluminatedEntrySys_C;
  } else {
    DoorLckCtl_EEIlluminatedEntrySys = BSW_EEIlluminatedEntrySys;
  }

  /* End of Switch: '<S641>/Switch14' */
  /* End of Outputs for SubSystem: '<S641>/Bit Shift14' */

  /* Outputs for Atomic SubSystem: '<S641>/Bit Shift15' */
  /* Switch: '<S641>/Switch15' incorporates:
   *  Constant: '<S641>/Constant75'
   *  Constant: '<S641>/Constant76'
   *  MATLAB Function: '<S736>/bit_shift'
   *  S-Function (sfix_bitop): '<S641>/Bitwise AND15'
   */
  if (((uint32)DoorLckCtl_InportCalSwBit_C >> 14 & 1U) != 0U) {
    DoorLckCtl_IllmndSts = DoorLckCtl_IllmndSts_C;
  } else {
    DoorLckCtl_IllmndSts = BSW_IllmndSts;
  }

  /* End of Switch: '<S641>/Switch15' */
  /* End of Outputs for SubSystem: '<S641>/Bit Shift15' */

  /* RelationalOperator: '<S641>/Relational Operator' incorporates:
   *  Constant: '<S641>/Constant'
   */
  rtb_Switch1 = (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpd_kph <
                 3.0F);

  /* Logic: '<S641>/Logical Operator1' incorporates:
   *  Logic: '<S641>/Logical Operator'
   *  RelationalOperator: '<S641>/Relational Operator2'
   */
  DoorLckCtl_VehStop =
    ((!AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg) ||
     rtb_Switch1);

  /* Logic: '<S641>/Logical Operator4' incorporates:
   *  Logic: '<S641>/Logical Operator2'
   *  Logic: '<S641>/Logical Operator3'
   *  RelationalOperator: '<S641>/Relational Operator1'
   */
  DoorLckCtl_VehRun = ((!rtb_Switch1) &&
                       AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg);

  /* Switch: '<S641>/Switch' incorporates:
   *  Constant: '<S641>/Constant54'
   *  RelationalOperator: '<S641>/Relational Operator5'
   */
  if (AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg) {
    DoorLckCtl_VehSpd =
      AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpd_kph;
  } else {
    DoorLckCtl_VehSpd = 0.0F;
  }

  /* End of Switch: '<S641>/Switch' */
}

/* ConstCode for atomic system: '<S601>/SignalProcess' */
static void AppSwcBcm_SignalProcess_g_Const(void)
{
  /* ConstCode for Constant: '<S641>/Constant69' */
  DoorLckCtl_HoodAjarSw = true;
}

/* System initialize for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S601>/DoorDrv' */
  AppSwcBcm_DoorDrv_Init();

  /* SystemInitialize for Atomic SubSystem: '<S601>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Init();

  /* End of SystemInitialize for SubSystem: '<S601>/DoorLckCtlLogic' */

  /* SystemInitialize for Atomic SubSystem: '<S601>/SignalProcess' */
  AppSwcBcm_SignalProcess_m_Init();

  /* End of SystemInitialize for SubSystem: '<S601>/SignalProcess' */
}

/* Outputs for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl(void)
{
  boolean rtb_DataTypeConversion1_p;

  /* Outputs for Atomic SubSystem: '<S601>/SignalProcess' */
  AppSwcBcm_SignalProcess_a();

  /* End of Outputs for SubSystem: '<S601>/SignalProcess' */

  /* Outputs for Atomic SubSystem: '<S601>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic();

  /* End of Outputs for SubSystem: '<S601>/DoorLckCtlLogic' */

  /* Chart: '<S601>/DoorDrv' */
  AppSwcBcm_DoorDrv();

  /* Outputs for Atomic SubSystem: '<S601>/Ovrd1' */
  /* Switch: '<S638>/Switch1' incorporates:
   *  Constant: '<S601>/Constant1'
   *  Constant: '<S601>/Constant2'
   *  Switch: '<S638>/Switch2'
   */
  if (DoorLckCtl_J54DoorLckOvrdFlg_C) {
    DoorLckCtl_J54DoorLck = DoorLckCtl_J54DoorLckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S601>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorLlckCtlFlg != 0);
    DoorLckCtl_J54DoorLck = (rtb_DataTypeConversion1_p ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J54);
  }

  /* End of Switch: '<S638>/Switch1' */
  /* End of Outputs for SubSystem: '<S601>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S601>/Ovrd2' */
  /* Switch: '<S639>/Switch1' incorporates:
   *  Constant: '<S601>/Constant3'
   *  Constant: '<S601>/Constant4'
   *  Switch: '<S639>/Switch2'
   */
  if (DoorLckCtl_J511TrunkUnlckOvrdFlg_C) {
    DoorLckCtl_J511TrunkUnlck = DoorLckCtl_J511TrunkUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S601>/Data Type Conversion2' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->TrunkUnlckCtlFlg != 0);
    DoorLckCtl_J511TrunkUnlck = (rtb_DataTypeConversion1_p ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J511);
  }

  /* End of Switch: '<S639>/Switch1' */
  /* End of Outputs for SubSystem: '<S601>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S601>/Ovrd3' */
  /* Switch: '<S640>/Switch1' incorporates:
   *  Constant: '<S601>/Constant18'
   *  Constant: '<S601>/Constant19'
   *  Switch: '<S640>/Switch2'
   */
  if (DoorLckCtl_J56DoorUnlckOvrdFlg_C) {
    DoorLckCtl_J56DoorUnlck = DoorLckCtl_J56DoorUnlckOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S601>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion1_p = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->DoorUnlckCtlFlg != 0);
    DoorLckCtl_J56DoorUnlck = (rtb_DataTypeConversion1_p ||
      AppSwcBcm_ARID_DEF.DoorLckCtl_J56);
  }

  /* End of Switch: '<S640>/Switch1' */
  /* End of Outputs for SubSystem: '<S601>/Ovrd3' */
}

/* ConstCode for atomic system: '<S4>/DoorLckCtl' */
static void AppSwcBcm_DoorLckCtl_Const(void)
{
  /* ConstCode for Atomic SubSystem: '<S601>/SignalProcess' */
  AppSwcBcm_SignalProcess_g_Const();

  /* End of ConstCode for SubSystem: '<S601>/SignalProcess' */

  /* ConstCode for Atomic SubSystem: '<S601>/DoorLckCtlLogic' */
  AppSwcBcm_DoorLckCtlLogic_Const();

  /* End of ConstCode for SubSystem: '<S601>/DoorLckCtlLogic' */
}

/* System initialize for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl_Init(void)
{
  /* SystemInitialize for Chart: '<S768>/LIB_TPD_10ms11' */
  AppSwcBcm_LIB_TPD_10ms_Init(&AppSwcBcm_ARID_DEF.LIB_bErrFlg);

  /* SystemInitialize for Chart: '<S768>/Lib_RiseEdgeDelay' */
  AppSwcBcm_Lib_RiseEdgeDelay_Init(&AppSwcBcm_ARID_DEF.LIB_blOut);
}

/* Output and update for atomic system: '<S4>/ESCLCtl' */
static void AppSwcBcm_ESCLCtl(void)
{
  sint32 tmp;
  uint8 rtb_Switch_at;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator5_pe;
  boolean rtb_RelationalOperator1_b4;
  boolean rtb_RelationalOperator1_ir;

  /* Chart: '<S768>/Lib_RiseEdgeDelay' incorporates:
   *  Constant: '<S768>/Constant6'
   *  RelationalOperator: '<S768>/Relational Operator'
   */
  AppSwcBcm_Lib_RiseEdgeDelay(AppSwcBcm_ARID_DEF.BusCreator4.OsLck, 2,
    &AppSwcBcm_ARID_DEF.LIB_blOut,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDelay);

  /* Logic: '<S768>/Logical Operator5' incorporates:
   *  Constant: '<S768>/Constant4'
   *  Constant: '<S768>/Constant5'
   *  Logic: '<S768>/Logical Operator4'
   *  RelationalOperator: '<S768>/Relational Operator4'
   *  RelationalOperator: '<S768>/Relational Operator5'
   *  RelationalOperator: '<S768>/Relational Operator6'
   */
  rtb_LogicalOperator5_pe =
    ((AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpd_kph == 0.0F) ||
     ((AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpd_kph < 5.0F) &&
      AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA.VIPM_ESCVehSpdVld_flg));

  /* RelationalOperator: '<S768>/Relational Operator1' incorporates:
   *  Constant: '<S768>/Constant1'
   */
  rtb_RelationalOperator1_b4 = (AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0);

  /* Logic: '<S768>/Logical Operator' incorporates:
   *  Constant: '<S768>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S768>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* RelationalOperator: '<S774>/Relational Operator1' incorporates:
   *  Constant: '<S768>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S768>/Relational Operator3'
   */
  rtb_RelationalOperator1_ir =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S768>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_RelationalOperator1_ir);

  /* RelationalOperator: '<S774>/Relational Operator1' incorporates:
   *  Constant: '<S774>/Constant1'
   *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
   */
  rtb_RelationalOperator1_ir =
    ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
      ())->VIPM_ESCLUnOrLockfeedback_nu == 648518346341351424ULL);

  /* Switch: '<S774>/Switch' */
  if (rtb_RelationalOperator1_ir) {
    /* Switch: '<S774>/Switch' incorporates:
     *  Constant: '<S774>/Constant2'
     */
    rtb_Switch_at = 2U;
  } else {
    /* RelationalOperator: '<S774>/Relational Operator' incorporates:
     *  Constant: '<S774>/Constant'
     *  Inport: '<Root>/IPM_ESCL_ESCLStatus_BOD'
     */
    rtb_RelationalOperator1_ir =
      ((Rte_IRead_Runbl_AppSwcBcm_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
        ())->VIPM_ESCLUnOrLockfeedback_nu == 1297036692682702848ULL);

    /* Switch: '<S774>/Switch' incorporates:
     *  Switch: '<S774>/Switch1'
     */
    rtb_Switch_at = rtb_RelationalOperator1_ir;
  }

  /* End of Switch: '<S774>/Switch' */

  /* Logic: '<S768>/Logical Operator1' */
  AppSwcBcm_ARID_DEF.Lib_blIn_h = (rtb_LogicalOperator5_pe &&
    AppSwcBcm_ARID_DEF.LIB_blOut && rtb_RelationalOperator1_b4 &&
    rtb_LogicalOperator);

  /* Chart: '<S768>/ESCLLck' incorporates:
   *  SubSystem: '<S769>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_m(AppSwcBcm_ARID_DEF.Lib_blIn_h,
    &AppSwcBcm_ARID_DEF.LogicalOperator_j,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_m);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_j) {
    AppSwcBcm_ARID_DEF.Flg_e = true;
    AppSwcBcm_ARID_DEF.Cnt_d = 0U;
    ESCLCtl_J436Lck = true;
    AppSwcBcm_ARID_DEF.Cnt2_j = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_e) {
    tmp = AppSwcBcm_ARID_DEF.Cnt2_j + 1;
    if (AppSwcBcm_ARID_DEF.Cnt2_j + 1 > 65535) {
      tmp = 65535;
    }

    AppSwcBcm_ARID_DEF.Cnt2_j = (uint16)tmp;
    if (AppSwcBcm_ARID_DEF.Cnt_d >= ESCLCtl_LckDelay_C) {
      ESCLCtl_Lck = 2U;
    } else {
      AppSwcBcm_ARID_DEF.Cnt_d++;
    }
  }

  if (rtb_Switch_at == 2) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_e = false;
    ESCLCtl_Lck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2_j >= ESCLCtl_LckTimMax_C) {
    ESCLCtl_J436Lck = false;
    AppSwcBcm_ARID_DEF.Flg_e = false;
    ESCLCtl_Lck = 0U;
  }

  /* Chart: '<S768>/LIB_TPD_10ms11' incorporates:
   *  Constant: '<S768>/Constant7'
   *  Constant: '<S768>/Constant8'
   */
  AppSwcBcm_LIB_TPD_10ms(rtb_RelationalOperator1_b4, 5, 0.05F,
    &AppSwcBcm_ARID_DEF.LIB_bErrFlg, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_TPD_10ms11);

  /* Logic: '<S768>/Logical Operator2' */
  AppSwcBcm_ARID_DEF.Lib_blIn_g = (AppSwcBcm_ARID_DEF.UnitDelay1.PwrOn &&
    AppSwcBcm_ARID_DEF.LIB_bErrFlg && rtb_LogicalOperator &&
    rtb_LogicalOperator5_pe);

  /* Chart: '<S768>/ESCLUnlck' incorporates:
   *  SubSystem: '<S770>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_m(AppSwcBcm_ARID_DEF.Lib_blIn_g,
    &AppSwcBcm_ARID_DEF.LogicalOperator_i,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet_g);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_i) {
    AppSwcBcm_ARID_DEF.Flg_a = true;
    AppSwcBcm_ARID_DEF.Cnt_e = 0U;
    ESCLCtl_J436Unlck = true;
    AppSwcBcm_ARID_DEF.Cnt2 = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg_a) {
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

  if (rtb_Switch_at == 1) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_a = false;
    ESCLCtl_Unlck = 0U;
  } else if (AppSwcBcm_ARID_DEF.Cnt2 >= ESCLCtl_UnlckTimMax_C) {
    ESCLCtl_J436Unlck = false;
    AppSwcBcm_ARID_DEF.Flg_a = false;
    ESCLCtl_Unlck = 0U;
  }

  /* Outputs for Atomic SubSystem: '<S768>/Ovrd' */
  /* Switch: '<S773>/Switch' incorporates:
   *  Constant: '<S768>/Constant18'
   */
  if (ESCLCtl_J436PwrSupOvrdFlg_C) {
    /* Switch: '<S773>/Switch' incorporates:
     *  Constant: '<S768>/Constant19'
     */
    ESCLCtl_J436PwrSup = ESCLCtl_J436PwrSupOvrdVal_C;
  } else {
    /* Switch: '<S773>/Switch' incorporates:
     *  Logic: '<S768>/Logical Operator3'
     */
    ESCLCtl_J436PwrSup = (ESCLCtl_J436Lck || ESCLCtl_J436Unlck);
  }

  /* End of Switch: '<S773>/Switch' */
  /* End of Outputs for SubSystem: '<S768>/Ovrd' */

  /* Truth Table: '<S768>/Truth Table' */
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

  /* End of Truth Table: '<S768>/Truth Table' */
}

/* System initialize for atomic system: '<S4>/IMMOCtl' */
static void AppSwcBcm_IMMOCtl_Init(void)
{
  sint32 i;
  for (i = 0; i < 8; i++) {
    /* SystemInitialize for Chart: '<S603>/IMMOCtl' */
    AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i] = MAX_uint8_T;

    /* SystemInitialize for SignalConversion generated from: '<S603>/IMMOCtl' */
    IMMOCtl_AuthResp[i] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i];
  }

  for (i = 0; i < 16; i++) {
    /* SystemInitialize for SignalConversion generated from: '<S603>/IMMOCtl' */
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

  /* SignalConversion: '<S603>/Signal Conversion' incorporates:
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

  /* Chart: '<S603>/IMMOCtl' */
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
    /* SignalConversion generated from: '<S603>/IMMOCtl' */
    IMMOCtl_SKRead[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_SKRead_b[i_0];
  }

  for (i_0 = 0; i_0 < 8; i_0++) {
    /* SignalConversion generated from: '<S603>/IMMOCtl' */
    IMMOCtl_AuthResp[i_0] = AppSwcBcm_ARID_DEF.IMMOCtl_AuthResp_b[i_0];
  }

  /* SignalConversion generated from: '<S603>/IMMOCtl' incorporates:
   *  Chart: '<S603>/IMMOCtl'
   */
  IMMOCtl_SKSta = (uint8)(b_k == 16);
}

/* Output and update for atomic system: '<S604>/Chart' */
static void AppSwcBcm_Chart(void)
{
  /* Chart: '<S604>/Chart' incorporates:
   *  UnitDelay: '<S604>/Unit Delay3'
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

  /* End of Chart: '<S604>/Chart' */
}

/* Output and update for atomic system: '<S604>/PwrOff' */
static void AppSwcBcm_PwrOff(void)
{
  sint32 tmp;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator1_gx;
  boolean rtb_LogicalOperator2_i;
  boolean rtb_LogicalOperator2_o2;
  boolean rtb_RelationalOperator11_n;
  boolean rtb_RelationalOperator4_d;
  boolean rtb_RelationalOperator5_fm;

  /* Logic: '<S787>/Logical Operator' incorporates:
   *  Constant: '<S787>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S787>/Relational Operator2'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VGSM_VehActGearPstn_enum == 0);

  /* Logic: '<S787>/Logical Operator1' incorporates:
   *  Constant: '<S787>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S787>/Relational Operator3'
   */
  rtb_LogicalOperator1_gx =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VGSM_VehActGearPstn_enum == 1);

  /* Logic: '<S787>/Logical Operator' */
  rtb_LogicalOperator = (rtb_LogicalOperator || rtb_LogicalOperator1_gx);

  /* Logic: '<S787>/Logical Operator1' incorporates:
   *  Constant: '<S787>/Constant'
   *  Constant: '<S787>/Constant10'
   *  Constant: '<S787>/Constant11'
   *  Logic: '<S787>/Logical Operator7'
   *  RelationalOperator: '<S787>/Relational Operator'
   *  RelationalOperator: '<S787>/Relational Operator6'
   *  RelationalOperator: '<S787>/Relational Operator7'
   *  UnitDelay: '<S604>/Unit Delay'
   *  UnitDelay: '<S604>/Unit Delay2'
   */
  rtb_LogicalOperator1_gx = (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n == 2) ||
    (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n == 1)) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 2) && rtb_LogicalOperator);

  /* RelationalOperator: '<S787>/Relational Operator11' */
  rtb_RelationalOperator11_n = !AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;

  /* Outputs for Atomic SubSystem: '<S787>/Lib_BothEdgeDet' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
    &rtb_LogicalOperator2_i, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet);

  /* End of Outputs for SubSystem: '<S787>/Lib_BothEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S787>/Lib_BothEdgeDet1' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
    &rtb_LogicalOperator2_o2, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet1);

  /* End of Outputs for SubSystem: '<S787>/Lib_BothEdgeDet1' */

  /* Outputs for Atomic SubSystem: '<S787>/Lib_BothEdgeDet2' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw,
    &rtb_RelationalOperator4_d, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet2);

  /* End of Outputs for SubSystem: '<S787>/Lib_BothEdgeDet2' */

  /* Outputs for Atomic SubSystem: '<S787>/Lib_BothEdgeDet3' */
  AppSwcBcm_Lib_BothEdgeDet(AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw,
    &rtb_RelationalOperator5_fm, &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_BothEdgeDet3);

  /* End of Outputs for SubSystem: '<S787>/Lib_BothEdgeDet3' */

  /* Logic: '<S787>/Logical Operator2' incorporates:
   *  Logic: '<S787>/Logical Operator3'
   */
  rtb_RelationalOperator5_fm = ((!rtb_LogicalOperator2_i) &&
    (!rtb_LogicalOperator2_o2) && (!rtb_RelationalOperator4_d) &&
    (!rtb_RelationalOperator5_fm));

  /* RelationalOperator: '<S787>/Relational Operator4' incorporates:
   *  Constant: '<S787>/Constant17'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S787>/Relational Operator1'
   */
  rtb_RelationalOperator4_d =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VIPC_VehHiddenMode_enum != 1);

  /* Chart: '<S787>/LIB_Tim' incorporates:
   *  Constant: '<S787>/Constant4'
   *  Constant: '<S787>/Constant5'
   *  Constant: '<S787>/Constant6'
   *  Constant: '<S787>/Constant7'
   *  Logic: '<S787>/Logical Operator4'
   *  RelationalOperator: '<S787>/Relational Operator12'
   */
  if (AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator11_n &&
      rtb_LogicalOperator1_gx && rtb_RelationalOperator5_fm &&
      rtb_RelationalOperator4_d) {
    if ((AppSwcBcm_ARID_DEF.Cnt_H >= PDUCtl_TimOutPwrOffH_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_M >= PDUCtl_TimOutPwrOffM_C) &&
        (AppSwcBcm_ARID_DEF.Cnt_S >= PDUCtl_TimOutPwrOffS_C)) {
      rtb_RelationalOperator4_d = true;
    } else {
      tmp = AppSwcBcm_ARID_DEF.Cnt_Tick + 1;
      if (AppSwcBcm_ARID_DEF.Cnt_Tick + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt_Tick = (uint16)tmp;
      rtb_RelationalOperator4_d = false;
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
    rtb_RelationalOperator4_d = false;
    AppSwcBcm_ARID_DEF.Cnt_Tick = 0U;
    AppSwcBcm_ARID_DEF.Cnt_S = 0U;
    AppSwcBcm_ARID_DEF.Cnt_M = 0U;
    AppSwcBcm_ARID_DEF.Cnt_H = 0U;
  }

  /* End of Chart: '<S787>/LIB_Tim' */

  /* RelationalOperator: '<S787>/Relational Operator5' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator5_fm = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_HU_B_BAC())
    ->VIPM_HUPwrOffReq_flg;

  /* Logic: '<S787>/Logical Operator6' incorporates:
   *  Constant: '<S787>/Constant12'
   *  Constant: '<S787>/Constant13'
   *  Constant: '<S787>/Constant14'
   *  Logic: '<S787>/Logical Operator10'
   *  Logic: '<S787>/Logical Operator11'
   *  Logic: '<S787>/Logical Operator5'
   *  Logic: '<S787>/Logical Operator8'
   *  Logic: '<S787>/Logical Operator9'
   *  RelationalOperator: '<S787>/Relational Operator10'
   *  RelationalOperator: '<S787>/Relational Operator12'
   *  RelationalOperator: '<S787>/Relational Operator4'
   *  RelationalOperator: '<S787>/Relational Operator8'
   *  RelationalOperator: '<S787>/Relational Operator9'
   *  UnitDelay: '<S604>/Unit Delay'
   *  UnitDelay: '<S604>/Unit Delay2'
   */
  PDUCtl_PwrOff = ((rtb_LogicalOperator && rtb_RelationalOperator11_n &&
                    (((AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n != 3) ||
                      (AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n != 5)) &&
                     (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 2)) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.OsLck &&
                    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
                     AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
                     AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw) &&
                    AppSwcBcm_ARID_DEF.BusCreator4.VehStop) ||
                   (rtb_RelationalOperator5_fm &&
                    AppSwcBcm_ARID_DEF.BusCreator4.VehStop &&
                    rtb_LogicalOperator1_gx) || rtb_RelationalOperator4_d);
}

/*
 * Output and update for atomic system:
 *    '<S788>/Lib_FailEdgeDet'
 *    '<S788>/Lib_FailEdgeDet1'
 */
static boolean AppSwcBcm_Lib_FailEdgeDet_ja(boolean rtu_Lib_blIn,
  ARID_DEF_Lib_FailEdgeDet_AppSwcBcm_k_T *AppSwcBcm__ARID_DEF_arg)
{
  boolean rty_Lib_blOut_0;

  /* Logic: '<S800>/Logical Operator' incorporates:
   *  Logic: '<S800>/Logical Operator1'
   *  UnitDelay: '<S800>/Unit Delay'
   */
  rty_Lib_blOut_0 = ((!rtu_Lib_blIn) &&
                     AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE);

  /* Update for UnitDelay: '<S800>/Unit Delay' */
  AppSwcBcm__ARID_DEF_arg->UnitDelay_DSTATE = rtu_Lib_blIn;
  return rty_Lib_blOut_0;
}

/* System initialize for atomic system: '<S604>/PwrOn' */
static void AppSwcBcm_PwrOn_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_c3;

  /* SystemInitialize for Chart: '<S788>/LIB_Tim' */
  AppSwcBcm_LIB_NegPluse_Init(&rtb_LIB_blOut_c3);
}

/* Output and update for atomic system: '<S604>/PwrOn' */
static void AppSwcBcm_PwrOn(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_c3;
  sint32 tmp;
  boolean rtb_LIB_blOut_g;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator3_di;
  boolean rtb_LogicalOperator_ar;
  boolean rtb_RelationalOperator1_ho;
  boolean rtb_RelationalOperator5_o;

  /* RelationalOperator: '<S788>/Relational Operator4' incorporates:
   *  Constant: '<S788>/Constant'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn_e = (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 1);

  /* Logic: '<S788>/Logical Operator8' incorporates:
   *  Constant: '<S788>/Constant7'
   *  RelationalOperator: '<S788>/Relational Operator6'
   *  UnitDelay: '<S788>/Unit Delay'
   */
  AppSwcBcm_ARID_DEF.Lib_blIn = (AppSwcBcm_ARID_DEF.Lib_blIn_e || PDUCtl_PwrOn ||
    (AppSwcBcm_ARID_DEF.BusCreator4.OsLckSta == 2));

  /* Chart: '<S788>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S798>/Lib_RiseEdgeDet'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn,
    &AppSwcBcm_ARID_DEF.LogicalOperator_d,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet);
  if (AppSwcBcm_ARID_DEF.LogicalOperator_d) {
    AppSwcBcm_ARID_DEF.Cnt = 0U;
    AppSwcBcm_ARID_DEF.Flg = false;
  }

  /* Chart: '<S788>/LIB_NegPluse1' incorporates:
   *  SubSystem: '<S798>/Lib_RiseEdgeDet1'
   */
  AppSwcBcm_Lib_RiseEdgeDet_c(AppSwcBcm_ARID_DEF.Lib_blIn_e,
    &AppSwcBcm_ARID_DEF.LogicalOperator,
    &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_RiseEdgeDet1);
  if (AppSwcBcm_ARID_DEF.LogicalOperator) {
    AppSwcBcm_ARID_DEF.Flg = true;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  if (AppSwcBcm_ARID_DEF.Flg) {
    /* Constant: '<S788>/Constant6' */
    if (AppSwcBcm_ARID_DEF.Cnt <= PDUCtl_OpenDoorPwrOnTimValid) {
      tmp = AppSwcBcm_ARID_DEF.Cnt + 1;
      if (AppSwcBcm_ARID_DEF.Cnt + 1 > 65535) {
        tmp = 65535;
      }

      AppSwcBcm_ARID_DEF.Cnt = (uint16)tmp;
      rtb_LIB_blOut_g = true;
    } else {
      rtb_LIB_blOut_g = false;
      AppSwcBcm_ARID_DEF.Flg = false;
    }

    /* End of Constant: '<S788>/Constant6' */
  } else {
    rtb_LIB_blOut_g = false;
    AppSwcBcm_ARID_DEF.Cnt = 0U;
  }

  /* RelationalOperator: '<S788>/Relational Operator5' incorporates:
   *  Constant: '<S788>/Constant8'
   */
  rtb_RelationalOperator5_o = (AppSwcBcm_ARID_DEF.BusCreator14.SKSta == 1);

  /* Outputs for Atomic SubSystem: '<S788>/Lib_FailEdgeDet' */
  rtb_LogicalOperator = AppSwcBcm_Lib_FailEdgeDet_ja
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet);

  /* End of Outputs for SubSystem: '<S788>/Lib_FailEdgeDet' */

  /* Outputs for Atomic SubSystem: '<S788>/Lib_FailEdgeDet1' */
  rtb_LogicalOperator_ar = AppSwcBcm_Lib_FailEdgeDet_ja
    (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw,
     &AppSwcBcm_ARID_DEF.ARID_DEF_Lib_FailEdgeDet1);

  /* End of Outputs for SubSystem: '<S788>/Lib_FailEdgeDet1' */

  /* Logic: '<S788>/Logical Operator3' incorporates:
   *  Constant: '<S788>/Constant4'
   *  Constant: '<S788>/Constant5'
   *  RelationalOperator: '<S788>/Relational Operator'
   *  RelationalOperator: '<S788>/Relational Operator3'
   *  UnitDelay: '<S604>/Unit Delay'
   *  UnitDelay: '<S604>/Unit Delay1'
   */
  rtb_LogicalOperator3_di = ((AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_g == 0) &&
    (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l == 0));

  /* Switch: '<S803>/Switch' incorporates:
   *  Constant: '<S788>/Constant11'
   *  Constant: '<S788>/Constant12'
   *  Logic: '<S788>/Logical Operator6'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    rtb_LIB_blOut_g = PDUCtl_KeyValidOvrdVal_C;
  } else {
    rtb_LIB_blOut_g = (rtb_LIB_blOut_g || rtb_RelationalOperator5_o);
  }

  /* Logic: '<S788>/Logical Operator' incorporates:
   *  Logic: '<S788>/Logical Operator4'
   *  Switch: '<S803>/Switch'
   */
  rtb_LIB_blOut_g = (rtb_LIB_blOut_g && (rtb_LogicalOperator_ar ||
    rtb_LogicalOperator) && rtb_LogicalOperator3_di);

  /* RelationalOperator: '<S788>/Relational Operator1' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator1_ho = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->BrakeLightSw;

  /* Chart: '<S788>/LIB_Tim' incorporates:
   *  Constant: '<S788>/Constant3'
   */
  AppSwcBcm_LIB_NegPluse(rtb_RelationalOperator1_ho, PDUCtl_PwrOnPSTimValid_C,
    &rtb_LIB_blOut_c3, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_Tim);

  /* Switch: '<S802>/Switch' incorporates:
   *  Constant: '<S788>/Constant9'
   */
  if (PDUCtl_KeyValidOvrdFlg_C) {
    /* Switch: '<S802>/Switch' incorporates:
     *  Constant: '<S788>/Constant10'
     */
    rtb_RelationalOperator5_o = PDUCtl_KeyValidOvrdVal_C;
  } else {
    /* RelationalOperator: '<S788>/Relational Operator2' incorporates:
     *  Constant: '<S788>/Constant2'
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
     */
    rtb_RelationalOperator1_ho = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus
      ())->KeySta != 0);

    /* Switch: '<S802>/Switch' incorporates:
     *  Logic: '<S788>/Logical Operator7'
     */
    rtb_RelationalOperator5_o = (rtb_RelationalOperator1_ho ||
      rtb_RelationalOperator5_o);
  }

  /* End of Switch: '<S802>/Switch' */

  /* Logic: '<S817>/Logical Operator10' incorporates:
   *  Logic: '<S788>/Logical Operator5'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_LIB_blOut_c3 &&
    rtb_RelationalOperator5_o);

  /* Logic: '<S788>/Logical Operator2' incorporates:
   *  Logic: '<S788>/Logical Operator1'
   */
  PDUCtl_PwrOn = (rtb_LIB_blOut_g || (rtb_LogicalOperator3_di &&
    AppSwcBcm_ARID_DEF.LogicalOperator10));
}

/* Output and update for atomic system: '<S604>/RelayDig' */
static void AppSwcBcm_RelayDig(void)
{
  float32 tmp;
  boolean rtb_RelationalOperator3_cc;
  boolean rtb_RelationalOperator7_m;

  /* RelationalOperator: '<S789>/Relational Operator3' incorporates:
   *  Constant: '<S789>/Constant2'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S789>/Relational Operator2'
   */
  rtb_RelationalOperator3_cc =
    ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
     ->VHVM_PTActOprtMode_enum != 2);

  /* RelationalOperator: '<S789>/Relational Operator7' incorporates:
   *  Constant: '<S789>/Constant'
   *  Logic: '<S789>/Logical Operator'
   *  RelationalOperator: '<S789>/Relational Operator'
   */
  rtb_RelationalOperator7_m = ((PDUCtl_SysPwrMode == 2) &&
    AppSwcBcm_ARID_DEF.BusCreator4.VehStop && rtb_RelationalOperator3_cc);

  /* RelationalOperator: '<S789>/Relational Operator3' incorporates:
   *  Constant: '<S789>/Constant3'
   */
  rtb_RelationalOperator3_cc = (PDUCtl_SysPwrMode == 0);

  /* RelationalOperator: '<S789>/Relational Operator7' incorporates:
   *  Logic: '<S789>/Logical Operator1'
   */
  rtb_RelationalOperator7_m = (rtb_RelationalOperator3_cc ||
    rtb_RelationalOperator7_m);

  /* Chart: '<S789>/LIB_TPD_10ms1' incorporates:
   *  Constant: '<S789>/Constant6'
   *  Constant: '<S789>/Constant7'
   *  Logic: '<S789>/Logical Operator3'
   *  RelationalOperator: '<S789>/Relational Operator5'
   */
  if (rtb_RelationalOperator7_m && (PDUCtl_J437IG2RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller35)) {
    tmp = 50.0F / (PDUCtl_Ts_C * 100.0F);
    if (AppSwcBcm_ARID_DEF.cnt_defect_m >= tmp) {
      PDUCtl_IG2RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_m++;
      AppSwcBcm_ARID_DEF.cnt_heal_h = (uint16)tmp;
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_m = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_h == 0) {
      PDUCtl_IG2RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_h--;
    }
  }

  /* End of Chart: '<S789>/LIB_TPD_10ms1' */

  /* Chart: '<S789>/LIB_TPD_10ms2' incorporates:
   *  Constant: '<S789>/Constant4'
   *  Constant: '<S789>/Constant5'
   *  Constant: '<S789>/Constant8'
   *  Logic: '<S789>/Logical Operator2'
   *  RelationalOperator: '<S789>/Relational Operator4'
   */
  if (rtb_RelationalOperator7_m && (PDUCtl_J421IG1RlyCtl !=
       AppSwcBcm_ARID_DEF.CCaller36)) {
    if (AppSwcBcm_ARID_DEF.cnt_defect_p >= 50.0F / (PDUCtl_Ts_C * 100.0F)) {
      PDUCtl_IG1RelayFault = true;
    } else {
      AppSwcBcm_ARID_DEF.cnt_defect_p++;
      AppSwcBcm_ARID_DEF.cnt_heal_a = (uint16)(50.0F / (PDUCtl_Ts_C * 100.0F));
    }
  } else {
    AppSwcBcm_ARID_DEF.cnt_defect_p = 0U;
    if (AppSwcBcm_ARID_DEF.cnt_heal_a == 0) {
      PDUCtl_IG1RelayFault = false;
    } else {
      AppSwcBcm_ARID_DEF.cnt_heal_a--;
    }
  }

  /* End of Chart: '<S789>/LIB_TPD_10ms2' */

  /* Switch: '<S789>/Switch' incorporates:
   *  Logic: '<S789>/Logical Operator4'
   */
  PDUCtl_SysPwrModeV = ((!PDUCtl_IG1RelayFault) && (!PDUCtl_IG2RelayFault));

  /* Chart: '<S789>/LIB_TPD_10ms3' incorporates:
   *  Constant: '<S789>/Constant1'
   *  Constant: '<S789>/Constant12'
   *  Constant: '<S789>/Constant13'
   *  Constant: '<S789>/Constant14'
   *  Constant: '<S789>/Constant15'
   *  Constant: '<S789>/Constant16'
   *  Constant: '<S789>/Constant17'
   *  Constant: '<S789>/Constant18'
   *  Logic: '<S789>/Logical Operator5'
   *  Logic: '<S789>/Logical Operator6'
   *  Logic: '<S789>/Logical Operator7'
   *  RelationalOperator: '<S789>/Relational Operator1'
   *  RelationalOperator: '<S789>/Relational Operator6'
   *  RelationalOperator: '<S789>/Relational Operator7'
   *  RelationalOperator: '<S789>/Relational Operator8'
   *  RelationalOperator: '<S789>/Relational Operator9'
   */
  if (((AppSwcBcm_ARID_DEF.CCaller35 == 1) || (AppSwcBcm_ARID_DEF.CCaller36 == 1))
      && ((AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 1) ||
          (AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 3) ||
          (AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts == 2)) &&
      rtb_RelationalOperator3_cc) {
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

  /* End of Chart: '<S789>/LIB_TPD_10ms3' */
}

/* System initialize for atomic system: '<S604>/StartReq' */
static void AppSwcBcm_StartReq_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_bb;
  boolean rtb_LIB_blOut_kn;

  /* SystemInitialize for Chart: '<S790>/LIB_PosPluse' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_kn);

  /* SystemInitialize for Chart: '<S790>/LIB_PosPluse1' */
  AppSwcBcm_LIB_PosPluse_Init(&rtb_LIB_blOut_bb);
}

/* Output and update for atomic system: '<S604>/StartReq' */
static void AppSwcBcm_StartReq(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_bb;
  boolean rtb_LIB_blOut_kn;
  boolean rtb_LogicalOperator;
  boolean rtb_UnitDelay_b3;

  /* UnitDelay: '<S813>/Unit Delay' incorporates:
   *  Constant: '<S790>/Constant'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S790>/Relational Operator1'
   */
  rtb_UnitDelay_b3 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
                      ->VHVM_PTActOprtMode_enum != 2);

  /* Logic: '<S790>/Logical Operator' incorporates:
   *  Constant: '<S790>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S790>/Relational Operator3'
   */
  rtb_LogicalOperator = ((PDUCtl_SysPwrMode == 2) &&
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw);

  /* Chart: '<S790>/LIB_PosPluse' incorporates:
   *  Constant: '<S790>/Constant4'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator, PDUCtl_StartReqTimValid_C,
    &rtb_LIB_blOut_kn, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse);

  /* Logic: '<S790>/Logical Operator1' incorporates:
   *  Constant: '<S790>/Constant1'
   *  RelationalOperator: '<S790>/Relational Operator'
   *  RelationalOperator: '<S790>/Relational Operator2'
   *  RelationalOperator: '<S790>/Relational Operator7'
   */
  rtb_UnitDelay_b3 = (PDUCtl_SysPwrModeV && AppSwcBcm_ARID_DEF.LogicalOperator10
                      && rtb_LIB_blOut_kn && (PDUCtl_SysPowerSts == 1) &&
                      rtb_UnitDelay_b3);

  /* RelationalOperator: '<S790>/Relational Operator6' incorporates:
   *  Constant: '<S790>/Constant7'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S790>/Relational Operator5'
   */
  rtb_LogicalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VHVM_PTActOprtMode_enum != 2);

  /* Chart: '<S790>/LIB_PosPluse1' incorporates:
   *  Constant: '<S790>/Constant5'
   *  Logic: '<S790>/Logical Operator3'
   *  UnitDelay: '<S790>/Unit Delay'
   */
  AppSwcBcm_LIB_PosPluse(rtb_LogicalOperator &&
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du, PDUCtl_StartReqOverTimValid_C,
    &rtb_LIB_blOut_bb, &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_PosPluse1);

  /* Outputs for Atomic SubSystem: '<S790>/Lib_SR' */
  /* Outputs for Atomic SubSystem: '<S790>/Lib_RiseEdgeDetHold' */
  /* Switch: '<S814>/Switch' incorporates:
   *  Constant: '<S790>/Constant6'
   *  Logic: '<S790>/Logical Operator2'
   *  Logic: '<S790>/Logical Operator4'
   *  Logic: '<S813>/Logical Operator'
   *  Logic: '<S813>/Logical Operator1'
   *  RelationalOperator: '<S790>/Relational Operator4'
   *  RelationalOperator: '<S790>/Relational Operator6'
   *  Switch: '<S815>/Switch'
   *  UnitDelay: '<S813>/Unit Delay'
   */
  if (((!AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw) &&
       AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bv &&
       (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) || (PDUCtl_SysPwrMode ==
       0) || rtb_LIB_blOut_bb) {
    /* Switch: '<S814>/Switch' incorporates:
     *  Constant: '<S814>/Constant'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e = false;

    /* Switch: '<S815>/Switch' incorporates:
     *  Constant: '<S815>/Constant'
     */
    PDUCtl_StartReq = false;
  } else {
    /* Switch: '<S814>/Switch' incorporates:
     *  Logic: '<S814>/Logical Operator'
     *  Logic: '<S814>/Logical Operator1'
     *  Logic: '<S814>/Logical Operator2'
     *  UnitDelay: '<S814>/Unit Delay'
     *  UnitDelay: '<S814>/Unit Delay1'
     */
    AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e = ((rtb_UnitDelay_b3 &&
      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mt)) ||
      AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e);

    /* Switch: '<S815>/Switch' incorporates:
     *  Logic: '<S815>/Logical Operator'
     *  UnitDelay: '<S815>/Unit Delay'
     */
    PDUCtl_StartReq = (AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_e || PDUCtl_StartReq);
  }

  /* End of Switch: '<S814>/Switch' */
  /* End of Outputs for SubSystem: '<S790>/Lib_SR' */

  /* Update for UnitDelay: '<S814>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_mt = rtb_UnitDelay_b3;

  /* End of Outputs for SubSystem: '<S790>/Lib_RiseEdgeDetHold' */

  /* Update for UnitDelay: '<S790>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_du = PDUCtl_StartReq;

  /* Update for UnitDelay: '<S813>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_bv =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvSeatSw;
}

/* Output and update for atomic system: '<S604>/Subsystem' */
static void AppSwcBcm_Subsystem(void)
{
  boolean rtb_RelationalOperator;
  boolean rtb_RelationalOperator1_ik;

  /* RelationalOperator: '<S791>/Relational Operator' incorporates:
   *  Constant: '<S791>/Constant'
   */
  rtb_RelationalOperator = (AppSwcBcm_ARID_DEF.CCaller36 == 1);

  /* RelationalOperator: '<S791>/Relational Operator1' incorporates:
   *  Constant: '<S791>/Constant1'
   */
  rtb_RelationalOperator1_ik = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* Switch: '<S791>/Switch' incorporates:
   *  Logic: '<S791>/Logical Operator'
   *  Logic: '<S791>/Logical Operator1'
   *  Logic: '<S791>/Logical Operator2'
   *  Logic: '<S791>/Logical Operator3'
   *  Switch: '<S791>/Switch1'
   */
  if (rtb_RelationalOperator && rtb_RelationalOperator1_ik) {
    /* Switch: '<S791>/Switch' incorporates:
     *  Constant: '<S791>/Constant2'
     */
    PDUCtl_SysPwrModeAct = 2U;
  } else if ((!rtb_RelationalOperator) && (!rtb_RelationalOperator1_ik)) {
    /* Switch: '<S791>/Switch1' incorporates:
     *  Constant: '<S791>/Constant3'
     *  Switch: '<S791>/Switch'
     */
    PDUCtl_SysPwrModeAct = 0U;
  }

  /* End of Switch: '<S791>/Switch' */
}

/* Output and update for atomic system: '<S604>/Truth Table' */
static void AppSwcBcm_TruthTable_o(void)
{
  /* UnitDelay: '<S784>/Unit Delay' */
  /*  Example condition 1 */
  if (AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0) {
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

  /* End of UnitDelay: '<S784>/Unit Delay' */
}

/* System initialize for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S604>/PwrOn' */
  AppSwcBcm_PwrOn_Init();

  /* End of SystemInitialize for SubSystem: '<S604>/PwrOn' */

  /* SystemInitialize for Atomic SubSystem: '<S604>/StartReq' */
  AppSwcBcm_StartReq_Init();

  /* End of SystemInitialize for SubSystem: '<S604>/StartReq' */
}

/* Output and update for atomic system: '<S4>/PDUCtl' */
static void AppSwcBcm_PDUCtl(void)
{
  boolean rtb_DataTypeConversion_c;

  /* Chart: '<S604>/Chart' */
  AppSwcBcm_Chart();

  /* Outputs for Atomic SubSystem: '<S604>/PwrOn' */
  AppSwcBcm_PwrOn();

  /* End of Outputs for SubSystem: '<S604>/PwrOn' */

  /* Outputs for Atomic SubSystem: '<S604>/PwrOff' */
  AppSwcBcm_PwrOff();

  /* End of Outputs for SubSystem: '<S604>/PwrOff' */

  /* Outputs for Atomic SubSystem: '<S604>/Lib_SR' */
  /* Switch: '<S784>/Switch' incorporates:
   *  Constant: '<S784>/Constant'
   *  Logic: '<S784>/Logical Operator'
   *  UnitDelay: '<S784>/Unit Delay'
   */
  if (PDUCtl_PwrOff) {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0 = false;
  } else {
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0 = (PDUCtl_PwrOn ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n0);
  }

  /* End of Switch: '<S784>/Switch' */
  /* End of Outputs for SubSystem: '<S604>/Lib_SR' */

  /* Truth Table: '<S604>/Truth Table' */
  AppSwcBcm_TruthTable_o();

  /* Outputs for Atomic SubSystem: '<S604>/Ovrd1' */
  /* Switch: '<S785>/Switch1' incorporates:
   *  Constant: '<S604>/Constant18'
   *  Constant: '<S604>/Constant19'
   */
  if (PDUCtl_J421IG1RlyCtlOvrdFlg_C) {
    PDUCtl_J421IG1RlyCtl = (uint8)PDUCtl_J421IG1RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S604>/Data Type Conversion' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG1RlyCtlFlg != 0);

    /* Switch: '<S785>/Switch2' */
    if (rtb_DataTypeConversion_c) {
      PDUCtl_J421IG1RlyCtl = 1U;
    } else {
      PDUCtl_J421IG1RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J421;
    }

    /* End of Switch: '<S785>/Switch2' */
  }

  /* End of Switch: '<S785>/Switch1' */
  /* End of Outputs for SubSystem: '<S604>/Ovrd1' */

  /* Outputs for Atomic SubSystem: '<S604>/Ovrd2' */
  /* Switch: '<S786>/Switch1' incorporates:
   *  Constant: '<S604>/Constant1'
   *  Constant: '<S604>/Constant2'
   */
  if (PDUCtl_J437IG2RlyCtlOvrdFlg_C) {
    PDUCtl_J437IG2RlyCtl = (uint8)PDUCtl_J437IG2RlyCtlOvrdVal_C;
  } else {
    /* DataTypeConversion: '<S604>/Data Type Conversion1' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms'
     */
    rtb_DataTypeConversion_c = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IODID_Bus()
      )->IG2RlyCtlFlg != 0);

    /* Switch: '<S786>/Switch2' */
    if (rtb_DataTypeConversion_c) {
      PDUCtl_J437IG2RlyCtl = 1U;
    } else {
      PDUCtl_J437IG2RlyCtl = AppSwcBcm_ARID_DEF.PDUCtl_J437;
    }

    /* End of Switch: '<S786>/Switch2' */
  }

  /* End of Switch: '<S786>/Switch1' */
  /* End of Outputs for SubSystem: '<S604>/Ovrd2' */

  /* Outputs for Atomic SubSystem: '<S604>/RelayDig' */
  AppSwcBcm_RelayDig();

  /* End of Outputs for SubSystem: '<S604>/RelayDig' */

  /* Outputs for Atomic SubSystem: '<S604>/StartReq' */
  AppSwcBcm_StartReq();

  /* End of Outputs for SubSystem: '<S604>/StartReq' */

  /* Outputs for Atomic SubSystem: '<S604>/Subsystem' */
  AppSwcBcm_Subsystem();

  /* End of Outputs for SubSystem: '<S604>/Subsystem' */

  /* Update for UnitDelay: '<S604>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_i = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S604>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_l = PDUCtl_SysPwrMode;

  /* Update for UnitDelay: '<S604>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_g = PDUCtl_SysPowerSts;

  /* Update for UnitDelay: '<S604>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE_n = PDUCtl_SysPowerSts;
}

/* System initialize for atomic system: '<S816>/NMCtl' */
static void AppSwcBcm_NMCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ng;

  /* InitializeConditions for Delay: '<S820>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = true;

  /* InitializeConditions for Delay: '<S821>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_f = true;

  /* InitializeConditions for Delay: '<S822>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = true;

  /* InitializeConditions for Delay: '<S823>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = true;

  /* InitializeConditions for Delay: '<S824>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_bj = true;

  /* SystemInitialize for Chart: '<S817>/LIB_NegPluse2' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_ng);
}

/* Outputs for atomic system: '<S816>/NMCtl' */
static void AppSwcBcm_NMCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_ng;
  boolean rtb_LogicalOperator9_c;
  boolean rtb_RelationalOperator15_f;
  boolean rtb_RelationalOperator16_d;
  boolean rtb_RelationalOperator17_f;
  boolean rtb_RelationalOperator18_l;
  boolean rtb_RelationalOperator27;
  boolean rtb_RelationalOperator28;

  /* RelationalOperator: '<S817>/Relational Operator15' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator15_f = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BrakeLightSw;

  /* RelationalOperator: '<S817>/Relational Operator16' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator16_d = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->PosLampSta;

  /* RelationalOperator: '<S817>/Relational Operator17' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator17_f = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->LowBeamSta;

  /* RelationalOperator: '<S817>/Relational Operator18' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  rtb_RelationalOperator18_l = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->HiBeamSta;

  /* RelationalOperator: '<S817>/Relational Operator27' incorporates:
   *  Constant: '<S817>/Constant28'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S817>/Relational Operator26'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->RKEReq != 0);

  /* Delay: '<S820>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_c) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_c =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;
  }

  /* Delay: '<S821>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_f) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_my =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;
  }

  /* Delay: '<S822>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_m) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_j =
      AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;
  }

  /* Delay: '<S823>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_b) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_g0 =
      AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;
  }

  /* Delay: '<S824>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad_bj) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_ba =
      AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;
  }

  /* RelationalOperator: '<S817>/Relational Operator28' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  Logic: '<S826>/Logical Operator'
   *  Logic: '<S826>/Logical Operator1'
   *  UnitDelay: '<S826>/Unit Delay'
   */
  rtb_RelationalOperator28 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus()
    )->BrakeLightSw && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ap));

  /* Logic: '<S817>/Logical Operator10' incorporates:
   *  Delay: '<S820>/Delay'
   *  Delay: '<S821>/Delay'
   *  Delay: '<S822>/Delay'
   *  Delay: '<S823>/Delay'
   *  Delay: '<S824>/Delay'
   *  Logic: '<S820>/Logical Operator1'
   *  Logic: '<S820>/Logical Operator2'
   *  Logic: '<S820>/Logical Operator3'
   *  Logic: '<S820>/Logical Operator4'
   *  Logic: '<S820>/Logical Operator5'
   *  Logic: '<S821>/Logical Operator1'
   *  Logic: '<S821>/Logical Operator2'
   *  Logic: '<S821>/Logical Operator3'
   *  Logic: '<S821>/Logical Operator4'
   *  Logic: '<S821>/Logical Operator5'
   *  Logic: '<S822>/Logical Operator1'
   *  Logic: '<S822>/Logical Operator2'
   *  Logic: '<S822>/Logical Operator3'
   *  Logic: '<S822>/Logical Operator4'
   *  Logic: '<S822>/Logical Operator5'
   *  Logic: '<S823>/Logical Operator1'
   *  Logic: '<S823>/Logical Operator2'
   *  Logic: '<S823>/Logical Operator3'
   *  Logic: '<S823>/Logical Operator4'
   *  Logic: '<S823>/Logical Operator5'
   *  Logic: '<S824>/Logical Operator1'
   *  Logic: '<S824>/Logical Operator2'
   *  Logic: '<S824>/Logical Operator3'
   *  Logic: '<S824>/Logical Operator4'
   *  Logic: '<S824>/Logical Operator5'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator10 = (rtb_RelationalOperator27 ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_c &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_c))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_my &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_my))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_j &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_j))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_g0 &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_g0))) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_ba &&
      (!AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw)) ||
     (AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_ba))) || rtb_RelationalOperator28);

  /* RelationalOperator: '<S817>/Relational Operator27' incorporates:
   *  Constant: '<S817>/Constant29'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator27 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->DrvPEAuthentAcsd == 1);

  /* Logic: '<S817>/Logical Operator6' */
  AppSwcBcm_ARID_DEF.LogicalOperator6 = (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
    rtb_RelationalOperator27);

  /* RelationalOperator: '<S817>/Relational Operator28' incorporates:
   *  Constant: '<S817>/Constant30'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_10ms'
   */
  rtb_RelationalOperator28 = ((Rte_IrvIRead_Runbl_AppSwcBcm_50ms_PEPSCtl_Bus()
    )->FRPEAuthentAcsd == 1);

  /* Logic: '<S817>/Logical Operator7' */
  AppSwcBcm_ARID_DEF.LogicalOperator7 = (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
    rtb_RelationalOperator28);

  /* Logic: '<S817>/Logical Operator9' incorporates:
   *  Logic: '<S827>/Logical Operator'
   *  Logic: '<S827>/Logical Operator1'
   *  Logic: '<S828>/Logical Operator'
   *  Logic: '<S828>/Logical Operator1'
   *  UnitDelay: '<S827>/Unit Delay'
   *  UnitDelay: '<S828>/Unit Delay'
   */
  rtb_LogicalOperator9_c = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (AppSwcBcm_ARID_DEF.LogicalOperator6 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ei)) ||
    (AppSwcBcm_ARID_DEF.LogicalOperator7 &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d1)));

  /* Chart: '<S817>/LIB_NegPluse2' incorporates:
   *  Constant: '<S817>/Constant'
   *  Constant: '<S817>/Constant19'
   *  Constant: '<S817>/Constant22'
   *  Logic: '<S817>/Logical Operator'
   *  Logic: '<S817>/Logical Operator1'
   *  Logic: '<S817>/Logical Operator3'
   *  RelationalOperator: '<S817>/Relational Operator'
   *  RelationalOperator: '<S817>/Relational Operator19'
   *  RelationalOperator: '<S817>/Relational Operator20'
   *  RelationalOperator: '<S817>/Relational Operator21'
   */
  AppSwcBcm_LIB_PosPluse2((AppSwcBcm_ARID_DEF.UnitDelay1.SysPwrMode == 0) &&
    rtb_RelationalOperator15_f && rtb_RelationalOperator16_d &&
    rtb_RelationalOperator17_f && rtb_RelationalOperator18_l &&
    (AppSwcBcm_ARID_DEF.UnitDelay3_k.BodyWarnSts != 2) &&
    ((!AppSwcBcm_ARID_DEF.BusCreator4.AutoLckSta) ||
     AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw),
    WakeUpCtl_CANSleepDelayTim_C, rtb_LogicalOperator9_c, &rtb_LIB_blOut_ng,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse2);

  /* Logic: '<S817>/Logical Operator2' incorporates:
   *  Logic: '<S817>/Logical Operator11'
   *  Logic: '<S817>/Logical Operator12'
   */
  AppSwcBcm_ARID_DEF.LogicalOperator2 = (AppSwcBcm_ARID_DEF.RelationalOperator14
    || AppSwcBcm_ARID_DEF.RelationalOperator1 ||
    AppSwcBcm_ARID_DEF.RelationalOperator5 ||
    AppSwcBcm_ARID_DEF.RelationalOperator6 ||
    AppSwcBcm_ARID_DEF.RelationalOperator7 ||
    AppSwcBcm_ARID_DEF.RelationalOperator8 ||
    AppSwcBcm_ARID_DEF.RelationalOperator4 ||
    (AppSwcBcm_ARID_DEF.RelationalOperator9 && rtb_RelationalOperator27) ||
    (AppSwcBcm_ARID_DEF.RelationalOperator10 && rtb_RelationalOperator28) ||
    AppSwcBcm_ARID_DEF.RelationalOperator12);

  /* Switch: '<S829>/Switch' */
  if (rtb_LIB_blOut_ng) {
    /* Switch: '<S829>/Switch' incorporates:
     *  Constant: '<S829>/Constant'
     */
    WakeUpCtl_NMReq = false;
  } else {
    /* Switch: '<S829>/Switch' incorporates:
     *  Logic: '<S817>/Logical Operator8'
     *  Logic: '<S825>/Logical Operator'
     *  Logic: '<S825>/Logical Operator1'
     *  Logic: '<S829>/Logical Operator'
     *  UnitDelay: '<S825>/Unit Delay'
     *  UnitDelay: '<S829>/Unit Delay'
     */
    WakeUpCtl_NMReq = ((AppSwcBcm_ARID_DEF.LogicalOperator2 &&
                        (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n5)) ||
                       rtb_LogicalOperator9_c || WakeUpCtl_NMReq);
  }

  /* End of Switch: '<S829>/Switch' */
}

/* Update for atomic system: '<S816>/NMCtl' */
static void AppSwcBcm_NMCtl_Update(void)
{
  /* Update for Delay: '<S820>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_c = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_c =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFLSw;

  /* Update for Delay: '<S821>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_f = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_my =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarFRSw;

  /* Update for Delay: '<S822>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_m = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_j =
    AppSwcBcm_ARID_DEF.BusCreator4.DriverDoorLckSw;

  /* Update for Delay: '<S823>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_b = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_g0 =
    AppSwcBcm_ARID_DEF.BusCreator4.DoorAjarRRSw;

  /* Update for Delay: '<S824>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad_bj = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_ba =
    AppSwcBcm_ARID_DEF.BusCreator4.TrunkAjarSw;

  /* Update for UnitDelay: '<S826>/Unit Delay' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ap =
    (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())->BrakeLightSw;

  /* Update for UnitDelay: '<S827>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_ei = AppSwcBcm_ARID_DEF.LogicalOperator6;

  /* Update for UnitDelay: '<S828>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_d1 = AppSwcBcm_ARID_DEF.LogicalOperator7;

  /* Update for UnitDelay: '<S825>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_n5 = AppSwcBcm_ARID_DEF.LogicalOperator2;
}

/* System initialize for atomic system: '<S816>/SleepCtl' */
static void AppSwcBcm_SleepCtl_Init(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;

  /* InitializeConditions for Delay: '<S833>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad = true;

  /* SystemInitialize for Chart: '<S818>/LIB_NegPluse1' */
  AppSwcBcm_LIB_PosPluse2_Init(&rtb_LIB_blOut_l);
}

/* Output and update for atomic system: '<S816>/SleepCtl' */
static void AppSwcBcm_SleepCtl(void)
{
  /* local block i/o variables */
  boolean rtb_LIB_blOut_l;
  boolean rtb_LogicalOperator;
  boolean rtb_LogicalOperator13;
  boolean rtb_RelationalOperator29;
  boolean rtb_RelationalOperator30;

  /* Logic: '<S836>/Logical Operator' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   *  RelationalOperator: '<S818>/Relational Operator24'
   */
  rtb_LogicalOperator = !(Rte_IrvIRead_Runbl_AppSwcBcm_50ms_LampCtl_Bus())
    ->BoxLampSta;

  /* RelationalOperator: '<S818>/Relational Operator29' incorporates:
   *  Constant: '<S818>/Constant31'
   */
  rtb_RelationalOperator29 = (AppSwcBcm_ARID_DEF.CCaller35 == 1);

  /* RelationalOperator: '<S818>/Relational Operator30' incorporates:
   *  Constant: '<S818>/Constant32'
   */
  rtb_RelationalOperator30 = (AppSwcBcm_ARID_DEF.CCaller36 == 1);

  /* Delay: '<S833>/Delay' */
  if (AppSwcBcm_ARID_DEF.icLoad) {
    AppSwcBcm_ARID_DEF.Delay_DSTATE_l = AppSwcBcm_ARID_DEF.HornCtl_Bus.HornSwCtl;
  }

  /* Logic: '<S818>/Logical Operator13' incorporates:
   *  Delay: '<S833>/Delay'
   *  Logic: '<S833>/Logical Operator1'
   *  Logic: '<S833>/Logical Operator2'
   *  Logic: '<S833>/Logical Operator3'
   *  Logic: '<S833>/Logical Operator4'
   *  Logic: '<S833>/Logical Operator5'
   *  Logic: '<S835>/Logical Operator'
   *  Logic: '<S835>/Logical Operator1'
   *  Logic: '<S836>/Logical Operator'
   *  Logic: '<S836>/Logical Operator1'
   *  Logic: '<S837>/Logical Operator'
   *  Logic: '<S837>/Logical Operator1'
   *  Logic: '<S838>/Logical Operator'
   *  Logic: '<S838>/Logical Operator1'
   *  UnitDelay: '<S835>/Unit Delay'
   *  UnitDelay: '<S836>/Unit Delay'
   *  UnitDelay: '<S837>/Unit Delay'
   *  UnitDelay: '<S838>/Unit Delay'
   */
  rtb_LogicalOperator13 = (AppSwcBcm_ARID_DEF.LogicalOperator10 ||
    (rtb_RelationalOperator29 && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hv)) ||
    (rtb_RelationalOperator30 && (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b4)) ||
    ((AppSwcBcm_ARID_DEF.Delay_DSTATE_l &&
      (!AppSwcBcm_ARID_DEF.HornCtl_Bus.HornSwCtl)) ||
     (AppSwcBcm_ARID_DEF.HornCtl_Bus.HornSwCtl &&
      (!AppSwcBcm_ARID_DEF.Delay_DSTATE_l))) ||
    (AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_lz)) ||
    (AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw &&
     (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o)));

  /* Chart: '<S818>/LIB_NegPluse1' incorporates:
   *  Constant: '<S818>/Constant27'
   *  Logic: '<S818>/Logical Operator4'
   *  RelationalOperator: '<S818>/Relational Operator23'
   *  RelationalOperator: '<S818>/Relational Operator25'
   */
  AppSwcBcm_LIB_PosPluse2((!WakeUpCtl_NMReq) && rtb_LogicalOperator &&
    (!AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr), WakeUpCtl_LocalSleepDelayTim_C,
    rtb_LogicalOperator13, &rtb_LIB_blOut_l,
    &AppSwcBcm_ARID_DEF.ARID_DEF_LIB_NegPluse1);

  /* Logic: '<S818>/Logical Operator3' */
  rtb_LogicalOperator = (AppSwcBcm_ARID_DEF.RelationalOperator14 ||
    AppSwcBcm_ARID_DEF.RelationalOperator1 ||
    AppSwcBcm_ARID_DEF.RelationalOperator5 ||
    AppSwcBcm_ARID_DEF.RelationalOperator6 ||
    AppSwcBcm_ARID_DEF.RelationalOperator7 ||
    AppSwcBcm_ARID_DEF.RelationalOperator8 ||
    AppSwcBcm_ARID_DEF.RelationalOperator4 ||
    AppSwcBcm_ARID_DEF.RelationalOperator9 ||
    AppSwcBcm_ARID_DEF.RelationalOperator10 ||
    AppSwcBcm_ARID_DEF.RelationalOperator22 ||
    AppSwcBcm_ARID_DEF.RelationalOperator12);

  /* Switch: '<S839>/Switch' */
  if (rtb_LIB_blOut_l) {
    /* Switch: '<S839>/Switch' incorporates:
     *  Constant: '<S839>/Constant'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dy = false;
  } else {
    /* Switch: '<S839>/Switch' incorporates:
     *  Logic: '<S818>/Logical Operator14'
     *  Logic: '<S834>/Logical Operator'
     *  Logic: '<S834>/Logical Operator1'
     *  Logic: '<S839>/Logical Operator'
     *  UnitDelay: '<S834>/Unit Delay'
     *  UnitDelay: '<S839>/Unit Delay'
     */
    AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dy = ((rtb_LogicalOperator &&
      (!AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hm)) || rtb_LogicalOperator13 ||
      AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dy);
  }

  /* End of Switch: '<S839>/Switch' */

  /* Logic: '<S818>/Logical Operator5' */
  WakeUpCtl_SleepAllwd = !AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_dy;

  /* Update for UnitDelay: '<S837>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hv = rtb_RelationalOperator29;

  /* Update for UnitDelay: '<S838>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_b4 = rtb_RelationalOperator30;

  /* Update for Delay: '<S833>/Delay' */
  AppSwcBcm_ARID_DEF.icLoad = false;
  AppSwcBcm_ARID_DEF.Delay_DSTATE_l = AppSwcBcm_ARID_DEF.HornCtl_Bus.HornSwCtl;

  /* Update for UnitDelay: '<S835>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_lz =
    AppSwcBcm_ARID_DEF.BusCreator4.DrvPESw;

  /* Update for UnitDelay: '<S836>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_o = AppSwcBcm_ARID_DEF.BusCreator4.PsgPESw;

  /* Update for UnitDelay: '<S834>/Unit Delay' */
  AppSwcBcm_ARID_DEF.UnitDelay_DSTATE_hm = rtb_LogicalOperator;
}

/* System initialize for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Init(void)
{
  /* SystemInitialize for Atomic SubSystem: '<S816>/NMCtl' */
  AppSwcBcm_NMCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S816>/NMCtl' */

  /* SystemInitialize for Atomic SubSystem: '<S816>/SleepCtl' */
  AppSwcBcm_SleepCtl_Init();

  /* End of SystemInitialize for SubSystem: '<S816>/SleepCtl' */
}

/* Outputs for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl(void)
{
  /* SignalConversion: '<S605>/Signal Conversion' incorporates:
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
   */
  BSW_WakeupReas = (Rte_IrvIRead_Runbl_AppSwcBcm_50ms_Vcu2BcmTms_outputs())
    ->VBSW_WakeupReasn_enum;

  /* RelationalOperator: '<S816>/Relational Operator14' incorporates:
   *  Constant: '<S816>/Constant14'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator14 = (BSW_WakeupReas == 49);

  /* RelationalOperator: '<S816>/Relational Operator1' incorporates:
   *  Constant: '<S816>/Constant1'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator1 = (BSW_WakeupReas == 54);

  /* RelationalOperator: '<S816>/Relational Operator5' incorporates:
   *  Constant: '<S816>/Constant5'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator5 = (BSW_WakeupReas == 58);

  /* RelationalOperator: '<S816>/Relational Operator6' incorporates:
   *  Constant: '<S816>/Constant6'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator6 = (BSW_WakeupReas == 59);

  /* RelationalOperator: '<S816>/Relational Operator7' incorporates:
   *  Constant: '<S816>/Constant7'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator7 = (BSW_WakeupReas == 61);

  /* RelationalOperator: '<S816>/Relational Operator8' incorporates:
   *  Constant: '<S816>/Constant8'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator8 = (BSW_WakeupReas == 62);

  /* RelationalOperator: '<S816>/Relational Operator4' incorporates:
   *  Constant: '<S816>/Constant4'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator4 = (BSW_WakeupReas == 57);

  /* RelationalOperator: '<S816>/Relational Operator9' incorporates:
   *  Constant: '<S816>/Constant9'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator9 = (BSW_WakeupReas == 63);

  /* RelationalOperator: '<S816>/Relational Operator10' incorporates:
   *  Constant: '<S816>/Constant10'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator10 = (BSW_WakeupReas == 64);

  /* RelationalOperator: '<S816>/Relational Operator13' incorporates:
   *  Constant: '<S816>/Constant13'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 17);

  /* Outputs for Atomic SubSystem: '<S816>/NMCtl' */
  AppSwcBcm_NMCtl();

  /* End of Outputs for SubSystem: '<S816>/NMCtl' */

  /* RelationalOperator: '<S816>/Relational Operator12' incorporates:
   *  Constant: '<S816>/Constant12'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator12 = (BSW_WakeupReas == 66);

  /* RelationalOperator: '<S816>/Relational Operator22' incorporates:
   *  Constant: '<S816>/Constant23'
   */
  AppSwcBcm_ARID_DEF.RelationalOperator22 = (BSW_WakeupReas == 50);

  /* Outputs for Atomic SubSystem: '<S816>/SleepCtl' */
  AppSwcBcm_SleepCtl();

  /* End of Outputs for SubSystem: '<S816>/SleepCtl' */
}

/* Update for atomic system: '<S4>/WakeUpCtl' */
static void AppSwcBcm_WakeUpCtl_Update(void)
{
  /* Update for Atomic SubSystem: '<S816>/NMCtl' */
  AppSwcBcm_NMCtl_Update();

  /* End of Update for SubSystem: '<S816>/NMCtl' */
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
  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.BatSaveCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_BatSaveCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  AppSwcBcm_ARID_DEF.ESCLCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_ESCLCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.RVMCtl_Bus = *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_RVMCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  AppSwcBcm_ARID_DEF.WinCtl_Bus = *Rte_IrvIRead_Runbl_AppSwcBcm_20ms_WinCtl_Bus();

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

  /* CCaller: '<S3>/C Caller31' */
  BSW_J319HornSw = GetHw_AlrmHornSw();

  /* SignalConversion generated from: '<S3>/IPM_HU_B_BAC' incorporates:
   *  Inport: '<Root>/IPM_HU_B_BAC'
   */
  AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC_IPM_HU_B_BAC();

  /* UnitDelay: '<S3>/Unit Delay2' */
  AppSwcBcm_ARID_DEF.UnitDelay2 = AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE;

  /* SignalConversion generated from: '<S3>/Vcu2BcmTms_outputs' incorporates:
   *  Inport: '<Root>/Vcu2BcmTms_outputs'
   */
  AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d =
    *Rte_IRead_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs();

  /* Outputs for Atomic SubSystem: '<S3>/HornCtl' */
  AppSwcBcm_HornCtl();

  /* End of Outputs for SubSystem: '<S3>/HornCtl' */

  /* UnitDelay: '<S3>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1_h = AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d;

  /* UnitDelay: '<S3>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3 = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE;

  /* Outputs for Atomic SubSystem: '<S3>/EEWriteCtl' */
  AppSwcBcm_EEWriteCtl();

  /* End of Outputs for SubSystem: '<S3>/EEWriteCtl' */

  /* Outputs for Atomic SubSystem: '<S3>/BCMTx' */
  AppSwcBcm_BCMTx();

  /* End of Outputs for SubSystem: '<S3>/BCMTx' */

  /* BusCreator: '<S3>/Bus Creator9' incorporates:
   *  UnitDelay: '<S3>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.HornDrv = HornCtl_J430HornDrv;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.LockHoornOnStFb =
    HornCtl_LockHoornOnStFb;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.LockHoornOnSt = HornCtl_LockHoornOnSt;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.HornSwCtl = HornCtl_HornSwCtl;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.PartArmedSta = HornCtl_PartArmedSta;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.ArmedSta = HornCtl_ArmedSta;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.AlarmSta = HornCtl_AlarmSta;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.SeekSta = HornCtl_SeekSta;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.AntiLckSta = HornCtl_AntiLckSta;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE_d.TrunkWarnSta = HornCtl_TrunkWarnSta;

  /* CCaller: '<S3>/C Caller15' */
  AppSwcBcm_ARID_DEF.CCaller15 = GetHw_CrashPWMSta();

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

  /* Outputs for Atomic SubSystem: '<S3>/LampCtl' */
  AppSwcBcm_LampCtl();

  /* End of Outputs for SubSystem: '<S3>/LampCtl' */

  /* BusCreator: '<S3>/Bus Creator' incorporates:
   *  UnitDelay: '<S3>/Unit Delay2'
   */
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.PosLampSw = LampCtl_PosLampSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.LowBeamSw = LampCtl_LowBeamSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.HiBeamSw = LampCtl_HiBeamSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.PassLightSw = LampCtl_PassLightSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrLSw = LampCtl_TurnIndcrLSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrLaneLSw =
    LampCtl_TurnIndcrLaneLSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrRSw = LampCtl_TurnIndcrRSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrLaneRSw =
    LampCtl_TurnIndcrLaneRSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FogLampRSw = LampCtl_FogLampRSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.HazardLightSw = LampCtl_HazardLightSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.BrakeLightSw = LampCtl_BrakeLightSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.LightIntstVal = LampCtl_LightIntstVal;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.AutoLampSw = LampCtl_AutoLampSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.PosLampSta = LampCtl_PosLampSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.DayRunLightSta = LampCtl_DayRunLightSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.BrakeLightSta = LampCtl_BrakeLightSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.BSDRightCtl = LampCtl_J420BSDRightCtl;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.BSDLeftCtl = LampCtl_J422BSDLeftCtl;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.LowBeamSta = LampCtl_LowBeamSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FogLampRSta = LampCtl_FogLampRSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.ReverseLampSta = LampCtl_ReverseLampSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.LightIntstSta = LampCtl_LightIntstSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.HiBeamSta = LampCtl_HiBeamSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.DomeLampPwmDuty = LampCtl_DomeLampPwmDuty;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrRSta = LampCtl_TurnIndcrRSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrLSta = LampCtl_TurnIndcrLSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.VehSeekSta = LampCtl_VehSeekSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.ThermalrunawaySta =
    LampCtl_ThermalrunawaySta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.EmerSta = LampCtl_EmerSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.ArmedSta = LampCtl_ArmedSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.CrashSta = LampCtl_CrashSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.DisarmedSta = LampCtl_DisarmedSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.PartArmedSta = LampCtl_PartArmedSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.AlrmSta = LampCtl_AlrmSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.EmerHazardLightSta =
    LampCtl_EmerHazardLightSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.HazardLightSta = LampCtl_HazardLightSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrMod = LampCtl_TurnIndcrMod;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.PassLightSta = LampCtl_PassLightSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.AutoLampSta = LampCtl_AutoLampSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.BoxLampSta = LampCtl_J449BoxLamp;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.WelcomeLampSta = LampCtl_WelcomeLampSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FlwrMeHomeSta = LampCtl_FlwrMeHomeSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FlwrMeHomeCtlFb = LampCtl_FlwrMeHomeCtlFb;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FlwrMeHomeTim = LampCtl_FlwrMeHomeTim;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrLOpen = LampCtl_TurnIndcrLOpen;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrLShort = LampCtl_TurnIndcrLShort;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrROpen = LampCtl_TurnIndcrROpen;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TurnIndcrRShort = LampCtl_TurnIndcrRShort;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.RKEReq = LampCtl_RKEReq;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.KnobBeamFaultSta =
    LampCtl_KnobBeamFaultSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.RodBeamFaultSta = LampCtl_RodBeamFaultSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.BackLadjvalFb = LampCtl_BackLadjvalFb;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.J408BackLampPWM = LampCtl_J408BackLampPWM;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FogLampFSw = LampCtl_FogLampFSw;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.FogLampFSta = LampCtl_FogLampFSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.LampDelay = LampCtl_LampDelay;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.AntiLckSta = LampCtl_AntiLckSta;
  AppSwcBcm_ARID_DEF.UnitDelay2_DSTATE.TrunkWarnSta = LampCtl_TrunkWarnSta;

  /* CCaller: '<S3>/C Caller8' */
  BSW_J334WiperParkPos = GetHw_WiprStopPstnDtct();

  /* Outputs for Atomic SubSystem: '<S3>/WiperCtl' */
  AppSwcBcm_WiperCtl();

  /* End of Outputs for SubSystem: '<S3>/WiperCtl' */

  /* BusCreator: '<S3>/Bus Creator6' incorporates:
   *  UnitDelay: '<S3>/Unit Delay3'
   */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperMistSw = WiperCtl_WiperMistSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WashSw = WiperCtl_WashSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperParkPosSw = WiperCtl_WiperParkPosSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperOffSw = WiperCtl_WiperOffSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperInrSw = WiperCtl_WiperInrSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperLowSpdSw = WiperCtl_WiperLowSpdSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperHiSpdSw = WiperCtl_WiperHiSpdSw;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperMistSta = WiperCtl_WiperMistSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperInrSta = WiperCtl_WiperInrSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.InrTim = WiperCtl_InrTim;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiprIntlTimeSetFb =
    WiperCtl_WiprIntlTimeSetFb;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.InrTimChg = WiperCtl_InrTimChg;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperOffSta = WiperCtl_WiperOffSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperMaintSta = WiperCtl_WiperMaintSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperHiSpdSta = WiperCtl_WiperHiSpdSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperLowSpdSta = WiperCtl_WiperLowSpdSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.LockedRotorProtSta =
    WiperCtl_LockedRotorProtSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WashSta = WiperCtl_WashWiperSta;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WashMotorDrv = WiperCtl_WashMotorDrv;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.LowSpdDrv = WiperCtl_LowSpdDrv;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.HiSpdDrv = WiperCtl_HiSpdDrv;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE.WiperSta = WiperCtl_WiperSta;

  /* Update for Atomic SubSystem: '<S3>/LampCtl' */
  AppSwcBcm_LampCtl_Update();

  /* End of Update for SubSystem: '<S3>/LampCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_LampCtl_Bus(&AppSwcBcm_ARID_DEF.UnitDelay2);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Wiper_Bus(&AppSwcBcm_ARID_DEF.UnitDelay3);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' incorporates:
   *  SignalConversion generated from: '<S3>/Vcu2BcmTms_outputs'
   */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_Vcu2BcmTms_outputs
    (&AppSwcBcm_ARID_DEF.Vcu2BcmTms_outputs_d);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_CCP_PanelStatus_BOD
    (&AppSwcBcm_ARID_DEF.IPM_CCP_PanelStatus_BOD_d);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_HU_B_BAC
    (&AppSwcBcm_ARID_DEF.IPM_HU_B_BAC_c);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_EEReadCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator12);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_HornCtl_Bus
    (&AppSwcBcm_ARID_DEF.UnitDelay1_h);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_20ms_IPM_ESC_7_FuncStatus_CHA
    (&AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA_e);

  /* Outport: '<Root>/Bcm2OpmBAC_outputs' */
  Rte_IWrite_Runbl_AppSwcBcm_20ms_Bcm2OpmBAC_outputs_Bcm2OpmBAC_outputs
    (&AppSwcBcm_ARID_DEF.Bcm2OpmBAC_outputs_m);

  /* Outport: '<Root>/Bcm2OpmOBD_outputs' incorporates:
   *  BusCreator: '<S217>/Bus Creator3'
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
  ESCLCtl rtb_BusCreator3;
  WakeUpCtl rtb_BusCreator15;
  sint32 i;

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.IPM_ESC_7_FuncStatus_CHA =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_IPM_ESC_7_FuncStatus_CHA();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.EEReadCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_EEReadCtl_Bus();

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms' */
  AppSwcBcm_ARID_DEF.HornCtl_Bus =
    *Rte_IrvIRead_Runbl_AppSwcBcm_50ms_HornCtl_Bus();

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_50ms'
   */
  /* UnitDelay: '<S4>/Unit Delay3' */
  AppSwcBcm_ARID_DEF.UnitDelay3_k = AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_a;

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

  /* UnitDelay: '<S4>/Unit Delay1' */
  AppSwcBcm_ARID_DEF.UnitDelay1 = AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE;

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
    AppSwcBcm_ARID_DEF.LogicalOperator_gw;
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

  /* Outputs for Atomic SubSystem: '<S4>/DTCCtl' */
  AppSwcBcm_DTCCtl();

  /* End of Outputs for SubSystem: '<S4>/DTCCtl' */

  /* Outputs for Atomic SubSystem: '<S4>/BatSaveCtl' */
  AppSwcBcm_BatSaveCtl();

  /* End of Outputs for SubSystem: '<S4>/BatSaveCtl' */

  /* CCaller: '<S4>/C Caller9' */
  AppSwcBcm_ARID_DEF.CCaller35 = GetHw_KL15A();

  /* CCaller: '<S4>/C Caller10' */
  AppSwcBcm_ARID_DEF.CCaller36 = GetHw_KL15B();

  /* Outputs for Atomic SubSystem: '<S4>/PDUCtl' */
  AppSwcBcm_PDUCtl();

  /* End of Outputs for SubSystem: '<S4>/PDUCtl' */

  /* BusCreator: '<S4>/Bus Creator1' incorporates:
   *  UnitDelay: '<S4>/Unit Delay1'
   */
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.SysPwrMode = PDUCtl_SysPwrMode;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.J421IG1RlyCtl = PDUCtl_J421IG1RlyCtl;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.J437IG2RlyCtl = PDUCtl_J437IG2RlyCtl;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.IG1RelayFault = PDUCtl_IG1RelayFault;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.IG2RelayFault = PDUCtl_IG2RelayFault;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.SysPwrModeV = PDUCtl_SysPwrModeV;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.SysPowerSts = PDUCtl_SysPowerSts;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.PwrOn = PDUCtl_PwrOn;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.SysPwrModeAct = PDUCtl_SysPwrModeAct;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.StartReq = PDUCtl_StartReq;
  AppSwcBcm_ARID_DEF.UnitDelay1_DSTATE.IGRlyIIgCls = PDUCtl_IGRlyIlgCls;

  /* CCaller: '<S4>/C Caller36' */
  AppSwcBcm_ARID_DEF.CCaller36 = GetHw_KL15A();

  /* CCaller: '<S4>/C Caller35' */
  AppSwcBcm_ARID_DEF.CCaller35 = GetHw_KL15B();

  /* BusCreator: '<S4>/Bus Creator8' */
  AppSwcBcm_ARID_DEF.BusCreator8.J64SavePwr = BatSaveCtl_J64SavePwr;

  /* Outputs for Atomic SubSystem: '<S4>/WakeUpCtl' */
  AppSwcBcm_WakeUpCtl();

  /* End of Outputs for SubSystem: '<S4>/WakeUpCtl' */

  /* BusCreator: '<S4>/Bus Creator15' */
  rtb_BusCreator15.NMReq = WakeUpCtl_NMReq;
  rtb_BusCreator15.SleepAllwd = WakeUpCtl_SleepAllwd;

  /* BusCreator: '<S4>/Bus Creator2' incorporates:
   *  UnitDelay: '<S4>/Unit Delay3'
   */
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_a.BodyWarnSts = AlmSysCtl_BodyWarnSts;
  AppSwcBcm_ARID_DEF.UnitDelay3_DSTATE_a.AlrmWarnTimOut =
    AlmSysCtl_AlrmWarnTimOut;

  /* Outputs for Atomic SubSystem: '<S4>/ESCLCtl' */
  AppSwcBcm_ESCLCtl();

  /* End of Outputs for SubSystem: '<S4>/ESCLCtl' */

  /* BusCreator: '<S4>/Bus Creator3' */
  rtb_BusCreator3.UnOrLockCrtl = ESCLCtl_UnOrLockCrtl;
  rtb_BusCreator3.J436PwrSup = ESCLCtl_J436PwrSup;

  /* CCaller: '<S4>/C Caller19' */
  BSW_J349TrunkLck = GetHw_TrunkLckSts();

  /* CCaller: '<S4>/C Caller22' */
  BSW_J38HoodAjar = GetHw_HoodAjarSts();

  /* Update for Atomic SubSystem: '<S4>/WakeUpCtl' */
  AppSwcBcm_WakeUpCtl_Update();

  /* End of Update for SubSystem: '<S4>/WakeUpCtl' */
  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_AlmSysCtl_Bus
    (&AppSwcBcm_ARID_DEF.UnitDelay3_k);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_PDUCtl_Bus(&AppSwcBcm_ARID_DEF.UnitDelay1);

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_50ms_DoorLckCtl_Bus
    (&AppSwcBcm_ARID_DEF.BusCreator4);

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
  uint8 rtb_Switch_at;
  boolean rtb_RelationalOperator;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' incorporates:
   *  SubSystem: '<Root>/AppSwcBcm_100ms'
   */
  /* CCaller: '<S1>/C Caller14' */
  BSW_CN744DrvSeatResis = GetHw_DrvSeatTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SeatCtl' */
  /* DataTypeConversion: '<S127>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S127>/Data Type Conversion1'
   *  Lookup_n-D: '<S127>/1-D Lookup Table3'
   */
  SeatCtl_DrvSeatTemp = (sint8)(float32)floor(look1_iflf_binlx
    (BSW_CN744DrvSeatResis, (const float32 *)&SeatCtl_DrvSeatTempLookUp_X[0], (
    const float32 *)&SeatCtl_DrvSeatTempLookUp_Y[0], 11U));

  /* RelationalOperator: '<S130>/Relational Operator' incorporates:
   *  Constant: '<S127>/Constant9'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   *  RelationalOperator: '<S127>/Relational Operator1'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S127>/Switch' */
  if (rtb_RelationalOperator) {
    /* Switch: '<S127>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch_at = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
      ->VIPM_HUMaiDrvrSeatHeat_enum;
  } else {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S127>/Constant10'
     */
    rtb_Switch_at = 1U;
  }

  /* End of Switch: '<S127>/Switch' */

  /* MultiPortSwitch: '<S127>/Multiport Switch' */
  switch (rtb_Switch_at) {
   case 1:
    /* MultiPortSwitch: '<S127>/Multiport Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    SeatCtl_MaiDrvSeatStFb = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S127>/Multiport Switch' incorporates:
     *  Constant: '<S127>/Constant2'
     */
    SeatCtl_MaiDrvSeatStFb = 1U;
    break;

   case 3:
    /* MultiPortSwitch: '<S127>/Multiport Switch' incorporates:
     *  Constant: '<S127>/Constant3'
     */
    SeatCtl_MaiDrvSeatStFb = 2U;
    break;

   case 4:
    /* MultiPortSwitch: '<S127>/Multiport Switch' incorporates:
     *  Constant: '<S127>/Constant4'
     */
    SeatCtl_MaiDrvSeatStFb = 3U;
    break;
  }

  /* End of MultiPortSwitch: '<S127>/Multiport Switch' */

  /* MultiPortSwitch: '<S127>/Multiport Switch1' */
  switch (SeatCtl_MaiDrvSeatStFb) {
   case 1:
    /* MultiPortSwitch: '<S127>/Multiport Switch1' incorporates:
     *  Constant: '<S127>/Constant5'
     */
    rtb_Switch_at = SeatCtl_DrvTempLvl1_C;
    break;

   case 2:
    /* MultiPortSwitch: '<S127>/Multiport Switch1' incorporates:
     *  Constant: '<S127>/Constant6'
     */
    rtb_Switch_at = SeatCtl_DrvTempLvl2_C;
    break;

   case 3:
    /* MultiPortSwitch: '<S127>/Multiport Switch1' incorporates:
     *  Constant: '<S127>/Constant7'
     */
    rtb_Switch_at = SeatCtl_DrvTempLvl3_C;
    break;

   default:
    /* MultiPortSwitch: '<S127>/Multiport Switch1' incorporates:
     *  Constant: '<S127>/Constant8'
     */
    rtb_Switch_at = SeatCtl_DrvTempLvl0_C;
    break;
  }

  /* End of MultiPortSwitch: '<S127>/Multiport Switch1' */

  /* Chart: '<S127>/Chart' */
  if (AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c1_SeatCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_dh;
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
  } else if (AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib == AppSwcBcm_IN_Off_dh) {
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    if ((rtb_Switch_at - SeatCtl_DrvSeatTemp >= SeatCtl_HtDiffTemp_C) &&
        (rtb_Switch_at != 0)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_On_b;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    }
  } else {
    /* case IN_On: */
    rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)100.0F;
    if ((SeatCtl_DrvSeatTemp >= rtb_Switch_at) || (rtb_Switch_at == 0)) {
      AppSwcBcm_ARID_DEF.is_c1_SeatCtl_Lib = AppSwcBcm_IN_Off_dh;
      rtb_SeatCtl_CN167DrvSeatHtPWM = (sint32)0.0F;
    }
  }

  /* End of Chart: '<S127>/Chart' */

  /* Outputs for Atomic SubSystem: '<S127>/Ovrd' */
  /* Switch: '<S129>/Switch' incorporates:
   *  Constant: '<S127>/Constant18'
   */
  if (SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C) {
    /* Switch: '<S129>/Switch' incorporates:
     *  Constant: '<S127>/Constant19'
     */
    SeatCtl_CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;
  } else {
    /* Switch: '<S129>/Switch' */
    SeatCtl_CN167DrvSeatHtPWM = (uint8)rtb_SeatCtl_CN167DrvSeatHtPWM;
  }

  /* End of Switch: '<S129>/Switch' */
  /* End of Outputs for SubSystem: '<S127>/Ovrd' */
  /* End of Outputs for SubSystem: '<S1>/SeatCtl' */

  /* BusCreator: '<S1>/Bus Creator11' */
  rtb_BusCreator11.MaiDrvSeatStFb = SeatCtl_MaiDrvSeatStFb;
  rtb_BusCreator11.CN167DrvSeatHtPWM = SeatCtl_CN167DrvSeatHtPWM;
  rtb_BusCreator11.DrvSeatTemp = SeatCtl_DrvSeatTemp;

  /* CCaller: '<S1>/C Caller34' */
  BSW_J134SteerWhlResis = GetHw_SteerWhlTempFrb();

  /* Outputs for Atomic SubSystem: '<S1>/SteerWhlCtl' */
  /* DataTypeConversion: '<S130>/Data Type Conversion' incorporates:
   *  DataTypeConversion: '<S130>/Data Type Conversion1'
   *  Lookup_n-D: '<S130>/1-D Lookup Table1'
   */
  SteerWhlCtl_SteerWhlTemp = (sint8)(float32)floor(look1_iflf_binlca
    (BSW_J134SteerWhlResis, (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_X[0],
     (const float32 *)&SteerWhlCtl_SteerWhlTempLookUp_Y[0], 2U));

  /* RelationalOperator: '<S130>/Relational Operator' incorporates:
   *  Constant: '<S130>/Constant3'
   *  DataTransferBlock generated from: '<Root>/AppSwcBcm_50ms'
   */
  rtb_RelationalOperator = ((Rte_IrvIRead_Runbl_AppSwcBcm_100ms_PDUCtl_Bus())
    ->SysPwrMode == 2);

  /* Switch: '<S130>/Switch' */
  if (rtb_RelationalOperator) {
    /* Switch: '<S130>/Switch' incorporates:
     *  DataTransferBlock generated from: '<Root>/AppSwcBcm_20ms'
     */
    rtb_Switch_at = (Rte_IrvIRead_Runbl_AppSwcBcm_100ms_IPM_HU_B_BAC())
      ->VIPM_HUSteerWhlHeat_enum;
  } else {
    /* Switch: '<S130>/Switch' incorporates:
     *  Constant: '<S130>/Constant4'
     */
    rtb_Switch_at = 1U;
  }

  /* End of Switch: '<S130>/Switch' */

  /* MultiPortSwitch: '<S130>/Multiport Switch' */
  switch (rtb_Switch_at) {
   case 1:
    /* MultiPortSwitch: '<S130>/Multiport Switch' incorporates:
     *  Constant: '<S130>/Constant1'
     */
    SteerWhlCtl_SteerWhlHeatSts = 0U;
    break;

   case 2:
    /* MultiPortSwitch: '<S130>/Multiport Switch' incorporates:
     *  Constant: '<S130>/Constant2'
     */
    SteerWhlCtl_SteerWhlHeatSts = 1U;
    break;
  }

  /* End of MultiPortSwitch: '<S130>/Multiport Switch' */

  /* Chart: '<S130>/HeatCtl' */
  if (AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib == 0U) {
    AppSwcBcm_ARID_DEF.is_active_c3_SteerWhlCtl_Lib = 1U;
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_dh;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  } else if (AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib == AppSwcBcm_IN_Off_dh) {
    if ((SteerWhlCtl_SteerWhlHeatSts != 0) && (SteerWhlCtl_TrgtTemp_C -
         SteerWhlCtl_SteerWhlTemp >= SteerWhlCtl_DiffTemp_C)) {
      AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_On_b;
      AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = true;
    }

    /* case IN_On: */
  } else if ((SteerWhlCtl_SteerWhlHeatSts == 0) || (SteerWhlCtl_SteerWhlTemp >=
              SteerWhlCtl_TrgtTemp_C)) {
    AppSwcBcm_ARID_DEF.is_c3_SteerWhlCtl_Lib = AppSwcBcm_IN_Off_dh;
    AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta = false;
  }

  /* End of Chart: '<S130>/HeatCtl' */

  /* Outputs for Atomic SubSystem: '<S130>/Ovrd' */
  /* Switch: '<S132>/Switch' incorporates:
   *  Constant: '<S130>/Constant18'
   */
  if (SteerWhlCtl_J447SteerWhlHtOvrdFlg_C) {
    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S130>/Constant19'
     */
    SteerWhlCtl_J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHtOvrdVal_C;
  } else {
    /* Switch: '<S132>/Switch' */
    SteerWhlCtl_J447SteerWhlHt = AppSwcBcm_ARID_DEF.SteerWhlCtl_SteerWhlHtSta;
  }

  /* End of Switch: '<S132>/Switch' */
  /* End of Outputs for SubSystem: '<S130>/Ovrd' */
  /* End of Outputs for SubSystem: '<S1>/SteerWhlCtl' */

  /* BusCreator: '<S1>/Bus Creator13' */
  rtb_BusCreator13.SteerWhlHeatSts = SteerWhlCtl_SteerWhlHeatSts;
  rtb_BusCreator13.J447SteerWhlHt = SteerWhlCtl_J447SteerWhlHt;
  rtb_BusCreator13.SteerWhlTemp = SteerWhlCtl_SteerWhlTemp;

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

  /* CCaller: '<S1>/C Caller12' */
  Get_RKEReq();

  /* CCaller: '<S1>/C Caller7' */
  GetHw_HzrdLampSw();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_100ms' */

  /* DataTransferBlock generated from: '<Root>/AppSwcBcm_100ms' */
  Rte_IrvIWrite_Runbl_AppSwcBcm_100ms_IODID_Bus(&rtb_BusCreator16);

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
    /* SystemInitialize for Atomic SubSystem: '<S3>/HornCtl' */
    AppSwcBcm_HornCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/HornCtl' */

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

    /* SystemInitialize for Atomic SubSystem: '<S3>/LampCtl' */
    AppSwcBcm_LampCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/LampCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S3>/WiperCtl' */
    AppSwcBcm_WiperCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S3>/WiperCtl' */
    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_20ms' */

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_AppSwcBcm_50ms' incorporates:
     *  SubSystem: '<Root>/AppSwcBcm_50ms'
     */
    /* SystemInitialize for Atomic SubSystem: '<S4>/AlmSysCtl' */
    AppSwcBcm_AlmSysCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/AlmSysCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/DoorLckCtl' */
    AppSwcBcm_DoorLckCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/DoorLckCtl' */

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

    /* SystemInitialize for Atomic SubSystem: '<S4>/BatSaveCtl' */
    AppSwcBcm_BatSaveCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/BatSaveCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/PDUCtl' */
    AppSwcBcm_PDUCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/PDUCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/WakeUpCtl' */
    AppSwcBcm_WakeUpCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/WakeUpCtl' */

    /* SystemInitialize for Atomic SubSystem: '<S4>/ESCLCtl' */
    AppSwcBcm_ESCLCtl_Init();

    /* End of SystemInitialize for SubSystem: '<S4>/ESCLCtl' */
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
