/*
 * File: AppSwcIpm.c
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.231
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Feb 10 15:10:30 2025
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "AppSwcIpm.h"
#include "rtwtypes.h"
#include "Rte_Type.h"
#include "monPrmsIpm.h"
#include "calPrmsIpm.h"
#include "AppSwcIpm_types.h"

/* PublicStructure Variables for Internal Data */
ARID_DEF_AppSwcIpm_T AppSwcIpm_ARID_DEF;
static void AppSwcIpm_Chart_Init(boolean *rty_y);
static void AppSwcIpm_Chart(boolean rtu_u, float32 rtu_dT, float32 rtu_T,
  boolean rtu_FirstStep, boolean *rty_y, ARID_DEF_Chart_AppSwcIpm_T
  *AppSwcIpm__ARID_DEF_arg);
static void Runbl_Ipm100ms(void);
static void Runbl_Ipm10ms(void);
static void Runbl_Ipm20ms(void);
static void Runbl_Ipm50ms(void);

/* Output and update for function-call system: '<Root>/Ipm100ms' */
static void Runbl_Ipm100ms(void)
{
  sint32 rtb_Add_np;
  float32 rtb_Product_eyc;
  boolean rtb_LogicalOperator2_j;

  /* Outputs for Atomic SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeYear_nu' */
  /* Logic: '<S21>/Logical Operator3' incorporates:
   *  Constant: '<S21>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeYearVld_flg = (KIPM_TBOXBJSTimeYear_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S21>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S21>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Sum: '<S22>/Add' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Product: '<S22>/Product'
       */
      rtb_Add_np =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Year;

      /* Switch: '<S21>/Switch' incorporates:
       *  Constant: '<S22>/Constant1'
       *  Sum: '<S22>/Add'
       *  Switch: '<S21>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g = (uint16)(rtb_Add_np + 2000);
    }

    /* End of Switch: '<S21>/Switch3' */
  } else {
    /* Switch: '<S21>/Switch' incorporates:
     *  Constant: '<S21>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g = KIPM_TBOXBJSTimeYearDflt_nu;
  }

  /* End of Switch: '<S21>/Switch' */

  /* Switch: '<S21>/Switch4' incorporates:
   *  Constant: '<S21>/sat3'
   */
  if (KIPM_TBOXBJSTimeYear_nu_ovrdflg) {
    /* Switch: '<S21>/Switch4' incorporates:
     *  Constant: '<S21>/sat4'
     */
    VIPM_TBOXBJSTimeYear_nu = KIPM_TBOXBJSTimeYear_nu_ovrdval;
  } else {
    /* Switch: '<S21>/Switch4' */
    VIPM_TBOXBJSTimeYear_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g;
  }

  /* End of Switch: '<S21>/Switch4' */
  /* End of Outputs for SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeYear_nu' */

  /* Outputs for Atomic SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeMonth_nu' */
  /* Logic: '<S19>/Logical Operator3' incorporates:
   *  Constant: '<S19>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeMonthVld_flg = (KIPM_TBOXBJSTimeMonth_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S19>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S19>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S19>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S19>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Month;
    }

    /* End of Switch: '<S19>/Switch3' */
  } else {
    /* Switch: '<S19>/Switch' incorporates:
     *  Constant: '<S19>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah = KIPM_TBOXBJSTimeMonthDflt_nu;
  }

  /* End of Switch: '<S19>/Switch' */

  /* Switch: '<S19>/Switch4' incorporates:
   *  Constant: '<S19>/sat3'
   */
  if (KIPM_TBOXBJSTimeMonth_nu_ovrdflg) {
    /* Switch: '<S19>/Switch4' incorporates:
     *  Constant: '<S19>/sat4'
     */
    VIPM_TBOXBJSTimeMonth_nu = KIPM_TBOXBJSTimeMonth_nu_ovrdval;
  } else {
    /* Switch: '<S19>/Switch4' */
    VIPM_TBOXBJSTimeMonth_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah;
  }

  /* End of Switch: '<S19>/Switch4' */
  /* End of Outputs for SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeMonth_nu' */

  /* Outputs for Atomic SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeDay_nu' */
  /* Logic: '<S16>/Logical Operator3' incorporates:
   *  Constant: '<S16>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeDayVld_flg = (KIPM_TBOXBJSTimeDay_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S16>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S16>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S16>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S16>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iy =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Day;
    }

    /* End of Switch: '<S16>/Switch3' */
  } else {
    /* Switch: '<S16>/Switch' incorporates:
     *  Constant: '<S16>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iy = KIPM_TBOXBJSTimeDayDflt_nu;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Switch: '<S16>/Switch4' incorporates:
   *  Constant: '<S16>/sat3'
   */
  if (KIPM_TBOXBJSTimeDay_nu_ovrdflg) {
    /* Switch: '<S16>/Switch4' incorporates:
     *  Constant: '<S16>/sat4'
     */
    VIPM_TBOXBJSTimeDay_nu = KIPM_TBOXBJSTimeDay_nu_ovrdval;
  } else {
    /* Switch: '<S16>/Switch4' */
    VIPM_TBOXBJSTimeDay_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iy;
  }

  /* End of Switch: '<S16>/Switch4' */
  /* End of Outputs for SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeDay_nu' */

  /* Outputs for Atomic SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeHour_nu' */
  /* Logic: '<S17>/Logical Operator3' incorporates:
   *  Constant: '<S17>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeHourVld_flg = (KIPM_TBOXBJSTimeHour_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S17>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S17>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S17>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S17>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ke =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Hour;
    }

    /* End of Switch: '<S17>/Switch3' */
  } else {
    /* Switch: '<S17>/Switch' incorporates:
     *  Constant: '<S17>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ke = KIPM_TBOXBJSTimeHourDflt_nu;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Switch: '<S17>/Switch4' incorporates:
   *  Constant: '<S17>/sat3'
   */
  if (KIPM_TBOXBJSTimeHour_nu_ovrdflg) {
    /* Switch: '<S17>/Switch4' incorporates:
     *  Constant: '<S17>/sat4'
     */
    VIPM_TBOXBJSTimeHour_nu = KIPM_TBOXBJSTimeHour_nu_ovrdval;
  } else {
    /* Switch: '<S17>/Switch4' */
    VIPM_TBOXBJSTimeHour_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ke;
  }

  /* End of Switch: '<S17>/Switch4' */
  /* End of Outputs for SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeHour_nu' */

  /* Outputs for Atomic SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeMin_nu' */
  /* Logic: '<S18>/Logical Operator3' incorporates:
   *  Constant: '<S18>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeMinVld_flg = (KIPM_TBOXBJSTimeMin_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S18>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S18>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S18>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S18>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Min;
    }

    /* End of Switch: '<S18>/Switch3' */
  } else {
    /* Switch: '<S18>/Switch' incorporates:
     *  Constant: '<S18>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0 = KIPM_TBOXBJSTimeMinDflt_nu;
  }

  /* End of Switch: '<S18>/Switch' */

  /* Switch: '<S18>/Switch4' incorporates:
   *  Constant: '<S18>/sat3'
   */
  if (KIPM_TBOXBJSTimeMin_nu_ovrdflg) {
    /* Switch: '<S18>/Switch4' incorporates:
     *  Constant: '<S18>/sat4'
     */
    VIPM_TBOXBJSTimeMin_nu = KIPM_TBOXBJSTimeMin_nu_ovrdval;
  } else {
    /* Switch: '<S18>/Switch4' */
    VIPM_TBOXBJSTimeMin_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0;
  }

  /* End of Switch: '<S18>/Switch4' */
  /* End of Outputs for SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeMin_nu' */

  /* Outputs for Atomic SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeSec_nu' */
  /* Logic: '<S20>/Logical Operator3' incorporates:
   *  Constant: '<S20>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXBJSTimeSecVld_flg = (KIPM_TBOXBJSTimeSec_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_TBOXMsgActv_flg);

  /* Switch: '<S20>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_TBOXMsgActv_flg) {
    /* Switch: '<S20>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_TBOX_BJS_Time_CRCFlt_flg) {
      /* Switch: '<S20>/Switch' incorporates:
       *  Inport: '<Root>/TBOX_BJS_Time_BAC'
       *  Switch: '<S20>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_no =
        (Rte_IRead_Runbl_IpmCanRx_100ms_TBOX_BJS_Time_BAC_TBOX_BJS_Time_BAC())
        ->TBOX_BJS_Time_Sec;
    }

    /* End of Switch: '<S20>/Switch3' */
  } else {
    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_no = KIPM_TBOXBJSTimeSecDflt_nu;
  }

  /* End of Switch: '<S20>/Switch' */

  /* Switch: '<S20>/Switch4' incorporates:
   *  Constant: '<S20>/sat3'
   */
  if (KIPM_TBOXBJSTimeSec_nu_ovrdflg) {
    /* Switch: '<S20>/Switch4' incorporates:
     *  Constant: '<S20>/sat4'
     */
    VIPM_TBOXBJSTimeSec_nu = KIPM_TBOXBJSTimeSec_nu_ovrdval;
  } else {
    /* Switch: '<S20>/Switch4' */
    VIPM_TBOXBJSTimeSec_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_no;
  }

  /* End of Switch: '<S20>/Switch4' */
  /* End of Outputs for SubSystem: '<S15>/Subsys_VIPM_TBOXBJSTimeSec_nu' */

  /* BusCreator: '<S15>/BusCreator' incorporates:
   *  Logic: '<S16>/Logical Operator3'
   *  Logic: '<S17>/Logical Operator3'
   *  Logic: '<S18>/Logical Operator3'
   *  Logic: '<S19>/Logical Operator3'
   *  Logic: '<S20>/Logical Operator3'
   *  Logic: '<S21>/Logical Operator3'
   *  Switch: '<S16>/Switch4'
   *  Switch: '<S17>/Switch4'
   *  Switch: '<S18>/Switch4'
   *  Switch: '<S19>/Switch4'
   *  Switch: '<S20>/Switch4'
   *  Switch: '<S21>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeYear_nu =
    VIPM_TBOXBJSTimeYear_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeYearVld_flg =
    VIPM_TBOXBJSTimeYearVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeMonth_nu =
    VIPM_TBOXBJSTimeMonth_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeMonthVld_flg =
    VIPM_TBOXBJSTimeMonthVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeDay_nu =
    VIPM_TBOXBJSTimeDay_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeDayVld_flg =
    VIPM_TBOXBJSTimeDayVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeHour_nu =
    VIPM_TBOXBJSTimeHour_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeHourVld_flg =
    VIPM_TBOXBJSTimeHourVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeMin_nu =
    VIPM_TBOXBJSTimeMin_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeMinVld_flg =
    VIPM_TBOXBJSTimeMinVld_flg;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeSec_nu =
    VIPM_TBOXBJSTimeSec_nu;
  AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d.VIPM_TBOXBJSTimeSecVld_flg =
    VIPM_TBOXBJSTimeSecVld_flg;

  /* Outputs for Atomic SubSystem: '<S23>/Subsys_VIPM_ICUTotOdo_km' */
  /* Logic: '<S25>/Logical Operator3' incorporates:
   *  Constant: '<S25>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ICUTotOdoVld_flg = (KIPM_ICUTotOdo_km_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_CDCMsgActv_flg);

  /* Switch: '<S25>/Switch4' incorporates:
   *  Constant: '<S25>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S25>/Switch'
   */
  if (KIPM_ICUTotOdo_km_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S25>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_ICUTotOdo_km_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_CDCMsgActv_flg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S26>/Constant'
     *  Inport: '<Root>/ICU_2_Odo_BAC'
     *  MinMax: '<S172>/MinMax'
     *  Product: '<S26>/Product'
     *  Switch: '<S25>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_ICU_2_Odo_BAC_ICU_2_Odo_BAC())
      ->ICU_ICUTotalOdometer * 0.1F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S25>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S25>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_ICUTotOdoDflt_km;
  }

  /* End of Switch: '<S25>/Switch4' */

  /* MinMax: '<S25>/MinMax' incorporates:
   *  Constant: '<S25>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_ICUTotOdoHi_km) {
    VIPM_IPUOBCTempInt_C = KIPM_ICUTotOdoHi_km;
  }

  /* MinMax: '<S25>/MinMax1' incorporates:
   *  Constant: '<S25>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_ICUTotOdoLo_km) {
    /* MinMax: '<S25>/MinMax1' */
    VIPM_ICUTotOdo_km = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S25>/MinMax1' */
    VIPM_ICUTotOdo_km = KIPM_ICUTotOdoLo_km;
  }

  /* End of MinMax: '<S25>/MinMax1' */
  /* End of Outputs for SubSystem: '<S23>/Subsys_VIPM_ICUTotOdo_km' */

  /* BusCreator: '<S23>/BusCreator' incorporates:
   *  Logic: '<S25>/Logical Operator3'
   *  MinMax: '<S25>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_ICU_2_Odo_BAC_j.VIPM_ICUTotOdo_km = VIPM_ICUTotOdo_km;
  AppSwcIpm_ARID_DEF.IPM_ICU_2_Odo_BAC_j.VIPM_ICUTotOdoVld_flg =
    VIPM_ICUTotOdoVld_flg;

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUHybEcoModeSet_enum' */
  /* Logic: '<S43>/Logical Operator3' incorporates:
   *  Constant: '<S43>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUHybEcoModeSetVld_flg = (KIPM_HUHybEcoModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S43>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S43>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S43>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S43>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o3 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_HybridEcoModeSet;
    }

    /* End of Switch: '<S43>/Switch3' */
  } else {
    /* Switch: '<S43>/Switch' incorporates:
     *  Constant: '<S43>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o3 = KIPM_HUHybEcoModeSetDflt_enum;
  }

  /* End of Switch: '<S43>/Switch' */

  /* Switch: '<S43>/Switch4' incorporates:
   *  Constant: '<S43>/sat3'
   */
  if (KIPM_HUHybEcoModeSet_enum_ovrdflg) {
    /* Switch: '<S43>/Switch4' incorporates:
     *  Constant: '<S43>/sat4'
     */
    VIPM_HUHybEcoModeSet_enum = KIPM_HUHybEcoModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S43>/Switch4' */
    VIPM_HUHybEcoModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o3;
  }

  /* End of Switch: '<S43>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUHybEcoModeSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HULeftTempSet_enum' */
  /* Logic: '<S48>/Logical Operator3' incorporates:
   *  Constant: '<S48>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HULeftTempSetVld_flg = (KIPM_HULeftTempSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S48>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S48>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S48>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S48>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lz =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_LeftTempSet;
    }

    /* End of Switch: '<S48>/Switch3' */
  } else {
    /* Switch: '<S48>/Switch' incorporates:
     *  Constant: '<S48>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lz = KIPM_HULeftTempSetDflt_enum;
  }

  /* End of Switch: '<S48>/Switch' */

  /* Switch: '<S48>/Switch4' incorporates:
   *  Constant: '<S48>/sat3'
   */
  if (KIPM_HULeftTempSet_enum_ovrdflg) {
    /* Switch: '<S48>/Switch4' incorporates:
     *  Constant: '<S48>/sat4'
     */
    VIPM_HULeftTempSet_enum = KIPM_HULeftTempSet_enum_ovrdval;
  } else {
    /* Switch: '<S48>/Switch4' */
    VIPM_HULeftTempSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lz;
  }

  /* End of Switch: '<S48>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HULeftTempSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUACPwrCtl_enum' */
  /* Logic: '<S29>/Logical Operator3' incorporates:
   *  Constant: '<S29>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUACPwrCtlVld_flg = (KIPM_HUACPwrCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S29>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S29>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S29>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S29>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ACPowerCtl;
    }

    /* End of Switch: '<S29>/Switch3' */
  } else {
    /* Switch: '<S29>/Switch' incorporates:
     *  Constant: '<S29>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2 = KIPM_HUACPwrCtlDflt_enum;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S29>/Switch4' incorporates:
   *  Constant: '<S29>/sat3'
   */
  if (KIPM_HUACPwrCtl_enum_ovrdflg) {
    /* Switch: '<S29>/Switch4' incorporates:
     *  Constant: '<S29>/sat4'
     */
    VIPM_HUACPwrCtl_enum = KIPM_HUACPwrCtl_enum_ovrdval;
  } else {
    /* Switch: '<S29>/Switch4' */
    VIPM_HUACPwrCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2;
  }

  /* End of Switch: '<S29>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUACPwrCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUAirInletModeSet_enum' */
  /* Logic: '<S31>/Logical Operator3' incorporates:
   *  Constant: '<S31>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUAirInletModeSetVld_flg = (KIPM_HUAirInletModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S31>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S31>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S31>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S31>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jp =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_AirInletModeSet;
    }

    /* End of Switch: '<S31>/Switch3' */
  } else {
    /* Switch: '<S31>/Switch' incorporates:
     *  Constant: '<S31>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jp = KIPM_HUAirInletModeSetDflt_enum;
  }

  /* End of Switch: '<S31>/Switch' */

  /* Switch: '<S31>/Switch4' incorporates:
   *  Constant: '<S31>/sat3'
   */
  if (KIPM_HUAirInletModeSet_enum_ovrdflg) {
    /* Switch: '<S31>/Switch4' incorporates:
     *  Constant: '<S31>/sat4'
     */
    VIPM_HUAirInletModeSet_enum = KIPM_HUAirInletModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S31>/Switch4' */
    VIPM_HUAirInletModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jp;
  }

  /* End of Switch: '<S31>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUAirInletModeSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUFrntFanSpdSet_enum' */
  /* Logic: '<S42>/Logical Operator3' incorporates:
   *  Constant: '<S42>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUFrntFanSpdSetVld_flg = (KIPM_HUFrntFanSpdSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S42>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S42>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S42>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S42>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ap =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_FrontFanSpdSet;
    }

    /* End of Switch: '<S42>/Switch3' */
  } else {
    /* Switch: '<S42>/Switch' incorporates:
     *  Constant: '<S42>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ap = KIPM_HUFrntFanSpdSetDflt_enum;
  }

  /* End of Switch: '<S42>/Switch' */

  /* Switch: '<S42>/Switch4' incorporates:
   *  Constant: '<S42>/sat3'
   */
  if (KIPM_HUFrntFanSpdSet_enum_ovrdflg) {
    /* Switch: '<S42>/Switch4' incorporates:
     *  Constant: '<S42>/sat4'
     */
    VIPM_HUFrntFanSpdSet_enum = KIPM_HUFrntFanSpdSet_enum_ovrdval;
  } else {
    /* Switch: '<S42>/Switch4' */
    VIPM_HUFrntFanSpdSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ap;
  }

  /* End of Switch: '<S42>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUFrntFanSpdSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUManlDefrstCtl_enum' */
  /* Logic: '<S50>/Logical Operator3' incorporates:
   *  Constant: '<S50>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUManlDefrstCtlVld_flg = (KIPM_HUManlDefrstCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S50>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S50>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S50>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S50>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kz =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_ManualDefrostCtl;
    }

    /* End of Switch: '<S50>/Switch3' */
  } else {
    /* Switch: '<S50>/Switch' incorporates:
     *  Constant: '<S50>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kz = KIPM_HUManlDefrstCtlDflt_enum;
  }

  /* End of Switch: '<S50>/Switch' */

  /* Switch: '<S50>/Switch4' incorporates:
   *  Constant: '<S50>/sat3'
   */
  if (KIPM_HUManlDefrstCtl_enum_ovrdflg) {
    /* Switch: '<S50>/Switch4' incorporates:
     *  Constant: '<S50>/sat4'
     */
    VIPM_HUManlDefrstCtl_enum = KIPM_HUManlDefrstCtl_enum_ovrdval;
  } else {
    /* Switch: '<S50>/Switch4' */
    VIPM_HUManlDefrstCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kz;
  }

  /* End of Switch: '<S50>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUManlDefrstCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUBlwrModeSet_enum' */
  /* Logic: '<S34>/Logical Operator3' incorporates:
   *  Constant: '<S34>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUBlwrModeSetVld_flg = (KIPM_HUBlwrModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S34>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S34>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S34>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S34>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fe =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_BlowerModeSet;
    }

    /* End of Switch: '<S34>/Switch3' */
  } else {
    /* Switch: '<S34>/Switch' incorporates:
     *  Constant: '<S34>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fe = KIPM_HUBlwrModeSetDflt_enum;
  }

  /* End of Switch: '<S34>/Switch' */

  /* Switch: '<S34>/Switch4' incorporates:
   *  Constant: '<S34>/sat3'
   */
  if (KIPM_HUBlwrModeSet_enum_ovrdflg) {
    /* Switch: '<S34>/Switch4' incorporates:
     *  Constant: '<S34>/sat4'
     */
    VIPM_HUBlwrModeSet_enum = KIPM_HUBlwrModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S34>/Switch4' */
    VIPM_HUBlwrModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fe;
  }

  /* End of Switch: '<S34>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUBlwrModeSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUFlwrMeHmCtrl_enum' */
  /* Logic: '<S41>/Logical Operator3' incorporates:
   *  Constant: '<S41>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUFlwrMeHmCtrlVld_flg = (KIPM_HUFlwrMeHmCtrl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S41>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S41>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S41>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S41>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_FlwrMeHmCtrl;
    }

    /* End of Switch: '<S41>/Switch3' */
  } else {
    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S41>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hv = KIPM_HUFlwrMeHmCtrlDflt_enum;
  }

  /* End of Switch: '<S41>/Switch' */

  /* Switch: '<S41>/Switch4' incorporates:
   *  Constant: '<S41>/sat3'
   */
  if (KIPM_HUFlwrMeHmCtrl_enum_ovrdflg) {
    /* Switch: '<S41>/Switch4' incorporates:
     *  Constant: '<S41>/sat4'
     */
    VIPM_HUFlwrMeHmCtrl_enum = KIPM_HUFlwrMeHmCtrl_enum_ovrdval;
  } else {
    /* Switch: '<S41>/Switch4' */
    VIPM_HUFlwrMeHmCtrl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hv;
  }

  /* End of Switch: '<S41>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUFlwrMeHmCtrl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUIllmndEntrySts_enum' */
  /* Logic: '<S44>/Logical Operator3' incorporates:
   *  Constant: '<S44>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUIllmndEntryStsVld_flg = (KIPM_HUIllmndEntrySts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S44>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S44>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S44>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S44>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ad =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_IllmndEntrySts;
    }

    /* End of Switch: '<S44>/Switch3' */
  } else {
    /* Switch: '<S44>/Switch' incorporates:
     *  Constant: '<S44>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ad = KIPM_HUIllmndEntryStsDflt_enum;
  }

  /* End of Switch: '<S44>/Switch' */

  /* Switch: '<S44>/Switch4' incorporates:
   *  Constant: '<S44>/sat3'
   */
  if (KIPM_HUIllmndEntrySts_enum_ovrdflg) {
    /* Switch: '<S44>/Switch4' incorporates:
     *  Constant: '<S44>/sat4'
     */
    VIPM_HUIllmndEntrySts_enum = KIPM_HUIllmndEntrySts_enum_ovrdval;
  } else {
    /* Switch: '<S44>/Switch4' */
    VIPM_HUIllmndEntrySts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ad;
  }

  /* End of Switch: '<S44>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUIllmndEntrySts_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HULckHornOnSt_enum' */
  /* Logic: '<S47>/Logical Operator3' incorporates:
   *  Constant: '<S47>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HULckHornOnStVld_flg = (KIPM_HULckHornOnSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S47>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S47>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S47>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S47>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fc =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_LockHornOnSt;
    }

    /* End of Switch: '<S47>/Switch3' */
  } else {
    /* Switch: '<S47>/Switch' incorporates:
     *  Constant: '<S47>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fc = KIPM_HULckHornOnStDflt_enum;
  }

  /* End of Switch: '<S47>/Switch' */

  /* Switch: '<S47>/Switch4' incorporates:
   *  Constant: '<S47>/sat3'
   */
  if (KIPM_HULckHornOnSt_enum_ovrdflg) {
    /* Switch: '<S47>/Switch4' incorporates:
     *  Constant: '<S47>/sat4'
     */
    VIPM_HULckHornOnSt_enum = KIPM_HULckHornOnSt_enum_ovrdval;
  } else {
    /* Switch: '<S47>/Switch4' */
    VIPM_HULckHornOnSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fc;
  }

  /* End of Switch: '<S47>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HULckHornOnSt_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUACAutoCtl_enum' */
  /* Logic: '<S28>/Logical Operator3' incorporates:
   *  Constant: '<S28>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUACAutoCtlVld_flg = (KIPM_HUACAutoCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S28>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S28>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S28>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S28>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_px =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ACAutoCtl;
    }

    /* End of Switch: '<S28>/Switch3' */
  } else {
    /* Switch: '<S28>/Switch' incorporates:
     *  Constant: '<S28>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_px = KIPM_HUACAutoCtlDflt_enum;
  }

  /* End of Switch: '<S28>/Switch' */

  /* Switch: '<S28>/Switch4' incorporates:
   *  Constant: '<S28>/sat3'
   */
  if (KIPM_HUACAutoCtl_enum_ovrdflg) {
    /* Switch: '<S28>/Switch4' incorporates:
     *  Constant: '<S28>/sat4'
     */
    VIPM_HUACAutoCtl_enum = KIPM_HUACAutoCtl_enum_ovrdval;
  } else {
    /* Switch: '<S28>/Switch4' */
    VIPM_HUACAutoCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_px;
  }

  /* End of Switch: '<S28>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUACAutoCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUParkAutoUnlckSet_enum' */
  /* Logic: '<S52>/Logical Operator3' incorporates:
   *  Constant: '<S52>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUParkAutoUnlckSetVld_flg = (KIPM_HUParkAutoUnlckSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S52>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S52>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S52>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S52>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fq =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_ParkAutoUnlckSet;
    }

    /* End of Switch: '<S52>/Switch3' */
  } else {
    /* Switch: '<S52>/Switch' incorporates:
     *  Constant: '<S52>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fq = KIPM_HUParkAutoUnlckSetDflt_enum;
  }

  /* End of Switch: '<S52>/Switch' */

  /* Switch: '<S52>/Switch4' incorporates:
   *  Constant: '<S52>/sat3'
   */
  if (KIPM_HUParkAutoUnlckSet_enum_ovrdflg) {
    /* Switch: '<S52>/Switch4' incorporates:
     *  Constant: '<S52>/sat4'
     */
    VIPM_HUParkAutoUnlckSet_enum = KIPM_HUParkAutoUnlckSet_enum_ovrdval;
  } else {
    /* Switch: '<S52>/Switch4' */
    VIPM_HUParkAutoUnlckSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fq;
  }

  /* End of Switch: '<S52>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUParkAutoUnlckSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUOvrspdCntrlLckSet_enum' */
  /* Logic: '<S51>/Logical Operator3' incorporates:
   *  Constant: '<S51>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUOvrspdCntrlLckSetVld_flg = (KIPM_HUOvrspdCntrlLckSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S51>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S51>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S51>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S51>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hig =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_OverspdCntrlLockSet;
    }

    /* End of Switch: '<S51>/Switch3' */
  } else {
    /* Switch: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hig = KIPM_HUOvrspdCntrlLckSetDflt_enum;
  }

  /* End of Switch: '<S51>/Switch' */

  /* Switch: '<S51>/Switch4' incorporates:
   *  Constant: '<S51>/sat3'
   */
  if (KIPM_HUOvrspdCntrlLckSet_enum_ovrdflg) {
    /* Switch: '<S51>/Switch4' incorporates:
     *  Constant: '<S51>/sat4'
     */
    VIPM_HUOvrspdCntrlLckSet_enum = KIPM_HUOvrspdCntrlLckSet_enum_ovrdval;
  } else {
    /* Switch: '<S51>/Switch4' */
    VIPM_HUOvrspdCntrlLckSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hig;
  }

  /* End of Switch: '<S51>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUOvrspdCntrlLckSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUTrnkLckSwCtrl_enum' */
  /* Logic: '<S59>/Logical Operator3' incorporates:
   *  Constant: '<S59>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUTrnkLckSwCtrlVld_flg = (KIPM_HUTrnkLckSwCtrl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S59>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S59>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S59>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S59>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a5 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_TrunkLockSwCtrl;
    }

    /* End of Switch: '<S59>/Switch3' */
  } else {
    /* Switch: '<S59>/Switch' incorporates:
     *  Constant: '<S59>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a5 = KIPM_HUTrnkLckSwCtrlDflt_enum;
  }

  /* End of Switch: '<S59>/Switch' */

  /* Switch: '<S59>/Switch4' incorporates:
   *  Constant: '<S59>/sat3'
   */
  if (KIPM_HUTrnkLckSwCtrl_enum_ovrdflg) {
    /* Switch: '<S59>/Switch4' incorporates:
     *  Constant: '<S59>/sat4'
     */
    VIPM_HUTrnkLckSwCtrl_enum = KIPM_HUTrnkLckSwCtrl_enum_ovrdval;
  } else {
    /* Switch: '<S59>/Switch4' */
    VIPM_HUTrnkLckSwCtrl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a5;
  }

  /* End of Switch: '<S59>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUTrnkLckSwCtrl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUChgWiprMtMdSwSet_enum' */
  /* Logic: '<S35>/Logical Operator3' incorporates:
   *  Constant: '<S35>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUChgWiprMtMdSwSetVld_flg = (KIPM_HUChgWiprMtMdSwSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S35>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S35>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S35>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S35>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gw =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_ChgWiperMtMdSwSet;
    }

    /* End of Switch: '<S35>/Switch3' */
  } else {
    /* Switch: '<S35>/Switch' incorporates:
     *  Constant: '<S35>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gw = KIPM_HUChgWiprMtMdSwSetDflt_enum;
  }

  /* End of Switch: '<S35>/Switch' */

  /* Switch: '<S35>/Switch4' incorporates:
   *  Constant: '<S35>/sat3'
   */
  if (KIPM_HUChgWiprMtMdSwSet_enum_ovrdflg) {
    /* Switch: '<S35>/Switch4' incorporates:
     *  Constant: '<S35>/sat4'
     */
    VIPM_HUChgWiprMtMdSwSet_enum = KIPM_HUChgWiprMtMdSwSet_enum_ovrdval;
  } else {
    /* Switch: '<S35>/Switch4' */
    VIPM_HUChgWiprMtMdSwSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gw;
  }

  /* End of Switch: '<S35>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUChgWiprMtMdSwSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUTPMSRstReq_flg' */
  /* Logic: '<S58>/Logical Operator3' incorporates:
   *  Constant: '<S58>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUTPMSRstReqVld_flg = (KIPM_HUTPMSRstReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S58>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S58>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S58>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S58>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aq =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_TPMSResetReq;
    }

    /* End of Switch: '<S58>/Switch3' */
  } else {
    /* Switch: '<S58>/Switch' incorporates:
     *  Constant: '<S58>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aq = KIPM_HUTPMSRstReqDflt_flg;
  }

  /* End of Switch: '<S58>/Switch' */

  /* Switch: '<S58>/Switch4' incorporates:
   *  Constant: '<S58>/sat3'
   */
  if (KIPM_HUTPMSRstReq_flg_ovrdflg) {
    /* Switch: '<S58>/Switch4' incorporates:
     *  Constant: '<S58>/sat4'
     */
    VIPM_HUTPMSRstReq_flg = KIPM_HUTPMSRstReq_flg_ovrdval;
  } else {
    /* Switch: '<S58>/Switch4' */
    VIPM_HUTPMSRstReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aq;
  }

  /* End of Switch: '<S58>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUTPMSRstReq_flg' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUMaiDrvrSeatHeat_enum' */
  /* Logic: '<S49>/Logical Operator3' incorporates:
   *  Constant: '<S49>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUMaiDrvrSeatHeatVld_flg = (KIPM_HUMaiDrvrSeatHeat_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S49>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S49>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S49>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S49>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_MaiDrvrSeatHeat;
    }

    /* End of Switch: '<S49>/Switch3' */
  } else {
    /* Switch: '<S49>/Switch' incorporates:
     *  Constant: '<S49>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h0 = KIPM_HUMaiDrvrSeatHeatDflt_enum;
  }

  /* End of Switch: '<S49>/Switch' */

  /* Switch: '<S49>/Switch4' incorporates:
   *  Constant: '<S49>/sat3'
   */
  if (KIPM_HUMaiDrvrSeatHeat_enum_ovrdflg) {
    /* Switch: '<S49>/Switch4' incorporates:
     *  Constant: '<S49>/sat4'
     */
    VIPM_HUMaiDrvrSeatHeat_enum = KIPM_HUMaiDrvrSeatHeat_enum_ovrdval;
  } else {
    /* Switch: '<S49>/Switch4' */
    VIPM_HUMaiDrvrSeatHeat_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h0;
  }

  /* End of Switch: '<S49>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUMaiDrvrSeatHeat_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUPwrOffReq_flg' */
  /* Logic: '<S54>/Logical Operator3' incorporates:
   *  Constant: '<S54>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUPwrOffReqVld_flg = (KIPM_HUPwrOffReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S54>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S54>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S54>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S54>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2g =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_PwrOFFReq;
    }

    /* End of Switch: '<S54>/Switch3' */
  } else {
    /* Switch: '<S54>/Switch' incorporates:
     *  Constant: '<S54>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2g = KIPM_HUPwrOffReqDflt_flg;
  }

  /* End of Switch: '<S54>/Switch' */

  /* Switch: '<S54>/Switch4' incorporates:
   *  Constant: '<S54>/sat3'
   */
  if (KIPM_HUPwrOffReq_flg_ovrdflg) {
    /* Switch: '<S54>/Switch4' incorporates:
     *  Constant: '<S54>/sat4'
     */
    VIPM_HUPwrOffReq_flg = KIPM_HUPwrOffReq_flg_ovrdval;
  } else {
    /* Switch: '<S54>/Switch4' */
    VIPM_HUPwrOffReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2g;
  }

  /* End of Switch: '<S54>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUPwrOffReq_flg' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUWiprIntlTmSet_enum' */
  /* Logic: '<S61>/Logical Operator3' incorporates:
   *  Constant: '<S61>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUWiprIntlTmSetVld_flg = (KIPM_HUWiprIntlTmSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S61>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S61>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S61>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S61>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a1 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_WiprIntlTimeSet;
    }

    /* End of Switch: '<S61>/Switch3' */
  } else {
    /* Switch: '<S61>/Switch' incorporates:
     *  Constant: '<S61>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a1 = KIPM_HUWiprIntlTmSetDflt_enum;
  }

  /* End of Switch: '<S61>/Switch' */

  /* Switch: '<S61>/Switch4' incorporates:
   *  Constant: '<S61>/sat3'
   */
  if (KIPM_HUWiprIntlTmSet_enum_ovrdflg) {
    /* Switch: '<S61>/Switch4' incorporates:
     *  Constant: '<S61>/sat4'
     */
    VIPM_HUWiprIntlTmSet_enum = KIPM_HUWiprIntlTmSet_enum_ovrdval;
  } else {
    /* Switch: '<S61>/Switch4' */
    VIPM_HUWiprIntlTmSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a1;
  }

  /* End of Switch: '<S61>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUWiprIntlTmSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_CDCBackLadjval_enum' */
  /* Logic: '<S27>/Logical Operator3' incorporates:
   *  Constant: '<S27>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CDCBackLadjvalVld_flg = (KIPM_CDCBackLadjval_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S27>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S27>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S27>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S27>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_af =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->CDC_BackLadjval;
    }

    /* End of Switch: '<S27>/Switch3' */
  } else {
    /* Switch: '<S27>/Switch' incorporates:
     *  Constant: '<S27>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_af = KIPM_CDCBackLadjvalDflt_enum;
  }

  /* End of Switch: '<S27>/Switch' */

  /* Switch: '<S27>/Switch4' incorporates:
   *  Constant: '<S27>/sat3'
   */
  if (KIPM_CDCBackLadjval_enum_ovrdflg) {
    /* Switch: '<S27>/Switch4' incorporates:
     *  Constant: '<S27>/sat4'
     */
    VIPM_CDCBackLadjval_enum = KIPM_CDCBackLadjval_enum_ovrdval;
  } else {
    /* Switch: '<S27>/Switch4' */
    VIPM_CDCBackLadjval_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_af;
  }

  /* End of Switch: '<S27>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_CDCBackLadjval_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HURrMirrHeat_enum' */
  /* Logic: '<S56>/Logical Operator3' incorporates:
   *  Constant: '<S56>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HURrMirrHeatVld_flg = (KIPM_HURrMirrHeat_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S56>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S56>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S56>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S56>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fiu =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_RearMirrorHeat;
    }

    /* End of Switch: '<S56>/Switch3' */
  } else {
    /* Switch: '<S56>/Switch' incorporates:
     *  Constant: '<S56>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fiu = KIPM_HURrMirrHeatDflt_enum;
  }

  /* End of Switch: '<S56>/Switch' */

  /* Switch: '<S56>/Switch4' incorporates:
   *  Constant: '<S56>/sat3'
   */
  if (KIPM_HURrMirrHeat_enum_ovrdflg) {
    /* Switch: '<S56>/Switch4' incorporates:
     *  Constant: '<S56>/sat4'
     */
    VIPM_HURrMirrHeat_enum = KIPM_HURrMirrHeat_enum_ovrdval;
  } else {
    /* Switch: '<S56>/Switch4' */
    VIPM_HURrMirrHeat_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fiu;
  }

  /* End of Switch: '<S56>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HURrMirrHeat_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUSteerWhlHeat_enum' */
  /* Logic: '<S57>/Logical Operator3' incorporates:
   *  Constant: '<S57>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUSteerWhlHeatVld_flg = (KIPM_HUSteerWhlHeat_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S57>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S57>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S57>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S57>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mj =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_SteerWhlHeat;
    }

    /* End of Switch: '<S57>/Switch3' */
  } else {
    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mj = KIPM_HUSteerWhlHeatDflt_enum;
  }

  /* End of Switch: '<S57>/Switch' */

  /* Switch: '<S57>/Switch4' incorporates:
   *  Constant: '<S57>/sat3'
   */
  if (KIPM_HUSteerWhlHeat_enum_ovrdflg) {
    /* Switch: '<S57>/Switch4' incorporates:
     *  Constant: '<S57>/sat4'
     */
    VIPM_HUSteerWhlHeat_enum = KIPM_HUSteerWhlHeat_enum_ovrdval;
  } else {
    /* Switch: '<S57>/Switch4' */
    VIPM_HUSteerWhlHeat_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mj;
  }

  /* End of Switch: '<S57>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUSteerWhlHeat_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUCstRecupModeSel_enum' */
  /* Logic: '<S38>/Logical Operator3' incorporates:
   *  Constant: '<S38>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUCstRecupModeSelVld_flg = (KIPM_HUCstRecupModeSel_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S38>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S38>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S38>/Switch' incorporates:
       *  DataTypeConversion: '<S38>/Data Type Conversion2'
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S38>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ca =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_CoastRecupModeSelect;
    }

    /* End of Switch: '<S38>/Switch3' */
  } else {
    /* Switch: '<S38>/Switch' incorporates:
     *  Constant: '<S38>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ca = KIPM_HUCstRecupModeSelDflt_enum;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Switch: '<S38>/Switch4' incorporates:
   *  Constant: '<S38>/sat3'
   */
  if (KIPM_HUCstRecupModeSel_enum_ovrdflg) {
    /* Switch: '<S38>/Switch4' incorporates:
     *  Constant: '<S38>/sat4'
     */
    VIPM_HUCstRecupModeSel_enum = KIPM_HUCstRecupModeSel_enum_ovrdval;
  } else {
    /* Switch: '<S38>/Switch4' incorporates:
     *  Switch: '<S38>/Switch'
     */
    VIPM_HUCstRecupModeSel_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ca;
  }

  /* End of Switch: '<S38>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUCstRecupModeSel_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUPeristalsisModeEnbl_enum' */
  /* Logic: '<S53>/Logical Operator3' incorporates:
   *  Constant: '<S53>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUPeristalsisModeEnblVld_flg = (KIPM_HUPeristalsisModeEnbl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S53>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S53>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S53>/Switch' incorporates:
       *  DataTypeConversion: '<S53>/Data Type Conversion2'
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S53>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dt =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_PeristalsisModeEnb;
    }

    /* End of Switch: '<S53>/Switch3' */
  } else {
    /* Switch: '<S53>/Switch' incorporates:
     *  Constant: '<S53>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dt = KIPM_HUPeristalsisModeEnblDflt_enum;
  }

  /* End of Switch: '<S53>/Switch' */

  /* Switch: '<S53>/Switch4' incorporates:
   *  Constant: '<S53>/sat3'
   */
  if (KIPM_HUPeristalsisModeEnbl_enum_ovrdflg) {
    /* Switch: '<S53>/Switch4' incorporates:
     *  Constant: '<S53>/sat4'
     */
    VIPM_HUPeristalsisModeEnbl_enum = KIPM_HUPeristalsisModeEnbl_enum_ovrdval;
  } else {
    /* Switch: '<S53>/Switch4' incorporates:
     *  Switch: '<S53>/Switch'
     */
    VIPM_HUPeristalsisModeEnbl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dt;
  }

  /* End of Switch: '<S53>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUPeristalsisModeEnbl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUIllmndUnlckSts_enum' */
  /* Logic: '<S46>/Logical Operator3' incorporates:
   *  Constant: '<S46>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUIllmndUnlckStsVld_flg = (KIPM_HUIllmndUnlckSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S46>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S46>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S46>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S46>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nfb =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_IllmndUnlockSts;
    }

    /* End of Switch: '<S46>/Switch3' */
  } else {
    /* Switch: '<S46>/Switch' incorporates:
     *  Constant: '<S46>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nfb = KIPM_HUIllmndUnlckStsDflt_enum;
  }

  /* End of Switch: '<S46>/Switch' */

  /* Switch: '<S46>/Switch4' incorporates:
   *  Constant: '<S46>/sat3'
   */
  if (KIPM_HUIllmndUnlckSts_enum_ovrdflg) {
    /* Switch: '<S46>/Switch4' incorporates:
     *  Constant: '<S46>/sat4'
     */
    VIPM_HUIllmndUnlckSts_enum = KIPM_HUIllmndUnlckSts_enum_ovrdval;
  } else {
    /* Switch: '<S46>/Switch4' */
    VIPM_HUIllmndUnlckSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nfb;
  }

  /* End of Switch: '<S46>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUIllmndUnlckSts_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUIllmndLckSts_enum' */
  /* Logic: '<S45>/Logical Operator3' incorporates:
   *  Constant: '<S45>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUIllmndLckStsVld_flg = (KIPM_HUIllmndLckSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S45>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S45>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S45>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S45>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jks =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_IllmndLockSts;
    }

    /* End of Switch: '<S45>/Switch3' */
  } else {
    /* Switch: '<S45>/Switch' incorporates:
     *  Constant: '<S45>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jks = KIPM_HUIllmndLckStsDflt_enum;
  }

  /* End of Switch: '<S45>/Switch' */

  /* Switch: '<S45>/Switch4' incorporates:
   *  Constant: '<S45>/sat3'
   */
  if (KIPM_HUIllmndLckSts_enum_ovrdflg) {
    /* Switch: '<S45>/Switch4' incorporates:
     *  Constant: '<S45>/sat4'
     */
    VIPM_HUIllmndLckSts_enum = KIPM_HUIllmndLckSts_enum_ovrdval;
  } else {
    /* Switch: '<S45>/Switch4' */
    VIPM_HUIllmndLckSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jks;
  }

  /* End of Switch: '<S45>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUIllmndLckSts_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUDrvModeSel_enum' */
  /* Logic: '<S39>/Logical Operator3' incorporates:
   *  Constant: '<S39>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUDrvModeSelVld_flg = (KIPM_HUDrvModeSel_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S39>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S39>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S39>/Switch' incorporates:
       *  DataTypeConversion: '<S39>/Data Type Conversion2'
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S39>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_DrivingModeSelect;
    }

    /* End of Switch: '<S39>/Switch3' */
  } else {
    /* Switch: '<S39>/Switch' incorporates:
     *  Constant: '<S39>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k0 = KIPM_HUDrvModeSelDflt_enum;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Switch: '<S39>/Switch4' incorporates:
   *  Constant: '<S39>/sat3'
   */
  if (KIPM_HUDrvModeSel_enum_ovrdflg) {
    /* Switch: '<S39>/Switch4' incorporates:
     *  Constant: '<S39>/sat4'
     */
    VIPM_HUDrvModeSel_enum = KIPM_HUDrvModeSel_enum_ovrdval;
  } else {
    /* Switch: '<S39>/Switch4' incorporates:
     *  Switch: '<S39>/Switch'
     */
    VIPM_HUDrvModeSel_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k0;
  }

  /* End of Switch: '<S39>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUDrvModeSel_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HURecupPwrSet_pct' */
  /* Logic: '<S55>/Logical Operator3' incorporates:
   *  Constant: '<S55>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HURecupPwrSetVld_flg = (KIPM_HURecupPwrSet_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S55>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S55>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S55>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S55>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dk =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_RecuperatePowerSet;
    }

    /* End of Switch: '<S55>/Switch3' */
  } else {
    /* Switch: '<S55>/Switch' incorporates:
     *  Constant: '<S55>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dk = KIPM_HURecupPwrSetDflt_pct;
  }

  /* End of Switch: '<S55>/Switch' */

  /* Switch: '<S55>/Switch4' incorporates:
   *  Constant: '<S55>/sat3'
   */
  if (KIPM_HURecupPwrSet_pct_ovrdflg) {
    /* Switch: '<S55>/Switch4' incorporates:
     *  Constant: '<S55>/sat4'
     */
    VIPM_HURecupPwrSet_pct = KIPM_HURecupPwrSet_pct_ovrdval;
  } else {
    /* Switch: '<S55>/Switch4' */
    VIPM_HURecupPwrSet_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dk;
  }

  /* End of Switch: '<S55>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HURecupPwrSet_pct' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUDrvPwrSet_cnt' */
  /* Logic: '<S40>/Logical Operator3' incorporates:
   *  Constant: '<S40>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUDrvPwrSetVld_flg = (KIPM_HUDrvPwrSet_cnt_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S40>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S40>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S40>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S40>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bg =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_DrivingPowerSet;
    }

    /* End of Switch: '<S40>/Switch3' */
  } else {
    /* Switch: '<S40>/Switch' incorporates:
     *  Constant: '<S40>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bg = KIPM_HUDrvPwrSetDflt_cnt;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Switch: '<S40>/Switch4' incorporates:
   *  Constant: '<S40>/sat3'
   */
  if (KIPM_HUDrvPwrSet_cnt_ovrdflg) {
    /* Switch: '<S40>/Switch4' incorporates:
     *  Constant: '<S40>/sat4'
     */
    VIPM_HUDrvPwrSet_cnt = KIPM_HUDrvPwrSet_cnt_ovrdval;
  } else {
    /* Switch: '<S40>/Switch4' */
    VIPM_HUDrvPwrSet_cnt = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bg;
  }

  /* End of Switch: '<S40>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUDrvPwrSet_cnt' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUChrgngmode_enum' */
  /* Logic: '<S37>/Logical Operator3' incorporates:
   *  Constant: '<S37>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUChrgngmodeVld_flg = (KIPM_HUChrgngmode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S37>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S37>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S37>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S37>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_Chargingmode;
    }

    /* End of Switch: '<S37>/Switch3' */
  } else {
    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S37>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mv = KIPM_HUChrgngmodeDflt_enum;
  }

  /* End of Switch: '<S37>/Switch' */

  /* Switch: '<S37>/Switch4' incorporates:
   *  Constant: '<S37>/sat3'
   */
  if (KIPM_HUChrgngmode_enum_ovrdflg) {
    /* Switch: '<S37>/Switch4' incorporates:
     *  Constant: '<S37>/sat4'
     */
    VIPM_HUChrgngmode_enum = KIPM_HUChrgngmode_enum_ovrdval;
  } else {
    /* Switch: '<S37>/Switch4' */
    VIPM_HUChrgngmode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mv;
  }

  /* End of Switch: '<S37>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUChrgngmode_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUChrgngReq_enum' */
  /* Logic: '<S36>/Logical Operator3' incorporates:
   *  Constant: '<S36>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUChrgngReqVld_flg = (KIPM_HUChrgngReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S36>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S36>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S36>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S36>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cd =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ChargingRequest;
    }

    /* End of Switch: '<S36>/Switch3' */
  } else {
    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S36>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cd = KIPM_HUChrgngReqDflt_enum;
  }

  /* End of Switch: '<S36>/Switch' */

  /* Switch: '<S36>/Switch4' incorporates:
   *  Constant: '<S36>/sat3'
   */
  if (KIPM_HUChrgngReq_enum_ovrdflg) {
    /* Switch: '<S36>/Switch4' incorporates:
     *  Constant: '<S36>/sat4'
     */
    VIPM_HUChrgngReq_enum = KIPM_HUChrgngReq_enum_ovrdval;
  } else {
    /* Switch: '<S36>/Switch4' */
    VIPM_HUChrgngReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cd;
  }

  /* End of Switch: '<S36>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUChrgngReq_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUVehMaxCurr_A' */
  /* Logic: '<S60>/Logical Operator3' incorporates:
   *  Constant: '<S60>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUVehMaxCurrVld_flg = (KIPM_HUVehMaxCurr_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S60>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S60>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S60>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S60>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ks =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_VehMaxCurrent;
    }

    /* End of Switch: '<S60>/Switch3' */
  } else {
    /* Switch: '<S60>/Switch' incorporates:
     *  Constant: '<S60>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ks = KIPM_HUVehMaxCurrDflt_A;
  }

  /* End of Switch: '<S60>/Switch' */

  /* Switch: '<S60>/Switch4' incorporates:
   *  Constant: '<S60>/sat3'
   */
  if (KIPM_HUVehMaxCurr_A_ovrdflg) {
    /* Switch: '<S60>/Switch4' incorporates:
     *  Constant: '<S60>/sat4'
     */
    VIPM_HUVehMaxCurr_A = KIPM_HUVehMaxCurr_A_ovrdval;
  } else {
    /* Switch: '<S60>/Switch4' */
    VIPM_HUVehMaxCurr_A = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ks;
  }

  /* End of Switch: '<S60>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUVehMaxCurr_A' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUACUnlckVentSet_enum' */
  /* Logic: '<S30>/Logical Operator3' incorporates:
   *  Constant: '<S30>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUACUnlckVentSetVld_flg = (KIPM_HUACUnlckVentSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S30>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S30>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S30>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S30>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_ACUnlockVentSet;
    }

    /* End of Switch: '<S30>/Switch3' */
  } else {
    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S30>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jv = KIPM_HUACUnlckVentSetDflt_enum;
  }

  /* End of Switch: '<S30>/Switch' */

  /* Switch: '<S30>/Switch4' incorporates:
   *  Constant: '<S30>/sat3'
   */
  if (KIPM_HUACUnlckVentSet_enum_ovrdflg) {
    /* Switch: '<S30>/Switch4' incorporates:
     *  Constant: '<S30>/sat4'
     */
    VIPM_HUACUnlckVentSet_enum = KIPM_HUACUnlckVentSet_enum_ovrdval;
  } else {
    /* Switch: '<S30>/Switch4' */
    VIPM_HUACUnlckVentSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jv;
  }

  /* End of Switch: '<S30>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUACUnlckVentSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBoxRmtCarSearch_enum' */
  /* Logic: '<S73>/Logical Operator3' incorporates:
   *  Constant: '<S73>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBoxRmtCarSearchVld_flg = (KIPM_TBoxRmtCarSearch_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S73>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S73>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S73>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S73>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c3 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBox_RemoteCarSearch;
    }

    /* End of Switch: '<S73>/Switch3' */
  } else {
    /* Switch: '<S73>/Switch' incorporates:
     *  Constant: '<S73>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c3 = KIPM_TBoxRmtCarSearchDflt_enum;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Switch: '<S73>/Switch4' incorporates:
   *  Constant: '<S73>/sat3'
   */
  if (KIPM_TBoxRmtCarSearch_enum_ovrdflg) {
    /* Switch: '<S73>/Switch4' incorporates:
     *  Constant: '<S73>/sat4'
     */
    VIPM_TBoxRmtCarSearch_enum = KIPM_TBoxRmtCarSearch_enum_ovrdval;
  } else {
    /* Switch: '<S73>/Switch4' */
    VIPM_TBoxRmtCarSearch_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c3;
  }

  /* End of Switch: '<S73>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBoxRmtCarSearch_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBoxOpenVentn_enum' */
  /* Logic: '<S72>/Logical Operator3' incorporates:
   *  Constant: '<S72>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBoxOpenVentnVld_flg = (KIPM_TBoxOpenVentn_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S72>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S72>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S72>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S72>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ps =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBox_OpenVentilation;
    }

    /* End of Switch: '<S72>/Switch3' */
  } else {
    /* Switch: '<S72>/Switch' incorporates:
     *  Constant: '<S72>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ps = KIPM_TBoxOpenVentnDflt_enum;
  }

  /* End of Switch: '<S72>/Switch' */

  /* Switch: '<S72>/Switch4' incorporates:
   *  Constant: '<S72>/sat3'
   */
  if (KIPM_TBoxOpenVentn_enum_ovrdflg) {
    /* Switch: '<S72>/Switch4' incorporates:
     *  Constant: '<S72>/sat4'
     */
    VIPM_TBoxOpenVentn_enum = KIPM_TBoxOpenVentn_enum_ovrdval;
  } else {
    /* Switch: '<S72>/Switch4' */
    VIPM_TBoxOpenVentn_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ps;
  }

  /* End of Switch: '<S72>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBoxOpenVentn_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXACRemtCtrlFlg_enum' */
  /* Logic: '<S62>/Logical Operator3' incorporates:
   *  Constant: '<S62>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXACRemtCtrlFlgVld_flg = (KIPM_TBOXACRemtCtrlFlg_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S62>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S62>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S62>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S62>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_np =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_AC_RemtCtrlFlag;
    }

    /* End of Switch: '<S62>/Switch3' */
  } else {
    /* Switch: '<S62>/Switch' incorporates:
     *  Constant: '<S62>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_np = KIPM_TBOXACRemtCtrlFlgDflt_enum;
  }

  /* End of Switch: '<S62>/Switch' */

  /* Switch: '<S62>/Switch4' incorporates:
   *  Constant: '<S62>/sat3'
   */
  if (KIPM_TBOXACRemtCtrlFlg_enum_ovrdflg) {
    /* Switch: '<S62>/Switch4' incorporates:
     *  Constant: '<S62>/sat4'
     */
    VIPM_TBOXACRemtCtrlFlg_enum = KIPM_TBOXACRemtCtrlFlg_enum_ovrdval;
  } else {
    /* Switch: '<S62>/Switch4' */
    VIPM_TBOXACRemtCtrlFlg_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_np;
  }

  /* End of Switch: '<S62>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXACRemtCtrlFlg_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXACTempSet_enum' */
  /* Logic: '<S63>/Logical Operator3' incorporates:
   *  Constant: '<S63>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXACTempSetVld_flg = (KIPM_TBOXACTempSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S63>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S63>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S63>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S63>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nuf =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->TBOX_AC_TempSet;
    }

    /* End of Switch: '<S63>/Switch3' */
  } else {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nuf = KIPM_TBOXACTempSetDflt_enum;
  }

  /* End of Switch: '<S63>/Switch' */

  /* Switch: '<S63>/Switch4' incorporates:
   *  Constant: '<S63>/sat3'
   */
  if (KIPM_TBOXACTempSet_enum_ovrdflg) {
    /* Switch: '<S63>/Switch4' incorporates:
     *  Constant: '<S63>/sat4'
     */
    VIPM_TBOXACTempSet_enum = KIPM_TBOXACTempSet_enum_ovrdval;
  } else {
    /* Switch: '<S63>/Switch4' */
    VIPM_TBOXACTempSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nuf;
  }

  /* End of Switch: '<S63>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXACTempSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TboxRmtDefrstCtl_enum' */
  /* Logic: '<S75>/Logical Operator3' incorporates:
   *  Constant: '<S75>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TboxRmtDefrstCtlVld_flg = (KIPM_TboxRmtDefrstCtl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S75>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S75>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S75>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S75>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mn =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->Tbox_RemoteDefrostCtl;
    }

    /* End of Switch: '<S75>/Switch3' */
  } else {
    /* Switch: '<S75>/Switch' incorporates:
     *  Constant: '<S75>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mn = KIPM_TboxRmtDefrstCtlDflt_enum;
  }

  /* End of Switch: '<S75>/Switch' */

  /* Switch: '<S75>/Switch4' incorporates:
   *  Constant: '<S75>/sat3'
   */
  if (KIPM_TboxRmtDefrstCtl_enum_ovrdflg) {
    /* Switch: '<S75>/Switch4' incorporates:
     *  Constant: '<S75>/sat4'
     */
    VIPM_TboxRmtDefrstCtl_enum = KIPM_TboxRmtDefrstCtl_enum_ovrdval;
  } else {
    /* Switch: '<S75>/Switch4' */
    VIPM_TboxRmtDefrstCtl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mn;
  }

  /* End of Switch: '<S75>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TboxRmtDefrstCtl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXVCUVer_flg' */
  /* Logic: '<S71>/Logical Operator3' incorporates:
   *  Constant: '<S71>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUVerVld_flg = (KIPM_TBOXVCUVer_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S71>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S71>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S71>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S71>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2i =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->TBOX_VCU_Version;
    }

    /* End of Switch: '<S71>/Switch3' */
  } else {
    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S71>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2i = KIPM_TBOXVCUVerDflt_flg;
  }

  /* End of Switch: '<S71>/Switch' */

  /* Switch: '<S71>/Switch4' incorporates:
   *  Constant: '<S71>/sat3'
   */
  if (KIPM_TBOXVCUVer_flg_ovrdflg) {
    /* Switch: '<S71>/Switch4' incorporates:
     *  Constant: '<S71>/sat4'
     */
    VIPM_TBOXVCUVer_flg = KIPM_TBOXVCUVer_flg_ovrdval;
  } else {
    /* Switch: '<S71>/Switch4' */
    VIPM_TBOXVCUVer_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2i;
  }

  /* End of Switch: '<S71>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXVCUVer_flg' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXVCUOprtLic_flg' */
  /* Logic: '<S70>/Logical Operator3' incorporates:
   *  Constant: '<S70>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUOprtLicVld_flg = (KIPM_TBOXVCUOprtLic_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S70>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S70>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S70>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S70>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_et =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_VCU_OperatLicence;
    }

    /* End of Switch: '<S70>/Switch3' */
  } else {
    /* Switch: '<S70>/Switch' incorporates:
     *  Constant: '<S70>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_et = KIPM_TBOXVCUOprtLicDflt_flg;
  }

  /* End of Switch: '<S70>/Switch' */

  /* Switch: '<S70>/Switch4' incorporates:
   *  Constant: '<S70>/sat3'
   */
  if (KIPM_TBOXVCUOprtLic_flg_ovrdflg) {
    /* Switch: '<S70>/Switch4' incorporates:
     *  Constant: '<S70>/sat4'
     */
    VIPM_TBOXVCUOprtLic_flg = KIPM_TBOXVCUOprtLic_flg_ovrdval;
  } else {
    /* Switch: '<S70>/Switch4' */
    VIPM_TBOXVCUOprtLic_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_et;
  }

  /* End of Switch: '<S70>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXVCUOprtLic_flg' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXVCUChrgngConds_flg' */
  /* Logic: '<S69>/Logical Operator3' incorporates:
   *  Constant: '<S69>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUChrgngCondsVld_flg = (KIPM_TBOXVCUChrgngConds_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S69>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S69>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S69>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S69>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo0 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_VCU_ChargingConditions;
    }

    /* End of Switch: '<S69>/Switch3' */
  } else {
    /* Switch: '<S69>/Switch' incorporates:
     *  Constant: '<S69>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo0 = KIPM_TBOXVCUChrgngCondsDflt_flg;
  }

  /* End of Switch: '<S69>/Switch' */

  /* Switch: '<S69>/Switch4' incorporates:
   *  Constant: '<S69>/sat3'
   */
  if (KIPM_TBOXVCUChrgngConds_flg_ovrdflg) {
    /* Switch: '<S69>/Switch4' incorporates:
     *  Constant: '<S69>/sat4'
     */
    VIPM_TBOXVCUChrgngConds_flg = KIPM_TBOXVCUChrgngConds_flg_ovrdval;
  } else {
    /* Switch: '<S69>/Switch4' */
    VIPM_TBOXVCUChrgngConds_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo0;
  }

  /* End of Switch: '<S69>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXVCUChrgngConds_flg' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXRmtPwrLck_enum' */
  /* Logic: '<S67>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/HU_B_BAC'
   */
  rtb_LogicalOperator2_j = ((Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC()
    )->TBOX_RemotePowerLockV &&
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Logic: '<S67>/Logical Operator3' incorporates:
   *  Constant: '<S67>/sat3'
   */
  VIPM_TBOXRmtPwrLckVld_flg = (KIPM_TBOXRmtPwrLck_enum_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S67>/Switch' */
  if (rtb_LogicalOperator2_j) {
    /* Switch: '<S67>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S67>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S67>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_js =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_RemotePowerLock;
    }

    /* End of Switch: '<S67>/Switch3' */
  } else {
    /* Switch: '<S67>/Switch' incorporates:
     *  Constant: '<S67>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_js = KIPM_TBOXRmtPwrLckDflt_enum;
  }

  /* End of Switch: '<S67>/Switch' */

  /* Switch: '<S67>/Switch4' incorporates:
   *  Constant: '<S67>/sat3'
   */
  if (KIPM_TBOXRmtPwrLck_enum_ovrdflg) {
    /* Switch: '<S67>/Switch4' incorporates:
     *  Constant: '<S67>/sat4'
     */
    VIPM_TBOXRmtPwrLck_enum = KIPM_TBOXRmtPwrLck_enum_ovrdval;
  } else {
    /* Switch: '<S67>/Switch4' */
    VIPM_TBOXRmtPwrLck_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_js;
  }

  /* End of Switch: '<S67>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXRmtPwrLck_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXVCUCCMSpdLimLvl_enum' */
  /* Logic: '<S68>/Logical Operator3' incorporates:
   *  Constant: '<S68>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXVCUCCMSpdLimLvlVld_flg = (KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S68>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S68>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S68>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S68>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_as =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_VCU_CCM_SpeedLimitLevel;
    }

    /* End of Switch: '<S68>/Switch3' */
  } else {
    /* Switch: '<S68>/Switch' incorporates:
     *  Constant: '<S68>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_as = KIPM_TBOXVCUCCMSpdLimLvlDflt_enum;
  }

  /* End of Switch: '<S68>/Switch' */

  /* Switch: '<S68>/Switch4' incorporates:
   *  Constant: '<S68>/sat3'
   */
  if (KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdflg) {
    /* Switch: '<S68>/Switch4' incorporates:
     *  Constant: '<S68>/sat4'
     */
    VIPM_TBOXVCUCCMSpdLimLvl_enum = KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdval;
  } else {
    /* Switch: '<S68>/Switch4' */
    VIPM_TBOXVCUCCMSpdLimLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_as;
  }

  /* End of Switch: '<S68>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXVCUCCMSpdLimLvl_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBoxRmtLck_enum' */
  /* Logic: '<S74>/Logical Operator3' incorporates:
   *  Constant: '<S74>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBoxRmtLckVld_flg = (KIPM_TBoxRmtLck_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S74>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S74>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S74>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S74>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c5 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->TBox_RemoteLock;
    }

    /* End of Switch: '<S74>/Switch3' */
  } else {
    /* Switch: '<S74>/Switch' incorporates:
     *  Constant: '<S74>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c5 = KIPM_TBoxRmtLckDflt_enum;
  }

  /* End of Switch: '<S74>/Switch' */

  /* Switch: '<S74>/Switch4' incorporates:
   *  Constant: '<S74>/sat3'
   */
  if (KIPM_TBoxRmtLck_enum_ovrdflg) {
    /* Switch: '<S74>/Switch4' incorporates:
     *  Constant: '<S74>/sat4'
     */
    VIPM_TBoxRmtLck_enum = KIPM_TBoxRmtLck_enum_ovrdval;
  } else {
    /* Switch: '<S74>/Switch4' */
    VIPM_TBoxRmtLck_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c5;
  }

  /* End of Switch: '<S74>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBoxRmtLck_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXRemtPwrCtrlReq_enum' */
  /* Logic: '<S65>/Logical Operator3' incorporates:
   *  Constant: '<S65>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXRemtPwrCtrlReqVld_flg = (KIPM_TBOXRemtPwrCtrlReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S65>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S65>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S65>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S65>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_RemtPowerCtrlReq;
    }

    /* End of Switch: '<S65>/Switch3' */
  } else {
    /* Switch: '<S65>/Switch' incorporates:
     *  Constant: '<S65>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo = KIPM_TBOXRemtPwrCtrlReqDflt_enum;
  }

  /* End of Switch: '<S65>/Switch' */

  /* Switch: '<S65>/Switch4' incorporates:
   *  Constant: '<S65>/sat3'
   */
  if (KIPM_TBOXRemtPwrCtrlReq_enum_ovrdflg) {
    /* Switch: '<S65>/Switch4' incorporates:
     *  Constant: '<S65>/sat4'
     */
    VIPM_TBOXRemtPwrCtrlReq_enum = KIPM_TBOXRemtPwrCtrlReq_enum_ovrdval;
  } else {
    /* Switch: '<S65>/Switch4' */
    VIPM_TBOXRemtPwrCtrlReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bo;
  }

  /* End of Switch: '<S65>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXRemtPwrCtrlReq_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXRemtStrWhlHeatReq_enum' */
  /* Logic: '<S66>/Logical Operator3' incorporates:
   *  Constant: '<S66>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXRemtStrWhlHeatReqVld_flg = (KIPM_TBOXRemtStrWhlHeatReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S66>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S66>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S66>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S66>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ic =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_RemtSteerWhlHeatReq;
    }

    /* End of Switch: '<S66>/Switch3' */
  } else {
    /* Switch: '<S66>/Switch' incorporates:
     *  Constant: '<S66>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ic = KIPM_TBOXRemtStrWhlHeatReqDflt_enum;
  }

  /* End of Switch: '<S66>/Switch' */

  /* Switch: '<S66>/Switch4' incorporates:
   *  Constant: '<S66>/sat3'
   */
  if (KIPM_TBOXRemtStrWhlHeatReq_enum_ovrdflg) {
    /* Switch: '<S66>/Switch4' incorporates:
     *  Constant: '<S66>/sat4'
     */
    VIPM_TBOXRemtStrWhlHeatReq_enum = KIPM_TBOXRemtStrWhlHeatReq_enum_ovrdval;
  } else {
    /* Switch: '<S66>/Switch4' */
    VIPM_TBOXRemtStrWhlHeatReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ic;
  }

  /* End of Switch: '<S66>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXRemtStrWhlHeatReq_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_TBOXRemtMaiDrSeatHeatReq_enum' */
  /* Logic: '<S64>/Logical Operator3' incorporates:
   *  Constant: '<S64>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_TBOXRemtMaiDrSeatHeatReqVld_flg =
    (KIPM_TBOXRemtMaiDrSeatHeatReq_enum_ovrdflg ||
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_HUMsgActv_flg);

  /* Switch: '<S64>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S64>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S64>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S64>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cc =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->TBOX_RemtMaiDrSeatHeatReq;
    }

    /* End of Switch: '<S64>/Switch3' */
  } else {
    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cc =
      KIPM_TBOXRemtMaiDrSeatHeatReqDflt_enum;
  }

  /* End of Switch: '<S64>/Switch' */

  /* Switch: '<S64>/Switch4' incorporates:
   *  Constant: '<S64>/sat3'
   */
  if (KIPM_TBOXRemtMaiDrSeatHeatReq_enum_ovrdflg) {
    /* Switch: '<S64>/Switch4' incorporates:
     *  Constant: '<S64>/sat4'
     */
    VIPM_TBOXRemtMaiDrSeatHeatReq_enum =
      KIPM_TBOXRemtMaiDrSeatHeatReq_enum_ovrdval;
  } else {
    /* Switch: '<S64>/Switch4' */
    VIPM_TBOXRemtMaiDrSeatHeatReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cc;
  }

  /* End of Switch: '<S64>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_TBOXRemtMaiDrSeatHeatReq_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUBCMCargoLghtSet_enum' */
  /* Logic: '<S32>/Logical Operator3' incorporates:
   *  Constant: '<S32>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUBCMCargoLghtSetVld_flg = (KIPM_HUBCMCargoLghtSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S32>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S32>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S32>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S32>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lt =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())
        ->HU_BCMCargoLightSet;
    }

    /* End of Switch: '<S32>/Switch3' */
  } else {
    /* Switch: '<S32>/Switch' incorporates:
     *  Constant: '<S32>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lt = KIPM_HUBCMCargoLghtSetDflt_enum;
  }

  /* End of Switch: '<S32>/Switch' */

  /* Switch: '<S32>/Switch4' incorporates:
   *  Constant: '<S32>/sat3'
   */
  if (KIPM_HUBCMCargoLghtSet_enum_ovrdflg) {
    /* Switch: '<S32>/Switch4' incorporates:
     *  Constant: '<S32>/sat4'
     */
    VIPM_HUBCMCargoLghtSet_enum = KIPM_HUBCMCargoLghtSet_enum_ovrdval;
  } else {
    /* Switch: '<S32>/Switch4' */
    VIPM_HUBCMCargoLghtSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lt;
  }

  /* End of Switch: '<S32>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUBCMCargoLghtSet_enum' */

  /* Outputs for Atomic SubSystem: '<S24>/Subsys_VIPM_HUBCMOTAModeSet_enum' */
  /* Logic: '<S33>/Logical Operator3' incorporates:
   *  Constant: '<S33>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HUBCMOTAModeSetVld_flg = (KIPM_HUBCMOTAModeSet_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())->VIPM_HUMsgActv_flg);

  /* Switch: '<S33>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_HUMsgActv_flg) {
    /* Switch: '<S33>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HU_B_CRCFlt_flg) {
      /* Switch: '<S33>/Switch' incorporates:
       *  Inport: '<Root>/HU_B_BAC'
       *  Switch: '<S33>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cu =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HU_B_BAC_HU_B_BAC())->HU_BCMOTAModeSet;
    }

    /* End of Switch: '<S33>/Switch3' */
  } else {
    /* Switch: '<S33>/Switch' incorporates:
     *  Constant: '<S33>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cu = KIPM_HUBCMOTAModeSetDflt_enum;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Switch: '<S33>/Switch4' incorporates:
   *  Constant: '<S33>/sat3'
   */
  if (KIPM_HUBCMOTAModeSet_enum_ovrdflg) {
    /* Switch: '<S33>/Switch4' incorporates:
     *  Constant: '<S33>/sat4'
     */
    VIPM_HUBCMOTAModeSet_enum = KIPM_HUBCMOTAModeSet_enum_ovrdval;
  } else {
    /* Switch: '<S33>/Switch4' */
    VIPM_HUBCMOTAModeSet_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cu;
  }

  /* End of Switch: '<S33>/Switch4' */
  /* End of Outputs for SubSystem: '<S24>/Subsys_VIPM_HUBCMOTAModeSet_enum' */

  /* BusCreator: '<S24>/BusCreator' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion'
   *  DataTypeConversion: '<S24>/Data Type Conversion1'
   *  DataTypeConversion: '<S24>/Data Type Conversion2'
   *  Logic: '<S27>/Logical Operator3'
   *  Logic: '<S28>/Logical Operator3'
   *  Logic: '<S29>/Logical Operator3'
   *  Logic: '<S30>/Logical Operator3'
   *  Logic: '<S31>/Logical Operator3'
   *  Logic: '<S32>/Logical Operator3'
   *  Logic: '<S33>/Logical Operator3'
   *  Logic: '<S34>/Logical Operator3'
   *  Logic: '<S35>/Logical Operator3'
   *  Logic: '<S36>/Logical Operator3'
   *  Logic: '<S37>/Logical Operator3'
   *  Logic: '<S38>/Logical Operator3'
   *  Logic: '<S39>/Logical Operator3'
   *  Logic: '<S40>/Logical Operator3'
   *  Logic: '<S41>/Logical Operator3'
   *  Logic: '<S42>/Logical Operator3'
   *  Logic: '<S43>/Logical Operator3'
   *  Logic: '<S44>/Logical Operator3'
   *  Logic: '<S45>/Logical Operator3'
   *  Logic: '<S46>/Logical Operator3'
   *  Logic: '<S47>/Logical Operator3'
   *  Logic: '<S48>/Logical Operator3'
   *  Logic: '<S49>/Logical Operator3'
   *  Logic: '<S50>/Logical Operator3'
   *  Logic: '<S51>/Logical Operator3'
   *  Logic: '<S52>/Logical Operator3'
   *  Logic: '<S53>/Logical Operator3'
   *  Logic: '<S54>/Logical Operator3'
   *  Logic: '<S55>/Logical Operator3'
   *  Logic: '<S56>/Logical Operator3'
   *  Logic: '<S57>/Logical Operator3'
   *  Logic: '<S58>/Logical Operator3'
   *  Logic: '<S59>/Logical Operator3'
   *  Logic: '<S60>/Logical Operator3'
   *  Logic: '<S61>/Logical Operator3'
   *  Logic: '<S62>/Logical Operator3'
   *  Logic: '<S63>/Logical Operator3'
   *  Logic: '<S64>/Logical Operator3'
   *  Logic: '<S65>/Logical Operator3'
   *  Logic: '<S66>/Logical Operator3'
   *  Logic: '<S67>/Logical Operator3'
   *  Logic: '<S68>/Logical Operator3'
   *  Logic: '<S69>/Logical Operator3'
   *  Logic: '<S70>/Logical Operator3'
   *  Logic: '<S71>/Logical Operator3'
   *  Logic: '<S72>/Logical Operator3'
   *  Logic: '<S73>/Logical Operator3'
   *  Logic: '<S74>/Logical Operator3'
   *  Logic: '<S75>/Logical Operator3'
   *  Switch: '<S27>/Switch4'
   *  Switch: '<S28>/Switch4'
   *  Switch: '<S29>/Switch4'
   *  Switch: '<S30>/Switch4'
   *  Switch: '<S31>/Switch4'
   *  Switch: '<S32>/Switch4'
   *  Switch: '<S33>/Switch4'
   *  Switch: '<S34>/Switch4'
   *  Switch: '<S35>/Switch4'
   *  Switch: '<S36>/Switch4'
   *  Switch: '<S37>/Switch4'
   *  Switch: '<S38>/Switch4'
   *  Switch: '<S39>/Switch4'
   *  Switch: '<S40>/Switch4'
   *  Switch: '<S41>/Switch4'
   *  Switch: '<S42>/Switch4'
   *  Switch: '<S43>/Switch4'
   *  Switch: '<S44>/Switch4'
   *  Switch: '<S45>/Switch4'
   *  Switch: '<S46>/Switch4'
   *  Switch: '<S47>/Switch4'
   *  Switch: '<S48>/Switch4'
   *  Switch: '<S49>/Switch4'
   *  Switch: '<S50>/Switch4'
   *  Switch: '<S51>/Switch4'
   *  Switch: '<S52>/Switch4'
   *  Switch: '<S53>/Switch4'
   *  Switch: '<S54>/Switch4'
   *  Switch: '<S55>/Switch4'
   *  Switch: '<S56>/Switch4'
   *  Switch: '<S57>/Switch4'
   *  Switch: '<S58>/Switch4'
   *  Switch: '<S59>/Switch4'
   *  Switch: '<S60>/Switch4'
   *  Switch: '<S61>/Switch4'
   *  Switch: '<S62>/Switch4'
   *  Switch: '<S63>/Switch4'
   *  Switch: '<S64>/Switch4'
   *  Switch: '<S65>/Switch4'
   *  Switch: '<S66>/Switch4'
   *  Switch: '<S67>/Switch4'
   *  Switch: '<S68>/Switch4'
   *  Switch: '<S69>/Switch4'
   *  Switch: '<S70>/Switch4'
   *  Switch: '<S71>/Switch4'
   *  Switch: '<S72>/Switch4'
   *  Switch: '<S73>/Switch4'
   *  Switch: '<S74>/Switch4'
   *  Switch: '<S75>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUHybEcoModeSet_enum =
    VIPM_HUHybEcoModeSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUHybEcoModeSetVld_flg =
    VIPM_HUHybEcoModeSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HULeftTempSet_enum =
    VIPM_HULeftTempSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HULeftTempSetVld_flg =
    VIPM_HULeftTempSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUACPwrCtl_enum = VIPM_HUACPwrCtl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUACPwrCtlVld_flg =
    VIPM_HUACPwrCtlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUAirInletModeSet_enum =
    VIPM_HUAirInletModeSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUAirInletModeSetVld_flg =
    VIPM_HUAirInletModeSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUFrntFanSpdSet_enum =
    VIPM_HUFrntFanSpdSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUFrntFanSpdSetVld_flg =
    VIPM_HUFrntFanSpdSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUManlDefrstCtl_enum =
    VIPM_HUManlDefrstCtl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUManlDefrstCtlVld_flg =
    VIPM_HUManlDefrstCtlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUBlwrModeSet_enum =
    VIPM_HUBlwrModeSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUBlwrModeSetVld_flg =
    VIPM_HUBlwrModeSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUFlwrMeHmCtrl_enum =
    VIPM_HUFlwrMeHmCtrl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUFlwrMeHmCtrlVld_flg =
    VIPM_HUFlwrMeHmCtrlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUIllmndEntrySts_enum =
    VIPM_HUIllmndEntrySts_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUIllmndEntryStsVld_flg =
    VIPM_HUIllmndEntryStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HULckHornOnSt_enum =
    VIPM_HULckHornOnSt_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HULckHornOnStVld_flg =
    VIPM_HULckHornOnStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUACAutoCtl_enum =
    VIPM_HUACAutoCtl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUACAutoCtlVld_flg =
    VIPM_HUACAutoCtlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUParkAutoUnlckSet_enum =
    VIPM_HUParkAutoUnlckSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUParkAutoUnlckSetVld_flg =
    VIPM_HUParkAutoUnlckSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUOvrspdCntrlLckSet_enum =
    VIPM_HUOvrspdCntrlLckSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUOvrspdCntrlLckSetVld_flg =
    VIPM_HUOvrspdCntrlLckSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUTrnkLckSwCtrl_enum =
    VIPM_HUTrnkLckSwCtrl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUTrnkLckSwCtrlVld_flg =
    VIPM_HUTrnkLckSwCtrlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUChgWiprMtMdSwSet_enum =
    VIPM_HUChgWiprMtMdSwSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUChgWiprMtMdSwSetVld_flg =
    VIPM_HUChgWiprMtMdSwSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUTPMSRstReq_flg =
    VIPM_HUTPMSRstReq_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUTPMSRstReqVld_flg =
    VIPM_HUTPMSRstReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUMaiDrvrSeatHeat_enum =
    VIPM_HUMaiDrvrSeatHeat_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUMaiDrvrSeatHeatVld_flg =
    VIPM_HUMaiDrvrSeatHeatVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUPwrOffReq_flg = VIPM_HUPwrOffReq_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUPwrOffReqVld_flg =
    VIPM_HUPwrOffReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUWiprIntlTmSet_enum =
    VIPM_HUWiprIntlTmSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUWiprIntlTmSetVld_flg =
    VIPM_HUWiprIntlTmSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_CDCBackLadjval_enum =
    VIPM_CDCBackLadjval_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_CDCBackLadjvalVld_flg =
    VIPM_CDCBackLadjvalVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HURrMirrHeat_enum =
    VIPM_HURrMirrHeat_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HURrMirrHeatVld_flg =
    VIPM_HURrMirrHeatVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUSteerWhlHeat_enum =
    VIPM_HUSteerWhlHeat_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUSteerWhlHeatVld_flg =
    VIPM_HUSteerWhlHeatVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUCstRecupModeSel_enum =
    VIPM_HUCstRecupModeSel_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUCstRecupModeSelVld_flg =
    VIPM_HUCstRecupModeSelVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUPeristalsisModeEnbl_enum =
    VIPM_HUPeristalsisModeEnbl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUPeristalsisModeEnblVld_flg =
    VIPM_HUPeristalsisModeEnblVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUIllmndUnlckSts_enum =
    VIPM_HUIllmndUnlckSts_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUIllmndUnlckStsVld_flg =
    VIPM_HUIllmndUnlckStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUIllmndLckSts_enum =
    VIPM_HUIllmndLckSts_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUIllmndLckStsVld_flg =
    VIPM_HUIllmndLckStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUDrvModeSel_enum =
    VIPM_HUDrvModeSel_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUDrvModeSelVld_flg =
    VIPM_HUDrvModeSelVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HURecupPwrSet_pct =
    VIPM_HURecupPwrSet_pct;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HURecupPwrSetVld_flg =
    VIPM_HURecupPwrSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUDrvPwrSet_cnt = VIPM_HUDrvPwrSet_cnt;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUDrvPwrSetVld_flg =
    VIPM_HUDrvPwrSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUChrgngmode_enum =
    VIPM_HUChrgngmode_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUChrgngmodeVld_flg =
    VIPM_HUChrgngmodeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUChrgngReq_enum =
    VIPM_HUChrgngReq_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUChrgngReqVld_flg =
    VIPM_HUChrgngReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUVehMaxCurr_A = VIPM_HUVehMaxCurr_A;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUVehMaxCurrVld_flg =
    VIPM_HUVehMaxCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUACUnlckVentSet_enum =
    VIPM_HUACUnlckVentSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUACUnlckVentSetVld_flg =
    VIPM_HUACUnlckVentSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBoxRmtCarSearch_enum =
    VIPM_TBoxRmtCarSearch_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBoxRmtCarSearchVld_flg =
    VIPM_TBoxRmtCarSearchVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBoxOpenVentn_enum =
    VIPM_TBoxOpenVentn_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBoxOpenVentnVld_flg =
    VIPM_TBoxOpenVentnVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXACRemtCtrlFlg_enum =
    VIPM_TBOXACRemtCtrlFlg_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXACRemtCtrlFlgVld_flg =
    VIPM_TBOXACRemtCtrlFlgVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXACTempSet_enum =
    VIPM_TBOXACTempSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXACTempSetVld_flg =
    VIPM_TBOXACTempSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TboxRmtDefrstCtl_enum =
    VIPM_TboxRmtDefrstCtl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TboxRmtDefrstCtlVld_flg =
    VIPM_TboxRmtDefrstCtlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUVer_flg = VIPM_TBOXVCUVer_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUVerVld_flg =
    VIPM_TBOXVCUVerVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUOprtLic_flg =
    VIPM_TBOXVCUOprtLic_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUOprtLicVld_flg =
    VIPM_TBOXVCUOprtLicVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUChrgngConds_flg =
    VIPM_TBOXVCUChrgngConds_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUChrgngCondsVld_flg =
    VIPM_TBOXVCUChrgngCondsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRmtPwrLck_enum =
    VIPM_TBOXRmtPwrLck_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRmtPwrLckVld_flg =
    VIPM_TBOXRmtPwrLckVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUCCMSpdLimLvl_enum =
    VIPM_TBOXVCUCCMSpdLimLvl_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXVCUCCMSpdLimLvlVld_flg =
    VIPM_TBOXVCUCCMSpdLimLvlVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBoxRmtLck_enum = VIPM_TBoxRmtLck_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBoxRmtLckVld_flg =
    VIPM_TBoxRmtLckVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRemtPwrCtrlReq_enum =
    VIPM_TBOXRemtPwrCtrlReq_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRemtPwrCtrlReqVld_flg =
    VIPM_TBOXRemtPwrCtrlReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRemtStrWhlHeatReq_enum =
    VIPM_TBOXRemtStrWhlHeatReq_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRemtStrWhlHeatReqVld_flg =
    VIPM_TBOXRemtStrWhlHeatReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRemtMaiDrSeatHeatReq_enum =
    VIPM_TBOXRemtMaiDrSeatHeatReq_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_TBOXRemtMaiDrSeatHeatReqVld_flg =
    VIPM_TBOXRemtMaiDrSeatHeatReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUBCMCargoLghtSet_enum =
    VIPM_HUBCMCargoLghtSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUBCMCargoLghtSetVld_flg =
    VIPM_HUBCMCargoLghtSetVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUBCMOTAModeSet_enum =
    VIPM_HUBCMOTAModeSet_enum;
  AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m.VIPM_HUBCMOTAModeSetVld_flg =
    VIPM_HUBCMOTAModeSetVld_flg;

  /* Outputs for Atomic SubSystem: '<S76>/Subsys_VIPM_ClientNum_enum' */
  /* Logic: '<S80>/Logical Operator3' incorporates:
   *  Constant: '<S80>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ClientNumVld_flg = (KIPM_ClientNum_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S80>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S80>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S80>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hzk =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Client_Number;
  } else {
    /* Switch: '<S80>/Switch' incorporates:
     *  Constant: '<S80>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hzk = KIPM_ClientNumDflt_enum;
  }

  /* End of Switch: '<S80>/Switch' */

  /* Switch: '<S80>/Switch4' incorporates:
   *  Constant: '<S80>/sat3'
   */
  if (KIPM_ClientNum_enum_ovrdflg) {
    /* Switch: '<S80>/Switch4' incorporates:
     *  Constant: '<S80>/sat4'
     */
    VIPM_ClientNum_enum = KIPM_ClientNum_enum_ovrdval;
  } else {
    /* Switch: '<S80>/Switch4' */
    VIPM_ClientNum_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hzk;
  }

  /* End of Switch: '<S80>/Switch4' */
  /* End of Outputs for SubSystem: '<S76>/Subsys_VIPM_ClientNum_enum' */

  /* Outputs for Atomic SubSystem: '<S76>/Subsys_VIPM_APPVerMax_enum' */
  /* Logic: '<S77>/Logical Operator3' incorporates:
   *  Constant: '<S77>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_APPVerMaxVld_flg = (KIPM_APPVerMax_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S77>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S77>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S77>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ce =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->APP_Version_Max;
  } else {
    /* Switch: '<S77>/Switch' incorporates:
     *  Constant: '<S77>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ce = KIPM_APPVerMaxDflt_enum;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Switch: '<S77>/Switch4' incorporates:
   *  Constant: '<S77>/sat3'
   */
  if (KIPM_APPVerMax_enum_ovrdflg) {
    /* Switch: '<S77>/Switch4' incorporates:
     *  Constant: '<S77>/sat4'
     */
    VIPM_APPVerMax_enum = KIPM_APPVerMax_enum_ovrdval;
  } else {
    /* Switch: '<S77>/Switch4' */
    VIPM_APPVerMax_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ce;
  }

  /* End of Switch: '<S77>/Switch4' */
  /* End of Outputs for SubSystem: '<S76>/Subsys_VIPM_APPVerMax_enum' */

  /* Outputs for Atomic SubSystem: '<S76>/Subsys_VIPM_APPVerMin_enum' */
  /* Logic: '<S78>/Logical Operator3' incorporates:
   *  Constant: '<S78>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_APPVerMinVld_flg = (KIPM_APPVerMin_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S78>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S78>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S78>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ge =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->APP_Version_Min;
  } else {
    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ge = KIPM_APPVerMinDflt_enum;
  }

  /* End of Switch: '<S78>/Switch' */

  /* Switch: '<S78>/Switch4' incorporates:
   *  Constant: '<S78>/sat3'
   */
  if (KIPM_APPVerMin_enum_ovrdflg) {
    /* Switch: '<S78>/Switch4' incorporates:
     *  Constant: '<S78>/sat4'
     */
    VIPM_APPVerMin_enum = KIPM_APPVerMin_enum_ovrdval;
  } else {
    /* Switch: '<S78>/Switch4' */
    VIPM_APPVerMin_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ge;
  }

  /* End of Switch: '<S78>/Switch4' */
  /* End of Outputs for SubSystem: '<S76>/Subsys_VIPM_APPVerMin_enum' */

  /* Outputs for Atomic SubSystem: '<S76>/Subsys_VIPM_HwVerMax_enum' */
  /* Logic: '<S81>/Logical Operator3' incorporates:
   *  Constant: '<S81>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HwVerMaxVld_flg = (KIPM_HwVerMax_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S81>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S81>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S81>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pyg =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Hardware_Version_Max;
  } else {
    /* Switch: '<S81>/Switch' incorporates:
     *  Constant: '<S81>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pyg = KIPM_HwVerMaxDflt_enum;
  }

  /* End of Switch: '<S81>/Switch' */

  /* Switch: '<S81>/Switch4' incorporates:
   *  Constant: '<S81>/sat3'
   */
  if (KIPM_HwVerMax_enum_ovrdflg) {
    /* Switch: '<S81>/Switch4' incorporates:
     *  Constant: '<S81>/sat4'
     */
    VIPM_HwVerMax_enum = KIPM_HwVerMax_enum_ovrdval;
  } else {
    /* Switch: '<S81>/Switch4' */
    VIPM_HwVerMax_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pyg;
  }

  /* End of Switch: '<S81>/Switch4' */
  /* End of Outputs for SubSystem: '<S76>/Subsys_VIPM_HwVerMax_enum' */

  /* Outputs for Atomic SubSystem: '<S76>/Subsys_VIPM_HwVerMin_enum' */
  /* Logic: '<S82>/Logical Operator3' incorporates:
   *  Constant: '<S82>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HwVerMinVld_flg = (KIPM_HwVerMin_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S82>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S82>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S82>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ha =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Hardware_Version_Min;
  } else {
    /* Switch: '<S82>/Switch' incorporates:
     *  Constant: '<S82>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ha = KIPM_HwVerMinDflt_enum;
  }

  /* End of Switch: '<S82>/Switch' */

  /* Switch: '<S82>/Switch4' incorporates:
   *  Constant: '<S82>/sat3'
   */
  if (KIPM_HwVerMin_enum_ovrdflg) {
    /* Switch: '<S82>/Switch4' incorporates:
     *  Constant: '<S82>/sat4'
     */
    VIPM_HwVerMin_enum = KIPM_HwVerMin_enum_ovrdval;
  } else {
    /* Switch: '<S82>/Switch4' */
    VIPM_HwVerMin_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ha;
  }

  /* End of Switch: '<S82>/Switch4' */
  /* End of Outputs for SubSystem: '<S76>/Subsys_VIPM_HwVerMin_enum' */

  /* Outputs for Atomic SubSystem: '<S76>/Subsys_VIPM_BootVer_enum' */
  /* Logic: '<S79>/Logical Operator3' incorporates:
   *  Constant: '<S79>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BootVerVld_flg = (KIPM_BootVer_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S79>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S79>/Switch' incorporates:
     *  Inport: '<Root>/ACCM_Version_BOD'
     *  Switch: '<S79>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_evy =
      (Rte_IRead_Runbl_IpmCanRx_100ms_ACCM_Version_BOD_ACCM_Version_BOD())
      ->Boot_Version;
  } else {
    /* Switch: '<S79>/Switch' incorporates:
     *  Constant: '<S79>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_evy = KIPM_BootVerDflt_enum;
  }

  /* End of Switch: '<S79>/Switch' */

  /* Switch: '<S79>/Switch4' incorporates:
   *  Constant: '<S79>/sat3'
   */
  if (KIPM_BootVer_enum_ovrdflg) {
    /* Switch: '<S79>/Switch4' incorporates:
     *  Constant: '<S79>/sat4'
     */
    VIPM_BootVer_enum = KIPM_BootVer_enum_ovrdval;
  } else {
    /* Switch: '<S79>/Switch4' */
    VIPM_BootVer_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_evy;
  }

  /* End of Switch: '<S79>/Switch4' */
  /* End of Outputs for SubSystem: '<S76>/Subsys_VIPM_BootVer_enum' */

  /* BusCreator: '<S76>/BusCreator' incorporates:
   *  Logic: '<S77>/Logical Operator3'
   *  Logic: '<S78>/Logical Operator3'
   *  Logic: '<S79>/Logical Operator3'
   *  Logic: '<S80>/Logical Operator3'
   *  Logic: '<S81>/Logical Operator3'
   *  Logic: '<S82>/Logical Operator3'
   *  Switch: '<S77>/Switch4'
   *  Switch: '<S78>/Switch4'
   *  Switch: '<S79>/Switch4'
   *  Switch: '<S80>/Switch4'
   *  Switch: '<S81>/Switch4'
   *  Switch: '<S82>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_ClientNum_enum =
    VIPM_ClientNum_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_ClientNumVld_flg =
    VIPM_ClientNumVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_APPVerMax_enum =
    VIPM_APPVerMax_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_APPVerMaxVld_flg =
    VIPM_APPVerMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_APPVerMin_enum =
    VIPM_APPVerMin_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_APPVerMinVld_flg =
    VIPM_APPVerMinVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_HwVerMax_enum =
    VIPM_HwVerMax_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_HwVerMaxVld_flg =
    VIPM_HwVerMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_HwVerMin_enum =
    VIPM_HwVerMin_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_HwVerMinVld_flg =
    VIPM_HwVerMinVld_flg;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_BootVer_enum =
    VIPM_BootVer_enum;
  AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d.VIPM_BootVerVld_flg =
    VIPM_BootVerVld_flg;

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPOverDuty_flg' */
  /* Logic: '<S97>/Logical Operator3' incorporates:
   *  Constant: '<S97>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPOverDutyVld_flg = (KIPM_COMPOverDuty_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S97>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S97>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S97>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S97>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ig =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_OverDuty;
    }

    /* End of Switch: '<S97>/Switch3' */
  } else {
    /* Switch: '<S97>/Switch' incorporates:
     *  Constant: '<S97>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ig = KIPM_COMPOverDutyDflt_flg;
  }

  /* End of Switch: '<S97>/Switch' */

  /* Switch: '<S97>/Switch4' incorporates:
   *  Constant: '<S97>/sat3'
   */
  if (KIPM_COMPOverDuty_flg_ovrdflg) {
    /* Switch: '<S97>/Switch4' incorporates:
     *  Constant: '<S97>/sat4'
     */
    VIPM_COMPOverDuty_flg = KIPM_COMPOverDuty_flg_ovrdval;
  } else {
    /* Switch: '<S97>/Switch4' */
    VIPM_COMPOverDuty_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ig;
  }

  /* End of Switch: '<S97>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPOverDuty_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPCommuError_flg' */
  /* Logic: '<S87>/Logical Operator3' incorporates:
   *  Constant: '<S87>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPCommuErrorVld_flg = (KIPM_COMPCommuError_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S87>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S87>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S87>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S87>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ch =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_Commu_Error;
    }

    /* End of Switch: '<S87>/Switch3' */
  } else {
    /* Switch: '<S87>/Switch' incorporates:
     *  Constant: '<S87>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ch = KIPM_COMPCommuErrorDflt_flg;
  }

  /* End of Switch: '<S87>/Switch' */

  /* Switch: '<S87>/Switch4' incorporates:
   *  Constant: '<S87>/sat3'
   */
  if (KIPM_COMPCommuError_flg_ovrdflg) {
    /* Switch: '<S87>/Switch4' incorporates:
     *  Constant: '<S87>/sat4'
     */
    VIPM_COMPCommuError_flg = KIPM_COMPCommuError_flg_ovrdval;
  } else {
    /* Switch: '<S87>/Switch4' */
    VIPM_COMPCommuError_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ch;
  }

  /* End of Switch: '<S87>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPCommuError_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPPISaturation_flg' */
  /* Logic: '<S99>/Logical Operator3' incorporates:
   *  Constant: '<S99>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPPISaturationVld_flg = (KIPM_COMPPISaturation_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S99>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S99>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S99>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S99>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bf =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_PI_Saturation;
    }

    /* End of Switch: '<S99>/Switch3' */
  } else {
    /* Switch: '<S99>/Switch' incorporates:
     *  Constant: '<S99>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bf = KIPM_COMPPISaturationDflt_flg;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Switch: '<S99>/Switch4' incorporates:
   *  Constant: '<S99>/sat3'
   */
  if (KIPM_COMPPISaturation_flg_ovrdflg) {
    /* Switch: '<S99>/Switch4' incorporates:
     *  Constant: '<S99>/sat4'
     */
    VIPM_COMPPISaturation_flg = KIPM_COMPPISaturation_flg_ovrdval;
  } else {
    /* Switch: '<S99>/Switch4' */
    VIPM_COMPPISaturation_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bf;
  }

  /* End of Switch: '<S99>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPPISaturation_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPLoseStep_flg' */
  /* Logic: '<S95>/Logical Operator3' incorporates:
   *  Constant: '<S95>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPLoseStepVld_flg = (KIPM_COMPLoseStep_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S95>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S95>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S95>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S95>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ii =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_LoseStep;
    }

    /* End of Switch: '<S95>/Switch3' */
  } else {
    /* Switch: '<S95>/Switch' incorporates:
     *  Constant: '<S95>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ii = KIPM_COMPLoseStepDflt_flg;
  }

  /* End of Switch: '<S95>/Switch' */

  /* Switch: '<S95>/Switch4' incorporates:
   *  Constant: '<S95>/sat3'
   */
  if (KIPM_COMPLoseStep_flg_ovrdflg) {
    /* Switch: '<S95>/Switch4' incorporates:
     *  Constant: '<S95>/sat4'
     */
    VIPM_COMPLoseStep_flg = KIPM_COMPLoseStep_flg_ovrdval;
  } else {
    /* Switch: '<S95>/Switch4' */
    VIPM_COMPLoseStep_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ii;
  }

  /* End of Switch: '<S95>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPLoseStep_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPSelfChkErr_enum' */
  /* Logic: '<S100>/Logical Operator3' incorporates:
   *  Constant: '<S100>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPSelfChkErrVld_flg = (KIPM_COMPSelfChkErr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S100>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S100>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S100>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S100>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_SelfCheckError;
    }

    /* End of Switch: '<S100>/Switch3' */
  } else {
    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv = KIPM_COMPSelfChkErrDflt_enum;
  }

  /* End of Switch: '<S100>/Switch' */

  /* Switch: '<S100>/Switch4' incorporates:
   *  Constant: '<S100>/sat3'
   */
  if (KIPM_COMPSelfChkErr_enum_ovrdflg) {
    /* Switch: '<S100>/Switch4' incorporates:
     *  Constant: '<S100>/sat4'
     */
    VIPM_COMPSelfChkErr_enum = KIPM_COMPSelfChkErr_enum_ovrdval;
  } else {
    /* Switch: '<S100>/Switch4' */
    VIPM_COMPSelfChkErr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv;
  }

  /* End of Switch: '<S100>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPSelfChkErr_enum' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPIPMErr_flg' */
  /* Logic: '<S93>/Logical Operator3' incorporates:
   *  Constant: '<S93>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPIPMErrVld_flg = (KIPM_COMPIPMErr_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S93>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S93>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S93>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S93>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_do =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_IPM_Error;
    }

    /* End of Switch: '<S93>/Switch3' */
  } else {
    /* Switch: '<S93>/Switch' incorporates:
     *  Constant: '<S93>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_do = KIPM_COMPIPMErrDflt_flg;
  }

  /* End of Switch: '<S93>/Switch' */

  /* Switch: '<S93>/Switch4' incorporates:
   *  Constant: '<S93>/sat3'
   */
  if (KIPM_COMPIPMErr_flg_ovrdflg) {
    /* Switch: '<S93>/Switch4' incorporates:
     *  Constant: '<S93>/sat4'
     */
    VIPM_COMPIPMErr_flg = KIPM_COMPIPMErr_flg_ovrdval;
  } else {
    /* Switch: '<S93>/Switch4' */
    VIPM_COMPIPMErr_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_do;
  }

  /* End of Switch: '<S93>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPIPMErr_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPTempErr_flg' */
  /* Logic: '<S101>/Logical Operator3' incorporates:
   *  Constant: '<S101>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPTempErrVld_flg = (KIPM_COMPTempErr_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S101>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S101>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S101>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S101>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ja =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_TempError;
    }

    /* End of Switch: '<S101>/Switch3' */
  } else {
    /* Switch: '<S101>/Switch' incorporates:
     *  Constant: '<S101>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ja = KIPM_COMPTempErrDflt_flg;
  }

  /* End of Switch: '<S101>/Switch' */

  /* Switch: '<S101>/Switch4' incorporates:
   *  Constant: '<S101>/sat3'
   */
  if (KIPM_COMPTempErr_flg_ovrdflg) {
    /* Switch: '<S101>/Switch4' incorporates:
     *  Constant: '<S101>/sat4'
     */
    VIPM_COMPTempErr_flg = KIPM_COMPTempErr_flg_ovrdval;
  } else {
    /* Switch: '<S101>/Switch4' */
    VIPM_COMPTempErr_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ja;
  }

  /* End of Switch: '<S101>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPTempErr_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPLvErr_enum' */
  /* Logic: '<S96>/Logical Operator3' incorporates:
   *  Constant: '<S96>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPLvErrVld_flg = (KIPM_COMPLvErr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S96>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S96>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S96>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S96>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ck =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())->COMP_LvError;
    }

    /* End of Switch: '<S96>/Switch3' */
  } else {
    /* Switch: '<S96>/Switch' incorporates:
     *  Constant: '<S96>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ck = KIPM_COMPLvErrDflt_enum;
  }

  /* End of Switch: '<S96>/Switch' */

  /* Switch: '<S96>/Switch4' incorporates:
   *  Constant: '<S96>/sat3'
   */
  if (KIPM_COMPLvErr_enum_ovrdflg) {
    /* Switch: '<S96>/Switch4' incorporates:
     *  Constant: '<S96>/sat4'
     */
    VIPM_COMPLvErr_enum = KIPM_COMPLvErr_enum_ovrdval;
  } else {
    /* Switch: '<S96>/Switch4' */
    VIPM_COMPLvErr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ck;
  }

  /* End of Switch: '<S96>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPLvErr_enum' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPHvErr_enum' */
  /* Logic: '<S92>/Logical Operator3' incorporates:
   *  Constant: '<S92>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPHvErrVld_flg = (KIPM_COMPHvErr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S92>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S92>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S92>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S92>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcn =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())->COMP_HvError;
    }

    /* End of Switch: '<S92>/Switch3' */
  } else {
    /* Switch: '<S92>/Switch' incorporates:
     *  Constant: '<S92>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcn = KIPM_COMPHvErrDflt_enum;
  }

  /* End of Switch: '<S92>/Switch' */

  /* Switch: '<S92>/Switch4' incorporates:
   *  Constant: '<S92>/sat3'
   */
  if (KIPM_COMPHvErr_enum_ovrdflg) {
    /* Switch: '<S92>/Switch4' incorporates:
     *  Constant: '<S92>/sat4'
     */
    VIPM_COMPHvErr_enum = KIPM_COMPHvErr_enum_ovrdval;
  } else {
    /* Switch: '<S92>/Switch4' */
    VIPM_COMPHvErr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcn;
  }

  /* End of Switch: '<S92>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPHvErr_enum' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPOvrCurr_enum' */
  /* Logic: '<S98>/Logical Operator3' incorporates:
   *  Constant: '<S98>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPOvrCurrVld_flg = (KIPM_COMPOvrCurr_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S98>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S98>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S98>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S98>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pr =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_OverCurrent;
    }

    /* End of Switch: '<S98>/Switch3' */
  } else {
    /* Switch: '<S98>/Switch' incorporates:
     *  Constant: '<S98>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pr = KIPM_COMPOvrCurrDflt_enum;
  }

  /* End of Switch: '<S98>/Switch' */

  /* Switch: '<S98>/Switch4' incorporates:
   *  Constant: '<S98>/sat3'
   */
  if (KIPM_COMPOvrCurr_enum_ovrdflg) {
    /* Switch: '<S98>/Switch4' incorporates:
     *  Constant: '<S98>/sat4'
     */
    VIPM_COMPOvrCurr_enum = KIPM_COMPOvrCurr_enum_ovrdval;
  } else {
    /* Switch: '<S98>/Switch4' */
    VIPM_COMPOvrCurr_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pr;
  }

  /* End of Switch: '<S98>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPOvrCurr_enum' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPEcompST_enum' */
  /* Logic: '<S90>/Logical Operator3' incorporates:
   *  Constant: '<S90>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPEcompSTVld_flg = (KIPM_COMPEcompST_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S90>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S90>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S90>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S90>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lo =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())->COMP_EcompST;
    }

    /* End of Switch: '<S90>/Switch3' */
  } else {
    /* Switch: '<S90>/Switch' incorporates:
     *  Constant: '<S90>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lo = KIPM_COMPEcompSTDflt_enum;
  }

  /* End of Switch: '<S90>/Switch' */

  /* Switch: '<S90>/Switch4' incorporates:
   *  Constant: '<S90>/sat3'
   */
  if (KIPM_COMPEcompST_enum_ovrdflg) {
    /* Switch: '<S90>/Switch4' incorporates:
     *  Constant: '<S90>/sat4'
     */
    VIPM_COMPEcompST_enum = KIPM_COMPEcompST_enum_ovrdval;
  } else {
    /* Switch: '<S90>/Switch4' */
    VIPM_COMPEcompST_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lo;
  }

  /* End of Switch: '<S90>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPEcompST_enum' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPCurrOfst_flg' */
  /* Logic: '<S88>/Logical Operator3' incorporates:
   *  Constant: '<S88>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPCurrOfstVld_flg = (KIPM_COMPCurrOfst_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S88>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S88>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S88>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S88>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2u =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_CurrentOffset;
    }

    /* End of Switch: '<S88>/Switch3' */
  } else {
    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S88>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2u = KIPM_COMPCurrOfstDflt_flg;
  }

  /* End of Switch: '<S88>/Switch' */

  /* Switch: '<S88>/Switch4' incorporates:
   *  Constant: '<S88>/sat3'
   */
  if (KIPM_COMPCurrOfst_flg_ovrdflg) {
    /* Switch: '<S88>/Switch4' incorporates:
     *  Constant: '<S88>/sat4'
     */
    VIPM_COMPCurrOfst_flg = KIPM_COMPCurrOfst_flg_ovrdval;
  } else {
    /* Switch: '<S88>/Switch4' */
    VIPM_COMPCurrOfst_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2u;
  }

  /* End of Switch: '<S88>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPCurrOfst_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPCANBusOff_flg' */
  /* Logic: '<S86>/Logical Operator3' incorporates:
   *  Constant: '<S86>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPCANBusOffVld_flg = (KIPM_COMPCANBusOff_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S86>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S86>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S86>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S86>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3l =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_CANBusOff;
    }

    /* End of Switch: '<S86>/Switch3' */
  } else {
    /* Switch: '<S86>/Switch' incorporates:
     *  Constant: '<S86>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3l = KIPM_COMPCANBusOffDflt_flg;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Switch: '<S86>/Switch4' incorporates:
   *  Constant: '<S86>/sat3'
   */
  if (KIPM_COMPCANBusOff_flg_ovrdflg) {
    /* Switch: '<S86>/Switch4' incorporates:
     *  Constant: '<S86>/sat4'
     */
    VIPM_COMPCANBusOff_flg = KIPM_COMPCANBusOff_flg_ovrdval;
  } else {
    /* Switch: '<S86>/Switch4' */
    VIPM_COMPCANBusOff_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3l;
  }

  /* End of Switch: '<S86>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPCANBusOff_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_ECUHiVoltInterlockSig_flg' */
  /* Logic: '<S103>/Logical Operator3' incorporates:
   *  Constant: '<S103>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ECUHiVoltInterlockSigVld_flg = (KIPM_ECUHiVoltInterlockSig_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S103>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S103>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S103>/Switch' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Switch: '<S103>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg3 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->ECUHighVoltInterlockSignal;
    }

    /* End of Switch: '<S103>/Switch3' */
  } else {
    /* Switch: '<S103>/Switch' incorporates:
     *  Constant: '<S103>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg3 = KIPM_ECUHiVoltInterlockSigDflt_flg;
  }

  /* End of Switch: '<S103>/Switch' */

  /* Switch: '<S103>/Switch4' incorporates:
   *  Constant: '<S103>/sat3'
   */
  if (KIPM_ECUHiVoltInterlockSig_flg_ovrdflg) {
    /* Switch: '<S103>/Switch4' incorporates:
     *  Constant: '<S103>/sat4'
     */
    VIPM_ECUHiVoltInterlockSig_flg = KIPM_ECUHiVoltInterlockSig_flg_ovrdval;
  } else {
    /* Switch: '<S103>/Switch4' */
    VIPM_ECUHiVoltInterlockSig_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg3;
  }

  /* End of Switch: '<S103>/Switch4' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_ECUHiVoltInterlockSig_flg' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPTemp_C' */
  /* Logic: '<S102>/Logical Operator3' incorporates:
   *  Constant: '<S102>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPTempVld_flg = (KIPM_COMPTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S102>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S102>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Product: '<S104>/Product' incorporates:
       *  Inport: '<Root>/COMP_AC_BOD'
       */
      rtb_Add_np = (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_Temperature;

      /* Switch: '<S102>/Switch' incorporates:
       *  Sum: '<S104>/Add'
       *  Switch: '<S102>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lq = (float32)rtb_Add_np - 60.0F;
    }

    /* End of Switch: '<S102>/Switch3' */
  } else {
    /* Switch: '<S102>/Switch' incorporates:
     *  Constant: '<S102>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lq = KIPM_COMPTempDflt_C;
  }

  /* End of Switch: '<S102>/Switch' */

  /* Switch: '<S102>/Switch4' incorporates:
   *  Constant: '<S102>/sat3'
   *  Constant: '<S102>/sat4'
   */
  if (KIPM_COMPTemp_C_ovrdflg) {
    VIPM_COMPTemp_C = KIPM_COMPTemp_C_ovrdval;
  } else {
    VIPM_COMPTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lq;
  }

  /* MinMax: '<S102>/MinMax' incorporates:
   *  Constant: '<S102>/sat6'
   *  Switch: '<S102>/Switch4'
   */
  if (VIPM_COMPTemp_C > KIPM_COMPTempHi_C) {
    VIPM_COMPTemp_C = KIPM_COMPTempHi_C;
  }

  /* End of MinMax: '<S102>/MinMax' */

  /* MinMax: '<S102>/MinMax1' incorporates:
   *  Constant: '<S102>/sat7'
   */
  if (VIPM_COMPTemp_C < KIPM_COMPTempLo_C) {
    /* Switch: '<S102>/Switch4' incorporates:
     *  MinMax: '<S102>/MinMax1'
     */
    VIPM_COMPTemp_C = KIPM_COMPTempLo_C;
  }

  /* End of MinMax: '<S102>/MinMax1' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPTemp_C' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPInCurr_A' */
  /* Logic: '<S94>/Logical Operator3' incorporates:
   *  Constant: '<S94>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPInCurrVld_flg = (KIPM_COMPInCurr_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S94>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S94>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Switch: '<S94>/Switch' incorporates:
       *  Constant: '<S105>/Constant'
       *  Inport: '<Root>/COMP_AC_BOD'
       *  Product: '<S105>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h = (float32)
        (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_InputCurrent * 0.25F;
    }

    /* End of Switch: '<S94>/Switch3' */
  } else {
    /* Switch: '<S94>/Switch' incorporates:
     *  Constant: '<S94>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h = KIPM_COMPInCurrDflt_A;
  }

  /* End of Switch: '<S94>/Switch' */

  /* Switch: '<S94>/Switch4' incorporates:
   *  Constant: '<S94>/sat3'
   *  Constant: '<S94>/sat4'
   */
  if (KIPM_COMPInCurr_A_ovrdflg) {
    VIPM_COMPInCurr_A = KIPM_COMPInCurr_A_ovrdval;
  } else {
    VIPM_COMPInCurr_A = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h;
  }

  /* MinMax: '<S94>/MinMax' incorporates:
   *  Constant: '<S94>/sat6'
   *  Switch: '<S94>/Switch4'
   */
  if (VIPM_COMPInCurr_A > KIPM_COMPInCurrHi_A) {
    VIPM_COMPInCurr_A = KIPM_COMPInCurrHi_A;
  }

  /* End of MinMax: '<S94>/MinMax' */

  /* MinMax: '<S94>/MinMax1' incorporates:
   *  Constant: '<S94>/sat7'
   */
  if (VIPM_COMPInCurr_A < KIPM_COMPInCurrLo_A) {
    /* Switch: '<S94>/Switch4' incorporates:
     *  MinMax: '<S94>/MinMax1'
     */
    VIPM_COMPInCurr_A = KIPM_COMPInCurrLo_A;
  }

  /* End of MinMax: '<S94>/MinMax1' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPInCurr_A' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPHiVolt_V' */
  /* Logic: '<S91>/Logical Operator3' incorporates:
   *  Constant: '<S91>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPHiVoltVld_flg = (KIPM_COMPHiVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S91>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S91>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Product: '<S106>/Product' incorporates:
       *  Constant: '<S106>/Constant'
       *  Inport: '<Root>/COMP_AC_BOD'
       */
      rtb_Add_np = (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_High_Voltage << 2;

      /* Switch: '<S91>/Switch' incorporates:
       *  Sum: '<S106>/Add'
       *  Switch: '<S91>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kc = (float32)rtb_Add_np;
    }

    /* End of Switch: '<S91>/Switch3' */
  } else {
    /* Switch: '<S91>/Switch' incorporates:
     *  Constant: '<S91>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kc = KIPM_COMPHiVoltDflt_V;
  }

  /* End of Switch: '<S91>/Switch' */

  /* Switch: '<S91>/Switch4' incorporates:
   *  Constant: '<S91>/sat3'
   *  Constant: '<S91>/sat4'
   */
  if (KIPM_COMPHiVolt_V_ovrdflg) {
    VIPM_COMPHiVolt_V = KIPM_COMPHiVolt_V_ovrdval;
  } else {
    VIPM_COMPHiVolt_V = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kc;
  }

  /* MinMax: '<S91>/MinMax' incorporates:
   *  Constant: '<S91>/sat6'
   *  Switch: '<S91>/Switch4'
   */
  if (VIPM_COMPHiVolt_V > KIPM_COMPHiVoltHi_V) {
    VIPM_COMPHiVolt_V = KIPM_COMPHiVoltHi_V;
  }

  /* End of MinMax: '<S91>/MinMax' */

  /* MinMax: '<S91>/MinMax1' incorporates:
   *  Constant: '<S91>/sat7'
   */
  if (VIPM_COMPHiVolt_V < KIPM_COMPHiVoltLo_V) {
    /* Switch: '<S91>/Switch4' incorporates:
     *  MinMax: '<S91>/MinMax1'
     */
    VIPM_COMPHiVolt_V = KIPM_COMPHiVoltLo_V;
  }

  /* End of MinMax: '<S91>/MinMax1' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPHiVolt_V' */

  /* Outputs for Atomic SubSystem: '<S83>/Subsys_VIPM_COMPEcompActSpd_rpm' */
  /* Logic: '<S89>/Logical Operator3' incorporates:
   *  Constant: '<S89>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_COMPEcompActSpdVld_flg = (KIPM_COMPEcompActSpd_rpm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_ACCMMsgActv_flg);

  /* Switch: '<S89>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_ACCMMsgActv_flg) {
    /* Switch: '<S89>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_COMP_AC_CRCFlt_flg) {
      /* Product: '<S107>/Product' incorporates:
       *  Constant: '<S107>/Constant'
       *  Inport: '<Root>/COMP_AC_BOD'
       */
      rtb_Add_np = (Rte_IRead_Runbl_IpmCanRx_100ms_COMP_AC_BOD_COMP_AC_BOD())
        ->COMP_EcompActSpd * 50;

      /* Switch: '<S89>/Switch' incorporates:
       *  Sum: '<S107>/Add'
       *  Switch: '<S89>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hz = (float32)rtb_Add_np;
    }

    /* End of Switch: '<S89>/Switch3' */
  } else {
    /* Switch: '<S89>/Switch' incorporates:
     *  Constant: '<S89>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hz = KIPM_COMPEcompActSpdDflt_rpm;
  }

  /* End of Switch: '<S89>/Switch' */

  /* Switch: '<S89>/Switch4' incorporates:
   *  Constant: '<S89>/sat3'
   *  Constant: '<S89>/sat4'
   */
  if (KIPM_COMPEcompActSpd_rpm_ovrdflg) {
    VIPM_COMPEcompActSpd_rpm = KIPM_COMPEcompActSpd_rpm_ovrdval;
  } else {
    VIPM_COMPEcompActSpd_rpm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hz;
  }

  /* MinMax: '<S89>/MinMax' incorporates:
   *  Constant: '<S89>/sat6'
   *  Switch: '<S89>/Switch4'
   */
  if (VIPM_COMPEcompActSpd_rpm > KIPM_COMPEcompActSpdHi_rpm) {
    VIPM_COMPEcompActSpd_rpm = KIPM_COMPEcompActSpdHi_rpm;
  }

  /* End of MinMax: '<S89>/MinMax' */

  /* MinMax: '<S89>/MinMax1' incorporates:
   *  Constant: '<S89>/sat7'
   */
  if (VIPM_COMPEcompActSpd_rpm < KIPM_COMPEcompActSpdLo_rpm) {
    /* Switch: '<S89>/Switch4' incorporates:
     *  MinMax: '<S89>/MinMax1'
     */
    VIPM_COMPEcompActSpd_rpm = KIPM_COMPEcompActSpdLo_rpm;
  }

  /* End of MinMax: '<S89>/MinMax1' */
  /* End of Outputs for SubSystem: '<S83>/Subsys_VIPM_COMPEcompActSpd_rpm' */

  /* BusCreator: '<S83>/BusCreator' incorporates:
   *  Logic: '<S100>/Logical Operator3'
   *  Logic: '<S101>/Logical Operator3'
   *  Logic: '<S102>/Logical Operator3'
   *  Logic: '<S103>/Logical Operator3'
   *  Logic: '<S86>/Logical Operator3'
   *  Logic: '<S87>/Logical Operator3'
   *  Logic: '<S88>/Logical Operator3'
   *  Logic: '<S89>/Logical Operator3'
   *  Logic: '<S90>/Logical Operator3'
   *  Logic: '<S91>/Logical Operator3'
   *  Logic: '<S92>/Logical Operator3'
   *  Logic: '<S93>/Logical Operator3'
   *  Logic: '<S94>/Logical Operator3'
   *  Logic: '<S95>/Logical Operator3'
   *  Logic: '<S96>/Logical Operator3'
   *  Logic: '<S97>/Logical Operator3'
   *  Logic: '<S98>/Logical Operator3'
   *  Logic: '<S99>/Logical Operator3'
   *  MinMax: '<S102>/MinMax1'
   *  MinMax: '<S89>/MinMax1'
   *  MinMax: '<S91>/MinMax1'
   *  MinMax: '<S94>/MinMax1'
   *  Switch: '<S100>/Switch4'
   *  Switch: '<S101>/Switch4'
   *  Switch: '<S103>/Switch4'
   *  Switch: '<S86>/Switch4'
   *  Switch: '<S87>/Switch4'
   *  Switch: '<S88>/Switch4'
   *  Switch: '<S90>/Switch4'
   *  Switch: '<S92>/Switch4'
   *  Switch: '<S93>/Switch4'
   *  Switch: '<S95>/Switch4'
   *  Switch: '<S96>/Switch4'
   *  Switch: '<S97>/Switch4'
   *  Switch: '<S98>/Switch4'
   *  Switch: '<S99>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPOverDuty_flg =
    VIPM_COMPOverDuty_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPOverDutyVld_flg =
    VIPM_COMPOverDutyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPCommuError_flg =
    VIPM_COMPCommuError_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPCommuErrorVld_flg =
    VIPM_COMPCommuErrorVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPPISaturation_flg =
    VIPM_COMPPISaturation_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPPISaturationVld_flg =
    VIPM_COMPPISaturationVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPLoseStep_flg =
    VIPM_COMPLoseStep_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPLoseStepVld_flg =
    VIPM_COMPLoseStepVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPSelfChkErr_enum =
    VIPM_COMPSelfChkErr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPSelfChkErrVld_flg =
    VIPM_COMPSelfChkErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPIPMErr_flg = VIPM_COMPIPMErr_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPIPMErrVld_flg =
    VIPM_COMPIPMErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPTempErr_flg =
    VIPM_COMPTempErr_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPTempErrVld_flg =
    VIPM_COMPTempErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPLvErr_enum = VIPM_COMPLvErr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPLvErrVld_flg =
    VIPM_COMPLvErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPHvErr_enum = VIPM_COMPHvErr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPHvErrVld_flg =
    VIPM_COMPHvErrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPOvrCurr_enum =
    VIPM_COMPOvrCurr_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPOvrCurrVld_flg =
    VIPM_COMPOvrCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPEcompST_enum =
    VIPM_COMPEcompST_enum;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPEcompSTVld_flg =
    VIPM_COMPEcompSTVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPCurrOfst_flg =
    VIPM_COMPCurrOfst_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPCurrOfstVld_flg =
    VIPM_COMPCurrOfstVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPCANBusOff_flg =
    VIPM_COMPCANBusOff_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPCANBusOffVld_flg =
    VIPM_COMPCANBusOffVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_ECUHiVoltInterlockSig_flg =
    VIPM_ECUHiVoltInterlockSig_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_ECUHiVoltInterlockSigVld_flg =
    VIPM_ECUHiVoltInterlockSigVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPTemp_C = VIPM_COMPTemp_C;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPTempVld_flg =
    VIPM_COMPTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPInCurr_A = VIPM_COMPInCurr_A;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPInCurrVld_flg =
    VIPM_COMPInCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPHiVolt_V = VIPM_COMPHiVolt_V;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPHiVoltVld_flg =
    VIPM_COMPHiVoltVld_flg;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPEcompActSpd_rpm =
    VIPM_COMPEcompActSpd_rpm;
  AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c.VIPM_COMPEcompActSpdVld_flg =
    VIPM_COMPEcompActSpdVld_flg;

  /* Outputs for Atomic SubSystem: '<S84>/Subsys_VIPM_HVCHInletTemp_C' */
  /* Logic: '<S109>/Logical Operator3' incorporates:
   *  Constant: '<S109>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHInletTempVld_flg = (KIPM_HVCHInletTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S109>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S109>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Product: '<S114>/Product' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       */
      rtb_Add_np =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_InletTemp;

      /* Switch: '<S109>/Switch' incorporates:
       *  Sum: '<S114>/Add'
       *  Switch: '<S109>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lk = (float32)rtb_Add_np - 40.0F;
    }

    /* End of Switch: '<S109>/Switch3' */
  } else {
    /* Switch: '<S109>/Switch' incorporates:
     *  Constant: '<S109>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lk = KIPM_HVCHInletTempDflt_C;
  }

  /* End of Switch: '<S109>/Switch' */

  /* Switch: '<S109>/Switch4' incorporates:
   *  Constant: '<S109>/sat3'
   *  Constant: '<S109>/sat4'
   */
  if (KIPM_HVCHInletTemp_C_ovrdflg) {
    VIPM_HVCHInletTemp_C = KIPM_HVCHInletTemp_C_ovrdval;
  } else {
    VIPM_HVCHInletTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lk;
  }

  /* MinMax: '<S109>/MinMax' incorporates:
   *  Constant: '<S109>/sat6'
   *  Switch: '<S109>/Switch4'
   */
  if (VIPM_HVCHInletTemp_C > KIPM_HVCHInletTempHi_C) {
    VIPM_HVCHInletTemp_C = KIPM_HVCHInletTempHi_C;
  }

  /* End of MinMax: '<S109>/MinMax' */

  /* MinMax: '<S109>/MinMax1' incorporates:
   *  Constant: '<S109>/sat7'
   */
  if (VIPM_HVCHInletTemp_C < KIPM_HVCHInletTempLo_C) {
    /* Switch: '<S109>/Switch4' incorporates:
     *  MinMax: '<S109>/MinMax1'
     */
    VIPM_HVCHInletTemp_C = KIPM_HVCHInletTempLo_C;
  }

  /* End of MinMax: '<S109>/MinMax1' */
  /* End of Outputs for SubSystem: '<S84>/Subsys_VIPM_HVCHInletTemp_C' */

  /* Outputs for Atomic SubSystem: '<S84>/Subsys_VIPM_HVCHOutlTemp_C' */
  /* Logic: '<S110>/Logical Operator3' incorporates:
   *  Constant: '<S110>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHOutlTempVld_flg = (KIPM_HVCHOutlTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S110>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S110>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Product: '<S115>/Product' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       */
      rtb_Add_np =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_OutletTemp;

      /* Switch: '<S110>/Switch' incorporates:
       *  Sum: '<S115>/Add'
       *  Switch: '<S110>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_py = (float32)rtb_Add_np - 40.0F;
    }

    /* End of Switch: '<S110>/Switch3' */
  } else {
    /* Switch: '<S110>/Switch' incorporates:
     *  Constant: '<S110>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_py = KIPM_HVCHOutlTempDflt_C;
  }

  /* End of Switch: '<S110>/Switch' */

  /* Switch: '<S110>/Switch4' incorporates:
   *  Constant: '<S110>/sat3'
   *  Constant: '<S110>/sat4'
   */
  if (KIPM_HVCHOutlTemp_C_ovrdflg) {
    VIPM_HVCHOutlTemp_C = KIPM_HVCHOutlTemp_C_ovrdval;
  } else {
    VIPM_HVCHOutlTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_py;
  }

  /* MinMax: '<S110>/MinMax' incorporates:
   *  Constant: '<S110>/sat6'
   *  Switch: '<S110>/Switch4'
   */
  if (VIPM_HVCHOutlTemp_C > KIPM_HVCHOutlTempHi_C) {
    VIPM_HVCHOutlTemp_C = KIPM_HVCHOutlTempHi_C;
  }

  /* End of MinMax: '<S110>/MinMax' */

  /* MinMax: '<S110>/MinMax1' incorporates:
   *  Constant: '<S110>/sat7'
   */
  if (VIPM_HVCHOutlTemp_C < KIPM_HVCHOutlTempLo_C) {
    /* Switch: '<S110>/Switch4' incorporates:
     *  MinMax: '<S110>/MinMax1'
     */
    VIPM_HVCHOutlTemp_C = KIPM_HVCHOutlTempLo_C;
  }

  /* End of MinMax: '<S110>/MinMax1' */
  /* End of Outputs for SubSystem: '<S84>/Subsys_VIPM_HVCHOutlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S84>/Subsys_VIPM_HVCHPCBTemp_C' */
  /* Logic: '<S111>/Logical Operator3' incorporates:
   *  Constant: '<S111>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHPCBTempVld_flg = (KIPM_HVCHPCBTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S111>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S111>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Product: '<S116>/Product' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       */
      rtb_Add_np =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_PCBTemp;

      /* Switch: '<S111>/Switch' incorporates:
       *  Sum: '<S116>/Add'
       *  Switch: '<S111>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1 = (float32)rtb_Add_np - 40.0F;
    }

    /* End of Switch: '<S111>/Switch3' */
  } else {
    /* Switch: '<S111>/Switch' incorporates:
     *  Constant: '<S111>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1 = KIPM_HVCHPCBTempDflt_C;
  }

  /* End of Switch: '<S111>/Switch' */

  /* Switch: '<S111>/Switch4' incorporates:
   *  Constant: '<S111>/sat3'
   *  Constant: '<S111>/sat4'
   */
  if (KIPM_HVCHPCBTemp_C_ovrdflg) {
    VIPM_HVCHPCBTemp_C = KIPM_HVCHPCBTemp_C_ovrdval;
  } else {
    VIPM_HVCHPCBTemp_C = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1;
  }

  /* MinMax: '<S111>/MinMax' incorporates:
   *  Constant: '<S111>/sat6'
   *  Switch: '<S111>/Switch4'
   */
  if (VIPM_HVCHPCBTemp_C > KIPM_HVCHPCBTempHi_C) {
    VIPM_HVCHPCBTemp_C = KIPM_HVCHPCBTempHi_C;
  }

  /* End of MinMax: '<S111>/MinMax' */

  /* MinMax: '<S111>/MinMax1' incorporates:
   *  Constant: '<S111>/sat7'
   */
  if (VIPM_HVCHPCBTemp_C < KIPM_HVCHPCBTempLo_C) {
    /* Switch: '<S111>/Switch4' incorporates:
     *  MinMax: '<S111>/MinMax1'
     */
    VIPM_HVCHPCBTemp_C = KIPM_HVCHPCBTempLo_C;
  }

  /* End of MinMax: '<S111>/MinMax1' */
  /* End of Outputs for SubSystem: '<S84>/Subsys_VIPM_HVCHPCBTemp_C' */

  /* Outputs for Atomic SubSystem: '<S84>/Subsys_VIPM_HVCHWorkMode_enum' */
  /* Logic: '<S113>/Logical Operator3' incorporates:
   *  Constant: '<S113>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHWorkModeVld_flg = (KIPM_HVCHWorkMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S113>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S113>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Switch: '<S113>/Switch' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       *  Switch: '<S113>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_State;
    }

    /* End of Switch: '<S113>/Switch3' */
  } else {
    /* Switch: '<S113>/Switch' incorporates:
     *  Constant: '<S113>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2 = KIPM_HVCHWorkModeDflt_enum;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Switch: '<S113>/Switch4' incorporates:
   *  Constant: '<S113>/sat3'
   */
  if (KIPM_HVCHWorkMode_enum_ovrdflg) {
    /* Switch: '<S113>/Switch4' incorporates:
     *  Constant: '<S113>/sat4'
     */
    VIPM_HVCHWorkMode_enum = KIPM_HVCHWorkMode_enum_ovrdval;
  } else {
    /* Switch: '<S113>/Switch4' */
    VIPM_HVCHWorkMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_h2;
  }

  /* End of Switch: '<S113>/Switch4' */
  /* End of Outputs for SubSystem: '<S84>/Subsys_VIPM_HVCHWorkMode_enum' */

  /* Outputs for Atomic SubSystem: '<S84>/Subsys_VIPM_HVCHHVSt_flg' */
  /* Logic: '<S108>/Logical Operator3' incorporates:
   *  Constant: '<S108>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHHVStVld_flg = (KIPM_HVCHHVSt_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S108>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S108>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Switch: '<S108>/Switch' incorporates:
       *  Inport: '<Root>/HVCH_Status1_BOD'
       *  Switch: '<S108>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kzl =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_HVState;
    }

    /* End of Switch: '<S108>/Switch3' */
  } else {
    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S108>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kzl = KIPM_HVCHHVStDflt_flg;
  }

  /* End of Switch: '<S108>/Switch' */

  /* Switch: '<S108>/Switch4' incorporates:
   *  Constant: '<S108>/sat3'
   */
  if (KIPM_HVCHHVSt_flg_ovrdflg) {
    /* Switch: '<S108>/Switch4' incorporates:
     *  Constant: '<S108>/sat4'
     */
    VIPM_HVCHHVSt_flg = KIPM_HVCHHVSt_flg_ovrdval;
  } else {
    /* Switch: '<S108>/Switch4' */
    VIPM_HVCHHVSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kzl;
  }

  /* End of Switch: '<S108>/Switch4' */
  /* End of Outputs for SubSystem: '<S84>/Subsys_VIPM_HVCHHVSt_flg' */

  /* Outputs for Atomic SubSystem: '<S84>/Subsys_VIPM_HVCHSt_enum' */
  /* Logic: '<S112>/Logical Operator3' incorporates:
   *  Constant: '<S112>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHStVld_flg = (KIPM_HVCHSt_enum_ovrdflg ||
                        (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV()
                        )->VIPM_PTCMsgActv_flg);

  /* Switch: '<S112>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S112>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_HVCH_Status1_CRCFlt_flg) {
      /* Switch: '<S112>/Switch' incorporates:
       *  DataTypeConversion: '<S112>/Data Type Conversion2'
       *  Inport: '<Root>/HVCH_Status1_BOD'
       *  Switch: '<S112>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g5 =
        (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status1_BOD_HVCH_Status1_BOD())
        ->HVCH_WorkMode;
    }

    /* End of Switch: '<S112>/Switch3' */
  } else {
    /* Switch: '<S112>/Switch' incorporates:
     *  Constant: '<S112>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g5 = KIPM_HVCHStDflt_enum;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Switch: '<S112>/Switch4' incorporates:
   *  Constant: '<S112>/sat3'
   */
  if (KIPM_HVCHSt_enum_ovrdflg) {
    /* Switch: '<S112>/Switch4' incorporates:
     *  Constant: '<S112>/sat4'
     */
    VIPM_HVCHSt_enum = KIPM_HVCHSt_enum_ovrdval;
  } else {
    /* Switch: '<S112>/Switch4' */
    VIPM_HVCHSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g5;
  }

  /* End of Switch: '<S112>/Switch4' */
  /* End of Outputs for SubSystem: '<S84>/Subsys_VIPM_HVCHSt_enum' */

  /* BusCreator: '<S84>/BusCreator' incorporates:
   *  Logic: '<S108>/Logical Operator3'
   *  Logic: '<S109>/Logical Operator3'
   *  Logic: '<S110>/Logical Operator3'
   *  Logic: '<S111>/Logical Operator3'
   *  Logic: '<S112>/Logical Operator3'
   *  Logic: '<S113>/Logical Operator3'
   *  MinMax: '<S109>/MinMax1'
   *  MinMax: '<S110>/MinMax1'
   *  MinMax: '<S111>/MinMax1'
   *  Switch: '<S108>/Switch4'
   *  Switch: '<S112>/Switch4'
   *  Switch: '<S113>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHInletTemp_C =
    VIPM_HVCHInletTemp_C;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHInletTempVld_flg =
    VIPM_HVCHInletTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHOutlTemp_C =
    VIPM_HVCHOutlTemp_C;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHOutlTempVld_flg =
    VIPM_HVCHOutlTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHPCBTemp_C =
    VIPM_HVCHPCBTemp_C;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHPCBTempVld_flg =
    VIPM_HVCHPCBTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHWorkMode_enum =
    VIPM_HVCHWorkMode_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHWorkModeVld_flg =
    VIPM_HVCHWorkModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHHVSt_flg =
    VIPM_HVCHHVSt_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHHVStVld_flg =
    VIPM_HVCHHVStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHSt_enum = VIPM_HVCHSt_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g.VIPM_HVCHStVld_flg =
    VIPM_HVCHStVld_flg;

  /* Outputs for Atomic SubSystem: '<S85>/Subsys_VIPM_HVCHFltCod_enum' */
  /* Logic: '<S118>/Logical Operator3' incorporates:
   *  Constant: '<S118>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHFltCodVld_flg = (KIPM_HVCHFltCod_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S118>/Switch4' incorporates:
   *  Constant: '<S118>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S118>/Switch'
   */
  if (KIPM_HVCHFltCod_enum_ovrdflg) {
    /* Switch: '<S118>/Switch4' incorporates:
     *  Constant: '<S118>/sat4'
     */
    VIPM_HVCHFltCod_enum = KIPM_HVCHFltCod_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S118>/Switch4' incorporates:
     *  DataTypeConversion: '<S118>/Data Type Conversion2'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  Switch: '<S118>/Switch'
     */
    VIPM_HVCHFltCod_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_FaultCode;
  } else {
    /* Switch: '<S118>/Switch4' incorporates:
     *  Constant: '<S118>/sat5'
     *  Switch: '<S118>/Switch'
     */
    VIPM_HVCHFltCod_enum = KIPM_HVCHFltCodDflt_enum;
  }

  /* End of Switch: '<S118>/Switch4' */
  /* End of Outputs for SubSystem: '<S85>/Subsys_VIPM_HVCHFltCod_enum' */

  /* Outputs for Atomic SubSystem: '<S85>/Subsys_VIPM_HVCHHVVolts_V' */
  /* Logic: '<S119>/Logical Operator3' incorporates:
   *  Constant: '<S119>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHHVVoltsVld_flg = (KIPM_HVCHHVVolts_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S119>/Switch4' incorporates:
   *  Constant: '<S119>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S119>/Switch'
   */
  if (KIPM_HVCHHVVolts_V_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S119>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHHVVolts_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* Product: '<S122>/Product' incorporates:
     *  Constant: '<S122>/Constant'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  Switch: '<S119>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_HV_Volts << 2;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S122>/Add'
     *  Switch: '<S119>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S119>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S119>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHHVVoltsDflt_V;
  }

  /* End of Switch: '<S119>/Switch4' */

  /* MinMax: '<S119>/MinMax' incorporates:
   *  Constant: '<S119>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_HVCHHVVoltsHi_V) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHHVVoltsHi_V;
  }

  /* End of MinMax: '<S119>/MinMax' */

  /* MinMax: '<S119>/MinMax1' incorporates:
   *  Constant: '<S119>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_HVCHHVVoltsLo_V) {
    /* MinMax: '<S119>/MinMax1' */
    VIPM_HVCHHVVolts_V = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S119>/MinMax1' */
    VIPM_HVCHHVVolts_V = KIPM_HVCHHVVoltsLo_V;
  }

  /* End of MinMax: '<S119>/MinMax1' */
  /* End of Outputs for SubSystem: '<S85>/Subsys_VIPM_HVCHHVVolts_V' */

  /* Outputs for Atomic SubSystem: '<S85>/Subsys_VIPM_HVCHCurr_A' */
  /* Logic: '<S117>/Logical Operator3' incorporates:
   *  Constant: '<S117>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHCurrVld_flg = (KIPM_HVCHCurr_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S117>/Switch4' incorporates:
   *  Constant: '<S117>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S117>/Switch'
   */
  if (KIPM_HVCHCurr_A_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S117>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHCurr_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S123>/Constant'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  MinMax: '<S172>/MinMax'
     *  Product: '<S123>/Product'
     *  Switch: '<S117>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_Current * 0.25F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S117>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S117>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHCurrDflt_A;
  }

  /* End of Switch: '<S117>/Switch4' */

  /* MinMax: '<S117>/MinMax' incorporates:
   *  Constant: '<S117>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_HVCHCurrHi_A) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHCurrHi_A;
  }

  /* End of MinMax: '<S117>/MinMax' */

  /* MinMax: '<S117>/MinMax1' incorporates:
   *  Constant: '<S117>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_HVCHCurrLo_A) {
    /* MinMax: '<S117>/MinMax1' */
    VIPM_HVCHCurr_A = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S117>/MinMax1' */
    VIPM_HVCHCurr_A = KIPM_HVCHCurrLo_A;
  }

  /* End of MinMax: '<S117>/MinMax1' */
  /* End of Outputs for SubSystem: '<S85>/Subsys_VIPM_HVCHCurr_A' */

  /* Outputs for Atomic SubSystem: '<S85>/Subsys_VIPM_HVCHPwr_kW' */
  /* Logic: '<S120>/Logical Operator3' incorporates:
   *  Constant: '<S120>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHPwrVld_flg = (KIPM_HVCHPwr_kW_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S120>/Switch4' incorporates:
   *  Constant: '<S120>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S120>/Switch'
   */
  if (KIPM_HVCHPwr_kW_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S120>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHPwr_kW_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_PTCMsgActv_flg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S124>/Constant'
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  MinMax: '<S172>/MinMax'
     *  Product: '<S124>/Product'
     *  Switch: '<S120>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_Power * 0.1F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S120>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S120>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHPwrDflt_kW;
  }

  /* End of Switch: '<S120>/Switch4' */

  /* MinMax: '<S120>/MinMax' incorporates:
   *  Constant: '<S120>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_HVCHPwrHi_kW) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_HVCHPwrHi_kW;
  }

  /* End of MinMax: '<S120>/MinMax' */

  /* MinMax: '<S120>/MinMax1' incorporates:
   *  Constant: '<S120>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_HVCHPwrLo_kW) {
    /* MinMax: '<S120>/MinMax1' */
    VIPM_HVCHPwr_kW = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S120>/MinMax1' */
    VIPM_HVCHPwr_kW = KIPM_HVCHPwrLo_kW;
  }

  /* End of MinMax: '<S120>/MinMax1' */
  /* End of Outputs for SubSystem: '<S85>/Subsys_VIPM_HVCHPwr_kW' */

  /* Outputs for Atomic SubSystem: '<S85>/Subsys_VIPM_HVCHWorkSt_enum' */
  /* Logic: '<S121>/Logical Operator3' incorporates:
   *  Constant: '<S121>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_HVCHWorkStVld_flg = (KIPM_HVCHWorkSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_PTCMsgActv_flg);

  /* Switch: '<S121>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_PTCMsgActv_flg) {
    /* Switch: '<S121>/Switch' incorporates:
     *  Inport: '<Root>/HVCH_Status2_BOD'
     *  Switch: '<S121>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c4 =
      (Rte_IRead_Runbl_IpmCanRx_100ms_HVCH_Status2_BOD_HVCH_Status2_BOD())
      ->HVCH_WorkState;
  } else {
    /* Switch: '<S121>/Switch' incorporates:
     *  Constant: '<S121>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c4 = KIPM_HVCHWorkStDflt_enum;
  }

  /* End of Switch: '<S121>/Switch' */

  /* Switch: '<S121>/Switch4' incorporates:
   *  Constant: '<S121>/sat3'
   */
  if (KIPM_HVCHWorkSt_enum_ovrdflg) {
    /* Switch: '<S121>/Switch4' incorporates:
     *  Constant: '<S121>/sat4'
     */
    VIPM_HVCHWorkSt_enum = KIPM_HVCHWorkSt_enum_ovrdval;
  } else {
    /* Switch: '<S121>/Switch4' */
    VIPM_HVCHWorkSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c4;
  }

  /* End of Switch: '<S121>/Switch4' */
  /* End of Outputs for SubSystem: '<S85>/Subsys_VIPM_HVCHWorkSt_enum' */

  /* BusCreator: '<S85>/BusCreator' incorporates:
   *  Logic: '<S117>/Logical Operator3'
   *  Logic: '<S118>/Logical Operator3'
   *  Logic: '<S119>/Logical Operator3'
   *  Logic: '<S120>/Logical Operator3'
   *  Logic: '<S121>/Logical Operator3'
   *  MinMax: '<S117>/MinMax1'
   *  MinMax: '<S119>/MinMax1'
   *  MinMax: '<S120>/MinMax1'
   *  Switch: '<S118>/Switch4'
   *  Switch: '<S121>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHFltCod_enum =
    VIPM_HVCHFltCod_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHFltCodVld_flg =
    VIPM_HVCHFltCodVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHHVVolts_V =
    VIPM_HVCHHVVolts_V;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHHVVoltsVld_flg =
    VIPM_HVCHHVVoltsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHCurr_A = VIPM_HVCHCurr_A;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHCurrVld_flg =
    VIPM_HVCHCurrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHPwr_kW = VIPM_HVCHPwr_kW;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHPwrVld_flg =
    VIPM_HVCHPwrVld_flg;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHWorkSt_enum =
    VIPM_HVCHWorkSt_enum;
  AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g.VIPM_HVCHWorkStVld_flg =
    VIPM_HVCHWorkStVld_flg;

  /* Outputs for Atomic SubSystem: '<S125>/Subsys_VIPM_FCMHMAHiBeamReq_flg' */
  /* Logic: '<S126>/Logical Operator3' incorporates:
   *  Constant: '<S126>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMHMAHiBeamReqVld_flg = (KIPM_FCMHMAHiBeamReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_FCMMsgActv_flg);

  /* Switch: '<S126>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S126>/Switch' incorporates:
     *  Inport: '<Root>/FCM_A_CHA'
     *  Switch: '<S126>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mo =
      (Rte_IRead_Runbl_IpmCanRx_100ms_FCM_A_CHA_FCM_A_CHA())
      ->FCM_HMA_HighbeamReq;
  } else {
    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S126>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mo = KIPM_FCMHMAHiBeamReqDflt_flg;
  }

  /* End of Switch: '<S126>/Switch' */

  /* Switch: '<S126>/Switch4' incorporates:
   *  Constant: '<S126>/sat3'
   */
  if (KIPM_FCMHMAHiBeamReq_flg_ovrdflg) {
    /* Switch: '<S126>/Switch4' incorporates:
     *  Constant: '<S126>/sat4'
     */
    VIPM_FCMHMAHiBeamReq_flg = KIPM_FCMHMAHiBeamReq_flg_ovrdval;
  } else {
    /* Switch: '<S126>/Switch4' */
    VIPM_FCMHMAHiBeamReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mo;
  }

  /* End of Switch: '<S126>/Switch4' */
  /* End of Outputs for SubSystem: '<S125>/Subsys_VIPM_FCMHMAHiBeamReq_flg' */

  /* Outputs for Atomic SubSystem: '<S125>/Subsys_VIPM_FCMHMASetFb_flg' */
  /* Logic: '<S127>/Logical Operator3' incorporates:
   *  Constant: '<S127>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMHMASetFbVld_flg = (KIPM_FCMHMASetFb_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_FCMMsgActv_flg);

  /* Switch: '<S127>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Inport: '<Root>/FCM_A_CHA'
     *  Switch: '<S127>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fy =
      (Rte_IRead_Runbl_IpmCanRx_100ms_FCM_A_CHA_FCM_A_CHA())->FCM_HMASetFb;
  } else {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S127>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fy = KIPM_FCMHMASetFbDflt_flg;
  }

  /* End of Switch: '<S127>/Switch' */

  /* Switch: '<S127>/Switch4' incorporates:
   *  Constant: '<S127>/sat3'
   */
  if (KIPM_FCMHMASetFb_flg_ovrdflg) {
    /* Switch: '<S127>/Switch4' incorporates:
     *  Constant: '<S127>/sat4'
     */
    VIPM_FCMHMASetFb_flg = KIPM_FCMHMASetFb_flg_ovrdval;
  } else {
    /* Switch: '<S127>/Switch4' */
    VIPM_FCMHMASetFb_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fy;
  }

  /* End of Switch: '<S127>/Switch4' */
  /* End of Outputs for SubSystem: '<S125>/Subsys_VIPM_FCMHMASetFb_flg' */

  /* BusCreator: '<S125>/BusCreator' incorporates:
   *  Logic: '<S126>/Logical Operator3'
   *  Logic: '<S127>/Logical Operator3'
   *  Switch: '<S126>/Switch4'
   *  Switch: '<S127>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_FCM_A_CHA_f.VIPM_FCMHMAHiBeamReq_flg =
    VIPM_FCMHMAHiBeamReq_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_A_CHA_f.VIPM_FCMHMAHiBeamReqVld_flg =
    VIPM_FCMHMAHiBeamReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_A_CHA_f.VIPM_FCMHMASetFb_flg = VIPM_FCMHMASetFb_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_A_CHA_f.VIPM_FCMHMASetFbVld_flg =
    VIPM_FCMHMASetFbVld_flg;

  /* Outputs for Atomic SubSystem: '<S128>/Subsys_VIPM_BMSHVBatCellTempAve_C' */
  /* Logic: '<S133>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_5_BatTemp_EPT'
   */
  rtb_LogicalOperator2_j =
    ((Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
     ->BMS_HVBatCellTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S133>/Logical Operator3' incorporates:
   *  Constant: '<S133>/sat3'
   */
  VIPM_BMSHVBatCellTempAveVld_flg = (KIPM_BMSHVBatCellTempAve_C_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S133>/Switch4' incorporates:
   *  Constant: '<S133>/sat3'
   *  Switch: '<S133>/Switch'
   */
  if (KIPM_BMSHVBatCellTempAve_C_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S133>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempAve_C_ovrdval;
  } else if (rtb_LogicalOperator2_j) {
    /* Product: '<S136>/Product' incorporates:
     *  Inport: '<Root>/BMS_5_BatTemp_EPT'
     *  Switch: '<S133>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
      ->BMS_HVBatCellTempAve;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S136>/Add'
     *  Switch: '<S133>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np - 40.0F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S133>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S133>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempAveDflt_C;
  }

  /* End of Switch: '<S133>/Switch4' */

  /* MinMax: '<S133>/MinMax' incorporates:
   *  Constant: '<S133>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_BMSHVBatCellTempAveHi_C) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempAveHi_C;
  }

  /* End of MinMax: '<S133>/MinMax' */

  /* MinMax: '<S133>/MinMax1' incorporates:
   *  Constant: '<S133>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_BMSHVBatCellTempAveLo_C) {
    /* MinMax: '<S133>/MinMax1' */
    VIPM_BMSHVBatCellTempAve_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S133>/MinMax1' */
    VIPM_BMSHVBatCellTempAve_C = KIPM_BMSHVBatCellTempAveLo_C;
  }

  /* End of MinMax: '<S133>/MinMax1' */
  /* End of Outputs for SubSystem: '<S128>/Subsys_VIPM_BMSHVBatCellTempAve_C' */

  /* Outputs for Atomic SubSystem: '<S128>/Subsys_VIPM_BMSHVBatCellTempMax_C' */
  /* Logic: '<S134>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_5_BatTemp_EPT'
   */
  rtb_LogicalOperator2_j =
    ((Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
     ->BMS_HVBatCellTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S134>/Logical Operator3' incorporates:
   *  Constant: '<S134>/sat3'
   */
  VIPM_BMSHVBatCellTempMaxVld_flg = (KIPM_BMSHVBatCellTempMax_C_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S134>/Switch4' incorporates:
   *  Constant: '<S134>/sat3'
   *  Switch: '<S134>/Switch'
   */
  if (KIPM_BMSHVBatCellTempMax_C_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S134>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMax_C_ovrdval;
  } else if (rtb_LogicalOperator2_j) {
    /* Product: '<S137>/Product' incorporates:
     *  Inport: '<Root>/BMS_5_BatTemp_EPT'
     *  Switch: '<S134>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
      ->BMS_HVBatCellTempMax;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S137>/Add'
     *  Switch: '<S134>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np - 40.0F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S134>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S134>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMaxDflt_C;
  }

  /* End of Switch: '<S134>/Switch4' */

  /* MinMax: '<S134>/MinMax' incorporates:
   *  Constant: '<S134>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_BMSHVBatCellTempMaxHi_C) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMaxHi_C;
  }

  /* End of MinMax: '<S134>/MinMax' */

  /* MinMax: '<S134>/MinMax1' incorporates:
   *  Constant: '<S134>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_BMSHVBatCellTempMaxLo_C) {
    /* MinMax: '<S134>/MinMax1' */
    VIPM_BMSHVBatCellTempMax_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S134>/MinMax1' */
    VIPM_BMSHVBatCellTempMax_C = KIPM_BMSHVBatCellTempMaxLo_C;
  }

  /* End of MinMax: '<S134>/MinMax1' */
  /* End of Outputs for SubSystem: '<S128>/Subsys_VIPM_BMSHVBatCellTempMax_C' */

  /* Outputs for Atomic SubSystem: '<S128>/Subsys_VIPM_BMSHVBatCellTempMin_C' */
  /* Logic: '<S135>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_5_BatTemp_EPT'
   */
  rtb_LogicalOperator2_j =
    ((Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
     ->BMS_HVBatCellTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S135>/Logical Operator3' incorporates:
   *  Constant: '<S135>/sat3'
   */
  VIPM_BMSHVBatCellTempMinVld_flg = (KIPM_BMSHVBatCellTempMin_C_ovrdflg ||
    rtb_LogicalOperator2_j);

  /* Switch: '<S135>/Switch4' incorporates:
   *  Constant: '<S135>/sat3'
   *  Switch: '<S135>/Switch'
   */
  if (KIPM_BMSHVBatCellTempMin_C_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S135>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMin_C_ovrdval;
  } else if (rtb_LogicalOperator2_j) {
    /* Product: '<S138>/Product' incorporates:
     *  Inport: '<Root>/BMS_5_BatTemp_EPT'
     *  Switch: '<S135>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_5_BatTemp_EPT_BMS_5_BatTemp_EPT())
      ->BMS_HVBatCellTempMin;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S138>/Add'
     *  Switch: '<S135>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np - 40.0F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S135>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S135>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMinDflt_C;
  }

  /* End of Switch: '<S135>/Switch4' */

  /* MinMax: '<S135>/MinMax' incorporates:
   *  Constant: '<S135>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_BMSHVBatCellTempMinHi_C) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_BMSHVBatCellTempMinHi_C;
  }

  /* End of MinMax: '<S135>/MinMax' */

  /* MinMax: '<S135>/MinMax1' incorporates:
   *  Constant: '<S135>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_BMSHVBatCellTempMinLo_C) {
    /* MinMax: '<S135>/MinMax1' */
    VIPM_BMSHVBatCellTempMin_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S135>/MinMax1' */
    VIPM_BMSHVBatCellTempMin_C = KIPM_BMSHVBatCellTempMinLo_C;
  }

  /* End of MinMax: '<S135>/MinMax1' */
  /* End of Outputs for SubSystem: '<S128>/Subsys_VIPM_BMSHVBatCellTempMin_C' */

  /* BusCreator: '<S128>/BusCreator' incorporates:
   *  Logic: '<S133>/Logical Operator3'
   *  Logic: '<S134>/Logical Operator3'
   *  Logic: '<S135>/Logical Operator3'
   *  MinMax: '<S133>/MinMax1'
   *  MinMax: '<S134>/MinMax1'
   *  MinMax: '<S135>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l.VIPM_BMSHVBatCellTempAve_C =
    VIPM_BMSHVBatCellTempAve_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l.VIPM_BMSHVBatCellTempAveVld_flg =
    VIPM_BMSHVBatCellTempAveVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l.VIPM_BMSHVBatCellTempMax_C =
    VIPM_BMSHVBatCellTempMax_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l.VIPM_BMSHVBatCellTempMaxVld_flg =
    VIPM_BMSHVBatCellTempMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l.VIPM_BMSHVBatCellTempMin_C =
    VIPM_BMSHVBatCellTempMin_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l.VIPM_BMSHVBatCellTempMinVld_flg =
    VIPM_BMSHVBatCellTempMinVld_flg;

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngSubID_cnt' */
  /* Logic: '<S146>/Logical Operator3' incorporates:
   *  Constant: '<S146>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngSubIDVld_flg = (KIPM_INVLrngSubID_cnt_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S146>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S146>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S146>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nf =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngSubID;
  } else {
    /* Switch: '<S146>/Switch' incorporates:
     *  Constant: '<S146>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nf = KIPM_INVLrngSubIDDflt_cnt;
  }

  /* End of Switch: '<S146>/Switch' */

  /* Switch: '<S146>/Switch4' incorporates:
   *  Constant: '<S146>/sat3'
   */
  if (KIPM_INVLrngSubID_cnt_ovrdflg) {
    /* Switch: '<S146>/Switch4' incorporates:
     *  Constant: '<S146>/sat4'
     */
    VIPM_INVLrngSubID_cnt = KIPM_INVLrngSubID_cnt_ovrdval;
  } else {
    /* Switch: '<S146>/Switch4' */
    VIPM_INVLrngSubID_cnt = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nf;
  }

  /* End of Switch: '<S146>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngSubID_cnt' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngSts_enum' */
  /* Logic: '<S145>/Logical Operator3' incorporates:
   *  Constant: '<S145>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngStsVld_flg = (KIPM_INVLrngSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S145>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S145>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S145>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5 =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngSts;
  } else {
    /* Switch: '<S145>/Switch' incorporates:
     *  Constant: '<S145>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5 = KIPM_INVLrngStsDflt_enum;
  }

  /* End of Switch: '<S145>/Switch' */

  /* Switch: '<S145>/Switch4' incorporates:
   *  Constant: '<S145>/sat3'
   */
  if (KIPM_INVLrngSts_enum_ovrdflg) {
    /* Switch: '<S145>/Switch4' incorporates:
     *  Constant: '<S145>/sat4'
     */
    VIPM_INVLrngSts_enum = KIPM_INVLrngSts_enum_ovrdval;
  } else {
    /* Switch: '<S145>/Switch4' */
    VIPM_INVLrngSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5;
  }

  /* End of Switch: '<S145>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngSts_enum' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngData02_nu' */
  /* Logic: '<S139>/Logical Operator3' incorporates:
   *  Constant: '<S139>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData02Vld_flg = (KIPM_INVLrngData02_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S139>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S139>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S139>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ju =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData02;
  } else {
    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S139>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ju = KIPM_INVLrngData02Dflt_nu;
  }

  /* End of Switch: '<S139>/Switch' */

  /* Switch: '<S139>/Switch4' incorporates:
   *  Constant: '<S139>/sat3'
   */
  if (KIPM_INVLrngData02_nu_ovrdflg) {
    /* Switch: '<S139>/Switch4' incorporates:
     *  Constant: '<S139>/sat4'
     */
    VIPM_INVLrngData02_nu = KIPM_INVLrngData02_nu_ovrdval;
  } else {
    /* Switch: '<S139>/Switch4' */
    VIPM_INVLrngData02_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ju;
  }

  /* End of Switch: '<S139>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngData02_nu' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngData03_nu' */
  /* Logic: '<S140>/Logical Operator3' incorporates:
   *  Constant: '<S140>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData03Vld_flg = (KIPM_INVLrngData03_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S140>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S140>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S140>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ec =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData03;
  } else {
    /* Switch: '<S140>/Switch' incorporates:
     *  Constant: '<S140>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ec = KIPM_INVLrngData03Dflt_nu;
  }

  /* End of Switch: '<S140>/Switch' */

  /* Switch: '<S140>/Switch4' incorporates:
   *  Constant: '<S140>/sat3'
   */
  if (KIPM_INVLrngData03_nu_ovrdflg) {
    /* Switch: '<S140>/Switch4' incorporates:
     *  Constant: '<S140>/sat4'
     */
    VIPM_INVLrngData03_nu = KIPM_INVLrngData03_nu_ovrdval;
  } else {
    /* Switch: '<S140>/Switch4' */
    VIPM_INVLrngData03_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ec;
  }

  /* End of Switch: '<S140>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngData03_nu' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngData04_nu' */
  /* Logic: '<S141>/Logical Operator3' incorporates:
   *  Constant: '<S141>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData04Vld_flg = (KIPM_INVLrngData04_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S141>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S141>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S141>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_euu =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData04;
  } else {
    /* Switch: '<S141>/Switch' incorporates:
     *  Constant: '<S141>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_euu = KIPM_INVLrngData04Dflt_nu;
  }

  /* End of Switch: '<S141>/Switch' */

  /* Switch: '<S141>/Switch4' incorporates:
   *  Constant: '<S141>/sat3'
   */
  if (KIPM_INVLrngData04_nu_ovrdflg) {
    /* Switch: '<S141>/Switch4' incorporates:
     *  Constant: '<S141>/sat4'
     */
    VIPM_INVLrngData04_nu = KIPM_INVLrngData04_nu_ovrdval;
  } else {
    /* Switch: '<S141>/Switch4' */
    VIPM_INVLrngData04_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_euu;
  }

  /* End of Switch: '<S141>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngData04_nu' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngData05_nu' */
  /* Logic: '<S142>/Logical Operator3' incorporates:
   *  Constant: '<S142>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData05Vld_flg = (KIPM_INVLrngData05_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S142>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S142>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S142>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hl =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData05;
  } else {
    /* Switch: '<S142>/Switch' incorporates:
     *  Constant: '<S142>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hl = KIPM_INVLrngData05Dflt_nu;
  }

  /* End of Switch: '<S142>/Switch' */

  /* Switch: '<S142>/Switch4' incorporates:
   *  Constant: '<S142>/sat3'
   */
  if (KIPM_INVLrngData05_nu_ovrdflg) {
    /* Switch: '<S142>/Switch4' incorporates:
     *  Constant: '<S142>/sat4'
     */
    VIPM_INVLrngData05_nu = KIPM_INVLrngData05_nu_ovrdval;
  } else {
    /* Switch: '<S142>/Switch4' */
    VIPM_INVLrngData05_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hl;
  }

  /* End of Switch: '<S142>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngData05_nu' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngData06_nu' */
  /* Logic: '<S143>/Logical Operator3' incorporates:
   *  Constant: '<S143>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData06Vld_flg = (KIPM_INVLrngData06_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S143>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S143>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S143>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pc =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData06;
  } else {
    /* Switch: '<S143>/Switch' incorporates:
     *  Constant: '<S143>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pc = KIPM_INVLrngData06Dflt_nu;
  }

  /* End of Switch: '<S143>/Switch' */

  /* Switch: '<S143>/Switch4' incorporates:
   *  Constant: '<S143>/sat3'
   */
  if (KIPM_INVLrngData06_nu_ovrdflg) {
    /* Switch: '<S143>/Switch4' incorporates:
     *  Constant: '<S143>/sat4'
     */
    VIPM_INVLrngData06_nu = KIPM_INVLrngData06_nu_ovrdval;
  } else {
    /* Switch: '<S143>/Switch4' */
    VIPM_INVLrngData06_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pc;
  }

  /* End of Switch: '<S143>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngData06_nu' */

  /* Outputs for Atomic SubSystem: '<S129>/Subsys_VIPM_INVLrngData07_nu' */
  /* Logic: '<S144>/Logical Operator3' incorporates:
   *  Constant: '<S144>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INVLrngData07Vld_flg = (KIPM_INVLrngData07_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_INVMsgActv_flg);

  /* Switch: '<S144>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S144>/Switch' incorporates:
     *  Inport: '<Root>/INV_IMMO_Req_EPT'
     *  Switch: '<S144>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg =
      (Rte_IRead_Runbl_IpmCanRx_100ms_INV_IMMO_Req_EPT_INV_IMMO_Req_EPT())
      ->INV_LrngData07;
  } else {
    /* Switch: '<S144>/Switch' incorporates:
     *  Constant: '<S144>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg = KIPM_INVLrngData07Dflt_nu;
  }

  /* End of Switch: '<S144>/Switch' */

  /* Switch: '<S144>/Switch4' incorporates:
   *  Constant: '<S144>/sat3'
   */
  if (KIPM_INVLrngData07_nu_ovrdflg) {
    /* Switch: '<S144>/Switch4' incorporates:
     *  Constant: '<S144>/sat4'
     */
    VIPM_INVLrngData07_nu = KIPM_INVLrngData07_nu_ovrdval;
  } else {
    /* Switch: '<S144>/Switch4' */
    VIPM_INVLrngData07_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lg;
  }

  /* End of Switch: '<S144>/Switch4' */
  /* End of Outputs for SubSystem: '<S129>/Subsys_VIPM_INVLrngData07_nu' */

  /* BusCreator: '<S129>/BusCreator' incorporates:
   *  Logic: '<S139>/Logical Operator3'
   *  Logic: '<S140>/Logical Operator3'
   *  Logic: '<S141>/Logical Operator3'
   *  Logic: '<S142>/Logical Operator3'
   *  Logic: '<S143>/Logical Operator3'
   *  Logic: '<S144>/Logical Operator3'
   *  Logic: '<S145>/Logical Operator3'
   *  Logic: '<S146>/Logical Operator3'
   *  Switch: '<S139>/Switch4'
   *  Switch: '<S140>/Switch4'
   *  Switch: '<S141>/Switch4'
   *  Switch: '<S142>/Switch4'
   *  Switch: '<S143>/Switch4'
   *  Switch: '<S144>/Switch4'
   *  Switch: '<S145>/Switch4'
   *  Switch: '<S146>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngSubID_cnt =
    VIPM_INVLrngSubID_cnt;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngSubIDVld_flg =
    VIPM_INVLrngSubIDVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngSts_enum =
    VIPM_INVLrngSts_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngStsVld_flg =
    VIPM_INVLrngStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData02_nu =
    VIPM_INVLrngData02_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData02Vld_flg =
    VIPM_INVLrngData02Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData03_nu =
    VIPM_INVLrngData03_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData03Vld_flg =
    VIPM_INVLrngData03Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData04_nu =
    VIPM_INVLrngData04_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData04Vld_flg =
    VIPM_INVLrngData04Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData05_nu =
    VIPM_INVLrngData05_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData05Vld_flg =
    VIPM_INVLrngData05Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData06_nu =
    VIPM_INVLrngData06_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData06Vld_flg =
    VIPM_INVLrngData06Vld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData07_nu =
    VIPM_INVLrngData07_nu;
  AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b.VIPM_INVLrngData07Vld_flg =
    VIPM_INVLrngData07Vld_flg;

  /* Outputs for Atomic SubSystem: '<S130>/Subsys_VIPM_IPUDCCActOprtMode_enum' */
  /* Logic: '<S147>/Logical Operator3' incorporates:
   *  Constant: '<S147>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCActOprtModeVld_flg = (KIPM_IPUDCCActOprtMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S147>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S147>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S147>/Switch' incorporates:
       *  DataTypeConversion: '<S147>/Data Type Conversion2'
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Switch: '<S147>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ov =
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_ActlOprtMode;
    }

    /* End of Switch: '<S147>/Switch3' */
  } else {
    /* Switch: '<S147>/Switch' incorporates:
     *  Constant: '<S147>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ov = KIPM_IPUDCCActOprtModeDflt_enum;
  }

  /* End of Switch: '<S147>/Switch' */

  /* Switch: '<S147>/Switch4' incorporates:
   *  Constant: '<S147>/sat3'
   */
  if (KIPM_IPUDCCActOprtMode_enum_ovrdflg) {
    /* Switch: '<S147>/Switch4' incorporates:
     *  Constant: '<S147>/sat4'
     */
    VIPM_IPUDCCActOprtMode_enum = KIPM_IPUDCCActOprtMode_enum_ovrdval;
  } else {
    /* Switch: '<S147>/Switch4' incorporates:
     *  Switch: '<S147>/Switch'
     */
    VIPM_IPUDCCActOprtMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ov;
  }

  /* End of Switch: '<S147>/Switch4' */
  /* End of Outputs for SubSystem: '<S130>/Subsys_VIPM_IPUDCCActOprtMode_enum' */

  /* Outputs for Atomic SubSystem: '<S130>/Subsys_VIPM_IPUDCCLoVoltActVolt_V' */
  /* Logic: '<S149>/Logical Operator3' incorporates:
   *  Constant: '<S149>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCLoVoltActVoltVld_flg = (KIPM_IPUDCCLoVoltActVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S149>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S149>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S149>/Switch' incorporates:
       *  Constant: '<S152>/Constant'
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Product: '<S152>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ow = (float32)
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_LowVolActlVol * 0.1F;
    }

    /* End of Switch: '<S149>/Switch3' */
  } else {
    /* Switch: '<S149>/Switch' incorporates:
     *  Constant: '<S149>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ow = KIPM_IPUDCCLoVoltActVoltDflt_V;
  }

  /* End of Switch: '<S149>/Switch' */

  /* Switch: '<S149>/Switch4' incorporates:
   *  Constant: '<S149>/sat3'
   *  Constant: '<S149>/sat4'
   */
  if (KIPM_IPUDCCLoVoltActVolt_V_ovrdflg) {
    VIPM_IPUDCCLoVoltActVolt_V = KIPM_IPUDCCLoVoltActVolt_V_ovrdval;
  } else {
    VIPM_IPUDCCLoVoltActVolt_V = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ow;
  }

  /* MinMax: '<S149>/MinMax' incorporates:
   *  Constant: '<S149>/sat6'
   *  Switch: '<S149>/Switch4'
   */
  if (VIPM_IPUDCCLoVoltActVolt_V > KIPM_IPUDCCLoVoltActVoltHi_V) {
    VIPM_IPUDCCLoVoltActVolt_V = KIPM_IPUDCCLoVoltActVoltHi_V;
  }

  /* End of MinMax: '<S149>/MinMax' */

  /* MinMax: '<S149>/MinMax1' incorporates:
   *  Constant: '<S149>/sat7'
   */
  if (VIPM_IPUDCCLoVoltActVolt_V < KIPM_IPUDCCLoVoltActVoltLo_V) {
    /* Switch: '<S149>/Switch4' incorporates:
     *  MinMax: '<S149>/MinMax1'
     */
    VIPM_IPUDCCLoVoltActVolt_V = KIPM_IPUDCCLoVoltActVoltLo_V;
  }

  /* End of MinMax: '<S149>/MinMax1' */
  /* End of Outputs for SubSystem: '<S130>/Subsys_VIPM_IPUDCCLoVoltActVolt_V' */

  /* Outputs for Atomic SubSystem: '<S130>/Subsys_VIPM_IPUDCCLoVoltActCurnt_A' */
  /* Logic: '<S148>/Logical Operator3' incorporates:
   *  Constant: '<S148>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCLoVoltActCurntVld_flg = (KIPM_IPUDCCLoVoltActCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S148>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S148>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Product: '<S153>/Product' incorporates:
       *  Constant: '<S153>/Constant'
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       */
      rtb_Product_eyc = (float32)
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_LowVolActlCur * 0.1F;

      /* Switch: '<S148>/Switch' incorporates:
       *  Sum: '<S153>/Add'
       *  Switch: '<S148>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p = rtb_Product_eyc - 409.6F;
    }

    /* End of Switch: '<S148>/Switch3' */
  } else {
    /* Switch: '<S148>/Switch' incorporates:
     *  Constant: '<S148>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p = KIPM_IPUDCCLoVoltActCurntDflt_A;
  }

  /* End of Switch: '<S148>/Switch' */

  /* Switch: '<S148>/Switch4' incorporates:
   *  Constant: '<S148>/sat3'
   *  Constant: '<S148>/sat4'
   */
  if (KIPM_IPUDCCLoVoltActCurnt_A_ovrdflg) {
    VIPM_IPUDCCLoVoltActCurnt_A = KIPM_IPUDCCLoVoltActCurnt_A_ovrdval;
  } else {
    VIPM_IPUDCCLoVoltActCurnt_A = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p;
  }

  /* MinMax: '<S148>/MinMax' incorporates:
   *  Constant: '<S148>/sat6'
   *  Switch: '<S148>/Switch4'
   */
  if (VIPM_IPUDCCLoVoltActCurnt_A > KIPM_IPUDCCLoVoltActCurntHi_A) {
    VIPM_IPUDCCLoVoltActCurnt_A = KIPM_IPUDCCLoVoltActCurntHi_A;
  }

  /* End of MinMax: '<S148>/MinMax' */

  /* MinMax: '<S148>/MinMax1' incorporates:
   *  Constant: '<S148>/sat7'
   */
  if (VIPM_IPUDCCLoVoltActCurnt_A < KIPM_IPUDCCLoVoltActCurntLo_A) {
    /* Switch: '<S148>/Switch4' incorporates:
     *  MinMax: '<S148>/MinMax1'
     */
    VIPM_IPUDCCLoVoltActCurnt_A = KIPM_IPUDCCLoVoltActCurntLo_A;
  }

  /* End of MinMax: '<S148>/MinMax1' */
  /* End of Outputs for SubSystem: '<S130>/Subsys_VIPM_IPUDCCLoVoltActCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S130>/Subsys_VIPM_IPUDCCSysFailSta_enum' */
  /* Logic: '<S150>/Logical Operator3' incorporates:
   *  Constant: '<S150>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCSysFailStaVld_flg = (KIPM_IPUDCCSysFailSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S150>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S150>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S150>/Switch' incorporates:
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Switch: '<S150>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ph =
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_DCC_SysFailSta;
    }

    /* End of Switch: '<S150>/Switch3' */
  } else {
    /* Switch: '<S150>/Switch' incorporates:
     *  Constant: '<S150>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ph = KIPM_IPUDCCSysFailStaDflt_enum;
  }

  /* End of Switch: '<S150>/Switch' */

  /* Switch: '<S150>/Switch4' incorporates:
   *  Constant: '<S150>/sat3'
   */
  if (KIPM_IPUDCCSysFailSta_enum_ovrdflg) {
    /* Switch: '<S150>/Switch4' incorporates:
     *  Constant: '<S150>/sat4'
     */
    VIPM_IPUDCCSysFailSta_enum = KIPM_IPUDCCSysFailSta_enum_ovrdval;
  } else {
    /* Switch: '<S150>/Switch4' */
    VIPM_IPUDCCSysFailSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ph;
  }

  /* End of Switch: '<S150>/Switch4' */
  /* End of Outputs for SubSystem: '<S130>/Subsys_VIPM_IPUDCCSysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S130>/Subsys_VIPM_IPUHVILFailSt_flg' */
  /* Logic: '<S151>/Logical Operator3' incorporates:
   *  Constant: '<S151>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUHVILFailStVld_flg = (KIPM_IPUHVILFailSt_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S151>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_DCDCMsgActv_flg) {
    /* Switch: '<S151>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_100ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_IPU_DCC_1_State_CRCFlt_flg) {
      /* Switch: '<S151>/Switch' incorporates:
       *  Inport: '<Root>/IPU_DCC_1_State_EPT'
       *  Switch: '<S151>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lku =
        (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_1_State_EPT_IPU_DCC_1_State_EPT())
        ->IPU_HVILFailSta;
    }

    /* End of Switch: '<S151>/Switch3' */
  } else {
    /* Switch: '<S151>/Switch' incorporates:
     *  Constant: '<S151>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lku = KIPM_IPUHVILFailStDflt_flg;
  }

  /* End of Switch: '<S151>/Switch' */

  /* Switch: '<S151>/Switch4' incorporates:
   *  Constant: '<S151>/sat3'
   */
  if (KIPM_IPUHVILFailSt_flg_ovrdflg) {
    /* Switch: '<S151>/Switch4' incorporates:
     *  Constant: '<S151>/sat4'
     */
    VIPM_IPUHVILFailSt_flg = KIPM_IPUHVILFailSt_flg_ovrdval;
  } else {
    /* Switch: '<S151>/Switch4' */
    VIPM_IPUHVILFailSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lku;
  }

  /* End of Switch: '<S151>/Switch4' */
  /* End of Outputs for SubSystem: '<S130>/Subsys_VIPM_IPUHVILFailSt_flg' */

  /* BusCreator: '<S130>/BusCreator' incorporates:
   *  DataTypeConversion: '<S130>/Data Type Conversion'
   *  Logic: '<S147>/Logical Operator3'
   *  Logic: '<S148>/Logical Operator3'
   *  Logic: '<S149>/Logical Operator3'
   *  Logic: '<S150>/Logical Operator3'
   *  Logic: '<S151>/Logical Operator3'
   *  MinMax: '<S148>/MinMax1'
   *  MinMax: '<S149>/MinMax1'
   *  Switch: '<S147>/Switch4'
   *  Switch: '<S150>/Switch4'
   *  Switch: '<S151>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCActOprtMode_enum =
    VIPM_IPUDCCActOprtMode_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCActOprtModeVld_flg =
    VIPM_IPUDCCActOprtModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCLoVoltActVolt_V =
    VIPM_IPUDCCLoVoltActVolt_V;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCLoVoltActVoltVld_flg =
    VIPM_IPUDCCLoVoltActVoltVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCLoVoltActCurnt_A =
    VIPM_IPUDCCLoVoltActCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCLoVoltActCurntVld_flg =
    VIPM_IPUDCCLoVoltActCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCSysFailSta_enum =
    VIPM_IPUDCCSysFailSta_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUDCCSysFailStaVld_flg =
    VIPM_IPUDCCSysFailStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUHVILFailSt_flg =
    VIPM_IPUHVILFailSt_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j.VIPM_IPUHVILFailStVld_flg =
    VIPM_IPUHVILFailStVld_flg;

  /* Outputs for Atomic SubSystem: '<S131>/Subsys_VIPM_IPUDCCHiVoltActCurnt_A' */
  /* Logic: '<S154>/Logical Operator3' incorporates:
   *  Constant: '<S154>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCHiVoltActCurntVld_flg = (KIPM_IPUDCCHiVoltActCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S154>/Switch4' incorporates:
   *  Constant: '<S154>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S154>/Switch'
   */
  if (KIPM_IPUDCCHiVoltActCurnt_A_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S154>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_DCDCMsgActv_flg) {
    /* Product: '<S156>/Product' incorporates:
     *  Constant: '<S156>/Constant'
     *  Inport: '<Root>/IPU_DCC_2_ChrgInValue_EPT'
     *  Switch: '<S154>/Switch'
     */
    rtb_Product_eyc = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT
       ())->IPU_DCC_HighVoltActlCur * 0.1F;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S156>/Add'
     *  Switch: '<S154>/Switch'
     */
    VIPM_IPUOBCTempInt_C = rtb_Product_eyc - 25.6F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S154>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S154>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActCurntDflt_A;
  }

  /* End of Switch: '<S154>/Switch4' */

  /* MinMax: '<S154>/MinMax' incorporates:
   *  Constant: '<S154>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUDCCHiVoltActCurntHi_A) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActCurntHi_A;
  }

  /* End of MinMax: '<S154>/MinMax' */

  /* MinMax: '<S154>/MinMax1' incorporates:
   *  Constant: '<S154>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUDCCHiVoltActCurntLo_A) {
    /* MinMax: '<S154>/MinMax1' */
    VIPM_IPUDCCHiVoltActCurnt_A = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S154>/MinMax1' */
    VIPM_IPUDCCHiVoltActCurnt_A = KIPM_IPUDCCHiVoltActCurntLo_A;
  }

  /* End of MinMax: '<S154>/MinMax1' */
  /* End of Outputs for SubSystem: '<S131>/Subsys_VIPM_IPUDCCHiVoltActCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S131>/Subsys_VIPM_IPUDCCHiVoltActVolt_V' */
  /* Logic: '<S155>/Logical Operator3' incorporates:
   *  Constant: '<S155>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDCCHiVoltActVoltVld_flg = (KIPM_IPUDCCHiVoltActVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_DCDCMsgActv_flg);

  /* Switch: '<S155>/Switch4' incorporates:
   *  Constant: '<S155>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S155>/Switch'
   */
  if (KIPM_IPUDCCHiVoltActVolt_V_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S155>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActVolt_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_DCDCMsgActv_flg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S157>/Constant'
     *  Inport: '<Root>/IPU_DCC_2_ChrgInValue_EPT'
     *  MinMax: '<S172>/MinMax'
     *  Product: '<S157>/Product'
     *  Switch: '<S155>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_ChrgInValue_EPT
       ())->IPU_DCC_HighVoltActlVol * 0.5F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S155>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S155>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActVoltDflt_V;
  }

  /* End of Switch: '<S155>/Switch4' */

  /* MinMax: '<S155>/MinMax' incorporates:
   *  Constant: '<S155>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUDCCHiVoltActVoltHi_V) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDCCHiVoltActVoltHi_V;
  }

  /* End of MinMax: '<S155>/MinMax' */

  /* MinMax: '<S155>/MinMax1' incorporates:
   *  Constant: '<S155>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUDCCHiVoltActVoltLo_V) {
    /* MinMax: '<S155>/MinMax1' */
    VIPM_IPUDCCHiVoltActVolt_V = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S155>/MinMax1' */
    VIPM_IPUDCCHiVoltActVolt_V = KIPM_IPUDCCHiVoltActVoltLo_V;
  }

  /* End of MinMax: '<S155>/MinMax1' */
  /* End of Outputs for SubSystem: '<S131>/Subsys_VIPM_IPUDCCHiVoltActVolt_V' */

  /* BusCreator: '<S131>/BusCreator' incorporates:
   *  Logic: '<S154>/Logical Operator3'
   *  Logic: '<S155>/Logical Operator3'
   *  MinMax: '<S154>/MinMax1'
   *  MinMax: '<S155>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT_o.VIPM_IPUDCCHiVoltActCurnt_A
    = VIPM_IPUDCCHiVoltActCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT_o.VIPM_IPUDCCHiVoltActCurntVld_flg
    = VIPM_IPUDCCHiVoltActCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT_o.VIPM_IPUDCCHiVoltActVolt_V =
    VIPM_IPUDCCHiVoltActVolt_V;
  AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT_o.VIPM_IPUDCCHiVoltActVoltVld_flg
    = VIPM_IPUDCCHiVoltActVoltVld_flg;

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCReq_enum' */
  /* Logic: '<S164>/Logical Operator3' incorporates:
   *  Constant: '<S164>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCReqVld_flg = (KIPM_IPUOBCReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S164>/Switch4' incorporates:
   *  Constant: '<S164>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S164>/Switch'
   */
  if (KIPM_IPUOBCReq_enum_ovrdflg) {
    /* Switch: '<S164>/Switch4' incorporates:
     *  Constant: '<S164>/sat4'
     */
    VIPM_IPUOBCReq_enum = KIPM_IPUOBCReq_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S164>/Switch4' incorporates:
     *  DataTypeConversion: '<S164>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S164>/Switch'
     */
    VIPM_IPUOBCReq_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_Request;
  } else {
    /* Switch: '<S164>/Switch4' incorporates:
     *  Constant: '<S164>/sat5'
     *  Switch: '<S164>/Switch'
     */
    VIPM_IPUOBCReq_enum = KIPM_IPUOBCReqDflt_enum;
  }

  /* End of Switch: '<S164>/Switch4' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCReq_enum' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCSysFailSta_enum' */
  /* Logic: '<S165>/Logical Operator3' incorporates:
   *  Constant: '<S165>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCSysFailStaVld_flg = (KIPM_IPUOBCSysFailSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S165>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S165>/Switch' incorporates:
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S165>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mu =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_SysFailSta;
  } else {
    /* Switch: '<S165>/Switch' incorporates:
     *  Constant: '<S165>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mu = KIPM_IPUOBCSysFailStaDflt_enum;
  }

  /* End of Switch: '<S165>/Switch' */

  /* Switch: '<S165>/Switch4' incorporates:
   *  Constant: '<S165>/sat3'
   */
  if (KIPM_IPUOBCSysFailSta_enum_ovrdflg) {
    /* Switch: '<S165>/Switch4' incorporates:
     *  Constant: '<S165>/sat4'
     */
    VIPM_IPUOBCSysFailSta_enum = KIPM_IPUOBCSysFailSta_enum_ovrdval;
  } else {
    /* Switch: '<S165>/Switch4' */
    VIPM_IPUOBCSysFailSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mu;
  }

  /* End of Switch: '<S165>/Switch4' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCSysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCConnectMainSta_flg' */
  /* Logic: '<S159>/Logical Operator3' incorporates:
   *  Constant: '<S159>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCConnectMainStaVld_flg = (KIPM_IPUOBCConnectMainSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S159>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S159>/Switch' incorporates:
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S159>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1x =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_ConnectMainSta;
  } else {
    /* Switch: '<S159>/Switch' incorporates:
     *  Constant: '<S159>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1x = KIPM_IPUOBCConnectMainStaDflt_flg;
  }

  /* End of Switch: '<S159>/Switch' */

  /* Switch: '<S159>/Switch4' incorporates:
   *  Constant: '<S159>/sat3'
   */
  if (KIPM_IPUOBCConnectMainSta_flg_ovrdflg) {
    /* Switch: '<S159>/Switch4' incorporates:
     *  Constant: '<S159>/sat4'
     */
    VIPM_IPUOBCConnectMainSta_flg = KIPM_IPUOBCConnectMainSta_flg_ovrdval;
  } else {
    /* Switch: '<S159>/Switch4' */
    VIPM_IPUOBCConnectMainSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1x;
  }

  /* End of Switch: '<S159>/Switch4' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCConnectMainSta_flg' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCActOprtMode_enum' */
  /* Logic: '<S158>/Logical Operator3' incorporates:
   *  Constant: '<S158>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCActOprtModeVld_flg = (KIPM_IPUOBCActOprtMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S158>/Switch4' incorporates:
   *  Constant: '<S158>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S158>/Switch'
   */
  if (KIPM_IPUOBCActOprtMode_enum_ovrdflg) {
    /* Switch: '<S158>/Switch4' incorporates:
     *  Constant: '<S158>/sat4'
     */
    VIPM_IPUOBCActOprtMode_enum = KIPM_IPUOBCActOprtMode_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S158>/Switch4' incorporates:
     *  DataTypeConversion: '<S158>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S158>/Switch'
     */
    VIPM_IPUOBCActOprtMode_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_ActlOprtMode;
  } else {
    /* Switch: '<S158>/Switch4' incorporates:
     *  Constant: '<S158>/sat5'
     *  Switch: '<S158>/Switch'
     */
    VIPM_IPUOBCActOprtMode_enum = KIPM_IPUOBCActOprtModeDflt_enum;
  }

  /* End of Switch: '<S158>/Switch4' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCActOprtMode_enum' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCInletConnectSta_enum' */
  /* Logic: '<S163>/Logical Operator3' incorporates:
   *  Constant: '<S163>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCInletConnectStaVld_flg = (KIPM_IPUOBCInletConnectSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S163>/Switch4' incorporates:
   *  Constant: '<S163>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S163>/Switch'
   */
  if (KIPM_IPUOBCInletConnectSta_enum_ovrdflg) {
    /* Switch: '<S163>/Switch4' incorporates:
     *  Constant: '<S163>/sat4'
     */
    VIPM_IPUOBCInletConnectSta_enum = KIPM_IPUOBCInletConnectSta_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S163>/Switch4' incorporates:
     *  DataTypeConversion: '<S163>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S163>/Switch'
     */
    VIPM_IPUOBCInletConnectSta_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_InletConnctSta;
  } else {
    /* Switch: '<S163>/Switch4' incorporates:
     *  Constant: '<S163>/sat5'
     *  Switch: '<S163>/Switch'
     */
    VIPM_IPUOBCInletConnectSta_enum = KIPM_IPUOBCInletConnectStaDflt_enum;
  }

  /* End of Switch: '<S163>/Switch4' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCInletConnectSta_enum' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCHVDCActCur_A' */
  /* Logic: '<S160>/Logical Operator3' incorporates:
   *  Constant: '<S160>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCHVDCActCurVld_flg = (KIPM_IPUOBCHVDCActCur_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S160>/Switch4' incorporates:
   *  Constant: '<S160>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S160>/Switch'
   */
  if (KIPM_IPUOBCHVDCActCur_A_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S160>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActCur_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S166>/Product' incorporates:
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S160>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_HVDC_ActlCur;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S166>/Add'
     *  Switch: '<S160>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np - 64.0F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S160>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S160>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActCurDflt_A;
  }

  /* End of Switch: '<S160>/Switch4' */

  /* MinMax: '<S160>/MinMax' incorporates:
   *  Constant: '<S160>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCHVDCActCurHi_A) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActCurHi_A;
  }

  /* End of MinMax: '<S160>/MinMax' */

  /* MinMax: '<S160>/MinMax1' incorporates:
   *  Constant: '<S160>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCHVDCActCurLo_A) {
    /* MinMax: '<S160>/MinMax1' */
    VIPM_IPUOBCHVDCActCur_A = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S160>/MinMax1' */
    VIPM_IPUOBCHVDCActCur_A = KIPM_IPUOBCHVDCActCurLo_A;
  }

  /* End of MinMax: '<S160>/MinMax1' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCHVDCActCur_A' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCHVDCActVol_V' */
  /* Logic: '<S161>/Logical Operator3' incorporates:
   *  Constant: '<S161>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCHVDCActVolVld_flg = (KIPM_IPUOBCHVDCActVol_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S161>/Switch4' incorporates:
   *  Constant: '<S161>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S161>/Switch'
   */
  if (KIPM_IPUOBCHVDCActVol_V_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S161>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActVol_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  DataTypeConversion: '<S161>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S161>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_HVDC_ActlVol;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S161>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S161>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActVolDflt_V;
  }

  /* End of Switch: '<S161>/Switch4' */

  /* MinMax: '<S161>/MinMax' incorporates:
   *  Constant: '<S161>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCHVDCActVolHi_V) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCHVDCActVolHi_V;
  }

  /* End of MinMax: '<S161>/MinMax' */

  /* MinMax: '<S161>/MinMax1' incorporates:
   *  Constant: '<S161>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCHVDCActVolLo_V) {
    /* MinMax: '<S161>/MinMax1' */
    VIPM_IPUOBCHVDCActVol_V = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S161>/MinMax1' */
    VIPM_IPUOBCHVDCActVol_V = KIPM_IPUOBCHVDCActVolLo_V;
  }

  /* End of MinMax: '<S161>/MinMax1' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCHVDCActVol_V' */

  /* Outputs for Atomic SubSystem: '<S132>/Subsys_VIPM_IPUOBCInletActPwr_kW' */
  /* Logic: '<S162>/Logical Operator3' incorporates:
   *  Constant: '<S162>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCInletActPwrVld_flg = (KIPM_IPUOBCInletActPwr_kW_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S162>/Switch4' incorporates:
   *  Constant: '<S162>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S162>/Switch'
   */
  if (KIPM_IPUOBCInletActPwr_kW_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S162>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCInletActPwr_kW_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S167>/Product' incorporates:
     *  Constant: '<S167>/Constant'
     *  Inport: '<Root>/IPU_OBC_1_State_EPT'
     *  Switch: '<S162>/Switch'
     */
    rtb_Product_eyc = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_1_State_EPT_IPU_OBC_1_State_EPT()
      )->IPU_OBC_InleltActlPower * 0.1F;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S167>/Add'
     *  Switch: '<S162>/Switch'
     */
    VIPM_IPUOBCTempInt_C = rtb_Product_eyc - 25.6F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S162>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S162>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCInletActPwrDflt_kW;
  }

  /* End of Switch: '<S162>/Switch4' */

  /* MinMax: '<S162>/MinMax' incorporates:
   *  Constant: '<S162>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCInletActPwrHi_kW) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCInletActPwrHi_kW;
  }

  /* End of MinMax: '<S162>/MinMax' */

  /* MinMax: '<S162>/MinMax1' incorporates:
   *  Constant: '<S162>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCInletActPwrLo_kW) {
    /* MinMax: '<S162>/MinMax1' */
    VIPM_IPUOBCInletActPwr_kW = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S162>/MinMax1' */
    VIPM_IPUOBCInletActPwr_kW = KIPM_IPUOBCInletActPwrLo_kW;
  }

  /* End of MinMax: '<S162>/MinMax1' */
  /* End of Outputs for SubSystem: '<S132>/Subsys_VIPM_IPUOBCInletActPwr_kW' */

  /* BusCreator: '<S132>/BusCreator' incorporates:
   *  DataTypeConversion: '<S132>/Data Type Conversion'
   *  DataTypeConversion: '<S132>/Data Type Conversion1'
   *  DataTypeConversion: '<S132>/Data Type Conversion2'
   *  Logic: '<S158>/Logical Operator3'
   *  Logic: '<S159>/Logical Operator3'
   *  Logic: '<S160>/Logical Operator3'
   *  Logic: '<S161>/Logical Operator3'
   *  Logic: '<S162>/Logical Operator3'
   *  Logic: '<S163>/Logical Operator3'
   *  Logic: '<S164>/Logical Operator3'
   *  Logic: '<S165>/Logical Operator3'
   *  MinMax: '<S160>/MinMax1'
   *  MinMax: '<S161>/MinMax1'
   *  MinMax: '<S162>/MinMax1'
   *  Switch: '<S158>/Switch4'
   *  Switch: '<S159>/Switch4'
   *  Switch: '<S163>/Switch4'
   *  Switch: '<S164>/Switch4'
   *  Switch: '<S165>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCReq_enum =
    VIPM_IPUOBCReq_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCReqVld_flg =
    VIPM_IPUOBCReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCSysFailSta_enum =
    VIPM_IPUOBCSysFailSta_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCSysFailStaVld_flg =
    VIPM_IPUOBCSysFailStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCConnectMainSta_flg =
    VIPM_IPUOBCConnectMainSta_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCConnectMainStaVld_flg =
    VIPM_IPUOBCConnectMainStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCActOprtMode_enum =
    VIPM_IPUOBCActOprtMode_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCActOprtModeVld_flg =
    VIPM_IPUOBCActOprtModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCInletConnectSta_enum =
    VIPM_IPUOBCInletConnectSta_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCInletConnectStaVld_flg
    = VIPM_IPUOBCInletConnectStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCHVDCActCur_A =
    VIPM_IPUOBCHVDCActCur_A;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCHVDCActCurVld_flg =
    VIPM_IPUOBCHVDCActCurVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCHVDCActVol_V =
    VIPM_IPUOBCHVDCActVol_V;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCHVDCActVolVld_flg =
    VIPM_IPUOBCHVDCActVolVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCInletActPwr_kW =
    VIPM_IPUOBCInletActPwr_kW;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b.VIPM_IPUOBCInletActPwrVld_flg =
    VIPM_IPUOBCInletActPwrVld_flg;

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_IPUOBCWakeUpMode_enum' */
  /* Logic: '<S173>/Logical Operator3' incorporates:
   *  Constant: '<S173>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCWakeUpModeVld_flg = (KIPM_IPUOBCWakeUpMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S173>/Switch4' incorporates:
   *  Constant: '<S173>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S173>/Switch'
   */
  if (KIPM_IPUOBCWakeUpMode_enum_ovrdflg) {
    /* Switch: '<S173>/Switch4' incorporates:
     *  Constant: '<S173>/sat4'
     */
    VIPM_IPUOBCWakeUpMode_enum = KIPM_IPUOBCWakeUpMode_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S173>/Switch4' incorporates:
     *  DataTypeConversion: '<S173>/Data Type Conversion2'
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S173>/Switch'
     */
    VIPM_IPUOBCWakeUpMode_enum =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_Wake_Up_Mode;
  } else {
    /* Switch: '<S173>/Switch4' incorporates:
     *  Constant: '<S173>/sat5'
     *  Switch: '<S173>/Switch'
     */
    VIPM_IPUOBCWakeUpMode_enum = KIPM_IPUOBCWakeUpModeDflt_enum;
  }

  /* End of Switch: '<S173>/Switch4' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_IPUOBCWakeUpMode_enum' */

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_IPUOBCS2State_flg' */
  /* Logic: '<S171>/Logical Operator3' incorporates:
   *  Constant: '<S171>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCS2StateVld_flg = (KIPM_IPUOBCS2State_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S171>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_OBCMsgActv_flg) {
    /* Switch: '<S171>/Switch' incorporates:
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S171>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aj =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_S2_State;
  } else {
    /* Switch: '<S171>/Switch' incorporates:
     *  Constant: '<S171>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aj = KIPM_IPUOBCS2StateDflt_flg;
  }

  /* End of Switch: '<S171>/Switch' */

  /* Switch: '<S171>/Switch4' incorporates:
   *  Constant: '<S171>/sat3'
   */
  if (KIPM_IPUOBCS2State_flg_ovrdflg) {
    /* Switch: '<S171>/Switch4' incorporates:
     *  Constant: '<S171>/sat4'
     */
    VIPM_IPUOBCS2State_flg = KIPM_IPUOBCS2State_flg_ovrdval;
  } else {
    /* Switch: '<S171>/Switch4' */
    VIPM_IPUOBCS2State_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_aj;
  }

  /* End of Switch: '<S171>/Switch4' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_IPUOBCS2State_flg' */

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW' */
  /* Logic: '<S170>/Logical Operator3' incorporates:
   *  Constant: '<S170>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCACMaxPwrAllowVld_flg = (KIPM_IPUOBCACMaxPwrAllow_kW_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S170>/Switch4' incorporates:
   *  Constant: '<S170>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S170>/Switch'
   */
  if (KIPM_IPUOBCACMaxPwrAllow_kW_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S170>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCACMaxPwrAllow_kW_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S174>/Product' incorporates:
     *  Constant: '<S174>/Constant'
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S170>/Switch'
     */
    rtb_Product_eyc = (float32)
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_ACMaxPwAllow * 0.2F;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S174>/Add'
     *  Switch: '<S170>/Switch'
     */
    VIPM_IPUOBCTempInt_C = rtb_Product_eyc - 102.4F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S170>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S170>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCACMaxPwrAllowDflt_kW;
  }

  /* End of Switch: '<S170>/Switch4' */

  /* MinMax: '<S170>/MinMax' incorporates:
   *  Constant: '<S170>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCACMaxPwrAllowHi_kW) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCACMaxPwrAllowHi_kW;
  }

  /* End of MinMax: '<S170>/MinMax' */

  /* MinMax: '<S170>/MinMax1' incorporates:
   *  Constant: '<S170>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUOBCACMaxPwrAllowLo_kW) {
    /* MinMax: '<S170>/MinMax1' */
    VIPM_IPUOBCACMaxPwrAllow_kW = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S170>/MinMax1' */
    VIPM_IPUOBCACMaxPwrAllow_kW = KIPM_IPUOBCACMaxPwrAllowLo_kW;
  }

  /* End of MinMax: '<S170>/MinMax1' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_IPUOBCACMaxPwrAllow_kW' */

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_IPUDeviceIntTemp_C' */
  /* Logic: '<S169>/Logical Operator3' incorporates:
   *  Constant: '<S169>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUDeviceIntTempVld_flg = (KIPM_IPUDeviceIntTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S169>/Switch4' incorporates:
   *  Constant: '<S169>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S169>/Switch'
   */
  if (KIPM_IPUDeviceIntTemp_C_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S169>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDeviceIntTemp_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S175>/Product' incorporates:
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S169>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_DeviceIntTemp;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S175>/Add'
     *  Switch: '<S169>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np - 40.0F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S169>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S169>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDeviceIntTempDflt_C;
  }

  /* End of Switch: '<S169>/Switch4' */

  /* MinMax: '<S169>/MinMax' incorporates:
   *  Constant: '<S169>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUDeviceIntTempHi_C) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUDeviceIntTempHi_C;
  }

  /* End of MinMax: '<S169>/MinMax' */

  /* MinMax: '<S169>/MinMax1' incorporates:
   *  Constant: '<S169>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C >= KIPM_IPUDeviceIntTempLo_C) {
    /* MinMax: '<S169>/MinMax1' */
    VIPM_IPUDeviceIntTemp_C = VIPM_IPUOBCTempInt_C;
  } else {
    /* MinMax: '<S169>/MinMax1' */
    VIPM_IPUDeviceIntTemp_C = KIPM_IPUDeviceIntTempLo_C;
  }

  /* End of MinMax: '<S169>/MinMax1' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_IPUDeviceIntTemp_C' */

  /* Outputs for Atomic SubSystem: '<S168>/Subsys_VIPM_IPUOBCTempInt_C' */
  /* Logic: '<S172>/Logical Operator3' incorporates:
   *  Constant: '<S172>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_IPUOBCTempIntVld_flg = (KIPM_IPUOBCTempInt_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_OBCMsgActv_flg);

  /* Switch: '<S172>/Switch4' incorporates:
   *  Constant: '<S172>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S172>/Switch'
   */
  if (KIPM_IPUOBCTempInt_C_ovrdflg) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S172>/sat4'
     *  MinMax: '<S172>/MinMax'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempInt_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
             ->VIPM_OBCMsgActv_flg) {
    /* Product: '<S176>/Product' incorporates:
     *  Inport: '<Root>/IPU_OBC_2_Inlet_EPT'
     *  Switch: '<S172>/Switch'
     */
    rtb_Add_np =
      (Rte_IRead_Runbl_IpmCanRx_100ms_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Inlet_EPT()
      )->IPU_OBC_TempInlet;

    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax'
     *  Sum: '<S176>/Add'
     *  Switch: '<S172>/Switch'
     */
    VIPM_IPUOBCTempInt_C = (float32)rtb_Add_np - 40.0F;
  } else {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  Constant: '<S172>/sat5'
     *  MinMax: '<S172>/MinMax'
     *  Switch: '<S172>/Switch'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempIntDflt_C;
  }

  /* End of Switch: '<S172>/Switch4' */

  /* MinMax: '<S172>/MinMax' incorporates:
   *  Constant: '<S172>/sat6'
   */
  if (VIPM_IPUOBCTempInt_C > KIPM_IPUOBCTempIntHi_C) {
    /* MinMax: '<S25>/MinMax' */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempIntHi_C;
  }

  /* End of MinMax: '<S172>/MinMax' */

  /* MinMax: '<S172>/MinMax1' incorporates:
   *  Constant: '<S172>/sat7'
   */
  if (VIPM_IPUOBCTempInt_C < KIPM_IPUOBCTempIntLo_C) {
    /* MinMax: '<S25>/MinMax' incorporates:
     *  MinMax: '<S172>/MinMax1'
     */
    VIPM_IPUOBCTempInt_C = KIPM_IPUOBCTempIntLo_C;
  }

  /* End of MinMax: '<S172>/MinMax1' */
  /* End of Outputs for SubSystem: '<S168>/Subsys_VIPM_IPUOBCTempInt_C' */

  /* BusCreator: '<S168>/BusCreator' incorporates:
   *  DataTypeConversion: '<S168>/Data Type Conversion'
   *  Logic: '<S169>/Logical Operator3'
   *  Logic: '<S170>/Logical Operator3'
   *  Logic: '<S171>/Logical Operator3'
   *  Logic: '<S172>/Logical Operator3'
   *  Logic: '<S173>/Logical Operator3'
   *  MinMax: '<S169>/MinMax1'
   *  MinMax: '<S170>/MinMax1'
   *  MinMax: '<S172>/MinMax1'
   *  Switch: '<S171>/Switch4'
   *  Switch: '<S173>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCWakeUpMode_enum =
    VIPM_IPUOBCWakeUpMode_enum;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCWakeUpModeVld_flg =
    VIPM_IPUOBCWakeUpModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCS2State_flg =
    VIPM_IPUOBCS2State_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCS2StateVld_flg =
    VIPM_IPUOBCS2StateVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCACMaxPwrAllow_kW =
    VIPM_IPUOBCACMaxPwrAllow_kW;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCACMaxPwrAllowVld_flg =
    VIPM_IPUOBCACMaxPwrAllowVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUDeviceIntTemp_C =
    VIPM_IPUDeviceIntTemp_C;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUDeviceIntTempVld_flg =
    VIPM_IPUDeviceIntTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCTempInt_C =
    VIPM_IPUOBCTempInt_C;
  AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c.VIPM_IPUOBCTempIntVld_flg =
    VIPM_IPUOBCTempIntVld_flg;

  /* Outputs for Atomic SubSystem: '<S177>/Subsys_VIPM_BMSPackID_enum' */
  /* Logic: '<S179>/Logical Operator3' incorporates:
   *  Constant: '<S179>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSPackIDVld_flg = (KIPM_BMSPackID_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_BMSMsgActv_flg);

  /* Switch: '<S179>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S179>/Switch' incorporates:
     *  Inport: '<Root>/BMS_9_BattInfo_EPT'
     *  Switch: '<S179>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jhg =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT())
      ->BMS_Pack_Identity;
  } else {
    /* Switch: '<S179>/Switch' incorporates:
     *  Constant: '<S179>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jhg = KIPM_BMSPackIDDflt_enum;
  }

  /* End of Switch: '<S179>/Switch' */

  /* Switch: '<S179>/Switch4' incorporates:
   *  Constant: '<S179>/sat3'
   */
  if (KIPM_BMSPackID_enum_ovrdflg) {
    /* Switch: '<S179>/Switch4' incorporates:
     *  Constant: '<S179>/sat4'
     */
    VIPM_BMSPackID_enum = KIPM_BMSPackID_enum_ovrdval;
  } else {
    /* Switch: '<S179>/Switch4' */
    VIPM_BMSPackID_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jhg;
  }

  /* End of Switch: '<S179>/Switch4' */
  /* End of Outputs for SubSystem: '<S177>/Subsys_VIPM_BMSPackID_enum' */

  /* Outputs for Atomic SubSystem: '<S177>/Subsys_VIPM_BMSBatCapcty_Ah' */
  /* Logic: '<S178>/Logical Operator3' incorporates:
   *  Constant: '<S178>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatCapctyVld_flg = (KIPM_BMSBatCapcty_Ah_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
    ->VIPM_BMSMsgActv_flg);

  /* Switch: '<S178>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_100ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S178>/Switch' incorporates:
     *  Inport: '<Root>/BMS_9_BattInfo_EPT'
     *  Switch: '<S178>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ol =
      (Rte_IRead_Runbl_IpmCanRx_100ms_BMS_9_BattInfo_EPT_BMS_9_BattInfo_EPT())
      ->BMS_BatCapacity;
  } else {
    /* Switch: '<S178>/Switch' incorporates:
     *  Constant: '<S178>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ol = KIPM_BMSBatCapctyDflt_Ah;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Switch: '<S178>/Switch4' incorporates:
   *  Constant: '<S178>/sat3'
   */
  if (KIPM_BMSBatCapcty_Ah_ovrdflg) {
    /* Switch: '<S178>/Switch4' incorporates:
     *  Constant: '<S178>/sat4'
     */
    VIPM_BMSBatCapcty_Ah = KIPM_BMSBatCapcty_Ah_ovrdval;
  } else {
    /* Switch: '<S178>/Switch4' */
    VIPM_BMSBatCapcty_Ah = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ol;
  }

  /* End of Switch: '<S178>/Switch4' */
  /* End of Outputs for SubSystem: '<S177>/Subsys_VIPM_BMSBatCapcty_Ah' */

  /* BusCreator: '<S177>/BusCreator' incorporates:
   *  Logic: '<S178>/Logical Operator3'
   *  Logic: '<S179>/Logical Operator3'
   *  Switch: '<S178>/Switch4'
   *  Switch: '<S179>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT_a.VIPM_BMSPackID_enum =
    VIPM_BMSPackID_enum;
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT_a.VIPM_BMSPackIDVld_flg =
    VIPM_BMSPackIDVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT_a.VIPM_BMSBatCapcty_Ah =
    VIPM_BMSBatCapcty_Ah;
  AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT_a.VIPM_BMSBatCapctyVld_flg =
    VIPM_BMSBatCapctyVld_flg;
}

/* Output and update for function-call system: '<Root>/Ipm10ms' */
static void Runbl_Ipm10ms(void)
{
  sint32 rtb_Product_bh;
  float32 rtb_Product_eh;
  boolean rtb_LogicalOperator2_mn;

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBEPBDynAppSt_enum' */
  /* Logic: '<S191>/Logical Operator3' incorporates:
   *  Constant: '<S191>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBDynAppStVld_flg = (KIPM_EHBEPBDynAppSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S191>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S191>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S191>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S191>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_EPB_DynamicApplySta;
    }

    /* End of Switch: '<S191>/Switch3' */
  } else {
    /* Switch: '<S191>/Switch' incorporates:
     *  Constant: '<S191>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i = KIPM_EHBEPBDynAppStDflt_enum;
  }

  /* End of Switch: '<S191>/Switch' */

  /* Switch: '<S191>/Switch4' incorporates:
   *  Constant: '<S191>/sat3'
   */
  if (KIPM_EHBEPBDynAppSt_enum_ovrdflg) {
    /* Switch: '<S191>/Switch4' incorporates:
     *  Constant: '<S191>/sat4'
     */
    VIPM_EHBEPBDynAppSt_enum = KIPM_EHBEPBDynAppSt_enum_ovrdval;
  } else {
    /* Switch: '<S191>/Switch4' */
    VIPM_EHBEPBDynAppSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i;
  }

  /* End of Switch: '<S191>/Switch4' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBEPBDynAppSt_enum' */

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBBrkPedlValPerc_pct' */
  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/EHB_B_CHA'
   *  Logic: '<S186>/Logical Operator2'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
    ->EHB_BrkPedlValPercVld &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Logic: '<S186>/Logical Operator3' incorporates:
   *  Constant: '<S186>/sat3'
   */
  VIPM_EHBBrkPedlValPercVld_flg = (KIPM_EHBBrkPedlValPerc_pct_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S186>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S186>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S186>/Switch' incorporates:
       *  DataTypeConversion: '<S186>/Data Type Conversion2'
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S186>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_BrkPedlValPerc;
    }

    /* End of Switch: '<S186>/Switch3' */
  } else {
    /* Switch: '<S186>/Switch' incorporates:
     *  Constant: '<S186>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg = KIPM_EHBBrkPedlValPercDflt_pct;
  }

  /* End of Switch: '<S186>/Switch' */

  /* Switch: '<S186>/Switch4' incorporates:
   *  Constant: '<S186>/sat3'
   *  Constant: '<S186>/sat4'
   */
  if (KIPM_EHBBrkPedlValPerc_pct_ovrdflg) {
    VIPM_EHBBrkPedlValPerc_pct = KIPM_EHBBrkPedlValPerc_pct_ovrdval;
  } else {
    VIPM_EHBBrkPedlValPerc_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg;
  }

  /* MinMax: '<S186>/MinMax' incorporates:
   *  Constant: '<S186>/sat6'
   *  Switch: '<S186>/Switch4'
   */
  if (VIPM_EHBBrkPedlValPerc_pct > KIPM_EHBBrkPedlValPercHi_pct) {
    VIPM_EHBBrkPedlValPerc_pct = KIPM_EHBBrkPedlValPercHi_pct;
  }

  /* End of MinMax: '<S186>/MinMax' */

  /* MinMax: '<S186>/MinMax1' incorporates:
   *  Constant: '<S186>/sat7'
   */
  if (VIPM_EHBBrkPedlValPerc_pct < KIPM_EHBBrkPedlValPercLo_pct) {
    /* Switch: '<S186>/Switch4' incorporates:
     *  MinMax: '<S186>/MinMax1'
     */
    VIPM_EHBBrkPedlValPerc_pct = KIPM_EHBBrkPedlValPercLo_pct;
  }

  /* End of MinMax: '<S186>/MinMax1' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBBrkPedlValPerc_pct' */

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBFltLvl_enum' */
  /* Logic: '<S192>/Logical Operator3' incorporates:
   *  Constant: '<S192>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBFltLvlVld_flg = (KIPM_EHBFltLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S192>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S192>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S192>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S192>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_da =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())->EHB_FaultLevel;
    }

    /* End of Switch: '<S192>/Switch3' */
  } else {
    /* Switch: '<S192>/Switch' incorporates:
     *  Constant: '<S192>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_da = KIPM_EHBFltLvlDflt_enum;
  }

  /* End of Switch: '<S192>/Switch' */

  /* Switch: '<S192>/Switch4' incorporates:
   *  Constant: '<S192>/sat3'
   */
  if (KIPM_EHBFltLvl_enum_ovrdflg) {
    /* Switch: '<S192>/Switch4' incorporates:
     *  Constant: '<S192>/sat4'
     */
    VIPM_EHBFltLvl_enum = KIPM_EHBFltLvl_enum_ovrdval;
  } else {
    /* Switch: '<S192>/Switch4' */
    VIPM_EHBFltLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_da;
  }

  /* End of Switch: '<S192>/Switch4' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBFltLvl_enum' */

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBReqBrkLiOn_flg' */
  /* Logic: '<S193>/Logical Operator3' incorporates:
   *  Constant: '<S193>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBReqBrkLiOnVld_flg = (KIPM_EHBReqBrkLiOn_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S193>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S193>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S193>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S193>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pk =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())->EHB_ReqBrkLiOn;
    }

    /* End of Switch: '<S193>/Switch3' */
  } else {
    /* Switch: '<S193>/Switch' incorporates:
     *  Constant: '<S193>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pk = KIPM_EHBReqBrkLiOnDflt_flg;
  }

  /* End of Switch: '<S193>/Switch' */

  /* Switch: '<S193>/Switch4' incorporates:
   *  Constant: '<S193>/sat3'
   */
  if (KIPM_EHBReqBrkLiOn_flg_ovrdflg) {
    /* Switch: '<S193>/Switch4' incorporates:
     *  Constant: '<S193>/sat4'
     */
    VIPM_EHBReqBrkLiOn_flg = KIPM_EHBReqBrkLiOn_flg_ovrdval;
  } else {
    /* Switch: '<S193>/Switch4' */
    VIPM_EHBReqBrkLiOn_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pk;
  }

  /* End of Switch: '<S193>/Switch4' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBReqBrkLiOn_flg' */

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm' */
  /* Logic: '<S188>/Logical Operator3' incorporates:
   *  Constant: '<S188>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBBrkPwrRecupTarWhlTqVld_flg = (KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S188>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S188>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Product: '<S194>/Product' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       */
      rtb_Product_bh = (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_BrkPwrRecupTarWhlTq;

      /* Switch: '<S188>/Switch' incorporates:
       *  Sum: '<S194>/Add'
       *  Switch: '<S188>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eu = (float32)rtb_Product_bh -
        32768.0F;
    }

    /* End of Switch: '<S188>/Switch3' */
  } else {
    /* Switch: '<S188>/Switch' incorporates:
     *  Constant: '<S188>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eu = KIPM_EHBBrkPwrRecupTarWhlTqDflt_Nm;
  }

  /* End of Switch: '<S188>/Switch' */

  /* Switch: '<S188>/Switch4' incorporates:
   *  Constant: '<S188>/sat3'
   *  Constant: '<S188>/sat4'
   */
  if (KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdflg) {
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdval;
  } else {
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eu;
  }

  /* MinMax: '<S188>/MinMax' incorporates:
   *  Constant: '<S188>/sat6'
   *  Switch: '<S188>/Switch4'
   */
  if (VIPM_EHBBrkPwrRecupTarWhlTq_Nm > KIPM_EHBBrkPwrRecupTarWhlTqHi_Nm) {
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = KIPM_EHBBrkPwrRecupTarWhlTqHi_Nm;
  }

  /* End of MinMax: '<S188>/MinMax' */

  /* MinMax: '<S188>/MinMax1' incorporates:
   *  Constant: '<S188>/sat7'
   */
  if (VIPM_EHBBrkPwrRecupTarWhlTq_Nm < KIPM_EHBBrkPwrRecupTarWhlTqLo_Nm) {
    /* Switch: '<S188>/Switch4' incorporates:
     *  MinMax: '<S188>/MinMax1'
     */
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm = KIPM_EHBBrkPwrRecupTarWhlTqLo_Nm;
  }

  /* End of MinMax: '<S188>/MinMax1' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTq_Nm' */

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum' */
  /* Logic: '<S187>/Logical Operator3' incorporates:
   *  Constant: '<S187>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg =
    (KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdflg ||
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_EHBMsgActv_flg);

  /* Switch: '<S187>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S187>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S187>/Switch' incorporates:
       *  DataTypeConversion: '<S187>/Data Type Conversion2'
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S187>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n0 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_BrkPwrRecupTarWhlTqSts;
    }

    /* End of Switch: '<S187>/Switch3' */
  } else {
    /* Switch: '<S187>/Switch' incorporates:
     *  Constant: '<S187>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n0 =
      KIPM_EHBBrkPwrRecupTarWhlTqStsDflt_enum;
  }

  /* End of Switch: '<S187>/Switch' */

  /* Switch: '<S187>/Switch4' incorporates:
   *  Constant: '<S187>/sat3'
   */
  if (KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdflg) {
    /* Switch: '<S187>/Switch4' incorporates:
     *  Constant: '<S187>/sat4'
     */
    VIPM_EHBBrkPwrRecupTarWhlTqSts_enum =
      KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdval;
  } else {
    /* Switch: '<S187>/Switch4' incorporates:
     *  Switch: '<S187>/Switch'
     */
    VIPM_EHBBrkPwrRecupTarWhlTqSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n0;
  }

  /* End of Switch: '<S187>/Switch4' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBBrkPwrRecupTarWhlTqSts_enum' */

  /* DataTypeConversion: '<S182>/Data Type Conversion1' incorporates:
   *  Switch: '<S187>/Switch4'
   */
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPwrRecupTarWhlTqSts_enum =
    VIPM_EHBBrkPwrRecupTarWhlTqSts_enum;

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBEPBActuatorStR_enum' */
  /* Logic: '<S190>/Logical Operator3' incorporates:
   *  Constant: '<S190>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBActuatorStRVld_flg = (KIPM_EHBEPBActuatorStR_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S190>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S190>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S190>/Switch' incorporates:
       *  DataTypeConversion: '<S190>/Data Type Conversion2'
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S190>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cj =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())
        ->EHB_EPB_ActuatorSt_R;
    }

    /* End of Switch: '<S190>/Switch3' */
  } else {
    /* Switch: '<S190>/Switch' incorporates:
     *  Constant: '<S190>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cj = KIPM_EHBEPBActuatorStRDflt_enum;
  }

  /* End of Switch: '<S190>/Switch' */

  /* Switch: '<S190>/Switch4' incorporates:
   *  Constant: '<S190>/sat3'
   */
  if (KIPM_EHBEPBActuatorStR_enum_ovrdflg) {
    /* Switch: '<S190>/Switch4' incorporates:
     *  Constant: '<S190>/sat4'
     */
    VIPM_EHBEPBActuatorStR_enum = KIPM_EHBEPBActuatorStR_enum_ovrdval;
  } else {
    /* Switch: '<S190>/Switch4' incorporates:
     *  Switch: '<S190>/Switch'
     */
    VIPM_EHBEPBActuatorStR_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cj;
  }

  /* End of Switch: '<S190>/Switch4' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBEPBActuatorStR_enum' */

  /* Outputs for Atomic SubSystem: '<S182>/Subsys_VIPM_EHBCDDActv_flg' */
  /* Logic: '<S189>/Logical Operator3' incorporates:
   *  Constant: '<S189>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBCDDActvVld_flg = (KIPM_EHBCDDActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S189>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S189>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EHB_B_CRCFlt_flg) {
      /* Switch: '<S189>/Switch' incorporates:
       *  Inport: '<Root>/EHB_B_CHA'
       *  Switch: '<S189>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cn =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EHB_B_CHA_EHB_B_CHA())->EHB_CDDActive;
    }

    /* End of Switch: '<S189>/Switch3' */
  } else {
    /* Switch: '<S189>/Switch' incorporates:
     *  Constant: '<S189>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cn = KIPM_EHBCDDActvDflt_flg;
  }

  /* End of Switch: '<S189>/Switch' */

  /* Switch: '<S189>/Switch4' incorporates:
   *  Constant: '<S189>/sat3'
   */
  if (KIPM_EHBCDDActv_flg_ovrdflg) {
    /* Switch: '<S189>/Switch4' incorporates:
     *  Constant: '<S189>/sat4'
     */
    VIPM_EHBCDDActv_flg = KIPM_EHBCDDActv_flg_ovrdval;
  } else {
    /* Switch: '<S189>/Switch4' */
    VIPM_EHBCDDActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cn;
  }

  /* End of Switch: '<S189>/Switch4' */
  /* End of Outputs for SubSystem: '<S182>/Subsys_VIPM_EHBCDDActv_flg' */

  /* BusCreator: '<S182>/BusCreator' incorporates:
   *  DataTypeConversion: '<S182>/Data Type Conversion'
   *  Logic: '<S186>/Logical Operator3'
   *  Logic: '<S187>/Logical Operator3'
   *  Logic: '<S188>/Logical Operator3'
   *  Logic: '<S189>/Logical Operator3'
   *  Logic: '<S190>/Logical Operator3'
   *  Logic: '<S191>/Logical Operator3'
   *  Logic: '<S192>/Logical Operator3'
   *  Logic: '<S193>/Logical Operator3'
   *  MinMax: '<S186>/MinMax1'
   *  MinMax: '<S188>/MinMax1'
   *  Switch: '<S189>/Switch4'
   *  Switch: '<S190>/Switch4'
   *  Switch: '<S191>/Switch4'
   *  Switch: '<S192>/Switch4'
   *  Switch: '<S193>/Switch4'
   */
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBEPBDynAppSt_enum =
    VIPM_EHBEPBDynAppSt_enum;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBEPBDynAppStVld_flg =
    VIPM_EHBEPBDynAppStVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPedlValPerc_pct =
    VIPM_EHBBrkPedlValPerc_pct;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPedlValPercVld_flg =
    VIPM_EHBBrkPedlValPercVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBFltLvl_enum = VIPM_EHBFltLvl_enum;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBFltLvlVld_flg = VIPM_EHBFltLvlVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBReqBrkLiOn_flg = VIPM_EHBReqBrkLiOn_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBReqBrkLiOnVld_flg =
    VIPM_EHBReqBrkLiOnVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPwrRecupTarWhlTq_Nm =
    VIPM_EHBBrkPwrRecupTarWhlTq_Nm;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPwrRecupTarWhlTqVld_flg =
    VIPM_EHBBrkPwrRecupTarWhlTqVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg =
    VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBEPBActuatorStR_enum =
    VIPM_EHBEPBActuatorStR_enum;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBEPBActuatorStRVld_flg =
    VIPM_EHBEPBActuatorStRVld_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBCDDActv_flg = VIPM_EHBCDDActv_flg;
  AppSwcIpm_ARID_DEF.EHB_B_CHA_l.VIPM_EHBCDDActvVld_flg = VIPM_EHBCDDActvVld_flg;

  /* Outputs for Atomic SubSystem: '<S183>/Subsys_VIPM_EPSSteerWhlAng_deg' */
  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
   *  Logic: '<S198>/Logical Operator2'
   */
  rtb_LogicalOperator2_mn =
    ((Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
     ->EPS_SteerWheelAngleValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_EPSMsgActv_flg);

  /* Logic: '<S198>/Logical Operator3' incorporates:
   *  Constant: '<S198>/sat3'
   */
  VIPM_EPSSteerWhlAngVld_flg = (KIPM_EPSSteerWhlAng_deg_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S198>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S198>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Product: '<S199>/Product' incorporates:
       *  Constant: '<S199>/Constant'
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       */
      rtb_Product_eh = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_SteerWheelAngle * 0.1F;

      /* Switch: '<S198>/Switch' incorporates:
       *  Sum: '<S199>/Add'
       *  Switch: '<S198>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a = rtb_Product_eh - 780.0F;
    }

    /* End of Switch: '<S198>/Switch3' */
  } else {
    /* Switch: '<S198>/Switch' incorporates:
     *  Constant: '<S198>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a = KIPM_EPSSteerWhlAngDflt_deg;
  }

  /* End of Switch: '<S198>/Switch' */

  /* Switch: '<S198>/Switch4' incorporates:
   *  Constant: '<S198>/sat3'
   *  Constant: '<S198>/sat4'
   */
  if (KIPM_EPSSteerWhlAng_deg_ovrdflg) {
    VIPM_EPSSteerWhlAng_deg = KIPM_EPSSteerWhlAng_deg_ovrdval;
  } else {
    VIPM_EPSSteerWhlAng_deg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a;
  }

  /* MinMax: '<S198>/MinMax' incorporates:
   *  Constant: '<S198>/sat6'
   *  Switch: '<S198>/Switch4'
   */
  if (VIPM_EPSSteerWhlAng_deg > KIPM_EPSSteerWhlAngHi_deg) {
    VIPM_EPSSteerWhlAng_deg = KIPM_EPSSteerWhlAngHi_deg;
  }

  /* End of MinMax: '<S198>/MinMax' */

  /* MinMax: '<S198>/MinMax1' incorporates:
   *  Constant: '<S198>/sat7'
   */
  if (VIPM_EPSSteerWhlAng_deg < KIPM_EPSSteerWhlAngLo_deg) {
    /* Switch: '<S198>/Switch4' incorporates:
     *  MinMax: '<S198>/MinMax1'
     */
    VIPM_EPSSteerWhlAng_deg = KIPM_EPSSteerWhlAngLo_deg;
  }

  /* End of MinMax: '<S198>/MinMax1' */
  /* End of Outputs for SubSystem: '<S183>/Subsys_VIPM_EPSSteerWhlAng_deg' */

  /* Outputs for Atomic SubSystem: '<S183>/Subsys_VIPM_EPSRotSpd_degps' */
  /* Logic: '<S195>/Logical Operator3' incorporates:
   *  Constant: '<S195>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EPSRotSpdVld_flg = (KIPM_EPSRotSpd_degps_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EPSMsgActv_flg);

  /* Switch: '<S195>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EPSMsgActv_flg) {
    /* Switch: '<S195>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Product: '<S200>/Product' incorporates:
       *  Constant: '<S200>/Constant'
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       */
      rtb_Product_eh = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_RotSpeed * 0.1F;

      /* Switch: '<S195>/Switch' incorporates:
       *  Sum: '<S200>/Add'
       *  Switch: '<S195>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_au = rtb_Product_eh - 1024.0F;
    }

    /* End of Switch: '<S195>/Switch3' */
  } else {
    /* Switch: '<S195>/Switch' incorporates:
     *  Constant: '<S195>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_au = KIPM_EPSRotSpdDflt_degps;
  }

  /* End of Switch: '<S195>/Switch' */

  /* Switch: '<S195>/Switch4' incorporates:
   *  Constant: '<S195>/sat3'
   *  Constant: '<S195>/sat4'
   */
  if (KIPM_EPSRotSpd_degps_ovrdflg) {
    VIPM_EPSRotSpd_degps = KIPM_EPSRotSpd_degps_ovrdval;
  } else {
    VIPM_EPSRotSpd_degps = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_au;
  }

  /* MinMax: '<S195>/MinMax' incorporates:
   *  Constant: '<S195>/sat6'
   *  Switch: '<S195>/Switch4'
   */
  if (VIPM_EPSRotSpd_degps > KIPM_EPSRotSpdHi_degps) {
    VIPM_EPSRotSpd_degps = KIPM_EPSRotSpdHi_degps;
  }

  /* End of MinMax: '<S195>/MinMax' */

  /* MinMax: '<S195>/MinMax1' incorporates:
   *  Constant: '<S195>/sat7'
   */
  if (VIPM_EPSRotSpd_degps < KIPM_EPSRotSpdLo_degps) {
    /* Switch: '<S195>/Switch4' incorporates:
     *  MinMax: '<S195>/MinMax1'
     */
    VIPM_EPSRotSpd_degps = KIPM_EPSRotSpdLo_degps;
  }

  /* End of MinMax: '<S195>/MinMax1' */
  /* End of Outputs for SubSystem: '<S183>/Subsys_VIPM_EPSRotSpd_degps' */

  /* Outputs for Atomic SubSystem: '<S183>/Subsys_VIPM_EPSSteerWhlAngCald_flg' */
  /* Logic: '<S196>/Logical Operator3' incorporates:
   *  Constant: '<S196>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EPSSteerWhlAngCaldVld_flg = (KIPM_EPSSteerWhlAngCald_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EPSMsgActv_flg);

  /* Switch: '<S196>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EPSMsgActv_flg) {
    /* Switch: '<S196>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Switch: '<S196>/Switch' incorporates:
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       *  Switch: '<S196>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ls =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_SteerWheelAngleCalibrated;
    }

    /* End of Switch: '<S196>/Switch3' */
  } else {
    /* Switch: '<S196>/Switch' incorporates:
     *  Constant: '<S196>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ls = KIPM_EPSSteerWhlAngCaldDflt_flg;
  }

  /* End of Switch: '<S196>/Switch' */

  /* Switch: '<S196>/Switch4' incorporates:
   *  Constant: '<S196>/sat3'
   */
  if (KIPM_EPSSteerWhlAngCald_flg_ovrdflg) {
    /* Switch: '<S196>/Switch4' incorporates:
     *  Constant: '<S196>/sat4'
     */
    VIPM_EPSSteerWhlAngCald_flg = KIPM_EPSSteerWhlAngCald_flg_ovrdval;
  } else {
    /* Switch: '<S196>/Switch4' */
    VIPM_EPSSteerWhlAngCald_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ls;
  }

  /* End of Switch: '<S196>/Switch4' */
  /* End of Outputs for SubSystem: '<S183>/Subsys_VIPM_EPSSteerWhlAngCald_flg' */

  /* Outputs for Atomic SubSystem: '<S183>/Subsys_VIPM_EPSSteerWhlAngFailr_flg' */
  /* Logic: '<S197>/Logical Operator3' incorporates:
   *  Constant: '<S197>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EPSSteerWhlAngFailrVld_flg = (KIPM_EPSSteerWhlAngFailr_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_EPSMsgActv_flg);

  /* Switch: '<S197>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_EPSMsgActv_flg) {
    /* Switch: '<S197>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_EPS_2_StrWhlAng_CRCFlt_flg) {
      /* Switch: '<S197>/Switch' incorporates:
       *  Inport: '<Root>/EPS_2_StrWhlAng_CHA'
       *  Switch: '<S197>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dj =
        (Rte_IRead_Runbl_IpmCanRx_10ms_EPS_2_StrWhlAng_CHA_EPS_2_StrWhlAng_CHA())
        ->EPS_SteerWheelAngleFailure;
    }

    /* End of Switch: '<S197>/Switch3' */
  } else {
    /* Switch: '<S197>/Switch' incorporates:
     *  Constant: '<S197>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dj = KIPM_EPSSteerWhlAngFailrDflt_flg;
  }

  /* End of Switch: '<S197>/Switch' */

  /* Switch: '<S197>/Switch4' incorporates:
   *  Constant: '<S197>/sat3'
   */
  if (KIPM_EPSSteerWhlAngFailr_flg_ovrdflg) {
    /* Switch: '<S197>/Switch4' incorporates:
     *  Constant: '<S197>/sat4'
     */
    VIPM_EPSSteerWhlAngFailr_flg = KIPM_EPSSteerWhlAngFailr_flg_ovrdval;
  } else {
    /* Switch: '<S197>/Switch4' */
    VIPM_EPSSteerWhlAngFailr_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dj;
  }

  /* End of Switch: '<S197>/Switch4' */
  /* End of Outputs for SubSystem: '<S183>/Subsys_VIPM_EPSSteerWhlAngFailr_flg' */

  /* BusCreator: '<S183>/BusCreator' incorporates:
   *  Logic: '<S195>/Logical Operator3'
   *  Logic: '<S196>/Logical Operator3'
   *  Logic: '<S197>/Logical Operator3'
   *  Logic: '<S198>/Logical Operator3'
   *  MinMax: '<S195>/MinMax1'
   *  MinMax: '<S198>/MinMax1'
   *  Switch: '<S196>/Switch4'
   *  Switch: '<S197>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSSteerWhlAng_deg =
    VIPM_EPSSteerWhlAng_deg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSSteerWhlAngVld_flg =
    VIPM_EPSSteerWhlAngVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSRotSpd_degps =
    VIPM_EPSRotSpd_degps;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSRotSpdVld_flg =
    VIPM_EPSRotSpdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSSteerWhlAngCald_flg =
    VIPM_EPSSteerWhlAngCald_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSSteerWhlAngCaldVld_flg =
    VIPM_EPSSteerWhlAngCaldVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSSteerWhlAngFailr_flg =
    VIPM_EPSSteerWhlAngFailr_flg;
  AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g.VIPM_EPSSteerWhlAngFailrVld_flg =
    VIPM_EPSSteerWhlAngFailrVld_flg;

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCABSActvSta_flg' */
  /* Logic: '<S201>/Logical Operator3' incorporates:
   *  Constant: '<S201>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCABSActvStaVld_flg = (KIPM_ESCABSActvSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S201>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S201>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S201>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S201>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a50 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ABSActiveSta;
    }

    /* End of Switch: '<S201>/Switch3' */
  } else {
    /* Switch: '<S201>/Switch' incorporates:
     *  Constant: '<S201>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a50 = KIPM_ESCABSActvStaDflt_flg;
  }

  /* End of Switch: '<S201>/Switch' */

  /* Switch: '<S201>/Switch4' incorporates:
   *  Constant: '<S201>/sat3'
   */
  if (KIPM_ESCABSActvSta_flg_ovrdflg) {
    /* Switch: '<S201>/Switch4' incorporates:
     *  Constant: '<S201>/sat4'
     */
    VIPM_ESCABSActvSta_flg = KIPM_ESCABSActvSta_flg_ovrdval;
  } else {
    /* Switch: '<S201>/Switch4' */
    VIPM_ESCABSActvSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a50;
  }

  /* End of Switch: '<S201>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCABSActvSta_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCVehSpd_kph' */
  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
   *  Logic: '<S210>/Logical Operator2'
   */
  rtb_LogicalOperator2_mn =
    ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA()
     )->ESC_VehicleSpeedV &&
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_ESCMsgActv_flg);

  /* Logic: '<S210>/Logical Operator3' incorporates:
   *  Constant: '<S210>/sat3'
   */
  VIPM_ESCVehSpdVld_flg = (KIPM_ESCVehSpd_kph_ovrdflg || rtb_LogicalOperator2_mn);

  /* Switch: '<S210>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S210>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S210>/Switch' incorporates:
       *  Constant: '<S211>/Constant'
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Product: '<S211>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dc = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_VehicleSpeed * 0.05625F;
    }

    /* End of Switch: '<S210>/Switch3' */
  } else {
    /* Switch: '<S210>/Switch' incorporates:
     *  Constant: '<S210>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dc = KIPM_ESCVehSpdDflt_kph;
  }

  /* End of Switch: '<S210>/Switch' */

  /* Switch: '<S210>/Switch4' incorporates:
   *  Constant: '<S210>/sat3'
   *  Constant: '<S210>/sat4'
   */
  if (KIPM_ESCVehSpd_kph_ovrdflg) {
    VIPM_ESCVehSpd_kph = KIPM_ESCVehSpd_kph_ovrdval;
  } else {
    VIPM_ESCVehSpd_kph = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dc;
  }

  /* MinMax: '<S210>/MinMax' incorporates:
   *  Constant: '<S210>/sat6'
   *  Switch: '<S210>/Switch4'
   */
  if (VIPM_ESCVehSpd_kph > KIPM_ESCVehSpdHi_kph) {
    VIPM_ESCVehSpd_kph = KIPM_ESCVehSpdHi_kph;
  }

  /* End of MinMax: '<S210>/MinMax' */

  /* MinMax: '<S210>/MinMax1' incorporates:
   *  Constant: '<S210>/sat7'
   */
  if (VIPM_ESCVehSpd_kph < KIPM_ESCVehSpdLo_kph) {
    /* Switch: '<S210>/Switch4' incorporates:
     *  MinMax: '<S210>/MinMax1'
     */
    VIPM_ESCVehSpd_kph = KIPM_ESCVehSpdLo_kph;
  }

  /* End of MinMax: '<S210>/MinMax1' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCVehSpd_kph' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCTCSActvSta_flg' */
  /* Logic: '<S209>/Logical Operator3' incorporates:
   *  Constant: '<S209>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCTCSActvStaVld_flg = (KIPM_ESCTCSActvSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S209>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S209>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S209>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S209>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b3 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_TCSActiveSta;
    }

    /* End of Switch: '<S209>/Switch3' */
  } else {
    /* Switch: '<S209>/Switch' incorporates:
     *  Constant: '<S209>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b3 = KIPM_ESCTCSActvStaDflt_flg;
  }

  /* End of Switch: '<S209>/Switch' */

  /* Switch: '<S209>/Switch4' incorporates:
   *  Constant: '<S209>/sat3'
   */
  if (KIPM_ESCTCSActvSta_flg_ovrdflg) {
    /* Switch: '<S209>/Switch4' incorporates:
     *  Constant: '<S209>/sat4'
     */
    VIPM_ESCTCSActvSta_flg = KIPM_ESCTCSActvSta_flg_ovrdval;
  } else {
    /* Switch: '<S209>/Switch4' */
    VIPM_ESCTCSActvSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b3;
  }

  /* End of Switch: '<S209>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCTCSActvSta_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCESPActvSta_flg' */
  /* Logic: '<S204>/Logical Operator3' incorporates:
   *  Constant: '<S204>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCESPActvStaVld_flg = (KIPM_ESCESPActvSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S204>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S204>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S204>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S204>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ESPActiveSta;
    }

    /* End of Switch: '<S204>/Switch3' */
  } else {
    /* Switch: '<S204>/Switch' incorporates:
     *  Constant: '<S204>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2 = KIPM_ESCESPActvStaDflt_flg;
  }

  /* End of Switch: '<S204>/Switch' */

  /* Switch: '<S204>/Switch4' incorporates:
   *  Constant: '<S204>/sat3'
   */
  if (KIPM_ESCESPActvSta_flg_ovrdflg) {
    /* Switch: '<S204>/Switch4' incorporates:
     *  Constant: '<S204>/sat4'
     */
    VIPM_ESCESPActvSta_flg = KIPM_ESCESPActvSta_flg_ovrdval;
  } else {
    /* Switch: '<S204>/Switch4' */
    VIPM_ESCESPActvSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_a2;
  }

  /* End of Switch: '<S204>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCESPActvSta_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCReqBrkLghtOn_flg' */
  /* Logic: '<S207>/Logical Operator3' incorporates:
   *  Constant: '<S207>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCReqBrkLghtOnVld_flg = (KIPM_ESCReqBrkLghtOn_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S207>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S207>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S207>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S207>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g2 =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ReqBrakeLightOn;
    }

    /* End of Switch: '<S207>/Switch3' */
  } else {
    /* Switch: '<S207>/Switch' incorporates:
     *  Constant: '<S207>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g2 = KIPM_ESCReqBrkLghtOnDflt_flg;
  }

  /* End of Switch: '<S207>/Switch' */

  /* Switch: '<S207>/Switch4' incorporates:
   *  Constant: '<S207>/sat3'
   */
  if (KIPM_ESCReqBrkLghtOn_flg_ovrdflg) {
    /* Switch: '<S207>/Switch4' incorporates:
     *  Constant: '<S207>/sat4'
     */
    VIPM_ESCReqBrkLghtOn_flg = KIPM_ESCReqBrkLghtOn_flg_ovrdval;
  } else {
    /* Switch: '<S207>/Switch4' */
    VIPM_ESCReqBrkLghtOn_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g2;
  }

  /* End of Switch: '<S207>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCReqBrkLghtOn_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCCDPActv_flg' */
  /* Logic: '<S202>/Logical Operator3' incorporates:
   *  Constant: '<S202>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCCDPActvVld_flg = (KIPM_ESCCDPActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S202>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S202>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S202>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S202>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fx =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_CDPActive;
    }

    /* End of Switch: '<S202>/Switch3' */
  } else {
    /* Switch: '<S202>/Switch' incorporates:
     *  Constant: '<S202>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fx = KIPM_ESCCDPActvDflt_flg;
  }

  /* End of Switch: '<S202>/Switch' */

  /* Switch: '<S202>/Switch4' incorporates:
   *  Constant: '<S202>/sat3'
   */
  if (KIPM_ESCCDPActv_flg_ovrdflg) {
    /* Switch: '<S202>/Switch4' incorporates:
     *  Constant: '<S202>/sat4'
     */
    VIPM_ESCCDPActv_flg = KIPM_ESCCDPActv_flg_ovrdval;
  } else {
    /* Switch: '<S202>/Switch4' */
    VIPM_ESCCDPActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fx;
  }

  /* End of Switch: '<S202>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCCDPActv_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCESSActv_flg' */
  /* Logic: '<S205>/Logical Operator3' incorporates:
   *  Constant: '<S205>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCESSActvVld_flg = (KIPM_ESCESSActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S205>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S205>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S205>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S205>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ieu =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_ESSActive;
    }

    /* End of Switch: '<S205>/Switch3' */
  } else {
    /* Switch: '<S205>/Switch' incorporates:
     *  Constant: '<S205>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ieu = KIPM_ESCESSActvDflt_flg;
  }

  /* End of Switch: '<S205>/Switch' */

  /* Switch: '<S205>/Switch4' incorporates:
   *  Constant: '<S205>/sat3'
   */
  if (KIPM_ESCESSActv_flg_ovrdflg) {
    /* Switch: '<S205>/Switch4' incorporates:
     *  Constant: '<S205>/sat4'
     */
    VIPM_ESCESSActv_flg = KIPM_ESCESSActv_flg_ovrdval;
  } else {
    /* Switch: '<S205>/Switch4' */
    VIPM_ESCESSActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ieu;
  }

  /* End of Switch: '<S205>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCESSActv_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCEBDActv_flg' */
  /* Logic: '<S203>/Logical Operator3' incorporates:
   *  Constant: '<S203>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCEBDActvVld_flg = (KIPM_ESCEBDActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S203>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S203>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S203>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S203>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lx =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_EBDActiveSta;
    }

    /* End of Switch: '<S203>/Switch3' */
  } else {
    /* Switch: '<S203>/Switch' incorporates:
     *  Constant: '<S203>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lx = KIPM_ESCEBDActvDflt_flg;
  }

  /* End of Switch: '<S203>/Switch' */

  /* Switch: '<S203>/Switch4' incorporates:
   *  Constant: '<S203>/sat3'
   */
  if (KIPM_ESCEBDActv_flg_ovrdflg) {
    /* Switch: '<S203>/Switch4' incorporates:
     *  Constant: '<S203>/sat4'
     */
    VIPM_ESCEBDActv_flg = KIPM_ESCEBDActv_flg_ovrdval;
  } else {
    /* Switch: '<S203>/Switch4' */
    VIPM_ESCEBDActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lx;
  }

  /* End of Switch: '<S203>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCEBDActv_flg' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCFltLvl_enum' */
  /* Logic: '<S206>/Logical Operator3' incorporates:
   *  Constant: '<S206>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCFltLvlVld_flg = (KIPM_ESCFltLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S206>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S206>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Switch: '<S206>/Switch' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       *  Switch: '<S206>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kv =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_FaultLevel;
    }

    /* End of Switch: '<S206>/Switch3' */
  } else {
    /* Switch: '<S206>/Switch' incorporates:
     *  Constant: '<S206>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kv = KIPM_ESCFltLvlDflt_enum;
  }

  /* End of Switch: '<S206>/Switch' */

  /* Switch: '<S206>/Switch4' incorporates:
   *  Constant: '<S206>/sat3'
   */
  if (KIPM_ESCFltLvl_enum_ovrdflg) {
    /* Switch: '<S206>/Switch4' incorporates:
     *  Constant: '<S206>/sat4'
     */
    VIPM_ESCFltLvl_enum = KIPM_ESCFltLvl_enum_ovrdval;
  } else {
    /* Switch: '<S206>/Switch4' */
    VIPM_ESCFltLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kv;
  }

  /* End of Switch: '<S206>/Switch4' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCFltLvl_enum' */

  /* Outputs for Atomic SubSystem: '<S184>/Subsys_VIPM_ESCSlopPct_pct' */
  /* Logic: '<S208>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
   */
  rtb_LogicalOperator2_mn =
    (((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA())
      ->ESC_SlopePercentV != 0) &&
     (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
     ->VIPM_ESCMsgActv_flg);

  /* Logic: '<S208>/Logical Operator3' incorporates:
   *  Constant: '<S208>/sat3'
   */
  VIPM_ESCSlopPctVld_flg = (KIPM_ESCSlopPct_pct_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S208>/Switch' */
  if (rtb_LogicalOperator2_mn) {
    /* Switch: '<S208>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_ESC_7_FuncStatus_CRCFlt_flg) {
      /* Product: '<S212>/Product' incorporates:
       *  Inport: '<Root>/ESC_7_FuncStatus_CHA'
       */
      rtb_Product_bh =
        (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_7_FuncStatus_CHA_ESC_7_FuncStatus_CHA
         ())->ESC_SlopePercent;

      /* Switch: '<S208>/Switch' incorporates:
       *  Sum: '<S212>/Add'
       *  Switch: '<S208>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ev = (float32)rtb_Product_bh - 100.0F;
    }

    /* End of Switch: '<S208>/Switch3' */
  } else {
    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S208>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ev = KIPM_ESCSlopPctDflt_pct;
  }

  /* End of Switch: '<S208>/Switch' */

  /* Switch: '<S208>/Switch4' incorporates:
   *  Constant: '<S208>/sat3'
   *  Constant: '<S208>/sat4'
   */
  if (KIPM_ESCSlopPct_pct_ovrdflg) {
    VIPM_ESCSlopPct_pct = KIPM_ESCSlopPct_pct_ovrdval;
  } else {
    VIPM_ESCSlopPct_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ev;
  }

  /* MinMax: '<S208>/MinMax' incorporates:
   *  Constant: '<S208>/sat6'
   *  Switch: '<S208>/Switch4'
   */
  if (VIPM_ESCSlopPct_pct > KIPM_ESCSlopPctHi_pct) {
    VIPM_ESCSlopPct_pct = KIPM_ESCSlopPctHi_pct;
  }

  /* End of MinMax: '<S208>/MinMax' */

  /* MinMax: '<S208>/MinMax1' incorporates:
   *  Constant: '<S208>/sat7'
   */
  if (VIPM_ESCSlopPct_pct < KIPM_ESCSlopPctLo_pct) {
    /* Switch: '<S208>/Switch4' incorporates:
     *  MinMax: '<S208>/MinMax1'
     */
    VIPM_ESCSlopPct_pct = KIPM_ESCSlopPctLo_pct;
  }

  /* End of MinMax: '<S208>/MinMax1' */
  /* End of Outputs for SubSystem: '<S184>/Subsys_VIPM_ESCSlopPct_pct' */

  /* BusCreator: '<S184>/BusCreator' incorporates:
   *  Logic: '<S201>/Logical Operator3'
   *  Logic: '<S202>/Logical Operator3'
   *  Logic: '<S203>/Logical Operator3'
   *  Logic: '<S204>/Logical Operator3'
   *  Logic: '<S205>/Logical Operator3'
   *  Logic: '<S206>/Logical Operator3'
   *  Logic: '<S207>/Logical Operator3'
   *  Logic: '<S208>/Logical Operator3'
   *  Logic: '<S209>/Logical Operator3'
   *  Logic: '<S210>/Logical Operator3'
   *  MinMax: '<S208>/MinMax1'
   *  MinMax: '<S210>/MinMax1'
   *  Switch: '<S201>/Switch4'
   *  Switch: '<S202>/Switch4'
   *  Switch: '<S203>/Switch4'
   *  Switch: '<S204>/Switch4'
   *  Switch: '<S205>/Switch4'
   *  Switch: '<S206>/Switch4'
   *  Switch: '<S207>/Switch4'
   *  Switch: '<S209>/Switch4'
   */
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCABSActvSta_flg =
    VIPM_ESCABSActvSta_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCABSActvStaVld_flg =
    VIPM_ESCABSActvStaVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCVehSpd_kph =
    VIPM_ESCVehSpd_kph;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCVehSpdVld_flg =
    VIPM_ESCVehSpdVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCTCSActvSta_flg =
    VIPM_ESCTCSActvSta_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCTCSActvStaVld_flg =
    VIPM_ESCTCSActvStaVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCESPActvSta_flg =
    VIPM_ESCESPActvSta_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCESPActvStaVld_flg =
    VIPM_ESCESPActvStaVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCReqBrkLghtOn_flg =
    VIPM_ESCReqBrkLghtOn_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCReqBrkLghtOnVld_flg =
    VIPM_ESCReqBrkLghtOnVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCCDPActv_flg =
    VIPM_ESCCDPActv_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCCDPActvVld_flg =
    VIPM_ESCCDPActvVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCESSActv_flg =
    VIPM_ESCESSActv_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCESSActvVld_flg =
    VIPM_ESCESSActvVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCEBDActv_flg =
    VIPM_ESCEBDActv_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCEBDActvVld_flg =
    VIPM_ESCEBDActvVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCFltLvl_enum =
    VIPM_ESCFltLvl_enum;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCFltLvlVld_flg =
    VIPM_ESCFltLvlVld_flg;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCSlopPct_pct =
    VIPM_ESCSlopPct_pct;
  AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a.VIPM_ESCSlopPctVld_flg =
    VIPM_ESCSlopPctVld_flg;

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCVehStandStillSta_enum' */
  /* Logic: '<S216>/Logical Operator3' incorporates:
   *  Constant: '<S216>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCVehStandStillStaVld_flg = (KIPM_ESCVehStandStillSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S216>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S216>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S216>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hi =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_VhclStandstillSta;
  } else {
    /* Switch: '<S216>/Switch' incorporates:
     *  Constant: '<S216>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hi = KIPM_ESCVehStandStillStaDflt_enum;
  }

  /* End of Switch: '<S216>/Switch' */

  /* Switch: '<S216>/Switch4' incorporates:
   *  Constant: '<S216>/sat3'
   */
  if (KIPM_ESCVehStandStillSta_enum_ovrdflg) {
    /* Switch: '<S216>/Switch4' incorporates:
     *  Constant: '<S216>/sat4'
     */
    VIPM_ESCVehStandStillSta_enum = KIPM_ESCVehStandStillSta_enum_ovrdval;
  } else {
    /* Switch: '<S216>/Switch4' */
    VIPM_ESCVehStandStillSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hi;
  }

  /* End of Switch: '<S216>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCVehStandStillSta_enum' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnFL_enum' */
  /* Logic: '<S217>/Logical Operator3' incorporates:
   *  Constant: '<S217>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnFLVld_flg = (KIPM_ESCWhlDirctnFL_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S217>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S217>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S217>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jc =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_FL;
  } else {
    /* Switch: '<S217>/Switch' incorporates:
     *  Constant: '<S217>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jc = KIPM_ESCWhlDirctnFLDflt_enum;
  }

  /* End of Switch: '<S217>/Switch' */

  /* Switch: '<S217>/Switch4' incorporates:
   *  Constant: '<S217>/sat3'
   */
  if (KIPM_ESCWhlDirctnFL_enum_ovrdflg) {
    /* Switch: '<S217>/Switch4' incorporates:
     *  Constant: '<S217>/sat4'
     */
    VIPM_ESCWhlDirctnFL_enum = KIPM_ESCWhlDirctnFL_enum_ovrdval;
  } else {
    /* Switch: '<S217>/Switch4' */
    VIPM_ESCWhlDirctnFL_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jc;
  }

  /* End of Switch: '<S217>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnFL_enum' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphFL_kph' */
  /* Logic: '<S221>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_FL &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S221>/Logical Operator3' incorporates:
   *  Constant: '<S221>/sat3'
   */
  VIPM_ESCWhlSpdKphFLVld_flg = (KIPM_ESCWhlSpdKphFL_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S221>/Switch4' incorporates:
   *  Constant: '<S221>/sat3'
   *  Switch: '<S221>/Switch'
   */
  if (KIPM_ESCWhlSpdKphFL_kph_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S221>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFL_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S230>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S260>/MinMax'
     *  Product: '<S230>/Product'
     *  Switch: '<S221>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_FL * 0.05625F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S221>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S221>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFLDflt_kph;
  }

  /* End of Switch: '<S221>/Switch4' */

  /* MinMax: '<S221>/MinMax' incorporates:
   *  Constant: '<S221>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphFLHi_kph) {
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFLHi_kph;
  }

  /* MinMax: '<S221>/MinMax1' incorporates:
   *  Constant: '<S221>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphFLLo_kph) {
    /* MinMax: '<S221>/MinMax1' */
    VIPM_ESCWhlSpdKphFL_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S221>/MinMax1' */
    VIPM_ESCWhlSpdKphFL_kph = KIPM_ESCWhlSpdKphFLLo_kph;
  }

  /* End of MinMax: '<S221>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphFL_kph' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnFR_enum' */
  /* Logic: '<S218>/Logical Operator3' incorporates:
   *  Constant: '<S218>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnFRVld_flg = (KIPM_ESCWhlDirctnFR_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S218>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S218>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S218>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nj =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_FR;
  } else {
    /* Switch: '<S218>/Switch' incorporates:
     *  Constant: '<S218>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nj = KIPM_ESCWhlDirctnFRDflt_enum;
  }

  /* End of Switch: '<S218>/Switch' */

  /* Switch: '<S218>/Switch4' incorporates:
   *  Constant: '<S218>/sat3'
   */
  if (KIPM_ESCWhlDirctnFR_enum_ovrdflg) {
    /* Switch: '<S218>/Switch4' incorporates:
     *  Constant: '<S218>/sat4'
     */
    VIPM_ESCWhlDirctnFR_enum = KIPM_ESCWhlDirctnFR_enum_ovrdval;
  } else {
    /* Switch: '<S218>/Switch4' */
    VIPM_ESCWhlDirctnFR_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nj;
  }

  /* End of Switch: '<S218>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnFR_enum' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphFR_kph' */
  /* Logic: '<S222>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_FR &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S222>/Logical Operator3' incorporates:
   *  Constant: '<S222>/sat3'
   */
  VIPM_ESCWhlSpdKphFRVld_flg = (KIPM_ESCWhlSpdKphFR_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S222>/Switch4' incorporates:
   *  Constant: '<S222>/sat3'
   *  Switch: '<S222>/Switch'
   */
  if (KIPM_ESCWhlSpdKphFR_kph_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S222>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFR_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S231>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S260>/MinMax'
     *  Product: '<S231>/Product'
     *  Switch: '<S222>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_FR * 0.05625F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S222>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S222>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFRDflt_kph;
  }

  /* End of Switch: '<S222>/Switch4' */

  /* MinMax: '<S222>/MinMax' incorporates:
   *  Constant: '<S222>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphFRHi_kph) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphFRHi_kph;
  }

  /* End of MinMax: '<S222>/MinMax' */

  /* MinMax: '<S222>/MinMax1' incorporates:
   *  Constant: '<S222>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphFRLo_kph) {
    /* MinMax: '<S222>/MinMax1' */
    VIPM_ESCWhlSpdKphFR_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S222>/MinMax1' */
    VIPM_ESCWhlSpdKphFR_kph = KIPM_ESCWhlSpdKphFRLo_kph;
  }

  /* End of MinMax: '<S222>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphFR_kph' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCMstrCylPresr_bar' */
  /* Logic: '<S215>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_MasterCylinderPresrV &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S215>/Logical Operator3' incorporates:
   *  Constant: '<S215>/sat3'
   */
  VIPM_ESCMstrCylPresrVld_flg = (KIPM_ESCMstrCylPresr_bar_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S215>/Switch4' incorporates:
   *  Constant: '<S215>/sat3'
   *  Switch: '<S215>/Switch'
   */
  if (KIPM_ESCMstrCylPresr_bar_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S215>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCMstrCylPresr_bar_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  DataTypeConversion: '<S215>/Data Type Conversion2'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S215>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_MasterCylinderPresr;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S215>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S215>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCMstrCylPresrDflt_bar;
  }

  /* End of Switch: '<S215>/Switch4' */

  /* MinMax: '<S215>/MinMax' incorporates:
   *  Constant: '<S215>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCMstrCylPresrHi_bar) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCMstrCylPresrHi_bar;
  }

  /* End of MinMax: '<S215>/MinMax' */

  /* MinMax: '<S215>/MinMax1' incorporates:
   *  Constant: '<S215>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCMstrCylPresrLo_bar) {
    /* MinMax: '<S215>/MinMax1' */
    VIPM_ESCMstrCylPresr_bar = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S215>/MinMax1' */
    VIPM_ESCMstrCylPresr_bar = KIPM_ESCMstrCylPresrLo_bar;
  }

  /* End of MinMax: '<S215>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCMstrCylPresr_bar' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnRL_enum' */
  /* Logic: '<S219>/Logical Operator3' incorporates:
   *  Constant: '<S219>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnRLVld_flg = (KIPM_ESCWhlDirctnRL_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S219>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S219>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S219>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ff =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_RL;
  } else {
    /* Switch: '<S219>/Switch' incorporates:
     *  Constant: '<S219>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ff = KIPM_ESCWhlDirctnRLDflt_enum;
  }

  /* End of Switch: '<S219>/Switch' */

  /* Switch: '<S219>/Switch4' incorporates:
   *  Constant: '<S219>/sat3'
   */
  if (KIPM_ESCWhlDirctnRL_enum_ovrdflg) {
    /* Switch: '<S219>/Switch4' incorporates:
     *  Constant: '<S219>/sat4'
     */
    VIPM_ESCWhlDirctnRL_enum = KIPM_ESCWhlDirctnRL_enum_ovrdval;
  } else {
    /* Switch: '<S219>/Switch4' */
    VIPM_ESCWhlDirctnRL_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ff;
  }

  /* End of Switch: '<S219>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnRL_enum' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphRL_kph' */
  /* Logic: '<S223>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_RL &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S223>/Logical Operator3' incorporates:
   *  Constant: '<S223>/sat3'
   */
  VIPM_ESCWhlSpdKphRLVld_flg = (KIPM_ESCWhlSpdKphRL_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S223>/Switch4' incorporates:
   *  Constant: '<S223>/sat3'
   *  Switch: '<S223>/Switch'
   */
  if (KIPM_ESCWhlSpdKphRL_kph_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S223>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRL_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S232>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S260>/MinMax'
     *  Product: '<S232>/Product'
     *  Switch: '<S223>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_RL * 0.05625F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S223>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S223>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRLDflt_kph;
  }

  /* End of Switch: '<S223>/Switch4' */

  /* MinMax: '<S223>/MinMax' incorporates:
   *  Constant: '<S223>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphRLHi_kph) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRLHi_kph;
  }

  /* End of MinMax: '<S223>/MinMax' */

  /* MinMax: '<S223>/MinMax1' incorporates:
   *  Constant: '<S223>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphRLLo_kph) {
    /* MinMax: '<S223>/MinMax1' */
    VIPM_ESCWhlSpdKphRL_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S223>/MinMax1' */
    VIPM_ESCWhlSpdKphRL_kph = KIPM_ESCWhlSpdKphRLLo_kph;
  }

  /* End of MinMax: '<S223>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphRL_kph' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnRR_enum' */
  /* Logic: '<S220>/Logical Operator3' incorporates:
   *  Constant: '<S220>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlDirctnRRVld_flg = (KIPM_ESCWhlDirctnRR_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S220>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S220>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S220>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lj =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelDirection_RR;
  } else {
    /* Switch: '<S220>/Switch' incorporates:
     *  Constant: '<S220>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lj = KIPM_ESCWhlDirctnRRDflt_enum;
  }

  /* End of Switch: '<S220>/Switch' */

  /* Switch: '<S220>/Switch4' incorporates:
   *  Constant: '<S220>/sat3'
   */
  if (KIPM_ESCWhlDirctnRR_enum_ovrdflg) {
    /* Switch: '<S220>/Switch4' incorporates:
     *  Constant: '<S220>/sat4'
     */
    VIPM_ESCWhlDirctnRR_enum = KIPM_ESCWhlDirctnRR_enum_ovrdval;
  } else {
    /* Switch: '<S220>/Switch4' */
    VIPM_ESCWhlDirctnRR_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_lj;
  }

  /* End of Switch: '<S220>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlDirctnRR_enum' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphRR_kph' */
  /* Logic: '<S224>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_WheelSpeedKphV_RR &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S224>/Logical Operator3' incorporates:
   *  Constant: '<S224>/sat3'
   */
  VIPM_ESCWhlSpdKphRRVld_flg = (KIPM_ESCWhlSpdKphRR_kph_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S224>/Switch4' incorporates:
   *  Constant: '<S224>/sat3'
   *  Switch: '<S224>/Switch'
   */
  if (KIPM_ESCWhlSpdKphRR_kph_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S224>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRR_kph_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S233>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  MinMax: '<S260>/MinMax'
     *  Product: '<S233>/Product'
     *  Switch: '<S224>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
      ->ESC_WheelSpeedKph_RR * 0.05625F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S224>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S224>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRRDflt_kph;
  }

  /* End of Switch: '<S224>/Switch4' */

  /* MinMax: '<S224>/MinMax' incorporates:
   *  Constant: '<S224>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlSpdKphRRHi_kph) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlSpdKphRRHi_kph;
  }

  /* End of MinMax: '<S224>/MinMax' */

  /* MinMax: '<S224>/MinMax1' incorporates:
   *  Constant: '<S224>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlSpdKphRRLo_kph) {
    /* MinMax: '<S224>/MinMax1' */
    VIPM_ESCWhlSpdKphRR_kph = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S224>/MinMax1' */
    VIPM_ESCWhlSpdKphRR_kph = KIPM_ESCWhlSpdKphRRLo_kph;
  }

  /* End of MinMax: '<S224>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlSpdKphRR_kph' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCLongAccSnsrVal_g' */
  /* Logic: '<S214>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_LongAccSensorValueVld &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S214>/Logical Operator3' incorporates:
   *  Constant: '<S214>/sat3'
   */
  VIPM_ESCLongAccSnsrValVld_flg = (KIPM_ESCLongAccSnsrVal_g_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S214>/Switch4' incorporates:
   *  Constant: '<S214>/sat3'
   *  Switch: '<S214>/Switch'
   */
  if (KIPM_ESCLongAccSnsrVal_g_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S214>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLongAccSnsrVal_g_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* Product: '<S234>/Product' incorporates:
     *  Constant: '<S234>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S214>/Switch'
     */
    rtb_Product_eh = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_LongAccSensorValue * 0.005F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S234>/Add'
     *  Switch: '<S214>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 36.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S214>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S214>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLongAccSnsrValDflt_g;
  }

  /* End of Switch: '<S214>/Switch4' */

  /* MinMax: '<S214>/MinMax' incorporates:
   *  Constant: '<S214>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCLongAccSnsrValHi_g) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLongAccSnsrValHi_g;
  }

  /* End of MinMax: '<S214>/MinMax' */

  /* MinMax: '<S214>/MinMax1' incorporates:
   *  Constant: '<S214>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCLongAccSnsrValLo_g) {
    /* MinMax: '<S214>/MinMax1' */
    VIPM_ESCLongAccSnsrVal_g = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S214>/MinMax1' */
    VIPM_ESCLongAccSnsrVal_g = KIPM_ESCLongAccSnsrValLo_g;
  }

  /* End of MinMax: '<S214>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCLongAccSnsrVal_g' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCLatAccSnsrVal_g' */
  /* Logic: '<S213>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_LatAccSensorValueVld &&
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Logic: '<S213>/Logical Operator3' incorporates:
   *  Constant: '<S213>/sat3'
   */
  VIPM_ESCLatAccSnsrValVld_flg = (KIPM_ESCLatAccSnsrVal_g_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S213>/Switch4' incorporates:
   *  Constant: '<S213>/sat3'
   *  Switch: '<S213>/Switch'
   */
  if (KIPM_ESCLatAccSnsrVal_g_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S213>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLatAccSnsrVal_g_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* Product: '<S235>/Product' incorporates:
     *  Constant: '<S235>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S213>/Switch'
     */
    rtb_Product_eh = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_LatAccSensorValue * 0.005F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S235>/Add'
     *  Switch: '<S213>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 36.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S213>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S213>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLatAccSnsrValDflt_g;
  }

  /* End of Switch: '<S213>/Switch4' */

  /* MinMax: '<S213>/MinMax' incorporates:
   *  Constant: '<S213>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCLatAccSnsrValHi_g) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCLatAccSnsrValHi_g;
  }

  /* End of MinMax: '<S213>/MinMax' */

  /* MinMax: '<S213>/MinMax1' incorporates:
   *  Constant: '<S213>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCLatAccSnsrValLo_g) {
    /* MinMax: '<S213>/MinMax1' */
    VIPM_ESCLatAccSnsrVal_g = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S213>/MinMax1' */
    VIPM_ESCLatAccSnsrVal_g = KIPM_ESCLatAccSnsrValLo_g;
  }

  /* End of MinMax: '<S213>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCLatAccSnsrVal_g' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCYawRate_degps' */
  /* Logic: '<S229>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/ESC_A_CHA'
   */
  rtb_LogicalOperator2_mn = ((Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())
    ->ESC_YawRateVld && (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV()
    )->VIPM_ESCMsgActv_flg);

  /* Logic: '<S229>/Logical Operator3' incorporates:
   *  Constant: '<S229>/sat3'
   */
  VIPM_ESCYawRateVld_flg = (KIPM_ESCYawRate_degps_ovrdflg ||
    rtb_LogicalOperator2_mn);

  /* Switch: '<S229>/Switch4' incorporates:
   *  Constant: '<S229>/sat3'
   *  Switch: '<S229>/Switch'
   */
  if (KIPM_ESCYawRate_degps_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S229>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCYawRate_degps_ovrdval;
  } else if (rtb_LogicalOperator2_mn) {
    /* Product: '<S236>/Product' incorporates:
     *  Constant: '<S236>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S229>/Switch'
     */
    rtb_Product_eh = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_YawRate * 0.01F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S236>/Add'
     *  Switch: '<S229>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 300.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S229>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S229>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCYawRateDflt_degps;
  }

  /* End of Switch: '<S229>/Switch4' */

  /* MinMax: '<S229>/MinMax' incorporates:
   *  Constant: '<S229>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCYawRateHi_degps) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCYawRateHi_degps;
  }

  /* End of MinMax: '<S229>/MinMax' */

  /* MinMax: '<S229>/MinMax1' incorporates:
   *  Constant: '<S229>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCYawRateLo_degps) {
    /* MinMax: '<S229>/MinMax1' */
    VIPM_ESCYawRate_degps = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S229>/MinMax1' */
    VIPM_ESCYawRate_degps = KIPM_ESCYawRateLo_degps;
  }

  /* End of MinMax: '<S229>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCYawRate_degps' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqDecReqActv_flg' */
  /* Logic: '<S225>/Logical Operator3' incorporates:
   *  Constant: '<S225>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqDecReqActvVld_flg = (KIPM_ESCWhlTqDecReqActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S225>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S225>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S225>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gg =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())->ESC_WhlTqDecReqActv;
  } else {
    /* Switch: '<S225>/Switch' incorporates:
     *  Constant: '<S225>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gg = KIPM_ESCWhlTqDecReqActvDflt_flg;
  }

  /* End of Switch: '<S225>/Switch' */

  /* Switch: '<S225>/Switch4' incorporates:
   *  Constant: '<S225>/sat3'
   */
  if (KIPM_ESCWhlTqDecReqActv_flg_ovrdflg) {
    /* Switch: '<S225>/Switch4' incorporates:
     *  Constant: '<S225>/sat4'
     */
    VIPM_ESCWhlTqDecReqActv_flg = KIPM_ESCWhlTqDecReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S225>/Switch4' */
    VIPM_ESCWhlTqDecReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gg;
  }

  /* End of Switch: '<S225>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqDecReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqDecReqVal_Nm' */
  /* Logic: '<S226>/Logical Operator3' incorporates:
   *  Constant: '<S226>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqDecReqValVld_flg = (KIPM_ESCWhlTqDecReqVal_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S226>/Switch4' incorporates:
   *  Constant: '<S226>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S226>/Switch'
   */
  if (KIPM_ESCWhlTqDecReqVal_Nm_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S226>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqDecReqVal_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_ESCMsgActv_flg) {
    /* Product: '<S237>/Product' incorporates:
     *  Constant: '<S237>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S226>/Switch'
     */
    rtb_Product_eh = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_WhlTqDecReqVal * 0.5F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S237>/Add'
     *  Switch: '<S226>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 6200.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S226>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S226>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqDecReqValDflt_Nm;
  }

  /* End of Switch: '<S226>/Switch4' */

  /* MinMax: '<S226>/MinMax' incorporates:
   *  Constant: '<S226>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlTqDecReqValHi_Nm) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqDecReqValHi_Nm;
  }

  /* End of MinMax: '<S226>/MinMax' */

  /* MinMax: '<S226>/MinMax1' incorporates:
   *  Constant: '<S226>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlTqDecReqValLo_Nm) {
    /* MinMax: '<S226>/MinMax1' */
    VIPM_ESCWhlTqDecReqVal_Nm = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S226>/MinMax1' */
    VIPM_ESCWhlTqDecReqVal_Nm = KIPM_ESCWhlTqDecReqValLo_Nm;
  }

  /* End of MinMax: '<S226>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqDecReqVal_Nm' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqIncReqActv_flg' */
  /* Logic: '<S227>/Logical Operator3' incorporates:
   *  Constant: '<S227>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqIncReqActvVld_flg = (KIPM_ESCWhlTqIncReqActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S227>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_ESCMsgActv_flg) {
    /* Switch: '<S227>/Switch' incorporates:
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S227>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ofi =
      (Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA())->ESC_WhlTqIncReqActv;
  } else {
    /* Switch: '<S227>/Switch' incorporates:
     *  Constant: '<S227>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ofi = KIPM_ESCWhlTqIncReqActvDflt_flg;
  }

  /* End of Switch: '<S227>/Switch' */

  /* Switch: '<S227>/Switch4' incorporates:
   *  Constant: '<S227>/sat3'
   */
  if (KIPM_ESCWhlTqIncReqActv_flg_ovrdflg) {
    /* Switch: '<S227>/Switch4' incorporates:
     *  Constant: '<S227>/sat4'
     */
    VIPM_ESCWhlTqIncReqActv_flg = KIPM_ESCWhlTqIncReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S227>/Switch4' */
    VIPM_ESCWhlTqIncReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ofi;
  }

  /* End of Switch: '<S227>/Switch4' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqIncReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqIncReqVal_Nm' */
  /* Logic: '<S228>/Logical Operator3' incorporates:
   *  Constant: '<S228>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCWhlTqIncReqValVld_flg = (KIPM_ESCWhlTqIncReqVal_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_ESCMsgActv_flg);

  /* Switch: '<S228>/Switch4' incorporates:
   *  Constant: '<S228>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S228>/Switch'
   */
  if (KIPM_ESCWhlTqIncReqVal_Nm_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S228>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqIncReqVal_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_ESCMsgActv_flg) {
    /* Product: '<S238>/Product' incorporates:
     *  Constant: '<S238>/Constant'
     *  Inport: '<Root>/ESC_A_CHA'
     *  Switch: '<S228>/Switch'
     */
    rtb_Product_eh = (float32)(Rte_IRead_Runbl_IpmCanRx_10ms_ESC_A_CHA_ESC_A_CHA
      ())->ESC_WhlTqIncReqVal * 0.5F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S238>/Add'
     *  Switch: '<S228>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 6200.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S228>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S228>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqIncReqValDflt_Nm;
  }

  /* End of Switch: '<S228>/Switch4' */

  /* MinMax: '<S228>/MinMax' incorporates:
   *  Constant: '<S228>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_ESCWhlTqIncReqValHi_Nm) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_ESCWhlTqIncReqValHi_Nm;
  }

  /* End of MinMax: '<S228>/MinMax' */

  /* MinMax: '<S228>/MinMax1' incorporates:
   *  Constant: '<S228>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_ESCWhlTqIncReqValLo_Nm) {
    /* MinMax: '<S228>/MinMax1' */
    VIPM_ESCWhlTqIncReqVal_Nm = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S228>/MinMax1' */
    VIPM_ESCWhlTqIncReqVal_Nm = KIPM_ESCWhlTqIncReqValLo_Nm;
  }

  /* End of MinMax: '<S228>/MinMax1' */
  /* End of Outputs for SubSystem: '<S185>/Subsys_VIPM_ESCWhlTqIncReqVal_Nm' */

  /* BusCreator: '<S185>/BusCreator' incorporates:
   *  Logic: '<S213>/Logical Operator3'
   *  Logic: '<S214>/Logical Operator3'
   *  Logic: '<S215>/Logical Operator3'
   *  Logic: '<S216>/Logical Operator3'
   *  Logic: '<S217>/Logical Operator3'
   *  Logic: '<S218>/Logical Operator3'
   *  Logic: '<S219>/Logical Operator3'
   *  Logic: '<S220>/Logical Operator3'
   *  Logic: '<S221>/Logical Operator3'
   *  Logic: '<S222>/Logical Operator3'
   *  Logic: '<S223>/Logical Operator3'
   *  Logic: '<S224>/Logical Operator3'
   *  Logic: '<S225>/Logical Operator3'
   *  Logic: '<S226>/Logical Operator3'
   *  Logic: '<S227>/Logical Operator3'
   *  Logic: '<S228>/Logical Operator3'
   *  Logic: '<S229>/Logical Operator3'
   *  MinMax: '<S213>/MinMax1'
   *  MinMax: '<S214>/MinMax1'
   *  MinMax: '<S215>/MinMax1'
   *  MinMax: '<S221>/MinMax1'
   *  MinMax: '<S222>/MinMax1'
   *  MinMax: '<S223>/MinMax1'
   *  MinMax: '<S224>/MinMax1'
   *  MinMax: '<S226>/MinMax1'
   *  MinMax: '<S228>/MinMax1'
   *  MinMax: '<S229>/MinMax1'
   *  Switch: '<S216>/Switch4'
   *  Switch: '<S217>/Switch4'
   *  Switch: '<S218>/Switch4'
   *  Switch: '<S219>/Switch4'
   *  Switch: '<S220>/Switch4'
   *  Switch: '<S225>/Switch4'
   *  Switch: '<S227>/Switch4'
   */
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCVehStandStillSta_enum =
    VIPM_ESCVehStandStillSta_enum;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCVehStandStillStaVld_flg =
    VIPM_ESCVehStandStillStaVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnFL_enum =
    VIPM_ESCWhlDirctnFL_enum;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnFLVld_flg =
    VIPM_ESCWhlDirctnFLVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphFL_kph =
    VIPM_ESCWhlSpdKphFL_kph;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphFLVld_flg =
    VIPM_ESCWhlSpdKphFLVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnFR_enum =
    VIPM_ESCWhlDirctnFR_enum;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnFRVld_flg =
    VIPM_ESCWhlDirctnFRVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphFR_kph =
    VIPM_ESCWhlSpdKphFR_kph;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphFRVld_flg =
    VIPM_ESCWhlSpdKphFRVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCMstrCylPresr_bar =
    VIPM_ESCMstrCylPresr_bar;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCMstrCylPresrVld_flg =
    VIPM_ESCMstrCylPresrVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnRL_enum =
    VIPM_ESCWhlDirctnRL_enum;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnRLVld_flg =
    VIPM_ESCWhlDirctnRLVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphRL_kph =
    VIPM_ESCWhlSpdKphRL_kph;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphRLVld_flg =
    VIPM_ESCWhlSpdKphRLVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnRR_enum =
    VIPM_ESCWhlDirctnRR_enum;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlDirctnRRVld_flg =
    VIPM_ESCWhlDirctnRRVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphRR_kph =
    VIPM_ESCWhlSpdKphRR_kph;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlSpdKphRRVld_flg =
    VIPM_ESCWhlSpdKphRRVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCLongAccSnsrVal_g =
    VIPM_ESCLongAccSnsrVal_g;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCLongAccSnsrValVld_flg =
    VIPM_ESCLongAccSnsrValVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCLatAccSnsrVal_g =
    VIPM_ESCLatAccSnsrVal_g;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCLatAccSnsrValVld_flg =
    VIPM_ESCLatAccSnsrValVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCYawRate_degps = VIPM_ESCYawRate_degps;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCYawRateVld_flg = VIPM_ESCYawRateVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqDecReqActv_flg =
    VIPM_ESCWhlTqDecReqActv_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqDecReqActvVld_flg =
    VIPM_ESCWhlTqDecReqActvVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqDecReqVal_Nm =
    VIPM_ESCWhlTqDecReqVal_Nm;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqDecReqValVld_flg =
    VIPM_ESCWhlTqDecReqValVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqIncReqActv_flg =
    VIPM_ESCWhlTqIncReqActv_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqIncReqActvVld_flg =
    VIPM_ESCWhlTqIncReqActvVld_flg;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqIncReqVal_Nm =
    VIPM_ESCWhlTqIncReqVal_Nm;
  AppSwcIpm_ARID_DEF.ESC_A_CHA_f.VIPM_ESCWhlTqIncReqValVld_flg =
    VIPM_ESCWhlTqIncReqValVld_flg;

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1MotSpd_rpm' */
  /* Logic: '<S246>/Logical Operator3' incorporates:
   *  Constant: '<S246>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1MotSpdVld_flg = (KIPM_INV1MotSpd_rpm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S246>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S246>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Product: '<S250>/Product' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       */
      rtb_Product_bh =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_MotSpeed;

      /* Switch: '<S246>/Switch' incorporates:
       *  Sum: '<S250>/Add'
       *  Switch: '<S246>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jy = (float32)rtb_Product_bh -
        12000.0F;
    }

    /* End of Switch: '<S246>/Switch3' */
  } else {
    /* Switch: '<S246>/Switch' incorporates:
     *  Constant: '<S246>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jy = KIPM_INV1MotSpdDflt_rpm;
  }

  /* End of Switch: '<S246>/Switch' */

  /* Switch: '<S246>/Switch4' incorporates:
   *  Constant: '<S246>/sat3'
   *  Constant: '<S246>/sat4'
   */
  if (KIPM_INV1MotSpd_rpm_ovrdflg) {
    VIPM_INV1MotSpd_rpm = KIPM_INV1MotSpd_rpm_ovrdval;
  } else {
    VIPM_INV1MotSpd_rpm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jy;
  }

  /* MinMax: '<S246>/MinMax' incorporates:
   *  Constant: '<S246>/sat6'
   *  Switch: '<S246>/Switch4'
   */
  if (VIPM_INV1MotSpd_rpm > KIPM_INV1MotSpdHi_rpm) {
    VIPM_INV1MotSpd_rpm = KIPM_INV1MotSpdHi_rpm;
  }

  /* End of MinMax: '<S246>/MinMax' */

  /* MinMax: '<S246>/MinMax1' incorporates:
   *  Constant: '<S246>/sat7'
   */
  if (VIPM_INV1MotSpd_rpm < KIPM_INV1MotSpdLo_rpm) {
    /* Switch: '<S246>/Switch4' incorporates:
     *  MinMax: '<S246>/MinMax1'
     */
    VIPM_INV1MotSpd_rpm = KIPM_INV1MotSpdLo_rpm;
  }

  /* End of MinMax: '<S246>/MinMax1' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1MotSpd_rpm' */

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1ActTorq_Nm' */
  /* Logic: '<S244>/Logical Operator3' incorporates:
   *  Constant: '<S244>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1ActTorqVld_flg = (KIPM_INV1ActTorq_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S244>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S244>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Product: '<S251>/Product' incorporates:
       *  Constant: '<S251>/Constant'
       *  Inport: '<Root>/INV_1_Value_EPT'
       */
      rtb_Product_eh = (float32)
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_ActTorque * 0.1F;

      /* Switch: '<S244>/Switch' incorporates:
       *  Sum: '<S251>/Add'
       *  Switch: '<S244>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k = rtb_Product_eh - 819.2F;
    }

    /* End of Switch: '<S244>/Switch3' */
  } else {
    /* Switch: '<S244>/Switch' incorporates:
     *  Constant: '<S244>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k = KIPM_INV1ActTorqDflt_Nm;
  }

  /* End of Switch: '<S244>/Switch' */

  /* Switch: '<S244>/Switch4' incorporates:
   *  Constant: '<S244>/sat3'
   *  Constant: '<S244>/sat4'
   */
  if (KIPM_INV1ActTorq_Nm_ovrdflg) {
    VIPM_INV1ActTorq_Nm = KIPM_INV1ActTorq_Nm_ovrdval;
  } else {
    VIPM_INV1ActTorq_Nm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k;
  }

  /* MinMax: '<S244>/MinMax' incorporates:
   *  Constant: '<S244>/sat6'
   *  Switch: '<S244>/Switch4'
   */
  if (VIPM_INV1ActTorq_Nm > KIPM_INV1ActTorqHi_Nm) {
    VIPM_INV1ActTorq_Nm = KIPM_INV1ActTorqHi_Nm;
  }

  /* End of MinMax: '<S244>/MinMax' */

  /* MinMax: '<S244>/MinMax1' incorporates:
   *  Constant: '<S244>/sat7'
   */
  if (VIPM_INV1ActTorq_Nm < KIPM_INV1ActTorqLo_Nm) {
    /* Switch: '<S244>/Switch4' incorporates:
     *  MinMax: '<S244>/MinMax1'
     */
    VIPM_INV1ActTorq_Nm = KIPM_INV1ActTorqLo_Nm;
  }

  /* End of MinMax: '<S244>/MinMax1' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1ActTorq_Nm' */

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1PreChrgAllwd_enum' */
  /* Logic: '<S247>/Logical Operator3' incorporates:
   *  Constant: '<S247>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1PreChrgAllwdVld_flg = (KIPM_INV1PreChrgAllwd_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S247>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S247>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S247>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S247>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gn =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_PreChargeAllowed;
    }

    /* End of Switch: '<S247>/Switch3' */
  } else {
    /* Switch: '<S247>/Switch' incorporates:
     *  Constant: '<S247>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gn = KIPM_INV1PreChrgAllwdDflt_enum;
  }

  /* End of Switch: '<S247>/Switch' */

  /* Switch: '<S247>/Switch4' incorporates:
   *  Constant: '<S247>/sat3'
   */
  if (KIPM_INV1PreChrgAllwd_enum_ovrdflg) {
    /* Switch: '<S247>/Switch4' incorporates:
     *  Constant: '<S247>/sat4'
     */
    VIPM_INV1PreChrgAllwd_enum = KIPM_INV1PreChrgAllwd_enum_ovrdval;
  } else {
    /* Switch: '<S247>/Switch4' */
    VIPM_INV1PreChrgAllwd_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gn;
  }

  /* End of Switch: '<S247>/Switch4' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1PreChrgAllwd_enum' */

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1ShutdownAllwd_enum' */
  /* Logic: '<S249>/Logical Operator3' incorporates:
   *  Constant: '<S249>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1ShutdownAllwdVld_flg = (KIPM_INV1ShutdownAllwd_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S249>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S249>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S249>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S249>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nu =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_ShutdownAllowed;
    }

    /* End of Switch: '<S249>/Switch3' */
  } else {
    /* Switch: '<S249>/Switch' incorporates:
     *  Constant: '<S249>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nu = KIPM_INV1ShutdownAllwdDflt_enum;
  }

  /* End of Switch: '<S249>/Switch' */

  /* Switch: '<S249>/Switch4' incorporates:
   *  Constant: '<S249>/sat3'
   */
  if (KIPM_INV1ShutdownAllwd_enum_ovrdflg) {
    /* Switch: '<S249>/Switch4' incorporates:
     *  Constant: '<S249>/sat4'
     */
    VIPM_INV1ShutdownAllwd_enum = KIPM_INV1ShutdownAllwd_enum_ovrdval;
  } else {
    /* Switch: '<S249>/Switch4' */
    VIPM_INV1ShutdownAllwd_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nu;
  }

  /* End of Switch: '<S249>/Switch4' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1ShutdownAllwd_enum' */

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1ActMode_enum' */
  /* Logic: '<S243>/Logical Operator3' incorporates:
   *  Constant: '<S243>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1ActModeVld_flg = (KIPM_INV1ActMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S243>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S243>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S243>/Switch' incorporates:
       *  DataTypeConversion: '<S243>/Data Type Conversion2'
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S243>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cw =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_1_ActMode;
    }

    /* End of Switch: '<S243>/Switch3' */
  } else {
    /* Switch: '<S243>/Switch' incorporates:
     *  Constant: '<S243>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cw = KIPM_INV1ActModeDflt_enum;
  }

  /* End of Switch: '<S243>/Switch' */

  /* Switch: '<S243>/Switch4' incorporates:
   *  Constant: '<S243>/sat3'
   */
  if (KIPM_INV1ActMode_enum_ovrdflg) {
    /* Switch: '<S243>/Switch4' incorporates:
     *  Constant: '<S243>/sat4'
     */
    VIPM_INV1ActMode_enum = KIPM_INV1ActMode_enum_ovrdval;
  } else {
    /* Switch: '<S243>/Switch4' incorporates:
     *  Switch: '<S243>/Switch'
     */
    VIPM_INV1ActMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cw;
  }

  /* End of Switch: '<S243>/Switch4' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1ActMode_enum' */

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1PreprogmFlg_flg' */
  /* Logic: '<S248>/Logical Operator3' incorporates:
   *  Constant: '<S248>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1PreprogmFlgVld_flg = (KIPM_INV1PreprogmFlg_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S248>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S248>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S248>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S248>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mvx =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_PreprogmFlg;
    }

    /* End of Switch: '<S248>/Switch3' */
  } else {
    /* Switch: '<S248>/Switch' incorporates:
     *  Constant: '<S248>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mvx = KIPM_INV1PreprogmFlgDflt_flg;
  }

  /* End of Switch: '<S248>/Switch' */

  /* Switch: '<S248>/Switch4' incorporates:
   *  Constant: '<S248>/sat3'
   */
  if (KIPM_INV1PreprogmFlg_flg_ovrdflg) {
    /* Switch: '<S248>/Switch4' incorporates:
     *  Constant: '<S248>/sat4'
     */
    VIPM_INV1PreprogmFlg_flg = KIPM_INV1PreprogmFlg_flg_ovrdval;
  } else {
    /* Switch: '<S248>/Switch4' */
    VIPM_INV1PreprogmFlg_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mvx;
  }

  /* End of Switch: '<S248>/Switch4' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1PreprogmFlg_flg' */

  /* Outputs for Atomic SubSystem: '<S239>/Subsys_VIPM_INV1AntithftAuthRslt_enum' */
  /* Logic: '<S245>/Logical Operator3' incorporates:
   *  Constant: '<S245>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV1AntithftAuthRsltVld_flg = (KIPM_INV1AntithftAuthRslt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S245>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S245>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_10ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_INV_1_Value_CRCFlt_flg) {
      /* Switch: '<S245>/Switch' incorporates:
       *  Inport: '<Root>/INV_1_Value_EPT'
       *  Switch: '<S245>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jq =
        (Rte_IRead_Runbl_IpmCanRx_10ms_INV_1_Value_EPT_INV_1_Value_EPT())
        ->INV_AntithftAuthRslt;
    }

    /* End of Switch: '<S245>/Switch3' */
  } else {
    /* Switch: '<S245>/Switch' incorporates:
     *  Constant: '<S245>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jq = KIPM_INV1AntithftAuthRsltDflt_enum;
  }

  /* End of Switch: '<S245>/Switch' */

  /* Switch: '<S245>/Switch4' incorporates:
   *  Constant: '<S245>/sat3'
   */
  if (KIPM_INV1AntithftAuthRslt_enum_ovrdflg) {
    /* Switch: '<S245>/Switch4' incorporates:
     *  Constant: '<S245>/sat4'
     */
    VIPM_INV1AntithftAuthRslt_enum = KIPM_INV1AntithftAuthRslt_enum_ovrdval;
  } else {
    /* Switch: '<S245>/Switch4' */
    VIPM_INV1AntithftAuthRslt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jq;
  }

  /* End of Switch: '<S245>/Switch4' */
  /* End of Outputs for SubSystem: '<S239>/Subsys_VIPM_INV1AntithftAuthRslt_enum' */

  /* BusCreator: '<S239>/BusCreator' incorporates:
   *  DataTypeConversion: '<S239>/Data Type Conversion'
   *  Logic: '<S243>/Logical Operator3'
   *  Logic: '<S244>/Logical Operator3'
   *  Logic: '<S245>/Logical Operator3'
   *  Logic: '<S246>/Logical Operator3'
   *  Logic: '<S247>/Logical Operator3'
   *  Logic: '<S248>/Logical Operator3'
   *  Logic: '<S249>/Logical Operator3'
   *  MinMax: '<S244>/MinMax1'
   *  MinMax: '<S246>/MinMax1'
   *  Switch: '<S243>/Switch4'
   *  Switch: '<S245>/Switch4'
   *  Switch: '<S247>/Switch4'
   *  Switch: '<S248>/Switch4'
   *  Switch: '<S249>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1MotSpd_rpm =
    VIPM_INV1MotSpd_rpm;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1MotSpdVld_flg =
    VIPM_INV1MotSpdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1ActTorq_Nm =
    VIPM_INV1ActTorq_Nm;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1ActTorqVld_flg =
    VIPM_INV1ActTorqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1PreChrgAllwd_enum =
    VIPM_INV1PreChrgAllwd_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1PreChrgAllwdVld_flg =
    VIPM_INV1PreChrgAllwdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1ShutdownAllwd_enum =
    VIPM_INV1ShutdownAllwd_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1ShutdownAllwdVld_flg =
    VIPM_INV1ShutdownAllwdVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1ActMode_enum =
    VIPM_INV1ActMode_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1ActModeVld_flg =
    VIPM_INV1ActModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1PreprogmFlg_flg =
    VIPM_INV1PreprogmFlg_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1PreprogmFlgVld_flg =
    VIPM_INV1PreprogmFlgVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1AntithftAuthRslt_enum =
    VIPM_INV1AntithftAuthRslt_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d.VIPM_INV1AntithftAuthRsltVld_flg =
    VIPM_INV1AntithftAuthRsltVld_flg;

  /* Outputs for Atomic SubSystem: '<S240>/Subsys_VIPM_INV2MotorMaxTemp_C' */
  /* Logic: '<S255>/Logical Operator3' incorporates:
   *  Constant: '<S255>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2MotorMaxTempVld_flg = (KIPM_INV2MotorMaxTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S255>/Switch4' incorporates:
   *  Constant: '<S255>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S255>/Switch'
   */
  if (KIPM_INV2MotorMaxTemp_C_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S255>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2MotorMaxTemp_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S256>/Product' incorporates:
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  Switch: '<S255>/Switch'
     */
    rtb_Product_bh =
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_MotorMaxTem;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S256>/Add'
     *  Switch: '<S255>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)rtb_Product_bh - 40.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S255>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S255>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2MotorMaxTempDflt_C;
  }

  /* End of Switch: '<S255>/Switch4' */

  /* MinMax: '<S255>/MinMax' incorporates:
   *  Constant: '<S255>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2MotorMaxTempHi_C) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2MotorMaxTempHi_C;
  }

  /* End of MinMax: '<S255>/MinMax' */

  /* MinMax: '<S255>/MinMax1' incorporates:
   *  Constant: '<S255>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2MotorMaxTempLo_C) {
    /* MinMax: '<S255>/MinMax1' */
    VIPM_INV2MotorMaxTemp_C = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S255>/MinMax1' */
    VIPM_INV2MotorMaxTemp_C = KIPM_INV2MotorMaxTempLo_C;
  }

  /* End of MinMax: '<S255>/MinMax1' */
  /* End of Outputs for SubSystem: '<S240>/Subsys_VIPM_INV2MotorMaxTemp_C' */

  /* Outputs for Atomic SubSystem: '<S240>/Subsys_VIPM_INV2IgbtMaxTemp_C' */
  /* Logic: '<S252>/Logical Operator3' incorporates:
   *  Constant: '<S252>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2IgbtMaxTempVld_flg = (KIPM_INV2IgbtMaxTemp_C_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S252>/Switch4' incorporates:
   *  Constant: '<S252>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S252>/Switch'
   */
  if (KIPM_INV2IgbtMaxTemp_C_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S252>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2IgbtMaxTemp_C_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S257>/Product' incorporates:
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  Switch: '<S252>/Switch'
     */
    rtb_Product_bh =
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_IgbtMaxTem;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S257>/Add'
     *  Switch: '<S252>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)rtb_Product_bh - 40.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S252>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S252>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2IgbtMaxTempDflt_C;
  }

  /* End of Switch: '<S252>/Switch4' */

  /* MinMax: '<S252>/MinMax' incorporates:
   *  Constant: '<S252>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2IgbtMaxTempHi_C) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2IgbtMaxTempHi_C;
  }

  /* End of MinMax: '<S252>/MinMax' */

  /* MinMax: '<S252>/MinMax1' incorporates:
   *  Constant: '<S252>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2IgbtMaxTempLo_C) {
    /* MinMax: '<S252>/MinMax1' */
    VIPM_INV2IgbtMaxTemp_C = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S252>/MinMax1' */
    VIPM_INV2IgbtMaxTemp_C = KIPM_INV2IgbtMaxTempLo_C;
  }

  /* End of MinMax: '<S252>/MinMax1' */
  /* End of Outputs for SubSystem: '<S240>/Subsys_VIPM_INV2IgbtMaxTemp_C' */

  /* Outputs for Atomic SubSystem: '<S240>/Subsys_VIPM_INV2InpCurnt_A' */
  /* Logic: '<S253>/Logical Operator3' incorporates:
   *  Constant: '<S253>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2InpCurntVld_flg = (KIPM_INV2InpCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S253>/Switch4' incorporates:
   *  Constant: '<S253>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S253>/Switch'
   */
  if (KIPM_INV2InpCurnt_A_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S253>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S258>/Product' incorporates:
     *  Constant: '<S258>/Constant'
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  Switch: '<S253>/Switch'
     */
    rtb_Product_eh = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_InpCurrent * 0.1F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S258>/Add'
     *  Switch: '<S253>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 819.2F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S253>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S253>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpCurntDflt_A;
  }

  /* End of Switch: '<S253>/Switch4' */

  /* MinMax: '<S253>/MinMax' incorporates:
   *  Constant: '<S253>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2InpCurntHi_A) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpCurntHi_A;
  }

  /* End of MinMax: '<S253>/MinMax' */

  /* MinMax: '<S253>/MinMax1' incorporates:
   *  Constant: '<S253>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2InpCurntLo_A) {
    /* MinMax: '<S253>/MinMax1' */
    VIPM_INV2InpCurnt_A = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S253>/MinMax1' */
    VIPM_INV2InpCurnt_A = KIPM_INV2InpCurntLo_A;
  }

  /* End of MinMax: '<S253>/MinMax1' */
  /* End of Outputs for SubSystem: '<S240>/Subsys_VIPM_INV2InpCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S240>/Subsys_VIPM_INV2InpVolt_V' */
  /* Logic: '<S254>/Logical Operator3' incorporates:
   *  Constant: '<S254>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV2InpVoltVld_flg = (KIPM_INV2InpVolt_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S254>/Switch4' incorporates:
   *  Constant: '<S254>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S254>/Switch'
   */
  if (KIPM_INV2InpVolt_V_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S254>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpVolt_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  DataTypeConversion: '<S254>/Data Type Conversion2'
     *  Inport: '<Root>/INV_2_Value_EPT'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S254>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_2_Value_EPT_INV_2_Value_EPT())
      ->INV_2_InpVoltage;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S254>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S254>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpVoltDflt_V;
  }

  /* End of Switch: '<S254>/Switch4' */

  /* MinMax: '<S254>/MinMax' incorporates:
   *  Constant: '<S254>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV2InpVoltHi_V) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV2InpVoltHi_V;
  }

  /* End of MinMax: '<S254>/MinMax' */

  /* MinMax: '<S254>/MinMax1' incorporates:
   *  Constant: '<S254>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV2InpVoltLo_V) {
    /* MinMax: '<S254>/MinMax1' */
    VIPM_INV2InpVolt_V = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S254>/MinMax1' */
    VIPM_INV2InpVolt_V = KIPM_INV2InpVoltLo_V;
  }

  /* End of MinMax: '<S254>/MinMax1' */
  /* End of Outputs for SubSystem: '<S240>/Subsys_VIPM_INV2InpVolt_V' */

  /* BusCreator: '<S240>/BusCreator' incorporates:
   *  Logic: '<S252>/Logical Operator3'
   *  Logic: '<S253>/Logical Operator3'
   *  Logic: '<S254>/Logical Operator3'
   *  Logic: '<S255>/Logical Operator3'
   *  MinMax: '<S252>/MinMax1'
   *  MinMax: '<S253>/MinMax1'
   *  MinMax: '<S254>/MinMax1'
   *  MinMax: '<S255>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2MotorMaxTemp_C =
    VIPM_INV2MotorMaxTemp_C;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2MotorMaxTempVld_flg =
    VIPM_INV2MotorMaxTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2IgbtMaxTemp_C =
    VIPM_INV2IgbtMaxTemp_C;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2IgbtMaxTempVld_flg =
    VIPM_INV2IgbtMaxTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2InpCurnt_A =
    VIPM_INV2InpCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2InpCurntVld_flg =
    VIPM_INV2InpCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2InpVolt_V =
    VIPM_INV2InpVolt_V;
  AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f.VIPM_INV2InpVoltVld_flg =
    VIPM_INV2InpVoltVld_flg;

  /* Outputs for Atomic SubSystem: '<S241>/Subsys_VIPM_INV3DrvTqAllwdMax_Nm' */
  /* Logic: '<S259>/Logical Operator3' incorporates:
   *  Constant: '<S259>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV3DrvTqAllwdMaxVld_flg = (KIPM_INV3DrvTqAllwdMax_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S259>/Switch4' incorporates:
   *  Constant: '<S259>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S259>/Switch'
   */
  if (KIPM_INV3DrvTqAllwdMax_Nm_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S259>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMax_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S261>/Constant'
     *  Inport: '<Root>/INV_3_Value_EPT'
     *  MinMax: '<S260>/MinMax'
     *  Product: '<S261>/Product'
     *  Switch: '<S259>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT())
      ->INV_3_DriveTqAllowedMax * 0.5F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S259>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S259>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMaxDflt_Nm;
  }

  /* End of Switch: '<S259>/Switch4' */

  /* MinMax: '<S259>/MinMax' incorporates:
   *  Constant: '<S259>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV3DrvTqAllwdMaxHi_Nm) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMaxHi_Nm;
  }

  /* End of MinMax: '<S259>/MinMax' */

  /* MinMax: '<S259>/MinMax1' incorporates:
   *  Constant: '<S259>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm >= KIPM_INV3DrvTqAllwdMaxLo_Nm) {
    /* MinMax: '<S259>/MinMax1' */
    VIPM_INV3DrvTqAllwdMax_Nm = VIPM_INV3RecupTqAllwdMax_Nm;
  } else {
    /* MinMax: '<S259>/MinMax1' */
    VIPM_INV3DrvTqAllwdMax_Nm = KIPM_INV3DrvTqAllwdMaxLo_Nm;
  }

  /* End of MinMax: '<S259>/MinMax1' */
  /* End of Outputs for SubSystem: '<S241>/Subsys_VIPM_INV3DrvTqAllwdMax_Nm' */

  /* Outputs for Atomic SubSystem: '<S241>/Subsys_VIPM_INV3RecupTqAllwdMax_Nm' */
  /* Logic: '<S260>/Logical Operator3' incorporates:
   *  Constant: '<S260>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV3RecupTqAllwdMaxVld_flg = (KIPM_INV3RecupTqAllwdMax_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S260>/Switch4' incorporates:
   *  Constant: '<S260>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S260>/Switch'
   */
  if (KIPM_INV3RecupTqAllwdMax_Nm_ovrdflg) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S260>/sat4'
     *  MinMax: '<S260>/MinMax'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMax_Nm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
             ->VIPM_INVMsgActv_flg) {
    /* Product: '<S262>/Product' incorporates:
     *  Constant: '<S262>/Constant'
     *  Inport: '<Root>/INV_3_Value_EPT'
     *  Switch: '<S260>/Switch'
     */
    rtb_Product_eh = (float32)
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_3_Value_EPT_INV_3_Value_EPT())
      ->INV_3_RecuperationTqAllowedMax * 0.5F;

    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax'
     *  Sum: '<S262>/Add'
     *  Switch: '<S260>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = rtb_Product_eh - 500.0F;
  } else {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  Constant: '<S260>/sat5'
     *  MinMax: '<S260>/MinMax'
     *  Switch: '<S260>/Switch'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMaxDflt_Nm;
  }

  /* End of Switch: '<S260>/Switch4' */

  /* MinMax: '<S260>/MinMax' incorporates:
   *  Constant: '<S260>/sat6'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm > KIPM_INV3RecupTqAllwdMaxHi_Nm) {
    /* MinMax: '<S221>/MinMax' */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMaxHi_Nm;
  }

  /* End of MinMax: '<S260>/MinMax' */

  /* MinMax: '<S260>/MinMax1' incorporates:
   *  Constant: '<S260>/sat7'
   */
  if (VIPM_INV3RecupTqAllwdMax_Nm < KIPM_INV3RecupTqAllwdMaxLo_Nm) {
    /* MinMax: '<S221>/MinMax' incorporates:
     *  MinMax: '<S260>/MinMax1'
     */
    VIPM_INV3RecupTqAllwdMax_Nm = KIPM_INV3RecupTqAllwdMaxLo_Nm;
  }

  /* End of MinMax: '<S260>/MinMax1' */
  /* End of Outputs for SubSystem: '<S241>/Subsys_VIPM_INV3RecupTqAllwdMax_Nm' */

  /* BusCreator: '<S241>/BusCreator' incorporates:
   *  Logic: '<S259>/Logical Operator3'
   *  Logic: '<S260>/Logical Operator3'
   *  MinMax: '<S259>/MinMax1'
   *  MinMax: '<S260>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT_n.VIPM_INV3DrvTqAllwdMax_Nm =
    VIPM_INV3DrvTqAllwdMax_Nm;
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT_n.VIPM_INV3DrvTqAllwdMaxVld_flg =
    VIPM_INV3DrvTqAllwdMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT_n.VIPM_INV3RecupTqAllwdMax_Nm =
    VIPM_INV3RecupTqAllwdMax_Nm;
  AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT_n.VIPM_INV3RecupTqAllwdMaxVld_flg =
    VIPM_INV3RecupTqAllwdMaxVld_flg;

  /* Outputs for Atomic SubSystem: '<S242>/Subsys_VIPM_INV4FltLvl_enum' */
  /* Logic: '<S263>/Logical Operator3' incorporates:
   *  Constant: '<S263>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_INV4FltLvlVld_flg = (KIPM_INV4FltLvl_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())->VIPM_INVMsgActv_flg);

  /* Switch: '<S263>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_10ms_MsgActv_outputsIRV())
      ->VIPM_INVMsgActv_flg) {
    /* Switch: '<S263>/Switch' incorporates:
     *  Inport: '<Root>/INV_4_Value_EPT'
     *  Switch: '<S263>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ga =
      (Rte_IRead_Runbl_IpmCanRx_10ms_INV_4_Value_EPT_INV_4_Value_EPT())
      ->INV_4_FaultLevl;
  } else {
    /* Switch: '<S263>/Switch' incorporates:
     *  Constant: '<S263>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ga = KIPM_INV4FltLvlDflt_enum;
  }

  /* End of Switch: '<S263>/Switch' */

  /* Switch: '<S263>/Switch4' incorporates:
   *  Constant: '<S263>/sat3'
   */
  if (KIPM_INV4FltLvl_enum_ovrdflg) {
    /* Switch: '<S263>/Switch4' incorporates:
     *  Constant: '<S263>/sat4'
     */
    VIPM_INV4FltLvl_enum = KIPM_INV4FltLvl_enum_ovrdval;
  } else {
    /* Switch: '<S263>/Switch4' */
    VIPM_INV4FltLvl_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ga;
  }

  /* End of Switch: '<S263>/Switch4' */
  /* End of Outputs for SubSystem: '<S242>/Subsys_VIPM_INV4FltLvl_enum' */

  /* BusCreator: '<S242>/BusCreator' incorporates:
   *  Logic: '<S263>/Logical Operator3'
   *  Switch: '<S263>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_INV_4_Value_EPT_b.VIPM_INV4FltLvl_enum =
    VIPM_INV4FltLvl_enum;
  AppSwcIpm_ARID_DEF.IPM_INV_4_Value_EPT_b.VIPM_INV4FltLvlVld_flg =
    VIPM_INV4FltLvlVld_flg;
}

/* Output and update for function-call system: '<Root>/Ipm20ms' */
static void Runbl_Ipm20ms(void)
{
  sint32 rtb_Product_os;
  float32 rtb_Product_f0;
  boolean rtb_LogicalOperator2_fz;

  /* Outputs for Atomic SubSystem: '<S267>/Subsys_VIPM_SCSGrShftLvrPstnReq_enum' */
  /* Logic: '<S327>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
   *  Logic: '<S268>/Logical Operator2'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
     ->SCS_GearShiftLeverPstReqVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S268>/Logical Operator3' incorporates:
   *  Constant: '<S268>/sat3'
   */
  VIPM_SCSGrShftLvrPstnReqVld_flg = (KIPM_SCSGrShftLvrPstnReq_enum_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S268>/Switch' */
  if (rtb_LogicalOperator2_fz) {
    /* Switch: '<S268>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S268>/Switch' incorporates:
       *  DataTypeConversion: '<S268>/Data Type Conversion2'
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S268>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n1 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_GearShiftLeverPstReq;
    }

    /* End of Switch: '<S268>/Switch3' */
  } else {
    /* Switch: '<S268>/Switch' incorporates:
     *  Constant: '<S268>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n1 = KIPM_SCSGrShftLvrPstnReqDflt_enum;
  }

  /* End of Switch: '<S268>/Switch' */

  /* Switch: '<S268>/Switch4' incorporates:
   *  Constant: '<S268>/sat3'
   */
  if (KIPM_SCSGrShftLvrPstnReq_enum_ovrdflg) {
    /* Switch: '<S268>/Switch4' incorporates:
     *  Constant: '<S268>/sat4'
     */
    VIPM_SCSGrShftLvrPstnReq_enum = KIPM_SCSGrShftLvrPstnReq_enum_ovrdval;
  } else {
    /* Switch: '<S268>/Switch4' incorporates:
     *  Switch: '<S268>/Switch'
     */
    VIPM_SCSGrShftLvrPstnReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n1;
  }

  /* End of Switch: '<S268>/Switch4' */
  /* End of Outputs for SubSystem: '<S267>/Subsys_VIPM_SCSGrShftLvrPstnReq_enum' */

  /* Outputs for Atomic SubSystem: '<S267>/Subsys_VIPM_SCSRghtSwVldty_flg' */
  /* Logic: '<S272>/Logical Operator3' incorporates:
   *  Constant: '<S272>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRghtSwVldtyVld_flg = (KIPM_SCSRghtSwVldty_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S272>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S272>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S272>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S272>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcv =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_RightSwtVD;
    }

    /* End of Switch: '<S272>/Switch3' */
  } else {
    /* Switch: '<S272>/Switch' incorporates:
     *  Constant: '<S272>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcv = KIPM_SCSRghtSwVldtyDflt_flg;
  }

  /* End of Switch: '<S272>/Switch' */

  /* Switch: '<S272>/Switch4' incorporates:
   *  Constant: '<S272>/sat3'
   */
  if (KIPM_SCSRghtSwVldty_flg_ovrdflg) {
    /* Switch: '<S272>/Switch4' incorporates:
     *  Constant: '<S272>/sat4'
     */
    VIPM_SCSRghtSwVldty_flg = KIPM_SCSRghtSwVldty_flg_ovrdval;
  } else {
    /* Switch: '<S272>/Switch4' */
    VIPM_SCSRghtSwVldty_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pcv;
  }

  /* End of Switch: '<S272>/Switch4' */
  /* End of Outputs for SubSystem: '<S267>/Subsys_VIPM_SCSRghtSwVldty_flg' */

  /* Outputs for Atomic SubSystem: '<S267>/Subsys_VIPM_SCSRght11Sw_flg' */
  /* Logic: '<S269>/Logical Operator3' incorporates:
   *  Constant: '<S269>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRght11SwVld_flg = (KIPM_SCSRght11Sw_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S269>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S269>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S269>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S269>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jyd =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_Right_11Swt;
    }

    /* End of Switch: '<S269>/Switch3' */
  } else {
    /* Switch: '<S269>/Switch' incorporates:
     *  Constant: '<S269>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jyd = KIPM_SCSRght11SwDflt_flg;
  }

  /* End of Switch: '<S269>/Switch' */

  /* Switch: '<S269>/Switch4' incorporates:
   *  Constant: '<S269>/sat3'
   */
  if (KIPM_SCSRght11Sw_flg_ovrdflg) {
    /* Switch: '<S269>/Switch4' incorporates:
     *  Constant: '<S269>/sat4'
     */
    VIPM_SCSRght11Sw_flg = KIPM_SCSRght11Sw_flg_ovrdval;
  } else {
    /* Switch: '<S269>/Switch4' */
    VIPM_SCSRght11Sw_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jyd;
  }

  /* End of Switch: '<S269>/Switch4' */
  /* End of Outputs for SubSystem: '<S267>/Subsys_VIPM_SCSRght11Sw_flg' */

  /* Outputs for Atomic SubSystem: '<S267>/Subsys_VIPM_SCSRght12Sw_flg' */
  /* Logic: '<S270>/Logical Operator3' incorporates:
   *  Constant: '<S270>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRght12SwVld_flg = (KIPM_SCSRght12Sw_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S270>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S270>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S270>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S270>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ka =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_Right_12Swt;
    }

    /* End of Switch: '<S270>/Switch3' */
  } else {
    /* Switch: '<S270>/Switch' incorporates:
     *  Constant: '<S270>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ka = KIPM_SCSRght12SwDflt_flg;
  }

  /* End of Switch: '<S270>/Switch' */

  /* Switch: '<S270>/Switch4' incorporates:
   *  Constant: '<S270>/sat3'
   */
  if (KIPM_SCSRght12Sw_flg_ovrdflg) {
    /* Switch: '<S270>/Switch4' incorporates:
     *  Constant: '<S270>/sat4'
     */
    VIPM_SCSRght12Sw_flg = KIPM_SCSRght12Sw_flg_ovrdval;
  } else {
    /* Switch: '<S270>/Switch4' */
    VIPM_SCSRght12Sw_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ka;
  }

  /* End of Switch: '<S270>/Switch4' */
  /* End of Outputs for SubSystem: '<S267>/Subsys_VIPM_SCSRght12Sw_flg' */

  /* Outputs for Atomic SubSystem: '<S267>/Subsys_VIPM_SCSRght13Sw_flg' */
  /* Logic: '<S271>/Logical Operator3' incorporates:
   *  Constant: '<S271>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSRght13SwVld_flg = (KIPM_SCSRght13Sw_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S271>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S271>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SCS_RiSwitchSts_CRCFlt_flg) {
      /* Switch: '<S271>/Switch' incorporates:
       *  Inport: '<Root>/SCS_RiSwitchSts_BOD'
       *  Switch: '<S271>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_el =
        (Rte_IRead_Runbl_IpmCanRx_20ms_SCS_RiSwitchSts_BOD_SCS_RiSwitchSts_BOD())
        ->SCS_Right_13Swt;
    }

    /* End of Switch: '<S271>/Switch3' */
  } else {
    /* Switch: '<S271>/Switch' incorporates:
     *  Constant: '<S271>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_el = KIPM_SCSRght13SwDflt_flg;
  }

  /* End of Switch: '<S271>/Switch' */

  /* Switch: '<S271>/Switch4' incorporates:
   *  Constant: '<S271>/sat3'
   */
  if (KIPM_SCSRght13Sw_flg_ovrdflg) {
    /* Switch: '<S271>/Switch4' incorporates:
     *  Constant: '<S271>/sat4'
     */
    VIPM_SCSRght13Sw_flg = KIPM_SCSRght13Sw_flg_ovrdval;
  } else {
    /* Switch: '<S271>/Switch4' */
    VIPM_SCSRght13Sw_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_el;
  }

  /* End of Switch: '<S271>/Switch4' */
  /* End of Outputs for SubSystem: '<S267>/Subsys_VIPM_SCSRght13Sw_flg' */

  /* BusCreator: '<S267>/BusCreator1' incorporates:
   *  DataTypeConversion: '<S267>/Data Type Conversion3'
   *  Logic: '<S268>/Logical Operator3'
   *  Logic: '<S269>/Logical Operator3'
   *  Logic: '<S270>/Logical Operator3'
   *  Logic: '<S271>/Logical Operator3'
   *  Logic: '<S272>/Logical Operator3'
   *  Switch: '<S268>/Switch4'
   *  Switch: '<S269>/Switch4'
   *  Switch: '<S270>/Switch4'
   *  Switch: '<S271>/Switch4'
   *  Switch: '<S272>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSGrShftLvrPstnReq_enum =
    VIPM_SCSGrShftLvrPstnReq_enum;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSGrShftLvrPstnReqVld_flg =
    VIPM_SCSGrShftLvrPstnReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRghtSwVldty_flg =
    VIPM_SCSRghtSwVldty_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRghtSwVldtyVld_flg =
    VIPM_SCSRghtSwVldtyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRght11Sw_flg =
    VIPM_SCSRght11Sw_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRght11SwVld_flg =
    VIPM_SCSRght11SwVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRght12Sw_flg =
    VIPM_SCSRght12Sw_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRght12SwVld_flg =
    VIPM_SCSRght12SwVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRght13Sw_flg =
    VIPM_SCSRght13Sw_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l.VIPM_SCSRght13SwVld_flg =
    VIPM_SCSRght13SwVld_flg;

  /* Outputs for Atomic SubSystem: '<S273>/Subsys_VIPM_CRRRBSDWarnLt_enum' */
  /* Logic: '<S276>/Logical Operator3' incorporates:
   *  Constant: '<S276>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRBSDWarnLtVld_flg = (KIPM_CRRRBSDWarnLt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S276>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S276>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S276>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S276>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ows =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_BSD_Warn_Left;
    }

    /* End of Switch: '<S276>/Switch3' */
  } else {
    /* Switch: '<S276>/Switch' incorporates:
     *  Constant: '<S276>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ows = KIPM_CRRRBSDWarnLtDflt_enum;
  }

  /* End of Switch: '<S276>/Switch' */

  /* Switch: '<S276>/Switch4' incorporates:
   *  Constant: '<S276>/sat3'
   */
  if (KIPM_CRRRBSDWarnLt_enum_ovrdflg) {
    /* Switch: '<S276>/Switch4' incorporates:
     *  Constant: '<S276>/sat4'
     */
    VIPM_CRRRBSDWarnLt_enum = KIPM_CRRRBSDWarnLt_enum_ovrdval;
  } else {
    /* Switch: '<S276>/Switch4' */
    VIPM_CRRRBSDWarnLt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ows;
  }

  /* End of Switch: '<S276>/Switch4' */
  /* End of Outputs for SubSystem: '<S273>/Subsys_VIPM_CRRRBSDWarnLt_enum' */

  /* Outputs for Atomic SubSystem: '<S273>/Subsys_VIPM_CRRRBSDWarnRt_enum' */
  /* Logic: '<S277>/Logical Operator3' incorporates:
   *  Constant: '<S277>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRBSDWarnRtVld_flg = (KIPM_CRRRBSDWarnRt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S277>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S277>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S277>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S277>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ki =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_BSD_Warn_Right;
    }

    /* End of Switch: '<S277>/Switch3' */
  } else {
    /* Switch: '<S277>/Switch' incorporates:
     *  Constant: '<S277>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ki = KIPM_CRRRBSDWarnRtDflt_enum;
  }

  /* End of Switch: '<S277>/Switch' */

  /* Switch: '<S277>/Switch4' incorporates:
   *  Constant: '<S277>/sat3'
   */
  if (KIPM_CRRRBSDWarnRt_enum_ovrdflg) {
    /* Switch: '<S277>/Switch4' incorporates:
     *  Constant: '<S277>/sat4'
     */
    VIPM_CRRRBSDWarnRt_enum = KIPM_CRRRBSDWarnRt_enum_ovrdval;
  } else {
    /* Switch: '<S277>/Switch4' */
    VIPM_CRRRBSDWarnRt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ki;
  }

  /* End of Switch: '<S277>/Switch4' */
  /* End of Outputs for SubSystem: '<S273>/Subsys_VIPM_CRRRBSDWarnRt_enum' */

  /* Outputs for Atomic SubSystem: '<S273>/Subsys_VIPM_CRRRDOWWarnLt_enum' */
  /* Logic: '<S278>/Logical Operator3' incorporates:
   *  Constant: '<S278>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRDOWWarnLtVld_flg = (KIPM_CRRRDOWWarnLt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S278>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S278>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S278>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S278>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ms =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_DOW_Warn_Left;
    }

    /* End of Switch: '<S278>/Switch3' */
  } else {
    /* Switch: '<S278>/Switch' incorporates:
     *  Constant: '<S278>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ms = KIPM_CRRRDOWWarnLtDflt_enum;
  }

  /* End of Switch: '<S278>/Switch' */

  /* Switch: '<S278>/Switch4' incorporates:
   *  Constant: '<S278>/sat3'
   */
  if (KIPM_CRRRDOWWarnLt_enum_ovrdflg) {
    /* Switch: '<S278>/Switch4' incorporates:
     *  Constant: '<S278>/sat4'
     */
    VIPM_CRRRDOWWarnLt_enum = KIPM_CRRRDOWWarnLt_enum_ovrdval;
  } else {
    /* Switch: '<S278>/Switch4' */
    VIPM_CRRRDOWWarnLt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ms;
  }

  /* End of Switch: '<S278>/Switch4' */
  /* End of Outputs for SubSystem: '<S273>/Subsys_VIPM_CRRRDOWWarnLt_enum' */

  /* Outputs for Atomic SubSystem: '<S273>/Subsys_VIPM_CRRRDOWWarnRt_enum' */
  /* Logic: '<S279>/Logical Operator3' incorporates:
   *  Constant: '<S279>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRDOWWarnRtVld_flg = (KIPM_CRRRDOWWarnRt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S279>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S279>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S279>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S279>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hg =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_DOW_Warn_Right;
    }

    /* End of Switch: '<S279>/Switch3' */
  } else {
    /* Switch: '<S279>/Switch' incorporates:
     *  Constant: '<S279>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hg = KIPM_CRRRDOWWarnRtDflt_enum;
  }

  /* End of Switch: '<S279>/Switch' */

  /* Switch: '<S279>/Switch4' incorporates:
   *  Constant: '<S279>/sat3'
   */
  if (KIPM_CRRRDOWWarnRt_enum_ovrdflg) {
    /* Switch: '<S279>/Switch4' incorporates:
     *  Constant: '<S279>/sat4'
     */
    VIPM_CRRRDOWWarnRt_enum = KIPM_CRRRDOWWarnRt_enum_ovrdval;
  } else {
    /* Switch: '<S279>/Switch4' */
    VIPM_CRRRDOWWarnRt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hg;
  }

  /* End of Switch: '<S279>/Switch4' */
  /* End of Outputs for SubSystem: '<S273>/Subsys_VIPM_CRRRDOWWarnRt_enum' */

  /* Outputs for Atomic SubSystem: '<S273>/Subsys_VIPM_CRRRRCTAWarnLt_enum' */
  /* Logic: '<S280>/Logical Operator3' incorporates:
   *  Constant: '<S280>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRRCTAWarnLtVld_flg = (KIPM_CRRRRCTAWarnLt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S280>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S280>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S280>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S280>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hf =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_RCTA_Warn_Left;
    }

    /* End of Switch: '<S280>/Switch3' */
  } else {
    /* Switch: '<S280>/Switch' incorporates:
     *  Constant: '<S280>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hf = KIPM_CRRRRCTAWarnLtDflt_enum;
  }

  /* End of Switch: '<S280>/Switch' */

  /* Switch: '<S280>/Switch4' incorporates:
   *  Constant: '<S280>/sat3'
   */
  if (KIPM_CRRRRCTAWarnLt_enum_ovrdflg) {
    /* Switch: '<S280>/Switch4' incorporates:
     *  Constant: '<S280>/sat4'
     */
    VIPM_CRRRRCTAWarnLt_enum = KIPM_CRRRRCTAWarnLt_enum_ovrdval;
  } else {
    /* Switch: '<S280>/Switch4' */
    VIPM_CRRRRCTAWarnLt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_hf;
  }

  /* End of Switch: '<S280>/Switch4' */
  /* End of Outputs for SubSystem: '<S273>/Subsys_VIPM_CRRRRCTAWarnLt_enum' */

  /* Outputs for Atomic SubSystem: '<S273>/Subsys_VIPM_CRRRRCTAWarnRt_enum' */
  /* Logic: '<S281>/Logical Operator3' incorporates:
   *  Constant: '<S281>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CRRRRCTAWarnRtVld_flg = (KIPM_CRRRRCTAWarnRt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_CRRRMsgActv_flg);

  /* Switch: '<S281>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_CRRRMsgActv_flg) {
    /* Switch: '<S281>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CRRR_A_CRCFlt_flg) {
      /* Switch: '<S281>/Switch' incorporates:
       *  Inport: '<Root>/CRRR_A_CHA'
       *  Switch: '<S281>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m =
        (Rte_IRead_Runbl_IpmCanRx_20ms_CRRR_A_CHA_CRRR_A_CHA())
        ->CRRR_RCTA_Warn_Right;
    }

    /* End of Switch: '<S281>/Switch3' */
  } else {
    /* Switch: '<S281>/Switch' incorporates:
     *  Constant: '<S281>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m = KIPM_CRRRRCTAWarnRtDflt_enum;
  }

  /* End of Switch: '<S281>/Switch' */

  /* Switch: '<S281>/Switch4' incorporates:
   *  Constant: '<S281>/sat3'
   */
  if (KIPM_CRRRRCTAWarnRt_enum_ovrdflg) {
    /* Switch: '<S281>/Switch4' incorporates:
     *  Constant: '<S281>/sat4'
     */
    VIPM_CRRRRCTAWarnRt_enum = KIPM_CRRRRCTAWarnRt_enum_ovrdval;
  } else {
    /* Switch: '<S281>/Switch4' */
    VIPM_CRRRRCTAWarnRt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m;
  }

  /* End of Switch: '<S281>/Switch4' */
  /* End of Outputs for SubSystem: '<S273>/Subsys_VIPM_CRRRRCTAWarnRt_enum' */

  /* BusCreator: '<S273>/BusCreator' incorporates:
   *  Logic: '<S276>/Logical Operator3'
   *  Logic: '<S277>/Logical Operator3'
   *  Logic: '<S278>/Logical Operator3'
   *  Logic: '<S279>/Logical Operator3'
   *  Logic: '<S280>/Logical Operator3'
   *  Logic: '<S281>/Logical Operator3'
   *  Switch: '<S276>/Switch4'
   *  Switch: '<S277>/Switch4'
   *  Switch: '<S278>/Switch4'
   *  Switch: '<S279>/Switch4'
   *  Switch: '<S280>/Switch4'
   *  Switch: '<S281>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRBSDWarnLt_enum =
    VIPM_CRRRBSDWarnLt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRBSDWarnLtVld_flg =
    VIPM_CRRRBSDWarnLtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRBSDWarnRt_enum =
    VIPM_CRRRBSDWarnRt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRBSDWarnRtVld_flg =
    VIPM_CRRRBSDWarnRtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRDOWWarnLt_enum =
    VIPM_CRRRDOWWarnLt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRDOWWarnLtVld_flg =
    VIPM_CRRRDOWWarnLtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRDOWWarnRt_enum =
    VIPM_CRRRDOWWarnRt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRDOWWarnRtVld_flg =
    VIPM_CRRRDOWWarnRtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRRCTAWarnLt_enum =
    VIPM_CRRRRCTAWarnLt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRRCTAWarnLtVld_flg =
    VIPM_CRRRRCTAWarnLtVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRRCTAWarnRt_enum =
    VIPM_CRRRRCTAWarnRt_enum;
  AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h.VIPM_CRRRRCTAWarnRtVld_flg =
    VIPM_CRRRRCTAWarnRtVld_flg;

  /* Outputs for Atomic SubSystem: '<S274>/Subsys_VIPM_EHBEPBActuatorStL_enum' */
  /* Logic: '<S284>/Logical Operator3' incorporates:
   *  Constant: '<S284>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBActuatorStLVld_flg = (KIPM_EHBEPBActuatorStL_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S284>/Switch4' incorporates:
   *  Constant: '<S284>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S284>/Switch'
   */
  if (KIPM_EHBEPBActuatorStL_enum_ovrdflg) {
    /* Switch: '<S284>/Switch4' incorporates:
     *  Constant: '<S284>/sat4'
     */
    VIPM_EHBEPBActuatorStL_enum = KIPM_EHBEPBActuatorStL_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S284>/Switch4' incorporates:
     *  DataTypeConversion: '<S284>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S284>/Switch'
     */
    VIPM_EHBEPBActuatorStL_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())
      ->EHB_EPB_ActuatorSt_L;
  } else {
    /* Switch: '<S284>/Switch4' incorporates:
     *  Constant: '<S284>/sat5'
     *  Switch: '<S284>/Switch'
     */
    VIPM_EHBEPBActuatorStL_enum = KIPM_EHBEPBActuatorStLDflt_enum;
  }

  /* End of Switch: '<S284>/Switch4' */
  /* End of Outputs for SubSystem: '<S274>/Subsys_VIPM_EHBEPBActuatorStL_enum' */

  /* Outputs for Atomic SubSystem: '<S274>/Subsys_VIPM_EHBEPBSwitchSts_enum' */
  /* Logic: '<S285>/Logical Operator3' incorporates:
   *  Constant: '<S285>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBSwitchStsVld_flg = (KIPM_EHBEPBSwitchSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S285>/Switch4' incorporates:
   *  Constant: '<S285>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S285>/Switch'
   */
  if (KIPM_EHBEPBSwitchSts_enum_ovrdflg) {
    /* Switch: '<S285>/Switch4' incorporates:
     *  Constant: '<S285>/sat4'
     */
    VIPM_EHBEPBSwitchSts_enum = KIPM_EHBEPBSwitchSts_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S285>/Switch4' incorporates:
     *  DataTypeConversion: '<S285>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S285>/Switch'
     */
    VIPM_EHBEPBSwitchSts_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())->EHB_EPB_SwitchSts;
  } else {
    /* Switch: '<S285>/Switch4' incorporates:
     *  Constant: '<S285>/sat5'
     *  Switch: '<S285>/Switch'
     */
    VIPM_EHBEPBSwitchSts_enum = KIPM_EHBEPBSwitchStsDflt_enum;
  }

  /* End of Switch: '<S285>/Switch4' */
  /* End of Outputs for SubSystem: '<S274>/Subsys_VIPM_EHBEPBSwitchSts_enum' */

  /* DataTypeConversion: '<S274>/Data Type Conversion1' incorporates:
   *  Switch: '<S285>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBEPBSwitchSts_enum =
    VIPM_EHBEPBSwitchSts_enum;

  /* Outputs for Atomic SubSystem: '<S274>/Subsys_VIPM_EHBEPBSysSt_enum' */
  /* Logic: '<S286>/Logical Operator3' incorporates:
   *  Constant: '<S286>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBEPBSysStVld_flg = (KIPM_EHBEPBSysSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S286>/Switch4' incorporates:
   *  Constant: '<S286>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S286>/Switch'
   */
  if (KIPM_EHBEPBSysSt_enum_ovrdflg) {
    /* Switch: '<S286>/Switch4' incorporates:
     *  Constant: '<S286>/sat4'
     */
    VIPM_EHBEPBSysSt_enum = KIPM_EHBEPBSysSt_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S286>/Switch4' incorporates:
     *  DataTypeConversion: '<S286>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S286>/Switch'
     */
    VIPM_EHBEPBSysSt_enum = (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())
      ->EHB_EPB_SystemState;
  } else {
    /* Switch: '<S286>/Switch4' incorporates:
     *  Constant: '<S286>/sat5'
     *  Switch: '<S286>/Switch'
     */
    VIPM_EHBEPBSysSt_enum = KIPM_EHBEPBSysStDflt_enum;
  }

  /* End of Switch: '<S286>/Switch4' */
  /* End of Outputs for SubSystem: '<S274>/Subsys_VIPM_EHBEPBSysSt_enum' */

  /* DataTypeConversion: '<S274>/Data Type Conversion2' incorporates:
   *  Switch: '<S286>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBEPBSysSt_enum =
    VIPM_EHBEPBSysSt_enum;

  /* Outputs for Atomic SubSystem: '<S274>/Subsys_VIPM_EHBHDCFucFault_flg' */
  /* Logic: '<S287>/Logical Operator3' incorporates:
   *  Constant: '<S287>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBHDCFucFaultVld_flg = (KIPM_EHBHDCFucFault_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S287>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S287>/Switch' incorporates:
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S287>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ie =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())->EHB_HDCFucFault;
  } else {
    /* Switch: '<S287>/Switch' incorporates:
     *  Constant: '<S287>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ie = KIPM_EHBHDCFucFaultDflt_flg;
  }

  /* End of Switch: '<S287>/Switch' */

  /* Switch: '<S287>/Switch4' incorporates:
   *  Constant: '<S287>/sat3'
   */
  if (KIPM_EHBHDCFucFault_flg_ovrdflg) {
    /* Switch: '<S287>/Switch4' incorporates:
     *  Constant: '<S287>/sat4'
     */
    VIPM_EHBHDCFucFault_flg = KIPM_EHBHDCFucFault_flg_ovrdval;
  } else {
    /* Switch: '<S287>/Switch4' */
    VIPM_EHBHDCFucFault_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ie;
  }

  /* End of Switch: '<S287>/Switch4' */
  /* End of Outputs for SubSystem: '<S274>/Subsys_VIPM_EHBHDCFucFault_flg' */

  /* Outputs for Atomic SubSystem: '<S274>/Subsys_VIPM_EHBAVHAppldSt_enum' */
  /* Logic: '<S282>/Logical Operator3' incorporates:
   *  Constant: '<S282>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBAVHAppldStVld_flg = (KIPM_EHBAVHAppldSt_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_EHBMsgActv_flg);

  /* Switch: '<S282>/Switch4' incorporates:
   *  Constant: '<S282>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S282>/Switch'
   */
  if (KIPM_EHBAVHAppldSt_enum_ovrdflg) {
    /* Switch: '<S282>/Switch4' incorporates:
     *  Constant: '<S282>/sat4'
     */
    VIPM_EHBAVHAppldSt_enum = KIPM_EHBAVHAppldSt_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S282>/Switch4' incorporates:
     *  DataTypeConversion: '<S282>/Data Type Conversion2'
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S282>/Switch'
     */
    VIPM_EHBAVHAppldSt_enum = (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA
      ())->EHB_AVHAppldSt;
  } else {
    /* Switch: '<S282>/Switch4' incorporates:
     *  Constant: '<S282>/sat5'
     *  Switch: '<S282>/Switch'
     */
    VIPM_EHBAVHAppldSt_enum = KIPM_EHBAVHAppldStDflt_enum;
  }

  /* End of Switch: '<S282>/Switch4' */
  /* End of Outputs for SubSystem: '<S274>/Subsys_VIPM_EHBAVHAppldSt_enum' */

  /* Outputs for Atomic SubSystem: '<S274>/Subsys_VIPM_EHBBLA_flg' */
  /* Logic: '<S283>/Logical Operator3' incorporates:
   *  Constant: '<S283>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_EHBBLAVld_flg = (KIPM_EHBBLA_flg_ovrdflg ||
                        (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV()
                        )->VIPM_EHBMsgActv_flg);

  /* Switch: '<S283>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_EHBMsgActv_flg) {
    /* Switch: '<S283>/Switch' incorporates:
     *  Inport: '<Root>/EHB_A_CHA'
     *  Switch: '<S283>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mg =
      (Rte_IRead_Runbl_IpmCanRx_20ms_EHB_A_CHA_EHB_A_CHA())->EHB_BLA;
  } else {
    /* Switch: '<S283>/Switch' incorporates:
     *  Constant: '<S283>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mg = KIPM_EHBBLADflt_flg;
  }

  /* End of Switch: '<S283>/Switch' */

  /* Switch: '<S283>/Switch4' incorporates:
   *  Constant: '<S283>/sat3'
   */
  if (KIPM_EHBBLA_flg_ovrdflg) {
    /* Switch: '<S283>/Switch4' incorporates:
     *  Constant: '<S283>/sat4'
     */
    VIPM_EHBBLA_flg = KIPM_EHBBLA_flg_ovrdval;
  } else {
    /* Switch: '<S283>/Switch4' */
    VIPM_EHBBLA_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_mg;
  }

  /* End of Switch: '<S283>/Switch4' */
  /* End of Outputs for SubSystem: '<S274>/Subsys_VIPM_EHBBLA_flg' */

  /* BusCreator: '<S274>/BusCreator' incorporates:
   *  DataTypeConversion: '<S274>/Data Type Conversion'
   *  DataTypeConversion: '<S274>/Data Type Conversion3'
   *  Logic: '<S282>/Logical Operator3'
   *  Logic: '<S283>/Logical Operator3'
   *  Logic: '<S284>/Logical Operator3'
   *  Logic: '<S285>/Logical Operator3'
   *  Logic: '<S286>/Logical Operator3'
   *  Logic: '<S287>/Logical Operator3'
   *  Switch: '<S282>/Switch4'
   *  Switch: '<S283>/Switch4'
   *  Switch: '<S284>/Switch4'
   *  Switch: '<S287>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBEPBActuatorStL_enum =
    VIPM_EHBEPBActuatorStL_enum;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBEPBActuatorStLVld_flg =
    VIPM_EHBEPBActuatorStLVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBEPBSwitchStsVld_flg =
    VIPM_EHBEPBSwitchStsVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBEPBSysStVld_flg =
    VIPM_EHBEPBSysStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBHDCFucFault_flg =
    VIPM_EHBHDCFucFault_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBHDCFucFaultVld_flg =
    VIPM_EHBHDCFucFaultVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBAVHAppldSt_enum =
    VIPM_EHBAVHAppldSt_enum;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBAVHAppldStVld_flg =
    VIPM_EHBAVHAppldStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBBLA_flg = VIPM_EHBBLA_flg;
  AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l.VIPM_EHBBLAVld_flg = VIPM_EHBBLAVld_flg;

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMACCWhlTqReqActv_flg' */
  /* Logic: '<S290>/Logical Operator3' incorporates:
   *  Constant: '<S290>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCWhlTqReqActvVld_flg = (KIPM_FCMACCWhlTqReqActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S290>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S290>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S290>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S290>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ep =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_ACCWhlTqReqActv;
    }

    /* End of Switch: '<S290>/Switch3' */
  } else {
    /* Switch: '<S290>/Switch' incorporates:
     *  Constant: '<S290>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ep = KIPM_FCMACCWhlTqReqActvDflt_flg;
  }

  /* End of Switch: '<S290>/Switch' */

  /* Switch: '<S290>/Switch4' incorporates:
   *  Constant: '<S290>/sat3'
   */
  if (KIPM_FCMACCWhlTqReqActv_flg_ovrdflg) {
    /* Switch: '<S290>/Switch4' incorporates:
     *  Constant: '<S290>/sat4'
     */
    VIPM_FCMACCWhlTqReqActv_flg = KIPM_FCMACCWhlTqReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S290>/Switch4' */
    VIPM_FCMACCWhlTqReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ep;
  }

  /* End of Switch: '<S290>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMACCWhlTqReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMACCWhlTqReqVal_Nm' */
  /* Logic: '<S291>/Logical Operator3' incorporates:
   *  Constant: '<S291>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCWhlTqReqValVld_flg = (KIPM_FCMACCWhlTqReqVal_Nm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S291>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S291>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Product: '<S302>/Product' incorporates:
       *  Constant: '<S302>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_f0 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_ACCWhlTqReqVal * 0.5F;

      /* Switch: '<S291>/Switch' incorporates:
       *  Sum: '<S302>/Add'
       *  Switch: '<S291>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f = rtb_Product_f0 - 6200.0F;
    }

    /* End of Switch: '<S291>/Switch3' */
  } else {
    /* Switch: '<S291>/Switch' incorporates:
     *  Constant: '<S291>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f = KIPM_FCMACCWhlTqReqValDflt_Nm;
  }

  /* End of Switch: '<S291>/Switch' */

  /* Switch: '<S291>/Switch4' incorporates:
   *  Constant: '<S291>/sat3'
   *  Constant: '<S291>/sat4'
   */
  if (KIPM_FCMACCWhlTqReqVal_Nm_ovrdflg) {
    VIPM_FCMACCWhlTqReqVal_Nm = KIPM_FCMACCWhlTqReqVal_Nm_ovrdval;
  } else {
    VIPM_FCMACCWhlTqReqVal_Nm = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f;
  }

  /* MinMax: '<S291>/MinMax' incorporates:
   *  Constant: '<S291>/sat6'
   *  Switch: '<S291>/Switch4'
   */
  if (VIPM_FCMACCWhlTqReqVal_Nm > KIPM_FCMACCWhlTqReqValHi_Nm) {
    VIPM_FCMACCWhlTqReqVal_Nm = KIPM_FCMACCWhlTqReqValHi_Nm;
  }

  /* End of MinMax: '<S291>/MinMax' */

  /* MinMax: '<S291>/MinMax1' incorporates:
   *  Constant: '<S291>/sat7'
   */
  if (VIPM_FCMACCWhlTqReqVal_Nm < KIPM_FCMACCWhlTqReqValLo_Nm) {
    /* Switch: '<S291>/Switch4' incorporates:
     *  MinMax: '<S291>/MinMax1'
     */
    VIPM_FCMACCWhlTqReqVal_Nm = KIPM_FCMACCWhlTqReqValLo_Nm;
  }

  /* End of MinMax: '<S291>/MinMax1' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMACCWhlTqReqVal_Nm' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMACCWhlDece_mps2' */
  /* Logic: '<S289>/Logical Operator3' incorporates:
   *  Constant: '<S289>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCWhlDeceVld_flg = (KIPM_FCMACCWhlDece_mps2_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S289>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S289>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Product: '<S303>/Product' incorporates:
       *  Constant: '<S303>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_f0 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_ACCWhlDece *
        0.05F;

      /* Switch: '<S289>/Switch' incorporates:
       *  Sum: '<S303>/Add'
       *  Switch: '<S289>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o = rtb_Product_f0 - 9.5F;
    }

    /* End of Switch: '<S289>/Switch3' */
  } else {
    /* Switch: '<S289>/Switch' incorporates:
     *  Constant: '<S289>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o = KIPM_FCMACCWhlDeceDflt_mps2;
  }

  /* End of Switch: '<S289>/Switch' */

  /* Switch: '<S289>/Switch4' incorporates:
   *  Constant: '<S289>/sat3'
   *  Constant: '<S289>/sat4'
   */
  if (KIPM_FCMACCWhlDece_mps2_ovrdflg) {
    VIPM_FCMACCWhlDece_mps2 = KIPM_FCMACCWhlDece_mps2_ovrdval;
  } else {
    VIPM_FCMACCWhlDece_mps2 = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_o;
  }

  /* MinMax: '<S289>/MinMax' incorporates:
   *  Constant: '<S289>/sat6'
   *  Switch: '<S289>/Switch4'
   */
  if (VIPM_FCMACCWhlDece_mps2 > KIPM_FCMACCWhlDeceHi_mps2) {
    VIPM_FCMACCWhlDece_mps2 = KIPM_FCMACCWhlDeceHi_mps2;
  }

  /* End of MinMax: '<S289>/MinMax' */

  /* MinMax: '<S289>/MinMax1' incorporates:
   *  Constant: '<S289>/sat7'
   */
  if (VIPM_FCMACCWhlDece_mps2 < KIPM_FCMACCWhlDeceLo_mps2) {
    /* Switch: '<S289>/Switch4' incorporates:
     *  MinMax: '<S289>/MinMax1'
     */
    VIPM_FCMACCWhlDece_mps2 = KIPM_FCMACCWhlDeceLo_mps2;
  }

  /* End of MinMax: '<S289>/MinMax1' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMACCWhlDece_mps2' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccTarAccrnReqActv_flg' */
  /* Logic: '<S296>/Logical Operator3' incorporates:
   *  Constant: '<S296>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTarAccrnReqActvVld_flg = (KIPM_FCMAccTarAccrnReqActv_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S296>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S296>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S296>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S296>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2f =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_AccTarAccrnReqActv;
    }

    /* End of Switch: '<S296>/Switch3' */
  } else {
    /* Switch: '<S296>/Switch' incorporates:
     *  Constant: '<S296>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2f = KIPM_FCMAccTarAccrnReqActvDflt_flg;
  }

  /* End of Switch: '<S296>/Switch' */

  /* Switch: '<S296>/Switch4' incorporates:
   *  Constant: '<S296>/sat3'
   */
  if (KIPM_FCMAccTarAccrnReqActv_flg_ovrdflg) {
    /* Switch: '<S296>/Switch4' incorporates:
     *  Constant: '<S296>/sat4'
     */
    VIPM_FCMAccTarAccrnReqActv_flg = KIPM_FCMAccTarAccrnReqActv_flg_ovrdval;
  } else {
    /* Switch: '<S296>/Switch4' */
    VIPM_FCMAccTarAccrnReqActv_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_m2f;
  }

  /* End of Switch: '<S296>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccTarAccrnReqActv_flg' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccTarAccrn_mps2' */
  /* Logic: '<S297>/Logical Operator3' incorporates:
   *  Constant: '<S297>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTarAccrnVld_flg = (KIPM_FCMAccTarAccrn_mps2_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S297>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S297>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Product: '<S304>/Product' incorporates:
       *  Constant: '<S304>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_f0 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccTarAccrn *
        0.05F;

      /* Switch: '<S297>/Switch' incorporates:
       *  Sum: '<S304>/Add'
       *  Switch: '<S297>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_j = rtb_Product_f0 - 5.0F;
    }

    /* End of Switch: '<S297>/Switch3' */
  } else {
    /* Switch: '<S297>/Switch' incorporates:
     *  Constant: '<S297>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_j = KIPM_FCMAccTarAccrnDflt_mps2;
  }

  /* End of Switch: '<S297>/Switch' */

  /* Switch: '<S297>/Switch4' incorporates:
   *  Constant: '<S297>/sat3'
   *  Constant: '<S297>/sat4'
   */
  if (KIPM_FCMAccTarAccrn_mps2_ovrdflg) {
    VIPM_FCMAccTarAccrn_mps2 = KIPM_FCMAccTarAccrn_mps2_ovrdval;
  } else {
    VIPM_FCMAccTarAccrn_mps2 = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_j;
  }

  /* MinMax: '<S297>/MinMax' incorporates:
   *  Constant: '<S297>/sat6'
   *  Switch: '<S297>/Switch4'
   */
  if (VIPM_FCMAccTarAccrn_mps2 > KIPM_FCMAccTarAccrnHi_mps2) {
    VIPM_FCMAccTarAccrn_mps2 = KIPM_FCMAccTarAccrnHi_mps2;
  }

  /* End of MinMax: '<S297>/MinMax' */

  /* MinMax: '<S297>/MinMax1' incorporates:
   *  Constant: '<S297>/sat7'
   */
  if (VIPM_FCMAccTarAccrn_mps2 < KIPM_FCMAccTarAccrnLo_mps2) {
    /* Switch: '<S297>/Switch4' incorporates:
     *  MinMax: '<S297>/MinMax1'
     */
    VIPM_FCMAccTarAccrn_mps2 = KIPM_FCMAccTarAccrnLo_mps2;
  }

  /* End of MinMax: '<S297>/MinMax1' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccTarAccrn_mps2' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMEPBReq_enum' */
  /* Logic: '<S327>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/FCM_B_CHA'
   *  Logic: '<S300>/Logical Operator2'
   */
  rtb_LogicalOperator2_fz = ((Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
    ->FCM_EPBReqV && (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
    ->VIPM_FCMMsgActv_flg);

  /* Logic: '<S300>/Logical Operator3' incorporates:
   *  Constant: '<S300>/sat3'
   */
  VIPM_FCMEPBReqVld_flg = (KIPM_FCMEPBReq_enum_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S300>/Switch' */
  if (rtb_LogicalOperator2_fz) {
    /* Switch: '<S300>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S300>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S300>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pi =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_EPBReq;
    }

    /* End of Switch: '<S300>/Switch3' */
  } else {
    /* Switch: '<S300>/Switch' incorporates:
     *  Constant: '<S300>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pi = KIPM_FCMEPBReqDflt_enum;
  }

  /* End of Switch: '<S300>/Switch' */

  /* Switch: '<S300>/Switch4' incorporates:
   *  Constant: '<S300>/sat3'
   */
  if (KIPM_FCMEPBReq_enum_ovrdflg) {
    /* Switch: '<S300>/Switch4' incorporates:
     *  Constant: '<S300>/sat4'
     */
    VIPM_FCMEPBReq_enum = KIPM_FCMEPBReq_enum_ovrdval;
  } else {
    /* Switch: '<S300>/Switch4' */
    VIPM_FCMEPBReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pi;
  }

  /* End of Switch: '<S300>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMEPBReq_enum' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccTgtAxReq_flg' */
  /* Logic: '<S298>/Logical Operator3' incorporates:
   *  Constant: '<S298>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTgtAxReqVld_flg = (KIPM_FCMAccTgtAxReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S298>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S298>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S298>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S298>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cb =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccTgtAxReq;
    }

    /* End of Switch: '<S298>/Switch3' */
  } else {
    /* Switch: '<S298>/Switch' incorporates:
     *  Constant: '<S298>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cb = KIPM_FCMAccTgtAxReqDflt_flg;
  }

  /* End of Switch: '<S298>/Switch' */

  /* Switch: '<S298>/Switch4' incorporates:
   *  Constant: '<S298>/sat3'
   */
  if (KIPM_FCMAccTgtAxReq_flg_ovrdflg) {
    /* Switch: '<S298>/Switch4' incorporates:
     *  Constant: '<S298>/sat4'
     */
    VIPM_FCMAccTgtAxReq_flg = KIPM_FCMAccTgtAxReq_flg_ovrdval;
  } else {
    /* Switch: '<S298>/Switch4' */
    VIPM_FCMAccTgtAxReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cb;
  }

  /* End of Switch: '<S298>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccTgtAxReq_flg' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccTgtAx_mps2' */
  /* Logic: '<S299>/Logical Operator3' incorporates:
   *  Constant: '<S299>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccTgtAxVld_flg = (KIPM_FCMAccTgtAx_mps2_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S299>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S299>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Product: '<S305>/Product' incorporates:
       *  Constant: '<S305>/Constant'
       *  Inport: '<Root>/FCM_B_CHA'
       */
      rtb_Product_f0 = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccTgtAx *
        0.05F;

      /* Switch: '<S299>/Switch' incorporates:
       *  Sum: '<S305>/Add'
       *  Switch: '<S299>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e = rtb_Product_f0 - 9.5F;
    }

    /* End of Switch: '<S299>/Switch3' */
  } else {
    /* Switch: '<S299>/Switch' incorporates:
     *  Constant: '<S299>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e = KIPM_FCMAccTgtAxDflt_mps2;
  }

  /* End of Switch: '<S299>/Switch' */

  /* Switch: '<S299>/Switch4' incorporates:
   *  Constant: '<S299>/sat3'
   *  Constant: '<S299>/sat4'
   */
  if (KIPM_FCMAccTgtAx_mps2_ovrdflg) {
    VIPM_FCMAccTgtAx_mps2 = KIPM_FCMAccTgtAx_mps2_ovrdval;
  } else {
    VIPM_FCMAccTgtAx_mps2 = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e;
  }

  /* MinMax: '<S299>/MinMax' incorporates:
   *  Constant: '<S299>/sat6'
   *  Switch: '<S299>/Switch4'
   */
  if (VIPM_FCMAccTgtAx_mps2 > KIPM_FCMAccTgtAxHi_mps2) {
    VIPM_FCMAccTgtAx_mps2 = KIPM_FCMAccTgtAxHi_mps2;
  }

  /* End of MinMax: '<S299>/MinMax' */

  /* MinMax: '<S299>/MinMax1' incorporates:
   *  Constant: '<S299>/sat7'
   */
  if (VIPM_FCMAccTgtAx_mps2 < KIPM_FCMAccTgtAxLo_mps2) {
    /* Switch: '<S299>/Switch4' incorporates:
     *  MinMax: '<S299>/MinMax1'
     */
    VIPM_FCMAccTgtAx_mps2 = KIPM_FCMAccTgtAxLo_mps2;
  }

  /* End of MinMax: '<S299>/MinMax1' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccTgtAx_mps2' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccReqStandstill_flg' */
  /* Logic: '<S295>/Logical Operator3' incorporates:
   *  Constant: '<S295>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccReqStandstillVld_flg = (KIPM_FCMAccReqStandstill_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S295>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S295>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S295>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S295>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv1 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_AccReqStandstill;
    }

    /* End of Switch: '<S295>/Switch3' */
  } else {
    /* Switch: '<S295>/Switch' incorporates:
     *  Constant: '<S295>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv1 = KIPM_FCMAccReqStandstillDflt_flg;
  }

  /* End of Switch: '<S295>/Switch' */

  /* Switch: '<S295>/Switch4' incorporates:
   *  Constant: '<S295>/sat3'
   */
  if (KIPM_FCMAccReqStandstill_flg_ovrdflg) {
    /* Switch: '<S295>/Switch4' incorporates:
     *  Constant: '<S295>/sat4'
     */
    VIPM_FCMAccReqStandstill_flg = KIPM_FCMAccReqStandstill_flg_ovrdval;
  } else {
    /* Switch: '<S295>/Switch4' */
    VIPM_FCMAccReqStandstill_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_iv1;
  }

  /* End of Switch: '<S295>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccReqStandstill_flg' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccReqDriveOff_flg' */
  /* Logic: '<S294>/Logical Operator3' incorporates:
   *  Constant: '<S294>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccReqDriveOffVld_flg = (KIPM_FCMAccReqDriveOff_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S294>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S294>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S294>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S294>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_AccReqDriveOff;
    }

    /* End of Switch: '<S294>/Switch3' */
  } else {
    /* Switch: '<S294>/Switch' incorporates:
     *  Constant: '<S294>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3 = KIPM_FCMAccReqDriveOffDflt_flg;
  }

  /* End of Switch: '<S294>/Switch' */

  /* Switch: '<S294>/Switch4' incorporates:
   *  Constant: '<S294>/sat3'
   */
  if (KIPM_FCMAccReqDriveOff_flg_ovrdflg) {
    /* Switch: '<S294>/Switch4' incorporates:
     *  Constant: '<S294>/sat4'
     */
    VIPM_FCMAccReqDriveOff_flg = KIPM_FCMAccReqDriveOff_flg_ovrdval;
  } else {
    /* Switch: '<S294>/Switch4' */
    VIPM_FCMAccReqDriveOff_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_g3;
  }

  /* End of Switch: '<S294>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccReqDriveOff_flg' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAccMode_enum' */
  /* Logic: '<S293>/Logical Operator3' incorporates:
   *  Constant: '<S293>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAccModeVld_flg = (KIPM_FCMAccMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S293>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S293>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S293>/Switch' incorporates:
       *  DataTypeConversion: '<S293>/Data Type Conversion2'
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S293>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ecm =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AccMode;
    }

    /* End of Switch: '<S293>/Switch3' */
  } else {
    /* Switch: '<S293>/Switch' incorporates:
     *  Constant: '<S293>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ecm = KIPM_FCMAccModeDflt_enum;
  }

  /* End of Switch: '<S293>/Switch' */

  /* Switch: '<S293>/Switch4' incorporates:
   *  Constant: '<S293>/sat3'
   */
  if (KIPM_FCMAccMode_enum_ovrdflg) {
    /* Switch: '<S293>/Switch4' incorporates:
     *  Constant: '<S293>/sat4'
     */
    VIPM_FCMAccMode_enum = KIPM_FCMAccMode_enum_ovrdval;
  } else {
    /* Switch: '<S293>/Switch4' incorporates:
     *  Switch: '<S293>/Switch'
     */
    VIPM_FCMAccMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ecm;
  }

  /* End of Switch: '<S293>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAccMode_enum' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMAEBReq_flg' */
  /* Logic: '<S292>/Logical Operator3' incorporates:
   *  Constant: '<S292>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMAEBReqVld_flg = (KIPM_FCMAEBReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S292>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S292>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S292>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S292>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0u =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_AEBReq;
    }

    /* End of Switch: '<S292>/Switch3' */
  } else {
    /* Switch: '<S292>/Switch' incorporates:
     *  Constant: '<S292>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0u = KIPM_FCMAEBReqDflt_flg;
  }

  /* End of Switch: '<S292>/Switch' */

  /* Switch: '<S292>/Switch4' incorporates:
   *  Constant: '<S292>/sat3'
   */
  if (KIPM_FCMAEBReq_flg_ovrdflg) {
    /* Switch: '<S292>/Switch4' incorporates:
     *  Constant: '<S292>/sat4'
     */
    VIPM_FCMAEBReq_flg = KIPM_FCMAEBReq_flg_ovrdval;
  } else {
    /* Switch: '<S292>/Switch4' */
    VIPM_FCMAEBReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jg0u;
  }

  /* End of Switch: '<S292>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMAEBReq_flg' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMTrnLampReq_enum' */
  /* Logic: '<S301>/Logical Operator3' incorporates:
   *  Constant: '<S301>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMTrnLampReqVld_flg = (KIPM_FCMTrnLampReq_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S301>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S301>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S301>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S301>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jk =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())->FCM_TurnLampReq;
    }

    /* End of Switch: '<S301>/Switch3' */
  } else {
    /* Switch: '<S301>/Switch' incorporates:
     *  Constant: '<S301>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jk = KIPM_FCMTrnLampReqDflt_enum;
  }

  /* End of Switch: '<S301>/Switch' */

  /* Switch: '<S301>/Switch4' incorporates:
   *  Constant: '<S301>/sat3'
   */
  if (KIPM_FCMTrnLampReq_enum_ovrdflg) {
    /* Switch: '<S301>/Switch4' incorporates:
     *  Constant: '<S301>/sat4'
     */
    VIPM_FCMTrnLampReq_enum = KIPM_FCMTrnLampReq_enum_ovrdval;
  } else {
    /* Switch: '<S301>/Switch4' */
    VIPM_FCMTrnLampReq_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jk;
  }

  /* End of Switch: '<S301>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMTrnLampReq_enum' */

  /* Outputs for Atomic SubSystem: '<S275>/Subsys_VIPM_FCMACCSdnMode_enum' */
  /* Logic: '<S288>/Logical Operator3' incorporates:
   *  Constant: '<S288>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_FCMACCSdnModeVld_flg = (KIPM_FCMACCSdnMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_FCMMsgActv_flg);

  /* Switch: '<S288>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_FCMMsgActv_flg) {
    /* Switch: '<S288>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_FCM_B_CRCFlt_flg) {
      /* Switch: '<S288>/Switch' incorporates:
       *  Inport: '<Root>/FCM_B_CHA'
       *  Switch: '<S288>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k3 =
        (Rte_IRead_Runbl_IpmCanRx_20ms_FCM_B_CHA_FCM_B_CHA())
        ->FCM_ACC_ShutdownMode;
    }

    /* End of Switch: '<S288>/Switch3' */
  } else {
    /* Switch: '<S288>/Switch' incorporates:
     *  Constant: '<S288>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k3 = KIPM_FCMACCSdnModeDflt_enum;
  }

  /* End of Switch: '<S288>/Switch' */

  /* Switch: '<S288>/Switch4' incorporates:
   *  Constant: '<S288>/sat3'
   */
  if (KIPM_FCMACCSdnMode_enum_ovrdflg) {
    /* Switch: '<S288>/Switch4' incorporates:
     *  Constant: '<S288>/sat4'
     */
    VIPM_FCMACCSdnMode_enum = KIPM_FCMACCSdnMode_enum_ovrdval;
  } else {
    /* Switch: '<S288>/Switch4' */
    VIPM_FCMACCSdnMode_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_k3;
  }

  /* End of Switch: '<S288>/Switch4' */
  /* End of Outputs for SubSystem: '<S275>/Subsys_VIPM_FCMACCSdnMode_enum' */

  /* BusCreator: '<S275>/BusCreator' incorporates:
   *  DataTypeConversion: '<S275>/Data Type Conversion3'
   *  Logic: '<S288>/Logical Operator3'
   *  Logic: '<S289>/Logical Operator3'
   *  Logic: '<S290>/Logical Operator3'
   *  Logic: '<S291>/Logical Operator3'
   *  Logic: '<S292>/Logical Operator3'
   *  Logic: '<S293>/Logical Operator3'
   *  Logic: '<S294>/Logical Operator3'
   *  Logic: '<S295>/Logical Operator3'
   *  Logic: '<S296>/Logical Operator3'
   *  Logic: '<S297>/Logical Operator3'
   *  Logic: '<S298>/Logical Operator3'
   *  Logic: '<S299>/Logical Operator3'
   *  Logic: '<S300>/Logical Operator3'
   *  Logic: '<S301>/Logical Operator3'
   *  MinMax: '<S289>/MinMax1'
   *  MinMax: '<S291>/MinMax1'
   *  MinMax: '<S297>/MinMax1'
   *  MinMax: '<S299>/MinMax1'
   *  Switch: '<S288>/Switch4'
   *  Switch: '<S290>/Switch4'
   *  Switch: '<S292>/Switch4'
   *  Switch: '<S293>/Switch4'
   *  Switch: '<S294>/Switch4'
   *  Switch: '<S295>/Switch4'
   *  Switch: '<S296>/Switch4'
   *  Switch: '<S298>/Switch4'
   *  Switch: '<S300>/Switch4'
   *  Switch: '<S301>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCWhlTqReqActv_flg =
    VIPM_FCMACCWhlTqReqActv_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCWhlTqReqActvVld_flg =
    VIPM_FCMACCWhlTqReqActvVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCWhlTqReqVal_Nm =
    VIPM_FCMACCWhlTqReqVal_Nm;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCWhlTqReqValVld_flg =
    VIPM_FCMACCWhlTqReqValVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCWhlDece_mps2 =
    VIPM_FCMACCWhlDece_mps2;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCWhlDeceVld_flg =
    VIPM_FCMACCWhlDeceVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTarAccrnReqActv_flg =
    VIPM_FCMAccTarAccrnReqActv_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTarAccrnReqActvVld_flg =
    VIPM_FCMAccTarAccrnReqActvVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTarAccrn_mps2 =
    VIPM_FCMAccTarAccrn_mps2;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTarAccrnVld_flg =
    VIPM_FCMAccTarAccrnVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMEPBReq_enum = VIPM_FCMEPBReq_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMEPBReqVld_flg =
    VIPM_FCMEPBReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTgtAxReq_flg =
    VIPM_FCMAccTgtAxReq_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTgtAxReqVld_flg =
    VIPM_FCMAccTgtAxReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTgtAx_mps2 =
    VIPM_FCMAccTgtAx_mps2;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccTgtAxVld_flg =
    VIPM_FCMAccTgtAxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccReqStandstill_flg =
    VIPM_FCMAccReqStandstill_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccReqStandstillVld_flg =
    VIPM_FCMAccReqStandstillVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccReqDriveOff_flg =
    VIPM_FCMAccReqDriveOff_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccReqDriveOffVld_flg =
    VIPM_FCMAccReqDriveOffVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccMode_enum = VIPM_FCMAccMode_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAccModeVld_flg =
    VIPM_FCMAccModeVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAEBReq_flg = VIPM_FCMAEBReq_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMAEBReqVld_flg =
    VIPM_FCMAEBReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMTrnLampReq_enum =
    VIPM_FCMTrnLampReq_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMTrnLampReqVld_flg =
    VIPM_FCMTrnLampReqVld_flg;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCSdnMode_enum =
    VIPM_FCMACCSdnMode_enum;
  AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k.VIPM_FCMACCSdnModeVld_flg =
    VIPM_FCMACCSdnModeVld_flg;

  /* Outputs for Atomic SubSystem: '<S306>/Subsys_VIPM_BMSDCSInletConnectSta_flg' */
  /* Logic: '<S314>/Logical Operator3' incorporates:
   *  Constant: '<S314>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDCSInletConnectStaVld_flg = (KIPM_BMSDCSInletConnectSta_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S314>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S314>/Switch' incorporates:
     *  Inport: '<Root>/BMS_10_DC_ChargeStates_EPT'
     *  Switch: '<S314>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_df =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT
       ())->BMS_DCS_InletConnectSta;
  } else {
    /* Switch: '<S314>/Switch' incorporates:
     *  Constant: '<S314>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_df = KIPM_BMSDCSInletConnectStaDflt_flg;
  }

  /* End of Switch: '<S314>/Switch' */

  /* Switch: '<S314>/Switch4' incorporates:
   *  Constant: '<S314>/sat3'
   */
  if (KIPM_BMSDCSInletConnectSta_flg_ovrdflg) {
    /* Switch: '<S314>/Switch4' incorporates:
     *  Constant: '<S314>/sat4'
     */
    VIPM_BMSDCSInletConnectSta_flg = KIPM_BMSDCSInletConnectSta_flg_ovrdval;
  } else {
    /* Switch: '<S314>/Switch4' */
    VIPM_BMSDCSInletConnectSta_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_df;
  }

  /* End of Switch: '<S314>/Switch4' */
  /* End of Outputs for SubSystem: '<S306>/Subsys_VIPM_BMSDCSInletConnectSta_flg' */

  /* Outputs for Atomic SubSystem: '<S306>/Subsys_VIPM_BMSDCSActOprtMode_enum' */
  /* Logic: '<S313>/Logical Operator3' incorporates:
   *  Constant: '<S313>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDCSActOprtModeVld_flg = (KIPM_BMSDCSActOprtMode_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S313>/Switch4' incorporates:
   *  Constant: '<S313>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S313>/Switch'
   */
  if (KIPM_BMSDCSActOprtMode_enum_ovrdflg) {
    /* Switch: '<S313>/Switch4' incorporates:
     *  Constant: '<S313>/sat4'
     */
    VIPM_BMSDCSActOprtMode_enum = KIPM_BMSDCSActOprtMode_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S313>/Switch4' incorporates:
     *  DataTypeConversion: '<S313>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_10_DC_ChargeStates_EPT'
     *  Switch: '<S313>/Switch'
     */
    VIPM_BMSDCSActOprtMode_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_10_DC_ChargeStates_EPT_BMS_10_DC_ChargeStates_EPT
       ())->BMS_DCS_ActOprtMode;
  } else {
    /* Switch: '<S313>/Switch4' incorporates:
     *  Constant: '<S313>/sat5'
     *  Switch: '<S313>/Switch'
     */
    VIPM_BMSDCSActOprtMode_enum = KIPM_BMSDCSActOprtModeDflt_enum;
  }

  /* End of Switch: '<S313>/Switch4' */
  /* End of Outputs for SubSystem: '<S306>/Subsys_VIPM_BMSDCSActOprtMode_enum' */

  /* BusCreator: '<S306>/BusCreator' incorporates:
   *  DataTypeConversion: '<S306>/Data Type Conversion'
   *  Logic: '<S313>/Logical Operator3'
   *  Logic: '<S314>/Logical Operator3'
   *  Switch: '<S313>/Switch4'
   *  Switch: '<S314>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT_j.VIPM_BMSDCSInletConnectSta_flg
    = VIPM_BMSDCSInletConnectSta_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT_j.VIPM_BMSDCSInletConnectStaVld_flg
    = VIPM_BMSDCSInletConnectStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT_j.VIPM_BMSDCSActOprtMode_enum
    = VIPM_BMSDCSActOprtMode_enum;
  AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT_j.VIPM_BMSDCSActOprtModeVld_flg
    = VIPM_BMSDCSActOprtModeVld_flg;

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSThermrunawayWrn_enum' */
  /* Logic: '<S322>/Logical Operator3' incorporates:
   *  Constant: '<S322>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSThermrunawayWrnVld_flg = (KIPM_BMSThermrunawayWrn_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S322>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S322>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S322>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dg =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_ThermalrunawayWrn;
  } else {
    /* Switch: '<S322>/Switch' incorporates:
     *  Constant: '<S322>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dg = KIPM_BMSThermrunawayWrnDflt_enum;
  }

  /* End of Switch: '<S322>/Switch' */

  /* Switch: '<S322>/Switch4' incorporates:
   *  Constant: '<S322>/sat3'
   */
  if (KIPM_BMSThermrunawayWrn_enum_ovrdflg) {
    /* Switch: '<S322>/Switch4' incorporates:
     *  Constant: '<S322>/sat4'
     */
    VIPM_BMSThermrunawayWrn_enum = KIPM_BMSThermrunawayWrn_enum_ovrdval;
  } else {
    /* Switch: '<S322>/Switch4' */
    VIPM_BMSThermrunawayWrn_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dg;
  }

  /* End of Switch: '<S322>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSThermrunawayWrn_enum' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSDchrgInterlockSta_enum' */
  /* Logic: '<S317>/Logical Operator3' incorporates:
   *  Constant: '<S317>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDchrgInterlockStaVld_flg = (KIPM_BMSDchrgInterlockSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S317>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S317>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S317>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_of =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_DisChargeInterlockSta;
  } else {
    /* Switch: '<S317>/Switch' incorporates:
     *  Constant: '<S317>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_of = KIPM_BMSDchrgInterlockStaDflt_enum;
  }

  /* End of Switch: '<S317>/Switch' */

  /* Switch: '<S317>/Switch4' incorporates:
   *  Constant: '<S317>/sat3'
   */
  if (KIPM_BMSDchrgInterlockSta_enum_ovrdflg) {
    /* Switch: '<S317>/Switch4' incorporates:
     *  Constant: '<S317>/sat4'
     */
    VIPM_BMSDchrgInterlockSta_enum = KIPM_BMSDchrgInterlockSta_enum_ovrdval;
  } else {
    /* Switch: '<S317>/Switch4' */
    VIPM_BMSDchrgInterlockSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_of;
  }

  /* End of Switch: '<S317>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSDchrgInterlockSta_enum' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSChrgInterlockSta_enum' */
  /* Logic: '<S316>/Logical Operator3' incorporates:
   *  Constant: '<S316>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSChrgInterlockStaVld_flg = (KIPM_BMSChrgInterlockSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S316>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S316>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S316>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gr =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_ChargeInterlockSta;
  } else {
    /* Switch: '<S316>/Switch' incorporates:
     *  Constant: '<S316>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gr = KIPM_BMSChrgInterlockStaDflt_enum;
  }

  /* End of Switch: '<S316>/Switch' */

  /* Switch: '<S316>/Switch4' incorporates:
   *  Constant: '<S316>/sat3'
   */
  if (KIPM_BMSChrgInterlockSta_enum_ovrdflg) {
    /* Switch: '<S316>/Switch4' incorporates:
     *  Constant: '<S316>/sat4'
     */
    VIPM_BMSChrgInterlockSta_enum = KIPM_BMSChrgInterlockSta_enum_ovrdval;
  } else {
    /* Switch: '<S316>/Switch4' */
    VIPM_BMSChrgInterlockSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_gr;
  }

  /* End of Switch: '<S316>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSChrgInterlockSta_enum' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSActExchgCurnt_A' */
  /* Logic: '<S315>/Logical Operator3' incorporates:
   *  Constant: '<S315>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSActExchgCurntVld_flg = (KIPM_BMSActExchgCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S315>/Switch4' incorporates:
   *  Constant: '<S315>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S315>/Switch'
   */
  if (KIPM_BMSActExchgCurnt_A_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S315>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSActExchgCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Product: '<S323>/Product' incorporates:
     *  Constant: '<S323>/Constant'
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S315>/Switch'
     */
    rtb_Product_f0 = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_ActlExchgCurnt * 0.1F;

    /* MinMax: '<S315>/MinMax' incorporates:
     *  MinMax: '<S353>/MinMax'
     *  Sum: '<S323>/Add'
     *  Switch: '<S315>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = rtb_Product_f0 - 1000.0F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S315>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S315>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSActExchgCurntDflt_A;
  }

  /* End of Switch: '<S315>/Switch4' */

  /* MinMax: '<S315>/MinMax' incorporates:
   *  Constant: '<S315>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSActExchgCurntHi_A) {
    VIPM_BMSCellVoltMin_mV = KIPM_BMSActExchgCurntHi_A;
  }

  /* MinMax: '<S315>/MinMax1' incorporates:
   *  Constant: '<S315>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSActExchgCurntLo_A) {
    /* MinMax: '<S315>/MinMax1' */
    VIPM_BMSActExchgCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S315>/MinMax1' */
    VIPM_BMSActExchgCurnt_A = KIPM_BMSActExchgCurntLo_A;
  }

  /* End of MinMax: '<S315>/MinMax1' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSActExchgCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSEmgcySdnReq_flg' */
  /* Logic: '<S318>/Logical Operator3' incorporates:
   *  Constant: '<S318>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSEmgcySdnReqVld_flg = (KIPM_BMSEmgcySdnReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S318>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S318>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S318>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nv =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_Emeshutdown_Req;
  } else {
    /* Switch: '<S318>/Switch' incorporates:
     *  Constant: '<S318>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nv = KIPM_BMSEmgcySdnReqDflt_flg;
  }

  /* End of Switch: '<S318>/Switch' */

  /* Switch: '<S318>/Switch4' incorporates:
   *  Constant: '<S318>/sat3'
   */
  if (KIPM_BMSEmgcySdnReq_flg_ovrdflg) {
    /* Switch: '<S318>/Switch4' incorporates:
     *  Constant: '<S318>/sat4'
     */
    VIPM_BMSEmgcySdnReq_flg = KIPM_BMSEmgcySdnReq_flg_ovrdval;
  } else {
    /* Switch: '<S318>/Switch4' */
    VIPM_BMSEmgcySdnReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nv;
  }

  /* End of Switch: '<S318>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSEmgcySdnReq_flg' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSSysFailSta_enum' */
  /* Logic: '<S321>/Logical Operator3' incorporates:
   *  Constant: '<S321>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSSysFailStaVld_flg = (KIPM_BMSSysFailSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S321>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S321>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S321>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jh =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_SysFailSta;
  } else {
    /* Switch: '<S321>/Switch' incorporates:
     *  Constant: '<S321>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jh = KIPM_BMSSysFailStaDflt_enum;
  }

  /* End of Switch: '<S321>/Switch' */

  /* Switch: '<S321>/Switch4' incorporates:
   *  Constant: '<S321>/sat3'
   */
  if (KIPM_BMSSysFailSta_enum_ovrdflg) {
    /* Switch: '<S321>/Switch4' incorporates:
     *  Constant: '<S321>/sat4'
     */
    VIPM_BMSSysFailSta_enum = KIPM_BMSSysFailSta_enum_ovrdval;
  } else {
    /* Switch: '<S321>/Switch4' */
    VIPM_BMSSysFailSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jh;
  }

  /* End of Switch: '<S321>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSSysFailSta_enum' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSPwrTrainConnectSta_enum' */
  /* Logic: '<S319>/Logical Operator3' incorporates:
   *  Constant: '<S319>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSPwrTrainConnectStaVld_flg = (KIPM_BMSPwrTrainConnectSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S319>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S319>/Switch' incorporates:
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S319>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_PwrTrainConnectSta;
  } else {
    /* Switch: '<S319>/Switch' incorporates:
     *  Constant: '<S319>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b = KIPM_BMSPwrTrainConnectStaDflt_enum;
  }

  /* End of Switch: '<S319>/Switch' */

  /* Switch: '<S319>/Switch4' incorporates:
   *  Constant: '<S319>/sat3'
   */
  if (KIPM_BMSPwrTrainConnectSta_enum_ovrdflg) {
    /* Switch: '<S319>/Switch4' incorporates:
     *  Constant: '<S319>/sat4'
     */
    VIPM_BMSPwrTrainConnectSta_enum = KIPM_BMSPwrTrainConnectSta_enum_ovrdval;
  } else {
    /* Switch: '<S319>/Switch4' */
    VIPM_BMSPwrTrainConnectSta_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b;
  }

  /* End of Switch: '<S319>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSPwrTrainConnectSta_enum' */

  /* Outputs for Atomic SubSystem: '<S307>/Subsys_VIPM_BMSRunSta_enum' */
  /* Logic: '<S320>/Logical Operator3' incorporates:
   *  Constant: '<S320>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSRunStaVld_flg = (KIPM_BMSRunSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S320>/Switch4' incorporates:
   *  Constant: '<S320>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S320>/Switch'
   */
  if (KIPM_BMSRunSta_enum_ovrdflg) {
    /* Switch: '<S320>/Switch4' incorporates:
     *  Constant: '<S320>/sat4'
     */
    VIPM_BMSRunSta_enum = KIPM_BMSRunSta_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S320>/Switch4' incorporates:
     *  DataTypeConversion: '<S320>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_1_MainState_EPT'
     *  Switch: '<S320>/Switch'
     */
    VIPM_BMSRunSta_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_1_MainState_EPT_BMS_1_MainState_EPT()
      )->BMS_RunState;
  } else {
    /* Switch: '<S320>/Switch4' incorporates:
     *  Constant: '<S320>/sat5'
     *  Switch: '<S320>/Switch'
     */
    VIPM_BMSRunSta_enum = KIPM_BMSRunStaDflt_enum;
  }

  /* End of Switch: '<S320>/Switch4' */
  /* End of Outputs for SubSystem: '<S307>/Subsys_VIPM_BMSRunSta_enum' */

  /* BusCreator: '<S307>/BusCreator' incorporates:
   *  DataTypeConversion: '<S307>/Data Type Conversion'
   *  Logic: '<S315>/Logical Operator3'
   *  Logic: '<S316>/Logical Operator3'
   *  Logic: '<S317>/Logical Operator3'
   *  Logic: '<S318>/Logical Operator3'
   *  Logic: '<S319>/Logical Operator3'
   *  Logic: '<S320>/Logical Operator3'
   *  Logic: '<S321>/Logical Operator3'
   *  Logic: '<S322>/Logical Operator3'
   *  MinMax: '<S315>/MinMax1'
   *  Switch: '<S316>/Switch4'
   *  Switch: '<S317>/Switch4'
   *  Switch: '<S318>/Switch4'
   *  Switch: '<S319>/Switch4'
   *  Switch: '<S320>/Switch4'
   *  Switch: '<S321>/Switch4'
   *  Switch: '<S322>/Switch4'
   */
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSThermrunawayWrn_enum =
    VIPM_BMSThermrunawayWrn_enum;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSThermrunawayWrnVld_flg =
    VIPM_BMSThermrunawayWrnVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSDchrgInterlockSta_enum =
    VIPM_BMSDchrgInterlockSta_enum;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSDchrgInterlockStaVld_flg =
    VIPM_BMSDchrgInterlockStaVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSChrgInterlockSta_enum =
    VIPM_BMSChrgInterlockSta_enum;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSChrgInterlockStaVld_flg =
    VIPM_BMSChrgInterlockStaVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSActExchgCurnt_A =
    VIPM_BMSActExchgCurnt_A;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSActExchgCurntVld_flg =
    VIPM_BMSActExchgCurntVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSEmgcySdnReq_flg =
    VIPM_BMSEmgcySdnReq_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSEmgcySdnReqVld_flg =
    VIPM_BMSEmgcySdnReqVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSSysFailSta_enum =
    VIPM_BMSSysFailSta_enum;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSSysFailStaVld_flg =
    VIPM_BMSSysFailStaVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSPwrTrainConnectSta_enum =
    VIPM_BMSPwrTrainConnectSta_enum;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSPwrTrainConnectStaVld_flg =
    VIPM_BMSPwrTrainConnectStaVld_flg;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSRunSta_enum = VIPM_BMSRunSta_enum;
  AppSwcIpm_ARID_DEF.BusCreator.VIPM_BMSRunStaVld_flg = VIPM_BMSRunStaVld_flg;

  /* Outputs for Atomic SubSystem: '<S308>/Subsys_VIPM_BMSBatSOCRpt_pct' */
  /* Logic: '<S325>/Logical Operator3' incorporates:
   *  Constant: '<S325>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatSOCRptVld_flg = (KIPM_BMSBatSOCRpt_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S325>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S325>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S325>/Switch' incorporates:
       *  Constant: '<S328>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S328>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_BatSOC_Rpt * 0.1F;
    }

    /* End of Switch: '<S325>/Switch3' */
  } else {
    /* Switch: '<S325>/Switch' incorporates:
     *  Constant: '<S325>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c = KIPM_BMSBatSOCRptDflt_pct;
  }

  /* End of Switch: '<S325>/Switch' */

  /* Switch: '<S325>/Switch4' incorporates:
   *  Constant: '<S325>/sat3'
   *  Constant: '<S325>/sat4'
   */
  if (KIPM_BMSBatSOCRpt_pct_ovrdflg) {
    VIPM_BMSBatSOCRpt_pct = KIPM_BMSBatSOCRpt_pct_ovrdval;
  } else {
    VIPM_BMSBatSOCRpt_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_c;
  }

  /* MinMax: '<S325>/MinMax' incorporates:
   *  Constant: '<S325>/sat6'
   *  Switch: '<S325>/Switch4'
   */
  if (VIPM_BMSBatSOCRpt_pct > KIPM_BMSBatSOCRptHi_pct) {
    VIPM_BMSBatSOCRpt_pct = KIPM_BMSBatSOCRptHi_pct;
  }

  /* End of MinMax: '<S325>/MinMax' */

  /* MinMax: '<S325>/MinMax1' incorporates:
   *  Constant: '<S325>/sat7'
   */
  if (VIPM_BMSBatSOCRpt_pct < KIPM_BMSBatSOCRptLo_pct) {
    /* Switch: '<S325>/Switch4' incorporates:
     *  MinMax: '<S325>/MinMax1'
     */
    VIPM_BMSBatSOCRpt_pct = KIPM_BMSBatSOCRptLo_pct;
  }

  /* End of MinMax: '<S325>/MinMax1' */
  /* End of Outputs for SubSystem: '<S308>/Subsys_VIPM_BMSBatSOCRpt_pct' */

  /* Outputs for Atomic SubSystem: '<S308>/Subsys_VIPM_BMSBatSOH_pct' */
  /* Logic: '<S326>/Logical Operator3' incorporates:
   *  Constant: '<S326>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatSOHVld_flg = (KIPM_BMSBatSOH_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S326>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S326>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S326>/Switch' incorporates:
       *  Constant: '<S329>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S329>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_d = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_BatSOH * 0.1F;
    }

    /* End of Switch: '<S326>/Switch3' */
  } else {
    /* Switch: '<S326>/Switch' incorporates:
     *  Constant: '<S326>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_d = KIPM_BMSBatSOHDflt_pct;
  }

  /* End of Switch: '<S326>/Switch' */

  /* Switch: '<S326>/Switch4' incorporates:
   *  Constant: '<S326>/sat3'
   *  Constant: '<S326>/sat4'
   */
  if (KIPM_BMSBatSOH_pct_ovrdflg) {
    VIPM_BMSBatSOH_pct = KIPM_BMSBatSOH_pct_ovrdval;
  } else {
    VIPM_BMSBatSOH_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_d;
  }

  /* MinMax: '<S326>/MinMax' incorporates:
   *  Constant: '<S326>/sat6'
   *  Switch: '<S326>/Switch4'
   */
  if (VIPM_BMSBatSOH_pct > KIPM_BMSBatSOHHi_pct) {
    VIPM_BMSBatSOH_pct = KIPM_BMSBatSOHHi_pct;
  }

  /* End of MinMax: '<S326>/MinMax' */

  /* MinMax: '<S326>/MinMax1' incorporates:
   *  Constant: '<S326>/sat7'
   */
  if (VIPM_BMSBatSOH_pct < KIPM_BMSBatSOHLo_pct) {
    /* Switch: '<S326>/Switch4' incorporates:
     *  MinMax: '<S326>/MinMax1'
     */
    VIPM_BMSBatSOH_pct = KIPM_BMSBatSOHLo_pct;
  }

  /* End of MinMax: '<S326>/MinMax1' */
  /* End of Outputs for SubSystem: '<S308>/Subsys_VIPM_BMSBatSOH_pct' */

  /* Outputs for Atomic SubSystem: '<S308>/Subsys_VIPM_BMSHVBatActVolt_V' */
  /* Logic: '<S327>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_2_BatState_EPT'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT())
     ->BMS_HVBatActlVoltageV &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S327>/Logical Operator3' incorporates:
   *  Constant: '<S327>/sat3'
   */
  VIPM_BMSHVBatActVoltVld_flg = (KIPM_BMSHVBatActVolt_V_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S327>/Switch' */
  if (rtb_LogicalOperator2_fz) {
    /* Switch: '<S327>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S327>/Switch' incorporates:
       *  Constant: '<S330>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S330>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_l = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_HVBatActlVoltage * 0.1F;
    }

    /* End of Switch: '<S327>/Switch3' */
  } else {
    /* Switch: '<S327>/Switch' incorporates:
     *  Constant: '<S327>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_l = KIPM_BMSHVBatActVoltDflt_V;
  }

  /* End of Switch: '<S327>/Switch' */

  /* Switch: '<S327>/Switch4' incorporates:
   *  Constant: '<S327>/sat3'
   *  Constant: '<S327>/sat4'
   */
  if (KIPM_BMSHVBatActVolt_V_ovrdflg) {
    VIPM_BMSHVBatActVolt_V = KIPM_BMSHVBatActVolt_V_ovrdval;
  } else {
    VIPM_BMSHVBatActVolt_V = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_l;
  }

  /* MinMax: '<S327>/MinMax' incorporates:
   *  Constant: '<S327>/sat6'
   *  Switch: '<S327>/Switch4'
   */
  if (VIPM_BMSHVBatActVolt_V > KIPM_BMSHVBatActVoltHi_V) {
    VIPM_BMSHVBatActVolt_V = KIPM_BMSHVBatActVoltHi_V;
  }

  /* End of MinMax: '<S327>/MinMax' */

  /* MinMax: '<S327>/MinMax1' incorporates:
   *  Constant: '<S327>/sat7'
   */
  if (VIPM_BMSHVBatActVolt_V < KIPM_BMSHVBatActVoltLo_V) {
    /* Switch: '<S327>/Switch4' incorporates:
     *  MinMax: '<S327>/MinMax1'
     */
    VIPM_BMSHVBatActVolt_V = KIPM_BMSHVBatActVoltLo_V;
  }

  /* End of MinMax: '<S327>/MinMax1' */
  /* End of Outputs for SubSystem: '<S308>/Subsys_VIPM_BMSHVBatActVolt_V' */

  /* Outputs for Atomic SubSystem: '<S308>/Subsys_VIPM_BMSBatSOCAct_pct' */
  /* Logic: '<S324>/Logical Operator3' incorporates:
   *  Constant: '<S324>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSBatSOCActVld_flg = (KIPM_BMSBatSOCAct_pct_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S324>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S324>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_20ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_BMS_2_BatState_CRCFlt_flg) {
      /* Switch: '<S324>/Switch' incorporates:
       *  Constant: '<S331>/Constant'
       *  Inport: '<Root>/BMS_2_BatState_EPT'
       *  Product: '<S331>/Product'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n = (float32)
        (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_2_BatState_EPT_BMS_2_BatState_EPT()
        )->BMS_BatSOC_Actl * 0.1F;
    }

    /* End of Switch: '<S324>/Switch3' */
  } else {
    /* Switch: '<S324>/Switch' incorporates:
     *  Constant: '<S324>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n = KIPM_BMSBatSOCActDflt_pct;
  }

  /* End of Switch: '<S324>/Switch' */

  /* Switch: '<S324>/Switch4' incorporates:
   *  Constant: '<S324>/sat3'
   *  Constant: '<S324>/sat4'
   */
  if (KIPM_BMSBatSOCAct_pct_ovrdflg) {
    VIPM_BMSBatSOCAct_pct = KIPM_BMSBatSOCAct_pct_ovrdval;
  } else {
    VIPM_BMSBatSOCAct_pct = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_n;
  }

  /* MinMax: '<S324>/MinMax' incorporates:
   *  Constant: '<S324>/sat6'
   *  Switch: '<S324>/Switch4'
   */
  if (VIPM_BMSBatSOCAct_pct > KIPM_BMSBatSOCActHi_pct) {
    VIPM_BMSBatSOCAct_pct = KIPM_BMSBatSOCActHi_pct;
  }

  /* End of MinMax: '<S324>/MinMax' */

  /* MinMax: '<S324>/MinMax1' incorporates:
   *  Constant: '<S324>/sat7'
   */
  if (VIPM_BMSBatSOCAct_pct < KIPM_BMSBatSOCActLo_pct) {
    /* Switch: '<S324>/Switch4' incorporates:
     *  MinMax: '<S324>/MinMax1'
     */
    VIPM_BMSBatSOCAct_pct = KIPM_BMSBatSOCActLo_pct;
  }

  /* End of MinMax: '<S324>/MinMax1' */
  /* End of Outputs for SubSystem: '<S308>/Subsys_VIPM_BMSBatSOCAct_pct' */

  /* BusCreator: '<S308>/BusCreator' incorporates:
   *  Logic: '<S324>/Logical Operator3'
   *  Logic: '<S325>/Logical Operator3'
   *  Logic: '<S326>/Logical Operator3'
   *  Logic: '<S327>/Logical Operator3'
   *  MinMax: '<S324>/MinMax1'
   *  MinMax: '<S325>/MinMax1'
   *  MinMax: '<S326>/MinMax1'
   *  MinMax: '<S327>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSBatSOCRpt_pct =
    VIPM_BMSBatSOCRpt_pct;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSBatSOCRptVld_flg =
    VIPM_BMSBatSOCRptVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSBatSOH_pct =
    VIPM_BMSBatSOH_pct;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSBatSOHVld_flg =
    VIPM_BMSBatSOHVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSHVBatActVolt_V =
    VIPM_BMSHVBatActVolt_V;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSHVBatActVoltVld_flg =
    VIPM_BMSHVBatActVoltVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSBatSOCAct_pct =
    VIPM_BMSBatSOCAct_pct;
  AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n.VIPM_BMSBatSOCActVld_flg =
    VIPM_BMSBatSOCActVld_flg;

  /* Outputs for Atomic SubSystem: '<S309>/Subsys_VIPM_BMSDCSChrgReq_flg' */
  /* Logic: '<S332>/Logical Operator3' incorporates:
   *  Constant: '<S332>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSDCSChrgReqVld_flg = (KIPM_BMSDCSChrgReq_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S332>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
      ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S332>/Switch' incorporates:
     *  Inport: '<Root>/BMS_3_DC_ChargeState_EPT'
     *  Switch: '<S332>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jn =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_3_DC_ChargeState_EPT_BMS_3_DC_ChargeState_EPT
       ())->BMS_DCS_ChargeRequest;
  } else {
    /* Switch: '<S332>/Switch' incorporates:
     *  Constant: '<S332>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jn = KIPM_BMSDCSChrgReqDflt_flg;
  }

  /* End of Switch: '<S332>/Switch' */

  /* Switch: '<S332>/Switch4' incorporates:
   *  Constant: '<S332>/sat3'
   */
  if (KIPM_BMSDCSChrgReq_flg_ovrdflg) {
    /* Switch: '<S332>/Switch4' incorporates:
     *  Constant: '<S332>/sat4'
     */
    VIPM_BMSDCSChrgReq_flg = KIPM_BMSDCSChrgReq_flg_ovrdval;
  } else {
    /* Switch: '<S332>/Switch4' */
    VIPM_BMSDCSChrgReq_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jn;
  }

  /* End of Switch: '<S332>/Switch4' */
  /* End of Outputs for SubSystem: '<S309>/Subsys_VIPM_BMSDCSChrgReq_flg' */

  /* BusCreator: '<S309>/BusCreator' incorporates:
   *  Logic: '<S332>/Logical Operator3'
   *  Switch: '<S332>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_3_DC_ChargeState_EPT_j.VIPM_BMSDCSChrgReq_flg =
    VIPM_BMSDCSChrgReq_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_3_DC_ChargeState_EPT_j.VIPM_BMSDCSChrgReqVld_flg =
    VIPM_BMSDCSChrgReqVld_flg;

  /* Outputs for Atomic SubSystem: '<S310>/Subsys_VIPM_BMSACChrgAtclSta_enum' */
  /* Logic: '<S333>/Logical Operator3' incorporates:
   *  Constant: '<S333>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSACChrgAtclStaVld_flg = (KIPM_BMSACChrgAtclSta_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S333>/Switch4' incorporates:
   *  Constant: '<S333>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S333>/Switch'
   */
  if (KIPM_BMSACChrgAtclSta_enum_ovrdflg) {
    /* Switch: '<S333>/Switch4' incorporates:
     *  Constant: '<S333>/sat4'
     */
    VIPM_BMSACChrgAtclSta_enum = KIPM_BMSACChrgAtclSta_enum_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* Switch: '<S333>/Switch4' incorporates:
     *  DataTypeConversion: '<S333>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  Switch: '<S333>/Switch'
     */
    VIPM_BMSACChrgAtclSta_enum =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_ACChrgAtclSta;
  } else {
    /* Switch: '<S333>/Switch4' incorporates:
     *  Constant: '<S333>/sat5'
     *  Switch: '<S333>/Switch'
     */
    VIPM_BMSACChrgAtclSta_enum = KIPM_BMSACChrgAtclStaDflt_enum;
  }

  /* End of Switch: '<S333>/Switch4' */
  /* End of Outputs for SubSystem: '<S310>/Subsys_VIPM_BMSACChrgAtclSta_enum' */

  /* Outputs for Atomic SubSystem: '<S310>/Subsys_VIPM_BMSOutlCooltActlTemp_C' */
  /* Logic: '<S338>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
      ())->BMS_OutletCoolantActlTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S338>/Logical Operator3' incorporates:
   *  Constant: '<S338>/sat3'
   */
  VIPM_BMSOutlCooltActlTempVld_flg = (KIPM_BMSOutlCooltActlTemp_C_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S338>/Switch4' incorporates:
   *  Constant: '<S338>/sat3'
   *  Switch: '<S338>/Switch'
   */
  if (KIPM_BMSOutlCooltActlTemp_C_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S338>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSOutlCooltActlTemp_C_ovrdval;
  } else if (rtb_LogicalOperator2_fz) {
    /* Product: '<S339>/Product' incorporates:
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  Switch: '<S338>/Switch'
     */
    rtb_Product_os =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_OutletCoolantActlTemp;

    /* MinMax: '<S315>/MinMax' incorporates:
     *  MinMax: '<S353>/MinMax'
     *  Sum: '<S339>/Add'
     *  Switch: '<S338>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)rtb_Product_os - 40.0F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S338>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S338>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSOutlCooltActlTempDflt_C;
  }

  /* End of Switch: '<S338>/Switch4' */

  /* MinMax: '<S338>/MinMax' incorporates:
   *  Constant: '<S338>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSOutlCooltActlTempHi_C) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSOutlCooltActlTempHi_C;
  }

  /* End of MinMax: '<S338>/MinMax' */

  /* MinMax: '<S338>/MinMax1' incorporates:
   *  Constant: '<S338>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSOutlCooltActlTempLo_C) {
    /* MinMax: '<S338>/MinMax1' */
    VIPM_BMSOutlCooltActlTemp_C = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S338>/MinMax1' */
    VIPM_BMSOutlCooltActlTemp_C = KIPM_BMSOutlCooltActlTempLo_C;
  }

  /* End of MinMax: '<S338>/MinMax1' */
  /* End of Outputs for SubSystem: '<S310>/Subsys_VIPM_BMSOutlCooltActlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S310>/Subsys_VIPM_BMSInletCooltActlTemp_C' */
  /* Logic: '<S334>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
   */
  rtb_LogicalOperator2_fz =
    ((Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
      ())->BMS_InletCoolantActlTempValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
     ->VIPM_BMSMsgActv_flg);

  /* Logic: '<S334>/Logical Operator3' incorporates:
   *  Constant: '<S334>/sat3'
   */
  VIPM_BMSInletCooltActlTempVld_flg = (KIPM_BMSInletCooltActlTemp_C_ovrdflg ||
    rtb_LogicalOperator2_fz);

  /* Switch: '<S334>/Switch4' incorporates:
   *  Constant: '<S334>/sat3'
   *  Switch: '<S334>/Switch'
   */
  if (KIPM_BMSInletCooltActlTemp_C_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S334>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSInletCooltActlTemp_C_ovrdval;
  } else if (rtb_LogicalOperator2_fz) {
    /* Product: '<S340>/Product' incorporates:
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  Switch: '<S334>/Switch'
     */
    rtb_Product_os =
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_InletCoolantActlTemp;

    /* MinMax: '<S315>/MinMax' incorporates:
     *  MinMax: '<S353>/MinMax'
     *  Sum: '<S340>/Add'
     *  Switch: '<S334>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)rtb_Product_os - 40.0F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S334>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S334>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSInletCooltActlTempDflt_C;
  }

  /* End of Switch: '<S334>/Switch4' */

  /* MinMax: '<S334>/MinMax' incorporates:
   *  Constant: '<S334>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSInletCooltActlTempHi_C) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSInletCooltActlTempHi_C;
  }

  /* End of MinMax: '<S334>/MinMax' */

  /* MinMax: '<S334>/MinMax1' incorporates:
   *  Constant: '<S334>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSInletCooltActlTempLo_C) {
    /* MinMax: '<S334>/MinMax1' */
    VIPM_BMSInletCooltActlTemp_C = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S334>/MinMax1' */
    VIPM_BMSInletCooltActlTemp_C = KIPM_BMSInletCooltActlTempLo_C;
  }

  /* End of MinMax: '<S334>/MinMax1' */
  /* End of Outputs for SubSystem: '<S310>/Subsys_VIPM_BMSInletCooltActlTemp_C' */

  /* Outputs for Atomic SubSystem: '<S310>/Subsys_VIPM_BMSIsoResist_MOhm' */
  /* Logic: '<S335>/Logical Operator3' incorporates:
   *  Constant: '<S335>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSIsoResistVld_flg = (KIPM_BMSIsoResist_MOhm_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S335>/Switch4' incorporates:
   *  Constant: '<S335>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S335>/Switch'
   */
  if (KIPM_BMSIsoResist_MOhm_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S335>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSIsoResist_MOhm_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S341>/Constant'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S341>/Product'
     *  Switch: '<S335>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_IsoResistance * 0.02F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S335>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S335>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSIsoResistDflt_MOhm;
  }

  /* End of Switch: '<S335>/Switch4' */

  /* MinMax: '<S335>/MinMax' incorporates:
   *  Constant: '<S335>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSIsoResistHi_MOhm) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSIsoResistHi_MOhm;
  }

  /* End of MinMax: '<S335>/MinMax' */

  /* MinMax: '<S335>/MinMax1' incorporates:
   *  Constant: '<S335>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSIsoResistLo_MOhm) {
    /* MinMax: '<S335>/MinMax1' */
    VIPM_BMSIsoResist_MOhm = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S335>/MinMax1' */
    VIPM_BMSIsoResist_MOhm = KIPM_BMSIsoResistLo_MOhm;
  }

  /* End of MinMax: '<S335>/MinMax1' */
  /* End of Outputs for SubSystem: '<S310>/Subsys_VIPM_BMSIsoResist_MOhm' */

  /* Outputs for Atomic SubSystem: '<S310>/Subsys_VIPM_BMSMaxChrgVoltAC_V' */
  /* Logic: '<S337>/Logical Operator3' incorporates:
   *  Constant: '<S337>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxChrgVoltACVld_flg = (KIPM_BMSMaxChrgVoltAC_V_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S337>/Switch4' incorporates:
   *  Constant: '<S337>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S337>/Switch'
   */
  if (KIPM_BMSMaxChrgVoltAC_V_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S337>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgVoltAC_V_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S342>/Constant'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S342>/Product'
     *  Switch: '<S337>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_MaxChrgVoltage_AC * 0.5F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S337>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S337>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgVoltACDflt_V;
  }

  /* End of Switch: '<S337>/Switch4' */

  /* MinMax: '<S337>/MinMax' incorporates:
   *  Constant: '<S337>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxChrgVoltACHi_V) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgVoltACHi_V;
  }

  /* End of MinMax: '<S337>/MinMax' */

  /* MinMax: '<S337>/MinMax1' incorporates:
   *  Constant: '<S337>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxChrgVoltACLo_V) {
    /* MinMax: '<S337>/MinMax1' */
    VIPM_BMSMaxChrgVoltAC_V = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S337>/MinMax1' */
    VIPM_BMSMaxChrgVoltAC_V = KIPM_BMSMaxChrgVoltACLo_V;
  }

  /* End of MinMax: '<S337>/MinMax1' */
  /* End of Outputs for SubSystem: '<S310>/Subsys_VIPM_BMSMaxChrgVoltAC_V' */

  /* Outputs for Atomic SubSystem: '<S310>/Subsys_VIPM_BMSMaxChrgCurntAC_A' */
  /* Logic: '<S336>/Logical Operator3' incorporates:
   *  Constant: '<S336>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxChrgCurntACVld_flg = (KIPM_BMSMaxChrgCurntAC_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S336>/Switch4' incorporates:
   *  Constant: '<S336>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S336>/Switch'
   */
  if (KIPM_BMSMaxChrgCurntAC_A_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S336>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgCurntAC_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S343>/Constant'
     *  Inport: '<Root>/BMS_4_AC_ChargeState_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S343>/Product'
     *  Switch: '<S336>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_4_AC_ChargeState_EPT_BMS_4_AC_ChargeState_EPT
       ())->BMS_MaxChrgCurrent_AC * 0.1F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S336>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S336>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgCurntACDflt_A;
  }

  /* End of Switch: '<S336>/Switch4' */

  /* MinMax: '<S336>/MinMax' incorporates:
   *  Constant: '<S336>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxChrgCurntACHi_A) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxChrgCurntACHi_A;
  }

  /* End of MinMax: '<S336>/MinMax' */

  /* MinMax: '<S336>/MinMax1' incorporates:
   *  Constant: '<S336>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxChrgCurntACLo_A) {
    /* MinMax: '<S336>/MinMax1' */
    VIPM_BMSMaxChrgCurntAC_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S336>/MinMax1' */
    VIPM_BMSMaxChrgCurntAC_A = KIPM_BMSMaxChrgCurntACLo_A;
  }

  /* End of MinMax: '<S336>/MinMax1' */
  /* End of Outputs for SubSystem: '<S310>/Subsys_VIPM_BMSMaxChrgCurntAC_A' */

  /* BusCreator: '<S310>/BusCreator' incorporates:
   *  DataTypeConversion: '<S310>/Data Type Conversion'
   *  Logic: '<S333>/Logical Operator3'
   *  Logic: '<S334>/Logical Operator3'
   *  Logic: '<S335>/Logical Operator3'
   *  Logic: '<S336>/Logical Operator3'
   *  Logic: '<S337>/Logical Operator3'
   *  Logic: '<S338>/Logical Operator3'
   *  MinMax: '<S334>/MinMax1'
   *  MinMax: '<S335>/MinMax1'
   *  MinMax: '<S336>/MinMax1'
   *  MinMax: '<S337>/MinMax1'
   *  MinMax: '<S338>/MinMax1'
   *  Switch: '<S333>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSACChrgAtclSta_enum =
    VIPM_BMSACChrgAtclSta_enum;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSACChrgAtclStaVld_flg
    = VIPM_BMSACChrgAtclStaVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSOutlCooltActlTemp_C =
    VIPM_BMSOutlCooltActlTemp_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSOutlCooltActlTempVld_flg
    = VIPM_BMSOutlCooltActlTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSInletCooltActlTemp_C
    = VIPM_BMSInletCooltActlTemp_C;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSInletCooltActlTempVld_flg
    = VIPM_BMSInletCooltActlTempVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSIsoResist_MOhm =
    VIPM_BMSIsoResist_MOhm;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSIsoResistVld_flg =
    VIPM_BMSIsoResistVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSMaxChrgVoltAC_V =
    VIPM_BMSMaxChrgVoltAC_V;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSMaxChrgVoltACVld_flg
    = VIPM_BMSMaxChrgVoltACVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSMaxChrgCurntAC_A =
    VIPM_BMSMaxChrgCurntAC_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c.VIPM_BMSMaxChrgCurntACVld_flg
    = VIPM_BMSMaxChrgCurntACVld_flg;

  /* Outputs for Atomic SubSystem: '<S311>/Subsys_VIPM_BMSMaxConDisCurnt_A' */
  /* Logic: '<S345>/Logical Operator3' incorporates:
   *  Constant: '<S345>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxConDisCurntVld_flg = (KIPM_BMSMaxConDisCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S345>/Switch4' incorporates:
   *  Constant: '<S345>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S345>/Switch'
   */
  if (KIPM_BMSMaxConDisCurnt_A_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S345>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConDisCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S348>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S348>/Product'
     *  Switch: '<S345>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_MaxConDisCurnt * 0.1F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S345>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S345>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConDisCurntDflt_A;
  }

  /* End of Switch: '<S345>/Switch4' */

  /* MinMax: '<S345>/MinMax' incorporates:
   *  Constant: '<S345>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxConDisCurntHi_A) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConDisCurntHi_A;
  }

  /* End of MinMax: '<S345>/MinMax' */

  /* MinMax: '<S345>/MinMax1' incorporates:
   *  Constant: '<S345>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxConDisCurntLo_A) {
    /* MinMax: '<S345>/MinMax1' */
    VIPM_BMSMaxConDisCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S345>/MinMax1' */
    VIPM_BMSMaxConDisCurnt_A = KIPM_BMSMaxConDisCurntLo_A;
  }

  /* End of MinMax: '<S345>/MinMax1' */
  /* End of Outputs for SubSystem: '<S311>/Subsys_VIPM_BMSMaxConDisCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S311>/Subsys_VIPM_BMSMaxInsDisCurnt_A' */
  /* Logic: '<S347>/Logical Operator3' incorporates:
   *  Constant: '<S347>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxInsDisCurntVld_flg = (KIPM_BMSMaxInsDisCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S347>/Switch4' incorporates:
   *  Constant: '<S347>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S347>/Switch'
   */
  if (KIPM_BMSMaxInsDisCurnt_A_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S347>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsDisCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S349>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S349>/Product'
     *  Switch: '<S347>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_MaxInstanDisCurnt * 0.1F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S347>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S347>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsDisCurntDflt_A;
  }

  /* End of Switch: '<S347>/Switch4' */

  /* MinMax: '<S347>/MinMax' incorporates:
   *  Constant: '<S347>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxInsDisCurntHi_A) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsDisCurntHi_A;
  }

  /* End of MinMax: '<S347>/MinMax' */

  /* MinMax: '<S347>/MinMax1' incorporates:
   *  Constant: '<S347>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxInsDisCurntLo_A) {
    /* MinMax: '<S347>/MinMax1' */
    VIPM_BMSMaxInsDisCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S347>/MinMax1' */
    VIPM_BMSMaxInsDisCurnt_A = KIPM_BMSMaxInsDisCurntLo_A;
  }

  /* End of MinMax: '<S347>/MinMax1' */
  /* End of Outputs for SubSystem: '<S311>/Subsys_VIPM_BMSMaxInsDisCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S311>/Subsys_VIPM_BMSMaxConChrgCurnt_A' */
  /* Logic: '<S344>/Logical Operator3' incorporates:
   *  Constant: '<S344>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxConChrgCurntVld_flg = (KIPM_BMSMaxConChrgCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S344>/Switch4' incorporates:
   *  Constant: '<S344>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S344>/Switch'
   */
  if (KIPM_BMSMaxConChrgCurnt_A_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S344>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConChrgCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S350>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S350>/Product'
     *  Switch: '<S344>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_PwrRecupMaxConChrgCurnt * 0.1F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S344>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S344>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConChrgCurntDflt_A;
  }

  /* End of Switch: '<S344>/Switch4' */

  /* MinMax: '<S344>/MinMax' incorporates:
   *  Constant: '<S344>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxConChrgCurntHi_A) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxConChrgCurntHi_A;
  }

  /* End of MinMax: '<S344>/MinMax' */

  /* MinMax: '<S344>/MinMax1' incorporates:
   *  Constant: '<S344>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxConChrgCurntLo_A) {
    /* MinMax: '<S344>/MinMax1' */
    VIPM_BMSMaxConChrgCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S344>/MinMax1' */
    VIPM_BMSMaxConChrgCurnt_A = KIPM_BMSMaxConChrgCurntLo_A;
  }

  /* End of MinMax: '<S344>/MinMax1' */
  /* End of Outputs for SubSystem: '<S311>/Subsys_VIPM_BMSMaxConChrgCurnt_A' */

  /* Outputs for Atomic SubSystem: '<S311>/Subsys_VIPM_BMSMaxInsChrgCurnt_A' */
  /* Logic: '<S346>/Logical Operator3' incorporates:
   *  Constant: '<S346>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSMaxInsChrgCurntVld_flg = (KIPM_BMSMaxInsChrgCurnt_A_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S346>/Switch4' incorporates:
   *  Constant: '<S346>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S346>/Switch'
   */
  if (KIPM_BMSMaxInsChrgCurnt_A_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S346>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsChrgCurnt_A_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S351>/Constant'
     *  Inport: '<Root>/BMS_6_DischrgRecup_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Product: '<S351>/Product'
     *  Switch: '<S346>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_6_DischrgRecup_EPT_BMS_6_DischrgRecup_EPT
       ())->BMS_PwrRecupMaxInstanChrgCurnt * 0.1F;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S346>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S346>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsChrgCurntDflt_A;
  }

  /* End of Switch: '<S346>/Switch4' */

  /* MinMax: '<S346>/MinMax' incorporates:
   *  Constant: '<S346>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSMaxInsChrgCurntHi_A) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSMaxInsChrgCurntHi_A;
  }

  /* End of MinMax: '<S346>/MinMax' */

  /* MinMax: '<S346>/MinMax1' incorporates:
   *  Constant: '<S346>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSMaxInsChrgCurntLo_A) {
    /* MinMax: '<S346>/MinMax1' */
    VIPM_BMSMaxInsChrgCurnt_A = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S346>/MinMax1' */
    VIPM_BMSMaxInsChrgCurnt_A = KIPM_BMSMaxInsChrgCurntLo_A;
  }

  /* End of MinMax: '<S346>/MinMax1' */
  /* End of Outputs for SubSystem: '<S311>/Subsys_VIPM_BMSMaxInsChrgCurnt_A' */

  /* BusCreator: '<S311>/BusCreator' incorporates:
   *  Logic: '<S344>/Logical Operator3'
   *  Logic: '<S345>/Logical Operator3'
   *  Logic: '<S346>/Logical Operator3'
   *  Logic: '<S347>/Logical Operator3'
   *  MinMax: '<S344>/MinMax1'
   *  MinMax: '<S345>/MinMax1'
   *  MinMax: '<S346>/MinMax1'
   *  MinMax: '<S347>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxConDisCurnt_A =
    VIPM_BMSMaxConDisCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxConDisCurntVld_flg =
    VIPM_BMSMaxConDisCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxInsDisCurnt_A =
    VIPM_BMSMaxInsDisCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxInsDisCurntVld_flg =
    VIPM_BMSMaxInsDisCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxConChrgCurnt_A =
    VIPM_BMSMaxConChrgCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxConChrgCurntVld_flg
    = VIPM_BMSMaxConChrgCurntVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxInsChrgCurnt_A =
    VIPM_BMSMaxInsChrgCurnt_A;
  AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m.VIPM_BMSMaxInsChrgCurntVld_flg
    = VIPM_BMSMaxInsChrgCurntVld_flg;

  /* Outputs for Atomic SubSystem: '<S312>/Subsys_VIPM_BMSCellVoltMax_mV' */
  /* Logic: '<S352>/Logical Operator3' incorporates:
   *  Constant: '<S352>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSCellVoltMaxVld_flg = (KIPM_BMSCellVoltMax_mV_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S352>/Switch4' incorporates:
   *  Constant: '<S352>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S352>/Switch'
   */
  if (KIPM_BMSCellVoltMax_mV_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S352>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMax_mV_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  DataTypeConversion: '<S352>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_7_CellVolt_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S352>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT())
      ->BMS_CellVolMax;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S352>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S352>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMaxDflt_mV;
  }

  /* End of Switch: '<S352>/Switch4' */

  /* MinMax: '<S352>/MinMax' incorporates:
   *  Constant: '<S352>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSCellVoltMaxHi_mV) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMaxHi_mV;
  }

  /* End of MinMax: '<S352>/MinMax' */

  /* MinMax: '<S352>/MinMax1' incorporates:
   *  Constant: '<S352>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV >= KIPM_BMSCellVoltMaxLo_mV) {
    /* MinMax: '<S352>/MinMax1' */
    VIPM_BMSCellVoltMax_mV = VIPM_BMSCellVoltMin_mV;
  } else {
    /* MinMax: '<S352>/MinMax1' */
    VIPM_BMSCellVoltMax_mV = KIPM_BMSCellVoltMaxLo_mV;
  }

  /* End of MinMax: '<S352>/MinMax1' */
  /* End of Outputs for SubSystem: '<S312>/Subsys_VIPM_BMSCellVoltMax_mV' */

  /* Outputs for Atomic SubSystem: '<S312>/Subsys_VIPM_BMSCellVoltMin_mV' */
  /* Logic: '<S353>/Logical Operator3' incorporates:
   *  Constant: '<S353>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_BMSCellVoltMinVld_flg = (KIPM_BMSCellVoltMin_mV_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())->VIPM_BMSMsgActv_flg);

  /* Switch: '<S353>/Switch4' incorporates:
   *  Constant: '<S353>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Switch: '<S353>/Switch'
   */
  if (KIPM_BMSCellVoltMin_mV_ovrdflg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S353>/sat4'
     *  MinMax: '<S353>/MinMax'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMin_mV_ovrdval;
  } else if ((Rte_IrvIRead_Runbl_IpmCanRx_20ms_MsgActv_outputsIRV())
             ->VIPM_BMSMsgActv_flg) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  DataTypeConversion: '<S353>/Data Type Conversion2'
     *  Inport: '<Root>/BMS_7_CellVolt_EPT'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S353>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = (float32)
      (Rte_IRead_Runbl_IpmCanRx_20ms_BMS_7_CellVolt_EPT_BMS_7_CellVolt_EPT())
      ->BMS_CellVolMin;
  } else {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  Constant: '<S353>/sat5'
     *  MinMax: '<S353>/MinMax'
     *  Switch: '<S353>/Switch'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMinDflt_mV;
  }

  /* End of Switch: '<S353>/Switch4' */

  /* MinMax: '<S353>/MinMax' incorporates:
   *  Constant: '<S353>/sat6'
   */
  if (VIPM_BMSCellVoltMin_mV > KIPM_BMSCellVoltMinHi_mV) {
    /* MinMax: '<S315>/MinMax' */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMinHi_mV;
  }

  /* End of MinMax: '<S353>/MinMax' */

  /* MinMax: '<S353>/MinMax1' incorporates:
   *  Constant: '<S353>/sat7'
   */
  if (VIPM_BMSCellVoltMin_mV < KIPM_BMSCellVoltMinLo_mV) {
    /* MinMax: '<S315>/MinMax' incorporates:
     *  MinMax: '<S353>/MinMax1'
     */
    VIPM_BMSCellVoltMin_mV = KIPM_BMSCellVoltMinLo_mV;
  }

  /* End of MinMax: '<S353>/MinMax1' */
  /* End of Outputs for SubSystem: '<S312>/Subsys_VIPM_BMSCellVoltMin_mV' */

  /* BusCreator: '<S312>/BusCreator' incorporates:
   *  Logic: '<S352>/Logical Operator3'
   *  Logic: '<S353>/Logical Operator3'
   *  MinMax: '<S352>/MinMax1'
   *  MinMax: '<S353>/MinMax1'
   */
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT_b.VIPM_BMSCellVoltMax_mV =
    VIPM_BMSCellVoltMax_mV;
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT_b.VIPM_BMSCellVoltMaxVld_flg =
    VIPM_BMSCellVoltMaxVld_flg;
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT_b.VIPM_BMSCellVoltMin_mV =
    VIPM_BMSCellVoltMin_mV;
  AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT_b.VIPM_BMSCellVoltMinVld_flg =
    VIPM_BMSCellVoltMinVld_flg;
}

/* Output and update for function-call system: '<Root>/Ipm50ms' */
static void Runbl_Ipm50ms(void)
{
  boolean rtb_LogicalOperator2_lt;

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPTempAddKey_flg' */
  /* Logic: '<S377>/Logical Operator3' incorporates:
   *  Constant: '<S377>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPTempAddKeyVld_flg = (KIPM_CCPTempAddKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S377>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S377>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S377>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S377>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nz =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_TempAddKey;
    }

    /* End of Switch: '<S377>/Switch3' */
  } else {
    /* Switch: '<S377>/Switch' incorporates:
     *  Constant: '<S377>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nz = KIPM_CCPTempAddKeyDflt_flg;
  }

  /* End of Switch: '<S377>/Switch' */

  /* Switch: '<S377>/Switch4' incorporates:
   *  Constant: '<S377>/sat3'
   */
  if (KIPM_CCPTempAddKey_flg_ovrdflg) {
    /* Switch: '<S377>/Switch4' incorporates:
     *  Constant: '<S377>/sat4'
     */
    VIPM_CCPTempAddKey_flg = KIPM_CCPTempAddKey_flg_ovrdval;
  } else {
    /* Switch: '<S377>/Switch4' */
    VIPM_CCPTempAddKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nz;
  }

  /* End of Switch: '<S377>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPTempAddKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPTempDecKey_flg' */
  /* Logic: '<S378>/Logical Operator3' incorporates:
   *  Constant: '<S378>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPTempDecKeyVld_flg = (KIPM_CCPTempDecKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S378>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S378>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S378>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S378>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5p =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_TempDecreaseKey;
    }

    /* End of Switch: '<S378>/Switch3' */
  } else {
    /* Switch: '<S378>/Switch' incorporates:
     *  Constant: '<S378>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5p = KIPM_CCPTempDecKeyDflt_flg;
  }

  /* End of Switch: '<S378>/Switch' */

  /* Switch: '<S378>/Switch4' incorporates:
   *  Constant: '<S378>/sat3'
   */
  if (KIPM_CCPTempDecKey_flg_ovrdflg) {
    /* Switch: '<S378>/Switch4' incorporates:
     *  Constant: '<S378>/sat4'
     */
    VIPM_CCPTempDecKey_flg = KIPM_CCPTempDecKey_flg_ovrdval;
  } else {
    /* Switch: '<S378>/Switch4' */
    VIPM_CCPTempDecKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_i5p;
  }

  /* End of Switch: '<S378>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPTempDecKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPBlwrLvlAddKey_flg' */
  /* Logic: '<S366>/Logical Operator3' incorporates:
   *  Constant: '<S366>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwrLvlAddKeyVld_flg = (KIPM_CCPBlwrLvlAddKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S366>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S366>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S366>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S366>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah2 =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowerLevelAddKey;
    }

    /* End of Switch: '<S366>/Switch3' */
  } else {
    /* Switch: '<S366>/Switch' incorporates:
     *  Constant: '<S366>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah2 = KIPM_CCPBlwrLvlAddKeyDflt_flg;
  }

  /* End of Switch: '<S366>/Switch' */

  /* Switch: '<S366>/Switch4' incorporates:
   *  Constant: '<S366>/sat3'
   */
  if (KIPM_CCPBlwrLvlAddKey_flg_ovrdflg) {
    /* Switch: '<S366>/Switch4' incorporates:
     *  Constant: '<S366>/sat4'
     */
    VIPM_CCPBlwrLvlAddKey_flg = KIPM_CCPBlwrLvlAddKey_flg_ovrdval;
  } else {
    /* Switch: '<S366>/Switch4' */
    VIPM_CCPBlwrLvlAddKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ah2;
  }

  /* End of Switch: '<S366>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPBlwrLvlAddKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPBlwrLvlDecKey_flg' */
  /* Logic: '<S367>/Logical Operator3' incorporates:
   *  Constant: '<S367>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwrLvlDecKeyVld_flg = (KIPM_CCPBlwrLvlDecKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S367>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S367>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S367>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S367>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ei =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowerLvlDecreaseKey;
    }

    /* End of Switch: '<S367>/Switch3' */
  } else {
    /* Switch: '<S367>/Switch' incorporates:
     *  Constant: '<S367>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ei = KIPM_CCPBlwrLvlDecKeyDflt_flg;
  }

  /* End of Switch: '<S367>/Switch' */

  /* Switch: '<S367>/Switch4' incorporates:
   *  Constant: '<S367>/sat3'
   */
  if (KIPM_CCPBlwrLvlDecKey_flg_ovrdflg) {
    /* Switch: '<S367>/Switch4' incorporates:
     *  Constant: '<S367>/sat4'
     */
    VIPM_CCPBlwrLvlDecKey_flg = KIPM_CCPBlwrLvlDecKey_flg_ovrdval;
  } else {
    /* Switch: '<S367>/Switch4' */
    VIPM_CCPBlwrLvlDecKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ei;
  }

  /* End of Switch: '<S367>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPBlwrLvlDecKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPBlwngModeNextKey_flg' */
  /* Logic: '<S364>/Logical Operator3' incorporates:
   *  Constant: '<S364>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwngModeNextKeyVld_flg = (KIPM_CCPBlwngModeNextKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S364>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S364>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S364>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S364>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bd =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowingModeNextKey;
    }

    /* End of Switch: '<S364>/Switch3' */
  } else {
    /* Switch: '<S364>/Switch' incorporates:
     *  Constant: '<S364>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bd = KIPM_CCPBlwngModeNextKeyDflt_flg;
  }

  /* End of Switch: '<S364>/Switch' */

  /* Switch: '<S364>/Switch4' incorporates:
   *  Constant: '<S364>/sat3'
   */
  if (KIPM_CCPBlwngModeNextKey_flg_ovrdflg) {
    /* Switch: '<S364>/Switch4' incorporates:
     *  Constant: '<S364>/sat4'
     */
    VIPM_CCPBlwngModeNextKey_flg = KIPM_CCPBlwngModeNextKey_flg_ovrdval;
  } else {
    /* Switch: '<S364>/Switch4' */
    VIPM_CCPBlwngModeNextKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bd;
  }

  /* End of Switch: '<S364>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPBlwngModeNextKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPBlwngModePrevKey_flg' */
  /* Logic: '<S365>/Logical Operator3' incorporates:
   *  Constant: '<S365>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPBlwngModePrevKeyVld_flg = (KIPM_CCPBlwngModePrevKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S365>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S365>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S365>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S365>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ob =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_BlowingModePreviousKey;
    }

    /* End of Switch: '<S365>/Switch3' */
  } else {
    /* Switch: '<S365>/Switch' incorporates:
     *  Constant: '<S365>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ob = KIPM_CCPBlwngModePrevKeyDflt_flg;
  }

  /* End of Switch: '<S365>/Switch' */

  /* Switch: '<S365>/Switch4' incorporates:
   *  Constant: '<S365>/sat3'
   */
  if (KIPM_CCPBlwngModePrevKey_flg_ovrdflg) {
    /* Switch: '<S365>/Switch4' incorporates:
     *  Constant: '<S365>/sat4'
     */
    VIPM_CCPBlwngModePrevKey_flg = KIPM_CCPBlwngModePrevKey_flg_ovrdval;
  } else {
    /* Switch: '<S365>/Switch4' */
    VIPM_CCPBlwngModePrevKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ob;
  }

  /* End of Switch: '<S365>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPBlwngModePrevKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPACSwKey_flg' */
  /* Logic: '<S360>/Logical Operator3' incorporates:
   *  Constant: '<S360>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPACSwKeyVld_flg = (KIPM_CCPACSwKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S360>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S360>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S360>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S360>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pz =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ACSwitchKey;
    }

    /* End of Switch: '<S360>/Switch3' */
  } else {
    /* Switch: '<S360>/Switch' incorporates:
     *  Constant: '<S360>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pz = KIPM_CCPACSwKeyDflt_flg;
  }

  /* End of Switch: '<S360>/Switch' */

  /* Switch: '<S360>/Switch4' incorporates:
   *  Constant: '<S360>/sat3'
   */
  if (KIPM_CCPACSwKey_flg_ovrdflg) {
    /* Switch: '<S360>/Switch4' incorporates:
     *  Constant: '<S360>/sat4'
     */
    VIPM_CCPACSwKey_flg = KIPM_CCPACSwKey_flg_ovrdval;
  } else {
    /* Switch: '<S360>/Switch4' */
    VIPM_CCPACSwKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_pz;
  }

  /* End of Switch: '<S360>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPACSwKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPACAutoKey_flg' */
  /* Logic: '<S359>/Logical Operator3' incorporates:
   *  Constant: '<S359>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPACAutoKeyVld_flg = (KIPM_CCPACAutoKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S359>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S359>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S359>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S359>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cr =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ACAutoKey;
    }

    /* End of Switch: '<S359>/Switch3' */
  } else {
    /* Switch: '<S359>/Switch' incorporates:
     *  Constant: '<S359>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cr = KIPM_CCPACAutoKeyDflt_flg;
  }

  /* End of Switch: '<S359>/Switch' */

  /* Switch: '<S359>/Switch4' incorporates:
   *  Constant: '<S359>/sat3'
   */
  if (KIPM_CCPACAutoKey_flg_ovrdflg) {
    /* Switch: '<S359>/Switch4' incorporates:
     *  Constant: '<S359>/sat4'
     */
    VIPM_CCPACAutoKey_flg = KIPM_CCPACAutoKey_flg_ovrdval;
  } else {
    /* Switch: '<S359>/Switch4' */
    VIPM_CCPACAutoKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cr;
  }

  /* End of Switch: '<S359>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPACAutoKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg' */
  /* Logic: '<S375>/Logical Operator3' incorporates:
   *  Constant: '<S375>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPRrViewMirrHeatgKeyVld_flg = (KIPM_CCPRrViewMirrHeatgKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S375>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S375>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S375>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S375>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dp =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_RearViewMirrHeatingKey;
    }

    /* End of Switch: '<S375>/Switch3' */
  } else {
    /* Switch: '<S375>/Switch' incorporates:
     *  Constant: '<S375>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dp = KIPM_CCPRrViewMirrHeatgKeyDflt_flg;
  }

  /* End of Switch: '<S375>/Switch' */

  /* Switch: '<S375>/Switch4' incorporates:
   *  Constant: '<S375>/sat3'
   */
  if (KIPM_CCPRrViewMirrHeatgKey_flg_ovrdflg) {
    /* Switch: '<S375>/Switch4' incorporates:
     *  Constant: '<S375>/sat4'
     */
    VIPM_CCPRrViewMirrHeatgKey_flg = KIPM_CCPRrViewMirrHeatgKey_flg_ovrdval;
  } else {
    /* Switch: '<S375>/Switch4' */
    VIPM_CCPRrViewMirrHeatgKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dp;
  }

  /* End of Switch: '<S375>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPRrViewMirrHeatgKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPAirInletModeKey_flg' */
  /* Logic: '<S363>/Logical Operator3' incorporates:
   *  Constant: '<S363>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPAirInletModeKeyVld_flg = (KIPM_CCPAirInletModeKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S363>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S363>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S363>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S363>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_go =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_AirInletModeKey;
    }

    /* End of Switch: '<S363>/Switch3' */
  } else {
    /* Switch: '<S363>/Switch' incorporates:
     *  Constant: '<S363>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_go = KIPM_CCPAirInletModeKeyDflt_flg;
  }

  /* End of Switch: '<S363>/Switch' */

  /* Switch: '<S363>/Switch4' incorporates:
   *  Constant: '<S363>/sat3'
   */
  if (KIPM_CCPAirInletModeKey_flg_ovrdflg) {
    /* Switch: '<S363>/Switch4' incorporates:
     *  Constant: '<S363>/sat4'
     */
    VIPM_CCPAirInletModeKey_flg = KIPM_CCPAirInletModeKey_flg_ovrdval;
  } else {
    /* Switch: '<S363>/Switch4' */
    VIPM_CCPAirInletModeKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_go;
  }

  /* End of Switch: '<S363>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPAirInletModeKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPFrntWindDefrstKey_flg' */
  /* Logic: '<S370>/Logical Operator3' incorporates:
   *  Constant: '<S370>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPFrntWindDefrstKeyVld_flg = (KIPM_CCPFrntWindDefrstKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S370>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S370>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S370>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S370>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ab =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_FrontWindDefrostKey;
    }

    /* End of Switch: '<S370>/Switch3' */
  } else {
    /* Switch: '<S370>/Switch' incorporates:
     *  Constant: '<S370>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ab = KIPM_CCPFrntWindDefrstKeyDflt_flg;
  }

  /* End of Switch: '<S370>/Switch' */

  /* Switch: '<S370>/Switch4' incorporates:
   *  Constant: '<S370>/sat3'
   */
  if (KIPM_CCPFrntWindDefrstKey_flg_ovrdflg) {
    /* Switch: '<S370>/Switch4' incorporates:
     *  Constant: '<S370>/sat4'
     */
    VIPM_CCPFrntWindDefrstKey_flg = KIPM_CCPFrntWindDefrstKey_flg_ovrdval;
  } else {
    /* Switch: '<S370>/Switch4' */
    VIPM_CCPFrntWindDefrstKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ab;
  }

  /* End of Switch: '<S370>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPFrntWindDefrstKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPModeKey_flg' */
  /* Logic: '<S373>/Logical Operator3' incorporates:
   *  Constant: '<S373>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPModeKeyVld_flg = (KIPM_CCPModeKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S373>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S373>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S373>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S373>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p1 =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ModeKey;
    }

    /* End of Switch: '<S373>/Switch3' */
  } else {
    /* Switch: '<S373>/Switch' incorporates:
     *  Constant: '<S373>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p1 = KIPM_CCPModeKeyDflt_flg;
  }

  /* End of Switch: '<S373>/Switch' */

  /* Switch: '<S373>/Switch4' incorporates:
   *  Constant: '<S373>/sat3'
   */
  if (KIPM_CCPModeKey_flg_ovrdflg) {
    /* Switch: '<S373>/Switch4' incorporates:
     *  Constant: '<S373>/sat4'
     */
    VIPM_CCPModeKey_flg = KIPM_CCPModeKey_flg_ovrdval;
  } else {
    /* Switch: '<S373>/Switch4' */
    VIPM_CCPModeKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_p1;
  }

  /* End of Switch: '<S373>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPModeKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPHzrdKey_flg' */
  /* Logic: '<S372>/Logical Operator3' incorporates:
   *  Constant: '<S372>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPHzrdKeyVld_flg = (KIPM_CCPHzrdKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S372>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S372>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S372>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S372>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_it =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_HazardKey;
    }

    /* End of Switch: '<S372>/Switch3' */
  } else {
    /* Switch: '<S372>/Switch' incorporates:
     *  Constant: '<S372>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_it = KIPM_CCPHzrdKeyDflt_flg;
  }

  /* End of Switch: '<S372>/Switch' */

  /* Switch: '<S372>/Switch4' incorporates:
   *  Constant: '<S372>/sat3'
   */
  if (KIPM_CCPHzrdKey_flg_ovrdflg) {
    /* Switch: '<S372>/Switch4' incorporates:
     *  Constant: '<S372>/sat4'
     */
    VIPM_CCPHzrdKey_flg = KIPM_CCPHzrdKey_flg_ovrdval;
  } else {
    /* Switch: '<S372>/Switch4' */
    VIPM_CCPHzrdKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_it;
  }

  /* End of Switch: '<S372>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPHzrdKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPCenLckKey_flg' */
  /* Logic: '<S368>/Logical Operator3' incorporates:
   *  Constant: '<S368>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPCenLckKeyVld_flg = (KIPM_CCPCenLckKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S368>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S368>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S368>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S368>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eo =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_CentralLockKey;
    }

    /* End of Switch: '<S368>/Switch3' */
  } else {
    /* Switch: '<S368>/Switch' incorporates:
     *  Constant: '<S368>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eo = KIPM_CCPCenLckKeyDflt_flg;
  }

  /* End of Switch: '<S368>/Switch' */

  /* Switch: '<S368>/Switch4' incorporates:
   *  Constant: '<S368>/sat3'
   */
  if (KIPM_CCPCenLckKey_flg_ovrdflg) {
    /* Switch: '<S368>/Switch4' incorporates:
     *  Constant: '<S368>/sat4'
     */
    VIPM_CCPCenLckKey_flg = KIPM_CCPCenLckKey_flg_ovrdval;
  } else {
    /* Switch: '<S368>/Switch4' */
    VIPM_CCPCenLckKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_eo;
  }

  /* End of Switch: '<S368>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPCenLckKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPTPMSKey_flg' */
  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S376>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPTPMSKeyVld_flg = (KIPM_CCPTPMSKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S376>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S376>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S376>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S376>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1e =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_TPMSKey;
    }

    /* End of Switch: '<S376>/Switch3' */
  } else {
    /* Switch: '<S376>/Switch' incorporates:
     *  Constant: '<S376>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1e = KIPM_CCPTPMSKeyDflt_flg;
  }

  /* End of Switch: '<S376>/Switch' */

  /* Switch: '<S376>/Switch4' incorporates:
   *  Constant: '<S376>/sat3'
   */
  if (KIPM_CCPTPMSKey_flg_ovrdflg) {
    /* Switch: '<S376>/Switch4' incorporates:
     *  Constant: '<S376>/sat4'
     */
    VIPM_CCPTPMSKey_flg = KIPM_CCPTPMSKey_flg_ovrdval;
  } else {
    /* Switch: '<S376>/Switch4' */
    VIPM_CCPTPMSKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_e1e;
  }

  /* End of Switch: '<S376>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPTPMSKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPESCOffKey_flg' */
  /* Logic: '<S369>/Logical Operator3' incorporates:
   *  Constant: '<S369>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPESCOffKeyVld_flg = (KIPM_CCPESCOffKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S369>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S369>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S369>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S369>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_phn =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_ESCOFFKey;
    }

    /* End of Switch: '<S369>/Switch3' */
  } else {
    /* Switch: '<S369>/Switch' incorporates:
     *  Constant: '<S369>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_phn = KIPM_CCPESCOffKeyDflt_flg;
  }

  /* End of Switch: '<S369>/Switch' */

  /* Switch: '<S369>/Switch4' incorporates:
   *  Constant: '<S369>/sat3'
   */
  if (KIPM_CCPESCOffKey_flg_ovrdflg) {
    /* Switch: '<S369>/Switch4' incorporates:
     *  Constant: '<S369>/sat4'
     */
    VIPM_CCPESCOffKey_flg = KIPM_CCPESCOffKey_flg_ovrdval;
  } else {
    /* Switch: '<S369>/Switch4' */
    VIPM_CCPESCOffKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_phn;
  }

  /* End of Switch: '<S369>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPESCOffKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPAVASOffKey_flg' */
  /* Logic: '<S361>/Logical Operator3' incorporates:
   *  Constant: '<S361>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPAVASOffKeyVld_flg = (KIPM_CCPAVASOffKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S361>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S361>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S361>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S361>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ky =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_AVASOffKey;
    }

    /* End of Switch: '<S361>/Switch3' */
  } else {
    /* Switch: '<S361>/Switch' incorporates:
     *  Constant: '<S361>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ky = KIPM_CCPAVASOffKeyDflt_flg;
  }

  /* End of Switch: '<S361>/Switch' */

  /* Switch: '<S361>/Switch4' incorporates:
   *  Constant: '<S361>/sat3'
   */
  if (KIPM_CCPAVASOffKey_flg_ovrdflg) {
    /* Switch: '<S361>/Switch4' incorporates:
     *  Constant: '<S361>/sat4'
     */
    VIPM_CCPAVASOffKey_flg = KIPM_CCPAVASOffKey_flg_ovrdval;
  } else {
    /* Switch: '<S361>/Switch4' */
    VIPM_CCPAVASOffKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ky;
  }

  /* End of Switch: '<S361>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPAVASOffKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPHDCKey_flg' */
  /* Logic: '<S371>/Logical Operator3' incorporates:
   *  Constant: '<S371>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPHDCKeyVld_flg = (KIPM_CCPHDCKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S371>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S371>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S371>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S371>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kd =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_HDCKey;
    }

    /* End of Switch: '<S371>/Switch3' */
  } else {
    /* Switch: '<S371>/Switch' incorporates:
     *  Constant: '<S371>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kd = KIPM_CCPHDCKeyDflt_flg;
  }

  /* End of Switch: '<S371>/Switch' */

  /* Switch: '<S371>/Switch4' incorporates:
   *  Constant: '<S371>/sat3'
   */
  if (KIPM_CCPHDCKey_flg_ovrdflg) {
    /* Switch: '<S371>/Switch4' incorporates:
     *  Constant: '<S371>/sat4'
     */
    VIPM_CCPHDCKey_flg = KIPM_CCPHDCKey_flg_ovrdval;
  } else {
    /* Switch: '<S371>/Switch4' */
    VIPM_CCPHDCKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_kd;
  }

  /* End of Switch: '<S371>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPHDCKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPAVHKey_flg' */
  /* Logic: '<S362>/Logical Operator3' incorporates:
   *  Constant: '<S362>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPAVHKeyVld_flg = (KIPM_CCPAVHKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S362>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S362>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S362>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S362>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jb =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_AVHKey;
    }

    /* End of Switch: '<S362>/Switch3' */
  } else {
    /* Switch: '<S362>/Switch' incorporates:
     *  Constant: '<S362>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jb = KIPM_CCPAVHKeyDflt_flg;
  }

  /* End of Switch: '<S362>/Switch' */

  /* Switch: '<S362>/Switch4' incorporates:
   *  Constant: '<S362>/sat3'
   */
  if (KIPM_CCPAVHKey_flg_ovrdflg) {
    /* Switch: '<S362>/Switch4' incorporates:
     *  Constant: '<S362>/sat4'
     */
    VIPM_CCPAVHKey_flg = KIPM_CCPAVHKey_flg_ovrdval;
  } else {
    /* Switch: '<S362>/Switch4' */
    VIPM_CCPAVHKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_jb;
  }

  /* End of Switch: '<S362>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPAVHKey_flg' */

  /* Outputs for Atomic SubSystem: '<S356>/Subsys_VIPM_CCPPwrRecupLvlKey_flg' */
  /* Logic: '<S374>/Logical Operator3' incorporates:
   *  Constant: '<S374>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_CCPPwrRecupLvlKeyVld_flg = (KIPM_CCPPwrRecupLvlKey_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_CCPMsgActv_flg);

  /* Switch: '<S374>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_CCPMsgActv_flg) {
    /* Switch: '<S374>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_CCP_PanelStatus_CRCFlt_flg) {
      /* Switch: '<S374>/Switch' incorporates:
       *  Inport: '<Root>/CCP_PanelStatus_BOD'
       *  Switch: '<S374>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b1 =
        (Rte_IRead_Runbl_IpmCanRx_50ms_CCP_PanelStatus_BOD_CCP_PanelStatus_BOD())
        ->CCP_PwrRecupLevelKey;
    }

    /* End of Switch: '<S374>/Switch3' */
  } else {
    /* Switch: '<S374>/Switch' incorporates:
     *  Constant: '<S374>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b1 = KIPM_CCPPwrRecupLvlKeyDflt_flg;
  }

  /* End of Switch: '<S374>/Switch' */

  /* Switch: '<S374>/Switch4' incorporates:
   *  Constant: '<S374>/sat3'
   */
  if (KIPM_CCPPwrRecupLvlKey_flg_ovrdflg) {
    /* Switch: '<S374>/Switch4' incorporates:
     *  Constant: '<S374>/sat4'
     */
    VIPM_CCPPwrRecupLvlKey_flg = KIPM_CCPPwrRecupLvlKey_flg_ovrdval;
  } else {
    /* Switch: '<S374>/Switch4' */
    VIPM_CCPPwrRecupLvlKey_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_b1;
  }

  /* End of Switch: '<S374>/Switch4' */
  /* End of Outputs for SubSystem: '<S356>/Subsys_VIPM_CCPPwrRecupLvlKey_flg' */

  /* BusCreator: '<S356>/BusCreator' incorporates:
   *  Logic: '<S359>/Logical Operator3'
   *  Logic: '<S360>/Logical Operator3'
   *  Logic: '<S361>/Logical Operator3'
   *  Logic: '<S362>/Logical Operator3'
   *  Logic: '<S363>/Logical Operator3'
   *  Logic: '<S364>/Logical Operator3'
   *  Logic: '<S365>/Logical Operator3'
   *  Logic: '<S366>/Logical Operator3'
   *  Logic: '<S367>/Logical Operator3'
   *  Logic: '<S368>/Logical Operator3'
   *  Logic: '<S369>/Logical Operator3'
   *  Logic: '<S370>/Logical Operator3'
   *  Logic: '<S371>/Logical Operator3'
   *  Logic: '<S372>/Logical Operator3'
   *  Logic: '<S373>/Logical Operator3'
   *  Logic: '<S374>/Logical Operator3'
   *  Logic: '<S375>/Logical Operator3'
   *  Logic: '<S376>/Logical Operator3'
   *  Logic: '<S377>/Logical Operator3'
   *  Logic: '<S378>/Logical Operator3'
   *  Switch: '<S359>/Switch4'
   *  Switch: '<S360>/Switch4'
   *  Switch: '<S361>/Switch4'
   *  Switch: '<S362>/Switch4'
   *  Switch: '<S363>/Switch4'
   *  Switch: '<S364>/Switch4'
   *  Switch: '<S365>/Switch4'
   *  Switch: '<S366>/Switch4'
   *  Switch: '<S367>/Switch4'
   *  Switch: '<S368>/Switch4'
   *  Switch: '<S369>/Switch4'
   *  Switch: '<S370>/Switch4'
   *  Switch: '<S371>/Switch4'
   *  Switch: '<S372>/Switch4'
   *  Switch: '<S373>/Switch4'
   *  Switch: '<S374>/Switch4'
   *  Switch: '<S375>/Switch4'
   *  Switch: '<S376>/Switch4'
   *  Switch: '<S377>/Switch4'
   *  Switch: '<S378>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPTempAddKey_flg =
    VIPM_CCPTempAddKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPTempAddKeyVld_flg =
    VIPM_CCPTempAddKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPTempDecKey_flg =
    VIPM_CCPTempDecKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPTempDecKeyVld_flg =
    VIPM_CCPTempDecKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwrLvlAddKey_flg =
    VIPM_CCPBlwrLvlAddKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwrLvlAddKeyVld_flg =
    VIPM_CCPBlwrLvlAddKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwrLvlDecKey_flg =
    VIPM_CCPBlwrLvlDecKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwrLvlDecKeyVld_flg =
    VIPM_CCPBlwrLvlDecKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwngModeNextKey_flg =
    VIPM_CCPBlwngModeNextKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwngModeNextKeyVld_flg =
    VIPM_CCPBlwngModeNextKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwngModePrevKey_flg =
    VIPM_CCPBlwngModePrevKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPBlwngModePrevKeyVld_flg =
    VIPM_CCPBlwngModePrevKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPACSwKey_flg =
    VIPM_CCPACSwKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPACSwKeyVld_flg =
    VIPM_CCPACSwKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPACAutoKey_flg =
    VIPM_CCPACAutoKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPACAutoKeyVld_flg =
    VIPM_CCPACAutoKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPRrViewMirrHeatgKey_flg =
    VIPM_CCPRrViewMirrHeatgKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPRrViewMirrHeatgKeyVld_flg
    = VIPM_CCPRrViewMirrHeatgKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPAirInletModeKey_flg =
    VIPM_CCPAirInletModeKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPAirInletModeKeyVld_flg =
    VIPM_CCPAirInletModeKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPFrntWindDefrstKey_flg =
    VIPM_CCPFrntWindDefrstKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPFrntWindDefrstKeyVld_flg =
    VIPM_CCPFrntWindDefrstKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPModeKey_flg =
    VIPM_CCPModeKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPModeKeyVld_flg =
    VIPM_CCPModeKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPHzrdKey_flg =
    VIPM_CCPHzrdKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPHzrdKeyVld_flg =
    VIPM_CCPHzrdKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPCenLckKey_flg =
    VIPM_CCPCenLckKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPCenLckKeyVld_flg =
    VIPM_CCPCenLckKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPTPMSKey_flg =
    VIPM_CCPTPMSKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPTPMSKeyVld_flg =
    VIPM_CCPTPMSKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPESCOffKey_flg =
    VIPM_CCPESCOffKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPESCOffKeyVld_flg =
    VIPM_CCPESCOffKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPAVASOffKey_flg =
    VIPM_CCPAVASOffKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPAVASOffKeyVld_flg =
    VIPM_CCPAVASOffKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPHDCKey_flg =
    VIPM_CCPHDCKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPHDCKeyVld_flg =
    VIPM_CCPHDCKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPAVHKey_flg =
    VIPM_CCPAVHKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPAVHKeyVld_flg =
    VIPM_CCPAVHKeyVld_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPPwrRecupLvlKey_flg =
    VIPM_CCPPwrRecupLvlKey_flg;
  AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p.VIPM_CCPPwrRecupLvlKeyVld_flg =
    VIPM_CCPPwrRecupLvlKeyVld_flg;

  /* Outputs for Atomic SubSystem: '<S357>/Subsys_VIPM_ESCLUnOrLockfeedback_nu' */
  /* Logic: '<S379>/Logical Operator3' incorporates:
   *  Constant: '<S379>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_ESCLUnOrLockfeedbackVld_flg = (KIPM_ESCLUnOrLockfeedback_nu_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
    ->VIPM_ESCLMsgActv_flg);

  /* Switch: '<S379>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_ESCLMsgActv_flg) {
    /* Switch: '<S379>/Switch' incorporates:
     *  Inport: '<Root>/ESCL_ESCLStatus_BOD'
     *  Switch: '<S379>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE =
      (Rte_IRead_Runbl_IpmCanRx_50ms_ESCL_ESCLStatus_BOD_ESCL_ESCLStatus_BOD()
      )->ESCL_UnOrLock_feedback;
  } else {
    /* Switch: '<S379>/Switch' incorporates:
     *  Constant: '<S379>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE = KIPM_ESCLUnOrLockfeedbackDflt_nu;
  }

  /* End of Switch: '<S379>/Switch' */

  /* Switch: '<S379>/Switch4' incorporates:
   *  Constant: '<S379>/sat3'
   */
  if (KIPM_ESCLUnOrLockfeedback_nu_ovrdflg) {
    /* Switch: '<S379>/Switch4' incorporates:
     *  Constant: '<S379>/sat4'
     */
    VIPM_ESCLUnOrLockfeedback_nu = KIPM_ESCLUnOrLockfeedback_nu_ovrdval;
  } else {
    /* Switch: '<S379>/Switch4' incorporates:
     *  Switch: '<S379>/Switch'
     */
    VIPM_ESCLUnOrLockfeedback_nu = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE;
  }

  /* End of Switch: '<S379>/Switch4' */
  /* End of Outputs for SubSystem: '<S357>/Subsys_VIPM_ESCLUnOrLockfeedback_nu' */

  /* BusCreator: '<S357>/BusCreator' incorporates:
   *  Logic: '<S379>/Logical Operator3'
   *  Switch: '<S379>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_ESCL_ESCLStatus_BOD_b.VIPM_ESCLUnOrLockfeedback_nu =
    VIPM_ESCLUnOrLockfeedback_nu;
  AppSwcIpm_ARID_DEF.IPM_ESCL_ESCLStatus_BOD_b.VIPM_ESCLUnOrLockfeedbackVld_flg =
    VIPM_ESCLUnOrLockfeedbackVld_flg;

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSFrntWshrSwtSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S381>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_FrntWshrSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S381>/Logical Operator3' incorporates:
   *  Constant: '<S381>/sat3'
   */
  VIPM_SCSFrntWshrSwtStVld_flg = (KIPM_SCSFrntWshrSwtSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S381>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S381>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S381>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1 =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_FrntWshrSwtSt;
  } else {
    /* Switch: '<S381>/Switch' incorporates:
     *  Constant: '<S381>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1 = KIPM_SCSFrntWshrSwtStDflt_flg;
  }

  /* End of Switch: '<S381>/Switch' */

  /* Switch: '<S381>/Switch4' incorporates:
   *  Constant: '<S381>/sat3'
   */
  if (KIPM_SCSFrntWshrSwtSt_flg_ovrdflg) {
    /* Switch: '<S381>/Switch4' incorporates:
     *  Constant: '<S381>/sat4'
     */
    VIPM_SCSFrntWshrSwtSt_flg = KIPM_SCSFrntWshrSwtSt_flg_ovrdval;
  } else {
    /* Switch: '<S381>/Switch4' */
    VIPM_SCSFrntWshrSwtSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_f1;
  }

  /* End of Switch: '<S381>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSFrntWshrSwtSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSFrntWiprSwtSt_enum' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S380>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_WiprSwtStVD && (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S380>/Logical Operator3' incorporates:
   *  Constant: '<S380>/sat3'
   */
  VIPM_SCSFrntWiprSwtStVld_flg = (KIPM_SCSFrntWiprSwtSt_enum_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S380>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S380>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S380>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nh =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_FrntWiprSwtSt;
  } else {
    /* Switch: '<S380>/Switch' incorporates:
     *  Constant: '<S380>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nh = KIPM_SCSFrntWiprSwtStDflt_enum;
  }

  /* End of Switch: '<S380>/Switch' */

  /* Switch: '<S380>/Switch4' incorporates:
   *  Constant: '<S380>/sat3'
   */
  if (KIPM_SCSFrntWiprSwtSt_enum_ovrdflg) {
    /* Switch: '<S380>/Switch4' incorporates:
     *  Constant: '<S380>/sat4'
     */
    VIPM_SCSFrntWiprSwtSt_enum = KIPM_SCSFrntWiprSwtSt_enum_ovrdval;
  } else {
    /* Switch: '<S380>/Switch4' */
    VIPM_SCSFrntWiprSwtSt_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_nh;
  }

  /* End of Switch: '<S380>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSFrntWiprSwtSt_enum' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSPstnLghtSwSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S387>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_KnobBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S387>/Logical Operator3' incorporates:
   *  Constant: '<S387>/sat3'
   */
  VIPM_SCSPstnLghtSwStVld_flg = (KIPM_SCSPstnLghtSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S387>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S387>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S387>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ko =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_PositionLightswitchSt;
  } else {
    /* Switch: '<S387>/Switch' incorporates:
     *  Constant: '<S387>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ko = KIPM_SCSPstnLghtSwStDflt_flg;
  }

  /* End of Switch: '<S387>/Switch' */

  /* Switch: '<S387>/Switch4' incorporates:
   *  Constant: '<S387>/sat3'
   */
  if (KIPM_SCSPstnLghtSwSt_flg_ovrdflg) {
    /* Switch: '<S387>/Switch4' incorporates:
     *  Constant: '<S387>/sat4'
     */
    VIPM_SCSPstnLghtSwSt_flg = KIPM_SCSPstnLghtSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S387>/Switch4' */
    VIPM_SCSPstnLghtSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ko;
  }

  /* End of Switch: '<S387>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSPstnLghtSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSLoBeamSwSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S385>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_KnobBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S385>/Logical Operator3' incorporates:
   *  Constant: '<S385>/sat3'
   */
  VIPM_SCSLoBeamSwStVld_flg = (KIPM_SCSLoBeamSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S385>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S385>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S385>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_oa =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_LowBeamSwtSt;
  } else {
    /* Switch: '<S385>/Switch' incorporates:
     *  Constant: '<S385>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_oa = KIPM_SCSLoBeamSwStDflt_flg;
  }

  /* End of Switch: '<S385>/Switch' */

  /* Switch: '<S385>/Switch4' incorporates:
   *  Constant: '<S385>/sat3'
   */
  if (KIPM_SCSLoBeamSwSt_flg_ovrdflg) {
    /* Switch: '<S385>/Switch4' incorporates:
     *  Constant: '<S385>/sat4'
     */
    VIPM_SCSLoBeamSwSt_flg = KIPM_SCSLoBeamSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S385>/Switch4' */
    VIPM_SCSLoBeamSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_oa;
  }

  /* End of Switch: '<S385>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSLoBeamSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSHiBeamSwSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S382>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S382>/Logical Operator3' incorporates:
   *  Constant: '<S382>/sat3'
   */
  VIPM_SCSHiBeamSwStVld_flg = (KIPM_SCSHiBeamSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S382>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S382>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S382>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dcs =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_HiBeamSwtSt;
  } else {
    /* Switch: '<S382>/Switch' incorporates:
     *  Constant: '<S382>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dcs = KIPM_SCSHiBeamSwStDflt_flg;
  }

  /* End of Switch: '<S382>/Switch' */

  /* Switch: '<S382>/Switch4' incorporates:
   *  Constant: '<S382>/sat3'
   */
  if (KIPM_SCSHiBeamSwSt_flg_ovrdflg) {
    /* Switch: '<S382>/Switch4' incorporates:
     *  Constant: '<S382>/sat4'
     */
    VIPM_SCSHiBeamSwSt_flg = KIPM_SCSHiBeamSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S382>/Switch4' */
    VIPM_SCSHiBeamSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_dcs;
  }

  /* End of Switch: '<S382>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSHiBeamSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSOvrVehBeamSwSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S386>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S386>/Logical Operator3' incorporates:
   *  Constant: '<S386>/sat3'
   */
  VIPM_SCSOvrVehBeamSwStVld_flg = (KIPM_SCSOvrVehBeamSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S386>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S386>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S386>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cds =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_OverVehBeamSwtSt;
  } else {
    /* Switch: '<S386>/Switch' incorporates:
     *  Constant: '<S386>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cds = KIPM_SCSOvrVehBeamSwStDflt_flg;
  }

  /* End of Switch: '<S386>/Switch' */

  /* Switch: '<S386>/Switch4' incorporates:
   *  Constant: '<S386>/sat3'
   */
  if (KIPM_SCSOvrVehBeamSwSt_flg_ovrdflg) {
    /* Switch: '<S386>/Switch4' incorporates:
     *  Constant: '<S386>/sat4'
     */
    VIPM_SCSOvrVehBeamSwSt_flg = KIPM_SCSOvrVehBeamSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S386>/Switch4' */
    VIPM_SCSOvrVehBeamSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_cds;
  }

  /* End of Switch: '<S386>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSOvrVehBeamSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSLampAutoSt_flg' */
  /* Logic: '<S383>/Logical Operator3' incorporates:
   *  Constant: '<S383>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SCSLampAutoStVld_flg = (KIPM_SCSLampAutoSt_flg_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_SCSMsgActv_flg);

  /* Switch: '<S383>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_SCSMsgActv_flg) {
    /* Switch: '<S383>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S383>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bc =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_LampAutoSt;
  } else {
    /* Switch: '<S383>/Switch' incorporates:
     *  Constant: '<S383>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bc = KIPM_SCSLampAutoStDflt_flg;
  }

  /* End of Switch: '<S383>/Switch' */

  /* Switch: '<S383>/Switch4' incorporates:
   *  Constant: '<S383>/sat3'
   */
  if (KIPM_SCSLampAutoSt_flg_ovrdflg) {
    /* Switch: '<S383>/Switch4' incorporates:
     *  Constant: '<S383>/sat4'
     */
    VIPM_SCSLampAutoSt_flg = KIPM_SCSLampAutoSt_flg_ovrdval;
  } else {
    /* Switch: '<S383>/Switch4' */
    VIPM_SCSLampAutoSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_bc;
  }

  /* End of Switch: '<S383>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSLampAutoSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSLeTrnLmpSwSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S384>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S384>/Logical Operator3' incorporates:
   *  Constant: '<S384>/sat3'
   */
  VIPM_SCSLeTrnLmpSwStVld_flg = (KIPM_SCSLeTrnLmpSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S384>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S384>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S384>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_du =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_LeTurnLmpSwtSt;
  } else {
    /* Switch: '<S384>/Switch' incorporates:
     *  Constant: '<S384>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_du = KIPM_SCSLeTrnLmpSwStDflt_flg;
  }

  /* End of Switch: '<S384>/Switch' */

  /* Switch: '<S384>/Switch4' incorporates:
   *  Constant: '<S384>/sat3'
   */
  if (KIPM_SCSLeTrnLmpSwSt_flg_ovrdflg) {
    /* Switch: '<S384>/Switch4' incorporates:
     *  Constant: '<S384>/sat4'
     */
    VIPM_SCSLeTrnLmpSwSt_flg = KIPM_SCSLeTrnLmpSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S384>/Switch4' */
    VIPM_SCSLeTrnLmpSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_du;
  }

  /* End of Switch: '<S384>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSLeTrnLmpSwSt_flg' */

  /* Outputs for Atomic SubSystem: '<S358>/Subsys_VIPM_SCSRiTrnLmpSwSt_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
   *  Logic: '<S388>/Logical Operator2'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD())
     ->SCS_RodBeamSwtStVD &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SCSMsgActv_flg);

  /* Logic: '<S388>/Logical Operator3' incorporates:
   *  Constant: '<S388>/sat3'
   */
  VIPM_SCSRiTrnLmpSwStVld_flg = (KIPM_SCSRiTrnLmpSwSt_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S388>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S388>/Switch' incorporates:
     *  Inport: '<Root>/SCS_LeSwitchSts_BOD'
     *  Switch: '<S388>/Switch3'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ds =
      (Rte_IRead_Runbl_IpmCanRx_50ms_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_BOD()
      )->SCS_RiTurnLmpSwtSt;
  } else {
    /* Switch: '<S388>/Switch' incorporates:
     *  Constant: '<S388>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ds = KIPM_SCSRiTrnLmpSwStDflt_flg;
  }

  /* End of Switch: '<S388>/Switch' */

  /* Switch: '<S388>/Switch4' incorporates:
   *  Constant: '<S388>/sat3'
   */
  if (KIPM_SCSRiTrnLmpSwSt_flg_ovrdflg) {
    /* Switch: '<S388>/Switch4' incorporates:
     *  Constant: '<S388>/sat4'
     */
    VIPM_SCSRiTrnLmpSwSt_flg = KIPM_SCSRiTrnLmpSwSt_flg_ovrdval;
  } else {
    /* Switch: '<S388>/Switch4' */
    VIPM_SCSRiTrnLmpSwSt_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_ds;
  }

  /* End of Switch: '<S388>/Switch4' */
  /* End of Outputs for SubSystem: '<S358>/Subsys_VIPM_SCSRiTrnLmpSwSt_flg' */

  /* BusCreator: '<S358>/BusCreator' incorporates:
   *  Logic: '<S380>/Logical Operator3'
   *  Logic: '<S381>/Logical Operator3'
   *  Logic: '<S382>/Logical Operator3'
   *  Logic: '<S383>/Logical Operator3'
   *  Logic: '<S384>/Logical Operator3'
   *  Logic: '<S385>/Logical Operator3'
   *  Logic: '<S386>/Logical Operator3'
   *  Logic: '<S387>/Logical Operator3'
   *  Logic: '<S388>/Logical Operator3'
   *  Switch: '<S380>/Switch4'
   *  Switch: '<S381>/Switch4'
   *  Switch: '<S382>/Switch4'
   *  Switch: '<S383>/Switch4'
   *  Switch: '<S384>/Switch4'
   *  Switch: '<S385>/Switch4'
   *  Switch: '<S386>/Switch4'
   *  Switch: '<S387>/Switch4'
   *  Switch: '<S388>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSFrntWshrSwtSt_flg =
    VIPM_SCSFrntWshrSwtSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSFrntWshrSwtStVld_flg =
    VIPM_SCSFrntWshrSwtStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSFrntWiprSwtSt_enum =
    VIPM_SCSFrntWiprSwtSt_enum;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSFrntWiprSwtStVld_flg =
    VIPM_SCSFrntWiprSwtStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSPstnLghtSwSt_flg =
    VIPM_SCSPstnLghtSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSPstnLghtSwStVld_flg =
    VIPM_SCSPstnLghtSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSLoBeamSwSt_flg =
    VIPM_SCSLoBeamSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSLoBeamSwStVld_flg =
    VIPM_SCSLoBeamSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSHiBeamSwSt_flg =
    VIPM_SCSHiBeamSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSHiBeamSwStVld_flg =
    VIPM_SCSHiBeamSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSOvrVehBeamSwSt_flg =
    VIPM_SCSOvrVehBeamSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSOvrVehBeamSwStVld_flg =
    VIPM_SCSOvrVehBeamSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSLampAutoSt_flg =
    VIPM_SCSLampAutoSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSLampAutoStVld_flg =
    VIPM_SCSLampAutoStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSLeTrnLmpSwSt_flg =
    VIPM_SCSLeTrnLmpSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSLeTrnLmpSwStVld_flg =
    VIPM_SCSLeTrnLmpSwStVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSRiTrnLmpSwSt_flg =
    VIPM_SCSRiTrnLmpSwSt_flg;
  AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l.VIPM_SCSRiTrnLmpSwStVld_flg =
    VIPM_SCSRiTrnLmpSwStVld_flg;

  /* Outputs for Atomic SubSystem: '<S389>/Subsys_VIPM_SRSDrvSeatbeltBkld_flg' */
  /* Logic: '<S391>/Logical Operator2' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   *  Inport: '<Root>/SRS_1_Status_CHA'
   */
  rtb_LogicalOperator2_lt =
    ((Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA())
     ->SRS_DrvSeatbeltBuckleValid &&
     (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
     ->VIPM_SRSMsgActv_flg);

  /* Logic: '<S391>/Logical Operator3' incorporates:
   *  Constant: '<S391>/sat3'
   */
  VIPM_SRSDrvSeatbeltBkldVld_flg = (KIPM_SRSDrvSeatbeltBkld_flg_ovrdflg ||
    rtb_LogicalOperator2_lt);

  /* Switch: '<S391>/Switch' */
  if (rtb_LogicalOperator2_lt) {
    /* Switch: '<S391>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SRS_1_Status_CRCFlt_flg) {
      /* Switch: '<S391>/Switch' incorporates:
       *  Inport: '<Root>/SRS_1_Status_CHA'
       *  Switch: '<S391>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fl =
        (Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA())
        ->SRS_DrvSeatbeltBucklestatus;
    }

    /* End of Switch: '<S391>/Switch3' */
  } else {
    /* Switch: '<S391>/Switch' incorporates:
     *  Constant: '<S391>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fl = KIPM_SRSDrvSeatbeltBkldDflt_flg;
  }

  /* End of Switch: '<S391>/Switch' */

  /* Switch: '<S391>/Switch4' incorporates:
   *  Constant: '<S391>/sat3'
   */
  if (KIPM_SRSDrvSeatbeltBkld_flg_ovrdflg) {
    /* Switch: '<S391>/Switch4' incorporates:
     *  Constant: '<S391>/sat4'
     */
    VIPM_SRSDrvSeatbeltBkld_flg = KIPM_SRSDrvSeatbeltBkld_flg_ovrdval;
  } else {
    /* Switch: '<S391>/Switch4' */
    VIPM_SRSDrvSeatbeltBkld_flg = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fl;
  }

  /* End of Switch: '<S391>/Switch4' */
  /* End of Outputs for SubSystem: '<S389>/Subsys_VIPM_SRSDrvSeatbeltBkld_flg' */

  /* Outputs for Atomic SubSystem: '<S389>/Subsys_VIPM_SRSCrashOutputSts_enum' */
  /* Logic: '<S390>/Logical Operator3' incorporates:
   *  Constant: '<S390>/sat3'
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  VIPM_SRSCrashOutputStsVld_flg = (KIPM_SRSCrashOutputSts_enum_ovrdflg ||
    (Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())->VIPM_SRSMsgActv_flg);

  /* Switch: '<S390>/Switch' incorporates:
   *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
   */
  if ((Rte_IrvIRead_Runbl_IpmCanRx_50ms_MsgActv_outputsIRV())
      ->VIPM_SRSMsgActv_flg) {
    /* Switch: '<S390>/Switch3' incorporates:
     *  DataTransferBlock generated from: '<Root>/IpmMsgActv'
     */
    if (!(Rte_IrvIRead_Runbl_IpmCanRx_50ms_CANCommCRCFlt_outputsIRV())
        ->VIPM_SRS_1_Status_CRCFlt_flg) {
      /* Switch: '<S390>/Switch' incorporates:
       *  Inport: '<Root>/SRS_1_Status_CHA'
       *  Switch: '<S390>/Switch3'
       */
      AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fi =
        (Rte_IRead_Runbl_IpmCanRx_50ms_SRS_1_Status_CHA_SRS_1_Status_CHA())
        ->SRS_CrashOutputSts;
    }

    /* End of Switch: '<S390>/Switch3' */
  } else {
    /* Switch: '<S390>/Switch' incorporates:
     *  Constant: '<S390>/sat5'
     */
    AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fi = KIPM_SRSCrashOutputStsDflt_enum;
  }

  /* End of Switch: '<S390>/Switch' */

  /* Switch: '<S390>/Switch4' incorporates:
   *  Constant: '<S390>/sat3'
   */
  if (KIPM_SRSCrashOutputSts_enum_ovrdflg) {
    /* Switch: '<S390>/Switch4' incorporates:
     *  Constant: '<S390>/sat4'
     */
    VIPM_SRSCrashOutputSts_enum = KIPM_SRSCrashOutputSts_enum_ovrdval;
  } else {
    /* Switch: '<S390>/Switch4' */
    VIPM_SRSCrashOutputSts_enum = AppSwcIpm_ARID_DEF.UnitDelay_DSTATE_fi;
  }

  /* End of Switch: '<S390>/Switch4' */
  /* End of Outputs for SubSystem: '<S389>/Subsys_VIPM_SRSCrashOutputSts_enum' */

  /* BusCreator: '<S389>/BusCreator' incorporates:
   *  Logic: '<S390>/Logical Operator3'
   *  Logic: '<S391>/Logical Operator3'
   *  Switch: '<S390>/Switch4'
   *  Switch: '<S391>/Switch4'
   */
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA_e.VIPM_SRSDrvSeatbeltBkld_flg =
    VIPM_SRSDrvSeatbeltBkld_flg;
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA_e.VIPM_SRSDrvSeatbeltBkldVld_flg =
    VIPM_SRSDrvSeatbeltBkldVld_flg;
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA_e.VIPM_SRSCrashOutputSts_enum =
    VIPM_SRSCrashOutputSts_enum;
  AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA_e.VIPM_SRSCrashOutputStsVld_flg =
    VIPM_SRSCrashOutputStsVld_flg;
}

/*
 * System initialize for atomic system:
 *    '<S395>/Chart'
 *    '<S396>/Chart'
 *    '<S397>/Chart'
 *    '<S398>/Chart'
 */
static void AppSwcIpm_Chart_Init(boolean *rty_y)
{
  *rty_y = false;
}

/*
 * Output and update for atomic system:
 *    '<S395>/Chart'
 *    '<S396>/Chart'
 *    '<S397>/Chart'
 *    '<S398>/Chart'
 */
static void AppSwcIpm_Chart(boolean rtu_u, float32 rtu_dT, float32 rtu_T,
  boolean rtu_FirstStep, boolean *rty_y, ARID_DEF_Chart_AppSwcIpm_T
  *AppSwcIpm__ARID_DEF_arg)
{
  /* Chart: '<S395>/Chart' */
  if (rtu_T <= 0.0F) {
    *rty_y = rtu_u;
  } else {
    if (rtu_FirstStep) {
      AppSwcIpm__ARID_DEF_arg->t = rtu_T;
    }

    if (rtu_u) {
      AppSwcIpm__ARID_DEF_arg->t = rtu_T;
    } else {
      AppSwcIpm__ARID_DEF_arg->t -= rtu_dT;
    }

    if (rtu_dT * 0.5 + AppSwcIpm__ARID_DEF_arg->t < 0.0) {
      *rty_y = false;
      AppSwcIpm__ARID_DEF_arg->t = -1.0F;
    } else {
      *rty_y = true;
    }
  }

  /* End of Chart: '<S395>/Chart' */
}

/* Model step function for TID1 */
void Runbl_IpmMsgActv_10ms(void)      /* Explicit Task: Runbl_IpmMsgActv_10ms */
{
  /* local block i/o variables */
  boolean rtb_y;
  boolean rtb_y_a;
  boolean rtb_y_d;
  boolean rtb_y_b;
  DT_CANCommCRCFlt CANCommCRCFlt_outputs_d;
  DT_CANCommCRCFlt rtb_SignalConversion1;
  DT_CANCommErr rtb_CANCommErr_outputs;
  DT_MsgActv rtb_SignalConversion;
  uint8 rtb_BitwiseAND1;
  boolean MsgActv_outputs_p_tmp;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmMsgActv_10ms' incorporates:
   *  SubSystem: '<Root>/IpmMsgActv'
   */
  /* S-Function (sfix_bitop): '<S393>/Bitwise AND1' incorporates:
   *  CCaller: '<S393>/DTC_0xC04688_ErrCode368'
   */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC04688_GetEventStatus();

  /* Chart: '<S396>/Chart' incorporates:
   *  Constant: '<S393>/Cnst'
   *  Constant: '<S393>/Cnst1'
   *  Constant: '<S396>/Constant1'
   *  DataTypeConversion: '<S393>/Data Type Conversion'
   *  Logic: '<S396>/Logical Operator'
   *  S-Function (sfix_bitop): '<S393>/Bitwise AND'
   */
  AppSwcIpm_Chart((rtb_BitwiseAND1 & 1U) != 0U, 0.01F, 0.5F, false, &rtb_y_d,
                  &AppSwcIpm_ARID_DEF.ARID_DEF_Chart_n);

  /* Switch: '<S393>/Switch' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg11'
   */
  if (KIPM_EPTCANBusOffOvrdSw_flg) {
    /* Switch: '<S393>/Switch' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg4'
     */
    VIPM_EPTCANBusOff_flg = KIPM_EPTCANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch' */
    VIPM_EPTCANBusOff_flg = rtb_y_d;
  }

  /* End of Switch: '<S393>/Switch' */

  /* CCaller: '<S393>/DTC_0xC11287_ErrCode354' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC11287_GetEventStatus();

  /* Switch: '<S393>/Switch4' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg8'
   */
  if (KIPM_BMSLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch4' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg9'
     */
    VIPM_BMSLostComm_flg = KIPM_BMSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch4' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion4'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND4'
     */
    VIPM_BMSLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch4' */

  /* Logic: '<S394>/Logical Operator' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch'
   *  Switch: '<S393>/Switch4'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_BMSMsgActv_flg =
    ((!VIPM_EPTCANBusOff_flg) && (!VIPM_BMSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_BMSCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xD10887_ErrCode364' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xD10887_GetEventStatus();

  /* Switch: '<S393>/Switch13' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg27'
   */
  if (KIPM_MCULostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch13' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg28'
     */
    VIPM_MCULostComm_flg = KIPM_MCULostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch13' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion13'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND13'
     */
    VIPM_MCULostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch13' */

  /* Logic: '<S394>/Logical Operator1' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch'
   *  Switch: '<S393>/Switch13'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_INVMsgActv_flg =
    ((!VIPM_EPTCANBusOff_flg) && (!VIPM_MCULostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_INVCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC14687_ErrCode376' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC14687_GetEventStatus();

  /* Switch: '<S393>/Switch17' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg35'
   */
  if (KIPM_IPULostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch17' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg36'
     */
    VIPM_IPULostComm_flg = KIPM_IPULostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch17' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion17'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND17'
     */
    VIPM_IPULostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch17' */

  /* Logic: '<S394>/Logical Operator2' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Logic: '<S394>/Logical Operator3'
   *  Switch: '<S393>/Switch'
   *  Switch: '<S393>/Switch17'
   */
  MsgActv_outputs_p_tmp = ((!VIPM_EPTCANBusOff_flg) && (!VIPM_IPULostComm_flg));
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_OBCMsgActv_flg =
    (MsgActv_outputs_p_tmp &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_IPUCRCChkFlt_flg));

  /* Logic: '<S394>/Logical Operator3' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_DCDCMsgActv_flg =
    (MsgActv_outputs_p_tmp &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_IPUCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC05588_ErrCode378' incorporates:
   *  CCaller: '<S393>/DTC_0xC06488_ErrCode379'
   */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC06488_GetEventStatus();

  /* Chart: '<S397>/Chart' incorporates:
   *  Constant: '<S393>/Cnst'
   *  Constant: '<S393>/Cnst1'
   *  Constant: '<S397>/Constant1'
   *  DataTypeConversion: '<S393>/Data Type Conversion3'
   *  Logic: '<S397>/Logical Operator'
   *  S-Function (sfix_bitop): '<S393>/Bitwise AND3'
   */
  AppSwcIpm_Chart((rtb_BitwiseAND1 & 1U) != 0U, 0.01F, 0.5F, false, &rtb_y_a,
                  &AppSwcIpm_ARID_DEF.ARID_DEF_Chart_o);

  /* Switch: '<S393>/Switch3' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg6'
   */
  if (KIPM_CHACANBusOffOvrdSw_flg) {
    /* Switch: '<S393>/Switch3' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg7'
     */
    VIPM_CHACANBusOff_flg = KIPM_CHACANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch3' */
    VIPM_CHACANBusOff_flg = rtb_y_a;
  }

  /* End of Switch: '<S393>/Switch3' */

  /* CCaller: '<S393>/DTC_0xC13087_ErrCode366' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC13087_GetEventStatus();

  /* Switch: '<S393>/Switch9' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg19'
   */
  if (KIPM_EPSLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch9' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg20'
     */
    VIPM_EPSLostComm_flg = KIPM_EPSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch9' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion9'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND9'
     */
    VIPM_EPSLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch9' */

  /* Logic: '<S394>/Logical Operator4' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch3'
   *  Switch: '<S393>/Switch9'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_EPSMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_EPSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_EPSCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC15187_ErrCode363' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC15187_GetEventStatus();

  /* Switch: '<S393>/Switch10' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg21'
   */
  if (KIPM_SRSLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch10' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg22'
     */
    VIPM_SRSLostComm_flg = KIPM_SRSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch10' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion10'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND10'
     */
    VIPM_SRSLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch10' */

  /* Logic: '<S394>/Logical Operator5' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch10'
   *  Switch: '<S393>/Switch3'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_SRSMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_SRSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_SRSCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC12287_ErrCode359' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC12287_GetEventStatus();

  /* Switch: '<S393>/Switch5' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg10'
   */
  if (KIPM_ESCLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch5' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg12'
     */
    VIPM_ESCLostComm_flg = KIPM_ESCLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch5' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion5'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND5'
     */
    VIPM_ESCLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch5' */

  /* Logic: '<S394>/Logical Operator6' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch3'
   *  Switch: '<S393>/Switch5'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_ESCMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_ESCLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_ESCCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xD10287_ErrCode372' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xD10287_GetEventStatus();

  /* Switch: '<S393>/Switch6' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg13'
   */
  if (KIPM_FCMLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch6' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg14'
     */
    VIPM_FCMLostComm_flg = KIPM_FCMLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch6' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion6'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND6'
     */
    VIPM_FCMLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch6' */

  /* Logic: '<S394>/Logical Operator7' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch3'
   *  Switch: '<S393>/Switch6'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_FCMMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_FCMLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_FCMCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC13187_ErrCode377' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC13187_GetEventStatus();

  /* Switch: '<S393>/Switch18' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg37'
   */
  if (KIPM_EHBLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch18' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg38'
     */
    VIPM_EHBLostComm_flg = KIPM_EHBLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch18' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion18'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND18'
     */
    VIPM_EHBLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch18' */

  /* Logic: '<S394>/Logical Operator17' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch18'
   *  Switch: '<S393>/Switch3'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_EHBMsgActv_flg =
    ((!VIPM_CHACANBusOff_flg) && (!VIPM_EHBLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_EHBCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC05588_ErrCode378' incorporates:
   *  CCaller: '<S393>/DTC_0xC07388_ErrCode367'
   */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC07388_GetEventStatus();

  /* Chart: '<S395>/Chart' incorporates:
   *  Constant: '<S393>/Cnst'
   *  Constant: '<S393>/Cnst1'
   *  Constant: '<S395>/Constant1'
   *  DataTypeConversion: '<S393>/Data Type Conversion2'
   *  Logic: '<S395>/Logical Operator'
   *  S-Function (sfix_bitop): '<S393>/Bitwise AND2'
   */
  AppSwcIpm_Chart((rtb_BitwiseAND1 & 1U) != 0U, 0.01F, 0.5F, false, &rtb_y_b,
                  &AppSwcIpm_ARID_DEF.ARID_DEF_Chart_i);

  /* Switch: '<S393>/Switch2' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg3'
   */
  if (KIPM_BACCANBusOffOvrdSw_flg) {
    /* Switch: '<S393>/Switch2' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg5'
     */
    VIPM_BACCANBusOff_flg = KIPM_BACCANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch2' */
    VIPM_BACCANBusOff_flg = rtb_y_b;
  }

  /* End of Switch: '<S393>/Switch2' */

  /* CCaller: '<S393>/DTC_0xD11687_ErrCode369' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xD11687_GetEventStatus();

  /* Switch: '<S393>/Switch11' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg23'
   */
  if (KIPM_ICULostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch11' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg24'
     */
    VIPM_ICULostComm_flg = KIPM_ICULostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch11' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion11'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND11'
     */
    VIPM_ICULostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch11' */

  /* Logic: '<S394>/Logical Operator8' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch11'
   *  Switch: '<S393>/Switch2'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_CDCMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_ICULostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_ICUCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xD11687_ErrCode365' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC19887_GetEventStatus();

  /* Switch: '<S393>/Switch12' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg25'
   */
  if (KIPM_TBOXLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch12' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg26'
     */
    VIPM_TBOXLostComm_flg = KIPM_TBOXLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch12' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion12'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND12'
     */
    VIPM_TBOXLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch12' */

  /* Logic: '<S394>/Logical Operator9' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch12'
   *  Switch: '<S393>/Switch2'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_TBOXMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_TBOXLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_TBOXCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC05588_ErrCode378' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC05588_GetEventStatus();

  /* Chart: '<S398>/Chart' incorporates:
   *  Constant: '<S393>/Cnst'
   *  Constant: '<S393>/Cnst1'
   *  Constant: '<S398>/Constant1'
   *  DataTypeConversion: '<S393>/Data Type Conversion1'
   *  Logic: '<S398>/Logical Operator'
   *  S-Function (sfix_bitop): '<S393>/Bitwise AND1'
   */
  AppSwcIpm_Chart((rtb_BitwiseAND1 & 1U) != 0U, 0.01F, 0.5F, false, &rtb_y,
                  &AppSwcIpm_ARID_DEF.ARID_DEF_Chart);

  /* Switch: '<S393>/Switch1' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg1'
   */
  if (KIPM_BODCANBusOffOvrdSw_flg) {
    /* Switch: '<S393>/Switch1' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg2'
     */
    VIPM_BODCANBusOff_flg = KIPM_BODCANBusOffOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch1' */
    VIPM_BODCANBusOff_flg = rtb_y;
  }

  /* End of Switch: '<S393>/Switch1' */

  /* CCaller: '<S393>/DTC_0xC10F87_ErrCode370' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC10F87_GetEventStatus();

  /* Switch: '<S393>/Switch14' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg29'
   */
  if (KIPM_ACCMLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch14' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg30'
     */
    VIPM_ACCMLostComm_flg = KIPM_ACCMLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch14' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion14'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND14'
     */
    VIPM_ACCMLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch14' */

  /* Logic: '<S394>/Logical Operator10' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch1'
   *  Switch: '<S393>/Switch14'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_ACCMMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_ACCMLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_ACCMCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC24087_ErrCode252' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC24087_GetEventStatus();

  /* Switch: '<S393>/Switch19' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg39'
   */
  if (KIPM_SCSLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch19' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg40'
     */
    VIPM_SCSLostComm_flg = KIPM_SCSLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch19' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion19'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND19'
     */
    VIPM_SCSLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch19' */

  /* Logic: '<S394>/Logical Operator18' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch1'
   *  Switch: '<S393>/Switch19'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_SCSMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_SCSLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_SCSCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC27087_ErrCode373' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC27087_GetEventStatus();

  /* Switch: '<S393>/Switch20' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg41'
   */
  if (KIPM_CCPLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch20' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg42'
     */
    VIPM_CCPLostComm_flg = KIPM_CCPLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch20' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion20'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND20'
     */
    VIPM_CCPLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch20' */

  /* Logic: '<S394>/Logical Operator19' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch1'
   *  Switch: '<S393>/Switch20'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_CCPMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_CCPLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_CCPCRCChkFlt_flg));

  /* Logic: '<S394>/Logical Operator13' incorporates:
   *  Switch: '<S393>/Switch1'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_ESCLMsgActv_flg =
    !VIPM_BODCANBusOff_flg;

  /* CCaller: '<S393>/DTC_0xD11D87_ErrCode360' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xD11D87_GetEventStatus();

  /* Switch: '<S393>/Switch16' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg33'
   */
  if (KIPM_CDCLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch16' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg34'
     */
    VIPM_CDCLostComm_flg = KIPM_CDCLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch16' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion16'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND16'
     */
    VIPM_CDCLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch16' */

  /* Logic: '<S394>/Logical Operator16' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch16'
   *  Switch: '<S393>/Switch2'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_HUMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_CDCLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_HUCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xC23087_ErrCode371' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xC23087_GetEventStatus();

  /* Switch: '<S393>/Switch15' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg31'
   */
  if (KIPM_PTCLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch15' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg32'
     */
    VIPM_PTCLostComm_flg = KIPM_PTCLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch15' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion15'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND15'
     */
    VIPM_PTCLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch15' */

  /* Logic: '<S394>/Logical Operator14' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch1'
   *  Switch: '<S393>/Switch15'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_PTCMsgActv_flg =
    ((!VIPM_BODCANBusOff_flg) && (!VIPM_PTCLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_PTCCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xD11287_ErrCode361' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xD11287_GetEventStatus();

  /* Switch: '<S393>/Switch7' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg15'
   */
  if (KIPM_CRRRLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch7' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg16'
     */
    VIPM_CRRRLostComm_flg = KIPM_CRRRLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch7' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion7'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND7'
     */
    VIPM_CRRRLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch7' */

  /* Logic: '<S394>/Logical Operator15' incorporates:
   *  Inport: '<Root>/DAG_Comm_outputs'
   *  Switch: '<S393>/Switch2'
   *  Switch: '<S393>/Switch7'
   */
  AppSwcIpm_ARID_DEF.MsgActv_outputs_p.VIPM_CRRRMsgActv_flg =
    ((!VIPM_BACCANBusOff_flg) && (!VIPM_CRRRLostComm_flg) &&
     (!(Rte_IRead_Runbl_IpmMsgActv_10ms_DAG_Comm_outputs_DAG_Comm_outputs())
      ->VDAG_CRRRCRCChkFlt_flg));

  /* CCaller: '<S393>/DTC_0xD10E87_ErrCode362' */
  rtb_BitwiseAND1 = App_Call_Event_DTC_0xD10E87_GetEventStatus();

  /* Switch: '<S393>/Switch8' incorporates:
   *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg17'
   */
  if (KIPM_PPLostCommOvrdSw_flg) {
    /* Switch: '<S393>/Switch8' incorporates:
     *  Constant: '<S393>/KIPC_LimpHomeOvrdSw_flg18'
     */
    VIPM_PPLostComm_flg = KIPM_PPLostCommOvrdVal_flg;
  } else {
    /* Switch: '<S393>/Switch8' incorporates:
     *  DataTypeConversion: '<S393>/Data Type Conversion8'
     *  S-Function (sfix_bitop): '<S393>/Bitwise AND8'
     */
    VIPM_PPLostComm_flg = ((rtb_BitwiseAND1 & 1U) != 0U);
  }

  /* End of Switch: '<S393>/Switch8' */

  /* BusCreator: '<S393>/Bus Creator' incorporates:
   *  Switch: '<S393>/Switch'
   *  Switch: '<S393>/Switch1'
   *  Switch: '<S393>/Switch10'
   *  Switch: '<S393>/Switch11'
   *  Switch: '<S393>/Switch12'
   *  Switch: '<S393>/Switch13'
   *  Switch: '<S393>/Switch14'
   *  Switch: '<S393>/Switch15'
   *  Switch: '<S393>/Switch16'
   *  Switch: '<S393>/Switch17'
   *  Switch: '<S393>/Switch18'
   *  Switch: '<S393>/Switch19'
   *  Switch: '<S393>/Switch2'
   *  Switch: '<S393>/Switch20'
   *  Switch: '<S393>/Switch3'
   *  Switch: '<S393>/Switch4'
   *  Switch: '<S393>/Switch5'
   *  Switch: '<S393>/Switch6'
   *  Switch: '<S393>/Switch7'
   *  Switch: '<S393>/Switch8'
   *  Switch: '<S393>/Switch9'
   */
  rtb_CANCommErr_outputs.VIPM_BACCANBusOff_flg = VIPM_BACCANBusOff_flg;
  rtb_CANCommErr_outputs.VIPM_EPTCANBusOff_flg = VIPM_EPTCANBusOff_flg;
  rtb_CANCommErr_outputs.VIPM_CHACANBusOff_flg = VIPM_CHACANBusOff_flg;
  rtb_CANCommErr_outputs.VIPM_BODCANBusOff_flg = VIPM_BODCANBusOff_flg;
  rtb_CANCommErr_outputs.VIPM_BMSLostComm_flg = VIPM_BMSLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_ESCLostComm_flg = VIPM_ESCLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_FCMLostComm_flg = VIPM_FCMLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_CRRRLostComm_flg = VIPM_CRRRLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_PPLostComm_flg = VIPM_PPLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_EPSLostComm_flg = VIPM_EPSLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_SRSLostComm_flg = VIPM_SRSLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_ICULostComm_flg = VIPM_ICULostComm_flg;
  rtb_CANCommErr_outputs.VIPM_TBOXLostComm_flg = VIPM_TBOXLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_MCULostComm_flg = VIPM_MCULostComm_flg;
  rtb_CANCommErr_outputs.VIPM_ACCMLostComm_flg = VIPM_ACCMLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_PTCLostComm_flg = VIPM_PTCLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_CDCLostComm_flg = VIPM_CDCLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_IPULostComm_flg = VIPM_IPULostComm_flg;
  rtb_CANCommErr_outputs.VIPM_EHBLostComm_flg = VIPM_EHBLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_SCSLostComm_flg = VIPM_SCSLostComm_flg;
  rtb_CANCommErr_outputs.VIPM_CCPLostComm_flg = VIPM_CCPLostComm_flg;

  /* SignalConversion: '<S6>/Signal Conversion' */
  rtb_SignalConversion = AppSwcIpm_ARID_DEF.MsgActv_outputs_p;

  /* Logic: '<S392>/Logical Operator' incorporates:
   *  Constant: '<S392>/Cnst'
   *  Constant: '<S392>/Constant1'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector'
   */
  VIPM_HU_B_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[87] && KIPM_HUCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator1' incorporates:
   *  Constant: '<S392>/Cnst1'
   *  Constant: '<S392>/Constant2'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector1'
   */
  VIPM_ICU_Info_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[43] &&
    KIPM_ICUCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator2' incorporates:
   *  Constant: '<S392>/Cnst2'
   *  Constant: '<S392>/Constant3'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector2'
   */
  VIPM_TBOX_BJS_Time_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[45] &&
    KIPM_TBOXCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator3' incorporates:
   *  Constant: '<S392>/Cnst3'
   *  Constant: '<S392>/Constant4'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector3'
   */
  VIPM_CCP_PanelStatus_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[11] &&
    KIPM_CCPCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator4' incorporates:
   *  Constant: '<S392>/Cnst4'
   *  Constant: '<S392>/Constant5'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector4'
   */
  VIPM_COMP_AC_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[16] &&
    KIPM_ACCMCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator5' incorporates:
   *  Constant: '<S392>/Cnst5'
   *  Constant: '<S392>/Constant6'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector5'
   */
  VIPM_HVCH_Status1_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[18] &&
    KIPM_PTCCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator6' incorporates:
   *  Constant: '<S392>/Cnst6'
   *  Constant: '<S392>/Constant7'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector6'
   */
  VIPM_SCS_RiSwitchSts_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[74] &&
    KIPM_SCSCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator7' incorporates:
   *  Constant: '<S392>/Cnst7'
   *  Constant: '<S392>/Constant8'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector7'
   */
  VIPM_CRRR_A_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[9] &&
    KIPM_CRRRCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator8' incorporates:
   *  Constant: '<S392>/Cnst8'
   *  Constant: '<S392>/Constant9'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector8'
   */
  VIPM_EHB_B_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[90] &&
    KIPM_EHBCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator9' incorporates:
   *  Constant: '<S392>/Cnst9'
   *  Constant: '<S392>/Constant10'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector9'
   */
  VIPM_EPS_2_StrWhlAng_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[7] &&
    KIPM_EPSCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator10' incorporates:
   *  Constant: '<S392>/Cnst10'
   *  Constant: '<S392>/Constant11'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector10'
   */
  VIPM_ESC_7_FuncStatus_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[75] &&
    KIPM_ESCCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator11' incorporates:
   *  Constant: '<S392>/Cnst11'
   *  Constant: '<S392>/Constant12'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector11'
   */
  VIPM_FCM_B_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[88] &&
    KIPM_FCMCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator12' incorporates:
   *  Constant: '<S392>/Cnst12'
   *  Constant: '<S392>/Constant13'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector12'
   */
  VIPM_PP_InformAndStatus_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[77] &&
    KIPM_PPCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator13' incorporates:
   *  Constant: '<S392>/Cnst13'
   *  Constant: '<S392>/Constant14'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector13'
   */
  VIPM_SRS_1_Status_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[76] &&
    KIPM_SRSCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator14' incorporates:
   *  Constant: '<S392>/Cnst14'
   *  Constant: '<S392>/Constant15'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector14'
   */
  VIPM_BMS_2_BatState_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[20] &&
    KIPM_BMSCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator15' incorporates:
   *  Constant: '<S392>/Cnst15'
   *  Constant: '<S392>/Constant16'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector15'
   */
  VIPM_INV_1_Value_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[37] &&
    KIPM_INVCRCChkEnbl_flg);

  /* Logic: '<S392>/Logical Operator16' incorporates:
   *  Constant: '<S392>/Cnst16'
   *  Constant: '<S392>/Constant17'
   *  DataStoreRead: '<S392>/Data Store Read'
   *  Selector: '<S392>/Selector16'
   */
  VIPM_IPU_DCC_1_State_CRCFlt_flg = (VBSW_CANComCRCInstFlt_flg[32] &&
    KIPM_IPUCRCChkEnbl_flg);

  /* BusCreator: '<S392>/Bus Creator' incorporates:
   *  Logic: '<S392>/Logical Operator'
   *  Logic: '<S392>/Logical Operator1'
   *  Logic: '<S392>/Logical Operator10'
   *  Logic: '<S392>/Logical Operator11'
   *  Logic: '<S392>/Logical Operator12'
   *  Logic: '<S392>/Logical Operator13'
   *  Logic: '<S392>/Logical Operator14'
   *  Logic: '<S392>/Logical Operator15'
   *  Logic: '<S392>/Logical Operator16'
   *  Logic: '<S392>/Logical Operator2'
   *  Logic: '<S392>/Logical Operator3'
   *  Logic: '<S392>/Logical Operator4'
   *  Logic: '<S392>/Logical Operator5'
   *  Logic: '<S392>/Logical Operator6'
   *  Logic: '<S392>/Logical Operator7'
   *  Logic: '<S392>/Logical Operator8'
   *  Logic: '<S392>/Logical Operator9'
   */
  CANCommCRCFlt_outputs_d.VIPM_HU_B_CRCFlt_flg = VIPM_HU_B_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_ICU_Info_CRCFlt_flg = VIPM_ICU_Info_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_TBOX_BJS_Time_CRCFlt_flg =
    VIPM_TBOX_BJS_Time_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_CCP_PanelStatus_CRCFlt_flg =
    VIPM_CCP_PanelStatus_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_COMP_AC_CRCFlt_flg = VIPM_COMP_AC_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_HVCH_Status1_CRCFlt_flg =
    VIPM_HVCH_Status1_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_SCS_RiSwitchSts_CRCFlt_flg =
    VIPM_SCS_RiSwitchSts_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_CRRR_A_CRCFlt_flg = VIPM_CRRR_A_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_EHB_B_CRCFlt_flg = VIPM_EHB_B_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_EPS_2_StrWhlAng_CRCFlt_flg =
    VIPM_EPS_2_StrWhlAng_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_ESC_7_FuncStatus_CRCFlt_flg =
    VIPM_ESC_7_FuncStatus_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_FCM_B_CRCFlt_flg = VIPM_FCM_B_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_PP_InformAndStatus_CRCFlt_flg =
    VIPM_PP_InformAndStatus_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_SRS_1_Status_CRCFlt_flg =
    VIPM_SRS_1_Status_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_BMS_2_BatState_CRCFlt_flg =
    VIPM_BMS_2_BatState_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_INV_1_Value_CRCFlt_flg =
    VIPM_INV_1_Value_CRCFlt_flg;
  CANCommCRCFlt_outputs_d.VIPM_IPU_DCC_1_State_CRCFlt_flg =
    VIPM_IPU_DCC_1_State_CRCFlt_flg;

  /* SignalConversion: '<S6>/Signal Conversion1' */
  rtb_SignalConversion1 = CANCommCRCFlt_outputs_d;

  /* Update for UnitDelay: '<S396>/Unit Delay3' incorporates:
   *  Constant: '<S396>/Constant2'
   */
  AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE = false;

  /* Update for UnitDelay: '<S397>/Unit Delay3' incorporates:
   *  Constant: '<S397>/Constant2'
   */
  AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE_l = false;

  /* Update for UnitDelay: '<S395>/Unit Delay3' incorporates:
   *  Constant: '<S395>/Constant2'
   */
  AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE_o = false;

  /* Update for UnitDelay: '<S398>/Unit Delay3' incorporates:
   *  Constant: '<S398>/Constant2'
   */
  AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE_g = false;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmMsgActv_10ms' */

  /* DataTransferBlock generated from: '<Root>/IpmMsgActv' */
  Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputsIRV(&rtb_SignalConversion);

  /* DataTransferBlock generated from: '<Root>/IpmMsgActv' */
  Rte_IrvIWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputsIRV
    (&rtb_SignalConversion1);

  /* Outport: '<Root>/CANCommErr_outputs' */
  Rte_IWrite_Runbl_IpmMsgActv_10ms_CANCommErr_outputs_CANCommErr_outputs
    (&rtb_CANCommErr_outputs);

  /* Outport: '<Root>/MsgActv_outputs' */
  Rte_IWrite_Runbl_IpmMsgActv_10ms_MsgActv_outputs_MsgActv_outputs
    (&AppSwcIpm_ARID_DEF.MsgActv_outputs_p);

  /* Outport: '<Root>/CANCommCRCFlt_outputs' */
  Rte_IWrite_Runbl_IpmMsgActv_10ms_CANCommCRCFlt_outputs_CANCommCRCFlt_outputs
    (&CANCommCRCFlt_outputs_d);
}

/* Model step function for TID2 */
void Runbl_IpmCanRx_10ms(void)         /* Explicit Task: Runbl_IpmCanRx_10ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_10ms' incorporates:
   *  SubSystem: '<Root>/Ipm10ms'
   */
  Runbl_Ipm10ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_10ms' */

  /* Outport: '<Root>/IPM_INV_1_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_1_Value_EPT_IPM_INV_1_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_1_Value_EPT_d);

  /* Outport: '<Root>/IPM_INV_2_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_2_Value_EPT_IPM_INV_2_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_2_Value_EPT_f);

  /* Outport: '<Root>/IPM_INV_3_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_3_Value_EPT_IPM_INV_3_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_3_Value_EPT_n);

  /* Outport: '<Root>/IPM_INV_4_Value_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_INV_4_Value_EPT_IPM_INV_4_Value_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_4_Value_EPT_b);

  /* Outport: '<Root>/IPM_EPS_2_StrWhlAng_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_EPS_2_StrWhlAng_CHA_IPM_EPS_2_StrWhlAng_CHA
    (&AppSwcIpm_ARID_DEF.IPM_EPS_2_StrWhlAng_CHA_g);

  /* Outport: '<Root>/IPM_ESC_7_FuncStatus_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_ESC_7_FuncStatus_CHA_IPM_ESC_7_FuncStatus_CHA
    (&AppSwcIpm_ARID_DEF.ESC_7_FuncStatus_CHA_a);

  /* Outport: '<Root>/IPM_ESC_A_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_ESC_A_CHA_IPM_ESC_A_CHA
    (&AppSwcIpm_ARID_DEF.ESC_A_CHA_f);

  /* Outport: '<Root>/IPM_EHB_B_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_10ms_IPM_EHB_B_CHA_IPM_EHB_B_CHA
    (&AppSwcIpm_ARID_DEF.EHB_B_CHA_l);
}

/* Model step function for TID3 */
void Runbl_IpmCanRx_20ms(void)         /* Explicit Task: Runbl_IpmCanRx_20ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_20ms' incorporates:
   *  SubSystem: '<Root>/Ipm20ms'
   */
  Runbl_Ipm20ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_20ms' */

  /* Outport: '<Root>/IPM_BMS_1_MainState_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_1_MainState_EPT_IPM_BMS_1_MainState_EPT
    (&AppSwcIpm_ARID_DEF.BusCreator);

  /* Outport: '<Root>/IPM_BMS_2_BatState_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_2_BatState_EPT_IPM_BMS_2_BatState_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_2_BatState_EPT_n);

  /* Outport: '<Root>/IPM_BMS_3_DC_ChargeState_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_3_DC_ChargeState_EPT_IPM_BMS_3_DC_ChargeState_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_3_DC_ChargeState_EPT_j);

  /* Outport: '<Root>/IPM_BMS_6_DischrgRecup_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_6_DischrgRecup_EPT_IPM_BMS_6_DischrgRecup_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_6_DischrgRecup_EPT_m);

  /* Outport: '<Root>/IPM_BMS_7_CellVolt_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_7_CellVolt_EPT_IPM_BMS_7_CellVolt_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_7_CellVolt_EPT_b);

  /* Outport: '<Root>/IPM_BMS_10_DC_ChargeStates_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_10_DC_ChargeStates_EPT_IPM_BMS_10_DC_ChargeStates_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_10_DC_ChargeStates_EPT_j);

  /* Outport: '<Root>/IPM_BMS_4_AC_ChargeState_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_BMS_4_AC_ChargeState_EPT_IPM_BMS_4_AC_ChargeState_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_4_AC_ChargeState_EPT_c);

  /* Outport: '<Root>/IPM_EHB_A_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_EHB_A_CHA_IPM_EHB_A_CHA
    (&AppSwcIpm_ARID_DEF.IPM_EHB_A_CHA_l);

  /* Outport: '<Root>/IPM_FCM_B_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_FCM_B_CHA_IPM_FCM_B_CHA
    (&AppSwcIpm_ARID_DEF.IPM_FCM_B_CHA_k);

  /* Outport: '<Root>/IPM_CRRR_A_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_CRRR_A_CHA_IPM_CRRR_A_CHA
    (&AppSwcIpm_ARID_DEF.IPM_CRRR_A_CHA_h);

  /* Outport: '<Root>/IPM_SCS_RiSwitchSts_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_20ms_IPM_SCS_RiSwitchSts_BOD_IPM_SCS_RiSwitchSts_BOD
    (&AppSwcIpm_ARID_DEF.IPM_SCS_RiSwitchSts_BOD_l);
}

/* Model step function for TID4 */
void Runbl_IpmCanRx_50ms(void)         /* Explicit Task: Runbl_IpmCanRx_50ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_50ms' incorporates:
   *  SubSystem: '<Root>/Ipm50ms'
   */
  Runbl_Ipm50ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_50ms' */

  /* Outport: '<Root>/IPM_CCP_PanelStatus_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_CCP_PanelStatus_BOD_IPM_CCP_PanelStatus_BOD
    (&AppSwcIpm_ARID_DEF.IPM_CCP_PanelStatus_BOD_p);

  /* Outport: '<Root>/IPM_ESCL_ESCLStatus_BOD' incorporates:
   *  BusCreator: '<S357>/BusCreator'
   */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_ESCL_ESCLStatus_BOD_IPM_ESCL_ESCLStatus_BOD
    (&AppSwcIpm_ARID_DEF.IPM_ESCL_ESCLStatus_BOD_b);

  /* Outport: '<Root>/IPM_SCS_LeSwitchSts_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_SCS_LeSwitchSts_BOD_IPM_SCS_LeSwitchSts_BOD
    (&AppSwcIpm_ARID_DEF.IPM_SCS_LeSwitchSts_BOD_l);

  /* Outport: '<Root>/IPM_SRS_1_Status_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_50ms_IPM_SRS_1_Status_CHA_IPM_SRS_1_Status_CHA
    (&AppSwcIpm_ARID_DEF.IPM_SRS_1_Status_CHA_e);
}

/* Model step function for TID5 */
void Runbl_IpmCanRx_100ms(void)        /* Explicit Task: Runbl_IpmCanRx_100ms */
{
  /* RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_100ms' incorporates:
   *  SubSystem: '<Root>/Ipm100ms'
   */
  Runbl_Ipm100ms();

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmCanRx_100ms' */

  /* Outport: '<Root>/IPM_BMS_5_BatTemp_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_BMS_5_BatTemp_EPT_IPM_BMS_5_BatTemp_EPT
    (&AppSwcIpm_ARID_DEF.IPM_BMS_5_BatTemp_EPT_l);

  /* Outport: '<Root>/IPM_IPU_OBC_1_State_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_1_State_EPT_IPM_IPU_OBC_1_State_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_OBC_1_State_EPT_b);

  /* Outport: '<Root>/IPM_IPU_DCC_1_State_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_1_State_EPT_IPM_IPU_DCC_1_State_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_DCC_1_State_EPT_j);

  /* Outport: '<Root>/IPM_IPU_DCC_2_ChrgInValue_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_DCC_2_ChrgInValue_EPT_IPM_IPU_DCC_2_ChrgInValue_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_DCC_2_ChrgInValue_EPT_o);

  /* Outport: '<Root>/IPM_INV_IMMO_Req_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_INV_IMMO_Req_EPT_IPM_INV_IMMO_Req_EPT
    (&AppSwcIpm_ARID_DEF.IPM_INV_IMMO_Req_EPT_b);

  /* Outport: '<Root>/IPM_IPU_OBC_2_Inlet_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_IPU_OBC_2_Inlet_EPT_IPM_IPU_OBC_2_Inlet_EPT
    (&AppSwcIpm_ARID_DEF.IPM_IPU_OBC_2_Inlet_EPT_c);

  /* Outport: '<Root>/IPM_BMS_9_BattInfo_EPT' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_BMS_9_BattInfo_EPT_IPM_BMS_9_BattInfo_EPT(
    &AppSwcIpm_ARID_DEF.IPM_BMS_9_BattInfo_EPT_a);

  /* Outport: '<Root>/IPM_HU_B_BAC' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HU_B_BAC_IPM_HU_B_BAC
    (&AppSwcIpm_ARID_DEF.IPM_HU_B_BAC_m);

  /* Outport: '<Root>/IPM_TBOX_BJS_Time_BAC' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_TBOX_BJS_Time_BAC_IPM_TBOX_BJS_Time_BAC
    (&AppSwcIpm_ARID_DEF.IPM_TBOX_BJS_Time_BAC_d);

  /* Outport: '<Root>/IPM_COMP_AC_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_COMP_AC_BOD_IPM_COMP_AC_BOD
    (&AppSwcIpm_ARID_DEF.IPM_COMP_AC_BOD_c);

  /* Outport: '<Root>/IPM_HVCH_Status1_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HVCH_Status1_BOD_IPM_HVCH_Status1_BOD
    (&AppSwcIpm_ARID_DEF.IPM_HVCH_Status1_BOD_g);

  /* Outport: '<Root>/IPM_HVCH_Status2_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_HVCH_Status2_BOD_IPM_HVCH_Status2_BOD
    (&AppSwcIpm_ARID_DEF.IPM_HVCH_Status2_BOD_g);

  /* Outport: '<Root>/IPM_ACCM_Version_BOD' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_ACCM_Version_BOD_IPM_ACCM_Version_BOD
    (&AppSwcIpm_ARID_DEF.IPM_ACCM_Version_BOD_d);

  /* Outport: '<Root>/IPM_ICU_2_Odo_BAC' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_ICU_2_Odo_BAC_IPM_ICU_2_Odo_BAC
    (&AppSwcIpm_ARID_DEF.IPM_ICU_2_Odo_BAC_j);

  /* Outport: '<Root>/IPM_FCM_A_CHA' */
  Rte_IWrite_Runbl_IpmCanRx_100ms_IPM_FCM_A_CHA_IPM_FCM_A_CHA
    (&AppSwcIpm_ARID_DEF.IPM_FCM_A_CHA_f);
}

/* Model initialize function */
void AppSwcIpm_Init(void)
{
  {
    /* local block i/o variables */
    boolean rtb_y;
    boolean rtb_y_a;
    boolean rtb_y_d;
    boolean rtb_y_b;

    /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmMsgActv_10ms' incorporates:
     *  SubSystem: '<Root>/IpmMsgActv'
     */
    /* InitializeConditions for UnitDelay: '<S396>/Unit Delay3' */
    AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE = true;

    /* InitializeConditions for UnitDelay: '<S397>/Unit Delay3' */
    AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE_l = true;

    /* InitializeConditions for UnitDelay: '<S395>/Unit Delay3' */
    AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE_o = true;

    /* InitializeConditions for UnitDelay: '<S398>/Unit Delay3' */
    AppSwcIpm_ARID_DEF.UnitDelay3_DSTATE_g = true;

    /* SystemInitialize for Chart: '<S395>/Chart' */
    AppSwcIpm_Chart_Init(&rtb_y_b);

    /* SystemInitialize for Chart: '<S396>/Chart' */
    AppSwcIpm_Chart_Init(&rtb_y_d);

    /* SystemInitialize for Chart: '<S397>/Chart' */
    AppSwcIpm_Chart_Init(&rtb_y_a);

    /* SystemInitialize for Chart: '<S398>/Chart' */
    AppSwcIpm_Chart_Init(&rtb_y);

    /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Runbl_IpmMsgActv_10ms' */
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
