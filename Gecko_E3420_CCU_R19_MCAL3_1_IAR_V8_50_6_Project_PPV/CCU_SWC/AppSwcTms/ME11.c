#include "ME11.h"
#include "rtwtypes.h"
#include <math.h>
#include "Rte_Type.h"
#include "ME11_types.h"
#include "TMS_CalibrationData.h"
#include "TMS_MonitorData.h"
#include "Dem_Cfg.h"
#include "ME11_ABI.h"
#include "zero_crossing_types.h"

#define ME11_IN_Clear                  ((uint8)1U)
#define ME11_IN_Fault                  ((uint8)1U)
#define ME11_IN_HVOff                  ((uint8)1U)
#define ME11_IN_HVOn                   ((uint8)2U)
#define ME11_IN_NO_ACTIVE_CHILD        ((uint8)0U)
#define ME11_IN_Normal                 ((uint8)2U)
#define ME11_IN_wait                   ((uint8)3U)
#define ME11_IN_wait1                  ((uint8)4U)

#define ME11_IN_Default                ((uint8)1U)
#define ME11_IN_Flg3                   ((uint8)2U)

#define ME11_IN_Off                    ((uint8)1U)
#define ME11_IN_On                     ((uint8)2U)

#define ME11_IN_Default_f              ((uint8)1U)
#define ME11_IN_wait1_e                ((uint8)3U)
#define ME11_IN_wait_n                 ((uint8)2U)

#define ME11_IN_Default_c              ((uint8)1U)
#define ME11_IN_Err                    ((uint8)2U)
#define ME11_IN_wait1_m                ((uint8)4U)
#define ME11_IN_wait_p                 ((uint8)3U)

#define ME11_IN_Default_d              ((uint8)1U)
#define ME11_IN_Err_b                  ((uint8)2U)
#define ME11_IN_wait1_d                ((uint8)4U)
#define ME11_IN_wait_o                 ((uint8)3U)

#define ME11_IN_Fault_a                ((uint8)1U)
#define ME11_IN_Normal_f               ((uint8)2U)
#define ME11_IN_wait_g                 ((uint8)3U)

#define ME11_IN_Off_c                  ((uint8)1U)
#define ME11_IN_On_k                   ((uint8)2U)
#define ME11_IN_Wait                   ((uint8)3U)

#define ME11_IN_Init                   ((uint8)1U)
#define ME11_IN_MaxErr                 ((uint8)1U)
#define ME11_IN_MaxJudge               ((uint8)2U)
#define ME11_IN_MinErr                 ((uint8)3U)
#define ME11_IN_MinJudge               ((uint8)4U)
#define ME11_IN_NO_ACTIVE_CHILD_g      ((uint8)0U)
#define ME11_IN_judge                  ((uint8)2U)
#define ME11_IN_wait_go                ((uint8)3U)

#define ME11_IN_Off_e                  ((uint8)1U)
#define ME11_IN_On_l                   ((uint8)2U)
#define ME11_IN_Wait_b                 ((uint8)3U)

#define ME11_IN_False                  ((uint8)1U)
#define ME11_IN_True                   ((uint8)2U)
#define ME11_IN_Wait_i                 ((uint8)3U)

#define ME11_IN_False_k                ((uint8)1U)
#define ME11_IN_True_a                 ((uint8)2U)
#define ME11_IN_Wait_p                 ((uint8)3U)

#define ME11_IN_Off_cr                 ((uint8)1U)
#define ME11_IN_On_lt                  ((uint8)2U)

#define ME11_IN_Fan_0                  ((uint8)1U)
#define ME11_IN_Fan_01                 ((uint8)2U)
#define ME11_IN_Fan_02                 ((uint8)3U)
#define ME11_IN_Fan_03                 ((uint8)4U)
#define ME11_IN_Fan_04                 ((uint8)5U)
#define ME11_IN_Fan_05                 ((uint8)6U)
#define ME11_IN_Fan_06                 ((uint8)7U)
#define ME11_IN_Fan_07                 ((uint8)8U)
#define ME11_IN_Fan_08                 ((uint8)9U)
#define ME11_IN_NO_ACTIVE_CHILD_gl     ((uint8)0U)

#define ME11_IN_Limit                  ((uint8)1U)
#define ME11_IN_Mode                   ((uint8)2U)
#define ME11_IN_Modehaschanged         ((uint8)3U)

#define ME11_ColdStart                 ((uint8)1U)
#define ME11_HotStart                  ((uint8)2U)
#define ME11_IN_BlowerModeLim          ((uint8)1U)
#define ME11_IN_BlowerModeLockFloor    ((uint8)2U)
#define ME11_IN_BlowerModeLockFloor1   ((uint8)3U)
#define ME11_IN_BlowerNormal           ((uint8)4U)
#define ME11_IN_Face                   ((uint8)1U)
#define ME11_IN_Face_Floor             ((uint8)2U)
#define ME11_IN_Floor                  ((uint8)3U)
#define ME11_LittleCold                ((uint8)3U)
#define ME11_NormalStart               ((uint8)0U)

#define ME11_IN_ACCtl_tiAQSHi_cnt      ((uint8)1U)
#define ME11_IN_ACCtl_tiAQSHi_cntClear ((uint8)2U)
#define ME11_IN_ACCtl_tiAQSLo_cnt      ((uint8)1U)
#define ME11_IN_ACCtl_tiAQSLo_cntClear ((uint8)2U)
#define ME11_IN_Initi                  ((uint8)1U)
#define ME11_IN_Recirc_AQS             ((uint8)2U)

#define ME11_IN_BlowerFanWorkTimeAdd   ((uint8)1U)
#define ME11_IN_BlowerFanWorkTimeKeep  ((uint8)2U)
#define ME11_IN_BlowerFan_Off          ((uint8)1U)
#define ME11_IN_BlowerFan_On           ((uint8)2U)
#define ME11_IN_Cold_Air_Protection    ((uint8)1U)
#define ME11_IN_Hot_Air_Protection     ((uint8)2U)
#define ME11_IN_IGN_OFF                ((uint8)1U)
#define ME11_IN_IGN_ON                 ((uint8)2U)
#define ME11_IN_Normal_LittleCold      ((uint8)3U)
#define ME11_IN_Normal_Op              ((uint8)4U)

#define ME11_IN_DecreaseTemp           ((uint8)1U)
#define ME11_IN_Delay                  ((uint8)1U)
#define ME11_IN_Delaychecked           ((uint8)2U)
#define ME11_IN_DontChange             ((uint8)2U)
#define ME11_IN_IncreaseTemp           ((uint8)3U)

#define ME11_IN_Eva_Stop               ((uint8)1U)
#define ME11_IN_Eva_Stoping            ((uint8)2U)
#define ME11_IN_Eva_cooling            ((uint8)3U)

#define ME11_IN_PTC_Heating            ((uint8)1U)
#define ME11_IN_PTC_Stop               ((uint8)2U)
#define ME11_IN_PTC_Stoping            ((uint8)3U)

#define ME11_IN_Exhaust_Check          ((uint8)1U)
#define ME11_IN_Exhaust_OFF            ((uint8)2U)
#define ME11_IN_Exhaust_ON             ((uint8)1U)
#define ME11_IN_Exhaust_intl           ((uint8)2U)

#define ME11_IN_Off_a                  ((uint8)1U)
#define ME11_IN_On_li                  ((uint8)2U)
#define ME11_IN_Wait_c                 ((uint8)3U)

#define ME11_IN_Clear_d                ((uint8)1U)
#define ME11_IN_Fault_ax               ((uint8)1U)
#define ME11_IN_HVOff_o                ((uint8)1U)
#define ME11_IN_HVOn_o                 ((uint8)2U)
#define ME11_IN_Normal_k               ((uint8)2U)
#define ME11_IN_wait1_o                ((uint8)4U)
#define ME11_IN_wait_k                 ((uint8)3U)

#define ME11_IN_Default_k              ((uint8)1U)
#define ME11_IN_Fault_b                ((uint8)2U)

#define ME11_IN_Normal_m               ((uint8)1U)
#define ME11_IN_Stop                   ((uint8)2U)
#define ME11_IN_Stop1                  ((uint8)3U)
#define ME11_IN_wait_f                 ((uint8)4U)

#define ME11_IN_Flg2                   ((uint8)1U)
#define ME11_IN_Flg3_n                 ((uint8)2U)
#define ME11_IN_wait_2                 ((uint8)3U)

#define ME11_IN_Flg1                   ((uint8)1U)
#define ME11_IN_Flg2_j                 ((uint8)2U)
#define ME11_IN_Flg3_p                 ((uint8)3U)
#define ME11_IN_wait_2_i               ((uint8)4U)
#define ME11_IN_wait_3                 ((uint8)5U)

#define ME11_IN_ChgBatCool             ((uint8)1U)
#define ME11_IN_ChgDCool               ((uint8)2U)
#define ME11_IN_NmlBatCool             ((uint8)3U)
#define ME11_IN_NmlBatCool1            ((uint8)4U)
#define ME11_IN_NmlBatCool2            ((uint8)5U)
#define ME11_IN_NmlDCoolHVS            ((uint8)6U)
#define ME11_IN_NmlDCoolLVS            ((uint8)7U)

#define ME11_IN_Init_i                 ((uint8)1U)
#define ME11_IN_protect                ((uint8)2U)

#define ME11_IN_Forbit                 ((uint8)2U)
#define ME11_IN_Lmt                    ((uint8)3U)

#define ME11_IN_CloseCtl               ((uint8)1U)
#define ME11_IN_DelayOpen              ((uint8)2U)
#define ME11_IN_OpenCtl                ((uint8)3U)
#define ME11_IN_RelayOpen              ((uint8)4U)

#define ME11_IN_forbit                 ((uint8)2U)
#define ME11_IN_limit                  ((uint8)3U)

#define ME11_IN_wait1_l                ((uint8)3U)
#define ME11_IN_wait_d                 ((uint8)2U)

#define ME11_IN_StepUp                 ((uint8)2U)

#define ME11_IN_CloseCtrl              ((uint8)1U)
#define ME11_IN_OpenCtrl               ((uint8)2U)

#define ME11_IN_CalClsSpd              ((uint8)1U)
#define ME11_IN_CloseVavle             ((uint8)2U)
#define ME11_IN_Default_o              ((uint8)3U)
#define ME11_IN_OpenCtrl_l             ((uint8)4U)
#define ME11_IN_Wait1                  ((uint8)6U)
#define ME11_IN_Wait_bn                ((uint8)5U)
#define ME11_IN_wait_oc                ((uint8)7U)

#define ME11_IN_wait_Off               ((uint8)3U)
#define ME11_IN_wait_On                ((uint8)4U)

#define ME11_IN_Err_e                  ((uint8)2U)

#define ME11_IN_Act                    ((uint8)1U)
#define ME11_IN_Dec                    ((uint8)1U)
#define ME11_IN_Init_o                 ((uint8)2U)

#define ME11_IN_OFF                    ((uint8)1U)
#define ME11_IN_ON                     ((uint8)2U)

#define ME11_IN_Add                    ((uint8)1U)
#define ME11_IN_Continue               ((uint8)1U)
#define ME11_IN_Dec_d                  ((uint8)2U)
#define ME11_IN_Init_n                 ((uint8)3U)
#define ME11_IN_Max                    ((uint8)1U)
#define ME11_IN_Min                    ((uint8)2U)
#define ME11_IN_Normal_i               ((uint8)3U)
#define ME11_IN_NvmRead                ((uint8)4U)
#define ME11_IN_One                    ((uint8)2U)
#define ME11_IN_Two                    ((uint8)2U)

#define ME11_IN_Max_d                  ((uint8)2U)
#define ME11_IN_Min_b                  ((uint8)3U)
#define ME11_IN_Normal_l               ((uint8)4U)
#define ME11_IN_One_l                  ((uint8)1U)
#define ME11_IN_Two_h                  ((uint8)1U)
#define ME11_IN_wait_Max               ((uint8)5U)
#define ME11_IN_wait_Min               ((uint8)6U)

#define ME11_IN_Defrost                ((uint8)1U)
#define ME11_IN_Defrost_Foot           ((uint8)2U)
#define ME11_IN_Face_Foot              ((uint8)4U)
#define ME11_IN_Face_l                 ((uint8)3U)
#define ME11_IN_Foot                   ((uint8)5U)

#define ME11_IN_AddT                   ((uint8)1U)
#define ME11_IN_Chg_Off                ((uint8)1U)
#define ME11_IN_Chg_On                 ((uint8)2U)
#define ME11_IN_DecT                   ((uint8)2U)
#define ME11_IN_Nml                    ((uint8)4U)
#define ME11_IN_Nml_Init               ((uint8)3U)
#define ME11_IN_Set                    ((uint8)4U)
#define ME11_event_AddKey              (0)
#define ME11_event_DecKey              (1)

#define ME11_IN_After                  ((uint8)1U)
#define ME11_IN_Enter                  ((uint8)2U)
#define ME11_IN_Exit                   ((uint8)3U)
#define ME11_IN_Init_h                 ((uint8)4U)
#define ME11_IN_wait_b                 ((uint8)5U)

#define ME11_IN_Off_l                  ((uint8)2U)
#define ME11_IN_On_kf                  ((uint8)3U)

#define ME11_IN_Active                 ((uint8)1U)
#define ME11_IN_Default_c4             ((uint8)2U)
#define ME11_IN_Max_n                  ((uint8)4U)

#define ME11_IN_ALLInner               ((uint8)1U)
#define ME11_IN_ALLOut                 ((uint8)2U)
#define ME11_IN_Fault1                 ((uint8)5U)
#define ME11_IN_Fault_j                ((uint8)4U)
#define ME11_IN_InRec_Stuck            ((uint8)6U)
#define ME11_IN_InnerRec               ((uint8)7U)
#define ME11_IN_Judge                  ((uint8)2U)
#define ME11_IN_OutRec                 ((uint8)8U)
#define ME11_IN_OutRec_Stuck           ((uint8)9U)

#define ME11_IN_ALLCool                ((uint8)1U)
#define ME11_IN_AllWarm                ((uint8)2U)
#define ME11_IN_Cool                   ((uint8)3U)
#define ME11_IN_Default_d2             ((uint8)4U)
#define ME11_IN_Fault1_c               ((uint8)6U)
#define ME11_IN_Fault_d                ((uint8)5U)
#define ME11_IN_InMix_Stuck            ((uint8)7U)
#define ME11_IN_OutMix_Stuck           ((uint8)8U)
#define ME11_IN_Warm                   ((uint8)9U)

#define ME11_IN_ALLDefrost             ((uint8)1U)
#define ME11_IN_ALLFace                ((uint8)2U)
#define ME11_IN_Defrost_Stuck          ((uint8)5U)
#define ME11_IN_Defrost_j              ((uint8)4U)
#define ME11_IN_Face_Stuck             ((uint8)7U)
#define ME11_IN_Face_f                 ((uint8)6U)
#define ME11_IN_Fault1_b               ((uint8)9U)
#define ME11_IN_Fault_l                ((uint8)8U)

#define ME11_IN_Counter_Cal            ((uint8)1U)
#define ME11_IN_Counter_Init           ((uint8)2U)

#define ME11_IN_BTMS_Default           ((uint8)1U)
#define ME11_IN_BTMS_NormalThermal     ((uint8)2U)
#define ME11_IN_BTMS_QuickChargeThermal ((uint8)3U)
#define ME11_IN_BTMS_SlowChargeThermal ((uint8)4U)

#define ME11_IN_CoAC_stAfterRun        ((uint8)1U)
#define ME11_IN_CoAC_stChargeWakeUp    ((uint8)1U)
#define ME11_IN_CoAC_stInit            ((uint8)2U)
#define ME11_IN_CoAC_stNativeWakeUp    ((uint8)2U)
#define ME11_IN_CoAC_stNormal          ((uint8)3U)
#define ME11_IN_CoAC_stOTA             ((uint8)4U)
#define ME11_IN_CoAC_stRemoteWakeUp    ((uint8)3U)
#define ME11_IN_CoAC_stStop            ((uint8)5U)

#define ME11_IN_T15_OFF                ((uint8)1U)
#define ME11_IN_T15_ON                 ((uint8)2U)

#define ME11_IN_ACchg                  ((uint8)1U)
#define ME11_IN_DCchg                  ((uint8)2U)
#define ME11_IN_Dischg                 ((uint8)4U)
#define ME11_IN_LowVoltage             ((uint8)5U)
#define ME11_IN_PTReady                ((uint8)6U)

#define ME11_IN_Close                  ((uint8)1U)
#define ME11_IN_Open                   ((uint8)2U)

#define ME11_IN_Balance                ((uint8)1U)
#define ME11_IN_BatMode                ((uint8)1U)
#define ME11_IN_Cool_j                 ((uint8)2U)
#define ME11_IN_HStr                   ((uint8)3U)
#define ME11_IN_Heat                   ((uint8)4U)
#define ME11_IN_LTR                    ((uint8)5U)
#define ME11_IN_MotorHeatBat           ((uint8)6U)
#define ME11_IN_Off_g                  ((uint8)7U)

#define ME11_IN_HStr_m                 ((uint8)2U)
#define ME11_IN_LTR_d                  ((uint8)3U)
#define ME11_IN_MotLTRAndBat           ((uint8)4U)
#define ME11_IN_MotLTRAndBatCool       ((uint8)5U)
#define ME11_IN_WatMode                ((uint8)2U)

#define ME11_IN_MD1                    ((uint8)1U)
#define ME11_IN_MD2                    ((uint8)2U)
#define ME11_IN_MD3                    ((uint8)3U)
#define ME11_IN_MD4                    ((uint8)4U)
#define ME11_IN_MD5                    ((uint8)1U)
#define ME11_IN_Standby                ((uint8)2U)
#define ME11_IN_Work                   ((uint8)3U)

#define ME11_IN_Wait_o                 ((uint8)2U)

#define ME11_IN_ExhDef                 ((uint8)1U)
#define ME11_IN_Nml_d                  ((uint8)2U)

#define ME11_IN_GetData                ((uint8)1U)
#define ME11_IN_Middle                 ((uint8)2U)
#define ME11_IN_init                   ((uint8)3U)

#define ME11_IN_after                  ((uint8)1U)
#define ME11_IN_init_f                 ((uint8)2U)

#define ME11_IN_COMP                   ((uint8)1U)
#define ME11_IN_ECV                    ((uint8)2U)
#define ME11_IN_EXV                    ((uint8)3U)
#define ME11_IN_Flt                    ((uint8)1U)
#define ME11_IN_PMP                    ((uint8)4U)
#define ME11_IN_PTC                    ((uint8)5U)
#define ME11_IN_SEN                    ((uint8)6U)
#ifndef PORTABLE_WORDSIZES
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULLONG_MAX != (0xFFFFFFFFFFFFFFFFULL) ) || ( LLONG_MAX != (0x7FFFFFFFFFFFFFFFLL) )
#error Code was generated for compiler with different sized typeStr. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif
#endif

ARID_DEF_ME11_TMSIODriverFunc_T ME11_TMSIODriverFunc_ARID_DEF;
ARID_DEF_ME11_TMSADCSampleFunc_T ME11_TMSADCSampleFunc_ARID_DEF;
float32 GLB_ESC_VehicleSpeed;
uint8 GLB_CoAC_stwork;
boolean GLB_CoAC_stColdStart;
boolean GLB_ESC_VehicleSpeedValid;
const ConstP_ME11_T ME11_ConstP = {

  { 1.5F, 2.5F, 4.5F, 8.0F, 12.0F },


  { -1.0F, 0.0F, 1.5F, 3.0F, 5.0F },


  { 0.5F, 4.5F },


  { 14U, 14U },


  { 9U, 9U },


  { 3U, 6U },


  { 13U, 13U },


  { 7U, 7U },


  { 5U, 5U },


  { 11U, 11U },


  { 5U, 6U },


  { 5U, 4U },


  { 3U, 12U },


  { 0U, 100U },


  { 4U, 5U, 6U, 7U, 8U },


  { 4U, 5U, 6U, 7U, 8U, 10U, 14U },


  { 1U, 3U, 7U, 8U, 14U },


  { 1U, 3U, 7U, 8U, 9U, 14U },


  { 4U, 6U, 7U, 8U, 14U }
};

ARID_DEF_ME11_T ME11_ARID_DEF;
sint16 look1_iu16lu64n48ts16Ds32_binlcas(uint16 u0, const uint16 bp0[], const
  sint16 table[], uint32 maxIndex);
float32 look1_iflf_binlca(float32 u0, const float32 bp0[], const float32 table[],
  uint32 maxIndex);
uint8 look1_iflftu8Df_binlca(float32 u0, const float32 bp0[], const uint8 table[],
  uint32 maxIndex);
uint32 binsearch_u32f(float32 u, const float32 bp[], uint32 startIndex, uint32
                      maxIndex);
float32 look2_iflf_binlca(float32 u0, float32 u1, const float32 bp0[], const
  float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride);
uint16 look1_iflftu16Df_binlca(float32 u0, const float32 bp0[], const uint16
  table[], uint32 maxIndex);
float32 look2_iu16flftf_binlca(uint16 u0, float32 u1, const uint16 bp0[], const
  float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride);
float32 look2_ifu8lftf_binlca(float32 u0, uint8 u1, const float32 bp0[], const
  uint8 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride);
float32 look1_iu8lftf_binlca(uint8 u0, const uint8 bp0[], const float32 table[],
  uint32 maxIndex);
float32 look2_ifbfu8lf_binlca(float32 u0, float32 u1, const float32 bp0[], const
  uint8 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride);
uint8 look2_iflftu8Dfdf_binlca(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const uint8 table[], const uint32 maxIndex[], uint32
  stride);
uint8 look1_iu8lu64n56_binlcase(uint8 u0, const uint8 bp0[], const uint8 table[],
  uint32 maxIndex);
float32 look2_iu8flftf_binlca(uint8 u0, float32 u1, const uint8 bp0[], const
  float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride);
float32 look1_iu8bflftf_binlca(uint8 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex);
float32 look1_iu16bflftf_binlca(uint16 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex);
float32 look1_iu16lftf_binlca(uint16 u0, const uint16 bp0[], const float32
  table[], uint32 maxIndex);
uint32 plook_u32f_bincka(float32 u, const float32 bp[], uint32 maxIndex);
uint32 plook_u32f_binckan(float32 u, const float32 bp[], uint32 maxIndex);
uint32 plook_u32u8_binckan(uint8 u, const uint8 bp[], uint32 maxIndex);
uint32 binsearch_u32u8(uint8 u, const uint8 bp[], uint32 startIndex, uint32
  maxIndex);
extern void ME11_ManualMode(boolean rtu_Enable, BlowerModes
  rtu_ACCtl_BlowerModeManual, BlowerModes *rty_ACCtl_stBlowerMode);
extern void ME11_ACCtlRecForPTCDvt(boolean *rty_ACCtl_stRecOut, uint8
  *rty_ACCtl_rIntakeDoor);
extern void ME11_P_NEG(boolean rtu_Enable, float32 rtu_Dvt, float32 rtu_IWinNeg,
  float32 rtu_IkiNeg, float32 rtu_Ki, float32 *rty_P_NEG);
extern void ME11_P_POS(boolean rtu_Enable, float32 rtu_Dvt, float32 rtu_IWinPos,
  float32 rtu_IKiPos, float32 rtu_Ki, float32 *rty_P_Pos);
extern void ME11_deadzone_Init(boolean *rty_flag);
extern void ME11_deadzone(float32 rtu_u, float32 rtu_Deadzone, boolean *rty_flag);
extern void ME11_PI_Controller(boolean rtu_Enable, boolean rtu_Dvt_POSFlag,
  float32 rtu_PI_feedforward, float32 rtu_P_Cor, float32 rtu_I_Sum, float32
  rtu_PI_CorMax, float32 rtu_PI_CorMin, float32 *rty_PI_Cor, uint8
  *rty_IFreezFlag);
extern void ME11_PI_Controller1(boolean rtu_Enable, float32 rtu_PI_Defult,
  float32 *rty_PI_Cor, uint8 *rty_IFreezFlag);
extern void ME11_P_NEG_p(boolean rtu_Enable, float32 rtu_Dvt, float32
  rtu_pWinNeg, float32 rtu_pkpNeg, float32 rtu_pKp, float32 *rty_Out1);
extern void ME11_P_POS_l(boolean rtu_Enable, float32 rtu_Dvt, float32
  rtu_pWinPos, float32 rtu_pKpPos, float32 rtu_pKp, float32 *rty_Out1);
extern void ME11_deadzone_a_Init(boolean *rty_flag);
extern void ME11_deadzone_h(float32 rtu_u, float64 rtu_Deadzone, boolean
  *rty_flag);
extern void ME11_OverDuty1_Init(boolean *rty_Sts, float64 *rty_ClearFlt);
extern void ME11_OverDuty1(uint8 rtu_PWRCtl_eTMSStatus, boolean rtu_FaultFlg,
  boolean *rty_Sts, float64 *rty_ClearFlt, ARID_DEF_OverDuty1_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_Flg3Cal_Init(boolean *rty_ACTCtl_eCOMPFlg3Cal);
extern void ME11_Flg3Cal(float32 rtu_HPFlg3, boolean *rty_ACTCtl_eCOMPFlg3Cal,
  ARID_DEF_Flg3Cal_ME11_T *ME11__ARID_DEF_arg);
extern void ME11_PwrOn_Init(boolean *rty_flg);
extern void ME11_PwrOn(boolean *rty_flg, ARID_DEF_PwrOn_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_deadzone_p_Init(boolean *rty_flag);
extern void ME11_deadzone_h1(float32 rtu_u, float32 rtu_Deadzone, boolean
  *rty_flag);
extern void ME11_Descending_filter_Init(ARID_DEF_Descending_filter_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_Descending_filter(boolean rtu_Enable, float32 rtu_Add, float32
  rtu_Dec, float32 rtu_Speed, float32 rtu_COMP_EcompActSpd, float32 *rty_Y,
  ARID_DEF_Descending_filter_ME11_T *ME11__ARID_DEF_arg);
extern void ME11_Chart_Init(boolean *rty_Flag);
extern void ME11_Chart(boolean rtu_Condition, uint16 rtu_Timer, boolean
  *rty_Flag, ARID_DEF_Chart_ME11_T *ME11__ARID_DEF_arg);
extern void ME11_Abnormal_Over_temperatura_via_software_monitoring_Init(boolean *
  rty_ErrSts);
extern void ME11_Abnormal_Over_temperatura_via_software_monitoring(boolean
  rtu_Flg, boolean *rty_ErrSts,
  ARID_DEF_Abnormal_Over_temperatura_via_software_monitoring_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_External_Com_Fault_Init(boolean *rty_ErrSts);
extern void ME11_External_Com_Fault(boolean rtu_Flg, boolean *rty_ErrSts,
  ARID_DEF_External_Com_Fault_ME11_T *ME11__ARID_DEF_arg);
extern void ME11_AcPMPFaultJudge_Init(boolean *rty_ACTCtl_bAcPMPFaultFlg);
extern void ME11_AcPMPFaultJudge(boolean rtu_AcPMPFaultFlg, boolean
  *rty_ACTCtl_bAcPMPFaultFlg, ARID_DEF_AcPMPFaultJudge_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_Delay1_Init(boolean *rty_C);
extern void ME11_Delay1(uint8 rtu_A, boolean *rty_C, ARID_DEF_Delay1_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_Judge_Init(uint8 *rty_SenSts);
extern void ME11_Judge(boolean rtu_MaxFlg, boolean rtu_MinFlg, uint8 rtu_timer,
  uint8 *rty_SenSts, ARID_DEF_Judge_ME11_T *ME11__ARID_DEF_arg);
extern void ME11_Delay_Init(boolean *rty_C);
extern void ME11_Delay(boolean rtu_A, boolean *rty_C, ARID_DEF_Delay_ME11_T
  *ME11__ARID_DEF_arg);
extern void ME11_Chart_a_Init(boolean *rty_B);
extern void ME11_Chart_p(boolean rtu_A, boolean *rty_B, ARID_DEF_Chart_ME11_k_T *
  ME11__ARID_DEF_arg);
extern void ME11_Chart_l_Init(boolean *rty_B);
extern void ME11_Chart_e(boolean rtu_A, boolean *rty_B, ARID_DEF_Chart_ME11_m_T *
  ME11__ARID_DEF_arg);
extern void ME11_TMSIODriverFunc(void);
extern void ME11_TMSADCSampleFunc_Init(void);
extern void ME11_TMSADCSampleFunc(void);
void ME11_enter_internal_ThermalCoordinate(void);
void ME11_enter_internal_Sts(uint8 *PWRCtl_eTMSStatus_a);
void ME11_Cal(const boolean *FixPtRelationalOperator);
void ME11_enter_internal_Mode(void);
void ME11_sart(float64 v1, float64 v2, float64 *a, float64 *b);
void ME11_enter_internal_Choice(const uint8 *SOMCtl_eRefModes_b);
sint16 look1_iu16lu64n48ts16Ds32_binlcas(uint16 u0, const uint16 bp0[], const
  sint16 table[], uint32 maxIndex)
{
  uint64 frac;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  sint16 y;
  sint16 yL_0d0;
  uint16 bpLeftVar;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
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

    bpLeftVar = bp0[iLeft];
    frac = ((uint64)(uint16)((uint32)u0 - bpLeftVar) << 48) / (uint16)((uint32)
      bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex;
    frac = 0ULL;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (sint16)((sint16)(((table[iLeft + 1U] - yL_0d0) * (sint64)frac) >> 48) +
                 yL_0d0);
  }

  return y;
}

float32 look1_iflf_binlca(float32 u0, const float32 bp0[], const float32 table[],
  uint32 maxIndex)
{
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

uint8 look1_iflftu8Df_binlca(float32 u0, const float32 bp0[], const uint8 table[],
  uint32 maxIndex)
{
  float32 frac;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 y;
  uint8 yL_0d0;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (uint8)((uint32)(uint8)(((float32)table[iLeft + 1U] - (float32)yL_0d0) *
      frac) + yL_0d0);
  }

  return y;
}

uint32 binsearch_u32f(float32 u, const float32 bp[], uint32 startIndex, uint32
                      maxIndex)
{
  uint32 bpIdx;
  uint32 bpIndex;
  uint32 iRght;
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

float32 look2_iflf_binlca(float32 u0, float32 u1, const float32 bp0[], const
  float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride)
{
  float32 fractions[2];
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
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
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

uint16 look1_iflftu16Df_binlca(float32 u0, const float32 bp0[], const uint16
  table[], uint32 maxIndex)
{
  float32 frac;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint16 y;
  uint16 yL_0d0;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (uint16)((uint32)(uint16)(((float32)table[iLeft + 1U] - (float32)yL_0d0)
      * frac) + yL_0d0);
  }

  return y;
}

float32 look2_iu16flftf_binlca(uint16 u0, float32 u1, const uint16 bp0[], const
  float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride)
{
  float32 fractions[2];
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint16 bpLeftVar;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = (float32)(uint16)((uint32)u0 - bpLeftVar) / (float32)(uint16)((uint32)
      bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

float32 look2_ifu8lftf_binlca(float32 u0, uint8 u1, const float32 bp0[], const
  uint8 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride)
{
  float32 fractions[2];
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 bpLeftVar;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
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
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    bpLeftVar = bp1[iLeft];
    frac = (float32)(uint8)((uint32)u1 - bpLeftVar) / (float32)(uint8)((uint32)
      bp1[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

float32 look1_iu8lftf_binlca(uint8 u0, const uint8 bp0[], const float32 table[],
  uint32 maxIndex)
{
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 bpLeftVar;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

    bpLeftVar = bp0[iLeft];
    frac = (float32)(uint8)((uint32)u0 - bpLeftVar) / (float32)(uint8)((uint32)
      bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

float32 look2_ifbfu8lf_binlca(float32 u0, float32 u1, const float32 bp0[], const
  uint8 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride)
{
  float32 fractions[2];
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 uCast;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
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
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;
  if (u1 < 256.0F) {
    if (u1 >= 0.0F) {
      uCast = (uint8)u1;
    } else {
      uCast = 0U;
    }
  } else {
    uCast = MAX_uint8_T;
  }

  if (u1 < bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (uCast < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - (float32)bp1[iLeft]) / (float32)(uint8)((uint32)bp1[iLeft + 1U]
      - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

uint8 look2_iflftu8Dfdf_binlca(float32 u0, float32 u1, const float32 bp0[],
  const float32 bp1[], const uint8 table[], const uint32 maxIndex[], uint32
  stride)
{
  float32 fractions[2];
  float32 frac;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 y;
  uint8 yL_0d0;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
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
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (uint8)((uint32)(uint8)(((float32)table[bpIdx + 1U] - (float32)yL_0d0) *
      fractions[0U]) + yL_0d0);
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 = (uint8)((uint32)(uint8)(((float32)table[bpIdx + 1U] - (float32)
        yL_0d0) * fractions[0U]) + yL_0d0);
    }

    y = (uint8)((uint32)(uint8)(((float32)yL_0d0 - (float32)y) * frac) + y);
  }

  return y;
}

uint8 look1_iu8lu64n56_binlcase(uint8 u0, const uint8 bp0[], const uint8 table[],
  uint32 maxIndex)
{
  uint64 frac;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 bpLeftVar;
  uint8 y;
  uint8 yL_0d0;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
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

    bpLeftVar = bp0[iLeft];
    frac = ((uint64)(uint8)((uint32)u0 - bpLeftVar) << 56) / (uint8)((uint32)
      bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex;
    frac = 0ULL;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    bpLeftVar = table[iLeft + 1U];
    yL_0d0 = table[iLeft];
    if (bpLeftVar >= yL_0d0) {
      y = (uint8)((uint32)(uint8)(((uint8)((uint32)bpLeftVar - yL_0d0) * frac) >>
        56) + yL_0d0);
    } else {
      y = (uint8)((uint32)yL_0d0 - (uint8)(((uint8)((uint32)yL_0d0 - bpLeftVar) *
        frac) >> 56));
    }
  }

  return y;
}

float32 look2_iu8flftf_binlca(uint8 u0, float32 u1, const uint8 bp0[], const
  float32 bp1[], const float32 table[], const uint32 maxIndex[], uint32 stride)
{
  float32 fractions[2];
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIndices[2];
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint8 bpLeftVar;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex[0U]]) {
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    bpLeftVar = bp0[iLeft];
    frac = (float32)(uint8)((uint32)u0 - bpLeftVar) / (float32)(uint8)((uint32)
      bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex[0U];
    frac = 0.0F;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u1 < bp1[maxIndex[1U]]) {
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U];
    frac = 0.0F;
  }

  bpIdx = iLeft * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[bpIdx];
  } else {
    yL_0d0 = table[bpIdx];
    y = (table[bpIdx + 1U] - yL_0d0) * fractions[0U] + yL_0d0;
  }

  if (iLeft == maxIndex[1U]) {
  } else {
    bpIdx += stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yL_0d0 = table[bpIdx];
    } else {
      yL_0d0 = table[bpIdx];
      yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
    }

    y += (yL_0d0 - y) * frac;
  }

  return y;
}

float32 look1_iu8bflftf_binlca(uint8 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

    frac = ((float32)u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

float32 look1_iu16bflftf_binlca(uint16 u0, const float32 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  if (u0 < bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

    frac = ((float32)u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

float32 look1_iu16lftf_binlca(uint16 u0, const uint16 bp0[], const float32
  table[], uint32 maxIndex)
{
  float32 frac;
  float32 y;
  float32 yL_0d0;
  uint32 bpIdx;
  uint32 iLeft;
  uint32 iRght;
  uint16 bpLeftVar;
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
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

    bpLeftVar = bp0[iLeft];
    frac = (float32)(uint16)((uint32)u0 - bpLeftVar) / (float32)(uint16)((uint32)
      bp0[iLeft + 1U] - bpLeftVar);
  } else {
    iLeft = maxIndex;
    frac = 0.0F;
  }

  if (iLeft == maxIndex) {
    y = table[iLeft];
  } else {
    yL_0d0 = table[iLeft];
    y = (table[iLeft + 1U] - yL_0d0) * frac + yL_0d0;
  }

  return y;
}

uint32 plook_u32f_bincka(float32 u, const float32 bp[], uint32 maxIndex)
{
  uint32 bpIndex;
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32 plook_u32f_binckan(float32 u, const float32 bp[], uint32 maxIndex)
{
  uint32 bpIndex;
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32f(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && (bp[bpIndex + 1U] - u <= u - bp[bpIndex])) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32 plook_u32u8_binckan(uint8 u, const uint8 bp[], uint32 maxIndex)
{
  uint32 bpIndex;
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = binsearch_u32u8(u, bp, maxIndex >> 1U, maxIndex);
    if ((bpIndex < maxIndex) && ((uint8)((uint32)bp[bpIndex + 1U] - u) <= (uint8)
         ((uint32)u - bp[bpIndex]))) {
      bpIndex++;
    }
  } else {
    bpIndex = maxIndex;
  }

  return bpIndex;
}

uint32 binsearch_u32u8(uint8 u, const uint8 bp[], uint32 startIndex, uint32
  maxIndex)
{
  uint32 bpIdx;
  uint32 bpIndex;
  uint32 iRght;
  bpIdx = startIndex;
  bpIndex = 0U;
  iRght = maxIndex;
  while (iRght - bpIndex > 1U) {
    if (u < bp[bpIdx]) {
      iRght = bpIdx;
    } else {
      bpIndex = bpIdx;
    }

    bpIdx = (iRght + bpIndex) >> 1U;
  }

  return bpIndex;
}

void ME11_ManualMode(boolean rtu_Enable, BlowerModes rtu_ACCtl_BlowerModeManual,
                     BlowerModes *rty_ACCtl_stBlowerMode)
{
  if (rtu_Enable) {
    *rty_ACCtl_stBlowerMode = rtu_ACCtl_BlowerModeManual;
  }
}

void ME11_ACCtlRecForPTCDvt(boolean *rty_ACCtl_stRecOut, uint8
  *rty_ACCtl_rIntakeDoor)
{
  *rty_ACCtl_stRecOut = true;
  *rty_ACCtl_rIntakeDoor = 100U;
}

void ME11_P_NEG(boolean rtu_Enable, float32 rtu_Dvt, float32 rtu_IWinNeg,
                float32 rtu_IkiNeg, float32 rtu_Ki, float32 *rty_P_NEG)
{
  if (rtu_Enable) {
    if (rtu_Dvt > rtu_IWinNeg) {
      *rty_P_NEG = rtu_IkiNeg * rtu_Dvt;
    } else {
      *rty_P_NEG = rtu_Ki * rtu_Dvt;
    }
  }
}

void ME11_P_POS(boolean rtu_Enable, float32 rtu_Dvt, float32 rtu_IWinPos,
                float32 rtu_IKiPos, float32 rtu_Ki, float32 *rty_P_Pos)
{
  if (rtu_Enable) {
    if (rtu_Dvt > rtu_IWinPos) {
      *rty_P_Pos = rtu_IKiPos * rtu_Dvt;
    } else {
      *rty_P_Pos = rtu_Ki * rtu_Dvt;
    }
  }
}

void ME11_deadzone_Init(boolean *rty_flag)
{
  *rty_flag = false;
}

void ME11_deadzone(float32 rtu_u, float32 rtu_Deadzone, boolean *rty_flag)
{
  *rty_flag = ((float32)fabs(rtu_u) < rtu_Deadzone);
}

void ME11_PI_Controller(boolean rtu_Enable, boolean rtu_Dvt_POSFlag, float32
  rtu_PI_feedforward, float32 rtu_P_Cor, float32 rtu_I_Sum, float32
  rtu_PI_CorMax, float32 rtu_PI_CorMin, float32 *rty_PI_Cor, uint8
  *rty_IFreezFlag)
{
  float32 rtb_Switch_ek;
  if (rtu_Enable) {
    if (rtu_Dvt_POSFlag) {
      rtb_Switch_ek = (rtu_PI_feedforward + rtu_P_Cor) + rtu_I_Sum;
    } else {
      if (rtu_P_Cor < rtu_PI_feedforward) {
        rtb_Switch_ek = rtu_PI_feedforward - rtu_P_Cor;
      } else {
        rtb_Switch_ek = 0.0F;
      }

      rtb_Switch_ek += rtu_I_Sum;
    }

    if (rtb_Switch_ek > rtu_PI_CorMax) {
      rtb_Switch_ek = rtu_PI_CorMax;
    } else if (rtb_Switch_ek < rtu_PI_CorMin) {
      rtb_Switch_ek = rtu_PI_CorMin;
    }

    *rty_PI_Cor = rtb_Switch_ek;
    *rty_IFreezFlag = (uint8)((uint32)((rtb_Switch_ek <= rtu_PI_CorMin) << 1) +
      (uint32)(rtu_PI_CorMax <= rtb_Switch_ek));
  }
}

void ME11_PI_Controller1(boolean rtu_Enable, float32 rtu_PI_Defult, float32
  *rty_PI_Cor, uint8 *rty_IFreezFlag)
{
  if (rtu_Enable) {
    *rty_PI_Cor = rtu_PI_Defult;
    *rty_IFreezFlag = 3U;
  }
}

void ME11_P_NEG_p(boolean rtu_Enable, float32 rtu_Dvt, float32 rtu_pWinNeg,
                  float32 rtu_pkpNeg, float32 rtu_pKp, float32 *rty_Out1)
{
  float32 tmp;
  float32 tmp_0;
  if (rtu_Enable) {
    if (rtu_Dvt > rtu_pWinNeg) {
      tmp = rtu_Dvt - rtu_pWinNeg;
    } else {
      tmp = 0.0F;
    }

    if (rtu_Dvt <= rtu_pWinNeg) {
      tmp_0 = rtu_pKp * rtu_Dvt;
    } else {
      tmp_0 = rtu_pWinNeg * rtu_pKp;
    }

    *rty_Out1 = rtu_pkpNeg * tmp + tmp_0;
  }
}

void ME11_P_POS_l(boolean rtu_Enable, float32 rtu_Dvt, float32 rtu_pWinPos,
                  float32 rtu_pKpPos, float32 rtu_pKp, float32 *rty_Out1)
{
  float32 tmp;
  float32 tmp_0;
  if (rtu_Enable) {
    if (rtu_Dvt <= rtu_pWinPos) {
      tmp = rtu_pKp * rtu_Dvt;
    } else {
      tmp = rtu_pWinPos * rtu_pKp;
    }

    if (rtu_Dvt > rtu_pWinPos) {
      tmp_0 = rtu_Dvt - rtu_pWinPos;
    } else {
      tmp_0 = 0.0F;
    }

    *rty_Out1 = rtu_pKpPos * tmp_0 + tmp;
  }
}

void ME11_deadzone_a_Init(boolean *rty_flag)
{
  *rty_flag = false;
}

void ME11_deadzone_h(float32 rtu_u, float64 rtu_Deadzone, boolean *rty_flag)
{
  *rty_flag = ((float32)fabs(rtu_u) < rtu_Deadzone);
}

void ME11_OverDuty1_Init(boolean *rty_Sts, float64 *rty_ClearFlt)
{
  *rty_Sts = false;
  *rty_ClearFlt = 0.0;
}

void ME11_OverDuty1(uint8 rtu_PWRCtl_eTMSStatus, boolean rtu_FaultFlg, boolean
                    *rty_Sts, float64 *rty_ClearFlt, ARID_DEF_OverDuty1_ME11_T
                    *ME11__ARID_DEF_arg)
{
  sint32 tmp;
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 31U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->temporalCounter_i2 < 511U) {
    ME11__ARID_DEF_arg->temporalCounter_i2++;
  }

  if (ME11__ARID_DEF_arg->is_active_c36_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c36_ME11 = 1U;
    ME11__ARID_DEF_arg->is_FaultJudge = ME11_IN_Normal;
    *rty_Sts = false;
    ME11__ARID_DEF_arg->is_ClearFault = ME11_IN_HVOff;
    ME11__ARID_DEF_arg->Count = 0U;
    *rty_ClearFlt = 0.0;
  } else {
    switch (ME11__ARID_DEF_arg->is_FaultJudge) {
     case ME11_IN_Fault:
      *rty_Sts = true;
      if ((!rtu_FaultFlg) && (ME11__ARID_DEF_arg->Count < 4)) {
        ME11__ARID_DEF_arg->is_FaultJudge = ME11_IN_Normal;
        *rty_Sts = false;
      }
      break;

     case ME11_IN_Normal:
      *rty_Sts = false;
      if (rtu_FaultFlg && (*rty_ClearFlt == 0.0)) {
        ME11__ARID_DEF_arg->is_FaultJudge = ME11_IN_wait;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     default:
      if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 20U) {
        ME11__ARID_DEF_arg->is_FaultJudge = ME11_IN_Fault;
        *rty_Sts = true;
      } else if (!rtu_FaultFlg) {
        ME11__ARID_DEF_arg->is_FaultJudge = ME11_IN_Normal;
        *rty_Sts = false;
      }
      break;
    }

    if (ME11__ARID_DEF_arg->is_ClearFault == ME11_IN_HVOff) {
      *rty_ClearFlt = 0.0;
      if (rtu_PWRCtl_eTMSStatus >= 2) {
        ME11__ARID_DEF_arg->is_ClearFault = ME11_IN_HVOn;
        ME11__ARID_DEF_arg->is_HVOn = ME11_IN_Normal;
        *rty_ClearFlt = 0.0;
      }
    } else if (rtu_PWRCtl_eTMSStatus < 2) {
      ME11__ARID_DEF_arg->is_HVOn = ME11_IN_NO_ACTIVE_CHILD;
      ME11__ARID_DEF_arg->is_ClearFault = ME11_IN_HVOff;
      ME11__ARID_DEF_arg->Count = 0U;
      *rty_ClearFlt = 0.0;
    } else {
      switch (ME11__ARID_DEF_arg->is_HVOn) {
       case ME11_IN_Clear:
        *rty_ClearFlt = 1.0;
        if (ME11__ARID_DEF_arg->temporalCounter_i2 >= 5U) {
          ME11__ARID_DEF_arg->is_HVOn = ME11_IN_wait1;
          ME11__ARID_DEF_arg->temporalCounter_i2 = 0U;
          *rty_ClearFlt = 0.0;
        }
        break;

       case ME11_IN_Normal:
        *rty_ClearFlt = 0.0;
        if ((*rty_Sts) && (ME11__ARID_DEF_arg->Count < 4)) {
          ME11__ARID_DEF_arg->is_HVOn = ME11_IN_wait;
          ME11__ARID_DEF_arg->temporalCounter_i2 = 0U;
        }
        break;

       case ME11_IN_wait:
        if (ME11__ARID_DEF_arg->temporalCounter_i2 >= 50U) {
          ME11__ARID_DEF_arg->is_HVOn = ME11_IN_Clear;
          ME11__ARID_DEF_arg->temporalCounter_i2 = 0U;
          *rty_ClearFlt = 1.0;
          tmp = ME11__ARID_DEF_arg->Count + 1;
          if (ME11__ARID_DEF_arg->Count + 1 > 255) {
            tmp = 255;
          }

          ME11__ARID_DEF_arg->Count = (uint8)tmp;
        }
        break;

       default:
        *rty_ClearFlt = 0.0;
        if (ME11__ARID_DEF_arg->temporalCounter_i2 >= 300U) {
          ME11__ARID_DEF_arg->is_HVOn = ME11_IN_Normal;
          *rty_ClearFlt = 0.0;
        }
        break;
      }
    }
  }
}

void ME11_Flg3Cal_Init(boolean *rty_ACTCtl_eCOMPFlg3Cal)
{
  *rty_ACTCtl_eCOMPFlg3Cal = false;
}

void ME11_Flg3Cal(float32 rtu_HPFlg3, boolean *rty_ACTCtl_eCOMPFlg3Cal,
                  ARID_DEF_Flg3Cal_ME11_T *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->is_active_c34_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c34_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c34_ME11 = ME11_IN_Default;
    *rty_ACTCtl_eCOMPFlg3Cal = false;
  } else if (ME11__ARID_DEF_arg->is_c34_ME11 == ME11_IN_Default) {
    *rty_ACTCtl_eCOMPFlg3Cal = false;
    if (rtu_HPFlg3 == 1.0F) {
      ME11__ARID_DEF_arg->is_c34_ME11 = ME11_IN_Flg3;
      *rty_ACTCtl_eCOMPFlg3Cal = true;
    }
  } else {
    *rty_ACTCtl_eCOMPFlg3Cal = true;
    if (rtu_HPFlg3 == 0.0F) {
      ME11__ARID_DEF_arg->is_c34_ME11 = ME11_IN_Default;
      *rty_ACTCtl_eCOMPFlg3Cal = false;
    }
  }
}

void ME11_PwrOn_Init(boolean *rty_flg)
{
  *rty_flg = false;
}

void ME11_PwrOn(boolean *rty_flg, ARID_DEF_PwrOn_ME11_T *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 15U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c5_ME11Lib == 0U) {
    ME11__ARID_DEF_arg->is_active_c5_ME11Lib = 1U;
    ME11__ARID_DEF_arg->is_c5_ME11Lib = ME11_IN_Off;
    ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
    *rty_flg = true;
  } else if (ME11__ARID_DEF_arg->is_c5_ME11Lib == ME11_IN_Off) {
    *rty_flg = true;
    if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 10U) {
      ME11__ARID_DEF_arg->is_c5_ME11Lib = ME11_IN_On;
      *rty_flg = false;
    }
  } else {
    *rty_flg = false;
  }
}

void ME11_deadzone_p_Init(boolean *rty_flag)
{
  *rty_flag = false;
}

void ME11_deadzone_h1(float32 rtu_u, float32 rtu_Deadzone, boolean *rty_flag)
{
  *rty_flag = ((float32)fabs(rtu_u) < rtu_Deadzone);
}

void ME11_Descending_filter_Init(ARID_DEF_Descending_filter_ME11_T
  *ME11__ARID_DEF_arg)
{
  ME11__ARID_DEF_arg->FixPtUnitDelay2_DSTATE = 1U;
}

void ME11_Descending_filter(boolean rtu_Enable, float32 rtu_Add, float32 rtu_Dec,
  float32 rtu_Speed, float32 rtu_COMP_EcompActSpd, float32 *rty_Y,
  ARID_DEF_Descending_filter_ME11_T *ME11__ARID_DEF_arg)
{
  if (rtu_Enable) {
    if (ME11__ARID_DEF_arg->FixPtUnitDelay2_DSTATE != 0) {
      *rty_Y = rtu_Add;
    } else {
      *rty_Y = ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE;
    }

    if ((ME11__ARID_DEF_arg->Delay_DSTATE < 800.0F) && (rtu_COMP_EcompActSpd >=
         800.0F)) {
      ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE = rtu_Add;
    } else {
      ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE = *rty_Y - rtu_Speed;
      if (ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE - rtu_Dec <= 0.0F) {
        ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE = *rty_Y + rtu_Speed;
        if (ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE - rtu_Dec >= 0.0F) {
          ME11__ARID_DEF_arg->FixPtUnitDelay1_DSTATE = rtu_Dec;
        }
      }
    }

    ME11__ARID_DEF_arg->Delay_DSTATE = rtu_COMP_EcompActSpd;
    ME11__ARID_DEF_arg->FixPtUnitDelay2_DSTATE = 0U;
  }
}

void ME11_Chart_Init(boolean *rty_Flag)
{
  *rty_Flag = false;
}

void ME11_Chart(boolean rtu_Condition, uint16 rtu_Timer, boolean *rty_Flag,
                ARID_DEF_Chart_ME11_T *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->is_active_c153_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c153_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c153_ME11 = ME11_IN_Default_f;
    *rty_Flag = false;
    ME11__ARID_DEF_arg->counter = 0U;
  } else {
    switch (ME11__ARID_DEF_arg->is_c153_ME11) {
     case ME11_IN_Default_f:
      *rty_Flag = false;
      if (rtu_Condition) {
        ME11__ARID_DEF_arg->is_c153_ME11 = ME11_IN_wait_n;
      }
      break;

     case ME11_IN_wait_n:
      if (!rtu_Condition) {
        ME11__ARID_DEF_arg->is_c153_ME11 = ME11_IN_Default_f;
        *rty_Flag = false;
        ME11__ARID_DEF_arg->counter = 0U;
      } else if (ME11__ARID_DEF_arg->counter >= rtu_Timer) {
        ME11__ARID_DEF_arg->is_c153_ME11 = ME11_IN_wait1_e;
        *rty_Flag = true;
      } else {
        ME11__ARID_DEF_arg->counter++;
      }
      break;

     default:
      *rty_Flag = true;
      if (!rtu_Condition) {
        ME11__ARID_DEF_arg->is_c153_ME11 = ME11_IN_Default_f;
        *rty_Flag = false;
        ME11__ARID_DEF_arg->counter = 0U;
      }
      break;
    }
  }
}

void ME11_Abnormal_Over_temperatura_via_software_monitoring_Init(boolean
  *rty_ErrSts)
{
  *rty_ErrSts = false;
}

void ME11_Abnormal_Over_temperatura_via_software_monitoring(boolean rtu_Flg,
  boolean *rty_ErrSts,
  ARID_DEF_Abnormal_Over_temperatura_via_software_monitoring_ME11_T
  *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 7U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c119_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c119_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_Default_c;
    *rty_ErrSts = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c119_ME11) {
     case ME11_IN_Default_c:
      *rty_ErrSts = false;
      if (rtu_Flg) {
        ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_wait_p;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     case ME11_IN_Err:
      *rty_ErrSts = true;
      if (!rtu_Flg) {
        ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_wait1_m;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     case ME11_IN_wait_p:
      if (!rtu_Flg) {
        ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_Default_c;
        *rty_ErrSts = false;
      } else if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 5U) {
        ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_Err;
        *rty_ErrSts = true;
      }
      break;

     default:
      if (rtu_Flg) {
        ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_Err;
        *rty_ErrSts = true;
      } else if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 5U) {
        ME11__ARID_DEF_arg->is_c119_ME11 = ME11_IN_Default_c;
        *rty_ErrSts = false;
      }
      break;
    }
  }
}

void ME11_External_Com_Fault_Init(boolean *rty_ErrSts)
{
  *rty_ErrSts = false;
}

void ME11_External_Com_Fault(boolean rtu_Flg, boolean *rty_ErrSts,
  ARID_DEF_External_Com_Fault_ME11_T *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 31U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c66_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c66_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_Default_d;
    *rty_ErrSts = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c66_ME11) {
     case ME11_IN_Default_d:
      *rty_ErrSts = false;
      if (rtu_Flg) {
        ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_wait_o;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     case ME11_IN_Err_b:
      *rty_ErrSts = true;
      if (!rtu_Flg) {
        ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_wait1_d;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     case ME11_IN_wait_o:
      if (!rtu_Flg) {
        ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_Default_d;
        *rty_ErrSts = false;
      } else if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 20U) {
        ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_Err_b;
        *rty_ErrSts = true;
      }
      break;

     default:
      if (rtu_Flg) {
        ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_Err_b;
        *rty_ErrSts = true;
      } else if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 20U) {
        ME11__ARID_DEF_arg->is_c66_ME11 = ME11_IN_Default_d;
        *rty_ErrSts = false;
      }
      break;
    }
  }
}

void ME11_AcPMPFaultJudge_Init(boolean *rty_ACTCtl_bAcPMPFaultFlg)
{
  *rty_ACTCtl_bAcPMPFaultFlg = false;
}

void ME11_AcPMPFaultJudge(boolean rtu_AcPMPFaultFlg, boolean
  *rty_ACTCtl_bAcPMPFaultFlg, ARID_DEF_AcPMPFaultJudge_ME11_T
  *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 127U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c90_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c90_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c90_ME11 = ME11_IN_Normal_f;
    *rty_ACTCtl_bAcPMPFaultFlg = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c90_ME11) {
     case ME11_IN_Fault_a:
      if (!rtu_AcPMPFaultFlg) {
        ME11__ARID_DEF_arg->is_c90_ME11 = ME11_IN_Normal_f;
        *rty_ACTCtl_bAcPMPFaultFlg = false;
      }
      break;

     case ME11_IN_Normal_f:
      if (rtu_AcPMPFaultFlg) {
        ME11__ARID_DEF_arg->is_c90_ME11 = ME11_IN_wait_g;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     default:
      if (!rtu_AcPMPFaultFlg) {
        ME11__ARID_DEF_arg->is_c90_ME11 = ME11_IN_Normal_f;
        *rty_ACTCtl_bAcPMPFaultFlg = false;
      } else if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 100U) {
        ME11__ARID_DEF_arg->is_c90_ME11 = ME11_IN_Fault_a;
        *rty_ACTCtl_bAcPMPFaultFlg = true;
      }
      break;
    }
  }
}

void ME11_Delay1_Init(boolean *rty_C)
{
  *rty_C = false;
}

void ME11_Delay1(uint8 rtu_A, boolean *rty_C, ARID_DEF_Delay1_ME11_T
                 *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 63U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c164_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c164_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c164_ME11 = ME11_IN_Off_c;
    *rty_C = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c164_ME11) {
     case ME11_IN_Off_c:
      *rty_C = false;
      if (rtu_A >= 2) {
        ME11__ARID_DEF_arg->is_c164_ME11 = ME11_IN_On_k;
        *rty_C = true;
      }
      break;

     case ME11_IN_On_k:
      *rty_C = true;
      if (rtu_A <= 1) {
        ME11__ARID_DEF_arg->is_c164_ME11 = ME11_IN_Wait;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     default:
      if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 60U) {
        ME11__ARID_DEF_arg->is_c164_ME11 = ME11_IN_Off_c;
        *rty_C = false;
      } else if (rtu_A >= 2) {
        ME11__ARID_DEF_arg->is_c164_ME11 = ME11_IN_On_k;
        *rty_C = true;
      }
      break;
    }
  }
}

void ME11_TMSIODriverFunc(void)
{
  sint32 rtb_HVCHModeFlg;
  sint32 tmp;
  uint8 rtb_Switch3_jj_idx_0;
  uint8 rtb_Switch3_jj_idx_1;
  if (ME11_TMSIODriverFunc_ARID_DEF.is_active_c161_ME11 == 0U) {
    ME11_TMSIODriverFunc_ARID_DEF.is_active_c161_ME11 = 1U;
    ME11_TMSIODriverFunc_ARID_DEF.is_c161_ME11 = ME11_IN_Off_cr;
    rtb_HVCHModeFlg = 0;
  } else if (ME11_TMSIODriverFunc_ARID_DEF.is_c161_ME11 == ME11_IN_Off_cr) {
    rtb_HVCHModeFlg = 0;
    if (ME11_TMSIODriverFunc_ARID_DEF.Cnt >= cal_HVCHDriverTime) {
      ME11_TMSIODriverFunc_ARID_DEF.is_c161_ME11 = ME11_IN_On_lt;
      rtb_HVCHModeFlg = 1;
      ME11_TMSIODriverFunc_ARID_DEF.Cnt = 0U;
    } else {
      tmp = ME11_TMSIODriverFunc_ARID_DEF.Cnt + 1;
      if (ME11_TMSIODriverFunc_ARID_DEF.Cnt + 1 > 255) {
        tmp = 255;
      }

      ME11_TMSIODriverFunc_ARID_DEF.Cnt = (uint8)tmp;
    }
  } else {
    rtb_HVCHModeFlg = 1;
    if (ME11_TMSIODriverFunc_ARID_DEF.Cnt == 0) {
      ME11_TMSIODriverFunc_ARID_DEF.is_c161_ME11 = ME11_IN_Off_cr;
      rtb_HVCHModeFlg = 0;
    }
  }

  if (!cal_CallDrvierCtlSwitch) {
    rtb_HVCHModeFlg = 1;
  }

  if (rtb_HVCHModeFlg > 0) {
    rtb_Switch3_jj_idx_0 = ME11_ARID_DEF.p;
    rtb_Switch3_jj_idx_1 = ME11_ARID_DEF.n;
  } else {
    rtb_Switch3_jj_idx_0 = 0U;
    rtb_Switch3_jj_idx_1 = 0U;
  }

  if (cal_ModeMotorEnb) {
    rtb_Switch3_jj_idx_0 = cal_ModeMotorPData;
    rtb_Switch3_jj_idx_1 = cal_ModeMotorNData;
  }

  set_ModeMotor(rtb_Switch3_jj_idx_0, rtb_Switch3_jj_idx_1);
  if (rtb_HVCHModeFlg > 0) {
    rtb_Switch3_jj_idx_0 = ME11_ARID_DEF.p_n;
    rtb_Switch3_jj_idx_1 = ME11_ARID_DEF.n_d;
  } else {
    rtb_Switch3_jj_idx_0 = 0U;
    rtb_Switch3_jj_idx_1 = 0U;
  }

  if (cal_MixDoorEnb) {
    rtb_Switch3_jj_idx_0 = cal_MixDoorPData;
    rtb_Switch3_jj_idx_1 = cal_MixDoorNData;
  }

  set_MixDoor(rtb_Switch3_jj_idx_0, rtb_Switch3_jj_idx_1);
  if (rtb_HVCHModeFlg > 0) {
    rtb_Switch3_jj_idx_0 = ME11_ARID_DEF.p_c;
    rtb_Switch3_jj_idx_1 = ME11_ARID_DEF.n_h;
  } else {
    rtb_Switch3_jj_idx_0 = 0U;
    rtb_Switch3_jj_idx_1 = 0U;
  }

  if (cal_RecircMotorEnb) {
    rtb_Switch3_jj_idx_0 = cal_RecircMotorPData;
    rtb_Switch3_jj_idx_1 = cal_RecircMotorNData;
  }

  set_RecircMotor(rtb_Switch3_jj_idx_0, rtb_Switch3_jj_idx_1);
}

void ME11_Judge_Init(uint8 *rty_SenSts)
{
  *rty_SenSts = 0U;
}

void ME11_Judge(boolean rtu_MaxFlg, boolean rtu_MinFlg, uint8 rtu_timer, uint8
                *rty_SenSts, ARID_DEF_Judge_ME11_T *ME11__ARID_DEF_arg)
{
  sint32 tmp;
  if (ME11__ARID_DEF_arg->is_active_c2_ME11Lib == 0U) {
    ME11__ARID_DEF_arg->is_active_c2_ME11Lib = 1U;
    ME11__ARID_DEF_arg->is_c2_ME11Lib = ME11_IN_Init;
    *rty_SenSts = 0U;
    ME11__ARID_DEF_arg->T = 0U;
  } else {
    switch (ME11__ARID_DEF_arg->is_c2_ME11Lib) {
     case ME11_IN_Init:
      *rty_SenSts = 0U;
      if (rtu_MinFlg || rtu_MaxFlg) {
        ME11__ARID_DEF_arg->is_c2_ME11Lib = ME11_IN_judge;
        if (rtu_MinFlg) {
          ME11__ARID_DEF_arg->is_judge = ME11_IN_MinJudge;
          *rty_SenSts = 0U;
          tmp = ME11__ARID_DEF_arg->T + 1;
          if (ME11__ARID_DEF_arg->T + 1 > 255) {
            tmp = 255;
          }

          ME11__ARID_DEF_arg->T = (uint8)tmp;
        } else {
          ME11__ARID_DEF_arg->is_judge = ME11_IN_MaxJudge;
          *rty_SenSts = 0U;
          tmp = ME11__ARID_DEF_arg->T + 1;
          if (ME11__ARID_DEF_arg->T + 1 > 255) {
            tmp = 255;
          }

          ME11__ARID_DEF_arg->T = (uint8)tmp;
        }
      }
      break;

     case ME11_IN_judge:
      if ((!rtu_MinFlg) && (!rtu_MaxFlg)) {
        ME11__ARID_DEF_arg->is_judge = ME11_IN_NO_ACTIVE_CHILD_g;
        ME11__ARID_DEF_arg->is_c2_ME11Lib = ME11_IN_wait_go;
        tmp = ME11__ARID_DEF_arg->T + 1;
        if (ME11__ARID_DEF_arg->T + 1 > 255) {
          tmp = 255;
        }

        ME11__ARID_DEF_arg->T = (uint8)tmp;
      } else {
        switch (ME11__ARID_DEF_arg->is_judge) {
         case ME11_IN_MaxErr:
          *rty_SenSts = 2U;
          break;

         case ME11_IN_MaxJudge:
          *rty_SenSts = 0U;
          if (ME11__ARID_DEF_arg->T > rtu_timer) {
            ME11__ARID_DEF_arg->is_judge = ME11_IN_MaxErr;
            *rty_SenSts = 2U;
            ME11__ARID_DEF_arg->T = 0U;
          } else if (rtu_MinFlg) {
            ME11__ARID_DEF_arg->is_judge = ME11_IN_MinJudge;
            *rty_SenSts = 0U;
            ME11__ARID_DEF_arg->T = 1U;
          } else {
            tmp = ME11__ARID_DEF_arg->T + 1;
            if (ME11__ARID_DEF_arg->T + 1 > 255) {
              tmp = 255;
            }

            ME11__ARID_DEF_arg->T = (uint8)tmp;
          }
          break;

         case ME11_IN_MinErr:
          *rty_SenSts = 1U;
          break;

         default:
          *rty_SenSts = 0U;
          if (rtu_MaxFlg) {
            ME11__ARID_DEF_arg->is_judge = ME11_IN_MaxJudge;
            *rty_SenSts = 0U;
            ME11__ARID_DEF_arg->T = 1U;
          } else if (ME11__ARID_DEF_arg->T > rtu_timer) {
            ME11__ARID_DEF_arg->is_judge = ME11_IN_MinErr;
            *rty_SenSts = 1U;
            ME11__ARID_DEF_arg->T = 0U;
          } else {
            tmp = ME11__ARID_DEF_arg->T + 1;
            if (ME11__ARID_DEF_arg->T + 1 > 255) {
              tmp = 255;
            }

            ME11__ARID_DEF_arg->T = (uint8)tmp;
          }
          break;
        }
      }
      break;

     default:
      if (ME11__ARID_DEF_arg->T > rtu_timer) {
        ME11__ARID_DEF_arg->is_c2_ME11Lib = ME11_IN_Init;
        *rty_SenSts = 0U;
        ME11__ARID_DEF_arg->T = 0U;
      } else {
        tmp = ME11__ARID_DEF_arg->T + 1;
        if (ME11__ARID_DEF_arg->T + 1 > 255) {
          tmp = 255;
        }

        ME11__ARID_DEF_arg->T = (uint8)tmp;
      }
      break;
    }
  }
}

void ME11_TMSADCSampleFunc_Init(void)
{
  ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay2_DSTATE = 1U;
  ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay2_DSTATE_l = 1U;
  ME11_Judge_Init(&ME11_TMSADCSampleFunc_ARID_DEF.SenSts);
  ME11_Judge_Init(&ME11_TMSADCSampleFunc_ARID_DEF.SenSts_o);
  ME11_Judge_Init(&ME11_TMSADCSampleFunc_ARID_DEF.SenSts_l);
}

void ME11_TMSADCSampleFunc(void)
{
  float32 rtb_Add_kg;
  uint8 rtb_Compare_l5c;
  uint8 rtb_FixPtUnitDelay2_it;
  SENCtl_uRecircDoorVol = get_RecircValtage();
  rtb_Add_kg = (float32)((sint16)SENCtl_uRecircDoorVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uRecircDoorVol, (const uint16 *)
    &cal_RecircDoorVolAmend_1X[0], (const sint16 *)&cal_RecircDoorVolAmend_CUR[0],
    1U));
  Buffer_DcmDspData_F271H[0] = (uint8)(uint16)rtb_Add_kg;
  Buffer_DcmDspData_F271H[1] = (uint8)((uint32)(uint16)rtb_Add_kg >> 8);
  ME11_Judge(rtb_Add_kg > cal_SensorVolUpFlg, rtb_Add_kg < cal_SensorVolDownFlg,
             20, &ME11_TMSADCSampleFunc_ARID_DEF.SenSts,
             &ME11_TMSADCSampleFunc_ARID_DEF.ARID_DEF_Judge);
  ACSen_eRecircSenSts = ME11_TMSADCSampleFunc_ARID_DEF.SenSts;
  rtb_Compare_l5c = (uint8)(ACSen_eRecircSenSts == Ground);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943211), rtb_Compare_l5c);
  rtb_FixPtUnitDelay2_it = (uint8)(ACSen_eRecircSenSts == Power);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943215), rtb_FixPtUnitDelay2_it);
  ME11_TMSADCSampleFunc_ARID_DEF.Compare = (ACSen_eRecircSenSts != Normal);
  ME11_ARID_DEF.VectorConcatenate[26] = (rtb_Compare_l5c != 0);
  ME11_ARID_DEF.VectorConcatenate[27] = (rtb_FixPtUnitDelay2_it != 0);
  if (cal_AirInletPerEnb) {
    ACSen_eAirInletPer = cal_AirInletPerData;
  } else {
    ACSen_eAirInletPer = look1_iflftu8Df_binlca(0.001F * rtb_Add_kg, (const
      float32 *)&cal_RecirActVal_1X[0], (const uint8 *)&cal_RecirActVal_CUR[0],
      1U);
  }

  SENCtl_uMixDoorVol = get_MixDoorValtage();
  rtb_Add_kg = (float32)((sint16)SENCtl_uMixDoorVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uMixDoorVol, (const uint16 *)
    &cal_MixDoorVolAmend_1X[0], (const sint16 *)&cal_MixDoorVolAmend_CUR[0], 1U));
  Buffer_DcmDspData_F272H[0] = (uint8)(uint16)rtb_Add_kg;
  Buffer_DcmDspData_F272H[1] = (uint8)((uint32)(uint16)rtb_Add_kg >> 8);
  ME11_Judge(rtb_Add_kg > cal_SensorVolUpFlg, rtb_Add_kg < cal_SensorVolDownFlg,
             20, &ME11_TMSADCSampleFunc_ARID_DEF.SenSts_o,
             &ME11_TMSADCSampleFunc_ARID_DEF.ARID_DEF_Judge_c);
  ACSen_eMixDoorSenSts = ME11_TMSADCSampleFunc_ARID_DEF.SenSts_o;
  rtb_FixPtUnitDelay2_it = (uint8)(ACSen_eMixDoorSenSts == Ground);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943411), rtb_FixPtUnitDelay2_it);
  rtb_Compare_l5c = (uint8)(ACSen_eMixDoorSenSts == Power);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943415), rtb_Compare_l5c);
  ME11_TMSADCSampleFunc_ARID_DEF.Compare_a = (ACSen_eMixDoorSenSts != Normal);
  ME11_ARID_DEF.VectorConcatenate[32] = (rtb_FixPtUnitDelay2_it != 0);
  ME11_ARID_DEF.VectorConcatenate[33] = (rtb_Compare_l5c != 0);
  SEN_MixDoorRaw = look1_iflf_binlca(rtb_Add_kg, (const float32 *)
    &cal_MixDoorV_1X[0], (const float32 *)&cal_MixDoorPerc_CUR[0], 1U);
  if (ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay2_DSTATE != 0) {
    ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE = SEN_MixDoorRaw;
  }

  ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE = SEN_MixDoorRaw * 0.9F
    + ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE * 0.100000024F;
  if (cal_MixDoorPercDataEnb) {
    ACSen_sMixDoorPerc = cal_MixDoorPercData;
  } else {
    ACSen_sMixDoorPerc = ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE;
  }

  SENCtl_uModeDoorVol = get_ModeMotorValtage();
  rtb_Add_kg = (float32)((sint16)SENCtl_uModeDoorVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uModeDoorVol, (const uint16 *)
    &cal_ModeDoorVolAmend_1X[0], (const sint16 *)&cal_ModeDoorVolAmend_CUR[0],
    1U));
  Buffer_DcmDspData_F270H[0] = (uint8)(uint16)rtb_Add_kg;
  Buffer_DcmDspData_F270H[1] = (uint8)((uint32)(uint16)rtb_Add_kg >> 8);
  ME11_Judge(rtb_Add_kg > cal_SensorVolUpFlg, rtb_Add_kg < cal_SensorVolDownFlg,
             20, &ME11_TMSADCSampleFunc_ARID_DEF.SenSts_l,
             &ME11_TMSADCSampleFunc_ARID_DEF.ARID_DEF_Judge_m);
  ACSen_eModeSenSts = ME11_TMSADCSampleFunc_ARID_DEF.SenSts_l;
  rtb_FixPtUnitDelay2_it = (uint8)(ACSen_eModeSenSts == Ground);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943211), rtb_FixPtUnitDelay2_it);
  rtb_Compare_l5c = (uint8)(ACSen_eModeSenSts == Power);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943315), rtb_Compare_l5c);
  ME11_TMSADCSampleFunc_ARID_DEF.Compare_n = (ACSen_eModeSenSts != Normal);
  ME11_ARID_DEF.VectorConcatenate[29] = (rtb_FixPtUnitDelay2_it != 0);
  ME11_ARID_DEF.VectorConcatenate[30] = (rtb_Compare_l5c != 0);
  rtb_Add_kg *= 0.001F;
  if (ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay2_DSTATE_l != 0) {
    ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE_g = rtb_Add_kg;
  }

  ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE_g = rtb_Add_kg * 0.9F +
    ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE_g * 0.100000024F;
  if (cal_MotorModeEnb) {
    ACSen_sModeMotorVol = cal_MotorModeData;
  } else {
    ACSen_sModeMotorVol =
      ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay1_DSTATE_g;
  }

  ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay2_DSTATE = 0U;
  ME11_TMSADCSampleFunc_ARID_DEF.FixPtUnitDelay2_DSTATE_l = 0U;
}

void ME11_Delay_Init(boolean *rty_C)
{
  *rty_C = false;
}

void ME11_Delay(boolean rtu_A, boolean *rty_C, ARID_DEF_Delay_ME11_T
                *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 63U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c155_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c155_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c155_ME11 = ME11_IN_Off_e;
    *rty_C = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c155_ME11) {
     case ME11_IN_Off_e:
      *rty_C = false;
      if (rtu_A) {
        ME11__ARID_DEF_arg->is_c155_ME11 = ME11_IN_On_l;
        *rty_C = true;
      }
      break;

     case ME11_IN_On_l:
      *rty_C = true;
      if (!rtu_A) {
        ME11__ARID_DEF_arg->is_c155_ME11 = ME11_IN_Wait_b;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     default:
      if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 50U) {
        ME11__ARID_DEF_arg->is_c155_ME11 = ME11_IN_Off_e;
        *rty_C = false;
      } else if (rtu_A) {
        ME11__ARID_DEF_arg->is_c155_ME11 = ME11_IN_On_l;
        *rty_C = true;
      }
      break;
    }
  }
}

void ME11_Chart_a_Init(boolean *rty_B)
{
  *rty_B = false;
}

void ME11_Chart_p(boolean rtu_A, boolean *rty_B, ARID_DEF_Chart_ME11_k_T
                  *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 511U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c130_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c130_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c130_ME11 = ME11_IN_False;
    *rty_B = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c130_ME11) {
     case ME11_IN_False:
      *rty_B = false;
      if (rtu_A) {
        ME11__ARID_DEF_arg->is_c130_ME11 = ME11_IN_Wait_i;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     case ME11_IN_True:
      *rty_B = true;
      if (!rtu_A) {
        ME11__ARID_DEF_arg->is_c130_ME11 = ME11_IN_False;
        *rty_B = false;
      }
      break;

     default:
      if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 300U) {
        ME11__ARID_DEF_arg->is_c130_ME11 = ME11_IN_True;
        *rty_B = true;
      } else if (!rtu_A) {
        ME11__ARID_DEF_arg->is_c130_ME11 = ME11_IN_False;
        *rty_B = false;
      }
      break;
    }
  }
}

void ME11_Chart_l_Init(boolean *rty_B)
{
  *rty_B = false;
}

void ME11_Chart_e(boolean rtu_A, boolean *rty_B, ARID_DEF_Chart_ME11_m_T
                  *ME11__ARID_DEF_arg)
{
  if (ME11__ARID_DEF_arg->temporalCounter_i1 < 15U) {
    ME11__ARID_DEF_arg->temporalCounter_i1++;
  }

  if (ME11__ARID_DEF_arg->is_active_c135_ME11 == 0U) {
    ME11__ARID_DEF_arg->is_active_c135_ME11 = 1U;
    ME11__ARID_DEF_arg->is_c135_ME11 = ME11_IN_False_k;
    *rty_B = false;
  } else {
    switch (ME11__ARID_DEF_arg->is_c135_ME11) {
     case ME11_IN_False_k:
      *rty_B = false;
      if (rtu_A) {
        ME11__ARID_DEF_arg->is_c135_ME11 = ME11_IN_Wait_p;
        ME11__ARID_DEF_arg->temporalCounter_i1 = 0U;
      }
      break;

     case ME11_IN_True_a:
      *rty_B = true;
      if (!rtu_A) {
        ME11__ARID_DEF_arg->is_c135_ME11 = ME11_IN_False_k;
        *rty_B = false;
      }
      break;

     default:
      if (ME11__ARID_DEF_arg->temporalCounter_i1 >= 10U) {
        ME11__ARID_DEF_arg->is_c135_ME11 = ME11_IN_True_a;
        *rty_B = true;
      } else if (!rtu_A) {
        ME11__ARID_DEF_arg->is_c135_ME11 = ME11_IN_False_k;
        *rty_B = false;
      }
      break;
    }
  }
}

void ME11_enter_internal_ThermalCoordinate(void)
{
  if ((Rte_IRead_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
       ())->VIPM_BMSDCSActOprtMode_enum == 5) {
    ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_BTMS_QuickChargeThermal;
    PWRCtl_eBatChargSts = 2U;
  } else if
      (((Rte_IRead_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
         ())->VIPM_BMSACChrgAtclSta_enum != 1) &&
       ((Rte_IRead_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
         ())->VIPM_BMSDCSActOprtMode_enum != 5)) {
    ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_BTMS_NormalThermal;
    PWRCtl_eBatChargSts = 0U;
  } else if
      ((Rte_IRead_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
        ())->VIPM_BMSACChrgAtclSta_enum == 1) {
    ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_BTMS_SlowChargeThermal;
    PWRCtl_eBatChargSts = 1U;
  } else {
    ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_BTMS_Default;
    PWRCtl_eBatChargSts = 0U;
  }
}

void ME11_enter_internal_Sts(uint8 *PWRCtl_eTMSStatus_a)
{
  switch (PWRCtl_eBatChargSts) {
   case 2:
    ME11_ARID_DEF.is_Sts = ME11_IN_DCchg;
    *PWRCtl_eTMSStatus_a = 4U;
    break;

   case 1:
    ME11_ARID_DEF.is_Sts = ME11_IN_ACchg;
    *PWRCtl_eTMSStatus_a = 3U;
    break;

   default:
    if (PWRCtl_eVCUPTSts == 2) {
      ME11_ARID_DEF.is_Sts = ME11_IN_PTReady;
      *PWRCtl_eTMSStatus_a = 5U;
    } else if (PWRCtl_bKL15swtSt && ((PWRCtl_eVCUPTSts == 0) ||
                (PWRCtl_eVCUPTSts == 3)) && (PWRCtl_eBatChargSts == 0)) {
      ME11_ARID_DEF.is_Sts = ME11_IN_LowVoltage;
      *PWRCtl_eTMSStatus_a = 1U;
    } else if ((PWRCtl_eVCUPTSts == 1) && (PWRCtl_eBatChargSts == 0)) {
      ME11_ARID_DEF.is_Sts = ME11_IN_Dischg;
      *PWRCtl_eTMSStatus_a = 2U;
    } else {
      ME11_ARID_DEF.is_Sts = ME11_IN_Default_o;
      *PWRCtl_eTMSStatus_a = 0U;
    }
    break;
  }
}

void ME11_Cal(const boolean *FixPtRelationalOperator)
{
  sint32 tmp;
  uint8 tmp_0;
  switch (ME11_ARID_DEF.is_Cal) {
   case ME11_IN_Init_i:
    if ((ME11_ARID_DEF.sfEvent == -1) && (ME11_ARID_DEF.temporalCounter_i1_fs >=
         10)) {
      ME11_ARID_DEF.is_Cal = ME11_IN_Nml;
      ME11_ARID_DEF.is_Nml = ME11_IN_Nml_Init;
    } else {
      ME11_ARID_DEF.Fb = ME11_ARID_DEF.EERead_CabinSetTemp;
    }
    break;

   case ME11_IN_Max_d:
    if (*FixPtRelationalOperator) {
      ME11_ARID_DEF.is_Cal = ME11_IN_Nml;
      ME11_ARID_DEF.is_Nml = ME11_IN_Set;
      if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
        if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
          tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
        } else {
          tmp_0 = 0U;
        }
      } else {
        tmp_0 = MAX_uint8_T;
      }

      tmp = tmp_0 - 1;
      if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
        if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
          tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
        } else {
          tmp_0 = 0U;
        }
      } else {
        tmp_0 = MAX_uint8_T;
      }

      if (tmp_0 - 1 < 0) {
        tmp = 0;
      }

      ME11_ARID_DEF.Fb = (uint8)tmp;
    } else if (ME11_ARID_DEF.sfEvent == ME11_event_DecKey) {
      ME11_ARID_DEF.is_Cal = ME11_IN_Nml;
      ME11_ARID_DEF.is_Nml = ME11_IN_DecT;
      tmp = ME11_ARID_DEF.Fb - 1;
      if (ME11_ARID_DEF.Fb - 1 < 0) {
        tmp = 0;
      }

      ME11_ARID_DEF.Fb = (uint8)tmp;
    }
    break;

   case ME11_IN_Min_b:
    if (*FixPtRelationalOperator) {
      ME11_ARID_DEF.is_Cal = ME11_IN_Nml;
      ME11_ARID_DEF.is_Nml = ME11_IN_Set;
      if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
        if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
          tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
        } else {
          tmp_0 = 0U;
        }
      } else {
        tmp_0 = MAX_uint8_T;
      }

      tmp = tmp_0 - 1;
      if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
        if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
          tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
        } else {
          tmp_0 = 0U;
        }
      } else {
        tmp_0 = MAX_uint8_T;
      }

      if (tmp_0 - 1 < 0) {
        tmp = 0;
      }

      ME11_ARID_DEF.Fb = (uint8)tmp;
    } else if (ME11_ARID_DEF.sfEvent == ME11_event_AddKey) {
      ME11_ARID_DEF.is_Cal = ME11_IN_Nml;
      ME11_ARID_DEF.is_Nml = ME11_IN_AddT;
      tmp = ME11_ARID_DEF.Fb + 1;
      if (ME11_ARID_DEF.Fb + 1 > 255) {
        tmp = 255;
      }

      ME11_ARID_DEF.Fb = (uint8)tmp;
    }
    break;

   case ME11_IN_Nml:
    if (ME11_ARID_DEF.Fb >= 32) {
      ME11_ARID_DEF.is_Nml = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_Cal = ME11_IN_Max_d;
      ME11_ARID_DEF.Fb = 32U;
    } else if (ME11_ARID_DEF.Fb <= 0) {
      ME11_ARID_DEF.is_Nml = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_Cal = ME11_IN_Min_b;
    } else {
      switch (ME11_ARID_DEF.is_Nml) {
       case ME11_IN_AddT:
        if (*FixPtRelationalOperator) {
          ME11_ARID_DEF.is_Nml = ME11_IN_Set;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          tmp = tmp_0 - 1;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          if (tmp_0 - 1 < 0) {
            tmp = 0;
          }

          ME11_ARID_DEF.Fb = (uint8)tmp;
        } else {
          switch (ME11_ARID_DEF.sfEvent) {
           case ME11_event_AddKey:
            ME11_ARID_DEF.is_Nml = ME11_IN_AddT;
            ME11_ARID_DEF.Fb++;
            break;

           case ME11_event_DecKey:
            ME11_ARID_DEF.is_Nml = ME11_IN_DecT;
            ME11_ARID_DEF.Fb--;
            break;
          }
        }
        break;

       case ME11_IN_DecT:
        if (ME11_ARID_DEF.sfEvent == ME11_event_DecKey) {
          ME11_ARID_DEF.is_Nml = ME11_IN_DecT;
          ME11_ARID_DEF.Fb--;
        } else if (*FixPtRelationalOperator) {
          ME11_ARID_DEF.is_Nml = ME11_IN_Set;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          tmp = tmp_0 - 1;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          if (tmp_0 - 1 < 0) {
            tmp = 0;
          }

          ME11_ARID_DEF.Fb = (uint8)tmp;
        } else if (ME11_ARID_DEF.sfEvent == ME11_event_AddKey) {
          ME11_ARID_DEF.is_Nml = ME11_IN_AddT;
          ME11_ARID_DEF.Fb++;
        }
        break;

       case ME11_IN_Nml_Init:
        if (*FixPtRelationalOperator) {
          ME11_ARID_DEF.is_Nml = ME11_IN_Set;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          tmp = tmp_0 - 1;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          if (tmp_0 - 1 < 0) {
            tmp = 0;
          }

          ME11_ARID_DEF.Fb = (uint8)tmp;
        } else {
          switch (ME11_ARID_DEF.sfEvent) {
           case ME11_event_AddKey:
            ME11_ARID_DEF.is_Nml = ME11_IN_AddT;
            ME11_ARID_DEF.Fb++;
            break;

           case ME11_event_DecKey:
            ME11_ARID_DEF.is_Nml = ME11_IN_DecT;
            ME11_ARID_DEF.Fb--;
            break;
          }
        }
        break;

       case ME11_IN_Set:
        if (*FixPtRelationalOperator) {
          ME11_ARID_DEF.is_Nml = ME11_IN_Set;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          tmp = tmp_0 - 1;
          if (ME11_ARID_DEF.Delay_DSTATE_d < 256.0F) {
            if (ME11_ARID_DEF.Delay_DSTATE_d >= 0.0F) {
              tmp_0 = (uint8)ME11_ARID_DEF.Delay_DSTATE_d;
            } else {
              tmp_0 = 0U;
            }
          } else {
            tmp_0 = MAX_uint8_T;
          }

          if (tmp_0 - 1 < 0) {
            tmp = 0;
          }

          ME11_ARID_DEF.Fb = (uint8)tmp;
        } else {
          switch (ME11_ARID_DEF.sfEvent) {
           case ME11_event_AddKey:
            ME11_ARID_DEF.is_Nml = ME11_IN_AddT;
            ME11_ARID_DEF.Fb++;
            break;

           case ME11_event_DecKey:
            ME11_ARID_DEF.is_Nml = ME11_IN_DecT;
            ME11_ARID_DEF.Fb--;
            break;
          }
        }
        break;
      }
    }
    break;
  }
}

void ME11_enter_internal_Mode(void)
{
  boolean guard1 = false;
  guard1 = false;
  if (ME11_ARID_DEF.Delay_DSTATE_hx == 5) {
    guard1 = true;
  } else if (ME11_ARID_DEF.Delay_DSTATE_hx == 3) {
    ME11_ARID_DEF.is_Mode = ME11_IN_Defrost_Foot;
    ME11_ARID_DEF.mode = 3U;
  } else if (ME11_ARID_DEF.Delay_DSTATE_hx == 4) {
    ME11_ARID_DEF.is_Mode = ME11_IN_Face_Foot;
    ME11_ARID_DEF.mode = 4U;
  } else if (ME11_ARID_DEF.Delay_DSTATE_hx == 1) {
    ME11_ARID_DEF.is_Mode = ME11_IN_Defrost;
    ME11_ARID_DEF.mode = 1U;
  } else if (ME11_ARID_DEF.Delay_DSTATE_hx == 2) {
    ME11_ARID_DEF.is_Mode = ME11_IN_Foot;
    ME11_ARID_DEF.mode = 2U;
  } else {
    guard1 = true;
  }

  if (guard1) {
    ME11_ARID_DEF.is_Mode = ME11_IN_Face_l;
    ME11_ARID_DEF.mode = 5U;
  }
}

void ME11_sart(float64 v1, float64 v2, float64 *a, float64 *b)
{
  *a = v2;
  *b = v1;
}

void ME11_enter_internal_Choice(const uint8 *SOMCtl_eRefModes_b)
{
  boolean guard1 = false;
  guard1 = false;
  if (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
       (ME11_ARID_DEF.DataTypeConversion1 == 4)) && (*SOMCtl_eRefModes_b == 3))
  {
    guard1 = true;
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 4)) && (*SOMCtl_eRefModes_b ==
              2)) {
    ME11_ARID_DEF.is_Choice = ME11_IN_ChgBatCool;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = cal_COMPBatMaxSpdLmt;
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (*SOMCtl_eRefModes_b ==
              1) &&
             ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
               ())->VIPM_ESCVehSpd_kph > 20.0F)) {
    ME11_ARID_DEF.is_Choice = ME11_IN_NmlBatCool2;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = cal_COMPCabinCoolMaxSpdLmt;
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (*SOMCtl_eRefModes_b ==
              1) &&
             ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
               ())->VIPM_ESCVehSpd_kph <= 20.0F)) {
    ME11_ARID_DEF.is_Choice = ME11_IN_NmlBatCool1;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = ACTCtl_sCOMPFanlevelLmtSpd;
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (*SOMCtl_eRefModes_b ==
              2)) {
    ME11_ARID_DEF.is_Choice = ME11_IN_NmlBatCool;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = cal_COMPBatMaxSpdLmt;
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (*SOMCtl_eRefModes_b ==
              3) &&
             ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
               ())->VIPM_ESCVehSpd_kph > 20.0F)) {
    ME11_ARID_DEF.is_Choice = ME11_IN_NmlDCoolHVS;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = ACTCtl_sCOMPEnvLmtSpd;
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (*SOMCtl_eRefModes_b ==
              3) &&
             ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
               ())->VIPM_ESCVehSpd_kph <= 20.0F)) {
    ME11_ARID_DEF.is_Choice = ME11_IN_NmlDCoolLVS;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = ACTCtl_sCOMPFanlevelLmtSpd;
  } else {
    guard1 = true;
  }

  if (guard1) {
    ME11_ARID_DEF.is_Choice = ME11_IN_ChgDCool;
    ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd = ACTCtl_sCOMPEnvLmtSpd;
  }
}

void Task_100ms(void)
{
  boolean rtb_flag;
  boolean rtb_flg;
  boolean rtb_flg_d;
  boolean rtb_flg_g;
  boolean rtb_flg_o;
  boolean rtb_flag_l;
  boolean rtb_flg_dg;
  boolean rtb_flg_f;
  boolean rtb_flag_c;
  boolean rtb_flag_k;
  boolean rtb_flg_n;
  boolean rtb_flg_m;
  boolean rtb_ACTCtl_eCOMPFlg3Cal;
  boolean rtb_ACTCtl_eCOMPFlg3Cal_c;
  boolean rtb_flag_f;
  boolean rtb_flag_g;
  boolean rtb_flag_n;
  boolean rtb_flag_nk;
  boolean rtb_flag_d;
  boolean rtb_flag_a;
  boolean rtb_flag_g4;
  boolean rtb_flag_de;
  boolean rtb_flag_ko;
  TMS2VCU_AC_1_Command_Outputs rtb_BusCreator1;
  TMS2VCU_AC_2_State_Outputs rtb_BusCreator2;
  TMS2VCU_AC_3_State_Outputs rtb_BusCreator3;
  TMS2VCU_AC_8_status_Outputs rtb_BusCreator4;
  TMS2VCU_AC_ACStatuts_Outputs rtb_BusCreator5;
  TMS2VCU_AC_COMP_Outputs rtb_BusCreator6;
  TMS2VCU_HVCH_Command_Outputs rtb_BusCreator7;
  TMS2VCU_PPVAddSignalGroup_Outputs rtb_BusCreator11;
  TMS2VCU_TMS_LINTestData1_Outputs rtb_BusCreator8;
  TMS2VCU_TMS_LINTestData2_Outputs rtb_BusCreator9;
  TMS2VCU_TMS_LINTestData3_Outputs rtb_BusCreator10;
  Tms2Vcu_Info rtb_BusCreator;
  float64 a;
  float64 b;
  sint32 b_previousEvent;
  sint32 rtb_Relay_f;
  float32 rtb_Add;
  float32 rtb_Add_ax;
  float32 rtb_Add_cy;
  float32 rtb_DataTypeConversion23;
  float32 rtb_Delay1_ie;
  float32 rtb_Delay_ci;
  float32 rtb_Gain8;
  float32 rtb_LowPressLmt;
  float32 rtb_Merge;
  float32 rtb_Merge1;
  float32 rtb_Merge1_m;
  float32 rtb_Merge_g;
  float32 rtb_MultiportSwitch2_e;
  float32 rtb_PI_Cor_a;
  float32 rtb_PI_Cor_d;
  float32 rtb_Saturation_ou;
  float32 rtb_Switch4_a;
  uint32 rtb_Divide1_f;
  sint16 rtb_DataTypeConversion1_kh;
  sint16 rtb_DataTypeConversion2;
  sint16 rtb_DataTypeConversion3;
  sint16 rtb_DataTypeConversion4;
  sint16 rtb_DataTypeConversion_dt;
  uint16 rtb_Divide_ox;
  uint16 rtb_Gain1_j_0;
  uint16 rtb_Gain_az;
  ACEconMode rtb_DataTypeConversion_f;
  BlowerModes rtb_DataTypeConversion_jf;
  BlowerModes rtb_Delay_n2;
  FaultStatus rtb_Compare_dz_tmp_tmp;
  FaultStatus rtb_Compare_ecv_tmp_tmp;
  FaultStatus rtb_Compare_gt_tmp_tmp;
  FaultStatus rtb_Compare_jvo_tmp_tmp;
  FaultStatus rtb_Compare_oik_tmp_tmp;
  uint8 rtb_VectorConcatenate_dq[13];
  uint8 PWRCtl_eTMSStatus_a;
  uint8 rtb_Add2_j5;
  uint8 rtb_Add3_do;
  uint8 rtb_Add4_ox;
  uint8 rtb_Add5_d;
  uint8 rtb_Add6_d;
  uint8 rtb_Add7_i;
  uint8 rtb_Add_ge3;
  uint8 rtb_Compare;
  uint8 rtb_Compare_bxp;
  uint8 rtb_Compare_i1;
  uint8 rtb_Compare_ij;
  uint8 rtb_Compare_nw0;
  uint8 rtb_DataTypeConversion19;
  uint8 rtb_DataTypeConversion1_g;
  uint8 rtb_DataTypeConversion1_l;
  uint8 rtb_DataTypeConversion1_on;
  uint8 rtb_DataTypeConversion2_a;
  uint8 rtb_Delay1_i;
  uint8 rtb_Delay_ku;
  uint8 rtb_IFreezFlag;
  uint8 rtb_IFreezFlag_bd;
  uint8 rtb_IFreezFlag_c;
  uint8 rtb_IFreezFlag_d;
  uint8 rtb_IFreezFlag_jz;
  uint8 rtb_IFreezFlag_k;
  uint8 rtb_IFreezFlag_m;
  uint8 rtb_IFreezFlag_o;
  uint8 rtb_MultiportSwitch1;
  uint8 rtb_SOMCtl_WaterMode;
  uint8 rtb_Switch1_e3;
  uint8 rtb_Switch1_mn;
  uint8 rtb_Switch2_gua;
  uint8 rtb_Switch2_ht;
  uint8 u1;
  uint8 u1_0;
  uint8 u1_1;
  uint8 u1_2;
  boolean rtb_Compare_hdh[7];
  boolean rtb_Compare_mjv[6];
  boolean rtb_Compare_btd[5];
  boolean FixPtRelationalOperator;
  boolean guard1 = false;
  boolean guard2 = false;
  boolean rtb_ACTCtl_bEXVDiagFlg_0;
  boolean rtb_ACTCtl_bPMPDiagFlg;
  boolean rtb_AND1_c;
  boolean rtb_AND1_h0y;
  boolean rtb_AND1_hh;
  boolean rtb_AND4_f;
  boolean rtb_AND_hi;
  boolean rtb_Compare_bdq;
  boolean rtb_Compare_bu;
  boolean rtb_Compare_c;
  boolean rtb_Compare_cd_tmp;
  boolean rtb_Compare_cj1;
  boolean rtb_Compare_cls;
  boolean rtb_Compare_cvf;
  boolean rtb_Compare_cwj;
  boolean rtb_Compare_cz;
  boolean rtb_Compare_d0e;
  boolean rtb_Compare_dsx;
  boolean rtb_Compare_e5;
  boolean rtb_Compare_ej;
  boolean rtb_Compare_f2;
  boolean rtb_Compare_fe4;
  boolean rtb_Compare_fhh;
  boolean rtb_Compare_gzu;
  boolean rtb_Compare_h1;
  boolean rtb_Compare_ip;
  boolean rtb_Compare_j2e;
  boolean rtb_Compare_jac;
  boolean rtb_Compare_jkf;
  boolean rtb_Compare_jkh;
  boolean rtb_Compare_kq;
  boolean rtb_Compare_l;
  boolean rtb_Compare_l5;
  boolean rtb_Compare_lfo;
  boolean rtb_Compare_lwc;
  boolean rtb_Compare_ly;
  boolean rtb_Compare_mcu;
  boolean rtb_Compare_mdjr;
  boolean rtb_Compare_mos;
  boolean rtb_Compare_mwc;
  boolean rtb_Compare_ny;
  boolean rtb_Compare_nzl;
  boolean rtb_Compare_oc;
  boolean rtb_Compare_ppz;
  boolean rtb_Compare_pw;
  boolean rtb_Delay1_ag;
  boolean rtb_FixPtRelationalOperator_cd;
  boolean rtb_FixPtRelationalOperator_d5;
  boolean rtb_FixPtRelationalOperator_dx;
  boolean rtb_FixPtRelationalOperator_ex;
  boolean rtb_FixPtRelationalOperator_gf;
  boolean rtb_FixPtRelationalOperator_ka;
  boolean rtb_LogicalOperator1_f;
  boolean rtb_LogicalOperator5;
  boolean rtb_LogicalOperator_j0;
  boolean rtb_OR2_a;
  boolean rtb_OR_i4;
  boolean rtb_RelationalOperator3_d;
  boolean rtb_RelationalOperator_kh;
  boolean rtb_RelationalOperator_lt;
  boolean rtb_RelationalOperator_pl;
  boolean rtb_Switch_kl;
  boolean rtb_Switch_n2;
  GLB_ESC_VehicleSpeedValid =
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpdVld_flg;
  GLB_ESC_VehicleSpeed =
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpd_kph;
  COMP_Commu_Error = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPCommuError_flg;
  rtb_Compare_mos = COMP_Commu_Error;
  COMP_CANBusOff = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPCANBusOff_flg;
  rtb_Compare_cj1 = COMP_CANBusOff;
  COMP_LoseStep = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPLoseStep_flg;
  rtb_Compare_fhh = COMP_LoseStep;
  COMP_HvError = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPHvErr_enum;
  rtb_Compare_e5 = (COMP_HvError != 0);
  COMP_LvError = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPLvErr_enum;
  rtb_Compare_kq = (COMP_LvError != 0);
  COMP_TempError = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPTempErr_flg;
  rtb_Compare_lfo = COMP_TempError;
  HU_LeftTempSet = (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
    ->VIPM_HULeftTempSet_enum;
  rtb_Compare_bxp = GetHw_KL15A();
  rtb_Compare_i1 = GetHw_KL15B();
  PWRCtl_bKL15swtSt = ((rtb_Compare_bxp != 0) || (rtb_Compare_i1 != 0));
  PWRCtl_eVCUPTSts = (Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs
                      ())->VHVM_PTActOprtMode_enum;
  if (ME11_ARID_DEF.is_active_c58_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c58_ME11 = 1U;
    ME11_enter_internal_ThermalCoordinate();
  } else {
    switch (ME11_ARID_DEF.is_ThermalCoordinate) {
     case ME11_IN_BTMS_Default:
      PWRCtl_eBatChargSts = 0U;
      ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_ThermalCoordinate();
      break;

     case ME11_IN_BTMS_NormalThermal:
      PWRCtl_eBatChargSts = 0U;
      ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_ThermalCoordinate();
      break;

     case ME11_IN_BTMS_QuickChargeThermal:
      PWRCtl_eBatChargSts = 2U;
      ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_ThermalCoordinate();
      break;

     default:
      PWRCtl_eBatChargSts = 1U;
      ME11_ARID_DEF.is_ThermalCoordinate = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_ThermalCoordinate();
      break;
    }
  }

  if (ME11_ARID_DEF.is_active_c7_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c7_ME11 = 1U;
    ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
  } else {
    switch (ME11_ARID_DEF.is_Sts) {
     case ME11_IN_ACchg:
      PWRCtl_eTMSStatus_a = 3U;
      ME11_ARID_DEF.is_Sts = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
      break;

     case ME11_IN_DCchg:
      PWRCtl_eTMSStatus_a = 4U;
      ME11_ARID_DEF.is_Sts = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
      break;

     case ME11_IN_Default_o:
      PWRCtl_eTMSStatus_a = 0U;
      ME11_ARID_DEF.is_Sts = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
      break;

     case ME11_IN_Dischg:
      PWRCtl_eTMSStatus_a = 2U;
      ME11_ARID_DEF.is_Sts = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
      break;

     case ME11_IN_LowVoltage:
      PWRCtl_eTMSStatus_a = 1U;
      ME11_ARID_DEF.is_Sts = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
      break;

     default:
      PWRCtl_eTMSStatus_a = 5U;
      ME11_ARID_DEF.is_Sts = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Sts(&PWRCtl_eTMSStatus_a);
      break;
    }
  }

  if (cal_TMSStatusEnb > 0) {
    PWRCtl_eTMSStatus = cal_TMSStatusData;
  } else {
    PWRCtl_eTMSStatus = PWRCtl_eTMSStatus_a;
  }

  ME11_ARID_DEF.DataTypeConversion1 = PWRCtl_eTMSStatus;
  if ((ME11_ARID_DEF.DataTypeConversion1 >= 2) && PWRCtl_bKL15swtSt) {
    ME11_ARID_DEF.HMI_MODE = true;
    rtb_FixPtRelationalOperator_dx =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_TBOXACTempSet_enum != ME11_ARID_DEF.DelayInput1_DSTATE_f);
    rtb_FixPtRelationalOperator_cd =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_TBOXACTempSet_enum != 0);
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.Delay2_DSTATE_nm;
    if (rtb_FixPtRelationalOperator_dx && rtb_FixPtRelationalOperator_cd) {
      ME11_ARID_DEF.Delay2_DSTATE_nm =
        (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
        ->VIPM_TBOXACTempSet_enum;
    }

    rtb_FixPtRelationalOperator_dx =
      ((Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs())
       ->VTBX_VCURmtACCtrlSt_enum == 1);
    if (cal_RemtACDefEnbData) {
      RMTCtl_bRemtACFlg = cal_RemtACDefEnbData;
    } else {
      rtb_Compare_ly =
        (Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs())
        ->VTBX_VCURmtACCtrlReq_flg;
      RMTCtl_bRemtACFlg = (rtb_Compare_ly && rtb_FixPtRelationalOperator_dx);
    }

    rtb_Compare_ly = ME11_ARID_DEF.Delay3_DSTATE_kci;
    rtb_AND_hi = ((HU_LeftTempSet != ME11_ARID_DEF.DelayInput1_DSTATE_d1) &&
                  (HU_LeftTempSet != 0));
    if (rtb_AND_hi) {
      ME11_ARID_DEF.Delay_DSTATE_d = HU_LeftTempSet;
    }

    FixPtRelationalOperator = (rtb_AND_hi != ME11_ARID_DEF.DelayInput1_DSTATE_kr);
    if (ME11_ARID_DEF.temporalCounter_i5 < 7U) {
      ME11_ARID_DEF.temporalCounter_i5++;
    }

    if (ME11_ARID_DEF.temporalCounter_i6 < 7U) {
      ME11_ARID_DEF.temporalCounter_i6++;
    }

    ME11_ARID_DEF.sfEvent = -1;
    if (ME11_ARID_DEF.temporalCounter_i1_fs < 15U) {
      ME11_ARID_DEF.temporalCounter_i1_fs++;
    }

    if (ME11_ARID_DEF.temporalCounter_i2_fk < 7U) {
      ME11_ARID_DEF.temporalCounter_i2_fk++;
    }

    if (ME11_ARID_DEF.temporalCounter_i3 < 7U) {
      ME11_ARID_DEF.temporalCounter_i3++;
    }

    if (ME11_ARID_DEF.temporalCounter_i4 < 3U) {
      ME11_ARID_DEF.temporalCounter_i4++;
    }

    if (ME11_ARID_DEF.is_active_c56_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c56_ME11 = 1U;
      ME11_ARID_DEF.is_active_Cal = 1U;
      ME11_ARID_DEF.is_Cal = ME11_IN_Init_i;
      ME11_ARID_DEF.temporalCounter_i1_fs = 0U;
      ME11_ARID_DEF.Fb = ME11_ARID_DEF.EERead_CabinSetTemp;
      ME11_ARID_DEF.is_active_Add = 1U;
      ME11_ARID_DEF.is_Add = ME11_IN_Init_o;
      ME11_ARID_DEF.temporalCounter_i2_fk = 0U;
      ME11_ARID_DEF.is_active_Dec = 1U;
      ME11_ARID_DEF.is_Dec = ME11_IN_Init_o;
      ME11_ARID_DEF.temporalCounter_i3 = 0U;
      ME11_ARID_DEF.is_active_ChgJudge = 1U;
      ME11_ARID_DEF.is_ChgJudge = ME11_IN_Chg_Off;
      ME11_ARID_DEF.HMICtl_bChgFlg = false;
    } else {
      if (ME11_ARID_DEF.is_active_Cal != 0U) {
        ME11_Cal(&FixPtRelationalOperator);
      }

      if (ME11_ARID_DEF.is_active_Add != 0U) {
        switch (ME11_ARID_DEF.is_Add) {
         case ME11_IN_Add:
          if (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                ())->VIPM_CCPTempAddKey_flg) {
            ME11_ARID_DEF.is_Add = ME11_IN_Init_o;
            ME11_ARID_DEF.temporalCounter_i2_fk = 0U;
          } else {
            ME11_ARID_DEF.is_Add = ME11_IN_Wait_c;
            ME11_ARID_DEF.temporalCounter_i5 = 0U;
          }
          break;

         case ME11_IN_Init_o:
          if ((ME11_ARID_DEF.sfEvent == -1) &&
              (ME11_ARID_DEF.temporalCounter_i2_fk >= 4) &&
              (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
               ())->VIPM_CCPTempAddKey_flg) {
            ME11_ARID_DEF.is_Add = ME11_IN_NO_ACTIVE_CHILD_gl;
            b_previousEvent = ME11_ARID_DEF.sfEvent;
            ME11_ARID_DEF.sfEvent = ME11_event_AddKey;
            if (ME11_ARID_DEF.is_active_Cal != 0U) {
              ME11_Cal(&FixPtRelationalOperator);
            }

            ME11_ARID_DEF.sfEvent = b_previousEvent;
            ME11_ARID_DEF.is_Add = ME11_IN_Wait_c;
            ME11_ARID_DEF.temporalCounter_i5 = 0U;
          }
          break;

         case ME11_IN_Wait_c:
          if (ME11_ARID_DEF.temporalCounter_i5 >= 5U) {
            ME11_ARID_DEF.is_Add = ME11_IN_Add;
            b_previousEvent = ME11_ARID_DEF.sfEvent;
            ME11_ARID_DEF.sfEvent = ME11_event_AddKey;
            if (ME11_ARID_DEF.is_active_Cal != 0U) {
              ME11_Cal(&FixPtRelationalOperator);
            }

            ME11_ARID_DEF.sfEvent = b_previousEvent;
          } else if
              (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                 ())->VIPM_CCPTempAddKey_flg) {
            ME11_ARID_DEF.is_Add = ME11_IN_Init_o;
            ME11_ARID_DEF.temporalCounter_i2_fk = 0U;
          }
          break;
        }
      }

      if (ME11_ARID_DEF.is_active_Dec != 0U) {
        switch (ME11_ARID_DEF.is_Dec) {
         case ME11_IN_Add:
          if (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                ())->VIPM_CCPTempDecKey_flg) {
            ME11_ARID_DEF.is_Dec = ME11_IN_Init_o;
            ME11_ARID_DEF.temporalCounter_i3 = 0U;
          } else {
            ME11_ARID_DEF.is_Dec = ME11_IN_Wait_c;
            ME11_ARID_DEF.temporalCounter_i6 = 0U;
          }
          break;

         case ME11_IN_Init_o:
          if ((ME11_ARID_DEF.sfEvent == -1) && (ME11_ARID_DEF.temporalCounter_i3
               >= 4) &&
              (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
               ())->VIPM_CCPTempDecKey_flg) {
            ME11_ARID_DEF.is_Dec = ME11_IN_NO_ACTIVE_CHILD_gl;
            b_previousEvent = ME11_ARID_DEF.sfEvent;
            ME11_ARID_DEF.sfEvent = ME11_event_DecKey;
            if (ME11_ARID_DEF.is_active_Cal != 0U) {
              ME11_Cal(&FixPtRelationalOperator);
            }

            ME11_ARID_DEF.sfEvent = b_previousEvent;
            ME11_ARID_DEF.is_Dec = ME11_IN_Wait_c;
            ME11_ARID_DEF.temporalCounter_i6 = 0U;
          }
          break;

         case ME11_IN_Wait_c:
          if (ME11_ARID_DEF.temporalCounter_i6 >= 5U) {
            ME11_ARID_DEF.is_Dec = ME11_IN_Add;
            b_previousEvent = ME11_ARID_DEF.sfEvent;
            ME11_ARID_DEF.sfEvent = ME11_event_DecKey;
            if (ME11_ARID_DEF.is_active_Cal != 0U) {
              ME11_Cal(&FixPtRelationalOperator);
            }

            ME11_ARID_DEF.sfEvent = b_previousEvent;
          } else if
              (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                 ())->VIPM_CCPTempDecKey_flg) {
            ME11_ARID_DEF.is_Dec = ME11_IN_Init_o;
            ME11_ARID_DEF.temporalCounter_i3 = 0U;
          }
          break;
        }
      }

      if (ME11_ARID_DEF.is_active_ChgJudge != 0U) {
        switch (ME11_ARID_DEF.is_ChgJudge) {
         case ME11_IN_Chg_Off:
          ME11_ARID_DEF.HMICtl_bChgFlg = false;
          if (FixPtRelationalOperator || (ME11_ARID_DEF.sfEvent ==
               ME11_event_AddKey) || (ME11_ARID_DEF.sfEvent == ME11_event_DecKey))
          {
            ME11_ARID_DEF.is_ChgJudge = ME11_IN_Chg_On;
            ME11_ARID_DEF.temporalCounter_i4 = 0U;
            ME11_ARID_DEF.HMICtl_bChgFlg = true;
          }
          break;

         case ME11_IN_Chg_On:
          ME11_ARID_DEF.HMICtl_bChgFlg = true;
          if ((ME11_ARID_DEF.sfEvent == -1) && (ME11_ARID_DEF.temporalCounter_i4
               >= 2)) {
            ME11_ARID_DEF.is_ChgJudge = ME11_IN_Chg_Off;
            ME11_ARID_DEF.HMICtl_bChgFlg = false;
          }
          break;
        }
      }
    }

    if (RMTCtl_bRemtACFlg) {
      ME11_ARID_DEF.Delay1_DSTATE_fq = ME11_ARID_DEF.Delay2_DSTATE_nm;
    } else if ((sint32)ME11_ARID_DEF.Delay3_DSTATE_kci > (sint32)
               ME11_ARID_DEF.DelayInput1_DSTATE_jg) {
      ME11_ARID_DEF.Delay1_DSTATE_fq = 32U;
    } else if ((ME11_ARID_DEF.Fb != ME11_ARID_DEF.DelayInput1_DSTATE_gt) ||
               ME11_ARID_DEF.HMICtl_bChgFlg || ((sint32)
                ME11_ARID_DEF.Delay3_DSTATE_kci < (sint32)
                ME11_ARID_DEF.DelayInput1_DSTATE_f0)) {
      ME11_ARID_DEF.Delay1_DSTATE_fq = ME11_ARID_DEF.Fb;
    }

    if (cal_tLeftSetPointEnb) {
      HMICtl_sLeftSetPoint = cal_tLeftSetPointData;
    } else {
      HMICtl_sLeftSetPoint = 0.5F * (float32)ME11_ARID_DEF.Delay1_DSTATE_fq +
        16.0F;
    }

    rtb_Divide_ox = (uint16)(10.0F * HMICtl_sLeftSetPoint);
    Buffer_DcmDspData_F26CH[0] = (uint8)rtb_Divide_ox;
    Buffer_DcmDspData_F26CH[1] = (uint8)((uint32)rtb_Divide_ox >> 8);
    if (cal_RemtACEnb) {
      RMTCtl_bRemtACDefFlg = cal_RemtACEnbData;
    } else {
      FixPtRelationalOperator =
        (Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs())
        ->VTBX_VCURmtACDefrstReq_flg;
      RMTCtl_bRemtACDefFlg = (rtb_FixPtRelationalOperator_dx &&
        FixPtRelationalOperator);
    }

    PWRCtl_eTMSStatus_a = HMICtl_eACSts;
    rtb_Delay1_ie = ME11_ARID_DEF.Delay1_DSTATE_d;
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.DelayInput1_DSTATE_di;
    rtb_FixPtRelationalOperator_cd =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_HUFrntFanSpdSet_enum > ME11_ARID_DEF.DelayInput1_DSTATE_f);
    rtb_FixPtRelationalOperator_dx = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPBlwrLvlAddKey_flg > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_hg);
    ME11_ARID_DEF.DelayInput1_DSTATE_bx = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPBlwrLvlDecKey_flg > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_bx);
    rtb_AND1_hh = (rtb_FixPtRelationalOperator_cd ||
                   rtb_FixPtRelationalOperator_dx ||
                   ME11_ARID_DEF.DelayInput1_DSTATE_bx);
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.DelayInput1_DSTATE_iv;
    ME11_ARID_DEF.DelayInput1_DSTATE_bx =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_HUAirInletModeSet_enum > ME11_ARID_DEF.DelayInput1_DSTATE_f);
    rtb_FixPtRelationalOperator_ka = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPAirInletModeKey_flg > (sint32)
      ME11_ARID_DEF.DelayInput1_DSTATE_br);
    rtb_FixPtRelationalOperator_dx = (ME11_ARID_DEF.DelayInput1_DSTATE_bx ||
      rtb_FixPtRelationalOperator_ka);
    FixPtRelationalOperator = ME11_ARID_DEF.Delay_DSTATE_by;
    rtb_Delay1_ag = ME11_ARID_DEF.Delay1_DSTATE_c1;
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.DelayInput1_DSTATE_op;
    ME11_ARID_DEF.DelayInput1_DSTATE_bx =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_HUBlwrModeSet_enum != ME11_ARID_DEF.DelayInput1_DSTATE_f);
    rtb_FixPtRelationalOperator_cd =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_HUBlwrModeSet_enum != 0);
    ME11_ARID_DEF.DelayInput1_DSTATE_bx = (ME11_ARID_DEF.DelayInput1_DSTATE_bx &&
      rtb_FixPtRelationalOperator_cd);
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.Delay_DSTATE_hx;
    if (ME11_ARID_DEF.DelayInput1_DSTATE_bx) {
      ME11_ARID_DEF.Delay_DSTATE_hx =
        (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
        ->VIPM_HUBlwrModeSet_enum;
    }

    if (ME11_ARID_DEF.is_active_c60_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c60_ME11 = 1U;
      ME11_enter_internal_Mode();
    } else {
      switch (ME11_ARID_DEF.is_Mode) {
       case ME11_IN_Defrost:
        ME11_ARID_DEF.mode = 1U;
        ME11_ARID_DEF.is_Mode = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_enter_internal_Mode();
        break;

       case ME11_IN_Defrost_Foot:
        ME11_ARID_DEF.mode = 3U;
        ME11_ARID_DEF.is_Mode = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_enter_internal_Mode();
        break;

       case ME11_IN_Face_l:
        ME11_ARID_DEF.mode = 5U;
        ME11_ARID_DEF.is_Mode = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_enter_internal_Mode();
        break;

       case ME11_IN_Face_Foot:
        ME11_ARID_DEF.mode = 4U;
        ME11_ARID_DEF.is_Mode = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_enter_internal_Mode();
        break;

       default:
        ME11_ARID_DEF.mode = 2U;
        ME11_ARID_DEF.is_Mode = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_enter_internal_Mode();
        break;
      }
    }

    if (ME11_ARID_DEF.EERead_CabinModeDoor > 5) {
      rtb_Switch2_ht = 5U;
    } else if (ME11_ARID_DEF.EERead_CabinModeDoor < 1) {
      rtb_Switch2_ht = 1U;
    } else {
      rtb_Switch2_ht = ME11_ARID_DEF.EERead_CabinModeDoor;
    }

    if (ME11_ARID_DEF.temporalCounter_i2_kn < 15U) {
      ME11_ARID_DEF.temporalCounter_i2_kn++;
    }

    if (ME11_ARID_DEF.temporalCounter_i1_fj < 15U) {
      ME11_ARID_DEF.temporalCounter_i1_fj++;
    }

    if (ME11_ARID_DEF.is_active_c99_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c99_ME11 = 1U;
      ME11_ARID_DEF.is_c99_ME11 = ME11_IN_Init_i;
      ME11_ARID_DEF.temporalCounter_i1_fj = 0U;
      ME11_ARID_DEF.setMode = rtb_Switch2_ht;
    } else {
      switch (ME11_ARID_DEF.is_c99_ME11) {
       case ME11_IN_Init_i:
        if (ME11_ARID_DEF.temporalCounter_i1_fj >= 10) {
          ME11_ARID_DEF.is_c99_ME11 = ME11_IN_Normal_l;
          ME11_ARID_DEF.is_Normal = ME11_IN_Init_n;
          ME11_ARID_DEF.setMode = ME11_ARID_DEF.Delay1_DSTATE_es;
        } else {
          ME11_ARID_DEF.setMode = rtb_Switch2_ht;
        }
        break;

       case ME11_IN_Max_d:
        if (ME11_ARID_DEF.temporalCounter_i2_kn >= 10U) {
          ME11_ARID_DEF.is_c99_ME11 = ME11_IN_wait_Max;
        } else {
          ME11_ARID_DEF.setMode = 1U;
        }
        break;

       case ME11_IN_Min_b:
        if (ME11_ARID_DEF.temporalCounter_i2_kn >= 10U) {
          ME11_ARID_DEF.is_c99_ME11 = ME11_IN_wait_Min;
        } else {
          ME11_ARID_DEF.setMode = 5U;
        }
        break;

       case ME11_IN_Normal_l:
        if (ME11_ARID_DEF.setMode >= 6) {
          ME11_ARID_DEF.is_Add_p = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Dec_j = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Normal = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_c99_ME11 = ME11_IN_Max_d;
          ME11_ARID_DEF.temporalCounter_i2_kn = 0U;
          ME11_ARID_DEF.setMode = 1U;
        } else if (ME11_ARID_DEF.setMode <= 0) {
          ME11_ARID_DEF.is_Add_p = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Dec_j = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Normal = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_c99_ME11 = ME11_IN_Min_b;
          ME11_ARID_DEF.temporalCounter_i2_kn = 0U;
          ME11_ARID_DEF.setMode = 5U;
        } else {
          switch (ME11_ARID_DEF.is_Normal) {
           case ME11_IN_Add:
            if (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwngModeNextKey_flg) {
              ME11_ARID_DEF.is_Add_p = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_Normal = ME11_IN_Init_n;
              ME11_ARID_DEF.setMode = ME11_ARID_DEF.Delay1_DSTATE_es;
            } else if (ME11_ARID_DEF.is_Add_p == ME11_IN_One_l) {
              if (ME11_ARID_DEF.temporalCounter_i2_kn >= 10U) {
                ME11_ARID_DEF.is_Add_p = ME11_IN_wait_d;
              }
            } else if
                ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwngModeNextKey_flg) {
              ME11_ARID_DEF.is_Add_p = ME11_IN_One_l;
              ME11_ARID_DEF.temporalCounter_i2_kn = 0U;
              b_previousEvent = ME11_ARID_DEF.setMode + 1;
              if (ME11_ARID_DEF.setMode + 1 > 255) {
                b_previousEvent = 255;
              }

              ME11_ARID_DEF.setMode = (uint8)b_previousEvent;
            }
            break;

           case ME11_IN_Dec_d:
            if (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwngModePrevKey_flg) {
              ME11_ARID_DEF.is_Dec_j = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_Normal = ME11_IN_Init_n;
              ME11_ARID_DEF.setMode = ME11_ARID_DEF.Delay1_DSTATE_es;
            } else if (ME11_ARID_DEF.is_Dec_j == ME11_IN_Two_h) {
              if (ME11_ARID_DEF.temporalCounter_i2_kn >= 10U) {
                ME11_ARID_DEF.is_Dec_j = ME11_IN_wait_d;
              }
            } else if
                ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwngModePrevKey_flg) {
              ME11_ARID_DEF.is_Dec_j = ME11_IN_Two_h;
              ME11_ARID_DEF.temporalCounter_i2_kn = 0U;
              b_previousEvent = ME11_ARID_DEF.setMode - 1;
              if (ME11_ARID_DEF.setMode - 1 < 0) {
                b_previousEvent = 0;
              }

              ME11_ARID_DEF.setMode = (uint8)b_previousEvent;
            }
            break;

           default:
            if ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                 ())->VIPM_CCPBlwngModeNextKey_flg) {
              ME11_ARID_DEF.is_Normal = ME11_IN_Add;
              ME11_ARID_DEF.is_Add_p = ME11_IN_One_l;
              ME11_ARID_DEF.temporalCounter_i2_kn = 0U;
              b_previousEvent = ME11_ARID_DEF.setMode + 1;
              if (ME11_ARID_DEF.setMode + 1 > 255) {
                b_previousEvent = 255;
              }

              ME11_ARID_DEF.setMode = (uint8)b_previousEvent;
            } else if
                ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwngModePrevKey_flg) {
              ME11_ARID_DEF.is_Normal = ME11_IN_Dec_d;
              ME11_ARID_DEF.is_Dec_j = ME11_IN_Two_h;
              ME11_ARID_DEF.temporalCounter_i2_kn = 0U;
              b_previousEvent = ME11_ARID_DEF.setMode - 1;
              if (ME11_ARID_DEF.setMode - 1 < 0) {
                b_previousEvent = 0;
              }

              ME11_ARID_DEF.setMode = (uint8)b_previousEvent;
            } else {
              ME11_ARID_DEF.setMode = ME11_ARID_DEF.Delay1_DSTATE_es;
            }
            break;
          }
        }
        break;

       case ME11_IN_wait_Max:
        ME11_ARID_DEF.is_c99_ME11 = ME11_IN_Normal_l;
        ME11_ARID_DEF.is_Normal = ME11_IN_Init_n;
        ME11_ARID_DEF.setMode = ME11_ARID_DEF.Delay1_DSTATE_es;
        break;

       default:
        ME11_ARID_DEF.is_c99_ME11 = ME11_IN_Normal_l;
        ME11_ARID_DEF.is_Normal = ME11_IN_Init_n;
        ME11_ARID_DEF.setMode = ME11_ARID_DEF.Delay1_DSTATE_es;
        break;
      }
    }

    if (ME11_ARID_DEF.DelayInput1_DSTATE_bx) {
      ME11_ARID_DEF.Delay1_DSTATE_es = ME11_ARID_DEF.mode;
    } else {
      ME11_ARID_DEF.Delay1_DSTATE_es = ME11_ARID_DEF.setMode;
    }

    if (ME11_ARID_DEF.Delay1_DSTATE_es > 5) {
      ME11_ARID_DEF.Delay1_DSTATE_es = 5U;
    } else if (ME11_ARID_DEF.Delay1_DSTATE_es < 1) {
      ME11_ARID_DEF.Delay1_DSTATE_es = 1U;
    }

    if (cal_eModeMotorEnb) {
      HMICtl_eModeMotor = cal_eModeMotorData;
    } else {
      HMICtl_eModeMotor = ME11_ARID_DEF.Delay1_DSTATE_es;
    }

    if (((HMICtl_eACSts != ME11_ARID_DEF.DelayInput1_DSTATE_l) && (HMICtl_eACSts
          == 3)) || (rtb_Delay1_ie < ME11_ARID_DEF.DelayInput1_DSTATE_or) ||
        rtb_AND1_hh || (rtb_FixPtRelationalOperator_dx !=
                        ME11_ARID_DEF.DelayInput1_DSTATE_jx) || ((sint32)
         FixPtRelationalOperator < (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_c) ||
        ((sint32)ME11_ARID_DEF.Delay1_DSTATE_c1 > (sint32)
         ME11_ARID_DEF.DelayInput1_DSTATE_fq) || ((HMICtl_eModeMotor !=
          ME11_ARID_DEF.DelayInput1_DSTATE_gr) && (HMICtl_eModeMotor != 1))) {
      ME11_ARID_DEF.Delay_DSTATE_hv = false;
    } else {
      rtb_FixPtRelationalOperator_gf =
        ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
         ->VIPM_HUManlDefrstCtl_enum != ME11_ARID_DEF.DelayInput1_DSTATE_ov);
      rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                          ->VIPM_HUManlDefrstCtl_enum == 2);
      if (rtb_Compare_mdjr && rtb_FixPtRelationalOperator_gf) {
        ME11_ARID_DEF.Delay_DSTATE_hv = true;
      } else {
        rtb_FixPtRelationalOperator_gf =
          ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
           ->VIPM_HUManlDefrstCtl_enum != ME11_ARID_DEF.DelayInput1_DSTATE_ie);
        rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                            ->VIPM_HUManlDefrstCtl_enum == 1);
        if (rtb_Compare_mdjr && rtb_FixPtRelationalOperator_gf) {
          ME11_ARID_DEF.Delay_DSTATE_hv = false;
        } else {
          rtb_FixPtRelationalOperator_gf = ((sint32)
            (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
             ())->VIPM_CCPFrntWindDefrstKey_flg > (sint32)
            ME11_ARID_DEF.DelayInput1_DSTATE_jd);
          if (rtb_FixPtRelationalOperator_gf) {
            ME11_ARID_DEF.Delay_DSTATE_hv = !ME11_ARID_DEF.Delay_DSTATE_hv;
          }
        }
      }
    }

    if (cal_bACDefrostEnb) {
      HMICtl_bACDefrost = cal_bACDefrostData;
    } else if (RMTCtl_bRemtACDefFlg) {
      HMICtl_bACDefrost = true;
    } else {
      HMICtl_bACDefrost = (PWRCtl_bKL15swtSt && ME11_ARID_DEF.Delay_DSTATE_hv);
    }

    ME11_ARID_DEF.DelayInput1_DSTATE_bx = ME11_ARID_DEF.DelayInput1_DSTATE_os;
    rtb_FixPtRelationalOperator_gf = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPModeKey_flg > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_bx);
    if (ME11_ARID_DEF.temporalCounter_i1_b < 15U) {
      ME11_ARID_DEF.temporalCounter_i1_b++;
    }

    if (ME11_ARID_DEF.is_active_c100_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c100_ME11 = 1U;
      ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Init_n;
      ME11_ARID_DEF.temporalCounter_i1_b = 0U;
      ME11_ARID_DEF.Mode = ME11_ARID_DEF.EERead_CabinMode;
    } else {
      switch (ME11_ARID_DEF.is_c100_ME11) {
       case ME11_IN_Active:
        if (ME11_ARID_DEF.Mode > 3) {
          ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Max_n;
          ME11_ARID_DEF.temporalCounter_i1_b = 0U;
          ME11_ARID_DEF.Mode = 1U;
        } else if (rtb_FixPtRelationalOperator_gf) {
          ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Active;
          b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_cf + 1;
          if (ME11_ARID_DEF.Delay_DSTATE_cf + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Mode = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Default_c4;
          ME11_ARID_DEF.Mode = ME11_ARID_DEF.Delay_DSTATE_cf;
        }
        break;

       case ME11_IN_Default_c4:
        if (rtb_FixPtRelationalOperator_gf) {
          ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Active;
          b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_cf + 1;
          if (ME11_ARID_DEF.Delay_DSTATE_cf + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Mode = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.Mode = ME11_ARID_DEF.Delay_DSTATE_cf;
        }
        break;

       case ME11_IN_Init_n:
        if (ME11_ARID_DEF.temporalCounter_i1_b >= 10) {
          ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Default_c4;
          ME11_ARID_DEF.Mode = ME11_ARID_DEF.Delay_DSTATE_cf;
        } else {
          ME11_ARID_DEF.Mode = ME11_ARID_DEF.EERead_CabinMode;
        }
        break;

       default:
        if (ME11_ARID_DEF.temporalCounter_i1_b >= 1) {
          ME11_ARID_DEF.is_c100_ME11 = ME11_IN_Default_c4;
          ME11_ARID_DEF.Mode = ME11_ARID_DEF.Delay_DSTATE_cf;
        }
        break;
      }
    }

    if ((((sint32)HMICtl_bACDefrost > (sint32)
          ME11_ARID_DEF.DelayInput1_DSTATE_dz) || ((sint32)
          ME11_ARID_DEF.Delay1_DSTATE_c1 > (sint32)
          ME11_ARID_DEF.DelayInput1_DSTATE_a)) && (ME11_ARID_DEF.Delay_DSTATE_cf
         == 3)) {
      ME11_ARID_DEF.Delay_DSTATE_cf = 1U;
    } else {
      rtb_FixPtRelationalOperator_gf =
        ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
         ->VIPM_HUHybEcoModeSet_enum != ME11_ARID_DEF.DelayInput1_DSTATE_k);
      rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                          ->VIPM_HUHybEcoModeSet_enum == 2);
      rtb_Compare_mdjr = (rtb_Compare_mdjr && rtb_FixPtRelationalOperator_gf);
      if (rtb_Compare_mdjr) {
        ME11_ARID_DEF.Delay_DSTATE_cf =
          (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
          ->VIPM_HUHybEcoModeSet_enum;
      } else {
        rtb_FixPtRelationalOperator_gf =
          ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
           ->VIPM_HUHybEcoModeSet_enum != ME11_ARID_DEF.DelayInput1_DSTATE_gy);
        rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                            ->VIPM_HUHybEcoModeSet_enum == 1);
        rtb_Compare_mdjr = (rtb_Compare_mdjr && rtb_FixPtRelationalOperator_gf);
        if (rtb_Compare_mdjr) {
          ME11_ARID_DEF.Delay_DSTATE_cf =
            (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
            ->VIPM_HUHybEcoModeSet_enum;
        } else {
          rtb_FixPtRelationalOperator_gf =
            ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
             ->VIPM_HUHybEcoModeSet_enum != ME11_ARID_DEF.DelayInput1_DSTATE_p);
          rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC()
                              )->VIPM_HUHybEcoModeSet_enum == 3);
          rtb_Compare_mdjr = (rtb_Compare_mdjr && rtb_FixPtRelationalOperator_gf);
          if (rtb_Compare_mdjr) {
            ME11_ARID_DEF.Delay_DSTATE_cf =
              (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
              ->VIPM_HUHybEcoModeSet_enum;
          } else if (ME11_ARID_DEF.Mode <= 3) {
            ME11_ARID_DEF.Delay_DSTATE_cf = ME11_ARID_DEF.Mode;
          } else {
            ME11_ARID_DEF.Delay_DSTATE_cf = 3U;
          }
        }
      }
    }

    if (ME11_ARID_DEF.Delay_DSTATE_cf > 3) {
      ME11_ARID_DEF.Delay_DSTATE_cf = 3U;
    } else if (ME11_ARID_DEF.Delay_DSTATE_cf < 1) {
      ME11_ARID_DEF.Delay_DSTATE_cf = 1U;
    }

    if (cal_eACStsEnb) {
      HMICtl_eACSts = cal_eACStsData;
    } else {
      HMICtl_eACSts = ME11_ARID_DEF.Delay_DSTATE_cf;
    }

    rtb_FixPtRelationalOperator_gf = (RMTCtl_bRemtACFlg &&
      (!RMTCtl_bRemtACDefFlg));
    rtb_Compare_mdjr = ((!FixPtRelationalOperator) || HMICtl_bACDefrost);
    if (ME11_ARID_DEF.temporalCounter_i1_i < 15U) {
      ME11_ARID_DEF.temporalCounter_i1_i++;
    }

    if (ME11_ARID_DEF.is_active_c39_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c39_ME11 = 1U;
      ME11_ARID_DEF.is_c39_ME11 = ME11_IN_Init_h;
      ME11_ARID_DEF.temporalCounter_i1_i = 0U;
      ME11_ARID_DEF.Sts = ME11_ARID_DEF.EERead_bACAutoSts;
    } else {
      switch (ME11_ARID_DEF.is_c39_ME11) {
       case ME11_IN_After:
        if (rtb_Compare_mdjr && ME11_ARID_DEF.Delay_DSTATE_ly) {
          ME11_ARID_DEF.is_c39_ME11 = ME11_IN_wait_b;
          ME11_ARID_DEF.temporalCounter_i1_i = 0U;
          ME11_ARID_DEF.Sts = ME11_ARID_DEF.Delay_DSTATE_ly;
        } else {
          ME11_ARID_DEF.Sts = ME11_ARID_DEF.Delay_DSTATE_ly;
        }
        break;

       case ME11_IN_Enter:
        if (!rtb_Compare_mdjr) {
          ME11_ARID_DEF.is_c39_ME11 = ME11_IN_Exit;
          ME11_ARID_DEF.temporalCounter_i1_i = 0U;
          ME11_ARID_DEF.Sts = true;
        }
        break;

       case ME11_IN_Exit:
        if (ME11_ARID_DEF.temporalCounter_i1_i >= 3) {
          ME11_ARID_DEF.is_c39_ME11 = ME11_IN_After;
        }
        break;

       case ME11_IN_Init_h:
        if (ME11_ARID_DEF.temporalCounter_i1_i >= 10) {
          ME11_ARID_DEF.is_c39_ME11 = ME11_IN_After;
        } else {
          ME11_ARID_DEF.Sts = ME11_ARID_DEF.EERead_bACAutoSts;
        }
        break;

       default:
        if (!rtb_Compare_mdjr) {
          ME11_ARID_DEF.is_c39_ME11 = ME11_IN_Exit;
          ME11_ARID_DEF.temporalCounter_i1_i = 0U;
          ME11_ARID_DEF.Sts = true;
        } else if (ME11_ARID_DEF.temporalCounter_i1_i >= 1) {
          ME11_ARID_DEF.is_c39_ME11 = ME11_IN_Enter;
          ME11_ARID_DEF.Sts = false;
        }
        break;
      }
    }

    if ((rtb_FixPtRelationalOperator_dx != ME11_ARID_DEF.DelayInput1_DSTATE_m1) ||
        ((HMICtl_eACSts != ME11_ARID_DEF.DelayInput1_DSTATE_n4) &&
         (HMICtl_eACSts == 3)) || rtb_AND1_hh || (HMICtl_eModeMotor !=
         ME11_ARID_DEF.DelayInput1_DSTATE_m2)) {
      ME11_ARID_DEF.Delay_DSTATE_ly = false;
    } else {
      rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                          ->VIPM_HUACAutoCtl_enum !=
                          ME11_ARID_DEF.DelayInput1_DSTATE_hx);
      rtb_Compare_cvf = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                         ->VIPM_HUACAutoCtl_enum == 2);
      if (rtb_Compare_cvf && rtb_Compare_mdjr) {
        ME11_ARID_DEF.Delay_DSTATE_ly = true;
      } else {
        rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                            ->VIPM_HUACAutoCtl_enum !=
                            ME11_ARID_DEF.DelayInput1_DSTATE_kw);
        rtb_Compare_cvf = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                           ->VIPM_HUACAutoCtl_enum == 1);
        if (rtb_Compare_cvf && rtb_Compare_mdjr) {
          ME11_ARID_DEF.Delay_DSTATE_ly = false;
        } else {
          rtb_Compare_mdjr = ((sint32)
                              (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                               ())->VIPM_CCPACAutoKey_flg > (sint32)
                              ME11_ARID_DEF.DelayInput1_DSTATE_h2);
          if (rtb_Compare_mdjr) {
            ME11_ARID_DEF.Delay_DSTATE_ly = !ME11_ARID_DEF.Sts;
          } else {
            ME11_ARID_DEF.Delay_DSTATE_ly = ME11_ARID_DEF.Sts;
          }
        }
      }
    }

    if (cal_bACAutoEnb) {
      HMICtl_bACAuto = cal_bACAutoData;
    } else if (rtb_FixPtRelationalOperator_gf) {
      HMICtl_bACAuto = true;
    } else {
      HMICtl_bACAuto = (PWRCtl_bKL15swtSt && ME11_ARID_DEF.Delay_DSTATE_ly);
    }

    if (ME11_ARID_DEF.temporalCounter_i2_d < 15U) {
      ME11_ARID_DEF.temporalCounter_i2_d++;
    }

    if (ME11_ARID_DEF.temporalCounter_i1_dp < 15U) {
      ME11_ARID_DEF.temporalCounter_i1_dp++;
    }

    if (ME11_ARID_DEF.is_active_c59_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c59_ME11 = 1U;
      ME11_ARID_DEF.is_c59_ME11 = ME11_IN_NvmRead;
      ME11_ARID_DEF.temporalCounter_i1_dp = 0U;
      ME11_ARID_DEF.setBlw = ME11_ARID_DEF.EERead_CabinBlower;
    } else {
      switch (ME11_ARID_DEF.is_c59_ME11) {
       case ME11_IN_Max:
        if (ME11_ARID_DEF.Delay_DSTATE_oz < 8) {
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Normal_i;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_Init_n;
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        } else if
            ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
              ())->VIPM_CCPBlwrLvlDecKey_flg) {
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Normal_i;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_Dec_d;
          ME11_ARID_DEF.is_Dec_c = ME11_IN_Two;
          b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_oz - 1;
          if (ME11_ARID_DEF.Delay_DSTATE_oz - 1 < 0) {
            b_previousEvent = 0;
          }

          ME11_ARID_DEF.setBlw = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        }
        break;

       case ME11_IN_Min:
        if (ME11_ARID_DEF.Delay_DSTATE_oz > 0) {
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Normal_i;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_Init_n;
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        } else if
            ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
              ())->VIPM_CCPBlwrLvlAddKey_flg) {
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Normal_i;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_Add;
          ME11_ARID_DEF.is_Add_f = ME11_IN_One;
          b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_oz + 1;
          if (ME11_ARID_DEF.Delay_DSTATE_oz + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.setBlw = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        }
        break;

       case ME11_IN_Normal_i:
        if (ME11_ARID_DEF.setBlw >= 8) {
          ME11_ARID_DEF.is_Add_f = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Dec_c = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Max;
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        } else if (ME11_ARID_DEF.setBlw <= 0) {
          ME11_ARID_DEF.is_Add_f = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Dec_c = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Min;
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        } else {
          switch (ME11_ARID_DEF.is_Normal_i) {
           case ME11_IN_Add:
            if (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwrLvlAddKey_flg) {
              ME11_ARID_DEF.is_Add_f = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_Normal_i = ME11_IN_Init_n;
              ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
            } else {
              switch (ME11_ARID_DEF.is_Add_f) {
               case ME11_IN_Continue:
                if ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                     ())->VIPM_CCPBlwrLvlAddKey_flg) {
                  ME11_ARID_DEF.is_Add_f = ME11_IN_wait_k;
                  ME11_ARID_DEF.temporalCounter_i2_d = 0U;
                }
                break;

               case ME11_IN_One:
                if ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                     ())->VIPM_CCPBlwrLvlAddKey_flg) {
                  ME11_ARID_DEF.is_Add_f = ME11_IN_wait_k;
                  ME11_ARID_DEF.temporalCounter_i2_d = 0U;
                }
                break;

               default:
                if (ME11_ARID_DEF.temporalCounter_i2_d >= 10U) {
                  ME11_ARID_DEF.is_Add_f = ME11_IN_Continue;
                  b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_oz + 1;
                  if (ME11_ARID_DEF.Delay_DSTATE_oz + 1 > 255) {
                    b_previousEvent = 255;
                  }

                  ME11_ARID_DEF.setBlw = (uint8)b_previousEvent;
                }
                break;
              }
            }
            break;

           case ME11_IN_Dec_d:
            if (!(Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwrLvlDecKey_flg) {
              ME11_ARID_DEF.is_Dec_c = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_Normal_i = ME11_IN_Init_n;
              ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
            } else {
              switch (ME11_ARID_DEF.is_Dec_c) {
               case ME11_IN_Continue:
                if ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                     ())->VIPM_CCPBlwrLvlDecKey_flg) {
                  ME11_ARID_DEF.is_Dec_c = ME11_IN_wait_k;
                  ME11_ARID_DEF.temporalCounter_i2_d = 0U;
                }
                break;

               case ME11_IN_Two:
                if ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                     ())->VIPM_CCPBlwrLvlDecKey_flg) {
                  ME11_ARID_DEF.is_Dec_c = ME11_IN_wait_k;
                  ME11_ARID_DEF.temporalCounter_i2_d = 0U;
                }
                break;

               default:
                if (ME11_ARID_DEF.temporalCounter_i2_d >= 10U) {
                  ME11_ARID_DEF.is_Dec_c = ME11_IN_Continue;
                  b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_oz - 1;
                  if (ME11_ARID_DEF.Delay_DSTATE_oz - 1 < 0) {
                    b_previousEvent = 0;
                  }

                  ME11_ARID_DEF.setBlw = (uint8)b_previousEvent;
                }
                break;
              }
            }
            break;

           default:
            if ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                 ())->VIPM_CCPBlwrLvlAddKey_flg) {
              ME11_ARID_DEF.is_Normal_i = ME11_IN_Add;
              ME11_ARID_DEF.is_Add_f = ME11_IN_One;
              b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_oz + 1;
              if (ME11_ARID_DEF.Delay_DSTATE_oz + 1 > 255) {
                b_previousEvent = 255;
              }

              ME11_ARID_DEF.setBlw = (uint8)b_previousEvent;
            } else if
                ((Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
                  ())->VIPM_CCPBlwrLvlDecKey_flg) {
              ME11_ARID_DEF.is_Normal_i = ME11_IN_Dec_d;
              ME11_ARID_DEF.is_Dec_c = ME11_IN_Two;
              b_previousEvent = ME11_ARID_DEF.Delay_DSTATE_oz - 1;
              if (ME11_ARID_DEF.Delay_DSTATE_oz - 1 < 0) {
                b_previousEvent = 0;
              }

              ME11_ARID_DEF.setBlw = (uint8)b_previousEvent;
            } else {
              ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
            }
            break;
          }
        }
        break;

       default:
        if (ME11_ARID_DEF.temporalCounter_i1_dp >= 10) {
          ME11_ARID_DEF.is_c59_ME11 = ME11_IN_Normal_i;
          ME11_ARID_DEF.is_Normal_i = ME11_IN_Init_n;
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.Delay_DSTATE_oz;
        } else {
          ME11_ARID_DEF.setBlw = ME11_ARID_DEF.EERead_CabinBlower;
        }
        break;
      }
    }

    if ((HMICtl_eACSts == 3) && ((sint32)HMICtl_bACAuto < (sint32)
         ME11_ARID_DEF.DelayInput1_DSTATE_go)) {
      ME11_ARID_DEF.Delay_DSTATE_oz = 3U;
    } else {
      rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                          ->VIPM_HUFrntFanSpdSet_enum !=
                          ME11_ARID_DEF.DelayInput1_DSTATE_fp);
      if (rtb_Compare_mdjr) {
        rtb_Compare_mdjr = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                            ->VIPM_HUFrntFanSpdSet_enum >= 1);
        if (rtb_Compare_mdjr) {
          ME11_ARID_DEF.Delay_DSTATE_oz = (uint8)
            ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
             ->VIPM_HUFrntFanSpdSet_enum - 1);
        }
      } else {
        ME11_ARID_DEF.Delay_DSTATE_oz = ME11_ARID_DEF.setBlw;
      }

      if (ME11_ARID_DEF.Delay_DSTATE_oz <= 1) {
        ME11_ARID_DEF.Delay_DSTATE_oz = 1U;
      }
    }

    if (ME11_ARID_DEF.Delay_DSTATE_oz > 8) {
      ME11_ARID_DEF.Delay_DSTATE_oz = 8U;
    }

    ME11_ARID_DEF.EEWrite_CabinBlower = ME11_ARID_DEF.Delay_DSTATE_oz;
    if (HMICtl_bACDefrost) {
      if (HMICtl_eACSts == 1) {
        ME11_ARID_DEF.Switch1_n = 6U;
      } else {
        ME11_ARID_DEF.Switch1_n = 5U;
      }

      if (ME11_ARID_DEF.Switch1_n < ME11_ARID_DEF.Delay_DSTATE_oz) {
        ME11_ARID_DEF.Switch1_n = ME11_ARID_DEF.Delay_DSTATE_oz;
      }
    } else {
      ME11_ARID_DEF.Switch1_n = ME11_ARID_DEF.Delay_DSTATE_oz;
    }

    if (cal_eBlwStsEnb) {
      HMICtl_eBlwSts = cal_eBlwStsData;
    } else if (ME11_ARID_DEF.Delay2_DSTATE_pb) {
      HMICtl_eBlwSts = ME11_ARID_DEF.Switch1_n;
    } else {
      HMICtl_eBlwSts = 0U;
    }

    if (cal_bLeftSetLowEnb) {
      HMICtl_bLeftSetLow = cal_bLeftSetLowData;
    } else {
      HMICtl_bLeftSetLow = (HMICtl_sLeftSetPoint == 16.0F);
    }

    if (cal_bLeftSetHighEnb) {
      HMICtl_bLeftSetHigh = cal_bLeftSetHighData;
    } else {
      HMICtl_bLeftSetHigh = (HMICtl_sLeftSetPoint == 32.0F);
    }

    rtb_Compare_mdjr = (HMICtl_bLeftSetLow || ((!ME11_ARID_DEF.Delay1_DSTATE_ez)
      && HMICtl_bLeftSetHigh));
    if (rtb_Compare_mdjr) {
      rtb_Switch2_ht = 0U;
    } else {
      rtb_Switch2_ht = (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
        ->VIPM_HUAirInletModeSet_enum;
    }

    if (ME11_ARID_DEF.temporalCounter_i1_l4 < 15U) {
      ME11_ARID_DEF.temporalCounter_i1_l4++;
    }

    if (ME11_ARID_DEF.is_active_c128_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c128_ME11 = 1U;
      ME11_ARID_DEF.is_c128_ME11 = ME11_IN_Init_i;
      ME11_ARID_DEF.temporalCounter_i1_l4 = 0U;
      ME11_ARID_DEF.Result = ME11_ARID_DEF.EERead_CabinRecDoor;
    } else if (ME11_ARID_DEF.is_c128_ME11 == ME11_IN_Init_i) {
      if (ME11_ARID_DEF.temporalCounter_i1_l4 >= 10) {
        ME11_ARID_DEF.is_c128_ME11 = ME11_IN_Normal_k;
      } else {
        ME11_ARID_DEF.Result = ME11_ARID_DEF.EERead_CabinRecDoor;
      }
    } else {
      ME11_ARID_DEF.Result = ME11_ARID_DEF.Delay_DSTATE_fp;
    }

    if ((rtb_Switch2_ht == 2) && (rtb_Switch2_ht !=
         ME11_ARID_DEF.DelayInput1_DSTATE_nu)) {
      ME11_ARID_DEF.Delay_DSTATE_fp = 2U;
    } else if ((rtb_Switch2_ht == 1) && (rtb_Switch2_ht !=
                ME11_ARID_DEF.DelayInput1_DSTATE_dl)) {
      ME11_ARID_DEF.Delay_DSTATE_fp = 1U;
    } else if ((rtb_Switch2_ht == 3) && (rtb_Switch2_ht !=
                ME11_ARID_DEF.DelayInput1_DSTATE_p3)) {
      ME11_ARID_DEF.Delay_DSTATE_fp = 3U;
    } else {
      ME11_ARID_DEF.Delay_DSTATE_fp = ME11_ARID_DEF.Result;
    }

    if (rtb_Compare_mdjr || HMICtl_bACAuto) {
      ME11_ARID_DEF.Delay_DSTATE_fp = 1U;
    } else if (rtb_FixPtRelationalOperator_ka) {
      if (ME11_ARID_DEF.Delay_DSTATE_fp == 2) {
        ME11_ARID_DEF.Delay_DSTATE_fp = 1U;
      } else {
        ME11_ARID_DEF.Delay_DSTATE_fp = 2U;
      }
    }

    if (cal_eInnerEnb) {
      HMICtl_eInner = cal_eInnerData;
    } else {
      if (ME11_ARID_DEF.Delay1_DSTATE_ez) {
        HMICtl_eInner = 2U;
      } else {
        HMICtl_eInner = ME11_ARID_DEF.Delay_DSTATE_fp;
      }

      if (HMICtl_eInner > 3) {
        HMICtl_eInner = 3U;
      } else if (HMICtl_eInner < 1) {
        HMICtl_eInner = 1U;
      }
    }

    ME11_ARID_DEF.EEWrite_CabinRecDoor = HMICtl_eInner;
    ME11_ARID_DEF.EEWrite_CabinModeDoor = ME11_ARID_DEF.Delay1_DSTATE_es;
    ME11_ARID_DEF.EEWrite_CabinSetTemp = ME11_ARID_DEF.Fb;
    ME11_ARID_DEF.EEWrite_bACAutoSts = ME11_ARID_DEF.Delay_DSTATE_ly;
    rtb_FixPtRelationalOperator_ka = ((sint32)ME11_ARID_DEF.Delay1_DSTATE_c1 >
      (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_ovb);
    rtb_Compare_mdjr = ((sint32)HMICtl_bACDefrost > (sint32)
                        ME11_ARID_DEF.DelayInput1_DSTATE_in);
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.DelayInput1_DSTATE_b;
    ME11_ARID_DEF.DelayInput1_DSTATE_bx =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
       ->VIPM_HUHybEcoModeSet_enum > ME11_ARID_DEF.DelayInput1_DSTATE_f);
    rtb_FixPtRelationalOperator_cd =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPModeKey_flg;
    rtb_Compare_cvf = (ME11_ARID_DEF.DelayInput1_DSTATE_bx ||
                       rtb_FixPtRelationalOperator_cd);
    ME11_ARID_DEF.DelayInput1_DSTATE_bx = ME11_ARID_DEF.DelayInput1_DSTATE_ey;
    ME11_ARID_DEF.DelayInput1_DSTATE_bx = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPTempAddKey_flg > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_bx);
    rtb_FixPtRelationalOperator_cd = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPTempDecKey_flg > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_jm);
    rtb_FixPtRelationalOperator_cd = ((HU_LeftTempSet !=
      ME11_ARID_DEF.DelayInput1_DSTATE_nm) ||
      ME11_ARID_DEF.DelayInput1_DSTATE_bx || rtb_FixPtRelationalOperator_cd);
    ME11_ARID_DEF.DelayInput1_DSTATE_f = ME11_ARID_DEF.DelayInput1_DSTATE_fm;
    rtb_FixPtRelationalOperator_d5 =
      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())->VIPM_HUACPwrCtl_enum
       != ME11_ARID_DEF.DelayInput1_DSTATE_f);
    ME11_ARID_DEF.DelayInput1_DSTATE_bx = ME11_ARID_DEF.DelayInput1_DSTATE_id;
    rtb_FixPtRelationalOperator_ex = ((sint32)
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPACSwKey_flg > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_bx);
    if (ME11_ARID_DEF.is_active_c101_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c101_ME11 = 1U;
      ME11_ARID_DEF.is_c101_ME11 = ME11_IN_Init_i;
      ME11_ARID_DEF.HMICtl_bACOnOff_e = ME11_ARID_DEF.EERead_bACOnOff;
    } else {
      switch (ME11_ARID_DEF.is_c101_ME11) {
       case ME11_IN_Init_i:
        if (((rtb_FixPtRelationalOperator_d5 &&
              ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
               ->VIPM_HUACPwrCtl_enum == 1)) || rtb_FixPtRelationalOperator_ex) &&
            ME11_ARID_DEF.HMICtl_bACOnOff_e) {
          ME11_ARID_DEF.is_c101_ME11 = ME11_IN_Off_l;
          ME11_ARID_DEF.HMICtl_bACOnOff_e = false;
        } else if ((((rtb_FixPtRelationalOperator_d5 &&
                      ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                       ->VIPM_HUACPwrCtl_enum == 2)) ||
                     rtb_FixPtRelationalOperator_ex) &&
                    (!ME11_ARID_DEF.HMICtl_bACOnOff_e)) || (rtb_Compare_mdjr ||
                    rtb_FixPtRelationalOperator_ka || rtb_Compare_cvf ||
                    rtb_FixPtRelationalOperator_cd || rtb_AND1_hh)) {
          ME11_ARID_DEF.is_c101_ME11 = ME11_IN_On_kf;
          ME11_ARID_DEF.HMICtl_bACOnOff_e = true;
        } else {
          ME11_ARID_DEF.HMICtl_bACOnOff_e = ME11_ARID_DEF.EERead_bACOnOff;
        }
        break;

       case ME11_IN_Off_l:
        if ((((rtb_FixPtRelationalOperator_d5 &&
               ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                ->VIPM_HUACPwrCtl_enum == 2)) || rtb_FixPtRelationalOperator_ex)
             && (!ME11_ARID_DEF.HMICtl_bACOnOff_e)) || (rtb_Compare_mdjr ||
             rtb_FixPtRelationalOperator_ka || rtb_Compare_cvf ||
             rtb_FixPtRelationalOperator_cd || rtb_AND1_hh)) {
          ME11_ARID_DEF.is_c101_ME11 = ME11_IN_On_kf;
          ME11_ARID_DEF.HMICtl_bACOnOff_e = true;
        }
        break;

       default:
        if (((rtb_FixPtRelationalOperator_d5 &&
              ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
               ->VIPM_HUACPwrCtl_enum == 1)) || rtb_FixPtRelationalOperator_ex) &&
            ME11_ARID_DEF.HMICtl_bACOnOff_e) {
          ME11_ARID_DEF.is_c101_ME11 = ME11_IN_Off_l;
          ME11_ARID_DEF.HMICtl_bACOnOff_e = false;
        }
        break;
      }
    }

    if (cal_bACOnOffEnb) {
      HMICtl_bACOnOff = cal_bACOnOffData;
    } else {
      HMICtl_bACOnOff = ME11_ARID_DEF.HMICtl_bACOnOff_e;
    }

    ME11_ARID_DEF.EEWrite_bACOnOff = HMICtl_bACOnOff;
    if (PWRCtl_bKL15swtSt) {
      ME11_ARID_DEF.Switch_c = (RMTCtl_bRemtACDefFlg ||
        rtb_FixPtRelationalOperator_gf || HMICtl_bACOnOff);
    } else {
      ME11_ARID_DEF.Switch_c = false;
    }

    ME11_ARID_DEF.EEWrite_CabinMode = HMICtl_eACSts;
    Rte_DIDReadData(HMICtl_eACSts, ((uint8)DID_0xF273));
    ME11_ARID_DEF.DelayInput1_DSTATE_bx =
      ((Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs())
       ->VGSM_VehActGearPstn_enum == 0);
    if (ME11_ARID_DEF.Switch_c != ME11_ARID_DEF.DelayInput1_DSTATE_ej) {
      ME11_ARID_DEF.Delay_DSTATE_mu = ME11_ARID_DEF.Switch_c;
    }

    ACCtl_bExhaustFlg = (HMICtl_bLeftSetLow && (ME11_ARID_DEF.Delay_DSTATE_oz ==
      5) && (HMICtl_eACSts == 3) && (HMICtl_eInner == 1) && (HMICtl_eModeMotor ==
      1) && ME11_ARID_DEF.DelayInput1_DSTATE_bx && (!HMICtl_bACDefrost) &&
                         (!ME11_ARID_DEF.Delay_DSTATE_mu));
    if (HMICtl_bACDefrost) {
      ME11_ARID_DEF.Switch1_nv = 15U;
    } else if (HMICtl_bACAuto) {
      ME11_ARID_DEF.Switch1_nv = 7U;
    } else if (ME11_ARID_DEF.Switch_c) {
      ME11_ARID_DEF.Switch1_nv = 0U;
    } else {
      ME11_ARID_DEF.Switch1_nv = 8U;
    }

    if (cal_sMixDoorEnb) {
      HMICtl_sMixDoor = cal_sMixDoorData;
    } else {
      HMICtl_sMixDoor = 0.0F;
    }

    ME11_ARID_DEF.OutportBufferForHMICtl_bPTCOnReq = false;
    ME11_ARID_DEF.DelayInput1_DSTATE_f =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_TBOXACTempSet_enum;
    ME11_ARID_DEF.Delay3_DSTATE_kci = HMICtl_bACDefrost;
    ME11_ARID_DEF.DelayInput1_DSTATE_jg = rtb_Compare_ly;
    ME11_ARID_DEF.DelayInput1_DSTATE_d1 = HU_LeftTempSet;
    ME11_ARID_DEF.DelayInput1_DSTATE_kr = rtb_AND_hi;
    ME11_ARID_DEF.DelayInput1_DSTATE_gt = ME11_ARID_DEF.Fb;
    ME11_ARID_DEF.DelayInput1_DSTATE_f0 = rtb_Compare_ly;
    ME11_ARID_DEF.DelayInput1_DSTATE_l = PWRCtl_eTMSStatus_a;
    ME11_ARID_DEF.Delay1_DSTATE_d = HMICtl_sLeftSetPoint;
    ME11_ARID_DEF.DelayInput1_DSTATE_or = rtb_Delay1_ie;
    ME11_ARID_DEF.DelayInput1_DSTATE_di =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUFrntFanSpdSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_hg =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPBlwrLvlAddKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_bx =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPBlwrLvlDecKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_iv =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUAirInletModeSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_br =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPAirInletModeKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_jx = rtb_FixPtRelationalOperator_dx;
    ME11_ARID_DEF.Delay_DSTATE_by = ME11_ARID_DEF.Switch_c;
    ME11_ARID_DEF.DelayInput1_DSTATE_c = FixPtRelationalOperator;
    ME11_ARID_DEF.Delay1_DSTATE_c1 = HMICtl_bACAuto;
    ME11_ARID_DEF.DelayInput1_DSTATE_fq = rtb_Delay1_ag;
    ME11_ARID_DEF.DelayInput1_DSTATE_op =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUBlwrModeSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_gr = HMICtl_eModeMotor;
    ME11_ARID_DEF.DelayInput1_DSTATE_ov =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUManlDefrstCtl_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_ie =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUManlDefrstCtl_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_jd =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPFrntWindDefrstKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_dz = HMICtl_bACDefrost;
    ME11_ARID_DEF.DelayInput1_DSTATE_a = rtb_Delay1_ag;
    ME11_ARID_DEF.DelayInput1_DSTATE_k =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUHybEcoModeSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_gy =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUHybEcoModeSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_p =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUHybEcoModeSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_os =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPModeKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_m1 = rtb_FixPtRelationalOperator_dx;
    ME11_ARID_DEF.DelayInput1_DSTATE_n4 = HMICtl_eACSts;
    ME11_ARID_DEF.DelayInput1_DSTATE_m2 = HMICtl_eModeMotor;
    ME11_ARID_DEF.DelayInput1_DSTATE_hx =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())->VIPM_HUACAutoCtl_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_kw =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())->VIPM_HUACAutoCtl_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_h2 =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPACAutoKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_go = HMICtl_bACAuto;
    ME11_ARID_DEF.DelayInput1_DSTATE_fp =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUFrntFanSpdSet_enum;
    ME11_ARID_DEF.Delay2_DSTATE_pb = ME11_ARID_DEF.Switch_c;
    ME11_ARID_DEF.Delay1_DSTATE_ez = HMICtl_bACDefrost;
    ME11_ARID_DEF.DelayInput1_DSTATE_nu = rtb_Switch2_ht;
    ME11_ARID_DEF.DelayInput1_DSTATE_dl = rtb_Switch2_ht;
    ME11_ARID_DEF.DelayInput1_DSTATE_p3 = rtb_Switch2_ht;
    ME11_ARID_DEF.DelayInput1_DSTATE_ovb = rtb_Delay1_ag;
    ME11_ARID_DEF.DelayInput1_DSTATE_in = HMICtl_bACDefrost;
    ME11_ARID_DEF.DelayInput1_DSTATE_b =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUHybEcoModeSet_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_nm = HU_LeftTempSet;
    ME11_ARID_DEF.DelayInput1_DSTATE_ey =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPTempAddKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_jm =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPTempDecKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_fm =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())->VIPM_HUACPwrCtl_enum;
    ME11_ARID_DEF.DelayInput1_DSTATE_id =
      (Rte_IRead_Task_100ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD())
      ->VIPM_CCPACSwKey_flg;
    ME11_ARID_DEF.DelayInput1_DSTATE_ej = ME11_ARID_DEF.Switch_c;
  } else if (ME11_ARID_DEF.HMI_MODE) {
    HMICtl_bACAuto = false;
    ME11_ARID_DEF.Switch_c = false;
    HMICtl_bACDefrost = false;
    ME11_ARID_DEF.HMI_MODE = false;
  }

  rtb_Delay1_ie = ME11_ARID_DEF.Delay_DSTATE;
  rtb_Delay_ci = ME11_ARID_DEF.Delay_DSTATE_g;
  SENCtl_uEnvVoltage = get_EnvValtage();
  rtb_Add = (float32)((sint16)SENCtl_uEnvVoltage -
                      look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uEnvVoltage, (
    const uint16 *)&cal_EnvVolAmend_1X[0], (const sint16 *)&cal_EnvVolAmend_CUR
    [0], 1U));
  rtb_Add_ax = cal_ADCVCCVal - rtb_Add;
  ME11_Judge(rtb_Add > cal_SensorTempUpFlt, rtb_Add < cal_SensorTempDownFlg, 20,
             &ME11_ARID_DEF.SenSts_a, &ME11_ARID_DEF.ARID_DEF_Judge_g1);
  ACSen_eEnvSenSts = ME11_ARID_DEF.SenSts_a;
  if (rtb_Add_ax > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Add / rtb_Add_ax;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  SEN_TEnvRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 5.1F, (const
    float32 *)&cal_TEnvRaw_1X[0], (const float32 *)&cal_TEnvRaw_CUR[0], 26U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE = SEN_TEnvRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE = SEN_TEnvRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE * 0.100000024F;
  if (cal_EnvTempFltSwitch) {
    if ((float32)fabs(ME11_ARID_DEF.FixPtUnitDelay1_DSTATE - rtb_Delay_ci) >
        cal_EnvTempDiffMaxVal) {
      ME11_ARID_DEF.Delay_DSTATE_g = rtb_Delay_ci;
    } else {
      ME11_ARID_DEF.Delay_DSTATE_g = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE;
    }
  } else {
    ME11_ARID_DEF.Delay_DSTATE_g = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_g4 < 1U) {
    ME11_ARID_DEF.temporalCounter_i1_g4++;
  }

  if (ME11_ARID_DEF.is_active_c4_ME11Lib == 0U) {
    ME11_ARID_DEF.is_active_c4_ME11Lib = 1U;
    ME11_ARID_DEF.is_c4_ME11Lib = ME11_IN_init;
    ME11_ARID_DEF.temporalCounter_i1_g4 = 0U;
    ME11_ARID_DEF.even = 2.0F;
    ME11_ARID_DEF.i = 0U;
    while (ME11_ARID_DEF.i < 5) {
      ME11_ARID_DEF.y[ME11_ARID_DEF.i] = ME11_ARID_DEF.Delay_DSTATE_g;
      b_previousEvent = ME11_ARID_DEF.i + 1;
      if (ME11_ARID_DEF.i + 1 > 255) {
        b_previousEvent = 255;
      }

      ME11_ARID_DEF.i = (uint8)b_previousEvent;
    }
  } else {
    switch (ME11_ARID_DEF.is_c4_ME11Lib) {
     case ME11_IN_GetData:
      if (ME11_ARID_DEF.i >= 5) {
        ME11_ARID_DEF.is_c4_ME11Lib = ME11_IN_Middle;
        ME11_ARID_DEF.i = 0U;
        while (ME11_ARID_DEF.i < 5) {
          for (b_previousEvent = 0; b_previousEvent < ME11_ARID_DEF.i;
               b_previousEvent++) {
            if (ME11_ARID_DEF.y[b_previousEvent] >
                ME11_ARID_DEF.y[b_previousEvent + 1]) {
              ME11_sart((float64)ME11_ARID_DEF.y[b_previousEvent], (float64)
                        ME11_ARID_DEF.y[b_previousEvent + 1], &a, &b);
              ME11_ARID_DEF.y[b_previousEvent] = (float32)a;
              ME11_ARID_DEF.y[b_previousEvent + 1] = (float32)b;
            }
          }

          b_previousEvent = ME11_ARID_DEF.i + 1;
          if (ME11_ARID_DEF.i + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.i = (uint8)b_previousEvent;
        }

        ME11_ARID_DEF.i = 0U;
        ME11_ARID_DEF.flag = 0.0;
      } else {
        ME11_ARID_DEF.y[ME11_ARID_DEF.i] = ME11_ARID_DEF.Delay_DSTATE_g;
        b_previousEvent = ME11_ARID_DEF.i + 1;
        if (ME11_ARID_DEF.i + 1 > 255) {
          b_previousEvent = 255;
        }

        ME11_ARID_DEF.i = (uint8)b_previousEvent;
      }
      break;

     case ME11_IN_Middle:
      if (ME11_ARID_DEF.flag == 0.0) {
        ME11_ARID_DEF.is_c4_ME11Lib = ME11_IN_GetData;
        ME11_ARID_DEF.flag = 1.0;
        ME11_ARID_DEF.y[ME11_ARID_DEF.i] = ME11_ARID_DEF.Delay_DSTATE_g;
        b_previousEvent = ME11_ARID_DEF.i + 1;
        if (ME11_ARID_DEF.i + 1 > 255) {
          b_previousEvent = 255;
        }

        ME11_ARID_DEF.i = (uint8)b_previousEvent;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_g4 >= 1) {
        ME11_ARID_DEF.i = 0U;
        ME11_ARID_DEF.is_c4_ME11Lib = ME11_IN_GetData;
        ME11_ARID_DEF.flag = 1.0;
        ME11_ARID_DEF.y[ME11_ARID_DEF.i] = ME11_ARID_DEF.Delay_DSTATE_g;
        b_previousEvent = ME11_ARID_DEF.i + 1;
        if (ME11_ARID_DEF.i + 1 > 255) {
          b_previousEvent = 255;
        }

        ME11_ARID_DEF.i = (uint8)b_previousEvent;
      }
      break;
    }
  }

  if (ME11_ARID_DEF.even > 0.0F) {
    ACSen_sEnvTempFilter = ME11_ARID_DEF.y[3];
  } else {
    ACSen_sEnvTempFilter = ME11_ARID_DEF.y[2];
  }

  if (ME11_ARID_DEF.Delay_DSTATE_px) {
    rtb_Switch4_a = ACSen_sEnvTempFilter;
  } else {
    if ((ME11_ARID_DEF.EERead_AmbienceTemp < -40.0F) ||
        (ME11_ARID_DEF.EERead_AmbienceTemp > 80.0F)) {
      rtb_Switch4_a = ACSen_sEnvTempFilter;
    } else {
      rtb_Switch4_a = ME11_ARID_DEF.EERead_AmbienceTemp;
    }

    if ((float32)fabs(ACSen_sEnvTempFilter - rtb_Switch4_a) >
        cal_EEEnvAndEnvDiffVal) {
      rtb_Switch4_a = ACSen_sEnvTempFilter;
    }

    if (ACSen_sEnvTempFilter < rtb_Switch4_a) {
      rtb_Switch4_a = ACSen_sEnvTempFilter;
    } else if (GLB_CoAC_stColdStart) {
      rtb_Switch4_a = ACSen_sEnvTempFilter;
    }
  }

  if (rtb_Switch4_a > 80.0F) {
    rtb_Delay_ci = 80.0F;
  } else if (rtb_Switch4_a < -40.0F) {
    rtb_Delay_ci = -40.0F;
  } else {
    rtb_Delay_ci = rtb_Switch4_a;
  }

  SENCtl_uMotInletTempVol = get_MotInletTempValtage();
  rtb_Add = (float32)((sint16)SENCtl_uMotInletTempVol -
                      look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uMotInletTempVol,
    (const uint16 *)&cal_MotInletTempVolAmend_1X[0], (const sint16 *)
    &cal_MotInletTempVolAmend_CUR[0], 1U));
  rtb_Add_ax = cal_ADCVCCVal - rtb_Add;
  ME11_Judge(rtb_Add > cal_SensorTempUpFlt, rtb_Add < cal_SensorTempDownFlg, 20,
             &ME11_ARID_DEF.SenSts_b, &ME11_ARID_DEF.ARID_DEF_Judge_cv);
  ACSen_eMOTORTSenSts = ME11_ARID_DEF.SenSts_b;
  if (rtb_Add_ax > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Add / rtb_Add_ax;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  SEN_TMotRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 10000.0F, (const
    float32 *)&cal_TMotEntRaw_1X[0], (const float32 *)&cal_TMotEntRaw_CUR[0],
    16U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_n != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_c = SEN_TMotRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_c = SEN_TMotRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_c * 0.100000024F;
  if (cal_MotTempDataEnb) {
    ACSen_sMotTempFilter = cal_MotTempData;
  } else {
    ACSen_sMotTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_c;
  }

  rtb_Switch4_a = ME11_ARID_DEF.Delay1_DSTATE;
  ColdPCUTempMinByEnv = cal_ColdPCUTempMinByEnv_CUR[plook_u32f_bincka
    (rtb_Switch4_a, (const float32 *)&cal_ColdPCUTempMinByEnv_1X[0], 14U)];
  if (rtb_Delay_ci > rtb_Switch4_a) {
    if (GLB_ESC_VehicleSpeedValid) {
      if (GLB_ESC_VehicleSpeed >= cal_VehicleSpeedHighVs) {
        rtb_Add_ax = cal_TempRampStepFast;
      } else if (GLB_ESC_VehicleSpeed <= cal_VehicleSpeedLowVs) {
        if (ACSen_sMotTempFilter >= ColdPCUTempMinByEnv) {
          rtb_Add_ax = 0.0F;
        } else {
          rtb_Add_ax = cal_TempRampStepLoVSpeed;
        }
      } else {
        rtb_Add_ax = cal_TempRampStepSlow;
      }
    } else {
      rtb_Add_ax = 0.0F;
    }
  } else {
    rtb_Add_ax = cal_EnvTempRiseStep;
  }

  rtb_Add = rtb_Delay1_ie + rtb_Add_ax;
  if (rtb_Add > 80.0F) {
    rtb_Add = 80.0F;
  }

  if (rtb_Delay1_ie - -40.0F >= rtb_Add_ax) {
    rtb_Add_ax = rtb_Delay1_ie - rtb_Add_ax;
  } else {
    rtb_Add_ax = -40.0F;
  }

  if (ME11_ARID_DEF.is_active_c50_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c50_ME11 = 1U;
    ME11_ARID_DEF.OutData = rtb_Delay_ci;
    ME11_ARID_DEF.is_c50_ME11 = ME11_IN_DontChange;
    ME11_ARID_DEF.count = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c50_ME11) {
     case ME11_IN_DecreaseTemp:
      if (rtb_Delay1_ie <= rtb_Delay_ci) {
        ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_c50_ME11 = ME11_IN_DontChange;
        ME11_ARID_DEF.count = 0U;
      } else {
        rtb_Divide1_f = ME11_ARID_DEF.count + 1U;
        if (ME11_ARID_DEF.count + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.count = (uint16)rtb_Divide1_f;
        if (ME11_ARID_DEF.is_DecreaseTemp == ME11_IN_Delay) {
          ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_NO_ACTIVE_CHILD_gl;
          if (ME11_ARID_DEF.count > cal_FallTime2Tamb) {
            ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_Delaychecked;
            ME11_ARID_DEF.OutData = rtb_Add_ax;
            ME11_ARID_DEF.count = 0U;
          } else {
            ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_Delay;
            ME11_ARID_DEF.OutData = rtb_Delay1_ie;
          }
        } else {
          ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_NO_ACTIVE_CHILD_gl;
          if (ME11_ARID_DEF.count > cal_FallTime2Tamb) {
            ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_Delaychecked;
            ME11_ARID_DEF.OutData = rtb_Add_ax;
            ME11_ARID_DEF.count = 0U;
          } else {
            ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_Delay;
            ME11_ARID_DEF.OutData = rtb_Delay1_ie;
          }
        }
      }
      break;

     case ME11_IN_DontChange:
      if (rtb_Delay1_ie < rtb_Delay_ci) {
        ME11_ARID_DEF.is_c50_ME11 = ME11_IN_IncreaseTemp;
        ME11_ARID_DEF.count = 0U;
        if (ME11_ARID_DEF.count > cal_RiseTime2Tamb) {
          ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_Delaychecked;
          ME11_ARID_DEF.OutData = rtb_Add;
          ME11_ARID_DEF.count = 0U;
        } else {
          ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_Delay;
          ME11_ARID_DEF.OutData = rtb_Delay1_ie;
        }
      } else if (rtb_Delay1_ie > rtb_Delay_ci) {
        ME11_ARID_DEF.is_c50_ME11 = ME11_IN_DecreaseTemp;
        ME11_ARID_DEF.count = 0U;
        if (ME11_ARID_DEF.count > cal_FallTime2Tamb) {
          ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_Delaychecked;
          ME11_ARID_DEF.OutData = rtb_Add_ax;
          ME11_ARID_DEF.count = 0U;
        } else {
          ME11_ARID_DEF.is_DecreaseTemp = ME11_IN_Delay;
          ME11_ARID_DEF.OutData = rtb_Delay1_ie;
        }
      }
      break;

     default:
      if (rtb_Delay1_ie >= rtb_Delay_ci) {
        ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_c50_ME11 = ME11_IN_DontChange;
        ME11_ARID_DEF.count = 0U;
      } else {
        rtb_Divide1_f = ME11_ARID_DEF.count + 1U;
        if (ME11_ARID_DEF.count + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.count = (uint16)rtb_Divide1_f;
        if (ME11_ARID_DEF.is_IncreaseTemp == ME11_IN_Delay) {
          ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_NO_ACTIVE_CHILD_gl;
          if (ME11_ARID_DEF.count > cal_RiseTime2Tamb) {
            ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_Delaychecked;
            ME11_ARID_DEF.OutData = rtb_Add;
            ME11_ARID_DEF.count = 0U;
          } else {
            ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_Delay;
            ME11_ARID_DEF.OutData = rtb_Delay1_ie;
          }
        } else {
          ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_NO_ACTIVE_CHILD_gl;
          if (ME11_ARID_DEF.count > cal_RiseTime2Tamb) {
            ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_Delaychecked;
            ME11_ARID_DEF.OutData = rtb_Add;
            ME11_ARID_DEF.count = 0U;
          } else {
            ME11_ARID_DEF.is_IncreaseTemp = ME11_IN_Delay;
            ME11_ARID_DEF.OutData = rtb_Delay1_ie;
          }
        }
      }
      break;
    }
  }

  if ((GLB_CoAC_stwork == 2) || (GLB_CoAC_stwork == 3) || (GLB_CoAC_stwork == 5))
  {
    rtb_Delay1_ie = ME11_ARID_DEF.OutData;
  } else {
    rtb_Delay1_ie = ACSen_sEnvTempFilter;
  }

  ACSen_sEnvTAme = look1_iflf_binlca(rtb_Delay1_ie, (const float32 *)
    &cal_EnvTAme_1X[0], (const float32 *)&cal_EnvTAme_CUR[0], 10U);
  if (cal_EnvTempCorEnb) {
    ACSen_sEnvTempCor = cal_EnvTempCorData;
  } else {
    ACSen_sEnvTempCor = ACSen_sEnvTAme + rtb_Delay1_ie;
  }

  rtb_AND_hi = (cal_tCabinCoolEnvTempLow <= ACSen_sEnvTempCor);
  rtb_FixPtRelationalOperator_dx = (ACSen_sEnvTempCor <
    cal_tCabinCoolEnvTempHigh);
  if (HMICtl_sLeftSetPoint == cal_DefaultSetTemp) {
    rtb_MultiportSwitch2_e = 0.0F;
  } else {
    rtb_MultiportSwitch2_e = cal_PsEnv4SetSelect;
  }

  ACCtl_tRightSetPointModeCor = rtb_MultiportSwitch2_e + HMICtl_sLeftSetPoint;
  AC_Ps2DrSetTempDvt = ACCtl_tRightSetPointModeCor - HMICtl_sLeftSetPoint;
  ACCtl_tPsDVTCabinCor = look2_iflf_binlca(AC_Ps2DrSetTempDvt, ACSen_sEnvTempCor,
    (const float32 *)&cal_ACPsDVTSetCorByEnv_2X[0], (const float32 *)
    &cal_ACPsDVTSetCorByEnv_2Y[0], (const float32 *)&cal_ACPsDVTSetCorByEnv_MAP
    [0], ME11_ConstP.pooled36, 14U);
  SENCtl_uSolorVol = get_SolorValtage();
  rtb_Switch4_a = (float32)((sint16)SENCtl_uSolorVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uSolorVol, (const uint16 *)
    &cal_SolorVolAmend_1X[0], (const sint16 *)&cal_SolorVolAmend_CUR[0], 1U));
  SEN_SolarRaw = look1_iflftu16Df_binlca(0.001F * rtb_Switch4_a, (const float32 *)
    &cal_SolarValRaw_1X[0], (const uint16 *)&cal_SolarValRaw_CUR[0], 10U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_g != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_p = SEN_SolarRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_p = (float32)SEN_SolarRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_p * 0.100000024F;
  if (cal_SolarEnb) {
    AC_rSolarRight = cal_SolarData;
  } else {
    AC_rSolarRight = (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_p;
  }

  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_k != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_m = AC_rSolarRight;
  }

  rtb_Add = (float32)AC_rSolarRight * cal_U_DVTFFSolarFilterRate;
  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_m = (1.0F - cal_U_DVTFFSolarFilterRate) *
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_m + rtb_Add;
  GlbDa_RightSolar = (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_m;
  ACCtl_tPsDVTSolarCor = look2_iu16flftf_binlca(GlbDa_RightSolar,
    ACSen_sEnvTempCor, (const uint16 *)&cal_ACPsDVTSolarCor_2X[0], (const
    float32 *)&cal_ACPsDVTSolarCor_2Y[0], (const float32 *)
    &cal_ACPsDVTSolarCor_MAP[0], ME11_ConstP.pooled33, 15U);
  if ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
      ->BCM_SysPwrModeV > 0) {
    PWRCtl_eTMSStatus_a =
      (Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
      ->BCM_SysPwrMode;
  } else {
    PWRCtl_eTMSStatus_a = 0U;
  }

  guard1 = false;
  guard2 = false;
  if (ME11_ARID_DEF.is_active_c43_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c43_ME11 = 1U;
    if (PWRCtl_bKL15swtSt || (PWRCtl_eTMSStatus_a == 2) || (PWRCtl_eBatChargSts
         != 0)) {
      ME11_ARID_DEF.is_c43_ME11 = ME11_IN_T15_ON;
      guard2 = true;
    } else {
      ME11_ARID_DEF.is_c43_ME11 = ME11_IN_T15_OFF;
      guard1 = true;
    }
  } else if (ME11_ARID_DEF.is_c43_ME11 == ME11_IN_T15_OFF) {
    if (PWRCtl_bKL15swtSt || (PWRCtl_eTMSStatus_a == 2) || (PWRCtl_eBatChargSts
         != 0)) {
      ME11_ARID_DEF.is_c43_ME11 = ME11_IN_T15_ON;
      guard2 = true;
    } else {
      guard1 = true;
    }
  } else if ((!PWRCtl_bKL15swtSt) && (PWRCtl_eTMSStatus_a == 0) &&
             (PWRCtl_eBatChargSts == 0)) {
    ME11_ARID_DEF.is_c43_ME11 = ME11_IN_T15_OFF;
    guard1 = true;
  } else {
    guard2 = true;
  }

  if (guard2) {
    if ((uint16)(ME11_ARID_DEF.Delay_DSTATE_ns + 1U) <= 40000) {
      ME11_ARID_DEF.Delay_DSTATE_ns++;
    } else {
      ME11_ARID_DEF.Delay_DSTATE_ns = 40000U;
    }

    AC_stIGNON = (ME11_ARID_DEF.Delay_DSTATE_ns > cal_IGNONDelayTime);
  }

  if (guard1) {
    ME11_ARID_DEF.Delay_DSTATE_ns = 0U;
    AC_stIGNON = false;
  }

  if (ME11_ARID_DEF.is_active_c42_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c42_ME11 = 1U;
    ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stStop;
    ME11_ARID_DEF.CoAC_tiStandBy = 0U;
    ME11_ARID_DEF.CoAC_stwork_l = 0U;
  } else {
    switch (ME11_ARID_DEF.is_Run) {
     case ME11_IN_CoAC_stAfterRun:
      ME11_ARID_DEF.CoAC_stwork_l = 4U;
      if ((ME11_ARID_DEF.CoAC_tiStandBy > 6) || AC_stIGNON) {
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stStop;
        ME11_ARID_DEF.CoAC_tiStandBy = 0U;
        ME11_ARID_DEF.CoAC_stwork_l = 0U;
      } else {
        b_previousEvent = ME11_ARID_DEF.CoAC_tiStandBy + 1;
        if (ME11_ARID_DEF.CoAC_tiStandBy + 1 > 255) {
          b_previousEvent = 255;
        }

        ME11_ARID_DEF.CoAC_tiStandBy = (uint8)b_previousEvent;
      }
      break;

     case ME11_IN_CoAC_stInit:
      ME11_ARID_DEF.CoAC_stwork_l = 1U;
      if (!AC_stIGNON) {
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stStop;
        ME11_ARID_DEF.CoAC_tiStandBy = 0U;
        ME11_ARID_DEF.CoAC_stwork_l = 0U;
      } else if (ME11_ARID_DEF.CoAC_tiStandBy > 51) {
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stNormal;
        if (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
             ->BCM_SysPowerSts == 1) && PWRCtl_bKL15swtSt) {
          ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stNativeWakeUp;
          ME11_ARID_DEF.CoAC_stwork_l = 2U;
        } else if (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
                    ->BCM_SysPowerSts == 2) && PWRCtl_bKL15swtSt) {
          ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stRemoteWakeUp;
          ME11_ARID_DEF.CoAC_stwork_l = 3U;
        } else {
          ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stChargeWakeUp;
          ME11_ARID_DEF.CoAC_stwork_l = 5U;
        }
      } else {
        b_previousEvent = ME11_ARID_DEF.CoAC_tiStandBy + 1;
        if (ME11_ARID_DEF.CoAC_tiStandBy + 1 > 255) {
          b_previousEvent = 255;
        }

        ME11_ARID_DEF.CoAC_tiStandBy = (uint8)b_previousEvent;
      }
      break;

     case ME11_IN_CoAC_stNormal:
      if (!AC_stIGNON) {
        ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stAfterRun;
        ME11_ARID_DEF.CoAC_stwork_l = 4U;
        ME11_ARID_DEF.CoAC_tiStandBy = 0U;
      } else if ((((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
                   ->BCM_SysPowerSts == 3) ||
                  ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
                   ->BCM_SysPowerSts == 5)) && PWRCtl_bKL15swtSt &&
                 (ME11_ARID_DEF.CoAC_stwork_l != 1)) {
        ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stOTA;
      } else {
        switch (ME11_ARID_DEF.is_CoAC_stNormal) {
         case ME11_IN_CoAC_stChargeWakeUp:
          ME11_ARID_DEF.CoAC_stwork_l = 5U;
          if (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
               ->BCM_SysPowerSts == 2) && PWRCtl_bKL15swtSt) {
            ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stRemoteWakeUp;
            ME11_ARID_DEF.CoAC_stwork_l = 3U;
          } else if
              (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
                ->BCM_SysPowerSts == 1) && PWRCtl_bKL15swtSt) {
            ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stNativeWakeUp;
            ME11_ARID_DEF.CoAC_stwork_l = 2U;
          }
          break;

         case ME11_IN_CoAC_stNativeWakeUp:
          ME11_ARID_DEF.CoAC_stwork_l = 2U;
          if ((!PWRCtl_bKL15swtSt) &&
              ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
               ->BCM_SysPowerSts == 0) && (PWRCtl_eBatChargSts != 0)) {
            ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stChargeWakeUp;
            ME11_ARID_DEF.CoAC_stwork_l = 5U;
          } else if ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
                      ())->BCM_SysPowerSts == 2) {
            ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stRemoteWakeUp;
            ME11_ARID_DEF.CoAC_stwork_l = 3U;
          }
          break;

         default:
          ME11_ARID_DEF.CoAC_stwork_l = 3U;
          if ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
              ->BCM_SysPowerSts == 1) {
            ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stNativeWakeUp;
            ME11_ARID_DEF.CoAC_stwork_l = 2U;
          } else if ((!PWRCtl_bKL15swtSt) &&
                     ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
                       ())->BCM_SysPowerSts == 0) && (PWRCtl_eBatChargSts != 0))
          {
            ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stChargeWakeUp;
            ME11_ARID_DEF.CoAC_stwork_l = 5U;
          }
          break;
        }
      }
      break;

     case ME11_IN_CoAC_stOTA:
      if (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
           ->BCM_SysPowerSts != 3) &&
          ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
           ->BCM_SysPowerSts != 5)) {
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stNormal;
        if (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
             ->BCM_SysPowerSts == 1) && PWRCtl_bKL15swtSt) {
          ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stNativeWakeUp;
          ME11_ARID_DEF.CoAC_stwork_l = 2U;
        } else if (((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
                    ->BCM_SysPowerSts == 2) && PWRCtl_bKL15swtSt) {
          ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stRemoteWakeUp;
          ME11_ARID_DEF.CoAC_stwork_l = 3U;
        } else {
          ME11_ARID_DEF.is_CoAC_stNormal = ME11_IN_CoAC_stChargeWakeUp;
          ME11_ARID_DEF.CoAC_stwork_l = 5U;
        }
      } else if (!AC_stIGNON) {
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stAfterRun;
        ME11_ARID_DEF.CoAC_stwork_l = 4U;
        ME11_ARID_DEF.CoAC_tiStandBy = 0U;
      }
      break;

     default:
      ME11_ARID_DEF.CoAC_stwork_l = 0U;
      if (AC_stIGNON) {
        ME11_ARID_DEF.is_Run = ME11_IN_CoAC_stInit;
        ME11_ARID_DEF.CoAC_stwork_l = 1U;
      }
      break;
    }
  }

  if (cal_CANAliveEnable) {
    CoAC_stwork = ME11_ARID_DEF.CoAC_stwork_l;
  } else {
    CoAC_stwork = 0U;
  }

  if ((CoAC_stwork == 2) || (CoAC_stwork == 3) || (CoAC_stwork == 5)) {
    rtb_Delay_ci = ME11_ARID_DEF.Delay_DSTATE_o + cal_EnvTempStep;
    if (rtb_Delay_ci > 80.0F) {
      rtb_Delay_ci = 80.0F;
    }

    if (ME11_ARID_DEF.Delay_DSTATE_o - -40.0F >= cal_EnvTempStep) {
      rtb_Delay1_ie = ME11_ARID_DEF.Delay_DSTATE_o - cal_EnvTempStep;
    } else {
      rtb_Delay1_ie = -40.0F;
    }

    if (ME11_ARID_DEF.is_active_c45_ME11 == 0U) {
      ME11_ARID_DEF.is_active_c45_ME11 = 1U;
      AC_tEnvInvent = ACSen_sEnvTempCor;
      ME11_ARID_DEF.is_c45_ME11 = ME11_IN_DontChange;
      ME11_ARID_DEF.count_o = 0U;
    } else {
      switch (ME11_ARID_DEF.is_c45_ME11) {
       case ME11_IN_DecreaseTemp:
        if (ME11_ARID_DEF.Delay_DSTATE_o <= ACSen_sEnvTempCor) {
          ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_c45_ME11 = ME11_IN_DontChange;
          ME11_ARID_DEF.count_o = 0U;
        } else {
          rtb_Divide1_f = ME11_ARID_DEF.count_o + 1U;
          if (ME11_ARID_DEF.count_o + 1U > 65535U) {
            rtb_Divide1_f = 65535U;
          }

          ME11_ARID_DEF.count_o = (uint16)rtb_Divide1_f;
          if (ME11_ARID_DEF.is_DecreaseTemp_j == ME11_IN_Delay) {
            if (ME11_ARID_DEF.count_o > cal_FalseTime2EnvTamb) {
              ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_Delaychecked;
              AC_tEnvInvent = rtb_Delay1_ie;
              ME11_ARID_DEF.count_o = 0U;
            } else {
              ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_Delay;
              AC_tEnvInvent = ME11_ARID_DEF.Delay_DSTATE_o;
            }
          } else if (ME11_ARID_DEF.count_o > cal_FalseTime2EnvTamb) {
            ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_Delaychecked;
            AC_tEnvInvent = rtb_Delay1_ie;
            ME11_ARID_DEF.count_o = 0U;
          } else {
            ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_Delay;
            AC_tEnvInvent = ME11_ARID_DEF.Delay_DSTATE_o;
          }
        }
        break;

       case ME11_IN_DontChange:
        if (ACSen_sEnvTempCor - -40.0F >= cal_EnvTempStep) {
          rtb_MultiportSwitch2_e = ACSen_sEnvTempCor - cal_EnvTempStep;
        } else {
          rtb_MultiportSwitch2_e = -40.0F;
        }

        if (ME11_ARID_DEF.Delay_DSTATE_o < rtb_MultiportSwitch2_e) {
          ME11_ARID_DEF.is_c45_ME11 = ME11_IN_IncreaseTemp;
          ME11_ARID_DEF.count_o = 0U;
          if (ME11_ARID_DEF.count_o > cal_RiseTime2EnvTamb) {
            ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_Delaychecked;
            AC_tEnvInvent = rtb_Delay_ci;
            ME11_ARID_DEF.count_o = 0U;
          } else {
            ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_Delay;
            AC_tEnvInvent = ME11_ARID_DEF.Delay_DSTATE_o;
          }
        } else {
          rtb_Add_ax = ACSen_sEnvTempCor + cal_EnvTempStep;
          if (rtb_Add_ax > 80.0F) {
            rtb_Add_ax = 80.0F;
          }

          if (ME11_ARID_DEF.Delay_DSTATE_o > rtb_Add_ax) {
            ME11_ARID_DEF.is_c45_ME11 = ME11_IN_DecreaseTemp;
            ME11_ARID_DEF.count_o = 0U;
            if (ME11_ARID_DEF.count_o > cal_FalseTime2EnvTamb) {
              ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_Delaychecked;
              AC_tEnvInvent = rtb_Delay1_ie;
              ME11_ARID_DEF.count_o = 0U;
            } else {
              ME11_ARID_DEF.is_DecreaseTemp_j = ME11_IN_Delay;
              AC_tEnvInvent = ME11_ARID_DEF.Delay_DSTATE_o;
            }
          }
        }
        break;

       default:
        if (ME11_ARID_DEF.Delay_DSTATE_o >= ACSen_sEnvTempCor) {
          ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_NO_ACTIVE_CHILD_gl;
          ME11_ARID_DEF.is_c45_ME11 = ME11_IN_DontChange;
          ME11_ARID_DEF.count_o = 0U;
        } else {
          rtb_Divide1_f = ME11_ARID_DEF.count_o + 1U;
          if (ME11_ARID_DEF.count_o + 1U > 65535U) {
            rtb_Divide1_f = 65535U;
          }

          ME11_ARID_DEF.count_o = (uint16)rtb_Divide1_f;
          if (ME11_ARID_DEF.is_IncreaseTemp_l == ME11_IN_Delay) {
            if (ME11_ARID_DEF.count_o > cal_RiseTime2EnvTamb) {
              ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_Delaychecked;
              AC_tEnvInvent = rtb_Delay_ci;
              ME11_ARID_DEF.count_o = 0U;
            } else {
              ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_Delay;
              AC_tEnvInvent = ME11_ARID_DEF.Delay_DSTATE_o;
            }
          } else if (ME11_ARID_DEF.count_o > cal_RiseTime2EnvTamb) {
            ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_Delaychecked;
            AC_tEnvInvent = rtb_Delay_ci;
            ME11_ARID_DEF.count_o = 0U;
          } else {
            ME11_ARID_DEF.is_IncreaseTemp_l = ME11_IN_Delay;
            AC_tEnvInvent = ME11_ARID_DEF.Delay_DSTATE_o;
          }
        }
        break;
      }
    }

    ME11_ARID_DEF.Delay_DSTATE_o = AC_tEnvInvent;
  }

  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kt != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h = AC_rSolarRight;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h = (1.0F - cal_U_DVTFFSolarFilterRate) *
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h + rtb_Add;
  if (ME11_ARID_DEF.is_active_c41_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c41_ME11 = 1U;
    ME11_ARID_DEF.OutData_f = (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
    ME11_ARID_DEF.is_c41_ME11 = ME11_IN_DontChange;
    ME11_ARID_DEF.count_g = 0U;
  } else {
    guard1 = false;
    switch (ME11_ARID_DEF.is_c41_ME11) {
     case ME11_IN_DecreaseTemp:
      if (AC_rSunloadFlt <= (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h) {
        ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_c41_ME11 = ME11_IN_DontChange;
        ME11_ARID_DEF.count_g = 0U;
      } else {
        rtb_Divide1_f = ME11_ARID_DEF.count_g + 1U;
        if (ME11_ARID_DEF.count_g + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.count_g = (uint16)rtb_Divide1_f;
        if (ME11_ARID_DEF.is_DecreaseTemp_ji == ME11_IN_Delay) {
          if (ME11_ARID_DEF.count_g > cal_FalseTime2Solar) {
            ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_Delaychecked;
            ME11_ARID_DEF.count_g = 0U;
            rtb_Divide1_f = (uint32)(uint16)
              ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h + cal_SolarFalseStep;
            if (rtb_Divide1_f > 65535U) {
              rtb_Divide1_f = 65535U;
            }

            if (AC_rSunloadFlt > (sint32)rtb_Divide1_f) {
              rtb_Divide1_f = (uint32)AC_rSunloadFlt - cal_SolarFalseStep;
              if (rtb_Divide1_f > AC_rSunloadFlt) {
                rtb_Divide1_f = 0U;
              }

              ME11_ARID_DEF.OutData_f = (uint16)rtb_Divide1_f;
            } else {
              ME11_ARID_DEF.OutData_f = (uint16)
                ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
            }
          } else {
            ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_Delay;
          }
        } else if (ME11_ARID_DEF.count_g > cal_FalseTime2Solar) {
          ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_Delaychecked;
          ME11_ARID_DEF.count_g = 0U;
          rtb_Divide1_f = (uint32)(uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h
            + cal_SolarFalseStep;
          if (rtb_Divide1_f > 65535U) {
            rtb_Divide1_f = 65535U;
          }

          if (AC_rSunloadFlt > (sint32)rtb_Divide1_f) {
            rtb_Divide1_f = (uint32)AC_rSunloadFlt - cal_SolarFalseStep;
            if (rtb_Divide1_f > AC_rSunloadFlt) {
              rtb_Divide1_f = 0U;
            }

            ME11_ARID_DEF.OutData_f = (uint16)rtb_Divide1_f;
          } else {
            ME11_ARID_DEF.OutData_f = (uint16)
              ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
          }
        } else {
          ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_Delay;
        }
      }
      break;

     case ME11_IN_DontChange:
      rtb_Divide1_f = (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h - 20U;
      if ((uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h - 20U > (uint16)
          ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h) {
        rtb_Divide1_f = 0U;
      }

      if (AC_rSunloadFlt < (sint32)rtb_Divide1_f) {
        rtb_Divide1_f = ME11_ARID_DEF.count_g + 1U;
        if (ME11_ARID_DEF.count_g + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.count_g = (uint16)rtb_Divide1_f;
        rtb_Divide1_f = cal_UpAndDownStartTime - 10U;
        if (cal_UpAndDownStartTime - 10U > cal_UpAndDownStartTime) {
          rtb_Divide1_f = 0U;
        }

        if (ME11_ARID_DEF.count_g > (sint32)rtb_Divide1_f) {
          ME11_ARID_DEF.is_c41_ME11 = ME11_IN_IncreaseTemp;
          ME11_ARID_DEF.count_g = 0U;
          if (ME11_ARID_DEF.count_g > cal_RiseTime2Solar) {
            ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_Delaychecked;
            ME11_ARID_DEF.count_g = 0U;
            rtb_Divide1_f = (uint32)(uint16)
              ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h - cal_SolarRiseStep;
            if (rtb_Divide1_f > (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h)
            {
              rtb_Divide1_f = 0U;
            }

            if (AC_rSunloadFlt < (sint32)rtb_Divide1_f) {
              rtb_Divide1_f = (uint32)AC_rSunloadFlt + cal_SolarRiseStep;
              if (rtb_Divide1_f > 65535U) {
                rtb_Divide1_f = 65535U;
              }

              ME11_ARID_DEF.OutData_f = (uint16)rtb_Divide1_f;
            } else {
              ME11_ARID_DEF.OutData_f = (uint16)
                ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
            }
          } else {
            ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_Delay;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     default:
      if (AC_rSunloadFlt >= (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h) {
        ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_c41_ME11 = ME11_IN_DontChange;
        ME11_ARID_DEF.count_g = 0U;
      } else {
        rtb_Divide1_f = ME11_ARID_DEF.count_g + 1U;
        if (ME11_ARID_DEF.count_g + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.count_g = (uint16)rtb_Divide1_f;
        if (ME11_ARID_DEF.is_IncreaseTemp_g == ME11_IN_Delay) {
          if (ME11_ARID_DEF.count_g > cal_RiseTime2Solar) {
            ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_Delaychecked;
            ME11_ARID_DEF.count_g = 0U;
            rtb_Divide1_f = (uint32)(uint16)
              ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h - cal_SolarRiseStep;
            if (rtb_Divide1_f > (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h)
            {
              rtb_Divide1_f = 0U;
            }

            if (AC_rSunloadFlt < (sint32)rtb_Divide1_f) {
              rtb_Divide1_f = (uint32)AC_rSunloadFlt + cal_SolarRiseStep;
              if (rtb_Divide1_f > 65535U) {
                rtb_Divide1_f = 65535U;
              }

              ME11_ARID_DEF.OutData_f = (uint16)rtb_Divide1_f;
            } else {
              ME11_ARID_DEF.OutData_f = (uint16)
                ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
            }
          } else {
            ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_Delay;
          }
        } else if (ME11_ARID_DEF.count_g > cal_RiseTime2Solar) {
          ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_Delaychecked;
          ME11_ARID_DEF.count_g = 0U;
          rtb_Divide1_f = (uint32)(uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h
            - cal_SolarRiseStep;
          if (rtb_Divide1_f > (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h) {
            rtb_Divide1_f = 0U;
          }

          if (AC_rSunloadFlt < (sint32)rtb_Divide1_f) {
            rtb_Divide1_f = (uint32)AC_rSunloadFlt + cal_SolarRiseStep;
            if (rtb_Divide1_f > 65535U) {
              rtb_Divide1_f = 65535U;
            }

            ME11_ARID_DEF.OutData_f = (uint16)rtb_Divide1_f;
          } else {
            ME11_ARID_DEF.OutData_f = (uint16)
              ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
          }
        } else {
          ME11_ARID_DEF.is_IncreaseTemp_g = ME11_IN_Delay;
        }
      }
      break;
    }

    if (guard1) {
      rtb_Divide1_f = (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h + 20U;
      if ((uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h + 20U > 65535U) {
        rtb_Divide1_f = 65535U;
      }

      if (AC_rSunloadFlt > (sint32)rtb_Divide1_f) {
        rtb_Divide1_f = ME11_ARID_DEF.count_g + 1U;
        if (ME11_ARID_DEF.count_g + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.count_g = (uint16)rtb_Divide1_f;
        if (ME11_ARID_DEF.count_g > cal_UpAndDownStartTime) {
          ME11_ARID_DEF.is_c41_ME11 = ME11_IN_DecreaseTemp;
          ME11_ARID_DEF.count_g = 0U;
          if (ME11_ARID_DEF.count_g > cal_FalseTime2Solar) {
            ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_Delaychecked;
            ME11_ARID_DEF.count_g = 0U;
            rtb_Divide1_f = (uint32)(uint16)
              ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h + cal_SolarFalseStep;
            if (rtb_Divide1_f > 65535U) {
              rtb_Divide1_f = 65535U;
            }

            if (AC_rSunloadFlt > (sint32)rtb_Divide1_f) {
              rtb_Divide1_f = (uint32)AC_rSunloadFlt - cal_SolarFalseStep;
              if (rtb_Divide1_f > AC_rSunloadFlt) {
                rtb_Divide1_f = 0U;
              }

              ME11_ARID_DEF.OutData_f = (uint16)rtb_Divide1_f;
            } else {
              ME11_ARID_DEF.OutData_f = (uint16)
                ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_h;
            }
          } else {
            ME11_ARID_DEF.is_DecreaseTemp_ji = ME11_IN_Delay;
          }
        }
      }
    }
  }

  if (ME11_ARID_DEF.OutData_f > 1200) {
    AC_rSunloadFlt = 1200U;
  } else if (ME11_ARID_DEF.OutData_f < 20) {
    AC_rSunloadFlt = 20U;
  } else {
    AC_rSunloadFlt = ME11_ARID_DEF.OutData_f;
  }

  ACDVTPreSetSolarCor = look2_iu16flftf_binlca(AC_rSunloadFlt, AC_tEnvInvent, (
    const uint16 *)&cal_ACDVTPreSetSolarCor_2X[0], (const float32 *)
    &cal_ACDVTPreSetSolarCor_2Y[0], (const float32 *)
    &cal_ACDVTPreSetSolarCor_MAP[0],
    ME11_ConstP.cal_ACDVTPreSetSolarCor_MAP_maxIndex, 8U);
  ACDVTPreSetSolarCorByVx = look2_iu16flftf_binlca(AC_rSunloadFlt,
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpd_kph, (const uint16 *)&cal_ACDVTPreSetSolarCorByVx_2X[0], (
    const float32 *)&cal_ACDVTPreSetSolarCorByVx_2Y[0], (const float32 *)
    &cal_ACDVTPreSetSolarCorByVx_MAP[0], ME11_ConstP.pooled37, 6U);
  ACCCtl_sACCabinPreSetByEnv = look2_iflf_binlca(AC_tEnvInvent,
    HMICtl_sLeftSetPoint, (const float32 *)&cal_ACCabinPreSetByEnv_2X[0], (const
    float32 *)&cal_ACCabinPreSetByEnv_2Y[0], (const float32 *)
    &cal_ACCabinPreSetByEnv_MAP[0], ME11_ConstP.pooled38, 12U);
  CabinDesTempSolarCor = look2_iu16flftf_binlca(AC_rSunloadFlt, AC_tEnvInvent, (
    const uint16 *)&cal_CabinDesTempSolarCor_2X[0], (const float32 *)
    &cal_CabinDesTempSolarCor_2Y[0], (const float32 *)
    &cal_CabinDesTempSolarCor_MAP[0], ME11_ConstP.pooled36, 14U);
  if (HMICtl_eACSts == 0) {
    rtb_DataTypeConversion_f = 2U;
  } else {
    rtb_DataTypeConversion_f = (uint8)(HMICtl_eACSts - 1);
  }

  ACCCtl_sACCabinPreSetByEnvECO = look2_iflf_binlca(AC_tEnvInvent,
    HMICtl_sLeftSetPoint, (const float32 *)&cal_ACCabinPreSetByEnvECO_2X[0], (
    const float32 *)&cal_ACCabinPreSetByEnvECO_2Y[0], (const float32 *)
    &cal_ACCabinPreSetByEnvECO_MAP[0], ME11_ConstP.pooled38, 12U);
  CabinDesTempSolarCorECO = look2_iu16flftf_binlca(AC_rSunloadFlt, AC_tEnvInvent,
    (const uint16 *)&cal_CabinDesTempSolarCorECO_2X[0], (const float32 *)
    &cal_CabinDesTempSolarCorECO_2Y[0], (const float32 *)
    &cal_CabinDesTempSolarCorECO_MAP[0], ME11_ConstP.pooled36, 14U);
  if (rtb_DataTypeConversion_f != ACEconMode_Economy) {
    ACCtl_tDesFrontCabin = ACCCtl_sACCabinPreSetByEnv + CabinDesTempSolarCor;
  } else {
    ACCtl_tDesFrontCabin = ACCCtl_sACCabinPreSetByEnvECO +
      CabinDesTempSolarCorECO;
  }

  AC_DVTPreSetByEnv = look2_iflf_binlca(ACCtl_tDesFrontCabin, AC_tEnvInvent, (
    const float32 *)&cal_ACDVTPreSetByEnv_2X[0], (const float32 *)
    &cal_ACDVTPreSetByEnv_2Y[0], (const float32 *)&cal_ACDVTPreSetByEnv_MAP[0],
    ME11_ConstP.pooled34, 10U);
  ACCtl_tDVTFeedfoward = ((look1_iflf_binlca(AC_tEnvInvent, (const float32 *)
    &cal_ACDVTPreSetEnvCor_1X[0], (const float32 *)&cal_ACDVTPreSetEnvCor_CUR[0],
    15U) + ACDVTPreSetSolarCor) + ACDVTPreSetSolarCorByVx) + AC_DVTPreSetByEnv;
  if (ACCtl_tDVTFeedfoward > 80.0F) {
    ACCtl_tDVTFeedfoward = 80.0F;
  } else if (ACCtl_tDVTFeedfoward < -40.0F) {
    ACCtl_tDVTFeedfoward = -40.0F;
  }

  SENCtl_uCabinVoltage = get_CabinValtage();
  rtb_Delay1_ie = (float32)((sint16)SENCtl_uCabinVoltage -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uCabinVoltage, (const uint16 *)
    &cal_CabinVolAmend_1X[0], (const sint16 *)&cal_CabinVolAmend_CUR[0], 1U));
  ME11_Judge(rtb_Delay1_ie > cal_SensorTempUpFlt, rtb_Delay1_ie <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts_k,
             &ME11_ARID_DEF.ARID_DEF_Judge_d);
  ACSen_eCabinSenSts = ME11_ARID_DEF.SenSts_k;
  rtb_Compare = (uint8)(ACSen_eCabinSenSts == Ground);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941211), rtb_Compare);
  rtb_Compare_ij = (uint8)(ACSen_eCabinSenSts == Power);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941215), rtb_Compare_ij);
  rtb_Delay_ci = cal_ADCVCCVal - rtb_Delay1_ie;
  if (rtb_Delay_ci > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay1_ie / rtb_Delay_ci;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  SEN_TCabinRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 3.0F, (const
    float32 *)&cal_TCabinRaw_1X[0], (const float32 *)&cal_TCabinRaw_CUR[0], 26U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_c != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_o = SEN_TCabinRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_o = SEN_TCabinRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_o * 0.100000024F;
  if (cal_CabinTempEnb) {
    ACSen_sCabinTempFilter = cal_CabinTempData;
  } else {
    ACSen_sCabinTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_o;
  }

  ACTCtl_bCabinFltFlg = (ACSen_eCabinSenSts != Normal);
  rtb_Compare_ly = ((!ACTCtl_bCabinFltFlg) && (ME11_ARID_DEF.Switch1_nv != ACOff)
                    && ME11_ARID_DEF.Switch_c);
  rtb_Delay1_ie = ME11_ARID_DEF.UnitDelay3_DSTATE;
  if (ACSen_sCabinTempFilter > ACCtl_tDesFrontCabin) {
    ME11_ARID_DEF.UnitDelay3_DSTATE = ACSen_sCabinTempFilter -
      ACCtl_tDesFrontCabin;
  } else {
    ME11_ARID_DEF.UnitDelay3_DSTATE = ACCtl_tDesFrontCabin -
      ACSen_sCabinTempFilter;
  }

  rtb_LogicalOperator_j0 = ((HMICtl_sLeftSetPoint !=
    ME11_ARID_DEF.DelayInput1_DSTATE) || (HMICtl_sLeftSetPoint !=
    ME11_ARID_DEF.DelayInput1_DSTATE_j) || ((sint32)rtb_Compare_ly > (sint32)
    ME11_ARID_DEF.DelayInput1_DSTATE_gyl) || (((rtb_Delay1_ie >
    ME11_ARID_DEF.UnitDelay3_DSTATE + 1.0F) || (ME11_ARID_DEF.UnitDelay3_DSTATE >
    ME11_ARID_DEF.UnitDelay2_DSTATE + 1.0F)) && (ME11_ARID_DEF.UnitDelay3_DSTATE
    > ME11_ARID_DEF.DelayInput1_DSTATE_d)));
  if (rtb_LogicalOperator_j0 || (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_j != 0)) {
    rtb_Add_ax = ACSen_sCabinTempFilter;
  } else {
    rtb_Add_ax = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ma;
  }

  if (ACCtl_tDesFrontCabin > ME11_ARID_DEF.UnitDelay1_DSTATE) {
    rtb_Gain8 = ACCtl_tDesFrontCabin - ME11_ARID_DEF.UnitDelay1_DSTATE;
  } else {
    rtb_Gain8 = ME11_ARID_DEF.UnitDelay1_DSTATE - ACCtl_tDesFrontCabin;
  }

  SENCtl_uFaceDuctVal = get_FaceDuctValtage();
  rtb_Delay1_ie = (float32)((sint16)SENCtl_uFaceDuctVal -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uFaceDuctVal, (const uint16 *)
    &cal_FaceDuctVolAmend_1X[0], (const sint16 *)&cal_FaceDuctVolAmend_CUR[0],
    1U));
  rtb_Delay_ci = cal_ADCVCCVal - rtb_Delay1_ie;
  ME11_Judge(rtb_Delay1_ie > cal_SensorTempUpFlt, rtb_Delay1_ie <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts_c,
             &ME11_ARID_DEF.ARID_DEF_Judge_j);
  ACSen_eFaceDuctSenSts = ME11_ARID_DEF.SenSts_c;
  if (rtb_Delay_ci > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay1_ie / rtb_Delay_ci;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  rtb_Delay1_ie = rtb_DataTypeConversion23 * 10.0F;
  rtb_OR_i4 = (ACSen_eFaceDuctSenSts != Normal);
  SENCtl_uFootDuctVal = get_FootDuctValtage();
  rtb_Delay_ci = (float32)((sint16)SENCtl_uFootDuctVal -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uFootDuctVal, (const uint16 *)
    &cal_FootDuctVolAmend_1X[0], (const sint16 *)&cal_FootDuctVolAmend_CUR[0],
    1U));
  rtb_Add = cal_ADCVCCVal - rtb_Delay_ci;
  ME11_Judge(rtb_Delay_ci > cal_SensorTempUpFlt, rtb_Delay_ci <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts_no,
             &ME11_ARID_DEF.ARID_DEF_Judge_l);
  ACSen_eFootDuctSenSts = ME11_ARID_DEF.SenSts_no;
  if (rtb_Add > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay_ci / rtb_Add;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  rtb_Compare_fe4 = (ACSen_eFootDuctSenSts != Normal);
  rtb_RelationalOperator_kh = (rtb_OR_i4 || rtb_Compare_fe4);
  rtb_Delay_n2 = ME11_ARID_DEF.Delay_DSTATE_fl;
  SEN_TDuctRaw = look1_iflf_binlca(rtb_Delay1_ie, (const float32 *)
    &cal_TDuctRaw_1X[0], (const float32 *)&cal_TDuctRaw_CUR[0], 25U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_e != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_n = SEN_TDuctRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_n = SEN_TDuctRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_n * 0.100000024F;
  if (cal_FaceDuctTempEnb) {
    ACSen_sFaceDuctTempFilter = cal_FaceDuctTempData;
  } else {
    ACSen_sFaceDuctTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_n;
  }

  SEN_TFootDuctRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 10.0F, (const
    float32 *)&cal_TDuctRaw_1X[0], (const float32 *)&cal_TDuctRaw_CUR[0], 25U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_a != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_j = SEN_TFootDuctRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_j = SEN_TFootDuctRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_j * 0.100000024F;
  if (cal_FootDuctTempEnb) {
    ACSen_sFootDuctTempFilter = cal_FootDuctTempData;
  } else {
    ACSen_sFootDuctTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_j;
  }

  if (rtb_RelationalOperator_kh) {
    ACCtl_tLeftDuct = cal_DrDuctSenFailDeflt;
  } else {
    switch (ME11_ARID_DEF.Delay_DSTATE_fl) {
     case BlowerModes_FaceMode:
      ACCtl_tLeftDuct = ACSen_sFaceDuctTempFilter;
      break;

     case BlowerModes_FaceHeaterMode:
      ACCtl_tLeftDuct = ACSen_sFaceDuctTempFilter * cal_DrDuctFaceFloorFaFactor
        + ACSen_sFootDuctTempFilter * cal_DrDuctFaceFloorFoFactor;
      break;

     case BlowerModes_HeaterMode:
      ACCtl_tLeftDuct = ACSen_sFootDuctTempFilter;
      break;

     case BlowerModes_HeaterDeforstMode:
      ACCtl_tLeftDuct = ACSen_sFootDuctTempFilter;
      break;

     case BlowerModes_DeforstMode:
      ACCtl_tLeftDuct = 0.0F;
      break;

     default:
      ACCtl_tLeftDuct = 0.0F;
      break;
    }
  }

  if (rtb_Gain8 <= 0.5F) {
    rtb_Gain8 = 0.0F;
  } else {
    rtb_Gain8 = look1_iflf_binlca(ACCtl_tLeftDuct - ACSen_sCabinTempFilter, (
      const float32 *)&cal_CabinTempDuctUpStepCor_1X[0], (const float32 *)
      &cal_CabinTempDuctUpStepCor_CUR[0], 9U);
  }

  rtb_Add_ax += rtb_Gain8;
  if (rtb_Add_ax > 80.0F) {
    ME11_ARID_DEF.UnitDelay1_DSTATE = 80.0F;
  } else if (rtb_Add_ax < -40.0F) {
    ME11_ARID_DEF.UnitDelay1_DSTATE = -40.0F;
  } else {
    ME11_ARID_DEF.UnitDelay1_DSTATE = rtb_Add_ax;
  }

  if (cal_CabinTCorSelect != 0) {
    GlbDa_tCabinInvent = ME11_ARID_DEF.UnitDelay1_DSTATE;
  } else {
    GlbDa_tCabinInvent = ACSen_sCabinTempFilter;
  }

  if (cal_FixPIDSecletFlag) {
    rtb_Delay1_ie = ACCtl_tDesFrontCabin - GlbDa_tCabinInvent;
    ACCtl_DVTIDeadBand = cal_DvtDesValPIDIntegDeadBand;
    ME11_deadzone(rtb_Delay1_ie, 0.5F, &rtb_flag_ko);
    ACCtl_tErrDVTFlag = (ACCtl_tDesFrontCabin >= GlbDa_tCabinInvent);
    if (rtb_flag_ko) {
      ACCtl_tErrDVT = 0.0F;
    } else if (ACCtl_tErrDVTFlag) {
      ACCtl_tErrDVT = rtb_Delay1_ie;
    } else {
      ACCtl_tErrDVT = GlbDa_tCabinInvent - ACCtl_tDesFrontCabin;
    }

    rtb_Delay_ci = look1_iflf_binlca(rtb_Delay1_ie, (const float32 *)
      &cal_DvtDesValPIDKi_1X[0], (const float32 *)&cal_DvtDesValPIDKi_CUR[0], 8U);
    ME11_P_NEG(!ACCtl_tErrDVTFlag, ACCtl_tErrDVT, ACCtl_DVTIDeadBand,
               rtb_Delay_ci, cal_DvtDesValPID_Ki, (float32 *)&ACCtl_tDvtICor);
    ME11_P_POS(ACCtl_tErrDVTFlag, ACCtl_tErrDVT, ACCtl_DVTIDeadBand,
               rtb_Delay_ci, cal_DvtDesValPID_Ki, (float32 *)&ACCtl_tDvtICor);
    if (ACCtl_tErrDVTFlag) {
      rtb_MultiportSwitch2_e = ACCtl_tErrDVT;
    } else {
      rtb_MultiportSwitch2_e = 0.0F;
    }

    PidCabinX_IsumMax = look1_iflf_binlca(rtb_MultiportSwitch2_e, (const float32
      *)&cal_DvtDesIsumMaxByCabinTDiff_1X[0], (const float32 *)
      &cal_DvtDesIsumMaxByCabinTDiff_CUR[0], 7U);
    if (ACCtl_tErrDVTFlag) {
      rtb_MultiportSwitch2_e = 0.0F;
    } else {
      rtb_MultiportSwitch2_e = ACCtl_tErrDVT;
    }

    PidCabinX_IsumMin = look1_iflf_binlca(rtb_MultiportSwitch2_e, (const float32
      *)&cal_DvtDesIsumMinByCabinTDiff_1X[0], (const float32 *)
      &cal_DvtDesIsumMinByCabinTDiff_CUR[0], 7U);
    if (rtb_Compare_ly) {
      switch (ME11_ARID_DEF.Delay_DSTATE_e1) {
       case 0:
        if (ACCtl_tErrDVTFlag) {
          ACCtl_tDvtISum = ACCtl_tDvtISum + ACCtl_tDvtICor;
        } else {
          ACCtl_tDvtISum = ACCtl_tDvtISum - ACCtl_tDvtICor;
        }
        break;

       case 1:
        if (!ACCtl_tErrDVTFlag) {
          ACCtl_tDvtISum = ACCtl_tDvtISum - ACCtl_tDvtICor;
        }
        break;

       case 2:
        if (ACCtl_tErrDVTFlag) {
          ACCtl_tDvtISum = ACCtl_tDvtISum + ACCtl_tDvtICor;
        }
        break;

       case 3:
        break;
      }

      if (ACCtl_tDvtISum > PidCabinX_IsumMax) {
        ACCtl_tDvtISum = PidCabinX_IsumMax;
      } else if (ACCtl_tDvtISum < PidCabinX_IsumMin) {
        ACCtl_tDvtISum = PidCabinX_IsumMin;
      }
    } else {
      ACCtl_tDvtISum = 0.0F;
    }

    ME11_PI_Controller1(!rtb_Compare_ly, ACCtl_tDVTFeedfoward, (float32 *)
                        &ACCtl_tDVTPIBas, (uint8 *)&ACCtl_stDvtPIDFreez);
    rtb_Delay1_ie = look1_iflf_binlca(rtb_Delay1_ie, (const float32 *)
      &cal_DvtDesValPIDKp_1X[0], (const float32 *)&cal_DvtDesValPIDKp_CUR[0], 8U);
    ME11_P_NEG_p(!ACCtl_tErrDVTFlag, ACCtl_tErrDVT, cal_DvtDesValPID_pWinNeg,
                 rtb_Delay1_ie, cal_DvtDesValPID_Kp, (float32 *)&ACCtl_tDvtPCor);
    ME11_P_POS_l(ACCtl_tErrDVTFlag, ACCtl_tErrDVT, cal_DvtDesValPID_pWinPos,
                 rtb_Delay1_ie, cal_DvtDesValPID_Kp, (float32 *)&ACCtl_tDvtPCor);
    if (ACCtl_tErrDVTFlag) {
      rtb_MultiportSwitch2_e = ACCtl_tErrDVT;
    } else {
      rtb_MultiportSwitch2_e = 0.0F;
    }

    AC_PidCabinT_UL = look2_iflf_binlca(rtb_MultiportSwitch2_e,
      ACSen_sEnvTempCor, (const float32 *)&cal_DvtDesLmtByCabinTDiff_2X[0], (
      const float32 *)&cal_DvtDesLmtByCabinTDiff_2Y[0], (const float32 *)
      &cal_DvtDesLmtByCabinTDiff_MAP[0], ME11_ConstP.pooled34, 10U);
    ME11_PI_Controller(rtb_Compare_ly, ACCtl_tErrDVTFlag, ACCtl_tDVTFeedfoward,
                       ACCtl_tDvtPCor, ACCtl_tDvtISum, AC_PidCabinT_UL,
                       cal_DvtDesValPID_LL, (float32 *)&ACCtl_tDVTPIBas, (uint8 *)
                       &ACCtl_stDvtPIDFreez);
    ME11_ARID_DEF.Delay_DSTATE_e1 = ACCtl_stDvtPIDFreez;
  }

  if (HMICtl_bLeftSetLow) {
    ACCtl_tPsDVT = cal_DvtDesValPID_LL;
  } else if (HMICtl_bLeftSetHigh) {
    ACCtl_tPsDVT = cal_DvtDesValPID_UL;
  } else {
    ACCtl_tPsDVT = (ACCtl_tPsDVTCabinCor + ACCtl_tPsDVTSolarCor) +
      ACCtl_tDVTPIBas;
    if (ACCtl_tPsDVT > cal_DvtDesValPID_UL) {
      ACCtl_tPsDVT = cal_DvtDesValPID_UL;
    } else if (ACCtl_tPsDVT < cal_DvtDesValPID_LL) {
      ACCtl_tPsDVT = cal_DvtDesValPID_LL;
    }
  }

  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ec != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_d = AC_rSolarRight;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_d = (1.0F - cal_U_DVTFFSolarFilterRate) *
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_d + (float32)AC_rSolarRight *
    cal_U_DVTFFSolarFilterRate;
  GlbDa_LeftSolar = (uint16)ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_d;
  ACCtl_tDrDVTSolarCor = look2_iu16flftf_binlca(GlbDa_LeftSolar,
    ACSen_sEnvTempCor, (const uint16 *)&cal_ACDrDVTSolarCor_2X[0], (const
    float32 *)&cal_ACDrDVTSolarCor_2Y[0], (const float32 *)
    &cal_ACDrDVTSolarCor_MAP[0], ME11_ConstP.pooled33, 15U);
  if (HMICtl_bLeftSetLow) {
    ACCtl_tDrDVT = cal_DvtDesValPID_LL;
  } else if (HMICtl_bLeftSetHigh) {
    ACCtl_tDrDVT = cal_DvtDesValPID_UL;
  } else {
    ACCtl_tDrDVT = ACCtl_tDrDVTSolarCor + ACCtl_tDVTPIBas;
    if (ACCtl_tDrDVT > cal_DvtDesValPID_UL) {
      ACCtl_tDrDVT = cal_DvtDesValPID_UL;
    } else if (ACCtl_tDrDVT < cal_DvtDesValPID_LL) {
      ACCtl_tDrDVT = cal_DvtDesValPID_LL;
    }
  }

  if (ACCtl_tPsDVT >= ACCtl_tDrDVT) {
    rtb_Gain8 = ACCtl_tPsDVT;
  } else {
    rtb_Gain8 = ACCtl_tDrDVT;
  }

  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kj != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn = rtb_Gain8;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn = (1.0F - cal_DvtCoff) *
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn + rtb_Gain8 * cal_DvtCoff;
  SOMCtl_sF1Value = ACSen_sEnvTempCor * cal_CabinModeTransF1Slope +
    cal_CabinModeTransF1Constant;
  if (ME11_ARID_DEF.is_active_c14_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c14_ME11 = 1U;
    ME11_ARID_DEF.is_c14_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD1CLMSts = false;
  } else if (ME11_ARID_DEF.is_c14_ME11 == ME11_IN_Off_a) {
    SOMCtl_bMD1CLMSts = false;
    if ((rtb_AND_hi && rtb_FixPtRelationalOperator_dx &&
         (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn < SOMCtl_sF1Value)) ||
        (cal_tCabinCoolEnvTempHigh <= ACSen_sEnvTempCor)) {
      ME11_ARID_DEF.is_c14_ME11 = ME11_IN_On_li;
      SOMCtl_bMD1CLMSts = true;
    }
  } else {
    SOMCtl_bMD1CLMSts = true;
    rtb_MultiportSwitch2_e = cal_tCabinCoolEnvTempLow - cal_CabinHys1TempOffset;
    if ((rtb_MultiportSwitch2_e > ACSen_sEnvTempCor) || ((rtb_MultiportSwitch2_e
          <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor <
          cal_tCabinCoolEnvTempHigh - cal_CabinHys1TempOffset) &&
         (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn >= SOMCtl_sF1Value +
          cal_CabinHys2TempOffset))) {
      ME11_ARID_DEF.is_c14_ME11 = ME11_IN_Off_a;
      SOMCtl_bMD1CLMSts = false;
    }
  }

  SOMCtl_sF2Value = ACSen_sEnvTempCor * cal_CabinModeTransF2Slope +
    cal_CabinModeTransF2Constant;
  if (ME11_ARID_DEF.is_active_c15_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c15_ME11 = 1U;
    ME11_ARID_DEF.is_c15_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD2DHMD1Flg = false;
  } else if (ME11_ARID_DEF.is_c15_ME11 == ME11_IN_Off_a) {
    SOMCtl_bMD2DHMD1Flg = false;
    if (((cal_tCabinCoolEnvTempLow <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor <
          cal_CabinMD2F2MaxEnvTemp) && ((SOMCtl_sF2Value >=
           ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn) &&
          (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn >= SOMCtl_sF1Value))) ||
        ((cal_tCabinCoolEnvTempHigh > ACSen_sEnvTempCor) && (ACSen_sEnvTempCor >=
          cal_CabinMD2F2MaxEnvTemp) && (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn <=
          SOMCtl_sF1Value))) {
      ME11_ARID_DEF.is_c15_ME11 = ME11_IN_On_li;
      SOMCtl_bMD2DHMD1Flg = true;
    }
  } else {
    SOMCtl_bMD2DHMD1Flg = true;
    rtb_MultiportSwitch2_e = cal_tCabinCoolEnvTempHigh + cal_CabinHys1TempOffset;
    rtb_DataTypeConversion23 = cal_tCabinCoolEnvTempLow -
      cal_CabinHys1TempOffset;
    if ((rtb_MultiportSwitch2_e <= ACSen_sEnvTempCor) ||
        ((rtb_DataTypeConversion23 <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor <
          rtb_MultiportSwitch2_e) && (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn <
          SOMCtl_sF1Value - cal_CabinHys2TempOffset)) ||
        ((rtb_DataTypeConversion23 <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor <
          cal_CabinMD2F2MaxEnvTemp - cal_CabinHys1TempOffset) &&
         (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn >= SOMCtl_sF2Value +
          cal_CabinHys2TempOffset)) || (rtb_DataTypeConversion23 >
         ACSen_sEnvTempCor)) {
      ME11_ARID_DEF.is_c15_ME11 = ME11_IN_Off_a;
      SOMCtl_bMD2DHMD1Flg = false;
    }
  }

  if (ME11_ARID_DEF.is_active_c16_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c16_ME11 = 1U;
    ME11_ARID_DEF.is_c16_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD3DHMD2Flg = false;
  } else if (ME11_ARID_DEF.is_c16_ME11 == ME11_IN_Off_a) {
    SOMCtl_bMD3DHMD2Flg = false;
    if ((cal_tCabinCoolEnvTempLow <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor <
         cal_CabinMD2F2MaxEnvTemp) && (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn >=
         SOMCtl_sF2Value)) {
      ME11_ARID_DEF.is_c16_ME11 = ME11_IN_On_li;
      SOMCtl_bMD3DHMD2Flg = true;
    }
  } else {
    SOMCtl_bMD3DHMD2Flg = true;
    rtb_MultiportSwitch2_e = cal_tCabinCoolEnvTempLow - cal_CabinHys1TempOffset;
    rtb_DataTypeConversion23 = cal_CabinMD2F2MaxEnvTemp +
      cal_CabinHys1TempOffset;
    if ((rtb_MultiportSwitch2_e > ACSen_sEnvTempCor) || ((rtb_MultiportSwitch2_e
          <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor < rtb_DataTypeConversion23)
         && (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn < SOMCtl_sF2Value -
             cal_CabinHys2TempOffset)) || (rtb_DataTypeConversion23 <=
         ACSen_sEnvTempCor)) {
      ME11_ARID_DEF.is_c16_ME11 = ME11_IN_Off_a;
      SOMCtl_bMD3DHMD2Flg = false;
    }
  }

  if (ME11_ARID_DEF.is_active_c17_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c17_ME11 = 1U;
    ME11_ARID_DEF.is_c17_ME11 = ME11_IN_Off_a;
    rtb_FixPtRelationalOperator_dx = false;
  } else if (ME11_ARID_DEF.is_c17_ME11 == ME11_IN_Off_a) {
    rtb_FixPtRelationalOperator_dx = false;
    if (cal_tCabinCoolEnvTempLow > ACSen_sEnvTempCor) {
      ME11_ARID_DEF.is_c17_ME11 = ME11_IN_On_li;
      rtb_FixPtRelationalOperator_dx = true;
    }
  } else {
    rtb_FixPtRelationalOperator_dx = true;
    if (cal_tCabinCoolEnvTempLow + cal_CabinHys1TempOffset <= ACSen_sEnvTempCor)
    {
      ME11_ARID_DEF.is_c17_ME11 = ME11_IN_Off_a;
      rtb_FixPtRelationalOperator_dx = false;
    }
  }

  rtb_Gain8 = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn - ACCtl_tLeftDuct;
  rtb_Compare_l = (rtb_Gain8 < cal_tCabinCondToCoolDvtDiff);
  rtb_AND_hi = ME11_ARID_DEF.Delay1_DSTATE_b;
  rtb_Divide_ox =
    Rte_IRead_Task_100ms_HP_EXV_CurrentPosition_B_HP_EXV_CurrentPosition_B();
  HP_EXV_CurrentPosition_B = 0.15625F * (float32)rtb_Divide_ox;
  FixPtRelationalOperator = (rtb_Compare_l && (ME11_ARID_DEF.Delay1_DSTATE_b &&
    SOMCtl_bMD1CLMSts && (HP_EXV_CurrentPosition_B >=
    cal_CabinCondToCoolHPEXVPos1)));
  if (ME11_ARID_DEF.temporalCounter_i1_dt < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_dt++;
  }

  if (ME11_ARID_DEF.is_active_c19_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c19_ME11 = 1U;
    ME11_ARID_DEF.is_c19_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.SOMCtl_Two2OneA = false;
  } else {
    switch (ME11_ARID_DEF.is_c19_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.SOMCtl_Two2OneA = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c19_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_dt = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.SOMCtl_Two2OneA = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c19_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.SOMCtl_Two2OneA = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_dt >= 600U) {
        ME11_ARID_DEF.is_c19_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.SOMCtl_Two2OneA = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c19_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.SOMCtl_Two2OneA = false;
      }
      break;
    }
  }

  FixPtRelationalOperator = (HP_EXV_CurrentPosition_B <=
    cal_CabinCondToCoolHPEXVPos2);
  SENCtl_uEVAPSurfTempVol = get_EVAPSurfTempValtage();
  rtb_Delay1_ie = (float32)((sint16)SENCtl_uEVAPSurfTempVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uEVAPSurfTempVol, (const uint16 *)
    &cal_EVAPSurfTempVolAmend_1X[0], (const sint16 *)
    &cal_EVAPSurfTempVolAmend_CUR[0], 1U));
  rtb_Delay_ci = cal_ADCVCCVal - rtb_Delay1_ie;
  ME11_Judge(rtb_Delay1_ie > cal_SensorTempUpFlt, rtb_Delay1_ie <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts_f4,
             &ME11_ARID_DEF.ARID_DEF_Judge_f);
  ACSen_eEVAPSurfTSenSts = ME11_ARID_DEF.SenSts_f4;
  if (rtb_Delay_ci > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay1_ie / rtb_Delay_ci;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  SEN_TEvapSurRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 3.0F, (const
    float32 *)&cal_TEvapSurfRaw_1X[0], (const float32 *)&cal_TEvapSurfRaw_CUR[0],
    22U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_jm != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a = SEN_TEvapSurRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a = SEN_TEvapSurRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a * 0.100000024F;
  if (cal_EvapSurTempDataEnb) {
    ACSen_sEvapSurTemp = cal_EvapSurTempData;
  } else {
    ACSen_sEvapSurTemp = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a;
  }

  FixPtRelationalOperator = (FixPtRelationalOperator && rtb_Compare_l &&
    (SOMCtl_bMD1CLMSts && (ACSen_sEvapSurTemp <= cal_tCabinCondToCoolEvapTemp)));
  if (ME11_ARID_DEF.temporalCounter_i1_h2 < 511U) {
    ME11_ARID_DEF.temporalCounter_i1_h2++;
  }

  if (ME11_ARID_DEF.is_active_c20_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c20_ME11 = 1U;
    ME11_ARID_DEF.is_c20_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.SOMCtl_Two2OneB = false;
  } else {
    switch (ME11_ARID_DEF.is_c20_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.SOMCtl_Two2OneB = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c20_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_h2 = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.SOMCtl_Two2OneB = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c20_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.SOMCtl_Two2OneB = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_h2 >= 300U) {
        ME11_ARID_DEF.is_c20_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.SOMCtl_Two2OneB = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c20_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.SOMCtl_Two2OneB = false;
      }
      break;
    }
  }

  SOMCtl_bMD2ToMD1Flg = (ME11_ARID_DEF.SOMCtl_Two2OneA ||
    ME11_ARID_DEF.SOMCtl_Two2OneB);
  FixPtRelationalOperator = (ME11_ARID_DEF.Delay_DSTATE_he && (rtb_Gain8 >
    cal_tCabinCoolToCondDvtDiff));
  ME11_TMSADCSampleFunc();
  FixPtRelationalOperator = (FixPtRelationalOperator && ((ACSen_sMixDoorPerc >
    cal_rCabinCoolToCondMixDoor) && (!SOMCtl_bMD2DHMD1Flg)));
  if (ME11_ARID_DEF.temporalCounter_i1_en < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_en++;
  }

  if (ME11_ARID_DEF.is_active_c21_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c21_ME11 = 1U;
    ME11_ARID_DEF.is_c21_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD1ToMD2Flg = false;
  } else {
    switch (ME11_ARID_DEF.is_c21_ME11) {
     case ME11_IN_Off_a:
      SOMCtl_bMD1ToMD2Flg = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c21_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_en = 0U;
      }
      break;

     case ME11_IN_On_li:
      SOMCtl_bMD1ToMD2Flg = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c21_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD1ToMD2Flg = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_en >= 600U) {
        ME11_ARID_DEF.is_c21_ME11 = ME11_IN_On_li;
        SOMCtl_bMD1ToMD2Flg = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c21_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD1ToMD2Flg = false;
      }
      break;
    }
  }

  COMP_EcompActSpd = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPEcompActSpd_rpm;
  rtb_Compare_l = (COMP_EcompActSpd < cal_CabinEvpToCondCompLmt);
  FixPtRelationalOperator = (((ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn -
    ACSen_sFaceDuctTempFilter < cal_tCabinEvpToCondDvtDiff) ||
    (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn - ACSen_sFootDuctTempFilter <
     cal_tCabinEvpToCondDvtDiff)) && (ME11_ARID_DEF.Delay_DSTATE_d2 &&
    SOMCtl_bMD2DHMD1Flg && rtb_Compare_l));
  if (ME11_ARID_DEF.temporalCounter_i1_e < 511U) {
    ME11_ARID_DEF.temporalCounter_i1_e++;
  }

  if (ME11_ARID_DEF.is_active_c22_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c22_ME11 = 1U;
    ME11_ARID_DEF.is_c22_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD3ToMD2Flg = false;
  } else {
    switch (ME11_ARID_DEF.is_c22_ME11) {
     case ME11_IN_Off_a:
      SOMCtl_bMD3ToMD2Flg = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c22_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_e = 0U;
      }
      break;

     case ME11_IN_On_li:
      SOMCtl_bMD3ToMD2Flg = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c22_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD3ToMD2Flg = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_e >= 300U) {
        ME11_ARID_DEF.is_c22_ME11 = ME11_IN_On_li;
        SOMCtl_bMD3ToMD2Flg = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c22_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD3ToMD2Flg = false;
      }
      break;
    }
  }

  FixPtRelationalOperator = (rtb_Compare_l && SOMCtl_bMD3DHMD2Flg &&
    ((HP_EXV_CurrentPosition_B > cal_CabinCondToEvpHPEXVPos) &&
     (ACSen_sEvapSurTemp <= cal_tCabinCondToEvpEvapTemp)));
  if (ME11_ARID_DEF.temporalCounter_i1_dj < 511U) {
    ME11_ARID_DEF.temporalCounter_i1_dj++;
  }

  if (ME11_ARID_DEF.is_active_c23_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c23_ME11 = 1U;
    ME11_ARID_DEF.is_c23_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD2ToMD3Flg = false;
  } else {
    switch (ME11_ARID_DEF.is_c23_ME11) {
     case ME11_IN_Off_a:
      SOMCtl_bMD2ToMD3Flg = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c23_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_dj = 0U;
      }
      break;

     case ME11_IN_On_li:
      SOMCtl_bMD2ToMD3Flg = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c23_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD2ToMD3Flg = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_dj >= 300U) {
        ME11_ARID_DEF.is_c23_ME11 = ME11_IN_On_li;
        SOMCtl_bMD2ToMD3Flg = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c23_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD2ToMD3Flg = false;
      }
      break;
    }
  }

  FixPtRelationalOperator = ((ACSen_sEnvTempCor > cal_tCabinHPToEvpEnvTemp) &&
    ((ACSen_eAirInletPer > cal_rCabinHPToEvpInnRatio) && SOMCtl_bMD3DHMD2Flg));
  if (ME11_ARID_DEF.temporalCounter_i1_ng < 511U) {
    ME11_ARID_DEF.temporalCounter_i1_ng++;
  }

  if (ME11_ARID_DEF.is_active_c24_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c24_ME11 = 1U;
    ME11_ARID_DEF.is_c24_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD4ToMD3Flg = false;
  } else {
    switch (ME11_ARID_DEF.is_c24_ME11) {
     case ME11_IN_Off_a:
      SOMCtl_bMD4ToMD3Flg = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c24_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_ng = 0U;
      }
      break;

     case ME11_IN_On_li:
      SOMCtl_bMD4ToMD3Flg = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c24_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD4ToMD3Flg = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_ng >= 300U) {
        ME11_ARID_DEF.is_c24_ME11 = ME11_IN_On_li;
        SOMCtl_bMD4ToMD3Flg = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c24_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD4ToMD3Flg = false;
      }
      break;
    }
  }

  FixPtRelationalOperator = ((ACSen_eAirInletPer < cal_rCabinEvpToHPInnRatio) &&
    (rtb_FixPtRelationalOperator_dx && (ACSen_sEnvTempCor <
    cal_CabinEvpToHPEnvTemp)));
  if (ME11_ARID_DEF.temporalCounter_i1_po < 511U) {
    ME11_ARID_DEF.temporalCounter_i1_po++;
  }

  if (ME11_ARID_DEF.is_active_c25_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c25_ME11 = 1U;
    ME11_ARID_DEF.is_c25_ME11 = ME11_IN_Off_a;
    SOMCtl_bMD3ToMD4Flg = false;
  } else {
    switch (ME11_ARID_DEF.is_c25_ME11) {
     case ME11_IN_Off_a:
      SOMCtl_bMD3ToMD4Flg = false;
      if (FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c25_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_po = 0U;
      }
      break;

     case ME11_IN_On_li:
      SOMCtl_bMD3ToMD4Flg = true;
      if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c25_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD3ToMD4Flg = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_po >= 300U) {
        ME11_ARID_DEF.is_c25_ME11 = ME11_IN_On_li;
        SOMCtl_bMD3ToMD4Flg = true;
      } else if (!FixPtRelationalOperator) {
        ME11_ARID_DEF.is_c25_ME11 = ME11_IN_Off_a;
        SOMCtl_bMD3ToMD4Flg = false;
      }
      break;
    }
  }

  if ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
      ->BCM_SysPwrModeV > 0) {
    rtb_Switch2_ht = (Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs
                      ())->BCM_SysPwrMode;
  } else {
    rtb_Switch2_ht = 0U;
  }

  if (ME11_ARID_DEF.is_active_c18_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c18_ME11 = 1U;
    ME11_ARID_DEF.is_c18_ME11 = ME11_IN_Off_a;
    PWRCtl_eTMSStatus_a = 0U;
  } else if (ME11_ARID_DEF.is_c18_ME11 == ME11_IN_Off_a) {
    PWRCtl_eTMSStatus_a = 0U;
    if (ME11_ARID_DEF.Switch_c && (ME11_ARID_DEF.DataTypeConversion1 >= 2) &&
        (rtb_Switch2_ht == 2)) {
      ME11_ARID_DEF.is_c18_ME11 = ME11_IN_On_li;
      ME11_ARID_DEF.is_On = ME11_IN_Standby;
      PWRCtl_eTMSStatus_a = 7U;
    }
  } else if ((!ME11_ARID_DEF.Switch_c) || (ME11_ARID_DEF.DataTypeConversion1 <=
              1) || (rtb_Switch2_ht != 2)) {
    ME11_ARID_DEF.is_Work = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_On = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c18_ME11 = ME11_IN_Off_a;
    PWRCtl_eTMSStatus_a = 0U;
  } else {
    switch (ME11_ARID_DEF.is_On) {
     case ME11_IN_MD5:
      PWRCtl_eTMSStatus_a = 6U;
      if (HMICtl_eACSts != 3) {
        ME11_ARID_DEF.is_On = ME11_IN_Standby;
        PWRCtl_eTMSStatus_a = 7U;
      }
      break;

     case ME11_IN_Standby:
      PWRCtl_eTMSStatus_a = 7U;
      if (HMICtl_eACSts == 3) {
        ME11_ARID_DEF.is_On = ME11_IN_MD5;
        PWRCtl_eTMSStatus_a = 6U;
      } else if (SOMCtl_bMD1CLMSts) {
        ME11_ARID_DEF.is_On = ME11_IN_Work;
        ME11_ARID_DEF.is_Work = ME11_IN_MD1;
        PWRCtl_eTMSStatus_a = 1U;
      } else if (SOMCtl_bMD2DHMD1Flg) {
        ME11_ARID_DEF.is_On = ME11_IN_Work;
        ME11_ARID_DEF.is_Work = ME11_IN_MD2;
        PWRCtl_eTMSStatus_a = 2U;
      } else if (SOMCtl_bMD3DHMD2Flg) {
        ME11_ARID_DEF.is_On = ME11_IN_Work;
        ME11_ARID_DEF.is_Work = ME11_IN_MD3;
        PWRCtl_eTMSStatus_a = 3U;
      } else if (rtb_FixPtRelationalOperator_dx) {
        ME11_ARID_DEF.is_On = ME11_IN_Work;
        ME11_ARID_DEF.is_Work = ME11_IN_MD4;
        PWRCtl_eTMSStatus_a = 4U;
      }
      break;

     default:
      if (HMICtl_eACSts == 3) {
        ME11_ARID_DEF.is_Work = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_On = ME11_IN_MD5;
        PWRCtl_eTMSStatus_a = 6U;
      } else {
        switch (ME11_ARID_DEF.is_Work) {
         case ME11_IN_MD1:
          PWRCtl_eTMSStatus_a = 1U;
          if (!SOMCtl_bMD1CLMSts) {
            ME11_ARID_DEF.is_Work = ME11_IN_NO_ACTIVE_CHILD_gl;
            ME11_ARID_DEF.is_On = ME11_IN_Standby;
            PWRCtl_eTMSStatus_a = 7U;
          } else if (SOMCtl_bMD1ToMD2Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_MD2;
            PWRCtl_eTMSStatus_a = 2U;
          }
          break;

         case ME11_IN_MD2:
          PWRCtl_eTMSStatus_a = 2U;
          if (SOMCtl_bMD2ToMD1Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_MD1;
            PWRCtl_eTMSStatus_a = 1U;
          } else if (SOMCtl_bMD2ToMD3Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_MD3;
            PWRCtl_eTMSStatus_a = 3U;
          } else if (!SOMCtl_bMD2DHMD1Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_NO_ACTIVE_CHILD_gl;
            ME11_ARID_DEF.is_On = ME11_IN_Standby;
            PWRCtl_eTMSStatus_a = 7U;
          }
          break;

         case ME11_IN_MD3:
          PWRCtl_eTMSStatus_a = 3U;
          if (SOMCtl_bMD3ToMD2Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_MD2;
            PWRCtl_eTMSStatus_a = 2U;
          } else if (SOMCtl_bMD3ToMD4Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_MD4;
            PWRCtl_eTMSStatus_a = 4U;
          } else if (!SOMCtl_bMD3DHMD2Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_NO_ACTIVE_CHILD_gl;
            ME11_ARID_DEF.is_On = ME11_IN_Standby;
            PWRCtl_eTMSStatus_a = 7U;
          }
          break;

         default:
          PWRCtl_eTMSStatus_a = 4U;
          if (SOMCtl_bMD4ToMD3Flg) {
            ME11_ARID_DEF.is_Work = ME11_IN_MD3;
            PWRCtl_eTMSStatus_a = 3U;
          } else if (!rtb_FixPtRelationalOperator_dx) {
            ME11_ARID_DEF.is_Work = ME11_IN_NO_ACTIVE_CHILD_gl;
            ME11_ARID_DEF.is_On = ME11_IN_Standby;
            PWRCtl_eTMSStatus_a = 7U;
          }
          break;
        }
      }
      break;
    }
  }

  if (ME11_ARID_DEF.is_active_c38_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c38_ME11 = 1U;
    ME11_ARID_DEF.is_c38_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.ModeSts = PWRCtl_eTMSStatus_a;
  } else if (ME11_ARID_DEF.is_c38_ME11 == ME11_IN_Init_i) {
    if ((PWRCtl_eTMSStatus_a != ME11_ARID_DEF.DelayInput1_DSTATE_h) &&
        ((PWRCtl_eTMSStatus_a != 0) || (PWRCtl_eTMSStatus_a != 7))) {
      ME11_ARID_DEF.is_c38_ME11 = ME11_IN_Wait_o;
      ME11_ARID_DEF.ModeSts = 7U;
      ME11_ARID_DEF.Counter_b = 0U;
    } else {
      ME11_ARID_DEF.ModeSts = PWRCtl_eTMSStatus_a;
    }
  } else if (ME11_ARID_DEF.Counter_b >= (uint32)(cal_CabinModeKeepStandbyTime *
              600.0F)) {
    ME11_ARID_DEF.is_c38_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.ModeSts = PWRCtl_eTMSStatus_a;
  } else {
    rtb_Divide1_f = ME11_ARID_DEF.Counter_b + 1U;
    if (ME11_ARID_DEF.Counter_b + 1U < ME11_ARID_DEF.Counter_b) {
      rtb_Divide1_f = MAX_uint32_T;
    }

    ME11_ARID_DEF.Counter_b = rtb_Divide1_f;
  }

  if (cal_CabinModeEnb) {
    SOMCtl_eCabinMode = cal_CabinModeData;
  } else if (ME11_ARID_DEF.OutportBufferForHMICtl_bPTCOnReq &&
             (!cal_ACCMForbidCtrl)) {
    SOMCtl_eCabinMode = 4U;
  } else {
    SOMCtl_eCabinMode = ME11_ARID_DEF.ModeSts;
  }

  rtb_DataTypeConversion1_on = SOMCtl_eCabinMode;
  BMS_HVBatCellTempMax =
    (Rte_IRead_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT())
    ->VIPM_BMSHVBatCellTempMax_C;
  EXV_ResponseError = Rte_IRead_Task_100ms_EXV_ResponseError_EXV_ResponseError();
  rtb_Compare_cwj = EXV_ResponseError;
  EXV_FaultState = Rte_IRead_Task_100ms_EXV_FaultState_EXV_FaultState();
  rtb_Compare_mcu = (EXV_FaultState != 0);
  EXV_VoltageState = Rte_IRead_Task_100ms_EXV_VoltageState_EXV_VoltageState();
  rtb_Compare_l = (EXV_VoltageState != 0);
  EXV_TemperatureWarn =
    Rte_IRead_Task_100ms_EXV_TemperatureWarn_EXV_TemperatureWarn();
  rtb_Compare_ej = (EXV_TemperatureWarn == 1);
  ACTCtl_bAEXVFaultFlg = (EXV_ResponseError || rtb_Compare_mcu || rtb_Compare_l ||
    rtb_Compare_ej);
  BAT_EXV_ResponseError_B =
    Rte_IRead_Task_100ms_BAT_EXV_ResponseError_B_BAT_EXV_ResponseError_B();
  rtb_Compare_ppz = BAT_EXV_ResponseError_B;
  BAT_EXV_FaultState_B =
    Rte_IRead_Task_100ms_BAT_EXV_FaultState_B_BAT_EXV_FaultState_B();
  rtb_Compare_cz = (BAT_EXV_FaultState_B != 0);
  BAT_EXV_VoltageState_B =
    Rte_IRead_Task_100ms_BAT_EXV_VoltageState_B_BAT_EXV_VoltageState_B();
  rtb_Compare_jac = (BAT_EXV_VoltageState_B != 0);
  BAT_EXV_TemperatureWarn_B = (uint8)
    Rte_IRead_Task_100ms_BAT_EXV_Warning_OverTemp_BAT_EXV_Warning_OverTemp();
  rtb_Compare_lwc = (BAT_EXV_TemperatureWarn_B == 1);
  ACTCtl_bBEXVFaultFlg = (BAT_EXV_ResponseError_B || rtb_Compare_cz ||
    rtb_Compare_jac || rtb_Compare_lwc);
  HP_EXV_ResponseError_B =
    Rte_IRead_Task_100ms_HP_EXV_ResponseError_B_HP_EXV_ResponseError_B();
  rtb_Compare_nzl = HP_EXV_ResponseError_B;
  HP_EXV_VoltageState_B =
    Rte_IRead_Task_100ms_HP_EXV_VoltageState_B_HP_EXV_VoltageState_B();
  rtb_Compare_jkh = (HP_EXV_VoltageState_B != 0);
  HP_EXV_FaultState_B =
    Rte_IRead_Task_100ms_HP_EXV_FaultState_B_HP_EXV_FaultState_B();
  rtb_Compare_d0e = (HP_EXV_FaultState_B != 0);
  HP_EXV_Warning_OverTemp =
    Rte_IRead_Task_100ms_HP_EXV_Warning_OverTemp_HP_EXV_Warning_OverTemp();
  rtb_Compare_mwc = HP_EXV_Warning_OverTemp;
  ACTCtl_bHPEXVFaultFlg = (HP_EXV_ResponseError_B || rtb_Compare_jkh ||
    rtb_Compare_d0e || HP_EXV_Warning_OverTemp);
  BatPMP_RESP_ERROR = Rte_IRead_Task_100ms_BatPMP_RESP_ERROR_BatPMP_RESP_ERROR();
  rtb_FixPtRelationalOperator_dx = BatPMP_RESP_ERROR;
  BatPMP_PumpMotorSta =
    Rte_IRead_Task_100ms_BatPMP_PumpMotorSta_BatPMP_PumpMotorSta();
  FixPtRelationalOperator = (BatPMP_PumpMotorSta != 0);
  BatPMP_PumpDryRunningSta =
    Rte_IRead_Task_100ms_BatPMP_PumpDryRunningSta_BatPMP_PumpDryRunningSta();
  rtb_Delay1_ag = BatPMP_PumpDryRunningSta;
  BatPMP_PumpPowerSta =
    Rte_IRead_Task_100ms_BatPMP_PumpPowerSta_BatPMP_PumpPowerSta();
  rtb_AND1_hh = (BatPMP_PumpPowerSta != 0);
  BatPMP_PumpTempSta =
    Rte_IRead_Task_100ms_BatPMP_PumpTempSta_BatPMP_PumpTempSta();
  rtb_FixPtRelationalOperator_ka = (BatPMP_PumpTempSta != 0);
  rtb_FixPtRelationalOperator_gf = (BatPMP_RESP_ERROR || FixPtRelationalOperator
    || BatPMP_PumpDryRunningSta || rtb_AND1_hh || rtb_FixPtRelationalOperator_ka);
  if (ME11_ARID_DEF.temporalCounter_i1_fo < 127U) {
    ME11_ARID_DEF.temporalCounter_i1_fo++;
  }

  if (ME11_ARID_DEF.is_active_c124_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c124_ME11 = 1U;
    ME11_ARID_DEF.is_c124_ME11 = ME11_IN_Normal_k;
    ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m = false;
  } else {
    switch (ME11_ARID_DEF.is_c124_ME11) {
     case ME11_IN_Fault_ax:
      ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m = true;
      if (!rtb_FixPtRelationalOperator_gf) {
        ME11_ARID_DEF.is_c124_ME11 = ME11_IN_Normal_k;
        ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m = false;
      }
      break;

     case ME11_IN_Normal_k:
      ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m = false;
      if (rtb_FixPtRelationalOperator_gf) {
        ME11_ARID_DEF.is_c124_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_fo = 0U;
      }
      break;

     default:
      if (!rtb_FixPtRelationalOperator_gf) {
        ME11_ARID_DEF.is_c124_ME11 = ME11_IN_Normal_k;
        ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_fo >= 100U) {
        ME11_ARID_DEF.is_c124_ME11 = ME11_IN_Fault_ax;
        ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m = true;
      }
      break;
    }
  }

  if (cal_BatPMPFaultFlgDataEnb) {
    ACTCtl_bBatPMPFaultFlg = cal_BatPMPFaultFlgData;
  } else {
    ACTCtl_bBatPMPFaultFlg = ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_m;
  }

  BMS_HVBatCellTempMin =
    (Rte_IRead_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT())
    ->VIPM_BMSHVBatCellTempMin_C;
  PWRCtl_VCUACCMLimitPwr =
    (Rte_IRead_Task_100ms_Vcu2BcmTms_outputs_Vcu2BcmTms_outputs())
    ->VEMS_HeatCoolMaxPwrCmsp_kW;
  ME11_ARID_DEF.Relay_Mode = ((ACSen_sEnvTempCor >= cal_NmCOMPEnvTempLmtOn) ||
    ((ACSen_sEnvTempCor > cal_NmCOMPEnvTempLmtOff) && ME11_ARID_DEF.Relay_Mode));
  ACTCtl_bCOMPCoolEnvPrtFlg = !ME11_ARID_DEF.Relay_Mode;
  rtb_Delay1_ie = BMS_HVBatCellTempMax - BMS_HVBatCellTempMin;
  rtb_Delay_ci = (float32)fabs(rtb_Delay1_ie);
  rtb_Compare_cd_tmp = (ACTCtl_bAEXVFaultFlg || ACTCtl_bBEXVFaultFlg ||
                        ACTCtl_bHPEXVFaultFlg);
  SOMCtl_eBatCoolB2tB1 = (uint8)((((((uint32)((((BMS_HVBatCellTempMax <=
    cal_tBatCoolDCChrgCellTempOff) && (ME11_ARID_DEF.DataTypeConversion1 == 4)) ||
    ((BMS_HVBatCellTempMax <= cal_tBatCoolACChrgCellTempOff) &&
     (ME11_ARID_DEF.DataTypeConversion1 == 3)) || ((BMS_HVBatCellTempMax <=
    cal_tBatCoolVehReadyCellTempOff) && ((ME11_ARID_DEF.DataTypeConversion1 == 2)
    || (ME11_ARID_DEF.DataTypeConversion1 == 5)))) << 1) + (uint32)
    (((ME11_ARID_DEF.Delay_DSTATE_gh == 3) && (ME11_ARID_DEF.DataTypeConversion1
    != 3)) || ((ME11_ARID_DEF.Delay_DSTATE_gh == 4) &&
               (ME11_ARID_DEF.DataTypeConversion1 != 4)) ||
     (((ME11_ARID_DEF.Delay_DSTATE_gh == 2) || (ME11_ARID_DEF.Delay_DSTATE_gh ==
    5)) && ((ME11_ARID_DEF.DataTypeConversion1 != 2) &&
            (ME11_ARID_DEF.DataTypeConversion1 != 5))))) + (uint32)
    ((rtb_Compare_cd_tmp || ACTCtl_bBatPMPFaultFlg || ACTCtl_bCOMPForbidFlg) <<
     2)) + (uint32)((rtb_Delay_ci >= cal_tBatHeatExitMaxToMinCellDiff) << 3)) +
    (uint32)((PWRCtl_VCUACCMLimitPwr <= cal_BatHeatPwrLoLmt) << 4)) + (uint32)
    (ACTCtl_bCOMPCoolEnvPrtFlg << 5));
  rtb_FixPtRelationalOperator_gf = (SOMCtl_eBatCoolB2tB1 != 0);
  rtb_AND1_c = !ACTCtl_bBatPMPFaultFlg;
  rtb_RelationalOperator_lt = ((!ACTCtl_bAEXVFaultFlg) && (!ACTCtl_bBEXVFaultFlg)
    && (!ACTCtl_bHPEXVFaultFlg));
  rtb_OR2_a = !ACTCtl_bCOMPForbidFlg;
  b_previousEvent = (rtb_RelationalOperator_lt && rtb_AND1_c && rtb_OR2_a);
  rtb_Compare_bu = !ACTCtl_bCOMPCoolEnvPrtFlg;
  SOMCtl_eBatCoolB1tB21 = (uint8)(((((uint32)(((BMS_HVBatCellTempMax >=
    cal_tDCBatCoolCellTempOn) && (ME11_ARID_DEF.DataTypeConversion1 == 4)) ||
    ((ME11_ARID_DEF.DataTypeConversion1 == 3) && (BMS_HVBatCellTempMax >=
    cal_tACBatCoolCellTempOn))) + (uint32)(b_previousEvent << 1)) + (uint32)
    ((PWRCtl_VCUACCMLimitPwr >= cal_HeatPwrOn) << 2)) + (uint32)((rtb_Delay_ci <
    cal_tBatHeatExitMaxToMinCellDiff) << 3)) + (uint32)(rtb_Compare_bu << 4));
  SOMCtl_eBatCoolB1tB22 = (uint8)((((((uint32)
    ((ME11_ARID_DEF.DataTypeConversion1 == 5) ||
     (ME11_ARID_DEF.DataTypeConversion1 == 2)) + (uint32)(b_previousEvent << 2))
    + (uint32)((BMS_HVBatCellTempMax >= cal_tBatCoolCellTempOn) << 1)) + (uint32)
    ((rtb_Delay_ci < cal_tBatHeatExitMaxToMinCellDiff) << 3)) + (uint32)
    ((PWRCtl_VCUACCMLimitPwr >= cal_HeatPwrOn) << 4)) + (uint32)(rtb_Compare_bu <<
    5));
  if (ME11_ARID_DEF.is_active_c70_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c70_ME11 = 1U;
    ME11_ARID_DEF.is_c70_ME11 = ME11_IN_Off_a;
    rtb_Compare_mdjr = false;
  } else if (ME11_ARID_DEF.is_c70_ME11 == ME11_IN_Off_a) {
    rtb_Compare_mdjr = false;
    if (((SOMCtl_eBatCoolB1tB21 == 31) || (SOMCtl_eBatCoolB1tB22 == 63)) &&
        (!rtb_FixPtRelationalOperator_gf)) {
      ME11_ARID_DEF.is_c70_ME11 = ME11_IN_On_li;
      rtb_Compare_mdjr = true;
    }
  } else {
    rtb_Compare_mdjr = true;
    if (rtb_FixPtRelationalOperator_gf) {
      ME11_ARID_DEF.is_c70_ME11 = ME11_IN_Off_a;
      rtb_Compare_mdjr = false;
    }
  }

  BMS_InletCooltActlTemp =
    (Rte_IRead_Task_100ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
     ())->VIPM_BMSInletCooltActlTemp_C;
  if (ME11_ARID_DEF.temporalCounter_i1_p < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_p++;
  }

  if (ME11_ARID_DEF.is_active_c8_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c8_ME11 = 1U;
    ME11_ARID_DEF.is_c8_ME11 = ME11_IN_Open;
    ME11_ARID_DEF.SOMCtl_bCoolInletTempSts = true;
  } else {
    switch (ME11_ARID_DEF.is_c8_ME11) {
     case ME11_IN_Close:
      ME11_ARID_DEF.SOMCtl_bCoolInletTempSts = false;
      if (BMS_InletCooltActlTemp > cal_OpenCoolInletTemp) {
        ME11_ARID_DEF.is_c8_ME11 = ME11_IN_Open;
        ME11_ARID_DEF.SOMCtl_bCoolInletTempSts = true;
      }
      break;

     case ME11_IN_Open:
      ME11_ARID_DEF.SOMCtl_bCoolInletTempSts = true;
      if (BMS_InletCooltActlTemp < cal_ClsCoolInletTemp) {
        ME11_ARID_DEF.is_c8_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_p = 0U;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_p >= cal_ClsCoolInletTempTime * 10.0F)
      {
        ME11_ARID_DEF.is_c8_ME11 = ME11_IN_Close;
        ME11_ARID_DEF.SOMCtl_bCoolInletTempSts = false;
      } else if (BMS_InletCooltActlTemp >= cal_ClsCoolInletTemp) {
        ME11_ARID_DEF.is_c8_ME11 = ME11_IN_Open;
        ME11_ARID_DEF.SOMCtl_bCoolInletTempSts = true;
      }
      break;
    }
  }

  if (cal_BatCoolOverEnb) {
    SOMCtl_bBatCoolFlg = cal_BatCoolOverData;
  } else {
    SOMCtl_bBatCoolFlg = (ME11_ARID_DEF.SOMCtl_bCoolInletTempSts &&
                          rtb_Compare_mdjr);
  }

  BMS_BatSOCAct_pct =
    (Rte_IRead_Task_100ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT())
    ->VIPM_BMSBatSOCAct_pct;
  SOMCtl_eBatBalEntBFlg = (uint8)(((uint32)(((cal_TSACBatMinEntTempB <=
    BMS_HVBatCellTempMin) && (BMS_HVBatCellTempMax < cal_BatBalCellTemp2) &&
    (ME11_ARID_DEF.DataTypeConversion1 == 3) && (BMS_BatSOCAct_pct >=
    cal_ACChgBatHighSOCHeat)) << 1) + (uint32)(((cal_TSDCBatMinEntTempC <=
    BMS_HVBatCellTempMin) && (BMS_HVBatCellTempMax < cal_BatBalCellTemp2) &&
    (ME11_ARID_DEF.DataTypeConversion1 == 4) && (BMS_BatSOCAct_pct >=
    cal_ACChgBatHighSOCHeat)) << 2)) + (uint32)(((cal_BatBalCellTemp1 <
    BMS_HVBatCellTempMin) && (BMS_HVBatCellTempMax < cal_BatBalCellTemp2) &&
    ((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
     (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (BMS_BatSOCAct_pct >=
    cal_ACChgBatHighSOCHeat)) << 3));
  MotPMP_RESP_ERROR = Rte_IRead_Task_100ms_MotPMP_RESP_ERROR_MotPMP_RESP_ERROR();
  rtb_FixPtRelationalOperator_gf = MotPMP_RESP_ERROR;
  MotPMP_PumpMotorSta =
    Rte_IRead_Task_100ms_MotPMP_PumpMotorSta_MotPMP_PumpMotorSta();
  rtb_Compare_mdjr = (MotPMP_PumpMotorSta != 0);
  MotPMP_PumpDryRunningSta =
    Rte_IRead_Task_100ms_MotPMP_PumpDryRunningSta_MotPMP_PumpDryRunningSta();
  rtb_Compare_cvf = MotPMP_PumpDryRunningSta;
  MotPMP_PumpPowerSta =
    Rte_IRead_Task_100ms_MotPMP_PumpPowerSta_MotPMP_PumpPowerSta();
  rtb_FixPtRelationalOperator_cd = (MotPMP_PumpPowerSta != 0);
  MotPMP_PumpTempSta =
    Rte_IRead_Task_100ms_MotPMP_PumpTempSta_MotPMP_PumpTempSta();
  rtb_FixPtRelationalOperator_d5 = (MotPMP_PumpTempSta != 0);
  ME11_AcPMPFaultJudge(MotPMP_RESP_ERROR || rtb_Compare_mdjr ||
                       MotPMP_PumpDryRunningSta ||
                       rtb_FixPtRelationalOperator_cd ||
                       rtb_FixPtRelationalOperator_d5,
                       &ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_e,
                       &ME11_ARID_DEF.ARID_DEF_AcPMPFaultJudge);
  if (cal_MotPMPFaultFlgDataEnb) {
    ACTCtl_bMotPMPFaultFlg = cal_MotPMPFaultFlgData;
  } else {
    ACTCtl_bMotPMPFaultFlg = ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_e;
  }

  rtb_AND1_h0y = (rtb_AND1_c && (!ACTCtl_bMotPMPFaultFlg));
  SOMCtl_bBatBalEntBFlg = ((SOMCtl_eBatBalEntBFlg != 0) && (rtb_Delay1_ie <
    cal_tBatHeatExitMaxToMinCellDiff) && rtb_AND1_h0y);
  rtb_Compare_f2 =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2IgbtMaxTemp_C >= cal_tLTROnMotTemp);
  rtb_FixPtRelationalOperator_ex =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2MotorMaxTemp_C >= cal_LTRMotorMaxEntTemp);
  rtb_Divide1_f = (uint32)(rtb_AND1_h0y << 3);
  SOMCtl_eBatLTROnFlg = (uint8)((((uint32)(((ACSen_sMotTempFilter >=
    cal_tLTROnMotInletTemp) || rtb_Compare_f2 || rtb_FixPtRelationalOperator_ex)
    << 2) + (uint32)((BMS_HVBatCellTempMax < cal_BatBalCellTemp2) << 1)) +
    (uint32)(ME11_ARID_DEF.DataTypeConversion1 >= 2)) + rtb_Divide1_f);
  rtb_FixPtRelationalOperator_ex =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2MotorMaxTemp_C <= cal_LTRMotorMaxExitTemp);
  rtb_Compare_f2 =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2IgbtMaxTemp_C <= cal_LTRIGBTMaxExitTempB);
  rtb_RelationalOperator3_d =
    ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT())
     ->VIPM_IPUDeviceIntTemp_C >= cal_TSIPUExitTempI);
  ME11_Chart_p(rtb_RelationalOperator3_d, &ME11_ARID_DEF.B,
               &ME11_ARID_DEF.ARID_DEF_Chart);
  rtb_AND4_f = (ACTCtl_bBatPMPFaultFlg || ACTCtl_bMotPMPFaultFlg);
  SOMCtl_eMotLTRAndBatBalOffFlg = (uint8)((((((uint32)
    (rtb_FixPtRelationalOperator_ex && (ACSen_sMotTempFilter <=
    cal_LTRMotorInletMaxExitTempA) && rtb_Compare_f2) + (uint32)
    (((BMS_HVBatCellTempMin <= cal_TSDCBatMinExitTempK) &&
      (ME11_ARID_DEF.DataTypeConversion1 == 4)) << 1)) + (uint32)
    (((BMS_HVBatCellTempMin <= cal_TSACBatMinExitTempM) &&
      (ME11_ARID_DEF.DataTypeConversion1 == 3) && (BMS_BatSOCAct_pct >=
    cal_ACChgBatHighSOCHeat)) << 2)) + (uint32)((BMS_HVBatCellTempMax >=
    cal_BatBalCellTemp2) << 4)) + (uint32)(ME11_ARID_DEF.B << 5)) + (uint32)
    (rtb_AND4_f << 6));
  SOMCtl_bMotLTRAndBatBalOffFlg = (SOMCtl_eMotLTRAndBatBalOffFlg != 0);
  rtb_FixPtRelationalOperator_ex = (SOMCtl_bBatCoolFlg ||
    (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
      (ME11_ARID_DEF.DataTypeConversion1 == 4)) && SOMCtl_bBatHeatFlg));
  if (ME11_ARID_DEF.is_active_c142_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c142_ME11 = 1U;
    ME11_ARID_DEF.is_c142_ME11 = ME11_IN_Off_a;
    SOMCtl_bMotorLTRAndBatBalFlg = false;
  } else if (ME11_ARID_DEF.is_c142_ME11 == ME11_IN_Off_a) {
    SOMCtl_bMotorLTRAndBatBalFlg = false;
    if (((sint32)((uint32)((SOMCtl_eBatLTROnFlg == 15) << 1) +
                  SOMCtl_bBatBalEntBFlg) >= 1) &&
        (!SOMCtl_bMotLTRAndBatBalOffFlg) && (!rtb_FixPtRelationalOperator_ex)) {
      ME11_ARID_DEF.is_c142_ME11 = ME11_IN_On_li;
      SOMCtl_bMotorLTRAndBatBalFlg = true;
    }
  } else {
    SOMCtl_bMotorLTRAndBatBalFlg = true;
    if (SOMCtl_bMotLTRAndBatBalOffFlg || rtb_FixPtRelationalOperator_ex) {
      ME11_ARID_DEF.is_c142_ME11 = ME11_IN_Off_a;
      SOMCtl_bMotorLTRAndBatBalFlg = false;
    }
  }

  rtb_Add = BMS_HVBatCellTempMax - ACSen_sMotTempFilter;
  SOMCtl_eMotLTRAndBatBalOn1Flg = (uint8)(((uint32)(((BMS_HVBatCellTempMax >=
    cal_BatBalCellTemp2) && (BMS_HVBatCellTempMax <= look1_iflf_binlca
    (ACSen_sEnvTempCor, (const float32 *)&cal_DLTRBatMaxEntTempB_1X[0], (const
    float32 *)&cal_DLTRBatMaxEntTempB_CUR[0], 4U))) << 1) + (uint32)
    ((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
     (ME11_ARID_DEF.DataTypeConversion1 == 5))) + (uint32)((rtb_Add >=
    cal_tLTROnMaxCellToMotDiff) << 2));
  SOMCtl_bMotLTRAndBatBalOn1Flg = (SOMCtl_eMotLTRAndBatBalOn1Flg == 7);
  rtb_FixPtRelationalOperator_ex =
    ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT())
     ->VIPM_IPUDeviceIntTemp_C >= cal_tLTROnIPUTemp);
  rtb_Add_cy = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
    &cal_DLTRDCBatMaxEntTempB_1X[0], (const float32 *)
    &cal_DLTRDCBatMaxEntTempB_CUR[0], 4U);
  SOMCtl_eMotLTRAndBatBalOn2Flg = (uint8)((uint32)
    (((ME11_ARID_DEF.DataTypeConversion1 == 4) && (BMS_HVBatCellTempMax >=
    rtb_Add_cy)) || ((ME11_ARID_DEF.DataTypeConversion1 == 3) &&
                     (BMS_HVBatCellTempMax >= rtb_Add_cy))) + (uint32)((rtb_Add >=
    cal_tLTROnMaxCellToMotDiff) << 1));
  SOMCtl_bMotLTRAndBatBalOn2Flg = (SOMCtl_eMotLTRAndBatBalOn2Flg == 3);
  rtb_Compare_f2 = (SOMCtl_bMotLTRAndBatBalOn1Flg ||
                    (rtb_FixPtRelationalOperator_ex &&
                     (ME11_ARID_DEF.DataTypeConversion1 >= 2)) ||
                    SOMCtl_bMotLTRAndBatBalOn2Flg);
  rtb_FixPtRelationalOperator_ex =
    ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT())
     ->VIPM_IPUDeviceIntTemp_C <= cal_DLTRIPUTempExitVal);
  SOMCtl_bDBatLTROffFlg = ((rtb_FixPtRelationalOperator_ex &&
    ((BMS_InletCooltActlTemp - BMS_HVBatCellTempMax >=
      cal_DLTRBatInlet2MaxTempDiff) || (cal_BatBalCellTemp2 -
    BMS_HVBatCellTempMax >= cal_tLTROffBatBal2ToMaxCellDiff))) ||
    (((((ME11_ARID_DEF.DataTypeConversion1 == 4) && (look1_iflf_binlca
    (ACSen_sEnvTempCor, (const float32 *)&cal_DLTRDCBatMaxExitTempB_1X[0], (
    const float32 *)&cal_DLTRDCBatMaxExitTempB_CUR[0], 4U) <=
    BMS_HVBatCellTempMax)) || ((look1_iflf_binlca(ACSen_sEnvTempCor, (const
    float32 *)&cal_DLTRNotDCBatMaxExitTempC_1X[0], (const float32 *)
    &cal_DLTRNotDCBatMaxExitTempC_CUR[0], 4U) <= BMS_HVBatCellTempMax) &&
    ((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
     (ME11_ARID_DEF.DataTypeConversion1 == 3) ||
     (ME11_ARID_DEF.DataTypeConversion1 == 5)))) && rtb_Compare_bu) ||
     (rtb_Delay1_ie >= cal_tBatHeatExitMaxToMinCellDiff) || rtb_AND4_f));
  rtb_FixPtRelationalOperator_ex = (SOMCtl_bBatCoolFlg ||
    (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
      (ME11_ARID_DEF.DataTypeConversion1 == 4)) && ME11_ARID_DEF.Delay_DSTATE_jf));
  ME11_ARID_DEF.Relay_Mode_a = ((ACSen_sEnvTempCor >= cal_EnvDLTROnVal) ||
    ((ACSen_sEnvTempCor > cal_EnvDLTROffVal) && ME11_ARID_DEF.Relay_Mode_a));
  b_previousEvent = !ME11_ARID_DEF.Relay_Mode_a;
  if (ME11_ARID_DEF.is_active_c144_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c144_ME11 = 1U;
    ME11_ARID_DEF.is_c144_ME11 = ME11_IN_Off_a;
    SOMCtl_bMotAndBatLTRFlg = false;
  } else if (ME11_ARID_DEF.is_c144_ME11 == ME11_IN_Off_a) {
    SOMCtl_bMotAndBatLTRFlg = false;
    if (rtb_Compare_f2 && rtb_AND1_h0y && (rtb_Delay1_ie <
         cal_tBatHeatExitMaxToMinCellDiff) && (!SOMCtl_bDBatLTROffFlg) &&
        (!rtb_FixPtRelationalOperator_ex) && (b_previousEvent == 0)) {
      ME11_ARID_DEF.is_c144_ME11 = ME11_IN_On_li;
      SOMCtl_bMotAndBatLTRFlg = true;
    }
  } else {
    SOMCtl_bMotAndBatLTRFlg = true;
    if (SOMCtl_bDBatLTROffFlg || rtb_FixPtRelationalOperator_ex ||
        (b_previousEvent == 1)) {
      ME11_ARID_DEF.is_c144_ME11 = ME11_IN_Off_a;
      SOMCtl_bMotAndBatLTRFlg = false;
    }
  }

  ME11_ARID_DEF.Relay_Mode_o = ((BMS_BatSOCAct_pct >= cal_ACChgBatHighSOCHeat) ||
    ((BMS_BatSOCAct_pct > cal_ACChgBatLowSOCHeat) && ME11_ARID_DEF.Relay_Mode_o));
  if (ME11_ARID_DEF.Relay_Mode_o) {
    rtb_Compare_gzu = (BMS_HVBatCellTempMin <= cal_tBatHeatACChrgSOCHighTempOn);
  } else {
    rtb_Compare_gzu = (BMS_HVBatCellTempMin <= cal_tBatHeatACChrgCellTempOn);
  }

  SOMCtl_bBatHeatChrgFlgAB = (((BMS_HVBatCellTempMin <=
    cal_tBatHeatDCChrgCellTempOn) && (ME11_ARID_DEF.DataTypeConversion1 == 4)) ||
    ((ME11_ARID_DEF.DataTypeConversion1 == 3) && rtb_Compare_gzu));
  AcPMP_RESP_ERROR = Rte_IRead_Task_100ms_AcPMP_RESP_ERROR_AcPMP_RESP_ERROR();
  rtb_FixPtRelationalOperator_ex = AcPMP_RESP_ERROR;
  AcPMP_PumpMotorSta =
    Rte_IRead_Task_100ms_AcPMP_PumpMotorSta_AcPMP_PumpMotorSta();
  rtb_Compare_f2 = (AcPMP_PumpMotorSta != 0);
  AcPMP_PumpDryRunningSta =
    Rte_IRead_Task_100ms_AcPMP_PumpDryRunningSta_AcPMP_PumpDryRunningSta();
  rtb_Compare_bu = AcPMP_PumpDryRunningSta;
  AcPMP_PumpPowerSta =
    Rte_IRead_Task_100ms_AcPMP_PumpPowerSta_AcPMP_PumpPowerSta();
  rtb_RelationalOperator3_d = (AcPMP_PumpPowerSta != 0);
  AcPMP_PumpTempSta = Rte_IRead_Task_100ms_AcPMP_PumpTempSta_AcPMP_PumpTempSta();
  rtb_Compare_j2e = (AcPMP_PumpTempSta != 0);
  ME11_AcPMPFaultJudge(AcPMP_RESP_ERROR || rtb_Compare_f2 ||
                       AcPMP_PumpDryRunningSta || rtb_RelationalOperator3_d ||
                       rtb_Compare_j2e, &ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_c,
                       &ME11_ARID_DEF.ARID_DEF_AcPMPFaultJudge_b);
  if (cal_AcPMPFaultFlgDataEnb) {
    ACTCtl_bAcPMPFaultFlg = cal_AcPMPFaultFlgData;
  } else {
    ACTCtl_bAcPMPFaultFlg = ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_c;
  }

  if (cal_HVCHFltDataEnb) {
    ACTCtl_bHVCHFaultFlg = cal_HVCHFltData;
  } else {
    rtb_Compare_dsx =
      ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
       ->VIPM_HVCHSt_enum != 2);
    rtb_Compare_ny =
      ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
       ->VIPM_HVCHFltCod_enum == 0);
    ACTCtl_bHVCHFaultFlg = (rtb_Compare_ny && rtb_Compare_dsx);
  }

  SOMCtl_bBatHeatTempDiffE = (rtb_Delay_ci < cal_tBatHeatExitMaxToMinCellDiff);
  rtb_Add = PWRCtl_VCUACCMLimitPwr + PWRCtl_VCUACCMLimitPwr;
  SOMCtl_bBatHeatPwrLmtF = (rtb_Add >= cal_HeatPwrOn);
  rtb_AND1_c = (rtb_RelationalOperator_lt && ((!ACTCtl_bAcPMPFaultFlg) &&
    rtb_AND1_c) && rtb_OR2_a && ACTCtl_bHVCHFaultFlg);
  SOMCtl_bBatB1TB41Flg = (SOMCtl_bBatHeatChrgFlgAB && rtb_AND1_c &&
    SOMCtl_bBatHeatTempDiffE && SOMCtl_bBatHeatPwrLmtF);
  ME11_ARID_DEF.Relay_Mode_f = ((BMS_BatSOCAct_pct >= cal_ACChgBatHighSOCHeat) ||
    ((BMS_BatSOCAct_pct > cal_ACChgBatLowSOCHeat) && ME11_ARID_DEF.Relay_Mode_f));
  if (ME11_ARID_DEF.Relay_Mode_f) {
    rtb_Compare_gzu = (BMS_HVBatCellTempMin >= cal_tBatHeatACChrgSOCHighTempOff);
  } else {
    rtb_Compare_gzu = (BMS_HVBatCellTempMin >= cal_tBatHeatACChrgCellTempOff);
  }

  if ((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
      (ME11_ARID_DEF.DataTypeConversion1 == 4)) {
    rtb_RelationalOperator_lt = false;
  } else {
    rtb_RelationalOperator_lt = (BMS_BatSOCAct_pct <= cal_VehHeatSOCOff);
  }

  SOMCtl_eBatHeatOffVal = (uint8)((((((uint32)(((((ME11_ARID_DEF.Delay_DSTATE_bd
    == 3) && (ME11_ARID_DEF.DataTypeConversion1 != 3)) ||
    ((ME11_ARID_DEF.Delay_DSTATE_bd == 4) && (ME11_ARID_DEF.DataTypeConversion1
    != 4)) || ((ME11_ARID_DEF.Delay_DSTATE_bd == 5) &&
               (ME11_ARID_DEF.DataTypeConversion1 != 5))) &&
    ME11_ARID_DEF.Delay_DSTATE_bg) << 4) + (uint32)
    ((((ME11_ARID_DEF.DataTypeConversion1 == 4) && (BMS_HVBatCellTempMin >=
    cal_tBatHeatDCChrgCellTempOff)) || ((ME11_ARID_DEF.DataTypeConversion1 == 3)
    && rtb_Compare_gzu) || ((ME11_ARID_DEF.DataTypeConversion1 == 5) &&
    (BMS_HVBatCellTempMin >= cal_tBatHeatVehReadyCellTempOff))) << 5)) + (uint32)
    ((rtb_Compare_cd_tmp || (ACTCtl_bAcPMPFaultFlg || ACTCtl_bBatPMPFaultFlg) ||
      ACTCtl_bCOMPForbidFlg || (!ACTCtl_bHVCHFaultFlg)) << 2)) + (uint32)
    (rtb_RelationalOperator_lt << 3)) + (uint32)(rtb_Delay_ci >=
    cal_tBatHeatExitMaxToMinCellDiff)) + (uint32)((rtb_Add <=
    cal_BatHeatPwrLoLmt) << 1));
  SOMCtl_bBatHeatOffFlg = (SOMCtl_eBatHeatOffVal != 0);
  SOMCtl_bBatB1TB42Flg = ((ME11_ARID_DEF.DataTypeConversion1 == 5) &&
    (BMS_HVBatCellTempMin <= cal_tBatHeatVehReadyCellTempOn) && rtb_AND1_c &&
    (BMS_BatSOCAct_pct >= cal_VehHeatSOCOn) && (rtb_Delay_ci <
    cal_tBatHeatExitMaxToMinCellDiff) && (rtb_Add >= cal_HeatPwrOn));
  if (ME11_ARID_DEF.is_active_c71_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c71_ME11 = 1U;
    ME11_ARID_DEF.is_c71_ME11 = ME11_IN_Off_a;
    SOMCtl_bBatHeatFlg = false;
  } else if (ME11_ARID_DEF.is_c71_ME11 == ME11_IN_Off_a) {
    SOMCtl_bBatHeatFlg = false;
    if ((SOMCtl_bBatB1TB41Flg || SOMCtl_bBatB1TB42Flg) &&
        (!SOMCtl_bBatHeatOffFlg)) {
      ME11_ARID_DEF.is_c71_ME11 = ME11_IN_On_li;
      SOMCtl_bBatHeatFlg = true;
    }
  } else {
    SOMCtl_bBatHeatFlg = true;
    if (SOMCtl_bBatHeatOffFlg) {
      ME11_ARID_DEF.is_c71_ME11 = ME11_IN_Off_a;
      SOMCtl_bBatHeatFlg = false;
    }
  }

  if (cal_BatHeatOverEnb) {
    SOMCtl_bBatHeatFlg = cal_BatHeatOverData;
  }

  rtb_Compare_cls =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2MotorMaxTemp_C <= cal_TSMotorMinTempEntC);
  rtb_Compare_bdq =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2IgbtMaxTemp_C <= cal_TSIGBTMinTempEntC);
  SOMCtl_bBatTSEntAFlg = (((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
    (ME11_ARID_DEF.DataTypeConversion1 == 5)) && (rtb_Delay1_ie <
    cal_tBatHeatExitMaxToMinCellDiff) && rtb_AND1_h0y &&
    (cal_TSBatMinTemplowValB <= BMS_HVBatCellTempMin) && (BMS_HVBatCellTempMin <=
    cal_BatBalCellTemp1) && (rtb_Compare_cls || rtb_Compare_bdq));
  SOMCtl_bBatTSEntBFlg = ((cal_TSACBatMinEntTempA <= BMS_HVBatCellTempMin) &&
    (BMS_HVBatCellTempMax < cal_BatBalCellTemp2) &&
    (ME11_ARID_DEF.DataTypeConversion1 == 3) && (BMS_BatSOCAct_pct <=
    cal_ACChgBatLowSOCHeat) && (rtb_Delay1_ie < cal_tBatHeatExitMaxToMinCellDiff)
    && rtb_AND1_h0y);
  ME11_Chart_p(ACSen_sMotTempFilter >= BMS_HVBatCellTempMin +
               cal_TSBatMinTempOffsetD, &ME11_ARID_DEF.B_a,
               &ME11_ARID_DEF.ARID_DEF_Chart_d);
  ME11_Chart_p(ACSen_sMotTempFilter >= BMS_InletCooltActlTemp +
               cal_TSBatInletTempOffsetP, &ME11_ARID_DEF.B_i,
               &ME11_ARID_DEF.ARID_DEF_Chart1_d);
  rtb_Compare_dsx =
    ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
     ->VIPM_INV2IgbtMaxTemp_C >= cal_TSIGBTMinTempExitG);
  rtb_RelationalOperator_lt =
    ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT())
     ->VIPM_IPUDeviceIntTemp_C >= cal_TSIPUExitTempI);
  SOMCtl_bBatTSExitFlg = ((rtb_Delay1_ie >= cal_tBatHeatExitMaxToMinCellDiff) ||
    (ACTCtl_bBatPMPFaultFlg && ACTCtl_bMotPMPFaultFlg) || ((BMS_HVBatCellTempMin
    >= cal_BatBalCellTemp1 + 2.0F) && ((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
    (ME11_ARID_DEF.DataTypeConversion1 == 5))) || (BMS_HVBatCellTempMax >=
    look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
                      &cal_TSBatMaxTempForEnvExitC_1X[0], (const float32 *)
                      &cal_TSBatMaxTempForEnvExitC_CUR[0], 4U)) ||
    (ME11_ARID_DEF.B_a && ME11_ARID_DEF.B_i) || rtb_Compare_dsx ||
    (ACSen_sMotTempFilter >= cal_TSMotorMinTempExitH) ||
    rtb_RelationalOperator_lt || (BMS_HVBatCellTempMin <= cal_TSBatMinExitTempJ)
    || ((BMS_HVBatCellTempMin <= cal_TSACBatMinExitTempN) &&
        (ME11_ARID_DEF.DataTypeConversion1 == 3) && (BMS_BatSOCAct_pct <=
    cal_ACChgBatLowSOCHeat)));
  rtb_AND1_h0y = (SOMCtl_bBatCoolFlg || (((ME11_ARID_DEF.DataTypeConversion1 ==
    3) || (ME11_ARID_DEF.DataTypeConversion1 == 4)) &&
    ME11_ARID_DEF.Delay_DSTATE_jm));
  if (ME11_ARID_DEF.is_active_c132_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c132_ME11 = 1U;
    ME11_ARID_DEF.is_c132_ME11 = ME11_IN_Off_a;
    SOMCtl_bBatTSFlg = false;
  } else if (ME11_ARID_DEF.is_c132_ME11 == ME11_IN_Off_a) {
    SOMCtl_bBatTSFlg = false;
    if (((sint32)((uint32)(SOMCtl_bBatTSEntBFlg << 1) + SOMCtl_bBatTSEntAFlg) >=
         1) && (!SOMCtl_bBatTSExitFlg) && (!rtb_AND1_h0y)) {
      ME11_ARID_DEF.is_c132_ME11 = ME11_IN_On_li;
      SOMCtl_bBatTSFlg = true;
    }
  } else {
    SOMCtl_bBatTSFlg = true;
    if (SOMCtl_bBatTSExitFlg || rtb_AND1_h0y) {
      ME11_ARID_DEF.is_c132_ME11 = ME11_IN_Off_a;
      SOMCtl_bBatTSFlg = false;
    }
  }

  ME11_Chart_e(BMS_InletCooltActlTemp + cal_tMotHeatOnMotToMinCellDiff <=
               ACSen_sMotTempFilter, &ME11_ARID_DEF.B_e,
               &ME11_ARID_DEF.ARID_DEF_Chart_g);
  SOMCtl_eMotorHeatBatFlg = (uint8)((((uint32)(((BMS_HVBatCellTempMin <=
    cal_BatBalCellTemp1) && (BMS_HVBatCellTempMin >
    cal_tMotHeatBatMinCellTempLow)) << 1) + (uint32)(rtb_Delay1_ie <
    cal_tBatHeatExitMaxToMinCellDiff)) + (uint32)(ME11_ARID_DEF.B_e << 2)) +
    rtb_Divide1_f);
  ME11_Chart_e(BMS_HVBatCellTempMin + cal_tMotHeatOnMotToMinCellDiff <=
               ACSen_sMotTempFilter, &ME11_ARID_DEF.B_mb,
               &ME11_ARID_DEF.ARID_DEF_Chart_l);
  SOMCtl_eMotorHeatBat2Flg = (uint8)((((uint32)(((BMS_HVBatCellTempMin <=
    cal_BatBalCellTemp1) && (BMS_HVBatCellTempMin >
    cal_tMotHeatBatACChrgMinCellTempLow)) << 1) + (uint32)(rtb_Delay1_ie <
    cal_tBatHeatExitMaxToMinCellDiff)) + (uint32)(ME11_ARID_DEF.B_mb << 2)) +
    rtb_Divide1_f);
  if ((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
      (ME11_ARID_DEF.DataTypeConversion1 == 5)) {
    SOMCtl_bMotorHeatBatOnFlg = (SOMCtl_eMotorHeatBatFlg == 15);
  } else if (ME11_ARID_DEF.DataTypeConversion1 == 3) {
    SOMCtl_bMotorHeatBatOnFlg = (SOMCtl_eMotorHeatBat2Flg == 15);
  } else {
    SOMCtl_bMotorHeatBatOnFlg = false;
  }

  ME11_Chart_p(BMS_HVBatCellTempMin + cal_tMotHeatExitMinCellToMotTempDiff >
               ACSen_sMotTempFilter, &ME11_ARID_DEF.B_f,
               &ME11_ARID_DEF.ARID_DEF_Chart1);
  rtb_AND1_h0y = ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
                  ->VIPM_INV2IgbtMaxTemp_C >= cal_MBIGBTHighExitTempG);
  ME11_Chart_p(rtb_AND1_h0y, &ME11_ARID_DEF.B_b, &ME11_ARID_DEF.ARID_DEF_Chart2);
  ME11_Chart_p(ACSen_sMotTempFilter >= cal_MBMotorInletHighExitTempH,
               &ME11_ARID_DEF.B_m, &ME11_ARID_DEF.ARID_DEF_Chart3);
  rtb_AND1_h0y =
    ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT())
     ->VIPM_IPUDeviceIntTemp_C >= cal_MBIPUDevHighExitTempI);
  ME11_Chart_p(rtb_AND1_h0y, &ME11_ARID_DEF.B_p, &ME11_ARID_DEF.ARID_DEF_Chart4);
  SOMCtl_eMotorHeatBatOffFlg = (uint16)(((((((((uint32)((BMS_HVBatCellTempMin >
    cal_BatBalCellTemp1 + cal_tMotHeatExitMinCellToBal1Diff) << 1) + (uint32)
    (ME11_ARID_DEF.DataTypeConversion1 == 4)) + (uint32)((BMS_HVBatCellTempMax >=
    cal_tMotStorExitMaxCellTemp) << 2)) + (uint32)(ME11_ARID_DEF.B_f << 3)) +
    (uint32)((rtb_Delay1_ie >= cal_tBatHeatExitMaxToMinCellDiff) << 4)) +
    (uint32)(rtb_AND4_f << 5)) + (uint32)(ME11_ARID_DEF.B_b << 6)) + (uint32)
    (ME11_ARID_DEF.B_m << 7)) + (uint32)(ME11_ARID_DEF.B_p << 8));
  SOMCtl_bMotorHeatBatOffFlg = (SOMCtl_eMotorHeatBatOffFlg > 0);
  rtb_AND4_f = (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
                 (ME11_ARID_DEF.DataTypeConversion1 == 4)) &&
                ME11_ARID_DEF.Delay_DSTATE_dl);
  if (ME11_ARID_DEF.is_active_c138_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c138_ME11 = 1U;
    ME11_ARID_DEF.is_c138_ME11 = ME11_IN_Off_a;
    SOMCtl_bMotHeatBatFlg = false;
  } else if (ME11_ARID_DEF.is_c138_ME11 == ME11_IN_Off_a) {
    SOMCtl_bMotHeatBatFlg = false;
    if (SOMCtl_bMotorHeatBatOnFlg && (!SOMCtl_bMotorHeatBatOffFlg) &&
        (!rtb_AND4_f)) {
      ME11_ARID_DEF.is_c138_ME11 = ME11_IN_On_li;
      SOMCtl_bMotHeatBatFlg = true;
    }
  } else {
    SOMCtl_bMotHeatBatFlg = true;
    if (SOMCtl_bMotorHeatBatOffFlg || rtb_AND4_f) {
      ME11_ARID_DEF.is_c138_ME11 = ME11_IN_Off_a;
      SOMCtl_bMotHeatBatFlg = false;
    }
  }

  if (ME11_ARID_DEF.is_active_c133_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c133_ME11 = 1U;
    ME11_ARID_DEF.is_c133_ME11 = ME11_IN_Default_c4;
    rtb_Switch2_ht = 0U;
  } else if (ME11_ARID_DEF.is_c133_ME11 == ME11_IN_BatMode) {
    if (ME11_ARID_DEF.DataTypeConversion1 < 2) {
      ME11_ARID_DEF.is_BatMode = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_c133_ME11 = ME11_IN_Default_c4;
      rtb_Switch2_ht = 0U;
    } else {
      switch (ME11_ARID_DEF.is_BatMode) {
       case ME11_IN_Balance:
        rtb_Switch2_ht = 4U;
        if (!SOMCtl_bMotorLTRAndBatBalFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
          rtb_Switch2_ht = 0U;
        }
        break;

       case ME11_IN_Cool_j:
        rtb_Switch2_ht = 1U;
        if (!SOMCtl_bBatCoolFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
          rtb_Switch2_ht = 0U;
        }
        break;

       case ME11_IN_HStr:
        rtb_Switch2_ht = 2U;
        if (!SOMCtl_bBatTSFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
          rtb_Switch2_ht = 0U;
        }
        break;

       case ME11_IN_Heat:
        rtb_Switch2_ht = 6U;
        if (!SOMCtl_bBatHeatFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
          rtb_Switch2_ht = 0U;
        }
        break;

       case ME11_IN_LTR:
        rtb_Switch2_ht = 5U;
        if (!SOMCtl_bMotAndBatLTRFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
          rtb_Switch2_ht = 0U;
        }
        break;

       case ME11_IN_MotorHeatBat:
        rtb_Switch2_ht = 3U;
        if (!SOMCtl_bMotHeatBatFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
          rtb_Switch2_ht = 0U;
        }
        break;

       default:
        rtb_Switch2_ht = 0U;
        if (SOMCtl_bBatCoolFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Cool_j;
          rtb_Switch2_ht = 1U;
        } else if (SOMCtl_bBatTSFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_HStr;
          rtb_Switch2_ht = 2U;
        } else if (SOMCtl_bMotHeatBatFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_MotorHeatBat;
          rtb_Switch2_ht = 3U;
        } else if (SOMCtl_bMotorLTRAndBatBalFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Balance;
          rtb_Switch2_ht = 4U;
        } else if (SOMCtl_bMotAndBatLTRFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_LTR;
          rtb_Switch2_ht = 5U;
        } else if (SOMCtl_bBatHeatFlg) {
          ME11_ARID_DEF.is_BatMode = ME11_IN_Heat;
          rtb_Switch2_ht = 6U;
        }
        break;
      }
    }
  } else {
    rtb_Switch2_ht = 0U;
    if (ME11_ARID_DEF.DataTypeConversion1 >= 2) {
      ME11_ARID_DEF.is_c133_ME11 = ME11_IN_BatMode;
      ME11_ARID_DEF.is_BatMode = ME11_IN_Off_g;
    }
  }

  rtb_AND4_f = (ME11_ARID_DEF.DataTypeConversion1 <= 1);
  if (ME11_ARID_DEF.temporalCounter_i1 < 1048575U) {
    ME11_ARID_DEF.temporalCounter_i1++;
  }

  if (ME11_ARID_DEF.is_active_c148_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c148_ME11 = 1U;
    ME11_ARID_DEF.is_c148_ME11 = ME11_IN_Init_i;
    ACCtl_bExhFlg = false;
  } else {
    switch (ME11_ARID_DEF.is_c148_ME11) {
     case ME11_IN_Init_i:
      ACCtl_bExhFlg = false;
      if (ACCtl_bExhaustFlg && (ME11_ARID_DEF.DataTypeConversion1 >= 2)) {
        ME11_ARID_DEF.is_c148_ME11 = ME11_IN_On_kf;
        ME11_ARID_DEF.temporalCounter_i1 = 0U;
        ACCtl_bExhFlg = true;
      }
      break;

     case ME11_IN_Off_l:
      ACCtl_bExhFlg = false;
      if (rtb_AND4_f) {
        ME11_ARID_DEF.is_c148_ME11 = ME11_IN_Init_i;
      }
      break;

     default:
      ACCtl_bExhFlg = true;
      if (rtb_AND4_f) {
        ME11_ARID_DEF.is_c148_ME11 = ME11_IN_Init_i;
        ACCtl_bExhFlg = false;
      } else if ((ME11_ARID_DEF.temporalCounter_i1 >= (uint32)(cal_ExhaustTime *
        10)) || (!ACCtl_bExhaustFlg)) {
        ME11_ARID_DEF.is_c148_ME11 = ME11_IN_Off_l;
        ACCtl_bExhFlg = false;
      }
      break;
    }
  }

  if (cal_bExhFlgEnb) {
    ACCtl_bExhFlg = cal_bExhFlgData;
  }

  if (cal_BatModeEnb) {
    SOMCtl_eBatMode = cal_BatModeData;
  } else if ((ME11_ARID_DEF.DataTypeConversion1 >= 2) && (!ACCtl_bExhFlg)) {
    SOMCtl_eBatMode = rtb_Switch2_ht;
  } else {
    SOMCtl_eBatMode = 0U;
  }

  rtb_DataTypeConversion1_l = SOMCtl_eBatMode;
  SENCtl_uOHXTempVol = get_OHXTempValtage();
  rtb_Delay1_ie = (float32)((sint16)SENCtl_uOHXTempVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uOHXTempVol, (const uint16 *)
    &cal_OHXTempVolAmend_1X[0], (const sint16 *)&cal_OHXTempVolAmend_CUR[0], 1U));
  rtb_Delay_ci = cal_ADCVCCVal - rtb_Delay1_ie;
  ME11_Judge(rtb_Delay1_ie > cal_SensorTempUpFlt, rtb_Delay1_ie <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts_l,
             &ME11_ARID_DEF.ARID_DEF_Judge_p);
  ACSen_eOHXTSenSts = ME11_ARID_DEF.SenSts_l;
  if (rtb_Delay_ci > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay1_ie / rtb_Delay_ci;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  SEN_OHXTRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 20000.0F, (const
    float32 *)&cal_TOHXOutRaw_1X[0], (const float32 *)&cal_TOHXOutRaw_CUR[0],
    29U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_g3 != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_g = SEN_OHXTRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_g = SEN_OHXTRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_g * 0.100000024F;
  if (cal_OHXTempDataEnb) {
    ACSen_sOHXTempFilter = cal_OHXTempData;
  } else {
    ACSen_sOHXTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_g;
  }

  SOMCtl_bEntExtDefFlg = ((ACSen_sOHXTempFilter <= cal_ExtDefOHXOnTemp) &&
    ((cal_ExtDefEnvMinTemp <= ACSen_sEnvTempCor) && (ACSen_sEnvTempCor <=
    cal_ExtDefEnvMaxTemp)) && (ACSen_sEnvTempCor - ACSen_sOHXTempFilter >=
    cal_ExtDefTempDiff));
  SOMCtl_bExitExtDefTempFlg = (ACSen_sOHXTempFilter >= cal_ExtDefOHXOffTemp);
  if (ME11_ARID_DEF.temporalCounter_i1_j < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_j++;
  }

  if (ME11_ARID_DEF.is_active_c95_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c95_ME11 = 1U;
    ME11_ARID_DEF.is_c95_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.SOMCtl_bExtDefFlg_m = false;
    ME11_ARID_DEF.Cnt = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c95_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.SOMCtl_bExtDefFlg_m = false;
      if (SOMCtl_bEntExtDefFlg) {
        ME11_ARID_DEF.is_c95_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_j = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.SOMCtl_bExtDefFlg_m = true;
      if (SOMCtl_bExitExtDefTempFlg || (ME11_ARID_DEF.Cnt > (uint16)
           (cal_ExitExtDefTime * 600.0F))) {
        ME11_ARID_DEF.is_c95_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.SOMCtl_bExtDefFlg_m = false;
        ME11_ARID_DEF.Cnt = 0U;
      } else {
        b_previousEvent = ME11_ARID_DEF.Cnt + 1;
        if (ME11_ARID_DEF.Cnt + 1 > 65535) {
          b_previousEvent = 65535;
        }

        ME11_ARID_DEF.Cnt = (uint16)b_previousEvent;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_j >= cal_EntExtDefTime * 60.0F *
          10.0F) {
        ME11_ARID_DEF.is_c95_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.SOMCtl_bExtDefFlg_m = true;
      } else if (!SOMCtl_bEntExtDefFlg) {
        ME11_ARID_DEF.is_c95_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.SOMCtl_bExtDefFlg_m = false;
        ME11_ARID_DEF.Cnt = 0U;
      }
      break;
    }
  }

  ME11_ARID_DEF.Delay_DSTATE_d2 = ME11_ARID_DEF.Delay1_DSTATE_bs;
  if (cal_ExtDefFlgDataEnb) {
    SOMCtl_bExtDefFlg = cal_ExtDefFlgData;
  } else {
    SOMCtl_bExtDefFlg = (ME11_ARID_DEF.Delay_DSTATE_d2 &&
                         ME11_ARID_DEF.SOMCtl_bExtDefFlg_m);
  }

  if (ME11_ARID_DEF.is_active_c103_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c103_ME11 = 1U;
    ME11_ARID_DEF.is_c103_ME11 = ME11_IN_Nml_d;
  } else if (ME11_ARID_DEF.is_c103_ME11 == ME11_IN_ExhDef) {
    if (!SOMCtl_bExtDefFlg) {
      ME11_ARID_DEF.is_c103_ME11 = ME11_IN_Nml_d;
    }
  } else if (SOMCtl_bExtDefFlg) {
    ME11_ARID_DEF.is_c103_ME11 = ME11_IN_ExhDef;
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_Def;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD4_HP) &&
             (rtb_DataTypeConversion1_l == 1)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_CoolBatAHeatCabin;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD1_CLM) &&
             (rtb_DataTypeConversion1_l == 6)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_CoolCabinAHeatBat;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD1_CLM) &&
             ((rtb_DataTypeConversion1_l != 1) && (rtb_DataTypeConversion1_l !=
               6))) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_CoolCabin;
  } else if (((rtb_DataTypeConversion1_on == CabinMode_MD_Off) ||
              (rtb_DataTypeConversion1_on == CabinMode_VENT) ||
              (rtb_DataTypeConversion1_on == CabinMode_STANDBY)) &&
             (rtb_DataTypeConversion1_l == 1)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_CoolBat;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD1_CLM) &&
             (rtb_DataTypeConversion1_l == 1)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_CoolDouble;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD4_HP) &&
             ((rtb_DataTypeConversion1_l != 1) && (rtb_DataTypeConversion1_l !=
               6))) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_HeatCabin;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD2_DHMD1) &&
             (rtb_DataTypeConversion1_l != 1)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_SerDeh_LCC;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD3_DHMD2) &&
             (rtb_DataTypeConversion1_l != 1)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_SerDeh_EVAP;
  } else if ((rtb_DataTypeConversion1_on != CabinMode_MD1_CLM) &&
             (rtb_DataTypeConversion1_on != CabinMode_MD4_HP) &&
             (rtb_DataTypeConversion1_l == 6)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_HeatBat;
  } else if ((rtb_DataTypeConversion1_on == CabinMode_MD4_HP) &&
             (rtb_DataTypeConversion1_l == 6)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_HeatDouble;
  } else if (((rtb_DataTypeConversion1_on == CabinMode_MD2_DHMD1) ||
              (rtb_DataTypeConversion1_on == CabinMode_MD3_DHMD2)) &&
             (rtb_DataTypeConversion1_l == 1)) {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_DehAndBatCool;
  } else {
    ME11_ARID_DEF.ACSOM_eRefModes = RefModes_Ref_Off;
  }

  if (cal_RefModeEnb) {
    SOMCtl_eRefModes = cal_RefModeData;
  } else {
    SOMCtl_eRefModes = ME11_ARID_DEF.ACSOM_eRefModes;
  }

  rtb_Switch2_ht = SOMCtl_eRefModes;
  ME11_ARID_DEF.Relay1_Mode = ((ACSen_sEnvTempCor >= cal_HeatCOMPEnvTempLmtOn) ||
    ((ACSen_sEnvTempCor > cal_HeatCOMPEnvTempLmtOff) &&
     ME11_ARID_DEF.Relay1_Mode));
  if (SOMCtl_eRefModes == 0) {
    ACTCrl_bEnvCOMPLmt = false;
  } else {
    for (b_previousEvent = 0; b_previousEvent < 7; b_previousEvent++) {
      rtb_Compare_hdh[b_previousEvent] = (SOMCtl_eRefModes ==
        ME11_ConstP.Constant_Value_dw[b_previousEvent]);
    }

    rtb_Compare_gzu = rtb_Compare_hdh[0];
    for (b_previousEvent = 0; b_previousEvent < 6; b_previousEvent++) {
      rtb_Compare_gzu = (rtb_Compare_gzu || rtb_Compare_hdh[b_previousEvent + 1]);
    }

    if (rtb_Compare_gzu) {
      ACTCrl_bEnvCOMPLmt = !ME11_ARID_DEF.Relay1_Mode;
    } else {
      ACTCrl_bEnvCOMPLmt = ACTCtl_bCOMPCoolEnvPrtFlg;
    }
  }

  rtb_Compare_cd_tmp = (ACTCtl_bAEXVFaultFlg || ACTCtl_bBEXVFaultFlg ||
                        ACTCtl_bHPEXVFaultFlg);
  SENCtl_uWCCHPVol = get_WCCHighPressValtage();
  rtb_Gain8 = (float32)((sint16)SENCtl_uWCCHPVol -
                        look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uWCCHPVol, (
    const uint16 *)&cal_WCCHPVolAmend_1X[0], (const sint16 *)
    &cal_WCCHPVolAmend_CUR[0], 1U));
  SEN_WCCHiPressRaw = look1_iflf_binlca(rtb_Gain8, (const float32 *)
    &cal_LCCOutHiPressRaw_1X[0], (const float32 *)&cal_LCCOutHiPressRaw_CUR[0],
    1U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nw != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_f = SEN_WCCHiPressRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_f = SEN_WCCHiPressRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_f * 0.100000024F;
  if (cal_HiPressDataEnb) {
    ACSen_sHiPressFilter = cal_HiPressData;
  } else if (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_f > cal_HPHighLmtVal) {
    ACSen_sHiPressFilter = cal_HPHighLmtVal;
  } else if (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_f < 0.0F) {
    ACSen_sHiPressFilter = 0.0F;
  } else {
    ACSen_sHiPressFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_f;
  }

  SENCtl_uWCCLPVol = get_LowPressValtage();
  rtb_LowPressLmt = (float32)((sint16)SENCtl_uWCCLPVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uWCCLPVol, (const uint16 *)
    &cal_WCCLPVolAmend_1X[0], (const sint16 *)&cal_WCCLPVolAmend_CUR[0], 1U));
  SEN_LoPressRaw = look1_iflf_binlca(rtb_LowPressLmt, (const float32 *)
    &cal_LoPressRaw_1X[0], (const float32 *)&cal_LoPressRaw_CUR[0], 1U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_f != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_fi = SEN_LoPressRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_fi = SEN_LoPressRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_fi * 0.100000024F;
  if (cal_LoPressDataEnb) {
    ACSen_sLoPressFilter = cal_LoPressData;
  } else {
    ACSen_sLoPressFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_fi;
  }

  rtb_AND4_f = !ME11_ARID_DEF.Delay_DSTATE_kf;
  ACTCtl_bOCOLmtFlg = ((ACSen_sHiPressFilter - ACSen_sLoPressFilter >=
                        cal_HPAndLPDiffMaxVal) && rtb_AND4_f);
  rtb_AND1_h0y = ((sint32)rtb_AND4_f > (sint32)
                  ME11_ARID_DEF.DelayInput1_DSTATE_ln);
  if (ME11_ARID_DEF.temporalCounter_i1_hv < 63U) {
    ME11_ARID_DEF.temporalCounter_i1_hv++;
  }

  if (ME11_ARID_DEF.is_active_c30_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c30_ME11 = 1U;
    ME11_ARID_DEF.is_c30_ME11 = ME11_IN_Normal_m;
    ACTCtl_bCOMPEnbDelay = false;
  } else {
    switch (ME11_ARID_DEF.is_c30_ME11) {
     case ME11_IN_Normal_m:
      ACTCtl_bCOMPEnbDelay = false;
      if (rtb_AND1_h0y) {
        ME11_ARID_DEF.is_c30_ME11 = ME11_IN_wait_f;
        ACTCtl_bCOMPEnbDelay = false;
      }
      break;

     case ME11_IN_Stop:
      ACTCtl_bCOMPEnbDelay = false;
      if (!rtb_AND1_h0y) {
        ME11_ARID_DEF.is_c30_ME11 = ME11_IN_Normal_m;
        ACTCtl_bCOMPEnbDelay = false;
      }
      break;

     case ME11_IN_Stop1:
      ACTCtl_bCOMPEnbDelay = true;
      if (ME11_ARID_DEF.temporalCounter_i1_hv >= 50U) {
        ME11_ARID_DEF.is_c30_ME11 = ME11_IN_Stop;
        ACTCtl_bCOMPEnbDelay = false;
      }
      break;

     default:
      ACTCtl_bCOMPEnbDelay = false;
      if (COMP_EcompActSpd <= 50.0F) {
        ME11_ARID_DEF.is_c30_ME11 = ME11_IN_Stop1;
        ME11_ARID_DEF.temporalCounter_i1_hv = 0U;
        ACTCtl_bCOMPEnbDelay = true;
      }
      break;
    }
  }

  switch ((sint32)(((uint32)((COMP_EcompActSpd < cal_COMPActlSpd2) << 1) +
                    (uint32)(COMP_EcompActSpd < cal_COMPActlSpd1)) + (uint32)
                   ((COMP_EcompActSpd < cal_COMPActlSpd3) << 2))) {
   case 4:
    ACTCtl_eCOMPSpdSecSts = 1U;
    break;

   case 6:
    ACTCtl_eCOMPSpdSecSts = 2U;
    break;

   case 7:
    ACTCtl_eCOMPSpdSecSts = 3U;
    break;

   default:
    ACTCtl_eCOMPSpdSecSts = 0U;
    break;
  }

  ME11_ARID_DEF.Relay_Mode_c = ((ACSen_sHiPressFilter >= cal_HPProVal1) ||
    ((ACSen_sHiPressFilter > cal_HPProVal1Relay) && ME11_ARID_DEF.Relay_Mode_c));
  ME11_ARID_DEF.Relay1_Mode_c = ((ACSen_sHiPressFilter >= cal_HPProVal2) ||
    ((ACSen_sHiPressFilter > cal_HPProVal2Relay) && ME11_ARID_DEF.Relay1_Mode_c));
  ME11_ARID_DEF.Relay2_Mode = ((ACSen_sHiPressFilter >= cal_HPProVal3) ||
    ((ACSen_sHiPressFilter > cal_HPProVal3Relay) && ME11_ARID_DEF.Relay2_Mode));
  if (ME11_ARID_DEF.temporalCounter_i1_hq < 8191U) {
    ME11_ARID_DEF.temporalCounter_i1_hq++;
  }

  if (ME11_ARID_DEF.is_active_c31_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c31_ME11 = 1U;
    ME11_ARID_DEF.is_c31_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = false;
  } else if (ME11_ARID_DEF.is_c31_ME11 == ME11_IN_Default_k) {
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = false;
    if (ME11_ARID_DEF.Relay2_Mode) {
      ME11_ARID_DEF.is_c31_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_m = ME11_IN_Flg3_p;
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
    } else if (ME11_ARID_DEF.Relay1_Mode_c) {
      ME11_ARID_DEF.is_c31_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_m = ME11_IN_wait_2_i;
      ME11_ARID_DEF.temporalCounter_i1_hq = 0U;
    } else if (ME11_ARID_DEF.Relay_Mode_c) {
      ME11_ARID_DEF.is_c31_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_m = ME11_IN_wait_3;
      ME11_ARID_DEF.temporalCounter_i1_hq = 0U;
    }
  } else if (!ME11_ARID_DEF.Relay_Mode_c) {
    ME11_ARID_DEF.is_Fault_m = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c31_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = false;
  } else {
    switch (ME11_ARID_DEF.is_Fault_m) {
     case ME11_IN_Flg1:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
      break;

     case ME11_IN_Flg2_j:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
      break;

     case ME11_IN_Flg3_p:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
      break;

     case ME11_IN_wait_2_i:
      if (ME11_ARID_DEF.Relay2_Mode) {
        ME11_ARID_DEF.is_Fault_m = ME11_IN_Flg3_p;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
      } else if (ME11_ARID_DEF.temporalCounter_i1_hq >= 200U) {
        ME11_ARID_DEF.is_Fault_m = ME11_IN_Flg2_j;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_hq >= 6000U) {
        ME11_ARID_DEF.is_Fault_m = ME11_IN_Flg1;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d = true;
      } else if (ME11_ARID_DEF.Relay1_Mode_c) {
        ME11_ARID_DEF.is_Fault_m = ME11_IN_wait_2_i;
        ME11_ARID_DEF.temporalCounter_i1_hq = 0U;
      }
      break;
    }
  }

  ME11_ARID_DEF.Relay1_Mode_g = ((ACSen_sHiPressFilter >= cal_HPProVal2) ||
    ((ACSen_sHiPressFilter > cal_HPProVal2Relay) && ME11_ARID_DEF.Relay1_Mode_g));
  ME11_ARID_DEF.Relay2_Mode_i = ((ACSen_sHiPressFilter >= cal_HPProVal3) ||
    ((ACSen_sHiPressFilter > cal_HPProVal3Relay) && ME11_ARID_DEF.Relay2_Mode_i));
  if (ME11_ARID_DEF.temporalCounter_i1_i2 < 127U) {
    ME11_ARID_DEF.temporalCounter_i1_i2++;
  }

  if (ME11_ARID_DEF.is_active_c33_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c33_ME11 = 1U;
    ME11_ARID_DEF.is_c33_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = false;
  } else if (ME11_ARID_DEF.is_c33_ME11 == ME11_IN_Default_k) {
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = false;
    if (ME11_ARID_DEF.Relay2_Mode_i) {
      ME11_ARID_DEF.is_c33_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_k = ME11_IN_Flg3_n;
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = true;
    } else if (ME11_ARID_DEF.Relay1_Mode_g) {
      ME11_ARID_DEF.is_c33_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_k = ME11_IN_wait_2;
      ME11_ARID_DEF.temporalCounter_i1_i2 = 0U;
    }
  } else if (!ME11_ARID_DEF.Relay1_Mode_g) {
    ME11_ARID_DEF.is_Fault_k = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c33_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = false;
  } else {
    switch (ME11_ARID_DEF.is_Fault_k) {
     case ME11_IN_Flg2:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = true;
      break;

     case ME11_IN_Flg3_n:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = true;
      break;

     default:
      if (ME11_ARID_DEF.Relay2_Mode_i) {
        ME11_ARID_DEF.is_Fault_k = ME11_IN_Flg3_n;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = true;
      } else if (ME11_ARID_DEF.temporalCounter_i1_i2 >= 100U) {
        ME11_ARID_DEF.is_Fault_k = ME11_IN_Flg2;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b = true;
      }
      break;
    }
  }

  ME11_ARID_DEF.Relay2_Mode_e = ((ACSen_sHiPressFilter >= cal_HPProVal3) ||
    ((ACSen_sHiPressFilter > cal_HPProVal3Relay) && ME11_ARID_DEF.Relay2_Mode_e));
  ME11_Flg3Cal((float32)ME11_ARID_DEF.Relay2_Mode_e, &rtb_ACTCtl_eCOMPFlg3Cal_c,
               &ME11_ARID_DEF.ARID_DEF_Flg3Cal_n);
  ME11_ARID_DEF.Relay2_Mode_b = ((ACSen_sHiPressFilter >= cal_HPProVal4) ||
    ((ACSen_sHiPressFilter > cal_HPProVal3) && ME11_ARID_DEF.Relay2_Mode_b));
  switch (ACTCtl_eCOMPSpdSecSts) {
   case 3:
    ACTCtl_bPressProtectFlg = ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_d;
    break;

   case 2:
    ACTCtl_bPressProtectFlg = ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_b;
    break;

   case 1:
    ACTCtl_bPressProtectFlg = rtb_ACTCtl_eCOMPFlg3Cal_c;
    break;

   default:
    ACTCtl_bPressProtectFlg = ME11_ARID_DEF.Relay2_Mode_b;
    break;
  }

  if (ACSen_sLoPressFilter <= 0.0F) {
    ACSen_sPressRateVal = 20.0F;
  } else {
    ACSen_sPressRateVal = 1.0F / ACSen_sLoPressFilter * ACSen_sHiPressFilter;
  }

  ME11_ARID_DEF.Relay_Mode_fq = ((ACSen_sPressRateVal >= cal_PressRateVal1) ||
    ((ACSen_sPressRateVal > cal_PressRateVal1Relay) &&
     ME11_ARID_DEF.Relay_Mode_fq));
  ME11_ARID_DEF.Relay1_Mode_d = ((ACSen_sPressRateVal >= cal_PressRateVal2) ||
    ((ACSen_sPressRateVal > cal_PressRateVal2Relay) &&
     ME11_ARID_DEF.Relay1_Mode_d));
  ME11_ARID_DEF.Relay2_Mode_bp = ((ACSen_sPressRateVal >= cal_PressRateVal3) ||
    ((ACSen_sPressRateVal > cal_PressRateVal3Relay) &&
     ME11_ARID_DEF.Relay2_Mode_bp));
  if (ME11_ARID_DEF.temporalCounter_i1_pw < 8191U) {
    ME11_ARID_DEF.temporalCounter_i1_pw++;
  }

  if (ME11_ARID_DEF.is_active_c93_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c93_ME11 = 1U;
    ME11_ARID_DEF.is_c93_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = false;
  } else if (ME11_ARID_DEF.is_c93_ME11 == ME11_IN_Default_k) {
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = false;
    if (ME11_ARID_DEF.Relay2_Mode_bp) {
      ME11_ARID_DEF.is_c93_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault = ME11_IN_Flg3_p;
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
    } else if (ME11_ARID_DEF.Relay1_Mode_d) {
      ME11_ARID_DEF.is_c93_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault = ME11_IN_wait_2_i;
      ME11_ARID_DEF.temporalCounter_i1_pw = 0U;
    } else if (ME11_ARID_DEF.Relay_Mode_fq) {
      ME11_ARID_DEF.is_c93_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault = ME11_IN_wait_3;
      ME11_ARID_DEF.temporalCounter_i1_pw = 0U;
    }
  } else if (!ME11_ARID_DEF.Relay_Mode_fq) {
    ME11_ARID_DEF.is_Fault = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c93_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = false;
  } else {
    switch (ME11_ARID_DEF.is_Fault) {
     case ME11_IN_Flg1:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
      break;

     case ME11_IN_Flg2_j:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
      break;

     case ME11_IN_Flg3_p:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
      break;

     case ME11_IN_wait_2_i:
      if (ME11_ARID_DEF.Relay2_Mode_bp) {
        ME11_ARID_DEF.is_Fault = ME11_IN_Flg3_p;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
      } else if (ME11_ARID_DEF.temporalCounter_i1_pw >= 150U) {
        ME11_ARID_DEF.is_Fault = ME11_IN_Flg2_j;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_pw >= 6000U) {
        ME11_ARID_DEF.is_Fault = ME11_IN_Flg1;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal = true;
      } else if (ME11_ARID_DEF.Relay1_Mode_d) {
        ME11_ARID_DEF.is_Fault = ME11_IN_wait_2_i;
        ME11_ARID_DEF.temporalCounter_i1_pw = 0U;
      }
      break;
    }
  }

  ME11_ARID_DEF.Relay1_Mode_j = ((ACSen_sPressRateVal >= cal_PressRateVal2) ||
    ((ACSen_sPressRateVal > cal_PressRateVal2Relay) &&
     ME11_ARID_DEF.Relay1_Mode_j));
  ME11_ARID_DEF.Relay2_Mode_ii = ((ACSen_sPressRateVal >= cal_PressRateVal3) ||
    ((ACSen_sPressRateVal > cal_PressRateVal3Relay) &&
     ME11_ARID_DEF.Relay2_Mode_ii));
  if (ME11_ARID_DEF.temporalCounter_i1_ox < 255U) {
    ME11_ARID_DEF.temporalCounter_i1_ox++;
  }

  if (ME11_ARID_DEF.is_active_c92_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c92_ME11 = 1U;
    ME11_ARID_DEF.is_c92_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = false;
  } else if (ME11_ARID_DEF.is_c92_ME11 == ME11_IN_Default_k) {
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = false;
    if (ME11_ARID_DEF.Relay2_Mode_ii) {
      ME11_ARID_DEF.is_c92_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_i = ME11_IN_Flg3_n;
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = true;
    } else if (ME11_ARID_DEF.Relay1_Mode_j) {
      ME11_ARID_DEF.is_c92_ME11 = ME11_IN_Fault_b;
      ME11_ARID_DEF.is_Fault_i = ME11_IN_wait_2;
      ME11_ARID_DEF.temporalCounter_i1_ox = 0U;
    }
  } else if (!ME11_ARID_DEF.Relay1_Mode_j) {
    ME11_ARID_DEF.is_Fault_i = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c92_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = false;
  } else {
    switch (ME11_ARID_DEF.is_Fault_i) {
     case ME11_IN_Flg2:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = true;
      break;

     case ME11_IN_Flg3_n:
      ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = true;
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_ox >= 150U) {
        ME11_ARID_DEF.is_Fault_i = ME11_IN_Flg2;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = true;
      } else if (ME11_ARID_DEF.Relay2_Mode_ii) {
        ME11_ARID_DEF.is_Fault_i = ME11_IN_Flg3_n;
        ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h = true;
      }
      break;
    }
  }

  ME11_ARID_DEF.Relay2_Mode_l = ((ACSen_sPressRateVal >= cal_PressRateVal3) ||
    ((ACSen_sPressRateVal > cal_PressRateVal3Relay) &&
     ME11_ARID_DEF.Relay2_Mode_l));
  ME11_Flg3Cal((float32)ME11_ARID_DEF.Relay2_Mode_l, &rtb_ACTCtl_eCOMPFlg3Cal,
               &ME11_ARID_DEF.ARID_DEF_Flg3Cal);
  ME11_ARID_DEF.Relay1_Mode_h = ((ACSen_sPressRateVal >= cal_PressRateVal4) ||
    ((ACSen_sPressRateVal > cal_PressRateVal3) && ME11_ARID_DEF.Relay1_Mode_h));
  switch (ACTCtl_eCOMPSpdSecSts) {
   case 3:
    ACTCtl_bPressRateFlg = ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal;
    break;

   case 2:
    ACTCtl_bPressRateFlg = ME11_ARID_DEF.ACTCtl_eCOMPFlg3Cal_h;
    break;

   case 1:
    ACTCtl_bPressRateFlg = rtb_ACTCtl_eCOMPFlg3Cal;
    break;

   default:
    ACTCtl_bPressRateFlg = ME11_ARID_DEF.Relay1_Mode_h;
    break;
  }

  COMP_OverDuty = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPOverDuty_flg;
  if (ME11_ARID_DEF.temporalCounter_i1_if < 31U) {
    ME11_ARID_DEF.temporalCounter_i1_if++;
  }

  if (ME11_ARID_DEF.temporalCounter_i2_f < 511U) {
    ME11_ARID_DEF.temporalCounter_i2_f++;
  }

  if (ME11_ARID_DEF.is_active_c35_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c35_ME11 = 1U;
    ME11_ARID_DEF.is_FaultJudge = ME11_IN_Normal_k;
    ME11_ARID_DEF.Sts_h = false;
    ME11_ARID_DEF.is_ClearFault = ME11_IN_HVOff_o;
    ME11_ARID_DEF.Count = 0U;
    ME11_ARID_DEF.ClearFlt_n = 0.0;
  } else {
    switch (ME11_ARID_DEF.is_FaultJudge) {
     case ME11_IN_Fault_ax:
      ME11_ARID_DEF.Sts_h = true;
      if ((!COMP_OverDuty) && (ME11_ARID_DEF.Count < 4)) {
        ME11_ARID_DEF.is_FaultJudge = ME11_IN_Normal_k;
        ME11_ARID_DEF.Sts_h = false;
      }
      break;

     case ME11_IN_Normal_k:
      ME11_ARID_DEF.Sts_h = false;
      if ((!COMP_OverDuty) && (ME11_ARID_DEF.ClearFlt_n == 0.0)) {
        ME11_ARID_DEF.is_FaultJudge = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_if = 0U;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_if >= 20U) {
        ME11_ARID_DEF.is_FaultJudge = ME11_IN_Fault_ax;
        ME11_ARID_DEF.Sts_h = true;
      } else if (!COMP_OverDuty) {
        ME11_ARID_DEF.is_FaultJudge = ME11_IN_Normal_k;
        ME11_ARID_DEF.Sts_h = false;
      }
      break;
    }

    if (ME11_ARID_DEF.is_ClearFault == ME11_IN_HVOff_o) {
      ME11_ARID_DEF.ClearFlt_n = 0.0;
      if (ME11_ARID_DEF.DataTypeConversion1 >= 2) {
        ME11_ARID_DEF.is_ClearFault = ME11_IN_HVOn_o;
        ME11_ARID_DEF.is_HVOn = ME11_IN_Normal_k;
        ME11_ARID_DEF.ClearFlt_n = 0.0;
      }
    } else if (ME11_ARID_DEF.DataTypeConversion1 < 2) {
      ME11_ARID_DEF.is_HVOn = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_ClearFault = ME11_IN_HVOff_o;
      ME11_ARID_DEF.Count = 0U;
      ME11_ARID_DEF.ClearFlt_n = 0.0;
    } else {
      switch (ME11_ARID_DEF.is_HVOn) {
       case ME11_IN_Clear_d:
        ME11_ARID_DEF.ClearFlt_n = 1.0;
        if (ME11_ARID_DEF.temporalCounter_i2_f >= 5U) {
          ME11_ARID_DEF.is_HVOn = ME11_IN_wait1_o;
          ME11_ARID_DEF.temporalCounter_i2_f = 0U;
          ME11_ARID_DEF.ClearFlt_n = 0.0;
        }
        break;

       case ME11_IN_Normal_k:
        ME11_ARID_DEF.ClearFlt_n = 0.0;
        if (ME11_ARID_DEF.Sts_h && (ME11_ARID_DEF.Count < 4)) {
          ME11_ARID_DEF.is_HVOn = ME11_IN_wait_k;
          ME11_ARID_DEF.temporalCounter_i2_f = 0U;
        }
        break;

       case ME11_IN_wait_k:
        if (ME11_ARID_DEF.temporalCounter_i2_f >= 50U) {
          ME11_ARID_DEF.is_HVOn = ME11_IN_Clear_d;
          ME11_ARID_DEF.temporalCounter_i2_f = 0U;
          ME11_ARID_DEF.ClearFlt_n = 1.0;
          b_previousEvent = ME11_ARID_DEF.Count + 1;
          if (ME11_ARID_DEF.Count + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Count = (uint8)b_previousEvent;
        }
        break;

       default:
        ME11_ARID_DEF.ClearFlt_n = 0.0;
        if (ME11_ARID_DEF.temporalCounter_i2_f >= 300U) {
          ME11_ARID_DEF.is_HVOn = ME11_IN_Normal_k;
          ME11_ARID_DEF.ClearFlt_n = 0.0;
        }
        break;
      }
    }
  }

  COMP_PI_Saturation = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD()
    )->VIPM_COMPPISaturation_flg;
  ME11_OverDuty1(ME11_ARID_DEF.DataTypeConversion1, COMP_PI_Saturation,
                 &ME11_ARID_DEF.Sts_b, &ME11_ARID_DEF.ClearFlt_m,
                 &ME11_ARID_DEF.ARID_DEF_OverDuty1);
  COMP_SelfCheckError = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD()
    )->VIPM_COMPSelfChkErr_enum;
  ME11_OverDuty1(ME11_ARID_DEF.DataTypeConversion1, (COMP_SelfCheckError == 1) ||
                 (COMP_SelfCheckError == 2), &ME11_ARID_DEF.Sts_a,
                 &ME11_ARID_DEF.ClearFlt_k, &ME11_ARID_DEF.ARID_DEF_OverDuty2);
  COMP_IPM_Error = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPIPMErr_flg;
  ME11_OverDuty1(ME11_ARID_DEF.DataTypeConversion1, COMP_IPM_Error,
                 &ME11_ARID_DEF.Sts_e, &ME11_ARID_DEF.ClearFlt_c,
                 &ME11_ARID_DEF.ARID_DEF_OverDuty3);
  COMP_OverCurrent = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPOvrCurr_enum;
  ME11_OverDuty1(ME11_ARID_DEF.DataTypeConversion1, COMP_OverCurrent == 1,
                 &ME11_ARID_DEF.Sts_d3, &ME11_ARID_DEF.ClearFlt_f,
                 &ME11_ARID_DEF.ARID_DEF_OverDuty4);
  COMP_CurrentOffset = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD()
    )->VIPM_COMPCurrOfst_flg;
  ME11_OverDuty1(ME11_ARID_DEF.DataTypeConversion1, COMP_CurrentOffset,
                 &ME11_ARID_DEF.Sts_d, &ME11_ARID_DEF.ClearFlt,
                 &ME11_ARID_DEF.ARID_DEF_OverDuty5);
  ACTCtl_bCOMPRealFault = (ME11_ARID_DEF.Sts_h || ME11_ARID_DEF.Sts_b ||
    ME11_ARID_DEF.Sts_a || ME11_ARID_DEF.Sts_e || ME11_ARID_DEF.Sts_d3 ||
    ME11_ARID_DEF.Sts_d);
  ACTCtl_bCOMPForbidFlg = (ACTCrl_bEnvCOMPLmt || rtb_Compare_cd_tmp ||
    ACTCtl_bOCOLmtFlg || ACTCtl_bCOMPEnbDelay || ACTCtl_bPressProtectFlg ||
    ACTCtl_bPressRateFlg || ACTCtl_bCOMPRealFault);
  if (ME11_ARID_DEF.temporalCounter_i1_c < 15U) {
    ME11_ARID_DEF.temporalCounter_i1_c++;
  }

  if (ME11_ARID_DEF.is_active_c152_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c152_ME11 = 1U;
    ME11_ARID_DEF.is_c152_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p = false;
  } else {
    switch (ME11_ARID_DEF.is_c152_ME11) {
     case ME11_IN_Default_k:
      ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p = false;
      if (ACTCtl_bCOMPForbidFlg) {
        ME11_ARID_DEF.is_c152_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_c = 0U;
      }
      break;

     case ME11_IN_Fault_b:
      ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p = true;
      if (!ACTCtl_bCOMPForbidFlg) {
        ME11_ARID_DEF.is_c152_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_c >= 10) {
        ME11_ARID_DEF.is_c152_ME11 = ME11_IN_Fault_b;
        ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p = true;
      } else if (!ACTCtl_bCOMPForbidFlg) {
        ME11_ARID_DEF.is_c152_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p = false;
      }
      break;
    }
  }

  rtb_Compare_gzu = (rtb_Compare_mos || rtb_Compare_cj1 || rtb_Compare_fhh ||
                     rtb_Compare_e5 || rtb_Compare_kq || rtb_Compare_lfo ||
                     ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p);
  BatPMP_RealRPM = 0.400390625F * (float32)
    Rte_IRead_Task_100ms_BatPMP_RealRPM_BatPMP_RealRPM();
  if (ME11_ARID_DEF.is_active_c145_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c145_ME11 = 1U;
    ME11_ARID_DEF.is_c145_ME11 = ME11_IN_Default_k;
    rtb_SOMCtl_WaterMode = 0U;
  } else if (ME11_ARID_DEF.is_c145_ME11 == ME11_IN_Default_k) {
    rtb_SOMCtl_WaterMode = 0U;
    if (ME11_ARID_DEF.DataTypeConversion1 >= 1) {
      ME11_ARID_DEF.is_c145_ME11 = ME11_IN_WatMode;
      ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
    }
  } else if (ME11_ARID_DEF.DataTypeConversion1 < 1) {
    ME11_ARID_DEF.is_WatMode = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c145_ME11 = ME11_IN_Default_k;
    rtb_SOMCtl_WaterMode = 0U;
  } else {
    switch (ME11_ARID_DEF.is_WatMode) {
     case ME11_IN_Balance:
      rtb_SOMCtl_WaterMode = 4U;
      if (!SOMCtl_bMotorLTRAndBatBalFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
        rtb_SOMCtl_WaterMode = 0U;
      }
      break;

     case ME11_IN_HStr_m:
      rtb_SOMCtl_WaterMode = 3U;
      if (!SOMCtl_bBatTSFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
        rtb_SOMCtl_WaterMode = 0U;
      }
      break;

     case ME11_IN_LTR_d:
      rtb_SOMCtl_WaterMode = 1U;
      if (!SOMCtl_bMotAndBatLTRFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
        rtb_SOMCtl_WaterMode = 0U;
      }
      break;

     case ME11_IN_MotLTRAndBat:
      rtb_SOMCtl_WaterMode = 2U;
      if (!SOMCtl_bBatHeatFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
        rtb_SOMCtl_WaterMode = 0U;
      }
      break;

     case ME11_IN_MotLTRAndBatCool:
      rtb_SOMCtl_WaterMode = 2U;
      if (!SOMCtl_bBatCoolFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
        rtb_SOMCtl_WaterMode = 0U;
      }
      break;

     case ME11_IN_MotorHeatBat:
      rtb_SOMCtl_WaterMode = 5U;
      if (!SOMCtl_bMotHeatBatFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Off_g;
        rtb_SOMCtl_WaterMode = 0U;
      }
      break;

     default:
      rtb_SOMCtl_WaterMode = 0U;
      if (SOMCtl_bBatCoolFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_MotLTRAndBatCool;
        rtb_SOMCtl_WaterMode = 2U;
      } else if (SOMCtl_bBatTSFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_HStr_m;
        rtb_SOMCtl_WaterMode = 3U;
      } else if (SOMCtl_bMotHeatBatFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_MotorHeatBat;
        rtb_SOMCtl_WaterMode = 5U;
      } else if (SOMCtl_bMotorLTRAndBatBalFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_Balance;
        rtb_SOMCtl_WaterMode = 4U;
      } else if (SOMCtl_bMotAndBatLTRFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_LTR_d;
        rtb_SOMCtl_WaterMode = 1U;
      } else if (SOMCtl_bBatHeatFlg) {
        ME11_ARID_DEF.is_WatMode = ME11_IN_MotLTRAndBat;
        rtb_SOMCtl_WaterMode = 2U;
      }
      break;
    }
  }

  if (cal_WaterModeEnb) {
    SOMCtl_eWaterMode = cal_WaterModeData;
  } else {
    SOMCtl_eWaterMode = rtb_SOMCtl_WaterMode;
  }

  rtb_DataTypeConversion1_g = SOMCtl_eWaterMode;
  rtb_RelationalOperator_lt = (cal_LTRIGBTTempMotPMPCtrl_1X[0] >
    (Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
    ->VIPM_INV2IgbtMaxTemp_C);
  if (rtb_RelationalOperator_lt) {
    rtb_Compare_i1 = cal_LTRIGBTTempMotPMPCtrl_1Y[0];
  } else {
    rtb_AND1_h0y =
      ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
       ->VIPM_INV2IgbtMaxTemp_C >= cal_LTRIGBTTempMotPMPCtrl_1X[1]);
    if (rtb_AND1_h0y) {
      rtb_Compare_i1 = cal_LTRIGBTTempMotPMPCtrl_1Y[2];
    } else {
      rtb_Compare_i1 = cal_LTRIGBTTempMotPMPCtrl_1Y[1];
    }
  }

  rtb_RelationalOperator_lt = (cal_LTRMotorTempMotPMPCtrl_1X[0] >
    (Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
    ->VIPM_INV2MotorMaxTemp_C);
  if (rtb_RelationalOperator_lt) {
    rtb_Compare_bxp = cal_LTRMotorTempMotPMPCtrl_1Y[0];
  } else {
    rtb_AND1_h0y =
      ((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
       ->VIPM_INV2MotorMaxTemp_C >= cal_LTRMotorTempMotPMPCtrl_1X[1]);
    if (rtb_AND1_h0y) {
      rtb_Compare_bxp = cal_LTRMotorTempMotPMPCtrl_1Y[2];
    } else {
      rtb_Compare_bxp = cal_LTRMotorTempMotPMPCtrl_1Y[1];
    }
  }

  rtb_RelationalOperator_lt = (cal_LTRIPUTempMotPMPCtrl_1X[0] >
    (Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT())
    ->VIPM_IPUDeviceIntTemp_C);
  if (rtb_RelationalOperator_lt) {
    rtb_Compare_nw0 = cal_LTRIPUTempMotPMPCtrl_1Y[0];
  } else {
    rtb_AND1_h0y =
      ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT()
       )->VIPM_IPUDeviceIntTemp_C >= cal_LTRIPUTempMotPMPCtrl_1X[1]);
    if (rtb_AND1_h0y) {
      rtb_Compare_nw0 = cal_LTRIPUTempMotPMPCtrl_1Y[2];
    } else {
      rtb_Compare_nw0 = cal_LTRIPUTempMotPMPCtrl_1Y[1];
    }
  }

  if (rtb_Compare_i1 >= rtb_Compare_bxp) {
    rtb_Compare_bxp = rtb_Compare_i1;
  }

  if (rtb_Compare_bxp < rtb_Compare_nw0) {
    rtb_Compare_bxp = rtb_Compare_nw0;
  }

  BCV_PosRec = Rte_IRead_Task_100ms_C5WVPosRec_C5WVPosRec();
  if (ACCtl_bExhFlg) {
    rtb_Compare_nw0 = cal_C5WVExhPosVal;
  } else if (cal_BatModeTestCtrl) {
    rtb_Compare_nw0 = 13U;
  } else if (rtb_Switch2_ht == 13) {
    rtb_Compare_nw0 = 12U;
  } else if (rtb_Switch2_ht == 10) {
    rtb_Compare_nw0 = 25U;
  } else {
    switch (SOMCtl_eWaterMode) {
     case 1:
      rtb_Compare_nw0 = 12U;
      break;

     case 2:
      rtb_Compare_nw0 = 25U;
      break;

     case 3:
      rtb_Compare_nw0 = 13U;
      break;

     case 4:
      rtb_Compare_nw0 = 25U;
      break;

     case 5:
      rtb_Compare_nw0 = 0U;
      break;

     case 6:
      rtb_Compare_nw0 = 0U;
      break;

     default:
      rtb_Compare_nw0 = 25U;
      break;
    }
  }

  rtb_RelationalOperator_lt = ((uint16)(BCV_PosRec - rtb_Compare_nw0) >=
    cal_BCVPosDiffMaxVal);
  rtb_AND1_h0y = !rtb_RelationalOperator_lt;
  if (ME11_ARID_DEF.temporalCounter_i1_ev < 63U) {
    ME11_ARID_DEF.temporalCounter_i1_ev++;
  }

  if (ME11_ARID_DEF.is_active_c163_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c163_ME11 = 1U;
    ME11_ARID_DEF.is_c163_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.C_b = false;
  } else {
    switch (ME11_ARID_DEF.is_c163_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.C_b = false;
      if (ME11_ARID_DEF.DataTypeConversion1 >= 2) {
        ME11_ARID_DEF.is_c163_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.C_b = true;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.C_b = true;
      if (ME11_ARID_DEF.DataTypeConversion1 <= 1) {
        ME11_ARID_DEF.is_c163_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_ev = 0U;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_ev >= 60U) {
        ME11_ARID_DEF.is_c163_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.C_b = false;
      } else if (ME11_ARID_DEF.DataTypeConversion1 >= 2) {
        ME11_ARID_DEF.is_c163_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.C_b = true;
      }
      break;
    }
  }

  if (cal_MotPMPSpdSetDataEnb) {
    rtb_Compare_bxp = cal_MotPMPSpdSetData;
  } else if (rtb_AND1_h0y && ME11_ARID_DEF.C_b) {
    if (ACCtl_bExhFlg) {
      rtb_Compare_bxp = 50U;
    } else if (rtb_Switch2_ht == 10) {
      rtb_Compare_bxp = 100U;
    } else {
      switch (SOMCtl_eWaterMode) {
       case 1:
       case 4:
       case 2:
        break;

       case 5:
        rtb_Compare_bxp = cal_MotPMPMotHeatBatSpd;
        break;

       case 3:
        rtb_Compare_bxp = cal_MotPMPThStoSpd;
        break;
      }

      if (rtb_Compare_bxp < cal_MotPMPDefaultSpd) {
        rtb_Compare_bxp = cal_MotPMPDefaultSpd;
      }
    }
  } else {
    rtb_Compare_bxp = 10U;
  }

  if (rtb_Compare_bxp > 100) {
    rtb_Compare_bxp = 100U;
  } else if (rtb_Compare_bxp < 10) {
    rtb_Compare_bxp = 10U;
  }

  rtb_Compare_oc = (ME11_ARID_DEF.Delay_DSTATE_lv == 1);
  if (rtb_DataTypeConversion1_l == 1) {
    ME11_ARID_DEF.Delay_DSTATE_lv = 1U;
  } else if (rtb_DataTypeConversion1_l == 6) {
    ME11_ARID_DEF.Delay_DSTATE_lv = 2U;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_lv = 0U;
  }

  if (ME11_ARID_DEF.is_active_c151_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c151_ME11 = 1U;
    ME11_ARID_DEF.is_c151_ME11 = ME11_IN_OFF;
    ME11_ARID_DEF.BatPMPSpd = 10U;
    ME11_ARID_DEF.counter = 0U;
  } else if (ME11_ARID_DEF.is_c151_ME11 == ME11_IN_OFF) {
    if (rtb_Compare_oc && (ME11_ARID_DEF.Delay_DSTATE_lv !=
                           ME11_ARID_DEF.DelayInput1_DSTATE_ju)) {
      ME11_ARID_DEF.is_c151_ME11 = ME11_IN_ON;
      ME11_ARID_DEF.BatPMPSpd = cal_BatCoolStopBatPMPSpd;
    }
  } else if (ME11_ARID_DEF.counter > (sint32)(cal_BatCoolStopBatPMPRunTime * 10U))
  {
    ME11_ARID_DEF.is_c151_ME11 = ME11_IN_OFF;
    ME11_ARID_DEF.BatPMPSpd = 10U;
    ME11_ARID_DEF.counter = 0U;
  } else {
    b_previousEvent = ME11_ARID_DEF.counter + 1;
    if (ME11_ARID_DEF.counter + 1 > 65535) {
      b_previousEvent = 65535;
    }

    ME11_ARID_DEF.counter = (uint16)b_previousEvent;
  }

  ME11_Delay1(ME11_ARID_DEF.DataTypeConversion1, &ME11_ARID_DEF.C_j,
              &ME11_ARID_DEF.ARID_DEF_Delay1);
  if (cal_BatPMPSpdSetDataEnb) {
    rtb_MultiportSwitch1 = cal_BatPMPSpdSetData;
  } else if (rtb_AND1_h0y && ME11_ARID_DEF.C_j) {
    if (ACCtl_bExhFlg) {
      rtb_MultiportSwitch1 = 50U;
    } else {
      switch (SOMCtl_eWaterMode) {
       case 4:
        rtb_MultiportSwitch1 = look1_iflftu8Df_binlca(BMS_HVBatCellTempMax -
          BMS_HVBatCellTempMin, (const float32 *)&cal_BatPumpBal_1X[0], (const
          uint8 *)&cal_BatPumpBal_CUR[0], 3U);
        break;

       case 5:
        rtb_MultiportSwitch1 = cal_BatPumpMotHeatBatSpd;
        break;

       case 3:
        rtb_MultiportSwitch1 = look1_iflftu8Df_binlca(BMS_HVBatCellTempMax -
          BMS_HVBatCellTempMin, (const float32 *)&cal_BatPumpThSto_1X[0], (const
          uint8 *)&cal_BatPumpThSto_CUR[0], 3U);
        break;

       case 1:
        rtb_MultiportSwitch1 = rtb_Compare_bxp;
        break;

       case 2:
        rtb_MultiportSwitch1 = cal_BatPumpMotLTRAndBatCHSpd;
        break;

       default:
        rtb_MultiportSwitch1 = look1_iflftu8Df_binlca(BMS_HVBatCellTempMax -
          BMS_HVBatCellTempMin, (const float32 *)&cal_BatPumpB1Off_1X[0], (const
          uint8 *)&cal_BatPumpB1Off_CUR[0], 3U);
        break;
      }

      switch (rtb_Switch2_ht) {
       case 2:
       case 3:
       case 13:
       case 14:
        rtb_SOMCtl_WaterMode = cal_BatPumpCtrlASpd;
        break;

       case 5:
       case 6:
       case 10:
        rtb_SOMCtl_WaterMode = cal_BatPMPBatHeatSpd;
        break;

       default:
        rtb_SOMCtl_WaterMode = 10U;
        break;
      }

      if (rtb_SOMCtl_WaterMode >= rtb_MultiportSwitch1) {
        rtb_MultiportSwitch1 = rtb_SOMCtl_WaterMode;
      }

      if (rtb_MultiportSwitch1 < ME11_ARID_DEF.BatPMPSpd) {
        rtb_MultiportSwitch1 = ME11_ARID_DEF.BatPMPSpd;
      }
    }
  } else {
    rtb_MultiportSwitch1 = 10U;
  }

  if (rtb_MultiportSwitch1 > 100) {
    rtb_MultiportSwitch1 = 100U;
  } else if (rtb_MultiportSwitch1 < 10) {
    rtb_MultiportSwitch1 = 10U;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_ih < 63U) {
    ME11_ARID_DEF.temporalCounter_i1_ih++;
  }

  if (ME11_ARID_DEF.is_active_c125_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c125_ME11 = 1U;
    ME11_ARID_DEF.is_c125_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c = false;
  } else {
    switch (ME11_ARID_DEF.is_c125_ME11) {
     case ME11_IN_Default_k:
      ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c = false;
      if (rtb_MultiportSwitch1 > BatPMP_RealRPM + (float32)cal_BATPMPSpdDiffVal)
      {
        ME11_ARID_DEF.is_c125_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_ih = 0U;
      }
      break;

     case ME11_IN_Fault_b:
      ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c = true;
      if ((rtb_MultiportSwitch1 < BatPMP_RealRPM + (float32)cal_BATPMPSpdDiffVal)
          && (rtb_MultiportSwitch1 > BatPMP_RealRPM - (float32)
              cal_BATPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c125_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_ih >= 50U) {
        ME11_ARID_DEF.is_c125_ME11 = ME11_IN_Fault_b;
        ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c = true;
      } else if ((rtb_MultiportSwitch1 < BatPMP_RealRPM + (float32)
                  cal_BATPMPSpdDiffVal) && (rtb_MultiportSwitch1 >
                  BatPMP_RealRPM - (float32)cal_BATPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c125_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c = false;
      }
      break;
    }
  }

  ACTCtl_bBatPMPSpdFlt = ((rtb_MultiportSwitch1 > 12) &&
    ME11_ARID_DEF.ACTCtl_bBatPMPSpdFlt_c);
  AcPMP_RealRPM = 0.400390625F * (float32)
    Rte_IRead_Task_100ms_AcPMP_RealRPM_AcPMP_RealRPM();
  ME11_ARID_DEF.Relay_Mode_od = ((BMS_InletCooltActlTemp >=
    cal_BMSInletTempHighOffMCV) || ((BMS_InletCooltActlTemp >
    cal_BMSInletTempLowOnMCV) && ME11_ARID_DEF.Relay_Mode_od));
  rtb_Relay_f = ME11_ARID_DEF.Relay_Mode_od;
  switch (rtb_Switch2_ht) {
   case 4:
   case 13:
    ACTCtl_eACPumpRefSpd = cal_ACPumpCtrlASpd;
    break;

   case 5:
    ACTCtl_eACPumpRefSpd = cal_ACPumpBatHeatSpd;
    break;

   case 6:
    ACTCtl_eACPumpRefSpd = cal_ACPumpDoubleHeatSpd;
    break;

   case 7:
   case 8:
   case 14:
    ACTCtl_eACPumpRefSpd = cal_ACPumpDehSpd;
    break;

   case 12:
    if (ME11_ARID_DEF.Relay_Mode_od) {
      ACTCtl_eACPumpRefSpd = cal_ACPumpDefSpd;
    } else {
      ACTCtl_eACPumpRefSpd = cal_ACPumpBatHeatSpd;
    }
    break;

   default:
    ACTCtl_eACPumpRefSpd = cal_ACPumpDefSpd;
    break;
  }

  rtb_AND1_h0y = ME11_ARID_DEF.Delay_DSTATE_po;
  rtb_Compare_oc = ((sint32)ME11_ARID_DEF.Delay_DSTATE_po < (sint32)
                    ME11_ARID_DEF.DelayInput1_DSTATE_kp);
  if (ME11_ARID_DEF.temporalCounter_i1_fy < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_fy++;
  }

  if (ME11_ARID_DEF.is_active_c121_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c121_ME11 = 1U;
    ME11_ARID_DEF.is_c121_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.AcSpd = 10U;
  } else {
    switch (ME11_ARID_DEF.is_c121_ME11) {
     case ME11_IN_Default_k:
      if (rtb_Compare_oc) {
        ME11_ARID_DEF.is_c121_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.AcSpd = cal_PTCOffAcPMPSpd;
      }
      break;

     case ME11_IN_On_li:
      if (!rtb_Compare_oc) {
        ME11_ARID_DEF.is_c121_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_fy = 0U;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_fy >= 600U) {
        ME11_ARID_DEF.is_c121_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.AcSpd = 10U;
      } else if (rtb_Compare_oc) {
        ME11_ARID_DEF.is_c121_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.AcSpd = cal_PTCOffAcPMPSpd;
      }
      break;
    }
  }

  if (BMS_HVBatCellTempMin <= cal_ExtDefBatMinT) {
    rtb_Delay_ci = cal_ExtDefPTCTrgTemp;
  } else {
    rtb_Delay_ci = -40.0F;
  }

  rtb_AND1_c = ((rtb_Delay_ci >= 1.0F) && (rtb_Switch2_ht == 10));
  ME11_ARID_DEF.Delay_DSTATE_po = ME11_ARID_DEF.Delay_DSTATE_en;
  MCV_PosRec = Rte_IRead_Task_100ms_C3WV_PosRec_C3WV_PosRec();
  BMS_HVBatCellTempAve =
    (Rte_IRead_Task_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT())
    ->VIPM_BMSHVBatCellTempAve_C;
  if (ME11_ARID_DEF.DataTypeConversion1 == 4) {
    if (ACSen_sEnvTempCor <= cal_DCBatHeatEnvTemp[0]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_k = cal_DCBatHeatT1[0];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_m = cal_DCBatHeatT2[0];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else if (ACSen_sEnvTempCor <= cal_DCBatHeatEnvTemp[1]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_k = cal_DCBatHeatT1[1];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_m = cal_DCBatHeatT2[1];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else if (ACSen_sEnvTempCor > cal_DCBatHeatEnvTemp[1]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_k = cal_DCBatHeatT1[2];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_m = cal_DCBatHeatT2[2];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else {
      SOMCtl_bCalTempBatHeatFlg = false;
    }

    SOMCtl_sBatHeatT1 = ME11_ARID_DEF.SOMCtl_sBatHeatT1_k;
    SOMCtl_sBatHeatT2 = ME11_ARID_DEF.SOMCtl_sBatHeatT2_m;
  }

  if (ME11_ARID_DEF.DataTypeConversion1 == 3) {
    if (ACSen_sEnvTempCor <= cal_ACBatHeatEnvTemp[0]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_e = cal_ACBatHeatT1[0];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_mu = cal_ACBatHeatT2[0];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else if (ACSen_sEnvTempCor <= cal_ACBatHeatEnvTemp[1]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_e = cal_ACBatHeatT1[1];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_mu = cal_ACBatHeatT2[1];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else if (ACSen_sEnvTempCor > cal_ACBatHeatEnvTemp[1]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_e = cal_ACBatHeatT1[2];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_mu = cal_ACBatHeatT2[2];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else {
      SOMCtl_bCalTempBatHeatFlg = false;
    }

    SOMCtl_sBatHeatT1 = ME11_ARID_DEF.SOMCtl_sBatHeatT1_e;
    SOMCtl_sBatHeatT2 = ME11_ARID_DEF.SOMCtl_sBatHeatT2_mu;
  }

  if ((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
      (ME11_ARID_DEF.DataTypeConversion1 == 5)) {
    if (ACSen_sEnvTempCor <= cal_NmlBatHeatEnvTemp[0]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_a = cal_NmlBatHeatT1[0];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_p = cal_NmlBatHeatT2[0];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else if (ACSen_sEnvTempCor <= cal_NmlBatHeatEnvTemp[1]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_a = cal_NmlBatHeatT1[1];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_p = cal_NmlBatHeatT2[1];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else if (ACSen_sEnvTempCor > cal_NmlBatHeatEnvTemp[1]) {
      ME11_ARID_DEF.SOMCtl_sBatHeatT1_a = cal_NmlBatHeatT1[2];
      ME11_ARID_DEF.SOMCtl_sBatHeatT2_p = cal_NmlBatHeatT2[2];
      SOMCtl_bCalTempBatHeatFlg = true;
    } else {
      SOMCtl_bCalTempBatHeatFlg = false;
    }

    SOMCtl_sBatHeatT1 = ME11_ARID_DEF.SOMCtl_sBatHeatT1_a;
    SOMCtl_sBatHeatT2 = ME11_ARID_DEF.SOMCtl_sBatHeatT2_p;
  }

  if (BMS_HVBatCellTempMin > SOMCtl_sBatHeatT2) {
    ME11_ARID_DEF.Merge = 0U;
  }

  rtb_Compare_oc = (ME11_ARID_DEF.DataTypeConversion1 == 3);
  if (ME11_ARID_DEF.DataTypeConversion1 == 4) {
    SOMCtl_sBatHeatPTCTrgT = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32
      *)&cal_DCChrgBatHeatTrgTemp_1X[0], (const float32 *)
      &cal_DCChrgBatHeatTrgTemp_CUR[0], 6U);
  } else if (ME11_ARID_DEF.DataTypeConversion1 == 3) {
    SOMCtl_sBatHeatPTCTrgT = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32
      *)&cal_ACChrgBatHeatTrgTemp_1X[0], (const float32 *)
      &cal_ACChrgBatHeatTrgTemp_CUR[0], 6U);
  } else if (ME11_ARID_DEF.DataTypeConversion1 == 5) {
    SOMCtl_sBatHeatPTCTrgT = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32
      *)&cal_DisChrgBatHeatTrgTemp_1X[0], (const float32 *)
      &cal_DisChrgBatHeatTrgTemp_CUR[0], 6U);
  } else {
    SOMCtl_sBatHeatPTCTrgT = 0.0F;
  }

  SOMCtl_sBatHeatTrgTempComp = look1_iflf_binlca(ACTCtl_sBatHeatInletTrgT -
    BMS_InletCooltActlTemp, (const float32 *)&cal_BatHeatTrgTempComp_1X[0], (
    const float32 *)&cal_BatHeatTrgTempComp_CUR[0], 10U);
  if (cal_BatTrgTempEnb) {
    SOMCtl_sBatTrgTemp = cal_BatTrgTempData;
  } else {
    SOMCtl_sBatTrgTemp = SOMCtl_sBatHeatPTCTrgT - SOMCtl_sBatHeatTrgTempComp;
  }

  ACCCtl_sSetPtcDesTempMax = look2_ifu8lftf_binlca(ACSen_sEnvTempCor,
    ME11_ARID_DEF.Delay1_DSTATE_o, (const float32 *)&cal_SetPtcDesTempMax_2X[0],
    (const uint8 *)&cal_SetPtcDesTempMax_2Y[0], (const float32 *)
    &cal_SetPtcDesTempMax_MAP[0], ME11_ConstP.pooled34, 10U);
  if (ACCtl_tPsDVT >= ACCtl_tDrDVT) {
    rtb_Delay1_ie = ACCtl_tPsDVT;
  } else {
    rtb_Delay1_ie = ACCtl_tDrDVT;
  }

  SENCtl_uEVAPXTempVol = get_EVAPTempValtage();
  rtb_Add = (float32)((sint16)SENCtl_uEVAPXTempVol -
                      look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uEVAPXTempVol, (
    const uint16 *)&cal_EVAPTempVolAmend_1X[0], (const sint16 *)
    &cal_EVAPTempVolAmend_CUR[0], 1U));
  rtb_Add_cy = cal_ADCVCCVal - rtb_Add;
  ME11_Judge(rtb_Add > cal_SensorTempUpFlt, rtb_Add < cal_SensorTempDownFlg, 20,
             &ME11_ARID_DEF.SenSts_n, &ME11_ARID_DEF.ARID_DEF_Judge_g);
  ACSen_eEVAPTSenSts = ME11_ARID_DEF.SenSts_n;
  if (rtb_Add_cy > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Add / rtb_Add_cy;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  SEN_EvapTRaw = look1_iflf_binlca(rtb_DataTypeConversion23 * 3000.0F, (const
    float32 *)&cal_TEvapOutRaw_1X[0], (const float32 *)&cal_TEvapOutRaw_CUR[0],
    29U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_m != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ot = SEN_EvapTRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ot = SEN_EvapTRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ot * 0.100000024F;
  if (cal_EvapTempDataEnb) {
    ACSen_sEvapTempFilter = cal_EvapTempData;
  } else {
    ACSen_sEvapTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ot;
  }

  ACPTC_HeatingCond1 = ACSen_sEvapTempFilter + cal_TevapUpStepMin;
  ACPTC_HeatingCond2 = ACSen_sEnvTempCor - cal_ErrAmbTDvtForPtcUL;
  ACPTC_HeatedCond1 = ME11_ARID_DEF.Delay_DSTATE_e + cal_TevapUpStepMin;
  ACPtc_CloseCond1 = ACSen_sEnvTempCor + cal_ErrAmbTDvtForPtcLL;
  if (ME11_ARID_DEF.is_active_c53_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c53_ME11 = 1U;
    ME11_ARID_DEF.is_c53_ME11 = ME11_IN_PTC_Heating;
    ACCtl_stACPTCHeated = false;
  } else {
    switch (ME11_ARID_DEF.is_c53_ME11) {
     case ME11_IN_PTC_Heating:
      ACCtl_stACPTCHeated = false;
      if ((rtb_Delay1_ie > ACPTC_HeatingCond1) && (rtb_Delay1_ie <
           ACPTC_HeatingCond2)) {
        ME11_ARID_DEF.is_c53_ME11 = ME11_IN_PTC_Stoping;
        ME11_ARID_DEF.RecordInitialEvapTemp = ACSen_sEvapTempFilter;
        ACCtl_stACPTCHeated = false;
        ME11_ARID_DEF.EvapTempUpWaiteTime = 0U;
      }
      break;

     case ME11_IN_PTC_Stop:
      ACCtl_stACPTCHeated = true;
      if (rtb_Delay1_ie > ACPtc_CloseCond1) {
        ME11_ARID_DEF.is_c53_ME11 = ME11_IN_PTC_Heating;
        ACCtl_stACPTCHeated = false;
      }
      break;

     default:
      ACCtl_stACPTCHeated = false;
      if ((ME11_ARID_DEF.EvapTempUpWaiteTime > cal_TevapUpTime) ||
          (rtb_Delay1_ie > ACPtc_CloseCond1)) {
        ME11_ARID_DEF.EvapTempUpWaiteTime = 0U;
        ME11_ARID_DEF.is_c53_ME11 = ME11_IN_PTC_Heating;
        ACCtl_stACPTCHeated = false;
      } else if (ACSen_sEvapTempFilter > ACPTC_HeatedCond1) {
        ME11_ARID_DEF.EvapTempUpWaiteTime = 0U;
        ME11_ARID_DEF.is_c53_ME11 = ME11_IN_PTC_Stop;
        ACCtl_stACPTCHeated = true;
      } else {
        b_previousEvent = ME11_ARID_DEF.EvapTempUpWaiteTime + 1;
        if (ME11_ARID_DEF.EvapTempUpWaiteTime + 1 > 65535) {
          b_previousEvent = 65535;
        }

        ME11_ARID_DEF.EvapTempUpWaiteTime = (uint16)b_previousEvent;
      }
      break;
    }
  }

  rtb_Delay_ku = ME11_ARID_DEF.Delay_DSTATE_hr;
  ACPTCDrDesFanCor = look1_iu8lftf_binlca(ME11_ARID_DEF.Delay_DSTATE_hr, (const
    uint8 *)&cal_ACPTCDesFanCor_1X[0], (const float32 *)&cal_ACPTCDesFanCor_CUR
    [0], 3U);
  ACPTCDrDesEnvCor = look2_iflf_binlca(ACSen_sEnvTempCor,
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpd_kph, (const float32 *)&cal_ACPTCDesEnvCor_2X[0], (const
    float32 *)&cal_ACPTCDesEnvCor_2Y[0], (const float32 *)
    &cal_ACPTCDesEnvCor_MAP[0], ME11_ConstP.pooled37, 6U);
  ACPTCDrDesCabinCor = look1_iflf_binlca(GlbDa_tCabinInvent, (const float32 *)
    &cal_ACPTCDesCabinCor_1X[0], (const float32 *)&cal_ACPTCDesCabinCor_CUR[0],
    7U);
  switch (rtb_Delay_n2) {
   case BlowerModes_FaceMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_ACPTCDesBacAC_1X[0], (const float32 *)&cal_ACPTCDesBacAC_CUR[0], 11U);
    break;

   case BlowerModes_FaceHeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_ACPTCDesBacBi_1X[0], (const float32 *)&cal_ACPTCDesBacBi_CUR[0], 11U);
    break;

   case BlowerModes_HeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_ACPTCDesBacFoot_1X[0], (const float32 *)&cal_ACPTCDesBacFoot_CUR[0],
      11U);
    break;

   case BlowerModes_HeaterDeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_ACPTCDesBacFootDe_1X[0], (const float32 *)&cal_ACPTCDesBacFootDe_CUR
      [0], 11U);
    break;

   case BlowerModes_DeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_ACPTCDesBacDefog_1X[0], (const float32 *)&cal_ACPTCDesBacDefog_CUR[0],
      11U);
    break;

   default:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_ACPTCDesBacBi_1X[0], (const float32 *)&cal_ACPTCDesBacBi_CUR[0], 11U);
    break;
  }

  if (ACSen_eAirInletPer < cal_ACRecirRatioLmt) {
    rtb_MultiportSwitch2_e = ACPTCDrDesEnvCor;
  } else {
    rtb_MultiportSwitch2_e = ACPTCDrDesCabinCor;
  }

  ACCtl_tDrSetBasicPTC = (ACPTCDrDesFanCor + rtb_MultiportSwitch2_e) +
    rtb_DataTypeConversion23;
  if (ACCtl_tDrSetBasicPTC > 80.0F) {
    ACCtl_tDrSetBasicPTC = 80.0F;
  } else if (ACCtl_tDrSetBasicPTC < -40.0F) {
    ACCtl_tDrSetBasicPTC = -40.0F;
  }

  rtb_OR2_a = ((rtb_Delay_n2 != BlowerModes_DeforstMode) &&
               ((ME11_ARID_DEF.Switch1_nv != ACOff) && ME11_ARID_DEF.Switch_c));
  rtb_Compare_ny = !rtb_RelationalOperator_kh;
  rtb_LogicalOperator1_f = (rtb_Compare_ny && rtb_OR2_a);
  if (cal_FixPIDSecletFlag) {
    rtb_Delay1_ie = ACCtl_tDrDVT - ACCtl_tLeftDuct;
    ME11_deadzone_h(rtb_Delay1_ie, 0.5, &rtb_flag_nk);
    rtb_Compare_dsx = (ACCtl_tDrDVT >= ACCtl_tLeftDuct);
    if (rtb_flag_nk) {
      rtb_Delay1_ie = 0.0F;
    } else if (!rtb_Compare_dsx) {
      rtb_Delay1_ie = ACCtl_tLeftDuct - ACCtl_tDrDVT;
    }

    if (rtb_Compare_dsx) {
      rtb_Add = cal_DrPtcDesValPIDIntegDeadBand4InHeat;
    } else {
      rtb_Add = cal_DrPtcDesValPIDIntegDeadBand4OutHeat;
    }

    ME11_P_NEG(!rtb_Compare_dsx, rtb_Delay1_ie, rtb_Add, cal_DrPtcDesValPIDKiNeg,
               cal_DrPtcDesValPIDKi, (float32 *)&ACCtl_tDrPTCICor);
    ME11_P_POS(rtb_Compare_dsx, rtb_Delay1_ie, rtb_Add, cal_DrPtcDesValPIDKiPos,
               cal_DrPtcDesValPIDKi, (float32 *)&ACCtl_tDrPTCICor);
    if (rtb_LogicalOperator1_f) {
      switch (ME11_ARID_DEF.Delay_DSTATE_b4) {
       case 0:
        if (rtb_Compare_dsx) {
          ACCtl_tDrPTCISum = ACCtl_tDrPTCISum + ACCtl_tDrPTCICor;
        } else {
          ACCtl_tDrPTCISum = ACCtl_tDrPTCISum - ACCtl_tDrPTCICor;
        }
        break;

       case 1:
        if (!rtb_Compare_dsx) {
          ACCtl_tDrPTCISum = ACCtl_tDrPTCISum - ACCtl_tDrPTCICor;
        }
        break;

       case 2:
        if (rtb_Compare_dsx) {
          ACCtl_tDrPTCISum = ACCtl_tDrPTCISum + ACCtl_tDrPTCICor;
        }
        break;

       case 3:
        break;
      }

      if ((ACCtl_tDrPTCISum - 8000.0F) + 8000.0F > cal_DrPtcDesValPID_IsumMax) {
        ACCtl_tDrPTCISum = cal_DrPtcDesValPID_IsumMax;
      } else if ((ACCtl_tDrPTCISum - 8000.0F) + 8000.0F <
                 cal_DrPtcDesValPID_IsumMin) {
        ACCtl_tDrPTCISum = cal_DrPtcDesValPID_IsumMin;
      } else {
        ACCtl_tDrPTCISum = (ACCtl_tDrPTCISum - 8000.0F) + 8000.0F;
      }
    } else {
      ACCtl_tDrPTCISum = 0.0F;
    }

    ME11_PI_Controller1(!rtb_LogicalOperator1_f, ACCtl_tDrSetBasicPTC,
                        &ME11_ARID_DEF.PI_Cor_p, &ME11_ARID_DEF.Delay_DSTATE_b4);
    ME11_P_NEG_p(!rtb_Compare_dsx, rtb_Delay1_ie, cal_DrPtcDesValPID_pWinNeg,
                 cal_DrPtcDesValPIDKpNeg, cal_DrPtcDesValPIDKp, (float32 *)
                 &ACCtl_tDrPTCPCor);
    ME11_P_POS_l(rtb_Compare_dsx, rtb_Delay1_ie, cal_DrPtcDesValPID_pWinPos,
                 cal_DrPtcDesValPIDKpPos, cal_DrPtcDesValPIDKp, (float32 *)
                 &ACCtl_tDrPTCPCor);
    ME11_PI_Controller(rtb_LogicalOperator1_f, rtb_Compare_dsx,
                       ACCtl_tDrSetBasicPTC, ACCtl_tDrPTCPCor, ACCtl_tDrPTCISum,
                       cal_DrPtcDesValPIDUL, cal_DrPtcDesValPIDLL,
                       &ME11_ARID_DEF.PI_Cor_p, &ME11_ARID_DEF.Delay_DSTATE_b4);
  }

  ACPTCPsDesFanCor = look1_iu8lftf_binlca(ME11_ARID_DEF.Delay_DSTATE_hr, (const
    uint8 *)&cal_ACPTCPsDesFanCor_1X[0], (const float32 *)
    &cal_ACPTCPsDesFanCor_CUR[0], 3U);
  ACPTCPsDesEnvCor = look2_iflf_binlca(ACSen_sEnvTempCor,
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpd_kph, (const float32 *)&cal_ACPTCPsDesEnvCor_2X[0], (const
    float32 *)&cal_ACPTCPsDesEnvCor_2Y[0], (const float32 *)
    &cal_ACPTCPsDesEnvCor_MAP[0], ME11_ConstP.pooled37, 6U);
  ACPTCPsDesCabinCor = look1_iflf_binlca(GlbDa_tCabinInvent, (const float32 *)
    &cal_ACPTCPsDesCabinCor_1X[0], (const float32 *)&cal_ACPTCPsDesCabinCor_CUR
    [0], 7U);
  switch (rtb_Delay_n2) {
   case BlowerModes_FaceMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_ACPTCPsDesBacAC_1X[0], (const float32 *)&cal_ACPTCPsDesBacAC_CUR[0],
      11U);
    break;

   case BlowerModes_FaceHeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_ACPTCPsDesBacBi_1X[0], (const float32 *)&cal_ACPTCPsDesBacBi_CUR[0],
      11U);
    break;

   case BlowerModes_HeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_ACPTCPsDesBacFoot_1X[0], (const float32 *)&cal_ACPTCPsDesBacFoot_CUR
      [0], 11U);
    break;

   case BlowerModes_HeaterDeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_ACPTCPsDesBacFootDe_1X[0], (const float32 *)
      &cal_ACPTCPsDesBacFootDe_CUR[0], 11U);
    break;

   case BlowerModes_DeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_ACPTCPsDesBacDefog_1X[0], (const float32 *)
      &cal_ACPTCPsDesBacDefog_CUR[0], 11U);
    break;

   default:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_ACPTCPsDesBacBi_1X[0], (const float32 *)&cal_ACPTCPsDesBacBi_CUR[0],
      11U);
    break;
  }

  if (ACSen_eAirInletPer < cal_ACRecirRatioLmt) {
    rtb_MultiportSwitch2_e = ACPTCPsDesEnvCor;
  } else {
    rtb_MultiportSwitch2_e = ACPTCPsDesCabinCor;
  }

  ACCtl_tPsSetBasicPTC = (ACPTCPsDesFanCor + rtb_MultiportSwitch2_e) +
    rtb_DataTypeConversion23;
  if (ACCtl_tPsSetBasicPTC > 80.0F) {
    ACCtl_tPsSetBasicPTC = 80.0F;
  } else if (ACCtl_tPsSetBasicPTC < -40.0F) {
    ACCtl_tPsSetBasicPTC = -40.0F;
  }

  if (rtb_RelationalOperator_kh) {
    ACCtl_tRightDuct = cal_PsDuctSensorFailDeflt;
  } else {
    switch (rtb_Delay_n2) {
     case BlowerModes_FaceMode:
      ACCtl_tRightDuct = ACSen_sFaceDuctTempFilter;
      break;

     case BlowerModes_FaceHeaterMode:
      ACCtl_tRightDuct = ACSen_sFaceDuctTempFilter * cal_PsDuctFaceFloorFaFactor
        + ACSen_sFootDuctTempFilter * cal_PsDuctFaceFloorFoFactor;
      break;

     case BlowerModes_HeaterMode:
      ACCtl_tRightDuct = ACSen_sFootDuctTempFilter;
      break;

     case BlowerModes_HeaterDeforstMode:
      ACCtl_tRightDuct = ACSen_sFootDuctTempFilter;
      break;

     case BlowerModes_DeforstMode:
      ACCtl_tRightDuct = 0.0F;
      break;

     default:
      ACCtl_tRightDuct = 0.0F;
      break;
    }
  }

  rtb_LogicalOperator5 = (rtb_OR2_a && rtb_Compare_ny);
  if (cal_FixPIDSecletFlag) {
    rtb_Delay1_ie = ACCtl_tPsDVT - ACCtl_tRightDuct;
    ME11_deadzone_h(rtb_Delay1_ie, 0.5, &rtb_flag_n);
    rtb_RelationalOperator_kh = (ACCtl_tPsDVT >= ACCtl_tRightDuct);
    if (rtb_flag_n) {
      rtb_Delay1_ie = 0.0F;
    } else if (!rtb_RelationalOperator_kh) {
      rtb_Delay1_ie = ACCtl_tRightDuct - ACCtl_tPsDVT;
    }

    if (rtb_RelationalOperator_kh) {
      rtb_Add = cal_PsPtcDesValPIDIntegDeadBand4InHeat;
    } else {
      rtb_Add = cal_PsPtcDesValPIDIntegDeadBand4OutHeat;
    }

    ME11_P_NEG(!rtb_RelationalOperator_kh, rtb_Delay1_ie, rtb_Add,
               cal_PsPtcDesValPIDKiNeg, cal_PsPtcDesValPIDKi, (float32 *)
               &ACCtl_tPsPTCICor);
    ME11_P_POS(rtb_RelationalOperator_kh, rtb_Delay1_ie, rtb_Add,
               cal_PsPtcDesValPIDKiPos, cal_PsPtcDesValPIDKi, (float32 *)
               &ACCtl_tPsPTCICor);
    if (rtb_LogicalOperator5) {
      switch (ME11_ARID_DEF.Delay_DSTATE_ou) {
       case 0:
        if (rtb_RelationalOperator_kh) {
          ACCtl_tPsPTCISum = ACCtl_tPsPTCISum + ACCtl_tPsPTCICor;
        } else {
          ACCtl_tPsPTCISum = ACCtl_tPsPTCISum - ACCtl_tPsPTCICor;
        }
        break;

       case 1:
        if (!rtb_RelationalOperator_kh) {
          ACCtl_tPsPTCISum = ACCtl_tPsPTCISum - ACCtl_tPsPTCICor;
        }
        break;

       case 2:
        if (rtb_RelationalOperator_kh) {
          ACCtl_tPsPTCISum = ACCtl_tPsPTCISum + ACCtl_tPsPTCICor;
        }
        break;

       case 3:
        break;
      }

      if ((ACCtl_tPsPTCISum - 8000.0F) + 8000.0F > cal_PsPtcDesValPID_IsumMax) {
        ACCtl_tPsPTCISum = cal_PsPtcDesValPID_IsumMax;
      } else if ((ACCtl_tPsPTCISum - 8000.0F) + 8000.0F <
                 cal_PsPtcDesValPID_IsumMin) {
        ACCtl_tPsPTCISum = cal_PsPtcDesValPID_IsumMin;
      } else {
        ACCtl_tPsPTCISum = (ACCtl_tPsPTCISum - 8000.0F) + 8000.0F;
      }
    } else {
      ACCtl_tPsPTCISum = 0.0F;
    }

    ME11_PI_Controller1(!rtb_LogicalOperator5, ACCtl_tPsSetBasicPTC,
                        &ME11_ARID_DEF.PI_Cor, &ME11_ARID_DEF.Delay_DSTATE_ou);
    ME11_P_NEG_p(!rtb_RelationalOperator_kh, rtb_Delay1_ie,
                 cal_PsPtcDesValPID_pWinNeg, cal_PsPtcDesValPIDKpNeg,
                 cal_PsPtcDesValPIDKp, (float32 *)&ACCtl_tPsPTCPCor);
    ME11_P_POS_l(rtb_RelationalOperator_kh, rtb_Delay1_ie,
                 cal_PsPtcDesValPID_pWinPos, cal_PsPtcDesValPIDKpPos,
                 cal_PsPtcDesValPIDKp, (float32 *)&ACCtl_tPsPTCPCor);
    ME11_PI_Controller(rtb_LogicalOperator5, rtb_RelationalOperator_kh,
                       ACCtl_tPsSetBasicPTC, ACCtl_tPsPTCPCor, ACCtl_tPsPTCISum,
                       cal_PsPtcDesValPIDUL, cal_PsPtcDesValPIDLL,
                       &ME11_ARID_DEF.PI_Cor, &ME11_ARID_DEF.Delay_DSTATE_ou);
  }

  if (ACCtl_stACPTCHeated) {
    rtb_Delay1_ie =
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C;
    if (rtb_Delay1_ie > 0.0F) {
      rtb_Delay1_ie = 0.0F;
    }
  } else if (rtb_DataTypeConversion_f == ACEconMode_Economy) {
    rtb_Delay1_ie = ME11_ARID_DEF.PI_Cor_p;
  } else if (ME11_ARID_DEF.PI_Cor >= ME11_ARID_DEF.PI_Cor_p) {
    rtb_Delay1_ie = ME11_ARID_DEF.PI_Cor;
  } else {
    rtb_Delay1_ie = ME11_ARID_DEF.PI_Cor_p;
  }

  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_gm != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_b = rtb_Delay1_ie;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_b = (1.0F - cal_SetPtcDesCoff) *
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_b + rtb_Delay1_ie * cal_SetPtcDesCoff;
  if (cal_CabinSetPTCSwitch) {
    ACCtl_tSetPointPTC = ((((rtb_Delay1_ie + ME11_ARID_DEF.Delay1_DSTATE_f) +
      ME11_ARID_DEF.Delay_DSTATE_k[0]) + ME11_ARID_DEF.Delay2_DSTATE[0]) +
                          ME11_ARID_DEF.Delay3_DSTATE[0]) / 5.0F;
  } else {
    ACCtl_tSetPointPTC = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_b;
  }

  if (ACCtl_tSetPointPTC > ACCCtl_sSetPtcDesTempMax) {
    ACCtl_tSetPointPTC = ACCCtl_sSetPtcDesTempMax;
  } else if (ACCtl_tSetPointPTC < cal_SetPtcDesTempMin) {
    ACCtl_tSetPointPTC = cal_SetPtcDesTempMin;
  }

  ME11_ARID_DEF.Relay_Mode_d = ((ACSen_sEnvTempCor >= cal_ACCMOpenEnvTemp) ||
    ((ACSen_sEnvTempCor > cal_ACCMClsEnvTemp) && ME11_ARID_DEF.Relay_Mode_d));
  if (cal_PTCReqTempDataEnb) {
    ACTCtl_sPTCRequestTemp = cal_PTCReqTempData;
  } else {
    if (ME11_ARID_DEF.OutportBufferForHMICtl_bPTCOnReq &&
        (ME11_ARID_DEF.DataTypeConversion1 >= 2)) {
      if (SOMCtl_sBatTrgTemp >= ACCtl_tSetPointPTC) {
        rtb_Delay_ci = SOMCtl_sBatTrgTemp;
      } else {
        rtb_Delay_ci = ACCtl_tSetPointPTC;
      }
    } else {
      switch (rtb_Switch2_ht) {
       case 5:
        rtb_Delay_ci = SOMCtl_sBatTrgTemp;
        break;

       case 6:
        if (ME11_ARID_DEF.Relay_Mode_d) {
          rtb_Delay_ci = SOMCtl_sBatTrgTemp;
        } else if (SOMCtl_sBatTrgTemp >= ACCtl_tSetPointPTC) {
          rtb_Delay_ci = SOMCtl_sBatTrgTemp;
        } else {
          rtb_Delay_ci = ACCtl_tSetPointPTC;
        }
        break;

       case 4:
       case 13:
        rtb_Delay_ci = ACCtl_tSetPointPTC;
        break;

       case 10:
        break;

       case 8:
        if ((ME11_ARID_DEF.DataTypeConversion1 == 4) &&
            (rtb_DataTypeConversion1_l == 6)) {
          rtb_Delay_ci = SOMCtl_sBatTrgTemp;
        } else {
          rtb_Delay_ci = ACCtl_tSetPointPTC;
        }
        break;

       default:
        rtb_Delay_ci = -40.0F;
        break;
      }
    }

    if (rtb_Delay_ci > cal_PTCMaxTemp) {
      ACTCtl_sPTCRequestTemp = cal_PTCMaxTemp;
    } else if (rtb_Delay_ci < cal_PTCMinTemp) {
      ACTCtl_sPTCRequestTemp = cal_PTCMinTemp;
    } else {
      ACTCtl_sPTCRequestTemp = rtb_Delay_ci;
    }
  }

  if (rtb_Compare_oc) {
    ACTCtl_sBatHeatInletTrgT = cal_ACBatHeatTrgTemp;
  } else if (ME11_ARID_DEF.DataTypeConversion1 == 4) {
    ACTCtl_sBatHeatInletTrgT = cal_DCBatHeatTrgTemp;
  } else if (ME11_ARID_DEF.DataTypeConversion1 == 5) {
    ACTCtl_sBatHeatInletTrgT = cal_NmlBatHeatTrgTemp;
  } else {
    ACTCtl_sBatHeatInletTrgT = ACTCtl_sPTCRequestTemp;
  }

  if ((BMS_HVBatCellTempMin >= SOMCtl_sBatHeatT1) && (BMS_HVBatCellTempMin <=
       SOMCtl_sBatHeatT2)) {
    rtb_Delay_ci = ACTCtl_sBatHeatInletTrgT - BMS_InletCooltActlTemp;
    if (rtb_Delay_ci > ME11_ARID_DEF.Delay_DSTATE_i1) {
      ACTCtl_bBatTempDiff = 1U;
    } else if (ME11_ARID_DEF.Delay_DSTATE_i1 > rtb_Delay_ci) {
      ACTCtl_bBatTempDiff = 2U;
    }

    if (cal_LessThanT1CalSwt) {
      switch (ACTCtl_bBatTempDiff) {
       case 1:
        ME11_ARID_DEF.Merge = cal_BetwT1AndT2DownMCV_CUR[plook_u32f_binckan
          (rtb_Delay_ci, (const float32 *)&cal_BetwT1AndT2DownMCV_1X[0], 5U)];
        break;

       case 2:
        ME11_ARID_DEF.Merge = cal_BetwT1AndT2UpMCV_CUR[plook_u32f_binckan
          (rtb_Delay_ci, (const float32 *)&cal_BetwT1AndT2UpMCV_1X[0], 5U)];
        break;

       default:
        ME11_ARID_DEF.Merge = cal_BetwT1AndT2StbyMCV_CUR[plook_u32f_binckan
          (rtb_Delay_ci, (const float32 *)&cal_BetwT1AndT2StbyMCV_1X[0], 5U)];
        break;
      }
    } else {
      ME11_ARID_DEF.Merge = 0U;
    }

    ME11_ARID_DEF.Delay_DSTATE_i1 = rtb_Delay_ci;
  }

  if (BMS_HVBatCellTempMin <= SOMCtl_sBatHeatT1) {
    if (BMS_InletCooltActlTemp > ME11_ARID_DEF.Delay_DSTATE_kb) {
      ACTCtl_eLessThanT1Sts = 2U;
    } else if (ME11_ARID_DEF.Delay_DSTATE_kb > BMS_InletCooltActlTemp) {
      ACTCtl_eLessThanT1Sts = 1U;
    }

    if (cal_LessThanT1CalSwt) {
      switch (ACTCtl_eLessThanT1Sts) {
       case 1:
        ME11_ARID_DEF.Merge = cal_LTT1DownMCV_CUR[plook_u32f_binckan
          (BMS_InletCooltActlTemp, (const float32 *)&cal_LTT1DownMCV_1X[0], 4U)];
        break;

       case 2:
        ME11_ARID_DEF.Merge = cal_LTT1UpMCV_CUR[plook_u32f_binckan
          (BMS_InletCooltActlTemp, (const float32 *)&cal_LTT1UpMCV_1X[0], 4U)];
        break;

       default:
        ME11_ARID_DEF.Merge = cal_LTT1StbyMCV_CUR[plook_u32f_binckan
          (BMS_InletCooltActlTemp, (const float32 *)&cal_LTT1StbyMCV_1X[0], 5U)];
        break;
      }
    } else {
      ME11_ARID_DEF.Merge = 0U;
    }

    ME11_ARID_DEF.Delay_DSTATE_kb = BMS_InletCooltActlTemp;
  }

  if (ACCtl_bExhFlg) {
    rtb_Compare_i1 = cal_C3WVExhPosVal;
  } else if (rtb_Switch2_ht == 12) {
    if (rtb_Relay_f > 0) {
      rtb_Compare_i1 = 0U;
    } else {
      rtb_Compare_i1 = 20U;
    }
  } else if ((rtb_Switch2_ht == 10) && rtb_AND1_c) {
    rtb_Compare_i1 = 20U;
  } else if (rtb_Switch2_ht == 5) {
    rtb_Compare_i1 = 20U;
  } else if (rtb_Switch2_ht == 6) {
    rtb_Compare_i1 = ME11_ARID_DEF.Merge;
  } else {
    rtb_Compare_i1 = 0U;
  }

  rtb_RelationalOperator_pl = ((uint16)(MCV_PosRec - rtb_Compare_i1) >=
    cal_MCVPosDiffMaxVal);
  ME11_Delay1(ME11_ARID_DEF.DataTypeConversion1, &ME11_ARID_DEF.C_o,
              &ME11_ARID_DEF.ARID_DEF_Delay1_o);
  if (cal_AcPMPSpdSetDataEnb) {
    ACTCtl_eAcPMPSpdPerc = cal_AcPMPSpdSetData;
  } else if ((!rtb_RelationalOperator_pl) || ME11_ARID_DEF.C_o) {
    if (ACCtl_bExhFlg) {
      ACTCtl_eAcPMPSpdPerc = 50U;
    } else {
      for (b_previousEvent = 0; b_previousEvent < 5; b_previousEvent++) {
        rtb_Compare_btd[b_previousEvent] = (rtb_Switch2_ht ==
          ME11_ConstP.pooled85[b_previousEvent]);
      }

      if (rtb_AND1_c) {
        rtb_Add_ge3 = 100U;
      } else {
        rtb_Add_ge3 = 10U;
      }

      if (ME11_ARID_DEF.Delay_DSTATE_po || (rtb_Compare_btd[0] ||
           rtb_Compare_btd[1] || rtb_Compare_btd[2] || rtb_Compare_btd[3] ||
           rtb_Compare_btd[4])) {
        ACTCtl_eAcPMPSpdPerc = cal_PTCRunAcPMPFFSpd;
      } else {
        ACTCtl_eAcPMPSpdPerc = 10U;
      }

      if (ACTCtl_eACPumpRefSpd >= ME11_ARID_DEF.AcSpd) {
        rtb_SOMCtl_WaterMode = ACTCtl_eACPumpRefSpd;
      } else {
        rtb_SOMCtl_WaterMode = ME11_ARID_DEF.AcSpd;
      }

      if (rtb_SOMCtl_WaterMode >= rtb_Add_ge3) {
        rtb_Add_ge3 = rtb_SOMCtl_WaterMode;
      }

      if (rtb_Add_ge3 >= ACTCtl_eAcPMPSpdPerc) {
        ACTCtl_eAcPMPSpdPerc = rtb_Add_ge3;
      }
    }
  } else {
    ACTCtl_eAcPMPSpdPerc = 10U;
  }

  if (ACTCtl_eAcPMPSpdPerc > 100) {
    rtb_Switch2_gua = 100U;
  } else if (ACTCtl_eAcPMPSpdPerc < 10) {
    rtb_Switch2_gua = 10U;
  } else {
    rtb_Switch2_gua = ACTCtl_eAcPMPSpdPerc;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_ja < 63U) {
    ME11_ARID_DEF.temporalCounter_i1_ja++;
  }

  if (ME11_ARID_DEF.is_active_c94_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c94_ME11 = 1U;
    ME11_ARID_DEF.is_c94_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a = false;
  } else {
    switch (ME11_ARID_DEF.is_c94_ME11) {
     case ME11_IN_Default_k:
      ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a = false;
      if ((rtb_Switch2_gua > AcPMP_RealRPM + (float32)cal_ACPMPSpdDiffVal) ||
          (rtb_Switch2_gua < AcPMP_RealRPM - (float32)cal_ACPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c94_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_ja = 0U;
      }
      break;

     case ME11_IN_Fault_b:
      ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a = true;
      if ((rtb_Switch2_gua < AcPMP_RealRPM + (float32)cal_ACPMPSpdDiffVal) &&
          (rtb_Switch2_gua > AcPMP_RealRPM - (float32)cal_ACPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c94_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_ja >= 50U) {
        ME11_ARID_DEF.is_c94_ME11 = ME11_IN_Fault_b;
        ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a = true;
      } else if ((rtb_Switch2_gua < AcPMP_RealRPM + (float32)cal_ACPMPSpdDiffVal)
                 && (rtb_Switch2_gua > AcPMP_RealRPM - (float32)
                     cal_ACPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c94_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a = false;
      }
      break;
    }
  }

  ACTCtl_bAcPMPSpdFlt = ((rtb_Switch2_gua > 12) &&
    ME11_ARID_DEF.ACTCtl_bAcPMPSpdFlt_a);
  rtb_OR2_a = (ACTCtl_bBatPMPSpdFlt || ACTCtl_bAcPMPSpdFlt);
  rtb_Compare_dsx = (ACTCtl_bAcPMPFaultFlg || ACTCtl_bBatPMPFaultFlg);
  if (ME11_ARID_DEF.temporalCounter_i1_a < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_a++;
  }

  if (ME11_ARID_DEF.is_active_c123_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c123_ME11 = 1U;
    ME11_ARID_DEF.is_c123_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC = false;
  } else {
    switch (ME11_ARID_DEF.is_c123_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC = false;
      if (AcPMP_RealRPM >= cal_PTCRunAcPMPFFSpd) {
        ME11_ARID_DEF.is_c123_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_a = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC = true;
      if (AcPMP_RealRPM < cal_PTCRunAcPMPFFSpd) {
        ME11_ARID_DEF.is_c123_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_a >= look1_iflf_binlca
          (ACSen_sEnvTempCor, (const float32 *)&cal_PTCRunAcPMPFFTime_1X[0], (
            const float32 *)&cal_PTCRunAcPMPFFTime_CUR[0], 5U) * 10.0F) {
        ME11_ARID_DEF.is_c123_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC = true;
      }
      break;
    }
  }

  rtb_Compare_ny = ((!rtb_OR2_a) && (!rtb_Compare_dsx) && ACTCtl_bHVCHFaultFlg &&
                    ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC);
  rtb_ACTCtl_bEXVDiagFlg_0 = (ACTCtl_bAEXVFaultFlg || ACTCtl_bBEXVFaultFlg ||
    ACTCtl_bHPEXVFaultFlg);
  MotPMP_RealRPM = 0.400390625F * (float32)
    Rte_IRead_Task_100ms_MotPMP_RealRPM_MotPMP_RealRPM();
  if (ME11_ARID_DEF.temporalCounter_i1_fp < 63U) {
    ME11_ARID_DEF.temporalCounter_i1_fp++;
  }

  if (ME11_ARID_DEF.is_active_c127_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c127_ME11 = 1U;
    ME11_ARID_DEF.is_c127_ME11 = ME11_IN_Default_k;
    ACTCtl_bMotPMPSpdFlt = false;
  } else {
    switch (ME11_ARID_DEF.is_c127_ME11) {
     case ME11_IN_Default_k:
      ACTCtl_bMotPMPSpdFlt = false;
      if (rtb_Compare_bxp > MotPMP_RealRPM + (float32)cal_MotPMPSpdDiffVal) {
        ME11_ARID_DEF.is_c127_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_fp = 0U;
      }
      break;

     case ME11_IN_Fault_b:
      ACTCtl_bMotPMPSpdFlt = true;
      if ((rtb_Compare_bxp < MotPMP_RealRPM + (float32)cal_MotPMPSpdDiffVal) &&
          (rtb_Compare_bxp > MotPMP_RealRPM - (float32)cal_MotPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c127_ME11 = ME11_IN_Default_k;
        ACTCtl_bMotPMPSpdFlt = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_fp >= 50U) {
        ME11_ARID_DEF.is_c127_ME11 = ME11_IN_Fault_b;
        ACTCtl_bMotPMPSpdFlt = true;
      } else if ((rtb_Compare_bxp < MotPMP_RealRPM + (float32)
                  cal_MotPMPSpdDiffVal) && (rtb_Compare_bxp > MotPMP_RealRPM -
                  (float32)cal_MotPMPSpdDiffVal)) {
        ME11_ARID_DEF.is_c127_ME11 = ME11_IN_Default_k;
        ACTCtl_bMotPMPSpdFlt = false;
      }
      break;
    }
  }

  rtb_ACTCtl_bPMPDiagFlg = (ACTCtl_bAcPMPSpdFlt || ACTCtl_bBatPMPSpdFlt ||
    ACTCtl_bMotPMPSpdFlt || (ACTCtl_bAcPMPFaultFlg || ACTCtl_bBatPMPFaultFlg ||
    ACTCtl_bMotPMPFaultFlg));
  MCV_ErrResp = Rte_IRead_Task_100ms_C3WV_ErrResp_C3WV_ErrResp();
  rtb_Compare_ip = MCV_ErrResp;
  MCV_VoltSts = Rte_IRead_Task_100ms_C3WV_VoltSts_C3WV_VoltSts();
  rtb_Compare_bdq = (MCV_VoltSts > 0);
  MCV_TempSts = Rte_IRead_Task_100ms_C3WV_TempSts_C3WV_TempSts();
  rtb_Compare_cls = (MCV_TempSts > 1);
  MCV_FltSts = Rte_IRead_Task_100ms_C3WV_FltSts_C3WV_FltSts();
  rtb_Compare_h1 = (MCV_FltSts > 0);
  BCV_ErrResp = Rte_IRead_Task_100ms_ErrRespC5WV_ErrRespC5WV();
  rtb_Compare_l5 = BCV_ErrResp;
  BCV_VoltSts = Rte_IRead_Task_100ms_C5WVVoltSts_C5WVVoltSts();
  rtb_Compare_c = (BCV_VoltSts > 0);
  BCV_TempSts = Rte_IRead_Task_100ms_C5WVTempSts_C5WVTempSts();
  rtb_Compare_jkf = (BCV_TempSts > 1);
  BCV_FltSts = Rte_IRead_Task_100ms_C5WVFltSts_C5WVFltSts();
  rtb_Switch_kl = (BCV_FltSts > 0);
  rtb_Switch_n2 = (MCV_ErrResp || rtb_Compare_bdq || rtb_Compare_cls ||
                   rtb_Compare_h1 || BCV_ErrResp || rtb_Compare_c ||
                   rtb_Compare_jkf || rtb_Switch_kl);
  rtb_Compare_ecv_tmp_tmp = ACSen_eMOTORTSenSts;
  if (cal_EnvFailSwFlg) {
    rtb_RelationalOperator_kh = false;
  } else {
    rtb_RelationalOperator_kh = (ACSen_eEnvSenSts != Normal);
  }

  SENCtl_uACCMHighTempVol = get_ACCMHighTempValtage();
  rtb_Delay_ci = (float32)((sint16)SENCtl_uACCMHighTempVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uACCMHighTempVol, (const uint16 *)
    &cal_ACCMHighTempVolAmend_1X[0], (const sint16 *)
    &cal_ACCMHighTempVolAmend_CUR[0], 1U));
  rtb_Add = cal_ADCVCCVal - rtb_Delay_ci;
  ME11_Judge(rtb_Delay_ci > cal_SensorTempUpFlt, rtb_Delay_ci <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts,
             &ME11_ARID_DEF.ARID_DEF_Judge);
  ACSen_eACCMHTSenSts = ME11_ARID_DEF.SenSts;
  if (rtb_Add > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay_ci / rtb_Add;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  rtb_Add_cy = rtb_DataTypeConversion23 * 3000.0F;
  rtb_Compare_gt_tmp_tmp = ACSen_eACCMHTSenSts;
  SENCtl_uWCCHighTempVol = get_WCCHighTempValtage();
  rtb_Delay_ci = (float32)((sint16)SENCtl_uWCCHighTempVol -
    look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uWCCHighTempVol, (const uint16 *)
    &cal_WCCHighTempVolAmend_1X[0], (const sint16 *)
    &cal_WCCHighTempVolAmend_CUR[0], 1U));
  rtb_Add = cal_ADCVCCVal - rtb_Delay_ci;
  ME11_Judge(rtb_Delay_ci > cal_SensorTempUpFlt, rtb_Delay_ci <
             cal_SensorTempDownFlg, 20, &ME11_ARID_DEF.SenSts_fm,
             &ME11_ARID_DEF.ARID_DEF_Judge_b);
  ACSen_eWCCHTSenSts = ME11_ARID_DEF.SenSts_fm;
  if (rtb_Add > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Delay_ci / rtb_Add;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  rtb_Delay_ci = rtb_DataTypeConversion23 * 20000.0F;
  rtb_Compare_dz_tmp_tmp = ACSen_eWCCHTSenSts;
  rtb_Compare_oik_tmp_tmp = ACSen_eOHXTSenSts;
  rtb_Compare_jvo_tmp_tmp = ACSen_eEVAPTSenSts;
  SENCtl_uChillTempVol = get_ChillTempValtage();
  rtb_Add = (float32)((sint16)SENCtl_uChillTempVol -
                      look1_iu16lu64n48ts16Ds32_binlcas(SENCtl_uChillTempVol, (
    const uint16 *)&cal_ChillTempVolAmend_1X[0], (const sint16 *)
    &cal_ChillTempVolAmend_CUR[0], 1U));
  rtb_DataTypeConversion23 = cal_ADCVCCVal - rtb_Add;
  ME11_Judge(rtb_Add > cal_SensorTempUpFlt, rtb_Add < cal_SensorTempDownFlg, 20,
             &ME11_ARID_DEF.SenSts_o, &ME11_ARID_DEF.ARID_DEF_Judge_m);
  ACSen_eChillerTSenSts = ME11_ARID_DEF.SenSts_o;
  if (rtb_DataTypeConversion23 > 0.0F) {
    rtb_DataTypeConversion23 = rtb_Add / rtb_DataTypeConversion23;
  } else {
    rtb_DataTypeConversion23 = 1.0F;
  }

  rtb_Add = rtb_DataTypeConversion23 * 20000.0F;
  ME11_Judge(rtb_Gain8 > cal_SensorVolUpFlg, rtb_Gain8 < cal_SensorVolDownFlg,
             20, &ME11_ARID_DEF.SenSts_f, &ME11_ARID_DEF.ARID_DEF_Judge_c);
  rtb_Compare_pw = (ME11_ARID_DEF.SenSts_f != 0);
  ME11_Judge(rtb_LowPressLmt > cal_SensorVolUpFlg, rtb_LowPressLmt <
             cal_SensorVolDownFlg, 20, &ME11_ARID_DEF.SenSts_e,
             &ME11_ARID_DEF.ARID_DEF_Judge_pp);
  rtb_Compare_oc = (ME11_ARID_DEF.SenSts_e != 0);
  ME11_Judge(rtb_Switch4_a > cal_SensorVolUpFlg, rtb_Switch4_a <
             cal_SensorVolDownFlg, 20, &ME11_ARID_DEF.SenSts_fr,
             &ME11_ARID_DEF.ARID_DEF_Judge_n);
  ACSen_eSOLARSenSts = ME11_ARID_DEF.SenSts_fr;
  rtb_OR_i4 = (ME11_TMSADCSampleFunc_ARID_DEF.Compare_a ||
               ME11_TMSADCSampleFunc_ARID_DEF.Compare ||
               ME11_TMSADCSampleFunc_ARID_DEF.Compare_n ||
               (rtb_Compare_ecv_tmp_tmp != Normal) || rtb_RelationalOperator_kh ||
               ACTCtl_bCabinFltFlg || rtb_OR_i4 || rtb_Compare_fe4 ||
               (rtb_Compare_gt_tmp_tmp != Normal) || (rtb_Compare_dz_tmp_tmp !=
    Normal) || (rtb_Compare_oik_tmp_tmp != Normal) || (rtb_Compare_jvo_tmp_tmp
    != Normal) || (ACSen_eChillerTSenSts != Normal) || (ACSen_eEVAPSurfTSenSts
    != Normal) || rtb_Compare_pw || rtb_Compare_oc || (ACSen_eSOLARSenSts !=
    Normal));
  ME11_ARID_DEF.GLB_TMSFaultSort[0] = (rtb_Compare_gzu || rtb_Compare_ny ||
    rtb_ACTCtl_bEXVDiagFlg_0 || rtb_ACTCtl_bPMPDiagFlg || rtb_Switch_n2 ||
    rtb_OR_i4);
  ME11_ARID_DEF.GLB_TMSFaultSort[1] = rtb_Compare_gzu;
  ME11_ARID_DEF.GLB_TMSFaultSort[2] = rtb_Compare_ny;
  ME11_ARID_DEF.GLB_TMSFaultSort[3] = rtb_ACTCtl_bEXVDiagFlg_0;
  ME11_ARID_DEF.GLB_TMSFaultSort[4] = rtb_ACTCtl_bPMPDiagFlg;
  ME11_ARID_DEF.GLB_TMSFaultSort[5] = rtb_Switch_n2;
  ME11_ARID_DEF.GLB_TMSFaultSort[6] = false;
  ME11_ARID_DEF.GLB_TMSFaultSort[7] = rtb_OR_i4;
  if (ME11_ARID_DEF.is_active_c165_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c165_ME11 = 1U;
    ME11_ARID_DEF.is_c165_ME11 = ME11_IN_Init_o;
    ME11_ARID_DEF.FltSortVal = 0U;
    ME11_ARID_DEF.FltNum = 0U;
    ME11_ARID_DEF.Cnt_FltSort = 0U;
    ME11_ARID_DEF.Cnt_FltNum = 0U;
  } else if (ME11_ARID_DEF.is_c165_ME11 == ME11_IN_Flt) {
    if (!ME11_ARID_DEF.GLB_TMSFaultSort[0]) {
      ME11_ARID_DEF.is_Flt = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_c165_ME11 = ME11_IN_Init_o;
      ME11_ARID_DEF.FltSortVal = 0U;
      ME11_ARID_DEF.FltNum = 0U;
      ME11_ARID_DEF.Cnt_FltSort = 0U;
      ME11_ARID_DEF.Cnt_FltNum = 0U;
    } else {
      switch (ME11_ARID_DEF.is_Flt) {
       case ME11_IN_COMP:
        if (ME11_ARID_DEF.Cnt_FltNum < 8) {
          b_previousEvent = (ME11_ARID_DEF.Cnt_FltNum + 1) *
            ME11_ARID_DEF.GLB_TMSFaultCOMP[ME11_ARID_DEF.Cnt_FltNum];
          if (b_previousEvent > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.FltNum = (uint8)b_previousEvent;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltNum + 1;
          if (ME11_ARID_DEF.Cnt_FltNum + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltNum = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltNum = 0U;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case ME11_IN_ECV:
        if (ME11_ARID_DEF.Cnt_FltNum < 8) {
          b_previousEvent = (ME11_ARID_DEF.Cnt_FltNum + 1) *
            ME11_ARID_DEF.GLB_TMSFaultECV[ME11_ARID_DEF.Cnt_FltNum];
          if (b_previousEvent > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.FltNum = (uint8)b_previousEvent;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltNum + 1;
          if (ME11_ARID_DEF.Cnt_FltNum + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltNum = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltNum = 0U;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case ME11_IN_EXV:
        if (ME11_ARID_DEF.Cnt_FltNum < 12) {
          b_previousEvent = (ME11_ARID_DEF.Cnt_FltNum + 1) *
            ME11_ARID_DEF.GLB_TMSFaultEXV[ME11_ARID_DEF.Cnt_FltNum];
          if (b_previousEvent > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.FltNum = (uint8)b_previousEvent;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltNum + 1;
          if (ME11_ARID_DEF.Cnt_FltNum + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltNum = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltNum = 0U;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case ME11_IN_PMP:
        if (ME11_ARID_DEF.Cnt_FltNum < 18) {
          b_previousEvent = (ME11_ARID_DEF.Cnt_FltNum + 1) *
            ME11_ARID_DEF.GLB_TMSFaultPMP[ME11_ARID_DEF.Cnt_FltNum];
          if (b_previousEvent > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.FltNum = (uint8)b_previousEvent;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltNum + 1;
          if (ME11_ARID_DEF.Cnt_FltNum + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltNum = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltNum = 0U;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case ME11_IN_PTC:
        if (ME11_ARID_DEF.Cnt_FltNum < 4) {
          b_previousEvent = (ME11_ARID_DEF.Cnt_FltNum + 1) *
            ME11_ARID_DEF.GLB_TMSFaultPTC[ME11_ARID_DEF.Cnt_FltNum];
          if (b_previousEvent > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.FltNum = (uint8)b_previousEvent;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltNum + 1;
          if (ME11_ARID_DEF.Cnt_FltNum + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltNum = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltNum = 0U;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       default:
        if (ME11_ARID_DEF.Cnt_FltNum < 37) {
          b_previousEvent = (ME11_ARID_DEF.Cnt_FltNum + 1) *
            ME11_ARID_DEF.GLB_TMSFaultSEN[ME11_ARID_DEF.Cnt_FltNum];
          if (b_previousEvent > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.FltNum = (uint8)b_previousEvent;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltNum + 1;
          if (ME11_ARID_DEF.Cnt_FltNum + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltNum = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltNum = 0U;
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;
      }
    }
  } else {
    ME11_ARID_DEF.FltSortVal = 0U;
    if (ME11_ARID_DEF.GLB_TMSFaultSort[0]) {
      ME11_ARID_DEF.Cnt_FltSort = 1U;
      ME11_ARID_DEF.is_c165_ME11 = ME11_IN_Flt;
      switch (ME11_ARID_DEF.Cnt_FltSort) {
       case 1:
        if (ME11_ARID_DEF.GLB_TMSFaultSort[1]) {
          ME11_ARID_DEF.is_Flt = ME11_IN_COMP;
        } else {
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case 2:
        if (ME11_ARID_DEF.GLB_TMSFaultSort[2]) {
          ME11_ARID_DEF.is_Flt = ME11_IN_PTC;
        } else {
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case 3:
        if (ME11_ARID_DEF.GLB_TMSFaultSort[3]) {
          ME11_ARID_DEF.is_Flt = ME11_IN_PMP;
        } else {
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case 4:
        if (ME11_ARID_DEF.GLB_TMSFaultSort[4]) {
          ME11_ARID_DEF.is_Flt = ME11_IN_EXV;
        } else {
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case 5:
        if (ME11_ARID_DEF.GLB_TMSFaultSort[5]) {
          ME11_ARID_DEF.is_Flt = ME11_IN_ECV;
        } else {
          b_previousEvent = ME11_ARID_DEF.Cnt_FltSort + 1;
          if (ME11_ARID_DEF.Cnt_FltSort + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Cnt_FltSort = (uint8)b_previousEvent;
        }
        break;

       case 6:
        if (ME11_ARID_DEF.GLB_TMSFaultSort[6]) {
          ME11_ARID_DEF.is_Flt = ME11_IN_SEN;
        } else {
          ME11_ARID_DEF.FltNum = 0U;
          ME11_ARID_DEF.Cnt_FltSort = 1U;
        }
        break;

       default:
        ME11_ARID_DEF.FltNum = 0U;
        ME11_ARID_DEF.Cnt_FltSort = 1U;
        break;
      }
    }
  }

  ACDIA_eFltSortVal = ME11_ARID_DEF.FltSortVal;
  ACDIA_eFltNum = ME11_ARID_DEF.FltNum;
  Buffer_DcmDspData_F268H[0] = (uint8)AC_rSunloadFlt;
  Buffer_DcmDspData_F268H[1] = (uint8)((uint32)AC_rSunloadFlt >> 8);
  rtb_SOMCtl_WaterMode = ME11_ARID_DEF.Delay1_DSTATE_hx;
  rtb_Gain8 = ACCtl_tDrDVT - ACCtl_tLeftDuct;
  rtb_Switch4_a = rtb_Gain8;
  ME11_deadzone_h(rtb_Gain8, 0.5, &rtb_flag_de);
  rtb_OR_i4 = (ACCtl_tDrDVT >= ACCtl_tLeftDuct);
  if (rtb_flag_de) {
    rtb_Switch4_a = 0.0F;
  } else if (!rtb_OR_i4) {
    rtb_Switch4_a = ACCtl_tLeftDuct - ACCtl_tDrDVT;
  }

  ME11_P_NEG(!rtb_OR_i4, rtb_Switch4_a, cal_DcutTPidDeadBand,
             cal_DcutTempPid_KiNeg, cal_DcutTempPid_Ki, &rtb_Merge1);
  ME11_P_POS(rtb_OR_i4, rtb_Switch4_a, cal_DcutTPidDeadBand,
             cal_DcutTempPid_KiPos, cal_DcutTempPid_Ki, &rtb_Merge1);
  if (rtb_LogicalOperator1_f) {
    switch (ME11_ARID_DEF.Delay_DSTATE_o3) {
     case 0:
      if (rtb_OR_i4) {
        ME11_ARID_DEF.Delay_DSTATE_m += rtb_Merge1;
      } else {
        ME11_ARID_DEF.Delay_DSTATE_m -= rtb_Merge1;
      }
      break;

     case 1:
      if (!rtb_OR_i4) {
        ME11_ARID_DEF.Delay_DSTATE_m -= rtb_Merge1;
      }
      break;

     case 2:
      if (rtb_OR_i4) {
        ME11_ARID_DEF.Delay_DSTATE_m += rtb_Merge1;
      }
      break;

     case 3:
      break;
    }

    if ((ME11_ARID_DEF.Delay_DSTATE_m - 8000.0F) + 8000.0F >
        cal_DcutTempPid_IsumMax) {
      ME11_ARID_DEF.Delay_DSTATE_m = cal_DcutTempPid_IsumMax;
    } else if ((ME11_ARID_DEF.Delay_DSTATE_m - 8000.0F) + 8000.0F <
               cal_DcutTempPid_IsumMin) {
      ME11_ARID_DEF.Delay_DSTATE_m = cal_DcutTempPid_IsumMin;
    } else {
      ME11_ARID_DEF.Delay_DSTATE_m = (ME11_ARID_DEF.Delay_DSTATE_m - 8000.0F) +
        8000.0F;
    }
  } else {
    ME11_ARID_DEF.Delay_DSTATE_m = 0.0F;
  }

  ME11_PI_Controller1(!rtb_LogicalOperator1_f, 0.0F, &rtb_Merge1,
                      &rtb_IFreezFlag);
  ME11_P_NEG_p(!rtb_OR_i4, rtb_Switch4_a, cal_DcutTempPid_pWinNeg,
               cal_DcutTempPid_KpNeg, cal_DcutTempPid_Kp, &rtb_Merge);
  ME11_P_POS_l(rtb_OR_i4, rtb_Switch4_a, cal_DcutTempPid_pWinPos,
               cal_DcutTempPid_KpPos, cal_DcutTempPid_Kp, &rtb_Merge);
  ME11_PI_Controller(rtb_LogicalOperator1_f, rtb_OR_i4, 0.0F, rtb_Merge,
                     ME11_ARID_DEF.Delay_DSTATE_m, cal_DcutTempPidUL,
                     cal_DcutTempPidLL, &rtb_Merge1, &rtb_IFreezFlag);
  rtb_Delay1_i = ME11_ARID_DEF.Delay1_DSTATE_e0;
  rtb_Switch4_a = ACCtl_tPsDVT - ACCtl_tRightDuct;
  rtb_Merge = rtb_Switch4_a;
  ME11_deadzone_h(rtb_Switch4_a, 0.5, &rtb_flag_g4);
  rtb_OR_i4 = (ACCtl_tPsDVT >= ACCtl_tRightDuct);
  if (rtb_flag_g4) {
    rtb_Merge = 0.0F;
  } else if (!rtb_OR_i4) {
    rtb_Merge = ACCtl_tRightDuct - ACCtl_tPsDVT;
  }

  ME11_P_NEG(!rtb_OR_i4, rtb_Merge, cal_DcutTPidDeadBand, cal_DcutTempPid_KiNeg,
             cal_DcutTempPid_Ki, &rtb_Merge1_m);
  ME11_P_POS(rtb_OR_i4, rtb_Merge, cal_DcutTPidDeadBand, cal_DcutTempPid_KiPos,
             cal_DcutTempPid_Ki, &rtb_Merge1_m);
  if (rtb_LogicalOperator5) {
    switch (ME11_ARID_DEF.Delay_DSTATE_bf) {
     case 0:
      if (rtb_OR_i4) {
        ME11_ARID_DEF.Delay_DSTATE_mf += rtb_Merge1_m;
      } else {
        ME11_ARID_DEF.Delay_DSTATE_mf -= rtb_Merge1_m;
      }
      break;

     case 1:
      if (!rtb_OR_i4) {
        ME11_ARID_DEF.Delay_DSTATE_mf -= rtb_Merge1_m;
      }
      break;

     case 2:
      if (rtb_OR_i4) {
        ME11_ARID_DEF.Delay_DSTATE_mf += rtb_Merge1_m;
      }
      break;

     case 3:
      break;
    }

    if ((ME11_ARID_DEF.Delay_DSTATE_mf - 8000.0F) + 8000.0F >
        cal_DcutTempPid_IsumMax) {
      ME11_ARID_DEF.Delay_DSTATE_mf = cal_DcutTempPid_IsumMax;
    } else if ((ME11_ARID_DEF.Delay_DSTATE_mf - 8000.0F) + 8000.0F <
               cal_DcutTempPid_IsumMin) {
      ME11_ARID_DEF.Delay_DSTATE_mf = cal_DcutTempPid_IsumMin;
    } else {
      ME11_ARID_DEF.Delay_DSTATE_mf = (ME11_ARID_DEF.Delay_DSTATE_mf - 8000.0F)
        + 8000.0F;
    }
  } else {
    ME11_ARID_DEF.Delay_DSTATE_mf = 0.0F;
  }

  ME11_PI_Controller1(!rtb_LogicalOperator5, 0.0F, &rtb_Merge1_m,
                      &rtb_IFreezFlag_d);
  ME11_P_NEG_p(!rtb_OR_i4, rtb_Merge, cal_DcutTempPid_pWinNeg,
               cal_DcutTempPid_KpNeg, cal_DcutTempPid_Kp, &rtb_Merge_g);
  ME11_P_POS_l(rtb_OR_i4, rtb_Merge, cal_DcutTempPid_pWinPos,
               cal_DcutTempPid_KpPos, cal_DcutTempPid_Kp, &rtb_Merge_g);
  ME11_PI_Controller(rtb_LogicalOperator5, rtb_OR_i4, 0.0F, rtb_Merge_g,
                     ME11_ARID_DEF.Delay_DSTATE_mf, cal_DcutTempPidUL,
                     cal_DcutTempPidLL, &rtb_Merge1_m, &rtb_IFreezFlag_d);
  if (rtb_LogicalOperator_j0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ma = ACSen_sCabinTempFilter;
  } else {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_ma = rtb_Add_ax;
  }

  Eva_CoolingCond1 = ACSen_sEvapTempFilter - cal_TevapLoStepMin;
  Eva_CoolingCond2 = ACSen_sEnvTempCor + cal_ErrAmbTDvtForEvaUL;
  Eva_CloseCond1 = ACSen_sEnvTempCor + cal_ErrAmbTDvtForEvaLL;
  Eva_CooledCond1 = ME11_ARID_DEF.Delay_DSTATE_n + cal_TevapLoStepMin;
  EvapDesTempDrFanCor = look1_iu8lftf_binlca(rtb_Delay_ku, (const uint8 *)
    &cal_EvapDesTempFanCor_1X[0], (const float32 *)&cal_EvapDesTempFanCor_CUR[0],
    3U);
  EvapDesTempDrEnvCor = look2_iflf_binlca(ACSen_sEnvTempCor,
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpd_kph, (const float32 *)&cal_EvapDesTempEnvCor_2X[0], (const
    float32 *)&cal_EvapDesTempEnvCor_2Y[0], (const float32 *)
    &cal_EvapDesTempEnvCor_MAP[0], ME11_ConstP.pooled37, 6U);
  EvapDesTempDrCabinCor = look1_iflf_binlca(GlbDa_tCabinInvent, (const float32 *)
    &cal_EvapDesTempCabinCor_1X[0], (const float32 *)
    &cal_EvapDesTempCabinCor_CUR[0], 5U);
  switch (rtb_Delay_n2) {
   case BlowerModes_FaceMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_EvapBacTempDesAC_1X[0], (const float32 *)&cal_EvapBacTempDesAC_CUR[0],
      5U);
    break;

   case BlowerModes_FaceHeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_EvapBacTempDesACBi_1X[0], (const float32 *)
      &cal_EvapBacTempDesACBi_CUR[0], 5U);
    break;

   case BlowerModes_HeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_EvapBacTempDesFoot_1X[0], (const float32 *)
      &cal_EvapBacTempDesFoot_CUR[0], 5U);
    break;

   case BlowerModes_HeaterDeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_EvapBacTempDesFootDe_1X[0], (const float32 *)
      &cal_EvapBacTempDesFootDe_CUR[0], 5U);
    break;

   case BlowerModes_DeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_EvapBacTempDesDefog_1X[0], (const float32 *)
      &cal_EvapBacTempDesDefog_CUR[0], 5U);
    break;

   default:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
      &cal_EvapBacTempDesACBi_1X[0], (const float32 *)
      &cal_EvapBacTempDesACBi_CUR[0], 5U);
    break;
  }

  if (ACSen_eAirInletPer < cal_ACRecirRatioLmt) {
    rtb_MultiportSwitch2_e = EvapDesTempDrEnvCor;
  } else {
    rtb_MultiportSwitch2_e = EvapDesTempDrCabinCor;
  }

  ACCtl_tDrSetBasicEvap = (EvapDesTempDrFanCor + rtb_MultiportSwitch2_e) +
    rtb_DataTypeConversion23;
  if (ACCtl_tDrSetBasicEvap > cal_DrEvaDesValPIDUL) {
    ACCtl_tDrSetBasicEvap = cal_DrEvaDesValPIDUL;
  } else if (ACCtl_tDrSetBasicEvap < cal_DrEvaDesValPIDLL) {
    ACCtl_tDrSetBasicEvap = cal_DrEvaDesValPIDLL;
  }

  if (cal_FixPIDSecletFlag) {
    ACCtl_tErrDrDVT2Duct = rtb_Gain8;
    ME11_deadzone(ACCtl_tErrDrDVT2Duct, 0.5F, &rtb_flag_a);
    rtb_LogicalOperator_j0 = (ACCtl_tDrDVT >= ACCtl_tLeftDuct);
    if (rtb_flag_a) {
      ACCtl_tErrDrDVT2Duct = 0.0F;
    } else if (!rtb_LogicalOperator_j0) {
      ACCtl_tErrDrDVT2Duct = ACCtl_tLeftDuct - ACCtl_tDrDVT;
    }

    ME11_P_NEG(!rtb_LogicalOperator_j0, ACCtl_tErrDrDVT2Duct,
               cal_DrEvaDesValPIDIntegDeadBandNeg, cal_DrEvaDesValPIDKiNeg,
               cal_DrEvaDesValPIDKi, (float32 *)&ACCtl_tDrEvapICor);
    ME11_P_POS(rtb_LogicalOperator_j0, ACCtl_tErrDrDVT2Duct,
               cal_DrEvaDesValPIDIntegDeadBandPos, cal_DrEvaDesValPIDKiPos,
               cal_DrEvaDesValPIDKi, (float32 *)&ACCtl_tDrEvapICor);
    if (rtb_LogicalOperator1_f) {
      switch (ME11_ARID_DEF.Delay_DSTATE_opd) {
       case 0:
        if (rtb_LogicalOperator_j0) {
          ACCtl_tDrEvapISum = ACCtl_tDrEvapISum + ACCtl_tDrEvapICor;
        } else {
          ACCtl_tDrEvapISum = ACCtl_tDrEvapISum - ACCtl_tDrEvapICor;
        }
        break;

       case 1:
        if (!rtb_LogicalOperator_j0) {
          ACCtl_tDrEvapISum = ACCtl_tDrEvapISum - ACCtl_tDrEvapICor;
        }
        break;

       case 2:
        if (rtb_LogicalOperator_j0) {
          ACCtl_tDrEvapISum = ACCtl_tDrEvapISum + ACCtl_tDrEvapICor;
        }
        break;

       case 3:
        break;
      }

      if ((ACCtl_tDrEvapISum - 8000.0F) + 8000.0F > cal_DrEvaDesValPID_IsumMax)
      {
        ACCtl_tDrEvapISum = cal_DrEvaDesValPID_IsumMax;
      } else if ((ACCtl_tDrEvapISum - 8000.0F) + 8000.0F <
                 cal_DrEvaDesValPID_IsumMin) {
        ACCtl_tDrEvapISum = cal_DrEvaDesValPID_IsumMin;
      } else {
        ACCtl_tDrEvapISum = (ACCtl_tDrEvapISum - 8000.0F) + 8000.0F;
      }
    } else {
      ACCtl_tDrEvapISum = 0.0F;
    }

    ME11_PI_Controller1(!rtb_LogicalOperator1_f, ACCtl_tDrSetBasicEvap, (float32
      *)&ACCtl_tDrEvapDesPI, &ME11_ARID_DEF.Delay_DSTATE_opd);
    ME11_P_NEG_p(!rtb_LogicalOperator_j0, ACCtl_tErrDrDVT2Duct,
                 cal_DrEvaDesValPID_pWinNeg, cal_DrEvaDesValPIDKpNeg,
                 cal_DrEvaDesValPIDKp, (float32 *)&ACCtl_tDrEvapPCor);
    ME11_P_POS_l(rtb_LogicalOperator_j0, ACCtl_tErrDrDVT2Duct,
                 cal_DrEvaDesValPID_pWinPos, cal_DrEvaDesValPIDKpPos,
                 cal_DrEvaDesValPIDKp, (float32 *)&ACCtl_tDrEvapPCor);
    ME11_PI_Controller(rtb_LogicalOperator1_f, rtb_LogicalOperator_j0,
                       ACCtl_tDrSetBasicEvap, ACCtl_tDrEvapPCor,
                       ACCtl_tDrEvapISum, cal_DrEvaDesValPIDUL,
                       cal_DrEvaDesValPIDLL, (float32 *)&ACCtl_tDrEvapDesPI,
                       &ME11_ARID_DEF.Delay_DSTATE_opd);
    AC_DrEvapDesFilter = look1_iflf_binlca(ACCtl_tErrDrDVT2Duct, (const float32 *)
      &cal_DrEvapDesFilterByDvt_1X[0], (const float32 *)
      &cal_DrEvapDesFilterByDvt_CUR[0], 3U);
    if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ar != 0) {
      ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_bl = ACCtl_tDrEvapDesPI;
    }

    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_bl = (1.0F - AC_DrEvapDesFilter) *
      ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_bl + ACCtl_tDrEvapDesPI *
      AC_DrEvapDesFilter;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ar = 0U;
  }

  if (HMICtl_bLeftSetLow) {
    ACCtl_tDrEvapDes = cal_EvaDesLLMin;
  } else {
    ACCtl_tDrEvapDes = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_bl;
  }

  if (ACCtl_tDrEvapDes > cal_EvaDesLLMax) {
    ACCtl_tDrEvapDes = cal_EvaDesLLMax;
  } else {
    rtb_Add_ax = look2_iu8flftf_binlca(rtb_Delay_ku, HMICtl_sLeftSetPoint, (
      const uint8 *)&cal_DrEvaDesValPIDLL_2X[0], (const float32 *)
      &cal_DrEvaDesValPIDLL_2Y[0], (const float32 *)&cal_DrEvaDesValPIDLL_MAP[0],
      ME11_ConstP.pooled35, 4U);
    if (ACCtl_tDrEvapDes < rtb_Add_ax) {
      ACCtl_tDrEvapDes = rtb_Add_ax;
    }
  }

  EvapDesTempPsFanCor = look1_iu8lftf_binlca(rtb_Delay_ku, (const uint8 *)
    &cal_EvapDesTempPsFanCor_1X[0], (const float32 *)
    &cal_EvapDesTempPsFanCor_CUR[0], 3U);
  EvapDesTempPsEnvCor = look2_iflf_binlca(ACSen_sEnvTempCor,
    (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
    ->VIPM_ESCVehSpd_kph, (const float32 *)&cal_EvapDesTempPsEnvCor_2X[0], (
    const float32 *)&cal_EvapDesTempPsEnvCor_2Y[0], (const float32 *)
    &cal_EvapDesTempPsEnvCor_MAP[0], ME11_ConstP.pooled37, 6U);
  EvapDesTempPsCabinCor = look1_iflf_binlca(GlbDa_tCabinInvent, (const float32 *)
    &cal_EvapDesTempPsCabinCor_1X[0], (const float32 *)
    &cal_EvapDesTempPsCabinCor_CUR[0], 5U);
  switch (rtb_Delay_n2) {
   case BlowerModes_FaceMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_EvapBacTempPsDesAC_1X[0], (const float32 *)
      &cal_EvapBacTempPsDesAC_CUR[0], 5U);
    break;

   case BlowerModes_FaceHeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_EvapBacTempPsDesACBi_1X[0], (const float32 *)
      &cal_EvapBacTempPsDesACBi_CUR[0], 5U);
    break;

   case BlowerModes_HeaterMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_EvapBacTempPsDesFoot_1X[0], (const float32 *)
      &cal_EvapBacTempPsDesFoot_CUR[0], 5U);
    break;

   case BlowerModes_HeaterDeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_EvapBacTempPsDesFootDe_1X[0], (const float32 *)
      &cal_EvapBacTempPsDesFootDe_CUR[0], 5U);
    break;

   case BlowerModes_DeforstMode:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_EvapBacTempPsDesDefog_1X[0], (const float32 *)
      &cal_EvapBacTempPsDesDefog_CUR[0], 5U);
    break;

   default:
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
      &cal_EvapBacTempPsDesACBi_1X[0], (const float32 *)
      &cal_EvapBacTempPsDesACBi_CUR[0], 5U);
    break;
  }

  if (ACSen_eAirInletPer < cal_ACRecirRatioLmt) {
    rtb_MultiportSwitch2_e = EvapDesTempPsEnvCor;
  } else {
    rtb_MultiportSwitch2_e = EvapDesTempPsCabinCor;
  }

  ACCtl_tPsSetBasicEvap = (EvapDesTempPsFanCor + rtb_MultiportSwitch2_e) +
    rtb_DataTypeConversion23;
  if (ACCtl_tPsSetBasicEvap > cal_DrEvaDesValPIDUL) {
    ACCtl_tPsSetBasicEvap = cal_DrEvaDesValPIDUL;
  } else if (ACCtl_tPsSetBasicEvap < cal_DrEvaDesValPIDLL) {
    ACCtl_tPsSetBasicEvap = cal_DrEvaDesValPIDLL;
  }

  if (cal_FixPIDSecletFlag) {
    ME11_PI_Controller1(!rtb_LogicalOperator5, ACCtl_tPsSetBasicEvap, (float32 *)
                        &ACCtl_tPsEvapDesPI, &rtb_IFreezFlag_k);
    rtb_LogicalOperator_j0 = (ACCtl_tPsDVT >= ACCtl_tRightDuct);
    ACCtl_tErrPsDVT2Duct = rtb_Switch4_a;
    ME11_deadzone(ACCtl_tErrPsDVT2Duct, 0.5F, &rtb_flag_d);
    if (rtb_flag_d) {
      ACCtl_tErrPsDVT2Duct = 0.0F;
    } else if (!rtb_LogicalOperator_j0) {
      ACCtl_tErrPsDVT2Duct = ACCtl_tRightDuct - ACCtl_tPsDVT;
    }

    ME11_P_NEG_p(!rtb_LogicalOperator_j0, ACCtl_tErrPsDVT2Duct,
                 cal_PsEvaDesValPID_pWinNeg, cal_PsEvaDesValPIDKpNeg,
                 cal_PsEvaDesValPIDKp, (float32 *)&ACCtl_tPsEvapPCor);
    ME11_P_POS_l(rtb_LogicalOperator_j0, ACCtl_tErrPsDVT2Duct,
                 cal_PsEvaDesValPID_pWinPos, cal_PsEvaDesValPIDKpPos,
                 cal_PsEvaDesValPIDKp, (float32 *)&ACCtl_tPsEvapPCor);
    ME11_P_NEG(!rtb_LogicalOperator_j0, ACCtl_tErrPsDVT2Duct,
               cal_PsEvaDesValPIDIntegDeadBandNeg, cal_PsEvaDesValPIDKiNeg,
               cal_PsEvaDesValPIDKi, (float32 *)&ACCtl_tPsEvapICor);
    ME11_P_POS(rtb_LogicalOperator_j0, ACCtl_tErrPsDVT2Duct,
               cal_PsEvaDesValPIDIntegDeadBandPos, cal_PsEvaDesValPIDKiPos,
               cal_PsEvaDesValPIDKi, (float32 *)&ACCtl_tPsEvapICor);
    if (rtb_LogicalOperator5) {
      switch (ME11_ARID_DEF.Delay_DSTATE_fe) {
       case 0:
        if (rtb_LogicalOperator_j0) {
          ACCtl_tPsEvapISum = ACCtl_tPsEvapISum + ACCtl_tPsEvapICor;
        } else {
          ACCtl_tPsEvapISum = ACCtl_tPsEvapISum - ACCtl_tPsEvapICor;
        }
        break;

       case 1:
        if (!rtb_LogicalOperator_j0) {
          ACCtl_tPsEvapISum = ACCtl_tPsEvapISum - ACCtl_tPsEvapICor;
        }
        break;

       case 2:
        if (rtb_LogicalOperator_j0) {
          ACCtl_tPsEvapISum = ACCtl_tPsEvapISum + ACCtl_tPsEvapICor;
        }
        break;

       case 3:
        break;
      }

      if ((ACCtl_tPsEvapISum - 8000.0F) + 8000.0F > cal_PsEvaDesValPID_IsumMax)
      {
        ACCtl_tPsEvapISum = cal_PsEvaDesValPID_IsumMax;
      } else if ((ACCtl_tPsEvapISum - 8000.0F) + 8000.0F <
                 cal_PsEvaDesValPID_IsumMin) {
        ACCtl_tPsEvapISum = cal_PsEvaDesValPID_IsumMin;
      } else {
        ACCtl_tPsEvapISum = (ACCtl_tPsEvapISum - 8000.0F) + 8000.0F;
      }
    } else {
      ACCtl_tPsEvapISum = 0.0F;
    }

    ME11_PI_Controller(rtb_LogicalOperator5, rtb_LogicalOperator_j0,
                       ACCtl_tPsSetBasicEvap, ACCtl_tPsEvapPCor,
                       ACCtl_tPsEvapISum, cal_PsEvaDesValPIDUL,
                       cal_PsEvaDesValPIDLL, (float32 *)&ACCtl_tPsEvapDesPI,
                       &rtb_IFreezFlag_k);
    AC_PsEvapDesFilter = look1_iflf_binlca(ACCtl_tErrPsDVT2Duct, (const float32 *)
      &cal_PsEvapDesFilterByDvt_1X[0], (const float32 *)
      &cal_PsEvapDesFilterByDvt_CUR[0], 3U);
    if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_i != 0) {
      ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_he = ACCtl_tPsEvapDesPI;
    }

    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_he = (1.0F - AC_PsEvapDesFilter) *
      ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_he + ACCtl_tPsEvapDesPI *
      AC_PsEvapDesFilter;
    ME11_ARID_DEF.Delay_DSTATE_fe = rtb_IFreezFlag_k;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_i = 0U;
  }

  if (HMICtl_bLeftSetLow) {
    ACCtl_tPsEvapDes = cal_EvaDesLLMin;
  } else {
    ACCtl_tPsEvapDes = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_he;
  }

  if (ACCtl_tPsEvapDes > cal_EvaDesLLMax) {
    ACCtl_tPsEvapDes = cal_EvaDesLLMax;
  } else {
    rtb_Add_ax = look2_iu8flftf_binlca(rtb_Delay_ku, HMICtl_sLeftSetPoint, (
      const uint8 *)&cal_PsEvaDesValPIDLL_2X[0], (const float32 *)
      &cal_PsEvaDesValPIDLL_2Y[0], (const float32 *)&cal_PsEvaDesValPIDLL_MAP[0],
      ME11_ConstP.pooled35, 4U);
    if (ACCtl_tPsEvapDes < rtb_Add_ax) {
      ACCtl_tPsEvapDes = rtb_Add_ax;
    }
  }

  if (HMICtl_bACDefrost) {
    rtb_Merge_g = look1_iflf_binlca(0.0F, ME11_ConstP.uDLookupTable_bp01Data,
      ME11_ConstP.uDLookupTable_tableData, 4U);
  } else {
    rtb_Merge_g = 80.0F;
  }

  if (ACCtl_tPsDVT <= ACCtl_tDrDVT) {
    rtb_Add_ax = ACCtl_tPsDVT;
  } else {
    rtb_Add_ax = ACCtl_tDrDVT;
  }

  if (ME11_ARID_DEF.is_active_c49_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c49_ME11 = 1U;
    ME11_ARID_DEF.is_c49_ME11 = ME11_IN_Eva_cooling;
    ACCtl_stEvaCooledFlag = false;
  } else {
    switch (ME11_ARID_DEF.is_c49_ME11) {
     case ME11_IN_Eva_Stop:
      ACCtl_stEvaCooledFlag = true;
      if (rtb_Add_ax < Eva_CloseCond1) {
        ME11_ARID_DEF.is_c49_ME11 = ME11_IN_Eva_cooling;
        ACCtl_stEvaCooledFlag = false;
      }
      break;

     case ME11_IN_Eva_Stoping:
      ACCtl_stEvaCooledFlag = false;
      if ((ME11_ARID_DEF.EvapTempLoWaiteTime > cal_TevapLoTime) || (rtb_Add_ax <
           Eva_CloseCond1)) {
        ME11_ARID_DEF.EvapTempLoWaiteTime = 0U;
        ME11_ARID_DEF.is_c49_ME11 = ME11_IN_Eva_cooling;
        ACCtl_stEvaCooledFlag = false;
      } else if (ACSen_sEvapTempFilter < Eva_CooledCond1) {
        ME11_ARID_DEF.EvapTempLoWaiteTime = 0U;
        ME11_ARID_DEF.is_c49_ME11 = ME11_IN_Eva_Stop;
        ACCtl_stEvaCooledFlag = true;
      } else {
        b_previousEvent = ME11_ARID_DEF.EvapTempLoWaiteTime + 1;
        if (ME11_ARID_DEF.EvapTempLoWaiteTime + 1 > 65535) {
          b_previousEvent = 65535;
        }

        ME11_ARID_DEF.EvapTempLoWaiteTime = (uint16)b_previousEvent;
      }
      break;

     default:
      ACCtl_stEvaCooledFlag = false;
      if ((rtb_Add_ax < Eva_CoolingCond1) && (rtb_Add_ax > Eva_CoolingCond2)) {
        ME11_ARID_DEF.is_c49_ME11 = ME11_IN_Eva_Stoping;
        ME11_ARID_DEF.RecordInitialEvapTemp_o = ACSen_sEvapTempFilter;
        ACCtl_stEvaCooledFlag = false;
        ME11_ARID_DEF.EvapTempLoWaiteTime = 0U;
      }
      break;
    }
  }

  GlbDa_Solar = AC_rSolarRight;
  rtb_DataTypeConversion_dt = (sint16)(float32)floor(ACSen_sEvapTempFilter);
  rtb_Add_ax = ACCtl_tDrDVT -
    (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
    ->VIPM_HVCHOutlTemp_C;
  if (rtb_Add_ax > 80.0F) {
    rtb_Add_ax = 80.0F;
  } else if (rtb_Add_ax < -40.0F) {
    rtb_Add_ax = -40.0F;
  }

  rtb_DataTypeConversion1_kh = (sint16)(float32)floor(rtb_Add_ax);
  rtb_DataTypeConversion2 = (sint16)(float32)floor(ACCtl_tDrDVT);
  rtb_LogicalOperator_j0 = (((ME11_ARID_DEF.Switch1_nv & 1U) != 0U) &&
    ((ME11_ARID_DEF.Switch1_nv & 2U) != 0U));
  rtb_DataTypeConversion4 = (sint16)(float32)floor
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHOutlTemp_C);
  rtb_DataTypeConversion3 = (sint16)(float32)floor(ACSen_sEnvTempCor);
  rtb_Gain_az = (uint16)((uint32)cal_tiColdStartTimeMax >> 1);
  if (ME11_ARID_DEF.is_active_c28_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c28_ME11 = 1U;
    ME11_ARID_DEF.is_FanWorkTimeMng = ME11_IN_IGN_OFF;
    ME11_ARID_DEF.BlowerFanRunTime = 0U;
    ME11_ARID_DEF.IGN_ONTime = 0U;
    rtb_Compare_gzu = !HMICtl_bACDefrost;
    if ((rtb_DataTypeConversion4 < cal_CAPStartCoolantMin) && rtb_Compare_gzu &&
        (rtb_DataTypeConversion1_kh > 8) && rtb_LogicalOperator_j0 &&
        (rtb_DataTypeConversion3 < 15)) {
      ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Cold_Air_Protection;
      ACCtl_stStartState = ME11_ColdStart;
      ME11_ARID_DEF.time = 0U;
    } else if (rtb_LogicalOperator_j0 && rtb_Compare_gzu &&
               (rtb_DataTypeConversion2 < rtb_DataTypeConversion_dt) &&
               (rtb_DataTypeConversion3 > 30) && (rtb_DataTypeConversion_dt >
                cal_HAPevap_min) && (AC_tiAfterRun >= cal_HAPparkdly_time) &&
               (ME11_ARID_DEF.IGN_ONTime < cal_HAPtimelim2activtic) &&
               (ME11_ARID_DEF.BlowerFanRunTime < cal_HAPpurge_time)) {
      ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Hot_Air_Protection;
      ACCtl_stStartState = ME11_HotStart;
    } else {
      ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Normal_Op;
      ACCtl_stStartState = ME11_NormalStart;
    }
  } else {
    if (ME11_ARID_DEF.is_FanWorkTimeMng == ME11_IN_IGN_OFF) {
      if (CoAC_stwork == 2) {
        ME11_ARID_DEF.is_FanWorkTimeMng = ME11_IN_IGN_ON;
        ME11_ARID_DEF.IGN_ONTime = 0U;
        ME11_ARID_DEF.is_BlowerFanTime = ME11_IN_BlowerFan_On;
        if (ME11_ARID_DEF.BlowerFanRunTime >= cal_tiColdStartTimeMax) {
          ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_BlowerFanWorkTimeKeep;
          ME11_ARID_DEF.BlowerFanRunTime = cal_tiColdStartTimeMax;
        } else {
          ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_BlowerFanWorkTimeAdd;
          ME11_ARID_DEF.BlowerFanRunTime = 0U;
        }
      }
    } else if (CoAC_stwork != 2) {
      if (ME11_ARID_DEF.is_BlowerFanTime == ME11_IN_BlowerFan_Off) {
        ME11_ARID_DEF.is_BlowerFanTime = ME11_IN_NO_ACTIVE_CHILD_gl;
      } else {
        ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_BlowerFanTime = ME11_IN_NO_ACTIVE_CHILD_gl;
      }

      ME11_ARID_DEF.is_FanWorkTimeMng = ME11_IN_IGN_OFF;
      ME11_ARID_DEF.BlowerFanRunTime = 0U;
      ME11_ARID_DEF.IGN_ONTime = 0U;
    } else {
      if (ME11_ARID_DEF.is_BlowerFanTime == ME11_IN_BlowerFan_Off) {
        if (rtb_Delay_ku > 0) {
          ME11_ARID_DEF.BlowerFanRunTime = 0U;
          ME11_ARID_DEF.is_BlowerFanTime = ME11_IN_BlowerFan_On;
          if (ME11_ARID_DEF.BlowerFanRunTime >= cal_tiColdStartTimeMax) {
            ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_BlowerFanWorkTimeKeep;
            ME11_ARID_DEF.BlowerFanRunTime = cal_tiColdStartTimeMax;
          } else {
            ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_BlowerFanWorkTimeAdd;
            ME11_ARID_DEF.BlowerFanRunTime = 0U;
          }
        }
      } else if (rtb_Delay_ku == 0) {
        ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_BlowerFanTime = ME11_IN_BlowerFan_Off;
      } else if (ME11_ARID_DEF.is_BlowerFan_On == ME11_IN_BlowerFanWorkTimeAdd)
      {
        if (ME11_ARID_DEF.BlowerFanRunTime >= cal_tiColdStartTimeMax) {
          ME11_ARID_DEF.is_BlowerFan_On = ME11_IN_BlowerFanWorkTimeKeep;
          ME11_ARID_DEF.BlowerFanRunTime = cal_tiColdStartTimeMax;
        } else {
          rtb_Divide1_f = ME11_ARID_DEF.BlowerFanRunTime + 1U;
          if (ME11_ARID_DEF.BlowerFanRunTime + 1U > 65535U) {
            rtb_Divide1_f = 65535U;
          }

          ME11_ARID_DEF.BlowerFanRunTime = (uint16)rtb_Divide1_f;
        }
      } else {
      }

      rtb_Divide1_f = ME11_ARID_DEF.IGN_ONTime + 1U;
      if (ME11_ARID_DEF.IGN_ONTime + 1U > 65535U) {
        rtb_Divide1_f = 65535U;
      }

      ME11_ARID_DEF.IGN_ONTime = (uint16)rtb_Divide1_f;
    }

    switch (ME11_ARID_DEF.is_ACStartModeMng) {
     case ME11_IN_Cold_Air_Protection:
      ACCtl_stStartState = ME11_ColdStart;
      if (HMICtl_bACDefrost || (rtb_DataTypeConversion1_kh < 2) ||
          (!rtb_LogicalOperator_j0)) {
        ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Normal_Op;
        ACCtl_stStartState = ME11_NormalStart;
      } else if ((rtb_DataTypeConversion4 > cal_CAPStartCoolantMin + 3) ||
                 (ME11_ARID_DEF.time >= rtb_Gain_az)) {
        ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Normal_LittleCold;
        ACCtl_stStartState = ME11_LittleCold;
        ME11_ARID_DEF.time = 0U;
      } else {
        rtb_Divide1_f = ME11_ARID_DEF.time + 1U;
        if (ME11_ARID_DEF.time + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.time = (uint16)rtb_Divide1_f;
      }
      break;

     case ME11_IN_Hot_Air_Protection:
      ACCtl_stStartState = ME11_HotStart;
      if ((ME11_ARID_DEF.BlowerFanRunTime >= cal_HAPpurge_time) ||
          HMICtl_bACDefrost || (!rtb_LogicalOperator_j0)) {
        ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Normal_Op;
        ACCtl_stStartState = ME11_NormalStart;
      }
      break;

     case ME11_IN_Normal_LittleCold:
      ACCtl_stStartState = ME11_LittleCold;
      if ((rtb_DataTypeConversion4 < cal_CAPStartCoolantMin) &&
          (!HMICtl_bACDefrost) && (rtb_DataTypeConversion1_kh > 8) &&
          rtb_LogicalOperator_j0 && (rtb_DataTypeConversion3 < 15) &&
          (ME11_ARID_DEF.BlowerFanRunTime < cal_tiColdStartTimeMax) &&
          (ME11_ARID_DEF.time >= rtb_Gain_az)) {
        ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Cold_Air_Protection;
        ACCtl_stStartState = ME11_ColdStart;
        ME11_ARID_DEF.time = 0U;
      } else if ((rtb_DataTypeConversion4 > cal_CAPStartCoolantMin + 8) ||
                 HMICtl_bACDefrost || (rtb_DataTypeConversion1_kh < 2) ||
                 (!rtb_LogicalOperator_j0) || (ME11_ARID_DEF.time >= rtb_Gain_az))
      {
        ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Normal_Op;
        ACCtl_stStartState = ME11_NormalStart;
      } else {
        rtb_Divide1_f = ME11_ARID_DEF.time + 1U;
        if (ME11_ARID_DEF.time + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.time = (uint16)rtb_Divide1_f;
      }
      break;

     default:
      ACCtl_stStartState = ME11_NormalStart;
      if (rtb_LogicalOperator_j0 && (!HMICtl_bACDefrost) &&
          (rtb_DataTypeConversion2 < rtb_DataTypeConversion_dt) &&
          (rtb_DataTypeConversion3 > 30) && (rtb_DataTypeConversion_dt >
           cal_HAPevap_min) && (ME11_ARID_DEF.BlowerFanRunTime <
           cal_HAPpurge_time)) {
        ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Hot_Air_Protection;
        ACCtl_stStartState = ME11_HotStart;
      } else {
        rtb_Compare_gzu = !HMICtl_bACDefrost;
        if ((rtb_DataTypeConversion4 < cal_CAPStartCoolantMin) &&
            rtb_Compare_gzu && (rtb_DataTypeConversion1_kh > 8) &&
            rtb_LogicalOperator_j0 && (rtb_DataTypeConversion3 < 15) &&
            (ME11_ARID_DEF.BlowerFanRunTime < cal_tiColdStartTimeMax)) {
          ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Cold_Air_Protection;
          ACCtl_stStartState = ME11_ColdStart;
          ME11_ARID_DEF.time = 0U;
        } else if ((rtb_DataTypeConversion4 < cal_CAPStartCoolantMin + 5) &&
                   rtb_Compare_gzu && (rtb_DataTypeConversion1_kh > 8) &&
                   rtb_LogicalOperator_j0 && (rtb_DataTypeConversion3 < 15) &&
                   (ME11_ARID_DEF.BlowerFanRunTime < cal_tiColdStartTimeMax)) {
          ME11_ARID_DEF.is_ACStartModeMng = ME11_IN_Normal_LittleCold;
          ACCtl_stStartState = ME11_LittleCold;
          ME11_ARID_DEF.time = 0U;
        }
      }
      break;
    }
  }

  ACCtl_sECOEvaDesValLL = look2_iflf_binlca(ACSen_sEnvTempCor,
    HMICtl_sLeftSetPoint, (const float32 *)&cal_ECOEvaDesValLL_2X[0], (const
    float32 *)&cal_ECOEvaDesValLL_2Y[0], (const float32 *)
    &cal_ECOEvaDesValLL_MAP[0], ME11_ConstP.cal_ECOEvaDesValLL_MAP_maxIndex, 6U);
  if ((rtb_DataTypeConversion_f == ACEconMode_Economy) && (!HMICtl_bACDefrost))
  {
    if (ACCtl_tDrEvapDes >= ACCtl_sECOEvaDesValLL) {
      ACCtl_tSetPointEvap = ACCtl_tDrEvapDes;
    } else {
      ACCtl_tSetPointEvap = ACCtl_sECOEvaDesValLL;
    }
  } else {
    if (ACCtl_stEvaCooledFlag) {
      if (ACSen_sEvapTempFilter >= 25.0F) {
        ACCtl_tSetPointEvap = ACSen_sEvapTempFilter;
      } else {
        ACCtl_tSetPointEvap = 25.0F;
      }
    } else if (ACCtl_tDrEvapDes <= ACCtl_tPsEvapDes) {
      ACCtl_tSetPointEvap = ACCtl_tDrEvapDes;
    } else {
      ACCtl_tSetPointEvap = ACCtl_tPsEvapDes;
    }

    if (ACCtl_tSetPointEvap > cal_EvaDesLLMax) {
      ACCtl_tSetPointEvap = cal_EvaDesLLMax;
    } else {
      if (HMICtl_bLeftSetLow || cal_EvaDesLLSelect) {
        rtb_Add_ax = cal_EvaDesLLMin;
      } else {
        if (ACCtl_stStartState == 2) {
          rtb_Merge1_m = cal_CoolStartCompensate;
        } else {
          rtb_Merge1_m = 0.0F;
        }

        rtb_Add_ax = look1_iu16lftf_binlca(GlbDa_Solar, (const uint16 *)
          &cal_EvapDesLoLimBySolarCor_1X[0], (const float32 *)
          &cal_EvapDesLoLimBySolarCor_CUR[0], 1U);
        if (rtb_Add_ax <= rtb_Merge1_m) {
          rtb_Merge1_m = rtb_Add_ax;
        }

        rtb_Add_ax = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
          &cal_EvapDesLoLimByEnv_1X[0], (const float32 *)
          &cal_EvapDesLoLimByEnv_CUR[0], 7U) + rtb_Merge1_m;
        if (rtb_Add_ax > cal_EvaDesLLMax) {
          rtb_Add_ax = cal_EvaDesLLMax;
        } else if (rtb_Add_ax < cal_EvaDesLLMin) {
          rtb_Add_ax = cal_EvaDesLLMin;
        }
      }

      if (ACCtl_tSetPointEvap < rtb_Add_ax) {
        ACCtl_tSetPointEvap = rtb_Add_ax;
      }
    }

    if (HMICtl_bACDefrost) {
      rtb_Merge_g = 0.5F;
    }

    if (rtb_Merge_g <= ACCtl_tSetPointEvap) {
      ACCtl_tSetPointEvap = rtb_Merge_g;
    }
  }

  rtb_Switch_n2 = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                   ->VIPM_HUACUnlckVentSet_enum !=
                   ME11_ARID_DEF.DelayInput1_DSTATE_ez);
  rtb_Compare_gzu = ((Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
                     ->VIPM_HUACUnlckVentSet_enum != 0);
  rtb_LogicalOperator_j0 = (rtb_Switch_n2 && rtb_Compare_gzu);
  if (rtb_LogicalOperator_j0) {
    ME11_ARID_DEF.Delay_DSTATE_b2 =
      (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
      ->VIPM_HUACUnlckVentSet_enum;
  }

  if (ME11_ARID_DEF.is_active_c159_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c159_ME11 = 1U;
    ME11_ARID_DEF.is_c159_ME11 = ME11_IN_init_f;
    ME11_ARID_DEF.data = ME11_ARID_DEF.EERead_UnlockVentSts;
  } else if (ME11_ARID_DEF.is_c159_ME11 == ME11_IN_after) {
    ME11_ARID_DEF.data = ME11_ARID_DEF.Delay_DSTATE_b2;
  } else if (rtb_LogicalOperator_j0) {
    ME11_ARID_DEF.is_c159_ME11 = ME11_IN_after;
    ME11_ARID_DEF.data = ME11_ARID_DEF.Delay_DSTATE_b2;
  }

  if (cal_HMIUnlckVentEnb) {
    HMICtl_eUnlckVentSts = cal_HMIUnlckVentEnbData;
  } else {
    HMICtl_eUnlckVentSts = ME11_ARID_DEF.data;
  }

  rtb_Switch_n2 = ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
                   ->BCM_BodyWarnSts == 0);
  rtb_LogicalOperator_j0 =
    ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
     ->BCM_DoorAjarSta_FL > ME11_ARID_DEF.DelayInput1_DSTATE_j5);
  rtb_OR_i4 = ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
               ->BCM_DoorAjarSta_FR > ME11_ARID_DEF.DelayInput1_DSTATE_mu);
  if (ME11_ARID_DEF.temporalCounter_i1_mj < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_mj++;
  }

  if (ME11_ARID_DEF.is_active_c158_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c158_ME11 = 1U;
    ME11_ARID_DEF.is_c158_ME11 = ME11_IN_Init_i;
    PWRCtl_bUnlockVentTimeFlg = false;
  } else {
    switch (ME11_ARID_DEF.is_c158_ME11) {
     case ME11_IN_Init_i:
      PWRCtl_bUnlockVentTimeFlg = false;
      if ((HMICtl_eUnlckVentSts == 2) && (AC_tiAfterRun >= 120) &&
          (rtb_Switch_n2 && (ME11_ARID_DEF.Delay1_DSTATE_dt == 1)) &&
          (ME11_ARID_DEF.DataTypeConversion1 < 2)) {
        ME11_ARID_DEF.is_c158_ME11 = ME11_IN_On_kf;
        ME11_ARID_DEF.temporalCounter_i1_mj = 0U;
        PWRCtl_bUnlockVentTimeFlg = true;
      }
      break;

     case ME11_IN_Off_l:
      PWRCtl_bUnlockVentTimeFlg = false;
      break;

     default:
      PWRCtl_bUnlockVentTimeFlg = true;
      if ((ME11_ARID_DEF.temporalCounter_i1_mj >= 600U) ||
          (rtb_LogicalOperator_j0 || rtb_OR_i4)) {
        ME11_ARID_DEF.is_c158_ME11 = ME11_IN_Off_l;
        PWRCtl_bUnlockVentTimeFlg = false;
      }
      break;
    }
  }

  if (cal_UnlockVentEnb) {
    PWRCtl_bUnlockVentTimeFlg = cal_UnlockVentEnbData;
  }

  if (PWRCtl_bUnlockVentTimeFlg) {
    rtb_Switch1_e3 = 5U;
  } else {
    rtb_Switch1_e3 = HMICtl_eBlwSts;
  }

  rtb_LogicalOperator_j0 = (ME11_ARID_DEF.Switch1_nv != ACOff);
  if (!rtb_LogicalOperator_j0) {
    ACCtl_BloweFanSpeed = 0U;
    AC_FanLevelAct = 0U;
    AC_FanLeVel = rtb_Switch1_e3;
  }

  ACCtl_stRecTempLowEna = HMICtl_bLeftSetLow;
  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForForceChange) {
    if ((uint16)(ME11_ARID_DEF.Delay2_DSTATE_l + 1U) <= 50000) {
      ME11_ARID_DEF.Delay2_DSTATE_l++;
    } else {
      ME11_ARID_DEF.Delay2_DSTATE_l = 50000U;
    }
  } else {
    ME11_ARID_DEF.Delay2_DSTATE_l = 0U;
  }

  if (ME11_ARID_DEF.Delay1_DSTATE_dt4 == 100) {
    if ((uint16)(ME11_ARID_DEF.Delay1_DSTATE_m + 1U) <= 50000) {
      ME11_ARID_DEF.Delay1_DSTATE_m++;
    } else {
      ME11_ARID_DEF.Delay1_DSTATE_m = 50000U;
    }
  } else {
    ME11_ARID_DEF.Delay1_DSTATE_m = 0U;
  }

  if ((ME11_ARID_DEF.Delay1_DSTATE_m >= cal_tiCO2Recirc2FreshMax) ||
      (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForForceChange)) {
    ACCtl_stRecForceChangeEna = (ME11_ARID_DEF.Delay2_DSTATE_l <=
      cal_tiCO2Fresh2RecircMax);
  } else {
    ACCtl_stRecForceChangeEna = false;
  }

  rtb_OR_i4 = (cal_AQS2OutRecThreVal > 0);
  if (ME11_ARID_DEF.is_active_c27_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c27_ME11 = 1U;
    ME11_ARID_DEF.is_c27_ME11 = ME11_IN_Initi;
    ACCtl_stRecAQSEna = false;
    ME11_ARID_DEF.is_Initi = ME11_IN_ACCtl_tiAQSHi_cntClear;
    ME11_ARID_DEF.ACCtl_tiAQSHi = 0U;
  } else if (ME11_ARID_DEF.is_c27_ME11 == ME11_IN_Initi) {
    ACCtl_stRecAQSEna = false;
    if (ME11_ARID_DEF.ACCtl_tiAQSHi >= cal_tiAQSFresh2RecircDelay) {
      ME11_ARID_DEF.is_Initi = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_c27_ME11 = ME11_IN_Recirc_AQS;
      ACCtl_stRecAQSEna = true;
      ME11_ARID_DEF.ACCtl_tiAQSLo = 0U;
      if (rtb_OR_i4) {
        ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_ACCtl_tiAQSLo_cnt;
        rtb_Divide1_f = ME11_ARID_DEF.ACCtl_tiAQSLo + 1U;
        if (ME11_ARID_DEF.ACCtl_tiAQSLo + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.ACCtl_tiAQSLo = (uint16)rtb_Divide1_f;
      } else {
        ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_ACCtl_tiAQSLo_cntClear;
        ME11_ARID_DEF.ACCtl_tiAQSLo = 0U;
      }
    } else if (ME11_ARID_DEF.is_Initi == ME11_IN_ACCtl_tiAQSHi_cnt) {
      ME11_ARID_DEF.is_Initi = ME11_IN_ACCtl_tiAQSHi_cntClear;
      ME11_ARID_DEF.ACCtl_tiAQSHi = 0U;
    } else {
      ME11_ARID_DEF.is_Initi = ME11_IN_ACCtl_tiAQSHi_cntClear;
      ME11_ARID_DEF.ACCtl_tiAQSHi = 0U;
    }
  } else {
    ACCtl_stRecAQSEna = true;
    if (ME11_ARID_DEF.ACCtl_tiAQSLo >= cal_tiAQSRecirc2FreshDelay) {
      ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_c27_ME11 = ME11_IN_Initi;
      ACCtl_stRecAQSEna = false;
      ME11_ARID_DEF.is_Initi = ME11_IN_ACCtl_tiAQSHi_cntClear;
      ME11_ARID_DEF.ACCtl_tiAQSHi = 0U;
    } else if (ME11_ARID_DEF.is_Recirc_AQS == ME11_IN_ACCtl_tiAQSLo_cnt) {
      if (rtb_OR_i4) {
        ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_ACCtl_tiAQSLo_cnt;
        rtb_Divide1_f = ME11_ARID_DEF.ACCtl_tiAQSLo + 1U;
        if (ME11_ARID_DEF.ACCtl_tiAQSLo + 1U > 65535U) {
          rtb_Divide1_f = 65535U;
        }

        ME11_ARID_DEF.ACCtl_tiAQSLo = (uint16)rtb_Divide1_f;
      } else {
        ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_ACCtl_tiAQSLo_cntClear;
        ME11_ARID_DEF.ACCtl_tiAQSLo = 0U;
      }
    } else if (rtb_OR_i4) {
      ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_ACCtl_tiAQSLo_cnt;
      rtb_Divide1_f = ME11_ARID_DEF.ACCtl_tiAQSLo + 1U;
      if (ME11_ARID_DEF.ACCtl_tiAQSLo + 1U > 65535U) {
        rtb_Divide1_f = 65535U;
      }

      ME11_ARID_DEF.ACCtl_tiAQSLo = (uint16)rtb_Divide1_f;
    } else {
      ME11_ARID_DEF.is_Recirc_AQS = ME11_IN_ACCtl_tiAQSLo_cntClear;
      ME11_ARID_DEF.ACCtl_tiAQSLo = 0U;
    }
  }

  ACCtl_stRecNormalDefogEna = ((ACSen_sEnvTempCor < 30.0F) && (ACSen_sEnvTempCor
    > 5.0F));
  rtb_OR_i4 = (ME11_ARID_DEF.Switch1_nv != ACOff);
  ACCtl_stRecTargetOutTempEna = (((!rtb_OR_i4) ||
    (ME11_ARID_DEF.Delay1_Reset_ZCE == POS_ZCSIG)) &&
    ACCtl_stRecTargetOutTempEna);
  ME11_ARID_DEF.Delay1_Reset_ZCE = rtb_OR_i4;
  if (ACCtl_tDrDVT < cal_REC_DVTRecirc) {
    ACCtl_stRecTargetOutTempEna = true;
  } else {
    ACCtl_stRecTargetOutTempEna = ((ACCtl_tDrDVT <= cal_REC_DVTFresh) &&
      ACCtl_stRecTargetOutTempEna);
  }

  ACCtl_stRecVentEna = (ACCtl_stACPTCHeated || ACCtl_stEvaCooledFlag);
  ACCtl_stRecWinterCondEna = (ACSen_sEnvTempCor <= 5.0F);
  ACCtl_stRecSummerCondEna = (ACSen_sEnvTempCor >= 30.0F);
  rtb_Gain_az = (uint16)((ACCtl_tSetPointPTC -
    (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
    ->VIPM_HVCHOutlTemp_C) * 2.0F + 400.0F);
  rtb_OR_i4 = (ME11_ARID_DEF.Switch1_nv != ACOff);
  ACCtl_stRecPTCDvtEna = (((!rtb_OR_i4) || (ME11_ARID_DEF.Delay1_Reset_ZCE_a ==
    POS_ZCSIG)) && ACCtl_stRecPTCDvtEna);
  ME11_ARID_DEF.Delay1_Reset_ZCE_a = rtb_OR_i4;
  rtb_MultiportSwitch2_e = (float32)rtb_Gain_az * 0.5F - 200.0F;
  if (rtb_MultiportSwitch2_e >= cal_PTCTempRecircOn) {
    ACCtl_stRecPTCDvtEna = true;
  } else {
    ACCtl_stRecPTCDvtEna = ((rtb_MultiportSwitch2_e > cal_PTCTempRecircOff) &&
      ACCtl_stRecPTCDvtEna);
  }

  ACCtl_stRecACHotStartEna = (ACCtl_stStartState == AC_HotStart);
  ACCtl_stRecForceDefogEna = HMICtl_bACDefrost;
  ACCtl_stRecManualEna = (((ME11_ARID_DEF.Switch1_nv & 4U) == 0U) ||
    (ME11_ARID_DEF.Switch1_nv == ACOff));
  if (RMTCtl_bRemtACFlg && (!RMTCtl_bRemtACDefFlg)) {
    if ((uint16)(ME11_ARID_DEF.Delay_DSTATE_ke + 1U) <= 200) {
      ME11_ARID_DEF.Delay_DSTATE_ke++;
    } else {
      ME11_ARID_DEF.Delay_DSTATE_ke = 200U;
    }
  } else {
    ME11_ARID_DEF.Delay_DSTATE_ke = 0U;
  }

  ACCtl_stRecRemoteACEna = (ME11_ARID_DEF.Delay_DSTATE_ke >= 100);
  rtb_Switch_n2 =
    ((Rte_IRead_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
      ())->VIPM_BMSDCSActOprtMode_enum == 5);
  ACCtl_stRecQkChargeCoolingEna = (rtb_Switch_n2 &&
    (ME11_ARID_DEF.Delay_DSTATE_lv == 1));
  if (ACSen_sMotTempFilter > cal_AirInletRecInPCUTemp) {
    ACCtl_stRecPCUTempEna = true;
  } else {
    ACCtl_stRecPCUTempEna = ((ACSen_sMotTempFilter >= cal_AirInletRecOutPCUTemp)
      && ACCtl_stRecPCUTempEna);
  }

  if (ACCtl_stRecTempLowEna) {
    rtb_Add6_d = cal_ACCtlRecLevelForTempLow;
  } else {
    rtb_Add6_d = 0U;
  }

  if (ACCtl_stRecForceChangeEna) {
    rtb_Add_ge3 = cal_ACCtlRecLevelForForceChange;
  } else {
    rtb_Add_ge3 = 0U;
  }

  if (ACCtl_stRecAQSEna) {
    rtb_Add7_i = cal_ACCtlRecLevelForAQS;
  } else {
    rtb_Add7_i = 0U;
  }

  if (ACCtl_stRecNormalDefogEna) {
    rtb_Add2_j5 = cal_ACCtlRecLevelForNormalDefog;
  } else {
    rtb_Add2_j5 = 0U;
  }

  if (ACCtl_stRecTargetOutTempEna) {
    rtb_Add3_do = cal_ACCtlRecLevelForTargetOutTemp;
  } else {
    rtb_Add3_do = 0U;
  }

  if (ACCtl_stRecVentEna) {
    rtb_Add5_d = cal_ACCtlRecLevelForVent;
  } else {
    rtb_Add5_d = 0U;
  }

  if (ACCtl_stRecWinterCondEna) {
    rtb_Add4_ox = cal_ACCtlRecLevelForWinter;
  } else {
    rtb_Add4_ox = 0U;
  }

  if (ACCtl_stRecSummerCondEna) {
    rtb_DataTypeConversion19 = cal_ACCtlRecLevelForSummer;
  } else {
    rtb_DataTypeConversion19 = 0U;
  }

  if (ACCtl_stRecPTCDvtEna) {
    rtb_DataTypeConversion2_a = cal_ACCtlRecLevelForPTCDvt;
  } else {
    rtb_DataTypeConversion2_a = 0U;
  }

  if (ACCtl_stRecACHotStartEna) {
    u1 = cal_ACCtlRecLevelForACHotStart;
  } else {
    u1 = 0U;
  }

  if (ACCtl_stRecForceDefogEna) {
    u1_0 = cal_ACCtlRecLevelForForceDefog;
  } else {
    u1_0 = 0U;
  }

  if (ACCtl_stRecManualEna) {
    u1_1 = cal_ACCtlRecLevelForManual;
  } else {
    u1_1 = 0U;
  }

  if (ACCtl_stRecRemoteACEna) {
    u1_2 = cal_ACCtlRecLevelForRemoteAC;
  } else {
    u1_2 = 0U;
  }

  if (ACCtl_stRecQkChargeCoolingEna) {
    rtb_IFreezFlag_k = cal_ACCtlRecLevelForQkChargeCooling;
  } else {
    rtb_IFreezFlag_k = 0U;
  }

  if (ACCtl_stRecPCUTempEna) {
    ACCtl_stRecLevelFinal = cal_ACCtlRecLevelForPCUTemp;
  } else {
    ACCtl_stRecLevelFinal = 0U;
  }

  if (rtb_Add6_d >= rtb_Add_ge3) {
    rtb_Add_ge3 = rtb_Add6_d;
  }

  if (rtb_Add_ge3 >= rtb_Add7_i) {
    rtb_Add7_i = rtb_Add_ge3;
  }

  if (rtb_Add7_i >= rtb_Add2_j5) {
    rtb_Add2_j5 = rtb_Add7_i;
  }

  if (rtb_Add2_j5 >= rtb_Add3_do) {
    rtb_Add3_do = rtb_Add2_j5;
  }

  if (rtb_Add3_do >= rtb_Add5_d) {
    rtb_Add5_d = rtb_Add3_do;
  }

  if (rtb_Add5_d >= rtb_Add4_ox) {
    rtb_Add4_ox = rtb_Add5_d;
  }

  if (rtb_Add4_ox >= rtb_DataTypeConversion19) {
    rtb_DataTypeConversion19 = rtb_Add4_ox;
  }

  if (rtb_DataTypeConversion19 >= rtb_DataTypeConversion2_a) {
    rtb_DataTypeConversion2_a = rtb_DataTypeConversion19;
  }

  if (rtb_DataTypeConversion2_a >= u1) {
    u1 = rtb_DataTypeConversion2_a;
  }

  if (u1 >= u1_0) {
    u1_0 = u1;
  }

  if (u1_0 >= u1_1) {
    u1_1 = u1_0;
  }

  if (u1_1 >= u1_2) {
    u1_2 = u1_1;
  }

  if (u1_2 >= rtb_IFreezFlag_k) {
    rtb_IFreezFlag_k = u1_2;
  }

  if (rtb_IFreezFlag_k >= ACCtl_stRecLevelFinal) {
    ACCtl_stRecLevelFinal = rtb_IFreezFlag_k;
  }

  if (ACCtl_stACPTCHeated) {
    rtb_Switch1_mn = look1_iflftu8Df_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACInletEnvPrtSetHeat_1X[0], (const uint8 *)
      &cal_ACInletEnvPrtSetHeat_CUR[0], 4U);
  } else {
    rtb_Switch1_mn = look1_iflftu8Df_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACInletEnvPrtSetCool_1X[0], (const uint8 *)
      &cal_ACInletEnvPrtSetCool_CUR[0], 4U);
  }

  if (cal_AutoDefogEnable) {
    rtb_Add_ge3 = look1_iflftu8Df_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACInletAutoDefogPrtEnvCor_1X[0], (const uint8 *)
      &cal_ACInletAutoDefogPrtEnvCor_CUR[0], 9U);
  } else {
    rtb_Add_ge3 = look1_iflftu8Df_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACInletDefogPrtEnvCor_1X[0], (const uint8 *)
      &cal_ACInletDefogPrtEnvCor_CUR[0], 9U);
  }

  rtb_Add6_d = look1_iu8lu64n56_binlcase(0U, (const uint8 *)
    &cal_ACInletDefogRiskCor_1X[0], (const uint8 *)&cal_ACInletDefogRiskCor_CUR
    [0], 1U);
  if (rtb_Add6_d <= rtb_Add_ge3) {
    rtb_Add_ge3 = rtb_Add6_d;
  }

  if ((uint8)(100 - rtb_Add_ge3) <= 100) {
    ACCtl_IntakeRatio = (uint8)(100 - rtb_Add_ge3);
  } else {
    ACCtl_IntakeRatio = 100U;
  }

  if (PWRCtl_bUnlockVentTimeFlg) {
    rtb_IFreezFlag_k = 2U;
  } else {
    rtb_IFreezFlag_k = HMICtl_eInner;
  }

  rtb_OR_i4 = ((sint32)HMICtl_bACDefrost > (sint32)
               ME11_ARID_DEF.DelayInput1_DSTATE_lk);
  if (ACCtl_stRecForceDefogEna) {
    if ((sint32)HMICtl_bACDefrost > (sint32)ME11_ARID_DEF.DelayInput1_DSTATE_ne)
    {
      rtb_Delay_ku = DriveFRESH;
    } else if (rtb_IFreezFlag_k != 0) {
      rtb_Delay_ku = RECIRC;
    } else {
      rtb_Delay_ku = DriveFRESH;
    }
  } else {
    rtb_Delay_ku = 100U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForPTCDvt) {
    rtb_Add_ge3 = 2U;
  } else {
    rtb_Add_ge3 = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForACHotStart) {
    rtb_Add7_i = 3U;
  } else {
    rtb_Add7_i = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForTargetOutTemp) {
    rtb_Add2_j5 = 4U;
  } else {
    rtb_Add2_j5 = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForVent) {
    rtb_Add3_do = 5U;
  } else {
    rtb_Add3_do = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForTempLow) {
    rtb_Add5_d = 6U;
  } else {
    rtb_Add5_d = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForAQS) {
    rtb_Add4_ox = 7U;
  } else {
    rtb_Add4_ox = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForPCUTemp) {
    rtb_DataTypeConversion19 = 8U;
  } else {
    rtb_DataTypeConversion19 = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForForceDefog) {
    rtb_DataTypeConversion2_a = 9U;
  } else {
    rtb_DataTypeConversion2_a = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForManual) {
    u1 = 10U;
  } else {
    u1 = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForQkChargeCooling) {
    u1_0 = 11U;
  } else {
    u1_0 = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForForceChange) {
    u1_1 = 12U;
  } else {
    u1_1 = 0U;
  }

  if (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForRemoteAC) {
    u1_2 = 13U;
  } else {
    u1_2 = 0U;
  }

  rtb_Add6_d = (uint8)((ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForSummer) ||
                       (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForWinter) ||
                       (ACCtl_stRecLevelFinal == cal_ACCtlRecLevelForNormalDefog));
  if (rtb_Add6_d >= rtb_Add_ge3) {
    rtb_Add_ge3 = rtb_Add6_d;
  }

  if (rtb_Add_ge3 >= rtb_Add7_i) {
    rtb_Add7_i = rtb_Add_ge3;
  }

  if (rtb_Add7_i >= rtb_Add2_j5) {
    rtb_Add2_j5 = rtb_Add7_i;
  }

  if (rtb_Add2_j5 >= rtb_Add3_do) {
    rtb_Add3_do = rtb_Add2_j5;
  }

  if (rtb_Add3_do >= rtb_Add5_d) {
    rtb_Add5_d = rtb_Add3_do;
  }

  if (rtb_Add5_d >= rtb_Add4_ox) {
    rtb_Add4_ox = rtb_Add5_d;
  }

  if (rtb_Add4_ox >= rtb_DataTypeConversion19) {
    rtb_DataTypeConversion19 = rtb_Add4_ox;
  }

  if (rtb_DataTypeConversion19 >= rtb_DataTypeConversion2_a) {
    rtb_DataTypeConversion2_a = rtb_DataTypeConversion19;
  }

  if (rtb_DataTypeConversion2_a >= u1) {
    u1 = rtb_DataTypeConversion2_a;
  }

  if (u1 >= u1_0) {
    u1_0 = u1;
  }

  if (u1_0 >= u1_1) {
    u1_1 = u1_0;
  }

  if (u1_1 >= u1_2) {
    u1_2 = u1_1;
  }

  switch (u1_2) {
   case 1:
    ACCtl_stRecOut = (ACCtl_IntakeRatio == 100);
    break;

   case 2:
    ME11_ACCtlRecForPTCDvt((boolean *)&ACCtl_stRecOut, (uint8 *)
      &ACCtl_IntakeRatio);
    break;

   case 3:
    ACCtl_stRecOut = false;
    ACCtl_IntakeRatio = 0U;
    break;

   case 4:
    ME11_ACCtlRecForPTCDvt((boolean *)&ACCtl_stRecOut, (uint8 *)
      &ACCtl_IntakeRatio);
    break;

   case 5:
    ACCtl_IntakeRatio = rtb_Switch1_mn;
    ACCtl_stRecOut = (rtb_Switch1_mn == 100);
    break;

   case 6:
    ME11_ACCtlRecForPTCDvt((boolean *)&ACCtl_stRecOut, (uint8 *)
      &ACCtl_IntakeRatio);
    break;

   case 7:
    ME11_ACCtlRecForPTCDvt((boolean *)&ACCtl_stRecOut, (uint8 *)
      &ACCtl_IntakeRatio);
    break;

   case 8:
    ME11_ACCtlRecForPTCDvt((boolean *)&ACCtl_stRecOut, (uint8 *)
      &ACCtl_IntakeRatio);
    break;

   case 9:
    ACCtl_stRecOut = ((!rtb_OR_i4) && (rtb_IFreezFlag_k != 0));
    if (rtb_OR_i4) {
      ACCtl_IntakeRatio = DriveFRESH;
    } else if (rtb_IFreezFlag_k != 0) {
      ACCtl_IntakeRatio = RECIRC;
    } else {
      ACCtl_IntakeRatio = DriveFRESH;
    }
    break;

   case 10:
    ACCtl_stRecOut = (rtb_IFreezFlag_k == 1);
    if (ACCtl_stRecOut) {
      ACCtl_IntakeRatio = 100U;
    } else {
      ACCtl_IntakeRatio = 0U;
    }
    break;

   case 11:
    ACCtl_stRecOut = (rtb_IFreezFlag_k > 0);
    ACCtl_IntakeRatio = 100U;
    break;

   case 12:
    ACCtl_stRecOut = (rtb_IFreezFlag_k > 0);
    if (ACCtl_stRecForceChangeEna) {
      rtb_Add6_d = cal_CO2RecircRatio;
    } else {
      rtb_Add6_d = 100U;
    }

    if (!ACCtl_stRecVentEna) {
      rtb_Switch1_mn = 100U;
    }

    if (ACCtl_stRecACHotStartEna) {
      rtb_Add_ge3 = 0U;
    } else {
      rtb_Add_ge3 = 100U;
    }

    if (!ACCtl_stRecNormalDefogEna) {
      ACCtl_IntakeRatio = 100U;
    }

    if (rtb_Add6_d <= rtb_Delay_ku) {
      rtb_Delay_ku = rtb_Add6_d;
    }

    if (rtb_Delay_ku <= rtb_Switch1_mn) {
      rtb_Switch1_mn = rtb_Delay_ku;
    }

    if (rtb_Switch1_mn <= rtb_Add_ge3) {
      rtb_Add_ge3 = rtb_Switch1_mn;
    }

    if (rtb_Add_ge3 <= ACCtl_IntakeRatio) {
      ACCtl_IntakeRatio = rtb_Add_ge3;
    }
    break;

   case 13:
    ME11_ACCtlRecForPTCDvt((boolean *)&ACCtl_stRecOut, (uint8 *)
      &ACCtl_IntakeRatio);
    break;

   default:
    ACCtl_stRecOut = true;
    ACCtl_IntakeRatio = 100U;
    break;
  }

  if (rtb_LogicalOperator_j0) {
    rtb_Add_ax = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel0EnvCor_1X[0], (const float32 *)&cal_ACFanLevel0EnvCor_CUR
      [0], 1U);
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel1EnvCor_1X[0], (const float32 *)&cal_ACFanLevel1EnvCor_CUR
      [0], 1U);
    rtb_Merge1_m = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel2EnvCor_1X[0], (const float32 *)&cal_ACFanLevel2EnvCor_CUR
      [0], 1U);
    rtb_Merge = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel3EnvCor_1X[0], (const float32 *)&cal_ACFanLevel3EnvCor_CUR
      [0], 1U);
    rtb_Merge1 = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel4EnvCor_1X[0], (const float32 *)&cal_ACFanLevel4EnvCor_CUR
      [0], 1U);
    rtb_Switch4_a = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel5EnvCor_1X[0], (const float32 *)&cal_ACFanLevel5EnvCor_CUR
      [0], 1U);
    rtb_DataTypeConversion23 = look1_iflf_binlca(ACSen_sEnvTempCor, (const
      float32 *)&cal_ACFanLevel6EnvCor_1X[0], (const float32 *)
      &cal_ACFanLevel6EnvCor_CUR[0], 1U);
    rtb_Gain8 = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel7EnvCor_1X[0], (const float32 *)&cal_ACFanLevel7EnvCor_CUR
      [0], 1U);
    rtb_LowPressLmt = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACFanLevel8EnvCor_1X[0], (const float32 *)&cal_ACFanLevel8EnvCor_CUR
      [0], 1U);
    if (ME11_ARID_DEF.Switch1_nv > 0) {
      if (!HMICtl_bACDefrost) {
        ACCtl_tDVTFlt = (1.0F - cal_PsDVTWeight) * ACCtl_tDrDVT + ACCtl_tPsDVT *
          cal_PsDVTWeight;
        rtb_LogicalOperator_j0 =
          ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
            ())->VIPM_ESCVehSpdVld_flg && (ACSen_eAirInletPer <
            cal_ACRecirRatioLmt));
        if (rtb_LogicalOperator_j0) {
          rtb_Saturation_ou = look1_iflf_binlca
            ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
              ())->VIPM_ESCVehSpd_kph, (const float32 *)&cal_ACFanSpdVssCor_1X[0],
             (const float32 *)&cal_ACFanSpdVssCor_CUR[0], 2U);
        } else {
          rtb_Saturation_ou = 0.0F;
        }

        AC_rRecircInc = ACCtl_IntakeRatio;
        GlbDa_LeftSolarAvr = (uint16)((uint32)(uint16)((float32)GlbDa_LeftSolar *
          0.5F) + (uint16)((float32)GlbDa_RightSolar * 0.5F));
        ACFanSpdSolarCor = look2_iu16flftf_binlca(GlbDa_LeftSolarAvr,
          ACCtl_tDVTFlt, (const uint16 *)&cal_ACFanSpdSolarCor_2X[0], (const
          float32 *)&cal_ACFanSpdSolarCor_2Y[0], (const float32 *)
          &cal_ACFanSpdSolarCor_MAP[0], ME11_ConstP.pooled33, 15U);
        ACFanSpdSolarCorByEnv = look2_iu16flftf_binlca(GlbDa_LeftSolarAvr,
          ACSen_sEnvTempCor, (const uint16 *)&cal_ACFanSpdSolarCorByEnv_2X[0], (
          const float32 *)&cal_ACFanSpdSolarCorByEnv_2Y[0], (const float32 *)
          &cal_ACFanSpdSolarCorByEnv_MAP[0], ME11_ConstP.pooled33, 15U);
        rtb_MultiportSwitch2_e = (float32)cal_FanLevelToPWM[8] + rtb_LowPressLmt;
        if (rtb_MultiportSwitch2_e > 100.0F) {
          rtb_Delay_ku = 100U;
        } else if (rtb_MultiportSwitch2_e < 0.0F) {
          rtb_Delay_ku = 0U;
        } else {
          rtb_Delay_ku = (uint8)rtb_MultiportSwitch2_e;
        }

        ACCCtl_sBlowerFanSpd = ((((float32)(uint8)(look1_iflf_binlca
          (ACCtl_tDVTFlt, (const float32 *)&cal_ACFanSpdDvtSet_1X[0], (const
          float32 *)&cal_ACFanSpdDvtSet_CUR[0], 13U) - rtb_Saturation_ou) +
          look1_iu8bflftf_binlca(AC_rRecircInc, (const float32 *)
          &cal_ACFanSpdRecircCor_1X[0], (const float32 *)
          &cal_ACFanSpdRecircCor_CUR[0], 3U)) + ACFanSpdSolarCor) +
          ACFanSpdSolarCorByEnv) * look1_iu16bflftf_binlca(1200U, (const float32
          *)&cal_ACFanSpdBatCor_1X[0], (const float32 *)&cal_ACFanSpdBatCor_CUR
          [0], 2U);
        if (ACCCtl_sBlowerFanSpd > 100.0F) {
          ACCCtl_sBlowerFanSpd = 100.0F;
        } else if (ACCCtl_sBlowerFanSpd < 0.0F) {
          ACCCtl_sBlowerFanSpd = 0.0F;
        }

        if (rtb_Delay_ku <= ACCCtl_sBlowerFanSpd) {
          ACCCtl_sBlowerFanSpd = (float32)rtb_Delay_ku;
        }

        rtb_Add_ge3 = (uint8)(((float32)cal_FanLevelToPWM[0] + rtb_Add_ax) +
                              100.0F);
        rtb_Delay_ku = (uint8)(((float32)cal_FanLevelToPWM[1] + rtb_Merge_g) +
          100.0F);
        rtb_Add2_j5 = (uint8)(((float32)cal_FanLevelToPWM[2] + rtb_Merge1_m) +
                              100.0F);
        rtb_Add3_do = (uint8)(((float32)cal_FanLevelToPWM[3] + rtb_Merge) +
                              100.0F);
        rtb_Add4_ox = (uint8)(((float32)cal_FanLevelToPWM[4] + rtb_Merge1) +
                              100.0F);
        rtb_Add5_d = (uint8)(((float32)cal_FanLevelToPWM[5] + rtb_Switch4_a) +
                             100.0F);
        rtb_Add6_d = (uint8)(((float32)cal_FanLevelToPWM[6] +
                              rtb_DataTypeConversion23) + 100.0F);
        rtb_Add7_i = (uint8)(((float32)cal_FanLevelToPWM[7] + rtb_Gain8) +
                             100.0F);
        if (rtb_Add_ge3 > 200) {
          rtb_Add_ge3 = 100U;
        } else if (rtb_Add_ge3 < 100) {
          rtb_Add_ge3 = 0U;
        } else {
          rtb_Add_ge3 = (uint8)(rtb_Add_ge3 + -100);
        }

        if (rtb_Add2_j5 > 200) {
          rtb_Add2_j5 = 100U;
        } else if (rtb_Add2_j5 < 100) {
          rtb_Add2_j5 = 0U;
        } else {
          rtb_Add2_j5 = (uint8)(rtb_Add2_j5 + -100);
        }

        if (rtb_Add3_do > 200) {
          rtb_Add3_do = 100U;
        } else if (rtb_Add3_do < 100) {
          rtb_Add3_do = 0U;
        } else {
          rtb_Add3_do = (uint8)(rtb_Add3_do + -100);
        }

        if (rtb_Add4_ox > 200) {
          rtb_Add4_ox = 100U;
        } else if (rtb_Add4_ox < 100) {
          rtb_Add4_ox = 0U;
        } else {
          rtb_Add4_ox = (uint8)(rtb_Add4_ox + -100);
        }

        if (rtb_Add5_d > 200) {
          rtb_Add5_d = 100U;
        } else if (rtb_Add5_d < 100) {
          rtb_Add5_d = 0U;
        } else {
          rtb_Add5_d = (uint8)(rtb_Add5_d + -100);
        }

        if (rtb_Add6_d > 200) {
          rtb_Add6_d = 100U;
        } else if (rtb_Add6_d < 100) {
          rtb_Add6_d = 0U;
        } else {
          rtb_Add6_d = (uint8)(rtb_Add6_d + -100);
        }

        if (rtb_Add7_i > 200) {
          rtb_Add7_i = 100U;
        } else if (rtb_Add7_i < 100) {
          rtb_Add7_i = 0U;
        } else {
          rtb_Add7_i = (uint8)(rtb_Add7_i + -100);
        }

        if (ME11_ARID_DEF.is_active_c1_ME11 == 0U) {
          ME11_ARID_DEF.is_active_c1_ME11 = 1U;
          ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_0;
          ME11_ARID_DEF.AC_FanLevel = 0U;
        } else {
          switch (ME11_ARID_DEF.is_AmbienceTempHighZero) {
           case ME11_IN_Fan_0:
            ME11_ARID_DEF.AC_FanLevel = 0U;
            if ((uint8)ACCCtl_sBlowerFanSpd > (sint32)(rtb_Add_ge3 + 10U)) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_01;
              ME11_ARID_DEF.AC_FanLevel = 1U;
            }
            break;

           case ME11_IN_Fan_01:
            ME11_ARID_DEF.AC_FanLevel = 1U;
            if ((uint8)ACCCtl_sBlowerFanSpd < (sint32)(rtb_Add_ge3 + 5U)) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_0;
              ME11_ARID_DEF.AC_FanLevel = 0U;
            } else if ((uint8)ACCCtl_sBlowerFanSpd > rtb_Add2_j5) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_02;
              ME11_ARID_DEF.AC_FanLevel = 2U;
            }
            break;

           case ME11_IN_Fan_02:
            ME11_ARID_DEF.AC_FanLevel = 2U;
            if (rtb_Delay_ku > 200) {
              rtb_Delay_ku = 100U;
            } else if (rtb_Delay_ku < 100) {
              rtb_Delay_ku = 0U;
            } else {
              rtb_Delay_ku = (uint8)(rtb_Delay_ku + -100);
            }

            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Delay_ku) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_01;
              ME11_ARID_DEF.AC_FanLevel = 1U;
            } else if ((uint8)ACCCtl_sBlowerFanSpd > rtb_Add3_do) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_03;
              ME11_ARID_DEF.AC_FanLevel = 3U;
            }
            break;

           case ME11_IN_Fan_03:
            ME11_ARID_DEF.AC_FanLevel = 3U;
            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Add2_j5) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_02;
              ME11_ARID_DEF.AC_FanLevel = 2U;
            } else if ((uint8)ACCCtl_sBlowerFanSpd > rtb_Add4_ox) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_04;
              ME11_ARID_DEF.AC_FanLevel = 4U;
            }
            break;

           case ME11_IN_Fan_04:
            ME11_ARID_DEF.AC_FanLevel = 4U;
            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Add3_do) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_03;
              ME11_ARID_DEF.AC_FanLevel = 3U;
            } else if ((uint8)ACCCtl_sBlowerFanSpd > rtb_Add5_d) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_05;
              ME11_ARID_DEF.AC_FanLevel = 5U;
            }
            break;

           case ME11_IN_Fan_05:
            ME11_ARID_DEF.AC_FanLevel = 5U;
            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Add4_ox) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_04;
              ME11_ARID_DEF.AC_FanLevel = 4U;
            } else if ((uint8)ACCCtl_sBlowerFanSpd > rtb_Add6_d) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_06;
              ME11_ARID_DEF.AC_FanLevel = 6U;
            }
            break;

           case ME11_IN_Fan_06:
            ME11_ARID_DEF.AC_FanLevel = 6U;
            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Add5_d) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_05;
              ME11_ARID_DEF.AC_FanLevel = 5U;
            } else if ((uint8)ACCCtl_sBlowerFanSpd > rtb_Add7_i) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_07;
              ME11_ARID_DEF.AC_FanLevel = 7U;
            }
            break;

           case ME11_IN_Fan_07:
            ME11_ARID_DEF.AC_FanLevel = 7U;
            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Add6_d) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_06;
              ME11_ARID_DEF.AC_FanLevel = 6U;
            } else {
              if ((uint8)(rtb_MultiportSwitch2_e + 100.0F) > 200) {
                rtb_Delay_ku = 100U;
              } else if ((uint8)(rtb_MultiportSwitch2_e + 100.0F) < 100) {
                rtb_Delay_ku = 0U;
              } else {
                rtb_Delay_ku = (uint8)((uint8)(rtb_MultiportSwitch2_e + 100.0F)
                  + -100);
              }

              if ((uint8)ACCCtl_sBlowerFanSpd >= rtb_Delay_ku) {
                ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_08;
                ME11_ARID_DEF.AC_FanLevel = 8U;
              }
            }
            break;

           default:
            ME11_ARID_DEF.AC_FanLevel = 8U;
            if ((uint8)ACCCtl_sBlowerFanSpd < rtb_Add7_i) {
              ME11_ARID_DEF.is_AmbienceTempHighZero = ME11_IN_Fan_07;
              ME11_ARID_DEF.AC_FanLevel = 7U;
            }
            break;
          }
        }

        ACCtl_BloweFanSpeed = (uint8)ACCCtl_sBlowerFanSpd;
      }

      if (HMICtl_bACDefrost) {
        if (ME11_ARID_DEF.Delay_DSTATE_fk) {
          ME11_ARID_DEF.AC_FanLevel = rtb_Switch1_e3;
        } else {
          if (rtb_DataTypeConversion_f == ACEconMode_Comfort) {
            ME11_ARID_DEF.AC_FanLevel = 6U;
          } else {
            ME11_ARID_DEF.AC_FanLevel = 5U;
          }

          if (rtb_Switch1_e3 >= ME11_ARID_DEF.AC_FanLevel) {
            ME11_ARID_DEF.AC_FanLevel = rtb_Switch1_e3;
          }
        }

        switch (ME11_ARID_DEF.AC_FanLevel) {
         case 0:
          rtb_MultiportSwitch2_e = rtb_Add_ax;
          break;

         case 1:
          rtb_MultiportSwitch2_e = rtb_Merge_g;
          break;

         case 2:
          rtb_MultiportSwitch2_e = rtb_Merge1_m;
          break;

         case 3:
          rtb_MultiportSwitch2_e = rtb_Merge;
          break;

         case 4:
          rtb_MultiportSwitch2_e = rtb_Merge1;
          break;

         case 5:
          rtb_MultiportSwitch2_e = rtb_Switch4_a;
          break;

         case 6:
          rtb_MultiportSwitch2_e = rtb_DataTypeConversion23;
          break;

         case 7:
          rtb_MultiportSwitch2_e = rtb_Gain8;
          break;

         default:
          rtb_MultiportSwitch2_e = rtb_LowPressLmt;
          break;
        }

        rtb_Delay_ku = (uint8)(((float32)
          cal_FanLevelToPWM[ME11_ARID_DEF.AC_FanLevel] + rtb_MultiportSwitch2_e)
          + 100.0F);
        if (rtb_Delay_ku > 200) {
          ACCtl_BloweFanSpeed = 100U;
        } else if (rtb_Delay_ku < 100) {
          ACCtl_BloweFanSpeed = 0U;
        } else {
          ACCtl_BloweFanSpeed = (uint8)(rtb_Delay_ku + -100);
        }
      }
    }

    if (ME11_ARID_DEF.Switch1_nv == 0) {
      switch (rtb_Switch1_e3) {
       case 0:
        rtb_LowPressLmt = rtb_Add_ax;
        break;

       case 1:
        rtb_LowPressLmt = rtb_Merge_g;
        break;

       case 2:
        rtb_LowPressLmt = rtb_Merge1_m;
        break;

       case 3:
        rtb_LowPressLmt = rtb_Merge;
        break;

       case 4:
        rtb_LowPressLmt = rtb_Merge1;
        break;

       case 5:
        rtb_LowPressLmt = rtb_Switch4_a;
        break;

       case 6:
        rtb_LowPressLmt = rtb_DataTypeConversion23;
        break;

       case 7:
        rtb_LowPressLmt = rtb_Gain8;
        break;
      }

      rtb_Delay_ku = (uint8)(((float32)cal_FanLevelToPWM[rtb_Switch1_e3] +
        rtb_LowPressLmt) + 100.0F);
      if (rtb_Delay_ku > 200) {
        ACCtl_BloweFanSpeed = 100U;
      } else if (rtb_Delay_ku < 100) {
        ACCtl_BloweFanSpeed = 0U;
      } else {
        ACCtl_BloweFanSpeed = (uint8)(rtb_Delay_ku + -100);
      }

      ME11_ARID_DEF.AC_FanLevel = rtb_Switch1_e3;
    }

    AC_FanLeVel = ME11_ARID_DEF.AC_FanLevel;
    AC_FanLevelAct = ME11_ARID_DEF.AC_FanLevel;
  }

  AC_DVT2PTCErr = ACCtl_tDrDVT -
    (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
    ->VIPM_HVCHOutlTemp_C;
  if (PWRCtl_bUnlockVentTimeFlg) {
    rtb_DataTypeConversion_jf = 4U;
  } else {
    rtb_DataTypeConversion_jf = HMICtl_eModeMotor;
  }

  rtb_LogicalOperator_j0 = (ME11_ARID_DEF.Switch1_nv != ACOff);
  ME11_ManualMode(!rtb_LogicalOperator_j0, rtb_DataTypeConversion_jf,
                  (BlowerModes *)&ACCtl_BlowerMode);
  if (rtb_LogicalOperator_j0) {
    rtb_LogicalOperator_j0 = (ME11_ARID_DEF.Switch1_nv == 0);
    if (!rtb_LogicalOperator_j0) {
      if (!HMICtl_bACDefrost) {
        ACCtl_RFaceFloor2Face = look1_iflf_binlca(ACSen_sEnvTempCor, (const
          float32 *)&cal_RFaceFloor2FaceByEnv_1X[0], (const float32 *)
          &cal_RFaceFloor2FaceByEnv_CUR[0], 13U);
        ACCtl_RFace2FaceFloor = look1_iflf_binlca(ACSen_sEnvTempCor, (const
          float32 *)&cal_RFace2FaceFloorByEnv_1X[0], (const float32 *)
          &cal_RFace2FaceFloorByEnv_CUR[0], 13U);
        ACCtl_RFaceFloor2Floor = look1_iflf_binlca(ACSen_sEnvTempCor, (const
          float32 *)&cal_RFaceFloor2FloorByEnv_1X[0], (const float32 *)
          &cal_RFaceFloor2FloorByEnv_CUR[0], 13U);
        ACCtl_RFloor2FaceFloor = look1_iflf_binlca(ACSen_sEnvTempCor, (const
          float32 *)&cal_RFloor2FaceFloorByEnv_1X[0], (const float32 *)
          &cal_RFloor2FaceFloorByEnv_CUR[0], 13U);
        if (ME11_ARID_DEF.is_active_c3_ME11 == 0U) {
          ME11_ARID_DEF.is_active_c3_ME11 = 1U;
          ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerNormal;
          if (ACCtl_tDrDVT < ACCtl_RFaceFloor2Face) {
            ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face;
            rtb_Delay_ku = BlowerACMode;
          } else if (ACCtl_tDrDVT > ACCtl_RFaceFloor2Floor) {
            ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Floor;
            rtb_Delay_ku = BlowerHeaterMode;
          } else {
            ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face_Floor;
            rtb_Delay_ku = BlowerBILevelMode;
          }
        } else {
          switch (ME11_ARID_DEF.is_c3_ME11) {
           case ME11_IN_BlowerModeLim:
            rtb_Delay_ku = BlowerHeaterMode;
            if (ACCtl_stStartState != ME11_HotStart) {
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerNormal;
              if (ACCtl_tDrDVT < ACCtl_RFaceFloor2Face) {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face;
                rtb_Delay_ku = BlowerACMode;
              } else if (ACCtl_tDrDVT > ACCtl_RFaceFloor2Floor) {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Floor;
              } else {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face_Floor;
                rtb_Delay_ku = BlowerBILevelMode;
              }
            }
            break;

           case ME11_IN_BlowerModeLockFloor:
            rtb_Delay_ku = BlowerDefrostMode;
            if (ACCtl_stStartState == ME11_NormalStart) {
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerNormal;
              if (ACCtl_tDrDVT < ACCtl_RFaceFloor2Face) {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face;
                rtb_Delay_ku = BlowerACMode;
              } else if (ACCtl_tDrDVT > ACCtl_RFaceFloor2Floor) {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Floor;
                rtb_Delay_ku = BlowerHeaterMode;
              } else {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face_Floor;
                rtb_Delay_ku = BlowerBILevelMode;
              }
            } else if (ACCtl_stStartState == ME11_LittleCold) {
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerModeLockFloor1;
              rtb_Delay_ku = BlowerHeaterDefrostMode;
            }
            break;

           case ME11_IN_BlowerModeLockFloor1:
            rtb_Delay_ku = BlowerHeaterDefrostMode;
            if (ACCtl_stStartState == ME11_ColdStart) {
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerModeLockFloor;
              rtb_Delay_ku = BlowerDefrostMode;
            } else if (ACCtl_stStartState == ME11_NormalStart) {
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerNormal;
              if (ACCtl_tDrDVT < ACCtl_RFaceFloor2Face) {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face;
                rtb_Delay_ku = BlowerACMode;
              } else if (ACCtl_tDrDVT > ACCtl_RFaceFloor2Floor) {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Floor;
                rtb_Delay_ku = BlowerHeaterMode;
              } else {
                ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face_Floor;
                rtb_Delay_ku = BlowerBILevelMode;
              }
            }
            break;

           default:
            if (ACCtl_stStartState == ME11_ColdStart) {
              ME11_ARID_DEF.is_BlowerNormal = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerModeLockFloor;
              rtb_Delay_ku = BlowerDefrostMode;
            } else if (ACCtl_stStartState == ME11_HotStart) {
              ME11_ARID_DEF.is_BlowerNormal = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerModeLim;
              rtb_Delay_ku = BlowerHeaterMode;
            } else if (ACCtl_stStartState == ME11_LittleCold) {
              ME11_ARID_DEF.is_BlowerNormal = ME11_IN_NO_ACTIVE_CHILD_gl;
              ME11_ARID_DEF.is_c3_ME11 = ME11_IN_BlowerModeLockFloor1;
              rtb_Delay_ku = BlowerHeaterDefrostMode;
            } else {
              switch (ME11_ARID_DEF.is_BlowerNormal) {
               case ME11_IN_Face:
                rtb_Delay_ku = BlowerACMode;
                if (ACCtl_tDrDVT > ACCtl_RFace2FaceFloor) {
                  ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face_Floor;
                  rtb_Delay_ku = BlowerBILevelMode;
                }
                break;

               case ME11_IN_Face_Floor:
                rtb_Delay_ku = BlowerBILevelMode;
                if (ACCtl_tDrDVT < ACCtl_RFaceFloor2Face) {
                  ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face;
                  rtb_Delay_ku = BlowerACMode;
                } else if (ACCtl_tDrDVT > ACCtl_RFaceFloor2Floor) {
                  ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Floor;
                  rtb_Delay_ku = BlowerHeaterMode;
                }
                break;

               default:
                rtb_Delay_ku = BlowerHeaterMode;
                if (ACCtl_tDrDVT < ACCtl_RFloor2FaceFloor) {
                  ME11_ARID_DEF.is_BlowerNormal = ME11_IN_Face_Floor;
                  rtb_Delay_ku = BlowerBILevelMode;
                }
                break;
              }
            }
            break;
          }
        }

        ACCtl_BlowerMode = rtb_Delay_ku;
      } else {
        ACCtl_BlowerMode = BlowerModes_DeforstMode;
      }
    }

    ME11_ManualMode(rtb_LogicalOperator_j0, rtb_DataTypeConversion_jf,
                    (BlowerModes *)&ACCtl_BlowerMode);
  }

  rtb_Switch1_e3 = ACCtl_BlowerMode;
  if (cal_ModeMotorTrgPosDataEnb) {
    IOCtl_sModeMotorTrgPos = cal_ModeMotorTrgPosData;
  } else if (((Buffer_DcmDspData_3238[0] & 4) == 4) &&
             (Rte_DcmDspData_3238_CtlFlg == 1)) {
    IOCtl_sModeMotorTrgPos =
      ME11_ConstP.Rte_TMSPositions_ModeMotor_tableData[plook_u32u8_binckan
      (Buffer_DcmDspData_3238[3],
       ME11_ConstP.Rte_TMSPositions_ModeMotor_bp01Data, 1U)];
  } else {
    IOCtl_sModeMotorTrgPos = cal_ModeMotorTrgPos_CUR[plook_u32u8_binckan
      (ACCtl_BlowerMode, (const uint8 *)&cal_ModeMotorTrgPos_1X[0], 4U)];
  }

  rtb_LogicalOperator_j0 = (IOCtl_sModeMotorTrgPos !=
    ME11_ARID_DEF.DelayInput1_DSTATE_m);
  if (ME11_ARID_DEF.temporalCounter_i1_g < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_g++;
  }

  if (ME11_ARID_DEF.temporalCounter_i2_m < 7U) {
    ME11_ARID_DEF.temporalCounter_i2_m++;
  }

  if (ME11_ARID_DEF.is_active_c61_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c61_ME11 = 1U;
    ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
    ME11_ARID_DEF.p = 0U;
    ME11_ARID_DEF.n = 0U;
    ME11_ARID_DEF.MoveSts = false;
    ME11_ARID_DEF.Sts_m = 0U;
    ME11_ARID_DEF.is_Diagnostic = ME11_IN_Init_i;
    ME11_ARID_DEF.TempVol = ACSen_sModeMotorVol;
  } else {
    switch (ME11_ARID_DEF.is_Move) {
     case ME11_IN_ALLDefrost:
      ME11_ARID_DEF.p = 1U;
      ME11_ARID_DEF.n = 0U;
      if (ME11_ARID_DEF.temporalCounter_i1_g >= 10U) {
        ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
        ME11_ARID_DEF.Sts_m = 0U;
      }
      break;

     case ME11_IN_ALLFace:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 1U;
      if (ME11_ARID_DEF.temporalCounter_i1_g >= 10U) {
        ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
        ME11_ARID_DEF.Sts_m = 0U;
      }
      break;

     case ME11_IN_Default_o:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 0U;
      ME11_ARID_DEF.MoveSts = false;
      if ((IOCtl_sModeMotorTrgPos > ACSen_sModeMotorVol + cal_ModeMotorPErr) &&
          rtb_LogicalOperator_j0) {
        ME11_ARID_DEF.Stuck_Sts = 0U;
        ME11_ARID_DEF.is_Move = ME11_IN_Face_f;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 1U;
        ME11_ARID_DEF.MoveSts = true;
      } else if ((IOCtl_sModeMotorTrgPos < ACSen_sModeMotorVol -
                  cal_ModeMotorNErr) && rtb_LogicalOperator_j0) {
        ME11_ARID_DEF.Stuck_Sts = 0U;
        ME11_ARID_DEF.is_Move = ME11_IN_Defrost_j;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 1U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = true;
      }
      break;

     case ME11_IN_Defrost_j:
      ME11_ARID_DEF.p = 1U;
      ME11_ARID_DEF.n = 0U;
      ME11_ARID_DEF.MoveSts = true;
      if (IOCtl_sModeMotorTrgPos > ACSen_sModeMotorVol - cal_ModeMotorNErr) {
        if (IOCtl_sModeMotorTrgPos <= 0.9F) {
          ME11_ARID_DEF.is_Move = ME11_IN_ALLDefrost;
          ME11_ARID_DEF.temporalCounter_i1_g = 0U;
          ME11_ARID_DEF.p = 1U;
          ME11_ARID_DEF.n = 0U;
        } else {
          ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
          ME11_ARID_DEF.p = 0U;
          ME11_ARID_DEF.n = 0U;
          ME11_ARID_DEF.MoveSts = false;
          ME11_ARID_DEF.Sts_m = 0U;
        }
      } else if (ME11_ARID_DEF.Sts_m == 1) {
        ME11_ARID_DEF.is_Move = ME11_IN_Defrost_Stuck;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_g >= 600U) {
        ME11_ARID_DEF.is_Move = ME11_IN_Fault1_b;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
      }
      break;

     case ME11_IN_Defrost_Stuck:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 0U;
      ME11_ARID_DEF.MoveSts = false;
      if (ME11_ARID_DEF.Sts_m == 2) {
        ME11_ARID_DEF.Stuck_Sts = 1U;
        ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
        ME11_ARID_DEF.Sts_m = 0U;
      } else if (ME11_ARID_DEF.temporalCounter_i1_g >= 20U) {
        ME11_ARID_DEF.is_Move = ME11_IN_Defrost_j;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 1U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = true;
      }
      break;

     case ME11_IN_Face_f:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 1U;
      ME11_ARID_DEF.MoveSts = true;
      if (IOCtl_sModeMotorTrgPos < ACSen_sModeMotorVol + cal_ModeMotorPErr) {
        if (IOCtl_sModeMotorTrgPos >= 4.4F) {
          ME11_ARID_DEF.is_Move = ME11_IN_ALLFace;
          ME11_ARID_DEF.temporalCounter_i1_g = 0U;
          ME11_ARID_DEF.p = 0U;
          ME11_ARID_DEF.n = 1U;
        } else {
          ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
          ME11_ARID_DEF.p = 0U;
          ME11_ARID_DEF.n = 0U;
          ME11_ARID_DEF.MoveSts = false;
          ME11_ARID_DEF.Sts_m = 0U;
        }
      } else if (ME11_ARID_DEF.Sts_m == 1) {
        ME11_ARID_DEF.is_Move = ME11_IN_Face_Stuck;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_g >= 600U) {
        ME11_ARID_DEF.is_Move = ME11_IN_Fault_l;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
      }
      break;

     case ME11_IN_Face_Stuck:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 0U;
      ME11_ARID_DEF.MoveSts = false;
      if (ME11_ARID_DEF.Sts_m == 2) {
        ME11_ARID_DEF.Stuck_Sts = 1U;
        ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
        ME11_ARID_DEF.Sts_m = 0U;
      } else if (ME11_ARID_DEF.temporalCounter_i1_g >= 20U) {
        ME11_ARID_DEF.is_Move = ME11_IN_Face_f;
        ME11_ARID_DEF.temporalCounter_i1_g = 0U;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 1U;
        ME11_ARID_DEF.MoveSts = true;
      }
      break;

     case ME11_IN_Fault_l:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 0U;
      ME11_ARID_DEF.MoveSts = false;
      if (cal_ModeMotorEnb || (ME11_ARID_DEF.temporalCounter_i1_g >= 1000U)) {
        ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
        ME11_ARID_DEF.Sts_m = 0U;
      }
      break;

     default:
      ME11_ARID_DEF.p = 0U;
      ME11_ARID_DEF.n = 0U;
      ME11_ARID_DEF.MoveSts = false;
      if (cal_ModeMotorEnb || (ME11_ARID_DEF.temporalCounter_i1_g >= 1000U)) {
        ME11_ARID_DEF.is_Move = ME11_IN_Default_o;
        ME11_ARID_DEF.p = 0U;
        ME11_ARID_DEF.n = 0U;
        ME11_ARID_DEF.MoveSts = false;
        ME11_ARID_DEF.Sts_m = 0U;
      }
      break;
    }

    switch (ME11_ARID_DEF.is_Diagnostic) {
     case ME11_IN_Init_i:
      if (ME11_ARID_DEF.MoveSts) {
        ME11_ARID_DEF.is_Diagnostic = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i2_m = 0U;
      } else {
        ME11_ARID_DEF.TempVol = ACSen_sModeMotorVol;
      }
      break;

     case ME11_IN_Judge:
      ME11_ARID_DEF.is_Diagnostic = ME11_IN_Init_i;
      ME11_ARID_DEF.TempVol = ACSen_sModeMotorVol;
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i2_m >= 5U) {
        if ((float32)fabs(ME11_ARID_DEF.TempVol - ACSen_sModeMotorVol) < 0.04F)
        {
          ME11_ARID_DEF.is_Diagnostic = ME11_IN_Judge;
          b_previousEvent = ME11_ARID_DEF.Sts_m + 1;
          if (ME11_ARID_DEF.Sts_m + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Sts_m = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.is_Diagnostic = ME11_IN_Init_i;
          ME11_ARID_DEF.TempVol = ACSen_sModeMotorVol;
        }
      }
      break;
    }
  }

  IOCtl_bModeMoveSts = ME11_ARID_DEF.MoveSts;
  rtb_DataTypeConversion_jf = ACCtl_BlowerMode;
  rtb_OR_i4 = (ACCtl_BlowerMode != ME11_ARID_DEF.DelayInput1_DSTATE_hd);
  if (ME11_ARID_DEF.is_active_c2_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c2_ME11 = 1U;
    ME11_ARID_DEF.is_c2_ME11 = ME11_IN_Mode;
    rtb_LogicalOperator_j0 = false;
    ME11_ARID_DEF.FanLimitTime = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c2_ME11) {
     case ME11_IN_Limit:
      rtb_LogicalOperator_j0 = true;
      if (((!rtb_OR_i4) && (!IOCtl_bModeMoveSts)) || (ME11_ARID_DEF.FanLimitTime
           >= 2000)) {
        ME11_ARID_DEF.is_c2_ME11 = ME11_IN_Mode;
        rtb_LogicalOperator_j0 = false;
        ME11_ARID_DEF.FanLimitTime = 0U;
      } else {
        b_previousEvent = ME11_ARID_DEF.FanLimitTime + 1;
        if (ME11_ARID_DEF.FanLimitTime + 1 > 65535) {
          b_previousEvent = 65535;
        }

        ME11_ARID_DEF.FanLimitTime = (uint16)b_previousEvent;
      }
      break;

     case ME11_IN_Mode:
      rtb_LogicalOperator_j0 = false;
      if (rtb_OR_i4) {
        ME11_ARID_DEF.is_c2_ME11 = ME11_IN_Modehaschanged;
        rtb_LogicalOperator_j0 = true;
        ME11_ARID_DEF.FanLimitTime = 0U;
      }
      break;

     default:
      rtb_LogicalOperator_j0 = true;
      if (IOCtl_bModeMoveSts) {
        ME11_ARID_DEF.is_c2_ME11 = ME11_IN_Limit;
        ME11_ARID_DEF.FanLimitTime = 0U;
      } else if (ME11_ARID_DEF.FanLimitTime >= 50) {
        ME11_ARID_DEF.is_c2_ME11 = ME11_IN_Mode;
        rtb_LogicalOperator_j0 = false;
        ME11_ARID_DEF.FanLimitTime = 0U;
      } else {
        b_previousEvent = ME11_ARID_DEF.FanLimitTime + 1;
        if (ME11_ARID_DEF.FanLimitTime + 1 > 65535) {
          b_previousEvent = 65535;
        }

        ME11_ARID_DEF.FanLimitTime = (uint16)b_previousEvent;
      }
      break;
    }
  }

  rtb_Switch_n2 =
    ((Rte_IRead_Task_100ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
      ())->VIPM_BMSDCSActOprtMode_enum == 5);
  if ((ACCtl_stStartState == AC_ColdStart) || (AC_LittleColdStart ==
       ACCtl_stStartState)) {
    rtb_Delay_ku = look1_iflftu8Df_binlca(AC_DVT2PTCErr, (const float32 *)
      &cal_ACFanMaxSpdDvtLim_1X[0], (const uint8 *)&cal_ACFanMaxSpdDvtLim_CUR[0],
      4U);
  } else {
    rtb_Delay_ku = 93U;
  }

  if (rtb_Switch_n2 && (ME11_ARID_DEF.Delay_DSTATE_lv == 1)) {
    rtb_Add2_j5 = look1_iflftu8Df_binlca(BMS_HVBatCellTempMax, (const float32 *)
      &cal_ACFanMaxSpdCellTempLim_1X[0], (const uint8 *)
      &cal_ACFanMaxSpdCellTempLim_CUR[0], 4U);
  } else {
    rtb_Add2_j5 = 93U;
  }

  if (rtb_LogicalOperator_j0) {
    rtb_Add_ge3 = cal_FANSpdModeShiftMax;
  } else {
    rtb_Add_ge3 = 93U;
  }

  if (ACCtl_stStartState == AC_HotStart) {
    rtb_Add7_i = cal_FANSpdHotStartUL;
  } else {
    rtb_Add7_i = 93U;
  }

  if (rtb_DataTypeConversion_f == ACEconMode_FanOnly) {
    AC_BlowerFanSpeedMax = cal_BlowerFanSpdVentUL;
  } else {
    AC_BlowerFanSpeedMax = 93U;
  }

  if (rtb_Delay_ku <= rtb_Add_ge3) {
    rtb_Add_ge3 = rtb_Delay_ku;
  }

  if (rtb_Add_ge3 <= rtb_Add7_i) {
    rtb_Add7_i = rtb_Add_ge3;
  }

  if (rtb_Add7_i <= AC_BlowerFanSpeedMax) {
    AC_BlowerFanSpeedMax = rtb_Add7_i;
  }

  if (AC_BlowerFanSpeedMax > rtb_Add2_j5) {
    AC_BlowerFanSpeedMax = rtb_Add2_j5;
  }

  if (ACCtl_stStartState == AC_HotStart) {
    AC_BlowerFanSpeedMin = cal_FANSpdHotStartLL;
  } else {
    AC_BlowerFanSpeedMin = cal_BlowerFanSpdLL;
  }

  rtb_LogicalOperator_j0 =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 14);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_LogicalOperator_j0,
    &ME11_ARID_DEF.ErrSts_e, &ME11_ARID_DEF.ARID_DEF_Outlet_Temp_Sensor_Fault);
  if (ME11_ARID_DEF.Switch1_nv != ACOff) {
    if (rtb_Compare_oc || rtb_Compare_pw) {
      rtb_Add_ax = 0.0F;
    } else {
      rtb_Add_ax = ACSen_sEvapTempFilter;
    }

    if (cal_PtcEnable) {
      ACCtl_DrfacPtc2NominalTemp = 0.0F;
    } else if (ME11_ARID_DEF.ErrSts_e) {
      ACCtl_DrfacPtc2NominalTemp = 0.0F;
    } else {
      if (cal_EvaEnable) {
        rtb_Merge_g = 0.0F;
      } else {
        rtb_Merge_g = rtb_Add_ax;
      }

      rtb_Merge1_m =
        (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
        ->VIPM_HVCHOutlTemp_C - rtb_Merge_g;
      if (rtb_Merge1_m < 1.0F) {
        rtb_Merge1_m = 1.0F;
      }

      ACCtl_DrfacPtc2NominalTemp = (cal_LAirmixNomOutWaterT - rtb_Merge_g) /
        rtb_Merge1_m;
      if (ACCtl_DrfacPtc2NominalTemp > 1.0F) {
        ACCtl_DrfacPtc2NominalTemp = 1.0F;
      } else if (ACCtl_DrfacPtc2NominalTemp < 0.0F) {
        ACCtl_DrfacPtc2NominalTemp = 0.0F;
      }
    }

    rtb_MultiportSwitch2_e = (float32)floor((rtb_Add_ax - ACCtl_tDrDVT) * 2.0F);
    if (rtb_MultiportSwitch2_e < 32768.0F) {
      if (rtb_MultiportSwitch2_e >= -32768.0F) {
        rtb_DataTypeConversion_dt = (sint16)rtb_MultiportSwitch2_e;
      } else {
        rtb_DataTypeConversion_dt = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion_dt = MAX_int16_T;
    }

    rtb_Merge_g = cal_DrErrOfEvaDVT2CoolMixOn * 2.0F;
    rtb_Add_ax = cal_DrErrOfEvaDVT2CoolMixOff * 2.0F;
    if ((float32)fabs(rtb_Merge_g) >= 0.5F) {
      rtb_MultiportSwitch2_e = (float32)floor(rtb_Merge_g + 0.5F);
    } else {
      rtb_MultiportSwitch2_e = 0.0F;
    }

    if ((float32)fabs(rtb_Add_ax) >= 0.5F) {
      rtb_DataTypeConversion23 = (float32)floor(rtb_Add_ax + 0.5F);
    } else {
      rtb_DataTypeConversion23 = 0.0F;
    }

    ME11_ARID_DEF.Oncal_DrErrOfEvaDVT2CoolMixOnOffcal_DrErrOfEvaDVT2CoolMixOff_Mode
      = ((rtb_DataTypeConversion_dt >= (sint16)rtb_MultiportSwitch2_e) ||
         ((rtb_DataTypeConversion_dt > (sint16)rtb_DataTypeConversion23) &&
          ME11_ARID_DEF.Oncal_DrErrOfEvaDVT2CoolMixOnOffcal_DrErrOfEvaDVT2CoolMixOff_Mode));
    rtb_MultiportSwitch2_e = (float32)floor((ACCtl_tDrDVT -
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C) * 2.0F);
    if (rtb_MultiportSwitch2_e < 32768.0F) {
      if (rtb_MultiportSwitch2_e >= -32768.0F) {
        rtb_DataTypeConversion_dt = (sint16)rtb_MultiportSwitch2_e;
      } else {
        rtb_DataTypeConversion_dt = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion_dt = MAX_int16_T;
    }

    rtb_Merge_g = cal_DrErrOfPtcDVT2HeatMixOn * 2.0F;
    rtb_Add_ax = cal_DrErrOfPtcDVT2HeatMixOff * 2.0F;
    if ((float32)fabs(rtb_Merge_g) >= 0.5F) {
      rtb_MultiportSwitch2_e = (float32)floor(rtb_Merge_g + 0.5F);
    } else {
      rtb_MultiportSwitch2_e = 0.0F;
    }

    if ((float32)fabs(rtb_Add_ax) >= 0.5F) {
      rtb_DataTypeConversion23 = (float32)floor(rtb_Add_ax + 0.5F);
    } else {
      rtb_DataTypeConversion23 = 0.0F;
    }

    ME11_ARID_DEF.Oncal_DrErrOfPtcDVT2HeatMixOnOffcal_DrErrOfPtcDVT2HeatMixOff_Mode
      = ((rtb_DataTypeConversion_dt >= (sint16)rtb_MultiportSwitch2_e) ||
         ((rtb_DataTypeConversion_dt > (sint16)rtb_DataTypeConversion23) &&
          ME11_ARID_DEF.Oncal_DrErrOfPtcDVT2HeatMixOnOffcal_DrErrOfPtcDVT2HeatMixOff_Mode));
    if (ME11_ARID_DEF.Oncal_DrErrOfEvaDVT2CoolMixOnOffcal_DrErrOfEvaDVT2CoolMixOff_Mode)
    {
      ACCtl_rDrBasicMixDoor = 0U;
    } else if
        (ME11_ARID_DEF.Oncal_DrErrOfPtcDVT2HeatMixOnOffcal_DrErrOfPtcDVT2HeatMixOff_Mode)
    {
      ACCtl_rDrBasicMixDoor = 100U;
    } else {
      switch (rtb_Delay_n2) {
       case BlowerModes_FaceMode:
        rtb_Add_ax = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
          &cal_DrMixBacSetFace_1X[0], (const float32 *)&cal_DrMixBacSetFace_CUR
          [0], 7U);
        break;

       case BlowerModes_FaceHeaterMode:
        rtb_Add_ax = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
          &cal_DrMixBacSetFaceHeater_1X[0], (const float32 *)
          &cal_DrMixBacSetFaceHeater_CUR[0], 7U);
        break;

       case BlowerModes_HeaterMode:
        rtb_Add_ax = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
          &cal_DrMixBacSetHeater_1X[0], (const float32 *)
          &cal_DrMixBacSetHeater_CUR[0], 7U);
        break;

       case BlowerModes_HeaterDeforstMode:
        rtb_Add_ax = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
          &cal_DrMixBacSetHeaterDeforst_1X[0], (const float32 *)
          &cal_DrMixBacSetHeaterDeforst_CUR[0], 7U);
        break;

       default:
        rtb_Add_ax = look1_iflf_binlca(ACCtl_tDrDVT, (const float32 *)
          &cal_DrMixBacSetDefog_1X[0], (const float32 *)
          &cal_DrMixBacSetDefog_CUR[0], 7U);
        break;
      }

      rtb_Divide1_f = (uint32)(ACCtl_DrfacPtc2NominalTemp * rtb_Add_ax * 256.0F);
      if (rtb_Divide1_f > 25600U) {
        ACCtl_rDrBasicMixDoor = 100U;
      } else {
        ACCtl_rDrBasicMixDoor = (uint8)(rtb_Divide1_f >> 8);
      }
    }

    if (cal_FixPIDSecletFlag) {
      rtb_Add_ax = ACCtl_tDrDVT - ACCtl_tRightDuct;
      ME11_PI_Controller1(!rtb_LogicalOperator1_f, (float32)
                          ACCtl_rDrBasicMixDoor, &rtb_PI_Cor_d,
                          &rtb_IFreezFlag_bd);
      rtb_LogicalOperator_j0 = (ACCtl_tDrDVT >= ACCtl_tRightDuct);
      rtb_OR_i4 = ((rtb_Switch2_ht == 7) || (rtb_Switch2_ht == 8));
      if (rtb_OR_i4) {
        ACCtl_sMixDoorClsFF = look1_iflf_binlca(rtb_Add_ax, (const float32 *)
          &cal_MixDoorClsFF_1X[0], (const float32 *)&cal_MixDoorClsFF_CUR[0], 7U);
      } else {
        ACCtl_sMixDoorClsFF = (float32)ACCtl_rDrBasicMixDoor;
      }

      ME11_deadzone_h(rtb_Add_ax, 0.5, &rtb_flag_g);
      if (rtb_flag_g) {
        rtb_Merge_g = 0.0F;
      } else if (rtb_LogicalOperator_j0) {
        rtb_Merge_g = rtb_Add_ax;
      } else {
        rtb_Merge_g = ACCtl_tRightDuct - ACCtl_tDrDVT;
      }

      if (rtb_OR_i4) {
        ACTCtl_sCOMPSetPoint = look1_iflf_binlca(rtb_Add_ax, (const float32 *)
          &cal_MixDoorKp_1X[0], (const float32 *)&cal_MixDoorKp_CUR[0], 7U);
        ACTCtl_sCOMPActure = ACTCtl_sCOMPSetPoint;
        rtb_Merge1_m = 0.0F;
        rtb_MultiportSwitch2_e = 0.0F;
      } else {
        ACTCtl_sCOMPSetPoint = cal_DrMixDesValPID_KpPos;
        ACTCtl_sCOMPActure = cal_DrMixDesValPID_KpNeg;
        rtb_Merge1_m = cal_DrMixDesValPID_Kp;
        rtb_MultiportSwitch2_e = cal_DrMixDesValPID_pWinNeg;
      }

      ME11_P_NEG_p(!rtb_LogicalOperator_j0, rtb_Merge_g, rtb_MultiportSwitch2_e,
                   ACTCtl_sCOMPActure, rtb_Merge1_m, (float32 *)
                   &ACCtl_rDrSetMixDoorPCor);
      if (rtb_OR_i4) {
        rtb_MultiportSwitch2_e = 0.0F;
      } else {
        rtb_MultiportSwitch2_e = cal_DrMixDesValPID_pWinPos;
      }

      ME11_P_POS_l(rtb_LogicalOperator_j0, rtb_Merge_g, rtb_MultiportSwitch2_e,
                   ACTCtl_sCOMPSetPoint, rtb_Merge1_m, (float32 *)
                   &ACCtl_rDrSetMixDoorPCor);
      if (rtb_OR_i4) {
        ACTCtl_sCOMPSetPoint = look1_iflf_binlca(rtb_Add_ax, (const float32 *)
          &cal_MixDoorKi_1X[0], (const float32 *)&cal_MixDoorKi_CUR[0], 7U);
        ACTCtl_sCOMPActure = ACTCtl_sCOMPSetPoint;
      } else {
        ACTCtl_sCOMPSetPoint = cal_DrMixDesValPID_KiPos;
        ACTCtl_sCOMPActure = cal_DrMixDesValPID_KiNeg;
      }

      ME11_P_NEG(!rtb_LogicalOperator_j0, rtb_Merge_g,
                 cal_DrMixDesValPIDIntegDeadBand, ACTCtl_sCOMPActure,
                 cal_DrMixDesValPID_Ki, (float32 *)&ACCtl_rDrSetMixDoorICor);
      ME11_P_POS(rtb_LogicalOperator_j0, rtb_Merge_g,
                 cal_DrMixDesValPIDIntegDeadBand, ACTCtl_sCOMPSetPoint,
                 cal_DrMixDesValPID_Ki, (float32 *)&ACCtl_rDrSetMixDoorICor);
      if ((rtb_OR_i4 == ME11_ARID_DEF.DelayInput1_DSTATE_dw) &&
          rtb_LogicalOperator1_f) {
        switch (ME11_ARID_DEF.Delay_DSTATE_axe) {
         case 0:
          if (rtb_LogicalOperator_j0) {
            ACCtl_rDrSetMixDoorISum = ACCtl_rDrSetMixDoorISum +
              ACCtl_rDrSetMixDoorICor;
          } else {
            ACCtl_rDrSetMixDoorISum = ACCtl_rDrSetMixDoorISum -
              ACCtl_rDrSetMixDoorICor;
          }
          break;

         case 1:
          if (!rtb_LogicalOperator_j0) {
            ACCtl_rDrSetMixDoorISum = ACCtl_rDrSetMixDoorISum -
              ACCtl_rDrSetMixDoorICor;
          }
          break;

         case 2:
          if (rtb_LogicalOperator_j0) {
            ACCtl_rDrSetMixDoorISum = ACCtl_rDrSetMixDoorISum +
              ACCtl_rDrSetMixDoorICor;
          }
          break;

         case 3:
          break;
        }

        if (ACCtl_rDrSetMixDoorISum > cal_DrMixDesValPID_IsumMax) {
          ACCtl_rDrSetMixDoorISum = cal_DrMixDesValPID_IsumMax;
        } else if (ACCtl_rDrSetMixDoorISum < cal_DrMixDesValPID_IsumMin) {
          ACCtl_rDrSetMixDoorISum = cal_DrMixDesValPID_IsumMin;
        }
      } else {
        ACCtl_rDrSetMixDoorISum = 0.0F;
      }

      ME11_PI_Controller(rtb_LogicalOperator1_f, rtb_LogicalOperator_j0,
                         ACCtl_sMixDoorClsFF, ACCtl_rDrSetMixDoorPCor,
                         ACCtl_rDrSetMixDoorISum, (float32)cal_DrMixDesValPIDUL,
                         (float32)cal_DrMixDesValPIDLL, &rtb_PI_Cor_d,
                         &rtb_IFreezFlag_bd);
      ACCtl_rDrMixDoorDes = (uint8)rtb_PI_Cor_d;
      ME11_ARID_DEF.Delay_DSTATE_axe = rtb_IFreezFlag_bd;
      ME11_ARID_DEF.DelayInput1_DSTATE_dw = rtb_OR_i4;
    }
  }

  if (ME11_ARID_DEF.Switch1_nv != ACOff) {
    if (rtb_Compare_oc || rtb_Compare_pw) {
      rtb_PI_Cor_d = 0.0F;
    } else {
      rtb_PI_Cor_d = ACSen_sEvapTempFilter;
    }

    if (cal_PtcEnable) {
      ACCtl_PsfacPtc2NominalTemp = 0.0F;
    } else if (ME11_ARID_DEF.ErrSts_e) {
      ACCtl_PsfacPtc2NominalTemp = 0.0F;
    } else {
      if (cal_EvaEnable) {
        rtb_Add_ax = 0.0F;
      } else {
        rtb_Add_ax = rtb_PI_Cor_d;
      }

      rtb_Merge_g =
        (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
        ->VIPM_HVCHOutlTemp_C - rtb_Add_ax;
      if (rtb_Merge_g < 1.0F) {
        rtb_Merge_g = 1.0F;
      }

      ACCtl_PsfacPtc2NominalTemp = (cal_LAirmixNomOutWaterT - rtb_Add_ax) /
        rtb_Merge_g;
      if (ACCtl_PsfacPtc2NominalTemp > 1.0F) {
        ACCtl_PsfacPtc2NominalTemp = 1.0F;
      } else if (ACCtl_PsfacPtc2NominalTemp < 0.0F) {
        ACCtl_PsfacPtc2NominalTemp = 0.0F;
      }
    }

    switch (rtb_Delay_n2) {
     case BlowerModes_FaceMode:
      ACCtl_rPsBlowerModeSet = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
        &cal_PsMixBacSetAC_1X[0], (const float32 *)&cal_PsMixBacSetAC_CUR[0], 7U);
      break;

     case BlowerModes_FaceHeaterMode:
      ACCtl_rPsBlowerModeSet = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
        &cal_PsMixBacSetBi_1X[0], (const float32 *)&cal_PsMixBacSetBi_CUR[0], 7U);
      break;

     case BlowerModes_HeaterMode:
      ACCtl_rPsBlowerModeSet = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
        &cal_PsMixBacSetFoot_1X[0], (const float32 *)&cal_PsMixBacSetFoot_CUR[0],
        7U);
      break;

     case BlowerModes_HeaterDeforstMode:
      ACCtl_rPsBlowerModeSet = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
        &cal_PsMixBacSetFootDe_1X[0], (const float32 *)
        &cal_PsMixBacSetFootDe_CUR[0], 7U);
      break;

     default:
      ACCtl_rPsBlowerModeSet = look1_iflf_binlca(ACCtl_tPsDVT, (const float32 *)
        &cal_PsMixBacSetDefog_1X[0], (const float32 *)&cal_PsMixBacSetDefog_CUR
        [0], 7U);
      break;
    }

    rtb_MultiportSwitch2_e = (float32)floor((rtb_PI_Cor_d - ACCtl_tPsDVT) * 2.0F);
    if (rtb_MultiportSwitch2_e < 32768.0F) {
      if (rtb_MultiportSwitch2_e >= -32768.0F) {
        rtb_DataTypeConversion_dt = (sint16)rtb_MultiportSwitch2_e;
      } else {
        rtb_DataTypeConversion_dt = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion_dt = MAX_int16_T;
    }

    rtb_Merge_g = cal_PsErrOfEvaDVT2CoolMixOn * 2.0F;
    rtb_Add_ax = cal_PsErrOfEvaDVT2CoolMixOff * 2.0F;
    if ((float32)fabs(rtb_Merge_g) >= 0.5F) {
      rtb_MultiportSwitch2_e = (float32)floor(rtb_Merge_g + 0.5F);
    } else {
      rtb_MultiportSwitch2_e = 0.0F;
    }

    if ((float32)fabs(rtb_Add_ax) >= 0.5F) {
      rtb_DataTypeConversion23 = (float32)floor(rtb_Add_ax + 0.5F);
    } else {
      rtb_DataTypeConversion23 = 0.0F;
    }

    ME11_ARID_DEF.Oncal_PsErrOfEvaDVT2CoolMixOnOffcal_PsErrOfEvaDVT2CoolMixOff_Mode
      = ((rtb_DataTypeConversion_dt >= (sint16)rtb_MultiportSwitch2_e) ||
         ((rtb_DataTypeConversion_dt > (sint16)rtb_DataTypeConversion23) &&
          ME11_ARID_DEF.Oncal_PsErrOfEvaDVT2CoolMixOnOffcal_PsErrOfEvaDVT2CoolMixOff_Mode));
    rtb_MultiportSwitch2_e = (float32)floor((ACCtl_tPsDVT -
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C) * 2.0F);
    if (rtb_MultiportSwitch2_e < 32768.0F) {
      if (rtb_MultiportSwitch2_e >= -32768.0F) {
        rtb_DataTypeConversion_dt = (sint16)rtb_MultiportSwitch2_e;
      } else {
        rtb_DataTypeConversion_dt = MIN_int16_T;
      }
    } else {
      rtb_DataTypeConversion_dt = MAX_int16_T;
    }

    rtb_Merge_g = cal_PsErrOfPtcDVT2HeatMixOn * 2.0F;
    rtb_Add_ax = cal_PsErrOfPtcDVT2HeatMixOff * 2.0F;
    if ((float32)fabs(rtb_Merge_g) >= 0.5F) {
      rtb_MultiportSwitch2_e = (float32)floor(rtb_Merge_g + 0.5F);
    } else {
      rtb_MultiportSwitch2_e = 0.0F;
    }

    if ((float32)fabs(rtb_Add_ax) >= 0.5F) {
      rtb_DataTypeConversion23 = (float32)floor(rtb_Add_ax + 0.5F);
    } else {
      rtb_DataTypeConversion23 = 0.0F;
    }

    ME11_ARID_DEF.Oncal_PsErrOfPtcDVT2HeatMixOnOffcal_PsErrOfPtcDVT2HeatMixOff_Mode
      = ((rtb_DataTypeConversion_dt >= (sint16)rtb_MultiportSwitch2_e) ||
         ((rtb_DataTypeConversion_dt > (sint16)rtb_DataTypeConversion23) &&
          ME11_ARID_DEF.Oncal_PsErrOfPtcDVT2HeatMixOnOffcal_PsErrOfPtcDVT2HeatMixOff_Mode));
    if (ME11_ARID_DEF.Oncal_PsErrOfEvaDVT2CoolMixOnOffcal_PsErrOfEvaDVT2CoolMixOff_Mode)
    {
      ACCtl_rPsBasicMixDoor = 0U;
    } else if
        (ME11_ARID_DEF.Oncal_PsErrOfPtcDVT2HeatMixOnOffcal_PsErrOfPtcDVT2HeatMixOff_Mode)
    {
      ACCtl_rPsBasicMixDoor = 100U;
    } else {
      rtb_Divide1_f = (uint32)(ACCtl_PsfacPtc2NominalTemp *
        ACCtl_rPsBlowerModeSet * 256.0F);
      if (rtb_Divide1_f > 25600U) {
        ACCtl_rPsBasicMixDoor = 100U;
      } else {
        ACCtl_rPsBasicMixDoor = (uint8)((uint32)((rtb_Divide1_f & 128U) != 0U) +
          (rtb_Divide1_f >> 8));
      }
    }

    if (cal_FixPIDSecletFlag) {
      ME11_PI_Controller1(!rtb_LogicalOperator5, (float32)ACCtl_rPsBasicMixDoor,
                          &rtb_PI_Cor_a, &rtb_IFreezFlag_jz);
      rtb_LogicalOperator_j0 = (ACCtl_tPsDVT >= ACCtl_tLeftDuct);
      rtb_PI_Cor_d = ACCtl_tPsDVT - ACCtl_tLeftDuct;
      ME11_deadzone_h(rtb_PI_Cor_d, 0.5, &rtb_flag_f);
      if (rtb_flag_f) {
        rtb_PI_Cor_d = 0.0F;
      } else if (!rtb_LogicalOperator_j0) {
        rtb_PI_Cor_d = ACCtl_tLeftDuct - ACCtl_tPsDVT;
      }

      ME11_P_NEG_p(!rtb_LogicalOperator_j0, rtb_PI_Cor_d,
                   cal_PsMixDesValPID_pWinNeg, cal_PsMixDesValPID_KpNeg,
                   cal_PsMixDesValPID_Kp, (float32 *)&ACCtl_rPsSetMixDoorPCor);
      ME11_P_POS_l(rtb_LogicalOperator_j0, rtb_PI_Cor_d,
                   cal_PsMixDesValPID_pWinPos, cal_PsMixDesValPID_KpPos,
                   cal_PsMixDesValPID_Kp, (float32 *)&ACCtl_rPsSetMixDoorPCor);
      ME11_P_NEG(!rtb_LogicalOperator_j0, rtb_PI_Cor_d,
                 cal_PsMixDesValPIDIntegDeadBand, cal_PsMixDesValPID_KiNeg,
                 cal_PsMixDesValPID_Ki, (float32 *)&ACCtl_rPsSetMixDoorICor);
      ME11_P_POS(rtb_LogicalOperator_j0, rtb_PI_Cor_d,
                 cal_PsMixDesValPIDIntegDeadBand, cal_PsMixDesValPID_KiPos,
                 cal_PsMixDesValPID_Ki, (float32 *)&ACCtl_rPsSetMixDoorICor);
      if (rtb_LogicalOperator5) {
        switch (ME11_ARID_DEF.Delay_DSTATE_nz) {
         case 0:
          if (rtb_LogicalOperator_j0) {
            ACCtl_rPsSetMixDoorISum = ACCtl_rPsSetMixDoorISum +
              ACCtl_rPsSetMixDoorICor;
          } else {
            ACCtl_rPsSetMixDoorISum = ACCtl_rPsSetMixDoorISum -
              ACCtl_rPsSetMixDoorICor;
          }
          break;

         case 1:
          if (!rtb_LogicalOperator_j0) {
            ACCtl_rPsSetMixDoorISum = ACCtl_rPsSetMixDoorISum -
              ACCtl_rPsSetMixDoorICor;
          }
          break;

         case 2:
          if (rtb_LogicalOperator_j0) {
            ACCtl_rPsSetMixDoorISum = ACCtl_rPsSetMixDoorISum +
              ACCtl_rPsSetMixDoorICor;
          }
          break;

         case 3:
          break;
        }

        if ((ACCtl_rPsSetMixDoorISum - 8000.0F) + 8000.0F >
            cal_PsMixDesValPID_IsumMax) {
          ACCtl_rPsSetMixDoorISum = cal_PsMixDesValPID_IsumMax;
        } else if ((ACCtl_rPsSetMixDoorISum - 8000.0F) + 8000.0F <
                   cal_PsMixDesValPID_IsumMin) {
          ACCtl_rPsSetMixDoorISum = cal_PsMixDesValPID_IsumMin;
        } else {
          ACCtl_rPsSetMixDoorISum = (ACCtl_rPsSetMixDoorISum - 8000.0F) +
            8000.0F;
        }
      } else {
        ACCtl_rPsSetMixDoorISum = 0.0F;
      }

      ME11_PI_Controller(rtb_LogicalOperator5, rtb_LogicalOperator_j0, (float32)
                         ACCtl_rPsBasicMixDoor, ACCtl_rPsSetMixDoorPCor,
                         ACCtl_rPsSetMixDoorISum, (float32)cal_PsMixDesValPIDUL,
                         (float32)cal_PsMixDesValPIDLL, &rtb_PI_Cor_a,
                         &rtb_IFreezFlag_jz);
      ACCtl_rPsMixDoorDes = (uint8)rtb_PI_Cor_a;
      ME11_ARID_DEF.Delay_DSTATE_nz = rtb_IFreezFlag_jz;
    }
  }

  if ((rtb_DataTypeConversion_f == ACEconMode_FanOnly) &&
      (ME11_ARID_DEF.Switch1_nv != ACOff) && (ME11_ARID_DEF.Switch1_nv !=
       ACDefog)) {
    ThCo_rSetRightMixDoor = 0.0F;
    ThCo_rSetLeftMixDoor = 0.0F;
  } else if ((ME11_ARID_DEF.Delay_DSTATE_lv == 2) && (ME11_ARID_DEF.Switch1_nv ==
              ACOff)) {
    ThCo_rSetRightMixDoor = 100.0F;
    ThCo_rSetLeftMixDoor = 100.0F;
  } else {
    ThCo_rSetRightMixDoor = (float32)ACCtl_rPsMixDoorDes;
    ThCo_rSetLeftMixDoor = (float32)ACCtl_rDrMixDoorDes;
  }

  rtb_LogicalOperator_j0 = (ME11_ARID_DEF.Switch1_nv == ACOff);
  rtb_OR_i4 = (ACCtl_BlowerMode == BlowerModes_DeforstMode);
  rtb_Compare_fe4 = (HMICtl_sLeftSetPoint < 16.5F);
  rtb_LogicalOperator1_f = (HMICtl_sLeftSetPoint > 31.5F);
  rtb_LogicalOperator5 = (AC_FanLevelAct == 5);
  rtb_Compare_gzu = (rtb_DataTypeConversion_f == ACEconMode_FanOnly);
  if (ME11_ARID_DEF.is_active_c57_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c57_ME11 = 1U;
    if (rtb_OR_i4 && rtb_LogicalOperator1_f && rtb_Compare_fe4 &&
        rtb_LogicalOperator5 && rtb_Compare_gzu && ACCtl_stRecOut) {
      ME11_ARID_DEF.is_c57_ME11 = ME11_IN_Exhaust_Check;
      ME11_ARID_DEF.ExhaustTime = 0U;
      ME11_ARID_DEF.is_Exhaust_Check = ME11_IN_Exhaust_intl;
      AC_stExhaust = false;
    } else {
      ME11_ARID_DEF.is_c57_ME11 = ME11_IN_Exhaust_OFF;
      AC_stExhaust = false;
    }
  } else if (ME11_ARID_DEF.is_c57_ME11 == ME11_IN_Exhaust_Check) {
    if ((!AC_stIGNON) || (ME11_ARID_DEF.ExhaustTime >= 15000)) {
      ME11_ARID_DEF.is_Exhaust_Check = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_c57_ME11 = ME11_IN_Exhaust_OFF;
      AC_stExhaust = false;
    } else if (ME11_ARID_DEF.is_Exhaust_Check == ME11_IN_Exhaust_ON) {
      AC_stExhaust = true;
      if (!rtb_LogicalOperator_j0) {
        ME11_ARID_DEF.is_Exhaust_Check = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_c57_ME11 = ME11_IN_Exhaust_OFF;
        AC_stExhaust = false;
      } else {
        b_previousEvent = ME11_ARID_DEF.ExhaustTime + 1;
        if (ME11_ARID_DEF.ExhaustTime + 1 > 65535) {
          b_previousEvent = 65535;
        }

        ME11_ARID_DEF.ExhaustTime = (uint16)b_previousEvent;
      }
    } else {
      AC_stExhaust = false;
      if (rtb_LogicalOperator_j0) {
        ME11_ARID_DEF.is_Exhaust_Check = ME11_IN_Exhaust_ON;
        AC_stExhaust = true;
      } else if ((!rtb_OR_i4) || (!rtb_LogicalOperator1_f) || (!rtb_Compare_fe4)
                 || (!rtb_LogicalOperator5) || (!rtb_Compare_gzu) ||
                 (!ACCtl_stRecOut)) {
        ME11_ARID_DEF.is_Exhaust_Check = ME11_IN_NO_ACTIVE_CHILD_gl;
        ME11_ARID_DEF.is_c57_ME11 = ME11_IN_Exhaust_OFF;
        AC_stExhaust = false;
      }
    }
  } else {
    AC_stExhaust = false;
    if (rtb_OR_i4 && rtb_LogicalOperator1_f && rtb_Compare_fe4 &&
        rtb_LogicalOperator5 && rtb_Compare_gzu && ACCtl_stRecOut) {
      ME11_ARID_DEF.is_c57_ME11 = ME11_IN_Exhaust_Check;
      ME11_ARID_DEF.ExhaustTime = 0U;
      ME11_ARID_DEF.is_Exhaust_Check = ME11_IN_Exhaust_intl;
      AC_stExhaust = false;
    }
  }

  ME11_ARID_DEF.GLB_TMSFaultCOMP[0] = ME11_ARID_DEF.Sts_h;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[1] = rtb_Compare_mos;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[2] = ME11_ARID_DEF.Sts_b;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[3] = rtb_Compare_fhh;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[4] = ME11_ARID_DEF.Sts_a;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[5] = ME11_ARID_DEF.Sts_e;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[6] = rtb_Compare_lfo;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[7] = rtb_Compare_kq;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[8] = rtb_Compare_e5;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[9] = ME11_ARID_DEF.Sts_d3;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[10] = ME11_ARID_DEF.Sts_d;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[11] = rtb_Compare_cj1;
  SEN_ACCMTHiRaw = look1_iflf_binlca(rtb_Add_cy, (const float32 *)
    &cal_TACCMOutRaw_1X[0], (const float32 *)&cal_TACCMOutRaw_CUR[0], 29U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nc != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_mb = SEN_ACCMTHiRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_mb = SEN_ACCMTHiRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_mb * 0.100000024F;
  if (cal_ACCMHiTempDataEnb) {
    ACSen_sACCMHiTempFilter = cal_ACCMHiTempData;
  } else {
    ACSen_sACCMHiTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_mb;
  }

  ME11_ARID_DEF.Relay_Mode_p = ((ACSen_sACCMHiTempFilter >= cal_COMPExhTLmtVal) ||
    ((ACSen_sACCMHiTempFilter > cal_COMPExhTNmlVal) &&
     ME11_ARID_DEF.Relay_Mode_p));
  ME11_ARID_DEF.Relay1_Mode_e = ((ACSen_sACCMHiTempFilter >= cal_COMPExhTFrbVal)
    || ((ACSen_sACCMHiTempFilter > cal_COMPExhTLmtRlybVal) &&
        ME11_ARID_DEF.Relay1_Mode_e));
  if (ME11_ARID_DEF.is_active_c87_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c87_ME11 = 1U;
    ME11_ARID_DEF.is_c87_ME11 = ME11_IN_Default_k;
    ACTCtl_eCOMPExhTPrtSts = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c87_ME11) {
     case ME11_IN_Default_k:
      ACTCtl_eCOMPExhTPrtSts = 0U;
      if (ME11_ARID_DEF.Relay_Mode_p) {
        ME11_ARID_DEF.is_c87_ME11 = ME11_IN_limit;
        ACTCtl_eCOMPExhTPrtSts = 1U;
      }
      break;

     case ME11_IN_forbit:
      ACTCtl_eCOMPExhTPrtSts = 2U;
      if (!ME11_ARID_DEF.Relay1_Mode_e) {
        ME11_ARID_DEF.is_c87_ME11 = ME11_IN_limit;
        ACTCtl_eCOMPExhTPrtSts = 1U;
      }
      break;

     default:
      ACTCtl_eCOMPExhTPrtSts = 1U;
      if (ME11_ARID_DEF.Relay1_Mode_e) {
        ME11_ARID_DEF.is_c87_ME11 = ME11_IN_forbit;
        ACTCtl_eCOMPExhTPrtSts = 2U;
      } else if (!ME11_ARID_DEF.Relay_Mode_p) {
        ME11_ARID_DEF.is_c87_ME11 = ME11_IN_Default_k;
        ACTCtl_eCOMPExhTPrtSts = 0U;
      }
      break;
    }
  }

  ME11_ARID_DEF.GLB_TMSFaultCOMP[12] = (ACTCtl_eCOMPExhTPrtSts == 2);
  ME11_ARID_DEF.Relay2_Mode_d = ((ACSen_sHiPressFilter >= cal_NmlCOMPHPrsP6) ||
    ((ACSen_sHiPressFilter > cal_NmlCOMPHPrsP5) && ME11_ARID_DEF.Relay2_Mode_d));
  ME11_ARID_DEF.Relay_Mode_dd = ((ACSen_sHiPressFilter >= cal_NmlCOMPHPrsP4) ||
    ((ACSen_sHiPressFilter > cal_NmlCOMPHPrsP3) && ME11_ARID_DEF.Relay_Mode_dd));
  ME11_ARID_DEF.Relay1_Mode_hl = ((ACSen_sHiPressFilter >= cal_NmlCOMPHPrsP2) ||
    ((ACSen_sHiPressFilter > cal_NmlCOMPHPrsP1) && ME11_ARID_DEF.Relay1_Mode_hl));
  ME11_ARID_DEF.Relay3_Mode = ((ACSen_sHiPressFilter >= cal_NmlCOMPHPrsP8) ||
    ((ACSen_sHiPressFilter > cal_NmlCOMPHPrsP7) && ME11_ARID_DEF.Relay3_Mode));
  rtb_Compare_mos = ((rtb_Switch2_ht == 1) || (rtb_Switch2_ht == 2) ||
                     (rtb_Switch2_ht == 3));
  ME11_ARID_DEF.Relay14_Mode = ((ACSen_sHiPressFilter >= cal_HeatPumpCOMPHPrsP6)
    || ((ACSen_sHiPressFilter > cal_HeatPumpCOMPHPrsP5) &&
        ME11_ARID_DEF.Relay14_Mode));
  ME11_ARID_DEF.Relay12_Mode = ((ACSen_sHiPressFilter >= cal_HeatPumpCOMPHPrsP4)
    || ((ACSen_sHiPressFilter > cal_HeatPumpCOMPHPrsP3) &&
        ME11_ARID_DEF.Relay12_Mode));
  ME11_ARID_DEF.Relay13_Mode = ((ACSen_sHiPressFilter >= cal_HeatPumpCOMPHPrsP2)
    || ((ACSen_sHiPressFilter > cal_HeatPumpCOMPHPrsP1) &&
        ME11_ARID_DEF.Relay13_Mode));
  ME11_ARID_DEF.Relay15_Mode = ((ACSen_sHiPressFilter >= cal_HeatPumpCOMPHPrsP8)
    || ((ACSen_sHiPressFilter > cal_HeatPumpCOMPHPrsP7) &&
        ME11_ARID_DEF.Relay15_Mode));
  if (rtb_Compare_mos) {
    ACTCtl_bCOMPHPLmtFlg = (ME11_ARID_DEF.Relay2_Mode_d ||
      (!ME11_ARID_DEF.Relay_Mode_dd));
    ACTCtl_bCOMPHPFrbFlg = ((!ME11_ARID_DEF.Relay1_Mode_hl) ||
      ME11_ARID_DEF.Relay3_Mode);
    rtb_PI_Cor_a = cal_NmlCOMPHPrsDownSpd;
  } else {
    ACTCtl_bCOMPHPLmtFlg = (ME11_ARID_DEF.Relay14_Mode ||
      (!ME11_ARID_DEF.Relay12_Mode));
    ACTCtl_bCOMPHPFrbFlg = ((!ME11_ARID_DEF.Relay13_Mode) ||
      ME11_ARID_DEF.Relay15_Mode);
    rtb_PI_Cor_a = cal_HeatPumpCOMPHPrsDownSpd;
  }

  if (ME11_ARID_DEF.is_active_c85_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c85_ME11 = 1U;
    ME11_ARID_DEF.is_c85_ME11 = ME11_IN_Default_k;
    rtb_IFreezFlag_bd = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c85_ME11) {
     case ME11_IN_Default_k:
      rtb_IFreezFlag_bd = 0U;
      if (ACTCtl_bCOMPHPLmtFlg) {
        ME11_ARID_DEF.is_c85_ME11 = ME11_IN_Lmt;
        rtb_IFreezFlag_bd = 1U;
        ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_g = rtb_PI_Cor_a;
      }
      break;

     case ME11_IN_Forbit:
      rtb_IFreezFlag_bd = 2U;
      if (!ACTCtl_bCOMPHPFrbFlg) {
        ME11_ARID_DEF.is_c85_ME11 = ME11_IN_Lmt;
        rtb_IFreezFlag_bd = 1U;
        ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_g = rtb_PI_Cor_a;
      }
      break;

     default:
      rtb_IFreezFlag_bd = 1U;
      if (!ACTCtl_bCOMPHPLmtFlg) {
        ME11_ARID_DEF.is_c85_ME11 = ME11_IN_Default_k;
        rtb_IFreezFlag_bd = 0U;
      } else if (ACTCtl_bCOMPHPFrbFlg) {
        ME11_ARID_DEF.is_c85_ME11 = ME11_IN_Forbit;
        rtb_IFreezFlag_bd = 2U;
      }
      break;
    }
  }

  rtb_Compare_cj1 = (COMP_EcompActSpd > 800.0F);
  if (ME11_ARID_DEF.is_active_c4_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c4_ME11 = 1U;
    ME11_ARID_DEF.is_c4_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.ACTCtl_bLowPrsProFlg = true;
    ME11_ARID_DEF.Counter = 0.0F;
  } else {
    switch (ME11_ARID_DEF.is_c4_ME11) {
     case ME11_IN_Init_i:
      ME11_ARID_DEF.ACTCtl_bLowPrsProFlg = true;
      if (rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c4_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.Counter++;
      }
      break;

     case ME11_IN_protect:
      ME11_ARID_DEF.ACTCtl_bLowPrsProFlg = false;
      if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c4_ME11 = ME11_IN_Init_i;
        ME11_ARID_DEF.ACTCtl_bLowPrsProFlg = true;
        ME11_ARID_DEF.Counter = 0.0F;
      }
      break;

     default:
      if (ME11_ARID_DEF.Counter > (float32)(cal_StartPrsProTimes * 600.0)) {
        ME11_ARID_DEF.is_c4_ME11 = ME11_IN_protect;
        ME11_ARID_DEF.ACTCtl_bLowPrsProFlg = false;
        ME11_ARID_DEF.Counter = 0.0F;
      } else if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c4_ME11 = ME11_IN_Init_i;
        ME11_ARID_DEF.ACTCtl_bLowPrsProFlg = true;
        ME11_ARID_DEF.Counter = 0.0F;
      } else {
        ME11_ARID_DEF.Counter++;
      }
      break;
    }
  }

  ME11_ARID_DEF.Relay10_Mode = ((ACSen_sLoPressFilter >= cal_NmlCOMPLPrsP6) ||
    ((ACSen_sLoPressFilter > cal_NmlCOMPLPrsP5) && ME11_ARID_DEF.Relay10_Mode));
  ME11_ARID_DEF.Relay8_Mode = ((ACSen_sLoPressFilter >= cal_NmlCOMPLPrsP4) ||
    ((ACSen_sLoPressFilter > cal_NmlCOMPLPrsP3) && ME11_ARID_DEF.Relay8_Mode));
  ME11_ARID_DEF.Relay9_Mode = ((ACSen_sLoPressFilter >= cal_NmlCOMPLPrsP2) ||
    ((ACSen_sLoPressFilter > cal_NmlCOMPLPrsP1) && ME11_ARID_DEF.Relay9_Mode));
  ME11_ARID_DEF.Relay11_Mode = ((ACSen_sLoPressFilter >= cal_NmlCOMPLPrsP8) ||
    ((ACSen_sLoPressFilter > cal_NmlCOMPLPrsP7) && ME11_ARID_DEF.Relay11_Mode));
  ME11_ARID_DEF.Relay6_Mode = ((ACSen_sLoPressFilter >= cal_HeatPumpCOMPLPrsP6) ||
    ((ACSen_sLoPressFilter > cal_HeatPumpCOMPLPrsP5) &&
     ME11_ARID_DEF.Relay6_Mode));
  ME11_ARID_DEF.Relay4_Mode = ((ACSen_sLoPressFilter >= cal_HeatPumpCOMPLPrsP4) ||
    ((ACSen_sLoPressFilter > cal_HeatPumpCOMPLPrsP3) &&
     ME11_ARID_DEF.Relay4_Mode));
  ME11_ARID_DEF.Relay5_Mode = ((ACSen_sLoPressFilter >= cal_HeatPumpCOMPLPrsP2) ||
    ((ACSen_sLoPressFilter > cal_HeatPumpCOMPLPrsP1) &&
     ME11_ARID_DEF.Relay5_Mode));
  ME11_ARID_DEF.Relay7_Mode = ((ACSen_sLoPressFilter >= cal_HeatPumpCOMPLPrsP8) ||
    ((ACSen_sLoPressFilter > cal_HeatPumpCOMPLPrsP7) &&
     ME11_ARID_DEF.Relay7_Mode));
  if (ME11_ARID_DEF.ACTCtl_bLowPrsProFlg) {
    ACTCtl_bCOMPLPLmtFlg = false;
    ACTCtl_bCOMPLPFrbFlg = false;
  } else if (rtb_Compare_mos) {
    ACTCtl_bCOMPLPLmtFlg = (ME11_ARID_DEF.Relay10_Mode ||
      (!ME11_ARID_DEF.Relay8_Mode));
    ACTCtl_bCOMPLPFrbFlg = ((!ME11_ARID_DEF.Relay9_Mode) ||
      ME11_ARID_DEF.Relay11_Mode);
  } else {
    ACTCtl_bCOMPLPLmtFlg = (ME11_ARID_DEF.Relay6_Mode ||
      (!ME11_ARID_DEF.Relay4_Mode));
    ACTCtl_bCOMPLPFrbFlg = ((!ME11_ARID_DEF.Relay5_Mode) ||
      ME11_ARID_DEF.Relay7_Mode);
  }

  if (rtb_Compare_mos) {
    rtb_PI_Cor_a = cal_NmlCOMPLPrsDownSpd;
  } else {
    rtb_PI_Cor_a = cal_HeatPumpCOMPLPrsDownSpd;
  }

  if (ME11_ARID_DEF.is_active_c86_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c86_ME11 = 1U;
    ME11_ARID_DEF.is_c86_ME11 = ME11_IN_Default_k;
    rtb_IFreezFlag_jz = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c86_ME11) {
     case ME11_IN_Default_k:
      rtb_IFreezFlag_jz = 0U;
      if (ACTCtl_bCOMPLPLmtFlg) {
        ME11_ARID_DEF.is_c86_ME11 = ME11_IN_Lmt;
        rtb_IFreezFlag_jz = 1U;
        ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_m = rtb_PI_Cor_a;
      }
      break;

     case ME11_IN_Forbit:
      rtb_IFreezFlag_jz = 2U;
      if (!ACTCtl_bCOMPLPFrbFlg) {
        ME11_ARID_DEF.is_c86_ME11 = ME11_IN_Lmt;
        rtb_IFreezFlag_jz = 1U;
        ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_m = rtb_PI_Cor_a;
      }
      break;

     default:
      rtb_IFreezFlag_jz = 1U;
      if (!ACTCtl_bCOMPLPLmtFlg) {
        ME11_ARID_DEF.is_c86_ME11 = ME11_IN_Default_k;
        rtb_IFreezFlag_jz = 0U;
      } else if (ACTCtl_bCOMPLPFrbFlg) {
        ME11_ARID_DEF.is_c86_ME11 = ME11_IN_Forbit;
        rtb_IFreezFlag_jz = 2U;
      }
      break;
    }
  }

  ACTCtl_eCOMPPrsPrtSts = (uint8)(((((uint32)(((rtb_IFreezFlag_bd == 2) ||
    (rtb_IFreezFlag_jz == 2)) << 4) + (uint32)(((rtb_IFreezFlag_bd == 1) &&
    (rtb_IFreezFlag_jz == 1)) << 3)) + (uint32)(((rtb_IFreezFlag_jz == 1) &&
    (rtb_IFreezFlag_bd == 0)) << 2)) + (uint32)(((rtb_IFreezFlag_jz == 0) &&
    (rtb_IFreezFlag_bd == 1)) << 1)) + (uint32)((rtb_IFreezFlag_jz == 0) &&
    (rtb_IFreezFlag_bd == 0)));
  ME11_ARID_DEF.GLB_TMSFaultCOMP[13] = (ACTCtl_eCOMPPrsPrtSts >= 4);
  ME11_ARID_DEF.GLB_TMSFaultCOMP[14] = ME11_ARID_DEF.Delay2_DSTATE_lz;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[15] = rtb_Compare_cd_tmp;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[16] = ACTCtl_bOCOLmtFlg;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[17] = ACTCtl_bPressProtectFlg;
  ME11_ARID_DEF.GLB_TMSFaultCOMP[18] = ACTCtl_bPressRateFlg;
  rtb_Compare_mos = ((rtb_DataTypeConversion1_on >= 1) &&
                     (rtb_DataTypeConversion1_on <= 4));
  if (ME11_ARID_DEF.temporalCounter_i1_bc < 31U) {
    ME11_ARID_DEF.temporalCounter_i1_bc++;
  }

  if (ME11_ARID_DEF.is_active_c26_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c26_ME11 = 1U;
    ME11_ARID_DEF.is_c26_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a = false;
  } else {
    switch (ME11_ARID_DEF.is_c26_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a = false;
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c26_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_bc = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a = true;
      if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c26_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_bc >= 30U) {
        ME11_ARID_DEF.is_c26_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a = true;
      } else if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c26_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a = false;
      }
      break;
    }
  }

  if (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
       (ME11_ARID_DEF.DataTypeConversion1 == 4)) && ((rtb_Switch2_ht == 5) ||
       (rtb_Switch2_ht == 6))) {
    rtb_Switch_n2 = false;
  } else if (cal_BatHeatACCMEnb) {
    rtb_Switch_n2 = ((rtb_Switch2_ht == 10) ||
                     ((((ME11_ARID_DEF.DataTypeConversion1 == 2) ||
                        (ME11_ARID_DEF.DataTypeConversion1 == 5)) &&
                       (rtb_DataTypeConversion1_l == 6)) ||
                      (rtb_DataTypeConversion1_l == 1)) ||
                     (ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a && rtb_Compare_mos));
  } else {
    rtb_Switch_n2 = ((rtb_Switch2_ht == 10) || (rtb_DataTypeConversion1_l == 1) ||
                     (ME11_ARID_DEF.ACTCtl_eACCMCtlEnb_a && rtb_Compare_mos));
  }

  for (b_previousEvent = 0; b_previousEvent < 5; b_previousEvent++) {
    rtb_Compare_btd[b_previousEvent] = (rtb_Switch2_ht ==
      ME11_ConstP.pooled85[b_previousEvent]);
  }

  if (SOMCtl_bExtDefFlg) {
    rtb_DataTypeConversion23 = (PWRCtl_VCUACCMLimitPwr -
      (Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
      ->VIPM_HVCHPwr_kW) - cal_PwrOffsetVal;
  } else {
    rtb_DataTypeConversion23 = PWRCtl_VCUACCMLimitPwr - cal_PwrOffsetVal;
  }

  if (rtb_DataTypeConversion23 <= cal_COMPPwrMaxLmt) {
    PWRCtl_sLmtPwrCOMP = rtb_DataTypeConversion23;
  } else {
    PWRCtl_sLmtPwrCOMP = cal_COMPPwrMaxLmt;
  }

  ME11_ARID_DEF.Relay_Mode_l = ((PWRCtl_sLmtPwrCOMP >= cal_COMPStartPwrMinLmt) ||
    ((PWRCtl_sLmtPwrCOMP > cal_COMPClosePwrMaxLmt) && ME11_ARID_DEF.Relay_Mode_l));
  ACTCtl_bHPEXVInitFinishFlg = (ACTCtl_bHPEXVInitReq < 1);
  ACTCtl_bAEXVInitFinishFlg = (ACTCtl_bAEXVInitReq < 1);
  ACTCtl_bBEXVInitFinishFlg = (ACTCtl_bBEXVInitReq < 1);
  ACTCtl_eCOMPJudgeFlg = (uint8)((((((((uint32)(((((rtb_DataTypeConversion1_on
    != 1) && (rtb_DataTypeConversion1_on != 2) && (rtb_DataTypeConversion1_on !=
    3) && (rtb_DataTypeConversion1_on != 4)) || (!ACTCtl_bAcPMPSpdFlt)) &&
    ((!ACTCtl_bBatPMPSpdFlt) || ((rtb_DataTypeConversion1_l != 1) &&
    (rtb_DataTypeConversion1_l != 6)))) << 3) + (uint32)
    (!ME11_ARID_DEF.ACTCtl_bCOMPForbidFlg_p << 1)) + rtb_Switch_n2) + (uint32)
    (!ACTCtl_bCOMPStopFlg << 4)) + (uint32)((((!rtb_Compare_btd[0]) &&
    (!rtb_Compare_btd[1]) && (!rtb_Compare_btd[2]) && (!rtb_Compare_btd[3]) && (
    !rtb_Compare_btd[4])) || ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC) << 5)) +
    (uint32)(ME11_ARID_DEF.Relay_Mode_l << 6)) + (uint32)
    ((ACTCtl_bHPEXVInitFinishFlg && ACTCtl_bAEXVInitFinishFlg &&
      ACTCtl_bBEXVInitFinishFlg) << 7)) + 4U);
  rtb_Compare_mos = (ACTCtl_eCOMPJudgeFlg == 255);
  if (ME11_ARID_DEF.temporalCounter_i1_ep < 15U) {
    ME11_ARID_DEF.temporalCounter_i1_ep++;
  }

  if (ME11_ARID_DEF.is_active_c44_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c44_ME11 = 1U;
    ME11_ARID_DEF.is_c44_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.ACTCtl_eACCMCtlEnb = false;
  } else {
    switch (ME11_ARID_DEF.is_c44_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.ACTCtl_eACCMCtlEnb = false;
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c44_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_ep = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.ACTCtl_eACCMCtlEnb = true;
      if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c44_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.ACTCtl_eACCMCtlEnb = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_ep >= 10U) {
        ME11_ARID_DEF.is_c44_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.ACTCtl_eACCMCtlEnb = true;
      } else if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c44_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.ACTCtl_eACCMCtlEnb = false;
      }
      break;
    }
  }

  if (cal_ACCMEnbDataEnb) {
    ACTCtl_bACCMCtlEnb = cal_ACCMEnbData;
  } else if (ME11_ARID_DEF.Delay2_DSTATE_lz) {
    ACTCtl_bACCMCtlEnb = false;
  } else {
    ACTCtl_bACCMCtlEnb = (((COMP_EcompActSpd >= cal_COMPClsLowSpeed) &&
      (!ME11_ARID_DEF.ACTCtl_eACCMCtlEnb)) || ME11_ARID_DEF.ACTCtl_eACCMCtlEnb);
  }

  rtb_Merge1_m = (ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn - ACSen_sEvapSurTemp) *
    cal_ACCMCtrlACct * (float32)ACCtl_BloweFanSpeed;
  ACTCtl_sCOMPCtrlAClsFF = look2_iflf_binlca(ACSen_sEnvTempCor, rtb_Merge1_m, (
    const float32 *)&cal_ACCMCtrlA2FF_2X[0], (const float32 *)
    &cal_ACCMCtrlA2FF_2Y[0], (const float32 *)&cal_ACCMCtrlA2FF_MAP[0],
    ME11_ConstP.cal_ACCMCtrlA2FF_MAP_maxIndex, 6U);
  if (cal_BatHeatACCMEnb) {
    if (rtb_Switch2_ht == 6) {
      if (ACCtl_tSetPointPTC >= SOMCtl_sBatTrgTemp) {
        ACTCtl_sCOMPSetPoint = ACCtl_tSetPointPTC;
        ACTCtl_sCOMPActure =
          (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
          ->VIPM_HVCHOutlTemp_C;
      } else {
        ACTCtl_sCOMPSetPoint = SOMCtl_sBatTrgTemp;
        ACTCtl_sCOMPActure = BMS_InletCooltActlTemp;
      }
    } else if (rtb_Switch2_ht == 5) {
      ACTCtl_sCOMPSetPoint = SOMCtl_sBatTrgTemp;
      ACTCtl_sCOMPActure = BMS_InletCooltActlTemp;
    } else {
      ACTCtl_sCOMPSetPoint = ACCtl_tSetPointPTC;
      ACTCtl_sCOMPActure =
        (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
        ->VIPM_HVCHOutlTemp_C;
    }
  } else if (((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
              (ME11_ARID_DEF.DataTypeConversion1 == 4)) && ((rtb_Switch2_ht == 5)
              || (rtb_Switch2_ht == 6))) {
    ACTCtl_sCOMPSetPoint = 0.0F;
    ACTCtl_sCOMPActure = 0.0F;
  } else {
    ACTCtl_sCOMPSetPoint = ACCtl_tSetPointPTC;
    ACTCtl_sCOMPActure =
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C;
  }

  ACTCtl_tCtrlADiff = ACTCtl_sCOMPSetPoint - ACTCtl_sCOMPActure;
  ME11_Descending_filter(rtb_Switch2_ht == 2, BMS_InletCooltActlTemp,
    cal_BatCoolInletTrgTemp, cal_BatCoolTrgFilter, COMP_EcompActSpd,
    &ME11_ARID_DEF.Init_la, &ME11_ARID_DEF.ARID_DEF_Descending_filter_ny);
  ACTCtl_tCtrlBDiff = BMS_InletCooltActlTemp - ME11_ARID_DEF.Init_la;
  ACTCtl_tCtrlCDiff = ACSen_sEvapSurTemp - ACCtl_tSetPointEvap;
  ME11_Descending_filter(rtb_Switch2_ht == 14, BMS_InletCooltActlTemp,
    cal_ACCMCtrlETrgTemp, cal_BatCoolTrgFilter, COMP_EcompActSpd,
    &ME11_ARID_DEF.Init_l, &ME11_ARID_DEF.ARID_DEF_Descending_filter_o);
  rtb_PI_Cor_d = ACCtl_tSetPointPTC -
    (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
    ->VIPM_HVCHOutlTemp_C;
  ACTCtl_sDCoolBatTempDiff = BMS_InletCooltActlTemp - cal_BatCoolInletTrgTemp;
  ACTCtl_sDCoolCabinTempDiff = ACTCtl_tCtrlCDiff;
  switch (rtb_Switch2_ht) {
   case 4:
   case 5:
   case 6:
   case 13:
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlA1FF_1X[0], (const float32 *)&cal_ACCMCtrlA1FF_CUR[0], 5U);
    rtb_PI_Cor_a = cal_ACCMCtrlADlyTime;
    rtb_Add_ax = cal_ACCMCtrlARunTime;
    rtb_Merge1_m = ACTCtl_sCOMPCtrlAClsFF;
    rtb_Merge = cal_ACCMCtrlADeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(ACTCtl_tCtrlADiff, (const float32 *)
      &cal_ACCMCtrlAKp_1X[0], (const float32 *)&cal_ACCMCtrlAKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(ACTCtl_tCtrlADiff, (const float32 *)
      &cal_ACCMCtrlAKi_1X[0], (const float32 *)&cal_ACCMCtrlAKi_CUR[0], 7U);
    rtb_Merge1 = cal_ACCMCtrlAPIMax;
    rtb_Add_cy = cal_ACCMCtrlAPIMin;
    break;

   case 2:
    rtb_Merge_g = look1_iflf_binlca(BMS_HVBatCellTempMin, (const float32 *)
      &cal_ACCMCtrlBFF_1X[0], (const float32 *)&cal_ACCMCtrlBFF_CUR[0], 5U);
    rtb_PI_Cor_a = cal_ACCMCtrlBDlyTime;
    rtb_Add_ax = cal_ACCMCtrlBRunTime;
    rtb_Merge1_m = rtb_Merge_g;
    ACTCtl_sCOMPSetPoint = BMS_InletCooltActlTemp;
    ACTCtl_sCOMPActure = ME11_ARID_DEF.Init_la;
    rtb_Merge = cal_ACCMCtrlBDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(ACTCtl_tCtrlBDiff, (const float32 *)
      &cal_ACCMCtrlBKp_1X[0], (const float32 *)&cal_ACCMCtrlBKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(ACTCtl_tCtrlBDiff, (const float32 *)
      &cal_ACCMCtrlBKi_1X[0], (const float32 *)&cal_ACCMCtrlBKi_CUR[0], 7U);
    rtb_Merge1 = cal_ACCMCtrlBPIMax;
    rtb_Add_cy = cal_ACCMCtrlBPIMin;
    break;

   case 1:
   case 12:
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlC1FF_1X[0], (const float32 *)&cal_ACCMCtrlC1FF_CUR[0], 4U);
    rtb_PI_Cor_a = cal_ACCMCtrlCDlyTime;
    rtb_Add_ax = cal_ACCMCtrlCRunTime;
    rtb_Merge1_m = look1_iflf_binlca((float32)fabs(ACTCtl_tCtrlCDiff) *
      cal_ACCMCtrlACct * (float32)ACCtl_BloweFanSpeed, (const float32 *)
      &cal_ACCMCtrlC2FF_1X[0], (const float32 *)&cal_ACCMCtrlC2FF_CUR[0], 3U);
    ACTCtl_sCOMPSetPoint = ACSen_sEvapSurTemp;
    ACTCtl_sCOMPActure = ACCtl_tSetPointEvap;
    rtb_Merge = cal_ACCMCtrlCDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(ACTCtl_tCtrlCDiff, (const float32 *)
      &cal_ACCMCtrlCKp_1X[0], (const float32 *)&cal_ACCMCtrlCKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(ACTCtl_tCtrlCDiff, (const float32 *)
      &cal_ACCMCtrlCKi_1X[0], (const float32 *)&cal_ACCMCtrlCKi_CUR[0], 7U);
    rtb_Merge1 = cal_ACCMCtrlCPIMax;
    rtb_Add_cy = cal_ACCMCtrlCPIMin;
    break;

   case 7:
    ACTCtl_sCOMPActure = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlDTrg_1X[0], (const float32 *)&cal_ACCMCtrlDTrg_CUR[0], 6U);
    rtb_Merge1 = ACSen_sEvapSurTemp - ACTCtl_sCOMPActure;
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlD1FF_1X[0], (const float32 *)&cal_ACCMCtrlD1FF_CUR[0], 2U);
    rtb_PI_Cor_a = cal_ACCMCtrlDDlyTime;
    rtb_Add_ax = cal_ACCMCtrlDRunTime;
    rtb_Merge1_m = look1_iflf_binlca((ACSen_sEvapSurTemp -
      ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn) * cal_ACCMCtrlACct * (float32)
      ACCtl_BloweFanSpeed, (const float32 *)&cal_ACCMCtrlD2FF_1X[0], (const
      float32 *)&cal_ACCMCtrlD2FF_CUR[0], 3U);
    ACTCtl_sCOMPSetPoint = ACSen_sEvapSurTemp;
    rtb_Merge = cal_ACCMCtrlDDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_ACCMCtrlDKp_1X[0], (const float32 *)&cal_ACCMCtrlDKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_ACCMCtrlDKi_1X[0], (const float32 *)&cal_ACCMCtrlDKi_CUR[0], 7U);
    rtb_Merge1 = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlDPIMax_1X[0], (const float32 *)&cal_ACCMCtrlDPIMax_CUR[0], 4U);
    rtb_Add_cy = cal_ACCMCtrlDPIMin;
    break;

   case 14:
    rtb_Merge1 = BMS_InletCooltActlTemp - ME11_ARID_DEF.Init_l;
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlE1FF_1X[0], (const float32 *)&cal_ACCMCtrlE1FF_CUR[0], 6U);
    rtb_PI_Cor_a = cal_ACCMCtrlEDlyTime;
    rtb_Add_ax = cal_ACCMCtrlERunTime;
    rtb_Merge1_m = look1_iflf_binlca((ACSen_sEvapSurTemp - cal_ACCMCtrlETrgTemp)
      * cal_ACCMCtrlACct * (float32)ACCtl_BloweFanSpeed, (const float32 *)
      &cal_ACCMCtrlE2FF_1X[0], (const float32 *)&cal_ACCMCtrlE2FF_CUR[0], 3U);
    ACTCtl_sCOMPSetPoint = BMS_InletCooltActlTemp;
    ACTCtl_sCOMPActure = ME11_ARID_DEF.Init_l;
    rtb_Merge = cal_ACCMCtrlEDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_ACCMCtrlEKp_1X[0], (const float32 *)&cal_ACCMCtrlEKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_ACCMCtrlEKi_1X[0], (const float32 *)&cal_ACCMCtrlEKi_CUR[0], 7U);
    rtb_Merge1 = cal_ACCMCtrlEPIMax;
    rtb_Add_cy = cal_ACCMCtrlEPIMin;
    break;

   case 8:
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlF1FF_1X[0], (const float32 *)&cal_ACCMCtrlF1FF_CUR[0], 4U);
    rtb_PI_Cor_a = cal_ACCMCtrlFDlyTime;
    rtb_Add_ax = cal_ACCMCtrlFRunTime;
    rtb_Merge1_m = look1_iflf_binlca(rtb_Merge1_m, (const float32 *)
      &cal_ACCMCtrlF2FF_1X[0], (const float32 *)&cal_ACCMCtrlF2FF_CUR[0], 4U);
    ACTCtl_sCOMPSetPoint = ACCtl_tSetPointPTC;
    ACTCtl_sCOMPActure =
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C;
    rtb_Merge = cal_ACCMCtrlFDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(rtb_PI_Cor_d, (const float32 *)
      &cal_ACCMCtrlFKp_1X[0], (const float32 *)&cal_ACCMCtrlFKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(rtb_PI_Cor_d, (const float32 *)
      &cal_ACCMCtrlFKi_1X[0], (const float32 *)&cal_ACCMCtrlFKi_CUR[0], 7U);
    rtb_Merge1 = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlFPIMax_1X[0], (const float32 *)&cal_ACCMCtrlFPIMax_CUR[0], 4U);
    rtb_Add_cy = cal_ACCMCtrlFPIMin;
    break;

   case 3:
    if (ACTCtl_sDCoolBatTempDiff >= ACTCtl_sDCoolCabinTempDiff) {
      ACTCtl_sCOMPSetPoint = BMS_InletCooltActlTemp;
      ACTCtl_sCOMPActure = cal_BatCoolInletTrgTemp;
    } else {
      ACTCtl_sCOMPSetPoint = ACSen_sEvapSurTemp;
      ACTCtl_sCOMPActure = ACCtl_tSetPointEvap;
    }

    rtb_Merge1 = ACTCtl_sCOMPSetPoint - ACTCtl_sCOMPActure;
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlH1FF_1X[0], (const float32 *)&cal_ACCMCtrlH1FF_CUR[0], 4U);
    rtb_PI_Cor_a = cal_ACCMCtrlHDlyTime;
    rtb_Add_ax = cal_ACCMCtrlHRunTime;
    rtb_Merge1_m = look1_iflf_binlca((float32)fabs(rtb_Merge1) *
      cal_ACCMCtrlHCct * (float32)ACCtl_BloweFanSpeed, (const float32 *)
      &cal_ACCMCtrlH2FF_1X[0], (const float32 *)&cal_ACCMCtrlH2FF_CUR[0], 3U);
    rtb_Merge = cal_ACCMCtrlHDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_ACCMCtrlHKp_1X[0], (const float32 *)&cal_ACCMCtrlHKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_ACCMCtrlHKi_1X[0], (const float32 *)&cal_ACCMCtrlHKi_CUR[0], 7U);
    rtb_Merge1 = cal_ACCMCtrlHPIMax;
    rtb_Add_cy = cal_ACCMCtrlHPIMin;
    break;

   case 10:
    rtb_Merge_g = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_ACCMCtrlI1FF_1X[0], (const float32 *)&cal_ACCMCtrlI1FF_CUR[0], 4U);
    rtb_PI_Cor_a = cal_ACCMCtrlIDlyTime;
    rtb_Add_ax = cal_ACCMCtrlIRunTime;
    rtb_Merge1_m = look1_iflf_binlca((float32)fabs(ACTCtl_tCtrlCDiff) *
      cal_ACCMCtrlACct * (float32)ACCtl_BloweFanSpeed, (const float32 *)
      &cal_ACCMCtrlI2FF_1X[0], (const float32 *)&cal_ACCMCtrlI2FF_CUR[0], 3U);
    ACTCtl_sCOMPSetPoint = ACSen_sEvapSurTemp;
    ACTCtl_sCOMPActure = ACCtl_tSetPointEvap;
    rtb_Merge = cal_ACCMCtrlIDeadzone;
    ACTCtl_sCOMPCtrlKp = look1_iflf_binlca(ACTCtl_tCtrlCDiff, (const float32 *)
      &cal_ACCMCtrlIKp_1X[0], (const float32 *)&cal_ACCMCtrlIKp_CUR[0], 7U);
    ACTCtl_sCOMPCtrlKi = look1_iflf_binlca(ACTCtl_tCtrlCDiff, (const float32 *)
      &cal_ACCMCtrlIKi_1X[0], (const float32 *)&cal_ACCMCtrlIKi_CUR[0], 7U);
    rtb_Merge1 = cal_ACCMCtrlIPIMax;
    rtb_Add_cy = cal_ACCMCtrlIPIMin;
    break;

   default:
    rtb_Merge_g = 0.0F;
    rtb_PI_Cor_a = 0.0F;
    rtb_Add_ax = 0.0F;
    rtb_Merge1_m = 0.0F;
    ACTCtl_sCOMPSetPoint = 0.0F;
    ACTCtl_sCOMPActure = 0.0F;
    rtb_Merge = 0.0F;
    ACTCtl_sCOMPCtrlKp = 0.0F;
    ACTCtl_sCOMPCtrlKi = 0.0F;
    rtb_Merge1 = 0.0F;
    rtb_Add_cy = 0.0F;
    break;
  }

  ACTCtl_sDvtCOMPCtrl = ACTCtl_sCOMPSetPoint - ACTCtl_sCOMPActure;
  ME11_deadzone_h1(ACTCtl_sDvtCOMPCtrl, rtb_Merge, &rtb_flag_k);
  ACTCtl_bCOMPDvtFlg = (ACTCtl_sCOMPSetPoint >= ACTCtl_sCOMPActure);
  if (rtb_flag_k) {
    ACTCtl_sDvtCOMPCtrl = 0.0F;
  } else if (!ACTCtl_bCOMPDvtFlg) {
    ACTCtl_sDvtCOMPCtrl = ACTCtl_sCOMPActure - ACTCtl_sCOMPSetPoint;
  }

  ME11_P_NEG(!ACTCtl_bCOMPDvtFlg, ACTCtl_sDvtCOMPCtrl, cal_ACCMCtlKiDeadzoneNeg,
             ACTCtl_sCOMPCtrlKi, cal_ACCMCtrlKi, (float32 *)&ACTCtl_sACCMI_Cor);
  ME11_P_POS(ACTCtl_bCOMPDvtFlg, ACTCtl_sDvtCOMPCtrl, cal_ACCMCtlKiDeadzonePos,
             ACTCtl_sCOMPCtrlKi, cal_ACCMCtrlKi, (float32 *)&ACTCtl_sACCMI_Cor);
  if (ME11_ARID_DEF.temporalCounter_i2 < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i2++;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_k < 3U) {
    ME11_ARID_DEF.temporalCounter_i1_k++;
  }

  if (ME11_ARID_DEF.is_active_c5_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c5_ME11 = 1U;
    ME11_ARID_DEF.is_c5_ME11 = ME11_IN_Off_a;
    ACTCtl_bCOMPPIEnble = false;
    ACTCtl_sACCMCtlFF = 0.0F;
  } else if (ME11_ARID_DEF.is_c5_ME11 == ME11_IN_Off_a) {
    if (ME11_ARID_DEF.ACTCtl_eACCMCtlEnb) {
      ME11_ARID_DEF.is_c5_ME11 = ME11_IN_On_li;
      ME11_ARID_DEF.is_On_e = ME11_IN_DelayOpen;
      ME11_ARID_DEF.temporalCounter_i2 = 0U;
    }
  } else if (!ME11_ARID_DEF.ACTCtl_eACCMCtlEnb) {
    ME11_ARID_DEF.is_On_e = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c5_ME11 = ME11_IN_Off_a;
    ACTCtl_bCOMPPIEnble = false;
    ACTCtl_sACCMCtlFF = 0.0F;
  } else {
    switch (ME11_ARID_DEF.is_On_e) {
     case ME11_IN_CloseCtl:
      if ((ME11_ARID_DEF.Delay_DSTATE_af == 3) && (rtb_Switch2_ht == 1)) {
        ME11_ARID_DEF.is_On_e = ME11_IN_RelayOpen;
        ME11_ARID_DEF.temporalCounter_i1_k = 0U;
        ACTCtl_bCOMPPIEnble = false;
        ACTCtl_sACCMCtlFF = rtb_Merge_g;
      } else {
        ACTCtl_bCOMPPIEnble = true;
        ACTCtl_sACCMCtlFF = rtb_Merge1_m;
      }
      break;

     case ME11_IN_DelayOpen:
      if (ME11_ARID_DEF.temporalCounter_i2 >= rtb_PI_Cor_a * 10.0F) {
        ME11_ARID_DEF.is_On_e = ME11_IN_OpenCtl;
        ME11_ARID_DEF.temporalCounter_i2 = 0U;
        ACTCtl_sACCMCtlFF = rtb_Merge_g;
      }
      break;

     case ME11_IN_OpenCtl:
      if (ME11_ARID_DEF.temporalCounter_i2 >= rtb_Add_ax * 10.0F) {
        ME11_ARID_DEF.is_On_e = ME11_IN_CloseCtl;
        ACTCtl_bCOMPPIEnble = true;
        ACTCtl_sACCMCtlFF = rtb_Merge1_m;
      } else {
        ACTCtl_sACCMCtlFF = rtb_Merge_g;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_k >= 2) {
        ME11_ARID_DEF.is_On_e = ME11_IN_OpenCtl;
        ME11_ARID_DEF.temporalCounter_i2 = 0U;
        ACTCtl_sACCMCtlFF = rtb_Merge_g;
      } else {
        ACTCtl_bCOMPPIEnble = false;
        ACTCtl_sACCMCtlFF = rtb_Merge_g;
      }
      break;
    }
  }

  if (ACTCtl_bCOMPPIEnble) {
    switch (ME11_ARID_DEF.Delay_DSTATE_cv) {
     case 0:
      if (ACTCtl_bCOMPDvtFlg) {
        ACTCtl_sACCMI_Sum = ACTCtl_sACCMI_Sum + ACTCtl_sACCMI_Cor;
      } else {
        ACTCtl_sACCMI_Sum = ACTCtl_sACCMI_Sum - ACTCtl_sACCMI_Cor;
      }
      break;

     case 1:
      if (!ACTCtl_bCOMPDvtFlg) {
        ACTCtl_sACCMI_Sum = ACTCtl_sACCMI_Sum - ACTCtl_sACCMI_Cor;
      }
      break;

     case 2:
      if (ACTCtl_bCOMPDvtFlg) {
        ACTCtl_sACCMI_Sum = ACTCtl_sACCMI_Sum + ACTCtl_sACCMI_Cor;
      }
      break;

     case 3:
      break;
    }

    if (ACTCtl_sACCMI_Sum > cal_ACCMCtlPID_IsumMax) {
      ACTCtl_sACCMI_Sum = cal_ACCMCtlPID_IsumMax;
    } else if (ACTCtl_sACCMI_Sum < cal_ACCMCtlPID_IsumMin) {
      ACTCtl_sACCMI_Sum = cal_ACCMCtlPID_IsumMin;
    }
  } else {
    ACTCtl_sACCMI_Sum = 0.0F;
  }

  ME11_PI_Controller1(!ACTCtl_bCOMPPIEnble, ACTCtl_sACCMCtlFF, (float32 *)
                      &ACTCtl_sACCMPIVal, (uint8 *)&ACTCtl_bCOMPIFreeFlag);
  ME11_P_NEG_p(!ACTCtl_bCOMPDvtFlg, ACTCtl_sDvtCOMPCtrl,
               cal_ACCMCtlKpDeadzoneNeg, ACTCtl_sCOMPCtrlKp, cal_ACCMCtrlKp,
               (float32 *)&ACTCtl_sACCMP_Cor);
  ME11_P_POS_l(ACTCtl_bCOMPDvtFlg, ACTCtl_sDvtCOMPCtrl, cal_ACCMCtlKpDeadzonePos,
               ACTCtl_sCOMPCtrlKp, cal_ACCMCtrlKp, (float32 *)&ACTCtl_sACCMP_Cor);
  ME11_PI_Controller(ACTCtl_bCOMPPIEnble, ACTCtl_bCOMPDvtFlg, ACTCtl_sACCMCtlFF,
                     ACTCtl_sACCMP_Cor, ACTCtl_sACCMI_Sum, rtb_Merge1,
                     rtb_Add_cy, (float32 *)&ACTCtl_sACCMPIVal, (uint8 *)
                     &ACTCtl_bCOMPIFreeFlag);
  ACTCtl_bCOMPFaultClc = ((ME11_ARID_DEF.ClearFlt_n != 0.0) ||
    (ME11_ARID_DEF.ClearFlt_m != 0.0) || (ME11_ARID_DEF.ClearFlt_k != 0.0) ||
    (ME11_ARID_DEF.ClearFlt_c != 0.0) || (ME11_ARID_DEF.ClearFlt_f != 0.0) ||
    (ME11_ARID_DEF.ClearFlt != 0.0));
  rtb_BusCreator6.COMP_EcompErrorClean = ACTCtl_bCOMPFaultClc;
  rtb_Switch_n2 =
    ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA()
     )->VIPM_ESCVehSpd_kph > cal_COMPCoolLowSpd);
  ACTCtl_sCOMPATNoiseLmtHVSSpd = look1_iflf_binlca(ACSen_sEnvTempCor, (const
    float32 *)&cal_COMPATNoiseSpdLmtHVS_1X[0], (const float32 *)
    &cal_COMPATNoiseSpdLmtHVS_CUR[0], 7U);
  ACTCtl_sCOMPATNoiseBlwAndAccmSpd = look2_ifbfu8lf_binlca(ACTCtl_sACCMPIVal,
    ACCtl_BloweFanSpeed, (const float32 *)&cal_COMPATNoiseSpdLmt_2X[0], (const
    uint8 *)&cal_COMPATNoiseSpdLmt_2Y[0], (const float32 *)
    &cal_COMPATNoiseSpdLmt_MAP[0], ME11_ConstP.pooled34, 10U);
  if ((rtb_Switch2_ht == 3) && ((ME11_ARID_DEF.DataTypeConversion1 == 3) ||
       (ME11_ARID_DEF.DataTypeConversion1 == 4) || rtb_Switch_n2)) {
    ACTCtl_sCOMPCoolLmtSpd = ACTCtl_sCOMPATNoiseLmtHVSSpd;
  } else {
    rtb_Compare_mos =
      ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA())
       ->VIPM_ESCVehSpd_kph > cal_COMPCoolLowSpd);
    if (rtb_Compare_mos && (rtb_Switch2_ht == 1)) {
      ACTCtl_sCOMPCoolLmtSpd = 6000.0F;
    } else {
      rtb_Compare_mos =
        ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
          ())->VIPM_ESCVehSpd_kph < cal_COMPCoolLowSpd);
      if (((rtb_Switch2_ht == 3) && (ME11_ARID_DEF.DataTypeConversion1 == 5)) ||
          (rtb_Compare_mos && (rtb_Switch2_ht == 1))) {
        ACTCtl_sCOMPCoolLmtSpd = ACTCtl_sCOMPATNoiseBlwAndAccmSpd;
      } else {
        ACTCtl_sCOMPCoolLmtSpd = 8000.0F;
      }
    }
  }

  rtb_IFreezFlag_bd = look1_iflftu8Df_binlca(ACSen_sHiPressFilter, (const
    float32 *)&cal_AccmSpdLimByHiPressLevelCalcu_1X[0], (const uint8 *)
    &cal_AccmSpdLimByHiPressLevelCalcu_CUR[0], 11U);
  if (ACSen_sHiPressFilter < ME11_ARID_DEF.DelayInput1_DSTATE_e) {
    ACTCtl_sCOMPHPLmtSpd =
      cal_AccmSpdLimByHiPressDownSide_CUR[plook_u32u8_binckan(rtb_IFreezFlag_bd,
      (const uint8 *)&cal_AccmSpdLimByHiPressDownSide_1X[0], 11U)];
  } else if (ACSen_sHiPressFilter > ME11_ARID_DEF.DelayInput1_DSTATE_i) {
    ACTCtl_sCOMPHPLmtSpd = cal_AccmSpdLimByHiPressUpSide_CUR[plook_u32u8_binckan
      (rtb_IFreezFlag_bd, (const uint8 *)&cal_AccmSpdLimByHiPressUpSide_1X[0],
       11U)];
  }

  rtb_IFreezFlag_bd = look1_iflftu8Df_binlca(ACSen_sLoPressFilter, (const
    float32 *)&cal_AccmSpdLimByLoPressLevelCalcu_1X[0], (const uint8 *)
    &cal_AccmSpdLimByLoPressLevelCalcu_CUR[0], 11U);
  if (ACSen_sLoPressFilter < ME11_ARID_DEF.DelayInput1_DSTATE_o) {
    ACTCtl_sCOMPLPLmtSpd =
      cal_AccmSpdLimByLoPressDownSide_CUR[plook_u32u8_binckan(rtb_IFreezFlag_bd,
      (const uint8 *)&cal_AccmSpdLimByLoPressDownSide_1X[0], 11U)];
  } else if (ACSen_sLoPressFilter > ME11_ARID_DEF.DelayInput1_DSTATE_g) {
    ACTCtl_sCOMPLPLmtSpd = cal_AccmSpdLimByLoPressUpSide_CUR[plook_u32u8_binckan
      (rtb_IFreezFlag_bd, (const uint8 *)&cal_AccmSpdLimByLoPressUpSide_1X[0],
       11U)];
  }

  switch (rtb_Switch2_ht) {
   case 1:
    ACTCtl_sCOMPPCULimSpd = look1_iflf_binlca(ACSen_sMotTempFilter, (const
      float32 *)&cal_PCULimCabinAccmSpdDes_1X[0], (const float32 *)
      &cal_PCULimCabinAccmSpdDes_CUR[0], 7U);
    break;

   case 2:
    ACTCtl_sCOMPPCULimSpd = look1_iflf_binlca(ACSen_sMotTempFilter, (const
      float32 *)&cal_PCULimBTMAccmSpdDes_1X[0], (const float32 *)
      &cal_PCULimBTMAccmSpdDes_CUR[0], 7U);
    break;

   case 3:
    ACTCtl_sCOMPPCULimSpd = look1_iflf_binlca(ACSen_sMotTempFilter, (const
      float32 *)&cal_PCULimBTMAndCabinAccmSpdDes_1X[0], (const float32 *)
      &cal_PCULimBTMAndCabinAccmSpdDes_CUR[0], 7U);
    break;

   default:
    ACTCtl_sCOMPPCULimSpd = 8000.0F;
    break;
  }

  if (ACTCtl_sCOMPCoolLmtSpd <= ACTCtl_sCOMPHPLmtSpd) {
    ACTCtl_sCOMPATNoiseLmtSpd = ACTCtl_sCOMPCoolLmtSpd;
  } else {
    ACTCtl_sCOMPATNoiseLmtSpd = ACTCtl_sCOMPHPLmtSpd;
  }

  if (ACTCtl_sCOMPATNoiseLmtSpd > ACTCtl_sCOMPLPLmtSpd) {
    ACTCtl_sCOMPATNoiseLmtSpd = ACTCtl_sCOMPLPLmtSpd;
  }

  if (ACTCtl_sCOMPATNoiseLmtSpd > ACTCtl_sCOMPPCULimSpd) {
    ACTCtl_sCOMPATNoiseLmtSpd = ACTCtl_sCOMPPCULimSpd;
  }

  if (ACSen_sEnvTempCor > 40.0F) {
    ACTCtl_sCOMPEnvLmtSpd = 8000.0F;
  } else if (ACSen_sEnvTempCor > 35.0F) {
    ACTCtl_sCOMPEnvLmtSpd = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_COMPEnvSpdLmt3_1X[0], (const float32 *)&cal_COMPEnvSpdLmt3_CUR[0], 1U);
  } else if (ACSen_sEnvTempCor > 30.0F) {
    ACTCtl_sCOMPEnvLmtSpd = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_COMPEnvSpdLmt2_1X[0], (const float32 *)&cal_COMPEnvSpdLmt2_CUR[0], 1U);
  } else if (ACSen_sEnvTempCor > 20.0F) {
    ACTCtl_sCOMPEnvLmtSpd = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_COMPEnvSpdLmt1_1X[0], (const float32 *)&cal_COMPEnvSpdLmt1_CUR[0], 1U);
  } else if ((rtb_Switch2_ht == 4) || (rtb_Switch2_ht == 5) || (rtb_Switch2_ht ==
              6)) {
    ACTCtl_sCOMPEnvLmtSpd = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_COMPEnvSpdLmt4_1X[0], (const float32 *)&cal_COMPEnvSpdLmt4_CUR[0], 1U);
  } else {
    ACTCtl_sCOMPEnvLmtSpd = cal_COMPEnvSpdLmtDef;
  }

  ACTCtl_sCOMPFanlevelLmtSpd = look1_iu8lftf_binlca(AC_FanLeVel, (const uint8 *)
    &cal_COMPFanLevelLmt_1X[0], (const float32 *)&cal_COMPFanLevelLmt_CUR[0], 8U);
  if (ME11_ARID_DEF.is_active_c149_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c149_ME11 = 1U;
    ME11_enter_internal_Choice(&rtb_Switch2_ht);
  } else {
    switch (ME11_ARID_DEF.is_Choice) {
     case ME11_IN_ChgBatCool:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;

     case ME11_IN_ChgDCool:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;

     case ME11_IN_NmlBatCool:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;

     case ME11_IN_NmlBatCool1:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;

     case ME11_IN_NmlBatCool2:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;

     case ME11_IN_NmlDCoolHVS:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;

     default:
      ME11_ARID_DEF.is_Choice = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_enter_internal_Choice(&rtb_Switch2_ht);
      break;
    }
  }

  if (ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd <= ACTCtl_sCOMPATNoiseLmtSpd) {
    ACTCtl_sCOMPLmtMaxSpd = ME11_ARID_DEF.ACTCtl_sCOMPLmtSpd;
  } else {
    ACTCtl_sCOMPLmtMaxSpd = ACTCtl_sCOMPATNoiseLmtSpd;
  }

  rtb_Compare_mos = ((COMP_EcompActSpd <= cal_OilBackStartSpd) &&
                     (COMP_EcompActSpd > 0.0F));
  if (ME11_ARID_DEF.temporalCounter_i1_m < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_m++;
  }

  if (ME11_ARID_DEF.is_active_c166_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c166_ME11 = 1U;
    ME11_ARID_DEF.is_c166_ME11 = ME11_IN_Off_a;
    ACTCtl_bOilBackFlg = false;
  } else {
    switch (ME11_ARID_DEF.is_c166_ME11) {
     case ME11_IN_Off_a:
      ACTCtl_bOilBackFlg = false;
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c166_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_m = 0U;
      }
      break;

     case ME11_IN_On_li:
      ACTCtl_bOilBackFlg = true;
      if (ME11_ARID_DEF.temporalCounter_i1_m >= (uint32)ceil(cal_OilBackRunTime /
           600.0 * 10.0)) {
        ME11_ARID_DEF.is_c166_ME11 = ME11_IN_Off_a;
        ACTCtl_bOilBackFlg = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_m >= (uint32)ceil
          (cal_OilBackJudgeTime / 600.0 * 10.0)) {
        ME11_ARID_DEF.is_c166_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.temporalCounter_i1_m = 0U;
        ACTCtl_bOilBackFlg = true;
      } else if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c166_ME11 = ME11_IN_Off_a;
        ACTCtl_bOilBackFlg = false;
      }
      break;
    }
  }

  if (ACTCtl_bOilBackFlg) {
    rtb_PI_Cor_a = cal_COMPSpdOilBackVal;
  } else {
    if (ACTCtl_sACCMPIVal <= ACTCtl_sCOMPLmtMaxSpd) {
      rtb_PI_Cor_a = ACTCtl_sACCMPIVal;
    } else {
      rtb_PI_Cor_a = ACTCtl_sCOMPLmtMaxSpd;
    }

    if (cal_COMPSpdDiffUp <= rtb_PI_Cor_a - ME11_ARID_DEF.Delay_DSTATE_h) {
      rtb_PI_Cor_a = cal_COMPSpdDiffUpRate + ME11_ARID_DEF.Delay_DSTATE_h;
    } else if (ME11_ARID_DEF.Delay_DSTATE_h - rtb_PI_Cor_a >=
               cal_COMPSpdDiffDown) {
      rtb_PI_Cor_a = ME11_ARID_DEF.Delay_DSTATE_h - cal_COMPSpdDiffDownRate;
    }
  }

  ME11_PwrOn(&rtb_flg_m, &ME11_ARID_DEF.ARID_DEF_PwrOn_o);
  if (rtb_flg_m) {
    ME11_ARID_DEF.Delay_DSTATE_b = rtb_PI_Cor_a;
  } else if (rtb_PI_Cor_a > ME11_ARID_DEF.Delay_DSTATE_b + cal_ACCMCtlUplmt) {
    ME11_ARID_DEF.Delay_DSTATE_b += cal_ACCMCtlUplmt;
  } else if (rtb_PI_Cor_a < ME11_ARID_DEF.Delay_DSTATE_b - cal_ACCMCtlDownlmt) {
    ME11_ARID_DEF.Delay_DSTATE_b -= cal_ACCMCtlDownlmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_b = rtb_PI_Cor_a;
  }

  ME11_PwrOn(&rtb_flg_n, &ME11_ARID_DEF.ARID_DEF_PwrOn_i);
  if (rtb_flg_n) {
    ME11_ARID_DEF.Delay_DSTATE_p0 = rtb_PI_Cor_a;
  } else if (rtb_PI_Cor_a > ME11_ARID_DEF.Delay_DSTATE_p0 +
             cal_OpenCtrlCOMPUplmt) {
    ME11_ARID_DEF.Delay_DSTATE_p0 += cal_OpenCtrlCOMPUplmt;
  } else if (rtb_PI_Cor_a < ME11_ARID_DEF.Delay_DSTATE_p0 -
             cal_OpenCtrlCOMPDownlmt) {
    ME11_ARID_DEF.Delay_DSTATE_p0 -= cal_OpenCtrlCOMPDownlmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_p0 = rtb_PI_Cor_a;
  }

  if (ACTCtl_bCOMPPIEnble) {
    rtb_PI_Cor_a = ME11_ARID_DEF.Delay_DSTATE_b;
  } else {
    rtb_PI_Cor_a = ME11_ARID_DEF.Delay_DSTATE_p0;
  }

  rtb_Compare_mos = ((rtb_PI_Cor_a > cal_COMPClsLowSpeed) && (COMP_EcompActSpd ==
    0.0F));
  if (ACTCtl_eCOMPPrsPrtSts == 8) {
    if (ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_g >=
        ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_m) {
      rtb_DataTypeConversion23 = ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_g;
    } else {
      rtb_DataTypeConversion23 = ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_m;
    }
  } else if (ACTCtl_eCOMPPrsPrtSts == 4) {
    rtb_DataTypeConversion23 = ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_m;
  } else if (ACTCtl_eCOMPPrsPrtSts == 4) {
    rtb_DataTypeConversion23 = ME11_ARID_DEF.ACTCtl_sCOMPDownSpd_g;
  } else {
    rtb_DataTypeConversion23 = 0.0F;
  }

  if (ACTCtl_eCOMPExhTPrtSts == 1) {
    ACTCtl_sCOMPDownSpd = cal_COMPExhTDownSpd;
  } else {
    ACTCtl_sCOMPDownSpd = 0.0F;
  }

  if (rtb_DataTypeConversion23 >= ACTCtl_sCOMPDownSpd) {
    ACTCtl_sCOMPDownSpd = rtb_DataTypeConversion23;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_il < 255U) {
    ME11_ARID_DEF.temporalCounter_i1_il++;
  }

  if (ME11_ARID_DEF.is_active_c29_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c29_ME11 = 1U;
    ME11_ARID_DEF.is_c29_ME11 = ME11_IN_Off_a;
    ACTCtl_bCOMPSpdDiffFlt = false;
  } else {
    switch (ME11_ARID_DEF.is_c29_ME11) {
     case ME11_IN_Off_a:
      ACTCtl_bCOMPSpdDiffFlt = false;
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c29_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_il = 0U;
      }
      break;

     case ME11_IN_On_li:
      ACTCtl_bCOMPSpdDiffFlt = true;
      if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c29_ME11 = ME11_IN_wait1_o;
        ME11_ARID_DEF.temporalCounter_i1_il = 0U;
      }
      break;

     case ME11_IN_wait_k:
      if (ME11_ARID_DEF.temporalCounter_i1_il >= 50U) {
        ME11_ARID_DEF.is_c29_ME11 = ME11_IN_On_li;
        ACTCtl_bCOMPSpdDiffFlt = true;
      } else if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c29_ME11 = ME11_IN_Off_a;
        ACTCtl_bCOMPSpdDiffFlt = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_il >= 200U) {
        ME11_ARID_DEF.is_c29_ME11 = ME11_IN_Off_a;
        ACTCtl_bCOMPSpdDiffFlt = false;
      }
      break;
    }
  }

  rtb_Merge_g = ME11_ARID_DEF.Delay_DSTATE_k3;
  if (ME11_ARID_DEF.temporalCounter_i1_h < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_h++;
  }

  if (ME11_ARID_DEF.is_active_c52_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c52_ME11 = 1U;
    ME11_ARID_DEF.is_c52_ME11 = ME11_IN_Default_o;
    ACTCtl_eEvapProSts = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c52_ME11) {
     case ME11_IN_CalClsSpd:
      ACTCtl_eEvapProSts = 1U;
      if (ACSen_sEvapSurTemp > cal_AEXVOpenEvapNOPrtTemp) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_wait_oc;
        ME11_ARID_DEF.temporalCounter_i1_h = 0U;
        ACTCtl_eEvapProSts = 5U;
        ME11_ARID_DEF.ACTCtl_sAEXVVal = ME11_ARID_DEF.Delay_DSTATE_k3;
      } else if (ME11_ARID_DEF.Delay_DSTATE_k3 <= cal_AEXVClsValEvapPrt) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_Wait_bn;
        ME11_ARID_DEF.temporalCounter_i1_h = 0U;
        ACTCtl_eEvapProSts = 2U;
      }
      break;

     case ME11_IN_CloseVavle:
      ACTCtl_eEvapProSts = 3U;
      if (ACSen_sEvapSurTemp > cal_AEXVOpenEvapNOPrtTemp) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_Wait1;
        ME11_ARID_DEF.temporalCounter_i1_h = 0U;
        ACTCtl_eEvapProSts = 4U;
      }
      break;

     case ME11_IN_Default_o:
      ACTCtl_eEvapProSts = 0U;
      if (ACSen_sEvapSurTemp < cal_AEXVClsEvapPrtTemp) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_CalClsSpd;
        ACTCtl_eEvapProSts = 1U;
      }
      break;

     case ME11_IN_OpenCtrl_l:
      ACTCtl_eEvapProSts = 5U;
      if (ME11_ARID_DEF.temporalCounter_i1_h >= cal_AEXVOpenRunTimeEvapNOPrt *
          10.0F) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_Default_o;
        ACTCtl_eEvapProSts = 0U;
      } else if (ACSen_sEvapSurTemp < cal_AEXVClsEvapPrtTemp) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_CalClsSpd;
        ACTCtl_eEvapProSts = 1U;
      }
      break;

     case ME11_IN_Wait_bn:
      ACTCtl_eEvapProSts = 2U;
      if (ME11_ARID_DEF.temporalCounter_i1_h >= cal_AEXVClsValRunTimeEvapPrt *
          10.0F) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_CloseVavle;
        ACTCtl_eEvapProSts = 3U;
        ME11_ARID_DEF.ACTCtl_sAEXVVal = 0.0F;
      }
      break;

     case ME11_IN_Wait1:
      ACTCtl_eEvapProSts = 4U;
      if (ME11_ARID_DEF.temporalCounter_i1_h >= cal_AEXVOpenDelayTimeEvapNOPrt *
          10.0F) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_OpenCtrl_l;
        ME11_ARID_DEF.temporalCounter_i1_h = 0U;
        ACTCtl_eEvapProSts = 5U;
        ME11_ARID_DEF.ACTCtl_sAEXVVal = cal_AEXVOpenValEvapNOPrt;
      }
      break;

     default:
      ACTCtl_eEvapProSts = 5U;
      if (ME11_ARID_DEF.temporalCounter_i1_h >= cal_AEXVOpenRunTimeEvapNOPrt *
          10.0F) {
        ME11_ARID_DEF.is_c52_ME11 = ME11_IN_Default_o;
        ACTCtl_eEvapProSts = 0U;
      }
      break;
    }
  }

  ME11_ARID_DEF.Delay_DSTATE_kf = (cal_ACCMForbidCtrl && ACTCtl_bACCMCtlEnb);
  for (b_previousEvent = 0; b_previousEvent < 6; b_previousEvent++) {
    rtb_Compare_mjv[b_previousEvent] = (rtb_Switch2_ht ==
      ME11_ConstP.Constant_Value_ig[b_previousEvent]);
  }

  rtb_Compare_gzu = rtb_Compare_mjv[0];
  for (b_previousEvent = 0; b_previousEvent < 5; b_previousEvent++) {
    rtb_Compare_gzu = (rtb_Compare_gzu || rtb_Compare_mjv[b_previousEvent + 1]);
  }

  rtb_Compare_mos = (ME11_ARID_DEF.Delay_DSTATE_kf && rtb_Compare_gzu);
  if (rtb_Compare_mos) {
    rtb_IFreezFlag_bd = ACTCtl_eEvapProSts;
  } else {
    rtb_IFreezFlag_bd = 0U;
  }

  ACTCtl_bCOMPStopFlg = ((ACTCtl_eCOMPExhTPrtSts == 2) || (ACTCtl_eCOMPPrsPrtSts
    == 16) || (rtb_IFreezFlag_bd >= 2) || ACTCtl_bCOMPSpdDiffFlt);
  if (cal_ACCMCtrlSpdDataEnb) {
    rtb_PI_Cor_a = cal_ACCMCtrlSpdData;
  } else if (ACTCtl_bCOMPStopFlg) {
    rtb_PI_Cor_a = 0.0F;
  } else if (ACTCtl_sCOMPDownSpd > 0.0F) {
    rtb_PI_Cor_a = ME11_ARID_DEF.Delay_DSTATE_h - ACTCtl_sCOMPDownSpd;
  }

  if (rtb_PI_Cor_a > 8000.0F) {
    ME11_ARID_DEF.Delay_DSTATE_h = 8000.0F;
  } else if (rtb_PI_Cor_a < 0.0F) {
    ME11_ARID_DEF.Delay_DSTATE_h = 0.0F;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_h = rtb_PI_Cor_a;
  }

  ME11_ARID_DEF.Relay_Mode_j = ((ME11_ARID_DEF.Delay_DSTATE_h >=
    cal_COMPONMinSpd) || ((ME11_ARID_DEF.Delay_DSTATE_h > cal_COMPOffMaxSpd) &&
    ME11_ARID_DEF.Relay_Mode_j));
  if (ME11_ARID_DEF.Relay_Mode_j) {
    ACTCtl_sACCMCtlSpd = ME11_ARID_DEF.Delay_DSTATE_h;
  } else {
    ACTCtl_sACCMCtlSpd = 0.0F;
  }

  rtb_BusCreator6.COMP_EcompHVSt = ME11_ARID_DEF.Delay_DSTATE_kf;
  Rte_DIDReadData(ME11_ARID_DEF.Delay_DSTATE_kf, ((uint8)DID_0xF274));
  ACTCtl_sPTCAuxHeatPwr = look2_iflf_binlca(ACTCtl_tCtrlADiff,
    HMICtl_sLeftSetPoint, (const float32 *)&cal_PTCAuxHeatPwrLmt_2Y[0], (const
    float32 *)&cal_PTCAuxHeatPwrLmt_2X[0], (const float32 *)
    &cal_PTCAuxHeatPwrLmt_MAP[0], ME11_ConstP.pooled37, 6U);
  if (ACTCtl_sPTCAuxHeatPwr >= look1_iflf_binlca(ACCtl_tSetPointPTC, (const
        float32 *)&cal_PTCOnReqPower_1X[0], (const float32 *)
       &cal_PTCOnReqPower_CUR[0], 5U)) {
    ACTCtl_bPTCOnOrOffPwrDiff = true;
  } else {
    ACTCtl_bPTCOnOrOffPwrDiff = ((ACTCtl_sPTCAuxHeatPwr > cal_PTCOffPowerVal) &&
      ACTCtl_bPTCOnOrOffPwrDiff);
  }

  if (ACTCtl_bPTCOnOrOffPwrDiff) {
    rtb_PI_Cor_a = ACTCtl_sPTCAuxHeatPwr;
  } else {
    rtb_PI_Cor_a = 0.0F;
  }

  ACTCtl_sCtrlFPTCAuxHeatPwr = look2_iflf_binlca(rtb_PI_Cor_d,
    HMICtl_sLeftSetPoint, (const float32 *)&cal_CtrlFPTCAuxHeatPwrLmt_2Y[0], (
    const float32 *)&cal_CtrlFPTCAuxHeatPwrLmt_2X[0], (const float32 *)
    &cal_CtrlFPTCAuxHeatPwrLmt_MAP[0], ME11_ConstP.pooled37, 6U);
  if (ACTCtl_sCtrlFPTCAuxHeatPwr >= look1_iflf_binlca(ACCtl_tSetPointPTC, (const
        float32 *)&cal_CtrlFPTCOnReqPower_1X[0], (const float32 *)
       &cal_CtrlFPTCOnReqPower_CUR[0], 5U)) {
    ACTCtl_bCtrlFPTCOnOrOffPwrDiff = true;
  } else {
    ACTCtl_bCtrlFPTCOnOrOffPwrDiff = ((ACTCtl_sCtrlFPTCAuxHeatPwr >
      cal_CtrlFPTCOffPowerVal) && ACTCtl_bCtrlFPTCOnOrOffPwrDiff);
  }

  ME11_ARID_DEF.Relay2_Mode_o = ((ACSen_sEvapSurTemp >= cal_COMPEvapTNmlVal) ||
    ((ACSen_sEvapSurTemp > cal_COMPEvapTFrbVal) && ME11_ARID_DEF.Relay2_Mode_o));
  for (b_previousEvent = 0; b_previousEvent < 5; b_previousEvent++) {
    rtb_Compare_btd[b_previousEvent] = (rtb_Switch2_ht ==
      ME11_ConstP.Constant_Value_dn[b_previousEvent]);
  }

  ACTCtl_bCOMPEnvpTPrtFlg = ((!ME11_ARID_DEF.Relay2_Mode_o) && (rtb_Compare_btd
    [0] || rtb_Compare_btd[1] || rtb_Compare_btd[2] || rtb_Compare_btd[3] ||
    rtb_Compare_btd[4]));
  ME11_ARID_DEF.GLB_TMSFaultECV[0] = rtb_Switch_kl;
  ME11_ARID_DEF.GLB_TMSFaultECV[1] = rtb_Compare_jkf;
  ME11_ARID_DEF.GLB_TMSFaultECV[2] = rtb_Compare_c;
  ME11_ARID_DEF.GLB_TMSFaultECV[3] = rtb_Compare_l5;
  ME11_ARID_DEF.GLB_TMSFaultECV[4] = rtb_Compare_h1;
  ME11_ARID_DEF.GLB_TMSFaultECV[5] = rtb_Compare_cls;
  ME11_ARID_DEF.GLB_TMSFaultECV[6] = rtb_Compare_bdq;
  ME11_ARID_DEF.GLB_TMSFaultECV[7] = rtb_Compare_ip;
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943816), (uint8)(MCV_VoltSts ==
    2));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943817), (uint8)(MCV_VoltSts ==
    1));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943821), (uint8)(MCV_TempSts ==
    3));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x94384B), (uint8)(MCV_TempSts ==
    1));
  rtb_Compare_cj1 = (MCV_FltSts == 1);
  if (ME11_ARID_DEF.is_active_c160_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c160_ME11 = 1U;
    ME11_ARID_DEF.is_c160_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.Flag = 0U;
    ME11_ARID_DEF.counter_m = 0U;
  } else {
    switch (ME11_ARID_DEF.is_c160_ME11) {
     case ME11_IN_Default_k:
      ME11_ARID_DEF.Flag = 0U;
      if (rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c160_ME11 = ME11_IN_wait_d;
      }
      break;

     case ME11_IN_wait_d:
      if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c160_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.Flag = 0U;
        ME11_ARID_DEF.counter_m = 0U;
      } else if (ME11_ARID_DEF.counter_m >= 2) {
        ME11_ARID_DEF.is_c160_ME11 = ME11_IN_wait1_l;
        ME11_ARID_DEF.Flag = 1U;
      } else {
        b_previousEvent = ME11_ARID_DEF.counter_m + 1;
        if (ME11_ARID_DEF.counter_m + 1 > 255) {
          b_previousEvent = 255;
        }

        ME11_ARID_DEF.counter_m = (uint8)b_previousEvent;
      }
      break;

     default:
      ME11_ARID_DEF.Flag = 1U;
      if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c160_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.Flag = 0U;
        ME11_ARID_DEF.counter_m = 0U;
      }
      break;
    }
  }

  Dem_SetEventStatus(((uint8)DemEventParameter_0x943871), ME11_ARID_DEF.Flag);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943898), (uint8)(MCV_FltSts ==
    5));
  ME11_Chart((MCV_FltSts == 1) || (MCV_FltSts == 2), (uint16)
             (cal_MCVFltStsDelayTime * 10U), &ME11_ARID_DEF.Flag_a,
             &ME11_ARID_DEF.ARID_DEF_Chart_jz);
  rtb_Compare_cj1 = ((ACTCtl_eC3WVSLSts <= 0) && rtb_RelationalOperator_pl);
  if (ME11_ARID_DEF.temporalCounter_i1_n < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_n++;
  }

  if (ME11_ARID_DEF.is_active_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib == 0U) {
    ME11_ARID_DEF.is_active_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib = 1U;
    ME11_ARID_DEF.is_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib = ME11_IN_Init_i;
    ME11_ARID_DEF.Flag_o = false;
  } else {
    switch (ME11_ARID_DEF.is_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib) {
     case ME11_IN_Init_i:
      ME11_ARID_DEF.Flag_o = false;
      if (rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_n = 0U;
      }
      break;

     case ME11_IN_StepUp:
      ME11_ARID_DEF.Flag_o = true;
      if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib = ME11_IN_Init_i;
        ME11_ARID_DEF.Flag_o = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_n >= (uint32)ceil(60.0 *
           cal_MCVPosDiffDelayTime * 10.0)) {
        ME11_ARID_DEF.is_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib = ME11_IN_StepUp;
        ME11_ARID_DEF.Flag_o = true;
      } else if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c8_sTHND1sDWBc7on97EyIGeEG_ME11Lib = ME11_IN_Init_i;
        ME11_ARID_DEF.Flag_o = false;
      }
      break;
    }
  }

  ACTCtl_bMCVlearnFlg = (ME11_ARID_DEF.Flag_a || ME11_ARID_DEF.Flag_o);
  MCV_Mode = Rte_IRead_Task_100ms_C3WV_Mode_C3WV_Mode();
  if (MCV_Mode == 2) {
    ME11_ARID_DEF.Delay1_DSTATE_og = 0U;
  } else if (ACTCtl_bMCVlearnFlg) {
    ME11_ARID_DEF.Delay1_DSTATE_og = 1U;
  }

  if (cal_C3WVSLStsDataEnb) {
    ACTCtl_eC3WVSLSts = cal_C3WVSLStsData;
  } else {
    ACTCtl_eC3WVSLSts = ME11_ARID_DEF.Delay1_DSTATE_og;
  }

  ME11_Chart((BCV_FltSts == 1) || (BCV_FltSts == 2), (uint16)
             (cal_BCVFltStsDelayTime * 10U), &ME11_ARID_DEF.Flag_da,
             &ME11_ARID_DEF.ARID_DEF_Chart_j);
  rtb_Compare_cj1 = ((ACTCtl_eC5WVSLSts <= 0) && rtb_RelationalOperator_lt);
  if (ME11_ARID_DEF.temporalCounter_i1_o < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_o++;
  }

  if (ME11_ARID_DEF.is_active_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib == 0U) {
    ME11_ARID_DEF.is_active_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib = 1U;
    ME11_ARID_DEF.is_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib = ME11_IN_Init_i;
    ME11_ARID_DEF.Flag_d = false;
  } else {
    switch (ME11_ARID_DEF.is_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib) {
     case ME11_IN_Init_i:
      ME11_ARID_DEF.Flag_d = false;
      if (rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_o = 0U;
      }
      break;

     case ME11_IN_StepUp:
      ME11_ARID_DEF.Flag_d = true;
      if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib = ME11_IN_Init_i;
        ME11_ARID_DEF.Flag_d = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_o >= (float32)(60.0 *
           cal_BCVPosDiffDelayTime) * 10.0F) {
        ME11_ARID_DEF.is_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib = ME11_IN_StepUp;
        ME11_ARID_DEF.Flag_d = true;
      } else if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c8_szZQ41pI7cWCrGa5wTuio7D_ME11Lib = ME11_IN_Init_i;
        ME11_ARID_DEF.Flag_d = false;
      }
      break;
    }
  }

  ACTCtl_bBCVlearnFlg = (ME11_ARID_DEF.Flag_da || ME11_ARID_DEF.Flag_d);
  BCV_Mode = Rte_IRead_Task_100ms_C5WVMode_C5WVMode();
  if (BCV_Mode == 2) {
    ME11_ARID_DEF.Delay1_DSTATE_ob = 0U;
  } else if (ACTCtl_bBCVlearnFlg) {
    ME11_ARID_DEF.Delay1_DSTATE_ob = 1U;
  }

  if (cal_C5WVSLStsDataEnb) {
    ACTCtl_eC5WVSLSts = cal_C5WVSLStsData;
  } else {
    ACTCtl_eC5WVSLSts = ME11_ARID_DEF.Delay1_DSTATE_ob;
  }

  if (cal_eC3WVValueEnb) {
    ACTCtl_eC3WVValue = cal_eC3WVValueData;
  } else {
    ACTCtl_eC3WVValue = rtb_Compare_i1;
  }

  if (cal_eC5WVValueEnb) {
    ACTCtl_eC5WVValue = cal_eC5WVValueData;
  } else {
    ACTCtl_eC5WVValue = rtb_Compare_nw0;
  }

  ME11_ARID_DEF.GLB_TMSFaultEXV[0] = rtb_Compare_cwj;
  ME11_ARID_DEF.GLB_TMSFaultEXV[1] = rtb_Compare_l;
  ME11_ARID_DEF.GLB_TMSFaultEXV[2] = rtb_Compare_mcu;
  ME11_ARID_DEF.GLB_TMSFaultEXV[3] = rtb_Compare_ej;
  ME11_ARID_DEF.GLB_TMSFaultEXV[4] = rtb_Compare_ppz;
  ME11_ARID_DEF.GLB_TMSFaultEXV[5] = rtb_Compare_jac;
  ME11_ARID_DEF.GLB_TMSFaultEXV[6] = rtb_Compare_cz;
  ME11_ARID_DEF.GLB_TMSFaultEXV[7] = rtb_Compare_lwc;
  ME11_ARID_DEF.GLB_TMSFaultEXV[8] = rtb_Compare_nzl;
  ME11_ARID_DEF.GLB_TMSFaultEXV[9] = rtb_Compare_jkh;
  ME11_ARID_DEF.GLB_TMSFaultEXV[10] = rtb_Compare_d0e;
  ME11_ARID_DEF.GLB_TMSFaultEXV[11] = rtb_Compare_mwc;
  EXV_CurrentInitState =
    Rte_IRead_Task_100ms_EXV_CurrentInitState_EXV_CurrentInitState();
  if ((ME11_ARID_DEF.Delay1_DSTATE_hw < 2) && (ME11_ARID_DEF.DataTypeConversion1
       >= 2)) {
    ME11_ARID_DEF.Delay_DSTATE_ax = 1U;
  } else if (EXV_CurrentInitState == 2) {
    ME11_ARID_DEF.Delay_DSTATE_ax = 0U;
  } else if (EXV_CurrentInitState == 1) {
    ME11_ARID_DEF.Delay_DSTATE_ax = 2U;
  }

  if (cal_AEXVInitReqDataeEnb) {
    ACTCtl_bAEXVInitReq = cal_AEXVInitReqData;
  } else {
    ACTCtl_bAEXVInitReq = ME11_ARID_DEF.Delay_DSTATE_ax;
  }

  ACTCtl_sAEXVCtrlBFF = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
    &cal_AEXVCtrlBFF_1X[0], (const float32 *)&cal_AEXVCtrlBFF_CUR[0], 4U);
  rtb_DataTypeConversion23 = look1_iflf_binlca(ACSen_sHiPressFilter, (const
    float32 *)&cal_CondDep_1X[0], (const float32 *)&cal_CondDep_CUR[0], 27U);
  ACTCtl_sCoolCondDep = rtb_DataTypeConversion23 - ACSen_sOHXTempFilter;
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_fj != 0) {
    ACTCtl_sCoolCondDepAvg1 = ACTCtl_sCoolCondDep;
  }

  ACTCtl_sCoolCondDepAvg1 = (1.0F - cal_SuperHeatFilter) *
    ACTCtl_sCoolCondDepAvg1 + ACTCtl_sCoolCondDep * cal_SuperHeatFilter;
  ACTCtl_sCoolCondDepAvg = ((((ACTCtl_sCoolCondDep +
    ME11_ARID_DEF.Delay1_DSTATE_h) + ME11_ARID_DEF.Delay_DSTATE_i[0]) +
    ME11_ARID_DEF.Delay2_DSTATE_h[0]) + ME11_ARID_DEF.Delay3_DSTATE_i[0]) / 5.0F;
  if (cal_AvgSwitch) {
    rtb_Switch4_a = ACTCtl_sCoolCondDepAvg1;
  } else {
    rtb_Switch4_a = ACTCtl_sCoolCondDepAvg;
  }

  if (rtb_Switch2_ht == 1) {
    rtb_PI_Cor_d = look1_iflf_binlca(COMP_EcompActSpd, (const float32 *)
      &cal_AEXVCtrlBTrgSubCoolCOMPSpd_1X[0], (const float32 *)
      &cal_AEXVCtrlBTrgSubCoolCOMPSpd_CUR[0], 8U);
  } else {
    rtb_PI_Cor_d = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_AEXVCtrlBTrgSubCool_1X[0], (const float32 *)
      &cal_AEXVCtrlBTrgSubCool_CUR[0], 8U);
  }

  ME11_Descending_filter((rtb_Switch2_ht == 1) || (rtb_Switch2_ht == 3) ||
    (rtb_Switch2_ht == 12) || (rtb_Switch2_ht == 14), rtb_Switch4_a,
    rtb_PI_Cor_d, cal_AEXVSubCoolflt, COMP_EcompActSpd, &ME11_ARID_DEF.Init_m,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter_a);
  ACTCtl_sCondDepDiff = ME11_ARID_DEF.Init_m - rtb_Switch4_a;
  rtb_Add_ax = look1_iflf_binlca(ACSen_sLoPressFilter, (const float32 *)
    &cal_SuperHeat_1X[0], (const float32 *)&cal_SuperHeat_CUR[0], 27U);
  ACTCtl_sEvapSuperHeat = ACSen_sEvapTempFilter - rtb_Add_ax;
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_l != 0) {
    ACTCtl_sEvapSuperHeatAvg1 = ACTCtl_sEvapSuperHeat;
  }

  ACTCtl_sEvapSuperHeatAvg1 = (1.0F - cal_SuperHeatFilter) *
    ACTCtl_sEvapSuperHeatAvg1 + ACTCtl_sEvapSuperHeat * cal_SuperHeatFilter;
  ACTCtl_sEvapSuperHeatAvg = ((((ACTCtl_sEvapSuperHeat +
    ME11_ARID_DEF.Delay1_DSTATE_l) + ME11_ARID_DEF.Delay_DSTATE_bm[0]) +
    ME11_ARID_DEF.Delay2_DSTATE_a[0]) + ME11_ARID_DEF.Delay3_DSTATE_k[0]) / 5.0F;
  if (cal_AvgSwitch) {
    ACTCtl_sAEXVActure = ACTCtl_sEvapSuperHeatAvg1;
  } else {
    ACTCtl_sAEXVActure = ACTCtl_sEvapSuperHeatAvg;
  }

  ME11_Descending_filter(rtb_Switch2_ht == 7, ACTCtl_sAEXVActure,
    look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
                      &cal_AEXVCtrlCTrgtSuperHeat_1X[0], (const float32 *)
                      &cal_AEXVCtrlCTrgtSuperHeat_CUR[0], 6U),
    cal_AEXVCtrlCTrgflt, COMP_EcompActSpd, &ME11_ARID_DEF.Init_n,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter_f);
  switch (rtb_Switch2_ht) {
   case 2:
   case 4:
   case 5:
   case 6:
   case 13:
    rtb_Merge1_m = 0.0F;
    ACTCtl_sHPEXVCtrlFF = 0.0F;
    rtb_Merge = 0.0F;
    ACTCtl_sAEXVSetPoint = 0.0F;
    ACTCtl_sAEXVActure = 0.0F;
    rtb_PI_Cor_d = 0.0F;
    ACTCtl_sAEXVCtrlKp = 0.0F;
    ACTCtl_sAEXVCtrlKi = 0.0F;
    rtb_Add_cy = 0.0F;
    rtb_Merge1 = 0.0F;
    b_previousEvent = 0;
    break;

   case 1:
   case 3:
   case 12:
   case 14:
    switch (rtb_Switch2_ht) {
     case 1:
      rtb_Merge1 = look1_iflf_binlca(COMP_EcompActSpd, (const float32 *)
        &cal_AEXVCtrlBCabinCoolPIMin_1X[0], (const float32 *)
        &cal_AEXVCtrlBCabinCoolPIMin_CUR[0], 5U);
      break;

     case 3:
      rtb_Merge1 = look1_iflf_binlca(COMP_EcompActSpd, (const float32 *)
        &cal_AEXVCtrlBDCoolPIMin_1X[0], (const float32 *)
        &cal_AEXVCtrlBDCoolPIMin_CUR[0], 5U);
      break;

     default:
      rtb_Merge1 = cal_AEXVCtrlBPIMin;
      break;
    }

    rtb_Merge1_m = cal_AEXVCtrlBDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_AEXVCtrlBOpenVal;
    rtb_Merge = ACTCtl_sAEXVCtrlBFF;
    ACTCtl_sAEXVSetPoint = ME11_ARID_DEF.Init_m;
    ACTCtl_sAEXVActure = rtb_Switch4_a;
    rtb_PI_Cor_d = cal_AEXVCtrlBDeadzone;
    ACTCtl_sAEXVCtrlKp = look1_iflf_binlca(ACTCtl_sCondDepDiff, (const float32 *)
      &cal_AEXVCtrlBKp_1X[0], (const float32 *)&cal_AEXVCtrlBKp_CUR[0], 7U);
    ACTCtl_sAEXVCtrlKi = look1_iflf_binlca(ACTCtl_sCondDepDiff, (const float32 *)
      &cal_AEXVCtrlBKi_1X[0], (const float32 *)&cal_AEXVCtrlBKi_CUR[0], 7U);
    rtb_Add_cy = cal_AEXVCtrlBPIMax;
    b_previousEvent = 1;
    break;

   case 7:
    rtb_Merge1 = ME11_ARID_DEF.Init_n - ACTCtl_sAEXVActure;
    rtb_Merge1_m = cal_AEXVCtrlCDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_AEXVCtrlCOpenVal;
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_AEXVCtrlCFF_1X[0], (const float32 *)&cal_AEXVCtrlCFF_CUR[0], 4U);
    ACTCtl_sAEXVSetPoint = ME11_ARID_DEF.Init_n;
    rtb_PI_Cor_d = cal_AEXVCtrlCDeadzone;
    ACTCtl_sAEXVCtrlKp = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_AEXVCtrlCKp_1X[0], (const float32 *)&cal_AEXVCtrlCKp_CUR[0], 6U);
    ACTCtl_sAEXVCtrlKi = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_AEXVCtrlCKi_1X[0], (const float32 *)&cal_AEXVCtrlCKi_CUR[0], 6U);
    rtb_Add_cy = cal_AEXVCtrlCPIMax;
    rtb_Merge1 = cal_AEXVCtrlCPIMin;
    b_previousEvent = 1;
    break;

   case 8:
    ACTCtl_sAEXVSetPoint = look1_iflf_binlca(ACSen_sEnvTempCor, (const float32 *)
      &cal_AEXVCtrlDTrg_1X[0], (const float32 *)&cal_AEXVCtrlDTrg_CUR[0], 2U);
    rtb_Merge1 = ACTCtl_sAEXVSetPoint - ACSen_sEvapSurTemp;
    rtb_Merge1_m = cal_AEXVCtrlDDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_AEXVCtrlDOpenVal;
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_AEXVCtrlDFF_1X[0], (const float32 *)&cal_AEXVCtrlDFF_CUR[0], 4U);
    ACTCtl_sAEXVActure = ACSen_sEvapSurTemp;
    rtb_PI_Cor_d = cal_AEXVCtrlDDeadzone;
    ACTCtl_sAEXVCtrlKp = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_AEXVCtrlDKp_1X[0], (const float32 *)&cal_AEXVCtrlDKp_CUR[0], 7U);
    ACTCtl_sAEXVCtrlKi = look1_iflf_binlca(rtb_Merge1, (const float32 *)
      &cal_AEXVCtrlDKi_1X[0], (const float32 *)&cal_AEXVCtrlDKi_CUR[0], 7U);
    rtb_Add_cy = cal_AEXVCtrlDPIMax;
    rtb_Merge1 = cal_AEXVCtrlDPIMin;
    b_previousEvent = 1;
    break;

   case 10:
    rtb_Merge1_m = cal_AEXVCtrlDefPos;
    ACTCtl_sHPEXVCtrlFF = cal_AEXVCtrlDefPos;
    rtb_Merge = cal_AEXVCtrlDefPos;
    ACTCtl_sAEXVSetPoint = cal_AEXVCtrlDefPos;
    ACTCtl_sAEXVActure = cal_AEXVCtrlDefPos;
    rtb_PI_Cor_d = cal_AEXVCtrlDefPos;
    ACTCtl_sAEXVCtrlKp = cal_AEXVCtrlDefPos;
    ACTCtl_sAEXVCtrlKi = cal_AEXVCtrlDefPos;
    rtb_Add_cy = cal_AEXVCtrlDefPos;
    rtb_Merge1 = cal_AEXVCtrlDefPos;
    b_previousEvent = 0;
    break;

   default:
    rtb_Merge1_m = cal_AEXVCtrlDefaultPos;
    ACTCtl_sHPEXVCtrlFF = cal_AEXVCtrlDefaultPos;
    rtb_Merge = cal_AEXVCtrlDefaultPos;
    ACTCtl_sAEXVSetPoint = cal_AEXVCtrlDefaultPos;
    ACTCtl_sAEXVActure = cal_AEXVCtrlDefaultPos;
    rtb_PI_Cor_d = cal_AEXVCtrlDefaultPos;
    ACTCtl_sAEXVCtrlKp = cal_AEXVCtrlDefaultPos;
    ACTCtl_sAEXVCtrlKi = cal_AEXVCtrlDefaultPos;
    rtb_Add_cy = cal_AEXVCtrlDefaultPos;
    rtb_Merge1 = cal_AEXVCtrlDefaultPos;
    b_previousEvent = 0;
    break;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_ao < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_ao++;
  }

  if (ME11_ARID_DEF.is_active_c47_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c47_ME11 = 1U;
    ME11_ARID_DEF.is_c47_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.PID_Enble_i = false;
    ACTCtl_sAEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    ME11_ARID_DEF.AEXVCtrlEnb = true;
  } else if (ME11_ARID_DEF.is_c47_ME11 == ME11_IN_Init_i) {
    ME11_ARID_DEF.PID_Enble_i = false;
    ME11_ARID_DEF.AEXVCtrlEnb = true;
    if (ME11_ARID_DEF.Delay_DSTATE_kf) {
      ME11_ARID_DEF.is_c47_ME11 = ME11_IN_On_li;
      ME11_ARID_DEF.is_On_n = ME11_IN_OpenCtrl;
      ME11_ARID_DEF.temporalCounter_i1_ao = 0U;
      ACTCtl_sAEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
      ME11_ARID_DEF.AEXVCtrlEnb = true;
    } else {
      ACTCtl_sAEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    }
  } else if (!ME11_ARID_DEF.Delay_DSTATE_kf) {
    ME11_ARID_DEF.is_On_n = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c47_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.PID_Enble_i = false;
    ACTCtl_sAEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    ME11_ARID_DEF.AEXVCtrlEnb = true;
  } else if (ME11_ARID_DEF.is_On_n == ME11_IN_CloseCtrl) {
    ME11_ARID_DEF.PID_Enble_i = true;
    ACTCtl_sAEXVCtrlFF = rtb_Merge;
  } else {
    ME11_ARID_DEF.AEXVCtrlEnb = true;
    if (ME11_ARID_DEF.temporalCounter_i1_ao >= rtb_Merge1_m * 10.0F) {
      ME11_ARID_DEF.is_On_n = ME11_IN_CloseCtrl;
      ME11_ARID_DEF.PID_Enble_i = true;
      ACTCtl_sAEXVCtrlFF = rtb_Merge;
    } else {
      ACTCtl_sAEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    }
  }

  if (cal_AEXVEnbDataEnb) {
    ACTCtl_bAEXVEnb = cal_AEXVEnbData;
  } else {
    ACTCtl_bAEXVEnb = ((ACTCtl_bAEXVInitReq >= 1) || ME11_ARID_DEF.AEXVCtrlEnb);
  }

  ACTCtl_sAEXVDvt = ACTCtl_sAEXVSetPoint - ACTCtl_sAEXVActure;
  ME11_deadzone_h1(ACTCtl_sAEXVDvt, rtb_PI_Cor_d, &rtb_flag_c);
  rtb_Compare_cj1 = (ACTCtl_sAEXVSetPoint >= ACTCtl_sAEXVActure);
  if (rtb_flag_c) {
    ACTCtl_sAEXVDvt = 0.0F;
  } else if (!rtb_Compare_cj1) {
    ACTCtl_sAEXVDvt = ACTCtl_sAEXVActure - ACTCtl_sAEXVSetPoint;
  }

  ACTCtl_bAEXVDvtFlg = !rtb_Compare_cj1;
  ME11_P_NEG(!ACTCtl_bAEXVDvtFlg, ACTCtl_sAEXVDvt, rtb_PI_Cor_d,
             ACTCtl_sAEXVCtrlKi, cal_AEXVCtlKi, (float32 *)&ACTCtl_sAEXVI_Cor);
  ME11_P_POS(ACTCtl_bAEXVDvtFlg, ACTCtl_sAEXVDvt, rtb_PI_Cor_d,
             ACTCtl_sAEXVCtrlKi, cal_AEXVCtlKi, (float32 *)&ACTCtl_sAEXVI_Cor);
  ACTCtl_bAEXVPIEnble = (ME11_ARID_DEF.PID_Enble_i && (b_previousEvent != 0));
  if (ACTCtl_bAEXVPIEnble) {
    switch (ME11_ARID_DEF.Delay_DSTATE_op) {
     case 0:
      if (ACTCtl_bAEXVDvtFlg) {
        ACTCtl_sAEXVI_Sum = ACTCtl_sAEXVI_Sum + ACTCtl_sAEXVI_Cor;
      } else {
        ACTCtl_sAEXVI_Sum = ACTCtl_sAEXVI_Sum - ACTCtl_sAEXVI_Cor;
      }
      break;

     case 1:
      if (!ACTCtl_bAEXVDvtFlg) {
        ACTCtl_sAEXVI_Sum = ACTCtl_sAEXVI_Sum - ACTCtl_sAEXVI_Cor;
      }
      break;

     case 2:
      if (ACTCtl_bAEXVDvtFlg) {
        ACTCtl_sAEXVI_Sum = ACTCtl_sAEXVI_Sum + ACTCtl_sAEXVI_Cor;
      }
      break;

     case 3:
      break;
    }

    if (ACTCtl_sAEXVI_Sum > cal_AEXVCtlKisumMax) {
      ACTCtl_sAEXVI_Sum = cal_AEXVCtlKisumMax;
    } else if (ACTCtl_sAEXVI_Sum < cal_AEXVCtlKisumMin) {
      ACTCtl_sAEXVI_Sum = cal_AEXVCtlKisumMin;
    }
  } else {
    ACTCtl_sAEXVI_Sum = 0.0F;
  }

  ME11_PI_Controller1(!ACTCtl_bAEXVPIEnble, ACTCtl_sAEXVCtrlFF, (float32 *)
                      &ACTCtl_sAEXVPI_Cor, &rtb_IFreezFlag_o);
  ME11_P_NEG_p(!ACTCtl_bAEXVDvtFlg, ACTCtl_sAEXVDvt, rtb_PI_Cor_d,
               ACTCtl_sAEXVCtrlKp, cal_AEXVCtlKp, (float32 *)&ACTCtl_sAEXVP_Cor);
  ME11_P_POS_l(ACTCtl_bAEXVDvtFlg, ACTCtl_sAEXVDvt, rtb_PI_Cor_d,
               ACTCtl_sAEXVCtrlKp, cal_AEXVCtlKp, (float32 *)&ACTCtl_sAEXVP_Cor);
  ME11_PI_Controller(ACTCtl_bAEXVPIEnble, ACTCtl_bAEXVDvtFlg, ACTCtl_sAEXVCtrlFF,
                     ACTCtl_sAEXVP_Cor, ACTCtl_sAEXVI_Sum, rtb_Add_cy,
                     rtb_Merge1, (float32 *)&ACTCtl_sAEXVPI_Cor,
                     &rtb_IFreezFlag_o);
  if (cal_AEXVDiffUp <= ACTCtl_sAEXVPI_Cor - rtb_Merge_g) {
    rtb_PI_Cor_d = cal_AEXVDiffUpRate + rtb_Merge_g;
  } else if (rtb_Merge_g - ACTCtl_sAEXVPI_Cor >= cal_AEXVDiffDown) {
    rtb_PI_Cor_d = rtb_Merge_g - cal_AEXVDiffDownRate;
  } else {
    rtb_PI_Cor_d = ACTCtl_sAEXVPI_Cor;
  }

  ME11_PwrOn(&rtb_flg_f, &ME11_ARID_DEF.ARID_DEF_PwrOn_j);
  if (((ACSen_sLoPressFilter <= cal_AEXVLowPressLmtOn) || (ACSen_sHiPressFilter >=
        cal_AEXVHighPressLmtOn)) && rtb_Compare_mos && (rtb_Merge_g >=
       rtb_PI_Cor_d)) {
    rtb_PI_Cor_d = rtb_Merge_g;
  }

  if (rtb_flg_f) {
    ME11_ARID_DEF.Delay_DSTATE_gn = rtb_PI_Cor_d;
  } else if (rtb_PI_Cor_d > ME11_ARID_DEF.Delay_DSTATE_gn + cal_AEXVUpSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_gn += cal_AEXVUpSpdLmt;
  } else if (rtb_PI_Cor_d < ME11_ARID_DEF.Delay_DSTATE_gn - cal_AEXVDownSpdLmt)
  {
    ME11_ARID_DEF.Delay_DSTATE_gn -= cal_AEXVDownSpdLmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_gn = rtb_PI_Cor_d;
  }

  ME11_PwrOn(&rtb_flg_dg, &ME11_ARID_DEF.ARID_DEF_PwrOn_bj);
  if (rtb_flg_dg) {
    ME11_ARID_DEF.Delay_DSTATE_iw = ACTCtl_sAEXVPI_Cor;
  } else if (ACTCtl_sAEXVPI_Cor > ME11_ARID_DEF.Delay_DSTATE_iw +
             cal_AEXVOpenCtrlUpSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_iw += cal_AEXVOpenCtrlUpSpdLmt;
  } else if (ACTCtl_sAEXVPI_Cor < ME11_ARID_DEF.Delay_DSTATE_iw -
             cal_AEXVOpenCtrlDownSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_iw -= cal_AEXVOpenCtrlDownSpdLmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_iw = ACTCtl_sAEXVPI_Cor;
  }

  if (rtb_IFreezFlag_bd >= 3) {
    ME11_ARID_DEF.Delay_DSTATE_k3 = ME11_ARID_DEF.ACTCtl_sAEXVVal;
  } else if (rtb_IFreezFlag_bd >= 1) {
    ME11_ARID_DEF.Delay_DSTATE_k3 = rtb_Merge_g - cal_AEXVFltClsSpd;
    if (cal_AEXVClsValEvapPrt >= ME11_ARID_DEF.Delay_DSTATE_k3) {
      ME11_ARID_DEF.Delay_DSTATE_k3 = cal_AEXVClsValEvapPrt;
    }
  } else if (((ACSen_sHiPressFilter >= cal_AEXVHighPressProhOn) ||
              (ACSen_sLoPressFilter <= cal_AEXVLowPressProhOn)) &&
             rtb_Compare_mos) {
    ME11_ARID_DEF.Delay_DSTATE_k3 = rtb_Merge_g + cal_AEXVOpenValveSpd;
  } else if (ACTCtl_bAEXVPIEnble) {
    ME11_ARID_DEF.Delay_DSTATE_k3 = ME11_ARID_DEF.Delay_DSTATE_gn;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_k3 = ME11_ARID_DEF.Delay_DSTATE_iw;
  }

  if (cal_AEXVPosDataEnb) {
    ACTCtl_sAEXVPos = cal_AEXVPosData;
  } else {
    ACTCtl_sAEXVPos = (float32)floor(ME11_ARID_DEF.Delay_DSTATE_k3);
    rtb_PI_Cor_d = ME11_ARID_DEF.Delay_DSTATE_k3 - ACTCtl_sAEXVPos;
    if (cal_AEXVFloorDiff2 < rtb_PI_Cor_d) {
      ACTCtl_sAEXVPos = ACTCtl_sAEXVPos + 1.0F;
    } else if (cal_AEXVFloorDiff1 < rtb_PI_Cor_d) {
      ACTCtl_sAEXVPos = ACTCtl_sAEXVPos + 0.5F;
    }
  }

  if (ACTCtl_sAEXVPos > 100.0F) {
    ACTCtl_sAEXVPos = 100.0F;
  } else if (ACTCtl_sAEXVPos < 0.0F) {
    ACTCtl_sAEXVPos = 0.0F;
  }

  ACTCtl_sBEXVCtrlBFF = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
    &cal_BEXVCtrlBFF_1X[0], (const float32 *)&cal_BEXVCtrlBFF_CUR[0], 4U);
  SEN_ChiTRaw = look1_iflf_binlca(rtb_Add, (const float32 *)
    &cal_TChillOutRaw_1X[0], (const float32 *)&cal_TChillOutRaw_CUR[0], 26U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_eg != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_nn = SEN_ChiTRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_nn = SEN_ChiTRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_nn * 0.100000024F;
  if (cal_ChiTempDataEnb) {
    ACSen_sChiTempFilter = cal_ChiTempData;
  } else {
    ACSen_sChiTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_nn;
  }

  ACTCtl_sChiSuperHeat = ACSen_sChiTempFilter - rtb_Add_ax;
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_h != 0) {
    ACTCtl_sChiSuperHeatAvg1 = ACTCtl_sChiSuperHeat;
  }

  ACTCtl_sChiSuperHeatAvg1 = (1.0F - cal_SuperHeatFilter) *
    ACTCtl_sChiSuperHeatAvg1 + ACTCtl_sChiSuperHeat * cal_SuperHeatFilter;
  ACTCtl_sChiSuperHeatAvg = ((((ACTCtl_sChiSuperHeat +
    ME11_ARID_DEF.Delay1_DSTATE_e) + ME11_ARID_DEF.Delay_DSTATE_c[0]) +
    ME11_ARID_DEF.Delay2_DSTATE_k[0]) + ME11_ARID_DEF.Delay3_DSTATE_b[0]) / 5.0F;
  if (cal_AvgSwitch) {
    ACTCtl_sBEXVActure = ACTCtl_sChiSuperHeatAvg1;
  } else {
    ACTCtl_sBEXVActure = ACTCtl_sChiSuperHeatAvg;
  }

  if (ME11_ARID_DEF.DataTypeConversion1 == 4) {
    rtb_LowPressLmt = 0.0F;
  } else {
    rtb_LowPressLmt = look1_iflf_binlca(ACCtl_tLeftDuct -
      ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_dn, (const float32 *)
      &cal_BEXVCtrlBTrgCabinComp_1X[0], (const float32 *)
      &cal_BEXVCtrlBTrgCabinComp_CUR[0], 4U);
  }

  ME11_Descending_filter((rtb_Switch2_ht == 3) || (rtb_Switch2_ht == 14),
    ACTCtl_sBEXVActure, look1_iflf_binlca(BMS_InletCooltActlTemp -
    cal_BatCoolInletTrgTemp, (const float32 *)&cal_BEXVCtrlBTrgWtrTempDiff_1X[0],
    (const float32 *)&cal_BEXVCtrlBTrgWtrTempDiff_CUR[0], 5U) + rtb_LowPressLmt,
    cal_BEXVSubHeatflt, COMP_EcompActSpd, &ME11_ARID_DEF.Init_b1,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter_e);
  ME11_Descending_filter(rtb_Switch2_ht == 2, rtb_Switch4_a, look1_iflf_binlca
    (ACTCtl_sACCMCtlSpd, (const float32 *)&cal_BEXVCtrlCTrg_1X[0], (const
    float32 *)&cal_BEXVCtrlCTrg_CUR[0], 4U), cal_BEXVSubCoolflt,
    COMP_EcompActSpd, &ME11_ARID_DEF.Init_e,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter_d);
  switch (rtb_Switch2_ht) {
   case 1:
   case 4:
   case 5:
   case 6:
   case 7:
   case 8:
   case 12:
    rtb_Merge1_m = 0.0F;
    ACTCtl_sHPEXVCtrlFF = 0.0F;
    rtb_Merge = 0.0F;
    ACTCtl_sBEXVSetPoint = 0.0F;
    ACTCtl_sBEXVActure = 0.0F;
    rtb_PI_Cor_d = 0.0F;
    ACTCtl_sBEXVCtrlKp = 0.0F;
    ACTCtl_sBEXVCtrlKi = 0.0F;
    rtb_Add_cy = 0.0F;
    rtb_Merge1 = 0.0F;
    b_previousEvent = 0;
    break;

   case 3:
   case 14:
    rtb_Add = ME11_ARID_DEF.Init_b1 - ACTCtl_sBEXVActure;
    if (rtb_Switch2_ht == 3) {
      rtb_Merge1 = look1_iflf_binlca(COMP_EcompActSpd, (const float32 *)
        &cal_BEXVCtrlBDCoolPIMin_1X[0], (const float32 *)
        &cal_BEXVCtrlBDCoolPIMin_CUR[0], 5U);
    } else {
      rtb_Merge1 = cal_BEXVCtrlBPIDown;
    }

    rtb_Merge1_m = cal_BEXVCtrlBDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_BEXVCtrlBOpenVal;
    rtb_Merge = ACTCtl_sBEXVCtrlBFF;
    ACTCtl_sBEXVSetPoint = ME11_ARID_DEF.Init_b1;
    rtb_PI_Cor_d = cal_BEXVCtrlBDeadzone;
    ACTCtl_sBEXVCtrlKp = look1_iflf_binlca(rtb_Add, (const float32 *)
      &cal_BEXVCtrlBKp_1X[0], (const float32 *)&cal_BEXVCtrlBKp_CUR[0], 6U);
    ACTCtl_sBEXVCtrlKi = look1_iflf_binlca(rtb_Add, (const float32 *)
      &cal_BEXVCtrlBKi_1X[0], (const float32 *)&cal_BEXVCtrlBKi_CUR[0], 6U);
    rtb_Add_cy = cal_BEXVCtrlBPIUp;
    b_previousEvent = 1;
    break;

   case 2:
   case 13:
    rtb_Add = ME11_ARID_DEF.Init_e - rtb_Switch4_a;
    if (rtb_Switch2_ht == 2) {
      rtb_Merge1 = look1_iflf_binlca(COMP_EcompActSpd, (const float32 *)
        &cal_BEXVCtrlCBatCoolPIMin_1X[0], (const float32 *)
        &cal_BEXVCtrlCBatCoolPIMin_CUR[0], 5U);
    } else {
      rtb_Merge1 = cal_BEXVCtrlCPIMin;
    }

    rtb_Merge1_m = cal_BEXVCtrlCDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_BEXVCtrlCOpenVal;
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_BEXVCtrlCFF_1X[0], (const float32 *)&cal_BEXVCtrlCFF_CUR[0], 4U);
    ACTCtl_sBEXVSetPoint = ME11_ARID_DEF.Init_e;
    ACTCtl_sBEXVActure = rtb_Switch4_a;
    rtb_PI_Cor_d = cal_BEXVCtrlCDeadzone;
    ACTCtl_sBEXVCtrlKp = look1_iflf_binlca(rtb_Add, (const float32 *)
      &cal_BEXVCtrlCKp_1X[0], (const float32 *)&cal_BEXVCtrlCKp_CUR[0], 7U);
    ACTCtl_sBEXVCtrlKi = look1_iflf_binlca(rtb_Add, (const float32 *)
      &cal_BEXVCtrlCKi_1X[0], (const float32 *)&cal_BEXVCtrlCKi_CUR[0], 7U);
    rtb_Add_cy = cal_BEXVCtrlCPIMax;
    b_previousEvent = 1;
    break;

   case 10:
    rtb_Merge1_m = cal_BEXVCtrlDefPos;
    ACTCtl_sHPEXVCtrlFF = cal_BEXVCtrlDefPos;
    rtb_Merge = cal_BEXVCtrlDefPos;
    ACTCtl_sBEXVSetPoint = cal_BEXVCtrlDefPos;
    ACTCtl_sBEXVActure = cal_BEXVCtrlDefPos;
    rtb_PI_Cor_d = cal_BEXVCtrlDefPos;
    ACTCtl_sBEXVCtrlKp = cal_BEXVCtrlDefPos;
    ACTCtl_sBEXVCtrlKi = cal_BEXVCtrlDefPos;
    rtb_Add_cy = cal_BEXVCtrlDefPos;
    rtb_Merge1 = cal_BEXVCtrlDefPos;
    b_previousEvent = 0;
    break;

   default:
    rtb_Merge1_m = 50.0F;
    ACTCtl_sHPEXVCtrlFF = 50.0F;
    rtb_Merge = 50.0F;
    ACTCtl_sBEXVSetPoint = 50.0F;
    ACTCtl_sBEXVActure = 50.0F;
    rtb_PI_Cor_d = 50.0F;
    ACTCtl_sBEXVCtrlKp = 50.0F;
    ACTCtl_sBEXVCtrlKi = 50.0F;
    rtb_Add_cy = 50.0F;
    rtb_Merge1 = 50.0F;
    b_previousEvent = 0;
    break;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_l < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_l++;
  }

  if (ME11_ARID_DEF.is_active_c48_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c48_ME11 = 1U;
    ME11_ARID_DEF.is_c48_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.PID_Enble_b = false;
    ACTCtl_sBEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    ME11_ARID_DEF.BEXVCtrlEnb = true;
  } else if (ME11_ARID_DEF.is_c48_ME11 == ME11_IN_Init_i) {
    ME11_ARID_DEF.PID_Enble_b = false;
    ME11_ARID_DEF.BEXVCtrlEnb = true;
    if (ME11_ARID_DEF.Delay_DSTATE_kf) {
      ME11_ARID_DEF.is_c48_ME11 = ME11_IN_On_li;
      ME11_ARID_DEF.is_On_b = ME11_IN_OpenCtrl;
      ME11_ARID_DEF.temporalCounter_i1_l = 0U;
      ACTCtl_sBEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
      ME11_ARID_DEF.BEXVCtrlEnb = true;
    } else {
      ACTCtl_sBEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    }
  } else if (!ME11_ARID_DEF.Delay_DSTATE_kf) {
    ME11_ARID_DEF.is_On_b = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c48_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.PID_Enble_b = false;
    ACTCtl_sBEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    ME11_ARID_DEF.BEXVCtrlEnb = true;
  } else if (ME11_ARID_DEF.is_On_b == ME11_IN_CloseCtrl) {
    ME11_ARID_DEF.PID_Enble_b = true;
    ACTCtl_sBEXVCtrlFF = rtb_Merge;
  } else {
    ME11_ARID_DEF.BEXVCtrlEnb = true;
    if (ME11_ARID_DEF.temporalCounter_i1_l >= rtb_Merge1_m * 10.0F) {
      ME11_ARID_DEF.is_On_b = ME11_IN_CloseCtrl;
      ME11_ARID_DEF.PID_Enble_b = true;
      ACTCtl_sBEXVCtrlFF = rtb_Merge;
    } else {
      ACTCtl_sBEXVCtrlFF = ACTCtl_sHPEXVCtrlFF;
    }
  }

  ACTCtl_bBEXVPIEnble = (ME11_ARID_DEF.PID_Enble_b && (b_previousEvent != 0));
  BAT_EXV_CurrentInitState_B =
    Rte_IRead_Task_100ms_BAT_EXV_initialize_status_BAT_EXV_initialize_status();
  if ((ME11_ARID_DEF.Delay1_DSTATE_a < 2) && (ME11_ARID_DEF.DataTypeConversion1 >=
       2)) {
    ME11_ARID_DEF.Delay_DSTATE_hqw = 1U;
  } else if (BAT_EXV_CurrentInitState_B == 2) {
    ME11_ARID_DEF.Delay_DSTATE_hqw = 0U;
  } else if (BAT_EXV_CurrentInitState_B == 1) {
    ME11_ARID_DEF.Delay_DSTATE_hqw = 2U;
  }

  if (cal_BEXVInitReqDataeEnb) {
    ACTCtl_bBEXVInitReq = cal_BEXVInitReqData;
  } else {
    ACTCtl_bBEXVInitReq = ME11_ARID_DEF.Delay_DSTATE_hqw;
  }

  ACTCtl_sBEXVDvt = ACTCtl_sBEXVSetPoint - ACTCtl_sBEXVActure;
  ME11_deadzone_h1(ACTCtl_sBEXVDvt, rtb_PI_Cor_d, &rtb_flag_l);
  rtb_Compare_mos = (ACTCtl_sBEXVSetPoint >= ACTCtl_sBEXVActure);
  if (rtb_flag_l) {
    ACTCtl_sBEXVDvt = 0.0F;
  } else if (!rtb_Compare_mos) {
    ACTCtl_sBEXVDvt = ACTCtl_sBEXVActure - ACTCtl_sBEXVSetPoint;
  }

  ACTCtl_bBEXVDvtFlg = !rtb_Compare_mos;
  ME11_P_NEG(!ACTCtl_bBEXVDvtFlg, ACTCtl_sBEXVDvt, rtb_PI_Cor_d,
             ACTCtl_sBEXVCtrlKi, cal_BEXVCtlKi, (float32 *)&ACTCtl_sBEXVI_Cor);
  ME11_P_POS(ACTCtl_bBEXVDvtFlg, ACTCtl_sBEXVDvt, rtb_PI_Cor_d,
             ACTCtl_sBEXVCtrlKi, cal_BEXVCtlKi, (float32 *)&ACTCtl_sBEXVI_Cor);
  if (ACTCtl_bBEXVPIEnble) {
    switch (ME11_ARID_DEF.Delay_DSTATE_bmz) {
     case 0:
      if (ACTCtl_bBEXVDvtFlg) {
        ACTCtl_sBEXVI_Sum = ACTCtl_sBEXVI_Sum + ACTCtl_sBEXVI_Cor;
      } else {
        ACTCtl_sBEXVI_Sum = ACTCtl_sBEXVI_Sum - ACTCtl_sBEXVI_Cor;
      }
      break;

     case 1:
      if (!ACTCtl_bBEXVDvtFlg) {
        ACTCtl_sBEXVI_Sum = ACTCtl_sBEXVI_Sum - ACTCtl_sBEXVI_Cor;
      }
      break;

     case 2:
      if (ACTCtl_bBEXVDvtFlg) {
        ACTCtl_sBEXVI_Sum = ACTCtl_sBEXVI_Sum + ACTCtl_sBEXVI_Cor;
      }
      break;

     case 3:
      break;
    }

    if (ACTCtl_sBEXVI_Sum > cal_BEXVCtlKisumMax) {
      ACTCtl_sBEXVI_Sum = cal_BEXVCtlKisumMax;
    } else if (ACTCtl_sBEXVI_Sum < cal_BEXVCtlKisumMin) {
      ACTCtl_sBEXVI_Sum = cal_BEXVCtlKisumMin;
    }
  } else {
    ACTCtl_sBEXVI_Sum = 0.0F;
  }

  ME11_PI_Controller1(!ACTCtl_bBEXVPIEnble, ACTCtl_sBEXVCtrlFF, (float32 *)
                      &ACTCtl_sBEXVPI_Cor, &rtb_IFreezFlag_m);
  ME11_P_NEG_p(!ACTCtl_bBEXVDvtFlg, ACTCtl_sBEXVDvt, rtb_PI_Cor_d,
               ACTCtl_sBEXVCtrlKp, cal_BEXVCtlKp, (float32 *)&ACTCtl_sBEXVP_Cor);
  ME11_P_POS_l(ACTCtl_bBEXVDvtFlg, ACTCtl_sBEXVDvt, rtb_PI_Cor_d,
               ACTCtl_sBEXVCtrlKp, cal_BEXVCtlKp, (float32 *)&ACTCtl_sBEXVP_Cor);
  ME11_PI_Controller(ACTCtl_bBEXVPIEnble, ACTCtl_bBEXVDvtFlg, ACTCtl_sBEXVCtrlFF,
                     ACTCtl_sBEXVP_Cor, ACTCtl_sBEXVI_Sum, rtb_Add_cy,
                     rtb_Merge1, (float32 *)&ACTCtl_sBEXVPI_Cor,
                     &rtb_IFreezFlag_m);
  if (cal_BEXVEnbDataEnb) {
    ACTCtl_bBEXVEnb = cal_BEXVEnbData;
  } else {
    ACTCtl_bBEXVEnb = ((ACTCtl_bBEXVInitReq >= 1) || ME11_ARID_DEF.BEXVCtrlEnb);
  }

  rtb_Compare_mos = (ME11_ARID_DEF.Delay_DSTATE_kf && ((rtb_Switch2_ht == 2) ||
    (rtb_Switch2_ht == 3) || (rtb_Switch2_ht == 14)));
  if (cal_BEXVDiffUp <= ACTCtl_sBEXVPI_Cor - ME11_ARID_DEF.Delay_DSTATE_l) {
    rtb_PI_Cor_d = cal_BEXVDiffUpRate + ME11_ARID_DEF.Delay_DSTATE_l;
  } else if (ME11_ARID_DEF.Delay_DSTATE_l - ACTCtl_sBEXVPI_Cor >=
             cal_BEXVDiffDown) {
    rtb_PI_Cor_d = ME11_ARID_DEF.Delay_DSTATE_l - cal_BEXVDiffDownRate;
  } else {
    rtb_PI_Cor_d = ACTCtl_sBEXVPI_Cor;
  }

  if (((ACSen_sLoPressFilter <= cal_BEXVLowPressLmtOn) || (ACSen_sHiPressFilter >=
        cal_BEXVHighPressLmtOn)) && rtb_Compare_mos) {
    if (ME11_ARID_DEF.Delay_DSTATE_l >= rtb_PI_Cor_d) {
      rtb_Add = ME11_ARID_DEF.Delay_DSTATE_l;
    } else {
      rtb_Add = rtb_PI_Cor_d;
    }
  } else {
    rtb_Add = rtb_PI_Cor_d;
  }

  ME11_PwrOn(&rtb_flg_o, &ME11_ARID_DEF.ARID_DEF_PwrOn_b);
  if (rtb_flg_o) {
    ME11_ARID_DEF.Delay_DSTATE_c2 = rtb_Add;
  } else if (rtb_Add > ME11_ARID_DEF.Delay_DSTATE_c2 + cal_BEXVUpSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_c2 += cal_BEXVUpSpdLmt;
  } else if (rtb_Add < ME11_ARID_DEF.Delay_DSTATE_c2 - cal_BEXVDownSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_c2 -= cal_BEXVDownSpdLmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_c2 = rtb_Add;
  }

  ME11_PwrOn(&rtb_flg_g, &ME11_ARID_DEF.ARID_DEF_PwrOn_h);
  if (rtb_flg_g) {
    ME11_ARID_DEF.Delay_DSTATE_h0 = ACTCtl_sBEXVPI_Cor;
  } else if (ACTCtl_sBEXVPI_Cor > ME11_ARID_DEF.Delay_DSTATE_h0 +
             cal_BEXVOpenCtrlUpSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_h0 += cal_BEXVOpenCtrlUpSpdLmt;
  } else if (ACTCtl_sBEXVPI_Cor < ME11_ARID_DEF.Delay_DSTATE_h0 -
             cal_BEXVOpenCtrlDownSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_h0 -= cal_BEXVOpenCtrlDownSpdLmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_h0 = ACTCtl_sBEXVPI_Cor;
  }

  if ((ACSen_sHiPressFilter >= cal_BEXVHighPressProhOn) || (ACSen_sLoPressFilter
       <= cal_BEXVLowPressProhOn)) {
    ME11_ARID_DEF.Delay_DSTATE_l += cal_BEXVOpenValveSpd;
  } else if (ACTCtl_bBEXVPIEnble) {
    ME11_ARID_DEF.Delay_DSTATE_l = ME11_ARID_DEF.Delay_DSTATE_c2;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_l = ME11_ARID_DEF.Delay_DSTATE_h0;
  }

  if (cal_BEXVPosDataEnb) {
    ACTCtl_sBEXVPos = cal_BEXVPosData;
  } else {
    if (rtb_Compare_mos) {
      rtb_PI_Cor_d = ME11_ARID_DEF.Delay_DSTATE_l;
    }

    ACTCtl_sBEXVPos = (float32)floor(rtb_PI_Cor_d);
    rtb_PI_Cor_d -= ACTCtl_sBEXVPos;
    if (cal_BEXVFloorDiff2 < rtb_PI_Cor_d) {
      ACTCtl_sBEXVPos = ACTCtl_sBEXVPos + 1.0F;
    } else if (cal_BEXVFloorDiff1 < rtb_PI_Cor_d) {
      ACTCtl_sBEXVPos = ACTCtl_sBEXVPos + 0.5F;
    }
  }

  if (ACTCtl_sBEXVPos > 100.0F) {
    ACTCtl_sBEXVPos = 100.0F;
  } else if (ACTCtl_sBEXVPos < 0.0F) {
    ACTCtl_sBEXVPos = 0.0F;
  }

  rtb_PI_Cor_d = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
    &cal_HPEXVCtrlATrgtSubcool_1X[0], (const float32 *)
    &cal_HPEXVCtrlATrgtSubcool_CUR[0], 4U);
  SEN_WCCTHiRaw = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
    &cal_TLCCOutRaw_1X[0], (const float32 *)&cal_TLCCOutRaw_CUR[0], 19U);
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_fz != 0) {
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a3 = SEN_WCCTHiRaw;
  }

  ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a3 = SEN_WCCTHiRaw * 0.9F +
    ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a3 * 0.100000024F;
  if (cal_WCCTempDataEnb) {
    ACSen_sWCCHiTempFilter = cal_WCCTempData;
  } else {
    ACSen_sWCCHiTempFilter = ME11_ARID_DEF.FixPtUnitDelay1_DSTATE_a3;
  }

  ACTCtl_sCondDep = rtb_DataTypeConversion23 - ACSen_sWCCHiTempFilter;
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kg != 0) {
    ACTCtl_sCondDepAvg1 = ACTCtl_sCondDep;
  }

  ACTCtl_sCondDepAvg1 = (1.0F - cal_CondDepFilter) * ACTCtl_sCondDepAvg1 +
    ACTCtl_sCondDep * cal_CondDepFilter;
  ACTCtl_sCondDepAvg = ((((ACTCtl_sCondDep + ME11_ARID_DEF.Delay1_DSTATE_gh) +
    ME11_ARID_DEF.Delay_DSTATE_hl[0]) + ME11_ARID_DEF.Delay2_DSTATE_n[0]) +
                        ME11_ARID_DEF.Delay3_DSTATE_ks[0]) / 5.0F;
  if (cal_AvgSwitch) {
    ACTCtl_sHPEXVActure = ACTCtl_sCondDepAvg1;
  } else {
    ACTCtl_sHPEXVActure = ACTCtl_sCondDepAvg;
  }

  ME11_Descending_filter((rtb_Switch2_ht == 4) || (rtb_Switch2_ht == 5) ||
    (rtb_Switch2_ht == 6), cal_HPEXVCtrlATrgFilterVal, rtb_PI_Cor_d,
    cal_HPEXVSubCoolflt_CUR[plook_u32f_binckan(ACTCtl_sHPEXVActure -
    rtb_PI_Cor_d, (const float32 *)&cal_HPEXVSubCoolflt_1X[0], 5U)],
    COMP_EcompActSpd, &ME11_ARID_DEF.Init_b,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter_b);
  ACTCtl_sHPEXVCtrlADiff = ME11_ARID_DEF.Init_b - ACTCtl_sHPEXVActure;
  ME11_Descending_filter(rtb_Switch2_ht == 8, ACTCtl_sHPEXVActure,
    look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
                      &cal_HPEXVCtrlDTrgtSubcool_1X[0], (const float32 *)
                      &cal_HPEXVCtrlDTrgtSubcool_CUR[0], 4U),
    cal_HPEXVSubCoolflt, COMP_EcompActSpd, &ME11_ARID_DEF.Init_h,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter_n);
  ME11_Descending_filter(rtb_Switch2_ht == 13, ACTCtl_sHPEXVActure,
    look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
                      &cal_HPEXVCtrlETrgtSubcool_1X[0], (const float32 *)
                      &cal_HPEXVCtrlETrgtSubcool_CUR[0], 4U),
    cal_HPEXVSubCoolflt, COMP_EcompActSpd, &ME11_ARID_DEF.Init,
    &ME11_ARID_DEF.ARID_DEF_Descending_filter);
  switch (rtb_Switch2_ht) {
   case 4:
   case 5:
   case 6:
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_HPEXVCtrlAFF_1X[0], (const float32 *)&cal_HPEXVCtrlAFF_CUR[0], 4U);
    rtb_Merge1_m = cal_HPEXVCtrlADelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_HPEXVCtrlAOpenVal;
    if (rtb_Merge > cal_HPEXVCtrlAFFUplmt) {
      rtb_Merge = cal_HPEXVCtrlAFFUplmt;
    } else if (rtb_Merge < cal_HPEXVCtrlAFFLolmt) {
      rtb_Merge = cal_HPEXVCtrlAFFLolmt;
    }

    ACTCtl_sHPEXVSetPoint = ME11_ARID_DEF.Init_b;
    rtb_PI_Cor_d = cal_HPEXVCtrlADeadzone;
    ACTCtl_sHPEXVCtrlKp = look1_iflf_binlca(ACTCtl_sHPEXVCtrlADiff, (const
      float32 *)&cal_HPEXVCtrlAKp_1X[0], (const float32 *)&cal_HPEXVCtrlAKp_CUR
      [0], 11U);
    ACTCtl_sHPEXVCtrlKi = look1_iflf_binlca(ACTCtl_sHPEXVCtrlADiff, (const
      float32 *)&cal_HPEXVCtrlAKi_1X[0], (const float32 *)&cal_HPEXVCtrlAKi_CUR
      [0], 10U);
    rtb_Add_cy = cal_HPEXVCtrlAMax;
    rtb_Merge1 = cal_HPEXVCtrlAMin;
    b_previousEvent = 1;
    break;

   case 1:
   case 2:
   case 3:
   case 12:
   case 14:
    rtb_Merge1_m = 100.0F;
    ACTCtl_sHPEXVCtrlFF = 100.0F;
    rtb_Merge = 100.0F;
    ACTCtl_sHPEXVSetPoint = 0.0F;
    ACTCtl_sHPEXVActure = 0.0F;
    rtb_PI_Cor_d = 1.0F;
    ACTCtl_sHPEXVCtrlKp = 0.0F;
    ACTCtl_sHPEXVCtrlKi = 0.0F;
    rtb_Add_cy = 100.0F;
    rtb_Merge1 = 100.0F;
    b_previousEvent = 0;
    break;

   case 7:
    rtb_Delay_ci = ACCtl_tSetPointPTC -
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C;
    rtb_Merge1_m = cal_HPEXVCtrlCDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_HPEXVCtrlCOpenVal;
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_HPEXVCtrlCFF_1X[0], (const float32 *)&cal_HPEXVCtrlCFF_CUR[0], 4U);
    ACTCtl_sHPEXVSetPoint = ACCtl_tSetPointPTC;
    ACTCtl_sHPEXVActure =
      (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
      ->VIPM_HVCHOutlTemp_C;
    rtb_PI_Cor_d = cal_HPEXVCtrlCDeadzone;
    ACTCtl_sHPEXVCtrlKp = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
      &cal_HPEXVCtrlCKp_1X[0], (const float32 *)&cal_HPEXVCtrlCKp_CUR[0], 7U);
    ACTCtl_sHPEXVCtrlKi = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
      &cal_HPEXVCtrlCKi_1X[0], (const float32 *)&cal_HPEXVCtrlCKi_CUR[0], 7U);
    rtb_Add_cy = cal_HPEXVCtrlCMax;
    rtb_Merge1 = cal_HPEXVCtrlCMin;
    b_previousEvent = 1;
    break;

   case 8:
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_HPEXVCtrlDFF_1X[0], (const float32 *)&cal_HPEXVCtrlDFF_CUR[0], 4U);
    rtb_Delay_ci = ME11_ARID_DEF.Init_h - ACTCtl_sHPEXVActure;
    rtb_Merge1_m = cal_HPEXVCtrlDDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_HPEXVCtrlDOpenVal;
    if (rtb_Merge > cal_HPEXVCtrlDFFUplmt) {
      rtb_Merge = cal_HPEXVCtrlDFFUplmt;
    } else if (rtb_Merge < cal_HPEXVCtrlDFFLolmt) {
      rtb_Merge = cal_HPEXVCtrlDFFLolmt;
    }

    ACTCtl_sHPEXVSetPoint = ME11_ARID_DEF.Init_h;
    rtb_PI_Cor_d = cal_HPEXVCtrlDDeadzone;
    ACTCtl_sHPEXVCtrlKp = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
      &cal_HPEXVCtrlDKp_1X[0], (const float32 *)&cal_HPEXVCtrlDKp_CUR[0], 7U);
    ACTCtl_sHPEXVCtrlKi = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
      &cal_HPEXVCtrlDKi_1X[0], (const float32 *)&cal_HPEXVCtrlDKi_CUR[0], 7U);
    rtb_Add_cy = cal_HPEXVCtrlDMax;
    rtb_Merge1 = cal_HPEXVCtrlDMin;
    b_previousEvent = 1;
    break;

   case 13:
    rtb_Merge = look1_iflf_binlca(ACTCtl_sACCMCtlSpd, (const float32 *)
      &cal_HPEXVCtrlEFF_1X[0], (const float32 *)&cal_HPEXVCtrlEFF_CUR[0], 4U);
    rtb_Delay_ci = (float32)fabs(ME11_ARID_DEF.Init - ACTCtl_sHPEXVActure);
    rtb_Merge1_m = cal_HPEXVCtrlEDelayTime;
    ACTCtl_sHPEXVCtrlFF = cal_HPEXVCtrlEOpenVal;
    if (rtb_Merge > cal_HPEXVCtrlEFFUplmt) {
      rtb_Merge = cal_HPEXVCtrlEFFUplmt;
    } else if (rtb_Merge < cal_HPEXVCtrlEFFLolmt) {
      rtb_Merge = cal_HPEXVCtrlEFFLolmt;
    }

    ACTCtl_sHPEXVSetPoint = ME11_ARID_DEF.Init;
    rtb_PI_Cor_d = cal_HPEXVCtrlEDeadzone;
    ACTCtl_sHPEXVCtrlKp = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
      &cal_HPEXVCtrlEKp_1X[0], (const float32 *)&cal_HPEXVCtrlEKp_CUR[0], 5U);
    ACTCtl_sHPEXVCtrlKi = look1_iflf_binlca(rtb_Delay_ci, (const float32 *)
      &cal_HPEXVCtrlEKi_1X[0], (const float32 *)&cal_HPEXVCtrlEKi_CUR[0], 5U);
    rtb_Add_cy = cal_HPEXVCtrlEMax;
    rtb_Merge1 = cal_HPEXVCtrlEMin;
    b_previousEvent = 1;
    break;

   case 10:
    rtb_Merge1_m = 0.0F;
    ACTCtl_sHPEXVCtrlFF = 100.0F;
    rtb_Merge = 100.0F;
    ACTCtl_sHPEXVSetPoint = 0.0F;
    ACTCtl_sHPEXVActure = 0.0F;
    rtb_PI_Cor_d = 0.0F;
    ACTCtl_sHPEXVCtrlKp = 0.0F;
    ACTCtl_sHPEXVCtrlKi = 0.0F;
    rtb_Add_cy = 100.0F;
    rtb_Merge1 = 100.0F;
    b_previousEvent = 0;
    break;

   default:
    rtb_Merge1_m = 0.0F;
    ACTCtl_sHPEXVCtrlFF = 50.0F;
    rtb_Merge = 50.0F;
    ACTCtl_sHPEXVSetPoint = 0.0F;
    ACTCtl_sHPEXVActure = 0.0F;
    rtb_PI_Cor_d = 0.0F;
    ACTCtl_sHPEXVCtrlKp = 0.0F;
    ACTCtl_sHPEXVCtrlKi = 0.0F;
    rtb_Add_cy = 50.0F;
    rtb_Merge1 = 50.0F;
    b_previousEvent = 0;
    break;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_d < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_d++;
  }

  if (ME11_ARID_DEF.is_active_c6_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c6_ME11 = 1U;
    ME11_ARID_DEF.is_c6_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.PID_Enble = false;
    ME11_ARID_DEF.HPEXVCtrlEnb = true;
  } else if (ME11_ARID_DEF.is_c6_ME11 == ME11_IN_Init_i) {
    ME11_ARID_DEF.PID_Enble = false;
    ME11_ARID_DEF.HPEXVCtrlEnb = true;
    if (ME11_ARID_DEF.Delay_DSTATE_kf) {
      ME11_ARID_DEF.is_c6_ME11 = ME11_IN_On_li;
      ME11_ARID_DEF.is_On_i = ME11_IN_OpenCtrl;
      ME11_ARID_DEF.temporalCounter_i1_d = 0U;
      ME11_ARID_DEF.HPEXVCtrlEnb = true;
    }
  } else if (!ME11_ARID_DEF.Delay_DSTATE_kf) {
    ME11_ARID_DEF.is_On_i = ME11_IN_NO_ACTIVE_CHILD_gl;
    ME11_ARID_DEF.is_c6_ME11 = ME11_IN_Init_i;
    ME11_ARID_DEF.PID_Enble = false;
    ME11_ARID_DEF.HPEXVCtrlEnb = true;
  } else if (ME11_ARID_DEF.is_On_i == ME11_IN_CloseCtrl) {
    ME11_ARID_DEF.PID_Enble = true;
    ACTCtl_sHPEXVCtrlFF = rtb_Merge;
  } else {
    ME11_ARID_DEF.HPEXVCtrlEnb = true;
    if (ME11_ARID_DEF.temporalCounter_i1_d >= rtb_Merge1_m * 10.0F) {
      ME11_ARID_DEF.is_On_i = ME11_IN_CloseCtrl;
      ME11_ARID_DEF.PID_Enble = true;
      ACTCtl_sHPEXVCtrlFF = rtb_Merge;
    }
  }

  ACTCtl_bHPEXVPIEnble = (ME11_ARID_DEF.PID_Enble && (b_previousEvent != 0));
  ME11_ARID_DEF.LowProRelay_Mode = ((ACSen_sLoPressFilter >=
    cal_HPEXVlowPressProhOff) || ((ACSen_sLoPressFilter >
    cal_HPEXVlowPressProhOn) && ME11_ARID_DEF.LowProRelay_Mode));
  ACTCtl_bLowPressProFlg = (ME11_ARID_DEF.Delay_DSTATE_kf &&
    (!ME11_ARID_DEF.LowProRelay_Mode));
  ME11_ARID_DEF.HiProRelay_Mode = ((ACSen_sHiPressFilter >=
    cal_HPEXVHiPressProhOn) || ((ACSen_sHiPressFilter > cal_HPEXVHiPressProhOff)
    && ME11_ARID_DEF.HiProRelay_Mode));
  ACTCtl_bHiPressProFlg = (ME11_ARID_DEF.Delay_DSTATE_kf &&
    ME11_ARID_DEF.HiProRelay_Mode);
  ME11_PI_Controller1(!ACTCtl_bHPEXVPIEnble, ACTCtl_sHPEXVCtrlFF, (float32 *)
                      &ACTCtl_sHPEXVPI_Cor, &rtb_IFreezFlag_c);
  ME11_ARID_DEF.HiPressLmt_Mode = ((ACSen_sWCCHiTempFilter >=
    cal_HPEXVHiPressLmtOn) || ((ACSen_sWCCHiTempFilter > cal_HPEXVHiPressLmtOff)
    && ME11_ARID_DEF.HiPressLmt_Mode));
  ME11_ARID_DEF.LowPressLmt_Mode = ((ACSen_sLoPressFilter >=
    cal_HPEXVLowPressLmtOff) || ((ACSen_sLoPressFilter > cal_HPEXVLowPressLmtOn)
    && ME11_ARID_DEF.LowPressLmt_Mode));
  if (ME11_ARID_DEF.HiPressLmt_Mode && (!ME11_ARID_DEF.LowPressLmt_Mode)) {
    ACTCtl_sHPEXVSetPoint = cal_HPEXVlowPressLmtTrg;
  }

  rtb_Compare_mos = (ACTCtl_sHPEXVSetPoint >= ACTCtl_sHPEXVActure);
  ACTCtl_bHPEXVDvtFlg = !rtb_Compare_mos;
  ACTCtl_sHPEXVDvt = ACTCtl_sHPEXVSetPoint - ACTCtl_sHPEXVActure;
  ME11_deadzone_h1(ACTCtl_sHPEXVDvt, rtb_PI_Cor_d, &rtb_flag);
  if (rtb_flag) {
    ACTCtl_sHPEXVDvt = 0.0F;
  } else if (!rtb_Compare_mos) {
    ACTCtl_sHPEXVDvt = ACTCtl_sHPEXVActure - ACTCtl_sHPEXVSetPoint;
  }

  ME11_P_NEG_p(!ACTCtl_bHPEXVDvtFlg, ACTCtl_sHPEXVDvt, cal_HPEXVCtlKpDeadzoneNeg,
               ACTCtl_sHPEXVCtrlKp, cal_HPEXVCtlKp, (float32 *)
               &ACTCtl_sHPEXVP_Cor);
  ME11_P_POS_l(ACTCtl_bHPEXVDvtFlg, ACTCtl_sHPEXVDvt, cal_HPEXVCtlKpDeadzonePos,
               ACTCtl_sHPEXVCtrlKp, cal_HPEXVCtlKp, (float32 *)
               &ACTCtl_sHPEXVP_Cor);
  ME11_P_NEG(!ACTCtl_bHPEXVDvtFlg, ACTCtl_sHPEXVDvt, cal_HPEXVCtlKiDeadzoneNeg,
             ACTCtl_sHPEXVCtrlKi, cal_HPEXVCtlKi, (float32 *)&ACTCtl_sHPEXVI_Cor);
  ME11_P_POS(ACTCtl_bHPEXVDvtFlg, ACTCtl_sHPEXVDvt, cal_HPEXVCtlKiDeadzonePos,
             ACTCtl_sHPEXVCtrlKi, cal_HPEXVCtlKi, (float32 *)&ACTCtl_sHPEXVI_Cor);
  if (ACTCtl_bHPEXVPIEnble) {
    switch (ME11_ARID_DEF.Delay_DSTATE_nb) {
     case 0:
      if (ACTCtl_bHPEXVDvtFlg) {
        ACTCtl_sHPEXVI_Sum = ACTCtl_sHPEXVI_Sum + ACTCtl_sHPEXVI_Cor;
      } else {
        ACTCtl_sHPEXVI_Sum = ACTCtl_sHPEXVI_Sum - ACTCtl_sHPEXVI_Cor;
      }
      break;

     case 1:
      if (!ACTCtl_bHPEXVDvtFlg) {
        ACTCtl_sHPEXVI_Sum = ACTCtl_sHPEXVI_Sum - ACTCtl_sHPEXVI_Cor;
      }
      break;

     case 2:
      if (ACTCtl_bHPEXVDvtFlg) {
        ACTCtl_sHPEXVI_Sum = ACTCtl_sHPEXVI_Sum + ACTCtl_sHPEXVI_Cor;
      }
      break;

     case 3:
      break;
    }

    if (ACTCtl_sHPEXVI_Sum > cal_HPEXVCtlKisumMax) {
      ACTCtl_sHPEXVI_Sum = cal_HPEXVCtlKisumMax;
    } else if (ACTCtl_sHPEXVI_Sum < cal_HPEXVCtlKisumMin) {
      ACTCtl_sHPEXVI_Sum = cal_HPEXVCtlKisumMin;
    }
  } else {
    ACTCtl_sHPEXVI_Sum = 0.0F;
  }

  ME11_PI_Controller(ACTCtl_bHPEXVPIEnble, ACTCtl_bHPEXVDvtFlg,
                     ACTCtl_sHPEXVCtrlFF, ACTCtl_sHPEXVP_Cor, ACTCtl_sHPEXVI_Sum,
                     rtb_Add_cy, rtb_Merge1, (float32 *)&ACTCtl_sHPEXVPI_Cor,
                     &rtb_IFreezFlag_c);
  if (cal_HPEXVDiffUp <= ACTCtl_sHPEXVPI_Cor - ME11_ARID_DEF.Delay_DSTATE_ny) {
    rtb_PI_Cor_d = cal_HPEXVDiffUpRate + ME11_ARID_DEF.Delay_DSTATE_ny;
  } else if (ME11_ARID_DEF.Delay_DSTATE_ny - ACTCtl_sHPEXVPI_Cor >=
             cal_HPEXVDiffDown) {
    rtb_PI_Cor_d = ME11_ARID_DEF.Delay_DSTATE_ny - cal_HPEXVDiffDownRate;
  } else {
    rtb_PI_Cor_d = ACTCtl_sHPEXVPI_Cor;
  }

  ME11_PwrOn(&rtb_flg_d, &ME11_ARID_DEF.ARID_DEF_PwrOn_l);
  if (rtb_flg_d) {
    ME11_ARID_DEF.Delay_DSTATE_hq = rtb_PI_Cor_d;
  } else if (rtb_PI_Cor_d > ME11_ARID_DEF.Delay_DSTATE_hq + cal_HPEXVUpSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_hq += cal_HPEXVUpSpdLmt;
  } else if (rtb_PI_Cor_d < ME11_ARID_DEF.Delay_DSTATE_hq - cal_HPEXVDownSpdLmt)
  {
    ME11_ARID_DEF.Delay_DSTATE_hq -= cal_HPEXVDownSpdLmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_hq = rtb_PI_Cor_d;
  }

  ME11_PwrOn(&rtb_flg, &ME11_ARID_DEF.ARID_DEF_PwrOn);
  if (rtb_flg) {
    ME11_ARID_DEF.Delay_DSTATE_iy = ACTCtl_sHPEXVPI_Cor;
  } else if (ACTCtl_sHPEXVPI_Cor > ME11_ARID_DEF.Delay_DSTATE_iy +
             cal_HPEXVOpenCtrlUpSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_iy += cal_HPEXVOpenCtrlUpSpdLmt;
  } else if (ACTCtl_sHPEXVPI_Cor < ME11_ARID_DEF.Delay_DSTATE_iy -
             cal_HPEXVOpenCtrlDownSpdLmt) {
    ME11_ARID_DEF.Delay_DSTATE_iy -= cal_HPEXVOpenCtrlDownSpdLmt;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_iy = ACTCtl_sHPEXVPI_Cor;
  }

  if (ACTCtl_bLowPressProFlg && ACTCtl_bHiPressProFlg) {
    if (cal_HPEXVLowPressProOpenSpd >= cal_HPEXVHiPressProOpenSpd) {
      rtb_MultiportSwitch2_e = cal_HPEXVLowPressProOpenSpd;
    } else {
      rtb_MultiportSwitch2_e = cal_HPEXVHiPressProOpenSpd;
    }

    ME11_ARID_DEF.Delay_DSTATE_ny += rtb_MultiportSwitch2_e;
  } else if (ACTCtl_bLowPressProFlg) {
    ME11_ARID_DEF.Delay_DSTATE_ny += cal_HPEXVLowPressProOpenSpd;
  } else if (ACTCtl_bHiPressProFlg) {
    ME11_ARID_DEF.Delay_DSTATE_ny += cal_HPEXVHiPressProOpenSpd;
  } else if (ACTCtl_bHPEXVPIEnble) {
    ME11_ARID_DEF.Delay_DSTATE_ny = ME11_ARID_DEF.Delay_DSTATE_hq;
  } else {
    ME11_ARID_DEF.Delay_DSTATE_ny = ME11_ARID_DEF.Delay_DSTATE_iy;
  }

  ACTCtl_sHPEXVStepLmt = (float32)floor(ME11_ARID_DEF.Delay_DSTATE_ny);
  rtb_PI_Cor_d = ME11_ARID_DEF.Delay_DSTATE_ny - ACTCtl_sHPEXVStepLmt;
  if (cal_HPEXVFloorDiff2 < rtb_PI_Cor_d) {
    ACTCtl_sHPEXVStepLmt = ACTCtl_sHPEXVStepLmt + 1.0F;
  } else if (cal_HPEXVFloorDiff1 < rtb_PI_Cor_d) {
    ACTCtl_sHPEXVStepLmt = ACTCtl_sHPEXVStepLmt + 0.5F;
  }

  if (cal_HPEXVPosDataEnb) {
    ACTCtl_sHPEXVPos = cal_HPEXVPosData;
  } else if (cal_HPEXVStepLmtSw) {
    ACTCtl_sHPEXVPos = ACTCtl_sHPEXVStepLmt;
  } else {
    ACTCtl_sHPEXVPos = ME11_ARID_DEF.Delay_DSTATE_ny;
  }

  if (ACTCtl_sHPEXVPos > 100.0F) {
    ACTCtl_sHPEXVPos = 100.0F;
  } else if (ACTCtl_sHPEXVPos < 0.0F) {
    ACTCtl_sHPEXVPos = 0.0F;
  }

  HP_EXV_initialize_status =
    Rte_IRead_Task_100ms_HP_EXV_initialize_status_HP_EXV_initialize_status();
  if ((ME11_ARID_DEF.Delay1_DSTATE_gf < 2) && (ME11_ARID_DEF.DataTypeConversion1
       >= 2)) {
    ME11_ARID_DEF.Delay_DSTATE_kr = 1U;
  } else if (HP_EXV_initialize_status == 2) {
    ME11_ARID_DEF.Delay_DSTATE_kr = 0U;
  } else if (HP_EXV_initialize_status == 1) {
    ME11_ARID_DEF.Delay_DSTATE_kr = 2U;
  }

  if (cal_HPEXVInitReqDataeEnb) {
    ACTCtl_bHPEXVInitReq = cal_HPEXVInitReqData;
  } else {
    ACTCtl_bHPEXVInitReq = ME11_ARID_DEF.Delay_DSTATE_kr;
  }

  if (cal_HPEXVEnbDataEnb) {
    ACTCtl_bHPEXVEnb = cal_HPEXVEnbData;
  } else {
    ACTCtl_bHPEXVEnb = ((ACTCtl_bHPEXVInitReq >= 1) ||
                        ME11_ARID_DEF.HPEXVCtrlEnb);
  }

  ACTCtl_sSuperHeat = ACSen_sOHXTempFilter - rtb_Add_ax;
  ACTCtl_sExhSuperHeat = ACSen_sACCMHiTempFilter - rtb_DataTypeConversion23;
  ACTCtl_sExhSuperHeatAvg = ((((ACTCtl_sExhSuperHeat +
    ME11_ARID_DEF.Delay1_DSTATE_c) + ME11_ARID_DEF.Delay_DSTATE_l3[0]) +
    ME11_ARID_DEF.Delay2_DSTATE_p[0]) + ME11_ARID_DEF.Delay3_DSTATE_ij[0]) /
    5.0F;
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nk != 0) {
    ACTCtl_sExhSuperHeatAvg1 = ACTCtl_sExhSuperHeat;
  }

  ACTCtl_sExhSuperHeatAvg1 = (1.0F - cal_ExhSuperHeatFilter) *
    ACTCtl_sExhSuperHeatAvg1 + ACTCtl_sExhSuperHeat * cal_ExhSuperHeatFilter;
  ACTCtl_sSuperHeatAvg = ((((ACTCtl_sSuperHeat + ME11_ARID_DEF.Delay1_DSTATE_lt)
    + ME11_ARID_DEF.Delay_DSTATE_aj[0]) + ME11_ARID_DEF.Delay2_DSTATE_f[0]) +
    ME11_ARID_DEF.Delay3_DSTATE_kc[0]) / 5.0F;
  if (ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ak != 0) {
    ACTCtl_sSuperHeatAvg1 = ACTCtl_sSuperHeat;
  }

  ACTCtl_sSuperHeatAvg1 = (1.0F - cal_SuperHeatFilter) * ACTCtl_sSuperHeatAvg1 +
    ACTCtl_sSuperHeat * cal_SuperHeatFilter;
  ME11_ARID_DEF.GLB_TMSFaultPTC[0] = (uint8)
    (Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
    ->VIPM_HVCHFltCod_enum;
  ME11_ARID_DEF.GLB_TMSFaultPTC[1] = rtb_OR2_a;
  ME11_ARID_DEF.GLB_TMSFaultPTC[2] = rtb_Compare_dsx;
  ME11_ARID_DEF.GLB_TMSFaultPTC[3] = (uint8)
    !ME11_ARID_DEF.ACTCtl_bAcPMPRunFFForPTC;
  if (cal_PTCEnableDataEnb) {
    ACTCtl_sPTCEnable = cal_PTCEnableData;
  } else if (rtb_Compare_ny && (ACTCtl_sPTCRequestTemp > 0.0F)) {
    ACTCtl_sPTCEnable = 3U;
  } else {
    ACTCtl_sPTCEnable = 0U;
  }

  if (ME11_ARID_DEF.temporalCounter_i1_pz < 4095U) {
    ME11_ARID_DEF.temporalCounter_i1_pz++;
  }

  if (ME11_ARID_DEF.is_active_c122_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c122_ME11 = 1U;
    ME11_ARID_DEF.is_c122_ME11 = ME11_IN_Init_o;
    ME11_ARID_DEF.ACTCtl_sPTCPwrDeal = ACTCtl_sPTCReqPower;
  } else if (ME11_ARID_DEF.is_c122_ME11 == ME11_IN_Dec) {
    if (ACTCtl_sPTCEnable == 1) {
      ME11_ARID_DEF.is_Dec_g = ME11_IN_NO_ACTIVE_CHILD_gl;
      ME11_ARID_DEF.is_c122_ME11 = ME11_IN_Init_o;
      ME11_ARID_DEF.ACTCtl_sPTCPwrDeal = ACTCtl_sPTCReqPower;
    } else if (ME11_ARID_DEF.is_Dec_g == ME11_IN_Act) {
      if (ME11_ARID_DEF.temporalCounter_i1_pz >= cal_PTCDelOffTime * 10) {
        ME11_ARID_DEF.is_Dec_g = ME11_IN_wait_d;
      }
    } else {
      ME11_ARID_DEF.is_Dec_g = ME11_IN_Act;
      ME11_ARID_DEF.temporalCounter_i1_pz = 0U;
      ME11_ARID_DEF.ACTCtl_sPTCPwrDeal = ACTCtl_sPTCReqPower - cal_PTCPwrOffFlt;
    }
  } else if (ACTCtl_sPTCEnable == 0) {
    ME11_ARID_DEF.is_c122_ME11 = ME11_IN_Dec;
    ME11_ARID_DEF.is_Dec_g = ME11_IN_Act;
    ME11_ARID_DEF.temporalCounter_i1_pz = 0U;
    ME11_ARID_DEF.ACTCtl_sPTCPwrDeal = ACTCtl_sPTCReqPower - cal_PTCPwrOffFlt;
  } else {
    ME11_ARID_DEF.ACTCtl_sPTCPwrDeal = ACTCtl_sPTCReqPower;
  }

  ACTCtl_sSOCHighPTCPwrLmt = look1_iflf_binlca(HMICtl_sLeftSetPoint, (const
    float32 *)&cal_SOCHighPTCPwrLmt_1X[0], (const float32 *)
    &cal_SOCHighPTCPwrLmt_CUR[0], 5U);
  ME11_ARID_DEF.Relay_Mode_h = ((BMS_BatSOCAct_pct >= cal_SOCHighPTCPwrLmtOn) ||
    ((BMS_BatSOCAct_pct > cal_SOCHighPTCPwrLmtOff) && ME11_ARID_DEF.Relay_Mode_h));
  ACTCtl_sPTCBatHeatPwrLmt = look1_iflf_binlca(cal_BatHeatTrgTemp -
    BMS_InletCooltActlTemp, (const float32 *)&cal_PTCBatHeatPwrLmt_1X[0], (const
    float32 *)&cal_PTCBatHeatPwrLmt_CUR[0], 8U);
  COMP_High_Voltage = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPHiVolt_V;
  COMP_InputCurrent = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPInCurr_A;
  PWRCtl_sCOMPActlPwr = COMP_High_Voltage * COMP_InputCurrent / 1000.0F;
  if (SOMCtl_bExtDefFlg) {
    ACPwr_sPTCLmtPwrVal = PWRCtl_VCUACCMLimitPwr - cal_PwrOffsetVal;
  } else {
    ACPwr_sPTCLmtPwrVal = (PWRCtl_VCUACCMLimitPwr - PWRCtl_sCOMPActlPwr) -
      cal_PwrOffsetVal;
  }

  if (cal_PTCReqtPowerDataEnb) {
    ACTCtl_sPTCReqPower = cal_PTCReqtPowerData;
  } else {
    if (HMICtl_bACDefrost) {
      rtb_PI_Cor_a = 7.0F;
    } else if (cal_ACCMForbidCtrl) {
      if (rtb_Switch2_ht == 8) {
        if (ACTCtl_bCtrlFPTCOnOrOffPwrDiff) {
          rtb_PI_Cor_a = ACTCtl_sCtrlFPTCAuxHeatPwr;
        } else {
          rtb_PI_Cor_a = 0.0F;
        }
      } else if (rtb_Switch2_ht == 4) {
        if (ME11_ARID_DEF.Relay_Mode_h && (ME11_ARID_DEF.DataTypeConversion1 ==
             4)) {
          rtb_Add_ax = ACTCtl_sSOCHighPTCPwrLmt;
        } else {
          rtb_Add_ax = 7.0F;
        }

        if (!ME11_ARID_DEF.Delay_DSTATE_kf) {
          rtb_PI_Cor_a = 7.0F;
        }

        if (rtb_Add_ax <= rtb_PI_Cor_a) {
          rtb_PI_Cor_a = rtb_Add_ax;
        }
      } else if (rtb_Switch2_ht == 5) {
        rtb_PI_Cor_a = ACTCtl_sPTCBatHeatPwrLmt;
      } else if (rtb_Switch2_ht == 6) {
        rtb_PI_Cor_a += ACTCtl_sPTCBatHeatPwrLmt;
      } else if (rtb_AND1_c) {
        rtb_PI_Cor_a = 7.0F;
      } else {
        rtb_PI_Cor_a = 0.0F;
      }
    } else {
      rtb_PI_Cor_a = 7.0F;
    }

    if (rtb_PI_Cor_a > ACPwr_sPTCLmtPwrVal) {
      rtb_PI_Cor_a = ACPwr_sPTCLmtPwrVal;
    }

    if (rtb_PI_Cor_a == 0.0F) {
      if (ME11_ARID_DEF.ACTCtl_sPTCPwrDeal >= rtb_PI_Cor_a) {
        ACTCtl_sPTCReqPower = ME11_ARID_DEF.ACTCtl_sPTCPwrDeal;
      } else {
        ACTCtl_sPTCReqPower = rtb_PI_Cor_a;
      }
    } else {
      ACTCtl_sPTCReqPower = rtb_PI_Cor_a;
    }
  }

  ME11_ARID_DEF.Delay_DSTATE_en = (ACTCtl_sPTCReqPower > 0.5F);
  rtb_Delay_ku = (uint8)
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHInletTemp_C + 40.0F);
  Rte_DIDReadData(rtb_Delay_ku, ((uint8)DID_0xF277));
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 8);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_iw,
    &ME11_ARID_DEF.ARID_DEF_Internal_Voltage_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942629),
                     ME11_ARID_DEF.ErrSts_iw);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 9);
  if (ME11_ARID_DEF.temporalCounter_i1_h1 < 15U) {
    ME11_ARID_DEF.temporalCounter_i1_h1++;
  }

  if (ME11_ARID_DEF.is_active_c108_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c108_ME11 = 1U;
    ME11_ARID_DEF.is_c108_ME11 = ME11_IN_Default_k;
    ME11_ARID_DEF.ErrSts_o = false;
  } else {
    switch (ME11_ARID_DEF.is_c108_ME11) {
     case ME11_IN_Default_k:
      ME11_ARID_DEF.ErrSts_o = false;
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c108_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_h1 = 0U;
      }
      break;

     case ME11_IN_Err_e:
      ME11_ARID_DEF.ErrSts_o = true;
      if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c108_ME11 = ME11_IN_wait1_o;
        ME11_ARID_DEF.temporalCounter_i1_h1 = 0U;
      }
      break;

     case ME11_IN_wait_k:
      if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c108_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ErrSts_o = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_h1 >= 10U) {
        ME11_ARID_DEF.is_c108_ME11 = ME11_IN_Err_e;
        ME11_ARID_DEF.ErrSts_o = true;
      }
      break;

     default:
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c108_ME11 = ME11_IN_Err_e;
        ME11_ARID_DEF.ErrSts_o = true;
      } else if (ME11_ARID_DEF.temporalCounter_i1_h1 >= 10U) {
        ME11_ARID_DEF.is_c108_ME11 = ME11_IN_Default_k;
        ME11_ARID_DEF.ErrSts_o = false;
      }
      break;
    }
  }

  Dem_SetEventStatus(((uint8)DemEventParameter_0x942719), ME11_ARID_DEF.ErrSts_o);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 10);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts,
    &ME11_ARID_DEF.ARID_DEF_Power_Target_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942803), ME11_ARID_DEF.ErrSts);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 11);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_m, &ME11_ARID_DEF.ARID_DEF_PCB_Temp_Sensor_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942929), ME11_ARID_DEF.ErrSts_m);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 12);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_h, &ME11_ARID_DEF.ARID_DEF_Core_Temp_Sensor_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942A29), ME11_ARID_DEF.ErrSts_h);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 13);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_oi, &ME11_ARID_DEF.ARID_DEF_Inlet_Temp_Sensor_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942B29),
                     ME11_ARID_DEF.ErrSts_oi);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942C29), ME11_ARID_DEF.ErrSts_e);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 15);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_i,
    &ME11_ARID_DEF.ARID_DEF_PCB_Temp_High);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942D98), ME11_ARID_DEF.ErrSts_i);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 16);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_oe, &ME11_ARID_DEF.ARID_DEF_Core_Temp_High);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942E98),
                     ME11_ARID_DEF.ErrSts_oe);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 17);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_l,
    &ME11_ARID_DEF.ARID_DEF_Inlet_Temp_High);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942B98), ME11_ARID_DEF.ErrSts_l);
  Rte_DIDReadData
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHSt_enum, ((uint8)DID_0xF278));
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 18);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_nf, &ME11_ARID_DEF.ARID_DEF_Outlet_Temp_High);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942C98),
                     ME11_ARID_DEF.ErrSts_nf);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 19);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_li, &ME11_ARID_DEF.ARID_DEF_Current_Sensor_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942F1D),
                     ME11_ARID_DEF.ErrSts_li);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 20);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_nq,
    &ME11_ARID_DEF.ARID_DEF_Abnormal_Over_temperatura_via_software_monitoring);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942098),
                     ME11_ARID_DEF.ErrSts_nq);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 21);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_oel,
    &ME11_ARID_DEF.ARID_DEF_Abnormal_Over_temperatura_via_hardware_monitoring);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943198),
                     ME11_ARID_DEF.ErrSts_oel);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 1);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_d,
    &ME11_ARID_DEF.ARID_DEF_External_Com_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942386), ME11_ARID_DEF.ErrSts_d);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 2);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_n, &ME11_ARID_DEF.ARID_DEF_HVIL_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942229), ME11_ARID_DEF.ErrSts_n);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 3);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_cu,
    &ME11_ARID_DEF.ARID_DEF_HV_Over_Voltage);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942416),
                     ME11_ARID_DEF.ErrSts_cu);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 4);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_b,
    &ME11_ARID_DEF.ARID_DEF_HV_Under_Voltage);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942417), ME11_ARID_DEF.ErrSts_b);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 5);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_a, &ME11_ARID_DEF.ARID_DEF_LV_Over_Voltage);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942516), ME11_ARID_DEF.ErrSts_a);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 6);
  ME11_Abnormal_Over_temperatura_via_software_monitoring(rtb_Compare_mos,
    &ME11_ARID_DEF.ErrSts_e5, &ME11_ARID_DEF.ARID_DEF_LV_Under_Voltage);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942517),
                     ME11_ARID_DEF.ErrSts_e5);
  rtb_Compare_mos =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum == 7);
  ME11_External_Com_Fault(rtb_Compare_mos, &ME11_ARID_DEF.ErrSts_c,
    &ME11_ARID_DEF.ARID_DEF_Internal_Com_Fault);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942604), ME11_ARID_DEF.ErrSts_c);
  rtb_Delay_ku = (uint8)
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHPCBTemp_C + 40.0F);
  Rte_DIDReadData(rtb_Delay_ku, ((uint8)DID_0xF275));
  rtb_Delay_ku = (uint8)
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHOutlTemp_C + 40.0F);
  Rte_DIDReadData(rtb_Delay_ku, ((uint8)DID_0xF276));
  ME11_ARID_DEF.GLB_TMSFaultPMP[0] = rtb_FixPtRelationalOperator_ex;
  ME11_ARID_DEF.GLB_TMSFaultPMP[1] = rtb_Compare_f2;
  ME11_ARID_DEF.GLB_TMSFaultPMP[2] = rtb_Compare_bu;
  ME11_ARID_DEF.GLB_TMSFaultPMP[3] = rtb_RelationalOperator3_d;
  ME11_ARID_DEF.GLB_TMSFaultPMP[4] = rtb_Compare_j2e;
  ME11_ARID_DEF.GLB_TMSFaultPMP[5] = rtb_FixPtRelationalOperator_dx;
  ME11_ARID_DEF.GLB_TMSFaultPMP[6] = FixPtRelationalOperator;
  ME11_ARID_DEF.GLB_TMSFaultPMP[7] = rtb_Delay1_ag;
  ME11_ARID_DEF.GLB_TMSFaultPMP[8] = rtb_AND1_hh;
  ME11_ARID_DEF.GLB_TMSFaultPMP[9] = rtb_FixPtRelationalOperator_ka;
  ME11_ARID_DEF.GLB_TMSFaultPMP[10] = rtb_FixPtRelationalOperator_gf;
  ME11_ARID_DEF.GLB_TMSFaultPMP[11] = rtb_Compare_mdjr;
  ME11_ARID_DEF.GLB_TMSFaultPMP[12] = rtb_Compare_cvf;
  ME11_ARID_DEF.GLB_TMSFaultPMP[13] = rtb_FixPtRelationalOperator_cd;
  ME11_ARID_DEF.GLB_TMSFaultPMP[14] = rtb_FixPtRelationalOperator_d5;
  ME11_ARID_DEF.GLB_TMSFaultPMP[15] = ACTCtl_bAcPMPSpdFlt;
  ME11_ARID_DEF.GLB_TMSFaultPMP[16] = ACTCtl_bBatPMPSpdFlt;
  ME11_ARID_DEF.GLB_TMSFaultPMP[17] = ACTCtl_bMotPMPSpdFlt;
  ACTCtl_eAcPMPSpdSet = (uint8)((float32)rtb_Switch2_gua * 2.5F);
  ACTCtl_eBatPMPSpdSet = (uint8)((float32)rtb_MultiportSwitch1 * 2.5F);
  ACTCtl_eMotPMPSpdSet = (uint8)((float32)rtb_Compare_bxp * 2.5F);
  if (cal_LTRFanCtrl_1X[0] > ACSen_sMotTempFilter) {
    rtb_IFreezFlag_bd = cal_LTRFanCtrl_1Y[0];
  } else if (ACSen_sMotTempFilter >= cal_LTRFanCtrl_1X[1]) {
    rtb_IFreezFlag_bd = cal_LTRFanCtrl_1Y[2];
  } else {
    rtb_IFreezFlag_bd = cal_LTRFanCtrl_1Y[1];
  }

  if ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA()
      )->VIPM_ESCVehSpdVld_flg) {
    rtb_DataTypeConversion23 =
      (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA()
      )->VIPM_ESCVehSpd_kph;
  } else {
    rtb_DataTypeConversion23 = 0.0F;
  }

  ACTCtl_eCoolFanCtrl = look2_iflftu8Dfdf_binlca(rtb_DataTypeConversion23,
    ACSen_sHiPressFilter, (const float32 *)&cal_CoolFanCtrl_2X[0], (const
    float32 *)&cal_CoolFanCtrl_2Y[0], (const uint8 *)&cal_CoolFanCtrl_MAP[0],
    ME11_ConstP.pooled39, 4U);
  if (COMP_EcompActSpd >= cal_COMPSpdLmt[3]) {
    rtb_Compare_bxp = cal_COMPFanSpdLmt[2];
    ME11_ARID_DEF.Flg = 3U;
  } else if (COMP_EcompActSpd >= cal_COMPSpdLmt[2]) {
    if (ME11_ARID_DEF.Flg == 3) {
      rtb_Compare_bxp = cal_COMPFanSpdLmt[2];
      ME11_ARID_DEF.Flg = 3U;
    } else {
      rtb_Compare_bxp = cal_COMPFanSpdLmt[1];
      ME11_ARID_DEF.Flg = 2U;
    }
  } else if (COMP_EcompActSpd >= cal_COMPSpdLmt[1]) {
    if (ME11_ARID_DEF.Flg >= 2) {
      rtb_Compare_bxp = cal_COMPFanSpdLmt[1];
      ME11_ARID_DEF.Flg = 2U;
    } else {
      rtb_Compare_bxp = cal_COMPFanSpdLmt[0];
      ME11_ARID_DEF.Flg = 1U;
    }
  } else if ((COMP_EcompActSpd >= cal_COMPSpdLmt[0]) && (ME11_ARID_DEF.Flg >= 1))
  {
    rtb_Compare_bxp = cal_COMPFanSpdLmt[0];
    ME11_ARID_DEF.Flg = 1U;
  } else {
    rtb_Compare_bxp = 10U;
    ME11_ARID_DEF.Flg = 0U;
  }

  ME11_ARID_DEF.Relay_Mode_k = ((ACSen_sACCMHiTempFilter >= cal_ACCMHiTempFanOn)
    || ((ACSen_sACCMHiTempFilter > cal_ACCMHiTempFanOff) &&
        ME11_ARID_DEF.Relay_Mode_k));
  if (ME11_ARID_DEF.temporalCounter_i1_gg < 255U) {
    ME11_ARID_DEF.temporalCounter_i1_gg++;
  }

  if (ME11_ARID_DEF.is_active_c11_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c11_ME11 = 1U;
    ME11_ARID_DEF.is_c11_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.B_aq = false;
  } else {
    switch (ME11_ARID_DEF.is_c11_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.B_aq = false;
      if (ME11_ARID_DEF.Relay_Mode_k) {
        ME11_ARID_DEF.is_c11_ME11 = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i1_gg = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.B_aq = true;
      if (!ME11_ARID_DEF.Relay_Mode_k) {
        ME11_ARID_DEF.is_c11_ME11 = ME11_IN_wait1_o;
        ME11_ARID_DEF.temporalCounter_i1_gg = 0U;
      }
      break;

     case ME11_IN_wait_k:
      if (ME11_ARID_DEF.temporalCounter_i1_gg >= 200U) {
        ME11_ARID_DEF.is_c11_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.B_aq = true;
      } else if (!ME11_ARID_DEF.Relay_Mode_k) {
        ME11_ARID_DEF.is_c11_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.B_aq = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.Relay_Mode_k) {
        ME11_ARID_DEF.is_c11_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.B_aq = true;
      } else if (ME11_ARID_DEF.temporalCounter_i1_gg >= 200U) {
        ME11_ARID_DEF.is_c11_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.B_aq = false;
      }
      break;
    }
  }

  if ((Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA()
      )->VIPM_ESCVehSpdVld_flg) {
    rtb_Add_ax =
      (Rte_IRead_Task_100ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA()
      )->VIPM_ESCVehSpd_kph;
  } else {
    rtb_Add_ax = 0.0F;
  }

  ACTCtl_eHeatFanCtrl = look2_iflftu8Dfdf_binlca(rtb_Add_ax, ACSen_sEnvTempCor -
    ACSen_sOHXTempFilter, (const float32 *)&cal_HeatFanCtrl_2X[0], (const
    float32 *)&cal_HeatFanCtrl_2Y[0], (const uint8 *)&cal_HeatFanCtrl_MAP[0],
    ME11_ConstP.pooled39, 4U);
  rtb_Compare_mos = (ACSen_sLoPressFilter <= cal_LPFanOn);
  rtb_Compare_cj1 = (ACSen_sLoPressFilter >= cal_LPFanOff);
  if (ME11_ARID_DEF.temporalCounter_i1_jb < MAX_uint32_T) {
    ME11_ARID_DEF.temporalCounter_i1_jb++;
  }

  if (ME11_ARID_DEF.is_active_c65_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c65_ME11 = 1U;
    ME11_ARID_DEF.is_c65_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.B_pl = false;
  } else {
    switch (ME11_ARID_DEF.is_c65_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.B_pl = false;
      if (rtb_Compare_mos) {
        ME11_ARID_DEF.is_c65_ME11 = ME11_IN_wait_On;
        ME11_ARID_DEF.temporalCounter_i1_jb = 0U;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.B_pl = true;
      if (rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c65_ME11 = ME11_IN_wait_Off;
        ME11_ARID_DEF.temporalCounter_i1_jb = 0U;
      }
      break;

     case ME11_IN_wait_Off:
      if (!rtb_Compare_cj1) {
        ME11_ARID_DEF.is_c65_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.B_pl = true;
      } else if (ME11_ARID_DEF.temporalCounter_i1_jb >= cal_LPProOffTimer *
                 10.0F) {
        ME11_ARID_DEF.is_c65_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.B_pl = false;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_jb >= cal_LPProOnTimer * 10.0F) {
        ME11_ARID_DEF.is_c65_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.B_pl = true;
      } else if (!rtb_Compare_mos) {
        ME11_ARID_DEF.is_c65_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.B_pl = false;
      }
      break;
    }
  }

  if (cal_CoolFanEnb) {
    ACTCtl_eFanPerc = cal_CoolFanData;
  } else {
    for (b_previousEvent = 0; b_previousEvent < 5; b_previousEvent++) {
      rtb_Compare_btd[b_previousEvent] = (rtb_Switch2_ht ==
        ME11_ConstP.Constant_Value_l2[b_previousEvent]);
    }

    if (rtb_Compare_btd[0] || rtb_Compare_btd[1] || rtb_Compare_btd[2] ||
        rtb_Compare_btd[3] || rtb_Compare_btd[4]) {
      if (ME11_ARID_DEF.B_aq) {
        rtb_Compare_nw0 = cal_ACCMHiTempFanCtrl;
      } else {
        rtb_Compare_nw0 = 10U;
      }
    } else {
      rtb_Compare_nw0 = 10U;
    }

    if ((rtb_DataTypeConversion1_l == 0) || (rtb_DataTypeConversion1_l == 4)) {
      rtb_Compare_i1 = rtb_IFreezFlag_bd;
    } else if (rtb_DataTypeConversion1_l == 5) {
      rtb_Compare_mos = (cal_LTRIPUTempFanCtrl_1X[0] >
                         (Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT
                          ())->VIPM_IPUDeviceIntTemp_C);
      if (rtb_Compare_mos) {
        rtb_Compare_i1 = cal_LTRIPUTempFanCtrl_1Y[0];
      } else {
        rtb_Compare_mos =
          ((Rte_IRead_Task_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT
            ())->VIPM_IPUDeviceIntTemp_C >= cal_LTRIPUTempFanCtrl_1X[1]);
        if (rtb_Compare_mos) {
          rtb_Compare_i1 = cal_LTRIPUTempFanCtrl_1Y[2];
        } else {
          rtb_Compare_i1 = cal_LTRIPUTempFanCtrl_1Y[1];
        }
      }

      if (rtb_IFreezFlag_bd >= rtb_Compare_i1) {
        rtb_Compare_i1 = rtb_IFreezFlag_bd;
      }
    } else {
      rtb_Compare_i1 = 10U;
    }

    if ((rtb_DataTypeConversion1_on == 0) && ((rtb_DataTypeConversion1_l == 0) ||
         (rtb_DataTypeConversion1_l == 2) || (rtb_DataTypeConversion1_l == 3)))
    {
      rtb_Add_ge3 = cal_FanCtrlOff;
    } else {
      rtb_Add_ge3 = 10U;
    }

    if (ME11_ARID_DEF.Delay_DSTATE_kf) {
      rtb_Add7_i = ACTCtl_eCoolFanCtrl;
    } else {
      rtb_Add7_i = 10U;
    }

    if (((rtb_Switch2_ht == 4) || (rtb_Switch2_ht == 5) || (rtb_Switch2_ht == 6)
         || (rtb_Switch2_ht == 8)) && ME11_ARID_DEF.Delay_DSTATE_kf) {
      rtb_Add2_j5 = ACTCtl_eHeatFanCtrl;
    } else {
      rtb_Add2_j5 = 10U;
    }

    if (ME11_ARID_DEF.B_pl && (ME11_ARID_DEF.Delay_DSTATE_kf &&
         ((rtb_DataTypeConversion1_g != 3) || (rtb_DataTypeConversion1_g != 4))))
    {
      rtb_Add3_do = cal_LPFanCtrl;
    } else {
      rtb_Add3_do = 10U;
    }

    if (rtb_Switch2_ht == 13) {
      ACTCtl_eFanPerc = cal_HeatCabinAndCoolBatFanSpd;
    } else {
      ACTCtl_eFanPerc = 10U;
    }

    if (rtb_Compare_i1 >= rtb_Add_ge3) {
      rtb_Add_ge3 = rtb_Compare_i1;
    }

    if (rtb_Add_ge3 >= rtb_Compare_nw0) {
      rtb_Compare_nw0 = rtb_Add_ge3;
    }

    if (rtb_Compare_nw0 >= rtb_Add7_i) {
      rtb_Add7_i = rtb_Compare_nw0;
    }

    if (rtb_Add7_i >= rtb_Add2_j5) {
      rtb_Add2_j5 = rtb_Add7_i;
    }

    if (rtb_Add2_j5 >= rtb_Add3_do) {
      rtb_Add3_do = rtb_Add2_j5;
    }

    if (rtb_Add3_do >= ACTCtl_eFanPerc) {
      ACTCtl_eFanPerc = rtb_Add3_do;
    }

    if (ACTCtl_eFanPerc > 100) {
      ACTCtl_eFanPerc = 100U;
    } else if (ACTCtl_eFanPerc < rtb_Compare_bxp) {
      ACTCtl_eFanPerc = rtb_Compare_bxp;
    }
  }

  ME11_ARID_DEF.Relay_Mode_n = ((ACSen_sEvapSurTemp >= cal_EVAPSufTempClsSOV) ||
    ((ACSen_sEvapSurTemp > cal_EVAPSufTempOpenSOV) && ME11_ARID_DEF.Relay_Mode_n));
  switch (rtb_Switch2_ht) {
   case 4:
   case 5:
   case 6:
    ACTCtl_bSOVCmd = true;
    break;

   case 8:
    ACTCtl_bSOVCmd = !ME11_ARID_DEF.Relay_Mode_n;
    break;

   default:
    ACTCtl_bSOVCmd = false;
    break;
  }

  rtb_Gain_az = Rte_IRead_Task_100ms_EXV_CurrentPosition_EXV_CurrentPosition();
  Buffer_DcmDspData_F27DH[0] = (uint8)rtb_Gain_az;
  Buffer_DcmDspData_F27DH[1] = (uint8)((uint32)rtb_Gain_az >> 8);
  EXV_CurrentPosition = 0.15625F * (float32)rtb_Gain_az;
  EXV_RunState = Rte_IRead_Task_100ms_EXV_RunState_EXV_RunState();
  rtb_Gain_az =
    Rte_IRead_Task_100ms_BAT_EXV_CurrentPosition_B_BAT_EXV_CurrentPosition_B();
  Buffer_DcmDspData_F27EH[0] = (uint8)rtb_Gain_az;
  Buffer_DcmDspData_F27EH[1] = (uint8)((uint32)rtb_Gain_az >> 8);
  BAT_EXV_CurrentPosition_B = 0.15625F * (float32)rtb_Gain_az;
  BAT_EXV_RunState_B =
    Rte_IRead_Task_100ms_BAT_EXV_RunState_B_BAT_EXV_RunState_B();
  BAT_EXV_SupplierLabel =
    Rte_IRead_Task_100ms_BAT_EXV_SupplierLabel_BAT_EXV_SupplierLabel();
  Bat_EXV_ProjectCode1 =
    Rte_IRead_Task_100ms_Bat_EXV_ProjectCode1_Bat_EXV_ProjectCode1();
  Bat_EXV_ProjectCode2 =
    Rte_IRead_Task_100ms_Bat_EXV_ProjectCode2_Bat_EXV_ProjectCode2();
  Bat_EXV_SupplierNumber =
    Rte_IRead_Task_100ms_Bat_EXV_SupplierNumber_Bat_EXV_SupplierNumber();
  Bat_EXV_PartNumber =
    Rte_IRead_Task_100ms_Bat_EXV_PartNumber_Bat_EXV_PartNumber();
  Bat_EXV_HWVersion = Rte_IRead_Task_100ms_Bat_EXV_HWVersion_Bat_EXV_HWVersion();
  Bat_EXV_SWVersion_Main =
    Rte_IRead_Task_100ms_Bat_EXV_SWVersion_Main_Bat_EXV_SWVersion_Main();
  Bat_EXV_SWVersion_Sub =
    Rte_IRead_Task_100ms_Bat_EXV_SWVersion_Sub_Bat_EXV_SWVersion_Sub();
  Bat_EXV_SWVersion_Patch =
    Rte_IRead_Task_100ms_Bat_EXV_SWVersion_Patch_Bat_EXV_SWVersion_Patch();
  Buffer_DcmDspData_F27CH[0] = (uint8)rtb_Divide_ox;
  Buffer_DcmDspData_F27CH[1] = (uint8)((uint32)rtb_Divide_ox >> 8);
  HP_EXV_SupplierLabel =
    Rte_IRead_Task_100ms_HP_EXV_SupplierLabel_HP_EXV_SupplierLabel();
  HP_EXV_RunState_B = Rte_IRead_Task_100ms_HP_EXV_RunState_B_HP_EXV_RunState_B();
  HP_EXV_ProjectCode1 =
    Rte_IRead_Task_100ms_HP_EXV_ProjectCode1_HP_EXV_ProjectCode1();
  HP_EXV_ProjectCode2 =
    Rte_IRead_Task_100ms_HP_EXV_ProjectCode2_HP_EXV_ProjectCode2();
  HP_EXV_SupplierNumber =
    Rte_IRead_Task_100ms_HP_EXV_SupplierNumber_HP_EXV_SupplierNumber();
  HP_EXV_PartNumber = Rte_IRead_Task_100ms_HP_EXV_PartNumber_HP_EXV_PartNumber();
  HP_EXV_HWVersion = Rte_IRead_Task_100ms_HP_EXV_HWVersion_HP_EXV_HWVersion();
  HP_EXV_SWVersion_Main =
    Rte_IRead_Task_100ms_HP_EXV_SWVersion_Main_HP_EXV_SWVersion_Main();
  HP_EXV_SWVersion_Sub =
    Rte_IRead_Task_100ms_HP_EXV_SWVersion_Sub_HP_EXV_SWVersion_Sub();
  HP_EXV_SWVersion_Patch =
    Rte_IRead_Task_100ms_HP_EXV_SWVersion_Patch_HP_EXV_SWVersion_Patch();
  if (CoAC_stwork == 1) {
    EE_tEnv = ME11_ARID_DEF.EERead_AmbienceTemp;
    EE_PCUInletTemp = ME11_ARID_DEF.EERead_PCUInletTemp;
    PCU_StartClntTemp = ME11_ARID_DEF.Delay_DSTATE_kx;
    ColdStartPCUTempMinByEnv =
      cal_ColdStartPCUTempMinByEnv_CUR[plook_u32f_bincka(EE_tEnv, (const float32
      *)&cal_ColdStartPCUTempMinByEnv_1X[0], 6U)];
    if (EE_PCUInletTemp - PCU_StartClntTemp > 5.0F) {
      ME11_ARID_DEF.Switch4 = EE_PCUInletTemp;
    } else {
      ME11_ARID_DEF.Switch4 = PCU_StartClntTemp;
    }

    PCUtempOffset2ShutByEnv = cal_PCUtempOffset2ShutByEnv_CUR[plook_u32f_bincka
      (EE_tEnv, (const float32 *)&cal_PCUtempOffset2ShutByEnv_1X[0], 6U)];
    if ((EE_tEnv < 30.0F) && (PCU_StartClntTemp <= ColdStartPCUTempMinByEnv)) {
      ME11_ARID_DEF.Switch3 = true;
    } else {
      if (PCU_StartClntTemp < ME11_ARID_DEF.Switch4) {
        rtb_MultiportSwitch2_e = ME11_ARID_DEF.Switch4 - PCU_StartClntTemp;
      } else {
        rtb_MultiportSwitch2_e = 0.0F;
      }

      ME11_ARID_DEF.Switch3 = (PCUtempOffset2ShutByEnv <= rtb_MultiportSwitch2_e);
    }
  }

  CoAC_stColdStart = ((AC_tiAfterRun >= 90) || ME11_ARID_DEF.Switch3);
  GLB_CoAC_stColdStart = CoAC_stColdStart;
  GLB_CoAC_stwork = CoAC_stwork;
  if (ME11_ARID_DEF.Delay_DSTATE_kx >= ME11_ARID_DEF.Switch4) {
    rtb_MultiportSwitch2_e = ME11_ARID_DEF.Delay_DSTATE_kx;
  } else {
    rtb_MultiportSwitch2_e = ME11_ARID_DEF.Switch4;
  }

  ME11_ARID_DEF.EEWrite_PCUInletTemp = (uint8)((uint8)(rtb_MultiportSwitch2_e +
    40.0F) << 1);
  if (ME11_ARID_DEF.temporalCounter_i1_ex < 1U) {
    ME11_ARID_DEF.temporalCounter_i1_ex++;
  }

  if (ME11_ARID_DEF.is_active_c40_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c40_ME11 = 1U;
    ME11_ARID_DEF.is_c40_ME11 = ME11_IN_Counter_Init;
    ME11_ARID_DEF.temporalCounter_i1_ex = 0U;
    PWRCtl_uTMSRunTimer = 0U;
  } else if (ME11_ARID_DEF.is_c40_ME11 == ME11_IN_Counter_Cal) {
    if (PWRCtl_uTMSRunTimer >= 4294967294U) {
      ME11_ARID_DEF.is_c40_ME11 = ME11_IN_Counter_Init;
      ME11_ARID_DEF.temporalCounter_i1_ex = 0U;
      PWRCtl_uTMSRunTimer = 0U;
    } else {
      rtb_Divide1_f = PWRCtl_uTMSRunTimer + 1U;
      if (PWRCtl_uTMSRunTimer + 1U < PWRCtl_uTMSRunTimer) {
        rtb_Divide1_f = MAX_uint32_T;
      }

      PWRCtl_uTMSRunTimer = rtb_Divide1_f;
    }
  } else if (ME11_ARID_DEF.temporalCounter_i1_ex >= 1) {
    ME11_ARID_DEF.is_c40_ME11 = ME11_IN_Counter_Cal;
  }

  ME11_ARID_DEF.VectorConcatenate[0] = (rtb_Compare != 0);
  ME11_ARID_DEF.VectorConcatenate[1] = (rtb_Compare_ij != 0);
  rtb_Delay_ku = (uint8)(ACSen_eFaceDuctSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[2] = (rtb_Delay_ku != 0);
  rtb_Compare_ij = (uint8)(ACSen_eFaceDuctSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[3] = (rtb_Compare_ij != 0);
  rtb_Add2_j5 = (uint8)(ACSen_eFootDuctSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[4] = (rtb_Add2_j5 != 0);
  rtb_DataTypeConversion1_g = (uint8)(ACSen_eFootDuctSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[5] = (rtb_DataTypeConversion1_g != 0);
  rtb_IFreezFlag_bd = (uint8)(ACSen_eEVAPSurfTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[6] = (rtb_IFreezFlag_bd != 0);
  rtb_IFreezFlag_jz = (uint8)(ACSen_eEVAPSurfTSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[7] = (rtb_IFreezFlag_jz != 0);
  rtb_MultiportSwitch1 = (uint8)(ACSen_eEnvSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[8] = (rtb_MultiportSwitch1 != 0);
  rtb_Switch2_gua = (uint8)(ACSen_eEnvSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[9] = (rtb_Switch2_gua != 0);
  ACSen_eWCCHPSenSts = ME11_ARID_DEF.SenSts_f;
  rtb_Add7_i = (uint8)(ACSen_eWCCHPSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[10] = (rtb_Add7_i != 0);
  rtb_Add3_do = (uint8)(ACSen_eWCCHPSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[11] = (rtb_Add3_do != 0);
  rtb_Add6_d = (uint8)(ACSen_eWCCHTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[12] = (rtb_Add6_d != 0);
  rtb_Add5_d = (uint8)(ACSen_eWCCHTSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[13] = (rtb_Add5_d != 0);
  rtb_Compare_nw0 = (uint8)(ACSen_eChillerTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[14] = (rtb_Compare_nw0 != 0);
  rtb_Compare_i1 = (uint8)(ACSen_eChillerTSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[15] = (rtb_Compare_i1 != 0);
  ACSen_eLPSenSts = ME11_ARID_DEF.SenSts_e;
  rtb_Compare_bxp = (uint8)(ACSen_eLPSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[16] = (rtb_Compare_bxp != 0);
  rtb_Add4_ox = (uint8)(ACSen_eLPSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[17] = (rtb_Add4_ox != 0);
  rtb_DataTypeConversion19 = (uint8)(ACSen_eACCMHTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[18] = (rtb_DataTypeConversion19 != 0);
  rtb_DataTypeConversion2_a = (uint8)(ACSen_eACCMHTSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[19] = (rtb_DataTypeConversion2_a != 0);
  rtb_Add_ge3 = (uint8)(ACSen_eOHXTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[20] = (rtb_Add_ge3 != 0);
  rtb_Compare = (uint8)(ACSen_eOHXTSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[21] = (rtb_Compare != 0);
  ME11_ARID_DEF.VectorConcatenate[22] = (ACSen_eMOTORTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[23] = (ACSen_eMOTORTSenSts == Power);
  ME11_ARID_DEF.VectorConcatenate[24] = (ACSen_eEVAPTSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[25] = (ACSen_eEVAPTSenSts == Power);
  if (cal_RecircTrgPosDataEnb) {
    IOCtl_RecircTrgPos = cal_RecircTrgPosData;
  } else if (((Buffer_DcmDspData_3238[0] & 8) == 8) &&
             (Rte_DcmDspData_3238_CtlFlg == 1)) {
    IOCtl_RecircTrgPos = Buffer_DcmDspData_3238[4];
  } else {
    IOCtl_RecircTrgPos = ACCtl_IntakeRatio;
  }

  rtb_Compare_mos = (IOCtl_RecircTrgPos != ME11_ARID_DEF.DelayInput1_DSTATE_n);
  if (ME11_ARID_DEF.temporalCounter_i1_mf < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_mf++;
  }

  if (ME11_ARID_DEF.temporalCounter_i2_k < 7U) {
    ME11_ARID_DEF.temporalCounter_i2_k++;
  }

  if (ME11_ARID_DEF.is_active_c63_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c63_ME11 = 1U;
    ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
    ME11_ARID_DEF.p_c = 0U;
    ME11_ARID_DEF.n_h = 0U;
    ME11_ARID_DEF.MoveSts_d = false;
    ME11_ARID_DEF.Sts_e_k = 0U;
    ME11_ARID_DEF.is_Diagnostic_g = ME11_IN_Init_i;
    ME11_ARID_DEF.TempVol_h = ACSen_eAirInletPer;
  } else {
    switch (ME11_ARID_DEF.is_Move_f) {
     case ME11_IN_ALLInner:
      ME11_ARID_DEF.p_c = 1U;
      ME11_ARID_DEF.n_h = 0U;
      if (ME11_ARID_DEF.temporalCounter_i1_mf >= 10U) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
        ME11_ARID_DEF.Sts_e_k = 0U;
      }
      break;

     case ME11_IN_ALLOut:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 1U;
      if (ME11_ARID_DEF.temporalCounter_i1_mf >= 10U) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
        ME11_ARID_DEF.Sts_e_k = 0U;
      }
      break;

     case ME11_IN_Default_o:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 0U;
      ME11_ARID_DEF.MoveSts_d = false;
      if ((IOCtl_RecircTrgPos > (float32)ACSen_eAirInletPer + cal_RecircDoorPErr)
          && rtb_Compare_mos) {
        ME11_ARID_DEF.Stuck_Sts_a = false;
        ME11_ARID_DEF.is_Move_f = ME11_IN_InnerRec;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 1U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = true;
      } else if ((IOCtl_RecircTrgPos < (float32)ACSen_eAirInletPer -
                  cal_RecircDoorNErr) && rtb_Compare_mos) {
        ME11_ARID_DEF.Stuck_Sts_a = false;
        ME11_ARID_DEF.is_Move_f = ME11_IN_OutRec;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 1U;
        ME11_ARID_DEF.MoveSts_d = true;
      }
      break;

     case ME11_IN_Fault_j:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 0U;
      ME11_ARID_DEF.MoveSts_d = false;
      if (cal_RecircMotorEnb || (ME11_ARID_DEF.temporalCounter_i1_mf >= 1000U))
      {
        ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
        ME11_ARID_DEF.Sts_e_k = 0U;
      }
      break;

     case ME11_IN_Fault1:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 0U;
      ME11_ARID_DEF.MoveSts_d = false;
      if (cal_RecircMotorEnb || (ME11_ARID_DEF.temporalCounter_i1_mf >= 1000U))
      {
        ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
        ME11_ARID_DEF.Sts_e_k = 0U;
      }
      break;

     case ME11_IN_InRec_Stuck:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 0U;
      ME11_ARID_DEF.MoveSts_d = false;
      if (ME11_ARID_DEF.Sts_e_k == 2) {
        ME11_ARID_DEF.Stuck_Sts_a = true;
        ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
        ME11_ARID_DEF.Sts_e_k = 0U;
      } else if (ME11_ARID_DEF.temporalCounter_i1_mf >= 20U) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_InnerRec;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 1U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = true;
      }
      break;

     case ME11_IN_InnerRec:
      ME11_ARID_DEF.p_c = 1U;
      ME11_ARID_DEF.n_h = 0U;
      ME11_ARID_DEF.MoveSts_d = true;
      if (IOCtl_RecircTrgPos < (float32)ACSen_eAirInletPer + cal_RecircDoorPErr)
      {
        if (IOCtl_RecircTrgPos > cal_InnerRecTrgPos) {
          ME11_ARID_DEF.is_Move_f = ME11_IN_ALLInner;
          ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
          ME11_ARID_DEF.p_c = 1U;
          ME11_ARID_DEF.n_h = 0U;
        } else {
          ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
          ME11_ARID_DEF.p_c = 0U;
          ME11_ARID_DEF.n_h = 0U;
          ME11_ARID_DEF.MoveSts_d = false;
          ME11_ARID_DEF.Sts_e_k = 0U;
        }
      } else if (ME11_ARID_DEF.Sts_e_k == 1) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_InRec_Stuck;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_mf >= 600U) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_Fault_j;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
      }
      break;

     case ME11_IN_OutRec:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 1U;
      ME11_ARID_DEF.MoveSts_d = true;
      if (IOCtl_RecircTrgPos > (float32)ACSen_eAirInletPer - cal_RecircDoorNErr)
      {
        if (IOCtl_RecircTrgPos < cal_OutRecTrgPos) {
          ME11_ARID_DEF.is_Move_f = ME11_IN_ALLOut;
          ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
          ME11_ARID_DEF.p_c = 0U;
          ME11_ARID_DEF.n_h = 1U;
        } else {
          ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
          ME11_ARID_DEF.p_c = 0U;
          ME11_ARID_DEF.n_h = 0U;
          ME11_ARID_DEF.MoveSts_d = false;
          ME11_ARID_DEF.Sts_e_k = 0U;
        }
      } else if (ME11_ARID_DEF.temporalCounter_i1_mf >= 600U) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_Fault1;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
      } else if (ME11_ARID_DEF.Sts_e_k == 1) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_OutRec_Stuck;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
      }
      break;

     default:
      ME11_ARID_DEF.p_c = 0U;
      ME11_ARID_DEF.n_h = 0U;
      ME11_ARID_DEF.MoveSts_d = false;
      if (ME11_ARID_DEF.Sts_e_k == 2) {
        ME11_ARID_DEF.Stuck_Sts_a = true;
        ME11_ARID_DEF.is_Move_f = ME11_IN_Default_o;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 0U;
        ME11_ARID_DEF.MoveSts_d = false;
        ME11_ARID_DEF.Sts_e_k = 0U;
      } else if (ME11_ARID_DEF.temporalCounter_i1_mf >= 20U) {
        ME11_ARID_DEF.is_Move_f = ME11_IN_OutRec;
        ME11_ARID_DEF.temporalCounter_i1_mf = 0U;
        ME11_ARID_DEF.p_c = 0U;
        ME11_ARID_DEF.n_h = 1U;
        ME11_ARID_DEF.MoveSts_d = true;
      }
      break;
    }

    switch (ME11_ARID_DEF.is_Diagnostic_g) {
     case ME11_IN_Init_i:
      if (ME11_ARID_DEF.MoveSts_d) {
        ME11_ARID_DEF.is_Diagnostic_g = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i2_k = 0U;
      } else {
        ME11_ARID_DEF.TempVol_h = ACSen_eAirInletPer;
      }
      break;

     case ME11_IN_Judge:
      ME11_ARID_DEF.is_Diagnostic_g = ME11_IN_Init_i;
      ME11_ARID_DEF.TempVol_h = ACSen_eAirInletPer;
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i2_k >= 5U) {
        if ((float32)fabs(ME11_ARID_DEF.TempVol_h - (float32)ACSen_eAirInletPer)
            < 0.04F) {
          ME11_ARID_DEF.is_Diagnostic_g = ME11_IN_Judge;
          b_previousEvent = ME11_ARID_DEF.Sts_e_k + 1;
          if (ME11_ARID_DEF.Sts_e_k + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Sts_e_k = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.is_Diagnostic_g = ME11_IN_Init_i;
          ME11_ARID_DEF.TempVol_h = ACSen_eAirInletPer;
        }
      }
      break;
    }
  }

  IOCtl_bRecStall = ME11_ARID_DEF.Stuck_Sts_a;
  ME11_ARID_DEF.VectorConcatenate[28] = IOCtl_bRecStall;
  IOCtl_bModeStall = (ME11_ARID_DEF.Stuck_Sts != 0);
  ME11_ARID_DEF.VectorConcatenate[31] = IOCtl_bModeStall;
  if (cal_SetLeftMixDoorTrgDataEnb) {
    IOCtl_sMixDoorTrgPos = cal_SetLeftMixDoorTrgData;
  } else if (((Buffer_DcmDspData_3238[0] & 1) == 1) &&
             (Rte_DcmDspData_3238_CtlFlg == 1)) {
    IOCtl_sMixDoorTrgPos = (float32)Buffer_DcmDspData_3238[1];
  } else if ((ACTCtl_sACCMCtlSpd >= 700.0F) && (rtb_DataTypeConversion1_on == 4))
  {
    IOCtl_sMixDoorTrgPos = cal_MixDoorHPPosVal;
  } else {
    IOCtl_sMixDoorTrgPos = ThCo_rSetLeftMixDoor;
  }

  rtb_Compare_mos = (IOCtl_sMixDoorTrgPos != ME11_ARID_DEF.DelayInput1_DSTATE_dg);
  if (ME11_ARID_DEF.temporalCounter_i1_f < 1023U) {
    ME11_ARID_DEF.temporalCounter_i1_f++;
  }

  if (ME11_ARID_DEF.temporalCounter_i2_e < 7U) {
    ME11_ARID_DEF.temporalCounter_i2_e++;
  }

  if (ME11_ARID_DEF.is_active_c62_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c62_ME11 = 1U;
    ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
    ME11_ARID_DEF.p_n = 0U;
    ME11_ARID_DEF.n_d = 0U;
    ME11_ARID_DEF.MoveSts_m = false;
    ME11_ARID_DEF.Sts_a_c = 0U;
    ME11_ARID_DEF.is_Diagnostic_h = ME11_IN_Init_i;
    ME11_ARID_DEF.TempVol_b = ACSen_sMixDoorPerc;
  } else {
    switch (ME11_ARID_DEF.is_Move_b) {
     case ME11_IN_ALLCool:
      ME11_ARID_DEF.p_n = 1U;
      ME11_ARID_DEF.n_d = 0U;
      if (ME11_ARID_DEF.temporalCounter_i1_f >= 5U) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
        ME11_ARID_DEF.Sts_a_c = 0U;
      }
      break;

     case ME11_IN_AllWarm:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 1U;
      if (ME11_ARID_DEF.temporalCounter_i1_f >= 10U) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
        ME11_ARID_DEF.Sts_a_c = 0U;
      }
      break;

     case ME11_IN_Cool:
      ME11_ARID_DEF.p_n = 1U;
      ME11_ARID_DEF.n_d = 0U;
      ME11_ARID_DEF.MoveSts_m = true;
      if (IOCtl_sMixDoorTrgPos > ACSen_sMixDoorPerc - cal_MixDoorNErr) {
        if (IOCtl_sMixDoorTrgPos < cal_MixCoolTrgPos) {
          ME11_ARID_DEF.is_Move_b = ME11_IN_ALLCool;
          ME11_ARID_DEF.temporalCounter_i1_f = 0U;
          ME11_ARID_DEF.p_n = 1U;
          ME11_ARID_DEF.n_d = 0U;
        } else {
          ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
          ME11_ARID_DEF.p_n = 0U;
          ME11_ARID_DEF.n_d = 0U;
          ME11_ARID_DEF.MoveSts_m = false;
          ME11_ARID_DEF.Sts_a_c = 0U;
        }
      } else if (ME11_ARID_DEF.Sts_a_c == 1) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_OutMix_Stuck;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_f >= 600U) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Fault1_c;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
      }
      break;

     case ME11_IN_Default_d2:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 0U;
      ME11_ARID_DEF.MoveSts_m = false;
      if ((IOCtl_sMixDoorTrgPos > ACSen_sMixDoorPerc + cal_MixDoorPErr) &&
          rtb_Compare_mos) {
        ME11_ARID_DEF.Stuck_Sts_f = false;
        ME11_ARID_DEF.is_Move_b = ME11_IN_Warm;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 1U;
        ME11_ARID_DEF.MoveSts_m = true;
      } else if ((IOCtl_sMixDoorTrgPos < ACSen_sMixDoorPerc - cal_MixDoorNErr) &&
                 rtb_Compare_mos) {
        ME11_ARID_DEF.Stuck_Sts_f = false;
        ME11_ARID_DEF.is_Move_b = ME11_IN_Cool;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 1U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = true;
      }
      break;

     case ME11_IN_Fault_d:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 0U;
      ME11_ARID_DEF.MoveSts_m = false;
      if (cal_MixDoorEnb || (ME11_ARID_DEF.temporalCounter_i1_f >= 1000U)) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
        ME11_ARID_DEF.Sts_a_c = 0U;
      }
      break;

     case ME11_IN_Fault1_c:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 0U;
      ME11_ARID_DEF.MoveSts_m = false;
      if (cal_MixDoorEnb || (ME11_ARID_DEF.temporalCounter_i1_f >= 1000U)) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
        ME11_ARID_DEF.Sts_a_c = 0U;
      }
      break;

     case ME11_IN_InMix_Stuck:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 0U;
      ME11_ARID_DEF.MoveSts_m = false;
      if (ME11_ARID_DEF.temporalCounter_i1_f >= 20U) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Warm;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 1U;
        ME11_ARID_DEF.MoveSts_m = true;
      } else if (ME11_ARID_DEF.Sts_a_c == 2) {
        ME11_ARID_DEF.Stuck_Sts_f = true;
        ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
        ME11_ARID_DEF.Sts_a_c = 0U;
      }
      break;

     case ME11_IN_OutMix_Stuck:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 0U;
      ME11_ARID_DEF.MoveSts_m = false;
      if (ME11_ARID_DEF.Sts_a_c == 2) {
        ME11_ARID_DEF.Stuck_Sts_f = true;
        ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
        ME11_ARID_DEF.Sts_a_c = 0U;
      } else if (ME11_ARID_DEF.temporalCounter_i1_f >= 20U) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Cool;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 1U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = true;
      }
      break;

     default:
      ME11_ARID_DEF.p_n = 0U;
      ME11_ARID_DEF.n_d = 1U;
      ME11_ARID_DEF.MoveSts_m = true;
      if (IOCtl_sMixDoorTrgPos < ACSen_sMixDoorPerc + cal_MixDoorPErr) {
        if (IOCtl_sMixDoorTrgPos > cal_MixWarmTrgPos) {
          ME11_ARID_DEF.is_Move_b = ME11_IN_AllWarm;
          ME11_ARID_DEF.temporalCounter_i1_f = 0U;
          ME11_ARID_DEF.p_n = 0U;
          ME11_ARID_DEF.n_d = 1U;
        } else {
          ME11_ARID_DEF.is_Move_b = ME11_IN_Default_d2;
          ME11_ARID_DEF.p_n = 0U;
          ME11_ARID_DEF.n_d = 0U;
          ME11_ARID_DEF.MoveSts_m = false;
          ME11_ARID_DEF.Sts_a_c = 0U;
        }
      } else if (ME11_ARID_DEF.Sts_a_c == 1) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_InMix_Stuck;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
      } else if (ME11_ARID_DEF.temporalCounter_i1_f >= 600U) {
        ME11_ARID_DEF.is_Move_b = ME11_IN_Fault_d;
        ME11_ARID_DEF.temporalCounter_i1_f = 0U;
        ME11_ARID_DEF.p_n = 0U;
        ME11_ARID_DEF.n_d = 0U;
        ME11_ARID_DEF.MoveSts_m = false;
      }
      break;
    }

    switch (ME11_ARID_DEF.is_Diagnostic_h) {
     case ME11_IN_Init_i:
      if (ME11_ARID_DEF.MoveSts_m) {
        ME11_ARID_DEF.is_Diagnostic_h = ME11_IN_wait_k;
        ME11_ARID_DEF.temporalCounter_i2_e = 0U;
      } else {
        ME11_ARID_DEF.TempVol_b = ACSen_sMixDoorPerc;
      }
      break;

     case ME11_IN_Judge:
      ME11_ARID_DEF.is_Diagnostic_h = ME11_IN_Init_i;
      ME11_ARID_DEF.TempVol_b = ACSen_sMixDoorPerc;
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i2_e >= 5U) {
        if ((float32)fabs(ME11_ARID_DEF.TempVol_b - ACSen_sMixDoorPerc) < 0.04F)
        {
          ME11_ARID_DEF.is_Diagnostic_h = ME11_IN_Judge;
          b_previousEvent = ME11_ARID_DEF.Sts_a_c + 1;
          if (ME11_ARID_DEF.Sts_a_c + 1 > 255) {
            b_previousEvent = 255;
          }

          ME11_ARID_DEF.Sts_a_c = (uint8)b_previousEvent;
        } else {
          ME11_ARID_DEF.is_Diagnostic_h = ME11_IN_Init_i;
          ME11_ARID_DEF.TempVol_b = ACSen_sMixDoorPerc;
        }
      }
      break;
    }
  }

  IOCtl_bMixStall = ME11_ARID_DEF.Stuck_Sts_f;
  ME11_ARID_DEF.VectorConcatenate[34] = IOCtl_bMixStall;
  ME11_ARID_DEF.VectorConcatenate[35] = (ACSen_eSOLARSenSts == Ground);
  ME11_ARID_DEF.VectorConcatenate[36] = (ACSen_eSOLARSenSts == Power);
  for (b_previousEvent = 0; b_previousEvent < 37; b_previousEvent++) {
    ME11_ARID_DEF.GLB_TMSFaultSEN[b_previousEvent] =
      ME11_ARID_DEF.VectorConcatenate[b_previousEvent];
  }

  ME11_ARID_DEF.EEWrite_AmbienceTemp = (uint8)((uint8)(ME11_ARID_DEF.OutData +
    40.0F) << 1);
  rtb_Divide_ox = (uint16)((ACSen_sFaceDuctTempFilter + 40.0F) * 10.0F);
  Buffer_DcmDspData_F266H[0] = (uint8)rtb_Divide_ox;
  Buffer_DcmDspData_F266H[1] = (uint8)((uint32)rtb_Divide_ox >> 8);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941311), rtb_Delay_ku);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941315), rtb_Compare_ij);
  rtb_Divide_ox = (uint16)((ACSen_sFootDuctTempFilter + 40.0F) * 10.0F);
  Buffer_DcmDspData_F267H[0] = (uint8)rtb_Divide_ox;
  Buffer_DcmDspData_F267H[1] = (uint8)((uint32)rtb_Divide_ox >> 8);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941411), rtb_Add2_j5);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941515),
                     rtb_DataTypeConversion1_g);
  Rte_DIDReadData((uint8)(2.0F * (ACSen_sCabinTempFilter + 40.0F)), ((uint8)
    DID_0xF261));
  Rte_DIDReadData((uint8)(2.0F * (ACSen_sEnvTempCor + 40.0F)), ((uint8)
    DID_0xF260));
  Rte_DIDReadData((uint8)(100.0F * ACSen_sLoPressFilter), ((uint8)DID_0xF282));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942011), rtb_Compare_bxp);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942015), rtb_Add4_ox);
  Rte_DIDReadData((uint8)(ACSen_sChiTempFilter + 10.0F), ((uint8)DID_0xF27F));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941F11), rtb_Compare_nw0);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941F15), rtb_Compare_i1);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941B11), rtb_MultiportSwitch1);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941B15), rtb_Switch2_gua);
  Rte_DIDReadData((uint8)(ACSen_sEvapTempFilter + 40.0F), ((uint8)DID_0xF263));
  Rte_DIDReadData((uint8)(ACSen_sEvapSurTemp + 50.0F), ((uint8)DID_0xF262));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941A11), rtb_IFreezFlag_bd);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941A15), rtb_IFreezFlag_jz);
  Rte_DIDReadData((uint8)(ACSen_sOHXTempFilter + 40.0F), ((uint8)DID_0xF280));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942211), rtb_Add_ge3);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942215), rtb_Compare);
  Rte_DIDReadData((uint8)(ACSen_sWCCHiTempFilter + 40.0F), ((uint8)DID_0xF265));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941E11), rtb_Add6_d);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941E15), rtb_Add5_d);
  Rte_DIDReadData((uint8)(10.0F * ACSen_sHiPressFilter), ((uint8)DID_0xF264));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941D11), rtb_Add7_i);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x941D15), rtb_Add3_do);
  Rte_DIDReadData((uint8)(ACSen_sACCMHiTempFilter + 10.0F), ((uint8)DID_0xF281));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942111),
                     rtb_DataTypeConversion19);
  Dem_SetEventStatus(((uint8)DemEventParameter_0x942115),
                     rtb_DataTypeConversion2_a);
  if (ME11_ARID_DEF.temporalCounter_i1_j2 < 1U) {
    ME11_ARID_DEF.temporalCounter_i1_j2++;
  }

  if (ME11_ARID_DEF.is_active_c156_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c156_ME11 = 1U;
    ME11_ARID_DEF.is_c156_ME11 = ME11_IN_Counter_Init;
    ME11_ARID_DEF.temporalCounter_i1_j2 = 0U;
    PWRCtl_uTMSRunTimer20ms = 0U;
  } else if (ME11_ARID_DEF.is_c156_ME11 == ME11_IN_Counter_Cal) {
    if (PWRCtl_uTMSRunTimer20ms >= 4294967294U) {
      ME11_ARID_DEF.is_c156_ME11 = ME11_IN_Counter_Init;
      ME11_ARID_DEF.temporalCounter_i1_j2 = 0U;
      PWRCtl_uTMSRunTimer20ms = 0U;
    } else {
      rtb_Divide1_f = PWRCtl_uTMSRunTimer20ms + 1U;
      if (PWRCtl_uTMSRunTimer20ms + 1U < PWRCtl_uTMSRunTimer20ms) {
        rtb_Divide1_f = MAX_uint32_T;
      }

      PWRCtl_uTMSRunTimer20ms = rtb_Divide1_f;
    }
  } else if (ME11_ARID_DEF.temporalCounter_i1_j2 >= 1) {
    ME11_ARID_DEF.is_c156_ME11 = ME11_IN_Counter_Cal;
  }

  ME11_ARID_DEF.EEWrite_UnlockVentSts = HMICtl_eUnlckVentSts;
  rtb_BusCreator.TMS_HVReq_flg = (ME11_ARID_DEF.Delay_DSTATE_kf ||
    (ACTCtl_sPTCReqPower >= 0.5F));
  rtb_Compare_bxp = Rte_IOCtrl(((uint8)IODID_0x0x3237));
  if (ME11_ARID_DEF.temporalCounter_i1_hy < 15U) {
    ME11_ARID_DEF.temporalCounter_i1_hy++;
  }

  if (ME11_ARID_DEF.is_active_c13_ME11 == 0U) {
    ME11_ARID_DEF.is_active_c13_ME11 = 1U;
    ME11_ARID_DEF.is_c13_ME11 = ME11_IN_Off_a;
    ME11_ARID_DEF.C = false;
  } else {
    switch (ME11_ARID_DEF.is_c13_ME11) {
     case ME11_IN_Off_a:
      ME11_ARID_DEF.C = false;
      if (ME11_ARID_DEF.DataTypeConversion1 >= 2) {
        ME11_ARID_DEF.is_c13_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.C = true;
      }
      break;

     case ME11_IN_On_li:
      ME11_ARID_DEF.C = true;
      if (ME11_ARID_DEF.DataTypeConversion1 <= 1) {
        ME11_ARID_DEF.is_c13_ME11 = ME11_IN_Wait_c;
        ME11_ARID_DEF.temporalCounter_i1_hy = 0U;
      }
      break;

     default:
      if (ME11_ARID_DEF.temporalCounter_i1_hy >= 10U) {
        ME11_ARID_DEF.is_c13_ME11 = ME11_IN_Off_a;
        ME11_ARID_DEF.C = false;
      } else if (ME11_ARID_DEF.DataTypeConversion1 >= 2) {
        ME11_ARID_DEF.is_c13_ME11 = ME11_IN_On_li;
        ME11_ARID_DEF.C = true;
      }
      break;
    }
  }

  if (cal_PwrHVPartEnb) {
    rtb_Compare_mos = cal_PwrHVPartData;
  } else if (Rte_DcmDspData_3237_CtlFlg == 1) {
    rtb_Compare_mos = ((rtb_Compare_bxp & 1) == 1);
  } else {
    rtb_Compare_mos = ME11_ARID_DEF.C;
  }

  ME11_Delay(rtb_Compare_mos, &ME11_ARID_DEF.C_i,
             &ME11_ARID_DEF.ARID_DEF_Delay_l);
  if (cal_PwrACPumpEnb) {
    rtb_Switch_n2 = cal_PwrACPumpData;
  } else if (Rte_DcmDspData_3237_CtlFlg == 1) {
    rtb_Switch_n2 = ((rtb_Compare_bxp & 4) == 4);
  } else {
    rtb_Switch_n2 = ME11_ARID_DEF.C_i;
  }

  ME11_Delay(rtb_Compare_mos, &ME11_ARID_DEF.C_g, &ME11_ARID_DEF.ARID_DEF_Delay);
  if (cal_PwrFanAndPumpDataEnb) {
    rtb_Compare = cal_PwrFanAndPumpData;
  } else if (Rte_DcmDspData_3237_CtlFlg == 1) {
    rtb_Compare = (uint8)((rtb_Compare_bxp & 2) == 2);
  } else {
    rtb_Compare = ME11_ARID_DEF.C_g;
  }

  if (cal_SOVEnb) {
    rtb_Switch_kl = cal_SOVData;
  } else if (Rte_DcmDspData_3237_CtlFlg == 1) {
    rtb_Switch_kl = ((rtb_Compare_bxp & 8) == 8);
  } else {
    rtb_Switch_kl = ((ME11_ARID_DEF.DataTypeConversion1 >= 2) && ACTCtl_bSOVCmd);
  }

  rtb_Add_ge3 = (uint8)((((uint32)(rtb_Switch_n2 << 3) + (uint32)
    (rtb_Compare_mos << 2)) + (uint32)(rtb_Compare << 1)) + rtb_Switch_kl);
  IOCtl_PwrNmReqFlg = (rtb_Add_ge3 != 0);
  rtb_BusCreator.AppSwcTmsVersion = 5U;
  rtb_BusCreator.TMS_NMReq_flg = IOCtl_PwrNmReqFlg;
  if (ME11_ARID_DEF.DataTypeConversion1 < 2) {
    rtb_DataTypeConversion23 = 0.0F;
  } else {
    rtb_DataTypeConversion23 = PWRCtl_sCOMPActlPwr +
      (Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
      ->VIPM_HVCHPwr_kW;
  }

  rtb_BusCreator1.AC_1_Chksum = 0U;
  rtb_BusCreator1.AC_1_AliveCnt = 0U;
  rtb_BusCreator1.AC_CompFailModeOprtSta = false;
  rtb_BusCreator1.AC_CompOprtReq = ME11_ARID_DEF.Delay_DSTATE_kf;
  rtb_BusCreator1.AC_CompOprtEnaCmd = ME11_ARID_DEF.Delay_DSTATE_kf;
  rtb_BusCreator1.AC_CompTgtSpd = (uint16)ACTCtl_sACCMCtlSpd;
  rtb_BusCreator1.AC_CompMaxAllowPwrCmsp = PWRCtl_sLmtPwrCOMP;
  rtb_BusCreator1.AC_PumpActlSpdDuty = ACTCtl_eAcPMPSpdSet;
  rtb_BusCreator1.AC_HighVolDCTolalPwr = rtb_DataTypeConversion23;
  rtb_BusCreator1.AC_PumpActlSpdDutyV = !ACTCtl_bAcPMPFaultFlg;
  rtb_BusCreator10.TMS_HPEXVCurrentPosition = (uint16)(6.4F *
    HP_EXV_CurrentPosition_B);
  rtb_BusCreator10.TMS_C5WVBPosSetReq = ACTCtl_eC5WVValue;
  rtb_BusCreator10.TMS_C3WVBPosSetReq = ACTCtl_eC3WVValue;
  rtb_BusCreator10.TMS_HPEXVEnableCmd = ACTCtl_bHPEXVEnb;
  rtb_BusCreator10.TMS_BEXVEnableCmd = ACTCtl_bBEXVEnb;
  rtb_BusCreator10.TMS_AEXVEnableReq = ACTCtl_bAEXVEnb;
  rtb_BusCreator10.TMS_C5WVPosRec = BCV_PosRec;
  rtb_BusCreator10.TMS_C3WVPosRec = MCV_PosRec;
  rtb_BusCreator10.TMS_C5WVMode = BCV_Mode;
  rtb_BusCreator10.TMS_C3WVMode = MCV_Mode;
  rtb_BusCreator2.AC_HVHDeviceInternTemp_HVAC = (sint8)(float32)floor
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHInletTemp_C);
  rtb_BusCreator2.AC_HVHFailSta_HVAC =
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
     ->VIPM_HVCHFltCod_enum >= 1);
  rtb_BusCreator2.AC_2_Chksum = 0U;
  rtb_BusCreator2.AC_2_AliveCnt = 0U;
  rtb_BusCreator2.AC_HVHActlPwr_HVAC =
    (Rte_IRead_Task_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD())
    ->VIPM_HVCHPwr_kW;
  rtb_BusCreator2.TMS_PTPressure = 1000.0F * ACSen_sHiPressFilter;
  rtb_BusCreator2.AC_ActTotalPower = rtb_DataTypeConversion23;
  rtb_BusCreator2.AC_FailSta = false;
  rtb_BusCreator2.TMSR_BattTempCtrlRmnSwtFb = false;
  rtb_BusCreator2.AC_BatPumpFailSta = false;
  rtb_BusCreator2.AC_HVHActlOprtMode_HVAC =
    (Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
    ->VIPM_HVCHWorkMode_enum;
  rtb_BusCreator2.AC_ActlOprtMode = HMICtl_eACSts;
  rtb_BusCreator2.TMS_PTTemp = (sint8)(float32)floor(ACSen_sWCCHiTempFilter);
  rtb_BusCreator6.AC_Checksum = 0U;
  rtb_BusCreator6.AC_RollingCounter = 0U;
  rtb_BusCreator6.COMP_EcompSpeedCtrl = ACTCtl_sACCMCtlSpd;
  rtb_BusCreator6.COMP_EcompEnable = ME11_ARID_DEF.Delay_DSTATE_kf;
  rtb_BusCreator6.COMP_CompInputPowerLimit = 1000.0F * PWRCtl_sLmtPwrCOMP;
  rtb_BusCreator6.TMS_ACPExhaustTmp = (sint8)(float32)floor
    (ACSen_sACCMHiTempFilter);
  rtb_BusCreator6.TMS_ACPInletPressure = 1000.0F * ACSen_sLoPressFilter;
  rtb_BusCreator7.HVCHCmd_Checksum = 0U;
  rtb_BusCreator7.HVCHCmd_RollingCounter = 0U;
  rtb_BusCreator7.HVCH_RequestTemp = (sint8)(float32)floor
    (ACTCtl_sPTCRequestTemp);
  rtb_BusCreator7.HVCH_RequestPower = ACTCtl_sPTCReqPower;
  rtb_BusCreator7.HVCH_Enabled = ACTCtl_sPTCEnable;
  rtb_BusCreator8.TMS_AcPMPSpdSet = 0.400390625F * (float32)ACTCtl_eAcPMPSpdSet;
  rtb_BusCreator8.TMS_BatPMPSpdSet = 0.400390625F * (float32)
    ACTCtl_eBatPMPSpdSet;
  rtb_BusCreator8.TMS_MotPMPSpdSet = 0.400390625F * (float32)
    ACTCtl_eMotPMPSpdSet;
  rtb_BusCreator8.TMS_MotPMPRealRPM = MotPMP_RealRPM;
  rtb_BusCreator8.TMS_BatPMPRealRPM = BatPMP_RealRPM;
  rtb_BusCreator8.TMS_AcPMPRealRPM = AcPMP_RealRPM;
  rtb_BusCreator8.TMS_HPEXVPositionCmd = (uint16)(6.4F * ACTCtl_sHPEXVPos);
  rtb_BusCreator9.TMS_AEXVPositionReq = (uint16)(6.4F * ACTCtl_sAEXVPos);
  rtb_BusCreator9.TMS_BEXVPositionCmd = (uint16)(6.4F * ACTCtl_sBEXVPos);
  rtb_BusCreator9.TMS_BEXVCurrentPosition = (uint16)(6.4F *
    BAT_EXV_CurrentPosition_B);
  rtb_BusCreator9.TMS_AEXVCurrentPosition = (uint16)(6.4F * EXV_CurrentPosition);
  rtb_BusCreator3.TMS_EvapOutTmp = (sint8)(float32)floor(ACSen_sEvapTempFilter);
  rtb_BusCreator3.AC_3_Chksum = 0U;
  rtb_BusCreator3.AC_3_AliveCnt = 0U;
  rtb_BusCreator3.AC_ExtdDefrostActvReq = SOMCtl_bExtDefFlg;
  rtb_BusCreator3.AC_EnvirTempV = !rtb_RelationalOperator_kh;
  rtb_BusCreator3.AC_IndoorTemp = ACSen_sCabinTempFilter;
  rtb_BusCreator3.AC_EnvirTemp = ACSen_sEnvTempCor;
  rtb_BusCreator3.TMS_OHXOutTmp = (sint8)(float32)floor(ACSen_sOHXTempFilter);
  rtb_BusCreator3.TMS_EvapTmp = (sint8)(float32)floor(ACSen_sEvapSurTemp);
  rtb_BusCreator3.TMS_ChillerOutTmp = (sint8)(float32)floor(ACSen_sChiTempFilter);
  rtb_BusCreator4.AC_HV_PTC_InternalPCBTemp = (sint8)(float32)floor
    ((Rte_IRead_Task_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD())
     ->VIPM_HVCHPCBTemp_C);
  rtb_BusCreator4.AC_8_Checksum = 0U;
  rtb_BusCreator4.AC_8_RollingCounter = 0U;
  rtb_BusCreator4.AC_RefrgLoPressureV = !rtb_Compare_oc;
  rtb_BusCreator4.AC_RefrgLoPressure = ACSen_sLoPressFilter;
  rtb_BusCreator4.AC_L_Currt_Slct_Frg_Dirct = false;
  rtb_BusCreator4.AC_HV_PTC_heating_rq = ACTCtl_sPTCEnable;
  rtb_BusCreator4.AC_HV_PTC_MediumTemp = 0;
  rtb_BusCreator4.AC_EvapTgtTemp = ACCtl_tSetPointEvap;
  rtb_BusCreator4.AC_HV_PTC_On_Rq = ACTCtl_sPTCEnable;
  rtb_BusCreator4.AC_Auto_FrontFanSpd = AC_FanLeVel;
  rtb_BusCreator5.BCM_RearViewMirrHeatingSts =
    ((Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
     ->BCM_RearMirrorHeatSts != 0);
  rtb_BusCreator5.AC_ACStatus_Chksum = 0U;
  rtb_BusCreator5.AC_ACStatus_AliveCnt = 0U;
  rtb_BusCreator5.AC_leftTempValue = ME11_ARID_DEF.Delay1_DSTATE_fq;
  rtb_BusCreator5.AC_ManualDefrostFb = HMICtl_bACDefrost;
  rtb_BusCreator5.AC_ACAutoFb = HMICtl_bACAuto;
  rtb_BusCreator5.AC_BlowerModeSta = rtb_Switch1_e3;
  if (HMICtl_bACAuto) {
    rtb_BusCreator5.AC_FrontFanSpdValue = AC_FanLeVel;
  } else {
    rtb_BusCreator5.AC_FrontFanSpdValue = ME11_ARID_DEF.Switch1_n;
  }

  rtb_BusCreator5.AC_ACPowerFb = ME11_ARID_DEF.Switch_c;
  rtb_BusCreator5.AC_AutoBlowerModeSta = rtb_Switch1_e3;
  rtb_BusCreator5.AC_HybridEcoModeSta = HMICtl_eACSts;
  rtb_BusCreator5.AC_AirInletModeSta = rtb_IFreezFlag_k;
  rtb_BusCreator11.TMS_MotInletCooltTemp = (sint8)(float32)floor
    (ACSen_sMotTempFilter);
  rtb_BusCreator11.TMS_PwrCoolFanSpdDuty = ACTCtl_eFanPerc;
  rtb_BusCreator11.TMS_BATThermalMod = rtb_DataTypeConversion1_l;
  rtb_BusCreator11.TMS_CabThermalMod = rtb_DataTypeConversion1_on;
  rtb_BusCreator11.AC_ACUnlockVentSetFB = HMICtl_eUnlckVentSts;
  rtb_BusCreator11.CCU_RemoteLockFb = 0U;
  rtb_BusCreator11.CCU_RemoteCarSearchFb = 0U;
  rtb_BusCreator11.CCU_OpenVentilationFb = 0U;
  rtb_BusCreator11.AC_RemtCtrlFb = RMTCtl_bRemtACFlg;
  rtb_BusCreator11.AC_TempSetFb = RMTCtl_bRemtACFlg;
  rtb_BusCreator11.AC_RemoteDefrostCtlFb = RMTCtl_bRemtACDefFlg;
  ME11_TMSIODriverFunc();
  if (ME11_ARID_DEF.Stuck_Sts_a) {
    rtb_Delay_ku = (uint8)(ME11_ARID_DEF.Stuck_Sts_a ? 3 : 0);
  } else if (ME11_ARID_DEF.MoveSts_d) {
    rtb_Delay_ku = (uint8)(ME11_ARID_DEF.MoveSts_d << 1);
  } else {
    rtb_Delay_ku = (uint8)(cal_RecircTrgPosDataEnb || cal_RecircMotorEnb);
  }

  Rte_DIDReadData(rtb_Delay_ku, ((uint8)DID_0xF26A));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943271),
                     ME11_ARID_DEF.Stuck_Sts_a);
  if (ME11_ARID_DEF.Stuck_Sts_f) {
    rtb_Delay_ku = (uint8)(ME11_ARID_DEF.Stuck_Sts_f ? 3 : 0);
  } else if (ME11_ARID_DEF.MoveSts_m) {
    rtb_Delay_ku = (uint8)(ME11_ARID_DEF.MoveSts_m << 1);
  } else {
    rtb_Delay_ku = (uint8)(cal_SetLeftMixDoorTrgDataEnb || cal_MixDoorEnb);
  }

  Rte_DIDReadData(rtb_Delay_ku, ((uint8)DID_0xF26B));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943571),
                     ME11_ARID_DEF.Stuck_Sts_f);
  if (ME11_ARID_DEF.Stuck_Sts > 0) {
    rtb_Delay_ku = (uint8)(3U * ME11_ARID_DEF.Stuck_Sts);
  } else if (ME11_ARID_DEF.MoveSts) {
    rtb_Delay_ku = (uint8)(ME11_ARID_DEF.MoveSts << 1);
  } else {
    rtb_Delay_ku = (uint8)(cal_ModeMotorTrgPosDataEnb || cal_ModeMotorEnb);
  }

  Rte_DIDReadData(rtb_Delay_ku, ((uint8)DID_0xF269));
  Dem_SetEventStatus(((uint8)DemEventParameter_0x943371),
                     ME11_ARID_DEF.Stuck_Sts);
  if (cal_BlwFanEnb) {
    IOCtl_BloweFanSpeed = cal_BlwFanData;
  } else if (ACCtl_BloweFanSpeed > ME11_ARID_DEF.Delay_DSTATE_f) {
    IOCtl_BloweFanSpeed = ME11_ARID_DEF.Delay_DSTATE_f;
  } else if (ACCtl_BloweFanSpeed < AC_BlowerFanSpeedMin) {
    IOCtl_BloweFanSpeed = AC_BlowerFanSpeedMin;
  } else {
    IOCtl_BloweFanSpeed = ACCtl_BloweFanSpeed;
  }

  rtb_DataTypeConversion2_a = (uint8)(100 - IOCtl_BloweFanSpeed);
  set_BlwFan(cal_BlwFrqVal, (uint8)(100 - IOCtl_BloweFanSpeed));
  Rte_DIDReadData(rtb_DataTypeConversion2_a, ((uint8)DID_0xF26D));
  if (cal_PwrBlwEnb) {
    rtb_Compare_gzu = cal_PwrBlwData;
  } else {
    rtb_Compare_gzu = ((ME11_ARID_DEF.DataTypeConversion1 >= 2) ||
                       PWRCtl_bUnlockVentTimeFlg);
  }

  SetHw_PwrBlower(rtb_Compare_gzu);
  if (cal_PwrFanEnb) {
    rtb_Compare_gzu = cal_PwrFanData;
  } else {
    rtb_Compare_gzu = (ME11_ARID_DEF.DataTypeConversion1 >= 1);
  }

  set_PwrFanCabin(rtb_Compare_gzu);
  if (cal_PwrSensorEnb) {
    rtb_Compare_gzu = cal_PwrSensorData;
  } else {
    rtb_Compare_gzu = (ME11_ARID_DEF.DataTypeConversion1 >= 1);
  }

  set_PwrSensor(rtb_Compare_gzu);
  set_PwrACPump(rtb_Switch_n2);
  Rte_DIDReadData(rtb_Add_ge3, ((uint8)DID_0xF26F));
  set_PwrFanAndPump(rtb_Compare);
  set_PwrHVPart(rtb_Compare_mos);
  set_PwrSOV(rtb_Switch_kl);
  set_CoolFan(100U, (uint8)(100 - ACTCtl_eFanPerc));
  AcPMP_PumpInputVolt =
    Rte_IRead_Task_100ms_AcPMP_PumpInputVolt_AcPMP_PumpInputVolt();
  AcPMP_ProjectCode1 =
    Rte_IRead_Task_100ms_AcPMP_ProjectCode1_AcPMP_ProjectCode1();
  AcPMP_ProjectCode2 =
    Rte_IRead_Task_100ms_AcPMP_ProjectCode2_AcPMP_ProjectCode2();
  AcPMP_SupplierNumber =
    Rte_IRead_Task_100ms_AcPMP_SupplierNumber_AcPMP_SupplierNumber();
  AcPMP_PartNumber = Rte_IRead_Task_100ms_AcPMP_PartNumber_AcPMP_PartNumber();
  AcPMP_HWVersion = Rte_IRead_Task_100ms_AcPMP_HWVersion_AcPMP_HWVersion();
  AcPMP_SWVersion_Main =
    Rte_IRead_Task_100ms_AcPMP_SWVersion_Main_AcPMP_SWVersion_Main();
  AcPMP_SWVersion_Sub =
    Rte_IRead_Task_100ms_AcPMP_SWVersion_Sub_AcPMP_SWVersion_Sub();
  AcPMP_SWVersion_Patch =
    Rte_IRead_Task_100ms_AcPMP_SWVersion_Patch_AcPMP_SWVersion_Patch();
  Rte_DIDReadData((uint8)Rte_IRead_Task_100ms_C5WVPosRec_C5WVPosRec(), ((uint8)
    DID_0xF27B));
  BCV_RunSts = Rte_IRead_Task_100ms_C5WVRunSts_C5WVRunSts();
  BCV_SpdLvl = Rte_IRead_Task_100ms_C5WVSpdLvl_C5WVSpdLvl();
  Rte_DIDReadData((uint8)(BMS_InletCooltActlTemp + 40.0F), ((uint8)DID_0xF279));
  BatPMP_PumpInputVolt =
    Rte_IRead_Task_100ms_BatPMP_PumpInputVolt_BatPMP_PumpInputVolt();
  Rte_DIDReadData((uint8)Rte_IRead_Task_100ms_C3WV_PosRec_C3WV_PosRec(), ((uint8)
    DID_0xF27A));
  MCV_RunSts = Rte_IRead_Task_100ms_C3WV_RunSts_C3WV_RunSts();
  MCV_SpdLvl = Rte_IRead_Task_100ms_C3WV_SpdLvl_C3WV_SpdLvl();
  MotPMP_PumpInputVolt =
    Rte_IRead_Task_100ms_MotPMP_PumpInputVolt_MotPMP_PumpInputVolt();
  rtb_Divide_ox = (uint16)(6.4F * ACTCtl_sHPEXVPos);
  rtb_Compare_mos = ACTCtl_bHPEXVEnb;
  rtb_DataTypeConversion1_on = ACTCtl_bHPEXVInitReq;
  rtb_Gain_az = (uint16)(6.4F * ACTCtl_sBEXVPos);
  rtb_Compare_cj1 = ACTCtl_bBEXVEnb;
  rtb_DataTypeConversion1_l = ACTCtl_bBEXVInitReq;
  rtb_Gain1_j_0 = (uint16)(6.4F * ACTCtl_sAEXVPos);
  rtb_Compare_fhh = ACTCtl_bAEXVEnb;
  rtb_Compare_bxp = ACTCtl_bAEXVInitReq;
  rtb_Compare_nw0 = ACTCtl_eC3WVValue;
  rtb_IFreezFlag_k = ACTCtl_eC3WVSLSts;
  rtb_Compare_i1 = ACTCtl_eC5WVValue;
  rtb_Compare = ACTCtl_eC5WVSLSts;
  rtb_Compare_ij = ACTCtl_eAcPMPSpdSet;
  rtb_DataTypeConversion1_g = ACTCtl_eBatPMPSpdSet;
  rtb_IFreezFlag_bd = ACTCtl_eMotPMPSpdSet;
  SOMCtl_eCabinModePre = PWRCtl_eTMSStatus_a;
  ME11_ARID_DEF.Relay_Mode_jw = ((ACSen_sMotTempFilter >= cal_MotTempUpLmt) ||
    ((ACSen_sMotTempFilter > cal_MotTempDownLmt) && ME11_ARID_DEF.Relay_Mode_jw));
  ME11_ARID_DEF.Relay1_Mode_n =
    (((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
      ->VIPM_INV2IgbtMaxTemp_C >= cal_IGBTUpLmtTemp) ||
     (((Rte_IRead_Task_100ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT())
       ->VIPM_INV2IgbtMaxTemp_C > cal_IGBTDownLmtTemp) &&
      ME11_ARID_DEF.Relay1_Mode_n));
  if (cal_HVPartModeEnb) {
    SOMCtl_eHVPartMode = cal_HVPartModeData;
  } else if ((sint32)ME11_ARID_DEF.Relay_Mode_jw >= (sint32)
             ME11_ARID_DEF.Relay1_Mode_n) {
    SOMCtl_eHVPartMode = (uint8)ME11_ARID_DEF.Relay_Mode_jw;
  } else {
    SOMCtl_eHVPartMode = 1U;
  }

  COMP_EcompST = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPEcompST_enum;
  COMP_Temperature = (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_COMPTemp_C;
  ECUHighVoltInterlockSignal =
    (Rte_IRead_Task_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD())
    ->VIPM_ECUHiVoltInterlockSig_flg;
  rtb_VectorConcatenate_dq[0] = ME11_ARID_DEF.EEWrite_bACOnOff;
  rtb_VectorConcatenate_dq[1] = ME11_ARID_DEF.EEWrite_bACAutoSts;
  rtb_VectorConcatenate_dq[2] = ME11_ARID_DEF.EEWrite_CabinSetTemp;
  rtb_VectorConcatenate_dq[3] = ME11_ARID_DEF.EEWrite_AmbienceTemp;
  rtb_VectorConcatenate_dq[4] = ME11_ARID_DEF.EEWrite_CabinMode;
  rtb_VectorConcatenate_dq[5] = ME11_ARID_DEF.EEWrite_CabinBlower;
  rtb_VectorConcatenate_dq[6] = ME11_ARID_DEF.EEWrite_PCUInletTemp;
  rtb_VectorConcatenate_dq[7] = ME11_ARID_DEF.EEWrite_TimeHour;
  rtb_VectorConcatenate_dq[8] = ME11_ARID_DEF.EEWrite_TimeMin;
  rtb_VectorConcatenate_dq[9] = ME11_ARID_DEF.EEWrite_TimeDay;
  rtb_VectorConcatenate_dq[10] = ME11_ARID_DEF.EEWrite_CabinRecDoor;
  rtb_VectorConcatenate_dq[11] = ME11_ARID_DEF.EEWrite_CabinModeDoor;
  rtb_VectorConcatenate_dq[12] = ME11_ARID_DEF.EEWrite_UnlockVentSts;
  NvmTmsBlockWriteData(&rtb_VectorConcatenate_dq[0], 13U);
  ME11_ARID_DEF.Delay_DSTATE = ME11_ARID_DEF.OutData;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE = 0U;
  ME11_ARID_DEF.Delay_DSTATE_px = true;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_n = 0U;
  ME11_ARID_DEF.Delay1_DSTATE = ME11_ARID_DEF.OutData;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_g = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_k = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kt = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_c = 0U;
  ME11_ARID_DEF.DelayInput1_DSTATE = HMICtl_sLeftSetPoint;
  ME11_ARID_DEF.DelayInput1_DSTATE_j = HMICtl_sLeftSetPoint;
  ME11_ARID_DEF.DelayInput1_DSTATE_gyl = rtb_Compare_ly;
  ME11_ARID_DEF.UnitDelay2_DSTATE = ME11_ARID_DEF.UnitDelay3_DSTATE;
  ME11_ARID_DEF.DelayInput1_DSTATE_d = ME11_ARID_DEF.UnitDelay3_DSTATE;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_j = 0U;
  ME11_ARID_DEF.Delay_DSTATE_fl = ACCtl_BlowerMode;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_e = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_a = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ec = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kj = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_b = ME11_ARID_DEF.Delay_DSTATE_d2;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_jm = 0U;
  ME11_ARID_DEF.Delay_DSTATE_he = rtb_AND_hi;
  ME11_ARID_DEF.DelayInput1_DSTATE_h = PWRCtl_eTMSStatus_a;
  ME11_ARID_DEF.Delay_DSTATE_gh = ME11_ARID_DEF.DataTypeConversion1;
  ME11_ARID_DEF.Delay_DSTATE_jf = SOMCtl_bBatHeatFlg;
  ME11_ARID_DEF.Delay_DSTATE_bd = ME11_ARID_DEF.DataTypeConversion1;
  ME11_ARID_DEF.Delay_DSTATE_bg = SOMCtl_bBatHeatFlg;
  ME11_ARID_DEF.Delay_DSTATE_jm = SOMCtl_bBatHeatFlg;
  ME11_ARID_DEF.Delay_DSTATE_dl = SOMCtl_bBatHeatFlg;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_g3 = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_bs = ME11_ARID_DEF.Delay_DSTATE_kf;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nw = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_f = 0U;
  ME11_ARID_DEF.DelayInput1_DSTATE_ln = rtb_AND4_f;
  ME11_ARID_DEF.DelayInput1_DSTATE_ju = ME11_ARID_DEF.Delay_DSTATE_lv;
  ME11_ARID_DEF.DelayInput1_DSTATE_kp = rtb_AND1_h0y;
  ME11_ARID_DEF.Delay1_DSTATE_o = ACCtl_BloweFanSpeed;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_m = 0U;
  ME11_ARID_DEF.Delay_DSTATE_e = ME11_ARID_DEF.RecordInitialEvapTemp;
  ME11_ARID_DEF.Delay_DSTATE_hr = AC_FanLevelAct;
  ME11_ARID_DEF.Delay1_DSTATE_f = rtb_Delay1_ie;
  ME11_ARID_DEF.Delay_DSTATE_k[0] = ME11_ARID_DEF.Delay_DSTATE_k[1];
  ME11_ARID_DEF.Delay_DSTATE_k[1] = rtb_Delay1_ie;
  ME11_ARID_DEF.Delay2_DSTATE[0] = ME11_ARID_DEF.Delay2_DSTATE[1];
  ME11_ARID_DEF.Delay2_DSTATE[1] = ME11_ARID_DEF.Delay2_DSTATE[2];
  ME11_ARID_DEF.Delay2_DSTATE[2] = rtb_Delay1_ie;
  ME11_ARID_DEF.Delay3_DSTATE[0] = ME11_ARID_DEF.Delay3_DSTATE[1];
  ME11_ARID_DEF.Delay3_DSTATE[1] = ME11_ARID_DEF.Delay3_DSTATE[2];
  ME11_ARID_DEF.Delay3_DSTATE[2] = ME11_ARID_DEF.Delay3_DSTATE[3];
  ME11_ARID_DEF.Delay3_DSTATE[3] = rtb_Delay1_ie;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_gm = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_hx = rtb_IFreezFlag;
  ME11_ARID_DEF.Delay_DSTATE_o3 = rtb_SOMCtl_WaterMode;
  ME11_ARID_DEF.Delay1_DSTATE_e0 = rtb_IFreezFlag_d;
  ME11_ARID_DEF.Delay_DSTATE_bf = rtb_Delay1_i;
  ME11_ARID_DEF.Delay_DSTATE_n = ME11_ARID_DEF.RecordInitialEvapTemp_o;
  ME11_ARID_DEF.DelayInput1_DSTATE_ez =
    (Rte_IRead_Task_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC())
    ->VIPM_HUACUnlckVentSet_enum;
  ME11_ARID_DEF.Delay1_DSTATE_dt =
    (Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
    ->BCM_BodyWarnSts;
  ME11_ARID_DEF.DelayInput1_DSTATE_j5 =
    (Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
    ->BCM_DoorAjarSta_FL;
  ME11_ARID_DEF.DelayInput1_DSTATE_mu =
    (Rte_IRead_Task_100ms_Bcm2VcuTms_outputs_Bcm2VcuTms_outputs())
    ->BCM_DoorAjarSta_FR;
  ME11_ARID_DEF.Delay_DSTATE_fk = HMICtl_bACDefrost;
  ME11_ARID_DEF.Delay1_DSTATE_dt4 = ACCtl_IntakeRatio;
  ME11_ARID_DEF.DelayInput1_DSTATE_lk = HMICtl_bACDefrost;
  ME11_ARID_DEF.DelayInput1_DSTATE_ne = HMICtl_bACDefrost;
  ME11_ARID_DEF.DelayInput1_DSTATE_m = IOCtl_sModeMotorTrgPos;
  ME11_ARID_DEF.DelayInput1_DSTATE_hd = rtb_DataTypeConversion_jf;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nc = 0U;
  ME11_ARID_DEF.Delay2_DSTATE_lz = ACTCtl_bCOMPSpdDiffFlt;
  ME11_ARID_DEF.Delay_DSTATE_cv = ACTCtl_bCOMPIFreeFlag;
  ME11_ARID_DEF.Delay_DSTATE_af = rtb_Switch2_ht;
  ME11_ARID_DEF.DelayInput1_DSTATE_e = ACSen_sHiPressFilter;
  ME11_ARID_DEF.DelayInput1_DSTATE_o = ACSen_sLoPressFilter;
  ME11_ARID_DEF.DelayInput1_DSTATE_i = ACSen_sHiPressFilter;
  ME11_ARID_DEF.DelayInput1_DSTATE_g = ACSen_sLoPressFilter;
  ME11_ARID_DEF.Delay1_DSTATE_hw = ME11_ARID_DEF.DataTypeConversion1;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_fj = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_h = ACTCtl_sCoolCondDep;
  ME11_ARID_DEF.Delay_DSTATE_i[0] = ME11_ARID_DEF.Delay_DSTATE_i[1];
  ME11_ARID_DEF.Delay_DSTATE_i[1] = ACTCtl_sCoolCondDep;
  ME11_ARID_DEF.Delay2_DSTATE_h[0] = ME11_ARID_DEF.Delay2_DSTATE_h[1];
  ME11_ARID_DEF.Delay2_DSTATE_h[1] = ME11_ARID_DEF.Delay2_DSTATE_h[2];
  ME11_ARID_DEF.Delay2_DSTATE_h[2] = ACTCtl_sCoolCondDep;
  ME11_ARID_DEF.Delay3_DSTATE_i[0] = ME11_ARID_DEF.Delay3_DSTATE_i[1];
  ME11_ARID_DEF.Delay3_DSTATE_i[1] = ME11_ARID_DEF.Delay3_DSTATE_i[2];
  ME11_ARID_DEF.Delay3_DSTATE_i[2] = ME11_ARID_DEF.Delay3_DSTATE_i[3];
  ME11_ARID_DEF.Delay3_DSTATE_i[3] = ACTCtl_sCoolCondDep;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_l = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_l = ACTCtl_sEvapSuperHeat;
  ME11_ARID_DEF.Delay_DSTATE_bm[0] = ME11_ARID_DEF.Delay_DSTATE_bm[1];
  ME11_ARID_DEF.Delay_DSTATE_bm[1] = ACTCtl_sEvapSuperHeat;
  ME11_ARID_DEF.Delay2_DSTATE_a[0] = ME11_ARID_DEF.Delay2_DSTATE_a[1];
  ME11_ARID_DEF.Delay2_DSTATE_a[1] = ME11_ARID_DEF.Delay2_DSTATE_a[2];
  ME11_ARID_DEF.Delay2_DSTATE_a[2] = ACTCtl_sEvapSuperHeat;
  ME11_ARID_DEF.Delay3_DSTATE_k[0] = ME11_ARID_DEF.Delay3_DSTATE_k[1];
  ME11_ARID_DEF.Delay3_DSTATE_k[1] = ME11_ARID_DEF.Delay3_DSTATE_k[2];
  ME11_ARID_DEF.Delay3_DSTATE_k[2] = ME11_ARID_DEF.Delay3_DSTATE_k[3];
  ME11_ARID_DEF.Delay3_DSTATE_k[3] = ACTCtl_sEvapSuperHeat;
  ME11_ARID_DEF.Delay_DSTATE_op = rtb_IFreezFlag_o;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_eg = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_h = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_e = ACTCtl_sChiSuperHeat;
  ME11_ARID_DEF.Delay_DSTATE_c[0] = ME11_ARID_DEF.Delay_DSTATE_c[1];
  ME11_ARID_DEF.Delay_DSTATE_c[1] = ACTCtl_sChiSuperHeat;
  ME11_ARID_DEF.Delay2_DSTATE_k[0] = ME11_ARID_DEF.Delay2_DSTATE_k[1];
  ME11_ARID_DEF.Delay2_DSTATE_k[1] = ME11_ARID_DEF.Delay2_DSTATE_k[2];
  ME11_ARID_DEF.Delay2_DSTATE_k[2] = ACTCtl_sChiSuperHeat;
  ME11_ARID_DEF.Delay3_DSTATE_b[0] = ME11_ARID_DEF.Delay3_DSTATE_b[1];
  ME11_ARID_DEF.Delay3_DSTATE_b[1] = ME11_ARID_DEF.Delay3_DSTATE_b[2];
  ME11_ARID_DEF.Delay3_DSTATE_b[2] = ME11_ARID_DEF.Delay3_DSTATE_b[3];
  ME11_ARID_DEF.Delay3_DSTATE_b[3] = ACTCtl_sChiSuperHeat;
  ME11_ARID_DEF.Delay1_DSTATE_a = ME11_ARID_DEF.DataTypeConversion1;
  ME11_ARID_DEF.Delay_DSTATE_bmz = rtb_IFreezFlag_m;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_fz = 0U;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kg = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_gh = ACTCtl_sCondDep;
  ME11_ARID_DEF.Delay_DSTATE_hl[0] = ME11_ARID_DEF.Delay_DSTATE_hl[1];
  ME11_ARID_DEF.Delay_DSTATE_hl[1] = ACTCtl_sCondDep;
  ME11_ARID_DEF.Delay2_DSTATE_n[0] = ME11_ARID_DEF.Delay2_DSTATE_n[1];
  ME11_ARID_DEF.Delay2_DSTATE_n[1] = ME11_ARID_DEF.Delay2_DSTATE_n[2];
  ME11_ARID_DEF.Delay2_DSTATE_n[2] = ACTCtl_sCondDep;
  ME11_ARID_DEF.Delay3_DSTATE_ks[0] = ME11_ARID_DEF.Delay3_DSTATE_ks[1];
  ME11_ARID_DEF.Delay3_DSTATE_ks[1] = ME11_ARID_DEF.Delay3_DSTATE_ks[2];
  ME11_ARID_DEF.Delay3_DSTATE_ks[2] = ME11_ARID_DEF.Delay3_DSTATE_ks[3];
  ME11_ARID_DEF.Delay3_DSTATE_ks[3] = ACTCtl_sCondDep;
  ME11_ARID_DEF.Delay_DSTATE_nb = rtb_IFreezFlag_c;
  ME11_ARID_DEF.Delay1_DSTATE_gf = ME11_ARID_DEF.DataTypeConversion1;
  ME11_ARID_DEF.Delay1_DSTATE_c = ACTCtl_sExhSuperHeat;
  ME11_ARID_DEF.Delay_DSTATE_l3[0] = ME11_ARID_DEF.Delay_DSTATE_l3[1];
  ME11_ARID_DEF.Delay_DSTATE_l3[1] = ACTCtl_sExhSuperHeat;
  ME11_ARID_DEF.Delay2_DSTATE_p[0] = ME11_ARID_DEF.Delay2_DSTATE_p[1];
  ME11_ARID_DEF.Delay2_DSTATE_p[1] = ME11_ARID_DEF.Delay2_DSTATE_p[2];
  ME11_ARID_DEF.Delay2_DSTATE_p[2] = ACTCtl_sExhSuperHeat;
  ME11_ARID_DEF.Delay3_DSTATE_ij[0] = ME11_ARID_DEF.Delay3_DSTATE_ij[1];
  ME11_ARID_DEF.Delay3_DSTATE_ij[1] = ME11_ARID_DEF.Delay3_DSTATE_ij[2];
  ME11_ARID_DEF.Delay3_DSTATE_ij[2] = ME11_ARID_DEF.Delay3_DSTATE_ij[3];
  ME11_ARID_DEF.Delay3_DSTATE_ij[3] = ACTCtl_sExhSuperHeat;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nk = 0U;
  ME11_ARID_DEF.Delay1_DSTATE_lt = ACTCtl_sSuperHeat;
  ME11_ARID_DEF.Delay_DSTATE_aj[0] = ME11_ARID_DEF.Delay_DSTATE_aj[1];
  ME11_ARID_DEF.Delay_DSTATE_aj[1] = ACTCtl_sSuperHeat;
  ME11_ARID_DEF.Delay2_DSTATE_f[0] = ME11_ARID_DEF.Delay2_DSTATE_f[1];
  ME11_ARID_DEF.Delay2_DSTATE_f[1] = ME11_ARID_DEF.Delay2_DSTATE_f[2];
  ME11_ARID_DEF.Delay2_DSTATE_f[2] = ACTCtl_sSuperHeat;
  ME11_ARID_DEF.Delay3_DSTATE_kc[0] = ME11_ARID_DEF.Delay3_DSTATE_kc[1];
  ME11_ARID_DEF.Delay3_DSTATE_kc[1] = ME11_ARID_DEF.Delay3_DSTATE_kc[2];
  ME11_ARID_DEF.Delay3_DSTATE_kc[2] = ME11_ARID_DEF.Delay3_DSTATE_kc[3];
  ME11_ARID_DEF.Delay3_DSTATE_kc[3] = ACTCtl_sSuperHeat;
  ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ak = 0U;
  ME11_ARID_DEF.Delay_DSTATE_kx = ACSen_sMotTempFilter;
  ME11_ARID_DEF.DelayInput1_DSTATE_n = IOCtl_RecircTrgPos;
  ME11_ARID_DEF.DelayInput1_DSTATE_dg = IOCtl_sMixDoorTrgPos;
  ME11_ARID_DEF.Delay_DSTATE_f = AC_BlowerFanSpeedMax;
  Rte_IWrite_Task_100ms_TMS2VCU_AC_1_Command_Outputs_TMS2VCU_AC_1_Command_Outputs
    (&rtb_BusCreator1);
  Rte_IWrite_Task_100ms_TMS2VCU_AC_2_State_Outputs_TMS2VCU_AC_2_State_Outputs
    (&rtb_BusCreator2);
  Rte_IWrite_Task_100ms_TMS2VCU_AC_3_State_Outputs_TMS2VCU_AC_3_State_Outputs
    (&rtb_BusCreator3);
  Rte_IWrite_Task_100ms_TMS2VCU_AC_8_status_Outputs_TMS2VCU_AC_8_status_Outputs(
    &rtb_BusCreator4);
  Rte_IWrite_Task_100ms_TMS2VCU_AC_ACStatuts_Outputs_TMS2VCU_AC_ACStatuts_Outputs
    (&rtb_BusCreator5);
  Rte_IWrite_Task_100ms_TMS2VCU_AC_COMP_Outputs_TMS2VCU_AC_COMP_Outputs
    (&rtb_BusCreator6);
  Rte_IWrite_Task_100ms_TMS2VCU_HVCH_Command_Outputs_TMS2VCU_HVCH_Command_Outputs
    (&rtb_BusCreator7);
  Rte_IWrite_Task_100ms_TMS2VCU_TMS_LINTestData1_Outputs_TMS2VCU_TMS_LINTestData1_Outputs
    (&rtb_BusCreator8);
  Rte_IWrite_Task_100ms_TMS2VCU_TMS_LINTestData2_Outputs_TMS2VCU_TMS_LINTestData2_Outputs
    (&rtb_BusCreator9);
  Rte_IWrite_Task_100ms_TMS2VCU_TMS_LINTestData3_Outputs_TMS2VCU_TMS_LINTestData3_Outputs
    (&rtb_BusCreator10);
  Rte_IWrite_Task_100ms_Tms2Vcu_Info_Tms2Vcu_Info(&rtb_BusCreator);
  Rte_IWrite_Task_100ms_TMS2VCU_PPV_outputs_TMS2VCU_PPV_outputs
    (&rtb_BusCreator11);
  Rte_IWrite_Task_100ms_TMM_EXV_PositionRequest_TMM_EXV_PositionRequest
    (rtb_Gain1_j_0);
  Rte_IWrite_Task_100ms_TMM_EXV_EnableRequest_TMM_EXV_EnableRequest
    (rtb_Compare_fhh);
  Rte_IWrite_Task_100ms_TMM_EXV_initRequest_TMM_EXV_initRequest(rtb_Compare_bxp);
  Rte_IWrite_Task_100ms_BAT_EXV_position_command_B_BAT_EXV_position_command_B
    (rtb_Gain_az);
  Rte_IWrite_Task_100ms_BAT_EXV_movenable_command_B_BAT_EXV_movenable_command_B
    (rtb_Compare_cj1);
  Rte_IWrite_Task_100ms_BAT_EXV_initialize_command_B_BAT_EXV_initialize_command_B
    (rtb_DataTypeConversion1_l);
  Rte_IWrite_Task_100ms_C3WV_BPosSetReq_C3WV_BPosSetReq(rtb_Compare_nw0);
  Rte_IWrite_Task_100ms_C3WV_RefDrvReq_C3WV_RefDrvReq(rtb_IFreezFlag_k);
  Rte_IWrite_Task_100ms_C3WV_SpdLvlReq_C3WV_SpdLvlReq(0U);
  Rte_IWrite_Task_100ms_C5WV_BPosSetReq_C5WV_BPosSetReq(rtb_Compare_i1);
  Rte_IWrite_Task_100ms_C5WV_RefDrvReq_C5WV_RefDrvReq(rtb_Compare);
  Rte_IWrite_Task_100ms_C5WV_SpdLvlReq_C5WV_SpdLvlReq(0U);
  Rte_IWrite_Task_100ms_HP_EXV_position_command_B_HP_EXV_position_command_B
    (rtb_Divide_ox);
  Rte_IWrite_Task_100ms_HP_EXV_movenable_command_B_HP_EXV_movenable_command_B
    (rtb_Compare_mos);
  Rte_IWrite_Task_100ms_HP_EXV_initialize_command_B_HP_EXV_initialize_command_B
    (rtb_DataTypeConversion1_on);
  Rte_IWrite_Task_100ms_AcPMP_SpdSet_AcPMP_SpdSet(rtb_Compare_ij);
  Rte_IWrite_Task_100ms_BatPMP_SpdSet_BatPMP_SpdSet(rtb_DataTypeConversion1_g);
  Rte_IWrite_Task_100ms_MotPMP_SpdSet_MotPMP_SpdSet(rtb_IFreezFlag_bd);
}

void ME11_Init(void)
{
  {
    boolean rtb_flag;
    boolean rtb_flg;
    boolean rtb_flg_d;
    boolean rtb_flg_g;
    boolean rtb_flg_o;
    boolean rtb_flag_l;
    boolean rtb_flg_dg;
    boolean rtb_flg_f;
    boolean rtb_flag_c;
    boolean rtb_flag_k;
    boolean rtb_flg_n;
    boolean rtb_flg_m;
    boolean rtb_ACTCtl_eCOMPFlg3Cal;
    boolean rtb_ACTCtl_eCOMPFlg3Cal_c;
    boolean rtb_flag_f;
    boolean rtb_flag_g;
    boolean rtb_flag_n;
    boolean rtb_flag_nk;
    boolean rtb_flag_d;
    boolean rtb_flag_a;
    boolean rtb_flag_g4;
    boolean rtb_flag_de;
    boolean rtb_flag_ko;
    uint8 rtb_CCaller_i[13];
    uint8 rtb_Divide1_ae;
    Buffer_DcmDspData_F266H[0] = 32U;
    Buffer_DcmDspData_F267H[0] = 32U;
    Buffer_DcmDspData_F268H[0] = 32U;
    Buffer_DcmDspData_F26CH[0] = 32U;
    Buffer_DcmDspData_F271H[0] = 32U;
    Buffer_DcmDspData_F272H[0] = 32U;
    Buffer_DcmDspData_F27CH[0] = 32U;
    Buffer_DcmDspData_F27DH[0] = 32U;
    Buffer_DcmDspData_F27EH[0] = 32U;
    Buffer_DcmDspData_F270H[0] = 32U;
    Buffer_DcmDspData_F266H[1] = 32U;
    Buffer_DcmDspData_F267H[1] = 32U;
    Buffer_DcmDspData_F268H[1] = 32U;
    Buffer_DcmDspData_F26CH[1] = 32U;
    Buffer_DcmDspData_F271H[1] = 32U;
    Buffer_DcmDspData_F272H[1] = 32U;
    Buffer_DcmDspData_F27CH[1] = 32U;
    Buffer_DcmDspData_F27DH[1] = 32U;
    Buffer_DcmDspData_F27EH[1] = 32U;
    Buffer_DcmDspData_F270H[1] = 32U;
    ME11_ARID_DEF.EERead_AmbienceTemp = 25.0F;
    ME11_ARID_DEF.EERead_CabinSetTemp = 16U;
    ME11_ARID_DEF.EERead_UnlockVentSts = 1U;
    ME11_ARID_DEF.EEWrite_AmbienceTemp = 65U;
    ME11_ARID_DEF.EEWrite_CabinSetTemp = 16U;
    ME11_ARID_DEF.EEWrite_PCUInletTemp = 25U;
    ME11_ARID_DEF.EEWrite_UnlockVentSts = 1U;
    ME11_ARID_DEF.Delay1_Reset_ZCE = POS_ZCSIG;
    ME11_ARID_DEF.Delay1_Reset_ZCE_a = POS_ZCSIG;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_n = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_g = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_k = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kt = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_c = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_j = 1U;
    ME11_ARID_DEF.Delay_DSTATE_fl = BlowerModes_OffMode;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_e = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_a = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ec = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kj = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_jm = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_g3 = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nw = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_f = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_m = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_gm = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nc = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_fj = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_l = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_eg = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_h = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_fz = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_kg = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_nk = 1U;
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ak = 1U;
    ME11_deadzone_Init(&rtb_flag_ko);
    ME11_deadzone_a_Init(&rtb_flag_de);
    ME11_deadzone_a_Init(&rtb_flag_g4);
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_ar = 1U;
    ME11_deadzone_Init(&rtb_flag_a);
    ME11_ARID_DEF.FixPtUnitDelay2_DSTATE_i = 1U;
    ME11_deadzone_Init(&rtb_flag_d);
    ME11_deadzone_a_Init(&rtb_flag_nk);
    ME11_deadzone_a_Init(&rtb_flag_n);
    ME11_deadzone_a_Init(&rtb_flag_g);
    ME11_deadzone_a_Init(&rtb_flag_f);
    ME11_OverDuty1_Init(&ME11_ARID_DEF.Sts_b, &ME11_ARID_DEF.ClearFlt_m);
    ME11_OverDuty1_Init(&ME11_ARID_DEF.Sts_a, &ME11_ARID_DEF.ClearFlt_k);
    ME11_OverDuty1_Init(&ME11_ARID_DEF.Sts_e, &ME11_ARID_DEF.ClearFlt_c);
    ME11_OverDuty1_Init(&ME11_ARID_DEF.Sts_d3, &ME11_ARID_DEF.ClearFlt_f);
    ME11_OverDuty1_Init(&ME11_ARID_DEF.Sts_d, &ME11_ARID_DEF.ClearFlt);
    ME11_Flg3Cal_Init(&rtb_ACTCtl_eCOMPFlg3Cal_c);
    ME11_Flg3Cal_Init(&rtb_ACTCtl_eCOMPFlg3Cal);
    ME11_PwrOn_Init(&rtb_flg_m);
    ME11_PwrOn_Init(&rtb_flg_n);
    ME11_deadzone_p_Init(&rtb_flag_k);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_ny);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_o);
    ME11_Chart_Init(&ME11_ARID_DEF.Flag_a);
    ME11_Chart_Init(&ME11_ARID_DEF.Flag_da);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_a);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_f);
    ME11_deadzone_p_Init(&rtb_flag_c);
    ME11_PwrOn_Init(&rtb_flg_f);
    ME11_PwrOn_Init(&rtb_flg_dg);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_e);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_d);
    ME11_deadzone_p_Init(&rtb_flag_l);
    ME11_PwrOn_Init(&rtb_flg_o);
    ME11_PwrOn_Init(&rtb_flg_g);
    ME11_PwrOn_Init(&rtb_flg_d);
    ME11_PwrOn_Init(&rtb_flg);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_b);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter_n);
    ME11_Descending_filter_Init(&ME11_ARID_DEF.ARID_DEF_Descending_filter);
    ME11_deadzone_p_Init(&rtb_flag);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_nq);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_nf);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_oel);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_oe);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_h);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_li);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_d);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_n);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_cu);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_b);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_l);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_oi);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_c);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_iw);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_a);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_e5);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_e);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts_i);
    ME11_Abnormal_Over_temperatura_via_software_monitoring_Init
      (&ME11_ARID_DEF.ErrSts_m);
    ME11_External_Com_Fault_Init(&ME11_ARID_DEF.ErrSts);
    ME11_AcPMPFaultJudge_Init(&ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_c);
    ME11_Delay1_Init(&ME11_ARID_DEF.C_o);
    ME11_Delay1_Init(&ME11_ARID_DEF.C_j);
    ME11_AcPMPFaultJudge_Init(&ME11_ARID_DEF.ACTCtl_bAcPMPFaultFlg_e);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_c);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_no);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_k);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_e);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_fr);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_o);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_a);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_n);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_f4);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_b);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_l);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_fm);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts_f);
    ME11_Judge_Init(&ME11_ARID_DEF.SenSts);
    ME11_ARID_DEF.Delay_DSTATE_cf = 2U;
    ME11_ARID_DEF.Delay_DSTATE_fp = 2U;
    ME11_ARID_DEF.Delay_DSTATE_mu = true;
    ME11_ARID_DEF.sfEvent = -1;
    ME11_TMSADCSampleFunc_Init();
    ME11_Delay_Init(&ME11_ARID_DEF.C_i);
    ME11_Delay_Init(&ME11_ARID_DEF.C_g);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B_a);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B_i);
    ME11_Chart_l_Init(&ME11_ARID_DEF.B_mb);
    ME11_Chart_l_Init(&ME11_ARID_DEF.B_e);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B_f);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B_b);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B_m);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B_p);
    ME11_Chart_a_Init(&ME11_ARID_DEF.B);
    NvmTmsBlockReadData(&rtb_CCaller_i[0], 12U);
    rtb_Divide1_ae = rtb_CCaller_i[1];
    ACNvm_bACAutoSts = (rtb_Divide1_ae != 0);
    ME11_ARID_DEF.EERead_bACAutoSts = ACNvm_bACAutoSts;
    rtb_Divide1_ae = rtb_CCaller_i[0];
    ACNvm_bACOnOff = (rtb_Divide1_ae != 0);
    ME11_ARID_DEF.EERead_bACOnOff = ACNvm_bACOnOff;
    ACNvm_eCainRecDoor = rtb_CCaller_i[10];
    ME11_ARID_DEF.EERead_CabinRecDoor = ACNvm_eCainRecDoor;
    ACNvm_eCainModeDoor = rtb_CCaller_i[11];
    ME11_ARID_DEF.EERead_CabinModeDoor = ACNvm_eCainModeDoor;
    ACNvm_eUnlockVentSts = rtb_CCaller_i[12];
    ME11_ARID_DEF.EERead_UnlockVentSts = ACNvm_eUnlockVentSts;
    rtb_Divide1_ae = rtb_CCaller_i[3];
    ACNvm_sACEnvTemp = (float32)(uint8)((float64)rtb_Divide1_ae / 2.0) - 40.0F;
    ME11_ARID_DEF.EERead_AmbienceTemp = ACNvm_sACEnvTemp;
    ACNvm_eCabinSetTemp = rtb_CCaller_i[2];
    ME11_ARID_DEF.EERead_CabinSetTemp = ACNvm_eCabinSetTemp;
    ACNvm_eACCabinMode = rtb_CCaller_i[4];
    ME11_ARID_DEF.EERead_CabinMode = ACNvm_eACCabinMode;
    ACNvm_eCabinBlower = rtb_CCaller_i[5];
    ME11_ARID_DEF.EERead_CabinBlower = ACNvm_eCabinBlower;
    rtb_Divide1_ae = rtb_CCaller_i[6];
    ACNvm_sPCUInletTemp = (float32)(uint8)((float64)rtb_Divide1_ae / 2.0) -
      40.0F;
    ME11_ARID_DEF.EERead_PCUInletTemp = ACNvm_sPCUInletTemp;
    ME11_ARID_DEF.EERead_TimeHour = rtb_CCaller_i[7];
    ME11_ARID_DEF.EERead_TimeMin = rtb_CCaller_i[8];
    ME11_ARID_DEF.EERead_TimeDay = rtb_CCaller_i[9];
    set_PwrFanAndPump(0U);
    set_PwrHVPart(0U);
    SetHw_PwrBlower(0U);
    set_PwrHVPart(0U);
    set_PwrACPump(0U);
    set_PwrFanCabin(0U);
    set_PwrSensor(0U);
    GlbDa_uBat = 1200U;
    TMS_VersionNumber = 5U;
  }
}
